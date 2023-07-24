/**
 * \file   Fcu_Vdy.c
 *
 * \brief  Get the signal from CAN and Soc ,then send it to Vdy Algo.
 *
 * \version refer the Fcu_Vdy.h.
 * 
 * \copyright  2022 - 2023 Conti Smart Core
 *
 */
/* ==================[Includes]============================================ */
#include "Fcu_Common.h"
#include "Fcu_Vdy.h"
/*==================[internal data]=========================================*/
/*==================[.data]==============================*/

/*==================[.bss]==============================*/
static VehSig_t Fcu_Vdy_VehSigData;
static VehPar_t Fcu_Vdy_VehPar;


/*==================[external data]=========================================*/

/*==================[internal function declarations]========================*/
static void Fcu_RxProcess_VehSig(VehSig_t* const Fcu_Vdy_VehSigData, const s_Fcu_Rte_Input_SignalData_t* const ptr_Fcu_Rte_input_Signal);
static void Fcu_RxProcess_VehPar(VehPar_t* const Fcu_Vdy_VehPar);

/*==================[external function definitions]=========================*/
/**
 * \functions Fcu_Vdy_InitFunction
 *
 * \brief
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
FUNC(void, RTE_CODE) Fcu_Vdy_InitFunction (void)
{
	/*TODO : Clean the local variable*/   	

	uint8 uint8_index = 0x0u;
	
	/* Write signal sSigHeader_eSigStatus to AL_SIG_STATE_INIT */
	Fcu_Vdy_VehPar.sSigHeader.eSigStatus = 0u;//AL_SIG_STATE_INIT

	/* Write signal VehParMain_State to VDY_IO_STATE_INIT */
	for (uint8_index = 0x0u; uint8_index < 32u; uint8_index++)
	{
		Fcu_Vdy_VehPar.VehParMain.State[uint8_index] = 15u;//VDY_IO_STATE_INIT
	}

	/* Write signal VehParMain_State to VDY_IO_STATE_INIT */
	for (uint8_index = 0x0u; uint8_index < 32u; uint8_index++)
	{
		Fcu_Vdy_VehPar.VehParAdd.State[uint8_index] = 15u;//VDY_IO_STATE_INIT
	}

	/* Write signal SensorMounting_State to VDY_IO_STATE_INIT */
	for (uint8_index = 0x0u; uint8_index < 8u; uint8_index++)
	{
		Fcu_Vdy_VehPar.VehParAdd.State[uint8_index] = 15u;//VDY_IO_STATE_INIT
	}

	/* Write signal Sensor_State to VDY_IO_STATE_INIT */
	for (uint8_index = 0x0u; uint8_index < 8u; uint8_index++)
	{
		Fcu_Vdy_VehPar.Sensor.State[uint8_index] = 15u;//VDY_IO_STATE_INIT
	}
}

/**
 * \functions Fcu_Vdy_MainFunction
 *
 * \brief
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
FUNC(void, RTE_CODE) Fcu_Vdy_MainFunction (const s_Fcu_Rte_Input_SignalData_t* const ptr_Fcu_Rte_input_Signal)
{ 
	Fcu_RxProcess_VehSig(&Fcu_Vdy_VehSigData, ptr_Fcu_Rte_input_Signal);
	Fcu_RxProcess_VehPar(&Fcu_Vdy_VehPar);
}



/**
 * \functions Fcu_RxProcess_VehSig
 *
 * \brief
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
static void Fcu_RxProcess_VehSig(VehSig_t* const Fcu_Vdy_VehSigData, const s_Fcu_Rte_Input_SignalData_t* const ptr_Fcu_Rte_input_Signal)
{
	sint64 s64_timestamp = 0;
	//uint8 raw_gear = 0 ;
	//uint8 raw_gear_valid = 0 ;
	/*TODO : get time stamp*/
	(void)Time_GetTimeStampMs(&s64_timestamp);

	/*TODO : shall be check the vale range,or timeout or checksum error and etc. TBD*/
	// Fcu_Vdy_VehSigData->uiVersionNumber = 19;/*Shall check version number by DF*/
	Fcu_Vdy_VehSigData->uiVersionNumber =(AlgoInterfaceVersionNumber_t)BSW_VEH_SIG_INTFVER_LCF;  //defined from Bench Test
	Fcu_Vdy_VehSigData->sSigHeader.eSigStatus = 0x01;/*Valid*/
	Fcu_Vdy_VehSigData->sSigHeader.uiTimeStamp = (uint32)s64_timestamp;
	Fcu_Vdy_VehSigData->sSigHeader.uiCycleCounter++;
	Fcu_Vdy_VehSigData->sSigHeader.uiMeasurementCounter++;

	/*
		VehSigMain.State[32]
	*/
	/*
	0x0: Initializing
	0x1: Valid
	0x2: Invalid
	0x3: Reserved
	*/
	if(ptr_Fcu_Rte_input_Signal->ChassisDomain_Data.u8_Rte_ESP_YawRateValid == 0x0)
	{
		Fcu_Vdy_VehSigData->VehSigMain.State[VDY_SIN_POS_YWR] 	= VDY_IO_STATE_INIT;
	}
	else if(ptr_Fcu_Rte_input_Signal->ChassisDomain_Data.u8_Rte_ESP_YawRateValid == 0x1)
	{
		Fcu_Vdy_VehSigData->VehSigMain.State[VDY_SIN_POS_YWR] 	= VDY_IO_STATE_VALID;
	}
	else if(ptr_Fcu_Rte_input_Signal->ChassisDomain_Data.u8_Rte_ESP_YawRateValid == 0x2)
	{
		Fcu_Vdy_VehSigData->VehSigMain.State[VDY_SIN_POS_YWR] 	= VDY_IO_STATE_INVALID;
	}
	else
	{
		Fcu_Vdy_VehSigData->VehSigMain.State[VDY_SIN_POS_YWR] 	= VDY_IO_STATE_NOTAVAIL;
	}

	//Fcu_Vdy_VehSigData->VehSigMain.State[VDY_SIN_POS_YWR_TEMP]
	/*
	EpsSasSteerAgVld:    0x0:Valid    0x1:Invalid
	*/
	Fcu_Vdy_VehSigData->VehSigMain.State[VDY_SIN_POS_SWA] 		= ptr_Fcu_Rte_input_Signal->ChassisDomain_Data.u8_Rte_EpsSasSteerAgVld;

	/*ESP_LatAccelValid:
		0x0:Initializing
		0x1:Valid
		0x2:Invalid
		0x3:Reserved
	*/
	if(ptr_Fcu_Rte_input_Signal->ChassisDomain_Data.u8_Rte_ESP_LatAccelValid == 0x0)
	{
		Fcu_Vdy_VehSigData->VehSigMain.State[VDY_SIN_POS_LATA] 	= VDY_IO_STATE_INIT;
	}
	else if(ptr_Fcu_Rte_input_Signal->ChassisDomain_Data.u8_Rte_ESP_LatAccelValid == 0x1)
	{
		Fcu_Vdy_VehSigData->VehSigMain.State[VDY_SIN_POS_LATA] 	= VDY_IO_STATE_VALID;
	}
	else if(ptr_Fcu_Rte_input_Signal->ChassisDomain_Data.u8_Rte_ESP_LatAccelValid == 0x2)
	{
		Fcu_Vdy_VehSigData->VehSigMain.State[VDY_SIN_POS_LATA]	= VDY_IO_STATE_INVALID;
	}
	else
	{
		Fcu_Vdy_VehSigData->VehSigMain.State[VDY_SIN_POS_LATA] 	= VDY_IO_STATE_NOTAVAIL;
	}

	/*
		0x0:Valid
		0x1:Invalid 
	*/
	Fcu_Vdy_VehSigData->VehSigMain.State[VDY_SIN_POS_WVEL_FL] 	= ptr_Fcu_Rte_input_Signal->PowertrainDomain_Data.u8_Rte_WhlSpdLeFrntDataVld;
	Fcu_Vdy_VehSigData->VehSigMain.State[VDY_SIN_POS_WVEL_FR] 	= ptr_Fcu_Rte_input_Signal->PowertrainDomain_Data.u8_Rte_WhlSpdRiFrntDataVld;
	Fcu_Vdy_VehSigData->VehSigMain.State[VDY_SIN_POS_WVEL_RL] 	= ptr_Fcu_Rte_input_Signal->PowertrainDomain_Data.u8_Rte_WhlSpdLeReDataVld;
	Fcu_Vdy_VehSigData->VehSigMain.State[VDY_SIN_POS_WVEL_RR] 	= ptr_Fcu_Rte_input_Signal->PowertrainDomain_Data.u8_Rte_WhlSpdRiReDataVld;
	//Fcu_Vdy_VehSigData->VehSigMain.State[VDY_SIN_POS_YWRINT] 	= 
	//Fcu_Vdy_VehSigData->VehSigMain.State[VDY_SIN_POS_YWRINT_TEMP] 	= 
	Fcu_Vdy_VehSigData->VehSigMain.State[VDY_SIN_POS_LONGA] 		= 0;
	//Fcu_Vdy_VehSigData->VehSigMain.State[VDY_SIN_POS_RSTA] 	= 
	Fcu_Vdy_VehSigData->VehSigMain.State[VDY_SIN_POS_VEHVEL_EXT] = ptr_Fcu_Rte_input_Signal->ChassisDomain_Data.u8_Rte_EspVehSpdVld;
	Fcu_Vdy_VehSigData->VehSigMain.State[VDY_SIN_POS_VEHACL_EXT] = 0;

    if (ptr_Fcu_Rte_input_Signal->PowertrainDomain_Data.u8_Rte_WhlSpdLeFrntDir == 0x3 
		|| ptr_Fcu_Rte_input_Signal->PowertrainDomain_Data.u8_Rte_WhlSpdLeFrntDataVld == 0x1)
    {
        Fcu_Vdy_VehSigData->VehSigMain.State[VDY_SIN_POS_WDIR_FL] = VDY_IO_STATE_INVALID; /* Invalid */
    }
    else
    {
        Fcu_Vdy_VehSigData->VehSigMain.State[VDY_SIN_POS_WDIR_FL] = VDY_IO_STATE_VALID; /* Valid */
    }

    if (ptr_Fcu_Rte_input_Signal->PowertrainDomain_Data.u8_Rte_WhlSpdRiFrntDir == 0x3 
		|| ptr_Fcu_Rte_input_Signal->PowertrainDomain_Data.u8_Rte_WhlSpdRiFrntDataVld == 0x1)
    {
        Fcu_Vdy_VehSigData->VehSigMain.State[VDY_SIN_POS_WDIR_FR] = VDY_IO_STATE_INVALID; /* Invalid */
    }
    else
    {
        Fcu_Vdy_VehSigData->VehSigMain.State[VDY_SIN_POS_WDIR_FR] = VDY_IO_STATE_VALID; /* Valid */
    }

    if (ptr_Fcu_Rte_input_Signal->PowertrainDomain_Data.u8_Rte_WhlSpdLeReDir == 0x3 
		|| ptr_Fcu_Rte_input_Signal->PowertrainDomain_Data.u8_Rte_WhlSpdLeReDataVld == 0x1)
    {
        Fcu_Vdy_VehSigData->VehSigMain.State[VDY_SIN_POS_WDIR_RL] = VDY_IO_STATE_INVALID; /* Invalid */
    }
    else
    {
        Fcu_Vdy_VehSigData->VehSigMain.State[VDY_SIN_POS_WDIR_RL] = VDY_IO_STATE_VALID; /* Valid */
    }

    if (ptr_Fcu_Rte_input_Signal->PowertrainDomain_Data.u8_Rte_WhlSpdRiReDir == 0x3 
		|| ptr_Fcu_Rte_input_Signal->PowertrainDomain_Data.u8_Rte_WhlSpdRiReDataVld == 0x1)
    {
        Fcu_Vdy_VehSigData->VehSigMain.State[VDY_SIN_POS_WDIR_RR] = VDY_IO_STATE_INVALID; /* Invalid */
    }
    else
    {
        Fcu_Vdy_VehSigData->VehSigMain.State[VDY_SIN_POS_WDIR_RR] = VDY_IO_STATE_VALID; /* Valid */
    }

	/*
		0x0:Valid
		0x1:Invalid 
	*/
	/*VDY mapping review by Jiang,youni: not use,set VDY_IO_STATE_INVALID*/
	Fcu_Vdy_VehSigData->VehSigMain.State[VDY_SIN_POS_WTCKS_FL] 	= VDY_IO_STATE_INVALID;//WhlSpdLeFrntDataVld;
	Fcu_Vdy_VehSigData->VehSigMain.State[VDY_SIN_POS_WTCKS_FR] 	= VDY_IO_STATE_INVALID;//WhlSpdRiFrntDataVld;
	Fcu_Vdy_VehSigData->VehSigMain.State[VDY_SIN_POS_WTCKS_RL] 	= VDY_IO_STATE_INVALID;//WhlSpdLeReDataVld;
	Fcu_Vdy_VehSigData->VehSigMain.State[VDY_SIN_POS_WTCKS_RR] 	= VDY_IO_STATE_INVALID;//WhlSpdRiReDataVld;
	Fcu_Vdy_VehSigData->VehSigMain.State[VDY_SIN_POS_GEAR] 		= ptr_Fcu_Rte_input_Signal->ChassisDomain_Data.u8_Rte_VcuVehGearPosnVld;
	Fcu_Vdy_VehSigData->VehSigMain.State[VDY_SIN_POS_BRAKE] 		= 0;
	if (ptr_Fcu_Rte_input_Signal->ChassisDomain_Data.u8_Rte_EspVehSpdVld == 0x0)
	{
		Fcu_Vdy_VehSigData->VehSigMain.State[VDY_SIN_POS_PBRK] = VDY_IO_STATE_VALID;
	}
	else
	{
		Fcu_Vdy_VehSigData->VehSigMain.State[VDY_SIN_POS_PBRK] = VDY_IO_STATE_INVALID; 
	}
	//Fcu_Vdy_VehSigData->VehSigMain.State[VDY_SIN_POS_VDIR] 	= 
	//Fcu_Vdy_VehSigData->VehSigMain.State[VDY_SIN_POS_VMOT] 	= 
	//Fcu_Vdy_VehSigData->VehSigMain.State[VDY_SIN_POS_DUMMY] 	= 
	//Fcu_Vdy_VehSigData->VehSigMain.State[VDY_SIN_POS_CRV] 		= 
	//Fcu_Vdy_VehSigData->VehSigMain.State[VDY_SIN_POS_SSA] 		= 
	//Fcu_Vdy_VehSigData->VehSigMain.State[VDY_SIN_POS_MAX] 		= 

	/*
		VehLongAccelExt
	*/
	Fcu_Vdy_VehSigData->VehSigMain.VehLongAccelExt = ptr_Fcu_Rte_input_Signal->ChassisDomain_Data.f32_Rte_EspLongAccel;
	Fcu_Vdy_VehSigData->VehSigAdd.GasPedalPos = ptr_Fcu_Rte_input_Signal->ChassisDomain_Data.f32_Rte_VcuAccrPedlPosn;
	/*
		WhlDirFrLeft
		0x0:Forward
		0x1:backward
		0x2:Standstill
		0x3:Invalid
	*/
	if(ptr_Fcu_Rte_input_Signal->PowertrainDomain_Data.u8_Rte_WhlSpdLeFrntDir == 0x0)
    {
        Fcu_Vdy_VehSigData->VehSigMain.WhlDirFrLeft = 1; /* VDY_LONG_DIR_FWD */
    }
	else if(ptr_Fcu_Rte_input_Signal->PowertrainDomain_Data.u8_Rte_WhlSpdLeFrntDir == 0x1)
    {
    	Fcu_Vdy_VehSigData->VehSigMain.WhlDirFrLeft = 2; /* VDY_LONG_DIR_RWD */
    }
	else
    {
        Fcu_Vdy_VehSigData->VehSigMain.WhlDirFrLeft = 0; /* VDY_LONG_DIR_VOID */
    }
	/*
		WhlDirFrRight
	*/
	if(ptr_Fcu_Rte_input_Signal->PowertrainDomain_Data.u8_Rte_WhlSpdRiFrntDir == 0x0)
    {
        Fcu_Vdy_VehSigData->VehSigMain.WhlDirFrRight = 1; /* VDY_LONG_DIR_FWD */
    }
	else if(ptr_Fcu_Rte_input_Signal->PowertrainDomain_Data.u8_Rte_WhlSpdRiFrntDir == 0x1)
    {
    	Fcu_Vdy_VehSigData->VehSigMain.WhlDirFrRight = 2; /* VDY_LONG_DIR_RWD */
    }
	else
    {
        Fcu_Vdy_VehSigData->VehSigMain.WhlDirFrRight = 0; /* VDY_LONG_DIR_VOID */
    }
	/*
		WhlDirReLeft
	*/
	if(ptr_Fcu_Rte_input_Signal->PowertrainDomain_Data.u8_Rte_WhlSpdLeFrntDir == 0x0)
    {
        Fcu_Vdy_VehSigData->VehSigMain.WhlDirReLeft = 1; /* VDY_LONG_DIR_FWD */
    }
	else if(ptr_Fcu_Rte_input_Signal->PowertrainDomain_Data.u8_Rte_WhlSpdLeFrntDir == 0x1)
    {
    	Fcu_Vdy_VehSigData->VehSigMain.WhlDirReLeft = 2; /* VDY_LONG_DIR_RWD */
    }
	else //Wheel_Speed_RL_Direction == 0x2
    {
        Fcu_Vdy_VehSigData->VehSigMain.WhlDirReLeft = 0; /* VDY_LONG_DIR_VOID */
    }
	/*
		WhlDirReRight
	*/
	if(ptr_Fcu_Rte_input_Signal->PowertrainDomain_Data.u8_Rte_WhlSpdRiReDir == 0x0)
    {
        Fcu_Vdy_VehSigData->VehSigMain.WhlDirReRight = 1; /* VDY_LONG_DIR_FWD */
    }
	else if(ptr_Fcu_Rte_input_Signal->PowertrainDomain_Data.u8_Rte_WhlSpdRiReDir == 0x1)
    {
    	Fcu_Vdy_VehSigData->VehSigMain.WhlDirReRight = 2; /* VDY_LONG_DIR_RWD */
    }
	else
    {
        Fcu_Vdy_VehSigData->VehSigMain.WhlDirReRight = 0; /* VDY_LONG_DIR_VOID */
    }
	/*
	VDY Input ASIMA - ABSCtrl
		Raw GW_1C2.EspAbsActv, i.e. EspAbsActv.
			0x0u: Not active
			0x1u: Active
	*/
	Fcu_Vdy_VehSigData->Brake.ABSCtrl = ptr_Fcu_Rte_input_Signal->ChassisDomain_Data.u8_Rte_EspAbsActv;
	/*
	VDY Input ASIMA - TCSCtrl
		Raw EspTcsActvSts
			0x0=No_Active
			0x1=Active
	*/
	Fcu_Vdy_VehSigData->Brake.TCSCtrl = ptr_Fcu_Rte_input_Signal->ChassisDomain_Data.u8_Rte_EspTcsActvSts;

	Fcu_Vdy_VehSigData->VehSigMain.VehVelocityExtTimeStamp = (uint32)s64_timestamp;
	Fcu_Vdy_VehSigData->VehSigMain.VehVelocityExt = ptr_Fcu_Rte_input_Signal->ChassisDomain_Data.f32_Rte_EspVehSpd * 0.2777777778;//unit convert : km/h-->m/s

	Fcu_Vdy_VehSigData->VehSigMain.WhlVelFrLeftTimeStamp = (uint32)s64_timestamp;
	Fcu_Vdy_VehSigData->VehSigMain.WhlVelFrLeft = ptr_Fcu_Rte_input_Signal->PowertrainDomain_Data.f32_Rte_WhlSpdLeFrntData * 0.2777777778;

	Fcu_Vdy_VehSigData->VehSigMain.WhlVelFrRightTimeStamp = (uint32)s64_timestamp;
	Fcu_Vdy_VehSigData->VehSigMain.WhlVelFrRight = ptr_Fcu_Rte_input_Signal->PowertrainDomain_Data.f32_Rte_WhlSpdRiFrntData * 0.2777777778;

	Fcu_Vdy_VehSigData->VehSigMain.WhlVelReLeftTimeStamp = (uint32)s64_timestamp;
	Fcu_Vdy_VehSigData->VehSigMain.WhlVelReLeft = ptr_Fcu_Rte_input_Signal->PowertrainDomain_Data.f32_Rte_WhlSpdLeReData * 0.2777777778;

	Fcu_Vdy_VehSigData->VehSigMain.WhlVelReRightTimeStamp = (uint32)s64_timestamp;
	Fcu_Vdy_VehSigData->VehSigMain.WhlVelReRight = ptr_Fcu_Rte_input_Signal->PowertrainDomain_Data.f32_Rte_WhlSpdRiReData * 0.2777777778;
	

	Fcu_Vdy_VehSigData->VehSigAdd.SpeedUnit = 1;//set unit
	if (ptr_Fcu_Rte_input_Signal->ChassisDomain_Data.f32_Rte_EspVehSpd <= 5) {
		Fcu_Vdy_VehSigData->VehSigAdd.SpeedoSpeed = (float32)((uint32)ptr_Fcu_Rte_input_Signal->ChassisDomain_Data.f32_Rte_EspVehSpd);
	} else {
		Fcu_Vdy_VehSigData->VehSigAdd.SpeedoSpeed = (float32)((uint32)(ptr_Fcu_Rte_input_Signal->ChassisDomain_Data.f32_Rte_EspVehSpd/0.98 + 2));
	}

	Fcu_Vdy_VehSigData->VehSigMain.StWheelAngleTimeStamp = (uint32)s64_timestamp;
	Fcu_Vdy_VehSigData->VehSigMain.StWheelAngle = ptr_Fcu_Rte_input_Signal->ChassisDomain_Data.f32_Rte_EpsSasSteerAg * (3.141592653589793f/180.0);//unit convert : degree-->rad/s

	Fcu_Vdy_VehSigData->VehSigMain.YawRateTimeStamp = (uint32)s64_timestamp;
	/*TBD : Shall be check the - is rigth???*/
	Fcu_Vdy_VehSigData->VehSigMain.YawRate = (-1)*((ptr_Fcu_Rte_input_Signal->ChassisDomain_Data.f32_Rte_EspYawRate * 3.141592653589793f) / 180.0);

	Fcu_Vdy_VehSigData->VehSigMain.LatAccelTimeStamp = (uint32)s64_timestamp;
	Fcu_Vdy_VehSigData->VehSigMain.LatAccel = (-1)*ptr_Fcu_Rte_input_Signal->ChassisDomain_Data.f32_Rte_EspLatAccel;
	Fcu_Vdy_VehSigData->VehSigMain.VehLongAccelExtTimeStamp = (uint32)s64_timestamp;
	Fcu_Vdy_VehSigData->VehSigMain.LongAccel = ptr_Fcu_Rte_input_Signal->ChassisDomain_Data.f32_Rte_EspLongAccel;

/*TODO : The requirement from Lcf ASIMA Mapping */
    if(
		((0x01 == ptr_Fcu_Rte_input_Signal->BodyDomain_Data.u8_Rte_BcmTurnLightSwitchStst)
		||(0x01== ptr_Fcu_Rte_input_Signal->BodyDomain_Data.u8_Rte_BcmTurnIndcrLe)) 
		&& (0x01 != ptr_Fcu_Rte_input_Signal->BodyDomain_Data.u8_Rte_BcmEmgyLiSts)
	)
    {
        Fcu_Vdy_VehSigData->VehSigAdd.TurnSignal = 0x01;//Left
    }
    else if(
			((0x02 == ptr_Fcu_Rte_input_Signal->BodyDomain_Data.u8_Rte_BcmTurnLightSwitchStst)
			||(0x01== ptr_Fcu_Rte_input_Signal->BodyDomain_Data.u8_Rte_BcmTurnIndcrRi)) 
			&& (0x01 != ptr_Fcu_Rte_input_Signal->BodyDomain_Data.u8_Rte_BcmEmgyLiSts)
		)
    {
        Fcu_Vdy_VehSigData->VehSigAdd.TurnSignal = 0x02;//Right
    }
    else if(
			((0x00 == ptr_Fcu_Rte_input_Signal->BodyDomain_Data.u8_Rte_BcmTurnLightSwitchStst)
			||((0x02== ptr_Fcu_Rte_input_Signal->BodyDomain_Data.u8_Rte_BcmTurnIndcrLe)
			&&(0x02== ptr_Fcu_Rte_input_Signal->BodyDomain_Data.u8_Rte_BcmTurnIndcrRi)))
			&& (0x01 != ptr_Fcu_Rte_input_Signal->BodyDomain_Data.u8_Rte_BcmEmgyLiSts)
		 )
    {
     	Fcu_Vdy_VehSigData->VehSigAdd.TurnSignal = 0x03;//Neutral
    }
    else if(0x01 == ptr_Fcu_Rte_input_Signal->BodyDomain_Data.u8_Rte_BcmEmgyLiSts)
    {
        Fcu_Vdy_VehSigData->VehSigAdd.TurnSignal = 0x04;//Both
    }
    else
    {
        Fcu_Vdy_VehSigData->VehSigAdd.TurnSignal = 0x00;//unknown
    }

	//gear  0-->Invalid  1-->P  2-->R  3-->N  4-->D
	//Com_ReceiveSignal(ComConf_ComSignal_SGVcuGearPosn_353R,&raw_gear);
	//Com_ReceiveSignal(ComConf_ComSignal_SGVcuVehGearPosnVld_353R,&raw_gear_valid);
	if(0 == ptr_Fcu_Rte_input_Signal->ChassisDomain_Data.u8_Rte_VcuVehGearPosnVld)
	{
		if(ptr_Fcu_Rte_input_Signal->ChassisDomain_Data.u8_Rte_VcuGearPosn == 1)
		{
			Fcu_Vdy_VehSigData->PowerTrain.ActualGear = 11;
			Fcu_Vdy_VehSigData->VehSigMain.ActGearPos = 1;
		}
		else if(ptr_Fcu_Rte_input_Signal->ChassisDomain_Data.u8_Rte_VcuGearPosn == 2)
		{
			Fcu_Vdy_VehSigData->PowerTrain.ActualGear = 10;
			Fcu_Vdy_VehSigData->VehSigMain.ActGearPos = 3;
		}
		else if(ptr_Fcu_Rte_input_Signal->ChassisDomain_Data.u8_Rte_VcuGearPosn == 3)
		{
			Fcu_Vdy_VehSigData->PowerTrain.ActualGear = 0;
			Fcu_Vdy_VehSigData->VehSigMain.ActGearPos = 0;
		}
		else if(ptr_Fcu_Rte_input_Signal->ChassisDomain_Data.u8_Rte_VcuGearPosn == 4)
		{
			Fcu_Vdy_VehSigData->PowerTrain.ActualGear = 1;
			Fcu_Vdy_VehSigData->VehSigMain.ActGearPos = 2;
		}
		else
		{
			Fcu_Vdy_VehSigData->PowerTrain.ActualGear = 255;
			Fcu_Vdy_VehSigData->VehSigMain.State[VDY_SIN_POS_GEAR] = 1;
		}
	}
	else
	{
		Fcu_Vdy_VehSigData->PowerTrain.ActualGear =255;
	}

	if(0x1 == ptr_Fcu_Rte_input_Signal->ChassisDomain_Data.u8_Rte_IbBrkPedlStsGbVld)
	{
		if(ptr_Fcu_Rte_input_Signal->ChassisDomain_Data.u8_Rte_IbBrkPedlStsGb > 2)
		{
			Fcu_Vdy_VehSigData->VehSigAdd.BrakePedalPressed = 1;
		}
		else
		{
			Fcu_Vdy_VehSigData->VehSigAdd.BrakePedalPressed = 0;
		}

		if(0x65 == ptr_Fcu_Rte_input_Signal->ChassisDomain_Data.u8_Rte_IbBrkPedlStsGb)
		{
			//Fcu_DimInputGenericData.eDriverBraking = 0x01;
		}
		else
		{
			//Fcu_DimInputGenericData.eDriverBraking = 0x00;
		}
	}
	else
	{
		//Fcu_DimInputGenericData.eDriverBraking = 0x02;
		//nothing to do 
	}

	if (ptr_Fcu_Rte_input_Signal->BodyDomain_Data.u8_Rte_BcmFrntWiperSts == 1 
		|| ptr_Fcu_Rte_input_Signal->BodyDomain_Data.u8_Rte_BcmFrntWiperSts == 2)
	{
		Fcu_Vdy_VehSigData->VehSigAdd.WiperState = 1;
	}
	else 
	{
		Fcu_Vdy_VehSigData->VehSigAdd.WiperState = 0;
	}

	if (ptr_Fcu_Rte_input_Signal->BodyDomain_Data.u8_Rte_BcmFrntWiperSts == 1)
	{
		Fcu_Vdy_VehSigData->VehSigAdd.WiperStage = 5;
	}
	else if(ptr_Fcu_Rte_input_Signal->BodyDomain_Data.u8_Rte_BcmFrntWiperSts == 2)
	{
		Fcu_Vdy_VehSigData->VehSigAdd.WiperStage = 6;
	}
	else 
	{
		Fcu_Vdy_VehSigData->VehSigAdd.WiperStage = 0;
	}

	Fcu_Vdy_VehSigData->VehSigAdd.EspStatus = ptr_Fcu_Rte_input_Signal->ChassisDomain_Data.u8_Rte_EspActvSts;

	/*TODO : Write the VehSig to Rte*/
	(void)Rte_Write_PP_Fcu_VehSig_VehSig(Fcu_Vdy_VehSigData);
}



/**
 * \functions Fcu_RxProcess_VehPar
 *
 * \brief
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
static void Fcu_RxProcess_VehPar(VehPar_t* const Fcu_Vdy_VehPar)
{
	uint8 uint8_index = 0x0u;
	sint64 s64_timestamp = 0;

	/*TODO : get time stamp*/
	(void)Time_GetTimeStampMs(&s64_timestamp);

	/* Write signal sSigHeader_eSigStatus to AL_SIG_STATE_OK */
	Fcu_Vdy_VehPar->sSigHeader.eSigStatus = 1u; //AL_SIG_STATE_OK
	// Fcu_Vdy_VehPar->uiVersionNumber = 0x0;
	Fcu_Vdy_VehPar->uiVersionNumber = (AlgoInterfaceVersionNumber_t)BSW_VEH_PAR_INTFVER_LCF; //defined from Bench Test
	//Todo : The uint of time stamp  is ms 
	Fcu_Vdy_VehPar->sSigHeader.uiTimeStamp = (uint32)s64_timestamp;
	Fcu_Vdy_VehPar->sSigHeader.uiMeasurementCounter++;
	Fcu_Vdy_VehPar->sSigHeader.uiCycleCounter++;

	Fcu_Vdy_VehPar->VehParMain.SelfSteerGrad = 0;// Not Mandatory, TBD
	Fcu_Vdy_VehPar->VehParMain.SteeringRatio.swa.ang[0] = 0.0f; //TBD
	Fcu_Vdy_VehPar->VehParMain.SteeringRatio.swa.ang[1] = 0.0f; //TBD
	Fcu_Vdy_VehPar->VehParMain.SteeringRatio.swa.rat[0] = 14.45f; //referenced value :14.93 
	Fcu_Vdy_VehPar->VehParMain.SteeringRatio.swa.rat[1] = 14.45f; //referenced value :14.93 
	Fcu_Vdy_VehPar->VehParMain.SteeringRatio.vel.rat[0] = 57.33f; //TBD
	Fcu_Vdy_VehPar->VehParMain.SteeringRatio.vel.rat[1] = 57.33f; //TBD
	Fcu_Vdy_VehPar->VehParMain.SteeringRatio.vel.vel[0] = 0.0f; //TBD
	Fcu_Vdy_VehPar->VehParMain.SteeringRatio.vel.vel[1] = 0.0f; //TBD
	Fcu_Vdy_VehPar->VehParMain.WheelBase = 2.879f;
	Fcu_Vdy_VehPar->VehParMain.TrackWidthFront = 1.634f;
	Fcu_Vdy_VehPar->VehParMain.TrackWidthRear = 1.633f;
	Fcu_Vdy_VehPar->VehParMain.VehWeight = 2064.0f;
	Fcu_Vdy_VehPar->VehParMain.CntrOfGravHeight = 0.548f;
	Fcu_Vdy_VehPar->VehParMain.AxisLoadDistr = 0.544f;
	Fcu_Vdy_VehPar->VehParMain.WhlLoadDepFrontAxle = 1.0;
	Fcu_Vdy_VehPar->VehParMain.WhlLoadDepRearAxle = 1.0;
	Fcu_Vdy_VehPar->VehParMain.WhlCircumference = 2.316;
	Fcu_Vdy_VehPar->VehParMain.DrvAxle = 2u;
	Fcu_Vdy_VehPar->VehParMain.WhlTcksPerRev =  96u;// Not Mandatory , TBD
	Fcu_Vdy_VehPar->VehParMain.FrCrnrStiff = 0.0f;// Not Mandatory , TBD
	Fcu_Vdy_VehPar->VehParMain.ReCrnrStiff = 0.0f;// Not Mandatory , TBD
	
	/* Write signal VehParMain_State to VDY_IO_STATE_VALID */
	for (uint8_index = 0x0u; uint8_index < 32u; uint8_index++)
	{
		Fcu_Vdy_VehPar->VehParMain.State[uint8_index] = 0u;//VDY_IO_STATE_VALID
	}

	Fcu_Vdy_VehPar->VehParAdd.VehicleWidth = VDY_VEHICLEWIDTH;  //VDY_VEHICLEWIDTH ==  1.928f Wheel outer edge distance
	Fcu_Vdy_VehPar->VehParAdd.VehicleLength = 4.732f;
	Fcu_Vdy_VehPar->VehParAdd.CurbWeight = 2035.0f;
	Fcu_Vdy_VehPar->VehParAdd.OverhangFront = 0.882f;
	Fcu_Vdy_VehPar->VehParAdd.FrontAxleRoadDist = 0.33f;// Not Mandatory? TBD
	Fcu_Vdy_VehPar->VehParAdd.WheelWidth = 0.235f;// Not Mandatory , TBD
	Fcu_Vdy_VehPar->VehParAdd.PassableHeight = 1.52f;// Not Mandatory , TBD
	Fcu_Vdy_VehPar->VehParAdd.DistCameraToHoodX = 1.4713f; //VDY not used , TBD 
	Fcu_Vdy_VehPar->VehParAdd.DistCameraToHoodY = 0.4059f; //VDY not used , TBD 
	Fcu_Vdy_VehPar->VehParAdd.SteeringVariant = 1u;//VEH_PAR_ADD_STEERING_VAR_LEFT_SIDE=1

	/* Write signal VehParMain_State to VDY_IO_STATE_VALID */
	for (uint8_index = 0x0u; uint8_index < 32u; uint8_index++)
	{
		Fcu_Vdy_VehPar->VehParAdd.State[uint8_index] = 0u;//VDY_IO_STATE_VALID
	}

	Fcu_Vdy_VehPar->SensorMounting.LatPos = 0.094348f;//VDY not used , TBD 
	Fcu_Vdy_VehPar->SensorMounting.LongPos = -1.038336f;//VDY not used , TBD 
	Fcu_Vdy_VehPar->SensorMounting.VertPos = 0.982772f;//VDY not used , TBD 
	Fcu_Vdy_VehPar->SensorMounting.LongPosToCoG = Fcu_Vdy_VehPar->SensorMounting.LongPos + (Fcu_Vdy_VehPar->VehParMain.WheelBase * Fcu_Vdy_VehPar->VehParMain.AxisLoadDistr);//VDY not used , TBD
	Fcu_Vdy_VehPar->SensorMounting.PitchAngle = -0.007016f;//VDY not used , TBD 
	Fcu_Vdy_VehPar->SensorMounting.Orientation = 0u;//SENSOR_OR_NORMAL .VDY not used , TBD 
	Fcu_Vdy_VehPar->SensorMounting.RollAngle = 0.0f;//VDY not used , TBD 
	Fcu_Vdy_VehPar->SensorMounting.YawAngle = 0.0f;//VDY not used , TBD 

	/* Write signal SensorMounting_State to VDY_IO_STATE_VALID */
	for (uint8_index = 0x0u; uint8_index < 8u; uint8_index++)
	{
		Fcu_Vdy_VehPar->SensorMounting.State[uint8_index] = 0u;//VDY_IO_STATE_VALID
	}
 
	Fcu_Vdy_VehPar->Sensor.CoverDamping = 0.0f;//Not used
	Fcu_Vdy_VehPar->Sensor.fCoverageAngle = 0.0f;
	Fcu_Vdy_VehPar->Sensor.fLobeAngle = 0.0f;
	Fcu_Vdy_VehPar->Sensor.fCycleTime = 60.0f;
	Fcu_Vdy_VehPar->Sensor.uNoOfScans = 0u;

	/* Write signal Sensor_State to VDY_IO_STATE_VALID */
	for (uint8_index = 0x0u; uint8_index < 8u; uint8_index++)
	{
		Fcu_Vdy_VehPar->Sensor.State[uint8_index] = 0u;//VDY_IO_STATE_VALID
	}

	/*TODO : Write the VehPar to Rte*/
	(void)Rte_Write_PP_Fcu_VehPar_VehPar(Fcu_Vdy_VehPar);
    //Ioc_Write_Ioc_VehPar(Fcu_VehPar);
}