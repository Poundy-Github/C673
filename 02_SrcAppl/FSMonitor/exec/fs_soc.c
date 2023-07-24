
/******************************************************************************/
/*----------------------------------Includes----------------------------------*/
/******************************************************************************/
#include "fs_soc.h"
#include "Dio.h"
#include "Dio_Cfg.h"
#include "exec/fs_exec.h"

/******************************************************************************/
/*-----------------------------------Macros-----------------------------------*/
/******************************************************************************/
#define SOC_REQUEST_WARMRESET_TIME	200
#define SOC_REQUEST_COLDRESET_TIME	500


/******************************************************************************/
/*------------------------------TYEP DEFINITION-------------------------------*/
/******************************************************************************/

/******************************************************************************/
/*------------------------------Global variables------------------------------*/
/******************************************************************************/

/******************************************************************************/
/*------------------------------Static variables------------------------------*/
/******************************************************************************/
#define FS_START_SEC_VAR_CLEARED_LOCAL
#include "Fs_MemMap.h"

static enum fs_exec_soc_state_t s_current_soc_pwr_state = FS_EXEC_SOC_POWER_UNKNOWN;

static uint16 ui16_Soc_WarmReset_CycCnt = 0;
static uint16 ui16_Soc_ColdReset_CycCnt = 0;

static enum fs_exec_soc_state_t s_Soc_ResetRequestFlag = FS_EXEC_SOC_POWER_UNKNOWN;	

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


static void s_RequestSocpoweroff(void)
{
    Cdd_Pmc_SocPowerOff();
}

static void s_RequestSocpoweron(void)
{
    Cdd_Pmc_SocPowerOn();
}

/*
*perform soc warm reset funcition
*/
static void s_Request_Soc_Warm_ResetPin_Set(uint8 status)
{
	Dio_WriteChannel(DioConf_DioChannel_DIO_DO_MCU_J3_RST_B, status);
}

/*
*perform J3 cold reset funcition
*/
static void s_Request_Soc_Cold_ResetPin_Set(uint8 status)
{
	Dio_WriteChannel(DioConf_DioChannel_DIO_DO_J3_PMIC_8200_PWRON, status);
}

/******************************************************************************/
/*-------------------------Global Function----------------------------------*/
/******************************************************************************/
void FSExec_SocInit(void)
{
 	s_current_soc_pwr_state = FS_EXEC_SOC_POWER_UNKNOWN;
	s_Soc_ResetRequestFlag = FS_EXEC_SOC_POWER_UNKNOWN;
}

void FSExec_SocDeInit(void)
{

}

void FSExec_SocRequestReset(enum fs_exec_soc_state_t state)
{
    //if((FS_EXEC_SOC_WARM_RESET == state) || (FS_EXEC_SOC_COLD_RESET == state))
    //{
        s_Soc_ResetRequestFlag = state;
		s_current_soc_pwr_state = state;
    //}
	//else
	//{
        ///*Do nothing*/
	//}
}

fs_ret_code_t FSExec_SocPowerOff(void)
{
	s_current_soc_pwr_state = FS_EXEC_SOC_POWER_OFF;
	s_RequestSocpoweroff();
    return FS_RET_CODE_OK;
}

fs_ret_code_t FSExec_SocPowerOn(void)
{
	s_current_soc_pwr_state = FS_EXEC_SOC_POWER_ON;
	s_RequestSocpoweron();
    return FS_RET_CODE_OK;
}

/*
* Async Warm Reset Soc Process, It should be called every 5ms
*/
fs_ret_code_t FSExec_SocWarmReset_Async(void)
{
	fs_ret_code_t status = 0;
	
	ui16_Soc_WarmReset_CycCnt++;
	
	if(ui16_Soc_WarmReset_CycCnt == 1)
	{
		s_Request_Soc_Warm_ResetPin_Set(STD_LOW);
	
		s_current_soc_pwr_state = FS_EXEC_SOC_POWER_OFF;
	}
	else if(ui16_Soc_WarmReset_CycCnt > (SOC_REQUEST_WARMRESET_TIME / FSEXEC_MAINFUNCTION_PERIOD))
	{
		s_Request_Soc_Warm_ResetPin_Set(STD_HIGH);
		ui16_Soc_WarmReset_CycCnt = 0;
		s_current_soc_pwr_state = FS_EXEC_SOC_POWER_ON;
		status = 1;
	}
	
	return status;
}

/*
* 		Async Cold Reset Soc Process, It should be called every 5ms
*/
fs_ret_code_t FSExec_SocColdReset_Async(void)
{
	fs_ret_code_t status = 0;
	
	ui16_Soc_ColdReset_CycCnt++;
	
	if(ui16_Soc_ColdReset_CycCnt == 1)
	{
		s_Request_Soc_Cold_ResetPin_Set(STD_LOW);
		s_current_soc_pwr_state = FS_EXEC_SOC_POWER_OFF;
	}
	else if(ui16_Soc_ColdReset_CycCnt > (SOC_REQUEST_COLDRESET_TIME / FSEXEC_MAINFUNCTION_PERIOD))
	{
		s_Request_Soc_Cold_ResetPin_Set(STD_HIGH);
		ui16_Soc_ColdReset_CycCnt = 0;
		s_current_soc_pwr_state = FS_EXEC_SOC_POWER_ON;
		status = 1;
	}
	
	return status;
}

enum fs_exec_soc_state_t FSExec_SocPowerState(void)
{
	return s_current_soc_pwr_state;
}

enum fs_exec_soc_state_t FSExec_SocResetState(void)
{
	return s_Soc_ResetRequestFlag;
}

#define FS_STOP_SEC_CODE_LOCAL
#include "Fs_MemMap.h"

