/**
 * \file   Dsm_SecurityAccess.c
 *
 * \brief  UDS SecurityAccess service(27)
 *
 * \version refer the Rte_Dsm.h.
 * 
 * \copyright  2021 - 2022 Conti Smart Core
 *
 */
/*==================[inclusions]============================================*/
#include <Rte_Dsm.h>
#include "Dsm_Cfg.h"
#include "Dsm_Main.h"
#include "McalLib.h"
#include "Cdm.h"
#include <Nvm_Cfg.h>

/*==================[external constants definition]=========================*/


/*==================[internal constants definition]=========================*/


/*==================[external data definition]==============================*/


/*==================[internal data definition]==============================*/
#if(DSM_FEAT_MEMMAP_EB_IS_USED == STD_ON)
    #define Dsm_START_SEC_VAR_UNSPECIFIED
    #include <Dsm_MemMap.h>
#endif
static uint8 a_Seed_Level1[4] = {0}; /*Generate Seed for Service 0x27*/
#if(DSM_FEAT_MEMMAP_EB_IS_USED == STD_ON)
    #define Dsm_STOP_SEC_VAR_UNSPECIFIED
    #include <Dsm_MemMap.h>
#endif

/*==================[internal function declarations]========================*/
static uint8 u_GetAttemptCounter(e_Dsm_SALevel_t level);
static uint8 u_SetAttemptCounter(Dcm_OpStatusType OpStatus, e_Dsm_SALevel_t level, uint8 AttemptCounter);
static uint32 u_RandomGenerator(void);
#if((DSM_SYSTEM_TYPE == DSM_SYSTEM_MFC5J3_C673)|| \
    (DSM_SYSTEM_TYPE == DSM_SYSTEM_MFC5J3_C385))
static uint32 u_ChangAn_SecurityAlgorithm(void);
#endif

/*==================[external function definitions]=========================*/
#if(DSM_FEAT_MEMMAP_EB_IS_USED == STD_ON)
    #define Dsm_START_SEC_CODE
    #include <Dsm_MemMap.h> /* PRQA S 5087 */
#endif
/**
 * \functions Dsm_u_SA_Level1_GetSeed
 *
 * \brief
 *
 ** \param[out] ErrorCode,
 *
 ** \param[out] Seed,
 *
 ** \return none, 
 * \comments
 *
 */
FUNC(Std_ReturnType, RTE_CODE) Dsm_u_SA_Level1_GetSeed (Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_APPL_DATA) Seed, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_APPL_DATA) ErrorCode) /*PRQA S 3227,3432*/
{
    /* suppress compiler warnings about unused arguments */
    (void)OpStatus; /*PRQA S 3119*/
#if((DSM_SYSTEM_TYPE == DSM_SYSTEM_MFC5J3_C673)|| \
    (DSM_SYSTEM_TYPE == DSM_SYSTEM_MFC5J3_C385))
	uint32 u_LocalSeed;
	u_LocalSeed = u_RandomGenerator();

#if(DSM_FEAT_SECURITY_ACCESS_TEST == STD_ON)
	a_Seed_Level1[0] = 0;
	a_Seed_Level1[1] = 0;
	a_Seed_Level1[2] = 0;
    a_Seed_Level1[3] = 0;
#else
	/* PRQA S 3120 ++ */ /* Magic numbers, more readable like this */
	a_Seed_Level1[0] = (uint8)(u_LocalSeed);
	a_Seed_Level1[1] = (uint8)(u_LocalSeed >> 8);
	a_Seed_Level1[2] = (uint8)(u_LocalSeed >> 16);
	a_Seed_Level1[3] = (uint8)(u_LocalSeed >> 24);
	/* PRQA S 3120 -- */
#endif

	/* PRQA S 0492,3120 ++ */ /* Array subscripting necessary, proven in use */
	Seed[0] = a_Seed_Level1[0];
	Seed[1] = a_Seed_Level1[1];
	Seed[2] = a_Seed_Level1[2];
	Seed[3] = a_Seed_Level1[3];
	/* PRQA S 0492,3120 -- */
	*ErrorCode = E_OK;
	return E_OK;
#endif

}

/**
 * \functions Dsm_u_SA_Level1_CompareKey
 *
 * \brief
 *
 ** \param[in] Key,
 *
 ** \param[out] none,
 *
 ** \return none, 
 * \comments
 *
 */
FUNC(Std_ReturnType, RTE_CODE) Dsm_u_SA_Level1_CompareKey (P2CONST(uint8, AUTOMATIC, RTE_APPL_DATA) Key, Dcm_OpStatusType OpStatus) /*PRQA S 3227*/
{
    /* suppress compiler warnings about unused arguments */
    (void)OpStatus;/*PRQA S 3119*/
    Std_ReturnType u_RetVal = E_NOT_OK;
#if((DSM_SYSTEM_TYPE == DSM_SYSTEM_MFC5J3_C673)|| \
    (DSM_SYSTEM_TYPE == DSM_SYSTEM_MFC5J3_C385))

	uint32 u_InterKey = 0u; /*PRQA S 2211*/
	uint32 u_OutKey = 0u;
	u_InterKey = u_ChangAn_SecurityAlgorithm();
	u_OutKey = (uint32)(Key[3] + (Key[2] << 8) + (Key[1] << 16) + (Key[0] << 24)); /*PRQA S 0499,3120,4391*/

	if (u_InterKey != u_OutKey)
	{
		u_RetVal = DCM_E_COMPARE_KEY_FAILED;

	}
	else
	{
        u_RetVal = E_OK;
	}

#endif
	return u_RetVal;
}


/**
 * \functions Dsm_u_SA_Level1_GetAttemptCounter
 *
 * \brief
 *
 ** \param[in] none,
 *
 ** \param[out] AttemptCounter,
 *
 ** \return none, 
 * \comments
 *
 */
FUNC(Std_ReturnType, RTE_CODE) Dsm_u_SA_Level1_GetAttemptCounter (Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_APPL_DATA) AttemptCounter) /*PRQA S 3227,3432*/
{
    (void)OpStatus;/*PRQA S 3119*/
#if((DSM_SYSTEM_TYPE == DSM_SYSTEM_MFC5J3_C673)|| \
    (DSM_SYSTEM_TYPE == DSM_SYSTEM_MFC5J3_C385))
 
   *AttemptCounter = u_GetAttemptCounter(SA_Level1);

#endif
    return E_OK;
}

/**
 * \functions Dsm_u_SA_Level1_SetAttemptCounter
 *
 * \brief
 *
 ** \param[in] AttemptCounter,
 *
 ** \param[out] none,
 *
 ** \return none, 
 * \comments
 *
 */
FUNC(Std_ReturnType, RTE_CODE) Dsm_u_SA_Level1_SetAttemptCounter (Dcm_OpStatusType OpStatus, uint8 AttemptCounter)/*PRQA S 3227*/
{
    Std_ReturnType u_Retval = RTE_E_OK;
	
#if((DSM_SYSTEM_TYPE == DSM_SYSTEM_MFC5J3_C673)|| \
    (DSM_SYSTEM_TYPE == DSM_SYSTEM_MFC5J3_C385))
 
	u_Retval = u_SetAttemptCounter(OpStatus,SA_Level1, AttemptCounter);
    
#endif

    return u_Retval;
}

#if(DSM_FEAT_MEMMAP_EB_IS_USED == STD_ON)
    #define Dsm_STOP_SEC_CODE
    #include <Dsm_MemMap.h> /* PRQA S 5087 */
#endif

/*==================[internal function definitions]=========================*/
/**
 * \functions u_GetAttemptCounter
 *
 * \brief 
 *
 ** \param[in] level,
 *
 ** \return E_OK, 
 * \comments
 *
 */
static uint8 u_GetAttemptCounter(e_Dsm_SALevel_t level) /*PRQA S 3227*/
{	  
	uint8 u_AttemptCounter = 0u;
	
    if(SA_Level1 == level)
    {
        /*byte1: used for storing security L1 attempt counter, byte2: Reserved for storing security L2 attempt counter*/
        if(RAM_NVM_BLOCK_Security_AttemptCount[0] != 0x0u)
        {
            u_AttemptCounter = RAM_NVM_BLOCK_Security_AttemptCount[0];
        }
	}else if(SA_Level2 == level)
	{
	    if(RAM_NVM_BLOCK_Security_AttemptCount[1] != 0x0u)
        {
            u_AttemptCounter = RAM_NVM_BLOCK_Security_AttemptCount[1];
        }
	}
	else
	{
        /*Do nothing.*/
	}
		
    return u_AttemptCounter;

}

/**
 * \functions u_SetAttemptCounter
 *
 * \brief 
 *
 ** \param[in] level,
 *
 ** \param[in] AttemptCounter,
 *
 ** \return E_OK, 
 * \comments
 *
 */
static uint8 u_SetAttemptCounter(Dcm_OpStatusType OpStatus, e_Dsm_SALevel_t level, uint8 AttemptCounter) /*PRQA S 3227*/
{
	Std_ReturnType u_RetVal = RTE_E_OK; /* Result of this function */
	Std_ReturnType ui8_RetVal_Write = RTE_E_INVALID;
	Std_ReturnType ui8_RetVal_ErrStat = RTE_E_INVALID;
	NvM_RequestResultType ui8_WriteStatus = NVM_REQ_NOT_OK;	/*PRQA S 2211*/
	boolean b_NvmOperationPending = (Boolean)FALSE; /*PRQA S 2211*/  
    static boolean b_WriteFlagSuccess; /*PRQA S 2211*/
	
	if ((uint8) DCM_INITIAL == OpStatus)
	{
	    b_WriteFlagSuccess = (Boolean)FALSE;
		
        if(SA_Level1 == level)
        {
	        /*Sync for byte1: used for storing security L1 attempt counter*/
		    RAM_NVM_BLOCK_Security_AttemptCount[0] = AttemptCounter;
        }
        else if(SA_Level2 == level)
        {	
	        /*byte2: Not used, Reserved for storing security L2 attempt counter*/
	        RAM_NVM_BLOCK_Security_AttemptCount[1] = AttemptCounter;
        }
	    else
	    {
            /*Do nothing.*/
	    }

		(void)Rte_Call_RP_Nvm_Security_AttemptCount_SetRamBlockStatus((Boolean)FALSE);

		ui8_RetVal_Write = Rte_Call_RP_Nvm_Security_AttemptCount_WriteBlock((void*) &RAM_NVM_BLOCK_Security_AttemptCount); /*PRQA S 0314*/
		
        if ((uint8) E_OK == ui8_RetVal_Write) 
		{
		    ui8_RetVal_ErrStat = Rte_Call_RP_Nvm_Security_AttemptCount_GetErrorStatus(&ui8_WriteStatus);
	
			if ((uint8) E_OK == ui8_RetVal_ErrStat)
			{
				if ((uint8) NVM_REQ_OK == ui8_WriteStatus) 
				{
				    b_WriteFlagSuccess = (Boolean)TRUE;
				}
				else if ((uint8) NVM_REQ_PENDING == ui8_WriteStatus)
				{
				    u_RetVal = DCM_E_PENDING;
				} 
				else 
				{
					u_RetVal = RTE_E_INVALID;
				}
			} 
			else 
			{
				 u_RetVal = RTE_E_INVALID;
			}
		}
		else 
		{
			u_RetVal = RTE_E_INVALID;
		}  
	}
	else if ((uint8) DCM_PENDING == OpStatus) 
	{
        ui8_RetVal_ErrStat = Rte_Call_RP_Nvm_Security_AttemptCount_GetErrorStatus(&ui8_WriteStatus);
		   
		if ((uint8) E_OK == ui8_RetVal_ErrStat)
		{
			if ((uint8) NVM_REQ_OK == ui8_WriteStatus) 
			{
				b_WriteFlagSuccess = (Boolean)TRUE;
			} 
			else if ((uint8) NVM_REQ_PENDING == ui8_WriteStatus) 
			{
				u_RetVal = DCM_E_PENDING;
			} 
			else
			{
				u_RetVal = RTE_E_INVALID;
			}
		} 
		else 
		{
			u_RetVal = RTE_E_INVALID;
		}
	}
	else if ((uint8) DCM_CANCEL == OpStatus) 
	{
		(void)Rte_Call_RP_Nvm_Security_AttemptCount_GetErrorStatus(&ui8_WriteStatus);
	
		if ((uint8) NVM_REQ_PENDING == ui8_WriteStatus) 
		{
			ui8_RetVal_ErrStat = NvM_CancelJobs(NvMConf_NvMBlockDescriptor_NVM_BLOCK_Security_AttemptCount);
			  
			b_NvmOperationPending = (Boolean)TRUE;
	
			if ((uint8) E_OK == ui8_RetVal_ErrStat) 
			{
				u_RetVal = E_OK;
			} 
			else 
			{
				u_RetVal = RTE_E_INVALID;
			}
		} 
		else 
		{
			u_RetVal = E_OK;
		}
	
		b_WriteFlagSuccess = (Boolean)FALSE;
	} 
	else 
	{
		u_RetVal = RTE_E_INVALID;
	}
	
	if ((Boolean)TRUE == b_WriteFlagSuccess) 
	{
		(void)Rte_Call_RP_Nvm_Security_AttemptCount_SetRamBlockStatus((Boolean)TRUE);
	
		u_RetVal = E_OK;
	}
	else 
	{
		if ((uint8) DCM_E_PENDING == u_RetVal)
		{
		    /*Do nothing.*/
		} 
		else 
		{
			if ((Boolean)FALSE == b_NvmOperationPending) 
			{
				(void)Rte_Call_RP_Nvm_Security_AttemptCount_SetRamBlockStatus((Boolean)TRUE);
			}
		}
	}
	
	return u_RetVal;
}

/**
 * \functions u_RandomGenerator
 *
 * \brief 
 *
 ** \param[in] none,
 *
 ** \param[out] none,
 *
 ** \return randomw value, 
 * \comments
 *
 */
static uint32 u_RandomGenerator(void)
{
	uint32 u_RandomW = 0u;

	u_RandomW = Mcal_DelayGetTick();
	return (u_RandomW ^ (u_RandomW << 16)); /*PRQA S 3120*/
}

/**
 * \functions u_ChangAn_SecurityAlgorithm
 *
 * \brief 
 *
 ** \param[in] none,
 *
 ** \param[out] none,
 *
 ** \return calculate key from ChangAn, 
 * \comments
 *
 */
#if((DSM_SYSTEM_TYPE == DSM_SYSTEM_MFC5J3_C673)|| \
    (DSM_SYSTEM_TYPE == DSM_SYSTEM_MFC5J3_C385))
static uint32 u_ChangAn_SecurityAlgorithm(void)
{
    /* temporary variables */
    uint32 t_Iteration_ul;
    uint32 t_Seed_ul = 0u;
	uint32 t_Seed2_ul = 0u; /*PRQA S 2211*/
	uint32 t_Key_ul = 0u;
    uint32 t_Key1_ul = 0u; /*PRQA S 2211*/
	uint32 t_Key2_ul = 0u; /*PRQA S 2211*/
	static uint32 const App_Key_Const = 0x527F6374; /*PRQA S 2211*/

    t_Seed_ul = (uint32)(a_Seed_Level1[3] + (a_Seed_Level1[2]<<8) + (a_Seed_Level1[1]<<16) + (a_Seed_Level1[0]<<24)); /*PRQA S 0499,3120,4391*/
    if (t_Seed_ul != 0) /*PRQA S 1843*/
    {
		t_Key1_ul = t_Seed_ul ^ App_Key_Const;
		for (t_Iteration_ul = 0u; t_Iteration_ul < 32; t_Iteration_ul++)  /*PRQA S 3120,1842*/
		{
			t_Seed2_ul |= ((t_Seed_ul >> t_Iteration_ul) & 0x1) << (31 - t_Iteration_ul); /*PRQA S 4542,3120,1841,1840,3383*/
		}
        t_Key2_ul = t_Seed2_ul ^ App_Key_Const;
		t_Key_ul = t_Key1_ul + t_Key2_ul; /*PRQA S 3383*/
    }
    else
    {
        /* do nothing*/
    }
    return t_Key_ul;
}





#endif
