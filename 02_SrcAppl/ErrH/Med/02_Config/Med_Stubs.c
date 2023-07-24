/**
 * \file Med_Stubs.c
 *
 * \brief
 *
 * \version refer the Med_Core.h.
 *
 */

/*==================[inclusions]============================================*/
#include "Med_Core.h"
#include "Med_Stubs.h"
#include "Med_Rmt.h"
#include "Com.h"
#include <Com_Api_Static.h>
#include "Rte_Dem_Type.h"
#include "Cdd_EvAdc.h"
#include <Dem_Int_Stc.h>
#include "VoltageMonitor.h"




#if ((defined MED_INJECTION_ENABLED) && (MED_INJECTION_ENABLED == STD_ON))
//******************************************************************************
/// This static variable is used to trigger the event injection
/// \description of range
///   range: from b_FALSE to b_TRUE
/// \description of data flow
///   This variable is written and read in Med module
///
///******************************************************************************
static boolean Med_b_EventInjectionTrigger = FALSE;
//******************************************************************************
/// This static array variable is used to indicate the injection status of event \n 
/// specific state
/// \description of range
///   index range:  maximum number of elements this array can hold is 463 \n
///           each element value can be in the range 0x00 to 0xFF
/// \description of data flow
///   This variable is written and read in Med module
///
///******************************************************************************
//static Dem_EventStatusType Med_a_EventInjectionStatus[DEM_NUMBER_OF_EVENTS];
//******************************************************************************
/// This static array variable is used to inject the dem event into queue
/// \description of range
///   index range:  maximum number of elements this array can hold is 5 \n
///           each element value can be in the range 0x0000 to 0xFFFF
/// \description of data flow
///   This variable is written and read in Med module
///
///******************************************************************************
#define MED_EVENT_INJECTION_QUEUE_SIZE  10
static s_Med_InjectQueue_t Med_a_EventInjectionQueue[MED_EVENT_INJECTION_QUEUE_SIZE];

//******************************************************************************
/// DEM_EVENT_STATUS_NO_INJECTION is used to indicate no injection status of Dem event
/// \description of range
///   Not applicable, fixed value is used here (0xFF)
/// \description of data flow
///   This is constant value and it is used in Med module
///
///******************************************************************************
#define DEM_EVENT_STATUS_NO_INJECTION (0xFF)
#endif

#if ((defined MED_PARENTDTC_ENABLED) && (MED_PARENTDTC_ENABLED == STD_ON))
static s_Med_ParentDTC_t  s_Med_ParentDTC;
#endif

#if ((defined MED_SENDFCSTATUS_ENABLED) && (MED_SENDFCSTATUS_ENABLED == STD_ON))
static uint8 Med_a_CameraFailureStatus[DEM_NUMBER_OF_EVENTS] = {0};
static uint8 Med_a_AEBTextInfoStatus[DEM_NUMBER_OF_EVENTS] = {0};
static uint8 Med_a_CameraCalibrationStatus[DEM_NUMBER_OF_EVENTS] = {0};
#endif

static s_Med_ErrorInfo_t s_Med_ErrorInfo;



/*==================[external data definition]==============================*/


/*==================[internal data definition]==============================*/


/*==================[internal function declarations]========================*/
#if ((defined MED_SENDFCSTATUS_ENABLED) && (MED_SENDFCSTATUS_ENABLED == STD_ON))
static FUNC(Std_ReturnType, RTE_CODE)Med_u_FaultHandling_FCStatus(Dem_EventIdType EventId, Dem_EventStatusType EventStatus, uint8  CameraFailureStatus, uint8 AEBTextInfoStatus, uint8 CameraCalibrationStatus);
static FUNC(Std_ReturnType, RTE_CODE)Med_u_FaultHandling_FCStatus_TX(void);
#endif

#if ((defined MED_PARENTDTC_ENABLED) && (MED_PARENTDTC_ENABLED == STD_ON))
static FUNC(void, RTE_CODE) Med_ParentDTC(void);
static FUNC(void, RTE_CODE) Med_ParentDTC_VCU161(void);
static FUNC(void, RTE_CODE) Med_ParentDTC_GW17A(void);
static FUNC(void, RTE_CODE) Med_ParentDTC_GW170(void);
static FUNC(void, RTE_CODE) Med_ParentDTC_GW288(void);
static FUNC(void, RTE_CODE) Med_ParentDTC_GW2DE(void);
static FUNC(void, RTE_CODE) Med_ParentDTC_GW50(void);
static FUNC(void, RTE_CODE) Med_ParentDTC_GW278(void);
static FUNC(void, RTE_CODE) Med_ParentDTC_FR136(void);
#endif

static FUNC(Std_ReturnType, RTE_CODE) Med_u_Required_Port(void);

static FUNC(Std_ReturnType, RTE_CODE) Med_u_Provided_Port(void);

/*==================[external function definitions]=========================*/
/**
 * \functions Med_Cot_TestFailed_BattVoltTooLow
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
FUNC(boolean, RTE_CODE) Med_TestFailed_HwStatus_BattVoltTooLow(void)
{
	boolean b_RetVal = FALSE;
	
    static uint8 ui8_VoltState = (uint8)VoltMonI_VoltageNormal;
	
    ui8_VoltState = s_Med_ErrorInfo.HardwareStatus.ui8_BattVoltState;
	
	if(((uint8)VoltMonI_VoltageNormal) == ui8_VoltState)
	{
        b_RetVal = FALSE;
	}
	else if((((uint8)VoltMonI_VoltageLow) == ui8_VoltState) || (((uint8)VoltMonI_VoltageUnderLow) == ui8_VoltState))
	{
	    b_RetVal = TRUE;
	}
	
	return b_RetVal;
}

/**
 * \functions Med_Cot_TestFailed_BattVoltTooHigh
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
FUNC(boolean, RTE_CODE) Med_TestFailed_HwStatus_BattVoltTooHigh(void)
{
	boolean b_RetVal = FALSE;
	
    static uint8 ui8_VoltState = (uint8)VoltMonI_VoltageNormal;
	
    ui8_VoltState = s_Med_ErrorInfo.HardwareStatus.ui8_BattVoltState;
	
	if(((uint8)VoltMonI_VoltageNormal) == ui8_VoltState)
	{
        b_RetVal = FALSE;
	}
	else if((((uint8)VoltMonI_VoltageHigh) == ui8_VoltState) ||(((uint8)VoltMonI_VoltageOverHigh) == ui8_VoltState))
	{
	    b_RetVal = TRUE;
	}
	
	return b_RetVal;

}

/**
 * \functions Med_Cot_TestFailed_McuExtTempTooHigh
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
FUNC(boolean, RTE_CODE) Med_TestFailed_HwStatus_McuExtTempTooHigh(void)
{
	boolean b_RetVal = FALSE;
	uint16 ui16_EcuTemperature;

	ui16_EcuTemperature = s_Med_ErrorInfo.HardwareStatus.ui16_EcuTemperature;

	if(ui16_EcuTemperature < (230)) //120 = reg: 230.4799743
	{
        b_RetVal = TRUE;
	}
	else
	{
        b_RetVal = FALSE;
	}
	
	return b_RetVal;
}

/**
 * \functions Med_Cot_TestFailed_McuExtTempTooLow
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
FUNC(boolean, RTE_CODE) Med_TestFailed_HwStatus_McuExtTempTooLow(void)
{
	boolean b_RetVal = FALSE;
	uint16 ui16_EcuTemperature;
    
    ui16_EcuTemperature = s_Med_ErrorInfo.HardwareStatus.ui16_EcuTemperature;

	if(ui16_EcuTemperature > (3895)) //-40 = reg: 3895.87721
	{
        b_RetVal = TRUE;
	}
	else
	{
        b_RetVal = FALSE;
	}
	
	return b_RetVal;

}

/**
 * \functions Med_TestFailed_HwStatus_McuInitialTempTooHigh
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
FUNC(boolean, RTE_CODE) Med_TestFailed_HwStatus_McuInitialTempTooHigh(void)
{
	boolean b_RetVal = FALSE;

    //if(TRUE == Esm_b_SocIntialTemptoHigh)
    //{
       //b_RetVal = TRUE;
    //}
    //else
    //{
       //b_RetVal = FALSE;
    //}
	return b_RetVal;
}

/**
 * \functions Med_TestFailed_HwStatus_SpiDriverFault
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
FUNC(boolean, RTE_CODE) Med_TestFailed_HwStatus_SpiDriverFault(void)
{
	boolean b_RetVal = FALSE;
		
	return b_RetVal;

}

/**
 * \functions Med_TestFailed_HwStatus_Dflash_Error
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
FUNC(boolean, RTE_CODE) Med_TestFailed_HwStatus_Dflash_Error(void)
{
	boolean b_RetVal = FALSE;
		
	return b_RetVal;

}

/**
 * \functions Med_TestFailed_CAN_SigalStatus_VCUAccrPedlPosnInvld
 *
 * \brief   
 *
 ** \param[in] none,
 *
 ** \param[out] none,
 *
 ** \return RTE_E_OK, 
 * \comments
 * DTC Confirm Condition:
 * VcuAccrPedlPosn = 0x3FF or VcuAccrPedlPosnVld = 0x1 for consecutive 10 times(100ms)
 */
FUNC(boolean, RTE_CODE) Med_TestFailed_CAN_SigalStatus_VCUAccrPedlPosnInvld(void)
{	
    boolean b_RetVal = FALSE;

	if((s_Med_ErrorInfo.CanSignalStatus.ui16_VcuAccrPedlPosn == 0x3FF)  //raw = 0x3ff -> phy = 1023/ 0.1= 102.3
		     || (s_Med_ErrorInfo.CanSignalStatus.ui8_VcuAccrPedlPosn_Status == 0x01u))
	{
        b_RetVal = TRUE;  //Trigger report Dtc to Dem.
	}
	else
	{
        b_RetVal = FALSE;
	}
    return b_RetVal;
}

/**
 * \functions Med_TestFailed_CAN_SigalStatus_VCUGearPosnInvld
 *
 * \brief   
 *
 ** \param[in] none,
 *
 ** \param[out] none,
 *
 ** \return RTE_E_OK, 
 * \comments
 * DTC Confirm Condition:
 * VcuGearPosn is out of range 0x1~0x4 or VcuVehGearPosnVld = 0x1 for consecutive 10 times(100ms).
 */
FUNC(boolean, RTE_CODE) Med_TestFailed_CAN_SigalStatus_VCUGearPosnInvld(void)
{
	boolean b_RetVal = FALSE;

	if((s_Med_ErrorInfo.CanSignalStatus.ui8_VcuGearPosn <= 0x00U) \
		|| (s_Med_ErrorInfo.CanSignalStatus.ui8_VcuGearPosn >= 0x05U)  \
		  || (s_Med_ErrorInfo.CanSignalStatus.ui8_VcuGearPosn_Status == 0x01u))
	{
		b_RetVal = TRUE;
	}
	else
	{
		b_RetVal = FALSE;
	}
		
	return b_RetVal;
}

/**
 * \functions Med_TestFailed_CAN_SigalStatus_BCMTurnIndcrLightFault
 *
 * \brief   
 *
 ** \param[in] none,
 *
 ** \param[out] none,
 *
 ** \return RTE_E_OK, 
 * \comments
 * DTC Confirm Condition:
 * BcmTurnIndcrLe is 0x3 or BcmTurnIndcrRi is 0x3 for consecutive 10 times(400ms).
 */
FUNC(boolean, RTE_CODE) Med_TestFailed_CAN_SigalStatus_BCMTurnIndcrLightFault(void)
{	
    boolean b_RetVal = FALSE;

	if((s_Med_ErrorInfo.CanSignalStatus.ui8_BcmTurnIndcrLe == 0x03U)  \
	  || (s_Med_ErrorInfo.CanSignalStatus.ui8_BcmTurnIndcrRi == 0x03U))
	{
	    b_RetVal = TRUE;
	}
	else
	{
		b_RetVal = FALSE;
	}
	return b_RetVal;  	
}

/**
 * \functions Med_TestFailed_CAN_SigalStatus_BCMFrntWiperStsFault
 *
 * \brief   D791F1
 *
 ** \param[in] none,
 *
 ** \param[out] none,
 *
 ** \return RTE_E_OK, 
 * \comments
 * DTC Confirm Condition:
 * BcmFrntWiperSts is 0x3 for consecutive 10 times(400ms).
 */
FUNC(boolean, RTE_CODE) Med_TestFailed_CAN_SigalStatus_BCMFrntWiperStsFault(void)
{ 
	boolean b_RetVal = FALSE;

	if(s_Med_ErrorInfo.CanSignalStatus.ui8_BcmFrntWiperSts == 0x03U)
	{
		b_RetVal = TRUE;
	}
	else
	{
		b_RetVal = FALSE;
	}
	return b_RetVal;
}

/**
 * \functions Med_TestFailed_CAN_SigalStatus_ESPVehSpdInvld
 *
 * \brief   
 *
 ** \param[in] none,
 *
 ** \param[out] none,
 *
 ** \return RTE_E_OK, 
 * \comments
 * DTC Confirm Condition:
 * EspVehSpdVld = 0x1 for consecutive 10 times(100ms) or EspVehSpd is out of range 0x0~0x1900 for consecutive 10 times(100ms)
 */
FUNC(boolean, RTE_CODE) Med_TestFailed_CAN_SigalStatus_ESPVehSpdInvld(void)
{
    boolean b_RetVal = FALSE;
	
	if((s_Med_ErrorInfo.CanSignalStatus.ui8_EspVehSpd_Status == 0x01u) \
	|| (s_Med_ErrorInfo.CanSignalStatus.ui16_EspVehSpd > 0x1900)) //Raw value = 0x1900(6400) ->phy value = 6400 *0.05625 = 360km/h
	{
		b_RetVal = TRUE;
	}
	else
	{
		b_RetVal = FALSE;
	}

	return b_RetVal;  
}

/**
 * \functions Med_TestFailed_CAN_SigalStatus_WhlSpdPlsInvld
 *
 * \brief   
 *
 ** \param[in] none,
 *
 ** \param[out] none,
 *
 ** \return RTE_E_OK, 
 * \comments
 * DTC Confirm Condition:
 * WhlSpdFrntLePls=0xFF or WhlSpdFrntRiPls=0xFF or WhlSpdReLePls=0xFF or WhlSpdReRiPls=0xFF for consecutive 10 times(100ms).
 */
FUNC(boolean, RTE_CODE) Med_TestFailed_CAN_SigalStatus_WhlSpdPlsInvld(void)
{
    boolean b_RetVal = FALSE;
	
	if((s_Med_ErrorInfo.CanSignalStatus.ui8_WhlSpdFrntLePls == 0xFFU)  //Raw value = 0xFF(255) ->phy value = 255 *1 = 255
	|| (s_Med_ErrorInfo.CanSignalStatus.ui8_WhlSpdFrntRiPls == 0xFFU) 
	|| (s_Med_ErrorInfo.CanSignalStatus.ui8_WhlSpdReLePls == 0xFFU)   
	|| (s_Med_ErrorInfo.CanSignalStatus.ui8_WhlSpdReRiPls == 0xFFU)) 
	{
		b_RetVal = TRUE;
	}
	else
	{
		b_RetVal = FALSE;
	}

	return b_RetVal;  
}

/**
 * \functions Med_TestFailed_CAN_SigalStatus_WhlSpdDirInvld
 *
 * \brief   
 *
 ** \param[in] none,
 *
 ** \param[out] none,
 *
 ** \return RTE_E_OK, 
 * \comments
 * DTC Confirm Condition:
 * WhlSpdLeFrntDir or WhlSpdLeReDir or WhlSpdRiFrntDir or  WhlSpdRiReDir = 0x3 invalid for consecutive 10 times(100ms).
 */
FUNC(boolean, RTE_CODE) Med_TestFailed_CAN_SigalStatus_WhlSpdDirInvld(void)
{	
	boolean b_RetVal = FALSE;
	
   	if((s_Med_ErrorInfo.CanSignalStatus.ui8_WhlSpdLeFrntDir == 0x03U)  
	 || (s_Med_ErrorInfo.CanSignalStatus.ui8_WhlSpdLeReDir == 0x03U)  
	  || (s_Med_ErrorInfo.CanSignalStatus.ui8_WhlSpdRiFrntDir == 0x03U)    
	    || (s_Med_ErrorInfo.CanSignalStatus.ui8_WhlSpdRiReDir == 0x03U))
	{
		b_RetVal = TRUE;
	}
	else
	{
		b_RetVal = FALSE;
	}

	return b_RetVal;
}

/**
 * \functions Med_TestFailed_CAN_SigalStatus_WhlSpdDataInvld
 *
 * \brief   
 *
 ** \param[in] none,
 *
 ** \param[out] none,
 *
 ** \return RTE_E_OK, 
 * \comments
 * DTC Confirm Condition:
 * WhlSpdLeFrntDataVld or WhlSpdLeReDataVld or WhlSpdRiFrntDataVld or WhlSpdRiReDataVld= 0x1 invalid for consecutive 10 times(100ms).
 */
FUNC(boolean, RTE_CODE) Med_TestFailed_CAN_SigalStatus_WhlSpdDataInvld(void)
{
    boolean b_RetVal = FALSE;
		
	if((0x01u == s_Med_ErrorInfo.CanSignalStatus.ui8_WhlSpdLeFrntDataVld)  \
	|| (0x01u == s_Med_ErrorInfo.CanSignalStatus.ui8_WhlSpdLeReDataVld)  \
	|| (0x01u == s_Med_ErrorInfo.CanSignalStatus.ui8_WhlSpdRiFrntDataVld) \
	|| (0x01u == s_Med_ErrorInfo.CanSignalStatus.ui8_WhlSpdRiReDataVld))
	{
		b_RetVal = TRUE;
	}
	else
	{
		b_RetVal = FALSE;
	}
	
	return b_RetVal;
}

/**
 * \functions Med_TestFailed_CAN_SigalStatus_EPSSasNOTCal
 *
 * \brief   
 *
 ** \param[in] none,
 *
 ** \param[out] none,
 *
 ** \return RTE_E_OK, 
 * \comments
 * DTC Confirm Condition:
 * EpsSasCalSts=0x1 for consecutive 10 times(100ms).
 */
FUNC(boolean, RTE_CODE) Med_TestFailed_CAN_SigalStatus_EPSSasNOTCal(void)
{
    boolean b_RetVal = FALSE;
		
	if(s_Med_ErrorInfo.CanSignalStatus.ui8_EpsSasCalSts == 0x01U)  
	{
		b_RetVal = TRUE;
	}
	else
	{
		b_RetVal = FALSE;
	}
	
	return b_RetVal;	
}

/**
 * \functions Med_TestFailed_CAN_SigalStatus_EPSActualMotorTorqInvld
 *
 * \brief   
 *
 ** \param[in] none,
 *
 ** \param[out] none,
 *
 ** \return RTE_E_OK, 
 * \comments
 * DTC Confirm Condition:
 * EpsSasSteerAgVld=0x1 for consecutive 10 times(100ms)
 */
FUNC(boolean, RTE_CODE) Med_TestFailed_CAN_SigalStatus_EPSActualMotorTorqInvld(void)
{
	boolean b_RetVal = FALSE;
		
	if(s_Med_ErrorInfo.CanSignalStatus.ui8_EpsSasSteerAg_Status == 0x01u)  
	{
		b_RetVal = TRUE;
	}
	else
	{
		b_RetVal = FALSE;
	}
	
	return b_RetVal;
}

/**
 * \functions Med_TestFailed_CAN_SigalStatus_ESPLatAccelInvld
 *
 * \brief   
 *
 ** \param[in] none,
 *
 ** \param[out] none,
 *
 ** \return RTE_E_OK, 
 * \comments
 * DTC Confirm Condition:
 * ESP_LatAccel = 0x1FFF or ESP_LatAccelValid !=0x1 for consecutive 10 times(100ms)
 */
FUNC(boolean, RTE_CODE) Med_TestFailed_CAN_SigalStatus_ESPLatAccelInvld(void)
{
	boolean b_RetVal = FALSE;
		
	if((s_Med_ErrorInfo.CanSignalStatus.ui16_EspLatAccel == 0x1FFF)  //Raw value = 0x1FFF(8191) ->phy value = 8191 *0.01 -32 =49.91 m/s2
		||(s_Med_ErrorInfo.CanSignalStatus.ui8_EspLatAccel_Status != 0x01U))  
	
	{
		b_RetVal = TRUE;
	}
	else
	{
		b_RetVal = FALSE;
	}
	
	return b_RetVal;
}

/**
 * \functions Med_TestFailed_CAN_SigalStatus_ESPLongAccelInvld
 *
 * \brief   
 *
 ** \param[in] none,
 *
 ** \param[out] none,
 *
 ** \return RTE_E_OK, 
 * \comments
 * DTC Confirm Condition:
 * ESP_LongAccel = 0x1FFF or ESP_LongAccelValid !=0x1 for consecutive 10 times(100ms).
 */
FUNC(boolean, RTE_CODE) Med_TestFailed_CAN_SigalStatus_ESPLongAccelInvld(void)
{
	boolean b_RetVal = FALSE;
		
	if((s_Med_ErrorInfo.CanSignalStatus.ui16_EspLongAccel == 0x1FFF)  //Raw value = 0x1FFF(8191) ->phy value = 8191 *0.01 -32 =49.91 m/s2
		||(s_Med_ErrorInfo.CanSignalStatus.ui8_EspLongAccel_Status != 0x01U))  
	{
		b_RetVal = TRUE;
	}
	else
	{
		b_RetVal = FALSE;
	}
	
	return b_RetVal;
}

/**
 * \functions Med_TestFailed_CAN_SigalStatus_ESPYawRateInvld
 *
 * \brief   
 *
 ** \param[in] none,
 *
 ** \param[out] none,
 *
 ** \return RTE_E_OK, 
 * \comments
 * DTC Confirm Condition:
 * ESP_YawRate = 0x3FFF or ESP_YawRateValid  !=0x1 for consecutive 10 times(100ms).
 */
FUNC(boolean, RTE_CODE) Med_TestFailed_CAN_SigalStatus_ESPYawRateInvld(void)
{
	boolean b_RetVal = FALSE;
	/*Worse case: */	
	if((s_Med_ErrorInfo.CanSignalStatus.ui16_EspYawRate == 0x3FFF)  //Raw value = 0x3FFF(16383) ->phy value = 16383 *0.01 -81.91 =81.92 degree/s
		||(s_Med_ErrorInfo.CanSignalStatus.ui8_EspYawRate_Status != 0x01U))  
	{
		b_RetVal = TRUE;
	}
	else
	{
		b_RetVal = FALSE;
	}
	
	return b_RetVal;
}

/**
 * \functions Med_TestFailed_CAN_SigalStatus_EPSFault
 *
 * \brief   
 *
 ** \param[in] none,
 *
 ** \param[out] none,
 *
 ** \return RTE_E_OK, 
 * \comments
 * DTC Confirm Condition:
 * EPS_fault_state  != 0x0 for consecutive 10 times(100ms).
 */
FUNC(boolean, RTE_CODE) Med_TestFailed_CAN_SigalStatus_EPSFault(void)
{
	boolean b_RetVal = FALSE;
		
	if(s_Med_ErrorInfo.CanSignalStatus.ui8_Epsfaultstate != 0x00U)  
	{
		b_RetVal = TRUE;
	}
	else
	{
		b_RetVal = FALSE;
	}
	
	return b_RetVal;
}

/**
 * \functions Med_TestFailed_CAN_SigalStatus_ESPABSFault
 *
 * \brief   
 *
 ** \param[in] none,
 *
 ** \param[out] none,
 *
 ** \return RTE_E_OK, 
 * \comments
 * DTC Confirm Condition:
 * EspAbsFailr = 0x1 for consecutive10 times(100ms).
 */
FUNC(boolean, RTE_CODE) Med_TestFailed_CAN_SigalStatus_ESPABSFault(void)
{
	boolean b_RetVal = FALSE;
		
	if(s_Med_ErrorInfo.CanSignalStatus.ui8_EspAbsFailr == 0x01U)  
	{
		b_RetVal = TRUE;
	}
	else
	{
		b_RetVal = FALSE;
	}
	
	return b_RetVal;
}

/**
 * \functions Med_TestFailed_CAN_SigalStatus_ESPTCSFault
 *
 * \brief   
 *
 ** \param[in] none,
 *
 ** \param[out] none,
 *
 ** \return RTE_E_OK, 
 * \comments
 * DTC Confirm Condition:
 * EspTcsFailr = 0x1 for consecutive10 times(100ms).
 */
FUNC(boolean, RTE_CODE) Med_TestFailed_CAN_SigalStatus_ESPTCSFault(void)
{
	boolean b_RetVal = FALSE;
		
	if(s_Med_ErrorInfo.CanSignalStatus.ui8_EspTcsFailr == 0x01U)  
	{
		b_RetVal = TRUE;
	}
	else
	{
		b_RetVal = FALSE;
	}
	
	return b_RetVal;
}

/**
 * \functions Med_TestFailed_CAN_SigalStatus_ESPABANOTAvailable
 *
 * \brief   
 *
 ** \param[in] none,
 *
 ** \param[out] none,
 *
 ** \return RTE_E_OK, 
 * \comments
 * DTC Confirm Condition:
 * ESP_ABAavailable=0x0 for consecutive 10 times(100ms).
 */
 FUNC(boolean, RTE_CODE) Med_TestFailed_CAN_SigalStatus_ESPABANOTAvailable(void)
{
	boolean b_RetVal = FALSE;
		
	if(s_Med_ErrorInfo.CanSignalStatus.ui8_EspABAavailable == 0x00U)  
	{
		b_RetVal = TRUE;
	}
	else
	{
		b_RetVal = FALSE;
	}
	
	return b_RetVal;
}

/**
 * \functions Med_TestFailed_CAN_SigalStatus_ESPAEBNOTAvailable
 *
 * \brief   
 *
 ** \param[in] none,
 *
 ** \param[out] none,
 *
 ** \return RTE_E_OK, 
 * \comments
 * DTC Confirm Condition:
 * ESP_AEBavailable=0x0 for consecutive 10 times(100ms).
 */
FUNC(boolean, RTE_CODE) Med_TestFailed_CAN_SigalStatus_ESPAEBNOTAvailable(void)
{
	boolean b_RetVal = FALSE;
		
	if(s_Med_ErrorInfo.CanSignalStatus.ui8_EspAEBAvailable == 0x00U)  
	{
		b_RetVal = TRUE;
	}
	else
	{
		b_RetVal = FALSE;
	}
	
	return b_RetVal;
}

/**
 * \functions Med_TestFailed_CAN_SigalStatus_ESPAWBNOTAvailable
 *
 * \brief   
 *
 ** \param[in] none,
 *
 ** \param[out] none,
 *
 ** \return RTE_E_OK, 
 * \comments
 * DTC Confirm Condition:
 * ESP_AWBavailable=0x0 for consecutive 10 times(100ms).
 */
FUNC(boolean, RTE_CODE) Med_TestFailed_CAN_SigalStatus_ESPAWBNOTAvailable(void)
{
	boolean b_RetVal = FALSE;
		
	if(s_Med_ErrorInfo.CanSignalStatus.ui8_EspAWBavailable == 0x00U)  
	{
		b_RetVal = TRUE;
	}
	else
	{
		b_RetVal = FALSE;
	}
	
	return b_RetVal;
}

/**
 * \functions Med_TestFailed_CAN_SigalStatus_IBBrkPedlInvld
 *
 * \brief   
 *
 ** \param[in] none,
 *
 ** \param[out] none,
 *
 ** \return RTE_E_OK, 
 * \comments
 * DTC Confirm Condition:
 * IbBrkPedlStsGbVld=0x2 for consecutive 10 times(100ms).
 */
FUNC(boolean, RTE_CODE) Med_TestFailed_CAN_SigalStatus_IBBrkPedlInvld(void)
{
	boolean b_RetVal = FALSE;
		
	if(s_Med_ErrorInfo.CanSignalStatus.ui8_IbBrkPedlStsGbVld == 0x02U)  
	{
		b_RetVal = TRUE;
	}
	else
	{
		b_RetVal = FALSE;
	}
	
	return b_RetVal;
}

/**
 * \functions Med_TestFailed_CAN_SigalStatus_EPSActualTorsionTorqInvld
 *
 * \brief   
 *
 ** \param[in] none,
 *
 ** \param[out] none,
 *
 ** \return RTE_E_OK, 
 * \comments
 * DTC Confirm Condition:
 * EPS_ActualTorsionBarTorq=0x7FF for consecutive 10 times(100ms).
 */
FUNC(boolean, RTE_CODE) Med_TestFailed_CAN_SigalStatus_EPSActualTorsionTorqInvld(void)
{
	boolean b_RetVal = FALSE;
		
	if(s_Med_ErrorInfo.CanSignalStatus.ui16_EpsActualTorsionBarTorq == 0x7FF)  
	{
		b_RetVal = TRUE;
	}
	else
	{
		b_RetVal = FALSE;
	}
	
	return b_RetVal;
}

/**
 * \functions Med_TestFailed_CAN_SigalStatus_EPSActualMotorInvld
 *
 * \brief   
 *
 ** \param[in] none,
 *
 ** \param[out] none,
 *
 ** \return RTE_E_OK, 
 * \comments
 * DTC Confirm Condition:
 * EPS_ActualMotorTorq=0xFFF for consecutive10 times(100ms).
 */
FUNC(boolean, RTE_CODE) Med_TestFailed_CAN_SigalStatus_EPSActualMotorInvld(void)
{
	boolean b_RetVal = FALSE;

	if(s_Med_ErrorInfo.CanSignalStatus.ui16_EpsActualMotorTorq == 0x0FFF)
	{
		b_RetVal = TRUE;
	}
	else
	{
		b_RetVal = FALSE;
	}
	
	return b_RetVal;
}

/**
 * \functions Med_TestFailed_CAN_SigalStatus_EPSSteerAgSensFault
 *
 * \brief   
 *
 ** \param[in] none,
 *
 ** \param[out] none,
 *
 ** \return RTE_E_OK, 
 * \comments
 * DTC Confirm Condition:
 * EpsSteerAgSensFilr =0x1 for consecutive 10 times(100ms).
 */
FUNC(boolean, RTE_CODE) Med_TestFailed_CAN_SigalStatus_EPSSteerAgSensFault(void)
{
	boolean b_RetVal = FALSE;

	if(s_Med_ErrorInfo.CanSignalStatus.ui8_EpsSteerAgSensFilr == 0x01U)
	{
		b_RetVal = TRUE;
	}
	else
	{
		b_RetVal = FALSE;
	}
	
	return b_RetVal;
}

/**
 * \functions Med_TestFailed_CAN_SigalStatus_SRSDrvrBucSwtInvld
 *
 * \brief   
 *
 ** \param[in] none,
 *
 ** \param[out] none,
 *
 ** \return RTE_E_OK, 
 * \comments
 * DTC Confirm Condition:
 * SrsDrvrBucSwtSts !=(0x00 and 0x01) for consecutive 2500ms.
 */
FUNC(boolean, RTE_CODE) Med_TestFailed_CAN_SigalStatus_SRSDrvrBucSwtInvld(void)
{
	boolean b_RetVal = FALSE;

	if((s_Med_ErrorInfo.CanSignalStatus.ui8_SrsDrvrBucSwtSts != 0x00U)
	 &&(s_Med_ErrorInfo.CanSignalStatus.ui8_SrsDrvrBucSwtSts != 0x01U))
	{
		b_RetVal = TRUE;
	}
	else
	{
		b_RetVal = FALSE;
	}
	
	return b_RetVal;
}

/**
 * \functions Med_TestFailed_CAN_SigalStatus_SRSDrvrBucSwtInvld
 *
 * \brief   
 *
 ** \param[in] none,
 *
 ** \param[out] none,
 *
 ** \return RTE_E_OK, 
 * \comments
 * DTC Confirm Condition:
 * EPS_Pinionang_Valid= 0x1 for consecutive 10 times(100ms).
 */
FUNC(boolean, RTE_CODE) Med_TestFailed_CAN_SigalStatus_EPSPinionangInvld(void)
{
	boolean b_RetVal = FALSE;

	if(0x01u == s_Med_ErrorInfo.CanSignalStatus.ui8_EpsPinionang_Status)
	{
		b_RetVal = TRUE;
	}
	else
	{
		b_RetVal = FALSE;
	}
	
	return b_RetVal;
}

/**
 * \functions Med_TestFailed_CAN_SigalStatus_EPSPinionangFault
 *
 * \brief   
 *
 ** \param[in] none,
 *
 ** \param[out] none,
 *
 ** \return RTE_E_OK, 
 * \comments
 * DTC Confirm Condition:
 * EpsFaild =0x1 or 0x2 or 0x3 for consecutive 10 times(200ms).
 * Fault-age Condition:
 * EpsFaild =0x0
 */
FUNC(boolean, RTE_CODE) Med_TestFailed_CAN_SigalStatus_EPSPinionangFault(void)
{
	boolean b_RetVal = FALSE;

	if((s_Med_ErrorInfo.CanSignalStatus.ui8_EpsFaild == 0x01U) \
	||(s_Med_ErrorInfo.CanSignalStatus.ui8_EpsFaild == 0x02U)  \
	||(s_Med_ErrorInfo.CanSignalStatus.ui8_EpsFaild == 0x03U))
	{
		b_RetVal = TRUE;
	}
	/*Worse case: When the current fault happend ,Set EpsFaild = 0x04-0x07, the fault will be recover age.*/
	else if(s_Med_ErrorInfo.CanSignalStatus.ui8_EpsFaild == 0x00U)
	{
		b_RetVal = FALSE;
	}
	
	return b_RetVal;
}

/**
 * \functions Med_TestFailed_CAN_SigalStatus_EPSAPAEpasFault
 *
 * \brief   
 *
 ** \param[in] none,
 *
 ** \param[out] none,
 *
 ** \return RTE_E_OK, 
 * \comments
 * DTC Confirm Condition:
 * EPS_APA_EpasFAILED = 0x1 for consecutive 10 times(200ms).
 */
FUNC(boolean, RTE_CODE) Med_TestFailed_CAN_SigalStatus_EPSAPAEpasFault(void)
{
	boolean b_RetVal = FALSE;

	if(s_Med_ErrorInfo.CanSignalStatus.ui8_EpsAPAEpasFAILED == 0x01U)
	{
		b_RetVal = TRUE;
	}
	else
	{
		b_RetVal = FALSE;
	}
	
	return b_RetVal;
}

/**
 * \functions Med_TestFailed_CAN_SigalStatus_BCMEmgyLiFault
 *
 * \brief   
 *
 ** \param[in] none,
 *
 ** \param[out] none,
 *
 ** \return RTE_E_OK, 
 * \comments
 * DTC Confirm Condition:
 * BcmEmgyLiSts = 0x3 for consecutive 10 times(400ms).
 */
FUNC(boolean, RTE_CODE) Med_TestFailed_CAN_SigalStatus_BCMEmgyLiFault(void)
{
	boolean b_RetVal = FALSE;

	if(s_Med_ErrorInfo.CanSignalStatus.ui8_BcmEmgyLiSts == 0x03U)
	{
		b_RetVal = TRUE;
	}
	else
	{
		b_RetVal = FALSE;
	}
	
	return b_RetVal;
}

/**
 * \functions Med_TestFailed_CAN_SigalStatus_SteeringWheelVibrationFailure
 *
 * \brief   
 *
 ** \param[in] none,
 *
 ** \param[out] none,
 *
 ** \return RTE_E_OK, 
 * \comments
 * DTC Confirm Condition:
 * EPS_ConcussAvailabilityStatus = 0x2 or 0x3 for consecutive 10 times(200ms).
 */
FUNC(boolean, RTE_CODE) Med_TestFailed_CAN_SigalStatus_SteeringWheelVibrationFailure(void)
{
	boolean b_RetVal = FALSE;

	if((s_Med_ErrorInfo.CanSignalStatus.ui8_EpsConcussAvailabilityStatus == 0x02U) \
	||(s_Med_ErrorInfo.CanSignalStatus.ui8_EpsConcussAvailabilityStatus == 0x03U))
	{
		b_RetVal = TRUE;
	}
	else
	{
		b_RetVal = FALSE;
	}
	
	return b_RetVal;
}

/**
 * \functions Med_TestFailed_CAN_SigalStatus_DriverHandTorqueInvalid
 *
 * \brief   
 *
 ** \param[in] none,
 *
 ** \param[out] none,
 *
 ** \return RTE_E_OK, 
 * \comments
 * DTC Confirm Condition:
 * EPS_MeasuredTorsionBarTorqValid = 0x1 for consecutive 10 times(100ms).
 */
FUNC(boolean, RTE_CODE) Med_TestFailed_CAN_SigalStatus_DriverHandTorqueInvalid(void)
{
	boolean b_RetVal = FALSE;

	if(0x01u == s_Med_ErrorInfo.CanSignalStatus.ui8_EpsMeasuredTorsionBarTorque_Status)
	{
		b_RetVal = TRUE;
	}
	else
	{
		b_RetVal = FALSE;
	}
	
	return b_RetVal;
}

/**
 * \functions Med_TestFailed_CAN_SigalStatus_IPWarningInvalid
 *
 * \brief   
 *
 ** \param[in] none,
 *
 ** \param[out] none,
 *
 ** \return RTE_E_OK, 
 * \comments
 * DTC Confirm Condition:
 * IP_QDashACCFail = 0x1 or IP_DISFail  = 0x1 for consecutive 10 times(500ms).
 */
FUNC(boolean, RTE_CODE) Med_TestFailed_CAN_SigalStatus_IPWarningInvalid(void)
{
	boolean b_RetVal = FALSE;

	if((s_Med_ErrorInfo.CanSignalStatus.ui8_IP_QDashACCFail == 0x01U)  \
	||(s_Med_ErrorInfo.CanSignalStatus.ui8_IP_DISFail == 0x01U))
	{
		b_RetVal = TRUE;
	}
	else
	{
		b_RetVal = FALSE;
	}
	
	return b_RetVal;
}

/**
 * \functions Med_TestFailed_CAN_SigalStatus_FradarNotCalibrationOrBlockage
 *
 * \brief   
 *
 ** \param[in] none,
 *
 ** \param[out] none,
 *
 ** \return RTE_E_OK, 
 * \comments
 * DTC Confirm Condition:
 * FRadarCalibrationStatus != 0x0  or ((FR_RadarFailureStatus = 0x1 or 0x2 )) for consecutive 10 times(500ms).
 */
FUNC(boolean, RTE_CODE) Med_TestFailed_CAN_SigalStatus_FradarNotCalibrationOrBlockage(void)
{
	boolean b_RetVal = FALSE;

	if((s_Med_ErrorInfo.CanSignalStatus.ui8_FRadarCalibrationStatus != 0x00U)  
	  ||(s_Med_ErrorInfo.CanSignalStatus.ui8_FR_RadarFailureStatus == 0x01U)
	  ||(s_Med_ErrorInfo.CanSignalStatus.ui8_FR_RadarFailureStatus == 0x02U)
    )
	{
		b_RetVal = TRUE;
	}
	else
	{
		b_RetVal = FALSE;
	}
	
	return b_RetVal;
}

/**
 * \functions Med_TestFailed_CAN_SigalStatus_FradarHardwareError
 *
 * \brief   
 *
 ** \param[in] none,
 *
 ** \param[out] none,
 *
 ** \return RTE_E_OK, 
 * \comments
 * DTC Confirm Condition:
 * FR_RadarFailureStatus = 0x3 or 0x4 or 0x5 for consecutive 10 times(500ms).
 */
FUNC(boolean, RTE_CODE) Med_TestFailed_CAN_SigalStatus_FradarHardwareError(void)
{
	boolean b_RetVal = FALSE;

	if((s_Med_ErrorInfo.CanSignalStatus.ui8_FR_RadarFailureStatus == 0x03U)  \
	||(s_Med_ErrorInfo.CanSignalStatus.ui8_FR_RadarFailureStatus == 0x04U)  \
	||(s_Med_ErrorInfo.CanSignalStatus.ui8_FR_RadarFailureStatus == 0x05U)
	)
	{
		b_RetVal = TRUE;
	}
	else
	{
		b_RetVal = FALSE;
	}
	
	return b_RetVal;
}

/**
 * \functions Med_TestFailed_CAN_SigalStatus_BCMBrakeLampError
 *
 * \brief   
 *
 ** \param[in] none,
 *
 ** \param[out] none,
 *
 ** \return RTE_E_OK, 
 * \comments
 * DTC Confirm Condition:
 * BCM_BrakeLampError = 0x1 for consecutive 10 times(400ms).
 */
FUNC(boolean, RTE_CODE) Med_TestFailed_CAN_SigalStatus_BCMBrakeLampError(void)
{
	boolean b_RetVal = FALSE;

	if(s_Med_ErrorInfo.CanSignalStatus.ui8_BCMBrakeLampError == 0x01U)
	{
		b_RetVal = TRUE;
	}
	else
	{
		b_RetVal = FALSE;
	}
	
	return b_RetVal;
}

/**
 * \functions Med_TestFailed_CAN_SigalStatus_EspEbdFailr
 *
 * \brief   
 *
 ** \param[in] none,
 *
 ** \param[out] none,
 *
 ** \return RTE_E_OK, 
 * \comments
 * DTC Confirm Condition:
 * EspEbdFailr = 0x1 for consecutive10 times(100ms).
 */
FUNC(boolean, RTE_CODE) Med_TestFailed_CAN_SigalStatus_EspEbdFailr(void)
{
	boolean b_RetVal = FALSE;

	if(s_Med_ErrorInfo.CanSignalStatus.ui8_EspEbdFailr == 0x01U)
	{
		b_RetVal = TRUE;
	}
	else
	{
		b_RetVal = FALSE;
	}
	
	return b_RetVal;
}

/**
 * \functions Med_TestFailed_CAN_PduStatus_SRS_NodeMissing
 *
 * \brief   
 *
 ** \param[in] none,
 *
 ** \param[out] none,
 *
 ** \return RTE_E_OK, 
 * \comments
 * DTC confirm Condition:
 * Any of SRS node messges(0x050) is missing for 1s.
 */
FUNC(boolean, RTE_CODE) Med_TestFailed_CAN_PduStatus_SRS_NodeMissing(void)
{
    boolean b_RetVal = FALSE;
	
	if(s_Med_ErrorInfo.CanPduStatus.GW_50_PduSts == E_MSG_STATUS_TOUT)
	{
		b_RetVal = TRUE;
	}
	else
	{
		b_RetVal = FALSE;
	}
	
	return b_RetVal;
}

/**
 * \functions Med_TestFailed_CAN_PduStatus_FR_NodeMissing
 *
 * \brief   
 *
 ** \param[in] none,
 *
 ** \param[out] none,
 *
 ** \return RTE_E_OK, 
 * \comments
 * DTC confirm Condition:
 * Any of FR node messges(0x136) is missing for 1s.
 */
FUNC(boolean, RTE_CODE) Med_TestFailed_CAN_PduStatus_FR_NodeMissing(void)
{
    boolean b_RetVal = FALSE;
	
	if(s_Med_ErrorInfo.CanPduStatus.FR_136_PduSts == E_MSG_STATUS_TOUT)
	{
		b_RetVal = TRUE;
	}
	else
	{
		b_RetVal = FALSE;
	}
	
	return b_RetVal;
}

/**
 * \functions Med_TestFailed_CAN_PduStatus_ADC_NodeMissing
 *
 * \brief   
 *
 ** \param[in] none,
 *
 ** \param[out] none,
 *
 ** \return RTE_E_OK, 
 * \comments
 * DTC confirm Condition:
 * Any of ADC node messges(0x345, 0x346, 0x19B) is missing for 1s(0x345, 0x346, 0x19B)
 */
FUNC(boolean, RTE_CODE) Med_TestFailed_CAN_PduStatus_ADC_NodeMissing(void)
{
    boolean b_RetVal = FALSE;
	
	if((s_Med_ErrorInfo.CanPduStatus.ADC_345_PduSts == E_MSG_STATUS_TOUT)
	 ||(s_Med_ErrorInfo.CanPduStatus.ADC_346_PduSts == E_MSG_STATUS_TOUT)
	 ||(s_Med_ErrorInfo.CanPduStatus.ADC_19B_PduSts == E_MSG_STATUS_TOUT))
	{
		b_RetVal = TRUE;
	}
	else
	{
		b_RetVal = FALSE;
	}
	
	return b_RetVal;
}

/**
 * \functions Med_TestFailed_CAN_PduStatus_VCU_NodeMissing
 *
 * \brief   
 *
 ** \param[in] none,
 *
 ** \param[out] none,
 *
 ** \return RTE_E_OK, 
 * \comments
 * DTC confirm Condition:
 * Any of VCU node messges(0x161) is missing for 100ms.
 */
FUNC(boolean, RTE_CODE) Med_TestFailed_CAN_PduStatus_VCU_NodeMissing(void)
{	
    boolean b_RetVal = FALSE;
	
	if(s_Med_ErrorInfo.CanPduStatus.VCU_161_PduSts == E_MSG_STATUS_TOUT)
	{
		b_RetVal = TRUE;
	}
	else
	{
		b_RetVal = FALSE;
	}
	
	return b_RetVal;
}

/**
 * \functions Med_TestFailed_CAN_PduStatus_ESP_NodeMissing
 *
 * \brief   
 *
 ** \param[in] none,
 *
 ** \param[out] none,
 *
 ** \return RTE_E_OK, 
 * \comments
 * DTC confirm Condition:
 * Any of ESP node messages(0x17A, 0x1C2,0x20B, 0x2C2, 0x278)is missing for 100ms 
 */
FUNC(boolean, RTE_CODE) Med_TestFailed_CAN_PduStatus_ESP_NodeMissing(void)
{
    boolean b_RetVal = FALSE;
	
	if((s_Med_ErrorInfo.CanPduStatus.GW_17A_PduSts == E_MSG_STATUS_TOUT)
	 ||(s_Med_ErrorInfo.CanPduStatus.GW_1C2_PduSts == E_MSG_STATUS_TOUT)
	 ||(s_Med_ErrorInfo.CanPduStatus.GW_20B_PduSts == E_MSG_STATUS_TOUT)
	 ||(s_Med_ErrorInfo.CanPduStatus.GW_2C2_PduSts == E_MSG_STATUS_TOUT)
	 ||(s_Med_ErrorInfo.CanPduStatus.GW_278_PduSts == E_MSG_STATUS_TOUT))
	 
	{
		b_RetVal = TRUE;
	}
	else
	{
		b_RetVal = FALSE;
	}
	
	return b_RetVal;
}

/**
 * \functions Med_TestFailed_CAN_PduStatus_EPS_NodeMissing
 *
 * \brief   
 *
 ** \param[in] none,
 *
 ** \param[out] none,
 *
 ** \return RTE_E_OK, 
 * \comments
 * DTC confirm Condition:
 * Any of EPS node messages(0x170, 0x180,0x17E,0x24F) is missing for 100ms(0x170, 0x180,0x17E) or 200ms(0x24F).  
 */
FUNC(boolean, RTE_CODE) Med_TestFailed_CAN_PduStatus_EPS_NodeMissing(void)
{
    boolean b_RetVal = FALSE;
	
	if((s_Med_ErrorInfo.CanPduStatus.GW_170_PduSts == E_MSG_STATUS_TOUT)
	 ||(s_Med_ErrorInfo.CanPduStatus.GW_180_PduSts == E_MSG_STATUS_TOUT)
	 ||(s_Med_ErrorInfo.CanPduStatus.GW_17E_PduSts == E_MSG_STATUS_TOUT)
	 ||(s_Med_ErrorInfo.CanPduStatus.GW_24F_PduSts == E_MSG_STATUS_TOUT))
	 
	{
		b_RetVal = TRUE;
	}
	else
	{
		b_RetVal = FALSE;
	}
	
	return b_RetVal;
}

/**
 * \functions Med_TestFailed_CAN_PduStatus_BCM_NodeMissing
 *
 * \brief   
 *
 ** \param[in] none,
 *
 ** \param[out] none,
 *
 ** \return RTE_E_OK, 
 * \comments
 * DTC confirm Condition:
 * Any of BCM node messges(0x288) is missing for 1s.  
 */
FUNC(boolean, RTE_CODE) Med_TestFailed_CAN_PduStatus_BCM_NodeMissing(void)
{
	boolean b_RetVal = FALSE;
	 
	 if(s_Med_ErrorInfo.CanPduStatus.GW_288_PduSts == E_MSG_STATUS_TOUT)
	 {
		 b_RetVal = TRUE;
	 }
	 else
	 {
		 b_RetVal = FALSE;
	 }
	 
	 return b_RetVal;
}

/**
 * \functions Med_TestFailed_CAN_PduStatus_IP_NodeMissing
 *
 * \brief   
 *
 ** \param[in] none,
 *
 ** \param[out] none,
 *
 ** \return RTE_E_OK, 
 * \comments
 * DTC confirm Condition:
 * Any of IP node messges(0x2DE) is missing for 1s. 
 */
FUNC(boolean, RTE_CODE) Med_TestFailed_CAN_PduStatus_IP_NodeMissing(void)
{
	boolean b_RetVal = FALSE;
	 
    if(s_Med_ErrorInfo.CanPduStatus.GW_2DE_PduSts == E_MSG_STATUS_TOUT)
	{
		b_RetVal = TRUE;
	}
	else
	{
		b_RetVal = FALSE;
	}
	 
	return b_RetVal;
}

/**
 * \functions Med_TestFailed_CAN_PduStatus_RLR_AliveCounterError
 *
 * \brief   
 *
 ** \param[in] none,
 *
 ** \param[out] none,
 *
 ** \return RTE_E_OK, 
 * \comments
 * DTC confirm Condition:
 * RLR any message(345,346) alive counter failure(the delta counter is equal to 0 or greather than 2) qualification time is 1s.  OR
 * RLR any message(345,346) CRC failure qualification time is 1s. The period time of 0x345,346 is 50ms.  
 */
FUNC(boolean, RTE_CODE) Med_TestFailed_CAN_PduStatus_RLR_AliveCounterError(void)
{
	boolean b_RetVal = FALSE;
	 
    if((s_Med_ErrorInfo.CanPduStatus.ADC_345_PduSts == E_MSG_STATUS_ROLLINGCNT)
		||(s_Med_ErrorInfo.CanPduStatus.ADC_345_PduSts == E_MSG_STATUS_CRC)
		||(s_Med_ErrorInfo.CanPduStatus.ADC_345_PduSts == E_MSG_STATUS_CRC_AND_ROLLINGCNT)
		||(s_Med_ErrorInfo.CanPduStatus.ADC_346_PduSts == E_MSG_STATUS_ROLLINGCNT)
		||(s_Med_ErrorInfo.CanPduStatus.ADC_346_PduSts == E_MSG_STATUS_CRC)
		||(s_Med_ErrorInfo.CanPduStatus.ADC_346_PduSts == E_MSG_STATUS_CRC_AND_ROLLINGCNT)
	)
	{
		b_RetVal = TRUE;
	}
	else
	{
		b_RetVal = FALSE;
	}
	 
	return b_RetVal;

}


/**
 * \functions Med_TestFailed_CAN_PduStatus_VCU_AliveCounterError
 *
 * \brief   
 *
 ** \param[in] none,
 *
 ** \param[out] none,
 *
 ** \return RTE_E_OK, 
 * \comments
 * DTC confirm Condition:
 * VCU any message(161)alive counter failure(the delta counter is equal to 0 or greather than 2) qualification time is 100ms.  OR
 * VCU any message(161)CRC failure qualification time is 100ms.  
 */
FUNC(boolean, RTE_CODE) Med_TestFailed_CAN_PduStatus_VCU_AliveCounterError(void)
{
	boolean b_RetVal = FALSE;
	 
    if((s_Med_ErrorInfo.CanPduStatus.VCU_161_PduSts == E_MSG_STATUS_ROLLINGCNT)
		||(s_Med_ErrorInfo.CanPduStatus.VCU_161_PduSts == E_MSG_STATUS_CRC)
		||(s_Med_ErrorInfo.CanPduStatus.VCU_161_PduSts == E_MSG_STATUS_CRC_AND_ROLLINGCNT))
	{
		b_RetVal = TRUE;
	}
	else
	{
		b_RetVal = FALSE;
	}
	 
	return b_RetVal;
}

/**
 * \functions Med_TestFailed_CAN_PduStatus_ESP_AliveCounterError
 *
 * \brief   
 *
 ** \param[in] none,
 *
 ** \param[out] none,
 *
 ** \return RTE_E_OK, 
 * \comments
 * DTC confirm Condition:
 *ESP any message(17A, 1C2, 2C2, 3C2, 278, 20B)alive counter failure(the delta counter is equal to 0 or greather than 2) qualification time is 100ms(17A, 1C2, 2C2, 278, 20B) or 1s(3C2) .  OR
* ESP any message(17A, 1C2, 2C2, 3C2, 278, 20B)CRC failure qualification time is 100ms(17A, 1C2, 2C2, 278, 20B) or 1s(3C2). 
 */
FUNC(boolean, RTE_CODE) Med_TestFailed_CAN_PduStatus_ESP_AliveCounterError(void)
{
	boolean b_RetVal = FALSE;
	 
    if((s_Med_ErrorInfo.CanPduStatus.GW_17A_PduSts == E_MSG_STATUS_ROLLINGCNT)
		||(s_Med_ErrorInfo.CanPduStatus.GW_17A_PduSts == E_MSG_STATUS_CRC)
		||(s_Med_ErrorInfo.CanPduStatus.GW_17A_PduSts == E_MSG_STATUS_CRC_AND_ROLLINGCNT)
		||(s_Med_ErrorInfo.CanPduStatus.GW_1C2_PduSts == E_MSG_STATUS_ROLLINGCNT)
		||(s_Med_ErrorInfo.CanPduStatus.GW_1C2_PduSts == E_MSG_STATUS_CRC)
		||(s_Med_ErrorInfo.CanPduStatus.GW_1C2_PduSts == E_MSG_STATUS_CRC_AND_ROLLINGCNT)
		||(s_Med_ErrorInfo.CanPduStatus.GW_2C2_PduSts == E_MSG_STATUS_ROLLINGCNT)
		||(s_Med_ErrorInfo.CanPduStatus.GW_2C2_PduSts == E_MSG_STATUS_CRC)
		||(s_Med_ErrorInfo.CanPduStatus.GW_2C2_PduSts == E_MSG_STATUS_CRC_AND_ROLLINGCNT)
		||(s_Med_ErrorInfo.CanPduStatus.GW_278_PduSts == E_MSG_STATUS_ROLLINGCNT)
		||(s_Med_ErrorInfo.CanPduStatus.GW_278_PduSts == E_MSG_STATUS_CRC)
		||(s_Med_ErrorInfo.CanPduStatus.GW_278_PduSts == E_MSG_STATUS_CRC_AND_ROLLINGCNT)
		||(s_Med_ErrorInfo.CanPduStatus.GW_20B_PduSts == E_MSG_STATUS_ROLLINGCNT)
		||(s_Med_ErrorInfo.CanPduStatus.GW_20B_PduSts == E_MSG_STATUS_CRC)
		||(s_Med_ErrorInfo.CanPduStatus.GW_20B_PduSts == E_MSG_STATUS_CRC_AND_ROLLINGCNT)
	)
	{
		b_RetVal = TRUE;
	}
	else
	{
		b_RetVal = FALSE;
	}
	 
	return b_RetVal;

}

/**
 * \functions Med_TestFailed_CAN_PduStatus_ESP_AliveCounterError_100ms
 *
 * \brief   this function only use to check 1s(3C2).
 *
 ** \param[in] none,
 *
 ** \param[out] none,
 *
 ** \return RTE_E_OK, 
 * \comments
 * DTC confirm Condition:
 *ESP any message(17A, 1C2, 2C2, 3C2, 278, 20B)alive counter failure(the delta counter is equal to 0 or greather than 2) qualification time is 100ms(17A, 1C2, 2C2, 278, 20B) or 1s(3C2) .  OR
* ESP any message(17A, 1C2, 2C2, 3C2, 278, 20B)CRC failure qualification time is 100ms(17A, 1C2, 2C2, 278, 20B) or 1s(3C2). 
 */
FUNC(boolean, RTE_CODE) Med_TestFailed_CAN_PduStatus_ESP_AliveCounterError_100ms(void)
{
	boolean b_RetVal = FALSE;
	 
    if((s_Med_ErrorInfo.CanPduStatus.GW_3C2_PduSts == E_MSG_STATUS_ROLLINGCNT)
     ||(s_Med_ErrorInfo.CanPduStatus.GW_3C2_PduSts == E_MSG_STATUS_CRC)
     ||(s_Med_ErrorInfo.CanPduStatus.GW_3C2_PduSts == E_MSG_STATUS_CRC_AND_ROLLINGCNT)
	)
	{
		b_RetVal = TRUE;
	}
	else
	{
		b_RetVal = FALSE;
	}
	 
	return b_RetVal;
}

/**
 * \functions Med_TestFailed_CAN_PduStatus_FR_AliveCounterError
 *
 * \brief   
 *
 ** \param[in] none,
 *
 ** \param[out] none,
 *
 ** \return RTE_E_OK, 
 * \comments
 * DTC confirm Condition:
 * FR any message(111-120, 136)alive counter failure(the delta counter is equal to 0 or greather than 2) qualification time is 1s.  OR
 * FR any message(111-120, 136)CRC failure qualification time is 1s. The period time of 0x136 is 50ms，The period time of 111-120 is 70ms.
 */
FUNC(boolean, RTE_CODE) Med_TestFailed_CAN_PduStatus_FR_AliveCounterError(void)
{
	boolean b_RetVal = FALSE;
	 
    if((s_Med_ErrorInfo.CanPduStatus.FR_111_PduSts == E_MSG_STATUS_ROLLINGCNT)
     ||(s_Med_ErrorInfo.CanPduStatus.FR_111_PduSts == E_MSG_STATUS_CRC)
     ||(s_Med_ErrorInfo.CanPduStatus.FR_111_PduSts == E_MSG_STATUS_CRC_AND_ROLLINGCNT)
     ||(s_Med_ErrorInfo.CanPduStatus.FR_112_PduSts == E_MSG_STATUS_ROLLINGCNT)
     ||(s_Med_ErrorInfo.CanPduStatus.FR_112_PduSts == E_MSG_STATUS_CRC)
     ||(s_Med_ErrorInfo.CanPduStatus.FR_112_PduSts == E_MSG_STATUS_CRC_AND_ROLLINGCNT)
     ||(s_Med_ErrorInfo.CanPduStatus.FR_113_PduSts == E_MSG_STATUS_ROLLINGCNT)
     ||(s_Med_ErrorInfo.CanPduStatus.FR_113_PduSts == E_MSG_STATUS_CRC)
     ||(s_Med_ErrorInfo.CanPduStatus.FR_113_PduSts == E_MSG_STATUS_CRC_AND_ROLLINGCNT)
     ||(s_Med_ErrorInfo.CanPduStatus.FR_114_PduSts == E_MSG_STATUS_ROLLINGCNT)
     ||(s_Med_ErrorInfo.CanPduStatus.FR_114_PduSts == E_MSG_STATUS_CRC)
     ||(s_Med_ErrorInfo.CanPduStatus.FR_114_PduSts == E_MSG_STATUS_CRC_AND_ROLLINGCNT)
     ||(s_Med_ErrorInfo.CanPduStatus.FR_115_PduSts == E_MSG_STATUS_ROLLINGCNT)
     ||(s_Med_ErrorInfo.CanPduStatus.FR_115_PduSts == E_MSG_STATUS_CRC)
     ||(s_Med_ErrorInfo.CanPduStatus.FR_115_PduSts == E_MSG_STATUS_CRC_AND_ROLLINGCNT)
     ||(s_Med_ErrorInfo.CanPduStatus.FR_116_PduSts == E_MSG_STATUS_ROLLINGCNT)
     ||(s_Med_ErrorInfo.CanPduStatus.FR_116_PduSts == E_MSG_STATUS_CRC)
     ||(s_Med_ErrorInfo.CanPduStatus.FR_116_PduSts == E_MSG_STATUS_CRC_AND_ROLLINGCNT)
     ||(s_Med_ErrorInfo.CanPduStatus.FR_117_PduSts == E_MSG_STATUS_ROLLINGCNT)
     ||(s_Med_ErrorInfo.CanPduStatus.FR_117_PduSts == E_MSG_STATUS_CRC)
     ||(s_Med_ErrorInfo.CanPduStatus.FR_117_PduSts == E_MSG_STATUS_CRC_AND_ROLLINGCNT)
     ||(s_Med_ErrorInfo.CanPduStatus.FR_118_PduSts == E_MSG_STATUS_ROLLINGCNT)
     ||(s_Med_ErrorInfo.CanPduStatus.FR_118_PduSts == E_MSG_STATUS_CRC)
     ||(s_Med_ErrorInfo.CanPduStatus.FR_118_PduSts == E_MSG_STATUS_CRC_AND_ROLLINGCNT)
     ||(s_Med_ErrorInfo.CanPduStatus.FR_119_PduSts == E_MSG_STATUS_ROLLINGCNT)
     ||(s_Med_ErrorInfo.CanPduStatus.FR_119_PduSts == E_MSG_STATUS_CRC)
     ||(s_Med_ErrorInfo.CanPduStatus.FR_119_PduSts == E_MSG_STATUS_CRC_AND_ROLLINGCNT)
     ||(s_Med_ErrorInfo.CanPduStatus.FR_11A_PduSts == E_MSG_STATUS_ROLLINGCNT)
     ||(s_Med_ErrorInfo.CanPduStatus.FR_11A_PduSts == E_MSG_STATUS_CRC)
     ||(s_Med_ErrorInfo.CanPduStatus.FR_11A_PduSts == E_MSG_STATUS_CRC_AND_ROLLINGCNT)
     ||(s_Med_ErrorInfo.CanPduStatus.FR_11B_PduSts == E_MSG_STATUS_ROLLINGCNT)
     ||(s_Med_ErrorInfo.CanPduStatus.FR_11B_PduSts == E_MSG_STATUS_CRC)
     ||(s_Med_ErrorInfo.CanPduStatus.FR_11B_PduSts == E_MSG_STATUS_CRC_AND_ROLLINGCNT)
     ||(s_Med_ErrorInfo.CanPduStatus.FR_11C_PduSts == E_MSG_STATUS_ROLLINGCNT)
     ||(s_Med_ErrorInfo.CanPduStatus.FR_11C_PduSts == E_MSG_STATUS_CRC)
     ||(s_Med_ErrorInfo.CanPduStatus.FR_11C_PduSts == E_MSG_STATUS_CRC_AND_ROLLINGCNT)
     ||(s_Med_ErrorInfo.CanPduStatus.FR_11D_PduSts == E_MSG_STATUS_ROLLINGCNT)
     ||(s_Med_ErrorInfo.CanPduStatus.FR_11D_PduSts == E_MSG_STATUS_CRC)
     ||(s_Med_ErrorInfo.CanPduStatus.FR_11D_PduSts == E_MSG_STATUS_CRC_AND_ROLLINGCNT)
     ||(s_Med_ErrorInfo.CanPduStatus.FR_11E_PduSts == E_MSG_STATUS_ROLLINGCNT)
     ||(s_Med_ErrorInfo.CanPduStatus.FR_11E_PduSts == E_MSG_STATUS_CRC)
     ||(s_Med_ErrorInfo.CanPduStatus.FR_11E_PduSts == E_MSG_STATUS_CRC_AND_ROLLINGCNT)
     ||(s_Med_ErrorInfo.CanPduStatus.FR_11F_PduSts == E_MSG_STATUS_ROLLINGCNT)
     ||(s_Med_ErrorInfo.CanPduStatus.FR_11F_PduSts == E_MSG_STATUS_CRC)
     ||(s_Med_ErrorInfo.CanPduStatus.FR_11F_PduSts == E_MSG_STATUS_CRC_AND_ROLLINGCNT)  
     ||(s_Med_ErrorInfo.CanPduStatus.FR_120_PduSts == E_MSG_STATUS_ROLLINGCNT)
     ||(s_Med_ErrorInfo.CanPduStatus.FR_120_PduSts == E_MSG_STATUS_CRC)
     ||(s_Med_ErrorInfo.CanPduStatus.FR_120_PduSts == E_MSG_STATUS_CRC_AND_ROLLINGCNT)
     ||(s_Med_ErrorInfo.CanPduStatus.FR_136_PduSts == E_MSG_STATUS_ROLLINGCNT)
     ||(s_Med_ErrorInfo.CanPduStatus.FR_136_PduSts == E_MSG_STATUS_CRC)
     ||(s_Med_ErrorInfo.CanPduStatus.FR_136_PduSts == E_MSG_STATUS_CRC_AND_ROLLINGCNT)
	)
	{
		b_RetVal = TRUE;
	}
	else
	{
		b_RetVal = FALSE;
	}
	 
	return b_RetVal;

}


/**
 * \functions Med_TestFailed_CAN_PduStatus_BCM_AliveCounterError
 *
 * \brief   
 *
 ** \param[in] none,
 *
 ** \param[out] none,
 *
 ** \return RTE_E_OK, 
 * \comments
 * DTC confirm Condition:
 * BCM any message(288, 28B)alive counter failure(the delta counter is equal to 0 or greather than 2) qualification time is 1s.  OR
 * BCM any message(288, 28B)CRC failure qualification time is 1s.
 */
FUNC(boolean, RTE_CODE) Med_TestFailed_CAN_PduStatus_BCM_AliveCounterError(void)
{
	boolean b_RetVal = FALSE;
	 
    if((s_Med_ErrorInfo.CanPduStatus.GW_288_PduSts == E_MSG_STATUS_ROLLINGCNT)
     ||(s_Med_ErrorInfo.CanPduStatus.GW_288_PduSts == E_MSG_STATUS_CRC)
     ||(s_Med_ErrorInfo.CanPduStatus.GW_288_PduSts == E_MSG_STATUS_CRC_AND_ROLLINGCNT)
     ||(s_Med_ErrorInfo.CanPduStatus.GW_28B_PduSts == E_MSG_STATUS_ROLLINGCNT)
     ||(s_Med_ErrorInfo.CanPduStatus.GW_28B_PduSts == E_MSG_STATUS_CRC)
     ||(s_Med_ErrorInfo.CanPduStatus.GW_28B_PduSts == E_MSG_STATUS_CRC_AND_ROLLINGCNT)
	)
	{
		b_RetVal = TRUE;
	}
	else
	{
		b_RetVal = FALSE;
	}
	 
	return b_RetVal;
}

/**
 * \functions Med_TestFailed_CAN_PduStatus_IP_AliveCounterError
 *
 * \brief   
 *
 ** \param[in] none,
 *
 ** \param[out] none,
 *
 ** \return RTE_E_OK, 
 * \comments
 * DTC confirm Condition:
 * IP any message(2DE)alive counter failure(the delta counter is equal to 0 or greather than 2) qualification time is 1s.  OR
 * IP any message(2DE)CRC failure qualification time is 1s. The cycle time of 2DE is 50ms.
 */
FUNC(boolean, RTE_CODE) Med_TestFailed_CAN_PduStatus_IP_AliveCounterError(void)
{
	boolean b_RetVal = FALSE;
	 
    if((s_Med_ErrorInfo.CanPduStatus.GW_2DE_PduSts== E_MSG_STATUS_ROLLINGCNT)
     ||(s_Med_ErrorInfo.CanPduStatus.GW_2DE_PduSts == E_MSG_STATUS_CRC)
     ||(s_Med_ErrorInfo.CanPduStatus.GW_2DE_PduSts == E_MSG_STATUS_CRC_AND_ROLLINGCNT)
	)
	{
		b_RetVal = TRUE;
	}
	else
	{
		b_RetVal = FALSE;
	}
	 
	return b_RetVal;
}

/**
 * \functions Med_TestFailed_CAN_PduStatus_EPS_AliveCounterError_10ms
 *
 * \brief   
 *
 ** \param[in] none,
 *
 ** \param[out] none,
 *
 ** \return RTE_E_OK, 
 * \comments
 * DTC confirm Condition:
 * EPS any message(170, 17E, 24F, 180)alive counter failure(the delta counter is equal to 0 or greather than 2) qualification time is 100ms(170, 17E, 180)  or 200ms(24F).  OR
 * EPS any message(170, 17E, 24F, 180)CRC failure qualification time is 100ms(170, 17E, 180) or 200ms(24F). 
 */
FUNC(boolean, RTE_CODE) Med_TestFailed_CAN_PduStatus_EPS_AliveCounterError_10ms(void)
{
	boolean b_RetVal = FALSE;
	 
    if((s_Med_ErrorInfo.CanPduStatus.GW_170_PduSts == E_MSG_STATUS_ROLLINGCNT)
     ||(s_Med_ErrorInfo.CanPduStatus.GW_170_PduSts == E_MSG_STATUS_CRC)
     ||(s_Med_ErrorInfo.CanPduStatus.GW_170_PduSts == E_MSG_STATUS_CRC_AND_ROLLINGCNT)
     ||(s_Med_ErrorInfo.CanPduStatus.GW_17E_PduSts == E_MSG_STATUS_ROLLINGCNT)
     ||(s_Med_ErrorInfo.CanPduStatus.GW_17E_PduSts == E_MSG_STATUS_CRC)
     ||(s_Med_ErrorInfo.CanPduStatus.GW_17E_PduSts == E_MSG_STATUS_CRC_AND_ROLLINGCNT)
     ||(s_Med_ErrorInfo.CanPduStatus.GW_180_PduSts == E_MSG_STATUS_ROLLINGCNT)
     ||(s_Med_ErrorInfo.CanPduStatus.GW_180_PduSts == E_MSG_STATUS_CRC)
     ||(s_Med_ErrorInfo.CanPduStatus.GW_180_PduSts == E_MSG_STATUS_CRC_AND_ROLLINGCNT)
	)
	{
		b_RetVal = TRUE;
	}
	else
	{
		b_RetVal = FALSE;
	}
	 
	return b_RetVal;
}

/**
 * \functions Med_TestFailed_CAN_PduStatus_EPS_AliveCounterError_20ms
 *
 * \brief   
 *
 ** \param[in] none,
 *
 ** \param[out] none,
 *
 ** \return RTE_E_OK, 
 * \comments
 * DTC confirm Condition:
 * EPS any message(170, 17E, 24F, 180)alive counter failure(the delta counter is equal to 0 or greather than 2) qualification time is 100ms(170, 17E, 180)  or 200ms(24F).  OR
 * EPS any message(170, 17E, 24F, 180)CRC failure qualification time is 100ms(170, 17E, 180) or 200ms(24F). 
 */
FUNC(boolean, RTE_CODE) Med_TestFailed_CAN_PduStatus_EPS_AliveCounterError_20ms(void)
{
	boolean b_RetVal = FALSE;
	 
    if((s_Med_ErrorInfo.CanPduStatus.GW_24F_PduSts == E_MSG_STATUS_ROLLINGCNT)
     ||(s_Med_ErrorInfo.CanPduStatus.GW_24F_PduSts == E_MSG_STATUS_CRC)
     ||(s_Med_ErrorInfo.CanPduStatus.GW_24F_PduSts == E_MSG_STATUS_CRC_AND_ROLLINGCNT)
	)
	{
		b_RetVal = TRUE;
	}
	else
	{
		b_RetVal = FALSE;
	}
	 
	return b_RetVal;
}

/**
 * \functions Med_TestFailed_CAN_PduStatus_ADC_AliveCounterError
 *
 * \brief   
 *
 ** \param[in] none,
 *
 ** \param[out] none,
 *
 ** \return RTE_E_OK, 
 * \comments
 * DTC confirm Condition:
 * ADC any message(19B) alive counter failure(the delta counter is equal to 0 or greather than 2) qualification time is 1s.  OR
 * ADC any message(19B) CRC failure qualification time is 1s. The period time of 0x19B is 100ms.
 */
FUNC(boolean, RTE_CODE) Med_TestFailed_CAN_PduStatus_ADC_AliveCounterError(void)
{
	boolean b_RetVal = FALSE;
	 
    if((s_Med_ErrorInfo.CanPduStatus.ADC_19B_PduSts == E_MSG_STATUS_ROLLINGCNT)
     ||(s_Med_ErrorInfo.CanPduStatus.ADC_19B_PduSts == E_MSG_STATUS_CRC)
     ||(s_Med_ErrorInfo.CanPduStatus.ADC_19B_PduSts == E_MSG_STATUS_CRC_AND_ROLLINGCNT)
	)
	{
		b_RetVal = TRUE;
	}
	else
	{
		b_RetVal = FALSE;
	}
	 
	return b_RetVal;
}

/**
 * \functions Med_TestFailed_CAN_PduStatus_SRS_AliveCounterError
 *
 * \brief   
 *
 ** \param[in] none,
 *
 ** \param[out] none,
 *
 ** \return RTE_E_OK, 
 * \comments
 * DTC confirm Condition:
 * SRS any message(50) alive counter failure(the delta counter is equal to 0 or greather than 2) qualification time is 1s.  OR
 * SRS any message(50) CRC failure qualification time is 1s. The period time of 0x050 is 500ms
 */
FUNC(boolean, RTE_CODE) Med_TestFailed_CAN_PduStatus_SRS_AliveCounterError(void)
{
	boolean b_RetVal = FALSE;

    if((s_Med_ErrorInfo.CanPduStatus.GW_50_PduSts == E_MSG_STATUS_ROLLINGCNT)
     ||(s_Med_ErrorInfo.CanPduStatus.GW_50_PduSts == E_MSG_STATUS_CRC)
     ||(s_Med_ErrorInfo.CanPduStatus.GW_50_PduSts == E_MSG_STATUS_CRC_AND_ROLLINGCNT)
	)
	{
		b_RetVal = TRUE;
	}
	else
	{
		b_RetVal = FALSE;
	}
	 
	return b_RetVal;
}

/**
 * \functions Med_EnableCondition_Group_PVPU
 *
 * \brief   
 *
 ** \param[in] none,
 *
 ** \param[out] none,
 *
 ** \return RTE_E_OK, 
 * \comments
 * Preondition:
 * (1) Voltage supply of CAN Bus mode is in the range of 8.5V-16.5V.
 * (2) IGN is ON state after 3s 
 * (3) No BUS OFF or recover from BUS OFF at least 1s.
 * (4) .BcmPwrStsFb=0x2:ON
 */
FUNC(boolean, RTE_CODE) Med_EnableCondition_Group_PVPU(void)
{
	boolean b_RetVal = FALSE;
	
	if((s_Med_ErrorInfo.EnableCondition.Poweron3000ms == MED_EC_ACTIVE) 
	&& (s_Med_ErrorInfo.EnableCondition.VoltageNormal == MED_EC_ACTIVE)
	&& (s_Med_ErrorInfo.EnableCondition.BCMPowerModeState == MED_EC_ACTIVE)
	&& (s_Med_ErrorInfo.EnableCondition.NoBusOffPublicCAN == MED_EC_ACTIVE))
	{
		b_RetVal = TRUE; /* Satisfy Preconditions */
	}
	else
	{
		b_RetVal = FALSE; /* NOT Satisfy Preconditions, NO DTC */
	}
	return b_RetVal;
}

/**
 * \functions Med_EnableCondition_Group_BCM
 *
 * \brief   
 *
 ** \param[in] none,
 *
 ** \param[out] none,
 *
 ** \return RTE_E_OK, 
 * \comments
 * Preondition:
 * (1) Voltage supply of CAN Bus mode is in the range of 8.5V-16.5V.
 * (2) IGN is ON state after 3s 
 * (3) No BUS OFF or recover from BUS OFF at least 1s in public can.
 */
FUNC(boolean, RTE_CODE) Med_EnableCondition_Group_BCM(void)
{
	boolean b_RetVal = FALSE;
	
	if((s_Med_ErrorInfo.EnableCondition.Poweron3000ms == MED_EC_ACTIVE) 
	&& (s_Med_ErrorInfo.EnableCondition.VoltageNormal == MED_EC_ACTIVE)
	&& (s_Med_ErrorInfo.EnableCondition.NoBusOffPublicCAN == MED_EC_ACTIVE))
	{
		b_RetVal = TRUE; /* Satisfy Preconditions */
	}
	else
	{
		b_RetVal = FALSE; /* NOT Satisfy Preconditions, NO DTC */
	}
	return b_RetVal;
}

/**
 * \functions Med_EnableCondition_Group_PVPR
 *
 * \brief   
 *
 ** \param[in] none,
 *
 ** \param[out] none,
 *
 ** \return RTE_E_OK, 
 * \comments
 * Preondition:
 * (1) Voltage supply of CAN Bus mode is in the range of 8.5V-16.5V.
 * (2) IGN is ON state after 3s 
 * (3) No BUS OFF or recover from BUS OFF at least 1s in praivate can.
 * (4) BcmPwrStsFb=0x2:ON
 */
FUNC(boolean, RTE_CODE) Med_EnableCondition_Group_PVPR(void)
{
	boolean b_RetVal = FALSE;
	if((s_Med_ErrorInfo.EnableCondition.Poweron3000ms == MED_EC_ACTIVE) 
	&& (s_Med_ErrorInfo.EnableCondition.VoltageNormal == MED_EC_ACTIVE)
	&& (s_Med_ErrorInfo.EnableCondition.BCMPowerModeState == MED_EC_ACTIVE)
	&& (s_Med_ErrorInfo.EnableCondition.NoBusOffPrivateCAN == MED_EC_ACTIVE))
	{
		b_RetVal = TRUE; /* Satisfy Preconditions */
	}
	else
	{
		b_RetVal = FALSE; /* NOT Satisfy Preconditions, NO DTC */
	}
	return b_RetVal;
}

/**
 * \functions Med_EnableCondition_Group_PowerOn3000ms
 *
 * \brief   
 *
 ** \param[in] none,
 *
 ** \param[out] none,
 *
 ** \return RTE_E_OK, 
 * \comments
 * Preondition:
 * (1) IGN is ON state after 3s 
 */
boolean Med_EnableCondition_Group_PowerOn3000ms(void)
{
	boolean b_RetVal = FALSE;

	if(s_Med_ErrorInfo.EnableCondition.Poweron3000ms == MED_EC_ACTIVE)
	{
		b_RetVal = TRUE; /* Satisfy Preconditions */
	}
	else
	{
		b_RetVal = FALSE; /* NOT Satisfy Preconditions, NO DTC */
	}
	return b_RetVal;
}

/**
 * \functions Med_EnableCondition_Group_PV
 *
 * \brief   
 *
 ** \param[in] none,
 *
 ** \param[out] none,
 *
 ** \return RTE_E_OK, 
 * \comments
 * Preondition:
 * (1) Voltage supply of CAN Bus mode is in the range of 8.5V-16.5V.
 * (2) IGN is ON state after 3s 
 */
boolean Med_EnableCondition_Group_PV(void)
{
	boolean b_RetVal = FALSE;

	if((s_Med_ErrorInfo.EnableCondition.Poweron3000ms == MED_EC_ACTIVE) 
	&& (s_Med_ErrorInfo.EnableCondition.VoltageNormal == MED_EC_ACTIVE))
	{
		b_RetVal = TRUE; /* Satisfy Preconditions */
	}
	else
	{
		b_RetVal = FALSE; /* NOT Satisfy Preconditions, NO DTC */
	}
	return b_RetVal;
}

/**
 * \functions Med_EnableCondition_Group_PVPUvcu
 *
 * \brief   
 *
 ** \param[in] none,
 *
 ** \param[out] none,
 *
 ** \return RTE_E_OK, 
 * \comments
 * Preondition:
 * (1) Voltage supply of CAN Bus mode is in the range of 8.5V-16.5V.
 * (2) IGN is ON state after 3s 
 * (3) No BUS OFF or recover from BUS OFF at least 1s in public can.
 * (4) BcmPwrStsFb=0x2:ON
 * (5) Timeout, crc and alive couter DTC are not reported.
 */
FUNC(boolean, RTE_CODE) Med_EnableCondition_Group_PVPUvcu(void)
{
	boolean b_RetVal = FALSE;
	
	if((s_Med_ErrorInfo.EnableCondition.Poweron3000ms == MED_EC_ACTIVE) 
	&& (s_Med_ErrorInfo.EnableCondition.VoltageNormal == MED_EC_ACTIVE)
	&& (s_Med_ErrorInfo.EnableCondition.NoBusOffPublicCAN == MED_EC_ACTIVE)
	&& (s_Med_ErrorInfo.EnableCondition.BCMPowerModeState == MED_EC_ACTIVE)
	&& (s_Med_ParentDTC.VCU_161.timeout == MED_EC_INACTIVE) 
	&& (s_Med_ParentDTC.VCU_161.crc == MED_EC_INACTIVE)
	&& (s_Med_ParentDTC.VCU_161.rc == MED_EC_INACTIVE))
	{
		b_RetVal = TRUE; /* Satisfy Preconditions */
	}
	else
	{
		b_RetVal = FALSE; /* NOT Satisfy Preconditions, NO DTC */
	}
	return b_RetVal;
}

/**
 * \functions Med_EnableCondition_Group_PVPU
 *
 * \brief   
 *
 ** \param[in] none,
 *
 ** \param[out] none,
 *
 ** \return RTE_E_OK, 
 * \comments
 * Preondition:
 * (1) Voltage supply of CAN Bus mode is in the range of 8.5V-16.5V.
 * (2) IGN is ON state after 3s 
 * (3) No BUS OFF or recover from BUS OFF at least 1s in public can.
 * (4) BcmPwrStsFb=0x2:ON
 * (5) timeout, crc and alive couter DTC are not reported.
 */
FUNC(boolean, RTE_CODE) Med_EnableCondition_Group_PVPUesp(void)
{
	boolean b_RetVal = FALSE;
	
	if((s_Med_ErrorInfo.EnableCondition.Poweron3000ms == MED_EC_ACTIVE) 
	&& (s_Med_ErrorInfo.EnableCondition.VoltageNormal == MED_EC_ACTIVE)
	&& (s_Med_ErrorInfo.EnableCondition.NoBusOffPublicCAN == MED_EC_ACTIVE)
	&& (s_Med_ErrorInfo.EnableCondition.BCMPowerModeState == MED_EC_ACTIVE)
	&& (s_Med_ParentDTC.GW_17A.timeout == MED_EC_INACTIVE) 
	&& (s_Med_ParentDTC.GW_17A.crc == MED_EC_INACTIVE)
	&& (s_Med_ParentDTC.GW_17A.rc == MED_EC_INACTIVE))
	{
		b_RetVal = TRUE; /* Satisfy Preconditions */
	}
	else
	{
		b_RetVal = FALSE; /* NOT Satisfy Preconditions, NO DTC */
	}
	return b_RetVal;
}

/**
 * \functions Med_EnableCondition_Group_PVPUeps
 *
 * \brief   
 *
 ** \param[in] none,
 *
 ** \param[out] none,
 *
 ** \return RTE_E_OK, 
 * \comments
 * Preondition:
 * (1) Voltage supply of CAN Bus mode is in the range of 8.5V-16.5V.
 * (2) IGN is ON state after 3s 
 * (3) No BUS OFF or recover from BUS OFF at least 1s in public can.
 * (4) BcmPwrStsFb=0x2:ON
 * (5) timeout, crc and alive couter DTC are not reported.
 */
FUNC(boolean, RTE_CODE) Med_EnableCondition_Group_PVPUeps(void)
{
	boolean b_RetVal = FALSE;
	
	if((s_Med_ErrorInfo.EnableCondition.Poweron3000ms == MED_EC_ACTIVE) 
	&& (s_Med_ErrorInfo.EnableCondition.VoltageNormal == MED_EC_ACTIVE)
	&& (s_Med_ErrorInfo.EnableCondition.NoBusOffPublicCAN == MED_EC_ACTIVE)
	&& (s_Med_ErrorInfo.EnableCondition.BCMPowerModeState == MED_EC_ACTIVE)
	&& (s_Med_ParentDTC.GW_170.timeout == MED_EC_INACTIVE) 
	&& (s_Med_ParentDTC.GW_170.crc == MED_EC_INACTIVE)
	&& (s_Med_ParentDTC.GW_170.rc == MED_EC_INACTIVE))
	{
		b_RetVal = TRUE; /* Satisfy Preconditions */
	}
	else
	{
		b_RetVal = FALSE; /* NOT Satisfy Preconditions, NO DTC */
	}
	return b_RetVal;
}

/**
 * \functions Med_EnableCondition_Group_PVPUbcm
 *
 * \brief   
 *
 ** \param[in] none,
 *
 ** \param[out] none,
 *
 ** \return RTE_E_OK, 
 * \comments
 * Preondition:
 * (1) Voltage supply of CAN Bus mode is in the range of 8.5V-16.5V.
 * (2) IGN is ON state after 3s 
 * (3) No BUS OFF or recover from BUS OFF at least 1s.
 * (4) BcmPwrStsFb=0x2:ON
 * (5) timeout, crc and alive couter DTC are not reported.
 */
FUNC(boolean, RTE_CODE) Med_EnableCondition_Group_PVPUbcm(void)
{
	boolean b_RetVal = FALSE;
	
	if((s_Med_ErrorInfo.EnableCondition.Poweron3000ms == MED_EC_ACTIVE) 
	&& (s_Med_ErrorInfo.EnableCondition.VoltageNormal == MED_EC_ACTIVE)
	&& (s_Med_ErrorInfo.EnableCondition.NoBusOffPublicCAN == MED_EC_ACTIVE)
	&& (s_Med_ErrorInfo.EnableCondition.BCMPowerModeState == MED_EC_ACTIVE)
	&& (s_Med_ParentDTC.GW_288.timeout == MED_EC_INACTIVE) 
	&& (s_Med_ParentDTC.GW_288.crc == MED_EC_INACTIVE)
	&& (s_Med_ParentDTC.GW_288.rc == MED_EC_INACTIVE))
	{
		b_RetVal = TRUE; /* Satisfy Preconditions */
	}
	else
	{
		b_RetVal = FALSE; /* NOT Satisfy Preconditions, NO DTC */
	}
	return b_RetVal;
}

/**
 * \functions Med_EnableCondition_Group_PVPUip
 *
 * \brief   
 *
 ** \param[in] none,
 *
 ** \param[out] none,
 *
 ** \return RTE_E_OK, 
 * \comments
 * Preondition:
 * (1) Voltage supply of CAN Bus mode is in the range of 8.5V-16.5V.
 * (2) IGN is ON state after 3s 
 * (3) No BUS OFF or recover from BUS OFF at least 1s in public Can.
 * (4) BcmPwrStsFb=0x2:ON
 * (5) timeout, crc and alive couter DTC are not reported.
 */
FUNC(boolean, RTE_CODE) Med_EnableCondition_Group_PVPUip(void)
{
	boolean b_RetVal = FALSE;
	
	if((s_Med_ErrorInfo.EnableCondition.Poweron3000ms == MED_EC_ACTIVE) 
	&& (s_Med_ErrorInfo.EnableCondition.VoltageNormal == MED_EC_ACTIVE)
	&& (s_Med_ErrorInfo.EnableCondition.NoBusOffPublicCAN == MED_EC_ACTIVE)
	&& (s_Med_ErrorInfo.EnableCondition.BCMPowerModeState == MED_EC_ACTIVE)
	&& (s_Med_ParentDTC.GW_2DE.timeout == MED_EC_INACTIVE) 
	&& (s_Med_ParentDTC.GW_2DE.crc == MED_EC_INACTIVE)
	&& (s_Med_ParentDTC.GW_2DE.rc == MED_EC_INACTIVE))
	{
		b_RetVal = TRUE; /* Satisfy Preconditions */
	}
	else
	{
		b_RetVal = FALSE; /* NOT Satisfy Preconditions, NO DTC */
	}
	return b_RetVal;
}

/**
 * \functions Med_EnableCondition_Group_PVPUsrs
 *
 * \brief   
 *
 ** \param[in] none,
 *
 ** \param[out] none,
 *
 ** \return RTE_E_OK, 
 * \comments
 * Preondition:
 * (1) Voltage supply of CAN Bus mode is in the range of 8.5V-16.5V.
 * (2) IGN is ON state after 3s 
 * (3) No BUS OFF or recover from BUS OFF at least 1s in public can.
 * (4) BcmPwrStsFb=0x2:ON
 * (5) timeout, crc and alive couter DTC are not reported.
 */
FUNC(boolean, RTE_CODE) Med_EnableCondition_Group_PVPUsrs(void)
{
	boolean b_RetVal = FALSE;
	
	if((s_Med_ErrorInfo.EnableCondition.Poweron3000ms == MED_EC_ACTIVE) 
	&& (s_Med_ErrorInfo.EnableCondition.VoltageNormal == MED_EC_ACTIVE)
	&& (s_Med_ErrorInfo.EnableCondition.NoBusOffPublicCAN == MED_EC_ACTIVE)
	&& (s_Med_ErrorInfo.EnableCondition.BCMPowerModeState == MED_EC_ACTIVE)
	&& (s_Med_ParentDTC.GW_50.timeout == MED_EC_INACTIVE) 
	&& (s_Med_ParentDTC.GW_50.crc == MED_EC_INACTIVE)
	&& (s_Med_ParentDTC.GW_50.rc == MED_EC_INACTIVE))
	{
		b_RetVal = TRUE; /* Satisfy Preconditions */
	}
	else
	{
		b_RetVal = FALSE; /* NOT Satisfy Preconditions, NO DTC */
	}
	return b_RetVal;
}

/**
 * \functions Med_EnableCondition_Group_PVPUSesp
 *
 * \brief   
 *
 ** \param[in] none,
 *
 ** \param[out] none,
 *
 ** \return RTE_E_OK, 
 * \comments
 * Preondition:
 * (1) Voltage supply of CAN Bus mode is in the range of 8.5V-16.5V.
 * (2) IGN is ON state after 3s 
 * (3) No BUS OFF or recover from BUS OFF at least 1s.
 * (4) BcmPwrStsFb=0x2:ON
 * (5) timeout, crc and alive couter DTC are not reported.
 * (6) EspVehSpd>1km/h
 */
FUNC(boolean, RTE_CODE) Med_EnableCondition_Group_PVPUSesp(void)
{
	boolean b_RetVal = FALSE;
	
	if((s_Med_ErrorInfo.EnableCondition.Poweron3000ms == MED_EC_ACTIVE) 
	&& (s_Med_ErrorInfo.EnableCondition.VoltageNormal == MED_EC_ACTIVE)
	&& (s_Med_ErrorInfo.EnableCondition.NoBusOffPublicCAN == MED_EC_ACTIVE)
	&& (s_Med_ErrorInfo.EnableCondition.VehicleSpeedNot0 == MED_EC_ACTIVE)
	&& (s_Med_ErrorInfo.EnableCondition.BCMPowerModeState == MED_EC_ACTIVE)
	&& (s_Med_ParentDTC.GW_17A.timeout == MED_EC_INACTIVE) 
	&& (s_Med_ParentDTC.GW_17A.crc == MED_EC_INACTIVE)
	&& (s_Med_ParentDTC.GW_17A.rc == MED_EC_INACTIVE))
	{
		b_RetVal = TRUE; /* Satisfy Preconditions */
	}
	else
	{
		b_RetVal = FALSE; /* NOT Satisfy Preconditions, NO DTC */
	}
	return b_RetVal;
}

/**
 * \functions Med_EnableCondition_Group_Esp_GW278
 *
 * \brief   
 *
 ** \param[in] none,
 *
 ** \param[out] none,
 *
 ** \return RTE_E_OK, 
 * \comments
 * Preondition:
 * (1) Voltage supply of CAN Bus mode is in the range of 8.5V-16.5V.
 * (2) IGN is ON state after 3s 
 * (3) No BUS OFF or recover from BUS OFF at least 1s.
 * (4) BcmPwrStsFb=0x2:ON
 * (5) timeout, crc and alive couter DTC are not reported.
 */
FUNC(boolean, RTE_CODE) Med_EnableCondition_Group_Esp_GW278(void)         
{
	boolean b_RetVal = FALSE;
	
	if((s_Med_ErrorInfo.EnableCondition.Poweron3000ms == MED_EC_ACTIVE) 
	&& (s_Med_ErrorInfo.EnableCondition.VoltageNormal == MED_EC_ACTIVE)
	&& (s_Med_ErrorInfo.EnableCondition.NoBusOffPublicCAN == MED_EC_ACTIVE)
	&& (s_Med_ErrorInfo.EnableCondition.BCMPowerModeState == MED_EC_ACTIVE)
	&& (s_Med_ParentDTC.GW_278.timeout == MED_EC_INACTIVE) 
	&& (s_Med_ParentDTC.GW_278.crc == MED_EC_INACTIVE)
	&& (s_Med_ParentDTC.GW_278.rc == MED_EC_INACTIVE))
	{
		b_RetVal = TRUE; /* Satisfy Preconditions */
	}
	else
	{
		b_RetVal = FALSE; /* NOT Satisfy Preconditions, NO DTC */
	}
	return b_RetVal;
}

/**
 * \functions Med_EnableCondition_Group_FR_136
 *
 * \brief   
 *
 ** \param[in] none,
 *
 ** \param[out] none,
 *
 ** \return RTE_E_OK, 
 * \comments
 * Preondition:
 * (1) Voltage supply of CAN Bus mode is in the range of 8.5V-16.5V.
 * (2) IGN is ON state after 3s 
 * (3) No BUS OFF or recover from BUS OFF at least 1s.
 * (4) BcmPwrStsFb=0x2:ON
 * (5) timeout, crc and alive couter DTC are not reported.
 */
FUNC(boolean, RTE_CODE) Med_EnableCondition_Group_FR_136(void)         
{
	boolean b_RetVal = FALSE;
	
	if((s_Med_ErrorInfo.EnableCondition.Poweron3000ms == MED_EC_ACTIVE) 
	&& (s_Med_ErrorInfo.EnableCondition.VoltageNormal == MED_EC_ACTIVE)
	&& (s_Med_ErrorInfo.EnableCondition.NoBusOffPrivateCAN == MED_EC_ACTIVE)
	&& (s_Med_ErrorInfo.EnableCondition.BCMPowerModeState == MED_EC_ACTIVE)
	&& (s_Med_ParentDTC.FR_136.timeout == MED_EC_INACTIVE) 
	&& (s_Med_ParentDTC.FR_136.crc == MED_EC_INACTIVE)
	&& (s_Med_ParentDTC.FR_136.rc == MED_EC_INACTIVE))
	{
		b_RetVal = TRUE; /* Satisfy Preconditions */
	}
	else
	{
		b_RetVal = FALSE; /* NOT Satisfy Preconditions, NO DTC */
	}
	return b_RetVal;
}

/**
 * \functions Med_UserMainFunction
 *
 * \brief This function only use for do some userdata option.
 *
 ** \param[in] none,
 *
 ** \param[out] none,
 *
 ** \return RTE_E_OK, 
 * \comments
 *
 */
#if ((defined MED_USERMAINFUNCTION_ENABLE) && (MED_USERMAINFUNCTION_ENABLE == STD_ON))
void Med_UserMainFunction(void)
{
	/* 10ms */
    static uint16 ui16_Counter_100ms = 0x00;
	static uint16 ui16_Counter_500ms = 0x00;

	#if ((defined MED_PARENTDTC_ENABLED) && (MED_PARENTDTC_ENABLED == STD_ON))
	Med_ParentDTC();
    #endif

    (void)Med_u_Required_Port(); 
		
	if(ui16_Counter_100ms % 10 == 0U) //100ms
	{
	     #if ((defined MED_SENDFCSTATUS_ENABLED) && (MED_SENDFCSTATUS_ENABLED == STD_ON))
		(void)Med_u_FaultHandling_FCStatus_TX();
		 #endif
	}

	(void)Med_u_Provided_Port();
	

	if(ui16_Counter_500ms % 50 == 0U) //500ms
	{
	    Med_Rmt_MainFunction();
	}
    	
	ui16_Counter_100ms++;
	ui16_Counter_500ms++;

	if(ui16_Counter_100ms == 65535)
	{
        ui16_Counter_100ms = 0;
	}

	if(ui16_Counter_500ms == 65535)
	{
	    ui16_Counter_500ms = 0;
	}	
}
#endif

/**
 * \functions Med_Injection
 *
 * \brief This function only use for inject error event to Dem via XCP.
 *
 ** \param[in] none,
 *
 ** \param[out] none,
 *
 ** \return RTE_E_OK, 
 * \comments
 *
 */
#if ((defined MED_INJECTION_ENABLED) && (MED_INJECTION_ENABLED == STD_ON))
void Med_Injection(void)
{
  uint8 ui8_Dem_DEM_Type;
  
  if(TRUE == Med_b_EventInjectionTrigger)
  {
      for (uint32 ui32_EventInjectionIdx = 0; ui32_EventInjectionIdx < MED_EVENT_INJECTION_QUEUE_SIZE; ui32_EventInjectionIdx++)
      {
          uint8 ui8_HighByte = Med_a_EventInjectionQueue[ui32_EventInjectionIdx].DTC.HighByte;
		  uint8 ui8_MiddleByte = Med_a_EventInjectionQueue[ui32_EventInjectionIdx].DTC.MiddleByte;
		  uint8 ui8_LowByte = Med_a_EventInjectionQueue[ui32_EventInjectionIdx].DTC.LowByte;
		  
          if((ui8_HighByte == 0xFF) && (ui8_MiddleByte == 0xFF) && (ui8_LowByte == 0xFF))
		  {
              break;
		  }
		  else
		  {
			  for(uint16 ui16_EventIdindex = 1; ui16_EventIdindex < DEM_NUMBER_OF_EVENTS; ui16_EventIdindex++)
		      {
		          uint32 ui32_DTCOfEvent = 0;
			 
	              (void)Dem_GetDTCOfEvent(ui16_EventIdindex, DEM_DTC_FORMAT_UDS, &ui32_DTCOfEvent);
			 
	              uint8 ui8_Dem_DTCHighByte = (uint8)((ui32_DTCOfEvent >> 16) & 0xFF);
	              uint8 ui8_Dem_DTCMiddleByte = (uint8)((ui32_DTCOfEvent >> 8) & 0xFF);
	              uint8 ui8_Dem_DTCLowByte = (uint8)(ui32_DTCOfEvent & 0xFF);
			 
                  if((ui8_Dem_DTCHighByte != 0x00)&&(ui8_Dem_DTCMiddleByte != 0x00)&&(ui8_Dem_DTCLowByte != 0x00))
                  {
			          if((ui8_Dem_DTCHighByte == ui8_HighByte) &&
			 	         (ui8_Dem_DTCMiddleByte == ui8_MiddleByte) &&
			 	         (ui8_Dem_DTCLowByte == ui8_LowByte))
				         {
				             Dem_EventStatusType ui8_EventStatus = Med_a_EventInjectionQueue[ui32_EventInjectionIdx].trigger;
							 
				             if((ui8_EventStatus == DEM_EVENT_STATUS_PASSED) ||
							 	(ui8_EventStatus == DEM_EVENT_STATUS_FAILED) ||
							 	(ui8_EventStatus == DEM_EVENT_STATUS_PREPASSED) ||
							 	(ui8_EventStatus == DEM_EVENT_STATUS_PREFAILED))
				             	{
				                    ui8_Dem_DEM_Type = (uint8)Dem_GbiEventKind(ui16_EventIdindex);
                                    /* inject the DEM event with the chosen state */
			                        if ( (uint8)DEM_EVENT_KIND_BSW == ui8_Dem_DEM_Type )
			                        {            
				                        Dem_ReportErrorStatus(ui16_EventIdindex, ui8_EventStatus);
			                        }
			                        else
			                        {
				                        (void)Dem_SetEventStatus(ui16_EventIdindex, ui8_EventStatus);
			                        }
							 	}
								else
								{
								    break;
								}
				         }
                  }
		      }
          }
     }
	 /* reset the injection trigger */
     Med_b_EventInjectionTrigger = FALSE;
  }
  else
  {
    /* Injection is not requested, nothing to be done */
  }
}
#endif

/**
 * \functions Med_UserInitFunction
 *
 * \brief This function only use for do some userdata initial.
 *
 ** \param[in] none,
 *
 ** \param[out] none,
 *
 ** \return RTE_E_OK, 
 * \comments
 *
 */
#if ((defined MED_USERINITFUNCION_ENABLED) && (MED_USERINITFUNCION_ENABLED == STD_ON))
void Med_UserInitFunction(void)
{
#if ((defined MED_INJECTION_ENABLED) && (MED_INJECTION_ENABLED == STD_ON))

    for(uint32 ui32_EventInjectionIdx = 0;ui32_EventInjectionIdx < MED_EVENT_INJECTION_QUEUE_SIZE; ui32_EventInjectionIdx++)
    {
        Med_a_EventInjectionQueue[ui32_EventInjectionIdx].DTC.HighByte = 0xFF;
		Med_a_EventInjectionQueue[ui32_EventInjectionIdx].DTC.MiddleByte = 0xFF;
		Med_a_EventInjectionQueue[ui32_EventInjectionIdx].DTC.LowByte = 0xFF;
        Med_a_EventInjectionQueue[ui32_EventInjectionIdx].trigger = DEM_EVENT_STATUS_NO_INJECTION;
	}	
	
#endif

#if ((defined MED_SENDFCSTATUS_ENABLED) && (MED_SENDFCSTATUS_ENABLED == STD_ON))

    for(uint32 ui32_EventIdx = 0;ui32_EventIdx < DEM_NUMBER_OF_EVENTS; ui32_EventIdx++)
    {
	    Med_a_CameraFailureStatus[ui32_EventIdx] = 0x00u;
	    Med_a_AEBTextInfoStatus[ui32_EventIdx] = 0x00u;
		Med_a_CameraCalibrationStatus[ui32_EventIdx] = 0x00u;
	}

#endif

}
#endif


/**
 * \functions Med_u_CBStatusEvt_DEM_DTC_VCU_Accr_Pedl_Posn_Invld
 *
 * \brief 0xD790F0
 *
 ** \param[in] none,
 *
 ** \param[out] none,
 *
 ** \return RTE_E_OK, 
 * \comments
 *
 */
FUNC(Std_ReturnType, RTE_CODE) Med_u_CBStatusEvt_DEM_DTC_VCU_Accr_Pedl_Posn_Invld (Dem_EventStatusExtendedType EventStatusOld, Dem_EventStatusExtendedType EventStatusNew)
{
  /* suppress compiler warnings about unused arguments */
  (void)EventStatusOld;
  
  #if ((defined MED_SENDFCSTATUS_ENABLED) && (MED_SENDFCSTATUS_ENABLED == STD_ON))
  (void)Med_u_FaultHandling_FCStatus(DemConf_DemEventParameter_DEM_DTC_VCU_Accr_Pedl_Posn_Invld,EventStatusNew,0x00, 0x0A, 0x00);
  #endif
  
  return RTE_E_OK;
} /* FUNC(Std_ReturnType, RTE_CODE) Med_u_CBStatusEvt_DEM_DTC_VCU_Accr_Pedl_Posn_Invld (Dem_EventStatusExtendedType EventStatusOld, Dem_EventStatusExtendedType EventStatusNew) */

/**
 * \functions Med_u_CBStatusEvt_DEM_DTC_VCU_Gear_Posn_Invld
 *
 * \brief 0xD791F0
 *
 ** \param[in] none,
 *
 ** \param[out] none,
 *
 ** \return RTE_E_OK, 
 * \comments
 *
 */
FUNC(Std_ReturnType, RTE_CODE) Med_u_CBStatusEvt_DEM_DTC_VCU_Gear_Posn_Invld (Dem_EventStatusExtendedType EventStatusOld, Dem_EventStatusExtendedType EventStatusNew)
{
  /* suppress compiler warnings about unused arguments */
  (void)EventStatusOld;
  
  #if ((defined MED_SENDFCSTATUS_ENABLED) && (MED_SENDFCSTATUS_ENABLED == STD_ON))
  (void)Med_u_FaultHandling_FCStatus(DemConf_DemEventParameter_DEM_DTC_VCU_Gear_Posn_Invld,EventStatusNew,0x05, 0x09, 0x00);
  #endif
  
  return RTE_E_OK;
} /* FUNC(Std_ReturnType, RTE_CODE) Med_u_CBStatusEvt_DEM_DTC_VCU_Gear_Posn_Invld (Dem_EventStatusExtendedType EventStatusOld, Dem_EventStatusExtendedType EventStatusNew) */

/**
 * \functions Med_u_CBStatusEvt_DEM_DTC_BCM_TurnIndcrLight_Fault
 *
 * \brief 0xD790F1
 *
 ** \param[in] none,
 *
 ** \param[out] none,
 *
 ** \return RTE_E_OK, 
 * \comments
 *
 */
FUNC(Std_ReturnType, RTE_CODE) Med_u_CBStatusEvt_DEM_DTC_BCM_TurnIndcrLight_Fault (Dem_EventStatusExtendedType EventStatusOld, Dem_EventStatusExtendedType EventStatusNew)
{
  /* suppress compiler warnings about unused arguments */
  (void)EventStatusOld;
  
  #if ((defined MED_SENDFCSTATUS_ENABLED) && (MED_SENDFCSTATUS_ENABLED == STD_ON))
  (void)Med_u_FaultHandling_FCStatus(DemConf_DemEventParameter_DEM_DTC_BCM_Turn_Indcr_Light_Fault,EventStatusNew,0x00, 0x00, 0x00);
  #endif
  
  return RTE_E_OK;
} /* FUNC(Std_ReturnType, RTE_CODE) Med_u_CBStatusEvt_DEM_DTC_BCM_TurnIndcrLight_Fault (Dem_EventStatusExtendedType EventStatusOld, Dem_EventStatusExtendedType EventStatusNew) */

/**
 * \functions Med_u_CBStatusEvt_DEM_DTC_BCM_Brake_Lamp_Error
 *
 * \brief 0xD794F2
 *
 ** \param[in] none,
 *
 ** \param[out] none,
 *
 ** \return RTE_E_OK, 
 * \comments
 *
 */
FUNC(Std_ReturnType, RTE_CODE) Med_u_CBStatusEvt_DEM_DTC_BCM_Brake_Lamp_Error (Dem_EventStatusExtendedType EventStatusOld, Dem_EventStatusExtendedType EventStatusNew)
{
  /* suppress compiler warnings about unused arguments */
  (void)EventStatusOld;
  
  #if ((defined MED_SENDFCSTATUS_ENABLED) && (MED_SENDFCSTATUS_ENABLED == STD_ON))
  (void)Med_u_FaultHandling_FCStatus(DemConf_DemEventParameter_DEM_DTC_BCM_Brake_Lamp_Error,EventStatusNew,0x00, 0x00, 0x00);
  #endif
  
  return RTE_E_OK;
} /* FUNC(Std_ReturnType, RTE_CODE) Med_u_CBStatusEvt_DEM_DTC_BCM_Brake_Lamp_Error (Dem_EventStatusExtendedType EventStatusOld, Dem_EventStatusExtendedType EventStatusNew) */

/**
 * \functions Med_u_CBStatusEvt_DEM_DTC_BCM_FrntWiperSts_Fault
 *
 * \brief 0xD791F1
 *
 ** \param[in] none,
 *
 ** \param[out] none,
 *
 ** \return RTE_E_OK, 
 * \comments
 *
 */
FUNC(Std_ReturnType, RTE_CODE) Med_u_CBStatusEvt_DEM_DTC_BCM_FrntWiperSts_Fault (Dem_EventStatusExtendedType EventStatusOld, Dem_EventStatusExtendedType EventStatusNew)
{
  /* suppress compiler warnings about unused arguments */
  (void)EventStatusOld;

  #if ((defined MED_SENDFCSTATUS_ENABLED) && (MED_SENDFCSTATUS_ENABLED == STD_ON))
  (void)Med_u_FaultHandling_FCStatus(DemConf_DemEventParameter_DEM_DTC_BCM_Frnt_Wiper_Sts_Fault,EventStatusNew,0x00, 0x00, 0x00);
  #endif
  
  return RTE_E_OK;
} /* FUNC(Std_ReturnType, RTE_CODE) Med_u_CBStatusEvt_DEM_DTC_BCM_FrntWiperSts_Fault (Dem_EventStatusExtendedType EventStatusOld, Dem_EventStatusExtendedType EventStatusNew) */

/**
 * \functions Med_u_CBStatusEvt_DEM_DTC_ESP_Veh_Spd_Invld
 *
 * \brief 0xD792F0
 *
 ** \param[in] none,
 *
 ** \param[out] none,
 *
 ** \return RTE_E_OK, 
 * \comments
 *
 */
FUNC(Std_ReturnType, RTE_CODE) Med_u_CBStatusEvt_DEM_DTC_ESP_Veh_Spd_Invld (Dem_EventStatusExtendedType EventStatusOld, Dem_EventStatusExtendedType EventStatusNew)
{
  /* suppress compiler warnings about unused arguments */
  (void)EventStatusOld;

  #if ((defined MED_SENDFCSTATUS_ENABLED) && (MED_SENDFCSTATUS_ENABLED == STD_ON))
  (void)Med_u_FaultHandling_FCStatus(DemConf_DemEventParameter_DEM_DTC_ESP_Veh_Spd_Invld,EventStatusNew,0x05, 0x05, 0x00);
  #endif
  
  return RTE_E_OK;
} /* FUNC(Std_ReturnType, RTE_CODE) Med_u_CBStatusEvt_DEM_DTC_ESP_Veh_Spd_Invld (Dem_EventStatusExtendedType EventStatusOld, Dem_EventStatusExtendedType EventStatusNew) */

/**
 * \functions Med_u_CBStatusEvt_DEM_DTC_ESP_ABS_Fault
 *
 * \brief 0xD792F1
 *
 ** \param[in] none,
 *
 ** \param[out] none,
 *
 ** \return RTE_E_OK, 
 * \comments
 *
 */
FUNC(Std_ReturnType, RTE_CODE) Med_u_CBStatusEvt_DEM_DTC_ESP_ABS_Fault (Dem_EventStatusExtendedType EventStatusOld, Dem_EventStatusExtendedType EventStatusNew)
{
  /* suppress compiler warnings about unused arguments */
  (void)EventStatusOld;

   #if ((defined MED_SENDFCSTATUS_ENABLED) && (MED_SENDFCSTATUS_ENABLED == STD_ON))
  (void)Med_u_FaultHandling_FCStatus(DemConf_DemEventParameter_DEM_DTC_ESP_ABS_Fault,EventStatusNew,0x00, 0x05, 0x00);
  #endif
  
  return RTE_E_OK;
} /* FUNC(Std_ReturnType, RTE_CODE) Med_u_CBStatusEvt_DEM_DTC_ESP_ABS_Fault (Dem_EventStatusExtendedType EventStatusOld, Dem_EventStatusExtendedType EventStatusNew) */

/**
 * \functions Med_u_CBStatusEvt_DEM_DTC_ESP_TCS_Fault
 *
 * \brief 0xD793F1
 *
 ** \param[in] none,
 *
 ** \param[out] none,
 *
 ** \return RTE_E_OK, 
 * \comments
 *
 */
FUNC(Std_ReturnType, RTE_CODE) Med_u_CBStatusEvt_DEM_DTC_ESP_TCS_Fault (Dem_EventStatusExtendedType EventStatusOld, Dem_EventStatusExtendedType EventStatusNew)
{
  /* suppress compiler warnings about unused arguments */
  (void)EventStatusOld;

  #if ((defined MED_SENDFCSTATUS_ENABLED) && (MED_SENDFCSTATUS_ENABLED == STD_ON))
  (void)Med_u_FaultHandling_FCStatus(DemConf_DemEventParameter_DEM_DTC_ESP_TCS_Fault,EventStatusNew,0x00, 0x05, 0x00);
  #endif
  
  return RTE_E_OK;
} /* FUNC(Std_ReturnType, RTE_CODE) Med_u_CBStatusEvt_DEM_DTC_ESP_TCS_Fault (Dem_EventStatusExtendedType EventStatusOld, Dem_EventStatusExtendedType EventStatusNew) */

/**
 * \functions Med_u_CBStatusEvt_DEM_DTC_ESP_Ebd_Failr
 *
 * \brief 0xD793F2
 *
 ** \param[in] none,
 *
 ** \param[out] none,
 *
 ** \return RTE_E_OK, 
 * \comments
 *
 */
FUNC(Std_ReturnType, RTE_CODE) Med_u_CBStatusEvt_DEM_DTC_ESP_Ebd_Failr (Dem_EventStatusExtendedType EventStatusOld, Dem_EventStatusExtendedType EventStatusNew)
{
  /* suppress compiler warnings about unused arguments */
  (void)EventStatusOld;
  
  #if ((defined MED_SENDFCSTATUS_ENABLED) && (MED_SENDFCSTATUS_ENABLED == STD_ON))
  (void)Med_u_FaultHandling_FCStatus(DemConf_DemEventParameter_DEM_DTC_Esp_Ebd_Failr,EventStatusNew,0x00, 0x05, 0x00);
  #endif
  
  return RTE_E_OK;
} /* FUNC(Std_ReturnType, RTE_CODE) Med_u_CBStatusEvt_DEM_DTC_ESP_Ebd_Failr (Dem_EventStatusExtendedType EventStatusOld, Dem_EventStatusExtendedType EventStatusNew) */

/**
 * \functions Med_u_CBStatusEvt_DEM_DTC_ESP_ABA_NOT_Available
 *
 * \brief 0xD790F2
 *
 ** \param[in] none,
 *
 ** \param[out] none,
 *
 ** \return RTE_E_OK, 
 * \comments
 *
 */
FUNC(Std_ReturnType, RTE_CODE) Med_u_CBStatusEvt_DEM_DTC_ESP_ABA_NOT_Available (Dem_EventStatusExtendedType EventStatusOld, Dem_EventStatusExtendedType EventStatusNew)
{
  /* suppress compiler warnings about unused arguments */
  (void)EventStatusOld;

  #if ((defined MED_SENDFCSTATUS_ENABLED) && (MED_SENDFCSTATUS_ENABLED == STD_ON))
  (void)Med_u_FaultHandling_FCStatus(DemConf_DemEventParameter_DEM_DTC_ESP_ABA_NOT_Available,EventStatusNew,0x00, 0x05, 0x00);
  #endif
  
  return RTE_E_OK;
} /* FUNC(Std_ReturnType, RTE_CODE) Med_u_CBStatusEvt_DEM_DTC_ESP_ABA_NOT_Available (Dem_EventStatusExtendedType EventStatusOld, Dem_EventStatusExtendedType EventStatusNew) */

/**
 * \functions Med_u_CBStatusEvt_DEM_DTC_ESP_AEB_NOT_Available
 *
 * \brief 0xD791F2
 *
 ** \param[in] none,
 *
 ** \param[out] none,
 *
 ** \return RTE_E_OK, 
 * \comments
 *
 */
FUNC(Std_ReturnType, RTE_CODE) Med_u_CBStatusEvt_DEM_DTC_ESP_AEB_NOT_Available (Dem_EventStatusExtendedType EventStatusOld, Dem_EventStatusExtendedType EventStatusNew)
{
  /* suppress compiler warnings about unused arguments */
  (void)EventStatusOld;

  #if ((defined MED_SENDFCSTATUS_ENABLED) && (MED_SENDFCSTATUS_ENABLED == STD_ON))
  (void)Med_u_FaultHandling_FCStatus(DemConf_DemEventParameter_DEM_DTC_ESP_AEB_NOT_Available,EventStatusNew,0x00, 0x05, 0x00);
  #endif

  return RTE_E_OK;
} /* FUNC(Std_ReturnType, RTE_CODE) Med_u_CBStatusEvt_DEM_DTC_ESP_AEB_NOT_Available (Dem_EventStatusExtendedType EventStatusOld, Dem_EventStatusExtendedType EventStatusNew) */

/**
 * \functions Med_u_CBStatusEvt_DEM_DTC_ESP_AWB_NOT_Available
 *
 * \brief 0xD792F2
 *
 ** \param[in] none,
 *
 ** \param[out] none,
 *
 ** \return RTE_E_OK, 
 * \comments
 *
 */
FUNC(Std_ReturnType, RTE_CODE) Med_u_CBStatusEvt_DEM_DTC_ESP_AWB_NOT_Available (Dem_EventStatusExtendedType EventStatusOld, Dem_EventStatusExtendedType EventStatusNew)
{
  /* suppress compiler warnings about unused arguments */
  (void)EventStatusOld;
  
  #if ((defined MED_SENDFCSTATUS_ENABLED) && (MED_SENDFCSTATUS_ENABLED == STD_ON))
  (void)Med_u_FaultHandling_FCStatus(DemConf_DemEventParameter_DEM_DTC_ESP_AWB_NOT_Available,EventStatusNew,0x00, 0x05, 0x00);
  #endif
  
  return RTE_E_OK;
} /* FUNC(Std_ReturnType, RTE_CODE) Med_u_CBStatusEvt_DEM_DTC_ESP_AWB_NOT_Available (Dem_EventStatusExtendedType EventStatusOld, Dem_EventStatusExtendedType EventStatusNew) */

/**
 * \functions Med_u_CBStatusEvt_DEM_DTC_Whl_Spd_Pls_Invld
 *
 * \brief 0xD793F0
 *
 ** \param[in] none,
 *
 ** \param[out] none,
 *
 ** \return RTE_E_OK, 
 * \comments
 *
 */
FUNC(Std_ReturnType, RTE_CODE) Med_u_CBStatusEvt_DEM_DTC_Whl_Spd_Pls_Invld (Dem_EventStatusExtendedType EventStatusOld, Dem_EventStatusExtendedType EventStatusNew)
{
  /* suppress compiler warnings about unused arguments */
  (void)EventStatusOld;
  
  #if ((defined MED_SENDFCSTATUS_ENABLED) && (MED_SENDFCSTATUS_ENABLED == STD_ON))
  (void)Med_u_FaultHandling_FCStatus(DemConf_DemEventParameter_DEM_DTC_Whl_Spd_Pls_Invld,EventStatusNew,0x00, 0x05, 0x00);
  #endif

  return RTE_E_OK;
} /* FUNC(Std_ReturnType, RTE_CODE) Med_u_CBStatusEvt_DEM_DTC_Whl_Spd_Pls_Invld (Dem_EventStatusExtendedType EventStatusOld, Dem_EventStatusExtendedType EventStatusNew) */

/**
 * \functions Med_u_CBStatusEvt_DEM_DTC_Whl_Spd_Dir_Invld
 *
 * \brief 0xD794F0
 *
 ** \param[in] none,
 *
 ** \param[out] none,
 *
 ** \return RTE_E_OK, 
 * \comments
 *
 */
FUNC(Std_ReturnType, RTE_CODE) Med_u_CBStatusEvt_DEM_DTC_Whl_Spd_Dir_Invld (Dem_EventStatusExtendedType EventStatusOld, Dem_EventStatusExtendedType EventStatusNew)
{
  /* suppress compiler warnings about unused arguments */
  (void)EventStatusOld;
  
  #if ((defined MED_SENDFCSTATUS_ENABLED) && (MED_SENDFCSTATUS_ENABLED == STD_ON))
  (void)Med_u_FaultHandling_FCStatus(DemConf_DemEventParameter_DEM_DTC_Whl_Spd_Dir_Invld,EventStatusNew,0x00, 0x05, 0x00);
  #endif

  return RTE_E_OK;
} /* FUNC(Std_ReturnType, RTE_CODE) Med_u_CBStatusEvt_DEM_DTC_Whl_Spd_Dir_Invld (Dem_EventStatusExtendedType EventStatusOld, Dem_EventStatusExtendedType EventStatusNew) */

/**
 * \functions Med_u_CBStatusEvt_DEM_DTC_Whl_Spd_Data_Invld
 *
 * \brief 0xD795F0
 *
 ** \param[in] none,
 *
 ** \param[out] none,
 *
 ** \return RTE_E_OK, 
 * \comments
 *
 */
FUNC(Std_ReturnType, RTE_CODE) Med_u_CBStatusEvt_DEM_DTC_Whl_Spd_Data_Invld (Dem_EventStatusExtendedType EventStatusOld, Dem_EventStatusExtendedType EventStatusNew)
{
  /* suppress compiler warnings about unused arguments */
  (void)EventStatusOld;
  
  #if ((defined MED_SENDFCSTATUS_ENABLED) && (MED_SENDFCSTATUS_ENABLED == STD_ON))
  (void)Med_u_FaultHandling_FCStatus(DemConf_DemEventParameter_DEM_DTC_Whl_Spd_Data_Invld,EventStatusNew,0x00, 0x05, 0x00);
  #endif

  return RTE_E_OK;
} /* FUNC(Std_ReturnType, RTE_CODE) Med_u_CBStatusEvt_DEM_DTC_Whl_Spd_Data_Invld (Dem_EventStatusExtendedType EventStatusOld, Dem_EventStatusExtendedType EventStatusNew) */

/**
 * \functions Med_u_CBStatusEvt_DEM_DTC_IB_Brk_Pedl_Invld
 *
 * \brief 0xD796F0
 *
 ** \param[in] none,
 *
 ** \param[out] none,
 *
 ** \return RTE_E_OK, 
 * \comments
 *
 */
FUNC(Std_ReturnType, RTE_CODE) Med_u_CBStatusEvt_DEM_DTC_IB_Brk_Pedl_Invld (Dem_EventStatusExtendedType EventStatusOld, Dem_EventStatusExtendedType EventStatusNew)
{
  /* suppress compiler warnings about unused arguments */
  (void)EventStatusOld;
  
  #if ((defined MED_SENDFCSTATUS_ENABLED) && (MED_SENDFCSTATUS_ENABLED == STD_ON))
  (void)Med_u_FaultHandling_FCStatus(DemConf_DemEventParameter_DEM_DTC_IB_Brk_Pedl_Invld,EventStatusNew,0x00, 0x00, 0x00);
  #endif
  
  return RTE_E_OK;
} /* FUNC(Std_ReturnType, RTE_CODE) Med_u_CBStatusEvt_DEM_DTC_IB_Brk_Pedl_Invld (Dem_EventStatusExtendedType EventStatusOld, Dem_EventStatusExtendedType EventStatusNew) */

/**
 * \functions Med_u_CBStatusEvt_DEM_DTC_EPS_Actual_TorsionTorq_Invld
 *
 * \brief 0xD797F0
 *
 ** \param[in] none,
 *
 ** \param[out] none,
 *
 ** \return RTE_E_OK, 
 * \comments
 *
 */
FUNC(Std_ReturnType, RTE_CODE) Med_u_CBStatusEvt_DEM_DTC_EPS_Actual_TorsionTorq_Invld (Dem_EventStatusExtendedType EventStatusOld, Dem_EventStatusExtendedType EventStatusNew)
{
  /* suppress compiler warnings about unused arguments */
  (void)EventStatusOld;
  
  #if ((defined MED_SENDFCSTATUS_ENABLED) && (MED_SENDFCSTATUS_ENABLED == STD_ON))
  (void)Med_u_FaultHandling_FCStatus(DemConf_DemEventParameter_DEM_DTC_EPS_Actual_Torsion_Torq_Invld,EventStatusNew,0x00, 0x00, 0x00);
  #endif

  return RTE_E_OK;
} /* FUNC(Std_ReturnType, RTE_CODE) Med_u_CBStatusEvt_DEM_DTC_EPS_Actual_TorsionTorq_Invld (Dem_EventStatusExtendedType EventStatusOld, Dem_EventStatusExtendedType EventStatusNew) */

/**
 * \functions Med_u_CBStatusEvt_DEM_DTC_EPS_ActualMotor_Invld
 *
 * \brief 0xD798F0
 *
 ** \param[in] none,
 *
 ** \param[out] none,
 *
 ** \return RTE_E_OK, 
 * \comments
 *
 */
FUNC(Std_ReturnType, RTE_CODE) Med_u_CBStatusEvt_DEM_DTC_EPS_ActualMotor_Invld (Dem_EventStatusExtendedType EventStatusOld, Dem_EventStatusExtendedType EventStatusNew)
{
  /* suppress compiler warnings about unused arguments */
  (void)EventStatusOld;
  
  #if ((defined MED_SENDFCSTATUS_ENABLED) && (MED_SENDFCSTATUS_ENABLED == STD_ON))
  (void)Med_u_FaultHandling_FCStatus(DemConf_DemEventParameter_DEM_DTC_EPS_Actual_Motor_Invld,EventStatusNew,0x00, 0x00, 0x00);
  #endif
  
  return RTE_E_OK;
} /* FUNC(Std_ReturnType, RTE_CODE) Med_u_CBStatusEvt_DEM_DTC_EPS_ActualMotor_Invld (Dem_EventStatusExtendedType EventStatusOld, Dem_EventStatusExtendedType EventStatusNew) */

/**
 * \functions Med_u_CBStatusEvt_DEM_DTC_EPS_Sas_NOT_Cal
 *
 * \brief 0xD79010
 *
 ** \param[in] none,
 *
 ** \param[out] none,
 *
 ** \return RTE_E_OK, 
 * \comments
 *
 */
FUNC(Std_ReturnType, RTE_CODE) Med_u_CBStatusEvt_DEM_DTC_EPS_Sas_NOT_Cal (Dem_EventStatusExtendedType EventStatusOld, Dem_EventStatusExtendedType EventStatusNew)
{
  /* suppress compiler warnings about unused arguments */
  (void)EventStatusOld;
  
  #if ((defined MED_SENDFCSTATUS_ENABLED) && (MED_SENDFCSTATUS_ENABLED == STD_ON))
  (void)Med_u_FaultHandling_FCStatus(DemConf_DemEventParameter_DEM_DTC_EPS_Sas_NOT_Cal,EventStatusNew,0x05, 0x06, 0x00);
  #endif
  
  return RTE_E_OK;
} /* FUNC(Std_ReturnType, RTE_CODE) Med_u_CBStatusEvt_DEM_DTC_EPS_Sas_NOT_Cal (Dem_EventStatusExtendedType EventStatusOld, Dem_EventStatusExtendedType EventStatusNew) */

/**
 * \functions Med_u_CBStatusEvt_DEM_DTC_EPS_Actual_Motor_Torq_Invld
 *
 * \brief 0xD799F0
 *
 ** \param[in] none,
 *
 ** \param[out] none,
 *
 ** \return RTE_E_OK, 
 * \comments
 *
 */
FUNC(Std_ReturnType, RTE_CODE) Med_u_CBStatusEvt_DEM_DTC_EPS_Actual_Motor_Torq_Invld (Dem_EventStatusExtendedType EventStatusOld, Dem_EventStatusExtendedType EventStatusNew)
{
  /* suppress compiler warnings about unused arguments */
  (void)EventStatusOld;

  #if ((defined MED_SENDFCSTATUS_ENABLED) && (MED_SENDFCSTATUS_ENABLED == STD_ON))
  (void)Med_u_FaultHandling_FCStatus(DemConf_DemEventParameter_DEM_DTC_EPS_Actual_Motor_Torq_Invld,EventStatusNew,0x05, 0x06, 0x00);
  #endif
  
  return RTE_E_OK;
} /* FUNC(Std_ReturnType, RTE_CODE) Med_u_CBStatusEvt_DEM_DTC_EPS_Actual_Motor_Torq_Invld (Dem_EventStatusExtendedType EventStatusOld, Dem_EventStatusExtendedType EventStatusNew) */

/**
 * \functions Med_u_CBStatusEvt_DEM_DTC_EPS_Steer_AgSens_Fault
 *
 * \brief 0xD79AF0
 *
 ** \param[in] none,
 *
 ** \param[out] none,
 *
 ** \return RTE_E_OK, 
 * \comments
 *
 */
FUNC(Std_ReturnType, RTE_CODE) Med_u_CBStatusEvt_DEM_DTC_EPS_Steer_AgSens_Fault (Dem_EventStatusExtendedType EventStatusOld, Dem_EventStatusExtendedType EventStatusNew)
{
  /* suppress compiler warnings about unused arguments */
  (void)EventStatusOld;
  
  #if ((defined MED_SENDFCSTATUS_ENABLED) && (MED_SENDFCSTATUS_ENABLED == STD_ON))
  (void)Med_u_FaultHandling_FCStatus(DemConf_DemEventParameter_DEM_DTC_EPS_Steer_AgSens_Fault,EventStatusNew,0x05, 0x06, 0x00);
  #endif
  
  return RTE_E_OK;
} /* FUNC(Std_ReturnType, RTE_CODE) Med_u_CBStatusEvt_DEM_DTC_EPS_Steer_AgSens_Fault (Dem_EventStatusExtendedType EventStatusOld, Dem_EventStatusExtendedType EventStatusNew) */

/**
 * \functions Med_u_CBStatusEvt_DEM_DTC_SRS_Drvr_BucSwt_Invld
 *
 * \brief 0xD79BF0
 *
 ** \param[in] none,
 *
 ** \param[out] none,
 *
 ** \return RTE_E_OK, 
 * \comments
 *
 */
FUNC(Std_ReturnType, RTE_CODE) Med_u_CBStatusEvt_DEM_DTC_SRS_Drvr_BucSwt_Invld (Dem_EventStatusExtendedType EventStatusOld, Dem_EventStatusExtendedType EventStatusNew)
{
  /* suppress compiler warnings about unused arguments */
  (void)EventStatusOld;

  #if ((defined MED_SENDFCSTATUS_ENABLED) && (MED_SENDFCSTATUS_ENABLED == STD_ON))
  (void)Med_u_FaultHandling_FCStatus(DemConf_DemEventParameter_DEM_DTC_SRS_Drvr_BucSwt_Invld,EventStatusNew,0x00, 0x00, 0x00);
  #endif
  
  return RTE_E_OK;
} /* FUNC(Std_ReturnType, RTE_CODE) Med_u_CBStatusEvt_DEM_DTC_SRS_Drvr_BucSwt_Invld (Dem_EventStatusExtendedType EventStatusOld, Dem_EventStatusExtendedType EventStatusNew) */

/**
 * \functions Med_u_CBStatusEvt_DEM_DTC_EPS_Pinionang_Invld
 *
 * \brief 0xD79CF0
 *
 ** \param[in] none,
 *
 ** \param[out] none,
 *
 ** \return RTE_E_OK, 
 * \comments
 *
 */
FUNC(Std_ReturnType, RTE_CODE) Med_u_CBStatusEvt_DEM_DTC_EPS_Pinionang_Invld (Dem_EventStatusExtendedType EventStatusOld, Dem_EventStatusExtendedType EventStatusNew)
{
  /* suppress compiler warnings about unused arguments */
  (void)EventStatusOld;

  #if ((defined MED_SENDFCSTATUS_ENABLED) && (MED_SENDFCSTATUS_ENABLED == STD_ON))
  (void)Med_u_FaultHandling_FCStatus(DemConf_DemEventParameter_DEM_DTC_EPS_Pinionang_Invld,EventStatusNew,0x00, 0x00, 0x00);
  #endif
  
  return RTE_E_OK;
} /* FUNC(Std_ReturnType, RTE_CODE) Med_u_CBStatusEvt_DEM_DTC_EPS_Pinionang_Invld (Dem_EventStatusExtendedType EventStatusOld, Dem_EventStatusExtendedType EventStatusNew) */

/**
 * \functions Med_u_CBStatusEvt_DEM_DTC_EPS_Pinionang_Fault
 *
 * \brief 0xD794F1
 *
 ** \param[in] none,
 *
 ** \param[out] none,
 *
 ** \return RTE_E_OK, 
 * \comments
 *
 */
FUNC(Std_ReturnType, RTE_CODE) Med_u_CBStatusEvt_DEM_DTC_EPS_Pinionang_Fault (Dem_EventStatusExtendedType EventStatusOld, Dem_EventStatusExtendedType EventStatusNew)
{
  /* suppress compiler warnings about unused arguments */
  (void)EventStatusOld;

  #if ((defined MED_SENDFCSTATUS_ENABLED) && (MED_SENDFCSTATUS_ENABLED == STD_ON))
  (void)Med_u_FaultHandling_FCStatus(DemConf_DemEventParameter_DEM_DTC_EPS_Pinionang_Fault,EventStatusNew,0x00, 0x00, 0x00);
  #endif
  
  return RTE_E_OK;
} /* FUNC(Std_ReturnType, RTE_CODE) Med_u_CBStatusEvt_DEM_DTC_EPS_Pinionang_Fault (Dem_EventStatusExtendedType EventStatusOld, Dem_EventStatusExtendedType EventStatusNew) */

/**
 * \functions Med_u_CBStatusEvt_DEM_DTC_ESP_Lat_Accel_Invld
 *
 * \brief 0xD79DF0
 *
 ** \param[in] none,
 *
 ** \param[out] none,
 *
 ** \return RTE_E_OK, 
 * \comments
 *
 */
FUNC(Std_ReturnType, RTE_CODE) Med_u_CBStatusEvt_DEM_DTC_ESP_Lat_Accel_Invld (Dem_EventStatusExtendedType EventStatusOld, Dem_EventStatusExtendedType EventStatusNew)
{
  /* suppress compiler warnings about unused arguments */
  (void)EventStatusOld;

  #if ((defined MED_SENDFCSTATUS_ENABLED) && (MED_SENDFCSTATUS_ENABLED == STD_ON))
  (void)Med_u_FaultHandling_FCStatus(DemConf_DemEventParameter_DEM_DTC_ESP_Lat_Accel_Invld,EventStatusNew,0x00, 0x00, 0x00);
  #endif
  
  return RTE_E_OK;
} /* FUNC(Std_ReturnType, RTE_CODE) Med_u_CBStatusEvt_DEM_DTC_ESP_Lat_Accel_Invld (Dem_EventStatusExtendedType EventStatusOld, Dem_EventStatusExtendedType EventStatusNew) */

/**
 * \functions Med_u_CBStatusEvt_DEM_DTC_ESP_Long_Accel_Invld
 *
 * \brief 0xD79EF0
 *
 ** \param[in] none,
 *
 ** \param[out] none,
 *
 ** \return RTE_E_OK, 
 * \comments
 *
 */
FUNC(Std_ReturnType, RTE_CODE) Med_u_CBStatusEvt_DEM_DTC_ESP_Long_Accel_Invld (Dem_EventStatusExtendedType EventStatusOld, Dem_EventStatusExtendedType EventStatusNew)
{
  /* suppress compiler warnings about unused arguments */
  (void)EventStatusOld;

  #if ((defined MED_SENDFCSTATUS_ENABLED) && (MED_SENDFCSTATUS_ENABLED == STD_ON))
  (void)Med_u_FaultHandling_FCStatus(DemConf_DemEventParameter_DEM_DTC_ESP_Long_Accel_Invld,EventStatusNew,0x05, 0x00, 0x00);
  #endif
  
  return RTE_E_OK;
} /* FUNC(Std_ReturnType, RTE_CODE) Med_u_CBStatusEvt_DEM_DTC_ESP_Long_Accel_Invld (Dem_EventStatusExtendedType EventStatusOld, Dem_EventStatusExtendedType EventStatusNew) */

/**
 * \functions Med_u_CBStatusEvt_DEM_DTC_ESP_Yaw_Rate_Invld
 *
 * \brief 0xD79FF0
 *
 ** \param[in] none,
 *
 ** \param[out] none,
 *
 ** \return RTE_E_OK, 
 * \comments
 *
 */
FUNC(Std_ReturnType, RTE_CODE) Med_u_CBStatusEvt_DEM_DTC_ESP_Yaw_Rate_Invld (Dem_EventStatusExtendedType EventStatusOld, Dem_EventStatusExtendedType EventStatusNew)
{
  /* suppress compiler warnings about unused arguments */
  (void)EventStatusOld;

  #if ((defined MED_SENDFCSTATUS_ENABLED) && (MED_SENDFCSTATUS_ENABLED == STD_ON))
  (void)Med_u_FaultHandling_FCStatus(DemConf_DemEventParameter_DEM_DTC_ESP_Yaw_Rate_Invld,EventStatusNew,0x05, 0x00, 0x00);
  #endif
  
  return RTE_E_OK;
} /* FUNC(Std_ReturnType, RTE_CODE) Med_u_CBStatusEvt_DEM_DTC_ESP_Yaw_Rate_Invld (Dem_EventStatusExtendedType EventStatusOld, Dem_EventStatusExtendedType EventStatusNew) */

/**
 * \functions Med_u_CBStatusEvt_DEM_DTC_EPS_Fault
 *
 * \brief 0xD795F1
 *
 ** \param[in] none,
 *
 ** \param[out] none,
 *
 ** \return RTE_E_OK, 
 * \comments
 *
 */
FUNC(Std_ReturnType, RTE_CODE) Med_u_CBStatusEvt_DEM_DTC_EPS_Fault (Dem_EventStatusExtendedType EventStatusOld, Dem_EventStatusExtendedType EventStatusNew)
{
  /* suppress compiler warnings about unused arguments */
  (void)EventStatusOld;

  #if ((defined MED_SENDFCSTATUS_ENABLED) && (MED_SENDFCSTATUS_ENABLED == STD_ON))
  (void)Med_u_FaultHandling_FCStatus(DemConf_DemEventParameter_DEM_DTC_EPS_Fault,EventStatusNew,0x00, 0x06, 0x00);
  #endif
  
  return RTE_E_OK;
} /* FUNC(Std_ReturnType, RTE_CODE) Med_u_CBStatusEvt_DEM_DTC_EPS_Fault (Dem_EventStatusExtendedType EventStatusOld, Dem_EventStatusExtendedType EventStatusNew) */

/**
 * \functions Med_u_CBStatusEvt_DEM_DTC_EPS_APA_Epas_Fault
 *
 * \brief 0xD796F1
 *
 ** \param[in] none,
 *
 ** \param[out] none,
 *
 ** \return RTE_E_OK, 
 * \comments
 *
 */
FUNC(Std_ReturnType, RTE_CODE) Med_u_CBStatusEvt_DEM_DTC_EPS_APA_Epas_Fault (Dem_EventStatusExtendedType EventStatusOld, Dem_EventStatusExtendedType EventStatusNew)
{
  /* suppress compiler warnings about unused arguments */
  (void)EventStatusOld;

  #if ((defined MED_SENDFCSTATUS_ENABLED) && (MED_SENDFCSTATUS_ENABLED == STD_ON))
  (void)Med_u_FaultHandling_FCStatus(DemConf_DemEventParameter_DEM_DTC_EPS_APA_Epas_Fault,EventStatusNew,0x00, 0x06, 0x00);
  #endif
  
  return RTE_E_OK;
} /* FUNC(Std_ReturnType, RTE_CODE) Med_u_CBStatusEvt_DEM_DTC_EPS_APA_Epas_Fault (Dem_EventStatusExtendedType EventStatusOld, Dem_EventStatusExtendedType EventStatusNew) */

/**
 * \functions Med_u_CBStatusEvt_DEM_DTC_BCM_EmgyLi_Fault
 *
 * \brief 0xD7A0F0
 *
 ** \param[in] none,
 *
 ** \param[out] none,
 *
 ** \return RTE_E_OK, 
 * \comments
 *
 */
FUNC(Std_ReturnType, RTE_CODE) Med_u_CBStatusEvt_DEM_DTC_BCM_EmgyLi_Fault (Dem_EventStatusExtendedType EventStatusOld, Dem_EventStatusExtendedType EventStatusNew)
{
  /* suppress compiler warnings about unused arguments */
  (void)EventStatusOld;

  #if ((defined MED_SENDFCSTATUS_ENABLED) && (MED_SENDFCSTATUS_ENABLED == STD_ON))
  (void)Med_u_FaultHandling_FCStatus(DemConf_DemEventParameter_DEM_DTC_BCM_EmgyLi_Fault,EventStatusNew,0x00, 0x00, 0x00);
  #endif
  
  return RTE_E_OK;
} /* FUNC(Std_ReturnType, RTE_CODE) Med_u_CBStatusEvt_DEM_DTC_BCM_EmgyLi_Fault (Dem_EventStatusExtendedType EventStatusOld, Dem_EventStatusExtendedType EventStatusNew) */

/**
 * \functions Med_u_CBStatusEvt_DEM_DTC_EPS_Steering_wheelvibration_failure
 *
 * \brief 0xD7A1F0
 *
 ** \param[in] none,
 *
 ** \param[out] none,
 *
 ** \return RTE_E_OK, 
 * \comments
 *
 */
FUNC(Std_ReturnType, RTE_CODE) Med_u_CBStatusEvt_DEM_DTC_EPS_Steering_wheelvibration_failure (Dem_EventStatusExtendedType EventStatusOld, Dem_EventStatusExtendedType EventStatusNew)
{
  /* suppress compiler warnings about unused arguments */
  (void)EventStatusOld;

  #if ((defined MED_SENDFCSTATUS_ENABLED) && (MED_SENDFCSTATUS_ENABLED == STD_ON))
  (void)Med_u_FaultHandling_FCStatus(DemConf_DemEventParameter_DEM_DTC_EPS_Steering_wheel_vibration_failure,EventStatusNew,0x00, 0x00, 0x00);
  #endif
  
  return RTE_E_OK;
} /* FUNC(Std_ReturnType, RTE_CODE) Med_u_CBStatusEvt_DEM_DTC_EPS_Steering_wheelvibration_failure (Dem_EventStatusExtendedType EventStatusOld, Dem_EventStatusExtendedType EventStatusNew) */

/**
 * \functions Med_u_CBStatusEvt_DEM_DTC_EPS_Driver_handtorque_invalid
 *
 * \brief 0xD7A2F0
 *
 ** \param[in] none,
 *
 ** \param[out] none,
 *
 ** \return RTE_E_OK, 
 * \comments
 *
 */
FUNC(Std_ReturnType, RTE_CODE) Med_u_CBStatusEvt_DEM_DTC_EPS_Driver_handtorque_invalid (Dem_EventStatusExtendedType EventStatusOld, Dem_EventStatusExtendedType EventStatusNew)
{
  /* suppress compiler warnings about unused arguments */
  (void)EventStatusOld;

  #if ((defined MED_SENDFCSTATUS_ENABLED) && (MED_SENDFCSTATUS_ENABLED == STD_ON))
  (void)Med_u_FaultHandling_FCStatus(DemConf_DemEventParameter_DEM_DTC_EPS_Driver_hand_torque_invalid,EventStatusNew,0x00, 0x00, 0x00);
  #endif
  
  return RTE_E_OK;
} /* FUNC(Std_ReturnType, RTE_CODE) Med_u_CBStatusEvt_DEM_DTC_EPS_Driver_handtorque_invalid (Dem_EventStatusExtendedType EventStatusOld, Dem_EventStatusExtendedType EventStatusNew) */

/**
 * \functions Med_u_CBStatusEvt_DEM_DTC_IP_warning_invalid
 *
 * \brief 0xD7A3F0
 *
 ** \param[in] none,
 *
 ** \param[out] none,
 *
 ** \return RTE_E_OK, 
 * \comments
 *
 */
FUNC(Std_ReturnType, RTE_CODE) Med_u_CBStatusEvt_DEM_DTC_IP_warning_invalid (Dem_EventStatusExtendedType EventStatusOld, Dem_EventStatusExtendedType EventStatusNew)
{
  /* suppress compiler warnings about unused arguments */
  (void)EventStatusOld;

  #if ((defined MED_SENDFCSTATUS_ENABLED) && (MED_SENDFCSTATUS_ENABLED == STD_ON))
  (void)Med_u_FaultHandling_FCStatus(DemConf_DemEventParameter_DEM_DTC_IP_warning_invalid,EventStatusNew,0x00, 0x00, 0x00);
  #endif
  
  return RTE_E_OK;
} /* FUNC(Std_ReturnType, RTE_CODE) Med_u_CBStatusEvt_DEM_DTC_IP_warning_invalid (Dem_EventStatusExtendedType EventStatusOld, Dem_EventStatusExtendedType EventStatusNew) */

/**
 * \functions Med_u_CBStatusEvt_DEM_DTC_VCU_All_Node_Missing
 *
 * \brief 0xD78587
 *
 ** \param[in] none,
 *
 ** \param[out] none,
 *
 ** \return RTE_E_OK, 
 * \comments
 *
 */
FUNC(Std_ReturnType, RTE_CODE) Med_u_CBStatusEvt_DEM_DTC_VCU_All_Node_Missing (Dem_EventStatusExtendedType EventStatusOld, Dem_EventStatusExtendedType EventStatusNew)
{
  /* suppress compiler warnings about unused arguments */
  (void)EventStatusOld;

  #if ((defined MED_SENDFCSTATUS_ENABLED) && (MED_SENDFCSTATUS_ENABLED == STD_ON))
  (void)Med_u_FaultHandling_FCStatus(DemConf_DemEventParameter_DEM_DTC_VCU_All_Node_Missing,EventStatusNew,0x05, 0x0A, 0x00);
  #endif
  
  return RTE_E_OK;
} /* FUNC(Std_ReturnType, RTE_CODE) Med_u_CBStatusEvt_DEM_DTC_VCU_All_Node_Missing (Dem_EventStatusExtendedType EventStatusOld, Dem_EventStatusExtendedType EventStatusNew) */

/**
 * \functions Med_u_CBStatusEvt_DEM_DTC_ESP_All_Node_Missing
 *
 * \brief 0xD78387
 *
 ** \param[in] none,
 *
 ** \param[out] none,
 *
 ** \return RTE_E_OK, 
 * \comments
 *
 */
FUNC(Std_ReturnType, RTE_CODE) Med_u_CBStatusEvt_DEM_DTC_ESP_All_Node_Missing (Dem_EventStatusExtendedType EventStatusOld, Dem_EventStatusExtendedType EventStatusNew)
{
  /* suppress compiler warnings about unused arguments */
  (void)EventStatusOld;

  #if ((defined MED_SENDFCSTATUS_ENABLED) && (MED_SENDFCSTATUS_ENABLED == STD_ON))
  (void)Med_u_FaultHandling_FCStatus(DemConf_DemEventParameter_DEM_DTC_ESP_All_Node_Missing,EventStatusNew,0x05, 0x05, 0x00);
  #endif
  
  return RTE_E_OK;
} /* FUNC(Std_ReturnType, RTE_CODE) Med_u_CBStatusEvt_DEM_DTC_ESP_All_Node_Missing (Dem_EventStatusExtendedType EventStatusOld, Dem_EventStatusExtendedType EventStatusNew) */

/**
 * \functions Med_u_CBStatusEvt_DEM_DTC_EPS_All_Node_Missing
 *
 * \brief 0xD78287
 *
 ** \param[in] none,
 *
 ** \param[out] none,
 *
 ** \return RTE_E_OK, 
 * \comments
 *
 */
FUNC(Std_ReturnType, RTE_CODE) Med_u_CBStatusEvt_DEM_DTC_EPS_All_Node_Missing (Dem_EventStatusExtendedType EventStatusOld, Dem_EventStatusExtendedType EventStatusNew)
{
  /* suppress compiler warnings about unused arguments */
  (void)EventStatusOld;

  #if ((defined MED_SENDFCSTATUS_ENABLED) && (MED_SENDFCSTATUS_ENABLED == STD_ON))
  (void)Med_u_FaultHandling_FCStatus(DemConf_DemEventParameter_DEM_DTC_EPS_All_Node_Missing,EventStatusNew,0x05, 0x06, 0x00);
  #endif
  
  return RTE_E_OK;
} /* FUNC(Std_ReturnType, RTE_CODE) Med_u_CBStatusEvt_DEM_DTC_EPS_All_Node_Missing (Dem_EventStatusExtendedType EventStatusOld, Dem_EventStatusExtendedType EventStatusNew) */

/**
 * \functions Med_u_CBStatusEvt_DEM_DTC_BCM_All_Node_Missing
 *
 * \brief 0xD78487
 *
 ** \param[in] none,
 *
 ** \param[out] none,
 *
 ** \return RTE_E_OK, 
 * \comments
 *
 */
FUNC(Std_ReturnType, RTE_CODE) Med_u_CBStatusEvt_DEM_DTC_BCM_All_Node_Missing (Dem_EventStatusExtendedType EventStatusOld, Dem_EventStatusExtendedType EventStatusNew)
{
  /* suppress compiler warnings about unused arguments */
  (void)EventStatusOld;

  #if ((defined MED_SENDFCSTATUS_ENABLED) && (MED_SENDFCSTATUS_ENABLED == STD_ON))
  (void)Med_u_FaultHandling_FCStatus(DemConf_DemEventParameter_DEM_DTC_BCM_All_Node_Missing,EventStatusNew,0x00, 0x00, 0x00);
  #endif

  return RTE_E_OK;
} /* FUNC(Std_ReturnType, RTE_CODE) Med_u_CBStatusEvt_DEM_DTC_BCM_All_Node_Missing (Dem_EventStatusExtendedType EventStatusOld, Dem_EventStatusExtendedType EventStatusNew) */

/**
 * \functions Med_u_CBStatusEvt_DEM_DTC_IP_node_missing
 *
 * \brief 0xD7A487
 *
 ** \param[in] none,
 *
 ** \param[out] none,
 *
 ** \return RTE_E_OK, 
 * \comments
 *
 */
FUNC(Std_ReturnType, RTE_CODE) Med_u_CBStatusEvt_DEM_DTC_IP_node_missing (Dem_EventStatusExtendedType EventStatusOld, Dem_EventStatusExtendedType EventStatusNew)
{
  /* suppress compiler warnings about unused arguments */
  (void)EventStatusOld;

  #if ((defined MED_SENDFCSTATUS_ENABLED) && (MED_SENDFCSTATUS_ENABLED == STD_ON))
  (void)Med_u_FaultHandling_FCStatus(DemConf_DemEventParameter_DEM_DTC_IP_node_missing,EventStatusNew,0x00, 0x00, 0x00);
  #endif

  return RTE_E_OK;
} /* FUNC(Std_ReturnType, RTE_CODE) Med_u_CBStatusEvt_DEM_DTC_IP_node_missing (Dem_EventStatusExtendedType EventStatusOld, Dem_EventStatusExtendedType EventStatusNew) */

/**
 * \functions Med_u_CBStatusEvt_DEM_DTC_IP_node_missing
 *
 * \brief 0xD7A987
 *
 ** \param[in] none,
 *
 ** \param[out] none,
 *
 ** \return RTE_E_OK, 
 * \comments
 *
 */
FUNC(Std_ReturnType, RTE_CODE) Med_u_CBStatusEvt_DEM_DTC_SRS_All_Node_Missing (Dem_EventStatusExtendedType EventStatusOld, Dem_EventStatusExtendedType EventStatusNew)
{
  /* suppress compiler warnings about unused arguments */
  (void)EventStatusOld;
  
  #if ((defined MED_SENDFCSTATUS_ENABLED) && (MED_SENDFCSTATUS_ENABLED == STD_ON))
  (void)Med_u_FaultHandling_FCStatus(DemConf_DemEventParameter_DEM_DTC_SRS_All_Node_Missing,EventStatusNew,0x00, 0x00, 0x00);
  #endif

  return RTE_E_OK;
} /* FUNC(Std_ReturnType, RTE_CODE) Med_u_CBStatusEvt_DEM_DTC_SRS_All_Node_Missing (Dem_EventStatusExtendedType EventStatusOld, Dem_EventStatusExtendedType EventStatusNew) */

/**
 * \functions Med_u_CBStatusEvt_DEM_DTC_FR_All_Node_Missing
 *
 * \brief 0xD7AA87
 *
 ** \param[in] none,
 *
 ** \param[out] none,
 *
 ** \return RTE_E_OK, 
 * \comments
 *
 */
FUNC(Std_ReturnType, RTE_CODE) Med_u_CBStatusEvt_DEM_DTC_FR_All_Node_Missing (Dem_EventStatusExtendedType EventStatusOld, Dem_EventStatusExtendedType EventStatusNew)
{
  /* suppress compiler warnings about unused arguments */
  (void)EventStatusOld;
  
  #if ((defined MED_SENDFCSTATUS_ENABLED) && (MED_SENDFCSTATUS_ENABLED == STD_ON))
  (void)Med_u_FaultHandling_FCStatus(DemConf_DemEventParameter_DEM_DTC_FR_All_Node_Missing,EventStatusNew,0x00, 0x02, 0x00);
  #endif

  return RTE_E_OK;
} /* FUNC(Std_ReturnType, RTE_CODE) Med_u_CBStatusEvt_DEM_DTC_FR_All_Node_Missing (Dem_EventStatusExtendedType EventStatusOld, Dem_EventStatusExtendedType EventStatusNew) */

/**
 * \functions Med_u_CBStatusEvt_DEM_DTC_FR_All_Node_Missing
 *
 * \brief 0xD7AB87
 *
 ** \param[in] none,
 *
 ** \param[out] none,
 *
 ** \return RTE_E_OK, 
 * \comments
 *
 */
FUNC(Std_ReturnType, RTE_CODE) Med_u_CBStatusEvt_DEM_DTC_ADC_All_Node_Missing (Dem_EventStatusExtendedType EventStatusOld, Dem_EventStatusExtendedType EventStatusNew)
{
  /* suppress compiler warnings about unused arguments */
  (void)EventStatusOld;
  
  #if ((defined MED_SENDFCSTATUS_ENABLED) && (MED_SENDFCSTATUS_ENABLED == STD_ON))
  (void)Med_u_FaultHandling_FCStatus(DemConf_DemEventParameter_DEM_DTC_ADC_All_Node_Missing,EventStatusNew,0x00, 0x00, 0x00);
  #endif
  
  return RTE_E_OK;
} /* FUNC(Std_ReturnType, RTE_CODE) Med_u_CBStatusEvt_DEM_DTC_ADC_All_Node_Missing (Dem_EventStatusExtendedType EventStatusOld, Dem_EventStatusExtendedType EventStatusNew) */

/**
 * \functions Med_u_CBStatusEvt_DEM_DTC_VCU_Message_Alive_Counter_Error
 *
 * \brief 0xD78586
 *
 ** \param[in] none,
 *
 ** \param[out] none,
 *
 ** \return RTE_E_OK, 
 * \comments
 *
 */
FUNC(Std_ReturnType, RTE_CODE) Med_u_CBStatusEvt_DEM_DTC_VCU_Message_Alive_Counter_Error (Dem_EventStatusExtendedType EventStatusOld, Dem_EventStatusExtendedType EventStatusNew)
{
  /* suppress compiler warnings about unused arguments */
  (void)EventStatusOld;

  #if ((defined MED_SENDFCSTATUS_ENABLED) && (MED_SENDFCSTATUS_ENABLED == STD_ON))
  (void)Med_u_FaultHandling_FCStatus(DemConf_DemEventParameter_DEM_DTC_VCU_Message_Alive_Counter_Error,EventStatusNew,0x05, 0x0A, 0x00);
  #endif
  
  return RTE_E_OK;
} /* FUNC(Std_ReturnType, RTE_CODE) Med_u_CBStatusEvt_DEM_DTC_VCU_Message_Alive_Counter_Error (Dem_EventStatusExtendedType EventStatusOld, Dem_EventStatusExtendedType EventStatusNew) */

/**
 * \functions Med_u_CBStatusEvt_DEM_DTC_ESP_Message_Alive_Counter_Error
 *
 * \brief 0xD78386
 *
 ** \param[in] none,
 *
 ** \param[out] none,
 *
 ** \return RTE_E_OK, 
 * \comments
 *
 */
FUNC(Std_ReturnType, RTE_CODE) Med_u_CBStatusEvt_DEM_DTC_ESP_Message_Alive_Counter_Error (Dem_EventStatusExtendedType EventStatusOld, Dem_EventStatusExtendedType EventStatusNew)
{
  /* suppress compiler warnings about unused arguments */
  (void)EventStatusOld;

  #if ((defined MED_SENDFCSTATUS_ENABLED) && (MED_SENDFCSTATUS_ENABLED == STD_ON))
  (void)Med_u_FaultHandling_FCStatus(DemConf_DemEventParameter_DEM_DTC_ESP_Message_Alive_Counter_Error,EventStatusNew,0x05, 0x05, 0x00);
  #endif
  
  return RTE_E_OK;
} /* FUNC(Std_ReturnType, RTE_CODE) Med_u_CBStatusEvt_DEM_DTC_ESP_Message_Alive_Counter_Error (Dem_EventStatusExtendedType EventStatusOld, Dem_EventStatusExtendedType EventStatusNew) */

/**
 * \functions Med_u_CBStatusEvt_DEM_DTC_ESP_Message_Alive_Counter_Error
 *
 * \brief 0xD79086
 *
 ** \param[in] none,
 *
 ** \param[out] none,
 *
 ** \return RTE_E_OK, 
 * \comments
 *
 */
FUNC(Std_ReturnType, RTE_CODE) Med_u_CBStatusEvt_DEM_DTC_EPS_Message_Alive_Counter_Error_10ms (Dem_EventStatusExtendedType EventStatusOld, Dem_EventStatusExtendedType EventStatusNew)
{
  /* suppress compiler warnings about unused arguments */
  (void)EventStatusOld;

  #if ((defined MED_SENDFCSTATUS_ENABLED) && (MED_SENDFCSTATUS_ENABLED == STD_ON))
  (void)Med_u_FaultHandling_FCStatus(DemConf_DemEventParameter_DEM_DTC_EPS_Message_Alive_Counter_Error_10ms,EventStatusNew,0x05, 0x06, 0x00);
  #endif
  
  return RTE_E_OK;
} /* FUNC(Std_ReturnType, RTE_CODE) Med_u_CBStatusEvt_DEM_DTC_EPS_Message_Alive_Counter_Error_10ms (Dem_EventStatusExtendedType EventStatusOld, Dem_EventStatusExtendedType EventStatusNew) */

/**
 * \functions Med_u_CBStatusEvt_DEM_DTC_BCM_Message_Alive_Counter_Error_40ms
 *
 * \brief 0xD78786
 *
 ** \param[in] none,
 *
 ** \param[out] none,
 *
 ** \return RTE_E_OK, 
 * \comments
 *
 */
FUNC(Std_ReturnType, RTE_CODE) Med_u_CBStatusEvt_DEM_DTC_BCM_Message_Alive_Counter_Error_40ms (Dem_EventStatusExtendedType EventStatusOld, Dem_EventStatusExtendedType EventStatusNew)
{
  /* suppress compiler warnings about unused arguments */
  (void)EventStatusOld;

  #if ((defined MED_SENDFCSTATUS_ENABLED) && (MED_SENDFCSTATUS_ENABLED == STD_ON))
  (void)Med_u_FaultHandling_FCStatus(DemConf_DemEventParameter_DEM_DTC_BCM_Message_Alive_Counter_Error_40ms,EventStatusNew,0x00, 0x00, 0x00);
  #endif
  
  return RTE_E_OK;
} /* FUNC(Std_ReturnType, RTE_CODE) Med_u_CBStatusEvt_DEM_DTC_BCM_Message_Alive_Counter_Error_40ms (Dem_EventStatusExtendedType EventStatusOld, Dem_EventStatusExtendedType EventStatusNew) */

/**
 * \functions Med_u_CBStatusEvt_DEM_DTC_IP_message_alive_counter_error
 *
 * \brief 0xD7A486
 *
 ** \param[in] none,
 *
 ** \param[out] none,
 *
 ** \return RTE_E_OK, 
 * \comments
 *
 */
FUNC(Std_ReturnType, RTE_CODE) Med_u_CBStatusEvt_DEM_DTC_IP_message_alive_counter_error (Dem_EventStatusExtendedType EventStatusOld, Dem_EventStatusExtendedType EventStatusNew)
{
  /* suppress compiler warnings about unused arguments */
  (void)EventStatusOld;

  #if ((defined MED_SENDFCSTATUS_ENABLED) && (MED_SENDFCSTATUS_ENABLED == STD_ON))
  (void)Med_u_FaultHandling_FCStatus(DemConf_DemEventParameter_DEM_DTC_IP_message_alive_counter_error,EventStatusNew,0x00, 0x00, 0x00);
  #endif
  
  return RTE_E_OK;
} /* FUNC(Std_ReturnType, RTE_CODE) Med_u_CBStatusEvt_DEM_DTC_IP_message_alive_counter_error (Dem_EventStatusExtendedType EventStatusOld, Dem_EventStatusExtendedType EventStatusNew) */

/**
 * \functions Med_u_CBStatusEvt_DEM_DTC_Front_Radar_Alive_Counter_Error
 *
 * \brief 0xD78986
 *
 ** \param[in] none,
 *
 ** \param[out] none,
 *
 ** \return RTE_E_OK, 
 * \comments
 *
 */
FUNC(Std_ReturnType, RTE_CODE) Med_u_CBStatusEvt_DEM_DTC_Front_Radar_Alive_Counter_Error (Dem_EventStatusExtendedType EventStatusOld, Dem_EventStatusExtendedType EventStatusNew)
{
  /* suppress compiler warnings about unused arguments */
  (void)EventStatusOld;

  #if ((defined MED_SENDFCSTATUS_ENABLED) && (MED_SENDFCSTATUS_ENABLED == STD_ON))
  (void)Med_u_FaultHandling_FCStatus(DemConf_DemEventParameter_DEM_DTC_Front_Radar_Alive_Counter_Error,EventStatusNew,0x00, 0x02,0x00);
  #endif
  
  return RTE_E_OK;
} /* FUNC(Std_ReturnType, RTE_CODE) Med_u_CBStatusEvt_DEM_DTC_Front_Radar_Alive_Counter_Error (Dem_EventStatusExtendedType EventStatusOld, Dem_EventStatusExtendedType EventStatusNew) */

/**
 * \functions Med_u_CBStatusEvt_DEM_DTC_ADC_Message_Alive_Counter_Error
 *
 * \brief 0xD7A686
 *
 ** \param[in] none,
 *
 ** \param[out] none,
 *
 ** \return RTE_E_OK, 
 * \comments
 *
 */
FUNC(Std_ReturnType, RTE_CODE) Med_u_CBStatusEvt_DEM_DTC_ADC_Message_Alive_Counter_Error (Dem_EventStatusExtendedType EventStatusOld, Dem_EventStatusExtendedType EventStatusNew)
{
  /* suppress compiler warnings about unused arguments */
  (void)EventStatusOld;

  #if ((defined MED_SENDFCSTATUS_ENABLED) && (MED_SENDFCSTATUS_ENABLED == STD_ON))
  (void)Med_u_FaultHandling_FCStatus(DemConf_DemEventParameter_DEM_DTC_ADC_Message_Alive_Counter_Error,EventStatusNew,0x00, 0x00, 0x00);
  #endif
  
  return RTE_E_OK;
} /* FUNC(Std_ReturnType, RTE_CODE) Med_u_CBStatusEvt_DEM_DTC_ADC_Message_Alive_Counter_Error (Dem_EventStatusExtendedType EventStatusOld, Dem_EventStatusExtendedType EventStatusNew) */

/**
 * \functions Med_u_CBStatusEvt_DEM_DTC_RLR_Message_Alive_Counter_Error
 *
 * \brief 0xD7A786
 *
 ** \param[in] none,
 *
 ** \param[out] none,
 *
 ** \return RTE_E_OK, 
 * \comments
 *
 */
FUNC(Std_ReturnType, RTE_CODE) Med_u_CBStatusEvt_DEM_DTC_RLR_Message_Alive_Counter_Error (Dem_EventStatusExtendedType EventStatusOld, Dem_EventStatusExtendedType EventStatusNew)
{
  /* suppress compiler warnings about unused arguments */
  (void)EventStatusOld;
  
  #if ((defined MED_SENDFCSTATUS_ENABLED) && (MED_SENDFCSTATUS_ENABLED == STD_ON))
  (void)Med_u_FaultHandling_FCStatus(DemConf_DemEventParameter_DEM_DTC_RLR_Message_Alive_Counter_Error,EventStatusNew,0x00, 0x00, 0x00);
  #endif

  return RTE_E_OK;
} /* FUNC(Std_ReturnType, RTE_CODE) Med_u_CBStatusEvt_DEM_DTC_RLR_Message_Alive_Counter_Error (Dem_EventStatusExtendedType EventStatusOld, Dem_EventStatusExtendedType EventStatusNew) */

/**
 * \functions Med_u_CBStatusEvt_DEM_DTC_SRS_Message_Alive_Counter_Error
 *
 * \brief 0xD7A986
 *
 ** \param[in] none,
 *
 ** \param[out] none,
 *
 ** \return RTE_E_OK, 
 * \comments
 *
 */
FUNC(Std_ReturnType, RTE_CODE) Med_u_CBStatusEvt_DEM_DTC_SRS_Message_Alive_Counter_Error (Dem_EventStatusExtendedType EventStatusOld, Dem_EventStatusExtendedType EventStatusNew)
{
  /* suppress compiler warnings about unused arguments */
  (void)EventStatusOld;
  
  #if ((defined MED_SENDFCSTATUS_ENABLED) && (MED_SENDFCSTATUS_ENABLED == STD_ON))
  (void)Med_u_FaultHandling_FCStatus(DemConf_DemEventParameter_DEM_DTC_SRS_Message_Alive_Counter_Error,EventStatusNew,0x00, 0x00, 0x00);
  #endif
  
  return RTE_E_OK;
} /* FUNC(Std_ReturnType, RTE_CODE) Med_u_CBStatusEvt_DEM_DTC_SRS_Message_Alive_Counter_Error (Dem_EventStatusExtendedType EventStatusOld, Dem_EventStatusExtendedType EventStatusNew) */

/**
 * \functions Med_u_CBStatusEvt_DEM_VMON_BATT_HIGH
 *
 * \brief 0xA20017
 *
 ** \param[in] none,
 *
 ** \param[out] none,
 *
 ** \return RTE_E_OK, 
 * \comments
 *
 */
FUNC(Std_ReturnType, RTE_CODE) Med_u_CBStatusEvt_DEM_VMON_BATT_HIGH (Dem_EventStatusExtendedType EventStatusOld, Dem_EventStatusExtendedType EventStatusNew)
{
  /* suppress compiler warnings about unused arguments */
  (void)EventStatusOld;
  
   #if ((defined MED_SENDFCSTATUS_ENABLED) && (MED_SENDFCSTATUS_ENABLED == STD_ON))
  (void)Med_u_FaultHandling_FCStatus(DemConf_DemEventParameter_DEM_VMON_BATT_HIGH,EventStatusNew,0x03, 0x0A, 0x00);
  #endif
  
  return RTE_E_OK;
} /* FUNC(Std_ReturnType, RTE_CODE) Med_u_CBStatusEvt_DEM_VMON_BATT_HIGH (Dem_EventStatusExtendedType EventStatusOld, Dem_EventStatusExtendedType EventStatusNew) */

/**
 * \functions Med_u_CBStatusEvt_DEM_VMON_BATT_LOW
 *
 * \brief 0xA20016
 *
 ** \param[in] none,
 *
 ** \param[out] none,
 *
 ** \return RTE_E_OK, 
 * \comments
 *
 */
FUNC(Std_ReturnType, RTE_CODE) Med_u_CBStatusEvt_DEM_VMON_BATT_LOW (Dem_EventStatusExtendedType EventStatusOld, Dem_EventStatusExtendedType EventStatusNew)
{
  /* suppress compiler warnings about unused arguments */
  (void)EventStatusOld;
  
  #if ((defined MED_SENDFCSTATUS_ENABLED) && (MED_SENDFCSTATUS_ENABLED == STD_ON))
  (void)Med_u_FaultHandling_FCStatus(DemConf_DemEventParameter_DEM_VMON_BATT_LOW,EventStatusNew,0x03, 0x0A, 0x00);
  #endif
  
  return RTE_E_OK;
} /* FUNC(Std_ReturnType, RTE_CODE) Med_u_CBStatusEvt_DEM_VMON_BATT_LOW (Dem_EventStatusExtendedType EventStatusOld, Dem_EventStatusExtendedType EventStatusNew) */

/**
 * \functions Med_u_CBStatusEvt_DEM_DTC_MCU_TEMP_INITIAL_HIGH
 *
 * \brief 0xA20327
 *
 ** \param[in] none,
 *
 ** \param[out] none,
 *
 ** \return RTE_E_OK, 
 * \comments
 *
 */
FUNC(Std_ReturnType, RTE_CODE) Med_u_CBStatusEvt_DEM_DTC_MCU_TEMP_INITIAL_HIGH (Dem_EventStatusExtendedType EventStatusOld, Dem_EventStatusExtendedType EventStatusNew)
{
  /* suppress compiler warnings about unused arguments */
  (void)EventStatusOld;

  #if ((defined MED_SENDFCSTATUS_ENABLED) && (MED_SENDFCSTATUS_ENABLED == STD_ON))
  (void)Med_u_FaultHandling_FCStatus(DemConf_DemEventParameter_DEM_DTC_MCU_TEMP_INITIAL_HIGH,EventStatusNew,0x03, 0x01, 0x00);
  #endif

  return RTE_E_OK;
} /* FUNC(Std_ReturnType, RTE_CODE) Med_u_CBStatusEvt_DEM_DTC_MCU_TEMP_INITIAL_HIGH (Dem_EventStatusExtendedType EventStatusOld, Dem_EventStatusExtendedType EventStatusNew) */

/**
 * \functions Med_u_CBStatusEvt_DEM_MCU_TEMP_EXT_HIGH
 *
 * \brief 0xA20325
 *
 ** \param[in] none,
 *
 ** \param[out] none,
 *
 ** \return RTE_E_OK, 
 * \comments
 *
 */
FUNC(Std_ReturnType, RTE_CODE) Med_u_CBStatusEvt_DEM_MCU_TEMP_EXT_HIGH (Dem_EventStatusExtendedType EventStatusOld, Dem_EventStatusExtendedType EventStatusNew)
{
  /* suppress compiler warnings about unused arguments */
  (void)EventStatusOld;
  
  #if ((defined MED_SENDFCSTATUS_ENABLED) && (MED_SENDFCSTATUS_ENABLED == STD_ON))
  (void)Med_u_FaultHandling_FCStatus(DemConf_DemEventParameter_DEM_MCU_TEMP_EXT_HIGH,EventStatusNew,0x03, 0x01, 0x00);
  #endif
  
  return RTE_E_OK;
} /* FUNC(Std_ReturnType, RTE_CODE) Med_u_CBStatusEvt_DEM_MCU_TEMP_EXT_HIGH (Dem_EventStatusExtendedType EventStatusOld, Dem_EventStatusExtendedType EventStatusNew) */

/**
 * \functions Med_u_CBStatusEvt_DEM_MCU_TEMP_EXT_LOW
 *
 * \brief 0xA20326
 *
 ** \param[in] none,
 *
 ** \param[out] none,
 *
 ** \return RTE_E_OK, 
 * \comments
 *
 */
FUNC(Std_ReturnType, RTE_CODE) Med_u_CBStatusEvt_DEM_MCU_TEMP_EXT_LOW (Dem_EventStatusExtendedType EventStatusOld, Dem_EventStatusExtendedType EventStatusNew)
{
  /* suppress compiler warnings about unused arguments */
  (void)EventStatusOld;
  
  #if ((defined MED_SENDFCSTATUS_ENABLED) && (MED_SENDFCSTATUS_ENABLED == STD_ON))
  (void)Med_u_FaultHandling_FCStatus(DemConf_DemEventParameter_DEM_MCU_TEMP_EXT_LOW,EventStatusNew,0x03, 0x01, 0x00);
  #endif
  
  return RTE_E_OK;
} /* FUNC(Std_ReturnType, RTE_CODE) Med_u_CBStatusEvt_DEM_MCU_TEMP_EXT_LOW (Dem_EventStatusExtendedType EventStatusOld, Dem_EventStatusExtendedType EventStatusNew) */

/**
 * \functions Med_u_CBStatusEvt_DEM_CAMERA_CALIBRATION_FAILURE
 *
 * \brief 0xA20AE1
 *
 ** \param[in] none,
 *
 ** \param[out] none,
 *
 ** \return RTE_E_OK, 
 * \comments
 *
 */
FUNC(Std_ReturnType, RTE_CODE) Med_u_CBStatusEvt_DEM_CAMERA_CALIBRATION_FAILURE (Dem_EventStatusExtendedType EventStatusOld, Dem_EventStatusExtendedType EventStatusNew)
{
  /* suppress compiler warnings about unused arguments */
  (void)EventStatusOld;

  #if ((defined MED_SENDFCSTATUS_ENABLED) && (MED_SENDFCSTATUS_ENABLED == STD_ON))
   (void)Med_u_FaultHandling_FCStatus(DemConf_DemEventParameter_DEM_CAMERA_CALIBRATION_FAILURE,EventStatusNew,0x04, 0x01,0x03);
  #endif
  
  return RTE_E_OK;
} /* FUNC(Std_ReturnType, RTE_CODE) Med_u_CBStatusEvt_DEM_CAMERA_CALIBRATION_FAILURE (Dem_EventStatusExtendedType EventStatusOld, Dem_EventStatusExtendedType EventStatusNew) */

/**
 * \functions Med_u_CBStatusEvt_DEM_CAMERA_ONLINE_CALIBRATION_FAILURE
 *
 * \brief 0xA20EE1
 *
 ** \param[in] none,
 *
 ** \param[out] none,
 *
 ** \return RTE_E_OK, 
 * \comments
 *
 */
FUNC(Std_ReturnType, RTE_CODE) Med_u_CBStatusEvt_DEM_CAMERA_ONLINE_CALIBRATION_FAILURE (Dem_EventStatusExtendedType EventStatusOld, Dem_EventStatusExtendedType EventStatusNew)
{
  /* suppress compiler warnings about unused arguments */
  (void)EventStatusOld;

  #if ((defined MED_SENDFCSTATUS_ENABLED) && (MED_SENDFCSTATUS_ENABLED == STD_ON))
  (void)Med_u_FaultHandling_FCStatus(DemConf_DemEventParameter_DEM_CAMERA_ONLINE_CALIBRATION_FAILURE,EventStatusNew,0x04, 0x01,0x03);
  #endif
  
  return RTE_E_OK;
} /* FUNC(Std_ReturnType, RTE_CODE) Med_u_CBStatusEvt_DEM_CAMERA_ONLINE_CALIBRATION_FAILURE (Dem_EventStatusExtendedType EventStatusOld, Dem_EventStatusExtendedType EventStatusNew) */

/**
 * \functions Med_u_CBStatusEvt_DEM_DTC_J3_Camera_Blockage
 *
 * \brief 0xA20BE1
 *
 ** \param[in] none,
 *
 ** \param[out] none,
 *
 ** \return RTE_E_OK, 
 * \comments
 *
 */
FUNC(Std_ReturnType, RTE_CODE) Med_u_CBStatusEvt_DEM_DTC_J3_Camera_Blockage (Dem_EventStatusExtendedType EventStatusOld, Dem_EventStatusExtendedType EventStatusNew)
{
  /* suppress compiler warnings about unused arguments */
  (void)EventStatusOld;

  #if ((defined MED_SENDFCSTATUS_ENABLED) && (MED_SENDFCSTATUS_ENABLED == STD_ON))
  (void)Med_u_FaultHandling_FCStatus(DemConf_DemEventParameter_DEM_DTC_J3_Camera_Blockage,EventStatusNew,0x01, 0x01,0x00);
  #endif
  
  return RTE_E_OK;
} /* FUNC(Std_ReturnType, RTE_CODE) Med_u_CBStatusEvt_DEM_DTC_J3_Camera_Blockage (Dem_EventStatusExtendedType EventStatusOld, Dem_EventStatusExtendedType EventStatusNew) */

/**
 * \functions Med_u_CBStatusEvt_DEM_DTC_Fradar_not_calibration_or_blockage
 *
 * \brief 0xD78910
 *
 ** \param[in] none,
 *
 ** \param[out] none,
 *
 ** \return RTE_E_OK, 
 * \comments
 *
 */
FUNC(Std_ReturnType, RTE_CODE) Med_u_CBStatusEvt_DEM_DTC_Fradar_not_calibration_or_blockage (Dem_EventStatusExtendedType EventStatusOld, Dem_EventStatusExtendedType EventStatusNew)
{
  /* suppress compiler warnings about unused arguments */
  (void)EventStatusOld;

  #if ((defined MED_SENDFCSTATUS_ENABLED) && (MED_SENDFCSTATUS_ENABLED == STD_ON))
  (void)Med_u_FaultHandling_FCStatus(DemConf_DemEventParameter_DEM_DTC_Fradar_not_calibration_or_blockage,EventStatusNew,0x00, 0x02, 0x00);
  #endif
  
  return RTE_E_OK;
} /* FUNC(Std_ReturnType, RTE_CODE) Med_u_CBStatusEvt_DEM_DTC_Fradar_not_calibration_or_blockage (Dem_EventStatusExtendedType EventStatusOld, Dem_EventStatusExtendedType EventStatusNew) */

/**
 * \functions Med_u_CBStatusEvt_DEM_DTC_Fradar_hardware_error
 *
 * \brief 0xD789E0
 *
 ** \param[in] none,
 *
 ** \param[out] none,
 *
 ** \return RTE_E_OK, 
 * \comments
 *
 */
FUNC(Std_ReturnType, RTE_CODE) Med_u_CBStatusEvt_DEM_DTC_Fradar_hardware_error (Dem_EventStatusExtendedType EventStatusOld, Dem_EventStatusExtendedType EventStatusNew)
{
  /* suppress compiler warnings about unused arguments */
  (void)EventStatusOld;
  
  #if ((defined MED_SENDFCSTATUS_ENABLED) && (MED_SENDFCSTATUS_ENABLED == STD_ON))
  (void)Med_u_FaultHandling_FCStatus(DemConf_DemEventParameter_DEM_DTC_Fradar_hardware_error,EventStatusNew,0x00, 0x02, 0x00);
  #endif
  
  return RTE_E_OK;
} /* FUNC(Std_ReturnType, RTE_CODE) Med_u_CBStatusEvt_DEM_DTC_Fradar_hardware_error (Dem_EventStatusExtendedType EventStatusOld, Dem_EventStatusExtendedType EventStatusNew) */

/**
 * \functions Med_u_CBStatusEvt_DEM_DTC_Private_CAN_Bus_Off
 *
 * \brief 0xD78088
 *
 ** \param[in] none,
 *
 ** \param[out] none,
 *
 ** \return RTE_E_OK, 
 * \comments
 *
 */
FUNC(Std_ReturnType, RTE_CODE) Med_u_CBStatusEvt_DEM_DTC_Private_CAN_Bus_Off (Dem_EventStatusExtendedType EventStatusOld, Dem_EventStatusExtendedType EventStatusNew)
{
  /* suppress compiler warnings about unused arguments */
  (void)EventStatusOld;
  
  #if ((defined MED_SENDFCSTATUS_ENABLED) && (MED_SENDFCSTATUS_ENABLED == STD_ON))
  (void)Med_u_FaultHandling_FCStatus(DemConf_DemEventParameter_DEM_DTC_Private_CAN_Bus_Off,EventStatusNew,0x03, 0x0A, 0x00);
  #endif
  
  return RTE_E_OK;
} /* FUNC(Std_ReturnType, RTE_CODE) Med_u_CBStatusEvt_DEM_DTC_Private_CAN_Bus_Off (Dem_EventStatusExtendedType EventStatusOld, Dem_EventStatusExtendedType EventStatusNew) */

/**
 * \functions Med_u_CBStatusEvt_DEM_DTC_Public_CAN_Bus_Off
 *
 * \brief 0xD78188
 *
 ** \param[in] none,
 *
 ** \param[out] none,
 *
 ** \return RTE_E_OK, 
 * \comments
 *
 */
FUNC(Std_ReturnType, RTE_CODE) Med_u_CBStatusEvt_DEM_DTC_Public_CAN_Bus_Off (Dem_EventStatusExtendedType EventStatusOld, Dem_EventStatusExtendedType EventStatusNew)
{
  /* suppress compiler warnings about unused arguments */
  (void)EventStatusOld;
  
  #if ((defined MED_SENDFCSTATUS_ENABLED) && (MED_SENDFCSTATUS_ENABLED == STD_ON))
  (void)Med_u_FaultHandling_FCStatus(DemConf_DemEventParameter_DEM_DTC_Public_CAN_Bus_Off,EventStatusNew,0x03, 0x0A, 0x00);
  #endif
  
  return RTE_E_OK;
} /* FUNC(Std_ReturnType, RTE_CODE) Med_u_CBStatusEvt_DEM_DTC_Public_CAN_Bus_Off (Dem_EventStatusExtendedType EventStatusOld, Dem_EventStatusExtendedType EventStatusNew) */

/**
 * \functions Med_u_CBStatusEvt_DEM_DTC_Public_CAN_Bus_Off
 *
 * \brief 0xA2068E
 *
 ** \param[in] none,
 *
 ** \param[out] none,
 *
 ** \return RTE_E_OK, 
 * \comments
 *
 */
FUNC(Std_ReturnType, RTE_CODE) Med_u_CBStatusEvt_SPI_E_HARDWARE_ERROR (Dem_EventStatusExtendedType EventStatusOld, Dem_EventStatusExtendedType EventStatusNew)
{
  /* suppress compiler warnings about unused arguments */
  (void)EventStatusOld;
  
  #if ((defined MED_SENDFCSTATUS_ENABLED) && (MED_SENDFCSTATUS_ENABLED == STD_ON))
  (void)Med_u_FaultHandling_FCStatus(DemConf_DemEventParameter_SPI_E_HARDWARE_ERROR,EventStatusNew,0x03, 0x01, 0x00);
  #endif
  
  return RTE_E_OK;
} /* FUNC(Std_ReturnType, RTE_CODE) Med_u_CBStatusEvt_SPI_E_HARDWARE_ERROR (Dem_EventStatusExtendedType EventStatusOld, Dem_EventStatusExtendedType EventStatusNew) */

/**
 * \functions Med_u_CBStatusEvt_DEM_DTC_J3_Time_Sync_Error
 *
 * \brief 0xA210E1
 *
 ** \param[in] none,
 *
 ** \param[out] none,
 *
 ** \return RTE_E_OK, 
 * \comments
 *
 */
FUNC(Std_ReturnType, RTE_CODE) Med_u_CBStatusEvt_DEM_DTC_J3_Time_Sync_Error (Dem_EventStatusExtendedType EventStatusOld, Dem_EventStatusExtendedType EventStatusNew)
{
  /* suppress compiler warnings about unused arguments */
  (void)EventStatusOld;

  #if ((defined MED_SENDFCSTATUS_ENABLED) && (MED_SENDFCSTATUS_ENABLED == STD_ON))
  (void)Med_u_FaultHandling_FCStatus(DemConf_DemEventParameter_DEM_DTC_J3_Time_Sync_Error,EventStatusNew,0x03, 0x01, 0x00);
  #endif
  
  return RTE_E_OK;
} /* FUNC(Std_ReturnType, RTE_CODE) Med_u_CBStatusEvt_DEM_DTC_J3_Time_Sync_Error (Dem_EventStatusExtendedType EventStatusOld, Dem_EventStatusExtendedType EventStatusNew) */

/**
 * \functions Med_u_CBStatusEvt_DEM_J3_SYS_KERNEL_SW
 *
 * \brief 0xA205E1
 *
 ** \param[in] none,
 *
 ** \param[out] none,
 *
 ** \return RTE_E_OK, 
 * \comments
 *
 */
FUNC(Std_ReturnType, RTE_CODE) Med_u_CBStatusEvt_DEM_J3_SYS_KERNEL_SW (Dem_EventStatusExtendedType EventStatusOld, Dem_EventStatusExtendedType EventStatusNew)
{
  /* suppress compiler warnings about unused arguments */
  (void)EventStatusOld;

  #if ((defined MED_SENDFCSTATUS_ENABLED) && (MED_SENDFCSTATUS_ENABLED == STD_ON))
  (void)Med_u_FaultHandling_FCStatus(DemConf_DemEventParameter_DEM_J3_SYS_KERNEL_SW,EventStatusNew,0x03, 0x01, 0x00);
  #endif
  
  return RTE_E_OK;
} /* FUNC(Std_ReturnType, RTE_CODE) Med_u_CBStatusEvt_DEM_J3_SYS_KERNEL_SW (Dem_EventStatusExtendedType EventStatusOld, Dem_EventStatusExtendedType EventStatusNew) */

/**
 * \functions Med_u_CBStatusEvt_DEM_DTC_J3_SOC_System_Service_Error
 *
 * \brief 0xA206E1
 *
 ** \param[in] none,
 *
 ** \param[out] none,
 *
 ** \return RTE_E_OK, 
 * \comments
 *
 */
FUNC(Std_ReturnType, RTE_CODE) Med_u_CBStatusEvt_DEM_DTC_J3_SOC_System_Service_Error (Dem_EventStatusExtendedType EventStatusOld, Dem_EventStatusExtendedType EventStatusNew)
{
  /* suppress compiler warnings about unused arguments */
  (void)EventStatusOld;

  #if ((defined MED_SENDFCSTATUS_ENABLED) && (MED_SENDFCSTATUS_ENABLED == STD_ON))
  (void)Med_u_FaultHandling_FCStatus(DemConf_DemEventParameter_DEM_DTC_J3_SOC_System_Service_Error,EventStatusNew,0x03, 0x01, 0x00);
  #endif
  
  return RTE_E_OK;
} /* FUNC(Std_ReturnType, RTE_CODE) Med_u_CBStatusEvt_DEM_DTC_J3_SOC_System_Service_Error (Dem_EventStatusExtendedType EventStatusOld, Dem_EventStatusExtendedType EventStatusNew) */

/**
 * \functions Med_u_CBStatusEvt_DEM_DTC_J3_Camera_Error
 *
 * \brief 0xA207E1
 *
 ** \param[in] none,
 *
 ** \param[out] none,
 *
 ** \return RTE_E_OK, 
 * \comments
 *
 */
FUNC(Std_ReturnType, RTE_CODE) Med_u_CBStatusEvt_DEM_DTC_J3_Camera_Error (Dem_EventStatusExtendedType EventStatusOld, Dem_EventStatusExtendedType EventStatusNew)
{
  /* suppress compiler warnings about unused arguments */
  (void)EventStatusOld;

  #if ((defined MED_SENDFCSTATUS_ENABLED) && (MED_SENDFCSTATUS_ENABLED == STD_ON))
  (void)Med_u_FaultHandling_FCStatus(DemConf_DemEventParameter_DEM_DTC_J3_Camera_Error,EventStatusNew,0x03, 0x01, 0x00);
  #endif
  
  return RTE_E_OK;
} /* FUNC(Std_ReturnType, RTE_CODE) Med_u_CBStatusEvt_DEM_DTC_J3_Camera_Error (Dem_EventStatusExtendedType EventStatusOld, Dem_EventStatusExtendedType EventStatusNew) */

/**
 * \functions Med_u_CBStatusEvt_DEM_DTC_J3_SOC_Perception_Error
 *
 * \brief 0xA208E1
 *
 ** \param[in] none,
 *
 ** \param[out] none,
 *
 ** \return RTE_E_OK, 
 * \comments
 *
 */
FUNC(Std_ReturnType, RTE_CODE) Med_u_CBStatusEvt_DEM_DTC_J3_SOC_Perception_Error (Dem_EventStatusExtendedType EventStatusOld, Dem_EventStatusExtendedType EventStatusNew)
{
  /* suppress compiler warnings about unused arguments */
  (void)EventStatusOld;

  #if ((defined MED_SENDFCSTATUS_ENABLED) && (MED_SENDFCSTATUS_ENABLED == STD_ON))
  (void)Med_u_FaultHandling_FCStatus(DemConf_DemEventParameter_DEM_DTC_J3_SOC_Perception_Error,EventStatusNew,0x03, 0x01, 0x00);
  #endif
  
  return RTE_E_OK;
} /* FUNC(Std_ReturnType, RTE_CODE) Med_u_CBStatusEvt_DEM_DTC_J3_SOC_Perception_Error (Dem_EventStatusExtendedType EventStatusOld, Dem_EventStatusExtendedType EventStatusNew) */


/**
 * \functions Med_u_CBStatusEvt_DEM_DTC_J3_SOC_Safetylib_Error
 *
 * \brief 0xA204E0
 *
 ** \param[in] none,
 *
 ** \param[out] none,
 *
 ** \return RTE_E_OK, 
 * \comments
 *
 */
FUNC(Std_ReturnType, RTE_CODE) Med_u_CBStatusEvt_DEM_DTC_J3_SOC_Safetylib_Error (Dem_EventStatusExtendedType EventStatusOld, Dem_EventStatusExtendedType EventStatusNew)
{
  /* suppress compiler warnings about unused arguments */
  (void)EventStatusOld;

  #if ((defined MED_SENDFCSTATUS_ENABLED) && (MED_SENDFCSTATUS_ENABLED == STD_ON))
  (void)Med_u_FaultHandling_FCStatus(DemConf_DemEventParameter_DEM_DTC_J3_SOC_Safetylib_Error,EventStatusNew,0x03, 0x01, 0x00);
  #endif
  
  return RTE_E_OK;
} /* FUNC(Std_ReturnType, RTE_CODE) Med_u_CBStatusEvt_DEM_DTC_J3_SOC_Safetylib_Error (Dem_EventStatusExtendedType EventStatusOld, Dem_EventStatusExtendedType EventStatusNew) */

/**
 * \functions Med_u_CBStatusEvt_DEM_DTC_J3_SOC_CPU_Error_PWM_Missing
 *
 * \brief 0xA209E1
 *
 ** \param[in] none,
 *
 ** \param[out] none,
 *
 ** \return RTE_E_OK, 
 * \comments
 *
 */
FUNC(Std_ReturnType, RTE_CODE) Med_u_CBStatusEvt_DEM_DTC_J3_SOC_CPU_Error_PWM_Missing (Dem_EventStatusExtendedType EventStatusOld, Dem_EventStatusExtendedType EventStatusNew)
{
  /* suppress compiler warnings about unused arguments */
  (void)EventStatusOld;

  #if ((defined MED_SENDFCSTATUS_ENABLED) && (MED_SENDFCSTATUS_ENABLED == STD_ON))
  (void)Med_u_FaultHandling_FCStatus(DemConf_DemEventParameter_DEM_DTC_J3_SOC_CPU_Error_PWM_Missing,EventStatusNew,0x03, 0x01, 0x00);
  #endif
  
  return RTE_E_OK;
} /* FUNC(Std_ReturnType, RTE_CODE) Med_u_CBStatusEvt_DEM_DTC_J3_SOC_CPU_Error_PWM_Missing (Dem_EventStatusExtendedType EventStatusOld, Dem_EventStatusExtendedType EventStatusNew) */

/**
 * \functions Med_u_CBStatusEvt_DEM_SOCJ3_TEMP_EXT_HIGH
 *
 * \brief 0xA20427
 *
 ** \param[in] none,
 *
 ** \param[out] none,
 *
 ** \return RTE_E_OK, 
 * \comments
 *
 */
FUNC(Std_ReturnType, RTE_CODE) Med_u_CBStatusEvt_DEM_SOCJ3_TEMP_EXT_HIGH (Dem_EventStatusExtendedType EventStatusOld, Dem_EventStatusExtendedType EventStatusNew)
{
  /* suppress compiler warnings about unused arguments */
  (void)EventStatusOld;

  #if ((defined MED_SENDFCSTATUS_ENABLED) && (MED_SENDFCSTATUS_ENABLED == STD_ON))
  (void)Med_u_FaultHandling_FCStatus(DemConf_DemEventParameter_DEM_SOCJ3_TEMP_EXT_HIGH,EventStatusNew,0x03, 0x01, 0x00);
  #endif
  
  return RTE_E_OK;
} /* FUNC(Std_ReturnType, RTE_CODE) Med_u_CBStatusEvt_DEM_SOCJ3_TEMP_EXT_HIGH (Dem_EventStatusExtendedType EventStatusOld, Dem_EventStatusExtendedType EventStatusNew) */


/**
 * \functions Med_u_CBStatusEvt_DEM_SOCJ3_TEMP_EXT_HIGH
 *
 * \brief 0xD79086
 *
 ** \param[in] none,
 *
 ** \param[out] none,
 *
 ** \return RTE_E_OK, 
 * \comments
 *
 */
FUNC(Std_ReturnType, RTE_CODE) Med_u_CBStatusEvt_DEM_DTC_EPS_Message_Alive_Counter_Error_20ms (Dem_EventStatusExtendedType EventStatusOld, Dem_EventStatusExtendedType EventStatusNew)
{
  /* suppress compiler warnings about unused arguments */
  (void)EventStatusOld;

#if ((defined MED_SENDFCSTATUS_ENABLED) && (MED_SENDFCSTATUS_ENABLED == STD_ON))
  (void)Med_u_FaultHandling_FCStatus(DemConf_DemEventParameter_DEM_DTC_EPS_Message_Alive_Counter_Error_20ms,EventStatusNew,0x05, 0x06, 0x00);
#endif
  
  return RTE_E_OK;

} /* FUNC(Std_ReturnType, RTE_CODE) Med_u_CBStatusEvt_DEM_DTC_EPS_Message_Alive_Counter_Error_20ms (Dem_EventStatusExtendedType EventStatusOld, Dem_EventStatusExtendedType EventStatusNew) */



/**
 * \functions Med_u_CBStatusEvt_DEM_DTC_ESP_Message_Alive_Counter_Error_100ms
 *
 * \brief 0xD78386
 *
 ** \param[in] none,
 *
 ** \param[out] none,
 *
 ** \return RTE_E_OK, 
 * \comments
 *
 */
FUNC(Std_ReturnType, RTE_CODE) Med_u_CBStatusEvt_DEM_DTC_ESP_Message_Alive_Counter_Error_100ms (Dem_EventStatusExtendedType EventStatusOld, Dem_EventStatusExtendedType EventStatusNew)
{
  /* suppress compiler warnings about unused arguments */
  (void)EventStatusOld;

#if ((defined MED_SENDFCSTATUS_ENABLED) && (MED_SENDFCSTATUS_ENABLED == STD_ON))
  (void)Med_u_FaultHandling_FCStatus(DemConf_DemEventParameter_DEM_DTC_ESP_Message_Alive_Counter_Error_100ms,EventStatusNew,0x05, 0x05, 0x00);
#endif
  
  return RTE_E_OK;

} /* FUNC(Std_ReturnType, RTE_CODE) Med_u_CBStatusEvt_DEM_DTC_ESP_Message_Alive_Counter_Error_100ms (Dem_EventStatusExtendedType EventStatusOld, Dem_EventStatusExtendedType EventStatusNew) */



/*==================[internal function definitions]=========================*/
/**
 * \functions Med_u_FaultHandling_FCStatus
 *
 * \brief This function only use for if trigger event shall be fill in 
 * camerafailure and AEBTextinfo in buffer.
 *
 ** \param[in] EventId,
 *
 ** \param[in] EventStatus,
 *
 ** \param[in] CameraFailureStatus,
 *
 ** \param[in] AEBTextInfoStatus,
 *
 ** \param[out] none,
 *
 ** \return RTE_E_OK, 
 * \comments
 *
 */
#if ((defined MED_SENDFCSTATUS_ENABLED) && (MED_SENDFCSTATUS_ENABLED == STD_ON))
static FUNC(Std_ReturnType, RTE_CODE)Med_u_FaultHandling_FCStatus(Dem_EventIdType EventId, Dem_EventStatusType EventStatus, uint8  CameraFailureStatus, uint8 AEBTextInfoStatus, uint8 CameraCalibrationStatus)
{
    if((EventStatus & DEM_UDS_STATUS_TF) == DEM_UDS_STATUS_TF)
	{
		Med_a_CameraFailureStatus[EventId] = CameraFailureStatus;
		Med_a_AEBTextInfoStatus[EventId] = AEBTextInfoStatus; 
		Med_a_CameraCalibrationStatus[EventId] = CameraCalibrationStatus;
	}
	else
	{
		Med_a_CameraFailureStatus[EventId] = 0x00;
		Med_a_AEBTextInfoStatus[EventId] = 0x00;
		Med_a_CameraCalibrationStatus[EventId] = 0x00;
	}

	return RTE_E_OK;
}
#endif

/**
 * \functions Med_u_FaultHandling_FCStatus_TX
 *
 * \brief This function only use to Send information to CAN.
 *
 ** \param[in] EventId,
 *
 ** \param[in] EventStatus,
 *
 ** \param[in] CameraFailureStatus,
 *
 ** \param[in] AEBTextInfoStatus,
 *
 ** \param[out] none,
 *
 ** \return RTE_E_OK, 
 * \comments
 *
 */
 #if ((defined MED_SENDFCSTATUS_ENABLED) && (MED_SENDFCSTATUS_ENABLED == STD_ON))
static FUNC(Std_ReturnType, RTE_CODE)Med_u_FaultHandling_FCStatus_TX(void)
{
    uint8 a_CameraFailureStatus_Prioritybuffer[DEM_NUMBER_OF_EVENTS]={0};
	uint8 a_AEBTextInfoStatus_Prioritybuffer[DEM_NUMBER_OF_EVENTS]={0};
    uint8 ui8_CameraFailureStatus_Max = 0;
	uint8 ui8_AEBTextInfoStatus_Max = 0;
    uint8 ui8_CameraFailureStatus = 0;
	uint8 ui8_AEBTextInfoStatus = 0;
	uint8 ui8_CameraCalibrationStatus = 0;
	
	
    for(uint32 ui32_EventIdx = 0;ui32_EventIdx < DEM_NUMBER_OF_EVENTS; ui32_EventIdx++)
    {
	    if(Med_a_CameraFailureStatus[ui32_EventIdx] == 0x04) //irrversible failure
	    {
            a_CameraFailureStatus_Prioritybuffer[ui32_EventIdx] = Priority_A;
		}
		else if(Med_a_CameraFailureStatus[ui32_EventIdx] == 0x03) //reversible failure;
		{
            a_CameraFailureStatus_Prioritybuffer[ui32_EventIdx] = Priority_B;
		}
		else if(Med_a_CameraFailureStatus[ui32_EventIdx] == 0x01) //Blind
		{
            a_CameraFailureStatus_Prioritybuffer[ui32_EventIdx] = Priority_C;
		}
		else if(Med_a_CameraFailureStatus[ui32_EventIdx] == 0x05) //Vehicle information failed
		{
            a_CameraFailureStatus_Prioritybuffer[ui32_EventIdx] = Priority_D;
		}
		else
		{
            a_CameraFailureStatus_Prioritybuffer[ui32_EventIdx] = 0x00; //no failure
		}

	    if(Med_a_AEBTextInfoStatus[ui32_EventIdx] == 0x0A) //AEB error by other
	    {
            a_AEBTextInfoStatus_Prioritybuffer[ui32_EventIdx] = Priority_A;
		}
		else if(Med_a_AEBTextInfoStatus[ui32_EventIdx] == 0x05) //AEB error by EPBi
		{
            a_AEBTextInfoStatus_Prioritybuffer[ui32_EventIdx] = Priority_B;
		}
		else if(Med_a_AEBTextInfoStatus[ui32_EventIdx] == 0x09) //AEB error by TCU
		{
            a_AEBTextInfoStatus_Prioritybuffer[ui32_EventIdx] = Priority_C;
		}
		else if(Med_a_AEBTextInfoStatus[ui32_EventIdx] == 0x06) //AEB error by SAS
		{
            a_AEBTextInfoStatus_Prioritybuffer[ui32_EventIdx] = Priority_D;
		}
		else if(Med_a_AEBTextInfoStatus[ui32_EventIdx] == 0x02) //AEB error by FR
		{
            a_AEBTextInfoStatus_Prioritybuffer[ui32_EventIdx] = Priority_E;
		}
		else if(Med_a_AEBTextInfoStatus[ui32_EventIdx] == 0x01) //AEB error by camera
		{
            a_AEBTextInfoStatus_Prioritybuffer[ui32_EventIdx] = Priority_F;
		}
		else
		{
            a_AEBTextInfoStatus_Prioritybuffer[ui32_EventIdx] = 0x00;
		}		
	}

	 for(uint32 ui32_EventIdx = 0;ui32_EventIdx < DEM_NUMBER_OF_EVENTS; ui32_EventIdx++)
     {
         if(a_CameraFailureStatus_Prioritybuffer[ui32_EventIdx] > ui8_CameraFailureStatus_Max)
         {
             ui8_CameraFailureStatus_Max = a_CameraFailureStatus_Prioritybuffer[ui32_EventIdx];
		 }

		 if(a_AEBTextInfoStatus_Prioritybuffer[ui32_EventIdx] > ui8_AEBTextInfoStatus_Max)
         {
             ui8_AEBTextInfoStatus_Max = a_AEBTextInfoStatus_Prioritybuffer[ui32_EventIdx];
		 }		 
	 }

	 switch (ui8_CameraFailureStatus_Max)
	 {
	     case Priority_A: ui8_CameraFailureStatus = 0x04; break;
		 case Priority_B: ui8_CameraFailureStatus = 0x03; break;
		 case Priority_C: ui8_CameraFailureStatus = 0x01; break;
		 case Priority_D: ui8_CameraFailureStatus = 0x05; break;
	     default: ui8_CameraFailureStatus = 0x00; break;
	 }

	 switch (ui8_AEBTextInfoStatus_Max)
	 {
	     case Priority_A: ui8_AEBTextInfoStatus = 0x0A; break;
		 case Priority_B: ui8_AEBTextInfoStatus = 0x05; break;
		 case Priority_C: ui8_AEBTextInfoStatus = 0x09; break;
		 case Priority_D: ui8_AEBTextInfoStatus = 0x06; break;
		 case Priority_E: ui8_AEBTextInfoStatus = 0x02; break;
		 case Priority_F: ui8_AEBTextInfoStatus = 0x01; break;
	     default: ui8_AEBTextInfoStatus = 0x00; break;
	 }

     if((Med_a_CameraCalibrationStatus[DemConf_DemEventParameter_DEM_CAMERA_CALIBRATION_FAILURE] == 0x03) ||
	 	(Med_a_CameraCalibrationStatus[DemConf_DemEventParameter_DEM_CAMERA_ONLINE_CALIBRATION_FAILURE] == 0x03))
     {
         ui8_CameraCalibrationStatus = 0x03u;
	 }
	 else
	 {
         ui8_CameraCalibrationStatus = 0x00u;
	 }
	 
	 s_Med_ErrorInfo.FCStatus.ui8_CameraCalibrationStatus = ui8_CameraCalibrationStatus;	
     s_Med_ErrorInfo.FCStatus.ui8_CameraFailureStatus = ui8_CameraFailureStatus;
	 s_Med_ErrorInfo.FCStatus.ui8_AEBTextInfoStatus = ui8_AEBTextInfoStatus;

    return 0;
}
#endif

/**
 * \functions Med_ParentDTC
 *
 * \brief 
 *
 ** \param[in] none,
 *
 ** \param[out] none,
 *
 ** \return RTE_E_OK, 
 * \comments
 *
 */
#if ((defined MED_PARENTDTC_ENABLED) && (MED_PARENTDTC_ENABLED == STD_ON))
static FUNC(void, RTE_CODE) Med_ParentDTC(void)
{   
	Med_ParentDTC_VCU161();
	Med_ParentDTC_GW17A();
	Med_ParentDTC_GW170();
    Med_ParentDTC_GW288();
	Med_ParentDTC_GW2DE();
	Med_ParentDTC_GW50();
	Med_ParentDTC_GW278();
	Med_ParentDTC_FR136();
}
#endif

/**
 * \functions Med_ParentDTC_VCU161
 *
 * \brief 
 *
 ** \param[in] none,
 *
 ** \param[out] none,
 *
 ** \return RTE_E_OK, 
 * \comments
 *
 */
#if ((defined MED_PARENTDTC_ENABLED) && (MED_PARENTDTC_ENABLED == STD_ON))
static FUNC(void, RTE_CODE) Med_ParentDTC_VCU161(void)
{
    uint8 ui8_VCU161_TO;
	uint8 ui8_VCU161_CRC;
	
	(void)Dem_GetEventStatus(DemConf_DemEventParameter_DEM_DTC_VCU_All_Node_Missing, &ui8_VCU161_TO);
	(void)Dem_GetEventStatus(DemConf_DemEventParameter_DEM_DTC_VCU_Message_Alive_Counter_Error, &ui8_VCU161_CRC);
	
	if( (ui8_VCU161_TO & (uint8)DEM_UDS_STATUS_TF) == DEM_UDS_STATUS_TF)
	{
        s_Med_ParentDTC.VCU_161.timeout = MED_EC_ACTIVE;
	}
	else
	{
        s_Med_ParentDTC.VCU_161.timeout = MED_EC_INACTIVE;
	}

	if( (ui8_VCU161_CRC & (uint8)DEM_UDS_STATUS_TF) == DEM_UDS_STATUS_TF)
	{
        s_Med_ParentDTC.VCU_161.crc = MED_EC_ACTIVE;
	}
	else
	{
        s_Med_ParentDTC.VCU_161.crc = MED_EC_INACTIVE;
	}

}
#endif

/**
 * \functions Med_ParentDTC_GW17A
 *
 * \brief 
 *
 ** \param[in] none,
 *
 ** \param[out] none,
 *
 ** \return RTE_E_OK, 
 * \comments
 *
 */
#if ((defined MED_PARENTDTC_ENABLED) && (MED_PARENTDTC_ENABLED == STD_ON))
static FUNC(void, RTE_CODE) Med_ParentDTC_GW17A(void)
{
    uint8 ui8_GW17A_TO;
	uint8 ui8_GW17A_CRC;
	
	(void)Dem_GetEventStatus(DemConf_DemEventParameter_DEM_DTC_ESP_All_Node_Missing, &ui8_GW17A_TO);
	(void)Dem_GetEventStatus(DemConf_DemEventParameter_DEM_DTC_ESP_Message_Alive_Counter_Error, &ui8_GW17A_CRC);
	
	if( (ui8_GW17A_TO & (uint8)DEM_UDS_STATUS_TF) == DEM_UDS_STATUS_TF)
	{
        s_Med_ParentDTC.GW_17A.timeout = MED_EC_ACTIVE;
	}
	else
	{
        s_Med_ParentDTC.GW_17A.timeout = MED_EC_INACTIVE;
	}

	if( (ui8_GW17A_CRC & (uint8)DEM_UDS_STATUS_TF) == DEM_UDS_STATUS_TF)
	{
        s_Med_ParentDTC.GW_17A.crc = MED_EC_ACTIVE;
	}
	else
	{
        s_Med_ParentDTC.GW_17A.crc = MED_EC_INACTIVE;
	}

}
#endif

/**
 * \functions Med_ParentDTC_GW170
 *
 * \brief 
 *
 ** \param[in] none,
 *
 ** \param[out] none,
 *
 ** \return RTE_E_OK, 
 * \comments
 *
 */
#if ((defined MED_PARENTDTC_ENABLED) && (MED_PARENTDTC_ENABLED == STD_ON))
static FUNC(void, RTE_CODE) Med_ParentDTC_GW170(void)
{
    uint8 ui8_GW170_TO;
	uint8 ui8_GW170_CRC;
	uint8 ui8_GW170_RC;
	
	(void)Dem_GetEventStatus(DemConf_DemEventParameter_DEM_DTC_EPS_All_Node_Missing, &ui8_GW170_TO);
	(void)Dem_GetEventStatus(DemConf_DemEventParameter_DEM_DTC_EPS_Message_Alive_Counter_Error_10ms, &ui8_GW170_CRC);
	(void)Dem_GetEventStatus(DemConf_DemEventParameter_DEM_DTC_EPS_Message_Alive_Counter_Error_20ms, &ui8_GW170_RC);

	
	if( (ui8_GW170_TO & (uint8)DEM_UDS_STATUS_TF) == DEM_UDS_STATUS_TF)
	{
        s_Med_ParentDTC.GW_170.timeout = MED_EC_ACTIVE;
	}
	else
	{
        s_Med_ParentDTC.GW_170.timeout = MED_EC_INACTIVE;
	}

	if( (ui8_GW170_CRC & (uint8)DEM_UDS_STATUS_TF) == DEM_UDS_STATUS_TF)
	{
        s_Med_ParentDTC.GW_170.crc = MED_EC_ACTIVE;
	}
	else
	{
        s_Med_ParentDTC.GW_170.crc = MED_EC_INACTIVE;
	}

	if( (ui8_GW170_RC & (uint8)DEM_UDS_STATUS_TF) == DEM_UDS_STATUS_TF)
	{
        s_Med_ParentDTC.GW_170.rc = MED_EC_ACTIVE;
	}
	else
	{
        s_Med_ParentDTC.GW_170.rc = MED_EC_INACTIVE;
	}

}
#endif

/**
 * \functions Med_ParentDTC_GW288
 *
 * \brief 
 *
 ** \param[in] none,
 *
 ** \param[out] none,
 *
 ** \return RTE_E_OK, 
 * \comments
 *
 */
#if ((defined MED_PARENTDTC_ENABLED) && (MED_PARENTDTC_ENABLED == STD_ON))
static FUNC(void, RTE_CODE) Med_ParentDTC_GW288(void)
{
    uint8 ui8_GW288_TO;
	uint8 ui8_GW288_CRC;
	
	(void)Dem_GetEventStatus(DemConf_DemEventParameter_DEM_DTC_BCM_All_Node_Missing, &ui8_GW288_TO);
	(void)Dem_GetEventStatus(DemConf_DemEventParameter_DEM_DTC_BCM_Message_Alive_Counter_Error_40ms, &ui8_GW288_CRC);
	
	if( (ui8_GW288_TO & (uint8)DEM_UDS_STATUS_TF) == DEM_UDS_STATUS_TF)
	{
        s_Med_ParentDTC.GW_288.timeout = MED_EC_ACTIVE;
	}
	else
	{
        s_Med_ParentDTC.GW_288.timeout = MED_EC_INACTIVE;
	}

	if( (ui8_GW288_CRC & (uint8)DEM_UDS_STATUS_TF) == DEM_UDS_STATUS_TF)
	{
        s_Med_ParentDTC.GW_288.crc = MED_EC_ACTIVE;
	}
	else
	{
        s_Med_ParentDTC.GW_288.crc = MED_EC_INACTIVE;
	}
}
#endif

/**
 * \functions Med_ParentDTC_GW2DE
 *
 * \brief 
 *
 ** \param[in] none,
 *
 ** \param[out] none,
 *
 ** \return RTE_E_OK, 
 * \comments
 *
 */
#if ((defined MED_PARENTDTC_ENABLED) && (MED_PARENTDTC_ENABLED == STD_ON))
static FUNC(void, RTE_CODE) Med_ParentDTC_GW2DE(void)
{
    uint8 ui8_GW2DE_TO;
	uint8 ui8_GW2DE_CRC;
	
	(void)Dem_GetEventStatus(DemConf_DemEventParameter_DEM_DTC_IP_node_missing, &ui8_GW2DE_TO);
	(void)Dem_GetEventStatus(DemConf_DemEventParameter_DEM_DTC_IP_message_alive_counter_error, &ui8_GW2DE_CRC);

	
	if( (ui8_GW2DE_TO & (uint8)DEM_UDS_STATUS_TF) == DEM_UDS_STATUS_TF)
	{
        s_Med_ParentDTC.GW_2DE.timeout = MED_EC_ACTIVE;
	}
	else
	{
        s_Med_ParentDTC.GW_2DE.timeout = MED_EC_INACTIVE;
	}

	if( (ui8_GW2DE_CRC & (uint8)DEM_UDS_STATUS_TF) == DEM_UDS_STATUS_TF)
	{
        s_Med_ParentDTC.GW_2DE.crc = MED_EC_ACTIVE;
	}
	else
	{
        s_Med_ParentDTC.GW_2DE.crc = MED_EC_INACTIVE;
	}
}
#endif

/**
 * \functions Med_ParentDTC_GW50
 *
 * \brief 
 *
 ** \param[in] none,
 *
 ** \param[out] none,
 *
 ** \return RTE_E_OK, 
 * \comments
 *
 */
#if ((defined MED_PARENTDTC_ENABLED) && (MED_PARENTDTC_ENABLED == STD_ON))
static FUNC(void, RTE_CODE) Med_ParentDTC_GW50(void)
{
    uint8 ui8_GW50_TO;
	uint8 ui8_GW50_CRC;
	
	(void)Dem_GetEventStatus(DemConf_DemEventParameter_DEM_DTC_SRS_All_Node_Missing, &ui8_GW50_TO);
	(void)Dem_GetEventStatus(DemConf_DemEventParameter_DEM_DTC_SRS_Message_Alive_Counter_Error, &ui8_GW50_CRC);
	
	if( (ui8_GW50_TO & (uint8)DEM_UDS_STATUS_TF) == DEM_UDS_STATUS_TF)
	{
        s_Med_ParentDTC.GW_50.timeout = MED_EC_ACTIVE;
	}
	else
	{
        s_Med_ParentDTC.GW_50.timeout = MED_EC_INACTIVE;
	}

	if( (ui8_GW50_CRC & (uint8)DEM_UDS_STATUS_TF) == DEM_UDS_STATUS_TF)
	{
        s_Med_ParentDTC.GW_50.crc = MED_EC_ACTIVE;
	}
	else
	{
        s_Med_ParentDTC.GW_50.crc = MED_EC_INACTIVE;
	}
}
#endif

/**
 * \functions Med_ParentDTC_GW278
 *
 * \brief 
 *
 ** \param[in] none,
 *
 ** \param[out] none,
 *
 ** \return RTE_E_OK, 
 * \comments
 *
 */
#if ((defined MED_PARENTDTC_ENABLED) && (MED_PARENTDTC_ENABLED == STD_ON))
static FUNC(void, RTE_CODE) Med_ParentDTC_GW278(void)
{
    uint8 ui8_GW278_TO;
	uint8 ui8_GW278_CRC;
	
	(void)Dem_GetEventStatus(DemConf_DemEventParameter_DEM_DTC_ESP_All_Node_Missing, &ui8_GW278_TO);
	(void)Dem_GetEventStatus(DemConf_DemEventParameter_DEM_DTC_ESP_Message_Alive_Counter_Error, &ui8_GW278_CRC);
	
	if( (ui8_GW278_TO & (uint8)DEM_UDS_STATUS_TF) == DEM_UDS_STATUS_TF)
	{
        s_Med_ParentDTC.GW_278.timeout = MED_EC_ACTIVE;
	}
	else
	{
        s_Med_ParentDTC.GW_278.timeout = MED_EC_INACTIVE;
	}

	if( (ui8_GW278_CRC & (uint8)DEM_UDS_STATUS_TF) == DEM_UDS_STATUS_TF)
	{
        s_Med_ParentDTC.GW_278.crc = MED_EC_ACTIVE;
	}
	else
	{
        s_Med_ParentDTC.GW_278.crc = MED_EC_INACTIVE;
	}
}
#endif

/**
 * \functions Med_ParentDTC_FR136
 *
 * \brief 
 *
 ** \param[in] none,
 *
 ** \param[out] none,
 *
 ** \return RTE_E_OK, 
 * \comments
 *
 */
#if ((defined MED_PARENTDTC_ENABLED) && (MED_PARENTDTC_ENABLED == STD_ON))
static FUNC(void, RTE_CODE) Med_ParentDTC_FR136(void)
{
    uint8 ui8_FR136_TO;
	uint8 ui8_FR136_CRC;
	
	(void)Dem_GetEventStatus(DemConf_DemEventParameter_DEM_DTC_FR_All_Node_Missing, &ui8_FR136_TO);
	(void)Dem_GetEventStatus(DemConf_DemEventParameter_DEM_DTC_Front_Radar_Alive_Counter_Error, &ui8_FR136_CRC);
	
	if( (ui8_FR136_TO & (uint8)DEM_UDS_STATUS_TF) == DEM_UDS_STATUS_TF)
	{
        s_Med_ParentDTC.FR_136.timeout = MED_EC_ACTIVE;
	}
	else
	{
        s_Med_ParentDTC.FR_136.timeout = MED_EC_INACTIVE;
	}

	if( (ui8_FR136_CRC & (uint8)DEM_UDS_STATUS_TF) == DEM_UDS_STATUS_TF)
	{
        s_Med_ParentDTC.FR_136.crc = MED_EC_ACTIVE;
	}
	else
	{
        s_Med_ParentDTC.FR_136.crc = MED_EC_INACTIVE;
	}
}
#endif
/**
 * \functions Med_u_Required_Port
 *
 * \brief 
 *
 ** \param[in] none,
 *
 ** \param[out] none,
 *
 ** \return RTE_E_OK, 
 * \comments
 *
 */

static FUNC(Std_ReturnType, RTE_CODE) Med_u_Required_Port(void)
{	
    
#if ((defined MED_ENABLECONDITION_ENABLED) && (MED_ENABLECONDITION_ENABLED == STD_ON))

    (void)Esh_u_EnableCondition_Read(&s_Med_ErrorInfo.EnableCondition);

#endif

#if ((defined MED_HWINFO_RTE_UPDATE_ENABLED) && (MED_HWINFO_RTE_UPDATE_ENABLED == STD_ON))

    (void)Rte_Read_RP_VoltMonI_SRI_VoltState_DE_VoltMonI_VoltState(&s_Med_ErrorInfo.HardwareStatus.ui8_BattVoltState);

	(void)Cdd_EvAdc_GetRegValue(EVADC_TMON_SYS2_MCU_TEMP_AN21,&s_Med_ErrorInfo.HardwareStatus.ui16_EcuTemperature);
	
#endif
	
#if ((defined MED_CANINFO_RTE_UPDATE_ENABLED) && (MED_CANINFO_RTE_UPDATE_ENABLED == STD_ON))

	(void)Rte_Read_RP_Cpr_Body_Data_SRI_Cpr_Rxsignal_Body_BcmFrntWiperSts(&s_Med_ErrorInfo.CanSignalStatus.ui8_BcmFrntWiperSts);
	
	(void)Rte_Read_RP_Cpr_Body_Data_SRI_Cpr_Rxsignal_Body_BcmFrntWiperSts_Status(&s_Med_ErrorInfo.CanSignalStatus.ui8_BcmFrntWiperSts_Status);

	(void)Rte_Read_RP_Cpr_Body_Data_SRI_Cpr_Rxsignal_Body_BcmTurnIndcrLe(&s_Med_ErrorInfo.CanSignalStatus.ui8_BcmTurnIndcrLe);

	(void)Rte_Read_RP_Cpr_Body_Data_SRI_Cpr_Rxsignal_Body_BcmTurnIndcrLe_Status(&s_Med_ErrorInfo.CanSignalStatus.ui8_BcmTurnIndcrLe_Status);
	
	(void)Rte_Read_RP_Cpr_Body_Data_SRI_Cpr_Rxsignal_Body_BcmTurnIndcrRi(&s_Med_ErrorInfo.CanSignalStatus.ui8_BcmTurnIndcrRi);
	
	(void)Rte_Read_RP_Cpr_Body_Data_SRI_Cpr_Rxsignal_Body_BcmTurnIndcrRi_Status(&s_Med_ErrorInfo.CanSignalStatus.ui8_BcmTurnIndcrRi_Status);
	
	//(void)Rte_Read_RP_Cpr_Chassis_Data_SRI_Cpr_RxSignal_Chassisd_EspVehSpd(&s_Med_ErrorInfo.CanSignalStatus.f32_EspVehSpd);
	(void)Com_ReceiveSignal(ComConf_ComSignal_SGEspVehSpd_378R,&s_Med_ErrorInfo.CanSignalStatus.ui16_EspVehSpd);
	
	//(void)Rte_Read_RP_Cpr_Chassis_Data_SRI_Cpr_RxSignal_Chassisd_EspVehSpd_Status(&s_Med_ErrorInfo.CanSignalStatus.ui8_EspVehSpd_Status);
	(void)Com_ReceiveSignal(ComConf_ComSignal_SGEspVehSpdVld_378R,&s_Med_ErrorInfo.CanSignalStatus.ui8_EspVehSpd_Status);
	
	//(void)Rte_Read_RP_Cpr_Chassis_Data_SRI_Cpr_RxSignal_Chassisd_VcuAccrPedlPosn(&s_Med_ErrorInfo.CanSignalStatus.f32_VcuAccrPedlPosn);
	(void)Com_ReceiveSignal(ComConf_ComSignal_SGVcuAccrPedlPosn_353R,&s_Med_ErrorInfo.CanSignalStatus.ui16_VcuAccrPedlPosn);
	
	//(void)Rte_Read_RP_Cpr_Chassis_Data_SRI_Cpr_RxSignal_Chassisd_VcuAccrPedlPosn_Status(&s_Med_ErrorInfo.CanSignalStatus.ui8_VcuAccrPedlPosn_Status);
	(void)Com_ReceiveSignal(ComConf_ComSignal_SGVcuAccrPedlPosnVld_353R,&s_Med_ErrorInfo.CanSignalStatus.ui8_VcuAccrPedlPosn_Status);
	
	//(void)Rte_Read_RP_Cpr_Chassis_Data_SRI_Cpr_RxSignal_Chassisd_VcuGearPosn(&s_Med_ErrorInfo.CanSignalStatus.f32_VcuGearPosn);
	(void)Com_ReceiveSignal(ComConf_ComSignal_SGVcuGearPosn_353R,&s_Med_ErrorInfo.CanSignalStatus.ui8_VcuGearPosn);

	//(void)Rte_Read_RP_Cpr_Chassis_Data_SRI_Cpr_RxSignal_Chassisd_VcuGearPosn_Status(&s_Med_ErrorInfo.CanSignalStatus.ui8_VcuGearPosn_Status);
    (void)Com_ReceiveSignal(ComConf_ComSignal_SGVcuVehGearPosnVld_353R,&s_Med_ErrorInfo.CanSignalStatus.ui8_VcuGearPosn_Status);
	
	(void)Rte_Read_RP_Cpr_Powertrain_Data_SRI_Cpr_RxSignal_Powertrain_WhlSpdLeFrntData(&s_Med_ErrorInfo.CanSignalStatus.f32_WhlSpdLeFrntData);

	//(void)Rte_Read_RP_Cpr_Powertrain_Data_SRI_Cpr_RxSignal_Powertrain_WhlSpdLeFrntData_Status(&s_Med_ErrorInfo.CanSignalStatus.ui8_WhlSpdLeFrntData_Status);
    (void)Rte_Read_RP_Cpr_Powertrain_Data_SRI_Cpr_RxSignal_Powertrain_WhlSpdLeFrntDataVld(&s_Med_ErrorInfo.CanSignalStatus.ui8_WhlSpdLeFrntDataVld);
	
	(void)Rte_Read_RP_Cpr_Powertrain_Data_SRI_Cpr_RxSignal_Powertrain_WhlSpdLeFrntDir(&s_Med_ErrorInfo.CanSignalStatus.ui8_WhlSpdLeFrntDir);
	
	(void)Rte_Read_RP_Cpr_Powertrain_Data_SRI_Cpr_RxSignal_Powertrain_WhlSpdLeFrntDir_Status(&s_Med_ErrorInfo.CanSignalStatus.ui8_WhlSpdLeFrntDir_Status);
	
	(void)Rte_Read_RP_Cpr_Powertrain_Data_SRI_Cpr_RxSignal_Powertrain_WhlSpdLeReData(&s_Med_ErrorInfo.CanSignalStatus.f32_WhlSpdLeReData);
	
	//(void)Rte_Read_RP_Cpr_Powertrain_Data_SRI_Cpr_RxSignal_Powertrain_WhlSpdLeReData_Status(&s_Med_ErrorInfo.CanSignalStatus.ui8_WhlSpdLeReData_Status);
	(void)Rte_Read_RP_Cpr_Powertrain_Data_SRI_Cpr_RxSignal_Powertrain_WhlSpdLeReDataVld(&s_Med_ErrorInfo.CanSignalStatus.ui8_WhlSpdLeReDataVld);
	
	(void)Rte_Read_RP_Cpr_Powertrain_Data_SRI_Cpr_RxSignal_Powertrain_WhlSpdLeReDir(&s_Med_ErrorInfo.CanSignalStatus.ui8_WhlSpdLeReDir);
	
	(void)Rte_Read_RP_Cpr_Powertrain_Data_SRI_Cpr_RxSignal_Powertrain_WhlSpdLeReDir_Status(&s_Med_ErrorInfo.CanSignalStatus.ui8_WhlSpdLeReDir_Status);
	
	(void)Rte_Read_RP_Cpr_Powertrain_Data_SRI_Cpr_RxSignal_Powertrain_WhlSpdRiFrntData(&s_Med_ErrorInfo.CanSignalStatus.f32_WhlSpdRiFrntData);
	
	//(void)Rte_Read_RP_Cpr_Powertrain_Data_SRI_Cpr_RxSignal_Powertrain_WhlSpdRiFrntData_Status(&s_Med_ErrorInfo.CanSignalStatus.ui8_WhlSpdRiFrntData_Status);
	(void)Rte_Read_RP_Cpr_Powertrain_Data_SRI_Cpr_RxSignal_Powertrain_WhlSpdRiFrntDataVld(&s_Med_ErrorInfo.CanSignalStatus.ui8_WhlSpdRiFrntDataVld);
	
	(void)Rte_Read_RP_Cpr_Powertrain_Data_SRI_Cpr_RxSignal_Powertrain_WhlSpdRiFrntDir(&s_Med_ErrorInfo.CanSignalStatus.ui8_WhlSpdRiFrntDir);
	
	(void)Rte_Read_RP_Cpr_Powertrain_Data_SRI_Cpr_RxSignal_Powertrain_WhlSpdRiFrntDir_Status(&s_Med_ErrorInfo.CanSignalStatus.ui8_WhlSpdRiFrntDir_Status);
	
	(void)Rte_Read_RP_Cpr_Powertrain_Data_SRI_Cpr_RxSignal_Powertrain_WhlSpdRiReData(&s_Med_ErrorInfo.CanSignalStatus.f32_WhlSpdRiReData);
	
	//(void)Rte_Read_RP_Cpr_Powertrain_Data_SRI_Cpr_RxSignal_Powertrain_WhlSpdRiReData_Status(&s_Med_ErrorInfo.CanSignalStatus.ui8_WhlSpdRiReData_Status);
	(void)Rte_Read_RP_Cpr_Powertrain_Data_SRI_Cpr_RxSignal_Powertrain_WhlSpdRiReDataVld(&s_Med_ErrorInfo.CanSignalStatus.ui8_WhlSpdRiReDataVld);
	
	(void)Rte_Read_RP_Cpr_Powertrain_Data_SRI_Cpr_RxSignal_Powertrain_WhlSpdRiReDir(&s_Med_ErrorInfo.CanSignalStatus.ui8_WhlSpdRiReDir);
	
	(void)Rte_Read_RP_Cpr_Powertrain_Data_SRI_Cpr_RxSignal_Powertrain_WhlSpdRiReDir_Status(&s_Med_ErrorInfo.CanSignalStatus.ui8_WhlSpdRiReDir_Status);

    //(void)Rte_Read_RP_Cpr_Chassis_Data_SRI_Cpr_RxSignal_Chassisd_EpsSasSteerAg(&s_Med_ErrorInfo.CanSignalStatus.f32_EpsSasSteerAg);
    (void)Com_ReceiveSignal(ComConf_ComSignal_SGEpsSasSteerAg_384R,&s_Med_ErrorInfo.CanSignalStatus.ui16_EpsSasSteerAg);
	
    //(void)Rte_Read_RP_Cpr_Chassis_Data_SRI_Cpr_RxSignal_Chassisd_EpsSasSteerAg_Status(&s_Med_ErrorInfo.CanSignalStatus.ui8_EpsSasSteerAg_Status);
    (void)Com_ReceiveSignal(ComConf_ComSignal_SGEpsSasSteerAgVld_384R,&s_Med_ErrorInfo.CanSignalStatus.ui8_EpsSasSteerAg_Status);
	
	//(void)Rte_Read_RP_Cpr_Chassis_Data_SRI_Cpr_RxSignal_Chassisd_EspLatAccel(&s_Med_ErrorInfo.CanSignalStatus.f32_EspLatAccel);

	(void)Com_ReceiveSignal(ComConf_ComSignal_SGESP_LatAccel_632R,&s_Med_ErrorInfo.CanSignalStatus.ui16_EspLatAccel);
 		
    //(void)Rte_Read_RP_Cpr_Chassis_Data_SRI_Cpr_RxSignal_Chassisd_EspLatAccel_Status(&s_Med_ErrorInfo.CanSignalStatus.ui8_EspLatAccel_Status);

	(void)Com_ReceiveSignal(ComConf_ComSignal_SGESP_LatAccelValid_632R,&s_Med_ErrorInfo.CanSignalStatus.ui8_EspLatAccel_Status);
  
    //(void)Rte_Read_RP_Cpr_Chassis_Data_SRI_Cpr_RxSignal_Chassisd_EspLongAccel(&s_Med_ErrorInfo.CanSignalStatus.f32_EspLongAccel);
	  
	(void)Com_ReceiveSignal(ComConf_ComSignal_SGESP_LongAccel_632R,&s_Med_ErrorInfo.CanSignalStatus.ui16_EspLongAccel);
	
    //(void)Rte_Read_RP_Cpr_Chassis_Data_SRI_Cpr_RxSignal_Chassisd_EspLongAccel_Status(&s_Med_ErrorInfo.CanSignalStatus.ui8_EspLongAccel_Status);

	(void)Com_ReceiveSignal(ComConf_ComSignal_SGESP_LongAccelValid_632R,&s_Med_ErrorInfo.CanSignalStatus.ui8_EspLongAccel_Status);

	//(void)Rte_Read_RP_Cpr_Chassis_Data_SRI_Cpr_RxSignal_Chassisd_EspYawRate(&s_Med_ErrorInfo.CanSignalStatus.f32_EspYawRate);
	
	(void)Com_ReceiveSignal(ComConf_ComSignal_SGESP_YawRate_632R,&s_Med_ErrorInfo.CanSignalStatus.ui16_EspYawRate);
  
	//(void)Rte_Read_RP_Cpr_Chassis_Data_SRI_Cpr_RxSignal_Chassisd_EspYawRate_Status(&s_Med_ErrorInfo.CanSignalStatus.ui8_EspYawRate_Status);

	(void)Com_ReceiveSignal(ComConf_ComSignal_SGESP_YawRateValid_632R,&s_Med_ErrorInfo.CanSignalStatus.ui8_EspYawRate_Status);
	
	(void)Rte_Read_RP_Cpr_Chassis_Data_SRI_Cpr_RxSignal_Chassisd_EspAbsFailr(&s_Med_ErrorInfo.CanSignalStatus.ui8_EspAbsFailr);
  
    (void)Rte_Read_RP_Cpr_Chassis_Data_SRI_Cpr_RxSignal_Chassisd_EspAbsFailr_Status(&s_Med_ErrorInfo.CanSignalStatus.ui8_EspAbsFailr_Status);

	(void)Rte_Read_RP_Cpr_Chassis_Data_SRI_Cpr_RxSignal_Chassisd_EspTcsFailr(&s_Med_ErrorInfo.CanSignalStatus.ui8_EspTcsFailr);
	
    (void)Rte_Read_RP_Cpr_Chassis_Data_SRI_Cpr_RxSignal_Chassisd_EspTcsFailr_Status(&s_Med_ErrorInfo.CanSignalStatus.ui8_EspTcsFailr_Status);

	(void)Rte_Read_RP_Cpr_Chassis_Data_SRI_Cpr_RxSignal_Chassisd_EspABAavailable(&s_Med_ErrorInfo.CanSignalStatus.ui8_EspABAavailable);
 
    (void)Rte_Read_RP_Cpr_Chassis_Data_SRI_Cpr_RxSignal_Chassisd_EspABAavailable_Status(&s_Med_ErrorInfo.CanSignalStatus.ui8_EspABAavailable_Status);
  
    (void)Rte_Read_RP_Cpr_Chassis_Data_SRI_Cpr_RxSignal_Chassisd_EspAEBAvailable(&s_Med_ErrorInfo.CanSignalStatus.ui8_EspAEBAvailable);
  
    (void)Rte_Read_RP_Cpr_Chassis_Data_SRI_Cpr_RxSignal_Chassisd_EspAEBAvailable_Status(&s_Med_ErrorInfo.CanSignalStatus.ui8_EspAEBAvailable_Status);
  
    (void)Rte_Read_RP_Cpr_Chassis_Data_SRI_Cpr_RxSignal_Chassisd_EspAWBavailable(&s_Med_ErrorInfo.CanSignalStatus.ui8_EspAWBavailable);
  
    (void)Rte_Read_RP_Cpr_Chassis_Data_SRI_Cpr_RxSignal_Chassisd_EspAWBavailable_Status(&s_Med_ErrorInfo.CanSignalStatus.ui8_EspAWBavailable_Status);

	(void)Rte_Read_RP_Cpr_Chassis_Data_SRI_Cpr_RxSignal_Chassisd_IbBrkPedlStsGb(&s_Med_ErrorInfo.CanSignalStatus.ui8_IbBrkPedlStsGb);
    //Bug: Set IbBrkPedlStsGb to 0, The Status shall be return 0x16;
    //(void)Rte_Read_RP_Cpr_Chassis_Data_SRI_Cpr_RxSignal_Chassisd_IbBrkPedlStsGb_Status(&s_Med_ErrorInfo.CanSignalStatus.ui8_IbBrkPedlStsGb_Status);
  
    (void)Rte_Read_RP_Cpr_Body_Data_SRI_Cpr_Rxsignal_Body_SrsDrvrBucSwtSts(&s_Med_ErrorInfo.CanSignalStatus.ui8_SrsDrvrBucSwtSts);
  
    (void)Rte_Read_RP_Cpr_Body_Data_SRI_Cpr_Rxsignal_Body_SrsDrvrBucSwtSts_Status(&s_Med_ErrorInfo.CanSignalStatus.ui8_SrsDrvrBucSwtSts_Status);

	(void)Rte_Read_RP_Cpr_Chassis_Data_SRI_Cpr_RxSignal_Chassisd_EpsPinionang(&s_Med_ErrorInfo.CanSignalStatus.f32_EpsPinionang);
  
    //(void)Rte_Read_RP_Cpr_Chassis_Data_SRI_Cpr_RxSignal_Chassisd_EpsPinionang_Status(&s_Med_ErrorInfo.CanSignalStatus.ui8_EpsPinionang_Status);
	(void)Com_ReceiveSignal(ComConf_ComSignal_SGEPS_Pinionang_Valid_382R, &s_Med_ErrorInfo.CanSignalStatus.ui8_EpsPinionang_Status);
  
    (void)Rte_Read_RP_Cpr_Body_Data_SRI_Cpr_Rxsignal_Body_BcmEmgyLiSts(&s_Med_ErrorInfo.CanSignalStatus.ui8_BcmEmgyLiSts);
  
    (void)Rte_Read_RP_Cpr_Body_Data_SRI_Cpr_Rxsignal_Body_BcmEmgyLiSts_Status(&s_Med_ErrorInfo.CanSignalStatus.ui8_BcmEmgyLiSts_Status);

	(void)Rte_Read_RP_Cpr_Chassis_Data_SRI_Cpr_RxSignal_Chassisd_EpsConcussAvailabilityStatus(&s_Med_ErrorInfo.CanSignalStatus.ui8_EpsConcussAvailabilityStatus);

    (void)Rte_Read_RP_Cpr_Chassis_Data_SRI_Cpr_RxSignal_Chassisd_EpsConcussAvailabilityStatus_Status(&s_Med_ErrorInfo.CanSignalStatus.ui8_EpsConcussAvailabilitySts_Status);

	(void)Rte_Read_RP_Cpr_Chassis_Data_SRI_Cpr_RxSignal_Chassisd_EpsMeasuredTorsionBarTorque(&s_Med_ErrorInfo.CanSignalStatus.f32_EpsMeasuredTorsionBarTorque);

    //(void)Rte_Read_RP_Cpr_Chassis_Data_SRI_Cpr_RxSignal_Chassisd_EpsMeasuredTorsionBarTorque_Status(&s_Med_ErrorInfo.CanSignalStatus.ui8_EpsMeasuredTorsionBarTorque_Status);
	(void)Com_ReceiveSignal(ComConf_ComSignal_SGEPS_MeasuredTorsionBarTorqValid_382R, &s_Med_ErrorInfo.CanSignalStatus.ui8_EpsMeasuredTorsionBarTorque_Status);

    (void)Rte_Read_RP_Cpr_Body_Data_SRI_Cpr_Rxsignal_Body_IP_QDashACCFail(&s_Med_ErrorInfo.CanSignalStatus.ui8_IP_QDashACCFail);
	  
    (void)Rte_Read_RP_Cpr_Body_Data_SRI_Cpr_Rxsignal_Body_IP_QDashACCFail_Status(&s_Med_ErrorInfo.CanSignalStatus.ui8_IP_QDashACCFail_Status);
  
	(void)Com_ReceiveSignal(ComConf_ComSignal_SGWhlSpdFrntLePls_523R, &s_Med_ErrorInfo.CanSignalStatus.ui8_WhlSpdFrntLePls);

	(void)Com_ReceiveSignal(ComConf_ComSignal_SGWhlSpdFrntRiPls_523R, &s_Med_ErrorInfo.CanSignalStatus.ui8_WhlSpdFrntRiPls);

	(void)Com_ReceiveSignal(ComConf_ComSignal_SGWhlSpdReLePls_523R, &s_Med_ErrorInfo.CanSignalStatus.ui8_WhlSpdReLePls);

	(void)Com_ReceiveSignal(ComConf_ComSignal_SGWhlSpdReRiPls_523R, &s_Med_ErrorInfo.CanSignalStatus.ui8_WhlSpdReRiPls);

	(void)Com_ReceiveSignal(ComConf_ComSignal_SGEpsSasCalSts_384R, &s_Med_ErrorInfo.CanSignalStatus.ui8_EpsSasCalSts);

	(void)Com_ReceiveSignal(ComConf_ComSignal_SGEPS_fault_state_368R, &s_Med_ErrorInfo.CanSignalStatus.ui8_Epsfaultstate);

	(void)Com_ReceiveSignal(ComConf_ComSignal_SGEPS_ActualTorsionBarTorq_368R, &s_Med_ErrorInfo.CanSignalStatus.ui16_EpsActualTorsionBarTorq);

	(void)Com_ReceiveSignal(ComConf_ComSignal_SGEPS_ActualMotorTorq_368R, &s_Med_ErrorInfo.CanSignalStatus.ui16_EpsActualMotorTorq);

	(void)Com_ReceiveSignal(ComConf_ComSignal_SGEpsSteerAgSensFilr_384R, &s_Med_ErrorInfo.CanSignalStatus.ui8_EpsSteerAgSensFilr);

	(void)Com_ReceiveSignal(ComConf_ComSignal_SGEpsFaild_591R, &s_Med_ErrorInfo.CanSignalStatus.ui8_EpsFaild);

	(void)Com_ReceiveSignal(ComConf_ComSignal_SGEPS_APA_EpasFAILED_591R, &s_Med_ErrorInfo.CanSignalStatus.ui8_EpsAPAEpasFAILED);

	(void)Com_ReceiveSignal(ComConf_ComSignal_SGIP_DISFail_734R, &s_Med_ErrorInfo.CanSignalStatus.ui8_IP_DISFail);

	(void)Com_ReceiveSignal(ComConf_ComSignal_SGFR_FRadarCalibrationStatus_310R, &s_Med_ErrorInfo.CanSignalStatus.ui8_FRadarCalibrationStatus);
	
	(void)Com_ReceiveSignal(ComConf_ComSignal_SGFR_RadarFailureStatus_310R, &s_Med_ErrorInfo.CanSignalStatus.ui8_FR_RadarFailureStatus);

	(void)Com_ReceiveSignal(ComConf_ComSignal_SGBCM_BrakeLampError_651R, &s_Med_ErrorInfo.CanSignalStatus.ui8_BCMBrakeLampError);

    (void)Com_ReceiveSignal(ComConf_ComSignal_SGIbBrkPedlStsGbVld_706R, &s_Med_ErrorInfo.CanSignalStatus.ui8_IbBrkPedlStsGbVld);
	
	(void)Rte_Read_RP_Cpr_Chassis_Data_SRI_Cpr_RxSignal_Chassisd_EspEbdFailr(&s_Med_ErrorInfo.CanSignalStatus.ui8_EspEbdFailr);
  
    (void)Rte_Read_RP_Cpr_Chassis_Data_SRI_Cpr_RxSignal_Chassisd_EspEbdFailr_Status(&s_Med_ErrorInfo.CanSignalStatus.ui8_EspEbdFailr_Status);
	
	(void)Rte_Call_RP_Cpr_GetMsgStatusInfo_CSI_Cpr_RxMessageState_Get_RxMsgStatus(E_CPR_MSG_ID_GW_50, &s_Med_ErrorInfo.CanPduStatus.GW_50_PduSts);

	(void)Rte_Call_RP_Cpr_GetMsgStatusInfo_CSI_Cpr_RxMessageState_Get_RxMsgStatus(E_CPR_MSG_ID_GW_170, &s_Med_ErrorInfo.CanPduStatus.GW_170_PduSts);  

	(void)Rte_Call_RP_Cpr_GetMsgStatusInfo_CSI_Cpr_RxMessageState_Get_RxMsgStatus(E_CPR_MSG_ID_GW_17A, &s_Med_ErrorInfo.CanPduStatus.GW_17A_PduSts); 

	(void)Rte_Call_RP_Cpr_GetMsgStatusInfo_CSI_Cpr_RxMessageState_Get_RxMsgStatus(E_CPR_MSG_ID_GW_17E, &s_Med_ErrorInfo.CanPduStatus.GW_17E_PduSts); 
	
    (void)Rte_Call_RP_Cpr_GetMsgStatusInfo_CSI_Cpr_RxMessageState_Get_RxMsgStatus(E_CPR_MSG_ID_GW_180, &s_Med_ErrorInfo.CanPduStatus.GW_180_PduSts); 
	
    (void)Rte_Call_RP_Cpr_GetMsgStatusInfo_CSI_Cpr_RxMessageState_Get_RxMsgStatus(E_CPR_MSG_ID_GW_1C2, &s_Med_ErrorInfo.CanPduStatus.GW_1C2_PduSts);
	
    (void)Rte_Call_RP_Cpr_GetMsgStatusInfo_CSI_Cpr_RxMessageState_Get_RxMsgStatus(E_CPR_MSG_ID_GW_20B, &s_Med_ErrorInfo.CanPduStatus.GW_20B_PduSts);
	
    (void)Rte_Call_RP_Cpr_GetMsgStatusInfo_CSI_Cpr_RxMessageState_Get_RxMsgStatus(E_CPR_MSG_ID_GW_24F, &s_Med_ErrorInfo.CanPduStatus.GW_24F_PduSts); 
	
    (void)Rte_Call_RP_Cpr_GetMsgStatusInfo_CSI_Cpr_RxMessageState_Get_RxMsgStatus(E_CPR_MSG_ID_GW_278, &s_Med_ErrorInfo.CanPduStatus.GW_278_PduSts);  
	
    (void)Rte_Call_RP_Cpr_GetMsgStatusInfo_CSI_Cpr_RxMessageState_Get_RxMsgStatus(E_CPR_MSG_ID_GW_288, &s_Med_ErrorInfo.CanPduStatus.GW_288_PduSts);  
    
    (void)Rte_Call_RP_Cpr_GetMsgStatusInfo_CSI_Cpr_RxMessageState_Get_RxMsgStatus(E_CPR_MSG_ID_GW_28B, &s_Med_ErrorInfo.CanPduStatus.GW_28B_PduSts); 
    
    (void)Rte_Call_RP_Cpr_GetMsgStatusInfo_CSI_Cpr_RxMessageState_Get_RxMsgStatus(E_CPR_MSG_ID_GW_2A8, &s_Med_ErrorInfo.CanPduStatus.GW_2A8_PduSts); 
	
    (void)Rte_Call_RP_Cpr_GetMsgStatusInfo_CSI_Cpr_RxMessageState_Get_RxMsgStatus(E_CPR_MSG_ID_GW_2C2, &s_Med_ErrorInfo.CanPduStatus.GW_2C2_PduSts);  
	
    (void)Rte_Call_RP_Cpr_GetMsgStatusInfo_CSI_Cpr_RxMessageState_Get_RxMsgStatus(E_CPR_MSG_ID_GW_2DE, &s_Med_ErrorInfo.CanPduStatus.GW_2DE_PduSts); 
	
    (void)Rte_Call_RP_Cpr_GetMsgStatusInfo_CSI_Cpr_RxMessageState_Get_RxMsgStatus(E_CPR_MSG_ID_GW_3C2, &s_Med_ErrorInfo.CanPduStatus.GW_3C2_PduSts); 
	
    (void)Rte_Call_RP_Cpr_GetMsgStatusInfo_CSI_Cpr_RxMessageState_Get_RxMsgStatus(E_CPR_MSG_ID_VCU_161,&s_Med_ErrorInfo.CanPduStatus.VCU_161_PduSts);
	
    (void)Rte_Call_RP_Cpr_GetMsgStatusInfo_CSI_Cpr_RxMessageState_Get_RxMsgStatus(E_CPR_MSG_ID_VCU_38A, &s_Med_ErrorInfo.CanPduStatus.VCU_38A_PduSts); 
	
    (void)Rte_Call_RP_Cpr_GetMsgStatusInfo_CSI_Cpr_RxMessageState_Get_RxMsgStatus(E_CPR_MSG_ID_FR_111, &s_Med_ErrorInfo.CanPduStatus.FR_111_PduSts); 
	
    (void)Rte_Call_RP_Cpr_GetMsgStatusInfo_CSI_Cpr_RxMessageState_Get_RxMsgStatus(E_CPR_MSG_ID_FR_112, &s_Med_ErrorInfo.CanPduStatus.FR_112_PduSts); 
    
    (void)Rte_Call_RP_Cpr_GetMsgStatusInfo_CSI_Cpr_RxMessageState_Get_RxMsgStatus(E_CPR_MSG_ID_FR_113, &s_Med_ErrorInfo.CanPduStatus.FR_113_PduSts); 
	
    (void)Rte_Call_RP_Cpr_GetMsgStatusInfo_CSI_Cpr_RxMessageState_Get_RxMsgStatus(E_CPR_MSG_ID_FR_114, &s_Med_ErrorInfo.CanPduStatus.FR_114_PduSts);
	
    (void)Rte_Call_RP_Cpr_GetMsgStatusInfo_CSI_Cpr_RxMessageState_Get_RxMsgStatus(E_CPR_MSG_ID_FR_115, &s_Med_ErrorInfo.CanPduStatus.FR_115_PduSts); 
	
    (void)Rte_Call_RP_Cpr_GetMsgStatusInfo_CSI_Cpr_RxMessageState_Get_RxMsgStatus(E_CPR_MSG_ID_FR_116, &s_Med_ErrorInfo.CanPduStatus.FR_116_PduSts);
	
    (void)Rte_Call_RP_Cpr_GetMsgStatusInfo_CSI_Cpr_RxMessageState_Get_RxMsgStatus(E_CPR_MSG_ID_FR_117, &s_Med_ErrorInfo.CanPduStatus.FR_117_PduSts); 
	
    (void)Rte_Call_RP_Cpr_GetMsgStatusInfo_CSI_Cpr_RxMessageState_Get_RxMsgStatus(E_CPR_MSG_ID_FR_118, &s_Med_ErrorInfo.CanPduStatus.FR_118_PduSts); 
	
    (void)Rte_Call_RP_Cpr_GetMsgStatusInfo_CSI_Cpr_RxMessageState_Get_RxMsgStatus(E_CPR_MSG_ID_FR_119, &s_Med_ErrorInfo.CanPduStatus.FR_119_PduSts); 
	
    (void)Rte_Call_RP_Cpr_GetMsgStatusInfo_CSI_Cpr_RxMessageState_Get_RxMsgStatus(E_CPR_MSG_ID_FR_11A, &s_Med_ErrorInfo.CanPduStatus.FR_11A_PduSts); 
	
    (void)Rte_Call_RP_Cpr_GetMsgStatusInfo_CSI_Cpr_RxMessageState_Get_RxMsgStatus(E_CPR_MSG_ID_FR_11B, &s_Med_ErrorInfo.CanPduStatus.FR_11B_PduSts); 
	
    (void)Rte_Call_RP_Cpr_GetMsgStatusInfo_CSI_Cpr_RxMessageState_Get_RxMsgStatus(E_CPR_MSG_ID_FR_11C, &s_Med_ErrorInfo.CanPduStatus.FR_11C_PduSts);
	
    (void)Rte_Call_RP_Cpr_GetMsgStatusInfo_CSI_Cpr_RxMessageState_Get_RxMsgStatus(E_CPR_MSG_ID_FR_11D, &s_Med_ErrorInfo.CanPduStatus.FR_11D_PduSts);
	
    (void)Rte_Call_RP_Cpr_GetMsgStatusInfo_CSI_Cpr_RxMessageState_Get_RxMsgStatus(E_CPR_MSG_ID_FR_11E, &s_Med_ErrorInfo.CanPduStatus.FR_11E_PduSts);
	
    (void)Rte_Call_RP_Cpr_GetMsgStatusInfo_CSI_Cpr_RxMessageState_Get_RxMsgStatus(E_CPR_MSG_ID_FR_11F, &s_Med_ErrorInfo.CanPduStatus.FR_11F_PduSts); 
	
    (void)Rte_Call_RP_Cpr_GetMsgStatusInfo_CSI_Cpr_RxMessageState_Get_RxMsgStatus(E_CPR_MSG_ID_FR_120, &s_Med_ErrorInfo.CanPduStatus.FR_120_PduSts); 
	
    (void)Rte_Call_RP_Cpr_GetMsgStatusInfo_CSI_Cpr_RxMessageState_Get_RxMsgStatus(E_CPR_MSG_ID_FR_136, &s_Med_ErrorInfo.CanPduStatus.FR_136_PduSts);
	
    (void)Rte_Call_RP_Cpr_GetMsgStatusInfo_CSI_Cpr_RxMessageState_Get_RxMsgStatus(E_CPR_MSG_ID_FR_138, &s_Med_ErrorInfo.CanPduStatus.FR_138_PduSts);
	
    (void)Rte_Call_RP_Cpr_GetMsgStatusInfo_CSI_Cpr_RxMessageState_Get_RxMsgStatus(E_CPR_MSG_ID_ADC_19B, &s_Med_ErrorInfo.CanPduStatus.ADC_19B_PduSts);
	
    (void)Rte_Call_RP_Cpr_GetMsgStatusInfo_CSI_Cpr_RxMessageState_Get_RxMsgStatus(E_CPR_MSG_ID_ADC_200, &s_Med_ErrorInfo.CanPduStatus.ADC_200_PduSts);

	(void)Rte_Call_RP_Cpr_GetMsgStatusInfo_CSI_Cpr_RxMessageState_Get_RxMsgStatus(E_CPR_MSG_ID_ADC_345, &s_Med_ErrorInfo.CanPduStatus.ADC_345_PduSts);
	
    (void)Rte_Call_RP_Cpr_GetMsgStatusInfo_CSI_Cpr_RxMessageState_Get_RxMsgStatus(E_CPR_MSG_ID_ADC_346, &s_Med_ErrorInfo.CanPduStatus.ADC_346_PduSts);
#endif

	return RTE_E_OK;
}

/**
 * \functions Med_u_Provided_Port
 *
 * \brief 
 *
 ** \param[in] none,
 *
 ** \param[out] none,
 *
 ** \return RTE_E_OK, 
 * \comments
 *
 */
static FUNC(Std_ReturnType, RTE_CODE) Med_u_Provided_Port(void)
{
#if ((defined MED_SENDFCSTATUS_ENABLED) && (MED_SENDFCSTATUS_ENABLED == STD_ON))

	(void)Com_SendSignal(ComConf_ComGroupSignal_FC_CameraCalibrationStatus_400T, &s_Med_ErrorInfo.FCStatus.ui8_CameraCalibrationStatus);

	(void)Com_SendSignal(ComConf_ComGroupSignal_FC_CameraFailureStatus_400T, &s_Med_ErrorInfo.FCStatus.ui8_CameraFailureStatus);
	
	(void)Com_SendSignal(ComConf_ComSignal_SGFC_AEBTextInfo_264T, &s_Med_ErrorInfo.FCStatus.ui8_AEBTextInfoStatus);
#endif

	return RTE_E_OK;
}


