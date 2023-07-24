/**
 * \file Med_Core.c
 *
 * \brief Implement the Mcu Error Detection main logic
 *
 * \version refer the Med_Core.h.
 *
 */

/*==================[inclusions]============================================*/
#include "Rte_Med.h"
#include "Med_Core.h"
#include "Dem.h"
#include "Dsm_Cfg.h"

/*==================[external data]=========================================*/


/*==================[internal data]=========================================*/
e_Med_InitStatus_t Med_Core_InitStatus = Med_InitStatus_Uninit;
s_Med_ErrorDetectionState_t Med_ErrorDetectionState[MED_ERROR_DETECTION_NUMBER];

/*==================[internal function declarations]========================*/
static void Med_Core_ErrorDetectionProcess_InitFunction(void);
static void Med_Core_ErrorDetectionProcess_MainFunction(void);
static boolean Med_Core_ErrorDetectionProcess_CheckPreCond(s_Med_ErrorDetectionConfig_t cfg);
static boolean Med_Core_ErrorDetectionProcess_CheckTestFailed(s_Med_ErrorDetectionConfig_t cfg);
static boolean Med_Core_ErrorDetectionProcess_CheckTestPassed(s_Med_ErrorDetectionConfig_t cfg);
static e_Med_ErrorDetectionStatus_t Med_Core_ErrorDetectionProcess_MutexMode(s_Med_ErrorDetectionConfig_t cfg);
static e_Med_ErrorDetectionStatus_t Med_Core_ErrorDetectionProcess_CoincideMode(e_Med_ErrorDetectionStatus_t status_last,s_Med_ErrorDetectionConfig_t cfg);
static boolean Med_Core_ErrorDetectionProcess_MainLogic(s_Med_ErrorDetectionConfig_t cfg, s_Med_ErrorDetectionState_t* var);

/*==================[external function definitions]=========================*/
/**
 * \functions Med_Core_InitFunction
 *
 * \brief Implement the Mcu Error Detection main logic
 *
 * \parameters-in none
 *
 * \parameters-out none
 *
 * \return none
 *
 * \comments
 *
 */
void Med_Core_InitFunction(void)
{
#if ((defined MED_USERINITFUNCION_ENABLED) && (MED_USERINITFUNCION_ENABLED == STD_ON))
    Med_UserInitFunction();
#endif

	/*TODO: Initialized internal and external variables*/
	Med_Core_ErrorDetectionProcess_InitFunction();
	Med_Core_InitStatus = Med_InitStatus_Init;
}

/**
 * \functions Med_Core_InitFunction
 *
 * \brief
 *
 * \parameters-in none
 *
 * \parameters-out none
 *
 * \return none
 *
 * \comments
 *
 */
void Med_Core_MainFunction(void)
{
#if ((defined MED_INJECTION_ENABLED) && (MED_INJECTION_ENABLED == STD_ON))
    static uint8 ui8_InternalTestMode = 0;
#endif
	/*TODO: Check the Med_Core is initialization*/
	if(Med_InitStatus_Init == Med_Core_InitStatus)
	{
		/*TODO:If the Med initialized,go next step.*/
	}
	else
	{
		/*TODO: doing nothing or report Det*/
		return;
	}
	#if(MED_USERMAINFUNCTION_ENABLE == STD_ON)
		Med_UserMainFunction();
	#endif

	#if ((defined MED_INJECTION_ENABLED) && (MED_INJECTION_ENABLED == STD_ON))

	(void)Rte_Read_RP_Dsm_SRI_InternalTestMode_DE_InternalTestMode(&ui8_InternalTestMode);

	if(ui8_InternalTestMode == DSM_INTERNALTESTMODE_ON)
    {
	    Med_Injection();	    
	}
	else
	#endif
	{
	    /*TODO:Error Detection Process*/
	    Med_Core_ErrorDetectionProcess_MainFunction();
	}
}

/*==================[internal function definitions]=========================*/
/**
 * \functions Med_Core_ErrorDetectionProcess_InitFunction
 *
 * \brief Initialized related variable of Error Detection Process
 *
 * \parameters-in none
 *
 * \parameters-out none
 *
 * \return 	none
 *
 * \comments
 *
 */
static void Med_Core_ErrorDetectionProcess_InitFunction(void)
{
	uint8 i = 0x00;

	/*TODO: Init related variable of ErrorDetection Process*/
	for(i = 0x00; i < MED_ERROR_DETECTION_NUMBER; i++)
	{
		Med_ErrorDetectionState[i].Status = Med_ErrDetSts_Init;
#if (MED_ERROR_DETECTION_STATUS_CHANGED_NOTIFICATION == STD_ON)
		Med_ErrorDetectionState[i].Status_Last = Med_ErrDetSts_Init;
#endif
		Med_ErrorDetectionState[i].MonitorCycleCounter = 0x00;
	}
}

/**
 * \functions Med_Core_ErrorDetectionProcess_MainFunction
 *
 * \brief handling Error Detection Process
 *
 * \parameters-in none
 *
 * \parameters-out none
 *
 * \return 	none
 *
 * \comments
 *
 */
static void Med_Core_ErrorDetectionProcess_MainFunction(void)
{
	uint8 i = 0x00;

	for(i = 0x00; i < MED_ERROR_DETECTION_NUMBER; i++)
	{
		/*TODO : Check the Monitor cycle*/
		Med_ErrorDetectionState[i].MonitorCycleCounter++;
		if(Med_ErrorDetectionState[i].MonitorCycleCounter >= (Med_ErrorDetectionConfigTable[i].MonitorCycle / MED_MAIN_FUNCTION_PERIOD_TIME))
		{
			Med_ErrorDetectionState[i].MonitorCycleCounter = 0x00;/*TODO : When the counter reached,clean*/
			Med_Core_ErrorDetectionProcess_MainLogic(Med_ErrorDetectionConfigTable[i], &Med_ErrorDetectionState[i]);
		}
		else
		{
			/*TODO: The Monitor cycle not reached,skip.*/
		}
	}
}

/**
 * \functions Med_Core_ErrorDetectionProcess_CheckPreCond
 *
 * \brief Check the pre-conditions of monitor cycle
 *
 * \parameters-in cfg
 *
 * \parameters-out none
 *
 * \return 	FALSE : The pre-conditions is satisfy
 * 			TRUE : The pre-conditions is not satisfy
 *
 * \comments
 *
 */
static boolean Med_Core_ErrorDetectionProcess_CheckPreCond(s_Med_ErrorDetectionConfig_t cfg)
{
	boolean ret = FALSE;

	/*TODO: Check the pointer is null*/
	if(NULL_PTR != cfg.Op_CheckPreCond)
	{
		/*TODO: Check the pre-condition is satisfy*/
		if(TRUE == cfg.Op_CheckPreCond())
		{
			ret = TRUE;
		}
		else
		{
			ret = FALSE;
		}
	}
	else
	{
		/*TODO: If the function pointer of Op_CheckPreCond is NULL,it means skip the pre-condition check*/
		ret = TRUE;
	}

	return ret;
}

/**
 * \functions Med_Core_ErrorDetectionProcess_CheckTestFailed
 *
 * \brief Check the test failed conditions
 *
 * \parameters-in cfg
 *
 * \parameters-out none
 *
 * \return 	FALSE : The test failed conditions is satisfy
 * 			TRUE : The test failed conditions is not satisfy
 *
 * \comments
 *
 */
static boolean Med_Core_ErrorDetectionProcess_CheckTestFailed(s_Med_ErrorDetectionConfig_t cfg)
{
	boolean ret = FALSE;

	/*TODO: Check the pointer is null*/
	if(NULL_PTR != cfg.Op_TestFailed)
	{
		/*TODO: Check the TestFailed is satisfy*/
		if(TRUE == cfg.Op_TestFailed())
		{
			ret = TRUE;/*Detected an error*/
		}
		else
		{
			ret = FALSE;
		}
	}
	else
	{
		/*TODO: If the function pointer of Op_TestFailed is NULL,it means not detected error*/
		ret = FALSE;
	}

	return ret;
}

/**
 * \functions Med_Core_ErrorDetectionProcess_CheckTestPassed
 *
 * \brief Check the test passed conditions
 *
 * \parameters-in cfg
 *
 * \parameters-out none
 *
 * \return 	FALSE : The test passed conditions is satisfy
 * 			TRUE : The test passed conditions is not satisfy
 *
 * \comments
 *
 */
static boolean Med_Core_ErrorDetectionProcess_CheckTestPassed(s_Med_ErrorDetectionConfig_t cfg)
{
	boolean ret = FALSE;

	/*TODO: Check the pointer is null*/
	if(NULL_PTR != cfg.Op_TestPassed)
	{
		/*TODO: Check the TestFailed is satisfy*/
		if(TRUE == cfg.Op_TestPassed())
		{
			ret = TRUE;/*an error is recovery*/
		}
		else
		{
			ret = FALSE;
		}
	}
	else
	{
		/*TODO: If the function pointer of Op_TestPassed is NULL,it means not detected error*/
		ret = TRUE;
	}

	return ret;
}

/**
 * \functions Med_Core_ErrorDetectionProcess_MutexMode
 *
 * \brief
 *
 * \parameters-in cfg
 *
 * \parameters-out none
 *
 * \return 	Error Detection result of Mutex Mode
 *
 * \comments
 *
 */
static e_Med_ErrorDetectionStatus_t Med_Core_ErrorDetectionProcess_MutexMode(s_Med_ErrorDetectionConfig_t cfg)
{
	e_Med_ErrorDetectionStatus_t Status = Med_ErrDetSts_Init;

	/*TODO: Check the function pointer is NULL*/
	if(NULL_PTR != cfg.Op_TestFailed)
	{
		if(TRUE == Med_Core_ErrorDetectionProcess_CheckTestFailed(cfg))
		{
			/*TODO: Detected an Error*/
			Status = Med_ErrDetSts_TestFailed;
		}
		else
		{
			/*TODO: Detected the error recovery*/
			Status = Med_ErrDetSts_TestPassed;
		}
	}
	else
	{
		Status = Med_ErrDetSts_Init;
	}

	return Status;
}

/**
 * \functions Med_Core_ErrorDetectionProcess_CoincideMode
 *
 * \brief
 *
 * \parameters-in cfg
 *
 * \parameters-out none
 *
 * \return 	Error Detection result of Coincide Mode
 *
 * \comments
 *
 */
static e_Med_ErrorDetectionStatus_t Med_Core_ErrorDetectionProcess_CoincideMode(e_Med_ErrorDetectionStatus_t status_last,s_Med_ErrorDetectionConfig_t cfg)
{
	e_Med_ErrorDetectionStatus_t Status = Med_ErrDetSts_Init;

	if((NULL_PTR == cfg.Op_TestFailed) || (NULL_PTR == cfg.Op_TestPassed))
	{
		Status = Med_ErrDetSts_Init;
		return Status;
	}
	else
	{
		/*TODO:Doing nothing,go to next step*/
	}

	/*TODO: According the current to check the test failed or test passed conditions*/
	if((Med_ErrDetSts_Init == status_last) || (Med_ErrDetSts_TestPassed == status_last))
	{
		/*TODO: Check the TestFailed*/
		if(TRUE == Med_Core_ErrorDetectionProcess_CheckTestFailed(cfg))
		{
			/*TODO: Detected an Error*/
			Status = Med_ErrDetSts_TestFailed;
		}
		else
		{
			Status = Med_ErrDetSts_TestPassed;
		}
	}
	else if(Med_ErrDetSts_TestFailed == status_last)
	{
		/*TODO: Check the TestPassed*/
		if(TRUE == Med_Core_ErrorDetectionProcess_CheckTestPassed(cfg))
		{
			/*TODO: an Error recovery*/
			Status = Med_ErrDetSts_TestPassed;
		}
		else
		{
			Status = Med_ErrDetSts_TestFailed;
		}
	}
	else
	{
		Status = status_last;
	}

	return Status;
}

/**
 * \functions Med_Core_ErrorDetectionProcess_MainLogic
 *
 * \brief Implement the Mcu Error Detection main logic
 *
 * \parameters-in cfg/var
 *
 * \parameters-out var
 *
 * \return 	FALSE : This cycle error detection not completed
 * 			TRUE : This cycle error detection completed
 *
 * \comments
 *
 */
static boolean Med_Core_ErrorDetectionProcess_MainLogic(s_Med_ErrorDetectionConfig_t cfg, s_Med_ErrorDetectionState_t* var)
{
	boolean TestStatus = FALSE;

	/*TODO: Check the pointer is null*/
	if(NULL_PTR == var)
	{
		/*TODO: */
		return TestStatus;
	}
	else
	{
		/*TODO: The pre-condition is satisfy,go to next step*/
		/*TODO : Doing nothing*/
	}

	/*TODO: Check the pre-conditions*/
	if(TRUE != Med_Core_ErrorDetectionProcess_CheckPreCond(cfg))
	{
		/*TODO: The pre-condition is not satisfy,stop this cycle error detection */
		return TestStatus;
	}
	else
	{
		/*TODO: The pre-condition is satisfy,go to next step*/
		/*TODO : Doing nothing*/
	}

	/*TODO : According the mode to check test failed or test passed conditions*/
	if(Med_ErrDetMode_Mutex == cfg.Mode)
	{
		var->Status = Med_Core_ErrorDetectionProcess_MutexMode(cfg);
		if((Med_ErrDetSts_TestFailed == var->Status) || (Med_ErrDetSts_TestPassed == var->Status))
		{
			TestStatus = TRUE;/*error detection completed*/
		}
		else
		{
			/*TODO : Doing nothing*/
		}
	}
	else if(Med_ErrDetMode_Coincide == cfg.Mode)
	{
		var->Status = Med_Core_ErrorDetectionProcess_CoincideMode(var->Status,cfg);
		if((Med_ErrDetSts_TestFailed == var->Status) || (Med_ErrDetSts_TestPassed == var->Status))
		{
			TestStatus = TRUE;/*error detection completed*/
		}
		else
		{
			/*TODO : Doing nothing*/
		}
	}
	else
	{
		/*TODO : Doing nothing*/
	}

	/*TODO: According the ErrDetSts,report error to Dem*/
	if(TRUE == TestStatus)/*TODO: Check the test completed*/
	{
		if(STD_OFF == cfg.DebounceEnable)/*Debounce in Dem*/
		{
			if(Med_ErrDetSts_TestFailed == var->Status)
			{
#if (STD_ON == MED_USE_RTE_REPORT_EVENT_STATUS)
				if(NULL_PTR != cfg.Op_SetEventStatus)
				{
					cfg.Op_SetEventStatus(DEM_EVENT_STATUS_PREFAILED);
				}
				else
				{
					/*TODO : Doing nothing*/
				}
#else
				if(0x00 != cfg.EventId)
				{
					Dem_SetEventStatus(cfg.EventId, DEM_EVENT_STATUS_PREFAILED);/*pre-testFailed*/
				}
				else
				{
					/*TODO: Doing nothing*/
				}
#endif
			}
			else if(Med_ErrDetSts_TestPassed == var->Status)
			{
#if (STD_ON == MED_USE_RTE_REPORT_EVENT_STATUS)
				if(NULL_PTR != cfg.Op_SetEventStatus)
				{
					cfg.Op_SetEventStatus(DEM_EVENT_STATUS_PREPASSED);
				}
				else
				{
					/*TODO : Doing nothing*/
				}
#else
				if(0x00 != cfg.EventId)
				{
					Dem_SetEventStatus(cfg.EventId, DEM_EVENT_STATUS_PREPASSED);/*pre-testPassed*/
				}
				else
				{
					/*TODO: Doing nothing*/
				}
#endif
			}
			else
			{
				/*TODO : Doing nothing*/
			}
		}
		else if(STD_ON == cfg.DebounceEnable)/*Debounce in Med*/
		{
			if(Med_ErrDetSts_TestFailed == var->Status)
			{
#if (STD_ON == MED_USE_RTE_REPORT_EVENT_STATUS)
				if(NULL_PTR != cfg.Op_SetEventStatus)
				{
					cfg.Op_SetEventStatus(DEM_EVENT_STATUS_FAILED);
				}
				else
				{
					/*TODO : Doing nothing*/
				}
#else
				if(0x00 != cfg.EventId)
				{
					Dem_SetEventStatus(cfg.EventId, DEM_EVENT_STATUS_FAILED);/*testFailed*/
				}
				else
				{
					/*TODO: Doing nothing*/
				}
#endif
			}
			else if(Med_ErrDetSts_TestPassed == var->Status)
			{
#if (STD_ON == MED_USE_RTE_REPORT_EVENT_STATUS)
				if(NULL_PTR != cfg.Op_SetEventStatus)
				{
					cfg.Op_SetEventStatus(DEM_EVENT_STATUS_PASSED);
				}
				else
				{
					/*TODO : Doing nothing*/
				}
#else
				if(0x00 != cfg.EventId)
				{
					Dem_SetEventStatus(cfg.EventId, DEM_EVENT_STATUS_PASSED);/*testPassed*/
				}
				else
				{
					/*TODO : Doing nothing*/
				}
#endif
			}
			else
			{
				/*TODO : Doing nothing*/
			}
		}
		else
		{
			/*TODO : Doing nothing*/
		}
	}
	else
	{
		/*TODO : Doing nothing*/
	}

#if (MED_ERROR_DETECTION_STATUS_CHANGED_NOTIFICATION == STD_ON)
	/*TODO:According the status to call function */
	if(cfg.Notify_ErrDetStsChanged != NULL_PTR)
	{
		cfg.Notify_ErrDetStsChanged(var->Status,var->Status_Last);
		var->Status_Last = var->Status;
	}
#endif

	return TestStatus;
}
