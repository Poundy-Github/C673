/**
 * \file   Dsm_WriteDataByIdentifier.c
 *
 * \brief  UDS WriteDataByIdentifier service(2E)
 *
 * \version refer the Rte_Dsm.h.
 * 
 * \copyright  2021 - 2022 Conti Smart Core
 *
 */
/*==================[inclusions]============================================*/
#include <Rte_Dsm.h>
#include "Dsm_Cfg.h"
#include "Os_api.h"
#include "Dsm_Main.h"
#include "VerInfo.h"
#include "Cdm.h"
#include <Xcp.h>  
#include "Qsm_Lcfg.h"/* Module public API */
#include "SystemData_CustomerCoding.h"
#include "SystemData_VehicleVariant.h"

/*==================[external constants definition]=========================*/





/*==================[internal constants definition]=========================*/

/*==================[external data definition]==============================*/



/*==================[internal data definition]==============================*/


/*==================[internal function declarations]========================*/


/*==================[external function definitions]=========================*/
#if(DSM_FEAT_MEMMAP_EB_IS_USED == STD_ON)
    #define Dsm_START_SEC_CODE
    #include <Dsm_MemMap.h> /* PRQA S 5087 */
#endif

/**
 * \functions Dsm_u_WDBI_PartNumberDataIdentifier_Write
 *
 * \brief Write part number data identifier from specific DF static Address.(F187)
 *
 ** \param[in] none,
 *
 ** \param[out] Data, Pointer to Data buffer (21 bytes).
 **                  ASCII formatted
 *
 ** \return RTE_E_OK, 
 * \comments  base Address:0xAF07D000 startAddress: 0xAF07D048  Total Length: 32byte
 *
 */
#if (DSM_FEAT_WDBI_PartNumberDataIdentifier == STD_ON)
FUNC(Std_ReturnType, RTE_CODE) Dsm_u_WDBI_PartNumberDataIdentifier_Write (P2CONST(uint8, AUTOMATIC, RTE_APPL_DATA) Data, Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_APPL_DATA) ErrorCode)

{
     /* suppress compiler warnings about unused arguments */
    Std_ReturnType u_Retval = RTE_E_OK;
	
#if((DSM_SYSTEM_TYPE == DSM_SYSTEM_MFC5J3_C673)|| \
				  (DSM_SYSTEM_TYPE == DSM_SYSTEM_MFC5J3_C385))	

	static boolean b_WriteFlagSuccess;
	static uint8 ui8_QsmReqStatus = QSM_REQRESULT_NOT_OK;
	
    if((uint8)DCM_INITIAL == OpStatus)
    {
        b_WriteFlagSuccess = FALSE;	

		Rte_Enter_DSM_EXCLUSIVEAREA();
		
		/* PRQA S 0314 2 */ /* Pointer to void, no problem */
		(void)TS_MemCpy((void*)s_QSBlock_PartNumberSector.F187, (const void*)Data, PARTNUMBER_LEN);

		Rte_Exit_DSM_EXCLUSIVEAREA();
		
	    (void)Rte_Call_RP_Qsm_BlockPartNumber_SectorOp_Qsm_WriteBlock(&s_QSBlock_PartNumberSector);

		ui8_QsmReqStatus = Rte_Call_RP_Qsm_BlockPartNumber_SectorOp_Qsm_GetErrorStatues();
		
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
		ui8_QsmReqStatus = Rte_Call_RP_Qsm_BlockPartNumber_SectorOp_Qsm_GetErrorStatues();
		  
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
            /*Do nothing*/
        }
	}
#endif

    return u_Retval;
} /* FUNC(Std_ReturnType, RTE_CODE) Dsm_u_WDBI_PartNumberDataIdentifier_Write (P2CONST(uint8, AUTOMATIC, RTE_APPL_DATA) Data, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_APPL_DATA) ErrorCode) */
#endif

/**
 * \functions Dsm_u_WDBI_ECUHardwareVersionNumberDataIdentifier_Write
 *
 * \brief Write ECU hardware version number data identifier from specific DF static Address.(F089)
 *
 ** \param[in] none,
 *
 ** \param[out] Data, Pointer to Data buffer (8 bytes).
 **                  ASCII formatted
 *
 ** \return RTE_E_OK, 
 * \comments  base Address:0xAF07D000 startAddress: 0xAF07D068  Total Length: 32byte
 *
 */
#if (DSM_FEAT_WDBI_ECUHardwareVersionNumberDataIdentifier == STD_ON)
FUNC(Std_ReturnType, RTE_CODE) Dsm_u_WDBI_ECUHardwareVersionNumberDataIdentifier_Write (P2CONST(uint8, AUTOMATIC, RTE_APPL_DATA) Data, Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_APPL_DATA) ErrorCode)
{
    /* suppress compiler warnings about unused arguments */
    Std_ReturnType u_Retval = RTE_E_OK;
	
#if((DSM_SYSTEM_TYPE == DSM_SYSTEM_MFC5J3_C673)|| \
				  (DSM_SYSTEM_TYPE == DSM_SYSTEM_MFC5J3_C385))	
				  
	static boolean b_WriteFlagSuccess;
	static uint8 ui8_QsmReqStatus = QSM_REQRESULT_NOT_OK;
	
    if((uint8)DCM_INITIAL == OpStatus)
    {
        b_WriteFlagSuccess = FALSE;

		Rte_Enter_DSM_EXCLUSIVEAREA();
		/* PRQA S 0314 2 */ /* Pointer to void, no problem */
		(void)TS_MemCpy((void*)s_QSBlock_PartNumberSector.F089, (const void*)Data, ECUHWVERSNUMBER_LEN);

		Rte_Exit_DSM_EXCLUSIVEAREA();	

		(void)Rte_Call_RP_Qsm_BlockPartNumber_SectorOp_Qsm_WriteBlock(&s_QSBlock_PartNumberSector);

		ui8_QsmReqStatus = Rte_Call_RP_Qsm_BlockPartNumber_SectorOp_Qsm_GetErrorStatues();
		
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
	    ui8_QsmReqStatus = Rte_Call_RP_Qsm_BlockPartNumber_SectorOp_Qsm_GetErrorStatues();
		  
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
            /*Do nothing*/
        }
	}
#endif

    return u_Retval;
} /* FUNC(Std_ReturnType, RTE_CODE) Dsm_u_WDBI_ECUHardwareVersionNumberDataIdentifier_Write (P2CONST(uint8, AUTOMATIC, RTE_APPL_DATA) Data, Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_APPL_DATA) ErrorCode) */
#endif

/**
 * \functions Dsm_u_WDBI_SystemSupplierIdentifier_Write
 *
 * \brief Write System Supplier identifier from specific DF static Address.(F18A)
 *
 ** \param[in] none,
 *
 ** \param[out] Data, Pointer to Data buffer (7 bytes).
 **                  ASCII formatted
 *
 ** \return RTE_E_OK, 
 * \comments  base Address:0xAF07D000 startAddress: 0xAF07D028  Total Length: 32byte
 *
 */
#if (DSM_FEAT_WDBI_SystemSupplierIdentifier == STD_ON)
FUNC(Std_ReturnType, RTE_CODE) Dsm_u_WDBI_SystemSupplierIdentifier_Write (P2CONST(uint8, AUTOMATIC, RTE_APPL_DATA) Data, Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_APPL_DATA) ErrorCode)
{
	  /* suppress compiler warnings about unused arguments */
	  Std_ReturnType u_Retval = RTE_E_OK;
	  
#if((DSM_SYSTEM_TYPE == DSM_SYSTEM_MFC5J3_C673)|| \
					(DSM_SYSTEM_TYPE == DSM_SYSTEM_MFC5J3_C385))  
	  static boolean b_WriteFlagSuccess;
	  static uint8 ui8_QsmReqStatus = QSM_REQRESULT_NOT_OK;
  
	  if((uint8)DCM_INITIAL == OpStatus)
	  {
		  b_WriteFlagSuccess = FALSE;

		  Rte_Enter_DSM_EXCLUSIVEAREA();
		  /* PRQA S 0314 2 */ /* Pointer to void, no problem */
		  (void)TS_MemCpy((void*)s_QSBlock_PartNumberSector.F18A, (const void*)Data, SYSSUPPLIER_LEN);

		  Rte_Exit_DSM_EXCLUSIVEAREA();
		  
	      (void)Rte_Call_RP_Qsm_BlockPartNumber_SectorOp_Qsm_WriteBlock(&s_QSBlock_PartNumberSector);

		  ui8_QsmReqStatus = Rte_Call_RP_Qsm_BlockPartNumber_SectorOp_Qsm_GetErrorStatues();
		
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
	      ui8_QsmReqStatus = Rte_Call_RP_Qsm_BlockPartNumber_SectorOp_Qsm_GetErrorStatues();
		  
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
			  /*Do nothing*/
		  }
	  }
#endif
  
	  return u_Retval;

} /* FUNC(Std_ReturnType, RTE_CODE) Dsm_u_WDBI_SystemSupplierIdentifier_Write (P2CONST(uint8, AUTOMATIC, RTE_APPL_DATA) Data, Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_APPL_DATA) ErrorCode) */
#endif

/**
 * \functions Dsm_u_WDBI_ECUSerialNumberDataIdentifier_Write
 *
 * \brief Write ECU serial number data identifier from Data flash.(F18C)
 *
 ** \param[in] none,
 *
 ** \param[out] Data, Pointer to Data buffer (13 bytes).
 **                  The DID format as below:
 **         byte0-3: ProductSerialNumber /unsigned 
 **         byte4-9: ProductionLineNumber /ASCII 
 **         byte10: Years /unsigned
 **         byte11: Months /unisgned
 **         byte12: Days /unsigned
 ** \return RTE_E_OK, 
 * \comments  This value shall be used to reference the ECU (server) serial number.
Record data content and format shall be server specific.
 *
 */
#if (DSM_FEAT_WDBI_ECUSerialNumberDataIdentifier == STD_ON)
FUNC(Std_ReturnType, RTE_CODE) Dsm_u_WDBI_ECUSerialNumberDataIdentifier_Write (P2CONST(uint8, AUTOMATIC, RTE_APPL_DATA) Data, Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_APPL_DATA) ErrorCode)
{
    /* suppress compiler warnings about unused arguments */
    Std_ReturnType u_RetVal = RTE_E_OK;

#if((DSM_SYSTEM_TYPE == DSM_SYSTEM_MFC5J3_C673)|| \
				  (DSM_SYSTEM_TYPE == DSM_SYSTEM_MFC5J3_C385))	
				  
	Std_ReturnType ui8_RetVal_Write = RTE_E_INVALID;
	Std_ReturnType ui8_RetVal_ErrStat = RTE_E_INVALID;
	NvM_RequestResultType ui8_WriteStatus = NVM_REQ_NOT_OK; 
	boolean b_NvmOperationPending = FALSE;
    static boolean b_WriteFlagSuccess;
	
    if ((uint8) DCM_INITIAL == OpStatus) 
	{
	    b_WriteFlagSuccess = FALSE;
				
		if((Data[11] >= 0x01) && (Data[11] <= 0x0C) && (Data[12] >= 0x01) && (Data[12] <= 0x1F))
		{
		    /*Service for setting the lock status of a permanent RAM block of an NVRAM block.*/
			(void)Rte_Call_RP_Nvm_SerialNumberDataId_SetRamBlockStatus(FALSE);
			/* PRQA S 0314 ++ */ /* P2Obj to P2void conversion is safe */
			Rte_Enter_DSM_EXCLUSIVEAREA();
			
		    (void)TS_MemCpy((void*)RAM_NVM_BLOCK_SerialNumberDataId, (const void*)Data, ECUSERIALNUMBERDATAID_LEN);

			Rte_Exit_DSM_EXCLUSIVEAREA();
			
			ui8_RetVal_Write = Rte_Call_RP_Nvm_SerialNumberDataId_WriteBlock((void*) &RAM_NVM_BLOCK_SerialNumberDataId);
		  
		    if ((uint8) E_OK == ui8_RetVal_Write) 
		    {
				ui8_RetVal_ErrStat = Rte_Call_RP_Nvm_SerialNumberDataId_GetErrorStatus(&ui8_WriteStatus);
  
			    if ((uint8) E_OK == ui8_RetVal_ErrStat)
			    {
				    if ((uint8) NVM_REQ_OK == ui8_WriteStatus) 
				    {
					    b_WriteFlagSuccess = TRUE;
				    }
				    else if ((uint8) NVM_REQ_PENDING == ui8_WriteStatus)
				    {
					    u_RetVal = DCM_E_PENDING;
				    } 
				    else 
				    {
					    u_RetVal = RTE_E_INVALID;
					    *ErrorCode = DCM_E_GENERALPROGRAMMINGFAILURE;
				    }
			    } 
		 	    else 
			    {
				    u_RetVal = RTE_E_INVALID;
				    *ErrorCode = DCM_E_GENERALPROGRAMMINGFAILURE;
			    }
	        }
		    else 
		    {
		        u_RetVal = RTE_E_INVALID;
			    *ErrorCode = DCM_E_GENERALPROGRAMMINGFAILURE;
		    }
		}
		else
		{
		    /*The scope of months shall in 1 to 12 and the scope of days shall in 1 to 31,or else retunr NRC 0x31.*/
		    u_RetVal = RTE_E_INVALID;
		    *ErrorCode = DCM_E_REQUESTOUTOFRANGE;
		}

	}
	else if ((uint8) DCM_PENDING == OpStatus) 
	{
		ui8_RetVal_ErrStat = Rte_Call_RP_Nvm_SerialNumberDataId_GetErrorStatus(&ui8_WriteStatus);
  
		if ((uint8) E_OK == ui8_RetVal_ErrStat)
		{
		    if ((uint8) NVM_REQ_OK == ui8_WriteStatus) 
			{
			    b_WriteFlagSuccess = TRUE;
			} 
			else if ((uint8) NVM_REQ_PENDING == ui8_WriteStatus) 
			{
				u_RetVal = DCM_E_PENDING;
			} 
			else
			{
				u_RetVal = RTE_E_INVALID;
				*ErrorCode = DCM_E_GENERALPROGRAMMINGFAILURE;
			}
	    } 
		else 
		{
		    u_RetVal = RTE_E_INVALID;
		    *ErrorCode = DCM_E_GENERALPROGRAMMINGFAILURE;
		}
	}
	else if ((uint8) DCM_CANCEL == OpStatus) 
	{
		(void)Rte_Call_RP_Nvm_SerialNumberDataId_GetErrorStatus(&ui8_WriteStatus);
  
		if ((uint8) NVM_REQ_PENDING == ui8_WriteStatus) 
		{
		    ui8_RetVal_ErrStat = NvM_CancelJobs(NvMConf_NvMBlockDescriptor_NVM_BLOCK_SerialNumberDataId);
			  
			b_NvmOperationPending = TRUE;
  
			if ((uint8) E_OK == ui8_RetVal_ErrStat) 
			{
			    *ErrorCode = E_OK;
				u_RetVal = E_OK;
			} 
			else 
			{
				u_RetVal = RTE_E_INVALID;
				*ErrorCode = DCM_E_GENERALPROGRAMMINGFAILURE;
			}
	    } 
		else 
		{
		    *ErrorCode = E_OK;
			u_RetVal = E_OK;
		}
  
		b_WriteFlagSuccess = FALSE;
	} 
	else 
	{
		*ErrorCode = DCM_E_CONDITIONSNOTCORRECT;
		u_RetVal = RTE_E_INVALID;
	}
  
	if (TRUE == b_WriteFlagSuccess) 
	{
	    (void)Rte_Call_RP_Nvm_SerialNumberDataId_SetRamBlockStatus(TRUE);

		*ErrorCode = E_OK;
		u_RetVal = E_OK;
	}
	else 
	{
		if ((uint8) DCM_E_PENDING == u_RetVal)
		{
			*ErrorCode = DCM_E_REQUESTCORRECTLYRECEIVEDRESPONSEPENDING;
		} 
		else 
		{
			if (FALSE == b_NvmOperationPending) 
			{
			    (void)Rte_Call_RP_Nvm_SerialNumberDataId_SetRamBlockStatus(TRUE);
			}
		}
	}
#endif

	return u_RetVal;

} /* FUNC(Std_ReturnType, RTE_CODE) Dsm_u_WDBI_ECUSerialNumberDataIdentifier_Write (P2CONST(uint8, AUTOMATIC, RTE_APPL_DATA) Data, Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_APPL_DATA) ErrorCode) */
#endif

/**
 * \functions Dsm_u_WDBI_VINDataIdentifier_Write
 *
 * \brief Write VIN data identifier from Data flash.(F190)
 *
 ** \param[in] none,
 *
 ** \param[out] Data, Pointer to Data buffer (17 bytes).
 ** \return RTE_E_OK, 
 * \comments  This value shall be used to reference the VIN number. Record data
content and format shall be specified by the vehicle manufacturer.
 *
 */
#if (DSM_FEAT_WDBI_VINDataIdentifier == STD_ON)
FUNC(Std_ReturnType, RTE_CODE) Dsm_u_WDBI_VINDataIdentifier_Write (P2CONST(uint8, AUTOMATIC, RTE_APPL_DATA) Data, Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_APPL_DATA) ErrorCode)
{
	 /* suppress compiler warnings about unused arguments */
	  Std_ReturnType u_RetVal = RTE_E_OK;
  
#if((DSM_SYSTEM_TYPE == DSM_SYSTEM_MFC5J3_C673)|| \
					(DSM_SYSTEM_TYPE == DSM_SYSTEM_MFC5J3_C385))  
					
	  Std_ReturnType ui8_RetVal_Write = RTE_E_INVALID;
	  Std_ReturnType ui8_RetVal_ErrStat = RTE_E_INVALID;
	  NvM_RequestResultType ui8_WriteStatus = NVM_REQ_NOT_OK;	
	  boolean b_NvmOperationPending = FALSE;
	  static boolean b_WriteFlagSuccess;
  	  
	  if ((uint8) DCM_INITIAL == OpStatus) 
	  {
		  b_WriteFlagSuccess = FALSE;
		  
		  /*Service for setting the lock status of a permanent RAM block of an NVRAM block.*/
		  (void)Rte_Call_RP_Nvm_VINDataIdentifier_SetRamBlockStatus(FALSE);
		  
		  /* PRQA S 0314 ++ */ /* P2Obj to P2void conversion is safe */
		  Rte_Enter_DSM_EXCLUSIVEAREA();
		  
		  (void)TS_MemCpy((void*)RAM_NVM_BLOCK_VINDataIdentifier, (const void*)Data, VINDATAID_LEN);

		  Rte_Exit_DSM_EXCLUSIVEAREA();
		  
		  ui8_RetVal_Write = Rte_Call_RP_Nvm_VINDataIdentifier_WriteBlock((void*) &RAM_NVM_BLOCK_VINDataIdentifier);
		  
		  if ((uint8) E_OK == ui8_RetVal_Write) 
		  {
			  ui8_RetVal_ErrStat = Rte_Call_RP_Nvm_VINDataIdentifier_GetErrorStatus(&ui8_WriteStatus);
	
			  if ((uint8) E_OK == ui8_RetVal_ErrStat)
			  {
				  if ((uint8) NVM_REQ_OK == ui8_WriteStatus) 
				  {
						b_WriteFlagSuccess = TRUE;
				  }
				  else if ((uint8) NVM_REQ_PENDING == ui8_WriteStatus)
				  {
						u_RetVal = DCM_E_PENDING;
				  } 
				  else 
				  {
					   u_RetVal = RTE_E_INVALID;
					   *ErrorCode = DCM_E_GENERALPROGRAMMINGFAILURE;
				  }
			  } 
			  else 
			  {
				   u_RetVal = RTE_E_INVALID;
				   *ErrorCode = DCM_E_GENERALPROGRAMMINGFAILURE;
			  }
		  }
		  else 
		  {
			  u_RetVal = RTE_E_INVALID;
			  *ErrorCode = DCM_E_GENERALPROGRAMMINGFAILURE;
		  }
	  }
	  else if ((uint8) DCM_PENDING == OpStatus) 
	  {
	      ui8_RetVal_ErrStat = Rte_Call_RP_Nvm_VINDataIdentifier_GetErrorStatus(&ui8_WriteStatus);
		   
		  if ((uint8) E_OK == ui8_RetVal_ErrStat)
		  {
			  if ((uint8) NVM_REQ_OK == ui8_WriteStatus) 
			  {
				  b_WriteFlagSuccess = TRUE;
			  } 
			  else if ((uint8) NVM_REQ_PENDING == ui8_WriteStatus) 
			  {
				  u_RetVal = DCM_E_PENDING;
			  } 
			  else
			  {
				  u_RetVal = RTE_E_INVALID;
				  *ErrorCode = DCM_E_GENERALPROGRAMMINGFAILURE;
			  }
		  } 
		  else 
		  {
			  u_RetVal = RTE_E_INVALID;
			  *ErrorCode = DCM_E_GENERALPROGRAMMINGFAILURE;
		  }
	  }
	  else if ((uint8) DCM_CANCEL == OpStatus) 
	  {
		  (void)Rte_Call_RP_Nvm_VINDataIdentifier_GetErrorStatus(&ui8_WriteStatus);
	
		  if ((uint8) NVM_REQ_PENDING == ui8_WriteStatus) 
		  {
			  ui8_RetVal_ErrStat = NvM_CancelJobs(NvMConf_NvMBlockDescriptor_NVM_BLOCK_VINDataIdentifier);
				
			  b_NvmOperationPending = TRUE;
	
			  if ((uint8) E_OK == ui8_RetVal_ErrStat) 
			  {
				  *ErrorCode = E_OK;
				  u_RetVal = E_OK;
			  } 
			  else 
			  {
				  u_RetVal = RTE_E_INVALID;
				  *ErrorCode = DCM_E_GENERALPROGRAMMINGFAILURE;
			  }
		  } 
		  else 
		  {
			  *ErrorCode = E_OK;
			  u_RetVal = E_OK;
		  }
	
		  b_WriteFlagSuccess = FALSE;
	  } 
	  else 
	  {
		  *ErrorCode = DCM_E_CONDITIONSNOTCORRECT;
		  u_RetVal = RTE_E_INVALID;
	  }
	
	  if (TRUE == b_WriteFlagSuccess) 
	  {
		  (void)Rte_Call_RP_Nvm_VINDataIdentifier_SetRamBlockStatus(TRUE);
  
		  *ErrorCode = E_OK;
		  u_RetVal = E_OK;
	  }
	  else 
	  {
		  if ((uint8) DCM_E_PENDING == u_RetVal)
		  {
			  *ErrorCode = DCM_E_REQUESTCORRECTLYRECEIVEDRESPONSEPENDING;
		  } 
		  else 
		  {
			  if (FALSE == b_NvmOperationPending) 
			  {
				  (void)Rte_Call_RP_Nvm_VINDataIdentifier_SetRamBlockStatus(TRUE);
			  }
		  }
	  }
#endif
  
	  return u_RetVal;

} /* FUNC(Std_ReturnType, RTE_CODE) Dsm_u_WDBI_VINDataIdentifier_Write (P2CONST(uint8, AUTOMATIC, RTE_APPL_DATA) Data, Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_APPL_DATA) ErrorCode) */
#endif

/**
 * \functions Dsm_u_WDBI_VehicleType_Write
 *
 * \brief Write vehicle type from Data flash.(F1F0)
 *
 ** \param[in] none,
 *
 ** \param[out] Data, Pointer to Data buffer (1 bytes).
 ** \return RTE_E_OK, 
 * \comments  
 *
 */
#if (DSM_FEAT_WDBI_VehicleType == STD_ON)
FUNC(Std_ReturnType, RTE_CODE) Dsm_u_WDBI_VehicleType_Write (P2CONST(uint8, AUTOMATIC, RTE_APPL_DATA) Data, Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_APPL_DATA) ErrorCode)
{
    /* suppress compiler warnings about unused arguments */
	Std_ReturnType u_RetVal = RTE_E_OK;
	
#if((DSM_SYSTEM_TYPE == DSM_SYSTEM_MFC5J3_C673)|| \
					  (DSM_SYSTEM_TYPE == DSM_SYSTEM_MFC5J3_C385))	
					  
	Std_ReturnType ui8_RetVal_Write = RTE_E_INVALID;
	Std_ReturnType ui8_RetVal_ErrStat = RTE_E_INVALID;
	NvM_RequestResultType ui8_WriteStatus = NVM_REQ_NOT_OK;	  
	boolean b_NvmOperationPending = FALSE;
	static boolean b_WriteFlagSuccess;
		
	if ((uint8) DCM_INITIAL == OpStatus) 
	{
	    b_WriteFlagSuccess = FALSE;	

		if((0x01u == Data[0]) || (0x02u == Data[0]) || (0x03u == Data[0])  || (0x04u == Data[0]))
		{
		    /*Service for setting the lock status of a permanent RAM block of an NVRAM block.*/
		    (void)Rte_Call_RP_Nvm_Vehicletype_SetRamBlockStatus(FALSE);	
		    /* PRQA S 0314 ++ */ /* P2Obj to P2void conversion is safe */
		    if(0x01u == Data[0])
			{
                SET_SYS_VEHVARIANT(SYS_C673_EVE);
			}
			else if(0x02u == Data[0])
			{
                SET_SYS_VEHVARIANT(SYS_C673_PERFORMANCE);
			}
			else if(0x03u == Data[0])
			{
                SET_SYS_VEHVARIANT(SYS_C673_LBL);
			}
			else if(0x04u == Data[0])
			{
                SET_SYS_VEHVARIANT(SYS_C673_4WD);
			}
			else{/*Do nothing.*/}

		    ui8_RetVal_Write = Rte_Call_RP_Nvm_Vehicletype_WriteBlock((void*) &RAM_NVM_BLOCK_Vehicletype);
			  
		    if ((uint8) E_OK == ui8_RetVal_Write) 
		    {
			    ui8_RetVal_ErrStat = Rte_Call_RP_Nvm_Vehicletype_GetErrorStatus(&ui8_WriteStatus);
	  
			    if ((uint8) E_OK == ui8_RetVal_ErrStat)
			    {
				    if ((uint8) NVM_REQ_OK == ui8_WriteStatus) 
				    {
					    b_WriteFlagSuccess = TRUE;
				    }
				    else if ((uint8) NVM_REQ_PENDING == ui8_WriteStatus)
				    {
					    u_RetVal = DCM_E_PENDING;
				    } 
				    else 
				    {
					    u_RetVal = RTE_E_INVALID;
					    *ErrorCode = DCM_E_GENERALPROGRAMMINGFAILURE;
				    } 
			    } 
			    else 
			    {
				    u_RetVal = RTE_E_INVALID;
				    *ErrorCode = DCM_E_GENERALPROGRAMMINGFAILURE;
			    }
		    }
		    else 
		    {
			    u_RetVal = RTE_E_INVALID;
			    *ErrorCode = DCM_E_GENERALPROGRAMMINGFAILURE;
		    }
		}
		else
		{
			u_RetVal = RTE_E_INVALID;
			*ErrorCode = DCM_E_REQUESTOUTOFRANGE; //NRC31
		}
	}
	else if ((uint8) DCM_PENDING == OpStatus) 
	{
		ui8_RetVal_ErrStat = Rte_Call_RP_Nvm_Vehicletype_GetErrorStatus(&ui8_WriteStatus);
	  
		if ((uint8) E_OK == ui8_RetVal_ErrStat)
		{
			if ((uint8) NVM_REQ_OK == ui8_WriteStatus) 
			{
				b_WriteFlagSuccess = TRUE;
			} 
			else if ((uint8) NVM_REQ_PENDING == ui8_WriteStatus) 
			{
				u_RetVal = DCM_E_PENDING;
			} 
			else
			{
				u_RetVal = RTE_E_INVALID;
				*ErrorCode = DCM_E_GENERALPROGRAMMINGFAILURE;
			}
		} 
		else 
		{
			u_RetVal = RTE_E_INVALID;
			*ErrorCode = DCM_E_GENERALPROGRAMMINGFAILURE;
		}
	}
	else if ((uint8) DCM_CANCEL == OpStatus) 
	{
		(void)Rte_Call_RP_Nvm_Vehicletype_GetErrorStatus(&ui8_WriteStatus);
	  
		if ((uint8) NVM_REQ_PENDING == ui8_WriteStatus) 
		{
			ui8_RetVal_ErrStat = NvM_CancelJobs(NvMConf_NvMBlockDescriptor_NvM_Block_Vehicletype);
				  
			b_NvmOperationPending = TRUE;
	  
			if ((uint8) E_OK == ui8_RetVal_ErrStat) 
			{
				*ErrorCode = E_OK;
				u_RetVal = E_OK;
			} 
			else 
			{
				u_RetVal = RTE_E_INVALID;
				*ErrorCode = DCM_E_GENERALPROGRAMMINGFAILURE;
			}
		} 
		else 
		{
			*ErrorCode = E_OK;
			u_RetVal = E_OK;
		}
	  
			b_WriteFlagSuccess = FALSE;
	} 
	else 
	{
		*ErrorCode = DCM_E_CONDITIONSNOTCORRECT;
		u_RetVal = RTE_E_INVALID;
	}
	  
	if (TRUE == b_WriteFlagSuccess) 
	{
		(void)Rte_Call_RP_Nvm_Vehicletype_SetRamBlockStatus(TRUE);
	
		*ErrorCode = E_OK;
		u_RetVal = E_OK;
	}
	else 
	{
		if ((uint8) DCM_E_PENDING == u_RetVal)
		{
			*ErrorCode = DCM_E_REQUESTCORRECTLYRECEIVEDRESPONSEPENDING;
		} 
		else 
		{
			if (FALSE == b_NvmOperationPending) 
			{
				(void)Rte_Call_RP_Nvm_Vehicletype_SetRamBlockStatus(TRUE);
			}
		}
	}
#endif
	
	return u_RetVal;

} /* FUNC(Std_ReturnType, RTE_CODE) Dsm_u_WDBI_VehicleType_Write (P2CONST(uint8, AUTOMATIC, RTE_APPL_DATA) Data, Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_APPL_DATA) ErrorCode) */
#endif

/**
 * \functions Dsm_u_WDBI_FABSwitch_Write
 *
 * \brief Write the switch of the FAB from Data flash.(F1F1)
 *
 ** \param[in] none,
 *
 ** \param[out] Data, Pointer to Data buffer (1 bytes).
 ** \return RTE_E_OK, 
 * \comments  
 *
 */
#if (DSM_FEAT_WDBI_FABSwitch == STD_ON)
FUNC(Std_ReturnType, RTE_CODE) Dsm_u_WDBI_FABSwitch_Write (P2CONST(uint8, AUTOMATIC, RTE_APPL_DATA) Data, Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_APPL_DATA) ErrorCode)
{
	  /* suppress compiler warnings about unused arguments */
	  Std_ReturnType u_RetVal = RTE_E_OK;
	  
#if((DSM_SYSTEM_TYPE == DSM_SYSTEM_MFC5J3_C673)|| \
						(DSM_SYSTEM_TYPE == DSM_SYSTEM_MFC5J3_C385))  
						
	  Std_ReturnType ui8_RetVal_Write = RTE_E_INVALID;
	  Std_ReturnType ui8_RetVal_ErrStat = RTE_E_INVALID;
	  NvM_RequestResultType ui8_WriteStatus = NVM_REQ_NOT_OK;		
	  boolean b_NvmOperationPending = FALSE;
	  static boolean b_WriteFlagSuccess;
		  
	  if ((uint8) DCM_INITIAL == OpStatus) 
	  {
		  b_WriteFlagSuccess = FALSE;
		  
		  if((Data[0] == 0x00u)||
			  (Data[0] == 0x01u))
		  {
		      /*Service for setting the lock status of a permanent RAM block of an NVRAM block.*/
			  (void)Rte_Call_RP_Nvm_FAB_switch_SetRamBlockStatus(FALSE);
			  
		      /* PRQA S 0314 ++ */ /* P2Obj to P2void conversion is safe */
			  Rte_Enter_DSM_EXCLUSIVEAREA();
			  
		      (void)TS_MemCpy((void*)RAM_NVM_BLOCK_FAB_switch, (const void*)Data, FABSWITCH_LEN);

			  Rte_Exit_DSM_EXCLUSIVEAREA();
			  
			  ui8_RetVal_Write = Rte_Call_RP_Nvm_FAB_switch_WriteBlock((void*) &RAM_NVM_BLOCK_FAB_switch);
				
		      if ((uint8) E_OK == ui8_RetVal_Write) 
		      {
				  ui8_RetVal_ErrStat = Rte_Call_RP_Nvm_FAB_switch_GetErrorStatus(&ui8_WriteStatus);
		
			      if ((uint8) E_OK == ui8_RetVal_ErrStat)
			      {
				      if ((uint8) NVM_REQ_OK == ui8_WriteStatus) 
				      {
					      b_WriteFlagSuccess = TRUE;
				      }
				      else if ((uint8) NVM_REQ_PENDING == ui8_WriteStatus)
				      {
					      u_RetVal = DCM_E_PENDING;
				      } 
				      else 
				      {
					      u_RetVal = RTE_E_INVALID;
					      *ErrorCode = DCM_E_GENERALPROGRAMMINGFAILURE;
				      }
			      } 
			      else 
			      {
				      u_RetVal = RTE_E_INVALID;
				      *ErrorCode = DCM_E_GENERALPROGRAMMINGFAILURE;
			      }
		      }
		     else 
		     {
			     u_RetVal = RTE_E_INVALID;
			     *ErrorCode = DCM_E_GENERALPROGRAMMINGFAILURE;
		     }
		 }
		 else
		 {
		     *ErrorCode = DCM_E_REQUESTOUTOFRANGE; //NRC31
		     u_RetVal = RTE_E_INVALID;
		 }
			  	
	  }
	  else if ((uint8) DCM_PENDING == OpStatus) 
	  {
		  ui8_RetVal_ErrStat = Rte_Call_RP_Nvm_FAB_switch_GetErrorStatus(&ui8_WriteStatus);
		
		  if ((uint8) E_OK == ui8_RetVal_ErrStat)
		  {
			  if ((uint8) NVM_REQ_OK == ui8_WriteStatus) 
			  {
				  b_WriteFlagSuccess = TRUE;
			  } 
			  else if ((uint8) NVM_REQ_PENDING == ui8_WriteStatus) 
			  {
				  u_RetVal = DCM_E_PENDING;
			  } 
			  else
			  {
				  u_RetVal = RTE_E_INVALID;
				  *ErrorCode = DCM_E_GENERALPROGRAMMINGFAILURE;
			  }
		  } 
		  else 
		  {
			  u_RetVal = RTE_E_INVALID;
			  *ErrorCode = DCM_E_GENERALPROGRAMMINGFAILURE;
		  }
	  }
	  else if ((uint8) DCM_CANCEL == OpStatus) 
	  {
		  (void)Rte_Call_RP_Nvm_FAB_switch_GetErrorStatus(&ui8_WriteStatus);
		
		  if ((uint8) NVM_REQ_PENDING == ui8_WriteStatus) 
		  {
			  ui8_RetVal_ErrStat = NvM_CancelJobs(NvMConf_NvMBlockDescriptor_NVM_BLOCK_FAB_switch);
					
			  b_NvmOperationPending = TRUE;
		
			  if ((uint8) E_OK == ui8_RetVal_ErrStat) 
			  {
				  *ErrorCode = E_OK;
				  u_RetVal = E_OK;
			  } 
			  else 
			  {
				  u_RetVal = RTE_E_INVALID;
				  *ErrorCode = DCM_E_GENERALPROGRAMMINGFAILURE;
			  }
		  } 
		  else 
		  {
			  *ErrorCode = E_OK;
			  u_RetVal = E_OK;
		  }
		
			  b_WriteFlagSuccess = FALSE;
	  } 
	  else 
	  {
		  *ErrorCode = DCM_E_CONDITIONSNOTCORRECT;
		  u_RetVal = RTE_E_INVALID;
	  }
		
	  if (TRUE == b_WriteFlagSuccess) 
	  {
		  (void)Rte_Call_RP_Nvm_FAB_switch_SetRamBlockStatus(TRUE);
	  
		  *ErrorCode = E_OK;
		  u_RetVal = E_OK;
	  }
	  else 
	  {
		  if ((uint8) DCM_E_PENDING == u_RetVal)
		  {
			  *ErrorCode = DCM_E_REQUESTCORRECTLYRECEIVEDRESPONSEPENDING;
		  } 
		  else 
		  {
			  if (FALSE == b_NvmOperationPending) 
			  {
				  (void)Rte_Call_RP_Nvm_FAB_switch_SetRamBlockStatus(TRUE);
			  }
		  }
	  }
#endif
	  
		  return u_RetVal;

} /* FUNC(Std_ReturnType, RTE_CODE) Dsm_u_WDBI_FABSwitch_Write (P2CONST(uint8, AUTOMATIC, RTE_APPL_DATA) Data, Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_APPL_DATA) ErrorCode) */
#endif

/**
 * \functions Dsm_u_WDBI_TSRSwitch_Write
 *
 * \brief Write the switch of the TSR from Data flash.(F1F2)
 *
 ** \param[in] none,
 *
 ** \param[out] Data, Pointer to Data buffer (1 bytes).
 ** \return RTE_E_OK, 
 * \comments  
 *
 */
#if (DSM_FEAT_WDBI_TSRSwitch == STD_ON)
FUNC(Std_ReturnType, RTE_CODE) Dsm_u_WDBI_TSRSwitch_Write (P2CONST(uint8, AUTOMATIC, RTE_APPL_DATA) Data, Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_APPL_DATA) ErrorCode)
{
	/* suppress compiler warnings about unused arguments */
	Std_ReturnType u_RetVal = RTE_E_OK;
		
#if((DSM_SYSTEM_TYPE == DSM_SYSTEM_MFC5J3_C673)|| \
						  (DSM_SYSTEM_TYPE == DSM_SYSTEM_MFC5J3_C385))	
						  
	Std_ReturnType ui8_RetVal_Write = RTE_E_INVALID;
	Std_ReturnType ui8_RetVal_ErrStat = RTE_E_INVALID;
	NvM_RequestResultType ui8_WriteStatus = NVM_REQ_NOT_OK;		  
	boolean b_NvmOperationPending = FALSE;
	static boolean b_WriteFlagSuccess;
			
	if ((uint8) DCM_INITIAL == OpStatus) 
	{
		b_WriteFlagSuccess = FALSE;
		
		if((Data[0] == 0x00u)||
			(Data[0] == 0x01u))
		{
		    /*Service for setting the lock status of a permanent RAM block of an NVRAM block.*/
			(void)Rte_Call_RP_Nvm_TSR_switch_SetRamBlockStatus(FALSE);
				
		    /* PRQA S 0314 ++ */ /* P2Obj to P2void conversion is safe */
			Rte_Enter_DSM_EXCLUSIVEAREA();
			
		    (void)TS_MemCpy((void*)RAM_NVM_BLOCK_TSR_switch, (const void*)Data, TSRSWITCH_LEN);

			Rte_Exit_DSM_EXCLUSIVEAREA();
			
			ui8_RetVal_Write = Rte_Call_RP_Nvm_TSR_switch_WriteBlock((void*) &RAM_NVM_BLOCK_TSR_switch);
				  
		    if ((uint8) E_OK == ui8_RetVal_Write) 
		    {
				ui8_RetVal_ErrStat = Rte_Call_RP_Nvm_TSR_switch_GetErrorStatus(&ui8_WriteStatus);
		  
			    if ((uint8) E_OK == ui8_RetVal_ErrStat)
			    {
				    if ((uint8) NVM_REQ_OK == ui8_WriteStatus) 
				    {
					    b_WriteFlagSuccess = TRUE;
				    }
				    else if ((uint8) NVM_REQ_PENDING == ui8_WriteStatus)
				    {
					    u_RetVal = DCM_E_PENDING;
				    } 
				    else 
				    {
					    u_RetVal = RTE_E_INVALID;
					    *ErrorCode = DCM_E_GENERALPROGRAMMINGFAILURE;
				    }
			    } 
			    else 
			    {
				    u_RetVal = RTE_E_INVALID;
				    *ErrorCode = DCM_E_GENERALPROGRAMMINGFAILURE;
			    }
		    }
		    else 
		    {
			    u_RetVal = RTE_E_INVALID;
			    *ErrorCode = DCM_E_GENERALPROGRAMMINGFAILURE;
		    }
	    }
		else
		{
		    *ErrorCode = DCM_E_REQUESTOUTOFRANGE; //NRC31
		    u_RetVal = RTE_E_INVALID;
		}
	}
	else if ((uint8) DCM_PENDING == OpStatus) 
	{
		ui8_RetVal_ErrStat = Rte_Call_RP_Nvm_TSR_switch_GetErrorStatus(&ui8_WriteStatus);
		  
		if ((uint8) E_OK == ui8_RetVal_ErrStat)
		{
			if ((uint8) NVM_REQ_OK == ui8_WriteStatus) 
			{
				b_WriteFlagSuccess = TRUE;
			} 
			else if ((uint8) NVM_REQ_PENDING == ui8_WriteStatus) 
			{
				u_RetVal = DCM_E_PENDING;
			} 
			else
			{
				u_RetVal = RTE_E_INVALID;
				*ErrorCode = DCM_E_GENERALPROGRAMMINGFAILURE;
			}
		} 
		else 
		{
			u_RetVal = RTE_E_INVALID;
			*ErrorCode = DCM_E_GENERALPROGRAMMINGFAILURE;
		}
	}
	else if ((uint8) DCM_CANCEL == OpStatus) 
	{
		(void)Rte_Call_RP_Nvm_TSR_switch_GetErrorStatus(&ui8_WriteStatus);
		  
		if ((uint8) NVM_REQ_PENDING == ui8_WriteStatus) 
		{
			ui8_RetVal_ErrStat = NvM_CancelJobs(NvMConf_NvMBlockDescriptor_NVM_BLOCK_TSR_switch);
					  
			b_NvmOperationPending = TRUE;
		  
			if ((uint8) E_OK == ui8_RetVal_ErrStat) 
			{
				*ErrorCode = E_OK;
				u_RetVal = E_OK;
			} 
			else 
			{
				u_RetVal = RTE_E_INVALID;
				*ErrorCode = DCM_E_GENERALPROGRAMMINGFAILURE;
			}
		} 
		else 
		{
			*ErrorCode = E_OK;
			u_RetVal = E_OK;
		}
		  
		b_WriteFlagSuccess = FALSE;
	} 
	else 
	{
		*ErrorCode = DCM_E_CONDITIONSNOTCORRECT;
		u_RetVal = RTE_E_INVALID;
	}
		  
	if (TRUE == b_WriteFlagSuccess) 
	{
		(void)Rte_Call_RP_Nvm_TSR_switch_SetRamBlockStatus(TRUE);
		
		*ErrorCode = E_OK;
		u_RetVal = E_OK;
	}
	else 
	{
		if ((uint8) DCM_E_PENDING == u_RetVal)
		{
			*ErrorCode = DCM_E_REQUESTCORRECTLYRECEIVEDRESPONSEPENDING;
		} 
		else 
		{
			if (FALSE == b_NvmOperationPending) 
			{
				(void)Rte_Call_RP_Nvm_TSR_switch_SetRamBlockStatus(TRUE);
			}
		}
	}
#endif
		
	return u_RetVal;

} /* FUNC(Std_ReturnType, RTE_CODE) Dsm_u_WDBI_TSRSwitch_Write (P2CONST(uint8, AUTOMATIC, RTE_APPL_DATA) Data, Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_APPL_DATA) ErrorCode) */
#endif

/**
 * \functions Dsm_u_WDBI_TLASwitch_Write
 *
 * \brief Write the switch of the TLA from Data flash.(F1F3)
 *
 ** \param[in] none,
 *
 ** \param[out] Data, Pointer to Data buffer (1 bytes).
 ** \return RTE_E_OK, 
 * \comments  
 *
 */
#if (DSM_FEAT_WDBI_TLASwitch == STD_ON)
FUNC(Std_ReturnType, RTE_CODE) Dsm_u_WDBI_TLASwitch_Write (P2CONST(uint8, AUTOMATIC, RTE_APPL_DATA) Data, Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_APPL_DATA) ErrorCode)
{
	  /* suppress compiler warnings about unused arguments */
	  Std_ReturnType u_RetVal = RTE_E_OK;
		  
#if((DSM_SYSTEM_TYPE == DSM_SYSTEM_MFC5J3_C673)|| \
							(DSM_SYSTEM_TYPE == DSM_SYSTEM_MFC5J3_C385))  
							
	  Std_ReturnType ui8_RetVal_Write = RTE_E_INVALID;
	  Std_ReturnType ui8_RetVal_ErrStat = RTE_E_INVALID;
	  NvM_RequestResultType ui8_WriteStatus = NVM_REQ_NOT_OK;			
	  boolean b_NvmOperationPending = FALSE;
	  static boolean b_WriteFlagSuccess;
			  
	  if ((uint8) DCM_INITIAL == OpStatus) 
	  {
		  b_WriteFlagSuccess = FALSE;

		  if((Data[0] == 0x00u)||
			(Data[0] == 0x01u))
		  {
		      /*Service for setting the lock status of a permanent RAM block of an NVRAM block.*/
			  (void)Rte_Call_RP_Nvm_TLA_switch_SetRamBlockStatus(FALSE);  
		      /* PRQA S 0314 ++ */ /* P2Obj to P2void conversion is safe */
			  Rte_Enter_DSM_EXCLUSIVEAREA();
			  
		      (void)TS_MemCpy((void*)RAM_NVM_BLOCK_TLA_switch, (const void*)Data, TLASWITCH_LEN);

			  Rte_Exit_DSM_EXCLUSIVEAREA();
			  
			  ui8_RetVal_Write = Rte_Call_RP_Nvm_TLA_switch_WriteBlock((void*) &RAM_NVM_BLOCK_TLA_switch);
					
		      if ((uint8) E_OK == ui8_RetVal_Write) 
		      {
			      ui8_RetVal_ErrStat = Rte_Call_RP_Nvm_TLA_switch_GetErrorStatus(&ui8_WriteStatus);
				  
			      if ((uint8) E_OK == ui8_RetVal_ErrStat)
			      {
				      if ((uint8) NVM_REQ_OK == ui8_WriteStatus) 
				      {
					      b_WriteFlagSuccess = TRUE;
				      }
				      else if ((uint8) NVM_REQ_PENDING == ui8_WriteStatus)
				      {
					      u_RetVal = DCM_E_PENDING;
				      } 
				      else 
				      {
					      u_RetVal = RTE_E_INVALID;
					      *ErrorCode = DCM_E_GENERALPROGRAMMINGFAILURE;
				      }
			      } 
			      else 
			      {
				      u_RetVal = RTE_E_INVALID;
				      *ErrorCode = DCM_E_GENERALPROGRAMMINGFAILURE;
			      }
		      }
		      else 
		      {
			      u_RetVal = RTE_E_INVALID;
			      *ErrorCode = DCM_E_GENERALPROGRAMMINGFAILURE;
		      }
		 }
		 else
		 {
		     *ErrorCode = DCM_E_REQUESTOUTOFRANGE; //NRC31
		     u_RetVal = RTE_E_INVALID;
		 }
	  }
	  else if ((uint8) DCM_PENDING == OpStatus) 
	  {
		  ui8_RetVal_ErrStat = Rte_Call_RP_Nvm_TLA_switch_GetErrorStatus(&ui8_WriteStatus);
			
		  if ((uint8) E_OK == ui8_RetVal_ErrStat)
		  {
			  if ((uint8) NVM_REQ_OK == ui8_WriteStatus) 
			  {
				  b_WriteFlagSuccess = TRUE;
			  } 
			  else if ((uint8) NVM_REQ_PENDING == ui8_WriteStatus) 
			  {
				  u_RetVal = DCM_E_PENDING;
			  } 
			  else
			  {
				  u_RetVal = RTE_E_INVALID;
				  *ErrorCode = DCM_E_GENERALPROGRAMMINGFAILURE;
			  }
		  } 
		  else 
		  {
			  u_RetVal = RTE_E_INVALID;
			  *ErrorCode = DCM_E_GENERALPROGRAMMINGFAILURE;
		  }
	  }
	  else if ((uint8) DCM_CANCEL == OpStatus) 
	  {
		  (void)Rte_Call_RP_Nvm_TLA_switch_GetErrorStatus(&ui8_WriteStatus);
			
		  if ((uint8) NVM_REQ_PENDING == ui8_WriteStatus) 
		  {
			  ui8_RetVal_ErrStat = NvM_CancelJobs(NvMConf_NvMBlockDescriptor_NVM_BLOCK_TLA_switch);
						
			  b_NvmOperationPending = TRUE;
			
			  if ((uint8) E_OK == ui8_RetVal_ErrStat) 
			  {
				  *ErrorCode = E_OK;
				  u_RetVal = E_OK;
			  } 
			  else 
			  {
				  u_RetVal = RTE_E_INVALID;
				  *ErrorCode = DCM_E_GENERALPROGRAMMINGFAILURE;
			  }
		  } 
		  else 
		  {
			  *ErrorCode = E_OK;
			  u_RetVal = E_OK;
		  }
			
		  b_WriteFlagSuccess = FALSE;
	  } 
	  else 
	  {
		  *ErrorCode = DCM_E_CONDITIONSNOTCORRECT;
		  u_RetVal = RTE_E_INVALID;
	  }
			
	  if (TRUE == b_WriteFlagSuccess) 
	  {
		  (void)Rte_Call_RP_Nvm_TLA_switch_SetRamBlockStatus(TRUE);
		  
		  *ErrorCode = E_OK;
		  u_RetVal = E_OK;
	  }
	  else 
	  {
		  if ((uint8) DCM_E_PENDING == u_RetVal)
		  {
			  *ErrorCode = DCM_E_REQUESTCORRECTLYRECEIVEDRESPONSEPENDING;
		  } 
		  else 
		  {
			  if (FALSE == b_NvmOperationPending) 
			  {
				  (void)Rte_Call_RP_Nvm_TLA_switch_SetRamBlockStatus(TRUE);
			  }
		  }
	  }
#endif
		  
	  return u_RetVal;

} /* FUNC(Std_ReturnType, RTE_CODE) Dsm_u_WDBI_TLASwitch_Write (P2CONST(uint8, AUTOMATIC, RTE_APPL_DATA) Data, Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_APPL_DATA) ErrorCode) */
#endif

/**
 * \functions Dsm_u_RDBI_LaneFunctionConfiguration_Read
 *
 * \brief Write Lane function configuration from Data flash.(F1FE)
 *
 ** \param[in] none,
 *
 ** \param[out] Data, Pointer to Data buffer (2 bytes).
 **                  The DID format as below:
 **                   byte:   bit:    subdataname:  default value:
 **                   byte0	 bit0:	 LDW              1
 **                   byte0	 bit1:	 LKA              1
 **                   byte0	 bit2:	 LCS              0
 **                   byte0	 bit3:	 IACC             0
 **                   byte0	 bit4:	 ELK              1
 **                   byte0	 bit5:	 Handsfree        0
 **                   byte0	 bit6:	 AEB              1
 **                   byte0	 bit7:	 FCW              1
 **                   byte1	 bit0:	 TSR              1
 **                   byte1	 bit1:	 TLA              1
 **                   byte1	 bit2:	 FAB              1
 **                   byte1	 bit3-7: reserved         0
 ** \return RTE_E_OK, 
 * \comments  
 *
 */
#if (DSM_FEAT_WDBI_LaneFunctionConfiguration == STD_ON)
FUNC(Std_ReturnType, RTE_CODE) Dsm_u_WDBI_LaneFunctionConfiguration_Write (P2CONST(uint8, AUTOMATIC, RTE_APPL_DATA) Data, Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_APPL_DATA) ErrorCode)
{
    /* suppress compiler warnings about unused arguments */
	Std_ReturnType u_RetVal = RTE_E_OK;
			
#if((DSM_SYSTEM_TYPE == DSM_SYSTEM_MFC5J3_C673)|| \
							  (DSM_SYSTEM_TYPE == DSM_SYSTEM_MFC5J3_C385))	
							  
	Std_ReturnType ui8_RetVal_Write = RTE_E_INVALID;
	Std_ReturnType ui8_RetVal_ErrStat = RTE_E_INVALID;
	NvM_RequestResultType ui8_WriteStatus = NVM_REQ_NOT_OK;			  
	boolean b_NvmOperationPending = FALSE;
	static boolean b_WriteFlagSuccess;
				
	if ((uint8) DCM_INITIAL == OpStatus) 
	{
		b_WriteFlagSuccess = FALSE;
					
		/*Service for setting the lock status of a permanent RAM block of an NVRAM block.*/
		Rte_Call_RP_Nvm_LaneFunctionConfiguration_SetRamBlockStatus(FALSE);			
		/* PRQA S 0314 ++ */ /* P2Obj to P2void conversion is safe */
		Rte_Enter_DSM_EXCLUSIVEAREA();
		
		(void)TS_MemCpy((void*)RAM_NVM_BLOCK_LaneFunctionConfiguration, (const void*)Data, LANEFUNCCONFIG_LEN);

		Rte_Exit_DSM_EXCLUSIVEAREA();
		
		ui8_RetVal_Write = Rte_Call_RP_Nvm_LaneFunctionConfiguration_WriteBlock((void*) &RAM_NVM_BLOCK_LaneFunctionConfiguration);	
		
		if ((uint8) E_OK == ui8_RetVal_Write) 
		{
			ui8_RetVal_ErrStat = Rte_Call_RP_Nvm_LaneFunctionConfiguration_GetErrorStatus(&ui8_WriteStatus);
			
			if ((uint8) E_OK == ui8_RetVal_ErrStat)
			{
				if ((uint8) NVM_REQ_OK == ui8_WriteStatus) 
				{
					b_WriteFlagSuccess = TRUE;
				}
				else if ((uint8) NVM_REQ_PENDING == ui8_WriteStatus)
				{
					u_RetVal = DCM_E_PENDING;
				} 
				else 
				{
					u_RetVal = RTE_E_INVALID;
					*ErrorCode = DCM_E_GENERALPROGRAMMINGFAILURE;
				}
			} 
			else 
			{
				u_RetVal = RTE_E_INVALID;
				*ErrorCode = DCM_E_GENERALPROGRAMMINGFAILURE;
			}
		}
		else 
		{
			u_RetVal = RTE_E_INVALID;
			*ErrorCode = DCM_E_GENERALPROGRAMMINGFAILURE;
		}
	}
	else if ((uint8) DCM_PENDING == OpStatus) 
	{
		ui8_RetVal_ErrStat = Rte_Call_RP_Nvm_LaneFunctionConfiguration_GetErrorStatus(&ui8_WriteStatus);
			  
		if ((uint8) E_OK == ui8_RetVal_ErrStat)
		{
			if ((uint8) NVM_REQ_OK == ui8_WriteStatus) 
			{
				b_WriteFlagSuccess = TRUE;
			} 
			else if ((uint8) NVM_REQ_PENDING == ui8_WriteStatus) 
			{
				u_RetVal = DCM_E_PENDING;
			} 
			else
			{
				u_RetVal = RTE_E_INVALID;
				*ErrorCode = DCM_E_GENERALPROGRAMMINGFAILURE;
			}
		} 
		else 
		{
			u_RetVal = RTE_E_INVALID;
			*ErrorCode = DCM_E_GENERALPROGRAMMINGFAILURE;
		}
	}
	else if ((uint8) DCM_CANCEL == OpStatus) 
	{
		(void)Rte_Call_RP_Nvm_LaneFunctionConfiguration_GetErrorStatus(&ui8_WriteStatus);
			  
		if ((uint8) NVM_REQ_PENDING == ui8_WriteStatus) 
		{
		    ui8_RetVal_ErrStat = NvM_CancelJobs(NvMConf_NvMBlockDescriptor_NvM_Block_LaneFunctionConfiguration);
						  
			b_NvmOperationPending = TRUE;
			  
			if ((uint8) E_OK == ui8_RetVal_ErrStat) 
			{
				*ErrorCode = E_OK;
				u_RetVal = E_OK;
			} 
			else 
			{
				u_RetVal = RTE_E_INVALID;
				*ErrorCode = DCM_E_GENERALPROGRAMMINGFAILURE;
			}
		} 
		else 
		{
			*ErrorCode = E_OK;
			u_RetVal = E_OK;
		}
			  
		b_WriteFlagSuccess = FALSE;
	} 
	else 
	{
		*ErrorCode = DCM_E_CONDITIONSNOTCORRECT;
		u_RetVal = RTE_E_INVALID;
	}
			  
	if (TRUE == b_WriteFlagSuccess) 
	{
		(void)Rte_Call_RP_Nvm_LaneFunctionConfiguration_SetRamBlockStatus(TRUE);	
			
		*ErrorCode = E_OK;
		u_RetVal = E_OK;
	}
	else 
	{
		if ((uint8) DCM_E_PENDING == u_RetVal)
		{
			*ErrorCode = DCM_E_REQUESTCORRECTLYRECEIVEDRESPONSEPENDING;
		} 
		else 
		{
			if (FALSE == b_NvmOperationPending) 
			{
				(void)Rte_Call_RP_Nvm_LaneFunctionConfiguration_SetRamBlockStatus(TRUE);
			}
		}
	}
#endif
			
	return u_RetVal;

} /* FUNC(Std_ReturnType, RTE_CODE) Dsm_u_WDBI_LaneFunctionConfiguration_Write (P2CONST(uint8, AUTOMATIC, RTE_APPL_DATA) Data, Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_APPL_DATA) ErrorCode) */
#endif

/**
 * \functions Dsm_u_WDBI_EOL_ModeGate_Write
 *
 * \brief Write EOL mode gate from specific DF static Address.(F1FF)
 *
 ** \param[in] none,
 *
 ** \param[out] Data, Pointer to Data buffer (8 bytes).
 **                  ASCII formatted
 *
 ** \return RTE_E_OK, 
 * \comments  base Address:0xAF07B000 startAddress: 0xAF07B028  Total Length: 2byte
 *
 */
#if (DSM_FEAT_WDBI_EOL_ModeGate == STD_ON)
FUNC(Std_ReturnType, RTE_CODE) Dsm_u_WDBI_EOL_ModeGate_Write (P2CONST(uint8, AUTOMATIC, RTE_APPL_DATA) Data, Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_APPL_DATA) ErrorCode)
{
    /* suppress compiler warnings about unused arguments */
	Std_ReturnType u_Retval = RTE_E_OK;
	  
#if((DSM_SYSTEM_TYPE == DSM_SYSTEM_MFC5J3_C673)|| \
					(DSM_SYSTEM_TYPE == DSM_SYSTEM_MFC5J3_C385))  
	static boolean b_WriteFlagSuccess;
	static uint8 ui8_QsmReqStatus = QSM_REQRESULT_NOT_OK;
	  
	if((uint8)DCM_INITIAL == OpStatus)
	{
	    b_WriteFlagSuccess = FALSE;

		if(((Data[0] == 0x05u) &&(Data[1] == 0x25u))||
			((Data[0] == 0x00u) &&(Data[1]== 0x00u)))
		{  
		    /* PRQA S 0314 2 */ /* Pointer to void, no problem */
		    Rte_Enter_DSM_EXCLUSIVEAREA();

			(void)TS_MemCpy((void*)s_QSBlock_EcuSpecInfo.F1FF, (void*)Data, EOLMODEGATE_LEN);

			Rte_Exit_DSM_EXCLUSIVEAREA();
			
	        (void)Rte_Call_RP_Qsm_Block_EOLModeGateOP_Qsm_WriteBlock(&s_QSBlock_EcuSpecInfo);

		    ui8_QsmReqStatus = Rte_Call_RP_Qsm_Block_EOLModeGateOP_Qsm_GetErrorStatues();
		
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
		else
		{
		    *ErrorCode = DCM_E_REQUESTOUTOFRANGE; //NRC31
		    u_Retval = RTE_E_INVALID;
		} 
    }
	else if((uint8)DCM_PENDING == OpStatus)
	{
	    ui8_QsmReqStatus = Rte_Call_RP_Qsm_Block_EOLModeGateOP_Qsm_GetErrorStatues();
		
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
			 /*Do nothing*/
		}
	}
#endif
  
	 return u_Retval;
} /* FUNC(Std_ReturnType, RTE_CODE) Dsm_u_WDBI_EOL_ModeGate_Write (P2CONST(uint8, AUTOMATIC, RTE_APPL_DATA) Data, Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_APPL_DATA) ErrorCode) */
#endif

/**
 * \functions Dsm_u_WDBI_PCBASerialNumberDataIdentifier_Write
 *
 * \brief Write PCBA Serial number data identifier from Data flash.(FD24)
 *
 ** \param[in] none,
 *
 ** \param[out] Data, Pointer to Data buffer (5 bytes).
 **
 ** \return RTE_E_OK, 
 * \comments  
 *
 */
#if (DSM_FEAT_WDBI_PCBASerialNumberDataIdentifier == STD_ON)
FUNC(Std_ReturnType, RTE_CODE) Dsm_u_WDBI_PCBASerialNumberDataIdentifier_Write (P2CONST(uint8, AUTOMATIC, RTE_APPL_DATA) Data, Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_APPL_DATA) ErrorCode)
{
    /* suppress compiler warnings about unused arguments */
	Std_ReturnType u_RetVal = RTE_E_OK;
			  
#if((DSM_SYSTEM_TYPE == DSM_SYSTEM_MFC5J3_C673)|| \
								(DSM_SYSTEM_TYPE == DSM_SYSTEM_MFC5J3_C385))  
								
    Std_ReturnType ui8_RetVal_Write = RTE_E_INVALID;
	Std_ReturnType ui8_RetVal_ErrStat = RTE_E_INVALID;
	NvM_RequestResultType ui8_WriteStatus = NVM_REQ_NOT_OK;				
	boolean b_NvmOperationPending = FALSE;
	static boolean b_WriteFlagSuccess;
				  
	if ((uint8) DCM_INITIAL == OpStatus) 
	{
		b_WriteFlagSuccess = FALSE;
					  
		/*Service for setting the lock status of a permanent RAM block of an NVRAM block.*/
		(void)Rte_Call_RP_Nvm_PCBASerialNumberDataIdentifier_SetRamBlockStatus(FALSE);			  
		/* PRQA S 0314 ++ */ /* P2Obj to P2void conversion is safe */
		Rte_Enter_DSM_EXCLUSIVEAREA();
		
		(void)TS_MemCpy((void*)RAM_NVM_BLOCK_PCBASerialNumberDataIdentifier, (const void*)Data, PCBASNDATAIDENT_LEN);

		Rte_Exit_DSM_EXCLUSIVEAREA();
		
		ui8_RetVal_Write = Rte_Call_RP_Nvm_PCBASerialNumberDataIdentifier_WriteBlock((void*) &RAM_NVM_BLOCK_PCBASerialNumberDataIdentifier);
						
		if ((uint8) E_OK == ui8_RetVal_Write) 
		{
			ui8_RetVal_ErrStat = Rte_Call_RP_Nvm_PCBASerialNumberDataIdentifier_GetErrorStatus(&ui8_WriteStatus);
				
			if ((uint8) E_OK == ui8_RetVal_ErrStat)
			{
			    if ((uint8) NVM_REQ_OK == ui8_WriteStatus) 
				{
				    b_WriteFlagSuccess = TRUE;
				}
				else if ((uint8) NVM_REQ_PENDING == ui8_WriteStatus)
				{
					u_RetVal = DCM_E_PENDING;
				} 
				else 
				{
					u_RetVal = RTE_E_INVALID;
					*ErrorCode = DCM_E_GENERALPROGRAMMINGFAILURE;
				}
		    } 
			else 
			{
				u_RetVal = RTE_E_INVALID;
				*ErrorCode = DCM_E_GENERALPROGRAMMINGFAILURE;
			}
		}
		else 
		{
		    u_RetVal = RTE_E_INVALID;
			*ErrorCode = DCM_E_GENERALPROGRAMMINGFAILURE;
		}
    }
	else if ((uint8) DCM_PENDING == OpStatus) 
	{
		ui8_RetVal_ErrStat = Rte_Call_RP_Nvm_PCBASerialNumberDataIdentifier_GetErrorStatus(&ui8_WriteStatus);
				
		if ((uint8) E_OK == ui8_RetVal_ErrStat)
		{
		    if ((uint8) NVM_REQ_OK == ui8_WriteStatus) 
			{
			    b_WriteFlagSuccess = TRUE;
			} 
			else if ((uint8) NVM_REQ_PENDING == ui8_WriteStatus) 
			{
				u_RetVal = DCM_E_PENDING;
			} 
			else
			{
				u_RetVal = RTE_E_INVALID;
				*ErrorCode = DCM_E_GENERALPROGRAMMINGFAILURE;
			}
		} 
		else 
		{
			u_RetVal = RTE_E_INVALID;
			*ErrorCode = DCM_E_GENERALPROGRAMMINGFAILURE;
		}
	}
	else if ((uint8) DCM_CANCEL == OpStatus) 
	{
		(void)Rte_Call_RP_Nvm_PCBASerialNumberDataIdentifier_GetErrorStatus(&ui8_WriteStatus);
				
		if ((uint8) NVM_REQ_PENDING == ui8_WriteStatus) 
		{
			ui8_RetVal_ErrStat = NvM_CancelJobs(NvMConf_NvMBlockDescriptor_NvM_Block_PCBASerialNumberDataIdentifier);
							
			b_NvmOperationPending = TRUE;
				
			if ((uint8) E_OK == ui8_RetVal_ErrStat) 
			{
				*ErrorCode = E_OK;
				u_RetVal = E_OK;
			} 
			else 
			{
				u_RetVal = RTE_E_INVALID;
				*ErrorCode = DCM_E_GENERALPROGRAMMINGFAILURE;
			}
		} 
		else 
		{
			*ErrorCode = E_OK;
			u_RetVal = E_OK;
		}
				
		b_WriteFlagSuccess = FALSE;
	} 
	else 
	{
		*ErrorCode = DCM_E_CONDITIONSNOTCORRECT;
		u_RetVal = RTE_E_INVALID;
	}
				
	if (TRUE == b_WriteFlagSuccess) 
	{
		(void)Rte_Call_RP_Nvm_PCBASerialNumberDataIdentifier_SetRamBlockStatus(TRUE);
			  
		*ErrorCode = E_OK;
	    u_RetVal = E_OK;
	}
	else 
	{
		if ((uint8) DCM_E_PENDING == u_RetVal)
		{
			*ErrorCode = DCM_E_REQUESTCORRECTLYRECEIVEDRESPONSEPENDING;//NRC78
		} 
		else 
		{
			if (FALSE == b_NvmOperationPending) 
			{
				(void)Rte_Call_RP_Nvm_PCBASerialNumberDataIdentifier_SetRamBlockStatus(TRUE);
			}
		}
	}
#endif
			  
	  return u_RetVal;

} /* FUNC(Std_ReturnType, RTE_CODE) Dsm_u_WDBI_PCBASerialNumberDataIdentifier_Write (P2CONST(uint8, AUTOMATIC, RTE_APPL_DATA) Data, Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_APPL_DATA) ErrorCode) */
#endif

/**
 * \functions Dsm_u_WDBI_InternalTestMode_Write
 *
 * \brief Write internal test mode from RAM.(FDFF)
 *
 ** \param[in] OpStatus, 
 *
 ** \param[out] Data, Pointer to Data buffer (1 bytes).
 **                  unsigned formatted
 *
 ** \return RTE_E_OK, 
 * \comments  
 *
 */
#if (DSM_FEAT_WDBI_InternalTestMode == STD_ON)
FUNC(Std_ReturnType, RTE_CODE) Dsm_u_WDBI_InternalTestMode_Write (P2CONST(uint8, AUTOMATIC, RTE_APPL_DATA) Data, Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_APPL_DATA) ErrorCode)
{
    /* suppress compiler warnings about unused arguments */
	Std_ReturnType u_Retval = RTE_E_OK;
	(void)OpStatus;
	(void)*ErrorCode;
		
#if((DSM_SYSTEM_TYPE == DSM_SYSTEM_MFC5J3_C673)|| \
									  (DSM_SYSTEM_TYPE == DSM_SYSTEM_MFC5J3_C385)) 
	
	uint8 ui8_Writedata = 0U;
	
	if(Data[0] == DSM_INTERNALTESTMODE_ON) //0x42, Enter to internal test mode, support XCP write
	{
		ui8_Writedata = DSM_INTERNALTESTMODE_ON;
		Xcp_SetTransmissionMode(0, XCP_TX_ON);		
	}
	else
	{
		ui8_Writedata = DSM_INTERNALTESTMODE_OFF;
		Xcp_SetTransmissionMode(0, XCP_TX_OFF);		
	}
	
	(void)Rte_Write_PP_Dsm_SRI_InternalTestMode_DE_InternalTestMode(ui8_Writedata);
		
	(void)Rte_IrvWrite_Dsm_u_WDBI_InternalTestMode_Write_Dsm_IRV_InternalTestMode(ui8_Writedata);
#endif
	
	return u_Retval;

} /* FUNC(Std_ReturnType, RTE_CODE) Dsm_u_WDBI_InternalTestMode_Write (P2CONST(uint8, AUTOMATIC, RTE_APPL_DATA) Data, Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_APPL_DATA) ErrorCode) */
#endif

/**
 * \functions Dsm_u_WDBI_CalibrationDataIdentifier_Write
 *
 * \brief Write calibration data identifier to RAM .(F123)
 *
 ** \param[in] none,
 *
 ** \param[out] Data, Pointer to Data buffer (20 bytes).
 **                  ASCII formatted
 *
 ** \return RTE_E_OK, 
 * \comments  
 *
 */
#if (DSM_FEAT_WDBI_CalibrationDataIdentifier == STD_ON)
FUNC(Std_ReturnType, RTE_CODE) Dsm_u_WDBI_CalibrationDataIdentifier_Write (P2CONST(uint8, AUTOMATIC, RTE_APPL_DATA) Data, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_APPL_DATA) ErrorCode)
{
  /* suppress compiler warnings about unused arguments */
  (void)Data;
  (void)*ErrorCode;
  return RTE_E_OK;
} /* FUNC(Std_ReturnType, RTE_CODE) Dsm_u_WDBI_CalibrationDataIdentifier_Write (P2CONST(uint8, AUTOMATIC, RTE_APPL_DATA) Data, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_APPL_DATA) ErrorCode) */
#endif

/**
 * \functions Dsm_u_WDBI_EOL_CustomerCodeConfig_Write
 *
 * \brief Write customer coding from specific DF static Address.(xxxx)
 *
 ** \param[in] none,
 *
 ** \param[out] Data, Pointer to Data buffer (4 bytes).
 **                  ASCII formatted
 *
 ** \return RTE_E_OK, 
 * \comments  base Address:0xAF07B000 startAddress: 0xAF07B0xxx  Total Length: 2byte
 *
 */
#if (DSM_FEAT_WDBI_CustomerCodeConfig == STD_ON)
FUNC(Std_ReturnType, RTE_CODE) Dsm_u_WDBI_CustomerCodeConfig_Write (P2CONST(uint8, AUTOMATIC, RTE_APPL_DATA) Data, Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_APPL_DATA) ErrorCode)
{
    /* suppress compiler warnings about unused arguments */
	Std_ReturnType u_Retval = RTE_E_OK;
	  
#if((DSM_SYSTEM_TYPE == DSM_SYSTEM_MFC5J3_C673)|| \
					(DSM_SYSTEM_TYPE == DSM_SYSTEM_MFC5J3_C385))  
	static boolean b_WriteFlagSuccess;
	static uint8 ui8_QsmReqStatus = QSM_REQRESULT_NOT_OK;
	  
	if((uint8)DCM_INITIAL == OpStatus)
	{
	    b_WriteFlagSuccess = FALSE;

		if(0x00u != (Data[0] & 0x01u)) //bit0
		{
			WR_AEB_FUNCT_ACTIVATED
		}
		else
		{
            WR_AEB_FUNCT_NOT_ACTIVATED 
		}

		if(0x00u != (Data[0] & 0x02u) //bit1
		{
			WR_ACC_FUNCT_ACTIVATED
		}
		else
		{
            WR_ACC_FUNCT_NOT_ACTIVATED 
		}

        if(0x00u != (Data[0] & 0x04u) //bit2
		{
			WR_LCF_FUNCT_ACTIVATED
		}
		else
		{
            WR_LCF_FUNCT_NOT_ACTIVATED 
		}
		
		if(0x00u != (Data[0] & 0x08u) //bit3
		{
			WR_ELK_FUNCT_ACTIVATED
		}
		else
		{
            WR_ELK_FUNCT_NOT_ACTIVATED 
		}

        if(0x00u != (Data[0] & 0x10u) //bit4
		{
			WR_HLA_FUNCT_ACTIVATED
		}
		else
		{
            WR_HLA_FUNCT_NOT_ACTIVATED 
		}

		if(0x00u != (Data[2] & 0x01u) //bit20
		{
			WR_PERCEPTION_FUNCT_ACTIVATED
		}
		else
		{
            WR_PERCEPTION_FUNCT_NOT_ACTIVATED 
		}

		if(0x00u != (Data[2] & 0x02u) //bit21
		{
			WR_FUNSION_FUNCT_ACTIVATED
		}
		else
		{
            WR_FUNSION_FUNCT_NOT_ACTIVATED 
		}

		if(0x00u != (Data[3] & 0x01u) //bit24
		{
			WR_CSL_FUNCT_ACTIVATED
		}
		else
		{
            WR_CSL_FUNCT_NOT_ACTIVATED 
		}
		
		if(0x00u != (Data[3] & 0x02u) //bit25
		{
			WR_XCP_FUNCT_ACTIVATED
		}
		else
		{
            WR_XCP_FUNCT_NOT_ACTIVATED 
		}
		
		if(0x00u != (Data[3] & 0x04u) //bit26
		{
			WR_MTS_FUNCT_ACTIVATED
		}
		else
		{
            WR_MTS_FUNCT_NOT_ACTIVATED 
		}

		if(0x00u != (Data[3] & 0x08u) //bit27
		{
			WR_DBM_FUNCT_ACTIVATED
		}
		else
		{
            WR_DBM_FUNCT_NOT_ACTIVATED 
		}

		if(0x00u != (Data[3] & 0x10u) //bit28
		{
			WR_PRT_FUNCT_ACTIVATED
		}
		else
		{
            WR_PRT_FUNCT_NOT_ACTIVATED 
		}

		if(0x00u != (Data[3] & 0x20u) //bit29
		{
			WR_FIT_FUNCT_ACTIVATED
		}
		else
		{
            WR_FIT_FUNCT_NOT_ACTIVATED 
		}

		if(0x00u != (Data[3] & 0x40u) //bit30
		{
			WR_RTM_FUNCT_ACTIVATED
		}
		else
		{
            WR_RTM_FUNCT_NOT_ACTIVATED 
		}

		if(0x00u != (Data[3] & 0x80u) //bit31
		{
			WR_FIM_FUNCT_NOT_ACTIVATED
		}
		else
		{
            WR_FIM_FUNCT_ACTIVATED 
		}
		
	    (void)Rte_Call_RP_Qsm_Block_EOLModeGateOP_Qsm_WriteBlock(&s_QSBlock_EcuSpecInfo);

		ui8_QsmReqStatus = Rte_Call_RP_Qsm_Block_EOLModeGateOP_Qsm_GetErrorStatues();
		
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
	    ui8_QsmReqStatus = Rte_Call_RP_Qsm_Block_EOLModeGateOP_Qsm_GetErrorStatues();
		
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
			 /*Do nothing*/
		}
	}
#endif
  
	 return u_Retval;
} /* FUNC(Std_ReturnType, RTE_CODE) Dsm_u_WDBI_CustomerCodeConfig_Write (P2CONST(uint8, AUTOMATIC, RTE_APPL_DATA) Data, Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_APPL_DATA) ErrorCode) */
#endif

/**
 * \functions Dsm_u_WDBI_ECUOperationMode_Write
 *
 * \brief Write Ecu Operation mode gate from specific DF static Address.(F1FD)
 *
 ** \param[in] none,
 *
 ** \param[out] Data, Pointer to Data buffer (1 bytes).
 **                  ASCII formatted
 *
 ** \return RTE_E_OK, 
 * \comments  base Address:0xAF07B000 startAddress: 0xAF07B028  Total Length: 2byte
 *
 */
#if (DSM_FEAT_WDBI_ECUOperationMode == STD_ON)
FUNC(Std_ReturnType, RTE_CODE) Dsm_u_WDBI_ECUOperationMode_Write (P2CONST(uint8, AUTOMATIC, RTE_APPL_DATA) Data, Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_APPL_DATA) ErrorCode)
{
    /* suppress compiler warnings about unused arguments */
	Std_ReturnType u_Retval = RTE_E_OK;
	  
#if((DSM_SYSTEM_TYPE == DSM_SYSTEM_MFC5J3_C673)|| \
					(DSM_SYSTEM_TYPE == DSM_SYSTEM_MFC5J3_C385))  
	static boolean b_WriteFlagSuccess;
	static uint8 ui8_QsmReqStatus = QSM_REQRESULT_NOT_OK;
	  
	if((uint8)DCM_INITIAL == OpStatus)
	{
	    b_WriteFlagSuccess = FALSE;
        /*SWRS_MFC5J3_SysM_21: The Ecu Operation Mode request via diagnostic service sent to Mcu.*/
		if(Data[0] < 0x05u) 
		{  
		    /* PRQA S 0314 2 */ /* Pointer to void, no problem */
		    Rte_Enter_DSM_EXCLUSIVEAREA();
            /*SWRS_MFC5J3_SysM_22: When Ecu is running,the external Mode Switch Request shall be stored in NvM.*/
			(void)TS_MemCpy((void*)&s_QSBlock_EcuSpecInfo.OperationMode, (void*)Data, ECUOPERATIONMODE_LEN);

			Rte_Exit_DSM_EXCLUSIVEAREA();
			
	        (void)Rte_Call_RP_Qsm_Block_EOLModeGateOP_Qsm_WriteBlock(&s_QSBlock_EcuSpecInfo);

		    ui8_QsmReqStatus = Rte_Call_RP_Qsm_Block_EOLModeGateOP_Qsm_GetErrorStatues();
		
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
		else
		{
		    *ErrorCode = DCM_E_REQUESTOUTOFRANGE; //NRC31
		    u_Retval = RTE_E_INVALID;
		} 
    }
	else if((uint8)DCM_PENDING == OpStatus)
	{
	    ui8_QsmReqStatus = Rte_Call_RP_Qsm_Block_EOLModeGateOP_Qsm_GetErrorStatues();
		
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
			 /*Do nothing*/
		}
	}
#endif
  
	 return u_Retval;
} /* FUNC(Std_ReturnType, RTE_CODE) Dsm_u_WDBI_ECUOperationMode_Write (P2CONST(uint8, AUTOMATIC, RTE_APPL_DATA) Data, Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_APPL_DATA) ErrorCode) */
#endif

/**
 * \functions Dsm_u_WDBI_CustomerVariant_Write
 *
 * \brief Write Customer variants from specific DF static Address.(xxxx)
 *
 ** \param[in] none,
 *
 ** \param[out] Data, Pointer to Data buffer (1 bytes).
 **                  ASCII formatted
 *
 ** \return RTE_E_OK, 
 * \comments  base Address:0xAF07B000 startAddress: 0xAF07B028  Total Length: 2byte
 *
 */
#if (DSM_FEAT_WDBI_CustomerVariant == STD_ON)
FUNC(Std_ReturnType, RTE_CODE) Dsm_u_WDBI_CustomerVariant_Write (P2CONST(uint8, AUTOMATIC, RTE_APPL_DATA) Data, Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_APPL_DATA) ErrorCode)
{
    /* suppress compiler warnings about unused arguments */
	Std_ReturnType u_Retval = RTE_E_OK;
	  
#if((DSM_SYSTEM_TYPE == DSM_SYSTEM_MFC5J3_C673)|| \
					(DSM_SYSTEM_TYPE == DSM_SYSTEM_MFC5J3_C385))  
	static boolean b_WriteFlagSuccess;
	static uint8 ui8_QsmReqStatus = QSM_REQRESULT_NOT_OK;
	  
	if((uint8)DCM_INITIAL == OpStatus)
	{
	    b_WriteFlagSuccess = FALSE;

		if((0x01u == Data[0]) ||(0x02u == Data[0]) || (0x04u == Data[0]) || (0x08 == Data[0])) 
		{  
		    /* PRQA S 0314 2 */ /* Pointer to void, no problem */
		    Rte_Enter_DSM_EXCLUSIVEAREA();

			(void)TS_MemCpy((void*)&s_QSBlock_EcuSpecInfo.VehSpecVar, (void*)Data, CUSTOMERVAR_LEN);

			Rte_Exit_DSM_EXCLUSIVEAREA();
			
	        (void)Rte_Call_RP_Qsm_Block_EOLModeGateOP_Qsm_WriteBlock(&s_QSBlock_EcuSpecInfo);

		    ui8_QsmReqStatus = Rte_Call_RP_Qsm_Block_EOLModeGateOP_Qsm_GetErrorStatues();
		
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
		else
		{
		    *ErrorCode = DCM_E_REQUESTOUTOFRANGE; //NRC31
		    u_Retval = RTE_E_INVALID;
		} 
    }
	else if((uint8)DCM_PENDING == OpStatus)
	{
	    ui8_QsmReqStatus = Rte_Call_RP_Qsm_Block_EOLModeGateOP_Qsm_GetErrorStatues();
		
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
			 /*Do nothing*/
		}
	}
#endif
  
	 return u_Retval;
} /* FUNC(Std_ReturnType, RTE_CODE) Dsm_u_WDBI_ECUOperationMode_Write (P2CONST(uint8, AUTOMATIC, RTE_APPL_DATA) Data, Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_APPL_DATA) ErrorCode) */
#endif

/**
 * \functions Dsm_u_WDBI_SocResetControl_Write
 *
 * \brief Write Soc reset control state to RAM.(FD00)
 *
 ** \param[in] OpStatus, 
 *
 ** \param[out] Data, Pointer to Data buffer (1 bytes).
 **                  unsigned formatted
 *
 ** \return RTE_E_OK, 
 * \comments  
 *
 */
#if (DSM_FEAT_WDBI_SocResetControl == STD_ON)
FUNC(Std_ReturnType, RTE_CODE) Dsm_u_WDBI_SocResetControl_Write (P2CONST(uint8, AUTOMATIC, RTE_APPL_DATA) Data, Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_APPL_DATA) ErrorCode)
{
    /* suppress compiler warnings about unused arguments */
    (void)OpStatus;
    Std_ReturnType u_Retval = RTE_E_OK;
          
#if((DSM_SYSTEM_TYPE == DSM_SYSTEM_MFC5J3_C673)|| \
                        (DSM_SYSTEM_TYPE == DSM_SYSTEM_MFC5J3_C385))
    if((0x00u == Data[0]) || (0x01u == Data[0]))
    {
        Rte_IrvWrite_Dsm_u_WDBI_SocResetControl_Write_Dsm_IRV_SocResetControlState(Data[0]);
        (void)Rte_Write_PP_Dsm_SRI_SocResetControlState_DE_SocRersetControlState(Data[0]);
    }
    else
    {
        *ErrorCode = DCM_E_REQUESTOUTOFRANGE; //NRC31
		 u_Retval = RTE_E_INVALID; 
    }
#endif

    return u_Retval;
} /* FUNC(Std_ReturnType, RTE_CODE) Dsm_u_WDBI_SocResetControl_Write (P2CONST(uint8, AUTOMATIC, RTE_APPL_DATA) Data, Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_APPL_DATA) ErrorCode) */
#endif

/**
 * \functions Dsm_u_WDBI_Fusa_Debug_Status_Write
 *
 * \brief Clear NVM Log Data
 *
 ** \param[in] none,
 *
 ** \param[out] Data, Pointer to Data buffer (1 bytes).
 **                  
 *
 ** \return RTE_E_OK, 
 * \comments  
 *
 */
#if (DSM_FEAT_WDBI_Fusa_Debug_Status == STD_ON)
FUNC(Std_ReturnType, RTE_CODE) Dsm_u_WDBI_Fusa_Debug_Status_Write (P2CONST(uint8, AUTOMATIC, RTE_APPL_DATA) Data, Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_APPL_DATA) ErrorCode)
{
   /* suppress compiler warnings about unused arguments */
	Std_ReturnType u_RetVal = RTE_E_OK;

#if((DSM_SYSTEM_TYPE == DSM_SYSTEM_MFC5J3_C673)|| \
							  (DSM_SYSTEM_TYPE == DSM_SYSTEM_MFC5J3_C385))	

	Std_ReturnType ui8_RetVal_Write = RTE_E_INVALID;
	Std_ReturnType ui8_RetVal_ErrStat = RTE_E_INVALID;
	NvM_RequestResultType ui8_WriteStatus = NVM_REQ_NOT_OK;			  
	boolean b_NvmOperationPending = FALSE;
	static boolean b_WriteFlagSuccess;

	if ((uint8) DCM_INITIAL == OpStatus) 
	{
		b_WriteFlagSuccess = FALSE;

		/*Service for setting the lock status of a permanent RAM block of an NVRAM block.*/
		Rte_Call_RP_Nvm_FS_Debug_Status_SetRamBlockStatus(FALSE);			
		/* PRQA S 0314 ++ */ /* P2Obj to P2void conversion is safe */
		//Rte_Enter_DSM_EXCLUSIVEAREA();

		(void)TS_MemCpy((void*)&RAM_BLOCK_FS_DEBUG, (const void*)Data, FSDEBUG_LEN);

		//Rte_Exit_DSM_EXCLUSIVEAREA();

		ui8_RetVal_Write = Rte_Call_RP_Nvm_FS_Debug_Status_WriteBlock((void*) &RAM_BLOCK_FS_DEBUG);	

		if ((uint8) E_OK == ui8_RetVal_Write) 
		{
			ui8_RetVal_ErrStat =  Rte_Call_RP_Nvm_FS_Debug_Status_GetErrorStatus(&ui8_WriteStatus);

			if ((uint8) E_OK == ui8_RetVal_ErrStat)
			{
				if ((uint8) NVM_REQ_OK == ui8_WriteStatus) 
				{
					b_WriteFlagSuccess = TRUE;
				}
				else if ((uint8) NVM_REQ_PENDING == ui8_WriteStatus)
				{
					u_RetVal = DCM_E_PENDING;
				} 
				else 
				{
					u_RetVal = RTE_E_INVALID;
					*ErrorCode = DCM_E_GENERALPROGRAMMINGFAILURE;
				}
			} 
			else 
			{
				u_RetVal = RTE_E_INVALID;
				*ErrorCode = DCM_E_GENERALPROGRAMMINGFAILURE;
			}
		}
		else 
		{
			u_RetVal = RTE_E_INVALID;
			*ErrorCode = DCM_E_GENERALPROGRAMMINGFAILURE;
		}
	}
	else if ((uint8) DCM_PENDING == OpStatus) 
	{
		ui8_RetVal_ErrStat = Rte_Call_RP_Nvm_FS_Debug_Status_GetErrorStatus(&ui8_WriteStatus);

		if ((uint8) E_OK == ui8_RetVal_ErrStat)
		{
			if ((uint8) NVM_REQ_OK == ui8_WriteStatus) 
			{
				b_WriteFlagSuccess = TRUE;
			} 
			else if ((uint8) NVM_REQ_PENDING == ui8_WriteStatus) 
			{
				u_RetVal = DCM_E_PENDING;
			} 
			else
			{
				u_RetVal = RTE_E_INVALID;
				*ErrorCode = DCM_E_GENERALPROGRAMMINGFAILURE;
			}
		} 
		else 
		{
			u_RetVal = RTE_E_INVALID;
			*ErrorCode = DCM_E_GENERALPROGRAMMINGFAILURE;
		}
	}
	else if ((uint8) DCM_CANCEL == OpStatus) 
	{
		(void)Rte_Call_RP_Nvm_FS_Debug_Status_GetErrorStatus(&ui8_WriteStatus);

		if ((uint8) NVM_REQ_PENDING == ui8_WriteStatus) 
		{
		    ui8_RetVal_ErrStat = NvM_CancelJobs(NvMConf_NvMBlockDescriptor_NvM_BLOCK_FS_Debug_Status);

			b_NvmOperationPending = TRUE;

			if ((uint8) E_OK == ui8_RetVal_ErrStat) 
			{
				*ErrorCode = E_OK;
				u_RetVal = E_OK;
			} 
			else 
			{
				u_RetVal = RTE_E_INVALID;
				*ErrorCode = DCM_E_GENERALPROGRAMMINGFAILURE;
			}
		} 
		else 
		{
			*ErrorCode = E_OK;
			u_RetVal = E_OK;
		}

		b_WriteFlagSuccess = FALSE;
	} 
	else 
	{
		*ErrorCode = DCM_E_CONDITIONSNOTCORRECT;
		u_RetVal = RTE_E_INVALID;
	}

	if (TRUE == b_WriteFlagSuccess) 
	{
		(void)Rte_Call_RP_Nvm_FS_Debug_Status_SetRamBlockStatus(TRUE);	

		*ErrorCode = E_OK;
		u_RetVal = E_OK;
	}
	else 
	{
		if ((uint8) DCM_E_PENDING == u_RetVal)
		{
			*ErrorCode = DCM_E_REQUESTCORRECTLYRECEIVEDRESPONSEPENDING;
		} 
		else 
		{
			if (FALSE == b_NvmOperationPending) 
			{
				(void)Rte_Call_RP_Nvm_FS_Debug_Status_SetRamBlockStatus(TRUE);
			}
		}
	}
#endif

	return u_RetVal;
} /* FUNC(Std_ReturnType, RTE_CODE) Dsm_u_WDBI_Fusa_Debug_Status_Write (P2CONST(uint8, AUTOMATIC, RTE_APPL_DATA) Data, Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_APPL_DATA) ErrorCode) */
#endif

#if(DSM_FEAT_MEMMAP_EB_IS_USED == STD_ON)
    #define Dsm_STOP_SEC_CODE
    #include <Dsm_MemMap.h> /* PRQA S 5087 */
#endif

/*==================[internal function definitions]=========================*/









