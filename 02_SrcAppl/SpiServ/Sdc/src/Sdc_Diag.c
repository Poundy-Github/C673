/* ==================[Includes]=============================================== */
#include "Sdc_Diag.h"
#include "Dcm_Types.h"
#include "Sdc_Core.h"
#include "Com_SymbolicNames_PBcfg.h"	//because of the components shall use the Signal Id
#include "VerInfo.h"
#include "Com.h"
#include <Rte_type.h>
#include <Rte_Sdc.h>
#include "Dsm_Cfg.h"
#include "Sdc_Can_SignalGroup_Variable_Version.h"
#include "Sdc_SendHandler.h"
#include "fs_soc.h"


/*==================[external data]=========================================*/
/*==================[.bss]==============================*/
#define SDC_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "Sdc_MemMap.h"


#define SDC_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "Sdc_MemMap.h"

/*==================[internal data]=========================================*/
/*==================[.data]==============================*/
#define SDC_START_SEC_VAR_INIT_UNSPECIFIED
#include "Sdc_MemMap.h"

static uint8 ADC_Workmode_backup = 0xff;
static uint8 FC_Workmode = 0x01;
static uint8 FC_Workmode_backup = 0x01;
static uint8 ECUSoftwareVersion[7] = {'S', 'W', 'C', '.', '1', '.', '1'};

#define SDC_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Sdc_MemMap.h"

/*==================[.bss]==============================*/
#define SDC_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "Sdc_MemMap.h"

static s_DTC_ETH_V Sdc_Dtc_Eth;
static s_RID_ETH_V Sdc_Rid_Eth;

static uint8 ADC_Workmode = 0;	//1--driving mode  2--parking mode


static uint8 SocEOLCalResults = 0;
static uint8 PwmState = 0;
static uint16 counter_sencemode_changing = 0;
/* drive mode change */
uint16 counter_driver_initvalue = 0;

static s_Sdc_SocSystemInfo_t SocSysInfo_CpuInfo;
static uint8 SocSysInfo_CpuInfo_RawData[24] = {0x00};
static SocToMcu_Data SocToMcu;
uint16 FC_WorkmodeBuf[3] = {0, 0, 0};

static uint16 SocDiag_SysMgr = 0;
static uint8 SocDiagResp_Cnt = 0;
static s_Sdc_SocDiagInfo_Type SocDiagInfo[MAX_SOCDTCGROUP_NUMBER];

#if ((defined SDC_DIAG_INJECTION_ENABLED) && (SDC_DIAG_INJECTION_ENABLED == STD_ON))
static s_Sdc_SocDiagInfo_Type SocDiagInfo_Injection[MAX_SOCDTCGROUP_NUMBER];
#endif

static s_Sdc_CaliResult_Type CaliResult;

static uint8 DID_RID_Pengding_Stu_U8_L  = STD_IDLE;
static uint8 DID_RID_ResponseCnt;
static uint8 Sdc_SocRid_Did_Uls_A150U8[150];
static uint8 MCU_SOC_TXD_Uls_U8_D[30];
static uint8 Dig_inputdata_1[11];

#define SDC_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "Sdc_MemMap.h"

/*==================[.const]==============================*/
#define SDC_START_SEC_CONST_UNSPECIFIED
#include "Sdc_MemMap.h"

static const uint8 ECUHardwareVersion[7] = {'H', 'W', 'C', '.', '1', '.', '1'};

const s_Sdc_HandlerTable_t socsubfuncHdlTable[SDC_SOC_REPLY_SUBFUNC_SIZE] =
{
	{e_Sdc_SpiMsgSubType_ReadSocDiag, Sdc_Diag_SocDiag_vInfoUnpack},
	{e_Sdc_SpiMsgSubType_RequestCaliValue, Sdc_Diag_SocDiag_CaliInfoUnpack},
};

#define SDC_STOP_SEC_CONST_UNSPECIFIED
#include "Sdc_MemMap.h"
/*==================[macros]=================================================*/

/*==================[internal function declarations]========================*/
static void Sdc_Diag_MCURequestFaultList(void);
static void Sdc_Diag_SendCalibrationResult_Ack(uint16 Sub);
static void Sdc_Diag_DriverModeSend(uint8 value);

/*==================[external function definitions]=========================*/
/*==================[.text]==============================*/
#define SDC_START_SEC_CODE
#include "Sdc_MemMap.h"

FUNC(void, RTE_CODE) Sdc_Diag_InitFunction(void)
{
    ECUSoftwareVersion[4] = VERINFO_MCU_SW_MAJOR_VERSION + 0x30;
	ECUSoftwareVersion[6] = VERINFO_MCU_SW_MINOR_VERSION + 0x30;
}
FUNC(void, RTE_CODE) Sdc_Diag_DeInitFunction(void)
{
    
}
FUNC(void, RTE_CODE) Sdc_Diag_MainFunction(void)
{
    static uint32 ui32_Sdc_Diag_MainFunction_Cycle_Counter = 0x00;
	//uint8 J3resetStatus = 0;

	ui32_Sdc_Diag_MainFunction_Cycle_Counter++;

	/*Temporary strategy,the finally strategy shall be confirmed*/
	if(ui32_Sdc_Diag_MainFunction_Cycle_Counter >= 20U) //200ms
	{
		ui32_Sdc_Diag_MainFunction_Cycle_Counter = 0x00U;
		Sdc_Diag_MCURequestFaultList();/*periodly Request DTC List*/
	}
	else
	{
		/*TODO : Doing nothing*/
	}
	
}

/**
 * \functions Sdc_Diag_Sence_Mode
 *
 * \brief J3 Sence Mode judgment, run cycle 5ms
 *
 ** \param[in] none, message function ID
 **
 ** \return E_OK, 
 * \comments  
 *
 */
uint8 Sdc_Diag_Sence_Mode(void)
{
	s_Sdc_MsgSendHandleDataInfo_Event_st Sdc_eventMsgInfo;

	(void)Com_ReceiveSignal(ComConf_ComSignal_SGADC_WorkMode_411R, &ADC_Workmode);
	(void)Com_SendSignal(ComConf_ComGroupSignal_FC_WorkMode_400T, &FC_Workmode);
	if (ADC_Workmode_backup != ADC_Workmode)
	{
		if (ADC_Workmode == 0x00 || ADC_Workmode == 0x01) /*driving mode*/
		{
			FC_Workmode_backup = 0;
			Sdc_Diag_DriverModeSend(FC_Workmode_backup);

			if (ADC_Workmode_backup == 0x02)
			{
				FC_Workmode = 0x03;
				(void)Com_SendSignal(ComConf_ComGroupSignal_FC_WorkMode_400T, &FC_Workmode);
				counter_sencemode_changing = 0;

			}
			else
			{
				FC_Workmode = 0x01;
				(void)Com_SendSignal(ComConf_ComGroupSignal_FC_WorkMode_400T, &FC_Workmode);
			}

			ADC_Workmode_backup = ADC_Workmode;

		}
		else if (ADC_Workmode == 0x02) /*parking mode*/
		{
			FC_Workmode_backup = 5;
			Sdc_Diag_DriverModeSend(FC_Workmode_backup);

			if (ADC_Workmode_backup != 0xff)
			{
				FC_Workmode = 0x03;
				(void)Com_SendSignal(ComConf_ComGroupSignal_FC_WorkMode_400T, &FC_Workmode);
				counter_sencemode_changing = 0;
			}
			else
			{
				FC_Workmode = 0x02;
				(void)Com_SendSignal(ComConf_ComGroupSignal_FC_WorkMode_400T, &FC_Workmode);
			}

			ADC_Workmode_backup = ADC_Workmode;
		}
	}
	else
	{
		if((FC_Workmode != 0x02) && (ADC_Workmode == 0x02))
		{
			counter_driver_initvalue ++;
		}
		else
		{
			counter_driver_initvalue = 0;
		}

		if(counter_driver_initvalue == 1000)
		{
			if(FC_Workmode != 0x02)
			{
				FC_Workmode_backup = 5;
				Sdc_Diag_DriverModeSend(FC_Workmode_backup);
				counter_driver_initvalue = 0;
			}else{}
		}else{}
	}
	if(FC_Workmode == 0x03)
	{
		counter_sencemode_changing++;
		if (counter_sencemode_changing % 600 == 599)	//resend 3 times interval: 600*5ms == 3s
		{
			FC_Workmode_backup = 0;
			Sdc_Diag_DriverModeSend(FC_Workmode_backup);
		}
		else if (counter_sencemode_changing >= 2000)
		{
			FC_Workmode = 0x00;
			(void)Com_SendSignal(ComConf_ComGroupSignal_FC_WorkMode_400T, &FC_Workmode);
			counter_sencemode_changing = 0;
		}
	}
	return TRUE;
}

void Sdc_Diag_SocReplyInfo(const uint8 *data, uint16 length)
{
	uint16 sub = *((uint16 *)data);

	for (uint8 i = 0; i < SDC_SOC_REPLY_SUBFUNC_SIZE; i++)
	{
		if (sub == socsubfuncHdlTable[i].Id)
		{
			socsubfuncHdlTable[i].HandlerFunction(data + 2, length - 2); /*skip sub function*/
		}
	}

	if (sub == e_Sdc_SpiMsgSubType_ReadSocDiag && data[4] == 0x11) /* OM BOOTSENSOR */
	{
		SocToMcu.J3_BOOTSENSOR = data[7];
	}
	if (sub == e_Sdc_SpiMsgSubType_ReadSocDiag && data[4] == 0x10) /* OM sN */
	{
		SocToMcu.J3_OM_SN[0] = data[7];
		SocToMcu.J3_OM_SN[1] = data[8];
		SocToMcu.J3_OM_SN[2] = data[9];
		SocToMcu.J3_OM_SN[3] = data[10];
	}
}

/**
 * \functions Sdc_Diag_TxVersionData
 *
 * \brief
 *
 * \parameters-in none
 *
 * \parameters-out none
 *
 * \return 	none
 *
 * \comments send cycle 1s
 *
 */
FUNC(void, RTE_CODE) Sdc_Diag_TxVersionData(void)
{
	uint8  Version_8  = 0;
	uint16 Version_16 = 0;
	uint8 i = 0;
/*CAN0 FC_571  CAN1 FC_207*/
	for (i = 0; i < 7; i++)
	{
		if(i == 4)
		{
			Version_16 = ECUHardwareVersion[i];
			Com_SendSignal(Sdc_ConsigIdList_Tx_FC_HwVersion_571[i], &Version_16);
			Version_16 = ECUSoftwareVersion[i];
			Com_SendSignal(Sdc_ConsigIdList_Tx_FC_SwVersion_571[i], &Version_16);

			Version_16 = ECUHardwareVersion[i];
			Com_SendSignal(Sdc_ConsigIdList_Tx_FC_HwVersion_207[i], &Version_16);
			Version_16 = ECUSoftwareVersion[i];
			Com_SendSignal(Sdc_ConsigIdList_Tx_FC_SwVersion_207[i], &Version_16);
		}
		else
		{
			Com_SendSignal(Sdc_ConsigIdList_Tx_FC_HwVersion_571[i], ECUHardwareVersion + i);
			Com_SendSignal(Sdc_ConsigIdList_Tx_FC_SwVersion_571[i], ECUSoftwareVersion + i);

			Com_SendSignal(Sdc_ConsigIdList_Tx_FC_HwVersion_207[i], ECUHardwareVersion + i);
			Com_SendSignal(Sdc_ConsigIdList_Tx_FC_SwVersion_207[i], ECUSoftwareVersion + i);
		}
		
	}
	
	return;
}


void Sdc_Diag_DrivemodeChangeReq(const uint8 *data, uint16 length)
{
	uint16 sub = *((uint16 *)data);
	s_Sdc_MsgSendHandleDataInfo_Event_st Sdc_eventMsgInfo;

	/*current drive mode change*/
	// parking mode
	if (sub == e_Sdc_SpiMsgSubType_WorkMode_Req)
	{
		uint8 current_mode = data[4];

		if ((current_mode == 0x05) && (ADC_Workmode == 0x02))
		{
			// parking mode ack
			uint16 UserData[3];
			UserData[0] = 0x00; /*unused*/
			UserData[1] = 0x00;
			UserData[2] = 0x00; /*unused*/

			FC_Workmode = 0x02;
			(void)Com_UpdateShadowSignal(ComConf_ComGroupSignal_FC_WorkMode_400T, &FC_Workmode);
			counter_sencemode_changing = 0;

			Sdc_eventMsgInfo.msgId = e_Sdc_SpiMsgType_Evt_Mcu2J3_0603_WorkingMode_Reserve;
			Sdc_eventMsgInfo.subId = e_Sdc_SpiMsgSubType_WorkMode_Req;
			memcpy(&Sdc_eventMsgInfo.data[0], (uint8 *)&UserData, sizeof(UserData));
			Sdc_eventMsgInfo.len = 6;
			Sdc_SendHandler_SendEventMsg(Sdc_eventMsgInfo);
		}

		else if (((current_mode == 0x00) && (ADC_Workmode == 0x00 || ADC_Workmode == 0x01)))
		{
			// driving mode ack
			uint16 UserData[3];
			UserData[0] = 0x00; /*unused*/
			UserData[1] = 0x00;
			UserData[2] = 0x00; /*unused*/

			FC_Workmode = 0x01;
			(void)Com_UpdateShadowSignal(ComConf_ComGroupSignal_FC_WorkMode_400T, &FC_Workmode);
			counter_sencemode_changing = 0;

			Sdc_eventMsgInfo.msgId = e_Sdc_SpiMsgType_Evt_Mcu2J3_0603_WorkingMode_Reserve;
			Sdc_eventMsgInfo.subId = e_Sdc_SpiMsgSubType_WorkMode_Req;
			memcpy(&Sdc_eventMsgInfo.data[0], (uint8 *)&UserData, sizeof(UserData));
			Sdc_eventMsgInfo.len = 6;
			Sdc_SendHandler_SendEventMsg(Sdc_eventMsgInfo);
		}
	}
}

void Sdc_Diag_DrivemodeChangeAck(const uint8 *data, uint16 length)
{
	//TODO: now not used

}

void Sdc_Diag_SocSysInfo(const uint8 *data, uint16 length)
{
	uint16 sub = *((uint16 *)data);
	uint16 SocDiag_SysMgr_temp = 0;
	/*TODO : Check the sub id*/
	if (sub == e_Sdc_SpiMsgSubType_SetSoc_CPUState_Info)
	{
		memcpy(&SocSysInfo_CpuInfo, data + 4, sizeof(s_Sdc_SocSystemInfo_t));
		memcpy(SocSysInfo_CpuInfo_RawData, data + 4, sizeof(s_Sdc_SocSystemInfo_t)); // use the array transmit to can bus.
	}
	else if (sub == e_Sdc_SpiMsgSubType_SetSoc_State_Info) /*Read sysMgr 0x001E*/
	{
		memcpy(&SocDiag_SysMgr_temp, data + 4, 2);
		Sdc_Diag_SocSysState_Set(SocDiag_SysMgr_temp);
		uint8 SysState = data[4]; /*J3 system status 0x01 = normal*/
		// uint8 Position = data[5];

		// calib_normal();
		SocEOLCalResults = 0x01;
		/*Set calibration status*/
		switch (SysState)
		{
			case e_Sdc_SocSystemStatus_CameraEolCalibration:
			case e_Sdc_SocSystemStatus_CameraOnlineCalibration:
				Sdc_Diag_SetCaliResult_Flag(0x0E);
				break;
			case e_Sdc_SocSystemStatus_CameraEolCalibrationFinish:
				Sdc_Diag_SetCaliResult_Flag(0x02);
				break;
			case e_Sdc_SocSystemStatus_CameraOnlineCalibrationFinish:
				Sdc_Diag_SetCaliResult_Flag(0x05);
				break;
			default:
				break;
		}
	}
	else if (sub == e_Sdc_SpiMsgSubType_SetCalibration_Result || sub == e_Sdc_SpiMsgSubType_SetEOL_Calib_Result) /*0x0018 0x0021*/
	{
		Sdc_Diag_SetCalibrationResult(data, length);
		Sdc_Diag_SendCalibrationResult_Ack(sub);
		Sdc_Diag_RequestCalibrationValue();
	}
	else if (sub == e_Sdc_SpiMsgSubType_SetBootSet_Reboot)
	{
		PwmState = data[4]; /*Pwm state: 0: Disable pwm monitor,1: Enable pwm monitor*/
	}
}

/**
 * \functions Sdc_Diag_RequestSocSupplierSoftwarenumber
 *
 * \brief RequestSoc Supplier Software number to Soc via SPI.
 *
 ** \param[in] none, message function ID
 **
 **    the data package include the below infomation.
 **        byte#0-1: message id
 **        byte#2-3: message data length(start from byte16)
 **        byte#4-7: Protocol id(SPI: 0x00535049 ETH: 0x00455448 UART: Reserved)
 **        byte#8-15: time_stamp: If have the time synchronize with other chip
 **        byte#16-17: Sub-Function
 **        byte#18-...: user data
 ** \return E_OK, 
 * \comments  
 *
 */
FUNC(Std_ReturnType, RTE_CODE) Sdc_Diag_RequestSocSupplierSoftwarenumber(void)
{
    uint8 u_retVal = RTE_E_OK;
	s_Sdc_MsgSendHandleDataInfo_Event_st Sdc_eventMsgInfo;

	// const uint8 a_UserData[1] = {0x01};
	
	Sdc_eventMsgInfo.msgId = e_Sdc_SpiMsgType_Evt_J32Mcu_0605_SocSoftNumReq;
	Sdc_eventMsgInfo.subId = e_Sdc_SpiMsgSubType_J3SoftwareNumReq;
	Sdc_eventMsgInfo.data[0] = 0x01;
	Sdc_eventMsgInfo.len = 1;
	Sdc_SendHandler_SendEventMsg(Sdc_eventMsgInfo);
	return u_retVal;
}
/**
 * \functions Sdc_Diag_RequestOMSN
 *
 * \brief Request OM SN to Soc via SPI.
 *
 ** \param[in] none, message function ID
 **
 **    the data package include the below infomation.
 **        byte#0-1: message id
 **        byte#2-3: message data length(start from byte16)
 **        byte#4-7: Protocol id(SPI: 0x00535049 ETH: 0x00455448 UART: Reserved)
 **        byte#8-15: time_stamp: If have the time synchronize with other chip
 **        byte#16-17: Sub-Function
 **        byte#18-...: user data
 ** \return E_OK, 
 * \comments  
 *
 */
FUNC(Std_ReturnType, RTE_CODE) Sdc_Diag_RequestOMSN(void)
{
    uint8 u_retVal = RTE_E_OK;
	s_Sdc_MsgSendHandleDataInfo_Event_st Sdc_eventMsgInfo;

	const uint8 a_UserData[3] = {0x22,0xF2,0x10};
	
	Sdc_eventMsgInfo.msgId = e_Sdc_SpiMsgType_Evt_Mcu2J3_0202_RequestSocCmd;
	Sdc_eventMsgInfo.subId = e_Sdc_SpiMsgSubType_ReadSocDiag;
	memcpy(&Sdc_eventMsgInfo.data[0], a_UserData, 3);
	Sdc_eventMsgInfo.len = 3;
	Sdc_SendHandler_SendEventMsg(Sdc_eventMsgInfo);
	return u_retVal;
}

/**
 * \functions Sdc_Diag_SocOMSN_Read
 *
 * \brief Copy OMSN from Soc to buffer.
 *
 ** \param[in] length, 
 *
 ** \param[out] Data, Pointer to Data buffer (4 bytes).
 **                  unsigned formatted
 *
 ** \return RTE_E_OK, 
 * \comments  
 *
 */
FUNC(Std_ReturnType, RTE_CODE) Sdc_Diag_SocOMSN_Read(uint8 *data, uint16 length)
{
    Std_ReturnType u_RetVal = RTE_E_OK;
	uint8 len = length > 4 ? 4 : length;
    for(int i =0; i< len;i ++)
    {
        data[i] = SocToMcu.J3_OM_SN[i];
	}

	return u_RetVal;
}

/**
 * \functions Sdc_Diag_RequestBootSensor
 *
 * \brief Request boot sensor to Soc via SPI.
 *
 ** \param[in] none, message function ID
 **
 **    the data package include the below infomation.
 **        byte#0-1: message id
 **        byte#2-3: message data length(start from byte16)
 **        byte#4-7: Protocol id(SPI: 0x00535049 ETH: 0x00455448 UART: Reserved)
 **        byte#8-15: time_stamp: If have the time synchronize with other chip
 **        byte#16-17: Sub-Function
 **        byte#18-...: user data
 ** \return E_OK, 
 * \comments  
 *
 */
FUNC(Std_ReturnType, RTE_CODE) Sdc_Diag_RequestBootSensor(void)
{   
    uint8 u_retVal = RTE_E_OK;
	s_Sdc_MsgSendHandleDataInfo_Event_st Sdc_eventMsgInfo;

	const uint8 a_UserData[3] = {0x22,0xF2,0x11};
	
	Sdc_eventMsgInfo.msgId = e_Sdc_SpiMsgType_Evt_Mcu2J3_0202_RequestSocCmd;
	Sdc_eventMsgInfo.subId = e_Sdc_SpiMsgSubType_ReadSocDiag;
	memcpy(&Sdc_eventMsgInfo.data[0], a_UserData, 3);
	Sdc_eventMsgInfo.len = 3;
	Sdc_SendHandler_SendEventMsg(Sdc_eventMsgInfo);
	return u_retVal;
}

/**
 * \functions Sdc_Diag_RequestEOLCalibration
 *
 * \brief Request EOL calibration to Soc via SPI.
 *
 ** \param[in] none, message function ID
 **
 **    the data package include the below infomation.
 **        byte#0-1: message id
 **        byte#2-3: message data length(start from byte16)
 **        byte#4-7: Protocol id(SPI: 0x00535049 ETH: 0x00455448 UART: Reserved)
 **        byte#8-15: time_stamp: If have the time synchronize with other chip
 **        byte#16-17: Sub-Function
 **        byte#18-...: user data
 ** \return E_OK, 
 * \comments  
 *
 */
FUNC(Std_ReturnType, RTE_CODE) Sdc_Diag_RequestEOLCalibration(void)
{
    uint8 u_retVal = RTE_E_OK;
	s_Sdc_MsgSendHandleDataInfo_Event_st Sdc_eventMsgInfo;

	const uint8 a_UserData[6] = {0x00,0x00,0x06,0x01,0x00,0x00};//SYSMGR_CAMERA_EOL_CALIBRATION = 0x0106
	
	Sdc_eventMsgInfo.msgId = e_Sdc_SpiMsgType_Evt_Mcu2J3_0202_RequestSocCmd;
	Sdc_eventMsgInfo.subId = e_Sdc_SpiMsgSubType_RequestCalibration;
	memcpy(&Sdc_eventMsgInfo.data[0], a_UserData, 6);
	Sdc_eventMsgInfo.len = 6;
	Sdc_SendHandler_SendEventMsg(Sdc_eventMsgInfo);
	return u_retVal;
}

/**
 * \functions Sdc_Diag_EthCableLengthDiagnostic_StartRoutine
 *
 * \brief Request to ETH port configuration to Soc via SPI.
 *
 ** \param[in] none, message function ID
 **
 **    the data package include the below infomation.
 **        byte#0-1: message id
 **        byte#2-3: message data length(start from byte16)
 **        byte#4-7: Protocol id(SPI: 0x00535049 ETH: 0x00455448 UART: Reserved)
 **        byte#8-15: time_stamp: If have the time synchronize with other chip
 **        byte#16-17: Sub-Function
 **        byte#18-35: reserved
 **        byte#36: 0x31
 ** 	   byte#37: 0x01
 **        byte#38: 0x10  
 **        byte#39: 0x09
 **        byte#40: DataIn0
 ** \return E_OK, 
 * \comments  
 *
 */
FUNC(Std_ReturnType, RTE_CODE) Sdc_Diag_EthCableLengthDiagnostic_StartRoutine(uint8 u_InputData)
{
    Std_ReturnType u_retVal = RTE_E_OK;
	s_Sdc_MsgSendHandleDataInfo_Event_st Sdc_eventMsgInfo;
		
	Sdc_eventMsgInfo.msgId = e_Sdc_SpiMsgType_Evt_Mcu2J3_0803_UdsRequest;
	Sdc_eventMsgInfo.subId = e_Sdc_SpiMsgSubType_ETH_Normal;
	Sdc_eventMsgInfo.data[18] = 0x31;
	Sdc_eventMsgInfo.data[19] = 0x01;
	Sdc_eventMsgInfo.data[20] = 0x10;
	Sdc_eventMsgInfo.data[21] = 0x09;
	Sdc_eventMsgInfo.data[22] = u_InputData;
	Sdc_eventMsgInfo.len = 24;
	Sdc_SendHandler_SendEventMsg(Sdc_eventMsgInfo);
	return u_retVal;
}

/**
 * \functions Sdc_Diag_RequestSDACalibration
 *
 * \brief Request SDA calibration to Soc via SPI.
 *
 ** \param[in] none, message function ID
 **
 **    the data package include the below infomation.
 **        byte#0-1: message id
 **        byte#2-3: message data length(start from byte16)
 **        byte#4-7: Protocol id(SPI: 0x00535049 ETH: 0x00455448 UART: Reserved)
 **        byte#8-15: time_stamp: If have the time synchronize with other chip
 **        byte#16-17: Sub-Function
 **        byte#18-...: user data
 ** \return E_OK, 
 * \comments  
 *
 */
FUNC(Std_ReturnType, RTE_CODE) Sdc_Diag_RequestSDACalibration(void)
{
    uint8 u_retVal = RTE_E_OK;
	s_Sdc_MsgSendHandleDataInfo_Event_st Sdc_eventMsgInfo;

	const uint8 a_UserData[6] = {0x00,0x00,0x04,0x01,0x00,0x00}; //SYSMGR_CAMERA_ONL_CALIBRATION = 0x0104 BIGENDIAN MODE
	
	Sdc_eventMsgInfo.msgId = e_Sdc_SpiMsgType_Evt_Mcu2J3_0202_RequestSocCmd;
	Sdc_eventMsgInfo.subId = e_Sdc_SpiMsgSubType_RequestCalibration;
	memcpy(&Sdc_eventMsgInfo.data[0], a_UserData, 6);
	Sdc_eventMsgInfo.len = 6;
	Sdc_SendHandler_SendEventMsg(Sdc_eventMsgInfo);
	return u_retVal;
}

/**
 * \functions Sdc_Diag_EthSetPortConfiguration_StartRoutine
 *
 * \brief Request to ETH port configuration to Soc via SPI.
 *
 ** \param[in] none, message function ID
 **
 **    the data package include the below infomation.
 **        byte#0-1: message id
 **        byte#2-3: message data length(start from byte16)
 **        byte#4-7: Protocol id(SPI: 0x00535049 ETH: 0x00455448 UART: Reserved)
 **        byte#8-15: time_stamp: If have the time synchronize with other chip
 **        byte#16-17: Sub-Function
 **        byte#18-35: reserved
 **        byte#36: 0x31
 ** 	   byte#37: 0x01
 **        byte#38: 0x10  
 **        byte#39: 0x01
 **        byte#40: DataIn0
 ** \return E_OK, 
 * \comments  
 *
 */
FUNC(Std_ReturnType, RTE_CODE) Sdc_Diag_EthSetPortConfiguration_StartRoutine(uint8 u_InputData)
{
    Std_ReturnType u_retVal = RTE_E_OK;
	s_Sdc_MsgSendHandleDataInfo_Event_st Sdc_eventMsgInfo;

	Sdc_eventMsgInfo.msgId = e_Sdc_SpiMsgType_Evt_Mcu2J3_0803_UdsRequest;
	Sdc_eventMsgInfo.subId = e_Sdc_SpiMsgSubType_ETH_Normal;
	Sdc_eventMsgInfo.data[18] = 0x31;
	Sdc_eventMsgInfo.data[19] = 0x01;
	Sdc_eventMsgInfo.data[20] = 0x10;
	Sdc_eventMsgInfo.data[21] = 0x01;
	Sdc_eventMsgInfo.data[22] = u_InputData;
	Sdc_eventMsgInfo.len = 24;
	Sdc_SendHandler_SendEventMsg(Sdc_eventMsgInfo);
	return u_retVal;
}

/**
 * \functions Sdc_Diag_EthResetPortConfiguration_StartRoutine
 *
 * \brief Request to ETH port configuration to Soc via SPI.
 *
 ** \param[in] none, message function ID
 **
 **    the data package include the below infomation.
 **        byte#0-1: message id
 **        byte#2-3: message data length(start from byte16)
 **        byte#4-7: Protocol id(SPI: 0x00535049 ETH: 0x00455448 UART: Reserved)
 **        byte#8-15: time_stamp: If have the time synchronize with other chip
 **        byte#16-17: Sub-Function
 **        byte#18-35: reserved
 **        byte#36: 0x31
 ** 	   byte#37: 0x01
 **        byte#38: 0x10  
 **        byte#39: 0x01
 **        byte#40: DataIn0
 ** \return E_OK, 
 * \comments  
 *
 */
FUNC(Std_ReturnType, RTE_CODE) Sdc_Diag_EthResetPortConfiguration_StartRoutine(void)
{
    Std_ReturnType u_retVal = RTE_E_OK;
	s_Sdc_MsgSendHandleDataInfo_Event_st Sdc_eventMsgInfo;

	Sdc_eventMsgInfo.msgId = e_Sdc_SpiMsgType_Evt_Mcu2J3_0803_UdsRequest;
	Sdc_eventMsgInfo.subId = e_Sdc_SpiMsgSubType_ETH_Normal;
	Sdc_eventMsgInfo.data[18] = 0x31;
	Sdc_eventMsgInfo.data[19] = 0x01;
	Sdc_eventMsgInfo.data[20] = 0x10;
	Sdc_eventMsgInfo.data[21] = 0x02;
	Sdc_eventMsgInfo.len = 24;
	Sdc_SendHandler_SendEventMsg(Sdc_eventMsgInfo);
	return u_retVal;
}

/**
 * \functions Sdc_Diag_EthReadPhyRegister_StartRoutine
 *
 * \brief Request to reset ETH MAC layer statistic to Soc via SPI.
 *
 ** \param[in] none, message function ID
 **
 **    the data package include the below infomation.
 **        byte#0-1: message id
 **        byte#2-3: message data length(start from byte16)
 **        byte#4-7: Protocol id(SPI: 0x00535049 ETH: 0x00455448 UART: Reserved)
 **        byte#8-15: time_stamp: If have the time synchronize with other chip
 **        byte#16-17: Sub-Function
 **        byte#18-35: reserved
 **        byte#36: 0x31
 ** 	   byte#37: 0x01
 **        byte#38: 0x10  
 **        byte#39: 0x05
 **        byte#40: DataIn0
 **        byte#41: DataIn1
 **        byte#42: DataIn2
 **        byte#43: DataIn3
 **        byte#44: DataIn4
 **        byte#45: DataIn5
 **        byte#46: DataIn6
 **        byte#47: DataIn7
 **        byte#48: DataIn8
 **        byte#49: DataIn9
 **        byte#50: DataIn10
 ** \return E_OK, 
 * \comments  
 *
 */
FUNC(Std_ReturnType, RTE_CODE) Sdc_Diag_EthReadPhyRegister_StartRoutine(uint8 *data, uint16 length)
{
    Std_ReturnType u_retVal = RTE_E_OK;
	s_Sdc_MsgSendHandleDataInfo_Event_st Sdc_eventMsgInfo;

	Sdc_eventMsgInfo.msgId = e_Sdc_SpiMsgType_Evt_Mcu2J3_0803_UdsRequest;
	Sdc_eventMsgInfo.subId = e_Sdc_SpiMsgSubType_ETH_Normal;
	Sdc_eventMsgInfo.data[18] = 0x31;
	Sdc_eventMsgInfo.data[19] = 0x01;
	Sdc_eventMsgInfo.data[20] = 0x10;
	Sdc_eventMsgInfo.data[21] = 0x03;
	Sdc_eventMsgInfo.data[22] = data[0];
	Sdc_eventMsgInfo.data[23] = data[1];	
	Sdc_eventMsgInfo.data[24] = data[2];
	Sdc_eventMsgInfo.data[25] = data[3];
	Sdc_eventMsgInfo.data[26] = data[4];
	Sdc_eventMsgInfo.data[27] = data[5];
	Sdc_eventMsgInfo.data[28] = data[6];
	Sdc_eventMsgInfo.data[29] = data[7];
	Sdc_eventMsgInfo.data[30] = data[8];
	Sdc_eventMsgInfo.data[31] = data[9];
	Sdc_eventMsgInfo.data[32] = data[10];
	
	Sdc_eventMsgInfo.len = 33;
	Sdc_SendHandler_SendEventMsg(Sdc_eventMsgInfo);
	return u_retVal;
}

/**
 * \functions Sdc_Diag_EthCableDiagnostic_StartRoutine
 *
 * \brief Request to reset ETH MAC layer statistic to Soc via SPI.
 *
 ** \param[in] none, message function ID
 **
 **    the data package include the below infomation.
 **        byte#0-1: message id
 **        byte#2-3: message data length(start from byte16)
 **        byte#4-7: Protocol id(SPI: 0x00535049 ETH: 0x00455448 UART: Reserved)
 **        byte#8-15: time_stamp: If have the time synchronize with other chip
 **        byte#16-17: Sub-Function
 **        byte#18-35: reserved
 **        byte#36: 0x31
 ** 	   byte#37: 0x01
 **        byte#38: 0x10  
 **        byte#39: 0x04
 **        byte#40: DataIn0
 ** \return E_OK, 
 * \comments  
 *
 */
FUNC(Std_ReturnType, RTE_CODE) Sdc_Diag_EthCableDiagnostic_StartRoutine(uint8 u_InputData)
{
    Std_ReturnType u_retVal = RTE_E_OK;
	s_Sdc_MsgSendHandleDataInfo_Event_st Sdc_eventMsgInfo;

	Sdc_eventMsgInfo.msgId = e_Sdc_SpiMsgType_Evt_Mcu2J3_0803_UdsRequest;
	Sdc_eventMsgInfo.subId = e_Sdc_SpiMsgSubType_ETH_Normal;
	Sdc_eventMsgInfo.data[18] = 0x31;
	Sdc_eventMsgInfo.data[19] = 0x01;
	Sdc_eventMsgInfo.data[20] = 0x10;
	Sdc_eventMsgInfo.data[21] = 0x04;
	Sdc_eventMsgInfo.data[22] = u_InputData;
	Sdc_eventMsgInfo.len = 24;
	Sdc_SendHandler_SendEventMsg(Sdc_eventMsgInfo);
	return u_retVal;
}

/**
 * \functions Sdc_Diag_EthEnableTestMode_StartRoutine
 *
 * \brief Request to reset ETH MAC layer statistic to Soc via SPI.
 *
 ** \param[in] none, message function ID
 **
 **    the data package include the below infomation.
 **        byte#0-1: message id
 **        byte#2-3: message data length(start from byte16)
 **        byte#4-7: Protocol id(SPI: 0x00535049 ETH: 0x00455448 UART: Reserved)
 **        byte#8-15: time_stamp: If have the time synchronize with other chip
 **        byte#16-17: Sub-Function
 **        byte#18-35: reserved
 **        byte#36: 0x31
 ** 	   byte#37: 0x01
 **        byte#38: 0x10  
 **        byte#39: 0x05
 **        byte#40: DataIn0
 **        byte#41: DataIn1
 **        byte#42: DataIn2
 ** \return E_OK, 
 * \comments  
 *
 */
FUNC(Std_ReturnType, RTE_CODE) Sdc_Diag_EthEnableTestMode_StartRoutine(uint8 *data, uint16 length)
{
    Std_ReturnType u_retVal = RTE_E_OK;
	s_Sdc_MsgSendHandleDataInfo_Event_st Sdc_eventMsgInfo;

	Sdc_eventMsgInfo.msgId = e_Sdc_SpiMsgType_Evt_Mcu2J3_0803_UdsRequest;
	Sdc_eventMsgInfo.subId = e_Sdc_SpiMsgSubType_ETH_Normal;
	Sdc_eventMsgInfo.data[18] = 0x31;
	Sdc_eventMsgInfo.data[19] = 0x01;
	Sdc_eventMsgInfo.data[20] = 0x10;
	Sdc_eventMsgInfo.data[21] = 0x05;
	Sdc_eventMsgInfo.data[22] = data[0];
	Sdc_eventMsgInfo.data[23] = data[1];
	Sdc_eventMsgInfo.data[24] = data[2];
	Sdc_eventMsgInfo.len = 25;
	Sdc_SendHandler_SendEventMsg(Sdc_eventMsgInfo);
	return u_retVal;
}

/**
 * \functions Sdc_Diag_EthEnableTestMode_StopRoutine
 *
 * \brief Request to reset ETH MAC layer statistic to Soc via SPI.
 *
 ** \param[in] none, message function ID
 **
 **    the data package include the below infomation.
 **        byte#0-1: message id
 **        byte#2-3: message data length(start from byte16)
 **        byte#4-7: Protocol id(SPI: 0x00535049 ETH: 0x00455448 UART: Reserved)
 **        byte#8-15: time_stamp: If have the time synchronize with other chip
 **        byte#16-17: Sub-Function
 **        byte#18-35: reserved
 **        byte#36: 0x31
 ** 	   byte#37: 0x01
 **        byte#38: 0x10  
 **        byte#39: 0x06
 **        byte#40: 
 ** \return E_OK, 
 * \comments  
 *
 */
FUNC(Std_ReturnType, RTE_CODE) Sdc_Diag_EthEnableTestMode_StopRoutine(void)
{
    Std_ReturnType u_retVal = RTE_E_OK;
	s_Sdc_MsgSendHandleDataInfo_Event_st Sdc_eventMsgInfo;

	Sdc_eventMsgInfo.msgId = e_Sdc_SpiMsgType_Evt_Mcu2J3_0803_UdsRequest;
	Sdc_eventMsgInfo.subId = e_Sdc_SpiMsgSubType_ETH_Normal;
	Sdc_eventMsgInfo.data[18] = 0x31;
	Sdc_eventMsgInfo.data[19] = 0x02;
	Sdc_eventMsgInfo.data[20] = 0x10;
	Sdc_eventMsgInfo.data[21] = 0x05;
	Sdc_eventMsgInfo.len = 24;
	Sdc_SendHandler_SendEventMsg(Sdc_eventMsgInfo);
	return u_retVal;
}

/**
 * \functions Sdc_Diag_EthPhyLoopBackTest_StartRoutine
 *
 * \brief Request to reset ETH MAC layer statistic to Soc via SPI.
 *
 ** \param[in] none, message function ID
 **
 **    the data package include the below infomation.
 **        byte#0-1: message id
 **        byte#2-3: message data length(start from byte16)
 **        byte#4-7: Protocol id(SPI: 0x00535049 ETH: 0x00455448 UART: Reserved)
 **        byte#8-15: time_stamp: If have the time synchronize with other chip
 **        byte#16-17: Sub-Function
 **        byte#18-35: reserved
 **        byte#36: 0x31
 ** 	   byte#37: 0x01
 **        byte#38: 0x10  
 **        byte#39: 0x06
 **        byte#40: DataIn0
 **        byte#41: DataIn1
 ** \return E_OK, 
 * \comments  
 *
 */
FUNC(Std_ReturnType, RTE_CODE) Sdc_Diag_EthPhyLoopBackTest_StartRoutine(uint8 *data, uint16 length)
{
    Std_ReturnType u_retVal = RTE_E_OK;
	s_Sdc_MsgSendHandleDataInfo_Event_st Sdc_eventMsgInfo;

	Sdc_eventMsgInfo.msgId = e_Sdc_SpiMsgType_Evt_Mcu2J3_0803_UdsRequest;
	Sdc_eventMsgInfo.subId = e_Sdc_SpiMsgSubType_ETH_Normal;
	Sdc_eventMsgInfo.data[18] = 0x31;
	Sdc_eventMsgInfo.data[19] = 0x01;
	Sdc_eventMsgInfo.data[20] = 0x10;
	Sdc_eventMsgInfo.data[21] = 0x06;
	Sdc_eventMsgInfo.data[22] = data[0];
	Sdc_eventMsgInfo.data[23] = data[1];
	Sdc_eventMsgInfo.len = 24;
	Sdc_SendHandler_SendEventMsg(Sdc_eventMsgInfo);
	return u_retVal;
}

/**
 * \functions Sdc_Diag_EthResetMACAddress_StartRoutine
 *
 * \brief Request to reset ETH MAC layer statistic to Soc via SPI.
 *
 ** \param[in] none, message function ID
 **
 **    the data package include the below infomation.
 **        byte#0-1: message id
 **        byte#2-3: message data length(start from byte16)
 **        byte#4-7: Protocol id(SPI: 0x00535049 ETH: 0x00455448 UART: Reserved)
 **        byte#8-15: time_stamp: If have the time synchronize with other chip
 **        byte#16-17: Sub-Function
 **        byte#18-35: reserved
 **        byte#36: 0x31
 ** 	   byte#37: 0x01
 **        byte#38: 0x10  
 **        byte#39: 0x07
 **        byte#40: DataIn0
 ** \return E_OK, 
 * \comments  
 *
 */
FUNC(Std_ReturnType, RTE_CODE) Sdc_Diag_EthResetMACAddress_StartRoutine(uint8 u_InputData)
{
    Std_ReturnType u_retVal = RTE_E_OK;
	s_Sdc_MsgSendHandleDataInfo_Event_st Sdc_eventMsgInfo;

	Sdc_eventMsgInfo.msgId = e_Sdc_SpiMsgType_Evt_Mcu2J3_0803_UdsRequest;
	Sdc_eventMsgInfo.subId = e_Sdc_SpiMsgSubType_ETH_Normal;
	Sdc_eventMsgInfo.data[18] = 0x31;
	Sdc_eventMsgInfo.data[19] = 0x01;
	Sdc_eventMsgInfo.data[20] = 0x10;
	Sdc_eventMsgInfo.data[21] = 0x07;
	Sdc_eventMsgInfo.data[22] = u_InputData;

	Sdc_eventMsgInfo.len = 24;
	Sdc_SendHandler_SendEventMsg(Sdc_eventMsgInfo);
	return u_retVal;
}

/**
 * \functions Sdc_Diag_EthResetMACLayerStatistic_StartRoutine
 *
 * \brief Request to set ETH MAC layer statistic to Soc via SPI.
 *
 ** \param[in] none, message function ID
 **
 **    the data package include the below infomation.
 **        byte#0-1: message id
 **        byte#2-3: message data length(start from byte16)
 **        byte#4-7: Protocol id(SPI: 0x00535049 ETH: 0x00455448 UART: Reserved)
 **        byte#8-15: time_stamp: If have the time synchronize with other chip
 **        byte#16-17: Sub-Function
 **        byte#18-35: reserved
 **        byte#36: 0x31
 ** 	   byte#37: 0x01
 **        byte#38: 0x10  
 **        byte#39: 0x08
 **        byte#40: DataIn0
 ** \return E_OK, 
 * \comments  
 *
 */
FUNC(Std_ReturnType, RTE_CODE) Sdc_Diag_EthResetMACLayerStatistic_StartRoutine(uint8 u_InputData)
{
    Std_ReturnType u_retVal = RTE_E_OK;
	s_Sdc_MsgSendHandleDataInfo_Event_st Sdc_eventMsgInfo;

	Sdc_eventMsgInfo.msgId = e_Sdc_SpiMsgType_Evt_Mcu2J3_0803_UdsRequest;
	Sdc_eventMsgInfo.subId = e_Sdc_SpiMsgSubType_ETH_Normal;
	Sdc_eventMsgInfo.data[18] = 0x31;
	Sdc_eventMsgInfo.data[19] = 0x01;
	Sdc_eventMsgInfo.data[20] = 0x10;
	Sdc_eventMsgInfo.data[21] = 0x08;
	Sdc_eventMsgInfo.data[22] = u_InputData;

	Sdc_eventMsgInfo.len = 24;
	Sdc_SendHandler_SendEventMsg(Sdc_eventMsgInfo);
	return u_retVal;
}

/**
 * \functions Sdc_Diag_EthPhyLoopBackTest_StopRoutine
 *
 * \brief Request to reset ETH MAC layer statistic to Soc via SPI.
 *
 ** \param[in] none, message function ID
 **
 **    the data package include the below infomation.
 **        byte#0-1: message id
 **        byte#2-3: message data length(start from byte16)
 **        byte#4-7: Protocol id(SPI: 0x00535049 ETH: 0x00455448 UART: Reserved)
 **        byte#8-15: time_stamp: If have the time synchronize with other chip
 **        byte#16-17: Sub-Function
 **        byte#18-35: reserved
 **        byte#36: 0x31
 ** 	   byte#37: 0x01
 **        byte#38: 0x10  
 **        byte#39: 0x06
 **        byte#40: 
 ** \return E_OK, 
 * \comments  
 *
 */
FUNC(Std_ReturnType, RTE_CODE) Sdc_Diag_EthPhyLoopBackTest_StopRoutine(void)
{
    Std_ReturnType u_retVal = RTE_E_OK;
	s_Sdc_MsgSendHandleDataInfo_Event_st Sdc_eventMsgInfo;

	Sdc_eventMsgInfo.msgId = e_Sdc_SpiMsgType_Evt_Mcu2J3_0803_UdsRequest;
	Sdc_eventMsgInfo.subId = e_Sdc_SpiMsgSubType_ETH_Normal;
	Sdc_eventMsgInfo.data[18] = 0x31;
	Sdc_eventMsgInfo.data[19] = 0x02;
	Sdc_eventMsgInfo.data[20] = 0x10;
	Sdc_eventMsgInfo.data[21] = 0x06;

	Sdc_eventMsgInfo.len = 24;
	Sdc_SendHandler_SendEventMsg(Sdc_eventMsgInfo);
	return u_retVal;
}

/*! LINKSTO JIRA: MFC5J3-1974*/
FUNC(uint8, RTE_CODE) Sdc_Diag_SocShutdownReuqest(void)
{
    uint8 u_retVal = E_OK;
    uint16 u_Requeststate  = 0x0002;
	s_Sdc_MsgSendHandleDataInfo_Event_st Sdc_eventMsgInfo;

	Sdc_eventMsgInfo.msgId = e_Sdc_SpiMsgType_Evt_Mcu2J3_0202_RequestSocCmd;
	Sdc_eventMsgInfo.subId = e_Sdc_SpiMsgSubType_RequestCalibration;
	Sdc_eventMsgInfo.data[2] = u_Requeststate&0x00FF;
	Sdc_eventMsgInfo.data[3] = ((u_Requeststate >> 8)&0x00FF);

	Sdc_eventMsgInfo.len = 6;
	Sdc_SendHandler_SendEventMsg(Sdc_eventMsgInfo);
	return u_retVal;

}


uint8 Sdc_Diag_RequestCalibrationValue(void)
{
	uint8 retVal = E_OK;
	uint16 data[3];
	s_Sdc_MsgSendHandleDataInfo_Event_st Sdc_eventMsgInfo;

	data[0] = 0x0000;/*unused*/
	data[1] = 0x0001;
	data[2] = 0x0000;/*unused*/

	Sdc_eventMsgInfo.msgId = e_Sdc_SpiMsgType_Evt_Mcu2J3_0202_RequestSocCmd;
	Sdc_eventMsgInfo.subId = e_Sdc_SpiMsgSubType_RequestCaliValue;
	memcpy(&Sdc_eventMsgInfo.data[0], (uint8 *)data, sizeof(data));

	Sdc_eventMsgInfo.len = 6;
	Sdc_SendHandler_SendEventMsg(Sdc_eventMsgInfo);
	return retVal;
}


/*send diagnostic request to J3 - cycle send to J3*/
uint8 Sdc_Diag_svcRequestDiagData(sint64 ts, const void *data, uint16 length) 
{
	uint8 retVal = E_OK;
	s_Sdc_MsgSendHandleDataInfo_Event_st Sdc_eventMsgInfo;

	Sdc_eventMsgInfo.msgId = e_Sdc_SpiMsgType_Evt_Mcu2J3_0202_RequestSocCmd;
	Sdc_eventMsgInfo.subId = e_Sdc_SpiMsgSubType_ReadSocDiag;
	memcpy(&Sdc_eventMsgInfo.data[0], (uint8 *)data, length);

	Sdc_eventMsgInfo.len = length;
	Sdc_SendHandler_SendEventMsg(Sdc_eventMsgInfo);
	return retVal;
}

/**
 * \functions Sdc_Diag_RequestHwVersion_Response
 *
 * \brief Response for J3 request mcu's hardware version by msg id 0x0902
 *
 ** \param[in] length, 
 *
 ** \param[out] Data, Pointer to Data buffer (1 bytes).
 **                  unsigned formatted
 *
 ** \return RTE_E_OK, 
 * \comments  
 *
 */
static FUNC(uint8, RTE_CODE) Sdc_Diag_RequestHwVersion_Response(void)
{
    uint8 u_retVal = E_OK;

	s_Sdc_MsgSendHandleDataInfo_Event_st Sdc_eventMsgInfo;

	Sdc_eventMsgInfo.msgId = e_Sdc_SpiMsgType_Evt_Mcu2J3_0802_UdsResponse;
	Sdc_eventMsgInfo.subId = e_Sdc_SpiMsgSubType_Uds_J3Request;

	Sdc_eventMsgInfo.data[0] = (uint8)e_Sdc_DiagUds_GroupVersion;
	Sdc_eventMsgInfo.data[1] = (uint8)(e_Sdc_DiagUds_GroupVersion >> 8);
	Sdc_eventMsgInfo.data[2] = (uint8)e_Sdc_Diag_Uds_VerEvent_ReqMcuHw;
	Sdc_eventMsgInfo.data[3] = (uint8)(e_Sdc_Diag_Uds_VerEvent_ReqMcuHw >> 8);
	Sdc_eventMsgInfo.data[4] = 0x08;	//len
	Sdc_eventMsgInfo.data[5] = 0x00;
	memcpy(&Sdc_eventMsgInfo.data[6], ECUHardwareVersion, 7);
	Sdc_eventMsgInfo.data[13] = '\0';
	Sdc_eventMsgInfo.len = 14;
	Sdc_SendHandler_SendEventMsg(Sdc_eventMsgInfo);
	return u_retVal;

}


/**
 * \functions Sdc_Diag_RequestSwVersion_Response
 *
 * \brief Response for J3 request mcu's software version by msg id 0x0902
 *
 ** \param[in] length, 
 *
 ** \param[out] Data, Pointer to Data buffer (1 bytes).
 **                  unsigned formatted
 *
 ** \return RTE_E_OK, 
 * \comments  
 *
 */
static FUNC(uint8, RTE_CODE) Sdc_Diag_RequestSwVersion_Response(void)
{
    uint8 u_retVal = E_OK;
	uint8 index = 0;
	s_Sdc_MsgSendHandleDataInfo_Event_st Sdc_eventMsgInfo;

	Sdc_eventMsgInfo.msgId = e_Sdc_SpiMsgType_Evt_Mcu2J3_0802_UdsResponse;
	Sdc_eventMsgInfo.subId = e_Sdc_SpiMsgSubType_Uds_J3Request;

	Sdc_eventMsgInfo.data[0] = (uint8)e_Sdc_DiagUds_GroupVersion;
	Sdc_eventMsgInfo.data[1] = (uint8)(e_Sdc_DiagUds_GroupVersion >> 8);
	Sdc_eventMsgInfo.data[2] = (uint8)e_Sdc_Diag_Uds_VerEvent_ReqMcuSw;
	Sdc_eventMsgInfo.data[3] = (uint8)(e_Sdc_Diag_Uds_VerEvent_ReqMcuSw >> 8);
	Sdc_eventMsgInfo.data[4] = 12;	//len
	Sdc_eventMsgInfo.data[5] = 0x00;
	memcpy(&Sdc_eventMsgInfo.data[6], ECUSoftwareVersion, 4); // copy "SWC."
	index = 10;
	if(VERINFO_MCU_SW_MAJOR_VERSION >= 10)
	{
		Sdc_eventMsgInfo.data[index++] = (VERINFO_MCU_SW_MAJOR_VERSION / 10) + 0x30;		
	}
	Sdc_eventMsgInfo.data[index++] = (VERINFO_MCU_SW_MAJOR_VERSION % 10) + 0x30;
	Sdc_eventMsgInfo.data[index++] = '.';

	if(VERINFO_MCU_SW_MINOR_VERSION >= 10)
	{
		Sdc_eventMsgInfo.data[index++] = (VERINFO_MCU_SW_MINOR_VERSION / 10) + 0x30;		
	}
	Sdc_eventMsgInfo.data[index++] = (VERINFO_MCU_SW_MINOR_VERSION % 10) + 0x30;
	Sdc_eventMsgInfo.data[index++] = '.';

	if(VERINFO_MCU_SW_PATCH_VERSION >= 10)
	{
		Sdc_eventMsgInfo.data[index++] = (VERINFO_MCU_SW_PATCH_VERSION / 10) + 0x30;		
	}
	Sdc_eventMsgInfo.data[index++] = (VERINFO_MCU_SW_PATCH_VERSION % 10) + 0x30;

	Sdc_eventMsgInfo.len = 18;
	Sdc_SendHandler_SendEventMsg(Sdc_eventMsgInfo);
	return u_retVal;

}

/**
 * \functions Sdc_Diag_SocBootSensor_Read
 *
 * \brief Copy bootSensor from Soc to buffer.
 *
 ** \param[in] length, 
 *
 ** \param[out] Data, Pointer to Data buffer (1 bytes).
 **                  unsigned formatted
 *
 ** \return RTE_E_OK, 
 * \comments  
 *
 */
FUNC(Std_ReturnType, RTE_CODE)Sdc_Diag_SocBootSensor_Read(uint8 *data, uint16 length)
{
    Std_ReturnType u_RetVal = RTE_E_OK;

    data[length-1] = SocToMcu.J3_BOOTSENSOR;

	return u_RetVal;
}



/**
 * \functions Sdc_Diag_SocSupplierSoftwarenumber_Read
 *
 * \brief Copy Soc Supplier Software number from Soc to buffer.
 *
 ** \param[in] length, 
 *
 ** \param[out] Data, Pointer to Data buffer (8 bytes).
 **                  unsigned formatted
 *
 ** \return RTE_E_OK, 
 * \comments  
 *
 */
FUNC(Std_ReturnType, RTE_CODE)Sdc_Diag_SocSupplierSoftwarenumber_Read(uint8 *data, uint16 length)
{
    Std_ReturnType u_RetVal = RTE_E_OK;
	uint8 len = length > 8 ? 8 : length;
    for(int i =0; i< len;i ++)
    {
        data[i] = SocToMcu.J3_software_version[i];
	}
	return u_RetVal;
}

uint8 Sdc_Diag_GetWorkmode(void)
{
	return FC_Workmode;
}

uint8 Sdc_Diag_GetPWMState(void)
{
	return PwmState;
}



/*Rx Unpack & Analyse Diag data*/
uint8 Sdc_Diag_SocDiag_vInfoUnpack(const uint8 *data, uint16 length)
{
	if (data == NULL_PTR)
	{
		return 0;
	}
	
	uint8 ServiceResonse_0 = data[0];
	uint8 ServiceResonse_1 = data[1];
	uint8 ServiceResonse_2 = data[2];

	/* check parameters */
	/* Positive response of read DTC through 22 service */
	if((0x62 == ServiceResonse_0) && (0xf2 == ServiceResonse_1) && (0x00 == ServiceResonse_2))
	{
		SocDiagResp_Cnt++;
		
		uint8 *pFaultData = (uint8 *)&data[4]; 
		
		/*copy out all J3 DTC info*/
		for(uint8 i = 0; i < MAX_SOCDTCGROUP_NUMBER; i++)
		{
			uint8 grouplength = pFaultData[0];/*get data length*/
			memcpy(&SocDiagInfo[i], pFaultData, grouplength + 1 );/*the "+1" is the size of "length" value*/
			pFaultData += (grouplength + 1);
		}
	}
    return 0;
} 

uint8 Sdc_Diag_SocDiag_CaliInfoUnpack(const uint8 *data, uint16 length)
{
//	CameraValue_Type CameraValue = ((TotalCameraValue_Type*)data)->cali_value[0];
//
//	memcpy(&(CaliResult.cali_value), &CameraValue, sizeof(CameraValue));

	memcpy(&CaliResult.cali_value, data + 6, 8);
    return 0;
}

FUNC(Std_ReturnType, RTE_CODE) Sdc_Diag_ClearSocDiagInfo(void)
{
	Std_ReturnType u_RetVal = RTE_E_OK;
	uint8 ui8_InternalTestMode = 0;
	
	(void)Rte_Read_RP_Dsm_SRI_InternalTestMode_DE_InternalTestMode(&ui8_InternalTestMode);

    for(uint8_t i= 0; i < MAX_SOCDTCGROUP_NUMBER; i++)
    {
		if(ui8_InternalTestMode == DSM_INTERNALTESTMODE_ON)
		{
		    memset(&SocDiagInfo_Injection[i], 0, sizeof(s_Sdc_SocDiagInfo_Type));
		}
		else
		{
		    memset(&SocDiagInfo[i], 0, sizeof(s_Sdc_SocDiagInfo_Type));
		}     
	}

	return u_RetVal;
}

FUNC(Std_ReturnType, RTE_CODE) Sdc_Diag_SocDiagInfo_Read(uint8 group_id, void* socDiagInfo)
{
	Std_ReturnType u_RetVal = RTE_E_OK;
	uint8 ui8_InternalTestMode = 0;
	
	if(group_id < MAX_SOCDTCGROUP_NUMBER)
	{
		Rte_Read_RP_Dsm_SRI_InternalTestMode_DE_InternalTestMode(&ui8_InternalTestMode);
		
		if(ui8_InternalTestMode == DSM_INTERNALTESTMODE_ON)
		{
#if ((defined SDC_DIAG_INJECTION_ENABLED) && (SDC_DIAG_INJECTION_ENABLED == STD_ON))
			memcpy(socDiagInfo, &SocDiagInfo_Injection[group_id], sizeof(s_Sdc_SocDiagInfo_Type));
			Std_ReturnType u_RetVal = RTE_E_OK;
#endif
		}
		else
		{
			memcpy(socDiagInfo, &SocDiagInfo[group_id], sizeof(s_Sdc_SocDiagInfo_Type));
			Std_ReturnType u_RetVal = RTE_E_OK;
		}

	}
	else
	{
		u_RetVal = RTE_E_INVALID;
	}
	return u_RetVal;
}

FUNC(Std_ReturnType, RTE_CODE) Sdc_Diag_CameraValue_Read(void *data, uint16 length)
{
	Std_ReturnType u_RetVal = RTE_E_OK;	
	memcpy(data, &CaliResult.cali_value, sizeof(CameraValue_Type));
	 return u_RetVal;
}

uint8 ID0902_Buf[6][20];

uint8 ID0903_Buf[200];
uint8 ID0902Cnt = 0;
uint8 ID0902Len = 0;
uint16 debug_eventId = 0;
uint16 debug_subId = 0;
uint16 debug_groupId = 0;
/**
 * \functions Sdc_Diag_ReceiveHandler_ID0902
 *
 * \brief response to J3 Uds Request via SPI.
 *
 ** \param[in] none, message function ID
 **
 **    the data package include the below infomation.
 **        byte#0-1: sub id
 **        byte#2-3: unused
 **        byte#4-5: group id
 **		   byte#6-7: event id
 **        byte#8-9: message data length(start from byte16)
 **        byte#10: Status, some id have not this byte,eg.hardware version(group-0x0002,event-0x0001)
 ** \return E_OK, 
 * \comments  
 *
 */
uint8 Sdc_Diag_ReceiveHandler_ID0902(const uint8* Data, uint16 Length)
{
	uint16 eventId = 0;
	uint16 subId = 0;
	uint16 groupId = 0;

	ID0902Len = Length-4;
	memset(ID0902_Buf[ID0902Cnt%6], 0, 20);
	memcpy(&ID0902_Buf[ID0902Cnt%6], Data+4, ID0902Len);
	ID0902_Buf[ID0902Cnt%5][19] = ID0902Len;
	ID0902Cnt++;
	memset(ID0902_Buf[ID0902Cnt%6], 0, 20);
	if(Length >=10)
	{	
		subId = Data[1] << 8 | Data[0];
		groupId = Data[5] << 8 | Data[4];
		eventId = Data[7] << 8 | Data[6];
		debug_eventId = eventId;
		debug_subId = subId;
		debug_groupId = groupId;
		if(groupId == e_Sdc_DiagUds_GroupEth)	//group 1
		{
			switch (eventId)
			{
				case e_Sdc_Diag_Uds_EthEvent_CRC:	//DTC:D789 87
					if(Data[10] == 0x01)
					{
						Sdc_Dtc_Eth.DTC_D28987 = 0x01;
					}
					else
					{
						Sdc_Dtc_Eth.DTC_D28987 = 0x00;
					}
					break;
				case e_Sdc_Diag_Uds_EthEvent_SQI:	//DTC:D78A 87
					if(Data[10] == 0x01)
					{
						Sdc_Dtc_Eth.DTC_D28A87 = 0x01;
					}
					else
					{
						Sdc_Dtc_Eth.DTC_D28A87 = 0x00;
					}
					break;
				case e_Sdc_Diag_Uds_EthEvent_Cable:	//DTC:D78C 87
					if(Data[10] == 0x01)
					{
						Sdc_Dtc_Eth.DTC_D28C87 = 0x01;
					}
					else
					{
						Sdc_Dtc_Eth.DTC_D28C87 = 0x00;
					}
					break;
				case e_Sdc_Diag_Uds_EthEvent_ICMP:	//DTC:D78D 87
					if(Data[10] == 0x01)
					{
						Sdc_Dtc_Eth.DTC_D28D87 = 0x01;
					}
					else
					{
						Sdc_Dtc_Eth.DTC_D28D87 = 0x00;
					}
					break;
				
				default:
					break;
			}
		}
		else if(groupId == e_Sdc_DiagUds_GroupVersion)	//group 2
		{
			if(eventId == e_Sdc_Diag_Uds_VerEvent_ReqMcuHw)	//J3 read MCU Hardware version
			{
				Sdc_Diag_RequestHwVersion_Response();
			}
			else if(eventId == e_Sdc_Diag_Uds_VerEvent_ReqMcuSw)	//J3 read MCU Software version
			{
				Sdc_Diag_RequestSwVersion_Response();
			}
		}
		else if(groupId == e_Sdc_DiagUds_GroupControl)
		{
			if(eventId == e_Sdc_Diag_Uds_VerEvent_J3ReqRstJ3_Warm)	//J3 request MCU warm reset J3 event id
			{
				FSExec_SocRequestReset(FS_EXEC_SOC_WARM_RESET);
			}
			else if(eventId == e_Sdc_Diag_Uds_VerEvent_J3ReqRstJ3_Cold)	//J3 request MCU cold reset J3 event id
			{
				FSExec_SocRequestReset(FS_EXEC_SOC_COLD_RESET);
			}
		}
	}
}
uint8 ID0903Cnt = 0;
uint8 ID0903Len = 0;
uint8 Sdc_Diag_ReceiveHandler_ID0903(const uint8* Data, uint16 Length)
{
	memcpy(ID0903_Buf, Data, Length);
	ID0903Cnt++;
	ID0903Len = Length;
    if((NULL_PTR != Data) && (0x00 != Length))
    {
    	memcpy(&Sdc_SocRid_Did_Uls_A150U8, Data, Length);
    }

	if(Data[20] == 0x71	&& Data[21] == 0x01	&& Data[22] == 0x10)
	{
		switch (Data[23])
		{
			case 0x01:
				Sdc_Rid_Eth.RID_0301 = Data[24];
				break;
			case 0x02:
				Sdc_Rid_Eth.RID_0302 = Data[24];
				break;
			case 0x03:
				memcpy(Sdc_Rid_Eth.RID_0303,  &Data[24], 3);
				break;
			case 0x04:
				Sdc_Rid_Eth.RID_0305 = Data[24];
				break;
			case 0x05:
				Sdc_Rid_Eth.RID_0306 = Data[24];
				break;
			case 0x06:
				Sdc_Rid_Eth.RID_0307 = Data[24];
				break;
			case 0x07:
				Sdc_Rid_Eth.RID_0308 = Data[24];
				break;
			case 0x08:
				Sdc_Rid_Eth.RID_0309 = Data[24];
				break;
			case 0x09:
				Sdc_Rid_Eth.RID_030A = Data[24];
				break;
			default:
				break;
		}
	}
	else if(Data[20] == 0x62 && Data[21] == 0x00 && Data[22] == 0x12)	//Soc response Mcu It's soft version
	{
		memcpy(&SocToMcu.J3_software_version[0], &Data[23], 8);
	}
	
    return 0;
}

uint8 Sdc_Diag_UdsRequest(uint8_t ServerType,uint16 Did,const void *Inparameter,uint8 InparameterLength,const void *OutParam1,uint8 OutparameterLength)
{
	uint8 ReturnStu = E_NOT_OK;
	uint8 TXBufferLen ;
	s_Sdc_MsgSendHandleDataInfo_Event_st Sdc_eventMsgInfo;

	if(ServerType == UDSTYPE_DID)
	{
		if(DID_RID_Pengding_Stu_U8_L == STD_IDLE)
		{
			MCU_SOC_TXD_Uls_U8_D[8] = 0x22U;
			MCU_SOC_TXD_Uls_U8_D[9] = (uint8)(Did & 0xFF);			//did low
			MCU_SOC_TXD_Uls_U8_D[10] = (uint8)((Did >> 8) & 0xFF);	//did hight
			TXBufferLen = 11u + InparameterLength;
			memcpy(MCU_SOC_TXD_Uls_U8_D + 11, Inparameter, InparameterLength);
			
			Sdc_eventMsgInfo.msgId = e_Sdc_SpiMsgType_Evt_Mcu2J3_0803_UdsRequest;
			Sdc_eventMsgInfo.subId = e_Sdc_SpiMsgSubType_NULL;
			memcpy(&Sdc_eventMsgInfo.data[0], MCU_SOC_TXD_Uls_U8_D, TXBufferLen);
			Sdc_eventMsgInfo.len = TXBufferLen;
			Sdc_SendHandler_SendEventMsg(Sdc_eventMsgInfo);

			DID_RID_Pengding_Stu_U8_L = STD_ACTIVE;
			Sdc_SocRid_Did_Uls_A150U8[20] = 0X7F;
//			memset(MCU_SOC_TXD_Uls_U8_D, 0x00u, TXBufferLen);
		}

		if(DID_RID_ResponseCnt >= 100u)
		{
			memcpy(OutParam1, &Sdc_SocRid_Did_Uls_A150U8[0] + 23, OutparameterLength);
			DID_RID_Pengding_Stu_U8_L = STD_IDLE;
			DID_RID_ResponseCnt = 0;

			if(0x7F == Sdc_SocRid_Did_Uls_A150U8[20])
			{
				ReturnStu = E_NOT_OK;
			}
			else
			{
				ReturnStu = E_OK;
			}
		}
		else
		{
			ReturnStu = DCM_E_PENDING;
			DID_RID_ResponseCnt++;
		}
	}
	else if(ServerType == UDSTYPE_RID_START)
	{
		if(DID_RID_Pengding_Stu_U8_L == STD_IDLE)
		{
			MCU_SOC_TXD_Uls_U8_D[8] = 0x31U;
			MCU_SOC_TXD_Uls_U8_D[9] = 0x1U;
			MCU_SOC_TXD_Uls_U8_D[10] = (uint8)(Did && 0xFF);		//did low
			MCU_SOC_TXD_Uls_U8_D[11] = (uint8)((Did >> 8) && 0xFF);	//did hight
			TXBufferLen = 12u + InparameterLength;

			MCU_SOC_TXD_Uls_U8_D[12] = Dig_inputdata_1[0];
			MCU_SOC_TXD_Uls_U8_D[13] = Dig_inputdata_1[1];
			MCU_SOC_TXD_Uls_U8_D[14] = Dig_inputdata_1[2];
			MCU_SOC_TXD_Uls_U8_D[15] = Dig_inputdata_1[3];
			MCU_SOC_TXD_Uls_U8_D[16] = Dig_inputdata_1[4];
			MCU_SOC_TXD_Uls_U8_D[17] = Dig_inputdata_1[5];
			MCU_SOC_TXD_Uls_U8_D[18] = Dig_inputdata_1[6];
			MCU_SOC_TXD_Uls_U8_D[19] = Dig_inputdata_1[7];
			MCU_SOC_TXD_Uls_U8_D[20] = Dig_inputdata_1[8];
			MCU_SOC_TXD_Uls_U8_D[21] = Dig_inputdata_1[9];
			MCU_SOC_TXD_Uls_U8_D[22] = Dig_inputdata_1[10];
			// memcpy(MCU_SOC_TXD_Uls_U8_D + 12, Inparameter, InparameterLength);

			Sdc_eventMsgInfo.msgId = e_Sdc_SpiMsgType_Evt_Mcu2J3_0803_UdsRequest;
			Sdc_eventMsgInfo.subId = e_Sdc_SpiMsgSubType_NULL;
			memcpy(&Sdc_eventMsgInfo.data[0], MCU_SOC_TXD_Uls_U8_D, TXBufferLen);
			Sdc_eventMsgInfo.len = TXBufferLen;
			Sdc_SendHandler_SendEventMsg(Sdc_eventMsgInfo);

			DID_RID_Pengding_Stu_U8_L = STD_ACTIVE;
//			memset(MCU_SOC_TXD_Uls_U8_D, 0x00u, TXBufferLen);

			DID_RID_Pengding_Stu_U8_L = STD_IDLE;
			DID_RID_ResponseCnt = 0;
			ReturnStu = E_OK;
		}
	}
	else if(ServerType == UDSTYPE_RID_STOP)
	{
		if(DID_RID_Pengding_Stu_U8_L == STD_IDLE)
		{
			MCU_SOC_TXD_Uls_U8_D[8] = 0x31U;
			MCU_SOC_TXD_Uls_U8_D[9] = 0x2U;
			MCU_SOC_TXD_Uls_U8_D[10] = (uint8)(Did && 0xFF);		//did low
			MCU_SOC_TXD_Uls_U8_D[11] = (uint8)((Did >> 8) && 0xFF);	//did hight
			TXBufferLen = 12u + InparameterLength;
			memcpy(MCU_SOC_TXD_Uls_U8_D + 12, Inparameter, InparameterLength);

			Sdc_eventMsgInfo.msgId = e_Sdc_SpiMsgType_Evt_Mcu2J3_0803_UdsRequest;
			Sdc_eventMsgInfo.subId = e_Sdc_SpiMsgSubType_NULL;
			memcpy(&Sdc_eventMsgInfo.data[0], MCU_SOC_TXD_Uls_U8_D, TXBufferLen);
			Sdc_eventMsgInfo.len = TXBufferLen;
			Sdc_SendHandler_SendEventMsg(Sdc_eventMsgInfo);

			DID_RID_Pengding_Stu_U8_L = STD_ACTIVE;
//			memset(MCU_SOC_TXD_Uls_U8_D, 0x00u, TXBufferLen);

			DID_RID_Pengding_Stu_U8_L = STD_IDLE;
			DID_RID_ResponseCnt = 0;
			ReturnStu = E_OK;
		}
	}
	return ReturnStu;
}

/*receive Calibration result from J3*/
void Sdc_Diag_SetCalibrationResult(const uint8 *data, uint16 length)
{
	/*data[0] == e_Sdc_SpiMsgSubType_SetCalibration_Result || SUBFUNC_SET_OL_CALIB_RESULT*/
	uint64 timestamp = 0;
	
	if (data == NULL_PTR)
	{
		return;
	}
	
	/*Get timestamp*/
	Time_GetTimeStampMs(&timestamp);
	CaliResult.timestamp = timestamp;
	
	if(data[0] == e_Sdc_SpiMsgSubType_SetCalibration_Result)
	{
//		CaliResult.Calib_flag = 0x02; /*0x02 -static calibration is done*/
		CaliResult.SubFuncId = e_Sdc_SpiMsgSubType_SetCalibration_Result;
	}
	else if(data[0] == e_Sdc_SpiMsgSubType_SetEOL_Calib_Result)
	{
//		CaliResult.Calib_flag = 0x05; /*0x05 - Intial_online_Calibration is done*/
		CaliResult.SubFuncId = e_Sdc_SpiMsgSubType_SetEOL_Calib_Result;
	}
	else
	{
		/*invalid result*/
//		CaliResult.Calib_flag = 0x00; /*0x00 - Calibration is not done*/
	}
	
	CameraCaliResult_Type CameraCaliResult = ((TotalCaliResult_Type*)data)->CameraCaliResult[0];
	memcpy(&(CaliResult.CameraCaliResult), &CameraCaliResult, sizeof(CameraCaliResult));
}

s_Sdc_CaliResult_Type* Sdc_Diag_GetCalibrationResult()
{
	return &CaliResult;
}
void Sdc_Diag_SetCaliResult_Flag(uint8 flag)
{
	CaliResult.Calib_flag = flag;
}
FUNC(Std_ReturnType, RTE_CODE)Sdc_Diag_CalibrationFlag_Read(uint8 *data, uint16 length)
{
   Std_ReturnType u_RetVal = RTE_E_OK;

   data[length -1] = CaliResult.Calib_flag;

   return u_RetVal;
}

FUNC(Std_ReturnType, RTE_CODE)Sdc_Diag_CameraCaliresultDetails_Read(uint8 *data, uint16 length)
{
   Std_ReturnType u_RetVal = RTE_E_OK;
   
   data[length -1] = (uint8)CaliResult.CameraCaliResult.detail;

   return u_RetVal;
}

FUNC(Std_ReturnType, RTE_CODE) Sdc_Diag_SocCpuInfo_Read(void* socSystemInfo, uint16 length)
{
	Std_ReturnType u_RetVal = RTE_E_OK;

	((s_Sdc_SocSystemInfo_t*)socSystemInfo)->cpu_load = SocSysInfo_CpuInfo.cpu_load;
	((s_Sdc_SocSystemInfo_t*)socSystemInfo)->cpu_temp = SocSysInfo_CpuInfo.cpu_temp;
	((s_Sdc_SocSystemInfo_t*)socSystemInfo)->cpu_mem = SocSysInfo_CpuInfo.cpu_mem;
	((s_Sdc_SocSystemInfo_t*)socSystemInfo)->bpu0_load = SocSysInfo_CpuInfo.bpu0_load;
	((s_Sdc_SocSystemInfo_t*)socSystemInfo)->bpu1_load = SocSysInfo_CpuInfo.bpu1_load;
	((s_Sdc_SocSystemInfo_t*)socSystemInfo)->sensor_temp = SocSysInfo_CpuInfo.sensor_temp;

	return RTE_E_OK;
}
// s_Sdc_SocSystemInfo_t* Sdc_Diag_SocCpuInfo_Read(void)
// {

// 	return &SocSysInfo_CpuInfo;
// }

FUNC(Std_ReturnType, RTE_CODE) Sdc_Diag_EOLCalResult_Read(void)
{
	return SocEOLCalResults;
}

FUNC(Std_ReturnType, RTE_CODE) Sdc_Diag_SocSysState_Read(uint8 *data, uint16 length)
{
   Std_ReturnType u_RetVal = RTE_E_OK;
   
   data[length -1] = ((uint8)SocDiag_SysMgr&& 0xFF);

   return u_RetVal; 
}
void Sdc_Diag_SocSysState_Set(uint16 value)
{
	SocDiag_SysMgr = value;
}


FUNC(Std_ReturnType, RTE_CODE) Sdc_Diag_EthSetPortConfigurationInfo_Read(uint8 *data, uint16 length)
{
	Std_ReturnType u_RetVal = RTE_E_OK;
	
	data[length -1] = (uint8)Sdc_Rid_Eth.RID_0301;
	
	return u_RetVal; 
}

FUNC(Std_ReturnType, RTE_CODE) Sdc_Diag_EthReadPhyRegisterInfo_Read(uint8 *data, uint16 length)
{
    Std_ReturnType u_RetVal = RTE_E_OK;
	
    for(int i =0; i< length;i ++)
    {
        data[i] = (uint8)Sdc_Rid_Eth.RID_0303[i];
	}

	return u_RetVal;
}

FUNC(Std_ReturnType, RTE_CODE) Sdc_Diag_EthResetMACAddressInfo_Read(uint8 *data, uint16 length)
{
	Std_ReturnType u_RetVal = RTE_E_OK;
	
	data[length -1] = (uint8)Sdc_Rid_Eth.RID_0308;
	
	return u_RetVal; 
}

FUNC(Std_ReturnType, RTE_CODE) Sdc_Diag_EthResetPortConfigurationInfo_Read(uint8 *data, uint16 length)
{
	Std_ReturnType u_RetVal = RTE_E_OK;
	
	data[length -1] = (uint8)Sdc_Rid_Eth.RID_0302;
	
	return u_RetVal; 
}

FUNC(Std_ReturnType, RTE_CODE) Sdc_Diag_EthCableDiagnosticInfo_Read(uint8 *data, uint16 length)
{
	Std_ReturnType u_RetVal = RTE_E_OK;
	
	data[length -1] = (uint8)Sdc_Rid_Eth.RID_0305;
	
	return u_RetVal; 
}

FUNC(Std_ReturnType, RTE_CODE) Sdc_Diag_EthResetMACLayerStatisticInfo_Read(uint8 *data, uint16 length)
{
	Std_ReturnType u_RetVal = RTE_E_OK;
	
	data[length -1] = (uint8)Sdc_Rid_Eth.RID_0309;
	
	return u_RetVal; 
}

FUNC(Std_ReturnType, RTE_CODE) Sdc_Diag_EthEnableTestModeInfo_Read(uint8 *data, uint16 length)
{
	Std_ReturnType u_RetVal = RTE_E_OK;
	
	data[length -1] = (uint8)Sdc_Rid_Eth.RID_0306;
	
	return u_RetVal; 
}

FUNC(Std_ReturnType, RTE_CODE) Sdc_Diag_EthPhyLoopBackTestInfo_Read(uint8 *data, uint16 length)
{
	Std_ReturnType u_RetVal = RTE_E_OK;
	
	data[length -1] = (uint8)Sdc_Rid_Eth.RID_0307;
	
	return u_RetVal; 
}

FUNC(Std_ReturnType, RTE_CODE) Sdc_Diag_EthCableLengthDiagnosticInfo_Read(uint8 *data, uint16 length)
{
	Std_ReturnType u_RetVal = RTE_E_OK;
	
	data[length -1] = (uint8)Sdc_Rid_Eth.RID_030A;
	
	return u_RetVal; 
}

FUNC(Std_ReturnType, RTE_CODE) Sdc_Diag_EthCrcError_Read(uint8 *data, uint16 length)
{
	Std_ReturnType u_RetVal = RTE_E_OK;
	
	data[length -1] = (uint8)Sdc_Dtc_Eth.DTC_D28987;
	
	return u_RetVal; 
}

FUNC(Std_ReturnType, RTE_CODE) Sdc_Diag_EthSQI_Read(uint8 *data, uint16 length)
{
	Std_ReturnType u_RetVal = RTE_E_OK;
	
	data[length -1] = (uint8)Sdc_Dtc_Eth.DTC_D28A87;
	
	return u_RetVal; 
}

FUNC(Std_ReturnType, RTE_CODE) Sdc_Diag_EthCableFault_Read(uint8 *data, uint16 length)
{
	Std_ReturnType u_RetVal = RTE_E_OK;
	
	data[length -1] = (uint8)Sdc_Dtc_Eth.DTC_D28C87;
	
	return u_RetVal; 
}

FUNC(Std_ReturnType, RTE_CODE) Sdc_Diag_EthIcmpError_Read(uint8 *data, uint16 length)
{
	Std_ReturnType u_RetVal = RTE_E_OK;
	
	data[length -1] = (uint8)Sdc_Dtc_Eth.DTC_D28D87;
	
	return u_RetVal; 
}

/*==================[internal function definitions]=========================*/
/*after received Cali result, send ack to J3*/
static void Sdc_Diag_SendCalibrationResult_Ack(uint16 Sub)
{
	uint16 data[3];
	s_Sdc_MsgSendHandleDataInfo_Event_st Sdc_eventMsgInfo;

	data[0] = 0x0000;/*unused*/
	data[1] = 0x0001;
	data[2] = 0x0000;/*unused*/

	Sdc_eventMsgInfo.msgId = e_Sdc_SpiMsgType_Evt_Mcu2J3_0203_ReplyMcuCmdResult;
	Sdc_eventMsgInfo.subId = Sub;
	memcpy(&Sdc_eventMsgInfo.data[0], (uint8 *)data, sizeof(data));

	Sdc_eventMsgInfo.len = 6;
	Sdc_SendHandler_SendEventMsg(Sdc_eventMsgInfo);
								
}

static void Sdc_Diag_MCURequestFaultList(void)/*22 F2 00 - cycle send to J3*/
{
	uint8 u_retVal;
	uint8 a_DiagReqMsg[3];
	sint64 s64_timestamp = 0;

	a_DiagReqMsg[0] = 0x22;
	a_DiagReqMsg[1] = 0xF2;
	a_DiagReqMsg[2] = 0x00;

	(void)Time_GetTimeStampMs(&s64_timestamp);
	
	u_retVal = Sdc_Diag_svcRequestDiagData(s64_timestamp, &a_DiagReqMsg, sizeof(a_DiagReqMsg));
	
	if(u_retVal != E_OK)
	{
		/*jobs when sending message failed*/
	}
}

static void Sdc_Diag_DriverModeSend(uint8 value)
{
	s_Sdc_MsgSendHandleDataInfo_Event_st Sdc_eventMsgInfo;
	uint16 UserData[3];
	UserData[0] = 0x00; /*unused*/
	UserData[1] = value;
	UserData[2] = 0x00; /*unused*/

	Sdc_eventMsgInfo.msgId = e_Sdc_SpiMsgType_Evt_Mcu2J3_0602_WorkingMode;
	Sdc_eventMsgInfo.subId = e_Sdc_SpiMsgSubType_WorkMode;
	memcpy(&Sdc_eventMsgInfo.data[0], (uint8 *)&UserData, 6);
	Sdc_eventMsgInfo.len = 6;
	Sdc_SendHandler_SendEventMsg(Sdc_eventMsgInfo);
}

#if 0
static void Sed_MCURequest_DTCList(void)/*19 02 Status_Mask*/
{
	uint8 retVal;
	uint8 DiagReqMsg[3];

	DiagReqMsg[0] = 0x19U;
	DiagReqMsg[1] = 0x02U;
	DiagReqMsg[2] = 0xFFU;

	sint64 timestamp = 0;
	Time_GetTimeStampMs(&timestamp);
	Sdc_Diag_svcRequestDiagData(timestamp, &DiagReqMsg, sizeof(DiagReqMsg));
	if(retVal != E_OK)
	{
		/*jobs when sending message failed*/
	}
}
#endif


#define SDC_STOP_SEC_CODE
#include "Sdc_MemMap.h"


