/* kern-errext-TrapHandler.c - kernel error database for STATUS=EXTENDED
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
static const os_errorentry_t OS_errtblTrapHandler[7] =
{
  {
    OS_E_INTERNAL,
    OS_ERROR_UnknownInterrupt,
    OS_ACTION_RETURN|OS_ACTION_ERRORHOOK
  },
  {
    OS_E_TIMEPROT,
    OS_ERROR_TaskTimeBudgetExceeded,
    OS_ACTION_QUARANTINE|OS_ACTION_PROTECTIONHOOK
  },
  {
    OS_E_LOCKPROT,
    OS_ERROR_TaskResLockTimeExceeded,
    OS_ACTION_QUARANTINE|OS_ACTION_PROTECTIONHOOK
  },
  {
    OS_E_LOCKPROT,
    OS_ERROR_TaskIntLockTimeExceeded,
    OS_ACTION_QUARANTINE|OS_ACTION_PROTECTIONHOOK
  },
  {
    OS_E_TIMEPROT,
    OS_ERROR_IsrTimeBudgetExceeded,
    OS_ACTION_QUARANTINE|OS_ACTION_PROTECTIONHOOK
  },
  {
    OS_E_LOCKPROT,
    OS_ERROR_IsrResLockTimeExceeded,
    OS_ACTION_QUARANTINE|OS_ACTION_PROTECTIONHOOK
  },
  {
    OS_E_LOCKPROT,
    OS_ERROR_IsrIntLockTimeExceeded,
    OS_ACTION_QUARANTINE|OS_ACTION_PROTECTIONHOOK
  }
};

const os_serviceinfo_t OS_svc_TrapHandler =
{
    OS_errtblTrapHandler,
    OS_SID_TrapHandler,
    7
};
#include <memmap/Os_mm_const_end.h>

#endif /* (OS_KERNEL_TYPE != OS_MICROKERNEL) */

