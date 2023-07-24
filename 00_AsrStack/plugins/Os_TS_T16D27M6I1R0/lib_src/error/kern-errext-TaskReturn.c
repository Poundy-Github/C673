/* kern-errext-TaskReturn.c - kernel error database for STATUS=EXTENDED
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
static const os_errorentry_t OS_errtblTaskReturn[1] =
{
  {
    OS_E_TASKRETURN,
    OS_ERROR_ReturnFromTask,
    OS_ACTION_KILL|OS_ACTION_ERRORHOOK
  }
};

const os_serviceinfo_t OS_svc_TaskReturn =
{
    OS_errtblTaskReturn,
    OS_SID_TaskReturn,
    1
};
#include <memmap/Os_mm_const_end.h>

#endif /* (OS_KERNEL_TYPE != OS_MICROKERNEL) */

