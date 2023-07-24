#ifndef CDD_HEARTBEATDET_H_
#define CDD_HEARTBEATDET_H_


#include "Cdd_HeartbeatDet_Cfg.h"
#include "Mcal_Compiler.h"



#define CDD_HEARTBEATDET_CODE            



#define HEARTBEATDET_MODULE_ID                                               (0x10Cu)
#define HEARTBEATDET_INSTANCE_ID                                             (1u)
#define HEARTBEATDET_INSTANCE_ID_DET                                         (HEARTBEATDET_INSTANCE_ID)

/*Application id*/
#define HEARTBEATDET_API_ID_INIT                                             (0u)
#define HEARTBEATDET_API_ID_MAIN                                             (1u)
/*Error Code id */
#define HEARTBEATDET_ERROR_CODE_UNINIT                                       (0u)

/*
* Mapping of error reporting macro
*/
#if (HEARTBEATDET_DEV_ERROR_DETECT == STD_ON)

#define HEARTBEATDET_DET_REPORTERROR(API_ID, ERROR_CODE) \
    ((void)Det_ReportError((uint16)HEARTBEATDET_MODULE_ID, (uint8)HEARTBEATDET_INSTANCE_ID_DET, (uint8)(API_ID), (uint8)(ERROR_CODE)))
#else

#define HEARTBEATDET_DET_REPORTERROR(API_ID, ERROR_CODE) \
    /*Define an void function*/
#endif


typedef enum
{
    HEARTBEATDET_DET_STATE_UNINIT       = (0U),
    HEARTBEATDET_DET_STATE_INIT         = (1U),
    HEARTBEATDET_DET_STATE_STARTUP      = (2U),
    HEARTBEATDET_DET_STATE_STARTUPERROR = (3U),
    HEARTBEATDET_DET_STATE_RUNNING      = (4U),
    HEARTBEATDET_DET_STATE_RUNNINGERROR = (5U)
} Enum_HeartbeatDetDetState;

typedef enum
{
    HEARTBEATDET_ESM_J3_POWEROFF        = (0u),
    HEARTBEATDET_ESM_J3_POWERON         = (1u),
    HEARTBEATDET_ESM_J3_RESET           = (2u)
}Enum_SocPowerState;

typedef struct
{
    uint16 Frequency;
    uint16 Hightime;
} HeartbeatPwmData_t;


typedef struct 
{
    uint8 InitState;
    Icu_17_TimerIp_DutyCycleType DutyCycleVol;
    HeartbeatPwmData_t PwmData;
    Enum_HeartbeatDetDetState DetState;
}HeartbeatDet_Info_Type;



extern FUNC(void, CDD_HEARTBEATDET_CODE) Cdd_HeartbeatDet_InitFunction(void);
extern FUNC(void, CDD_HEARTBEATDET_CODE) Cdd_HeartbeatDet_MainFunction(void);
extern FUNC(Enum_HeartbeatDetDetState, CDD_HEARTBEATDET_CODE) Cdd_HeartbeatDet_GetDetState(void);



#endif
