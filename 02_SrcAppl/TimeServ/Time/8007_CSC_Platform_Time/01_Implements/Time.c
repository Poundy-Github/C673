/**
 * \file Time.c
 *
 * \brief
 *
 * \version refer the Time.h.
 *
 */


/*==================[inclusions]============================================*/
#include "Time.h"
#include "IfxStm_reg.h"
#if (TIME_STBM_RTE_USAGE == STD_ON)
#include "Rte_Time.h"
#endif
/*==================[external data]=========================================*/


/*==================[internal data]=========================================*/
#define TIME_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "Time_MemMap.h"
#if (TIME_TIMESTAMP_SOURCE_MODE == TIME_TIMESTAMP_SOURCE_MODE_STBM)
StbM_TimeStampType  Time_StbmTimeStamp;
StbM_UserDataType   Time_StbmUserData;
#endif
#define TIME_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "Time_MemMap.h"

/*==================[internal function declarations]========================*/

/*==================[external function definitions]=========================*/
#define TIME_START_SEC_CODE
#include "Time_MemMap.h"
/**
 * \functions Time_InitFunction
 *
 * \brief
 *
 * \parameters-in none
 *
 * \parameters-out none
 *
 * \return none
 *
 * \comments When the Ecu is TimeSync master via StbM,Shall be Called this Function.
 *           And the function shall called after StbM_Init
 *          
 *           The StbM and Time shall be location the same core.
 *
 */
void Time_InitFunction(void)
{
#if (TIME_TIMESYNC_MASTER == STD_ON)
	SchM_Enter_StbM_SCHM_STBM_EXCLUSIVE_AREA_0();
	Time_StbmTimeStamp.nanoseconds = TIME_TIMESYNC_MASTER_INIT_NS ;
    Time_StbmTimeStamp.seconds = TIME_TIMESYNC_MASTER_INIT_SEC ;
	(void)StbM_SetGlobalTime( TIME_STBM_TIMEBASE_ID,&Time_StbmTimeStamp, &Time_StbmUserData);
	SchM_Exit_StbM_SCHM_STBM_EXCLUSIVE_AREA_0();
#endif
}


/**
 * \functions Time_GetTimeStampNs
 *
 * \brief
 *
 * \parameters-in none
 *
 * \parameters-out ts_ns,time stamp,the unit is ns
 *
 * \return none
 *
 * \comments 
 *
 */
uint8 Time_GetTimeStampNs(uint64 *ts_ns)
{
	uint8 ret = 0x01;

	/*TODO : Check the parameters is NULL*/
	if(NULL_PTR == ts_ns)
	{
		ret = 0x01;
	}
	else
	{
#if (TIME_TIMESTAMP_SOURCE_MODE == TIME_TIMESTAMP_SOURCE_MODE_STBM)
#if (TIME_STBM_RTE_USAGE == STD_ON)
        (void)Time_StbMGlobalTime_Slave_GetCurrentTime(&Time_StbmTimeStamp, &Time_StbmUserData);
#else
        SchM_Enter_StbM_SCHM_STBM_EXCLUSIVE_AREA_0();
        (void)StbM_GetCurrentTime(TIME_STBM_TIMEBASE_ID, &Time_StbmTimeStamp, &Time_StbmUserData);
        SchM_Exit_StbM_SCHM_STBM_EXCLUSIVE_AREA_0();
#endif
        //*ts_ns = (uint64)Time_StbmTimeStamp.nanoseconds/1000000 + (uint64)Time_StbmTimeStamp.seconds*1000000000/* + (uint64)Time_StbmTimeStamp.secondsHi*4294967295*1000000000*/;
        *ts_ns = (uint64)Time_StbmTimeStamp.seconds * 1000000000 + (uint64)Time_StbmTimeStamp.nanoseconds;
#elif (TIME_TIMESTAMP_SOURCE_MODE == TIME_TIMESTAMP_SOURCE_MODE_STM0)
        *ts_ns = (uint64)(((STM0_TIM0.U)/(TIME_STM0_CLK_FREQ * 1.0)) * 1000000000);
#endif
        ret = 0x00;
	}
	return ret;
}

/**
 * \functions Time_GetTimeStampMs
 *
 * \brief
 *
 * \parameters-in none
 *
 * \parameters-out ts_ms,time stamp,the unit is ms
 *
 * \return none
 *
 * \comments
 *
 */
uint8 Time_GetTimeStampMs(uint64 *ts_ms)
{
	uint8 ret = 0x01;

	/*TODO : Check the parameters is NULL*/
	if(NULL_PTR == ts_ms)
	{
		ret = 0x01;
	}
	else
	{
#if (TIME_TIMESTAMP_SOURCE_MODE == TIME_TIMESTAMP_SOURCE_MODE_STBM)
#if (TIME_STBM_RTE_USAGE == STD_ON)
        (void)Time_StbMGlobalTime_Slave_GetCurrentTime(&Time_StbmTimeStamp, &Time_StbmUserData);
#else
        SchM_Enter_StbM_SCHM_STBM_EXCLUSIVE_AREA_0();
        (void)StbM_GetCurrentTime(TIME_STBM_TIMEBASE_ID, &Time_StbmTimeStamp, &Time_StbmUserData);
        SchM_Exit_StbM_SCHM_STBM_EXCLUSIVE_AREA_0();        
#endif /*TIME_STBM_RTE_USAGE == STD_ON*/
    *ts_ms = (uint64)Time_StbmTimeStamp.nanoseconds/1000000 + (uint64)Time_StbmTimeStamp.seconds*1000/* + (uint64)Time_StbmTimeStamp.secondsHi*4294967295*1000*/;
#elif (TIME_TIMESTAMP_SOURCE_MODE == TIME_TIMESTAMP_SOURCE_MODE_STM0)
        *ts_ms = (uint64)(((STM0_TIM0.U)/(TIME_STM0_CLK_FREQ * 1.0)) * 1000);
#endif
        ret = 0x00;
	}
	return ret;
}

/**
 * \functions Time_GetTimeStampSec
 *
 * \brief
 *
 * \parameters-in none
 *
 * \parameters-out ts_ms,time stamp,the unit is sec
 *
 * \return none
 *
 * \comments
 *
 */
uint8 Time_GetTimeStampSec(uint64 *ts_sec)
{
	uint8 ret = 0x01;

	/*TODO : Check the parameters is NULL*/
	if(NULL_PTR == ts_sec)
	{
		ret = 0x01;
	}
	else
	{
#if (TIME_TIMESTAMP_SOURCE_MODE == TIME_TIMESTAMP_SOURCE_MODE_STBM)
#if (TIME_STBM_RTE_USAGE == STD_ON)
        (void)Time_StbMGlobalTime_Slave_GetCurrentTime(&Time_StbmTimeStamp, &Time_StbmUserData);
#else
        TIME_ENTER_EXCLUSIVE_AREA_0();
        (void)StbM_GetCurrentTime(TIME_STBM_TIMEBASE_ID, &Time_StbmTimeStamp, &Time_StbmUserData); 
        TIME_EXIT_EXCLUSIVE_AREA_0();
#endif /*TIME_STBM_RTE_USAGE == STD_ON*/
    *ts_sec = (uint64)Time_StbmTimeStamp.seconds/* + (uint64)Time_StbmTimeStamp.secondsHi*4294967295*/;
#elif (TIME_TIMESTAMP_SOURCE_MODE == TIME_TIMESTAMP_SOURCE_MODE_STM0)
        *ts_sec = (uint64)((STM0_TIM0.U)/(TIME_STM0_CLK_FREQ * 1.0)) ;
#endif
        ret = 0x00;
	}
	return ret;
}

/**
 * \functions Time_GetGlobalTimeStatus
 *
 * \brief
 *
 * \parameters-in none
 *
 * \parameters-out  status,global Time status
 *                  bit mask definition,refer <<AUTOSAR_SWS_SynchronizedTimeBaseManager.pdf>>              
 * \return none
 *
 * \comments 1.The status definition,ple refer TIME_GLOBAL_TIME_STATUS_MASK in Time.h
 *
 */
uint8 Time_GetGlobalTimeStatus(uint8 *status)
{
	uint8 ret = 0x01;

	/*TODO : Check the parameters is NULL*/
	if(NULL_PTR == status)
	{
		ret = 0x01;
	}
	else
	{
#if (TIME_TIMESTAMP_SOURCE_MODE == TIME_TIMESTAMP_SOURCE_MODE_STBM)
#if (TIME_STBM_RTE_USAGE == STD_ON)
        (void)Time_StbMGlobalTime_Slave_GetCurrentTime(&Time_StbmTimeStamp, &Time_StbmUserData);
#else
        TIME_ENTER_EXCLUSIVE_AREA_0();
        (void)StbM_GetCurrentTime(TIME_STBM_TIMEBASE_ID, &Time_StbmTimeStamp, &Time_StbmUserData);
        TIME_EXIT_EXCLUSIVE_AREA_0();
#endif /*TIME_STBM_RTE_USAGE == STD_ON*/
    *status = Time_StbmTimeStamp.timeBaseStatus;
#else
        *status = TIME_GLOBAL_TIME_STATUS_MASK_GLOBAL_TIME_BASE;
#endif
        ret = 0x00;
	}
	return ret;
}

/**
 * \functions Time_MeasRunCycleTimeMs
 *
 * \brief
 *
 * \parameters-in none
 *
 * \parameters-out RunCycleMeas,
 *
 * \return none
 *
 * \comments 1.The param shall use the global variable,not use the stack variable;
 *           2.Use STM0 as the clock source
 *
 */
uint8 Time_MeasRunCycleTimeMs(s_Time_RunCycleMeas_t *RunCycleMeas)
{
	uint8 ret = 0x01;

    /*TODO : Check the parameters is NULL*/
	if(NULL_PTR == RunCycleMeas)
	{
		ret = 0x01;
	}
	else
    {
        if(0x00 == RunCycleMeas->RunCycleMs_Min)
        {
            RunCycleMeas->RunCycleMs_Min = 0xFFFFFFFF;
        }
        else
        {
            /*TODO : Doing nothing*/
        }

        RunCycleMeas->CurrentTimeStamp = STM0_TIM0.U;

        if((0x00 != RunCycleMeas->CurrentTimeStamp) && (0x00 != RunCycleMeas->LastTimeStamp))
        {
            RunCycleMeas->RunCounter++;
            if(RunCycleMeas->CurrentTimeStamp >= RunCycleMeas->LastTimeStamp)
            {
                RunCycleMeas->RunCycleMs = (float32)((RunCycleMeas->CurrentTimeStamp - RunCycleMeas->LastTimeStamp)/(TIME_STM0_CLK_FREQ*1.0)*1000);
            }
            else
            {
                RunCycleMeas->RunCycleMs = (float32)((0xffffffff - RunCycleMeas->LastTimeStamp + RunCycleMeas->CurrentTimeStamp)/(TIME_STM0_CLK_FREQ*1.0)*1000);
            }

            if(RunCycleMeas->RunCycleMs_Min > RunCycleMeas->RunCycleMs)
            {
                RunCycleMeas->RunCycleMs_Min = RunCycleMeas->RunCycleMs;
            }
            else
            {
                /*TODO : doing nothing*/
            }

            if(RunCycleMeas->RunCycleMs_Max < RunCycleMeas->RunCycleMs)
            {
                RunCycleMeas->RunCycleMs_Max = RunCycleMeas->RunCycleMs;
            }
            else
            {
                /*TODO : doing nothing*/
            }

            RunCycleMeas->RunCycleMs_Total = RunCycleMeas->RunCycleMs_Total + RunCycleMeas->RunCycleMs;
            RunCycleMeas->RunCycleMs_Average = RunCycleMeas->RunCycleMs_Total / RunCycleMeas->RunCounter;
        }
        else
        {
            /*TODO : doing nothing*/
        }

        RunCycleMeas->LastTimeStamp = RunCycleMeas->CurrentTimeStamp;

        ret = 0x00;
    }

    return ret;
}

/**
 * \functions Time_MeasRunIntervalTimeMs_Start
 *
 * \brief
 *
 * \parameters-in none
 *
 * \parameters-out RunIntervalTimeMeas,
 *
 * \return none
 *
 * \comments 1.The param shall use the global variable,not use the stack variable;
 *           2.Use STM0 as the clock source
 *
 */
uint8 Time_MeasRunIntervalTimeMs_Start(s_Time_RunIntervalMeas_t *RunIntervalTimeMeas)
{
	uint8 ret = 0x01;

    /*TODO : Check the parameters is NULL*/
	if(NULL_PTR == RunIntervalTimeMeas)
	{
		ret = 0x01;
	}
	else
    {
        RunIntervalTimeMeas->MeasStatus = 0x1;/*0x01 : Start*/
        RunIntervalTimeMeas->StartTimeStamp = STM0_TIM0.U;
       
        ret = 0x00;
    }

    return ret;
}

/**
 * \functions Time_MeasRunIntervalTimeMs_End
 *
 * \brief
 *
 * \parameters-in none
 *
 * \parameters-out RunIntervalTimeMeas,
 *
 * \return none
 *
 * \comments 1.The param shall use the global variable,not use the stack variable;
 *           2.Use STM0 as the clock source
 *
 */
uint8 Time_MeasRunIntervalTimeMs_End(s_Time_RunIntervalMeas_t *RunIntervalTimeMeas)
{
	uint8 ret = 0x01;

    /*TODO : Check the parameters is NULL*/
	if(NULL_PTR == RunIntervalTimeMeas)
	{
		ret = 0x01;
	}
	else
    {
        if(0x01 == RunIntervalTimeMeas->MeasStatus)
        {
            if(0x00 == RunIntervalTimeMeas->RunIntervalMs_Min)
            {
                RunIntervalTimeMeas->RunIntervalMs_Min = 0xFFFFFFFF;
            }
            else
            {
                /*TODO : Doing nothing*/
            }

            RunIntervalTimeMeas->EndTimeStamp = STM0_TIM0.U;

            if((0x00 != RunIntervalTimeMeas->EndTimeStamp) && (0x00 != RunIntervalTimeMeas->StartTimeStamp))
            {
                RunIntervalTimeMeas->RunCounter++;
                if(RunIntervalTimeMeas->EndTimeStamp >= RunIntervalTimeMeas->StartTimeStamp)
                {
                    RunIntervalTimeMeas->RunIntervalMs = (float32)((RunIntervalTimeMeas->EndTimeStamp - RunIntervalTimeMeas->StartTimeStamp)/(TIME_STM0_CLK_FREQ*1.0)*1000);
                }
                else
                {
                    RunIntervalTimeMeas->RunIntervalMs = (float32)((0xffffffff - RunIntervalTimeMeas->StartTimeStamp + RunIntervalTimeMeas->EndTimeStamp)/(TIME_STM0_CLK_FREQ*1.0)*1000);
                }

                if(RunIntervalTimeMeas->RunIntervalMs_Min > RunIntervalTimeMeas->RunIntervalMs)
                {
                    RunIntervalTimeMeas->RunIntervalMs_Min = RunIntervalTimeMeas->RunIntervalMs;
                }
                else
                {
                    /*TODO : doing nothing*/
                }

                if(RunIntervalTimeMeas->RunIntervalMs_Max < RunIntervalTimeMeas->RunIntervalMs)
                {
                    RunIntervalTimeMeas->RunIntervalMs_Max = RunIntervalTimeMeas->RunIntervalMs;
                }
                else
                {
                    /*TODO : doing nothing*/
                }

                RunIntervalTimeMeas->RunIntervalMs_Total = RunIntervalTimeMeas->RunIntervalMs_Total + RunIntervalTimeMeas->RunIntervalMs;
                RunIntervalTimeMeas->RunIntervalMs_Average = RunIntervalTimeMeas->RunIntervalMs_Total / RunIntervalTimeMeas->RunCounter;
            }
            else
            {
                /*TODO : doing nothing*/
            }
            RunIntervalTimeMeas->MeasStatus = 0x02;
            ret = 0x00;
        }
        else
        {
            RunIntervalTimeMeas->MeasStatus = 0x03;
            ret = 0x02;
        }      
    }

    return ret;
}

/**
 * \functions Time_MainFunction
 *
 * \brief
 *
 * \parameters-in none
 *
 * \parameters-out none
 *
 * \return none
 *
 * \comments The function not implemented,in order to mapping access event
 *
 */
void Time_MainFunction(void)
{

}

#define TIME_STOP_SEC_CODE
#include "Time_MemMap.h"
