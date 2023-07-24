#include "Logging.h"




#define __PDO__

typedef struct LoggingIF_MeasHeadType
{
    uint64              moduleid    :16;
    uint64              level       :2;
    uint64              timestampS  :22;
    uint64              timestampUS :24;
}LoggingIF_MeasHead_T;


typedef struct LoggingIF_MeasDataType
{
    uint8 Data[LOGGING_DATALENTH_THRESHOLD_HIGH];
}LoggingIF_MeasData_T;





extern Log_ReturnType_t LoggingIF_SendDataImmediately(Log_Cfg_t Cfg, uint8 const * const Data_p, const Log_Cbk_t Cbk_fp);
extern void LoggingIF_SendData_ViaCAN(void);
