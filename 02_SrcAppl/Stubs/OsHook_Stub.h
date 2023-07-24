
#ifndef _OS_HOOK_STUB_H_
#define _OS_HOOK_STUB_H_

#include "common_platform.h"
#include "Os_user.h"
#include "Os_salsa.h"
#include "TSAutosar.h"
#include "Os.h"
#include "Os_api.h"

 typedef struct
 {
	 StatusType ErrorId;
	 CoreIdType CoreId;
	 os_taskid_t taskId;
 }s_OSErrorType_t;
 
 typedef struct 
 {
	 StatusType ErrorId;
	 CoreIdType CoreId;
	 os_taskid_t taskId;
	 uint32 *curStackStart;
	 uint32 *curStackEnd;
	 os_stackinfo_t StackInfo;
 }s_OSProtectionType_t;




#endif /*_OS_HOOK_STUB_H_*/