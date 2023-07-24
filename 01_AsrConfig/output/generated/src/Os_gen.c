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

#include <Os_config.h>
#include <Os_kernel.h>
#include <Os_tool.h>

#if OS_GENERATION_ID_OS_H!=0xe00962e5UL
#error "Build-Ids of src\Os_gen.c and include\Os_user.h did not match! Hint: A wrong include\Os_user.h was most probably included."
#endif
#if OS_GENERATION_ID_OS_CONF_H!=0xe00962e5UL
#if OS_GENERATION_ID_OS_KCONF_H!=0xe00962e5UL
#error "Build-Ids of src\Os_gen.c and include\Os_config.h did not match! Hint: A wrong include\Os_config.h was most probably included."
#error "Build-Ids of src\Os_gen.c and include\Os_kconfig.h did not match! Hint: A wrong include\Os_kconfig.h was most probably included."
#endif
#endif

const os_uint32_t OS_os_GenBuildId = 0xe00962e5UL;

/*===================================================================
 * Counters
 *==================================================================*/

void OS_CounterIsr_HwCounter_C0(void)
{
  OS_HwCounterUpdate(&OS_counterTableBase[HwCounter_C0]);
}
void OS_CounterIsr_HwCounter_C1(void)
{
  OS_HwCounterUpdate(&OS_counterTableBase[HwCounter_C1]);
}
void OS_CounterIsr_HwCounter_C2(void)
{
  OS_HwCounterUpdate(&OS_counterTableBase[HwCounter_C2]);
}
void OS_CounterIsr_HwCounter_C3(void)
{
  OS_HwCounterUpdate(&OS_counterTableBase[HwCounter_C3]);
}

/*===================================================================
 * Stacks
 *==================================================================*/

#if OS_KERNEL_TYPE != OS_MICROKERNEL
OS_GEN_STACK(OS_taskStack0_slot0, .bss.core0.os_taskstack0_slot0, 1026, 8);
#endif
#if OS_KERNEL_TYPE != OS_MICROKERNEL
OS_GEN_STACK(OS_taskStack0_slot1, .bss.core0.os_taskstack0_slot1, 1026, 8);
#endif
#if OS_KERNEL_TYPE != OS_MICROKERNEL
OS_GEN_STACK(OS_taskStack0_slot2, .bss.core0.os_taskstack0_slot2, 258, 8);
#endif
#if OS_KERNEL_TYPE != OS_MICROKERNEL
OS_GEN_STACK(OS_taskStack0_slot3, .bss.core0.os_taskstack0_slot3, 258, 8);
#endif
#if OS_KERNEL_TYPE != OS_MICROKERNEL
OS_GEN_STACK(OS_taskStack0_slot4, .bss.core0.os_taskstack0_slot4, 258, 8);
#endif
#if OS_KERNEL_TYPE != OS_MICROKERNEL
OS_GEN_STACK(OS_taskStack0_slot5, .bss.core0.os_taskstack0_slot5, 130, 8);
#endif
#if OS_KERNEL_TYPE != OS_MICROKERNEL
OS_GEN_STACK(OS_taskStack0_slot6, .bss.core0.os_taskstack0_slot6, 130, 8);
#endif
#if OS_KERNEL_TYPE != OS_MICROKERNEL
OS_GEN_STACK(OS_taskStack0_slot7, .bss.core0.os_taskstack0_slot7, 130, 8);
#endif
#if OS_KERNEL_TYPE != OS_MICROKERNEL
OS_GEN_STACK(OS_taskStack0_slot8, .bss.core0.os_taskstack0_slot8, 130, 8);
#endif
#if OS_KERNEL_TYPE != OS_MICROKERNEL
OS_GEN_STACK(OS_taskStack0_slot9, .bss.core0.os_taskstack0_slot9, 130, 8);
#endif
#if OS_KERNEL_TYPE != OS_MICROKERNEL
OS_GEN_STACK(OS_taskStack0_slot10, .bss.core0.os_taskstack0_slot10, 130, 8);
#endif
#if OS_KERNEL_TYPE != OS_MICROKERNEL
OS_GEN_STACK(OS_taskStack1_slot0, .bss.core1.os_taskstack1_slot0, 1282, 8);
#endif
#if OS_KERNEL_TYPE != OS_MICROKERNEL
OS_GEN_STACK(OS_taskStack1_slot1, .bss.core1.os_taskstack1_slot1, 1282, 8);
#endif
#if OS_KERNEL_TYPE != OS_MICROKERNEL
OS_GEN_STACK(OS_taskStack1_slot2, .bss.core1.os_taskstack1_slot2, 1282, 8);
#endif
#if OS_KERNEL_TYPE != OS_MICROKERNEL
OS_GEN_STACK(OS_taskStack1_slot3, .bss.core1.os_taskstack1_slot3, 130, 8);
#endif
#if OS_KERNEL_TYPE != OS_MICROKERNEL
OS_GEN_STACK(OS_taskStack1_slot4, .bss.core1.os_taskstack1_slot4, 130, 8);
#endif
#if OS_KERNEL_TYPE != OS_MICROKERNEL
OS_GEN_STACK(OS_taskStack1_slot5, .bss.core1.os_taskstack1_slot5, 130, 8);
#endif
#if OS_KERNEL_TYPE != OS_MICROKERNEL
OS_GEN_STACK(OS_taskStack1_slot6, .bss.core1.os_taskstack1_slot6, 130, 8);
#endif
#if OS_KERNEL_TYPE != OS_MICROKERNEL
OS_GEN_STACK(OS_taskStack2_slot0, .bss.core2.os_taskstack2_slot0, 258, 8);
#endif
#if OS_KERNEL_TYPE != OS_MICROKERNEL
OS_GEN_STACK(OS_taskStack2_slot1, .bss.core2.os_taskstack2_slot1, 130, 8);
#endif
#if OS_KERNEL_TYPE != OS_MICROKERNEL
OS_GEN_STACK(OS_taskStack2_slot2, .bss.core2.os_taskstack2_slot2, 130, 8);
#endif
#if OS_KERNEL_TYPE != OS_MICROKERNEL
OS_GEN_STACK(OS_taskStack2_slot3, .bss.core2.os_taskstack2_slot3, 130, 8);
#endif
#if OS_KERNEL_TYPE != OS_MICROKERNEL
OS_GEN_STACK(OS_taskStack2_slot4, .bss.core2.os_taskstack2_slot4, 130, 8);
#endif
#if OS_KERNEL_TYPE != OS_MICROKERNEL
OS_GEN_STACK(OS_taskStack3_slot0, .bss.core3.os_taskstack3_slot0, 1794, 8);
#endif
#if OS_KERNEL_TYPE != OS_MICROKERNEL
OS_GEN_STACK(OS_taskStack3_slot1, .bss.core3.os_taskstack3_slot1, 1794, 8);
#endif
#if OS_KERNEL_TYPE != OS_MICROKERNEL
OS_GEN_STACK(OS_taskStack3_slot2, .bss.core3.os_taskstack3_slot2, 130, 8);
#endif
#if OS_KERNEL_TYPE != OS_MICROKERNEL
OS_GEN_STACK(OS_taskStack3_slot3, .bss.core3.os_taskstack3_slot3, 130, 8);
#endif
#if OS_KERNEL_TYPE != OS_MICROKERNEL
OS_GEN_STACK(OS_taskStack3_slot4, .bss.core3.os_taskstack3_slot4, 130, 8);
#endif
#if OS_KERNEL_TYPE != OS_MICROKERNEL
OS_GEN_STACK(OS_taskStack3_slot5, .bss.core3.os_taskstack3_slot5, 130, 8);
#endif
#if OS_KERNEL_TYPE != OS_MICROKERNEL
OS_GEN_STACK(OS_taskStack3_slot6, .bss.core3.os_taskstack3_slot6, 130, 8);
#endif
#if OS_KERNEL_TYPE != OS_MICROKERNEL
OS_GEN_STACK(OS_kernStack0, .bss.core0.os_kernstack0, 7984, 8);
#endif
#if OS_KERNEL_TYPE != OS_MICROKERNEL
OS_GEN_STACK(OS_kernStack1, .bss.core1.os_kernstack1, 276, 8);
#endif
#if OS_KERNEL_TYPE != OS_MICROKERNEL
OS_GEN_STACK(OS_kernStack2, .bss.core2.os_kernstack2, 276, 8);
#endif
#if OS_KERNEL_TYPE != OS_MICROKERNEL
OS_GEN_STACK(OS_kernStack3, .bss.core3.os_kernstack3, 276, 8);
#endif

