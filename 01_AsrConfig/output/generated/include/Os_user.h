/* This file is generated automatically. DO NOT EDIT!!
 * 
 * EB tresos AutoCore OS 6.1.31 TRICORE/TC38XQ
 * (Build 20210823)
 * 
 * (c) 1998-2023 Elektrobit Automotive GmbH
 * Am Wolfsmantel 46
 * 91058 Erlangen
 * GERMANY
 * 
 * Date         : 6/30/23 12:21 PM           !!!IGNORE-LINE!!!
 */

#ifndef OS_USER_H
#define OS_USER_H
#ifdef __cplusplus
extern "C" {
#endif

#define OS_GENERATION_ID_OS_H 0xe00962e5UL

#define OS_AUTOSAROS_VER 6

#define OS_AUTOSAROS_REV 1

#define OS_AUTOSAROS_CORE_BUILD 20210823

#define OS_AUTOSAROS_ARCH_BUILD 20210823

#ifndef OS_INTERRUPT_KEYWORD
#define OS_INTERRUPT_KEYWORD
#endif

#include <Os_api.h>
/*===================================================================
 * Alarms
 *==================================================================*/

#define AlarmIncrementRteCounter_C0 0
#define AlarmIncrementRteCounter_C1 1
#define AlarmIncrementRteCounter_C2 2
#define AlarmIncrementRteCounter_C3 3

/*===================================================================
 * Application modes
 *==================================================================*/

#define OSDEFAULTAPPMODE 0
/*===================================================================
 * Applications
 *==================================================================*/

#if OS_KERNEL_TYPE != OS_MICROKERNEL
#define OsApplication_C0 0
#endif
#if OS_KERNEL_TYPE != OS_MICROKERNEL
#define OsApplication_C1 1
#endif
#if OS_KERNEL_TYPE != OS_MICROKERNEL
#define OsApplication_C2 2
#endif
#if OS_KERNEL_TYPE != OS_MICROKERNEL
#define OsApplication_C3 3
#endif

/*===================================================================
 * CPU Core configuration
 *==================================================================*/

#define OS_CORE_ID_0 0
#define OS_CORE_ID_1 1
#define OS_CORE_ID_2 2
#define OS_CORE_ID_3 3

/*===================================================================
 * Core Mapping
 *==================================================================*/

#define RES_SCHEDULER OS_GetResScheduler()
/*===================================================================
 * Counters
 *==================================================================*/

#define OSMAXALLOWEDVALUE_HwCounter_C0 OS_U(4294967295)
#define OSTICKSPERBASE_HwCounter_C0 OS_U(1000)
#define OSMINCYCLE_HwCounter_C0 OS_U(100)
#ifndef OS_ASM
extern void OS_CounterIsr_HwCounter_C0(void);
#endif  /* OS_ASM */
#define OS_NsToTicks_HwCounter_C0(x) OS_NsToTicks_STM0_T0((x))
#define OS_TicksToNs_HwCounter_C0(x) OS_TicksToNs_STM0_T0((x))
#define OS_TICKS2NS_HwCounter_C0(x) (OS_TicksToNs_STM0_T0((x)))
#define OS_TICKS2US_HwCounter_C0(x) (OS_TicksToNs_STM0_T0((x))/1000u)
#define OS_TICKS2MS_HwCounter_C0(x) (OS_TicksToNs_STM0_T0((x))/1000000u)
#define OS_TICKS2SEC_HwCounter_C0(x) (OS_TicksToNs_STM0_T0((x))/1000000000u)
#define OSMAXALLOWEDVALUE_Rte_Counter_C0 OS_U(4294967295)
#define OSTICKSPERBASE_Rte_Counter_C0 OS_U(1)
#define OSMINCYCLE_Rte_Counter_C0 OS_U(1)
#define OS_NsToTicks_Rte_Counter_C0(x) ((x)/1000000)
#define OS_TicksToNs_Rte_Counter_C0(x) ((x)*1000000)
#define OS_TICKS2NS_Rte_Counter_C0(x) (OS_TicksToNs_Rte_Counter_C0((x)))
#define OS_TICKS2US_Rte_Counter_C0(x) (OS_TicksToNs_Rte_Counter_C0((x)))/1000u
#define OS_TICKS2MS_Rte_Counter_C0(x) (OS_TicksToNs_Rte_Counter_C0((x)))/1000000u
#define OS_TICKS2SEC_Rte_Counter_C0(x) (OS_TicksToNs_Rte_Counter_C0((x)))/1000000000u
#define OSMAXALLOWEDVALUE_HwCounter_C1 OS_U(4294967295)
#define OSTICKSPERBASE_HwCounter_C1 OS_U(1000)
#define OSMINCYCLE_HwCounter_C1 OS_U(100)
#ifndef OS_ASM
extern void OS_CounterIsr_HwCounter_C1(void);
#endif  /* OS_ASM */
#define OS_NsToTicks_HwCounter_C1(x) OS_NsToTicks_STM0_T1((x))
#define OS_TicksToNs_HwCounter_C1(x) OS_TicksToNs_STM0_T1((x))
#define OS_TICKS2NS_HwCounter_C1(x) (OS_TicksToNs_STM0_T1((x)))
#define OS_TICKS2US_HwCounter_C1(x) (OS_TicksToNs_STM0_T1((x))/1000u)
#define OS_TICKS2MS_HwCounter_C1(x) (OS_TicksToNs_STM0_T1((x))/1000000u)
#define OS_TICKS2SEC_HwCounter_C1(x) (OS_TicksToNs_STM0_T1((x))/1000000000u)
#define OSMAXALLOWEDVALUE_Rte_Counter_C1 OS_U(4294967295)
#define OSTICKSPERBASE_Rte_Counter_C1 OS_U(1)
#define OSMINCYCLE_Rte_Counter_C1 OS_U(1)
#define OS_NsToTicks_Rte_Counter_C1(x) ((x)/1000000)
#define OS_TicksToNs_Rte_Counter_C1(x) ((x)*1000000)
#define OS_TICKS2NS_Rte_Counter_C1(x) (OS_TicksToNs_Rte_Counter_C1((x)))
#define OS_TICKS2US_Rte_Counter_C1(x) (OS_TicksToNs_Rte_Counter_C1((x)))/1000u
#define OS_TICKS2MS_Rte_Counter_C1(x) (OS_TicksToNs_Rte_Counter_C1((x)))/1000000u
#define OS_TICKS2SEC_Rte_Counter_C1(x) (OS_TicksToNs_Rte_Counter_C1((x)))/1000000000u
#define OSMAXALLOWEDVALUE_HwCounter_C2 OS_U(4294967295)
#define OSTICKSPERBASE_HwCounter_C2 OS_U(1000)
#define OSMINCYCLE_HwCounter_C2 OS_U(100)
#ifndef OS_ASM
extern void OS_CounterIsr_HwCounter_C2(void);
#endif  /* OS_ASM */
#define OS_NsToTicks_HwCounter_C2(x) OS_NsToTicks_STM1_T0((x))
#define OS_TicksToNs_HwCounter_C2(x) OS_TicksToNs_STM1_T0((x))
#define OS_TICKS2NS_HwCounter_C2(x) (OS_TicksToNs_STM1_T0((x)))
#define OS_TICKS2US_HwCounter_C2(x) (OS_TicksToNs_STM1_T0((x))/1000u)
#define OS_TICKS2MS_HwCounter_C2(x) (OS_TicksToNs_STM1_T0((x))/1000000u)
#define OS_TICKS2SEC_HwCounter_C2(x) (OS_TicksToNs_STM1_T0((x))/1000000000u)
#define OSMAXALLOWEDVALUE_Rte_Counter_C2 OS_U(4294967295)
#define OSTICKSPERBASE_Rte_Counter_C2 OS_U(1)
#define OSMINCYCLE_Rte_Counter_C2 OS_U(1)
#define OS_NsToTicks_Rte_Counter_C2(x) ((x)/1000000)
#define OS_TicksToNs_Rte_Counter_C2(x) ((x)*1000000)
#define OS_TICKS2NS_Rte_Counter_C2(x) (OS_TicksToNs_Rte_Counter_C2((x)))
#define OS_TICKS2US_Rte_Counter_C2(x) (OS_TicksToNs_Rte_Counter_C2((x)))/1000u
#define OS_TICKS2MS_Rte_Counter_C2(x) (OS_TicksToNs_Rte_Counter_C2((x)))/1000000u
#define OS_TICKS2SEC_Rte_Counter_C2(x) (OS_TicksToNs_Rte_Counter_C2((x)))/1000000000u
#define OSMAXALLOWEDVALUE_HwCounter_C3 OS_U(4294967295)
#define OSTICKSPERBASE_HwCounter_C3 OS_U(1000)
#define OSMINCYCLE_HwCounter_C3 OS_U(100)
#ifndef OS_ASM
extern void OS_CounterIsr_HwCounter_C3(void);
#endif  /* OS_ASM */
#define OS_NsToTicks_HwCounter_C3(x) OS_NsToTicks_STM1_T1((x))
#define OS_TicksToNs_HwCounter_C3(x) OS_TicksToNs_STM1_T1((x))
#define OS_TICKS2NS_HwCounter_C3(x) (OS_TicksToNs_STM1_T1((x)))
#define OS_TICKS2US_HwCounter_C3(x) (OS_TicksToNs_STM1_T1((x))/1000u)
#define OS_TICKS2MS_HwCounter_C3(x) (OS_TicksToNs_STM1_T1((x))/1000000u)
#define OS_TICKS2SEC_HwCounter_C3(x) (OS_TicksToNs_STM1_T1((x))/1000000000u)
#define OSMAXALLOWEDVALUE_Rte_Counter_C3 OS_U(4294967295)
#define OSTICKSPERBASE_Rte_Counter_C3 OS_U(1)
#define OSMINCYCLE_Rte_Counter_C3 OS_U(1)
#define OS_NsToTicks_Rte_Counter_C3(x) ((x)/1000000)
#define OS_TicksToNs_Rte_Counter_C3(x) ((x)*1000000)
#define OS_TICKS2NS_Rte_Counter_C3(x) (OS_TicksToNs_Rte_Counter_C3((x)))
#define OS_TICKS2US_Rte_Counter_C3(x) (OS_TicksToNs_Rte_Counter_C3((x)))/1000u
#define OS_TICKS2MS_Rte_Counter_C3(x) (OS_TicksToNs_Rte_Counter_C3((x)))/1000000u
#define OS_TICKS2SEC_Rte_Counter_C3(x) (OS_TicksToNs_Rte_Counter_C3((x)))/1000000000u
#define HwCounter_C0 0
#define Rte_Counter_C0 1
#define HwCounter_C1 2
#define Rte_Counter_C1 3
#define HwCounter_C2 4
#define Rte_Counter_C2 5
#define HwCounter_C3 6
#define Rte_Counter_C3 7
#define OSMAXALLOWEDVALUE OSMAXALLOWEDVALUE_HwCounter_C0
#define OSTICKSPERBASE OSTICKSPERBASE_HwCounter_C0
#define OSMINCYCLE OSMINCYCLE_HwCounter_C0
#define OSTICKDURATION OS_TicksToNs_HwCounter_C0(1u)

/*===================================================================
 * Events
 *==================================================================*/

#define Rte_OSSendComSignalEvent_OsApplication_C0  0x0001u
#define Rte_OSTimingEvent_Core1_OsTask_Bsw_20ms_TE_9239C5A54F3433A5ED9A15C3877ED11B  0x0001u
#define Rte_OSTimingEvent_Core2_OsTask_Bsw_20ms_TE_D3A2F42BF7C6C717EC3CCFC9FD15E731  0x0001u
#define Rte_OSTimingEvent_Core3_OsTask_Bsw_20ms_TE_D9D2DDEE891EEE02E4F9199A02316334  0x0001u
#define SchM_OSShutdownEvent  0x0002u
#define Rte_OSTimingEvent_Core0_OsTask_Bsw_5ms_TE_9250283FD3A374F9E6E088501A7A0E92  0x0001u
#define Rte_OSTimingEvent_Core0_OsTask_Bsw_5ms_TE_C81871CF733B997334C7E18C4B5DB17E  0x0004u
#define Rte_OSTriggerExecutableEvent_Core0_OsTask_OperationInovkedProxy_MSE_5E3A8F3BBFFE5F72011B7ED19FA8023C  0x0001u
#define Rte_OSTriggerExecutableEvent_Core0_OsTask_OperationInovkedProxy_MSE_848AFAA86723FB0BC1753CC118949923  0x0004u
#define Rte_OSShutdownEvent  0x0001u
#define Rte_OSTimingEvent_Core0_OsTask_Appl_20ms_TE_F97F7A2ECAEA3A4FE9A6468E6E83C78D  0x0002u
#define Rte_OSResolveWaitPointEvent  0x0004u
#define Rte_OSTimingEvent_Core0_OsTask_Appl_60ms_TE_EF84604C92A30BF324A2DEF1D82825FD  0x0002u
#define Rte_OSTimingEvent_Core0_OsTask_Appl_60ms_TE_344FB9C7D2E189EB211BC438F55F3A79  0x0008u
#define Rte_OSTimingEvent_Core1_OsTask_Bsw_20ms_TE_3F85B53DA8A2367156B9DBD85092648F  0x0008u
#define Rte_OSTimingEvent_Core1_OsTask_Bsw_20ms_TE_B040B4ED3027D1A3758BCA982B69EF51  0x0010u
#define Rte_OSTriggerExecutableEvent_Core1_OsTask_Bsw_20ms_MSE_A201CE503011DA46E8ADB75826DD3A34  0x0020u
#define Rte_OSTimingEvent_Core1_OsTask_Appl_10ms_TE_82A7CF7B79788AAC9ACECC46B60FBA35  0x0008u
#define Rte_OSTimingEvent_Core1_OsTask_Appl_10ms_TE_B7D8AAA4EAF6595FD3CAC5E9F209B7C4  0x0010u
#define Rte_OSTimingEvent_Core2_OsTask_Bsw_20ms_TE_29BB7D421FDFD8A63D5E80341CE8612E  0x0008u
#define Rte_OSTriggerExecutableEvent_Core2_OsTask_Bsw_20ms_MSE_FE04558BC80964D5FF00CB2D19E636F1  0x0010u
#define Rte_OSTimingEvent_Core2_OsTask_Appl_5ms_TE_89C5AF3EF7B20A2642A74C905331C459  0x0002u
#define Rte_OSTimingEvent_Core2_OsTask_Appl_5ms_TE_2760829764E12F022E818C5F06DFF5F3  0x0008u
#define Rte_OSTimingEvent_Core3_OsTask_Bsw_20ms_TE_657DAD7D229C5C6ECB7466187F0A914C  0x0008u
#define Rte_OSTimingEvent_Core3_OsTask_Bsw_20ms_TE_60BBEC5D20DC45D3A7EA0EB66F240BAD  0x0010u
#define Rte_OSTriggerExecutableEvent_Core3_OsTask_Bsw_20ms_MSE_9D93B8918661A5C481676DEBE9105C4A  0x0020u
#define Rte_OSTriggerExecutableEvent_Core3_OsTask_OperationInovkedProxy_DRE_B4149D9898C6A2747D6E9740A283D97F  0x0001u
#define Rte_OSTriggerExecutableEvent_Core0_OsTask_OperationInovkedProxy_OIE_011AFBC720300F6A194EA60FB61F4E04  0x0008u
#define Rte_OSTriggerExecutableEvent_Core0_OsTask_OperationInovkedProxy_OIE_FD1BCC71E05DC6960AA85787EC4CB4F7  0x0010u
#define Rte_OSTriggerExecutableEvent_Core0_OsTask_OperationInovkedProxy_OIE_126A0C301745690712CD863C031BE784  0x0020u
#define Rte_OSTriggerExecutableEvent_Core0_OsTask_OperationInovkedProxy_OIE_7FD8B2BCE216C3489E24BBB9B7C1A49D  0x0040u
#define Rte_OSTriggerExecutableEvent_Core0_OsTask_OperationInovkedProxy_OIE_642E03D9FBEEA9D4F79B96B1408FE38F  0x0080u
#define Rte_OSTriggerExecutableEvent_Core3_OsTask_OperationInovkedProxy_OIE_BD25944D0BD6171202C934A684479703  0x0004u
#define Rte_OSTriggerExecutableEvent_Core3_OsTask_OperationInovkedProxy_OIE_4F2ABD96EE1AE82498BD60777EBCB149  0x0008u
#define Rte_OSTriggerExecutableEvent_Core3_OsTask_OperationInovkedProxy_OIE_862F453136842589E446179D9E799AEA  0x0010u
#define Rte_OSTriggerExecutableEvent_Core0_OsTask_OperationInovkedProxy_OIE_552EA811572BA59681987C71EFB54ECC  0x0100u
#define Rte_OSTriggerExecutableEvent_Core0_OsTask_OperationInovkedProxy_OIE_C56FF6B21164EDC76DC8EB2AEDD1EB41  0x0200u
#define Rte_OSTriggerExecutableEvent_Core0_OsTask_OperationInovkedProxy_MSE_6D56C5D58BD4F989CD4CFCC731898ACF  0x0400u
#define Rte_OSTriggerExecutableEvent_Core0_OsTask_OperationInovkedProxy_MSE_B765910ACCD46C21534E6C6B62E8C6C7  0x0800u
#define Rte_OSTimingEvent_Core1_OsTask_Appl_10ms_TE_4FEAAB8C3BCDA73855D3E70C1E051D1F  0x0020u

/*===================================================================
 * Interrupts
 *==================================================================*/

#ifndef OS_ASM
extern void OS_ISR_QSPI3ERR_ISR(void);
#endif  /* OS_ASM */
#define QSPI3ERR_ISR_ISR_CATEGORY 2
#define QSPI3ERR_ISR_ISR_VECTOR 25
#define QSPI3ERR_ISR_ISR_LEVEL 26
#ifndef OS_ASM
extern void OS_ISR_QSPI3PT_ISR(void);
#endif  /* OS_ASM */
#define QSPI3PT_ISR_ISR_CATEGORY 2
#define QSPI3PT_ISR_ISR_VECTOR 26
#define QSPI3PT_ISR_ISR_LEVEL 27
#ifndef OS_ASM
extern void OS_ISR_GTMTIM2SR5_ISR(void);
#endif  /* OS_ASM */
#define GTMTIM2SR5_ISR_ISR_CATEGORY 2
#define GTMTIM2SR5_ISR_ISR_VECTOR 6
#define GTMTIM2SR5_ISR_ISR_LEVEL 7
#ifndef OS_ASM
extern void OS_ISR_GTMTIM1SR5_ISR(void);
#endif  /* OS_ASM */
#define GTMTIM1SR5_ISR_ISR_CATEGORY 2
#define GTMTIM1SR5_ISR_ISR_VECTOR 7
#define GTMTIM1SR5_ISR_ISR_LEVEL 8
#ifndef OS_ASM
extern void OS_ISR_DMACH15SR_ISR(void);
#endif  /* OS_ASM */
#define DMACH15SR_ISR_ISR_CATEGORY 2
#define DMACH15SR_ISR_ISR_VECTOR 27
#define DMACH15SR_ISR_ISR_LEVEL 28
#ifndef OS_ASM
extern void OS_ISR_DMACH16SR_ISR(void);
#endif  /* OS_ASM */
#define DMACH16SR_ISR_ISR_CATEGORY 2
#define DMACH16SR_ISR_ISR_VECTOR 28
#define DMACH16SR_ISR_ISR_LEVEL 29
#ifndef OS_ASM
extern void OS_ISR_CAN1SR0_ISR(void);
#endif  /* OS_ASM */
#define CAN1SR0_ISR_ISR_CATEGORY 2
#define CAN1SR0_ISR_ISR_VECTOR 11
#define CAN1SR0_ISR_ISR_LEVEL 12
#ifndef OS_ASM
extern void OS_ISR_CAN1SR1_ISR(void);
#endif  /* OS_ASM */
#define CAN1SR1_ISR_ISR_CATEGORY 2
#define CAN1SR1_ISR_ISR_VECTOR 12
#define CAN1SR1_ISR_ISR_LEVEL 13
#ifndef OS_ASM
extern void OS_ISR_CAN1SR2_ISR(void);
#endif  /* OS_ASM */
#define CAN1SR2_ISR_ISR_CATEGORY 2
#define CAN1SR2_ISR_ISR_VECTOR 13
#define CAN1SR2_ISR_ISR_LEVEL 14
#ifndef OS_ASM
extern void OS_ISR_CAN1SR3_ISR(void);
#endif  /* OS_ASM */
#define CAN1SR3_ISR_ISR_CATEGORY 2
#define CAN1SR3_ISR_ISR_VECTOR 24
#define CAN1SR3_ISR_ISR_LEVEL 25
#ifndef OS_ASM
extern void OS_ISR_CAN1SR4_ISR(void);
#endif  /* OS_ASM */
#define CAN1SR4_ISR_ISR_CATEGORY 2
#define CAN1SR4_ISR_ISR_VECTOR 14
#define CAN1SR4_ISR_ISR_LEVEL 15
#ifndef OS_ASM
extern void OS_ISR_CAN1SR5_ISR(void);
#endif  /* OS_ASM */
#define CAN1SR5_ISR_ISR_CATEGORY 2
#define CAN1SR5_ISR_ISR_VECTOR 15
#define CAN1SR5_ISR_ISR_LEVEL 16
#ifndef OS_ASM
extern void OS_ISR_CAN1SR6_ISR(void);
#endif  /* OS_ASM */
#define CAN1SR6_ISR_ISR_CATEGORY 2
#define CAN1SR6_ISR_ISR_VECTOR 16
#define CAN1SR6_ISR_ISR_LEVEL 17
#ifndef OS_ASM
extern void OS_ISR_CAN0SR8_ISR(void);
#endif  /* OS_ASM */
#define CAN0SR8_ISR_ISR_CATEGORY 2
#define CAN0SR8_ISR_ISR_VECTOR 17
#define CAN0SR8_ISR_ISR_LEVEL 18
#ifndef OS_ASM
extern void OS_ISR_CAN0SR9_ISR(void);
#endif  /* OS_ASM */
#define CAN0SR9_ISR_ISR_CATEGORY 2
#define CAN0SR9_ISR_ISR_VECTOR 18
#define CAN0SR9_ISR_ISR_LEVEL 19
#ifndef OS_ASM
extern void OS_ISR_CAN0SR10_ISR(void);
#endif  /* OS_ASM */
#define CAN0SR10_ISR_ISR_CATEGORY 2
#define CAN0SR10_ISR_ISR_VECTOR 19
#define CAN0SR10_ISR_ISR_LEVEL 20
#ifndef OS_ASM
extern void OS_ISR_CAN0SR12_ISR(void);
#endif  /* OS_ASM */
#define CAN0SR12_ISR_ISR_CATEGORY 2
#define CAN0SR12_ISR_ISR_VECTOR 20
#define CAN0SR12_ISR_ISR_LEVEL 21
#ifndef OS_ASM
extern void OS_ISR_CAN0SR13_ISR(void);
#endif  /* OS_ASM */
#define CAN0SR13_ISR_ISR_CATEGORY 2
#define CAN0SR13_ISR_ISR_VECTOR 21
#define CAN0SR13_ISR_ISR_LEVEL 22
#ifndef OS_ASM
extern void OS_ISR_CAN0SR14_ISR(void);
#endif  /* OS_ASM */
#define CAN0SR14_ISR_ISR_CATEGORY 2
#define CAN0SR14_ISR_ISR_VECTOR 22
#define CAN0SR14_ISR_ISR_LEVEL 23
#ifndef OS_ASM
extern void OS_ISR_HSCT0_ISR(void);
#endif  /* OS_ASM */
#define HSCT0_ISR_ISR_CATEGORY 2
#define HSCT0_ISR_ISR_VECTOR 23
#define HSCT0_ISR_ISR_LEVEL 24
#ifndef OS_ASM
extern void OS_ISR_HSSL0COK0_ISR(void);
#endif  /* OS_ASM */
#define HSSL0COK0_ISR_ISR_CATEGORY 2
#define HSSL0COK0_ISR_ISR_VECTOR 30
#define HSSL0COK0_ISR_ISR_LEVEL 31
#ifndef OS_ASM
extern void OS_ISR_HSSL0COK2_ISR(void);
#endif  /* OS_ASM */
#define HSSL0COK2_ISR_ISR_CATEGORY 2
#define HSSL0COK2_ISR_ISR_VECTOR 29
#define HSSL0COK2_ISR_ISR_LEVEL 30
#ifndef OS_ASM
extern void OS_ISR_DMACH0SR_ISR(void);
#endif  /* OS_ASM */
#define DMACH0SR_ISR_ISR_CATEGORY 2
#define DMACH0SR_ISR_ISR_VECTOR 4
#define DMACH0SR_ISR_ISR_LEVEL 5
#ifndef OS_ASM
extern void OS_ISR_DMACH1SR_ISR(void);
#endif  /* OS_ASM */
#define DMACH1SR_ISR_ISR_CATEGORY 2
#define DMACH1SR_ISR_ISR_VECTOR 5
#define DMACH1SR_ISR_ISR_LEVEL 6
#ifndef OS_ASM
extern void OS_ISR_GTMTOM2SR3_ISR(void);
#endif  /* OS_ASM */
#define GTMTOM2SR3_ISR_ISR_CATEGORY 2
#define GTMTOM2SR3_ISR_ISR_VECTOR 8
#define GTMTOM2SR3_ISR_ISR_LEVEL 9
#ifndef OS_ASM
extern void OS_ISR_GTMTIM3SR4_ISR(void);
#endif  /* OS_ASM */
#define GTMTIM3SR4_ISR_ISR_CATEGORY 2
#define GTMTIM3SR4_ISR_ISR_VECTOR 10
#define GTMTIM3SR4_ISR_ISR_LEVEL 11
#ifndef OS_ASM
extern void OS_ISR_DMAERR0SR_ISR(void);
#endif  /* OS_ASM */
#define DMAERR0SR_ISR_ISR_CATEGORY 2
#define DMAERR0SR_ISR_ISR_VECTOR 9
#define DMAERR0SR_ISR_ISR_LEVEL 10
#define CrossCoreNotify0_ISR_CATEGORY CC
#define CrossCoreNotify0_ISR_VECTOR 34
#define CrossCoreNotify0_ISR_LEVEL 35
#define CrossCoreNotify1_ISR_CATEGORY CC
#define CrossCoreNotify1_ISR_VECTOR 34
#define CrossCoreNotify1_ISR_LEVEL 35
#define CrossCoreNotify2_ISR_CATEGORY CC
#define CrossCoreNotify2_ISR_VECTOR 34
#define CrossCoreNotify2_ISR_LEVEL 35
#define CrossCoreNotify3_ISR_CATEGORY CC
#define CrossCoreNotify3_ISR_VECTOR 34
#define CrossCoreNotify3_ISR_LEVEL 35
#define Os_Counter_STM0_T0_ISR_CATEGORY 2
#define Os_Counter_STM0_T0_ISR_VECTOR 3
#define Os_Counter_STM0_T0_ISR_LEVEL 4
#define Os_Counter_STM0_T1_ISR_CATEGORY 2
#define Os_Counter_STM0_T1_ISR_VECTOR 3
#define Os_Counter_STM0_T1_ISR_LEVEL 4
#define Os_Counter_STM1_T0_ISR_CATEGORY 2
#define Os_Counter_STM1_T0_ISR_VECTOR 3
#define Os_Counter_STM1_T0_ISR_LEVEL 4
#define Os_Counter_STM1_T1_ISR_CATEGORY 2
#define Os_Counter_STM1_T1_ISR_VECTOR 3
#define Os_Counter_STM1_T1_ISR_LEVEL 4
#if OS_KERNEL_TYPE != OS_MICROKERNEL
#define QSPI3ERR_ISR 0
#endif
#if OS_KERNEL_TYPE != OS_MICROKERNEL
#define QSPI3PT_ISR 1
#endif
#if OS_KERNEL_TYPE != OS_MICROKERNEL
#define GTMTIM2SR5_ISR 2
#endif
#if OS_KERNEL_TYPE != OS_MICROKERNEL
#define GTMTIM1SR5_ISR 3
#endif
#if OS_KERNEL_TYPE != OS_MICROKERNEL
#define DMACH15SR_ISR 4
#endif
#if OS_KERNEL_TYPE != OS_MICROKERNEL
#define DMACH16SR_ISR 5
#endif
#if OS_KERNEL_TYPE != OS_MICROKERNEL
#define CAN1SR0_ISR 6
#endif
#if OS_KERNEL_TYPE != OS_MICROKERNEL
#define CAN1SR1_ISR 7
#endif
#if OS_KERNEL_TYPE != OS_MICROKERNEL
#define CAN1SR2_ISR 8
#endif
#if OS_KERNEL_TYPE != OS_MICROKERNEL
#define CAN1SR3_ISR 9
#endif
#if OS_KERNEL_TYPE != OS_MICROKERNEL
#define CAN1SR4_ISR 10
#endif
#if OS_KERNEL_TYPE != OS_MICROKERNEL
#define CAN1SR5_ISR 11
#endif
#if OS_KERNEL_TYPE != OS_MICROKERNEL
#define CAN1SR6_ISR 12
#endif
#if OS_KERNEL_TYPE != OS_MICROKERNEL
#define CAN0SR8_ISR 13
#endif
#if OS_KERNEL_TYPE != OS_MICROKERNEL
#define CAN0SR9_ISR 14
#endif
#if OS_KERNEL_TYPE != OS_MICROKERNEL
#define CAN0SR10_ISR 15
#endif
#if OS_KERNEL_TYPE != OS_MICROKERNEL
#define CAN0SR12_ISR 16
#endif
#if OS_KERNEL_TYPE != OS_MICROKERNEL
#define CAN0SR13_ISR 17
#endif
#if OS_KERNEL_TYPE != OS_MICROKERNEL
#define CAN0SR14_ISR 18
#endif
#if OS_KERNEL_TYPE != OS_MICROKERNEL
#define HSCT0_ISR 19
#endif
#if OS_KERNEL_TYPE != OS_MICROKERNEL
#define HSSL0COK0_ISR 20
#endif
#if OS_KERNEL_TYPE != OS_MICROKERNEL
#define HSSL0COK2_ISR 21
#endif
#if OS_KERNEL_TYPE != OS_MICROKERNEL
#define DMACH0SR_ISR 22
#endif
#if OS_KERNEL_TYPE != OS_MICROKERNEL
#define DMACH1SR_ISR 23
#endif
#if OS_KERNEL_TYPE != OS_MICROKERNEL
#define GTMTOM2SR3_ISR 24
#endif
#if OS_KERNEL_TYPE != OS_MICROKERNEL
#define GTMTIM3SR4_ISR 25
#endif
#if OS_KERNEL_TYPE != OS_MICROKERNEL
#define DMAERR0SR_ISR 26
#endif

/*===================================================================
 * Resources
 *==================================================================*/

#if OS_KERNEL_TYPE != OS_MICROKERNEL
#define RES_SCHEDULER_0 0
#endif
#if OS_KERNEL_TYPE != OS_MICROKERNEL
#define RES_SCHEDULER_1 1
#endif
#if OS_KERNEL_TYPE != OS_MICROKERNEL
#define RES_SCHEDULER_2 2
#endif
#if OS_KERNEL_TYPE != OS_MICROKERNEL
#define RES_SCHEDULER_3 3
#endif
#if OS_KERNEL_TYPE != OS_MICROKERNEL
#define Rte_Res_0 4
#endif
#if OS_KERNEL_TYPE != OS_MICROKERNEL
#define Rte_Res_1 5
#endif
#if OS_KERNEL_TYPE != OS_MICROKERNEL
#define Rte_Res_2 6
#endif
#if OS_KERNEL_TYPE != OS_MICROKERNEL
#define Rte_Res_3 7
#endif
#if OS_KERNEL_TYPE != OS_MICROKERNEL
#define Rte_Res_4 8
#endif
#if OS_KERNEL_TYPE != OS_MICROKERNEL
#define Rte_Res_5 9
#endif
#if OS_KERNEL_TYPE != OS_MICROKERNEL
#define Rte_Res_6 10
#endif
#if OS_KERNEL_TYPE != OS_MICROKERNEL
#define Rte_Res_7 11
#endif
#if OS_KERNEL_TYPE != OS_MICROKERNEL
#define Rte_Res_8 12
#endif

/*===================================================================
 * Schedule Tables
 *==================================================================*/

#define SchM_DefaultScheduleTable_OsApplication_C0 0
#define Rte_DefaultScheduleTable_OsApplication_C0 1
#define SchM_DefaultScheduleTable_OsApplication_C1 2
#define Rte_DefaultScheduleTable_OsApplication_C1 3
#define SchM_DefaultScheduleTable_OsApplication_C2 4
#define Rte_DefaultScheduleTable_OsApplication_C2 5
#define SchM_DefaultScheduleTable_OsApplication_C3 6
#define Rte_DefaultScheduleTable_OsApplication_C3 7

/*===================================================================
 * Spinlocks
 *==================================================================*/

#if OS_KERNEL_TYPE != OS_MICROKERNEL
#define OsSpinlock_SpiBuffer 0
#endif
#if OS_KERNEL_TYPE != OS_MICROKERNEL
#define OsSpinlock_EventMsgPool 1
#endif
#if OS_KERNEL_TYPE != OS_MICROKERNEL
#define Rte_Spinlock_0 2
#endif
#if OS_KERNEL_TYPE != OS_MICROKERNEL
#define Rte_Spinlock_1 3
#endif
#if OS_KERNEL_TYPE != OS_MICROKERNEL
#define Rte_Spinlock_2 4
#endif
#if OS_KERNEL_TYPE != OS_MICROKERNEL
#define Rte_Spinlock_3 5
#endif
#if OS_KERNEL_TYPE != OS_MICROKERNEL
#define Rte_Spinlock_4 6
#endif
#if OS_KERNEL_TYPE != OS_MICROKERNEL
#define Rte_Spinlock_5 7
#endif
#if OS_KERNEL_TYPE != OS_MICROKERNEL
#define Rte_Spinlock_6 8
#endif
#if OS_KERNEL_TYPE != OS_MICROKERNEL
#define Rte_Spinlock_7 9
#endif
#if OS_KERNEL_TYPE != OS_MICROKERNEL
#define Rte_Spinlock_8 10
#endif
#if OS_KERNEL_TYPE != OS_MICROKERNEL
#define Rte_Spinlock_9 11
#endif
#if OS_KERNEL_TYPE != OS_MICROKERNEL
#define Rte_Spinlock_10 12
#endif
#if OS_KERNEL_TYPE != OS_MICROKERNEL
#define Rte_Spinlock_11 13
#endif
#if OS_KERNEL_TYPE != OS_MICROKERNEL
#define Rte_Spinlock_12 14
#endif
#if OS_KERNEL_TYPE != OS_MICROKERNEL
#define Rte_Spinlock_13 15
#endif
#if OS_KERNEL_TYPE != OS_MICROKERNEL
#define Rte_Spinlock_14 16
#endif
#if OS_KERNEL_TYPE != OS_MICROKERNEL
#define Rte_Spinlock_15 17
#endif
#if OS_KERNEL_TYPE != OS_MICROKERNEL
#define Rte_Spinlock_16 18
#endif
#if OS_KERNEL_TYPE != OS_MICROKERNEL
#define Rte_Spinlock_17 19
#endif
#if OS_KERNEL_TYPE != OS_MICROKERNEL
#define Rte_Spinlock_18 20
#endif
#if OS_KERNEL_TYPE != OS_MICROKERNEL
#define Rte_Spinlock_19 21
#endif
#if OS_KERNEL_TYPE != OS_MICROKERNEL
#define Rte_Spinlock_20 22
#endif
#if OS_KERNEL_TYPE != OS_MICROKERNEL
#define Rte_Spinlock_21 23
#endif

/*===================================================================
 * Tasks
 *==================================================================*/

#if OS_KERNEL_TYPE != OS_MICROKERNEL
#define Core0_OsTask_Bsw_5ms 0
#endif
#if OS_KERNEL_TYPE != OS_MICROKERNEL
#define Core0_OsTask_Appl_20ms 1
#endif
#if OS_KERNEL_TYPE != OS_MICROKERNEL
#define Core0_OsTask_Appl_60ms 2
#endif
#if OS_KERNEL_TYPE != OS_MICROKERNEL
#define Core0_OsTask_OperationInovkedProxy 3
#endif
#if OS_KERNEL_TYPE != OS_MICROKERNEL
#define Core1_OsTask_Bsw_20ms 4
#endif
#if OS_KERNEL_TYPE != OS_MICROKERNEL
#define Core1_OsTask_Appl_10ms 5
#endif
#if OS_KERNEL_TYPE != OS_MICROKERNEL
#define Core2_OsTask_Bsw_20ms 6
#endif
#if OS_KERNEL_TYPE != OS_MICROKERNEL
#define Core2_OsTask_Appl_5ms 7
#endif
#if OS_KERNEL_TYPE != OS_MICROKERNEL
#define Core3_OsTask_Bsw_20ms 8
#endif
#if OS_KERNEL_TYPE != OS_MICROKERNEL
#define Core3_OsTask_OperationInovkedProxy 9
#endif
#if OS_KERNEL_TYPE != OS_MICROKERNEL
#define Core0_DefaultTask 10
#endif
#if OS_KERNEL_TYPE != OS_MICROKERNEL
#define Core0_InitTask_Appl 11
#endif
#if OS_KERNEL_TYPE != OS_MICROKERNEL
#define Core0_OsTask_FunctionSafety_5ms 12
#endif
#if OS_KERNEL_TYPE != OS_MICROKERNEL
#define Core0_OsTask_Bsw_10ms 13
#endif
#if OS_KERNEL_TYPE != OS_MICROKERNEL
#define Core0_OsTask_Bsw_20ms 14
#endif
#if OS_KERNEL_TYPE != OS_MICROKERNEL
#define Core0_OsTask_Appl_5ms 15
#endif
#if OS_KERNEL_TYPE != OS_MICROKERNEL
#define Core0_OsTask_Appl_10ms 16
#endif
#if OS_KERNEL_TYPE != OS_MICROKERNEL
#define Core1_DefaultTask 17
#endif
#if OS_KERNEL_TYPE != OS_MICROKERNEL
#define Core1_InitTask_Appl 18
#endif
#if OS_KERNEL_TYPE != OS_MICROKERNEL
#define Core1_OsTask_Appl_20ms 19
#endif
#if OS_KERNEL_TYPE != OS_MICROKERNEL
#define Core1_OsTask_Appl_60ms 20
#endif
#if OS_KERNEL_TYPE != OS_MICROKERNEL
#define Core1_OsTask_OperationInovkedProxy 21
#endif
#if OS_KERNEL_TYPE != OS_MICROKERNEL
#define Core2_DefaultTask 22
#endif
#if OS_KERNEL_TYPE != OS_MICROKERNEL
#define Core2_InitTask_Appl 23
#endif
#if OS_KERNEL_TYPE != OS_MICROKERNEL
#define Core2_OsTask_OperationInovkedProxy 24
#endif
#if OS_KERNEL_TYPE != OS_MICROKERNEL
#define Core3_DefaultTask 25
#endif
#if OS_KERNEL_TYPE != OS_MICROKERNEL
#define Core3_InitTask_Appl 26
#endif
#if OS_KERNEL_TYPE != OS_MICROKERNEL
#define Core3_OsTask_Appl_10ms 27
#endif
#if OS_KERNEL_TYPE != OS_MICROKERNEL
#define Core3_OsTask_Appl_50ms 28
#endif
#if OS_KERNEL_TYPE != OS_MICROKERNEL
#define Core3_OsTask_Appl_60ms 29
#endif

/*===================================================================
 * Time-stamp timer
 *==================================================================*/

#define OS_TimestampNsToTicks(ns) OS_NsToTicks_TbTimer(ns)
#define OS_TimestampTicksToNs(ticks) OS_TicksToNs_TbTimer(ticks)
#ifdef __cplusplus
}
#endif
#endif  /* OS_USER_H */
