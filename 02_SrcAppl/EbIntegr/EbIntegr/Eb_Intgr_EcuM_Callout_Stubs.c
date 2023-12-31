/**
 * \file
 *
 * \brief AUTOSAR ApplTemplates
 *
 * This file contains the implementation of the AUTOSAR
 * module ApplTemplates.
 *
 * \version 6.8.0
 *
 * \author Elektrobit Automotive GmbH, 91058 Erlangen, Germany
 *
 * Copyright 2005 - 2020 Elektrobit Automotive GmbH
 * All rights exclusively reserved for Elektrobit Automotive GmbH,
 * unless expressly agreed to otherwise.
 */

/*==================[inclusions]============================================*/

#include <Std_Types.h>     /* AUTOSAR standard types */
#include <TSAutosar.h>     /* EB specific standard types, TS_PARAM_UNUSED() */

#include <EcuM_Cbk.h>      /* callbacks and callouts of EcuM */
#include <EcuM_PBcfg.h>
#include "IfxSrc_reg.h"
#ifdef _X86_
#include <stdlib.h>
#endif

#include <EcuM.h>
#include <EcuM_Trace.h>
#include "Dio_Cfg.h"
#include "Dio.h"
#include "Mcu.h"
#include "IfxStm_reg.h"
#include "Can_GeneralTypes.h"
#include "CanIf_Types.h"
#include "CanIf_Api.h"
#include "CanTrcv_8_Tja1043.h"
#include "Cdd_Pmc.h"
#include "Cdd_Sbc_Cfg.h"
#include "Print.h"
#include "function_safety.h"
#if FS_PDO_ENABLED
#include "fs_pdo.h"
#endif
/*==================[macros]================================================*/
#if(defined ECUM_GET_CORE_ID)
#error ECUM_GET_CORE_ID already defined
#endif
#if (ECUM_MULTICORE_ENABLED == TRUE)
/** \brief Returns the core ID that is currently active. */
#define ECUM_GET_CORE_ID() GetCoreID()
#else
#define ECUM_GET_CORE_ID() 0U
#endif /* (ECUM_MULTICORE_ENABLED == TRUE) */
/*==================[type definitions]======================================*/

/*==================[external function declarations]========================*/

/*==================[internal function declarations]========================*/

/*==================[external constants]====================================*/

/*==================[internal constants]====================================*/

/*==================[external data]=========================================*/

/*==================[internal data]=========================================*/

/*==================[external function definitions]=========================*/

#define ECUM_START_SEC_CODE
#include <EcuM_MemMap.h>

/*------------------[Callouts from STARTUP state]---------------------------*/

FUNC(void, ECUM_APPL_CODE) EcuM_AL_DriverInitZero(void)
{
 /* EcuM_DefaultInitListZero() provides the default implementation of the
  * EcuMDriverInitListZero.  When this function is called, the initialization of
  * the configured EcuMDriverInitItems within the EcuM configuration container
  * EcuMDriverInitListZero will be carried out.
  */
  EcuM_DefaultInitListZero();
}

/* Configured Initialization List One items */
FUNC(void, ECUM_APPL_CODE) EcuM_DriverInitListOne
(
  P2CONST(EcuM_ConfigType, AUTOMATIC, ECUM_CONST) ConfigPtr
)
{
  TS_PARAM_UNUSED(ConfigPtr);
  /* EcuM_DefaultInitListOne() provides the default implementation of the
   * EcuMDriverInitListOne.  When this function is called, the initialization of
   * the configured EcuMDriverInitItems within the EcuM configuration container
   * EcuMDriverInitListOne will be carried out.
   */
  EcuM_DefaultInitListOne();
}

#if (ECUM_INITLIST_ONE == STD_ON)
FUNC(void, ECUM_APPL_CODE) EcuM_AL_DriverInitOne
(
  P2CONST(EcuM_ConfigType, AUTOMATIC, ECUM_CONST) ConfigPtr
)
{
  /* Call Initialization List One. This initializes all the configured
   * modules in 'EcuMDriverInitListOne'
   */
  EcuM_DriverInitListOne(ConfigPtr);
}
#endif

/*------------------[Callouts from SLEEP state]--------------------------*/

#if (ECUM_INITLIST_RESTART == STD_ON)
FUNC(void, ECUM_APPL_CODE) EcuM_AL_DriverRestart
(
  P2CONST(EcuM_ConfigType, AUTOMATIC, ECUM_CONST) ConfigPtr
)
{
  /* Call Driver Restart List. This restart all the configured
   * modules in 'EcuMDriverRestartList'
   */
  TS_PARAM_UNUSED(ConfigPtr);
  EcuM_DefaultRestartList();
}
#endif

/*------------------[Generic callouts]--------------------------------------*/

FUNC(void,ECUM_APPL_CODE) EcuM_ErrorHook
(
  Std_ReturnType reason
)
{
  TS_PARAM_UNUSED(reason); /* remove if parameter is used */

  /* Implement the routine to handle the production error ECUM_RAM_CHECK_FAILED
   * with in this callout function.
   *
   * EcuM calls EcuM_ErrorHook with parameter ECUM_RAM_CHECK_FAILED when RAM Check
   * fails on wakeup.
   *
   * Integrator may define additional error codes to be passed as the 'reason'
   * parameter. This code shall not conflict with the development and production error
   * codes defined in SWS. Also it shall not conflict with standard error codes E_OK and
   * E_NOT_OK.
   * Note: The ECU Manager module can invoke EcuM_ErrorHook in all phases
   *
   *  Implementation hint:
   *
   *  FUNC(void,ECUM_APPL_CODE) EcuM_ErrorHook (Std_ReturnType reason)
   *  {
   *    if(reason == ECUM_RAM_CHECK_FAILED)
   *    {
   *      Mcu_PerformReset();
   *    }
   *  }
   */
}

/*------------------[Callouts from STARTUP phase]---------------------------*/

FUNC(void,ECUM_APPL_CODE) EcuM_AL_SetProgrammableInterrupts(void)
{
  /* Implement the routine to set interrupts on ECUs with programmable interrupts
   * with in this callout function.
   *
   * On ECUs with programmable interrupt priorities, these priorities must be set before
   * the OS is started. */
//	SRC_CAN0INT1.B.SRE = 1;
//	SRC_CAN1INT1.B.SRE = 1;
}

FUNC(EcuM_DeterminePbConfigurationRetType, ECUM_APPL_CODE)
  EcuM_DeterminePbConfiguration(void)
{
  EcuM_DeterminePbConfigurationRetType PbConfig = &(EcuM_Config_0);

  /* Implement the routine to return EcuM configuration structure
   * which shall be activated on start up in this callout function.
   *
   * Integrator may select the post-build configuration after evaluating
   * some condition like status of a port pin or NVRAM value. */

  return PbConfig;
}

/*------------------[Callouts from UP phase]-------------------------------*/

/*------------------[Callouts from SHUTDOWN phase]--------------------------*/

FUNC(void, ECUM_APPL_CODE) EcuM_OnGoOffOne(void)
{
  /* Ecu Manager module invokes this callout on entry actions of OffPreOS
   * sequence. */
}

FUNC(void, ECUM_APPL_CODE) EcuM_OnGoOffTwo(void)
{
  /* Ecu Manager module invokes this callout on entry actions of OffPostOS
   * sequence. */
}

FUNC(void,ECUM_APPL_CODE) EcuM_EnableWakeupSources
(
  EcuM_WakeupSourceType wakeupSource
)
{
  TS_PARAM_UNUSED(wakeupSource); /* remove if parameter is used */

  /* Implement the routine to notify the wakeup sources defined in the wakeupSource
   * bitfield that SLEEP will be entered and enable the wakeup functionality accordingly
   * in this callout function.
   *
   *  Implementation hint:
   *
   *  Enable GPT Wakeup:
   *
   *  FUNC(void,ECUM_APPL_CODE) EcuM_EnableWakeupSources (EcuM_WakeupSourceType wakeupSource)
   *  {
   *    if (wakeupSource is assigned to GPT channel)
   *    {
   *      Gpt_EnableWakeup(Gpt_ChannelType);
   *
   *      Gpt_StartTimer(Gpt_ChannelType, Gpt_ValueType);
   *
   *      Gpt_SetMode(Gpt_ModeType);
   *    }
   *  }
   *  Enable CAN Wakeup:
   *
   *  void EcuM_EnableWakeupSources (EcuM_WakeupSourceType wakeupSource)
   *  {
   *    if (wakeupSource is assigned to CAN channel)
   *    {
   *      CanIf_SetTrcvWakeupMode(TransceiverId, TrcvWakeupMode);
   *    }
   *    else if (wakeupSource is assigned to ICU channel)
   *    {
   *      Icu_EnableWakeup(Icu_ChannelType);
   *    }
   *  }
   */
}

FUNC(void,ECUM_APPL_CODE) EcuM_GenerateRamHash(void)
{
  /* Implement the routine to check RAM memories integrity with in this callout
   * function.
   *
   * The ECU Manager module invokes EcuM_GenerateRamHash callout
   * before halting the micro controller and check the RAM integrity using
   * the callout EcuM_CheckRamHash after the processor returns from halt.
   *
   * Ram memory may become corrupted when an ECU is held in sleep mode for a
   * long time. The RAM memories integrity should therefore be checked to prevent
   * unforeseen behavior. The system designer may choose an adequate checksum
   * algorithm to perform the check. */
}

//extern TJA1043TK_SleepMode(void);
//extern drvData;
static uint32 Debug_EcuM_AL_SwitchOff_Cnt = 0x00;
static uint32 Debug_EcuM_AL_SwitchOff_FristTime = 0x00;
static uint32 Debug_EcuM_AL_SwitchOff_CurrentTime = 0x00;
static uint32 Debug_EcuM_AL_SwitchOff_DiffTime = 0x00;

FUNC(void, ECUM_APPL_CODE) EcuM_AL_SwitchOff(void)
{
   /* The ECU Manager module invokes EcuM_AL_SwitchOff as the last activity
   * in the OffPostOS Sequence.
   *
   * In some cases of HW/SW concurrency, it may happen that during the power
   * down in EcuM_AL_SwitchOff(endless loop) some hardware(eg. CAN transciver)
   * switches on the ECU again.
   *
   * In this case the Ecu may be in deadlock until the hardware watchdog resets
   * the ECU. To reduce the time until the hardware  watchdog fixes this deadlock,
   * the integrator code in EcuM_AL_SwitchOff as last action can limit the endless
   * loop and after a sufficient long time reset the Ecu using Mcu_PerformReset(). */
    Cdd_Pmc_PmicDisable();
        
    Cdd_Pmc_CanTrvGotoSleep();
	
	Timer_DelayMs(2);	//delay 2ms
    //Off Soc Power
	Dio_WriteChannel(DioConf_DioChannel_DIO_DO_MCU_J3_RST_B, STD_LOW);
    Timer_DelayMs(2);	//delay 2ms
	Dio_WriteChannel(DioConf_DioChannel_DIO_DO_J3_PMIC_8200_PWRON, STD_LOW);
	/*Off PMIC FS84*/
	//Timer_DelayMs(6);	//delay 6ms
    Dio_WriteChannel(DioConf_DioChannel_DIO_DO_PWR_EN_2V9_OM, STD_LOW);
    Timer_DelayMs(2);	//delay 2ms
	Dio_WriteChannel(DioConf_DioChannel_DIO_DO_PWR_EN_1V0_GEPHY, STD_LOW);
	Timer_DelayMs(2);	//delay 2ms
	FS8x_SetRegulatorState(&fs8400drvData, fs8xLdo2, false);
	Timer_DelayMs(2);	//delay 2ms
	FS8x_SetRegulatorState(&fs8400drvData, fs8xLdo1, false);
	Timer_DelayMs(2);	//delay 2ms
	FS8x_SetRegulatorState(&fs8400drvData, fs8xBuck1, false);
	Timer_DelayMs(2);	//delay 2ms
	FS8x_SetRegulatorState(&fs8400drvData, fs8xBuck2, false);
	Timer_DelayMs(2);	//delay 2ms
	FS8x_SetRegulatorState(&fs8400drvData, fs8xBuck3, false);//Deleted by Mingfen

	/*Off Power for shutdown*/
	Dio_WriteChannel(DioConf_DioChannel_DIO_DO_SYS_OFF_B, STD_LOW);
	
	Debug_EcuM_AL_SwitchOff_FristTime = STM0_TIM0.U;
	
	while(1)
	{
			Debug_EcuM_AL_SwitchOff_CurrentTime = STM0_TIM0.U;
	
	
			if(Debug_EcuM_AL_SwitchOff_CurrentTime > Debug_EcuM_AL_SwitchOff_FristTime)
			{
				//ms
				Debug_EcuM_AL_SwitchOff_DiffTime = (uint32)(Debug_EcuM_AL_SwitchOff_CurrentTime-Debug_EcuM_AL_SwitchOff_FristTime)/100000.0;
			}
			else
			{
				Debug_EcuM_AL_SwitchOff_DiffTime = (0xffffffff-Debug_EcuM_AL_SwitchOff_FristTime+Debug_EcuM_AL_SwitchOff_CurrentTime)/100000.0;
			}
	
			if(Debug_EcuM_AL_SwitchOff_DiffTime >= 5000)
			{
				Debug_EcuM_AL_SwitchOff_FristTime = STM0_TIM0.U;
#if FS_PDO_ENABLED
		    g_fs_debug_status.reset_source_fs[g_fs_debug_status.reset_source_fs_count]=FS_RS_EcumSwitchOff;
		    g_fs_debug_status.reset_source_fs_count = (g_fs_debug_status.reset_source_fs_count + 1)% 32;    
#endif /** FS_PDO_ENABLED */
        Mcu_PerformReset();
				//FS8x_SetRegulatorState(drvData, fs8xBuck3, false);
			}
	
	}
	
#ifdef _X86_
  exit(0);
#endif   
}

FUNC(void, ECUM_APPL_CODE) EcuM_AL_Reset(EcuM_ResetType reset)
{
  TS_PARAM_UNUSED(reset); /* remove if parameter is used */

  /* Implement the routine to reset the ECU with in this callout function.
   *
   * When the shutdown target is RESET, the ECU Manager module invokes
   * this callout. This callout shall take the code for resetting the ECU.
   * The parameter 'reset' tells which type of reset to be done in Ecu.
   *
   * ECUM_RESET_MCU - Perform Microcontroller reset via Mcu_PerformReset
   * ECUM_RESET_WDG - Perform Watchdog reset via WdgM_PerformReset
   * ECUM_RESET_IO  - Perform Reset by toggeling an I/O line
   *
   * This values can be extended by configuration and the integrator shall decide
   * the type of reset to be performed with respect to the 'reset' received.
   *
   *  Implementation hint:
   *  FUNC(void, ECUM_APPL_CODE) EcuM_AL_Reset(EcuM_ResetType reset)
   *  {
   *    if(reset == ECUM_RESET_MCU )
   *    {
   *      Mcu_PerformReset();
   *    }
   *    else if(reset == ECUM_RESET_WDG )
   *    {
   *      WdgM_PerformReset();
   *    }
   *    if(reset == ECUM_RESET_IO )
   *    {
   *
   *    }
   *  }
   *
   */
#ifdef _X86_
  exit(0);
#endif    
}

/*------------------[Callouts from WAKEUP state]----------------------------*/

FUNC(uint8, ECUM_APPL_CODE) EcuM_CheckRamHash(void)
{
  /* Implement the routine to check RAM memories integrity with in this callout
   * function.
   *
   * The goal of this test is to ensure that after a long SLEEP duration, RAM
   * contents is still consistent. The check does not need to be exhaustive since
   * this would consume quite some processing time during wakeups. A well
   * designed check will execute quickly and detect RAM integrity defects
   * with a sufficient probability.
   */

  /* 0: RAM integrity test failed
     else: RAM integrity test passed */
  return 1U;
}

FUNC(void,ECUM_APPL_CODE) EcuM_DisableWakeupSources
(
  EcuM_WakeupSourceType wakeupSource
)
{
  TS_PARAM_UNUSED(wakeupSource); /* remove if parameter is used */

  /* Implement the routine to disable all wakeup sources in this callout function.
   *
   * The ECU Manager Module calls EcuM_DisableWakeupSources to set the wakeup
   * source(s) defined in the wakeupSource bitfield so that they are not able
   * to wake the ECU up and will be invoked in the WakeupRestart Sequence.
   *
   * The ECU Manager module derives the wakeup sources to be checked
   * (and used as the wakeupSource parameter) from the internal pending events
   * variable (NOT operation). The integration code used for this callout must
   * determine which wakeup sources must be checked.
   *
   *  Implementation hint:
   *
   *  Disable GPT Wakeup:
   *  FUNC(void,ECUM_APPL_CODE) EcuM_DisableWakeupSources ( EcuM_WakeupSourceType wakeupSource)
   *  {
   *    if (wakeupSource is assigned to GPT channel)
   *    {
   *      Gpt_DisableWakeup(Gpt_ChannelType);
   *
   *      Gpt_SetMode(Gpt_ModeType);
   *    }
   *  }
   */
}

/*------------------[Callouts from UP phase]----------------------------*/

FUNC(void,ECUM_APPL_CODE) EcuM_StartWakeupSources
(
  EcuM_WakeupSourceType wakeupSource
)
{
  TS_PARAM_UNUSED(wakeupSource); /* remove if parameter is used */

  /* Implement the routine to start the given wakeup source(s) with in this callout function,
  //  * so that they are ready to perform wakeup validation
  //  *
  //  * Implementation hint:
  //  *
  //  * Can start wakeup :
  //  * FUNC(void,ECUM_APPL_CODE) EcuM_StartWakeupSources ( EcuM_WakeupSourceType wakeupSource )
  //  *  {
  //  *    if (wakeupSource is assigned to CAN channel)
  //  *    {
  //  *      CanIf_SetTrcvMode(uint8 TransceiverId, CanIf_TrcvModeType TransceiverMode);
  //  *
  //  *      CanIf_SetControllerMode( uint8 ControllerId, CanIf_ControllerModeType ControllerMode);
  //  *    }
  //  *  }
  //  */
    if (wakeupSource & (ECUM_WKSMASKALL>>6) == 1)
    {
      // CanIf_SetTrcvMode( 0, CANTRCV_TRCVMODE_NORMAL);
      CanIf_SetControllerMode( 0, CANIF_CS_STARTED);
    }
}

FUNC(void,ECUM_APPL_CODE) EcuM_CheckValidation
(
  EcuM_WakeupSourceType wakeupSource
)
{
  /* Implement the routine to validate a wakeup source with in this callout function.
   *
   * If a valid wakeup has been detected, it shall be reported to EcuM
   * via EcuM_ValidateWakeupEvent().
   * This callout will be invoked by EcuM in the Wakeup Validation Sequence.
   *
   * Implementation hint :
   *
   * Can Wakeup Validation :
   *  FUNC(void,ECUM_APPL_CODE) EcuM_CheckValidation(EcuM_WakeupSourceType wakeupSource)
   *    {
   *      if (wakeupSource is assigned to CAN channel)
   *      {
   *        CanIf_CheckValidation(WakeupSource);
   *      }
   *    }
   */
    //CanIf_CheckValidation(wakeupSource);
  //  EcuM_ValidateWakeupEvent(wakeupSource);
}

FUNC(void,ECUM_APPL_CODE) EcuM_StopWakeupSources
(
  EcuM_WakeupSourceType wakeupSource
)
{
  TS_PARAM_UNUSED(wakeupSource); /* remove if parameter is used */

  /* Implement the routine to stop the given wakeup sources after
   * unsuccesful wakeup validation, with in this callout function.
   *
   * This callout will be invoked by EcuM in Wakeup Validation sequence.
   *
   * Implementation hint:
   *
   * Stop CanIf wakeup:
   * FUNC(void,ECUM_APPL_CODE) EcuM_StopWakeupSources (EcuM_WakeupSourceType wakeupSource)
   * {
   *   Std_ReturnType CanIf_SetControllerMode
   *                   ( uint8 ControllerId, CanIf_ControllerModeType ControllerMode );
   * }
   */
}

/*------------------[Callouts from SLEEP phase]-----------------------------*/

FUNC(void,ECUM_APPL_CODE) EcuM_SleepActivity(void)
{
  /* EcuM invokes this callout function in Poll sequence in a blocking loop at
   * maximum frequency. The callout implementation must ensure by other means, if
   * callout code shall be executed with a lower period. The integrator may choose
   * any method to control this, e.g. with the help of OS counters, OS alarms
   * or Gpt timers. */
   EcuM_WakeupSourceType wkSrc = EcuMConf_EcuMWakeupSource_ECUM_WKSOURCE_POWER;

   EcuM_SetWakeupEvent(wkSrc);
}

FUNC(void,ECUM_APPL_CODE) EcuM_CheckWakeup
(
  EcuM_WakeupSourceType wakeupSource
)
{
  TS_PARAM_UNUSED(wakeupSource); /* remove if parameter is used */

  /* Implement the routine to poll for a wakeup source in this callout function.
   *
   * It may also be called by the ISR of a wakeup source to set up the PLL and set
   * other wakeup sources that may be connected to the same interrupt.
   *
   * The Ecu Manager module invokes EcuM_CheckWakeup() periodically during the Poll
   * sequence(See section 7.5.3 Activities in the Poll Sequence) if the MCU is not halted
   * or when handling a wakeup interrupt.
   * If called from the Poll sequence, EcuM calls this callout functions in a blocking
   * loop at maximum frequency. The implementation must ensure by other means if callout
   * code shall be executed with a lower period. Choose any method to control the
   * execution period. eg. with the help of OS counters, OS alarms or GPT timers.
   *
   *  Implementation hint:
   *
   *  FUNC(void,ECUM_APPL_CODE) EcuM_CheckWakeup (EcuM_WakeupSourceType wakeupSource)
   *  {
   *    <Module>_CheckWakeup(wakeupSource);
   *  }
   */
}

FUNC(void, ECUM_APPL_CODE) EcuM_PreHalt(void)
{
  /* Implement the routine to disable all the interrupts which lead to ECU wakeup. */
}

FUNC(void, ECUM_APPL_CODE) EcuM_PostHalt(void)
{
  /* Implement the routine to enable all the interrupts, that were disabled by
   * EcuM_PreHalt. */
}

/*-------------[Callouts for EcuM Multi-Core synchronization]---------------*/

/* !LINKSTO EcuM.Impl.EcuM_OnCoreSync,1 */
FUNC(EcuM_SyncActionType, ECUM_APPL_CODE) EcuM_OnCoreSync(void)
{
  const uint8 coreID = ECUM_GET_CORE_ID();
  EcuM_SyncActionType syncValue = ECUM_CONTINUE_SYNC;
  switch(coreID)
  {
    case 0:
    /* Function blocking on the Master-Core on entry to Sleep(EcuM_GoHalt) or Shutdown(EcuM_GoDown) on EcuM_SlaveCoreSync(). */
    {
    	return ECUM_CONTINUE_SYNC;
      /* If you want to continue waiting for Slave-Cores to synchronize, return ECUM_CONTINUE_SYNC.
       * If you want to abort synchronization with the Slave-Cores, return ECUM_ABORT_SYNC.
       *
       * if (shutdownTarget == ECUM_STATE_SLEEP)
       * {
       * The Master-Core is waiting for the Slave-Cores to signal that they have entered the sleep state.  The
       * Master-Core must synchronize here so that the Ram is not modified while the Master-Core calculates the
       * Ram hash.
       *
       * If this function returns ECUM_ABORT_SYNC and the selected shutdown target is ECUM_STATE_SLEEP, the
       * Master-Core will not enter the sleep state, because the Ram hash would likely not be correct, which
       * would lead to an ECU reset.
       * }
       * else if (shutdownTarget == (ECUM_STATE_OFF || ECUM_STATE_RESET))
       * {
       * The Master-Core is waiting for the Slave-Cores to signal that they have entered the shutdown state.  The
       * Master-Core must synchronize here so that the Slave-Cores are not stopped before they have finished de-initialization.
       *
       * If this function returns ECUM_ABORT_SYNC and the selected shutdown target is ECUM_STATE_OFF, the
       * Master-Core will not enter the shutdown state. The BswM on the Master-Core must then restart the
       * shutdown transition for all cores.
       * }
       */
      break;
    }
    case 1:
    /* Function blocking on Slave-Core ID 1 on exit from Sleep (EcuM_GoHalt or EcuM_GoPoll) on EcuM_MasterCoreSync(). */
    {
    	return ECUM_CONTINUE_SYNC;
     /* If you want to continue waiting for synchronization with the Master-Core, return ECUM_CONTINUE_SYNC.
      * If you want to abort synchronization with the Master-Core, return ECUM_ABORT_SYNC.
      *
      * The Slave-Core ID 1 is waiting for the Master-Core to signal that it has completed
      * the verification of the Ram hash (in case the selected sleep mode is halt) and that the other cores are
      * ready to transition into the UP state.
      *
      * If a wakeup event has occured only on a Slave-Core, this callout function can be used to trigger a wakeup
      * event on the other cores (for example, by setting an OsEvent which triggers a user-defined function that
      * sets an EcuM wakeup event on the core that the OsEvent is allocated to).
      *
      * If this function returns ECUM_ABORT_SYNC, the Slave-Core will immediately continue transition into the UP state.  If the
      * Master-Core is still verifying the Ram hash, and the Slave-Core modifies a section of memory that is being verified, the
      * Ram validation may fail, leading to an Ecu reset. The Ram hash is only calculated in the halt sleep mode.
      */
      break;
    }
    default:
    {
      break;
    }
  }

  return syncValue;
}

#define ECUM_STOP_SEC_CODE
#include <EcuM_MemMap.h>

/*==================[internal function definitions]=========================*/

/*==================[end of file]===========================================*/
