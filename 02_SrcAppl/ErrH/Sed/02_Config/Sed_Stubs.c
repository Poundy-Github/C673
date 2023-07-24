/**
 * \file Sed_Stubs.c
 *
 * \brief
 *
 * \version refer the Sed_Core.h.
 *
 */
/* ==================[Includes]=============================================== */
#include <Rte_Sed.h>
#include <Rte_Dem_Type.h>
#include "Sed_Cfg.h"
#include "Sed_Stubs.h"
#include "Sdc_Core.h"
#include "Sdc_SendInterface.h"
#include "Cdd_HeartbeatDet.h"
//#include "Med_Stubs.h"
#include "Esh_Main.h"

/*==================[external data definition]==============================*/


/*==================[internal data definition]==============================*/
#if ((defined SED_ENABLECONDITION_ENABLE) && (SED_ENABLECONDITION_ENABLE == STD_ON))
static s_Esh_EnableCondition_t s_Sed_EnableCondition;
#endif


/*==================[internal function declarations]========================*/



/*==================[external function definitions]=========================*/
#define Sed_START_SEC_CODE
#include <Sed_MemMap.h>
/**
 * \functions Sed_UserInitFunction
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
#if ((defined SED_USERINITFUNCTION_ENABLE) && (SED_USERINITFUNCTION_ENABLE == STD_ON))
FUNC(void, RTE_CODE) Sed_UserInitFunction (void)
{

} 
#endif

/**
 * \functions Sed_UserMainFunction
 *
 * \brief This function only use for do some userdata operation.
 *
 ** \param[in] none,
 *
 ** \param[out] none,
 *
 ** \return RTE_E_OK, 
 * \comments
 *
 */
#if ((defined SED_USERMAINFUNCTION_ENABLE) && (SED_USERMAINFUNCTION_ENABLE == STD_ON))
FUNC(void, RTE_CODE) Sed_UserMainFunction (void)
{
#if ((defined SED_ENABLECONDITION_ENABLE) && (SED_ENABLECONDITION_ENABLE == STD_ON))
	(void)Esh_u_EnableCondition_Read(&s_Sed_EnableCondition);
#endif

} 
#endif

/**
 * \functions Sed_EnableCondition_SocTimeSyncError
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
FUNC(boolean, RTE_CODE) Sed_EnableCondition_SocTimeSyncError(void)
{
	boolean b_RetVal = FALSE;

#if ((defined SED_ENABLECONDITION_ENABLE) && (SED_ENABLECONDITION_ENABLE == STD_ON))	
	if((s_Sed_EnableCondition.VoltageNormal == SED_EC_ACTIVE)  \
	&& (s_Sed_EnableCondition.Poweron3000ms == SED_EC_ACTIVE)  \
	&& (s_Sed_EnableCondition.BCMPowerModeState == SED_EC_ACTIVE) \
	&& (s_Sed_EnableCondition.Poweron15000ms == SED_EC_ACTIVE))
	{
		b_RetVal = TRUE; /* Satisfy Preconditions */
	}
	else
	{
		b_RetVal = FALSE; /* NOT Satisfy Preconditions, NO DTC */
	}
#endif
	return b_RetVal;

}

/**
 * \functions Sed_EnableCondition_SocSystemKernelError
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
FUNC(boolean, RTE_CODE) Sed_EnableCondition_SocSystemKernelError(void)
{
	boolean b_RetVal = FALSE;
#if ((defined SED_ENABLECONDITION_ENABLE) && (SED_ENABLECONDITION_ENABLE == STD_ON))	
	if((s_Sed_EnableCondition.VoltageNormal == SED_EC_ACTIVE)  \
	&& (s_Sed_EnableCondition.Poweron3000ms == SED_EC_ACTIVE)  \
	&& (s_Sed_EnableCondition.Poweron15000ms == SED_EC_ACTIVE))
	{
		b_RetVal = TRUE; /* Satisfy Preconditions */
	}
	else
	{
		b_RetVal = FALSE; /* NOT Satisfy Preconditions, NO DTC */
	}
#endif
	return b_RetVal;

}

/**
 * \functions Sed_EnableCondition_SocSystemServiceError
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
FUNC(boolean, RTE_CODE) Sed_EnableCondition_SocSystemServiceError(void)
{
	boolean b_RetVal = FALSE;
#if ((defined SED_ENABLECONDITION_ENABLE) && (SED_ENABLECONDITION_ENABLE == STD_ON))	
	if((s_Sed_EnableCondition.VoltageNormal == SED_EC_ACTIVE)  \
	&& (s_Sed_EnableCondition.Poweron3000ms == SED_EC_ACTIVE)  \
	&& (s_Sed_EnableCondition.BCMPowerModeState == SED_EC_ACTIVE) \
	&& (s_Sed_EnableCondition.Poweron15000ms == SED_EC_ACTIVE))
	{
		b_RetVal = TRUE; /* Satisfy Preconditions */
	}
	else
	{
		b_RetVal = FALSE; /* NOT Satisfy Preconditions, NO DTC */
	}
#endif
	return b_RetVal;
}

/**
 * \functions Sed_EnableCondition_SocCameraError
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
FUNC(boolean, RTE_CODE) Sed_EnableCondition_SocCameraError(void)
{
	boolean b_RetVal = FALSE;
#if ((defined SED_ENABLECONDITION_ENABLE) && (SED_ENABLECONDITION_ENABLE == STD_ON))	
	if((s_Sed_EnableCondition.VoltageNormal == SED_EC_ACTIVE)  \
	&& (s_Sed_EnableCondition.Poweron3000ms == SED_EC_ACTIVE)  \
	&& (s_Sed_EnableCondition.Poweron15000ms == SED_EC_ACTIVE))
	{
		b_RetVal = TRUE; /* Satisfy Preconditions */
	}
	else
	{
		b_RetVal = FALSE; /* NOT Satisfy Preconditions, NO DTC */
	}
#endif
	return b_RetVal;
}

/**
 * \functions Sed_EnableCondition_SocSafetylibError
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
FUNC(boolean, RTE_CODE) Sed_EnableCondition_SocSafetylibError(void)
{
	boolean b_RetVal = FALSE;
#if ((defined SED_ENABLECONDITION_ENABLE) && (SED_ENABLECONDITION_ENABLE == STD_ON))	
	if((s_Sed_EnableCondition.VoltageNormal == SED_EC_ACTIVE)  \
	&& (s_Sed_EnableCondition.Poweron3000ms == SED_EC_ACTIVE)  \
	&& (s_Sed_EnableCondition.Poweron15000ms == SED_EC_ACTIVE))
	{
		b_RetVal = TRUE; /* Satisfy Preconditions */
	}
	else
	{
		b_RetVal = FALSE; /* NOT Satisfy Preconditions, NO DTC */
	}
#endif
	return b_RetVal;
}

/**
 * \functions Sed_EnableCondition_SocPerceptionError
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
FUNC(boolean, RTE_CODE) Sed_EnableCondition_SocPerceptionError(void)
{
	boolean b_RetVal = FALSE;
#if ((defined SED_ENABLECONDITION_ENABLE) && (SED_ENABLECONDITION_ENABLE == STD_ON))	
	if((s_Sed_EnableCondition.VoltageNormal == SED_EC_ACTIVE)  \
	&& (s_Sed_EnableCondition.Poweron3000ms == SED_EC_ACTIVE)  \
	&& (s_Sed_EnableCondition.BCMPowerModeState == SED_EC_ACTIVE) \
	&& (s_Sed_EnableCondition.Poweron15000ms == SED_EC_ACTIVE))
	{
		b_RetVal = TRUE; /* Satisfy Preconditions */
	}
	else
	{
		b_RetVal = FALSE; /* NOT Satisfy Preconditions, NO DTC */
	}
#endif
	return b_RetVal;
}

/**
 * \functions Sed_EnableCondition_CPUErrorPWMMissing
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
FUNC(boolean, RTE_CODE) Sed_EnableCondition_CPUErrorPWMMissing(void)
{
	boolean b_RetVal = FALSE;
#if ((defined SED_ENABLECONDITION_ENABLE) && (SED_ENABLECONDITION_ENABLE == STD_ON))	
	if((s_Sed_EnableCondition.VoltageNormal == SED_EC_ACTIVE)  \
	&& (s_Sed_EnableCondition.Poweron3000ms == SED_EC_ACTIVE))
	{
		b_RetVal = TRUE; /* Satisfy Preconditions */
	}
	else
	{
		b_RetVal = FALSE; /* NOT Satisfy Preconditions, NO DTC */
	}
#endif
	return b_RetVal;
}

/**
 * \functions Sed_EnableCondition_SocTempExtTooHigh
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
FUNC(boolean, RTE_CODE) Sed_EnableCondition_SocTempExtTooHigh(void)
{
	boolean b_RetVal = FALSE;
#if ((defined SED_ENABLECONDITION_ENABLE) && (SED_ENABLECONDITION_ENABLE == STD_ON))	
	if((s_Sed_EnableCondition.VoltageNormal == SED_EC_ACTIVE)  \
	&& (s_Sed_EnableCondition.Poweron3000ms == SED_EC_ACTIVE))
	{
		b_RetVal = TRUE; /* Satisfy Preconditions */
	}
	else
	{
		b_RetVal = FALSE; /* NOT Satisfy Preconditions, NO DTC */
	}
#endif
	return b_RetVal;
}

/**
 * \functions Sed_EnableCondition_CameraBlockage
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
FUNC(boolean, RTE_CODE) Sed_EnableCondition_CameraBlockage(void)
{
	boolean b_RetVal = FALSE;
#if ((defined SED_ENABLECONDITION_ENABLE) && (SED_ENABLECONDITION_ENABLE == STD_ON))	
	if((s_Sed_EnableCondition.VoltageNormal == SED_EC_ACTIVE)  \
	&& (s_Sed_EnableCondition.Poweron3000ms == SED_EC_ACTIVE)  \
	&& (s_Sed_EnableCondition.Poweron15000ms == SED_EC_ACTIVE))
	{
		b_RetVal = TRUE; /* Satisfy Preconditions */
	}
	else
	{
		b_RetVal = FALSE; /* NOT Satisfy Preconditions, NO DTC */
	}
#endif
	return b_RetVal;
}
 
/**
 * \functions Sed_EnableCondition_CameraBlockage
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
FUNC(boolean, RTE_CODE) Sed_EnableCondition_EthUnexpectedLinkDown(void)
{
	boolean b_RetVal = FALSE;
#if ((defined SED_ENABLECONDITION_ENABLE) && (SED_ENABLECONDITION_ENABLE == STD_ON))	
	if((s_Sed_EnableCondition.VoltageNormal == SED_EC_ACTIVE))
	{
		b_RetVal = TRUE; /* Satisfy Preconditions */
	}
	else
	{
		b_RetVal = FALSE; /* NOT Satisfy Preconditions, NO DTC */
	}
#endif
	return b_RetVal;
}

/**
 * \functions Sed_EnableCondition_EthDriverAbnormal
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
FUNC(boolean, RTE_CODE) Sed_EnableCondition_EthDriverAbnormal(void)
{
	boolean b_RetVal = FALSE;
#if ((defined SED_ENABLECONDITION_ENABLE) && (SED_ENABLECONDITION_ENABLE == STD_ON))	
	if((s_Sed_EnableCondition.VoltageNormal == SED_EC_ACTIVE))
	{
		b_RetVal = TRUE; /* Satisfy Preconditions */
	}
	else
	{
		b_RetVal = FALSE; /* NOT Satisfy Preconditions, NO DTC */
	}
#endif
	return b_RetVal;
}

/**
 * \functions Sed_EnableCondition_CameraCalibrationFailure
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
FUNC(boolean, RTE_CODE) Sed_EnableCondition_CameraCalibrationFailure(void)
{
	boolean b_RetVal = FALSE;
#if ((defined SED_ENABLECONDITION_ENABLE) && (SED_ENABLECONDITION_ENABLE == STD_ON))	
	if((s_Sed_EnableCondition.VoltageNormal == SED_EC_ACTIVE) \
	 &&(s_Sed_EnableCondition.Poweron3000ms == SED_EC_ACTIVE) \
	 &&(s_Sed_EnableCondition.Poweron15000ms == SED_EC_ACTIVE))
	{
		b_RetVal = TRUE; /* Satisfy Preconditions */
	}
	else
	{
		b_RetVal = FALSE; /* NOT Satisfy Preconditions, NO DTC */
	}
#endif
	return b_RetVal;
}

/**
 * \functions Sed_EnableCondition_CameraAutoCalibrationFailure
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
FUNC(boolean, RTE_CODE) Sed_EnableCondition_CameraAutoCalibrationFailure(void)
{
	boolean b_RetVal = FALSE;
#if ((defined SED_ENABLECONDITION_ENABLE) && (SED_ENABLECONDITION_ENABLE == STD_ON))	
	if((s_Sed_EnableCondition.VoltageNormal == SED_EC_ACTIVE) \
	 &&(s_Sed_EnableCondition.Poweron3000ms == SED_EC_ACTIVE) \
	 &&(s_Sed_EnableCondition.Poweron15000ms == SED_EC_ACTIVE))
	{
		b_RetVal = TRUE; /* Satisfy Preconditions */
	}
	else
	{
		b_RetVal = FALSE; /* NOT Satisfy Preconditions, NO DTC */
	}
#endif
	return b_RetVal;
}

/**
 * \functions Sed_EnableCondition_EthCrcError
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
FUNC(boolean, RTE_CODE) Sed_EnableCondition_EthCrcError(void)
{
	boolean b_RetVal = FALSE;
#if ((defined SED_ENABLECONDITION_ENABLE) && (SED_ENABLECONDITION_ENABLE == STD_ON))	
	if(s_Sed_EnableCondition.VoltageNormal == SED_EC_ACTIVE)
	{
		b_RetVal = TRUE; /* Satisfy Preconditions */
	}
	else
	{
		b_RetVal = FALSE; /* NOT Satisfy Preconditions, NO DTC */
	}
#endif
	return b_RetVal;
}

/**
 * \functions Sed_EnableCondition_EthLinkSignalWake
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
FUNC(boolean, RTE_CODE) Sed_EnableCondition_EthLinkSignalWake(void)
{
	boolean b_RetVal = FALSE;
#if ((defined SED_ENABLECONDITION_ENABLE) && (SED_ENABLECONDITION_ENABLE == STD_ON))	
	if(s_Sed_EnableCondition.VoltageNormal == SED_EC_ACTIVE)
	{
		b_RetVal = TRUE; /* Satisfy Preconditions */
	}
	else
	{
		b_RetVal = FALSE; /* NOT Satisfy Preconditions, NO DTC */
	}
#endif
	return b_RetVal;
}

/**
 * \functions Sed_EnableCondition_EthCableFault
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
FUNC(boolean, RTE_CODE) Sed_EnableCondition_EthCableFault(void)
{
	boolean b_RetVal = FALSE;
#if ((defined SED_ENABLECONDITION_ENABLE) && (SED_ENABLECONDITION_ENABLE == STD_ON))	
	if(s_Sed_EnableCondition.VoltageNormal == SED_EC_ACTIVE)
	{
		b_RetVal = TRUE; /* Satisfy Preconditions */
	}
	else
	{
		b_RetVal = FALSE; /* NOT Satisfy Preconditions, NO DTC */
	}
#endif
	return b_RetVal;
}

/**
 * \functions Sed_EnableCondition_EthIcmpError
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
FUNC(boolean, RTE_CODE) Sed_EnableCondition_EthIcmpError(void)
{
	boolean b_RetVal = FALSE;
#if ((defined SED_ENABLECONDITION_ENABLE) && (SED_ENABLECONDITION_ENABLE == STD_ON))	
	if(s_Sed_EnableCondition.VoltageNormal == SED_EC_ACTIVE)
	{
		b_RetVal = TRUE; /* Satisfy Preconditions */
	}
	else
	{
		b_RetVal = FALSE; /* NOT Satisfy Preconditions, NO DTC */
	}
#endif
	return b_RetVal;
}


/**
 * \functions Sed_Cot_TestFailed_CameraAutoCalibrationFailure
 *
 * \brief   
 *
 ** \param[in] none,
 *
 ** \param[out] none,
 *
 ** \return none, 
 * \comments
 * Confirm Condition:
 * When J3 sent message (any of these)(ADASErrMap,module_id,event_id
 * -bit15,0xA006,0x0001;bit16,0xA006,0x0002;bit17,0xA006,0x0003;) to mcu.
 *
 */
FUNC(boolean, RTE_CODE) Sed_TestFailed_CameraAutoCalibrationFailure(void) 			
{
    boolean b_RetVal = FALSE;
	
	s_Sdc_SocDiagInfo_Type p_Data;
	Rte_Call_RP_Sdc_SendInterface_Diag_SocDiagInfo_Read(SED_GROUPID_ADASErrMap, &p_Data);
	
	uint8 ui8_length = p_Data.FaultDataLength;
	
	if(ui8_length >= 4U)
	{
		uint16 ui16_FaultDataCUT0 = (p_Data.FaultData[ui8_length-2] << 8U) | (p_Data.FaultData[ui8_length-1]); /* bit 0-15 */
		uint16 ui16_FaultDataCUT1 = (p_Data.FaultData[ui8_length-4] << 8U) | (p_Data.FaultData[ui8_length-3]); /* bit 16-31 */

		if((ui16_FaultDataCUT0 & SED_BITMASK_adas_0_diagnose_online_calibration_pitch)   \
			|| (ui16_FaultDataCUT1 & SED_BITMASK_adas_0_diagnose_online_calibration_yaw)  \
			|| (ui16_FaultDataCUT1 & SED_BITMASK_adas_0_diagnose_online_calibration_roll))
		{
			b_RetVal = TRUE;
		}
		else
		{
			b_RetVal = FALSE;
		}
	}
	else
	{/*Do nothing.*/}		

	return b_RetVal;
}

/**
 * \functions Sed_Cot_TestFailed_CameraCalibrationFailure
 *
 * \brief   
 *
 ** \param[in] none,
 *
 ** \param[out] none,
 *
 ** \return none, 
 * \comments
 * Confirm Condition:
 * When J3 sent message (all of these)(SystemServiceErrMap,module_id,event_id
 * bit62,0x9015,0x0001;bit63,0x9015,0x0002;) to mcu.
 * (no valid calibrated parameter)
 *
 */
FUNC(boolean, RTE_CODE) Sed_TestFailed_CameraCalibrationFailure(void) 			
{
	boolean b_RetVal = FALSE;

	s_Sdc_SocDiagInfo_Type p_Data;
	Rte_Call_RP_Sdc_SendInterface_Diag_SocDiagInfo_Read(SED_GROUPID_SystemServiceErrMap, &p_Data);
	
	uint8 ui8_length = p_Data.FaultDataLength;

	if(ui8_length >= 8U)
	{
		uint16 ui16_FaultDataCUT3 = (p_Data.FaultData[ui8_length-8] << 8U) | (p_Data.FaultData[ui8_length-7]); /* bit 48-63 */
	
		if((ui16_FaultDataCUT3 & SED_BITMASK_SystemServiceErrMap_Reserved_bit62)  \
			&& (ui16_FaultDataCUT3 & SED_BITMASK_SystemServiceErrMap_Reserved_bit63))
		{
			b_RetVal = TRUE;
		}
		else
		{
			b_RetVal = FALSE;
		}
	}
	else
	{/*Do nothing.*/}

	return b_RetVal;
}

/**
 * \functions Sed_Cot_TestFailed_SocTempExtTooHigh
 *
 * \brief   
 *
 ** \param[in] none,
 *
 ** \param[out] none,
 *
 ** \return none, 
 * \comments
 * Confirm Condition:
 * SOC Internal temperature is > 125℃  (after initialization)
 * When J3 sent message (any of these) (Safetylib,module_id,event_id------bit9,0x4005,0x0001;) to MCU.
 *
 */
FUNC(boolean, RTE_CODE) Sed_TestFailed_SocTempExtTooHigh(void)
{
	boolean b_RetVal = FALSE;

	s_Sdc_SocDiagInfo_Type p_Data;
	Rte_Call_RP_Sdc_SendInterface_Diag_SocDiagInfo_Read(SED_GROUPID_SAFETYLIB, &p_Data);
	
	uint8 ui8_length = p_Data.FaultDataLength;

	if(ui8_length >= 2U)
	{
		uint16 ui16_FaultDataCUT0 = (p_Data.FaultData[ui8_length-2] << 8U) | (p_Data.FaultData[ui8_length-1]); /* bit 0-15 */

		if(ui16_FaultDataCUT0 & SED_BITMASK_soc_temperature_check)
		{
			b_RetVal = TRUE;
		}
		else
		{
			b_RetVal = FALSE;
		}
	}
	else
	{/*Do nothing.*/}

	return b_RetVal;
} 

/**
 * \functions Sed_Cot_TestFailed_CameraBlockage
 *
 * \brief   
 *
 ** \param[in] none,
 *
 ** \param[out] none,
 *
 ** \return none, 
 * \comments
 * When J3 sent message (any of these)(ADASErrMap,module_id,event_id
 * bit3,0xA001,0x0004;bit4,0xA001,0x0005;bit5,0xA001,0x0006;) to mcu for 300s
 *
 */	
FUNC(boolean, RTE_CODE) Sed_TestFailed_CameraBlockage(void)
{
	boolean b_RetVal = FALSE;

	s_Sdc_SocDiagInfo_Type p_Data ;
	Rte_Call_RP_Sdc_SendInterface_Diag_SocDiagInfo_Read(SED_GROUPID_ADASErrMap, &p_Data);

	uint8 ui8_length = p_Data.FaultDataLength;
	
	if(ui8_length >= 2U)
	{
		uint16 ui16_FaultDataCUT0 = (p_Data.FaultData[ui8_length-2] << 8U) | (p_Data.FaultData[ui8_length-1]); /* bit 0-15 */

		if((ui16_FaultDataCUT0 & SED_BITMASK_adas_0_diagnose_image_covered)  \
		|| (ui16_FaultDataCUT0 & SED_BITMASK_adas_0_diagnose_image_blurred)  \
		|| (ui16_FaultDataCUT0 & SED_BITMASK_adas_0_diagnose_image_glare))
		{
			b_RetVal = TRUE;
		}
		else
		{
			b_RetVal = FALSE;
		}
	}
	else
	{/*Do nothing.*/}

	return b_RetVal;
}

/**
 * \functions Sed_Cot_TestFailed_EthUnexpectedLinkDown
 *
 * \brief   
 *
 ** \param[in] none,
 *
 ** \param[out] none,
 *
 ** \return none, 
 * \comments
 * When J3 sent message (ETH_link_down:SystemServiceErrMap bit9=1,module_id:0x9025,event_id:0x0001,dtc_id:0x200A) to mcu
 *
 */	
FUNC(boolean, RTE_CODE) Sed_TestFailed_EthUnexpectedLinkDown(void)
{
	boolean b_RetVal = FALSE;
	s_Sdc_SocDiagInfo_Type p_Data;
	Rte_Call_RP_Sdc_SendInterface_Diag_SocDiagInfo_Read(SED_GROUPID_SystemServiceErrMap, &p_Data);
	
	uint8 ui8_length = p_Data.FaultDataLength;

	if(ui8_length >= 2U)
	{
		uint16 ui16_FaultDataCUT0 = (p_Data.FaultData[ui8_length-2] << 8) | (p_Data.FaultData[ui8_length-1]); /* bit 0-15 */

		if(ui16_FaultDataCUT0 & SED_BITMASK_ETH_link_down)
		{
			b_RetVal = TRUE;
		}
		else
		{
			b_RetVal = FALSE;
		}
	}
	else
	{/*Do nothing.*/}

	return b_RetVal;
}

/**
 * \functions Sed_Cot_TestFailed_EthDriverAbnormal
 *
 * \brief   
 *
 ** \param[in] none,
 *
 ** \param[out] none,
 *
 ** \return none, 
 * \comments
 * When J3 sent message (kernel_ethernet:SystemKernalErrMap bit30=1,module_id:0x0007,event_id:0x0001,dtc_id:0x001F) to mcu
 *
 */	
FUNC(boolean, RTE_CODE) Sed_TestFailed_EthDriverAbnormal(void)
{
	boolean b_RetVal = FALSE;

	s_Sdc_SocDiagInfo_Type p_Data;
	Rte_Call_RP_Sdc_SendInterface_Diag_SocDiagInfo_Read(SED_GROUPID_SystemKernelErrMap, &p_Data);
	
	uint8 ui8_length = p_Data.FaultDataLength;

	if(ui8_length >= 4U)
	{
		uint16 ui16_FaultDataCUT1 = (p_Data.FaultData[ui8_length-4] << 8U) | (p_Data.FaultData[ui8_length-3]); /* bit 16-31 */

		if(ui16_FaultDataCUT1 & SED_BITMASK_kernel_ethernet)
		{
			b_RetVal = TRUE;
		}
		else
		{
			b_RetVal = FALSE;
		}
	}
	else
	{/*Do nothing.*/}

	return b_RetVal;
}

/**
 * \functions Sed_Cot_TestFailed_SocSystemKernelError
 *
 * \brief   
 *
 ** \param[in] none,
 *
 ** \param[out] none,
 *
 ** \return none, 
 * \comments
 * Confirm Condition:
 * bit0,0x0002,0x0001;bit12,0x0003,0x0007;bit13,0x0003,0x0008;bit17,0x0003,0x000C;
 * bit18,0x0003,0x0006;bit23,0x0004,0x0001;bit24,0x0004,0x0002;bit33,0x0008,0x0003;
 * bit34,0x0009,0x0001;bit36,0x000B,0x0001;bit39,0x000C,0x000E;bit40,0x000C,0x000F;
 * bit41,0x000C,0x001D;bit42,0x000C,0x001E;bit43,0x000C,0x001F;bit44,0x000D,0x0001;
 * bit52,0x000E,0x0005;bit53,0x000E,0x0006
 *
 */
FUNC(boolean, RTE_CODE) Sed_TestFailed_SocSystemKernelError(void) 			
{
	static boolean b_RetVal = FALSE;
	
	s_Sdc_SocDiagInfo_Type p_Data;

	(void)Rte_Call_RP_Sdc_SendInterface_Diag_SocDiagInfo_Read(SED_GROUPID_SystemKernelErrMap, &p_Data);

	uint8 ui8_length = p_Data.FaultDataLength;
	
	if(ui8_length >= 8U)
	{
		uint16 ui16_FaultDataCUT0 = (p_Data.FaultData[ui8_length-2] << 8U) | (p_Data.FaultData[ui8_length-1]); /* bit 0-15 */
		uint16 ui16_FaultDataCUT1 = (p_Data.FaultData[ui8_length-4] << 8U) | (p_Data.FaultData[ui8_length-3]); /* bit 16-31 */
		uint16 ui16_FaultDataCUT2 = (p_Data.FaultData[ui8_length-6] << 8U) | (p_Data.FaultData[ui8_length-5]); /* bit 32-47 */
		uint16 ui16_FaultDataCUT3 = (p_Data.FaultData[ui8_length-8] << 8U) | (p_Data.FaultData[ui8_length-7]); /* bit 48-63 */

		if((ui16_FaultDataCUT0 & SED_BITMASK_KERNEL_GROUPCUT0)
			||(ui16_FaultDataCUT1 & SED_BITMASK_KERNEL_GROUPCUT1)
			||(ui16_FaultDataCUT2 & SED_BITMASK_KERNEL_GROUPCUT2)
			||(ui16_FaultDataCUT3 & SED_BITMASK_KERNEL_GROUPCUT3)
		)
		{
			b_RetVal = TRUE;
		}
		else
		{
			b_RetVal = FALSE;
		}
	}
	else
	{/*Do nothing.*/}
	return b_RetVal;	
} 

/**
 * \functions Sed_Cot_TestFailed_SocSystemServiceError
 *
 * \brief   
 *
 ** \param[in] none,
 *
 ** \param[out] none,
 *
 ** \return none, 
 * \comments
 * bit0,0x9010,0x0001;bit1,0x9010,0x0002;bit2,0x9021,0x0003;bit3,0x9021,0x0001;
 * bit15,0x9010,0x0004;bit22,0x9012,0x0001;bit65,0x9017,0x0001
 *
 */
FUNC(boolean, RTE_CODE) Sed_TestFailed_SocSystemServiceError(void)
{
	static boolean b_RetVal = FALSE;

	s_Sdc_SocDiagInfo_Type p_Data;
	
	(void)Rte_Call_RP_Sdc_SendInterface_Diag_SocDiagInfo_Read(SED_GROUPID_SystemServiceErrMap, &p_Data);

	uint8 ui8_length = p_Data.FaultDataLength;
	
	if(ui8_length >= 10U)
	{
		uint16 ui16_FaultDataCUT0 = (p_Data.FaultData[ui8_length-2] << 8U) | (p_Data.FaultData[ui8_length-1]); /* bit 0-15 */
		uint16 ui16_FaultDataCUT1 = (p_Data.FaultData[ui8_length-4] << 8U) | (p_Data.FaultData[ui8_length-3]); /* bit 16-31 */
		uint16 ui16_FaultDataCUT4 = (p_Data.FaultData[ui8_length-10] << 8U) | (p_Data.FaultData[ui8_length-9]); /* bit 64-79 */

		if((ui16_FaultDataCUT0 & SED_BITMASK_SYSSERVICE_GROUPCUT0)
			||(ui16_FaultDataCUT1 & SED_BITMASK_SYSSERVICE_GROUPCUT1)
			||(ui16_FaultDataCUT4 & SED_BITMASK_SYSSERVICE_GROUPCUT4)
		)
		{ 
			b_RetVal = TRUE;
		}
		else
		{
			b_RetVal = FALSE;
		}
	}
	else
	{/*Do nothing.*/}		

	return b_RetVal;
}

/**
 * \functions Sed_Cot_TestFailed_SocPerceptionError
 *
 * \brief   
 *
 ** \param[in] none,
 *
 ** \param[out] none,
 *
 ** \return none, 
 * \comments
 * Confirm Condition:
 * bit0, 0xA001,0x0001;bit1, 0xA001,0x0002;bit9, 0xA003,0x0001;
 * bit10,0xA003,0x0002;bit13,0xA005,0x0001;bit14,0xA005,0x0002;
 * bit18,0xA007,0x0001;bit19,0xA007,0x0002;bit20,0xA007,0x0003;
 * bit21,0xA007,0x0004;bit28,0xA009,0x0001;bit29,0xA009,0x0002;
 * bit30,0xA009,0x0003;bit31,0xA009,0x0004;bit32,0xA009,0x0005;
 * bit33,0xA009,0x0006;bit34,0xA009,0x0007;bit35,0xA009,0x0008;
 * bit36,0xA009,0x0009;bit40,0XA005,0x0003;bit46,0xA00D,0x0001;
 * bit47,0xA00E, 0x0001;bit48,0xA00F,0x0001
 *
 */
FUNC(boolean, RTE_CODE) Sed_TestFailed_SocPerceptionError(void)
{
	static boolean b_RetVal = FALSE;

	s_Sdc_SocDiagInfo_Type p_Data;
	
	(void)Rte_Call_RP_Sdc_SendInterface_Diag_SocDiagInfo_Read(SED_GROUPID_ADASErrMap, &p_Data);

	uint8 ui8_length = p_Data.FaultDataLength; //The max length of data length is 7.

	if(ui8_length >= 7U)
	{
		uint16 ui16_FaultDataCUT0 = (p_Data.FaultData[ui8_length-2] << 8U) | (p_Data.FaultData[ui8_length-1]); /* bit 0-15 */
		uint16 ui16_FaultDataCUT1 = (p_Data.FaultData[ui8_length-4] << 8U) | (p_Data.FaultData[ui8_length-3]); /* bit 16-31 */
		uint16 ui16_FaultDataCUT2 = (p_Data.FaultData[ui8_length-6] << 8U) | (p_Data.FaultData[ui8_length-5]); /* bit 32-47 */
		uint16 ui16_FaultDataCUT3 = (uint16)(p_Data.FaultData[ui8_length-7]); /* bit 48-55 */

		if((ui16_FaultDataCUT0 & SED_BITMASK_ADAS_0_DIAGNOSE_GROUPCUT0)
			||(ui16_FaultDataCUT1 & SED_BITMASK_ADAS_0_DIAGNOSE_GROUPCUT1)
			||(ui16_FaultDataCUT2 & SED_BITMASK_ADAS_0_DIAGNOSE_GROUPCUT2)
			||(ui16_FaultDataCUT3 & SED_BITMASK_ADAS_0_DIAGNOSE_GROUPCUT3)
		)
		{
			b_RetVal = TRUE;
		}
		else
		{
			b_RetVal = FALSE;
		}
	}
	else
	{/*Do nothing.*/}	

	return b_RetVal;
}

/**
 * \functions Sed_Cot_TestFailed_SocCameraError
 *
 * \brief   
 *
 ** \param[in] none,
 *
 ** \param[out] none,
 *
 ** \return none, 
 * \comments
 *Confirm Condition:
 *bit0,0xC001,0x0001;bit5,0xC002,0x0001;bit25,0xC006,0x0001;bit30,0xC007,0x0001;
 *bit35,0xC008,0x0001;bit50,0xC00A,0x0001
 */
FUNC(boolean, RTE_CODE) Sed_TestFailed_SocCameraError(void)
{
	static boolean b_RetVal = FALSE;

	s_Sdc_SocDiagInfo_Type p_Data;
	
	(void)Rte_Call_RP_Sdc_SendInterface_Diag_SocDiagInfo_Read(SED_GROUPID_CAMERAERR, &p_Data);

	uint8 ui8_length = p_Data.FaultDataLength;

	if(ui8_length >= 8U)
	{
		uint16 ui16_FaultDataCUT0 = (p_Data.FaultData[ui8_length-2] << 8U) | (p_Data.FaultData[ui8_length-1]); /* bit 0-15 */
		uint16 ui16_FaultDataCUT1 = (p_Data.FaultData[ui8_length-4] << 8U) | (p_Data.FaultData[ui8_length-3]); /* bit 16-31 */
		uint16 ui16_FaultDataCUT2 = (p_Data.FaultData[ui8_length-6] << 8U) | (p_Data.FaultData[ui8_length-5]); /* bit 32-47 */
		uint16 ui16_FaultDataCUT3 = (p_Data.FaultData[ui8_length-8] << 8U) | (p_Data.FaultData[ui8_length-7]); /* bit 48-63 */

		if((ui16_FaultDataCUT0 & SED_BITMASK_CAMERA_ERROR_GROUPCUT0)
			|| (ui16_FaultDataCUT1 & SED_BITMASK_CAMERA_ERROR_GROUPCUT1)
			|| (ui16_FaultDataCUT2 & SED_BITMASK_CAMERA_ERROR_GROUPCUT2)
			|| (ui16_FaultDataCUT3 & SED_BITMASK_CAMERA_ERROR_GROUPCUT3))
		{  
			b_RetVal = TRUE;
		}
		else
		{
			b_RetVal = FALSE;
		}
	}
	else
	{/*Do nothing*/}

	return b_RetVal;
}

/**
 * \functions Sed_Cot_TestFailed_SocSafetylibError
 *
 * \brief   
 *
 ** \param[in] none,
 *
 ** \param[out] none,
 *
 ** \return none, 
 * \comments 
 * Confirm Condition:
 * bit2,0x4002,0x0001;bit3,0x4002,0x0002;bit4,0x4002,0x0003;bit5,0x4003,0x0001;
 * bit6,0x4003,0x0002;bit7,0x4004,0x0001;bit8,0x4004,0x0002;
 * bit10,0x4005,0x0002;bit11,0x4006,0x0001;bit12,0x4007,0x0001;bit13,0x4007,0x0002;
 *
 */
FUNC(boolean, RTE_CODE) Sed_TestFailed_SocSafetylibError(void)
{
    static boolean b_RetVal = FALSE;

	s_Sdc_SocDiagInfo_Type p_Data ;
	
	(void)Rte_Call_RP_Sdc_SendInterface_Diag_SocDiagInfo_Read(SED_GROUPID_SAFETYLIB, &p_Data);

	uint8 ui8_length = p_Data.FaultDataLength;
	
	if(ui8_length >= 2U)
	{
		uint16 ui16_FaultDataCUT0 = (p_Data.FaultData[ui8_length-2] << 8U) | (p_Data.FaultData[ui8_length-1]); /* bit 0-15 */

		if(ui16_FaultDataCUT0 & SED_BITMASK_SAFETYLIB_GROUPCUT0)
		{
			b_RetVal = TRUE;
		}
		else
		{
			b_RetVal = FALSE;
		}
	}
	else
	{/*Do nothing.*/}		

	return b_RetVal;
}

/**
 * \functions Sed_Cot_TestFailed_SocTimeSyncError
 *
 * \brief   
 *
 ** \param[in] none,
 *
 ** \param[out] none,
 *
 ** \return none, 
 * \comments  
 * Confirm Condition:
 * bit25,0x9013,0x0001;bit26,0x9013,0x0002;bit27,0x9013,0x0003
 *
 */
FUNC(boolean, RTE_CODE) Sed_TestFailed_SocTimeSyncError(void)
{
    static boolean b_RetVal = FALSE;	 

    s_Sdc_SocDiagInfo_Type p_Data;
	
	(void)Rte_Call_RP_Sdc_SendInterface_Diag_SocDiagInfo_Read(SED_GROUPID_SystemServiceErrMap, &p_Data);

	uint8 ui8_length = p_Data.FaultDataLength;
	
	if(ui8_length >= 4U)
	{
		uint16 ui16_FaultDataCUT1 = (p_Data.FaultData[ui8_length-4] << 8U) | (p_Data.FaultData[ui8_length-3]); /* bit 16-31 */
	
		if((ui16_FaultDataCUT1 & SED_BITMASK_timesync_init_error)   \
			|| (ui16_FaultDataCUT1 & SED_BITMASK_timesync_comm_error)  \
			|| (ui16_FaultDataCUT1 & SED_BITMASK_timesync_delay))
		{
			b_RetVal = TRUE;
		}
		else
		{
			b_RetVal = FALSE;
		}
	}
	else
	{/*Do nothing.*/}

	return b_RetVal;
}

/**
 * \functions Sed_Cot_TestFailed_CPUErrorPWMMissing
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
FUNC(boolean, RTE_CODE) Sed_TestFailed_CPUErrorPWMMissing(void)
{
	static boolean b_RetVal = FALSE;
	
	Enum_HeartbeatDetDetState e_heartbeatstate = HEARTBEATDET_DET_STATE_UNINIT;

	e_heartbeatstate = Cdd_HeartbeatDet_GetDetState();

	if(e_heartbeatstate == HEARTBEATDET_DET_STATE_RUNNINGERROR)
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
 * \functions Sed_Cot_TestFailed_EthCrcError
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
FUNC(boolean, RTE_CODE) Sed_TestFailed_EthCrcError(void)
{
	boolean b_RetVal = FALSE;
	uint8 ui8_EthCrcError = 0x00U;

	Rte_Call_RP_Sdc_SendInterface_Eth_EthCrcError_Read(&ui8_EthCrcError, 1);

	if(ui8_EthCrcError == 0x01U)
	{
		b_RetVal = TRUE;
	}
	else if(ui8_EthCrcError == 0x00U)
	{
		b_RetVal = FALSE;
	}
	else
	{/*Do nothing.*/}

	return b_RetVal;
}

/**
 * \functions Sed_Cot_TestFailed_EthLinkSignalWake
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
FUNC(boolean, RTE_CODE) Sed_TestFailed_EthLinkSignalWake(void)
{
	boolean b_RetVal = FALSE;
	uint8 ui8_EthLinkSignalWake = 0x00U;

    Rte_Call_RP_Sdc_SendInterface_Eth_EthSQI_Read(&ui8_EthLinkSignalWake, 1);

	if(ui8_EthLinkSignalWake == 0x01U)
	{
		b_RetVal = TRUE;
	}
	else if(ui8_EthLinkSignalWake == 0x00U)
	{
		b_RetVal = FALSE;
	}
	else
	{/*Do nothing.*/}

	return b_RetVal;
}

/**
 * \functions Sed_Cot_TestFailed_EthCableFault
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
FUNC(boolean, RTE_CODE) Sed_TestFailed_EthCableFault(void)
{
	boolean b_RetVal = FALSE;
	uint8 ui8_EthCableFault = 0x00U;

    Rte_Call_RP_Sdc_SendInterface_Eth_EthCableFault_Read(&ui8_EthCableFault, 1);
		
	if(ui8_EthCableFault == 0x01U)
	{
		b_RetVal = TRUE;
	}
	else if(ui8_EthCableFault == 0x00U)
	{
		b_RetVal = FALSE;
	}
	else
	{/*Do nothing.*/}

	return b_RetVal;
}

/**
 * \functions Sed_Cot_TestFailed_EthIcmpError
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
FUNC(boolean, RTE_CODE) Sed_TestFailed_EthIcmpError(void)
{
	boolean b_RetVal = FALSE;
	uint8 ui8_EthIcmpError = 0x00U;

    Rte_Call_RP_Sdc_SendInterface_Eth_EthIcmpError_Read(&ui8_EthIcmpError, 1);
		
	if(ui8_EthIcmpError == 0x01U)
	{
		b_RetVal = TRUE;
	}
	else if(ui8_EthIcmpError == 0x00U)
	{
		b_RetVal = FALSE;
	}
	else
	{/*Do nothing.*/}

	return b_RetVal;
}




#define Sed_STOP_SEC_CODE
#include <Sed_MemMap.h>

