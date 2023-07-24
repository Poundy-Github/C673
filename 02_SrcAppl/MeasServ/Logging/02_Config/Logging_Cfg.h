#include "Dbg_Cfg.h"

#define LOGGINGIF_MTSI_ENABLE   STD_ON
#define LOGGINGIF_CDM_ENABLE    STD_OFF
#define LOGGINGIF_J3_ENABLE     STD_OFF

#if (DBG_LOGGINGIF_CAN_ENABLE == STD_ON)
#define LOGGINGIF_CAN_ENABLE    STD_ON
#endif /*just release version use*/

#if (LOGGINGIF_CAN_ENABLE == STD_ON)
#define LOG_CAN_COMSIG_LOGLEVEL     ComConf_ComSignal_SGFC_Logging_Level_1568T
#define LOG_CAN_COMSIG_MODULEID     ComConf_ComSignal_SGFC_Logging_ModuleId_1568T
#define LOG_CAN_COMSIG_TSTAMP_S     ComConf_ComSignal_SGFC_Logging_TStampS_1568T
#define LOG_CAN_COMSIG_TSTAMPNS     ComConf_ComSignal_SGFC_Logging_TStampNS_1568T
#define LOG_CAN_COMSIG_PAYLOAD1     ComConf_ComSignal_SGFC_Logging_DataPayload1_1568T
#define LOG_CAN_COMSIG_PAYLOAD2     ComConf_ComSignal_SGFC_Logging_DataPayload2_1568T
#define LOG_CAN_COMSIG_PAYLOAD3     ComConf_ComSignal_SGFC_Logging_DataPayload3_1568T
#define LOG_CAN_COMSIG_PAYLOAD4     ComConf_ComSignal_SGFC_Logging_DataPayload4_1568T
#define LOG_CAN_COMSIG_PAYLOAD5     ComConf_ComSignal_SGFC_Logging_DataPayload5_1568T
#define LOG_CAN_COMSIG_PAYLOAD6     ComConf_ComSignal_SGFC_Logging_DataPayload6_1568T
#define LOG_CAN_COMSIG_PAYLOAD7     ComConf_ComSignal_SGFC_Logging_DataPayload7_1568T
#define LOG_CAN_COMIPDU             ComConf_ComIPdu_PDFC_620_1568T
#endif /*LOGGINGIF_CAN_ENABLE*/


#define LOGGING_QUEUE_SIZE  30u