//* **********************************************************************
//  COMPANY:         $CompanyInfo: CONFIDENTIAL AND PROPRIETARY PROPERTY OF CONTINENTAL AG , A.D.C. GmbH  -  ALL RIGHTS RESERVED $
//  
//  PROJECT:         MFC30x_MCU
//  CPU:             MPC5675K
//  
//  PACKAGE:         $Source: ic_embdat_proc.h $ $Revision: 1.1 $
//  MKS Date:        $Date: 2021/12/13 17:25:50CET $
//  
//  RHAPSODY:        7.5.3
//  COMPONENT:       IC
//  CONFIGURATION:   DefaultConfig
//  MODEL ELEMENT:   ic_embdat_proc
//  MODULNAME:       ..\..\..\04_Engineering\01_Source_Code\Algo\ic\ic_embdat_proc.h
//  LOGIN:           uidt3974  
//  
//  
//  
//  AUTHOR:          $Author: Wang, David (Wangd3) $
//! CREATION DATE:   Fri, 20, Jul 2012  9:41 W. Europe Daylight Time PM 
//**************************************************************************** */

#ifndef ic_embdat_proc_H
#define ic_embdat_proc_H

/*## dependency ic_registers */
#include "ic_registers.h"
/*## dependency ic_types */
#include "ic_types.h"
/*## package Ic_Pkg */

/*## class TopLevel::ic_embdat_proc */


/*#[ ignore */

#ifdef __cplusplus
extern "C"
{
#endif

/*#]*/


/*## attribute IEDP_csi16_NOERROR */
#define IEDP_csi16_NOERROR 0

/*## attribute IEDP_csi16_ERROR_EMBEDDED_INVALID_TAG */
#define IEDP_csi16_ERROR_EMBEDDED_INVALID_TAG 3

/*## attribute IEDP_csi16_ERROR_EMBEDDED_INVALID_REGADDRESS */
#define IEDP_csi16_ERROR_EMBEDDED_INVALID_REGADDRESS 4

/*## attribute IEDP_csi16_ERROR_EMBEDDED_REGADDR_NOT_INCREASING */
#define IEDP_csi16_ERROR_EMBEDDED_REGADDR_NOT_INCREASING 5

/*## attribute IEDP_csi16_ERROR_ADDRESSMAP_NOT_BUILD */
#define IEDP_csi16_ERROR_ADDRESSMAP_NOT_BUILD 6

/*## attribute IEDP_csi16_ERROR_EMBEDDED_INVALID_PREAMBLE */
#define IEDP_csi16_ERROR_EMBEDDED_INVALID_PREAMBLE 7

/*## attribute IEDP_csi16_ERROR_NULLPOINTER */
#define IEDP_csi16_ERROR_NULLPOINTER 8

/*## attribute IEDP_csi16_ERROR_IMGREG_INIT */
#define IEDP_csi16_ERROR_IMGREG_INIT 9

/*## attribute IEDP_csi16_ERROR_NOINIT */
#define IEDP_csi16_ERROR_NOINIT 10

/*## attribute IEDP_csi16_ERROR_LINENUM */
#define IEDP_csi16_ERROR_LINENUM 11

/***    User explicit entries    ***/


/* Operations */

//*****************************************************************************
//  Functionname:  IEDP_si16_Init
//  
//  Initializes this module.
//  
//    
//  
//  return         sint16
//**************************************************************************** */
/*## operation IEDP_si16_Init() */
sint16 IEDP_si16_Init(void);

//*****************************************************************************
//  Functionname:  IEDP_si16_ExtractRegisters
//  
//  Extracts embedded register data by using a lookup table that directly maps registers to pixels.
//  This is much faster than analyzing the embedded data by using the embedded tags.
//  Nevertheless the consistency of the embedded lines should be checked by calling
//  IEDP_si_CheckEmbeddedRegisterLine.
//  
//  Parameter:     const uint16 * const pui16_EmbeddedLine1   <In>
//  
//  
//  Parameter:     const uint16 * const pui16_EmbeddedLine2   <In>
//  
//  
//  Parameter:     IC_S_RegBuff * const ps_Regs   <In>
//  
//    
//  
//  return         sint16
//**************************************************************************** */
/*## operation IEDP_si16_ExtractRegisters(const uint16 * const,const uint16 * const,IC_S_RegBuff * const) */
sint16 IEDP_si16_ExtractRegisters(const uint16 * const pui16_EmbeddedLine1, const uint16 * const pui16_EmbeddedLine2, IC_S_RegBuff * const ps_Regs);

//*****************************************************************************
//  Functionname:  IEDP_si16_ExtractStatistics
//  
//  Extracts embedded statistics data from the statistics lines
//  
//  Parameter:     const uint16 * const pui16_StatisticsLine1   <In>
//  
//  
//  Parameter:     const uint16 * const pui16_StatisticsLine2   <In>
//  
//  
//  Parameter:     IC_S_EmbeddedStatData * const ps_Data   <In>
//  
//    
//  
//  return         sint16
//**************************************************************************** */
/*## operation IEDP_si16_ExtractStatistics(const uint16 * const,const uint16 * const,IC_S_EmbeddedStatData * const) */
sint16 IEDP_si16_ExtractStatistics(const uint16 * const pui16_StatisticsLine1, const uint16 * const pui16_StatisticsLine2, IC_S_EmbeddedStatData * const ps_Data);

//*****************************************************************************
//  Functionname:  IEDP_si16_ExtractHistogram
//  
//  Extracts embedded histogram data from the statistics lines
//  
//  Parameter:     const uint16 * const pui16_StatisticsLine1   <In>
//  
//  
//  Parameter:     IC_S_Histogram * const ps_Histogram   <In>
//  
//    
//  
//  return         sint16
//**************************************************************************** */
/*## operation IEDP_si16_ExtractHistogram(const uint16 * const,IC_S_Histogram * const) */
sint16 IEDP_si16_ExtractHistogram(const uint16 * const pui16_StatisticsLine1, IC_S_Histogram * const ps_Histogram);

//*****************************************************************************
//  Functionname:  IEDP_si16_CheckRegisterLine
//  
//  This checks the consistency of the embedded register data lines by looking
//  for expected fixed data and tags at fixed intervals.
//  
//  Parameter:     const uint16 * const pui16_EmbDatPtr   <In>
//  
//  
//  Parameter:     const uint16 ui16_EmbeddedLineNum   <In>
//  
//  
//  Parameter:     uint16 * const pui16_FailedPixelPos   <In>
//  
//    
//  
//  return         sint16
//**************************************************************************** */
/*## operation IEDP_si16_CheckRegisterLine(const uint16 * const,const uint16,uint16 * const) */
sint16 IEDP_si16_CheckRegisterLine(const uint16 * const pui16_EmbDatPtr, const uint16 ui16_EmbeddedLineNum, uint16 * const pui16_FailedPixelPos);

//*****************************************************************************
//  Functionname:  IEDP_ui16_GetFrameNumber
//  
//  Returns the current frame-number read from the embedded register lines.
//  
//  Parameter:     const uint16 * const pui16_EmbeddedLine1   <In>
//  
//    
//  
//  return         uint16
//**************************************************************************** */
/*## operation IEDP_ui16_GetFrameNumber(const uint16 * const) */
uint16 IEDP_ui16_GetFrameNumber(const uint16 * const pui16_EmbeddedLine1);

//*****************************************************************************
//  Functionname:  IEDP_si16_ExtractRegistersByTags
//  
//  
//  
//  Parameter:     uint16 * pui16_EmbeddedLine1   <In>
//  
//  
//  Parameter:     uint16 * pui16_EmbeddedLine2   <In>
//  
//  
//  Parameter:     uint16 * pui16_Registers   <Out>
//  
//    
//  
//  return         uint16
//**************************************************************************** */
/*## operation IEDP_si16_ExtractRegistersByTags(uint16 *,uint16 *,uint16 *) */
#ifdef WIN32
uint16 IEDP_si16_ExtractRegistersByTags(uint16 * pui16_EmbeddedLine1, uint16 * pui16_EmbeddedLine2, uint16 * pui16_Registers);
#endif

/***    User explicit entries    ***/



/*#[ ignore */

#ifdef __cplusplus
}
#endif

/*#]*/


#endif
/*********************************************************************
	File Path: ..\..\..\04_Engineering\01_Source_Code\Algo\ic\ic_embdat_proc.h
*********************************************************************/
