//* **********************************************************************
//  COMPANY:         $CompanyInfo: CONFIDENTIAL AND PROPRIETARY PROPERTY OF CONTINENTAL AG , A.D.C. GmbH  -  ALL RIGHTS RESERVED $
//  
//  PROJECT:         MFC30x_MCU
//  CPU:             MPC5675K
//  
//  PACKAGE:         $Source: ic_common.c $ $Revision: 1.1 $
//  MKS Date:        $Date: 2021/12/13 17:25:48CET $
//  
//  RHAPSODY:        7.5.3
//  COMPONENT:       IC
//  CONFIGURATION:   DefaultConfig
//  MODEL ELEMENT:   ic_common
//  MODULNAME:       ..\..\..\04_Engineering\01_Source_Code\Algo\ic\ic_common.c
//  LOGIN:           uidt3974  
//  
//  
//  
//  AUTHOR:          $Author: Wang, David (Wangd3) $
//! CREATION DATE:   Thu, 19, Jul 2012  4:25 W. Europe Daylight Time PM 
//**************************************************************************** */

/*## auto_generated */
#include "ic_common.h"
/*## package Ic_Pkg */

/*## class TopLevel::ic_common */


/*#[ ignore */
#ifdef __cplusplus
extern "C"
{
#endif

/*#]*/


/*## attribute IC_cui16_EndianessCheck */
const uint16 IC_cui16_EndianessCheck = 0x0100;

/*## operation IC_ui16_SaturateUi32(const uint32) */
uint16 IC_ui16_SaturateUi32(const uint32 ui32_Value) {
    /*#[ operation IC_ui16_SaturateUi32(const uint32) */
    uint16 ui16_Ret;
    if (ui32_Value > TYPEMAX_UI16)
    {
      ui16_Ret = TYPEMAX_UI16;
    }
    else
    {
      ui16_Ret = (uint16)ui32_Value;
    }
    return ui16_Ret;
    /*#]*/
}

/*## operation IC_si16_SaturateSi32(const sint32) */
sint16 IC_si16_SaturateSi32(const sint32 si32_Value) {
    /*#[ operation IC_si16_SaturateSi32(const sint32) */
    sint16 si16_Ret;
    if (si32_Value < TYPEMIN_SI16)
    {
      si16_Ret = TYPEMIN_SI16;
    }
    else if (si32_Value > TYPEMAX_SI16)
    {
      si16_Ret = TYPEMAX_SI16;
    }
    else
    {
      si16_Ret = (sint16)si32_Value;
    }
    return si16_Ret;
    /*#]*/
}

/*## operation IC_ui8_SaturateUi16(const uint16) */
uint8 IC_ui8_SaturateUi16(const uint16 ui16_Value) {
    /*#[ operation IC_ui8_SaturateUi16(const uint16) */
    uint8 ui8_Ret;
    if (ui16_Value > TYPEMAX_UI8)
    {
      ui8_Ret = TYPEMAX_UI8;
    }
    else
    {
      ui8_Ret = (uint8)ui16_Value;
    }
    return ui8_Ret;
    /*#]*/
}

/*## operation IC_v_RectToRoi(IC_S_Roi * const,const IC_S_Rect_ui16 * const) */
void IC_v_RectToRoi(IC_S_Roi * const ps_Dest, const IC_S_Rect_ui16 * const ps_Src) {
    /*#[ operation IC_v_RectToRoi(IC_S_Roi * const,const IC_S_Rect_ui16 * const) */
    if ((ps_Dest != NULL) && (ps_Src != NULL))
    {
      ps_Dest->ui16_StartX = ps_Src->ui16_x1;
      ps_Dest->ui16_StartY = ps_Src->ui16_y1;
      ps_Dest->ui16_Width  = (ps_Src->ui16_x2 - ps_Src->ui16_x1) + 1;
      ps_Dest->ui16_Height = (ps_Src->ui16_y2 - ps_Src->ui16_y1) + 1;
    }
    /*#]*/
}

/*## operation IC_e_SlopeRatioIntToEnum(const uint16) */
IC_E_INTEGR_RATIO IC_e_SlopeRatioIntToEnum(const uint16 ui16_Ratio) {
    /*#[ operation IC_e_SlopeRatioIntToEnum(const uint16) */
    // Magic numbers are intended here & allow compact code for this "Lookup table" kind
    // of switch statement:
    // PRQA S 3120,2205 8
    IC_E_INTEGR_RATIO e_Ret;
    switch (ui16_Ratio)
    {
      case 4u:  e_Ret = IC_e_INTEGR_RATIO_4;  break;
      case 8u:  e_Ret = IC_e_INTEGR_RATIO_8;  break;
      case 16u: e_Ret = IC_e_INTEGR_RATIO_16; break;
      case 32u: e_Ret = IC_e_INTEGR_RATIO_32; break;
      default:  e_Ret = IC_e_INTEGR_RATIO_16; break;
    }
    return e_Ret;
    /*#]*/
}

/*## operation IC_ui16_SlopeRatioEnumToInt(const IC_E_INTEGR_RATIO) */
uint16 IC_ui16_SlopeRatioEnumToInt(const IC_E_INTEGR_RATIO e_Ratio) {
    /*#[ operation IC_ui16_SlopeRatioEnumToInt(const IC_E_INTEGR_RATIO) */
    // Magic numbers are intended here & allow compact code for this "Lookup table" kind
    // of switch statement:
    // PRQA S 3120,2205 8
    uint16 e_Ret;
    switch (e_Ratio)
    {
      case IC_e_INTEGR_RATIO_4:  e_Ret = 4;  break;
      case IC_e_INTEGR_RATIO_8:  e_Ret = 8;  break;
      case IC_e_INTEGR_RATIO_16: e_Ret = 16; break;
      case IC_e_INTEGR_RATIO_32: e_Ret = 32; break;
      default:                   e_Ret = 16; break;
    }
    return e_Ret;
    /*#]*/
}

/*## operation IC_v_BitmapSetBit(uint8 * const,uint32) */
void IC_v_BitmapSetBit(uint8 * const pui8_Bitmap, uint32 ui32_Bitnum) {
    /*#[ operation IC_v_BitmapSetBit(uint8 * const,uint32) */
    // 3120: 'Magic Numbers' are commented in the code
    // 0492: Pointer usage as array can not be omitted here
    //
    // PRQA S 0506,3120,0492 3
    const uint32 ui32_ElemIndex = ui32_Bitnum >> 3u; // div 8
    ui32_Bitnum -= ui32_ElemIndex << 3u; // mult 8
    pui8_Bitmap[ui32_ElemIndex] |= (1u << ui32_Bitnum);
    /*#]*/
}

/*## operation IC_b_BitmapGetBit(const uint8 * const,uint32) */
boolean IC_b_BitmapGetBit(const uint8 * const pui8_Bitmap, uint32 ui32_Bitnum) {
    /*#[ operation IC_b_BitmapGetBit(const uint8 * const,uint32) */
    // 3120: 'Magic Numbers' are commented in the code
    // 0492: Pointer usage as array can not be omitted here
    //
    // PRQA S 0506,3120,0492 4
    boolean b_Ret;
    const uint32 ui32_ElemIndex = ui32_Bitnum >> 3u; // div 8
    ui32_Bitnum -= ui32_ElemIndex << 3u; // mult 8
    if ((pui8_Bitmap[ui32_ElemIndex] & (1u << ui32_Bitnum)) != 0)
    {
      b_Ret = b_TRUE;
    }
    else
    {
      b_Ret = b_FALSE;
    }
    return b_Ret;
    /*#]*/
}

/*## operation IC_v_BitmapClearBit(uint8 * const,uint32) */
void IC_v_BitmapClearBit(uint8 * const pui8_Bitmap, uint32 ui32_Bitnum) {
    /*#[ operation IC_v_BitmapClearBit(uint8 * const,uint32) */
    // 3120: 'Magic Numbers' are commented in the code
    // 0492: Pointer usage as array can not be omitted here
    //
    // PRQA S 0506,3120,0492 3
    const uint32 ui32_ElemIndex = ui32_Bitnum >> 3u; // div 8
    ui32_Bitnum -= ui32_ElemIndex << 3u; // mult 8
    pui8_Bitmap[ui32_ElemIndex] &= ~(1u << ui32_Bitnum);
    /*#]*/
}

/*## operation IC_e_ImageCounterToFrameType(const uint16) */
IC_E_FRAMETYPE IC_e_ImageCounterToFrameType(const uint16 ui16_ImageCounter) {
    /*#[ operation IC_e_ImageCounterToFrameType(const uint16) */
    IC_E_FRAMETYPE e_Type = IC_e_FRAMETYPE_ODD;
    
    if ((ui16_ImageCounter & 1) == 0)
    {
      e_Type = IC_e_FRAMETYPE_EVEN;
    }
    else
    {
      e_Type = IC_e_FRAMETYPE_ODD;
    }
    return e_Type;
    /*#]*/
}

/*## operation IC_b_IsBigEndian() */
boolean IC_b_IsBigEndian(void) {
    /*#[ operation IC_b_IsBigEndian() */
    boolean b_Ret;
    
    // Use pre-defined 16-bit value and evaluate value of the first byte:
    if (( *((uint8 const*)&IC_cui16_EndianessCheck)) == 1) // PRQA S 0310
    {
      // First byte is = 0x01 ==> We have big endian
      b_Ret = b_TRUE;
    }
    else
    {
      // First byte is = 0x00 ==> We have little endian
      b_Ret = b_FALSE;
    }
    return b_Ret;
    /*#]*/
}

/*## operation IC_ui16_RectWidth(const IC_S_Rect_ui16 * const) */
uint16 IC_ui16_RectWidth(const IC_S_Rect_ui16 * const ps_Rect) {
    /*#[ operation IC_ui16_RectWidth(const IC_S_Rect_ui16 * const) */
    // PRQA S 0506 1
    return (ps_Rect->ui16_x2 - ps_Rect->ui16_x1) + 1;
    /*#]*/
}

/*## operation IC_ui16_RectHeight(const IC_S_Rect_ui16 * const) */
uint16 IC_ui16_RectHeight(const IC_S_Rect_ui16 * const ps_Rect) {
    /*#[ operation IC_ui16_RectHeight(const IC_S_Rect_ui16 * const) */
    // PRQA S 0506 1
    return (ps_Rect->ui16_y2 - ps_Rect->ui16_y1) + 1;
    /*#]*/
}

/*## operation IC_ui16_RoiEndX(const IC_S_Roi * const) */
uint16 IC_ui16_RoiEndX(const IC_S_Roi * const ps_Roi) {
    /*#[ operation IC_ui16_RoiEndX(const IC_S_Roi * const) */
    // PRQA S 0506 1
    return (ps_Roi->ui16_StartX + ps_Roi->ui16_Width) - 1;
    /*#]*/
}

/*## operation IC_ui16_RoiEndY(const IC_S_Roi * const) */
uint16 IC_ui16_RoiEndY(const IC_S_Roi * const ps_Roi) {
    /*#[ operation IC_ui16_RoiEndY(const IC_S_Roi * const) */
    // PRQA S 0506 1
    return (ps_Roi->ui16_StartY + ps_Roi->ui16_Height) - 1;
    /*#]*/
}


/*#[ ignore */

#ifdef __cplusplus
}
#endif

/*#]*/


/*********************************************************************
	File Path: ..\..\..\04_Engineering\01_Source_Code\Algo\ic\ic_common.c
*********************************************************************/
