/******************************************************************************/
/*----------------------------------Includes----------------------------------*/
/******************************************************************************/
#include "fs_mcu.h"
#include "Cdd_Pmc.h"
#include "Os_api.h"
#if FS_FEATURE_CAN_TRCV_CONTROL
#include "CanTrcv_8_Tja1043.h"
#endif 

/******************************************************************************/
/*-----------------------------------Macros-----------------------------------*/
/******************************************************************************/
#define CAN_DEFAULT_DATA_TABLE_SIZE (sizeof(s_can_default_data_table)/sizeof(s_can_default_data_table[0]))

/******************************************************************************/
/*------------------------------TYEP DEFINITION-------------------------------*/
/******************************************************************************/

/******************************************************************************/
/*------------------------------Global variables------------------------------*/
/******************************************************************************/



/******************************************************************************/
/*------------------------------Static variables------------------------------*/
/******************************************************************************/

#define FS_START_SEC_CONST_LOCAL
#include "Fs_MemMap.h"

const struct fs_can_data_t s_can_default_data_table[] = {{0,0,{0}}};

#define FS_STOP_SEC_CONST_LOCAL
#include "Fs_MemMap.h"

#define FS_START_SEC_VAR_CLEARED_LOCAL
#include "Fs_MemMap.h"

#if FS_FEATURE_CAN_TRCV_CONTROL
static CanTrcv_TrcvModeType s_app_request_trcv_mode = CANTRCV_TRCVMODE_SLEEP;
#endif

static bool s_fs_trcv_disabled = true;

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

#if FS_FEATURE_CAN_TRCV_CONTROL
static Std_ReturnType s_update_can_trcv_mode(void)
{   
    FS_LOG_DEBUG("update_can_trcv_mode disabled=%s request mode=%d",s_fs_trcv_disabled?"yes":"no",s_app_request_trcv_mode);
	
    if(s_fs_trcv_disabled)
	{
        (void)CanTrcv_8_Tja1043_SetOpMode(0,CANTRCV_TRCVMODE_STANDBY);
        return E_NOT_OK;
    }
	else
	{
        return CanTrcv_8_Tja1043_SetOpMode(0,s_app_request_trcv_mode);
    }
}
#else 
static Std_ReturnType s_update_can_trcv_mode(void)
{
    /** pass */
    return E_OK;
}
#endif /* FS_FEATURE_CAN_TRCV_CONTROL */

static void s_RequestEcuReset(void)
{
	SuspendAllInterrupts();

	Cdd_Pmc_McuSoftReset();
	
	EnableAllInterrupts();
}

/******************************************************************************/
/*-------------------------Global Function----------------------------------*/
/******************************************************************************/
void FSExec_McuInit(void)
{
#if FS_FEATURE_CAN_TRCV_CONTROL
	s_app_request_trcv_mode = CANTRCV_TRCVMODE_SLEEP;
#endif 
	s_fs_trcv_disabled = true;
}

void FSExec_DisableCan(bool disable)
{
    s_fs_trcv_disabled = disable;
    Std_ReturnType ret = s_update_can_trcv_mode();
    (void)ret;
}

void FSExec_McuReset(void)
{
	FS_LOG_DEBUG("%s","FSExec McuReset");
    FSExec_DisableCan(true);
    s_RequestEcuReset();
}

void FSExec_FillDefaultCanData(uint32_t pduid,uint8_t *data,uint16_t len)
{
	if(len > CAN_DEFAULT_DATA_MAX_SIZE)
	{
		FS_LOG_ERROR("%s","FillDefaultCanData len too large");
		return ;
	}
	for(uint16_t i = 0; i < CAN_DEFAULT_DATA_TABLE_SIZE; i++)
	{
		if( s_can_default_data_table[i].pduid == pduid)
		{
			if(len != s_can_default_data_table[i].len)
			{
				FS_LOG_ERROR("%s","FillDefaultCanData len mismatch");
				/** copy */
				for(uint16_t offset = 0;offset < s_can_default_data_table[i].len; offset++)
				{
					data[offset] = s_can_default_data_table[i].data[offset];
				}
			}
			break;
		}
	}
}

#if FS_FEATURE_CAN_TRCV_CONTROL
Std_ReturnType FSExec_AppSetCanTrcvMode(CanTrcv_TrcvModeType OpMode)
{
    s_app_request_trcv_mode = OpMode;
    return s_update_can_trcv_mode();
}
#endif /* FS_FEATURE_CAN_TRCV_CONTROL */


#define FS_STOP_SEC_CODE_LOCAL
#include "Fs_MemMap.h"


