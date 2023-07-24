/**
 * \file Esm.c
 *
 * \brief This files include startup and shutdown operation of ECU and soc.
 *
 * \version refer the Esm.h.
 * 
 * \copyright  2021 - 2022 Conti Smart Core
 *
 */
/*==================[inclusions]============================================*/
#include <Rte_Esm.h>
#include "Esm.h"
#include "Eb_Intgr_BswM_UserCallouts.h"
#include "BswM.h"
#include "NmStack_Types.h"
#include "comcoordinator.h"
#include "Cdd_Pmc.h"
#include "Sdc_SendInterface.h"
#include "WdgM_Cfg.h"
#include "function_safety.h"
#if FS_PDO_ENABLED
#include "fs_pdo.h"
#endif

/*==================[external constants definition]=========================*/
#define Esm_START_SEC_CALIB
#include <Esm_MemMap.h> 
//10000ms  = 10s
const volatile uint16 c_Esm_SocExceptionDelayTime = 10000u;//PRQA S 3408
//5000ms = 5s
const volatile uint16 c_Esm_SysShutDownDelaytTime = 5000u;//PRQA S 3408
#define Esm_STOP_SEC_CALIB
#include <Esm_MemMap.h> 



/*==================[internal constants definition]=========================*/


/*==================[external data definition]==============================*/



/*==================[internal data definition]==============================*/
#define Esm_START_SEC_VAR_INIT_LOCAL
#include <Esm_MemMap.h> 
static boolean b_SocPowerOnRequest = TRUE; //PRQA S 1295
static boolean b_SocShutdownReuqest = FALSE; //PRQA S 1295
static boolean b_RunSocshutdownLoop = FALSE; //PRQA S 1295
static boolean b_SocSafetyPoweroff = FALSE; //PRQA S 1295
static boolean b_CameraPowerOnRequest = TRUE; //PRQA S 1295
static boolean b_CameraPowerOffRequest = FALSE; //PRQA S 1295
static boolean b_SocStartupCompleted = FALSE; //PRQA S 1295
#define Esm_STOP_SEC_VAR_INIT_LOCAL
#include <Esm_MemMap.h>

/*==================[internal function declarations]========================*/
#define Esm_START_SEC_CODE_LOCAL
#include <Esm_MemMap.h> 
static FUNC(void, RTE_CODE) Esm_Calculation(void);
static FUNC(void, RTE_CODE) Esm_SocStartupPermission(void);
static FUNC(void, RTE_CODE) Esm_RequestSocShutdownLoop(void);
static FUNC(boolean, RTE_CODE) Esm_shutdownprecondition(void);
#define Esm_STOP_SEC_CODE_LOCAL
#include <Esm_MemMap.h>

/*==================[external function definitions]=========================*/
#define Esm_START_SEC_CODE
#include <Esm_MemMap.h>
/**
 * \functions Esm_InitFunction
 *
 * \brief
 *
 ** \param[in] none
 *
 ** \param[in] none
 *
 * \return none 

 * \comments
 *
 */
FUNC(void, RTE_CODE) Esm_InitFunction (void)
{

} /* FUNC(void, RTE_CODE) Esm_InitFunction (void) */

/**
 * \functions Esm_MainFunction
 *
 * \brief
 *
 ** \param[in] none
 *
 ** \param[in] none
 *
 * \return none 

 * \comments
 *
 */
FUNC(void, RTE_CODE) Esm_MainFunction (void)
{
	Esm_Calculation();
	Esm_SocStartupPermission();
	Esm_RequestSocShutdownLoop();
} /* FUNC(void, RTE_CODE) Esm_MainFunction (void) */


/**
 * \functions Esm_v_Soc_PowerOff
 *
 * \brief
 *
 ** \param[in] none,
 *
 ** \param[out] none,
 *
 ** \return none, 
 * \comments
 *
 */
FUNC(void, RTE_CODE) Esm_v_Soc_PowerOff(void)
{
    if( TRUE == b_SocShutdownReuqest)//PRQA S 3760,1881
	{
		b_SocShutdownReuqest = FALSE; //PRQA S 1295
		b_SocPowerOnRequest = TRUE; //PRQA S 1295
		b_RunSocshutdownLoop = TRUE; //PRQA S 1295
	}
}

/**
 * \functions Esm_v_Soc_PowerOn
 *
 * \brief
 *
 ** \param[in] none,
 *
 ** \param[out] none,
 *
 ** \return none, 
 * \comments
 *
 */
FUNC(void, RTE_CODE) Esm_v_Soc_PowerOn(void)
{
	if((TRUE == b_SocPowerOnRequest)&&(b_RunSocshutdownLoop == FALSE))//PRQA S 3760,1881
	{
        b_SocPowerOnRequest = FALSE; //PRQA S 1295
		b_SocShutdownReuqest = TRUE; //PRQA S 1295
        #if (!FS_EXEC_DISABLED)
        FS_SocPwrRequest(TRUE); //PRQA S 1295
        #else
		Cdd_Pmc_SocPowerOn();
		#endif
		
	}
}

/**
 * \functions Esm_v_Soc_Reset
 *
 * \brief
 *
 ** \param[in] none,
 *
 ** \param[out] none,
 *
 ** \return none, 
 * \comments
 *
 */
FUNC(void, RTE_CODE) Esm_v_Soc_Reset(void)
{
    uint8 ui8_SocResetControlState = 0;

    (void)Rte_Read_RP_Dsm_SRI_SocResetControlState_DE_SocRersetControlState(&ui8_SocResetControlState);
	
	if((0x01u == Sdc_SendInterface_GetPWMState()) && (0x00u /*enable*/ == ui8_SocResetControlState)) //PRQA S 1823,3760,3416
	{
        Cdd_Pmc_SocHardReset();	
	}
}

/**
 * \functions Esm_v_Camera_PowerOff
 *
 * \brief
 *
 ** \param[in] none,
 *
 ** \param[out] none,
 *
 ** \return none, 
 * \comments
 *
 */
FUNC(void, RTE_CODE) Esm_v_Camera_PowerOff(void)
{
    if(TRUE == b_CameraPowerOffRequest)//PRQA S 3760,1881
	{   
		b_CameraPowerOffRequest = FALSE; //PRQA S 1295
		b_CameraPowerOnRequest = TRUE; //PRQA S 1295
        Cdd_Pmc_CamPowerOff();
	}
}

/**
 * \functions Esm_v_Camera_PowerOn
 *
 * \brief
 *
 ** \param[in] none,
 *
 ** \param[out] none,
 *
 ** \return none, 
 * \comments
 *
 */
FUNC(void, RTE_CODE) Esm_v_Camera_PowerOn(void)
{
	if(TRUE == b_CameraPowerOnRequest)//PRQA S 3760,1881
	{
		b_CameraPowerOnRequest = FALSE; //PRQA S 1295
		b_CameraPowerOffRequest = TRUE; //PRQA S 1295
        Cdd_Pmc_CamPowerOn();
	}
}

/**
 * \functions Esm_v_Ecu_SoftReset
 *
 * \brief
 *
 ** \param[in] none,
 *
 ** \param[out] none,
 *
 ** \return none, 
 * \comments
 *
 */
FUNC(void, RTE_CODE) Esm_v_Ecu_SoftReset(void)
{
#if FS_PDO_ENABLED
    g_fs_debug_status.reset_source_fs[g_fs_debug_status.reset_source_fs_count]=FS_RS_ESM;
    g_fs_debug_status.reset_source_fs_count = (g_fs_debug_status.reset_source_fs_count + 1)% 32;    
#endif /** FS_PDO_ENABLED */
    Cdd_Pmc_McuSoftReset();
}


/**
 * \functions Esm_v_Ecu_HardReset
 *
 * \brief
 *
 ** \param[in] none,
 *
 ** \param[out] none,
 *
 ** \return none, 
 * \comments
 *
 */
FUNC(void, RTE_CODE) Esm_v_Ecu_HardReset(void)
{
    Cdd_Pmc_McuHardReset();
}


/**
 * \functions Esm_v_System_Shutdown
 *
 * \brief
 *
 ** \param[in] none,
 *
 ** \param[out] none,
 *
 ** \return none, 
 * \comments
 *
 */
FUNC(void, RTE_CODE) Esm_v_System_Shutdown(void)
{
	static boolean b_call_frist_time = FALSE; //PRQA S 1295
      
	/*request shutdown*/
	if(b_call_frist_time == FALSE) //PRQA S 3760,1881
	{   
		b_call_frist_time = TRUE; //PRQA S 1295
		
		(void)Rte_Call_RP_EcuM_ShutdownTarget_Switchoff_SelectShutdownTarget(ECUM_STATE_OFF, 0);
        //before goto shutdown, set watchdog to sleep mode to disable watchdog monitor.
		(void)WdgM_SetMode(WdgMConf_WdgMMode_WDGM_SLEEP); //PRQA S 3335	
		
		(void)BswM_RequestMode(0, EB_INTGR_BSWM_SWC_CYCLIC_SHUTDOWN);//PRQA S 3212
	}

}

/**
 * \functions Esm_v_Safety_Shutdown
 *
 * \brief 
 *
 ** \param[in] none,
 *
 ** \param[out] none,
 *
 ** \return none, 
 * \comments
 *
 */
FUNC(void, RTE_CODE) Esm_v_Safety_Shutdown(void)
{
	static boolean b_call_frist_time = FALSE; //PRQA S 1295

	Esm_v_Soc_PowerOff();
    /*Loop request soc safety power off ,until successful.*/
	if((b_call_frist_time == FALSE) &&(TRUE == b_SocSafetyPoweroff)) //PRQA S 3760,1881
	{   
	    b_call_frist_time = TRUE; //PRQA S 1295
		/*CLear the flag of Soc safety power off.*/
		b_SocSafetyPoweroff = FALSE; //PRQA S 1295
            	    
        (void)Rte_Call_RP_EcuM_ShutdownTarget_Switchoff_SelectShutdownTarget(ECUM_STATE_OFF, 0);

        (void)WdgM_SetMode(WdgMConf_WdgMMode_WDGM_SLEEP);//before goto shutdown, set watchdog to sleep mode to disable watchdog monitor.

        (void)BswM_RequestMode(0, EB_INTGR_BSWM_SWC_CYCLIC_SHUTDOWN);//PRQA S 3212
	}
}

/**
 * \functions Esm_GetSocStartupFlag
 *
 * \brief 
 *
 ** \param[in] none,
 *
 ** \param[out] none,
 *
 ** \return none, 
 * \comments
 *
 */
FUNC(boolean, RTE_CODE) Esm_GetSocStartupFlag(void)
{
    return b_SocStartupCompleted;
}

#define Esm_STOP_SEC_CODE
#include <Esm_MemMap.h>


/*==================[internal function definitions]=========================*/
#define Esm_START_SEC_CODE_LOCAL
#include <Esm_MemMap.h> 
/**
 * \functions Esm_v_RequestSocShutdownLoop
 *
 * \brief Used to request safety power off of soc.
 *
 ** \param[in] none,
 *
 ** \param[out] none,
 *
 ** \return none, 
 * \comments
 *
 */
/*! LINKSTO JIRA:MFC5J3-1974*/
static FUNC(void, RTE_CODE) Esm_RequestSocShutdownLoop(void) //invoke cycle :20ms
{
	uint8 ui8_Results = E_OK;
	uint8 ui8_DioSts;
    static uint64 ui64_StartTime = 0; //PRQA S 2211
    uint64 ui64_currentTime = 0; //PRQA S 2211
	uint64 ui64_deltatime = 0; //PRQA S 2211
    static uint8 ui8_EsmState = ESM_STATE_INIT; //PRQA S 2211
    
	if(TRUE == b_RunSocshutdownLoop) //PRQA S 3760,1881
	{   
        if(ESM_STATE_INIT == ui8_EsmState)
        {
            (void)Rte_Call_RP_Time_GlobalTime_GetTimeStampMs(&ui64_StartTime);
            ui8_EsmState = ESM_STATE_ACTIVE;
        }
        
	    /*Step1: MCU side send shutdown request command via SPI.*/
		ui8_Results = Rte_Call_RP_Sdc_SendInterface_SocInfo_SocShutdownReuqest();
		
		if(ui8_Results == E_OK)
		{
			/*Step2: Soc side set GPIO to low to notification MCU execute shutdown.*/
            ui8_DioSts = Cdd_Pmc_ReadSocShutDownState();

			if(STD_LOW == ui8_DioSts)
			{
                #if (!FS_EXEC_DISABLED)
				FS_SocPwrRequest(FALSE); //PRQA S 1295
                #else
				Cdd_Pmc_SocPowerOff();
                #endif
              
				b_RunSocshutdownLoop = FALSE; //PRQA S 1295
				b_SocSafetyPoweroff = TRUE; //PRQA S 1295
                ui8_EsmState = ESM_STATE_INIT;
				ui64_StartTime = 0;

			}
			else /*Exception handling: if not get the GPIO is low shall be start time out machanism when get shutdown request via SPI.*/
			{   
			    (void)Rte_Call_RP_Time_GlobalTime_GetTimeStampMs(&ui64_currentTime);

				ui64_deltatime = (ui64_currentTime > ui64_StartTime)? (ui64_currentTime - ui64_StartTime):(ui64_StartTime- ui64_currentTime); //PRQA S 3383
				
				if(ui64_deltatime >= c_Esm_SocExceptionDelayTime) //PRQA S 3416
				{
					ui64_StartTime = 0u;
					
	                #if (!FS_EXEC_DISABLED)
				    FS_SocPwrRequest(FALSE); //PRQA S 1295
                    #else
				    Cdd_Pmc_SocPowerOff();
                    #endif
                    
					b_RunSocshutdownLoop = FALSE;  //PRQA S 1295
					b_SocSafetyPoweroff = TRUE; //PRQA S 1295
				}
			}
		}
		else
		{
            (void)Rte_Call_RP_Time_GlobalTime_GetTimeStampMs(&ui64_currentTime);
			
            ui64_deltatime = (ui64_currentTime > ui64_StartTime)? (ui64_currentTime - ui64_StartTime):(ui64_StartTime- ui64_currentTime); //PRQA S 3383
            
            if(ui64_deltatime >= c_Esm_SocExceptionDelayTime) //PRQA S 3416
		    {
			    ui64_StartTime = 0u;	
                
                #if (!FS_EXEC_DISABLED)
				FS_SocPwrRequest(FALSE);//PRQA S 1295
                #else
				Cdd_Pmc_SocPowerOff();
                #endif

			    b_RunSocshutdownLoop = FALSE;  //PRQA S 1295
			    b_SocSafetyPoweroff = TRUE; //PRQA S 1295
		    }
		}
	}
	else
	{
        /*Do nothing*/
	}   
}

/**
 * \functions Esm_shutdownprecondition
 *
 * \brief Used to Check shutdown condtion of ECU.
 *
 ** \param[in] none
 *
 ** \param[in] none
 *
 * \return none 

 * \comments
 *
 */
static FUNC(boolean, RTE_CODE) Esm_shutdownprecondition(void)
{
	static boolean b_status = FALSE; //PRQA S 1295
	uint8 ui8_CurNmState;//PRQA S 2211
	/*when the FC transmit to shutdown, the following condition shall be satisified.
	1. KL15 off.
	2.The network mode stay in sleep mode.
	3.The current vehicle speed is 0km/h.
	*/
	(void)Rte_Call_RP_Comco_CSI_nmCurrentState_nmCurrentState(&ui8_CurNmState);
	
	if(ui8_CurNmState == (uint8)nm_state_bus_sleep)
	{
		b_status = TRUE; //PRQA S 1295
	}
	else
	{
        b_status = FALSE; //PRQA S 1295
	}

	return (b_status);
}

/**
 * \functions Esm_Calculation
 *
 * \brief Used to control system shutdown when get valid shutdown event.
 *
 ** \param[in] none
 *
 ** \param[in] none
 *
 * \return none 

 * \comments
 *
 */
static FUNC(void, RTE_CODE) Esm_Calculation(void)
{
    static uint64 ui64_StartTime = 0;
    uint64 ui64_currentTime = 0;//PRQA S 2211
    static uint8 u_EsmState = ESM_STATE_INIT;//PRQA S 2211
    uint8 ui8_WakeupFlag;//PRQA S 2211
    
    (void)Rte_Call_RP_Comco_CSI_NMWakupFlag_NMWakupFlag(&ui8_WakeupFlag);
	
	 if(ESM_STATE_INIT == u_EsmState)
	 {
         (void)Rte_Call_RP_Time_GlobalTime_GetTimeStampMs(&ui64_StartTime);
		 u_EsmState = ESM_STATE_INACTIVE;
	 }
	 else if(ESM_STATE_INACTIVE == u_EsmState)
	 {
         if(!((Esm_shutdownprecondition() == (Boolean)TRUE)||(0x00u == ui8_WakeupFlag))) //PRQA S 3760,3416
		 {
             u_EsmState = ESM_STATE_ACTIVE;
		 }
		 else
		 {
			 (void)Rte_Call_RP_Time_GlobalTime_GetTimeStampMs(&ui64_currentTime);
             /*If not have any vaild wake up signal ,the FC shall not be execute shutdown within 5000ms When the ECU start up */
			 if((ui64_currentTime - ui64_StartTime) >= c_Esm_SysShutDownDelaytTime) //PRQA S 3416,3383
			 {
			     ui64_StartTime = 0;
				 Esm_v_System_Shutdown(); 
			 }
		 }
	 }else if(ESM_STATE_ACTIVE == u_EsmState)
	 {
         if(Esm_shutdownprecondition() == TRUE) //PRQA S 3760,3416,1881
		 {      
			 Esm_v_Safety_Shutdown();
		 }
	 }
	 else
	 {
         /*Do nothing.*/
	 }
}

/**
 * \functions Esm_SocStartupPermission
 *
 * \brief Used to control soc startup when get valid wakeup event.
 *
 ** \param[in] none
 *
 ** \param[in] none
 *
 * \return none 

 * \comments
 *
 */
static FUNC(void, RTE_CODE) Esm_SocStartupPermission(void)
{
	static boolean b_SocStartupFlag = TRUE; //PRQA S 1295
	uint8 ui8_WakeupFlag;//PRQA S 2211
         
    (void)Rte_Call_RP_Comco_CSI_NMWakupFlag_NMWakupFlag(&ui8_WakeupFlag);

	if(TRUE == b_SocStartupFlag)//PRQA S 3760,1881
    {
        /*Only run in start up sequence */
        if(WAKEUP_SUCCESSFUL == ui8_WakeupFlag)
        {
            b_SocStartupFlag = FALSE; //PRQA S 1295

            Esm_v_Soc_PowerOn();

	        b_SocStartupCompleted = TRUE; //PRQA S 1295		
	    }
	    else
	    {/*Do nothings*/}
    }
}

#define Esm_STOP_SEC_CODE_LOCAL
#include <Esm_MemMap.h> 


