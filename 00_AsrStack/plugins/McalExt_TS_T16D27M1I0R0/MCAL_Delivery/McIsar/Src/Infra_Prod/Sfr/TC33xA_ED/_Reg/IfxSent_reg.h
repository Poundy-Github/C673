/**
 * \file IfxSent_reg.h
 * \brief
 * \copyright Copyright (c) 2021 Infineon Technologies AG. All rights reserved.
 *
 *
 * Version: TC33XED_UM_V2.0.0.R0
 * Specification: TC3xx User Manual V2.0.0
 * MAY BE CHANGED BY USER [yes/no]: No
 *
 *                                 IMPORTANT NOTICE
 *
 *
 * Use of this file is subject to the terms of use agreed between (i) you or 
 * the company in which ordinary course of business you are acting and (ii) 
 * Infineon Technologies AG or its licensees. If and as long as no such 
 * terms of use are agreed, use of this file is subject to following:


 * Boost Software License - Version 1.0 - August 17th, 2003

 * Permission is hereby granted, free of charge, to any person or 
 * organization obtaining a copy of the software and accompanying 
 * documentation covered by this license (the "Software") to use, reproduce,
 * display, distribute, execute, and transmit the Software, and to prepare
 * derivative works of the Software, and to permit third-parties to whom the 
 * Software is furnished to do so, all subject to the following:

 * The copyright notices in the Software and this entire statement, including
 * the above license grant, this restriction and the following disclaimer, must
 * be included in all copies of the Software, in whole or in part, and all
 * derivative works of the Software, unless such copies or derivative works are
 * solely in the form of machine-executable object code generated by a source
 * language processor.

 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR 
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE, TITLE AND NON-INFRINGEMENT. IN NO EVENT
 * SHALL THE COPYRIGHT HOLDERS OR ANYONE DISTRIBUTING THE SOFTWARE BE LIABLE 
 * FOR ANY DAMAGES OR OTHER LIABILITY, WHETHER IN CONTRACT, TORT OR OTHERWISE,
 * ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
 * DEALINGS IN THE SOFTWARE.
 *
 * \defgroup IfxSfr_Sent_Registers_Cfg Sent address
 * \ingroup IfxSfr_Sent_Registers
 * 
 * \defgroup IfxSfr_Sent_Registers_Cfg_BaseAddress Base address
 * \ingroup IfxSfr_Sent_Registers_Cfg
 *
 * \defgroup IfxSfr_Sent_Registers_Cfg_Sent 2-SENT
 * \ingroup IfxSfr_Sent_Registers_Cfg
 *
 *
 */
#ifndef IFXSENT_REG_H
#define IFXSENT_REG_H 1
/******************************************************************************/
#include "IfxSent_regdef.h"
/******************************************************************************/

/******************************************************************************/

/******************************************************************************/

/** \addtogroup IfxSfr_Sent_Registers_Cfg_BaseAddress
 * \{  */

/** \brief SENT object */
#define MODULE_SENT /*lint --e(923, 9078)*/ ((*(Ifx_SENT*)0xF0003000u))
/** \}  */


/******************************************************************************/
/******************************************************************************/
/** \addtogroup IfxSfr_Sent_Registers_Cfg_Sent
 * \{  */
/** \brief 0, Clock Control Register */
#define SENT_CLC /*lint --e(923, 9078)*/ (*(volatile Ifx_SENT_CLC*)0xF0003000u)

/** \brief 8, Module Identification Register */
#define SENT_ID /*lint --e(923, 9078)*/ (*(volatile Ifx_SENT_ID*)0xF0003008u)

/** \brief C, SENT Fractional Divider Register */
#define SENT_FDR /*lint --e(923, 9078)*/ (*(volatile Ifx_SENT_FDR*)0xF000300Cu)

/** \brief 14, Interrupt Overview Register */
#define SENT_INTOV /*lint --e(923, 9078)*/ (*(volatile Ifx_SENT_INTOV*)0xF0003014u)

/** \brief 18, Module Time Stamp Register */
#define SENT_TSR /*lint --e(923, 9078)*/ (*(volatile Ifx_SENT_TSR*)0xF0003018u)

/** \brief 1C, Time Stamp Predivider Register */
#define SENT_TPD /*lint --e(923, 9078)*/ (*(volatile Ifx_SENT_TPD*)0xF000301Cu)

/** \brief 80, Receive Data Register 0 */
#define SENT_RDR0 /*lint --e(923, 9078)*/ (*(volatile Ifx_SENT_RDR*)0xF0003080u)

/** \brief 84, Receive Data Register 1 */
#define SENT_RDR1 /*lint --e(923, 9078)*/ (*(volatile Ifx_SENT_RDR*)0xF0003084u)

/** \brief 88, Receive Data Register 2 */
#define SENT_RDR2 /*lint --e(923, 9078)*/ (*(volatile Ifx_SENT_RDR*)0xF0003088u)

/** \brief 8C, Receive Data Register 3 */
#define SENT_RDR3 /*lint --e(923, 9078)*/ (*(volatile Ifx_SENT_RDR*)0xF000308Cu)

/** \brief 90, Receive Data Register 4 */
#define SENT_RDR4 /*lint --e(923, 9078)*/ (*(volatile Ifx_SENT_RDR*)0xF0003090u)

/** \brief 94, Receive Data Register 5 */
#define SENT_RDR5 /*lint --e(923, 9078)*/ (*(volatile Ifx_SENT_RDR*)0xF0003094u)

/** \brief E8, OCDS Control and Status */
#define SENT_OCS /*lint --e(923, 9078)*/ (*(volatile Ifx_SENT_OCS*)0xF00030E8u)

/** \brief EC, Kernel Reset Status Clear Register */
#define SENT_KRSTCLR /*lint --e(923, 9078)*/ (*(volatile Ifx_SENT_KRSTCLR*)0xF00030ECu)

/** \brief F0, Kernel Reset Register 1 */
#define SENT_KRST1 /*lint --e(923, 9078)*/ (*(volatile Ifx_SENT_KRST1*)0xF00030F0u)

/** \brief F4, Kernel Reset Register 0 */
#define SENT_KRST0 /*lint --e(923, 9078)*/ (*(volatile Ifx_SENT_KRST0*)0xF00030F4u)

/** \brief F8, Access Enable Register 1 */
#define SENT_ACCEN1 /*lint --e(923, 9078)*/ (*(volatile Ifx_SENT_ACCEN1*)0xF00030F8u)

/** \brief FC, Access Enable Register 0 */
#define SENT_ACCEN0 /*lint --e(923, 9078)*/ (*(volatile Ifx_SENT_ACCEN0*)0xF00030FCu)

/** \brief 100, Channel Pre Divider Register 0 */
#define SENT_CH0_CPDR /*lint --e(923, 9078)*/ (*(volatile Ifx_SENT_CH_CPDR*)0xF0003100u)
/** Alias (User Manual Name) for SENT_CH0_CPDR.
* To use register names with standard convension, please use SENT_CH0_CPDR.
*/
#define SENT_CPDR0 (SENT_CH0_CPDR)

/** \brief 104, Channel Fractional Divider Register 0 */
#define SENT_CH0_CFDR /*lint --e(923, 9078)*/ (*(volatile Ifx_SENT_CH_CFDR*)0xF0003104u)
/** Alias (User Manual Name) for SENT_CH0_CFDR.
* To use register names with standard convension, please use SENT_CH0_CFDR.
*/
#define SENT_CFDR0 (SENT_CH0_CFDR)

/** \brief 108, Receiver Control Register 0 */
#define SENT_CH0_RCR /*lint --e(923, 9078)*/ (*(volatile Ifx_SENT_CH_RCR*)0xF0003108u)
/** Alias (User Manual Name) for SENT_CH0_RCR.
* To use register names with standard convension, please use SENT_CH0_RCR.
*/
#define SENT_RCR0 (SENT_CH0_RCR)

/** \brief 10C, Receive Status Register 0 */
#define SENT_CH0_RSR /*lint --e(923, 9078)*/ (*(volatile Ifx_SENT_CH_RSR*)0xF000310Cu)
/** Alias (User Manual Name) for SENT_CH0_RSR.
* To use register names with standard convension, please use SENT_CH0_RSR.
*/
#define SENT_RSR0 (SENT_CH0_RSR)

/** \brief 110, Serial Data and Status Register 0 */
#define SENT_CH0_SDS /*lint --e(923, 9078)*/ (*(volatile Ifx_SENT_CH_SDS*)0xF0003110u)
/** Alias (User Manual Name) for SENT_CH0_SDS.
* To use register names with standard convension, please use SENT_CH0_SDS.
*/
#define SENT_SDS0 (SENT_CH0_SDS)

/** \brief 114, Input and Output Control Register 0 */
#define SENT_CH0_IOCR /*lint --e(923, 9078)*/ (*(volatile Ifx_SENT_CH_IOCR*)0xF0003114u)
/** Alias (User Manual Name) for SENT_CH0_IOCR.
* To use register names with standard convension, please use SENT_CH0_IOCR.
*/
#define SENT_IOCR0 (SENT_CH0_IOCR)

/** \brief 118, SPC Control Register 0 */
#define SENT_CH0_SCR /*lint --e(923, 9078)*/ (*(volatile Ifx_SENT_CH_SCR*)0xF0003118u)
/** Alias (User Manual Name) for SENT_CH0_SCR.
* To use register names with standard convension, please use SENT_CH0_SCR.
*/
#define SENT_SCR0 (SENT_CH0_SCR)

/** \brief 11C, Receive Data View Register 0 */
#define SENT_CH0_VIEW /*lint --e(923, 9078)*/ (*(volatile Ifx_SENT_CH_VIEW*)0xF000311Cu)
/** Alias (User Manual Name) for SENT_CH0_VIEW.
* To use register names with standard convension, please use SENT_CH0_VIEW.
*/
#define SENT_VIEW0 (SENT_CH0_VIEW)

/** \brief 120, Interrupt Status Register 0 */
#define SENT_CH0_INTSTAT /*lint --e(923, 9078)*/ (*(volatile Ifx_SENT_CH_INTSTAT*)0xF0003120u)
/** Alias (User Manual Name) for SENT_CH0_INTSTAT.
* To use register names with standard convension, please use SENT_CH0_INTSTAT.
*/
#define SENT_INTSTAT0 (SENT_CH0_INTSTAT)

/** \brief 124, Interrupt Set Register 0 */
#define SENT_CH0_INTSET /*lint --e(923, 9078)*/ (*(volatile Ifx_SENT_CH_INTSET*)0xF0003124u)
/** Alias (User Manual Name) for SENT_CH0_INTSET.
* To use register names with standard convension, please use SENT_CH0_INTSET.
*/
#define SENT_INTSET0 (SENT_CH0_INTSET)

/** \brief 128, Interrupt Clear Register 0 */
#define SENT_CH0_INTCLR /*lint --e(923, 9078)*/ (*(volatile Ifx_SENT_CH_INTCLR*)0xF0003128u)
/** Alias (User Manual Name) for SENT_CH0_INTCLR.
* To use register names with standard convension, please use SENT_CH0_INTCLR.
*/
#define SENT_INTCLR0 (SENT_CH0_INTCLR)

/** \brief 12C, Interrupt Enable Register 0 */
#define SENT_CH0_INTEN /*lint --e(923, 9078)*/ (*(volatile Ifx_SENT_CH_INTEN*)0xF000312Cu)
/** Alias (User Manual Name) for SENT_CH0_INTEN.
* To use register names with standard convension, please use SENT_CH0_INTEN.
*/
#define SENT_INTEN0 (SENT_CH0_INTEN)

/** \brief 130, Interrupt Node Pointer Register 0 */
#define SENT_CH0_INP /*lint --e(923, 9078)*/ (*(volatile Ifx_SENT_CH_INP*)0xF0003130u)
/** Alias (User Manual Name) for SENT_CH0_INP.
* To use register names with standard convension, please use SENT_CH0_INP.
*/
#define SENT_INP0 (SENT_CH0_INP)

/** \brief 134, Watch Dog Timer Register 0 */
#define SENT_CH0_WDT /*lint --e(923, 9078)*/ (*(volatile Ifx_SENT_CH_WDT*)0xF0003134u)
/** Alias (User Manual Name) for SENT_CH0_WDT.
* To use register names with standard convension, please use SENT_CH0_WDT.
*/
#define SENT_WDT0 (SENT_CH0_WDT)

/** \brief 140, Channel Pre Divider Register 1 */
#define SENT_CH1_CPDR /*lint --e(923, 9078)*/ (*(volatile Ifx_SENT_CH_CPDR*)0xF0003140u)
/** Alias (User Manual Name) for SENT_CH1_CPDR.
* To use register names with standard convension, please use SENT_CH1_CPDR.
*/
#define SENT_CPDR1 (SENT_CH1_CPDR)

/** \brief 144, Channel Fractional Divider Register 1 */
#define SENT_CH1_CFDR /*lint --e(923, 9078)*/ (*(volatile Ifx_SENT_CH_CFDR*)0xF0003144u)
/** Alias (User Manual Name) for SENT_CH1_CFDR.
* To use register names with standard convension, please use SENT_CH1_CFDR.
*/
#define SENT_CFDR1 (SENT_CH1_CFDR)

/** \brief 148, Receiver Control Register 1 */
#define SENT_CH1_RCR /*lint --e(923, 9078)*/ (*(volatile Ifx_SENT_CH_RCR*)0xF0003148u)
/** Alias (User Manual Name) for SENT_CH1_RCR.
* To use register names with standard convension, please use SENT_CH1_RCR.
*/
#define SENT_RCR1 (SENT_CH1_RCR)

/** \brief 14C, Receive Status Register 1 */
#define SENT_CH1_RSR /*lint --e(923, 9078)*/ (*(volatile Ifx_SENT_CH_RSR*)0xF000314Cu)
/** Alias (User Manual Name) for SENT_CH1_RSR.
* To use register names with standard convension, please use SENT_CH1_RSR.
*/
#define SENT_RSR1 (SENT_CH1_RSR)

/** \brief 150, Serial Data and Status Register 1 */
#define SENT_CH1_SDS /*lint --e(923, 9078)*/ (*(volatile Ifx_SENT_CH_SDS*)0xF0003150u)
/** Alias (User Manual Name) for SENT_CH1_SDS.
* To use register names with standard convension, please use SENT_CH1_SDS.
*/
#define SENT_SDS1 (SENT_CH1_SDS)

/** \brief 154, Input and Output Control Register 1 */
#define SENT_CH1_IOCR /*lint --e(923, 9078)*/ (*(volatile Ifx_SENT_CH_IOCR*)0xF0003154u)
/** Alias (User Manual Name) for SENT_CH1_IOCR.
* To use register names with standard convension, please use SENT_CH1_IOCR.
*/
#define SENT_IOCR1 (SENT_CH1_IOCR)

/** \brief 158, SPC Control Register 1 */
#define SENT_CH1_SCR /*lint --e(923, 9078)*/ (*(volatile Ifx_SENT_CH_SCR*)0xF0003158u)
/** Alias (User Manual Name) for SENT_CH1_SCR.
* To use register names with standard convension, please use SENT_CH1_SCR.
*/
#define SENT_SCR1 (SENT_CH1_SCR)

/** \brief 15C, Receive Data View Register 1 */
#define SENT_CH1_VIEW /*lint --e(923, 9078)*/ (*(volatile Ifx_SENT_CH_VIEW*)0xF000315Cu)
/** Alias (User Manual Name) for SENT_CH1_VIEW.
* To use register names with standard convension, please use SENT_CH1_VIEW.
*/
#define SENT_VIEW1 (SENT_CH1_VIEW)

/** \brief 160, Interrupt Status Register 1 */
#define SENT_CH1_INTSTAT /*lint --e(923, 9078)*/ (*(volatile Ifx_SENT_CH_INTSTAT*)0xF0003160u)
/** Alias (User Manual Name) for SENT_CH1_INTSTAT.
* To use register names with standard convension, please use SENT_CH1_INTSTAT.
*/
#define SENT_INTSTAT1 (SENT_CH1_INTSTAT)

/** \brief 164, Interrupt Set Register 1 */
#define SENT_CH1_INTSET /*lint --e(923, 9078)*/ (*(volatile Ifx_SENT_CH_INTSET*)0xF0003164u)
/** Alias (User Manual Name) for SENT_CH1_INTSET.
* To use register names with standard convension, please use SENT_CH1_INTSET.
*/
#define SENT_INTSET1 (SENT_CH1_INTSET)

/** \brief 168, Interrupt Clear Register 1 */
#define SENT_CH1_INTCLR /*lint --e(923, 9078)*/ (*(volatile Ifx_SENT_CH_INTCLR*)0xF0003168u)
/** Alias (User Manual Name) for SENT_CH1_INTCLR.
* To use register names with standard convension, please use SENT_CH1_INTCLR.
*/
#define SENT_INTCLR1 (SENT_CH1_INTCLR)

/** \brief 16C, Interrupt Enable Register 1 */
#define SENT_CH1_INTEN /*lint --e(923, 9078)*/ (*(volatile Ifx_SENT_CH_INTEN*)0xF000316Cu)
/** Alias (User Manual Name) for SENT_CH1_INTEN.
* To use register names with standard convension, please use SENT_CH1_INTEN.
*/
#define SENT_INTEN1 (SENT_CH1_INTEN)

/** \brief 170, Interrupt Node Pointer Register 1 */
#define SENT_CH1_INP /*lint --e(923, 9078)*/ (*(volatile Ifx_SENT_CH_INP*)0xF0003170u)
/** Alias (User Manual Name) for SENT_CH1_INP.
* To use register names with standard convension, please use SENT_CH1_INP.
*/
#define SENT_INP1 (SENT_CH1_INP)

/** \brief 174, Watch Dog Timer Register 1 */
#define SENT_CH1_WDT /*lint --e(923, 9078)*/ (*(volatile Ifx_SENT_CH_WDT*)0xF0003174u)
/** Alias (User Manual Name) for SENT_CH1_WDT.
* To use register names with standard convension, please use SENT_CH1_WDT.
*/
#define SENT_WDT1 (SENT_CH1_WDT)

/** \brief 180, Channel Pre Divider Register 2 */
#define SENT_CH2_CPDR /*lint --e(923, 9078)*/ (*(volatile Ifx_SENT_CH_CPDR*)0xF0003180u)
/** Alias (User Manual Name) for SENT_CH2_CPDR.
* To use register names with standard convension, please use SENT_CH2_CPDR.
*/
#define SENT_CPDR2 (SENT_CH2_CPDR)

/** \brief 184, Channel Fractional Divider Register 2 */
#define SENT_CH2_CFDR /*lint --e(923, 9078)*/ (*(volatile Ifx_SENT_CH_CFDR*)0xF0003184u)
/** Alias (User Manual Name) for SENT_CH2_CFDR.
* To use register names with standard convension, please use SENT_CH2_CFDR.
*/
#define SENT_CFDR2 (SENT_CH2_CFDR)

/** \brief 188, Receiver Control Register 2 */
#define SENT_CH2_RCR /*lint --e(923, 9078)*/ (*(volatile Ifx_SENT_CH_RCR*)0xF0003188u)
/** Alias (User Manual Name) for SENT_CH2_RCR.
* To use register names with standard convension, please use SENT_CH2_RCR.
*/
#define SENT_RCR2 (SENT_CH2_RCR)

/** \brief 18C, Receive Status Register 2 */
#define SENT_CH2_RSR /*lint --e(923, 9078)*/ (*(volatile Ifx_SENT_CH_RSR*)0xF000318Cu)
/** Alias (User Manual Name) for SENT_CH2_RSR.
* To use register names with standard convension, please use SENT_CH2_RSR.
*/
#define SENT_RSR2 (SENT_CH2_RSR)

/** \brief 190, Serial Data and Status Register 2 */
#define SENT_CH2_SDS /*lint --e(923, 9078)*/ (*(volatile Ifx_SENT_CH_SDS*)0xF0003190u)
/** Alias (User Manual Name) for SENT_CH2_SDS.
* To use register names with standard convension, please use SENT_CH2_SDS.
*/
#define SENT_SDS2 (SENT_CH2_SDS)

/** \brief 194, Input and Output Control Register 2 */
#define SENT_CH2_IOCR /*lint --e(923, 9078)*/ (*(volatile Ifx_SENT_CH_IOCR*)0xF0003194u)
/** Alias (User Manual Name) for SENT_CH2_IOCR.
* To use register names with standard convension, please use SENT_CH2_IOCR.
*/
#define SENT_IOCR2 (SENT_CH2_IOCR)

/** \brief 198, SPC Control Register 2 */
#define SENT_CH2_SCR /*lint --e(923, 9078)*/ (*(volatile Ifx_SENT_CH_SCR*)0xF0003198u)
/** Alias (User Manual Name) for SENT_CH2_SCR.
* To use register names with standard convension, please use SENT_CH2_SCR.
*/
#define SENT_SCR2 (SENT_CH2_SCR)

/** \brief 19C, Receive Data View Register 2 */
#define SENT_CH2_VIEW /*lint --e(923, 9078)*/ (*(volatile Ifx_SENT_CH_VIEW*)0xF000319Cu)
/** Alias (User Manual Name) for SENT_CH2_VIEW.
* To use register names with standard convension, please use SENT_CH2_VIEW.
*/
#define SENT_VIEW2 (SENT_CH2_VIEW)

/** \brief 1A0, Interrupt Status Register 2 */
#define SENT_CH2_INTSTAT /*lint --e(923, 9078)*/ (*(volatile Ifx_SENT_CH_INTSTAT*)0xF00031A0u)
/** Alias (User Manual Name) for SENT_CH2_INTSTAT.
* To use register names with standard convension, please use SENT_CH2_INTSTAT.
*/
#define SENT_INTSTAT2 (SENT_CH2_INTSTAT)

/** \brief 1A4, Interrupt Set Register 2 */
#define SENT_CH2_INTSET /*lint --e(923, 9078)*/ (*(volatile Ifx_SENT_CH_INTSET*)0xF00031A4u)
/** Alias (User Manual Name) for SENT_CH2_INTSET.
* To use register names with standard convension, please use SENT_CH2_INTSET.
*/
#define SENT_INTSET2 (SENT_CH2_INTSET)

/** \brief 1A8, Interrupt Clear Register 2 */
#define SENT_CH2_INTCLR /*lint --e(923, 9078)*/ (*(volatile Ifx_SENT_CH_INTCLR*)0xF00031A8u)
/** Alias (User Manual Name) for SENT_CH2_INTCLR.
* To use register names with standard convension, please use SENT_CH2_INTCLR.
*/
#define SENT_INTCLR2 (SENT_CH2_INTCLR)

/** \brief 1AC, Interrupt Enable Register 2 */
#define SENT_CH2_INTEN /*lint --e(923, 9078)*/ (*(volatile Ifx_SENT_CH_INTEN*)0xF00031ACu)
/** Alias (User Manual Name) for SENT_CH2_INTEN.
* To use register names with standard convension, please use SENT_CH2_INTEN.
*/
#define SENT_INTEN2 (SENT_CH2_INTEN)

/** \brief 1B0, Interrupt Node Pointer Register 2 */
#define SENT_CH2_INP /*lint --e(923, 9078)*/ (*(volatile Ifx_SENT_CH_INP*)0xF00031B0u)
/** Alias (User Manual Name) for SENT_CH2_INP.
* To use register names with standard convension, please use SENT_CH2_INP.
*/
#define SENT_INP2 (SENT_CH2_INP)

/** \brief 1B4, Watch Dog Timer Register 2 */
#define SENT_CH2_WDT /*lint --e(923, 9078)*/ (*(volatile Ifx_SENT_CH_WDT*)0xF00031B4u)
/** Alias (User Manual Name) for SENT_CH2_WDT.
* To use register names with standard convension, please use SENT_CH2_WDT.
*/
#define SENT_WDT2 (SENT_CH2_WDT)

/** \brief 1C0, Channel Pre Divider Register 3 */
#define SENT_CH3_CPDR /*lint --e(923, 9078)*/ (*(volatile Ifx_SENT_CH_CPDR*)0xF00031C0u)
/** Alias (User Manual Name) for SENT_CH3_CPDR.
* To use register names with standard convension, please use SENT_CH3_CPDR.
*/
#define SENT_CPDR3 (SENT_CH3_CPDR)

/** \brief 1C4, Channel Fractional Divider Register 3 */
#define SENT_CH3_CFDR /*lint --e(923, 9078)*/ (*(volatile Ifx_SENT_CH_CFDR*)0xF00031C4u)
/** Alias (User Manual Name) for SENT_CH3_CFDR.
* To use register names with standard convension, please use SENT_CH3_CFDR.
*/
#define SENT_CFDR3 (SENT_CH3_CFDR)

/** \brief 1C8, Receiver Control Register 3 */
#define SENT_CH3_RCR /*lint --e(923, 9078)*/ (*(volatile Ifx_SENT_CH_RCR*)0xF00031C8u)
/** Alias (User Manual Name) for SENT_CH3_RCR.
* To use register names with standard convension, please use SENT_CH3_RCR.
*/
#define SENT_RCR3 (SENT_CH3_RCR)

/** \brief 1CC, Receive Status Register 3 */
#define SENT_CH3_RSR /*lint --e(923, 9078)*/ (*(volatile Ifx_SENT_CH_RSR*)0xF00031CCu)
/** Alias (User Manual Name) for SENT_CH3_RSR.
* To use register names with standard convension, please use SENT_CH3_RSR.
*/
#define SENT_RSR3 (SENT_CH3_RSR)

/** \brief 1D0, Serial Data and Status Register 3 */
#define SENT_CH3_SDS /*lint --e(923, 9078)*/ (*(volatile Ifx_SENT_CH_SDS*)0xF00031D0u)
/** Alias (User Manual Name) for SENT_CH3_SDS.
* To use register names with standard convension, please use SENT_CH3_SDS.
*/
#define SENT_SDS3 (SENT_CH3_SDS)

/** \brief 1D4, Input and Output Control Register 3 */
#define SENT_CH3_IOCR /*lint --e(923, 9078)*/ (*(volatile Ifx_SENT_CH_IOCR*)0xF00031D4u)
/** Alias (User Manual Name) for SENT_CH3_IOCR.
* To use register names with standard convension, please use SENT_CH3_IOCR.
*/
#define SENT_IOCR3 (SENT_CH3_IOCR)

/** \brief 1D8, SPC Control Register 3 */
#define SENT_CH3_SCR /*lint --e(923, 9078)*/ (*(volatile Ifx_SENT_CH_SCR*)0xF00031D8u)
/** Alias (User Manual Name) for SENT_CH3_SCR.
* To use register names with standard convension, please use SENT_CH3_SCR.
*/
#define SENT_SCR3 (SENT_CH3_SCR)

/** \brief 1DC, Receive Data View Register 3 */
#define SENT_CH3_VIEW /*lint --e(923, 9078)*/ (*(volatile Ifx_SENT_CH_VIEW*)0xF00031DCu)
/** Alias (User Manual Name) for SENT_CH3_VIEW.
* To use register names with standard convension, please use SENT_CH3_VIEW.
*/
#define SENT_VIEW3 (SENT_CH3_VIEW)

/** \brief 1E0, Interrupt Status Register 3 */
#define SENT_CH3_INTSTAT /*lint --e(923, 9078)*/ (*(volatile Ifx_SENT_CH_INTSTAT*)0xF00031E0u)
/** Alias (User Manual Name) for SENT_CH3_INTSTAT.
* To use register names with standard convension, please use SENT_CH3_INTSTAT.
*/
#define SENT_INTSTAT3 (SENT_CH3_INTSTAT)

/** \brief 1E4, Interrupt Set Register 3 */
#define SENT_CH3_INTSET /*lint --e(923, 9078)*/ (*(volatile Ifx_SENT_CH_INTSET*)0xF00031E4u)
/** Alias (User Manual Name) for SENT_CH3_INTSET.
* To use register names with standard convension, please use SENT_CH3_INTSET.
*/
#define SENT_INTSET3 (SENT_CH3_INTSET)

/** \brief 1E8, Interrupt Clear Register 3 */
#define SENT_CH3_INTCLR /*lint --e(923, 9078)*/ (*(volatile Ifx_SENT_CH_INTCLR*)0xF00031E8u)
/** Alias (User Manual Name) for SENT_CH3_INTCLR.
* To use register names with standard convension, please use SENT_CH3_INTCLR.
*/
#define SENT_INTCLR3 (SENT_CH3_INTCLR)

/** \brief 1EC, Interrupt Enable Register 3 */
#define SENT_CH3_INTEN /*lint --e(923, 9078)*/ (*(volatile Ifx_SENT_CH_INTEN*)0xF00031ECu)
/** Alias (User Manual Name) for SENT_CH3_INTEN.
* To use register names with standard convension, please use SENT_CH3_INTEN.
*/
#define SENT_INTEN3 (SENT_CH3_INTEN)

/** \brief 1F0, Interrupt Node Pointer Register 3 */
#define SENT_CH3_INP /*lint --e(923, 9078)*/ (*(volatile Ifx_SENT_CH_INP*)0xF00031F0u)
/** Alias (User Manual Name) for SENT_CH3_INP.
* To use register names with standard convension, please use SENT_CH3_INP.
*/
#define SENT_INP3 (SENT_CH3_INP)

/** \brief 1F4, Watch Dog Timer Register 3 */
#define SENT_CH3_WDT /*lint --e(923, 9078)*/ (*(volatile Ifx_SENT_CH_WDT*)0xF00031F4u)
/** Alias (User Manual Name) for SENT_CH3_WDT.
* To use register names with standard convension, please use SENT_CH3_WDT.
*/
#define SENT_WDT3 (SENT_CH3_WDT)

/** \brief 200, Channel Pre Divider Register 4 */
#define SENT_CH4_CPDR /*lint --e(923, 9078)*/ (*(volatile Ifx_SENT_CH_CPDR*)0xF0003200u)
/** Alias (User Manual Name) for SENT_CH4_CPDR.
* To use register names with standard convension, please use SENT_CH4_CPDR.
*/
#define SENT_CPDR4 (SENT_CH4_CPDR)

/** \brief 204, Channel Fractional Divider Register 4 */
#define SENT_CH4_CFDR /*lint --e(923, 9078)*/ (*(volatile Ifx_SENT_CH_CFDR*)0xF0003204u)
/** Alias (User Manual Name) for SENT_CH4_CFDR.
* To use register names with standard convension, please use SENT_CH4_CFDR.
*/
#define SENT_CFDR4 (SENT_CH4_CFDR)

/** \brief 208, Receiver Control Register 4 */
#define SENT_CH4_RCR /*lint --e(923, 9078)*/ (*(volatile Ifx_SENT_CH_RCR*)0xF0003208u)
/** Alias (User Manual Name) for SENT_CH4_RCR.
* To use register names with standard convension, please use SENT_CH4_RCR.
*/
#define SENT_RCR4 (SENT_CH4_RCR)

/** \brief 20C, Receive Status Register 4 */
#define SENT_CH4_RSR /*lint --e(923, 9078)*/ (*(volatile Ifx_SENT_CH_RSR*)0xF000320Cu)
/** Alias (User Manual Name) for SENT_CH4_RSR.
* To use register names with standard convension, please use SENT_CH4_RSR.
*/
#define SENT_RSR4 (SENT_CH4_RSR)

/** \brief 210, Serial Data and Status Register 4 */
#define SENT_CH4_SDS /*lint --e(923, 9078)*/ (*(volatile Ifx_SENT_CH_SDS*)0xF0003210u)
/** Alias (User Manual Name) for SENT_CH4_SDS.
* To use register names with standard convension, please use SENT_CH4_SDS.
*/
#define SENT_SDS4 (SENT_CH4_SDS)

/** \brief 214, Input and Output Control Register 4 */
#define SENT_CH4_IOCR /*lint --e(923, 9078)*/ (*(volatile Ifx_SENT_CH_IOCR*)0xF0003214u)
/** Alias (User Manual Name) for SENT_CH4_IOCR.
* To use register names with standard convension, please use SENT_CH4_IOCR.
*/
#define SENT_IOCR4 (SENT_CH4_IOCR)

/** \brief 218, SPC Control Register 4 */
#define SENT_CH4_SCR /*lint --e(923, 9078)*/ (*(volatile Ifx_SENT_CH_SCR*)0xF0003218u)
/** Alias (User Manual Name) for SENT_CH4_SCR.
* To use register names with standard convension, please use SENT_CH4_SCR.
*/
#define SENT_SCR4 (SENT_CH4_SCR)

/** \brief 21C, Receive Data View Register 4 */
#define SENT_CH4_VIEW /*lint --e(923, 9078)*/ (*(volatile Ifx_SENT_CH_VIEW*)0xF000321Cu)
/** Alias (User Manual Name) for SENT_CH4_VIEW.
* To use register names with standard convension, please use SENT_CH4_VIEW.
*/
#define SENT_VIEW4 (SENT_CH4_VIEW)

/** \brief 220, Interrupt Status Register 4 */
#define SENT_CH4_INTSTAT /*lint --e(923, 9078)*/ (*(volatile Ifx_SENT_CH_INTSTAT*)0xF0003220u)
/** Alias (User Manual Name) for SENT_CH4_INTSTAT.
* To use register names with standard convension, please use SENT_CH4_INTSTAT.
*/
#define SENT_INTSTAT4 (SENT_CH4_INTSTAT)

/** \brief 224, Interrupt Set Register 4 */
#define SENT_CH4_INTSET /*lint --e(923, 9078)*/ (*(volatile Ifx_SENT_CH_INTSET*)0xF0003224u)
/** Alias (User Manual Name) for SENT_CH4_INTSET.
* To use register names with standard convension, please use SENT_CH4_INTSET.
*/
#define SENT_INTSET4 (SENT_CH4_INTSET)

/** \brief 228, Interrupt Clear Register 4 */
#define SENT_CH4_INTCLR /*lint --e(923, 9078)*/ (*(volatile Ifx_SENT_CH_INTCLR*)0xF0003228u)
/** Alias (User Manual Name) for SENT_CH4_INTCLR.
* To use register names with standard convension, please use SENT_CH4_INTCLR.
*/
#define SENT_INTCLR4 (SENT_CH4_INTCLR)

/** \brief 22C, Interrupt Enable Register 4 */
#define SENT_CH4_INTEN /*lint --e(923, 9078)*/ (*(volatile Ifx_SENT_CH_INTEN*)0xF000322Cu)
/** Alias (User Manual Name) for SENT_CH4_INTEN.
* To use register names with standard convension, please use SENT_CH4_INTEN.
*/
#define SENT_INTEN4 (SENT_CH4_INTEN)

/** \brief 230, Interrupt Node Pointer Register 4 */
#define SENT_CH4_INP /*lint --e(923, 9078)*/ (*(volatile Ifx_SENT_CH_INP*)0xF0003230u)
/** Alias (User Manual Name) for SENT_CH4_INP.
* To use register names with standard convension, please use SENT_CH4_INP.
*/
#define SENT_INP4 (SENT_CH4_INP)

/** \brief 234, Watch Dog Timer Register 4 */
#define SENT_CH4_WDT /*lint --e(923, 9078)*/ (*(volatile Ifx_SENT_CH_WDT*)0xF0003234u)
/** Alias (User Manual Name) for SENT_CH4_WDT.
* To use register names with standard convension, please use SENT_CH4_WDT.
*/
#define SENT_WDT4 (SENT_CH4_WDT)

/** \brief 240, Channel Pre Divider Register 5 */
#define SENT_CH5_CPDR /*lint --e(923, 9078)*/ (*(volatile Ifx_SENT_CH_CPDR*)0xF0003240u)
/** Alias (User Manual Name) for SENT_CH5_CPDR.
* To use register names with standard convension, please use SENT_CH5_CPDR.
*/
#define SENT_CPDR5 (SENT_CH5_CPDR)

/** \brief 244, Channel Fractional Divider Register 5 */
#define SENT_CH5_CFDR /*lint --e(923, 9078)*/ (*(volatile Ifx_SENT_CH_CFDR*)0xF0003244u)
/** Alias (User Manual Name) for SENT_CH5_CFDR.
* To use register names with standard convension, please use SENT_CH5_CFDR.
*/
#define SENT_CFDR5 (SENT_CH5_CFDR)

/** \brief 248, Receiver Control Register 5 */
#define SENT_CH5_RCR /*lint --e(923, 9078)*/ (*(volatile Ifx_SENT_CH_RCR*)0xF0003248u)
/** Alias (User Manual Name) for SENT_CH5_RCR.
* To use register names with standard convension, please use SENT_CH5_RCR.
*/
#define SENT_RCR5 (SENT_CH5_RCR)

/** \brief 24C, Receive Status Register 5 */
#define SENT_CH5_RSR /*lint --e(923, 9078)*/ (*(volatile Ifx_SENT_CH_RSR*)0xF000324Cu)
/** Alias (User Manual Name) for SENT_CH5_RSR.
* To use register names with standard convension, please use SENT_CH5_RSR.
*/
#define SENT_RSR5 (SENT_CH5_RSR)

/** \brief 250, Serial Data and Status Register 5 */
#define SENT_CH5_SDS /*lint --e(923, 9078)*/ (*(volatile Ifx_SENT_CH_SDS*)0xF0003250u)
/** Alias (User Manual Name) for SENT_CH5_SDS.
* To use register names with standard convension, please use SENT_CH5_SDS.
*/
#define SENT_SDS5 (SENT_CH5_SDS)

/** \brief 254, Input and Output Control Register 5 */
#define SENT_CH5_IOCR /*lint --e(923, 9078)*/ (*(volatile Ifx_SENT_CH_IOCR*)0xF0003254u)
/** Alias (User Manual Name) for SENT_CH5_IOCR.
* To use register names with standard convension, please use SENT_CH5_IOCR.
*/
#define SENT_IOCR5 (SENT_CH5_IOCR)

/** \brief 258, SPC Control Register 5 */
#define SENT_CH5_SCR /*lint --e(923, 9078)*/ (*(volatile Ifx_SENT_CH_SCR*)0xF0003258u)
/** Alias (User Manual Name) for SENT_CH5_SCR.
* To use register names with standard convension, please use SENT_CH5_SCR.
*/
#define SENT_SCR5 (SENT_CH5_SCR)

/** \brief 25C, Receive Data View Register 5 */
#define SENT_CH5_VIEW /*lint --e(923, 9078)*/ (*(volatile Ifx_SENT_CH_VIEW*)0xF000325Cu)
/** Alias (User Manual Name) for SENT_CH5_VIEW.
* To use register names with standard convension, please use SENT_CH5_VIEW.
*/
#define SENT_VIEW5 (SENT_CH5_VIEW)

/** \brief 260, Interrupt Status Register 5 */
#define SENT_CH5_INTSTAT /*lint --e(923, 9078)*/ (*(volatile Ifx_SENT_CH_INTSTAT*)0xF0003260u)
/** Alias (User Manual Name) for SENT_CH5_INTSTAT.
* To use register names with standard convension, please use SENT_CH5_INTSTAT.
*/
#define SENT_INTSTAT5 (SENT_CH5_INTSTAT)

/** \brief 264, Interrupt Set Register 5 */
#define SENT_CH5_INTSET /*lint --e(923, 9078)*/ (*(volatile Ifx_SENT_CH_INTSET*)0xF0003264u)
/** Alias (User Manual Name) for SENT_CH5_INTSET.
* To use register names with standard convension, please use SENT_CH5_INTSET.
*/
#define SENT_INTSET5 (SENT_CH5_INTSET)

/** \brief 268, Interrupt Clear Register 5 */
#define SENT_CH5_INTCLR /*lint --e(923, 9078)*/ (*(volatile Ifx_SENT_CH_INTCLR*)0xF0003268u)
/** Alias (User Manual Name) for SENT_CH5_INTCLR.
* To use register names with standard convension, please use SENT_CH5_INTCLR.
*/
#define SENT_INTCLR5 (SENT_CH5_INTCLR)

/** \brief 26C, Interrupt Enable Register 5 */
#define SENT_CH5_INTEN /*lint --e(923, 9078)*/ (*(volatile Ifx_SENT_CH_INTEN*)0xF000326Cu)
/** Alias (User Manual Name) for SENT_CH5_INTEN.
* To use register names with standard convension, please use SENT_CH5_INTEN.
*/
#define SENT_INTEN5 (SENT_CH5_INTEN)

/** \brief 270, Interrupt Node Pointer Register 5 */
#define SENT_CH5_INP /*lint --e(923, 9078)*/ (*(volatile Ifx_SENT_CH_INP*)0xF0003270u)
/** Alias (User Manual Name) for SENT_CH5_INP.
* To use register names with standard convension, please use SENT_CH5_INP.
*/
#define SENT_INP5 (SENT_CH5_INP)

/** \brief 274, Watch Dog Timer Register 5 */
#define SENT_CH5_WDT /*lint --e(923, 9078)*/ (*(volatile Ifx_SENT_CH_WDT*)0xF0003274u)
/** Alias (User Manual Name) for SENT_CH5_WDT.
* To use register names with standard convension, please use SENT_CH5_WDT.
*/
#define SENT_WDT5 (SENT_CH5_WDT)

/** \brief A80, Receive Time Stamp Register 0 */
#define SENT_RTS0 /*lint --e(923, 9078)*/ (*(volatile Ifx_SENT_RTS*)0xF0003A80u)

/** \brief A84, Receive Time Stamp Register 1 */
#define SENT_RTS1 /*lint --e(923, 9078)*/ (*(volatile Ifx_SENT_RTS*)0xF0003A84u)

/** \brief A88, Receive Time Stamp Register 2 */
#define SENT_RTS2 /*lint --e(923, 9078)*/ (*(volatile Ifx_SENT_RTS*)0xF0003A88u)

/** \brief A8C, Receive Time Stamp Register 3 */
#define SENT_RTS3 /*lint --e(923, 9078)*/ (*(volatile Ifx_SENT_RTS*)0xF0003A8Cu)

/** \brief A90, Receive Time Stamp Register 4 */
#define SENT_RTS4 /*lint --e(923, 9078)*/ (*(volatile Ifx_SENT_RTS*)0xF0003A90u)

/** \brief A94, Receive Time Stamp Register 5 */
#define SENT_RTS5 /*lint --e(923, 9078)*/ (*(volatile Ifx_SENT_RTS*)0xF0003A94u)


/** \}  */

/******************************************************************************/

/******************************************************************************/

#endif /* IFXSENT_REG_H */
