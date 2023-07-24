/**
 * \file   Cdd_Pmc.c
 *
 * \brief  configuration and control power mode for all HSI.
 *
 * \version refer the Cdd_Pmc.h.
 *
 * \copyright  2022 - 2023 Conti Smart Core
 *
 */
/*==================[inclusions]============================================*/
#include "Cdd_Pmc.h"
#include "Cdd_Sbc_Cfg.h"
#include "IfxStm_reg.h"
#include "IfxSrc_reg.h"
#include "IfxScu_reg.h"
#include "IfxPms_reg.h"
#include "Mcu.h"
#include "CanTrcv_8_Tja1043.h"
#include "Dio.h"
//#include "Print.h"

/*==================[internal data]=========================================*/


/*==================[internal function declarations]========================*/
static uint32 Get_Fstm(void);
static uint32 Get_Counter_Value(const uint32 reqTime, const uint8 unitOfReqTime);


/*==================[external function definitions]=========================*/
/*******************************************************************************
** Syntax           : Cdd_Pmc_GetPmicIOState()                                **
**                                                                            **
** Service ID       : none                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : non - reentrant                                         **
**                                                                            **
** Parameters(in)   : none                                                    **
**                                                                            **
** Parameters (out) : none                                                    **
**                                                                            **
** Return value     : none                                                    **
**                                                                            **
** Description      : This function reuqest to get port state of all PMIC.    **
**                                                                            **
**                                                                            **
*******************************************************************************/
s_Pmc_PmicIOState_t Cdd_Pmc_GetPmicIOState(void)
{
    s_Pmc_PmicIOState_t s_PmicIOState;
    
    s_PmicIOState.Fs84_FS0B =  Dio_ReadChannel(DioConf_DioChannel_DIO_DI_PMIC_FS84_FS0_B);
    s_PmicIOState.Fs84_PG =  Dio_ReadChannel(DioConf_DioChannel_DIO_DI_PMIC_FS84_PG);
    s_PmicIOState.Pf50_PG = Dio_ReadChannel(DioConf_DioChannel_DIO_DI_J3_PMIC_5024_PG);
    s_PmicIOState.Pf50_PG1 = Dio_ReadChannel(DioConf_DioChannel_DIO_DI_B2_Sample_J3_PMIC_5024_PG1);
    s_PmicIOState.Pf50_PG3 = Dio_ReadChannel(DioConf_DioChannel_DIO_DI_B2_Sample_J3_PMIC_5024_PG3);
    s_PmicIOState.Pf50_RSTOut = Dio_ReadChannel(DioConf_DioChannel_DIO_DI_J3_PMIC_5024_RST_OUT);
    s_PmicIOState.Pf82_EWARN = Dio_ReadChannel(DioConf_DioChannel_DIO_DI_J3_PMIC_8200_EWARN);
    s_PmicIOState.Pf82_FS0B = Dio_ReadChannel(DioConf_DioChannel_DIO_DI_J3_PMIC_8200_FS0B);
    s_PmicIOState.Pf82_INTB = Dio_ReadChannel(DioConf_DioChannel_DIO_DI_J3_PMIC_8200_INTB);
    s_PmicIOState.Pf82_PG = Dio_ReadChannel(DioConf_DioChannel_DIO_DI_J3_PMIC_8200_PG);
    s_PmicIOState.Pf82_RSTOut = Dio_ReadChannel(DioConf_DioChannel_DIO_DI_J3_PMIC_8200_RST_OUT);

    return s_PmicIOState;
}

/*******************************************************************************
** Syntax           : Pmc_ReadSocState()                                      **
**                                                                            **
** Service ID       : none                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : non - reentrant                                         **
**                                                                            **
** Parameters(in)   : none                                                    **
**                                                                            **
** Parameters (out) : none                                                    **
**                                                                            **
** Return value     : none                                                    **
**                                                                            **
** Description      : This function reuqest to read the state of Soc.         **
**                                                                            **
**                                                                            **
*******************************************************************************/
uint8 Cdd_Pmc_ReadSocState(void)
{
    uint8 u8_RetVal = E_OK;
	
	Dio_LevelType u_PF8200level,u_PF5024level; /* PRQA S 2211,1 # 2023-07-17 Z.J.L:not any affect: accept */

    u_PF8200level =Dio_ReadChannel(DioConf_DioChannel_DIO_DI_J3_PMIC_8200_PG);
    u_PF5024level =Dio_ReadChannel(DioConf_DioChannel_DIO_DI_J3_PMIC_5024_PG);

	if((STD_HIGH == u_PF8200level) && (STD_HIGH == u_PF5024level))
	{
        u8_RetVal = E_OK;
	}
	else
	{
        u8_RetVal = E_NOT_OK;
	}
	return u8_RetVal;
}
/*******************************************************************************
** Syntax           : Pmc_CanTrvGotoSleep()                                   **
**                                                                            **
** Service ID       : none                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : non - reentrant                                         **
**                                                                            **
** Parameters(in)   : none                                                    **
**                                                                            **
** Parameters (out) : none                                                    **
**                                                                            **
** Return value     : none                                                    **
**                                                                            **
** Description      : This function reuqest Can trcviver go to sleep mode     **
**                                                                            **
**                                                                            **
*******************************************************************************/
void Cdd_Pmc_CanTrvGotoSleep(void)
{
    (void)CanTrcv_Tja1043_SetOpMode(0,CANTRCV_TRCVMODE_STANDBY);
    (void)CanTrcv_Tja1043_SetOpMode(0,CANTRCV_TRCVMODE_SLEEP);
}

/*******************************************************************************
** Syntax           : Pmc_PmicDisable()                                      **
**                                                                            **
** Service ID       : none                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : non - reentrant                                         **
**                                                                            **
** Parameters(in)   : none                                                    **
**                                                                            **
** Parameters (out) : none                                                    **
**                                                                            **
** Return value     : none                                                    **
**                                                                            **
** Description      : This function reuqest PMIC disable                      **
**                                                                            **
**                                                                            **
*******************************************************************************/
void Cdd_Pmc_PmicDisable(void)
{  
    //Refresh wd make sure the WD refresh time in 256ms.
    (void)FS8x_WD_Refresh(&fs8400drvData); /* PRQA S 0431,8 # 2023-07-17 Z.J.L:not any affect: accept */
	//FS8435 goto INITFS function
	(void)GOTO_INITFS(&fs8400drvData);/* PRQA S 0431,8 # 2023-07-17 Z.J.L:not any affect: accept */
	//FS8435 disable WD ,allow bootloader to download.
	(void)Disable_WD(&fs8400drvData);/* PRQA S 0431,8 # 2023-07-17 Z.J.L:not any affect: accept */	
	//FS8435 first WD refesh and exit INITFS
	(void)sbcInitClose(&fs8400drvData);	/* PRQA S 0431,8 # 2023-07-17 Z.J.L:not any affect: accept */
}

/*******************************************************************************
** Syntax           : Pmc_MCUHardReset()                                      **
**                                                                            **
** Service ID       : none                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : non - reentrant                                         **
**                                                                            **
** Parameters(in)   : none                                                    **
**                                                                            **
** Parameters (out) : none                                                    **
**                                                                            **
** Return value     : none                                                    **
**                                                                            **
** Description      : This function reuqest hardware reset of MCU             **
**                                                                            **
**                                                                            **
*******************************************************************************/
void Cdd_Pmc_McuHardReset(void)
{
    //Refresh wd make sure the WD refresh time in 256ms.
	(void)FS8x_WD_Refresh(&fs8400drvData);/* PRQA S 0431,8 # 2023-07-17 Z.J.L:not any affect: accept */
	//FS8435 goto INITFS function
	(void)GOTO_INITFS(&fs8400drvData);/* PRQA S 0431,8 # 2023-07-17 Z.J.L:not any affect: accept */	
	(void)Goto_Standby(&fs8400drvData);/* PRQA S 0431,8 # 2023-07-17 Z.J.L:not any affect: accept */
}

/*******************************************************************************
** Syntax           : Pmc_MCUSoftReset()                                      **
**                                                                            **
** Service ID       : none                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : non - reentrant                                         **
**                                                                            **
** Parameters(in)   : none                                                    **
**                                                                            **
** Parameters (out) : none                                                    **
**                                                                            **
** Return value     : none                                                    **
**                                                                            **
** Description      : This function reuqest software reset of MCU             **
**                                                                            **
**                                                                            **
*******************************************************************************/
void Cdd_Pmc_McuSoftReset(void)
{
	(void)FS8x_WD_Refresh(&fs8400drvData);/* PRQA S 0431,8 # 2023-07-17 Z.J.L:not any affect: accept */	
	(void)GOTO_INITFS(&fs8400drvData);/* PRQA S 0431,8 # 2023-07-17 Z.J.L:not any affect: accept */		
	(void)Disable_WD(&fs8400drvData);/* PRQA S 0431,8 # 2023-07-17 Z.J.L:not any affect: accept */		
	(void)sbcInitClose(&fs8400drvData);/* PRQA S 0431,8 # 2023-07-17 Z.J.L:not any affect: accept */	
	Mcu_PerformReset();				
}
/*******************************************************************************
** Syntax           : Pmc_CamPowerOff()                                       **
**                                                                            **
** Service ID       : none                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : non - reentrant                                         **
**                                                                            **
** Parameters(in)   : none                                                    **
**                                                                            **
** Parameters (out) : none                                                    **
**                                                                            **
** Return value     : none                                                    **
**                                                                            **
** Description      : This function reuqest camera power off                  **
**                                                                            **
**                                                                            **
*******************************************************************************/
void Cdd_Pmc_CamPowerOff(void)
{
	Dio_WriteChannel(DioConf_DioChannel_DIO_DO_PWR_EN_2V9_OM, STD_LOW);
}

/*******************************************************************************
** Syntax           : Pmc_CamPowerOn()                                        **
**                                                                            **
** Service ID       : none                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : non - reentrant                                         **
**                                                                            **
** Parameters(in)   : none                                                    **
**                                                                            **
** Parameters (out) : none                                                    **
**                                                                            **
** Return value     : none                                                    **
**                                                                            **
** Description      : This function reuqest camera power on                   **
**                                                                            **
**                                                                            **
*******************************************************************************/
void Cdd_Pmc_CamPowerOn(void)
{
    Dio_WriteChannel(DioConf_DioChannel_DIO_DO_PWR_EN_2V9_OM, STD_HIGH);
}

/*******************************************************************************
** Syntax           : Pmc_SocHardReset()                                      **
**                                                                            **
** Service ID       : none                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : non - reentrant                                         **
**                                                                            **
** Parameters(in)   : none                                                    **
**                                                                            **
** Parameters (out) : none                                                    **
**                                                                            **
** Return value     : none                                                    **
**                                                                            **
** Description      : This function reuqest soc to execute Hardware reset     **
**                                                                            **
**                                                                            **
*******************************************************************************/
void Cdd_Pmc_SocHardReset(void)
{
	Dio_LevelType u_PF8200level = STD_LOW;
	Dio_LevelType u_PF5024level = STD_LOW;
	
	uint32 u_counter; /* PRQA S 2211,1 # 2023-07-17 Z.J.L:not any affect: accept */
	
	Dio_WriteChannel(DioConf_DioChannel_DIO_DO_MCU_J3_RST_B, STD_LOW);
	Dio_WriteChannel(DioConf_DioChannel_DIO_DO_J3_PMIC_8200_PWRON, STD_LOW);
	
	for(u_counter = 0; u_counter <= (uint32)SOCRESET_CNT;u_counter++)
	{
		if(u_counter == (uint32)SOCRESET_CNT)
		{
				u_PF8200level =Dio_ReadChannel(DioConf_DioChannel_DIO_DI_J3_PMIC_8200_PG);
				u_PF5024level =Dio_ReadChannel(DioConf_DioChannel_DIO_DI_J3_PMIC_5024_PG);
		}	  
	}
	
	if((u_PF8200level == STD_HIGH)&&(u_PF5024level== STD_HIGH))
	{
	    /*Do nothing*/
	}
	else  //Reset successful
	{ 
		Dio_WriteChannel(DioConf_DioChannel_DIO_DO_J3_PMIC_8200_PWRON, STD_HIGH);
		Dio_WriteChannel(DioConf_DioChannel_DIO_DO_MCU_J3_RST_B, STD_HIGH);
		/*After PF8200 enters OFF Mode, the configuration of AMUX will be reset and needs to be re-initialized*/
		(void)PF8X_SetAmux(&pf8200drvData,true,PF8X_F_AMUX_SEL_TEMP_IC); /* PRQA S 0431,8 # 2023-07-17 Z.J.L:not any affect: accept */
		/*Readback can be used to check if the configuration was successful */
		//PF8X_ReadRegister(&pf8200drvData,PF8X_AMUX_ADDR,&u8_PF8X_AMUX_RxData);
	}	
}
/*******************************************************************************
** Syntax           : Pmc_ReadSocShutDownState()                              **
**                                                                            **
** Service ID       : none                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : non - reentrant                                         **
**                                                                            **
** Parameters(in)   : none                                                    **
**                                                                            **
** Parameters (out) : none                                                    **
**                                                                            **
** Return value     : none                                                    **
**                                                                            **
** Description      : This function reuqest to get soc safety shutdown        **
**                    infdication                                             **
**                                                                            **
*******************************************************************************/
uint8 Cdd_Pmc_ReadSocShutDownState(void)
{
    Dio_LevelType u8_Diosts;
	
	u8_Diosts = Dio_ReadChannel(DioConf_DioChannel_DIO_DO_MCU_P1508_J3_GPIO117);

    return u8_Diosts;
}
/*******************************************************************************
** Syntax           : Pmc_SocPowerOff()                                        **
**                                                                            **
** Service ID       : none                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : non - reentrant                                         **
**                                                                            **
** Parameters(in)   : none                                                    **
**                                                                            **
** Parameters (out) : none                                                    **
**                                                                            **
** Return value     : none                                                    **
**                                                                            **
** Description      : This function reuqest soc power off                     **
**                                                                            **
*******************************************************************************/
void Cdd_Pmc_SocPowerOff(void)
{
	Dio_WriteChannel(DioConf_DioChannel_DIO_DO_MCU_J3_RST_B, STD_LOW);
	Dio_WriteChannel(DioConf_DioChannel_DIO_DO_J3_PMIC_8200_PWRON, STD_LOW); 
}

/*******************************************************************************
** Syntax           : Pmc_SocPowerOn()                                        **
**                                                                            **
** Service ID       : none                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : non - reentrant                                         **
**                                                                            **
** Parameters(in)   : none                                                    **
**                                                                            **
** Parameters (out) : none                                                    **
**                                                                            **
** Return value     : none                                                    **
**                                                                            **
** Description      : This function reuqest soc power on                      **
**                                                                            **
*******************************************************************************/
void Cdd_Pmc_SocPowerOn(void)
{
	Dio_WriteChannel(DioConf_DioChannel_DIO_DO_J3_PMIC_8200_PWRON, STD_HIGH);
	Dio_WriteChannel(DioConf_DioChannel_DIO_DO_MCU_J3_RST_B, STD_HIGH);
	/*After PF8200 enters OFF Mode, the configuration of AMUX will be reset and needs to be re-initialized*/
	(void)PF8X_SetAmux(&pf8200drvData,true,PF8X_F_AMUX_SEL_TEMP_IC);/* PRQA S 0431,8 # 2023-07-17 Z.J.L:not any affect: accept */
}

/*******************************************************************************
** Syntax           : void Timer_DelayMs(uint32 ReqTime)                      **
**                                                                            **
** Service ID       : none                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : non - reentrant                                         **
**                                                                            **
** Parameters(in)   : none                                                    **
**                                                                            **
** Parameters (out) : none                                                    **
**                                                                            **
** Return value     : none                                                    **
**                                                                            **
** Description      : This function introduces a delay of ReqTimeMs in        **
**                      milli seconds                                         **
*******************************************************************************/
/*Warning: Please do not call this function in cycle task*/
void Timer_DelayMs(const uint32 ReqTimeMs)
{
  volatile uint32 ReadStm;
  uint32 Delay_Count, Delay_Compare_Count; /* PRQA S 2211,1 # 2023-07-17 Z.J.L:not any affect: accept */

  Delay_Count = Get_Counter_Value(ReqTimeMs, TIMER_MS);

  ReadStm = STM0_TIM0.U; /* PRQA S 0303,2 # 2023-07-17 Z.J.L:not any affect: accept */
	  
  if((MAX_STM_VALUE - ReadStm) > Delay_Count) /* PRQA S 3383,3416,3 # 2023-07-17 Z.J.L:The value is get from register not any affect: accept */
  {
      Delay_Compare_Count = Delay_Count + STM0_TIM0.U;/* PRQA S 3383,0303,2 # 2023-07-17 Z.J.L:not any affect: accept */
  }
  else
  {
      Delay_Compare_Count = Delay_Count - (MAX_STM_VALUE - ReadStm);/* PRQA S 3383,3871,4461,2 # 2023-07-17 Z.J.L:not any affect: accept */
      /*Waiting till the timer overflows */
      while( Delay_Compare_Count <= ReadStm) /* PRQA S 3416,3 # 2023-07-17 Z.J.L:The value is get from register not any affect: accept */
      {
          ReadStm = STM0_TIM0.U;/* PRQA S 0303,2 # 2023-07-17 Z.J.L:not any affect: accept */
      }
  }
	  
  while( Delay_Compare_Count >= ReadStm) /* PRQA S 3416,3 # 2023-07-17 Z.J.L:The value is get from register not any affect: accept */
  {
      ReadStm = STM0_TIM0.U;/* PRQA S 0303,2 # 2023-07-17 Z.J.L:not any affect: accept */
  }
 }



/*******************************************************************************
** Syntax           : Pmc_Init                                                **
**                                                                            **
** Service ID       : none                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : non - reentrant                                         **
**                                                                            **
** Parameters(in)   : none                                                    **
**                                                                            **
** Parameters (out) : none                                                    **
**                                                                            **
** Return value     : none                                                    **
**                                                                            **
** Description      : This function shall be enable PMIC and Power on pin     **
**                     in startup sequence
**                                                                            **
*******************************************************************************/
void Cdd_Pmc_Init(void)
{
    uint8 u8_ErrorCnt =0;
    /*Set pin  to high of original system power.*/
	Dio_WriteChannel(DioConf_DioChannel_DIO_DO_SYS_OFF_B, STD_HIGH);

    /*FS8435 watchdog init*/
	(void)FS8x_WD_Refresh(&fs8400drvData);	/* PRQA S 0431,8 # 2023-07-17 Z.J.L:not any affect: accept */
	(void)GOTO_INITFS(&fs8400drvData);		/* PRQA S 0431,8 # 2023-07-17 Z.J.L:not any affect: accept */
	/*Configure wd window to disable*/
    (void)sbcInitStart(&fs8400drvData); /* PRQA S 0431,8 # 2023-07-17 Z.J.L:not any affect: accept */
    (void)sbcInitClose(&fs8400drvData);/* PRQA S 0431,8 # 2023-07-17 Z.J.L:not any affect: accept */
    
	 /* Watchdog configuration - WD disabled, disabled in Standby mode, 1024 ms window. */
	(void)PF502X_SetWatchdogConfig(&pf5024drvData, false, false, PF502X_F_WD_DURATION_1024_MS, PF502X_F_WD_MAX_EXPIRE_7, PF502X_F_WD_MAX_CNT_15);/* PRQA S 0303,2 # 2023-07-17 Z.J.L:not any affect: accept */
	(void)PF8X_SetWatchdogConfig(&pf8200drvData, false, false, PF8X_F_WD_DURATION_1024_MS, PF8X_F_WD_MAX_EXPIRE_7, PF8X_F_WD_MAX_CNT_15);/* PRQA S 0431,8 # 2023-07-17 Z.J.L:not any affect: accept */

	Timer_DelayMs(TIMER_2MS);
	(void)FS8x_SetRegulatorState(&fs8400drvData, fs8xLdo2, true);/* PRQA S 0431,8 # 2023-07-17 Z.J.L:not any affect: accept */
	Timer_DelayMs(TIMER_2MS);
	(void)FS8x_SetRegulatorState(&fs8400drvData, fs8xLdo1, true);/* PRQA S 0431,8 # 2023-07-17 Z.J.L:not any affect: accept */
	Timer_DelayMs(TIMER_2MS);
	(void)FS8x_SetRegulatorState(&fs8400drvData, fs8xBuck2, true);/* PRQA S 0431,8 # 2023-07-17 Z.J.L:not any affect: accept */

    /*Reduce FS_Cnt to 0 by feeding the watchdog-----Temporary writing,Functional safety should be removed*/
	(void)FS8x_GetFaultErrorCounterValue(&fs8400drvData,&u8_ErrorCnt);/* PRQA S 0431,8 # 2023-07-17 Z.J.L:not any affect: accept */
    
	for(uint8 i = 0;i <= (uint8)(PMIC_WDGCNT * u8_ErrorCnt);i++)
	{
		(void)FS8x_WD_Refresh(&fs8400drvData);/* PRQA S 0431,8 # 2023-07-17 Z.J.L:not any affect: accept */
	}
    /* Try to release the FS0b pin. */
	(void)FS8x_FS0B_Release(&fs8400drvData);/* PRQA S 0431,8 # 2023-07-17 Z.J.L:not any affect: accept */

    (void)FS8x_SwitchAMUXchannel(&fs8400drvData,fs8xAmuxTempSensor); /* PRQA S 0431,8 # 2023-07-17 Z.J.L:not any affect: accept */
    Timer_DelayMs(TIMER_2MS);
	Dio_WriteChannel(DioConf_DioChannel_DIO_DO_PWR_EN_2V9_OM, STD_HIGH); //Camera
    Timer_DelayMs(TIMER_2MS);
	Dio_WriteChannel(DioConf_DioChannel_DIO_DO_PWR_EN_1V0_GEPHY, STD_HIGH); //Eth
	/*************************ISR enable*************************************************/
    //CAN1 BUS OFF
	SRC_CAN1INT6.B.SRE = 1;  /* PRQA S 0303,2 # 2023-07-17 Z.J.L:not any affect: accept */
	SRC_CAN1INT2.B.SRE = 1;  /* PRQA S 0303,2 # 2023-07-17 Z.J.L:not any affect: accept */

	/****************************************************************************************/
}

/*******************************************************************************
** Syntax           : Cdd_Pmc_GetDieTemperature                               **
**                                                                            **
** Service ID       : none                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : non - reentrant                                         **
**                                                                            **
** Parameters(in)   : none                                                    **
**                                                                            **
** Parameters (out) : none                                                    **
**                                                                            **
** Return value     : Dietemperature                                          **
**                                                                            **
** Description      : This bit field shows the result of the DTS measurement. **
** The value given is directly related to the die temperature and can be      **
** evaluated using the following formula.                                     **
** T(C) = [RESULT / Gnom] - 273.15                                          **
** T(k)=[RESULT]/G_nom                                                       **
** RESULT =G_nom * {T (C) + 273.15} = G_nom * T (k)                         **
** G_nom = 7.505                                                              **
**                                                                            **
*******************************************************************************/
float Cdd_Pmc_GetDieTemperature(void)
{
    return ((PMS_DTSSTAT.B.RESULT / DIETEMP_FACTOR) - DIETEMP_OFFSET);/* PRQA S 3774,1800,0303,2 # 2023-07-17 Z.J.L:not any affect: accept */
}

/*******************************************************************************
** Syntax           : Cdd_Pmc_GetDieTempOverFlow                               **
**                                                                            **
** Service ID       : none                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : non - reentrant                                         **
**                                                                            **
** Parameters(in)   : none                                                    **
**                                                                            **
** Parameters (out) : none                                                    **
**                                                                            **
** Return value     : 0B No temperature overflow was detected                 **
**                    1B A temperature overflow was detected                  **
**                                                                            **
** Description      : This bit is set when a DTS measurement is finished and  **
** the result is exceeding the upper limit (i.e. DTSLIM.UPPER).               **
**                                                                            **
**                                                                            **
*******************************************************************************/
uint8 Cdd_Pmc_GetDieTempOverFlow(void)
{
    return ((uint8)(PMS_DTSLIM.B.UOF));/* PRQA S 0303,2 # 2023-07-17 Z.J.L:not any affect: accept */
}

/*******************************************************************************
** Syntax           : Cdd_Pmc_ClrDieTempOverFlow                               **
**                                                                            **
** Service ID       : none                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : non - reentrant                                         **
**                                                                            **
** Parameters(in)   : none                                                    **
**                                                                            **
** Parameters (out) : none                                                    **
**                                                                            **
** Return value     : none                                                    **
**                                                                            **
** Description      : This bit has to be written with zero in order to clear  **
** it. Writing a one has no effect.                                           **
**                                                                            **
**                                                                            **
*******************************************************************************/
void Cdd_Pmc_ClrDieTempOverFlow(void)
{
    PMS_DTSLIM.B.UOF = 0U;/* PRQA S 0303,2 # 2023-07-17 Z.J.L:not any affect: accept */
}
/*******************************************************************************
** Syntax           : Cdd_Pmc_GetDieTempUnderFlow                             **
**                                                                            **
** Service ID       : none                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : non - reentrant                                         **
**                                                                            **
** Parameters(in)   : none                                                    **
**                                                                            **
** Parameters (out) : none                                                    **
**                                                                            **
** Return value     : 0B No temperature underflow was detected                **
**                    1B A temperature underflow was detected                 **
**                                                                            **
** Description      : This bit is set when a DTS measurement is finished and  **
** the result is exceeding the under limit (i.e. DTSLIM.LOWER).               **
**                                                                            **
**                                                                            **
*******************************************************************************/
uint8 Cdd_Pmc_GetDieTempUnderFlow(void)
{
    return ((uint8)(PMS_DTSLIM.B.LLU));/* PRQA S 0303,2 # 2023-07-17 Z.J.L:not any affect: accept */
}

/*******************************************************************************
** Syntax           : Cdd_Pmc_ClrDieTempUnderFlow                               **
**                                                                            **
** Service ID       : none                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : non - reentrant                                         **
**                                                                            **
** Parameters(in)   : none                                                    **
**                                                                            **
** Parameters (out) : none                                                    **
**                                                                            **
** Return value     : none                                                    **
**                                                                            **
** Description      : This bit has to be written with zero in order to clear  **
** it. Writing a one has no effect.                                           **
**                                                                            **
**                                                                            **
*******************************************************************************/
void Cdd_Pmc_ClrDieTempUnderFlow(void)
{
    PMS_DTSLIM.B.LLU = 0U;/* PRQA S 0303,2 # 2023-07-17 Z.J.L:not any affect: accept */
}

/*******************************************************************************
** Syntax           : Cdd_Pmc_SetDieTempLmit                                  **
**                                                                            **
** Service ID       : none                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : non - reentrant                                         **
**                                                                            **
** Parameters(in)   : none                                                    **
**                                                                            **
** Parameters (out) : none                                                    **
**                                                                            **
** Return value     : Dietemperature                                          **
**                                                                            **
** Description      : The DTS measurement result is compared against this     **
** value and if the measurement result is less than or greather to the        **
** configured LOWER bitfield value; flag LLU/UOF is set.                      **
** T (C) = [RESULT / Gnom] - 273.15                                          **
** T(k)=[RESULT]/G_nom                                                       **
** RESULT =G_nom * {T (C) + 273.15} = G_nom * T (k)                         **
** G_nom = 7.505                                                              **
**                                                                            **
*******************************************************************************/
uint8 Cdd_Pmc_SetDieTempLmit(const float LowerLimit, const float UpperLimit)
{
    uint8 ui8_Retval = E_OK;
    
    uint16 ui16_LowerLimitVal = (uint16)((LowerLimit + DIETEMP_OFFSET) * DIETEMP_FACTOR); /* PRQA S 4395,2211,1 # 2023-07-17 Z.J.L:not any affect: accept */
    uint16 ui16_UpperLimitVal = (uint16)((UpperLimit + DIETEMP_OFFSET) * DIETEMP_FACTOR); /* PRQA S 4395,2211,1 # 2023-07-17 Z.J.L:not any affect: accept */
   
    if((ui16_LowerLimitVal <= 0xFFF) && (ui16_UpperLimitVal <= 0xFFF))//PRQA S 1862,3120
    {
        PMS_DTSLIM.B.LOWER = ui16_LowerLimitVal; //PRQA S 0303
        PMS_DTSLIM.B.UPPER = ui16_UpperLimitVal; //PRQA S 0303
        
        ui8_Retval = E_OK;
    }
    else
    {
        ui8_Retval = E_NOT_OK;
        /*The raw data out of range, shall be keep intial value*/
    }  

    return ui8_Retval;
}

/*******************************************************************************
** Syntax           : Cdd_Pmc_GetCoreDieTemperature                           **
**                                                                            **
** Service ID       : none                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : non - reentrant                                         **
**                                                                            **
** Parameters(in)   : none                                                    **
**                                                                            **
** Parameters (out) : none                                                    **
**                                                                            **
** Return value     : Dietemperature                                          **
**                                                                            **
** Description      : This bit field shows the result of the DTSC measurement.**
** The value given is directly related to the die temperature and can be      **
** evaluated using the following formula.                                     **
** T (C) = [RESULT / Gnom] - 273.15                                          **
** T(k)=[RESULT]/G_nom                                                       **
** RESULT =G_nom * {T (C) + 273.15} = G_nom * T (k)                         **
** G_nom = 7.505                                                              **
**                                                                            **
*******************************************************************************/
float Cdd_Pmc_GetCoreDieTemperature(void)
{   
    /*DTSC is enabled*/
    SCU_DTSCLIM.B.EN = 1U; //PRQA S 0303 
    return ((float)((SCU_DTSCSTAT.B.RESULT)/7.505 - 273.15));//PRQA S 1800,0303,3121,1263,3212,3775,3395
}

/*******************************************************************************
** Syntax           : Cdd_Pmc_GetPmsVoltageResult                             **
**                                                                            **
** Service ID       : none                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : non - reentrant                                         **
**                                                                            **
** Parameters(in)   : none                                                    **
**                                                                            **
** Parameters (out) : none                                                    **
**                                                                            **
** Return value     : s_Pmc_VoltConversionResult_t                            **
**                                                                            **
** Description      : This Function only use to get internal register result  **
** of PMS. And the any voltage conversion format  as follow:                  **
** VIN = [0.7125 + (ADCCV * LSB)] V   LSB = 5mv                               **
** VIN = [0.9375 + (ADC33V * LSB)] V  LSB = 15mv                              **
** VIN = [1.050 + (ADCSWDV * LSB)] V  LSB = 20mv                              **
** VIN = [LSB * (ADCx-1)] ; Ideal LSB = 5.7692 mV                             **
** VIN = [LSB * (ADCx-1)] ; Ideal LSB = 15.00 mV                              **
** VIN = [LSB * (ADCx-1)] ; LSB = 23.077 mV                                   **
** VIN = [LSB * (ADCx-1)] ; Ideal LSB = 5.7692 mV                             **
** VIN = [LSB * (ADCx-1)] ; Ideal LSB = 23.077 mV                             **
** VIN = [LSB * (ADCx-1)] ; Ideal LSB = 23.077 mV                             **
*******************************************************************************/
s_Pmc_VoltConversionResult_t Cdd_Pmc_GetPmsVoltageResult(void)
{
    s_Pmc_VoltConversionResult_t s_CoverVoltResult;

    s_CoverVoltResult.ADCVDD = (float32)((PMS_EVRADCSTAT.B.ADCCV * 0.005f) + 0.7125f);//PRQA S 1800,0303,3121,1263,3212,3774 # 2023-07-17 Z.J.L:not any affect: accept
    s_CoverVoltResult.ADCVDDP3 = (float32)((PMS_EVRADCSTAT.B.ADC33V * 0.015f) + 0.9375f);//PRQA S 1800,0303,3121,1263,3212,3774 # 2023-07-17 Z.J.L:not any affect: accept
    s_CoverVoltResult.ADCVEXT = (float32)((PMS_EVRADCSTAT.B.ADCSWDV * 0.020f) + 1.050f);//PRQA S 1800,0303,3121,1263,3212,3774 # 2023-07-17 Z.J.L:not any affect: accept
    s_CoverVoltResult.VDDADC =  (float32)((PMS_EVRMONSTAT1.B.ADCCV - 1.0f) * (0.0057692f));//PRQA S 1800,0303,3121,1263,3212,3774 # 2023-07-17 Z.J.L:not any affect: accept
    s_CoverVoltResult.VDDP3ADC = (float32)((PMS_EVRMONSTAT1.B.ADC33V - 1.0f) * (0.015f));//PRQA S 1800,0303,3121,1263,3212,3774 # 2023-07-17 Z.J.L:not any affect: accept
    s_CoverVoltResult.VEXTADC = (float32)((PMS_EVRMONSTAT1.B.ADCSWDV - 1.0f) * (0.023077f));//PRQA S 1800,0303,3121,1263,3212,3774 # 2023-07-17 Z.J.L:not any affect: accept
    s_CoverVoltResult.VDDPDADC = (float32)((PMS_EVRMONSTAT2.B.ADCPRE - 1.0f) * (0.0057692f));//PRQA S 1800,0303,3121,1263,3212,3774 # 2023-07-17 Z.J.L:not any affect: accept
    s_CoverVoltResult.VEVRSBADC = (float32)((PMS_EVRMONSTAT2.B.ADCSB - 1.0f) * (0.023077f)); //PRQA S 1800,0303,3121,1263,3212,3774 # 2023-07-17 Z.J.L:not any affect: accept
    s_CoverVoltResult.VDDMADC = (float32)((PMS_EVRMONSTAT2.B.ADCVDDM - 1.0f) * (0.023077f));//PRQA S 1800,0303,3121,1263,3212,3774 # 2023-07-17 Z.J.L:not any affect: accept
    
    return s_CoverVoltResult;
}

/*******************************************************************************
** Syntax           : Cdd_Pmc_GetPmsVoltageErrorStatus                        **
**                                                                            **
** Service ID       : none                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : non - reentrant                                         **
**                                                                            **
** Parameters(in)   : none                                                    **
**                                                                            **
** Parameters (out) : none                                                    **
**                                                                            **
** Return value     : s_Pmc_VoltErrorStatus_t                                 **
**                                                                            **
** Description      : This Function only use to get Voltage error status of   **
** PMS.                                                                       **
*******************************************************************************/
s_Pmc_VoltErrorStatus_t Cdd_Pmc_GetPmsVoltageErrorStatus(void)
{
    s_Pmc_VoltErrorStatus_t s_VoltErrorStatus;

    s_VoltErrorStatus.ShortDetect.VDDP3ShortToGround = (PMS_EVRSTAT.B.EVRCSHLV == 1)? (E_NOT_OK):(E_OK);//PRQA S 0303,1863 # 2023-07-17 Z.J.L:not any affect: accept
    s_VoltErrorStatus.ShortDetect.VDDP3ShortToSupply = (PMS_EVRSTAT.B.EVRCSHHV == 1)? (E_NOT_OK):(E_OK);//PRQA S 0303,1863 # 2023-07-17 Z.J.L:not any affect: accept
    s_VoltErrorStatus.ShortDetect.VDDShortToGround = (PMS_EVRSTAT.B.EVR33SHLV == 1)? (E_NOT_OK):(E_OK);//PRQA S 0303,1863 # 2023-07-17 Z.J.L:not any affect: accept
    s_VoltErrorStatus.ShortDetect.VDDShortToSupply =  (PMS_EVRSTAT.B.EVR33SHHV == 1)? (E_NOT_OK):(E_OK);//PRQA S 0303,1863 # 2023-07-17 Z.J.L:not any affect: accept
	/*VDD Over-voltage event flag*/
    s_VoltErrorStatus.EventFlag.VDDOverFlag = (PMS_EVRSTAT.B.OVC == 1)? (E_NOT_OK):(E_OK);//PRQA S 0303,1863 # 2023-07-17 Z.J.L:not any affect: accept 
	/*VDDP3 Over-voltage event flag*/
    s_VoltErrorStatus.EventFlag.VDDP3OverFlag = (PMS_EVRSTAT.B.OV33 == 1)? (E_NOT_OK):(E_OK);//PRQA S 0303,1863 # 2023-07-17 Z.J.L:not any affect: accept 
	/*VEXT Over-voltage event flag*/
    s_VoltErrorStatus.EventFlag.VEXTOverFlag = (PMS_EVRSTAT.B.OVSWD == 1)? (E_NOT_OK):(E_OK);//PRQA S 0303,1863 # 2023-07-17 Z.J.L:not any affect: accept 
	/*VDD Under-voltage event flag*/
    s_VoltErrorStatus.EventFlag.VDDUnderFlag = (PMS_EVRSTAT.B.UVC == 1)? (E_NOT_OK):(E_OK);//PRQA S 0303,1863 # 2023-07-17 Z.J.L:not any affect: accept 
	/*VDDP3 Under-voltage event flag*/
    s_VoltErrorStatus.EventFlag.VDDP3UnderFlag = (PMS_EVRSTAT.B.UV33 == 1)? (E_NOT_OK):(E_OK);//PRQA S 0303,1863 # 2023-07-17 Z.J.L:not any affect: accept 
	/*VEXT Under-voltage event flag*/
    s_VoltErrorStatus.EventFlag.VEXTUnderFlag = (PMS_EVRSTAT.B.UVSWD == 1)? (E_NOT_OK):(E_OK);//PRQA S 0303,1863 # 2023-07-17 Z.J.L:not any affect: accept 
	/*Pre Regulator VDDPD Over-voltage event flag*/
    s_VoltErrorStatus.EventFlag.VDDPDOverFlag = (PMS_EVRSTAT.B.OVPRE == 1)? (E_NOT_OK):(E_OK);//PRQA S 0303,1863 # 2023-07-17 Z.J.L:not any affect: accept 
	/*Standby Supply or VEVRSB Over-voltage event flag*/
    s_VoltErrorStatus.EventFlag.VEVRSBOverFlag = (PMS_EVRSTAT.B.OVSB == 1)? (E_NOT_OK):(E_OK);//PRQA S 0303,1863 # 2023-07-17 Z.J.L:not any affect: accept 
	/*ADC VDDM Supply Over-voltage event flag*/
    s_VoltErrorStatus.EventFlag.VDDMOverFlag = (PMS_EVRSTAT.B.OVDDM == 1)? (E_NOT_OK):(E_OK); //PRQA S 0303,1863 # 2023-07-17 Z.J.L:not any affect: accept
	/*Pre Regulator VDDPD Under-voltage event flag*/
    s_VoltErrorStatus.EventFlag.VDDPDUnderFlag = (PMS_EVRSTAT.B.UVPRE == 1)? (E_NOT_OK):(E_OK);//PRQA S 0303,1863 # 2023-07-17 Z.J.L:not any affect: accept
	/*VEVRSB Under-voltage event flag*/
    s_VoltErrorStatus.EventFlag.VEVRSBUnderFlag = (PMS_EVRSTAT.B.UVSB == 1)? (E_NOT_OK):(E_OK);//PRQA S 0303,1863 # 2023-07-17 Z.J.L:not any affect: accept 
	/*ADC VDDM Supply Under-voltage event flag*/
    s_VoltErrorStatus.EventFlag.VDDMUnderFlag =  (PMS_EVRSTAT.B.UVDDM == 1)? (E_NOT_OK):(E_OK); //PRQA S 0303,1863 # 2023-07-17 Z.J.L:not any affect: accept
    
    return s_VoltErrorStatus;

}

/*******************************************************************************
** Syntax           : uint32 Get_Counter_Value(uint32 reqTime,Test_TimeUnit   **
**                    unitOfReqTime)                                          **
**                                                                            **
** Service ID       : none                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : non - reentrant                                         **
**                                                                            **
** Parameters(in)   : uint32 reqTime (Input time)                             **
**                    Test_TimeUnit unitOfReqTime (NS/MS/US)                  **
** Parameters (out) : none                                                    **
**                                                                            **
** Return value     : uint32 - Fstm                                           **
**                                                                            **
** Description      : This function calculates Fstm runtime                   **
**                                                                            **
*******************************************************************************/
static uint32 Get_Counter_Value(const uint32 reqTime, const uint8 unitOfReqTime)
{
  uint32 Fstm = Get_Fstm();
  if(unitOfReqTime == TIMER_MS)
  {
    return (uint32)((float)(((((float)Fstm / (1000.0))) * (reqTime)) + 0.5)); //PRQA S 3797,3121,1800 # 2023-07-17 Z.J.L:not any affect: accept
  }
  else if(unitOfReqTime == TIMER_US)
  {
    return (uint32)((float)(((((float)Fstm / (1000000.0))) * (reqTime))));//PRQA S 3797,3121,1800 # 2023-07-17 Z.J.L:not any affect: accept
  }
  else
  {
    return (uint32)0;
  }
}

/*******************************************************************************
** Syntax           : uint32 Get_Fstm()                                       **
**                                                                            **
** Service ID       : none                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : non - reentrant                                         **
**                                                                            **
** Parameters(in)   : none                                                    **
**                                                                            **
** Parameters (out) : none                                                    **
**                                                                            **
** Return value     : uint32 - Fstm                                           **
**                                                                            **
** Description      : This function calculates Fstm runtime                   **
**                                                                            **
*******************************************************************************/
static uint32 Get_Fstm(void)
{
  uint32 Fsrc = 0;
  uint32 Fstm = 10;//PRQA S 3120

  uint8 CLKSEL = SCU_CCUCON0.B.CLKSEL; /* PRQA S 2211,0303,1 # 2023-07-17 Z.J.L:not any affect: accept */

  if(CLKSEL == (uint8)1)
  {
    Fsrc = ((MCU_MAIN_OSC_FREQ * 1000000) * (SCU_SYSPLLCON0.B.NDIV + 1)) / ((SCU_SYSPLLCON0.B.PDIV + 1) * (SCU_SYSPLLCON1.B.K2DIV + 1));//PRQA S 0303,3120,1860,1820,0404,1840,3384 # 2023-07-17 Z.J.L:not any affect: accept
  }
  else
  {
    Fsrc = (MCU_BACKUP_FREQ * 1000000);//PRQA S 3120,1840 # 2023-07-17 Z.J.L:not any affect: accept
  }

  Fstm = Fsrc / (SCU_CCUCON0.B.STMDIV);//PRQA S 0303 # 2023-07-17 Z.J.L:not any affect: accept

  return Fstm;
}


