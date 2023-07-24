/**
 * \file Med_Stubs.h
 *
 * \brief
 *
 * \version refer the Med_Core.h.
 *
 */

#ifndef MED_STUBS_H
#define MED_STUBS_H

/*==================[inclusions]============================================*/
#include "Med_Type.h"
#include "CSC_Platform_Common.h"
#include "Rte_Med.h"
#include "Esh_Main.h"


#define Priority_A      0x09u
#define Priority_B      0x08u
#define Priority_C      0x07u
#define Priority_D      0x06u
#define Priority_E      0x05u
#define Priority_F      0x04u

#define MED_EC_INACTIVE     0x00U
#define MED_EC_ACTIVE       0x01U


/*==================[macros]=================================================*/

#if ((defined MED_PARENTDTC_ENABLED) && (MED_PARENTDTC_ENABLED == STD_ON))
typedef struct 
{
    uint8 timeout;
    uint8 crc;
	uint8 rc;
	uint8 dlc;
}s_Med_PDUFaultType_t;

typedef struct
{
    s_Med_PDUFaultType_t VCU_161;
	s_Med_PDUFaultType_t GW_17A;
	s_Med_PDUFaultType_t GW_170;
    s_Med_PDUFaultType_t GW_288;
	s_Med_PDUFaultType_t GW_2DE;
    s_Med_PDUFaultType_t GW_50;	
	s_Med_PDUFaultType_t GW_278;
	s_Med_PDUFaultType_t FR_136;
}s_Med_ParentDTC_t;
#endif

#if ((defined MED_INJECTION_ENABLED) && (MED_INJECTION_ENABLED == STD_ON))
typedef struct
{
    uint8 HighByte;
	uint8 MiddleByte;
	uint8 LowByte;
}s_Med_Dtc_t;

typedef struct
{
	s_Med_Dtc_t DTC;
    Dem_EventStatusType trigger;
}s_Med_InjectQueue_t;
#endif

typedef struct
{
	Com_Receive_BcmFrntWiperSts  ui8_BcmFrntWiperSts;
	Com_SignalSts_t              ui8_BcmFrntWiperSts_Status;
	Com_Receive_BcmTurnIndcrLe   ui8_BcmTurnIndcrLe;
	Com_SignalSts_t              ui8_BcmTurnIndcrLe_Status;
	Com_Receive_BcmTurnIndcrRi   ui8_BcmTurnIndcrRi;
	Com_SignalSts_t              ui8_BcmTurnIndcrRi_Status;
	//Com_Receive_EspVehSpd        f32_EspVehSpd;
	uint16_t                     ui16_EspVehSpd;
	//Com_SignalSts_t              ui8_EspVehSpd_Status;
	uint8_t                      ui8_EspVehSpd_Status;
	//Com_Receive_VcuAccrPedlPosn  f32_VcuAccrPedlPosn;
	uint16_t                     ui16_VcuAccrPedlPosn;
	//Com_SignalSts_t              ui8_VcuAccrPedlPosn_Status;
	uint8_t                      ui8_VcuAccrPedlPosn_Status;
	//Com_Receive_VcuGearPosn      f32_VcuGearPosn;
	uint8_t                      ui8_VcuGearPosn;
	//Com_SignalSts_t              ui8_VcuGearPosn_Status;
	uint8_t                      ui8_VcuGearPosn_Status;
	Com_Receive_WhlSpdLeFrntData f32_WhlSpdLeFrntData;
	Com_SignalSts_t              ui8_WhlSpdLeFrntData_Status;
	uint8_t      ui8_WhlSpdLeFrntDataVld;
	Com_Receive_WhlSpdLeFrntDir  ui8_WhlSpdLeFrntDir;
	Com_SignalSts_t              ui8_WhlSpdLeFrntDir_Status;
	Com_Receive_WhlSpdLeReData   f32_WhlSpdLeReData;
	Com_SignalSts_t              ui8_WhlSpdLeReData_Status;
	uint8_t      ui8_WhlSpdLeReDataVld;
	Com_Receive_WhlSpdLeReDir    ui8_WhlSpdLeReDir;
	Com_SignalSts_t              ui8_WhlSpdLeReDir_Status;
	Com_Receive_WhlSpdRiFrntData f32_WhlSpdRiFrntData;
	Com_SignalSts_t              ui8_WhlSpdRiFrntData_Status;
	uint8_t      ui8_WhlSpdRiFrntDataVld;
	Com_Receive_WhlSpdRiFrntDir  ui8_WhlSpdRiFrntDir;
	Com_SignalSts_t              ui8_WhlSpdRiFrntDir_Status;
	Com_Receive_WhlSpdRiReData   f32_WhlSpdRiReData;
	Com_SignalSts_t              ui8_WhlSpdRiReData_Status;
	uint8_t      ui8_WhlSpdRiReDataVld;
	Com_Receive_WhlSpdRiReDir    ui8_WhlSpdRiReDir;
	Com_SignalSts_t              ui8_WhlSpdRiReDir_Status;
	//Com_Recevie_EpsSasSteerAg    f32_EpsSasSteerAg;
    uint16_t                     ui16_EpsSasSteerAg;
	//Com_SignalSts_t              ui8_EpsSasSteerAg_Status;
	uint8_t                      ui8_EpsSasSteerAg_Status;
	//Com_Receive_EspLatAccel      f32_EspLatAccel;
    //Com_SignalSts_t              ui8_EspLatAccel_Status;
    //Com_Receive_EspLongAccel     f32_EspLongAccel;
    //Com_SignalSts_t              ui8_EspLongAccel_Status;
	//Com_Receive_EspYawRate       f32_EspYawRate;
    //Com_SignalSts_t              ui8_EspYawRate_Status;
    uint16_t                     ui16_EspLatAccel;
    uint8_t                      ui8_EspLatAccel_Status;
    uint16_t                     ui16_EspLongAccel;
    uint8_t                      ui8_EspLongAccel_Status;
	uint16_t                     ui16_EspYawRate;
    uint8_t                      ui8_EspYawRate_Status;
	Com_Receive_EspAbsFailr      ui8_EspAbsFailr;
    Com_SignalSts_t              ui8_EspAbsFailr_Status;
    Com_Receive_EspTcsFailr      ui8_EspTcsFailr;
    Com_SignalSts_t              ui8_EspTcsFailr_Status;
	Com_Receive_EspABAavailable  ui8_EspABAavailable;
    Com_SignalSts_t              ui8_EspABAavailable_Status;
    Com_Receive_EspAEBAvailable  ui8_EspAEBAvailable;
    Com_SignalSts_t              ui8_EspAEBAvailable_Status;
    Com_Receive_EspAWBavailable  ui8_EspAWBavailable;
    Com_SignalSts_t              ui8_EspAWBavailable_Status;
    Com_Receive_IbBrkPedlStsGb   ui8_IbBrkPedlStsGb;
    Com_SignalSts_t              ui8_IbBrkPedlStsGb_Status;
    Com_Receive_SrsDrvrBucSwtSts ui8_SrsDrvrBucSwtSts;
    Com_SignalSts_t              ui8_SrsDrvrBucSwtSts_Status;
	Com_Receive_EpsPinionang     f32_EpsPinionang;
    uint8_t              ui8_EpsPinionang_Status;
	Com_Receive_BcmEmgyLiSts     ui8_BcmEmgyLiSts;
    Com_SignalSts_t              ui8_BcmEmgyLiSts_Status;
    Com_Receive_EpsConcussAvailabilityStatus ui8_EpsConcussAvailabilityStatus;
    Com_Receive_EpsConcussAvailabilityStatus_Status ui8_EpsConcussAvailabilitySts_Status;
	Com_Receive_EpsMeasuredTorsionBarTorque f32_EpsMeasuredTorsionBarTorque;
    Com_SignalSts_t ui8_EpsMeasuredTorsionBarTorque_Status;
	Com_Receive_IP_QDashACCFail ui8_IP_QDashACCFail;
    Com_SignalSts_t ui8_IP_QDashACCFail_Status;
	Com_Receive_EspEbdFailr      ui8_EspEbdFailr;
    Com_SignalSts_t              ui8_EspEbdFailr_Status;
	uint8                        ui8_WhlSpdFrntLePls;
	uint8                        ui8_WhlSpdFrntRiPls;
	uint8                        ui8_WhlSpdReLePls;
	uint8                        ui8_WhlSpdReRiPls;
	uint8                        ui8_EpsSasCalSts;
	uint8                        ui8_Epsfaultstate;
	uint16                       ui16_EpsActualTorsionBarTorq;  
	uint16                       ui16_EpsActualMotorTorq;
	uint8                        ui8_EpsSteerAgSensFilr;
	uint8                        ui8_EpsFaild;
	uint8                        ui8_EpsAPAEpasFAILED;
	uint8                        ui8_IP_DISFail;
	uint8                        ui8_FRadarCalibrationStatus;
	uint8                        ui8_FR_RadarFailureStatus;
	uint8                        ui8_BCMBrakeLampError;
	uint8                        ui8_IbBrkPedlStsGbVld;
}s_Med_SignalStatusInfo_t;

typedef struct
{
    Cpr_Msg_State GW_50_PduSts;
    Cpr_Msg_State GW_170_PduSts;
    Cpr_Msg_State GW_17A_PduSts;      
    Cpr_Msg_State GW_17E_PduSts;    
    Cpr_Msg_State GW_180_PduSts;      
    Cpr_Msg_State GW_1C2_PduSts;      
    Cpr_Msg_State GW_20B_PduSts;      
    Cpr_Msg_State GW_24F_PduSts;      
    Cpr_Msg_State GW_278_PduSts;      
    Cpr_Msg_State GW_288_PduSts;      
    Cpr_Msg_State GW_28B_PduSts;      
    Cpr_Msg_State GW_2A8_PduSts;      
    Cpr_Msg_State GW_2C2_PduSts;     
    Cpr_Msg_State GW_2DE_PduSts;      
    Cpr_Msg_State GW_3C2_PduSts;      
    Cpr_Msg_State VCU_161_PduSts;     
    Cpr_Msg_State VCU_38A_PduSts;     
    Cpr_Msg_State FR_111_PduSts;      
    Cpr_Msg_State FR_112_PduSts;      
    Cpr_Msg_State FR_113_PduSts;      
    Cpr_Msg_State FR_114_PduSts;     
    Cpr_Msg_State FR_115_PduSts;      
    Cpr_Msg_State FR_116_PduSts;      
    Cpr_Msg_State FR_117_PduSts;      
    Cpr_Msg_State FR_118_PduSts;      
    Cpr_Msg_State FR_119_PduSts;      
    Cpr_Msg_State FR_11A_PduSts;     
    Cpr_Msg_State FR_11B_PduSts;      
    Cpr_Msg_State FR_11C_PduSts;     
    Cpr_Msg_State FR_11D_PduSts;      
    Cpr_Msg_State FR_11E_PduSts;      
    Cpr_Msg_State FR_11F_PduSts;      
    Cpr_Msg_State FR_120_PduSts;      
    Cpr_Msg_State FR_136_PduSts;      
    Cpr_Msg_State FR_138_PduSts;      
    Cpr_Msg_State ADC_19B_PduSts;    
    Cpr_Msg_State ADC_200_PduSts;     
    Cpr_Msg_State ADC_345_PduSts;     
    Cpr_Msg_State ADC_346_PduSts;    
}s_Med_MessageStatusInfo_t;

typedef struct
{
    uint8 ui8_BattVoltState;
	uint16 ui16_EcuTemperature;	
}s_Med_HardwareStatusInfo_t;

typedef struct
{
    uint8 ui8_CameraFailureStatus;
    uint8 ui8_AEBTextInfoStatus;
	uint8 ui8_CameraCalibrationStatus;
}s_Med_FCStatus_t;

typedef struct
{   
	s_Esh_EnableCondition_t EnableCondition;
	s_Med_SignalStatusInfo_t CanSignalStatus;
	s_Med_MessageStatusInfo_t  CanPduStatus;
	s_Med_HardwareStatusInfo_t  HardwareStatus;
	s_Med_FCStatus_t FCStatus;
}s_Med_ErrorInfo_t;


/*==================[external function declarations]========================*/
extern FUNC(boolean, RTE_CODE) Med_TestFailed_HwStatus_BattVoltTooLow(void);
extern FUNC(boolean, RTE_CODE) Med_TestFailed_HwStatus_BattVoltTooHigh(void);
extern FUNC(boolean, RTE_CODE) Med_TestFailed_HwStatus_McuExtTempTooLow(void);
extern FUNC(boolean, RTE_CODE) Med_TestFailed_HwStatus_McuExtTempTooHigh(void);
extern FUNC(boolean, RTE_CODE) Med_TestFailed_HwStatus_McuInitialTempTooHigh(void);
extern FUNC(boolean, RTE_CODE) Med_TestFailed_HwStatus_SpiDriverFault(void);
extern FUNC(boolean, RTE_CODE) Med_TestFailed_HwStatus_Dflash_Error(void);
extern FUNC(boolean, RTE_CODE) Med_TestFailed_CAN_SigalStatus_VCUAccrPedlPosnInvld(void);
extern FUNC(boolean, RTE_CODE) Med_TestFailed_CAN_SigalStatus_VCUGearPosnInvld(void);
extern FUNC(boolean, RTE_CODE) Med_TestFailed_CAN_SigalStatus_BCMTurnIndcrLightFault(void);
extern FUNC(boolean, RTE_CODE) Med_TestFailed_CAN_SigalStatus_BCMFrntWiperStsFault(void);
extern FUNC(boolean, RTE_CODE) Med_TestFailed_CAN_SigalStatus_ESPVehSpdInvld(void);
extern FUNC(boolean, RTE_CODE) Med_TestFailed_CAN_SigalStatus_WhlSpdPlsInvld(void);
extern FUNC(boolean, RTE_CODE) Med_TestFailed_CAN_SigalStatus_WhlSpdDirInvld(void);
extern FUNC(boolean, RTE_CODE) Med_TestFailed_CAN_SigalStatus_WhlSpdDataInvld(void);
extern FUNC(boolean, RTE_CODE) Med_TestFailed_CAN_SigalStatus_EPSSasNOTCal(void);
extern FUNC(boolean, RTE_CODE) Med_TestFailed_CAN_SigalStatus_EPSActualMotorTorqInvld(void);
extern FUNC(boolean, RTE_CODE) Med_TestFailed_CAN_SigalStatus_ESPLatAccelInvld(void);
extern FUNC(boolean, RTE_CODE) Med_TestFailed_CAN_SigalStatus_ESPLongAccelInvld(void);
extern FUNC(boolean, RTE_CODE) Med_TestFailed_CAN_SigalStatus_ESPYawRateInvld(void);
extern FUNC(boolean, RTE_CODE) Med_TestFailed_CAN_SigalStatus_EPSFault(void);
extern FUNC(boolean, RTE_CODE) Med_TestFailed_CAN_SigalStatus_ESPABSFault(void);
extern FUNC(boolean, RTE_CODE) Med_TestFailed_CAN_SigalStatus_ESPTCSFault(void);
extern FUNC(boolean, RTE_CODE) Med_TestFailed_CAN_SigalStatus_ESPABANOTAvailable(void);
extern FUNC(boolean, RTE_CODE) Med_TestFailed_CAN_SigalStatus_ESPAEBNOTAvailable(void);
extern FUNC(boolean, RTE_CODE) Med_TestFailed_CAN_SigalStatus_ESPAWBNOTAvailable(void);
extern FUNC(boolean, RTE_CODE) Med_TestFailed_CAN_SigalStatus_IBBrkPedlInvld(void);
extern FUNC(boolean, RTE_CODE) Med_TestFailed_CAN_SigalStatus_EPSActualTorsionTorqInvld(void);
extern FUNC(boolean, RTE_CODE) Med_TestFailed_CAN_SigalStatus_EPSActualMotorInvld(void);
extern FUNC(boolean, RTE_CODE) Med_TestFailed_CAN_SigalStatus_EPSSteerAgSensFault(void);
extern FUNC(boolean, RTE_CODE) Med_TestFailed_CAN_SigalStatus_SRSDrvrBucSwtInvld(void);
extern FUNC(boolean, RTE_CODE) Med_TestFailed_CAN_SigalStatus_EPSPinionangInvld(void);
extern FUNC(boolean, RTE_CODE) Med_TestFailed_CAN_SigalStatus_EPSPinionangFault(void);
extern FUNC(boolean, RTE_CODE) Med_TestFailed_CAN_SigalStatus_EPSAPAEpasFault(void);
extern FUNC(boolean, RTE_CODE) Med_TestFailed_CAN_SigalStatus_BCMEmgyLiFault(void);
extern FUNC(boolean, RTE_CODE) Med_TestFailed_CAN_SigalStatus_SteeringWheelVibrationFailure(void);
extern FUNC(boolean, RTE_CODE) Med_TestFailed_CAN_SigalStatus_DriverHandTorqueInvalid(void);
extern FUNC(boolean, RTE_CODE) Med_TestFailed_CAN_SigalStatus_IPWarningInvalid(void);
extern FUNC(boolean, RTE_CODE) Med_TestFailed_CAN_SigalStatus_FradarNotCalibrationOrBlockage(void);
extern FUNC(boolean, RTE_CODE) Med_TestFailed_CAN_SigalStatus_FradarHardwareError(void);
extern FUNC(boolean, RTE_CODE) Med_TestFailed_CAN_SigalStatus_BCMBrakeLampError(void);
extern FUNC(boolean, RTE_CODE) Med_TestFailed_CAN_SigalStatus_EspEbdFailr(void);
extern FUNC(boolean, RTE_CODE) Med_TestFailed_CAN_PduStatus_VCU_NodeMissing(void);
extern FUNC(boolean, RTE_CODE) Med_TestFailed_CAN_PduStatus_ESP_NodeMissing(void);
extern FUNC(boolean, RTE_CODE) Med_TestFailed_CAN_PduStatus_EPS_NodeMissing(void);
extern FUNC(boolean, RTE_CODE) Med_TestFailed_CAN_PduStatus_BCM_NodeMissing(void);
extern FUNC(boolean, RTE_CODE) Med_TestFailed_CAN_PduStatus_IP_NodeMissing(void);
extern FUNC(boolean, RTE_CODE) Med_TestFailed_CAN_PduStatus_SRS_NodeMissing(void);
extern FUNC(boolean, RTE_CODE) Med_TestFailed_CAN_PduStatus_FR_NodeMissing(void);
extern FUNC(boolean, RTE_CODE) Med_TestFailed_CAN_PduStatus_ADC_NodeMissing(void);
extern FUNC(boolean, RTE_CODE) Med_TestFailed_CAN_PduStatus_VCU_AliveCounterError(void);
extern FUNC(boolean, RTE_CODE) Med_TestFailed_CAN_PduStatus_ESP_AliveCounterError(void);
extern FUNC(boolean, RTE_CODE) Med_TestFailed_CAN_PduStatus_ESP_AliveCounterError_100ms(void);
extern FUNC(boolean, RTE_CODE) Med_TestFailed_CAN_PduStatus_EPS_AliveCounterError_10ms(void);
extern FUNC(boolean, RTE_CODE) Med_TestFailed_CAN_PduStatus_EPS_AliveCounterError_20ms(void);
extern FUNC(boolean, RTE_CODE) Med_TestFailed_CAN_PduStatus_FR_AliveCounterError(void);
extern FUNC(boolean, RTE_CODE) Med_TestFailed_CAN_PduStatus_BCM_AliveCounterError(void);
extern FUNC(boolean, RTE_CODE) Med_TestFailed_CAN_PduStatus_IP_AliveCounterError(void);
extern FUNC(boolean, RTE_CODE) Med_TestFailed_CAN_PduStatus_ADC_AliveCounterError(void);
extern FUNC(boolean, RTE_CODE) Med_TestFailed_CAN_PduStatus_SRS_AliveCounterError(void);
extern FUNC(boolean, RTE_CODE) Med_TestFailed_CAN_PduStatus_RLR_AliveCounterError(void);

extern FUNC(boolean, RTE_CODE) Med_EnableCondition_Group_PVPU(void);
extern FUNC(boolean, RTE_CODE) Med_EnableCondition_Group_PVPR(void);
extern FUNC(boolean, RTE_CODE) Med_EnableCondition_Group_PowerOn3000ms(void);
extern FUNC(boolean, RTE_CODE) Med_EnableCondition_Group_PV(void);
extern FUNC(boolean, RTE_CODE) Med_EnableCondition_Group_PVPUvcu(void);
extern FUNC(boolean, RTE_CODE) Med_EnableCondition_Group_PVPUesp(void);
extern FUNC(boolean, RTE_CODE) Med_EnableCondition_Group_PVPUeps(void);
extern FUNC(boolean, RTE_CODE) Med_EnableCondition_Group_PVPUbcm(void);
extern FUNC(boolean, RTE_CODE) Med_EnableCondition_Group_PVPUip(void);
extern FUNC(boolean, RTE_CODE) Med_EnableCondition_Group_PVPUsrs(void);
extern FUNC(boolean, RTE_CODE) Med_EnableCondition_Group_PVPUSesp(void);
extern FUNC(boolean, RTE_CODE) Med_EnableCondition_Group_BCM(void);
extern FUNC(boolean, RTE_CODE) Med_EnableCondition_Group_Esp_GW278(void);
extern FUNC(boolean, RTE_CODE) Med_EnableCondition_Group_FR_136(void);
#endif /* MED_STUBS_H */



