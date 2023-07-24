/* kern-errext-ResumeInterrupts.c - kernel error database for STATUS=EXTENDED
 *
 * This is a generated file - DO NOT EDIT
 *
 * Generated by errdb-to-c.pl on 2021-08-23 15:36
 *
 * (c) 2021 Elektrobit Automotive GmbH
*/

#include <Os_kernel.h>

#if (OS_KERNEL_TYPE != OS_MICROKERNEL)

#include <Os_error.h>

#include <memmap/Os_mm_const_begin.h>
static const os_errorentry_t OS_errtblResumeInterrupts[2] =
{
  {
    OS_E_CALLLEVEL,
    OS_ERROR_WrongContext,
    OS_ACTION_RETURN|OS_ACTION_ERRORHOOK_EB
  },
  {
    OS_E_NOFUNC,
    OS_ERROR_NestingUnderflow,
    OS_ACTION_RETURN|OS_ACTION_ERRORHOOK_EB
  }
};

const os_serviceinfo_t OS_svc_ResumeInterrupts =
{
    OS_errtblResumeInterrupts,
    OS_SID_ResumeInterrupts,
    2
};
#include <memmap/Os_mm_const_end.h>

#endif /* (OS_KERNEL_TYPE != OS_MICROKERNEL) */

