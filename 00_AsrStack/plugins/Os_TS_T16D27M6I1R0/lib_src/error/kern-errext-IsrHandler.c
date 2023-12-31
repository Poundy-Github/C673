/* kern-errext-IsrHandler.c - kernel error database for STATUS=EXTENDED
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
static const os_errorentry_t OS_errtblIsrHandler[6] =
{
  {
    OS_E_STACKPROT,
    OS_ERROR_InsufficientStack,
    OS_ACTION_SHUTDOWN|OS_ACTION_PROTECTIONHOOK
  },
  {
    OS_E_RATEPROT,
    OS_ERROR_RateLimitExceeded,
    OS_ACTION_RETURN|OS_ACTION_PROTECTIONHOOK
  },
  {
    OS_E_ISRRETURNSPINLOCKED,
    OS_ERROR_HoldsLock,
    OS_ACTION_RETURN|OS_ACTION_ERRORHOOK_APP|OS_ACTION_ERRORHOOK
  },
  {
    OS_E_ISRRETURNRESLOCKED,
    OS_ERROR_HoldsResource,
    OS_ACTION_RETURN|OS_ACTION_ERRORHOOK_APP|OS_ACTION_ERRORHOOK
  },
  {
    OS_E_ISRRETURNINTLOCKED,
    OS_ERROR_InterruptDisabled,
    OS_ACTION_RETURN|OS_ACTION_ERRORHOOK_APP|OS_ACTION_ERRORHOOK
  },
  {
    OS_E_STACKPROT,
    OS_ERROR_KernelStackOverflow,
    OS_ACTION_SHUTDOWN|OS_ACTION_PROTECTIONHOOK
  }
};

const os_serviceinfo_t OS_svc_IsrHandler =
{
    OS_errtblIsrHandler,
    OS_SID_IsrHandler,
    6
};
#include <memmap/Os_mm_const_end.h>

#endif /* (OS_KERNEL_TYPE != OS_MICROKERNEL) */

