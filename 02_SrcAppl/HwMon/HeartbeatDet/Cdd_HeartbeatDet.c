/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/

#include "Cdd_HeartbeatDet.h"
#include "Cdd_Pmc.h"


/**********************************************************************************************************************
 *  LOCAL CONSTANT MACROS
 **********************************************************************************************************************/
#define HEARTBEATDET_STATIC                     static
#define HEARTBEATDET_STATIC_INLINE              static inline


#define HEARTBEATDET_UNINIT                     (0u)
#define HEARTBEATDET_INIT                       (1u)
#define HEARTBEATDET_CORE_RUN_0                 (0u)


#define HEARTBEATDET_STARTUPFLAG_END            (0u)
#define HEARTBEATDET_STARTUPFLAG_START          (1u)


/**********************************************************************************************************************
 *  GLOBAL DATA
 **********************************************************************************************************************/


static HeartbeatDet_Info_Type HeartbeatDet_Info = 
{
    HEARTBEATDET_UNINIT,/*init state*/
    {0u,0u},/*period time and active time cnt*/
    {0u,0u},/*Frequency and Hightime*/
    HEARTBEATDET_DET_STATE_UNINIT/*Det state of Heartbeat */
};

 
/**********************************************************************************************************************
*  LOCAL FUNCTION PROTOTYPES
**********************************************************************************************************************/
HEARTBEATDET_STATIC FUNC(void, CDD_HEARTBEATDET_CODE) Cdd_HeartbeatDet_InitVariable(void);
HEARTBEATDET_STATIC FUNC(HeartbeatPwmData_t, CDD_HEARTBEATDET_CODE) Cdd_HeartbeatDet_CalPwmData(Icu_17_TimerIp_DutyCycleType  DutyCycleVol);
HEARTBEATDET_STATIC FUNC(uint8, CDD_HEARTBEATDET_CODE) Cdd_HeartbeatDet_GetPwmState(HeartbeatPwmData_t HeartbeatPwmData);
HEARTBEATDET_STATIC FUNC(uint8, CDD_HEARTBEATDET_CODE) Cdd_HeartbeatDet_GetSinalState(void);
HEARTBEATDET_STATIC FUNC(Enum_HeartbeatDetDetState, CDD_HEARTBEATDET_CODE) Cdd_HeartbeatDet_JudgeDetState(uint8 Flag);
HEARTBEATDET_STATIC FUNC(Enum_SocPowerState, CDD_HEARTBEATDET_CODE) Cdd_HeartbeatDet_GetSocpowerState(void);






HEARTBEATDET_STATIC FUNC(void, CDD_HEARTBEATDET_CODE) Cdd_HeartbeatDet_InitVariable(void)
{
    HeartbeatDet_Info.InitState = HEARTBEATDET_UNINIT;
    //HeartbeatDet_Info.DutyCycleVol = {0u,0u};
    //HeartbeatDet_Info.PwmData = {0u,0u};
    HeartbeatDet_Info.DetState = HEARTBEATDET_DET_STATE_UNINIT;
}

HEARTBEATDET_STATIC FUNC(HeartbeatPwmData_t, CDD_HEARTBEATDET_CODE) Cdd_HeartbeatDet_CalPwmData(Icu_17_TimerIp_DutyCycleType  DutyCycleVol)
{
    HeartbeatPwmData_t HeartbeatPwmData={0u,0u};

    if((DutyCycleVol.PeriodTime == 0u) || (DutyCycleVol.ActiveTime == 0u) )
    {
        HeartbeatPwmData.Frequency = 0u;
        HeartbeatPwmData.Hightime = 0u; 
    }
    else
    {
        HeartbeatPwmData.Frequency = (uint16)(HEARTBEATDET_TIM_CLOCK_FREQUENCY * 1000000u / DutyCycleVol.PeriodTime) ;
        HeartbeatPwmData.Hightime = (uint16)(DutyCycleVol.ActiveTime / HEARTBEATDET_TIM_CLOCK_FREQUENCY / 1000u); 
    }

    return HeartbeatPwmData;
}

HEARTBEATDET_STATIC FUNC(uint8, CDD_HEARTBEATDET_CODE) Cdd_HeartbeatDet_GetPwmState(HeartbeatPwmData_t HeartbeatPwmData)
{
    uint8 Result  = E_NOT_OK;
    uint8 Result1 = E_NOT_OK;
    uint8 Result2 = E_NOT_OK;


    if((HeartbeatPwmData.Frequency > HEARTBEATDET_FREQUENCY_MAX) || \
        HeartbeatPwmData.Frequency < HEARTBEATDET_FREQUENCY_MIN )
    {
        Result1 = E_NOT_OK;
    }
    else
    {
        Result1 = E_OK;
    }

    if((HeartbeatPwmData.Hightime > HEARTBEATDET_HIGHTIME_MAX) || \
        HeartbeatPwmData.Hightime < HEARTBEATDET_HIGHTIME_MIN )
    {
        Result2 = E_NOT_OK;
    }
    else
    {
        Result2 = E_OK;
    }

    Result = ((Result1 == E_OK) && (Result2 == E_OK))?E_OK:E_NOT_OK;

    return Result;
}



HEARTBEATDET_STATIC FUNC(uint8, CDD_HEARTBEATDET_CODE) Cdd_HeartbeatDet_GetSinalState(void)
{
    static uint16 NoSingleCnt = 0u;
    uint16 NoSingleContinueCntMax = HEARTBEATDET_NO_SINGLE_CONTINUE_MAX/HEARTBEATDET_OPERATING_CYCLE;
    uint8 Result=0u;

    /*Get information about duty cycle*/
    Icu_17_TimerIp_GetDutyCycleValues( HeartbeatDet_Channel, &(HeartbeatDet_Info.DutyCycleVol) );
    /*Calculate frequency and high time*/
    HeartbeatDet_Info.PwmData = Cdd_HeartbeatDet_CalPwmData(HeartbeatDet_Info.DutyCycleVol);
    /*Determine whether the PWM wave is valid*/
    if( E_OK != Cdd_HeartbeatDet_GetPwmState(HeartbeatDet_Info.PwmData) )
    {
        NoSingleCnt++;
        if(NoSingleCnt > NoSingleContinueCntMax)
        {
            Result = E_NOT_OK;
        }
        else
        {
            Result = E_OK;
        }
    }
    else
    {
        /*get valid value to clear state*/
        NoSingleCnt = 0u;
        Result = E_OK;
    }
    return Result;
}





HEARTBEATDET_STATIC FUNC(Enum_HeartbeatDetDetState, CDD_HEARTBEATDET_CODE) Cdd_HeartbeatDet_JudgeDetState(uint8 Flag)
{
    Enum_HeartbeatDetDetState DetState = HEARTBEATDET_DET_STATE_UNINIT;
    uint16 StartupCntStart = HEARTBEATDET_STARTUPPHASE_START/HEARTBEATDET_OPERATING_CYCLE;
    uint16 StartupCntEnd   = HEARTBEATDET_STARTUPPHASE_END/HEARTBEATDET_OPERATING_CYCLE;
    uint8  SignalResult = E_NOT_OK;
    static uint16 TimeCnt = 0u;


    SignalResult = Cdd_HeartbeatDet_GetSinalState();
    if( Flag == HEARTBEATDET_STARTUPFLAG_START )
    {
        TimeCnt++;

        if(TimeCnt < StartupCntStart)
        {
            DetState = HEARTBEATDET_DET_STATE_INIT;
        }
        else if(TimeCnt > StartupCntEnd)
        {
            TimeCnt = StartupCntEnd;
            if(E_OK == SignalResult )
            {
                DetState = HEARTBEATDET_DET_STATE_RUNNING;
            }
            else
            {
                DetState = HEARTBEATDET_DET_STATE_RUNNINGERROR;
            }
        }
        else
        {
             if(E_OK == SignalResult )
             {
                DetState = HEARTBEATDET_DET_STATE_STARTUP;
             }
             else
             {
                DetState = HEARTBEATDET_DET_STATE_STARTUPERROR;
             }
        }
    }
    else 
    {
        TimeCnt  = 0u;
        DetState = HEARTBEATDET_DET_STATE_INIT;
    }


    return DetState;
}

HEARTBEATDET_STATIC FUNC(Enum_SocPowerState, CDD_HEARTBEATDET_CODE) Cdd_HeartbeatDet_GetSocpowerState(void)
{
	Enum_SocPowerState Socmode;

	if(E_OK == Cdd_Pmc_ReadSocState())
	{
        Socmode = HEARTBEATDET_ESM_J3_POWERON;
	}
	else 
	{
        Socmode = HEARTBEATDET_ESM_J3_POWEROFF;
	}

	return Socmode;
}




/**********************************************************************************************************************
* PUBLIC FUNCTION DEFINITIONS
**********************************************************************************************************************/


FUNC(void, RTE_CODE) HeartbeatDet_InitFunction (void)
{

} /* FUNC(void, RTE_CODE) HeartbeatDet_InitFunction (void) */

FUNC(void, RTE_CODE) HeartbeatDet_MainFunction (void)
{

} /* FUNC(void, RTE_CODE) HeartbeatDet_MainFunction (void) */


FUNC(void, CDD_HEARTBEATDET_CODE) Cdd_HeartbeatDet_InitFunction(void)
{
    // Ifx_GTM_TIM_CH *TimChannelRegPtr = NULL_PTR;
    uint8 CoreId = 0U; 
    
    /*get core id*/
    CoreId = ( uint8 )Mcal_GetCpuIndex();
    if(CoreId == HEARTBEATDET_CORE_RUN_0)
    {
        /*Initialize ICU*/
        Cdd_HeartbeatDet_InitVariable();
        Icu_17_TimerIp_StartSignalMeasurement( HeartbeatDet_Channel );
        // /*Get the address of the relevant register*/
        // TimChannelRegPtr = GTM_TIM_CH_POINTER( 3, 4 ); /* PRQA S 303,316 */
        // /*use the Pulse-Notify mode*/
        // TimChannelRegPtr->IRQ.MODE.B.IRQ_MODE = 2U;/* PRQA S 2850 */
        // TimChannelRegPtr->IRQ.EN.B.CNTOFL_IRQ_EN = 0U;/* PRQA S 2850 */
        // /*we should enable newval IRQ*/
        // TimChannelRegPtr->IRQ.EN.B.NEWVAL_IRQ_EN = 1U;/* PRQA S 2850 */
        // TimChannelRegPtr->IRQ.EN.B.GPROFL_IRQ_EN = 1U;/* PRQA S 2850 */
        HeartbeatDet_Info.InitState = HEARTBEATDET_INIT;
    
    }
    else
    {
        HEARTBEATDET_DET_REPORTERROR( HEARTBEATDET_API_ID_INIT, HEARTBEATDET_ERROR_CODE_UNINIT );
    }
    
    
}
 
 
FUNC(void, CDD_HEARTBEATDET_CODE) Cdd_HeartbeatDet_MainFunction(void)
{
    static Enum_SocPowerState CurrState   = HEARTBEATDET_ESM_J3_POWEROFF;
    static Enum_SocPowerState LastState   = HEARTBEATDET_ESM_J3_POWEROFF;
    static uint8 StartupFlag = HEARTBEATDET_STARTUPFLAG_END;

    if(HeartbeatDet_Info.InitState == HEARTBEATDET_INIT)
    {
        LastState = CurrState;
        CurrState = Cdd_HeartbeatDet_GetSocpowerState();

        if( (LastState != HEARTBEATDET_ESM_J3_POWERON)   &&  \
            (CurrState == HEARTBEATDET_ESM_J3_POWERON) )
        {
            StartupFlag = HEARTBEATDET_STARTUPFLAG_START;
        }
        else if((CurrState != HEARTBEATDET_ESM_J3_POWERON))
        {
            StartupFlag = HEARTBEATDET_STARTUPFLAG_END;
        }
        else
        {
            /*Keep Last Value*/
        }

        HeartbeatDet_Info.DetState = Cdd_HeartbeatDet_JudgeDetState(StartupFlag);

    }
    else
    {
        HEARTBEATDET_DET_REPORTERROR( HEARTBEATDET_API_ID_MAIN, HEARTBEATDET_ERROR_CODE_UNINIT );
    }

}



FUNC(Enum_HeartbeatDetDetState, CDD_HEARTBEATDET_CODE) Cdd_HeartbeatDet_GetDetState(void)
{
    return HeartbeatDet_Info.DetState;
}







