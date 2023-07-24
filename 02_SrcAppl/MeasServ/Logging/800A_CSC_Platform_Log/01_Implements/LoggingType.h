/*For external module including*/
#include "Std_Types.h"

typedef enum
{
    LOGGING_MODEMASK_NULL =   0x00,
    LOGGING_MODEMASK_CAN  =   0x01,
    LOGGING_MODEMASK_MTSI =   0x02,
    LOGGING_MODEMASK_CDM  =   0x04,
    LOGGING_MODEMASK_ETH  =   0x08,   /*Not implemented*/
    LOGGING_MODEMASK_UART =   0x10,   /*Not implemented*/
    LOGGING_MODEMASK_J3   =   0x20    /*Not implemented*/
}Log_ModeMask_t;

typedef enum
{
    LOGGING_RET_CONDITION_ACCEPT    =   0u,
    LOGGING_RET_MODULE_NOTSUPPORT   =   1u,//not used
    LOGGING_RET_MASK_NOTSUPPORT     =   2u,
    LOGGING_RET_DATALENTH_NOTACCEPT =   3u,
    LOGGING_RET_GENERALREJECT       =   4u,
    LOGGING_RET_ASYNCJOB_ACCEPT     =   5u,
    LOGGING_RET_SYNCJOB_SENT        =   6u
}Log_ReturnType_t;

typedef enum
{
    LOGGING_LEVEL_INFO      = 0u,
    LOGGING_LEVEL_WARNING   = 1u,
    LOGGING_LEVEL_ERROR     = 2u
}Log_Level_t;

typedef struct
{
    uint16          ModuleId;       /*Specified in Module configuration*/
    Log_ModeMask_t  Mode;
    Log_Level_t     Level;
    uint16          DataLength;     /*Range: 1 - 448 (7*64) Bytes*/
    boolean         ImmediateSend;  /*ONLY for the cases that will directly shut Os down !!!*/
}Log_Cfg_t;

typedef void (*Log_Cbk_t)(void); 

