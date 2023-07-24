/**
 * \file IfxAsclin_regdef.h
 * \brief
 * \copyright Copyright (c) 2021 Infineon Technologies AG. All rights reserved.
 *
 *
 * Version: TC37xED_UM_V2.0.0.R0
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
 * \defgroup IfxSfr_Asclin_Registers Asclin Registers
 * \ingroup IfxSfr
 * 
 * \defgroup IfxSfr_Asclin_Registers_Bitfields Bitfields
 * \ingroup IfxSfr_Asclin_Registers
 * 
 * \defgroup IfxSfr_Asclin_Registers_union Register unions
 * \ingroup IfxSfr_Asclin_Registers
 * 
 * \defgroup IfxSfr_Asclin_Registers_struct Memory map
 * \ingroup IfxSfr_Asclin_Registers
 */
#ifndef IFXASCLIN_REGDEF_H
#define IFXASCLIN_REGDEF_H 1
/******************************************************************************/
#include "Ifx_TypesReg.h"
/******************************************************************************/

/******************************************************************************/

/******************************************************************************/


/** \addtogroup IfxSfr_Asclin_Registers_Bitfields
 * \{  */
/** \brief Access Enable Register 0 */
typedef struct _Ifx_ASCLIN_ACCEN0_Bits
{
    Ifx_UReg_32Bit EN0:1;             /**< \brief [0:0] Access Enable for Master TAG ID 0 - EN0 (rw) */
    Ifx_UReg_32Bit EN1:1;             /**< \brief [1:1] Access Enable for Master TAG ID 1 - EN1 (rw) */
    Ifx_UReg_32Bit EN2:1;             /**< \brief [2:2] Access Enable for Master TAG ID 2 - EN2 (rw) */
    Ifx_UReg_32Bit EN3:1;             /**< \brief [3:3] Access Enable for Master TAG ID 3 - EN3 (rw) */
    Ifx_UReg_32Bit EN4:1;             /**< \brief [4:4] Access Enable for Master TAG ID 4 - EN4 (rw) */
    Ifx_UReg_32Bit EN5:1;             /**< \brief [5:5] Access Enable for Master TAG ID 5 - EN5 (rw) */
    Ifx_UReg_32Bit EN6:1;             /**< \brief [6:6] Access Enable for Master TAG ID 6 - EN6 (rw) */
    Ifx_UReg_32Bit EN7:1;             /**< \brief [7:7] Access Enable for Master TAG ID 7 - EN7 (rw) */
    Ifx_UReg_32Bit EN8:1;             /**< \brief [8:8] Access Enable for Master TAG ID 8 - EN8 (rw) */
    Ifx_UReg_32Bit EN9:1;             /**< \brief [9:9] Access Enable for Master TAG ID 9 - EN9 (rw) */
    Ifx_UReg_32Bit EN10:1;            /**< \brief [10:10] Access Enable for Master TAG ID 10 - EN10 (rw) */
    Ifx_UReg_32Bit EN11:1;            /**< \brief [11:11] Access Enable for Master TAG ID 11 - EN11 (rw) */
    Ifx_UReg_32Bit EN12:1;            /**< \brief [12:12] Access Enable for Master TAG ID 12 - EN12 (rw) */
    Ifx_UReg_32Bit EN13:1;            /**< \brief [13:13] Access Enable for Master TAG ID 13 - EN13 (rw) */
    Ifx_UReg_32Bit EN14:1;            /**< \brief [14:14] Access Enable for Master TAG ID 14 - EN14 (rw) */
    Ifx_UReg_32Bit EN15:1;            /**< \brief [15:15] Access Enable for Master TAG ID 15 - EN15 (rw) */
    Ifx_UReg_32Bit EN16:1;            /**< \brief [16:16] Access Enable for Master TAG ID 16 - EN16 (rw) */
    Ifx_UReg_32Bit EN17:1;            /**< \brief [17:17] Access Enable for Master TAG ID 17 - EN17 (rw) */
    Ifx_UReg_32Bit EN18:1;            /**< \brief [18:18] Access Enable for Master TAG ID 18 - EN18 (rw) */
    Ifx_UReg_32Bit EN19:1;            /**< \brief [19:19] Access Enable for Master TAG ID 19 - EN19 (rw) */
    Ifx_UReg_32Bit EN20:1;            /**< \brief [20:20] Access Enable for Master TAG ID 20 - EN20 (rw) */
    Ifx_UReg_32Bit EN21:1;            /**< \brief [21:21] Access Enable for Master TAG ID 21 - EN21 (rw) */
    Ifx_UReg_32Bit EN22:1;            /**< \brief [22:22] Access Enable for Master TAG ID 22 - EN22 (rw) */
    Ifx_UReg_32Bit EN23:1;            /**< \brief [23:23] Access Enable for Master TAG ID 23 - EN23 (rw) */
    Ifx_UReg_32Bit EN24:1;            /**< \brief [24:24] Access Enable for Master TAG ID 24 - EN24 (rw) */
    Ifx_UReg_32Bit EN25:1;            /**< \brief [25:25] Access Enable for Master TAG ID 25 - EN25 (rw) */
    Ifx_UReg_32Bit EN26:1;            /**< \brief [26:26] Access Enable for Master TAG ID 26 - EN26 (rw) */
    Ifx_UReg_32Bit EN27:1;            /**< \brief [27:27] Access Enable for Master TAG ID 27 - EN27 (rw) */
    Ifx_UReg_32Bit EN28:1;            /**< \brief [28:28] Access Enable for Master TAG ID 28 - EN28 (rw) */
    Ifx_UReg_32Bit EN29:1;            /**< \brief [29:29] Access Enable for Master TAG ID 29 - EN29 (rw) */
    Ifx_UReg_32Bit EN30:1;            /**< \brief [30:30] Access Enable for Master TAG ID 30 - EN30 (rw) */
    Ifx_UReg_32Bit EN31:1;            /**< \brief [31:31] Access Enable for Master TAG ID 31 - EN31 (rw) */
} Ifx_ASCLIN_ACCEN0_Bits;

/** \brief Access Enable Register 1 */
typedef struct _Ifx_ASCLIN_ACCEN1_Bits
{
    Ifx_UReg_32Bit reserved_0:32;     /**< \brief [31:0] \internal Reserved */
} Ifx_ASCLIN_ACCEN1_Bits;

/** \brief Bit Configuration Register */
typedef struct _Ifx_ASCLIN_BITCON_Bits
{
    Ifx_UReg_32Bit PRESCALER:12;      /**< \brief [11:0] Prescaling of the Fractional Divider - PRESCALER (rw) */
    Ifx_UReg_32Bit reserved_12:4;     /**< \brief [15:12] \internal Reserved */
    Ifx_UReg_32Bit OVERSAMPLING:4;    /**< \brief [19:16] Oversampling Factor - OVERSAMPLING (rw) */
    Ifx_UReg_32Bit reserved_20:4;     /**< \brief [23:20] \internal Reserved */
    Ifx_UReg_32Bit SAMPLEPOINT:4;     /**< \brief [27:24] Sample Point Position - SAMPLEPOINT (rw) */
    Ifx_UReg_32Bit reserved_28:3;     /**< \brief [30:28] \internal Reserved */
    Ifx_UReg_32Bit SM:1;              /**< \brief [31:31] Sample Mode - SM (rw) */
} Ifx_ASCLIN_BITCON_Bits;

/** \brief Baud Rate Detection Register */
typedef struct _Ifx_ASCLIN_BRD_Bits
{
    Ifx_UReg_32Bit LOWERLIMIT:8;      /**< \brief [7:0] Lower Limit - LOWERLIMIT (rw) */
    Ifx_UReg_32Bit UPPERLIMIT:8;      /**< \brief [15:8] Upper Limit - UPPERLIMIT (rw) */
    Ifx_UReg_32Bit MEASURED:12;       /**< \brief [27:16] Measured Value of 8-bits from Sync Field - MEASURED (rh) */
    Ifx_UReg_32Bit reserved_28:4;     /**< \brief [31:28] \internal Reserved */
} Ifx_ASCLIN_BRD_Bits;

/** \brief Baud Rate Generation Register */
typedef struct _Ifx_ASCLIN_BRG_Bits
{
    Ifx_UReg_32Bit DENOMINATOR:12;    /**< \brief [11:0] Denominator - DENOMINATOR (rw) */
    Ifx_UReg_32Bit reserved_12:4;     /**< \brief [15:12] \internal Reserved */
    Ifx_UReg_32Bit NUMERATOR:12;      /**< \brief [27:16] Numerator - NUMERATOR (rw) */
    Ifx_UReg_32Bit reserved_28:4;     /**< \brief [31:28] \internal Reserved */
} Ifx_ASCLIN_BRG_Bits;

/** \brief Clock Control Register */
typedef struct _Ifx_ASCLIN_CLC_Bits
{
    Ifx_UReg_32Bit DISR:1;            /**< \brief [0:0] Module Disable Request Bit - DISR (rw) */
    Ifx_UReg_32Bit DISS:1;            /**< \brief [1:1] Module Disable Status Bit - DISS (rh) */
    Ifx_UReg_32Bit reserved_2:1;      /**< \brief [2:2] \internal Reserved */
    Ifx_UReg_32Bit EDIS:1;            /**< \brief [3:3] Sleep Mode Enable Control - EDIS (rw) */
    Ifx_UReg_32Bit reserved_4:28;     /**< \brief [31:4] \internal Reserved */
} Ifx_ASCLIN_CLC_Bits;

/** \brief Clock Selection Register */
typedef struct _Ifx_ASCLIN_CSR_Bits
{
    Ifx_UReg_32Bit CLKSEL:5;          /**< \brief [4:0] Baud Rate Logic Clock Select - CLKSEL (rw) */
    Ifx_UReg_32Bit reserved_5:26;     /**< \brief [30:5] \internal Reserved */
    Ifx_UReg_32Bit CON:1;             /**< \brief [31:31] Clock On Flag - CON (rh) */
} Ifx_ASCLIN_CSR_Bits;

/** \brief Data Configuration Register */
typedef struct _Ifx_ASCLIN_DATCON_Bits
{
    Ifx_UReg_32Bit DATLEN:4;          /**< \brief [3:0] Data Length - DATLEN (rw) */
    Ifx_UReg_32Bit reserved_4:9;      /**< \brief [12:4] \internal Reserved */
    Ifx_UReg_32Bit HO:1;              /**< \brief [13:13] Header Only - HO (rw) */
    Ifx_UReg_32Bit RM:1;              /**< \brief [14:14] Response Mode - RM (rw) */
    Ifx_UReg_32Bit CSM:1;             /**< \brief [15:15] Checksum Mode - CSM (rw) */
    Ifx_UReg_32Bit RESPONSE:8;        /**< \brief [23:16] Response Timeout Threshold Value - RESPONSE (rw) */
    Ifx_UReg_32Bit reserved_24:8;     /**< \brief [31:24] \internal Reserved */
} Ifx_ASCLIN_DATCON_Bits;

/** \brief Flags Register */
typedef struct _Ifx_ASCLIN_FLAGS_Bits
{
    Ifx_UReg_32Bit TH:1;              /**< \brief [0:0] Transmit Header End Flag - TH (rh) */
    Ifx_UReg_32Bit TR:1;              /**< \brief [1:1] Transmit Response End Flag - TR (rh) */
    Ifx_UReg_32Bit RH:1;              /**< \brief [2:2] Receive Header End Flag - RH (rh) */
    Ifx_UReg_32Bit RR:1;              /**< \brief [3:3] Receive Response End Flag - RR (rh) */
    Ifx_UReg_32Bit reserved_4:1;      /**< \brief [4:4] \internal Reserved */
    Ifx_UReg_32Bit FED:1;             /**< \brief [5:5] Falling Edge from Level 1 to Level 0 Detected - FED (rh) */
    Ifx_UReg_32Bit RED:1;             /**< \brief [6:6] Rising Edge from Level 0 to Level 1 Detected - RED (rh) */
    Ifx_UReg_32Bit reserved_7:6;      /**< \brief [12:7] \internal Reserved */
    Ifx_UReg_32Bit TWRQ:1;            /**< \brief [13:13] Transmit Wake Request Flag - TWRQ (rh) */
    Ifx_UReg_32Bit THRQ:1;            /**< \brief [14:14] Transmit Header Request Flag - THRQ (rh) */
    Ifx_UReg_32Bit TRRQ:1;            /**< \brief [15:15] Transmit Response Request Flag - TRRQ (rh) */
    Ifx_UReg_32Bit PE:1;              /**< \brief [16:16] Parity Error Flag - PE (rh) */
    Ifx_UReg_32Bit TC:1;              /**< \brief [17:17] Transmission Completed Flag - TC (rh) */
    Ifx_UReg_32Bit FE:1;              /**< \brief [18:18] Framing Error Flag - FE (rh) */
    Ifx_UReg_32Bit HT:1;              /**< \brief [19:19] Header Timeout Flag - HT (rh) */
    Ifx_UReg_32Bit RT:1;              /**< \brief [20:20] Response Timeout Flag - RT (rh) */
    Ifx_UReg_32Bit BD:1;              /**< \brief [21:21] Break Detected Flag - BD (rh) */
    Ifx_UReg_32Bit LP:1;              /**< \brief [22:22] LIN Parity Error Flag - LP (rh) */
    Ifx_UReg_32Bit LA:1;              /**< \brief [23:23] LIN Autobaud Detection Error Flag - LA (rh) */
    Ifx_UReg_32Bit LC:1;              /**< \brief [24:24] LIN Checksum Error Flag - LC (rh) */
    Ifx_UReg_32Bit CE:1;              /**< \brief [25:25] Collision Detection Error Flag - CE (rh) */
    Ifx_UReg_32Bit RFO:1;             /**< \brief [26:26] Receive FIFO Overflow Flag - RFO (rh) */
    Ifx_UReg_32Bit RFU:1;             /**< \brief [27:27] Receive FIFO Underflow Flag - RFU (rh) */
    Ifx_UReg_32Bit RFL:1;             /**< \brief [28:28] Receive FIFO Level Flag - RFL (rh) */
    Ifx_UReg_32Bit reserved_29:1;     /**< \brief [29:29] \internal Reserved */
    Ifx_UReg_32Bit TFO:1;             /**< \brief [30:30] Transmit FIFO Overflow Flag - TFO (rh) */
    Ifx_UReg_32Bit TFL:1;             /**< \brief [31:31] Transmit FIFO Level Flag - TFL (rh) */
} Ifx_ASCLIN_FLAGS_Bits;

/** \brief Flags Clear Register */
typedef struct _Ifx_ASCLIN_FLAGSCLEAR_Bits
{
    Ifx_UReg_32Bit THC:1;             /**< \brief [0:0] Flag Clear Bit - THC (w) */
    Ifx_UReg_32Bit TRC:1;             /**< \brief [1:1] Flag Clear Bit - TRC (w) */
    Ifx_UReg_32Bit RHC:1;             /**< \brief [2:2] Flag Clear Bit - RHC (w) */
    Ifx_UReg_32Bit RRC:1;             /**< \brief [3:3] Flag Clear Bit - RRC (w) */
    Ifx_UReg_32Bit reserved_4:1;      /**< \brief [4:4] \internal Reserved */
    Ifx_UReg_32Bit FEDC:1;            /**< \brief [5:5] Flag Clear Bit - FEDC (w) */
    Ifx_UReg_32Bit REDC:1;            /**< \brief [6:6] Flag Clear Bit - REDC (w) */
    Ifx_UReg_32Bit reserved_7:6;      /**< \brief [12:7] \internal Reserved */
    Ifx_UReg_32Bit TWRQC:1;           /**< \brief [13:13] Flag Clear Bit - TWRQC (w) */
    Ifx_UReg_32Bit THRQC:1;           /**< \brief [14:14] Flag Clear Bit - THRQC (w) */
    Ifx_UReg_32Bit TRRQC:1;           /**< \brief [15:15] Flag Clear Bit - TRRQC (w) */
    Ifx_UReg_32Bit PEC:1;             /**< \brief [16:16] Flag Clear Bit - PEC (w) */
    Ifx_UReg_32Bit TCC:1;             /**< \brief [17:17] Flag Clear Bit - TCC (w) */
    Ifx_UReg_32Bit FEC:1;             /**< \brief [18:18] Flag Clear Bit - FEC (w) */
    Ifx_UReg_32Bit HTC:1;             /**< \brief [19:19] Flag Clear Bit - HTC (w) */
    Ifx_UReg_32Bit RTC:1;             /**< \brief [20:20] Flag Clear Bit - RTC (w) */
    Ifx_UReg_32Bit BDC:1;             /**< \brief [21:21] Flag Clear Bit - BDC (w) */
    Ifx_UReg_32Bit LPC:1;             /**< \brief [22:22] Flag Clear Bit - LPC (w) */
    Ifx_UReg_32Bit LAC:1;             /**< \brief [23:23] Flag Clear Bit - LAC (w) */
    Ifx_UReg_32Bit LCC:1;             /**< \brief [24:24] Flag Clear Bit - LCC (w) */
    Ifx_UReg_32Bit CEC:1;             /**< \brief [25:25] Flag Clear Bit - CEC (w) */
    Ifx_UReg_32Bit RFOC:1;            /**< \brief [26:26] Flag Clear Bit - RFOC (w) */
    Ifx_UReg_32Bit RFUC:1;            /**< \brief [27:27] Flag Clear Bit - RFUC (w) */
    Ifx_UReg_32Bit RFLC:1;            /**< \brief [28:28] Flag Clear Bit - RFLC (w) */
    Ifx_UReg_32Bit reserved_29:1;     /**< \brief [29:29] \internal Reserved */
    Ifx_UReg_32Bit TFOC:1;            /**< \brief [30:30] Flag Clear Bit - TFOC (w) */
    Ifx_UReg_32Bit TFLC:1;            /**< \brief [31:31] Flag Clear Bit - TFLC (w) */
} Ifx_ASCLIN_FLAGSCLEAR_Bits;

/** \brief Flags Enable Register */
typedef struct _Ifx_ASCLIN_FLAGSENABLE_Bits
{
    Ifx_UReg_32Bit THE:1;             /**< \brief [0:0] Flag Enable Bit - THE (rw) */
    Ifx_UReg_32Bit TRE:1;             /**< \brief [1:1] Flag Enable Bit - TRE (rw) */
    Ifx_UReg_32Bit RHE:1;             /**< \brief [2:2] Flag Enable Bit - RHE (rw) */
    Ifx_UReg_32Bit RRE:1;             /**< \brief [3:3] Flag Enable Bit - RRE (rw) */
    Ifx_UReg_32Bit reserved_4:1;      /**< \brief [4:4] \internal Reserved */
    Ifx_UReg_32Bit FEDE:1;            /**< \brief [5:5] Flag Enable Bit - FEDE (rw) */
    Ifx_UReg_32Bit REDE:1;            /**< \brief [6:6] Flag Enable Bit - REDE (rw) */
    Ifx_UReg_32Bit reserved_7:9;      /**< \brief [15:7] \internal Reserved */
    Ifx_UReg_32Bit PEE:1;             /**< \brief [16:16] Flag Enable Bit - PEE (rw) */
    Ifx_UReg_32Bit TCE:1;             /**< \brief [17:17] Flag Enable Bit - TCE (rw) */
    Ifx_UReg_32Bit FEE:1;             /**< \brief [18:18] Flag Enable Bit - FEE (rw) */
    Ifx_UReg_32Bit HTE:1;             /**< \brief [19:19] Flag Enable Bit - HTE (rw) */
    Ifx_UReg_32Bit RTE:1;             /**< \brief [20:20] Flag Enable Bit - RTE (rw) */
    Ifx_UReg_32Bit BDE:1;             /**< \brief [21:21] Flag Enable Bit - BDE (rw) */
    Ifx_UReg_32Bit LPE:1;             /**< \brief [22:22] Flag Enable Bit - LPE (rw) */
    Ifx_UReg_32Bit LAE:1;             /**< \brief [23:23] Flag Enable Bit - LAE (rw) */
    Ifx_UReg_32Bit LCE:1;             /**< \brief [24:24] Flag Enable Bit - LCE (rw) */
    Ifx_UReg_32Bit CEE:1;             /**< \brief [25:25] Flag Enable Bit - CEE (rw) */
    Ifx_UReg_32Bit RFOE:1;            /**< \brief [26:26] Flag Enable Bit - RFOE (rw) */
    Ifx_UReg_32Bit RFUE:1;            /**< \brief [27:27] Flag Enable Bit - RFUE (rw) */
    Ifx_UReg_32Bit RFLE:1;            /**< \brief [28:28] Flag Enable Bit - RFLE (rw) */
    Ifx_UReg_32Bit reserved_29:1;     /**< \brief [29:29] \internal Reserved */
    Ifx_UReg_32Bit TFOE:1;            /**< \brief [30:30] Flag Enable Bit - TFOE (rw) */
    Ifx_UReg_32Bit TFLE:1;            /**< \brief [31:31] Flag Enable Bit - TFLE (rw) */
} Ifx_ASCLIN_FLAGSENABLE_Bits;

/** \brief Flags Set Register */
typedef struct _Ifx_ASCLIN_FLAGSSET_Bits
{
    Ifx_UReg_32Bit THS:1;             /**< \brief [0:0] Flag Set Bit - THS (w) */
    Ifx_UReg_32Bit TRS:1;             /**< \brief [1:1] Flag Set Bit - TRS (w) */
    Ifx_UReg_32Bit RHS:1;             /**< \brief [2:2] Flag Set Bit - RHS (w) */
    Ifx_UReg_32Bit RRS:1;             /**< \brief [3:3] Flag Set Bit - RRS (w) */
    Ifx_UReg_32Bit reserved_4:1;      /**< \brief [4:4] \internal Reserved */
    Ifx_UReg_32Bit FEDS:1;            /**< \brief [5:5] Flag Set Bit - FEDS (w) */
    Ifx_UReg_32Bit REDS:1;            /**< \brief [6:6] Flag Set Bit - REDS (w) */
    Ifx_UReg_32Bit reserved_7:6;      /**< \brief [12:7] \internal Reserved */
    Ifx_UReg_32Bit TWRQS:1;           /**< \brief [13:13] Flag Set Bit - TWRQS (w) */
    Ifx_UReg_32Bit THRQS:1;           /**< \brief [14:14] Flag Set Bit - THRQS (w) */
    Ifx_UReg_32Bit TRRQS:1;           /**< \brief [15:15] Flag Set Bit - TRRQS (w) */
    Ifx_UReg_32Bit PES:1;             /**< \brief [16:16] Flag Set Bit - PES (w) */
    Ifx_UReg_32Bit TCS:1;             /**< \brief [17:17] Flag Set Bit - TCS (w) */
    Ifx_UReg_32Bit FES:1;             /**< \brief [18:18] Flag Set Bit - FES (w) */
    Ifx_UReg_32Bit HTS:1;             /**< \brief [19:19] Flag Set Bit - HTS (w) */
    Ifx_UReg_32Bit RTS:1;             /**< \brief [20:20] Flag Set Bit - RTS (w) */
    Ifx_UReg_32Bit BDS:1;             /**< \brief [21:21] Flag Set Bit - BDS (w) */
    Ifx_UReg_32Bit LPS:1;             /**< \brief [22:22] Flag Set Bit - LPS (w) */
    Ifx_UReg_32Bit LAS:1;             /**< \brief [23:23] Flag Set Bit - LAS (w) */
    Ifx_UReg_32Bit LCS:1;             /**< \brief [24:24] Flag Set Bit - LCS (w) */
    Ifx_UReg_32Bit CES:1;             /**< \brief [25:25] Flag Set Bit - CES (w) */
    Ifx_UReg_32Bit RFOS:1;            /**< \brief [26:26] Flag Set Bit - RFOS (w) */
    Ifx_UReg_32Bit RFUS:1;            /**< \brief [27:27] Flag Set Bit - RFUS (w) */
    Ifx_UReg_32Bit RFLS:1;            /**< \brief [28:28] Flag Set Bit - RFLS (w) */
    Ifx_UReg_32Bit reserved_29:1;     /**< \brief [29:29] \internal Reserved */
    Ifx_UReg_32Bit TFOS:1;            /**< \brief [30:30] Flag Set Bit - TFOS (w) */
    Ifx_UReg_32Bit TFLS:1;            /**< \brief [31:31] Flag Set Bit - TFLS (w) */
} Ifx_ASCLIN_FLAGSSET_Bits;

/** \brief Frame Control Register */
typedef struct _Ifx_ASCLIN_FRAMECON_Bits
{
    Ifx_UReg_32Bit reserved_0:6;      /**< \brief [5:0] \internal Reserved */
    Ifx_UReg_32Bit IDLE:3;            /**< \brief [8:6] Duration of the IDLE delay - IDLE (rw) */
    Ifx_UReg_32Bit STOP:3;            /**< \brief [11:9] Number of Stop Bits - STOP (rw) */
    Ifx_UReg_32Bit LEAD:3;            /**< \brief [14:12] Duration of the Leading Delay - LEAD (rw) */
    Ifx_UReg_32Bit reserved_15:1;     /**< \brief [15:15] \internal Reserved */
    Ifx_UReg_32Bit MODE:2;            /**< \brief [17:16] Mode Selection - MODE (rw) */
    Ifx_UReg_32Bit reserved_18:10;    /**< \brief [27:18] \internal Reserved */
    Ifx_UReg_32Bit MSB:1;             /**< \brief [28:28] Shift Direction - MSB (rw) */
    Ifx_UReg_32Bit CEN:1;             /**< \brief [29:29] Collision Detection Enable - CEN (rw) */
    Ifx_UReg_32Bit PEN:1;             /**< \brief [30:30] Parity Enable - PEN (rw) */
    Ifx_UReg_32Bit ODD:1;             /**< \brief [31:31] Parity Type - ODD (rw) */
} Ifx_ASCLIN_FRAMECON_Bits;

/** \brief Module Identification Register */
typedef struct _Ifx_ASCLIN_ID_Bits
{
    Ifx_UReg_32Bit MODREV:8;          /**< \brief [7:0] Module Revision Number - MODREV (r) */
    Ifx_UReg_32Bit MODTYPE:8;         /**< \brief [15:8] Module Type - MODTYPE (r) */
    Ifx_UReg_32Bit MODNUMBER:16;      /**< \brief [31:16] Module Number Value - MODNUMBER (r) */
} Ifx_ASCLIN_ID_Bits;

/** \brief Input and Output Control Register */
typedef struct _Ifx_ASCLIN_IOCR_Bits
{
    Ifx_UReg_32Bit ALTI:3;            /**< \brief [2:0] Alternate Input Select - ALTI (rw) */
    Ifx_UReg_32Bit reserved_3:1;      /**< \brief [3:3] \internal Reserved */
    Ifx_UReg_32Bit DEPTH:6;           /**< \brief [9:4] Digital Glitch Filter Depth - DEPTH (rw) */
    Ifx_UReg_32Bit reserved_10:6;     /**< \brief [15:10] \internal Reserved */
    Ifx_UReg_32Bit CTS:2;             /**< \brief [17:16] CTS Select - CTS (rw) */
    Ifx_UReg_32Bit reserved_18:7;     /**< \brief [24:18] \internal Reserved */
    Ifx_UReg_32Bit RCPOL:1;           /**< \brief [25:25] RTS CTS Polarity - RCPOL (rw) */
    Ifx_UReg_32Bit CPOL:1;            /**< \brief [26:26] Clock Polarity in Synchronous Mode - CPOL (rw) */
    Ifx_UReg_32Bit SPOL:1;            /**< \brief [27:27] Slave Polarity in Synchronous Mode - SPOL (rw) */
    Ifx_UReg_32Bit LB:1;              /**< \brief [28:28] Loop Back Mode - LB (rw) */
    Ifx_UReg_32Bit CTSEN:1;           /**< \brief [29:29] Input Signal CTS Enable - CTSEN (rw) */
    Ifx_UReg_32Bit RXM:1;             /**< \brief [30:30] Receive Monitor - RXM (rh) */
    Ifx_UReg_32Bit TXM:1;             /**< \brief [31:31] Transmit Monitor - TXM (rh) */
} Ifx_ASCLIN_IOCR_Bits;

/** \brief Kernel Reset Register 0 */
typedef struct _Ifx_ASCLIN_KRST0_Bits
{
    Ifx_UReg_32Bit RST:1;             /**< \brief [0:0] Kernel Reset - RST (rwh) */
    Ifx_UReg_32Bit RSTSTAT:1;         /**< \brief [1:1] Kernel Reset Status - RSTSTAT (rh) */
    Ifx_UReg_32Bit reserved_2:30;     /**< \brief [31:2] \internal Reserved */
} Ifx_ASCLIN_KRST0_Bits;

/** \brief Kernel Reset Register 1 */
typedef struct _Ifx_ASCLIN_KRST1_Bits
{
    Ifx_UReg_32Bit RST:1;             /**< \brief [0:0] Kernel Reset - RST (rwh) */
    Ifx_UReg_32Bit reserved_1:31;     /**< \brief [31:1] \internal Reserved */
} Ifx_ASCLIN_KRST1_Bits;

/** \brief Kernel Reset Status Clear Register */
typedef struct _Ifx_ASCLIN_KRSTCLR_Bits
{
    Ifx_UReg_32Bit CLR:1;             /**< \brief [0:0] Kernel Reset Status Clear - CLR (w) */
    Ifx_UReg_32Bit reserved_1:31;     /**< \brief [31:1] \internal Reserved */
} Ifx_ASCLIN_KRSTCLR_Bits;

/** \brief LIN Break Timer Register */
typedef struct _Ifx_ASCLIN_LIN_BTIMER_Bits
{
    Ifx_UReg_32Bit BREAK:6;           /**< \brief [5:0] Break Pulse Generation and Detection - BREAK (rw) */
    Ifx_UReg_32Bit reserved_6:26;     /**< \brief [31:6] \internal Reserved */
} Ifx_ASCLIN_LIN_BTIMER_Bits;

/** \brief LIN Control Register */
typedef struct _Ifx_ASCLIN_LIN_CON_Bits
{
    Ifx_UReg_32Bit reserved_0:23;     /**< \brief [22:0] \internal Reserved */
    Ifx_UReg_32Bit CSI:1;             /**< \brief [23:23] Checksum Injection - CSI (rw) */
    Ifx_UReg_32Bit reserved_24:1;     /**< \brief [24:24] \internal Reserved */
    Ifx_UReg_32Bit CSEN:1;            /**< \brief [25:25] Hardware Checksum Enable - CSEN (rw) */
    Ifx_UReg_32Bit MS:1;              /**< \brief [26:26] Master Slave Mode - MS (rw) */
    Ifx_UReg_32Bit ABD:1;             /**< \brief [27:27] Autobaud Detection - ABD (rw) */
    Ifx_UReg_32Bit reserved_28:4;     /**< \brief [31:28] \internal Reserved */
} Ifx_ASCLIN_LIN_CON_Bits;

/** \brief LIN Header Timer Register */
typedef struct _Ifx_ASCLIN_LIN_HTIMER_Bits
{
    Ifx_UReg_32Bit HEADER:8;          /**< \brief [7:0] Header Timeout Threshold Value - HEADER (rw) */
    Ifx_UReg_32Bit reserved_8:24;     /**< \brief [31:8] \internal Reserved */
} Ifx_ASCLIN_LIN_HTIMER_Bits;

/** \brief OCDS Control and Status */
typedef struct _Ifx_ASCLIN_OCS_Bits
{
    Ifx_UReg_32Bit reserved_0:24;     /**< \brief [23:0] \internal Reserved */
    Ifx_UReg_32Bit SUS:4;             /**< \brief [27:24] OCDS Suspend Control - SUS (rw) */
    Ifx_UReg_32Bit SUS_P:1;           /**< \brief [28:28] SUS Write Protection - SUS_P (w) */
    Ifx_UReg_32Bit SUSSTA:1;          /**< \brief [29:29] Suspend State - SUSSTA (rh) */
    Ifx_UReg_32Bit reserved_30:2;     /**< \brief [31:30] \internal Reserved */
} Ifx_ASCLIN_OCS_Bits;

/** \brief Receive Data Register */
typedef struct _Ifx_ASCLIN_RXDATA_Bits
{
    Ifx_UReg_32Bit DATA:32;           /**< \brief [31:0] Data - DATA (rh) */
} Ifx_ASCLIN_RXDATA_Bits;

/** \brief Receive Data Debug Register */
typedef struct _Ifx_ASCLIN_RXDATAD_Bits
{
    Ifx_UReg_32Bit DATA:32;           /**< \brief [31:0] Data - DATA (rh) */
} Ifx_ASCLIN_RXDATAD_Bits;

/** \brief RX FIFO Configuration Register */
typedef struct _Ifx_ASCLIN_RXFIFOCON_Bits
{
    Ifx_UReg_32Bit FLUSH:1;           /**< \brief [0:0] Flush the receive FIFO - FLUSH (w) */
    Ifx_UReg_32Bit ENI:1;             /**< \brief [1:1] Receive FIFO Inlet Enable - ENI (rwh) */
    Ifx_UReg_32Bit reserved_2:2;      /**< \brief [3:2] \internal Reserved */
    Ifx_UReg_32Bit FM:2;              /**< \brief [5:4] RXFIFO Mode - FM (rw) */
    Ifx_UReg_32Bit OUTW:2;            /**< \brief [7:6] Receive FIFO Outlet Width - OUTW (rw) */
    Ifx_UReg_32Bit INTLEVEL:4;        /**< \brief [11:8] FIFO Interrupt Level - INTLEVEL (rw) */
    Ifx_UReg_32Bit reserved_12:4;     /**< \brief [15:12] \internal Reserved */
    Ifx_UReg_32Bit FILL:5;            /**< \brief [20:16] FIFO Filling Level - FILL (rh) */
    Ifx_UReg_32Bit reserved_21:10;    /**< \brief [30:21] \internal Reserved */
    Ifx_UReg_32Bit BUF:1;             /**< \brief [31:31] Receive Buffer Mode - BUF (rw) */
} Ifx_ASCLIN_RXFIFOCON_Bits;

/** \brief Transmit Data Register */
typedef struct _Ifx_ASCLIN_TXDATA_Bits
{
    Ifx_UReg_32Bit DATA:32;           /**< \brief [31:0] Data - DATA (w) */
} Ifx_ASCLIN_TXDATA_Bits;

/** \brief TX FIFO Configuration Register */
typedef struct _Ifx_ASCLIN_TXFIFOCON_Bits
{
    Ifx_UReg_32Bit FLUSH:1;           /**< \brief [0:0] Flush the transmit FIFO - FLUSH (w) */
    Ifx_UReg_32Bit ENO:1;             /**< \brief [1:1] Transmit FIFO Outlet Enable - ENO (rw) */
    Ifx_UReg_32Bit reserved_2:2;      /**< \brief [3:2] \internal Reserved */
    Ifx_UReg_32Bit FM:2;              /**< \brief [5:4] TXFIFO Mode - FM (rw) */
    Ifx_UReg_32Bit INW:2;             /**< \brief [7:6] Transmit FIFO Inlet Width - INW (rw) */
    Ifx_UReg_32Bit INTLEVEL:4;        /**< \brief [11:8] FIFO Interrupt Level - INTLEVEL (rw) */
    Ifx_UReg_32Bit reserved_12:4;     /**< \brief [15:12] \internal Reserved */
    Ifx_UReg_32Bit FILL:5;            /**< \brief [20:16] FIFO Filling Level - FILL (rh) */
    Ifx_UReg_32Bit reserved_21:11;    /**< \brief [31:21] \internal Reserved */
} Ifx_ASCLIN_TXFIFOCON_Bits;

/** \}  */
/******************************************************************************/
/******************************************************************************/
/** \addtogroup IfxSfr_asclin_Registers_union
 * \{   */
/** \brief Access Enable Register 0   */
typedef union
{
    Ifx_UReg_32Bit U;                 /**< \brief Unsigned access */
    Ifx_SReg_32Bit I;                 /**< \brief Signed access */
    Ifx_ASCLIN_ACCEN0_Bits B;         /**< \brief Bitfield access */
} Ifx_ASCLIN_ACCEN0;

/** \brief Access Enable Register 1   */
typedef union
{
    Ifx_UReg_32Bit U;                 /**< \brief Unsigned access */
    Ifx_SReg_32Bit I;                 /**< \brief Signed access */
    Ifx_ASCLIN_ACCEN1_Bits B;         /**< \brief Bitfield access */
} Ifx_ASCLIN_ACCEN1;

/** \brief Bit Configuration Register   */
typedef union
{
    Ifx_UReg_32Bit U;                 /**< \brief Unsigned access */
    Ifx_SReg_32Bit I;                 /**< \brief Signed access */
    Ifx_ASCLIN_BITCON_Bits B;         /**< \brief Bitfield access */
} Ifx_ASCLIN_BITCON;

/** \brief Baud Rate Detection Register   */
typedef union
{
    Ifx_UReg_32Bit U;                 /**< \brief Unsigned access */
    Ifx_SReg_32Bit I;                 /**< \brief Signed access */
    Ifx_ASCLIN_BRD_Bits B;            /**< \brief Bitfield access */
} Ifx_ASCLIN_BRD;

/** \brief Baud Rate Generation Register   */
typedef union
{
    Ifx_UReg_32Bit U;                 /**< \brief Unsigned access */
    Ifx_SReg_32Bit I;                 /**< \brief Signed access */
    Ifx_ASCLIN_BRG_Bits B;            /**< \brief Bitfield access */
} Ifx_ASCLIN_BRG;

/** \brief Clock Control Register   */
typedef union
{
    Ifx_UReg_32Bit U;                 /**< \brief Unsigned access */
    Ifx_SReg_32Bit I;                 /**< \brief Signed access */
    Ifx_ASCLIN_CLC_Bits B;            /**< \brief Bitfield access */
} Ifx_ASCLIN_CLC;

/** \brief Clock Selection Register   */
typedef union
{
    Ifx_UReg_32Bit U;                 /**< \brief Unsigned access */
    Ifx_SReg_32Bit I;                 /**< \brief Signed access */
    Ifx_ASCLIN_CSR_Bits B;            /**< \brief Bitfield access */
} Ifx_ASCLIN_CSR;

/** \brief Data Configuration Register   */
typedef union
{
    Ifx_UReg_32Bit U;                 /**< \brief Unsigned access */
    Ifx_SReg_32Bit I;                 /**< \brief Signed access */
    Ifx_ASCLIN_DATCON_Bits B;         /**< \brief Bitfield access */
} Ifx_ASCLIN_DATCON;

/** \brief Flags Register   */
typedef union
{
    Ifx_UReg_32Bit U;                 /**< \brief Unsigned access */
    Ifx_SReg_32Bit I;                 /**< \brief Signed access */
    Ifx_ASCLIN_FLAGS_Bits B;          /**< \brief Bitfield access */
} Ifx_ASCLIN_FLAGS;

/** \brief Flags Clear Register   */
typedef union
{
    Ifx_UReg_32Bit U;                 /**< \brief Unsigned access */
    Ifx_SReg_32Bit I;                 /**< \brief Signed access */
    Ifx_ASCLIN_FLAGSCLEAR_Bits B;     /**< \brief Bitfield access */
} Ifx_ASCLIN_FLAGSCLEAR;

/** \brief Flags Enable Register   */
typedef union
{
    Ifx_UReg_32Bit U;                 /**< \brief Unsigned access */
    Ifx_SReg_32Bit I;                 /**< \brief Signed access */
    Ifx_ASCLIN_FLAGSENABLE_Bits B;    /**< \brief Bitfield access */
} Ifx_ASCLIN_FLAGSENABLE;

/** \brief Flags Set Register   */
typedef union
{
    Ifx_UReg_32Bit U;                 /**< \brief Unsigned access */
    Ifx_SReg_32Bit I;                 /**< \brief Signed access */
    Ifx_ASCLIN_FLAGSSET_Bits B;       /**< \brief Bitfield access */
} Ifx_ASCLIN_FLAGSSET;

/** \brief Frame Control Register   */
typedef union
{
    Ifx_UReg_32Bit U;                 /**< \brief Unsigned access */
    Ifx_SReg_32Bit I;                 /**< \brief Signed access */
    Ifx_ASCLIN_FRAMECON_Bits B;       /**< \brief Bitfield access */
} Ifx_ASCLIN_FRAMECON;

/** \brief Module Identification Register   */
typedef union
{
    Ifx_UReg_32Bit U;                 /**< \brief Unsigned access */
    Ifx_SReg_32Bit I;                 /**< \brief Signed access */
    Ifx_ASCLIN_ID_Bits B;             /**< \brief Bitfield access */
} Ifx_ASCLIN_ID;

/** \brief Input and Output Control Register   */
typedef union
{
    Ifx_UReg_32Bit U;                 /**< \brief Unsigned access */
    Ifx_SReg_32Bit I;                 /**< \brief Signed access */
    Ifx_ASCLIN_IOCR_Bits B;           /**< \brief Bitfield access */
} Ifx_ASCLIN_IOCR;

/** \brief Kernel Reset Register 0   */
typedef union
{
    Ifx_UReg_32Bit U;                 /**< \brief Unsigned access */
    Ifx_SReg_32Bit I;                 /**< \brief Signed access */
    Ifx_ASCLIN_KRST0_Bits B;          /**< \brief Bitfield access */
} Ifx_ASCLIN_KRST0;

/** \brief Kernel Reset Register 1   */
typedef union
{
    Ifx_UReg_32Bit U;                 /**< \brief Unsigned access */
    Ifx_SReg_32Bit I;                 /**< \brief Signed access */
    Ifx_ASCLIN_KRST1_Bits B;          /**< \brief Bitfield access */
} Ifx_ASCLIN_KRST1;

/** \brief Kernel Reset Status Clear Register   */
typedef union
{
    Ifx_UReg_32Bit U;                 /**< \brief Unsigned access */
    Ifx_SReg_32Bit I;                 /**< \brief Signed access */
    Ifx_ASCLIN_KRSTCLR_Bits B;        /**< \brief Bitfield access */
} Ifx_ASCLIN_KRSTCLR;

/** \brief LIN Break Timer Register   */
typedef union
{
    Ifx_UReg_32Bit U;                 /**< \brief Unsigned access */
    Ifx_SReg_32Bit I;                 /**< \brief Signed access */
    Ifx_ASCLIN_LIN_BTIMER_Bits B;     /**< \brief Bitfield access */
} Ifx_ASCLIN_LIN_BTIMER;

/** \brief LIN Control Register   */
typedef union
{
    Ifx_UReg_32Bit U;                 /**< \brief Unsigned access */
    Ifx_SReg_32Bit I;                 /**< \brief Signed access */
    Ifx_ASCLIN_LIN_CON_Bits B;        /**< \brief Bitfield access */
} Ifx_ASCLIN_LIN_CON;

/** \brief LIN Header Timer Register   */
typedef union
{
    Ifx_UReg_32Bit U;                 /**< \brief Unsigned access */
    Ifx_SReg_32Bit I;                 /**< \brief Signed access */
    Ifx_ASCLIN_LIN_HTIMER_Bits B;     /**< \brief Bitfield access */
} Ifx_ASCLIN_LIN_HTIMER;

/** \brief OCDS Control and Status   */
typedef union
{
    Ifx_UReg_32Bit U;                 /**< \brief Unsigned access */
    Ifx_SReg_32Bit I;                 /**< \brief Signed access */
    Ifx_ASCLIN_OCS_Bits B;            /**< \brief Bitfield access */
} Ifx_ASCLIN_OCS;

/** \brief Receive Data Register   */
typedef union
{
    Ifx_UReg_32Bit U;                 /**< \brief Unsigned access */
    Ifx_SReg_32Bit I;                 /**< \brief Signed access */
    Ifx_ASCLIN_RXDATA_Bits B;         /**< \brief Bitfield access */
} Ifx_ASCLIN_RXDATA;

/** \brief Receive Data Debug Register   */
typedef union
{
    Ifx_UReg_32Bit U;                 /**< \brief Unsigned access */
    Ifx_SReg_32Bit I;                 /**< \brief Signed access */
    Ifx_ASCLIN_RXDATAD_Bits B;        /**< \brief Bitfield access */
} Ifx_ASCLIN_RXDATAD;

/** \brief RX FIFO Configuration Register   */
typedef union
{
    Ifx_UReg_32Bit U;                 /**< \brief Unsigned access */
    Ifx_SReg_32Bit I;                 /**< \brief Signed access */
    Ifx_ASCLIN_RXFIFOCON_Bits B;      /**< \brief Bitfield access */
} Ifx_ASCLIN_RXFIFOCON;

/** \brief Transmit Data Register   */
typedef union
{
    Ifx_UReg_32Bit U;                 /**< \brief Unsigned access */
    Ifx_SReg_32Bit I;                 /**< \brief Signed access */
    Ifx_ASCLIN_TXDATA_Bits B;         /**< \brief Bitfield access */
} Ifx_ASCLIN_TXDATA;

/** \brief TX FIFO Configuration Register   */
typedef union
{
    Ifx_UReg_32Bit U;                 /**< \brief Unsigned access */
    Ifx_SReg_32Bit I;                 /**< \brief Signed access */
    Ifx_ASCLIN_TXFIFOCON_Bits B;      /**< \brief Bitfield access */
} Ifx_ASCLIN_TXFIFOCON;

/** \}  */

/******************************************************************************/
/******************************************************************************/
/** \addtogroup IfxSfr_Asclin_LIN_struct
 * \{  */
/******************************************************************************/
/** \name Object L1
 * \{  */
/** \brief LIN object */
typedef volatile struct _Ifx_ASCLIN_LIN
{
       Ifx_ASCLIN_LIN_CON                  CON;                    /**< \brief 0, LIN Control Register*/
       Ifx_ASCLIN_LIN_BTIMER               BTIMER;                 /**< \brief 4, LIN Break Timer Register*/
       Ifx_ASCLIN_LIN_HTIMER               HTIMER;                 /**< \brief 8, LIN Header Timer Register*/
} Ifx_ASCLIN_LIN;
/** \}  */
/******************************************************************************/
/** \}  */
/******************************************************************************/
/******************************************************************************/

/******************************************************************************/
/** \addtogroup IfxSfr_Asclin_Registers_struct
 * \{  */
/******************************************************************************/
/** \name Object L0
 * \{  */

/** \brief ASCLIN object */
typedef volatile struct _Ifx_ASCLIN
{
       Ifx_ASCLIN_CLC                      CLC;                    /**< \brief 0, Clock Control Register*/
       Ifx_ASCLIN_IOCR                     IOCR;                   /**< \brief 4, Input and Output Control Register*/
       Ifx_ASCLIN_ID                       ID;                     /**< \brief 8, Module Identification Register*/
       Ifx_ASCLIN_TXFIFOCON                TXFIFOCON;              /**< \brief C, TX FIFO Configuration Register*/
       Ifx_ASCLIN_RXFIFOCON                RXFIFOCON;              /**< \brief 10, RX FIFO Configuration Register*/
       Ifx_ASCLIN_BITCON                   BITCON;                 /**< \brief 14, Bit Configuration Register*/
       Ifx_ASCLIN_FRAMECON                 FRAMECON;               /**< \brief 18, Frame Control Register*/
       Ifx_ASCLIN_DATCON                   DATCON;                 /**< \brief 1C, Data Configuration Register*/
       Ifx_ASCLIN_BRG                      BRG;                    /**< \brief 20, Baud Rate Generation Register*/
       Ifx_ASCLIN_BRD                      BRD;                    /**< \brief 24, Baud Rate Detection Register*/
       Ifx_ASCLIN_LIN                      LIN;                    /**< \brief 28, LIN Header Timer Register*/
       Ifx_ASCLIN_FLAGS                    FLAGS;                  /**< \brief 34, Flags Register*/
       Ifx_ASCLIN_FLAGSSET                 FLAGSSET;               /**< \brief 38, Flags Set Register*/
       Ifx_ASCLIN_FLAGSCLEAR               FLAGSCLEAR;             /**< \brief 3C, Flags Clear Register*/
       Ifx_ASCLIN_FLAGSENABLE              FLAGSENABLE;            /**< \brief 40, Flags Enable Register*/
       Ifx_ASCLIN_TXDATA                   TXDATA;                 /**< \brief 44, Transmit Data Register*/
       Ifx_ASCLIN_RXDATA                   RXDATA;                 /**< \brief 48, Receive Data Register*/
       Ifx_ASCLIN_CSR                      CSR;                    /**< \brief 4C, Clock Selection Register*/
       Ifx_ASCLIN_RXDATAD                  RXDATAD;                /**< \brief 50, Receive Data Debug Register*/
       Ifx_UReg_8Bit                       reserved_54[148];       /**< \brief 54, \internal Reserved */
       Ifx_ASCLIN_OCS                      OCS;                    /**< \brief E8, OCDS Control and Status*/
       Ifx_ASCLIN_KRSTCLR                  KRSTCLR;                /**< \brief EC, Kernel Reset Status Clear Register*/
       Ifx_ASCLIN_KRST1                    KRST1;                  /**< \brief F0, Kernel Reset Register 1*/
       Ifx_ASCLIN_KRST0                    KRST0;                  /**< \brief F4, Kernel Reset Register 0*/
       Ifx_ASCLIN_ACCEN1                   ACCEN1;                 /**< \brief F8, Access Enable Register 1*/
       Ifx_ASCLIN_ACCEN0                   ACCEN0;                 /**< \brief FC, Access Enable Register 0*/
} Ifx_ASCLIN;

/** \}  */
/******************************************************************************/
/** \}  */


/******************************************************************************/

/******************************************************************************/

#endif /* IFXASCLIN_REGDEF_H */
