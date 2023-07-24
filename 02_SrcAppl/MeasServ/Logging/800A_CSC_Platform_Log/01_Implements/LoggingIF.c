/**
 * 
 * Concept:
 * invoke different bus to send data
*/
#include "Com.h"
#include "LoggingIF.h"
#include "Logging_Cfg.h"
#include "Com_SymbolicNames_PBcfg.h"
#include "Meas.h"
void LoadLoggingCANMsg(uint16 Length, uint8* Data_p);
void LoggingIF_CheckModeMaskNull(void);




#define LOG_MEAS_ADDR_HEAD  (0xA00E0000)
#define LOG_MEAS_ADDR_DATA  (0xA00E1000)
/*****************************************************************************
  PDO
*****************************************************************************/
#ifdef __PDO__
/****** Logging IF ******/
/*! @VADDR: LOG_MEAS_ADDR_HEAD 		@CYCLEID: CycleId_120 */
typedef LoggingIF_MeasHead_T LoggingIF_MeasHead_MTS_T;
/*! @VADDR: LOG_MEAS_ADDR_DATA 		@CYCLEID: CycleId_120 */
typedef LoggingIF_MeasData_T LoggingIF_MeasData_MTS_T;

#endif /*__PDO__*/
Log_ReturnType_t LoggingIF_SendDataImmediately(Log_Cfg_t Cfg, uint8 const * const Data_p, const Log_Cbk_t Cbk_fp)
{
    uint64 Sec;
    uint64 Nanosec;
    uint32 Microsec;
    MEASInfo_t MeasInfo,MeasInfo2;
    LoggingIF_MeasHead_T    Head;
    Log_ReturnType_t ret;

    (void)Time_GetTimeStampSec(&Sec);
    (void)Time_GetTimeStampNs(&Nanosec);

    if(LOGGING_MODEMASK_MTSI == (Cfg.Mode & LOGGING_MODEMASK_MTSI))
    {
#       if(LOGGINGIF_MTSI_ENABLE == STD_ON)
        (void)MTSI_DriverStartTaskCycle(120);
        MeasInfo.VirtualAddress = LOG_MEAS_ADDR_HEAD;
        MeasInfo.Length         = LOGGING_HEADLENTH;
        MeasInfo.FuncID         = 120;
        Head.moduleid   = Cfg.ModuleId;
        Head.level      = Cfg.Level;
        Head.timestampS = Sec;
        Head.timestampUS= (uint32)((Nanosec - (Sec * 1000000000ull))*0.001);
        MEASFreezeDataMTS(  &MeasInfo, 
                            &Head, 
                            NULL_PTR);

        MeasInfo2.VirtualAddress = LOG_MEAS_ADDR_DATA;
        MeasInfo2.Length         = Cfg.DataLength;
        MeasInfo2.FuncID         = 120;
        MEASFreezeDataMTS(  &MeasInfo2,
                            Data_p,
                            Cbk_fp);
#       endif/*LOGGINGIF_MTSI_ENABLE*/

        Cfg.Mode &= (~LOGGING_MODEMASK_MTSI);//clear mask
    }

    if(LOGGING_MODEMASK_CAN == (Cfg.Mode & LOGGING_MODEMASK_CAN))
    {
#       if(LOGGINGIF_CAN_ENABLE == STD_ON)
        Microsec = (uint32)((Nanosec - (Sec * 1000000000ull))*0.001);
        (void)Com_SendSignal(LOG_CAN_COMSIG_MODULEID,&(Cfg.ModuleId));
        (void)Com_SendSignal(LOG_CAN_COMSIG_LOGLEVEL,&(Cfg.Level));
        (void)Com_SendSignal(LOG_CAN_COMSIG_TSTAMP_S,&Sec);
        (void)Com_SendSignal(LOG_CAN_COMSIG_TSTAMPNS,&Microsec);

        LoadLoggingCANMsg(Cfg.DataLength,Data_p);
        (void)Com_TriggerIPDUSend(LOG_CAN_COMIPDU);

        //Calling callback function here, since IPDU callout is unable to distinguish Logging Sync/Async send
        if(NULL_PTR != Cbk_fp)
        {
            Cbk_fp();
        }
#       endif /*LOGGINGIF_CAN_ENABLE*/

        Cfg.Mode &= (~LOGGING_MODEMASK_CAN);//clear mask
    }

    ret = LOGGING_RET_SYNCJOB_SENT;
    return ret;
}








void LoggingIF_SendData_ViaMTSI(void)
{
    MEASInfo_t MeasInfo,MeasInfo2;
    LoggingIF_MeasHead_T    Head;   

    LogHandler.QIndex = LogHandler.Tail;
    do
    {
        if(LOGGING_MODEMASK_MTSI == (LogHandler.LogQueue_p[LogHandler.QIndex].Cfg.Mode & LOGGING_MODEMASK_MTSI))
        {

#           if(LOGGINGIF_MTSI_ENABLE == STD_ON)
            (void)MTSI_DriverStartTaskCycle(120);
            MeasInfo.VirtualAddress = LOG_MEAS_ADDR_HEAD;
            MeasInfo.Length         = LOGGING_HEADLENTH;
            MeasInfo.FuncID         = 120;
            Head.moduleid   = LogHandler.LogQueue_p[LogHandler.QIndex].Cfg.ModuleId;
            Head.level      = LogHandler.LogQueue_p[LogHandler.QIndex].Cfg.Level;
            Head.timestampS = LogHandler.LogQueue_p[LogHandler.QIndex].TimestampS;
            Head.timestampUS= LogHandler.LogQueue_p[LogHandler.QIndex].TimestampUS;
            MEASFreezeDataMTS(  &MeasInfo, 
                                &Head, 
                                NULL_PTR);

            MeasInfo2.VirtualAddress = LOG_MEAS_ADDR_DATA;
            MeasInfo2.Length         = LogHandler.LogQueue_p[LogHandler.QIndex].Cfg.DataLength;
            MeasInfo2.FuncID         = 120;
            MEASFreezeDataMTS(  &MeasInfo2,
                                LogHandler.LogQueue_p[LogHandler.QIndex].Data_p,
                                LogHandler.LogQueue_p[LogHandler.QIndex].Cbk_fp);
#           endif/*LOGGINGIF_MTSI_ENABLE*/

            LogHandler.LogQueue_p[LogHandler.QIndex].Cfg.Mode &= (~LOGGING_MODEMASK_MTSI);//clear mask
            LoggingIF_CheckModeMaskNull();
        }
        LogHandler.QIndex = (LogHandler.QIndex + 1) % LOGGING_QUEUE_SIZE;
    } while (LogHandler.QIndex != LogHandler.Head);
}


void LoggingIF_SendData_ViaCAN(void)
{
    uint8   u8_data = 0;
    LogHandler.QIndex = LogHandler.Tail;

    do
    {
        if(LOGGING_MODEMASK_CAN == (LogHandler.LogQueue_p[LogHandler.QIndex].Cfg.Mode & LOGGING_MODEMASK_CAN))
        {

#           if(LOGGINGIF_CAN_ENABLE == STD_ON)
            (void)Com_SendSignal(LOG_CAN_COMSIG_MODULEID,&(LogHandler.LogQueue_p[LogHandler.QIndex].Cfg.ModuleId));
            (void)Com_SendSignal(LOG_CAN_COMSIG_LOGLEVEL,&(LogHandler.LogQueue_p[LogHandler.QIndex].Cfg.Level));
            (void)Com_SendSignal(LOG_CAN_COMSIG_TSTAMP_S,&(LogHandler.LogQueue_p[LogHandler.QIndex].TimestampS));
            (void)Com_SendSignal(LOG_CAN_COMSIG_TSTAMPNS,&(LogHandler.LogQueue_p[LogHandler.QIndex].TimestampUS));

            LoadLoggingCANMsg(  LogHandler.LogQueue_p[LogHandler.QIndex].Cfg.DataLength,
                                LogHandler.LogQueue_p[LogHandler.QIndex].Data_p);
            (void)Com_TriggerIPDUSend(LOG_CAN_COMIPDU);
            //Calling callback function here, since IPDU callout is unable to distinguish Logging Sync/Async send
            if(NULL_PTR != LogHandler.LogQueue_p[LogHandler.QIndex].Cbk_fp)
            {
                LogHandler.LogQueue_p[LogHandler.QIndex].Cbk_fp();
            }
#           endif /*LOGGINGIF_CAN_ENABLE*/

            LogHandler.LogQueue_p[LogHandler.QIndex].Cfg.Mode &= (~LOGGING_MODEMASK_CAN);//clear mask
            LoggingIF_CheckModeMaskNull();
        }
        LogHandler.QIndex = (LogHandler.QIndex + 1) % LOGGING_QUEUE_SIZE;
    } while (LogHandler.QIndex != LogHandler.Head);
    
}

FUNC(boolean, COM_APPL_CODE)Logging_ComIPduCallout(PduIdType ID,P2VAR(PduInfoType, AUTOMATIC, COM_VAR_CLEARED) PduInfoPtr)
{
    // if(NULL_PTR != LogHandler.LogQueue_p[LogHandler.QIndex].Cbk_fp)
    // {
    //     LogHandler.LogQueue_p[LogHandler.QIndex].Cbk_fp();
    // }
}

void LoadLoggingCANMsg(uint16 Length, uint8* Data_p)
{
    uint64  u64_data = 0;
    uint16  index = 0;

#   if(LOGGINGIF_CAN_ENABLE == STD_ON)
    while ((0 == index / 8)&&(index<Length))
    {
        u64_data |= ((uint64)Data_p[index] << (8*(7-(index % 8))));
        index ++;
    }
    (void)Com_SendSignal(LOG_CAN_COMSIG_PAYLOAD1,&u64_data);
    u64_data = 0;
    while ((1 == index / 8)&&(index<Length))
    {
        u64_data |= ((uint64)Data_p[index] << (8*(7-(index % 8))));
        index ++;
    }
    (void)Com_SendSignal(LOG_CAN_COMSIG_PAYLOAD2,&u64_data);
    u64_data = 0;
    while ((2 == index / 8)&&(index<Length))
    {
        u64_data |= ((uint64)Data_p[index] << (8*(7-(index % 8))));
        index ++;
    }
    (void)Com_SendSignal(LOG_CAN_COMSIG_PAYLOAD3,&u64_data);
    u64_data = 0;
    while ((3 == index / 8)&&(index<Length))
    {
        u64_data |= ((uint64)Data_p[index] << (8*(7-(index % 8))));
        index ++;
    }
    (void)Com_SendSignal(LOG_CAN_COMSIG_PAYLOAD4,&u64_data);
    u64_data = 0;
    while ((4 == index / 8)&&(index<Length))
    {
        u64_data |= ((uint64)Data_p[index] << (8*(7-(index % 8))));
        index ++;
    }
    (void)Com_SendSignal(LOG_CAN_COMSIG_PAYLOAD5,&u64_data);
    u64_data = 0;
    while ((5 == index / 8)&&(index<Length))
    {
        u64_data |= ((uint64)Data_p[index] << (8*(7-(index % 8))));
        index ++;
    }
    (void)Com_SendSignal(LOG_CAN_COMSIG_PAYLOAD6,&u64_data);
    u64_data = 0;
    while ((6 == index / 8)&&(index<Length))
    {
        u64_data |= ((uint64)Data_p[index] << (8*(7-(index % 8))));
        index ++;
    }
    (void)Com_SendSignal(LOG_CAN_COMSIG_PAYLOAD7,&u64_data);
    u64_data = 0;
#   endif /*LOGGINGIF_CAN_ENABLE*/
}
void LoggingIF_CheckModeMaskNull(void)
{
    if(LOGGING_MODEMASK_NULL == LogHandler.LogQueue_p[LogHandler.QIndex].Cfg.Mode)
    {
        LogHandler.Tail = (LogHandler.Tail+ 1) % LOGGING_QUEUE_SIZE;
    }
}
