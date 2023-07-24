/******************************************************************************/
/*----------------------------------Includes----------------------------------*/
/******************************************************************************/
#include "exec_main_sm.h"
#include "function_safety.h"
#include "fs_required.h"
#include <stdbool.h>
#include "exec/fs_soc.h"
#include "exec/fs_mcu.h"
#include "exec_running_sm.h"
#include "exec/fs_catx.h"
#include "fs_config.h"
#include "ism/fs_check.h"
#if FS_FEATURE_RECORD_DEM
#include "Dem_Cfg.h"
#include "Dem.h"
#include "Rte_Dem.h"
#endif
#include "fs_common.h"
#include "fs_pdo.h"

/******************************************************************************/
/*-----------------------------------Macros-----------------------------------*/
/******************************************************************************/

/******************************************************************************/
/*------------------------------TYEP DEFINITION-------------------------------*/
/******************************************************************************/

enum record_cat2_then_op_t{
    THEN_NOTHING = 0,
    THEN_RESET,
    // THEN_SHUTDOWN
};
struct exec_sm_t{
    enum exec_sm_state_t state;
    bool app_request_soc_power_on;
#if FS_OPTION_IMMEDIATELY_CAT2_RESET == 0
    enum record_cat2_then_op_t then_op;
    uint32_t then_remain_time;
#endif /* FS_OPTION_IMMEDIATELY_CAT2_RESET */
};
/******************************************************************************/
/*------------------------------Global variables------------------------------*/
/******************************************************************************/


/******************************************************************************/
/*------------------------------Static variables------------------------------*/
/******************************************************************************/
#define FS_START_SEC_VAR_CLEARED_LOCAL
#include "Fs_MemMap.h"

static struct exec_sm_t s_main_sm = { 0 };

#define FS_STOP_SEC_VAR_CLEARED_LOCAL
#include "Fs_MemMap.h"

/******************************************************************************/
/*-------------------------Function Prototypes--------------------------------*/
/******************************************************************************/

/******************************************************************************/
/*-------------------------Static Function----------------------------------*/
/******************************************************************************/
#define FS_START_SEC_CODE_LOCAL
#include "Fs_MemMap.h"
static const char *s_state_repr(enum exec_sm_state_t new_state)
{
    switch(new_state){
    case EXEC_SM_STATE_STARTUP:
        return "STARTUP";
    case EXEC_SM_STATE_LIMITED:
        return "LIMITED";
    case EXEC_SM_STATE_RUNNING:
        return "RUNNING";
    default:
        break;
    }
    return "UNKNWON";

}
static void s_state_transition(enum exec_sm_state_t new_state)
{
    FS_LOG_DEBUG("fs state %s->%s",s_state_repr(s_main_sm.state),s_state_repr(new_state));
	
    s_main_sm.state = new_state;

	switch(new_state)
	{
        case EXEC_SM_STATE_STARTUP:
            FSExec_DisableCan(true);
            break;
        case EXEC_SM_STATE_LIMITED:
            FSExec_DisableCan(false);
            FSExec_SocPowerOff();
            FSCheck_WdgKeepFeed(true);
            FSExec_RuningSMDeInit();
            break;
        case EXEC_SM_STATE_RUNNING:
            FSExec_SocPowerOn();
            FSCheck_WdgKeepFeed(false);
            FSExec_RuningSMInit();
            break;
        default:
            FS_ASSERT(false,"unknown state");
    }
}
static bool s_soc_power_on_ready(void)
{
    bool ret = s_main_sm.app_request_soc_power_on && FSCat_Cat3Count() == 0;
    FS_LOG_DEBUG("Fs power_on ready=%s,cat3 count=%d,app_request=%s",
        ret?"yes":"no",
        FSCat_Cat3Count(),
        s_main_sm.app_request_soc_power_on?"yes":"no"
    );
    return ret;
}

static void s_recalucate_state_transition(void)
{
    if(s_main_sm.state == EXEC_SM_STATE_LIMITED)
	{
        if(s_soc_power_on_ready())
		{
            s_state_transition(EXEC_SM_STATE_RUNNING);
        }
		else
		{
            /* pass */
        }
    }
    else if(s_main_sm.state == EXEC_SM_STATE_RUNNING)
	{
        if(s_soc_power_on_ready())
		{
            /* pass */
        }
		else
        {
            s_state_transition(EXEC_SM_STATE_LIMITED);
        }
    }
}

static void s_record_cat2_then(fs_catx_id_t catid,enum record_cat2_then_op_t then)
{
#if FS_FEATURE_RECORD_DEM
    if(catid > 0){
        Dem_SetEventStatus(catid, DEM_EVENT_STATUS_FAILED);
    }
#endif
    FSCat_SetResetReason(FS_CAT_RESET_REASON_CAT2);
    
    FSCat_Cat2Increase();
#if FS_OPTION_IMMEDIATELY_CAT2_RESET
    FSExec_McuReset();
#else /** FS_OPTION_IMMEDIATELY_CAT2_RESET */
    s_main_sm.then_op = then;
    s_main_sm.then_remain_time = FS_CONFIG_DEM_CAT2_TIMEOUT;
#endif /* FS_OPTION_IMMEDIATELY_CAT2_RESET*/
    
}
/******************************************************************************/
/*-------------------------Global Function----------------------------------*/
/******************************************************************************/
void FSExec_SMInit(void)
{
    FSExec_RuningSMInit();
    s_main_sm.state = EXEC_SM_STATE_STARTUP;
    s_main_sm.app_request_soc_power_on = 0;
	
#if (FS_OPTION_IMMEDIATELY_CAT2_RESET == 0)

    s_main_sm.then_op = THEN_NOTHING;
    s_main_sm.then_remain_time = 0;
	
#endif
}

void FSExec_SMDeInit(void)
{
    FSExec_RuningSMDeInit();
    s_main_sm.state = EXEC_SM_STATE_STARTUP;
}

void FSExec_SMPostEvent(const struct exec_sm_event_t *event)
{
    switch(event->id)
    {
        case EXEC_SM_EVENT_SELF_TEST_FINISH:
            if(s_main_sm.state == EXEC_SM_STATE_STARTUP)
			{
                s_state_transition(EXEC_SM_STATE_LIMITED);
            }
            break;
        case EXEC_SM_EVENT_SET_SOC_POWER:
            if(s_main_sm.app_request_soc_power_on != event->params.set_soc_power.on)
			{
                FS_LOG_DEBUG("Set soc pwr = %s",event->params.set_soc_power.on?"on":"off");
                s_main_sm.app_request_soc_power_on = event->params.set_soc_power.on;
                s_recalucate_state_transition();
            }
            break;
        case EXEC_SM_EVENT_CAT3_POST:
            #if FS_PDO_ENABLED
            g_fs_debug_status.cat3_record_post[g_fs_debug_status.cat3_record_post_count]=event->params.cat3_post.error.cat3id;
            g_fs_debug_status.cat3_record_post_count = (g_fs_debug_status.cat3_record_post_count + 1)% 8;
            #endif /** FS_PDO_ENABLED */

            #if (!FS_EXEC_DISABLED)
            if(!FSCat_HasCat3(event->params.cat3_post.error.cat3id))
			{
                FS_LOG_DEBUG("Post cat3 0x%x",event->params.cat3_post.error.cat3id);
                #if FS_FEATURE_RECORD_DEM
                if( event->params.cat3_post.error.is_dem )
				{
                    Dem_SetEventStatus(event->params.cat3_post.error.cat3id, DEM_EVENT_STATUS_FAILED);
                }
                #endif

				FSCat_AddCat3(event->params.cat3_post.error.cat3id);
                s_recalucate_state_transition();
            }
            #endif /* !FS_EXEC_DISABLED */

            break;
        case EXEC_SM_EVENT_CAT3_RECOVER:
            #if FS_PDO_ENABLED
            //g_fs_debug_status.cat3_record_recovery[g_fs_debug_status.cat3_record_recovery_count]=event->params.cat3_recovery.error.cat3id;
            //g_fs_debug_status.cat3_record_recovery_count = (g_fs_debug_status.cat3_record_recovery_count + 1)% 8;
            #endif /** FS_PDO_ENABLED */

            #if (!FS_EXEC_DISABLED)
            if(FSCat_HasCat3(event->params.cat3_recovery.error.cat3id))
			{
                FS_LOG_DEBUG("Recovery cat3 0x%x",event->params.cat3_recovery.error.cat3id);
                #if FS_FEATURE_RECORD_DEM
                if( event->params.cat3_recovery.error.is_dem )
				{
                    Dem_SetEventStatus(event->params.cat3_recovery.error.cat3id, DEM_EVENT_STATUS_PASSED);
                }
                #endif

				FSCat_ClearCat3(event->params.cat3_recovery.error.cat3id);
                s_recalucate_state_transition();
            }
            #endif /* !FS_EXEC_DISABLED */

			break;
        case EXEC_SM_EVENT_CAT2:
            #if FS_PDO_ENABLED
            g_fs_debug_status.reset_source_fs[g_fs_debug_status.reset_source_fs_count] = 0xe0+((uint8)event->params.cat2.error.cat2id);
	        g_fs_debug_status.reset_source_fs_count = (g_fs_debug_status.reset_source_fs_count + 1)% 32;
            #endif /** FS_PDO_ENABLED */

            #if (!FS_EXEC_DISABLED)
                #if !FS_OPTION_IMMEDIATELY_CAT2_RESET
                if(s_main_sm.then_op == THEN_NOTHING)
				{
                #endif
                    //FS_LOG_DEBUG("Cat2 0x%x detected",event->params.cat2.error.cat2id);
                    s_state_transition(EXEC_SM_STATE_STARTUP);
                    s_record_cat2_then(event->params.cat2.error.cat2id,THEN_RESET);
                #if !FS_OPTION_IMMEDIATELY_CAT2_RESET
                }
                #endif 
            #endif /* !FS_EXEC_DISABLED */
            break;
        default:
            FS_ASSERT(false,"unknown fs event");
    }
}

void FSExec_SMPoll(unsigned int ms){

    if(s_main_sm.state == EXEC_SM_STATE_RUNNING){
        if(FSExec_AppIsEOL()){
            FSExec_RuningSMPostEvent(EXEC_RSM_EVENT_EOL_DIAGREQUEST);
        }else{
            FSExec_RuningSMPostEvent(EXEC_RSM_EVENT_EOL_FINISH);
        }
    }
#if FS_OPTION_IMMEDIATELY_CAT2_RESET == 0
    if( s_main_sm.then_remain_time > 0 ){
        if( ms > s_main_sm.then_remain_time ){
            s_main_sm.then_remain_time = 0;
        }else{
            s_main_sm.then_remain_time -= ms;
        }
    }
#endif /* FS_OPTION_IMMEDIATELY_CAT2_RESET */

}

enum fs_state_t FSExec_CurrentFSState(void){
    switch(s_main_sm.state){
    case EXEC_SM_STATE_STARTUP:
        return FS_SAFE_SILENT;
    case EXEC_SM_STATE_LIMITED:
        return FS_SAFE_COMMINUCATION;
    case EXEC_SM_STATE_RUNNING:
        switch(FSExec_RuningSMCurrentState()){
        case EXEC_RSM_STATE_STARTUP:
            return FS_SAFE_COMMINUCATION;
        case EXEC_RSM_STATE_NORMAL:
            return FS_NORMAL_COMMINUCATION;
        case EXEC_RSM_STATE_IMAGE_OVER_BUS:
            return FS_NORMAL_COMMINUCATION;
        case EXEC_RSM_STATE_CALIBRATION:
            return FS_SAFE_COMMINUCATION;
        }
        /** failsafe */
        return FS_SAFE_SILENT;
    default:
        return FS_SAFE_SILENT;
    }
}

#if FS_OPTION_IMMEDIATELY_CAT2_RESET == 0
bool FSExec_NeedReset(void)
{
    if( s_main_sm.then_op & THEN_RESET ){
        if( s_main_sm.then_remain_time == 0 ){
            return true;
        }
    }
    return false;
}
#endif /* FS_OPTION_IMMEDIATELY_CAT2_RESET */

#define FS_STOP_SEC_CODE_LOCAL
#include "Fs_MemMap.h"

