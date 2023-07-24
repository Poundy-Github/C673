/**
 * \file Cps_Lcfg.h
 *
 * \brief This file contains related data types of Cps.
 *
 * \version refer the Cps_Core.h.
 *
 */


#ifndef _CPS_LCFG_H_
#define _CPS_LCFG_H_
/*==================[inclusions]============================================*/
#include "Cps_Type.h"
#include "Cps_Cfg.h"

/*==================[external constants]====================================*/
extern boolean Cps_SignalPhyData_FC_AEBTargetDetection;
// FC_107/263T
extern boolean Cps_SignalPhyData_FC_LatAngReqActive;
// FC_1BA/442T
extern boolean Cps_SignalPhyData_ACC_LatAngReqActive;

extern boolean Cps_SignalPhyData_FC_HMALightDistribution;
extern uint8 Cps_SignalPhyData_FC_HMAStatus;

extern uint8 Cps_SignalPhyData_FC_FCWLatentWarning;
extern uint8 Cps_SignalPhyData_FC_AEBActive;
extern uint8 Cps_SignalPhyData_FC_AEBCtrlType;
extern uint8 Cps_SignalPhyData_FC_AEBVehilceHoldReq;
extern uint8 Cps_SignalPhyData_FC_PrefillActive;
extern uint8 Cps_SignalPhyData_FC_AWBlevel;
extern uint8 Cps_SignalPhyData_FC_AWBActive;
extern uint8 Cps_SignalPhyData_FC_FCWActive;
extern uint8 Cps_SignalPhyData_FC_ABAlevel;
extern uint8 Cps_SignalPhyData_FC_ABAActive;
extern uint8 Cps_SignalPhyData_FC_FCWPreWarning;
extern uint8 Cps_SignalPhyData_FC_OBJ_AEB_ID;
extern uint8 Cps_SignalPhyData_FC_AEBTargetType;
extern uint8 Cps_SignalPhyData_FC_AEBTargetProb;
extern uint8 Cps_SignalPhyData_FC_AEBTargetStatus;
extern uint8 Cps_SignalPhyData_ACC_LLaneMarkerType;
extern uint8 Cps_SignalPhyData_ACC_RLaneMarkerType;
extern uint8 Cps_SignalPhyData_ACC_HostLaneLeftStatus;
extern uint8 Cps_SignalPhyData_ACC_HostLaneRightStatus;
extern uint8 Cps_SignalPhyData_FC_HostLaneLeftStatus;
extern uint8 Cps_SignalPhyData_FC_HostLaneRightStatus;
extern uint8 Cps_SignalPhyData_FC_LDWStatus;
extern uint8 Cps_SignalPhyData_FC_LDWStatus_Current;
extern uint8 Cps_SignalPhyData_FC_LDWVibrationWarningReq;
extern uint8 Cps_SignalPhyData_FC_LKAStatus;
extern uint8 Cps_SignalPhyData_FC_LKAStatus_Current;
extern uint8 Cps_SignalPhyData_FC_LKATakeoverReq;
extern uint8 Cps_SignalPhyData_FC_LDWShakeLevStatus;
extern uint8 Cps_SignalPhyData_FC_ELKMode;
extern uint8 Cps_SignalPhyData_FC_ELKInterventionMode;
extern uint8 Cps_SignalPhyData_FC_AEBStatus;
extern uint8 Cps_SignalPhyData_FC_Voiceinfo;
extern uint8 Cps_SignalPhyData_FC_AEBTargetmode;
extern uint8 Cps_SignalPhyData_FC_AEBTextInfo;

extern float32 Cps_SignalPhyData_FC_AEBTargetDeceleration;
extern float32 Cps_SignalPhyData_FC_AEBTargetLngRange;
extern float32 Cps_SignalPhyData_FC_AEBTargetLatRange;
extern sint16 Cps_SignalPhyData_FC_AEBTargetRelSpeed;
extern float32 Cps_SignalPhyData_FC_AEBTargetAx;
extern float32 Cps_SignalPhyData_FC_AEBTargetAy;
extern float32 Cps_SignalPhyData_FC_AEBTargetLatRelSpeed ;
extern float32 Cps_SignalPhyData_ACC_LLaneDistanceFus;
extern float32 Cps_SignalPhyData_ACC_RLaneDistanceFus;
// FC_107/263T
extern float32 Cps_SignalPhyData_FC_LatAngReq;
// FC_1BA/442T
extern float32 Cps_SignalPhyData_ACC_LatAngReq;
extern float32 Cps_SignalPhyData_FC_MotorTorqueMaxLimitRequest;
extern float32 Cps_SignalPhyData_FC_MotorTorqueMinLimitRequest;

//HMI
extern uint8 Cps_SignalPhyData_FC_AEBEnable;
extern uint8 Cps_SignalPhyData_FC_FCWSettingStatus;
extern boolean Cps_SignalPhyData_FC_HMAEnableStatus;
extern uint8 Cps_SignalPhyData_FC_LASModeSelectionStatus;
extern uint8 Cps_SignalPhyData_FC_LASWarningModeSelectionSts;
extern uint8 Cps_SignalPhyData_FC_ELKEnableStatus;
extern uint8 Cps_SignalPhyData_FC_FCWStatus;

/*==================[internal constants]====================================*/
extern const s_Cps_SendSignalConfig_t Cps_SendSignalConfigTable[CPS_SEND_SIGNAL_NUMBER];

/*==================[external data]=========================================*/

/*==================[internal data]=========================================*/


#endif /* _CPS_LCFG_H_ */
