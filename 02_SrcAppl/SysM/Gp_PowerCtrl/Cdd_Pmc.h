/**
 * \file Cdd_pmc.h
 *
 * \brief  Power mode control
 *
 * \version
 * --------------------------------------------------------------------------------------------
 * Version	| 		Date		|		Author			| 	Comments
 * V0.0.1		2023.01.22			Jinlong Zhang			Init version
 *
 *
 */
#ifndef __CDD_PMC_H__
#define __CDD_PMC_H__ //PRQA S 0602,0603
/*==================[inclusions]============================================*/
#include "Std_Types.h"


/*==================[macros definitions]====================================*/
#define TIMER_MS               (uint8)0u
#define TIMER_US               (uint8)1u
#define MAX_STM_VALUE          (uint64)0xFFFFFFFFu

#define SOCRESET_CNT           (100000)

#define TIMER_2MS              (uint32)2u

#define PMIC_WDGCNT            ((uint8)6)

#define DIETEMP_FACTOR         ((float)7.505)

#define DIETEMP_OFFSET         ((float)273.15)

typedef  float32 VoltResultType_t;

typedef  uint8 VoltErrorType_t;

typedef  uint8 ShortErrorType_t;

typedef  uint8 PmicDioLevelType_t;

/*==================[external constants declarations]========================*/
typedef struct 
{
    PmicDioLevelType_t Fs84_PG;
    PmicDioLevelType_t Fs84_FS0B;
    PmicDioLevelType_t Pf82_PG;
    PmicDioLevelType_t Pf82_EWARN;
    PmicDioLevelType_t Pf82_FS0B;
    PmicDioLevelType_t Pf82_INTB;
    PmicDioLevelType_t Pf82_RSTOut;
    PmicDioLevelType_t Pf50_PG;
    PmicDioLevelType_t Pf50_PG1;
    PmicDioLevelType_t Pf50_PG3;
    PmicDioLevelType_t Pf50_RSTOut;
}s_Pmc_PmicIOState_t;

typedef struct
{
    VoltErrorType_t VDDOverFlag;
    VoltErrorType_t VDDP3OverFlag;
    VoltErrorType_t VEXTOverFlag;
    VoltErrorType_t VDDUnderFlag;
    VoltErrorType_t VDDP3UnderFlag;
    VoltErrorType_t VEXTUnderFlag;
    VoltErrorType_t VDDPDOverFlag;
    VoltErrorType_t VEVRSBOverFlag;
    VoltErrorType_t VDDMOverFlag;
    VoltErrorType_t VDDPDUnderFlag;
    VoltErrorType_t VEVRSBUnderFlag;
    VoltErrorType_t VDDMUnderFlag;
}s_Pmc_VoltEventFlag_t;

typedef struct
{
    ShortErrorType_t VDDShortToGround;
    ShortErrorType_t VDDShortToSupply;
    ShortErrorType_t VDDP3ShortToGround;
    ShortErrorType_t VDDP3ShortToSupply;
}s_Pmc_VoltShortError_t;

typedef struct
{
    s_Pmc_VoltEventFlag_t EventFlag;
    s_Pmc_VoltShortError_t ShortDetect;    
}s_Pmc_VoltErrorStatus_t;

typedef struct
{
    VoltResultType_t ADCVDD;
    VoltResultType_t ADCVDDP3;
    VoltResultType_t ADCVEXT;
    VoltResultType_t VDDADC;
    VoltResultType_t VDDP3ADC;
    VoltResultType_t VEXTADC;
    VoltResultType_t VDDPDADC;
    VoltResultType_t VEVRSBADC;
    VoltResultType_t VDDMADC;
}s_Pmc_VoltConversionResult_t;
/*==================[external data declarations]=============================*/

    
/*==================[external function declarations]=========================*/
extern uint8 Cdd_Pmc_ReadSocState(void);
extern uint8 Cdd_Pmc_ReadSocShutDownState(void);
extern void Cdd_Pmc_SocHardReset(void);
extern void Cdd_Pmc_SocPowerOff(void);
extern void Cdd_Pmc_SocPowerOn(void);
extern void Cdd_Pmc_CamPowerOn(void);
extern void Cdd_Pmc_CamPowerOff(void);
extern void Cdd_Pmc_McuSoftReset(void);
extern void Cdd_Pmc_McuHardReset(void);
extern void Cdd_Pmc_PmicDisable(void);
extern void Cdd_Pmc_CanTrvGotoSleep(void);
extern void Cdd_Pmc_Init(void);
extern float Cdd_Pmc_GetDieTemperature(void);
extern uint8 Cdd_Pmc_GetDieTempOverFlow(void);
extern void Cdd_Pmc_ClrDieTempOverFlow(void);
extern uint8 Cdd_Pmc_GetDieTempUnderFlow(void);
extern void Cdd_Pmc_ClrDieTempUnderFlow(void);
extern uint8 Cdd_Pmc_SetDieTempLmit(const float LowerLimit, const float UpperLimit);
extern float Cdd_Pmc_GetCoreDieTemperature(void);
extern s_Pmc_VoltConversionResult_t Cdd_Pmc_GetPmsVoltageResult(void);
extern s_Pmc_VoltErrorStatus_t Cdd_Pmc_GetPmsVoltageErrorStatus(void);
extern s_Pmc_PmicIOState_t Cdd_Pmc_GetPmicIOState(void);
extern void Timer_DelayMs(const uint32 ReqTimeMs);

#endif
