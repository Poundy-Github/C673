/**
 * \file   Dsm_Main.c
 *
 * \brief  include ECUReset($11) and Diagnostic Seesion(10 02)
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
#include "Esm.h"
#include <Dcm_Dsl_SecurityLevelHandler.h>
#include <Cdm.h>
#include <Nvm_Cfg.h>
//#include "Esh_Main.h"



/*==================[external constants definition]=========================*/




/*==================[internal constants definition]=========================*/
/// All reset flags FALSE.
#define DSM_RESET_NONE        ((uint8)0x00u)
/// HardResetFlag (bit0).
#define DSM_RESET_HARD        ((uint8)0x01u)
/// ProgrammingResetFlag (bit1).
#define DSM_RESET_PROGRAMMING ((uint8)0x02u)
/// KeyOnOffFlag (bit2).
#define DSM_RESET_KEYONOFF    ((uint8)0x04u)
/// SoftResetFlag (bit3).
#define DSM_RESET_SOFT        ((uint8)0x08u)

/*==================[external data definition]==============================*/
//uint32 FBLUpdateFlag __at ( 0x70037F00 ); /*PRQA S 3408*/

#pragma section farbss Grp_RAM_DSPR0_Dsm_ProgramFlag
uint32 Dsm_FBLUpdateFlag;
#pragma section farbss restore


/*==================[internal data definition]==============================*/
#if(DSM_FEAT_MEMMAP_EB_IS_USED == STD_ON)
    #define Dsm_START_SEC_VAR_UNSPECIFIED
    #include <Dsm_MemMap.h>
#endif

static uint8 u_ResetTrigger = DSM_RESET_NONE;

#if(DSM_FEAT_MEMMAP_EB_IS_USED == STD_ON)
    #define Dsm_STOP_SEC_VAR_UNSPECIFIED
    #include <Dsm_MemMap.h>
#endif

#if(DSM_FEAT_MEMMAP_EB_IS_USED == STD_ON)
    #define Dsm_START_SEC_VAR_UNSPECIFIED
    #include <Dsm_MemMap.h>
#endif

static uint16 Dsm_SecurityAccess_DelayTimers = DSM_SA_DELAYTIMER;

#if(DSM_FEAT_MEMMAP_EB_IS_USED == STD_ON)
    #define Dsm_STOP_SEC_VAR_UNSPECIFIED
    #include <Dsm_MemMap.h>
#endif


/*==================[internal function declarations]========================*/
static FUNC(void, RTE_CODE)Dsm_v_SecurityAccess_DelayTimers_Decrement(void);

/*==================[external function definitions]=========================*/
#if(DSM_FEAT_MEMMAP_EB_IS_USED == STD_ON)
    #define Dsm_START_SEC_CODE
    #include <Dsm_MemMap.h>
#endif

/**
 * \functions Dsm_v_EcuReset
 *
 * \brief 
 *
 ** \param[in] none,
 *
 ** \param[out] none,
 *
 ** \return , 
 * \comments
 *
 */
FUNC(void, APPL_DSM_CODE) Dsm_v_EcuReset(void)
{
    /* PRQA S 3415,3416 2 */ /* No side effects, function only returns */
    if((DSM_RESET_HARD == (u_ResetTrigger & DSM_RESET_HARD)) ||
       (DSM_RESET_KEYONOFF == (u_ResetTrigger & DSM_RESET_KEYONOFF)))
    {
        Esm_v_Ecu_HardReset();   
    }
    else if(DSM_RESET_SOFT == (u_ResetTrigger & DSM_RESET_SOFT))
    {
        Esm_v_Ecu_SoftReset();
    }
    #if (DSM_FEAT_SU_PROGRAMMING_SESSION == STD_ON)
    else if(DSM_RESET_PROGRAMMING == ((u_ResetTrigger) & DSM_RESET_PROGRAMMING))
    {
        Esm_v_Ecu_SoftReset();
    }
    #endif
    else
    {
      /* Do nothing */
    }
}

/**
 * \functions Dsm_v_HardReset_CallBack
 *
 * \brief 
 *
 ** \param[in] none,
 *
 ** \param[out] none,
 *
 ** \return , 
 * \comments
 *
 */
FUNC(void, APPL_DSM_CODE) Dsm_v_HardReset_CallBack(void)
{
  u_ResetTrigger |= DSM_RESET_HARD;
}

/**
 * \functions Dsm_v_KeyOnoff_CallBack
 *
 * \brief 
 *
 ** \param[in] none,
 *
 ** \param[out] none,
 *
 ** \return , 
 * \comments
 *
 */
FUNC(void, APPL_DSM_CODE) Dsm_v_KeyOnoff_CallBack(void)
{
  u_ResetTrigger |= DSM_RESET_KEYONOFF;
}

/**
 * \functions Dsm_v_ProgrammingReset_CallBack
 *
 * \brief 
 *
 ** \param[in] none,
 *
 ** \param[out] none,
 *
 ** \return , 
 * \comments
 *
 */
FUNC(void, APPL_DSM_CODE) Dsm_v_ProgrammingReset_CallBack(void)
{
  u_ResetTrigger |= DSM_RESET_PROGRAMMING;
}

/**
 * \functions Dsm_v_SoftReset_CallBack
 *
 * \brief 
 *
 ** \param[in] none,
 *
 ** \param[out] none,
 *
 ** \return , 
 * \comments
 *
 */
FUNC(void, APPL_DSM_CODE) Dsm_v_SoftReset_CallBack(void)
{
  u_ResetTrigger |= DSM_RESET_SOFT;
}

#if(DSM_FEAT_MEMMAP_EB_IS_USED == STD_ON)
    #define Dsm_STOP_SEC_CODE
    #include <Dsm_MemMap.h>
#endif

/**
 * \functions Dsm_v_Init
 *
 * \brief 
 *
 ** \param[in] none,
 *
 ** \param[out] none,
 *
 ** \return , 
 * \comments
 *
 */
FUNC(void, RTE_CODE) Dsm_v_Init (void)
{
    u_ResetTrigger = DSM_RESET_NONE;

} /* FUNC(void, RTE_CODE) Dsm_v_Init (void) */

/**
 * \functions Dsm_v_MainFunction
 *
 * \brief 
 *
 ** \param[in] none,
 *
 ** \param[out] none,
 *
 ** \return , 
 * \comments
 *
 */
FUNC(void, RTE_CODE) Dsm_v_MainFunction (void) //10ms
{
    if(0x03u == RAM_NVM_BLOCK_Security_AttemptCount[0])/*PRQA S 3120*/
    {
	    Dsm_v_SecurityAccess_DelayTimers_Decrement();
    }
	else
	{
        Dsm_SecurityAccess_DelayTimers = DSM_SA_DELAYTIMER;
	}
	
} /* FUNC(void, RTE_CODE) Dsm_v_MainFunction (void) */

/**
 * \functions Dcm_SetProgConditions
 *
 * \brief 
 *
 ** \param[in] none,
 *
 ** \param[out] none,	
 *
 ** \return , 
 * \comments
 *
 */
FUNC(Std_ReturnType, DCM_CODE) Dcm_SetProgConditions(P2VAR(Dcm_ProgConditionsType, AUTOMATIC, DCM_VAR) ProgConditions)/*PRQA S 3227,3432,3673*/
{
    TS_PARAM_UNUSED(ProgConditions); /*PRQA S 3119,3469*/
	
    Std_ReturnType u_RetVal = RTE_E_OK;
    boolean b_CheckState = (Boolean)FALSE; /*PRQA S 2211*/
	
	b_CheckState = Rte_IrvRead_Dsm_v_MainFunction_Dsm_IRV_PreCondition_CheckState(); /*PRQA S 3469*/
	
	if(b_CheckState == (Boolean)TRUE)
	{
		Dsm_FBLUpdateFlag = 0x5AA5A55A;	/*PRQA S 3120*/
	}
	else
	{
		u_RetVal = RTE_E_INVALID;
	}
	
    return u_RetVal;
}

/**
 * \functions Dcm_GetProgConditions
 *
 * \brief 
 *
 ** \param[in] none,
 *
 ** \param[out] none,
 *
 ** \return , 
 * \comments
 *
 */
FUNC(Dcm_EcuStartModeType, DCM_CODE) Dcm_GetProgConditions(
  P2VAR(Dcm_ProgConditionsType, AUTOMATIC, DCM_VAR) ProgConditions) /*PRQA S 3227,3432,3673*/
 {
     TS_PARAM_UNUSED(ProgConditions); /*PRQA S 3119,3469*/
     return DCM_COLD_START;
 }

/**
 * \functions Dsm_u_ServiceRequestSupplierNotification_Confirmation
 *
 * \brief 
 *
 ** \param[in] none,
 *
 ** \param[out] none,
 *
 ** \return , 
 * \comments
 *
 */
FUNC(Std_ReturnType, RTE_CODE) Dsm_u_ServiceRequestSupplierNotification_Confirmation (uint8 SID, uint8 ReqType, uint16 SourceAddress, Dcm_ConfirmationStatusType ConfirmationStatus) /*PRQA S 3227*/
{
  /* suppress compiler warnings about unused arguments */
  (void)SID;/*PRQA S 3119*/
  (void)ReqType;/*PRQA S 3119*/
  (void)SourceAddress;/*PRQA S 3119*/
  (void)ConfirmationStatus;/*PRQA S 3119*/
  return RTE_E_OK;
} /* FUNC(Std_ReturnType, RTE_CODE) Dsm_u_ServiceRequestSupplierNotification_Confirmation (uint8 SID, uint8 ReqType, uint16 SourceAddress, Dcm_ConfirmationStatusType ConfirmationStatus) */

/**
 * \functions Dsm_u_ServiceRequestSupplierNotification_Indication
 *
 * \brief 
 *
 ** \param[in] none,
 *
 ** \param[out] none,
 *
 ** \return , 
 * \comments
 *
 */
FUNC(Std_ReturnType, RTE_CODE) Dsm_u_ServiceRequestSupplierNotification_Indication (uint8 SID, P2CONST(uint8, AUTOMATIC, RTE_APPL_DATA) RequestData, uint16 DataSize, uint8 ReqType, uint16 SourceAddress, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_APPL_DATA) ErrorCode)/*PRQA S 3227,3432*/
{
    /* suppress compiler warnings about unused arguments */
    TS_PARAM_UNUSED(DataSize);/*PRQA S 3119,3469*/
	TS_PARAM_UNUSED(ReqType);/*PRQA S 3119,3469*/
	TS_PARAM_UNUSED(SourceAddress);/*PRQA S 3119,3469*/
	TS_PARAM_UNUSED(RequestData);/*PRQA S 3119,3469*/
	
    Std_ReturnType u_RetVal = RTE_E_OK;
	float32_t f32_BattVolt;/*PRQA S 2211*/
    //uint8_t ui8_subFunction = RequestData[0];
	
	(void)Rte_Call_RP_EvAdc_GetValue_VMON_BATT_GetPhyValue(&f32_BattVolt);
	
    switch (SID) /*PRQA S 3352*/
	{   
	    #if 0
	    case 0x10:
			
		if(((u_subFunction&0x80)!=0x00)&&(ReqType == DCM_FUNCTIONAL_ADDRESSING))
        {
            u_RetVal = DCM_E_REQUEST_NOT_ACCEPTED;
		}
		else if(((u_subFunction&0x80)!=0x00)&&(ReqType == DCM_PHYSICAL_ADDRESSING))
        {
            *ErrorCode = DCM_E_SUBFUNCTIONNOTSUPPORTED;
			u_RetVal = RTE_E_INVALID;
		}
		else
		{
            u_RetVal = RTE_E_OK;
		}	
		break;
		
	    case 0x19: //Set suppressPosRspMsgIndicationBit= TRUE (1) (No response) not supported

        if(((u_subFunction&0x80)!=0x00)&&(ReqType == DCM_FUNCTIONAL_ADDRESSING))
        {
            u_RetVal = DCM_E_REQUEST_NOT_ACCEPTED;
		}
		else if(((u_subFunction&0x80)!=0x00)&&(ReqType == DCM_PHYSICAL_ADDRESSING))
        {
            *ErrorCode = DCM_E_SUBFUNCTIONNOTSUPPORTED;
			u_RetVal = RTE_E_INVALID;
		}
		else
		{
            u_RetVal = RTE_E_OK;
		}
		break;
		#endif
		
		case 0x28:/*PRQA S 3120*/
        
		if(f32_BattVolt < DSM_RC_VOLT_MIN_THSLD)
		{
		    *ErrorCode = DCM_E_VOLTAGETOOLOW; //NRC93
		    u_RetVal = RTE_E_INVALID;
		}
		else if(f32_BattVolt > DSM_RC_VOLT_MAX_THSLD)
		{
		  	*ErrorCode = DCM_E_VOLTAGETOOHIGH; //NRC92
		    u_RetVal = RTE_E_INVALID;
		}
		else
		{
		    *ErrorCode = E_OK;
		    u_RetVal = RTE_E_OK;
		}	
		break;
					
		default:break;/*PRQA S 2016*/
	
	}


	return u_RetVal;
} /* FUNC(Std_ReturnType, RTE_CODE) Dsm_u_ServiceRequestSupplierNotification_Indication (uint8 SID, P2CONST(uint8, AUTOMATIC, RTE_APPL_DATA) RequestData, uint16 DataSize, uint8 ReqType, uint16 SourceAddress, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_APPL_DATA) ErrorCode) */


/*==================[internal function definitions]=========================*/
/**
 * \functions Dsm_v_SecurityAccess_DelayTimers_Decrement
 *
 * \brief 
 *
 ** \param[in] none,
 *
 ** \param[out] none,
 *
 ** \return , 
 * \comments
 *
 */
static FUNC(void, RTE_CODE)Dsm_v_SecurityAccess_DelayTimers_Decrement(void)
{
    if(Dsm_SecurityAccess_DelayTimers > 0u)
    {
        Dsm_SecurityAccess_DelayTimers--;
	}
	else
	{
        RAM_NVM_BLOCK_Security_AttemptCount[0] = 0x02u;/*PRQA S 3120*/
		
		(void)Rte_Call_RP_Nvm_Security_AttemptCount_WriteBlock((void*)&RAM_NVM_BLOCK_Security_AttemptCount);/*PRQA S 0314*/
	}
}


