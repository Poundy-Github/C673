/******************************************************************************/
/*----------------------------------Includes----------------------------------*/
/******************************************************************************/
#include <Rte_FSMonitor.h>
#include "Mcu.h"				/* invoke Mcu_GetRamState() */
#include "Cdd_HeartbeatDet.h" 	/* invoke Cdd_HeartbeatDet_GetDetState() */
#include "IfxDmu_reg.h"
#include "IfxPort_reg.h"
#include "ism/fs_check.h"
#include "Sdc_Diag.h"
#include "WdgM_Cfg.h"
#include "Sdc_SendInterface.h"
#include "Sed_Stubs.h"
#include "Esm.h"


/******************************************************************************/
/*-----------------------------------Macros-----------------------------------*/
/******************************************************************************/
#define CHECKED_RUNTIMECHECK_MAX (sizeof(Fs_RuntimeChecktable)/sizeof(Fs_RuntimeChecktable[0]))

#define CHECKED_REG_MAX (sizeof(StaticConfigRegValueTable)/sizeof(StaticConfigRegValueTable[0]))

#define CHECKED_SOCFAULT_MAX (sizeof(Fs_SocFaultTable)/sizeof(Fs_SocFaultTable[0]))

/******************************************************************************/
/*------------------------------TYEP DEFINITION-------------------------------*/
/******************************************************************************/


/******************************************************************************/
/*------------------------------Global variables------------------------------*/
/******************************************************************************/


/******************************************************************************/
/*-------------------------Function Prototypes--------------------------------*/
/******************************************************************************/
static boolean FsCheck_GetSocErrormapError(uint8_t groupid ,uint8_t bitpos);
static boolean FSCheck_StaticConfigRegCheck(volatile void* const RegAddress, uint32 mask, uint32 expectValue);
static boolean FSCheck_UpdateSpiMonitorFlag(void);
static void FSCheck_SocErrormapResetCheck(void);
static void FSCheck_CameraTempCheck(void);
static void FSCheck_CpuTempLevelCheck(void);
static void FSCheck_SocTempCheck(void);
static void FSCheck_ConfigIORegCheck(void);
static void FSCheck_SpiAliveFlagCheck(void);
static void FsCheck_IpcServersCheck(void);
static void FSCheck_AdcMonitorCheck(void);
static void FSCheck_SocPwmErrorCheck(void);


/******************************************************************************/
/*------------------------------Static variables------------------------------*/
/******************************************************************************/
#define FS_START_SEC_VAR_CLEARED_LOCAL
#include "Fs_MemMap.h"

static boolean FS_WdgSpiAliveFlag = FALSE;
static boolean FS_WdgKeepFeedFlag = FALSE;
static uint8 Fs_runtimeCnt[FS_CHECK_NUM] = {0}; 
static uint8 Fs_SocIpcState = FS_IPC_SERVER_COMM_NORMAL;
static uint8 Fs_IpcReceiveState = 0;
static s_Fs_AdcMonitorInfo_t FSAdcMonitorInfo[FS_ADC_CHANNEL_NUM] = {0};

#define FS_STOP_SEC_VAR_CLEARED_LOCAL
#include "Fs_MemMap.h"


#define FS_START_SEC_CONST_LOCAL
#include "Fs_MemMap.h"
/*
 * Runtime check list
 */
static const s_Fs_RuntimeCheckType_t Fs_RuntimeChecktable[] = 
{
     {TRUE, 5,  &FSCheck_SocErrormapResetCheck , FALSE,                                                 0,                                                  0}
 	,{TRUE, 5,  &FSCheck_CameraTempCheck       ,  TRUE,  WdgMConf_WdgMSupervisedEntity_WdgM_SE_CameraTemp,  WdgMConf_WdgMCheckpoint_WdgMCheckpoint_CameraTemp}
    ,{TRUE, 5,  &FSCheck_CpuTempLevelCheck     , FALSE,                                                 0,                                                  0}
	,{TRUE, 5,  &FSCheck_SocTempCheck          , FALSE,                                                 0,                                                  0}
    ,{TRUE, 50, &FSCheck_ConfigIORegCheck      ,  TRUE,   WdgMConf_WdgMSupervisedEntity_WdgM_SE_ConfigReg,   WdgMConf_WdgMCheckpoint_WdgMCheckpoint_ConfigReg}
    ,{TRUE, 15, &FSCheck_SpiAliveFlagCheck     ,  TRUE,       WdgMConf_WdgMSupervisedEntity_WdgM_SE_AS_HM,       WdgMConf_WdgMCheckpoint_WdgMCheckpoint_AS_HM}
	,{TRUE, 5,  &FsCheck_IpcServersCheck       , FALSE,                                                 0,                                                  0}
	,{TRUE, 5,  &FSCheck_AdcMonitorCheck       ,  TRUE,      WdgMConf_WdgMSupervisedEntity_WdgM_SE_FS_ADC,      WdgMConf_WdgMCheckpoint_WdgMCheckpoint_FS_ADC}
	,{TRUE, 5,  &FSCheck_SocPwmErrorCheck      , FALSE,                                                 0,                                                  0}
};

/*
 * Adc monitor configuration table
 */
static const s_Fs_AdcMonitorCfg_t FSAdcMonitorCfg[FS_ADC_CHANNEL_NUM] = 
{
   {6,   20,  28,   100, 300,   200,   100,     &FSExec_SetUBattRange,          }, /* BattVolt */
   {6,   20,  28,   100, 300,   200,   100,     &FSExec_SetKL15Range,           }, /* IgnVolt */
   {0,   0,   0,    0,     0,     0,     0,     NULL_PTR,                       }, /* OmVolt_1V0 */
   {0,   0,   0,    0,     0,     0,     0,     NULL_PTR,                       }, /* OmVolt_3V3 */
   {-40, 120, 120,  100, 300,   100,   100,     &FSExec_SetMCUTemperature,      }, /* McuExtTemp */
   {-40, 125, 125,  200, 300,   200,   200,     &FSExec_SetSoCTemperatureRange, }, /* SocExtTemp */
   {0,   0,   0,    0,     0,     0,     0,     NULL_PTR,                       }, /* PmicTemp_FS84 */
   {0,   0,   0,    0,     0,     0,     0,     NULL_PTR,                       }, /* PmicTemp_PF8200 */
};
   
/*
 * Register configuration table
 */
static const s_Fs_PortRegvalType_t StaticConfigRegValueTable[] = 
{
    {(uint32*)&P00_IOCR4.U,  0xB8B80000, 0x80800000}, // P0.6 P0.7  IOCR4 Register
    {(uint32*)&P02_IOCR0.U,  0x000000B8, 0x00000000}, // P2.0  IOCR0 Register
    {(uint32*)&P10_IOCR4.U,  0xB8B8B800, 0x80000000}, // P10.5 P10.6 P10.7 IOCR4 Register
    {(uint32*)&P10_IOCR8.U,  0x000000B8, 0x00000000}, // P10.8 IOCR8 Register
    {(uint32*)&P11_IOCR0.U,  0xB8B8B8B8, 0x00008080}, // P11.0 P11.1 P11.2 P11.3 IOCR0 Register
    {(uint32*)&P11_IOCR4.U,  0xB8B8B8B8, 0x00008000}, // P11.4 P11.5 P11.6 P11.7 IOCR4 Register
    {(uint32*)&P11_IOCR8.U,  0xB8B8B8B8, 0x00008000}, // P11.8 P11.9 P11.10 P11.11 IOCR8 Register
    {(uint32*)&P11_IOCR12.U, 0xB800B800, 0x00000000}, // P11.13 P11.15 IOCR12 Register
    {(uint32*)&P14_IOCR0.U,  0xB8B8B800, 0x00008000}, // P14.1 P14.2 P14.3 IOCR0 Register
    {(uint32*)&P14_IOCR4.U,  0x0000B8B8, 0x00000000}, // P14.4 P14.5 IOCR4 Register
    {(uint32*)&P15_IOCR0.U,  0x0000B800, 0x00000000}, // P15.1 IOCR0 Register
    {(uint32*)&P15_IOCR4.U,  0xB8000000, 0x00000000}, // P15.7 IOCR4 Register
    {(uint32*)&P15_IOCR8.U,  0x00000098, 0x00000010}, // P15.8 IOCR8 Register  (output -> input; 0x00000098 -> 0x00000010)
    {(uint32*)&P20_IOCR0.U,  0x00B8B800, 0x00000000}, // P20.1 P20.2 IOCR0 Register
    {(uint32*)&P20_IOCR4.U,  0xB8000000, 0x80000000}, // P20.7 IOCR4 Register
    {(uint32*)&P20_IOCR8.U,  0x0000B8B8, 0x00000080}, // P20.8 P20.9 IOCR8 Register
    {(uint32*)&P23_IOCR0.U,  0x00B8B8B8, 0x00808080}, // P23.0 P23.1 P23.2 IOCR0 Register
    {(uint32*)&P33_IOCR0.U,  0xB8000000, 0x80000000}, // P33.3 IOCR0 Register
    {(uint32*)&P33_IOCR4.U,  0x0000B800, 0x00008000}, // P33.5 IOCR4 Register
    {(uint32*)&P33_IOCR8.U,  0x000000B8, 0x00000080}  // P33.8 IOCR8 Register
};

/*The changes requirments Link to MFC5J3CN15-308*/
static const s_Fs_SocErrorlist_t Fs_SocFaultTable[] = 
{
     /*0*/   {SED_GROUPID_SystemKernelErrMap,  SED_BITPOS_kernel_i2c_ctrl0,                            CAT3}
     /*1*/  ,{SED_GROUPID_SystemKernelErrMap,  SED_BITPOS_kernel_ipu,                                  CAT3}
	 /*2*/	,{SED_GROUPID_SystemKernelErrMap,  SED_BITPOS_kernel_isp_drop,                             CAT3}
	 /*3*/	,{SED_GROUPID_SystemKernelErrMap,  SED_BITPOS_kernel_pym,                                  CAT3}
	 /*4*/	,{SED_GROUPID_SystemKernelErrMap,  SED_BITPOS_kernel_sif0,                                 CAT3}
	 /*5*/	,{SED_GROUPID_SystemKernelErrMap,  SED_BITPOS_kernel_bpu0,                                 CAT3}
	 /*6*/	,{SED_GROUPID_SystemKernelErrMap,  SED_BITPOS_kernel_bpu1,                                 CAT3}
	 /*7*/	,{SED_GROUPID_SystemKernelErrMap,  SED_BITPOS_kernel_spi2,                                 CAT3}
	 /*8*/	,{SED_GROUPID_SystemKernelErrMap,  SED_BITPOS_kernel_emmc,                                 CAT3}
	 /*9*/	,{SED_GROUPID_SystemKernelErrMap,  SED_BITPOS_kernel_cpu_cal_err,                          CAT3}
	 /*10*/	,{SED_GROUPID_SystemKernelErrMap,  SED_BITPOS_kernel_mpu_cnn0_other_err,                   CAT3}
	 /*11*/	,{SED_GROUPID_SystemKernelErrMap,  SED_BITPOS_kernel_mpu_cnn1_other_err,                   CAT3}
	 /*12*/	,{SED_GROUPID_SystemKernelErrMap,  SED_BITPOS_kernel_mpu_vio_m0_err,                       CAT3}
	 /*13*/	,{SED_GROUPID_SystemKernelErrMap,  SED_BITPOS_kernel_mpu_vpu_err,                          CAT3}
	 /*14*/	,{SED_GROUPID_SystemKernelErrMap,  SED_BITPOS_kernel_mpu_vio_m1_err,                       CAT3}
	 /*15*/	,{SED_GROUPID_SystemServiceErrMap, SED_BITPOS_higt_cpu_load,                               CAT3}
	 /*16*/	,{SED_GROUPID_SystemServiceErrMap, SED_BITPOS_higt_cpu_temp,                               CAT3}
     /*17*/	,{SED_GROUPID_SystemServiceErrMap, SED_BITPOS_higt_memory,                                 CAT3}
	 /*18*/	,{SED_GROUPID_SystemServiceErrMap, SED_BITPOS_timesync_init_error,                         CAT3}
	 /*19*/	,{SED_GROUPID_ADASErrMap,          SED_BITPOS_adas_0_diagnose_forward_timeout,             CAT3}
	 /*20*/	,{SED_GROUPID_ADASErrMap,          SED_BITPOS_adas_0_diagnose_forward_block,               CAT3}
	 /*21*/	,{SED_GROUPID_ADASErrMap,          SED_BITPOS_adas_0_diagnose_config,                      CAT3}
	 /*22*/	,{SED_GROUPID_ADASErrMap,          SED_BITPOS_adas_0_diagnose_bpu_task_timeout,            CAT3}
	 /*23*/	,{SED_GROUPID_ADASErrMap,          SED_BITPOS_adas_0_diagnose_bpu_task_abondon,            CAT3}
	 /*24*/	,{SED_GROUPID_ADASErrMap,          SED_BITPOS_adas_0_diagnose_bpu_task_start_fail,         CAT3}
	 /*25*/	,{SED_GROUPID_ADASErrMap,          SED_BITPOS_adas_0_diagnose_forward_order_error,         CAT3}
	 /*26*/	,{SED_GROUPID_SAFETYLIB,           SED_BITPOS_bpu_check,                                   CAT3}
	 /*27*/	,{SED_GROUPID_SAFETYLIB,           SED_BITPOS_RCore_alu_check,                             CAT3}
	 /*28*/	,{SED_GROUPID_SAFETYLIB,           SED_BITPOS_bpu_check_timeout,                           CAT3}
	 /*29*/	,{SED_GROUPID_SAFETYLIB,           SED_BITPOS_ddr_dataline_check,                          CAT3}
	 /*30*/	,{SED_GROUPID_SAFETYLIB,           SED_BITPOS_ddr_dataline_check_timeout,                  CAT3}
	 /*31*/	,{SED_GROUPID_SAFETYLIB,           SED_BITPOS_safe_reg_check,                              CAT3}
	 /*32*/	,{SED_GROUPID_SAFETYLIB,           SED_BITPOS_safe_reg_check_timeout,                      CAT3}
	 /*33*/	,{SED_GROUPID_SAFETYLIB,           SED_BITPOS_soc_temperature_check_timeout,               CAT3}
	 /*34*/	,{SED_GROUPID_SAFETYLIB,           SED_BITPOS_nvm_crc_check,                               CAT3}
	 /*35*/	,{SED_GROUPID_SAFETYLIB,           SED_BITPOS_qa_btwn_acore_check,                         CAT3}
	 /*36*/	,{SED_GROUPID_SAFETYLIB,           SED_BITPOS_qa_btwn_acore_check_timeout,                 CAT3}
};

#define FS_START_SEC_CONST_LOCAL
#include "Fs_MemMap.h"

const volatile uint32 c_Fs_CameraRecoverMaxTime = 60000; //60s

const volatile uint32  c_Fs_CameraRecheckMaxTime = 10000; //10s

const volatile uint32 c_Fs_SocRecoverMaxTime = 60000; //60s

const volatile uint32  c_Fs_SocRecheckMaxTime = 10000; //10s

const volatile uint32 c_Fs_SpiWaitWrongDelayTime = 20000; //20s

const volatile uint32 c_Fs_IpcServerPostDelayTime = 20000; //20s

const volatile uint32 c_Fs_IpcServerRecoveryDelayTime = 1000; //1s

const volatile float32 c_Fs_EspSpdminThsld = 3.0f; //3km/h

const volatile uint8 c_FS_SpiTimeoutMinCnt = 2; 

const volatile uint8 c_Fs_SpiAliveFlagCheckPeriod  = 15; //15ms

const volatile uint16 c_Fs_SocErrorbitRecheckMaxTime = 10000; //10s

const volatile float32 c_Fs_IpcServercheckSpdThsld = 3.0f;

const volatile uint16 c_Fs_HeartTriggerDebounceTime = 300u; //300ms

const volatile float32 c_Fs_SocDeltaTemp = 10.0f; 


#define FS_STOP_SEC_CONST_LOCAL
#include "Fs_MemMap.h"

/******************************************************************************/
/*-------------------------Static Function----------------------------------*/
/******************************************************************************/

#define FS_START_SEC_CODE_LOCAL
#include "Fs_MemMap.h"

/**
 * \functions FsCheck_GetSocErrormapError
 *
 * \brief Used to Get error map infomation of soc according input.
 *
 * \parameters-in groupid,bitpos
 *
 * \parameters-out error status of bit,
 *
 * \return
 *
 * \comments:
 *
 */
static boolean FsCheck_GetSocErrormapError(uint8_t groupid ,uint8_t bitpos)
{
	s_Sdc_SocDiagInfo_Type p_Data;
	boolean b_ErrorSet = FALSE;
    uint16_t ui16_FaultDataCUT = 0;
	uint8_t u16_index_h = 2*(bitpos/16 + 1u); 
	uint8_t u16_index_l = 2*(bitpos/16 + 1u) - 1u; 

    if(groupid <= SED_GROUPID_MAX)
	{
	    (void)Sdc_SendInterface_SocDiagInfo_Read(groupid, &p_Data);

        if(p_Data.FaultDataLength >= u16_index_h)
	    {
            ui16_FaultDataCUT = (p_Data.FaultData[p_Data.FaultDataLength - u16_index_h] << 8u) | (p_Data.FaultData[p_Data.FaultDataLength - u16_index_l]); 
	       
		    b_ErrorSet = (Fs_GetBit(ui16_FaultDataCUT, Fs_GetBitMask(bitpos)) == TRUE);          
		}
		else
		{
             /*Do nothing.*/
		}
	}

	return b_ErrorSet;	
}

static void FSCheck_SocErrormapResetCheck(void)
{ 
    static boolean b_socResetFlag = FALSE;
	static uint32  ui32_recoverTimeCount = 0;
    boolean b_ErrorSts = FALSE;
	
	if(FALSE == b_socResetFlag)
	{
	    for(uint8_t i = 0; i< CHECKED_SOCFAULT_MAX; i++)
		{
			if(((uint8_t)CAT3) == (uint8_t)Fs_SocFaultTable[i].CATtype)
			{
				b_ErrorSts  = FsCheck_GetSocErrormapError(Fs_SocFaultTable[i].groupid, Fs_SocFaultTable[i].bitpos);

				if(TRUE == b_ErrorSts)
				{
				   #if !FS_EXEC_DISABLED
				   Esm_v_Soc_Reset();
				   #endif
				   
				   /* Set reset flag */
                   b_socResetFlag = TRUE; 
				   /* the recovery time clear */
				   ui32_recoverTimeCount = 0;
				}
			}
			else
			{
				/*Do nothing*/
			}
		}	
	}
	else
	{
        /* If the temperature is out of range, start the recovery time. */
        ui32_recoverTimeCount += FSCHECK_MAINFUNCTION_PERIOD;
		/* Recovery time reached,recover CAT3 ERROR, which will try to perform check soc bit error. */
        if(ui32_recoverTimeCount >= c_Fs_SocErrorbitRecheckMaxTime)
		{
            b_socResetFlag = FALSE;
        }
	}
}

/**
 * \functions FSCheck_CameraTempCheck
 *
 * \brief Used to check the camera temperature and report the error information to CAT3
 *
 * \parameters-in none
 *
 * \parameters-out none
 *
 * \return
 *
 * \comments:
 *
 */
static void FSCheck_CameraTempCheck(void)
{
    boolean b_ErrorSts = FALSE;
    static boolean b_outOfRangeFlag = FALSE;
    static uint32  ui32_recoverTimeCount = 0;

    if(FALSE == b_outOfRangeFlag) 
    {
	    b_ErrorSts = FsCheck_GetSocErrormapError(FS_SOC_DIAG_GROUPID_CAMERA ,FS_BITPOS_CAMERA_TEMP_ERROR);
			
	    if(TRUE == b_ErrorSts)
        /* The camera temperature is fault. (bit 5) */
	    {
            /* Report to EXEC, add CAT3 ERROR,which will perform J3 power off.*/
            FSExec_ModuleTempOutOfRange();
            /* Set out of range flag */
            b_outOfRangeFlag = TRUE;
            /* the recovery time clear */
            ui32_recoverTimeCount = 0;
        }
    } 
    else 
    {
        /* If the temperature is out of range, start the recovery time. */
        ui32_recoverTimeCount += FSCHECK_MAINFUNCTION_PERIOD;

        /* Recovery time reached,recover CAT3 ERROR, which will try to perform J3 power on in case of no other errors. */
        if(ui32_recoverTimeCount == c_Fs_CameraRecoverMaxTime)
		{
            FSExec_ModuleTempInRange();
        }
        else if(ui32_recoverTimeCount >= (c_Fs_CameraRecoverMaxTime + c_Fs_CameraRecheckMaxTime))
        {
            b_outOfRangeFlag = FALSE;
        }
		else
		{
            /*Do nothing.*/
		}
    }
}

/**
 * \functions FSCheck_SocHighTempCheck
 *
 * \brief Used to check the cpu temp level error of soc and report the error information to CAT3
 *
 * \parameters-in none
 *
 * \parameters-out none
 *
 * \return
 *
 * \comments:
 *
 */
static void FSCheck_CpuTempLevelCheck(void)
{
    boolean b_ErrorSts = FALSE;
    static boolean b_outOfRangeFlag = FALSE;
    static uint32  ui32_recoverTimeCount = 0;
	
    if(FALSE == b_outOfRangeFlag) 
	{
	    b_ErrorSts = FsCheck_GetSocErrormapError(FS_SOC_DIAG_GROUPID_SYSSERVICE ,FS_BITPOS_CPU_TEMP_LEVEL);

		if(TRUE == b_ErrorSts)
		{
            /* Report to EXEC, add CAT3 ERROR,which will perform soc power off. */
            FSExec_SocInternalTempOutOfRange();
            /* Set out of range flag */
            b_outOfRangeFlag = TRUE;
            /* the recovery time clear */
            ui32_recoverTimeCount = 0;
        }
    } 
    else 
    {
        /* If the temperature is out of range, start the recovery time. */
        ui32_recoverTimeCount += FSCHECK_MAINFUNCTION_PERIOD;

        /* Recovery time(60s) reached,recover CAT3 ERROR, which will try to perform soc power on in case of no other errors. */
        if(ui32_recoverTimeCount == c_Fs_SocRecoverMaxTime) 
		{        
            FSExec_SocInternalTempInRange();
        }	
		/*After Soc power on 10s, shall be restart check High temp. */
        else if(ui32_recoverTimeCount >= (c_Fs_SocRecoverMaxTime + c_Fs_SocRecheckMaxTime))
        {
            b_outOfRangeFlag = FALSE;
        }
		else
	    {
            /*Do nothing.*/
		}
    }
	 
}

/**
 * \functions FSCheck_SocTempCheck
 *
 * \brief Used to check the soc temperature check error of soc and report the error information to CAT3
 *
 * \parameters-in none
 *
 * \parameters-out none
 *
 * \return
 *
 * \comments:
 *
 */
static void FSCheck_SocTempCheck(void)
{
    boolean b_ErrorSts = FALSE;
    static boolean b_outOfRangeFlag = FALSE;
    static float32 f32_oldSocNtcTemp = 0;
	static boolean b_SocPoweron = TRUE;
	static uint32  ui32_recoverTimeCount = 0;
	float32 f32_currentTemp = 0;
	
    if(FALSE == b_outOfRangeFlag)
    {
	    b_ErrorSts = FsCheck_GetSocErrormapError(FS_SOC_DIAG_GROUPID_SAFETYLIB ,FS_BITPOS_SOC_TEMP_CHECK);

		if(TRUE == b_ErrorSts)
		{
			/* Record current NTC temperature of soc */
			(void)FSAdc_ReadChannel(FS_ADC_CHANNEL_TEMP_SOC_EXT, &f32_oldSocNtcTemp);
            /* Report to EXEC, add CAT3 ERROR,which will perform soc power off. */
            FSExec_SocInternalTempOutOfRange();
            /* Set out of range flag */
            b_outOfRangeFlag = TRUE;
			/* Indicate the soc power off */
			b_SocPoweron = FALSE;
        }			
	}
	else
	{
        (void)FSAdc_ReadChannel(FS_ADC_CHANNEL_TEMP_SOC_EXT, &f32_currentTemp);
		
		/* When the NTC delta temp thsld more than 10, shall be do soc power on */
        if(((f32_oldSocNtcTemp - f32_currentTemp) >= c_Fs_SocDeltaTemp) && (FALSE == b_SocPoweron))
        {
            FSExec_SocInternalTempInRange();
			/* Indicate the soc power on */
			b_SocPoweron = TRUE;
	    }
		/*After Soc power on 10s, shall be restart check soc temp.*/
		if(TRUE == b_SocPoweron)
		{
		    if(ui32_recoverTimeCount >= c_Fs_SocRecheckMaxTime)
		    {
		        /* the recovery time clear */
			    ui32_recoverTimeCount = 0;
						
                b_outOfRangeFlag = FALSE;
		    }
		    else
		    {
		        /* If the soc power on, start the recovery time of check sequence. */
                ui32_recoverTimeCount += FSCHECK_MAINFUNCTION_PERIOD;
		    }	
		}
	}

}

/**
 * \functions StaticConfigRegCheck
 *
 * \brief Used to check the config register
 *
 * \parameters-RegAddress: register address
 *
 * \parameters-mask:register mask
 *
 * \parameters-expectValue:register expectvalue,reference to StaticConfigRegValueTable.
 *
 * \return 
 *
 * \comments:
 *
 */
static boolean FSCheck_StaticConfigRegCheck(volatile void* const RegAddress, uint32 mask, uint32 expectValue)
{
    boolean b_CheckResult = TRUE;
    uint32 ui32_RegVal = 0;

    if ((RegAddress) != NULL)
    {
        ui32_RegVal = *((volatile uint32*)RegAddress);

		if (expectValue != (ui32_RegVal & mask))
		{
            b_CheckResult = FALSE;
        }
    }
    else
    {
        /*Do nothing.*/
    }
	
    return b_CheckResult;
}

/**
 * \functions FSCheck_ConfigRegCheck_Main
 *
 * \brief Used to monitor the register
 *
 * \parameters-in none
 *
 * \parameters-out none
 *
 * \return
 *
 * \comments:
 *
 */
static void FSCheck_ConfigIORegCheck(void)
{
    boolean b_CheckResult = TRUE;
	
    for (uint8 i = 0; i < CHECKED_REG_MAX; i++)
	{
        b_CheckResult = FSCheck_StaticConfigRegCheck(StaticConfigRegValueTable[i].addr, StaticConfigRegValueTable[i].mask, StaticConfigRegValueTable[i].expectValue);
		
        if (FALSE == b_CheckResult)
		{
            #if FS_PDO_ENABLED
                g_fs_debug_status.reset_source_fs[g_fs_debug_status.reset_source_fs_count]=FS_RS_REGISTER_CHECK;
                g_fs_debug_status.reset_source_fs_count = (g_fs_debug_status.reset_source_fs_count + 1)% 32;  
                g_fs_debug_status.wdgm_status[7] = i+1;      
            #endif /** FS_PDO_ENABLED */
			
            FS_MCUReset(FS_RESET_SOURCE_FS);
			
            return;
        }
    }
}


/**
 * \functions FSCheck_CheckFS_WdgSpiAliveFlag
 *
 * \brief Spi monitoring interface, vehicle speed and OTA 20 s after startup
 *
 * \parameters-in none
 *
 * \parameters-out ture : we should monitor SPI.(SPI is working and the system is not doing OTA)
 *                 false: we shouldn't monitor SPI(SPI is not working or the system is doing OTA)
 * \return
 *
 * \comments:
 *
 */
static boolean FSCheck_UpdateSpiMonitorFlag(void)
{
    static uint32 b_cancelKeepCnt = 0; // the counter to wait SPI work after J3 power ON
    boolean b_workingFlag = TRUE;
    boolean b_otaFlag = TRUE;
    Com_Receive_EspVehSpd f32_EspSpd = 0.0f;
    
    if(TRUE == FS_WdgKeepFeedFlag) 
    {   
        /* when KeepFeed Flag is TRUE, It means J3 is power off and SPI is not work */
        b_workingFlag = FALSE;
        b_cancelKeepCnt = 0;
    } 
    else if(b_cancelKeepCnt < c_Fs_SpiWaitWrongDelayTime)
    {   
        /* when KeepFeed Flag is FALSE, It means J3 is power ON, wait SPI work */
        b_workingFlag = FALSE;
        b_cancelKeepCnt += c_Fs_SpiAliveFlagCheckPeriod;
    } 
    else 
    {   /* SPI is working, we should monitor SPI  */
        // workingFlag = TRUE;
    }

    /* we don't have API to check OTA status. According to Conti, if vechile speed >= 3.0km/h, OTA will not work  */
    (void)Rte_Read_RP_Fs_Chassis_Data_EspVehSpd_Status_EspVehSpd(&f32_EspSpd);
	
    if(f32_EspSpd >= c_Fs_EspSpdminThsld)
    {
        b_otaFlag = FALSE;
    }
    
    return ((TRUE == b_workingFlag)&&(FALSE == b_otaFlag));
}

/**
 * \functions FSCheck_CheckFS_WdgSpiAliveFlag
 *
 * \brief :flag bit checking and for executing the checkpointreached interface call.
 *
 * \parameters-in none
 *
 * \parameters-out none
 *
 * \return
 *
 * \comments:
 *
 */
static void FSCheck_SpiAliveFlagCheck(void)
{
    static uint32 ui32_spiNotCnt = 0;

    if(TRUE == FSCheck_UpdateSpiMonitorFlag()) // Attention: FSCheck_UpdateSpiMonitorFlag() should be call only 1 times in this task  
    {
        /* J3 is power on for 20s and the vechile speed >= 3km, the SPI is working and OTA is not work, we should monitor SPI */
        if(FS_WdgSpiAliveFlag == TRUE)
        {
            FS_WdgSpiAliveFlag = FALSE;
            ui32_spiNotCnt = 0;
        }
        else
        {
            ui32_spiNotCnt++;
        }
    }
    else
    {
        ui32_spiNotCnt = 0; // reset the counter
    }

    if(c_FS_SpiTimeoutMinCnt <= ui32_spiNotCnt)
    {
        /* SPI is not work for 15ms *2 = 30ms */
        #if FS_PDO_ENABLED
            g_fs_debug_status.reset_source_fs[g_fs_debug_status.reset_source_fs_count]=FS_RS_SPI;
            g_fs_debug_status.reset_source_fs_count = (g_fs_debug_status.reset_source_fs_count + 1)% 32;    
        #endif /** FS_PDO_ENABLED */

		FS_MCUReset(FS_RESET_SOURCE_FS);
		
        ui32_spiNotCnt = 0; // reset the counter
    }
}


/**
 * \functions FsCheck_IpcServersCheck
 *
 * \brief 
 *
 * \parameters-in  NULL
 *                         

 * \parameters-out u8Retval :NULL
 *
 * \return
 *
 * \comments:
 *
 */
static void FsCheck_IpcServersCheck(void)
{
	static uint8 ui8_CurrentIpcState = 0;
	static uint8 ui8_CurrentSocState  = 0;
	static uint16 ui16_IpcRecoveryCountTimer = 0;
	static uint16 ui16_IpcAbnormalCountTimer = 0;
	static enum fs_exec_soc_state_t eCurrentSocState = FS_EXEC_SOC_POWER_UNKNOWN;
	float32 f32_Com_EspSpd = 0.0f;

	eCurrentSocState =  FSExec_SocPowerState();/*Obtain soc ipc communication status*/
	ui8_CurrentIpcState =  FsCheck_IpcServersGetSocState();/*Obtain the soc power supply status of the mcu*/
	/*Check whether the vehicle speed meets the conditions*/
	(void)Rte_Read_RP_Fs_Chassis_Data_EspVehSpd_Status_EspVehSpd(&f32_Com_EspSpd);
	
	if (c_Fs_IpcServercheckSpdThsld > f32_Com_EspSpd)
	{
		ui16_IpcAbnormalCountTimer = 0;  //Reset abnormal timing
	}
	
	/**Power state transition, power on is true /1; Others think it is not powered on (false /0)*/
	if(FS_EXEC_SOC_POWER_UNKNOWN == eCurrentSocState)
	{
		ui8_CurrentSocState = 0;
	} 
	else if (FS_EXEC_SOC_POWER_ON == eCurrentSocState)
	{
		ui8_CurrentSocState = 1;
	}
	else if (FS_EXEC_SOC_POWER_OFF == eCurrentSocState)
	{
		ui8_CurrentSocState = 0;
	}
	else
	{
	}
	/*The ipc status is as expected*/
	if(ui8_CurrentSocState == ui8_CurrentIpcState )
	{
		// soc power on and ipc valid  or soc power off ipc invalid
		if (FS_IPC_SERVER_COMM_NORMAL == ui8_CurrentIpcState)
		{
			FsCheck_IpcServerSetSocState(0);
		}
		ui16_IpcAbnormalCountTimer = 0;
	}
	else 
	{
		/*The ipc status is not as expected*/
		if (FS_IPC_SERVER_COUNT_TIMENR_MAX > ui16_IpcRecoveryCountTimer)
		{
			ui16_IpcAbnormalCountTimer += FSCHECK_MAINFUNCTION_PERIOD ;
		}	 
	}
	/*
	*	Power status and ipc status are not as expected. Timing exceeds 5s
	*/
	if((c_Fs_IpcServerPostDelayTime < ui16_IpcAbnormalCountTimer)&&(FS_IPC_SERVER_COMM_ABNORMAL != Fs_SocIpcState))
	{
		//Report cat3 error 
		FSExec_SoCStatePostFailure();
		ui16_IpcRecoveryCountTimer = 0;
		Fs_SocIpcState  = FS_IPC_SERVER_COMM_ABNORMAL;
	}

	if (FS_IPC_SERVER_COMM_ABNORMAL == Fs_SocIpcState)
	{
		ui16_IpcRecoveryCountTimer += FSCHECK_MAINFUNCTION_PERIOD;
	}
	
	if (c_Fs_IpcServerRecoveryDelayTime < ui16_IpcRecoveryCountTimer)
	{
		/*Request recovery  from cat3  */
		FSExec_SoCStateRecoveryFailure();
		Fs_SocIpcState = FS_IPC_SERVER_COMM_NORMAL;
		ui16_IpcRecoveryCountTimer = 0;
		ui16_IpcAbnormalCountTimer = 0;
	}
	
}
/**
 * \functions FSCheck_AdcMonitorCheck
 *
 * \brief 
 *
 * \parameters-in  NULL
 *                         

 * \parameters-out u8Retval :NULL
 *
 * \return
 *
 * \comments:
 *
 */
static void FSCheck_AdcMonitorCheck(void)
{
    Std_ReturnType Ret;
    uint8 Channel;
    float Value;

    FSAdc_MainFunction();
		
    for(Channel = (uint8)0; Channel < FS_ADC_CHANNEL_NUM; Channel++)
    {
        if(FSAdcMonitorCfg[Channel].Report == NULL_PTR)
        {
            /* current channel do not need monitor */
            continue;
        }

        /* read current channel value */
        Ret = FSAdc_ReadChannel(Channel, &Value);
        if(Ret == FALSE)
        {
            /* current channel value is invalid */
            continue;
        }

        //FS_LOG_DEBUG("channel %d status %d counter %d value %.1f", Channel, FSAdcMonitorInfo[Channel].Status, FSAdcMonitorInfo[Channel].Counter, Value);

        if(Value < FSAdcMonitorCfg[Channel].LowValue)
        {
            /* current channel value is low */
            if(FSAdcMonitorInfo[Channel].Status == FS_ADC_MONITOR_STATUS_LOW)
            {
                /* current status is low, check the time*/
                if(FSAdcMonitorInfo[Channel].Counter >= FSAdcMonitorCfg[Channel].LowCount)
                {
                    /* time arrive, report the status */
                    // FS_LOG_WARNING("channel %d low detect", Channel);
                    FSAdcMonitorCfg[Channel].Report(EXEC_RANGE_LOW);
                }
                else
                {
                    /* time not arrive */
                    FSAdcMonitorInfo[Channel].Counter += FSCHECK_MAINFUNCTION_PERIOD;
                }
            }
            else
            {
                /* current status is not low, change to low*/
                FSAdcMonitorInfo[Channel].Counter = 0U;
                FSAdcMonitorInfo[Channel].Status = FS_ADC_MONITOR_STATUS_LOW;
            }
        }
        else if(Value <= FSAdcMonitorCfg[Channel].High1Value)
        {
            /* current channel value is normal */
            if(FSAdcMonitorInfo[Channel].Status == FS_ADC_MONITOR_STATUS_NORMAL)
            {
                /* current status is normal, check the time*/
                if(FSAdcMonitorInfo[Channel].Counter >= FSAdcMonitorCfg[Channel].NormalCount)
                {
                    /* time arrive, report the status */
                    //FS_LOG_INFO("channel %d normal detect", Channel);
                    FSAdcMonitorCfg[Channel].Report(EXEC_RANGE_NORMAL);
                }
                else
                {
                    /* time not arrive */
                    FSAdcMonitorInfo[Channel].Counter += FSCHECK_MAINFUNCTION_PERIOD;
                }
            }
            else
            {
                /* current status is not normal, change to normal*/
                FSAdcMonitorInfo[Channel].Counter = 0U;
                FSAdcMonitorInfo[Channel].Status = FS_ADC_MONITOR_STATUS_NORMAL;
            }
        }
        else if(Value <= FSAdcMonitorCfg[Channel].High2Value)
        {
            /* current channel value is high1 */
            if(FSAdcMonitorInfo[Channel].Status == FS_ADC_MONITOR_STATUS_HIGH1)
            {
                /* current status is high1, check the time*/
                if(FSAdcMonitorInfo[Channel].Counter >= FSAdcMonitorCfg[Channel].High1Count)
                {
                    /* time arrive, report the status */
                    // FS_LOG_WARNING("channel %d high1 detect", Channel);
                    FSAdcMonitorCfg[Channel].Report(EXEC_RANGE_HIGH);
                }
                else
                {
                    /* time not arrive */
                    FSAdcMonitorInfo[Channel].Counter += FSCHECK_MAINFUNCTION_PERIOD;
                }
            }
            else
            {
                /* current status is not high1, change to high1*/
                FSAdcMonitorInfo[Channel].Counter = 0U;
                FSAdcMonitorInfo[Channel].Status = FS_ADC_MONITOR_STATUS_HIGH1;
            }
        }
        else
        {
            /* current channel value is high2 */
            if(FSAdcMonitorInfo[Channel].Status == FS_ADC_MONITOR_STATUS_HIGH2)
            {
                /* current status is high2, check the time*/
                if(FSAdcMonitorInfo[Channel].Counter >= FSAdcMonitorCfg[Channel].High2Count)
                {
                    /* time arrive, report the status */
                    // FS_LOG_WARNING("channel %d high2 detect", Channel);
                    FSAdcMonitorCfg[Channel].Report(EXEC_RANGE_EXTREM_HIGH);
                }
                else
                {
                    /* time not arrive */
                    FSAdcMonitorInfo[Channel].Counter += FSCHECK_MAINFUNCTION_PERIOD;
                }
            }
            else
            {
                /* current status is not high2, change to high2*/
                FSAdcMonitorInfo[Channel].Counter = 0U;
                FSAdcMonitorInfo[Channel].Status = FS_ADC_MONITOR_STATUS_HIGH2;
            }
        }
    }
}

/**
 * \functions FSCheck_SocPwmErrorCheck
 *
 * \brief 
 *
 * \parameters-in  none
 *                         
 * \parameters-out none
 *
 * \return
 *
 * \comments:
 *
 */
static void FSCheck_SocPwmErrorCheck(void)
{
    Enum_HeartbeatDetDetState e_status;
	static uint32  ui32_TriggerTimeCount = 0;

    e_status = Cdd_HeartbeatDet_GetDetState();
	
	if((HEARTBEATDET_DET_STATE_STARTUPERROR == e_status) || (HEARTBEATDET_DET_STATE_RUNNINGERROR == e_status))
	{   
	    ui32_TriggerTimeCount += FSCHECK_MAINFUNCTION_PERIOD;
		
        if(ui32_TriggerTimeCount % c_Fs_HeartTriggerDebounceTime == 0) //Debounce time 300ms
		{
	        ui32_TriggerTimeCount = 0;

			#if !FS_EXEC_DISABLED	
			Esm_v_Soc_Reset();
			#endif
		}
    }
	else 
	{
        /*Do nothing.*/
	}	
}

/******************************************************************************/
/*-------------------------Global Function----------------------------------*/
/******************************************************************************/
/**
 * \functions FSCheck_InitFunction
 *
 * \brief- init monitor main task
 *
 * \parameters-in none
 *
 * \parameters-out none
 *
 * \return
 *
 * \comments:
 *
 */
void FSCheck_InitFunction(void)
{
    uint8 Channel;

    FS_LOG_INFO("%s", "FS Adc Monitor Init");

    for(Channel = (uint8)0; Channel < FS_ADC_CHANNEL_NUM; Channel++)
    {
        FSAdcMonitorInfo[Channel].Status = FS_ADC_MONITOR_STATUS_INVALID;
        FSAdcMonitorInfo[Channel].Counter = 0U;
    }
}

/**
 * \functions FSCheck_MainFunction
 *
 * \brief- Cycle monitor main task
 *
 * \parameters-in none
 *
 * \parameters-out none
 *
 * \return
 *
 * \comments:
 *
 */
void FSCheck_MainFunction(void) //5ms
{
	for(uint8 i = 0; i < CHECKED_RUNTIMECHECK_MAX; i++)
	{
	    Fs_runtimeCnt[i]++;
		if(Fs_runtimeCnt[i] % (Fs_RuntimeChecktable[i].period/FSCHECK_MAINFUNCTION_PERIOD) == 0)
		{
		    Fs_runtimeCnt[i] = 0;
			
			if(TRUE == Fs_RuntimeChecktable[i].enable)
			{
			    if(Fs_RuntimeChecktable[i].CheckFunc != NULL_PTR)
			    {
                    Fs_RuntimeChecktable[i].CheckFunc();

					if(TRUE == Fs_RuntimeChecktable[i].WdgMenable)
					{
                        (void)WdgM_Rte_CheckpointReached_CORE_0(Fs_RuntimeChecktable[i].SEID, Fs_RuntimeChecktable[i].CheckpointID);
					}	
			    }
			}
		}
	}
}


/**
 * \functions FSCheck_SetSpiAliveFlag
 *
 * \brief call by spi
 *
 * \parameters-in none
 * 
 * \parameters-out none
 *
 * \return
 *
 * \comments:
 *
 */
void FSCheck_SetSpiAliveFlag(void)
{
    FS_WdgSpiAliveFlag = TRUE;
}

/**
 * \functions FSCheck_WdgKeepFeed
 *
 * \brief force feed wdg or not
 *
 * \parameters-in keep_feed - TRUE  : keep feed watch dog
 *                            FALSE : not keep feed watch dog
 * \parameters-out none
 *
 * \return
 *
 * \comments:
 *
 */
void FSCheck_WdgKeepFeed(boolean keep_feed)
{
    FS_WdgKeepFeedFlag = keep_feed;
}

/**
 * \functions FsCheck_IpcServersGetSocState
 *
 * \brief Get the current ipc receive state from spi sequnece
 *
 * \parameters-in keep_feed - TRUE  : keep feed watch dog
 *                            FALSE : not keep feed watch dog
 * \parameters-out none
 *
 * \return
 *
 * \comments:
 *
 */
uint8 FsCheck_IpcServersGetSocState(void)
{
	return Fs_IpcReceiveState ;
}

/**
 * \functions FsCheck_IpcServerSetSocState
 *
 * \brief Set the current ipc receive state in spi recevice sequnece
 *
 * \parameters-in u8State - 0x01  : spi communication normal
 * \parameters-out none
 *
 * \return
 *
 * \comments:
 *
 */
uint8 FsCheck_IpcServerSetSocState(uint8 u8State)
{
	static uint8_t u8Retval = E_OK;

	Fs_IpcReceiveState = u8State;

	return u8Retval;
}


#define FS_STOP_SEC_CODE_LOCAL
#include "Fs_MemMap.h"
