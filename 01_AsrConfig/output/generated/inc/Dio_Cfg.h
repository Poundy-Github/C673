
/*******************************************************************************
**                                                                            **
** Copyright (C) Infineon Technologies (2020)                                 **
**                                                                            **
** All rights reserved.                                                       **
**                                                                            **
** This document contains proprietary information belonging to Infineon       **
** Technologies. Passing on and copying of this document, and communication   **
** of its contents is not permitted without prior written authorization.      **
**                                                                            **
********************************************************************************
**                                                                            **
**  FILENAME  : Dio_Cfg.h                                                     **
**                                                                            **
**  VERSION   : 8.0.0                                                         **
**                                                                            **
**  DATE, TIME: 2023-02-28, 15:54:28         !!!IGNORE-LINE!!!                **
**                                                                            **
**  GENERATOR : Build b211016-0103             !!!IGNORE-LINE!!!              **
**                                                                            **
**  BSW MODULE DECRIPTION : Dio.bmd                                           **
**                                                                            **
**  VARIANT   : Variant LT                                                    **
**                                                                            **
**  PLATFORM  : Infineon AURIX2G                                              **
**                                                                            **
**  AUTHOR    : DL-AUTOSAR-Engineering                                        **
**                                                                            **
**  VENDOR    : Infineon Technologies                                         **
**                                                                            **
**  DESCRIPTION  : Dio configuration generated out of ECUC file               **
**                                                                            **
**  SPECIFICATION(S) : Specification of Dio Driver, AUTOSAR Release 4.2.2     **
**                     and AUTOSAR Release 4.4.0                              **
**                                                                            **
** MAY BE CHANGED BY USER : no                                                **
**                                                                            **
*******************************************************************************/
#ifndef DIO_CFG_H
#define DIO_CFG_H
/*
Notes:
- The runtime configuration is handled by the Port Driver Module.
- The configuration and usage of the DIO Driver Module is adapted to
the microcontroller and ECU.

*/

/*Version check macros */
#define DIO_AR_RELEASE_MAJOR_VERSION     (4U)
#define DIO_AR_RELEASE_MINOR_VERSION     (2U)
#define DIO_AR_RELEASE_REVISION_VERSION  (2U)


#define DIO_SW_MAJOR_VERSION  (20U)
#define DIO_SW_MINOR_VERSION  (0U)
#define DIO_SW_PATCH_VERSION  (1U)

/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/

/*******************************************************************************
**                      Global Macro Definitions                              **
*******************************************************************************/

/*                          Container: DioGeneral                            */
/*

Pre-processor switch to enable/disable detection of Development errors.
- if defined ON, Development error detection is enabled
- if defined OFF, Development error detection is disabled
*/
#define DIO_DEV_ERROR_DETECT                (STD_OFF)

/*
Pre-Compiler switch to include the API Dio_GetVersionInfo()
- if defined ON, Dio_GetVersionInfo API available
- if defined OFF, Dio_GetVersionInfo API not available
*/
#define DIO_VERSION_INFO_API                (STD_OFF)

/*
Pre-Compiler switch to include the API Dio_FlipChannel()
- if defined ON, Dio_FlipChannel API available
- if defined OFF, Dio_FlipChannel API not available
*/
#define DIO_FLIP_CHANNEL_API                (STD_OFF)

#define DIO_MASKED_WRITE_PORT_API           (STD_OFF)
/*
Pre-Compiler switch to include the Safety Check
*/

#define DIO_SAFETY_ENABLE                (STD_OFF)

/* The following macros are available only if development error detection
is enabled */
/* Macro to define the maximum port available */
#define MAX_AVAILABLE_PORT                  (40U)

/* Values to mask the undefined port pins within a port */
#define DIO_MASK_ALL_PINS_PORT0             (0x1fffU)
#define DIO_MASK_ALL_PINS_PORT1             (0x00f8U)
#define DIO_MASK_ALL_PINS_PORT2             (0x0fffU)
#define DIO_MASK_ALL_PINS_PORT3             (0x0000U)
#define DIO_MASK_ALL_PINS_PORT4             (0x0000U)
#define DIO_MASK_ALL_PINS_PORT5             (0x0000U)
#define DIO_MASK_ALL_PINS_PORT6             (0x0000U)
#define DIO_MASK_ALL_PINS_PORT7             (0x0000U)
#define DIO_MASK_ALL_PINS_PORT8             (0x0000U)
#define DIO_MASK_ALL_PINS_PORT9             (0x0000U)
#define DIO_MASK_ALL_PINS_PORT10             (0x01ffU)
#define DIO_MASK_ALL_PINS_PORT11             (0xffffU)
#define DIO_MASK_ALL_PINS_PORT12             (0x0003U)
#define DIO_MASK_ALL_PINS_PORT13             (0x000fU)
#define DIO_MASK_ALL_PINS_PORT14             (0x07ffU)
#define DIO_MASK_ALL_PINS_PORT15             (0x01ffU)
#define DIO_MASK_ALL_PINS_PORT16             (0x0000U)
#define DIO_MASK_ALL_PINS_PORT17             (0x0000U)
#define DIO_MASK_ALL_PINS_PORT18             (0x0000U)
#define DIO_MASK_ALL_PINS_PORT19             (0x0000U)
#define DIO_MASK_ALL_PINS_PORT20             (0x7fcfU)
#define DIO_MASK_ALL_PINS_PORT21             (0x00ffU)
#define DIO_MASK_ALL_PINS_PORT22             (0x0fffU)
#define DIO_MASK_ALL_PINS_PORT23             (0x00ffU)
#define DIO_MASK_ALL_PINS_PORT24             (0x0000U)
#define DIO_MASK_ALL_PINS_PORT25             (0x0000U)
#define DIO_MASK_ALL_PINS_PORT26             (0x0000U)
#define DIO_MASK_ALL_PINS_PORT27             (0x0000U)
#define DIO_MASK_ALL_PINS_PORT28             (0x0000U)
#define DIO_MASK_ALL_PINS_PORT29             (0x0000U)
#define DIO_MASK_ALL_PINS_PORT30             (0x0000U)
#define DIO_MASK_ALL_PINS_PORT31             (0x0000U)
#define DIO_MASK_ALL_PINS_PORT32             (0x00ffU)
#define DIO_MASK_ALL_PINS_PORT33             (0xffffU)
#define DIO_MASK_ALL_PINS_PORT34             (0x003eU)
#define DIO_MASK_ALL_PINS_PORT35             (0x0000U)
#define DIO_MASK_ALL_PINS_PORT36             (0x0000U)
#define DIO_MASK_ALL_PINS_PORT37             (0x0000U)
#define DIO_MASK_ALL_PINS_PORT38             (0x0000U)
#define DIO_MASK_ALL_PINS_PORT39             (0x0000U)
#define DIO_MASK_ALL_PINS_PORT40             (0x7fffU)
#define DIO_MASK_ALL_PINS_PORT41             (0x0000U)

#define DIO_MAX_VALID_PORT_PIN_ID                  (0x28eU)

/* Macro to define the No of channel groups configured */
#define DIO_CHANNELGROUPCOUNT               (0U)


/*******************************************************************************
**                           Global Symbols                                   **
*******************************************************************************/

/*
Symbolic names for DIO Channels, Port & Channel groups
*/

/*
Symbolic names for Channels
*/
#define DIO_CHANNEL_0_0                    ((Dio_ChannelType)0x000)
#define DIO_CHANNEL_0_1                    ((Dio_ChannelType)0x001)
#define DIO_CHANNEL_0_2                    ((Dio_ChannelType)0x002)
#define DIO_CHANNEL_0_3                    ((Dio_ChannelType)0x003)
#define DIO_CHANNEL_0_4                    ((Dio_ChannelType)0x004)
#define DIO_CHANNEL_0_5                    ((Dio_ChannelType)0x005)
#define DIO_CHANNEL_0_6                    ((Dio_ChannelType)0x006)
#define DIO_CHANNEL_0_7                    ((Dio_ChannelType)0x007)
#define DIO_CHANNEL_0_8                    ((Dio_ChannelType)0x008)
#define DIO_CHANNEL_0_9                    ((Dio_ChannelType)0x009)
#define DIO_CHANNEL_0_10                    ((Dio_ChannelType)0x00a)
#define DIO_CHANNEL_0_11                    ((Dio_ChannelType)0x00b)
#define DIO_CHANNEL_0_12                    ((Dio_ChannelType)0x00c)
#define DIO_CHANNEL_1_3                    ((Dio_ChannelType)0x013)
#define DIO_CHANNEL_1_4                    ((Dio_ChannelType)0x014)
#define DIO_CHANNEL_1_5                    ((Dio_ChannelType)0x015)
#define DIO_CHANNEL_1_6                    ((Dio_ChannelType)0x016)
#define DIO_CHANNEL_1_7                    ((Dio_ChannelType)0x017)
#define DIO_CHANNEL_2_0                    ((Dio_ChannelType)0x020)
#define DIO_CHANNEL_2_1                    ((Dio_ChannelType)0x021)
#define DIO_CHANNEL_2_2                    ((Dio_ChannelType)0x022)
#define DIO_CHANNEL_2_3                    ((Dio_ChannelType)0x023)
#define DIO_CHANNEL_2_4                    ((Dio_ChannelType)0x024)
#define DIO_CHANNEL_2_5                    ((Dio_ChannelType)0x025)
#define DIO_CHANNEL_2_6                    ((Dio_ChannelType)0x026)
#define DIO_CHANNEL_2_7                    ((Dio_ChannelType)0x027)
#define DIO_CHANNEL_2_8                    ((Dio_ChannelType)0x028)
#define DIO_CHANNEL_2_9                    ((Dio_ChannelType)0x029)
#define DIO_CHANNEL_2_10                    ((Dio_ChannelType)0x02a)
#define DIO_CHANNEL_2_11                    ((Dio_ChannelType)0x02b)
#define DIO_CHANNEL_10_0                    ((Dio_ChannelType)0x0a0)
#define DIO_CHANNEL_10_1                    ((Dio_ChannelType)0x0a1)
#define DIO_CHANNEL_10_2                    ((Dio_ChannelType)0x0a2)
#define DIO_CHANNEL_10_3                    ((Dio_ChannelType)0x0a3)
#define DIO_CHANNEL_10_4                    ((Dio_ChannelType)0x0a4)
#define DIO_CHANNEL_10_5                    ((Dio_ChannelType)0x0a5)
#define DIO_CHANNEL_10_6                    ((Dio_ChannelType)0x0a6)
#define DIO_CHANNEL_10_7                    ((Dio_ChannelType)0x0a7)
#define DIO_CHANNEL_10_8                    ((Dio_ChannelType)0x0a8)
#define DIO_CHANNEL_11_0                    ((Dio_ChannelType)0x0b0)
#define DIO_CHANNEL_11_1                    ((Dio_ChannelType)0x0b1)
#define DIO_CHANNEL_11_2                    ((Dio_ChannelType)0x0b2)
#define DIO_CHANNEL_11_3                    ((Dio_ChannelType)0x0b3)
#define DIO_CHANNEL_11_4                    ((Dio_ChannelType)0x0b4)
#define DIO_CHANNEL_11_5                    ((Dio_ChannelType)0x0b5)
#define DIO_CHANNEL_11_6                    ((Dio_ChannelType)0x0b6)
#define DIO_CHANNEL_11_7                    ((Dio_ChannelType)0x0b7)
#define DIO_CHANNEL_11_8                    ((Dio_ChannelType)0x0b8)
#define DIO_CHANNEL_11_9                    ((Dio_ChannelType)0x0b9)
#define DIO_CHANNEL_11_10                    ((Dio_ChannelType)0x0ba)
#define DIO_CHANNEL_11_11                    ((Dio_ChannelType)0x0bb)
#define DIO_CHANNEL_11_12                    ((Dio_ChannelType)0x0bc)
#define DIO_CHANNEL_11_13                    ((Dio_ChannelType)0x0bd)
#define DIO_CHANNEL_11_14                    ((Dio_ChannelType)0x0be)
#define DIO_CHANNEL_11_15                    ((Dio_ChannelType)0x0bf)
#define DIO_CHANNEL_12_0                    ((Dio_ChannelType)0x0c0)
#define DIO_CHANNEL_12_1                    ((Dio_ChannelType)0x0c1)
#define DIO_CHANNEL_13_0                    ((Dio_ChannelType)0x0d0)
#define DIO_CHANNEL_13_1                    ((Dio_ChannelType)0x0d1)
#define DIO_CHANNEL_13_2                    ((Dio_ChannelType)0x0d2)
#define DIO_CHANNEL_13_3                    ((Dio_ChannelType)0x0d3)
#define DIO_CHANNEL_14_0                    ((Dio_ChannelType)0x0e0)
#define DIO_CHANNEL_14_1                    ((Dio_ChannelType)0x0e1)
#define DIO_CHANNEL_14_2                    ((Dio_ChannelType)0x0e2)
#define DIO_CHANNEL_14_3                    ((Dio_ChannelType)0x0e3)
#define DIO_CHANNEL_14_4                    ((Dio_ChannelType)0x0e4)
#define DIO_CHANNEL_14_5                    ((Dio_ChannelType)0x0e5)
#define DIO_CHANNEL_14_6                    ((Dio_ChannelType)0x0e6)
#define DIO_CHANNEL_14_7                    ((Dio_ChannelType)0x0e7)
#define DIO_CHANNEL_14_8                    ((Dio_ChannelType)0x0e8)
#define DIO_CHANNEL_14_9                    ((Dio_ChannelType)0x0e9)
#define DIO_CHANNEL_14_10                    ((Dio_ChannelType)0x0ea)
#define DIO_CHANNEL_15_0                    ((Dio_ChannelType)0x0f0)
#define DIO_CHANNEL_15_1                    ((Dio_ChannelType)0x0f1)
#define DIO_CHANNEL_15_2                    ((Dio_ChannelType)0x0f2)
#define DIO_CHANNEL_15_3                    ((Dio_ChannelType)0x0f3)
#define DIO_CHANNEL_15_4                    ((Dio_ChannelType)0x0f4)
#define DIO_CHANNEL_15_5                    ((Dio_ChannelType)0x0f5)
#define DIO_CHANNEL_15_6                    ((Dio_ChannelType)0x0f6)
#define DIO_CHANNEL_15_7                    ((Dio_ChannelType)0x0f7)
#define DIO_CHANNEL_15_8                    ((Dio_ChannelType)0x0f8)
#define DIO_CHANNEL_20_0                    ((Dio_ChannelType)0x140)
#define DIO_CHANNEL_20_1                    ((Dio_ChannelType)0x141)
#define DIO_CHANNEL_20_2                    ((Dio_ChannelType)0x142)
#define DIO_CHANNEL_20_3                    ((Dio_ChannelType)0x143)
#define DIO_CHANNEL_20_6                    ((Dio_ChannelType)0x146)
#define DIO_CHANNEL_20_7                    ((Dio_ChannelType)0x147)
#define DIO_CHANNEL_20_8                    ((Dio_ChannelType)0x148)
#define DIO_CHANNEL_20_9                    ((Dio_ChannelType)0x149)
#define DIO_CHANNEL_20_10                    ((Dio_ChannelType)0x14a)
#define DIO_CHANNEL_20_11                    ((Dio_ChannelType)0x14b)
#define DIO_CHANNEL_20_12                    ((Dio_ChannelType)0x14c)
#define DIO_CHANNEL_20_13                    ((Dio_ChannelType)0x14d)
#define DIO_CHANNEL_20_14                    ((Dio_ChannelType)0x14e)
#define DIO_CHANNEL_21_0                    ((Dio_ChannelType)0x150)
#define DIO_CHANNEL_21_1                    ((Dio_ChannelType)0x151)
#define DIO_CHANNEL_21_2                    ((Dio_ChannelType)0x152)
#define DIO_CHANNEL_21_3                    ((Dio_ChannelType)0x153)
#define DIO_CHANNEL_21_4                    ((Dio_ChannelType)0x154)
#define DIO_CHANNEL_21_5                    ((Dio_ChannelType)0x155)
#define DIO_CHANNEL_21_6                    ((Dio_ChannelType)0x156)
#define DIO_CHANNEL_21_7                    ((Dio_ChannelType)0x157)
#define DIO_CHANNEL_22_0                    ((Dio_ChannelType)0x160)
#define DIO_CHANNEL_22_1                    ((Dio_ChannelType)0x161)
#define DIO_CHANNEL_22_2                    ((Dio_ChannelType)0x162)
#define DIO_CHANNEL_22_3                    ((Dio_ChannelType)0x163)
#define DIO_CHANNEL_22_4                    ((Dio_ChannelType)0x164)
#define DIO_CHANNEL_22_5                    ((Dio_ChannelType)0x165)
#define DIO_CHANNEL_22_6                    ((Dio_ChannelType)0x166)
#define DIO_CHANNEL_22_7                    ((Dio_ChannelType)0x167)
#define DIO_CHANNEL_22_8                    ((Dio_ChannelType)0x168)
#define DIO_CHANNEL_22_9                    ((Dio_ChannelType)0x169)
#define DIO_CHANNEL_22_10                    ((Dio_ChannelType)0x16a)
#define DIO_CHANNEL_22_11                    ((Dio_ChannelType)0x16b)
#define DIO_CHANNEL_23_0                    ((Dio_ChannelType)0x170)
#define DIO_CHANNEL_23_1                    ((Dio_ChannelType)0x171)
#define DIO_CHANNEL_23_2                    ((Dio_ChannelType)0x172)
#define DIO_CHANNEL_23_3                    ((Dio_ChannelType)0x173)
#define DIO_CHANNEL_23_4                    ((Dio_ChannelType)0x174)
#define DIO_CHANNEL_23_5                    ((Dio_ChannelType)0x175)
#define DIO_CHANNEL_23_6                    ((Dio_ChannelType)0x176)
#define DIO_CHANNEL_23_7                    ((Dio_ChannelType)0x177)
#define DIO_CHANNEL_32_0                    ((Dio_ChannelType)0x200)
#define DIO_CHANNEL_32_1                    ((Dio_ChannelType)0x201)
#define DIO_CHANNEL_32_2                    ((Dio_ChannelType)0x202)
#define DIO_CHANNEL_32_3                    ((Dio_ChannelType)0x203)
#define DIO_CHANNEL_32_4                    ((Dio_ChannelType)0x204)
#define DIO_CHANNEL_32_5                    ((Dio_ChannelType)0x205)
#define DIO_CHANNEL_32_6                    ((Dio_ChannelType)0x206)
#define DIO_CHANNEL_32_7                    ((Dio_ChannelType)0x207)
#define DIO_CHANNEL_33_0                    ((Dio_ChannelType)0x210)
#define DIO_CHANNEL_33_1                    ((Dio_ChannelType)0x211)
#define DIO_CHANNEL_33_2                    ((Dio_ChannelType)0x212)
#define DIO_CHANNEL_33_3                    ((Dio_ChannelType)0x213)
#define DIO_CHANNEL_33_4                    ((Dio_ChannelType)0x214)
#define DIO_CHANNEL_33_5                    ((Dio_ChannelType)0x215)
#define DIO_CHANNEL_33_6                    ((Dio_ChannelType)0x216)
#define DIO_CHANNEL_33_7                    ((Dio_ChannelType)0x217)
#define DIO_CHANNEL_33_8                    ((Dio_ChannelType)0x218)
#define DIO_CHANNEL_33_9                    ((Dio_ChannelType)0x219)
#define DIO_CHANNEL_33_10                    ((Dio_ChannelType)0x21a)
#define DIO_CHANNEL_33_11                    ((Dio_ChannelType)0x21b)
#define DIO_CHANNEL_33_12                    ((Dio_ChannelType)0x21c)
#define DIO_CHANNEL_33_13                    ((Dio_ChannelType)0x21d)
#define DIO_CHANNEL_33_14                    ((Dio_ChannelType)0x21e)
#define DIO_CHANNEL_33_15                    ((Dio_ChannelType)0x21f)
#define DIO_CHANNEL_34_1                    ((Dio_ChannelType)0x221)
#define DIO_CHANNEL_34_2                    ((Dio_ChannelType)0x222)
#define DIO_CHANNEL_34_3                    ((Dio_ChannelType)0x223)
#define DIO_CHANNEL_34_4                    ((Dio_ChannelType)0x224)
#define DIO_CHANNEL_34_5                    ((Dio_ChannelType)0x225)
#define DIO_CHANNEL_40_0                    ((Dio_ChannelType)0x280)
#define DIO_CHANNEL_40_1                    ((Dio_ChannelType)0x281)
#define DIO_CHANNEL_40_2                    ((Dio_ChannelType)0x282)
#define DIO_CHANNEL_40_3                    ((Dio_ChannelType)0x283)
#define DIO_CHANNEL_40_4                    ((Dio_ChannelType)0x284)
#define DIO_CHANNEL_40_5                    ((Dio_ChannelType)0x285)
#define DIO_CHANNEL_40_6                    ((Dio_ChannelType)0x286)
#define DIO_CHANNEL_40_7                    ((Dio_ChannelType)0x287)
#define DIO_CHANNEL_40_8                    ((Dio_ChannelType)0x288)
#define DIO_CHANNEL_40_9                    ((Dio_ChannelType)0x289)
#define DIO_CHANNEL_40_10                    ((Dio_ChannelType)0x28a)
#define DIO_CHANNEL_40_11                    ((Dio_ChannelType)0x28b)
#define DIO_CHANNEL_40_12                    ((Dio_ChannelType)0x28c)
#define DIO_CHANNEL_40_13                    ((Dio_ChannelType)0x28d)
#define DIO_CHANNEL_40_14                    ((Dio_ChannelType)0x28e)
/*
Symbolic names for DIO ports
*/
#define DIO_PORT_0                          ((Dio_PortType)0)
#define DIO_PORT_1                          ((Dio_PortType)1)
#define DIO_PORT_2                          ((Dio_PortType)2)
#define DIO_PORT_10                          ((Dio_PortType)10)
#define DIO_PORT_11                          ((Dio_PortType)11)
#define DIO_PORT_12                          ((Dio_PortType)12)
#define DIO_PORT_13                          ((Dio_PortType)13)
#define DIO_PORT_14                          ((Dio_PortType)14)
#define DIO_PORT_15                          ((Dio_PortType)15)
#define DIO_PORT_20                          ((Dio_PortType)20)
#define DIO_PORT_21                          ((Dio_PortType)21)
#define DIO_PORT_22                          ((Dio_PortType)22)
#define DIO_PORT_23                          ((Dio_PortType)23)
#define DIO_PORT_32                          ((Dio_PortType)32)
#define DIO_PORT_33                          ((Dio_PortType)33)
#define DIO_PORT_34                          ((Dio_PortType)34)
#define DIO_PORT_40                          ((Dio_PortType)40)

/*
User Defined Symbolic Names for the DIO Ports, Channels & Channel Groups
*/
/*
DIO PORT : (DioPort_0)
*/
#ifndef DioConf_DioPort_DioPort_0
#define DioConf_DioPort_DioPort_0 (DIO_PORT_0)
#endif
/* DIO Channel : (DIO_DO_AURIX_CAN2_STB) */
/* MISRA2012_RULE_5_1_JUSTIFICATION: External identifiers are defined
according to requirement ecuc_sws_2108*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: External identifiers are defined
according to requirement ecuc_sws_2108*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: External identifiers are defined
according to requirement ecuc_sws_2108*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: External identifiers are defined
according to requirement ecuc_sws_2108*/
#ifndef DioConf_DioChannel_DIO_DO_AURIX_CAN2_STB
/* MISRA2012_RULE_5_1_JUSTIFICATION: External identifiers are defined
according to requirement ecuc_sws_2108*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: External identifiers are defined
according to requirement ecuc_sws_2108*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: External identifiers are defined
according to requirement ecuc_sws_2108*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: External identifiers are defined
according to requirement ecuc_sws_2108*/
#define DioConf_DioChannel_DIO_DO_AURIX_CAN2_STB (DIO_CHANNEL_0_6)
#endif
/* DIO Channel : (DIO_DO_AURIX_CAN3_STB) */
/* MISRA2012_RULE_5_1_JUSTIFICATION: External identifiers are defined
according to requirement ecuc_sws_2108*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: External identifiers are defined
according to requirement ecuc_sws_2108*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: External identifiers are defined
according to requirement ecuc_sws_2108*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: External identifiers are defined
according to requirement ecuc_sws_2108*/
#ifndef DioConf_DioChannel_DIO_DO_AURIX_CAN3_STB
/* MISRA2012_RULE_5_1_JUSTIFICATION: External identifiers are defined
according to requirement ecuc_sws_2108*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: External identifiers are defined
according to requirement ecuc_sws_2108*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: External identifiers are defined
according to requirement ecuc_sws_2108*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: External identifiers are defined
according to requirement ecuc_sws_2108*/
#define DioConf_DioChannel_DIO_DO_AURIX_CAN3_STB (DIO_CHANNEL_0_7)
#endif
/* DIO Channel : (MCU_CAN10_RXD_CAN0RXD) */
/* MISRA2012_RULE_5_1_JUSTIFICATION: External identifiers are defined
according to requirement ecuc_sws_2108*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: External identifiers are defined
according to requirement ecuc_sws_2108*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: External identifiers are defined
according to requirement ecuc_sws_2108*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: External identifiers are defined
according to requirement ecuc_sws_2108*/
#ifndef DioConf_DioChannel_MCU_CAN10_RXD_CAN0RXD
/* MISRA2012_RULE_5_1_JUSTIFICATION: External identifiers are defined
according to requirement ecuc_sws_2108*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: External identifiers are defined
according to requirement ecuc_sws_2108*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: External identifiers are defined
according to requirement ecuc_sws_2108*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: External identifiers are defined
according to requirement ecuc_sws_2108*/
#define DioConf_DioChannel_MCU_CAN10_RXD_CAN0RXD (DIO_CHANNEL_0_1)
#endif
/* DIO Channel : (MCU_CAN11_RXD_CAN1RXD) */
/* MISRA2012_RULE_5_1_JUSTIFICATION: External identifiers are defined
according to requirement ecuc_sws_2108*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: External identifiers are defined
according to requirement ecuc_sws_2108*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: External identifiers are defined
according to requirement ecuc_sws_2108*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: External identifiers are defined
according to requirement ecuc_sws_2108*/
#ifndef DioConf_DioChannel_MCU_CAN11_RXD_CAN1RXD
/* MISRA2012_RULE_5_1_JUSTIFICATION: External identifiers are defined
according to requirement ecuc_sws_2108*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: External identifiers are defined
according to requirement ecuc_sws_2108*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: External identifiers are defined
according to requirement ecuc_sws_2108*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: External identifiers are defined
according to requirement ecuc_sws_2108*/
#define DioConf_DioChannel_MCU_CAN11_RXD_CAN1RXD (DIO_CHANNEL_0_5)
#endif
/*
DIO PORT : (DioPort_1)
*/
#ifndef DioConf_DioPort_DioPort_1
#define DioConf_DioPort_DioPort_1 (DIO_PORT_1)
#endif
/*
DIO PORT : (DioPort_2)
*/
#ifndef DioConf_DioPort_DioPort_2
#define DioConf_DioPort_DioPort_2 (DIO_PORT_2)
#endif
/* DIO Channel : (DIO_DI_J3_PMIC_8200_FS0B) */
/* MISRA2012_RULE_5_1_JUSTIFICATION: External identifiers are defined
according to requirement ecuc_sws_2108*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: External identifiers are defined
according to requirement ecuc_sws_2108*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: External identifiers are defined
according to requirement ecuc_sws_2108*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: External identifiers are defined
according to requirement ecuc_sws_2108*/
#ifndef DioConf_DioChannel_DIO_DI_J3_PMIC_8200_FS0B
/* MISRA2012_RULE_5_1_JUSTIFICATION: External identifiers are defined
according to requirement ecuc_sws_2108*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: External identifiers are defined
according to requirement ecuc_sws_2108*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: External identifiers are defined
according to requirement ecuc_sws_2108*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: External identifiers are defined
according to requirement ecuc_sws_2108*/
#define DioConf_DioChannel_DIO_DI_J3_PMIC_8200_FS0B (DIO_CHANNEL_2_0)
#endif
/* DIO Channel : (DIO_DO_MCU_SPI3_CS_B) */
/* MISRA2012_RULE_5_1_JUSTIFICATION: External identifiers are defined
according to requirement ecuc_sws_2108*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: External identifiers are defined
according to requirement ecuc_sws_2108*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: External identifiers are defined
according to requirement ecuc_sws_2108*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: External identifiers are defined
according to requirement ecuc_sws_2108*/
#ifndef DioConf_DioChannel_DIO_DO_MCU_SPI3_CS_B
/* MISRA2012_RULE_5_1_JUSTIFICATION: External identifiers are defined
according to requirement ecuc_sws_2108*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: External identifiers are defined
according to requirement ecuc_sws_2108*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: External identifiers are defined
according to requirement ecuc_sws_2108*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: External identifiers are defined
according to requirement ecuc_sws_2108*/
#define DioConf_DioChannel_DIO_DO_MCU_SPI3_CS_B (DIO_CHANNEL_2_4)
#endif
/*
DIO PORT : (DioPort_10)
*/
#ifndef DioConf_DioPort_DioPort_10
#define DioConf_DioPort_DioPort_10 (DIO_PORT_10)
#endif
/* DIO Channel : (DIO_DI_B2_Sample_CAN1_EN_SPI_MISO) */
/* MISRA2012_RULE_5_1_JUSTIFICATION: External identifiers are defined
according to requirement ecuc_sws_2108*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: External identifiers are defined
according to requirement ecuc_sws_2108*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: External identifiers are defined
according to requirement ecuc_sws_2108*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: External identifiers are defined
according to requirement ecuc_sws_2108*/
#ifndef DioConf_DioChannel_DIO_DI_B2_Sample_CAN1_EN_SPI_MISO
/* MISRA2012_RULE_5_1_JUSTIFICATION: External identifiers are defined
according to requirement ecuc_sws_2108*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: External identifiers are defined
according to requirement ecuc_sws_2108*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: External identifiers are defined
according to requirement ecuc_sws_2108*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: External identifiers are defined
according to requirement ecuc_sws_2108*/
#define DioConf_DioChannel_DIO_DI_B2_Sample_CAN1_EN_SPI_MISO (DIO_CHANNEL_10_1)
#endif
/* DIO Channel : (DIO_DI_B2_Sample_CAN1_ERR_B_SPI_SCK) */
/* MISRA2012_RULE_5_1_JUSTIFICATION: External identifiers are defined
according to requirement ecuc_sws_2108*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: External identifiers are defined
according to requirement ecuc_sws_2108*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: External identifiers are defined
according to requirement ecuc_sws_2108*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: External identifiers are defined
according to requirement ecuc_sws_2108*/
#ifndef DioConf_DioChannel_DIO_DI_B2_Sample_CAN1_ERR_B_SPI_SCK
/* MISRA2012_RULE_5_1_JUSTIFICATION: External identifiers are defined
according to requirement ecuc_sws_2108*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: External identifiers are defined
according to requirement ecuc_sws_2108*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: External identifiers are defined
according to requirement ecuc_sws_2108*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: External identifiers are defined
according to requirement ecuc_sws_2108*/
#define DioConf_DioChannel_DIO_DI_B2_Sample_CAN1_ERR_B_SPI_SCK (DIO_CHANNEL_10_2)
#endif
/* DIO Channel : (DIO_DI_B2_Sample_CAN1_SPI_MOSI) */
/* MISRA2012_RULE_5_1_JUSTIFICATION: External identifiers are defined
according to requirement ecuc_sws_2108*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: External identifiers are defined
according to requirement ecuc_sws_2108*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: External identifiers are defined
according to requirement ecuc_sws_2108*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: External identifiers are defined
according to requirement ecuc_sws_2108*/
#ifndef DioConf_DioChannel_DIO_DI_B2_Sample_CAN1_SPI_MOSI
/* MISRA2012_RULE_5_1_JUSTIFICATION: External identifiers are defined
according to requirement ecuc_sws_2108*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: External identifiers are defined
according to requirement ecuc_sws_2108*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: External identifiers are defined
according to requirement ecuc_sws_2108*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: External identifiers are defined
according to requirement ecuc_sws_2108*/
#define DioConf_DioChannel_DIO_DI_B2_Sample_CAN1_SPI_MOSI (DIO_CHANNEL_10_3)
#endif
/* DIO Channel : (DIO_DI_B2_Sample_AURIX_CAN1_STB) */
/* MISRA2012_RULE_5_1_JUSTIFICATION: External identifiers are defined
according to requirement ecuc_sws_2108*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: External identifiers are defined
according to requirement ecuc_sws_2108*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: External identifiers are defined
according to requirement ecuc_sws_2108*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: External identifiers are defined
according to requirement ecuc_sws_2108*/
#ifndef DioConf_DioChannel_DIO_DI_B2_Sample_AURIX_CAN1_STB
/* MISRA2012_RULE_5_1_JUSTIFICATION: External identifiers are defined
according to requirement ecuc_sws_2108*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: External identifiers are defined
according to requirement ecuc_sws_2108*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: External identifiers are defined
according to requirement ecuc_sws_2108*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: External identifiers are defined
according to requirement ecuc_sws_2108*/
#define DioConf_DioChannel_DIO_DI_B2_Sample_AURIX_CAN1_STB (DIO_CHANNEL_10_4)
#endif
/* DIO Channel : (DIO_DI_AURIX_HWCFG4) */
/* MISRA2012_RULE_5_1_JUSTIFICATION: External identifiers are defined
according to requirement ecuc_sws_2108*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: External identifiers are defined
according to requirement ecuc_sws_2108*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: External identifiers are defined
according to requirement ecuc_sws_2108*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: External identifiers are defined
according to requirement ecuc_sws_2108*/
#ifndef DioConf_DioChannel_DIO_DI_AURIX_HWCFG4
/* MISRA2012_RULE_5_1_JUSTIFICATION: External identifiers are defined
according to requirement ecuc_sws_2108*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: External identifiers are defined
according to requirement ecuc_sws_2108*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: External identifiers are defined
according to requirement ecuc_sws_2108*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: External identifiers are defined
according to requirement ecuc_sws_2108*/
#define DioConf_DioChannel_DIO_DI_AURIX_HWCFG4 (DIO_CHANNEL_10_5)
#endif
/* DIO Channel : (DIO_DI_AURIX_HWCFG5) */
/* MISRA2012_RULE_5_1_JUSTIFICATION: External identifiers are defined
according to requirement ecuc_sws_2108*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: External identifiers are defined
according to requirement ecuc_sws_2108*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: External identifiers are defined
according to requirement ecuc_sws_2108*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: External identifiers are defined
according to requirement ecuc_sws_2108*/
#ifndef DioConf_DioChannel_DIO_DI_AURIX_HWCFG5
/* MISRA2012_RULE_5_1_JUSTIFICATION: External identifiers are defined
according to requirement ecuc_sws_2108*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: External identifiers are defined
according to requirement ecuc_sws_2108*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: External identifiers are defined
according to requirement ecuc_sws_2108*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: External identifiers are defined
according to requirement ecuc_sws_2108*/
#define DioConf_DioChannel_DIO_DI_AURIX_HWCFG5 (DIO_CHANNEL_10_6)
#endif
/* DIO Channel : (DIO_DO_MCU_P1007_J3_GPIO22_IND) */
/* MISRA2012_RULE_5_1_JUSTIFICATION: External identifiers are defined
according to requirement ecuc_sws_2108*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: External identifiers are defined
according to requirement ecuc_sws_2108*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: External identifiers are defined
according to requirement ecuc_sws_2108*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: External identifiers are defined
according to requirement ecuc_sws_2108*/
#ifndef DioConf_DioChannel_DIO_DO_MCU_P1007_J3_GPIO22_IND
/* MISRA2012_RULE_5_1_JUSTIFICATION: External identifiers are defined
according to requirement ecuc_sws_2108*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: External identifiers are defined
according to requirement ecuc_sws_2108*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: External identifiers are defined
according to requirement ecuc_sws_2108*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: External identifiers are defined
according to requirement ecuc_sws_2108*/
#define DioConf_DioChannel_DIO_DO_MCU_P1007_J3_GPIO22_IND (DIO_CHANNEL_10_7)
#endif
/* DIO Channel : (DIO_DI_MCU_P1008_J3_GPIO23_ACK) */
/* MISRA2012_RULE_5_1_JUSTIFICATION: External identifiers are defined
according to requirement ecuc_sws_2108*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: External identifiers are defined
according to requirement ecuc_sws_2108*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: External identifiers are defined
according to requirement ecuc_sws_2108*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: External identifiers are defined
according to requirement ecuc_sws_2108*/
#ifndef DioConf_DioChannel_DIO_DI_MCU_P1008_J3_GPIO23_ACK
/* MISRA2012_RULE_5_1_JUSTIFICATION: External identifiers are defined
according to requirement ecuc_sws_2108*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: External identifiers are defined
according to requirement ecuc_sws_2108*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: External identifiers are defined
according to requirement ecuc_sws_2108*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: External identifiers are defined
according to requirement ecuc_sws_2108*/
#define DioConf_DioChannel_DIO_DI_MCU_P1008_J3_GPIO23_ACK (DIO_CHANNEL_10_8)
#endif
/*
DIO PORT : (DioPort_11)
*/
#ifndef DioConf_DioPort_DioPort_11
#define DioConf_DioPort_DioPort_11 (DIO_PORT_11)
#endif
/* DIO Channel : (DIO_DO_J3_PMIC_8200_PWRON) */
/* MISRA2012_RULE_5_1_JUSTIFICATION: External identifiers are defined
according to requirement ecuc_sws_2108*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: External identifiers are defined
according to requirement ecuc_sws_2108*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: External identifiers are defined
according to requirement ecuc_sws_2108*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: External identifiers are defined
according to requirement ecuc_sws_2108*/
#ifndef DioConf_DioChannel_DIO_DO_J3_PMIC_8200_PWRON
/* MISRA2012_RULE_5_1_JUSTIFICATION: External identifiers are defined
according to requirement ecuc_sws_2108*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: External identifiers are defined
according to requirement ecuc_sws_2108*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: External identifiers are defined
according to requirement ecuc_sws_2108*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: External identifiers are defined
according to requirement ecuc_sws_2108*/
#define DioConf_DioChannel_DIO_DO_J3_PMIC_8200_PWRON (DIO_CHANNEL_11_0)
#endif
/* DIO Channel : (DIO_DO_J3_PMIC_8200_WDI) */
/* MISRA2012_RULE_5_1_JUSTIFICATION: External identifiers are defined
according to requirement ecuc_sws_2108*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: External identifiers are defined
according to requirement ecuc_sws_2108*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: External identifiers are defined
according to requirement ecuc_sws_2108*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: External identifiers are defined
according to requirement ecuc_sws_2108*/
#ifndef DioConf_DioChannel_DIO_DO_J3_PMIC_8200_WDI
/* MISRA2012_RULE_5_1_JUSTIFICATION: External identifiers are defined
according to requirement ecuc_sws_2108*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: External identifiers are defined
according to requirement ecuc_sws_2108*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: External identifiers are defined
according to requirement ecuc_sws_2108*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: External identifiers are defined
according to requirement ecuc_sws_2108*/
#define DioConf_DioChannel_DIO_DO_J3_PMIC_8200_WDI (DIO_CHANNEL_11_1)
#endif
/* DIO Channel : (DIO_DI_J3_PMIC_8200_EWARN) */
/* MISRA2012_RULE_5_1_JUSTIFICATION: External identifiers are defined
according to requirement ecuc_sws_2108*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: External identifiers are defined
according to requirement ecuc_sws_2108*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: External identifiers are defined
according to requirement ecuc_sws_2108*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: External identifiers are defined
according to requirement ecuc_sws_2108*/
#ifndef DioConf_DioChannel_DIO_DI_J3_PMIC_8200_EWARN
/* MISRA2012_RULE_5_1_JUSTIFICATION: External identifiers are defined
according to requirement ecuc_sws_2108*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: External identifiers are defined
according to requirement ecuc_sws_2108*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: External identifiers are defined
according to requirement ecuc_sws_2108*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: External identifiers are defined
according to requirement ecuc_sws_2108*/
#define DioConf_DioChannel_DIO_DI_J3_PMIC_8200_EWARN (DIO_CHANNEL_11_2)
#endif
/* DIO Channel : (DIO_DI_J3_PMIC_8200_RST_OUT) */
/* MISRA2012_RULE_5_1_JUSTIFICATION: External identifiers are defined
according to requirement ecuc_sws_2108*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: External identifiers are defined
according to requirement ecuc_sws_2108*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: External identifiers are defined
according to requirement ecuc_sws_2108*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: External identifiers are defined
according to requirement ecuc_sws_2108*/
#ifndef DioConf_DioChannel_DIO_DI_J3_PMIC_8200_RST_OUT
/* MISRA2012_RULE_5_1_JUSTIFICATION: External identifiers are defined
according to requirement ecuc_sws_2108*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: External identifiers are defined
according to requirement ecuc_sws_2108*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: External identifiers are defined
according to requirement ecuc_sws_2108*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: External identifiers are defined
according to requirement ecuc_sws_2108*/
#define DioConf_DioChannel_DIO_DI_J3_PMIC_8200_RST_OUT (DIO_CHANNEL_11_3)
#endif
/* DIO Channel : (DIO_DI_J3_PMIC_8200_INTB) */
/* MISRA2012_RULE_5_1_JUSTIFICATION: External identifiers are defined
according to requirement ecuc_sws_2108*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: External identifiers are defined
according to requirement ecuc_sws_2108*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: External identifiers are defined
according to requirement ecuc_sws_2108*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: External identifiers are defined
according to requirement ecuc_sws_2108*/
#ifndef DioConf_DioChannel_DIO_DI_J3_PMIC_8200_INTB
/* MISRA2012_RULE_5_1_JUSTIFICATION: External identifiers are defined
according to requirement ecuc_sws_2108*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: External identifiers are defined
according to requirement ecuc_sws_2108*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: External identifiers are defined
according to requirement ecuc_sws_2108*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: External identifiers are defined
according to requirement ecuc_sws_2108*/
#define DioConf_DioChannel_DIO_DI_J3_PMIC_8200_INTB (DIO_CHANNEL_11_4)
#endif
/* DIO Channel : (DIO_DO_J3_PMIC_5024_WDI) */
/* MISRA2012_RULE_5_1_JUSTIFICATION: External identifiers are defined
according to requirement ecuc_sws_2108*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: External identifiers are defined
according to requirement ecuc_sws_2108*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: External identifiers are defined
according to requirement ecuc_sws_2108*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: External identifiers are defined
according to requirement ecuc_sws_2108*/
#ifndef DioConf_DioChannel_DIO_DO_J3_PMIC_5024_WDI
/* MISRA2012_RULE_5_1_JUSTIFICATION: External identifiers are defined
according to requirement ecuc_sws_2108*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: External identifiers are defined
according to requirement ecuc_sws_2108*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: External identifiers are defined
according to requirement ecuc_sws_2108*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: External identifiers are defined
according to requirement ecuc_sws_2108*/
#define DioConf_DioChannel_DIO_DO_J3_PMIC_5024_WDI (DIO_CHANNEL_11_5)
#endif
/* DIO Channel : (DIO_DI_J3_PMIC_5024_RST_OUT) */
/* MISRA2012_RULE_5_1_JUSTIFICATION: External identifiers are defined
according to requirement ecuc_sws_2108*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: External identifiers are defined
according to requirement ecuc_sws_2108*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: External identifiers are defined
according to requirement ecuc_sws_2108*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: External identifiers are defined
according to requirement ecuc_sws_2108*/
#ifndef DioConf_DioChannel_DIO_DI_J3_PMIC_5024_RST_OUT
/* MISRA2012_RULE_5_1_JUSTIFICATION: External identifiers are defined
according to requirement ecuc_sws_2108*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: External identifiers are defined
according to requirement ecuc_sws_2108*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: External identifiers are defined
according to requirement ecuc_sws_2108*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: External identifiers are defined
according to requirement ecuc_sws_2108*/
#define DioConf_DioChannel_DIO_DI_J3_PMIC_5024_RST_OUT (DIO_CHANNEL_11_6)
#endif
/* DIO Channel : (DIO_DI_J3_PMIC_8200_PG) */
/* MISRA2012_RULE_5_1_JUSTIFICATION: External identifiers are defined
according to requirement ecuc_sws_2108*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: External identifiers are defined
according to requirement ecuc_sws_2108*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: External identifiers are defined
according to requirement ecuc_sws_2108*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: External identifiers are defined
according to requirement ecuc_sws_2108*/
#ifndef DioConf_DioChannel_DIO_DI_J3_PMIC_8200_PG
/* MISRA2012_RULE_5_1_JUSTIFICATION: External identifiers are defined
according to requirement ecuc_sws_2108*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: External identifiers are defined
according to requirement ecuc_sws_2108*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: External identifiers are defined
according to requirement ecuc_sws_2108*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: External identifiers are defined
according to requirement ecuc_sws_2108*/
#define DioConf_DioChannel_DIO_DI_J3_PMIC_8200_PG (DIO_CHANNEL_11_7)
#endif
/* DIO Channel : (DIO_DI_J3_PMIC_5024_PG) */
/* MISRA2012_RULE_5_1_JUSTIFICATION: External identifiers are defined
according to requirement ecuc_sws_2108*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: External identifiers are defined
according to requirement ecuc_sws_2108*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: External identifiers are defined
according to requirement ecuc_sws_2108*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: External identifiers are defined
according to requirement ecuc_sws_2108*/
#ifndef DioConf_DioChannel_DIO_DI_J3_PMIC_5024_PG
/* MISRA2012_RULE_5_1_JUSTIFICATION: External identifiers are defined
according to requirement ecuc_sws_2108*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: External identifiers are defined
according to requirement ecuc_sws_2108*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: External identifiers are defined
according to requirement ecuc_sws_2108*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: External identifiers are defined
according to requirement ecuc_sws_2108*/
#define DioConf_DioChannel_DIO_DI_J3_PMIC_5024_PG (DIO_CHANNEL_11_8)
#endif
/* DIO Channel : (DIO_DO_MCU_J3_RST_B) */
/* MISRA2012_RULE_5_1_JUSTIFICATION: External identifiers are defined
according to requirement ecuc_sws_2108*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: External identifiers are defined
according to requirement ecuc_sws_2108*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: External identifiers are defined
according to requirement ecuc_sws_2108*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: External identifiers are defined
according to requirement ecuc_sws_2108*/
#ifndef DioConf_DioChannel_DIO_DO_MCU_J3_RST_B
/* MISRA2012_RULE_5_1_JUSTIFICATION: External identifiers are defined
according to requirement ecuc_sws_2108*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: External identifiers are defined
according to requirement ecuc_sws_2108*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: External identifiers are defined
according to requirement ecuc_sws_2108*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: External identifiers are defined
according to requirement ecuc_sws_2108*/
#define DioConf_DioChannel_DIO_DO_MCU_J3_RST_B (DIO_CHANNEL_11_9)
#endif
/* DIO Channel : (DIO_DI_MCU_P1110_J3_GPIO24) */
/* MISRA2012_RULE_5_1_JUSTIFICATION: External identifiers are defined
according to requirement ecuc_sws_2108*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: External identifiers are defined
according to requirement ecuc_sws_2108*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: External identifiers are defined
according to requirement ecuc_sws_2108*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: External identifiers are defined
according to requirement ecuc_sws_2108*/
#ifndef DioConf_DioChannel_DIO_DI_MCU_P1110_J3_GPIO24
/* MISRA2012_RULE_5_1_JUSTIFICATION: External identifiers are defined
according to requirement ecuc_sws_2108*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: External identifiers are defined
according to requirement ecuc_sws_2108*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: External identifiers are defined
according to requirement ecuc_sws_2108*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: External identifiers are defined
according to requirement ecuc_sws_2108*/
#define DioConf_DioChannel_DIO_DI_MCU_P1110_J3_GPIO24 (DIO_CHANNEL_11_10)
#endif
/* DIO Channel : (DIO_DI_PMIC_FS84_PG) */
/* MISRA2012_RULE_5_1_JUSTIFICATION: External identifiers are defined
according to requirement ecuc_sws_2108*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: External identifiers are defined
according to requirement ecuc_sws_2108*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: External identifiers are defined
according to requirement ecuc_sws_2108*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: External identifiers are defined
according to requirement ecuc_sws_2108*/
#ifndef DioConf_DioChannel_DIO_DI_PMIC_FS84_PG
/* MISRA2012_RULE_5_1_JUSTIFICATION: External identifiers are defined
according to requirement ecuc_sws_2108*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: External identifiers are defined
according to requirement ecuc_sws_2108*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: External identifiers are defined
according to requirement ecuc_sws_2108*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: External identifiers are defined
according to requirement ecuc_sws_2108*/
#define DioConf_DioChannel_DIO_DI_PMIC_FS84_PG (DIO_CHANNEL_11_11)
#endif
/* DIO Channel : (DIO_DI_B2_Sample_J3_PMIC_5024_PG1) */
/* MISRA2012_RULE_5_1_JUSTIFICATION: External identifiers are defined
according to requirement ecuc_sws_2108*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: External identifiers are defined
according to requirement ecuc_sws_2108*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: External identifiers are defined
according to requirement ecuc_sws_2108*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: External identifiers are defined
according to requirement ecuc_sws_2108*/
#ifndef DioConf_DioChannel_DIO_DI_B2_Sample_J3_PMIC_5024_PG1
/* MISRA2012_RULE_5_1_JUSTIFICATION: External identifiers are defined
according to requirement ecuc_sws_2108*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: External identifiers are defined
according to requirement ecuc_sws_2108*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: External identifiers are defined
according to requirement ecuc_sws_2108*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: External identifiers are defined
according to requirement ecuc_sws_2108*/
#define DioConf_DioChannel_DIO_DI_B2_Sample_J3_PMIC_5024_PG1 (DIO_CHANNEL_11_13)
#endif
/* DIO Channel : (DIO_DI_B2_Sample_J3_PMIC_5024_PG3) */
/* MISRA2012_RULE_5_1_JUSTIFICATION: External identifiers are defined
according to requirement ecuc_sws_2108*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: External identifiers are defined
according to requirement ecuc_sws_2108*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: External identifiers are defined
according to requirement ecuc_sws_2108*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: External identifiers are defined
according to requirement ecuc_sws_2108*/
#ifndef DioConf_DioChannel_DIO_DI_B2_Sample_J3_PMIC_5024_PG3
/* MISRA2012_RULE_5_1_JUSTIFICATION: External identifiers are defined
according to requirement ecuc_sws_2108*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: External identifiers are defined
according to requirement ecuc_sws_2108*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: External identifiers are defined
according to requirement ecuc_sws_2108*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: External identifiers are defined
according to requirement ecuc_sws_2108*/
#define DioConf_DioChannel_DIO_DI_B2_Sample_J3_PMIC_5024_PG3 (DIO_CHANNEL_11_15)
#endif
/*
DIO PORT : (DioPort_12)
*/
#ifndef DioConf_DioPort_DioPort_12
#define DioConf_DioPort_DioPort_12 (DIO_PORT_12)
#endif
/*
DIO PORT : (DioPort_13)
*/
#ifndef DioConf_DioPort_DioPort_13
#define DioConf_DioPort_DioPort_13 (DIO_PORT_13)
#endif
/*
DIO PORT : (DioPort_14)
*/
#ifndef DioConf_DioPort_DioPort_14
#define DioConf_DioPort_DioPort_14 (DIO_PORT_14)
#endif
/* DIO Channel : (DIO_DO_MCU_P1401_J3_GPIO25) */
/* MISRA2012_RULE_5_1_JUSTIFICATION: External identifiers are defined
according to requirement ecuc_sws_2108*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: External identifiers are defined
according to requirement ecuc_sws_2108*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: External identifiers are defined
according to requirement ecuc_sws_2108*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: External identifiers are defined
according to requirement ecuc_sws_2108*/
#ifndef DioConf_DioChannel_DIO_DO_MCU_P1401_J3_GPIO25
/* MISRA2012_RULE_5_1_JUSTIFICATION: External identifiers are defined
according to requirement ecuc_sws_2108*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: External identifiers are defined
according to requirement ecuc_sws_2108*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: External identifiers are defined
according to requirement ecuc_sws_2108*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: External identifiers are defined
according to requirement ecuc_sws_2108*/
#define DioConf_DioChannel_DIO_DO_MCU_P1401_J3_GPIO25 (DIO_CHANNEL_14_1)
#endif
/* DIO Channel : (DIO_DI_MCU_HWCFG2) */
/* MISRA2012_RULE_5_1_JUSTIFICATION: External identifiers are defined
according to requirement ecuc_sws_2108*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: External identifiers are defined
according to requirement ecuc_sws_2108*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: External identifiers are defined
according to requirement ecuc_sws_2108*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: External identifiers are defined
according to requirement ecuc_sws_2108*/
#ifndef DioConf_DioChannel_DIO_DI_MCU_HWCFG2
/* MISRA2012_RULE_5_1_JUSTIFICATION: External identifiers are defined
according to requirement ecuc_sws_2108*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: External identifiers are defined
according to requirement ecuc_sws_2108*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: External identifiers are defined
according to requirement ecuc_sws_2108*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: External identifiers are defined
according to requirement ecuc_sws_2108*/
#define DioConf_DioChannel_DIO_DI_MCU_HWCFG2 (DIO_CHANNEL_14_2)
#endif
/* DIO Channel : (DIO_DI_MCU_HWCFG3) */
/* MISRA2012_RULE_5_1_JUSTIFICATION: External identifiers are defined
according to requirement ecuc_sws_2108*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: External identifiers are defined
according to requirement ecuc_sws_2108*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: External identifiers are defined
according to requirement ecuc_sws_2108*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: External identifiers are defined
according to requirement ecuc_sws_2108*/
#ifndef DioConf_DioChannel_DIO_DI_MCU_HWCFG3
/* MISRA2012_RULE_5_1_JUSTIFICATION: External identifiers are defined
according to requirement ecuc_sws_2108*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: External identifiers are defined
according to requirement ecuc_sws_2108*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: External identifiers are defined
according to requirement ecuc_sws_2108*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: External identifiers are defined
according to requirement ecuc_sws_2108*/
#define DioConf_DioChannel_DIO_DI_MCU_HWCFG3 (DIO_CHANNEL_14_3)
#endif
/* DIO Channel : (DIO_DI_MCU_HWCFG6) */
/* MISRA2012_RULE_5_1_JUSTIFICATION: External identifiers are defined
according to requirement ecuc_sws_2108*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: External identifiers are defined
according to requirement ecuc_sws_2108*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: External identifiers are defined
according to requirement ecuc_sws_2108*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: External identifiers are defined
according to requirement ecuc_sws_2108*/
#ifndef DioConf_DioChannel_DIO_DI_MCU_HWCFG6
/* MISRA2012_RULE_5_1_JUSTIFICATION: External identifiers are defined
according to requirement ecuc_sws_2108*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: External identifiers are defined
according to requirement ecuc_sws_2108*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: External identifiers are defined
according to requirement ecuc_sws_2108*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: External identifiers are defined
according to requirement ecuc_sws_2108*/
#define DioConf_DioChannel_DIO_DI_MCU_HWCFG6 (DIO_CHANNEL_14_4)
#endif
/* DIO Channel : (DIO_DI_MCU_HWCFG1) */
/* MISRA2012_RULE_5_1_JUSTIFICATION: External identifiers are defined
according to requirement ecuc_sws_2108*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: External identifiers are defined
according to requirement ecuc_sws_2108*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: External identifiers are defined
according to requirement ecuc_sws_2108*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: External identifiers are defined
according to requirement ecuc_sws_2108*/
#ifndef DioConf_DioChannel_DIO_DI_MCU_HWCFG1
/* MISRA2012_RULE_5_1_JUSTIFICATION: External identifiers are defined
according to requirement ecuc_sws_2108*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: External identifiers are defined
according to requirement ecuc_sws_2108*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: External identifiers are defined
according to requirement ecuc_sws_2108*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: External identifiers are defined
according to requirement ecuc_sws_2108*/
#define DioConf_DioChannel_DIO_DI_MCU_HWCFG1 (DIO_CHANNEL_14_5)
#endif
/*
DIO PORT : (DioPort_15)
*/
#ifndef DioConf_DioPort_DioPort_15
#define DioConf_DioPort_DioPort_15 (DIO_PORT_15)
#endif
/* DIO Channel : (DIO_DI_MCU_P1501_J3_GPIO116) */
/* MISRA2012_RULE_5_1_JUSTIFICATION: External identifiers are defined
according to requirement ecuc_sws_2108*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: External identifiers are defined
according to requirement ecuc_sws_2108*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: External identifiers are defined
according to requirement ecuc_sws_2108*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: External identifiers are defined
according to requirement ecuc_sws_2108*/
#ifndef DioConf_DioChannel_DIO_DI_MCU_P1501_J3_GPIO116
/* MISRA2012_RULE_5_1_JUSTIFICATION: External identifiers are defined
according to requirement ecuc_sws_2108*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: External identifiers are defined
according to requirement ecuc_sws_2108*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: External identifiers are defined
according to requirement ecuc_sws_2108*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: External identifiers are defined
according to requirement ecuc_sws_2108*/
#define DioConf_DioChannel_DIO_DI_MCU_P1501_J3_GPIO116 (DIO_CHANNEL_15_1)
#endif
/* DIO Channel : (DIO_DI_MCU_P1507_J3_GPIO118) */
/* MISRA2012_RULE_5_1_JUSTIFICATION: External identifiers are defined
according to requirement ecuc_sws_2108*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: External identifiers are defined
according to requirement ecuc_sws_2108*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: External identifiers are defined
according to requirement ecuc_sws_2108*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: External identifiers are defined
according to requirement ecuc_sws_2108*/
#ifndef DioConf_DioChannel_DIO_DI_MCU_P1507_J3_GPIO118
/* MISRA2012_RULE_5_1_JUSTIFICATION: External identifiers are defined
according to requirement ecuc_sws_2108*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: External identifiers are defined
according to requirement ecuc_sws_2108*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: External identifiers are defined
according to requirement ecuc_sws_2108*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: External identifiers are defined
according to requirement ecuc_sws_2108*/
#define DioConf_DioChannel_DIO_DI_MCU_P1507_J3_GPIO118 (DIO_CHANNEL_15_7)
#endif
/* DIO Channel : (DIO_DO_MCU_P1508_J3_GPIO117) */
/* MISRA2012_RULE_5_1_JUSTIFICATION: External identifiers are defined
according to requirement ecuc_sws_2108*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: External identifiers are defined
according to requirement ecuc_sws_2108*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: External identifiers are defined
according to requirement ecuc_sws_2108*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: External identifiers are defined
according to requirement ecuc_sws_2108*/
#ifndef DioConf_DioChannel_DIO_DO_MCU_P1508_J3_GPIO117
/* MISRA2012_RULE_5_1_JUSTIFICATION: External identifiers are defined
according to requirement ecuc_sws_2108*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: External identifiers are defined
according to requirement ecuc_sws_2108*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: External identifiers are defined
according to requirement ecuc_sws_2108*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: External identifiers are defined
according to requirement ecuc_sws_2108*/
#define DioConf_DioChannel_DIO_DO_MCU_P1508_J3_GPIO117 (DIO_CHANNEL_15_8)
#endif
/*
DIO PORT : (DioPort_20)
*/
#ifndef DioConf_DioPort_DioPort_20
#define DioConf_DioPort_DioPort_20 (DIO_PORT_20)
#endif
/* DIO Channel : (DIO_DI_OM_PWR_PG_2V9) */
/* MISRA2012_RULE_5_1_JUSTIFICATION: External identifiers are defined
according to requirement ecuc_sws_2108*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: External identifiers are defined
according to requirement ecuc_sws_2108*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: External identifiers are defined
according to requirement ecuc_sws_2108*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: External identifiers are defined
according to requirement ecuc_sws_2108*/
#ifndef DioConf_DioChannel_DIO_DI_OM_PWR_PG_2V9
/* MISRA2012_RULE_5_1_JUSTIFICATION: External identifiers are defined
according to requirement ecuc_sws_2108*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: External identifiers are defined
according to requirement ecuc_sws_2108*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: External identifiers are defined
according to requirement ecuc_sws_2108*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: External identifiers are defined
according to requirement ecuc_sws_2108*/
#define DioConf_DioChannel_DIO_DI_OM_PWR_PG_2V9 (DIO_CHANNEL_20_1)
#endif
/* DIO Channel : (DIO_DI_MCU_TESTMODE_B) */
/* MISRA2012_RULE_5_1_JUSTIFICATION: External identifiers are defined
according to requirement ecuc_sws_2108*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: External identifiers are defined
according to requirement ecuc_sws_2108*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: External identifiers are defined
according to requirement ecuc_sws_2108*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: External identifiers are defined
according to requirement ecuc_sws_2108*/
#ifndef DioConf_DioChannel_DIO_DI_MCU_TESTMODE_B
/* MISRA2012_RULE_5_1_JUSTIFICATION: External identifiers are defined
according to requirement ecuc_sws_2108*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: External identifiers are defined
according to requirement ecuc_sws_2108*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: External identifiers are defined
according to requirement ecuc_sws_2108*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: External identifiers are defined
according to requirement ecuc_sws_2108*/
#define DioConf_DioChannel_DIO_DI_MCU_TESTMODE_B (DIO_CHANNEL_20_2)
#endif
/* DIO Channel : (DIO_DO_MCU_HEATER_EN) */
/* MISRA2012_RULE_5_1_JUSTIFICATION: External identifiers are defined
according to requirement ecuc_sws_2108*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: External identifiers are defined
according to requirement ecuc_sws_2108*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: External identifiers are defined
according to requirement ecuc_sws_2108*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: External identifiers are defined
according to requirement ecuc_sws_2108*/
#ifndef DioConf_DioChannel_DIO_DO_MCU_HEATER_EN
/* MISRA2012_RULE_5_1_JUSTIFICATION: External identifiers are defined
according to requirement ecuc_sws_2108*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: External identifiers are defined
according to requirement ecuc_sws_2108*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: External identifiers are defined
according to requirement ecuc_sws_2108*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: External identifiers are defined
according to requirement ecuc_sws_2108*/
#define DioConf_DioChannel_DIO_DO_MCU_HEATER_EN (DIO_CHANNEL_20_6)
#endif
/* DIO Channel : (DIO_DO_PWR_EN_2V9_OM) */
/* MISRA2012_RULE_5_1_JUSTIFICATION: External identifiers are defined
according to requirement ecuc_sws_2108*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: External identifiers are defined
according to requirement ecuc_sws_2108*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: External identifiers are defined
according to requirement ecuc_sws_2108*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: External identifiers are defined
according to requirement ecuc_sws_2108*/
#ifndef DioConf_DioChannel_DIO_DO_PWR_EN_2V9_OM
/* MISRA2012_RULE_5_1_JUSTIFICATION: External identifiers are defined
according to requirement ecuc_sws_2108*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: External identifiers are defined
according to requirement ecuc_sws_2108*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: External identifiers are defined
according to requirement ecuc_sws_2108*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: External identifiers are defined
according to requirement ecuc_sws_2108*/
#define DioConf_DioChannel_DIO_DO_PWR_EN_2V9_OM (DIO_CHANNEL_20_7)
#endif
/* DIO Channel : (DIO_DO_PWR_EN_1V0_GEPHY) */
/* MISRA2012_RULE_5_1_JUSTIFICATION: External identifiers are defined
according to requirement ecuc_sws_2108*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: External identifiers are defined
according to requirement ecuc_sws_2108*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: External identifiers are defined
according to requirement ecuc_sws_2108*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: External identifiers are defined
according to requirement ecuc_sws_2108*/
#ifndef DioConf_DioChannel_DIO_DO_PWR_EN_1V0_GEPHY
/* MISRA2012_RULE_5_1_JUSTIFICATION: External identifiers are defined
according to requirement ecuc_sws_2108*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: External identifiers are defined
according to requirement ecuc_sws_2108*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: External identifiers are defined
according to requirement ecuc_sws_2108*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: External identifiers are defined
according to requirement ecuc_sws_2108*/
#define DioConf_DioChannel_DIO_DO_PWR_EN_1V0_GEPHY (DIO_CHANNEL_20_8)
#endif
/* DIO Channel : (DIO_DI_MCU_P2009_J3_GPIO119) */
/* MISRA2012_RULE_5_1_JUSTIFICATION: External identifiers are defined
according to requirement ecuc_sws_2108*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: External identifiers are defined
according to requirement ecuc_sws_2108*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: External identifiers are defined
according to requirement ecuc_sws_2108*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: External identifiers are defined
according to requirement ecuc_sws_2108*/
#ifndef DioConf_DioChannel_DIO_DI_MCU_P2009_J3_GPIO119
/* MISRA2012_RULE_5_1_JUSTIFICATION: External identifiers are defined
according to requirement ecuc_sws_2108*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: External identifiers are defined
according to requirement ecuc_sws_2108*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: External identifiers are defined
according to requirement ecuc_sws_2108*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: External identifiers are defined
according to requirement ecuc_sws_2108*/
#define DioConf_DioChannel_DIO_DI_MCU_P2009_J3_GPIO119 (DIO_CHANNEL_20_9)
#endif
/* DIO Channel : (DIO_DI_B2_Sample_CAN0_ERR_B) */
/* MISRA2012_RULE_5_1_JUSTIFICATION: External identifiers are defined
according to requirement ecuc_sws_2108*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: External identifiers are defined
according to requirement ecuc_sws_2108*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: External identifiers are defined
according to requirement ecuc_sws_2108*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: External identifiers are defined
according to requirement ecuc_sws_2108*/
#ifndef DioConf_DioChannel_DIO_DI_B2_Sample_CAN0_ERR_B
/* MISRA2012_RULE_5_1_JUSTIFICATION: External identifiers are defined
according to requirement ecuc_sws_2108*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: External identifiers are defined
according to requirement ecuc_sws_2108*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: External identifiers are defined
according to requirement ecuc_sws_2108*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: External identifiers are defined
according to requirement ecuc_sws_2108*/
#define DioConf_DioChannel_DIO_DI_B2_Sample_CAN0_ERR_B (DIO_CHANNEL_20_11)
#endif
/* DIO Channel : (DIO_DO_B2_Sample_AURIX_CAN0_EN) */
/* MISRA2012_RULE_5_1_JUSTIFICATION: External identifiers are defined
according to requirement ecuc_sws_2108*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: External identifiers are defined
according to requirement ecuc_sws_2108*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: External identifiers are defined
according to requirement ecuc_sws_2108*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: External identifiers are defined
according to requirement ecuc_sws_2108*/
#ifndef DioConf_DioChannel_DIO_DO_B2_Sample_AURIX_CAN0_EN
/* MISRA2012_RULE_5_1_JUSTIFICATION: External identifiers are defined
according to requirement ecuc_sws_2108*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: External identifiers are defined
according to requirement ecuc_sws_2108*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: External identifiers are defined
according to requirement ecuc_sws_2108*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: External identifiers are defined
according to requirement ecuc_sws_2108*/
#define DioConf_DioChannel_DIO_DO_B2_Sample_AURIX_CAN0_EN (DIO_CHANNEL_20_12)
#endif
/* DIO Channel : (DIO_DO_B2_Sample_AURIX_CAN0_STB_B) */
/* MISRA2012_RULE_5_1_JUSTIFICATION: External identifiers are defined
according to requirement ecuc_sws_2108*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: External identifiers are defined
according to requirement ecuc_sws_2108*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: External identifiers are defined
according to requirement ecuc_sws_2108*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: External identifiers are defined
according to requirement ecuc_sws_2108*/
#ifndef DioConf_DioChannel_DIO_DO_B2_Sample_AURIX_CAN0_STB_B
/* MISRA2012_RULE_5_1_JUSTIFICATION: External identifiers are defined
according to requirement ecuc_sws_2108*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: External identifiers are defined
according to requirement ecuc_sws_2108*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: External identifiers are defined
according to requirement ecuc_sws_2108*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: External identifiers are defined
according to requirement ecuc_sws_2108*/
#define DioConf_DioChannel_DIO_DO_B2_Sample_AURIX_CAN0_STB_B (DIO_CHANNEL_20_13)
#endif
/*
DIO PORT : (DioPort_21)
*/
#ifndef DioConf_DioPort_DioPort_21
#define DioConf_DioPort_DioPort_21 (DIO_PORT_21)
#endif
/* DIO Channel : (DIO_DI_MCU_HSCT0_RXDN) */
/* MISRA2012_RULE_5_1_JUSTIFICATION: External identifiers are defined
according to requirement ecuc_sws_2108*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: External identifiers are defined
according to requirement ecuc_sws_2108*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: External identifiers are defined
according to requirement ecuc_sws_2108*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: External identifiers are defined
according to requirement ecuc_sws_2108*/
#ifndef DioConf_DioChannel_DIO_DI_MCU_HSCT0_RXDN
/* MISRA2012_RULE_5_1_JUSTIFICATION: External identifiers are defined
according to requirement ecuc_sws_2108*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: External identifiers are defined
according to requirement ecuc_sws_2108*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: External identifiers are defined
according to requirement ecuc_sws_2108*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: External identifiers are defined
according to requirement ecuc_sws_2108*/
#define DioConf_DioChannel_DIO_DI_MCU_HSCT0_RXDN (DIO_CHANNEL_21_2)
#endif
/* DIO Channel : (DIO_DI_MCU_HSCT0_RXDP) */
/* MISRA2012_RULE_5_1_JUSTIFICATION: External identifiers are defined
according to requirement ecuc_sws_2108*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: External identifiers are defined
according to requirement ecuc_sws_2108*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: External identifiers are defined
according to requirement ecuc_sws_2108*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: External identifiers are defined
according to requirement ecuc_sws_2108*/
#ifndef DioConf_DioChannel_DIO_DI_MCU_HSCT0_RXDP
/* MISRA2012_RULE_5_1_JUSTIFICATION: External identifiers are defined
according to requirement ecuc_sws_2108*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: External identifiers are defined
according to requirement ecuc_sws_2108*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: External identifiers are defined
according to requirement ecuc_sws_2108*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: External identifiers are defined
according to requirement ecuc_sws_2108*/
#define DioConf_DioChannel_DIO_DI_MCU_HSCT0_RXDP (DIO_CHANNEL_21_3)
#endif
/* DIO Channel : (DIO_DO_MCU_HSCT0_TXDN) */
/* MISRA2012_RULE_5_1_JUSTIFICATION: External identifiers are defined
according to requirement ecuc_sws_2108*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: External identifiers are defined
according to requirement ecuc_sws_2108*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: External identifiers are defined
according to requirement ecuc_sws_2108*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: External identifiers are defined
according to requirement ecuc_sws_2108*/
#ifndef DioConf_DioChannel_DIO_DO_MCU_HSCT0_TXDN
/* MISRA2012_RULE_5_1_JUSTIFICATION: External identifiers are defined
according to requirement ecuc_sws_2108*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: External identifiers are defined
according to requirement ecuc_sws_2108*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: External identifiers are defined
according to requirement ecuc_sws_2108*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: External identifiers are defined
according to requirement ecuc_sws_2108*/
#define DioConf_DioChannel_DIO_DO_MCU_HSCT0_TXDN (DIO_CHANNEL_21_4)
#endif
/* DIO Channel : (DIO_DO_MCU_HSCT0_TXDP) */
/* MISRA2012_RULE_5_1_JUSTIFICATION: External identifiers are defined
according to requirement ecuc_sws_2108*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: External identifiers are defined
according to requirement ecuc_sws_2108*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: External identifiers are defined
according to requirement ecuc_sws_2108*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: External identifiers are defined
according to requirement ecuc_sws_2108*/
#ifndef DioConf_DioChannel_DIO_DO_MCU_HSCT0_TXDP
/* MISRA2012_RULE_5_1_JUSTIFICATION: External identifiers are defined
according to requirement ecuc_sws_2108*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: External identifiers are defined
according to requirement ecuc_sws_2108*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: External identifiers are defined
according to requirement ecuc_sws_2108*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: External identifiers are defined
according to requirement ecuc_sws_2108*/
#define DioConf_DioChannel_DIO_DO_MCU_HSCT0_TXDP (DIO_CHANNEL_21_5)
#endif
/*
DIO PORT : (DioPort_22)
*/
#ifndef DioConf_DioPort_DioPort_22
#define DioConf_DioPort_DioPort_22 (DIO_PORT_22)
#endif
/*
DIO PORT : (DioPort_23)
*/
#ifndef DioConf_DioPort_DioPort_23
#define DioConf_DioPort_DioPort_23 (DIO_PORT_23)
#endif
/* DIO Channel : (DIO_DO_MCU_J3_BOOT_SEL1) */
/* MISRA2012_RULE_5_1_JUSTIFICATION: External identifiers are defined
according to requirement ecuc_sws_2108*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: External identifiers are defined
according to requirement ecuc_sws_2108*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: External identifiers are defined
according to requirement ecuc_sws_2108*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: External identifiers are defined
according to requirement ecuc_sws_2108*/
#ifndef DioConf_DioChannel_DIO_DO_MCU_J3_BOOT_SEL1
/* MISRA2012_RULE_5_1_JUSTIFICATION: External identifiers are defined
according to requirement ecuc_sws_2108*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: External identifiers are defined
according to requirement ecuc_sws_2108*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: External identifiers are defined
according to requirement ecuc_sws_2108*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: External identifiers are defined
according to requirement ecuc_sws_2108*/
#define DioConf_DioChannel_DIO_DO_MCU_J3_BOOT_SEL1 (DIO_CHANNEL_23_0)
#endif
/* DIO Channel : (DIO_DO_MCU_J3_BOOT_SEL2) */
/* MISRA2012_RULE_5_1_JUSTIFICATION: External identifiers are defined
according to requirement ecuc_sws_2108*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: External identifiers are defined
according to requirement ecuc_sws_2108*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: External identifiers are defined
according to requirement ecuc_sws_2108*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: External identifiers are defined
according to requirement ecuc_sws_2108*/
#ifndef DioConf_DioChannel_DIO_DO_MCU_J3_BOOT_SEL2
/* MISRA2012_RULE_5_1_JUSTIFICATION: External identifiers are defined
according to requirement ecuc_sws_2108*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: External identifiers are defined
according to requirement ecuc_sws_2108*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: External identifiers are defined
according to requirement ecuc_sws_2108*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: External identifiers are defined
according to requirement ecuc_sws_2108*/
#define DioConf_DioChannel_DIO_DO_MCU_J3_BOOT_SEL2 (DIO_CHANNEL_23_1)
#endif
/* DIO Channel : (DIO_DO_MCU_J3_BOOT_SEL3) */
/* MISRA2012_RULE_5_1_JUSTIFICATION: External identifiers are defined
according to requirement ecuc_sws_2108*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: External identifiers are defined
according to requirement ecuc_sws_2108*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: External identifiers are defined
according to requirement ecuc_sws_2108*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: External identifiers are defined
according to requirement ecuc_sws_2108*/
#ifndef DioConf_DioChannel_DIO_DO_MCU_J3_BOOT_SEL3
/* MISRA2012_RULE_5_1_JUSTIFICATION: External identifiers are defined
according to requirement ecuc_sws_2108*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: External identifiers are defined
according to requirement ecuc_sws_2108*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: External identifiers are defined
according to requirement ecuc_sws_2108*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: External identifiers are defined
according to requirement ecuc_sws_2108*/
#define DioConf_DioChannel_DIO_DO_MCU_J3_BOOT_SEL3 (DIO_CHANNEL_23_2)
#endif
/* DIO Channel : (DIO_DO_MCU_OM_SYNC) */
/* MISRA2012_RULE_5_1_JUSTIFICATION: External identifiers are defined
according to requirement ecuc_sws_2108*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: External identifiers are defined
according to requirement ecuc_sws_2108*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: External identifiers are defined
according to requirement ecuc_sws_2108*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: External identifiers are defined
according to requirement ecuc_sws_2108*/
#ifndef DioConf_DioChannel_DIO_DO_MCU_OM_SYNC
/* MISRA2012_RULE_5_1_JUSTIFICATION: External identifiers are defined
according to requirement ecuc_sws_2108*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: External identifiers are defined
according to requirement ecuc_sws_2108*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: External identifiers are defined
according to requirement ecuc_sws_2108*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: External identifiers are defined
according to requirement ecuc_sws_2108*/
#define DioConf_DioChannel_DIO_DO_MCU_OM_SYNC (DIO_CHANNEL_23_7)
#endif
/*
DIO PORT : (DioPort_32)
*/
#ifndef DioConf_DioPort_DioPort_32
#define DioConf_DioPort_DioPort_32 (DIO_PORT_32)
#endif
/*
DIO PORT : (DioPort_33)
*/
#ifndef DioConf_DioPort_DioPort_33
#define DioConf_DioPort_DioPort_33 (DIO_PORT_33)
#endif
/* DIO Channel : (DIO_DO_J3_PMIC_STANDBY) */
/* MISRA2012_RULE_5_1_JUSTIFICATION: External identifiers are defined
according to requirement ecuc_sws_2108*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: External identifiers are defined
according to requirement ecuc_sws_2108*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: External identifiers are defined
according to requirement ecuc_sws_2108*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: External identifiers are defined
according to requirement ecuc_sws_2108*/
#ifndef DioConf_DioChannel_DIO_DO_J3_PMIC_STANDBY
/* MISRA2012_RULE_5_1_JUSTIFICATION: External identifiers are defined
according to requirement ecuc_sws_2108*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: External identifiers are defined
according to requirement ecuc_sws_2108*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: External identifiers are defined
according to requirement ecuc_sws_2108*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: External identifiers are defined
according to requirement ecuc_sws_2108*/
#define DioConf_DioChannel_DIO_DO_J3_PMIC_STANDBY (DIO_CHANNEL_33_0)
#endif
/* DIO Channel : (DIO_DO_SYS_OFF_B) */
/* MISRA2012_RULE_5_1_JUSTIFICATION: External identifiers are defined
according to requirement ecuc_sws_2108*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: External identifiers are defined
according to requirement ecuc_sws_2108*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: External identifiers are defined
according to requirement ecuc_sws_2108*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: External identifiers are defined
according to requirement ecuc_sws_2108*/
#ifndef DioConf_DioChannel_DIO_DO_SYS_OFF_B
/* MISRA2012_RULE_5_1_JUSTIFICATION: External identifiers are defined
according to requirement ecuc_sws_2108*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: External identifiers are defined
according to requirement ecuc_sws_2108*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: External identifiers are defined
according to requirement ecuc_sws_2108*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: External identifiers are defined
according to requirement ecuc_sws_2108*/
#define DioConf_DioChannel_DIO_DO_SYS_OFF_B (DIO_CHANNEL_33_5)
#endif
/* DIO Channel : (DIO_DO_MCU_ERR1) */
/* MISRA2012_RULE_5_1_JUSTIFICATION: External identifiers are defined
according to requirement ecuc_sws_2108*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: External identifiers are defined
according to requirement ecuc_sws_2108*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: External identifiers are defined
according to requirement ecuc_sws_2108*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: External identifiers are defined
according to requirement ecuc_sws_2108*/
#ifndef DioConf_DioChannel_DIO_DO_MCU_ERR1
/* MISRA2012_RULE_5_1_JUSTIFICATION: External identifiers are defined
according to requirement ecuc_sws_2108*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: External identifiers are defined
according to requirement ecuc_sws_2108*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: External identifiers are defined
according to requirement ecuc_sws_2108*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: External identifiers are defined
according to requirement ecuc_sws_2108*/
#define DioConf_DioChannel_DIO_DO_MCU_ERR1 (DIO_CHANNEL_33_8)
#endif
/* DIO Channel : (DIO_DI_PMIC_FS84_FS0_B) */
/* MISRA2012_RULE_5_1_JUSTIFICATION: External identifiers are defined
according to requirement ecuc_sws_2108*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: External identifiers are defined
according to requirement ecuc_sws_2108*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: External identifiers are defined
according to requirement ecuc_sws_2108*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: External identifiers are defined
according to requirement ecuc_sws_2108*/
#ifndef DioConf_DioChannel_DIO_DI_PMIC_FS84_FS0_B
/* MISRA2012_RULE_5_1_JUSTIFICATION: External identifiers are defined
according to requirement ecuc_sws_2108*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: External identifiers are defined
according to requirement ecuc_sws_2108*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: External identifiers are defined
according to requirement ecuc_sws_2108*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: External identifiers are defined
according to requirement ecuc_sws_2108*/
#define DioConf_DioChannel_DIO_DI_PMIC_FS84_FS0_B (DIO_CHANNEL_33_11)
#endif
/*
DIO PORT : (DioPort_34)
*/
#ifndef DioConf_DioPort_DioPort_34
#define DioConf_DioPort_DioPort_34 (DIO_PORT_34)
#endif
/* DIO Channel : (DIO_DO_AURIX_J3B_SPI2_INT) */
/* MISRA2012_RULE_5_1_JUSTIFICATION: External identifiers are defined
according to requirement ecuc_sws_2108*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: External identifiers are defined
according to requirement ecuc_sws_2108*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: External identifiers are defined
according to requirement ecuc_sws_2108*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: External identifiers are defined
according to requirement ecuc_sws_2108*/
#ifndef DioConf_DioChannel_DIO_DO_AURIX_J3B_SPI2_INT
/* MISRA2012_RULE_5_1_JUSTIFICATION: External identifiers are defined
according to requirement ecuc_sws_2108*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: External identifiers are defined
according to requirement ecuc_sws_2108*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: External identifiers are defined
according to requirement ecuc_sws_2108*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: External identifiers are defined
according to requirement ecuc_sws_2108*/
#define DioConf_DioChannel_DIO_DO_AURIX_J3B_SPI2_INT (DIO_CHANNEL_34_3)
#endif
/*
DIO PORT : (DioPort_40)
*/
#ifndef DioConf_DioPort_DioPort_40
#define DioConf_DioPort_DioPort_40 (DIO_PORT_40)
#endif
/* DIO Channel : (DIO_20028_AURIX_RESET1_5V) */
/* MISRA2012_RULE_5_1_JUSTIFICATION: External identifiers are defined
according to requirement ecuc_sws_2108*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: External identifiers are defined
according to requirement ecuc_sws_2108*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: External identifiers are defined
according to requirement ecuc_sws_2108*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: External identifiers are defined
according to requirement ecuc_sws_2108*/
#ifndef DioConf_DioChannel_DIO_20028_AURIX_RESET1_5V
/* MISRA2012_RULE_5_1_JUSTIFICATION: External identifiers are defined
according to requirement ecuc_sws_2108*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: External identifiers are defined
according to requirement ecuc_sws_2108*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: External identifiers are defined
according to requirement ecuc_sws_2108*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: External identifiers are defined
according to requirement ecuc_sws_2108*/
#define DioConf_DioChannel_DIO_20028_AURIX_RESET1_5V (DIO_CHANNEL_40_0)
#endif
/* DIO Channel : (DIO_20028_AURIX_RESET2_1V0) */
/* MISRA2012_RULE_5_1_JUSTIFICATION: External identifiers are defined
according to requirement ecuc_sws_2108*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: External identifiers are defined
according to requirement ecuc_sws_2108*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: External identifiers are defined
according to requirement ecuc_sws_2108*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: External identifiers are defined
according to requirement ecuc_sws_2108*/
#ifndef DioConf_DioChannel_DIO_20028_AURIX_RESET2_1V0
/* MISRA2012_RULE_5_1_JUSTIFICATION: External identifiers are defined
according to requirement ecuc_sws_2108*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: External identifiers are defined
according to requirement ecuc_sws_2108*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: External identifiers are defined
according to requirement ecuc_sws_2108*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: External identifiers are defined
according to requirement ecuc_sws_2108*/
#define DioConf_DioChannel_DIO_20028_AURIX_RESET2_1V0 (DIO_CHANNEL_40_1)
#endif
/* DIO Channel : (DIO_20028_AURIX_RESET3_1V2) */
/* MISRA2012_RULE_5_1_JUSTIFICATION: External identifiers are defined
according to requirement ecuc_sws_2108*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: External identifiers are defined
according to requirement ecuc_sws_2108*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: External identifiers are defined
according to requirement ecuc_sws_2108*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: External identifiers are defined
according to requirement ecuc_sws_2108*/
#ifndef DioConf_DioChannel_DIO_20028_AURIX_RESET3_1V2
/* MISRA2012_RULE_5_1_JUSTIFICATION: External identifiers are defined
according to requirement ecuc_sws_2108*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: External identifiers are defined
according to requirement ecuc_sws_2108*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: External identifiers are defined
according to requirement ecuc_sws_2108*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: External identifiers are defined
according to requirement ecuc_sws_2108*/
#define DioConf_DioChannel_DIO_20028_AURIX_RESET3_1V2 (DIO_CHANNEL_40_2)
#endif



/*******************************************************************************
**                      Global Constant Declarations                          **
*******************************************************************************/
#define DIO_START_SEC_CONFIG_DATA_ASIL_B_GLOBAL_UNSPECIFIED
#include "Dio_MemMap.h"

extern const struct Dio_ConfigType Dio_Config; 
#define DIO_STOP_SEC_CONFIG_DATA_ASIL_B_GLOBAL_UNSPECIFIED
/* MISRA2012_RULE_4_10_JUSTIFICATION: To be compliant with autosar guidelines 
Dio_Memmap.h header is included without safegaurd.*/
#include "Dio_MemMap.h"
/*******************************************************************************
**                      Global Data Type                                      **
*******************************************************************************/
/* End of DIO_CFG_H */
#endif
