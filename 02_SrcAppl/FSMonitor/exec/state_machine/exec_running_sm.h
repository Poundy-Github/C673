#ifndef EXEC_RUNNING_SM_H
#define EXEC_RUNNING_SM_H

enum exec_rsm_event_t{
    EXEC_RSM_EVENT_IMAGE_OVER_BUS_REQUEST,
    EXEC_RSM_EVENT_IMAGE_OVER_BUS_FINISHED,
    EXEC_RSM_EVENT_EOL_DIAGREQUEST,
    EXEC_RSM_EVENT_EOL_FINISH
};

enum exec_rsm_state_t{
    EXEC_RSM_STATE_STARTUP,
    EXEC_RSM_STATE_NORMAL,
    EXEC_RSM_STATE_IMAGE_OVER_BUS,
    EXEC_RSM_STATE_CALIBRATION
};

/**
 * @brief The init function of Running SM
*/
void FSExec_RuningSMInit(void);
/**
 * @brief The DeInit function of Running SM
*/
void FSExec_RuningSMDeInit(void);
/**
 * @brief Post a event to this SM
 * 
 * @param event the event post to the SM
*/
void FSExec_RuningSMPostEvent(enum exec_rsm_event_t event);
/**
 * @brief  Query the current SM State
 * 
 * @retval the state
*/
enum exec_rsm_state_t FSExec_RuningSMCurrentState(void);

#endif /** EXEC_RUNNING_SM_H */