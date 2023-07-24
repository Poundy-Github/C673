/**
 * \file   Comcoordinator.c
 *
 * \brief  According the NM state and volatge to control communication action .
 *
 * \version refer the Rte_comcoordinator.h.
 * 
 * \copyright  2021 - 2023 Conti Smart Core
 *
 */
/*==================[inclusions]============================================*/
#include <Nm_Cbk.h>
#include <CanNm_Api.h>
#include <CanIf_Api.h>
#include <Rte_Comco.h>
#include "comcoordinator.h"

/*==================[external constants definition]=========================*/


/*==================[internal constants definition]=========================*/


/*==================[external data definition]==============================*/


/*==================[internal data definition]==============================*/
#define Comco_START_SEC_VAR_CLEARED_LOCAL
#include <Comco_MemMap.h>

static s_Comco_StatusInfo_t  s_Comco_StatusInfoData;

#define Comco_STOP_SEC_VAR_CLEARED_LOCAL
#include <Comco_MemMap.h>

/*==================[internal function declarations]========================*/
#define Comco_START_SEC_CODE_LOCAL
#include <Comco_MemMap.h>
static FUNC(void, RTE_CODE) Comco_v_CheckforWakeUpStatus(void);
static FUNC(void, RTE_CODE) Comco_v_CheckforKeepAwakeStatus(void);
static FUNC(void, RTE_CODE) Comco_v_CheckforRXspecificNMPDU(void);
static FUNC(void, RTE_CODE) Comco_v_Update_NMState_PDU(void);
static FUNC(void, RTE_CODE) ComCo_v_PduGroupSwitchRunnable(void);
static FUNC(void, RTE_CODE) ComCo_v_PduStateUpdate(const uint8_t ReqPduState);
#define Comco_STOP_SEC_CODE_LOCAL
#include <Comco_MemMap.h>

/*==================[external function definitions]=========================*/
#define Comco_START_SEC_CODE
#include <Comco_MemMap.h>
/**
 * \functions Comco_Init
 *
 * \brief This is the initial function of Comco.
 *
 ** \param[in] none, 
 *
 ** \param[out] none,
 **                
 ** \return RTE_E_OK, 
 * \comments  The below initial function shall be call in Action list "BswM_ActLst_StartupTwoA"
 *
 */
FUNC(void, RTE_CODE) Comco_Init(void)
{
	s_Comco_StatusInfoData.RxSpecNMPdu = RX_NMPDU_NOK;
	s_Comco_StatusInfoData.PduState = PDUINACTIVE;
	s_Comco_StatusInfoData.WakeupFlag = (Boolean)FALSE;
	s_Comco_StatusInfoData.nmCurrentState = nm_state_unit;
	s_Comco_StatusInfoData.nmPreviousState = nm_state_unit;
	s_Comco_StatusInfoData.GlobVarsInitialized = (Boolean)TRUE;
}


/**
 * \functions Comco_MainFunction
 *
 * \brief The main function of the comcoordinator module. Core0_appl_10ms task
 *
 ** \param[in] none, 
 *
 ** \param[out] none,
 **                
 ** \return RTE_E_OK, 
 * \comments  
 *
 */
FUNC(void, RTE_CODE) Comco_MainFunction(void)
{
    if((Boolean)TRUE == s_Comco_StatusInfoData.GlobVarsInitialized)
    {
    	Comco_v_CheckforWakeUpStatus();
    	Comco_v_CheckforRXspecificNMPDU();
    	Comco_v_CheckforKeepAwakeStatus();
    	ComCo_v_PduGroupSwitchRunnable();
    	Comco_v_Update_NMState_PDU();
    }
    else
    { /*Do nothing.*/ }
} /* FUNC(void, RTE_CODE) Comco_MainFunction (void) */

/**
 * \functions Comco_u_NMWakupFlag_Read
 *
 * \brief This function only use for read NM wakeup flag.
 *
 ** \param[in] none, 
 *
 ** \param[out] *u_wakeupFlag, return NM wakeup flag.
 **              0x01: The ECU wakeup by NM PDU.
 **              0x00:  The ECU not wakeup by NM PDU.              
 ** \return RTE_E_OK, 
 * \comments  
 *
 */
FUNC(Std_ReturnType, RTE_CODE) Comco_u_NMWakupFlag_Read (P2VAR(uint8_t, AUTOMATIC, RTE_APPL_DATA) u_WakeupFlag)/* PRQA S 3432,3227,2 # 2023-07-17 Z.J.L:Add parenthesized in include files, not any affect: accept */

{
    Std_ReturnType u_Retval = RTE_E_OK;
		
    if((Boolean)TRUE == s_Comco_StatusInfoData.WakeupFlag)
    {
        *u_WakeupFlag = (uint8_t)WAKEUP_SUCCESSFUL;
	}
	else
	{
	    *u_WakeupFlag = (uint8_t)WAKEUP_FAILED;
	}
	
    return u_Retval;
} /* FUNC(Std_ReturnType, RTE_CODE) Comco_u_NMWakupFlag_Read (P2VAR(uint8_t, AUTOMATIC, RTE_APPL_DATA) u_WakeupFlag) */

/**
 * \functions Comco_u_nmPreviousState_Read
 *
 * \brief This function only use for read NM previous state.
 *
 ** \param[in] none, 
 *
 ** \param[out] *u_PreNmState, return NM previous state.
 **              0x00: nm_state_unit
 **              0x01: nm_state_sleep
 **              0x02: nm_state_Prepare_bus_sleep
 **              0x03: nm_state_ready_sleep
 **              0x04: nm_state_normal_operation
 **              0x05: nm_state_repeat_message
 ** \return RTE_E_OK, 
 * \comments  
 *
 */
FUNC(Std_ReturnType, RTE_CODE) Comco_u_nmPreviousState_Read (P2VAR(uint8_t, AUTOMATIC, RTE_APPL_DATA) u_PreNmState)/* PRQA S 3432,3227,2 # 2023-07-17 Z.J.L:Add parenthesized in include files, not any affect: accept */
{
    Std_ReturnType u_Retval = RTE_E_OK;

    *u_PreNmState = (uint8_t)s_Comco_StatusInfoData.nmPreviousState;

	return u_Retval;
}/* FUNC(Std_ReturnType, RTE_CODE) Comco_u_nmPreviousState_Read (P2VAR(uint8_t, AUTOMATIC, RTE_APPL_DATA) u_PreNmState) */

/**
 * \functions Comco_u_nmCurrentState_Read
 *
 * \brief This function only use for read NM current state.
 *
 ** \param[in] none, 
 *
 ** \param[out] *u_PreNmState, return NM previous state.
 **              0x00: nm_state_unit
 **              0x01: nm_state_sleep
 **              0x02: nm_state_Prepare_bus_sleep
 **              0x03: nm_state_ready_sleep
 **              0x04: nm_state_normal_operation
 **              0x05: nm_state_repeat_message
 ** \return RTE_E_OK, 
 * \comments  
 *
 */
FUNC(Std_ReturnType, RTE_CODE) Comco_u_nmCurrentState_Read (P2VAR(uint8_t, AUTOMATIC, RTE_APPL_DATA) u_CurNmState)/* PRQA S 3432,3227,2 # 2023-07-17 Z.J.L:Add parenthesized in include files, not any affect: accept */
{
    Std_ReturnType u_Retval = RTE_E_OK;

    *u_CurNmState = (uint8_t)s_Comco_StatusInfoData.nmCurrentState;

	return u_Retval;
}/* FUNC(Std_ReturnType, RTE_CODE) Comco_u_nmCurrentState_Read (P2VAR(uint8_t, AUTOMATIC, RTE_APPL_DATA) u_CurNmState) */

/**
 * \functions Nm_PduRxIndication
 *
 * \brief The function Nm_PduRxIndication() will be call when receive NM PDU.
 *
 ** \param[in] nmNetworkHandle, not used.
 *
 ** \param[out] none,
 **                
 ** \return RTE_E_OK, 
 * \comments  
 *
 */
FUNC(void, NM_CODE) Nm_PduRxIndication(NetworkHandleType nmNetworkHandle)/* PRQA S 3227,2 # 2023-07-17 Z.J.L:It's generate by RTE tools, not any affect: accept */
{
	 static boolean b_Rxcompleted = (Boolean)TRUE;

	 TS_PARAM_UNUSED(nmNetworkHandle); /* PRQA S 3469,3119,2 # 2023-07-17 Z.J.L: Not use this parameter in function, not any affect: accept */
     /*Verify that the CAN wake up is valid,the below variant will be set to 0x01 when receive valid NM PDU. */
	 SET_COMCO_RXSPECNMPDU(RX_NMPDU_OK); /* PRQA S 3432,2 # 2023-07-17 Z.J.L:Add parenthesized in include files, not any affect: accept */

     if((Boolean)FALSE != b_Rxcompleted)
     {
         (void)Rte_Call_RP_ComM_UserRequest_Public_RequestComMode(COMM_FULL_COMMUNICATION);
         (void)Rte_Call_RP_ComM_UserRequest_Private_RequestComMode(COMM_FULL_COMMUNICATION);
	     
		 b_Rxcompleted = (Boolean)FALSE;
     }
}

/**
 * \functions Nm_StateChangeNotificationCallout
 *
 * \brief When the Network Management state change, will be call this function to notification nm state.
 *
 ** \param[in] nmNetworkHandle, not used.
 *
 ** \param[in] nmPreviousState, the previous state of nm.
 *
 ** \param[in] nmCurrentState, the current state of nm.
 *
 ** \param[out] none,
 **                
 ** \return RTE_E_OK, 
 * \comments  
 *
 */
FUNC(void, NM_CODE) Nm_StateChangeNotificationCallout
(
  NetworkHandleType nmNetworkHandle, /* PRQA S 3227,2 # 2023-07-17 Z.J.L:It's generate by RTE tools, not any affect: accept */
  Nm_StateType nmPreviousState, /* PRQA S 3227,2 # 2023-07-17 Z.J.L:It's generate by RTE tools, not any affect: accept */
  Nm_StateType nmCurrentState /* PRQA S 3227,2 # 2023-07-17 Z.J.L:It's generate by RTE tools, not any affect: accept */
)
{
	TS_PARAM_UNUSED(nmNetworkHandle);/* PRQA S 3469,3119,2 # 2023-07-17 Z.J.L: Not use this parameter in function, not any affect: accept */

	SET_COMCO_PREVIOUS_NMSTATE((e_Comco_NMStateType_t)nmPreviousState); /* PRQA S 4342,3430,4 # 2023-07-17 Z.J.L: Need limit in normal scope, not any affect: accept */

	switch(nmCurrentState)
	{
	    case NM_STATE_UNINIT:
		    SET_COMCO_CURRENT_NMSTATE(nm_state_unit);/* PRQA S 3432,2 # 2023-07-17 Z.J.L:Add parenthesized in include files, not any affect: accept */
		    break;
	    case NM_STATE_BUS_SLEEP:
	    	SET_COMCO_CURRENT_NMSTATE(nm_state_bus_sleep);/* PRQA S 3432,2 # 2023-07-17 Z.J.L:Add parenthesized in include files, not any affect: accept */
			/*When the transmit to bussleep,shall be clean wake up flag.*/
		    if(nm_state_Prepare_bus_sleep == s_Comco_StatusInfoData.nmPreviousState)
		    {
                SET_COMCO_WAKEUPFLAG((Boolean)FALSE);/* PRQA S 3430,4 # 2023-07-17 Z.J.L: Need limit in normal scope, not any affect: accept */
			}
			else
			{/*Do nothing.*/}
	    	break;
	    case NM_STATE_PREPARE_BUS_SLEEP:
	    	SET_COMCO_CURRENT_NMSTATE(nm_state_Prepare_bus_sleep);/* PRQA S 3432,2 # 2023-07-17 Z.J.L:Add parenthesized in include files, not any affect: accept */
	    	/*Clear wake flag of NM PDU*/
            SET_COMCO_RXSPECNMPDU(RX_NMPDU_NOK); /* PRQA S 3432,2 # 2023-07-17 Z.J.L:Add parenthesized in include files, not any affect: accept */
	    	break;
	    case NM_STATE_READY_SLEEP:
	    	SET_COMCO_CURRENT_NMSTATE(nm_state_ready_sleep);/* PRQA S 3432,2 # 2023-07-17 Z.J.L:Add parenthesized in include files, not any affect: accept */
	    	break;
	    case NM_STATE_NORMAL_OPERATION:
	    	SET_COMCO_CURRENT_NMSTATE(nm_state_normal_operation);/* PRQA S 3432,2 # 2023-07-17 Z.J.L:Add parenthesized in include files, not any affect: accept */
	    	break;
	    case NM_STATE_REPEAT_MESSAGE:
	    	SET_COMCO_CURRENT_NMSTATE(nm_state_repeat_message);/* PRQA S 3432,2 # 2023-07-17 Z.J.L:Add parenthesized in include files, not any affect: accept */
	    	break;
	    default:/* PRQA S 2016,2 # 2023-07-17 Z.J.L:not other state need to process, not any affect: accept */
	    	break;
	}
}

/**
 * \functions CanIfTransmit_UserCallout
 *
 * \brief if not get vaild wakeup source ,shall be choke CanIf_Transmit(), not send any PDU to CANbus.
 *
 ** \param[in] none, 
 *
 ** \param[out] none,
 **                
 ** \return RTE_E_OK, 
 * \comments  
 *
 */
FUNC(Std_ReturnType, RTE_CODE) CanIfTransmit_UserCallout(void)
{
     if((Boolean)TRUE != s_Comco_StatusInfoData.WakeupFlag)
	 {
	     (void)CanIf_SetPduMode(0,CANIF_TX_OFFLINE);
	     (void)CanIf_SetPduMode(1,CANIF_TX_OFFLINE);
	 } 
	 else
	 {  
		/*Can be to continue execute the next step*/
	 }

	 return 0;
}

#define Comco_STOP_SEC_CODE
#include <Comco_MemMap.h>

/*==================[internal function definitions]=========================*/
#define Comco_START_SEC_CODE_LOCAL
#include <Comco_MemMap.h>
/**
 * \functions ComCo_v_PduGroupSwitchRunnable
 *
 * \brief The function only used to control communication state(Only ApplicationMessage).
 *
 ** \param[in] none, 
 *
 ** \param[out] none,
 **                
 ** \return RTE_E_OK, 
 * \comments  
 *
 */
static FUNC(void, RTE_CODE) ComCo_v_PduGroupSwitchRunnable(void)
{  
	uint8_t   ui8_BswM_DiagComControl;
	boolean b_DisComReqest = (Boolean)FALSE; /* PRQA S 2211,1 # 2023-07-17 Z.J.L:not any affect: accept */

	/*Get the communicationControl($28) request from Dcm.*/
	ui8_BswM_DiagComControl = Rte_Mode_RP_BswM_MSI_DiagComControlMode_proto_DcmCommunicationControl();	

	(void)Rte_Read_RP_VoltMonI_SRI_DisableCommunication_DE_VoltMonI_DisableCommunication(&b_DisComReqest);
	
    if((Boolean)TRUE == s_Comco_StatusInfoData.WakeupFlag) //Only in normal wake up sequence ,can be control communication state.
    {
        if(((uint8_t)nm_state_repeat_message ==  (uint8_t)s_Comco_StatusInfoData.nmCurrentState) || \
			((uint8_t)nm_state_normal_operation == (uint8_t)s_Comco_StatusInfoData.nmCurrentState) || \
			  ((uint8_t)nm_state_ready_sleep == (uint8_t)s_Comco_StatusInfoData.nmCurrentState))
	    {   
	        if(((Boolean)FALSE == b_DisComReqest) 
				&& (((uint8_t)RTE_MODE_DcmCommunicationControl_DCM_ENABLE_RX_TX_NM == ui8_BswM_DiagComControl) \
				   ||((uint8_t)RTE_MODE_DcmCommunicationControl_DCM_DISABLE_RX_TX_NM == ui8_BswM_DiagComControl) \
				    ||((uint8_t)RTE_MODE_DcmCommunicationControl_DCM_DISABLE_RX_ENABLE_TX_NM == ui8_BswM_DiagComControl) \
				     ||((uint8_t)RTE_MODE_DcmCommunicationControl_DCM_ENABLE_RX_DISABLE_TX_NM == ui8_BswM_DiagComControl) \
				      ||((uint8_t)RTE_MODE_DcmCommunicationControl_DCM_ENABLE_RX_TX_NORM == ui8_BswM_DiagComControl) \
				       ||((uint8_t)RTE_MODE_DcmCommunicationControl_DCM_ENABLE_RX_TX_NORM_NM == ui8_BswM_DiagComControl))) 
		    {
	    	    ComCo_v_PduStateUpdate(PDURXTXACTIVE);
		    }
		    else if(((uint8_t)RTE_MODE_DcmCommunicationControl_DCM_DISABLE_RX_ENABLE_TX_NORM == ui8_BswM_DiagComControl) \
				  ||((uint8_t)RTE_MODE_DcmCommunicationControl_DCM_DISABLE_RX_ENABLE_TX_NORM_NM == ui8_BswM_DiagComControl))
		    {
                ComCo_v_PduStateUpdate(PDUTXACTIVE);
			}
			else if(((uint8_t)RTE_MODE_DcmCommunicationControl_DCM_ENABLE_RX_DISABLE_TX_NORM == ui8_BswM_DiagComControl) \
				  ||((uint8_t)RTE_MODE_DcmCommunicationControl_DCM_ENABLE_RX_DISABLE_TX_NORM_NM == ui8_BswM_DiagComControl))
			{
                ComCo_v_PduStateUpdate(PDURXACTIVE);
			}
			else
		    {
		    	/*When the current less than 6.5V or greater than 18.5 V AND Not any enable communication request from Dcm,the ECU shall be disable communication */
			    ComCo_v_PduStateUpdate(PDUINACTIVE);
		    }
	    }
	    else if((uint8_t)nm_state_Prepare_bus_sleep == (uint8_t)s_Comco_StatusInfoData.nmCurrentState)
	    {
		    ComCo_v_PduStateUpdate(PDURXACTIVE);
	    }
	    else
	    {
		    ComCo_v_PduStateUpdate(PDUINACTIVE);
	    }
    }
	else
	{/*Do nothing.*/}
}

/**
 * \functions ComCo_v_PduStateUpdate
 *
 * \brief The function only used to request communication state via BswM.
 *
 ** \param[in] ReqPduState, the state of Request PDU.
 *
 ** \param[out] none,
 **                
 ** \return none, 
 * \comments  
 *
 */
static FUNC(void, RTE_CODE) ComCo_v_PduStateUpdate(const uint8_t ReqPduState)
{
	if(ReqPduState != s_Comco_StatusInfoData.PduState)
	{
		if(PDURXACTIVE == (ReqPduState & PDURXACTIVE))
		{
			(s_Comco_StatusInfoData.PduState) |= PDURXACTIVE;
			(void)Rte_Switch_PP_Comco_MSI_RxPduGroupSwitch_proto_MDG_IPduGroupSwitch(RTE_MODE_MDG_IPduGroupSwitch_PDU_GROUP_START);
		}
		else
		{
			(s_Comco_StatusInfoData.PduState) &= (~(uint8_t)PDURXACTIVE); 
			(void)Rte_Switch_PP_Comco_MSI_RxPduGroupSwitch_proto_MDG_IPduGroupSwitch(RTE_MODE_MDG_IPduGroupSwitch_PDU_GROUP_STOP);
		}

		if(PDUTXACTIVE == (ReqPduState & PDUTXACTIVE))
		{
			(s_Comco_StatusInfoData.PduState) |= PDUTXACTIVE;
			(void)Rte_Switch_PP_Comco_MSI_TxPduGroupSwitch_proto_MDG_IPduGroupSwitch(RTE_MODE_MDG_IPduGroupSwitch_PDU_GROUP_START);
		}
		else
		{
			(s_Comco_StatusInfoData.PduState) &= (~(uint8_t)PDUTXACTIVE);  //PRQA S 4130// MISRA Rule 12.7/Bitwise operations on signed data will give implementation defined results is Accepted Ok.
			(void)Rte_Switch_PP_Comco_MSI_TxPduGroupSwitch_proto_MDG_IPduGroupSwitch(RTE_MODE_MDG_IPduGroupSwitch_PDU_GROUP_STOP);
		}
	}
	else
	{/* do nothing */}
}

/**
 * \functions Comco_v_CheckforWakeUpStatus
 *
 * \brief The function only used to check wake up status.
 *
 ** \param[in] none,
 *
 ** \param[out] none,
 **                
 ** \return none, 
 * \comments  
 *
 */
static FUNC(void, RTE_CODE) Comco_v_CheckforWakeUpStatus(void)
{
	float32_t f32_IgnVolt = 0.0f;
	
    (void)Rte_Call_RP_EvAdc_GetValue_VMON_IGN_GetPhyValue(&f32_IgnVolt);

	/*Verify that the CAN wake up is valid. RxSpecNMPdu will be set to 0x01 when get valid NM PDU.*/
	if(((RX_NMPDU_OK == s_Comco_StatusInfoData.RxSpecNMPdu)||(f32_IgnVolt >= IGN_ON_THSLD))&&(s_Comco_StatusInfoData.WakeupFlag != (Boolean)TRUE))
	{
		SET_COMCO_WAKEUPFLAG(TRUE); /* PRQA S 3432,1295,1 # 2023-07-17 Z.J.L:not any affect: accept */
	}
}

/**
 * \functions Comco_v_CheckforKeepAwakeStatus
 *
 * \brief The function only used to request network release or network request.
 *
 ** \param[in] none,
 *
 ** \param[out] none,
 **                
 ** \return none, 
 * \comments  
 *
 */
static FUNC(void, RTE_CODE) Comco_v_CheckforKeepAwakeStatus(void)
{   
    uint8_t   ui8_EspVehSpdVld = 0;
	uint16_t  ui16_EspVehSpd = 0; /* PRQA S 2211,1 # 2023-07-17 Z.J.L:not any affect: accept */
	float32_t f32_IgnVolt = 0.0f;
	float32_t f_EspVehSpd;
	static float32_t f_lastEsPVehSpd = 0.0f;/* PRQA S 2211,1 # 2023-07-17 Z.J.L:not any affect: accept */
	
    (void)Rte_Call_RP_EvAdc_GetValue_VMON_IGN_GetPhyValue(&f32_IgnVolt);

	(void)Rte_Read_RP_Com_SRI_EspVehSpdVld_DE_EspVehSpdVld(&ui8_EspVehSpdVld);

	(void)Rte_Read_RP_Com_SRI_EspVehSpd_DE_EspVehSpd(&ui16_EspVehSpd);
	//phy = raw* 0.05625;
	f_EspVehSpd = ((float)ui16_EspVehSpd * 5625.0f) / 100000.0f; /* PRQA S 3121,1 # 2023-07-17 Z.J.L:not any affect: accept */
	
	if((Boolean)TRUE == s_Comco_StatusInfoData.WakeupFlag)
	{  
		if(VEHSPD_VALID == ui8_EspVehSpdVld) //valid
        {		    
           f_lastEsPVehSpd = f_EspVehSpd;
		}
		else
		{
			/*When the vehicle speed vaildity not establish, shall be use the last value as precondtion */
           f_EspVehSpd = f_lastEsPVehSpd;
		}

	    if((f32_IgnVolt < IGN_OFF_THSLD) && (f_EspVehSpd < VEHSPD_THSLD)) /* Network release: normal operation mode ->ready sleep mode */
	    {
	    	/*(NM_11)Check if the local event disappear(KL15 off) AND (vehicle speed less than 3Km/h),request the communication state to FULL,then
	        the NM state will be transmit to ready sleep state.*/
		    (void)Rte_Call_RP_ComM_UserRequest_Public_RequestComMode(COMM_NO_COMMUNICATION);
	    }
	    else
	    {
	    	/*Network request.*/
		    (void)Rte_Call_RP_ComM_UserRequest_Public_RequestComMode(COMM_FULL_COMMUNICATION);
	    }
	}
	else
	{
		if((f32_IgnVolt < IGN_OFF_THSLD) && ((uint8_t)nm_state_normal_operation == (uint8_t)s_Comco_StatusInfoData.nmCurrentState)) //KL15 off
		{
		    (void)Rte_Call_RP_ComM_UserRequest_Public_RequestComMode(COMM_NO_COMMUNICATION);
		}
	}
	/*The FC shall be keep private channel to FULL when NM state stay in network mode.*/
    if(((uint8_t)nm_state_repeat_message == (uint8_t)s_Comco_StatusInfoData.nmCurrentState) || ((uint8_t)nm_state_normal_operation == (uint8_t)s_Comco_StatusInfoData.nmCurrentState)
		   || ((uint8_t)nm_state_ready_sleep == (uint8_t)s_Comco_StatusInfoData.nmCurrentState))
    {
	    (void)Rte_Call_RP_ComM_UserRequest_Private_RequestComMode(COMM_FULL_COMMUNICATION);
    }
    /*The FC need transmit to repeat message state when get valid wake source in prepare bus sleep mode.*/
    else if((uint8_t)nm_state_Prepare_bus_sleep == (uint8_t)s_Comco_StatusInfoData.nmCurrentState)
    {
        (void)Rte_Call_RP_ComM_UserRequest_Private_RequestComMode(COMM_NO_COMMUNICATION);
    }
    else if((uint8_t)nm_state_bus_sleep == (uint8_t)s_Comco_StatusInfoData.nmCurrentState)
    {
	    (void)Rte_Call_RP_ComM_UserRequest_Private_RequestComMode(COMM_NO_COMMUNICATION);
    }
    else
    {
	    (void)Rte_Call_RP_ComM_UserRequest_Private_RequestComMode(COMM_FULL_COMMUNICATION);
    }
}

/**
 * \functions Comco_v_CheckforRXspecificNMPDU
 *
 * \brief The function only used to check valid wakeup source to set PDU enable.
 *
 ** \param[in] none,
 *
 ** \param[out] none,
 **                
 ** \return none, 
 * \comments  
 *
 */
static FUNC(void, RTE_CODE) Comco_v_CheckforRXspecificNMPDU(void)
{
    static boolean b_Rxflag =(Boolean)TRUE;

    if(b_Rxflag != (Boolean)FALSE)
    {
    	/*if get the valid range of NM PDU or KL15 ON(local event wake up), shall be transmit normal PDU to can bus. */
        if((Boolean)TRUE == s_Comco_StatusInfoData.WakeupFlag)
    	{
        	(void)CanIf_SetPduMode(0,CANIF_ONLINE);
        	(void)CanIf_SetPduMode(1,CANIF_ONLINE);
    		/*Enable TX and RX normal PDU group and NM TX PDU, and then transmit signal. */
    		b_Rxflag = (Boolean)FALSE;
    	}
    	else
    	{/*Do nothing.*/}
    }
}

/**
 * \functions Comco_v_Update_NMState_PDU
 *
 * \brief The function only used to fill in some infomation in userdata.
 *
 ** \param[in] none,
 *
 ** \param[out] none,
 **                
 ** \return none, 
 * \comments  
 *
 */
static FUNC(void, RTE_CODE) Comco_v_Update_NMState_PDU(void)
{
    /*Do nothing*/
}

#define Comco_STOP_SEC_CODE_LOCAL
#include <Comco_MemMap.h>



