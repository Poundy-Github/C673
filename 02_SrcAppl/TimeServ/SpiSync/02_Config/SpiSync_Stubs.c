/**
 * \file 
 *
 * \brief 
 *
 * \version refer the SpiSync_Core.h.  
 * 
 * \copyright  2021 - 2022 Conti Smart Core
 *
 */
/*==================[inclusions]============================================*/
#include "SpiSync_Stubs.h"
#include "SpiSync_Cfg.h"
#include "Com_SymbolicNames_PBcfg.h"
#include "SpiSync_Type.h"
#include "SpiSync_Type.h"
#include "SpiSync_Core.h"
#include "Sdc_Core.h"
#include "Com.h"
#include "Cdd_Sbc_Cfg.h"
#include "Mcu_17_TimerIp.h"
#include <Rte_SpiSync.h>

/*==================[external constants definition]=========================*/


/*==================[internal constants definition]=========================*/
const uint8 SpiSync_leapYear[12] = {31,29,31,30,31,30,31,31,30,31,30,31};
const uint8 SpiSync_commonYear[12] = {31,28,31,30,31,30,31,31,30,31,30,31};

/*==================[external data definition]==============================*/

extern s_SpiSync_TimeSyncStatus_t SpiSync_TimeSyncStatus;
/*==================[internal data definition]==============================*/
static uint8 SpiSync_UseDefaultOffset = 0x00;///< 0 : Use default offset; 1 : Use Utc offset
static SpiSync_AdcUtcTimeType SpiSync_AdcUtcTime;
static uint8 vldFlag;
/*==================[internal function declarations]========================*/
static boolean SpiSync_getAdcUtcTime(SpiSync_AdcUtcTimeType *st);
static void SpiSync_sentFcUtcTime(SpiSync_AdcUtcTimeType *st,uint8 valid);
static uint8 SpiSync_IsLeap(int year);
static uint64 SpiSync_calAllYears2Days(uint16 year);
static uint64 SpiSync_calAllMonths2Days(uint16 year,uint16 month);
uint64 SpiSync_transUtc2Seconds(uint16 year,uint16 month,uint16 day,uint16 hour,uint16 minute,uint16 sec);

/**
 * \functions Pwm_Trigger_Function
 *
 * \brief
 *
 * \parameters-in none
 *
 * \parameters-out none
 *
 * \return none
 *
 * \comments
 *
 */
static void Pwm_Trigger_Function(void)
{
    static uint64 TimesecondStampold = 0x00;
    static uint64 Timestamp_Sec = 0x00;

    Time_GetTimeStampSec(&Timestamp_Sec);
	if(TimesecondStampold != Timestamp_Sec)
	{
        /**/
		Mcu_17_Gtm_AtomChannelDisable(SpiSync_Used_Gtm_AtomModule,SpiSync_Used_Gtm_AtomChannel);
		TimesecondStampold = Timestamp_Sec;
		Mcu_17_Gtm_AtomChannelEnable(SpiSync_Used_Gtm_AtomModule,SpiSync_Used_Gtm_AtomChannel,MCU_GTM_TIMER_OUT_ENABLE);
	}
}


/*==================[external function definitions]=========================*/
uint8 SpiSync_Cot_GetTimestampOffset(uint64 *time_stamp)
{
    uint8 ret = 0xFF;

    if(TRUE == SpiSync_getAdcUtcTime(&SpiSync_AdcUtcTime))
    {
        *time_stamp = (SPISYNC_TIMESYNC_DYNAMIC_DEFAULT_TIMESTAMP_OFFSET + SpiSync_transUtc2Seconds(CELLENDAR_GET_UTC_PARA(SpiSync_AdcUtcTime))) * 1000000000ul;
        SpiSync_UseDefaultOffset = 0x01;
        ret = 0x00;
    }
    else
    {
        ret = 0x01;
    }
    return ret;
}

#if (SPISYNC_USERFUNCTION_ENABLE == STD_ON)
/**
 * \functions SpiSync_UserInitFunction
 *
 * \brief
 *
 * \parameters-in none
 *
 * \parameters-out none
 *
 * \return none
 *
 * \comments
 *
 */
void SpiSync_UserInitFunction(void)
{
    SpiSync_AdcUtcTime.year   = 0;//represent 2000 year
    SpiSync_AdcUtcTime.month  = 1;
    SpiSync_AdcUtcTime.day    = 1;
    SpiSync_AdcUtcTime.hour   = 0;
    SpiSync_AdcUtcTime.minute = 0;
    SpiSync_AdcUtcTime.sec    = 0;
}


/**
 * \functions SpiSync_UserMainFunction
 *
 * \brief
 *
 * \parameters-in none
 *
 * \parameters-out none
 *
 * \return none
 *
 * \comments
 *
 */
void SpiSync_UserMainFunction(void)
{
    e_SpiSync_TimeSyncState_t SpiSync_TimeSyncState = SpiSync_TimeSync_State_None;

    /*PWM trigger 30hz,duty cycle 50%*/
    Pwm_Trigger_Function();

    /* Get and check the Spi Time Sync Status */
    SpiSync_Core_GetSpiTimeSyncStatus(&SpiSync_TimeSyncState);

    if(SpiSync_TimeSync_State_Sync_Success == SpiSync_TimeSyncState)
    {

        s_SipSync_TimeSyncMessage_t utc_time_stamp;
        utc_time_stamp.TimeStamp.raw[0] = (SpiSync_AdcUtcTime.year + 2000) / 256;
        utc_time_stamp.TimeStamp.raw[1] = (SpiSync_AdcUtcTime.year + 2000) % 256;
        utc_time_stamp.TimeStamp.raw[2] = SpiSync_AdcUtcTime.month;
        utc_time_stamp.TimeStamp.raw[3] = SpiSync_AdcUtcTime.day;
        utc_time_stamp.TimeStamp.raw[4] = SpiSync_AdcUtcTime.hour;
        utc_time_stamp.TimeStamp.raw[5] = SpiSync_AdcUtcTime.minute;
        utc_time_stamp.TimeStamp.raw[6] = SpiSync_AdcUtcTime.sec;

        // Sdc_Core_SendHandler_svcAPTimeSyncUtc(&utc_time_stamp);
        // Sdc_SendInterface_TimeSyncUtc(&utc_time_stamp);
        Rte_Call_RP_Sdc_TimeSync_TimeSyncUtc((uint8 *)&utc_time_stamp, sizeof(s_SipSync_TimeSyncMessage_t));
    }

    if((SpiSync_TimeSync_State_Sync_Success == SpiSync_TimeSyncState)
    ||(SpiSync_TimeSync_State_Sync == SpiSync_TimeSyncState))
    {
        if(0x01 == SpiSync_UseDefaultOffset)
        {
            SpiSync_sentFcUtcTime(&SpiSync_AdcUtcTime,0);//0 for valid
        }
        else
        {
            //using default
            SpiSync_AdcUtcTime.year   = 0;//represent 2000 year
            SpiSync_AdcUtcTime.month  = 1;
            SpiSync_AdcUtcTime.day    = 1;
            SpiSync_AdcUtcTime.hour   = 0;
            SpiSync_AdcUtcTime.minute = 0;
            SpiSync_AdcUtcTime.sec    = 0;
            SpiSync_sentFcUtcTime(&SpiSync_AdcUtcTime,1);//1 for invalid
        }
    }
    
}
#endif

FUNC(boolean, COM_APPL_CODE) ComIPduCallout_201
(
  PduIdType ID,
  P2VAR(PduInfoType, AUTOMATIC, COM_VAR_CLEARED) PduInfoPtr
)
{
    uint8 global_time_status = 0x00;
    Time_GetGlobalTimeStatus(&global_time_status);

    if((1 == (PduInfoPtr->SduDataPtr[0] & 0x3)) && ((global_time_status & 0x8) == 0x8 ))
    {
    Goto_Standby(&fs8400drvData);
    }

    return 1;
}


FUNC(boolean, COM_APPL_CODE) ComIPduCallout_0x1F1
(
  PduIdType ID,
  P2VAR(PduInfoType, AUTOMATIC, COM_VAR_CLEARED) PduInfoPtr
)
{
    if (SpiSync_TimeSyncStatus.TimeSyncWaitStartUpCounter >= (SPISYNC_TIMESYNC_START_UP_WAIT_TIME/SPISYNC_MAIN_FUNCTION_PERIOD_TIME))
    {
        /**
         *     Bit  7   6   5   4   3   2   1   0   
         * Byte
         *  0     |<-------- UTC_Year ---------->|
         *  1     |<- UTC_Month ->|<-- UTC_Date --
         *  2     --->|<---- UTC_Hour --->|<------
         *  3     - UTC_Minute -->|<-- UTC_Second 
         *  4     ------->|Vld|
         * **/
        if(PduInfoPtr->SduLength >= SPISYNC_SIG_UTCVALID_BYTE_POS)
        {
            if(0 == (PduInfoPtr->SduDataPtr[SPISYNC_SIG_UTCVALID_BYTE_POS] & SPISYNC_SIG_UTCVALID_BIT_MASK))/* valid *///Req:7.2.2_2,Req:7.2.2_3
            {
                vldFlag++;//Req:7.2.2_4
            }
        }
    }
    return 1;
}


/*==================[internal function definitions]=========================*/
static boolean SpiSync_getAdcUtcTime(SpiSync_AdcUtcTimeType *st)
{
  /* TODO */
    uint8 u8Tmp = 1;
    uint8 ret = FALSE;

    /*Signal validation check implemented in ComIPduCallout_0x1F1*/
    if(vldFlag >= 2)//Req:7.2.2_5
    {
        (void)Com_ReceiveSignal(ComConf_ComSignal_SGADC_UTCTiYear_497R,&st->year);
        (void)Com_ReceiveSignal(ComConf_ComSignal_SGADC_UTCTiMth_497R,&st->month);
        (void)Com_ReceiveSignal(ComConf_ComSignal_SGADC_UTCTiDate_497R,&st->day);
        (void)Com_ReceiveSignal(ComConf_ComSignal_SGADC_UTCTiHr_497R,&st->hour);
        (void)Com_ReceiveSignal(ComConf_ComSignal_SGADC_UTCTiMins_497R,&st->minute);
        (void)Com_ReceiveSignal(ComConf_ComSignal_SGADC_UTCTiSec_497R,&st->sec);

        /*Check the signal range*/
        if(    ((st->month >= 13) || (0x00 == st->month))
            || ((st->day >= 32) || (0x00 == st->day))
            || (st->hour >= 24)
            || (st->minute >= 60)
            || (st->sec >= 60) )
        {
            ret = FALSE;
        }
        else
        {
            ret = TRUE;
        }
    }
    else
    {
        ret = FALSE;
    }
    return ret;
}

static void SpiSync_sentFcUtcTime(SpiSync_AdcUtcTimeType *st,uint8 valid)
{
  (void)Com_SendSignal(ComConf_ComSignal_SGFC_UTCTiYear_498T,&st->year);
  (void)Com_SendSignal(ComConf_ComSignal_SGFC_UTCTiMth_498T,&st->month);
  (void)Com_SendSignal(ComConf_ComSignal_SGFC_UTCTiDate_498T,&st->day);
  (void)Com_SendSignal(ComConf_ComSignal_SGFC_UTCTiHr_498T,&st->hour);
  (void)Com_SendSignal(ComConf_ComSignal_SGFC_UTCTiMins_498T,&st->minute);
  (void)Com_SendSignal(ComConf_ComSignal_SGFC_UTCTiSec_498T,&st->sec);
  (void)Com_SendSignal(ComConf_ComSignal_SGFC_UTCTiVld_498T,&valid);
}

static uint8 SpiSync_IsLeap(int year)
{
    if ((year % 400 == 0) || (((year % 4) == 0) && ((year % 100) != 0))) 
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

static uint64 SpiSync_calAllYears2Days(uint16 year)
{
    uint16 i ;
    uint32 days = 0;

    if(1 <= year)
    {
       for(i = 0; i < year ; i++)
        {
            days += SpiSync_IsLeap(OFFSET_YEAR + i) ? 366:365;
        }
    }

    return days;
}

static uint64 SpiSync_calAllMonths2Days(uint16 year,uint16 month)
{
    uint16 i ;
    uint32 days = 0;

    if (month >= 1 && month <= 12)
    {
        for(i = 0; i < (month - 1) ; i++)
        {
            days += SpiSync_IsLeap(year)? SpiSync_leapYear[i]:SpiSync_commonYear[i];
        }
    }

    return days;
}

uint64 SpiSync_transUtc2Seconds(uint16 year,uint16 month,uint16 day,uint16 hour,uint16 minute,uint16 sec)
{
    uint16 i ;
    uint32 days = 0;

    days += SpiSync_calAllYears2Days(year);
    days += SpiSync_calAllMonths2Days(year,month);
    days += (day-1);

    return sec + (((days * 24 + hour) * 60 + minute)* 60);
}
