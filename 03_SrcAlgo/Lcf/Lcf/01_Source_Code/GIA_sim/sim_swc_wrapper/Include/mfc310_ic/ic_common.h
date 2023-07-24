//* **********************************************************************
//  COMPANY:         $CompanyInfo: CONFIDENTIAL AND PROPRIETARY PROPERTY OF CONTINENTAL AG , A.D.C. GmbH  -  ALL RIGHTS RESERVED $
//  
//  PROJECT:         MFC30x_MCU
//  CPU:             MPC5675K
//  
//  PACKAGE:         $Source: ic_common.h $ $Revision: 1.1 $
//  MKS Date:        $Date: 2021/12/13 17:25:48CET $
//  
//  RHAPSODY:        7.5.3
//  COMPONENT:       IC
//  CONFIGURATION:   DefaultConfig
//  MODEL ELEMENT:   ic_common
//  MODULNAME:       ..\..\..\04_Engineering\01_Source_Code\Algo\ic\ic_common.h
//  LOGIN:           uidt3974  
//  
//  
//  
//  AUTHOR:          $Author: Wang, David (Wangd3) $
//! CREATION DATE:   Thu, 19, Jul 2012  10:36 W. Europe Daylight Time PM 
//**************************************************************************** */

#ifndef ic_common_H
#define ic_common_H

/*## dependency ic_types */
#include "ic_types.h"
/*## package Ic_Pkg */

/*## class TopLevel::ic_common */


/*#[ ignore */

#ifdef __cplusplus
extern "C"
{
#endif

/*#]*/


/*## attribute IC_cui16_EndianessCheck */
extern const uint16 IC_cui16_EndianessCheck;

/***    User explicit entries    ***/


/* Operations */

//*****************************************************************************
//  Functionname:  IC_BITFIELD_UI8SIZE
//  
//  Returns the number of uint8 array elements required for a bitfield with specified size
//  
//  Parameter:     const RhpString numBits   <In>
//  
//    
//  
//  return         RhpString
//**************************************************************************** */
/*## operation IC_BITFIELD_UI8SIZE(RhpString) const */
#define IC_BITFIELD_UI8SIZE(numBits)    \
    (((numBits)+7)/8) // PRQA S 3429,3453 2

//*****************************************************************************
//  Functionname:  IC_ui16_SaturateUi32
//  
//  
//  
//  Parameter:     const uint32 ui32_Value   <In>
//  
//    
//  
//  return         uint16
//**************************************************************************** */
/*## operation IC_ui16_SaturateUi32(const uint32) */
uint16 IC_ui16_SaturateUi32(const uint32 ui32_Value);

//*****************************************************************************
//  Functionname:  IC_si16_SaturateSi32
//  
//  
//  
//  Parameter:     const sint32 si32_Value   <In>
//  
//    
//  
//  return         sint16
//**************************************************************************** */
/*## operation IC_si16_SaturateSi32(const sint32) */
sint16 IC_si16_SaturateSi32(const sint32 si32_Value);

//*****************************************************************************
//  Functionname:  IC_ui8_SaturateUi16
//  
//  
//  
//  Parameter:     const uint16 ui16_Value   <In>
//  
//    
//  
//  return         uint8
//**************************************************************************** */
/*## operation IC_ui8_SaturateUi16(const uint16) */
uint8 IC_ui8_SaturateUi16(const uint16 ui16_Value);

//*****************************************************************************
//  Functionname:  IC_v_RectToRoi
//  
//  
//  
//  Parameter:     IC_S_Roi * const ps_Dest   <In>
//  
//  
//  Parameter:     const IC_S_Rect_ui16 * const ps_Src   <In>
//  
//    
//  
//  return         void
//**************************************************************************** */
/*## operation IC_v_RectToRoi(IC_S_Roi * const,const IC_S_Rect_ui16 * const) */
void IC_v_RectToRoi(IC_S_Roi * const ps_Dest, const IC_S_Rect_ui16 * const ps_Src);

//*****************************************************************************
//  Functionname:  IC_e_SlopeRatioIntToEnum
//  
//  
//  
//  Parameter:     const uint16 ui16_Ratio   <In>
//  
//    
//  
//  return         IC_E_INTEGR_RATIO
//**************************************************************************** */
/*## operation IC_e_SlopeRatioIntToEnum(const uint16) */
IC_E_INTEGR_RATIO IC_e_SlopeRatioIntToEnum(const uint16 ui16_Ratio);

//*****************************************************************************
//  Functionname:  IC_ui16_SlopeRatioEnumToInt
//  
//  
//  
//  Parameter:     const IC_E_INTEGR_RATIO e_Ratio   <In>
//  
//    
//  
//  return         uint16
//**************************************************************************** */
/*## operation IC_ui16_SlopeRatioEnumToInt(const IC_E_INTEGR_RATIO) */
uint16 IC_ui16_SlopeRatioEnumToInt(const IC_E_INTEGR_RATIO e_Ratio);

//*****************************************************************************
//  Functionname:  IC_v_BitmapSetBit
//  
//  
//  
//  Parameter:     uint8 * const pui8_Bitmap   <In>
//  
//  
//  Parameter:     uint32 ui32_Bitnum   <In>
//  
//    
//  
//  return         void
//**************************************************************************** */
/*## operation IC_v_BitmapSetBit(uint8 * const,uint32) */
void IC_v_BitmapSetBit(uint8 * const pui8_Bitmap, uint32 ui32_Bitnum);

//*****************************************************************************
//  Functionname:  IC_b_BitmapGetBit
//  
//  
//  
//  Parameter:     const uint8 * const pui8_Bitmap   <In>
//  
//  
//  Parameter:     uint32 ui32_Bitnum   <In>
//  
//    
//  
//  return         boolean
//**************************************************************************** */
/*## operation IC_b_BitmapGetBit(const uint8 * const,uint32) */
boolean IC_b_BitmapGetBit(const uint8 * const pui8_Bitmap, uint32 ui32_Bitnum);

//*****************************************************************************
//  Functionname:  IC_v_BitmapClearBit
//  
//  
//  
//  Parameter:     uint8 * const pui8_Bitmap   <In>
//  
//  
//  Parameter:     uint32 ui32_Bitnum   <In>
//  
//    
//  
//  return         void
//**************************************************************************** */
/*## operation IC_v_BitmapClearBit(uint8 * const,uint32) */
void IC_v_BitmapClearBit(uint8 * const pui8_Bitmap, uint32 ui32_Bitnum);

//*****************************************************************************
//  Functionname:  IC_e_ImageCounterToFrameType
//  
//  
//  
//  Parameter:     const uint16 ui16_ImageCounter   <In>
//  
//    
//  
//  return         IC_E_FRAMETYPE
//**************************************************************************** */
/*## operation IC_e_ImageCounterToFrameType(const uint16) */
IC_E_FRAMETYPE IC_e_ImageCounterToFrameType(const uint16 ui16_ImageCounter);

//*****************************************************************************
//  Functionname:  IC_b_IsBigEndian
//  
//  
//  
//    
//  
//  return         boolean
//**************************************************************************** */
/*## operation IC_b_IsBigEndian() */
boolean IC_b_IsBigEndian(void);

//*****************************************************************************
//  Functionname:  IC_ui16_RectWidth
//  
//  
//  
//  Parameter:     const IC_S_Rect_ui16 * const ps_Rect   <In>
//  
//    
//  
//  return         uint16
//**************************************************************************** */
/*## operation IC_ui16_RectWidth(const IC_S_Rect_ui16 * const) */
uint16 IC_ui16_RectWidth(const IC_S_Rect_ui16 * const ps_Rect);

//*****************************************************************************
//  Functionname:  IC_ui16_RectHeight
//  
//  
//  
//  Parameter:     const IC_S_Rect_ui16 * const ps_Rect   <In>
//  
//    
//  
//  return         uint16
//**************************************************************************** */
/*## operation IC_ui16_RectHeight(const IC_S_Rect_ui16 * const) */
uint16 IC_ui16_RectHeight(const IC_S_Rect_ui16 * const ps_Rect);

//*****************************************************************************
//  Functionname:  IC_ui16_RoiEndX
//  
//  
//  
//  Parameter:     const IC_S_Roi * const ps_Roi   <In>
//  
//    
//  
//  return         uint16
//**************************************************************************** */
/*## operation IC_ui16_RoiEndX(const IC_S_Roi * const) */
uint16 IC_ui16_RoiEndX(const IC_S_Roi * const ps_Roi);

//*****************************************************************************
//  Functionname:  IC_ui16_RoiEndY
//  
//  
//  
//  Parameter:     const IC_S_Roi * const ps_Roi   <In>
//  
//    
//  
//  return         uint16
//**************************************************************************** */
/*## operation IC_ui16_RoiEndY(const IC_S_Roi * const) */
uint16 IC_ui16_RoiEndY(const IC_S_Roi * const ps_Roi);

/***    User explicit entries    ***/



/*#[ ignore */

#ifdef __cplusplus
}
#endif

/*#]*/


#endif
/*********************************************************************
	File Path: ..\..\..\04_Engineering\01_Source_Code\Algo\ic\ic_common.h
*********************************************************************/
