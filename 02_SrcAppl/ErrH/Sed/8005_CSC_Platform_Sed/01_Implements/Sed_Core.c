/**
 * \file Sed_Core.c
 *
 * \brief Implement the Mcu Error Detection main logic
 *
 * \version refer the Sed_Core.h.
 *
 */

/*==================[inclusions]============================================*/
#include "Sed_Core.h"
#include "Dem.h"

/*==================[external data]=========================================*/


/*==================[internal data]=========================================*/
e_Sed_InitStatus_t Sed_Core_InitStatus = Sed_InitStatus_Uninit;
s_Sed_ErrorDetectionState_t Sed_ErrorDetectionState[SED_ERROR_DETECTION_NUMBER];

/*==================[internal function declarations]========================*/
static void Sed_Core_ErrorDetectionProcess_InitFunction(void);
static void Sed_Core_ErrorDetectionProcess_MainFunction(void);
static boolean Sed_Core_ErrorDetectionProcess_CheckPreCond(s_Sed_ErrorDetectionConfig_t cfg);
static boolean Sed_Core_ErrorDetectionProcess_CheckTestFailed(s_Sed_ErrorDetectionConfig_t cfg);
static boolean Sed_Core_ErrorDetectionProcess_CheckTestPassed(s_Sed_ErrorDetectionConfig_t cfg);
static e_Sed_ErrorDetectionStatus_t Sed_Core_ErrorDetectionProcess_MutexMode(s_Sed_ErrorDetectionConfig_t cfg);
static e_Sed_ErrorDetectionStatus_t Sed_Core_ErrorDetectionProcess_CoincideMode(e_Sed_ErrorDetectionStatus_t status_last,s_Sed_ErrorDetectionConfig_t cfg);
static boolean Sed_Core_ErrorDetectionProcess_MainLogic(s_Sed_ErrorDetectionConfig_t cfg, s_Sed_ErrorDetectionState_t* var);

/*==================[external function definitions]=========================*/
/**
 * \functions Sed_Core_InitFunction
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
void Sed_Core_InitFunction(void)
{
	/*TODO: Initialized internal and external variables*/
	Sed_Core_ErrorDetectionProcess_InitFunction();
    #if(SED_USERFUNCTION_ENABLE == STD_ON)
        Sed_UserInitFunction();
    #endif
	Sed_Core_InitStatus = Sed_InitStatus_Init;
}

/**
 * \functions Sed_Core_InitFunction
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
void Sed_Core_MainFunction(void)
{
	/*TODO: Check the Sed_Core is initialization*/
	if(Sed_InitStatus_Init == Sed_Core_InitStatus)
	{
		/*TODO:If the Sed initialized,go next step.*/
	}
	else
	{
		/*TODO: doing nothing or report Det*/
		return;
	}
	#if(SED_USERFUNCTION_ENABLE == STD_ON)
		Sed_UserMainFunction();
	#endif
	/*TODO:Error Detection Process*/
	Sed_Core_ErrorDetectionProcess_MainFunction();
}

/*==================[internal function definitions]=========================*/
/**
 * \functions Sed_Core_ErrorDetectionProcess_InitFunction
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
static void Sed_Core_ErrorDetectionProcess_InitFunction(void)
{
	uint8 i = 0x00;

	/*TODO: Init related variable of ErrorDetection Process*/
	for(i = 0x00; i < SED_ERROR_DETECTION_NUMBER; i++)
	{
		Sed_ErrorDetectionState[i].Status = Sed_ErrDetSts_Init;
#if (Sed_ERROR_DETECTION_STATUS_CHANGED_NOTIFICATION == STD_ON)
		Sed_ErrorDetectionState[i].Status_Last = Sed_ErrDetSts_Init;
#endif
		Sed_ErrorDetectionState[i].MonitorCycleCounter = 0x00;
	}
}

/**
 * \functions Sed_Core_ErrorDetectionProcess_MainFunction
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
static void Sed_Core_ErrorDetectionProcess_MainFunction(void)
{
	uint8 i = 0x00;

	for(i = 0x00; i < SED_ERROR_DETECTION_NUMBER; i++)
	{
		/*TODO : Check the Monitor cycle*/
		Sed_ErrorDetectionState[i].MonitorCycleCounter++;
		if(Sed_ErrorDetectionState[i].MonitorCycleCounter >= (Sed_ErrorDetectionConfigTable[i].MonitorCycle / SED_MAIN_FUNCTION_PERIOD_TIME))
		{
			Sed_ErrorDetectionState[i].MonitorCycleCounter = 0x00;/*TODO : When the counter reached,clean*/
			Sed_Core_ErrorDetectionProcess_MainLogic(Sed_ErrorDetectionConfigTable[i], &Sed_ErrorDetectionState[i]);
		}
		else
		{
			/*TODO: The Monitor cycle not reached,skip.*/
		}
	}
}

/**
 * \functions Sed_Core_ErrorDetectionProcess_CheckPreCond
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
static boolean Sed_Core_ErrorDetectionProcess_CheckPreCond(s_Sed_ErrorDetectionConfig_t cfg)
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
 * \functions Sed_Core_ErrorDetectionProcess_CheckTestFailed
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
static boolean Sed_Core_ErrorDetectionProcess_CheckTestFailed(s_Sed_ErrorDetectionConfig_t cfg)
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
 * \functions Sed_Core_ErrorDetectionProcess_CheckTestPassed
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
static boolean Sed_Core_ErrorDetectionProcess_CheckTestPassed(s_Sed_ErrorDetectionConfig_t cfg)
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
 * \functions Sed_Core_ErrorDetectionProcess_MutexMode
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
static e_Sed_ErrorDetectionStatus_t Sed_Core_ErrorDetectionProcess_MutexMode(s_Sed_ErrorDetectionConfig_t cfg)
{
	e_Sed_ErrorDetectionStatus_t Status = Sed_ErrDetSts_Init;

	/*TODO: Check the function pointer is NULL*/
	if(NULL_PTR != cfg.Op_TestFailed)
	{
		if(TRUE == Sed_Core_ErrorDetectionProcess_CheckTestFailed(cfg))
		{
			/*TODO: Detected an Error*/
			Status = Sed_ErrDetSts_TestFailed;
		}
		else
		{
			/*TODO: Detected the error recovery*/
			Status = Sed_ErrDetSts_TestPassed;
		}
	}
	else
	{
		Status = Sed_ErrDetSts_Init;
	}

	return Status;
}

/**
 * \functions Sed_Core_ErrorDetectionProcess_CoincideMode
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
static e_Sed_ErrorDetectionStatus_t Sed_Core_ErrorDetectionProcess_CoincideMode(e_Sed_ErrorDetectionStatus_t status_last,s_Sed_ErrorDetectionConfig_t cfg)
{
	e_Sed_ErrorDetectionStatus_t Status = Sed_ErrDetSts_Init;

	if((NULL_PTR == cfg.Op_TestFailed) || (NULL_PTR == cfg.Op_TestPassed))
	{
		Status = Sed_ErrDetSts_Init;
		return Status;
	}
	else
	{
		/*TODO:Doing nothing,go to next step*/
	}

	/*TODO: According the current to check the test failed or test passed conditions*/
	if((Sed_ErrDetSts_Init == status_last) || (Sed_ErrDetSts_TestPassed == status_last))
	{
		/*TODO: Check the TestFailed*/
		if(TRUE == Sed_Core_ErrorDetectionProcess_CheckTestFailed(cfg))
		{
			/*TODO: Detected an Error*/
			Status = Sed_ErrDetSts_TestFailed;
		}
		else
		{
			Status = Sed_ErrDetSts_TestPassed;
		}
	}
	else if(Sed_ErrDetSts_TestFailed == status_last)
	{
		/*TODO: Check the TestPassed*/
		if(TRUE == Sed_Core_ErrorDetectionProcess_CheckTestPassed(cfg))
		{
			/*TODO: an Error recovery*/
			Status = Sed_ErrDetSts_TestPassed;
		}
		else
		{
			Status = Sed_ErrDetSts_TestFailed;
		}
	}
	else
	{
		Status = status_last;
	}

	return Status;
}

/**
 * \functions Sed_Core_ErrorDetectionProcess_MainLogic
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
static boolean Sed_Core_ErrorDetectionProcess_MainLogic(s_Sed_ErrorDetectionConfig_t cfg, s_Sed_ErrorDetectionState_t* var)
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
	if(TRUE != Sed_Core_ErrorDetectionProcess_CheckPreCond(cfg))
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
	if(Sed_ErrDetMode_Mutex == cfg.Mode)
	{
		var->Status = Sed_Core_ErrorDetectionProcess_MutexMode(cfg);
		if((Sed_ErrDetSts_TestFailed == var->Status) || (Sed_ErrDetSts_TestPassed == var->Status))
		{
			TestStatus = TRUE;/*error detection completed*/
		}
		else
		{
			/*TODO : Doing nothing*/
		}
	}
	else if(Sed_ErrDetMode_Coincide == cfg.Mode)
	{
		var->Status = Sed_Core_ErrorDetectionProcess_CoincideMode(var->Status,cfg);
		if((Sed_ErrDetSts_TestFailed == var->Status) || (Sed_ErrDetSts_TestPassed == var->Status))
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
			if(Sed_ErrDetSts_TestFailed == var->Status)
			{
#if (STD_ON == SED_USE_RTE_REPORT_EVENT_STATUS)
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
			else if(Sed_ErrDetSts_TestPassed == var->Status)
			{
#if (STD_ON == SED_USE_RTE_REPORT_EVENT_STATUS)
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
		else if(STD_ON == cfg.DebounceEnable)/*Debounce in Sed*/
		{
			if(Sed_ErrDetSts_TestFailed == var->Status)
			{
#if (STD_ON == SED_USE_RTE_REPORT_EVENT_STATUS)
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
			else if(Sed_ErrDetSts_TestPassed == var->Status)
			{
#if (STD_ON == SED_USE_RTE_REPORT_EVENT_STATUS)
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

#if (Sed_ERROR_DETECTION_STATUS_CHANGED_NOTIFICATION == STD_ON)
	/*TODO:According the status to call function */
	if(cfg.Notify_ErrDetStsChanged != NULL_PTR)
	{
		cfg.Notify_ErrDetStsChanged(var->Status,var->Status_Last);
		var->Status_Last = var->Status;
	}
#endif

	return TestStatus;
}
