/**
 * \file IfxRif_reg.h
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
 * \defgroup IfxSfr_Rif_Registers_Cfg Rif address
 * \ingroup IfxSfr_Rif_Registers
 * 
 * \defgroup IfxSfr_Rif_Registers_Cfg_BaseAddress Base address
 * \ingroup IfxSfr_Rif_Registers_Cfg
 *
 * \defgroup IfxSfr_Rif_Registers_Cfg_Rif0 2-RIF0
 * \ingroup IfxSfr_Rif_Registers_Cfg
 *
 *
 */
#ifndef IFXRIF_REG_H
#define IFXRIF_REG_H 1
/******************************************************************************/
#include "IfxRif_regdef.h"
/******************************************************************************/

/******************************************************************************/

/******************************************************************************/

/** \addtogroup IfxSfr_Rif_Registers_Cfg_BaseAddress
 * \{  */

/** \brief RIF object */
#define MODULE_RIF0 /*lint --e(923, 9078)*/ ((*(Ifx_RIF*)0xFA040000u))
/** \}  */


/******************************************************************************/
/******************************************************************************/
/** \addtogroup IfxSfr_Rif_Registers_Cfg_Rif0
 * \{  */
/** \brief 0, Clock Control Register */
#define RIF0_CLC /*lint --e(923, 9078)*/ (*(volatile Ifx_RIF_CLC*)0xFA040000u)

/** \brief 8, Module Identification Register */
#define RIF0_ID /*lint --e(923, 9078)*/ (*(volatile Ifx_RIF_ID*)0xFA040008u)

/** \brief 10, External Serial Interface Register */
#define RIF0_ESI /*lint --e(923, 9078)*/ (*(volatile Ifx_RIF_ESI*)0xFA040010u)

/** \brief 14, Internal Parallel Interface Register */
#define RIF0_IPI /*lint --e(923, 9078)*/ (*(volatile Ifx_RIF_IPI*)0xFA040014u)

/** \brief 18, FIFO and Lane Management Register */
#define RIF0_FLM /*lint --e(923, 9078)*/ (*(volatile Ifx_RIF_FLM*)0xFA040018u)

/** \brief 1C, Data Memory Interface Register */
#define RIF0_DMI /*lint --e(923, 9078)*/ (*(volatile Ifx_RIF_DMI*)0xFA04001Cu)

/** \brief 20, Radar State Machine Register 0 */
#define RIF0_RSM0 /*lint --e(923, 9078)*/ (*(volatile Ifx_RIF_RSM0*)0xFA040020u)

/** \brief 24, Radar State Machine Register 1 */
#define RIF0_RSM1 /*lint --e(923, 9078)*/ (*(volatile Ifx_RIF_RSM1*)0xFA040024u)

/** \brief 28, Radar State Machine Register 2 */
#define RIF0_RSM2 /*lint --e(923, 9078)*/ (*(volatile Ifx_RIF_RSM2*)0xFA040028u)

/** \brief 2C, Interrupt Control Register */
#define RIF0_INTCON /*lint --e(923, 9078)*/ (*(volatile Ifx_RIF_INTCON*)0xFA04002Cu)

/** \brief 30, Flags Set Register */
#define RIF0_FLAGSSET /*lint --e(923, 9078)*/ (*(volatile Ifx_RIF_FLAGSSET*)0xFA040030u)

/** \brief 34, Flags Clear Register */
#define RIF0_FLAGSCL /*lint --e(923, 9078)*/ (*(volatile Ifx_RIF_FLAGSCL*)0xFA040034u)

/** \brief 38, Frame Watchdog Register */
#define RIF0_FWDG /*lint --e(923, 9078)*/ (*(volatile Ifx_RIF_FWDG*)0xFA040038u)

/** \brief 3C, Data Formatting Unit Register */
#define RIF0_DFU /*lint --e(923, 9078)*/ (*(volatile Ifx_RIF_DFU*)0xFA04003Cu)

/** \brief 40, SRIF Override Configuration Register */
#define RIF0_SRIFOVRCFG /*lint --e(923, 9078)*/ (*(volatile Ifx_RIF_SRIFOVRCFG*)0xFA040040u)

/** \brief 44, Radar State Machine 2 Capture Register */
#define RIF0_RSM2CAP /*lint --e(923, 9078)*/ (*(volatile Ifx_RIF_RSM2CAP*)0xFA040044u)

/** \brief 48, Skew Calibration Register */
#define RIF0_SKEWCAL /*lint --e(923, 9078)*/ (*(volatile Ifx_RIF_SKEWCAL*)0xFA040048u)

/** \brief 4C, LVDS Control Register 0 */
#define RIF0_LVDSCON0 /*lint --e(923, 9078)*/ (*(volatile Ifx_RIF_LVDSCON0*)0xFA04004Cu)

/** \brief 50, LVDS Control Register 1 */
#define RIF0_LVDSCON1 /*lint --e(923, 9078)*/ (*(volatile Ifx_RIF_LVDSCON1*)0xFA040050u)

/** \brief 54, Debug Delay Register 0 */
#define RIF0_DBGDLY0 /*lint --e(923, 9078)*/ (*(volatile Ifx_RIF_DBGDLY0*)0xFA040054u)

/** \brief 58, Debug Delay Register 1 */
#define RIF0_DBGDLY1 /*lint --e(923, 9078)*/ (*(volatile Ifx_RIF_DBGDLY1*)0xFA040058u)

/** \brief 80, Debug Data Register 0 */
#define RIF0_DBG0 /*lint --e(923, 9078)*/ (*(volatile Ifx_RIF_DBG0*)0xFA040080u)

/** \brief 84, Debug Data Register 1 */
#define RIF0_DBG1 /*lint --e(923, 9078)*/ (*(volatile Ifx_RIF_DBG1*)0xFA040084u)

/** \brief 88, Safety Functions Register */
#define RIF0_SFCON /*lint --e(923, 9078)*/ (*(volatile Ifx_RIF_SFCON*)0xFA040088u)

/** \brief 8C, Register CRC Register  */
#define RIF0_REGCRC /*lint --e(923, 9078)*/ (*(volatile Ifx_RIF_REGCRC*)0xFA04008Cu)

/** \brief E8, OCDS Control and Status */
#define RIF0_OCS /*lint --e(923, 9078)*/ (*(volatile Ifx_RIF_OCS*)0xFA0400E8u)

/** \brief EC, Kernel Reset Status Clear Register */
#define RIF0_KRSTCLR /*lint --e(923, 9078)*/ (*(volatile Ifx_RIF_KRSTCLR*)0xFA0400ECu)

/** \brief F0, Kernel Reset Register 1 */
#define RIF0_KRST1 /*lint --e(923, 9078)*/ (*(volatile Ifx_RIF_KRST1*)0xFA0400F0u)

/** \brief F4, Kernel Reset Register 0 */
#define RIF0_KRST0 /*lint --e(923, 9078)*/ (*(volatile Ifx_RIF_KRST0*)0xFA0400F4u)

/** \brief F8, Access Enable Register 1 */
#define RIF0_ACCEN1 /*lint --e(923, 9078)*/ (*(volatile Ifx_RIF_ACCEN1*)0xFA0400F8u)

/** \brief FC, Access Enable Register 0 */
#define RIF0_ACCEN0 /*lint --e(923, 9078)*/ (*(volatile Ifx_RIF_ACCEN0*)0xFA0400FCu)


/** \}  */

/******************************************************************************/

/******************************************************************************/

#endif /* IFXRIF_REG_H */
