/******************************************************************************/
/*----------------------------------Includes----------------------------------*/
/******************************************************************************/

#include "exec_running_sm.h"
#include "fs_common.h"
/******************************************************************************/
/*-----------------------------------Macros-----------------------------------*/
/******************************************************************************/

#define exec_rsm_flag_t int
#define EXEC_RSM_FLAG_IMAGE_OVER_BUS (1<<0)
#define EXEC_RSM_FLAG_CALIBRATION    (1<<1)
/******************************************************************************/
/*------------------------------TYEP DEFINITION-------------------------------*/
/******************************************************************************/

struct runing_sm_t{
    enum exec_rsm_state_t state;
    exec_rsm_flag_t       flags;
};
/******************************************************************************/
/*------------------------------Global variables------------------------------*/
/******************************************************************************/


/******************************************************************************/
/*------------------------------Static variables------------------------------*/
/******************************************************************************/
#define FS_START_SEC_VAR_CLEARED_LOCAL
#include "Fs_MemMap.h"
static struct runing_sm_t s_runing_sm = { 0 };

#define FS_STOP_SEC_VAR_CLEARED_LOCAL
#include "Fs_MemMap.h"

/******************************************************************************/
/*-------------------------Function Prototypes--------------------------------*/
/******************************************************************************/

/******************************************************************************/
/*-------------------------Static Function----------------------------------*/
#define FS_START_SEC_CODE_LOCAL
#include "Fs_MemMap.h"
static const char *s_state_repr(enum exec_rsm_state_t new_state)
{
    switch(new_state){
    case EXEC_RSM_STATE_STARTUP:
        return "STARTUP";
    case EXEC_RSM_STATE_NORMAL:
        return "NORMAL";
    case EXEC_RSM_STATE_IMAGE_OVER_BUS:
        return "IMAGE_OVER_BUS";
    case EXEC_RSM_STATE_CALIBRATION:
        return "CALIBRATION";
    default:
        break;
    }
    return "UNKNOWN";

}
static void s_state_transition(enum exec_rsm_state_t new_state)
{
    FS_LOG_DEBUG("fs runing state %s->%s",s_state_repr(s_runing_sm.state),s_state_repr(new_state));
    s_runing_sm.state = new_state;
}
/******************************************************************************/
/*-------------------------Global Function----------------------------------*/
/******************************************************************************/
void FSExec_RuningSMInit(void)
{
    FS_LOG_DEBUG("%s","fs runing sm init");
    s_runing_sm.state = EXEC_RSM_STATE_STARTUP;
    s_runing_sm.flags = 0;
    /** init stuff */
    
    /** init finish */
    s_state_transition(EXEC_RSM_STATE_NORMAL);
}

void FSExec_RuningSMDeInit(void)
{
    FS_LOG_DEBUG("%s","fs runing sm deinit");
    s_state_transition(EXEC_RSM_STATE_STARTUP);
    // s_runing_sm.state = EXEC_RSM_STATE_STARTUP;
}

void FSExec_RuningSMPostEvent(enum exec_rsm_event_t event)
{
    switch(event){
    case EXEC_RSM_EVENT_IMAGE_OVER_BUS_REQUEST:
        FS_FLAG_SET(s_runing_sm.flags,EXEC_RSM_FLAG_IMAGE_OVER_BUS);
        if(s_runing_sm.state == EXEC_RSM_STATE_NORMAL){
            s_state_transition(EXEC_RSM_STATE_IMAGE_OVER_BUS);
        }
        break;
    case EXEC_RSM_EVENT_IMAGE_OVER_BUS_FINISHED:
        FS_FLAG_CLEAR(s_runing_sm.flags,EXEC_RSM_FLAG_IMAGE_OVER_BUS);
        if(s_runing_sm.state == EXEC_RSM_STATE_IMAGE_OVER_BUS){
            s_state_transition(EXEC_RSM_STATE_NORMAL);
            if(s_runing_sm.flags & EXEC_RSM_FLAG_CALIBRATION){
                s_state_transition(EXEC_RSM_STATE_CALIBRATION);
            }
        }
        break;
    case EXEC_RSM_EVENT_EOL_DIAGREQUEST:
        FS_FLAG_SET(s_runing_sm.flags,EXEC_RSM_FLAG_CALIBRATION);
        if(s_runing_sm.state == EXEC_RSM_STATE_NORMAL){
            s_state_transition(EXEC_RSM_STATE_CALIBRATION);
        }
        break;
    case EXEC_RSM_EVENT_EOL_FINISH:
        FS_FLAG_CLEAR(s_runing_sm.flags,EXEC_RSM_FLAG_CALIBRATION);
        if(s_runing_sm.state == EXEC_RSM_STATE_CALIBRATION){
            s_state_transition(EXEC_RSM_STATE_NORMAL);
            if(s_runing_sm.flags & EXEC_RSM_FLAG_IMAGE_OVER_BUS){
                s_state_transition(EXEC_RSM_STATE_IMAGE_OVER_BUS);
            }
        }
        break;
    default:
        FS_ASSERT(0,"unknown state");
    }
}

enum exec_rsm_state_t FSExec_RuningSMCurrentState(void)
{
    return s_runing_sm.state;    
}


#define FS_STOP_SEC_CODE_LOCAL
#include "Fs_MemMap.h"