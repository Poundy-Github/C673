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

#ifndef OS_CONFIG_H
#define OS_CONFIG_H
#ifdef __cplusplus
extern "C" {
#endif

/*
 * MISRA-C:2012 Deviation List
 *
 * MISRAC2012-1) Deviated Rule: 8.6 (required)
 * An identifier with external linkage shall have exactly one external definition.
 *
 * Reason:
 * These symbols are defined in assembly language files and hence,
 * are not visible to the MISRA-C analyzer.
*/
#include <Os.h>
#include <Os_tool.h>
#include <TRICORE/Os_TRICORE_timer_stm.h>

#define OS_GENERATION_ID_OS_CONF_H 0xe00962e5UL

#define OS_AUTOSAROS_VER 6

#define OS_AUTOSAROS_REV 1

#define OS_AUTOSAROS_CORE_BUILD 20210823

#define OS_AUTOSAROS_ARCH_BUILD 20210823

#ifndef OS_ASM
extern const os_uint32_t OS_OS_SYSTEM_1GenBuildId;
#endif  /* OS_ASM */
#ifndef OS_ASM
extern const os_uint32_t OS_os_GenBuildId;
#endif  /* OS_ASM */
#ifndef OS_ASM
extern const os_uint32_t OS_OsApplication_C1GenBuildId;
#endif  /* OS_ASM */
#ifndef OS_ASM
extern const os_uint32_t OS_OS_SYSTEM_0GenBuildId;
#endif  /* OS_ASM */
#ifndef OS_ASM
extern const os_uint32_t OS_OsApplication_C2GenBuildId;
#endif  /* OS_ASM */
#ifndef OS_ASM
extern const os_uint32_t OS_OS_SYSTEM_3GenBuildId;
#endif  /* OS_ASM */
#ifndef OS_ASM
extern const os_uint32_t OS_OsApplication_C0GenBuildId;
#endif  /* OS_ASM */
#ifndef OS_ASM
extern const os_uint32_t OS_OsApplication_C3GenBuildId;
#endif  /* OS_ASM */
#ifndef OS_ASM
extern const os_uint32_t OS_OS_SYSTEM_2GenBuildId;
#endif  /* OS_ASM */

/*===================================================================
 * Advanced Logical Core Interface
 *==================================================================*/

#define OS_ALCI_PHY_TO_LOG_CORE0 0
#define OS_ALCI_PHY_TO_LOG_CORE1 1
#define OS_ALCI_PHY_TO_LOG_CORE2 2
#define OS_ALCI_PHY_TO_LOG_CORE3 3
#define OS_ALCI_LOG_TO_PHY_CORE0 0
#define OS_ALCI_LOG_TO_PHY_CORE1 1
#define OS_ALCI_LOG_TO_PHY_CORE2 2
#define OS_ALCI_LOG_TO_PHY_CORE3 3

/*===================================================================
 * Alarms
 *==================================================================*/

#define OS_NALARMS 4
#define OS_NALARMCALLBACKS 0
#define OS_SchM_DefaultScheduleTable_OsApplication_C0 4
#define OS_Rte_DefaultScheduleTable_OsApplication_C0 5
#define OS_SchM_DefaultScheduleTable_OsApplication_C1 6
#define OS_Rte_DefaultScheduleTable_OsApplication_C1 7
#define OS_SchM_DefaultScheduleTable_OsApplication_C2 8
#define OS_Rte_DefaultScheduleTable_OsApplication_C2 9
#define OS_SchM_DefaultScheduleTable_OsApplication_C3 10
#define OS_Rte_DefaultScheduleTable_OsApplication_C3 11
#define OS_ALARM OS_ALARM_INIT(    /* AlarmIncrementRteCounter_C0 */  \
  OsApplication_C0,                                    /* Application id */  \
  &OS_appTable[OsApplication_C0],                      /* Application pointer */  \
  0x1U,                                                /* Permissions */  \
  &OS_WrapIncrementCounter,                            /* Counter wrapper */  \
  0,                                                   /* Not used */  \
  Rte_Counter_C0,                                      /* Incremented counter */  \
  HwCounter_C0,                                        /* Alarm counter */  \
  &OS_alarmDynamic_core0[0]                            /* dynamic data */  \
),  \
OS_ALARM_INIT(    /* AlarmIncrementRteCounter_C1 */  \
  OsApplication_C1,                                    /* Application id */  \
  &OS_appTable[OsApplication_C1],                      /* Application pointer */  \
  0x2U,                                                /* Permissions */  \
  &OS_WrapIncrementCounter,                            /* Counter wrapper */  \
  0,                                                   /* Not used */  \
  Rte_Counter_C1,                                      /* Incremented counter */  \
  HwCounter_C1,                                        /* Alarm counter */  \
  &OS_alarmDynamic_core1[0]                            /* dynamic data */  \
),  \
OS_ALARM_INIT(    /* AlarmIncrementRteCounter_C2 */  \
  OsApplication_C2,                                    /* Application id */  \
  &OS_appTable[OsApplication_C2],                      /* Application pointer */  \
  0x4U,                                                /* Permissions */  \
  &OS_WrapIncrementCounter,                            /* Counter wrapper */  \
  0,                                                   /* Not used */  \
  Rte_Counter_C2,                                      /* Incremented counter */  \
  HwCounter_C2,                                        /* Alarm counter */  \
  &OS_alarmDynamic_core2[0]                            /* dynamic data */  \
),  \
OS_ALARM_INIT(    /* AlarmIncrementRteCounter_C3 */  \
  OsApplication_C3,                                    /* Application id */  \
  &OS_appTable[OsApplication_C3],                      /* Application pointer */  \
  0x8U,                                                /* Permissions */  \
  &OS_WrapIncrementCounter,                            /* Counter wrapper */  \
  0,                                                   /* Not used */  \
  Rte_Counter_C3,                                      /* Incremented counter */  \
  HwCounter_C3,                                        /* Alarm counter */  \
  &OS_alarmDynamic_core3[0]                            /* dynamic data */  \
),  \
OS_ALARM_INIT(    /* OS_SchM_DefaultScheduleTable_OsApplication_C0 */  \
  OsApplication_C0,                                    /* Application id */  \
  &OS_appTable[OsApplication_C0],                      /* Application pointer */  \
  0x1U,                                                /* Permissions */  \
  &OS_WrapRunSchedule,                                 /* Schedule table wrapper */  \
  0,                                                   /* Not used */  \
  SchM_DefaultScheduleTable_OsApplication_C0,          /* Schedule table */  \
  Rte_Counter_C0,                                      /* Alarm counter */  \
  &OS_alarmDynamic_core0[1]                            /* dynamic data */  \
),  \
OS_ALARM_INIT(    /* OS_Rte_DefaultScheduleTable_OsApplication_C0 */  \
  OsApplication_C0,                                    /* Application id */  \
  &OS_appTable[OsApplication_C0],                      /* Application pointer */  \
  0x1U,                                                /* Permissions */  \
  &OS_WrapRunSchedule,                                 /* Schedule table wrapper */  \
  0,                                                   /* Not used */  \
  Rte_DefaultScheduleTable_OsApplication_C0,           /* Schedule table */  \
  Rte_Counter_C0,                                      /* Alarm counter */  \
  &OS_alarmDynamic_core0[2]                            /* dynamic data */  \
),  \
OS_ALARM_INIT(    /* OS_SchM_DefaultScheduleTable_OsApplication_C1 */  \
  OsApplication_C1,                                    /* Application id */  \
  &OS_appTable[OsApplication_C1],                      /* Application pointer */  \
  0x2U,                                                /* Permissions */  \
  &OS_WrapRunSchedule,                                 /* Schedule table wrapper */  \
  0,                                                   /* Not used */  \
  SchM_DefaultScheduleTable_OsApplication_C1,          /* Schedule table */  \
  Rte_Counter_C1,                                      /* Alarm counter */  \
  &OS_alarmDynamic_core1[1]                            /* dynamic data */  \
),  \
OS_ALARM_INIT(    /* OS_Rte_DefaultScheduleTable_OsApplication_C1 */  \
  OsApplication_C1,                                    /* Application id */  \
  &OS_appTable[OsApplication_C1],                      /* Application pointer */  \
  0x2U,                                                /* Permissions */  \
  &OS_WrapRunSchedule,                                 /* Schedule table wrapper */  \
  0,                                                   /* Not used */  \
  Rte_DefaultScheduleTable_OsApplication_C1,           /* Schedule table */  \
  Rte_Counter_C1,                                      /* Alarm counter */  \
  &OS_alarmDynamic_core1[2]                            /* dynamic data */  \
),  \
OS_ALARM_INIT(    /* OS_SchM_DefaultScheduleTable_OsApplication_C2 */  \
  OsApplication_C2,                                    /* Application id */  \
  &OS_appTable[OsApplication_C2],                      /* Application pointer */  \
  0x4U,                                                /* Permissions */  \
  &OS_WrapRunSchedule,                                 /* Schedule table wrapper */  \
  0,                                                   /* Not used */  \
  SchM_DefaultScheduleTable_OsApplication_C2,          /* Schedule table */  \
  Rte_Counter_C2,                                      /* Alarm counter */  \
  &OS_alarmDynamic_core2[1]                            /* dynamic data */  \
),  \
OS_ALARM_INIT(    /* OS_Rte_DefaultScheduleTable_OsApplication_C2 */  \
  OsApplication_C2,                                    /* Application id */  \
  &OS_appTable[OsApplication_C2],                      /* Application pointer */  \
  0x4U,                                                /* Permissions */  \
  &OS_WrapRunSchedule,                                 /* Schedule table wrapper */  \
  0,                                                   /* Not used */  \
  Rte_DefaultScheduleTable_OsApplication_C2,           /* Schedule table */  \
  Rte_Counter_C2,                                      /* Alarm counter */  \
  &OS_alarmDynamic_core2[2]                            /* dynamic data */  \
),  \
OS_ALARM_INIT(    /* OS_SchM_DefaultScheduleTable_OsApplication_C3 */  \
  OsApplication_C3,                                    /* Application id */  \
  &OS_appTable[OsApplication_C3],                      /* Application pointer */  \
  0x8U,                                                /* Permissions */  \
  &OS_WrapRunSchedule,                                 /* Schedule table wrapper */  \
  0,                                                   /* Not used */  \
  SchM_DefaultScheduleTable_OsApplication_C3,          /* Schedule table */  \
  Rte_Counter_C3,                                      /* Alarm counter */  \
  &OS_alarmDynamic_core3[1]                            /* dynamic data */  \
),  \
OS_ALARM_INIT(    /* OS_Rte_DefaultScheduleTable_OsApplication_C3 */  \
  OsApplication_C3,                                    /* Application id */  \
  &OS_appTable[OsApplication_C3],                      /* Application pointer */  \
  0x8U,                                                /* Permissions */  \
  &OS_WrapRunSchedule,                                 /* Schedule table wrapper */  \
  0,                                                   /* Not used */  \
  Rte_DefaultScheduleTable_OsApplication_C3,           /* Schedule table */  \
  Rte_Counter_C3,                                      /* Alarm counter */  \
  &OS_alarmDynamic_core3[2]                            /* dynamic data */  \
),
#define OS_NALARMS_CORE0 1
#define OS_NALARMS_CORE1 1
#define OS_NALARMS_CORE2 1
#define OS_NALARMS_CORE3 1

/*===================================================================
 * Application modes
 *==================================================================*/

#define OS_NSTARTMODES 1
#define OS_AUTOSTARTTASKS   Core0_DefaultTask,                                   \
  Core1_DefaultTask,                                   \
  Core2_DefaultTask,                                   \
  Core3_DefaultTask,                                   \
  OS_NULLTASK
#define OS_STARTMODETASKS   0
#define OS_AUTOSTARTALARMS     {  \
      AlarmIncrementRteCounter_C0,                         \
      OS_STARTMETHOD_REL,                                  \
      OS_NsToTicks_HwCounter_C0(1000000),                  \
      OS_NsToTicks_HwCounter_C0(1000000)  \
    },  \
    {  \
      AlarmIncrementRteCounter_C1,                         \
      OS_STARTMETHOD_REL,                                  \
      OS_NsToTicks_HwCounter_C1(1000000),                  \
      OS_NsToTicks_HwCounter_C1(1000000)  \
    },  \
    {  \
      AlarmIncrementRteCounter_C2,                         \
      OS_STARTMETHOD_REL,                                  \
      OS_NsToTicks_HwCounter_C2(1000000),                  \
      OS_NsToTicks_HwCounter_C2(1000000)  \
    },  \
    {  \
      AlarmIncrementRteCounter_C3,                         \
      OS_STARTMETHOD_REL,                                  \
      OS_NsToTicks_HwCounter_C3(1000000),                  \
      OS_NsToTicks_HwCounter_C3(1000000)  \
    },  \
    {  \
      OS_NULLALARM,                                        \
      OS_STARTMETHOD_REL,                                  \
      0,                                                   \
      0  \
    }
#define OS_STARTMODEALARMS   0

/*===================================================================
 * Applications
 *==================================================================*/

#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern os_uint8_t OS_TOOL_MR_START(OsApplication_C0);
#endif
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern os_uint8_t OS_TOOL_MR_END(OsApplication_C0);
#endif
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern os_uint8_t OS_TOOL_MR_LMA_START(OsApplication_C0);
#endif
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern os_uint8_t OS_TOOL_MR_LMA_END(OsApplication_C0);
#endif
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern os_uint8_t OS_TOOL_MR_START(OsApplication_C1);
#endif
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern os_uint8_t OS_TOOL_MR_END(OsApplication_C1);
#endif
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern os_uint8_t OS_TOOL_MR_LMA_START(OsApplication_C1);
#endif
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern os_uint8_t OS_TOOL_MR_LMA_END(OsApplication_C1);
#endif
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern os_uint8_t OS_TOOL_MR_START(OsApplication_C2);
#endif
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern os_uint8_t OS_TOOL_MR_END(OsApplication_C2);
#endif
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern os_uint8_t OS_TOOL_MR_LMA_START(OsApplication_C2);
#endif
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern os_uint8_t OS_TOOL_MR_LMA_END(OsApplication_C2);
#endif
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern os_uint8_t OS_TOOL_MR_START(OsApplication_C3);
#endif
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern os_uint8_t OS_TOOL_MR_END(OsApplication_C3);
#endif
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern os_uint8_t OS_TOOL_MR_LMA_START(OsApplication_C3);
#endif
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern os_uint8_t OS_TOOL_MR_LMA_END(OsApplication_C3);
#endif
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#define OS_NAPPS 8
#define OS_NAPPSNONPRIV 0
#if OS_KERNEL_TYPE != OS_MICROKERNEL
#define OS_SYSTEM_0 4
#endif
#if OS_KERNEL_TYPE != OS_MICROKERNEL
#define OS_SYSTEM_1 5
#endif
#if OS_KERNEL_TYPE != OS_MICROKERNEL
#define OS_SYSTEM_2 6
#endif
#if OS_KERNEL_TYPE != OS_MICROKERNEL
#define OS_SYSTEM_3 7
#endif
#define OS_APPCONFIG OS_APPCONFIG_INIT(    /* OsApplication_C0 */  \
  &OS_OsApplication_C0GenBuildId,                      /* Build ID */  \
  OS_NULL,                                             /* Startup Hook */  \
  OS_NULL,                                             /* Shutdown Hook */  \
  OS_NULL,                                             /* Error hook */  \
  &OS_TOOL_MR_START(OsApplication_C0),                 /* start of data/bss */  \
  &OS_TOOL_MR_END(OsApplication_C0),                   /* end of data/bss */  \
  &OS_TOOL_MR_LMA_START(OsApplication_C0),             /* start of initial data */  \
  &OS_TOOL_MR_LMA_END(OsApplication_C0),               /* end of initial data */  \
  0x1,                                                 /* Permission Bit */  \
  0x1,                                                 /* Accessing applications */  \
  0,                                                   /* Startup hook stack */  \
  0,                                                   /* Shutdown hook stack */  \
  0,                                                   /* Error hook stack */  \
  OS_NULLTASK,                                         /* Restart Task */  \
  (OS_APP_TRUSTED),                                    /* Flags */  \
  OsApplication_C0,                                    /* Application ID */  \
  &OS_appDynamic_core0[0],                             /* dynamic data */  \
  0,                                                   /* CPU core */  \
    OS_ARCHAPP_INIT(  \
      (OS_PSW_PRS_0|OS_PSW_IO_SU|OS_PSW_CDC_DIS)           /* Flags */  \
    )  \
),  \
OS_APPCONFIG_INIT(    /* OsApplication_C1 */  \
  &OS_OsApplication_C1GenBuildId,                      /* Build ID */  \
  OS_NULL,                                             /* Startup Hook */  \
  OS_NULL,                                             /* Shutdown Hook */  \
  OS_NULL,                                             /* Error hook */  \
  &OS_TOOL_MR_START(OsApplication_C1),                 /* start of data/bss */  \
  &OS_TOOL_MR_END(OsApplication_C1),                   /* end of data/bss */  \
  &OS_TOOL_MR_LMA_START(OsApplication_C1),             /* start of initial data */  \
  &OS_TOOL_MR_LMA_END(OsApplication_C1),               /* end of initial data */  \
  0x2,                                                 /* Permission Bit */  \
  0x2,                                                 /* Accessing applications */  \
  0,                                                   /* Startup hook stack */  \
  0,                                                   /* Shutdown hook stack */  \
  0,                                                   /* Error hook stack */  \
  OS_NULLTASK,                                         /* Restart Task */  \
  (OS_APP_TRUSTED),                                    /* Flags */  \
  OsApplication_C1,                                    /* Application ID */  \
  &OS_appDynamic_core1[0],                             /* dynamic data */  \
  1,                                                   /* CPU core */  \
    OS_ARCHAPP_INIT(  \
      (OS_PSW_PRS_0|OS_PSW_IO_SU|OS_PSW_CDC_DIS)           /* Flags */  \
    )  \
),  \
OS_APPCONFIG_INIT(    /* OsApplication_C2 */  \
  &OS_OsApplication_C2GenBuildId,                      /* Build ID */  \
  OS_NULL,                                             /* Startup Hook */  \
  OS_NULL,                                             /* Shutdown Hook */  \
  OS_NULL,                                             /* Error hook */  \
  &OS_TOOL_MR_START(OsApplication_C2),                 /* start of data/bss */  \
  &OS_TOOL_MR_END(OsApplication_C2),                   /* end of data/bss */  \
  &OS_TOOL_MR_LMA_START(OsApplication_C2),             /* start of initial data */  \
  &OS_TOOL_MR_LMA_END(OsApplication_C2),               /* end of initial data */  \
  0x4,                                                 /* Permission Bit */  \
  0x4,                                                 /* Accessing applications */  \
  0,                                                   /* Startup hook stack */  \
  0,                                                   /* Shutdown hook stack */  \
  0,                                                   /* Error hook stack */  \
  OS_NULLTASK,                                         /* Restart Task */  \
  (OS_APP_TRUSTED),                                    /* Flags */  \
  OsApplication_C2,                                    /* Application ID */  \
  &OS_appDynamic_core2[0],                             /* dynamic data */  \
  2,                                                   /* CPU core */  \
    OS_ARCHAPP_INIT(  \
      (OS_PSW_PRS_0|OS_PSW_IO_SU|OS_PSW_CDC_DIS)           /* Flags */  \
    )  \
),  \
OS_APPCONFIG_INIT(    /* OsApplication_C3 */  \
  &OS_OsApplication_C3GenBuildId,                      /* Build ID */  \
  OS_NULL,                                             /* Startup Hook */  \
  OS_NULL,                                             /* Shutdown Hook */  \
  OS_NULL,                                             /* Error hook */  \
  &OS_TOOL_MR_START(OsApplication_C3),                 /* start of data/bss */  \
  &OS_TOOL_MR_END(OsApplication_C3),                   /* end of data/bss */  \
  &OS_TOOL_MR_LMA_START(OsApplication_C3),             /* start of initial data */  \
  &OS_TOOL_MR_LMA_END(OsApplication_C3),               /* end of initial data */  \
  0x8,                                                 /* Permission Bit */  \
  0x8,                                                 /* Accessing applications */  \
  0,                                                   /* Startup hook stack */  \
  0,                                                   /* Shutdown hook stack */  \
  0,                                                   /* Error hook stack */  \
  OS_NULLTASK,                                         /* Restart Task */  \
  (OS_APP_TRUSTED),                                    /* Flags */  \
  OsApplication_C3,                                    /* Application ID */  \
  &OS_appDynamic_core3[0],                             /* dynamic data */  \
  3,                                                   /* CPU core */  \
    OS_ARCHAPP_INIT(  \
      (OS_PSW_PRS_0|OS_PSW_IO_SU|OS_PSW_CDC_DIS)           /* Flags */  \
    )  \
),  \
OS_APPCONFIG_INIT(    /* OS_SYSTEM_0 */  \
  &OS_OS_SYSTEM_0GenBuildId,                           /* Build ID */  \
  OS_NULL,                                             /* Startup Hook */  \
  OS_NULL,                                             /* Shutdown Hook */  \
  OS_NULL,                                             /* Error hook */  \
  OS_NULL,                                             \
  OS_NULL,                                             \
  OS_NULL,                                             \
  OS_NULL,                                             \
  0xff,                                                /* Permission Bit */  \
  0xff,                                                /* Accessing applications */  \
  0,                                                   /* Startup hook stack */  \
  0,                                                   /* Shutdown hook stack */  \
  0,                                                   /* Error hook stack */  \
  OS_NULLTASK,                                         /* Restart Task */  \
  (OS_APP_TRUSTED|OS_APP_SYSTEM),                      /* Flags */  \
  OS_SYSTEM_0,                                         /* Application ID */  \
  &OS_appDynamic_core0[1],                             /* dynamic data */  \
  0,                                                   /* CPU core */  \
    OS_ARCHAPP_INIT(  \
      (OS_PSW_PRS_0|OS_PSW_IO_SU|OS_PSW_CDC_DIS)           /* Flags */  \
    )  \
),  \
OS_APPCONFIG_INIT(    /* OS_SYSTEM_1 */  \
  &OS_OS_SYSTEM_1GenBuildId,                           /* Build ID */  \
  OS_NULL,                                             /* Startup Hook */  \
  OS_NULL,                                             /* Shutdown Hook */  \
  OS_NULL,                                             /* Error hook */  \
  OS_NULL,                                             \
  OS_NULL,                                             \
  OS_NULL,                                             \
  OS_NULL,                                             \
  0xff,                                                /* Permission Bit */  \
  0xff,                                                /* Accessing applications */  \
  0,                                                   /* Startup hook stack */  \
  0,                                                   /* Shutdown hook stack */  \
  0,                                                   /* Error hook stack */  \
  OS_NULLTASK,                                         /* Restart Task */  \
  (OS_APP_TRUSTED|OS_APP_SYSTEM),                      /* Flags */  \
  OS_SYSTEM_1,                                         /* Application ID */  \
  &OS_appDynamic_core1[1],                             /* dynamic data */  \
  1,                                                   /* CPU core */  \
    OS_ARCHAPP_INIT(  \
      (OS_PSW_PRS_0|OS_PSW_IO_SU|OS_PSW_CDC_DIS)           /* Flags */  \
    )  \
),  \
OS_APPCONFIG_INIT(    /* OS_SYSTEM_2 */  \
  &OS_OS_SYSTEM_2GenBuildId,                           /* Build ID */  \
  OS_NULL,                                             /* Startup Hook */  \
  OS_NULL,                                             /* Shutdown Hook */  \
  OS_NULL,                                             /* Error hook */  \
  OS_NULL,                                             \
  OS_NULL,                                             \
  OS_NULL,                                             \
  OS_NULL,                                             \
  0xff,                                                /* Permission Bit */  \
  0xff,                                                /* Accessing applications */  \
  0,                                                   /* Startup hook stack */  \
  0,                                                   /* Shutdown hook stack */  \
  0,                                                   /* Error hook stack */  \
  OS_NULLTASK,                                         /* Restart Task */  \
  (OS_APP_TRUSTED|OS_APP_SYSTEM),                      /* Flags */  \
  OS_SYSTEM_2,                                         /* Application ID */  \
  &OS_appDynamic_core2[1],                             /* dynamic data */  \
  2,                                                   /* CPU core */  \
    OS_ARCHAPP_INIT(  \
      (OS_PSW_PRS_0|OS_PSW_IO_SU|OS_PSW_CDC_DIS)           /* Flags */  \
    )  \
),  \
OS_APPCONFIG_INIT(    /* OS_SYSTEM_3 */  \
  &OS_OS_SYSTEM_3GenBuildId,                           /* Build ID */  \
  OS_NULL,                                             /* Startup Hook */  \
  OS_NULL,                                             /* Shutdown Hook */  \
  OS_NULL,                                             /* Error hook */  \
  OS_NULL,                                             \
  OS_NULL,                                             \
  OS_NULL,                                             \
  OS_NULL,                                             \
  0xff,                                                /* Permission Bit */  \
  0xff,                                                /* Accessing applications */  \
  0,                                                   /* Startup hook stack */  \
  0,                                                   /* Shutdown hook stack */  \
  0,                                                   /* Error hook stack */  \
  OS_NULLTASK,                                         /* Restart Task */  \
  (OS_APP_TRUSTED|OS_APP_SYSTEM),                      /* Flags */  \
  OS_SYSTEM_3,                                         /* Application ID */  \
  &OS_appDynamic_core3[1],                             /* dynamic data */  \
  3,                                                   /* CPU core */  \
    OS_ARCHAPP_INIT(  \
      (OS_PSW_PRS_0|OS_PSW_IO_SU|OS_PSW_CDC_DIS)           /* Flags */  \
    )  \
),
#define OS_NFUNCTIONS 0
#define OS_SHOOKSTACKLEN 0
#define OS_EHOOKSTACKLEN 0
#define OS_NAPPS_CORE0 2
#define OS_NAPPS_CORE1 2
#define OS_NAPPS_CORE2 2
#define OS_NAPPS_CORE3 2

/*===================================================================
 * CPU Core configuration
 *==================================================================*/

#define OS_PROPERTIES_CORE0 (OS_U(0)|OS_COREPROP_USED_BIT)
#define OS_PROPERTIES_CORE1 (OS_U(0)|OS_COREPROP_USED_BIT)
#define OS_PROPERTIES_CORE2 (OS_U(0)|OS_COREPROP_USED_BIT)
#define OS_PROPERTIES_CORE3 (OS_U(0)|OS_COREPROP_USED_BIT)

/*===================================================================
 * Channel Initializers
 *==================================================================*/

#define OS_IOC_ENABLED 0
/*===================================================================
 * Configured Modes
 *==================================================================*/

#define OS_CONFIGMODE (OS_ECC2|OS_SCHEDMIX|OS_EXTENDED|OS_STACKCHECK|OS_DBGPROT_OFF)
#define OS_IECMODE (OS_IEC_AUTOSAR)
#define OS_HOOKSELECTION (OS_ACTION_PROTECTIONHOOK|OS_ACTION_ERRORHOOK)
#define OS_PERMITTEDCONTEXT (OS_permittedContextAutosar)
#define OS_INCLUDE_RTE 0

/*===================================================================
 * Counters
 *==================================================================*/

#define OS_NSHAREDHWCOUNTERTIMESTAMP 0
#define OS_SHAREDHWCOUNTERTIMESTAMP_ALARMID -1
#define OS_SHAREDHWCOUNTERTIMESTAMP_COREID -1
#define OS_NCOUNTERS 8
#define OS_NSWCOUNTERS 4
#define OS_COUNTER OS_COUNTER_INIT(    /* HwCounter_C0 */  \
  OsApplication_C0,                                    /* Application id */  \
  &OS_appTable[OsApplication_C0],                      /* Application pointer */  \
  &OS_HwCounterUpdate,                                 \
  0x1U,                                                /* Permissions */  \
  &OS_hwTimer[0],                                      /* Hardware timer */  \
  (os_tick_t)4294967295U,                              /* Max allowed value */  \
  (os_tick_t)1000U,                                    /* Ticks per base */  \
  (os_tick_t)100U,                                     /* Min cycle */  \
  &OS_counterDynamic_core0[0]                          /* dynamic data */  \
),  \
OS_COUNTER_INIT(    /* Rte_Counter_C0 */  \
  OsApplication_C0,                                    /* Application id */  \
  &OS_appTable[OsApplication_C0],                      /* Application pointer */  \
  OS_NULL,                                             \
  0x1U,                                                /* Permissions */  \
  OS_NULL,                                             /* Hardware timer */  \
  (os_tick_t)4294967295U,                              /* Max allowed value */  \
  (os_tick_t)1U,                                       /* Ticks per base */  \
  (os_tick_t)1U,                                       /* Min cycle */  \
  &OS_counterDynamic_core0[1]                          /* dynamic data */  \
),  \
OS_COUNTER_INIT(    /* HwCounter_C1 */  \
  OsApplication_C1,                                    /* Application id */  \
  &OS_appTable[OsApplication_C1],                      /* Application pointer */  \
  &OS_HwCounterUpdate,                                 \
  0x2U,                                                /* Permissions */  \
  &OS_hwTimer[1],                                      /* Hardware timer */  \
  (os_tick_t)4294967295U,                              /* Max allowed value */  \
  (os_tick_t)1000U,                                    /* Ticks per base */  \
  (os_tick_t)100U,                                     /* Min cycle */  \
  &OS_counterDynamic_core1[0]                          /* dynamic data */  \
),  \
OS_COUNTER_INIT(    /* Rte_Counter_C1 */  \
  OsApplication_C1,                                    /* Application id */  \
  &OS_appTable[OsApplication_C1],                      /* Application pointer */  \
  OS_NULL,                                             \
  0x2U,                                                /* Permissions */  \
  OS_NULL,                                             /* Hardware timer */  \
  (os_tick_t)4294967295U,                              /* Max allowed value */  \
  (os_tick_t)1U,                                       /* Ticks per base */  \
  (os_tick_t)1U,                                       /* Min cycle */  \
  &OS_counterDynamic_core1[1]                          /* dynamic data */  \
),  \
OS_COUNTER_INIT(    /* HwCounter_C2 */  \
  OsApplication_C2,                                    /* Application id */  \
  &OS_appTable[OsApplication_C2],                      /* Application pointer */  \
  &OS_HwCounterUpdate,                                 \
  0x4U,                                                /* Permissions */  \
  &OS_hwTimer[2],                                      /* Hardware timer */  \
  (os_tick_t)4294967295U,                              /* Max allowed value */  \
  (os_tick_t)1000U,                                    /* Ticks per base */  \
  (os_tick_t)100U,                                     /* Min cycle */  \
  &OS_counterDynamic_core2[0]                          /* dynamic data */  \
),  \
OS_COUNTER_INIT(    /* Rte_Counter_C2 */  \
  OsApplication_C2,                                    /* Application id */  \
  &OS_appTable[OsApplication_C2],                      /* Application pointer */  \
  OS_NULL,                                             \
  0x4U,                                                /* Permissions */  \
  OS_NULL,                                             /* Hardware timer */  \
  (os_tick_t)4294967295U,                              /* Max allowed value */  \
  (os_tick_t)1U,                                       /* Ticks per base */  \
  (os_tick_t)1U,                                       /* Min cycle */  \
  &OS_counterDynamic_core2[1]                          /* dynamic data */  \
),  \
OS_COUNTER_INIT(    /* HwCounter_C3 */  \
  OsApplication_C3,                                    /* Application id */  \
  &OS_appTable[OsApplication_C3],                      /* Application pointer */  \
  &OS_HwCounterUpdate,                                 \
  0x8U,                                                /* Permissions */  \
  &OS_hwTimer[3],                                      /* Hardware timer */  \
  (os_tick_t)4294967295U,                              /* Max allowed value */  \
  (os_tick_t)1000U,                                    /* Ticks per base */  \
  (os_tick_t)100U,                                     /* Min cycle */  \
  &OS_counterDynamic_core3[0]                          /* dynamic data */  \
),  \
OS_COUNTER_INIT(    /* Rte_Counter_C3 */  \
  OsApplication_C3,                                    /* Application id */  \
  &OS_appTable[OsApplication_C3],                      /* Application pointer */  \
  OS_NULL,                                             \
  0x8U,                                                /* Permissions */  \
  OS_NULL,                                             /* Hardware timer */  \
  (os_tick_t)4294967295U,                              /* Max allowed value */  \
  (os_tick_t)1U,                                       /* Ticks per base */  \
  (os_tick_t)1U,                                       /* Min cycle */  \
  &OS_counterDynamic_core3[1]                          /* dynamic data */  \
),
#define OS_NINTERNALTICKERS 0
#define OS_NCOUNTERS_CORE0 2
#define OS_NCOUNTERS_CORE1 2
#define OS_NCOUNTERS_CORE2 2
#define OS_NCOUNTERS_CORE3 2

/*===================================================================
 * Events
 *==================================================================*/

#define OS_NEVENTS 40
/*===================================================================
 * Execution timer
 *==================================================================*/

#define OS_EXECUTIONTIMER_INIT     /* Execution timer init */  \
  OS_NULL,                                             \
  OS_NULL,                                             \
  OS_NULL,                                             \
  OS_NULL

/*===================================================================
 * Hardware Timers
 *==================================================================*/

#define OS_NHWTIMERS 4
#define OS_NHWTIMERS_CORE0 1
#define OS_NHWTIMERS_CORE1 1
#define OS_NHWTIMERS_CORE2 1
#define OS_NHWTIMERS_CORE3 1
#define OS_HWTIMER {    /* STM0_T0 */  \
  &OS_stmDriver,                                       /* Driver table */  \
  &OS_hwtLastValue_core0[0],                           \
  3221225472U,                                         /* Max delta */  \
  2147483648U,                                         /* Default delta if max exceeded */  \
  4294967295U,                                         /* Wrap mask */  \
  0U,                                                  /* Driver number */  \
  0U,                                                  /* Driver channel */  \
  0U                                                   /* core */  \
},  \
{    /* STM0_T1 */  \
  &OS_stmDriver,                                       /* Driver table */  \
  &OS_hwtLastValue_core1[0],                           \
  3221225472U,                                         /* Max delta */  \
  2147483648U,                                         /* Default delta if max exceeded */  \
  4294967295U,                                         /* Wrap mask */  \
  0U,                                                  /* Driver number */  \
  1U,                                                  /* Driver channel */  \
  1U                                                   /* core */  \
},  \
{    /* STM1_T0 */  \
  &OS_stmDriver,                                       /* Driver table */  \
  &OS_hwtLastValue_core2[0],                           \
  3221225472U,                                         /* Max delta */  \
  2147483648U,                                         /* Default delta if max exceeded */  \
  4294967295U,                                         /* Wrap mask */  \
  1U,                                                  /* Driver number */  \
  0U,                                                  /* Driver channel */  \
  2U                                                   /* core */  \
},  \
{    /* STM1_T1 */  \
  &OS_stmDriver,                                       /* Driver table */  \
  &OS_hwtLastValue_core3[0],                           \
  3221225472U,                                         /* Max delta */  \
  2147483648U,                                         /* Default delta if max exceeded */  \
  4294967295U,                                         /* Wrap mask */  \
  1U,                                                  /* Driver number */  \
  1U,                                                  /* Driver channel */  \
  3U                                                   /* core */  \
},

/*===================================================================
 * Hook Functions
 *==================================================================*/

#define OS_ERRORHOOK &ErrorHook
#define OS_PRETASKHOOK &PreTaskHook
#define OS_POSTTASKHOOK &PostTaskHook
#define OS_STARTUPHOOK &StartupHook
#define OS_SHUTDOWNHOOK &ShutdownHook
#define OS_PREISRHOOK &PreIsrHook
#define OS_POSTISRHOOK &PostIsrHook
#define OS_PROTECTIONHOOK &ProtectionHook

/*===================================================================
 * Interrupts
 *==================================================================*/

#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern os_uint8_t OS_TOOL_MR_START(QSPI3ERR_ISR);
#endif
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern os_uint8_t OS_TOOL_MR_END(QSPI3ERR_ISR);
#endif
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern os_uint8_t OS_TOOL_MR_LMA_START(QSPI3ERR_ISR);
#endif
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern os_uint8_t OS_TOOL_MR_LMA_END(QSPI3ERR_ISR);
#endif
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#define OS_IRQ1a_NAME OS_VECTOR_QSPI3ERR
#define OS_IRQ1a_ISRID QSPI3ERR_ISR
#define OS_IRQ1a_ENTRY OS_Cat2Handler
#define OS_IRQ1a_TYPE OS_VECTOR_TYPE_CAT2
#define OS_IRQ1a_EXIT OS_Cat2Exit
#define OS_IRQ1a_BISRPRIO 35
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern os_uint8_t OS_TOOL_MR_START(QSPI3PT_ISR);
#endif
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern os_uint8_t OS_TOOL_MR_END(QSPI3PT_ISR);
#endif
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern os_uint8_t OS_TOOL_MR_LMA_START(QSPI3PT_ISR);
#endif
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern os_uint8_t OS_TOOL_MR_LMA_END(QSPI3PT_ISR);
#endif
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#define OS_IRQ1b_NAME OS_VECTOR_QSPI3PT
#define OS_IRQ1b_ISRID QSPI3PT_ISR
#define OS_IRQ1b_ENTRY OS_Cat2Handler
#define OS_IRQ1b_TYPE OS_VECTOR_TYPE_CAT2
#define OS_IRQ1b_EXIT OS_Cat2Exit
#define OS_IRQ1b_BISRPRIO 35
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern os_uint8_t OS_TOOL_MR_START(GTMTIM2SR5_ISR);
#endif
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern os_uint8_t OS_TOOL_MR_END(GTMTIM2SR5_ISR);
#endif
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern os_uint8_t OS_TOOL_MR_LMA_START(GTMTIM2SR5_ISR);
#endif
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern os_uint8_t OS_TOOL_MR_LMA_END(GTMTIM2SR5_ISR);
#endif
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#define OS_IRQ07_NAME OS_VECTOR_GTMTIM25
#define OS_IRQ07_ISRID GTMTIM2SR5_ISR
#define OS_IRQ07_ENTRY OS_Cat2Handler
#define OS_IRQ07_TYPE OS_VECTOR_TYPE_CAT2
#define OS_IRQ07_EXIT OS_Cat2Exit
#define OS_IRQ07_BISRPRIO 35
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern os_uint8_t OS_TOOL_MR_START(GTMTIM1SR5_ISR);
#endif
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern os_uint8_t OS_TOOL_MR_END(GTMTIM1SR5_ISR);
#endif
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern os_uint8_t OS_TOOL_MR_LMA_START(GTMTIM1SR5_ISR);
#endif
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern os_uint8_t OS_TOOL_MR_LMA_END(GTMTIM1SR5_ISR);
#endif
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#define OS_IRQ08_NAME OS_VECTOR_GTMTIM15
#define OS_IRQ08_ISRID GTMTIM1SR5_ISR
#define OS_IRQ08_ENTRY OS_Cat2Handler
#define OS_IRQ08_TYPE OS_VECTOR_TYPE_CAT2
#define OS_IRQ08_EXIT OS_Cat2Exit
#define OS_IRQ08_BISRPRIO 35
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern os_uint8_t OS_TOOL_MR_START(DMACH15SR_ISR);
#endif
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern os_uint8_t OS_TOOL_MR_END(DMACH15SR_ISR);
#endif
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern os_uint8_t OS_TOOL_MR_LMA_START(DMACH15SR_ISR);
#endif
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern os_uint8_t OS_TOOL_MR_LMA_END(DMACH15SR_ISR);
#endif
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#define OS_IRQ1c_NAME OS_VECTOR_DMACH15
#define OS_IRQ1c_ISRID DMACH15SR_ISR
#define OS_IRQ1c_ENTRY OS_Cat2Handler
#define OS_IRQ1c_TYPE OS_VECTOR_TYPE_CAT2
#define OS_IRQ1c_EXIT OS_Cat2Exit
#define OS_IRQ1c_BISRPRIO 35
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern os_uint8_t OS_TOOL_MR_START(DMACH16SR_ISR);
#endif
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern os_uint8_t OS_TOOL_MR_END(DMACH16SR_ISR);
#endif
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern os_uint8_t OS_TOOL_MR_LMA_START(DMACH16SR_ISR);
#endif
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern os_uint8_t OS_TOOL_MR_LMA_END(DMACH16SR_ISR);
#endif
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#define OS_IRQ1d_NAME OS_VECTOR_DMACH16
#define OS_IRQ1d_ISRID DMACH16SR_ISR
#define OS_IRQ1d_ENTRY OS_Cat2Handler
#define OS_IRQ1d_TYPE OS_VECTOR_TYPE_CAT2
#define OS_IRQ1d_EXIT OS_Cat2Exit
#define OS_IRQ1d_BISRPRIO 35
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern os_uint8_t OS_TOOL_MR_START(CAN1SR0_ISR);
#endif
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern os_uint8_t OS_TOOL_MR_END(CAN1SR0_ISR);
#endif
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern os_uint8_t OS_TOOL_MR_LMA_START(CAN1SR0_ISR);
#endif
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern os_uint8_t OS_TOOL_MR_LMA_END(CAN1SR0_ISR);
#endif
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#define OS_IRQ0c_NAME OS_VECTOR_CAN1INT0
#define OS_IRQ0c_ISRID CAN1SR0_ISR
#define OS_IRQ0c_ENTRY OS_Cat2Handler
#define OS_IRQ0c_TYPE OS_VECTOR_TYPE_CAT2
#define OS_IRQ0c_EXIT OS_Cat2Exit
#define OS_IRQ0c_BISRPRIO 35
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern os_uint8_t OS_TOOL_MR_START(CAN1SR1_ISR);
#endif
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern os_uint8_t OS_TOOL_MR_END(CAN1SR1_ISR);
#endif
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern os_uint8_t OS_TOOL_MR_LMA_START(CAN1SR1_ISR);
#endif
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern os_uint8_t OS_TOOL_MR_LMA_END(CAN1SR1_ISR);
#endif
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#define OS_IRQ0d_NAME OS_VECTOR_CAN1INT1
#define OS_IRQ0d_ISRID CAN1SR1_ISR
#define OS_IRQ0d_ENTRY OS_Cat2Handler
#define OS_IRQ0d_TYPE OS_VECTOR_TYPE_CAT2
#define OS_IRQ0d_EXIT OS_Cat2Exit
#define OS_IRQ0d_BISRPRIO 35
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern os_uint8_t OS_TOOL_MR_START(CAN1SR2_ISR);
#endif
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern os_uint8_t OS_TOOL_MR_END(CAN1SR2_ISR);
#endif
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern os_uint8_t OS_TOOL_MR_LMA_START(CAN1SR2_ISR);
#endif
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern os_uint8_t OS_TOOL_MR_LMA_END(CAN1SR2_ISR);
#endif
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#define OS_IRQ0e_NAME OS_VECTOR_CAN1INT2
#define OS_IRQ0e_ISRID CAN1SR2_ISR
#define OS_IRQ0e_ENTRY OS_Cat2Handler
#define OS_IRQ0e_TYPE OS_VECTOR_TYPE_CAT2
#define OS_IRQ0e_EXIT OS_Cat2Exit
#define OS_IRQ0e_BISRPRIO 35
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern os_uint8_t OS_TOOL_MR_START(CAN1SR3_ISR);
#endif
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern os_uint8_t OS_TOOL_MR_END(CAN1SR3_ISR);
#endif
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern os_uint8_t OS_TOOL_MR_LMA_START(CAN1SR3_ISR);
#endif
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern os_uint8_t OS_TOOL_MR_LMA_END(CAN1SR3_ISR);
#endif
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#define OS_IRQ19_NAME OS_VECTOR_CAN1INT3
#define OS_IRQ19_ISRID CAN1SR3_ISR
#define OS_IRQ19_ENTRY OS_Cat2Handler
#define OS_IRQ19_TYPE OS_VECTOR_TYPE_CAT2
#define OS_IRQ19_EXIT OS_Cat2Exit
#define OS_IRQ19_BISRPRIO 35
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern os_uint8_t OS_TOOL_MR_START(CAN1SR4_ISR);
#endif
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern os_uint8_t OS_TOOL_MR_END(CAN1SR4_ISR);
#endif
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern os_uint8_t OS_TOOL_MR_LMA_START(CAN1SR4_ISR);
#endif
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern os_uint8_t OS_TOOL_MR_LMA_END(CAN1SR4_ISR);
#endif
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#define OS_IRQ0f_NAME OS_VECTOR_CAN1INT4
#define OS_IRQ0f_ISRID CAN1SR4_ISR
#define OS_IRQ0f_ENTRY OS_Cat2Handler
#define OS_IRQ0f_TYPE OS_VECTOR_TYPE_CAT2
#define OS_IRQ0f_EXIT OS_Cat2Exit
#define OS_IRQ0f_BISRPRIO 35
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern os_uint8_t OS_TOOL_MR_START(CAN1SR5_ISR);
#endif
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern os_uint8_t OS_TOOL_MR_END(CAN1SR5_ISR);
#endif
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern os_uint8_t OS_TOOL_MR_LMA_START(CAN1SR5_ISR);
#endif
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern os_uint8_t OS_TOOL_MR_LMA_END(CAN1SR5_ISR);
#endif
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#define OS_IRQ10_NAME OS_VECTOR_CAN1INT5
#define OS_IRQ10_ISRID CAN1SR5_ISR
#define OS_IRQ10_ENTRY OS_Cat2Handler
#define OS_IRQ10_TYPE OS_VECTOR_TYPE_CAT2
#define OS_IRQ10_EXIT OS_Cat2Exit
#define OS_IRQ10_BISRPRIO 35
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern os_uint8_t OS_TOOL_MR_START(CAN1SR6_ISR);
#endif
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern os_uint8_t OS_TOOL_MR_END(CAN1SR6_ISR);
#endif
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern os_uint8_t OS_TOOL_MR_LMA_START(CAN1SR6_ISR);
#endif
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern os_uint8_t OS_TOOL_MR_LMA_END(CAN1SR6_ISR);
#endif
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#define OS_IRQ11_NAME OS_VECTOR_CAN1INT6
#define OS_IRQ11_ISRID CAN1SR6_ISR
#define OS_IRQ11_ENTRY OS_Cat2Handler
#define OS_IRQ11_TYPE OS_VECTOR_TYPE_CAT2
#define OS_IRQ11_EXIT OS_Cat2Exit
#define OS_IRQ11_BISRPRIO 35
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern os_uint8_t OS_TOOL_MR_START(CAN0SR8_ISR);
#endif
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern os_uint8_t OS_TOOL_MR_END(CAN0SR8_ISR);
#endif
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern os_uint8_t OS_TOOL_MR_LMA_START(CAN0SR8_ISR);
#endif
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern os_uint8_t OS_TOOL_MR_LMA_END(CAN0SR8_ISR);
#endif
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#define OS_IRQ12_NAME OS_VECTOR_CAN0INT8
#define OS_IRQ12_ISRID CAN0SR8_ISR
#define OS_IRQ12_ENTRY OS_Cat2Handler
#define OS_IRQ12_TYPE OS_VECTOR_TYPE_CAT2
#define OS_IRQ12_EXIT OS_Cat2Exit
#define OS_IRQ12_BISRPRIO 35
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern os_uint8_t OS_TOOL_MR_START(CAN0SR9_ISR);
#endif
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern os_uint8_t OS_TOOL_MR_END(CAN0SR9_ISR);
#endif
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern os_uint8_t OS_TOOL_MR_LMA_START(CAN0SR9_ISR);
#endif
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern os_uint8_t OS_TOOL_MR_LMA_END(CAN0SR9_ISR);
#endif
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#define OS_IRQ13_NAME OS_VECTOR_CAN0INT9
#define OS_IRQ13_ISRID CAN0SR9_ISR
#define OS_IRQ13_ENTRY OS_Cat2Handler
#define OS_IRQ13_TYPE OS_VECTOR_TYPE_CAT2
#define OS_IRQ13_EXIT OS_Cat2Exit
#define OS_IRQ13_BISRPRIO 35
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern os_uint8_t OS_TOOL_MR_START(CAN0SR10_ISR);
#endif
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern os_uint8_t OS_TOOL_MR_END(CAN0SR10_ISR);
#endif
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern os_uint8_t OS_TOOL_MR_LMA_START(CAN0SR10_ISR);
#endif
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern os_uint8_t OS_TOOL_MR_LMA_END(CAN0SR10_ISR);
#endif
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#define OS_IRQ14_NAME OS_VECTOR_CAN0INT10
#define OS_IRQ14_ISRID CAN0SR10_ISR
#define OS_IRQ14_ENTRY OS_Cat2Handler
#define OS_IRQ14_TYPE OS_VECTOR_TYPE_CAT2
#define OS_IRQ14_EXIT OS_Cat2Exit
#define OS_IRQ14_BISRPRIO 35
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern os_uint8_t OS_TOOL_MR_START(CAN0SR12_ISR);
#endif
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern os_uint8_t OS_TOOL_MR_END(CAN0SR12_ISR);
#endif
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern os_uint8_t OS_TOOL_MR_LMA_START(CAN0SR12_ISR);
#endif
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern os_uint8_t OS_TOOL_MR_LMA_END(CAN0SR12_ISR);
#endif
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#define OS_IRQ15_NAME OS_VECTOR_CAN0INT12
#define OS_IRQ15_ISRID CAN0SR12_ISR
#define OS_IRQ15_ENTRY OS_Cat2Handler
#define OS_IRQ15_TYPE OS_VECTOR_TYPE_CAT2
#define OS_IRQ15_EXIT OS_Cat2Exit
#define OS_IRQ15_BISRPRIO 35
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern os_uint8_t OS_TOOL_MR_START(CAN0SR13_ISR);
#endif
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern os_uint8_t OS_TOOL_MR_END(CAN0SR13_ISR);
#endif
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern os_uint8_t OS_TOOL_MR_LMA_START(CAN0SR13_ISR);
#endif
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern os_uint8_t OS_TOOL_MR_LMA_END(CAN0SR13_ISR);
#endif
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#define OS_IRQ16_NAME OS_VECTOR_CAN0INT13
#define OS_IRQ16_ISRID CAN0SR13_ISR
#define OS_IRQ16_ENTRY OS_Cat2Handler
#define OS_IRQ16_TYPE OS_VECTOR_TYPE_CAT2
#define OS_IRQ16_EXIT OS_Cat2Exit
#define OS_IRQ16_BISRPRIO 35
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern os_uint8_t OS_TOOL_MR_START(CAN0SR14_ISR);
#endif
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern os_uint8_t OS_TOOL_MR_END(CAN0SR14_ISR);
#endif
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern os_uint8_t OS_TOOL_MR_LMA_START(CAN0SR14_ISR);
#endif
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern os_uint8_t OS_TOOL_MR_LMA_END(CAN0SR14_ISR);
#endif
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#define OS_IRQ17_NAME OS_VECTOR_CAN0INT14
#define OS_IRQ17_ISRID CAN0SR14_ISR
#define OS_IRQ17_ENTRY OS_Cat2Handler
#define OS_IRQ17_TYPE OS_VECTOR_TYPE_CAT2
#define OS_IRQ17_EXIT OS_Cat2Exit
#define OS_IRQ17_BISRPRIO 35
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern os_uint8_t OS_TOOL_MR_START(HSCT0_ISR);
#endif
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern os_uint8_t OS_TOOL_MR_END(HSCT0_ISR);
#endif
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern os_uint8_t OS_TOOL_MR_LMA_START(HSCT0_ISR);
#endif
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern os_uint8_t OS_TOOL_MR_LMA_END(HSCT0_ISR);
#endif
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#define OS_IRQ18_NAME OS_VECTOR_HSCT0
#define OS_IRQ18_ISRID HSCT0_ISR
#define OS_IRQ18_ENTRY OS_Cat2Handler
#define OS_IRQ18_TYPE OS_VECTOR_TYPE_CAT2
#define OS_IRQ18_EXIT OS_Cat2Exit
#define OS_IRQ18_BISRPRIO 35
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern os_uint8_t OS_TOOL_MR_START(HSSL0COK0_ISR);
#endif
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern os_uint8_t OS_TOOL_MR_END(HSSL0COK0_ISR);
#endif
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern os_uint8_t OS_TOOL_MR_LMA_START(HSSL0COK0_ISR);
#endif
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern os_uint8_t OS_TOOL_MR_LMA_END(HSSL0COK0_ISR);
#endif
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#define OS_IRQ1f_NAME OS_VECTOR_HSSL0COK0
#define OS_IRQ1f_ISRID HSSL0COK0_ISR
#define OS_IRQ1f_ENTRY OS_Cat2Handler
#define OS_IRQ1f_TYPE OS_VECTOR_TYPE_CAT2
#define OS_IRQ1f_EXIT OS_Cat2Exit
#define OS_IRQ1f_BISRPRIO 35
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern os_uint8_t OS_TOOL_MR_START(HSSL0COK2_ISR);
#endif
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern os_uint8_t OS_TOOL_MR_END(HSSL0COK2_ISR);
#endif
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern os_uint8_t OS_TOOL_MR_LMA_START(HSSL0COK2_ISR);
#endif
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern os_uint8_t OS_TOOL_MR_LMA_END(HSSL0COK2_ISR);
#endif
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#define OS_IRQ1e_NAME OS_VECTOR_HSSL0COK2
#define OS_IRQ1e_ISRID HSSL0COK2_ISR
#define OS_IRQ1e_ENTRY OS_Cat2Handler
#define OS_IRQ1e_TYPE OS_VECTOR_TYPE_CAT2
#define OS_IRQ1e_EXIT OS_Cat2Exit
#define OS_IRQ1e_BISRPRIO 35
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern os_uint8_t OS_TOOL_MR_START(DMACH0SR_ISR);
#endif
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern os_uint8_t OS_TOOL_MR_END(DMACH0SR_ISR);
#endif
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern os_uint8_t OS_TOOL_MR_LMA_START(DMACH0SR_ISR);
#endif
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern os_uint8_t OS_TOOL_MR_LMA_END(DMACH0SR_ISR);
#endif
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#define OS_IRQ05_NAME OS_VECTOR_DMACH0
#define OS_IRQ05_ISRID DMACH0SR_ISR
#define OS_IRQ05_ENTRY OS_Cat2Handler
#define OS_IRQ05_TYPE OS_VECTOR_TYPE_CAT2
#define OS_IRQ05_EXIT OS_Cat2Exit
#define OS_IRQ05_BISRPRIO 35
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern os_uint8_t OS_TOOL_MR_START(DMACH1SR_ISR);
#endif
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern os_uint8_t OS_TOOL_MR_END(DMACH1SR_ISR);
#endif
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern os_uint8_t OS_TOOL_MR_LMA_START(DMACH1SR_ISR);
#endif
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern os_uint8_t OS_TOOL_MR_LMA_END(DMACH1SR_ISR);
#endif
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#define OS_IRQ06_NAME OS_VECTOR_DMACH1
#define OS_IRQ06_ISRID DMACH1SR_ISR
#define OS_IRQ06_ENTRY OS_Cat2Handler
#define OS_IRQ06_TYPE OS_VECTOR_TYPE_CAT2
#define OS_IRQ06_EXIT OS_Cat2Exit
#define OS_IRQ06_BISRPRIO 35
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern os_uint8_t OS_TOOL_MR_START(GTMTOM2SR3_ISR);
#endif
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern os_uint8_t OS_TOOL_MR_END(GTMTOM2SR3_ISR);
#endif
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern os_uint8_t OS_TOOL_MR_LMA_START(GTMTOM2SR3_ISR);
#endif
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern os_uint8_t OS_TOOL_MR_LMA_END(GTMTOM2SR3_ISR);
#endif
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#define OS_IRQ09_NAME OS_VECTOR_GTMATOM23
#define OS_IRQ09_ISRID GTMTOM2SR3_ISR
#define OS_IRQ09_ENTRY OS_Cat2Handler
#define OS_IRQ09_TYPE OS_VECTOR_TYPE_CAT2
#define OS_IRQ09_EXIT OS_Cat2Exit
#define OS_IRQ09_BISRPRIO 35
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern os_uint8_t OS_TOOL_MR_START(GTMTIM3SR4_ISR);
#endif
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern os_uint8_t OS_TOOL_MR_END(GTMTIM3SR4_ISR);
#endif
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern os_uint8_t OS_TOOL_MR_LMA_START(GTMTIM3SR4_ISR);
#endif
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern os_uint8_t OS_TOOL_MR_LMA_END(GTMTIM3SR4_ISR);
#endif
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#define OS_IRQ0b_NAME OS_VECTOR_GTMTIM34
#define OS_IRQ0b_ISRID GTMTIM3SR4_ISR
#define OS_IRQ0b_ENTRY OS_Cat2Handler
#define OS_IRQ0b_TYPE OS_VECTOR_TYPE_CAT2
#define OS_IRQ0b_EXIT OS_Cat2Exit
#define OS_IRQ0b_BISRPRIO 35
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern os_uint8_t OS_TOOL_MR_START(DMAERR0SR_ISR);
#endif
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern os_uint8_t OS_TOOL_MR_END(DMAERR0SR_ISR);
#endif
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern os_uint8_t OS_TOOL_MR_LMA_START(DMAERR0SR_ISR);
#endif
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern os_uint8_t OS_TOOL_MR_LMA_END(DMAERR0SR_ISR);
#endif
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#define OS_IRQ0a_NAME OS_VECTOR_DMAERR0
#define OS_IRQ0a_ISRID DMAERR0SR_ISR
#define OS_IRQ0a_ENTRY OS_Cat2Handler
#define OS_IRQ0a_TYPE OS_VECTOR_TYPE_CAT2
#define OS_IRQ0a_EXIT OS_Cat2Exit
#define OS_IRQ0a_BISRPRIO 35
#define OS_IRQ23_NAME OS_VECTOR_GPSR20
#define OS_IRQ23_ISRID CrossCoreNotify0
#define OS_IRQ23_ENTRY OS_CrossCoreNotifyIsr
#define OS_IRQ23_TYPE OS_VECTOR_TYPE_CATCC
#define OS_IRQ23_EXIT OS_CatCCExit
#define OS_IRQ23_BISRPRIO 35
#define OS_IRQ01_NAME OS_VECTOR_STM0SR0
#define OS_IRQ01_ISRID Os_Counter_STM0_T0
#define OS_IRQ01_ENTRY OS_Cat2Handler
#define OS_IRQ01_TYPE OS_VECTOR_TYPE_CAT2
#define OS_IRQ01_EXIT OS_Cat2Exit
#define OS_IRQ01_BISRPRIO 35
#define OS_IRQ02_NAME OS_VECTOR_STM0SR1
#define OS_IRQ02_ISRID Os_Counter_STM0_T1
#define OS_IRQ02_ENTRY OS_Cat2Handler
#define OS_IRQ02_TYPE OS_VECTOR_TYPE_CAT2
#define OS_IRQ02_EXIT OS_Cat2Exit
#define OS_IRQ02_BISRPRIO 35
#define OS_IRQ03_NAME OS_VECTOR_STM1SR0
#define OS_IRQ03_ISRID Os_Counter_STM1_T0
#define OS_IRQ03_ENTRY OS_Cat2Handler
#define OS_IRQ03_TYPE OS_VECTOR_TYPE_CAT2
#define OS_IRQ03_EXIT OS_Cat2Exit
#define OS_IRQ03_BISRPRIO 35
#define OS_IRQ04_NAME OS_VECTOR_STM1SR1
#define OS_IRQ04_ISRID Os_Counter_STM1_T1
#define OS_IRQ04_ENTRY OS_Cat2Handler
#define OS_IRQ04_TYPE OS_VECTOR_TYPE_CAT2
#define OS_IRQ04_EXIT OS_Cat2Exit
#define OS_IRQ04_BISRPRIO 35
#define OS_NINTERRUPTS 35
#define OS_NCAT1_INTERRUPTS 0
#define OS_NCAT2_INTERRUPTS 31
#define OS_NCATK_INTERRUPTS 0
#define OS_NCAT2K_INTERRUPTS 0
#define OS_NISRSEXECTIMELIMIT 0
#define OS_NISRSINTLOCKLIMIT 0
#define OS_NISRSRESLOCKLIMIT 0
#define OS_NISRACCOUNTING 0
#define OS_CAT1LOCK 35
#define OS_CAT2LOCK 31
#define OS_KERNLOCK 35
#define OS_XCOREUNLOCK 34
#define OS_ENABLEALLLOCK 1
#if OS_KERNEL_TYPE != OS_MICROKERNEL
#define CrossCoreNotify0 27
#endif
#if OS_KERNEL_TYPE != OS_MICROKERNEL
#define CrossCoreNotify1 28
#endif
#if OS_KERNEL_TYPE != OS_MICROKERNEL
#define CrossCoreNotify2 29
#endif
#if OS_KERNEL_TYPE != OS_MICROKERNEL
#define CrossCoreNotify3 30
#endif
#if OS_KERNEL_TYPE != OS_MICROKERNEL
#define Os_Counter_STM0_T0 31
#endif
#if OS_KERNEL_TYPE != OS_MICROKERNEL
#define Os_Counter_STM0_T1 32
#endif
#if OS_KERNEL_TYPE != OS_MICROKERNEL
#define Os_Counter_STM1_T0 33
#endif
#if OS_KERNEL_TYPE != OS_MICROKERNEL
#define Os_Counter_STM1_T1 34
#endif
#define OS_ISRCONFIG OS_ISRCONFIG_INIT(    /* QSPI3ERR_ISR */  \
  &OS_appTable[OsApplication_C0],                      /* Application */  \
  0x1U,                                                /* Permissions */  \
  OS_NULL,                                             /* Accounting structure */  \
  &OS_TOOL_MR_START(QSPI3ERR_ISR),                     /* start of data/bss */  \
  &OS_TOOL_MR_END(QSPI3ERR_ISR),                       /* end of data/bss */  \
  &OS_TOOL_MR_LMA_START(QSPI3ERR_ISR),                 /* start of initial data */  \
  &OS_TOOL_MR_LMA_END(QSPI3ERR_ISR),                   /* end of initial data */  \
  &OS_ISR_QSPI3ERR_ISR,                                /* Interrupt entry */  \
  0U,                                                  /* Execution budget */  \
  0U,                                                  /* Os interrupt lock budget */  \
  0U,                                                  /* All interrupt lock budget */  \
  OS_NULL,                                             /* Resource lock budget */  \
  512U,                                                /* Stack size */  \
  OS_NULLRATEMONITOR,                                  /* Rate monitor */  \
  QSPI3ERR_ISR,                                        /* Isr id */  \
  &OS_isrDynamic_core0[0],                             /* dynamic data */  \
  (OS_ISRF_CAT2|OS_ISRF_ENABLE),                       /* Flags */  \
    OS_ARCHISR_INIT(  \
      &OS_SRC_QSPI3ERR,                                    /* Service request node */  \
      26,                                                  /* Arbitration priority */  \
      26                                                   /* Run priority */  \
    )  \
),  \
OS_ISRCONFIG_INIT(    /* QSPI3PT_ISR */  \
  &OS_appTable[OsApplication_C0],                      /* Application */  \
  0x1U,                                                /* Permissions */  \
  OS_NULL,                                             /* Accounting structure */  \
  &OS_TOOL_MR_START(QSPI3PT_ISR),                      /* start of data/bss */  \
  &OS_TOOL_MR_END(QSPI3PT_ISR),                        /* end of data/bss */  \
  &OS_TOOL_MR_LMA_START(QSPI3PT_ISR),                  /* start of initial data */  \
  &OS_TOOL_MR_LMA_END(QSPI3PT_ISR),                    /* end of initial data */  \
  &OS_ISR_QSPI3PT_ISR,                                 /* Interrupt entry */  \
  0U,                                                  /* Execution budget */  \
  0U,                                                  /* Os interrupt lock budget */  \
  0U,                                                  /* All interrupt lock budget */  \
  OS_NULL,                                             /* Resource lock budget */  \
  5120U,                                               /* Stack size */  \
  OS_NULLRATEMONITOR,                                  /* Rate monitor */  \
  QSPI3PT_ISR,                                         /* Isr id */  \
  &OS_isrDynamic_core0[1],                             /* dynamic data */  \
  (OS_ISRF_CAT2|OS_ISRF_ENABLE),                       /* Flags */  \
    OS_ARCHISR_INIT(  \
      &OS_SRC_QSPI3PT,                                     /* Service request node */  \
      27,                                                  /* Arbitration priority */  \
      27                                                   /* Run priority */  \
    )  \
),  \
OS_ISRCONFIG_INIT(    /* GTMTIM2SR5_ISR */  \
  &OS_appTable[OsApplication_C0],                      /* Application */  \
  0x1U,                                                /* Permissions */  \
  OS_NULL,                                             /* Accounting structure */  \
  &OS_TOOL_MR_START(GTMTIM2SR5_ISR),                   /* start of data/bss */  \
  &OS_TOOL_MR_END(GTMTIM2SR5_ISR),                     /* end of data/bss */  \
  &OS_TOOL_MR_LMA_START(GTMTIM2SR5_ISR),               /* start of initial data */  \
  &OS_TOOL_MR_LMA_END(GTMTIM2SR5_ISR),                 /* end of initial data */  \
  &OS_ISR_GTMTIM2SR5_ISR,                              /* Interrupt entry */  \
  0U,                                                  /* Execution budget */  \
  0U,                                                  /* Os interrupt lock budget */  \
  0U,                                                  /* All interrupt lock budget */  \
  OS_NULL,                                             /* Resource lock budget */  \
  512U,                                                /* Stack size */  \
  OS_NULLRATEMONITOR,                                  /* Rate monitor */  \
  GTMTIM2SR5_ISR,                                      /* Isr id */  \
  &OS_isrDynamic_core0[2],                             /* dynamic data */  \
  (OS_ISRF_CAT2|OS_ISRF_ENABLE),                       /* Flags */  \
    OS_ARCHISR_INIT(  \
      &OS_SRC_GTMTIM25,                                    /* Service request node */  \
      7,                                                   /* Arbitration priority */  \
      7                                                    /* Run priority */  \
    )  \
),  \
OS_ISRCONFIG_INIT(    /* GTMTIM1SR5_ISR */  \
  &OS_appTable[OsApplication_C0],                      /* Application */  \
  0x1U,                                                /* Permissions */  \
  OS_NULL,                                             /* Accounting structure */  \
  &OS_TOOL_MR_START(GTMTIM1SR5_ISR),                   /* start of data/bss */  \
  &OS_TOOL_MR_END(GTMTIM1SR5_ISR),                     /* end of data/bss */  \
  &OS_TOOL_MR_LMA_START(GTMTIM1SR5_ISR),               /* start of initial data */  \
  &OS_TOOL_MR_LMA_END(GTMTIM1SR5_ISR),                 /* end of initial data */  \
  &OS_ISR_GTMTIM1SR5_ISR,                              /* Interrupt entry */  \
  0U,                                                  /* Execution budget */  \
  0U,                                                  /* Os interrupt lock budget */  \
  0U,                                                  /* All interrupt lock budget */  \
  OS_NULL,                                             /* Resource lock budget */  \
  512U,                                                /* Stack size */  \
  OS_NULLRATEMONITOR,                                  /* Rate monitor */  \
  GTMTIM1SR5_ISR,                                      /* Isr id */  \
  &OS_isrDynamic_core0[3],                             /* dynamic data */  \
  (OS_ISRF_CAT2|OS_ISRF_ENABLE),                       /* Flags */  \
    OS_ARCHISR_INIT(  \
      &OS_SRC_GTMTIM15,                                    /* Service request node */  \
      8,                                                   /* Arbitration priority */  \
      8                                                    /* Run priority */  \
    )  \
),  \
OS_ISRCONFIG_INIT(    /* DMACH15SR_ISR */  \
  &OS_appTable[OsApplication_C0],                      /* Application */  \
  0x1U,                                                /* Permissions */  \
  OS_NULL,                                             /* Accounting structure */  \
  &OS_TOOL_MR_START(DMACH15SR_ISR),                    /* start of data/bss */  \
  &OS_TOOL_MR_END(DMACH15SR_ISR),                      /* end of data/bss */  \
  &OS_TOOL_MR_LMA_START(DMACH15SR_ISR),                /* start of initial data */  \
  &OS_TOOL_MR_LMA_END(DMACH15SR_ISR),                  /* end of initial data */  \
  &OS_ISR_DMACH15SR_ISR,                               /* Interrupt entry */  \
  0U,                                                  /* Execution budget */  \
  0U,                                                  /* Os interrupt lock budget */  \
  0U,                                                  /* All interrupt lock budget */  \
  OS_NULL,                                             /* Resource lock budget */  \
  512U,                                                /* Stack size */  \
  OS_NULLRATEMONITOR,                                  /* Rate monitor */  \
  DMACH15SR_ISR,                                       /* Isr id */  \
  &OS_isrDynamic_core0[4],                             /* dynamic data */  \
  (OS_ISRF_CAT2|OS_ISRF_ENABLE),                       /* Flags */  \
    OS_ARCHISR_INIT(  \
      &OS_SRC_DMACH15,                                     /* Service request node */  \
      28,                                                  /* Arbitration priority */  \
      28                                                   /* Run priority */  \
    )  \
),  \
OS_ISRCONFIG_INIT(    /* DMACH16SR_ISR */  \
  &OS_appTable[OsApplication_C0],                      /* Application */  \
  0x1U,                                                /* Permissions */  \
  OS_NULL,                                             /* Accounting structure */  \
  &OS_TOOL_MR_START(DMACH16SR_ISR),                    /* start of data/bss */  \
  &OS_TOOL_MR_END(DMACH16SR_ISR),                      /* end of data/bss */  \
  &OS_TOOL_MR_LMA_START(DMACH16SR_ISR),                /* start of initial data */  \
  &OS_TOOL_MR_LMA_END(DMACH16SR_ISR),                  /* end of initial data */  \
  &OS_ISR_DMACH16SR_ISR,                               /* Interrupt entry */  \
  0U,                                                  /* Execution budget */  \
  0U,                                                  /* Os interrupt lock budget */  \
  0U,                                                  /* All interrupt lock budget */  \
  OS_NULL,                                             /* Resource lock budget */  \
  512U,                                                /* Stack size */  \
  OS_NULLRATEMONITOR,                                  /* Rate monitor */  \
  DMACH16SR_ISR,                                       /* Isr id */  \
  &OS_isrDynamic_core0[5],                             /* dynamic data */  \
  (OS_ISRF_CAT2|OS_ISRF_ENABLE),                       /* Flags */  \
    OS_ARCHISR_INIT(  \
      &OS_SRC_DMACH16,                                     /* Service request node */  \
      29,                                                  /* Arbitration priority */  \
      29                                                   /* Run priority */  \
    )  \
),  \
OS_ISRCONFIG_INIT(    /* CAN1SR0_ISR */  \
  &OS_appTable[OsApplication_C0],                      /* Application */  \
  0x1U,                                                /* Permissions */  \
  OS_NULL,                                             /* Accounting structure */  \
  &OS_TOOL_MR_START(CAN1SR0_ISR),                      /* start of data/bss */  \
  &OS_TOOL_MR_END(CAN1SR0_ISR),                        /* end of data/bss */  \
  &OS_TOOL_MR_LMA_START(CAN1SR0_ISR),                  /* start of initial data */  \
  &OS_TOOL_MR_LMA_END(CAN1SR0_ISR),                    /* end of initial data */  \
  &OS_ISR_CAN1SR0_ISR,                                 /* Interrupt entry */  \
  0U,                                                  /* Execution budget */  \
  0U,                                                  /* Os interrupt lock budget */  \
  0U,                                                  /* All interrupt lock budget */  \
  OS_NULL,                                             /* Resource lock budget */  \
  512U,                                                /* Stack size */  \
  OS_NULLRATEMONITOR,                                  /* Rate monitor */  \
  CAN1SR0_ISR,                                         /* Isr id */  \
  &OS_isrDynamic_core0[6],                             /* dynamic data */  \
  (OS_ISRF_CAT2|OS_ISRF_ENABLE),                       /* Flags */  \
    OS_ARCHISR_INIT(  \
      &OS_SRC_CAN1INT0,                                    /* Service request node */  \
      12,                                                  /* Arbitration priority */  \
      12                                                   /* Run priority */  \
    )  \
),  \
OS_ISRCONFIG_INIT(    /* CAN1SR1_ISR */  \
  &OS_appTable[OsApplication_C0],                      /* Application */  \
  0x1U,                                                /* Permissions */  \
  OS_NULL,                                             /* Accounting structure */  \
  &OS_TOOL_MR_START(CAN1SR1_ISR),                      /* start of data/bss */  \
  &OS_TOOL_MR_END(CAN1SR1_ISR),                        /* end of data/bss */  \
  &OS_TOOL_MR_LMA_START(CAN1SR1_ISR),                  /* start of initial data */  \
  &OS_TOOL_MR_LMA_END(CAN1SR1_ISR),                    /* end of initial data */  \
  &OS_ISR_CAN1SR1_ISR,                                 /* Interrupt entry */  \
  0U,                                                  /* Execution budget */  \
  0U,                                                  /* Os interrupt lock budget */  \
  0U,                                                  /* All interrupt lock budget */  \
  OS_NULL,                                             /* Resource lock budget */  \
  512U,                                                /* Stack size */  \
  OS_NULLRATEMONITOR,                                  /* Rate monitor */  \
  CAN1SR1_ISR,                                         /* Isr id */  \
  &OS_isrDynamic_core0[7],                             /* dynamic data */  \
  (OS_ISRF_CAT2|OS_ISRF_ENABLE),                       /* Flags */  \
    OS_ARCHISR_INIT(  \
      &OS_SRC_CAN1INT1,                                    /* Service request node */  \
      13,                                                  /* Arbitration priority */  \
      13                                                   /* Run priority */  \
    )  \
),  \
OS_ISRCONFIG_INIT(    /* CAN1SR2_ISR */  \
  &OS_appTable[OsApplication_C0],                      /* Application */  \
  0x1U,                                                /* Permissions */  \
  OS_NULL,                                             /* Accounting structure */  \
  &OS_TOOL_MR_START(CAN1SR2_ISR),                      /* start of data/bss */  \
  &OS_TOOL_MR_END(CAN1SR2_ISR),                        /* end of data/bss */  \
  &OS_TOOL_MR_LMA_START(CAN1SR2_ISR),                  /* start of initial data */  \
  &OS_TOOL_MR_LMA_END(CAN1SR2_ISR),                    /* end of initial data */  \
  &OS_ISR_CAN1SR2_ISR,                                 /* Interrupt entry */  \
  0U,                                                  /* Execution budget */  \
  0U,                                                  /* Os interrupt lock budget */  \
  0U,                                                  /* All interrupt lock budget */  \
  OS_NULL,                                             /* Resource lock budget */  \
  512U,                                                /* Stack size */  \
  OS_NULLRATEMONITOR,                                  /* Rate monitor */  \
  CAN1SR2_ISR,                                         /* Isr id */  \
  &OS_isrDynamic_core0[8],                             /* dynamic data */  \
  (OS_ISRF_CAT2|OS_ISRF_ENABLE),                       /* Flags */  \
    OS_ARCHISR_INIT(  \
      &OS_SRC_CAN1INT2,                                    /* Service request node */  \
      14,                                                  /* Arbitration priority */  \
      14                                                   /* Run priority */  \
    )  \
),  \
OS_ISRCONFIG_INIT(    /* CAN1SR3_ISR */  \
  &OS_appTable[OsApplication_C0],                      /* Application */  \
  0x1U,                                                /* Permissions */  \
  OS_NULL,                                             /* Accounting structure */  \
  &OS_TOOL_MR_START(CAN1SR3_ISR),                      /* start of data/bss */  \
  &OS_TOOL_MR_END(CAN1SR3_ISR),                        /* end of data/bss */  \
  &OS_TOOL_MR_LMA_START(CAN1SR3_ISR),                  /* start of initial data */  \
  &OS_TOOL_MR_LMA_END(CAN1SR3_ISR),                    /* end of initial data */  \
  &OS_ISR_CAN1SR3_ISR,                                 /* Interrupt entry */  \
  0U,                                                  /* Execution budget */  \
  0U,                                                  /* Os interrupt lock budget */  \
  0U,                                                  /* All interrupt lock budget */  \
  OS_NULL,                                             /* Resource lock budget */  \
  512U,                                                /* Stack size */  \
  OS_NULLRATEMONITOR,                                  /* Rate monitor */  \
  CAN1SR3_ISR,                                         /* Isr id */  \
  &OS_isrDynamic_core0[9],                             /* dynamic data */  \
  (OS_ISRF_CAT2|OS_ISRF_ENABLE),                       /* Flags */  \
    OS_ARCHISR_INIT(  \
      &OS_SRC_CAN1INT3,                                    /* Service request node */  \
      25,                                                  /* Arbitration priority */  \
      25                                                   /* Run priority */  \
    )  \
),  \
OS_ISRCONFIG_INIT(    /* CAN1SR4_ISR */  \
  &OS_appTable[OsApplication_C0],                      /* Application */  \
  0x1U,                                                /* Permissions */  \
  OS_NULL,                                             /* Accounting structure */  \
  &OS_TOOL_MR_START(CAN1SR4_ISR),                      /* start of data/bss */  \
  &OS_TOOL_MR_END(CAN1SR4_ISR),                        /* end of data/bss */  \
  &OS_TOOL_MR_LMA_START(CAN1SR4_ISR),                  /* start of initial data */  \
  &OS_TOOL_MR_LMA_END(CAN1SR4_ISR),                    /* end of initial data */  \
  &OS_ISR_CAN1SR4_ISR,                                 /* Interrupt entry */  \
  0U,                                                  /* Execution budget */  \
  0U,                                                  /* Os interrupt lock budget */  \
  0U,                                                  /* All interrupt lock budget */  \
  OS_NULL,                                             /* Resource lock budget */  \
  512U,                                                /* Stack size */  \
  OS_NULLRATEMONITOR,                                  /* Rate monitor */  \
  CAN1SR4_ISR,                                         /* Isr id */  \
  &OS_isrDynamic_core0[10],                            /* dynamic data */  \
  (OS_ISRF_CAT2|OS_ISRF_ENABLE),                       /* Flags */  \
    OS_ARCHISR_INIT(  \
      &OS_SRC_CAN1INT4,                                    /* Service request node */  \
      15,                                                  /* Arbitration priority */  \
      15                                                   /* Run priority */  \
    )  \
),  \
OS_ISRCONFIG_INIT(    /* CAN1SR5_ISR */  \
  &OS_appTable[OsApplication_C0],                      /* Application */  \
  0x1U,                                                /* Permissions */  \
  OS_NULL,                                             /* Accounting structure */  \
  &OS_TOOL_MR_START(CAN1SR5_ISR),                      /* start of data/bss */  \
  &OS_TOOL_MR_END(CAN1SR5_ISR),                        /* end of data/bss */  \
  &OS_TOOL_MR_LMA_START(CAN1SR5_ISR),                  /* start of initial data */  \
  &OS_TOOL_MR_LMA_END(CAN1SR5_ISR),                    /* end of initial data */  \
  &OS_ISR_CAN1SR5_ISR,                                 /* Interrupt entry */  \
  0U,                                                  /* Execution budget */  \
  0U,                                                  /* Os interrupt lock budget */  \
  0U,                                                  /* All interrupt lock budget */  \
  OS_NULL,                                             /* Resource lock budget */  \
  512U,                                                /* Stack size */  \
  OS_NULLRATEMONITOR,                                  /* Rate monitor */  \
  CAN1SR5_ISR,                                         /* Isr id */  \
  &OS_isrDynamic_core0[11],                            /* dynamic data */  \
  (OS_ISRF_CAT2|OS_ISRF_ENABLE),                       /* Flags */  \
    OS_ARCHISR_INIT(  \
      &OS_SRC_CAN1INT5,                                    /* Service request node */  \
      16,                                                  /* Arbitration priority */  \
      16                                                   /* Run priority */  \
    )  \
),  \
OS_ISRCONFIG_INIT(    /* CAN1SR6_ISR */  \
  &OS_appTable[OsApplication_C0],                      /* Application */  \
  0x1U,                                                /* Permissions */  \
  OS_NULL,                                             /* Accounting structure */  \
  &OS_TOOL_MR_START(CAN1SR6_ISR),                      /* start of data/bss */  \
  &OS_TOOL_MR_END(CAN1SR6_ISR),                        /* end of data/bss */  \
  &OS_TOOL_MR_LMA_START(CAN1SR6_ISR),                  /* start of initial data */  \
  &OS_TOOL_MR_LMA_END(CAN1SR6_ISR),                    /* end of initial data */  \
  &OS_ISR_CAN1SR6_ISR,                                 /* Interrupt entry */  \
  0U,                                                  /* Execution budget */  \
  0U,                                                  /* Os interrupt lock budget */  \
  0U,                                                  /* All interrupt lock budget */  \
  OS_NULL,                                             /* Resource lock budget */  \
  512U,                                                /* Stack size */  \
  OS_NULLRATEMONITOR,                                  /* Rate monitor */  \
  CAN1SR6_ISR,                                         /* Isr id */  \
  &OS_isrDynamic_core0[12],                            /* dynamic data */  \
  (OS_ISRF_CAT2|OS_ISRF_ENABLE),                       /* Flags */  \
    OS_ARCHISR_INIT(  \
      &OS_SRC_CAN1INT6,                                    /* Service request node */  \
      17,                                                  /* Arbitration priority */  \
      17                                                   /* Run priority */  \
    )  \
),  \
OS_ISRCONFIG_INIT(    /* CAN0SR8_ISR */  \
  &OS_appTable[OsApplication_C0],                      /* Application */  \
  0x1U,                                                /* Permissions */  \
  OS_NULL,                                             /* Accounting structure */  \
  &OS_TOOL_MR_START(CAN0SR8_ISR),                      /* start of data/bss */  \
  &OS_TOOL_MR_END(CAN0SR8_ISR),                        /* end of data/bss */  \
  &OS_TOOL_MR_LMA_START(CAN0SR8_ISR),                  /* start of initial data */  \
  &OS_TOOL_MR_LMA_END(CAN0SR8_ISR),                    /* end of initial data */  \
  &OS_ISR_CAN0SR8_ISR,                                 /* Interrupt entry */  \
  0U,                                                  /* Execution budget */  \
  0U,                                                  /* Os interrupt lock budget */  \
  0U,                                                  /* All interrupt lock budget */  \
  OS_NULL,                                             /* Resource lock budget */  \
  512U,                                                /* Stack size */  \
  OS_NULLRATEMONITOR,                                  /* Rate monitor */  \
  CAN0SR8_ISR,                                         /* Isr id */  \
  &OS_isrDynamic_core0[13],                            /* dynamic data */  \
  (OS_ISRF_CAT2|OS_ISRF_ENABLE),                       /* Flags */  \
    OS_ARCHISR_INIT(  \
      &OS_SRC_CAN0INT8,                                    /* Service request node */  \
      18,                                                  /* Arbitration priority */  \
      18                                                   /* Run priority */  \
    )  \
),  \
OS_ISRCONFIG_INIT(    /* CAN0SR9_ISR */  \
  &OS_appTable[OsApplication_C0],                      /* Application */  \
  0x1U,                                                /* Permissions */  \
  OS_NULL,                                             /* Accounting structure */  \
  &OS_TOOL_MR_START(CAN0SR9_ISR),                      /* start of data/bss */  \
  &OS_TOOL_MR_END(CAN0SR9_ISR),                        /* end of data/bss */  \
  &OS_TOOL_MR_LMA_START(CAN0SR9_ISR),                  /* start of initial data */  \
  &OS_TOOL_MR_LMA_END(CAN0SR9_ISR),                    /* end of initial data */  \
  &OS_ISR_CAN0SR9_ISR,                                 /* Interrupt entry */  \
  0U,                                                  /* Execution budget */  \
  0U,                                                  /* Os interrupt lock budget */  \
  0U,                                                  /* All interrupt lock budget */  \
  OS_NULL,                                             /* Resource lock budget */  \
  512U,                                                /* Stack size */  \
  OS_NULLRATEMONITOR,                                  /* Rate monitor */  \
  CAN0SR9_ISR,                                         /* Isr id */  \
  &OS_isrDynamic_core0[14],                            /* dynamic data */  \
  (OS_ISRF_CAT2|OS_ISRF_ENABLE),                       /* Flags */  \
    OS_ARCHISR_INIT(  \
      &OS_SRC_CAN0INT9,                                    /* Service request node */  \
      19,                                                  /* Arbitration priority */  \
      19                                                   /* Run priority */  \
    )  \
),  \
OS_ISRCONFIG_INIT(    /* CAN0SR10_ISR */  \
  &OS_appTable[OsApplication_C0],                      /* Application */  \
  0x1U,                                                /* Permissions */  \
  OS_NULL,                                             /* Accounting structure */  \
  &OS_TOOL_MR_START(CAN0SR10_ISR),                     /* start of data/bss */  \
  &OS_TOOL_MR_END(CAN0SR10_ISR),                       /* end of data/bss */  \
  &OS_TOOL_MR_LMA_START(CAN0SR10_ISR),                 /* start of initial data */  \
  &OS_TOOL_MR_LMA_END(CAN0SR10_ISR),                   /* end of initial data */  \
  &OS_ISR_CAN0SR10_ISR,                                /* Interrupt entry */  \
  0U,                                                  /* Execution budget */  \
  0U,                                                  /* Os interrupt lock budget */  \
  0U,                                                  /* All interrupt lock budget */  \
  OS_NULL,                                             /* Resource lock budget */  \
  512U,                                                /* Stack size */  \
  OS_NULLRATEMONITOR,                                  /* Rate monitor */  \
  CAN0SR10_ISR,                                        /* Isr id */  \
  &OS_isrDynamic_core0[15],                            /* dynamic data */  \
  (OS_ISRF_CAT2|OS_ISRF_ENABLE),                       /* Flags */  \
    OS_ARCHISR_INIT(  \
      &OS_SRC_CAN0INT10,                                   /* Service request node */  \
      20,                                                  /* Arbitration priority */  \
      20                                                   /* Run priority */  \
    )  \
),  \
OS_ISRCONFIG_INIT(    /* CAN0SR12_ISR */  \
  &OS_appTable[OsApplication_C0],                      /* Application */  \
  0x1U,                                                /* Permissions */  \
  OS_NULL,                                             /* Accounting structure */  \
  &OS_TOOL_MR_START(CAN0SR12_ISR),                     /* start of data/bss */  \
  &OS_TOOL_MR_END(CAN0SR12_ISR),                       /* end of data/bss */  \
  &OS_TOOL_MR_LMA_START(CAN0SR12_ISR),                 /* start of initial data */  \
  &OS_TOOL_MR_LMA_END(CAN0SR12_ISR),                   /* end of initial data */  \
  &OS_ISR_CAN0SR12_ISR,                                /* Interrupt entry */  \
  0U,                                                  /* Execution budget */  \
  0U,                                                  /* Os interrupt lock budget */  \
  0U,                                                  /* All interrupt lock budget */  \
  OS_NULL,                                             /* Resource lock budget */  \
  512U,                                                /* Stack size */  \
  OS_NULLRATEMONITOR,                                  /* Rate monitor */  \
  CAN0SR12_ISR,                                        /* Isr id */  \
  &OS_isrDynamic_core0[16],                            /* dynamic data */  \
  (OS_ISRF_CAT2|OS_ISRF_ENABLE),                       /* Flags */  \
    OS_ARCHISR_INIT(  \
      &OS_SRC_CAN0INT12,                                   /* Service request node */  \
      21,                                                  /* Arbitration priority */  \
      21                                                   /* Run priority */  \
    )  \
),  \
OS_ISRCONFIG_INIT(    /* CAN0SR13_ISR */  \
  &OS_appTable[OsApplication_C0],                      /* Application */  \
  0x1U,                                                /* Permissions */  \
  OS_NULL,                                             /* Accounting structure */  \
  &OS_TOOL_MR_START(CAN0SR13_ISR),                     /* start of data/bss */  \
  &OS_TOOL_MR_END(CAN0SR13_ISR),                       /* end of data/bss */  \
  &OS_TOOL_MR_LMA_START(CAN0SR13_ISR),                 /* start of initial data */  \
  &OS_TOOL_MR_LMA_END(CAN0SR13_ISR),                   /* end of initial data */  \
  &OS_ISR_CAN0SR13_ISR,                                /* Interrupt entry */  \
  0U,                                                  /* Execution budget */  \
  0U,                                                  /* Os interrupt lock budget */  \
  0U,                                                  /* All interrupt lock budget */  \
  OS_NULL,                                             /* Resource lock budget */  \
  512U,                                                /* Stack size */  \
  OS_NULLRATEMONITOR,                                  /* Rate monitor */  \
  CAN0SR13_ISR,                                        /* Isr id */  \
  &OS_isrDynamic_core0[17],                            /* dynamic data */  \
  (OS_ISRF_CAT2|OS_ISRF_ENABLE),                       /* Flags */  \
    OS_ARCHISR_INIT(  \
      &OS_SRC_CAN0INT13,                                   /* Service request node */  \
      22,                                                  /* Arbitration priority */  \
      22                                                   /* Run priority */  \
    )  \
),  \
OS_ISRCONFIG_INIT(    /* CAN0SR14_ISR */  \
  &OS_appTable[OsApplication_C0],                      /* Application */  \
  0x1U,                                                /* Permissions */  \
  OS_NULL,                                             /* Accounting structure */  \
  &OS_TOOL_MR_START(CAN0SR14_ISR),                     /* start of data/bss */  \
  &OS_TOOL_MR_END(CAN0SR14_ISR),                       /* end of data/bss */  \
  &OS_TOOL_MR_LMA_START(CAN0SR14_ISR),                 /* start of initial data */  \
  &OS_TOOL_MR_LMA_END(CAN0SR14_ISR),                   /* end of initial data */  \
  &OS_ISR_CAN0SR14_ISR,                                /* Interrupt entry */  \
  0U,                                                  /* Execution budget */  \
  0U,                                                  /* Os interrupt lock budget */  \
  0U,                                                  /* All interrupt lock budget */  \
  OS_NULL,                                             /* Resource lock budget */  \
  512U,                                                /* Stack size */  \
  OS_NULLRATEMONITOR,                                  /* Rate monitor */  \
  CAN0SR14_ISR,                                        /* Isr id */  \
  &OS_isrDynamic_core0[18],                            /* dynamic data */  \
  (OS_ISRF_CAT2|OS_ISRF_ENABLE),                       /* Flags */  \
    OS_ARCHISR_INIT(  \
      &OS_SRC_CAN0INT14,                                   /* Service request node */  \
      23,                                                  /* Arbitration priority */  \
      23                                                   /* Run priority */  \
    )  \
),  \
OS_ISRCONFIG_INIT(    /* HSCT0_ISR */  \
  &OS_appTable[OsApplication_C0],                      /* Application */  \
  0x1U,                                                /* Permissions */  \
  OS_NULL,                                             /* Accounting structure */  \
  &OS_TOOL_MR_START(HSCT0_ISR),                        /* start of data/bss */  \
  &OS_TOOL_MR_END(HSCT0_ISR),                          /* end of data/bss */  \
  &OS_TOOL_MR_LMA_START(HSCT0_ISR),                    /* start of initial data */  \
  &OS_TOOL_MR_LMA_END(HSCT0_ISR),                      /* end of initial data */  \
  &OS_ISR_HSCT0_ISR,                                   /* Interrupt entry */  \
  0U,                                                  /* Execution budget */  \
  0U,                                                  /* Os interrupt lock budget */  \
  0U,                                                  /* All interrupt lock budget */  \
  OS_NULL,                                             /* Resource lock budget */  \
  4096U,                                               /* Stack size */  \
  OS_NULLRATEMONITOR,                                  /* Rate monitor */  \
  HSCT0_ISR,                                           /* Isr id */  \
  &OS_isrDynamic_core0[19],                            /* dynamic data */  \
  (OS_ISRF_CAT2|OS_ISRF_ENABLE),                       /* Flags */  \
    OS_ARCHISR_INIT(  \
      &OS_SRC_HSCT0,                                       /* Service request node */  \
      24,                                                  /* Arbitration priority */  \
      24                                                   /* Run priority */  \
    )  \
),  \
OS_ISRCONFIG_INIT(    /* HSSL0COK0_ISR */  \
  &OS_appTable[OsApplication_C0],                      /* Application */  \
  0x1U,                                                /* Permissions */  \
  OS_NULL,                                             /* Accounting structure */  \
  &OS_TOOL_MR_START(HSSL0COK0_ISR),                    /* start of data/bss */  \
  &OS_TOOL_MR_END(HSSL0COK0_ISR),                      /* end of data/bss */  \
  &OS_TOOL_MR_LMA_START(HSSL0COK0_ISR),                /* start of initial data */  \
  &OS_TOOL_MR_LMA_END(HSSL0COK0_ISR),                  /* end of initial data */  \
  &OS_ISR_HSSL0COK0_ISR,                               /* Interrupt entry */  \
  0U,                                                  /* Execution budget */  \
  0U,                                                  /* Os interrupt lock budget */  \
  0U,                                                  /* All interrupt lock budget */  \
  OS_NULL,                                             /* Resource lock budget */  \
  4096U,                                               /* Stack size */  \
  OS_NULLRATEMONITOR,                                  /* Rate monitor */  \
  HSSL0COK0_ISR,                                       /* Isr id */  \
  &OS_isrDynamic_core0[20],                            /* dynamic data */  \
  (OS_ISRF_CAT2|OS_ISRF_ENABLE),                       /* Flags */  \
    OS_ARCHISR_INIT(  \
      &OS_SRC_HSSL0COK0,                                   /* Service request node */  \
      31,                                                  /* Arbitration priority */  \
      31                                                   /* Run priority */  \
    )  \
),  \
OS_ISRCONFIG_INIT(    /* HSSL0COK2_ISR */  \
  &OS_appTable[OsApplication_C0],                      /* Application */  \
  0x1U,                                                /* Permissions */  \
  OS_NULL,                                             /* Accounting structure */  \
  &OS_TOOL_MR_START(HSSL0COK2_ISR),                    /* start of data/bss */  \
  &OS_TOOL_MR_END(HSSL0COK2_ISR),                      /* end of data/bss */  \
  &OS_TOOL_MR_LMA_START(HSSL0COK2_ISR),                /* start of initial data */  \
  &OS_TOOL_MR_LMA_END(HSSL0COK2_ISR),                  /* end of initial data */  \
  &OS_ISR_HSSL0COK2_ISR,                               /* Interrupt entry */  \
  0U,                                                  /* Execution budget */  \
  0U,                                                  /* Os interrupt lock budget */  \
  0U,                                                  /* All interrupt lock budget */  \
  OS_NULL,                                             /* Resource lock budget */  \
  4096U,                                               /* Stack size */  \
  OS_NULLRATEMONITOR,                                  /* Rate monitor */  \
  HSSL0COK2_ISR,                                       /* Isr id */  \
  &OS_isrDynamic_core0[21],                            /* dynamic data */  \
  (OS_ISRF_CAT2|OS_ISRF_ENABLE),                       /* Flags */  \
    OS_ARCHISR_INIT(  \
      &OS_SRC_HSSL0COK2,                                   /* Service request node */  \
      30,                                                  /* Arbitration priority */  \
      30                                                   /* Run priority */  \
    )  \
),  \
OS_ISRCONFIG_INIT(    /* DMACH0SR_ISR */  \
  &OS_appTable[OsApplication_C0],                      /* Application */  \
  0x1U,                                                /* Permissions */  \
  OS_NULL,                                             /* Accounting structure */  \
  &OS_TOOL_MR_START(DMACH0SR_ISR),                     /* start of data/bss */  \
  &OS_TOOL_MR_END(DMACH0SR_ISR),                       /* end of data/bss */  \
  &OS_TOOL_MR_LMA_START(DMACH0SR_ISR),                 /* start of initial data */  \
  &OS_TOOL_MR_LMA_END(DMACH0SR_ISR),                   /* end of initial data */  \
  &OS_ISR_DMACH0SR_ISR,                                /* Interrupt entry */  \
  0U,                                                  /* Execution budget */  \
  0U,                                                  /* Os interrupt lock budget */  \
  0U,                                                  /* All interrupt lock budget */  \
  OS_NULL,                                             /* Resource lock budget */  \
  512U,                                                /* Stack size */  \
  OS_NULLRATEMONITOR,                                  /* Rate monitor */  \
  DMACH0SR_ISR,                                        /* Isr id */  \
  &OS_isrDynamic_core0[22],                            /* dynamic data */  \
  (OS_ISRF_CAT2|OS_ISRF_ENABLE),                       /* Flags */  \
    OS_ARCHISR_INIT(  \
      &OS_SRC_DMACH0,                                      /* Service request node */  \
      5,                                                   /* Arbitration priority */  \
      5                                                    /* Run priority */  \
    )  \
),  \
OS_ISRCONFIG_INIT(    /* DMACH1SR_ISR */  \
  &OS_appTable[OsApplication_C0],                      /* Application */  \
  0x1U,                                                /* Permissions */  \
  OS_NULL,                                             /* Accounting structure */  \
  &OS_TOOL_MR_START(DMACH1SR_ISR),                     /* start of data/bss */  \
  &OS_TOOL_MR_END(DMACH1SR_ISR),                       /* end of data/bss */  \
  &OS_TOOL_MR_LMA_START(DMACH1SR_ISR),                 /* start of initial data */  \
  &OS_TOOL_MR_LMA_END(DMACH1SR_ISR),                   /* end of initial data */  \
  &OS_ISR_DMACH1SR_ISR,                                /* Interrupt entry */  \
  0U,                                                  /* Execution budget */  \
  0U,                                                  /* Os interrupt lock budget */  \
  0U,                                                  /* All interrupt lock budget */  \
  OS_NULL,                                             /* Resource lock budget */  \
  512U,                                                /* Stack size */  \
  OS_NULLRATEMONITOR,                                  /* Rate monitor */  \
  DMACH1SR_ISR,                                        /* Isr id */  \
  &OS_isrDynamic_core0[23],                            /* dynamic data */  \
  (OS_ISRF_CAT2|OS_ISRF_ENABLE),                       /* Flags */  \
    OS_ARCHISR_INIT(  \
      &OS_SRC_DMACH1,                                      /* Service request node */  \
      6,                                                   /* Arbitration priority */  \
      6                                                    /* Run priority */  \
    )  \
),  \
OS_ISRCONFIG_INIT(    /* GTMTOM2SR3_ISR */  \
  &OS_appTable[OsApplication_C0],                      /* Application */  \
  0x1U,                                                /* Permissions */  \
  OS_NULL,                                             /* Accounting structure */  \
  &OS_TOOL_MR_START(GTMTOM2SR3_ISR),                   /* start of data/bss */  \
  &OS_TOOL_MR_END(GTMTOM2SR3_ISR),                     /* end of data/bss */  \
  &OS_TOOL_MR_LMA_START(GTMTOM2SR3_ISR),               /* start of initial data */  \
  &OS_TOOL_MR_LMA_END(GTMTOM2SR3_ISR),                 /* end of initial data */  \
  &OS_ISR_GTMTOM2SR3_ISR,                              /* Interrupt entry */  \
  0U,                                                  /* Execution budget */  \
  0U,                                                  /* Os interrupt lock budget */  \
  0U,                                                  /* All interrupt lock budget */  \
  OS_NULL,                                             /* Resource lock budget */  \
  512U,                                                /* Stack size */  \
  OS_NULLRATEMONITOR,                                  /* Rate monitor */  \
  GTMTOM2SR3_ISR,                                      /* Isr id */  \
  &OS_isrDynamic_core0[24],                            /* dynamic data */  \
  (OS_ISRF_CAT2|OS_ISRF_ENABLE),                       /* Flags */  \
    OS_ARCHISR_INIT(  \
      &OS_SRC_GTMATOM23,                                   /* Service request node */  \
      9,                                                   /* Arbitration priority */  \
      9                                                    /* Run priority */  \
    )  \
),  \
OS_ISRCONFIG_INIT(    /* GTMTIM3SR4_ISR */  \
  &OS_appTable[OsApplication_C0],                      /* Application */  \
  0x1U,                                                /* Permissions */  \
  OS_NULL,                                             /* Accounting structure */  \
  &OS_TOOL_MR_START(GTMTIM3SR4_ISR),                   /* start of data/bss */  \
  &OS_TOOL_MR_END(GTMTIM3SR4_ISR),                     /* end of data/bss */  \
  &OS_TOOL_MR_LMA_START(GTMTIM3SR4_ISR),               /* start of initial data */  \
  &OS_TOOL_MR_LMA_END(GTMTIM3SR4_ISR),                 /* end of initial data */  \
  &OS_ISR_GTMTIM3SR4_ISR,                              /* Interrupt entry */  \
  0U,                                                  /* Execution budget */  \
  0U,                                                  /* Os interrupt lock budget */  \
  0U,                                                  /* All interrupt lock budget */  \
  OS_NULL,                                             /* Resource lock budget */  \
  2048U,                                               /* Stack size */  \
  OS_NULLRATEMONITOR,                                  /* Rate monitor */  \
  GTMTIM3SR4_ISR,                                      /* Isr id */  \
  &OS_isrDynamic_core0[25],                            /* dynamic data */  \
  (OS_ISRF_CAT2|OS_ISRF_ENABLE),                       /* Flags */  \
    OS_ARCHISR_INIT(  \
      &OS_SRC_GTMTIM34,                                    /* Service request node */  \
      11,                                                  /* Arbitration priority */  \
      11                                                   /* Run priority */  \
    )  \
),  \
OS_ISRCONFIG_INIT(    /* DMAERR0SR_ISR */  \
  &OS_appTable[OsApplication_C0],                      /* Application */  \
  0x1U,                                                /* Permissions */  \
  OS_NULL,                                             /* Accounting structure */  \
  &OS_TOOL_MR_START(DMAERR0SR_ISR),                    /* start of data/bss */  \
  &OS_TOOL_MR_END(DMAERR0SR_ISR),                      /* end of data/bss */  \
  &OS_TOOL_MR_LMA_START(DMAERR0SR_ISR),                /* start of initial data */  \
  &OS_TOOL_MR_LMA_END(DMAERR0SR_ISR),                  /* end of initial data */  \
  &OS_ISR_DMAERR0SR_ISR,                               /* Interrupt entry */  \
  0U,                                                  /* Execution budget */  \
  0U,                                                  /* Os interrupt lock budget */  \
  0U,                                                  /* All interrupt lock budget */  \
  OS_NULL,                                             /* Resource lock budget */  \
  512U,                                                /* Stack size */  \
  OS_NULLRATEMONITOR,                                  /* Rate monitor */  \
  DMAERR0SR_ISR,                                       /* Isr id */  \
  &OS_isrDynamic_core0[26],                            /* dynamic data */  \
  (OS_ISRF_CAT2|OS_ISRF_ENABLE),                       /* Flags */  \
    OS_ARCHISR_INIT(  \
      &OS_SRC_DMAERR0,                                     /* Service request node */  \
      10,                                                  /* Arbitration priority */  \
      10                                                   /* Run priority */  \
    )  \
),  \
OS_ISRCONFIG_INIT(    /* CrossCoreNotify0 */  \
  &OS_appTable[OS_SYSTEM_0],                           /* Application */  \
  0xffU,                                               /* Permissions */  \
  OS_NULL,                                             /* Accounting structure */  \
  OS_NULL,                                             /* start of data/bss */  \
  OS_NULL,                                             /* end of data/bss */  \
  OS_NULL,                                             /* start of initial data */  \
  OS_NULL,                                             /* start of initial data */  \
  &OS_NullFunction,                                    /* Interrupt entry */  \
  0U,                                                  /* Execution budget */  \
  0U,                                                  /* Os interrupt lock budget */  \
  0U,                                                  /* All interrupt lock budget */  \
  OS_NULL,                                             /* Resource lock budget */  \
  200U,                                                /* Stack size */  \
  OS_NULLRATEMONITOR,                                  /* Rate monitor */  \
  CrossCoreNotify0,                                    /* Isr id */  \
  &OS_isrDynamic_core0[27],                            /* dynamic data */  \
  (OS_ISRF_CATK|OS_ISRF_CROSSCORE|OS_ISRF_ENABLE),     /* Flags */  \
    OS_ARCHISR_INIT(  \
      &OS_SRC_GPSR20,                                      /* Service request node */  \
      35,                                                  /* Arbitration priority */  \
      35                                                   /* Run priority */  \
    )  \
),  \
OS_ISRCONFIG_INIT(    /* CrossCoreNotify1 */  \
  &OS_appTable[OS_SYSTEM_1],                           /* Application */  \
  0xffU,                                               /* Permissions */  \
  OS_NULL,                                             /* Accounting structure */  \
  OS_NULL,                                             /* start of data/bss */  \
  OS_NULL,                                             /* end of data/bss */  \
  OS_NULL,                                             /* start of initial data */  \
  OS_NULL,                                             /* start of initial data */  \
  &OS_NullFunction,                                    /* Interrupt entry */  \
  0U,                                                  /* Execution budget */  \
  0U,                                                  /* Os interrupt lock budget */  \
  0U,                                                  /* All interrupt lock budget */  \
  OS_NULL,                                             /* Resource lock budget */  \
  200U,                                                /* Stack size */  \
  OS_NULLRATEMONITOR,                                  /* Rate monitor */  \
  CrossCoreNotify1,                                    /* Isr id */  \
  &OS_isrDynamic_core1[0],                             /* dynamic data */  \
  (OS_ISRF_CATK|OS_ISRF_CROSSCORE|OS_ISRF_ENABLE),     /* Flags */  \
    OS_ARCHISR_INIT(  \
      &OS_SRC_GPSR21,                                      /* Service request node */  \
      35,                                                  /* Arbitration priority */  \
      35                                                   /* Run priority */  \
    )  \
),  \
OS_ISRCONFIG_INIT(    /* CrossCoreNotify2 */  \
  &OS_appTable[OS_SYSTEM_2],                           /* Application */  \
  0xffU,                                               /* Permissions */  \
  OS_NULL,                                             /* Accounting structure */  \
  OS_NULL,                                             /* start of data/bss */  \
  OS_NULL,                                             /* end of data/bss */  \
  OS_NULL,                                             /* start of initial data */  \
  OS_NULL,                                             /* start of initial data */  \
  &OS_NullFunction,                                    /* Interrupt entry */  \
  0U,                                                  /* Execution budget */  \
  0U,                                                  /* Os interrupt lock budget */  \
  0U,                                                  /* All interrupt lock budget */  \
  OS_NULL,                                             /* Resource lock budget */  \
  200U,                                                /* Stack size */  \
  OS_NULLRATEMONITOR,                                  /* Rate monitor */  \
  CrossCoreNotify2,                                    /* Isr id */  \
  &OS_isrDynamic_core2[0],                             /* dynamic data */  \
  (OS_ISRF_CATK|OS_ISRF_CROSSCORE|OS_ISRF_ENABLE),     /* Flags */  \
    OS_ARCHISR_INIT(  \
      &OS_SRC_GPSR22,                                      /* Service request node */  \
      35,                                                  /* Arbitration priority */  \
      35                                                   /* Run priority */  \
    )  \
),  \
OS_ISRCONFIG_INIT(    /* CrossCoreNotify3 */  \
  &OS_appTable[OS_SYSTEM_3],                           /* Application */  \
  0xffU,                                               /* Permissions */  \
  OS_NULL,                                             /* Accounting structure */  \
  OS_NULL,                                             /* start of data/bss */  \
  OS_NULL,                                             /* end of data/bss */  \
  OS_NULL,                                             /* start of initial data */  \
  OS_NULL,                                             /* start of initial data */  \
  &OS_NullFunction,                                    /* Interrupt entry */  \
  0U,                                                  /* Execution budget */  \
  0U,                                                  /* Os interrupt lock budget */  \
  0U,                                                  /* All interrupt lock budget */  \
  OS_NULL,                                             /* Resource lock budget */  \
  200U,                                                /* Stack size */  \
  OS_NULLRATEMONITOR,                                  /* Rate monitor */  \
  CrossCoreNotify3,                                    /* Isr id */  \
  &OS_isrDynamic_core3[0],                             /* dynamic data */  \
  (OS_ISRF_CATK|OS_ISRF_CROSSCORE|OS_ISRF_ENABLE),     /* Flags */  \
    OS_ARCHISR_INIT(  \
      &OS_SRC_GPSR37,                                      /* Service request node */  \
      35,                                                  /* Arbitration priority */  \
      35                                                   /* Run priority */  \
    )  \
),  \
OS_ISRCONFIG_INIT(    /* Os_Counter_STM0_T0 */  \
  &OS_appTable[OS_SYSTEM_0],                           /* Application */  \
  0xffU,                                               /* Permissions */  \
  OS_NULL,                                             /* Accounting structure */  \
  OS_NULL,                                             /* start of data/bss */  \
  OS_NULL,                                             /* end of data/bss */  \
  OS_NULL,                                             /* start of initial data */  \
  OS_NULL,                                             /* start of initial data */  \
  &OS_CounterIsr_HwCounter_C0,                         /* Interrupt entry */  \
  0U,                                                  /* Execution budget */  \
  0U,                                                  /* Os interrupt lock budget */  \
  0U,                                                  /* All interrupt lock budget */  \
  OS_NULL,                                             /* Resource lock budget */  \
  160U,                                                /* Stack size */  \
  OS_NULLRATEMONITOR,                                  /* Rate monitor */  \
  Os_Counter_STM0_T0,                                  /* Isr id */  \
  &OS_isrDynamic_core0[28],                            /* dynamic data */  \
  (OS_ISRF_CAT2|OS_ISRF_ENABLE),                       /* Flags */  \
    OS_ARCHISR_INIT(  \
      &OS_SRC_STM0SR0,                                     /* Service request node */  \
      1,                                                   /* Arbitration priority */  \
      4                                                    /* Run priority */  \
    )  \
),  \
OS_ISRCONFIG_INIT(    /* Os_Counter_STM0_T1 */  \
  &OS_appTable[OS_SYSTEM_1],                           /* Application */  \
  0xffU,                                               /* Permissions */  \
  OS_NULL,                                             /* Accounting structure */  \
  OS_NULL,                                             /* start of data/bss */  \
  OS_NULL,                                             /* end of data/bss */  \
  OS_NULL,                                             /* start of initial data */  \
  OS_NULL,                                             /* start of initial data */  \
  &OS_CounterIsr_HwCounter_C1,                         /* Interrupt entry */  \
  0U,                                                  /* Execution budget */  \
  0U,                                                  /* Os interrupt lock budget */  \
  0U,                                                  /* All interrupt lock budget */  \
  OS_NULL,                                             /* Resource lock budget */  \
  160U,                                                /* Stack size */  \
  OS_NULLRATEMONITOR,                                  /* Rate monitor */  \
  Os_Counter_STM0_T1,                                  /* Isr id */  \
  &OS_isrDynamic_core1[1],                             /* dynamic data */  \
  (OS_ISRF_CAT2|OS_ISRF_ENABLE),                       /* Flags */  \
    OS_ARCHISR_INIT(  \
      &OS_SRC_STM0SR1,                                     /* Service request node */  \
      2,                                                   /* Arbitration priority */  \
      4                                                    /* Run priority */  \
    )  \
),  \
OS_ISRCONFIG_INIT(    /* Os_Counter_STM1_T0 */  \
  &OS_appTable[OS_SYSTEM_2],                           /* Application */  \
  0xffU,                                               /* Permissions */  \
  OS_NULL,                                             /* Accounting structure */  \
  OS_NULL,                                             /* start of data/bss */  \
  OS_NULL,                                             /* end of data/bss */  \
  OS_NULL,                                             /* start of initial data */  \
  OS_NULL,                                             /* start of initial data */  \
  &OS_CounterIsr_HwCounter_C2,                         /* Interrupt entry */  \
  0U,                                                  /* Execution budget */  \
  0U,                                                  /* Os interrupt lock budget */  \
  0U,                                                  /* All interrupt lock budget */  \
  OS_NULL,                                             /* Resource lock budget */  \
  160U,                                                /* Stack size */  \
  OS_NULLRATEMONITOR,                                  /* Rate monitor */  \
  Os_Counter_STM1_T0,                                  /* Isr id */  \
  &OS_isrDynamic_core2[1],                             /* dynamic data */  \
  (OS_ISRF_CAT2|OS_ISRF_ENABLE),                       /* Flags */  \
    OS_ARCHISR_INIT(  \
      &OS_SRC_STM1SR0,                                     /* Service request node */  \
      3,                                                   /* Arbitration priority */  \
      4                                                    /* Run priority */  \
    )  \
),  \
OS_ISRCONFIG_INIT(    /* Os_Counter_STM1_T1 */  \
  &OS_appTable[OS_SYSTEM_3],                           /* Application */  \
  0xffU,                                               /* Permissions */  \
  OS_NULL,                                             /* Accounting structure */  \
  OS_NULL,                                             /* start of data/bss */  \
  OS_NULL,                                             /* end of data/bss */  \
  OS_NULL,                                             /* start of initial data */  \
  OS_NULL,                                             /* start of initial data */  \
  &OS_CounterIsr_HwCounter_C3,                         /* Interrupt entry */  \
  0U,                                                  /* Execution budget */  \
  0U,                                                  /* Os interrupt lock budget */  \
  0U,                                                  /* All interrupt lock budget */  \
  OS_NULL,                                             /* Resource lock budget */  \
  160U,                                                /* Stack size */  \
  OS_NULLRATEMONITOR,                                  /* Rate monitor */  \
  Os_Counter_STM1_T1,                                  /* Isr id */  \
  &OS_isrDynamic_core3[1],                             /* dynamic data */  \
  (OS_ISRF_CAT2|OS_ISRF_ENABLE),                       /* Flags */  \
    OS_ARCHISR_INIT(  \
      &OS_SRC_STM1SR1,                                     /* Service request node */  \
      4,                                                   /* Arbitration priority */  \
      4                                                    /* Run priority */  \
    )  \
),
#define OS_ISTACKBASE_0 OS_kernStack0
#define OS_ISTACKLEN_0 OS_U( 31936 )
#define OS_ISTACKBASE_1 OS_kernStack1
#define OS_ISTACKLEN_1 OS_U( 1104 )
#define OS_ISTACKBASE_2 OS_kernStack2
#define OS_ISTACKLEN_2 OS_U( 1104 )
#define OS_ISTACKBASE_3 OS_kernStack3
#define OS_ISTACKLEN_3 OS_U( 1104 )
#define OS_NINTERRUPTS_CORE0 29
#define OS_NISRACCOUNTING_CORE0 0
#define OS_NINTERRUPTS_CORE1 2
#define OS_NISRACCOUNTING_CORE1 0
#define OS_NINTERRUPTS_CORE2 2
#define OS_NISRACCOUNTING_CORE2 0
#define OS_NINTERRUPTS_CORE3 2
#define OS_NISRACCOUNTING_CORE3 0

/*===================================================================
 * Kernel data
 *==================================================================*/

#define OS_KERNELDATA_INIT_CORE0     /* kernel data core 0 */  \
  OS_NULL,                                             /* taskQueueHead */  \
  OS_NULL,                                             /* taskCurrent */  \
  OS_GetInitialStackPointer(OS_ISTACKBASE_0, OS_ISTACKLEN_0),  /* iSpInitial */  \
  OS_NULL,                                             /* hookApp */  \
  0,                                                   /* inKernel */  \
  IDLE_NO_HALT,                                        /* idleMode */  \
  0,                                                   /* inFunction */  \
  0,                                                   /* tfCalledFrom */  \
  OS_ISTACKBASE_0,                                     /* iStackBase */  \
  OS_ISTACKLEN_0,                                      /* iStackLen */  \
  OS_NULLISR,                                          /* isrCurrent */  \
  OS_NULLOBJECT,                                       /* isrLastLock */  \
  0,                                                   /* oldSuspendOs */  \
  0,                                                   /* oldSuspendAll */  \
  0,                                                   /* nestSuspendOs */  \
  0,                                                   /* nestSuspendAll */  \
  OS_ERRORSTATUS_INIT,                                 /* errorStatus */  \
  OS_HOOKCONTEXT_INIT,                                 /* sHookContext */  \
  OS_HOOKCONTEXT_INIT,                                 /* eHookContext */  \
  0,                                                   /* errorHookNesting */  \
  OS_ACCOUNTINGS_INIT,                                 /* accounting */  \
  0,                                                   /* appsStarted */  \
  OS_PANIC_NONE                                        /* panicCode */
#define OS_KERNELDATA_INIT_CORE1     /* kernel data core 1 */  \
  OS_NULL,                                             /* taskQueueHead */  \
  OS_NULL,                                             /* taskCurrent */  \
  OS_GetInitialStackPointer(OS_ISTACKBASE_1, OS_ISTACKLEN_1),  /* iSpInitial */  \
  OS_NULL,                                             /* hookApp */  \
  0,                                                   /* inKernel */  \
  IDLE_NO_HALT,                                        /* idleMode */  \
  0,                                                   /* inFunction */  \
  0,                                                   /* tfCalledFrom */  \
  OS_ISTACKBASE_1,                                     /* iStackBase */  \
  OS_ISTACKLEN_1,                                      /* iStackLen */  \
  OS_NULLISR,                                          /* isrCurrent */  \
  OS_NULLOBJECT,                                       /* isrLastLock */  \
  0,                                                   /* oldSuspendOs */  \
  0,                                                   /* oldSuspendAll */  \
  0,                                                   /* nestSuspendOs */  \
  0,                                                   /* nestSuspendAll */  \
  OS_ERRORSTATUS_INIT,                                 /* errorStatus */  \
  OS_HOOKCONTEXT_INIT,                                 /* sHookContext */  \
  OS_HOOKCONTEXT_INIT,                                 /* eHookContext */  \
  0,                                                   /* errorHookNesting */  \
  OS_ACCOUNTINGS_INIT,                                 /* accounting */  \
  0,                                                   /* appsStarted */  \
  OS_PANIC_NONE                                        /* panicCode */
#define OS_KERNELDATA_INIT_CORE2     /* kernel data core 2 */  \
  OS_NULL,                                             /* taskQueueHead */  \
  OS_NULL,                                             /* taskCurrent */  \
  OS_GetInitialStackPointer(OS_ISTACKBASE_2, OS_ISTACKLEN_2),  /* iSpInitial */  \
  OS_NULL,                                             /* hookApp */  \
  0,                                                   /* inKernel */  \
  IDLE_NO_HALT,                                        /* idleMode */  \
  0,                                                   /* inFunction */  \
  0,                                                   /* tfCalledFrom */  \
  OS_ISTACKBASE_2,                                     /* iStackBase */  \
  OS_ISTACKLEN_2,                                      /* iStackLen */  \
  OS_NULLISR,                                          /* isrCurrent */  \
  OS_NULLOBJECT,                                       /* isrLastLock */  \
  0,                                                   /* oldSuspendOs */  \
  0,                                                   /* oldSuspendAll */  \
  0,                                                   /* nestSuspendOs */  \
  0,                                                   /* nestSuspendAll */  \
  OS_ERRORSTATUS_INIT,                                 /* errorStatus */  \
  OS_HOOKCONTEXT_INIT,                                 /* sHookContext */  \
  OS_HOOKCONTEXT_INIT,                                 /* eHookContext */  \
  0,                                                   /* errorHookNesting */  \
  OS_ACCOUNTINGS_INIT,                                 /* accounting */  \
  0,                                                   /* appsStarted */  \
  OS_PANIC_NONE                                        /* panicCode */
#define OS_KERNELDATA_INIT_CORE3     /* kernel data core 3 */  \
  OS_NULL,                                             /* taskQueueHead */  \
  OS_NULL,                                             /* taskCurrent */  \
  OS_GetInitialStackPointer(OS_ISTACKBASE_3, OS_ISTACKLEN_3),  /* iSpInitial */  \
  OS_NULL,                                             /* hookApp */  \
  0,                                                   /* inKernel */  \
  IDLE_NO_HALT,                                        /* idleMode */  \
  0,                                                   /* inFunction */  \
  0,                                                   /* tfCalledFrom */  \
  OS_ISTACKBASE_3,                                     /* iStackBase */  \
  OS_ISTACKLEN_3,                                      /* iStackLen */  \
  OS_NULLISR,                                          /* isrCurrent */  \
  OS_NULLOBJECT,                                       /* isrLastLock */  \
  0,                                                   /* oldSuspendOs */  \
  0,                                                   /* oldSuspendAll */  \
  0,                                                   /* nestSuspendOs */  \
  0,                                                   /* nestSuspendAll */  \
  OS_ERRORSTATUS_INIT,                                 /* errorStatus */  \
  OS_HOOKCONTEXT_INIT,                                 /* sHookContext */  \
  OS_HOOKCONTEXT_INIT,                                 /* eHookContext */  \
  0,                                                   /* errorHookNesting */  \
  OS_ACCOUNTINGS_INIT,                                 /* accounting */  \
  0,                                                   /* appsStarted */  \
  OS_PANIC_NONE                                        /* panicCode */

/*===================================================================
 * Optimization
 *==================================================================*/

#define OS_CAT1_DIRECTCALL 0
/*===================================================================
 * Rate Monitor
 *==================================================================*/

#define OS_NRATEMONS 0
#define OS_NRATEMONS_CORE0 0
#define OS_NRATEMONS_CORE1 0
#define OS_NRATEMONS_CORE2 0
#define OS_NRATEMONS_CORE3 0

/*===================================================================
 * Resource Lock Timing
 *==================================================================*/

#define OS_NRESLOCKTIMES 0
/*===================================================================
 * Resources
 *==================================================================*/

#define OS_NRESOURCES 13
#define OS_RESOURCES OS_RESOURCES_INIT(    /* RES_SCHEDULER_0 */  \
  &OS_appTable[OS_SYSTEM_0],                           /* Application */  \
  0xffU,                                               /* Permissions */  \
  13,                                                  /* Priority */  \
  &OS_resourceDynamic_core0[0]                         /* dynamic data */  \
),  \
OS_RESOURCES_INIT(    /* RES_SCHEDULER_1 */  \
  &OS_appTable[OS_SYSTEM_1],                           /* Application */  \
  0xffU,                                               /* Permissions */  \
  7,                                                   /* Priority */  \
  &OS_resourceDynamic_core1[0]                         /* dynamic data */  \
),  \
OS_RESOURCES_INIT(    /* RES_SCHEDULER_2 */  \
  &OS_appTable[OS_SYSTEM_2],                           /* Application */  \
  0xffU,                                               /* Permissions */  \
  5,                                                   /* Priority */  \
  &OS_resourceDynamic_core2[0]                         /* dynamic data */  \
),  \
OS_RESOURCES_INIT(    /* RES_SCHEDULER_3 */  \
  &OS_appTable[OS_SYSTEM_3],                           /* Application */  \
  0xffU,                                               /* Permissions */  \
  7,                                                   /* Priority */  \
  &OS_resourceDynamic_core3[0]                         /* dynamic data */  \
),  \
OS_RESOURCES_INIT(    /* Rte_Res_0 */  \
  &OS_appTable[OsApplication_C0],                      /* Application */  \
  0x1U,                                                /* Permissions */  \
  13,                                                  /* Priority */  \
  &OS_resourceDynamic_core0[1]                         /* dynamic data */  \
),  \
OS_RESOURCES_INIT(    /* Rte_Res_1 */  \
  &OS_appTable[OsApplication_C0],                      /* Application */  \
  0x1U,                                                /* Permissions */  \
  13,                                                  /* Priority */  \
  &OS_resourceDynamic_core0[2]                         /* dynamic data */  \
),  \
OS_RESOURCES_INIT(    /* Rte_Res_2 */  \
  &OS_appTable[OsApplication_C0],                      /* Application */  \
  0x1U,                                                /* Permissions */  \
  5,                                                   /* Priority */  \
  &OS_resourceDynamic_core0[3]                         /* dynamic data */  \
),  \
OS_RESOURCES_INIT(    /* Rte_Res_3 */  \
  &OS_appTable[OsApplication_C0],                      /* Application */  \
  0x1U,                                                /* Permissions */  \
  13,                                                  /* Priority */  \
  &OS_resourceDynamic_core0[4]                         /* dynamic data */  \
),  \
OS_RESOURCES_INIT(    /* Rte_Res_4 */  \
  &OS_appTable[OsApplication_C0],                      /* Application */  \
  0x1U,                                                /* Permissions */  \
  11,                                                  /* Priority */  \
  &OS_resourceDynamic_core0[5]                         /* dynamic data */  \
),  \
OS_RESOURCES_INIT(    /* Rte_Res_5 */  \
  &OS_appTable[OsApplication_C0],                      /* Application */  \
  0x1U,                                                /* Permissions */  \
  13,                                                  /* Priority */  \
  &OS_resourceDynamic_core0[6]                         /* dynamic data */  \
),  \
OS_RESOURCES_INIT(    /* Rte_Res_6 */  \
  &OS_appTable[OsApplication_C0],                      /* Application */  \
  0x1U,                                                /* Permissions */  \
  13,                                                  /* Priority */  \
  &OS_resourceDynamic_core0[7]                         /* dynamic data */  \
),  \
OS_RESOURCES_INIT(    /* Rte_Res_7 */  \
  &OS_appTable[OsApplication_C0],                      /* Application */  \
  0x1U,                                                /* Permissions */  \
  13,                                                  /* Priority */  \
  &OS_resourceDynamic_core0[8]                         /* dynamic data */  \
),  \
OS_RESOURCES_INIT(    /* Rte_Res_8 */  \
  &OS_appTable[OsApplication_C0],                      /* Application */  \
  0x1U,                                                /* Permissions */  \
  13,                                                  /* Priority */  \
  &OS_resourceDynamic_core0[9]                         /* dynamic data */  \
),
#define OS_NRESOURCES_CORE0 10
#define OS_NRESOURCES_CORE1 1
#define OS_NRESOURCES_CORE2 1
#define OS_NRESOURCES_CORE3 1

/*===================================================================
 * Schedule Tables
 *==================================================================*/

#define OS_NSCHEDULES 8
#define OS_NSCHEDULESSYNC 0
#define OS_STCONFIG OS_STCONFIG_INIT(    /* SchM_DefaultScheduleTable_OsApplication_C0 */  \
  OsApplication_C0,                                    /* Application id */  \
  &OS_appTable[OsApplication_C0],                      /* Application pointer */  \
  0x1U,                                                /* Permissions */  \
  &OS_stEntries[0],                                    /* Schedule table entries */  \
  20,                                                  /* Duration */  \
  0,                                                   /* Cut off */  \
  0,                                                   /* Precision */  \
  4,                                                   /* Alarm ID */  \
  7,                                                   /* Number of expiry points */  \
  (OS_ST_REPEATING),                                   /* Flags */  \
  &OS_scheduleDynamic_core0[0]                         /* dynamic data */  \
),  \
OS_STCONFIG_INIT(    /* Rte_DefaultScheduleTable_OsApplication_C0 */  \
  OsApplication_C0,                                    /* Application id */  \
  &OS_appTable[OsApplication_C0],                      /* Application pointer */  \
  0x1U,                                                /* Permissions */  \
  &OS_stEntries[7],                                    /* Schedule table entries */  \
  300,                                                 /* Duration */  \
  0,                                                   /* Cut off */  \
  0,                                                   /* Precision */  \
  5,                                                   /* Alarm ID */  \
  235,                                                 /* Number of expiry points */  \
  (OS_ST_REPEATING),                                   /* Flags */  \
  &OS_scheduleDynamic_core0[1]                         /* dynamic data */  \
),  \
OS_STCONFIG_INIT(    /* SchM_DefaultScheduleTable_OsApplication_C1 */  \
  OsApplication_C1,                                    /* Application id */  \
  &OS_appTable[OsApplication_C1],                      /* Application pointer */  \
  0x2U,                                                /* Permissions */  \
  &OS_stEntries[242],                                  /* Schedule table entries */  \
  20,                                                  /* Duration */  \
  0,                                                   /* Cut off */  \
  0,                                                   /* Precision */  \
  6,                                                   /* Alarm ID */  \
  6,                                                   /* Number of expiry points */  \
  (OS_ST_REPEATING),                                   /* Flags */  \
  &OS_scheduleDynamic_core1[0]                         /* dynamic data */  \
),  \
OS_STCONFIG_INIT(    /* Rte_DefaultScheduleTable_OsApplication_C1 */  \
  OsApplication_C1,                                    /* Application id */  \
  &OS_appTable[OsApplication_C1],                      /* Application pointer */  \
  0x2U,                                                /* Permissions */  \
  &OS_stEntries[248],                                  /* Schedule table entries */  \
  300,                                                 /* Duration */  \
  0,                                                   /* Cut off */  \
  0,                                                   /* Precision */  \
  7,                                                   /* Alarm ID */  \
  53,                                                  /* Number of expiry points */  \
  (OS_ST_REPEATING),                                   /* Flags */  \
  &OS_scheduleDynamic_core1[1]                         /* dynamic data */  \
),  \
OS_STCONFIG_INIT(    /* SchM_DefaultScheduleTable_OsApplication_C2 */  \
  OsApplication_C2,                                    /* Application id */  \
  &OS_appTable[OsApplication_C2],                      /* Application pointer */  \
  0x4U,                                                /* Permissions */  \
  &OS_stEntries[301],                                  /* Schedule table entries */  \
  20,                                                  /* Duration */  \
  0,                                                   /* Cut off */  \
  0,                                                   /* Precision */  \
  8,                                                   /* Alarm ID */  \
  2,                                                   /* Number of expiry points */  \
  (OS_ST_REPEATING),                                   /* Flags */  \
  &OS_scheduleDynamic_core2[0]                         /* dynamic data */  \
),  \
OS_STCONFIG_INIT(    /* Rte_DefaultScheduleTable_OsApplication_C2 */  \
  OsApplication_C2,                                    /* Application id */  \
  &OS_appTable[OsApplication_C2],                      /* Application pointer */  \
  0x4U,                                                /* Permissions */  \
  &OS_stEntries[303],                                  /* Schedule table entries */  \
  100,                                                 /* Duration */  \
  0,                                                   /* Cut off */  \
  0,                                                   /* Precision */  \
  9,                                                   /* Alarm ID */  \
  6,                                                   /* Number of expiry points */  \
  (OS_ST_REPEATING),                                   /* Flags */  \
  &OS_scheduleDynamic_core2[1]                         /* dynamic data */  \
),  \
OS_STCONFIG_INIT(    /* SchM_DefaultScheduleTable_OsApplication_C3 */  \
  OsApplication_C3,                                    /* Application id */  \
  &OS_appTable[OsApplication_C3],                      /* Application pointer */  \
  0x8U,                                                /* Permissions */  \
  &OS_stEntries[309],                                  /* Schedule table entries */  \
  20,                                                  /* Duration */  \
  0,                                                   /* Cut off */  \
  0,                                                   /* Precision */  \
  10,                                                  /* Alarm ID */  \
  2,                                                   /* Number of expiry points */  \
  (OS_ST_REPEATING),                                   /* Flags */  \
  &OS_scheduleDynamic_core3[0]                         /* dynamic data */  \
),  \
OS_STCONFIG_INIT(    /* Rte_DefaultScheduleTable_OsApplication_C3 */  \
  OsApplication_C3,                                    /* Application id */  \
  &OS_appTable[OsApplication_C3],                      /* Application pointer */  \
  0x8U,                                                /* Permissions */  \
  &OS_stEntries[311],                                  /* Schedule table entries */  \
  60,                                                  /* Duration */  \
  0,                                                   /* Cut off */  \
  0,                                                   /* Precision */  \
  11,                                                  /* Alarm ID */  \
  16,                                                  /* Number of expiry points */  \
  (OS_ST_REPEATING),                                   /* Flags */  \
  &OS_scheduleDynamic_core3[1]                         /* dynamic data */  \
),
#define OS_NSTENTRIES 327
#define OS_STENTRIES     /* EP_0 */  \
    {  \
      0,                                                   /* Offset */  \
      0,                                                   /* Max advance */  \
      0,                                                   /* Max retard */  \
      0,                                                   /* Event */  \
      Core0_OsTask_Bsw_20ms                                /* Task */  \
    },  \
    {  \
      0,                                                   /* Offset */  \
      0,                                                   /* Max advance */  \
      0,                                                   /* Max retard */  \
      0,                                                   /* Event */  \
      Core0_OsTask_Bsw_10ms                                /* Task */  \
    },  \
    {  \
      0,                                                   /* Offset */  \
      0,                                                   /* Max advance */  \
      0,                                                   /* Max retard */  \
      Rte_OSTimingEvent_Core0_OsTask_Bsw_5ms_TE_9250283FD3A374F9E6E088501A7A0E92,  /* Events */  \
      Core0_OsTask_Bsw_5ms                                 /* Task */  \
    },  \
    /* EP_5000 */  \
    {  \
      5,                                                   /* Offset */  \
      0,                                                   /* Max advance */  \
      0,                                                   /* Max retard */  \
      Rte_OSTimingEvent_Core0_OsTask_Bsw_5ms_TE_9250283FD3A374F9E6E088501A7A0E92,  /* Events */  \
      Core0_OsTask_Bsw_5ms                                 /* Task */  \
    },  \
    /* EP_10000 */  \
    {  \
      10,                                                  /* Offset */  \
      0,                                                   /* Max advance */  \
      0,                                                   /* Max retard */  \
      0,                                                   /* Event */  \
      Core0_OsTask_Bsw_10ms                                /* Task */  \
    },  \
    {  \
      10,                                                  /* Offset */  \
      0,                                                   /* Max advance */  \
      0,                                                   /* Max retard */  \
      Rte_OSTimingEvent_Core0_OsTask_Bsw_5ms_TE_9250283FD3A374F9E6E088501A7A0E92,  /* Events */  \
      Core0_OsTask_Bsw_5ms                                 /* Task */  \
    },  \
    /* EP_15000 */  \
    {  \
      15,                                                  /* Offset */  \
      0,                                                   /* Max advance */  \
      0,                                                   /* Max retard */  \
      Rte_OSTimingEvent_Core0_OsTask_Bsw_5ms_TE_9250283FD3A374F9E6E088501A7A0E92,  /* Events */  \
      Core0_OsTask_Bsw_5ms                                 /* Task */  \
    },  \
    /* EP_0 */  \
    {  \
      0,                                                   /* Offset */  \
      0,                                                   /* Max advance */  \
      0,                                                   /* Max retard */  \
      0,                                                   /* Event */  \
      Core0_OsTask_Appl_10ms                               /* Task */  \
    },  \
    {  \
      0,                                                   /* Offset */  \
      0,                                                   /* Max advance */  \
      0,                                                   /* Max retard */  \
      0,                                                   /* Event */  \
      Core0_OsTask_Appl_5ms                                /* Task */  \
    },  \
    {  \
      0,                                                   /* Offset */  \
      0,                                                   /* Max advance */  \
      0,                                                   /* Max retard */  \
      0,                                                   /* Event */  \
      Core0_OsTask_FunctionSafety_5ms                      /* Task */  \
    },  \
    {  \
      0,                                                   /* Offset */  \
      0,                                                   /* Max advance */  \
      0,                                                   /* Max retard */  \
      Rte_OSTimingEvent_Core0_OsTask_Bsw_5ms_TE_C81871CF733B997334C7E18C4B5DB17E,  /* Events */  \
      Core0_OsTask_Bsw_5ms                                 /* Task */  \
    },  \
    {  \
      0,                                                   /* Offset */  \
      0,                                                   /* Max advance */  \
      0,                                                   /* Max retard */  \
      Rte_OSTimingEvent_Core0_OsTask_Appl_20ms_TE_F97F7A2ECAEA3A4FE9A6468E6E83C78D,  /* Events */  \
      Core0_OsTask_Appl_20ms                               /* Task */  \
    },  \
    {  \
      0,                                                   /* Offset */  \
      0,                                                   /* Max advance */  \
      0,                                                   /* Max retard */  \
      Rte_OSTimingEvent_Core0_OsTask_Appl_60ms_TE_EF84604C92A30BF324A2DEF1D82825FD | Rte_OSTimingEvent_Core0_OsTask_Appl_60ms_TE_344FB9C7D2E189EB211BC438F55F3A79,  /* Events */  \
      Core0_OsTask_Appl_60ms                               /* Task */  \
    },  \
    /* EP_5000 */  \
    {  \
      5,                                                   /* Offset */  \
      0,                                                   /* Max advance */  \
      0,                                                   /* Max retard */  \
      0,                                                   /* Event */  \
      Core0_OsTask_Appl_5ms                                /* Task */  \
    },  \
    {  \
      5,                                                   /* Offset */  \
      0,                                                   /* Max advance */  \
      0,                                                   /* Max retard */  \
      0,                                                   /* Event */  \
      Core0_OsTask_FunctionSafety_5ms                      /* Task */  \
    },  \
    {  \
      5,                                                   /* Offset */  \
      0,                                                   /* Max advance */  \
      0,                                                   /* Max retard */  \
      Rte_OSTimingEvent_Core0_OsTask_Bsw_5ms_TE_C81871CF733B997334C7E18C4B5DB17E,  /* Events */  \
      Core0_OsTask_Bsw_5ms                                 /* Task */  \
    },  \
    /* EP_10000 */  \
    {  \
      10,                                                  /* Offset */  \
      0,                                                   /* Max advance */  \
      0,                                                   /* Max retard */  \
      0,                                                   /* Event */  \
      Core0_OsTask_Appl_10ms                               /* Task */  \
    },  \
    {  \
      10,                                                  /* Offset */  \
      0,                                                   /* Max advance */  \
      0,                                                   /* Max retard */  \
      0,                                                   /* Event */  \
      Core0_OsTask_Appl_5ms                                /* Task */  \
    },  \
    {  \
      10,                                                  /* Offset */  \
      0,                                                   /* Max advance */  \
      0,                                                   /* Max retard */  \
      0,                                                   /* Event */  \
      Core0_OsTask_FunctionSafety_5ms                      /* Task */  \
    },  \
    {  \
      10,                                                  /* Offset */  \
      0,                                                   /* Max advance */  \
      0,                                                   /* Max retard */  \
      Rte_OSTimingEvent_Core0_OsTask_Bsw_5ms_TE_C81871CF733B997334C7E18C4B5DB17E,  /* Events */  \
      Core0_OsTask_Bsw_5ms                                 /* Task */  \
    },  \
    /* EP_15000 */  \
    {  \
      15,                                                  /* Offset */  \
      0,                                                   /* Max advance */  \
      0,                                                   /* Max retard */  \
      0,                                                   /* Event */  \
      Core0_OsTask_Appl_5ms                                /* Task */  \
    },  \
    {  \
      15,                                                  /* Offset */  \
      0,                                                   /* Max advance */  \
      0,                                                   /* Max retard */  \
      0,                                                   /* Event */  \
      Core0_OsTask_FunctionSafety_5ms                      /* Task */  \
    },  \
    {  \
      15,                                                  /* Offset */  \
      0,                                                   /* Max advance */  \
      0,                                                   /* Max retard */  \
      Rte_OSTimingEvent_Core0_OsTask_Bsw_5ms_TE_C81871CF733B997334C7E18C4B5DB17E,  /* Events */  \
      Core0_OsTask_Bsw_5ms                                 /* Task */  \
    },  \
    /* EP_20000 */  \
    {  \
      20,                                                  /* Offset */  \
      0,                                                   /* Max advance */  \
      0,                                                   /* Max retard */  \
      0,                                                   /* Event */  \
      Core0_OsTask_Appl_10ms                               /* Task */  \
    },  \
    {  \
      20,                                                  /* Offset */  \
      0,                                                   /* Max advance */  \
      0,                                                   /* Max retard */  \
      0,                                                   /* Event */  \
      Core0_OsTask_Appl_5ms                                /* Task */  \
    },  \
    {  \
      20,                                                  /* Offset */  \
      0,                                                   /* Max advance */  \
      0,                                                   /* Max retard */  \
      0,                                                   /* Event */  \
      Core0_OsTask_FunctionSafety_5ms                      /* Task */  \
    },  \
    {  \
      20,                                                  /* Offset */  \
      0,                                                   /* Max advance */  \
      0,                                                   /* Max retard */  \
      Rte_OSTimingEvent_Core0_OsTask_Bsw_5ms_TE_C81871CF733B997334C7E18C4B5DB17E,  /* Events */  \
      Core0_OsTask_Bsw_5ms                                 /* Task */  \
    },  \
    {  \
      20,                                                  /* Offset */  \
      0,                                                   /* Max advance */  \
      0,                                                   /* Max retard */  \
      Rte_OSTimingEvent_Core0_OsTask_Appl_20ms_TE_F97F7A2ECAEA3A4FE9A6468E6E83C78D,  /* Events */  \
      Core0_OsTask_Appl_20ms                               /* Task */  \
    },  \
    /* EP_25000 */  \
    {  \
      25,                                                  /* Offset */  \
      0,                                                   /* Max advance */  \
      0,                                                   /* Max retard */  \
      0,                                                   /* Event */  \
      Core0_OsTask_Appl_5ms                                /* Task */  \
    },  \
    {  \
      25,                                                  /* Offset */  \
      0,                                                   /* Max advance */  \
      0,                                                   /* Max retard */  \
      0,                                                   /* Event */  \
      Core0_OsTask_FunctionSafety_5ms                      /* Task */  \
    },  \
    {  \
      25,                                                  /* Offset */  \
      0,                                                   /* Max advance */  \
      0,                                                   /* Max retard */  \
      Rte_OSTimingEvent_Core0_OsTask_Bsw_5ms_TE_C81871CF733B997334C7E18C4B5DB17E,  /* Events */  \
      Core0_OsTask_Bsw_5ms                                 /* Task */  \
    },  \
    /* EP_30000 */  \
    {  \
      30,                                                  /* Offset */  \
      0,                                                   /* Max advance */  \
      0,                                                   /* Max retard */  \
      0,                                                   /* Event */  \
      Core0_OsTask_Appl_10ms                               /* Task */  \
    },  \
    {  \
      30,                                                  /* Offset */  \
      0,                                                   /* Max advance */  \
      0,                                                   /* Max retard */  \
      0,                                                   /* Event */  \
      Core0_OsTask_Appl_5ms                                /* Task */  \
    },  \
    {  \
      30,                                                  /* Offset */  \
      0,                                                   /* Max advance */  \
      0,                                                   /* Max retard */  \
      0,                                                   /* Event */  \
      Core0_OsTask_FunctionSafety_5ms                      /* Task */  \
    },  \
    {  \
      30,                                                  /* Offset */  \
      0,                                                   /* Max advance */  \
      0,                                                   /* Max retard */  \
      Rte_OSTimingEvent_Core0_OsTask_Bsw_5ms_TE_C81871CF733B997334C7E18C4B5DB17E,  /* Events */  \
      Core0_OsTask_Bsw_5ms                                 /* Task */  \
    },  \
    /* EP_35000 */  \
    {  \
      35,                                                  /* Offset */  \
      0,                                                   /* Max advance */  \
      0,                                                   /* Max retard */  \
      0,                                                   /* Event */  \
      Core0_OsTask_Appl_5ms                                /* Task */  \
    },  \
    {  \
      35,                                                  /* Offset */  \
      0,                                                   /* Max advance */  \
      0,                                                   /* Max retard */  \
      0,                                                   /* Event */  \
      Core0_OsTask_FunctionSafety_5ms                      /* Task */  \
    },  \
    {  \
      35,                                                  /* Offset */  \
      0,                                                   /* Max advance */  \
      0,                                                   /* Max retard */  \
      Rte_OSTimingEvent_Core0_OsTask_Bsw_5ms_TE_C81871CF733B997334C7E18C4B5DB17E,  /* Events */  \
      Core0_OsTask_Bsw_5ms                                 /* Task */  \
    },  \
    /* EP_40000 */  \
    {  \
      40,                                                  /* Offset */  \
      0,                                                   /* Max advance */  \
      0,                                                   /* Max retard */  \
      0,                                                   /* Event */  \
      Core0_OsTask_Appl_10ms                               /* Task */  \
    },  \
    {  \
      40,                                                  /* Offset */  \
      0,                                                   /* Max advance */  \
      0,                                                   /* Max retard */  \
      0,                                                   /* Event */  \
      Core0_OsTask_Appl_5ms                                /* Task */  \
    },  \
    {  \
      40,                                                  /* Offset */  \
      0,                                                   /* Max advance */  \
      0,                                                   /* Max retard */  \
      0,                                                   /* Event */  \
      Core0_OsTask_FunctionSafety_5ms                      /* Task */  \
    },  \
    {  \
      40,                                                  /* Offset */  \
      0,                                                   /* Max advance */  \
      0,                                                   /* Max retard */  \
      Rte_OSTimingEvent_Core0_OsTask_Bsw_5ms_TE_C81871CF733B997334C7E18C4B5DB17E,  /* Events */  \
      Core0_OsTask_Bsw_5ms                                 /* Task */  \
    },  \
    {  \
      40,                                                  /* Offset */  \
      0,                                                   /* Max advance */  \
      0,                                                   /* Max retard */  \
      Rte_OSTimingEvent_Core0_OsTask_Appl_20ms_TE_F97F7A2ECAEA3A4FE9A6468E6E83C78D,  /* Events */  \
      Core0_OsTask_Appl_20ms                               /* Task */  \
    },  \
    /* EP_45000 */  \
    {  \
      45,                                                  /* Offset */  \
      0,                                                   /* Max advance */  \
      0,                                                   /* Max retard */  \
      0,                                                   /* Event */  \
      Core0_OsTask_Appl_5ms                                /* Task */  \
    },  \
    {  \
      45,                                                  /* Offset */  \
      0,                                                   /* Max advance */  \
      0,                                                   /* Max retard */  \
      0,                                                   /* Event */  \
      Core0_OsTask_FunctionSafety_5ms                      /* Task */  \
    },  \
    {  \
      45,                                                  /* Offset */  \
      0,                                                   /* Max advance */  \
      0,                                                   /* Max retard */  \
      Rte_OSTimingEvent_Core0_OsTask_Bsw_5ms_TE_C81871CF733B997334C7E18C4B5DB17E,  /* Events */  \
      Core0_OsTask_Bsw_5ms                                 /* Task */  \
    },  \
    /* EP_50000 */  \
    {  \
      50,                                                  /* Offset */  \
      0,                                                   /* Max advance */  \
      0,                                                   /* Max retard */  \
      0,                                                   /* Event */  \
      Core0_OsTask_Appl_10ms                               /* Task */  \
    },  \
    {  \
      50,                                                  /* Offset */  \
      0,                                                   /* Max advance */  \
      0,                                                   /* Max retard */  \
      0,                                                   /* Event */  \
      Core0_OsTask_Appl_5ms                                /* Task */  \
    },  \
    {  \
      50,                                                  /* Offset */  \
      0,                                                   /* Max advance */  \
      0,                                                   /* Max retard */  \
      0,                                                   /* Event */  \
      Core0_OsTask_FunctionSafety_5ms                      /* Task */  \
    },  \
    {  \
      50,                                                  /* Offset */  \
      0,                                                   /* Max advance */  \
      0,                                                   /* Max retard */  \
      Rte_OSTimingEvent_Core0_OsTask_Bsw_5ms_TE_C81871CF733B997334C7E18C4B5DB17E,  /* Events */  \
      Core0_OsTask_Bsw_5ms                                 /* Task */  \
    },  \
    {  \
      50,                                                  /* Offset */  \
      0,                                                   /* Max advance */  \
      0,                                                   /* Max retard */  \
      Rte_OSTimingEvent_Core0_OsTask_Appl_60ms_TE_344FB9C7D2E189EB211BC438F55F3A79,  /* Events */  \
      Core0_OsTask_Appl_60ms                               /* Task */  \
    },  \
    /* EP_55000 */  \
    {  \
      55,                                                  /* Offset */  \
      0,                                                   /* Max advance */  \
      0,                                                   /* Max retard */  \
      0,                                                   /* Event */  \
      Core0_OsTask_Appl_5ms                                /* Task */  \
    },  \
    {  \
      55,                                                  /* Offset */  \
      0,                                                   /* Max advance */  \
      0,                                                   /* Max retard */  \
      0,                                                   /* Event */  \
      Core0_OsTask_FunctionSafety_5ms                      /* Task */  \
    },  \
    {  \
      55,                                                  /* Offset */  \
      0,                                                   /* Max advance */  \
      0,                                                   /* Max retard */  \
      Rte_OSTimingEvent_Core0_OsTask_Bsw_5ms_TE_C81871CF733B997334C7E18C4B5DB17E,  /* Events */  \
      Core0_OsTask_Bsw_5ms                                 /* Task */  \
    },  \
    /* EP_60000 */  \
    {  \
      60,                                                  /* Offset */  \
      0,                                                   /* Max advance */  \
      0,                                                   /* Max retard */  \
      0,                                                   /* Event */  \
      Core0_OsTask_Appl_10ms                               /* Task */  \
    },  \
    {  \
      60,                                                  /* Offset */  \
      0,                                                   /* Max advance */  \
      0,                                                   /* Max retard */  \
      0,                                                   /* Event */  \
      Core0_OsTask_Appl_5ms                                /* Task */  \
    },  \
    {  \
      60,                                                  /* Offset */  \
      0,                                                   /* Max advance */  \
      0,                                                   /* Max retard */  \
      0,                                                   /* Event */  \
      Core0_OsTask_FunctionSafety_5ms                      /* Task */  \
    },  \
    {  \
      60,                                                  /* Offset */  \
      0,                                                   /* Max advance */  \
      0,                                                   /* Max retard */  \
      Rte_OSTimingEvent_Core0_OsTask_Bsw_5ms_TE_C81871CF733B997334C7E18C4B5DB17E,  /* Events */  \
      Core0_OsTask_Bsw_5ms                                 /* Task */  \
    },  \
    {  \
      60,                                                  /* Offset */  \
      0,                                                   /* Max advance */  \
      0,                                                   /* Max retard */  \
      Rte_OSTimingEvent_Core0_OsTask_Appl_20ms_TE_F97F7A2ECAEA3A4FE9A6468E6E83C78D,  /* Events */  \
      Core0_OsTask_Appl_20ms                               /* Task */  \
    },  \
    {  \
      60,                                                  /* Offset */  \
      0,                                                   /* Max advance */  \
      0,                                                   /* Max retard */  \
      Rte_OSTimingEvent_Core0_OsTask_Appl_60ms_TE_EF84604C92A30BF324A2DEF1D82825FD,  /* Events */  \
      Core0_OsTask_Appl_60ms                               /* Task */  \
    },  \
    /* EP_65000 */  \
    {  \
      65,                                                  /* Offset */  \
      0,                                                   /* Max advance */  \
      0,                                                   /* Max retard */  \
      0,                                                   /* Event */  \
      Core0_OsTask_Appl_5ms                                /* Task */  \
    },  \
    {  \
      65,                                                  /* Offset */  \
      0,                                                   /* Max advance */  \
      0,                                                   /* Max retard */  \
      0,                                                   /* Event */  \
      Core0_OsTask_FunctionSafety_5ms                      /* Task */  \
    },  \
    {  \
      65,                                                  /* Offset */  \
      0,                                                   /* Max advance */  \
      0,                                                   /* Max retard */  \
      Rte_OSTimingEvent_Core0_OsTask_Bsw_5ms_TE_C81871CF733B997334C7E18C4B5DB17E,  /* Events */  \
      Core0_OsTask_Bsw_5ms                                 /* Task */  \
    },  \
    /* EP_70000 */  \
    {  \
      70,                                                  /* Offset */  \
      0,                                                   /* Max advance */  \
      0,                                                   /* Max retard */  \
      0,                                                   /* Event */  \
      Core0_OsTask_Appl_10ms                               /* Task */  \
    },  \
    {  \
      70,                                                  /* Offset */  \
      0,                                                   /* Max advance */  \
      0,                                                   /* Max retard */  \
      0,                                                   /* Event */  \
      Core0_OsTask_Appl_5ms                                /* Task */  \
    },  \
    {  \
      70,                                                  /* Offset */  \
      0,                                                   /* Max advance */  \
      0,                                                   /* Max retard */  \
      0,                                                   /* Event */  \
      Core0_OsTask_FunctionSafety_5ms                      /* Task */  \
    },  \
    {  \
      70,                                                  /* Offset */  \
      0,                                                   /* Max advance */  \
      0,                                                   /* Max retard */  \
      Rte_OSTimingEvent_Core0_OsTask_Bsw_5ms_TE_C81871CF733B997334C7E18C4B5DB17E,  /* Events */  \
      Core0_OsTask_Bsw_5ms                                 /* Task */  \
    },  \
    /* EP_75000 */  \
    {  \
      75,                                                  /* Offset */  \
      0,                                                   /* Max advance */  \
      0,                                                   /* Max retard */  \
      0,                                                   /* Event */  \
      Core0_OsTask_Appl_5ms                                /* Task */  \
    },  \
    {  \
      75,                                                  /* Offset */  \
      0,                                                   /* Max advance */  \
      0,                                                   /* Max retard */  \
      0,                                                   /* Event */  \
      Core0_OsTask_FunctionSafety_5ms                      /* Task */  \
    },  \
    {  \
      75,                                                  /* Offset */  \
      0,                                                   /* Max advance */  \
      0,                                                   /* Max retard */  \
      Rte_OSTimingEvent_Core0_OsTask_Bsw_5ms_TE_C81871CF733B997334C7E18C4B5DB17E,  /* Events */  \
      Core0_OsTask_Bsw_5ms                                 /* Task */  \
    },  \
    /* EP_80000 */  \
    {  \
      80,                                                  /* Offset */  \
      0,                                                   /* Max advance */  \
      0,                                                   /* Max retard */  \
      0,                                                   /* Event */  \
      Core0_OsTask_Appl_10ms                               /* Task */  \
    },  \
    {  \
      80,                                                  /* Offset */  \
      0,                                                   /* Max advance */  \
      0,                                                   /* Max retard */  \
      0,                                                   /* Event */  \
      Core0_OsTask_Appl_5ms                                /* Task */  \
    },  \
    {  \
      80,                                                  /* Offset */  \
      0,                                                   /* Max advance */  \
      0,                                                   /* Max retard */  \
      0,                                                   /* Event */  \
      Core0_OsTask_FunctionSafety_5ms                      /* Task */  \
    },  \
    {  \
      80,                                                  /* Offset */  \
      0,                                                   /* Max advance */  \
      0,                                                   /* Max retard */  \
      Rte_OSTimingEvent_Core0_OsTask_Bsw_5ms_TE_C81871CF733B997334C7E18C4B5DB17E,  /* Events */  \
      Core0_OsTask_Bsw_5ms                                 /* Task */  \
    },  \
    {  \
      80,                                                  /* Offset */  \
      0,                                                   /* Max advance */  \
      0,                                                   /* Max retard */  \
      Rte_OSTimingEvent_Core0_OsTask_Appl_20ms_TE_F97F7A2ECAEA3A4FE9A6468E6E83C78D,  /* Events */  \
      Core0_OsTask_Appl_20ms                               /* Task */  \
    },  \
    /* EP_85000 */  \
    {  \
      85,                                                  /* Offset */  \
      0,                                                   /* Max advance */  \
      0,                                                   /* Max retard */  \
      0,                                                   /* Event */  \
      Core0_OsTask_Appl_5ms                                /* Task */  \
    },  \
    {  \
      85,                                                  /* Offset */  \
      0,                                                   /* Max advance */  \
      0,                                                   /* Max retard */  \
      0,                                                   /* Event */  \
      Core0_OsTask_FunctionSafety_5ms                      /* Task */  \
    },  \
    {  \
      85,                                                  /* Offset */  \
      0,                                                   /* Max advance */  \
      0,                                                   /* Max retard */  \
      Rte_OSTimingEvent_Core0_OsTask_Bsw_5ms_TE_C81871CF733B997334C7E18C4B5DB17E,  /* Events */  \
      Core0_OsTask_Bsw_5ms                                 /* Task */  \
    },  \
    /* EP_90000 */  \
    {  \
      90,                                                  /* Offset */  \
      0,                                                   /* Max advance */  \
      0,                                                   /* Max retard */  \
      0,                                                   /* Event */  \
      Core0_OsTask_Appl_10ms                               /* Task */  \
    },  \
    {  \
      90,                                                  /* Offset */  \
      0,                                                   /* Max advance */  \
      0,                                                   /* Max retard */  \
      0,                                                   /* Event */  \
      Core0_OsTask_Appl_5ms                                /* Task */  \
    },  \
    {  \
      90,                                                  /* Offset */  \
      0,                                                   /* Max advance */  \
      0,                                                   /* Max retard */  \
      0,                                                   /* Event */  \
      Core0_OsTask_FunctionSafety_5ms                      /* Task */  \
    },  \
    {  \
      90,                                                  /* Offset */  \
      0,                                                   /* Max advance */  \
      0,                                                   /* Max retard */  \
      Rte_OSTimingEvent_Core0_OsTask_Bsw_5ms_TE_C81871CF733B997334C7E18C4B5DB17E,  /* Events */  \
      Core0_OsTask_Bsw_5ms                                 /* Task */  \
    },  \
    /* EP_95000 */  \
    {  \
      95,                                                  /* Offset */  \
      0,                                                   /* Max advance */  \
      0,                                                   /* Max retard */  \
      0,                                                   /* Event */  \
      Core0_OsTask_Appl_5ms                                /* Task */  \
    },  \
    {  \
      95,                                                  /* Offset */  \
      0,                                                   /* Max advance */  \
      0,                                                   /* Max retard */  \
      0,                                                   /* Event */  \
      Core0_OsTask_FunctionSafety_5ms                      /* Task */  \
    },  \
    {  \
      95,                                                  /* Offset */  \
      0,                                                   /* Max advance */  \
      0,                                                   /* Max retard */  \
      Rte_OSTimingEvent_Core0_OsTask_Bsw_5ms_TE_C81871CF733B997334C7E18C4B5DB17E,  /* Events */  \
      Core0_OsTask_Bsw_5ms                                 /* Task */  \
    },  \
    /* EP_100000 */  \
    {  \
      100,                                                 /* Offset */  \
      0,                                                   /* Max advance */  \
      0,                                                   /* Max retard */  \
      0,                                                   /* Event */  \
      Core0_OsTask_Appl_10ms                               /* Task */  \
    },  \
    {  \
      100,                                                 /* Offset */  \
      0,                                                   /* Max advance */  \
      0,                                                   /* Max retard */  \
      0,                                                   /* Event */  \
      Core0_OsTask_Appl_5ms                                /* Task */  \
    },  \
    {  \
      100,                                                 /* Offset */  \
      0,                                                   /* Max advance */  \
      0,                                                   /* Max retard */  \
      0,                                                   /* Event */  \
      Core0_OsTask_FunctionSafety_5ms                      /* Task */  \
    },  \
    {  \
      100,                                                 /* Offset */  \
      0,                                                   /* Max advance */  \
      0,                                                   /* Max retard */  \
      Rte_OSTimingEvent_Core0_OsTask_Bsw_5ms_TE_C81871CF733B997334C7E18C4B5DB17E,  /* Events */  \
      Core0_OsTask_Bsw_5ms                                 /* Task */  \
    },  \
    {  \
      100,                                                 /* Offset */  \
      0,                                                   /* Max advance */  \
      0,                                                   /* Max retard */  \
      Rte_OSTimingEvent_Core0_OsTask_Appl_20ms_TE_F97F7A2ECAEA3A4FE9A6468E6E83C78D,  /* Events */  \
      Core0_OsTask_Appl_20ms                               /* Task */  \
    },  \
    {  \
      100,                                                 /* Offset */  \
      0,                                                   /* Max advance */  \
      0,                                                   /* Max retard */  \
      Rte_OSTimingEvent_Core0_OsTask_Appl_60ms_TE_344FB9C7D2E189EB211BC438F55F3A79,  /* Events */  \
      Core0_OsTask_Appl_60ms                               /* Task */  \
    },  \
    /* EP_105000 */  \
    {  \
      105,                                                 /* Offset */  \
      0,                                                   /* Max advance */  \
      0,                                                   /* Max retard */  \
      0,                                                   /* Event */  \
      Core0_OsTask_Appl_5ms                                /* Task */  \
    },  \
    {  \
      105,                                                 /* Offset */  \
      0,                                                   /* Max advance */  \
      0,                                                   /* Max retard */  \
      0,                                                   /* Event */  \
      Core0_OsTask_FunctionSafety_5ms                      /* Task */  \
    },  \
    {  \
      105,                                                 /* Offset */  \
      0,                                                   /* Max advance */  \
      0,                                                   /* Max retard */  \
      Rte_OSTimingEvent_Core0_OsTask_Bsw_5ms_TE_C81871CF733B997334C7E18C4B5DB17E,  /* Events */  \
      Core0_OsTask_Bsw_5ms                                 /* Task */  \
    },  \
    /* EP_110000 */  \
    {  \
      110,                                                 /* Offset */  \
      0,                                                   /* Max advance */  \
      0,                                                   /* Max retard */  \
      0,                                                   /* Event */  \
      Core0_OsTask_Appl_10ms                               /* Task */  \
    },  \
    {  \
      110,                                                 /* Offset */  \
      0,                                                   /* Max advance */  \
      0,                                                   /* Max retard */  \
      0,                                                   /* Event */  \
      Core0_OsTask_Appl_5ms                                /* Task */  \
    },  \
    {  \
      110,                                                 /* Offset */  \
      0,                                                   /* Max advance */  \
      0,                                                   /* Max retard */  \
      0,                                                   /* Event */  \
      Core0_OsTask_FunctionSafety_5ms                      /* Task */  \
    },  \
    {  \
      110,                                                 /* Offset */  \
      0,                                                   /* Max advance */  \
      0,                                                   /* Max retard */  \
      Rte_OSTimingEvent_Core0_OsTask_Bsw_5ms_TE_C81871CF733B997334C7E18C4B5DB17E,  /* Events */  \
      Core0_OsTask_Bsw_5ms                                 /* Task */  \
    },  \
    /* EP_115000 */  \
    {  \
      115,                                                 /* Offset */  \
      0,                                                   /* Max advance */  \
      0,                                                   /* Max retard */  \
      0,                                                   /* Event */  \
      Core0_OsTask_Appl_5ms                                /* Task */  \
    },  \
    {  \
      115,                                                 /* Offset */  \
      0,                                                   /* Max advance */  \
      0,                                                   /* Max retard */  \
      0,                                                   /* Event */  \
      Core0_OsTask_FunctionSafety_5ms                      /* Task */  \
    },  \
    {  \
      115,                                                 /* Offset */  \
      0,                                                   /* Max advance */  \
      0,                                                   /* Max retard */  \
      Rte_OSTimingEvent_Core0_OsTask_Bsw_5ms_TE_C81871CF733B997334C7E18C4B5DB17E,  /* Events */  \
      Core0_OsTask_Bsw_5ms                                 /* Task */  \
    },  \
    /* EP_120000 */  \
    {  \
      120,                                                 /* Offset */  \
      0,                                                   /* Max advance */  \
      0,                                                   /* Max retard */  \
      0,                                                   /* Event */  \
      Core0_OsTask_Appl_10ms                               /* Task */  \
    },  \
    {  \
      120,                                                 /* Offset */  \
      0,                                                   /* Max advance */  \
      0,                                                   /* Max retard */  \
      0,                                                   /* Event */  \
      Core0_OsTask_Appl_5ms                                /* Task */  \
    },  \
    {  \
      120,                                                 /* Offset */  \
      0,                                                   /* Max advance */  \
      0,                                                   /* Max retard */  \
      0,                                                   /* Event */  \
      Core0_OsTask_FunctionSafety_5ms                      /* Task */  \
    },  \
    {  \
      120,                                                 /* Offset */  \
      0,                                                   /* Max advance */  \
      0,                                                   /* Max retard */  \
      Rte_OSTimingEvent_Core0_OsTask_Bsw_5ms_TE_C81871CF733B997334C7E18C4B5DB17E,  /* Events */  \
      Core0_OsTask_Bsw_5ms                                 /* Task */  \
    },  \
    {  \
      120,                                                 /* Offset */  \
      0,                                                   /* Max advance */  \
      0,                                                   /* Max retard */  \
      Rte_OSTimingEvent_Core0_OsTask_Appl_20ms_TE_F97F7A2ECAEA3A4FE9A6468E6E83C78D,  /* Events */  \
      Core0_OsTask_Appl_20ms                               /* Task */  \
    },  \
    {  \
      120,                                                 /* Offset */  \
      0,                                                   /* Max advance */  \
      0,                                                   /* Max retard */  \
      Rte_OSTimingEvent_Core0_OsTask_Appl_60ms_TE_EF84604C92A30BF324A2DEF1D82825FD,  /* Events */  \
      Core0_OsTask_Appl_60ms                               /* Task */  \
    },  \
    /* EP_125000 */  \
    {  \
      125,                                                 /* Offset */  \
      0,                                                   /* Max advance */  \
      0,                                                   /* Max retard */  \
      0,                                                   /* Event */  \
      Core0_OsTask_Appl_5ms                                /* Task */  \
    },  \
    {  \
      125,                                                 /* Offset */  \
      0,                                                   /* Max advance */  \
      0,                                                   /* Max retard */  \
      0,                                                   /* Event */  \
      Core0_OsTask_FunctionSafety_5ms                      /* Task */  \
    },  \
    {  \
      125,                                                 /* Offset */  \
      0,                                                   /* Max advance */  \
      0,                                                   /* Max retard */  \
      Rte_OSTimingEvent_Core0_OsTask_Bsw_5ms_TE_C81871CF733B997334C7E18C4B5DB17E,  /* Events */  \
      Core0_OsTask_Bsw_5ms                                 /* Task */  \
    },  \
    /* EP_130000 */  \
    {  \
      130,                                                 /* Offset */  \
      0,                                                   /* Max advance */  \
      0,                                                   /* Max retard */  \
      0,                                                   /* Event */  \
      Core0_OsTask_Appl_10ms                               /* Task */  \
    },  \
    {  \
      130,                                                 /* Offset */  \
      0,                                                   /* Max advance */  \
      0,                                                   /* Max retard */  \
      0,                                                   /* Event */  \
      Core0_OsTask_Appl_5ms                                /* Task */  \
    },  \
    {  \
      130,                                                 /* Offset */  \
      0,                                                   /* Max advance */  \
      0,                                                   /* Max retard */  \
      0,                                                   /* Event */  \
      Core0_OsTask_FunctionSafety_5ms                      /* Task */  \
    },  \
    {  \
      130,                                                 /* Offset */  \
      0,                                                   /* Max advance */  \
      0,                                                   /* Max retard */  \
      Rte_OSTimingEvent_Core0_OsTask_Bsw_5ms_TE_C81871CF733B997334C7E18C4B5DB17E,  /* Events */  \
      Core0_OsTask_Bsw_5ms                                 /* Task */  \
    },  \
    /* EP_135000 */  \
    {  \
      135,                                                 /* Offset */  \
      0,                                                   /* Max advance */  \
      0,                                                   /* Max retard */  \
      0,                                                   /* Event */  \
      Core0_OsTask_Appl_5ms                                /* Task */  \
    },  \
    {  \
      135,                                                 /* Offset */  \
      0,                                                   /* Max advance */  \
      0,                                                   /* Max retard */  \
      0,                                                   /* Event */  \
      Core0_OsTask_FunctionSafety_5ms                      /* Task */  \
    },  \
    {  \
      135,                                                 /* Offset */  \
      0,                                                   /* Max advance */  \
      0,                                                   /* Max retard */  \
      Rte_OSTimingEvent_Core0_OsTask_Bsw_5ms_TE_C81871CF733B997334C7E18C4B5DB17E,  /* Events */  \
      Core0_OsTask_Bsw_5ms                                 /* Task */  \
    },  \
    /* EP_140000 */  \
    {  \
      140,                                                 /* Offset */  \
      0,                                                   /* Max advance */  \
      0,                                                   /* Max retard */  \
      0,                                                   /* Event */  \
      Core0_OsTask_Appl_10ms                               /* Task */  \
    },  \
    {  \
      140,                                                 /* Offset */  \
      0,                                                   /* Max advance */  \
      0,                                                   /* Max retard */  \
      0,                                                   /* Event */  \
      Core0_OsTask_Appl_5ms                                /* Task */  \
    },  \
    {  \
      140,                                                 /* Offset */  \
      0,                                                   /* Max advance */  \
      0,                                                   /* Max retard */  \
      0,                                                   /* Event */  \
      Core0_OsTask_FunctionSafety_5ms                      /* Task */  \
    },  \
    {  \
      140,                                                 /* Offset */  \
      0,                                                   /* Max advance */  \
      0,                                                   /* Max retard */  \
      Rte_OSTimingEvent_Core0_OsTask_Bsw_5ms_TE_C81871CF733B997334C7E18C4B5DB17E,  /* Events */  \
      Core0_OsTask_Bsw_5ms                                 /* Task */  \
    },  \
    {  \
      140,                                                 /* Offset */  \
      0,                                                   /* Max advance */  \
      0,                                                   /* Max retard */  \
      Rte_OSTimingEvent_Core0_OsTask_Appl_20ms_TE_F97F7A2ECAEA3A4FE9A6468E6E83C78D,  /* Events */  \
      Core0_OsTask_Appl_20ms                               /* Task */  \
    },  \
    /* EP_145000 */  \
    {  \
      145,                                                 /* Offset */  \
      0,                                                   /* Max advance */  \
      0,                                                   /* Max retard */  \
      0,                                                   /* Event */  \
      Core0_OsTask_Appl_5ms                                /* Task */  \
    },  \
    {  \
      145,                                                 /* Offset */  \
      0,                                                   /* Max advance */  \
      0,                                                   /* Max retard */  \
      0,                                                   /* Event */  \
      Core0_OsTask_FunctionSafety_5ms                      /* Task */  \
    },  \
    {  \
      145,                                                 /* Offset */  \
      0,                                                   /* Max advance */  \
      0,                                                   /* Max retard */  \
      Rte_OSTimingEvent_Core0_OsTask_Bsw_5ms_TE_C81871CF733B997334C7E18C4B5DB17E,  /* Events */  \
      Core0_OsTask_Bsw_5ms                                 /* Task */  \
    },  \
    /* EP_150000 */  \
    {  \
      150,                                                 /* Offset */  \
      0,                                                   /* Max advance */  \
      0,                                                   /* Max retard */  \
      0,                                                   /* Event */  \
      Core0_OsTask_Appl_10ms                               /* Task */  \
    },  \
    {  \
      150,                                                 /* Offset */  \
      0,                                                   /* Max advance */  \
      0,                                                   /* Max retard */  \
      0,                                                   /* Event */  \
      Core0_OsTask_Appl_5ms                                /* Task */  \
    },  \
    {  \
      150,                                                 /* Offset */  \
      0,                                                   /* Max advance */  \
      0,                                                   /* Max retard */  \
      0,                                                   /* Event */  \
      Core0_OsTask_FunctionSafety_5ms                      /* Task */  \
    },  \
    {  \
      150,                                                 /* Offset */  \
      0,                                                   /* Max advance */  \
      0,                                                   /* Max retard */  \
      Rte_OSTimingEvent_Core0_OsTask_Bsw_5ms_TE_C81871CF733B997334C7E18C4B5DB17E,  /* Events */  \
      Core0_OsTask_Bsw_5ms                                 /* Task */  \
    },  \
    {  \
      150,                                                 /* Offset */  \
      0,                                                   /* Max advance */  \
      0,                                                   /* Max retard */  \
      Rte_OSTimingEvent_Core0_OsTask_Appl_60ms_TE_344FB9C7D2E189EB211BC438F55F3A79,  /* Events */  \
      Core0_OsTask_Appl_60ms                               /* Task */  \
    },  \
    /* EP_155000 */  \
    {  \
      155,                                                 /* Offset */  \
      0,                                                   /* Max advance */  \
      0,                                                   /* Max retard */  \
      0,                                                   /* Event */  \
      Core0_OsTask_Appl_5ms                                /* Task */  \
    },  \
    {  \
      155,                                                 /* Offset */  \
      0,                                                   /* Max advance */  \
      0,                                                   /* Max retard */  \
      0,                                                   /* Event */  \
      Core0_OsTask_FunctionSafety_5ms                      /* Task */  \
    },  \
    {  \
      155,                                                 /* Offset */  \
      0,                                                   /* Max advance */  \
      0,                                                   /* Max retard */  \
      Rte_OSTimingEvent_Core0_OsTask_Bsw_5ms_TE_C81871CF733B997334C7E18C4B5DB17E,  /* Events */  \
      Core0_OsTask_Bsw_5ms                                 /* Task */  \
    },  \
    /* EP_160000 */  \
    {  \
      160,                                                 /* Offset */  \
      0,                                                   /* Max advance */  \
      0,                                                   /* Max retard */  \
      0,                                                   /* Event */  \
      Core0_OsTask_Appl_10ms                               /* Task */  \
    },  \
    {  \
      160,                                                 /* Offset */  \
      0,                                                   /* Max advance */  \
      0,                                                   /* Max retard */  \
      0,                                                   /* Event */  \
      Core0_OsTask_Appl_5ms                                /* Task */  \
    },  \
    {  \
      160,                                                 /* Offset */  \
      0,                                                   /* Max advance */  \
      0,                                                   /* Max retard */  \
      0,                                                   /* Event */  \
      Core0_OsTask_FunctionSafety_5ms                      /* Task */  \
    },  \
    {  \
      160,                                                 /* Offset */  \
      0,                                                   /* Max advance */  \
      0,                                                   /* Max retard */  \
      Rte_OSTimingEvent_Core0_OsTask_Bsw_5ms_TE_C81871CF733B997334C7E18C4B5DB17E,  /* Events */  \
      Core0_OsTask_Bsw_5ms                                 /* Task */  \
    },  \
    {  \
      160,                                                 /* Offset */  \
      0,                                                   /* Max advance */  \
      0,                                                   /* Max retard */  \
      Rte_OSTimingEvent_Core0_OsTask_Appl_20ms_TE_F97F7A2ECAEA3A4FE9A6468E6E83C78D,  /* Events */  \
      Core0_OsTask_Appl_20ms                               /* Task */  \
    },  \
    /* EP_165000 */  \
    {  \
      165,                                                 /* Offset */  \
      0,                                                   /* Max advance */  \
      0,                                                   /* Max retard */  \
      0,                                                   /* Event */  \
      Core0_OsTask_Appl_5ms                                /* Task */  \
    },  \
    {  \
      165,                                                 /* Offset */  \
      0,                                                   /* Max advance */  \
      0,                                                   /* Max retard */  \
      0,                                                   /* Event */  \
      Core0_OsTask_FunctionSafety_5ms                      /* Task */  \
    },  \
    {  \
      165,                                                 /* Offset */  \
      0,                                                   /* Max advance */  \
      0,                                                   /* Max retard */  \
      Rte_OSTimingEvent_Core0_OsTask_Bsw_5ms_TE_C81871CF733B997334C7E18C4B5DB17E,  /* Events */  \
      Core0_OsTask_Bsw_5ms                                 /* Task */  \
    },  \
    /* EP_170000 */  \
    {  \
      170,                                                 /* Offset */  \
      0,                                                   /* Max advance */  \
      0,                                                   /* Max retard */  \
      0,                                                   /* Event */  \
      Core0_OsTask_Appl_10ms                               /* Task */  \
    },  \
    {  \
      170,                                                 /* Offset */  \
      0,                                                   /* Max advance */  \
      0,                                                   /* Max retard */  \
      0,                                                   /* Event */  \
      Core0_OsTask_Appl_5ms                                /* Task */  \
    },  \
    {  \
      170,                                                 /* Offset */  \
      0,                                                   /* Max advance */  \
      0,                                                   /* Max retard */  \
      0,                                                   /* Event */  \
      Core0_OsTask_FunctionSafety_5ms                      /* Task */  \
    },  \
    {  \
      170,                                                 /* Offset */  \
      0,                                                   /* Max advance */  \
      0,                                                   /* Max retard */  \
      Rte_OSTimingEvent_Core0_OsTask_Bsw_5ms_TE_C81871CF733B997334C7E18C4B5DB17E,  /* Events */  \
      Core0_OsTask_Bsw_5ms                                 /* Task */  \
    },  \
    /* EP_175000 */  \
    {  \
      175,                                                 /* Offset */  \
      0,                                                   /* Max advance */  \
      0,                                                   /* Max retard */  \
      0,                                                   /* Event */  \
      Core0_OsTask_Appl_5ms                                /* Task */  \
    },  \
    {  \
      175,                                                 /* Offset */  \
      0,                                                   /* Max advance */  \
      0,                                                   /* Max retard */  \
      0,                                                   /* Event */  \
      Core0_OsTask_FunctionSafety_5ms                      /* Task */  \
    },  \
    {  \
      175,                                                 /* Offset */  \
      0,                                                   /* Max advance */  \
      0,                                                   /* Max retard */  \
      Rte_OSTimingEvent_Core0_OsTask_Bsw_5ms_TE_C81871CF733B997334C7E18C4B5DB17E,  /* Events */  \
      Core0_OsTask_Bsw_5ms                                 /* Task */  \
    },  \
    /* EP_180000 */  \
    {  \
      180,                                                 /* Offset */  \
      0,                                                   /* Max advance */  \
      0,                                                   /* Max retard */  \
      0,                                                   /* Event */  \
      Core0_OsTask_Appl_10ms                               /* Task */  \
    },  \
    {  \
      180,                                                 /* Offset */  \
      0,                                                   /* Max advance */  \
      0,                                                   /* Max retard */  \
      0,                                                   /* Event */  \
      Core0_OsTask_Appl_5ms                                /* Task */  \
    },  \
    {  \
      180,                                                 /* Offset */  \
      0,                                                   /* Max advance */  \
      0,                                                   /* Max retard */  \
      0,                                                   /* Event */  \
      Core0_OsTask_FunctionSafety_5ms                      /* Task */  \
    },  \
    {  \
      180,                                                 /* Offset */  \
      0,                                                   /* Max advance */  \
      0,                                                   /* Max retard */  \
      Rte_OSTimingEvent_Core0_OsTask_Bsw_5ms_TE_C81871CF733B997334C7E18C4B5DB17E,  /* Events */  \
      Core0_OsTask_Bsw_5ms                                 /* Task */  \
    },  \
    {  \
      180,                                                 /* Offset */  \
      0,                                                   /* Max advance */  \
      0,                                                   /* Max retard */  \
      Rte_OSTimingEvent_Core0_OsTask_Appl_20ms_TE_F97F7A2ECAEA3A4FE9A6468E6E83C78D,  /* Events */  \
      Core0_OsTask_Appl_20ms                               /* Task */  \
    },  \
    {  \
      180,                                                 /* Offset */  \
      0,                                                   /* Max advance */  \
      0,                                                   /* Max retard */  \
      Rte_OSTimingEvent_Core0_OsTask_Appl_60ms_TE_EF84604C92A30BF324A2DEF1D82825FD,  /* Events */  \
      Core0_OsTask_Appl_60ms                               /* Task */  \
    },  \
    /* EP_185000 */  \
    {  \
      185,                                                 /* Offset */  \
      0,                                                   /* Max advance */  \
      0,                                                   /* Max retard */  \
      0,                                                   /* Event */  \
      Core0_OsTask_Appl_5ms                                /* Task */  \
    },  \
    {  \
      185,                                                 /* Offset */  \
      0,                                                   /* Max advance */  \
      0,                                                   /* Max retard */  \
      0,                                                   /* Event */  \
      Core0_OsTask_FunctionSafety_5ms                      /* Task */  \
    },  \
    {  \
      185,                                                 /* Offset */  \
      0,                                                   /* Max advance */  \
      0,                                                   /* Max retard */  \
      Rte_OSTimingEvent_Core0_OsTask_Bsw_5ms_TE_C81871CF733B997334C7E18C4B5DB17E,  /* Events */  \
      Core0_OsTask_Bsw_5ms                                 /* Task */  \
    },  \
    /* EP_190000 */  \
    {  \
      190,                                                 /* Offset */  \
      0,                                                   /* Max advance */  \
      0,                                                   /* Max retard */  \
      0,                                                   /* Event */  \
      Core0_OsTask_Appl_10ms                               /* Task */  \
    },  \
    {  \
      190,                                                 /* Offset */  \
      0,                                                   /* Max advance */  \
      0,                                                   /* Max retard */  \
      0,                                                   /* Event */  \
      Core0_OsTask_Appl_5ms                                /* Task */  \
    },  \
    {  \
      190,                                                 /* Offset */  \
      0,                                                   /* Max advance */  \
      0,                                                   /* Max retard */  \
      0,                                                   /* Event */  \
      Core0_OsTask_FunctionSafety_5ms                      /* Task */  \
    },  \
    {  \
      190,                                                 /* Offset */  \
      0,                                                   /* Max advance */  \
      0,                                                   /* Max retard */  \
      Rte_OSTimingEvent_Core0_OsTask_Bsw_5ms_TE_C81871CF733B997334C7E18C4B5DB17E,  /* Events */  \
      Core0_OsTask_Bsw_5ms                                 /* Task */  \
    },  \
    /* EP_195000 */  \
    {  \
      195,                                                 /* Offset */  \
      0,                                                   /* Max advance */  \
      0,                                                   /* Max retard */  \
      0,                                                   /* Event */  \
      Core0_OsTask_Appl_5ms                                /* Task */  \
    },  \
    {  \
      195,                                                 /* Offset */  \
      0,                                                   /* Max advance */  \
      0,                                                   /* Max retard */  \
      0,                                                   /* Event */  \
      Core0_OsTask_FunctionSafety_5ms                      /* Task */  \
    },  \
    {  \
      195,                                                 /* Offset */  \
      0,                                                   /* Max advance */  \
      0,                                                   /* Max retard */  \
      Rte_OSTimingEvent_Core0_OsTask_Bsw_5ms_TE_C81871CF733B997334C7E18C4B5DB17E,  /* Events */  \
      Core0_OsTask_Bsw_5ms                                 /* Task */  \
    },  \
    /* EP_200000 */  \
    {  \
      200,                                                 /* Offset */  \
      0,                                                   /* Max advance */  \
      0,                                                   /* Max retard */  \
      0,                                                   /* Event */  \
      Core0_OsTask_Appl_10ms                               /* Task */  \
    },  \
    {  \
      200,                                                 /* Offset */  \
      0,                                                   /* Max advance */  \
      0,                                                   /* Max retard */  \
      0,                                                   /* Event */  \
      Core0_OsTask_Appl_5ms                                /* Task */  \
    },  \
    {  \
      200,                                                 /* Offset */  \
      0,                                                   /* Max advance */  \
      0,                                                   /* Max retard */  \
      0,                                                   /* Event */  \
      Core0_OsTask_FunctionSafety_5ms                      /* Task */  \
    },  \
    {  \
      200,                                                 /* Offset */  \
      0,                                                   /* Max advance */  \
      0,                                                   /* Max retard */  \
      Rte_OSTimingEvent_Core0_OsTask_Bsw_5ms_TE_C81871CF733B997334C7E18C4B5DB17E,  /* Events */  \
      Core0_OsTask_Bsw_5ms                                 /* Task */  \
    },  \
    {  \
      200,                                                 /* Offset */  \
      0,                                                   /* Max advance */  \
      0,                                                   /* Max retard */  \
      Rte_OSTimingEvent_Core0_OsTask_Appl_20ms_TE_F97F7A2ECAEA3A4FE9A6468E6E83C78D,  /* Events */  \
      Core0_OsTask_Appl_20ms                               /* Task */  \
    },  \
    {  \
      200,                                                 /* Offset */  \
      0,                                                   /* Max advance */  \
      0,                                                   /* Max retard */  \
      Rte_OSTimingEvent_Core0_OsTask_Appl_60ms_TE_344FB9C7D2E189EB211BC438F55F3A79,  /* Events */  \
      Core0_OsTask_Appl_60ms                               /* Task */  \
    },  \
    /* EP_205000 */  \
    {  \
      205,                                                 /* Offset */  \
      0,                                                   /* Max advance */  \
      0,                                                   /* Max retard */  \
      0,                                                   /* Event */  \
      Core0_OsTask_Appl_5ms                                /* Task */  \
    },  \
    {  \
      205,                                                 /* Offset */  \
      0,                                                   /* Max advance */  \
      0,                                                   /* Max retard */  \
      0,                                                   /* Event */  \
      Core0_OsTask_FunctionSafety_5ms                      /* Task */  \
    },  \
    {  \
      205,                                                 /* Offset */  \
      0,                                                   /* Max advance */  \
      0,                                                   /* Max retard */  \
      Rte_OSTimingEvent_Core0_OsTask_Bsw_5ms_TE_C81871CF733B997334C7E18C4B5DB17E,  /* Events */  \
      Core0_OsTask_Bsw_5ms                                 /* Task */  \
    },  \
    /* EP_210000 */  \
    {  \
      210,                                                 /* Offset */  \
      0,                                                   /* Max advance */  \
      0,                                                   /* Max retard */  \
      0,                                                   /* Event */  \
      Core0_OsTask_Appl_10ms                               /* Task */  \
    },  \
    {  \
      210,                                                 /* Offset */  \
      0,                                                   /* Max advance */  \
      0,                                                   /* Max retard */  \
      0,                                                   /* Event */  \
      Core0_OsTask_Appl_5ms                                /* Task */  \
    },  \
    {  \
      210,                                                 /* Offset */  \
      0,                                                   /* Max advance */  \
      0,                                                   /* Max retard */  \
      0,                                                   /* Event */  \
      Core0_OsTask_FunctionSafety_5ms                      /* Task */  \
    },  \
    {  \
      210,                                                 /* Offset */  \
      0,                                                   /* Max advance */  \
      0,                                                   /* Max retard */  \
      Rte_OSTimingEvent_Core0_OsTask_Bsw_5ms_TE_C81871CF733B997334C7E18C4B5DB17E,  /* Events */  \
      Core0_OsTask_Bsw_5ms                                 /* Task */  \
    },  \
    /* EP_215000 */  \
    {  \
      215,                                                 /* Offset */  \
      0,                                                   /* Max advance */  \
      0,                                                   /* Max retard */  \
      0,                                                   /* Event */  \
      Core0_OsTask_Appl_5ms                                /* Task */  \
    },  \
    {  \
      215,                                                 /* Offset */  \
      0,                                                   /* Max advance */  \
      0,                                                   /* Max retard */  \
      0,                                                   /* Event */  \
      Core0_OsTask_FunctionSafety_5ms                      /* Task */  \
    },  \
    {  \
      215,                                                 /* Offset */  \
      0,                                                   /* Max advance */  \
      0,                                                   /* Max retard */  \
      Rte_OSTimingEvent_Core0_OsTask_Bsw_5ms_TE_C81871CF733B997334C7E18C4B5DB17E,  /* Events */  \
      Core0_OsTask_Bsw_5ms                                 /* Task */  \
    },  \
    /* EP_220000 */  \
    {  \
      220,                                                 /* Offset */  \
      0,                                                   /* Max advance */  \
      0,                                                   /* Max retard */  \
      0,                                                   /* Event */  \
      Core0_OsTask_Appl_10ms                               /* Task */  \
    },  \
    {  \
      220,                                                 /* Offset */  \
      0,                                                   /* Max advance */  \
      0,                                                   /* Max retard */  \
      0,                                                   /* Event */  \
      Core0_OsTask_Appl_5ms                                /* Task */  \
    },  \
    {  \
      220,                                                 /* Offset */  \
      0,                                                   /* Max advance */  \
      0,                                                   /* Max retard */  \
      0,                                                   /* Event */  \
      Core0_OsTask_FunctionSafety_5ms                      /* Task */  \
    },  \
    {  \
      220,                                                 /* Offset */  \
      0,                                                   /* Max advance */  \
      0,                                                   /* Max retard */  \
      Rte_OSTimingEvent_Core0_OsTask_Bsw_5ms_TE_C81871CF733B997334C7E18C4B5DB17E,  /* Events */  \
      Core0_OsTask_Bsw_5ms                                 /* Task */  \
    },  \
    {  \
      220,                                                 /* Offset */  \
      0,                                                   /* Max advance */  \
      0,                                                   /* Max retard */  \
      Rte_OSTimingEvent_Core0_OsTask_Appl_20ms_TE_F97F7A2ECAEA3A4FE9A6468E6E83C78D,  /* Events */  \
      Core0_OsTask_Appl_20ms                               /* Task */  \
    },  \
    /* EP_225000 */  \
    {  \
      225,                                                 /* Offset */  \
      0,                                                   /* Max advance */  \
      0,                                                   /* Max retard */  \
      0,                                                   /* Event */  \
      Core0_OsTask_Appl_5ms                                /* Task */  \
    },  \
    {  \
      225,                                                 /* Offset */  \
      0,                                                   /* Max advance */  \
      0,                                                   /* Max retard */  \
      0,                                                   /* Event */  \
      Core0_OsTask_FunctionSafety_5ms                      /* Task */  \
    },  \
    {  \
      225,                                                 /* Offset */  \
      0,                                                   /* Max advance */  \
      0,                                                   /* Max retard */  \
      Rte_OSTimingEvent_Core0_OsTask_Bsw_5ms_TE_C81871CF733B997334C7E18C4B5DB17E,  /* Events */  \
      Core0_OsTask_Bsw_5ms                                 /* Task */  \
    },  \
    /* EP_230000 */  \
    {  \
      230,                                                 /* Offset */  \
      0,                                                   /* Max advance */  \
      0,                                                   /* Max retard */  \
      0,                                                   /* Event */  \
      Core0_OsTask_Appl_10ms                               /* Task */  \
    },  \
    {  \
      230,                                                 /* Offset */  \
      0,                                                   /* Max advance */  \
      0,                                                   /* Max retard */  \
      0,                                                   /* Event */  \
      Core0_OsTask_Appl_5ms                                /* Task */  \
    },  \
    {  \
      230,                                                 /* Offset */  \
      0,                                                   /* Max advance */  \
      0,                                                   /* Max retard */  \
      0,                                                   /* Event */  \
      Core0_OsTask_FunctionSafety_5ms                      /* Task */  \
    },  \
    {  \
      230,                                                 /* Offset */  \
      0,                                                   /* Max advance */  \
      0,                                                   /* Max retard */  \
      Rte_OSTimingEvent_Core0_OsTask_Bsw_5ms_TE_C81871CF733B997334C7E18C4B5DB17E,  /* Events */  \
      Core0_OsTask_Bsw_5ms                                 /* Task */  \
    },  \
    /* EP_235000 */  \
    {  \
      235,                                                 /* Offset */  \
      0,                                                   /* Max advance */  \
      0,                                                   /* Max retard */  \
      0,                                                   /* Event */  \
      Core0_OsTask_Appl_5ms                                /* Task */  \
    },  \
    {  \
      235,                                                 /* Offset */  \
      0,                                                   /* Max advance */  \
      0,                                                   /* Max retard */  \
      0,                                                   /* Event */  \
      Core0_OsTask_FunctionSafety_5ms                      /* Task */  \
    },  \
    {  \
      235,                                                 /* Offset */  \
      0,                                                   /* Max advance */  \
      0,                                                   /* Max retard */  \
      Rte_OSTimingEvent_Core0_OsTask_Bsw_5ms_TE_C81871CF733B997334C7E18C4B5DB17E,  /* Events */  \
      Core0_OsTask_Bsw_5ms                                 /* Task */  \
    },  \
    /* EP_240000 */  \
    {  \
      240,                                                 /* Offset */  \
      0,                                                   /* Max advance */  \
      0,                                                   /* Max retard */  \
      0,                                                   /* Event */  \
      Core0_OsTask_Appl_10ms                               /* Task */  \
    },  \
    {  \
      240,                                                 /* Offset */  \
      0,                                                   /* Max advance */  \
      0,                                                   /* Max retard */  \
      0,                                                   /* Event */  \
      Core0_OsTask_Appl_5ms                                /* Task */  \
    },  \
    {  \
      240,                                                 /* Offset */  \
      0,                                                   /* Max advance */  \
      0,                                                   /* Max retard */  \
      0,                                                   /* Event */  \
      Core0_OsTask_FunctionSafety_5ms                      /* Task */  \
    },  \
    {  \
      240,                                                 /* Offset */  \
      0,                                                   /* Max advance */  \
      0,                                                   /* Max retard */  \
      Rte_OSTimingEvent_Core0_OsTask_Bsw_5ms_TE_C81871CF733B997334C7E18C4B5DB17E,  /* Events */  \
      Core0_OsTask_Bsw_5ms                                 /* Task */  \
    },  \
    {  \
      240,                                                 /* Offset */  \
      0,                                                   /* Max advance */  \
      0,                                                   /* Max retard */  \
      Rte_OSTimingEvent_Core0_OsTask_Appl_20ms_TE_F97F7A2ECAEA3A4FE9A6468E6E83C78D,  /* Events */  \
      Core0_OsTask_Appl_20ms                               /* Task */  \
    },  \
    {  \
      240,                                                 /* Offset */  \
      0,                                                   /* Max advance */  \
      0,                                                   /* Max retard */  \
      Rte_OSTimingEvent_Core0_OsTask_Appl_60ms_TE_EF84604C92A30BF324A2DEF1D82825FD,  /* Events */  \
      Core0_OsTask_Appl_60ms                               /* Task */  \
    },  \
    /* EP_245000 */  \
    {  \
      245,                                                 /* Offset */  \
      0,                                                   /* Max advance */  \
      0,                                                   /* Max retard */  \
      0,                                                   /* Event */  \
      Core0_OsTask_Appl_5ms                                /* Task */  \
    },  \
    {  \
      245,                                                 /* Offset */  \
      0,                                                   /* Max advance */  \
      0,                                                   /* Max retard */  \
      0,                                                   /* Event */  \
      Core0_OsTask_FunctionSafety_5ms                      /* Task */  \
    },  \
    {  \
      245,                                                 /* Offset */  \
      0,                                                   /* Max advance */  \
      0,                                                   /* Max retard */  \
      Rte_OSTimingEvent_Core0_OsTask_Bsw_5ms_TE_C81871CF733B997334C7E18C4B5DB17E,  /* Events */  \
      Core0_OsTask_Bsw_5ms                                 /* Task */  \
    },  \
    /* EP_250000 */  \
    {  \
      250,                                                 /* Offset */  \
      0,                                                   /* Max advance */  \
      0,                                                   /* Max retard */  \
      0,                                                   /* Event */  \
      Core0_OsTask_Appl_10ms                               /* Task */  \
    },  \
    {  \
      250,                                                 /* Offset */  \
      0,                                                   /* Max advance */  \
      0,                                                   /* Max retard */  \
      0,                                                   /* Event */  \
      Core0_OsTask_Appl_5ms                                /* Task */  \
    },  \
    {  \
      250,                                                 /* Offset */  \
      0,                                                   /* Max advance */  \
      0,                                                   /* Max retard */  \
      0,                                                   /* Event */  \
      Core0_OsTask_FunctionSafety_5ms                      /* Task */  \
    },  \
    {  \
      250,                                                 /* Offset */  \
      0,                                                   /* Max advance */  \
      0,                                                   /* Max retard */  \
      Rte_OSTimingEvent_Core0_OsTask_Bsw_5ms_TE_C81871CF733B997334C7E18C4B5DB17E,  /* Events */  \
      Core0_OsTask_Bsw_5ms                                 /* Task */  \
    },  \
    {  \
      250,                                                 /* Offset */  \
      0,                                                   /* Max advance */  \
      0,                                                   /* Max retard */  \
      Rte_OSTimingEvent_Core0_OsTask_Appl_60ms_TE_344FB9C7D2E189EB211BC438F55F3A79,  /* Events */  \
      Core0_OsTask_Appl_60ms                               /* Task */  \
    },  \
    /* EP_255000 */  \
    {  \
      255,                                                 /* Offset */  \
      0,                                                   /* Max advance */  \
      0,                                                   /* Max retard */  \
      0,                                                   /* Event */  \
      Core0_OsTask_Appl_5ms                                /* Task */  \
    },  \
    {  \
      255,                                                 /* Offset */  \
      0,                                                   /* Max advance */  \
      0,                                                   /* Max retard */  \
      0,                                                   /* Event */  \
      Core0_OsTask_FunctionSafety_5ms                      /* Task */  \
    },  \
    {  \
      255,                                                 /* Offset */  \
      0,                                                   /* Max advance */  \
      0,                                                   /* Max retard */  \
      Rte_OSTimingEvent_Core0_OsTask_Bsw_5ms_TE_C81871CF733B997334C7E18C4B5DB17E,  /* Events */  \
      Core0_OsTask_Bsw_5ms                                 /* Task */  \
    },  \
    /* EP_260000 */  \
    {  \
      260,                                                 /* Offset */  \
      0,                                                   /* Max advance */  \
      0,                                                   /* Max retard */  \
      0,                                                   /* Event */  \
      Core0_OsTask_Appl_10ms                               /* Task */  \
    },  \
    {  \
      260,                                                 /* Offset */  \
      0,                                                   /* Max advance */  \
      0,                                                   /* Max retard */  \
      0,                                                   /* Event */  \
      Core0_OsTask_Appl_5ms                                /* Task */  \
    },  \
    {  \
      260,                                                 /* Offset */  \
      0,                                                   /* Max advance */  \
      0,                                                   /* Max retard */  \
      0,                                                   /* Event */  \
      Core0_OsTask_FunctionSafety_5ms                      /* Task */  \
    },  \
    {  \
      260,                                                 /* Offset */  \
      0,                                                   /* Max advance */  \
      0,                                                   /* Max retard */  \
      Rte_OSTimingEvent_Core0_OsTask_Bsw_5ms_TE_C81871CF733B997334C7E18C4B5DB17E,  /* Events */  \
      Core0_OsTask_Bsw_5ms                                 /* Task */  \
    },  \
    {  \
      260,                                                 /* Offset */  \
      0,                                                   /* Max advance */  \
      0,                                                   /* Max retard */  \
      Rte_OSTimingEvent_Core0_OsTask_Appl_20ms_TE_F97F7A2ECAEA3A4FE9A6468E6E83C78D,  /* Events */  \
      Core0_OsTask_Appl_20ms                               /* Task */  \
    },  \
    /* EP_265000 */  \
    {  \
      265,                                                 /* Offset */  \
      0,                                                   /* Max advance */  \
      0,                                                   /* Max retard */  \
      0,                                                   /* Event */  \
      Core0_OsTask_Appl_5ms                                /* Task */  \
    },  \
    {  \
      265,                                                 /* Offset */  \
      0,                                                   /* Max advance */  \
      0,                                                   /* Max retard */  \
      0,                                                   /* Event */  \
      Core0_OsTask_FunctionSafety_5ms                      /* Task */  \
    },  \
    {  \
      265,                                                 /* Offset */  \
      0,                                                   /* Max advance */  \
      0,                                                   /* Max retard */  \
      Rte_OSTimingEvent_Core0_OsTask_Bsw_5ms_TE_C81871CF733B997334C7E18C4B5DB17E,  /* Events */  \
      Core0_OsTask_Bsw_5ms                                 /* Task */  \
    },  \
    /* EP_270000 */  \
    {  \
      270,                                                 /* Offset */  \
      0,                                                   /* Max advance */  \
      0,                                                   /* Max retard */  \
      0,                                                   /* Event */  \
      Core0_OsTask_Appl_10ms                               /* Task */  \
    },  \
    {  \
      270,                                                 /* Offset */  \
      0,                                                   /* Max advance */  \
      0,                                                   /* Max retard */  \
      0,                                                   /* Event */  \
      Core0_OsTask_Appl_5ms                                /* Task */  \
    },  \
    {  \
      270,                                                 /* Offset */  \
      0,                                                   /* Max advance */  \
      0,                                                   /* Max retard */  \
      0,                                                   /* Event */  \
      Core0_OsTask_FunctionSafety_5ms                      /* Task */  \
    },  \
    {  \
      270,                                                 /* Offset */  \
      0,                                                   /* Max advance */  \
      0,                                                   /* Max retard */  \
      Rte_OSTimingEvent_Core0_OsTask_Bsw_5ms_TE_C81871CF733B997334C7E18C4B5DB17E,  /* Events */  \
      Core0_OsTask_Bsw_5ms                                 /* Task */  \
    },  \
    /* EP_275000 */  \
    {  \
      275,                                                 /* Offset */  \
      0,                                                   /* Max advance */  \
      0,                                                   /* Max retard */  \
      0,                                                   /* Event */  \
      Core0_OsTask_Appl_5ms                                /* Task */  \
    },  \
    {  \
      275,                                                 /* Offset */  \
      0,                                                   /* Max advance */  \
      0,                                                   /* Max retard */  \
      0,                                                   /* Event */  \
      Core0_OsTask_FunctionSafety_5ms                      /* Task */  \
    },  \
    {  \
      275,                                                 /* Offset */  \
      0,                                                   /* Max advance */  \
      0,                                                   /* Max retard */  \
      Rte_OSTimingEvent_Core0_OsTask_Bsw_5ms_TE_C81871CF733B997334C7E18C4B5DB17E,  /* Events */  \
      Core0_OsTask_Bsw_5ms                                 /* Task */  \
    },  \
    /* EP_280000 */  \
    {  \
      280,                                                 /* Offset */  \
      0,                                                   /* Max advance */  \
      0,                                                   /* Max retard */  \
      0,                                                   /* Event */  \
      Core0_OsTask_Appl_10ms                               /* Task */  \
    },  \
    {  \
      280,                                                 /* Offset */  \
      0,                                                   /* Max advance */  \
      0,                                                   /* Max retard */  \
      0,                                                   /* Event */  \
      Core0_OsTask_Appl_5ms                                /* Task */  \
    },  \
    {  \
      280,                                                 /* Offset */  \
      0,                                                   /* Max advance */  \
      0,                                                   /* Max retard */  \
      0,                                                   /* Event */  \
      Core0_OsTask_FunctionSafety_5ms                      /* Task */  \
    },  \
    {  \
      280,                                                 /* Offset */  \
      0,                                                   /* Max advance */  \
      0,                                                   /* Max retard */  \
      Rte_OSTimingEvent_Core0_OsTask_Bsw_5ms_TE_C81871CF733B997334C7E18C4B5DB17E,  /* Events */  \
      Core0_OsTask_Bsw_5ms                                 /* Task */  \
    },  \
    {  \
      280,                                                 /* Offset */  \
      0,                                                   /* Max advance */  \
      0,                                                   /* Max retard */  \
      Rte_OSTimingEvent_Core0_OsTask_Appl_20ms_TE_F97F7A2ECAEA3A4FE9A6468E6E83C78D,  /* Events */  \
      Core0_OsTask_Appl_20ms                               /* Task */  \
    },  \
    /* EP_285000 */  \
    {  \
      285,                                                 /* Offset */  \
      0,                                                   /* Max advance */  \
      0,                                                   /* Max retard */  \
      0,                                                   /* Event */  \
      Core0_OsTask_Appl_5ms                                /* Task */  \
    },  \
    {  \
      285,                                                 /* Offset */  \
      0,                                                   /* Max advance */  \
      0,                                                   /* Max retard */  \
      0,                                                   /* Event */  \
      Core0_OsTask_FunctionSafety_5ms                      /* Task */  \
    },  \
    {  \
      285,                                                 /* Offset */  \
      0,                                                   /* Max advance */  \
      0,                                                   /* Max retard */  \
      Rte_OSTimingEvent_Core0_OsTask_Bsw_5ms_TE_C81871CF733B997334C7E18C4B5DB17E,  /* Events */  \
      Core0_OsTask_Bsw_5ms                                 /* Task */  \
    },  \
    /* EP_290000 */  \
    {  \
      290,                                                 /* Offset */  \
      0,                                                   /* Max advance */  \
      0,                                                   /* Max retard */  \
      0,                                                   /* Event */  \
      Core0_OsTask_Appl_10ms                               /* Task */  \
    },  \
    {  \
      290,                                                 /* Offset */  \
      0,                                                   /* Max advance */  \
      0,                                                   /* Max retard */  \
      0,                                                   /* Event */  \
      Core0_OsTask_Appl_5ms                                /* Task */  \
    },  \
    {  \
      290,                                                 /* Offset */  \
      0,                                                   /* Max advance */  \
      0,                                                   /* Max retard */  \
      0,                                                   /* Event */  \
      Core0_OsTask_FunctionSafety_5ms                      /* Task */  \
    },  \
    {  \
      290,                                                 /* Offset */  \
      0,                                                   /* Max advance */  \
      0,                                                   /* Max retard */  \
      Rte_OSTimingEvent_Core0_OsTask_Bsw_5ms_TE_C81871CF733B997334C7E18C4B5DB17E,  /* Events */  \
      Core0_OsTask_Bsw_5ms                                 /* Task */  \
    },  \
    /* EP_295000 */  \
    {  \
      295,                                                 /* Offset */  \
      0,                                                   /* Max advance */  \
      0,                                                   /* Max retard */  \
      0,                                                   /* Event */  \
      Core0_OsTask_Appl_5ms                                /* Task */  \
    },  \
    {  \
      295,                                                 /* Offset */  \
      0,                                                   /* Max advance */  \
      0,                                                   /* Max retard */  \
      0,                                                   /* Event */  \
      Core0_OsTask_FunctionSafety_5ms                      /* Task */  \
    },  \
    {  \
      295,                                                 /* Offset */  \
      0,                                                   /* Max advance */  \
      0,                                                   /* Max retard */  \
      Rte_OSTimingEvent_Core0_OsTask_Bsw_5ms_TE_C81871CF733B997334C7E18C4B5DB17E,  /* Events */  \
      Core0_OsTask_Bsw_5ms                                 /* Task */  \
    },  \
    /* EP_0 */  \
    {  \
      0,                                                   /* Offset */  \
      0,                                                   /* Max advance */  \
      0,                                                   /* Max retard */  \
      Rte_OSTimingEvent_Core1_OsTask_Bsw_20ms_TE_3F85B53DA8A2367156B9DBD85092648F | Rte_OSTimingEvent_Core1_OsTask_Bsw_20ms_TE_9239C5A54F3433A5ED9A15C3877ED11B,  /* Events */  \
      Core1_OsTask_Bsw_20ms                                /* Task */  \
    },  \
    {  \
      0,                                                   /* Offset */  \
      0,                                                   /* Max advance */  \
      0,                                                   /* Max retard */  \
      Rte_OSTimingEvent_Core1_OsTask_Appl_10ms_TE_4FEAAB8C3BCDA73855D3E70C1E051D1F,  /* Events */  \
      Core1_OsTask_Appl_10ms                               /* Task */  \
    },  \
    /* EP_5000 */  \
    {  \
      5,                                                   /* Offset */  \
      0,                                                   /* Max advance */  \
      0,                                                   /* Max retard */  \
      Rte_OSTimingEvent_Core1_OsTask_Appl_10ms_TE_4FEAAB8C3BCDA73855D3E70C1E051D1F,  /* Events */  \
      Core1_OsTask_Appl_10ms                               /* Task */  \
    },  \
    /* EP_10000 */  \
    {  \
      10,                                                  /* Offset */  \
      0,                                                   /* Max advance */  \
      0,                                                   /* Max retard */  \
      Rte_OSTimingEvent_Core1_OsTask_Bsw_20ms_TE_9239C5A54F3433A5ED9A15C3877ED11B,  /* Events */  \
      Core1_OsTask_Bsw_20ms                                /* Task */  \
    },  \
    {  \
      10,                                                  /* Offset */  \
      0,                                                   /* Max advance */  \
      0,                                                   /* Max retard */  \
      Rte_OSTimingEvent_Core1_OsTask_Appl_10ms_TE_4FEAAB8C3BCDA73855D3E70C1E051D1F,  /* Events */  \
      Core1_OsTask_Appl_10ms                               /* Task */  \
    },  \
    /* EP_15000 */  \
    {  \
      15,                                                  /* Offset */  \
      0,                                                   /* Max advance */  \
      0,                                                   /* Max retard */  \
      Rte_OSTimingEvent_Core1_OsTask_Appl_10ms_TE_4FEAAB8C3BCDA73855D3E70C1E051D1F,  /* Events */  \
      Core1_OsTask_Appl_10ms                               /* Task */  \
    },  \
    /* EP_0 */  \
    {  \
      0,                                                   /* Offset */  \
      0,                                                   /* Max advance */  \
      0,                                                   /* Max retard */  \
      0,                                                   /* Event */  \
      Core1_OsTask_Appl_60ms                               /* Task */  \
    },  \
    {  \
      0,                                                   /* Offset */  \
      0,                                                   /* Max advance */  \
      0,                                                   /* Max retard */  \
      0,                                                   /* Event */  \
      Core1_OsTask_Appl_20ms                               /* Task */  \
    },  \
    {  \
      0,                                                   /* Offset */  \
      0,                                                   /* Max advance */  \
      0,                                                   /* Max retard */  \
      Rte_OSTimingEvent_Core1_OsTask_Bsw_20ms_TE_B040B4ED3027D1A3758BCA982B69EF51,  /* Events */  \
      Core1_OsTask_Bsw_20ms                                /* Task */  \
    },  \
    {  \
      0,                                                   /* Offset */  \
      0,                                                   /* Max advance */  \
      0,                                                   /* Max retard */  \
      Rte_OSTimingEvent_Core1_OsTask_Appl_10ms_TE_82A7CF7B79788AAC9ACECC46B60FBA35 | Rte_OSTimingEvent_Core1_OsTask_Appl_10ms_TE_B7D8AAA4EAF6595FD3CAC5E9F209B7C4,  /* Events */  \
      Core1_OsTask_Appl_10ms                               /* Task */  \
    },  \
    /* EP_20000 */  \
    {  \
      20,                                                  /* Offset */  \
      0,                                                   /* Max advance */  \
      0,                                                   /* Max retard */  \
      0,                                                   /* Event */  \
      Core1_OsTask_Appl_20ms                               /* Task */  \
    },  \
    {  \
      20,                                                  /* Offset */  \
      0,                                                   /* Max advance */  \
      0,                                                   /* Max retard */  \
      Rte_OSTimingEvent_Core1_OsTask_Bsw_20ms_TE_B040B4ED3027D1A3758BCA982B69EF51,  /* Events */  \
      Core1_OsTask_Bsw_20ms                                /* Task */  \
    },  \
    {  \
      20,                                                  /* Offset */  \
      0,                                                   /* Max advance */  \
      0,                                                   /* Max retard */  \
      Rte_OSTimingEvent_Core1_OsTask_Appl_10ms_TE_82A7CF7B79788AAC9ACECC46B60FBA35,  /* Events */  \
      Core1_OsTask_Appl_10ms                               /* Task */  \
    },  \
    /* EP_40000 */  \
    {  \
      40,                                                  /* Offset */  \
      0,                                                   /* Max advance */  \
      0,                                                   /* Max retard */  \
      0,                                                   /* Event */  \
      Core1_OsTask_Appl_20ms                               /* Task */  \
    },  \
    {  \
      40,                                                  /* Offset */  \
      0,                                                   /* Max advance */  \
      0,                                                   /* Max retard */  \
      Rte_OSTimingEvent_Core1_OsTask_Bsw_20ms_TE_B040B4ED3027D1A3758BCA982B69EF51,  /* Events */  \
      Core1_OsTask_Bsw_20ms                                /* Task */  \
    },  \
    {  \
      40,                                                  /* Offset */  \
      0,                                                   /* Max advance */  \
      0,                                                   /* Max retard */  \
      Rte_OSTimingEvent_Core1_OsTask_Appl_10ms_TE_82A7CF7B79788AAC9ACECC46B60FBA35,  /* Events */  \
      Core1_OsTask_Appl_10ms                               /* Task */  \
    },  \
    /* EP_50000 */  \
    {  \
      50,                                                  /* Offset */  \
      0,                                                   /* Max advance */  \
      0,                                                   /* Max retard */  \
      Rte_OSTimingEvent_Core1_OsTask_Appl_10ms_TE_B7D8AAA4EAF6595FD3CAC5E9F209B7C4,  /* Events */  \
      Core1_OsTask_Appl_10ms                               /* Task */  \
    },  \
    /* EP_60000 */  \
    {  \
      60,                                                  /* Offset */  \
      0,                                                   /* Max advance */  \
      0,                                                   /* Max retard */  \
      0,                                                   /* Event */  \
      Core1_OsTask_Appl_60ms                               /* Task */  \
    },  \
    {  \
      60,                                                  /* Offset */  \
      0,                                                   /* Max advance */  \
      0,                                                   /* Max retard */  \
      0,                                                   /* Event */  \
      Core1_OsTask_Appl_20ms                               /* Task */  \
    },  \
    {  \
      60,                                                  /* Offset */  \
      0,                                                   /* Max advance */  \
      0,                                                   /* Max retard */  \
      Rte_OSTimingEvent_Core1_OsTask_Bsw_20ms_TE_B040B4ED3027D1A3758BCA982B69EF51,  /* Events */  \
      Core1_OsTask_Bsw_20ms                                /* Task */  \
    },  \
    {  \
      60,                                                  /* Offset */  \
      0,                                                   /* Max advance */  \
      0,                                                   /* Max retard */  \
      Rte_OSTimingEvent_Core1_OsTask_Appl_10ms_TE_82A7CF7B79788AAC9ACECC46B60FBA35,  /* Events */  \
      Core1_OsTask_Appl_10ms                               /* Task */  \
    },  \
    /* EP_80000 */  \
    {  \
      80,                                                  /* Offset */  \
      0,                                                   /* Max advance */  \
      0,                                                   /* Max retard */  \
      0,                                                   /* Event */  \
      Core1_OsTask_Appl_20ms                               /* Task */  \
    },  \
    {  \
      80,                                                  /* Offset */  \
      0,                                                   /* Max advance */  \
      0,                                                   /* Max retard */  \
      Rte_OSTimingEvent_Core1_OsTask_Bsw_20ms_TE_B040B4ED3027D1A3758BCA982B69EF51,  /* Events */  \
      Core1_OsTask_Bsw_20ms                                /* Task */  \
    },  \
    {  \
      80,                                                  /* Offset */  \
      0,                                                   /* Max advance */  \
      0,                                                   /* Max retard */  \
      Rte_OSTimingEvent_Core1_OsTask_Appl_10ms_TE_82A7CF7B79788AAC9ACECC46B60FBA35,  /* Events */  \
      Core1_OsTask_Appl_10ms                               /* Task */  \
    },  \
    /* EP_100000 */  \
    {  \
      100,                                                 /* Offset */  \
      0,                                                   /* Max advance */  \
      0,                                                   /* Max retard */  \
      0,                                                   /* Event */  \
      Core1_OsTask_Appl_20ms                               /* Task */  \
    },  \
    {  \
      100,                                                 /* Offset */  \
      0,                                                   /* Max advance */  \
      0,                                                   /* Max retard */  \
      Rte_OSTimingEvent_Core1_OsTask_Bsw_20ms_TE_B040B4ED3027D1A3758BCA982B69EF51,  /* Events */  \
      Core1_OsTask_Bsw_20ms                                /* Task */  \
    },  \
    {  \
      100,                                                 /* Offset */  \
      0,                                                   /* Max advance */  \
      0,                                                   /* Max retard */  \
      Rte_OSTimingEvent_Core1_OsTask_Appl_10ms_TE_82A7CF7B79788AAC9ACECC46B60FBA35 | Rte_OSTimingEvent_Core1_OsTask_Appl_10ms_TE_B7D8AAA4EAF6595FD3CAC5E9F209B7C4,  /* Events */  \
      Core1_OsTask_Appl_10ms                               /* Task */  \
    },  \
    /* EP_120000 */  \
    {  \
      120,                                                 /* Offset */  \
      0,                                                   /* Max advance */  \
      0,                                                   /* Max retard */  \
      0,                                                   /* Event */  \
      Core1_OsTask_Appl_60ms                               /* Task */  \
    },  \
    {  \
      120,                                                 /* Offset */  \
      0,                                                   /* Max advance */  \
      0,                                                   /* Max retard */  \
      0,                                                   /* Event */  \
      Core1_OsTask_Appl_20ms                               /* Task */  \
    },  \
    {  \
      120,                                                 /* Offset */  \
      0,                                                   /* Max advance */  \
      0,                                                   /* Max retard */  \
      Rte_OSTimingEvent_Core1_OsTask_Bsw_20ms_TE_B040B4ED3027D1A3758BCA982B69EF51,  /* Events */  \
      Core1_OsTask_Bsw_20ms                                /* Task */  \
    },  \
    {  \
      120,                                                 /* Offset */  \
      0,                                                   /* Max advance */  \
      0,                                                   /* Max retard */  \
      Rte_OSTimingEvent_Core1_OsTask_Appl_10ms_TE_82A7CF7B79788AAC9ACECC46B60FBA35,  /* Events */  \
      Core1_OsTask_Appl_10ms                               /* Task */  \
    },  \
    /* EP_140000 */  \
    {  \
      140,                                                 /* Offset */  \
      0,                                                   /* Max advance */  \
      0,                                                   /* Max retard */  \
      0,                                                   /* Event */  \
      Core1_OsTask_Appl_20ms                               /* Task */  \
    },  \
    {  \
      140,                                                 /* Offset */  \
      0,                                                   /* Max advance */  \
      0,                                                   /* Max retard */  \
      Rte_OSTimingEvent_Core1_OsTask_Bsw_20ms_TE_B040B4ED3027D1A3758BCA982B69EF51,  /* Events */  \
      Core1_OsTask_Bsw_20ms                                /* Task */  \
    },  \
    {  \
      140,                                                 /* Offset */  \
      0,                                                   /* Max advance */  \
      0,                                                   /* Max retard */  \
      Rte_OSTimingEvent_Core1_OsTask_Appl_10ms_TE_82A7CF7B79788AAC9ACECC46B60FBA35,  /* Events */  \
      Core1_OsTask_Appl_10ms                               /* Task */  \
    },  \
    /* EP_150000 */  \
    {  \
      150,                                                 /* Offset */  \
      0,                                                   /* Max advance */  \
      0,                                                   /* Max retard */  \
      Rte_OSTimingEvent_Core1_OsTask_Appl_10ms_TE_B7D8AAA4EAF6595FD3CAC5E9F209B7C4,  /* Events */  \
      Core1_OsTask_Appl_10ms                               /* Task */  \
    },  \
    /* EP_160000 */  \
    {  \
      160,                                                 /* Offset */  \
      0,                                                   /* Max advance */  \
      0,                                                   /* Max retard */  \
      0,                                                   /* Event */  \
      Core1_OsTask_Appl_20ms                               /* Task */  \
    },  \
    {  \
      160,                                                 /* Offset */  \
      0,                                                   /* Max advance */  \
      0,                                                   /* Max retard */  \
      Rte_OSTimingEvent_Core1_OsTask_Bsw_20ms_TE_B040B4ED3027D1A3758BCA982B69EF51,  /* Events */  \
      Core1_OsTask_Bsw_20ms                                /* Task */  \
    },  \
    {  \
      160,                                                 /* Offset */  \
      0,                                                   /* Max advance */  \
      0,                                                   /* Max retard */  \
      Rte_OSTimingEvent_Core1_OsTask_Appl_10ms_TE_82A7CF7B79788AAC9ACECC46B60FBA35,  /* Events */  \
      Core1_OsTask_Appl_10ms                               /* Task */  \
    },  \
    /* EP_180000 */  \
    {  \
      180,                                                 /* Offset */  \
      0,                                                   /* Max advance */  \
      0,                                                   /* Max retard */  \
      0,                                                   /* Event */  \
      Core1_OsTask_Appl_60ms                               /* Task */  \
    },  \
    {  \
      180,                                                 /* Offset */  \
      0,                                                   /* Max advance */  \
      0,                                                   /* Max retard */  \
      0,                                                   /* Event */  \
      Core1_OsTask_Appl_20ms                               /* Task */  \
    },  \
    {  \
      180,                                                 /* Offset */  \
      0,                                                   /* Max advance */  \
      0,                                                   /* Max retard */  \
      Rte_OSTimingEvent_Core1_OsTask_Bsw_20ms_TE_B040B4ED3027D1A3758BCA982B69EF51,  /* Events */  \
      Core1_OsTask_Bsw_20ms                                /* Task */  \
    },  \
    {  \
      180,                                                 /* Offset */  \
      0,                                                   /* Max advance */  \
      0,                                                   /* Max retard */  \
      Rte_OSTimingEvent_Core1_OsTask_Appl_10ms_TE_82A7CF7B79788AAC9ACECC46B60FBA35,  /* Events */  \
      Core1_OsTask_Appl_10ms                               /* Task */  \
    },  \
    /* EP_200000 */  \
    {  \
      200,                                                 /* Offset */  \
      0,                                                   /* Max advance */  \
      0,                                                   /* Max retard */  \
      0,                                                   /* Event */  \
      Core1_OsTask_Appl_20ms                               /* Task */  \
    },  \
    {  \
      200,                                                 /* Offset */  \
      0,                                                   /* Max advance */  \
      0,                                                   /* Max retard */  \
      Rte_OSTimingEvent_Core1_OsTask_Bsw_20ms_TE_B040B4ED3027D1A3758BCA982B69EF51,  /* Events */  \
      Core1_OsTask_Bsw_20ms                                /* Task */  \
    },  \
    {  \
      200,                                                 /* Offset */  \
      0,                                                   /* Max advance */  \
      0,                                                   /* Max retard */  \
      Rte_OSTimingEvent_Core1_OsTask_Appl_10ms_TE_82A7CF7B79788AAC9ACECC46B60FBA35 | Rte_OSTimingEvent_Core1_OsTask_Appl_10ms_TE_B7D8AAA4EAF6595FD3CAC5E9F209B7C4,  /* Events */  \
      Core1_OsTask_Appl_10ms                               /* Task */  \
    },  \
    /* EP_220000 */  \
    {  \
      220,                                                 /* Offset */  \
      0,                                                   /* Max advance */  \
      0,                                                   /* Max retard */  \
      0,                                                   /* Event */  \
      Core1_OsTask_Appl_20ms                               /* Task */  \
    },  \
    {  \
      220,                                                 /* Offset */  \
      0,                                                   /* Max advance */  \
      0,                                                   /* Max retard */  \
      Rte_OSTimingEvent_Core1_OsTask_Bsw_20ms_TE_B040B4ED3027D1A3758BCA982B69EF51,  /* Events */  \
      Core1_OsTask_Bsw_20ms                                /* Task */  \
    },  \
    {  \
      220,                                                 /* Offset */  \
      0,                                                   /* Max advance */  \
      0,                                                   /* Max retard */  \
      Rte_OSTimingEvent_Core1_OsTask_Appl_10ms_TE_82A7CF7B79788AAC9ACECC46B60FBA35,  /* Events */  \
      Core1_OsTask_Appl_10ms                               /* Task */  \
    },  \
    /* EP_240000 */  \
    {  \
      240,                                                 /* Offset */  \
      0,                                                   /* Max advance */  \
      0,                                                   /* Max retard */  \
      0,                                                   /* Event */  \
      Core1_OsTask_Appl_60ms                               /* Task */  \
    },  \
    {  \
      240,                                                 /* Offset */  \
      0,                                                   /* Max advance */  \
      0,                                                   /* Max retard */  \
      0,                                                   /* Event */  \
      Core1_OsTask_Appl_20ms                               /* Task */  \
    },  \
    {  \
      240,                                                 /* Offset */  \
      0,                                                   /* Max advance */  \
      0,                                                   /* Max retard */  \
      Rte_OSTimingEvent_Core1_OsTask_Bsw_20ms_TE_B040B4ED3027D1A3758BCA982B69EF51,  /* Events */  \
      Core1_OsTask_Bsw_20ms                                /* Task */  \
    },  \
    {  \
      240,                                                 /* Offset */  \
      0,                                                   /* Max advance */  \
      0,                                                   /* Max retard */  \
      Rte_OSTimingEvent_Core1_OsTask_Appl_10ms_TE_82A7CF7B79788AAC9ACECC46B60FBA35,  /* Events */  \
      Core1_OsTask_Appl_10ms                               /* Task */  \
    },  \
    /* EP_250000 */  \
    {  \
      250,                                                 /* Offset */  \
      0,                                                   /* Max advance */  \
      0,                                                   /* Max retard */  \
      Rte_OSTimingEvent_Core1_OsTask_Appl_10ms_TE_B7D8AAA4EAF6595FD3CAC5E9F209B7C4,  /* Events */  \
      Core1_OsTask_Appl_10ms                               /* Task */  \
    },  \
    /* EP_260000 */  \
    {  \
      260,                                                 /* Offset */  \
      0,                                                   /* Max advance */  \
      0,                                                   /* Max retard */  \
      0,                                                   /* Event */  \
      Core1_OsTask_Appl_20ms                               /* Task */  \
    },  \
    {  \
      260,                                                 /* Offset */  \
      0,                                                   /* Max advance */  \
      0,                                                   /* Max retard */  \
      Rte_OSTimingEvent_Core1_OsTask_Bsw_20ms_TE_B040B4ED3027D1A3758BCA982B69EF51,  /* Events */  \
      Core1_OsTask_Bsw_20ms                                /* Task */  \
    },  \
    {  \
      260,                                                 /* Offset */  \
      0,                                                   /* Max advance */  \
      0,                                                   /* Max retard */  \
      Rte_OSTimingEvent_Core1_OsTask_Appl_10ms_TE_82A7CF7B79788AAC9ACECC46B60FBA35,  /* Events */  \
      Core1_OsTask_Appl_10ms                               /* Task */  \
    },  \
    /* EP_280000 */  \
    {  \
      280,                                                 /* Offset */  \
      0,                                                   /* Max advance */  \
      0,                                                   /* Max retard */  \
      0,                                                   /* Event */  \
      Core1_OsTask_Appl_20ms                               /* Task */  \
    },  \
    {  \
      280,                                                 /* Offset */  \
      0,                                                   /* Max advance */  \
      0,                                                   /* Max retard */  \
      Rte_OSTimingEvent_Core1_OsTask_Bsw_20ms_TE_B040B4ED3027D1A3758BCA982B69EF51,  /* Events */  \
      Core1_OsTask_Bsw_20ms                                /* Task */  \
    },  \
    {  \
      280,                                                 /* Offset */  \
      0,                                                   /* Max advance */  \
      0,                                                   /* Max retard */  \
      Rte_OSTimingEvent_Core1_OsTask_Appl_10ms_TE_82A7CF7B79788AAC9ACECC46B60FBA35,  /* Events */  \
      Core1_OsTask_Appl_10ms                               /* Task */  \
    },  \
    /* EP_0 */  \
    {  \
      0,                                                   /* Offset */  \
      0,                                                   /* Max advance */  \
      0,                                                   /* Max retard */  \
      Rte_OSTimingEvent_Core2_OsTask_Bsw_20ms_TE_29BB7D421FDFD8A63D5E80341CE8612E | Rte_OSTimingEvent_Core2_OsTask_Bsw_20ms_TE_D3A2F42BF7C6C717EC3CCFC9FD15E731,  /* Events */  \
      Core2_OsTask_Bsw_20ms                                /* Task */  \
    },  \
    /* EP_10000 */  \
    {  \
      10,                                                  /* Offset */  \
      0,                                                   /* Max advance */  \
      0,                                                   /* Max retard */  \
      Rte_OSTimingEvent_Core2_OsTask_Bsw_20ms_TE_D3A2F42BF7C6C717EC3CCFC9FD15E731,  /* Events */  \
      Core2_OsTask_Bsw_20ms                                /* Task */  \
    },  \
    /* EP_0 */  \
    {  \
      0,                                                   /* Offset */  \
      0,                                                   /* Max advance */  \
      0,                                                   /* Max retard */  \
      Rte_OSTimingEvent_Core2_OsTask_Appl_5ms_TE_89C5AF3EF7B20A2642A74C905331C459 | Rte_OSTimingEvent_Core2_OsTask_Appl_5ms_TE_2760829764E12F022E818C5F06DFF5F3,  /* Events */  \
      Core2_OsTask_Appl_5ms                                /* Task */  \
    },  \
    /* EP_20000 */  \
    {  \
      20,                                                  /* Offset */  \
      0,                                                   /* Max advance */  \
      0,                                                   /* Max retard */  \
      Rte_OSTimingEvent_Core2_OsTask_Appl_5ms_TE_89C5AF3EF7B20A2642A74C905331C459,  /* Events */  \
      Core2_OsTask_Appl_5ms                                /* Task */  \
    },  \
    /* EP_40000 */  \
    {  \
      40,                                                  /* Offset */  \
      0,                                                   /* Max advance */  \
      0,                                                   /* Max retard */  \
      Rte_OSTimingEvent_Core2_OsTask_Appl_5ms_TE_89C5AF3EF7B20A2642A74C905331C459,  /* Events */  \
      Core2_OsTask_Appl_5ms                                /* Task */  \
    },  \
    /* EP_50000 */  \
    {  \
      50,                                                  /* Offset */  \
      0,                                                   /* Max advance */  \
      0,                                                   /* Max retard */  \
      Rte_OSTimingEvent_Core2_OsTask_Appl_5ms_TE_2760829764E12F022E818C5F06DFF5F3,  /* Events */  \
      Core2_OsTask_Appl_5ms                                /* Task */  \
    },  \
    /* EP_60000 */  \
    {  \
      60,                                                  /* Offset */  \
      0,                                                   /* Max advance */  \
      0,                                                   /* Max retard */  \
      Rte_OSTimingEvent_Core2_OsTask_Appl_5ms_TE_89C5AF3EF7B20A2642A74C905331C459,  /* Events */  \
      Core2_OsTask_Appl_5ms                                /* Task */  \
    },  \
    /* EP_80000 */  \
    {  \
      80,                                                  /* Offset */  \
      0,                                                   /* Max advance */  \
      0,                                                   /* Max retard */  \
      Rte_OSTimingEvent_Core2_OsTask_Appl_5ms_TE_89C5AF3EF7B20A2642A74C905331C459,  /* Events */  \
      Core2_OsTask_Appl_5ms                                /* Task */  \
    },  \
    /* EP_0 */  \
    {  \
      0,                                                   /* Offset */  \
      0,                                                   /* Max advance */  \
      0,                                                   /* Max retard */  \
      Rte_OSTimingEvent_Core3_OsTask_Bsw_20ms_TE_657DAD7D229C5C6ECB7466187F0A914C | Rte_OSTimingEvent_Core3_OsTask_Bsw_20ms_TE_D9D2DDEE891EEE02E4F9199A02316334,  /* Events */  \
      Core3_OsTask_Bsw_20ms                                /* Task */  \
    },  \
    /* EP_10000 */  \
    {  \
      10,                                                  /* Offset */  \
      0,                                                   /* Max advance */  \
      0,                                                   /* Max retard */  \
      Rte_OSTimingEvent_Core3_OsTask_Bsw_20ms_TE_D9D2DDEE891EEE02E4F9199A02316334,  /* Events */  \
      Core3_OsTask_Bsw_20ms                                /* Task */  \
    },  \
    /* EP_0 */  \
    {  \
      0,                                                   /* Offset */  \
      0,                                                   /* Max advance */  \
      0,                                                   /* Max retard */  \
      0,                                                   /* Event */  \
      Core3_OsTask_Appl_50ms                               /* Task */  \
    },  \
    {  \
      0,                                                   /* Offset */  \
      0,                                                   /* Max advance */  \
      0,                                                   /* Max retard */  \
      0,                                                   /* Event */  \
      Core3_OsTask_Appl_10ms                               /* Task */  \
    },  \
    {  \
      0,                                                   /* Offset */  \
      0,                                                   /* Max advance */  \
      0,                                                   /* Max retard */  \
      0,                                                   /* Event */  \
      Core3_OsTask_Appl_60ms                               /* Task */  \
    },  \
    {  \
      0,                                                   /* Offset */  \
      0,                                                   /* Max advance */  \
      0,                                                   /* Max retard */  \
      Rte_OSTimingEvent_Core3_OsTask_Bsw_20ms_TE_60BBEC5D20DC45D3A7EA0EB66F240BAD,  /* Events */  \
      Core3_OsTask_Bsw_20ms                                /* Task */  \
    },  \
    /* EP_10000 */  \
    {  \
      10,                                                  /* Offset */  \
      0,                                                   /* Max advance */  \
      0,                                                   /* Max retard */  \
      0,                                                   /* Event */  \
      Core3_OsTask_Appl_10ms                               /* Task */  \
    },  \
    {  \
      10,                                                  /* Offset */  \
      0,                                                   /* Max advance */  \
      0,                                                   /* Max retard */  \
      0,                                                   /* Event */  \
      Core3_OsTask_Appl_60ms                               /* Task */  \
    },  \
    /* EP_20000 */  \
    {  \
      20,                                                  /* Offset */  \
      0,                                                   /* Max advance */  \
      0,                                                   /* Max retard */  \
      0,                                                   /* Event */  \
      Core3_OsTask_Appl_10ms                               /* Task */  \
    },  \
    {  \
      20,                                                  /* Offset */  \
      0,                                                   /* Max advance */  \
      0,                                                   /* Max retard */  \
      0,                                                   /* Event */  \
      Core3_OsTask_Appl_60ms                               /* Task */  \
    },  \
    {  \
      20,                                                  /* Offset */  \
      0,                                                   /* Max advance */  \
      0,                                                   /* Max retard */  \
      Rte_OSTimingEvent_Core3_OsTask_Bsw_20ms_TE_60BBEC5D20DC45D3A7EA0EB66F240BAD,  /* Events */  \
      Core3_OsTask_Bsw_20ms                                /* Task */  \
    },  \
    /* EP_30000 */  \
    {  \
      30,                                                  /* Offset */  \
      0,                                                   /* Max advance */  \
      0,                                                   /* Max retard */  \
      0,                                                   /* Event */  \
      Core3_OsTask_Appl_10ms                               /* Task */  \
    },  \
    {  \
      30,                                                  /* Offset */  \
      0,                                                   /* Max advance */  \
      0,                                                   /* Max retard */  \
      0,                                                   /* Event */  \
      Core3_OsTask_Appl_60ms                               /* Task */  \
    },  \
    /* EP_40000 */  \
    {  \
      40,                                                  /* Offset */  \
      0,                                                   /* Max advance */  \
      0,                                                   /* Max retard */  \
      0,                                                   /* Event */  \
      Core3_OsTask_Appl_10ms                               /* Task */  \
    },  \
    {  \
      40,                                                  /* Offset */  \
      0,                                                   /* Max advance */  \
      0,                                                   /* Max retard */  \
      0,                                                   /* Event */  \
      Core3_OsTask_Appl_60ms                               /* Task */  \
    },  \
    {  \
      40,                                                  /* Offset */  \
      0,                                                   /* Max advance */  \
      0,                                                   /* Max retard */  \
      Rte_OSTimingEvent_Core3_OsTask_Bsw_20ms_TE_60BBEC5D20DC45D3A7EA0EB66F240BAD,  /* Events */  \
      Core3_OsTask_Bsw_20ms                                /* Task */  \
    },  \
    /* EP_50000 */  \
    {  \
      50,                                                  /* Offset */  \
      0,                                                   /* Max advance */  \
      0,                                                   /* Max retard */  \
      0,                                                   /* Event */  \
      Core3_OsTask_Appl_10ms                               /* Task */  \
    },  \
    {  \
      50,                                                  /* Offset */  \
      0,                                                   /* Max advance */  \
      0,                                                   /* Max retard */  \
      0,                                                   /* Event */  \
      Core3_OsTask_Appl_60ms                               /* Task */  \
    }
#define OS_NSCHEDULES_CORE0 2
#define OS_NSCHEDULES_CORE1 2
#define OS_NSCHEDULES_CORE2 2
#define OS_NSCHEDULES_CORE3 2

/*===================================================================
 * Spinlocks
 *==================================================================*/

#define OS_NAUTOSARSPINLOCKS 24
#define OS_AUTOSARSPINLOCKCONFIG {    /* OsSpinlock_SpiBuffer */  \
  &OS_autosarSpinlockDynamic[OsSpinlock_SpiBuffer],    /* Dynamic spinlock structure */  \
  OS_NULLSPINLOCK,                                     /* Successor spinlock */  \
  0xf,                                                 /* Accessing Applications */  \
  OsSpinlock_SpiBuffer,                                /* Spinlock ID */  \
  OS_SPINLOCKLM_LOCK_NOTHING                           /* Lock method */  \
},  \
{    /* OsSpinlock_EventMsgPool */  \
  &OS_autosarSpinlockDynamic[OsSpinlock_EventMsgPool],  /* Dynamic spinlock structure */  \
  OS_NULLSPINLOCK,                                     /* Successor spinlock */  \
  0xf,                                                 /* Accessing Applications */  \
  OsSpinlock_EventMsgPool,                             /* Spinlock ID */  \
  OS_SPINLOCKLM_LOCK_ALL_INTERRUPTS                    /* Lock method */  \
},  \
{    /* Rte_Spinlock_0 */  \
  &OS_autosarSpinlockDynamic[Rte_Spinlock_0],          /* Dynamic spinlock structure */  \
  OS_NULLSPINLOCK,                                     /* Successor spinlock */  \
  0xe,                                                 /* Accessing Applications */  \
  Rte_Spinlock_0,                                      /* Spinlock ID */  \
  OS_SPINLOCKLM_LOCK_NOTHING                           /* Lock method */  \
},  \
{    /* Rte_Spinlock_1 */  \
  &OS_autosarSpinlockDynamic[Rte_Spinlock_1],          /* Dynamic spinlock structure */  \
  OS_NULLSPINLOCK,                                     /* Successor spinlock */  \
  0x3,                                                 /* Accessing Applications */  \
  Rte_Spinlock_1,                                      /* Spinlock ID */  \
  OS_SPINLOCKLM_LOCK_NOTHING                           /* Lock method */  \
},  \
{    /* Rte_Spinlock_2 */  \
  &OS_autosarSpinlockDynamic[Rte_Spinlock_2],          /* Dynamic spinlock structure */  \
  OS_NULLSPINLOCK,                                     /* Successor spinlock */  \
  0x9,                                                 /* Accessing Applications */  \
  Rte_Spinlock_2,                                      /* Spinlock ID */  \
  OS_SPINLOCKLM_LOCK_NOTHING                           /* Lock method */  \
},  \
{    /* Rte_Spinlock_3 */  \
  &OS_autosarSpinlockDynamic[Rte_Spinlock_3],          /* Dynamic spinlock structure */  \
  OS_NULLSPINLOCK,                                     /* Successor spinlock */  \
  0x9,                                                 /* Accessing Applications */  \
  Rte_Spinlock_3,                                      /* Spinlock ID */  \
  OS_SPINLOCKLM_LOCK_NOTHING                           /* Lock method */  \
},  \
{    /* Rte_Spinlock_4 */  \
  &OS_autosarSpinlockDynamic[Rte_Spinlock_4],          /* Dynamic spinlock structure */  \
  OS_NULLSPINLOCK,                                     /* Successor spinlock */  \
  0xf,                                                 /* Accessing Applications */  \
  Rte_Spinlock_4,                                      /* Spinlock ID */  \
  OS_SPINLOCKLM_LOCK_NOTHING                           /* Lock method */  \
},  \
{    /* Rte_Spinlock_5 */  \
  &OS_autosarSpinlockDynamic[Rte_Spinlock_5],          /* Dynamic spinlock structure */  \
  OS_NULLSPINLOCK,                                     /* Successor spinlock */  \
  0x3,                                                 /* Accessing Applications */  \
  Rte_Spinlock_5,                                      /* Spinlock ID */  \
  OS_SPINLOCKLM_LOCK_NOTHING                           /* Lock method */  \
},  \
{    /* Rte_Spinlock_6 */  \
  &OS_autosarSpinlockDynamic[Rte_Spinlock_6],          /* Dynamic spinlock structure */  \
  OS_NULLSPINLOCK,                                     /* Successor spinlock */  \
  0x3,                                                 /* Accessing Applications */  \
  Rte_Spinlock_6,                                      /* Spinlock ID */  \
  OS_SPINLOCKLM_LOCK_NOTHING                           /* Lock method */  \
},  \
{    /* Rte_Spinlock_7 */  \
  &OS_autosarSpinlockDynamic[Rte_Spinlock_7],          /* Dynamic spinlock structure */  \
  OS_NULLSPINLOCK,                                     /* Successor spinlock */  \
  0x3,                                                 /* Accessing Applications */  \
  Rte_Spinlock_7,                                      /* Spinlock ID */  \
  OS_SPINLOCKLM_LOCK_NOTHING                           /* Lock method */  \
},  \
{    /* Rte_Spinlock_8 */  \
  &OS_autosarSpinlockDynamic[Rte_Spinlock_8],          /* Dynamic spinlock structure */  \
  OS_NULLSPINLOCK,                                     /* Successor spinlock */  \
  0x3,                                                 /* Accessing Applications */  \
  Rte_Spinlock_8,                                      /* Spinlock ID */  \
  OS_SPINLOCKLM_LOCK_NOTHING                           /* Lock method */  \
},  \
{    /* Rte_Spinlock_9 */  \
  &OS_autosarSpinlockDynamic[Rte_Spinlock_9],          /* Dynamic spinlock structure */  \
  OS_NULLSPINLOCK,                                     /* Successor spinlock */  \
  0x3,                                                 /* Accessing Applications */  \
  Rte_Spinlock_9,                                      /* Spinlock ID */  \
  OS_SPINLOCKLM_LOCK_NOTHING                           /* Lock method */  \
},  \
{    /* Rte_Spinlock_10 */  \
  &OS_autosarSpinlockDynamic[Rte_Spinlock_10],         /* Dynamic spinlock structure */  \
  OS_NULLSPINLOCK,                                     /* Successor spinlock */  \
  0xb,                                                 /* Accessing Applications */  \
  Rte_Spinlock_10,                                     /* Spinlock ID */  \
  OS_SPINLOCKLM_LOCK_NOTHING                           /* Lock method */  \
},  \
{    /* Rte_Spinlock_11 */  \
  &OS_autosarSpinlockDynamic[Rte_Spinlock_11],         /* Dynamic spinlock structure */  \
  OS_NULLSPINLOCK,                                     /* Successor spinlock */  \
  0xb,                                                 /* Accessing Applications */  \
  Rte_Spinlock_11,                                     /* Spinlock ID */  \
  OS_SPINLOCKLM_LOCK_NOTHING                           /* Lock method */  \
},  \
{    /* Rte_Spinlock_12 */  \
  &OS_autosarSpinlockDynamic[Rte_Spinlock_12],         /* Dynamic spinlock structure */  \
  OS_NULLSPINLOCK,                                     /* Successor spinlock */  \
  0x3,                                                 /* Accessing Applications */  \
  Rte_Spinlock_12,                                     /* Spinlock ID */  \
  OS_SPINLOCKLM_LOCK_NOTHING                           /* Lock method */  \
},  \
{    /* Rte_Spinlock_13 */  \
  &OS_autosarSpinlockDynamic[Rte_Spinlock_13],         /* Dynamic spinlock structure */  \
  OS_NULLSPINLOCK,                                     /* Successor spinlock */  \
  0x3,                                                 /* Accessing Applications */  \
  Rte_Spinlock_13,                                     /* Spinlock ID */  \
  OS_SPINLOCKLM_LOCK_NOTHING                           /* Lock method */  \
},  \
{    /* Rte_Spinlock_14 */  \
  &OS_autosarSpinlockDynamic[Rte_Spinlock_14],         /* Dynamic spinlock structure */  \
  OS_NULLSPINLOCK,                                     /* Successor spinlock */  \
  0xb,                                                 /* Accessing Applications */  \
  Rte_Spinlock_14,                                     /* Spinlock ID */  \
  OS_SPINLOCKLM_LOCK_NOTHING                           /* Lock method */  \
},  \
{    /* Rte_Spinlock_15 */  \
  &OS_autosarSpinlockDynamic[Rte_Spinlock_15],         /* Dynamic spinlock structure */  \
  OS_NULLSPINLOCK,                                     /* Successor spinlock */  \
  0xb,                                                 /* Accessing Applications */  \
  Rte_Spinlock_15,                                     /* Spinlock ID */  \
  OS_SPINLOCKLM_LOCK_NOTHING                           /* Lock method */  \
},  \
{    /* Rte_Spinlock_16 */  \
  &OS_autosarSpinlockDynamic[Rte_Spinlock_16],         /* Dynamic spinlock structure */  \
  OS_NULLSPINLOCK,                                     /* Successor spinlock */  \
  0x9,                                                 /* Accessing Applications */  \
  Rte_Spinlock_16,                                     /* Spinlock ID */  \
  OS_SPINLOCKLM_LOCK_NOTHING                           /* Lock method */  \
},  \
{    /* Rte_Spinlock_17 */  \
  &OS_autosarSpinlockDynamic[Rte_Spinlock_17],         /* Dynamic spinlock structure */  \
  OS_NULLSPINLOCK,                                     /* Successor spinlock */  \
  0x9,                                                 /* Accessing Applications */  \
  Rte_Spinlock_17,                                     /* Spinlock ID */  \
  OS_SPINLOCKLM_LOCK_NOTHING                           /* Lock method */  \
},  \
{    /* Rte_Spinlock_18 */  \
  &OS_autosarSpinlockDynamic[Rte_Spinlock_18],         /* Dynamic spinlock structure */  \
  OS_NULLSPINLOCK,                                     /* Successor spinlock */  \
  0x9,                                                 /* Accessing Applications */  \
  Rte_Spinlock_18,                                     /* Spinlock ID */  \
  OS_SPINLOCKLM_LOCK_NOTHING                           /* Lock method */  \
},  \
{    /* Rte_Spinlock_19 */  \
  &OS_autosarSpinlockDynamic[Rte_Spinlock_19],         /* Dynamic spinlock structure */  \
  OS_NULLSPINLOCK,                                     /* Successor spinlock */  \
  0x9,                                                 /* Accessing Applications */  \
  Rte_Spinlock_19,                                     /* Spinlock ID */  \
  OS_SPINLOCKLM_LOCK_NOTHING                           /* Lock method */  \
},  \
{    /* Rte_Spinlock_20 */  \
  &OS_autosarSpinlockDynamic[Rte_Spinlock_20],         /* Dynamic spinlock structure */  \
  OS_NULLSPINLOCK,                                     /* Successor spinlock */  \
  0xb,                                                 /* Accessing Applications */  \
  Rte_Spinlock_20,                                     /* Spinlock ID */  \
  OS_SPINLOCKLM_LOCK_NOTHING                           /* Lock method */  \
},  \
{    /* Rte_Spinlock_21 */  \
  &OS_autosarSpinlockDynamic[Rte_Spinlock_21],         /* Dynamic spinlock structure */  \
  OS_NULLSPINLOCK,                                     /* Successor spinlock */  \
  0xf,                                                 /* Accessing Applications */  \
  Rte_Spinlock_21,                                     /* Spinlock ID */  \
  OS_SPINLOCKLM_LOCK_NOTHING                           /* Lock method */  \
},

/*===================================================================
 * Stacks
 *==================================================================*/

#define OS_STACK_REGION_ALIGNMENT 8
#ifndef OS_ASM
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern OS_GEN_STACK_DECL(OS_taskStack0_slot0, .bss.core0.os_taskstack0_slot0, 1026, 8);
#endif
#endif  /* OS_ASM */
#ifndef OS_ASM
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern OS_GEN_STACK_DECL(OS_taskStack0_slot1, .bss.core0.os_taskstack0_slot1, 1026, 8);
#endif
#endif  /* OS_ASM */
#ifndef OS_ASM
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern OS_GEN_STACK_DECL(OS_taskStack0_slot2, .bss.core0.os_taskstack0_slot2, 258, 8);
#endif
#endif  /* OS_ASM */
#ifndef OS_ASM
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern OS_GEN_STACK_DECL(OS_taskStack0_slot3, .bss.core0.os_taskstack0_slot3, 258, 8);
#endif
#endif  /* OS_ASM */
#ifndef OS_ASM
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern OS_GEN_STACK_DECL(OS_taskStack0_slot4, .bss.core0.os_taskstack0_slot4, 258, 8);
#endif
#endif  /* OS_ASM */
#ifndef OS_ASM
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern OS_GEN_STACK_DECL(OS_taskStack0_slot5, .bss.core0.os_taskstack0_slot5, 130, 8);
#endif
#endif  /* OS_ASM */
#ifndef OS_ASM
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern OS_GEN_STACK_DECL(OS_taskStack0_slot6, .bss.core0.os_taskstack0_slot6, 130, 8);
#endif
#endif  /* OS_ASM */
#ifndef OS_ASM
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern OS_GEN_STACK_DECL(OS_taskStack0_slot7, .bss.core0.os_taskstack0_slot7, 130, 8);
#endif
#endif  /* OS_ASM */
#ifndef OS_ASM
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern OS_GEN_STACK_DECL(OS_taskStack0_slot8, .bss.core0.os_taskstack0_slot8, 130, 8);
#endif
#endif  /* OS_ASM */
#ifndef OS_ASM
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern OS_GEN_STACK_DECL(OS_taskStack0_slot9, .bss.core0.os_taskstack0_slot9, 130, 8);
#endif
#endif  /* OS_ASM */
#ifndef OS_ASM
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern OS_GEN_STACK_DECL(OS_taskStack0_slot10, .bss.core0.os_taskstack0_slot10, 130, 8);
#endif
#endif  /* OS_ASM */
#ifndef OS_ASM
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern OS_GEN_STACK_DECL(OS_taskStack1_slot0, .bss.core1.os_taskstack1_slot0, 1282, 8);
#endif
#endif  /* OS_ASM */
#ifndef OS_ASM
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern OS_GEN_STACK_DECL(OS_taskStack1_slot1, .bss.core1.os_taskstack1_slot1, 1282, 8);
#endif
#endif  /* OS_ASM */
#ifndef OS_ASM
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern OS_GEN_STACK_DECL(OS_taskStack1_slot2, .bss.core1.os_taskstack1_slot2, 1282, 8);
#endif
#endif  /* OS_ASM */
#ifndef OS_ASM
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern OS_GEN_STACK_DECL(OS_taskStack1_slot3, .bss.core1.os_taskstack1_slot3, 130, 8);
#endif
#endif  /* OS_ASM */
#ifndef OS_ASM
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern OS_GEN_STACK_DECL(OS_taskStack1_slot4, .bss.core1.os_taskstack1_slot4, 130, 8);
#endif
#endif  /* OS_ASM */
#ifndef OS_ASM
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern OS_GEN_STACK_DECL(OS_taskStack1_slot5, .bss.core1.os_taskstack1_slot5, 130, 8);
#endif
#endif  /* OS_ASM */
#ifndef OS_ASM
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern OS_GEN_STACK_DECL(OS_taskStack1_slot6, .bss.core1.os_taskstack1_slot6, 130, 8);
#endif
#endif  /* OS_ASM */
#ifndef OS_ASM
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern OS_GEN_STACK_DECL(OS_taskStack2_slot0, .bss.core2.os_taskstack2_slot0, 258, 8);
#endif
#endif  /* OS_ASM */
#ifndef OS_ASM
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern OS_GEN_STACK_DECL(OS_taskStack2_slot1, .bss.core2.os_taskstack2_slot1, 130, 8);
#endif
#endif  /* OS_ASM */
#ifndef OS_ASM
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern OS_GEN_STACK_DECL(OS_taskStack2_slot2, .bss.core2.os_taskstack2_slot2, 130, 8);
#endif
#endif  /* OS_ASM */
#ifndef OS_ASM
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern OS_GEN_STACK_DECL(OS_taskStack2_slot3, .bss.core2.os_taskstack2_slot3, 130, 8);
#endif
#endif  /* OS_ASM */
#ifndef OS_ASM
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern OS_GEN_STACK_DECL(OS_taskStack2_slot4, .bss.core2.os_taskstack2_slot4, 130, 8);
#endif
#endif  /* OS_ASM */
#ifndef OS_ASM
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern OS_GEN_STACK_DECL(OS_taskStack3_slot0, .bss.core3.os_taskstack3_slot0, 1794, 8);
#endif
#endif  /* OS_ASM */
#ifndef OS_ASM
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern OS_GEN_STACK_DECL(OS_taskStack3_slot1, .bss.core3.os_taskstack3_slot1, 1794, 8);
#endif
#endif  /* OS_ASM */
#ifndef OS_ASM
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern OS_GEN_STACK_DECL(OS_taskStack3_slot2, .bss.core3.os_taskstack3_slot2, 130, 8);
#endif
#endif  /* OS_ASM */
#ifndef OS_ASM
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern OS_GEN_STACK_DECL(OS_taskStack3_slot3, .bss.core3.os_taskstack3_slot3, 130, 8);
#endif
#endif  /* OS_ASM */
#ifndef OS_ASM
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern OS_GEN_STACK_DECL(OS_taskStack3_slot4, .bss.core3.os_taskstack3_slot4, 130, 8);
#endif
#endif  /* OS_ASM */
#ifndef OS_ASM
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern OS_GEN_STACK_DECL(OS_taskStack3_slot5, .bss.core3.os_taskstack3_slot5, 130, 8);
#endif
#endif  /* OS_ASM */
#ifndef OS_ASM
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern OS_GEN_STACK_DECL(OS_taskStack3_slot6, .bss.core3.os_taskstack3_slot6, 130, 8);
#endif
#endif  /* OS_ASM */
#ifndef OS_ASM
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern OS_GEN_STACK_DECL(OS_kernStack0, .bss.core0.os_kernstack0, 7984, 8);
#endif
#endif  /* OS_ASM */
#ifndef OS_ASM
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern OS_GEN_STACK_DECL(OS_kernStack1, .bss.core1.os_kernstack1, 276, 8);
#endif
#endif  /* OS_ASM */
#ifndef OS_ASM
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern OS_GEN_STACK_DECL(OS_kernStack2, .bss.core2.os_kernstack2, 276, 8);
#endif
#endif  /* OS_ASM */
#ifndef OS_ASM
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern OS_GEN_STACK_DECL(OS_kernStack3, .bss.core3.os_kernstack3, 276, 8);
#endif
#endif  /* OS_ASM */

/*===================================================================
 * TRICORE CSAs
 *==================================================================*/

/* Deviation MISRAC2012-1 <START> */
#ifndef OS_ASM
extern os_cx_t OS_csaCore0_BEGIN;
#endif  /* OS_ASM */
#ifndef OS_ASM
extern os_uint8_t OS_csaCore0_NCSA;
#endif  /* OS_ASM */
/* Deviation MISRAC2012-1 <STOP> */
/* Deviation MISRAC2012-1 <START> */
#ifndef OS_ASM
extern os_cx_t OS_csaCore1_BEGIN;
#endif  /* OS_ASM */
#ifndef OS_ASM
extern os_uint8_t OS_csaCore1_NCSA;
#endif  /* OS_ASM */
/* Deviation MISRAC2012-1 <STOP> */
/* Deviation MISRAC2012-1 <START> */
#ifndef OS_ASM
extern os_cx_t OS_csaCore2_BEGIN;
#endif  /* OS_ASM */
#ifndef OS_ASM
extern os_uint8_t OS_csaCore2_NCSA;
#endif  /* OS_ASM */
/* Deviation MISRAC2012-1 <STOP> */
/* Deviation MISRAC2012-1 <START> */
#ifndef OS_ASM
extern os_cx_t OS_csaCore3_BEGIN;
#endif  /* OS_ASM */
#ifndef OS_ASM
extern os_uint8_t OS_csaCore3_NCSA;
#endif  /* OS_ASM */
/* Deviation MISRAC2012-1 <STOP> */
#define OS_CFG_INITCORECSAS     /* CSA initialization */  \
    {  \
      &OS_csaCore0_BEGIN,                                  /* begin */  \
      (os_uint32_t) &OS_csaCore0_NCSA                      /* size */  \
    },  \
    {  \
      &OS_csaCore1_BEGIN,                                  /* begin */  \
      (os_uint32_t) &OS_csaCore1_NCSA                      /* size */  \
    },  \
    {  \
      &OS_csaCore2_BEGIN,                                  /* begin */  \
      (os_uint32_t) &OS_csaCore2_NCSA                      /* size */  \
    },  \
    {  \
      &OS_csaCore3_BEGIN,                                  /* begin */  \
      (os_uint32_t) &OS_csaCore3_NCSA                      /* size */  \
    }
#define OS_TRICORE_XCORESRCS {  \
  &OS_SRC_GPSR20,                                      \
  &OS_SRC_GPSR21,                                      \
  &OS_SRC_GPSR22,                                      \
  &OS_SRC_GPSR37  \
}

/*===================================================================
 * Tasks
 *==================================================================*/

#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern os_uint8_t OS_TOOL_MR_START(Core0_OsTask_Bsw_5ms);
#endif
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern os_uint8_t OS_TOOL_MR_END(Core0_OsTask_Bsw_5ms);
#endif
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern os_uint8_t OS_TOOL_MR_LMA_START(Core0_OsTask_Bsw_5ms);
#endif
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern os_uint8_t OS_TOOL_MR_LMA_END(Core0_OsTask_Bsw_5ms);
#endif
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
DeclareTask(Core0_OsTask_Bsw_5ms);
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern os_uint8_t OS_TOOL_MR_START(Core0_OsTask_Appl_20ms);
#endif
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern os_uint8_t OS_TOOL_MR_END(Core0_OsTask_Appl_20ms);
#endif
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern os_uint8_t OS_TOOL_MR_LMA_START(Core0_OsTask_Appl_20ms);
#endif
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern os_uint8_t OS_TOOL_MR_LMA_END(Core0_OsTask_Appl_20ms);
#endif
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
DeclareTask(Core0_OsTask_Appl_20ms);
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern os_uint8_t OS_TOOL_MR_START(Core0_OsTask_Appl_60ms);
#endif
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern os_uint8_t OS_TOOL_MR_END(Core0_OsTask_Appl_60ms);
#endif
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern os_uint8_t OS_TOOL_MR_LMA_START(Core0_OsTask_Appl_60ms);
#endif
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern os_uint8_t OS_TOOL_MR_LMA_END(Core0_OsTask_Appl_60ms);
#endif
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
DeclareTask(Core0_OsTask_Appl_60ms);
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern os_uint8_t OS_TOOL_MR_START(Core0_OsTask_OperationInovkedProxy);
#endif
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern os_uint8_t OS_TOOL_MR_END(Core0_OsTask_OperationInovkedProxy);
#endif
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern os_uint8_t OS_TOOL_MR_LMA_START(Core0_OsTask_OperationInovkedProxy);
#endif
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern os_uint8_t OS_TOOL_MR_LMA_END(Core0_OsTask_OperationInovkedProxy);
#endif
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
DeclareTask(Core0_OsTask_OperationInovkedProxy);
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern os_uint8_t OS_TOOL_MR_START(Core1_OsTask_Bsw_20ms);
#endif
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern os_uint8_t OS_TOOL_MR_END(Core1_OsTask_Bsw_20ms);
#endif
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern os_uint8_t OS_TOOL_MR_LMA_START(Core1_OsTask_Bsw_20ms);
#endif
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern os_uint8_t OS_TOOL_MR_LMA_END(Core1_OsTask_Bsw_20ms);
#endif
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
DeclareTask(Core1_OsTask_Bsw_20ms);
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern os_uint8_t OS_TOOL_MR_START(Core1_OsTask_Appl_10ms);
#endif
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern os_uint8_t OS_TOOL_MR_END(Core1_OsTask_Appl_10ms);
#endif
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern os_uint8_t OS_TOOL_MR_LMA_START(Core1_OsTask_Appl_10ms);
#endif
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern os_uint8_t OS_TOOL_MR_LMA_END(Core1_OsTask_Appl_10ms);
#endif
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
DeclareTask(Core1_OsTask_Appl_10ms);
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern os_uint8_t OS_TOOL_MR_START(Core2_OsTask_Bsw_20ms);
#endif
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern os_uint8_t OS_TOOL_MR_END(Core2_OsTask_Bsw_20ms);
#endif
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern os_uint8_t OS_TOOL_MR_LMA_START(Core2_OsTask_Bsw_20ms);
#endif
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern os_uint8_t OS_TOOL_MR_LMA_END(Core2_OsTask_Bsw_20ms);
#endif
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
DeclareTask(Core2_OsTask_Bsw_20ms);
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern os_uint8_t OS_TOOL_MR_START(Core2_OsTask_Appl_5ms);
#endif
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern os_uint8_t OS_TOOL_MR_END(Core2_OsTask_Appl_5ms);
#endif
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern os_uint8_t OS_TOOL_MR_LMA_START(Core2_OsTask_Appl_5ms);
#endif
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern os_uint8_t OS_TOOL_MR_LMA_END(Core2_OsTask_Appl_5ms);
#endif
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
DeclareTask(Core2_OsTask_Appl_5ms);
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern os_uint8_t OS_TOOL_MR_START(Core3_OsTask_Bsw_20ms);
#endif
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern os_uint8_t OS_TOOL_MR_END(Core3_OsTask_Bsw_20ms);
#endif
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern os_uint8_t OS_TOOL_MR_LMA_START(Core3_OsTask_Bsw_20ms);
#endif
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern os_uint8_t OS_TOOL_MR_LMA_END(Core3_OsTask_Bsw_20ms);
#endif
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
DeclareTask(Core3_OsTask_Bsw_20ms);
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern os_uint8_t OS_TOOL_MR_START(Core3_OsTask_OperationInovkedProxy);
#endif
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern os_uint8_t OS_TOOL_MR_END(Core3_OsTask_OperationInovkedProxy);
#endif
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern os_uint8_t OS_TOOL_MR_LMA_START(Core3_OsTask_OperationInovkedProxy);
#endif
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern os_uint8_t OS_TOOL_MR_LMA_END(Core3_OsTask_OperationInovkedProxy);
#endif
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
DeclareTask(Core3_OsTask_OperationInovkedProxy);
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern os_uint8_t OS_TOOL_MR_START(Core0_DefaultTask);
#endif
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern os_uint8_t OS_TOOL_MR_END(Core0_DefaultTask);
#endif
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern os_uint8_t OS_TOOL_MR_LMA_START(Core0_DefaultTask);
#endif
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern os_uint8_t OS_TOOL_MR_LMA_END(Core0_DefaultTask);
#endif
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
DeclareTask(Core0_DefaultTask);
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern os_uint8_t OS_TOOL_MR_START(Core0_InitTask_Appl);
#endif
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern os_uint8_t OS_TOOL_MR_END(Core0_InitTask_Appl);
#endif
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern os_uint8_t OS_TOOL_MR_LMA_START(Core0_InitTask_Appl);
#endif
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern os_uint8_t OS_TOOL_MR_LMA_END(Core0_InitTask_Appl);
#endif
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
DeclareTask(Core0_InitTask_Appl);
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern os_uint8_t OS_TOOL_MR_START(Core0_OsTask_FunctionSafety_5ms);
#endif
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern os_uint8_t OS_TOOL_MR_END(Core0_OsTask_FunctionSafety_5ms);
#endif
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern os_uint8_t OS_TOOL_MR_LMA_START(Core0_OsTask_FunctionSafety_5ms);
#endif
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern os_uint8_t OS_TOOL_MR_LMA_END(Core0_OsTask_FunctionSafety_5ms);
#endif
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
DeclareTask(Core0_OsTask_FunctionSafety_5ms);
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern os_uint8_t OS_TOOL_MR_START(Core0_OsTask_Bsw_10ms);
#endif
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern os_uint8_t OS_TOOL_MR_END(Core0_OsTask_Bsw_10ms);
#endif
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern os_uint8_t OS_TOOL_MR_LMA_START(Core0_OsTask_Bsw_10ms);
#endif
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern os_uint8_t OS_TOOL_MR_LMA_END(Core0_OsTask_Bsw_10ms);
#endif
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
DeclareTask(Core0_OsTask_Bsw_10ms);
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern os_uint8_t OS_TOOL_MR_START(Core0_OsTask_Bsw_20ms);
#endif
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern os_uint8_t OS_TOOL_MR_END(Core0_OsTask_Bsw_20ms);
#endif
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern os_uint8_t OS_TOOL_MR_LMA_START(Core0_OsTask_Bsw_20ms);
#endif
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern os_uint8_t OS_TOOL_MR_LMA_END(Core0_OsTask_Bsw_20ms);
#endif
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
DeclareTask(Core0_OsTask_Bsw_20ms);
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern os_uint8_t OS_TOOL_MR_START(Core0_OsTask_Appl_5ms);
#endif
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern os_uint8_t OS_TOOL_MR_END(Core0_OsTask_Appl_5ms);
#endif
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern os_uint8_t OS_TOOL_MR_LMA_START(Core0_OsTask_Appl_5ms);
#endif
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern os_uint8_t OS_TOOL_MR_LMA_END(Core0_OsTask_Appl_5ms);
#endif
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
DeclareTask(Core0_OsTask_Appl_5ms);
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern os_uint8_t OS_TOOL_MR_START(Core0_OsTask_Appl_10ms);
#endif
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern os_uint8_t OS_TOOL_MR_END(Core0_OsTask_Appl_10ms);
#endif
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern os_uint8_t OS_TOOL_MR_LMA_START(Core0_OsTask_Appl_10ms);
#endif
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern os_uint8_t OS_TOOL_MR_LMA_END(Core0_OsTask_Appl_10ms);
#endif
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
DeclareTask(Core0_OsTask_Appl_10ms);
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern os_uint8_t OS_TOOL_MR_START(Core1_DefaultTask);
#endif
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern os_uint8_t OS_TOOL_MR_END(Core1_DefaultTask);
#endif
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern os_uint8_t OS_TOOL_MR_LMA_START(Core1_DefaultTask);
#endif
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern os_uint8_t OS_TOOL_MR_LMA_END(Core1_DefaultTask);
#endif
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
DeclareTask(Core1_DefaultTask);
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern os_uint8_t OS_TOOL_MR_START(Core1_InitTask_Appl);
#endif
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern os_uint8_t OS_TOOL_MR_END(Core1_InitTask_Appl);
#endif
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern os_uint8_t OS_TOOL_MR_LMA_START(Core1_InitTask_Appl);
#endif
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern os_uint8_t OS_TOOL_MR_LMA_END(Core1_InitTask_Appl);
#endif
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
DeclareTask(Core1_InitTask_Appl);
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern os_uint8_t OS_TOOL_MR_START(Core1_OsTask_Appl_20ms);
#endif
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern os_uint8_t OS_TOOL_MR_END(Core1_OsTask_Appl_20ms);
#endif
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern os_uint8_t OS_TOOL_MR_LMA_START(Core1_OsTask_Appl_20ms);
#endif
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern os_uint8_t OS_TOOL_MR_LMA_END(Core1_OsTask_Appl_20ms);
#endif
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
DeclareTask(Core1_OsTask_Appl_20ms);
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern os_uint8_t OS_TOOL_MR_START(Core1_OsTask_Appl_60ms);
#endif
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern os_uint8_t OS_TOOL_MR_END(Core1_OsTask_Appl_60ms);
#endif
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern os_uint8_t OS_TOOL_MR_LMA_START(Core1_OsTask_Appl_60ms);
#endif
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern os_uint8_t OS_TOOL_MR_LMA_END(Core1_OsTask_Appl_60ms);
#endif
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
DeclareTask(Core1_OsTask_Appl_60ms);
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern os_uint8_t OS_TOOL_MR_START(Core1_OsTask_OperationInovkedProxy);
#endif
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern os_uint8_t OS_TOOL_MR_END(Core1_OsTask_OperationInovkedProxy);
#endif
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern os_uint8_t OS_TOOL_MR_LMA_START(Core1_OsTask_OperationInovkedProxy);
#endif
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern os_uint8_t OS_TOOL_MR_LMA_END(Core1_OsTask_OperationInovkedProxy);
#endif
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
DeclareTask(Core1_OsTask_OperationInovkedProxy);
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern os_uint8_t OS_TOOL_MR_START(Core2_DefaultTask);
#endif
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern os_uint8_t OS_TOOL_MR_END(Core2_DefaultTask);
#endif
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern os_uint8_t OS_TOOL_MR_LMA_START(Core2_DefaultTask);
#endif
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern os_uint8_t OS_TOOL_MR_LMA_END(Core2_DefaultTask);
#endif
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
DeclareTask(Core2_DefaultTask);
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern os_uint8_t OS_TOOL_MR_START(Core2_InitTask_Appl);
#endif
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern os_uint8_t OS_TOOL_MR_END(Core2_InitTask_Appl);
#endif
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern os_uint8_t OS_TOOL_MR_LMA_START(Core2_InitTask_Appl);
#endif
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern os_uint8_t OS_TOOL_MR_LMA_END(Core2_InitTask_Appl);
#endif
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
DeclareTask(Core2_InitTask_Appl);
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern os_uint8_t OS_TOOL_MR_START(Core2_OsTask_OperationInovkedProxy);
#endif
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern os_uint8_t OS_TOOL_MR_END(Core2_OsTask_OperationInovkedProxy);
#endif
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern os_uint8_t OS_TOOL_MR_LMA_START(Core2_OsTask_OperationInovkedProxy);
#endif
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern os_uint8_t OS_TOOL_MR_LMA_END(Core2_OsTask_OperationInovkedProxy);
#endif
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
DeclareTask(Core2_OsTask_OperationInovkedProxy);
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern os_uint8_t OS_TOOL_MR_START(Core3_DefaultTask);
#endif
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern os_uint8_t OS_TOOL_MR_END(Core3_DefaultTask);
#endif
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern os_uint8_t OS_TOOL_MR_LMA_START(Core3_DefaultTask);
#endif
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern os_uint8_t OS_TOOL_MR_LMA_END(Core3_DefaultTask);
#endif
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
DeclareTask(Core3_DefaultTask);
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern os_uint8_t OS_TOOL_MR_START(Core3_InitTask_Appl);
#endif
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern os_uint8_t OS_TOOL_MR_END(Core3_InitTask_Appl);
#endif
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern os_uint8_t OS_TOOL_MR_LMA_START(Core3_InitTask_Appl);
#endif
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern os_uint8_t OS_TOOL_MR_LMA_END(Core3_InitTask_Appl);
#endif
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
DeclareTask(Core3_InitTask_Appl);
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern os_uint8_t OS_TOOL_MR_START(Core3_OsTask_Appl_10ms);
#endif
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern os_uint8_t OS_TOOL_MR_END(Core3_OsTask_Appl_10ms);
#endif
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern os_uint8_t OS_TOOL_MR_LMA_START(Core3_OsTask_Appl_10ms);
#endif
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern os_uint8_t OS_TOOL_MR_LMA_END(Core3_OsTask_Appl_10ms);
#endif
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
DeclareTask(Core3_OsTask_Appl_10ms);
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern os_uint8_t OS_TOOL_MR_START(Core3_OsTask_Appl_50ms);
#endif
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern os_uint8_t OS_TOOL_MR_END(Core3_OsTask_Appl_50ms);
#endif
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern os_uint8_t OS_TOOL_MR_LMA_START(Core3_OsTask_Appl_50ms);
#endif
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern os_uint8_t OS_TOOL_MR_LMA_END(Core3_OsTask_Appl_50ms);
#endif
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
DeclareTask(Core3_OsTask_Appl_50ms);
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern os_uint8_t OS_TOOL_MR_START(Core3_OsTask_Appl_60ms);
#endif
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern os_uint8_t OS_TOOL_MR_END(Core3_OsTask_Appl_60ms);
#endif
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern os_uint8_t OS_TOOL_MR_LMA_START(Core3_OsTask_Appl_60ms);
#endif
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern os_uint8_t OS_TOOL_MR_LMA_END(Core3_OsTask_Appl_60ms);
#endif
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
DeclareTask(Core3_OsTask_Appl_60ms);
#endif  /* OS_ASM */
#define OS_NTASKS 30
#define OS_NETASKS 10
#define OS_NTASKSEXECTIMELIMIT 0
#define OS_NTASKSINTLOCKLIMIT 0
#define OS_NTASKSRESLOCKLIMIT 0
#define OS_TASKCONFIG OS_TASKCONFIG_INIT(    /* Core0_OsTask_Bsw_5ms */  \
  &OS_taskDynamic_core0[0],                            /* Dynamic task structure */  \
  8U,                                                  /* Run priority */  \
  8U,                                                  /* Queuing priority */  \
  1,                                                   /* Activation index */  \
  &OS_TASK_Core0_OsTask_Bsw_5ms,                       /* Task entry */  \
  &OS_taskStack0_slot5[0],                             /* Stack base */  \
  520U,                                                /* Stack size */  \
  0U,                                                  /* Max. activations */  \
  (OS_TF_EXTENDED),                                    /* Flags */  \
  Core0_OsTask_Bsw_5ms,                                /* Task ID */  \
  OS_NULL,                                             /* Accounting structure */  \
  &OS_TOOL_MR_START(Core0_OsTask_Bsw_5ms),             /* start of data/bss */  \
  &OS_TOOL_MR_END(Core0_OsTask_Bsw_5ms),               /* end of data/bss */  \
  &OS_TOOL_MR_LMA_START(Core0_OsTask_Bsw_5ms),         /* start of initial data */  \
  &OS_TOOL_MR_LMA_END(Core0_OsTask_Bsw_5ms),           /* end of initial data */  \
  0U,                                                  /* Execution budget */  \
  0U,                                                  /* Os interrupt lock budget */  \
  0U,                                                  /* All interrupt lock budget */  \
  OS_NULL,                                             /* Resource lock budget */  \
  OS_NULLRATEMONITOR,                                  /* Rate monitor */  \
  &OS_appTable[OsApplication_C0],                      /* Application */  \
  0xfU,                                                /* Permissions */  \
    OS_ARCHTASK_INIT(  \
      0  \
    )  \
),  \
OS_TASKCONFIG_INIT(    /* Core0_OsTask_Appl_20ms */  \
  &OS_taskDynamic_core0[1],                            /* Dynamic task structure */  \
  2U,                                                  /* Run priority */  \
  2U,                                                  /* Queuing priority */  \
  2,                                                   /* Activation index */  \
  &OS_TASK_Core0_OsTask_Appl_20ms,                     /* Task entry */  \
  &OS_taskStack0_slot0[0],                             /* Stack base */  \
  4104U,                                               /* Stack size */  \
  0U,                                                  /* Max. activations */  \
  (OS_TF_EXTENDED),                                    /* Flags */  \
  Core0_OsTask_Appl_20ms,                              /* Task ID */  \
  OS_NULL,                                             /* Accounting structure */  \
  &OS_TOOL_MR_START(Core0_OsTask_Appl_20ms),           /* start of data/bss */  \
  &OS_TOOL_MR_END(Core0_OsTask_Appl_20ms),             /* end of data/bss */  \
  &OS_TOOL_MR_LMA_START(Core0_OsTask_Appl_20ms),       /* start of initial data */  \
  &OS_TOOL_MR_LMA_END(Core0_OsTask_Appl_20ms),         /* end of initial data */  \
  0U,                                                  /* Execution budget */  \
  0U,                                                  /* Os interrupt lock budget */  \
  0U,                                                  /* All interrupt lock budget */  \
  OS_NULL,                                             /* Resource lock budget */  \
  OS_NULLRATEMONITOR,                                  /* Rate monitor */  \
  &OS_appTable[OsApplication_C0],                      /* Application */  \
  0xfU,                                                /* Permissions */  \
    OS_ARCHTASK_INIT(  \
      0  \
    )  \
),  \
OS_TASKCONFIG_INIT(    /* Core0_OsTask_Appl_60ms */  \
  &OS_taskDynamic_core0[2],                            /* Dynamic task structure */  \
  0U,                                                  /* Run priority */  \
  0U,                                                  /* Queuing priority */  \
  3,                                                   /* Activation index */  \
  &OS_TASK_Core0_OsTask_Appl_60ms,                     /* Task entry */  \
  &OS_taskStack0_slot2[0],                             /* Stack base */  \
  1032U,                                               /* Stack size */  \
  0U,                                                  /* Max. activations */  \
  (OS_TF_EXTENDED),                                    /* Flags */  \
  Core0_OsTask_Appl_60ms,                              /* Task ID */  \
  OS_NULL,                                             /* Accounting structure */  \
  &OS_TOOL_MR_START(Core0_OsTask_Appl_60ms),           /* start of data/bss */  \
  &OS_TOOL_MR_END(Core0_OsTask_Appl_60ms),             /* end of data/bss */  \
  &OS_TOOL_MR_LMA_START(Core0_OsTask_Appl_60ms),       /* start of initial data */  \
  &OS_TOOL_MR_LMA_END(Core0_OsTask_Appl_60ms),         /* end of initial data */  \
  0U,                                                  /* Execution budget */  \
  0U,                                                  /* Os interrupt lock budget */  \
  0U,                                                  /* All interrupt lock budget */  \
  OS_NULL,                                             /* Resource lock budget */  \
  OS_NULLRATEMONITOR,                                  /* Rate monitor */  \
  &OS_appTable[OsApplication_C0],                      /* Application */  \
  0xfU,                                                /* Permissions */  \
    OS_ARCHTASK_INIT(  \
      0  \
    )  \
),  \
OS_TASKCONFIG_INIT(    /* Core0_OsTask_OperationInovkedProxy */  \
  &OS_taskDynamic_core0[3],                            /* Dynamic task structure */  \
  9U,                                                  /* Run priority */  \
  9U,                                                  /* Queuing priority */  \
  4,                                                   /* Activation index */  \
  &OS_TASK_Core0_OsTask_OperationInovkedProxy,         /* Task entry */  \
  &OS_taskStack0_slot6[0],                             /* Stack base */  \
  520U,                                                /* Stack size */  \
  0U,                                                  /* Max. activations */  \
  (OS_TF_EXTENDED),                                    /* Flags */  \
  Core0_OsTask_OperationInovkedProxy,                  /* Task ID */  \
  OS_NULL,                                             /* Accounting structure */  \
  &OS_TOOL_MR_START(Core0_OsTask_OperationInovkedProxy),  /* start of data/bss */  \
  &OS_TOOL_MR_END(Core0_OsTask_OperationInovkedProxy),  /* end of data/bss */  \
  &OS_TOOL_MR_LMA_START(Core0_OsTask_OperationInovkedProxy),  /* start of initial data */  \
  &OS_TOOL_MR_LMA_END(Core0_OsTask_OperationInovkedProxy),  /* end of initial data */  \
  0U,                                                  /* Execution budget */  \
  0U,                                                  /* Os interrupt lock budget */  \
  0U,                                                  /* All interrupt lock budget */  \
  OS_NULL,                                             /* Resource lock budget */  \
  OS_NULLRATEMONITOR,                                  /* Rate monitor */  \
  &OS_appTable[OsApplication_C0],                      /* Application */  \
  0xfU,                                                /* Permissions */  \
    OS_ARCHTASK_INIT(  \
      0  \
    )  \
),  \
OS_TASKCONFIG_INIT(    /* Core1_OsTask_Bsw_20ms */  \
  &OS_taskDynamic_core1[0],                            /* Dynamic task structure */  \
  3U,                                                  /* Run priority */  \
  3U,                                                  /* Queuing priority */  \
  1,                                                   /* Activation index */  \
  &OS_TASK_Core1_OsTask_Bsw_20ms,                      /* Task entry */  \
  &OS_taskStack1_slot3[0],                             /* Stack base */  \
  520U,                                                /* Stack size */  \
  0U,                                                  /* Max. activations */  \
  (OS_TF_EXTENDED),                                    /* Flags */  \
  Core1_OsTask_Bsw_20ms,                               /* Task ID */  \
  OS_NULL,                                             /* Accounting structure */  \
  &OS_TOOL_MR_START(Core1_OsTask_Bsw_20ms),            /* start of data/bss */  \
  &OS_TOOL_MR_END(Core1_OsTask_Bsw_20ms),              /* end of data/bss */  \
  &OS_TOOL_MR_LMA_START(Core1_OsTask_Bsw_20ms),        /* start of initial data */  \
  &OS_TOOL_MR_LMA_END(Core1_OsTask_Bsw_20ms),          /* end of initial data */  \
  0U,                                                  /* Execution budget */  \
  0U,                                                  /* Os interrupt lock budget */  \
  0U,                                                  /* All interrupt lock budget */  \
  OS_NULL,                                             /* Resource lock budget */  \
  OS_NULLRATEMONITOR,                                  /* Rate monitor */  \
  &OS_appTable[OsApplication_C1],                      /* Application */  \
  0xfU,                                                /* Permissions */  \
    OS_ARCHTASK_INIT(  \
      0  \
    )  \
),  \
OS_TASKCONFIG_INIT(    /* Core1_OsTask_Appl_10ms */  \
  &OS_taskDynamic_core1[1],                            /* Dynamic task structure */  \
  4U,                                                  /* Run priority */  \
  4U,                                                  /* Queuing priority */  \
  2,                                                   /* Activation index */  \
  &OS_TASK_Core1_OsTask_Appl_10ms,                     /* Task entry */  \
  &OS_taskStack1_slot0[0],                             /* Stack base */  \
  5128U,                                               /* Stack size */  \
  0U,                                                  /* Max. activations */  \
  (OS_TF_EXTENDED),                                    /* Flags */  \
  Core1_OsTask_Appl_10ms,                              /* Task ID */  \
  OS_NULL,                                             /* Accounting structure */  \
  &OS_TOOL_MR_START(Core1_OsTask_Appl_10ms),           /* start of data/bss */  \
  &OS_TOOL_MR_END(Core1_OsTask_Appl_10ms),             /* end of data/bss */  \
  &OS_TOOL_MR_LMA_START(Core1_OsTask_Appl_10ms),       /* start of initial data */  \
  &OS_TOOL_MR_LMA_END(Core1_OsTask_Appl_10ms),         /* end of initial data */  \
  0U,                                                  /* Execution budget */  \
  0U,                                                  /* Os interrupt lock budget */  \
  0U,                                                  /* All interrupt lock budget */  \
  OS_NULL,                                             /* Resource lock budget */  \
  OS_NULLRATEMONITOR,                                  /* Rate monitor */  \
  &OS_appTable[OsApplication_C1],                      /* Application */  \
  0xfU,                                                /* Permissions */  \
    OS_ARCHTASK_INIT(  \
      0  \
    )  \
),  \
OS_TASKCONFIG_INIT(    /* Core2_OsTask_Bsw_20ms */  \
  &OS_taskDynamic_core2[0],                            /* Dynamic task structure */  \
  1U,                                                  /* Run priority */  \
  1U,                                                  /* Queuing priority */  \
  1,                                                   /* Activation index */  \
  &OS_TASK_Core2_OsTask_Bsw_20ms,                      /* Task entry */  \
  &OS_taskStack2_slot1[0],                             /* Stack base */  \
  520U,                                                /* Stack size */  \
  0U,                                                  /* Max. activations */  \
  (OS_TF_EXTENDED),                                    /* Flags */  \
  Core2_OsTask_Bsw_20ms,                               /* Task ID */  \
  OS_NULL,                                             /* Accounting structure */  \
  &OS_TOOL_MR_START(Core2_OsTask_Bsw_20ms),            /* start of data/bss */  \
  &OS_TOOL_MR_END(Core2_OsTask_Bsw_20ms),              /* end of data/bss */  \
  &OS_TOOL_MR_LMA_START(Core2_OsTask_Bsw_20ms),        /* start of initial data */  \
  &OS_TOOL_MR_LMA_END(Core2_OsTask_Bsw_20ms),          /* end of initial data */  \
  0U,                                                  /* Execution budget */  \
  0U,                                                  /* Os interrupt lock budget */  \
  0U,                                                  /* All interrupt lock budget */  \
  OS_NULL,                                             /* Resource lock budget */  \
  OS_NULLRATEMONITOR,                                  /* Rate monitor */  \
  &OS_appTable[OsApplication_C2],                      /* Application */  \
  0xfU,                                                /* Permissions */  \
    OS_ARCHTASK_INIT(  \
      0  \
    )  \
),  \
OS_TASKCONFIG_INIT(    /* Core2_OsTask_Appl_5ms */  \
  &OS_taskDynamic_core2[1],                            /* Dynamic task structure */  \
  2U,                                                  /* Run priority */  \
  2U,                                                  /* Queuing priority */  \
  2,                                                   /* Activation index */  \
  &OS_TASK_Core2_OsTask_Appl_5ms,                      /* Task entry */  \
  &OS_taskStack2_slot0[0],                             /* Stack base */  \
  1032U,                                               /* Stack size */  \
  0U,                                                  /* Max. activations */  \
  (OS_TF_EXTENDED),                                    /* Flags */  \
  Core2_OsTask_Appl_5ms,                               /* Task ID */  \
  OS_NULL,                                             /* Accounting structure */  \
  &OS_TOOL_MR_START(Core2_OsTask_Appl_5ms),            /* start of data/bss */  \
  &OS_TOOL_MR_END(Core2_OsTask_Appl_5ms),              /* end of data/bss */  \
  &OS_TOOL_MR_LMA_START(Core2_OsTask_Appl_5ms),        /* start of initial data */  \
  &OS_TOOL_MR_LMA_END(Core2_OsTask_Appl_5ms),          /* end of initial data */  \
  0U,                                                  /* Execution budget */  \
  0U,                                                  /* Os interrupt lock budget */  \
  0U,                                                  /* All interrupt lock budget */  \
  OS_NULL,                                             /* Resource lock budget */  \
  OS_NULLRATEMONITOR,                                  /* Rate monitor */  \
  &OS_appTable[OsApplication_C2],                      /* Application */  \
  0xfU,                                                /* Permissions */  \
    OS_ARCHTASK_INIT(  \
      0  \
    )  \
),  \
OS_TASKCONFIG_INIT(    /* Core3_OsTask_Bsw_20ms */  \
  &OS_taskDynamic_core3[0],                            /* Dynamic task structure */  \
  2U,                                                  /* Run priority */  \
  2U,                                                  /* Queuing priority */  \
  1,                                                   /* Activation index */  \
  &OS_TASK_Core3_OsTask_Bsw_20ms,                      /* Task entry */  \
  &OS_taskStack3_slot2[0],                             /* Stack base */  \
  520U,                                                /* Stack size */  \
  0U,                                                  /* Max. activations */  \
  (OS_TF_EXTENDED),                                    /* Flags */  \
  Core3_OsTask_Bsw_20ms,                               /* Task ID */  \
  OS_NULL,                                             /* Accounting structure */  \
  &OS_TOOL_MR_START(Core3_OsTask_Bsw_20ms),            /* start of data/bss */  \
  &OS_TOOL_MR_END(Core3_OsTask_Bsw_20ms),              /* end of data/bss */  \
  &OS_TOOL_MR_LMA_START(Core3_OsTask_Bsw_20ms),        /* start of initial data */  \
  &OS_TOOL_MR_LMA_END(Core3_OsTask_Bsw_20ms),          /* end of initial data */  \
  0U,                                                  /* Execution budget */  \
  0U,                                                  /* Os interrupt lock budget */  \
  0U,                                                  /* All interrupt lock budget */  \
  OS_NULL,                                             /* Resource lock budget */  \
  OS_NULLRATEMONITOR,                                  /* Rate monitor */  \
  &OS_appTable[OsApplication_C3],                      /* Application */  \
  0xfU,                                                /* Permissions */  \
    OS_ARCHTASK_INIT(  \
      0  \
    )  \
),  \
OS_TASKCONFIG_INIT(    /* Core3_OsTask_OperationInovkedProxy */  \
  &OS_taskDynamic_core3[1],                            /* Dynamic task structure */  \
  5U,                                                  /* Run priority */  \
  5U,                                                  /* Queuing priority */  \
  2,                                                   /* Activation index */  \
  &OS_TASK_Core3_OsTask_OperationInovkedProxy,         /* Task entry */  \
  &OS_taskStack3_slot3[0],                             /* Stack base */  \
  520U,                                                /* Stack size */  \
  0U,                                                  /* Max. activations */  \
  (OS_TF_EXTENDED),                                    /* Flags */  \
  Core3_OsTask_OperationInovkedProxy,                  /* Task ID */  \
  OS_NULL,                                             /* Accounting structure */  \
  &OS_TOOL_MR_START(Core3_OsTask_OperationInovkedProxy),  /* start of data/bss */  \
  &OS_TOOL_MR_END(Core3_OsTask_OperationInovkedProxy),  /* end of data/bss */  \
  &OS_TOOL_MR_LMA_START(Core3_OsTask_OperationInovkedProxy),  /* start of initial data */  \
  &OS_TOOL_MR_LMA_END(Core3_OsTask_OperationInovkedProxy),  /* end of initial data */  \
  0U,                                                  /* Execution budget */  \
  0U,                                                  /* Os interrupt lock budget */  \
  0U,                                                  /* All interrupt lock budget */  \
  OS_NULL,                                             /* Resource lock budget */  \
  OS_NULLRATEMONITOR,                                  /* Rate monitor */  \
  &OS_appTable[OsApplication_C3],                      /* Application */  \
  0xfU,                                                /* Permissions */  \
    OS_ARCHTASK_INIT(  \
      0  \
    )  \
),  \
OS_TASKCONFIG_INIT(    /* Core0_DefaultTask */  \
  &OS_taskDynamic_core0[4],                            /* Dynamic task structure */  \
  13U,                                                 /* Run priority */  \
  1U,                                                  /* Queuing priority */  \
  5,                                                   /* Activation index */  \
  &OS_TASK_Core0_DefaultTask,                          /* Task entry */  \
  &OS_taskStack0_slot7[0],                             /* Stack base */  \
  520U,                                                /* Stack size */  \
  0U,                                                  /* Max. activations */  \
  (OS_TF_NONPREEMPT),                                  /* Flags */  \
  Core0_DefaultTask,                                   /* Task ID */  \
  OS_NULL,                                             /* Accounting structure */  \
  &OS_TOOL_MR_START(Core0_DefaultTask),                /* start of data/bss */  \
  &OS_TOOL_MR_END(Core0_DefaultTask),                  /* end of data/bss */  \
  &OS_TOOL_MR_LMA_START(Core0_DefaultTask),            /* start of initial data */  \
  &OS_TOOL_MR_LMA_END(Core0_DefaultTask),              /* end of initial data */  \
  0U,                                                  /* Execution budget */  \
  0U,                                                  /* Os interrupt lock budget */  \
  0U,                                                  /* All interrupt lock budget */  \
  OS_NULL,                                             /* Resource lock budget */  \
  OS_NULLRATEMONITOR,                                  /* Rate monitor */  \
  &OS_appTable[OsApplication_C0],                      /* Application */  \
  0x1U,                                                /* Permissions */  \
    OS_ARCHTASK_INIT(  \
      0  \
    )  \
),  \
OS_TASKCONFIG_INIT(    /* Core0_InitTask_Appl */  \
  &OS_taskDynamic_core0[5],                            /* Dynamic task structure */  \
  13U,                                                 /* Run priority */  \
  12U,                                                 /* Queuing priority */  \
  6,                                                   /* Activation index */  \
  &OS_TASK_Core0_InitTask_Appl,                        /* Task entry */  \
  &OS_taskStack0_slot8[0],                             /* Stack base */  \
  520U,                                                /* Stack size */  \
  0U,                                                  /* Max. activations */  \
  (OS_TF_NONPREEMPT),                                  /* Flags */  \
  Core0_InitTask_Appl,                                 /* Task ID */  \
  OS_NULL,                                             /* Accounting structure */  \
  &OS_TOOL_MR_START(Core0_InitTask_Appl),              /* start of data/bss */  \
  &OS_TOOL_MR_END(Core0_InitTask_Appl),                /* end of data/bss */  \
  &OS_TOOL_MR_LMA_START(Core0_InitTask_Appl),          /* start of initial data */  \
  &OS_TOOL_MR_LMA_END(Core0_InitTask_Appl),            /* end of initial data */  \
  0U,                                                  /* Execution budget */  \
  0U,                                                  /* Os interrupt lock budget */  \
  0U,                                                  /* All interrupt lock budget */  \
  OS_NULL,                                             /* Resource lock budget */  \
  OS_NULLRATEMONITOR,                                  /* Rate monitor */  \
  &OS_appTable[OsApplication_C0],                      /* Application */  \
  0xfU,                                                /* Permissions */  \
    OS_ARCHTASK_INIT(  \
      0  \
    )  \
),  \
OS_TASKCONFIG_INIT(    /* Core0_OsTask_FunctionSafety_5ms */  \
  &OS_taskDynamic_core0[6],                            /* Dynamic task structure */  \
  10U,                                                 /* Run priority */  \
  10U,                                                 /* Queuing priority */  \
  7,                                                   /* Activation index */  \
  &OS_TASK_Core0_OsTask_FunctionSafety_5ms,            /* Task entry */  \
  &OS_taskStack0_slot9[0],                             /* Stack base */  \
  520U,                                                /* Stack size */  \
  0U,                                                  /* Max. activations */  \
  0,                                                   /* Flags */  \
  Core0_OsTask_FunctionSafety_5ms,                     /* Task ID */  \
  OS_NULL,                                             /* Accounting structure */  \
  &OS_TOOL_MR_START(Core0_OsTask_FunctionSafety_5ms),  /* start of data/bss */  \
  &OS_TOOL_MR_END(Core0_OsTask_FunctionSafety_5ms),    /* end of data/bss */  \
  &OS_TOOL_MR_LMA_START(Core0_OsTask_FunctionSafety_5ms),  /* start of initial data */  \
  &OS_TOOL_MR_LMA_END(Core0_OsTask_FunctionSafety_5ms),  /* end of initial data */  \
  0U,                                                  /* Execution budget */  \
  0U,                                                  /* Os interrupt lock budget */  \
  0U,                                                  /* All interrupt lock budget */  \
  OS_NULL,                                             /* Resource lock budget */  \
  OS_NULLRATEMONITOR,                                  /* Rate monitor */  \
  &OS_appTable[OsApplication_C0],                      /* Application */  \
  0xfU,                                                /* Permissions */  \
    OS_ARCHTASK_INIT(  \
      0  \
    )  \
),  \
OS_TASKCONFIG_INIT(    /* Core0_OsTask_Bsw_10ms */  \
  &OS_taskDynamic_core0[7],                            /* Dynamic task structure */  \
  6U,                                                  /* Run priority */  \
  6U,                                                  /* Queuing priority */  \
  8,                                                   /* Activation index */  \
  &OS_TASK_Core0_OsTask_Bsw_10ms,                      /* Task entry */  \
  &OS_taskStack0_slot1[0],                             /* Stack base */  \
  4104U,                                               /* Stack size */  \
  0U,                                                  /* Max. activations */  \
  0,                                                   /* Flags */  \
  Core0_OsTask_Bsw_10ms,                               /* Task ID */  \
  OS_NULL,                                             /* Accounting structure */  \
  &OS_TOOL_MR_START(Core0_OsTask_Bsw_10ms),            /* start of data/bss */  \
  &OS_TOOL_MR_END(Core0_OsTask_Bsw_10ms),              /* end of data/bss */  \
  &OS_TOOL_MR_LMA_START(Core0_OsTask_Bsw_10ms),        /* start of initial data */  \
  &OS_TOOL_MR_LMA_END(Core0_OsTask_Bsw_10ms),          /* end of initial data */  \
  0U,                                                  /* Execution budget */  \
  0U,                                                  /* Os interrupt lock budget */  \
  0U,                                                  /* All interrupt lock budget */  \
  OS_NULL,                                             /* Resource lock budget */  \
  OS_NULLRATEMONITOR,                                  /* Rate monitor */  \
  &OS_appTable[OsApplication_C0],                      /* Application */  \
  0xfU,                                                /* Permissions */  \
    OS_ARCHTASK_INIT(  \
      0  \
    )  \
),  \
OS_TASKCONFIG_INIT(    /* Core0_OsTask_Bsw_20ms */  \
  &OS_taskDynamic_core0[8],                            /* Dynamic task structure */  \
  3U,                                                  /* Run priority */  \
  3U,                                                  /* Queuing priority */  \
  9,                                                   /* Activation index */  \
  &OS_TASK_Core0_OsTask_Bsw_20ms,                      /* Task entry */  \
  &OS_taskStack0_slot10[0],                            /* Stack base */  \
  520U,                                                /* Stack size */  \
  0U,                                                  /* Max. activations */  \
  0,                                                   /* Flags */  \
  Core0_OsTask_Bsw_20ms,                               /* Task ID */  \
  OS_NULL,                                             /* Accounting structure */  \
  &OS_TOOL_MR_START(Core0_OsTask_Bsw_20ms),            /* start of data/bss */  \
  &OS_TOOL_MR_END(Core0_OsTask_Bsw_20ms),              /* end of data/bss */  \
  &OS_TOOL_MR_LMA_START(Core0_OsTask_Bsw_20ms),        /* start of initial data */  \
  &OS_TOOL_MR_LMA_END(Core0_OsTask_Bsw_20ms),          /* end of initial data */  \
  0U,                                                  /* Execution budget */  \
  0U,                                                  /* Os interrupt lock budget */  \
  0U,                                                  /* All interrupt lock budget */  \
  OS_NULL,                                             /* Resource lock budget */  \
  OS_NULLRATEMONITOR,                                  /* Rate monitor */  \
  &OS_appTable[OsApplication_C0],                      /* Application */  \
  0xfU,                                                /* Permissions */  \
    OS_ARCHTASK_INIT(  \
      0  \
    )  \
),  \
OS_TASKCONFIG_INIT(    /* Core0_OsTask_Appl_5ms */  \
  &OS_taskDynamic_core0[9],                            /* Dynamic task structure */  \
  7U,                                                  /* Run priority */  \
  7U,                                                  /* Queuing priority */  \
  10,                                                  /* Activation index */  \
  &OS_TASK_Core0_OsTask_Appl_5ms,                      /* Task entry */  \
  &OS_taskStack0_slot3[0],                             /* Stack base */  \
  1032U,                                               /* Stack size */  \
  0U,                                                  /* Max. activations */  \
  0,                                                   /* Flags */  \
  Core0_OsTask_Appl_5ms,                               /* Task ID */  \
  OS_NULL,                                             /* Accounting structure */  \
  &OS_TOOL_MR_START(Core0_OsTask_Appl_5ms),            /* start of data/bss */  \
  &OS_TOOL_MR_END(Core0_OsTask_Appl_5ms),              /* end of data/bss */  \
  &OS_TOOL_MR_LMA_START(Core0_OsTask_Appl_5ms),        /* start of initial data */  \
  &OS_TOOL_MR_LMA_END(Core0_OsTask_Appl_5ms),          /* end of initial data */  \
  0U,                                                  /* Execution budget */  \
  0U,                                                  /* Os interrupt lock budget */  \
  0U,                                                  /* All interrupt lock budget */  \
  OS_NULL,                                             /* Resource lock budget */  \
  OS_NULLRATEMONITOR,                                  /* Rate monitor */  \
  &OS_appTable[OsApplication_C0],                      /* Application */  \
  0xfU,                                                /* Permissions */  \
    OS_ARCHTASK_INIT(  \
      0  \
    )  \
),  \
OS_TASKCONFIG_INIT(    /* Core0_OsTask_Appl_10ms */  \
  &OS_taskDynamic_core0[10],                           /* Dynamic task structure */  \
  4U,                                                  /* Run priority */  \
  4U,                                                  /* Queuing priority */  \
  11,                                                  /* Activation index */  \
  &OS_TASK_Core0_OsTask_Appl_10ms,                     /* Task entry */  \
  &OS_taskStack0_slot4[0],                             /* Stack base */  \
  1032U,                                               /* Stack size */  \
  0U,                                                  /* Max. activations */  \
  0,                                                   /* Flags */  \
  Core0_OsTask_Appl_10ms,                              /* Task ID */  \
  OS_NULL,                                             /* Accounting structure */  \
  &OS_TOOL_MR_START(Core0_OsTask_Appl_10ms),           /* start of data/bss */  \
  &OS_TOOL_MR_END(Core0_OsTask_Appl_10ms),             /* end of data/bss */  \
  &OS_TOOL_MR_LMA_START(Core0_OsTask_Appl_10ms),       /* start of initial data */  \
  &OS_TOOL_MR_LMA_END(Core0_OsTask_Appl_10ms),         /* end of initial data */  \
  0U,                                                  /* Execution budget */  \
  0U,                                                  /* Os interrupt lock budget */  \
  0U,                                                  /* All interrupt lock budget */  \
  OS_NULL,                                             /* Resource lock budget */  \
  OS_NULLRATEMONITOR,                                  /* Rate monitor */  \
  &OS_appTable[OsApplication_C0],                      /* Application */  \
  0xfU,                                                /* Permissions */  \
    OS_ARCHTASK_INIT(  \
      0  \
    )  \
),  \
OS_TASKCONFIG_INIT(    /* Core1_DefaultTask */  \
  &OS_taskDynamic_core1[2],                            /* Dynamic task structure */  \
  7U,                                                  /* Run priority */  \
  1U,                                                  /* Queuing priority */  \
  3,                                                   /* Activation index */  \
  &OS_TASK_Core1_DefaultTask,                          /* Task entry */  \
  &OS_taskStack1_slot4[0],                             /* Stack base */  \
  520U,                                                /* Stack size */  \
  0U,                                                  /* Max. activations */  \
  (OS_TF_NONPREEMPT),                                  /* Flags */  \
  Core1_DefaultTask,                                   /* Task ID */  \
  OS_NULL,                                             /* Accounting structure */  \
  &OS_TOOL_MR_START(Core1_DefaultTask),                /* start of data/bss */  \
  &OS_TOOL_MR_END(Core1_DefaultTask),                  /* end of data/bss */  \
  &OS_TOOL_MR_LMA_START(Core1_DefaultTask),            /* start of initial data */  \
  &OS_TOOL_MR_LMA_END(Core1_DefaultTask),              /* end of initial data */  \
  0U,                                                  /* Execution budget */  \
  0U,                                                  /* Os interrupt lock budget */  \
  0U,                                                  /* All interrupt lock budget */  \
  OS_NULL,                                             /* Resource lock budget */  \
  OS_NULLRATEMONITOR,                                  /* Rate monitor */  \
  &OS_appTable[OsApplication_C1],                      /* Application */  \
  0x2U,                                                /* Permissions */  \
    OS_ARCHTASK_INIT(  \
      0  \
    )  \
),  \
OS_TASKCONFIG_INIT(    /* Core1_InitTask_Appl */  \
  &OS_taskDynamic_core1[3],                            /* Dynamic task structure */  \
  7U,                                                  /* Run priority */  \
  6U,                                                  /* Queuing priority */  \
  4,                                                   /* Activation index */  \
  &OS_TASK_Core1_InitTask_Appl,                        /* Task entry */  \
  &OS_taskStack1_slot5[0],                             /* Stack base */  \
  520U,                                                /* Stack size */  \
  0U,                                                  /* Max. activations */  \
  (OS_TF_NONPREEMPT),                                  /* Flags */  \
  Core1_InitTask_Appl,                                 /* Task ID */  \
  OS_NULL,                                             /* Accounting structure */  \
  &OS_TOOL_MR_START(Core1_InitTask_Appl),              /* start of data/bss */  \
  &OS_TOOL_MR_END(Core1_InitTask_Appl),                /* end of data/bss */  \
  &OS_TOOL_MR_LMA_START(Core1_InitTask_Appl),          /* start of initial data */  \
  &OS_TOOL_MR_LMA_END(Core1_InitTask_Appl),            /* end of initial data */  \
  0U,                                                  /* Execution budget */  \
  0U,                                                  /* Os interrupt lock budget */  \
  0U,                                                  /* All interrupt lock budget */  \
  OS_NULL,                                             /* Resource lock budget */  \
  OS_NULLRATEMONITOR,                                  /* Rate monitor */  \
  &OS_appTable[OsApplication_C1],                      /* Application */  \
  0xfU,                                                /* Permissions */  \
    OS_ARCHTASK_INIT(  \
      0  \
    )  \
),  \
OS_TASKCONFIG_INIT(    /* Core1_OsTask_Appl_20ms */  \
  &OS_taskDynamic_core1[4],                            /* Dynamic task structure */  \
  2U,                                                  /* Run priority */  \
  2U,                                                  /* Queuing priority */  \
  5,                                                   /* Activation index */  \
  &OS_TASK_Core1_OsTask_Appl_20ms,                     /* Task entry */  \
  &OS_taskStack1_slot1[0],                             /* Stack base */  \
  5128U,                                               /* Stack size */  \
  0U,                                                  /* Max. activations */  \
  0,                                                   /* Flags */  \
  Core1_OsTask_Appl_20ms,                              /* Task ID */  \
  OS_NULL,                                             /* Accounting structure */  \
  &OS_TOOL_MR_START(Core1_OsTask_Appl_20ms),           /* start of data/bss */  \
  &OS_TOOL_MR_END(Core1_OsTask_Appl_20ms),             /* end of data/bss */  \
  &OS_TOOL_MR_LMA_START(Core1_OsTask_Appl_20ms),       /* start of initial data */  \
  &OS_TOOL_MR_LMA_END(Core1_OsTask_Appl_20ms),         /* end of initial data */  \
  0U,                                                  /* Execution budget */  \
  0U,                                                  /* Os interrupt lock budget */  \
  0U,                                                  /* All interrupt lock budget */  \
  OS_NULL,                                             /* Resource lock budget */  \
  OS_NULLRATEMONITOR,                                  /* Rate monitor */  \
  &OS_appTable[OsApplication_C1],                      /* Application */  \
  0xfU,                                                /* Permissions */  \
    OS_ARCHTASK_INIT(  \
      0  \
    )  \
),  \
OS_TASKCONFIG_INIT(    /* Core1_OsTask_Appl_60ms */  \
  &OS_taskDynamic_core1[5],                            /* Dynamic task structure */  \
  0U,                                                  /* Run priority */  \
  0U,                                                  /* Queuing priority */  \
  6,                                                   /* Activation index */  \
  &OS_TASK_Core1_OsTask_Appl_60ms,                     /* Task entry */  \
  &OS_taskStack1_slot2[0],                             /* Stack base */  \
  5128U,                                               /* Stack size */  \
  0U,                                                  /* Max. activations */  \
  0,                                                   /* Flags */  \
  Core1_OsTask_Appl_60ms,                              /* Task ID */  \
  OS_NULL,                                             /* Accounting structure */  \
  &OS_TOOL_MR_START(Core1_OsTask_Appl_60ms),           /* start of data/bss */  \
  &OS_TOOL_MR_END(Core1_OsTask_Appl_60ms),             /* end of data/bss */  \
  &OS_TOOL_MR_LMA_START(Core1_OsTask_Appl_60ms),       /* start of initial data */  \
  &OS_TOOL_MR_LMA_END(Core1_OsTask_Appl_60ms),         /* end of initial data */  \
  0U,                                                  /* Execution budget */  \
  0U,                                                  /* Os interrupt lock budget */  \
  0U,                                                  /* All interrupt lock budget */  \
  OS_NULL,                                             /* Resource lock budget */  \
  OS_NULLRATEMONITOR,                                  /* Rate monitor */  \
  &OS_appTable[OsApplication_C1],                      /* Application */  \
  0xfU,                                                /* Permissions */  \
    OS_ARCHTASK_INIT(  \
      0  \
    )  \
),  \
OS_TASKCONFIG_INIT(    /* Core1_OsTask_OperationInovkedProxy */  \
  &OS_taskDynamic_core1[6],                            /* Dynamic task structure */  \
  5U,                                                  /* Run priority */  \
  5U,                                                  /* Queuing priority */  \
  7,                                                   /* Activation index */  \
  &OS_TASK_Core1_OsTask_OperationInovkedProxy,         /* Task entry */  \
  &OS_taskStack1_slot6[0],                             /* Stack base */  \
  520U,                                                /* Stack size */  \
  0U,                                                  /* Max. activations */  \
  0,                                                   /* Flags */  \
  Core1_OsTask_OperationInovkedProxy,                  /* Task ID */  \
  OS_NULL,                                             /* Accounting structure */  \
  &OS_TOOL_MR_START(Core1_OsTask_OperationInovkedProxy),  /* start of data/bss */  \
  &OS_TOOL_MR_END(Core1_OsTask_OperationInovkedProxy),  /* end of data/bss */  \
  &OS_TOOL_MR_LMA_START(Core1_OsTask_OperationInovkedProxy),  /* start of initial data */  \
  &OS_TOOL_MR_LMA_END(Core1_OsTask_OperationInovkedProxy),  /* end of initial data */  \
  0U,                                                  /* Execution budget */  \
  0U,                                                  /* Os interrupt lock budget */  \
  0U,                                                  /* All interrupt lock budget */  \
  OS_NULL,                                             /* Resource lock budget */  \
  OS_NULLRATEMONITOR,                                  /* Rate monitor */  \
  &OS_appTable[OsApplication_C1],                      /* Application */  \
  0xfU,                                                /* Permissions */  \
    OS_ARCHTASK_INIT(  \
      0  \
    )  \
),  \
OS_TASKCONFIG_INIT(    /* Core2_DefaultTask */  \
  &OS_taskDynamic_core2[2],                            /* Dynamic task structure */  \
  5U,                                                  /* Run priority */  \
  0U,                                                  /* Queuing priority */  \
  3,                                                   /* Activation index */  \
  &OS_TASK_Core2_DefaultTask,                          /* Task entry */  \
  &OS_taskStack2_slot2[0],                             /* Stack base */  \
  520U,                                                /* Stack size */  \
  0U,                                                  /* Max. activations */  \
  (OS_TF_NONPREEMPT),                                  /* Flags */  \
  Core2_DefaultTask,                                   /* Task ID */  \
  OS_NULL,                                             /* Accounting structure */  \
  &OS_TOOL_MR_START(Core2_DefaultTask),                /* start of data/bss */  \
  &OS_TOOL_MR_END(Core2_DefaultTask),                  /* end of data/bss */  \
  &OS_TOOL_MR_LMA_START(Core2_DefaultTask),            /* start of initial data */  \
  &OS_TOOL_MR_LMA_END(Core2_DefaultTask),              /* end of initial data */  \
  0U,                                                  /* Execution budget */  \
  0U,                                                  /* Os interrupt lock budget */  \
  0U,                                                  /* All interrupt lock budget */  \
  OS_NULL,                                             /* Resource lock budget */  \
  OS_NULLRATEMONITOR,                                  /* Rate monitor */  \
  &OS_appTable[OsApplication_C2],                      /* Application */  \
  0x4U,                                                /* Permissions */  \
    OS_ARCHTASK_INIT(  \
      0  \
    )  \
),  \
OS_TASKCONFIG_INIT(    /* Core2_InitTask_Appl */  \
  &OS_taskDynamic_core2[3],                            /* Dynamic task structure */  \
  5U,                                                  /* Run priority */  \
  4U,                                                  /* Queuing priority */  \
  4,                                                   /* Activation index */  \
  &OS_TASK_Core2_InitTask_Appl,                        /* Task entry */  \
  &OS_taskStack2_slot3[0],                             /* Stack base */  \
  520U,                                                /* Stack size */  \
  0U,                                                  /* Max. activations */  \
  (OS_TF_NONPREEMPT),                                  /* Flags */  \
  Core2_InitTask_Appl,                                 /* Task ID */  \
  OS_NULL,                                             /* Accounting structure */  \
  &OS_TOOL_MR_START(Core2_InitTask_Appl),              /* start of data/bss */  \
  &OS_TOOL_MR_END(Core2_InitTask_Appl),                /* end of data/bss */  \
  &OS_TOOL_MR_LMA_START(Core2_InitTask_Appl),          /* start of initial data */  \
  &OS_TOOL_MR_LMA_END(Core2_InitTask_Appl),            /* end of initial data */  \
  0U,                                                  /* Execution budget */  \
  0U,                                                  /* Os interrupt lock budget */  \
  0U,                                                  /* All interrupt lock budget */  \
  OS_NULL,                                             /* Resource lock budget */  \
  OS_NULLRATEMONITOR,                                  /* Rate monitor */  \
  &OS_appTable[OsApplication_C2],                      /* Application */  \
  0xfU,                                                /* Permissions */  \
    OS_ARCHTASK_INIT(  \
      0  \
    )  \
),  \
OS_TASKCONFIG_INIT(    /* Core2_OsTask_OperationInovkedProxy */  \
  &OS_taskDynamic_core2[4],                            /* Dynamic task structure */  \
  3U,                                                  /* Run priority */  \
  3U,                                                  /* Queuing priority */  \
  5,                                                   /* Activation index */  \
  &OS_TASK_Core2_OsTask_OperationInovkedProxy,         /* Task entry */  \
  &OS_taskStack2_slot4[0],                             /* Stack base */  \
  520U,                                                /* Stack size */  \
  0U,                                                  /* Max. activations */  \
  0,                                                   /* Flags */  \
  Core2_OsTask_OperationInovkedProxy,                  /* Task ID */  \
  OS_NULL,                                             /* Accounting structure */  \
  &OS_TOOL_MR_START(Core2_OsTask_OperationInovkedProxy),  /* start of data/bss */  \
  &OS_TOOL_MR_END(Core2_OsTask_OperationInovkedProxy),  /* end of data/bss */  \
  &OS_TOOL_MR_LMA_START(Core2_OsTask_OperationInovkedProxy),  /* start of initial data */  \
  &OS_TOOL_MR_LMA_END(Core2_OsTask_OperationInovkedProxy),  /* end of initial data */  \
  0U,                                                  /* Execution budget */  \
  0U,                                                  /* Os interrupt lock budget */  \
  0U,                                                  /* All interrupt lock budget */  \
  OS_NULL,                                             /* Resource lock budget */  \
  OS_NULLRATEMONITOR,                                  /* Rate monitor */  \
  &OS_appTable[OsApplication_C2],                      /* Application */  \
  0xfU,                                                /* Permissions */  \
    OS_ARCHTASK_INIT(  \
      0  \
    )  \
),  \
OS_TASKCONFIG_INIT(    /* Core3_DefaultTask */  \
  &OS_taskDynamic_core3[2],                            /* Dynamic task structure */  \
  7U,                                                  /* Run priority */  \
  0U,                                                  /* Queuing priority */  \
  3,                                                   /* Activation index */  \
  &OS_TASK_Core3_DefaultTask,                          /* Task entry */  \
  &OS_taskStack3_slot4[0],                             /* Stack base */  \
  520U,                                                /* Stack size */  \
  0U,                                                  /* Max. activations */  \
  (OS_TF_NONPREEMPT),                                  /* Flags */  \
  Core3_DefaultTask,                                   /* Task ID */  \
  OS_NULL,                                             /* Accounting structure */  \
  &OS_TOOL_MR_START(Core3_DefaultTask),                /* start of data/bss */  \
  &OS_TOOL_MR_END(Core3_DefaultTask),                  /* end of data/bss */  \
  &OS_TOOL_MR_LMA_START(Core3_DefaultTask),            /* start of initial data */  \
  &OS_TOOL_MR_LMA_END(Core3_DefaultTask),              /* end of initial data */  \
  0U,                                                  /* Execution budget */  \
  0U,                                                  /* Os interrupt lock budget */  \
  0U,                                                  /* All interrupt lock budget */  \
  OS_NULL,                                             /* Resource lock budget */  \
  OS_NULLRATEMONITOR,                                  /* Rate monitor */  \
  &OS_appTable[OsApplication_C3],                      /* Application */  \
  0x8U,                                                /* Permissions */  \
    OS_ARCHTASK_INIT(  \
      0  \
    )  \
),  \
OS_TASKCONFIG_INIT(    /* Core3_InitTask_Appl */  \
  &OS_taskDynamic_core3[3],                            /* Dynamic task structure */  \
  7U,                                                  /* Run priority */  \
  6U,                                                  /* Queuing priority */  \
  4,                                                   /* Activation index */  \
  &OS_TASK_Core3_InitTask_Appl,                        /* Task entry */  \
  &OS_taskStack3_slot5[0],                             /* Stack base */  \
  520U,                                                /* Stack size */  \
  0U,                                                  /* Max. activations */  \
  (OS_TF_NONPREEMPT),                                  /* Flags */  \
  Core3_InitTask_Appl,                                 /* Task ID */  \
  OS_NULL,                                             /* Accounting structure */  \
  &OS_TOOL_MR_START(Core3_InitTask_Appl),              /* start of data/bss */  \
  &OS_TOOL_MR_END(Core3_InitTask_Appl),                /* end of data/bss */  \
  &OS_TOOL_MR_LMA_START(Core3_InitTask_Appl),          /* start of initial data */  \
  &OS_TOOL_MR_LMA_END(Core3_InitTask_Appl),            /* end of initial data */  \
  0U,                                                  /* Execution budget */  \
  0U,                                                  /* Os interrupt lock budget */  \
  0U,                                                  /* All interrupt lock budget */  \
  OS_NULL,                                             /* Resource lock budget */  \
  OS_NULLRATEMONITOR,                                  /* Rate monitor */  \
  &OS_appTable[OsApplication_C3],                      /* Application */  \
  0xfU,                                                /* Permissions */  \
    OS_ARCHTASK_INIT(  \
      0  \
    )  \
),  \
OS_TASKCONFIG_INIT(    /* Core3_OsTask_Appl_10ms */  \
  &OS_taskDynamic_core3[4],                            /* Dynamic task structure */  \
  3U,                                                  /* Run priority */  \
  3U,                                                  /* Queuing priority */  \
  5,                                                   /* Activation index */  \
  &OS_TASK_Core3_OsTask_Appl_10ms,                     /* Task entry */  \
  &OS_taskStack3_slot0[0],                             /* Stack base */  \
  7176U,                                               /* Stack size */  \
  0U,                                                  /* Max. activations */  \
  0,                                                   /* Flags */  \
  Core3_OsTask_Appl_10ms,                              /* Task ID */  \
  OS_NULL,                                             /* Accounting structure */  \
  &OS_TOOL_MR_START(Core3_OsTask_Appl_10ms),           /* start of data/bss */  \
  &OS_TOOL_MR_END(Core3_OsTask_Appl_10ms),             /* end of data/bss */  \
  &OS_TOOL_MR_LMA_START(Core3_OsTask_Appl_10ms),       /* start of initial data */  \
  &OS_TOOL_MR_LMA_END(Core3_OsTask_Appl_10ms),         /* end of initial data */  \
  0U,                                                  /* Execution budget */  \
  0U,                                                  /* Os interrupt lock budget */  \
  0U,                                                  /* All interrupt lock budget */  \
  OS_NULL,                                             /* Resource lock budget */  \
  OS_NULLRATEMONITOR,                                  /* Rate monitor */  \
  &OS_appTable[OsApplication_C3],                      /* Application */  \
  0xfU,                                                /* Permissions */  \
    OS_ARCHTASK_INIT(  \
      0  \
    )  \
),  \
OS_TASKCONFIG_INIT(    /* Core3_OsTask_Appl_50ms */  \
  &OS_taskDynamic_core3[5],                            /* Dynamic task structure */  \
  1U,                                                  /* Run priority */  \
  1U,                                                  /* Queuing priority */  \
  6,                                                   /* Activation index */  \
  &OS_TASK_Core3_OsTask_Appl_50ms,                     /* Task entry */  \
  &OS_taskStack3_slot1[0],                             /* Stack base */  \
  7176U,                                               /* Stack size */  \
  0U,                                                  /* Max. activations */  \
  0,                                                   /* Flags */  \
  Core3_OsTask_Appl_50ms,                              /* Task ID */  \
  OS_NULL,                                             /* Accounting structure */  \
  &OS_TOOL_MR_START(Core3_OsTask_Appl_50ms),           /* start of data/bss */  \
  &OS_TOOL_MR_END(Core3_OsTask_Appl_50ms),             /* end of data/bss */  \
  &OS_TOOL_MR_LMA_START(Core3_OsTask_Appl_50ms),       /* start of initial data */  \
  &OS_TOOL_MR_LMA_END(Core3_OsTask_Appl_50ms),         /* end of initial data */  \
  0U,                                                  /* Execution budget */  \
  0U,                                                  /* Os interrupt lock budget */  \
  0U,                                                  /* All interrupt lock budget */  \
  OS_NULL,                                             /* Resource lock budget */  \
  OS_NULLRATEMONITOR,                                  /* Rate monitor */  \
  &OS_appTable[OsApplication_C3],                      /* Application */  \
  0xfU,                                                /* Permissions */  \
    OS_ARCHTASK_INIT(  \
      0  \
    )  \
),  \
OS_TASKCONFIG_INIT(    /* Core3_OsTask_Appl_60ms */  \
  &OS_taskDynamic_core3[6],                            /* Dynamic task structure */  \
  4U,                                                  /* Run priority */  \
  4U,                                                  /* Queuing priority */  \
  7,                                                   /* Activation index */  \
  &OS_TASK_Core3_OsTask_Appl_60ms,                     /* Task entry */  \
  &OS_taskStack3_slot6[0],                             /* Stack base */  \
  520U,                                                /* Stack size */  \
  0U,                                                  /* Max. activations */  \
  0,                                                   /* Flags */  \
  Core3_OsTask_Appl_60ms,                              /* Task ID */  \
  OS_NULL,                                             /* Accounting structure */  \
  &OS_TOOL_MR_START(Core3_OsTask_Appl_60ms),           /* start of data/bss */  \
  &OS_TOOL_MR_END(Core3_OsTask_Appl_60ms),             /* end of data/bss */  \
  &OS_TOOL_MR_LMA_START(Core3_OsTask_Appl_60ms),       /* start of initial data */  \
  &OS_TOOL_MR_LMA_END(Core3_OsTask_Appl_60ms),         /* end of initial data */  \
  0U,                                                  /* Execution budget */  \
  0U,                                                  /* Os interrupt lock budget */  \
  0U,                                                  /* All interrupt lock budget */  \
  OS_NULL,                                             /* Resource lock budget */  \
  OS_NULLRATEMONITOR,                                  /* Rate monitor */  \
  &OS_appTable[OsApplication_C3],                      /* Application */  \
  0xfU,                                                /* Permissions */  \
    OS_ARCHTASK_INIT(  \
      0  \
    )  \
),
#define OS_NTASKS_CORE0 11
#define OS_NTASKS_CORE1 7
#define OS_NTASKS_CORE2 5
#define OS_NTASKS_CORE3 7

/*===================================================================
 * Tasks Common Scheduling
 *==================================================================*/

#define OS_NPRIORITIES_CORE0 14
#define OS_NPRIORITIES_CORE1 8
#define OS_NPRIORITIES_CORE2 6
#define OS_NPRIORITIES_CORE3 8

/*===================================================================
 * Tasks Linked List Scheduling
 *==================================================================*/

#define OS_NTASKACCOUNTING 0
#define OS_NTASKACTIVATIONS 30
#define OS_NTASKACCOUNTING_CORE0 0
#define OS_NTASKACTIVATIONS_CORE0 11
#define OS_TASKACTIVATIONS_CORE0   \
  /*  0 */ &OS_taskTable[Core0_OsTask_Bsw_5ms],                 \
  /*  1 */ &OS_taskTable[Core0_OsTask_Appl_20ms],               \
  /*  2 */ &OS_taskTable[Core0_OsTask_Appl_60ms],               \
  /*  3 */ &OS_taskTable[Core0_OsTask_OperationInovkedProxy],   \
  /*  4 */ &OS_taskTable[Core0_DefaultTask],                    \
  /*  5 */ &OS_taskTable[Core0_InitTask_Appl],                  \
  /*  6 */ &OS_taskTable[Core0_OsTask_FunctionSafety_5ms],      \
  /*  7 */ &OS_taskTable[Core0_OsTask_Bsw_10ms],                \
  /*  8 */ &OS_taskTable[Core0_OsTask_Bsw_20ms],                \
  /*  9 */ &OS_taskTable[Core0_OsTask_Appl_5ms],                \
  /* 10 */ &OS_taskTable[Core0_OsTask_Appl_10ms]
#define OS_NTASKACCOUNTING_CORE1 0
#define OS_NTASKACTIVATIONS_CORE1 7
#define OS_TASKACTIVATIONS_CORE1   \
  /* 0 */ &OS_taskTable[Core1_OsTask_Bsw_20ms],                \
  /* 1 */ &OS_taskTable[Core1_OsTask_Appl_10ms],               \
  /* 2 */ &OS_taskTable[Core1_DefaultTask],                    \
  /* 3 */ &OS_taskTable[Core1_InitTask_Appl],                  \
  /* 4 */ &OS_taskTable[Core1_OsTask_Appl_20ms],               \
  /* 5 */ &OS_taskTable[Core1_OsTask_Appl_60ms],               \
  /* 6 */ &OS_taskTable[Core1_OsTask_OperationInovkedProxy]
#define OS_NTASKACCOUNTING_CORE2 0
#define OS_NTASKACTIVATIONS_CORE2 5
#define OS_TASKACTIVATIONS_CORE2   \
  /* 0 */ &OS_taskTable[Core2_OsTask_Bsw_20ms],                \
  /* 1 */ &OS_taskTable[Core2_OsTask_Appl_5ms],                \
  /* 2 */ &OS_taskTable[Core2_DefaultTask],                    \
  /* 3 */ &OS_taskTable[Core2_InitTask_Appl],                  \
  /* 4 */ &OS_taskTable[Core2_OsTask_OperationInovkedProxy]
#define OS_NTASKACCOUNTING_CORE3 0
#define OS_NTASKACTIVATIONS_CORE3 7
#define OS_TASKACTIVATIONS_CORE3   \
  /* 0 */ &OS_taskTable[Core3_OsTask_Bsw_20ms],                \
  /* 1 */ &OS_taskTable[Core3_OsTask_OperationInovkedProxy],   \
  /* 2 */ &OS_taskTable[Core3_DefaultTask],                    \
  /* 3 */ &OS_taskTable[Core3_InitTask_Appl],                  \
  /* 4 */ &OS_taskTable[Core3_OsTask_Appl_10ms],               \
  /* 5 */ &OS_taskTable[Core3_OsTask_Appl_50ms],               \
  /* 6 */ &OS_taskTable[Core3_OsTask_Appl_60ms]

/*===================================================================
 * Tricore specific data
 *==================================================================*/

#define OS_TRICORE_TIMESTAMPSTMBASE OS_STM0_BASE
#ifdef __cplusplus
}
#endif
#endif  /* OS_CONFIG_H */
