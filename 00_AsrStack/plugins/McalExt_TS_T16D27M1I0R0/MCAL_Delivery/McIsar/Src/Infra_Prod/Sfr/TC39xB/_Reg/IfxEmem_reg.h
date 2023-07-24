/**
 * \file IfxEmem_reg.h
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
 * \defgroup IfxSfr_Emem_Registers_Cfg Emem address
 * \ingroup IfxSfr_Emem_Registers
 * 
 * \defgroup IfxSfr_Emem_Registers_Cfg_BaseAddress Base address
 * \ingroup IfxSfr_Emem_Registers_Cfg
 *
 * \defgroup IfxSfr_Emem_Registers_Cfg_Emem 2-EMEM
 * \ingroup IfxSfr_Emem_Registers_Cfg
 *
 *
 */
#ifndef IFXEMEM_REG_H
#define IFXEMEM_REG_H 1
/******************************************************************************/
#include "IfxEmem_regdef.h"
/******************************************************************************/

/******************************************************************************/

/******************************************************************************/

/** \addtogroup IfxSfr_Emem_Registers_Cfg_BaseAddress
 * \{  */

/** \brief EMEM object */
#define MODULE_EMEM /*lint --e(923, 9078)*/ ((*(Ifx_EMEM*)0xFA006000u))
/** \}  */


/******************************************************************************/
/******************************************************************************/
/** \addtogroup IfxSfr_Emem_Registers_Cfg_Emem
 * \{  */
/** \brief 0, EMEM Core Clock Control Register */
#define EMEM_CLC /*lint --e(923, 9078)*/ (*(volatile Ifx_EMEM_CLC*)0xFA006000u)

/** \brief 8, EMEM Core Module Identification Register */
#define EMEM_ID /*lint --e(923, 9078)*/ (*(volatile Ifx_EMEM_ID*)0xFA006008u)

/** \brief 20, EMEM Core Tile Configuration Register */
#define EMEM_TILECONFIG /*lint --e(923, 9078)*/ (*(volatile Ifx_EMEM_TILECONFIG*)0xFA006020u)

/** \brief 24, EMEM Core Tile Control Common Memory Register */
#define EMEM_TILECC /*lint --e(923, 9078)*/ (*(volatile Ifx_EMEM_TILECC*)0xFA006024u)

/** \brief 28, EMEM Core Tile Control Trace Memory Register */
#define EMEM_TILECT /*lint --e(923, 9078)*/ (*(volatile Ifx_EMEM_TILECT*)0xFA006028u)

/** \brief 2C, EMEM Core Tile Status Register */
#define EMEM_TILESTATE /*lint --e(923, 9078)*/ (*(volatile Ifx_EMEM_TILESTATE*)0xFA00602Cu)

/** \brief 34, EMEM Core Standby RAM Control Register */
#define EMEM_SBRCTR /*lint --e(923, 9078)*/ (*(volatile Ifx_EMEM_SBRCTR*)0xFA006034u)

/** \brief F8, EMEM Core Access Enable Register 1 */
#define EMEM_ACCEN1 /*lint --e(923, 9078)*/ (*(volatile Ifx_EMEM_ACCEN1*)0xFA0060F8u)

/** \brief FC, EMEM Core Access Enable Register 0 */
#define EMEM_ACCEN0 /*lint --e(923, 9078)*/ (*(volatile Ifx_EMEM_ACCEN0*)0xFA0060FCu)


/** \}  */

/******************************************************************************/

/******************************************************************************/

#endif /* IFXEMEM_REG_H */
