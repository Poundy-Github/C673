/* kern-erruni-GetTaskId.c - kernel error database for STATUS=UNIVERSAL
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
static const os_errorentry_t OS_errtblGetTaskId[3] =
{
  {
    OS_E_CALLLEVEL,
    OS_ERROR_WrongContext,
    OS_ACTION_QUARANTINE|OS_ACTION_ERRORHOOK
  },
  {
    OS_E_INTDISABLE,
    OS_ERROR_InterruptDisabled,
    OS_ACTION_QUARANTINE|OS_ACTION_ERRORHOOK
  },
  {
    OS_E_ADDRESS,
    OS_ERROR_WriteProtect,
    OS_ACTION_QUARANTINE|OS_ACTION_ERRORHOOK
  }
};

const os_serviceinfo_t OS_svc_GetTaskId =
{
    OS_errtblGetTaskId,
    OS_SID_GetTaskId,
    3
};
#include <memmap/Os_mm_const_end.h>

#endif /* (OS_KERNEL_TYPE != OS_MICROKERNEL) */

