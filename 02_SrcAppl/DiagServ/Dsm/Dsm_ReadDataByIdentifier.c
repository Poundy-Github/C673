/**
 * \file   Dsm_ReadDataByIdentifier.c
 *
 * \brief  UDS ReadDataByIdentifier service(22)
 *
 * \version refer the Rte_Dsm.h.
 * 
 * \copyright  2021 - 2022 Conti Smart Core
 *
 */
/*==================[inclusions]============================================*/
#include <Rte_Dsm.h> /* PRQA S 0380,2 # 2023-06-13 Z.J.L: 0380: Number of macro definitions exceeds 4095 - program does not conform strictly to ISO:C99. 0380: accept */
#include "Dsm_Cfg.h"
#include "Dsm_Main.h"
#include "VerInfo.h"
#include "Cdm.h"
#include "Sdc_SendInterface.h"
#include "fs_adc.h"
#include "Qsm_Lcfg.h"
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
 * \functions Dsm_u_RDBI_NetworkInformationDataIdentifier_Read
 *
 * \brief Read Network information from ROM.(F120)
 *
 ** \param[in] none,
 *
 ** \param[out] Data, Pointer to Data buffer (4 bytes).
 **                  ASCII formatted
 *
 ** \return RTE_E_OK, 
 * \comments
 *
 */
#if (DSM_FEAT_RDBI_NetworkInformationDataIdentifier == STD_ON)
FUNC(Std_ReturnType, RTE_CODE) Dsm_u_RDBI_NetworkInformationDataIdentifier_Read (P2VAR(uint8, AUTOMATIC, RTE_APPL_DATA) Data)/* PRQA S 03432,2 # 2023-06-13 Z.J.L: 3432: Simple macro argument expression is not parenthesized. 03432: Gnenerate by Rte,check it ok */
{
    /* suppress compiler warnings about unused arguments */
    Std_ReturnType u_RetVal = RTE_E_INVALID;

#if((DSM_SYSTEM_TYPE == DSM_SYSTEM_MFC5J3_C673)|| \
    (DSM_SYSTEM_TYPE == DSM_SYSTEM_MFC5J3_C385))
    if(NULL_PTR != Data)
    {
        TS_MemCpy(&Data[0], s_ReleaseVariables.a_NetworkInformationDataIdentifier, sizeof(s_ReleaseVariables.a_NetworkInformationDataIdentifier)); /* PRQA S 3469,2 # 2023-06-13 Z.J.L: 3469: This usage of a function-like macro looks like it could be replaced by an equivalent function call. 3469: defined by Bsw platform header,check it ok */
        u_RetVal = RTE_E_OK;
    }
    else
    {/*Do nothing*/}
#endif

    return u_RetVal;
} /* FUNC(Std_ReturnType, RTE_CODE) Dsm_u_RDBI_NetworkInformationDataIdentifier_Read (P2VAR(uint8, AUTOMATIC, RTE_APPL_DATA) Data) */
#endif

/**
 * \functions Dsm_u_RDBI_FunctionSpecificationDataIdentifier_Read
 *
 * \brief Read Function specification version from ROM.(F121)
 *
 ** \param[in] none,
 *
 ** \param[out] Data, Pointer to Data buffer (4 bytes).
 **                  ASCII formatted
 *
 ** \return RTE_E_OK, 
 * \comments
 *
 */
#if (DSM_FEAT_RDBI_FunctionSpecificationDataIdentifier == STD_ON)
FUNC(Std_ReturnType, RTE_CODE) Dsm_u_RDBI_FunctionSpecificationDataIdentifier_Read (P2VAR(uint8, AUTOMATIC, RTE_APPL_DATA) Data)/* PRQA S 03432,2 # 2023-06-13 Z.J.L: 3432: Simple macro argument expression is not parenthesized. 03432: Gnenerate by Rte,check it ok */
{
    /* suppress compiler warnings about unused arguments */
    Std_ReturnType u_RetVal = RTE_E_INVALID;

 #if((DSM_SYSTEM_TYPE == DSM_SYSTEM_MFC5J3_C673)|| \
    (DSM_SYSTEM_TYPE == DSM_SYSTEM_MFC5J3_C385))   
    if(NULL_PTR != Data)
    {
        TS_MemCpy(&Data[0], s_ReleaseVariables.a_FunctionSpecificationDataIdentifier, sizeof(s_ReleaseVariables.a_FunctionSpecificationDataIdentifier)); /* PRQA S 3469,2 # 2023-06-13 Z.J.L: 3469: This usage of a function-like macro looks like it could be replaced by an equivalent function call. 3469: defined by Bsw platform header,check it ok */
        u_RetVal = RTE_E_OK;
    }
    else
    {/*Do nothing*/}
#endif

    return u_RetVal;
} /* FUNC(Std_ReturnType, RTE_CODE) Dsm_u_RDBI_FunctionSpecificationDataIdentifier_Read (P2VAR(uint8, AUTOMATIC, RTE_APPL_DATA) Data) */
#endif

/**
 * \functions Dsm_u_RDBI_DiagnosticDefinitionDataIdentifier_Read
 *
 * \brief Read Diagnostic definition version infomation from ROM.(F122)
 *
 ** \param[in] none,
 *
 ** \param[out] Data, Pointer to Data buffer (4 bytes).
 **                  ASCII formatted
 *
 ** \return RTE_E_OK, 
 * \comments
 *
 */
#if (DSM_FEAT_RDBI_DiagnosticDefinitionDataIdentifier == STD_ON)
FUNC(Std_ReturnType, RTE_CODE) Dsm_u_RDBI_DiagnosticDefinitionDataIdentifier_Read (P2VAR(uint8, AUTOMATIC, RTE_APPL_DATA) Data)/* PRQA S 03432,2 # 2023-06-13 Z.J.L: 3432: Simple macro argument expression is not parenthesized. 03432: Gnenerate by Rte,check it ok */
{
    /* suppress compiler warnings about unused arguments */
    Std_ReturnType u_RetVal = RTE_E_INVALID;

 #if((DSM_SYSTEM_TYPE == DSM_SYSTEM_MFC5J3_C673)|| \
    (DSM_SYSTEM_TYPE == DSM_SYSTEM_MFC5J3_C385))
    if(NULL_PTR != Data)
    {
        TS_MemCpy(&Data[0], s_ReleaseVariables.a_DiagnosticDefinitionDataIdentifier, sizeof(s_ReleaseVariables.a_DiagnosticDefinitionDataIdentifier)); /* PRQA S 3469,2 # 2023-06-13 Z.J.L: 3469: This usage of a function-like macro looks like it could be replaced by an equivalent function call. 3469: defined by Bsw platform header,check it ok */
        u_RetVal = RTE_E_OK;
    }
    else
    {/*Do nothing*/}
#endif

    return u_RetVal;
} /* FUNC(Std_ReturnType, RTE_CODE) Dsm_u_RDBI_DiagnosticDefinitionDataIdentifier_Read (P2VAR(uint8, AUTOMATIC, RTE_APPL_DATA) Data) */
#endif

/**
 * \functions Dsm_u_RDBI_PartNumberDataIdentifier_Read
 *
 * \brief Read part number data identifier from specific DF static Address.(F187)
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
#if (DSM_FEAT_RDBI_ECUPartNumber == STD_ON)
FUNC(Std_ReturnType, RTE_CODE) Dsm_u_RDBI_PartNumberDataIdentifier_Read (Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_APPL_DATA) Data)/* PRQA S 03432,2 # 2023-06-13 Z.J.L: 3432: Simple macro argument expression is not parenthesized. 03432: Gnenerate by Rte,check it ok */
{
		/* suppress compiler warnings about unused arguments */
		Std_ReturnType u_RetVal = RTE_E_OK;
		
#if((DSM_SYSTEM_TYPE == DSM_SYSTEM_MFC5J3_C673)|| \
				  (DSM_SYSTEM_TYPE == DSM_SYSTEM_MFC5J3_C385))		
		Std_ReturnType ui8_RetVal_Read = E_NOT_OK; 
		static uint8 ui8_QsmReqStatus = QSM_REQRESULT_NOT_OK;
		static boolean b_ReadFlagSuccess;
		
		if((uint8)DCM_INITIAL == OpStatus)
		{
			b_ReadFlagSuccess = (boolean)FALSE;

			ui8_RetVal_Read = Rte_Call_RP_Qsm_BlockPartNumber_SectorOp_Qsm_ReadBlock((void*)&s_QSBlock_PartNumberSector, 0, sizeof(s_QSBlock_PartNumberSector));

			if(ui8_RetVal_Read == RTE_E_OK)
			{
                ui8_QsmReqStatus = Rte_Call_RP_Qsm_BlockPartNumber_SectorOp_Qsm_GetErrorStatues();
     		
		        if(QSM_REQRESULT_PENDING == ui8_QsmReqStatus)
	            {
		            u_RetVal = DCM_E_PENDING;
		        }
		        else if(QSM_REQRESULT_OK == ui8_QsmReqStatus)
		        {
			        b_ReadFlagSuccess = (boolean)TRUE;
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
		else if((uint8)DCM_PENDING == OpStatus)
		{
            ui8_QsmReqStatus = Rte_Call_RP_Qsm_BlockPartNumber_SectorOp_Qsm_GetErrorStatues();
     		
		    if(QSM_REQRESULT_PENDING == ui8_QsmReqStatus)
	        {
		        u_RetVal = DCM_E_PENDING;
		    }
		    else if(QSM_REQRESULT_OK == ui8_QsmReqStatus)
		    {
			    b_ReadFlagSuccess = (boolean)TRUE;
		    }
		    else
		    {
		        u_RetVal = RTE_E_INVALID;	
		    }			
		}
		else if((uint8)DCM_CANCEL == OpStatus)
		{
			b_ReadFlagSuccess = (boolean)FALSE;
			u_RetVal = RTE_E_INVALID;
		}
		else
		{
			/*Do nothing*/
		}
	
		if((boolean)TRUE == b_ReadFlagSuccess)
		{
			/* PRQA S 0314 2 */ /* Pointer to void, no problem */
			TS_MemCpy((void*)Data, (void*)s_QSBlock_PartNumberSector.F187, PARTNUMBER_LEN); /* PRQA S 3469,2 # 2023-06-13 Z.J.L: 3469: This usage of a function-like macro looks like it could be replaced by an equivalent function call. 3469: defined by Bsw platform header,check it ok */
			u_RetVal = RTE_E_OK;
		}
#endif
	
	  return u_RetVal;

} /* FUNC(Std_ReturnType, RTE_CODE) Dsm_u_RDBI_ECUPartNumber_Read (P2VAR(uint8, AUTOMATIC, RTE_APPL_DATA) Data) */
#endif

/**
 * \functions Dsm_u_RDBI_ECUSoftwareVersionNumberDataIdentifier_Read
 *
 * \brief Read ECU software version number from ROM.(F189)
 *
 ** \param[in] none,
 *
 ** \param[out] Data, Pointer to Data buffer (8 bytes).
 **                  ASCII formatted
 *
 ** \return RTE_E_OK, 
 * \comments
 *
 */
#if (DSM_FEAT_RDBI_ECUSoftwareVersionNumberDataIdentifier == STD_ON)
FUNC(Std_ReturnType, RTE_CODE) Dsm_u_RDBI_ECUSoftwareVersionNumberDataIdentifier_Read (P2VAR(uint8, AUTOMATIC, RTE_APPL_DATA) Data)/* PRQA S 03432,2 # 2023-06-13 Z.J.L: 3432: Simple macro argument expression is not parenthesized. 03432: Gnenerate by Rte,check it ok */
{
    /* suppress compiler warnings about unused arguments */
    Std_ReturnType u_RetVal = RTE_E_INVALID;

 #if((DSM_SYSTEM_TYPE == DSM_SYSTEM_MFC5J3_C673)|| \
    (DSM_SYSTEM_TYPE == DSM_SYSTEM_MFC5J3_C385))
    if(NULL_PTR != Data)
    {
        TS_MemCpy(&Data[0], s_ReleaseVariables.a_ECUSoftwareVersionNumberDataIdentifier, sizeof(s_ReleaseVariables.a_ECUSoftwareVersionNumberDataIdentifier)); /* PRQA S 3469,2 # 2023-06-13 Z.J.L: 3469: This usage of a function-like macro looks like it could be replaced by an equivalent function call. 3469: defined by Bsw platform header,check it ok */
        u_RetVal = RTE_E_OK;
    }
    else
    {/*Do nothing*/}
#endif

    return u_RetVal;
} /* FUNC(Std_ReturnType, RTE_CODE) Dsm_u_RDBI_ECUSoftwareVersionNumberDataIdentifier_Read (P2VAR(uint8, AUTOMATIC, RTE_APPL_DATA) Data) */
#endif

/**
 * \functions Dsm_u_RDBI_FBLVersionInformation_Read
 *
 * \brief Read FBL version information from the ROM of Boot.(F170)
 *
 ** \param[in] none,
 *
 ** \param[out] Data, Pointer to Data buffer (4 bytes).
 **                  ASCII formatted
 *
 ** \return RTE_E_OK, 
 * \comments
 *
 */
#if (DSM_FEAT_RDBI_FBLVersionInformation == STD_ON)
FUNC(Std_ReturnType, RTE_CODE) Dsm_u_RDBI_FBLVersionInformation_Read (P2VAR(uint8, AUTOMATIC, RTE_APPL_DATA) Data)/* PRQA S 03432,2 # 2023-06-13 Z.J.L: 3432: Simple macro argument expression is not parenthesized. 03432: Gnenerate by Rte,check it ok */
{
    /* suppress compiler warnings about unused arguments */
  	Std_ReturnType u_RetVal = RTE_E_INVALID;

 #if((DSM_SYSTEM_TYPE == DSM_SYSTEM_MFC5J3_C673)|| \
     (DSM_SYSTEM_TYPE == DSM_SYSTEM_MFC5J3_C385))
	if(NULL_PTR != Data)
	{
        TS_MemCpy((void*)Data, FBLVERSIONINFO_START_ADDRESS, FBLVERSIONINFO_LEN); /* PRQA S 0326,3469,7 2 # 2023-06-13 Z.J.L: 3469: This usage of a function-like macro looks like it could be replaced by an equivalent function call. 3469: defined by Bsw platform header,check it ok */
		u_RetVal = RTE_E_OK;
	}
	else
    {/*Do nothing*/}
#endif

    return u_RetVal;
} /* FUNC(Std_ReturnType, RTE_CODE) Dsm_u_RDBI_FBLVersionInformation_Read (P2VAR(uint8, AUTOMATIC, RTE_APPL_DATA) Data) */
#endif

/**
 * \functions Dsm_u_RDBI_FBLRequirementSpecification_Read
 *
 * \brief Read FBL Requirements specification the ROM of Boot.(F171)
 *
 ** \param[in] none,
 *
 ** \param[out] Data, Pointer to Data buffer (4 bytes).
 **                  ASCII formatted
 *
 ** \return RTE_E_OK, 
 * \comments
 *
 */
#if (DSM_FEAT_RDBI_FBLRequirementSpecification == STD_ON)
FUNC(Std_ReturnType, RTE_CODE) Dsm_u_RDBI_FBLRequirementSpecification_Read (P2VAR(uint8, AUTOMATIC, RTE_APPL_DATA) Data)/* PRQA S 03432,2 # 2023-06-13 Z.J.L: 3432: Simple macro argument expression is not parenthesized. 03432: Gnenerate by Rte,check it ok */
{
    /* suppress compiler warnings about unused arguments */
  	Std_ReturnType u_RetVal = RTE_E_INVALID;

 #if((DSM_SYSTEM_TYPE == DSM_SYSTEM_MFC5J3_C673)|| \
     (DSM_SYSTEM_TYPE == DSM_SYSTEM_MFC5J3_C385))
	if(NULL_PTR != Data)
	{
        TS_MemCpy((void*)Data, FBLREQUIREMENTSPEC_START_ADDRESS, FBLREQUIREMENTSPEC_LEN); /* PRQA S 0326,3469,2 # 2023-06-13 Z.J.L: 3469: This usage of a function-like macro looks like it could be replaced by an equivalent function call. 3469: defined by Bsw platform header,check it ok */
		u_RetVal = RTE_E_OK;
	}
	else
    {/*Do nothing*/}
#endif

    return u_RetVal;
} /* FUNC(Std_ReturnType, RTE_CODE) Dsm_u_RDBI_FBLRequirementSpecification_Read (P2VAR(uint8, AUTOMATIC, RTE_APPL_DATA) Data) */
#endif

/**
 * \functions Dsm_u_RDBI_SoftwareNumber_Read
 *
 * \brief Read software number from ROM .(F188)
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
#if (DSM_FEAT_RDBI_SoftwareNumber == STD_ON)
FUNC(Std_ReturnType, RTE_CODE) Dsm_u_RDBI_SoftwareNumber_Read (P2VAR(uint8, AUTOMATIC, RTE_APPL_DATA) Data)/* PRQA S 03432,2 # 2023-06-13 Z.J.L: 3432: Simple macro argument expression is not parenthesized. 03432: Gnenerate by Rte,check it ok */
{
    /* suppress compiler warnings about unused arguments */
    Std_ReturnType u_RetVal = RTE_E_INVALID;

 #if((DSM_SYSTEM_TYPE == DSM_SYSTEM_MFC5J3_C673)|| \
    (DSM_SYSTEM_TYPE == DSM_SYSTEM_MFC5J3_C385))
    if(NULL_PTR != Data)
    {
        TS_MemCpy(&Data[0],a_vehicleManufacturerECUSoftwareNumberDataIdentifier, sizeof(a_vehicleManufacturerECUSoftwareNumberDataIdentifier)); /* PRQA S 3469,2 # 2023-06-13 Z.J.L: 3469: This usage of a function-like macro looks like it could be replaced by an equivalent function call. 3469: defined by Bsw platform header,check it ok */
        u_RetVal = RTE_E_OK;
    }
    else
    {/*Do nothing*/}
#endif

    return u_RetVal;
} /* FUNC(Std_ReturnType, RTE_CODE) Dsm_u_RDBI_SoftwareNumber_Read (P2VAR(uint8, AUTOMATIC, RTE_APPL_DATA) Data) */
#endif

/**
 * \functions Dsm_u_RDBI_ECUHardwareVersionNumber_Read
 *
 * \brief Read ECU hardware version software number from ROM .(F191)
 *
 ** \param[in] none,
 *
 ** \param[out] Data, Pointer to Data buffer (9 bytes).
 **                  ASCII formatted
 *
 ** \return RTE_E_OK, 
 * \comments
 *
 */
#if (DSM_FEAT_RDBI_ECUHardwareVersionNumber == STD_ON)
FUNC(Std_ReturnType, RTE_CODE) Dsm_u_RDBI_ECUHardwareVersionNumber_Read (P2VAR(uint8, AUTOMATIC, RTE_APPL_DATA) Data)/* PRQA S 03432,2 # 2023-06-13 Z.J.L: 3432: Simple macro argument expression is not parenthesized. 03432: Gnenerate by Rte,check it ok */
{
    /* suppress compiler warnings about unused arguments */
    Std_ReturnType u_RetVal = RTE_E_INVALID;

 #if((DSM_SYSTEM_TYPE == DSM_SYSTEM_MFC5J3_C673)|| \
    (DSM_SYSTEM_TYPE == DSM_SYSTEM_MFC5J3_C385))
    if(NULL_PTR != Data)
    {
        TS_MemCpy(&Data[0], s_ReleaseVariables.a_ECUHardwareVersionNumber, sizeof(s_ReleaseVariables.a_ECUHardwareVersionNumber)); /* PRQA S 3469,2 # 2023-06-13 Z.J.L: 3469: This usage of a function-like macro looks like it could be replaced by an equivalent function call. 3469: defined by Bsw platform header,check it ok */
        u_RetVal = RTE_E_OK;
    }
    else
    {/*Do nothing*/}
#endif

    return u_RetVal;
} /* FUNC(Std_ReturnType, RTE_CODE) Dsm_u_RDBI_ECUHardwareVersionNumber_Read (P2VAR(uint8, AUTOMATIC, RTE_APPL_DATA) Data) */
#endif

/**
 * \functions Dsm_u_RDBI_ProjectID_Read
 *
 * \brief Read project id from ROM .(FD21)
 *
 ** \param[in] none,
 *
 ** \param[out] Data, Pointer to Data buffer (2 bytes).
 **                  unsigned formatted
 *
 ** \return RTE_E_OK, 
 * \comments
 *
 */
#if (DSM_FEAT_RDBI_ProjectID == STD_ON)
FUNC(Std_ReturnType, RTE_CODE) Dsm_u_RDBI_ProjectID_Read (P2VAR(uint8, AUTOMATIC, RTE_APPL_DATA) Data)/* PRQA S 03432,2 # 2023-06-13 Z.J.L: 3432: Simple macro argument expression is not parenthesized. 03432: Gnenerate by Rte,check it ok */
{
    /* suppress compiler warnings about unused arguments */
    Std_ReturnType u_RetVal = RTE_E_INVALID;

 #if((DSM_SYSTEM_TYPE == DSM_SYSTEM_MFC5J3_C673)|| \
    (DSM_SYSTEM_TYPE == DSM_SYSTEM_MFC5J3_C385))
    if(NULL_PTR != Data)
    {
        TS_MemCpy(&Data[0], s_ReleaseVariables.a_ProjectID, sizeof(s_ReleaseVariables.a_ProjectID)); /* PRQA S 3469,2 # 2023-06-13 Z.J.L: 3469: This usage of a function-like macro looks like it could be replaced by an equivalent function call. 3469: defined by Bsw platform header,check it ok */
        u_RetVal = RTE_E_OK;
    }
    else
    {/*Do nothing*/}
#endif

    return u_RetVal;
} /* FUNC(Std_ReturnType, RTE_CODE) Dsm_u_RDBI_ProjectID_Read (P2VAR(uint8, AUTOMATIC, RTE_APPL_DATA) Data) */
#endif

/**
 * \functions Dsm_u_RDBI_ECUInternalSoftwareVersionNumber_Read
 *
 * \brief Read ECU Internal software version number from ROM .(FD28)
 *
 ** \param[in] none,
 *
 ** \param[out] Data, Pointer to Data buffer (5 bytes).
 **                  unsigned formatted
 *
 ** \return RTE_E_OK, 
 * \comments
 *
 */
#if (DSM_FEAT_RDBI_ECUInternalSoftwareVersionNumber == STD_ON)
FUNC(Std_ReturnType, RTE_CODE) Dsm_u_RDBI_ECUInternalSoftwareVersionNumber_Read (P2VAR(uint8, AUTOMATIC, RTE_APPL_DATA) Data)/* PRQA S 03432,2 # 2023-06-13 Z.J.L: 3432: Simple macro argument expression is not parenthesized. 03432: Gnenerate by Rte,check it ok */
{
    /* suppress compiler warnings about unused arguments */
    Std_ReturnType u_RetVal = RTE_E_INVALID;

 #if((DSM_SYSTEM_TYPE == DSM_SYSTEM_MFC5J3_C673)|| \
    (DSM_SYSTEM_TYPE == DSM_SYSTEM_MFC5J3_C385))
    if(NULL_PTR != Data)
    {
        TS_MemCpy(&Data[0], s_ReleaseVariables.a_ECUInternalSoftwareVersionNumber, sizeof(s_ReleaseVariables.a_ECUInternalSoftwareVersionNumber)); /* PRQA S 3469,2 # 2023-06-13 Z.J.L: 3469: This usage of a function-like macro looks like it could be replaced by an equivalent function call. 3469: defined by Bsw platform header,check it ok */
        u_RetVal = RTE_E_OK;
    }
    else
    {/*Do nothing*/}
#endif

    return u_RetVal;
} /* FUNC(Std_ReturnType, RTE_CODE) Dsm_u_RDBI_ECUInternalSoftwareVersionNumber_Read (P2VAR(uint8, AUTOMATIC, RTE_APPL_DATA) Data) */
#endif

/**
 * \functions Dsm_u_RDBI_APPDownloadArea_ConditionCheck
 *
 * \brief Set calibration data identifier check condition.(F010)
 *
 ** \param[in] none,
 *
 ** \param[out] ErrorCode,
 *
 ** \return RTE_E_OK, 
 * \comments  
 *
 */
#if (DSM_FEAT_RDBI_APPDownloadArea_ConditionCheck == STD_ON)
FUNC(Std_ReturnType, RTE_CODE) Dsm_u_RDBI_APPDownloadArea_ConditionCheck (P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_APPL_DATA) ErrorCode)/* PRQA S 03432,2 # 2023-06-13 Z.J.L: 3432: Simple macro argument expression is not parenthesized. 03432: Gnenerate by Rte,check it ok */
{
    /* suppress compiler warnings about unused arguments */
	Std_ReturnType u_RetVal = RTE_E_INVALID;

 #if((DSM_SYSTEM_TYPE == DSM_SYSTEM_MFC5J3_C673)|| \
    (DSM_SYSTEM_TYPE == DSM_SYSTEM_MFC5J3_C385))
	e_VerInfo_BankType_t e_bank = VerInfo_BankType_Max;
	/* Total input data length check */
	e_bank = VerInfo_GetSoftwareBank();

    if((VerInfo_BankType_None > e_bank) || (VerInfo_BankType_Max < e_bank))
	{
		*ErrorCode = DCM_E_CONDITIONSNOTCORRECT; //return NRC22
		u_RetVal =  RTE_E_INVALID;
	}
	else
	{
		u_RetVal =  RTE_E_OK;
	}
#endif

	return u_RetVal;
} /* FUNC(Std_ReturnType, RTE_CODE) Dsm_u_RDBI_APPDownloadArea_ConditionCheck (P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_APPL_DATA) ErrorCode) */
#endif

/**
 * \functions Dsm_u_RDBI_APPDownloadArea_Read
 *
 * \brief Read APP download area from RAM.(F010)
 *
 ** \param[in] none,
 *
 ** \param[out] Data, Pointer to Data buffer (1 bytes).
 **                  ASCII formatted
 *
 ** \return RTE_E_OK, 
 * \comments  
 *
 */
#if (DSM_FEAT_RDBI_APPDownloadArea_Read == STD_ON)
FUNC(Std_ReturnType, RTE_CODE) Dsm_u_RDBI_APPDownloadArea_Read (P2VAR(uint8, AUTOMATIC, RTE_APPL_DATA) Data)/* PRQA S 03432,2 # 2023-06-13 Z.J.L: 3432: Simple macro argument expression is not parenthesized. 03432: Gnenerate by Rte,check it ok */
{
    /* suppress compiler warnings about unused arguments */
  	Std_ReturnType u_RetVal = RTE_E_INVALID;

#if((DSM_SYSTEM_TYPE == DSM_SYSTEM_MFC5J3_C673)|| \
    (DSM_SYSTEM_TYPE == DSM_SYSTEM_MFC5J3_C385))  
	e_VerInfo_BankType_t e_bank = VerInfo_BankType_Max;
	/* Total input data length check */
	e_bank = VerInfo_GetSoftwareBank();

	if(VerInfo_BankType_A == e_bank)
	{
		Data[0] = ((uint8)VerInfo_BankType_B);
  	    u_RetVal = RTE_E_OK;
	}
	else if(VerInfo_BankType_B == e_bank)
	{
		Data[0] = ((uint8)VerInfo_BankType_A);
        u_RetVal = RTE_E_OK;
	}
	else
	{
		Data[0] = 0xFF;
        u_RetVal = RTE_E_INVALID;
	}
#endif

    return u_RetVal;
} /* FUNC(Std_ReturnType, RTE_CODE) Dsm_u_RDBI_APPDownloadArea_Read (P2VAR(uint8, AUTOMATIC, RTE_APPL_DATA) Data) */
#endif

/**
 * \functions Dsm_u_RDBI_CalibrationDataIdentifier_Read
 *
 * \brief Read calibration data identifier from RAM .(F123)
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
#if (DSM_FEAT_RDBI_CalibrationDataIdentifier == STD_ON)
FUNC(Std_ReturnType, RTE_CODE) Dsm_u_RDBI_CalibrationDataIdentifier_Read (P2VAR(uint8, AUTOMATIC, RTE_APPL_DATA) Data)/* PRQA S 03432,2 # 2023-06-13 Z.J.L: 3432: Simple macro argument expression is not parenthesized. 03432: Gnenerate by Rte,check it ok */
{
    /* suppress compiler warnings about unused arguments */
#if((DSM_SYSTEM_TYPE == DSM_SYSTEM_MFC5J3_C673)|| \
    (DSM_SYSTEM_TYPE == DSM_SYSTEM_MFC5J3_C385))
    (void)TS_MemBZero(Data, 20); /* PRQA S 3469,2 # 2023-06-13 Z.J.L: 3469: This usage of a function-like macro looks like it could be replaced by an equivalent function call. 3469: defined by Bsw platform header,check it ok */
#endif

    return RTE_E_OK;
} /* FUNC(Std_ReturnType, RTE_CODE) Dsm_u_RDBI_CalibrationDataIdentifier_Read (P2VAR(uint8, AUTOMATIC, RTE_APPL_DATA) Data) */
#endif

/**
 * \functions Dsm_u_RDBI_MCU_BbankError_Read
 *
 * \brief Read A blank start up error from DF.(FD26)
 *
 ** \param[in] none,
 *
 ** \param[out] Data, Pointer to Data buffer (1 bytes).
 **                  Unsigned formatted
 *
 ** \return RTE_E_OK, 
 * \comments  
 *
 */
#if (DSM_FEAT_RDBI_MCU_AbankError == STD_ON)
FUNC(Std_ReturnType, RTE_CODE) Dsm_u_RDBI_MCU_AbankError_Read (P2VAR(uint8, AUTOMATIC, RTE_APPL_DATA) Data)/* PRQA S 03432,2 # 2023-06-13 Z.J.L: 3432: Simple macro argument expression is not parenthesized. 03432: Gnenerate by Rte,check it ok */
{
    /* suppress compiler warnings about unused arguments */
    Std_ReturnType u_RetVal = RTE_E_INVALID; 
#if((DSM_SYSTEM_TYPE == DSM_SYSTEM_MFC5J3_C673)|| \
		(DSM_SYSTEM_TYPE == DSM_SYSTEM_MFC5J3_C385))
	e_VerInfo_BankType_t e_bank = VerInfo_BankType_Max;

	uint64 const* address = A_BLANKSTARTUPABNORMAL_START_ADDRESS;/* PRQA S 0326,0317,2 # 2023-06-13 Z.J.L: 0317:Implicit conversion from a pointer to void to a pointer to object type. 0317: Read data from address,check it ok */

	e_bank = VerInfo_GetSoftwareBank();
	if(VerInfo_BankType_A == e_bank)
	{
		Cdm_v_BoardDisableECCCheck();
		if(*address != BKANKSTARTUPABNORMAL_FLAG)
		{
			Data[0] = 0x02u; 
		}
		else
		{
			Data[0] = 0x01u; //startup abnormal
		}
		Cdm_v_BoardEnableECCCheck();
        u_RetVal = RTE_E_OK;
	}
	else
	{
		Data[0] = 0x00u;
		u_RetVal = RTE_E_OK;
	}
#endif

	return u_RetVal;
} /* FUNC(Std_ReturnType, RTE_CODE) Dsm_u_RDBI_MCU_AbankError_Read (P2VAR(uint8, AUTOMATIC, RTE_APPL_DATA) Data) */
#endif

/**
 * \functions Dsm_u_RDBI_MCU_BbankError_Read
 *
 * \brief Read B blank start up error from DF.(FD27)
 *
 ** \param[in] none,
 *
 ** \param[out] Data, Pointer to Data buffer (1 bytes).
 **                  Unsigned formatted
 *
 ** \return RTE_E_OK, 
 * \comments  
 *
 */
#if (DSM_FEAT_RDBI_MCU_BbankError == STD_ON)
FUNC(Std_ReturnType, RTE_CODE) Dsm_u_RDBI_MCU_BbankError_Read (P2VAR(uint8, AUTOMATIC, RTE_APPL_DATA) Data)/* PRQA S 03432,2 # 2023-06-13 Z.J.L: 3432: Simple macro argument expression is not parenthesized. 03432: Gnenerate by Rte,check it ok */
{
	  /* suppress compiler warnings about unused arguments */
	  Std_ReturnType u_RetVal = RTE_E_INVALID; 
#if((DSM_SYSTEM_TYPE == DSM_SYSTEM_MFC5J3_C673)|| \
		  (DSM_SYSTEM_TYPE == DSM_SYSTEM_MFC5J3_C385))
	  e_VerInfo_BankType_t e_bank = VerInfo_BankType_Max;
  
	  uint64 const* address = B_BLANKSTARTUPABNORMAL_START_ADDRESS;/* PRQA S 0326,0317,2 # 2023-06-13 Z.J.L: 0317:Implicit conversion from a pointer to void to a pointer to object type. 0317: Read data from address,check it ok */
  
	  e_bank = VerInfo_GetSoftwareBank();
	  if(VerInfo_BankType_B == e_bank)
	  {
		  Cdm_v_BoardDisableECCCheck();
		  if(*address != BKANKSTARTUPABNORMAL_FLAG)
		  {
			  Data[0] = 0x02u; //startup normal
		  }
		  else
		  {
			  Data[0] = 0x01u; //startup abnormal
		  }
		  Cdm_v_BoardEnableECCCheck();
		  u_RetVal = RTE_E_OK;
	  }
	  else
	  {
		  Data[0] = 0x00u; //default value
		  u_RetVal = RTE_E_OK;	  
	  }
#endif
  
	  return u_RetVal;
} /* FUNC(Std_ReturnType, RTE_CODE) Dsm_u_RDBI_MCU_BbankError_Read (P2VAR(uint8, AUTOMATIC, RTE_APPL_DATA) Data) */
#endif

/**
 * \functions Dsm_u_RDBI_ActiveDiagnosticSessionDataIdentifier_Read
 *
 * \brief Read Active diagnostic session from RAM.(F186)
 *
 ** \param[in] none,
 *
 ** \param[out] Data, Pointer to Data buffer (1 bytes).
 **                  Unsigned formatted
 *
 ** \return RTE_E_OK, 
 * \comments  
 *
 */
#if (DSM_FEAT_RDBI_ActiveDiagnosticSessionDataIdentifier == STD_ON)
FUNC(Std_ReturnType, RTE_CODE) Dsm_u_RDBI_ActiveDiagnosticSessionDataIdentifier_Read (P2VAR(uint8, AUTOMATIC, RTE_APPL_DATA) Data)/* PRQA S 03432,2 # 2023-06-13 Z.J.L: 3432: Simple macro argument expression is not parenthesized. 03432: Gnenerate by Rte,check it ok */
{
    /* suppress compiler warnings about unused arguments */
    Std_ReturnType u_RetVal = RTE_E_OK;
#if((DSM_SYSTEM_TYPE == DSM_SYSTEM_MFC5J3_C673)|| \
		  (DSM_SYSTEM_TYPE == DSM_SYSTEM_MFC5J3_C385))	
    Dcm_SesCtrlType ui8_SesCtrlType;
	
    (void)Rte_Call_RP_Dcm_DCMServices_GetSesCtrlType(&ui8_SesCtrlType);
    
    Data[0] = ui8_SesCtrlType;
#endif

    return u_RetVal;
} /* FUNC(Std_ReturnType, RTE_CODE) Dsm_u_RDBI_ActiveDiagnosticSessionDataIdentifier_Read (P2VAR(uint8, AUTOMATIC, RTE_APPL_DATA) Data) */
#endif

/**
 * \functions Dsm_u_RDBI_ECUSupplierVoltage_Read
 *
 * \brief Read ECU supplier voltage from RAM.(11B5)
 *
 ** \param[in] none,
 *
 ** \param[out] Data, Pointer to Data buffer (1 bytes).
 **                  Unsigned formatted
 *
 ** \return RTE_E_OK, 
 * \comments  
 *
 */
#if (DSM_FEAT_RDBI_ECUSupplierVoltage == STD_ON)
FUNC(Std_ReturnType, RTE_CODE) Dsm_u_RDBI_ECUSupplierVoltage_Read (P2VAR(uint8, AUTOMATIC, RTE_APPL_DATA) Data)/* PRQA S 03432,2 # 2023-06-13 Z.J.L: 3432: Simple macro argument expression is not parenthesized. 03432: Gnenerate by Rte,check it ok */
{
    Std_ReturnType u_RetVal = RTE_E_OK;
	
#if((DSM_SYSTEM_TYPE == DSM_SYSTEM_MFC5J3_C673)|| \
			  (DSM_SYSTEM_TYPE == DSM_SYSTEM_MFC5J3_C385))	
    float32_t f32_BattVolt = 0.0f ;

	(void)Rte_Call_RP_EvAdc_GetValue_VMON_BATT_GetPhyValue(&f32_BattVolt);

    Data[0] = (uint8)((float32_t)((f32_BattVolt * 100.0f)/8.0f));

#endif

    return u_RetVal;
} /* FUNC(Std_ReturnType, RTE_CODE) Dsm_u_RDBI_ECUSupplierVoltage_Read (P2VAR(uint8, AUTOMATIC, RTE_APPL_DATA) Data) */
#endif

/**
 * \functions Dsm_u_RDBI_ECUTemperature_Read
 *
 * \brief Read PCBA temperature from RAM.(11B7)
 *
 ** \param[in] none,
 *
 ** \param[out] Data, Pointer to Data buffer (2 bytes).
 **                  Unsigned formatted
 *
 ** \return RTE_E_OK, 
 * \comments  
 *
 */
#if (DSM_FEAT_RDBI_ECUTemperature == STD_ON)
FUNC(Std_ReturnType, RTE_CODE) Dsm_u_RDBI_ECUTemperature_Read (P2VAR(uint8, AUTOMATIC, RTE_APPL_DATA) Data)/* PRQA S 03432,2 # 2023-06-13 Z.J.L: 3432: Simple macro argument expression is not parenthesized. 03432: Gnenerate by Rte,check it ok */
{
    /* suppress compiler warnings about unused arguments */
    Std_ReturnType u_RetVal = RTE_E_OK;
#if((DSM_SYSTEM_TYPE == DSM_SYSTEM_MFC5J3_C673)|| \
			  (DSM_SYSTEM_TYPE == DSM_SYSTEM_MFC5J3_C385))	  
    float32_t f_EcuTemperature = 0.0f;
    float32_t f32_SocTemp = 0.0f,f32_MCUTemp=0.0f;
	  
	(void)FSAdc_ReadChannel(FS_ADC_CHANNEL_TEMP_MCU_EXT, &f32_MCUTemp);
    (void)FSAdc_ReadChannel(FS_ADC_CHANNEL_TEMP_SOC_EXT, &f32_SocTemp);

    f_EcuTemperature = (f32_SocTemp + f32_MCUTemp) / 2.0f;
  
    if((f_EcuTemperature < DSM_ECUTEMP_MIN_THLSD)||(f_EcuTemperature > DSM_ECUTEMP_MAX_THLSD))
    {
        u_RetVal = RTE_E_INVALID; //return NRC10
    }
    else
    {	 
        Data[0] = (uint8)(((uint16)f_EcuTemperature >> 8) & ((uint8_t)0xFF));
	    Data[1] = (uint8)(((uint16)f_EcuTemperature) & ((uint8_t)0xFF));
	    u_RetVal = RTE_E_OK;
    }

#endif

    return u_RetVal;
} /* FUNC(Std_ReturnType, RTE_CODE) Dsm_u_RDBI_ECUTemperature_Read (P2VAR(uint8, AUTOMATIC, RTE_APPL_DATA) Data) */
#endif

/**
 * \functions Dsm_u_RDBI_ECUHardwareVersionNumberDataIdentifier_Read
 *
 * \brief Read ECU hardware version number data identifier from specific DF static Address.(F089)
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
#if (DSM_FEAT_RDBI_ECUHardwareVersionNumberDataIdentifier == STD_ON)
FUNC(Std_ReturnType, RTE_CODE) Dsm_u_RDBI_ECUHardwareVersionNumberDataIdentifier_Read (Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_APPL_DATA) Data)/* PRQA S 03432,2 # 2023-06-13 Z.J.L: 3432: Simple macro argument expression is not parenthesized. 03432: Gnenerate by Rte,check it ok */
{
    /* suppress compiler warnings about unused arguments */
    Std_ReturnType u_RetVal = RTE_E_OK;
	
#if((DSM_SYSTEM_TYPE == DSM_SYSTEM_MFC5J3_C673)|| \
			  (DSM_SYSTEM_TYPE == DSM_SYSTEM_MFC5J3_C385))			
    Std_ReturnType ui8_RetVal_Read = E_NOT_OK; 
	static uint8 ui8_QsmReqStatus = QSM_REQRESULT_NOT_OK;
	static boolean b_ReadFlagSuccess;
		
	if((uint8)DCM_INITIAL == OpStatus)
	{
		b_ReadFlagSuccess = (boolean)FALSE;

		ui8_RetVal_Read = Rte_Call_RP_Qsm_BlockPartNumber_SectorOp_Qsm_ReadBlock((void*)&s_QSBlock_PartNumberSector, 0, sizeof(s_QSBlock_PartNumberSector));

		if(ui8_RetVal_Read == RTE_E_OK)
		{
            ui8_QsmReqStatus = Rte_Call_RP_Qsm_BlockPartNumber_SectorOp_Qsm_GetErrorStatues();
     		
		    if(QSM_REQRESULT_PENDING == ui8_QsmReqStatus)
	        {
		        u_RetVal = DCM_E_PENDING;
		    }
		    else if(QSM_REQRESULT_OK == ui8_QsmReqStatus)
		    {
			    b_ReadFlagSuccess = (boolean)TRUE;
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
	else if((uint8)DCM_PENDING == OpStatus)
	{
        ui8_QsmReqStatus = Rte_Call_RP_Qsm_BlockPartNumber_SectorOp_Qsm_GetErrorStatues();
     		
		if(QSM_REQRESULT_PENDING == ui8_QsmReqStatus)
	    {
		    u_RetVal = DCM_E_PENDING;
		}
		else if(QSM_REQRESULT_OK == ui8_QsmReqStatus)
		{
			b_ReadFlagSuccess = (boolean)TRUE;
		}
		else
		{
		    u_RetVal = RTE_E_INVALID;	
		}			
    }
	else if((uint8)DCM_CANCEL == OpStatus)
	{
		b_ReadFlagSuccess = (boolean)FALSE;
		u_RetVal = RTE_E_INVALID;
	}
	else
	{
		/*Do nothing*/
	}

    if((boolean)TRUE == b_ReadFlagSuccess)
    {
        /* PRQA S 0314 2 */ /* Pointer to void, no problem */
        (void)TS_MemCpy((void*)Data, (void*)s_QSBlock_PartNumberSector.F089, ECUHWVERSNUMBER_LEN); /* PRQA S 3469,2 # 2023-06-13 Z.J.L: 3469: This usage of a function-like macro looks like it could be replaced by an equivalent function call. 3469: defined by Bsw platform header,check it ok */
        u_RetVal = RTE_E_OK;
	}
#endif

  return u_RetVal;
} /* FUNC(Std_ReturnType, RTE_CODE) Dsm_u_RDBI_ECUHardwareVersionNumberDataIdentifier_Read (Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_APPL_DATA) Data) */
#endif

/**
 * \functions Dsm_u_RDBI_ECUHardwareVersionNumberDataIdentifier_Read
 *
 * \brief Read System Supplier identifier from specific DF static Address.(F18A)
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
#if (DSM_FEAT_RDBI_SystemSupplierIdentifier == STD_ON)
FUNC(Std_ReturnType, RTE_CODE) Dsm_u_RDBI_SystemSupplierIdentifier_Read (Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_APPL_DATA) Data)/* PRQA S 03432,2 # 2023-06-13 Z.J.L: 3432: Simple macro argument expression is not parenthesized. 03432: Gnenerate by Rte,check it ok */
{
	  /* suppress compiler warnings about unused arguments */
	  Std_ReturnType u_RetVal = RTE_E_OK;
	  
#if((DSM_SYSTEM_TYPE == DSM_SYSTEM_MFC5J3_C673)|| \
				(DSM_SYSTEM_TYPE == DSM_SYSTEM_MFC5J3_C385))

      Std_ReturnType ui8_RetVal_Read = E_NOT_OK; 
	  static uint8 ui8_QsmReqStatus = QSM_REQRESULT_NOT_OK; 
	  static boolean b_ReadFlagSuccess;
	  
	  if((uint8)DCM_INITIAL == OpStatus)
	  {
		  b_ReadFlagSuccess = (boolean)FALSE;

		  ui8_RetVal_Read = Rte_Call_RP_Qsm_BlockPartNumber_SectorOp_Qsm_ReadBlock((void*)&s_QSBlock_PartNumberSector, 0, sizeof(s_QSBlock_PartNumberSector));

		  if ((uint8)E_OK == ui8_RetVal_Read)
		  {
              ui8_QsmReqStatus = Rte_Call_RP_Qsm_BlockPartNumber_SectorOp_Qsm_GetErrorStatues();
		  
		      if(QSM_REQRESULT_PENDING == ui8_QsmReqStatus)
	          {
		          u_RetVal = DCM_E_PENDING;
		      }
		      else if(QSM_REQRESULT_OK == ui8_QsmReqStatus)
		      {
		          b_ReadFlagSuccess = (boolean)TRUE;
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
	  else if((uint8)DCM_PENDING == OpStatus)
	  {
		  ui8_QsmReqStatus = Rte_Call_RP_Qsm_BlockPartNumber_SectorOp_Qsm_GetErrorStatues();
		  
		  if(QSM_REQRESULT_PENDING == ui8_QsmReqStatus)
	      {
		      u_RetVal = DCM_E_PENDING;
		  }
		  else if(QSM_REQRESULT_OK == ui8_QsmReqStatus)
		  {
		      b_ReadFlagSuccess = (boolean)TRUE;
		  }
		  else
		  {
		      u_RetVal = RTE_E_INVALID;	
		  }  
	  }
	  else if((uint8)DCM_CANCEL == OpStatus)
	  {
		  b_ReadFlagSuccess = (boolean)FALSE;
		  u_RetVal = RTE_E_INVALID;
	  }
	  else
	  {
		  /*Do nothing*/
	  }
  
	  if((boolean)TRUE == b_ReadFlagSuccess)
	  {
		  /* PRQA S 0314 2 */ /* Pointer to void, no problem */
		  (void)TS_MemCpy((void*)Data, (void*)s_QSBlock_PartNumberSector.F18A, PARTNUMBER_LEN); /* PRQA S 3469,2 # 2023-06-13 Z.J.L: 3469: This usage of a function-like macro looks like it could be replaced by an equivalent function call. 3469: defined by Bsw platform header,check it ok */
		  u_RetVal = RTE_E_OK;
	  }
#endif
    return u_RetVal;
} /* FUNC(Std_ReturnType, RTE_CODE) Dsm_u_RDBI_SystemSupplierIdentifier_Read (Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_APPL_DATA) Data) */
#endif

/**
 * \functions Dsm_u_RDBI_ECUSerialNumberDataIdentifier_Read
 *
 * \brief Read ECU serial number data identifier from Data flash.(F18C)
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
#if (DSM_FEAT_RDBI_ECUSerialNumberDataIdentifier == STD_ON)
FUNC(Std_ReturnType, RTE_CODE) Dsm_u_RDBI_ECUSerialNumberDataIdentifier_Read (Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_APPL_DATA) Data)/* PRQA S 03432,2 # 2023-06-13 Z.J.L: 3432: Simple macro argument expression is not parenthesized. 03432: Gnenerate by Rte,check it ok */
{
    /* suppress compiler warnings about unused arguments */
	Std_ReturnType u_RetVal = RTE_E_OK;
		
#if((DSM_SYSTEM_TYPE == DSM_SYSTEM_MFC5J3_C673)|| \
				  (DSM_SYSTEM_TYPE == DSM_SYSTEM_MFC5J3_C385))	
				  
	Std_ReturnType ui8_RetVal_Read = E_NOT_OK; 
	NvM_RequestResultType ui8_ReadStatus;
	Std_ReturnType ui8_RetVal_ErrStat;
	static boolean b_ReadFlagSuccess;

    if((uint8)DCM_INITIAL == OpStatus)
    {
        b_ReadFlagSuccess = (boolean)FALSE;

        /* PRQA S 0314 2 */ /* P2Obj to P2void conversion is safe */
        ui8_RetVal_Read = Rte_Call_RP_Nvm_SerialNumberDataId_ReadBlock((void*)RAM_NVM_BLOCK_SerialNumberDataId);

        if ( (uint8)E_OK == ui8_RetVal_Read )
        {
            ui8_RetVal_ErrStat = Rte_Call_RP_Nvm_SerialNumberDataId_GetErrorStatus(&ui8_ReadStatus);

            if ( (uint8)E_OK == ui8_RetVal_ErrStat )
            {
                if ( ((uint8)NVM_REQ_OK == ui8_ReadStatus) ||
                ((uint8)NVM_REQ_RESTORED_FROM_ROM == ui8_ReadStatus) ||
                ((uint8)NVM_REQ_REDUNDANCY_FAILED == ui8_ReadStatus) )
                {
                    b_ReadFlagSuccess = (boolean)TRUE;
                }
                else if ( (uint8)NVM_REQ_PENDING == ui8_ReadStatus )
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
  else if((uint8)DCM_PENDING == OpStatus)
  {  
      ui8_RetVal_ErrStat = Rte_Call_RP_Nvm_SerialNumberDataId_GetErrorStatus(&ui8_ReadStatus);

        if ( (uint8)E_OK == ui8_RetVal_ErrStat )
        {
            if ( ((uint8)NVM_REQ_OK == ui8_ReadStatus) ||
            ((uint8)NVM_REQ_RESTORED_FROM_ROM == ui8_ReadStatus) ||
            ((uint8)NVM_REQ_REDUNDANCY_FAILED == ui8_ReadStatus) )
            {
                b_ReadFlagSuccess = (boolean)TRUE;
            }
            else if ( (uint8)NVM_REQ_PENDING == ui8_ReadStatus )
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
  else if((uint8)DCM_CANCEL == OpStatus)
  {
      (void)Rte_Call_RP_Nvm_SerialNumberDataId_GetErrorStatus(&ui8_ReadStatus);

      if ( (uint8)NVM_REQ_PENDING == ui8_ReadStatus )
      {
          ui8_RetVal_ErrStat = NvM_CancelJobs(NvMConf_NvMBlockDescriptor_NVM_BLOCK_SerialNumberDataId);

          if ( (uint8)E_OK == ui8_RetVal_ErrStat )
          {
              u_RetVal = RTE_E_OK;
          }
          else
          {
              u_RetVal = RTE_E_INVALID;
          }
      }
      b_ReadFlagSuccess = (boolean)FALSE;
  }
  else
  {
   /*Do nothing.*/
  }

  if ((boolean)TRUE == b_ReadFlagSuccess )
  {
       /* PRQA S 0314 2 */ /* Pointer to void, no problem */
       (void)TS_MemCpy((void*)Data, (void*)RAM_NVM_BLOCK_SerialNumberDataId, ECUSERIALNUMBERDATAID_LEN); /* PRQA S 3469,2 # 2023-06-13 Z.J.L: 3469: This usage of a function-like macro looks like it could be replaced by an equivalent function call. 3469: defined by Bsw platform header,check it ok */
       u_RetVal = RTE_E_OK;
  }
  
#endif

  return u_RetVal;
} /* FUNC(Std_ReturnType, RTE_CODE) Dsm_u_RDBI_ECUSerialNumberDataIdentifier_Read (Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_APPL_DATA) Data) */
#endif

/**
 * \functions Dsm_u_RDBI_VINDataIdentifier_Read
 *
 * \brief Read VIN data identifier from Data flash.(F190)
 *
 ** \param[in] none,
 *
 ** \param[out] Data, Pointer to Data buffer (17 bytes).
 ** \return RTE_E_OK, 
 * \comments  This value shall be used to reference the VIN number. Record data
content and format shall be specified by the vehicle manufacturer.
 *
 */
#if (DSM_FEAT_RDBI_VINDataIdentifier == STD_ON)
FUNC(Std_ReturnType, RTE_CODE) Dsm_u_RDBI_VINDataIdentifier_Read (Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_APPL_DATA) Data)/* PRQA S 03432,2 # 2023-06-13 Z.J.L: 3432: Simple macro argument expression is not parenthesized. 03432: Gnenerate by Rte,check it ok */
{
	/* suppress compiler warnings about unused arguments */
	Std_ReturnType u_RetVal = RTE_E_OK;

 #if((DSM_SYSTEM_TYPE == DSM_SYSTEM_MFC5J3_C673)|| \
	  (DSM_SYSTEM_TYPE == DSM_SYSTEM_MFC5J3_C385))

    Std_ReturnType ui8_RetVal_Read = E_NOT_OK; 
 	Std_ReturnType ui8_RetVal_ErrStat = E_NOT_OK;
	NvM_RequestResultType ui8_ReadStatus;
    static boolean b_ReadFlagSuccess;

    if((uint8)DCM_INITIAL == OpStatus)
	{
		b_ReadFlagSuccess = (boolean)FALSE;
		  
		/* PRQA S 0314 2 */ /* P2Obj to P2void conversion is safe */
		ui8_RetVal_Read = Rte_Call_RP_Nvm_VINDataIdentifier_ReadBlock((void*)RAM_NVM_BLOCK_VINDataIdentifier);
		  
		if ( (uint8)E_OK == ui8_RetVal_Read )
		{
		    ui8_RetVal_ErrStat = Rte_Call_RP_Nvm_VINDataIdentifier_GetErrorStatus(&ui8_ReadStatus);
			
			if ((uint8)E_OK == ui8_RetVal_ErrStat )
			{
				if ( ((uint8)NVM_REQ_OK == ui8_ReadStatus) ||
					((uint8)NVM_REQ_RESTORED_FROM_ROM == ui8_ReadStatus) ||
					((uint8)NVM_REQ_REDUNDANCY_FAILED == ui8_ReadStatus) )
				{
					b_ReadFlagSuccess = (boolean)TRUE;
				}
				else if ((uint8)NVM_REQ_PENDING == ui8_ReadStatus )
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
	else if((uint8)DCM_PENDING == OpStatus)
	{  
	    ui8_RetVal_ErrStat = Rte_Call_RP_Nvm_VINDataIdentifier_GetErrorStatus(&ui8_ReadStatus);
			
		if ((uint8)E_OK == ui8_RetVal_ErrStat )
		{
		    if ( ((uint8)NVM_REQ_OK == ui8_ReadStatus) ||
				 ((uint8)NVM_REQ_RESTORED_FROM_ROM == ui8_ReadStatus) ||
				 ((uint8)NVM_REQ_REDUNDANCY_FAILED == ui8_ReadStatus) )
			{
				b_ReadFlagSuccess = (boolean)TRUE;
			}
			else if ((uint8)NVM_REQ_PENDING == ui8_ReadStatus )
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
	else if((uint8)DCM_CANCEL == OpStatus)
	{		
		(void)Rte_Call_RP_Nvm_VINDataIdentifier_GetErrorStatus(&ui8_ReadStatus);
		
		if ( (uint8)NVM_REQ_PENDING == ui8_ReadStatus )
		{
		    ui8_RetVal_ErrStat = NvM_CancelJobs(NvMConf_NvMBlockDescriptor_NVM_BLOCK_VINDataIdentifier);
		
			if ( (uint8)E_OK == ui8_RetVal_ErrStat )
			{
				u_RetVal = RTE_E_OK;
			}
			else
			{
				u_RetVal = RTE_E_INVALID;
			}
		}
		b_ReadFlagSuccess = (boolean)FALSE;
	}
	else
	{
		/*Do nothing.*/
	}
		  
	if ((boolean)TRUE == b_ReadFlagSuccess )
	{
		/* PRQA S 0314 2 */ /* Pointer to void, no problem */
		(void)TS_MemCpy((void*)Data, (void*)RAM_NVM_BLOCK_VINDataIdentifier, VINDATAID_LEN); /* PRQA S 3469,2 # 2023-06-13 Z.J.L: 3469: This usage of a function-like macro looks like it could be replaced by an equivalent function call. 3469: defined by Bsw platform header,check it ok */
		u_RetVal = RTE_E_OK;
	}
			
#endif
  
	  return u_RetVal;

} /* FUNC(Std_ReturnType, RTE_CODE) Dsm_u_RDBI_VINDataIdentifier_Read (Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_APPL_DATA) Data) */
#endif

/**
 * \functions Dsm_u_RDBI_applicationSoftwareFingerprintDataIdentifier_Read
 *
 * \brief Read app programming fingerprint from ROM.(F184)
 *
 ** \param[in] none,
 *
 ** \param[out] Data, Pointer to Data buffer (7 bytes).
 ** \return RTE_E_OK, 
 * \comments  This value shall be used to reference the vehicle manufacturer specific
ECU application software fingerprint identification record. Record data
content and format shall be ECU specific and defined by the vehicle
manufacturer.
 *
 */
#if (DSM_FEAT_RDBI_applicationSoftwareFingerprintDataIdentifier == STD_ON)
FUNC(Std_ReturnType, RTE_CODE) Dsm_u_RDBI_applicationSoftwareFingerprintDataIdentifier_Read (Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_APPL_DATA) Data)/* PRQA S 03432,2 # 2023-06-13 Z.J.L: 3432: Simple macro argument expression is not parenthesized. 03432: Gnenerate by Rte,check it ok */
{
    /* suppress compiler warnings about unused arguments */
    Std_ReturnType u_RetVal = RTE_E_OK;
	(void)OpStatus;
	
 #if((DSM_SYSTEM_TYPE == DSM_SYSTEM_MFC5J3_C673)|| \
	  (DSM_SYSTEM_TYPE == DSM_SYSTEM_MFC5J3_C385))	
	e_VerInfo_BankType_t e_bank = VerInfo_BankType_Max;
	
	uint64 const* addressA = A_BLANK_FINGERPRINT_START_ADDRESS;/* PRQA S 0326,0317,2 # 2023-06-13 Z.J.L: 0317:Implicit conversion from a pointer to void to a pointer to object type. 0317: Read data from address,check it ok */
	uint64 const* addressB = B_BLANK_FINGERPRINT_START_ADDRESS;/* PRQA S 0326,0317,2 # 2023-06-13 Z.J.L: 0317:Implicit conversion from a pointer to void to a pointer to object type. 0317: Read data from address,check it ok */
	
	e_bank = VerInfo_GetSoftwareBank();
	
	if(VerInfo_BankType_A == e_bank)
	{
	    Cdm_v_BoardDisableECCCheck();
		Data[0] = (uint8_t)((*addressA) & ((uint8_t)0xFF));
		Data[1] = (uint8_t)((*addressA >> 8) & ((uint8_t)0xFF));
		Data[2] = (uint8_t)((*addressA >> 16) & ((uint8_t)0xFF));
		Data[3] = (uint8_t)((*addressA >> 24) & ((uint8_t)0xFF));
		Data[4] = (uint8_t)((*addressA >> 32) & ((uint8_t)0xFF));
		Data[5] = (uint8_t)((*addressA >> 40) & ((uint8_t)0xFF));
		Data[6] = (uint8_t)((*addressA >> 48) & ((uint8_t)0xFF));
		Cdm_v_BoardEnableECCCheck();
	}
	else
	{
	    Cdm_v_BoardDisableECCCheck();
		Data[0] = (uint8_t)((*addressB) & ((uint8_t)0xFF));
		Data[1] = (uint8_t)((*addressB >> 8) & ((uint8_t)0xFF));
		Data[2] = (uint8_t)((*addressB >> 16) & ((uint8_t)0xFF));
		Data[3] = (uint8_t)((*addressB >> 24) & ((uint8_t)0xFF));
		Data[4] = (uint8_t)((*addressB >> 32) & ((uint8_t)0xFF));
		Data[5] = (uint8_t)((*addressB >> 40) & ((uint8_t)0xFF));
		Data[6] = (uint8_t)((*addressB >> 48) & ((uint8_t)0xFF));
		Cdm_v_BoardEnableECCCheck();
    }
#endif

	return u_RetVal;

} /* FUNC(Std_ReturnType, RTE_CODE) Dsm_u_RDBI_applicationSoftwareFingerprintDataIdentifier_Read (Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_APPL_DATA) Data) */
#endif

/**
 * \functions Dsm_u_RDBI_ETH_MAC_Address_Read
 *
 * \brief Read ethernet MAC address from Soc via SPI.(F1A3)
 *
 ** \param[in] none,
 *
 ** \param[out] Data, Pointer to Data buffer (8 bytes).
 **                  unsigned formatted
 *
 ** \return RTE_E_OK, 
 * \comments
 *
 */
#if (DSM_FEAT_RDBI_ETH_MAC_Address == STD_ON)
FUNC(Std_ReturnType, RTE_CODE) Dsm_u_RDBI_ETH_MAC_Address_Read (Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_APPL_DATA) Data)/* PRQA S 03432,2 # 2023-06-13 Z.J.L: 3432: Simple macro argument expression is not parenthesized. 03432: Gnenerate by Rte,check it ok */
{
    /* suppress compiler warnings about unused arguments */
    Std_ReturnType u_RetVal = RTE_E_INVALID;
	
 #if((DSM_SYSTEM_TYPE == DSM_SYSTEM_MFC5J3_C673)|| \
	  (DSM_SYSTEM_TYPE == DSM_SYSTEM_MFC5J3_C385))		
	Std_ReturnType u_RetVal_Read = E_NOT_OK; 
    static uint8 a_DataResponse[ETHMAC_ADDRESS_LEN]={0};
	static boolean b_ReadFlagSuccess;
	static uint8 u_Readcounter = 0;
	
    if((uint8)DCM_INITIAL == OpStatus)
    {
        b_ReadFlagSuccess = (boolean)FALSE;
		
  	    (void)TS_MemBZero(a_DataResponse, ETHMAC_ADDRESS_LEN);	 /* PRQA S 3469,2 # 2023-06-13 Z.J.L: 3469: This usage of a function-like macro looks like it could be replaced by an equivalent function call. 3469: defined by Bsw platform header,check it ok */
		
		u_RetVal = DCM_E_PENDING;
    }
    else if((uint8)DCM_PENDING == OpStatus)
    {
        u_RetVal_Read = Rte_Call_RP_Sdc_SendInterface_Diag_UdsRequest( (uint8_t)UDSTYPE_DID,0X0100,NULL_PTR,0,a_DataResponse,ETHMAC_ADDRESS_LEN);
	
	    if (u_RetVal_Read == RTE_E_OK)
	    {
            b_ReadFlagSuccess = (boolean)TRUE;
	    }
        else
        {           
            if(u_RetVal_Read == DCM_E_PENDING)
            {
                u_RetVal = u_RetVal_Read;
            }
		    else if (u_RetVal_Read == RTE_E_INVALID)
		    {
                u_Readcounter++;
			    if(u_Readcounter <200u)
			    {
				    u_RetVal = DCM_E_PENDING;
			    }
			    else
			    {
				    u_RetVal = RTE_E_INVALID;
				    u_Readcounter =0u;
			    }
		    }
			else
			{/*Do nothing*/}
	    }
    }
	else if ((uint8)DCM_CANCEL == OpStatus)
	{
		b_ReadFlagSuccess = (boolean)FALSE;	
	}
	else
	{
		/*Do nothing.*/
	}

	if((boolean)TRUE == b_ReadFlagSuccess)
	{
	    /* PRQA S 0314 2 */ /* Pointer to void, no problem */
        TS_MemCpy((void*)Data, (void*)a_DataResponse, ETHMAC_ADDRESS_LEN); /* PRQA S 3469,2 # 2023-06-13 Z.J.L: 3469: This usage of a function-like macro looks like it could be replaced by an equivalent function call. 3469: defined by Bsw platform header,check it ok */
        u_RetVal = RTE_E_OK;
	}
#endif

    return u_RetVal;
} /* FUNC(Std_ReturnType, RTE_CODE) Dsm_u_RDBI_ETH_MAC_Address_Read (Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_APPL_DATA) Data) */
#endif

/**
 * \functions Dsm_u_RDBI_ETH_ReadPHYLink_State_Read
 *
 * \brief Read ethernet Read physical link state from Soc via SPI.(F1A4)
 *
 ** \param[in] none,
 *
 ** \param[out] Data, Pointer to Data buffer (2 bytes).
 **                  unsigned formatted
 *
 ** \return RTE_E_OK, 
 * \comments
 *
 */
#if (DSM_FEAT_RDBI_ETH_ReadPHYLink_State == STD_ON)
FUNC(Std_ReturnType, RTE_CODE) Dsm_u_RDBI_ETH_ReadPHYLink_State_Read (Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_APPL_DATA) Data)/* PRQA S 03432,2 # 2023-06-13 Z.J.L: 3432: Simple macro argument expression is not parenthesized. 03432: Gnenerate by Rte,check it ok */
{
	  /* suppress compiler warnings about unused arguments */
	  Std_ReturnType u_RetVal = RTE_E_INVALID;
	  
 #if((DSM_SYSTEM_TYPE == DSM_SYSTEM_MFC5J3_C673)|| \
		(DSM_SYSTEM_TYPE == DSM_SYSTEM_MFC5J3_C385))	  
	  Std_ReturnType u_RetVal_Read = E_NOT_OK; 
	  static uint8 a_DataResponse[ETH_READPHYLINKSTATE_LEN]={0};
	  static boolean b_ReadFlagSuccess;
	  static uint8 u_Readcounter = 0;
	  
	  if((uint8)DCM_INITIAL == OpStatus)
	  {
		  b_ReadFlagSuccess = (boolean)FALSE;
		  
		  (void)TS_MemBZero(a_DataResponse, ETH_READPHYLINKSTATE_LEN); /* PRQA S 3469,2 # 2023-06-13 Z.J.L: 3469: This usage of a function-like macro looks like it could be replaced by an equivalent function call. 3469: defined by Bsw platform header,check it ok */

		   u_RetVal = DCM_E_PENDING;
	  }
	  else if ((uint8)DCM_PENDING == OpStatus)
	  {
	      u_RetVal_Read = Rte_Call_RP_Sdc_SendInterface_Diag_UdsRequest( (uint8_t)UDSTYPE_DID,0X0200,NULL_PTR,0,a_DataResponse,ETH_READPHYLINKSTATE_LEN);
		  
		  if (u_RetVal_Read == RTE_E_OK)
		  {
		      b_ReadFlagSuccess = (boolean)TRUE;
		  }
		  else
		  {			 
		      if(u_RetVal_Read == DCM_E_PENDING)
			  {
			      u_RetVal = u_RetVal_Read;
			  }
			  else if (u_RetVal_Read == RTE_E_INVALID)
			  {
			      u_Readcounter++;
				  if(u_Readcounter < 200u)
				  {
				      u_RetVal = DCM_E_PENDING;
				  }
				  else
				  {
				      u_RetVal = RTE_E_INVALID;
					  u_Readcounter =0u;
				  }
			  }
              else
              {/*Do nothing*/}
		  }
	  }
	  else if ((uint8)DCM_CANCEL == OpStatus)
	  {
		  b_ReadFlagSuccess = (boolean)FALSE;  
	  }
	  else
	  {
		  /*Do nothing.*/
	  }
  
	  if((boolean)TRUE == b_ReadFlagSuccess)
	  {
		  /* PRQA S 0314 2 */ /* Pointer to void, no problem */
		  TS_MemCpy((void*)Data, (void*)a_DataResponse, ETH_READPHYLINKSTATE_LEN); /* PRQA S 3469,2 # 2023-06-13 Z.J.L: 3469: This usage of a function-like macro looks like it could be replaced by an equivalent function call. 3469: defined by Bsw platform header,check it ok */
		  u_RetVal = RTE_E_OK;
	  }
#endif
  
	  return u_RetVal;

} /* FUNC(Std_ReturnType, RTE_CODE) Dsm_u_RDBI_ETH_ReadPHYLink_State_Read (Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_APPL_DATA) Data) */
#endif

/**
 * \functions Dsm_u_RDBI_ETH_ReadPHYSignal_QualityIndex_Read
 *
 * \brief Read ethernet Read physical signal quality index from Soc via SPI.(F1A5)
 *
 ** \param[in] none,
 *
 ** \param[out] Data, Pointer to Data buffer (2 bytes).
 **                  unsigned formatted
 *
 ** \return RTE_E_OK, 
 * \comments
 *
 */
#if (DSM_FEAT_RDBI_ETH_ReadPHYSignal_QualityIndex == STD_ON)
FUNC(Std_ReturnType, RTE_CODE) Dsm_u_RDBI_ETH_ReadPHYSignal_QualityIndex_Read (Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_APPL_DATA) Data)/* PRQA S 03432,2 # 2023-06-13 Z.J.L: 3432: Simple macro argument expression is not parenthesized. 03432: Gnenerate by Rte,check it ok */
{
    /* suppress compiler warnings about unused arguments */
	Std_ReturnType u_RetVal = RTE_E_INVALID;
		
 #if((DSM_SYSTEM_TYPE == DSM_SYSTEM_MFC5J3_C673)|| \
		  (DSM_SYSTEM_TYPE == DSM_SYSTEM_MFC5J3_C385))		
	Std_ReturnType u_RetVal_Read = E_NOT_OK; 
	static uint8 a_DataResponse[ETH_READPHYSIGQUALITYINDEX_LEN]={0};
	static boolean b_ReadFlagSuccess;
	static uint16 u_Readcounter = 0;
		
	if((uint8)DCM_INITIAL == OpStatus)
	{
		b_ReadFlagSuccess = (boolean)FALSE;
			
		(void)TS_MemBZero(a_DataResponse, ETH_READPHYSIGQUALITYINDEX_LEN); /* PRQA S 3469,2 # 2023-06-13 Z.J.L: 3469: This usage of a function-like macro looks like it could be replaced by an equivalent function call. 3469: defined by Bsw platform header,check it ok */
			
		u_RetVal = DCM_E_PENDING;
	}
	else if ((uint8)DCM_PENDING == OpStatus)
	{
		u_RetVal_Read = Rte_Call_RP_Sdc_SendInterface_Diag_UdsRequest( (uint8_t)UDSTYPE_DID,0X0300,NULL_PTR,0,a_DataResponse,ETH_READPHYSIGQUALITYINDEX_LEN);
			
		if (u_RetVal_Read == RTE_E_OK)
		{
			b_ReadFlagSuccess = (boolean)TRUE;
		}
		else
		{		   
			if(u_RetVal_Read == DCM_E_PENDING)
			{
				u_RetVal = u_RetVal_Read;
			}
			else if (u_RetVal_Read == RTE_E_INVALID)
			{
				u_Readcounter++;
				if(u_Readcounter < 200u)
				{
					u_RetVal = DCM_E_PENDING;
				}
				else
				{
					u_RetVal = RTE_E_INVALID;
					u_Readcounter =0u;
				}
			}
			else
			{/*Do nothing*/}
		}
	}
	else if ((uint8)DCM_CANCEL == OpStatus)
	{
		b_ReadFlagSuccess = (boolean)FALSE;	
	}
	else
	{
		/*Do nothing.*/
	}
	
	if((boolean)TRUE == b_ReadFlagSuccess)
	{
		/* PRQA S 0314 2 */ /* Pointer to void, no problem */
		TS_MemCpy((void*)Data, (void*)a_DataResponse, ETH_READPHYSIGQUALITYINDEX_LEN); /* PRQA S 3469,2 # 2023-06-13 Z.J.L: 3469: This usage of a function-like macro looks like it could be replaced by an equivalent function call. 3469: defined by Bsw platform header,check it ok */
		u_RetVal = RTE_E_OK;
	}
#endif
	
		return u_RetVal;

} /* FUNC(Std_ReturnType, RTE_CODE) Dsm_u_RDBI_ETH_ReadPHYSignal_QualityIndex_Read (Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_APPL_DATA) Data) */
#endif

/**
 * \functions Dsm_u_RDBI_ETH_Read_NumberOfPorts_Read
 *
 * \brief Read ethernet read number of ports from Soc via SPI.(F1A7)
 *
 ** \param[in] none,
 *
 ** \param[out] Data, Pointer to Data buffer (1 bytes).
 **                  unsigned formatted
 *
 ** \return RTE_E_OK, 
 * \comments
 *
 */
#if (DSM_FEAT_RDBI_ETH_Read_NumberOfPorts == STD_ON)
FUNC(Std_ReturnType, RTE_CODE) Dsm_u_RDBI_ETH_Read_NumberOfPorts_Read (Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_APPL_DATA) Data)/* PRQA S 03432,2 # 2023-06-13 Z.J.L: 3432: Simple macro argument expression is not parenthesized. 03432: Gnenerate by Rte,check it ok */
{
	/* suppress compiler warnings about unused arguments */
	Std_ReturnType u_RetVal = RTE_E_INVALID;
		  
 #if((DSM_SYSTEM_TYPE == DSM_SYSTEM_MFC5J3_C673)|| \
			(DSM_SYSTEM_TYPE == DSM_SYSTEM_MFC5J3_C385))	  
	Std_ReturnType u_RetVal_Read = E_NOT_OK; 
	static uint8 a_DataResponse[ETH_READNUMBEROFPORTS_LEN]={0};
	static boolean b_ReadFlagSuccess;
	static uint16 u_Readcounter = 0;
		  
    if((uint8)DCM_INITIAL == OpStatus)
	{
		b_ReadFlagSuccess = (boolean)FALSE;
			  
	    (void)TS_MemBZero(a_DataResponse, ETH_READNUMBEROFPORTS_LEN); /* PRQA S 3469,2 # 2023-06-13 Z.J.L: 3469: This usage of a function-like macro looks like it could be replaced by an equivalent function call. 3469: defined by Bsw platform header,check it ok */
			  		 
		u_RetVal = DCM_E_PENDING;
	}
	else if ((uint8)DCM_PENDING == OpStatus)
	{
		u_RetVal_Read = Rte_Call_RP_Sdc_SendInterface_Diag_UdsRequest( (uint8_t)UDSTYPE_DID,0X0400,NULL_PTR,0,a_DataResponse,ETH_READNUMBEROFPORTS_LEN);			  
	
	    if (u_RetVal_Read == RTE_E_OK)
	    {
		    b_ReadFlagSuccess = (boolean)TRUE;
	    }
	    else
	    {		   
		    if(u_RetVal_Read == DCM_E_PENDING)
		    {
			    u_RetVal = u_RetVal_Read;
		    }
		    else if (u_RetVal_Read == RTE_E_INVALID)
		    {
			    u_Readcounter++;
			    if(u_Readcounter < 200u)
			    {
				    u_RetVal = DCM_E_PENDING;
			    }
			    else
			    {
				    u_RetVal = RTE_E_INVALID;
				    u_Readcounter =0u;
			    }
		    }
			else
			{/*Do nothing*/}
	    }
    }
	else if ((uint8)DCM_CANCEL == OpStatus)
	{
		b_ReadFlagSuccess = (boolean)FALSE;  
	}
	else
	{
		/*Do nothing.*/
	}
	  
	if((boolean)TRUE == b_ReadFlagSuccess)
	{
	    /* PRQA S 0314 2 */ /* Pointer to void, no problem */
		TS_MemCpy((void*)Data, (void*)a_DataResponse, ETH_READNUMBEROFPORTS_LEN); /* PRQA S 3469,2 # 2023-06-13 Z.J.L: 3469: This usage of a function-like macro looks like it could be replaced by an equivalent function call. 3469: defined by Bsw platform header,check it ok */
		u_RetVal = RTE_E_OK;
	}
#endif
	  
		  return u_RetVal;

} /* FUNC(Std_ReturnType, RTE_CODE) Dsm_u_RDBI_ETH_Read_NumberOfPorts_Read (Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_APPL_DATA) Data) */
#endif

/**
 * \functions Dsm_u_RDBI_ETH_ReadPort_Configuration_Read
 *
 * \brief Read ethernet read port configuration from Soc via SPI.(F1A8)
 *
 ** \param[in] none,
 *
 ** \param[out] Data, Pointer to Data buffer (2 bytes).
 **                  unsigned formatted
 *
 ** \return RTE_E_OK, 
 * \comments
 *
 */
#if (DSM_FEAT_RDBI_ETH_ReadPort_Configuration == STD_ON)
FUNC(Std_ReturnType, RTE_CODE) Dsm_u_RDBI_ETH_ReadPort_Configuration_Read (Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_APPL_DATA) Data)/* PRQA S 03432,2 # 2023-06-13 Z.J.L: 3432: Simple macro argument expression is not parenthesized. 03432: Gnenerate by Rte,check it ok */
{
	/* suppress compiler warnings about unused arguments */
	Std_ReturnType u_RetVal = RTE_E_INVALID;
			
 #if((DSM_SYSTEM_TYPE == DSM_SYSTEM_MFC5J3_C673)|| \
			  (DSM_SYSTEM_TYPE == DSM_SYSTEM_MFC5J3_C385))		
	Std_ReturnType u_RetVal_Read = E_NOT_OK; 
	static uint8 a_DataResponse[ETH_READPORTCONFIG_LEN]={0};
	static boolean b_ReadFlagSuccess;
	static uint16 u_Readcounter = 0;
			
	if((uint8)DCM_INITIAL == OpStatus)
	{
		b_ReadFlagSuccess = (boolean)FALSE;
				
		(void)TS_MemBZero(a_DataResponse, ETH_READPORTCONFIG_LEN); /* PRQA S 3469,2 # 2023-06-13 Z.J.L: 3469: This usage of a function-like macro looks like it could be replaced by an equivalent function call. 3469: defined by Bsw platform header,check it ok */
				
		u_RetVal = DCM_E_PENDING;
	}
	else if ((uint8)DCM_PENDING == OpStatus)
	{
		u_RetVal_Read = Rte_Call_RP_Sdc_SendInterface_Diag_UdsRequest( (uint8_t)UDSTYPE_DID,0X0500,NULL_PTR,0,a_DataResponse,ETH_READPORTCONFIG_LEN);
				
		if (u_RetVal_Read == RTE_E_OK)
		{
		    b_ReadFlagSuccess = (boolean)TRUE;
		}
		else
		{		   
			if(u_RetVal_Read == DCM_E_PENDING)
			{
				u_RetVal = u_RetVal_Read;
			}
			else if (u_RetVal_Read == RTE_E_INVALID)
			{
				u_Readcounter++;
				if(u_Readcounter < 200u)
				{
					u_RetVal = DCM_E_PENDING;
				}
				else
				{
					u_RetVal = RTE_E_INVALID;
					u_Readcounter =0u;
				}
			}
			else
			{/*Do nothing*/}
		}
	}
	else if ((uint8)DCM_CANCEL == OpStatus)
	{
		b_ReadFlagSuccess = (boolean)FALSE;	
	}
	else
	{
		/*Do nothing.*/
	}
		
	if((boolean)TRUE == b_ReadFlagSuccess)
	{
		/* PRQA S 0314 2 */ /* Pointer to void, no problem */
		TS_MemCpy((void*)Data, (void*)a_DataResponse, ETH_READPORTCONFIG_LEN); /* PRQA S 3469,2 # 2023-06-13 Z.J.L: 3469: This usage of a function-like macro looks like it could be replaced by an equivalent function call. 3469: defined by Bsw platform header,check it ok */
		u_RetVal = RTE_E_OK;
	}
#endif
		
	return u_RetVal;

} /* FUNC(Std_ReturnType, RTE_CODE) Dsm_u_RDBI_ETH_ReadPort_Configuration_Read (Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_APPL_DATA) Data) */
#endif

/**
 * \functions Dsm_u_RDBI_ETH_ReadCommunication_ReadyStatus_Read
 *
 * \brief Read ethernet readcommunication Ready status from Soc via SPI.(F1A9)
 *
 ** \param[in] none,
 *
 ** \param[out] Data, Pointer to Data buffer (2 bytes).
 **                  unsigned formatted
 *
 ** \return RTE_E_OK, 
 * \comments
 *
 */
#if (DSM_FEAT_RDBI_ETH_ReadCommunication_ReadyStatus == STD_ON)
FUNC(Std_ReturnType, RTE_CODE) Dsm_u_RDBI_ETH_ReadCommunication_ReadyStatus_Read (Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_APPL_DATA) Data)/* PRQA S 03432,2 # 2023-06-13 Z.J.L: 3432: Simple macro argument expression is not parenthesized. 03432: Gnenerate by Rte,check it ok */
{
    /* suppress compiler warnings about unused arguments */
	Std_ReturnType u_RetVal = RTE_E_INVALID;
			  
 #if((DSM_SYSTEM_TYPE == DSM_SYSTEM_MFC5J3_C673)|| \
				(DSM_SYSTEM_TYPE == DSM_SYSTEM_MFC5J3_C385))	  
	Std_ReturnType u_RetVal_Read = E_NOT_OK; 
	static uint8 a_DataResponse[ETH_READCOMREADYSTATUS_LEN]={0};
	static boolean b_ReadFlagSuccess;
	static uint8 u_Readcounter = 0;
			  
	if((uint8)DCM_INITIAL == OpStatus)
	{
	    b_ReadFlagSuccess = (boolean)FALSE;
				  
		(void)TS_MemBZero(a_DataResponse, ETH_READCOMREADYSTATUS_LEN); /* PRQA S 3469,2 # 2023-06-13 Z.J.L: 3469: This usage of a function-like macro looks like it could be replaced by an equivalent function call. 3469: defined by Bsw platform header,check it ok */
				  
		u_RetVal = DCM_E_PENDING;
	}
	else if ((uint8)DCM_PENDING == OpStatus)
	{
	    u_RetVal_Read = Rte_Call_RP_Sdc_SendInterface_Diag_UdsRequest( (uint8_t)UDSTYPE_DID,0X0600,NULL_PTR,0,a_DataResponse,ETH_READCOMREADYSTATUS_LEN);
				  
		if (u_RetVal_Read == RTE_E_OK)
		{
		    b_ReadFlagSuccess = (boolean)TRUE;
		}
		else
		{		   
			if(u_RetVal_Read == DCM_E_PENDING)
			{
				u_RetVal = u_RetVal_Read;
			}
			else if (u_RetVal_Read == RTE_E_INVALID)
			{
				u_Readcounter++;
				if(u_Readcounter < 200u)
				{
					u_RetVal = DCM_E_PENDING;
				}
				else
				{
					u_RetVal = RTE_E_INVALID;
					u_Readcounter =0u;
				}
			}
			else
			{/*Do nothing*/}
		}
	}
	else if ((uint8)DCM_CANCEL == OpStatus)
	{
		b_ReadFlagSuccess = (boolean)FALSE;  
	}
	else
	{
		/*Do nothing.*/
	}
		  
	if((boolean)TRUE == b_ReadFlagSuccess)
	{
		/* PRQA S 0314 2 */ /* Pointer to void, no problem */
		TS_MemCpy((void*)Data, (void*)a_DataResponse, ETH_READCOMREADYSTATUS_LEN); /* PRQA S 3469,2 # 2023-06-13 Z.J.L: 3469: This usage of a function-like macro looks like it could be replaced by an equivalent function call. 3469: defined by Bsw platform header,check it ok */
		u_RetVal = RTE_E_OK;
	}
#endif
		  
	return u_RetVal;

} /* FUNC(Std_ReturnType, RTE_CODE) Dsm_u_RDBI_ETH_ReadCommunication_ReadyStatus_Read (Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_APPL_DATA) Data) */
#endif

/**
 * \functions Dsm_u_RDBI_ETH_ReadMasterSlave_Configures_Read
 *
 * \brief Read ethernet read master and slave configures from Soc via SPI.(F1AA)
 *
 ** \param[in] none,
 *
 ** \param[out] Data, Pointer to Data buffer (2 bytes).
 **                  unsigned formatted
 *
 ** \return RTE_E_OK, 
 * \comments
 *
 */
#if (DSM_FEAT_RDBI_ETH_ReadMasterSlave_Configures == STD_ON)
FUNC(Std_ReturnType, RTE_CODE) Dsm_u_RDBI_ETH_ReadMasterSlave_Configures_Read (Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_APPL_DATA) Data)/* PRQA S 03432,2 # 2023-06-13 Z.J.L: 3432: Simple macro argument expression is not parenthesized. 03432: Gnenerate by Rte,check it ok */
{
    /* suppress compiler warnings about unused arguments */
	Std_ReturnType u_RetVal = RTE_E_INVALID;
				
 #if((DSM_SYSTEM_TYPE == DSM_SYSTEM_MFC5J3_C673)|| \
				  (DSM_SYSTEM_TYPE == DSM_SYSTEM_MFC5J3_C385))		
	Std_ReturnType u_RetVal_Read = E_NOT_OK; 
	static uint8 a_DataResponse[ETH_READMASTERSLAVECONFIG_LEN]={0};
	static boolean b_ReadFlagSuccess;
	static uint8 u_Readcounter = 0;
				
	if((uint8)DCM_INITIAL == OpStatus)
	{
		b_ReadFlagSuccess = (boolean)FALSE;
					
		(void)TS_MemBZero(a_DataResponse, ETH_READMASTERSLAVECONFIG_LEN); /* PRQA S 3469,2 # 2023-06-13 Z.J.L: 3469: This usage of a function-like macro looks like it could be replaced by an equivalent function call. 3469: defined by Bsw platform header,check it ok */
					
		u_RetVal = DCM_E_PENDING;	
	}
	else if ((uint8)DCM_PENDING == OpStatus)
	{
		u_RetVal_Read = Rte_Call_RP_Sdc_SendInterface_Diag_UdsRequest( (uint8_t)UDSTYPE_DID,0X0700,NULL_PTR,0,a_DataResponse,ETH_READMASTERSLAVECONFIG_LEN);

		if (u_RetVal_Read == RTE_E_OK)
		{
		    b_ReadFlagSuccess = (boolean)TRUE;
		}
		else
		{		   
			if(u_RetVal_Read == DCM_E_PENDING)
			{
				u_RetVal = u_RetVal_Read;
			}
			else if (u_RetVal_Read == RTE_E_INVALID)
			{
				u_Readcounter++;
				if(u_Readcounter < 200u)
				{
					u_RetVal = DCM_E_PENDING;
				}
				else
				{
					u_RetVal = RTE_E_INVALID;
					u_Readcounter =0u;
				}
			}
			else
			{/*Do nothing*/}
		}			
	}
	else if ((uint8)DCM_CANCEL == OpStatus)
	{
		b_ReadFlagSuccess = (boolean)FALSE;	
	}
	else
	{
		/*Do nothing.*/
	}
			
	if((boolean)TRUE == b_ReadFlagSuccess)
	{
		/* PRQA S 0314 2 */ /* Pointer to void, no problem */
		TS_MemCpy((void*)Data, (void*)a_DataResponse, ETH_READMASTERSLAVECONFIG_LEN); /* PRQA S 3469,2 # 2023-06-13 Z.J.L: 3469: This usage of a function-like macro looks like it could be replaced by an equivalent function call. 3469: defined by Bsw platform header,check it ok */
		u_RetVal = RTE_E_OK;
	}
#endif
			
		return u_RetVal;

} /* FUNC(Std_ReturnType, RTE_CODE) Dsm_u_RDBI_ETH_ReadMasterSlave_Configures_Read (Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_APPL_DATA) Data) */
#endif

/**
 * \functions Dsm_u_RDBI_ETH_ReadMACLayer_Statistics_Read
 *
 * \brief Read ethernet read MAC layer statistics from Soc via SPI.(F1AB)
 *
 ** \param[in] none,
 *
 ** \param[out] Data, Pointer to Data buffer (88 bytes).
 **                  unsigned formatted
 *
 ** \return RTE_E_OK, 
 * \comments
 *
 */
#if (DSM_FEAT_RDBI_ETH_ReadMACLayer_Statistics == STD_ON)
FUNC(Std_ReturnType, RTE_CODE) Dsm_u_RDBI_ETH_ReadMACLayer_Statistics_Read (Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_APPL_DATA) Data)/* PRQA S 03432,2 # 2023-06-13 Z.J.L: 3432: Simple macro argument expression is not parenthesized. 03432: Gnenerate by Rte,check it ok */
{
    /* suppress compiler warnings about unused arguments */
	Std_ReturnType u_RetVal = RTE_E_INVALID;
				  
 #if((DSM_SYSTEM_TYPE == DSM_SYSTEM_MFC5J3_C673)|| \
					(DSM_SYSTEM_TYPE == DSM_SYSTEM_MFC5J3_C385))	  
	Std_ReturnType u_RetVal_Read = E_NOT_OK; 
	static uint8 a_DataResponse[ETH_READMACLAYERSTATISTICS_LEN]={0};
	static boolean b_ReadFlagSuccess;
    static uint16 u_Readcounter = 0;
				  
	if((uint8)DCM_INITIAL == OpStatus)
	{
		b_ReadFlagSuccess = (boolean)FALSE;
					  
		(void)TS_MemBZero(a_DataResponse, ETH_READMACLAYERSTATISTICS_LEN); /* PRQA S 3469,2 # 2023-06-13 Z.J.L: 3469: This usage of a function-like macro looks like it could be replaced by an equivalent function call. 3469: defined by Bsw platform header,check it ok */
					  			  
		u_RetVal = DCM_E_PENDING;
	}
	else if ((uint8)DCM_PENDING == OpStatus)
	{
		u_RetVal_Read = Rte_Call_RP_Sdc_SendInterface_Diag_UdsRequest( (uint8_t)UDSTYPE_DID,0X0800,NULL_PTR,0,a_DataResponse,ETH_READMACLAYERSTATISTICS_LEN);
		
		if (u_RetVal_Read == RTE_E_OK)
		{
		    b_ReadFlagSuccess = (boolean)TRUE;
		}
		else
		{		   
			if(u_RetVal_Read == DCM_E_PENDING)
			{
				u_RetVal = u_RetVal_Read;
			}
			else if (u_RetVal_Read == RTE_E_INVALID)
			{
				u_Readcounter++;
				if(u_Readcounter < 200u)
				{
					u_RetVal = DCM_E_PENDING;
				}
				else
				{
					u_RetVal = RTE_E_INVALID;
					u_Readcounter =0u;
				}
			}
			else
			{/*Do nothing*/}
		}						  
	}
	else if ((uint8)DCM_CANCEL == OpStatus)
	{
		 b_ReadFlagSuccess = (boolean)FALSE;  
	}
	else
	{
		 /*Do nothing.*/
	}
			  
	if((boolean)TRUE == b_ReadFlagSuccess)
	{
		 /* PRQA S 0314 2 */ /* Pointer to void, no problem */
		 TS_MemCpy((void*)Data, (void*)a_DataResponse, ETH_READMACLAYERSTATISTICS_LEN); /* PRQA S 3469,2 # 2023-06-13 Z.J.L: 3469: This usage of a function-like macro looks like it could be replaced by an equivalent function call. 3469: defined by Bsw platform header,check it ok */
		 u_RetVal = RTE_E_OK;
    }
#endif
			  
	return u_RetVal;

} /* FUNC(Std_ReturnType, RTE_CODE) Dsm_u_RDBI_ETH_ReadMACLayer_Statistics_Read (Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_APPL_DATA) Data) */
#endif

/**
 * \functions Dsm_u_RDBI_VehicleType_Read
 *
 * \brief Read vehicle type from Data flash.(F1F0)
 *
 ** \param[in] none,
 *
 ** \param[out] Data, Pointer to Data buffer (1 bytes).
 **                  The default value is 0x00.
 ** \return RTE_E_OK, 
 * \comments  
 *
 */
#if (DSM_FEAT_RDBI_VehicleType == STD_ON)
FUNC(Std_ReturnType, RTE_CODE) Dsm_u_RDBI_VehicleType_Read (Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_APPL_DATA) Data)/* PRQA S 03432,2 # 2023-06-13 Z.J.L: 3432: Simple macro argument expression is not parenthesized. 03432: Gnenerate by Rte,check it ok */
{
    /* suppress compiler warnings about unused arguments */
	Std_ReturnType u_RetVal = RTE_E_OK;
		  
#if((DSM_SYSTEM_TYPE == DSM_SYSTEM_MFC5J3_C673)|| \
					(DSM_SYSTEM_TYPE == DSM_SYSTEM_MFC5J3_C385))  
					
	Std_ReturnType ui8_RetVal_Read = E_NOT_OK; 
	NvM_RequestResultType ui8_ReadStatus;
	Std_ReturnType ui8_RetVal_ErrStat;
	static boolean b_ReadFlagSuccess;
  
	if((uint8)DCM_INITIAL == OpStatus)
	{
		 b_ReadFlagSuccess = (boolean)FALSE;
  
		 /* PRQA S 0314 2 */ /* P2Obj to P2void conversion is safe */
		 ui8_RetVal_Read = Rte_Call_RP_Nvm_Vehicletype_ReadBlock((void*)RAM_NVM_BLOCK_Vehicletype);
  
		 if ( (uint8)E_OK == ui8_RetVal_Read )
		 {
			  ui8_RetVal_ErrStat = Rte_Call_RP_Nvm_Vehicletype_GetErrorStatus(&ui8_ReadStatus);
  
			  if ( (uint8)E_OK == ui8_RetVal_ErrStat )
			  {
				  if ( ((uint8)NVM_REQ_OK == ui8_ReadStatus) ||
				  ((uint8)NVM_REQ_RESTORED_FROM_ROM == ui8_ReadStatus) ||
				  ((uint8)NVM_REQ_REDUNDANCY_FAILED == ui8_ReadStatus) )
				  {
					  b_ReadFlagSuccess = (boolean)TRUE;
				  }
				  else if ( (uint8)NVM_REQ_PENDING == ui8_ReadStatus )
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
	else if((uint8)DCM_PENDING == OpStatus)
	{  
		ui8_RetVal_ErrStat = Rte_Call_RP_Nvm_Vehicletype_GetErrorStatus( &ui8_ReadStatus);
  
		if ( (uint8)E_OK == ui8_RetVal_ErrStat )
		{
			if ( ((uint8)NVM_REQ_OK == ui8_ReadStatus) ||
			((uint8)NVM_REQ_RESTORED_FROM_ROM == ui8_ReadStatus) ||
			((uint8)NVM_REQ_REDUNDANCY_FAILED == ui8_ReadStatus) )
			{
				  b_ReadFlagSuccess = (boolean)TRUE;
			  }
			  else if ( (uint8)NVM_REQ_PENDING == ui8_ReadStatus )
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
	else if((uint8)DCM_CANCEL == OpStatus)
	{
		(void)Rte_Call_RP_Nvm_Vehicletype_GetErrorStatus( &ui8_ReadStatus);
		
		  if ( (uint8)NVM_REQ_PENDING == ui8_ReadStatus )
		  {
			  ui8_RetVal_ErrStat = NvM_CancelJobs(NvMConf_NvMBlockDescriptor_NvM_Block_Vehicletype);
  
			  if ( (uint8)E_OK == ui8_RetVal_ErrStat )
			  {
				  u_RetVal = RTE_E_OK;
			  }
			  else
			  {
				  u_RetVal = RTE_E_INVALID;
			  }
		  }
		  b_ReadFlagSuccess = (boolean)FALSE;
  
	}
	else
	{
	 /*Do nothing.*/
	}
  
    if ((boolean)TRUE == b_ReadFlagSuccess )
	{
		 /* PRQA S 0314 2 */ /* Pointer to void, no problem */
		 if((uint8)SYS_C673_EVE == GET_SYS_VEHVARIANT()) /* PRQA S 3469,2 # 2023-06-13 Z.J.L: 3469: This usage of a function-like macro looks like it could be replaced by an equivalent function call. 3469: defined by Bsw platform header,check it ok */
		 {
             Data[0] = 0x01u;
		 }
		 else if((uint8)SYS_C673_PERFORMANCE == GET_SYS_VEHVARIANT()) /* PRQA S 3469,2 # 2023-06-13 Z.J.L: 3469: This usage of a function-like macro looks like it could be replaced by an equivalent function call. 3469: defined by Bsw platform header,check it ok */
		 {
             Data[0] = 0x02u;
		 }
		 else if((uint8)SYS_C673_LBL == GET_SYS_VEHVARIANT()) /* PRQA S 3469,2 # 2023-06-13 Z.J.L: 3469: This usage of a function-like macro looks like it could be replaced by an equivalent function call. 3469: defined by Bsw platform header,check it ok */
		 {
             Data[0] = 0x03u;
		 }
		 else if((uint8)SYS_C673_4WD == GET_SYS_VEHVARIANT()) /* PRQA S 3469,2 # 2023-06-13 Z.J.L: 3469: This usage of a function-like macro looks like it could be replaced by an equivalent function call. 3469: defined by Bsw platform header,check it ok */
		 {
             Data[0] = 0x04u;
		 }
		 else{/*Do nothing.*/}
	 
		 u_RetVal = RTE_E_OK;
	}
	
#endif
  
	return u_RetVal;

} /* FUNC(Std_ReturnType, RTE_CODE) Dsm_u_RDBI_VehicleType_Read (Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_APPL_DATA) Data) */
#endif

/**
 * \functions Dsm_u_RDBI_FABSwitch_Read
 *
 * \brief Read the switch of FAB from Data flash.(F1F1)
 *
 ** \param[in] none,
 *
 ** \param[out] Data, Pointer to Data buffer (1 bytes).
 **                  The DID format as below:
 **                  off: 0x00
 **                   on: 0x01
 ** \return RTE_E_OK, 
 * \comments  
 *
 */
#if (DSM_FEAT_RDBI_FABSwitch == STD_ON)
FUNC(Std_ReturnType, RTE_CODE) Dsm_u_RDBI_FABSwitch_Read (Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_APPL_DATA) Data)/* PRQA S 03432,2 # 2023-06-13 Z.J.L: 3432: Simple macro argument expression is not parenthesized. 03432: Gnenerate by Rte,check it ok */
{
	  /* suppress compiler warnings about unused arguments */
	  Std_ReturnType u_RetVal = RTE_E_OK;
			
#if((DSM_SYSTEM_TYPE == DSM_SYSTEM_MFC5J3_C673)|| \
					  (DSM_SYSTEM_TYPE == DSM_SYSTEM_MFC5J3_C385))	
					  
	  Std_ReturnType ui8_RetVal_Read = E_NOT_OK; 
	  NvM_RequestResultType ui8_ReadStatus;
	  Std_ReturnType ui8_RetVal_ErrStat;
	  static boolean b_ReadFlagSuccess;
	
	  if((uint8)DCM_INITIAL == OpStatus)
	  {
		   b_ReadFlagSuccess = (boolean)FALSE;
	
		   /* PRQA S 0314 2 */ /* P2Obj to P2void conversion is safe */
		   ui8_RetVal_Read = Rte_Call_RP_Nvm_FAB_switch_ReadBlock((void*)RAM_NVM_BLOCK_FAB_switch);
	
		   if ( (uint8)E_OK == ui8_RetVal_Read )
		   {
				ui8_RetVal_ErrStat = Rte_Call_RP_Nvm_FAB_switch_GetErrorStatus(&ui8_ReadStatus);
	
				if ( (uint8)E_OK == ui8_RetVal_ErrStat )
				{
					if ( ((uint8)NVM_REQ_OK == ui8_ReadStatus) ||
					((uint8)NVM_REQ_RESTORED_FROM_ROM == ui8_ReadStatus) ||
					((uint8)NVM_REQ_REDUNDANCY_FAILED == ui8_ReadStatus) )
					{
						b_ReadFlagSuccess = (boolean)TRUE;
					}
					else if ( (uint8)NVM_REQ_PENDING == ui8_ReadStatus )
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
	  else if((uint8)DCM_PENDING == OpStatus)
	  {  
		  ui8_RetVal_ErrStat = Rte_Call_RP_Nvm_FAB_switch_GetErrorStatus(&ui8_ReadStatus);
	
			if ( (uint8)E_OK == ui8_RetVal_ErrStat )
			{
				if ( ((uint8)NVM_REQ_OK == ui8_ReadStatus) ||
				((uint8)NVM_REQ_RESTORED_FROM_ROM == ui8_ReadStatus) ||
				((uint8)NVM_REQ_REDUNDANCY_FAILED == ui8_ReadStatus) )
				{
					b_ReadFlagSuccess = (boolean)TRUE;
				}
				else if ( (uint8)NVM_REQ_PENDING == ui8_ReadStatus )
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
	  else if((uint8)DCM_CANCEL == OpStatus)
	  {
		  (void)Rte_Call_RP_Nvm_FAB_switch_GetErrorStatus(&ui8_ReadStatus);
	
			if ( (uint8)NVM_REQ_PENDING == ui8_ReadStatus )
			{
				ui8_RetVal_ErrStat = NvM_CancelJobs(NvMConf_NvMBlockDescriptor_NVM_BLOCK_FAB_switch);
	
				if ( (uint8)E_OK == ui8_RetVal_ErrStat )
				{
					u_RetVal = RTE_E_OK;
				}
				else
				{
					u_RetVal = RTE_E_INVALID;
				}
			}
			b_ReadFlagSuccess = (boolean)FALSE;
	
	  }
	  else
	  {
	   /*Do nothing.*/
	  }
	
	  if ((boolean)TRUE == b_ReadFlagSuccess )
	  {
		   /* PRQA S 0314 2 */ /* Pointer to void, no problem */
		   TS_MemCpy((void*)Data, (void*)RAM_NVM_BLOCK_FAB_switch, FABSWITCH_LEN); /* PRQA S 3469,2 # 2023-06-13 Z.J.L: 3469: This usage of a function-like macro looks like it could be replaced by an equivalent function call. 3469: defined by Bsw platform header,check it ok */
		   u_RetVal = RTE_E_OK;
	  }
	  
#endif
	
	  return u_RetVal;

} /* FUNC(Std_ReturnType, RTE_CODE) Dsm_u_RDBI_FABSwitch_Read (Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_APPL_DATA) Data) */
#endif

/**
 * \functions Dsm_u_RDBI_TSRSwitch_Read
 *
 * \brief Read the switch of TSR from Data flash.(F1F2)
 *
 ** \param[in] none,
 *
 ** \param[out] Data, Pointer to Data buffer (1 bytes).
 **                  The DID format as below:
 **                  off: 0x00
 **                   on: 0x01
 ** \return RTE_E_OK, 
 * \comments  
 *
 */
#if (DSM_FEAT_RDBI_TSRSwitch == STD_ON)
FUNC(Std_ReturnType, RTE_CODE) Dsm_u_RDBI_TSRSwitch_Read (Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_APPL_DATA) Data)/* PRQA S 03432,2 # 2023-06-13 Z.J.L: 3432: Simple macro argument expression is not parenthesized. 03432: Gnenerate by Rte,check it ok */
{
	/* suppress compiler warnings about unused arguments */
	Std_ReturnType u_RetVal = RTE_E_OK;
				
#if((DSM_SYSTEM_TYPE == DSM_SYSTEM_MFC5J3_C673)|| \
						  (DSM_SYSTEM_TYPE == DSM_SYSTEM_MFC5J3_C385))	
						  
	 Std_ReturnType ui8_RetVal_Read = E_NOT_OK; 
	 NvM_RequestResultType ui8_ReadStatus;
	 Std_ReturnType ui8_RetVal_ErrStat;
	 static boolean b_ReadFlagSuccess;
		
	 if((uint8)DCM_INITIAL == OpStatus)
	 {
		  b_ReadFlagSuccess = (boolean)FALSE;
		
		  /* PRQA S 0314 2 */ /* P2Obj to P2void conversion is safe */
		  ui8_RetVal_Read = Rte_Call_RP_Nvm_TSR_switch_ReadBlock((void*)RAM_NVM_BLOCK_TSR_switch);
		
		  if ( (uint8)E_OK == ui8_RetVal_Read )
		  {
			  ui8_RetVal_ErrStat = Rte_Call_RP_Nvm_TSR_switch_GetErrorStatus(&ui8_ReadStatus);
		
			  if ( (uint8)E_OK == ui8_RetVal_ErrStat )
			  {
				  if ( ((uint8)NVM_REQ_OK == ui8_ReadStatus) ||
					  ((uint8)NVM_REQ_RESTORED_FROM_ROM == ui8_ReadStatus) ||
					  ((uint8)NVM_REQ_REDUNDANCY_FAILED == ui8_ReadStatus) )
				  {
				      b_ReadFlagSuccess = (boolean)TRUE;
				  }
				  else if ( (uint8)NVM_REQ_PENDING == ui8_ReadStatus )
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
	 else if((uint8)DCM_PENDING == OpStatus)
	 {	
		  ui8_RetVal_ErrStat = Rte_Call_RP_Nvm_TSR_switch_GetErrorStatus(&ui8_ReadStatus);
		
		  if ( (uint8)E_OK == ui8_RetVal_ErrStat )
		  {
			  if ( ((uint8)NVM_REQ_OK == ui8_ReadStatus) ||
				  ((uint8)NVM_REQ_RESTORED_FROM_ROM == ui8_ReadStatus) ||
				  ((uint8)NVM_REQ_REDUNDANCY_FAILED == ui8_ReadStatus) )
			  {
				  b_ReadFlagSuccess = (boolean)TRUE;
			  }
			  else if ( (uint8)NVM_REQ_PENDING == ui8_ReadStatus )
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
	 else if((uint8)DCM_CANCEL == OpStatus)
	 {
		  (void)Rte_Call_RP_Nvm_TSR_switch_GetErrorStatus(&ui8_ReadStatus);
		
		  if ( (uint8)NVM_REQ_PENDING == ui8_ReadStatus )
		  {
			  ui8_RetVal_ErrStat = NvM_CancelJobs(NvMConf_NvMBlockDescriptor_NVM_BLOCK_TSR_switch);
		
			  if ( (uint8)E_OK == ui8_RetVal_ErrStat )
			  {
				  u_RetVal = RTE_E_OK;
			  }
			  else
			  {
				  u_RetVal = RTE_E_INVALID;
			  }
		  }
		  b_ReadFlagSuccess = (boolean)FALSE;
		
	 }
	 else
	 {
			  /*Do nothing.*/
	 }
		
	 if ((boolean)TRUE == b_ReadFlagSuccess )
	 {
		 /* PRQA S 0314 2 */ /* Pointer to void, no problem */
		 TS_MemCpy((void*)Data, (void*)RAM_NVM_BLOCK_TSR_switch, TSRSWITCH_LEN); /* PRQA S 3469,2 # 2023-06-13 Z.J.L: 3469: This usage of a function-like macro looks like it could be replaced by an equivalent function call. 3469: defined by Bsw platform header,check it ok */
		 u_RetVal = RTE_E_OK;
	 }
		  
#endif
		
	  return u_RetVal;
} /* FUNC(Std_ReturnType, RTE_CODE) Dsm_u_RDBI_TSRSwitch_Read (Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_APPL_DATA) Data) */
#endif


/**
 * \functions Dsm_u_RDBI_TLASwitch_Read
 *
 * \brief Read the switch of TLA from Data flash.(F1F3)
 *
 ** \param[in] none,
 *
 ** \param[out] Data, Pointer to Data buffer (1 bytes).
 **                  The DID format as below:
 **                  off: 0x00
 **                   on: 0x01
 ** \return RTE_E_OK, 
 * \comments  
 *
 */
#if (DSM_FEAT_RDBI_TLASwitch == STD_ON)
FUNC(Std_ReturnType, RTE_CODE) Dsm_u_RDBI_TLASwitch_Read (Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_APPL_DATA) Data)/* PRQA S 03432,2 # 2023-06-13 Z.J.L: 3432: Simple macro argument expression is not parenthesized. 03432: Gnenerate by Rte,check it ok */
{
    /* suppress compiler warnings about unused arguments */
	Std_ReturnType u_RetVal = RTE_E_OK;
			  
#if((DSM_SYSTEM_TYPE == DSM_SYSTEM_MFC5J3_C673)|| \
						(DSM_SYSTEM_TYPE == DSM_SYSTEM_MFC5J3_C385))  
						
	Std_ReturnType ui8_RetVal_Read = E_NOT_OK; 
	NvM_RequestResultType ui8_ReadStatus;
	Std_ReturnType ui8_RetVal_ErrStat;
	static boolean b_ReadFlagSuccess;
	  
	if((uint8)DCM_INITIAL == OpStatus)
	{
	    b_ReadFlagSuccess = (boolean)FALSE;
	  
		/* PRQA S 0314 2 */ /* P2Obj to P2void conversion is safe */
		ui8_RetVal_Read = Rte_Call_RP_Nvm_TLA_switch_ReadBlock((void*)RAM_NVM_BLOCK_TLA_switch);
		
		if ( (uint8)E_OK == ui8_RetVal_Read )
		{
		    ui8_RetVal_ErrStat = Rte_Call_RP_Nvm_TLA_switch_GetErrorStatus(&ui8_ReadStatus);
	  
			if ( (uint8)E_OK == ui8_RetVal_ErrStat )
			{
				if ( ((uint8)NVM_REQ_OK == ui8_ReadStatus) ||
					((uint8)NVM_REQ_RESTORED_FROM_ROM == ui8_ReadStatus) ||
					((uint8)NVM_REQ_REDUNDANCY_FAILED == ui8_ReadStatus) )
				{
					b_ReadFlagSuccess = (boolean)TRUE;
				}
				else if ( (uint8)NVM_REQ_PENDING == ui8_ReadStatus )
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
   else if((uint8)DCM_PENDING == OpStatus)
   {  
		ui8_RetVal_ErrStat = Rte_Call_RP_Nvm_TLA_switch_GetErrorStatus(&ui8_ReadStatus);
	  
		if ( (uint8)E_OK == ui8_RetVal_ErrStat )
		{
			if ( ((uint8)NVM_REQ_OK == ui8_ReadStatus) ||
				((uint8)NVM_REQ_RESTORED_FROM_ROM == ui8_ReadStatus) ||
				((uint8)NVM_REQ_REDUNDANCY_FAILED == ui8_ReadStatus) )
			{
				b_ReadFlagSuccess = (boolean)TRUE;
			}
			else if ( (uint8)NVM_REQ_PENDING == ui8_ReadStatus )
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
   else if((uint8)DCM_CANCEL == OpStatus)
   {
		(void)Rte_Call_RP_Nvm_TLA_switch_GetErrorStatus(&ui8_ReadStatus);
	  
		if ( (uint8)NVM_REQ_PENDING == ui8_ReadStatus )
		{
			ui8_RetVal_ErrStat = NvM_CancelJobs(NvMConf_NvMBlockDescriptor_NVM_BLOCK_TLA_switch);
	  
			if ( (uint8)E_OK == ui8_RetVal_ErrStat )
			{
				u_RetVal = RTE_E_OK;
			}
			else
			{
				u_RetVal = RTE_E_INVALID;
			}
		}
		b_ReadFlagSuccess = (boolean)FALSE;
	  
	}
	else
	{
		/*Do nothing.*/
	}
	  
	if ((boolean)TRUE == b_ReadFlagSuccess )
	{
		/* PRQA S 0314 2 */ /* Pointer to void, no problem */
		TS_MemCpy((void*)Data, (void*)RAM_NVM_BLOCK_TLA_switch, TLASWITCH_LEN); /* PRQA S 3469,2 # 2023-06-13 Z.J.L: 3469: This usage of a function-like macro looks like it could be replaced by an equivalent function call. 3469: defined by Bsw platform header,check it ok */
		u_RetVal = RTE_E_OK;
	}
		
#endif
	  
	return u_RetVal;

} /* FUNC(Std_ReturnType, RTE_CODE) Dsm_u_RDBI_TLASwitch_Read (Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_APPL_DATA) Data) */
#endif

/**
 * \functions Dsm_u_RDBI_InvalidAttemptCounter_Read
 *
 * \brief Read invalid attempt counter from Data flash.(0103)
 *
 ** \param[in] none,
 *
 ** \param[out] Data, Pointer to Data buffer (1 bytes).
 **                  The DID format as below:
 ** \return RTE_E_OK, 
 * \comments  
 *
 */
#if (DSM_FEAT_RDBI_InvalidAttemptCounter == STD_ON)
FUNC(Std_ReturnType, RTE_CODE) Dsm_u_RDBI_InvalidAttemptCounter_Read (Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_APPL_DATA) Data)/* PRQA S 03432,2 # 2023-06-13 Z.J.L: 3432: Simple macro argument expression is not parenthesized. 03432: Gnenerate by Rte,check it ok */
{
    /* suppress compiler warnings about unused arguments */
	Std_ReturnType u_RetVal = RTE_E_INVALID;
	(void)OpStatus;
	
 #if((DSM_SYSTEM_TYPE == DSM_SYSTEM_MFC5J3_C673)|| \
		(DSM_SYSTEM_TYPE == DSM_SYSTEM_MFC5J3_C385))
		
	if(NULL_PTR != Data)
	{
		TS_MemCpy(&Data[0], RAM_NVM_BLOCK_Security_AttemptCount, sizeof(RAM_NVM_BLOCK_Security_AttemptCount)); /* PRQA S 3469,2 # 2023-06-13 Z.J.L: 3469: This usage of a function-like macro looks like it could be replaced by an equivalent function call. 3469: defined by Bsw platform header,check it ok */
		u_RetVal = RTE_E_OK;
	}
	else
	{/*Do nothing*/}
#endif
	
	return u_RetVal;

} /* FUNC(Std_ReturnType, RTE_CODE) Dsm_u_RDBI_InvalidAttemptCounter_Read (Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_APPL_DATA) Data) */
#endif

/**
 * \functions Dsm_u_RDBI_EOL_CalibrationParameters_Read
 *
 * \brief Read calibration parameter of EOL from Data flash.(F1F9)
 *
 ** \param[in] none,
 *
 ** \param[out] Data, Pointer to Data buffer (8 bytes).
 **                  The DID format as below:
 **             byte0-1: Initial_calibration_camera_height
 **             byte2-3: Initial_calibration_roll_angle
 **             byte4-5: Initial_calibration_pitch_angle
 **             byte6-7: Initial_calibration_yaw_angle
 ** \return RTE_E_OK, 
 * \comments  
 *
 */
#if (DSM_FEAT_RDBI_EOL_CalibrationParameters == STD_ON)
FUNC(Std_ReturnType, RTE_CODE) Dsm_u_RDBI_EOL_CalibrationParameters_Read (Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_APPL_DATA) Data)/* PRQA S 03432,2 # 2023-06-13 Z.J.L: 3432: Simple macro argument expression is not parenthesized. 03432: Gnenerate by Rte,check it ok */
{
    /* suppress compiler warnings about unused arguments */
	Std_ReturnType u_RetVal = RTE_E_OK;
			
#if((DSM_SYSTEM_TYPE == DSM_SYSTEM_MFC5J3_C673)|| \
					  (DSM_SYSTEM_TYPE == DSM_SYSTEM_MFC5J3_C385))	
					  
	Std_ReturnType ui8_RetVal_Read = E_NOT_OK; 
	NvM_RequestResultType ui8_ReadStatus;
	Std_ReturnType ui8_RetVal_ErrStat;
	static boolean b_ReadFlagSuccess;
	
	if((uint8)DCM_INITIAL == OpStatus)
	{
		 b_ReadFlagSuccess = (boolean)FALSE;
	
		 /* PRQA S 0314 2 */ /* P2Obj to P2void conversion is safe */
		 ui8_RetVal_Read = Rte_Call_RP_Nvm_EOLCalibrationData_ReadBlock((void*)RAM_NVM_BLOCK_EOLCalibrationData);
	
		 if((uint8)E_OK == ui8_RetVal_Read)
		 {
		     ui8_RetVal_ErrStat = Rte_Call_RP_Nvm_EOLCalibrationData_GetErrorStatus(&ui8_ReadStatus);
	
			 if ( (uint8)E_OK == ui8_RetVal_ErrStat )
			 {
			     if ( ((uint8)NVM_REQ_OK == ui8_ReadStatus) ||
					((uint8)NVM_REQ_RESTORED_FROM_ROM == ui8_ReadStatus) ||
					((uint8)NVM_REQ_REDUNDANCY_FAILED == ui8_ReadStatus) )
				 {
				     b_ReadFlagSuccess = (boolean)TRUE;
				 }
				 else if ( (uint8)NVM_REQ_PENDING == ui8_ReadStatus )
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
	else if((uint8)DCM_PENDING == OpStatus)
	{  
		ui8_RetVal_ErrStat = Rte_Call_RP_Nvm_EOLCalibrationData_GetErrorStatus(&ui8_ReadStatus);
	
		if ( (uint8)E_OK == ui8_RetVal_ErrStat )
		{
			if ( ((uint8)NVM_REQ_OK == ui8_ReadStatus) ||
			((uint8)NVM_REQ_RESTORED_FROM_ROM == ui8_ReadStatus) ||
			((uint8)NVM_REQ_REDUNDANCY_FAILED == ui8_ReadStatus) )
			{
				b_ReadFlagSuccess = (boolean)TRUE;
			}
			else if ( (uint8)NVM_REQ_PENDING == ui8_ReadStatus )
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
	  else if((uint8)DCM_CANCEL == OpStatus)
	  {
		  (void)Rte_Call_RP_Nvm_EOLCalibrationData_GetErrorStatus(&ui8_ReadStatus);
	
			if ( (uint8)NVM_REQ_PENDING == ui8_ReadStatus )
			{
				ui8_RetVal_ErrStat = NvM_CancelJobs(NvMConf_NvMBlockDescriptor_NvM_Block_EOLCalibrationData);
	
				if ( (uint8)E_OK == ui8_RetVal_ErrStat )
				{
					u_RetVal = RTE_E_OK;
				}
				else
				{
					u_RetVal = RTE_E_INVALID;
				}
			}
			b_ReadFlagSuccess = (boolean)FALSE;
	
	  }
	  else
	  {
	   /*Do nothing.*/
	  }
	
	  if ((boolean)TRUE == b_ReadFlagSuccess )
	  {
		   /* PRQA S 0314 2 */ /* Pointer to void, no problem */
		   TS_MemCpy((void*)Data, (void*)RAM_NVM_BLOCK_EOLCalibrationData, EOLCALPARAMETER_LEN); /* PRQA S 3469,2 # 2023-06-13 Z.J.L: 3469: This usage of a function-like macro looks like it could be replaced by an equivalent function call. 3469: defined by Bsw platform header,check it ok */
		   u_RetVal = RTE_E_OK;
	  }
	  
#endif
	
	  return u_RetVal;

} /* FUNC(Std_ReturnType, RTE_CODE) Dsm_u_RDBI_EOL_CalibrationParameters_Read (Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_APPL_DATA) Data) */
#endif

/**
 * \functions Dsm_u_RDBI_EOL_CalibrationParameters_Read
 *
 * \brief Read calibration parameter of EOL from Data flash.(F1FA)
 *
 ** \param[in] none,
 *
 ** \param[out] Data, Pointer to Data buffer (1 bytes).
 **                  The DID format as below:
 **             byte0: Failure reason
 ** \return RTE_E_OK, 
 * \comments  
 *
 */
#if (DSM_FEAT_RDBI_EOL_LastResult == STD_ON)
FUNC(Std_ReturnType, RTE_CODE) Dsm_u_RDBI_EOL_LastResult_Read (Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_APPL_DATA) Data)/* PRQA S 03432,2 # 2023-06-13 Z.J.L: 3432: Simple macro argument expression is not parenthesized. 03432: Gnenerate by Rte,check it ok */
{
    /* suppress compiler warnings about unused arguments */
	Std_ReturnType u_RetVal = RTE_E_INVALID;
	(void)OpStatus;
	  
 #if((DSM_SYSTEM_TYPE == DSM_SYSTEM_MFC5J3_C673)|| \
		  (DSM_SYSTEM_TYPE == DSM_SYSTEM_MFC5J3_C385))
		  
	 if(NULL_PTR != Data)
	 {
		 TS_MemCpy(&Data[0], &RAM_NVM_BLOCK_EOLCalibrationData[8], EOL_LASTRESULT_LEN); /* PRQA S 3469,2 # 2023-06-13 Z.J.L: 3469: This usage of a function-like macro looks like it could be replaced by an equivalent function call. 3469: defined by Bsw platform header,check it ok */
		 u_RetVal = RTE_E_OK;
	 }
	 else
	 {/*Do nothing*/}
#endif
	  
	  return u_RetVal;

} /* FUNC(Std_ReturnType, RTE_CODE) Dsm_u_RDBI_EOL_LastResult_Read (Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_APPL_DATA) Data) */
#endif

/**
 * \functions Dsm_u_RDBI_EOL_Previous_EOLResult_Read
 *
 * \brief Read the result of EOL from Data flash.(F1FB)
 *
 ** \param[in] none,
 *
 ** \param[out] Data, Pointer to Data buffer (1 bytes).
 **                  The DID format as below:
 **             byte0: Failure reason
 ** \return RTE_E_OK, 
 * \comments  
 *
 */
#if (DSM_FEAT_RDBI_EOL_Previous_EOLResult == STD_ON)
FUNC(Std_ReturnType, RTE_CODE) Dsm_u_RDBI_EOL_Previous_EOLResult_Read (Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_APPL_DATA) Data)/* PRQA S 03432,2 # 2023-06-13 Z.J.L: 3432: Simple macro argument expression is not parenthesized. 03432: Gnenerate by Rte,check it ok */
{
    /* suppress compiler warnings about unused arguments */
	Std_ReturnType u_RetVal = RTE_E_INVALID;
	(void)OpStatus;
		
 #if((DSM_SYSTEM_TYPE == DSM_SYSTEM_MFC5J3_C673)|| \
			(DSM_SYSTEM_TYPE == DSM_SYSTEM_MFC5J3_C385))
			
	if(NULL_PTR != Data)
	{
		TS_MemCpy(&Data[0], &RAM_NVM_BLOCK_EOLCalibrationData[9], EOL_PRERESULT_LEN); /* PRQA S 3469,2 # 2023-06-13 Z.J.L: 3469: This usage of a function-like macro looks like it could be replaced by an equivalent function call. 3469: defined by Bsw platform header,check it ok */
		u_RetVal = RTE_E_OK;
	}
	else
	{/*Do nothing*/}
#endif
		
	return u_RetVal;

} /* FUNC(Std_ReturnType, RTE_CODE) Dsm_u_RDBI_EOL_Previous_EOLResult_Read (Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_APPL_DATA) Data) */
#endif

/**
 * \functions Dsm_u_RDBI_SDA_LastResults_Read
 *
 * \brief Read the last result of SDA from Data flash.(F1FC)
 *
 ** \param[in] none,
 *
 ** \param[out] Data, Pointer to Data buffer (1 bytes).
 **                  The DID format as below:
 **             byte0: Failure reason
 ** \return RTE_E_OK, 
 * \comments  
 *
 */
#if (DSM_FEAT_RDBI_SDA_LastResults == STD_ON)
FUNC(Std_ReturnType, RTE_CODE) Dsm_u_RDBI_SDA_LastResults_Read (Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_APPL_DATA) Data)/* PRQA S 03432,2 # 2023-06-13 Z.J.L: 3432: Simple macro argument expression is not parenthesized. 03432: Gnenerate by Rte,check it ok */
{
	 /* suppress compiler warnings about unused arguments */
	 Std_ReturnType u_RetVal = RTE_E_INVALID;
	 (void)OpStatus;
		  
 #if((DSM_SYSTEM_TYPE == DSM_SYSTEM_MFC5J3_C673)|| \
			  (DSM_SYSTEM_TYPE == DSM_SYSTEM_MFC5J3_C385))
			  
	 if(NULL_PTR != Data)
	 {
		 TS_MemCpy(&Data[0], RAM_NVM_BLOCK_SDACalibrationData, EOL_SDALASTRESULT_LEN); /* PRQA S 3469,2 # 2023-06-13 Z.J.L: 3469: This usage of a function-like macro looks like it could be replaced by an equivalent function call. 3469: defined by Bsw platform header,check it ok */
		 u_RetVal = RTE_E_OK;
	 }
	 else
	 {/*Do nothing*/}
#endif
		  
	 return u_RetVal;

} /* FUNC(Std_ReturnType, RTE_CODE) Dsm_u_RDBI_SDA_LastResults_Read (Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_APPL_DATA) Data) */
#endif

/**
 * \functions Dsm_u_RDBI_LaneFunctionConfiguration_Read
 *
 * \brief Read Lane function configuration from Data flash.(F1FE)
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
#if (DSM_FEAT_RDBI_LaneFunctionConfiguration == STD_ON)
FUNC(Std_ReturnType, RTE_CODE) Dsm_u_RDBI_LaneFunctionConfiguration_Read (Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_APPL_DATA) Data)/* PRQA S 03432,2 # 2023-06-13 Z.J.L: 3432: Simple macro argument expression is not parenthesized. 03432: Gnenerate by Rte,check it ok */
{
	   /* suppress compiler warnings about unused arguments */
	   Std_ReturnType u_RetVal = RTE_E_INVALID;
	   (void)OpStatus;
			
 #if((DSM_SYSTEM_TYPE == DSM_SYSTEM_MFC5J3_C673)|| \
				(DSM_SYSTEM_TYPE == DSM_SYSTEM_MFC5J3_C385))
				
	   if(NULL_PTR != Data)
	   {
		   TS_MemCpy(&Data[0], RAM_NVM_BLOCK_LaneFunctionConfiguration, LANEFUNCCONFIG_LEN); /* PRQA S 3469,2 # 2023-06-13 Z.J.L: 3469: This usage of a function-like macro looks like it could be replaced by an equivalent function call. 3469: defined by Bsw platform header,check it ok */
		   u_RetVal = RTE_E_OK;
	   }
	   else
	   {/*Do nothing*/}
#endif
			
	   return u_RetVal;

} /* FUNC(Std_ReturnType, RTE_CODE) Dsm_u_RDBI_LaneFunctionConfiguration_Read (Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_APPL_DATA) Data) */
#endif

/**
 * \functions Dsm_u_RDBI_EOL_ModeGate_Read
 *
 * \brief Read EOL mode gate from specific DF static Address.(F1FF)
 *
 ** \param[in] none,
 *
 ** \param[out] Data, Pointer to Data buffer (2 bytes).
 **                  ASCII formatted
 *
 ** \return RTE_E_OK, 
 * \comments  base Address:0xAF07B000 startAddress: 0xAF07B028  Total Length: 2byte
 *
 */
#if (DSM_FEAT_RDBI_EOL_ModeGate == STD_ON)
FUNC(Std_ReturnType, RTE_CODE) Dsm_u_RDBI_EOL_ModeGate_Read (Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_APPL_DATA) Data)/* PRQA S 03432,2 # 2023-06-13 Z.J.L: 3432: Simple macro argument expression is not parenthesized. 03432: Gnenerate by Rte,check it ok */
{
	  /* suppress compiler warnings about unused arguments */
	  Std_ReturnType u_RetVal = RTE_E_OK;
	  
#if((DSM_SYSTEM_TYPE == DSM_SYSTEM_MFC5J3_C673)|| \
				(DSM_SYSTEM_TYPE == DSM_SYSTEM_MFC5J3_C385))	
				
      Std_ReturnType ui8_RetVal_Read = E_NOT_OK; 
	  static uint8 ui8_QsmReqStatus = QSM_REQRESULT_NOT_OK; 
	  static boolean b_ReadFlagSuccess;
	  
	  if((uint8)DCM_INITIAL == OpStatus)
	  {
		  b_ReadFlagSuccess = (boolean)FALSE;

		  ui8_RetVal_Read = Rte_Call_RP_Qsm_Block_EOLModeGateOP_Qsm_ReadBlock((void*)&s_QSBlock_EcuSpecInfo, 0, sizeof(s_QSBlock_EcuSpecInfo));

		  if ((uint8)E_OK == ui8_RetVal_Read)
		  {
              ui8_QsmReqStatus = Rte_Call_RP_Qsm_Block_EOLModeGateOP_Qsm_GetErrorStatues();
		  
		      if(QSM_REQRESULT_PENDING == ui8_QsmReqStatus)
	          {
		          u_RetVal = DCM_E_PENDING;
		      }
		      else if(QSM_REQRESULT_OK == ui8_QsmReqStatus)
		      {
		          b_ReadFlagSuccess = (boolean)TRUE;
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
	  else if((uint8)DCM_PENDING == OpStatus)
	  {
		  ui8_QsmReqStatus = Rte_Call_RP_Qsm_Block_EOLModeGateOP_Qsm_GetErrorStatues();
		  
		  if(QSM_REQRESULT_PENDING == ui8_QsmReqStatus)
	      {
		      u_RetVal = DCM_E_PENDING;
		  }
		  else if(QSM_REQRESULT_OK == ui8_QsmReqStatus)
		  {
		      b_ReadFlagSuccess = (boolean)TRUE;
		  }
		  else
		  {
		      u_RetVal = RTE_E_INVALID;	
		  }  
	  }
	  else if((uint8)DCM_CANCEL == OpStatus)
	  {
		  b_ReadFlagSuccess = (boolean)FALSE;
		  u_RetVal = RTE_E_INVALID;
	  }
	  else
	  {
		  /*Do nothing*/
	  }

	  if((boolean)TRUE == b_ReadFlagSuccess)
	  {
		  /* PRQA S 0314 2 */ /* Pointer to void, no problem */
		  TS_MemCpy((void*)Data, (void*)s_QSBlock_EcuSpecInfo.F1FF, EOLMODEGATE_LEN); /* PRQA S 3469,2 # 2023-06-13 Z.J.L: 3469: This usage of a function-like macro looks like it could be replaced by an equivalent function call. 3469: defined by Bsw platform header,check it ok */
		  u_RetVal = RTE_E_OK;
	  }
#endif
  
	return u_RetVal;

} /* FUNC(Std_ReturnType, RTE_CODE) Dsm_u_RDBI_EOL_ModeGate_Read (Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_APPL_DATA) Data) */
#endif


/**
 * \functions Dsm_u_RDBI_FCW_Lastbutoneappeared_Read
 *
 * \brief Read FCW last butoneappeared from Data flash.(FD14)
 *
 ** \param[in] none,
 *
 ** \param[out] Data, Pointer to Data buffer (49 bytes).
 **                  unsigned formatted
 *
 ** \return RTE_E_OK, 
 * \comments  
 *
 */
#if (DSM_FEAT_RDBI_FCW_Lastbutoneappeared == STD_ON)
FUNC(Std_ReturnType, RTE_CODE) Dsm_u_RDBI_FCW_Lastbutoneappeared_Read (Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_APPL_DATA) Data)/* PRQA S 03432,2 # 2023-06-13 Z.J.L: 3432: Simple macro argument expression is not parenthesized. 03432: Gnenerate by Rte,check it ok */
{
    /* suppress compiler warnings about unused arguments */
	Std_ReturnType u_RetVal = RTE_E_INVALID;
	(void)OpStatus;
			  
 #if((DSM_SYSTEM_TYPE == DSM_SYSTEM_MFC5J3_C673)|| \
				  (DSM_SYSTEM_TYPE == DSM_SYSTEM_MFC5J3_C385))
				  
	if(NULL_PTR != Data)
	{
	    TS_MemCpy(&Data[0], RAM_NVM_BLOCK_FCWLastbutoneappearedFD14, FCW_LASTBUTONEAPPEARED_LEN); /* PRQA S 3469,2 # 2023-06-13 Z.J.L: 3469: This usage of a function-like macro looks like it could be replaced by an equivalent function call. 3469: defined by Bsw platform header,check it ok */
		u_RetVal = RTE_E_OK;
	}
	else
	{/*Do nothing*/}
#endif
			  
	return u_RetVal;

} /* FUNC(Std_ReturnType, RTE_CODE) Dsm_u_RDBI_FCW_Lastbutoneappeared_Read (Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_APPL_DATA) Data) */
#endif

/**
 * \functions Dsm_u_RDBI_AWB_Lastbutoneappeared_Read
 *
 * \brief Read AWB last butoneappeared from Data flash.(FD15)
 *
 ** \param[in] none,
 *
 ** \param[out] Data, Pointer to Data buffer (49 bytes).
 **                  unsigned formatted
 *
 ** \return RTE_E_OK, 
 * \comments  
 *
 */
#if (DSM_FEAT_RDBI_AWB_Lastbutoneappeared == STD_ON)
FUNC(Std_ReturnType, RTE_CODE) Dsm_u_RDBI_AWB_Lastbutoneappeared_Read (Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_APPL_DATA) Data)/* PRQA S 03432,2 # 2023-06-13 Z.J.L: 3432: Simple macro argument expression is not parenthesized. 03432: Gnenerate by Rte,check it ok */
{
	/* suppress compiler warnings about unused arguments */
	Std_ReturnType u_RetVal = RTE_E_INVALID;
	(void)OpStatus;
				
 #if((DSM_SYSTEM_TYPE == DSM_SYSTEM_MFC5J3_C673)|| \
					(DSM_SYSTEM_TYPE == DSM_SYSTEM_MFC5J3_C385))
					
	if(NULL_PTR != Data)
	{
		TS_MemCpy(&Data[0], RAM_NVM_BLOCK_AWBLastbutoneappearFD15, AWB_LASTBUTONEAPPEARED_LEN); /* PRQA S 3469,2 # 2023-06-13 Z.J.L: 3469: This usage of a function-like macro looks like it could be replaced by an equivalent function call. 3469: defined by Bsw platform header,check it ok */
		u_RetVal = RTE_E_OK;
	}
	else
	{/*Do nothing*/}
#endif
				
	return u_RetVal;

} /* FUNC(Std_ReturnType, RTE_CODE) Dsm_u_RDBI_AWB_Lastbutoneappeared_Read (Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_APPL_DATA) Data) */
#endif

/**
 * \functions Dsm_u_RDBI_AEB_Lastbutoneappeared_Read
 *
 * \brief Read AEB last butoneappeared from Data flash.(FD16)
 *
 ** \param[in] none,
 *
 ** \param[out] Data, Pointer to Data buffer (49 bytes).
 **                  unsigned formatted
 *
 ** \return RTE_E_OK, 
 * \comments  
 *
 */
#if (DSM_FEAT_RDBI_AEB_Lastbutoneappeared == STD_ON)
FUNC(Std_ReturnType, RTE_CODE) Dsm_u_RDBI_AEB_Lastbutoneappeared_Read (Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_APPL_DATA) Data)/* PRQA S 03432,2 # 2023-06-13 Z.J.L: 3432: Simple macro argument expression is not parenthesized. 03432: Gnenerate by Rte,check it ok */
{
	  /* suppress compiler warnings about unused arguments */
	  Std_ReturnType u_RetVal = RTE_E_INVALID;
	  (void)OpStatus;
				  
 #if((DSM_SYSTEM_TYPE == DSM_SYSTEM_MFC5J3_C673)|| \
					  (DSM_SYSTEM_TYPE == DSM_SYSTEM_MFC5J3_C385))
					  
	  if(NULL_PTR != Data)
	  {
		  TS_MemCpy(&Data[0], RAM_NVM_BLOCK_AEBLastbutoneappearFD16, AEB_LASTBUTONEAPPEARED_LEN); /* PRQA S 3469,2 # 2023-06-13 Z.J.L: 3469: This usage of a function-like macro looks like it could be replaced by an equivalent function call. 3469: defined by Bsw platform header,check it ok */
		  u_RetVal = RTE_E_OK;
	  }
	  else
	  {/*Do nothing*/}
#endif
				  
	  return u_RetVal;

} /* FUNC(Std_ReturnType, RTE_CODE) Dsm_u_RDBI_AEB_Lastbutoneappeared_Read (Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_APPL_DATA) Data) */
#endif

/**
 * \functions Dsm_u_RDBI_FCW_Lastappeared_Read
 *
 * \brief Read FCW last appeared from Data flash.(FD17)
 *
 ** \param[in] OpStatus, 
 *
 ** \param[out] Data, Pointer to Data buffer (49 bytes).
 **                  unsigned formatted
 *
 ** \return RTE_E_OK, 
 * \comments  
 *
 */
#if (DSM_FEAT_RDBI_FCW_Lastappeared == STD_ON)
FUNC(Std_ReturnType, RTE_CODE) Dsm_u_RDBI_FCW_Lastappeared_Read (Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_APPL_DATA) Data)/* PRQA S 03432,2 # 2023-06-13 Z.J.L: 3432: Simple macro argument expression is not parenthesized. 03432: Gnenerate by Rte,check it ok */
{
	/* suppress compiler warnings about unused arguments */
	Std_ReturnType u_RetVal = RTE_E_INVALID;
	(void)OpStatus;
					
 #if((DSM_SYSTEM_TYPE == DSM_SYSTEM_MFC5J3_C673)|| \
						(DSM_SYSTEM_TYPE == DSM_SYSTEM_MFC5J3_C385))
						
	if(NULL_PTR != Data)
	{
		TS_MemCpy(&Data[0], RAM_NVM_BLOCK_FCWLastappearFD17, FCW_LASTAPPEARED_LEN); /* PRQA S 3469,2 # 2023-06-13 Z.J.L: 3469: This usage of a function-like macro looks like it could be replaced by an equivalent function call. 3469: defined by Bsw platform header,check it ok */
		u_RetVal = RTE_E_OK;
	}
	else
	{/*Do nothing*/}
#endif
					
    return u_RetVal;

} /* FUNC(Std_ReturnType, RTE_CODE) Dsm_u_RDBI_FCW_Lastappeared_Read (Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_APPL_DATA) Data) */
#endif

/**
 * \functions Dsm_u_RDBI_AWB_Lastappeared_Read
 *
 * \brief Read FCW last appeared from Data flash.(FD18)
 *
 ** \param[in] OpStatus, 
 *
 ** \param[out] Data, Pointer to Data buffer (49 bytes).
 **                  unsigned formatted
 *
 ** \return RTE_E_OK, 
 * \comments  
 *
 */
#if (DSM_FEAT_RDBI_AWB_Lastappeared == STD_ON)
FUNC(Std_ReturnType, RTE_CODE) Dsm_u_RDBI_AWB_Lastappeared_Read (Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_APPL_DATA) Data)/* PRQA S 03432,2 # 2023-06-13 Z.J.L: 3432: Simple macro argument expression is not parenthesized. 03432: Gnenerate by Rte,check it ok */
{
    /* suppress compiler warnings about unused arguments */
	Std_ReturnType u_RetVal = RTE_E_INVALID;
	(void)OpStatus;
					  
 #if((DSM_SYSTEM_TYPE == DSM_SYSTEM_MFC5J3_C673)|| \
						  (DSM_SYSTEM_TYPE == DSM_SYSTEM_MFC5J3_C385))					  
	if(NULL_PTR != Data)
	{
		TS_MemCpy(&Data[0], RAM_NVM_BLOCK_AWBLasteappearFD18, AWB_LASTAPPEARED_LEN); /* PRQA S 3469,2 # 2023-06-13 Z.J.L: 3469: This usage of a function-like macro looks like it could be replaced by an equivalent function call. 3469: defined by Bsw platform header,check it ok */
		u_RetVal = RTE_E_OK;
	}
	else
	{/*Do nothing*/}
#endif
					  
	  return u_RetVal;

} /* FUNC(Std_ReturnType, RTE_CODE) Dsm_u_RDBI_AWB_Lastappeared_Read (Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_APPL_DATA) Data) */
#endif

/**
 * \functions Dsm_u_RDBI_AEB_Lastappeared_Read
 *
 * \brief Read AEB last appeared from Data flash.(FD19)
 *
 ** \param[in] OpStatus, 
 *
 ** \param[out] Data, Pointer to Data buffer (49 bytes).
 **                  unsigned formatted
 *
 ** \return RTE_E_OK, 
 * \comments  
 *
 */
#if (DSM_FEAT_RDBI_AEB_Lastappeared == STD_ON)
FUNC(Std_ReturnType, RTE_CODE) Dsm_u_RDBI_AEB_Lastappeared_Read (Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_APPL_DATA) Data)/* PRQA S 03432,2 # 2023-06-13 Z.J.L: 3432: Simple macro argument expression is not parenthesized. 03432: Gnenerate by Rte,check it ok */
{
    /* suppress compiler warnings about unused arguments */
	Std_ReturnType u_RetVal = RTE_E_INVALID;
	(void)OpStatus;
						
 #if((DSM_SYSTEM_TYPE == DSM_SYSTEM_MFC5J3_C673)|| \
							(DSM_SYSTEM_TYPE == DSM_SYSTEM_MFC5J3_C385))					
	if(NULL_PTR != Data)
	{
	    TS_MemCpy(&Data[0], RAM_NVM_BLOCK_AEBLastappearFD19, AEB_LASTAPPEARED_LEN); /* PRQA S 3469,2 # 2023-06-13 Z.J.L: 3469: This usage of a function-like macro looks like it could be replaced by an equivalent function call. 3469: defined by Bsw platform header,check it ok */
		u_RetVal = RTE_E_OK;
	}
	else
	{/*Do nothing*/}
#endif
						
	return u_RetVal;

} /* FUNC(Std_ReturnType, RTE_CODE) Dsm_u_RDBI_AEB_Lastappeared_Read (Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_APPL_DATA) Data) */
#endif

/**
 * \functions Dsm_u_RDBI_InternalSocTemperature_Read
 *
 * \brief Read The internal temperature of Soc via SPI.(FD1E)
 *
 ** \param[in] OpStatus, 
 *
 ** \param[out] Data, Pointer to Data buffer (2 bytes).
 **                  unsigned formatted
 *
 ** \return RTE_E_OK, 
 * \comments  
 *
 */
#if (DSM_FEAT_RDBI_InternalSocTemperature == STD_ON)
FUNC(Std_ReturnType, RTE_CODE) Dsm_u_RDBI_InternalSocTemperature_Read (Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_APPL_DATA) Data)/* PRQA S 03432,2 # 2023-06-13 Z.J.L: 3432: Simple macro argument expression is not parenthesized. 03432: Gnenerate by Rte,check it ok */
{
    /* suppress compiler warnings about unused arguments */
    Std_ReturnType u_RetVal = RTE_E_INVALID;
	(void)OpStatus;
#if((DSM_SYSTEM_TYPE == DSM_SYSTEM_MFC5J3_C673)|| \
							(DSM_SYSTEM_TYPE == DSM_SYSTEM_MFC5J3_C385))
	s_Sdc_SocSystemInfo_t s_SocData ;
	uint16_t ui16_length = 0;						
	float32 f32_SocTemperature = 0.0f;
	uint16 ui16_SocTemperature = 0;
	
	(void)Rte_Call_RP_Sdc_SendInterface_SocInfo_SocCpuInfo_Read(&s_SocData, ui16_length);

	/*transfer integer to Physhical value */
	f32_SocTemperature = (float32)((int)(s_SocData.cpu_temp/SPI_SOCTEMP_FACTOR));
		
    if((f32_SocTemperature < DSM_SOCTEMP_MIN_THLSD) || (f32_SocTemperature > DSM_SOCTEMP_MAX_THLSD))
	{
	    u_RetVal = RTE_E_INVALID; //return NRC10
	}
	else
	{
	    /*Physhical value to uint16 */
		ui16_SocTemperature = (uint16_t)((float32_t)(((f32_SocTemperature + 50.0f) * 100.0f) + 0.5f));
		u_RetVal = RTE_E_OK;
	} 

	Data[0] = (uint8)(ui16_SocTemperature >> 8);
	Data[1] = (uint8)(ui16_SocTemperature & ((uint8_t)0xFF));
#endif

	return u_RetVal;

} /* FUNC(Std_ReturnType, RTE_CODE) Dsm_u_RDBI_InternalSocTemperature_Read (Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_APPL_DATA) Data) */
#endif

/**
 * \functions Dsm_u_RDBI_PCBASerialNumberDataIdentifier_Read
 *
 * \brief Read PCBA serial number data identifier from Data flash.(FD24)
 *
 ** \param[in] OpStatus, 
 *
 ** \param[out] Data, Pointer to Data buffer (5 bytes).
 **                  unsigned formatted
 *
 ** \return RTE_E_OK, 
 * \comments  
 *
 */
#if (DSM_FEAT_RDBI_PCBASerialNumberDataIdentifier == STD_ON)
FUNC(Std_ReturnType, RTE_CODE) Dsm_u_RDBI_PCBASerialNumberDataIdentifier_Read (Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_APPL_DATA) Data)/* PRQA S 03432,2 # 2023-06-13 Z.J.L: 3432: Simple macro argument expression is not parenthesized. 03432: Gnenerate by Rte,check it ok */
{
    /* suppress compiler warnings about unused arguments */
	Std_ReturnType u_RetVal = RTE_E_INVALID;
	(void)OpStatus;
						  
 #if((DSM_SYSTEM_TYPE == DSM_SYSTEM_MFC5J3_C673)|| \
							  (DSM_SYSTEM_TYPE == DSM_SYSTEM_MFC5J3_C385))					  
	if(NULL_PTR != Data)
	{
	    (void)TS_MemCpy(&Data[0], RAM_NVM_BLOCK_PCBASerialNumberDataIdentifier, PCBASNDATAIDENT_LEN); /* PRQA S 3469,2 # 2023-06-13 Z.J.L: 3469: This usage of a function-like macro looks like it could be replaced by an equivalent function call. 3469: defined by Bsw platform header,check it ok */
		u_RetVal = RTE_E_OK;
	}
	else
	{/*Do nothing*/}
#endif
						  
	return u_RetVal;

} /* FUNC(Std_ReturnType, RTE_CODE) Dsm_u_RDBI_PCBASerialNumberDataIdentifier_Read (Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_APPL_DATA) Data) */
#endif

/**
 * \functions Dsm_u_RDBI_ImagerTemperature_Read
 *
 * \brief Read The Imager temperature of Soc via SPI.(FD25)
 *
 ** \param[in] OpStatus, 
 *
 ** \param[out] Data, Pointer to Data buffer (2 bytes).
 **                  unsigned formatted
 *
 ** \return RTE_E_OK, 
 * \comments  
 *
 */
#if (DSM_FEAT_RDBI_ImagerTemperature == STD_ON)
FUNC(Std_ReturnType, RTE_CODE) Dsm_u_RDBI_ImagerTemperature_Read (Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_APPL_DATA) Data)/* PRQA S 03432,2 # 2023-06-13 Z.J.L: 3432: Simple macro argument expression is not parenthesized. 03432: Gnenerate by Rte,check it ok */
{
    /* suppress compiler warnings about unused arguments */
	Std_ReturnType u_RetVal = RTE_E_INVALID;
	(void)OpStatus;
#if((DSM_SYSTEM_TYPE == DSM_SYSTEM_MFC5J3_C673)|| \
							  (DSM_SYSTEM_TYPE == DSM_SYSTEM_MFC5J3_C385))
	s_Sdc_SocSystemInfo_t s_SocData;	
	uint16_t ui16_length = 0;					  
	float32 f32_ImagerTemperature = 0.0f;
	uint16 ui16_ImagerTemperature = 0;

	(void)Rte_Call_RP_Sdc_SendInterface_SocInfo_SocCpuInfo_Read(&s_SocData, ui16_length);
	  
	/*transfer integer to Physhical value */
	f32_ImagerTemperature = (float32)((int)(s_SocData.sensor_temp/SPI_IMAGETEMP_FACTOR));
		  
    if((f32_ImagerTemperature < DSM_IMAGERTEMP_MIN_THLSD) || (f32_ImagerTemperature > DSM_IMAGERTEMP_MAX_THLSD))
	{
	    u_RetVal = RTE_E_INVALID; //return NRC10
	}
	else
	{
		/*Physhical value to uint16 */
	    ui16_ImagerTemperature = (uint16)((float32_t)(((f32_ImagerTemperature + 50.0f) * 100.0f) + 0.5f));
		u_RetVal = RTE_E_OK;
	} 
	  
	Data[0] = (uint8)(ui16_ImagerTemperature >> 8);
	Data[1] = (uint8)(ui16_ImagerTemperature & ((uint8_t)0xFF));
#endif
  
	  return u_RetVal;

} /* FUNC(Std_ReturnType, RTE_CODE) Dsm_u_RDBI_ImagerTemperature_Read (Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_APPL_DATA) Data) */
#endif

/**
 * \functions Dsm_u_RDBI_SecureUpdateLog_Read
 *
 * \brief Read secure update log from specific DF static Address.(FEC0)
 *
 ** \param[in] none,
 *
 ** \param[out] Data, Pointer to Data buffer (16 bytes).
 **                  unisgned formatted
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
#if (DSM_FEAT_RDBI_SecureUpdateLog == STD_ON)
FUNC(Std_ReturnType, RTE_CODE) Dsm_u_RDBI_SecureUpdateLog_Read (Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_APPL_DATA) Data)/* PRQA S 03432,2 # 2023-06-13 Z.J.L: 3432: Simple macro argument expression is not parenthesized. 03432: Gnenerate by Rte,check it ok */
{
    /* suppress compiler warnings about unused arguments */
    Std_ReturnType u_RetVal = RTE_E_OK;
		
#if((DSM_SYSTEM_TYPE == DSM_SYSTEM_MFC5J3_C673)|| \
				  (DSM_SYSTEM_TYPE == DSM_SYSTEM_MFC5J3_C385))		
	Std_ReturnType ui8_RetVal_Read = E_NOT_OK; 
	static uint8 ui8_QsmReqStatus = QSM_REQRESULT_NOT_OK; 
	static boolean b_ReadFlagSuccess;
		
	if((uint8)DCM_INITIAL == OpStatus)
	{
		b_ReadFlagSuccess = (boolean)FALSE;
		
		ui8_RetVal_Read = Rte_Call_RP_Qsm_BlockSecureUpdateLogOp_Qsm_ReadBlock((void*)&s_QSBlock_SecureUpdateInfo, 0, sizeof(s_QSBlock_SecureUpdateInfo));

		if ((uint8)E_OK == ui8_RetVal_Read)
		{
            ui8_QsmReqStatus = Rte_Call_RP_Qsm_BlockSecureUpdateLogOp_Qsm_GetErrorStatues();
		  
		    if(QSM_REQRESULT_PENDING == ui8_QsmReqStatus)
	        {
		        u_RetVal = DCM_E_PENDING;
		    }
		    else if(QSM_REQRESULT_OK == ui8_QsmReqStatus)
		    {
		        b_ReadFlagSuccess = (boolean)TRUE;
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
	else if((uint8)DCM_PENDING == OpStatus)
	{
	    ui8_QsmReqStatus = Rte_Call_RP_Qsm_BlockSecureUpdateLogOp_Qsm_GetErrorStatues();
			 
		if(QSM_REQRESULT_PENDING == ui8_QsmReqStatus)
		{
			u_RetVal = DCM_E_PENDING;
		}
		else if(QSM_REQRESULT_OK == ui8_QsmReqStatus)
		{
			b_ReadFlagSuccess = (boolean)TRUE;
		}
		else
		{
			u_RetVal = RTE_E_INVALID; 
		}
			 
	}
	else if((uint8)DCM_CANCEL == OpStatus)
	{
		b_ReadFlagSuccess = (boolean)FALSE;
		u_RetVal = RTE_E_INVALID;
	}
	else
	{
		/*Do nothing*/
	}
	
	if((boolean)TRUE == b_ReadFlagSuccess)
	{
		/* PRQA S 0314 2 */ /* Pointer to void, no problem */
		Data[0] = (uint8)(s_QSBlock_SecureUpdateInfo.SecLogInfo.u_AttemptDownloadingCounter >> 8);
		Data[1] = (uint8)(s_QSBlock_SecureUpdateInfo.SecLogInfo.u_AttemptDownloadingCounter);
		Data[2] = (uint8)(s_QSBlock_SecureUpdateInfo.SecLogInfo.u_FlashDriverActivatedSuccessfullyCounter >> 8);
		Data[3] = (uint8)(s_QSBlock_SecureUpdateInfo.SecLogInfo.u_FlashDriverActivatedSuccessfullyCounter);
		Data[4] = (uint8)(s_QSBlock_SecureUpdateInfo.SecLogInfo.u_AppDownloadedSuccessfullyCounter >> 8);
		Data[5] = (uint8)(s_QSBlock_SecureUpdateInfo.SecLogInfo.u_AppDownloadedSuccessfullyCounter);
		Data[6] = (uint8)(s_QSBlock_SecureUpdateInfo.SecLogInfo.u_FblDownloadedSuccessfullyCounter >> 8);
		Data[7] = (uint8)(s_QSBlock_SecureUpdateInfo.SecLogInfo.u_FblDownloadedSuccessfullyCounter);	
		u_RetVal = RTE_E_OK;
	}
#endif
    return u_RetVal;
} /* FUNC(Std_ReturnType, RTE_CODE) Dsm_u_RDBI_SecureUpdateLog_Read (Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_APPL_DATA) Data) */
#endif

/**
 * \functions Dsm_u_RDBI_InternalTestMode_Read
 *
 * \brief Read internal test mode from RAM.(FDFF)
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
#if (DSM_FEAT_RDBI_InternalTestMode == STD_ON)
FUNC(Std_ReturnType, RTE_CODE) Dsm_u_RDBI_InternalTestMode_Read (Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_APPL_DATA) Data)/* PRQA S 03432,2 # 2023-06-13 Z.J.L: 3432: Simple macro argument expression is not parenthesized. 03432: Gnenerate by Rte,check it ok */
{
    /* suppress compiler warnings about unused arguments */
    Std_ReturnType u_RetVal = RTE_E_OK;
    (void)OpStatus;
	
#if((DSM_SYSTEM_TYPE == DSM_SYSTEM_MFC5J3_C673)|| \
				  (DSM_SYSTEM_TYPE == DSM_SYSTEM_MFC5J3_C385))		
    Data[0] = Rte_IrvRead_Dsm_u_RDBI_InternalTestMode_Read_Dsm_IRV_InternalTestMode(); /* PRQA S 3469,2 # 2023-06-13 Z.J.L: 3469: This usage of a function-like macro looks like it could be replaced by an equivalent function call. 3469: defined by Bsw platform header,check it ok */
#endif

    return u_RetVal;
} /* FUNC(Std_ReturnType, RTE_CODE) Dsm_u_RDBI_InternalTestMode_Read (Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_APPL_DATA) Data) */
#endif

/**
 * \functions Dsm_u_RDBI_SocSupplierSoftwareNumber_Read
 *
 * \brief Read Soc supplier software number from Soc via SPI.(F194)
 *
 ** \param[in] OpStatus, 
 *
 ** \param[out] Data, Pointer to Data buffer (8 bytes).
 **                  unsigned formatted
 *
 ** \return RTE_E_OK, 
 * \comments  
 *
 */
#if (DSM_FEAT_RDBI_SocSupplierSoftwareNumber == STD_ON)
FUNC(Std_ReturnType, RTE_CODE) Dsm_u_RDBI_SocSupplierSoftwareNumber_Read (Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_APPL_DATA) Data)/* PRQA S 03432,2 # 2023-06-13 Z.J.L: 3432: Simple macro argument expression is not parenthesized. 03432: Gnenerate by Rte,check it ok */
{
    /* suppress compiler warnings about unused arguments */
    Std_ReturnType u_RetVal = RTE_E_OK;
	
#if((DSM_SYSTEM_TYPE == DSM_SYSTEM_MFC5J3_C673)|| \
				  (DSM_SYSTEM_TYPE == DSM_SYSTEM_MFC5J3_C385))
				  
	Std_ReturnType u_RetVal_Read = RTE_E_OK; 
	static uint8 a_Mirror_Block[SOCSSNUMBER_LEN] = {0};
	static boolean b_ReadFlagSuccess;
	static uint16 u_Requestcounter =0;
	static uint16 u_Readcounter =0;
	
    if((uint8)DCM_INITIAL == OpStatus)
    {
		b_ReadFlagSuccess = (boolean)FALSE;
		
  	    (void)TS_MemBZero(a_Mirror_Block, SOCSSNUMBER_LEN);
		
		u_RetVal = DCM_E_PENDING;
	}
	else if((uint8)DCM_PENDING == OpStatus)
	{
		u_RetVal_Read = Rte_Call_RP_Sdc_SendInterface_Diag_UdsRequest(UDSTYPE_DID, 0x1200, NULL_PTR, 0, a_Mirror_Block, SOCSSNUMBER_LEN);
	  
		if(u_RetVal_Read == RTE_E_OK)
		{
			b_ReadFlagSuccess = (boolean)TRUE;
		}
		else
		{
			if(u_RetVal_Read == DCM_E_PENDING)
            {
                u_RetVal = u_RetVal_Read;
            }
		    else if (u_RetVal_Read == RTE_E_INVALID)
		    {
                u_Readcounter++;
			    if(u_Readcounter <200u)
			    {
				    u_RetVal = DCM_E_PENDING;
			    }
			    else
			    {
				    u_RetVal = RTE_E_INVALID;
				    u_Readcounter =0u;
			    }
		    }
			else
			{/*Do nothing*/}
		} 	
	}
	else if((uint8)DCM_CANCEL == OpStatus)
	{
		b_ReadFlagSuccess = (boolean)FALSE;	
	}
	else
	{
        /*Do nothing*/
	}

	if((boolean)TRUE == b_ReadFlagSuccess)
	{
		/* PRQA S 0314 2 */ /* Pointer to void, no problem */
		(void)TS_MemCpy((void*)Data, (void*)a_Mirror_Block, SOCSSNUMBER_LEN); /* PRQA S 3469,2 # 2023-06-13 Z.J.L: 3469: This usage of a function-like macro looks like it could be replaced by an equivalent function call. 3469: defined by Bsw platform header,check it ok */
		u_RetVal = RTE_E_OK;
	}
#endif

	return u_RetVal;
} /* FUNC(Std_ReturnType, RTE_CODE) Dsm_u_RDBI_SocSupplierSoftwareNumber_Read (Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_APPL_DATA) Data) */
#endif

/**
 * \functions Dsm_u_RDBI_SocSoftwareVersion_Read
 *
 * \brief Read Soc supplier software number from Soc via SPI.(FD1F)
 *
 ** \param[in] OpStatus, 
 *
 ** \param[out] Data, Pointer to Data buffer (8 bytes).
 **                  unsigned formatted
 *
 ** \return RTE_E_OK, 
 * \comments  
 *
 */
#if (DSM_FEAT_RDBI_SocSoftwareVersion == STD_ON)
FUNC(Std_ReturnType, RTE_CODE) Dsm_u_RDBI_SocSoftwareVersion_Read (Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_APPL_DATA) Data)/* PRQA S 03432,2 # 2023-06-13 Z.J.L: 3432: Simple macro argument expression is not parenthesized. 03432: Gnenerate by Rte,check it ok */
{
    /* suppress compiler warnings about unused arguments */
	Std_ReturnType u_RetVal = RTE_E_OK;
	  
#if((DSM_SYSTEM_TYPE == DSM_SYSTEM_MFC5J3_C673)|| \
					(DSM_SYSTEM_TYPE == DSM_SYSTEM_MFC5J3_C385))
					
	Std_ReturnType u_RetVal_Read = RTE_E_OK; 
	static uint8 a_Mirror_Block[SOCSOFTVER_LEN] = {0};
	static boolean b_ReadFlagSuccess;
	static uint16 u_Requestcounter =0;
	static uint16 u_Readcounter =0;
	  
	if((uint8)DCM_INITIAL == OpStatus)
	{
		b_ReadFlagSuccess = (boolean)FALSE;
		
  	    (void)TS_MemBZero(a_Mirror_Block, SOCSOFTVER_LEN);
		
		u_RetVal = DCM_E_PENDING;
	}
	else if((uint8)DCM_PENDING == OpStatus)
	{
		u_RetVal_Read = Rte_Call_RP_Sdc_SendInterface_Diag_UdsRequest(UDSTYPE_DID, 0x1200, NULL_PTR, 0, a_Mirror_Block, SOCSOFTVER_LEN);
	  
		if(u_RetVal_Read == RTE_E_OK)
		{
			b_ReadFlagSuccess = (boolean)TRUE;
		}
		else
		{
			if(u_RetVal_Read == DCM_E_PENDING)
            {
                u_RetVal = u_RetVal_Read;
            }
		    else if (u_RetVal_Read == RTE_E_INVALID)
		    {
                u_Readcounter++;
			    if(u_Readcounter <200u)
			    {
				    u_RetVal = DCM_E_PENDING;
			    }
			    else
			    {
				    u_RetVal = RTE_E_INVALID;
				    u_Readcounter =0u;
			    }
		    }
			else
			{/*Do nothing*/}
		} 	
	}
	else if((uint8)DCM_CANCEL == OpStatus)
	{
		b_ReadFlagSuccess = (boolean)FALSE;	
	}
	else
	{
		/*Do nothing*/
	}
  
	if((boolean)TRUE == b_ReadFlagSuccess)
	{
		/* PRQA S 0314 2 */ /* Pointer to void, no problem */
		(void)TS_MemCpy((void*)Data, (void*)a_Mirror_Block, SOCSOFTVER_LEN); /* PRQA S 3469,2 # 2023-06-13 Z.J.L: 3469: This usage of a function-like macro looks like it could be replaced by an equivalent function call. 3469: defined by Bsw platform header,check it ok */
		u_RetVal = RTE_E_OK;
	}
#endif
  
	return u_RetVal;

} /* FUNC(Std_ReturnType, RTE_CODE) Dsm_u_RDBI_SocSoftwareVersion_Read (Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_APPL_DATA) Data) */
#endif

/**
 * \functions Dsm_u_RDBI_OMSN_Read
 *
 * \brief Read OMSN from Soc via SPI.(FD22)
 *
 ** \param[in] OpStatus, 
 *
 ** \param[out] Data, Pointer to Data buffer (4 bytes).
 **                  unsigned formatted
 *
 ** \return RTE_E_OK, 
 * \comments  
 *
 */
#if (DSM_FEAT_RDBI_OMSN == STD_ON)
FUNC(Std_ReturnType, RTE_CODE) Dsm_u_RDBI_OMSN_Read (Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_APPL_DATA) Data)/* PRQA S 03432,2 # 2023-06-13 Z.J.L: 3432: Simple macro argument expression is not parenthesized. 03432: Gnenerate by Rte,check it ok */
{
    /* suppress compiler warnings about unused arguments */
	Std_ReturnType u_RetVal = RTE_E_OK;
		
#if((DSM_SYSTEM_TYPE == DSM_SYSTEM_MFC5J3_C673)|| \
					  (DSM_SYSTEM_TYPE == DSM_SYSTEM_MFC5J3_C385))
					  
	Std_ReturnType u_RetVal_Read = RTE_E_OK; 
	static uint8 a_Mirror_Block[OMSN_LEN] = {0};
	static boolean b_ReadFlagSuccess;
	static uint16 u_Requestcounter =0;
	static uint16 u_Readcounter =0;
		
	if((uint8)DCM_INITIAL == OpStatus)
	{
	    u_RetVal_Read = Rte_Call_RP_Sdc_SendInterface_SocInfo_RequestOMSN();
	
		if(u_RetVal_Read != RTE_E_OK)
		{
		    u_RetVal = DCM_E_PENDING;
		}
		else
		{
			(void)Rte_Call_RP_Sdc_SendInterface_SocInfo_SocOMSN_Read((uint8_t*)a_Mirror_Block, OMSN_LEN);
	
			if((a_Mirror_Block[0] == 0x00u) && (a_Mirror_Block[1] == 0x00u) &&
				   (a_Mirror_Block[2] == 0x00u) && (a_Mirror_Block[3] == 0x00u))			
			{
				b_ReadFlagSuccess = (boolean)FALSE;
				u_RetVal = DCM_E_PENDING;
			}
			else
			{
				b_ReadFlagSuccess = (boolean)TRUE;
			}
		}   
    }
	else if((uint8)DCM_PENDING == OpStatus)
	{
		u_RetVal_Read = Rte_Call_RP_Sdc_SendInterface_SocInfo_RequestOMSN();
		
		if(u_RetVal_Read != RTE_E_OK)
		{
		    u_Requestcounter++;
			if(u_Requestcounter < 500u)
			{
				u_RetVal = DCM_E_PENDING;
			}
			else
			{
				u_RetVal = RTE_E_INVALID;
				u_Requestcounter =0u;
			} 		
		}
		else
		{
			(void)Rte_Call_RP_Sdc_SendInterface_SocInfo_SocOMSN_Read((uint8_t*)a_Mirror_Block, OMSN_LEN);
		
			if((a_Mirror_Block[0] == 0x00u) && (a_Mirror_Block[1] == 0x00u) &&
				   (a_Mirror_Block[2] == 0x00u) && (a_Mirror_Block[3] == 0x00u))		
			{
				u_Readcounter++;
				if(u_Readcounter < 500u)
				{
					b_ReadFlagSuccess = (boolean)FALSE;
				    u_RetVal = DCM_E_PENDING;
				}
				else
				{
					u_RetVal = RTE_E_INVALID;
					u_Readcounter =0u;
				} 		
			}
			else
			{
				b_ReadFlagSuccess = (boolean)TRUE;
			}
		}   
	}
	else if((uint8)DCM_CANCEL == OpStatus)
	{
		b_ReadFlagSuccess = (boolean)FALSE;
		u_RetVal = RTE_E_INVALID;
	}
	else
	{
		/*Do nothing*/
	}
	
	if((boolean)TRUE == b_ReadFlagSuccess)
	{
		/* PRQA S 0314 2 */ /* Pointer to void, no problem */
		TS_MemCpy((void*)Data, (void*)a_Mirror_Block, OMSN_LEN); /* PRQA S 3469,2 # 2023-06-13 Z.J.L: 3469: This usage of a function-like macro looks like it could be replaced by an equivalent function call. 3469: defined by Bsw platform header,check it ok */
		u_RetVal = RTE_E_OK;
	}
#endif
	
	return u_RetVal;

} /* FUNC(Std_ReturnType, RTE_CODE) Dsm_u_RDBI_OMSN_Read (Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_APPL_DATA) Data) */
#endif

/**
 * \functions Dsm_u_RDBI_SocSoftwareNumberDataIdentifier_Read
 *
 * \brief Read Soc software number data identifier from ROM.(FD29)
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
#if (DSM_FEAT_RDBI_SocSoftwareNumberDataIdentifier == STD_ON)
FUNC(Std_ReturnType, RTE_CODE) Dsm_u_RDBI_SocSoftwareNumberDataIdentifier_Read (Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_APPL_DATA) Data)/* PRQA S 03432,2 # 2023-06-13 Z.J.L: 3432: Simple macro argument expression is not parenthesized. 03432: Gnenerate by Rte,check it ok */
{
	/* suppress compiler warnings about unused arguments */
	(void)OpStatus;
	Std_ReturnType u_RetVal = RTE_E_INVALID;
  
 #if((DSM_SYSTEM_TYPE == DSM_SYSTEM_MFC5J3_C673)|| \
	  (DSM_SYSTEM_TYPE == DSM_SYSTEM_MFC5J3_C385))
	if(NULL_PTR != Data)
	{
	    TS_MemCpy(&Data[0], s_ReleaseVariables.a_SocSoftwareNumberDataIdentifier, sizeof(s_ReleaseVariables.a_SocSoftwareNumberDataIdentifier)); /* PRQA S 3469,2 # 2023-06-13 Z.J.L: 3469: This usage of a function-like macro looks like it could be replaced by an equivalent function call. 3469: defined by Bsw platform header,check it ok */
		u_RetVal = RTE_E_OK;
	}
	else
	{/*Do nothing*/}
#endif

    return u_RetVal;

} /* FUNC(Std_ReturnType, RTE_CODE) Dsm_u_RDBI_SocSoftwareNumberDataIdentifier_Read (Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_APPL_DATA) Data) */
#endif

/**
 * \functions Dsm_u_RDBI_SocBootSensor_Read
 *
 * \brief Read boot sensor from Soc via SPI.(FD23)
 *
 ** \param[in] OpStatus, 
 *
 ** \param[out] Data, Pointer to Data buffer (4 bytes).
 **                  unsigned formatted
 *
 ** \return RTE_E_OK, 
 * \comments  
 *
 */
#if (DSM_FEAT_RDBI_SocBootSensor == STD_ON)
FUNC(Std_ReturnType, RTE_CODE) Dsm_u_RDBI_SocBootSensor_Read (Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_APPL_DATA) Data)/* PRQA S 03432,2 # 2023-06-13 Z.J.L: 3432: Simple macro argument expression is not parenthesized. 03432: Gnenerate by Rte,check it ok */
{
    /* suppress compiler warnings about unused arguments */
	Std_ReturnType u_RetVal = RTE_E_OK;
		  
#if((DSM_SYSTEM_TYPE == DSM_SYSTEM_MFC5J3_C673)|| \
						(DSM_SYSTEM_TYPE == DSM_SYSTEM_MFC5J3_C385))
						
	Std_ReturnType u_RetVal_Read = RTE_E_OK; 
	static uint8 a_Mirror_Block_OMSN[OMSN_LEN] = {0};
	static uint8 a_Mirror_Block_BOOTSENSOR[BOOTSENSOR_LEN] = {0};
	static boolean b_ReadFlagSuccess;
	static uint16 u_Request_OMSNcounter =0;
	static uint16 u_Request_BOOTSENSORcounter =0;
	static uint16 u_Readcounter =0;
		  
	if((uint8)DCM_INITIAL == OpStatus)
	{
		u_RetVal_Read = Rte_Call_RP_Sdc_SendInterface_SocInfo_RequestOMSN();
	  
		if(u_RetVal_Read != RTE_E_OK)
		{
		    u_RetVal = DCM_E_PENDING;
		}
		else
		{
		    u_RetVal_Read = Rte_Call_RP_Sdc_SendInterface_SocInfo_RequestBootSensor();
			if(u_RetVal_Read != RTE_E_OK)
		    {
			    u_RetVal = DCM_E_PENDING;
		    }
			else
			{
                (void)Rte_Call_RP_Sdc_SendInterface_SocInfo_SocOMSN_Read((uint8_t*)a_Mirror_Block_OMSN, OMSN_LEN);

				(void)Rte_Call_RP_Sdc_SendInterface_SocInfo_SocBootSensor_Read((uint8_t*)a_Mirror_Block_BOOTSENSOR, BOOTSENSOR_LEN);

				if((a_Mirror_Block_OMSN[0] == 0x00u) && (a_Mirror_Block_OMSN[1] == 0x00u) &&
				   (a_Mirror_Block_OMSN[2] == 0x00u) && (a_Mirror_Block_OMSN[3] == 0x00u) &&
				    (a_Mirror_Block_BOOTSENSOR[0] == 0x00u))
				{
				    b_ReadFlagSuccess = (boolean)FALSE;
				    u_RetVal = DCM_E_PENDING;
				}
				else
				{
				    b_ReadFlagSuccess = (boolean)TRUE;
				}
			}			  
		}   
	}
	else if((uint8)DCM_PENDING == OpStatus)
	{
	    u_RetVal_Read = Rte_Call_RP_Sdc_SendInterface_SocInfo_RequestOMSN();
		  
		if(u_RetVal_Read != RTE_E_OK)
		{
	        u_Request_OMSNcounter++;
			if(u_Request_OMSNcounter < 500u)
			{
				u_RetVal = DCM_E_PENDING;
			}
			else
			{
				u_RetVal = RTE_E_INVALID;
				u_Request_OMSNcounter =0u;
			} 	  
	   }
	   else
	   {
	       u_RetVal_Read = Rte_Call_RP_Sdc_SendInterface_SocInfo_RequestBootSensor();
		   if(u_RetVal_Read != RTE_E_OK)
		   {
               u_Request_BOOTSENSORcounter++;
			   if(u_Request_BOOTSENSORcounter < 500u)
			   {
			       u_RetVal = DCM_E_PENDING;
			   }
			   else
			   {
			       u_RetVal = RTE_E_INVALID;
				   u_Request_BOOTSENSORcounter =0u;
			   } 	  
		   }
		   else
		   {
                (void)Rte_Call_RP_Sdc_SendInterface_SocInfo_SocOMSN_Read((uint8_t*)a_Mirror_Block_OMSN, OMSN_LEN);

				(void)Rte_Call_RP_Sdc_SendInterface_SocInfo_SocBootSensor_Read((uint8_t*)a_Mirror_Block_BOOTSENSOR, BOOTSENSOR_LEN);

				if((a_Mirror_Block_OMSN[0] == 0x00u) && (a_Mirror_Block_OMSN[1] == 0x00u) &&
				   (a_Mirror_Block_OMSN[2] == 0x00u) && (a_Mirror_Block_OMSN[3] == 0x00u) &&
				    (a_Mirror_Block_BOOTSENSOR[0] == 0x00u))	  
			    {
				    u_Readcounter++;
				    if(u_Readcounter < 500u)
				    {
					    b_ReadFlagSuccess = (boolean)FALSE;
					    u_RetVal = DCM_E_PENDING;
				    }
				    else
				    {
					    b_ReadFlagSuccess = (boolean)TRUE;
					    u_Readcounter =0u;
				    } 	  
			    }
			    else
			    {
				    b_ReadFlagSuccess = (boolean)TRUE;
			    }
		   }
	  }   
   }
   else if((uint8)DCM_CANCEL == OpStatus)
   {
	   b_ReadFlagSuccess = (boolean)FALSE;
	   u_RetVal = RTE_E_INVALID;
   }
   else
   {
		/*Do nothing*/
   }
	  
   if((boolean)TRUE == b_ReadFlagSuccess)
   {
        if((a_Mirror_Block_OMSN[0] == 0x00u) && (a_Mirror_Block_OMSN[1] == 0x00u) &&
		   (a_Mirror_Block_OMSN[2] == 0x00u) && (a_Mirror_Block_OMSN[3] == 0x00u) &&
			(a_Mirror_Block_BOOTSENSOR[0] == 0x00u))
        {
            Data[0] = 0x00u;//abnormal
		}
		else
		{
            Data[0] = 0x01u; //normal
		}
		u_RetVal = RTE_E_OK;
   }
#endif
	  
	return u_RetVal;

} /* FUNC(Std_ReturnType, RTE_CODE) Dsm_u_RDBI_SocBootSensor_Read (Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_APPL_DATA) Data) */
#endif

/**
 * \functions Dsm_u_RDBI_OMCalibrationStatus_Read
 *
 * \brief Read OM calibration status from Soc via SPI.(FD20)
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
#if (DSM_FEAT_RDBI_OMCalibrationStatus == STD_ON)
FUNC(Std_ReturnType, RTE_CODE) Dsm_u_RDBI_OMCalibrationStatus_Read (Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_APPL_DATA) Data)/* PRQA S 03432,2 # 2023-06-13 Z.J.L: 3432: Simple macro argument expression is not parenthesized. 03432: Gnenerate by Rte,check it ok */
{
    /* suppress compiler warnings about unused arguments */
	Std_ReturnType u_RetVal = RTE_E_OK;
			
#if((DSM_SYSTEM_TYPE == DSM_SYSTEM_MFC5J3_C673)|| \
						  (DSM_SYSTEM_TYPE == DSM_SYSTEM_MFC5J3_C385))
						  
	Std_ReturnType u_RetVal_Read = RTE_E_OK; 
	static uint8 a_Mirror_Block_OMSN[OMSN_LEN] = {0};
	static uint8 a_Mirror_Block_BOOTSENSOR[BOOTSENSOR_LEN] = {0};
	static boolean b_ReadFlagSuccess;
	static uint16 u_Request_OMSNcounter =0;
	static uint16 u_Request_BOOTSENSORcounter =0;
	static uint16 u_Readcounter =0;
			
	if((uint8)DCM_INITIAL == OpStatus)
	{
		u_RetVal_Read = Rte_Call_RP_Sdc_SendInterface_SocInfo_RequestOMSN();
		
		if(u_RetVal_Read != RTE_E_OK)
		{
			u_RetVal = DCM_E_PENDING;
		}
		else
		{
			u_RetVal_Read = Rte_Call_RP_Sdc_SendInterface_SocInfo_RequestBootSensor();
			if(u_RetVal_Read != RTE_E_OK)
			{
				u_RetVal = DCM_E_PENDING;
			}
			else
			{
				(void)Rte_Call_RP_Sdc_SendInterface_SocInfo_SocOMSN_Read((uint8_t*)a_Mirror_Block_OMSN, OMSN_LEN);
  
				(void)Rte_Call_RP_Sdc_SendInterface_SocInfo_SocBootSensor_Read((uint8_t*)a_Mirror_Block_BOOTSENSOR, BOOTSENSOR_LEN);
  
				if((a_Mirror_Block_OMSN[0] == 0x00u) && (a_Mirror_Block_OMSN[1] == 0x00u) &&
				   (a_Mirror_Block_OMSN[2] == 0x00u) && (a_Mirror_Block_OMSN[3] == 0x00u) &&
					(a_Mirror_Block_BOOTSENSOR[0] == 0x00u))
				{
					b_ReadFlagSuccess = (boolean)FALSE;
					u_RetVal = DCM_E_PENDING;
				}
				else
				{
					b_ReadFlagSuccess = (Boolean)TRUE;
				}
			} 			
		}   
	}
	else if((uint8)DCM_PENDING == OpStatus)
	{
		u_RetVal_Read = Rte_Call_RP_Sdc_SendInterface_SocInfo_RequestOMSN();
			
		if(u_RetVal_Read != RTE_E_OK)
		{
			u_Request_OMSNcounter++;
			if(u_Request_OMSNcounter < 500u)
			{
				u_RetVal = DCM_E_PENDING;
			}
			else
			{
				u_RetVal = RTE_E_INVALID;
				u_Request_OMSNcounter =0u;
			} 	
	    }
		else
		{
			u_RetVal_Read = Rte_Call_RP_Sdc_SendInterface_SocInfo_RequestBootSensor();
			if(u_RetVal_Read != RTE_E_OK)
			{
			    u_Request_BOOTSENSORcounter++;
				if(u_Request_BOOTSENSORcounter < 500u)
				{
					u_RetVal = DCM_E_PENDING;
				}
				else
				{
					u_RetVal = RTE_E_INVALID;
					u_Request_BOOTSENSORcounter =0u;
				}		
			}
			else
			{
				 (void)Rte_Call_RP_Sdc_SendInterface_SocInfo_SocOMSN_Read((uint8_t*)a_Mirror_Block_OMSN, OMSN_LEN);
  
				 (void)Rte_Call_RP_Sdc_SendInterface_SocInfo_SocBootSensor_Read((uint8_t*)a_Mirror_Block_BOOTSENSOR, BOOTSENSOR_LEN);
				 
				 if(((a_Mirror_Block_OMSN[0] == 0x00u) && (a_Mirror_Block_OMSN[1] == 0x00u) &&
					(a_Mirror_Block_OMSN[2] == 0x00u) && (a_Mirror_Block_OMSN[3] == 0x00u)) ||
					 (a_Mirror_Block_BOOTSENSOR[0] == 0x00u)) 	
				 {
				 
					 u_Readcounter++;
					 if(u_Readcounter < 500u)
					 {
						 b_ReadFlagSuccess = (boolean)FALSE;
						 u_RetVal = DCM_E_PENDING;
					 }
					 else
					 {
						 b_ReadFlagSuccess = (boolean)TRUE;
						 u_Readcounter =0u;
					 } 	
				 } 
				 else
				 {
					 b_ReadFlagSuccess = (boolean)TRUE;
				 }
		    }
	    }	
	}
	else if((uint8)DCM_CANCEL == OpStatus)
	{
		b_ReadFlagSuccess = (boolean)FALSE;
		u_RetVal = RTE_E_INVALID;
	}
	else
	{
		 /*Do nothing*/
	}
		
	if((boolean)TRUE == b_ReadFlagSuccess)
	{
		if(a_Mirror_Block_BOOTSENSOR[0] == 0x1Au)//calibration succssful
		{
			Data[0] = 0x01u;
		}
		else
		{
			Data[0] = 0x00u;  
		}
	    u_RetVal = RTE_E_OK;
	}
#endif
		
	return u_RetVal;

} /* FUNC(Std_ReturnType, RTE_CODE) Dsm_u_RDBI_OMCalibrationStatus_Read (Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_APPL_DATA) Data) */
#endif

/**
 * \functions Dsm_u_RDBI_CalibrationStatus_Read
 *
 * \brief Read calibration status from Soc via SPI.(F1F7)
 *
 ** \param[in] OpStatus, 
 *
 ** \param[out] Data, Pointer to Data buffer (1 bytes).
 **                  unsigned formatted
 *
 ** \return RTE_E_OK, 
 * \comments     * 0x00 - Calibration is not done
                 * 0x02 -static calibration is done
                 * 0x04 - Intial_online_Calibration is not done
                 * 0x05 - Intial_online_Calibration is  done
                 * 0x06 - Static calibration is not done
                 * 0x0E - calibration is not finished
 *
 */
#if (DSM_FEAT_RDBI_CalibrationStatus == STD_ON)
FUNC(Std_ReturnType, RTE_CODE) Dsm_u_RDBI_CalibrationStatus_Read (Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_APPL_DATA) Data)/* PRQA S 03432,2 # 2023-06-13 Z.J.L: 3432: Simple macro argument expression is not parenthesized. 03432: Gnenerate by Rte,check it ok */
{
    /* suppress compiler warnings about unused arguments */
    (void)OpStatus;
    Std_ReturnType u_RetVal = RTE_E_OK;
  
#if((DSM_SYSTEM_TYPE == DSM_SYSTEM_MFC5J3_C673)|| \
						  (DSM_SYSTEM_TYPE == DSM_SYSTEM_MFC5J3_C385))
	static uint8 a_Mirror_Block_CalibrationFlag[1] = {0};
    static uint8 a_Mirror_Block_SocSysState[1] = {0};
  
    (void)Rte_Call_RP_Sdc_SendInterface_Calibration_CalibrationFlag_Read((uint8_t*)a_Mirror_Block_CalibrationFlag,1);

    (void)Rte_Call_RP_Sdc_SendInterface_Diag_SocSysState_Read((uint8_t*)a_Mirror_Block_SocSysState,1);
 
    if((a_Mirror_Block_SocSysState[0] == (uint8_t)STATE_SYSMGR_CAMERA_ONL_CALIB)
    || (a_Mirror_Block_SocSysState[0] == (uint8_t)STATE_SYSMGR_CAMERA_EOL_CALIB)
    || (a_Mirror_Block_SocSysState[0] == (uint8_t)STATE_SYSMGR_CAMERA_EOL_CALIB_FINISH)
    || (a_Mirror_Block_SocSysState[0] == (uint8_t)STATE_SYSMGR_CAMERA_ONL_CALIB_FINISH))
    {
	    Data[0] = a_Mirror_Block_CalibrationFlag[0];
    }
    else
    {
	    Data[0] = 0xFF;
    }
#endif

    return u_RetVal;
} /* FUNC(Std_ReturnType, RTE_CODE) Dsm_u_RDBI_CalibrationStatus_Read (Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_APPL_DATA) Data) */
#endif

/**
 * \functions Dsm_u_RDBI_CalibrationStatus_Read
 *
 * \brief Read calibration status from Soc via SPI.(F1F7)
 *
 ** \param[in] OpStatus, 
 *
 ** \param[out] Data, Pointer to Data buffer (1 bytes).
 **                  unsigned formatted
 *
 ** \return RTE_E_OK, 
 * \comments     *	0x00-NO_CALIBRATION_RELEVANT_ERROR
				 *	0x01-CALIBRATION_NOT_STARTED
				 *	0x02-ILLUMINATION_TOO_BRIGHT
				 *	0x03-ILLUMINATION_TOO_INHOMOGENEOUS
				 *	0x04-ILLUMINATION_TOO_DARK
				 *	0x05-CONTRAST_TOO_LOW
				 *	0x06-CAMERA_HEIGHT_INVALID
				 *	0x07-VISUAL_CONTACT_DISTURBED
				 *	0x08-CALIBRATION_PANEL_POSITION_WRONG
				 *	0x09-SYSTEM_NOT_IN_REST_STATE
				 *	0x0A-MARKER_DETECTION_INCOMPLETE
				 *	0x0B-MOUNTING_POSITION_WRONG
				 *	0x0C-CALIBRATION_TARGET_MISMATCH
				 *	0x0D-LEFT_TARGET_NOT_DETECTED
				 *	0x0E-CENTER_TARGET_NOT_DETECTED
				 *	0x0F-RIGHT_TARGET_NOT_DETECTED
				 *	0xFF-CALIBRATION_NOT_FINISHED
				 * 
 *
 */
#if (DSM_FEAT_RDBI_CurrentStaticCalibrationDetails == STD_ON)
FUNC(Std_ReturnType, RTE_CODE) Dsm_u_RDBI_CurrentStaticCalibrationDetails_Read (Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_APPL_DATA) Data)/* PRQA S 03432,2 # 2023-06-13 Z.J.L: 3432: Simple macro argument expression is not parenthesized. 03432: Gnenerate by Rte,check it ok */
{
    /* suppress compiler warnings about unused arguments */
	(void)OpStatus;
	Std_ReturnType u_RetVal = RTE_E_OK;
	
#if((DSM_SYSTEM_TYPE == DSM_SYSTEM_MFC5J3_C673)|| \
							(DSM_SYSTEM_TYPE == DSM_SYSTEM_MFC5J3_C385))
	static uint8 a_CameraCaliresultDetails[1] = {0};
	static uint8 a_SocSysState[1] = {0};
	
	(void)Rte_Call_RP_Sdc_SendInterface_Calibration_CameraCaliresultDetails_Read((uint8_t*)a_CameraCaliresultDetails,1);
  
	(void)Rte_Call_RP_Sdc_SendInterface_Diag_SocSysState_Read((uint8_t*)a_SocSysState,1);
   
	if((a_SocSysState[0] == (uint8_t)STATE_SYSMGR_CAMERA_ONL_CALIB)
	  || (a_SocSysState[0] == (uint8_t)STATE_SYSMGR_CAMERA_EOL_CALIB)
	  || (a_SocSysState[0] == (uint8_t)STATE_SYSMGR_CAMERA_EOL_CALIB_FINISH)
	  || (a_SocSysState[0] == (uint8_t)STATE_SYSMGR_CAMERA_ONL_CALIB_FINISH))
	 {
		 Data[0] = a_CameraCaliresultDetails[0];
	 }
	 else
	 {
		 Data[0] = 0xFF;
	 }
#endif
  
	 return u_RetVal;

} /* FUNC(Std_ReturnType, RTE_CODE) Dsm_u_RDBI_CurrentStaticCalibrationDetails_Read (Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_APPL_DATA) Data) */
#endif

/**
 * \functions Dsm_u_RDBI_CalibrationBoardDistance_Read
 *
 * \brief Read calibration board distance from DFlash.(3BAF)
 *
 ** \param[in] OpStatus, 
 *
 ** \param[out] Data, Pointer to Data buffer (2 bytes).
 **                  unsigned formatted
 *
 ** \return RTE_E_OK, 
 * \comments                  
 *
 */
#if (DSM_FEAT_RDBI_CalibrationBoardDistance == STD_ON)
FUNC(Std_ReturnType, RTE_CODE) Dsm_u_RDBI_CalibrationBoardDistance_Read (Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_APPL_DATA) Data)/* PRQA S 03432,2 # 2023-06-13 Z.J.L: 3432: Simple macro argument expression is not parenthesized. 03432: Gnenerate by Rte,check it ok */
{
    /* suppress compiler warnings about unused arguments */
	Std_ReturnType u_RetVal = RTE_E_INVALID;
	(void)OpStatus;
							
 #if((DSM_SYSTEM_TYPE == DSM_SYSTEM_MFC5J3_C673)|| \
								(DSM_SYSTEM_TYPE == DSM_SYSTEM_MFC5J3_C385))					
	if(NULL_PTR != Data)
	{
		TS_MemCpy(&Data[0], &RAM_NVM_BLOCK_EOL_Info_Input[4], CALBOARDDIS_LEN); /* PRQA S 3469,2 # 2023-06-13 Z.J.L: 3469: This usage of a function-like macro looks like it could be replaced by an equivalent function call. 3469: defined by Bsw platform header,check it ok */
		u_RetVal = RTE_E_OK;
	}
	else
	{/*Do nothing*/}
#endif
							
	  return u_RetVal;

} /* FUNC(Std_ReturnType, RTE_CODE) Dsm_u_RDBI_CalibrationBoardDistance_Read (Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_APPL_DATA) Data) */
#endif

/**
 * \functions Dsm_u_RDBI_BodyHeightWheelHouseEdge_Read
 *
 * \brief Read Body height wheel house edge from DFlash.(F1F5)
 *
 ** \param[in] OpStatus, 
 *
 ** \param[out] Data, Pointer to Data buffer (8 bytes).
 **                  unsigned formatted
 *
 ** \return RTE_E_OK, 
 * \comments                  
 *
 */
#if (DSM_FEAT_RDBI_BodyHeightWheelHouseEdge == STD_ON)
FUNC(Std_ReturnType, RTE_CODE) Dsm_u_RDBI_BodyHeightWheelHouseEdge_Read (Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_APPL_DATA) Data)/* PRQA S 03432,2 # 2023-06-13 Z.J.L: 3432: Simple macro argument expression is not parenthesized. 03432: Gnenerate by Rte,check it ok */
{
    /* suppress compiler warnings about unused arguments */
	Std_ReturnType u_RetVal = RTE_E_INVALID;
	(void)OpStatus;
							  
 #if((DSM_SYSTEM_TYPE == DSM_SYSTEM_MFC5J3_C673)|| \
								  (DSM_SYSTEM_TYPE == DSM_SYSTEM_MFC5J3_C385))					  
    if(NULL_PTR != Data)
	{
	    Data[0] = RAM_NVM_BLOCK_EOL_Info_Input[0];
	    Data[1] = RAM_NVM_BLOCK_EOL_Info_Input[1];
	    Data[2] = RAM_NVM_BLOCK_EOL_Info_Input[0];
	    Data[3] = RAM_NVM_BLOCK_EOL_Info_Input[1];
	    Data[4] = RAM_NVM_BLOCK_EOL_Info_Input[2];
	    Data[5] = RAM_NVM_BLOCK_EOL_Info_Input[3];
	    Data[6] = RAM_NVM_BLOCK_EOL_Info_Input[2];
	    Data[7] = RAM_NVM_BLOCK_EOL_Info_Input[3];
		u_RetVal = RTE_E_OK;
	}
	else
	{/*Do nothing*/}
#endif
							  
    return u_RetVal;

} /* FUNC(Std_ReturnType, RTE_CODE) Dsm_u_RDBI_BodyHeightWheelHouseEdge_Read (Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_APPL_DATA) Data) */
#endif


/**
 * \functions Dsm_u_RDBI_ECUOperationMode_Read
 *
 * \brief Read Ecu operation mode from specific DF static Address.(F1FD)
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
#if (DSM_FEAT_RDBI_ECUOperationMode == STD_ON)
FUNC(Std_ReturnType, RTE_CODE) Dsm_u_RDBI_ECUOperationMode_Read (Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_APPL_DATA) Data)/* PRQA S 03432,2 # 2023-06-13 Z.J.L: 3432: Simple macro argument expression is not parenthesized. 03432: Gnenerate by Rte,check it ok */
{
	  /* suppress compiler warnings about unused arguments */
	  Std_ReturnType u_RetVal = RTE_E_OK;
	  
#if((DSM_SYSTEM_TYPE == DSM_SYSTEM_MFC5J3_C673)|| \
				(DSM_SYSTEM_TYPE == DSM_SYSTEM_MFC5J3_C385))	
				
      Std_ReturnType ui8_RetVal_Read = E_NOT_OK; 
	  static uint8 ui8_QsmReqStatus = QSM_REQRESULT_NOT_OK; 
	  static boolean b_ReadFlagSuccess;
	  
	  if((uint8)DCM_INITIAL == OpStatus)
	  {
		  b_ReadFlagSuccess = (boolean)FALSE;

		  ui8_RetVal_Read = Rte_Call_RP_Qsm_Block_EOLModeGateOP_Qsm_ReadBlock((void*)&s_QSBlock_EcuSpecInfo, 0, sizeof(s_QSBlock_EcuSpecInfo));

		  if ((uint8)E_OK == ui8_RetVal_Read)
		  {
              ui8_QsmReqStatus = Rte_Call_RP_Qsm_Block_EOLModeGateOP_Qsm_GetErrorStatues();
		  
		      if(QSM_REQRESULT_PENDING == ui8_QsmReqStatus)
	          {
		          u_RetVal = DCM_E_PENDING;
		      }
		      else if(QSM_REQRESULT_OK == ui8_QsmReqStatus)
		      {
		          b_ReadFlagSuccess = (boolean)TRUE;
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
	  else if((uint8)DCM_PENDING == OpStatus)
	  {
		  ui8_QsmReqStatus = Rte_Call_RP_Qsm_Block_EOLModeGateOP_Qsm_GetErrorStatues();
		  
		  if(QSM_REQRESULT_PENDING == ui8_QsmReqStatus)
	      {
		      u_RetVal = DCM_E_PENDING;
		  }
		  else if(QSM_REQRESULT_OK == ui8_QsmReqStatus)
		  {
		      b_ReadFlagSuccess = (boolean)TRUE;
		  }
		  else
		  {
		      u_RetVal = RTE_E_INVALID;	
		  }  
	  }
	  else if((uint8)DCM_CANCEL == OpStatus)
	  {
		  b_ReadFlagSuccess = (boolean)FALSE;
		  u_RetVal = RTE_E_INVALID;
	  }
	  else
	  {
		  /*Do nothing*/
	  }

	  if((boolean)TRUE == b_ReadFlagSuccess)
	  {
		  /* PRQA S 0314 2 */ /* Pointer to void, no problem */
		  TS_MemCpy((void*)Data, (void*)&s_QSBlock_EcuSpecInfo.OperationMode, ECUOPERATIONMODE_LEN); /* PRQA S 3469,2 # 2023-06-13 Z.J.L: 3469: This usage of a function-like macro looks like it could be replaced by an equivalent function call. 3469: defined by Bsw platform header,check it ok */
		  u_RetVal = RTE_E_OK;
	  }
#endif
  
	return u_RetVal;

} /* FUNC(Std_ReturnType, RTE_CODE) Dsm_u_RDBI_EOL_ModeGate_Read (Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_APPL_DATA) Data) */
#endif

/**
 * \functions Dsm_u_RDBI_SocResetControl_Read
 *
 * \brief Read soc reset control state from RAM.(FD00)
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
#if (DSM_FEAT_RDBI_SocResetControl == STD_ON)
FUNC(Std_ReturnType, RTE_CODE) Dsm_u_RDBI_SocResetControl_Read (Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_APPL_DATA) Data)
{
  (void)OpStatus;
  
#if((DSM_SYSTEM_TYPE == DSM_SYSTEM_MFC5J3_C673)|| \
				  (DSM_SYSTEM_TYPE == DSM_SYSTEM_MFC5J3_C385))  
  Data[0] = Rte_IrvRead_Dsm_u_RDBI_SocResetControl_Read_Dsm_IRV_SocResetControlState();
#endif

  return RTE_E_OK;
} /* FUNC(Std_ReturnType, RTE_CODE) Dsm_u_RDBI_SocResetControl_Read (Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_APPL_DATA) Data) */
#endif

/**
 * \functions Dsm_u_RDBI_Fusa_Debug_Status_Read
 *
 * \brief Clear NVM Log Data(FD2A)
 *
 ** \param[in] OpStatus, 
 *
 ** \param[out] Data, Pointer to Data buffer (1 bytes).
 **                  
 *
 ** \return RTE_E_OK, 
 * \comments  
 *
 */

#if (DSM_FEAT_RDBI_Fusa_Debug_Status == STD_ON)
FUNC(Std_ReturnType, RTE_CODE) Dsm_u_RDBI_Fusa_Debug_Status_Read (Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_APPL_DATA) Data)
{
	/* suppress compiler warnings about unused arguments */
	Std_ReturnType u_RetVal = RTE_E_OK;

 #if((DSM_SYSTEM_TYPE == DSM_SYSTEM_MFC5J3_C673)|| \
	  (DSM_SYSTEM_TYPE == DSM_SYSTEM_MFC5J3_C385))

    Std_ReturnType ui8_RetVal_Read = E_NOT_OK; 
 	Std_ReturnType ui8_RetVal_ErrStat = E_NOT_OK;
	NvM_RequestResultType ui8_ReadStatus;
    static boolean b_ReadFlagSuccess;

    if((uint8)DCM_INITIAL == OpStatus)
	{
		b_ReadFlagSuccess = (boolean)FALSE;

		/* PRQA S 0314 2 */ /* P2Obj to P2void conversion is safe */
		ui8_RetVal_Read = Rte_Call_RP_Nvm_FS_Debug_Status_ReadBlock((void*)&RAM_BLOCK_FS_DEBUG);

		if ( (uint8)E_OK == ui8_RetVal_Read )
		{
		    ui8_RetVal_ErrStat = Rte_Call_RP_Nvm_FS_Debug_Status_GetErrorStatus(&ui8_ReadStatus);

			if ((uint8)E_OK == ui8_RetVal_ErrStat )
			{
				if ( ((uint8)NVM_REQ_OK == ui8_ReadStatus) ||
					((uint8)NVM_REQ_RESTORED_FROM_ROM == ui8_ReadStatus) ||
					((uint8)NVM_REQ_REDUNDANCY_FAILED == ui8_ReadStatus) )
				{
					b_ReadFlagSuccess = (boolean)TRUE;
				}
				else if ((uint8)NVM_REQ_PENDING == ui8_ReadStatus )
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
	else if((uint8)DCM_PENDING == OpStatus)
	{  
	    ui8_RetVal_ErrStat = Rte_Call_RP_Nvm_FS_Debug_Status_GetErrorStatus(&ui8_ReadStatus);

		if ((uint8)E_OK == ui8_RetVal_ErrStat )
		{
		    if ( ((uint8)NVM_REQ_OK == ui8_ReadStatus) ||
				 ((uint8)NVM_REQ_RESTORED_FROM_ROM == ui8_ReadStatus) ||
				 ((uint8)NVM_REQ_REDUNDANCY_FAILED == ui8_ReadStatus) )
			{
				b_ReadFlagSuccess = (boolean)TRUE;
			}
			else if ((uint8)NVM_REQ_PENDING == ui8_ReadStatus )
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
	else if((uint8)DCM_CANCEL == OpStatus)
	{		
		(void)Rte_Call_RP_Nvm_FS_Debug_Status_GetErrorStatus(&ui8_ReadStatus);

		if ( (uint8)NVM_REQ_PENDING == ui8_ReadStatus )
		{
		    ui8_RetVal_ErrStat = NvM_CancelJobs(NvMConf_NvMBlockDescriptor_NvM_BLOCK_FS_Debug_Status);

			if ( (uint8)E_OK == ui8_RetVal_ErrStat )
			{
				u_RetVal = RTE_E_OK;
			}
			else
			{
				u_RetVal = RTE_E_INVALID;
			}
		}
		b_ReadFlagSuccess = (boolean)FALSE;
	}
	else
	{
		/*Do nothing.*/
	}

	if ((boolean)TRUE == b_ReadFlagSuccess )
	{
		/* PRQA S 0314 2 */ /* Pointer to void, no problem */
		(void)TS_MemCpy((void*)Data, (void*)&RAM_BLOCK_FS_DEBUG, FSDEBUG_LEN); /* PRQA S 3469,2 # 2023-06-13 Z.J.L: 3469: This usage of a function-like macro looks like it could be replaced by an equivalent function call. 3469: defined by Bsw platform header,check it ok */
		u_RetVal = RTE_E_OK;
	}

#endif

	  return u_RetVal;
} /* FUNC(Std_ReturnType, RTE_CODE) Dsm_u_RDBI_Fusa_Debug_Status_Read (Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_APPL_DATA) Data) */
#endif

#if(DSM_FEAT_MEMMAP_EB_IS_USED == STD_ON)
    #define Dsm_STOP_SEC_CODE
    #include <Dsm_MemMap.h> /* PRQA S 5087 */
#endif



/*==================[internal function definitions]=========================*/








