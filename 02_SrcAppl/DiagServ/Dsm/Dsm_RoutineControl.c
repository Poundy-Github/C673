/**
 * \file   Dsm_RoutineControl.c
 *
 * \brief  UDS RoutineControl service(31)
 *
 * \version refer the Rte_Dsm.h.
 * 
 * \copyright  2022 - 2023 Conti Smart Core
 *
 */
/*==================[inclusions]============================================*/
#include <Rte_Dsm.h>
#include "Dsm_Cfg.h"
#include "Dsm_Main.h"
#include "Os_api.h"
#include "VerInfo.h"
#include "Cdm.h"
#include "Sdc_Core.h"
#include "Cdd_Ucb.h"
#include "Cdd_EvAdc.h"
#include "Qsm_Lcfg.h"



/*==================[external constants definition]=========================*/




/*==================[internal constants definition]=========================*/


/*==================[external data definition]==============================*/


/*==================[internal data definition]==============================*/
#if(DSM_FEAT_MEMMAP_EB_IS_USED == STD_ON)
    #define Dsm_START_SEC_VAR_UNSPECIFIED
    #include <Dsm_MemMap.h>
#endif
static uint8 a_JTAGPasswd[32] = {0};
#if(DSM_FEAT_MEMMAP_EB_IS_USED == STD_ON)
    #define Dsm_STOP_SEC_VAR_UNSPECIFIED
    #include <Dsm_MemMap.h>
#endif


/*==================[internal function declarations]========================*/


/*==================[external function definitions]=========================*/
#if(DSM_FEAT_MEMMAP_EB_IS_USED == STD_ON)
    #define Dsm_START_SEC_CODE
    #include <Dsm_MemMap.h> /* PRQA S 5087 */
#endif

/**
 * \functions Dsm_u_RC_ProgrammingPreconditionCheck_StartRoutine
 *
 * \brief start programming precondition check .(31 01 0203)
 *
 ** \param[in] none,
 *
 *     the DID include the below infomation.
 **           
 **                 byte0-1: Attempt Downloading Counter
 **                 byte2-3: FlashDriver activated successfully counter
 **                 byte4-5: App downloaded successfully counter
 **                 byte6-7: Fbl downloaded successfully counter
 ** \return RTE_E_OK, 
 * \comments  base Address:0xAF07C000 startAddress: 0xAF07C028  Total Length: 8byte
 *
 */
#if (DSM_FEAT_RC_ProgrammingPreconditionCheck_StartRoutine == STD_ON)
FUNC(Std_ReturnType, RTE_CODE) Dsm_u_RC_ProgrammingPreconditionCheck_StartRoutine (Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_APPL_DATA) ErrorCode)
{
    /* suppress compiler warnings about unused arguments */
	Std_ReturnType u_Retval = RTE_E_OK;
	  
#if((DSM_SYSTEM_TYPE == DSM_SYSTEM_MFC5J3_C673)|| \
					(DSM_SYSTEM_TYPE == DSM_SYSTEM_MFC5J3_C385))  

	static boolean b_WriteFlagSuccess;	
	static uint8 ui8_QsmReqStatus = QSM_REQRESULT_NOT_OK;
	uint16 ui16_Esp_VehicleSpeed;
	float f_Esp_VehicleSpeed;	
    float32 f32_BattVolt;
	
    (void)Rte_Call_RP_EvAdc_GetValue_VMON_BATT_GetPhyValue(&f32_BattVolt);

	(void)Rte_Read_RP_Com_SRI_EspVehSpd_DE_EspVehSpd(&ui16_Esp_VehicleSpeed);

	f_Esp_VehicleSpeed = ((float)ui16_Esp_VehicleSpeed * 5625) / 100000; //phy = raw* 0.05625;
	
	if((uint8)DCM_INITIAL == OpStatus)
	{
	    b_WriteFlagSuccess = FALSE;	

		s_QSBlock_SecureUpdateInfo.SecLogInfo.u_AttemptDownloadingCounter++;
		
		Rte_Call_RP_Qsm_BlockSecureUpdateLogOp_Qsm_WriteBlock(&s_QSBlock_SecureUpdateInfo);

		ui8_QsmReqStatus = Rte_Call_RP_Qsm_BlockSecureUpdateLogOp_Qsm_GetErrorStatues();
		
		if(QSM_REQRESULT_PENDING == ui8_QsmReqStatus)
	    {
		    u_Retval = DCM_E_PENDING;
		}
		else if(QSM_REQRESULT_OK == ui8_QsmReqStatus)
		{
		    b_WriteFlagSuccess = TRUE;
		}
		else
		{
		    *ErrorCode = DCM_E_GENERALPROGRAMMINGFAILURE;
		    u_Retval = RTE_E_INVALID;	
		}
	}
	else if((uint8)DCM_PENDING == OpStatus)
	{
	    ui8_QsmReqStatus = Rte_Call_RP_Qsm_BlockSecureUpdateLogOp_Qsm_GetErrorStatues();
		  
		if(QSM_REQRESULT_PENDING == ui8_QsmReqStatus)
	    {
		    u_Retval = DCM_E_PENDING;
		}
		else if(QSM_REQRESULT_OK == ui8_QsmReqStatus)
		{
		    b_WriteFlagSuccess = TRUE;
		}
		else
		{
		    *ErrorCode = DCM_E_GENERALPROGRAMMINGFAILURE;
		    u_Retval = RTE_E_INVALID;	
		}		        
	}
	else if((uint8)DCM_CANCEL == OpStatus)
	{
		  b_WriteFlagSuccess = FALSE;
		  *ErrorCode = E_OK;
		  u_Retval = RTE_E_OK;
	}
	else
	{
		  /*Do nothing*/
	}
  
	if(TRUE == b_WriteFlagSuccess)
	{
	    if (f_Esp_VehicleSpeed > DSM_RC_VEHSPEED_MIN_THSLD)
	    {    
		    *ErrorCode = DCM_E_VEHICLESPEEDTOOHIGH; //NRC88
		    u_Retval = RTE_E_INVALID;
	    }
		else if(f32_BattVolt < DSM_RC_VOLT_MIN_THSLD)
		{
		    *ErrorCode = DCM_E_VOLTAGETOOLOW; //NRC93
		    u_Retval = RTE_E_INVALID;
		}
		else if(f32_BattVolt > DSM_RC_VOLT_MAX_THSLD)
		{
		  	*ErrorCode = DCM_E_VOLTAGETOOHIGH; //NRC92
		    u_Retval = RTE_E_INVALID;
		}
		else
		{
		    Rte_IrvWrite_Dsm_u_RC_ProgrammingPreconditionCheck_StartRoutine_Dsm_IRV_PreCondition_CheckState(TRUE);
		    *ErrorCode = E_OK;
		    u_Retval = RTE_E_OK;
		}
	}
	else
	{
		if ((uint8)DCM_E_PENDING == u_Retval)
		{
			*ErrorCode = DCM_E_REQUESTCORRECTLYRECEIVEDRESPONSEPENDING;
		}
		else
		{
			/*Do nothing*/
		}
	}
#endif
      return u_Retval;

} /* FUNC(Std_ReturnType, RTE_CODE) Dsm_u_RC_ProgrammingPreconditionCheck_StartRoutine (Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_APPL_DATA) ErrorCode) */
#endif


/**
 * \functions Dsm_u_RC_ExchangeApplicationRunningArea_StartRoutine
 *
 * \brief Exchange Appplication running area.(31 01 0204)
 *
 ** \param[in] none,
 *
 ** \param[out] none,
 **                 
 *
 ** \return RTE_E_OK, 
 * \comments  A/B startup Flag: base Address:0xAF07F000 startAddress: 0xAF07F028  Total Length: 8byte
 *
 */
#if (DSM_FEAT_RC_ExchangeApplicationRunningArea_StartRoutine == STD_ON)
FUNC(Std_ReturnType, RTE_CODE) Dsm_u_RC_ExchangeApplicationRunningArea_StartRoutine (Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_APPL_DATA) ErrorCode)
{
    /* suppress compiler warnings about unused arguments */
	Std_ReturnType u_Retval = RTE_E_OK;
		
#if((DSM_SYSTEM_TYPE == DSM_SYSTEM_MFC5J3_C673)|| \
					  (DSM_SYSTEM_TYPE == DSM_SYSTEM_MFC5J3_C385))	
	static boolean b_CompleteSuccess = TRUE;
	static uint8 ui8_QsmReqStatus = QSM_REQRESULT_NOT_OK;
	uint32 *p_address = NULL_PTR;/*the start address in PFlash*/
	static e_VerInfo_BankType_t e_bank = VerInfo_BankType_Max;
	uint8 a_ABValidFlag[32]={0};
	static uint8 a_StartupFlag[8] = {0x5A,0xA5,0xA5,0x5A,0x5A,0xA5,0xA5,0x5A};
	
   	if((uint8)DCM_INITIAL == OpStatus)
	{
	    b_CompleteSuccess = FALSE;	
	
	    e_bank = VerInfo_GetSoftwareBank();
		
	    if(VerInfo_BankType_A == e_bank)
	    {
		    Cdm_v_BoardDisableECCCheck();		
		    p_address = APPLICATION_B_VALIDFLAG_ADDRESS;  
		    (void)TS_MemCpy(&a_ABValidFlag, p_address, 32);		
		    Cdm_v_BoardEnableECCCheck();
	    }
	    else if(VerInfo_BankType_B == e_bank)
	    {
		    Cdm_v_BoardDisableECCCheck();		
		    p_address = APPLICATION_A_VALIDFLAG_ADDRESS;
		    (void)TS_MemCpy(&a_ABValidFlag, p_address, 32);		
		    Cdm_v_BoardEnableECCCheck();
	    }
	    else {/*Do nothing.*/}
		
		for(uint8 i=0; i < 32; i++)
	    {
		    if((((i % 4) == 0x00)||((i % 4) == 0x03)) && (0x5A == a_ABValidFlag[i]))
		    {
			    u_Retval = RTE_E_OK;
		    }
		    else if((((i % 4) == 0x01)||((i % 4) == 0x02)) && (0xA5 == a_ABValidFlag[i]))
		    {
			    u_Retval = RTE_E_OK;
		    }
		    else
		    {
				*ErrorCode = 0x02; //Indicate the download programm is invalid, exhange failed.This is defintion by OEM spec.
				u_Retval = RTE_E_INVALID;
			    break;
		    }
	    }  

		if((uint8)RTE_E_OK == u_Retval)
		{
		    if(VerInfo_BankType_A == e_bank)
		    {
		        Rte_Enter_DSM_EXCLUSIVEAREA();
		        /* PRQA S 0314 2 */ /* Pointer to void, no problem */
		        (void)TS_MemCpy((void*)s_QSBlock_StartupFlag.StartupFlag, (const void*)a_StartupFlag, sizeof(s_QSBlock_StartupFlag.StartupFlag));
                /*if the Write flash flag in flash address:0xAF07F028~0xAF07F02F 5AA5A55A5AA5A55A ,the ECU shall be satrt up in B Blank.**/
		        Rte_Exit_DSM_EXCLUSIVEAREA();		                   
			}
			else if(VerInfo_BankType_B == e_bank)
			{
			    Rte_Enter_DSM_EXCLUSIVEAREA();
			    /* PRQA S 0314 2 */ /* Pointer to void, no problem */
			    (void)TS_MemBZero((void*)s_QSBlock_StartupFlag.StartupFlag, sizeof(s_QSBlock_StartupFlag.StartupFlag));
				
			    Rte_Exit_DSM_EXCLUSIVEAREA();
			}
			else
			{/*Do nothing.*/}

            (void)Rte_Call_RP_Qsm_BlockStartup_FlagOp_Qsm_WriteBlock(&s_QSBlock_StartupFlag);
			
			ui8_QsmReqStatus = Rte_Call_RP_Qsm_BlockStartup_FlagOp_Qsm_GetErrorStatues();
		
		    if(QSM_REQRESULT_PENDING == ui8_QsmReqStatus)
	        {
		      u_Retval = DCM_E_PENDING;
		    }
		    else if(QSM_REQRESULT_OK == ui8_QsmReqStatus)
		    {
		      b_CompleteSuccess = TRUE;
		    }
		    else
		    {
		      *ErrorCode = DCM_E_GENERALPROGRAMMINGFAILURE;
		      u_Retval = RTE_E_INVALID;	
		    }     		 		     	
		}
		else
		{}
	}
	else if((uint8)DCM_PENDING == OpStatus)
	{
        ui8_QsmReqStatus = Rte_Call_RP_Qsm_BlockStartup_FlagOp_Qsm_GetErrorStatues();
		
		if(QSM_REQRESULT_PENDING == ui8_QsmReqStatus)
	    {
		    u_Retval = DCM_E_PENDING;
		}
		else if(QSM_REQRESULT_OK == ui8_QsmReqStatus)
		{
		    b_CompleteSuccess = TRUE;
		}
		else
		{
		    *ErrorCode = DCM_E_GENERALPROGRAMMINGFAILURE;
		    u_Retval = RTE_E_INVALID;	
		}     		 		     	   			   
	}
	else if((uint8)DCM_CANCEL == OpStatus)
	{
		b_CompleteSuccess = FALSE;
		*ErrorCode = E_OK;
		u_Retval = RTE_E_OK;
	}
	else
	{
		/*Do nothing*/
	}

	if(TRUE == b_CompleteSuccess)
	{	    
	    *ErrorCode = E_OK;
		u_Retval = RTE_E_OK;
	}
	else
	{
	    if ((uint8)DCM_E_PENDING == u_Retval)
		{
			*ErrorCode = DCM_E_REQUESTCORRECTLYRECEIVEDRESPONSEPENDING;
		}
		else
		{
		    /*Do nothing.*/
		}
	}
#endif

    return u_Retval;

} /* FUNC(Std_ReturnType, RTE_CODE) Dsm_u_RC_ExchangeApplicationRunningArea_StartRoutine (Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_APPL_DATA) ErrorCode) */
#endif


/**
 * \functions Dsm_u_RC_ApplicationRollback_StartRoutine
 *
 * \brief Run application roll back.(31 01 0205)
 *
 ** \param[in] none,
 *
 ** \param[out] none,
 **                 
 *
 ** \return RTE_E_OK, 
 * \comments  A/B startup Flag: base Address:0xAF07F000 startAddress: 0xAF07F028  Total Length: 8byte
 *
 */
#if (DSM_FEAT_RC_ApplicationRollback_StartRoutine == STD_ON)
FUNC(Std_ReturnType, RTE_CODE) Dsm_u_RC_ApplicationRollback_StartRoutine (Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_APPL_DATA) ErrorCode)
{
    /* suppress compiler warnings about unused arguments */
	Std_ReturnType u_Retval = RTE_E_OK;
		  
#if((DSM_SYSTEM_TYPE == DSM_SYSTEM_MFC5J3_C673)|| \
						(DSM_SYSTEM_TYPE == DSM_SYSTEM_MFC5J3_C385))  
	uint32 *p_address = NULL_PTR;/*the start address in PFlash*/
	uint32 *p_SWVer_address = NULL_PTR;/*the start address in PFlash*/
	uint8 a_ABValidFlag[32]={0};
	uint8 a_A_SWVersion[32]={0};
	uint8 a_B_SWVersion[32]={0};
	static boolean b_CompleteSuccess = TRUE;
	static uint8 ui8_QsmReqStatus = QSM_REQRESULT_NOT_OK;
	static e_VerInfo_BankType_t e_bank = VerInfo_BankType_Max;
	static uint8 ui8_SoftVerCompareResults = 0x00u;
	static uint8 a_StartupFlag[8] = {0x5A,0xA5,0xA5,0x5A,0x5A,0xA5,0xA5,0x5A};
	  
	if((uint8)DCM_INITIAL == OpStatus)
	{
		b_CompleteSuccess = FALSE;  
		
	    /*Step1: Get software running area and A/B blank validity flag.*/
		e_bank = VerInfo_GetSoftwareBank();
		if(VerInfo_BankType_A == e_bank)
		{
			Cdm_v_BoardDisableECCCheck(); 	  
			p_address = APPLICATION_B_VALIDFLAG_ADDRESS;	
			(void)TS_MemCpy(&a_ABValidFlag, p_address, 32);	  
			Cdm_v_BoardEnableECCCheck();
		}
		else if(VerInfo_BankType_B == e_bank)
		{
			Cdm_v_BoardDisableECCCheck(); 	  
			p_address = APPLICATION_A_VALIDFLAG_ADDRESS;
			(void)TS_MemCpy(&a_ABValidFlag, p_address, 32);	  
			Cdm_v_BoardEnableECCCheck();
		}
		else {/*Do nothing.*/}
		
		/*Step2: Check software validity flag is valid or not.*/  
		for(uint8 i=0; i < 32; i++)
		{
			if((((i % 4) == 0x00)||((i % 4) == 0x03)) && (0x5A == a_ABValidFlag[i]))
			{
				u_Retval = RTE_E_OK;
			}
			else if((((i % 4) == 0x01)||((i % 4) == 0x02)) && (0xA5 == a_ABValidFlag[i]))
			{
				u_Retval = RTE_E_OK;
			}
			else
			{
				*ErrorCode = 0x02;
				u_Retval = RTE_E_INVALID;
				break;
			}
		} 
		
        /*Step3: Compare the software version of A and B, and rollback to old software version.*/
		if(u_Retval == RTE_E_OK)
		{
		    Cdm_v_BoardDisableECCCheck();
		    p_SWVer_address = VERINFO_MCU_SW_BANK_A_ADDRESS;	//get A SW version
		    (void)TS_MemCpy(&a_A_SWVersion, p_SWVer_address, 32);
		    p_SWVer_address = VERINFO_MCU_SW_BANK_B_ADDRESS;	//get B SW Version
		    (void)TS_MemCpy(&a_B_SWVersion, p_SWVer_address, 32);
		    Cdm_v_BoardEnableECCCheck();
			
		    for(uint8 i=4;i<8;i++)		//compare A B SW Version info
		    {
			    if(a_A_SWVersion[i] > a_B_SWVersion[i])
			    {
				    ui8_SoftVerCompareResults = 0x01u;	//1 means A version is latest			
				    break;
			    }
			    else if(a_A_SWVersion[i] == a_B_SWVersion[i])
			    {
                    ui8_SoftVerCompareResults = 0x02u;  	//2 means A equal B version
			    }				
			    else 
			    {
				    ui8_SoftVerCompareResults = 0x03u;	//3 means B version is latest	
				    break;
			    }
		    }

			/*Step4: Write start up flag in specific QS Data area.*/
		    if(VerInfo_BankType_A == e_bank)
		    {
                if(ui8_SoftVerCompareResults == 0x01u) ////compare version,A is latest version
                {
                    /*if Write flash flag in flash address:0xAF07F028~0xAF07F02F 5AA5A55A5AA5A55A ,the ECU shall be from A rollback to B.**/
				    Rte_Enter_DSM_EXCLUSIVEAREA();
		            /* PRQA S 0314 2 */ /* Pointer to void, no problem */
		            (void)TS_MemCpy((void*)s_QSBlock_StartupFlag.StartupFlag, (const void*)a_StartupFlag, sizeof(s_QSBlock_StartupFlag.StartupFlag));
					
		            Rte_Exit_DSM_EXCLUSIVEAREA();
			    }
			    else
			    {
			        *ErrorCode = 0x02;
			        u_Retval = RTE_E_INVALID;
			    }
		    }
		    else if(VerInfo_BankType_B == e_bank)
		    {
		        if(ui8_SoftVerCompareResults == 0x03u)
		        {
		    		Rte_Enter_DSM_EXCLUSIVEAREA();
			        /* PRQA S 0314 2 */ /* Pointer to void, no problem */
			        (void)TS_MemBZero((void*)s_QSBlock_StartupFlag.StartupFlag, sizeof(s_QSBlock_StartupFlag.StartupFlag));
				    /*if clear flash flag in flash address:0xAF07F028~0xAF07F02F ,the ECU shall be from B rollback to A.**/
			        Rte_Exit_DSM_EXCLUSIVEAREA();
		        }
			    else
			    {
			        *ErrorCode = 0x02;
			        u_Retval = RTE_E_INVALID;
			    }
		    }
			else
			{
                /*Do nothing.*/
			}
			
			if(u_Retval == RTE_E_OK)
			{
		        (void)Rte_Call_RP_Qsm_BlockStartup_FlagOp_Qsm_WriteBlock(&s_QSBlock_StartupFlag);
					
			    ui8_QsmReqStatus = Rte_Call_RP_Qsm_BlockStartup_FlagOp_Qsm_GetErrorStatues();
				
			    if(QSM_REQRESULT_PENDING == ui8_QsmReqStatus)
			    {
				    u_Retval = DCM_E_PENDING;
			    }
			    else if(QSM_REQRESULT_OK == ui8_QsmReqStatus)
			    {
				    b_CompleteSuccess = TRUE;
			    }
			    else
			    {
				    *ErrorCode = DCM_E_GENERALPROGRAMMINGFAILURE;
				    u_Retval = RTE_E_INVALID; 
			    }
			}
			else
			{}
		}
		else
		{
            /*Do nothing.*/
		}
		
    }
	else if((uint8)DCM_PENDING == OpStatus)
	{
	    ui8_QsmReqStatus = Rte_Call_RP_Qsm_BlockStartup_FlagOp_Qsm_GetErrorStatues();
			
		if(QSM_REQRESULT_PENDING == ui8_QsmReqStatus)
		{
		    u_Retval = DCM_E_PENDING;
		}
		else if(QSM_REQRESULT_OK == ui8_QsmReqStatus)
		{
			b_CompleteSuccess = TRUE;
		}
		else
		{
			*ErrorCode = DCM_E_GENERALPROGRAMMINGFAILURE;
			u_Retval = RTE_E_INVALID;	
		}							
	}
	else if((uint8)DCM_CANCEL == OpStatus)
	{
		b_CompleteSuccess = FALSE;
		*ErrorCode = E_OK;
		u_Retval = RTE_E_OK;
	}
	else
	{
		/*Do nothing*/
	}
  
	if(TRUE == b_CompleteSuccess)
	{ 	  
		*ErrorCode = E_OK;
		u_Retval = RTE_E_OK;
	}
	else
	{
		 if ((uint8)DCM_E_PENDING == u_Retval)
		 {
			 *ErrorCode = DCM_E_REQUESTCORRECTLYRECEIVEDRESPONSEPENDING;
		 }
		 else
		 {
			 /*Do nothing.*/
		 }
	}
#endif
  
	return u_Retval;
} /* FUNC(Std_ReturnType, RTE_CODE) Dsm_u_RC_ApplicationRollback_StartRoutine (Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_APPL_DATA) ErrorCode) */
#endif

/**
 * \functions Dsm_v_LockJTAGPassword
 *
 * \brief Send Passwd to Cdd_Ucb component.
 *
 ** \param[in] none,
 *
 ** \param[out] *ptr, passwd
 **                 
 *
 ** \return RTE_E_OK, 
 * \comments  passwd：total byte: 32byte
 *
 */
FUNC(void, APPL_DSM_CODE) Dsm_v_LockJTAGPassword(uint8 *const ptr)
{
	for(int i=0;i<32;i++)
	{
		ptr[i] = a_JTAGPasswd[i];
	}
}

/**
 * \functions Dsm_u_RC_LockJTAG_StartRoutine
 *
 * \brief Send Passwd to lock JTAG.(31 01 8010)
 *
 ** \param[in] none,
 *
 ** \param[out] none,
 **                 
 *
 ** \return RTE_E_OK, 
 * \comments  passwd：total byte: 32byte
 *
 */
#if (DSM_FEAT_RC_LockJTAG_StartRoutine == STD_ON)
FUNC(Std_ReturnType, RTE_CODE) Dsm_u_RC_LockJTAG_StartRoutine (P2CONST(uint8, AUTOMATIC, RTE_APPL_DATA) dataIn0, Dcm_OpStatusType OpStatus, P2VAR(Dcm_StartDataOut_DcmDspRoutine_0x8010_DcmDspStartRoutineOutSignal_0Type, AUTOMATIC, RTE_APPL_DATA) dataOut0, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_APPL_DATA) ErrorCode)

{
    /* suppress compiler warnings about unused arguments */
    (void)OpStatus;
    (void)*ErrorCode;
#if((DSM_SYSTEM_TYPE == DSM_SYSTEM_MFC5J3_C673)|| \
								(DSM_SYSTEM_TYPE == DSM_SYSTEM_MFC5J3_C385))

    (void)TS_MemCpy(&a_JTAGPasswd, dataIn0, 32);

	CDD_Ucb_ReqDBGIFLock();

	dataOut0[0] = 0x01u; //JTAG disable and protection
	
#endif

    return RTE_E_OK;
} /* FUNC(Std_ReturnType, RTE_CODE) Dsm_u_RC_LockJTAG_StartRoutine (P2CONST(uint8, AUTOMATIC, RTE_APPL_DATA) dataIn0, Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_APPL_DATA) ErrorCode) */
#endif

/**
 * \functions Dsm_u_RC_LockJTAG_RequestRoutineResults
 *
 * \brief Request the lock results of JTAG.(31 03 8010)
 *
 ** \param[in] none,
 *
 ** \param[out] none,
 **                 
 *
 ** \return RTE_E_OK, 
 * \comments  passwd：total byte: 32byte
 *
 */
#if (DSM_FEAT_RC_LockJTAG_RequestRoutineResults == STD_ON)
FUNC(Std_ReturnType, RTE_CODE) Dsm_u_RC_LockJTAG_RequestRoutineResults (Dcm_OpStatusType OpStatus, P2VAR(Dcm_RequestDataOut_DcmDspRoutine_0x8010_DcmDspRoutineRequestResOutSignal_0Type, AUTOMATIC, RTE_APPL_DATA) dataOut0, P2VAR(Dcm_RequestDataOut_DcmDspRoutine_0x8010_DcmDspRoutineRequestResOutSignal_1Type, AUTOMATIC, RTE_APPL_DATA) dataOut1, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_APPL_DATA) ErrorCode)
{
    /* suppress compiler warnings about unused arguments */
    (void)OpStatus;
    (void)*ErrorCode;
	
#if((DSM_SYSTEM_TYPE == DSM_SYSTEM_MFC5J3_C673)|| \
							(DSM_SYSTEM_TYPE == DSM_SYSTEM_MFC5J3_C385))
    if(CDD_Ucb_GetDBGIFLockState() == 0x01u)/*UCB_LOCK:1;UCB_UNLOCK:0*/
    {
	    *dataOut0 = 0x01u; /* 01:JTAG Disabled */
	}
	else
	{
		*dataOut0 = 0x02u; /* 02:JTAG Enabled */
	}

	if(CDD_Ucb_GetDBGConfirmState() == 1u)/*UCB_PROTECT:1;UCB_NOTPROTECE:0*/
	{
		*dataOut1 = 0x01u; /* 01:JTAG Protected */
	}
	else
	{
		*dataOut1 = 0x02u; /* 02:JTAG NOT Protected */
	}

#endif
		
    return RTE_E_OK;
} /* FUNC(Std_ReturnType, RTE_CODE) Dsm_u_RC_LockJTAG_RequestRoutineResults (Dcm_OpStatusType OpStatus, P2VAR(Dcm_RequestDataOut_DcmDspRoutine_0x8010_DcmDspRoutineRequestResOutSignal_JtagstatusType, AUTOMATIC, RTE_APPL_DATA) dataOut0, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_APPL_DATA) ErrorCode) */
#endif

/**
 * \functions Dsm_u_RC_EOLCalibration_StartRoutine
 *
 * \brief Request to start EOL online calibration.(31 01 800B)
 *
 ** \param[in] none,  byte0-13:
 *
 ** \param[out] none,
 **                 
 *
 ** \return RTE_E_OK, 
 * \comments 
 *
 */
#if (DSM_FEAT_RC_EOLCalibration_StartRoutine == STD_ON)
FUNC(Std_ReturnType, RTE_CODE) Dsm_u_RC_EOLCalibration_StartRoutine (Dcm_StartDataIn_DcmDspRoutine_0x800B_DcmDspStartRoutineInSignal_0Type dataIn0, Dcm_StartDataIn_DcmDspRoutine_0x800B_DcmDspStartRoutineInSignal_00_01Type dataIn1, Dcm_StartDataIn_DcmDspRoutine_0x800B_DcmDspStartRoutineInSignal_02_03Type dataIn2, Dcm_StartDataIn_DcmDspRoutine_0x800B_DcmDspStartRoutineInSignal_04_05Type dataIn3, Dcm_StartDataIn_DcmDspRoutine_0x800B_DcmDspStartRoutineInSignal_06_07Type dataIn4, Dcm_StartDataIn_DcmDspRoutine_0x800B_DcmDspStartRoutineInSignal_08_09Type dataIn5, Dcm_StartDataIn_DcmDspRoutine_0x800B_DcmDspStartRoutineInSignal_10_11Type dataIn6, Dcm_StartDataIn_DcmDspRoutine_0x800B_DcmDspStartRoutineInSignal_12_13Type dataIn7, Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_APPL_DATA) ErrorCode)
{
    /* suppress compiler warnings about unused arguments */
    Std_ReturnType u_Retval = RTE_E_OK;
	(void)dataIn0;
    //(void)dataIn1;
    //(void)dataIn2;
    (void)dataIn3;
    //(void)dataIn4;
    (void)dataIn5;
    (void)dataIn6;
    (void)dataIn7;
#if((DSM_SYSTEM_TYPE == DSM_SYSTEM_MFC5J3_C673)|| \
							(DSM_SYSTEM_TYPE == DSM_SYSTEM_MFC5J3_C385))
	static uint8 a_SocSysState[1] = {0};
	Std_ReturnType ui8_RetVal_Read = RTE_E_OK; 
	static boolean b_ReuqestFlagSuccess;
	Std_ReturnType ui8_RetVal_Write = RTE_E_INVALID;
	Std_ReturnType ui8_RetVal_ErrStat = RTE_E_INVALID;
	NvM_RequestResultType ui8_WriteStatus = NVM_REQ_NOT_OK;
	boolean b_NvmOperationPending = FALSE;

    if((uint8)DCM_INITIAL == OpStatus)
    {
        b_ReuqestFlagSuccess = FALSE;
		
		Rte_Call_RP_Sdc_SendInterface_Diag_SocSysState_Read((void*)a_SocSysState,1);
		
	    if(a_SocSysState[0] != e_Sdc_SocSystemStatus_Normal)
	    {
            *ErrorCode = DCM_E_CONDITIONSNOTCORRECT;
		    u_Retval = RTE_E_INVALID;
	    }
	    else if(a_SocSysState[0] == e_Sdc_SocSystemStatus_Normal)
	    {
	         /*MCU recevived UDS code and send EOL calibration request through SPI message 0x0202.*/
             ui8_RetVal_Read= Rte_Call_RP_Sdc_SendInterface_Calibration_RequestEOLCalibration();
             if(ui8_RetVal_Read != RTE_E_OK)
			 {
			     *ErrorCode = DCM_E_CONDITIONSNOTCORRECT;
		         u_Retval = RTE_E_INVALID;
			 }
			 else
			 {   
			      /*Service for setting the lock status of a permanent RAM block of an NVRAM block.*/
				  (void)Rte_Call_RP_Nvm_EOL_Info_Input_SetRamBlockStatus(FALSE);
                  /*Get DID 0xF1F5 Body_height_wheelhouse_edge info */
			      RAM_NVM_BLOCK_EOL_Info_Input[0] = (uint8) ((dataIn1 & 0xFF00) >> 8);
			      RAM_NVM_BLOCK_EOL_Info_Input[1] = (uint8) (dataIn1 & 0x00FF);
			      RAM_NVM_BLOCK_EOL_Info_Input[2] = (uint8) ((dataIn2 & 0xFF00) >> 8);
			      RAM_NVM_BLOCK_EOL_Info_Input[3] = (uint8) (dataIn2 & 0x00FF);

			      /*Get DID 0x3BAF Calibration Board Distance info */
			      RAM_NVM_BLOCK_EOL_Info_Input[4] = (uint8) ((dataIn4 & 0xFF00) >> 8);
			      RAM_NVM_BLOCK_EOL_Info_Input[5] = (uint8) (dataIn4 & 0x00FF);
					
			      ui8_RetVal_Write = Rte_Call_RP_Nvm_EOL_Info_Input_WriteBlock((void*) &RAM_NVM_BLOCK_EOL_Info_Input);

			      if ((uint8) E_OK == ui8_RetVal_Write) 
		          {
			          ui8_RetVal_ErrStat = Rte_Call_RP_Nvm_EOL_Info_Input_GetErrorStatus(&ui8_WriteStatus);
	
			          if ((uint8) E_OK == ui8_RetVal_ErrStat)
			          {
				          if ((uint8) NVM_REQ_OK == ui8_WriteStatus) 
				          {
						      b_ReuqestFlagSuccess = TRUE;
				          }
				          else if ((uint8) NVM_REQ_PENDING == ui8_WriteStatus)
				          {
						      u_Retval = DCM_E_PENDING;
				          } 
				          else 
				          {
					          u_Retval = RTE_E_INVALID;
					          *ErrorCode = DCM_E_GENERALPROGRAMMINGFAILURE;
				          }
			          } 
			          else 
			          {
				          u_Retval = RTE_E_INVALID;
				          *ErrorCode = DCM_E_GENERALPROGRAMMINGFAILURE;
			          }
		          }
		          else 
		          {
			          u_Retval = RTE_E_INVALID;
			          *ErrorCode = DCM_E_GENERALPROGRAMMINGFAILURE;
		          }
			  }
        }
	}
	else if((uint8)DCM_PENDING == OpStatus)
    {
        ui8_RetVal_ErrStat = Rte_Call_RP_Nvm_EOL_Info_Input_GetErrorStatus(&ui8_WriteStatus);
	
		if ((uint8) E_OK == ui8_RetVal_ErrStat)
		{
		    if ((uint8) NVM_REQ_OK == ui8_WriteStatus) 
			{
				b_ReuqestFlagSuccess = TRUE;
			} 
			else if ((uint8) NVM_REQ_PENDING == ui8_WriteStatus) 
			{
				u_Retval = DCM_E_PENDING;
			} 
			else
			{
			    u_Retval = RTE_E_INVALID;
				*ErrorCode = DCM_E_GENERALPROGRAMMINGFAILURE;
			}
	    } 
		else 
		{
			u_Retval = RTE_E_INVALID;
			*ErrorCode = DCM_E_GENERALPROGRAMMINGFAILURE;
		}    
	}
    else if ((uint8) DCM_CANCEL == OpStatus) 
	{
	    (void) Rte_Call_RP_Nvm_EOL_Info_Input_GetErrorStatus(&ui8_WriteStatus);
	
		if ((uint8) NVM_REQ_PENDING == ui8_WriteStatus) 
		{
		    ui8_RetVal_ErrStat = NvM_CancelJobs(NvMConf_NvMBlockDescriptor_NVM_BLOCK_EOL_Info_Input);
				
			b_NvmOperationPending = TRUE;
	
			if ((uint8) E_OK == ui8_RetVal_ErrStat) 
			{
				*ErrorCode = E_OK;
				u_Retval = E_OK;
			} 
			else 
			{
				u_Retval = RTE_E_INVALID;
				*ErrorCode = DCM_E_GENERALPROGRAMMINGFAILURE;
			}
		} 
		else 
		{
			*ErrorCode = E_OK;
			u_Retval = E_OK;
		}
	
		b_ReuqestFlagSuccess = FALSE;
	} 
	else
	{/*Do nothing.*/}

	if (TRUE == b_ReuqestFlagSuccess) 
	{
	    (void)Rte_Call_RP_Nvm_EOL_Info_Input_SetRamBlockStatus(TRUE);
  
		*ErrorCode = E_OK;
		u_Retval = E_OK;
	}
	else 
	{
		if ((uint8) DCM_E_PENDING == u_Retval)
		{
			*ErrorCode = DCM_E_REQUESTCORRECTLYRECEIVEDRESPONSEPENDING;
		} 
		else 
		{
			if (FALSE == b_NvmOperationPending) 
			{
				(void)Rte_Call_RP_Nvm_EOL_Info_Input_SetRamBlockStatus(TRUE);
			}
		}
	}
#endif

    return u_Retval;
} /* FUNC(Std_ReturnType, RTE_CODE) Dsm_u_RC_EOLCalibration_StartRoutine (Dcm_StartDataIn_DcmDspRoutine_0x800B_DcmDspStartRoutineInSignal_0Type dataIn0, Dcm_StartDataIn_DcmDspRoutine_0x800B_DcmDspStartRoutineInSignal_00_01Type dataIn1, Dcm_StartDataIn_DcmDspRoutine_0x800B_DcmDspStartRoutineInSignal_02_03Type dataIn2, Dcm_StartDataIn_DcmDspRoutine_0x800B_DcmDspStartRoutineInSignal_04_05Type dataIn3, Dcm_StartDataIn_DcmDspRoutine_0x800B_DcmDspStartRoutineInSignal_06_07Type dataIn4, Dcm_StartDataIn_DcmDspRoutine_0x800B_DcmDspStartRoutineInSignal_08_09Type dataIn5, Dcm_StartDataIn_DcmDspRoutine_0x800B_DcmDspStartRoutineInSignal_10_11Type dataIn6, Dcm_StartDataIn_DcmDspRoutine_0x800B_DcmDspStartRoutineInSignal_12_13Type dataIn7, Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_APPL_DATA) ErrorCode) */
#endif

/**
 * \functions Dsm_u_RC_EOLCalib[]ration_RequestRoutineResults
 *
 * \brief Request to get the results of  EOL online calibration.(31 03 800B)
 *
 ** \param[in] none,
 *
 ** \param[out] none,
 **                 
 *
 ** \return RTE_E_OK, 
 * \comments  passwd：total byte: 32byte
 *
 */
#if (DSM_FEAT_RC_EOLCalibration_RequestRoutineResults == STD_ON)
FUNC(Std_ReturnType, RTE_CODE) Dsm_u_RC_EOLCalibration_RequestRoutineResults (Dcm_OpStatusType OpStatus, P2VAR(Dcm_RequestDataOut_DcmDspRoutine_0x800B_DcmDspRoutineRequestResOutSignal_RoutineInformationType, AUTOMATIC, RTE_APPL_DATA) dataOut0, P2VAR(Dcm_RequestDataOut_DcmDspRoutine_0x800B_DcmDspRoutineRequestResOutSignal_RoutineStatusType, AUTOMATIC, RTE_APPL_DATA) dataOut1, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_APPL_DATA) ErrorCode)
{
    /* suppress compiler warnings about unused arguments */
    Std_ReturnType u_Retval = RTE_E_OK;
	uint16 length = 0;

#if((DSM_SYSTEM_TYPE == DSM_SYSTEM_MFC5J3_C673)|| \
							(DSM_SYSTEM_TYPE == DSM_SYSTEM_MFC5J3_C385))
    static uint8 a_CalibrationFlag[1] = {0};
    static uint8 a_CameraCaliresultDetails[1] = {0};
    static uint8 a_Sendbuffer[2] ={0x68,0xFF};
    CameraValue_Type s_CameraParamter;
  	Std_ReturnType ui8_RetVal_Read = RTE_E_OK; 
	static boolean b_ReuqestFlagSuccess;
	Std_ReturnType ui8_RetVal_Write = RTE_E_INVALID;
	Std_ReturnType ui8_RetVal_ErrStat = RTE_E_INVALID;
	NvM_RequestResultType ui8_WriteStatus = NVM_REQ_NOT_OK;
    boolean b_NvmOperationPending = FALSE;
	uint8 socEOLCalResult = Rte_Call_RP_Sdc_SendInterface_Calibration_EOLCalResult_Read();
    if((uint8)DCM_INITIAL == OpStatus)	
    {
        b_ReuqestFlagSuccess = FALSE;
		
        if(socEOLCalResult == 0x00)
        {
            /*0x02 -static calibration is done*/
	        /* timeout / Invalid Result*/
	        a_Sendbuffer[0] = 0x68;
	        a_Sendbuffer[1] = 0xff;
        }
        else
        {
            Rte_Call_RP_Sdc_SendInterface_Calibration_CalibrationFlag_Read((void*)a_CalibrationFlag,1);
	        Rte_Call_RP_Sdc_SendInterface_Calibration_CameraCaliresultDetails_Read((void*)a_CameraCaliresultDetails,1);
	  
	        if(a_CalibrationFlag[0] == 0x0E)
	        {
	            /*Soc is on calibration process.*/
		        a_Sendbuffer[0] = 0x69u;
		        a_Sendbuffer[1] = 0xffu;
	        }
            else if(a_CalibrationFlag[0] == 0x02) /*static calibration is done*/
	        {
	            switch(a_CameraCaliresultDetails[0])
		        {
		            case 0:
			            a_Sendbuffer[0] = 0x6A;
				        a_Sendbuffer[1] = 0x00;/*cali success*/
				        break;
			        case 6:
				        a_Sendbuffer[0] = 0x6A;
				        a_Sendbuffer[1] = 0x05;/*Pitch angle out of tolerance*/
				        break;
			        case 7:
				        a_Sendbuffer[0] = 0x6A;
				        a_Sendbuffer[1] = 0x03;/*Roll angle out of tolerance*/
				        break;
			        case 8:
				        a_Sendbuffer[0] = 0x6A;
				        a_Sendbuffer[1] = 0x06;/*yaw angle out of tolerance*/
				        break;
			        case 1:
			        case 2:
			        case 3:	
			        case 4:
			        case 5:
				        a_Sendbuffer[0] = 0x6A;
				        a_Sendbuffer[1] = 0xFF;/*Invalid parameter*/
				        break;
			        default:
				        a_Sendbuffer[0] = 0x6A;
				        a_Sendbuffer[1] = 0xFF;/*failed for other reasons*/
				        break;
		       }
			}
            else{/*Do nothing.*/}
			
		  	/*Step2: Save some infomation of EOL calibration details in DFlash.*/
            Rte_Call_RP_Sdc_SendInterface_Calibration_CameraValue_Read(&s_CameraParamter, length);

       		/*Service for setting the lock status of a permanent RAM block of an NVRAM block.*/
		    (void)Rte_Call_RP_Nvm_EOLCalibrationData_SetRamBlockStatus(FALSE);
			
		    if(a_CameraCaliresultDetails[0] == 0x00)
		    {
		        /* Byte 0-7: F1F9 - EOL calibration parameters */
		        uint16 ui16_roll_angle = (uint16)((20 - ((float32)(s_CameraParamter.roll * 0.001 ) - 10))/0.001);
		        uint16 ui16_pitch_angle = (uint16)((20 - ((float32)(s_CameraParamter.pitch * 0.001 ) - 10))/0.001);
		        uint16 ui16_yaw_angle = (uint16)((20 - ((float32)(s_CameraParamter.yaw * 0.001 ) - 10))/0.001);

		        RAM_NVM_BLOCK_EOLCalibrationData[2] = (uint8)(ui16_roll_angle >> 8);
		        RAM_NVM_BLOCK_EOLCalibrationData[3] = (uint8)(ui16_roll_angle);
		        RAM_NVM_BLOCK_EOLCalibrationData[4] = (uint8)(ui16_pitch_angle >> 8);
		        RAM_NVM_BLOCK_EOLCalibrationData[5] = (uint8)(ui16_pitch_angle);
		        RAM_NVM_BLOCK_EOLCalibrationData[6] = (uint8)(ui16_yaw_angle >> 8);
		        RAM_NVM_BLOCK_EOLCalibrationData[7] = (uint8)(ui16_yaw_angle);
	        }

	        RAM_NVM_BLOCK_EOLCalibrationData[9] = RAM_NVM_BLOCK_EOLCalibrationData[8]; /* Byte 9: F1FB - Can read the last but one Previous customer plant EOL result */
	        RAM_NVM_BLOCK_EOLCalibrationData[8] = (uint8)(a_CameraCaliresultDetails[0]); /* Byte 8: F1FA - Can read the last customer plant EOL result*/

	        ui8_RetVal_Write = Rte_Call_RP_Nvm_EOLCalibrationData_WriteBlock((void *) &RAM_NVM_BLOCK_EOLCalibrationData);	
			
		    if ((uint8) E_OK == ui8_RetVal_Write) 
		    {
			    ui8_RetVal_ErrStat = Rte_Call_RP_Nvm_EOLCalibrationData_GetErrorStatus(&ui8_WriteStatus);
	
			    if ((uint8) E_OK == ui8_RetVal_ErrStat)
			    {
				    if ((uint8) NVM_REQ_OK == ui8_WriteStatus) 
				    {
					    b_ReuqestFlagSuccess = TRUE;
				    }
				    else if ((uint8) NVM_REQ_PENDING == ui8_WriteStatus)
				    {
					    u_Retval = DCM_E_PENDING;
				    } 
				    else 
				    {
					    u_Retval = RTE_E_INVALID;
					    *ErrorCode = DCM_E_GENERALPROGRAMMINGFAILURE;
				    }
			    } 
			    else 
			    {
				    u_Retval = RTE_E_INVALID;
				    *ErrorCode = DCM_E_GENERALPROGRAMMINGFAILURE;
			    }
		    }
		    else 
		    {
			    u_Retval = RTE_E_INVALID;
			    *ErrorCode = DCM_E_GENERALPROGRAMMINGFAILURE;
		    }
        }
    }
    else if((uint8)DCM_PENDING == OpStatus)
    {
        ui8_RetVal_ErrStat = Rte_Call_RP_Nvm_EOLCalibrationData_GetErrorStatus(&ui8_WriteStatus);
	
		if ((uint8) E_OK == ui8_RetVal_ErrStat)
		{
		    if ((uint8) NVM_REQ_OK == ui8_WriteStatus) 
			{
				b_ReuqestFlagSuccess = TRUE;
			} 
			else if ((uint8) NVM_REQ_PENDING == ui8_WriteStatus) 
			{
				u_Retval = DCM_E_PENDING;
			} 
			else
			{
			    u_Retval = RTE_E_INVALID;
				*ErrorCode = DCM_E_GENERALPROGRAMMINGFAILURE;
			}
	    } 
		else 
		{
			u_Retval = RTE_E_INVALID;
			*ErrorCode = DCM_E_GENERALPROGRAMMINGFAILURE;
		}    
    }
	else if((uint8) DCM_CANCEL == OpStatus)
	{
	    (void)Rte_Call_RP_Nvm_EOLCalibrationData_GetErrorStatus(&ui8_WriteStatus);
	
	    if ((uint8) NVM_REQ_PENDING == ui8_WriteStatus) 
	    {
		    ui8_RetVal_ErrStat = NvM_CancelJobs(NvMConf_NvMBlockDescriptor_NvM_Block_EOLCalibrationData);
			
		    b_NvmOperationPending = TRUE;
	
		    if ((uint8) E_OK == ui8_RetVal_ErrStat) 
		    {
			    *ErrorCode = E_OK;
			    u_Retval = E_OK;
		    } 
		    else 
		    {
			    u_Retval = RTE_E_INVALID;
			    *ErrorCode = DCM_E_GENERALPROGRAMMINGFAILURE;
		    }
	    } 
	    else 
	    {
		    *ErrorCode = E_OK;
		    u_Retval = E_OK;
	    }
	
	    b_ReuqestFlagSuccess = FALSE;
	}
	else
	{/*Do nothing.*/}

	dataOut0[0] = a_Sendbuffer[0];
	dataOut0[1] = a_Sendbuffer[1];

	if (TRUE == b_ReuqestFlagSuccess) 
    {		
	    (void)Rte_Call_RP_Nvm_EOLCalibrationData_SetRamBlockStatus(TRUE);
	  
		*ErrorCode = E_OK;
		u_Retval = E_OK;
	}
	else 
	{
		if ((uint8) DCM_E_PENDING == u_Retval)
		{
			*ErrorCode = DCM_E_REQUESTCORRECTLYRECEIVEDRESPONSEPENDING;
		} 
		else 
		{
			if (FALSE == b_NvmOperationPending) 
			{
				(void)Rte_Call_RP_Nvm_EOLCalibrationData_SetRamBlockStatus(TRUE);
			}
		}
	}
#endif
 
  return u_Retval;
} /* FUNC(Std_ReturnType, RTE_CODE) Dsm_u_RC_EOLCalibration_RequestRoutineResults (Dcm_OpStatusType OpStatus, P2VAR(Dcm_RequestDataOut_DcmDspRoutine_0x800B_DcmDspRoutineRequestResOutSignal_RoutineInformationType, AUTOMATIC, RTE_APPL_DATA) dataOut0, P2VAR(Dcm_RequestDataOut_DcmDspRoutine_0x800B_DcmDspRoutineRequestResOutSignal_RoutineStatusType, AUTOMATIC, RTE_APPL_DATA) dataOut1, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_APPL_DATA) ErrorCode) */
#endif


/**
 * \functions Dsm_u_RC_SDACalibration_StartRoutine
 *
 * \brief Request to start SDA online calibration.(31 01 800C)
 *
 ** \param[in] none,
 *
 ** \param[out] none,
 **                 
 *
 ** \return RTE_E_OK, 
 * \comments 
 *
 */
#if (DSM_FEAT_RC_SDACalibration_StartRoutine == STD_ON)
FUNC(Std_ReturnType, RTE_CODE) Dsm_u_RC_SDACalibration_StartRoutine (Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_APPL_DATA) ErrorCode)
{
    /* suppress compiler warnings about unused arguments */
	Std_ReturnType u_Retval = RTE_E_OK;
    (void)OpStatus;
#if((DSM_SYSTEM_TYPE == DSM_SYSTEM_MFC5J3_C673)|| \
								(DSM_SYSTEM_TYPE == DSM_SYSTEM_MFC5J3_C385))

	static uint8 a_SocSysState[1] = {0};
	Std_ReturnType u_RetVal_Read = RTE_E_OK;
	static boolean b_ReuqestFlagSuccess;
    static uint8 u_RequestCounter = 0;
	
	b_ReuqestFlagSuccess = FALSE;
	
    Rte_Call_RP_Sdc_SendInterface_Diag_SocSysState_Read((void*)a_SocSysState,1);
	/*MCU check the system state of Soc in normal or not, if not will be return NRC22.*/	
	if(a_SocSysState[0] != e_Sdc_SocSystemStatus_Normal)
	{
        *ErrorCode = DCM_E_CONDITIONSNOTCORRECT;
		u_Retval = RTE_E_INVALID;
	}
	else if(a_SocSysState[0] == e_Sdc_SocSystemStatus_Normal)
	{   
	    /*MCU recevived UDS code and send SDA calibration request through SPI message 0x0202.*/
        u_RetVal_Read= Rte_Call_RP_Sdc_SendInterface_Calibration_RequestSDACalibration();
		
	    if(u_RetVal_Read != RTE_E_OK)
	    {   
            u_RequestCounter++;
			if(u_RequestCounter < 0x05u)
			{
			    u_Retval = DCM_E_PENDING; 
			}
			else
			{
			    u_RequestCounter =0u;
		        *ErrorCode = DCM_E_CONDITIONSNOTCORRECT;
		        u_Retval = RTE_E_INVALID;
			}
	    }
	    else
	    {
	        b_ReuqestFlagSuccess = TRUE;
	    }
	}
    else
    {/*Do nothing.*/}

	if (TRUE == b_ReuqestFlagSuccess) 
	{  
		*ErrorCode = E_OK;
		u_Retval = RTE_E_OK;
	}
	else
	{
	    if ((uint8)DCM_E_PENDING == u_Retval)
	    {
		    *ErrorCode = DCM_E_REQUESTCORRECTLYRECEIVEDRESPONSEPENDING;
	    }
	    else{ /*Do nothing.*/ }
	}
#endif

    return u_Retval;
} /* FUNC(Std_ReturnType, RTE_CODE) Dsm_u_RC_SDACalibration_StartRoutine (Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_APPL_DATA) ErrorCode) */
#endif

/**
 * \functions Dsm_u_RC_SDACalibration_RequestRoutineResults
 *
 * \brief Request to get the results of SDA online calibration.(31 03 800C)
 *
 ** \param[in] none,
 *
 ** \param[out] none,
 **                 
 *
 ** \return RTE_E_OK, 
 * \comments 
 *
 */
#if (DSM_FEAT_RC_SDACalibration_RequestRoutineResults == STD_ON)
FUNC(Std_ReturnType, RTE_CODE) Dsm_u_RC_SDACalibration_RequestRoutineResults (Dcm_OpStatusType OpStatus, P2VAR(Dcm_RequestDataOut_DcmDspRoutine_0x800C_DcmDspRoutineRequestResOutSignal_00Type, AUTOMATIC, RTE_APPL_DATA) dataOut0, P2VAR(Dcm_RequestDataOut_DcmDspRoutine_0x800C_DcmDspRoutineRequestResOutSignal_01Type, AUTOMATIC, RTE_APPL_DATA) dataOut1, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_APPL_DATA) ErrorCode)
{
    /* suppress compiler warnings about unused arguments */
    Std_ReturnType u_Retval = RTE_E_OK;
	uint16 length = 0;
#if((DSM_SYSTEM_TYPE == DSM_SYSTEM_MFC5J3_C673)|| \
							  (DSM_SYSTEM_TYPE == DSM_SYSTEM_MFC5J3_C385))

    static uint8 a_CalibrationFlag[1] = {0};
    static uint8 a_CameraCaliresultDetails[1] = {0};
    static uint8 a_Sendbuffer[2] ={0x78,0xFF};
    static boolean b_WriteFlagSuccess;
	Std_ReturnType ui8_RetVal_Write = RTE_E_INVALID;
	Std_ReturnType ui8_RetVal_ErrStat = RTE_E_INVALID;
	NvM_RequestResultType ui8_WriteStatus = NVM_REQ_NOT_OK;
    boolean b_NvmOperationPending = FALSE;
	CameraValue_Type s_CameraParamter;
	uint8 SocEOLCalResults = Rte_Call_RP_Sdc_SendInterface_Calibration_EOLCalResult_Read();
	if((uint8)DCM_INITIAL == OpStatus)	
	{
	    b_WriteFlagSuccess = FALSE;
		
        Rte_Call_RP_Sdc_SendInterface_Calibration_CalibrationFlag_Read((void*)a_CalibrationFlag,1);
	    Rte_Call_RP_Sdc_SendInterface_Calibration_CameraCaliresultDetails_Read((void*)a_CameraCaliresultDetails,1);
		
	    if(SocEOLCalResults == 0x00)
	    {
		    /*78 00: The result is invalid, the routine is not executed*/
		    a_Sendbuffer[0] = 0x78;
		    a_Sendbuffer[1] = 0xff;
	    }
	    else if((SocEOLCalResults == 0x00) && (a_CalibrationFlag[0] == 0x00))
	    {
		    /*7A 00: The result is valid, the routine is not executed*/	
		    a_Sendbuffer[0] = 0x7A;
		    a_Sendbuffer[1] = 0xff;
	    }
		else{/*Do nothing.*/}
		
		if(a_CalibrationFlag[0] == 0x0E)
		{
			/*0x0E :  calibration is not finished*/
			/*7B 01: Calibration in progress */
			a_Sendbuffer[0] = 0x7B;
			a_Sendbuffer[1] = 0X01;
		}
		else if(a_CalibrationFlag[0] == 0x05)
		{
			/*0x05 - Intial_online_Calibration is  done*/			
			if(a_CameraCaliresultDetails[0] == 0x00)
			{
				/*Success*/
				/*7B 03: Calibration completed */
				a_Sendbuffer[0] = 0x7B;
				a_Sendbuffer[1] = 0X03;
			}
			else if((a_CameraCaliresultDetails[0] == 0x06) ||
				    (a_CameraCaliresultDetails[0] == 0x07) ||
				    (a_CameraCaliresultDetails[0] == 0x08))
			{
				/*7B 04: The angle exceeds the limit, the calibration fails 02 Calibration progress*/
				a_Sendbuffer[0] = 0x7B;
				a_Sendbuffer[1] = 0X04;
			}
			else
			{
				/*other failure*/
				/*7B 02: Calibration suspended, the condition is incorrect*/
				a_Sendbuffer[0] = 0x7B;
				a_Sendbuffer[1] = 0X02;			
			}
			Rte_Call_RP_Sdc_SendInterface_Calibration_CameraValue_Read(&s_CameraParamter, length);
			
       		/*Service for setting the lock status of a permanent RAM block of an NVRAM block.*/
		    (void)Rte_Call_RP_Nvm_SDACalibrationData_SetRamBlockStatus(FALSE);
			
			RAM_NVM_BLOCK_SDACalibrationData[0] = (uint8)(a_CameraCaliresultDetails[0]); /* Byte 8: Can read last SDA result*/

			if(a_CameraCaliresultDetails[0] == 0x00)
		    {
		        /* Byte 0-7: F1F9 - EOL calibration parameters */
		        uint16 ui16_roll_angle = (uint16)((20 - ((float32)(s_CameraParamter.roll * 0.001 ) - 10))/0.001);
		        uint16 ui16_pitch_angle = (uint16)((20 - ((float32)(s_CameraParamter.pitch * 0.001 ) - 10))/0.001);
		        uint16 ui16_yaw_angle = (uint16)((20 - ((float32)(s_CameraParamter.yaw * 0.001 ) - 10))/0.001);

		        RAM_NVM_BLOCK_SDACalibrationData[1] = (uint8)(ui16_roll_angle >> 8);
		        RAM_NVM_BLOCK_SDACalibrationData[2] = (uint8)(ui16_roll_angle);
		        RAM_NVM_BLOCK_SDACalibrationData[3] = (uint8)(ui16_pitch_angle >> 8);
		        RAM_NVM_BLOCK_SDACalibrationData[4] = (uint8)(ui16_pitch_angle);
		        RAM_NVM_BLOCK_SDACalibrationData[5] = (uint8)(ui16_yaw_angle >> 8);
		        RAM_NVM_BLOCK_SDACalibrationData[6] = (uint8)(ui16_yaw_angle);
	        }

	        ui8_RetVal_Write = Rte_Call_RP_Nvm_SDACalibrationData_WriteBlock((void *) &RAM_NVM_BLOCK_SDACalibrationData);

		    if ((uint8) E_OK == ui8_RetVal_Write) 
		    {
			    ui8_RetVal_ErrStat = Rte_Call_RP_Nvm_SDACalibrationData_GetErrorStatus(&ui8_WriteStatus);
	
			    if ((uint8) E_OK == ui8_RetVal_ErrStat)
			    {
				    if ((uint8) NVM_REQ_OK == ui8_WriteStatus) 
				    {
					    b_WriteFlagSuccess = TRUE;
				    }
				    else if ((uint8) NVM_REQ_PENDING == ui8_WriteStatus)
				    {
					    u_Retval = DCM_E_PENDING;
				    } 
				    else 
				    {
					    u_Retval = RTE_E_INVALID;
					    *ErrorCode = DCM_E_GENERALPROGRAMMINGFAILURE;
				    }
			    } 
			    else 
			    {
				    u_Retval = RTE_E_INVALID;
				    *ErrorCode = DCM_E_GENERALPROGRAMMINGFAILURE;
			    }
		    }
		    else 
		    {
			    u_Retval = RTE_E_INVALID;
			    *ErrorCode = DCM_E_GENERALPROGRAMMINGFAILURE;
		    }
		}
	}
	else if((uint8)DCM_PENDING == OpStatus)
	{
	    ui8_RetVal_ErrStat = Rte_Call_RP_Nvm_SDACalibrationData_GetErrorStatus(&ui8_WriteStatus);
	
		if ((uint8) E_OK == ui8_RetVal_ErrStat)
		{
		    if ((uint8) NVM_REQ_OK == ui8_WriteStatus) 
			{
				b_WriteFlagSuccess = TRUE;
			} 
			else if ((uint8) NVM_REQ_PENDING == ui8_WriteStatus) 
			{
				u_Retval = DCM_E_PENDING;
			} 
			else
			{
			    u_Retval = RTE_E_INVALID;
				*ErrorCode = DCM_E_GENERALPROGRAMMINGFAILURE;
			}
	    } 
		else 
		{
			u_Retval = RTE_E_INVALID;
			*ErrorCode = DCM_E_GENERALPROGRAMMINGFAILURE;
		}    
	}
	else if((uint8) DCM_CANCEL == OpStatus)
	{
	    (void) Rte_Call_RP_Nvm_SDACalibrationData_GetErrorStatus(&ui8_WriteStatus);
	
	    if ((uint8) NVM_REQ_PENDING == ui8_WriteStatus) 
	    {
		    ui8_RetVal_ErrStat = NvM_CancelJobs(NvMConf_NvMBlockDescriptor_NvM_Block_SDACalibrationData);
			
		    b_NvmOperationPending = TRUE;
	
		    if ((uint8) E_OK == ui8_RetVal_ErrStat) 
		    {
			    *ErrorCode = E_OK;
			    u_Retval = E_OK;
		    } 
		    else 
		    {
			    u_Retval = RTE_E_INVALID;
			    *ErrorCode = DCM_E_GENERALPROGRAMMINGFAILURE;
		    }
	    } 
	    else 
	    {
		    *ErrorCode = E_OK;
		    u_Retval = E_OK;
	    }
	
	    b_WriteFlagSuccess = FALSE;

	}
	else
	{/*Do nothing.*/}

	dataOut0[0] = a_Sendbuffer[0];
	dataOut0[1] = a_Sendbuffer[1];
	
	if (TRUE == b_WriteFlagSuccess) 
    {		
	    (void)Rte_Call_RP_Nvm_SDACalibrationData_SetRamBlockStatus(TRUE);
	  
		*ErrorCode = E_OK;
		u_Retval = E_OK;
	}
	else 
	{
		if ((uint8) DCM_E_PENDING == u_Retval)
		{
			*ErrorCode = DCM_E_REQUESTCORRECTLYRECEIVEDRESPONSEPENDING;
		} 
		else 
		{
			if (FALSE == b_NvmOperationPending) 
			{
				(void)Rte_Call_RP_Nvm_SDACalibrationData_SetRamBlockStatus(TRUE);
			}
		}
	}
#endif

    return u_Retval;
} /* FUNC(Std_ReturnType, RTE_CODE) Dsm_u_RC_SDACalibration_RequestRoutineResults (Dcm_OpStatusType OpStatus, P2VAR(Dcm_RequestDataOut_DcmDspRoutine_0x800C_DcmDspRoutineRequestResOutSignal_00Type, AUTOMATIC, RTE_APPL_DATA) dataOut0, P2VAR(Dcm_RequestDataOut_DcmDspRoutine_0x800C_DcmDspRoutineRequestResOutSignal_01Type, AUTOMATIC, RTE_APPL_DATA) dataOut1, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_APPL_DATA) ErrorCode) */
#endif

/**
 * \functions Dsm_u_RC_OTPEnable_StartRoutine
 *
 * \brief Request to enable OTP protection.(31 01 8011)
 *
 ** \param[in] none,
 *
 ** \param[out] none,
 **                 
 *
 ** \return RTE_E_OK, 
 * \comments 
 *
 */
#if (DSM_FEAT_RC_OTPEnable_StartRoutine == STD_ON)
FUNC(Std_ReturnType, RTE_CODE) Dsm_u_RC_OTPEnable_StartRoutine (Dcm_StartDataIn_DcmDspRoutine_0x8011_DcmDspStartRoutineInSignal_0Type dataIn0, Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_APPL_DATA) ErrorCode)
{
    /* suppress compiler warnings about unused arguments */
	Std_ReturnType u_Retval = RTE_E_OK;
	(void)OpStatus;
#if((DSM_SYSTEM_TYPE == DSM_SYSTEM_MFC5J3_C673)|| \
								(DSM_SYSTEM_TYPE == DSM_SYSTEM_MFC5J3_C385))

    if(dataIn0 == 0x01u)
    {
        CDD_Ucb_ReqOTPIFLock();
	}
	else
	{
	    *ErrorCode = DCM_E_REQUESTOUTOFRANGE; //NRC31
	    u_Retval = RTE_E_INVALID;
	}
	
#endif

  return u_Retval;
} /* FUNC(Std_ReturnType, RTE_CODE) Dsm_u_RC_OTPEnable_StartRoutine (Dcm_StartDataIn_DcmDspRoutine_0x8011_DcmDspStartRoutineInSignal_0Type dataIn0, Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_APPL_DATA) ErrorCode) */
#endif

/**
 * \functions Dsm_u_RC_OTPEnable_RequestRoutineResults
 *
 * \brief Request to get the results of OTP protection.(31 03 8011)
 *
 ** \param[in] none,
 *
 ** \param[out] none,
 **                 
 *
 ** \return RTE_E_OK, 
 * \comments 
 *
 */
#if (DSM_FEAT_RC_OTPEnable_RequestRoutineResults == STD_ON)
FUNC(Std_ReturnType, RTE_CODE) Dsm_u_RC_OTPEnable_RequestRoutineResults (Dcm_OpStatusType OpStatus, P2VAR(Dcm_RequestDataOut_DcmDspRoutine_0x8011_DcmDspRoutineRequestResOutSignal_0Type, AUTOMATIC, RTE_APPL_DATA) dataOut0, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_APPL_DATA) ErrorCode)
{
    /* suppress compiler warnings about unused arguments */
	Std_ReturnType u_Retval = RTE_E_OK;
	(void)OpStatus;
	(void)*ErrorCode;
#if((DSM_SYSTEM_TYPE == DSM_SYSTEM_MFC5J3_C673)|| \
								  (DSM_SYSTEM_TYPE == DSM_SYSTEM_MFC5J3_C385))

    if(CDD_Ucb_GetOTPLockState() == 0x01u)
    {
        dataOut0[0] = 0x02u; //OTP Enabled
    }
    else
    {
        dataOut0[0] = 0x01u; //OTP Disabled
    }
#endif

    return u_Retval;
} /* FUNC(Std_ReturnType, RTE_CODE) Dsm_u_RC_OTPEnable_RequestRoutineResults (Dcm_OpStatusType OpStatus, P2VAR(Dcm_RequestDataOut_DcmDspRoutine_0x8011_DcmDspRoutineRequestResOutSignal_0Type, AUTOMATIC, RTE_APPL_DATA) dataOut0, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_APPL_DATA) ErrorCode) */
#endif

/**
 * \functions Dsm_u_RC_ETHSetPortConfiguration_StartRoutine
 *
 * \brief Request to Set ethernet port configuration.(31 01 0301)
 *
 ** \param[in] dataIn0, 0x01:link down 0x00:link up
 *
 ** \param[out] none,
 **                 
 *
 ** \return RTE_E_OK, 
 * \comments 
 *
 */
#if (DSM_FEAT_RC_ETHSetPortConfiguration_StartRoutine == STD_ON)
FUNC(Std_ReturnType, RTE_CODE) Dsm_u_RC_ETHSetPortConfiguration_StartRoutine (Dcm_StartDataIn_DcmDspRoutine_0x0301_DcmDspStartRoutineInSignal_0Type dataIn0, Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_APPL_DATA) ErrorCode)
{
    /* suppress compiler warnings about unused arguments */
    Std_ReturnType u_Retval = RTE_E_OK;
    (void)OpStatus;
#if((DSM_SYSTEM_TYPE == DSM_SYSTEM_MFC5J3_C673)|| \
								(DSM_SYSTEM_TYPE == DSM_SYSTEM_MFC5J3_C385)) 

    static uint8 u_RequestCounter = 0;
    static boolean b_CompleteSuccess;

	b_CompleteSuccess = FALSE;
	
    if((dataIn0 == 0x00u)||(dataIn0 == 0x01u))
    {
        u_Retval = Rte_Call_RP_Sdc_SendInterface_Eth_EthSetPortConfiguration_StartRoutine(dataIn0);
	    if((uint8)E_OK == u_Retval)
	    {
	        b_CompleteSuccess = TRUE;
	    }
	    else
	    {
	        u_RequestCounter++;
		    if(u_RequestCounter < 10u)
		    {
		        u_Retval = DCM_E_PENDING; 
		    }
		    else
		    {
		        u_RequestCounter = 0u;
			    *ErrorCode = DCM_E_CONDITIONSNOTCORRECT;
			    u_Retval = RTE_E_INVALID;
		    }
	    } 
    }
    else
    {
  	    *ErrorCode = DCM_E_REQUESTOUTOFRANGE;
	    u_Retval = RTE_E_INVALID;
    }
  
    if(TRUE == b_CompleteSuccess)
    {	 
        *ErrorCode = E_OK;
		u_Retval = RTE_E_OK;
    }
	else
	{
	    if ((uint8)DCM_E_PENDING == u_Retval)
		{
		    *ErrorCode = DCM_E_REQUESTCORRECTLYRECEIVEDRESPONSEPENDING;
		}
		else
		{
		    /*Do nothing.*/
		}
	}
#endif
  
   return u_Retval;

} /* FUNC(Std_ReturnType, RTE_CODE) Dsm_u_RC_ETHSetPortConfiguration_StartRoutine (Dcm_StartDataIn_DcmDspRoutine_0x0301_DcmDspStartRoutineInSignal_0Type dataIn0, Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_APPL_DATA) ErrorCode) */
#endif

/**
 * \functions Dsm_u_RC_ETHSetPortConfiguration_RequestRoutineResults
 *
 * \brief Request to reset ethernet port configuration.(31 03 0301)
 *
 ** \param[in] none,
 *
 ** \param[out] none,
 **                 
 *
 ** \return RTE_E_OK, 
 * \comments 
 *
 */
#if (DSM_FEAT_RC_ETHSetPortConfiguration_RequestRoutineResults == STD_ON)
FUNC(Std_ReturnType, RTE_CODE) Dsm_u_RC_ETHSetPortConfiguration_RequestRoutineResults (Dcm_OpStatusType OpStatus, P2VAR(Dcm_RequestDataOut_DcmDspRoutine_0x0301_DcmDspRoutineRequestResOutSignal_0Type, AUTOMATIC, RTE_APPL_DATA) dataOut0, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_APPL_DATA) ErrorCode)
{
    /* suppress compiler warnings about unused arguments */
	(void)OpStatus;
	(void)*ErrorCode;
#if((DSM_SYSTEM_TYPE == DSM_SYSTEM_MFC5J3_C673)|| \
								(DSM_SYSTEM_TYPE == DSM_SYSTEM_MFC5J3_C385)) 
								
	Rte_Call_RP_Sdc_SendInterface_Eth_EthSetPortConfigurationInfo_Read((void*)dataOut0,1);

#endif

	return RTE_E_OK;

} /* FUNC(Std_ReturnType, RTE_CODE) Dsm_u_RC_ETHSetPortConfiguration_RequestRoutineResults (Dcm_OpStatusType OpStatus, P2VAR(Dcm_RequestDataOut_DcmDspRoutine_0x0301_DcmDspRoutineRequestResOutSignal_0Type, AUTOMATIC, RTE_APPL_DATA) dataOut0, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_APPL_DATA) ErrorCode) */
#endif

/**
 * \functions Dsm_u_RC_ETHResetPortConfiguration_StartRoutine
 *
 * \brief Request to reset ethernet port configuration.(31 01 0302)
 *
 ** \param[in] none,
 *
 ** \param[out] none,
 **                 
 *
 ** \return RTE_E_OK, 
 * \comments 
 *
 */
#if (DSM_FEAT_RC_ETHResetPortConfiguration_StartRoutine == STD_ON)
FUNC(Std_ReturnType, RTE_CODE) Dsm_u_RC_ETHResetPortConfiguration_StartRoutine (Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_APPL_DATA) ErrorCode)
{
    /* suppress compiler warnings about unused arguments */
	Std_ReturnType u_Retval = RTE_E_OK;
	(void)OpStatus;
#if((DSM_SYSTEM_TYPE == DSM_SYSTEM_MFC5J3_C673)|| \
								  (DSM_SYSTEM_TYPE == DSM_SYSTEM_MFC5J3_C385)) 
  
	  static uint8 u_RequestCounter = 0;
	  static boolean b_CompleteSuccess;
  
	  b_CompleteSuccess = FALSE;
	  
	  u_Retval = Rte_Call_RP_Sdc_SendInterface_Eth_EthResetPortConfiguration_StartRoutine();
  
	  if((uint8)E_OK == u_Retval)
	  {
	      b_CompleteSuccess = TRUE;
	  }
	  else
	  {
		  u_RequestCounter++;
		  if(u_RequestCounter < 10u)
		  {
		      u_Retval = DCM_E_PENDING; 
		  }
		  else
		  {
			  u_RequestCounter = 0u;
			  *ErrorCode = DCM_E_CONDITIONSNOTCORRECT;
			  u_Retval = RTE_E_INVALID;
		  }
	  } 
	  
	  if(TRUE == b_CompleteSuccess)
	  {    
		  *ErrorCode = E_OK;
		  u_Retval = RTE_E_OK;
	  }
	  else
	  {
		  if ((uint8)DCM_E_PENDING == u_Retval)
		  {
			  *ErrorCode = DCM_E_REQUESTCORRECTLYRECEIVEDRESPONSEPENDING;
		  }
		  else
		  {
			  /*Do nothing.*/
		  }
	  }
#endif
	
	 return u_Retval;

} /* FUNC(Std_ReturnType, RTE_CODE) Dsm_u_RC_ETHResetPortConfiguration_StartRoutine (Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_APPL_DATA) ErrorCode) */
#endif

/**
 * \functions Dsm_u_RC_ETHResetPortConfiguration_RequestRoutineResults
 *
 * \brief Request to get the results of ethernet port configuration.(31 03 0302)
 *
 ** \param[in] none,
 *
 ** \param[out] none,
 **                 
 *
 ** \return RTE_E_OK, 
 * \comments 
 *
 */
#if (DSM_FEAT_RC_ETHResetPortConfiguration_RequestRoutineResults == STD_ON)
FUNC(Std_ReturnType, RTE_CODE) Dsm_u_RC_ETHResetPortConfiguration_RequestRoutineResults (Dcm_OpStatusType OpStatus, P2VAR(Dcm_RequestDataOut_DcmDspRoutine_0x0302_DcmDspRoutineRequestResOutSignal_0Type, AUTOMATIC, RTE_APPL_DATA) dataOut0, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_APPL_DATA) ErrorCode)
{
    /* suppress compiler warnings about unused arguments */
	(void)OpStatus;
	(void)*ErrorCode;
#if((DSM_SYSTEM_TYPE == DSM_SYSTEM_MFC5J3_C673)|| \
								  (DSM_SYSTEM_TYPE == DSM_SYSTEM_MFC5J3_C385)) 
								  
	Rte_Call_RP_Sdc_SendInterface_Eth_EthResetPortConfigurationInfo_Read((void*)dataOut0,1);
  
#endif
  
	return RTE_E_OK;

} /* FUNC(Std_ReturnType, RTE_CODE) Dsm_u_RC_ETHResetPortConfiguration_RequestRoutineResults (Dcm_OpStatusType OpStatus, P2VAR(Dcm_RequestDataOut_DcmDspRoutine_0x0302_DcmDspRoutineRequestResOutSignal_0Type, AUTOMATIC, RTE_APPL_DATA) dataOut0, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_APPL_DATA) ErrorCode) */
#endif

/**
 * \functions Dsm_u_RC_ETHReadPhyRegister_StartRoutine
 *
 * \brief Request to Read ethernet physical register.(31 01 0303)
 *
 ** \param[in] none,
 *
 ** \param[out] none,
 **                 
 *
 ** \return RTE_E_OK, 
 * \comments 
 *
 */
#if (DSM_FEAT_RC_ETHReadPhyRegister_StartRoutine == STD_ON)
FUNC(Std_ReturnType, RTE_CODE) Dsm_u_RC_ETHReadPhyRegister_StartRoutine (Dcm_StartDataIn_DcmDspRoutine_0x0303_DcmDspStartRoutineInSignal_0Type dataIn0, Dcm_StartDataIn_DcmDspRoutine_0x0303_DcmDspStartRoutineInSignal_1Type dataIn1, Dcm_StartDataIn_DcmDspRoutine_0x0303_DcmDspStartRoutineInSignal_2Type dataIn2, Dcm_StartDataIn_DcmDspRoutine_0x0303_DcmDspStartRoutineInSignal_3Type dataIn3, Dcm_StartDataIn_DcmDspRoutine_0x0303_DcmDspStartRoutineInSignal_4Type dataIn4, Dcm_StartDataIn_DcmDspRoutine_0x0303_DcmDspStartRoutineInSignal_5Type dataIn5, Dcm_StartDataIn_DcmDspRoutine_0x0303_DcmDspStartRoutineInSignal_6Type dataIn6, Dcm_StartDataIn_DcmDspRoutine_0x0303_DcmDspStartRoutineInSignal_7Type dataIn7, Dcm_StartDataIn_DcmDspRoutine_0x0303_DcmDspStartRoutineInSignal_8Type dataIn8, Dcm_StartDataIn_DcmDspRoutine_0x0303_DcmDspStartRoutineInSignal_9Type dataIn9, Dcm_StartDataIn_DcmDspRoutine_0x0303_DcmDspStartRoutineInSignal_10Type dataIn10, Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_APPL_DATA) ErrorCode)
{
    /* suppress compiler warnings about unused arguments */
	Std_ReturnType u_Retval = RTE_E_OK;
	(void)OpStatus;
#if((DSM_SYSTEM_TYPE == DSM_SYSTEM_MFC5J3_C673)|| \
										  (DSM_SYSTEM_TYPE == DSM_SYSTEM_MFC5J3_C385)) 
		  
	static uint8 u_RequestCounter = 0;
	static boolean b_CompleteSuccess;
	uint8 a_buffer[11]={0};
		
	b_CompleteSuccess = FALSE;
  
	a_buffer[0] = dataIn0;
	a_buffer[1] = dataIn1;
	a_buffer[2] = dataIn2;
	a_buffer[3] = dataIn3;
	a_buffer[4] = dataIn4;
	a_buffer[5] = dataIn5;
	a_buffer[6] = dataIn6;
	a_buffer[7] = dataIn7;
	a_buffer[8] = dataIn8;
	a_buffer[9] = dataIn9;
	a_buffer[10] = dataIn10;	
	
	u_Retval = Rte_Call_RP_Sdc_SendInterface_Eth_EthReadPhyRegister_StartRoutine((void*)a_buffer, 11);
				
	if((uint8)E_OK == u_Retval)
	{
		b_CompleteSuccess = TRUE;
	}
	else
	{
		u_RequestCounter++;
		if(u_RequestCounter < 10u)
		{
			u_Retval = DCM_E_PENDING; 
		}
		else
		{
			u_RequestCounter = 0u;
			*ErrorCode = DCM_E_CONDITIONSNOTCORRECT;
			u_Retval = RTE_E_INVALID;
		}
	} 
		 
	if(TRUE == b_CompleteSuccess)
	{	 
		*ErrorCode = E_OK;
		u_Retval = RTE_E_OK;
	}
	else
	{
		if ((uint8)DCM_E_PENDING == u_Retval)
		{
			*ErrorCode = DCM_E_REQUESTCORRECTLYRECEIVEDRESPONSEPENDING;
		}
		else
		{
			/*Do nothing.*/
		}
	}
#endif
			
	return u_Retval;

} /* FUNC(Std_ReturnType, RTE_CODE) Dsm_u_RC_ETHReadPhyRegister_StartRoutine (Dcm_StartDataIn_DcmDspRoutine_0x0303_DcmDspStartRoutineInSignal_0Type dataIn0, Dcm_StartDataIn_DcmDspRoutine_0x0303_DcmDspStartRoutineInSignal_1Type dataIn1, Dcm_StartDataIn_DcmDspRoutine_0x0303_DcmDspStartRoutineInSignal_2Type dataIn2, Dcm_StartDataIn_DcmDspRoutine_0x0303_DcmDspStartRoutineInSignal_3Type dataIn3, Dcm_StartDataIn_DcmDspRoutine_0x0303_DcmDspStartRoutineInSignal_4Type dataIn4, Dcm_StartDataIn_DcmDspRoutine_0x0303_DcmDspStartRoutineInSignal_5Type dataIn5, Dcm_StartDataIn_DcmDspRoutine_0x0303_DcmDspStartRoutineInSignal_6Type dataIn6, Dcm_StartDataIn_DcmDspRoutine_0x0303_DcmDspStartRoutineInSignal_7Type dataIn7, Dcm_StartDataIn_DcmDspRoutine_0x0303_DcmDspStartRoutineInSignal_8Type dataIn8, Dcm_StartDataIn_DcmDspRoutine_0x0303_DcmDspStartRoutineInSignal_9Type dataIn9, Dcm_StartDataIn_DcmDspRoutine_0x0303_DcmDspStartRoutineInSignal_10Type dataIn10, Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_APPL_DATA) ErrorCode) */
#endif

/**
 * \functions Dsm_u_RC_ETHResetPortConfiguration_RequestRoutineResults
 *
 * \brief Request to get the results of ethernet physical register.(31 03 0303)
 *
 ** \param[in] none,
 *
 ** \param[out] none,
 **                 
 *
 ** \return RTE_E_OK, 
 * \comments 
 *
 */
#if (DSM_FEAT_RC_ETHReadPhyRegister_RequestRoutineResults == STD_ON)
FUNC(Std_ReturnType, RTE_CODE) Dsm_u_RC_ETHReadPhyRegister_RequestRoutineResults (Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_APPL_DATA) dataOut0, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_APPL_DATA) ErrorCode)
{
    /* suppress compiler warnings about unused arguments */
	(void)OpStatus;
	(void)*ErrorCode;
#if((DSM_SYSTEM_TYPE == DSM_SYSTEM_MFC5J3_C673)|| \
										  (DSM_SYSTEM_TYPE == DSM_SYSTEM_MFC5J3_C385)) 
										  
	Rte_Call_RP_Sdc_SendInterface_Eth_EthReadPhyRegisterInfo_Read((void*)dataOut0,3);
		  
#endif
		  
	return RTE_E_OK;

} /* FUNC(Std_ReturnType, RTE_CODE) Dsm_u_RC_ETHReadPhyRegister_RequestRoutineResults (Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_APPL_DATA) dataOut0, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_APPL_DATA) ErrorCode) */
#endif

/**
 * \functions Dsm_u_RC_ETHCableDiagnostic_StartRoutine
 *
 * \brief Request to set ethernet cable diagnostic.(31 01 0305)
 *
 ** \param[in] none,
 *
 ** \param[out] none,
 **                 
 *
 ** \return RTE_E_OK, 
 * \comments 
 *
 */
#if (DSM_FEAT_RC_ETHCableDiagnostic_StartRoutine == STD_ON)
FUNC(Std_ReturnType, RTE_CODE) Dsm_u_RC_ETHCableDiagnostic_StartRoutine (Dcm_StartDataIn_DcmDspRoutine_0x0305_DcmDspStartRoutineInSignal_0Type dataIn0, Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_APPL_DATA) ErrorCode)
{
	  /* suppress compiler warnings about unused arguments */
	  Std_ReturnType u_Retval = RTE_E_OK;
	  (void)OpStatus;
#if((DSM_SYSTEM_TYPE == DSM_SYSTEM_MFC5J3_C673)|| \
											(DSM_SYSTEM_TYPE == DSM_SYSTEM_MFC5J3_C385)) 
			
	  static uint8 u_RequestCounter = 0;
	  static boolean b_CompleteSuccess;
		  
	  b_CompleteSuccess = FALSE;
				  
	  u_Retval = Rte_Call_RP_Sdc_SendInterface_Eth_EthCableDiagnostic_StartRoutine(dataIn0);
				  
	  if((uint8)E_OK == u_Retval)
	  {
	      b_CompleteSuccess = TRUE;
	  }
	  else
	  {
		  u_RequestCounter++;
		  if(u_RequestCounter < 10u)
		  {
		      u_Retval = DCM_E_PENDING; 
		  }
		  else
		  {
			  u_RequestCounter = 0u;
			  *ErrorCode = DCM_E_CONDITIONSNOTCORRECT;
			  u_Retval = RTE_E_INVALID;
		  }
	  } 
	  			   
	  if(TRUE == b_CompleteSuccess)
	  {    
		  *ErrorCode = E_OK;
		  u_Retval = RTE_E_OK;
	  }
	  else
	  {
		  if ((uint8)DCM_E_PENDING == u_Retval)
		  {
			  *ErrorCode = DCM_E_REQUESTCORRECTLYRECEIVEDRESPONSEPENDING;
		  }
		  else
		  {
			  /*Do nothing.*/
		  }
	  }
#endif
			  
	  return u_Retval;

} /* FUNC(Std_ReturnType, RTE_CODE) Dsm_u_RC_ETHCableDiagnostic_StartRoutine (Dcm_StartDataIn_DcmDspRoutine_0x0305_DcmDspStartRoutineInSignal_0Type dataIn0, Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_APPL_DATA) ErrorCode) */
#endif

/**
 * \functions Dsm_u_RC_ETHCableDiagnostic_RequestRoutineResults
 *
 * \brief Request to get the results of ethernet cable diagnostic.(31 03 0305)
 *
 ** \param[in] none,
 *
 ** \param[out] none,
 **                 
 *
 ** \return RTE_E_OK, 
 * \comments 
 *
 */
#if (DSM_FEAT_RC_ETHCableDiagnostic_RequestRoutineResults == STD_ON)
FUNC(Std_ReturnType, RTE_CODE) Dsm_u_RC_ETHCableDiagnostic_RequestRoutineResults (Dcm_OpStatusType OpStatus, P2VAR(Dcm_RequestDataOut_DcmDspRoutine_0x0305_DcmDspRoutineRequestResOutSignal_0Type, AUTOMATIC, RTE_APPL_DATA) dataOut0, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_APPL_DATA) ErrorCode)
{
    /* suppress compiler warnings about unused arguments */
	(void)OpStatus;
	(void)*ErrorCode;
#if((DSM_SYSTEM_TYPE == DSM_SYSTEM_MFC5J3_C673)|| \
										(DSM_SYSTEM_TYPE == DSM_SYSTEM_MFC5J3_C385)) 
										
	Rte_Call_RP_Sdc_SendInterface_Eth_EthCableDiagnosticInfo_Read((void*)dataOut0,1);
		
#endif
		
	return RTE_E_OK;

} /* FUNC(Std_ReturnType, RTE_CODE) Dsm_u_RC_ETHCableDiagnostic_RequestRoutineResults (Dcm_OpStatusType OpStatus, P2VAR(Dcm_RequestDataOut_DcmDspRoutine_0x0305_DcmDspRoutineRequestResOutSignal_0Type, AUTOMATIC, RTE_APPL_DATA) dataOut0, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_APPL_DATA) ErrorCode) */
#endif

/**
 * \functions Dsm_u_RC_ETHEnableTestMode_StartRoutine
 *
 * \brief Request to enable Ethernet test mode.(31 01 0306)
 *
 ** \param[in] none,
 *
 ** \param[out] none,
 **                 
 *
 ** \return RTE_E_OK, 
 * \comments 
 *
 */
#if (DSM_FEAT_RC_ETHEnableTestMode_StartRoutine == STD_ON)
FUNC(Std_ReturnType, RTE_CODE) Dsm_u_RC_ETHEnableTestMode_StartRoutine (Dcm_StartDataIn_DcmDspRoutine_0x0306_DcmDspStartRoutineInSignal_0Type dataIn0, Dcm_StartDataIn_DcmDspRoutine_0x0306_DcmDspStartRoutineInSignal_1Type dataIn1, Dcm_StartDataIn_DcmDspRoutine_0x0306_DcmDspStartRoutineInSignal_2Type dataIn2, Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_APPL_DATA) ErrorCode)
{
    /* suppress compiler warnings about unused arguments */
	Std_ReturnType u_Retval = RTE_E_OK;
	(void)OpStatus;
#if((DSM_SYSTEM_TYPE == DSM_SYSTEM_MFC5J3_C673)|| \
										  (DSM_SYSTEM_TYPE == DSM_SYSTEM_MFC5J3_C385)) 
		  
	static uint8 u_RequestCounter = 0;
	static boolean b_CompleteSuccess;
	uint8 a_buffer[3]={0};
		
	b_CompleteSuccess = FALSE;
  
	if((dataIn2 == 0x01u) || (dataIn2 == 0x02u)||
		(dataIn2 == 0x03u) || (dataIn2 == 0x04u)||
		(dataIn2 == 0x05u))
	{
		a_buffer[0] = dataIn0;
		a_buffer[1] = dataIn1;
		a_buffer[2] = dataIn2;		
			
		u_Retval = Rte_Call_RP_Sdc_SendInterface_Eth_EthEnableTestMode_StartRoutine((void*)a_buffer, 3);
				
		if((uint8)E_OK == u_Retval)
		{
			b_CompleteSuccess = TRUE;
		}
		else
		{
			u_RequestCounter++;
			if(u_RequestCounter < 10u)
			{
				u_Retval = DCM_E_PENDING; 
			}
			else
			{
				u_RequestCounter = 0u;
				*ErrorCode = DCM_E_CONDITIONSNOTCORRECT;
				u_Retval = RTE_E_INVALID;
			}
		} 
	}
	else
	{
		*ErrorCode = DCM_E_REQUESTOUTOFRANGE; //NRC31
		u_Retval = RTE_E_INVALID;
	}
		
			 
	if(TRUE == b_CompleteSuccess)
	{	 
		*ErrorCode = E_OK;
		u_Retval = RTE_E_OK;
	}
	else
	{
	    if ((uint8)DCM_E_PENDING == u_Retval)
		{
			*ErrorCode = DCM_E_REQUESTCORRECTLYRECEIVEDRESPONSEPENDING;
		}
		else
		{
			/*Do nothing.*/
		}
	}
#endif
			
	return u_Retval;

} /* FUNC(Std_ReturnType, RTE_CODE) Dsm_u_RC_ETHEnableTestMode_StartRoutine (Dcm_StartDataIn_DcmDspRoutine_0x0306_DcmDspStartRoutineInSignal_0Type dataIn0, Dcm_StartDataIn_DcmDspRoutine_0x0306_DcmDspStartRoutineInSignal_1Type dataIn1, Dcm_StartDataIn_DcmDspRoutine_0x0306_DcmDspStartRoutineInSignal_2Type dataIn2, Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_APPL_DATA) ErrorCode) */
#endif

/**
 * \functions Dsm_u_RC_ETHEnableTestMode_StopRoutine
 *
 * \brief Request to disable Ethernet test mode.(31 02 0306)
 *
 ** \param[in] none,
 *
 ** \param[out] none,
 **                 
 *
 ** \return RTE_E_OK, 
 * \comments 
 *
 */
#if (DSM_FEAT_RC_ETHEnableTestMode_StopRoutine == STD_ON)
FUNC(Std_ReturnType, RTE_CODE) Dsm_u_RC_ETHEnableTestMode_StopRoutine (Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_APPL_DATA) ErrorCode)
{
  /* suppress compiler warnings about unused arguments */
  (void)OpStatus;
  (void)*ErrorCode;
#if((DSM_SYSTEM_TYPE == DSM_SYSTEM_MFC5J3_C673)|| \
											(DSM_SYSTEM_TYPE == DSM_SYSTEM_MFC5J3_C385)) 

  Rte_Call_RP_Sdc_SendInterface_Eth_EthEnableTestMode_StopRoutine();

#endif

  return RTE_E_OK;
} /* FUNC(Std_ReturnType, RTE_CODE) Dsm_u_RC_ETHEnableTestMode_StopRoutine (Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_APPL_DATA) ErrorCode) */
#endif

/**
 * \functions Dsm_u_RC_ETHEnableTestMode_RequestRoutineResults
 *
 * \brief Request to get the results of Ethernet test mode.(31 03 0306)
 *
 ** \param[in] none,
 *
 ** \param[out] none,
 **                 
 *
 ** \return RTE_E_OK, 
 * \comments 
 *
 */
#if (DSM_FEAT_RC_ETHEnableTestMode_RequestRoutineResults == STD_ON)
FUNC(Std_ReturnType, RTE_CODE) Dsm_u_RC_ETHEnableTestMode_RequestRoutineResults (Dcm_OpStatusType OpStatus, P2VAR(Dcm_RequestDataOut_DcmDspRoutine_0x0306_DcmDspRoutineRequestResOutSignal_0Type, AUTOMATIC, RTE_APPL_DATA) dataOut0, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_APPL_DATA) ErrorCode)
{
	/* suppress compiler warnings about unused arguments */
	(void)OpStatus;
	(void)*ErrorCode;
#if((DSM_SYSTEM_TYPE == DSM_SYSTEM_MFC5J3_C673)|| \
									  (DSM_SYSTEM_TYPE == DSM_SYSTEM_MFC5J3_C385)) 
									  
	Rte_Call_RP_Sdc_SendInterface_Eth_EthEnableTestModeInfo_Read((void*)dataOut0,1);
	  
#endif
	  
	 return RTE_E_OK;

} /* FUNC(Std_ReturnType, RTE_CODE) Dsm_u_RC_ETHEnableTestMode_RequestRoutineResults (Dcm_OpStatusType OpStatus, P2VAR(Dcm_RequestDataOut_DcmDspRoutine_0x0306_DcmDspRoutineRequestResOutSignal_0Type, AUTOMATIC, RTE_APPL_DATA) dataOut0, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_APPL_DATA) ErrorCode) */
#endif

/**
 * \functions Dsm_u_RC_ETHPhyLoopBackTest_StartRoutine
 *
 * \brief Request to set ethernet physical loop back test.(31 01 0307)
 *
 ** \param[in] none,
 *
 ** \param[out] none,
 **                 
 *
 ** \return RTE_E_OK, 
 * \comments 
 *
 */
#if (DSM_FEAT_RC_ETHPhyLoopBackTest_StartRoutine == STD_ON)
FUNC(Std_ReturnType, RTE_CODE) Dsm_u_RC_ETHPhyLoopBackTest_StartRoutine (Dcm_StartDataIn_DcmDspRoutine_0x0307_DcmDspStartRoutineInSignal_0Type dataIn0, Dcm_StartDataIn_DcmDspRoutine_0x0307_DcmDspStartRoutineInSignal_1Type dataIn1, Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_APPL_DATA) ErrorCode)
{
	  /* suppress compiler warnings about unused arguments */
	  Std_ReturnType u_Retval = RTE_E_OK;
	  (void)OpStatus;
#if((DSM_SYSTEM_TYPE == DSM_SYSTEM_MFC5J3_C673)|| \
										(DSM_SYSTEM_TYPE == DSM_SYSTEM_MFC5J3_C385)) 
		
	  static uint8 u_RequestCounter = 0;
	  static boolean b_CompleteSuccess;
	  uint8 a_buffer[2]={0};
	  
	  b_CompleteSuccess = FALSE;

      if((dataIn1 == 0x01u) || (dataIn1 == 0x02u))
      {
	      a_buffer[0] = dataIn0;
		  a_buffer[1] = dataIn1;
						
		  u_Retval = Rte_Call_RP_Sdc_SendInterface_Eth_EthPhyLoopBackTest_StartRoutine((void*)a_buffer, 2);
			  
	      if((uint8)E_OK == u_Retval)
		  {
		      b_CompleteSuccess = TRUE;
		  }
		  else
		  {
			  u_RequestCounter++;
			  if(u_RequestCounter < 10u)
			  {
				  u_Retval = DCM_E_PENDING; 
			  }
			  else
			  {
				  u_RequestCounter = 0u;
				  *ErrorCode = DCM_E_CONDITIONSNOTCORRECT;
				  u_Retval = RTE_E_INVALID;
			  }
		  } 
	  }
	  else
	  {
	      *ErrorCode = DCM_E_REQUESTOUTOFRANGE; //NRC31
	      u_Retval = RTE_E_INVALID;
	  }
	  
		   
	  if(TRUE == b_CompleteSuccess)
	  {    
		  *ErrorCode = E_OK;
		  u_Retval = RTE_E_OK;
	  }
	  else
	  {
		  if ((uint8)DCM_E_PENDING == u_Retval)
		  {
			  *ErrorCode = DCM_E_REQUESTCORRECTLYRECEIVEDRESPONSEPENDING;
		  }
		  else
		  {
			  /*Do nothing.*/
		  }
	  }
#endif
		  
	  return u_Retval;

} /* FUNC(Std_ReturnType, RTE_CODE) Dsm_u_RC_ETHPhyLoopBackTest_StartRoutine (Dcm_StartDataIn_DcmDspRoutine_0x0307_DcmDspStartRoutineInSignal_0Type dataIn0, Dcm_StartDataIn_DcmDspRoutine_0x0307_DcmDspStartRoutineInSignal_1Type dataIn1, Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_APPL_DATA) ErrorCode) */
#endif

/**
 * \functions Dsm_u_RC_ETHPhyLoopBackTest_StartRoutine
 *
 * \brief Request to disable ethernet physical loop back test.(31 02 0307)
 *
 ** \param[in] none,
 *
 ** \param[out] none,
 **                 
 *
 ** \return RTE_E_OK, 
 * \comments 
 *
 */
#if (DSM_FEAT_RC_ETHPhyLoopBackTest_StopRoutine == STD_ON)
FUNC(Std_ReturnType, RTE_CODE) Dsm_u_RC_ETHPhyLoopBackTest_StopRoutine (Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_APPL_DATA) ErrorCode)
{
    /* suppress compiler warnings about unused arguments */
    (void)OpStatus;
    (void)*ErrorCode;
#if((DSM_SYSTEM_TYPE == DSM_SYSTEM_MFC5J3_C673)|| \
										  (DSM_SYSTEM_TYPE == DSM_SYSTEM_MFC5J3_C385))

  Rte_Call_RP_Sdc_SendInterface_Eth_EthPhyLoopBackTest_StopRoutine();

#endif

  return RTE_E_OK;
} /* FUNC(Std_ReturnType, RTE_CODE) Dsm_u_RC_ETHPhyLoopBackTest_StopRoutine (Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_APPL_DATA) ErrorCode) */
#endif

/**
 * \functions Dsm_u_RC_ETHPhyLoopBackTest_RequestRoutineResults
 *
 * \brief Request to get the results of ethernet physical loop back test.(31 03 0307)
 *
 ** \param[in] none,
 *
 ** \param[out] none,
 **                 
 *
 ** \return RTE_E_OK, 
 * \comments 
 *
 */
#if (DSM_FEAT_RC_ETHPhyLoopBackTest_RequestRoutineResults == STD_ON)
FUNC(Std_ReturnType, RTE_CODE) Dsm_u_RC_ETHPhyLoopBackTest_RequestRoutineResults (Dcm_OpStatusType OpStatus, P2VAR(Dcm_RequestDataOut_DcmDspRoutine_0x0307_DcmDspRoutineRequestResOutSignal_0Type, AUTOMATIC, RTE_APPL_DATA) dataOut0, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_APPL_DATA) ErrorCode)
{
	  /* suppress compiler warnings about unused arguments */
	  (void)OpStatus;
	  (void)*ErrorCode;
#if((DSM_SYSTEM_TYPE == DSM_SYSTEM_MFC5J3_C673)|| \
									(DSM_SYSTEM_TYPE == DSM_SYSTEM_MFC5J3_C385)) 
									
	 Rte_Call_RP_Sdc_SendInterface_Eth_EthPhyLoopBackTestInfo_Read((void*)dataOut0,1);
	
#endif
	
	 return RTE_E_OK;

} /* FUNC(Std_ReturnType, RTE_CODE) Dsm_u_RC_ETHPhyLoopBackTest_RequestRoutineResults (Dcm_OpStatusType OpStatus, P2VAR(Dcm_RequestDataOut_DcmDspRoutine_0x0307_DcmDspRoutineRequestResOutSignal_0Type, AUTOMATIC, RTE_APPL_DATA) dataOut0, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_APPL_DATA) ErrorCode) */
#endif

/**
 * \functions Dsm_u_RC_ETHResetMACAddress_StartRoutine
 *
 * \brief Request to reset ethernet MAC address.(31 01 0308)
 *
 ** \param[in] none,
 *
 ** \param[out] none,
 **                 
 *
 ** \return RTE_E_OK, 
 * \comments 
 *
 */
#if (DSM_FEAT_RC_ETHResetMACAddress_StartRoutine == STD_ON)
FUNC(Std_ReturnType, RTE_CODE) Dsm_u_RC_ETHResetMACAddress_StartRoutine (Dcm_StartDataIn_DcmDspRoutine_0x0308_DcmDspStartRoutineInSignal_0Type dataIn0, Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_APPL_DATA) ErrorCode)
{
	/* suppress compiler warnings about unused arguments */
	Std_ReturnType u_Retval = RTE_E_OK;
	  (void)OpStatus;
#if((DSM_SYSTEM_TYPE == DSM_SYSTEM_MFC5J3_C673)|| \
									  (DSM_SYSTEM_TYPE == DSM_SYSTEM_MFC5J3_C385)) 
	  
	static uint8 u_RequestCounter = 0;
	static boolean b_CompleteSuccess;
	
	b_CompleteSuccess = FALSE;
		
	u_Retval = Rte_Call_RP_Sdc_SendInterface_Eth_EthResetMACAddress_StartRoutine(dataIn0);
	  
	if((uint8)E_OK == u_Retval)
	{
		b_CompleteSuccess = TRUE;
	}
	else
	{
		u_RequestCounter++;
		if(u_RequestCounter < 10u)
		{
			u_Retval = DCM_E_PENDING; 
		}
		else
		{
			u_RequestCounter = 0u;
			*ErrorCode = DCM_E_CONDITIONSNOTCORRECT;
			u_Retval = RTE_E_INVALID;
		}
	} 
		 
	if(TRUE == b_CompleteSuccess)
	{    
		*ErrorCode = E_OK;
		u_Retval = RTE_E_OK;
	}
	else
	{
		if ((uint8)DCM_E_PENDING == u_Retval)
		{
			*ErrorCode = DCM_E_REQUESTCORRECTLYRECEIVEDRESPONSEPENDING;
		}
		else
		{
			/*Do nothing.*/
		}
	}
#endif
		
	return u_Retval;
} /* FUNC(Std_ReturnType, RTE_CODE) Dsm_u_RC_ETHResetMACAddress_StartRoutine (Dcm_StartDataIn_DcmDspRoutine_0x0308_DcmDspStartRoutineInSignal_0Type dataIn0, Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_APPL_DATA) ErrorCode) */
#endif

/**
 * \functions Dsm_u_RC_ETHResetMACAddress_RequestRoutineResults
 *
 * \brief Request to get the results of reset ethernet MAC address.(31 03 0308)
 *
 ** \param[in] none,
 *
 ** \param[out] none,
 **                 
 *
 ** \return RTE_E_OK, 
 * \comments 
 *
 */
#if (DSM_FEAT_RC_ETHResetMACAddress_RequestRoutineResults == STD_ON)
FUNC(Std_ReturnType, RTE_CODE) Dsm_u_RC_ETHResetMACAddress_RequestRoutineResults (Dcm_OpStatusType OpStatus, P2VAR(Dcm_RequestDataOut_DcmDspRoutine_0x0308_DcmDspRoutineRequestResOutSignal_0Type, AUTOMATIC, RTE_APPL_DATA) dataOut0, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_APPL_DATA) ErrorCode)
{
	/* suppress compiler warnings about unused arguments */
	(void)OpStatus;
	(void)*ErrorCode;
#if((DSM_SYSTEM_TYPE == DSM_SYSTEM_MFC5J3_C673)|| \
									  (DSM_SYSTEM_TYPE == DSM_SYSTEM_MFC5J3_C385)) 
									  
	Rte_Call_RP_Sdc_SendInterface_Eth_EthResetMACAddressInfo_Read((void*)dataOut0,1);
	  
#endif
	  
	return RTE_E_OK;
} /* FUNC(Std_ReturnType, RTE_CODE) Dsm_u_RC_ETHResetMACAddress_RequestRoutineResults (Dcm_OpStatusType OpStatus, P2VAR(Dcm_RequestDataOut_DcmDspRoutine_0x0308_DcmDspRoutineRequestResOutSignal_0Type, AUTOMATIC, RTE_APPL_DATA) dataOut0, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_APPL_DATA) ErrorCode) */
#endif

/**
 * \functions Dsm_u_RC_ETHResetMACLayerStatistic_StartRoutine
 *
 * \brief Request to reset ethernet MAC layer statistic.(31 01 0309)
 *
 ** \param[in] none,
 *
 ** \param[out] none,
 **                 
 *
 ** \return RTE_E_OK, 
 * \comments 
 *
 */
#if (DSM_FEAT_RC_ETHResetMACLayerStatistic_StartRoutine == STD_ON)
FUNC(Std_ReturnType, RTE_CODE) Dsm_u_RC_ETHResetMACLayerStatistic_StartRoutine (Dcm_StartDataIn_DcmDspRoutine_0x0309_DcmDspStartRoutineInSignal_0Type dataIn0, Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_APPL_DATA) ErrorCode)
{
    /* suppress compiler warnings about unused arguments */
	Std_ReturnType u_Retval = RTE_E_OK;
	(void)OpStatus;
#if((DSM_SYSTEM_TYPE == DSM_SYSTEM_MFC5J3_C673)|| \
									(DSM_SYSTEM_TYPE == DSM_SYSTEM_MFC5J3_C385)) 
	
	static uint8 u_RequestCounter = 0;
	static boolean b_CompleteSuccess;
  
	b_CompleteSuccess = FALSE;
	  
	u_Retval = Rte_Call_RP_Sdc_SendInterface_Eth_EthResetMACLayerStatistic_StartRoutine(dataIn0);
	
	if((uint8)E_OK == u_Retval)
	{
		b_CompleteSuccess = TRUE;
	}
	else
	{
		u_RequestCounter++;
		if(u_RequestCounter < 10u)
		{
			u_Retval = DCM_E_PENDING; 
		}
		else
		{
			u_RequestCounter = 0u;
			*ErrorCode = DCM_E_CONDITIONSNOTCORRECT;
			u_Retval = RTE_E_INVALID;
		}
	} 
	   
	if(TRUE == b_CompleteSuccess)
	{    
		*ErrorCode = E_OK;
		u_Retval = RTE_E_OK;
	}
	else
	{
		if ((uint8)DCM_E_PENDING == u_Retval)
		{
			*ErrorCode = DCM_E_REQUESTCORRECTLYRECEIVEDRESPONSEPENDING;
		}
		else
		{
			/*Do nothing.*/
		}
	}
#endif
	  
	 return u_Retval;

} /* FUNC(Std_ReturnType, RTE_CODE) Dsm_u_RC_ETHResetMACLayerStatistic_StartRoutine (Dcm_StartDataIn_DcmDspRoutine_0x0309_DcmDspStartRoutineInSignal_0Type dataIn0, Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_APPL_DATA) ErrorCode) */
#endif

/**
 * \functions Dsm_u_RC_ETHResetMACLayerStatistic_RequestRoutineResults
 *
 * \brief Request to get the results of ethernet MAC layer statistic.(31 03 0309)
 *
 ** \param[in] none,
 *
 ** \param[out] none,
 **                 
 *
 ** \return RTE_E_OK, 
 * \comments 
 *
 */
#if (DSM_FEAT_RC_ETHResetMACLayerStatistic_RequestRoutineResults == STD_ON)
FUNC(Std_ReturnType, RTE_CODE) Dsm_u_RC_ETHResetMACLayerStatistic_RequestRoutineResults (Dcm_OpStatusType OpStatus, P2VAR(Dcm_RequestDataOut_DcmDspRoutine_0x0309_DcmDspRoutineRequestResOutSignal_0Type, AUTOMATIC, RTE_APPL_DATA) dataOut0, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_APPL_DATA) ErrorCode)
{
	/* suppress compiler warnings about unused arguments */
	(void)OpStatus;
	(void)*ErrorCode;
#if((DSM_SYSTEM_TYPE == DSM_SYSTEM_MFC5J3_C673)|| \
									(DSM_SYSTEM_TYPE == DSM_SYSTEM_MFC5J3_C385)) 
									
		Rte_Call_RP_Sdc_SendInterface_Eth_EthResetMACLayerStatisticInfo_Read((void*)dataOut0,1);
	
#endif
	
	return RTE_E_OK;

} /* FUNC(Std_ReturnType, RTE_CODE) Dsm_u_RC_ETHResetMACLayerStatistic_RequestRoutineResults (Dcm_OpStatusType OpStatus, P2VAR(Dcm_RequestDataOut_DcmDspRoutine_0x0309_DcmDspRoutineRequestResOutSignal_0Type, AUTOMATIC, RTE_APPL_DATA) dataOut0, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_APPL_DATA) ErrorCode) */
#endif

/**
 * \functions Dsm_u_RC_ETHCableLengthDiagnostic_StartRoutine
 *
 * \brief Request to enable ethernet ethernet cable length diagnostic.(31 01 030A)
 *
 ** \param[in] none,
 *
 ** \param[out] none,
 **                 
 *
 ** \return RTE_E_OK, 
 * \comments 
 *
 */
#if (DSM_FEAT_RC_ETHCableLengthDiagnostic_StartRoutine == STD_ON)
FUNC(Std_ReturnType, RTE_CODE) Dsm_u_RC_ETHCableLengthDiagnostic_StartRoutine (Dcm_StartDataIn_DcmDspRoutine_0x030A_DcmDspStartRoutineInSignal_0Type dataIn0, Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_APPL_DATA) ErrorCode)
{
    /* suppress compiler warnings about unused arguments */
	Std_ReturnType u_Retval = RTE_E_OK;
	(void)OpStatus;
#if((DSM_SYSTEM_TYPE == DSM_SYSTEM_MFC5J3_C673)|| \
								  (DSM_SYSTEM_TYPE == DSM_SYSTEM_MFC5J3_C385)) 
  
	static uint8 u_RequestCounter = 0;
	static boolean b_CompleteSuccess;

	b_CompleteSuccess = FALSE;
	
	u_Retval = Rte_Call_RP_Sdc_SendInterface_Eth_EthCableLengthDiagnostic_StartRoutine(dataIn0);
  
	if((uint8)E_OK == u_Retval)
	{
	    b_CompleteSuccess = TRUE;
	}
	else
	{
		u_RequestCounter++;
		if(u_RequestCounter < 10u)
		{
			u_Retval = DCM_E_PENDING; 
		}
		else
		{
			u_RequestCounter = 0u;
			*ErrorCode = DCM_E_CONDITIONSNOTCORRECT;
			u_Retval = RTE_E_INVALID;
		}
	} 
	 
	if(TRUE == b_CompleteSuccess)
	{    
		*ErrorCode = E_OK;
		u_Retval = RTE_E_OK;
	}
	else
	{
		if ((uint8)DCM_E_PENDING == u_Retval)
		{
			*ErrorCode = DCM_E_REQUESTCORRECTLYRECEIVEDRESPONSEPENDING;
		}
		else
		{
			/*Do nothing.*/
		}
	}
#endif
	
	 return u_Retval;
} /* FUNC(Std_ReturnType, RTE_CODE) Dsm_u_RC_ETHCableLengthDiagnostic_StartRoutine (Dcm_StartDataIn_DcmDspRoutine_0x030A_DcmDspStartRoutineInSignal_0Type dataIn0, Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_APPL_DATA) ErrorCode) */
#endif

/**
 * \functions Dsm_u_RC_ETHCableLengthDiagnostic_RequestRoutineResults
 *
 * \brief Request to get the results of ethernet ethernet cable length diagnostic.(31 03 030A)
 *
 ** \param[in] none,
 *
 ** \param[out] none,
 **                 
 *
 ** \return RTE_E_OK, 
 * \comments 
 *
 */
#if (DSM_FEAT_RC_ETHCableLengthDiagnostic_RequestRoutineResults == STD_ON)
FUNC(Std_ReturnType, RTE_CODE) Dsm_u_RC_ETHCableLengthDiagnostic_RequestRoutineResults (Dcm_OpStatusType OpStatus, P2VAR(Dcm_RequestDataOut_DcmDspRoutine_0x030A_DcmDspRoutineRequestResOutSignal_0Type, AUTOMATIC, RTE_APPL_DATA) dataOut0, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_APPL_DATA) ErrorCode)
{
	/* suppress compiler warnings about unused arguments */
	(void)OpStatus;
	(void)*ErrorCode;
#if((DSM_SYSTEM_TYPE == DSM_SYSTEM_MFC5J3_C673)|| \
								  (DSM_SYSTEM_TYPE == DSM_SYSTEM_MFC5J3_C385)) 
								  
	 Rte_Call_RP_Sdc_SendInterface_Eth_EthCableLengthDiagnosticInfo_Read((void*)dataOut0,1);
  
#endif
  
	  return RTE_E_OK;
} /* FUNC(Std_ReturnType, RTE_CODE) Dsm_u_RC_ETHCableLengthDiagnostic_RequestRoutineResults (Dcm_OpStatusType OpStatus, P2VAR(Dcm_RequestDataOut_DcmDspRoutine_0x030A_DcmDspRoutineRequestResOutSignal_0Type, AUTOMATIC, RTE_APPL_DATA) dataOut0, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_APPL_DATA) ErrorCode) */
#endif

/**
 * \functions Dsm_u_RC_ClearNvM_StartRoutine
 *
 * \brief Request to clear partial NvM.(31 01 F012)
 *
 ** \param[in] dataIn0: indicate the clear record number (01:clear NvM Data of Vdy.)
 *
 ** \param[out] none,
 **                 
 *
 ** \return RTE_E_OK, 
 * \comments 
 *
 */
#if (DSM_FEAT_RC_ClearNvM_StartRoutine == STD_ON)
FUNC(Std_ReturnType, RTE_CODE) Dsm_u_RC_ClearNvM_StartRoutine (Dcm_StartDataIn_DcmDspRoutine_0xF012_DcmDspStartRoutineInSignal_0Type dataIn0, Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_APPL_DATA) ErrorCode)
{
  /* suppress compiler warnings about unused arguments */
  Std_ReturnType NvmRet = E_NOT_OK;
  Std_ReturnType ret = E_NOT_OK;
  
  switch(dataIn0)
  {
  case 0x01:
  	VdyNvm_Clear = 0x01u;
	
  	NvmRet = Rte_Call_RP_Nvm_VdyBlockOperation_WriteBlock(&ROM_BLOCK_VDY_Data);
  
  	if(NvmRet == E_NOT_OK)
  	{
  		ret = E_NOT_OK;
  		*ErrorCode = DCM_E_CONDITIONSNOTCORRECT;
  	}
  	else
  	{
  		ret = E_OK;
  	}
  
  	break;
  default:
  	ErrorCode = DCM_E_REQUESTOUTOFRANGE;
  	ret = E_NOT_OK;
  
  	break;
  }
  
  return ret;
} /* FUNC(Std_ReturnType, RTE_CODE) Dsm_u_RC_ClearNvM_StartRoutine (Dcm_StartDataIn_DcmDspRoutine_0xF012_DcmDspStartRoutineInSignal_0Type dataIn0, Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_APPL_DATA) ErrorCode) */
#endif

/**
 * \functions Dsm_u_RC_ClearNvM_RequestRoutineResults
 *
 * \brief Request to clear partial NvM.(31 03 F012)
 *
 ** \param[in] dataIn0: indicate the clear record number (01:clear NvM Data of Vdy.)
 *
 ** \param[out] dataOut0: indicate clear NvM data of Vdy 
 **                 
 ** \param[out] dataOut1: 00:fail  01:success
 *
 ** \return RTE_E_OK, 
 * \comments 
 *
 */
#if (DSM_FEAT_RC_ClearNvM_RequestRoutineResults == STD_ON)
FUNC(Std_ReturnType, RTE_CODE) Dsm_u_RC_ClearNvM_RequestRoutineResults (Dcm_RequestDataIn_DcmDspRoutine_0xF012_DcmDspRoutineRequestResInSignal_0Type dataIn0, Dcm_OpStatusType OpStatus, P2VAR(Dcm_RequestDataOut_DcmDspRoutine_0xF012_DcmDspRoutineRequestResOutSignal_0Type, AUTOMATIC, RTE_APPL_DATA) dataOut0, P2VAR(Dcm_RequestDataOut_DcmDspRoutine_0xF012_DcmDspRoutineRequestResOutSignal_1Type, AUTOMATIC, RTE_APPL_DATA) dataOut1, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_APPL_DATA) ErrorCode)
{
  Std_ReturnType ret = E_NOT_OK;
  NvM_ASR40_RequestResultType VdyInitRst = E_NOT_OK;
  
  switch(dataIn0)
  {
  case 0x01:
  	(void)Rte_Call_RP_Nvm_VdyBlockOperation_GetErrorStatus(&VdyInitRst);
  
  	if(VdyInitRst == NVM_REQ_PENDING)
  	{
  		return DCM_E_PENDING;
  	}
  	else if(VdyInitRst == NVM_REQ_OK)
  	{
  		*dataOut0 = 0x01u;
  		*dataOut1 = 0x01u;
  		ret = E_OK;
  	}
  	else
  	{
  		*dataOut0 = 0x01u;
  		*dataOut1 = 0x00u;
  		ret = E_OK;
  	}
  
  	break;
  
  default:
  	ErrorCode = DCM_E_REQUESTOUTOFRANGE;
  	ret = E_NOT_OK;
  
  	break;
  }
  
  return ret;
} /* FUNC(Std_ReturnType, RTE_CODE) Dsm_u_RC_ClearNvM_RequestRoutineResults (Dcm_RequestDataIn_DcmDspRoutine_0xF012_DcmDspRoutineRequestResInSignal_0Type dataIn0, Dcm_OpStatusType OpStatus, P2VAR(Dcm_RequestDataOut_DcmDspRoutine_0xF012_DcmDspRoutineRequestResOutSignal_0Type, AUTOMATIC, RTE_APPL_DATA) dataOut0, P2VAR(Dcm_RequestDataOut_DcmDspRoutine_0xF012_DcmDspRoutineRequestResOutSignal_1Type, AUTOMATIC, RTE_APPL_DATA) dataOut1, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_APPL_DATA) ErrorCode) */
#endif

/**
 * \functions Dsm_u_RC_SaveNvM_StartRoutine
 *
 * \brief Request to save all NvM data.(31 01 F013)
 *
 ** \param[in] none,
 *
 ** \param[out] none,
 **                 
 *
 ** \return RTE_E_OK, 
 * \comments 
 *
 */
#if (DSM_FEAT_RC_SaveNvM_StartRoutine  == STD_ON)
FUNC(Std_ReturnType, RTE_CODE) Dsm_u_RC_SaveNvM_StartRoutine (Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_APPL_DATA) ErrorCode)
{
  /* suppress compiler warnings about unused arguments */
  (void)OpStatus;
  (void)*ErrorCode;

  NvM_WriteAll();
  
  return RTE_E_OK;
} /* FUNC(Std_ReturnType, RTE_CODE) Dsm_u_RC_SaveNvM_StartRoutine (Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_APPL_DATA) ErrorCode) */
#endif

/**
 * \functions Dsm_u_RC_SaveNvM_RequestRoutineResults
 *
 * \brief Request to save all NvM.(31 03 F013)
 *
 ** \param[in] none,
 *
 ** \param[out] dataOut0: indicate clear NvM data of Vdy 
 **                 
 ** \param[out] dataOut1: 00:fail  01:success
 *
 ** \return RTE_E_OK, 
 * \comments 
 *
 */
 #if (DSM_FEAT_RC_SaveNvM_RequestRoutineResults  == STD_ON)
FUNC(Std_ReturnType, RTE_CODE) Dsm_u_RC_SaveNvM_RequestRoutineResults (Dcm_OpStatusType OpStatus, P2VAR(Dcm_RequestDataOut_DcmDspRoutine_0xF013_DcmDspRoutineRequestResOutSignal_0Type, AUTOMATIC, RTE_APPL_DATA) dataOut0, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_APPL_DATA) ErrorCode)
{
  /* suppress compiler warnings about unused arguments */
  Std_ReturnType Result;
  NvM_RequestResultType JobResult = NVM_REQ_PENDING;
  
  (void) NvM_GetErrorStatus( NVM_BLOCK_MULTI, &JobResult);
  
  switch(JobResult)
  {
  case NVM_REQ_PENDING:
  	Result = DCM_E_PENDING;
  	
  	break;
  case NVM_REQ_OK:
  	Result = E_OK;
  	*dataOut0 = 0x01;
  
  	break;
  
  default:
  	Result = E_OK;
  	*dataOut0 = 0x00;
  	
  	break;
  }
  
  return Result;
} /* FUNC(Std_ReturnType, RTE_CODE) Dsm_u_RC_SaveNvM_RequestRoutineResults (Dcm_OpStatusType OpStatus, P2VAR(Dcm_RequestDataOut_DcmDspRoutine_0xF013_DcmDspRoutineRequestResOutSignal_0Type, AUTOMATIC, RTE_APPL_DATA) dataOut0, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_APPL_DATA) ErrorCode) */
#endif




#if(DSM_FEAT_MEMMAP_EB_IS_USED == STD_ON)
    #define Dsm_STOP_SEC_CODE
    #include <Dsm_MemMap.h> /* PRQA S 5087 */
#endif



/*==================[internal function definitions]=========================*/






