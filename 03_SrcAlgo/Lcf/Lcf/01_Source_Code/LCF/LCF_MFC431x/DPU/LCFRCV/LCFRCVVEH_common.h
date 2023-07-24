/*! \file **********************************************************************

  TEMPLATE VERSION:          1.2
                             changed parameters in cpp version to be a struct/class
                             added version management for template

  COMPANY:                   Continental AG, ADAS, A.D.C. GmbH

  PROJECT:                   MFC4xx

  CPU:                       CPU-Independent

  COMPONENT:                 Lcf

  MODULNAME:                 LCFRCVVEH_common.h

  DESCRIPTION:               -

  AUTHOR:                    -

  CREATION DATE:             -

  VERSION:                   $Revision: 1.17 $


  ---*/ /*--- 
  CHANGES:                   $Log: LCFRCVVEH_common.h  $
  CHANGES:                   Revision 1.17 2021/04/14 10:39:23CEST Borza, Elena-Nicoleta (uib44190) (uib44190) 
  CHANGES:                   Update LCFCVVEH_common.h file for BD10 for issue no 1640787
  CHANGES:                   Revision 1.16 2020/02/21 12:50:25CET Craciun, Mihaela (uidl9730) (uidl9730) 
  CHANGES:                   Updates after qaf report
  CHANGES:                   Revision 1.14 2019/11/20 13:05:09CET Craciun, Mihaela (uidl9730) (uidl9730) 
  CHANGES:                   Integrate updates for weekly CP
  CHANGES:                   Revision 1.13 2019/11/04 12:11:11CET Nastasa, Elena (uidt4846) 
  CHANGES:                   Small wrappers updates
  CHANGES:                   Revision 1.11 2019/07/24 09:12:16CEST Stajilov, Victor (uidn1924) 
  CHANGES:                   Use LCF_LADMC_REQUEST (RTE define) instead of hardcoded state 6 for DMC_LAT_STATUS
  CHANGES:                   Revision 1.10 2019/06/27 10:19:09CEST Craciun, Mihaela (uidl9730) (uidl9730) 
  CHANGES:                   Fixed compiler warnings
  CHANGES:                   Revision 1.6 2019/06/05 15:32:23CEST Nastasa, Elena (uidt4846) 
  CHANGES:                   Update for Sprint 05.10.01
  CHANGES:                   Revision 1.5 2019/05/22 12:44:50CEST Nastasa, Elena (uidt4846) 
  CHANGES:                   Update LCF for Sprint10
  CHANGES:                   Revision 1.3 2019/05/06 16:33:13CEST Nastasa, Elena (uidt4846) 
  CHANGES:                   Update wrappers for new RTE
  CHANGES:                   Revision 1.2 2019/04/10 03:45:42CEST Nastasa, Elena (uidt4846) 
  CHANGES:                   Update LCF files for auxcodegen v4.0
  CHANGES:                   Revision 1.1 2019/03/24 17:37:15CET Asong, Wedndah Asaha (uidj2187) 
  CHANGES:                   Initial revision
  CHANGES:                   Member added to project /ADAS/SW/Projects/MFC431x/MFC431/DPU/04_Engineering/01_Source_Code/LCF/LCF_MFC431x/DPU/LCFRCV/project.pj
  CHANGES:                   Revision 1.1 2019/03/24 08:39:33CET Asong, Wedndah Asaha (uidj2187) 
  CHANGES:                   Initial revision
  CHANGES:                   Member added to project /ADAS/SW/Projects/MFC431x/MFC431/DPU/04_Engineering/01_Source_Code/LCF/LCF_MFC431x/DPU/LCFRCV/project.pj
  CHANGES:                   Revision 1.1 2019/02/19 13:54:32CET Asong, Wedndah Asaha (uidj2187) 
  CHANGES:                   Initial revision
  CHANGES:                   Member added to project /ADAS/SW/Components/LCF_LateralControlFunctions/04_Engineering/01_Source_Code/LCF/LCF_MFC/DPU/LCFRCV/project.pj

**************************************************************************** */

#ifndef LCFRCVVEH_COMMON_H_
#define LCFRCVVEH_COMMON_H_

/*---------------------------------------------------------*
   I N C L U D E S
**---------------------------------------------------------*/

#include "LCFERR/LCFERR_VehCustom.h"
#include "LCFERR/lcferr_veh.h"
#include "LCFERR/ERRIO_VehCustom.h"
#include "LCFERR/errio_veh.h"

/*---------------------------------------------------------*
   S T R U C T U R E S
**---------------------------------------------------------*/

typedef struct
{
	float32 T_LCFRCV_VehVelX_mps;
} LCFRCV_VehCommonOutType;

/*---------------------------------------------------------*
   F U N C T I O N   P R O T O T Y P E S
**---------------------------------------------------------*/
extern const LCFRCV_VehCommonOutType* Get_LCFRCV_VehCommonOutPtr(void);
extern void  LCFRCV_VehCommonReset  (void);
extern void  LCFRCV_VehCommonProcess(void);

/*---------------------------------------------------------*
   E X T E R N A L   V A R I A B L E S
**---------------------------------------------------------*/
extern volatile uint8 P_LCF_VEHCopyVDY2LCFParam_bool; /*Parameter to switch between VDY and LCF values*/
/*---------------------------------------------------------*
   M A C R O S
**---------------------------------------------------------*/
#ifndef LCF_IO_POS_RDWSW /* Must be deleted */
#define LCF_IO_POS_RDWSW LCF_IO_POS_NotAvailable
#endif

/* Constant cycle time if cycle time is zero */
#define TPC_CONST_CYCLE_TIME	((float32)0.020f)

/* Maximum cycle time if cycle time too high */
#define TPC_MAX_CYCLE_TIME		((float32)0.110f)

/*--------------------------------- Inputs from ABD ---------------------------------------*/
#ifndef	S_LCFRCV_PitchAngleOnline_rad
#define	S_LCFRCV_PitchAngleOnline_rad		(0.0f) /*signal not available in pAbdOutputData*/
#define GET_S_LCFRCV_PitchAngleOnline_rad()	S_LCFRCV_PitchAngleOnline_rad
#endif

/*--------------------------------- Inputs from BaseCtrlData ---------------------------------------*/
/*RO 840628*/
#ifndef	S_LCFRCV_VehSync4LCO_us
#define	S_LCFRCV_VehSync4LCO_us		(pLcfVehReqPorts->pBaseCtrlData->sSigHeader.uiTimeStamp)
#define GET_S_LCFRCV_VehSync4LCO_us()	S_LCFRCV_VehSync4LCO_us
#endif

/*------------------ Veh Generic Input(LCF_GenericInputs_t* pLcfInputData) -------------------------*/
#ifndef	S_LCFRCV_BankAngle_rad
#define	S_LCFRCV_BankAngle_rad			(pLcfVehReqPorts->pLcfInputData->BankAngle_rad)
#define GET_S_LCFRCV_BankAngle_rad()	S_LCFRCV_BankAngle_rad
#endif

#ifndef	S_LCFRCV_EPS_ManualTrqActualVal_Nm
#define	S_LCFRCV_EPS_ManualTrqActualVal_Nm			(pLcfVehReqPorts->pLcfInputData->DrvSteerWheelTrq_nm)
#define GET_S_LCFRCV_EPS_ManualTrqActualVal_Nm()	S_LCFRCV_EPS_ManualTrqActualVal_Nm
#endif

#ifndef	S_LCFRCV_TieRodLoad_N
#define	S_LCFRCV_TieRodLoad_N		(pLcfVehReqPorts->pLcfInputData->TieRodLoad_n)
#define GET_S_LCFRCV_TieRodLoad_N()	S_LCFRCV_TieRodLoad_N
#endif

#ifndef	S_LCFRCV_ActiveStCtrlESC_bool
#define	S_LCFRCV_ActiveStCtrlESC_bool			(pLcfVehReqPorts->pLcfInputData->ESC_ActiveState_nu == (uint8) LCF_ACTIVITY_CONTROLLING)
#define GET_S_LCFRCV_ActiveStCtrlESC_bool()	S_LCFRCV_ActiveStCtrlESC_bool
#endif

#ifndef	S_LCFRCV_ActiveStShutdownESC_bool
#define	S_LCFRCV_ActiveStShutdownESC_bool			((pLcfVehReqPorts->pLcfInputData->ESC_ActiveState_nu == (uint8) LCF_ACTIVITY_SHUTDOWN))
#define GET_S_LCFRCV_ActiveStShutdownESC_bool()	S_LCFRCV_ActiveStShutdownESC_bool
#endif

#ifndef	S_LCFRCV_SysStNotAvailESC_bool
#define	S_LCFRCV_SysStNotAvailESC_bool			(pLcfVehReqPorts->pLcfInputData->ESC_SystemState_nu == (uint8)LCF_SYSTEM_NOT_AVAILABLE)
#define GET_S_LCFRCV_SysStNotAvailESC_bool()	S_LCFRCV_SysStNotAvailESC_bool
#endif

#ifndef	S_LCFRCV_SysStErrorESC_bool
#define	S_LCFRCV_SysStErrorESC_bool			(pLcfVehReqPorts->pLcfInputData->ESC_SystemState_nu == (uint8)LCF_SYSTEM_ERROR)
#define GET_S_LCFRCV_SysStErrorESC_bool()	S_LCFRCV_SysStErrorESC_bool
#endif

#ifndef	S_LCFRCV_StateInValidEPS_bool
#define	S_LCFRCV_StateInValidEPS_bool		(pLcfVehReqPorts->pLcfInputData->State_nu[LCF_IO_POS_DSWT] != (uint8) LCF_IO_STATE_VALID)
#define GET_S_LCFRCV_StateInValidEPS_bool()	S_LCFRCV_StateInValidEPS_bool
#endif

#ifndef	S_LCFRCV_SteerAngleEPS_deg
#define	S_LCFRCV_SteerAngleEPS_deg			(pLcfVehReqPorts->pLcfInputData->DeltaFSteerAngle_deg)
#define GET_S_LCFRCV_SteerAngleEPS_deg()	S_LCFRCV_SteerAngleEPS_deg
#endif

#ifndef	S_LCFRCV_SteerAngleValidEPS_bool
#define	S_LCFRCV_SteerAngleValidEPS_bool		(pLcfVehReqPorts->pLcfInputData->State_nu[LCF_IO_POS_DFSA] == (uint8) LCF_IO_STATE_VALID)
#define GET_S_LCFRCV_SteerAngleValidEPS_bool()	S_LCFRCV_SteerAngleValidEPS_bool
#endif

#ifndef	S_LCFRCV_SteerAngleRateEPS_degps
#define	S_LCFRCV_SteerAngleRateEPS_degps		(pLcfVehReqPorts->pLcfInputData->DeltaFSteerAngleRate_degps)
#define GET_S_LCFRCV_SteerAngleRateEPS_degps()	S_LCFRCV_SteerAngleRateEPS_degps
#endif

#ifndef	S_LCFRCV_SteerAngleRateValidEPS_bool
#define	S_LCFRCV_SteerAngleRateValidEPS_bool		(pLcfVehReqPorts->pLcfInputData->State_nu[LCF_IO_POS_DFSAR] == (uint8) LCF_IO_STATE_VALID)
#define GET_S_LCFRCV_SteerAngleRateValidEPS_bool()	S_LCFRCV_SteerAngleRateValidEPS_bool
#endif

#ifndef	S_LCFRCV_MotorTorqueEPS_Nm
#define	S_LCFRCV_MotorTorqueEPS_Nm			(pLcfVehReqPorts->pLcfInputData->EPS_Motor_Torque_nm)
#define GET_S_LCFRCV_MotorTorqueEPS_Nm()	S_LCFRCV_MotorTorqueEPS_Nm
#endif

#ifndef	S_LCFRCV_TorqueFaultEPS_nu
#define	S_LCFRCV_TorqueFaultEPS_nu			(pLcfVehReqPorts->pLcfInputData->EPS_Toi_Flt_nu)
#define GET_S_LCFRCV_TorqueFaultEPS_nu()	S_LCFRCV_TorqueFaultEPS_nu
#endif

#ifndef	S_LCFRCV_TorqueActiveEPS_nu
#define	S_LCFRCV_TorqueActiveEPS_nu			(pLcfVehReqPorts->pLcfInputData->EPS_Toi_Active_nu)
#define GET_S_LCFRCV_TorqueActiveEPS_nu()	S_LCFRCV_TorqueActiveEPS_nu
#endif

#ifndef	S_LCFRCV_TorqueUnavailableEPS_nu
#define	S_LCFRCV_TorqueUnavailableEPS_nu		(pLcfVehReqPorts->pLcfInputData->EPS_Toi_Unavail_nu)
#define GET_S_LCFRCV_TorqueUnavailableEPS_nu()	S_LCFRCV_TorqueUnavailableEPS_nu
#endif

#ifndef	S_LCFRCV_SteerWAngleRate_degps
#define	S_LCFRCV_SteerWAngleRate_degps			((pLcfVehReqPorts->pLcfInputData->SteerHandWheelAngleRate_rps) * CONV_RAD2DEG) /* Checked, not used*/
#define GET_S_LCFRCV_SteerWAngleRate_degps()	S_LCFRCV_SteerWAngleRate_degps
#endif

#ifndef	S_LCFRCV_LDPSwitch_bool
#define S_LCFRCV_LDPSwitch_bool			(pLcfVehReqPorts->pLcfInputData->LDPSwitch_nu)  /* Checked, not used*/
#define GET_S_LCFRCV_LDPSwitch_bool()	S_LCFRCV_LDPSwitch_bool
#endif

#ifndef	S_LCFRCV_RDWSwitch_bool
#define S_LCFRCV_RDWSwitch_bool			(pLcfVehReqPorts->pLcfInputData->RDWSwitch_nu) 
#define GET_S_LCFRCV_RDWSwitch_bool()	S_LCFRCV_RDWSwitch_bool
#endif

#ifndef	S_LCFRCV_LDWSwitch_bool
#define S_LCFRCV_LDWSwitch_bool			(pLcfVehReqPorts->pLcfInputData->LDWSwitch_nu)   /* Checked*/
#define GET_S_LCFRCV_LDWSwitch_bool()	S_LCFRCV_LDWSwitch_bool
#endif
/*--------------------------------------------------------------------------------------------------*/

/*----------- Inputs from SEN to VEH(LCF_SenToVeh_t* pLcfVehInputFromSenData) ----------------------*/
#ifndef	S_LCFRCV_ActFctLevel_nu
#define S_LCFRCV_ActFctLevel_nu    	    (pLcfVehReqPorts->pLcfVehInputFromSenData->ActFctLevel_nu)
#define GET_S_LCFRCV_ActFctLevel_nu()	S_LCFRCV_ActFctLevel_nu
#endif

#ifndef	S_CSCLTA_MaxJerkAllowed_mps3
#define S_CSCLTA_MaxJerkAllowed_mps3    	    (pLcfVehReqPorts->pLcfVehInputFromSenData->MaxJerkAllowed_mps3)
#define GET_S_CSCLTA_MaxJerkAllowed_mps3()	S_CSCLTA_MaxJerkAllowed_mps3
#endif

#ifndef	S_LCFRCV_OcObjActSide_nu
#define S_LCFRCV_OcObjActSide_nu    	    (pLcfVehReqPorts->pLcfVehInputFromSenData->OcObjActSide_nu)
#define GET_S_LCFRCV_OcObjActSide_nu()   	S_LCFRCV_OcObjActSide_nu
#endif

#ifndef	S_LCFRCV_AngReqMaxLimitScale_per
#define S_LCFRCV_AngReqMaxLimitScale_per    	    (pLcfVehReqPorts->pLcfVehInputFromSenData->AngReqMaxLimitScale_per)
#define GET_S_LCFRCV_AngReqMaxLimitScale_per()   	S_LCFRCV_AngReqMaxLimitScale_per
#endif

#ifndef	S_LCFRCV_AngReqRateMaxLimitScale_per
#define S_LCFRCV_AngReqRateMaxLimitScale_per    	    (pLcfVehReqPorts->pLcfVehInputFromSenData->AngReqRateMaxLimitScale_per)
#define GET_S_LCFRCV_AngReqRateMaxLimitScale_per()   	S_LCFRCV_AngReqRateMaxLimitScale_per
#endif

#ifndef	S_HMIOC_AvailableFunction_btf
#define	S_HMIOC_AvailableFunction_btf			(pLcfVehReqPorts->pLcfVehInputFromSenData->ActFctEnabled_nu) /*Checked*/
#define	GET_S_HMIOC_AvailableFunction_btf()	   S_HMIOC_AvailableFunction_btf
#endif

#ifndef	S_HMORQG_AvailableFunction_btf
#define	S_HMORQG_AvailableFunction_btf			(pLcfVehReqPorts->pLcfVehInputFromSenData->ActFctEnabled_nu) /*Checked*/
#define	GET_S_HMORQG_AvailableFunction_btf()	S_HMORQG_AvailableFunction_btf
#endif

#ifndef	S_HMIOC_ActFctEnabled_bool
#define	S_HMIOC_ActFctEnabled_bool	  (uint8)( S_HMIOC_AvailableFunction_btf & GET_P_DRMDAE_MonitoredFunctions_btf() ) /* provide boolean for DRVMN*/
#define GET_S_HMIOC_ActFctEnabled_bool()  S_HMIOC_ActFctEnabled_bool
#endif

#ifndef	S_MCTLFC_ControllingFunction_nu
#define	S_MCTLFC_ControllingFunction_nu			(pLcfVehReqPorts->pLcfVehInputFromSenData->ControllingFunction_nu)
#define GET_S_MCTLFC_ControllingFunction_nu()	S_MCTLFC_ControllingFunction_nu
#endif

#ifndef	S_DPLSTM_SysStateLDP_nu
#define	S_DPLSTM_SysStateLDP_nu			(pLcfVehReqPorts->pLcfVehInputFromSenData->LCF_SysCoordinator.SysStateLDP_nu)
#define GET_S_DPLSTM_SysStateLDP_nu()	S_DPLSTM_SysStateLDP_nu
#endif

#ifndef	S_DPRSTM_SysStateRDP_nu
#define	S_DPRSTM_SysStateRDP_nu			(pLcfVehReqPorts->pLcfVehInputFromSenData->LCF_SysCoordinator.SysStateRDP_nu)
#define GET_S_DPRSTM_SysStateRDP_nu()	S_DPRSTM_SysStateRDP_nu
#endif

#ifndef	S_CSCLTA_SysStateLCF_enum
#define	S_CSCLTA_SysStateLCF_enum		(pLcfVehReqPorts->pLcfVehInputFromSenData->LCF_SysCoordinator.CoordSysStateLCF_nu)
#define	GET_S_CSCLTA_SysStateLCF_enum()	S_CSCLTA_SysStateLCF_enum
#endif

#ifndef	S_CSCLTA_StrWhStifLimit_nu
#define	S_CSCLTA_StrWhStifLimit_nu			(pLcfVehReqPorts->pLcfVehInputFromSenData->LCF_FCT.TrajCtrlDirect.CtrlTransitions.StrWhStifLimit_nu)
#define	GET_S_CSCLTA_StrWhStifLimit_nu()	S_CSCLTA_StrWhStifLimit_nu
#endif

#ifndef	S_CSCLTA_StrWhStifGrad_1ps
#define	S_CSCLTA_StrWhStifGrad_1ps			(pLcfVehReqPorts->pLcfVehInputFromSenData->LCF_FCT.TrajCtrlDirect.CtrlTransitions.StrWhStifGrad_1ps)
#define	GET_S_CSCLTA_StrWhStifGrad_1ps()	S_CSCLTA_StrWhStifGrad_1ps
#endif

#ifndef	S_CSCLTA_TrqRampGrad_1ps
#define	S_CSCLTA_TrqRampGrad_1ps			(pLcfVehReqPorts->pLcfVehInputFromSenData->LCF_FCT.TrajCtrlDirect.CtrlTransitions.TrqRampGrad_1ps)
#define	GET_S_CSCLTA_TrqRampGrad_1ps()	S_CSCLTA_TrqRampGrad_1ps
#endif

#ifndef	S_CSCLTA_MaxTrqScalLimit_nu
#define	S_CSCLTA_MaxTrqScalLimit_nu			(pLcfVehReqPorts->pLcfVehInputFromSenData->LCF_FCT.TrajCtrlDirect.CtrlTransitions.MaxTrqScalLimit_nu)
#define	GET_S_CSCLTA_MaxTrqScalLimit_nu()	S_CSCLTA_MaxTrqScalLimit_nu
#endif

#ifndef	S_CSCLTA_MaxTrqScalGrad_1ps
#define	S_CSCLTA_MaxTrqScalGrad_1ps			(pLcfVehReqPorts->pLcfVehInputFromSenData->LCF_FCT.TrajCtrlDirect.CtrlTransitions.MaxTrqScalGrad_1ps)
#define	GET_S_CSCLTA_MaxTrqScalGrad_1ps()	S_CSCLTA_MaxTrqScalGrad_1ps
#endif

#ifndef	S_CSCLTA_HighStatAccu_bool
#define	S_CSCLTA_HighStatAccu_bool			(pLcfVehReqPorts->pLcfVehInputFromSenData->LCF_FCT.TrajCtrlDirect.CtrlTransitions.HighStatAccu_nu)
#define	GET_S_CSCLTA_HighStatAccu_bool()	S_CSCLTA_HighStatAccu_bool
#endif

#ifndef	S_CSCLTA_GrdLimitTgtCrvTGC_1pms
#define	S_CSCLTA_GrdLimitTgtCrvTGC_1pms			(pLcfVehReqPorts->pLcfVehInputFromSenData->LCF_FCT.TrajCtrlDirect.CrvLimitation.GrdLimitTgtCrvTrajGuiCtrl_1pms)
#define GET_S_CSCLTA_GrdLimitTgtCrvTGC_1pms()	S_CSCLTA_GrdLimitTgtCrvTGC_1pms
#endif

#ifndef	S_CSCLTA_MaxCrvGrdBuildup_1pms
#define	S_CSCLTA_MaxCrvGrdBuildup_1pms			(pLcfVehReqPorts->pLcfVehInputFromSenData->LCF_FCT.TrajCtrlDirect.CrvLimitation.MaxCrvGrdBuildup_1pms)
#define GET_S_CSCLTA_MaxCrvGrdBuildup_1pms()	S_CSCLTA_MaxCrvGrdBuildup_1pms
#endif

#ifndef	S_CSCLTA_MaxCrvGrdRed_1pms
#define	S_CSCLTA_MaxCrvGrdRed_1pms		(pLcfVehReqPorts->pLcfVehInputFromSenData->LCF_FCT.TrajCtrlDirect.CrvLimitation.MaxCrvGrdReduction_1pms)
#define GET_S_CSCLTA_MaxCrvGrdRed_1pms()	S_CSCLTA_MaxCrvGrdRed_1pms
#endif

#ifndef	S_CSCLTA_MaxCrvTrajGuiCtrl_1pm
#define	S_CSCLTA_MaxCrvTrajGuiCtrl_1pm			(pLcfVehReqPorts->pLcfVehInputFromSenData->LCF_FCT.TrajCtrlDirect.CrvLimitation.MaxCrvTrajGuiCtrl_1pm)
#define GET_S_CSCLTA_MaxCrvTrajGuiCtrl_1pm()	S_CSCLTA_MaxCrvTrajGuiCtrl_1pm
#endif

#ifndef	S_CSCLTA_TgtStiffTrajGuiCtrl_nu
#define	S_CSCLTA_TgtStiffTrajGuiCtrl_nu			(pLcfVehReqPorts->pLcfVehInputFromSenData->LCF_FCT.TrajCtrlDirect.CtrlTransitions.TgtStiffTrajGuiCtrl_nu)
#define GET_S_CSCLTA_TgtStiffTrajGuiCtrl_nu()	S_CSCLTA_TgtStiffTrajGuiCtrl_nu
#endif

#ifndef	S_CSCLTA_LimiterActivated_nu
#define	S_CSCLTA_LimiterActivated_nu		(pLcfVehReqPorts->pLcfVehInputFromSenData->LCF_FCT.TrajCtrlLimiter.LimiterActivated_nu)
#define GET_S_CSCLTA_LimiterActivated_nu()	S_CSCLTA_LimiterActivated_nu
#endif

#ifndef	S_CSCLTA_LimiterTimeDuration_sec
#define	S_CSCLTA_LimiterTimeDuration_sec		(pLcfVehReqPorts->pLcfVehInputFromSenData->LCF_FCT.TrajCtrlLimiter.LimiterTimeDuration_s)
#define GET_S_CSCLTA_LimiterTimeDuration_sec()	S_CSCLTA_LimiterTimeDuration_sec
#endif

#ifndef	S_CSCLTA_LeCridrBndCrvChng_1pm2
#define	S_CSCLTA_LeCridrBndCrvChng_1pm2			(pLcfVehReqPorts->pLcfVehInputFromSenData->LCF_FCT.AllCorridors.LeftCorridor.CorridorChngOfCrv_1pm2)
#define GET_S_CSCLTA_LeCridrBndCrvChng_1pm2()	S_CSCLTA_LeCridrBndCrvChng_1pm2
#endif

#ifndef	S_CSCLTA_LeCridrBndCrv_1pm
#define	S_CSCLTA_LeCridrBndCrv_1pm		(pLcfVehReqPorts->pLcfVehInputFromSenData->LCF_FCT.AllCorridors.LeftCorridor.CorridorCrv_1pm)
#define GET_S_CSCLTA_LeCridrBndCrv_1pm()	S_CSCLTA_LeCridrBndCrv_1pm
#endif

#ifndef	S_CSCLTA_LeCridrBndHeadAng_rad
#define	S_CSCLTA_LeCridrBndHeadAng_rad		(pLcfVehReqPorts->pLcfVehInputFromSenData->LCF_FCT.AllCorridors.LeftCorridor.CorridorHeading_rad)
#define GET_S_CSCLTA_LeCridrBndHeadAng_rad()	S_CSCLTA_LeCridrBndHeadAng_rad
#endif

#ifndef	S_CSCLTA_LeCridrBndLength_met
#define	S_CSCLTA_LeCridrBndLength_met			(pLcfVehReqPorts->pLcfVehInputFromSenData->LCF_FCT.AllCorridors.LeftCorridor.CorridorLength_m)
#define GET_S_CSCLTA_LeCridrBndLength_met()	S_CSCLTA_LeCridrBndLength_met
#endif

#ifndef	S_CSCLTA_LeCridrBndPosX0_met
#define	S_CSCLTA_LeCridrBndPosX0_met			(pLcfVehReqPorts->pLcfVehInputFromSenData->LCF_FCT.AllCorridors.LeftCorridor.CorridorPosX0_m)
#define GET_S_CSCLTA_LeCridrBndPosX0_met()	S_CSCLTA_LeCridrBndPosX0_met
#endif

#ifndef	S_CSCLTA_LeCridrBndPosY0_met
#define	S_CSCLTA_LeCridrBndPosY0_met			(pLcfVehReqPorts->pLcfVehInputFromSenData->LCF_FCT.AllCorridors.LeftCorridor.CorridorPosY0_m)
#define GET_S_CSCLTA_LeCridrBndPosY0_met()	S_CSCLTA_LeCridrBndPosY0_met
#endif

#ifndef	S_CSCLTA_RiCridrBndCrvChng_1pm2
#define	S_CSCLTA_RiCridrBndCrvChng_1pm2		(pLcfVehReqPorts->pLcfVehInputFromSenData->LCF_FCT.AllCorridors.RightCorridor.CorridorChngOfCrv_1pm2)
#define GET_S_CSCLTA_RiCridrBndCrvChng_1pm2()	S_CSCLTA_RiCridrBndCrvChng_1pm2
#endif

#ifndef	S_CSCLTA_RiCridrBndCrv_1pm
#define	S_CSCLTA_RiCridrBndCrv_1pm			(pLcfVehReqPorts->pLcfVehInputFromSenData->LCF_FCT.AllCorridors.RightCorridor.CorridorCrv_1pm)
#define GET_S_CSCLTA_RiCridrBndCrv_1pm()	S_CSCLTA_RiCridrBndCrv_1pm
#endif

#ifndef	S_CSCLTA_RiCridrBndHeadAng_rad
#define	S_CSCLTA_RiCridrBndHeadAng_rad			(pLcfVehReqPorts->pLcfVehInputFromSenData->LCF_FCT.AllCorridors.RightCorridor.CorridorHeading_rad)
#define GET_S_CSCLTA_RiCridrBndHeadAng_rad()	S_CSCLTA_RiCridrBndHeadAng_rad
#endif

#ifndef	S_CSCLTA_RiCridrBndLength_met
#define	S_CSCLTA_RiCridrBndLength_met		(pLcfVehReqPorts->pLcfVehInputFromSenData->LCF_FCT.AllCorridors.RightCorridor.CorridorLength_m)
#define GET_S_CSCLTA_RiCridrBndLength_met()	S_CSCLTA_RiCridrBndLength_met
#endif

#ifndef	S_CSCLTA_RiCridrBndPosX0_met
#define	S_CSCLTA_RiCridrBndPosX0_met		(pLcfVehReqPorts->pLcfVehInputFromSenData->LCF_FCT.AllCorridors.RightCorridor.CorridorPosX0_m)
#define GET_S_CSCLTA_RiCridrBndPosX0_met()	S_CSCLTA_RiCridrBndPosX0_met
#endif

#ifndef	S_CSCLTA_RiCridrBndPosY0_met
#define	S_CSCLTA_RiCridrBndPosY0_met		(pLcfVehReqPorts->pLcfVehInputFromSenData->LCF_FCT.AllCorridors.RightCorridor.CorridorPosY0_m)
#define GET_S_CSCLTA_RiCridrBndPosY0_met()	S_CSCLTA_RiCridrBndPosY0_met
#endif

#ifndef	S_CSCLTA_TgtTrajCrvChng_1pm2
#define	S_CSCLTA_TgtTrajCrvChng_1pm2		(pLcfVehReqPorts->pLcfVehInputFromSenData->LCF_FCT.AllCorridors.TargetCorridor.CorridorChngOfCrv_1pm2)
#define GET_S_CSCLTA_TgtTrajCrvChng_1pm2()	S_CSCLTA_TgtTrajCrvChng_1pm2
#endif

#ifndef	S_CSCLTA_TgtTrajCrv_1pm
#define	S_CSCLTA_TgtTrajCrv_1pm			(pLcfVehReqPorts->pLcfVehInputFromSenData->LCF_FCT.AllCorridors.TargetCorridor.CorridorCrv_1pm)
#define GET_S_CSCLTA_TgtTrajCrv_1pm()	S_CSCLTA_TgtTrajCrv_1pm
#endif

#ifndef	S_CSCLTA_TgtTrajHeadAng_rad
#define	S_CSCLTA_TgtTrajHeadAng_rad			(pLcfVehReqPorts->pLcfVehInputFromSenData->LCF_FCT.AllCorridors.TargetCorridor.CorridorHeading_rad)
#define GET_S_CSCLTA_TgtTrajHeadAng_rad()	S_CSCLTA_TgtTrajHeadAng_rad
#endif

#ifndef	S_CSCLTA_TgtTrajLength_met
#define	S_CSCLTA_TgtTrajLength_met		(pLcfVehReqPorts->pLcfVehInputFromSenData->LCF_FCT.AllCorridors.TargetCorridor.CorridorLength_m)
#define GET_S_CSCLTA_TgtTrajLength_met()	S_CSCLTA_TgtTrajLength_met
#endif

#ifndef	S_CSCLTA_TgtTrajPosX0_met
#define	S_CSCLTA_TgtTrajPosX0_met		(pLcfVehReqPorts->pLcfVehInputFromSenData->LCF_FCT.AllCorridors.TargetCorridor.CorridorPosX0_m)
#define GET_S_CSCLTA_TgtTrajPosX0_met()	S_CSCLTA_TgtTrajPosX0_met
#endif

#ifndef	S_CSCLTA_TgtTrajPosY0_met
#define	S_CSCLTA_TgtTrajPosY0_met		(pLcfVehReqPorts->pLcfVehInputFromSenData->LCF_FCT.AllCorridors.TargetCorridor.CorridorPosY0_m)
#define GET_S_CSCLTA_TgtTrajPosY0_met()	S_CSCLTA_TgtTrajPosY0_met
#endif

#ifndef	S_CSCLTA_LatencyCompActivated_nu
#define	S_CSCLTA_LatencyCompActivated_nu		(pLcfVehReqPorts->pLcfVehInputFromSenData->LCF_FCT.LtcyComp.LtcyCompActivated_nu)
#define GET_S_CSCLTA_LatencyCompActivated_nu()	S_CSCLTA_LatencyCompActivated_nu
#endif

#ifndef	S_CSCLTA_SensorTStamp_sec
#define	S_CSCLTA_SensorTStamp_sec			(pLcfVehReqPorts->pLcfVehInputFromSenData->LCF_FCT.LtcyComp.TimeStamp_s)
#define GET_S_CSCLTA_SensorTStamp_sec()	S_CSCLTA_SensorTStamp_sec
#endif

#ifndef	S_CSCLTA_PlanningHorizon_sec
#define	S_CSCLTA_PlanningHorizon_sec		(pLcfVehReqPorts->pLcfVehInputFromSenData->LCF_FCT.TrajCalc.PlanningHorizon_s)
#define GET_S_CSCLTA_PlanningHorizon_sec()	S_CSCLTA_PlanningHorizon_sec
#endif

#ifndef	S_CSCLTA_PredictionTimeCrv_sec
#define	S_CSCLTA_PredictionTimeCrv_sec			(pLcfVehReqPorts->pLcfVehInputFromSenData->LCF_FCT.TrajCalc.PredictionTimeCrv_s)
#define GET_S_CSCLTA_PredictionTimeCrv_sec()	S_CSCLTA_PredictionTimeCrv_sec
#endif

#ifndef	S_CSCLTA_PredTimeHeadAng_sec
#define	S_CSCLTA_PredTimeHeadAng_sec			(pLcfVehReqPorts->pLcfVehInputFromSenData->LCF_FCT.TrajCalc.PredictionTimeHeading_s)
#define GET_S_CSCLTA_PredTimeHeadAng_sec()	S_CSCLTA_PredTimeHeadAng_sec
#endif

#ifndef	S_CSCLTA_TrajGuiQualifier_nu
#define	S_CSCLTA_TrajGuiQualifier_nu		(pLcfVehReqPorts->pLcfVehInputFromSenData->LCF_FCT.TrajCalc.TrajGuiQualifier_nu)
#define GET_S_CSCLTA_TrajGuiQualifier_nu()	S_CSCLTA_TrajGuiQualifier_nu
#endif

#ifndef	S_CSCLTA_TriggerReplan_nu
#define	S_CSCLTA_TriggerReplan_nu		(pLcfVehReqPorts->pLcfVehInputFromSenData->LCF_FCT.TrajCalc.TriggerReplan_nu)
#define GET_S_CSCLTA_TriggerReplan_nu()	S_CSCLTA_TriggerReplan_nu
#endif

#ifndef	S_CSCLTA_FTireAclMax_mps2
#define	S_CSCLTA_FTireAclMax_mps2		(pLcfVehReqPorts->pLcfVehInputFromSenData->LCF_FCT.TrajOptimization.FTireAclMax_mps2)
#define GET_S_CSCLTA_FTireAclMax_mps2()	S_CSCLTA_FTireAclMax_mps2
#endif

#ifndef	S_CSCLTA_FTireAclMin_mps2
#define	S_CSCLTA_FTireAclMin_mps2		(pLcfVehReqPorts->pLcfVehInputFromSenData->LCF_FCT.TrajOptimization.FTireAclMin_mps2)
#define GET_S_CSCLTA_FTireAclMin_mps2()	S_CSCLTA_FTireAclMin_mps2
#endif

#ifndef	S_CSCLTA_TrajPlanServQu_nu
#define	S_CSCLTA_TrajPlanServQu_nu			(pLcfVehReqPorts->pLcfVehInputFromSenData->LCF_FCT.TrajOptimization.TrajServiceQualifier_nu)
#define GET_S_CSCLTA_TrajPlanServQu_nu()	S_CSCLTA_TrajPlanServQu_nu
#endif

#ifndef	S_CSCLTA_WeightEndTime_nu
#define	S_CSCLTA_WeightEndTime_nu		(pLcfVehReqPorts->pLcfVehInputFromSenData->LCF_FCT.TrajOptimization.WeightEndTime_nu)
#define GET_S_CSCLTA_WeightEndTime_nu()	S_CSCLTA_WeightEndTime_nu
#endif

#ifndef	S_CSCLTA_WeightTgtDistY_nu
#define	S_CSCLTA_WeightTgtDistY_nu			(pLcfVehReqPorts->pLcfVehInputFromSenData->LCF_FCT.TrajOptimization.WeightTgtDistY_nu)
#define GET_S_CSCLTA_WeightTgtDistY_nu()	S_CSCLTA_WeightTgtDistY_nu
#endif

#ifndef	S_CSCLTA_ObstacleAclX_mps2
#define	S_CSCLTA_ObstacleAclX_mps2		(pLcfVehReqPorts->pLcfVehInputFromSenData->LCF_FCT.Obstacle.Obstacle_AclX_mps2)
#define	GET_S_CSCLTA_ObstacleAclX_mps2()	S_CSCLTA_ObstacleAclX_mps2
#endif

#ifndef	S_CSCLTA_ObstacleVelX_mps
#define	S_CSCLTA_ObstacleVelX_mps		(pLcfVehReqPorts->pLcfVehInputFromSenData->LCF_FCT.Obstacle.Obstacle_VelX_mps)
#define	GET_S_CSCLTA_ObstacleVelX_mps()	S_CSCLTA_ObstacleVelX_mps
#endif

#ifndef	S_CSCLTA_ObstacleDistX_met
#define	S_CSCLTA_ObstacleDistX_met			(pLcfVehReqPorts->pLcfVehInputFromSenData->LCF_FCT.Obstacle.Obstacle_DistX_m)
#define	GET_S_CSCLTA_ObstacleDistX_met()	S_CSCLTA_ObstacleDistX_met
#endif

#ifndef	S_CSCLTA_ObstacleDistY_met
#define	S_CSCLTA_ObstacleDistY_met			(pLcfVehReqPorts->pLcfVehInputFromSenData->LCF_FCT.Obstacle.Obstacle_DistY_m)
#define	GET_S_CSCLTA_ObstacleDistY_met()	S_CSCLTA_ObstacleDistY_met
#endif

#ifndef	S_CSCLTA_ObstacleWidth_met
#define	S_CSCLTA_ObstacleWidth_met			(pLcfVehReqPorts->pLcfVehInputFromSenData->LCF_FCT.Obstacle.Obstacle_Width_m)
#define	GET_S_CSCLTA_ObstacleWidth_met()	S_CSCLTA_ObstacleWidth_met
#endif

#ifndef	S_CSCLTA_DistYTolLeTgtArea_met
#define	S_CSCLTA_DistYTolLeTgtArea_met		(pLcfVehReqPorts->pLcfVehInputFromSenData->LCF_FCT.TrajOptimization.DistYToleranceLeftTgtArea_m)
#define	GET_S_CSCLTA_DistYTolLeTgtArea_met()	S_CSCLTA_DistYTolLeTgtArea_met
#endif

#ifndef	S_CSCLTA_DistYTolRiTgtArea_met
#define	S_CSCLTA_DistYTolRiTgtArea_met		(pLcfVehReqPorts->pLcfVehInputFromSenData->LCF_FCT.TrajOptimization.DistYToleranceRightTgtArea_m)
#define	GET_S_CSCLTA_DistYTolRiTgtArea_met()	S_CSCLTA_DistYTolRiTgtArea_met
#endif

/*RO 891132 Function shall define the driver override capability*/
#ifndef	S_CSCLTA_DeratingLevel_nu
#define	S_CSCLTA_DeratingLevel_nu		(pLcfVehReqPorts->pLcfVehInputFromSenData->LCF_FCT.TrajCtrlDirect.CtrlTransitions.DeratingLevel_nu)
#define	GET_S_CSCLTA_DeratingLevel_nu()	S_CSCLTA_DeratingLevel_nu
#endif

#ifndef	S_TJAOBS_OffScenarioInvalid_btf
#define	S_TJAOBS_OffScenarioInvalid_btf		(0u) /*MiCr set to 0 because TJAOBS is not used any more in the projects*/
#define	GET_S_TJAOBS_OffScenarioInvalid_btf()	S_TJAOBS_OffScenarioInvalid_btf
#endif

#ifndef	S_ABPLBP_CntrLnClthCrv_1pm
#define	S_ABPLBP_CntrLnClthCrv_1pm			(pLcfVehReqPorts->pLcfVehInputFromSenData->ABP_CamRawData.ABP_CamCorridorCurvature_1pm)
#define	GET_S_ABPLBP_CntrLnClthCrv_1pm()	S_ABPLBP_CntrLnClthCrv_1pm
#endif

#ifndef	S_ABPLBP_CntrLnClthPosY0_met
#define	S_ABPLBP_CntrLnClthPosY0_met		(pLcfVehReqPorts->pLcfVehInputFromSenData->ABP_CamRawData.ABP_CamLateralError_m)
#define	GET_S_ABPLBP_CntrLnClthPosY0_met()	S_ABPLBP_CntrLnClthPosY0_met
#endif

#ifndef	S_ABPLBP_CntrLnClthHeading_rad
#define	S_ABPLBP_CntrLnClthHeading_rad			(pLcfVehReqPorts->pLcfVehInputFromSenData->ABP_CamRawData.ABP_CamHeadingError_rad)
#define	GET_S_ABPLBP_CntrLnClthHeading_rad()	S_ABPLBP_CntrLnClthHeading_rad
#endif

#ifndef	S_TJATVG_CrvAmplActivated_nu
#define	S_TJATVG_CrvAmplActivated_nu		(pLcfVehReqPorts->pLcfVehInputFromSenData->LCF_FCT.CrvAmp.CrvAmplificationActivated_nu)
#define GET_S_TJATVG_CrvAmplActivated_nu()	S_TJATVG_CrvAmplActivated_nu
#endif

#ifndef	S_TJATVG_LimiterType_nu
#define	S_TJATVG_LimiterType_nu			(pLcfVehReqPorts->pLcfVehInputFromSenData->LCF_FCT.TrajCtrlLimiter.LimiterType_nu)
#define GET_S_TJATVG_LimiterType_nu()	S_TJATVG_LimiterType_nu
#endif

#ifndef	S_LCFRCV_EvntDtctnSenEvID_nu
#define	S_LCFRCV_EvntDtctnSenEvID_nu(i)		(pLcfVehReqPorts->pLcfVehInputFromSenData->EvntDtctnSenEvents_nu[i].EventId_nu)
#define	GET_S_LCFRCV_EvntDtctnSenEvID_nu(i)	S_LCFRCV_EvntDtctnSenEvID_nu(i)
#endif

#ifndef	S_LCFRCV_EvntDtctnSenEvLifeTime_nu
#define	S_LCFRCV_EvntDtctnSenEvLifeTime_nu(i)		(pLcfVehReqPorts->pLcfVehInputFromSenData->EvntDtctnSenEvents_nu[i].EventLifetime_nu)
#define	GET_S_LCFRCV_EvntDtctnSenEvLifeTime_nu(i)	S_LCFRCV_EvntDtctnSenEvLifeTime_nu(i)
#endif

#ifndef	S_ABPLBP_RiLnQuality_perc
#define	S_ABPLBP_RiLnQuality_perc		(pLcfVehReqPorts->pLcfVehInputFromSenData->EvntDtctnSenEvents_nu[0].EventId_nu)
#define	GET_S_ABPLBP_RiLnQuality_perc()	        S_ABPLBP_RiLnQuality_perc
#endif

#ifndef	S_ABPLBP_LeLnQuality_perc
#define	S_ABPLBP_LeLnQuality_perc		(pLcfVehReqPorts->pLcfVehInputFromSenData->EvntDtctnSenEvents_nu[1].EventId_nu)
#define	GET_S_ABPLBP_LeLnQuality_perc()	        S_ABPLBP_LeLnQuality_perc
#endif

#ifndef	S_ABPLBP_RiCrvQuality_perc
#define	S_ABPLBP_RiCrvQuality_perc		(pLcfVehReqPorts->pLcfVehInputFromSenData->EvntDtctnSenEvents_nu[0].EventLifetime_nu)
#define	GET_S_ABPLBP_RiCrvQuality_perc()	    S_ABPLBP_RiCrvQuality_perc
#endif

#ifndef	S_ABPLBP_LeCrvQuality_perc
#define	S_ABPLBP_LeCrvQuality_perc		(pLcfVehReqPorts->pLcfVehInputFromSenData->EvntDtctnSenEvents_nu[1].EventLifetime_nu)
#define	GET_S_ABPLBP_LeCrvQuality_perc()	     S_ABPLBP_LeCrvQuality_perc
#endif 

#ifndef	S_TJASTM_SysStateLKA_nu
#define	S_TJASTM_SysStateLKA_nu		(pLcfVehReqPorts->pLcfVehInputFromSenData->LCF_SysCoordinator.SysStateLKA_nu)
#define	GET_S_TJASTM_SysStateLKA_nu()	S_TJASTM_SysStateLKA_nu
#endif    
   
#ifndef	S_TJASTM_SysStateTJA_nu
#define	S_TJASTM_SysStateTJA_nu		(pLcfVehReqPorts->pLcfVehInputFromSenData->LCF_SysCoordinator.SysStateTJA_nu)
#define	GET_S_TJASTM_SysStateTJA_nu()	S_TJASTM_SysStateTJA_nu
#endif    
 
#ifndef	S_TJASTM_LatCtrlMode_nu
#define	S_TJASTM_LatCtrlMode_nu		    (pLcfVehReqPorts->pLcfVehInputFromSenData->Reserved1_nu)  /* map reserved bit to send GET_S_TJASTM_LatCtrlMode_nu to VEH*/
#define	GET_S_TJASTM_LatCtrlMode_nu()	 S_TJASTM_LatCtrlMode_nu
#endif

/*GeGr: New signal for TRJPLN*/
#ifndef	S_LCFRCV_SenToVehTStamp_us
#define	S_LCFRCV_SenToVehTStamp_us			(pLcfVehReqPorts->pLcfVehInputFromSenData->sSigHeader.uiTimeStamp)
#define	GET_S_LCFRCV_SenToVehTStamp_us()	S_LCFRCV_SenToVehTStamp_us
#endif

#ifndef	S_LCFRCV_LatCtrlModeTJA_nu
#define	S_LCFRCV_LatCtrlModeTJA_nu			(pLcfVehReqPorts->pLcfVehInputFromSenData->LCF_SysCoordinator.LatCtrlModeTJA_nu)
#define	GET_S_LCFRCV_LatCtrlModeTJA_nu()	S_LCFRCV_LatCtrlModeTJA_nu
#endif

#ifndef	S_ABPLBP_StraightPathDtct_nu
#define	S_ABPLBP_StraightPathDtct_nu			(pLcfVehReqPorts->pLcfVehInputFromSenData->StraightPathDtct_nu)
#define	GET_S_ABPLBP_StraightPathDtct_nu()	S_ABPLBP_StraightPathDtct_nu
#endif
/*------------------------------------------------------------------------------------------------*/

/*------- Input from SEN Generic outputs(LCF_SenGenericOutputs_t* pLcfSenOutputData)--------------*/
#ifndef	S_LCFRCV_LaneStatusLaKMC_st
#define	S_LCFRCV_LaneStatusLaKMC_st			(pLcfVehReqPorts->pLcfSenOutputData->LaKMC_lane_status_nu)
#define GET_S_LCFRCV_LaneStatusLaKMC_st()	S_LCFRCV_LaneStatusLaKMC_st
#endif

#ifndef	S_LCFRCV_LdwsLHWarning_bool
#define	S_LCFRCV_LdwsLHWarning_bool			(pLcfVehReqPorts->pLcfSenOutputData->Lkas_LdwsLHWarning_nu)
#define GET_S_LCFRCV_LdwsLHWarning_bool()	S_LCFRCV_LdwsLHWarning_bool
#endif

#ifndef	S_LCFRCV_LdwsRHWarning_bool
#define	S_LCFRCV_LdwsRHWarning_bool			(pLcfVehReqPorts->pLcfSenOutputData->Lkas_LdwsRHWarning_nu)
#define GET_S_LCFRCV_LdwsRHWarning_bool()	S_LCFRCV_LdwsRHWarning_bool
#endif

#ifndef	S_LCFRCV_LaneValidQualifier_bool	
#define S_LCFRCV_LaneValidQualifier_bool	(pLcfVehReqPorts->pLcfSenOutputData->LaneValidQualDMC_nu != 0u)
#define GET_S_LCFRCV_LaneValidQualifier_bool()	S_LCFRCV_LaneValidQualifier_bool
#endif
/*------------------------------------------------------------------------------------------------*/

/*-------------------- Input from Vehicle dynamic(VehDyn_t* pVehDyn) -----------------------------*/
#ifndef	S_LCFRCV_VehVelX_mps
#define	S_LCFRCV_VehVelX_mps		(Get_LCFRCV_VehCommonOutPtr()->T_LCFRCV_VehVelX_mps)
#define GET_S_LCFRCV_VehVelX_mps()	S_LCFRCV_VehVelX_mps
#endif

#ifndef	S_LCFRCV_VehAclX_mps2
#define	S_LCFRCV_VehAclX_mps2		(pLcfVehReqPorts->pVehDyn->Longitudinal.Accel)
#define GET_S_LCFRCV_VehAclX_mps2()	S_LCFRCV_VehAclX_mps2
#endif

#ifndef	S_LCFRCV_VehAclY_mps2
#define	S_LCFRCV_VehAclY_mps2		(pLcfVehReqPorts->pVehDyn->Lateral.Accel.LatAccel)
#define GET_S_LCFRCV_VehAclY_mps2()	S_LCFRCV_VehAclY_mps2
#endif

#ifndef	S_LCFRCV_VehCrv_1pm
#define	S_LCFRCV_VehCrv_1pm			(pLcfVehReqPorts->pVehDyn->Lateral.Curve.Curve)
#define GET_S_LCFRCV_VehCrv_1pm()	S_LCFRCV_VehCrv_1pm
#endif

#ifndef	S_LCFRCV_VehOdoState_nu
#define	S_LCFRCV_VehOdoState_nu			(pLcfVehReqPorts->pVehDyn->sSigHeader.eSigStatus == AL_SIG_STATE_OK) /*correct mapping*/
#define GET_S_LCFRCV_VehOdoState_nu()	S_LCFRCV_VehOdoState_nu
#endif

#ifndef	S_LCFRCV_VehStopped_nu
#define S_LCFRCV_VehStopped_nu          (pLcfVehReqPorts->pVehDyn->MotionState.MotState == VDY_LONG_MOT_STATE_STDST) /*correct mapping*/
#define GET_S_LCFRCV_VehStopped_nu()	S_LCFRCV_VehStopped_nu
#endif

#ifndef	S_LCFRCV_VehMotionState_enum
#define S_LCFRCV_VehMotionState_enum    (pLcfVehReqPorts->pVehDyn->MotionState.MotState)  /*correct mapping*/
#define GET_S_LCFRCV_VehMotionState_enum()	S_LCFRCV_VehMotionState_enum
#endif

#ifndef	S_LCFRCV_VehSync_us
#define	S_LCFRCV_VehSync_us			(pLcfVehReqPorts->pVehDyn->sSigHeader.uiTimeStamp)
#define GET_S_LCFRCV_VehSync_us()	S_LCFRCV_VehSync_us
#endif

#ifndef	S_LCFRCV_VehYawRate_rps
#define	S_LCFRCV_VehYawRate_rps			(pLcfVehReqPorts->pVehDyn->Lateral.YawRate.YawRate)
#define GET_S_LCFRCV_VehYawRate_rps()	S_LCFRCV_VehYawRate_rps
#endif

#ifndef	S_LCFRCV_OffCompStWheelAngle_rad
#define	S_LCFRCV_OffCompStWheelAngle_rad		(pLcfVehReqPorts->pVehDyn->Lateral.OffCompStWheelAngle)
#define GET_S_LCFRCV_OffCompStWheelAngle_rad()	S_LCFRCV_OffCompStWheelAngle_rad
#endif

/*RO 955654 New VDY RTE outputs*/
#ifndef	S_LCFRCV_RoadBankAngle_rad
#define S_LCFRCV_RoadBankAngle_rad		(pLcfVehReqPorts->pVehDyn->Lateral.SelfSteering.RoadBankAngle)
#define GET_S_LCFRCV_RoadBankAngle_rad()	S_LCFRCV_RoadBankAngle_rad
#endif
/*RO 955654 New VDY RTE outputs*/
#ifndef	S_LCFRCV_QuRoadBankAngle_nu
#define S_LCFRCV_QuRoadBankAngle_nu		(pLcfVehReqPorts->pVehDyn->Lateral.SelfSteering.QuRoadBankAngle)
#define GET_S_LCFRCV_QuRoadBankAngle_nu()	S_LCFRCV_QuRoadBankAngle_nu
#endif
/*RO 955654 New VDY RTE outputs*/
#ifndef	S_LCFRCV_SelfSteerGradEst_rads2pm
#define S_LCFRCV_SelfSteerGradEst_rads2pm		(pLcfVehReqPorts->pVehDyn->Lateral.SelfSteering.SelfSteerGradEst)
#define GET_S_LCFRCV_SelfSteerGradEst_rads2pm()	S_LCFRCV_SelfSteerGradEst_rads2pm
#endif
/*RO 955654 New VDY RTE outputs*/
#ifndef	S_LCFRCV_QuSelfSteerGradEst_nu
#define S_LCFRCV_QuSelfSteerGradEst_nu		(pLcfVehReqPorts->pVehDyn->Lateral.SelfSteering.QuSelfSteerGradEst)
#define GET_S_LCFRCV_QuSelfSteerGradEst_nu()	S_LCFRCV_QuSelfSteerGradEst_nu
#endif
/*------------------------------------------------------------------------------------------------*/


/*--------------------- Input from Main Vehicle dynamics(VehSig_t* pVehSig) ----------------------*/
#ifndef	S_LCFRCV_EgoYawRate_rps
#define	S_LCFRCV_EgoYawRate_rps			(pLcfVehReqPorts->pVehSig->VehSigMain.YawRate)
#define GET_S_LCFRCV_EgoYawRate_rps()	S_LCFRCV_EgoYawRate_rps
#endif

#ifndef	S_LCFRCV_SteeringAngleFrontAxleEff_rad
#define	S_LCFRCV_SteeringAngleFrontAxleEff_rad			(pLcfVehReqPorts->pVehSig->VehSigAdd.RoadWhlAngFr)	/* VDY: Not Available*/
#define GET_S_LCFRCV_SteeringAngleFrontAxleEff_rad()	S_LCFRCV_SteeringAngleFrontAxleEff_rad
#endif

#ifndef	S_LCFRCV_EgoYawRateValid_bool
#define	S_LCFRCV_EgoYawRateValid_bool		(pLcfVehReqPorts->pVehSig->VehSigMain.State[VDY_SIN_POS_YWR] == (uint8)VDY_IO_STATE_VALID)
#define GET_S_LCFRCV_EgoYawRateValid_bool()	S_LCFRCV_EgoYawRateValid_bool
#endif

#ifndef	S_LCFRCV_EgoAclY_mps2
#define	S_LCFRCV_EgoAclY_mps2		(pLcfVehReqPorts->pVehSig->VehSigMain.LatAccel)
#define GET_S_LCFRCV_EgoAclY_mps2()	S_LCFRCV_EgoAclY_mps2
#endif

#ifndef	S_LCFRCV_EgoAclYValid_bool
#define	S_LCFRCV_EgoAclYValid_bool			(pLcfVehReqPorts->pVehSig->VehSigMain.State[VDY_SIN_POS_LATA] == (uint8)VDY_IO_STATE_VALID)
#define GET_S_LCFRCV_EgoAclYValid_bool()	S_LCFRCV_EgoAclYValid_bool
#endif
/*------------------------------------------------------------------------------------------------*/

/*----------------- Input offsets from the VDY(VDYOffsets_t* pVdyOffsets) ------------------------*/
#ifndef	S_LCFRCV_EgoYawRateOffset_rps
#define	S_LCFRCV_EgoYawRateOffset_rps		(pLcfVehReqPorts->pVdyOffsets->Ywr.DynOffset)
#define GET_S_LCFRCV_EgoYawRateOffset_rps()	S_LCFRCV_EgoYawRateOffset_rps
#endif

#ifndef	S_LCFRCV_EgoYawRateState_st
#define	S_LCFRCV_EgoYawRateState_st			(pLcfVehReqPorts->pVdyOffsets->Ywr.StandStillState)
#define GET_S_LCFRCV_EgoYawRateState_st()	S_LCFRCV_EgoYawRateState_st
#endif

#ifndef	S_LCFRCV_SteeringAngleOffset_rad
#define	S_LCFRCV_SteeringAngleOffset_rad			(pLcfVehReqPorts->pVdyOffsets->Swa.Offset)
#define GET_S_LCFRCV_SteeringAngleOffset_rad()	S_LCFRCV_SteeringAngleOffset_rad
#endif

#ifndef	S_LCFRCV_SteeringAngleState_rad
#define	S_LCFRCV_SteeringAngleState_rad			(pLcfVehReqPorts->pVdyOffsets->Swa.State)
#define GET_S_LCFRCV_SteeringAngleState_rad()	S_LCFRCV_SteeringAngleState_rad
#endif

/*----------------- Inputs from IuC to VEH(LCF_LaDmcIucToSoc_t* pLcfLaDmcIucToSoc) -------------------*/
#if defined(LCF_IUC_USED) && (LCF_IUC_USED == 1)

#ifndef	S_LCFRCV_Eps_Torque_Request_nm
#define	S_LCFRCV_Eps_Torque_Request_nm	(pLcfVehReqPorts->pLcfLaDmcIucToSoc->SAC_Eps_Torque_Request_nm)
#define GET_S_LCFRCV_Eps_Torque_Request_nm()	S_LCFRCV_Eps_Torque_Request_nm
#endif

#ifndef	S_LCFRCV_LatDMCTrqRequest_bool
#define	S_LCFRCV_LatDMCTrqRequest_bool	(pLcfVehReqPorts->pLcfLaDmcIucToSoc->SAC_Eps_Request_Flag_nu)
#define GET_S_LCFRCV_LatDMCTrqRequest_bool()	S_LCFRCV_LatDMCTrqRequest_bool
#endif

#ifndef	S_LCFRCV_Dmc_Status_nu
#define	S_LCFRCV_Dmc_Status_nu			(pLcfVehReqPorts->pLcfLaDmcIucToSoc->SAC_Dmc_Status_nu)
#define GET_S_LCFRCV_Dmc_Status_nu()	S_LCFRCV_Dmc_Status_nu
#endif

#ifndef	S_LCFRCV_EvntDtctnIucEvID_nu
#define	S_LCFRCV_EvntDtctnIucEvID_nu(i)		(pLcfVehReqPorts->pLcfLaDmcIucToSoc->EvntDtctnIucEvents_nu[i].EventId_nu)
#define	GET_S_LCFRCV_EvntDtctnIucEvID_nu(i)	S_LCFRCV_EvntDtctnIucEvID_nu(i)
#endif

#ifndef	S_LCFRCV_EvntDtctnIucEvLifeTime_nu
#define	S_LCFRCV_EvntDtctnIucEvLifeTime_nu(i)		(pLcfVehReqPorts->pLcfLaDmcIucToSoc->EvntDtctnIucEvents_nu[i].EventLifetime_nu)
#define	GET_S_LCFRCV_EvntDtctnIucEvLifeTime_nu(i)	S_LCFRCV_EvntDtctnIucEvLifeTime_nu(i)
#endif

#else
#ifndef	S_LCFRCV_Eps_Torque_Request_nm
#define	S_LCFRCV_Eps_Torque_Request_nm	        (0u)
#define GET_S_LCFRCV_Eps_Torque_Request_nm()	S_LCFRCV_Eps_Torque_Request_nm
#endif

#ifndef	S_LCFRCV_LatDMCTrqRequest_bool
#define	S_LCFRCV_LatDMCTrqRequest_bool	        (0u)
#define GET_S_LCFRCV_LatDMCTrqRequest_bool()	S_LCFRCV_LatDMCTrqRequest_bool
#endif

#ifndef	S_LCFRCV_Dmc_Status_nu
#define	S_LCFRCV_Dmc_Status_nu			(0u)
#define GET_S_LCFRCV_Dmc_Status_nu()	S_LCFRCV_Dmc_Status_nu
#endif

#ifndef	S_LCFRCV_EvntDtctnIucEvID_nu
#define	S_LCFRCV_EvntDtctnIucEvID_nu(i)		(0u)
#define	GET_S_LCFRCV_EvntDtctnIucEvID_nu(i)	S_LCFRCV_EvntDtctnIucEvID_nu(i)
#endif

#ifndef	S_LCFRCV_EvntDtctnIucEvLifeTime_nu
#define	S_LCFRCV_EvntDtctnIucEvLifeTime_nu(i)		(0u)
#define	GET_S_LCFRCV_EvntDtctnIucEvLifeTime_nu(i)	S_LCFRCV_EvntDtctnIucEvLifeTime_nu(i)
#endif
	
#endif
/*---------------------------------------------------------------------------------------------*/

/*------------------------------------------- Other Inputs ------------------------------------*/
#ifndef	S_LCFRCV_SysCycleTimeVeh_sec
#define	S_LCFRCV_SysCycleTimeVeh_sec		(TPC_CONST_CYCLE_TIME)	/*Use const cycle time*/
#define GET_S_LCFRCV_SysCycleTimeVeh_sec()	S_LCFRCV_SysCycleTimeVeh_sec
#endif

#ifndef	S_LCFRCV_SysStOffLatDMC_bool
#define	S_LCFRCV_SysStOffLatDMC_bool		(DMC_LAT_STATUS == LCF_LADMC_OFF)
#define GET_S_LCFRCV_SysStOffLatDMC_bool()	S_LCFRCV_SysStOffLatDMC_bool
#endif

#ifndef	S_LCFRCV_SysStReqLatDMC_bool
#define	S_LCFRCV_SysStReqLatDMC_bool		(DMC_LAT_STATUS == LCF_LADMC_REQUEST) /*REQUEST = 6 = 'Wait for EPS handshake' */
#define GET_S_LCFRCV_SysStReqLatDMC_bool()	S_LCFRCV_SysStReqLatDMC_bool
#endif

/*Issue 1640787*/
#ifndef S_LCFRCV_SteerAngleLatDMC_deg
#define S_LCFRCV_SteerAngleLatDMC_deg ((float32)(float64)(DMC_Steer_Angle_Oc_deg*0.001526f))
#define GET_S_LCFRCV_SteerAngleLatDMC_deg() S_LCFRCV_SteerAngleLatDMC_deg
#endif

#ifndef	S_LCFRCV_ActToi_nu
#define	S_LCFRCV_ActToi_nu			(Get_T_LCFSND_ActToi_nu())
#define	GET_S_LCFRCV_ActToi_nu()	S_LCFRCV_ActToi_nu
#endif

#ifndef	S_LCFRCV_KappaSumCommand_1pm
#define	S_LCFRCV_KappaSumCommand_1pm	    ((float32)(float64)(LAT_Kappa_Sum_Command_1pm / 50000.0)) /*!< @ASAP_NAME LAT_Kappa_Sum_Command_1pm @UNIT 1/m @LSB 0.0000200000 @MIN -Inf @MAX Inf @OFFSET 0 */
#define GET_S_LCFRCV_KappaSumCommand_1pm()	S_LCFRCV_KappaSumCommand_1pm
#endif

#ifndef	S_LCFRCV_ActualStWheelAngle_deg	
#define S_LCFRCV_ActualStWheelAngle_deg	(0u) /*ToDo To find out default value, discuss with Stefan Feick*/
#define GET_S_LCFRCV_ActualStWheelAngle_deg()	S_LCFRCV_ActualStWheelAngle_deg
#endif  

#ifndef	S_LCFERR_SenErrorToVeh_btf
#define S_LCFERR_SenErrorToVeh_btf    	(pLcfVehReqPorts->pLcfVehInputFromSenData->EvntDtctnSenEvents_nu[2].EventId_nu)
#define GET_S_LCFERR_SenErrorToVeh_btf()	S_LCFERR_SenErrorToVeh_btf
#endif

#endif /* _LCFRCVVEH_COMMON_H_ */