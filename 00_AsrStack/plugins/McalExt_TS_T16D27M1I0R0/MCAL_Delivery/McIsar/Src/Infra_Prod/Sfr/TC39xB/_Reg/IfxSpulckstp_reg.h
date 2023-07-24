/**
 * \file IfxSpulckstp_reg.h
 * \brief
 * \copyright Copyright (c) 2021 Infineon Technologies AG. All rights reserved.
 *
 *
 * Version: TC39XB_UM_V2.0.0.R0
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
 * \defgroup IfxSfr_Spulckstp_Registers_Cfg Spulckstp address
 * \ingroup IfxSfr_Spulckstp_Registers
 * 
 * \defgroup IfxSfr_Spulckstp_Registers_Cfg_BaseAddress Base address
 * \ingroup IfxSfr_Spulckstp_Registers_Cfg
 *
 * \defgroup IfxSfr_Spulckstp_Registers_Cfg_Spulckstp 2-SPULCKSTP
 * \ingroup IfxSfr_Spulckstp_Registers_Cfg
 *
 *
 */
#ifndef IFXSPULCKSTP_REG_H
#define IFXSPULCKSTP_REG_H 1
/******************************************************************************/
#include "IfxSpulckstp_regdef.h"
/******************************************************************************/

/******************************************************************************/

/******************************************************************************/

/** \addtogroup IfxSfr_Spulckstp_Registers_Cfg_BaseAddress
 * \{  */

/** \brief SPULCKSTP object */
#define MODULE_SPULCKSTP /*lint --e(923, 9078)*/ ((*(Ifx_SPULCKSTP*)0xFA700000u))
/** \}  */


/******************************************************************************/
/******************************************************************************/
/** \addtogroup IfxSfr_Spulckstp_Registers_Cfg_Spulckstp
 * \{  */
/** \brief 0, Clock Control */
#define SPULCKSTP_CLC /*lint --e(923, 9078)*/ (*(volatile Ifx_SPULCKSTP_CLC*)0xFA700000u)

/** \brief 4, Module Identification Register */
#define SPULCKSTP_MODID /*lint --e(923, 9078)*/ (*(volatile Ifx_SPULCKSTP_MODID*)0xFA700004u)

/** \brief 10, SPU Lockstep Control */
#define SPULCKSTP_CTRL /*lint --e(923, 9078)*/ (*(volatile Ifx_SPULCKSTP_CTRL*)0xFA700010u)

/** \brief 18, Error Monitoring Register */
#define SPULCKSTP_ERROR /*lint --e(923, 9078)*/ (*(volatile Ifx_SPULCKSTP_ERROR*)0xFA700018u)

/** \brief 1C, Error Clear */
#define SPULCKSTP_ERRCLR /*lint --e(923, 9078)*/ (*(volatile Ifx_SPULCKSTP_ERRCLR*)0xFA70001Cu)

/** \brief 20, Alarm Test Register */
#define SPULCKSTP_TEST /*lint --e(923, 9078)*/ (*(volatile Ifx_SPULCKSTP_TEST*)0xFA700020u)

/** \brief 24, SPU Control */
#define SPULCKSTP_SPUCTRL /*lint --e(923, 9078)*/ (*(volatile Ifx_SPULCKSTP_SPUCTRL*)0xFA700024u)

/** \brief E4, Access Enable Register 0 */
#define SPULCKSTP_ACCEN0 /*lint --e(923, 9078)*/ (*(volatile Ifx_SPULCKSTP_ACCEN0*)0xFA7000E4u)

/** \brief E8, Access Enable Register 1 */
#define SPULCKSTP_ACCEN1 /*lint --e(923, 9078)*/ (*(volatile Ifx_SPULCKSTP_ACCEN1*)0xFA7000E8u)


/** \}  */

/******************************************************************************/

/******************************************************************************/

#endif /* IFXSPULCKSTP_REG_H */
