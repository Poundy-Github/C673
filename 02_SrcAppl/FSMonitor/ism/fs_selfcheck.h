#ifndef __FS_SELFCHECK_H__
#define __FS_SELFCHECK_H__

extern void FSSelfCheck_MainFunction(void);
extern void FSSelfCheck_Finish(void);
#if 0
extern void FsCom_DetCallback(uint16 ModuleId,uint8 InstanceId,uint8 ApiId,uint8 ErrorId);
#endif

#endif /*__FS_SELFCHECK_H__*/