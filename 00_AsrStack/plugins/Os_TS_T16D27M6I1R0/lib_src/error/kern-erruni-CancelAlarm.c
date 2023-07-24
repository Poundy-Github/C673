/* kern-erruni-CancelAlarm.c - kernel error database for STATUS=UNIVERSAL
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
static const os_errorentry_t OS_errtblCancelAlarm[7] =
{
  {
    OS_E_ACCESS,
    OS_ERROR_ApplicationNotAccessible,
    OS_ACTION_RETURN|OS_ACTION_ERRORHOOK
  },
  {
    OS_E_CORE,
    OS_ERROR_CoreIsDown,
    OS_ACTION_RETURN|OS_ACTION_ERRORHOOK
  },
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
    OS_E_ID,
    OS_ERROR_InvalidAlarmId,
    OS_ACTION_QUARANTINE|OS_ACTION_ERRORHOOK
  },
  {
    OS_E_NOFUNC,
    OS_ERROR_AlarmNotInUse,
    OS_ACTION_RETURN|OS_ACTION_ERRORHOOK_APP|OS_ACTION_ERRORHOOK
  },
  {
    OS_E_ACCESS,
    OS_ERROR_Permission,
    OS_ACTION_QUARANTINE|OS_ACTION_ERRORHOOK
  }
};

const os_serviceinfo_t OS_svc_CancelAlarm =
{
    OS_errtblCancelAlarm,
    OS_SID_CancelAlarm,
    7
};
#include <memmap/Os_mm_const_end.h>

#endif /* (OS_KERNEL_TYPE != OS_MICROKERNEL) */
