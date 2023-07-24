/******************************************************************************/
/*----------------------------------Includes----------------------------------*/
/******************************************************************************/
#include <stdbool.h>
#include "exec/fs_exec.h"
#include "state_machine/exec_main_sm.h"
#include "exec/fs_soc.h"
#include "exec/fs_mcu.h"
#include "exec/fs_catx.h"
#include "esm/fs_adc.h"
#include "fs_pdo.h"

/******************************************************************************/
/*-----------------------------------Macros-----------------------------------*/
/******************************************************************************/

/******************************************************************************/
/*------------------------------TYEP DEFINITION-------------------------------*/
/*****************************************x*************************************/

/******************************************************************************/
/*------------------------------Global variables------------------------------*/
/******************************************************************************/

/******************************************************************************/
/*------------------------------Static variables------------------------------*/
/******************************************************************************/
#define FS_START_SEC_VAR_CLEARED_LOCAL
#include "Fs_MemMap.h"


#define FS_STOP_SEC_VAR_CLEARED_LOCAL
#include "Fs_MemMap.h"

/******************************************************************************/
/*-------------------------Function Prototypes--------------------------------*/
/******************************************************************************/

/******************************************************************************/
/*-------------------------Static Function----------------------------------*/
/******************************************************************************/



/******************************************************************************/
/*-------------------------Global Function----------------------------------*/
/******************************************************************************/
#define FS_START_SEC_CODE_LOCAL
#include "Fs_MemMap.h"

void FSExec_Init(void)
{
    /** this is already inited in boot code */
    /* FSCat_Init(); */
	FSExec_McuInit();
    FSExec_SocInit();
    FSExec_SMInit();
}


void FSExec_MainFunction(void) //5ms
{
    uint8 ui8_resetStatus = 0;
	enum fs_exec_soc_state_t SocResetFlag;
	
	SocResetFlag = FSExec_SocResetState();

	if(FS_EXEC_SOC_WARM_RESET == SocResetFlag)
	{
        ui8_resetStatus = FSExec_SocWarmReset_Async();
		if(ui8_resetStatus == 0x01)
		{
            FSExec_SocRequestReset(FS_EXEC_SOC_POWER_ON);
		}
	}
	else if(FS_EXEC_SOC_COLD_RESET == SocResetFlag)
	{
	    ui8_resetStatus = FSExec_SocColdReset_Async();
	    if(ui8_resetStatus == 0x01)
	    {
		    FSExec_SocRequestReset(FS_EXEC_SOC_POWER_ON);
	    }
	}


}

void FSExec_Poll( unsigned  ms )
{
    
#if FS_OPTION_IMMEDIATELY_CAT2_RESET == 0
    if(FSExec_NeedReset())
	{
        /** reset by cat2 */
        FSCat_SetResetReason(FS_CAT_RESET_REASON_CAT2);
        FSExec_McuReset();
    }
#endif

    FSExec_SMPoll(ms);
}

void FSExec_ModuleTempOutOfRange(void)
{
    struct exec_sm_event_t event;
    event.id = EXEC_SM_EVENT_CAT3_POST;
    event.params.cat3_post.error.cat3id = FS_CAT3_MODULE_TEMP_OUT_OF_RANGE;
#if FS_FEATURE_RECORD_DEM
    event.params.cat3_post.error.is_dem = false;
#endif
    FSExec_SMPostEvent(&event);
}

void FSExec_ModuleTempInRange(void)
{
    struct exec_sm_event_t event;
    event.id = EXEC_SM_EVENT_CAT3_RECOVER;
    event.params.cat3_post.error.cat3id = FS_CAT3_MODULE_TEMP_OUT_OF_RANGE;
#if FS_FEATURE_RECORD_DEM
    event.params.cat3_post.error.is_dem = false;
#endif
    FSExec_SMPostEvent(&event);
}

void FSExec_SocInternalTempOutOfRange(void)
{
    struct exec_sm_event_t event;
    event.id = EXEC_SM_EVENT_CAT3_POST;
    event.params.cat3_post.error.cat3id = FS_CAT3_SOC_TEMP_OUT_OF_RANGE;
#if FS_FEATURE_RECORD_DEM
    event.params.cat3_post.error.is_dem = false;
#endif
    FSExec_SMPostEvent(&event);
}

void FSExec_SocInternalTempInRange(void)
{
    struct exec_sm_event_t event;
    event.id = EXEC_SM_EVENT_CAT3_RECOVER;
    event.params.cat3_post.error.cat3id = FS_CAT3_SOC_TEMP_OUT_OF_RANGE;
#if FS_FEATURE_RECORD_DEM
    event.params.cat3_post.error.is_dem = false;
#endif
    FSExec_SMPostEvent(&event);
}

void FSExec_SpiPwmPostFailure(void)
{
    struct exec_sm_event_t event;
    event.id = EXEC_SM_EVENT_CAT3_POST;
    event.params.cat3_post.error.cat3id = FS_CAT3_SOC_PWM_ERROR;
#if FS_FEATURE_RECORD_DEM
    event.params.cat3_post.error.is_dem = true;
#endif
    FSExec_SMPostEvent(&event);
}

void FSExec_SpiPwmRecoveryFailure(void)
{
    struct exec_sm_event_t event;
    event.id = EXEC_SM_EVENT_CAT3_RECOVER;
    event.params.cat3_post.error.cat3id = FS_CAT3_SOC_PWM_ERROR;
#if FS_FEATURE_RECORD_DEM
    event.params.cat3_post.error.is_dem = true;
#endif
    FSExec_SMPostEvent(&event);
}

void FSExec_SoCStatePostFailure(void)
{
    struct exec_sm_event_t event;
    event.id = EXEC_SM_EVENT_CAT3_POST;
    event.params.cat3_post.error.cat3id = FS_CAT3_SOC_STATE_ERROR;
#if FS_FEATURE_RECORD_DEM
    event.params.cat3_post.error.is_dem = false;
#endif
    FSExec_SMPostEvent(&event);
}

void FSExec_SoCStateRecoveryFailure(void)
{
    struct exec_sm_event_t event;
    event.id = EXEC_SM_EVENT_CAT3_RECOVER;
    event.params.cat3_post.error.cat3id = FS_CAT3_SOC_STATE_ERROR;
#if FS_FEATURE_RECORD_DEM
    event.params.cat3_post.error.is_dem = false;
#endif
    FSExec_SMPostEvent(&event);
}

void FSExec_SetSoCTemperatureRange( enum exec_range_t range )
{
    struct exec_sm_event_t event;
    switch(range){
    case EXEC_RANGE_EXTREM_LOW:
    case EXEC_RANGE_LOW:
        event.id = EXEC_SM_EVENT_CAT3_POST;
        event.params.cat3_post.error.cat3id = FS_CAT3_SOC_TEMP_EXT_LOW;
    #if FS_FEATURE_RECORD_DEM
        event.params.cat3_post.error.is_dem = false;
    #endif
        FSExec_SMPostEvent(&event);

        event.id = EXEC_SM_EVENT_CAT3_RECOVER;
        event.params.cat3_post.error.cat3id = FS_CAT3_SOC_TEMP_EXT_HIGH;
    #if FS_FEATURE_RECORD_DEM
        event.params.cat3_post.error.is_dem = true;
    #endif
        FSExec_SMPostEvent(&event);
        break;
    case EXEC_RANGE_NORMAL:
        event.id = EXEC_SM_EVENT_CAT3_RECOVER;
        event.params.cat3_post.error.cat3id = FS_CAT3_SOC_TEMP_EXT_LOW;
    #if FS_FEATURE_RECORD_DEM
        event.params.cat3_post.error.is_dem = false;
    #endif
        FSExec_SMPostEvent(&event);

        event.id = EXEC_SM_EVENT_CAT3_RECOVER;
        event.params.cat3_post.error.cat3id = FS_CAT3_SOC_TEMP_EXT_HIGH;
    #if FS_FEATURE_RECORD_DEM
        event.params.cat3_post.error.is_dem = true;
    #endif
        FSExec_SMPostEvent(&event);
        break;
    case EXEC_RANGE_HIGH:
    case EXEC_RANGE_EXTREM_HIGH:
        event.id = EXEC_SM_EVENT_CAT3_POST;
        event.params.cat3_post.error.cat3id = FS_CAT3_SOC_TEMP_EXT_HIGH;
    #if FS_FEATURE_RECORD_DEM
        event.params.cat3_post.error.is_dem = true;
    #endif
        FSExec_SMPostEvent(&event);

        event.id = EXEC_SM_EVENT_CAT3_RECOVER;
        event.params.cat3_post.error.cat3id = FS_CAT3_SOC_TEMP_EXT_LOW;
    #if FS_FEATURE_RECORD_DEM
        event.params.cat3_post.error.is_dem = false;
    #endif
        FSExec_SMPostEvent(&event);
        break;
    default:
        break;
    }
}

void FSExec_SetUBattRange( enum exec_range_t range )
{
    struct exec_sm_event_t event;
    switch(range){
    case EXEC_RANGE_EXTREM_LOW:
        event.id = EXEC_SM_EVENT_CAT2;
        event.params.cat2.error.cat2id = FS_CAT2_MCU_VMON_BATT_LOW;
        FSExec_SMPostEvent(&event);
        break;
    case EXEC_RANGE_LOW:
        event.id = EXEC_SM_EVENT_CAT3_POST;
        event.params.cat3_post.error.cat3id = FS_CAT3_MCU_VMON_BATT_LOW;
    #if FS_FEATURE_RECORD_DEM
        event.params.cat3_post.error.is_dem = true;
    #endif
        FSExec_SMPostEvent(&event);

        event.id = EXEC_SM_EVENT_CAT3_RECOVER;
        event.params.cat3_post.error.cat3id = FS_CAT3_MCU_VMON_BATT_HIGH;
    #if FS_FEATURE_RECORD_DEM
        event.params.cat3_post.error.is_dem = true;
    #endif
        FSExec_SMPostEvent(&event);
        break;
    case EXEC_RANGE_NORMAL:
        event.id = EXEC_SM_EVENT_CAT3_RECOVER;
        event.params.cat3_post.error.cat3id = FS_CAT3_MCU_VMON_BATT_LOW;
    #if FS_FEATURE_RECORD_DEM
        event.params.cat3_post.error.is_dem = true;
    #endif
        FSExec_SMPostEvent(&event);

        event.id = EXEC_SM_EVENT_CAT3_RECOVER;
        event.params.cat3_post.error.cat3id = FS_CAT3_MCU_VMON_BATT_HIGH;
    #if FS_FEATURE_RECORD_DEM
        event.params.cat3_post.error.is_dem = true;
    #endif
        FSExec_SMPostEvent(&event);
        break;
    case EXEC_RANGE_HIGH:
        event.id = EXEC_SM_EVENT_CAT3_POST;
        event.params.cat3_post.error.cat3id = FS_CAT3_MCU_VMON_BATT_HIGH;
    #if FS_FEATURE_RECORD_DEM
        event.params.cat3_post.error.is_dem = true;
    #endif
        FSExec_SMPostEvent(&event);

        event.id = EXEC_SM_EVENT_CAT3_RECOVER;
        event.params.cat3_post.error.cat3id = FS_CAT3_MCU_VMON_BATT_LOW;
    #if FS_FEATURE_RECORD_DEM
        event.params.cat3_post.error.is_dem = true;
    #endif
        FSExec_SMPostEvent(&event);
        break;
    case EXEC_RANGE_EXTREM_HIGH:        
        event.id = EXEC_SM_EVENT_CAT2;
        event.params.cat2.error.cat2id = FS_CAT2_MCU_VMON_BATT_HIGH;
        FSExec_SMPostEvent(&event);
        break;
    default:
        break;
    }
}

void FSExec_SetMCUTemperature( enum exec_range_t range )
{
    struct exec_sm_event_t event;
    switch(range){
    case EXEC_RANGE_EXTREM_LOW:
    case EXEC_RANGE_LOW:
        event.id = EXEC_SM_EVENT_CAT2;
        event.params.cat2.error.cat2id = FS_CAT2_MCU_TEMP_EXT_LOW;
        FSExec_SMPostEvent(&event);
        break;
    case EXEC_RANGE_NORMAL:
        break;
    case EXEC_RANGE_HIGH:
    case EXEC_RANGE_EXTREM_HIGH:        
        event.id = EXEC_SM_EVENT_CAT2;
        event.params.cat2.error.cat2id = FS_CAT2_MCU_TEMP_EXT_HIGH;
        FSExec_SMPostEvent(&event);
        break;
    default:
        break;
    }
}

void FSExec_SetKL15Range( enum exec_range_t range )
{    
    switch(range){
    case EXEC_RANGE_EXTREM_LOW:
    case EXEC_RANGE_LOW:
        FSCat_Cat2CountReset();
        break;
    case EXEC_RANGE_NORMAL:
    case EXEC_RANGE_HIGH:
    case EXEC_RANGE_EXTREM_HIGH:        
        break;
    default:
        break;
    }
}

void FSExec_FinishSelfTest(fs_self_test_error_flag_t error_flags)
{
     struct exec_sm_event_t event;
#if FS_PDO_ENABLED
    if(error_flags != 0)
    {
        g_fs_debug_status.selfcheck_result[g_fs_debug_status.selfcheck_result_count]=error_flags;
        g_fs_debug_status.selfcheck_result_count = (g_fs_debug_status.selfcheck_result_count + 1)% 8;
    }
#endif /** FS_PDO_ENABLED */

#if FS_EXEC_DISABLED
    error_flags = 0;
#endif 
    if(error_flags == 0)
	{      
        event.id = EXEC_SM_EVENT_SELF_TEST_FINISH;
    }
	else
	{
        FS_LOG_DEBUG("fs selftest error=%x",error_flags);
        event.id = EXEC_SM_EVENT_CAT2;
		
        if( error_flags & FS_SELF_TEST_ERROR_FLAG_UBATT_HIGHT )
		{
            event.params.cat2.error.cat2id = FS_CAT2_MCU_VMON_BATT_HIGH;
        }
        else if( error_flags & FS_SELF_TEST_ERROR_FLAG_UBATT_LOW )
		{
            event.params.cat2.error.cat2id = FS_CAT2_MCU_VMON_BATT_LOW;
        }
        else if( error_flags & FS_SELF_TEST_ERROR_FLAG_MCUTEMP_HIGH )
		{
            event.params.cat2.error.cat2id = FS_CAT2_MCU_TEMP_EXT_HIGH;
        }
        else if( error_flags & FS_SELF_TEST_ERROR_FLAG_MCUTEMP_LOW )
		{
            event.params.cat2.error.cat2id = FS_CAT2_MCU_TEMP_EXT_LOW;
        }
        #if 0
        else if( error_flags & FS_SELF_TEST_ERROR_FLAG_RAM )
		{
            event.params.cat2.error.cat2id = 0;
        }
        else if( error_flags & FS_SELF_TEST_ERROR_FLAG_DATA_FLASH )
		{
            event.params.cat2.error.cat2id = 0;
        }
        #endif
        else if( error_flags & FS_SELF_TEST_ERROR_FLAG_WDG )
		{
            event.params.cat2.error.cat2id = 0;
        }
        else if( error_flags & FS_SELF_TEST_ERROR_FLAG_COM )
		{
            event.params.cat2.error.cat2id = 0;
        }
    }

	FSExec_SMPostEvent(&event);
}

#define FS_STOP_SEC_CODE_LOCAL
#include "Fs_MemMap.h"

