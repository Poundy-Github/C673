/**
 * \file Fcu_Type.h
 *
 * \brief
 *
 * \version
 * --------------------------------------------------------------------------------------------
 * Version	| 		Data		|		Author			| 	Comments
 * V0.0.1		2023.02.08			  Kun Zhang			Init version
 * V
 *
 *
 */
#ifndef __FCU_TYPE_H_
#define __FCU_TYPE_H_

/*==================[inclusions]============================================*/
#include "Std_Types.h" /* AUTOSAR standard types */
#include "Platform_Types.h"
#include "Rte_Algo_Type.h"
#include "Rte_Type.h"
#include "Rte_Fcu.h"
#include "Rte_Fcu_Type.h"
#include "Ioc_gen.h"
#include "cml_ext.h"
#include "Sdc_Perception_Type.h"
#include "Com_SymbolicNames_PBcfg.h"
#include "P_TrajPlanMathDefs.h"

/*==================[definee]============================================*/
#ifndef max
#define max( a, b ) ( ((a) > (b)) ? (a) : (b) )
#endif

#ifndef min
#define min( a, b ) ( ((a) < (b)) ? (a) : (b) )
#endif

#define VDY_VEHICLEWIDTH   1.928f  //Wheel outer edge distance
#define FC_LKATAKEOVER_REQ   STD_OFF //Customer delete
/*=======================================================================*/

typedef enum
{
    FUNC_FCW = 0,
    FUNC_FAB,
    FUNC_LDW_or_LKA,
    FUNC_LDW_Warning,
    FUNC_ELK,
    FUNC_AEB,
    FUNC_Factory_Mode
}e_Fcu_HMIFuncID_t;
	
typedef struct
{
    uint8 FCW_Switch;
    uint8 FAB_Switch;
    uint8 LDW_Switch;
    uint8 LDW_Warning;
    uint8 LKA_Switch;
    uint8 ELK_Switch;
    uint8 reserved;
}e_Hmi_FuncSwitch_Status_t;

typedef struct 
{
    /* data */
    uint8       u8_Rte_WhlSpdLeFrntDir;
    uint8       u8_Rte_WhlSpdLeReDir;
    uint8       u8_Rte_WhlSpdRiFrntDir;
    uint8       u8_Rte_WhlSpdRiReDir;
    uint8       u8_Rte_WhlSpdLeFrntDataVld;
    uint8       u8_Rte_WhlSpdLeReDataVld;
    uint8       u8_Rte_WhlSpdRiFrntDataVld;
    uint8       u8_Rte_WhlSpdRiReDataVld;
    float32     f32_Rte_WhlSpdLeFrntData;
    float32     f32_Rte_WhlSpdLeReData;
    float32     f32_Rte_WhlSpdRiFrntData;
    float32     f32_Rte_WhlSpdRiReData;
}s_Fcu_PowertrainDomain_SignalData_t;

typedef struct 
{
    /* data */
	uint8 	u8_Rte_BcmDrvrDoorSts;
	uint8 	u8_Rte_BcmLeReDoorSts;
	uint8 	u8_Rte_BcmPassDoorSts;
	uint8 	u8_Rte_BcmRiReDoorSts;
	uint8   u8_Rte_SrsDrvrBucSwtSts;
	uint8   u8_Rte_BcmTurnLightSwitchStst;
    uint8   u8_Rte_BcmTurnIndcrLe;
    uint8   u8_Rte_BcmTurnIndcrRi;
    uint8   u8_Rte_BcmEmgyLiSts;
    uint8   u8_Rte_BcmAutHeadLiSts;
    uint8   u8_Rte_BcmReFoglmpSts;
    uint8   u8_Rte_BcmHiBeamSts;
    uint8   u8_Rte_BcmFrntFogLmpSts;
    uint8   u8_Rte_BcmFrntWiperSts;
}s_Fcu_BodyDomain_SignalData_t;

typedef struct 
{
    /* data */
	uint8   u8_Rte_EspEbdFailr;
	uint8   u8_Rte_EspAbsFailr;
	uint8   u8_Rte_EspAbsActv ;
	uint8   u8_Rte_EspActvSts ;
    uint8   u8_Rte_EspTcsFailr; 
	uint8   u8_Rte_EspTcsActvSts;
    uint8   u8_Rte_EspAEBdecActive;
    uint8   u8_Rte_EspVdcActvSts;
	uint8   u8_Rte_EpsLatCtrlActive;
	uint8   u8_Rte_EpsIACCabortreason;
	uint8   u8_Rte_EpsLatCtrlAvailabilityStatus;
	uint8   u8_Rte_IbBrkPedlStsGb;
	uint8   u8_Rte_EspAEBAvailable;
	uint8   u8_Rte_EspAWBavailable;
	uint8   u8_Rte_EspABAavailable;
	uint8   u8_Rte_EsprefillAvailable;
	uint8	u8_Rte_VcuGearPosn;
    uint8   u8_Rte_ADS_UDLCStatus;
    uint8   u8_Rte_EpsConcussAvailabilityStatus;
    uint8   u8_Rte_EPS_Pinionang_Valid;
    uint8   u8_Rte_EPS_MeasuredTorsionBarTorqValid;
    uint8   u8_Rte_IBCU_PFSBrakePressureValid;
    uint8   u8_Rte_IbBrkPedlStsGbVld;
    uint8   u8_Rte_EpsSasSteerAgVld;
    uint8   u8_Rte_EspVehSpdVld;
    uint8   u8_Rte_ESP_YawRateValid;
    uint8   u8_Rte_ESP_LongAccelValid;
    uint8   u8_Rte_ESP_LatAccelValid;
    uint8   u8_Rte_VcuAccrPedlPosnVld;
    uint8   u8_Rte_VcuVehGearPosnVld;
    uint8   u8_Rte_IbBrkPedlTrvlDrvrVld;
    float32 f32_Rte_IbBrkPedlTrvlDrvr;
    float32 f32_Rte_EpsPinionang;
	float32 f32_Rte_EpsSasSteerAg;
	float32 f32_Rte_EpsSteerAgRate; 
	float32 f32_Rte_EpsMeasuredTorsionBarTorque;
	uint16 f32_Rte_BrakePressureSimulator;
	float32 f32_Rte_VcuAccrPedlPosn;
    float32 f32_Rte_EspLongAccel;
    float32 f32_Rte_EspLatAccel;
    float32 f32_Rte_EspVehSpd;
    float32 f32_Rte_EspYawRate;
}s_Fcu_ChassisDomain_SignalData_t;

typedef struct 
{
    /* data */
    uint8 	u8_Rte_Radar_Location[4];
    uint8   u8_Rte_Radar_ExistProb[4];
    uint8   u8_Rte_Radar_Measured[4];
	uint8   u8_Rte_AccIaccHWAMode;
	uint8   u8_Rte_ACC_ACCMode;//
    float32 f32_Rte_Radar_Dx[4];
    float32 f32_Rte_Radar_RelVx[4];
    float32 f32_Rte_Radar_RelAx[4];
    float32 f32_Rte_Radar_Dy[4];
    float32 f32_Rte_Radar_RelVy[4];
    float32 f32_Rte_Radar_Length[4];
    float32 f32_Rte_Radar_Width[4];
}s_Fcu_AdasDomain_SignalData_t;

typedef struct 
{
    /* data */
    uint8   u8_FC_AEBActive;
    uint8   u8_FC_AEBCtrlType;
    uint8   u8_FC_AEBEnable;
    uint8   u8_FC_AEBVehilceHoldReq;
    uint8   u8_FC_PrefillActive;
    uint8   u8_FC_AWBlevell;
    uint8   u8_FC_AWBActive;
    uint8   u8_FC_FCWActive;
    uint8   u8_FC_ABAlevel;
    uint8   u8_FC_ABAActive;
    uint8   u8_FC_FCWPreWarning;
    uint8   u8_FC_OBJ_AEB_ID;
    uint8   u8_FC_AEBTargetType;
    uint8   u8_FC_AEBTargetDetection;
    uint8   u8_FC_AEBTargetmode;
    uint8   u8_FC_AEBTextInfo;
    uint8   u8_FC_LLaneMarkerType;    //lcf
    uint8   u8_FC_RLaneMarkerType;    //lcf
    uint8   u8_FC_FCWSettingStatus;
    uint8   u8_FC_FCWStatus;
    uint8   u8_FC_AEBStatus;
    uint8   u8_FC_AEBTargetProb;
    uint8   u8_FC_FCWLatentWarning;
    uint8   u8_FC_Voiceinfo_Aeb;
    float32 f32_FC_AEBTargetLngRange;
    float32 f32_FC_AEBTargetDeceleration;
    float32 f32_FC_AEBTargetLatRange;
    float32 f32_FC_AEBTargetRelSpeed;
    float32 f32_FC_AEBTargetLatRelSpeed;
    float32 f32_FC_AEBTargetAy;
    float32 f32_FC_AEBTargetAx;
    float32 f32_FC_LLaneDistanceFus;   //lcf
    float32 f32_FC_RLaneDistanceFus;   //lcf

}s_Fcu_Aeb_SignalData_t;

typedef struct 
{
    /* data */
    uint8 empty;
    
}s_Fcu_Acc_SignalData_t;

typedef struct 
{
    /* data */
    uint8   u8_FC_HostLaneLeftStatus;
    uint8   u8_FC_HostLaneRightStatus;
    uint8   u8_FC_LDWStatus;
    uint8   u8_FC_LDWVibrationWarningReq;
    uint8   u8_FC_LKAStatus;
    uint8   u8_FC_LKATakeoverReq;
    uint8   u8_FC_LASModeSelectionStatus;
    uint8   u8_FC_LASWarningModeSelectionSts;
    uint8   u8_FC_LDWShakeLevStatus;
    uint8   u8_FC_ELKMode;
    uint8   u8_FC_ELKInterventionMode;
    uint8   u8_FC_ELKEnableStatus;
    uint8   u8_FC_LatAngReqActive;
    uint8   u8_FC_Voiceinfo_Lcf;
    float32 f32_FC_LatAngReq;
    float32 f32_FC_MotorTorqueMaxLimitRequest;
    float32 f32_FC_MotorTorqueMinLimitRequest;
}s_Fcu_Lcf_SignalData_t;

typedef struct 
{
    /* data */
    uint8 u8_FC_HMALightDistribution;
    uint8 u8_FC_HMAEnableStatus;
    uint8 u8_FC_HMAStatus;
    
}s_Fcu_Hla_SignalData_t;

typedef struct 
{
    s_Fcu_PowertrainDomain_SignalData_t     PowertrainDomain_Data;
    s_Fcu_BodyDomain_SignalData_t           BodyDomain_Data;
    s_Fcu_ChassisDomain_SignalData_t        ChassisDomain_Data;
    s_Fcu_AdasDomain_SignalData_t           AdasDomain_Data;

}s_Fcu_Rte_Input_SignalData_t;

typedef struct 
{
    s_Fcu_Aeb_SignalData_t                  Aeb_Data;
    s_Fcu_Acc_SignalData_t                  Acc_Data;    
    s_Fcu_Lcf_SignalData_t                  Lcf_Data;
    s_Fcu_Hla_SignalData_t                  Hla_Data;
    
}s_Fcu_Rte_Output_SignalData_t;



/*==================[external constants declarations]========================*/


/*==================[external data declarations]=============================*/

/*==================[external function declarations]=========================*/
#endif /* __FCU_TYPE_H_ */