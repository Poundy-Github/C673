/******************************************************************************/
/*----------------------------------Includes----------------------------------*/
/******************************************************************************/
#include "function_safety.h"
#include "exec/fs_exec.h"
#include "exec/fs_mcu.h"
#include "exec/fs_catx.h"
#include "exec/state_machine/exec_main_sm.h"
#include "circular_queue.h"
/* for importing NULL */
#include <stdlib.h>
#include "fs_common.h"
#include "WdgM_Cfg.h"
#include "fs_config.h"
#if FS_FEATURE_CAN_TRCV_CONTROL

#include "CanTrcv_8_Tja1043.h"

#endif
#include "esm/fs_adc.h"
//#include "esm/fs_adc_monitor.h"
#include "ism/fs_check.h"
#include "ism/fs_selfcheck.h"
//#include "ism/fs_IpcServers.h"

#include "fs_pdo.h"

#if FS_PDO_ENABLED
#include <NvM.h>
#include <fls.h>
#include <Fee.h>
#include "Cdm.h"
#include <Rte_FSMonitor.h>
#endif
/******************************************************************************/
/*-----------------------------------Macros-----------------------------------*/
/******************************************************************************/
#define EVENT_QUEUE_SIZE 8 
/******************************************************************************/
/*------------------------------TYEP DEFINITION-------------------------------*/
/******************************************************************************/
struct fs_event_queue_cq_t;
/******************************************************************************/
/*------------------------------Global variables------------------------------*/
/******************************************************************************/

/******************************************************************************/
/*------------------------------Static variables------------------------------*/
/******************************************************************************/
#define FS_START_SEC_CODE_LOCAL
#include "Fs_MemMap.h"

LS_CIRCULAR_QUEUE_GEN_STATIC(fs_event_queue,struct exec_sm_event_t,EVENT_QUEUE_SIZE);

#define FS_STOP_SEC_CODE_LOCAL
#include "Fs_MemMap.h"


#define FS_START_SEC_VAR_CLEARED_LOCAL
#include "Fs_MemMap.h"

static struct fs_event_queue_cq_t s_event_queue = LS_CIRCULAR_QUEUE_INITIALIZER;
static bool s_enter_rte = false;
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

/******************************************************************************/
/*-------------------------Global Function----------------------------------*/
/******************************************************************************/

void FS_MCUReset(enum fs_reset_source_t source)
{
#if FS_PDO_ENABLED
	NvM_RequestResultType Result;
	uint8 NvmDemCycleMax = 0xffu;

    if((source == FS_RESET_SOURCE_WATCH_DOG))
	{
        g_fs_debug_status.reset_source_fs[g_fs_debug_status.reset_source_fs_count]=FS_RS_WATCHDOG;
        g_fs_debug_status.reset_source_fs_count = (g_fs_debug_status.reset_source_fs_count + 1)% 32;  
    }
    g_fs_debug_status.reset_reasonlist[g_fs_debug_status.reset_counter] = (uint8)source;
    g_fs_debug_status.reset_counter = (g_fs_debug_status.reset_counter+1)%8;

    Cdm_WriteBlock(NvMConf_NvMBlockDescriptor_NvM_BLOCK_FS_Debug_Status, &g_fs_debug_status);
	do
	{
	   NvmDemCycleMax--;
	   NvM_MainFunction();
	   Fee_MainFunction();
	   Fls_MainFunction();
	   
	   (void)Cdm_GetErrorStatus(NvMConf_NvMBlockDescriptor_NvM_BLOCK_FS_Debug_Status, &Result);
	}
	while ((Result == NVM_REQ_PENDING) && (NvmDemCycleMax != 0u));
#endif /** FS_PDO_ENABLED */


    bool is_error =  ((source == FS_RESET_SOURCE_WATCH_DOG) ||(source == FS_RESET_SOURCE_FS));

    if(is_error)
	{
        FSCat_Cat2Increase();
        FSCat_SetResetReason(FS_CAT_RESET_REASON_CAT2);
    }
	else
	{
        FSCat_Cat2CountReset();
        FSCat_SetResetReason(FS_CAT_RESET_REASON_RESET);
    }
#if FS_EXEC_DISABLED
    if(is_error)
    {
        return;
    }
#endif /* FS_EXEC_DISABLED */
    FSExec_McuReset();
    
   
}

void FS_SocPwrRequest(bool on_off)
{
    struct exec_sm_event_t event;
    event.id = EXEC_SM_EVENT_SET_SOC_POWER;
    event.params.set_soc_power.on = on_off;
    SuspendAllInterrupts();
    fs_event_queue_enqueue(&s_event_queue,&event);
    ResumeAllInterrupts();
}

const char *FS_FSStateRepr(enum fs_state_t s){
    switch(s){
    case FS_SAFE_SILENT:
        return "FS_SAFE_SILENT";
    case FS_SAFE_COMMINUCATION:
        return "FS_SAFE_COMMINUCATION";
    case FS_NORMAL_COMMINUCATION:
        return "FS_NORMAL_COMMINUCATION";
    default:
        break;
    }
    return "UNKNOWN";

}

enum fs_state_t FS_FSState(void)
{
    return FSExec_CurrentFSState();
}


void FS_Init(void)
{
    FS_LOG_DEBUG("%s","FS Init");
    s_enter_rte = false;
    /** kill unused fn warnings */
    (void)fs_event_queue_ref_enqueue;
    (void)fs_event_queue_ref_dequeue;
    (void)fs_event_queue_ref_get;
    fs_event_queue_init(&s_event_queue);
    /* pass */
    FSExec_Init();
    FSAdc_InitFunction();

}
void FS_RETInit(void)
{
    FS_LOG_DEBUG("%s","FS RTE Init");
    s_enter_rte = true;
    FSAdc_InitFunction();  
    FSCheck_InitFunction();
}

bool FS_HasEnterRTE(void){
    return s_enter_rte;
}

void FS_MainFunction(void)
{
    if(FS_HasEnterRTE())
	{
	    FSCheck_MainFunction();
    }

    FSExec_MainFunction();
	
    while( fs_event_queue_get_length(&s_event_queue) > 0)
	{
        struct exec_sm_event_t event;
        SuspendAllInterrupts();
        fs_event_queue_dequeue(&s_event_queue,&event);
        FSExec_SMPostEvent(&event);
        ResumeAllInterrupts();
    }
    FSExec_Poll(5);
	
    (void)WdgM_Rte_CheckpointReached_CORE_0(WdgMConf_WdgMSupervisedEntity_WdgM_SE_FS_MAIN, WdgMConf_WdgMCheckpoint_WdgMCheckpoint_FS_MAIN);
}


#if FS_FEATURE_CAN_TRCV_CONTROL

/**
 * sed -i "" 's/CanTrcv_8_Tja1043_SetOpMode/FS_CanTrcv_SetOpMode/' output/generated/src/CanIf_Cfg.c
 */ 
Std_ReturnType FS_CanTrcv_SetOpMode(uint8 CanTrcvIndex, CanTrcv_TrcvModeType OpMode)
{
#if FS_EXEC_DISABLED
    return CanTrcv_8_Tja1043_SetOpMode(CanTrcvIndex,OpMode);
#else /* FS_EXEC_DISABLED */
    FS_LOG_DEBUG("CanTrcvSetOpMode %d = %d ",CanTrcvIndex,OpMode);
    if(CanTrcvIndex == 0){
        return FSExec_AppSetCanTrcvMode(OpMode);
    }else{
        return CanTrcv_8_Tja1043_SetOpMode(CanTrcvIndex,OpMode);
    }
#endif  /* FS_EXEC_DISABLED */
}

#endif

#if FS_FEATURE_CAN_DEFAULT_DATA_CONTROL
/**
 * This function is called from modified CanIf.c (inside Eb plugin).
 * To make it work,a patch to CanIf.c must be applied.
*/
void FS_CanIf_SupervisePduData(PduIdType CanTxPduId, PduInfoType *PduInfoPtr)
{
    if(FS_FSState() == FS_SAFE_COMMINUCATION){
        FSExec_FillDefaultCanData(CanTxPduId,PduInfoPtr->SduDataPtr,PduInfoPtr->SduLength);
    }else{
        /** pass */
    }
}


#endif

#define FS_STOP_SEC_CODE_LOCAL
#include "Fs_MemMap.h"
