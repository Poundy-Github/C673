#include "LoggingType.h"


#define LOGGING_HEADLENTH   10u
#define LOGGING_DATALENTH_THRESHOLD_LOW  1u
#define LOGGING_DATALENTH_THRESHOLD_HIGH 56u //7*8
#define LOGGING_SCHEDULE_CNT_MAX    12u


typedef struct LogRecord_TYPE
{
    Log_Cfg_t       Cfg;
    uint32          TimestampS;
    uint32          TimestampUS;
    uint8*          Data_p;
    Log_Cbk_t       Cbk_fp;
}LogRecord_t;


typedef struct LogHandler_TYPE
{
    uint16          Head;
    uint16          Tail;
    uint16          QIndex;
    uint8           ScheduleCnt;
    LogRecord_t*    LogQueue_p;
}LogHandler_t;

extern LogHandler_t LogHandler;

/// @brief DO NOT USE cyclically calling in order to reduce bus load
/// @param Cfg Field"DataLength" range: 1-56 Bytes ///Field"ImmediateSend" is ONLY reserved for the cases that will directly shut OS down
/// @param Data_p DO NOT USE NULL_PRT
/// @param Cbk_fp Shall be call after data sent. Use NULL_PTR in case not used callback function.
/// @return Details seen in Return type enum
extern Log_ReturnType_t Logging_SendData(Log_Cfg_t Cfg, uint8 const * const Data_p, const Log_Cbk_t Cbk_fp);