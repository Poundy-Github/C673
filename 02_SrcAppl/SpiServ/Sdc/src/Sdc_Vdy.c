/* ==================[Includes]=============================================== */
#include "Sdc_Vdy.h"
#include "Sdc_Vdy_Type.h"
#include "Rte_Type.h"
#include "Rte_Sdc.h"
#include "Sdc_Diag.h"
#include "Sdc_Core.h"
#include "SpiSync_Core.h"

/*==================[external data]=========================================*/


/*==================[internal data]=========================================*/
/*==================[.bss]==============================*/
#define SDC_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "Sdc_MemMap.h"

static VehDyn_t Sdc_Read_VehDynData;
u_Sdc_VdyDyn_t Sdc_Write_VehDynData;

#define SDC_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "Sdc_MemMap.h"
/*==================[macros]=================================================*/

/*==================[internal function declarations]========================*/



/*==================[external function definitions]=========================*/
/*==================[.text]==============================*/
#define SDC_START_SEC_CODE
#include "Sdc_MemMap.h"

/**
 * \functions Sdc_Vdy_InitFunction
 *
 * \brief
 *
 * \parameters-in
 *
 * \parameters-out
 *
 * \return 	none
 *
 * \comments
 */
FUNC(void, RTE_CODE) Sdc_Vdy_InitFunction(void)
{
    memset(&Sdc_Read_VehDynData, 0, sizeof(VehDyn_t));
    memset(&Sdc_Write_VehDynData, 0, sizeof(u_Sdc_VdyDyn_t));
}

/**
 * \functions Sdc_Vdy_DeInitFunction
 *
 * \brief
 *
 * \parameters-in
 *
 * \parameters-out
 *
 * \return 	none
 *
 * \comments
 */
FUNC(void, RTE_CODE) Sdc_Vdy_DeInitFunction(void)
{
    //TODO
}

/**
 * \functions Sdc_Vdy_MainFunction
 *
 * \brief
 *
 * \parameters-in
 *
 * \parameters-out
 *
 * \return 	none
 *
 * \comments
 */
FUNC(void, RTE_CODE) Sdc_Vdy_MainFunction(void)
{
    uint64 time_stamp = 0;
    uint64 timestamp_offset = 0x00;

	/*TODO : get time stamp and offset*/
	Time_GetTimeStampMs(&time_stamp);
    SpiSync_Core_GetTimestampOffset(&timestamp_offset);

	/*TODO : read data from VdyAdapter components*/
	Rte_Read_RP_VdyAdapter_VehDyn_VehDyn(&Sdc_Read_VehDynData);
    //Ioc_Read_Ioc_VehDyn(&Sdc_Read_VehDynData);

	/*TODO : Mapping data from VdyAdapter to Spi*/
	/*TODO : SigHeader */
	Sdc_Write_VehDynData.data.SigHeader.data.TimeStampe = Sdc_Read_VehDynData.sSigHeader.uiTimeStamp + timestamp_offset / 1000000;//ms
	Sdc_Write_VehDynData.data.SigHeader.data.eSignalStatus = Sdc_Read_VehDynData.sSigHeader.eSigStatus;
	Sdc_Write_VehDynData.data.SigHeader.data.flag_changing = Sdc_Diag_GetWorkmode();
	/*TODO : Longitudinal*/
	Sdc_Write_VehDynData.data.Longitudinal.data.Velocity = Sdc_Read_VehDynData.Longitudinal.Velocity;
	Sdc_Write_VehDynData.data.Longitudinal.data.varVelocity = Sdc_Read_VehDynData.Longitudinal.varVelocity;
	Sdc_Write_VehDynData.data.Longitudinal.data.Accel = Sdc_Read_VehDynData.Longitudinal.Accel;
	Sdc_Write_VehDynData.data.Longitudinal.data.varAccel = Sdc_Read_VehDynData.Longitudinal.varAccel;
	Sdc_Write_VehDynData.data.Longitudinal.data.VelocityCorrectionQuality = Sdc_Read_VehDynData.Longitudinal.VelocityCorrectionQuality;
	Sdc_Write_VehDynData.data.Longitudinal.data.VeloCorr_corrQual = Sdc_Read_VehDynData.Longitudinal.VeloCorr.corrQual;
	Sdc_Write_VehDynData.data.Longitudinal.data.VeloCorr_corrFact = Sdc_Read_VehDynData.Longitudinal.VeloCorr.corrFact;
	Sdc_Write_VehDynData.data.Longitudinal.data.VeloCorr_corrVar = Sdc_Read_VehDynData.Longitudinal.VeloCorr.corrVar;
	Sdc_Write_VehDynData.data.Longitudinal.data.VeloCorr_corrVelo = Sdc_Read_VehDynData.Longitudinal.VeloCorr.corrVelo;
	Sdc_Write_VehDynData.data.Longitudinal.data.VeloCorr_corrVeloVar = Sdc_Read_VehDynData.Longitudinal.VeloCorr.corrVeloVar;
	Sdc_Write_VehDynData.data.Longitudinal.data.VeloCorr_minVelo = Sdc_Read_VehDynData.Longitudinal.VeloCorr.minVelo;
	Sdc_Write_VehDynData.data.Longitudinal.data.VeloCorr_maxVelo = Sdc_Read_VehDynData.Longitudinal.VeloCorr.maxVelo;
	Sdc_Write_VehDynData.data.Longitudinal.data.AccelCorr_corrAccel = Sdc_Read_VehDynData.Longitudinal.AccelCorr.corrAccel;
	Sdc_Write_VehDynData.data.Longitudinal.data.AccelCorr_corrAccelVar = Sdc_Read_VehDynData.Longitudinal.AccelCorr.corrAccelVar;
	/*TODO : Lateral*/

	Sdc_Write_VehDynData.data.Lateral.data.YawRateVehDyn_YawRate = Sdc_Read_VehDynData.Lateral.YawRate.YawRate ;
	Sdc_Write_VehDynData.data.Lateral.data.YawRateVehDyn_YawRateRaw = Sdc_Read_VehDynData.Lateral.YawRate.YawRateRaw ;
	Sdc_Write_VehDynData.data.Lateral.data.YawRateVehDyn_YawAngle = Sdc_Read_VehDynData.Lateral.YawRate.YawAngle ;
	Sdc_Write_VehDynData.data.Lateral.data.YawRateVehDyn_Variance = Sdc_Read_VehDynData.Lateral.YawRate.Variance ;
	Sdc_Write_VehDynData.data.Lateral.data.YawRateVehDyn_Quality = Sdc_Read_VehDynData.Lateral.YawRate.Quality ;
	Sdc_Write_VehDynData.data.Lateral.data.OffCompStWheelAngle = Sdc_Read_VehDynData.Lateral.OffCompStWheelAngle ;
	Sdc_Write_VehDynData.data.Lateral.data.CurveVehDyn_Curve = Sdc_Read_VehDynData.Lateral.Curve.Curve;
	Sdc_Write_VehDynData.data.Lateral.data.CurveVehDyn_C1 = Sdc_Read_VehDynData.Lateral.Curve.C1 ;
	Sdc_Write_VehDynData.data.Lateral.data.CurveVehDyn_Gradient = Sdc_Read_VehDynData.Lateral.Curve.Gradient ;
	Sdc_Write_VehDynData.data.Lateral.data.CurveVehDyn_varC0 = Sdc_Read_VehDynData.Lateral.Curve.varC0 ;
	Sdc_Write_VehDynData.data.Lateral.data.CurveVehDyn_varC1 = Sdc_Read_VehDynData.Lateral.Curve.varC1 ;
	Sdc_Write_VehDynData.data.Lateral.data.CurveVehDyn_CurveQuality = Sdc_Read_VehDynData.Lateral.Curve.Quality ;
	Sdc_Write_VehDynData.data.Lateral.data.CurveVehDyn_CrvError = Sdc_Read_VehDynData.Lateral.Curve.CrvError ;
	Sdc_Write_VehDynData.data.Lateral.data.CurveVehDyn_CrvConf = Sdc_Read_VehDynData.Lateral.Curve.CrvConf ;
	Sdc_Write_VehDynData.data.Lateral.data.CurveVehDyn_VarCurve = Sdc_Read_VehDynData.Lateral.Curve.VarCurve ;
	Sdc_Write_VehDynData.data.Lateral.data.DrvIntCurveVehDyn_Curve = Sdc_Read_VehDynData.Lateral.DrvIntCurve.Curve ;
	Sdc_Write_VehDynData.data.Lateral.data.DrvIntCurveVehDyn_Variance = Sdc_Read_VehDynData.Lateral.DrvIntCurve.Variance ;
	Sdc_Write_VehDynData.data.Lateral.data.DrvIntCurveVehDyn_Gradient = Sdc_Read_VehDynData.Lateral.DrvIntCurve.Gradient ;
	Sdc_Write_VehDynData.data.Lateral.data.LatAccelVehDyn_LatAccel = Sdc_Read_VehDynData.Lateral.Accel.LatAccel ;
	Sdc_Write_VehDynData.data.Lateral.data.LatAccelVehDyn_Variance = Sdc_Read_VehDynData.Lateral.Accel.Variance ;
	Sdc_Write_VehDynData.data.Lateral.data.SideSlipVehDyn_SideSlipAngle = Sdc_Read_VehDynData.Lateral.SlipAngle.SideSlipAngle ;
	Sdc_Write_VehDynData.data.Lateral.data.SideSlipVehDyn_Variance = Sdc_Read_VehDynData.Lateral.SlipAngle.Variance ;
	Sdc_Write_VehDynData.data.Lateral.data.SelfSteerVehDyn_RoadBankAngle = Sdc_Read_VehDynData.Lateral.SelfSteering.RoadBankAngle ;
	Sdc_Write_VehDynData.data.Lateral.data.SelfSteerVehDyn_QuRoadBankAngle = Sdc_Read_VehDynData.Lateral.SelfSteering.QuRoadBankAngle ;
	Sdc_Write_VehDynData.data.Lateral.data.SelfSteerVehDyn_SelfSteerGradEst = Sdc_Read_VehDynData.Lateral.SelfSteering.SelfSteerGradEst ;
	Sdc_Write_VehDynData.data.Lateral.data.SelfSteerVehDyn_QuSelfSteerGradEst = Sdc_Read_VehDynData.Lateral.SelfSteering.QuSelfSteerGradEst ;
	/*TODO : MotionState*/
	Sdc_Write_VehDynData.data.MotionState.data.MotState = Sdc_Read_VehDynData.MotionState.MotState;
	Sdc_Write_VehDynData.data.MotionState.data.bRollerTestBench = Sdc_Read_VehDynData.MotionState.bRollerTestBench;
	Sdc_Write_VehDynData.data.MotionState.data.Confidence = Sdc_Read_VehDynData.MotionState.Confidence;
	/*TODO : Legacy*/
	Sdc_Write_VehDynData.data.Legacy.data.YawRateMaxJitter = Sdc_Read_VehDynData.Legacy.YawRateMaxJitter;
	Sdc_Write_VehDynData.data.Legacy.data.bStandStill = Sdc_Read_VehDynData.Legacy.bStandStill;

	/*TODO : State*/
	memcpy(&Sdc_Write_VehDynData.data.State.State[0], &Sdc_Read_VehDynData.State[0], sizeof(State_array_t));

	/*TODO : Call API send data to SPI service*/
	// now cycle send to j3
}


#define SDC_STOP_SEC_CODE
#include "Sdc_MemMap.h"

/*==================[internal function definitions]=========================*/


