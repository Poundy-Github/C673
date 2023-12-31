/* Os_configuration_c1.c
 *
 * This file contains the architecture-independent kernel configuration data for core C1.
 *
 * CHECK: TABS 4 (see editor commands at end of file)
 *
 * Copyright Elektrobit Automotive GmbH
 * All rights exclusively reserved for Elektrobit Automotive GmbH,
 * unless expressly agreed to otherwise.
 *
 * $Id: Os_configuration_c1.c 33382 2021-03-03 08:00:10Z arla271030 $
*/

/* CHECK: NOPARSE */
#include <Os_tool.h>
#include <Os_configuration.h>
#include <Os_kernel.h>
#include <Os_configuration_decls.h>

#if (OS_KERNEL_TYPE != OS_MICROKERNEL)
#include <Os_syscalls.h>
#include <board.h>
#include <Os_api.h>
#include <Os_messagequeue.h>
#endif /* OS_KERNEL_TYPE != OS_MICROKERNEL */

#if (OS_KERNEL_TYPE == OS_MICROKERNEL)
#include <Mk_qmboard.h>
#endif /* OS_KERNEL_TYPE == OS_MICROKERNEL */



#if ((OS_PROPERTIES_CORE1 & OS_COREPROP_USED_BIT) != OS_COREPROP_USED_BIT)
#include <memmap/Os_mm_var_begin.h>
os_uint8_t OS_unused_configuration_c1;
#include <memmap/Os_mm_var_end.h>
#else

#if (OS_KERNEL_TYPE != OS_MICROKERNEL)
/*!
 * OS_appDynamic_core1
 *
 * Application state of applications on core C1.
*/
#include <memmap/Os_mm_var_begin.h>
#if (OS_NAPPS_CORE1 != 0)
OS_SECTION_PRAGMA(OS_appDynamic_core1, .bss.core1.appDynamic)
os_appdynamic_t
		OS_SECTION_ATTRIB_PRE(.bss.core1.appDynamic)
		OS_appDynamic_core1[OS_NAPPS_CORE1]
		OS_BSS_SECTION_ATTRIB_POST(.bss.core1.appDynamic);
#endif
#include <memmap/Os_mm_var_end.h>

/*!
 * OS_taskAccounting_core1
 *
 * The accounting information for tasks, one entry per task that needs it.
 * They are only accessible via the pointer os_task_t::accounting.
*/
#if (OS_NTASKACCOUNTING != 0)
#include <memmap/Os_mm_var_begin.h>
#if (OS_NTASKACCOUNTING_CORE1 != 0)
OS_SECTION_PRAGMA(OS_taskAccounting_core1, .bss.core1.taskAccounting)
os_taskaccounting_t
		OS_SECTION_ATTRIB_PRE(.bss.core1.taskAccounting)
		OS_taskAccounting_core1[OS_NTASKACCOUNTING_CORE1]
		OS_BSS_SECTION_ATTRIB_POST(.bss.core1.taskAccounting);
#endif
#include <memmap/Os_mm_var_end.h>
#endif

/*!
 * OS_taskDynamic_core1
 *
 * The dynamic status of tasks, one entry per task. Note: this is not the
 * context of the task, though it may contain it.
*/
#include <memmap/Os_mm_var_begin.h>
#if (OS_NTASKS_CORE1 != 0)
OS_SECTION_PRAGMA(OS_taskDynamic_core1, .bss.core1.taskDynamic)
os_taskdynamic_t
		OS_SECTION_ATTRIB_PRE(.bss.core1.taskDynamic)
		OS_taskDynamic_core1[OS_NTASKS_CORE1]
		OS_BSS_SECTION_ATTRIB_POST(.bss.core1.taskDynamic);
#endif
#include <memmap/Os_mm_var_end.h>


/*!
 * Linked list scheduling algorithm.
 *
 * OS_taskActivations
 *
 * The links in the linked list of the task queue. Each slot contains the
 * index of the next slot in the queue. The corresponding (same index)
 * entry in OS_taskPtrs[] contains the address of the task that owns
 * the slot. There is always at least 1 entry in this array.
 * The first entry (index 0) is used to store the index of the current
 * activation of the currently running task or 0, if there is none.
 */
#include <memmap/Os_mm_const_begin.h>
#if ((OS_NTASKACTIVATIONS_CORE1 != 0) || (OS_N_CORES == 1))
const os_task_t * const OS_TASKPTRS_OBJ_CORE1[OS_NTASKACTIVATIONS_CORE1 + 1] = { OS_TASKACT_CORE1 };
#endif
#include <memmap/Os_mm_const_end.h>

#include <memmap/Os_mm_var_begin.h>
#if ((OS_NTASKACTIVATIONS_CORE1 != 0) || (OS_N_CORES == 1))
OS_SECTION_PRAGMA(OS_TASKACTIVATIONS_OBJ_CORE1, .bss.core1.taskActivations)
os_tasklink_t
		OS_SECTION_ATTRIB_PRE(.bss.core1.taskActivations)
		OS_TASKACTIVATIONS_OBJ_CORE1[OS_NTASKACTIVATIONS_CORE1 + 1]
		OS_BSS_SECTION_ATTRIB_POST(.bss.core1.taskActivations);
#endif
#include <memmap/Os_mm_var_end.h>

/*!
 * Resources
*/
#include <memmap/Os_mm_var_begin.h>
#if (OS_NRESOURCES_CORE1 != 0)
OS_SECTION_PRAGMA(OS_resourceDynamic_core1, .bss.core1.resourceDynamic)
os_resourcedynamic_t
		OS_SECTION_ATTRIB_PRE(.bss.core1.resourceDynamic)
		OS_resourceDynamic_core1[OS_NRESOURCES_CORE1]
		OS_BSS_SECTION_ATTRIB_POST(.bss.core1.resourceDynamic);
#endif
#include <memmap/Os_mm_var_end.h>

/*!
 * OS_isrAccounting_core1
 *
 * The accounting information for ISRs, one entry per ISR that needs it.
 * It's accessible via the pointer os_isr_t::accounting.
*/
#if (OS_NISRACCOUNTING != 0)
#include <memmap/Os_mm_var_begin.h>
#if (OS_NISRACCOUNTING_CORE1 != 0)
OS_SECTION_PRAGMA(OS_isrAccounting_core1, .bss.core1.isrAccounting)
os_israccounting_t
		OS_SECTION_ATTRIB_PRE(.bss.core1.isrAccounting)
		OS_isrAccounting_core1[OS_NISRACCOUNTING_CORE1]
		OS_BSS_SECTION_ATTRIB_POST(.bss.core1.isrAccounting);
#endif
#include <memmap/Os_mm_var_end.h>
#endif /* OS_NISRACCOUNTING!=0 */

/*!
 * Interrupts
 */
#include <memmap/Os_mm_var_begin.h>
#if (OS_NINTERRUPTS_CORE1 != 0)
OS_SECTION_PRAGMA(OS_isrDynamic_core1, .bss.core1.isrDynamic)
os_isrdynamic_t
		OS_SECTION_ATTRIB_PRE(.bss.core1.isrDynamic)
		OS_isrDynamic_core1[OS_NINTERRUPTS_CORE1]
		OS_BSS_SECTION_ATTRIB_POST(.bss.core1.isrDynamic);
#endif
#include <memmap/Os_mm_var_end.h>

/*!
 * OS_rateIndex_core1
 * OS_rateTimer_core1
 *
 * The dynamic state of all rate-monitors. The index array (one per
 * rate-monitor) is the index into the rate-monitor's own ring buffer.
 * The timer array is the aggregated ring buffer array, COUNTLIMIT
 * entries per rate-monitor.
*/
#if (OS_NRATEMONS != 0)
#include <memmap/Os_mm_var_begin.h>
#if (OS_NRATEMONS_CORE1 != 0)
OS_SECTION_PRAGMA(OS_rateIndex_core1, .bss.core1.rateIndex)
os_rateindex_t
		OS_SECTION_ATTRIB_PRE(.bss.core1.rateIndex)
		OS_rateIndex_core1[OS_NRATEMONS_CORE1]
		OS_BSS_SECTION_ATTRIB_POST(.bss.core1.rateIndex);
#endif
#if (OS_NRATETIMERS_CORE1 != 0)
OS_SECTION_PRAGMA(OS_rateTimer_core1, .bss.core1.rateTimer)
os_timestamp_t
		OS_SECTION_ATTRIB_PRE(.bss.core1.rateTimer)
		OS_rateTimer_core1[OS_NRATETIMERS_CORE1]
		OS_BSS_SECTION_ATTRIB_POST(.bss.core1.rateTimer);
#endif
#include <memmap/Os_mm_var_end.h>
#endif /* OS_NRATEMONS != 0 */

/*!
 * OS_crosscoreMessageQueue_ptr
 *
 * Inter-core message queues.
 */
#if (OS_N_CORES > 1)
#include <memmap/Os_mm_var_begin.h>
OS_SECTION_PRAGMA(OS_messageQueue_core1, .bss.shared.core1.messageQueue)
os_messagequeue_t
		OS_SECTION_ATTRIB_PRE(.bss.shared.core1.messageQueue)
		OS_messageQueue_core1
		OS_BSS_SECTION_ATTRIB_POST(.bss.shared.core1.messageQueue);
#include <memmap/Os_mm_var_end.h>
#endif /* OS_N_CORES > 1 */

/*!
 * OS kernel data.
 *
 * OS kernel data local to each core. Hence, each core has its own instance,
 * which needs not to be synchronized with the ones of the other cores (if any).
 */
#include <memmap/Os_mm_var_begin.h>
OS_SECTION_PRAGMA(OS_KERNELDATA_OBJ_CORE1, .data.core1.kernelData)
os_kerneldata_t
		OS_SECTION_ATTRIB_PRE(.data.core1.kernelData)
		OS_KERNELDATA_OBJ_CORE1
		OS_DATA_SECTION_ATTRIB_POST(.data.core1.kernelData) = { OS_KERNELDATA_INIT_CORE1 };
#include <memmap/Os_mm_var_end.h>

#endif /* OS_KERNEL_TYPE != OS_MICROKERNEL */

/*!
 * Counters
*/
#include <memmap/Os_mm_var_begin.h>
#if (OS_NCOUNTERS_CORE1 != 0)
OS_SECTION_PRAGMA(OS_counterDynamic_core1, .bss.core1.counterDynamic)
os_counterdynamic_t
		OS_SECTION_ATTRIB_PRE(.bss.core1.counterDynamic)
		OS_counterDynamic_core1[OS_NCOUNTERS_CORE1]
		OS_BSS_SECTION_ATTRIB_POST(.bss.core1.counterDynamic);
#endif
#include <memmap/Os_mm_var_end.h>

/*!
 * Alarms
*/
#include <memmap/Os_mm_var_begin.h>
#if (OS_TOTALALARMS_CORE1 != 0)
OS_SECTION_PRAGMA(OS_alarmDynamic_core1, .bss.core1.alarmDynamic)
os_alarmdynamic_t
		OS_SECTION_ATTRIB_PRE(.bss.core1.alarmDynamic)
		OS_alarmDynamic_core1[OS_TOTALALARMS_CORE1]
		OS_BSS_SECTION_ATTRIB_POST(.bss.core1.alarmDynamic);
#endif
#include <memmap/Os_mm_var_end.h>

/*!
 * ScheduleTables
*/
#include <memmap/Os_mm_var_begin.h>
#if (OS_NSCHEDULES_CORE1 != 0)
OS_SECTION_PRAGMA(OS_scheduleDynamic_core1, .bss.core1.scheduleDynamic)
os_scheduledynamic_t
		OS_SECTION_ATTRIB_PRE(.bss.core1.scheduleDynamic)
		OS_scheduleDynamic_core1[OS_NSCHEDULES_CORE1]
		OS_BSS_SECTION_ATTRIB_POST(.bss.core1.scheduleDynamic);
#endif
#include <memmap/Os_mm_var_end.h>

/*!
 * HardwareTimers
 *
 * OS_hwtLastValue: An array of values associated timers had the last time they were updated.
*/
#if (OS_NHWTIMERS_CORE1 != 0)
#include <memmap/Os_mm_var_begin.h>
OS_SECTION_PRAGMA(OS_hwtLastValue_core1, .bss.core1.hwtLastValue)
os_timervalue_t
		OS_SECTION_ATTRIB_PRE(.bss.core1.hwtLastValue)
		OS_hwtLastValue_core1[OS_NHWTIMERS_CORE1]
		OS_BSS_SECTION_ATTRIB_POST(.bss.core1.hwtLastValue);
#include <memmap/Os_mm_var_end.h>
#endif


/*!
 * QM-OS specific core-local variables.
*/
#if (OS_KERNEL_TYPE == OS_MICROKERNEL)

#include <memmap/Os_mm_var_begin.h>
OS_SECTION_PRAGMA(OS_panicCode_core1, .bss.core1.panicCode)
volatile os_panic_t
		OS_SECTION_ATTRIB_PRE(.bss.core1.panicCode)
		OS_panicCode_core1
		OS_BSS_SECTION_ATTRIB_POST(.bss.core1.panicCode);
#include <memmap/Os_mm_var_end.h>


#endif /* OS_KERNEL_TYPE == OS_MICROKERNEL */


#endif /* USED */
/* CHECK: PARSE */

/* Editor settings; DO NOT DELETE
 * vi:set ts=4:
*/
