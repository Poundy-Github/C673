#ifndef EXEC_MAIN_SM_H
#define EXEC_MAIN_SM_H
#include "exec/fs_exec.h"
#include "exec/fs_catx.h"
enum exec_sm_event_id_t{
    EXEC_SM_EVENT_SELF_TEST_FINISH,
    EXEC_SM_EVENT_SET_SOC_POWER,
    // EXEC_SM_EVENT_SOC_TEMPERATURE,
    // EXEC_SM_EVENT_UBATT,
    EXEC_SM_EVENT_CAT3_POST,
    EXEC_SM_EVENT_CAT3_RECOVER,
    // EXEC_SM_EVENT_TEMPERATURE_SHUTDOWN,
    // EXEC_SM_EVENT_SHUTDOWN,
    EXEC_SM_EVENT_CAT2,
};

enum exec_sm_state_t{
    /** Startup MCU this is a boot code */
    EXEC_SM_STATE_STARTUP = 0,
    /** SAFE_STATE this is a boot code */
    /* EXEC_SM_STATE_SAFE_STATE, */
    EXEC_SM_STATE_LIMITED,/* Limited Mode Functions OFF */
    EXEC_SM_STATE_RUNNING,/* Infrastructure Running */
};
enum exec_sm_event_range_state_t{
    EXEC_SM_EVENT_STATE_LOW,
    EXEC_SM_EVENT_STATE_NORMAL,
    EXEC_SM_EVENT_STATE_HIGH
};
struct exec_sm_event_t{
    enum exec_sm_event_id_t id;
    union {
        struct {
            bool on;
        }set_soc_power;
        
        struct {
            struct fs_cat3_t error;
        }cat3_post;

        struct {
            struct fs_cat3_t error;
        }cat3_recovery;

        struct{
            struct fs_cat2_t error;
        } cat2;
        
    }params;
};

/**
 * @brief The Main SM Init Function
*/
void FSExec_SMInit(void);

/**
 * @brief The Main SM DeInit Function
*/
void FSExec_SMDeInit(void);

/**
 * @brief Post a event to this SM
 * 
 * @param event the event to post
 * 
*/
void FSExec_SMPostEvent(const struct exec_sm_event_t *event);

/**
 * @brief Poll function of Main SM 
 * 
 * @param ms interval
 * 
*/
void FSExec_SMPoll(unsigned int ms);

/**
 * @brief Query the current SM State
 * 
 * @retval the state
 * 
*/
enum fs_state_t FSExec_CurrentFSState(void);
#if FS_OPTION_IMMEDIATELY_CAT2_RESET == 0
/**
 * @brief Is the exec module request a reset
 * 
 * @retval true need to reset; false no request
 * 
*/
bool FSExec_NeedReset(void);
#endif /* FS_OPTION_IMMEDIATELY_CAT2_RESET*/
#endif /** EXEC_MAIN_SM_H */