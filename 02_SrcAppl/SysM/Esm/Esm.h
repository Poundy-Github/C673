#ifndef _ESM_H_
#define _ESM_H_ //PRQA S 0602,0603



#define ESM_STATE_INIT            (0x00u) //PRQA S 4640
#define ESM_STATE_INACTIVE        (0x01u) //PRQA S 4640
#define ESM_STATE_ACTIVE          (0x02u) //PRQA S 4640
#define ESM_STATE_SHUTDOWN        (0x03u) //PRQA S 4640



#define Esm_START_SEC_CODE
#include <Esm_MemMap.h>
extern FUNC(void, RTE_CODE) Esm_v_Soc_PowerOff(void);
extern FUNC(void, RTE_CODE) Esm_v_Soc_PowerOn(void);
extern FUNC(void, RTE_CODE) Esm_v_Soc_Reset(void);
extern FUNC(void, RTE_CODE) Esm_v_Camera_PowerOff(void);
extern FUNC(void, RTE_CODE) Esm_v_Camera_PowerOn(void);
extern FUNC(void, RTE_CODE) Esm_v_Ecu_SoftReset(void);
extern FUNC(void, RTE_CODE) Esm_v_Ecu_HardReset(void);
extern FUNC(void, RTE_CODE) Esm_v_System_Shutdown(void);
extern FUNC(void, RTE_CODE) Esm_v_Safety_Shutdown(void);
extern FUNC(boolean, RTE_CODE) Esm_GetSocStartupFlag(void);
extern FUNC(boolean, RTE_CODE) Esm_GetSocInitTempHighFlag(void);
#define Esm_STOP_SEC_CODE
#include <Esm_MemMap.h>

#endif /*_ESM_H_*/


