//* **********************************************************************
//  COMPANY:         $CompanyInfo: CONFIDENTIAL AND PROPRIETARY PROPERTY OF CONTINENTAL AG , A.D.C. GmbH  -  ALL RIGHTS RESERVED $
//  
//  PROJECT:         MFC30x_MCU
//  CPU:             MPC5675K
//  
//  PACKAGE:         $Source: ic_embdat_proc.c $ $Revision: 1.1 $
//  MKS Date:        $Date: 2021/12/13 17:25:49CET $
//  
//  RHAPSODY:        7.5.3
//  COMPONENT:       IC
//  CONFIGURATION:   DefaultConfig
//  MODEL ELEMENT:   ic_embdat_proc
//  MODULNAME:       ..\..\..\04_Engineering\01_Source_Code\Algo\ic\ic_embdat_proc.c
//  LOGIN:           uidt3974  
//  
//  
//  
//  AUTHOR:          $Author: Wang, David (Wangd3) $
//! CREATION DATE:   Fri, 20, Jul 2012  9:41 W. Europe Daylight Time PM 
//**************************************************************************** */

/*## auto_generated */
#include "ic_embdat_proc.h"
/*## dependency ic_cfg */
#include "ic_cfg.h"
/*## auto_generated */
#include <string.h>
/*## package Ic_Pkg */

/*## class TopLevel::ic_embdat_proc */


/*#[ ignore */
#ifdef __cplusplus
extern "C"
{
#endif

/*#]*/


/*## type IEDP_S_EmbdStatEntry16 */
typedef struct IEDP_S_EmbdStatEntry16 {
    uint16 ui16_Msb;		/*## attribute ui16_Msb */
    uint16 ui16_Lsb;		/*## attribute ui16_Lsb */
} IEDP_S_EmbdStatEntry16;

/*## type IEDP_S_EmbdStatEntry20 */
typedef struct IEDP_S_EmbdStatEntry20 {
    uint16 ui16_Msb;		/*## attribute ui16_Msb */
    uint16 ui16_Lsb;		/*## attribute ui16_Lsb */
} IEDP_S_EmbdStatEntry20;

/*## type IEDP_S_EmbStatIdentifier */
typedef struct IEDP_S_EmbStatIdentifier {
    uint16 ui16_Value1;		/*## attribute ui16_Value1 */
    uint16 ui16_Value2;		/*## attribute ui16_Value2 */
} IEDP_S_EmbStatIdentifier;

/*## type IEDP_S_EmbdStatLine1 */
typedef struct IEDP_S_EmbdStatLine1 {
    IEDP_S_EmbStatIdentifier s_Identifier;		/*## attribute s_Identifier */
    IEDP_S_EmbdStatEntry16 s_FrameCounter;		/*## attribute s_FrameCounter */
    IEDP_S_EmbdStatEntry16 s_FrameId;		/*## attribute s_FrameId */
    IEDP_S_EmbdStatEntry20 as_Histogram[ICCFG_cui16_NumHistogramValues];		/*## attribute as_Histogram */
} IEDP_S_EmbdStatLine1;

/*## type IEDP_S_EmbdStatLine2 */
typedef struct IEDP_S_EmbdStatLine2 {
    IEDP_S_EmbStatIdentifier s_Identifier;		/*## attribute s_Identifier */
    IEDP_S_EmbdStatEntry20 s_Mean;		/*## attribute s_Mean */
    IEDP_S_EmbdStatEntry20 s_HistBegin;		/*## attribute s_HistBegin */
    IEDP_S_EmbdStatEntry20 s_HistEnd;		/*## attribute s_HistEnd */
    IEDP_S_EmbdStatEntry20 s_LowEndMean;		/*## attribute s_LowEndMean */
    IEDP_S_EmbdStatEntry20 s_PercLowEnd;		/*## attribute s_PercLowEnd */
    IEDP_S_EmbdStatEntry20 s_NormAbsDev;		/*## attribute s_NormAbsDev */
} IEDP_S_EmbdStatLine2;

/*## attribute IEDP_b_Initialized */
static boolean IEDP_b_Initialized = b_FALSE;

//  Number of pixels in the embedded register preamble
/*## attribute IEDP_cui16_EMBDREGS_PREAMBLE_LENGTH */
#define IEDP_cui16_EMBDREGS_PREAMBLE_LENGTH 5

/*## attribute IEDP_aui16_RegToPixelMap */
static uint16 IEDP_aui16_RegToPixelMap[IMGREG_cui16_NumImagerRegs];

//  The contents of this array will be compared/checked against start of embedded register line #1
//  PRQA S 3218,3120 2
/*## attribute IEDP_caui16_RegLine1Preamble */
static const uint16 IEDP_caui16_RegLine1Preamble[IEDP_cui16_EMBDREGS_PREAMBLE_LENGTH] = { 0x00a0, 0x0aa0, 0x0300, 0x0a50, 0x0000 };

//  Number of tags in the embedded register line #1 after the preamble
/*## attribute IEDP_cui16_RegLine1NumTagsAfterPreamble */
#define IEDP_cui16_RegLine1NumTagsAfterPreamble 304

//  Number of tags in the embedded register line #2 after the preamble
/*## attribute IEDP_cui16_RegLine2NumTagsAfterPreamble */
#define IEDP_cui16_RegLine2NumTagsAfterPreamble 188

/*## attribute IEDP_cui16_ADDRESSMAP_LINE2_MARKER */
#define IEDP_cui16_ADDRESSMAP_LINE2_MARKER 0x8000

/*## attribute IEDP_cui16_STATLINE1_ID1 */
#define IEDP_cui16_STATLINE1_ID1 0x00b0

/*## attribute IEDP_cui16_STATLINE1_ID2 */
#define IEDP_cui16_STATLINE1_ID2 0x07b0

/*## attribute IEDP_cui16_STATLINE2_ID1 */
#define IEDP_cui16_STATLINE2_ID1 0x00b0

/*## attribute IEDP_cui16_STATLINE2_ID2 */
#define IEDP_cui16_STATLINE2_ID2 0x0030

/*## attribute IEDP_cui16_EMBDREGS_SR_LSB */
#define IEDP_cui16_EMBDREGS_SR_LSB 4

/*## attribute IEDP_cui16_EMBDREGS_SL_MSB */
#define IEDP_cui16_EMBDREGS_SL_MSB 4

//  The contents of this array will be compared/checked against start of embedded register line #2
//  PRQA S 3218,3120 2
/*## attribute IEDP_caui16_RegLine2Preamble */
static const uint16 IEDP_caui16_RegLine2Preamble[IEDP_cui16_EMBDREGS_PREAMBLE_LENGTH] = { 0x00a0, 0x0aa0, 0x0310, 0x0a50, 0x0360 };

//*****************************************************************************
//  Functionname:  IEDP_si16_BuildRegPixelMap
//  
//  This function creates a lookup-table for mapping 'IMGREG_E_SENSOR_REG' to a 'PixelOffset'.
//  The map can be used for fast lookup of the embedded pixels, which contains register values
//  of a specific register.
//  
//  NOTE: The map is _not_ complete, as some registers are not contained in the embedded data.
//  
//    
//  
//  return         sint16
//**************************************************************************** */
/*## operation IEDP_si16_BuildRegPixelMap() */
static sint16 IEDP_si16_BuildRegPixelMap(void);

//*****************************************************************************
//  Functionname:  IEDP_ui16_ExtractStat16
//  
//  Extracts a 16 bit value from statistics data
//  
//  Parameter:     const IEDP_S_EmbdStatEntry16 * const ps_Entry   <In>
//  
//    
//  
//  return         IC_INLINE_UI16
//**************************************************************************** */
/*## operation IEDP_ui16_ExtractStat16(const IEDP_S_EmbdStatEntry16 * const) */
static IC_INLINE_UI16 IEDP_ui16_ExtractStat16(const IEDP_S_EmbdStatEntry16 * const ps_Entry);

//*****************************************************************************
//  Functionname:  IEDP_ui32_ExtractStat20
//  
//  Extracts a 20 bit value from statistics data
//  
//  Parameter:     const IEDP_S_EmbdStatEntry20 * const ps_Entry   <In>
//  
//    
//  
//  return         IC_INLINE_UI32
//**************************************************************************** */
/*## operation IEDP_ui32_ExtractStat20(const IEDP_S_EmbdStatEntry20 * const) */
static IC_INLINE_UI32 IEDP_ui32_ExtractStat20(const IEDP_S_EmbdStatEntry20 * const ps_Entry);

/*## operation IEDP_si16_Init() */
sint16 IEDP_si16_Init(void) {
    /*#[ operation IEDP_si16_Init() */
    IMGREG_E_ERROR e_ImgRegRet = IMGREG_e_ERR_OK;
    sint16 si16_Ret = IEDP_csi16_NOERROR;
    
    // Reset module variables
    IEDP_b_Initialized = b_FALSE;
    (void)memset(IEDP_aui16_RegToPixelMap, 0, (size_t)sizeof(IEDP_aui16_RegToPixelMap));
    
    // Initialize imager register module, which provides a mapping from "RegisterName -> RegisterAddress"
    e_ImgRegRet = IMGREG_e_Init();
    if (IMGREG_e_ERR_OK != e_ImgRegRet)
    {
      si16_Ret = IEDP_csi16_ERROR_IMGREG_INIT;
    }
    
    if (IEDP_csi16_NOERROR == si16_Ret)
    {
      // Now build the map from "RegisterName -> Pixel Offset"
      si16_Ret = IEDP_si16_BuildRegPixelMap();
    }
    
    if (IEDP_csi16_NOERROR == si16_Ret)
    {
      // We're done
      IEDP_b_Initialized = b_TRUE;
    }
    
    return si16_Ret;
    /*#]*/
}

/*## operation IEDP_si16_BuildRegPixelMap() */
static sint16 IEDP_si16_BuildRegPixelMap(void) {
    /*#[ operation IEDP_si16_BuildRegPixelMap() */
    #define BLOCK_LINE1         0u
    #define BLOCK_LINE2_A       1u
    #define BLOCK_LINE2_B       2u
    #define PIXELS_PER_REGISTER 4u
    #define ADDRESS_INCREMENT   2u
    
    IMGREG_E_SENSOR_REG e_Register;
    uint16 ui16_PixIndex      = 0;
    uint32 ui32_RegBlockIndex = 0;
    uint32 ui32_RegAddrPix    = 0;
    uint32 ui32_RegAddr       = 0;
    uint32 ui32_LastRegAddr   = 0;
    
    // The two embedded register data lines starts with the following data:
    //   0x0A0 | 0xAA0 | 0x300 | 0xA50 | 0x000 | 0x5A0 | 0x240 | 0x5A0 | 0x000 | 0x5A0 | ...
    //   0x0A0 | 0xAA0 | 0x310 | 0xA50 | 0x360 | 0x5A0 | 0x000 | 0x5A0 | 0x000 | 0x5A0 | ...
    //    IV      TAG    ADR_H    TAG    ADR_L    TAG    VAL_H    TAG    VAL_L    TAG
    //
    //  IV    => Initial value
    //  TAG   => Every second pixel is a tag. When a register-address follows, the TAG is 0xAA0,
    //           register values are prefixed by 0x5A.
    //  ADR_H => High byte of the register address.
    //  ADR_L => Low  byte of the register address.
    //  VAL_H => High byte of the register value.
    //  VAL_L => Low  byte of the register value.
    //
    //  NOTE: The bytes are embedded in the upper bits [11..4] in 12-bit output mode. Therefore
    //        the lowest nibble is always zero.
    
    // Register setup:
    //   Line #1 contains registers 0x3000 - 0x312F
    //   Line #2 contains registers 0x3136 - 0x31BF; 0x31D0 - 0x31FF
    //
    // So we have THREE blocks of registers in the embedded data.
    
    // Build the register --> address map
    e_Register = (IMGREG_E_SENSOR_REG)0; /* Start with first register */  // PRQA S 1484
    ui32_RegAddr = IMGREG_ui16_GetRegAddr(e_Register);
    for (ui32_RegBlockIndex = 0; ui32_RegBlockIndex <= BLOCK_LINE2_B; ui32_RegBlockIndex++)
    {
      // Setup variables for current block. Magic numbers are commented in the code:
      // PRQA S 3120 REGBLOCK_PARAMS
      switch (ui32_RegBlockIndex)
      {
      case BLOCK_LINE1:
        // First embedded register line:
        ui16_PixIndex    = 6;      // First register value is at pixel offset 6 in line 1
        ui32_RegAddrPix  = 0x3000; // Block starts with register 0x3000
        ui32_LastRegAddr = 0x312f; // Block ends   with register 0x312f
        break;
      case BLOCK_LINE2_A:
        // Second embedded register line: part #1
        ui16_PixIndex    = 6 | IEDP_cui16_ADDRESSMAP_LINE2_MARKER; // First register value is at pixel offset 6 in line 2
        ui32_RegAddrPix  = 0x3136; // Block starts with register 0x3136
        ui32_LastRegAddr = 0x31bf; // Block ends   with register 0x31bf
        break;
      case BLOCK_LINE2_B:
        // Second embedded register line: part #2 (proceed after part #1)
        ui16_PixIndex   += PIXELS_PER_REGISTER; // Skip embedded register address data (4 pixels):
        ui32_RegAddrPix  = 0x31d0;              // Block continues with register 0x31d0
        ui32_LastRegAddr = 0x31ff;              // Block ends      with register 0x31ff
        break;
      default:
        /* Never happens */
        break;
      }
      // PRQA L:REGBLOCK_PARAMS
    
      // Process current line
      while (ui32_RegAddrPix <= ui32_LastRegAddr)
      {
        // Lookup enum value of the register which has the same address as the register
        // of the current pixel.
        //
        // Note: The register addresses of the registers in the enum are always
        //       monotonically increasing.
        while ((ui32_RegAddr < ui32_RegAddrPix) && (e_Register < IMGREG_e_REG__LAST_ENTRY_))
        {
          e_Register++; // PRQA S 1319,1481
          ui32_RegAddr = IMGREG_ui16_GetRegAddr(e_Register);
        }
    
        // Register found? Then create map-entry:
        if (ui32_RegAddr == ui32_RegAddrPix)
        {
          IEDP_aui16_RegToPixelMap[e_Register] = ui16_PixIndex;
        }
    
        // Move to next data-set
        ui32_RegAddrPix += ADDRESS_INCREMENT;
        ui16_PixIndex   += PIXELS_PER_REGISTER;
      }
    }
    
    return IEDP_csi16_NOERROR;
    /*#]*/
}

/*## operation IEDP_ui16_ExtractStat16(const IEDP_S_EmbdStatEntry16 * const) */
static IC_INLINE_UI16 IEDP_ui16_ExtractStat16(const IEDP_S_EmbdStatEntry16 * const ps_Entry) {
    /*#[ operation IEDP_ui16_ExtractStat16(const IEDP_S_EmbdStatEntry16 * const) */
    // PRQA S 3120,0506 2
    return (ps_Entry->ui16_Lsb >> 2u)
        | ((ps_Entry->ui16_Msb >> 2u) << 8u);
    /*#]*/
}

/*## operation IEDP_ui32_ExtractStat20(const IEDP_S_EmbdStatEntry20 * const) */
static IC_INLINE_UI32 IEDP_ui32_ExtractStat20(const IEDP_S_EmbdStatEntry20 * const ps_Entry) {
    /*#[ operation IEDP_ui32_ExtractStat20(const IEDP_S_EmbdStatEntry20 * const) */
    // PRQA S 3120,0506 2
    return ((uint32)ps_Entry->ui16_Lsb >> 2u)
        | (((uint32)ps_Entry->ui16_Msb >> 2u) << 10u);
    /*#]*/
}

/*## operation IEDP_si16_ExtractRegisters(const uint16 * const,const uint16 * const,IC_S_RegBuff * const) */
sint16 IEDP_si16_ExtractRegisters(const uint16 * const pui16_EmbeddedLine1, const uint16 * const pui16_EmbeddedLine2, IC_S_RegBuff * const ps_Regs) {
    /*#[ operation IEDP_si16_ExtractRegisters(const uint16 * const,const uint16 * const,IC_S_RegBuff * const) */
    sint16 si16_Ret         = IEDP_csi16_NOERROR;
    uint32 ui32_RegIndex    = 0;
    uint16 ui16_PixelNum    = 0;
    
    // Check for NULL pointers
    if ( (NULL == pui16_EmbeddedLine1)
      || (NULL == pui16_EmbeddedLine2)
      || (NULL == ps_Regs))
    {
      si16_Ret = IEDP_csi16_ERROR_NULLPOINTER;
    }
    else if (b_FALSE == IEDP_b_Initialized)
    {
      si16_Ret = IEDP_csi16_ERROR_NOINIT;
    }
    else
    {
      // Extract register data
      for (ui32_RegIndex = 0; ui32_RegIndex < IMGREG_cui16_NumImagerRegs; ui32_RegIndex++)
      {
        // Get pixel index from MAP
        ui16_PixelNum = IEDP_aui16_RegToPixelMap[ui32_RegIndex];
    
        // Lookup which line contains the register value
        if (ui16_PixelNum == 0u)
        {
          // Entry not mapped (register not contained in embedded data), so skip register
        }
        else if ((ui16_PixelNum & IEDP_cui16_ADDRESSMAP_LINE2_MARKER) != 0)
        {
          // Register value is in line 2. Remove marker from pixel index and extract register value.
          ui16_PixelNum &= (uint16)(~IEDP_cui16_ADDRESSMAP_LINE2_MARKER); // PRQA S 0277
    
          // A register value is split over 4 pixels: [LSB | TAG | MSB | TAG]
          // The tags are ignored here, as they do not contain register data. LSB and MSB are each
          // stored in bits [11..4], all other bits are ZERO:
          //
          // PRQA S 0492,3120 2
          ps_Regs->aRegs[ui32_RegIndex] = (pui16_EmbeddedLine2[ui16_PixelNum  ] << IEDP_cui16_EMBDREGS_SL_MSB)
                                        | (pui16_EmbeddedLine2[ui16_PixelNum+2] >> IEDP_cui16_EMBDREGS_SR_LSB);
        }
        else
        {
          // Register value is in line 1. Extract register value.
          // PRQA S 0492,3120 2
          ps_Regs->aRegs[ui32_RegIndex] = (pui16_EmbeddedLine1[ui16_PixelNum  ] << IEDP_cui16_EMBDREGS_SL_MSB)
                                        | (pui16_EmbeddedLine1[ui16_PixelNum+2] >> IEDP_cui16_EMBDREGS_SR_LSB);
        }
      }
    }
    return si16_Ret;
    /*#]*/
}

/*## operation IEDP_si16_ExtractStatistics(const uint16 * const,const uint16 * const,IC_S_EmbeddedStatData * const) */
sint16 IEDP_si16_ExtractStatistics(const uint16 * const pui16_StatisticsLine1, const uint16 * const pui16_StatisticsLine2, IC_S_EmbeddedStatData * const ps_Data) {
    /*#[ operation IEDP_si16_ExtractStatistics(const uint16 * const,const uint16 * const,IC_S_EmbeddedStatData * const) */
    #define PERC_LOW_END_SCALOR 65536.0f
    
    sint16  si16_Ret   = IEDP_csi16_NOERROR;
    uint16  ui16_PercLowEndReg;
    IEDP_S_EmbdStatLine1 const *ps_Line1;
    IEDP_S_EmbdStatLine2 const *ps_Line2;
    
    // Check for NULL pointers
    if  ((NULL == pui16_StatisticsLine1)
      || (NULL == pui16_StatisticsLine2)
      || (NULL == ps_Data))
    {
      si16_Ret = IEDP_csi16_ERROR_NULLPOINTER;
    }
    else
    {
      // Cast to expected data structure
      ps_Line1 = (IEDP_S_EmbdStatLine1 const *)pui16_StatisticsLine1; // PRQA S 0310
      ps_Line2 = (IEDP_S_EmbdStatLine2 const *)pui16_StatisticsLine2; // PRQA S 0310
    
      // Check for identifiers (line 1)
      if ( (ps_Line1->s_Identifier.ui16_Value1 != IEDP_cui16_STATLINE1_ID1)
        || (ps_Line1->s_Identifier.ui16_Value2 != IEDP_cui16_STATLINE1_ID2))
      {
        si16_Ret = IEDP_csi16_ERROR_EMBEDDED_INVALID_TAG;
      }
    
      if (IEDP_csi16_NOERROR == si16_Ret)
      {
        // Check for identifier (line 2)
        if ( (ps_Line2->s_Identifier.ui16_Value1 != IEDP_cui16_STATLINE2_ID1)
          || (ps_Line2->s_Identifier.ui16_Value2 != IEDP_cui16_STATLINE2_ID2))
        {
          si16_Ret = IEDP_csi16_ERROR_EMBEDDED_INVALID_TAG;
        }
      }
    
      if (IEDP_csi16_NOERROR == si16_Ret)
      {
        // Extract statistics data.
        // NOTE: Some values are split into LSB / MSB (8-bit), others are split into 10-bit pairs!
        //       See embedded data appnote from Aptina.
        ps_Data->ui16_FrameCounter = IEDP_ui16_ExtractStat16(&ps_Line1->s_FrameCounter);
        ps_Data->ui16_FrameId      = IEDP_ui16_ExtractStat16(&ps_Line1->s_FrameId);
        ps_Data->ui32_LumaMean     = IEDP_ui32_ExtractStat20(&ps_Line2->s_Mean);
        ps_Data->ui32_LowEndMean   = IEDP_ui32_ExtractStat20(&ps_Line2->s_LowEndMean);
        ui16_PercLowEndReg         = (uint16)IEDP_ui32_ExtractStat20(&ps_Line2->s_PercLowEnd);
    
        // Convert values
        ps_Data->f32_PercLowEnd = (float32)ui16_PercLowEndReg / PERC_LOW_END_SCALOR;
      }
    }
    
    return si16_Ret;
    /*#]*/
}

/*## operation IEDP_si16_ExtractHistogram(const uint16 * const,IC_S_Histogram * const) */
sint16 IEDP_si16_ExtractHistogram(const uint16 * const pui16_StatisticsLine1, IC_S_Histogram * const ps_Histogram) {
    /*#[ operation IEDP_si16_ExtractHistogram(const uint16 * const,IC_S_Histogram * const) */
    sint16  si16_Ret   = IEDP_csi16_NOERROR;
    uint32  ui32_Index = 0;
    IEDP_S_EmbdStatLine1 const * ps_EmbStatLine;
    
    // Check NULL pointer
    if ((NULL == pui16_StatisticsLine1) || (NULL == ps_Histogram))
    {
      si16_Ret = IEDP_csi16_ERROR_NULLPOINTER;
    }
    else
    {
    
      // Cast to expected structure
      ps_EmbStatLine = (IEDP_S_EmbdStatLine1 const *)pui16_StatisticsLine1; // PRQA S 0310
    
      // Check for identifier
      if ((ps_EmbStatLine->s_Identifier.ui16_Value1 != IEDP_cui16_STATLINE1_ID1)
       || (ps_EmbStatLine->s_Identifier.ui16_Value2 != IEDP_cui16_STATLINE1_ID2))
      {
        si16_Ret = IEDP_csi16_ERROR_EMBEDDED_INVALID_TAG;
      }
    
      if (IEDP_csi16_NOERROR == si16_Ret)
      {
        // Extract histogram values
        for (ui32_Index = 0; ui32_Index < ICCFG_cui16_NumHistogramValues; ui32_Index++)
        {
          ps_Histogram->aui32_Bins[ui32_Index] = IEDP_ui32_ExtractStat20(&ps_EmbStatLine->as_Histogram[ui32_Index]);
        }
      }
    }
    return si16_Ret;
    /*#]*/
}

/*## operation IEDP_si16_CheckRegisterLine(const uint16 * const,const uint16,uint16 * const) */
sint16 IEDP_si16_CheckRegisterLine(const uint16 * const pui16_EmbDatPtr, const uint16 ui16_EmbeddedLineNum, uint16 * const pui16_FailedPixelPos) {
    /*#[ operation IEDP_si16_CheckRegisterLine(const uint16 * const,const uint16,uint16 * const) */
    #define IEDP_cui16_TAG_REGADDR        0x0AA0
    #define IEDP_cui16_TAG_ADDR_SEPERATOR 0x0A50
    #define IEDP_cui16_TAG_DATA_SEPERATOR 0x05A0
    #define IEDP_cui16_PADDING_BYTES      0x0070
    
    sint16 si16_Ret   = IEDP_csi16_NOERROR;
    uint32 ui32_Index = 0;
    uint16 const * pui16_PreamblePtr = 0;
    uint16 ui16_PreambleSize = 0;
    uint16 ui16_NumTagsAfterPreamble = 0;
    uint16 ui16_PixelIndex = 0;
    
    // Check input parameters
    if (NULL == pui16_EmbDatPtr)
    {
      si16_Ret = IEDP_csi16_ERROR_NULLPOINTER;
    }
    else if (ui16_EmbeddedLineNum > 1)
    {
      si16_Ret = IEDP_csi16_ERROR_LINENUM;
    }
    else
    {
      // *************************************************************
      // *                 Check start of line                       *
      // *************************************************************
    
      // Determine parameters for selected embedded data line
      if (0 == ui16_EmbeddedLineNum)
      {
        pui16_PreamblePtr = IEDP_caui16_RegLine1Preamble;
        ui16_PreambleSize = (uint16)sizeof(IEDP_caui16_RegLine1Preamble) / (uint16)sizeof(IEDP_caui16_RegLine1Preamble[0]);
        ui16_NumTagsAfterPreamble = IEDP_cui16_RegLine1NumTagsAfterPreamble;
      }
      else
      {
        pui16_PreamblePtr = IEDP_caui16_RegLine2Preamble;
        ui16_PreambleSize = (uint16)sizeof(IEDP_caui16_RegLine2Preamble) / (uint16)sizeof(IEDP_caui16_RegLine2Preamble[0]);
        ui16_NumTagsAfterPreamble = IEDP_cui16_RegLine2NumTagsAfterPreamble;
      }
    
      // Check start of line
      for (ui32_Index = 0; ui32_Index < ui16_PreambleSize; ui32_Index++)
      {
        // PRQA S 0491,0492 1
        if (pui16_EmbDatPtr[ui16_PixelIndex] != pui16_PreamblePtr[ui32_Index])
        {
          si16_Ret = IEDP_csi16_ERROR_EMBEDDED_INVALID_PREAMBLE;
          break;
        }
        ui16_PixelIndex++;
      }
    
      // *************************************************************
      // *                 Check tags inside line                    *
      // *************************************************************
      if (IEDP_csi16_NOERROR == si16_Ret)
      {
        // Only tags with value 0x5A0 and 0xA50 are allowed
        for (ui32_Index = 0; ui32_Index < ui16_NumTagsAfterPreamble; ui32_Index++)
        {
          // PRQA S 0491,0492 3
          if (  (pui16_EmbDatPtr[ui16_PixelIndex] != IEDP_cui16_TAG_DATA_SEPERATOR)
             && (pui16_EmbDatPtr[ui16_PixelIndex] != IEDP_cui16_TAG_REGADDR)
             && (pui16_EmbDatPtr[ui16_PixelIndex] != IEDP_cui16_TAG_ADDR_SEPERATOR))
          {
            break;
          }
          ui16_PixelIndex += 2; // PRQA S 3120
        }
    
        // Check if loop aborted before last entry
        if (ui32_Index != ui16_NumTagsAfterPreamble)
        {
          si16_Ret = IEDP_csi16_ERROR_EMBEDDED_INVALID_TAG;
        }
      }
    
      // *************************************************************
      // *                    Check end of line                      *
      // *************************************************************
      if (IEDP_csi16_NOERROR == si16_Ret)
      {
        // Lines are padded with 0x70, so look if there is at least one value
        // PRQA S 0492 1
        if (pui16_EmbDatPtr[ui16_PixelIndex] != IEDP_cui16_PADDING_BYTES)
        {
          si16_Ret = IEDP_csi16_ERROR_EMBEDDED_INVALID_TAG;
        }
      }
    }
    
    // If we had a problem, then return failed pixel to caller
    if ((IEDP_csi16_NOERROR != si16_Ret) && (NULL != pui16_FailedPixelPos))
    {
      *pui16_FailedPixelPos = ui16_PixelIndex;
    }
    
    return si16_Ret;
    
    // PRQA S 7002 3
    /*#]*/
}

/*## operation IEDP_ui16_GetFrameNumber(const uint16 * const) */
uint16 IEDP_ui16_GetFrameNumber(const uint16 * const pui16_EmbeddedLine1) {
    /*#[ operation IEDP_ui16_GetFrameNumber(const uint16 * const) */
    uint16 ui16_Ret = 0;
    uint16 ui16_PixelNum = 0;
    
    if ( (NULL    == pui16_EmbeddedLine1)
      || (b_FALSE == IEDP_b_Initialized))
    {
      ui16_Ret = 0;
    }
    else
    {
      ui16_PixelNum = IEDP_aui16_RegToPixelMap[IMGREG_e_REG_FRAME_COUNT];
      ui16_Ret = (pui16_EmbeddedLine1[ui16_PixelNum  ] << IEDP_cui16_EMBDREGS_SL_MSB)  // PRQA S 0492
               | (pui16_EmbeddedLine1[ui16_PixelNum+2] >> IEDP_cui16_EMBDREGS_SR_LSB); // PRQA S 0492,3120
    }
    
    return ui16_Ret;
    /*#]*/
}

/*## operation IEDP_si16_ExtractRegistersByTags(uint16 *,uint16 *,uint16 *) */
#ifdef WIN32
uint16 IEDP_si16_ExtractRegistersByTags(uint16 * pui16_EmbeddedLine1, uint16 * pui16_EmbeddedLine2, uint16 * pui16_Registers) {
    /*#[ operation IEDP_si16_ExtractRegistersByTags(uint16 *,uint16 *,uint16 *) */
    sint16    si16_Ret        = IEDP_csi16_NOERROR;
    uint16    ui16_RegAddr    = 0x0000u;
    uint16    ui16_RegAddrPrv = 0x0000u;
    uint8     ui8_Tag1        = 0x00u;
    uint8     ui8_Tag2        = 0x00u;
    uint8     ui8_DataH       = 0x00u;
    uint8     ui8_DataL       = 0x00u;
    uint16    ui16_Data       = 0x0000u;
    sint16    si16_WordIndex  = 0;
    uint16   *pui16_Line      = 0;
    uint16    ui16_PixelIndex = 0;
    sint16    si_LineIndex    = 0;
    IMGREG_E_SENSOR_REG e_TargetReg  = (IMGREG_E_SENSOR_REG)0;
    uint16    ui16_TargetRegAddr = 0;
    
    // Initialize first address
    ui16_TargetRegAddr = IMGREG_ui16_GetRegAddr(e_TargetReg);
    
    // Nullpointer checks
    if (0 == pui16_EmbeddedLine1 || 0 == pui16_EmbeddedLine2 || 0 == pui16_Registers)
    {
      si16_Ret = IEDP_csi16_ERROR_NULLPOINTER;
    }
    
    if (IEDP_csi16_NOERROR == si16_Ret)
    {
      // Check for identifier present
      if (pui16_EmbeddedLine1[0] != 0x00a0)
      {
        si16_Ret = IEDP_csi16_ERROR_EMBEDDED_INVALID_TAG;
      }
    }
    
    if (IEDP_csi16_NOERROR == si16_Ret)
    {
      // Initialize all with 0xBEEF (allows to identify non-existing registers)
      #if 0
      for (si16_WordIndex = 0; si16_WordIndex < ICCFG_ui16_NumImagerRegs; si16_WordIndex++)
      {
        pui16_Registers[si16_WordIndex] = 0xBEEF;
      }
      #endif
    
      // Loop trough both lines
      for (si_LineIndex = 0; si_LineIndex < 2 && IEDP_csi16_NOERROR == si16_Ret; si_LineIndex++)
      {
        pui16_Line = (si_LineIndex == 0 ? pui16_EmbeddedLine1 : pui16_EmbeddedLine2);
    
        // Loop trough all words of this line
        for (si16_WordIndex = 1; si16_WordIndex < ICCFG_cui16_CROI_ODD_WIDTH; /* nothing */ )
        {
          // Each 16-bit word contains 8-bit pixels/values from the imager adjusted to 12-bit, so pixelformat is: 0x0XY0.
          // Shift by one hex-digit to get the "proper" value
          ui8_Tag1   = (uint8)(pui16_Line[si16_WordIndex++] >> 4);
          ui8_DataH  = (uint8)(pui16_Line[si16_WordIndex++] >> 4);
          ui8_Tag2   = (uint8)(pui16_Line[si16_WordIndex++] >> 4);
          ui8_DataL  = (uint8)(pui16_Line[si16_WordIndex++] >> 4);
          ui16_Data  = (uint16)(((uint16)(ui8_DataH) << 8) | ((uint16)(ui8_DataL)));
          if (ui8_Tag1 == 0xaa && ui8_Tag2 == 0xa5)
          {
            ui16_RegAddr = ui16_Data;
          }
          else if (ui8_Tag1 == 0x5a && ui8_Tag2 == 0x5a)
          {
    
            // Is the current register-address smaller than last TargetReg-address?
            // Addresses are assumed to be strictly increasing in this implementation!
            // (It should according to the appnote from Aptina)
            if (ui16_RegAddr < ui16_RegAddrPrv)
            {
              si16_Ret = IEDP_csi16_ERROR_EMBEDDED_REGADDR_NOT_INCREASING;
              break;
            }
    
            // Find matching register in enum
            while (ui16_TargetRegAddr < ui16_RegAddr && e_TargetReg < IMGREG_e_REG__LAST_ENTRY_)
            {
              e_TargetReg++;
              ui16_TargetRegAddr = IMGREG_ui16_GetRegAddr(e_TargetReg);
            }
    
            // Are we at the end of the enum? Then exit
            if (e_TargetReg == IMGREG_e_REG__LAST_ENTRY_)
            {
              break;
            }
    
            // Matching register in enum found?
            if (ui16_TargetRegAddr == ui16_RegAddr)
            {
              pui16_Registers[e_TargetReg] = ui16_Data;
              ui16_PixelIndex = si16_WordIndex - 3;
              if (si_LineIndex == 1)
              {
                ui16_PixelIndex |= IEDP_cui16_ADDRESSMAP_LINE2_MARKER;
              }
              IEDP_aui16_RegToPixelMap[e_TargetReg] = ui16_PixelIndex;
            }
            ui16_RegAddrPrv = ui16_RegAddr;
            ui16_RegAddr += 2;
          }
          else if (ui8_Tag1 == 0x07)
          {
            // End of line
            break;
          }
          else
          {
            // ERROR
            si16_Ret = IEDP_csi16_ERROR_EMBEDDED_INVALID_TAG;
            break;
          }
        }
      }
    }
    return si16_Ret;
    /*#]*/
}
#endif


/*#[ ignore */

#ifdef __cplusplus
}
#endif

/*#]*/


/*********************************************************************
	File Path: ..\..\..\04_Engineering\01_Source_Code\Algo\ic\ic_embdat_proc.c
*********************************************************************/
