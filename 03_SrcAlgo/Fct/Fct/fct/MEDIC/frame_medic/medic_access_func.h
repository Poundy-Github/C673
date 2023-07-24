/*! \file **********************************************************************

COMPANY:                   COPYRIGHT (C) Continental AG

PROJECT:                   Mainstream

CPU:                       CPU-Independent

COMPONENT:                 MEDIC (Monitoring Evaluation And Decision For Intervention Control) 

PACKAGENAME:               medic_access_func.h

DESCRIPTION:               Definitions of inline functions to access global data

AUTHOR:                    $Author: Vogl, Armin (uid19462) $

CREATION DATE:             $Date: 2020/11/05 16:18:38CET $

VERSION:                   $Revision: 1.135 $

**************************************************************************** */

#ifndef MEDIC_ACCESS_H_INCLUDED
#define MEDIC_ACCESS_H_INCLUDED

#if (MEDIC_CFG_EMERGENCY_BRAKE_ASSIST)

/*****************************************************************************
  MACROS 
*****************************************************************************/
#ifndef IS_SIGNAL_STATUS_OK
#define IS_SIGNAL_STATUS_OK(status) (VDY_IO_STATE_VALID == (status))
#endif

/************************************************************************/
/*                      ASSERT MACRO                                    */
/************************************************************************/
/* Check if we are in QA-C: PRQA_SIZE_T is defined in QA-C environment. */
#ifdef PRQA_SIZE_T
/* Switch off QA-C warnings on side effects for functions, which don't have any side effects and will certainly never have any. */
#pragma PRQA_NO_SIDE_EFFECTS MEDIC_p_GetVDYDynRaw
#pragma PRQA_NO_SIDE_EFFECTS MEDIC_f_GetEgoVelRaw
#pragma PRQA_NO_SIDE_EFFECTS MEDIC_f_GetEgoVelVarianceRaw
#pragma PRQA_NO_SIDE_EFFECTS MEDIC_f_GetEgoAccelRaw
#pragma PRQA_NO_SIDE_EFFECTS MEDIC_u_GetIOStateEgoSpeedX
#pragma PRQA_NO_SIDE_EFFECTS MEDIC_u_GetIOStateEgoAccelX
#pragma PRQA_NO_SIDE_EFFECTS MEDIC_u_GetIOStateEgoAccelY
#pragma PRQA_NO_SIDE_EFFECTS MEDIC_u_GetIOStateEgoYawRate
#pragma PRQA_NO_SIDE_EFFECTS MEDIC_u_GetIOStateEgoCurve
#pragma PRQA_NO_SIDE_EFFECTS MEDIC_u_GetIOStateEgoMotion
#pragma PRQA_NO_SIDE_EFFECTS MEDIC_u_GetEgoMotionState
#pragma PRQA_NO_SIDE_EFFECTS MEDIC_f_GetCycleTime
#pragma PRQA_NO_SIDE_EFFECTS MEDIC_p_GetHypothesisIntf
#pragma PRQA_NO_SIDE_EFFECTS MEDIC_p_GetHypothesis
#pragma PRQA_NO_SIDE_EFFECTS MEDIC_p_GetHypDegradation
#pragma PRQA_NO_SIDE_EFFECTS MEDIC_p_GetAlgoParameters
#pragma PRQA_NO_SIDE_EFFECTS MEDIC_p_GetCPARFCTParameters
#pragma PRQA_NO_SIDE_EFFECTS MEDIC_p_GetHeadOutCustom
#pragma PRQA_NO_SIDE_EFFECTS MEDIC_p_ModHeadOutCustom
#pragma PRQA_NO_SIDE_EFFECTS MEDIC_p_GetHeadOutGeneric
#pragma PRQA_NO_SIDE_EFFECTS MEDIC_p_ModHeadOutGeneric
#pragma PRQA_NO_SIDE_EFFECTS MEDIC_p_GetHeadInGeneric
#pragma PRQA_NO_SIDE_EFFECTS MEDIC_p_GetHeadInCustom
#pragma PRQA_NO_SIDE_EFFECTS MEDIC_p_GetDIMOutCustom
#pragma PRQA_NO_SIDE_EFFECTS MEDIC_p_GetDIMOutCustom
#pragma PRQA_NO_SIDE_EFFECTS MEDIC_p_GetDIMInCustom
#pragma PRQA_NO_SIDE_EFFECTS MEDIC_p_GetDIMInGeneric
#pragma PRQA_NO_SIDE_EFFECTS MEDIC_p_ModAccessData
#pragma PRQA_NO_SIDE_EFFECTS MEDIC_p_GetAccessData
#pragma PRQA_NO_SIDE_EFFECTS MEDIC_p_GetWorkingData
#pragma PRQA_NO_SIDE_EFFECTS MEDIC_p_ModWorkingData
#pragma PRQA_NO_SIDE_EFFECTS MEDIC_p_GetInput
#pragma PRQA_NO_SIDE_EFFECTS MEDIC_p_GetOutput  
#pragma PRQA_NO_SIDE_EFFECTS MEDIC_p_ModOutput
#pragma PRQA_NO_SIDE_EFFECTS MEDIC_p_GetReqPortList
#pragma PRQA_NO_SIDE_EFFECTS MEDIC_p_GetProPortList   
#pragma PRQA_NO_SIDE_EFFECTS MEDIC_p_ModProPortList
#pragma PRQA_NO_SIDE_EFFECTS MEDIC_p_ModFrameData
#pragma PRQA_NO_SIDE_EFFECTS MEDIC_p_GetFrameData
#pragma PRQA_NO_SIDE_EFFECTS MEDIC_p_ModSyncRef
#pragma PRQA_NO_SIDE_EFFECTS MEDIC_p_GetSyncRef
#pragma PRQA_NO_SIDE_EFFECTS MEDIC_p_GetPortHandlerList
#pragma PRQA_NO_SIDE_EFFECTS MEDIC_p_ModPortHandlerList
#pragma PRQA_NO_SIDE_EFFECTS MEDIC_p_GetVehSig
#pragma PRQA_NO_SIDE_EFFECTS MEDIC_p_GetBswAlgoParameters
#pragma PRQA_NO_SIDE_EFFECTS MEDIC_p_ModErrorOut
#pragma PRQA_NO_SIDE_EFFECTS MEDIC_p_GetVehCompState
#pragma PRQA_NO_SIDE_EFFECTS MEDIC_p_GetFctVehCustInput
#pragma PRQA_NO_SIDE_EFFECTS MEDIC_p_GetServiceFuncts
#pragma PRQA_NO_SIDE_EFFECTS MEDIC_p_GetDIMData
#pragma PRQA_NO_SIDE_EFFECTS MEDIC_p_GetDimInputGlobal
#pragma PRQA_NO_SIDE_EFFECTS MEDIC_p_GetDIM_HYPOUT_CAL_DATA_EBA
#pragma PRQA_NO_SIDE_EFFECTS MEDIC_p_GetDIMHypothesisList
#pragma PRQA_NO_SIDE_EFFECTS MEDIC_e_GetHypType
#endif /* end of PRQA_SIZE_T check*/

/* PRQA S 3406,3238,1055,3472,3242,3240,3239,3241,3243,3332 EOF*//* uic45572 Inline warnings to be suppressed */
/*****************************************************************************
  EXTERN VARIABLES
*****************************************************************************/
extern MEMSEC_REF MEDICAccessData_t                  MEDICAccessData;

/*****************************************************************************
  INLINE FUNCTIONS
*****************************************************************************/
ALGO_INLINE float32                 MEDIC_f_GetEgoVelRaw(void);
ALGO_INLINE float32                 MEDIC_f_GetEgoVelVarianceRaw(void);
ALGO_INLINE float32                 MEDIC_f_GetEgoAccelRaw(void);
ALGO_INLINE float32                 MEDIC_f_GetCycleTime(void);
ALGO_INLINE VDYIoStateTypes_t       MEDIC_u_GetIOStateEgoSpeedX(void);
ALGO_INLINE VDYIoStateTypes_t       MEDIC_u_GetIOStateEgoAccelX(void);
ALGO_INLINE VDYIoStateTypes_t       MEDIC_u_GetIOStateEgoAccelY(void);
ALGO_INLINE VDYIoStateTypes_t       MEDIC_u_GetIOStateEgoYawRate(void);
ALGO_INLINE VDYIoStateTypes_t       MEDIC_u_GetIOStateEgoCurve(void);
ALGO_INLINE VDYIoStateTypes_t       MEDIC_u_GetIOStateEgoMotion(void);

ALGO_INLINE DIMInputSignalState_t   MEDIC_e_GetAccelerationPedalState(void);
ALGO_INLINE float32                 MEDIC_f_GetAccelerationPedalPosition(void);
ALGO_INLINE DIMInputSignalState_t   MEDIC_e_GetAccelerationPedalGradState(void);
ALGO_INLINE float32                 MEDIC_f_GetGradAccelerationPedalPosition(void);
ALGO_INLINE boolean                 MEDIC_b_GetACCActive(void);
ALGO_INLINE eDriverSetting_t        MEDIC_e_GetDriverSetting(void);
#if (MEDIC_ARCHITECTURE_VERSION < 0x10)
ALGO_INLINE VehDyn_t const*         MEDIC_p_GetVDYDynRaw(void);
ALGO_INLINE EM_t_GenObjSensorSource MEDIC_e_GetObjectListConfiguration(void);
#endif
ALGO_INLINE boolean                 MEDIC_b_GetCodingParamValid(void);
ALGO_INLINE EBACodingParamGen_t     MEDIC_u_GetCodingParamGen(void);
ALGO_INLINE EBACodingParamCustom_t  MEDIC_u_GetCodingParamCustom(void);
ALGO_INLINE AlgoSignalState_t       MEDIC_u_GetCodingParHeaderStatus(void);
ALGO_INLINE fVariance_t             MEDIC_f_GetLateralCurveVariance(void);
ALGO_INLINE fCurve_t                MEDIC_f_GetLateralCurve(void);
ALGO_INLINE float32                 MEDIC_f_GetYawRateVariance(void);
ALGO_INLINE uint8                   MEDIC_u_GetOpMode(void);
ALGO_INLINE FCTStateSig_t           MEDIC_e_GetDriverBraking(void);
ALGO_INLINE eTurnIndicator_t        MEDIC_e_GetTurnIndicator(void);
ALGO_INLINE float32                 MEDIC_f_GetSteeringWheelAngle(void);
ALGO_INLINE DIMInputSignalState_t   MEDIC_e_GetSteeringWheelAngleState(void);
ALGO_INLINE float32                 MEDIC_f_GetSteeringWheelAngleGrad(void);
ALGO_INLINE DIMInputSignalState_t   MEDIC_e_GetSteeringWheelAngleGradState(void);
ALGO_INLINE uint32                  MEDIC_e_DriverOverride(void);
ALGO_INLINE boolean                 MEDIC_b_GetKickdown(void);
ALGO_INLINE FCTStateSig_t           MEDIC_f_GetSpeedLimitStatus(void);
#if (MEDIC_ARCHITECTURE_VERSION >= 0x10)
ALGO_INLINE const float32 *         MEDIC_p_GetDrvHeadPosX(void);
ALGO_INLINE const float32 *         MEDIC_p_GetDrvHeadPosY(void);
ALGO_INLINE const float32 *         MEDIC_p_GetDrvHeadPosZ(void);
ALGO_INLINE const float32 *         MEDIC_p_GetDrvHeadOrientationYaw(void);
ALGO_INLINE const float32 *         MEDIC_p_GetDrvHeadOrientationPitch(void);
ALGO_INLINE const float32 *         MEDIC_p_GetDrvHeadOrientationRoll(void);
ALGO_INLINE const float32 *         MEDIC_p_GetDrvGazeDirX(void);
ALGO_INLINE const float32 *         MEDIC_p_GetDrvGazeDirY(void);
ALGO_INLINE const float32 *         MEDIC_p_GetDrvGazeDirZ(void);
ALGO_INLINE const MEDIC_eFatigueLevel * MEDIC_p_GetDrvFatigueLvl(void);
ALGO_INLINE const MEDIC_eMultitaskingLevel * MEDIC_p_GetDrvMultitaskingLvl(void);
ALGO_INLINE const MEDIC_eConversationLevel * MEDIC_p_GetDrvConverationLvl(void);
ALGO_INLINE const MEDIC_eHeadPosConfidence * MEDIC_p_GetDrvHeadPosConf(void);
ALGO_INLINE const MEDIC_eGazeDirConfidence * MEDIC_p_GetDrvGazeDirConf(void);
#endif

#if (MEDIC_ARCHITECTURE_VERSION < 0x10)
ALGO_INLINE VehLongMotStateExt_t    MEDIC_u_GetLongitudinalMotionState(void);
#else
ALGO_INLINE uint8   MEDIC_u_GetLongitudinalMotionState(void);
#endif

#if (MEDIC_ARCHITECTURE_VERSION < 0x10)
ALGO_INLINE MotState_t              MEDIC_u_GetEgoMotionState(void);
#if (MEDIC_CFG_HYPOTHESIS_EVAL_AND_DECISION)
ALGO_INLINE HypothesisIntf_t const* MEDIC_p_GetHypothesisIntf(void);
ALGO_INLINE HypoIntfDegr_t   const* MEDIC_p_GetHypDegradation(void);
#endif
#else
ALGO_INLINE ACDC2_HypothesisIntf const* MEDIC_p_GetHypothesisIntf(void);
#endif

#if (MEDIC_ARCHITECTURE_VERSION < 0x10)
ALGO_INLINE Hypothesis_t    const* MEDIC_p_GetHypothesis(const uint8 iHyp);
#else
ALGO_INLINE ACDC2_Hypothesis const* MEDIC_p_GetHypothesis(const uint8 iHyp);
#endif

#if ((MEDIC_CFG_CPAR_PARAMS)|| (MEDIC_CFG_INCLUDE_UNUSED_INTF))
#if (MEDIC_ARCHITECTURE_VERSION < 0x10)
ALGO_INLINE CPAR_FCT_Parameters_t const* MEDIC_p_GetCPARFCTParameters(void);
#endif
#endif

#if ((MEDIC_CFG_HYPOTHESIS_EVAL_AND_DECISION)|| (MEDIC_CFG_INCLUDE_UNUSED_INTF))
#if (MEDIC_ARCHITECTURE_VERSION < 0x10)
ALGO_INLINE HEADOutputCustom_t const  *  MEDIC_p_GetHeadOutCustom(void);
ALGO_INLINE HEADOutputCustom_t*          MEDIC_p_ModHeadOutCustom(void);
ALGO_INLINE HEADOutputGeneric_t const *  MEDIC_p_GetHeadOutGeneric(void);
ALGO_INLINE HEADOutputGeneric_t*         MEDIC_p_ModHeadOutGeneric(void);
ALGO_INLINE HEADInputGeneric_t const *   MEDIC_p_GetHeadInGeneric(void);
ALGO_INLINE HEADInputCustom_t  const *   MEDIC_p_GetHeadInCustom(void);
#endif
#endif

#if (MEDIC_CFG_HYPOTHESIS_EVAL_AND_DECISION)
ALGO_INLINE EBASignalState_t *        MEDIC_p_GetEBASignalState(void);
ALGO_INLINE EBAFctChan_t *            MEDIC_p_GetEBAFctChan(void);
ALGO_INLINE HEADCustOutputLocVar_t *  MEDIC_p_GetHEADCustOutputLocVar(void);
ALGO_INLINE HEADInputData_t const *   MEDIC_p_GetHEADInputData(void);
ALGO_INLINE HEADInputData_t *         MEDIC_p_ModHEADInputData(void);
#endif

#if ((MEDIC_CFG_DRIVER_INTENTION_MONITORING)|| (MEDIC_CFG_INCLUDE_UNUSED_INTF))
#if (MEDIC_ARCHITECTURE_VERSION < 0x10)
ALGO_INLINE DIMOutputCustom_t const * MEDIC_p_GetDIMOutCustom(void);
ALGO_INLINE DIMOutputCustom_t       * MEDIC_p_ModDIMOutCustom(void);
ALGO_INLINE DIMInputCustom_t  const * MEDIC_p_GetDIMInCustom(void);
ALGO_INLINE DIMInputGeneric_t const * MEDIC_p_GetDIMInGeneric(void);
#endif
#endif

#if(MEDIC_CFG_DRIVER_INTENTION_MONITORING)
ALGO_INLINE DIMData_t *             MEDIC_p_GetDIMData(void);
ALGO_INLINE DIMInputDataGlobal_t  * MEDIC_p_GetDimInputGlobal(void);
ALGO_INLINE DIM_HYPOUT_CAL_DATA_t * MEDIC_p_GetDIM_HYPOUT_CAL_DATA_EBA(void);
ALGO_INLINE DIMHypothesisList_t *   MEDIC_p_GetDIMHypothesisList(void);
#if (DIM_CFG_CALC_STEERING_ANGLE_GRADIENT)
ALGO_INLINE DimIirFilt_t *          MEDIC_p_GetDimIirFiltSteeringAngle(void);
#endif
#if (DIM_CFG_CALC_GAS_PEDAL_GRADIENT)
ALGO_INLINE DimIirFilt_t *          MEDIC_p_GetDimIirFiltGasPedal(void);
#endif
#endif
ALGO_INLINE MEDICAccessData_t        const * MEDIC_p_GetAccessData (void);
ALGO_INLINE MEDICAccessData_t              * MEDIC_p_ModAccessData (void);
ALGO_INLINE MEDIC_Working_t          const * MEDIC_p_GetWorkingData(void);
ALGO_INLINE MEDIC_Working_t                * MEDIC_p_ModWorkingData(void);
ALGO_INLINE MEDIC_Input_t            const * MEDIC_p_GetInput      (void);
ALGO_INLINE MEDIC_Output_t           const * MEDIC_p_GetOutput     (void);
ALGO_INLINE MEDIC_Output_t                 * MEDIC_p_ModOutput     (void);
ALGO_INLINE MEDICFrame_t             const * MEDIC_p_GetFrameData  (void);
ALGO_INLINE MEDICFrame_t                   * MEDIC_p_ModFrameData (void);
ALGO_INLINE MEDICPortHandlerList_t   const * MEDIC_p_GetPortHandlerList(void);
ALGO_INLINE MEDICPortHandlerList_t         * MEDIC_p_ModPortHandlerList(void);
ALGO_INLINE MEDICSyncRef_t                 * MEDIC_p_ModSyncRef (void);
ALGO_INLINE MEDICSyncRef_t           const * MEDIC_p_GetSyncRef (void);
#if (MEDIC_ARCHITECTURE_VERSION < 0x10)
ALGO_INLINE reqMEDICPtrList_t        const * MEDIC_p_GetReqPortList(void);
ALGO_INLINE proMEDICPtrList_t        const * MEDIC_p_GetProPortList(void);
ALGO_INLINE proMEDICPtrList_t              * MEDIC_p_ModProPortList(void);
#else
ALGO_INLINE MEDIC01_ReqPorts         const * MEDIC_p_GetReqPortList(void);
ALGO_INLINE MEDIC01_ProPorts         const * MEDIC_p_GetProPortList(void);
ALGO_INLINE MEDIC01_ProPorts               * MEDIC_p_ModProPortList(void);
#endif

#if (MEDIC_CFG_DIAGNOSTIC_OUTPUT)
ALGO_INLINE MEDIC_Diagnostic_t * MEDIC_p_ModMEDICDiag(void);
#endif

#if (MEDIC_ARCHITECTURE_VERSION < 0x10)
#if ((MEDIC_CFG_VEH_SIG_INPUT)|| (MEDIC_CFG_INCLUDE_UNUSED_INTF))
ALGO_INLINE VehSig_t const* MEDIC_p_GetVehSig(void);
#endif
#endif  /*MEDIC_ARCHITECTURE_VERSION < 0x10 */

#if (MEDIC_ARCHITECTURE_VERSION < 0x10)
#if ((MEDIC_CFG_BSW_ALGO_PARAMS) || (MEDIC_CFG_INCLUDE_UNUSED_INTF))
ALGO_INLINE BSW_s_AlgoParameters_t const* MEDIC_p_GetBswAlgoParameters(void);
#endif

#if((MEDIC_CFG_ERROR_OUTPUT_VEH)|| (MEDIC_CFG_INCLUDE_UNUSED_INTF))
ALGO_INLINE FCTVehErrorOut_t * MEDIC_p_ModErrorOut(void);
#endif
#endif

#if((MEDIC_CFG_USE_ALGOCOMPSTATE)|| (MEDIC_CFG_INCLUDE_UNUSED_INTF))
ALGO_INLINE AlgoCompState_t * MEDIC_p_GetVehCompState(void);
#endif 

#if ((MEDIC_CFG_CUSTOMINPUT) || (MEDIC_CFG_INCLUDE_UNUSED_INTF))
ALGO_INLINE FCTVehCustomInput_t const * MEDIC_p_GetFctVehCustInput(void);
#endif

#if((MEDIC_CFG_USE_SERVICE_POINTER_FUNCTS)|| (MEDIC_CFG_INCLUDE_UNUSED_INTF))
#if (MEDIC_ARCHITECTURE_VERSION < 0x10)
ALGO_INLINE AS_t_ServiceFuncts const * MEDIC_p_GetServiceFuncts(void);
#else
ALGO_INLINE MEDIC_Services     const * MEDIC_p_GetServiceFuncts(void);
#endif

#endif
#if (MEDIC_ARCHITECTURE_VERSION >= 0x10)
ALGO_INLINE MEDIC_t_BrakeCascades const*  MEDIC_p_GetbrakeCascades(void);
ALGO_INLINE MEDIC_t_BrakeCascades *       MEDIC_p_ModbrakeCascades(void);
ALGO_INLINE MEDIC_TargetRequest_t const*  MEDIC_p_GettrajPlanerCtrlLimits(void);
ALGO_INLINE MEDIC_TargetRequest_t *       MEDIC_p_ModtrajPlanerCtrlLimits(void);
#if (CFG_MEDIC_OUT_HBA)
ALGO_INLINE MEDIC_t_HBA const*  MEDIC_p_GethbaHydrBrkAss(void);
ALGO_INLINE MEDIC_t_HBA *       MEDIC_p_ModhbaHydrBrkAss(void);
#endif 
#if (CFG_MEDIC_OUT_PREFILL)
ALGO_INLINE MEDIC_t_Prefill const*  MEDIC_p_Getprefill(void);
ALGO_INLINE MEDIC_t_Prefill *       MEDIC_p_Modprefill(void);
#endif 
#if (CFG_MEDIC_OUT_PREBRAKE)
ALGO_INLINE MEDIC_t_PreBrake const*  MEDIC_p_GetpreBrake(void);
ALGO_INLINE MEDIC_t_PreBrake *       MEDIC_p_ModpreBrake(void);
#endif 
#if (CFG_MEDIC_OUT_WARNINGS)
ALGO_INLINE MEDIC_t_Warnings const*  MEDIC_p_Getwarnings(void);
ALGO_INLINE MEDIC_t_Warnings *       MEDIC_p_Modwarnings(void);
#endif 
#if (CFG_MEDIC_OUT_PRECRASH)
ALGO_INLINE MEDIC_t_PreCrash const*  MEDIC_p_GetpreCrash(void);
ALGO_INLINE MEDIC_t_PreCrash *       MEDIC_p_ModpreCrash(void);
#endif 
#if (CFG_MEDIC_OUT_DRIVEROFFPREV)
ALGO_INLINE MEDIC_t_DriveOffPrev const*  MEDIC_p_GetdriveOffPrev(void);
ALGO_INLINE MEDIC_t_DriveOffPrev *       MEDIC_p_ModdriveOffPrev(void);
#endif 
#if (CFG_MEDIC_OUT_ESA)
ALGO_INLINE MEDIC_t_SteerAssist const*  MEDIC_p_GetsteerAssist(void);
ALGO_INLINE MEDIC_t_SteerAssist *       MEDIC_p_ModsteerAssist(void);
#endif 
#if (CFG_MEDIC_OUT_HYPREACTIONS)
ALGO_INLINE MEDIC_t_HypReactions_Interf const*  MEDIC_p_GethypReactions(void);
ALGO_INLINE MEDIC_t_HypReactions_Interf *       MEDIC_p_ModhypReactions(void);
#endif 
#if (CFG_MEDIC_OUT_FCTQUALIFIERS)
ALGO_INLINE MEDIC_t_FCTQualifiers_Interf const*  MEDIC_p_GetfctQualifiers(void);
ALGO_INLINE MEDIC_t_FCTQualifiers_Interf *       MEDIC_p_ModfctQualifiers(void);
#endif 
#if (CFG_MEDIC_OUT_FCTDATA )
ALGO_INLINE MEDIC_t_FCTData_Interf const*  MEDIC_p_GetfctData(void);
ALGO_INLINE MEDIC_t_FCTData_Interf *       MEDIC_p_ModfctData(void);
#endif 
#if (CFG_MEDIC_OUT_TOYOTA == 1)
ALGO_INLINE MEDIC_t_TMCOutput_Interf const*  MEDIC_p_GettmcOutput(void);
ALGO_INLINE MEDIC_t_TMCOutput_Interf *       MEDIC_p_ModtmcOutput(void);
#endif
#if (CFG_MEDIC_OUT_DIMOUTPUT)
ALGO_INLINE MEDIC_t_DIMOutput_Interf const*  MEDIC_p_GetdimOutput(void);
ALGO_INLINE MEDIC_t_DIMOutput_Interf *       MEDIC_p_ModdimOutput(void);
#endif
#endif 
#if ((MEDIC_CFG_HYPOTHESIS_EVAL_AND_DECISION)||(MEDIC_CFG_DRIVER_INTENTION_MONITORING)|| (MEDIC_CFG_INCLUDE_UNUSED_INTF)) 
ALGO_INLINE eEBAFctChan_t *     MEDIC_p_ModPreStaticWarnfctchan(void);
ALGO_INLINE eEBASignalState_t * MEDIC_p_ModPreStaticWarnSignal(void);
ALGO_INLINE uint8 *             MEDIC_p_ModPreStaticWarnActiveHyp(void);
ALGO_INLINE eEBAFctChan_t *     MEDIC_p_ModAcuteStaticWarnfctchan(void);
ALGO_INLINE eEBASignalState_t * MEDIC_p_ModAcuteStaticWarnSignal(void);
ALGO_INLINE uint8 *             MEDIC_p_ModAcuteStaticWarnActiveHyp(void);
ALGO_INLINE eEBAFctChan_t *     MEDIC_p_ModPreDynamicWarnfctchan(void);
ALGO_INLINE eEBASignalState_t * MEDIC_p_ModPreDynamicWarnSignal(void);
ALGO_INLINE uint8 *             MEDIC_p_ModPreDynamicWarnActiveHyp(void);
ALGO_INLINE eEBAFctChan_t *     MEDIC_p_ModAcuteDynamicWarnfctchan(void);
ALGO_INLINE eEBASignalState_t * MEDIC_p_ModAcuteDynamicWarnSignal(void);
ALGO_INLINE uint8 *             MEDIC_p_ModAcuteDynamicWarnActiveHyp(void);
ALGO_INLINE eEBAFctChan_t  *    MEDIC_p_ModPrefillfctchan(void);
ALGO_INLINE boolean *           MEDIC_p_ModPrefillActive(void);
ALGO_INLINE boolean *           MEDIC_p_ModPrefillPreRunActive(void);
ALGO_INLINE uint8 *             MEDIC_p_ModPrefillGeneratorControl(void);
ALGO_INLINE uint8 *             MEDIC_p_ModPrefillActiveHyp(void);
ALGO_INLINE float32 *           MEDIC_p_ModHBADecel(void);
ALGO_INLINE uint8 *             MEDIC_p_ModHBAActiveHyp(void);
ALGO_INLINE eEBAFctChan_t *     MEDIC_p_ModHBAFctChan(void);
ALGO_INLINE uint8 *             MEDIC_p_ModHBALevel(void);
ALGO_INLINE boolean *           MEDIC_p_ModPreBrakeDecelEnabled(void);
ALGO_INLINE boolean *           MEDIC_p_ModPreBrakeStdstillRequest(void);
ALGO_INLINE boolean *           MEDIC_p_ModPreBrakeEmergency(void);
ALGO_INLINE eEBAFctChan_t *     MEDIC_p_ModPreBrakeFctChan(void);
ALGO_INLINE float32 *           MEDIC_p_ModPreBrakeDecel(void);
ALGO_INLINE uint8 *             MEDIC_p_ModPreBrakeActiveHyp(void);
ALGO_INLINE uint8 *             MEDIC_p_ModPreBrakeLevel(void);
#if (MEDIC_CFG_EBA_2ND_SENSOR_CONFIRMATION)
ALGO_INLINE  boolean *          MEDIC_p_ModPreBrakeCamConfirmed(void);
#endif 
ALGO_INLINE boolean *           MEDIC_p_ModPreCrashEMAActive(void);
ALGO_INLINE eEBAFctChan_t *     MEDIC_p_ModPreCrashEBAFctChan(void);
ALGO_INLINE float32 *           MEDIC_p_ModPreCrashCV(void);
ALGO_INLINE float32 *           MEDIC_p_ModPreCrashTTC(void);
ALGO_INLINE uint8 *             MEDIC_p_ModPreCrashActiveHyp(void);
ALGO_INLINE eFunctionQualifier_t * MEDIC_p_ModPedFunctionQualifier(void);
ALGO_INLINE eFunctionQualifier_t * MEDIC_p_ModCyclFunctionQualifier(void);
ALGO_INLINE eFunctionQualifier_t * MEDIC_p_ModUnclassifiedFunctionQualifier(void);
ALGO_INLINE eFunctionQualifier_t * MEDIC_p_ModVehFunctionQualifier(void);
ALGO_INLINE HEADOutCustHypReactions_t  * MEDIC_p_ModrgHypReactions(uint8 uHyp);
#if (MEDIC_ARCHITECTURE_VERSION >= 0x10)
ALGO_INLINE uint32  *                   MEDIC_p_ModFCTDataVersionNumber(void);
ALGO_INLINE SignalHeader_t  *           MEDIC_p_ModFCTDatasigHeader(void);
ALGO_INLINE ObjectDescription  *        MEDIC_p_ModFCTDataObjDescription(void);
ALGO_INLINE ObjectDescription  *        MEDIC_p_ModFCTDataObjDisColl(void);
#endif
#if ((MEDIC_ARCHITECTURE_VERSION >= 0x10) && (MEDIC_CFG_ABORT_REASON))
ALGO_INLINE uint8    *               MEDIC_p_ModFCTDataAbortReasonParamOutType(uint8 index);
ALGO_INLINE boolean  *               MEDIC_p_ModFCTDataAbortReasonHypLost(uint8 index);
#endif
ALGO_INLINE float32  *                   MEDIC_p_ModFCTDataVelocityFactor(void);
ALGO_INLINE float32  *                   MEDIC_p_ModFCTDataSafeObjDistance(void);
#if (HEAD_USE_TIME_HIGH_OBJ_QUALITY)
ALGO_INLINE float32  *               MEDIC_p_ModFCTDataObjLifeTimeHiQual(void);
#endif
ALGO_INLINE float32  *                  MEDIC_p_ModFCTDataObjTTC(void);
ALGO_INLINE float32  *                  MEDIC_p_ModFCTDataObjDistX(void);

#if (MEDIC_ARCHITECTURE_VERSION >= 0x10)
ALGO_INLINE float32  *                  MEDIC_p_ModFCTDataObjDistY(void);
ALGO_INLINE float32  *                  MEDIC_p_ModFCTDataObjVelX(void);
ALGO_INLINE float32  *                  MEDIC_p_ModFCTDataObjAccelX(void);
ALGO_INLINE float32  *                  MEDIC_p_ModFCTDataObjVelY(void);
ALGO_INLINE float32  *                  MEDIC_p_ModFCTDataObjAccelY(void);
ALGO_INLINE  float32  *                 MEDIC_p_ModFCTDataObjTTB(void);
#endif
ALGO_INLINE float32  *                  MEDIC_p_ModFCTDaCollisionAvoidAccel(void);
#if (MEDIC_ARCHITECTURE_VERSION >= 0x10)
ALGO_INLINE float32  *                  MEDIC_p_ModFCTDataObjPoe(void);
#endif
ALGO_INLINE ObjNumber_t  *              MEDIC_p_ModFCTDataObjref(void);
#if (MEDIC_ARCHITECTURE_VERSION >= 0x10)
ALGO_INLINE eEBARelObjClass_t  *        MEDIC_p_ModFCTDataObjClass(void);
#endif
ALGO_INLINE eEBARelObjQualifier_t  *    MEDIC_p_ModFCTDataObjRelQualifier(void);
#if (MEDIC_ARCHITECTURE_VERSION >= 0x10)
ALGO_INLINE eSensorSource_t  *          MEDIC_p_ModFCTDataFusionState(void);
#endif
#endif
/*****************************************************************************
  INLINE FUNCTIONS
*****************************************************************************/

/* Deactivate QA-C warning 3406; Reviewer: S. Schwarzkopf; Date: 05.12.2014; 
   Reason: Styleguide specifies this as best practice (R231, R238) and 
   ALGO_INLINE is defined compiler dependent for inlining with internal linkage.
   Review-ID: */
/* PRQA S 3406 ALGO_INLINES */
/*************************************************************************************************************************
  Functionname:         MEDIC_p_GetAccessData                                                                       */ /*!
  @brief                Returns the pointer to the access data structure.
  @glob_in              @ref MEDICAccessData
  @return               MEDICAccessData_t const *
  @author               Nagaraja Veerashettappa  | Nagaraja.Veerashettappa@continental-corporation.com 
*************************************************************************************************************************/  
ALGO_INLINE MEDICAccessData_t const * MEDIC_p_GetAccessData(void)
{
  return &MEDICAccessData;
}

/*************************************************************************************************************************
  Functionname:         MEDIC_p_ModAccessData                                                                         */ /*!
  @brief                Returns the mutable pointer to the access data structure.
  @glob_in              @ref MEDICAccessData
  @return               MEDICAccessData_t *
  @author               Nagaraja Veerashettappa  | Nagaraja.Veerashettappa@continental-corporation.com 
*************************************************************************************************************************/
ALGO_INLINE MEDICAccessData_t * MEDIC_p_ModAccessData(void)
{
  return &MEDICAccessData;
}
#if (MEDIC_ARCHITECTURE_VERSION >= 0x10)
/*************************************************************************************************************************
  Functionname:         MEDIC_u_GetLongMotStateStandStill                                                                         */ /*!
  @brief                Returns the Motion state
  @return               uint32
  @author               Nalina M  | Nalina.Muddaveeraiah@continental-corporation.com
*************************************************************************************************************************/
ALGO_INLINE uint32 MEDIC_u_GetLongMotStateStandStill(void)
{
  #if (MEDIC_CFG_USE_VDY)
  return VDY_LONG_MOT_STATE_STDST;
  #else
  return CEM_LONG_MOT_STATE_STDST;
  #endif
}
#endif
/*************************************************************************************************************************
  Functionname:         MEDIC_p_GetWorkingData                                                                       */ /*!
  @brief                Returns the pointer to the working data.
  @glob_in              @ref MEDIC_p_GetAccessData
  @return               MEDIC_Working_t  const *
  @author               Nagaraja Veerashettappa  | Nagaraja.Veerashettappa@continental-corporation.com 
*************************************************************************************************************************/ 
ALGO_INLINE MEDIC_Working_t const * MEDIC_p_GetWorkingData(void)
{
  return &MEDIC_p_GetAccessData()->Working;
}

/*************************************************************************************************************************
  Functionname:         MEDIC_p_ModWorkingData                                                                         */ /*!
  @brief                Returns the mutable pointer to the working data
  @glob_in              @ref MEDIC_p_ModAccessData
  @return               MEDIC_Working_t const *
  @author               Nagaraja Veerashettappa  | Nagaraja.Veerashettappa@continental-corporation.com 
*************************************************************************************************************************/
ALGO_INLINE MEDIC_Working_t  * MEDIC_p_ModWorkingData(void)
{
  return &MEDIC_p_ModAccessData()->Working;
}
/*************************************************************************************************************************
  Functionname:         MEDIC_p_GetInput                                                                            */ /*!
  @brief                Returns the pointer to the inputs.
  @glob_in              @ref MEDIC_p_GetAccessData
  @return               MEDIC_Input_t const *
  @author               Nagaraja Veerashettappa  | Nagaraja.Veerashettappa@continental-corporation.com 
*************************************************************************************************************************/ 
ALGO_INLINE MEDIC_Input_t const *  MEDIC_p_GetInput(void)
{
  return &MEDIC_p_GetAccessData()->Input;
}

/*************************************************************************************************************************
  Functionname:         MEDIC_p_GetOutput                                                                              */ /*!
  @brief                Returns the pointer to the outputs 
  @glob_in              @ref MEDIC_p_GetAccessData
  @return               MEDIC_Output_t const *
  @author               Nagaraja Veerashettappa  | Nagaraja.Veerashettappa@continental-corporation.com 
*************************************************************************************************************************/ 
ALGO_INLINE MEDIC_Output_t const * MEDIC_p_GetOutput(void)
{
  return &MEDIC_p_GetAccessData()->Output;
}

/*************************************************************************************************************************
  Functionname:         MEDIC_p_ModOutput                                                                         */ /*!
  @brief                Returns the mutable pointer to the outputs 
  @glob_in              @ref MEDIC_p_ModAccessData
  @return               MEDIC_Output_t *
  @author               Nagaraja Veerashettappa  | Nagaraja.Veerashettappa@continental-corporation.com 
*************************************************************************************************************************/
ALGO_INLINE MEDIC_Output_t * MEDIC_p_ModOutput(void)
{
  return &MEDIC_p_ModAccessData()->Output;
}

/*************************************************************************************************************************
  Functionname:         MEDIC_p_GetReqPortList                                                                       */ /*!
  @brief                Returns the pointer to the request ports
  @glob_in              @ref MEDIC_p_GetInput
  @return               reqMEDICPtrList_t const * 
  @author               Nagaraja Veerashettappa  | Nagaraja.Veerashettappa@continental-corporation.com 
*************************************************************************************************************************/ 
#if (MEDIC_ARCHITECTURE_VERSION < 0x10)
ALGO_INLINE reqMEDICPtrList_t const *  MEDIC_p_GetReqPortList(void)
#else
ALGO_INLINE MEDIC01_ReqPorts  const *  MEDIC_p_GetReqPortList(void)
#endif
{
  return &MEDICAccessData.Input.ReqPorts;
}


/*************************************************************************************************************************
  Functionname:         MEDIC_p_GetProPortList                                                                       */ /*!
  @brief                Returns the pointer to the provide ports
  @glob_in              @ref MEDIC_p_GetOutput
  @return               proMEDICPtrList_t const *
  @author               Nagaraja Veerashettappa  | Nagaraja.Veerashettappa@continental-corporation.com 
*************************************************************************************************************************/ 
#if (MEDIC_ARCHITECTURE_VERSION < 0x10)
ALGO_INLINE proMEDICPtrList_t const * MEDIC_p_GetProPortList(void)
#else
ALGO_INLINE MEDIC01_ProPorts const  *  MEDIC_p_GetProPortList(void)
#endif
{
  return &MEDIC_p_GetOutput()->ProPorts;
}

/*************************************************************************************************************************
  Functionname:         MEDIC_p_ModProPortList                                                                       */ /*!
  @brief                Returns the pointer to the provide ports
  @glob_in              @ref MEDIC_p_GetOutput
  @return               proMEDICPtrList_t *
  @author               Nagaraja Veerashettappa  | Nagaraja.Veerashettappa@continental-corporation.com 
*************************************************************************************************************************/ 
#if (MEDIC_ARCHITECTURE_VERSION < 0x10)
ALGO_INLINE proMEDICPtrList_t *  MEDIC_p_ModProPortList(void)
#else
ALGO_INLINE MEDIC01_ProPorts  *  MEDIC_p_ModProPortList(void)
#endif
{
  return &MEDIC_p_ModOutput()->ProPorts; 
}

#if (MEDIC_CFG_DIAGNOSTIC_OUTPUT)
/*************************************************************************************************************************
  Functionname:         MEDIC_p_ModMEDICDiag                                                                        */ /*!
  @brief                Returns the pointer to the diagnostic info structure
  @glob_in              @ref MEDICAccessData
  @return               MEDIC_Diagnostic_t *
  @author               Armin Vogl | armin.vogl@continental-corporation.com 
*************************************************************************************************************************/ 
ALGO_INLINE MEDIC_Diagnostic_t * MEDIC_p_ModMEDICDiag(void)
{
  return &MEDICAccessData.Working.pInterCycleMeas->MEDICDiag;
}
#endif

/*************************************************************************************************************************
Functionname:         MEDIC_p_ModHEADState                                                                          */ /*!
@brief                Returns the pointer to the local HEADState variable in head
@glob_in              @ref MEDICAccessData
@return               MEDICCompState_t *
@author               Armin Vogl | armin.vogl@continental-corporation.com
*************************************************************************************************************************/ 
ALGO_INLINE MEDICCompState_t * MEDIC_p_ModHEADState(void)
{
  #if MEDIC_CFG_MTS_DATA_IN_INTER_MEAS
  return &(MEDICAccessData.Working.pInterCycleMeas->HEADState);
  #else
  return &(MEDICAccessData.Working.pStackData->HEADState);
  #endif
}

/*************************************************************************************************************************
Functionname:         MEDIC_p_ModHEADMTSData                                                                        */ /*!
@brief                Returns the pointer to the HEADMTSData structure
@glob_in              @ref MEDICAccessData
@return               HEADMTSData_t *
@author               Armin Vogl | armin.vogl@continental-corporation.com
*************************************************************************************************************************/ 
ALGO_INLINE HEADMTSData_t * MEDIC_p_ModHEADMTSData(void)
{
  #if MEDIC_CFG_MTS_DATA_IN_INTER_MEAS
  return &(MEDICAccessData.Working.pInterCycleMeas->HEADMTSData);
  #else
  return &(MEDICAccessData.Working.pStackData->HEADMTSData);
  #endif
}

/*************************************************************************************************************************
Functionname:         MEDIC_p_ModHEADMTSExtData                                                                     */ /*!
@brief                Returns the pointer to the HEADMTSSpecificData structure
@glob_in              @ref MEDICAccessData
@return               HEADMTSSpecificData_t *
@author               Armin Vogl | armin.vogl@continental-corporation.com
*************************************************************************************************************************/ 
ALGO_INLINE HEADMTSSpecificData_t * MEDIC_p_ModHEADMTSExtData(void)
{
  #if MEDIC_CFG_MTS_DATA_IN_INTER_MEAS
  return &(MEDICAccessData.Working.pInterCycleMeas->HEADMTSExtData);
  #else
  return &(MEDICAccessData.Working.pStackData->HEADMTSExtData);
  #endif
}

/*************************************************************************************************************************
Functionname:         MEDIC_p_ModHEADMTSCodedInhibition                                                              */ /*!
@brief                Returns the pointer to the HEADMTSCodedInhibition structure
@glob_in              @ref MEDICAccessData
@return               HEADMTSCodedInhibition_t *
@author               Armin Vogl | armin.vogl@continental-corporation.com
*************************************************************************************************************************/ 
ALGO_INLINE HEADMTSCodedInhibition_t * MEDIC_p_ModHEADMTSCodedInhibition(void)
{
  #if MEDIC_CFG_MTS_DATA_IN_INTER_MEAS
  return &(MEDICAccessData.Working.pInterCycleMeas->HEADMTSCodedInhibition);
  #else
  return &(MEDICAccessData.Working.pStackData->HEADMTSCodedInhibition);
  #endif
}

/*************************************************************************************************************************
Functionname:         MEDIC_p_ModHEADMTSConditionsOKTimer                                                           */ /*!
@brief                Returns the pointer to the HEADMTSConditionsOKTimer structure
@glob_in              @ref MEDICAccessData
@return               HEADMTSConditionsOKTimer_t *
@author               Armin Vogl | armin.vogl@continental-corporation.com
*************************************************************************************************************************/ 
ALGO_INLINE HEADMTSConditionsOKTimer_t * MEDIC_p_ModHEADMTSConditionsOKTimer(void)
{
  #if MEDIC_CFG_MTS_DATA_IN_INTER_MEAS
  return &(MEDICAccessData.Working.pInterCycleMeas->HEADMTSConditionsOKTimer);
  #else
  return &(MEDICAccessData.Working.pStackData->HEADMTSConditionsOKTimer);
  #endif
}

/*************************************************************************************************************************
Functionname:         MEDIC_p_ModHEADMTSModuleCommonOut                                                             */ /*!
@brief                Returns the pointer to the HEADMTSModuleCommonOut structure
@glob_in              @ref MEDICAccessData
@return               HEADMTSModuleCommonOut_t *
@author               Armin Vogl | armin.vogl@continental-corporation.com
*************************************************************************************************************************/ 
ALGO_INLINE HEADMTSModuleCommonOut_t * MEDIC_p_ModHEADMTSModuleCommonOut(void)
{
  #if MEDIC_CFG_MTS_DATA_IN_INTER_MEAS
  return &(MEDICAccessData.Working.pInterCycleMeas->HEADMTSModuleCommonOut);
  #else
  return &(MEDICAccessData.Working.pStackData->HEADMTSModuleCommonOut);
  #endif
}

#if (MEDIC_ARCHITECTURE_VERSION >= 0x10)
/*************************************************************************************************************************
  Functionname:         MEDIC_p_GetVehicleKinematics                                                                */ /*!
  @brief                Returns the pointer to the vehicle kinematics
  @return               EgoVehicleKinematics const* const 
  @author               Armin Vogl | armin.vogl@continental-corporation.com
*************************************************************************************************************************/ 
ALGO_INLINE CEM_EgoVehicleKinematics const *  MEDIC_p_GetVehicleEgoMotion(void)
{
  return (MEDIC_p_GetInput()->ReqPorts.egoMotion);
}

/*************************************************************************************************************************
  Functionname:         MEDIC_p_GetVehicleData                                                                */ /*!
  @brief                Returns the pointer to the vehicle data
  @return               EgoVehicleKinematics const* const
  @author               Armin Vogl | armin.vogl@continental-corporation.com
*************************************************************************************************************************/
ALGO_INLINE MEDIC_t_Vehicle const *  MEDIC_p_GetVehicleData(void)
{
  return (MEDIC_p_GetInput()->ReqPorts.vehicle);
}
#endif

#if (MEDIC_ARCHITECTURE_VERSION >= 0x10)
#if (MEDIC_CFG_USE_VDY)
/*************************************************************************************************************************
  Functionname:         MEDIC_p_GetVDyInput                                                                */ /*!
  @brief                Returns the pointer to the vehicle dynamic structure`
  @return               VehDyn_t const *
  @author               Nalina M | nalina.muddhaveeraiah@continental-corporation.com
*************************************************************************************************************************/
ALGO_INLINE VehDyn_t const *  MEDIC_p_GetVDyInput(void)
{
    return (MEDIC_p_GetInput()->ReqPorts.vDY_In);
}
#endif /* #if (MEDIC_CFG_USE_VDY) */
#endif
/*************************************************************************************************************************
  Functionname:         MEDIC_u_GetLongitudinalMotionState                                                          */ /*!
  @brief                Returns the longitudinal motion state
  @return               uint8
  @author               Armin Vogl | armin.vogl@continental-corporation.com
*************************************************************************************************************************/ 
#if (MEDIC_CFG_HYPOTHESIS_EVAL_AND_DECISION)
#if (MEDIC_ARCHITECTURE_VERSION < 0x10)
ALGO_INLINE VehLongMotStateExt_t MEDIC_u_GetLongitudinalMotionState(void)
#else
ALGO_INLINE uint8  MEDIC_u_GetLongitudinalMotionState(void)
#endif
{
  #if (MEDIC_ARCHITECTURE_VERSION < 0x10)
  return MEDIC_p_GetVehSig()->VehSigMain.VehLongMotStateExt;
  #else
  #if (MEDIC_CFG_USE_VDY)
  return MEDIC_p_GetVDyInput()->MotionState.MotState;
  #else
  return MEDIC_p_GetVehicleEgoMotion()->egoMotion.motionState.longMotStateOverall;
  #endif
  #endif
} 
#endif // MEDIC_CFG_HYPOTHESIS_EVAL_AND_DECISION

/*************************************************************************************************************************
  Functionname:         MEDIC_p_GetFrameData                                                           */ /*!
  @brief                Returns the const pointer to the MEDIC Frame Data.
  @return               ALGO_INLINE MEDICFrame_t const *
  @glob_in              MEDIC_p_GetWorkingData
  @return               MEDICFrame_t const *
  @author               Nagaraja Veerashettappa  | Nagaraja.Veerashettappa@continental-corporation.com 
*************************************************************************************************************************/
ALGO_INLINE MEDICFrame_t const * MEDIC_p_GetFrameData(void)
{
  return &(MEDIC_p_GetWorkingData()->pInterCycleMeas->sGlobData.MEDIC.MEDICFrame);
}

/*************************************************************************************************************************
  Functionname:         MEDIC_p_ModFrameData                                                           */ /*!
  @brief                Returns the pointer to the MEDIC Frame Data.
  @glob_in              MEDIC_p_GetWorkingData
  @return               MEDICFrame_t *
  @author               Nagaraja Veerashettappa  | Nagaraja.Veerashettappa@continental-corporation.com 
*************************************************************************************************************************/
ALGO_INLINE MEDICFrame_t * MEDIC_p_ModFrameData(void)
{
  return &(MEDIC_p_GetWorkingData()->pInterCycleMeas->sGlobData.MEDIC.MEDICFrame);
}

#if (MEDIC_ARCHITECTURE_VERSION >= 0x10)
/*************************************************************************************************************************
  Functionname:         MEDIC_p_ModAlgoTimestamp                                                                    */ /*!
  @brief                Returns the last available MEDIC algo timestamp in micro-seconds
  @glob_in              MEDICAccessData
  @return               uint64*
  @author               Armin Vogl | armin.vogl@continental-corporation.com
*************************************************************************************************************************/
ALGO_INLINE uint64* MEDIC_p_ModAlgoTimestamp(void)
{
  return &(MEDICAccessData.Working.pInterCycleMeas->sGlobData.MEDIC.uiAlgoTimestamp);
} 

/*************************************************************************************************************************
  Functionname:         MEDIC_p_ModAlgoCycleTime                                                                    */ /*!
  @brief                Returns the pointer to the MEDIC cycle time in micro-seconds
  @glob_in              MEDICAccessData
  @return               uint32*
  @author               Armin Vogl | armin.vogl@continental-corporation.com
*************************************************************************************************************************/
ALGO_INLINE uint32* MEDIC_p_ModAlgoCycleTime(void)
{
  return &(MEDICAccessData.Working.pInterCycleMeas->sGlobData.MEDIC.uiAlgoCycleTime);
}
#endif
/*************************************************************************************************************************
  Functionname:         MEDIC_u_GetOpMode                                                                           */ /*!
  @brief                Returns the MEDIC OpMode
  @return               uint8
  @glob_in              MEDICAccessData
  @author               Armin Vogl | armin.vogl@continental-corporation.com
*************************************************************************************************************************/
ALGO_INLINE uint8 MEDIC_u_GetOpMode(void)
{
  uint8 retValue;
  #if (MEDIC_ARCHITECTURE_VERSION < 0x10)
  /* Check for NULL pointers */
  if (MEDIC_p_GetReqPortList()->pVehCtrlData != NULL)
  {
    #if (MEDIC_CFG_USE_BASECTRLDATA)
    retValue = (MEDIC_p_GetReqPortList()->pVehCtrlData->eOpMode == BASE_OM_RUN) ? MEDIC_MOD_RUNNING : MEDIC_MOD_INIT;
    #else
    retValue = MEDIC_p_GetReqPortList()->pVehCtrlData->OpMode;
    #endif
  }
  else
  {
    /* Set the operation mode to init if an NULL pointer is received. */
    retValue = MEDIC_MOD_INIT;
  }
   return retValue;
  #else
  if (MEDICAccessData.Input.ReqPorts.controlData != NULL)
  {
    #if (MEDIC_CFG_USE_BASECTRLDATA)
    retValue = (MEDICAccessData.Input.ReqPorts.controlData->opMode == BASE_OM_RUN) ? MEDIC_MOD_RUNNING : MEDIC_MOD_INIT;
    #else
    retValue = MEDICAccessData.Input.ReqPorts.controlData->opMode;
    #endif
  }
  else
  {
    retValue = MEDIC_MOD_INIT;
  }
  return retValue;
  #endif
}

/*************************************************************************************************************************
  Functionname:         MEDIC_p_GetSyncRef                                                                         */ /*!
  @brief                Returns the pointer to the MEDIC SyncRef data. 
  @glob_in              @ref MEDIC_p_GetWorkingData
  @return               MEDICSyncRef_t*
  @author               Nagaraja Veerashettappa  | Nagaraja.Veerashettappa@continental-corporation.com 
*************************************************************************************************************************/
ALGO_INLINE MEDICSyncRef_t const * MEDIC_p_GetSyncRef(void)
{
  return &(MEDIC_p_GetWorkingData()->pIntraCycleMeas->sGlobData.MEDIC.MEDICSyncRef);
}

/*************************************************************************************************************************
  Functionname:         MEDIC_p_ModSyncRef                                                           */ /*!
  @brief                Returns the pointer to the MEDIC SyncRef data.
  @glob_in              MEDIC_p_GetWorkingData
  @return               ALGO_INLINE MEDICSyncRef_t 
  @c_switch_full        None
  @author               Nagaraja Veerashettappa  | Nagaraja.Veerashettappa@continental-corporation.com 
*************************************************************************************************************************/
ALGO_INLINE MEDICSyncRef_t* MEDIC_p_ModSyncRef(void)
{
  return &(MEDIC_p_GetWorkingData()->pIntraCycleMeas->sGlobData.MEDIC.MEDICSyncRef);
}

/*************************************************************************************************************************
  Functionname:         MEDIC_p_GetPortHandlerList                                                                         */ /*!
  @brief                Returns the const pointer to list of all port handlers 
  @glob_in              @ref MEDIC_p_GetWorkingData
  @return               MEDICPortHandlerList_t const *
  @author               Nagaraja Veerashettappa  | Nagaraja.Veerashettappa@continental-corporation.com 
*************************************************************************************************************************/
ALGO_INLINE MEDICPortHandlerList_t const * MEDIC_p_GetPortHandlerList(void)
{
  return &(MEDIC_p_GetWorkingData()->pInterCycle->sGlobData.MEDIC.MEDIC_PortHandlerList);
}

/*************************************************************************************************************************
  Functionname:         MEDIC_p_ModPortHandlerList                                                                  */ /*!
  @brief                Returns the mutable pointer to list of all port handlers 
  @glob_in              @ref MEDIC_p_ModWorkingData
  @return               MEDICPortHandlerList_t *
  @author               Nagaraja Veerashettappa  | Nagaraja.Veerashettappa@continental-corporation.com 
*************************************************************************************************************************/
ALGO_INLINE MEDICPortHandlerList_t * MEDIC_p_ModPortHandlerList(void)
{
  return &(MEDIC_p_ModWorkingData()->pInterCycle->sGlobData.MEDIC.MEDIC_PortHandlerList);
}

#if (MEDIC_CFG_HYPOTHESIS_EVAL_AND_DECISION)
/*************************************************************************************************************************
  Functionname:         MEDIC_p_GetCodingParamFctMods                                                               */ /*!
  @brief                Returns a pointer to the coding parameters
  @glob_in              @ref MEDICAccessData
  @return               CPAREBACodingFctMods_t const *
  @author               Armin Vogl | armin.vogl@continental-corporation.com
*************************************************************************************************************************/
ALGO_INLINE CPAREBACodingFctMods_t const * MEDIC_p_GetCodingParamFctMods(void)
{
  #if (MEDIC_ARCHITECTURE_VERSION < 0x10)
  return MEDICAccessData.Input.ReqPorts.pCPAR_FCT_Parameters->EBA.EBACodingParamFctMods;
  #else
  return MEDICAccessData.Input.ReqPorts.medicParameters->CodingParams.CodingParamMods;
  #endif
}

/*************************************************************************************************************************
  Functionname:         MEDIC_u_GetObjectListConfig                                                                 */ /*!
  @brief                Returns eObjListConfig
  @glob_in              @ref MEDICAccessData
  @return               EM_t_GenObjSensorSource
  @author               Armin Vogl | armin.vogl@continental-corporation.com
*************************************************************************************************************************/
#if (MEDIC_ARCHITECTURE_VERSION < 0x10)
ALGO_INLINE EM_t_GenObjSensorSource MEDIC_u_GetObjectListConfig(void)
#else
ALGO_INLINE uint8 MEDIC_u_GetObjectListConfig(void)
#endif
{
  #if (MEDIC_ARCHITECTURE_VERSION < 0x10)
  return MEDIC_p_GetCPARFCTParameters()->EBA.eObjListConfig;
  #else
  return MEDICAccessData.Input.ReqPorts.medicParameters->CodingParams.eObjListConfig;
  #endif
}

/*************************************************************************************************************************
  Functionname:         MEDIC_u_GetFunctionSwitch                                                                   */ /*!
  @brief                Returns the function switch
  @glob_in              @ref MEDICAccessData
  @return               eFunctionSwitch_t
  @author               Armin Vogl | armin.vogl@continental-corporation.com
*************************************************************************************************************************/
ALGO_INLINE eFunctionSwitch_t MEDIC_u_GetFunctionSwitch(void)
{
  #if (MEDIC_ARCHITECTURE_VERSION < 0x10)
  return MEDIC_p_GetHeadInGeneric()->eFunctionSwitch;
  #else
  return MEDICAccessData.Input.ReqPorts.switches->eFunctionSwitch;
  #endif
}

/*************************************************************************************************************************
  Functionname:         MEDIC_e_GetMainSwitch                                                                       */ /*!
  @brief                Returns the main switch
  @glob_in              @ref MEDICAccessData
  @return               eMainSwitch_t
  @author               Armin Vogl | armin.vogl@continental-corporation.com
*************************************************************************************************************************/
ALGO_INLINE eMainSwitch_t MEDIC_e_GetMainSwitch(void)
{
  #if (MEDIC_ARCHITECTURE_VERSION < 0x10)
  return MEDIC_p_GetHeadInGeneric()->eMainSwitch;
  #else
  return MEDICAccessData.Input.ReqPorts.switches->eMainSwitch;
  #endif
}

/*************************************************************************************************************************
  Functionname:         MEDIC_e_GetDriverBraking                                                                 */ /*!
  @brief                Returns if the driver is braking 
  @glob_in              @ref MEDICAccessData.Input.ReqPorts
  @return               FCTStateSig_t
  @author               Armin Vogl | armin.vogl@continental-corporation.com
*************************************************************************************************************************/
ALGO_INLINE FCTStateSig_t MEDIC_e_GetDriverBraking(void)
{
  #if (MEDIC_ARCHITECTURE_VERSION < 0x10)
  return MEDICAccessData.Input.ReqPorts.pDIMInputGeneric->eDriverBraking;
  #else
  return MEDICAccessData.Input.ReqPorts.vehicle->eDriverBraking;
  #endif
}

/*************************************************************************************************************************
  Functionname:         MEDIC_e_GetTurnIndicator                                                                  */ /*!
  @brief                Returns the turn indicator value
  @glob_in              @ref MEDICAccessData.Input.ReqPorts
  @return               eTurnIndicator
  @author               Armin Vogl | armin.vogl@continental-corporation.com
*************************************************************************************************************************/
ALGO_INLINE eTurnIndicator_t MEDIC_e_GetTurnIndicator(void)
{
  #if (MEDIC_ARCHITECTURE_VERSION < 0x10)
  return MEDICAccessData.Input.ReqPorts.pDIMInputGeneric->eTurnIndicator;
  #else
  return MEDICAccessData.Input.ReqPorts.vehicle->eTurnIndicator;
  #endif
}

/*************************************************************************************************************************
  Functionname:         MEDIC_f_GetSteeringWheelAngle                                                             */ /*!
  @brief                Returns the steering wheel angle
  @glob_in              @ref MEDICAccessData.Input.ReqPorts
  @return               float32
  @author               Armin Vogl | armin.vogl@continental-corporation.com
*************************************************************************************************************************/
ALGO_INLINE float32 MEDIC_f_GetSteeringWheelAngle(void)
{
  #if (MEDIC_ARCHITECTURE_VERSION < 0x10)
  return MEDICAccessData.Input.ReqPorts.pDIMInputGeneric->fSteeringWheelAngle;
  #else
  return MEDICAccessData.Input.ReqPorts.vehicle->fSteeringWheelAngle;
  #endif
}

/*************************************************************************************************************************
  Functionname:         MEDIC_e_GetSteeringWheelAngleState                                                        */ /*!
  @brief                Returns the steering wheel angle state
  @glob_in              @ref MEDICAccessData.Input.ReqPorts
  @return               DIMInputSignalState_t
  @author               Armin Vogl | armin.vogl@continental-corporation.com
*************************************************************************************************************************/
ALGO_INLINE DIMInputSignalState_t MEDIC_e_GetSteeringWheelAngleState(void)
{
  #if (MEDIC_ARCHITECTURE_VERSION < 0x10)
  return MEDICAccessData.Input.ReqPorts.pDIMInputGeneric->eSteeringWheelAngleStat;
  #else
  return MEDICAccessData.Input.ReqPorts.vehicle->eSteeringWheelAngleStat;
  #endif
}

/*************************************************************************************************************************
  Functionname:         MEDIC_f_GetSteeringWheelAngleGrad                                                               */ /*!
  @brief                Returns the steering wheel angle gradient
  @glob_in              @ref MEDICAccessData.Input.ReqPorts
  @return               float32
  @author               Armin Vogl | armin.vogl@continental-corporation.com
*************************************************************************************************************************/
ALGO_INLINE float32 MEDIC_f_GetSteeringWheelAngleGrad(void)
{
  #if (MEDIC_ARCHITECTURE_VERSION < 0x10)
  return MEDICAccessData.Input.ReqPorts.pDIMInputGeneric->fSteeringWheelAngleGrad;
  #else
  return MEDICAccessData.Input.ReqPorts.vehicle->fSteeringWheelAngleGrad;
  #endif
}

/*************************************************************************************************************************
  Functionname:         MEDIC_e_GetSteeringWheelAngleGradState                                                          */ /*!
  @brief                Returns the steering wheel angle gradient state
  @glob_in              @ref MEDICAccessData.Input.ReqPorts
  @return               DIMInputSignalState_t
  @author               Armin Vogl | armin.vogl@continental-corporation.com
*************************************************************************************************************************/
ALGO_INLINE DIMInputSignalState_t MEDIC_e_GetSteeringWheelAngleGradState(void)
{
  #if (MEDIC_ARCHITECTURE_VERSION < 0x10)
  return MEDICAccessData.Input.ReqPorts.pDIMInputGeneric->eSteeringWheelAngleGradStat;
  #else
  return MEDICAccessData.Input.ReqPorts.vehicle->eSteeringWheelAngleGradStat;
  #endif
}

/*************************************************************************************************************************
  Functionname:         MEDIC_e_GetAccelerationPedalState()                                                          */ /*!
  @brief                Returns accelerator pedal position state
  @glob_in              @ref MEDICAccessData.Input.ReqPorts
  @return               DIMInputSignalState_t
  @author               Armin Vogl | armin.vogl@continental-corporation.com
*************************************************************************************************************************/
ALGO_INLINE DIMInputSignalState_t MEDIC_e_GetAccelerationPedalState(void)
{
  #if (MEDIC_ARCHITECTURE_VERSION < 0x10)
  return MEDICAccessData.Input.ReqPorts.pDIMInputGeneric->eAccelPadelStat;
  #else
  return MEDICAccessData.Input.ReqPorts.vehicle->eAccelPedalStat;
  #endif
}

/*************************************************************************************************************************
  Functionname:         MEDIC_f_GetAccelerationPedalPosition                                                      */ /*!
  @brief                Returns the acceleration pedal position 
  @glob_in              @ref MEDICAccessData.Input.ReqPorts
  @return               float32
  @author               Armin Vogl | armin.vogl@continental-corporation.com
*************************************************************************************************************************/
ALGO_INLINE float32 MEDIC_f_GetAccelerationPedalPosition(void)
{
  #if (MEDIC_ARCHITECTURE_VERSION < 0x10)
  return MEDICAccessData.Input.ReqPorts.pDIMInputGeneric->fAccelPedalPos;
  #else
  return MEDICAccessData.Input.ReqPorts.vehicle->fAccelPedalPos;
  #endif
}

/*************************************************************************************************************************
  Functionname:         MEDIC_e_GetAccelerationPedalGradState                                                          */ /*!
  @brief                Returns the accelerator pedal position gradient state
  @glob_in              @ref MEDICAccessData.Input.ReqPorts
  @return               DIMInputSignalState_t
  @author               Armin Vogl | armin.vogl@continental-corporation.com
*************************************************************************************************************************/
ALGO_INLINE DIMInputSignalState_t MEDIC_e_GetAccelerationPedalGradState(void)
{
  #if (MEDIC_ARCHITECTURE_VERSION < 0x10)
  return MEDICAccessData.Input.ReqPorts.pDIMInputGeneric->eAccelPadelGradStat;
  #else
  return MEDICAccessData.Input.ReqPorts.vehicle->eAccelPedalGradStat;
  #endif
}

/*************************************************************************************************************************
  Functionname:         MEDIC_f_GetAccelerationPedalPositionGrad()                                                        */ /*!
  @brief                Returns the acceleration pedal position gradient
  @glob_in              @ref MEDICAccessData.Input.ReqPorts
  @return               float32
  @author               Armin Vogl | armin.vogl@continental-corporation.com
*************************************************************************************************************************/
ALGO_INLINE float32 MEDIC_f_GetGradAccelerationPedalPosition(void)
{
  #if (MEDIC_ARCHITECTURE_VERSION < 0x10)
  return MEDICAccessData.Input.ReqPorts.pDIMInputGeneric->fAccelPedalGrad;
  #else
  return MEDICAccessData.Input.ReqPorts.vehicle->fAccelPedalGrad;
  #endif
}

#if (MEDIC_ARCHITECTURE_VERSION >= 0x10)

/*************************************************************************************************************************
  Functionname:         MEDIC_f_GetSpeedLimitStatus()                                                        */ /*!
  @brief                Returns the speedlimiter status
  @glob_in              @ref MEDICAccessData.Input.ReqPorts
  @return               FCTStateSig_t
  @author               Armin Vogl | armin.vogl@continental-corporation.com
*************************************************************************************************************************/
ALGO_INLINE FCTStateSig_t MEDIC_f_GetSpeedLimitStatus(void)
{
  return MEDIC_p_GetReqPortList()->vehicle->eSpeedLimitActive;
}

/*************************************************************************************************************************
  Functionname:         MEDIC_b_GetKickdown()                                                        */ /*!
  @brief                Returns the kickdown status
  @glob_in              @ref MEDICAccessData.Input.ReqPorts
  @return               boolean
  @author               Armin Vogl | armin.vogl@continental-corporation.com
*************************************************************************************************************************/
ALGO_INLINE boolean MEDIC_b_GetKickdown(void)
{
  return MEDIC_p_GetReqPortList()->vehSig->VehSigAdd.KickDown;
}

/*************************************************************************************************************************
  Functionname:         MEDIC_e_DriverOverride()                                                        */ /*!
  @brief                Returns the driver override status
  @glob_in              @ref MEDICAccessData.Input.ReqPorts
  @return               uint
  @author               Armin Vogl | armin.vogl@continental-corporation.com
*************************************************************************************************************************/
ALGO_INLINE uint32 MEDIC_e_DriverOverride(void)
{
  return MEDIC_p_GetReqPortList()->vehicle->eDriverOverride;
}

/*************************************************************************************************************************
  Functionname:         MEDIC_f_GetDrvHeadPosX                                                                */ /*!
  @brief                Returns ptr to Head Position X value
  @return               float32 *
  @author               Armin Vogl | armin.vogl@continental-corporation.com
*************************************************************************************************************************/ 
ALGO_INLINE const float32 * MEDIC_p_GetDrvHeadPosX(void)
{
  return (&(MEDIC_p_GetInput()->ReqPorts.driverMonitor->fHeadPositionX));
}

/*************************************************************************************************************************
  Functionname:         MEDIC_p_GetDrvHeadPosY                                                                */ /*!
  @brief                Returns the pointer to the Head Position Y value
  @return               float32 *
  @author               Armin Vogl | armin.vogl@continental-corporation.com
*************************************************************************************************************************/ 
ALGO_INLINE const float32 * MEDIC_p_GetDrvHeadPosY(void)
{
  return (&(MEDIC_p_GetInput()->ReqPorts.driverMonitor->fHeadPositionY));
}

/*************************************************************************************************************************
  Functionname:         MEDIC_p_GetDrvHeadPosZ                                                                */ /*!
  @brief                Returns the pointer to the Head Position Z value
  @return               float32 *
  @author               Armin Vogl | armin.vogl@continental-corporation.com
*************************************************************************************************************************/ 
ALGO_INLINE const float32 * MEDIC_p_GetDrvHeadPosZ(void)
{
  return (&(MEDIC_p_GetInput()->ReqPorts.driverMonitor->fHeadPositionZ));
}

/*************************************************************************************************************************
  Functionname:         MEDIC_p_GetDrvHeadOrientationYaw                                                                */ /*!
  @brief                Returns the pointer to the Head Orientation Yaw value
  @return               float32*
  @author               Armin Vogl | armin.vogl@continental-corporation.com
*************************************************************************************************************************/ 
ALGO_INLINE const float32 * MEDIC_p_GetDrvHeadOrientationYaw(void)
{
  return (&(MEDIC_p_GetInput()->ReqPorts.driverMonitor->fHeadOrientationYaw));
}

/*************************************************************************************************************************
  Functionname:         MEDIC_p_GetDrvHeadOrientationPitch                                                                */ /*!
  @brief                Returns the pointer to the Head Orientation Pitch value
  @return               float32*
  @author               Armin Vogl | armin.vogl@continental-corporation.com
*************************************************************************************************************************/ 
ALGO_INLINE const float32 * MEDIC_p_GetDrvHeadOrientationPitch(void)
{
  return (&(MEDIC_p_GetInput()->ReqPorts.driverMonitor->fHeadOrientationPitch));
}

/*************************************************************************************************************************
  Functionname:         MEDIC_p_GetDrvHeadOrientationRoll                                                                */ /*!
  @brief                Returns the pointer to the Head Orientation Roll value
  @return               float32*
  @author               Armin Vogl | armin.vogl@continental-corporation.com
*************************************************************************************************************************/ 
ALGO_INLINE const float32 * MEDIC_p_GetDrvHeadOrientationRoll(void)
{
  return (&(MEDIC_p_GetInput()->ReqPorts.driverMonitor->fHeadOrientationRoll));
}

/*************************************************************************************************************************
  Functionname:         MEDIC_p_GetDrvGazeDirX                                                                */ /*!
  @brief                Returns the pointer to the gaze direction X value
  @return               float32* 
  @author               Armin Vogl | armin.vogl@continental-corporation.com
*************************************************************************************************************************/ 
ALGO_INLINE const float32 * MEDIC_p_GetDrvGazeDirX(void)
{
  return (&(MEDIC_p_GetInput()->ReqPorts.driverMonitor->fGazeDirectionX));
}

/*************************************************************************************************************************
  Functionname:         MEDIC_p_GetDrvGazeDirY                                                                */ /*!
  @brief                Returns the pointer to the gaze direction Y value
  @return               float32* 
  @author               Armin Vogl | armin.vogl@continental-corporation.com
*************************************************************************************************************************/ 
ALGO_INLINE const float32 * MEDIC_p_GetDrvGazeDirY(void)
{
  return (&(MEDIC_p_GetInput()->ReqPorts.driverMonitor->fGazeDirectionY));
}

/*************************************************************************************************************************
  Functionname:         MEDIC_p_GetDrvGazeDirZ                                                                */ /*!
  @brief                Returns the pointer to the gaze direction Z value
  @return               float32* 
  @author               Armin Vogl | armin.vogl@continental-corporation.com
*************************************************************************************************************************/ 
ALGO_INLINE const float32 * MEDIC_p_GetDrvGazeDirZ(void)
{
  return (&(MEDIC_p_GetInput()->ReqPorts.driverMonitor->fGazeDirectionZ));
}

/*************************************************************************************************************************
  Functionname:         MEDIC_p_GetDrvFatigueLvl                                                                */ /*!
  @brief                Returns the pointer to the Fatigue level value
  @return               MEDIC_eFatigueLevel* 
  @author               Armin Vogl | armin.vogl@continental-corporation.com
*************************************************************************************************************************/ 
ALGO_INLINE const MEDIC_eFatigueLevel * MEDIC_p_GetDrvFatigueLvl(void)
{
  return (&(MEDIC_p_GetInput()->ReqPorts.driverMonitor->eFatigueLevel));
}

/*************************************************************************************************************************
  Functionname:         MEDIC_p_GetDrvMultitaskingLvl                                                                */ /*!
  @brief                Returns the pointer to the multitasking level value
  @return               MEDIC_eMultitaskingLevel* 
  @author               Armin Vogl | armin.vogl@continental-corporation.com
*************************************************************************************************************************/ 
ALGO_INLINE const MEDIC_eMultitaskingLevel * MEDIC_p_GetDrvMultitaskingLvl(void)
{
  return (&(MEDIC_p_GetInput()->ReqPorts.driverMonitor->eMultitaskingLevel));
}

/*************************************************************************************************************************
  Functionname:         MEDIC_p_GetDrvConverationLvl                                                                */ /*!
  @brief                Returns the pointer to the conversation level value
  @return               MEDIC_eConversationLevel* 
  @author               Armin Vogl | armin.vogl@continental-corporation.com
*************************************************************************************************************************/ 
ALGO_INLINE const MEDIC_eConversationLevel * MEDIC_p_GetDrvConverationLvl(void)
{
  return (&(MEDIC_p_GetInput()->ReqPorts.driverMonitor->eConversationLevel));
}

/*************************************************************************************************************************
  Functionname:         MEDIC_p_GetDrvHeadPosConf                                                                */ /*!
  @brief                Returns the pointer to the head position confidence value
  @return               MEDIC_eHeadPosConfidence* 
  @author               Armin Vogl | armin.vogl@continental-corporation.com
*************************************************************************************************************************/ 
ALGO_INLINE const MEDIC_eHeadPosConfidence * MEDIC_p_GetDrvHeadPosConf(void)
{
  return (&(MEDIC_p_GetInput()->ReqPorts.driverMonitor->eHeadPosConfidence));
}

/*************************************************************************************************************************
  Functionname:         MEDIC_p_GetDrvGazeDirConf                                                                */ /*!
  @brief                Returns the pointer to the gaze direction confidence value
  @return               MEDIC_eGazeDirConfidence* 
  @author               Armin Vogl | armin.vogl@continental-corporation.com
*************************************************************************************************************************/ 
ALGO_INLINE const MEDIC_eGazeDirConfidence * MEDIC_p_GetDrvGazeDirConf(void)
{
  return (&(MEDIC_p_GetInput()->ReqPorts.driverMonitor->eGazeDirConfidence));
}
#endif

/*************************************************************************************************************************
  Functionname:         MEDIC_b_GetACCActive()                                                                      */ /*!
  @brief                Returns if ACC is active
  @glob_in              @ref MEDICAccessData.Input.ReqPorts
  @return               boolean
  @author               Armin Vogl | armin.vogl@continental-corporation.com
*************************************************************************************************************************/
ALGO_INLINE boolean MEDIC_b_GetACCActive(void)
{
  #if (MEDIC_ARCHITECTURE_VERSION < 0x10)
  return MEDIC_p_GetDIMInGeneric()->bACCActive;
  #else
  return MEDICAccessData.Input.ReqPorts.vehicle->bACCActive;
  #endif
}

/*************************************************************************************************************************
  Functionname:         MEDIC_e_GetDriverSetting()                                                                  */ /*!
  @brief                Returns the driver setting
  @glob_in              @ref MEDICAccessData.Input.ReqPorts
  @return               eDriverSetting_t
  @author               Armin Vogl | armin.vogl@continental-corporation.com
*************************************************************************************************************************/
ALGO_INLINE eDriverSetting_t MEDIC_e_GetDriverSetting(void)
{
  #if (MEDIC_ARCHITECTURE_VERSION < 0x10)
  return MEDIC_p_GetDIMInGeneric()->eDriverSetting;
  #else
  return MEDICAccessData.Input.ReqPorts.switches->eDriverSetting;
  #endif
}

#if (MEDIC_ARCHITECTURE_VERSION < 0x10)
/*************************************************************************************************************************
  Functionname:         MEDIC_e_GetObjectListConfiguration                                                        */ /*!
  @brief                Returns the object list configuration
  @glob_in              @ref MEDICAccessData.Input.ReqPorts
  @return               EM_t_GenObjSensorSource
  @author               Armin Vogl | armin.vogl@continental-corporation.com
*************************************************************************************************************************/
ALGO_INLINE EM_t_GenObjSensorSource MEDIC_e_GetObjectListConfiguration(void)
{
  return MEDICAccessData.Input.ReqPorts.pCPAR_FCT_Parameters->EBA.eObjListConfig;
}
#endif 

/*************************************************************************************************************************
  Functionname:         MEDIC_b_GetCodingParamValid()                                                               */ /*!
  @brief                Returns if the coding parameters are valid
  @glob_in              @ref MEDICAccessData.Input.ReqPorts
  @return               boolean
  @author               Armin Vogl | armin.vogl@continental-corporation.com
*************************************************************************************************************************/
ALGO_INLINE boolean MEDIC_b_GetCodingParamValid(void)
{
  #if (MEDIC_ARCHITECTURE_VERSION < 0x10)
  return MEDICAccessData.Input.ReqPorts.pCPAR_FCT_Parameters->EBA.EBACodingParamValid;
  #else
  return MEDICAccessData.Input.ReqPorts.medicParameters->CodingParams.CodingParamValid;
  #endif
}

/*************************************************************************************************************************
  Functionname:         MEDIC_u_GetCodingParamGen()                                                                 */ /*!
  @brief                Returns EBACodingParamGen
  @glob_in              @ref MEDICAccessData.Input.ReqPorts
  @return               EBACodingParamGen_t
  @author               Armin Vogl | armin.vogl@continental-corporation.com
*************************************************************************************************************************/
ALGO_INLINE EBACodingParamGen_t MEDIC_u_GetCodingParamGen(void)
{
  #if (MEDIC_ARCHITECTURE_VERSION < 0x10)
  return MEDICAccessData.Input.ReqPorts.pCPAR_FCT_Parameters->EBA.EBACodingParamGen;
  #else
  return MEDICAccessData.Input.ReqPorts.medicParameters->CodingParams.CodingParamGen;
  #endif
}

/*************************************************************************************************************************
  Functionname:         MEDIC_u_GetCodingParamCustom()                                                                 */ /*!
  @brief                Returns EBACodingParamCustom
  @glob_in              @ref MEDICAccessData.Input.ReqPorts
  @return               EBACodingParamCustom_t
  @author               Sadhanashree Srinivasa  | Sadhanashree.Srinivasa@continental-corporation.com
*************************************************************************************************************************/
ALGO_INLINE EBACodingParamCustom_t MEDIC_u_GetCodingParamCustom(void)
{
#if (MEDIC_ARCHITECTURE_VERSION < 0x10)
  return MEDICAccessData.Input.ReqPorts.pCPAR_FCT_Parameters->EBA.EBACodingParamCustom;
#else
  return MEDICAccessData.Input.ReqPorts.medicParameters->CodingParams.CodingParamCustom;
#endif
}

/*************************************************************************************************************************
  Functionname:         MEDIC_u_GetCodingParHeaderStatus()                                                          */ /*!
  @brief                Returns the status of the coding parameter's signal header
  @glob_in              @ref MEDICAccessData.Input.ReqPorts
  @return               AlgoSignalState_t
  @author               Armin Vogl | armin.vogl@continental-corporation.com
*************************************************************************************************************************/
ALGO_INLINE AlgoSignalState_t MEDIC_u_GetCodingParHeaderStatus(void)
{
  #if (MEDIC_ARCHITECTURE_VERSION < 0x10)
  return MEDIC_p_GetCPARFCTParameters()->sSigHeader.eSigStatus;
  #else
  return MEDICAccessData.Input.ReqPorts.medicParameters->sigHeader.eSigStatus;
  #endif
} 

#endif // (MEDIC_CFG_HYPOTHESIS_EVAL_AND_DECISION)

#if (MEDIC_ARCHITECTURE_VERSION < 0x10)
/*************************************************************************************************************************
  Functionname:         MEDIC_p_GetVDYDynRaw                                                                       */ /*!
  @brief                Gets the Ego vehicle raw data
  @glob_in              MEDIC_pEgoDynRaw
  @return               Ego Dynamic Raw data
  @author               Andreas Kramer|Andreas Kramer@continental-corporation.com
*************************************************************************************************************************/
ALGO_INLINE VehDyn_t const* MEDIC_p_GetVDYDynRaw(void)
{
  return MEDIC_p_GetAccessData()->Input.ReqPorts.pEgoDynRaw;
}
#endif

/*************************************************************************************************************************
  Functionname:         MEDIC_f_GetEgoVelRaw                                                                        */ /*!
  @brief                Gets the corrected longitudinal ego velocity from VDY
  @glob_in              Velocity: defined in Rte_type.h
  @return               Longitudinal velocity
  @author               Andreas Kramer|Andreas Kramer@continental-corporation.com
*************************************************************************************************************************/
ALGO_INLINE float32 MEDIC_f_GetEgoVelRaw(void)
{
  #if (MEDIC_ARCHITECTURE_VERSION < 0x10)
  #if (VDY_VEH_DYN_INTFVER >= 32 || MEDIC_ARCHITECTURE_VERSION >= 0x10)
  return MEDIC_p_GetVDYDynRaw()->Longitudinal.Velocity;
  #else
  return MEDIC_p_GetVDYDynRaw()->Longitudinal.VeloCorr.corrVelo;
  #endif
  #else
  #if (MEDIC_CFG_USE_VDY)
  return MEDIC_p_GetVDyInput()->Longitudinal.Velocity;
  #else
  return MEDIC_p_GetVehicleEgoMotion()->egoMotion.velocityTrans.x.mu;
  #endif
  #endif
}

/*************************************************************************************************************************
  Functionname:         MEDIC_f_GetEgoVelVarianceRaw                                                                */ /*!
  @brief                Gets the corrected longitudinal ego velocity variance from VDY
  @glob_in              Velocity Variance: defined in Rte_type.h
  @return               Longitudinal velocity variance
  @author               Armin Vogl|Armin.Vogl@continental-corporation.com
*************************************************************************************************************************/
ALGO_INLINE float32 MEDIC_f_GetEgoVelVarianceRaw(void)
{
  #if (MEDIC_ARCHITECTURE_VERSION < 0x10)
  #if (VDY_VEH_DYN_INTFVER >= 32 || MEDIC_ARCHITECTURE_VERSION >= 0x10)
  return MEDIC_p_GetVDYDynRaw()->Longitudinal.varVelocity;
  #else
  return MEDIC_p_GetVDYDynRaw()->Longitudinal.VeloCorr.corrVeloVar;
  #endif
  #else
  #if (MEDIC_CFG_USE_VDY)
  if (MEDIC_p_GetVDyInput()->Longitudinal.varVelocity > 0.0f)
  {
    return (MEDIC_p_GetVDyInput()->Longitudinal.varVelocity) * (MEDIC_p_GetVDyInput()->Longitudinal.varVelocity);
  }
  else
  {
    return (MEDIC_p_GetVDyInput()->Longitudinal.varVelocity) * (MEDIC_p_GetVDyInput()->Longitudinal.varVelocity);
  }
  #else
  // convert standard deviation to variance; keep sign, since since it gives the value a different meaning (unavailable)
  if (MEDIC_p_GetVehicleEgoMotion()->egoMotion.velocityTrans.x.sig > 0.0f)
  {
    return  (MEDIC_p_GetVehicleEgoMotion()->egoMotion.velocityTrans.x.sig) * (MEDIC_p_GetVehicleEgoMotion()->egoMotion.velocityTrans.x.sig);
  }
  else
  {
    return -(MEDIC_p_GetVehicleEgoMotion()->egoMotion.velocityTrans.x.sig) * (MEDIC_p_GetVehicleEgoMotion()->egoMotion.velocityTrans.x.sig);
  }
  #endif
  #endif
}/* PRQA S 7010 *//* date: 2020-10-21, reviewer:Siri Prakash, reason: suppressing cyclomatic complexity for better code maintainability*/ 

/*************************************************************************************************************************
  Functionname:         MEDIC_f_GetEgoAccelRaw                                                                        */ /*!
  @brief                Gets the Longitudinal Acceleration  
  @glob_in              Accel: Acceleration defined in Rte_Type.h
  @return               Longitudinal Acceleration
  @author               Andreas Kramer|Andreas Kramer@continental-corporation.com
*************************************************************************************************************************/
ALGO_INLINE float32 MEDIC_f_GetEgoAccelRaw(void)
{
  #if (MEDIC_ARCHITECTURE_VERSION < 0x10)
  #if (VDY_VEH_DYN_INTFVER >= 32)
  return MEDIC_p_GetVDYDynRaw()->Longitudinal.Accel;
  #else
  return MEDIC_p_GetVDYDynRaw()->Longitudinal.MotVar.Accel;
  #endif
  #else
  #if (MEDIC_CFG_USE_VDY)
  return MEDIC_p_GetVDyInput()->Longitudinal.Accel;
  #else
  return MEDIC_p_GetVehicleEgoMotion()->egoMotion.accelerationTrans.x.mu;
  #endif
  #endif
}

/*************************************************************************************************************************
  Functionname:         MEDIC_f_GetEgoAccelVarianceRaw                                                                        */ /*!
  @brief                Gets the Longitudinal Acceleration Variance 
  @glob_in              varAccel: Acceleration Variance defined in Rte_Type.h
  @return               Longitudinal Acceleration Variance
  @author               Andreas Kramer|Andreas Kramer@continental-corporation.com
*************************************************************************************************************************/
ALGO_INLINE float32 MEDIC_f_GetEgoAccelVarianceRaw(void)
{
  #if (MEDIC_ARCHITECTURE_VERSION < 0x10)
  #if (VDY_VEH_DYN_INTFVER >= 32)
  return MEDIC_p_GetVDYDynRaw()->Longitudinal.varAccel;
  #else
  return MEDIC_p_GetVDYDynRaw()->Longitudinal.MotVar.varAccel;
  #endif
  #else
  #if (MEDIC_CFG_USE_VDY)
  if (MEDIC_p_GetVDyInput()->Longitudinal.varAccel > 0.0f)
  {
    return  (MEDIC_p_GetVDyInput()->Longitudinal.varAccel) * (MEDIC_p_GetVDyInput()->Longitudinal.varAccel);
  }
  else
  {
    return -(MEDIC_p_GetVDyInput()->Longitudinal.varAccel) * (MEDIC_p_GetVDyInput()->Longitudinal.varAccel);
  }
  #else
  // convert standard deviation to variance; keep sign, since since it gives the value a different meaning (unavailable)
  if (MEDIC_p_GetVehicleEgoMotion()->egoMotion.accelerationTrans.x.sig > 0.0f)
  {
    return  (MEDIC_p_GetVehicleEgoMotion()->egoMotion.accelerationTrans.x.sig) * (MEDIC_p_GetVehicleEgoMotion()->egoMotion.accelerationTrans.x.sig);
  }
  else
  {
    return -(MEDIC_p_GetVehicleEgoMotion()->egoMotion.accelerationTrans.x.sig) * (MEDIC_p_GetVehicleEgoMotion()->egoMotion.accelerationTrans.x.sig);
  }
  #endif
  #endif
}/* PRQA S 7010 *//* date: 2020-10-21, reviewer:Siri Prakash, reason: suppressing cyclomatic complexity for better code maintainability*/ 

/*************************************************************************************************************************
  Functionname:         MEDIC_u_GetIOStateEgoSpeedX                                                                        */ /*!
  @brief                Returns the input/output state of X
  @glob_in              MEDIC_p_GetVDYDynRaw
  @return               VDYIoStateTypes_t
  @author               Andreas Kramer|Andreas Kramer@continental-corporation.com
*************************************************************************************************************************/
ALGO_INLINE VDYIoStateTypes_t MEDIC_u_GetIOStateEgoSpeedX(void)
{
  #if (MEDIC_ARCHITECTURE_VERSION < 0x10)
  #if (VDY_VEH_DYN_INTFVER >= 32 || MEDIC_ARCHITECTURE_VERSION >= 0x10)
  return VDY_GET_IO_STATE(VDY_SOUT_POS_VELOCITY, MEDIC_p_GetVDYDynRaw()->State);
  #else
  return VDY_GET_IO_STATE(VDY_SOUT_POS_VEL, MEDIC_p_GetVDYDynRaw()->State);
  #endif
  #else
  // Interface not clear: where and how to get this from CEM
  return 0u; /* Ego vehicle motion state */
  #endif
}

/*************************************************************************************************************************
  Functionname:         MEDIC_f_GetCurveVariance                                                                    */ /*!
  @brief                Returns the curve variance
  @glob_in              @ref MEDIC_p_GetVDYDynRaw()
  @return               fVariance_t
  @author               Armin Vogl | armin.vogl@continental-corporation.com
*************************************************************************************************************************/
ALGO_INLINE fVariance_t MEDIC_f_GetLateralCurveVariance(void)
{
  #if (MEDIC_ARCHITECTURE_VERSION < 0x10)
  #if (VDY_VEH_DYN_INTFVER >= 32)
  return MEDIC_p_GetVDYDynRaw()->Lateral.Curve.VarCurve;
  #else
  return MEDIC_p_GetVDYDynRaw()->Lateral.Curve.varC0;
  #endif
  #else
  return (fVariance_t)0.0;  // Deactivated in new architecture until CEM provides usable data
  /*
  // convert standard deviation to variance; keep sign, since since it gives the value a different meaning (unavailable)
  if (MEDIC_p_GetVehicleEgoMotion()->localization.curvatureC0.sig > 0.0f)
  {
    return  (MEDIC_p_GetVehicleEgoMotion()->localization.curvatureC0.sig) * (MEDIC_p_GetVehicleEgoMotion()->localization.curvatureC0.sig);
  }
  else
  {
    return -(MEDIC_p_GetVehicleEgoMotion()->localization.curvatureC0.sig) * (MEDIC_p_GetVehicleEgoMotion()->localization.curvatureC0.sig);
  }
  */
  #endif
}

/*************************************************************************************************************************
  Functionname:         MEDIC_f_GetLateralCurve                                                                     */ /*!
  @brief                Returns the curve
  @glob_in              @ref MEDIC_p_GetVDYDynRaw()
  @return               fCurve_t
  @author               Armin Vogl | armin.vogl@continental-corporation.com
*************************************************************************************************************************/
ALGO_INLINE fCurve_t MEDIC_f_GetLateralCurve(void)
{
  #if (MEDIC_ARCHITECTURE_VERSION < 0x10)
  return MEDIC_p_GetVDYDynRaw()->Lateral.Curve.Curve;
  #else
  return MEDIC_p_GetVehicleEgoMotion()->localization.curvatureC0.mu; /*return (fCurve_t)HEAD_DEFAULT_EgoLatCur;*/
  #endif
}

/*************************************************************************************************************************
  Functionname:         MEDIC_u_GetIOStateEgoAccelX                                                                        */ /*!
  @brief                Returns the input/output state of X
  @glob_in              MEDIC_p_GetVDYDynRaw
  @return               VDYIoStateTypes_t
  @author               Andreas Kramer|Andreas Kramer@continental-corporation.com
*************************************************************************************************************************/
ALGO_INLINE VDYIoStateTypes_t MEDIC_u_GetIOStateEgoAccelX(void)
{
  #if (MEDIC_ARCHITECTURE_VERSION < 0x10)
  return VDY_GET_IO_STATE(VDY_SOUT_POS_ACCEL, MEDIC_p_GetVDYDynRaw()->State) ;
  #else
  // Interface not clear: where and how to get this from CEM
  return 0u; /*ego vehicle motion state */
  #endif
}

/*************************************************************************************************************************
  Functionname:         MEDIC_u_GetIOStateEgoAccelY                                                                        */ /*!
  @brief                Returns the input/output state of Y
  @glob_in              MEDIC_p_GetVDYDynRaw
  @return               VDYIoStateTypes_t
  @author               Andreas Kramer|Andreas Kramer@continental-corporation.com
*************************************************************************************************************************/
ALGO_INLINE  VDYIoStateTypes_t  MEDIC_u_GetIOStateEgoAccelY(void)
{
  #if (MEDIC_ARCHITECTURE_VERSION < 0x10)
  #if (VDY_VEH_DYN_INTFVER >= 32)
  return VDY_GET_IO_STATE(VDY_SOUT_POS_LATERALACCEL, MEDIC_p_GetVDYDynRaw()->State) ;
  #else
  return VDY_GET_IO_STATE(VDY_SOUT_POS_LATACC      , MEDIC_p_GetVDYDynRaw()->State) ;
  #endif
  #else
  // Interface not clear: where and how to get this from CEM
  return 0u; /* ego vehicle motion state */
  #endif
}

/*************************************************************************************************************************
  Functionname:         MEDIC_u_GetYawRate                                                                           */ /*!
  @brief                Returns the YawRate
  @glob_in              MEDIC_p_GetVDYDynRaw
  @return               float32
  @author               Armin Vogl|armin.vogl@continental-corporation.com
*************************************************************************************************************************/
ALGO_INLINE float32 MEDIC_u_GetYawRate(void)
{
  #if (MEDIC_ARCHITECTURE_VERSION < 0x10)
  return MEDIC_p_GetVDYDynRaw()->Lateral.YawRate.YawRate;
  #else
  #if (MEDIC_CFG_USE_VDY)
  return MEDIC_p_GetVDyInput()->Lateral.YawRate.YawRate;
  #else
  return MEDIC_p_GetVehicleEgoMotion()->egoMotion.velocityAng.z.mu;
  #endif
  #endif
}

/*************************************************************************************************************************
  Functionname:         MEDIC_f_GetYawRateVariance                                                                  */ /*!
  @brief                Returns the yaw rate variance
  @glob_in              @ref MEDIC_p_GetVDYDynRaw
  @return               float32
  @author               Armin Vogl | armin.vogl@continental-corporation.com
*************************************************************************************************************************/
ALGO_INLINE float32 MEDIC_f_GetYawRateVariance(void)
{
  #if (MEDIC_ARCHITECTURE_VERSION < 0x10)
  return MEDIC_p_GetVDYDynRaw()->Lateral.YawRate.Variance;
  #else
  #if (MEDIC_CFG_USE_VDY)
  if (MEDIC_p_GetVDyInput()->Lateral.YawRate.Variance > 0.0f)
  {
    return (MEDIC_p_GetVDyInput()->Lateral.YawRate.Variance) * (MEDIC_p_GetVDyInput()->Lateral.YawRate.Variance);
  }
  else
  {
    return -(MEDIC_p_GetVDyInput()->Lateral.YawRate.Variance) * (MEDIC_p_GetVDyInput()->Lateral.YawRate.Variance);
  }
  #else
  // convert standard deviation to variance; keep sign, since since it gives the value a different meaning (unavailable)
  if (MEDIC_p_GetVehicleEgoMotion()->egoMotion.velocityAng.z.sig > 0.0f)
  {
    return  (MEDIC_p_GetVehicleEgoMotion()->egoMotion.velocityAng.z.sig) * (MEDIC_p_GetVehicleEgoMotion()->egoMotion.velocityAng.z.sig);
  }
  else
  {
    return -(MEDIC_p_GetVehicleEgoMotion()->egoMotion.velocityAng.z.sig) * (MEDIC_p_GetVehicleEgoMotion()->egoMotion.velocityAng.z.sig);
  }
  #endif
  #endif
}/* PRQA S 7010 *//* date: 2020-10-21, reviewer:Siri Prakash, reason: suppressing cyclomatic complexity for better code maintainability*/ 

/*************************************************************************************************************************
  Functionname:         MEDIC_u_GetIOStateEgoYawRate                                                                        */ /*!
  @brief                Returns the input/output state of X
  @glob_in              MEDIC_p_GetVDYDynRaw
  @return               VDYIoStateTypes_t
  @author               Andreas Kramer|Andreas Kramer@continental-corporation.com
*************************************************************************************************************************/
ALGO_INLINE VDYIoStateTypes_t MEDIC_u_GetIOStateEgoYawRate(void)
{
  #if (MEDIC_ARCHITECTURE_VERSION < 0x10)
  #if (VDY_VEH_DYN_INTFVER >= 32)
  return VDY_GET_IO_STATE(VDY_SOUT_POS_YAWRATE, MEDIC_p_GetVDYDynRaw()->State) ;
  #else
  return VDY_GET_IO_STATE(VDY_SOUT_POS_YWR    , MEDIC_p_GetVDYDynRaw()->State) ;
  #endif
  #else
  // Interface not clear: where and how to get this from CEM
  return 0u; /*ego vehicle motion state */
  #endif
}

/*************************************************************************************************************************
  Functionname:         MEDIC_u_GetIOStateEgoCurve                                                                        */ /*!
  @brief                Returns the input/output state of X
  @glob_in              MEDIC_p_GetVDYDynRaw
  @return               VDYIoStateTypes_t
  @author               Andreas Kramer|Andreas Kramer@continental-corporation.com
*************************************************************************************************************************/
ALGO_INLINE VDYIoStateTypes_t MEDIC_u_GetIOStateEgoCurve(void)
{
  #if (MEDIC_ARCHITECTURE_VERSION < 0x10)
  return VDY_GET_IO_STATE(VDY_SOUT_POS_CURVE, MEDIC_p_GetVDYDynRaw()->State) ;
  #else
  // Interface not clear: where and how to get this from CEM
  return 0u; /* ego vehicle motion state */
  #endif
}

/*************************************************************************************************************************
  Functionname:         MEDIC_u_GetIOStateEgoMotion                                                                        */ /*!
  @brief                Returns the input/output state of X
  @glob_in              MEDIC_p_GetVDYDynRaw
  @return               VDYIoStateTypes_t
  @author               Andreas Kramer|Andreas Kramer@continental-corporation.com
*************************************************************************************************************************/
ALGO_INLINE VDYIoStateTypes_t MEDIC_u_GetIOStateEgoMotion(void)
{
  #if (MEDIC_ARCHITECTURE_VERSION < 0x10)
  #if (VDY_VEH_DYN_INTFVER >= 32)
  return VDY_GET_IO_STATE(VDY_SOUT_POS_MOTIONSTATE, MEDIC_p_GetVDYDynRaw()->State) ;
  #else
  return VDY_GET_IO_STATE(VDY_SOUT_POS_MSTAT      , MEDIC_p_GetVDYDynRaw()->State) ;
  #endif
  #else
  // Interface not clear: where and how to get this from CEM
  return 0u; /* ego vehicle motion state */
  #endif
}

/*************************************************************************************************************************
  Functionname:         MEDIC_u_GetEgoMotionState                                                                   */ /*!
  @brief                Returns The motion state of the vehicle
  @glob_in              MEDIC_p_GetVDYDynRaw
  @return               MotState_t
  @author               Armin Vogl | armin.vogl@continental-corporation.com
*************************************************************************************************************************/
#if (MEDIC_ARCHITECTURE_VERSION < 0x10)
ALGO_INLINE MotState_t MEDIC_u_GetEgoMotionState(void)
#else
ALGO_INLINE uint8 MEDIC_u_GetEgoMotionState(void)
#endif
{
  #if (MEDIC_ARCHITECTURE_VERSION < 0x10)
  return MEDIC_p_GetVDYDynRaw()->MotionState.MotState;
  #else
  #if (MEDIC_CFG_USE_VDY)
  return MEDIC_p_GetVDyInput()->MotionState.MotState;
  #else
  return MEDIC_p_GetVehicleEgoMotion()->egoMotion.motionState.longMotStateOverall;
  #endif
  #endif
}

/************************************************************************/
/* Misc                                                                 */
/************************************************************************/

/*************************************************************************************************************************
  Functionname:         MEDIC_f_GetCycleTime                                                                        */ /*!
  @brief                Returns cycle time in seconds
  @glob_in              None
  @return               float32
  @author               Andreas Kramer|Andreas Kramer@continental-corporation.com
*************************************************************************************************************************/
ALGO_INLINE float32 MEDIC_f_GetCycleTime(void)
{
   #if (MEDIC_ARCHITECTURE_VERSION < 0x10)
   return (MEDIC_CYCLE_TIME);
   #else
   return (float32)(*MEDIC_p_ModAlgoCycleTime() / 1000000.0f); /* PRQA S 1800 *//* date: 2020-10-21, reviewer:Siri Prakash, reason: intended behavior to cast float to uInt. fractional part is neglectible*/ 
   #endif
}

/************************************************************************/
/* Hypothesis                                                           */
/************************************************************************/

#if (MEDIC_CFG_HYPOTHESIS_EVAL_AND_DECISION)

#if (MEDIC_ARCHITECTURE_VERSION < 0x10)
/*************************************************************************************************************************
  Functionname:         MEDIC_p_GetHypothesisIntf                                                           */ /*!
  @brief                Returns CD hypothesis
  @glob_in              @ref MEDIC_p_GetAccessData
  @return               HypothesisIntf_t const*
  @c_switch_full        @ref MEDIC_CFG_HYPOTHESIS_EVAL_AND_DECISION
  @author               Nagaraja Veerashettappa  | Nagaraja.Veerashettappa@continental-corporation.com 
*************************************************************************************************************************/
ALGO_INLINE HypothesisIntf_t const* MEDIC_p_GetHypothesisIntf(void)
#else
ALGO_INLINE ACDC2_HypothesisIntf const* MEDIC_p_GetHypothesisIntf(void)
#endif
{
  #if (MEDIC_ARCHITECTURE_VERSION < 0x10)
  return MEDIC_p_GetAccessData()->Input.ReqPorts.pFCTCDHypotheses;
  #else 
  return MEDIC_p_GetAccessData()->Input.ReqPorts.hypothesis;
  #endif
}

/*************************************************************************************************************************
  Functionname:         MEDIC_p_GetHypothesis                                                                         */ /*!
  @brief                returns CD hypothesis ptr
  @glob_in              MEDIC_p_GetHypothesisIntf
  @return               Hypothesis_t * 
  @author               Andreas Kramer| Andreas Kramer@continental-corporation.com
*************************************************************************************************************************/
#if (MEDIC_ARCHITECTURE_VERSION < 0x10)
ALGO_INLINE Hypothesis_t    const* MEDIC_p_GetHypothesis(const uint8 iHyp)
#else
ALGO_INLINE ACDC2_Hypothesis const* MEDIC_p_GetHypothesis(const uint8 iHyp)
#endif
{
  #if (MEDIC_ARCHITECTURE_VERSION < 0x10)
  /* Check range */
  /* Suppress "Msg(3:3112) This statement has no side-effect - it can be removed"  */ /*PRQA S 3112 1*/
  MEDIC_ASSERT((0 <= iHyp) && (iHyp < MAX_NUM_OF_HYPS)); /*PRQA S 3119*/ /*date: 2020-07-06, Reviewer:Rashmi Ramachandra, Reason: Assert is required for failsafe*/
  return &(MEDIC_p_GetHypothesisIntf()->Hypothesis[iHyp]);
  #else
  /* Check range */
  /* Suppress "Msg(3:3112) This statement has no side-effect - it can be removed"  */ /*PRQA S 3112 1*/
  MEDIC_ASSERT((0 <= iHyp) && (iHyp < MAX_NUM_OF_HYPS)); /*PRQA S 3119*/ /*date: 2020-07-06, Reviewer:Sadhanashree Srinivasa, Reason: Assert used for failsafe*/
  return &(MEDICAccessData.Input.ReqPorts.hypothesis->Hypothesis[iHyp]);
  #endif
}


/*************************************************************************************************************************
  Functionname:         MEDIC_p_GetHypDegradation                                                                         */ /*!
  @brief                returns hypothesis degradation ptr
  @glob_in              MEDIC_p_GetHypothesisIntf
  @return               HypoIntfDegr_t * 
  @author               Armin Vogl | armin.vogl@continental-corporation.com
*************************************************************************************************************************/
#if (MEDIC_ARCHITECTURE_VERSION < 0x10)
ALGO_INLINE HypoIntfDegr_t const* MEDIC_p_GetHypDegradation(void)
{
  return &(MEDIC_p_GetHypothesisIntf()->Degradation);
}
#endif

/*************************************************************************************************************************
  Functionname:         MEDIC_p_GetHypVersionNumber                                                                         */ /*!
  @brief                returns hypothesis Version Number
  @glob_in              MEDIC_p_GetHypothesisIntf
  @return               uint32
  @author               Armin Vogl | armin.vogl@continental-corporation.com
*************************************************************************************************************************/
#if (MEDIC_ARCHITECTURE_VERSION < 0x10)
ALGO_INLINE uint32  MEDIC_p_GetHypVersionNumber(void)
#else
ALGO_INLINE uint32  MEDIC_p_GetHypVersionNumber(void)
#endif
{
  #if (MEDIC_ARCHITECTURE_VERSION < 0x10)
  return (MEDIC_p_GetHypothesisIntf()->uiVersionNumber);
  #else
  return (MEDIC_p_GetHypothesisIntf()->versionNumber);
  #endif
}

/*************************************************************************************************************************
  Functionname:         MEDIC_p_GetHypSigHeader                                                                     */ /*!
  @brief                returns hypothesis Sigheader
  @glob_in              MEDIC_p_GetHypothesisIntf
  @return               SignalHeader_t
  @author               Armin Vogl | armin.vogl@continental-corporation.com
*************************************************************************************************************************/
#if (MEDIC_ARCHITECTURE_VERSION < 0x10)
ALGO_INLINE SignalHeader_t MEDIC_p_GetHypSigHeader(void)
#else
ALGO_INLINE SignalHeader_t MEDIC_p_GetHypSigHeader(void)
#endif
{
  #if (MEDIC_ARCHITECTURE_VERSION < 0x10)
  return (MEDIC_p_GetHypothesisIntf()->sSigHeader);
  #else
  return (MEDIC_p_GetHypothesisIntf()->sigHeader);
  #endif
}

/*************************************************************************************************************************
  Functionname:         MEDIC_p_GetNumOfHyp                                                                         */ /*!
  @brief                returns Number of hypothesis
  @glob_in              MEDIC_p_GetHypothesisIntf
  @return               uint8
  @author               Armin Vogl | armin.vogl@continental-corporation.com
*************************************************************************************************************************/
#if (MEDIC_ARCHITECTURE_VERSION < 0x10)
ALGO_INLINE uint8 MEDIC_p_GetNumOfHyp(void)
#else
ALGO_INLINE uint8 MEDIC_p_GetNumOfHyp(void)
#endif
{
  #if (MEDIC_ARCHITECTURE_VERSION < 0x10)
  return (MEDIC_p_GetHypothesisIntf()->Header.uiNumOfHypotheses);
  #else
  return MAX_NUM_OF_HYPS; // need to be change after update of ACDC interface 
  #endif
}

/*************************************************************************************************************************
  Functionname:         MEDIC_p_GetObjListSrc                                                                         */ /*!
  @brief                returns Object List Source
  @glob_in              MEDIC_p_GetHypothesisIntf
  @return               EM_t_GenObjSensorSource
  @author               Armin Vogl | armin.vogl@continental-corporation.com
*************************************************************************************************************************/
#if (MEDIC_ARCHITECTURE_VERSION < 0x10)
ALGO_INLINE EM_t_GenObjSensorSource const* MEDIC_p_GetObjListSrc(void)
{
  return &(MEDIC_p_GetHypothesisIntf()->Header.eObjListSource);
}
#endif

/*************************************************************************************************************************
  Functionname:         MEDIC_p_GetObjListSrc                                                                         */ /*!
  @brief                returns Object List Degraded
  @glob_in              MEDIC_p_GetHypothesisIntf
  @return               EM_t_GenObjSensorSource
  @author               Armin Vogl | armin.vogl@continental-corporation.com
*************************************************************************************************************************/
#if (MEDIC_ARCHITECTURE_VERSION < 0x10)
ALGO_INLINE EM_t_GenObjSensorSource const* MEDIC_p_GetObjListDeg(void)
{
  return &(MEDIC_p_GetHypothesisIntf()->Header.eObjListDegraded);
}
#endif

/*************************************************************************************************************************
  Functionname:         MEDIC_p_GetEBASignalState                                                           */ /*!
  @brief                Returns EBASignalState_t
  @glob_in              @ref MEDIC_p_GetWorkingData
  @return               EBASignalState_t * 
  @author               Nagaraja Veerashettappa  | Nagaraja.Veerashettappa@continental-corporation.com 
*************************************************************************************************************************/
ALGO_INLINE EBASignalState_t *  MEDIC_p_GetEBASignalState(void)
{
  return &(MEDIC_p_GetWorkingData()->pInterCycleMeas->sGlobData.HEAD.EBASignalState);
}

/*************************************************************************************************************************
  Functionname:         MEDIC_p_GetEBAFctChan                                                           */ /*!
  @brief                Returns EBAFctChan_t
  @glob_in              @ref MEDIC_p_GetWorkingData
  @return               EBAFctChan_t * 
  @author               Nagaraja Veerashettappa  | Nagaraja.Veerashettappa@continental-corporation.com 
*************************************************************************************************************************/
ALGO_INLINE EBAFctChan_t *  MEDIC_p_GetEBAFctChan(void)
{
  return &(MEDIC_p_GetWorkingData()->pInterCycleMeas->sGlobData.HEAD.EBAFctChan);
}

/*************************************************************************************************************************
  Functionname:         HEADCustOutputLocVar                                                                        */ /*!
  @brief                Returns HEADCustOutputLocVar_t
  @glob_in              @ref MEDIC_p_GetWorkingData
  @return               HEADCustOutputLocVar_t
  @author               Nagaraja Veerashettappa  | Nagaraja.Veerashettappa@continental-corporation.com 
*************************************************************************************************************************/
ALGO_INLINE HEADCustOutputLocVar_t *  MEDIC_p_GetHEADCustOutputLocVar(void)
{
  return &(MEDIC_p_GetWorkingData()->pInterCycleMeas->sGlobData.HEAD.HEADCustOutputLocVar);
}

/*************************************************************************************************************************
Functionname:         MEDIC_p_GetHEADInputData                                                                      */ /*!
@brief                Returns HEADInputData_t
@glob_in              @ref MEDIC_p_GetWorkingData
@return               HEADInputData_t
@author               Armin Vogl | armin.vogl@continental-corporation.com
*************************************************************************************************************************/
ALGO_INLINE HEADInputData_t const *  MEDIC_p_GetHEADInputData(void)
{
  return (HEADInputData_t const *)&(MEDIC_p_GetWorkingData()->pInterCycleMeas->sGlobData.HEAD.HEADInputData);
}

/*************************************************************************************************************************
Functionname:         MEDIC_p_ModHEADInputData                                                                      */ /*!
@brief                Returns HEADInputData_t
@glob_in              @ref MEDIC_p_GetWorkingData
@return               HEADInputData_t
@author               Armin Vogl | armin.vogl@continental-corporation.com
*************************************************************************************************************************/
ALGO_INLINE HEADInputData_t * MEDIC_p_ModHEADInputData(void)
{
  return (HEADInputData_t *)&(MEDIC_p_GetWorkingData()->pInterCycleMeas->sGlobData.HEAD.HEADInputData);
}
#endif /*MEDIC_CFG_HYPOTHESIS_EVAL_AND_DECISION*/

#if (MEDIC_CFG_DRIVER_INTENTION_MONITORING)
/*************************************************************************************************************************
  Functionname:         MEDIC_p_GetDIMdata                                                           */ /*!
  @brief                Returns DIMData_t
  @glob_in              @ref MEDIC_p_GetWorkingData
  @return               DIMData_t *
  @author               Nagaraja Veerashettappa  | Nagaraja.Veerashettappa@continental-corporation.com 
*************************************************************************************************************************/
ALGO_INLINE DIMData_t *MEDIC_p_GetDIMData(void)
{
  return &(MEDIC_p_GetWorkingData()->pInterCycleMeas->sGlobData.DIM.DIMData);
}

/*************************************************************************************************************************
  Functionname:         MEDIC_p_GetDimInputGlobal                                                           */ /*!
  @brief                Returns DIMInputDataGlobal_t
  @glob_in              @ref MEDIC_p_GetDIMdata
  @return               DIMInputDataGlobal_t * const
  @author               Nagaraja Veerashettappa  | Nagaraja.Veerashettappa@continental-corporation.com 
*************************************************************************************************************************/
ALGO_INLINE DIMInputDataGlobal_t *MEDIC_p_GetDimInputGlobal(void)
{
  return  &(MEDIC_p_GetDIMData()->DimInputData.Global);
}

/*************************************************************************************************************************
  Functionname:         MEDIC_p_GetDIM_HYPOUT_CAL_DATA_EBA                                                           */ /*!
  @brief                Returns DIM_HYPOUT_CAL_DATA_t
  @glob_in              @ref MEDIC_p_GetWorkingData
  @return               DIM_HYPOUT_CAL_DATA_t *
  @author               Nagaraja Veerashettappa  | Nagaraja.Veerashettappa@continental-corporation.com 
*************************************************************************************************************************/
ALGO_INLINE DIM_HYPOUT_CAL_DATA_t *MEDIC_p_GetDIM_HYPOUT_CAL_DATA_EBA(void)
{
  return &(MEDIC_p_GetWorkingData()->pInterCycleMeas->sGlobData.DIM.DIM_HYPOUT_CAL_DATA_EBA);
}

/*************************************************************************************************************************
  Functionname:         MEDIC_p_GetDIMHypothesisList                                                           */ /*!
  @brief                Returns DIMHypothesisList_t
  @glob_in              @ref MEDIC_p_GetWorkingData
  @return               DIMHypothesisList_t *
  @author               Nagaraja Veerashettappa  | Nagaraja.Veerashettappa@continental-corporation.com 
*************************************************************************************************************************/
ALGO_INLINE DIMHypothesisList_t *MEDIC_p_GetDIMHypothesisList(void)
{
  return &(MEDIC_p_GetWorkingData()->pInterCycleMeas->sGlobData.DIM.DIMHypothesisList);
}

#if (DIM_CFG_CALC_STEERING_ANGLE_GRADIENT)
/*************************************************************************************************************************
  Functionname:         MEDIC_p_GetDimIirFiltSteeringAngle                                                           */ /*!
  @brief                Static differentiator used for the calculation of the DIM steering wheel gradient
  @glob_in              @ref MEDIC_p_GetWorkingData
  @return               DimIirFilt_t *
  @author               Nagaraja Veerashettappa  | Nagaraja.Veerashettappa@continental-corporation.com 
*************************************************************************************************************************/
ALGO_INLINE DimIirFilt_t *  MEDIC_p_GetDimIirFiltSteeringAngle(void)
{
  return &(MEDIC_p_GetWorkingData()->pInterCycleMeas->sGlobData.DIM.DimIirFiltSteeringAngle);
}
#endif /*DIM_CFG_CALC_STEERING_ANGLE_GRADIENT*/

#if (DIM_CFG_CALC_GAS_PEDAL_GRADIENT)
/*************************************************************************************************************************
  Functionname:         MEDIC_p_GetDimIirFiltGasPedal                                                           */ /*!
  @brief                Static differentiator used for the calculation of the DIM gas pedal gradient 
  @glob_in              @ref MEDIC_p_GetWorkingData
  @return               DimIirFilt_t *
  @author               Nagaraja Veerashettappa  | Nagaraja.Veerashettappa@continental-corporation.com 
*************************************************************************************************************************/
ALGO_INLINE DimIirFilt_t *  MEDIC_p_GetDimIirFiltGasPedal(void)
{
  return &(MEDIC_p_GetWorkingData()->pInterCycleMeas->sGlobData.DIM.DimIirFiltGasPedal);
}
#endif/*DIM_CFG_CALC_GAS_PEDAL_GRADIENT*/
#endif /*MEDIC_CFG_DRIVER_INTENTION_MONITORING*/
/************************************************************************/
/* Parameter                                                            */
/************************************************************************/
#if ((MEDIC_CFG_BSW_ALGO_PARAMS) || (MEDIC_CFG_INCLUDE_UNUSED_INTF))

#if (MEDIC_ARCHITECTURE_VERSION < 0x10)
/*************************************************************************************************************************
  Functionname:         MEDIC_p_GetBswAlgoParameters                                                           */ /*!
  @brief                Returns BSW_s_AlgoParameters_t
  @glob_in              @ref MEDIC_p_GetAccessData
  @return               BSW_s_AlgoParameters_t const*
  @c_switch_full        @ref MEDIC_CFG_BSW_ALGO_PARAMS @ref MEDIC_CFG_INCLUDE_UNUSED_INTF
  @author               Nagaraja Veerashettappa  | Nagaraja.Veerashettappa@continental-corporation.com 
*************************************************************************************************************************/
ALGO_INLINE BSW_s_AlgoParameters_t const* MEDIC_p_GetBswAlgoParameters(void)
{
  return  MEDIC_p_GetAccessData()->Input.ReqPorts.pBswAlgoParameters;
}
#endif
#endif /* MEDIC_CFG_BSW_ALGO_PARAMS */
#if (MEDIC_ARCHITECTURE_VERSION >= 0x10)

/*************************************************************************************************************************
  Functionname:         MEDIC_p_GetalgoCompState                                                            */ /*!
  @brief                Returns the Algo component states
  @return               AlgoCompState_t const*
  @glob_in              @ref MEDIC_p_GetAccessData
  @c_switch_full        @ref MEDIC_ARCHITECTURE_VERSION
  @author               Nagaraja Veerashettappa  | Nagaraja.Veerashettappa@continental-corporation.com
*************************************************************************************************************************/
ALGO_INLINE AlgoCompState_t const*  MEDIC_p_GetalgoCompState(void)
{
  return  MEDIC_p_GetAccessData()->Output.ProPorts.algoCompState;
}

/*************************************************************************************************************************
  Functionname:         MEDIC_p_ModalgoCompState                                                            */ /*!
  @brief                Returns the Algo component states 
  @return               AlgoCompState_t *
  @glob_in              @ref MEDIC_p_GetAccessData
  @c_switch_full        @ref MEDIC_ARCHITECTURE_VERSION
  @author               Nagaraja Veerashettappa  | Nagaraja.Veerashettappa@continental-corporation.com
*************************************************************************************************************************/
ALGO_INLINE AlgoCompState_t *  MEDIC_p_ModalgoCompState(void)
{
  return  MEDIC_p_ModAccessData()->Output.ProPorts.algoCompState;
}

/*************************************************************************************************************************
  Functionname:         MEDIC_p_GetbrakeCascades                                                            */ /*!
  @brief                Returns the Brake Cascades value
  @return               MEDIC_t_BrakeCascades const *
  @glob_in              @ref MEDIC_p_GetAccessData
  @c_switch_full        @ref MEDIC_ARCHITECTURE_VERSION
  @author               Nagaraja Veerashettappa  | Nagaraja.Veerashettappa@continental-corporation.com
*************************************************************************************************************************/
ALGO_INLINE MEDIC_t_BrakeCascades const*  MEDIC_p_GetbrakeCascades(void)
{
  return  MEDIC_p_GetAccessData()->Output.ProPorts.brakeCascades;
}

/*************************************************************************************************************************
  Functionname:         MEDIC_p_ModbrakeCascades                                                            */ /*!
  @brief                Returns the Brake Cascades value
  @return               MEDIC_t_BrakeCascades *
  @glob_in              @ref MEDIC_p_ModAccessData
  @c_switch_full        @ref MEDIC_ARCHITECTURE_VERSION
  @author               Nagaraja Veerashettappa  | Nagaraja.Veerashettappa@continental-corporation.com
*************************************************************************************************************************/
ALGO_INLINE MEDIC_t_BrakeCascades *  MEDIC_p_ModbrakeCascades(void)
{
  return  MEDIC_p_ModAccessData()->Output.ProPorts.brakeCascades;
}

/*************************************************************************************************************************
  Functionname:         MEDIC_p_GettrajPlanerCtrlLimits                                                            */ /*!
  @brief                Returns the TrajPlanerControlLimits 
  @return               MEDIC_TargetRequest_t const*
  @glob_in              @ref MEDIC_p_GetAccessData
  @c_switch_full        @ref MEDIC_ARCHITECTURE_VERSION
  @author               Nagaraja Veerashettappa  | Nagaraja.Veerashettappa@continental-corporation.com
*************************************************************************************************************************/
ALGO_INLINE MEDIC_TargetRequest_t const*  MEDIC_p_GettrajPlanerCtrlLimits(void)
{
  return  MEDIC_p_GetAccessData()->Output.ProPorts.trajPlanerCtrlLimits;
}

/*************************************************************************************************************************
  Functionname:         MEDIC_p_ModtrajPlanerCtrlLimits                                                            */ /*!
  @brief                Returns the TrajPlanerControlLimits 
  @return               MEDIC_TargetRequest_t *
  @glob_in              @ref MEDIC_p_ModAccessData
  @c_switch_full        @ref MEDIC_ARCHITECTURE_VERSION 
  @author               Nagaraja Veerashettappa  | Nagaraja.Veerashettappa@continental-corporation.com
*************************************************************************************************************************/
ALGO_INLINE MEDIC_TargetRequest_t *  MEDIC_p_ModtrajPlanerCtrlLimits(void)
{
  return   MEDIC_p_ModAccessData()->Output.ProPorts.trajPlanerCtrlLimits;
}

#if (CFG_MEDIC_OUT_HBA)
/*************************************************************************************************************************
  Functionname:         MEDIC_p_GethbaHydrBrkAss                                                            */ /*!
  @brief                Returns the Hydrolic Break Assist  
  @return               MEDIC_t_HBA const*
  @glob_in              @ref MEDIC_p_GetAccessData
  @c_switch_full        @ref MEDIC_ARCHITECTURE_VERSION  @ref CFG_MEDIC_OUT_HBA
  @author               Nagaraja Veerashettappa  | Nagaraja.Veerashettappa@continental-corporation.com
*************************************************************************************************************************/
ALGO_INLINE MEDIC_t_HBA const*  MEDIC_p_GethbaHydrBrkAss(void)
{
  return MEDIC_p_GetAccessData()->Output.ProPorts.hbaHydrBrkAss;
}

/*************************************************************************************************************************
  Functionname:         MEDIC_p_ModhbaHydrBrkAss                                                            */ /*!
  @brief                Returns the Hydrolic Break Assist  
  @return               MEDIC_t_HBA *
  @glob_in              @ref MEDIC_p_ModAccessData
  @c_switch_full        @ref MEDIC_ARCHITECTURE_VERSION  @ref CFG_MEDIC_OUT_HBA
  @author               Nagaraja Veerashettappa  | Nagaraja.Veerashettappa@continental-corporation.com
*************************************************************************************************************************/
ALGO_INLINE MEDIC_t_HBA * MEDIC_p_ModhbaHydrBrkAss(void)
{
  return MEDIC_p_ModAccessData()->Output.ProPorts.hbaHydrBrkAss;
}
#endif 

#if (CFG_MEDIC_OUT_PREFILL)
/*************************************************************************************************************************
  Functionname:         MEDIC_p_Getprefill                                                            */ /*!
  @brief                Returns the prefill   
  @return               MEDIC_t_Prefill const*
  @glob_in              @ref MEDIC_p_GetAccessData
  @c_switch_full        @ref MEDIC_ARCHITECTURE_VERSION @ref CFG_MEDIC_OUT_PREFILL
  @author               Nagaraja Veerashettappa  | Nagaraja.Veerashettappa@continental-corporation.com
*************************************************************************************************************************/
ALGO_INLINE MEDIC_t_Prefill const*  MEDIC_p_Getprefill(void)
{
  return  MEDIC_p_GetAccessData()->Output.ProPorts.prefill;
}

/*************************************************************************************************************************
  Functionname:         MEDIC_p_Modprefill                                                            */ /*!
  @brief                Returns the prefill
  @return               MEDIC_t_Prefill *
  @glob_in              @ref MEDIC_p_ModAccessData
  @c_switch_full        @ref MEDIC_ARCHITECTURE_VERSION @ref CFG_MEDIC_OUT_PREFILL
  @author               Nagaraja Veerashettappa  | Nagaraja.Veerashettappa@continental-corporation.com
*************************************************************************************************************************/
ALGO_INLINE MEDIC_t_Prefill *  MEDIC_p_Modprefill(void)
{
  return   MEDIC_p_ModAccessData()->Output.ProPorts.prefill;
}
#endif 

#if (CFG_MEDIC_OUT_PREBRAKE)
/*************************************************************************************************************************
  Functionname:         MEDIC_p_GetpreBrake                                                            */ /*!
  @brief                Returns the Prebrake   
  @return               MEDIC_t_PreBrake const*
  @glob_in              @ref MEDIC_p_GetAccessData
  @c_switch_full        @ref MEDIC_ARCHITECTURE_VERSION @ref CFG_MEDIC_OUT_BRAKE
  @author               Nagaraja Veerashettappa  | Nagaraja.Veerashettappa@continental-corporation.com
*************************************************************************************************************************/
ALGO_INLINE MEDIC_t_PreBrake const*  MEDIC_p_GetpreBrake(void)
{
  return  MEDIC_p_GetAccessData()->Output.ProPorts.preBrake;
}

/*************************************************************************************************************************
  Functionname:         MEDIC_p_ModpreBrake                                                            */ /*!
  @brief                Returns the Prebrake
  @return               MEDIC_t_PreBrake *
  @glob_in              @ref MEDIC_p_ModAccessData
  @c_switch_full        @ref MEDIC_ARCHITECTURE_VERSION @ref CFG_MEDIC_OUT_BRAKE
  @author               Nagaraja Veerashettappa  | Nagaraja.Veerashettappa@continental-corporation.com
*************************************************************************************************************************/
ALGO_INLINE MEDIC_t_PreBrake *  MEDIC_p_ModpreBrake(void)
{
  return MEDIC_p_ModAccessData()->Output.ProPorts.preBrake;
}
#endif 

#if (CFG_MEDIC_OUT_WARNINGS)
/*************************************************************************************************************************
  Functionname:         MEDIC_p_Getwarnings                                                            */ /*!
  @brief                Returns the warning levels
  @return               MEDIC_t_Warnings const*
  @glob_in              @ref MEDIC_p_GetAccessData
  @c_switch_full        @ref MEDIC_ARCHITECTURE_VERSION @ref CFG_MEDIC_OUT_WARNING
  @author               Nagaraja Veerashettappa  | Nagaraja.Veerashettappa@continental-corporation.com
*************************************************************************************************************************/
ALGO_INLINE MEDIC_t_Warnings const*  MEDIC_p_Getwarnings(void)
{
  return  MEDIC_p_GetAccessData()->Output.ProPorts.warnings;
}

/*************************************************************************************************************************
  Functionname:         MEDIC_p_Modwarnings                                                            */ /*!
  @brief                Returns the warning levels
  @return               MEDIC_t_Warnings *
  @glob_in              @ref MEDIC_p_ModAccessData
  @c_switch_full        @ref MEDIC_ARCHITECTURE_VERSION @ref CFG_MEDIC_OUT_WARNING
  @author               Nagaraja Veerashettappa  | Nagaraja.Veerashettappa@continental-corporation.com
*************************************************************************************************************************/
ALGO_INLINE MEDIC_t_Warnings *  MEDIC_p_Modwarnings(void)
{
  return   MEDIC_p_ModAccessData()->Output.ProPorts.warnings;
}
#endif 

#if (CFG_MEDIC_OUT_PRECRASH)
/*************************************************************************************************************************
  Functionname:         MEDIC_p_GetpreCrash                                                            */ /*!
  @brief                Returns the PreCrash
  @return               MEDIC_t_PreCrash const* 
  @glob_in              @ref MEDIC_p_GetAccessData
  @c_switch_part        @ref MEDIC_ARCHITECTURE_VERSION @ref CFG_MEDIC_OUT_PRECRASH
  @author               Nagaraja Veerashettappa  | Nagaraja.Veerashettappa@continental-corporation.com
*************************************************************************************************************************/
ALGO_INLINE MEDIC_t_PreCrash const*  MEDIC_p_GetpreCrash(void)
{
  return  MEDIC_p_GetAccessData()->Output.ProPorts.preCrash;
}

/*************************************************************************************************************************
  Functionname:         MEDIC_p_ModpreCrash                                                            */ /*!
  @brief                Returns the PreCrash
  @return               MEDIC_t_PreCrash * 
  @glob_in              @ref MEDIC_p_ModAccessData
  @c_switch_full        @ref MEDIC_ARCHITECTURE_VERSION @ref CFG_MEDIC_OUT_PRECRASH
  @author               Nagaraja Veerashettappa  | Nagaraja.Veerashettappa@continental-corporation.com
*************************************************************************************************************************/
ALGO_INLINE MEDIC_t_PreCrash *  MEDIC_p_ModpreCrash(void)
{
  return   MEDIC_p_ModAccessData()->Output.ProPorts.preCrash;
}
#endif 

#if (CFG_MEDIC_OUT_DRIVEROFFPREV)
/*************************************************************************************************************************
  Functionname:         MEDIC_p_GetdriveOffPrev                                                            */ /*!
  @brief                Returns the DriverOff Prev
  @return               MEDIC_t_DriveOffPrev const* 
  @glob_in              @ref MEDIC_p_GetAccessData
  @c_switch_full        @ref MEDIC_ARCHITECTURE_VERSION @ref CFG_MEDIC_OUT_DRIVEOFF
  @author               Nagaraja Veerashettappa  | Nagaraja.Veerashettappa@continental-corporation.com
*************************************************************************************************************************/
ALGO_INLINE MEDIC_t_DriveOffPrev const*  MEDIC_p_GetdriveOffPrev(void)
{
  return  MEDIC_p_GetAccessData()->Output.ProPorts.driveOffPrev;
}

/*************************************************************************************************************************
  Functionname:         MEDIC_p_ModdriveOffPrev                                                            */ /*!
  @brief                Returns the DriverOff Prev 
  @return               MEDIC_t_DriveOffPrev * 
  @glob_in              @ref MEDIC_p_ModAccessData
  @c_switch_full        @ref MEDIC_ARCHITECTURE_VERSION @ref CFG_MEDIC_OUT_DRIVEOFF
  @author               Nagaraja Veerashettappa  | Nagaraja.Veerashettappa@continental-corporation.com
*************************************************************************************************************************/
ALGO_INLINE MEDIC_t_DriveOffPrev *  MEDIC_p_ModdriveOffPrev(void)
{
  return   MEDIC_p_ModAccessData()->Output.ProPorts.driveOffPrev;
}
#endif 

#if (CFG_MEDIC_OUT_ESA)
/*************************************************************************************************************************
  Functionname:         MEDIC_p_GetsteerAssist                                                            */ /*!
  @brief                Returns the SteerAssist
  @return               MEDIC_t_SteerAssist const* 
  @glob_in              @ref MEDIC_p_GetAccessData
  @c_switch_full        @ref MEDIC_ARCHITECTURE_VERSION @ref CFG_MEDIC_OUT_ESA
  @author               Nagaraja Veerashettappa  | Nagaraja.Veerashettappa@continental-corporation.com
*************************************************************************************************************************/
ALGO_INLINE MEDIC_t_SteerAssist const*  MEDIC_p_GetsteerAssist(void)
{
  return  MEDIC_p_GetAccessData()->Output.ProPorts.steerAssist;
}

/*************************************************************************************************************************
  Functionname:         MEDIC_p_ModsteerAssist                                                            */ /*!
  @brief                Returns the SteerAssist  
  @return               MEDIC_t_SteerAssist * 
  @glob_in              @ref MEDIC_p_ModAccessData
  @c_switch_full        @ref MEDIC_ARCHITECTURE_VERSION @ref CFG_MEDIC_OUT_ESA
  @author               Nagaraja Veerashettappa  | Nagaraja.Veerashettappa@continental-corporation.com
*************************************************************************************************************************/
ALGO_INLINE MEDIC_t_SteerAssist *  MEDIC_p_ModsteerAssist(void)
{
  return   MEDIC_p_ModAccessData()->Output.ProPorts.steerAssist;
}
#endif

#if (CFG_MEDIC_OUT_HYPREACTIONS)
/*************************************************************************************************************************
  Functionname:         MEDIC_p_GethypReactions                                                            */ /*!
  @brief                Returns the hypothesis Reactions
  @return               MEDIC_t_HypReactions_Interf const* 
  @glob_in              @ref MEDIC_p_GetAccessData
  @c_switch_full        @ref MEDIC_ARCHITECTURE_VERSION @ref CFG_MEDIC_OUT_HYP_REACTIONS
  @author               Nagaraja Veerashettappa  | Nagaraja.Veerashettappa@continental-corporation.com
*************************************************************************************************************************/
ALGO_INLINE MEDIC_t_HypReactions_Interf const*  MEDIC_p_GethypReactions(void)
{
  return  MEDIC_p_GetAccessData()->Output.ProPorts.hypReactions;
}

/*************************************************************************************************************************
  Functionname:         MEDIC_p_ModhypReactions                                                            */ /*!
  @brief                Returns the hypothesis Reactions   
  @return               MEDIC_t_HypReactions_Interf * 
  @glob_in              @ref MEDIC_p_ModAccessData
  @c_switch_full        @ref MEDIC_ARCHITECTURE_VERSION @ref CFG_MEDIC_OUT_HYP_REACTIONS
  @author               Nagaraja Veerashettappa  | Nagaraja.Veerashettappa@continental-corporation.com
*************************************************************************************************************************/
ALGO_INLINE MEDIC_t_HypReactions_Interf *  MEDIC_p_ModhypReactions(void)
{
  return MEDIC_p_ModAccessData()->Output.ProPorts.hypReactions;
}
#endif 

#if (CFG_MEDIC_OUT_FCTQUALIFIERS)
/*************************************************************************************************************************
  Functionname:         MEDIC_p_GetfctQualifiers                                                            */ /*!
  @brief                Returns the FCT Qualifiers
  @return               MEDIC_t_FCTQualifiers_Interf const* 
  @glob_in              @ref MEDIC_p_GetAccessData
  @c_switch_full       @ref MEDIC_ARCHITECTURE_VERSION @ref CFG_MEDIC_OUT_QUALIFIERS
  @author               Nagaraja Veerashettappa  | Nagaraja.Veerashettappa@continental-corporation.com
*************************************************************************************************************************/
ALGO_INLINE MEDIC_t_FCTQualifiers_Interf const*  MEDIC_p_GetfctQualifiers(void)
{
  return MEDIC_p_GetAccessData()->Output.ProPorts.fctQualifiers;
}

/*************************************************************************************************************************
  Functionname:         MEDIC_p_ModfctQualifiers                                                            */ /*!
  @brief                Returns the FCT Qualifiers    
  @return               MEDIC_t_FCTQualifiers_Interf * 
  @glob_in              @ref MEDIC_p_ModAccessData
  @c_switch_full        @ref MEDIC_ARCHITECTURE_VERSION @ref CFG_MEDIC_OUT_QUALIFIERS
  @author               Nagaraja Veerashettappa  | Nagaraja.Veerashettappa@continental-corporation.com
*************************************************************************************************************************/
ALGO_INLINE MEDIC_t_FCTQualifiers_Interf *  MEDIC_p_ModfctQualifiers(void)
{
  return MEDIC_p_ModAccessData()->Output.ProPorts.fctQualifiers;
}
#endif 

#if (CFG_MEDIC_OUT_FCTDATA)
/*************************************************************************************************************************
  Functionname:         MEDIC_p_GetfctData                                                            */ /*!
  @brief                Returns the FCT Data    
  @return               MEDIC_t_FCTData_Interf const*
  @glob_in              @ref MEDIC_p_GetAccessData
  @c_switch_full        @ref MEDIC_ARCHITECTURE_VERSION @ref CFG_MEDIC_OUT_QUALIFIERS
  @author               Nagaraja Veerashettappa  | Nagaraja.Veerashettappa@continental-corporation.com
*************************************************************************************************************************/
ALGO_INLINE MEDIC_t_FCTData_Interf const*  MEDIC_p_GetfctData(void)
{
  return  MEDIC_p_GetAccessData()->Output.ProPorts.fctData;
}

/*************************************************************************************************************************
  Functionname:         MEDIC_p_ModfctQualifiers                                                            */ /*!
  @brief                Returns the FCT Qualifiers    
  @return               MEDIC_t_FCTQualifiers_Interf * 
  @glob_in              @ref MEDIC_p_ModAccessData
  @c_switch_full        @ref MEDIC_ARCHITECTURE_VERSION @ref CFG_MEDIC_OUT_QUALIFIERS
  @author               Nagaraja Veerashettappa  | Nagaraja.Veerashettappa@continental-corporation.com
*************************************************************************************************************************/
ALGO_INLINE MEDIC_t_FCTData_Interf *  MEDIC_p_ModfctData(void)
{
  return  MEDIC_p_ModAccessData()->Output.ProPorts.fctData;
}
#endif 

#if (CFG_MEDIC_OUT_TOYOTA)
/*************************************************************************************************************************
  Functionname:         MEDIC_p_GettmcOutput                                                            */ /*!
  @brief                Returns the TMC(Toyota specific output)
  @return               MEDIC_t_TMCOutput_Interf const* 
  @glob_in              @ref MEDIC_p_GetAccessData
  @c_switch_full        @ref MEDIC_ARCHITECTURE_VERSION @ref CFG_MEDIC_OUT_TOYOTA
  @author               Nagaraja Veerashettappa  | Nagaraja.Veerashettappa@continental-corporation.com
*************************************************************************************************************************/
ALGO_INLINE MEDIC_t_TMCOutput_Interf const*  MEDIC_p_GettmcOutput(void)
{
  return  MEDIC_p_GetAccessData()->Output.ProPorts.tmcOutput;
}

/*************************************************************************************************************************
  Functionname:         MEDIC_p_ModtmcOutput                                                            */ /*!
  @brief                Returns the TMC(Toyota specific output)
  @return               MEDIC_t_TMCOutput_Interf * 
  @glob_in              @ref MEDIC_p_ModAccessData
  @c_switch_full        @ref MEDIC_ARCHITECTURE_VERSION @ref CFG_MEDIC_OUT_TOYOTA
  @author               Nagaraja Veerashettappa  | Nagaraja.Veerashettappa@continental-corporation.com
*************************************************************************************************************************/
ALGO_INLINE MEDIC_t_TMCOutput_Interf *  MEDIC_p_ModtmcOutput(void)
{
  return   MEDIC_p_ModAccessData()->Output.ProPorts.tmcOutput;
}
#endif

#if (CFG_MEDIC_OUT_DIMOUTPUT)
/*************************************************************************************************************************
  Functionname:         MEDIC_p_GetdimOutput                                                            */ /*!
  @brief                Returns Dim output  
  @return               MEDIC_t_DIMOutput_Interf const* 
  @glob_in              @ref MEDIC_p_GetAccessData
  @c_switch_full        @ref MEDIC_ARCHITECTURE_VERSION @ref CFG_MEDIC_OUT_DIM
  @author               Nagaraja Veerashettappa  | Nagaraja.Veerashettappa@continental-corporation.com
*************************************************************************************************************************/
ALGO_INLINE MEDIC_t_DIMOutput_Interf const*  MEDIC_p_GetdimOutput(void)
{
  return  MEDIC_p_GetAccessData()->Output.ProPorts.dimOutput;
}

/*************************************************************************************************************************
  Functionname:         MEDIC_p_ModdimOutput                                                            */ /*!
  @brief                Returns Dim output  
  @return               MEDIC_t_DIMOutput_Interf const* 
  @glob_in              @ref MEDIC_p_GetAccessData
  @c_switch_full        @ref MEDIC_ARCHITECTURE_VERSION @ref CFG_MEDIC_OUT_DIM
  @author               Nagaraja Veerashettappa  | Nagaraja.Veerashettappa@continental-corporation.com
*************************************************************************************************************************/
ALGO_INLINE MEDIC_t_DIMOutput_Interf *  MEDIC_p_ModdimOutput(void)
{
  return   MEDIC_p_ModAccessData()->Output.ProPorts.dimOutput;
}
#endif 
#endif /* MEDIC_FSF.500 */

//provide port member level 
#if ((MEDIC_CFG_HYPOTHESIS_EVAL_AND_DECISION)||(MEDIC_CFG_DRIVER_INTENTION_MONITORING)|| (MEDIC_CFG_INCLUDE_UNUSED_INTF)) 
/*************************************************************************************************************************
  Functionname:         MEDIC_p_ModPreStaticWarnfctchan                                                            */ /*!
  @brief                Returns PreStaticWarnfctchan 
  @return               eEBAFctChan_t * 
  @glob_in              @ref MEDIC_p_ModHeadOutCustom @ref MEDIC_p_Modwarnings
  @c_switch_part        @ref MEDIC_ARCHITECTURE_VERSION 
  @author               Nagaraja Veerashettappa  | Nagaraja.Veerashettappa@continental-corporation.com
*************************************************************************************************************************/
ALGO_INLINE   eEBAFctChan_t *MEDIC_p_ModPreStaticWarnfctchan(void)
{ 
  #if (MEDIC_ARCHITECTURE_VERSION < 0x10)
  return &(MEDIC_p_ModHeadOutCustom()->sWarnings.sPreStaticWarning.eFctChan);
  #else
  return &(MEDIC_p_Modwarnings()->sPreStaticWarning.sHypInfo.eFctChan);
  #endif 
}

/*************************************************************************************************************************
  Functionname:         MEDIC_p_ModPreStaticWarnSignal                                                            */ /*!
  @brief                Returns PreStaticWarnSignal 
  @return               eEBASignalState_t * 
  @glob_in              @ref MEDIC_p_ModHeadOutCustom @ref MEDIC_p_Modwarnings
  @c_switch_part        @ref MEDIC_ARCHITECTURE_VERSION 
  @author               Nagaraja Veerashettappa  | Nagaraja.Veerashettappa@continental-corporation.com
*************************************************************************************************************************/
ALGO_INLINE   eEBASignalState_t * MEDIC_p_ModPreStaticWarnSignal(void)
{
  #if (MEDIC_ARCHITECTURE_VERSION < 0x10)
  return &(MEDIC_p_ModHeadOutCustom()->sWarnings.sPreStaticWarning.eSignal);
  #else
  return &(MEDIC_p_Modwarnings()->sPreStaticWarning.sHypInfo.eSignal);
  #endif 
}

/*************************************************************************************************************************
  Functionname:         MEDIC_p_ModPreStaticWarnActiveHyp                                                            */ /*!
  @brief                Returns StaticWarnActiveHyp
  @return               uint8 *
  @glob_in              @ref MEDIC_p_ModHeadOutCustom @ref MEDIC_p_Modwarnings
  @c_switch_part        @ref MEDIC_ARCHITECTURE_VERSION
  @author               Nagaraja Veerashettappa  | Nagaraja.Veerashettappa@continental-corporation.com
*************************************************************************************************************************/
ALGO_INLINE   uint8 * MEDIC_p_ModPreStaticWarnActiveHyp(void)
{
  #if (MEDIC_ARCHITECTURE_VERSION < 0x10)
  return &(MEDIC_p_ModHeadOutCustom()->sWarnings.sPreStaticWarning.uActiveHyp);
  #else
  return &(MEDIC_p_Modwarnings()->sPreStaticWarning.sHypInfo.uActiveHyp);
  #endif 
}

#if (MEDIC_ARCHITECTURE_VERSION >= 0x10)
/*************************************************************************************************************************
  Functionname:         MEDIC_p_ModPreStaticWarnbActive                                                            */ /*!
  @brief                Returns StaticWarnbActive
  @return               boolean *
  @glob_in              @ref MEDIC_p_ModHeadOutCustom @ref MEDIC_p_Modwarnings
  @c_switch_part        @ref MEDIC_ARCHITECTURE_VERSION
  @author               Sadhanashree Srinivasa  | Sadhanashree.Srinivasa@continental-corporation.com
*************************************************************************************************************************/
ALGO_INLINE   boolean * MEDIC_p_ModPreStaticWarnbActive(void)
{
  return &(MEDIC_p_Modwarnings()->sPreStaticWarning.bActive);
}
#endif

/*************************************************************************************************************************
  Functionname:         MEDIC_p_ModAcuteStaticWarnfctchan                                                            */ /*!
  @brief                Returns AcuteStaticWarnfctchan  
  @return               eEBAFctChan_t * 
  @glob_in              @ref MEDIC_p_ModHeadOutCustom @ref MEDIC_p_Modwarnings
  @c_switch_part        @ref MEDIC_ARCHITECTURE_VERSION
  @author               Nagaraja Veerashettappa  | Nagaraja.Veerashettappa@continental-corporation.com
*************************************************************************************************************************/
ALGO_INLINE   eEBAFctChan_t * MEDIC_p_ModAcuteStaticWarnfctchan(void)
{ 
  #if (MEDIC_ARCHITECTURE_VERSION < 0x10)
  return &(MEDIC_p_ModHeadOutCustom()->sWarnings.sAcuteStaticWarning.eFctChan);
  #else
  return &(MEDIC_p_Modwarnings()->sAcuteStaticWarning.sHypInfo.eFctChan);
  #endif 
}

/*************************************************************************************************************************
  Functionname:         MEDIC_p_ModAcuteStaticWarnSignal                                                            */ /*!
  @brief                Returns AcuteStaticWarnSignal 
  @return               eEBASignalState_t *
  @glob_in              @ref MEDIC_p_ModHeadOutCustom @ref MEDIC_p_Modwarnings
  @c_switch_part        @ref MEDIC_ARCHITECTURE_VERSION 
  @author               Nagaraja Veerashettappa  | Nagaraja.Veerashettappa@continental-corporation.com
*************************************************************************************************************************/
ALGO_INLINE   eEBASignalState_t * MEDIC_p_ModAcuteStaticWarnSignal(void)
{
  #if (MEDIC_ARCHITECTURE_VERSION < 0x10)
  return &(MEDIC_p_ModHeadOutCustom()->sWarnings.sAcuteStaticWarning.eSignal);
  #else
  return &(MEDIC_p_Modwarnings()->sAcuteStaticWarning.sHypInfo.eSignal);
  #endif 
}

/*************************************************************************************************************************
  Functionname:         MEDIC_p_ModAcuteStaticWarnActiveHyp                                                            */ /*!
  @brief                Returns AcuteStaticWarnActiveHyp 
  @return               uint8 *
  @glob_in              @ref MEDIC_p_ModHeadOutCustom @ref MEDIC_p_Modwarnings
  @c_switch_part        @ref MEDIC_ARCHITECTURE_VERSION 
  @author               Nagaraja Veerashettappa  | Nagaraja.Veerashettappa@continental-corporation.com
*************************************************************************************************************************/
ALGO_INLINE   uint8 * MEDIC_p_ModAcuteStaticWarnActiveHyp(void)
{
  #if (MEDIC_ARCHITECTURE_VERSION < 0x10)
  return &(MEDIC_p_ModHeadOutCustom()->sWarnings.sAcuteStaticWarning.uActiveHyp);
  #else
  return &(MEDIC_p_Modwarnings()->sAcuteStaticWarning.sHypInfo.uActiveHyp);
  #endif 
}

#if (MEDIC_ARCHITECTURE_VERSION >= 0x10)
/*************************************************************************************************************************
  Functionname:         MEDIC_p_ModAcuteStaticWarnbActive                                                            */ /*!
  @brief                Returns AcuteStaticWarnbActive
  @return               boolean *
  @glob_in              @ref MEDIC_p_ModHeadOutCustom @ref MEDIC_p_Modwarnings
  @c_switch_part        @ref MEDIC_ARCHITECTURE_VERSION
  @author               Sadhanashree Srinivasa  | Sadhanashree.Srinivasa@continental-corporation.com
*************************************************************************************************************************/
ALGO_INLINE   boolean * MEDIC_p_ModAcuteStaticWarnbActive(void)
{
  return &(MEDIC_p_Modwarnings()->sAcuteStaticWarning.bActive);
}
#endif 

/*************************************************************************************************************************
  Functionname:         MEDIC_p_ModPreDynamicWarnfctchan                                                            */ /*!
  @brief                Returns PreDynamicWarnfctchan 
  @return               eEBAFctChan_t *
  @glob_in              @ref MEDIC_p_ModHeadOutCustom @ref MEDIC_p_Modwarnings
  @c_switch_part        @ref MEDIC_ARCHITECTURE_VERSION 
  @author               Nagaraja Veerashettappa  | Nagaraja.Veerashettappa@continental-corporation.com
*************************************************************************************************************************/
ALGO_INLINE   eEBAFctChan_t *MEDIC_p_ModPreDynamicWarnfctchan(void)
{ 
  #if (MEDIC_ARCHITECTURE_VERSION < 0x10)
  return &(MEDIC_p_ModHeadOutCustom()->sWarnings.sPreDynamicWarning.eFctChan);
  #else
  return &(MEDIC_p_Modwarnings()->sPreDynamicWarning.sHypInfo.eFctChan);
  #endif 
}

/*************************************************************************************************************************
  Functionname:         MEDIC_p_ModPreDynamicWarnSignal                                                            */ /*!
  @brief                Returns PreDynamicWarnSignal
  @return               eEBASignalState_t *
  @glob_in              @ref MEDIC_p_ModHeadOutCustom @ref MEDIC_p_Modwarnings
  @c_switch_part        @ref MEDIC_ARCHITECTURE_VERSION
  @author               Nagaraja Veerashettappa  | Nagaraja.Veerashettappa@continental-corporation.com
*************************************************************************************************************************/
ALGO_INLINE   eEBASignalState_t * MEDIC_p_ModPreDynamicWarnSignal(void)
{
  #if (MEDIC_ARCHITECTURE_VERSION < 0x10)
  return &(MEDIC_p_ModHeadOutCustom()->sWarnings.sPreDynamicWarning.eSignal);
  #else
  return &(MEDIC_p_Modwarnings()->sPreDynamicWarning.sHypInfo.eSignal);
  #endif 
}

/*************************************************************************************************************************
  Functionname:         MEDIC_p_ModPreDynamicWarnActiveHyp                                                            */ /*!
  @brief                Returns PreDynamicWarnActiveHyp
  @return               uint8 *
  @glob_in              @ref MEDIC_p_ModHeadOutCustom @ref MEDIC_p_Modwarnings
  @c_switch_part        @ref MEDIC_ARCHITECTURE_VERSION
  @author               Nagaraja Veerashettappa  | Nagaraja.Veerashettappa@continental-corporation.com
*************************************************************************************************************************/
ALGO_INLINE   uint8 * MEDIC_p_ModPreDynamicWarnActiveHyp(void)
{
  #if (MEDIC_ARCHITECTURE_VERSION < 0x10)
  return &(MEDIC_p_ModHeadOutCustom()->sWarnings.sPreDynamicWarning.uActiveHyp);
  #else
  return &(MEDIC_p_Modwarnings()->sPreDynamicWarning.sHypInfo.uActiveHyp);
  #endif 
}

#if (MEDIC_ARCHITECTURE_VERSION >= 0x10)
/*************************************************************************************************************************
  Functionname:         MEDIC_p_ModPreDynamicWarnbActive                                                            */ /*!
  @brief                Returns PreDynamicWarnbActive
  @return               boolean *
  @glob_in              @ref MEDIC_p_ModHeadOutCustom @ref MEDIC_p_Modwarnings
  @c_switch_part        @ref MEDIC_ARCHITECTURE_VERSION
  @author               Sadhanashree Srinivasa  | Sadhanashree.Srinivasa@continental-corporation.com
*************************************************************************************************************************/
ALGO_INLINE   boolean * MEDIC_p_ModPreDynamicWarnbActive(void)
{
  return &(MEDIC_p_Modwarnings()->sPreDynamicWarning.bActive);
}

/*************************************************************************************************************************
  Functionname:         MEDIC_p_ModAcuteDynamicHaptWarnfctchan                                                            */ /*!
  @brief                Returns AcuteDynamicHaptWarnfctchan
  @return               eEBAFctChan_t *
  @glob_in              @ref MEDIC_p_ModHeadOutCustom @ref MEDIC_p_Modwarnings
  @c_switch_part        @ref MEDIC_ARCHITECTURE_VERSION
  @author               Nagaraja Veerashettappa  | Nagaraja.Veerashettappa@continental-corporation.com
*************************************************************************************************************************/
ALGO_INLINE   eEBAFctChan_t *MEDIC_p_ModAcuteDynamicHaptWarnfctchan(void)
{
  return &(MEDIC_p_Modwarnings()->sAcuteDynamicHaptWarning.sHypInfo.eFctChan);
}

/*************************************************************************************************************************
  Functionname:         MEDIC_p_ModAcuteDynamicHaptWarnSignal                                                            */ /*!
  @brief                Returns AcuteDynamicHaptWarnSignal
  @return               eEBASignalState_t *
  @glob_in              @ref MEDIC_p_ModHeadOutCustom @ref MEDIC_p_Modwarnings
  @c_switch_part        @ref MEDIC_ARCHITECTURE_VERSION
  @author               Nagaraja Veerashettappa  | Nagaraja.Veerashettappa@continental-corporation.com
*************************************************************************************************************************/
ALGO_INLINE   eEBASignalState_t * MEDIC_p_ModAcuteDynamicHaptWarnSignal(void)
{
  return &(MEDIC_p_Modwarnings()->sAcuteDynamicHaptWarning.sHypInfo.eSignal);
}

/*************************************************************************************************************************
  Functionname:         MEDIC_p_ModAcuteDynamicHaptWarnActiveHyp                                                            */ /*!
  @brief                Returns AcuteDynamicHaptWarnActiveHyp
  @return               uint8 *
  @glob_in              @ref MEDIC_p_ModHeadOutCustom @ref MEDIC_p_Modwarnings
  @c_switch_part        @ref MEDIC_ARCHITECTURE_VERSION
  @author               Nagaraja Veerashettappa  | Nagaraja.Veerashettappa@continental-corporation.com
*************************************************************************************************************************/
ALGO_INLINE   uint8 * MEDIC_p_ModAcuteDynamicHaptWarnActiveHyp(void)
{
  return &(MEDIC_p_Modwarnings()->sAcuteDynamicHaptWarning.sHypInfo.uActiveHyp);
}

/*************************************************************************************************************************
  Functionname:         MEDIC_p_ModAcuteDynamicHaptWarnLevel                                                            */ /*!
  @brief                Returns AcuteDynamicHaptWarnLevel
  @return               uint8 *
  @glob_in              @ref MEDIC_p_ModHeadOutCustom @ref MEDIC_p_Modwarnings
  @c_switch_part        @ref MEDIC_ARCHITECTURE_VERSION
  @author               Nagaraja Veerashettappa  | Nagaraja.Veerashettappa@continental-corporation.com
*************************************************************************************************************************/
ALGO_INLINE   uint8 * MEDIC_p_ModAcuteDynamicHaptWarnLevel(void)
{
  return &(MEDIC_p_Modwarnings()->sAcuteDynamicHaptWarning.eWarnLevel);
}
#endif
/*************************************************************************************************************************
  Functionname:         MEDIC_p_ModAcuteDynamicWarnfctchan                                                            */ /*!
  @brief                Returns AcuteDynamicWarnfctchan
  @return               eEBAFctChan_t *
  @glob_in              @ref MEDIC_p_ModHeadOutCustom @ref MEDIC_p_Modwarnings
  @c_switch_part        @ref MEDIC_ARCHITECTURE_VERSION 
  @author               Nagaraja Veerashettappa  | Nagaraja.Veerashettappa@continental-corporation.com
*************************************************************************************************************************/
ALGO_INLINE   eEBAFctChan_t *MEDIC_p_ModAcuteDynamicWarnfctchan(void)
{ 
  #if (MEDIC_ARCHITECTURE_VERSION < 0x10)
  return &(MEDIC_p_ModHeadOutCustom()->sWarnings.sAcuteDynamicWarning.eFctChan);
  #else
  return &(MEDIC_p_Modwarnings()->sAcuteDynamicWarning.sHypInfo.eFctChan);
  #endif 
}

/*************************************************************************************************************************
  Functionname:         MEDIC_p_ModAcuteDynamicWarnSignal                                                            */ /*!
  @brief                Returns AcuteDynamicWarnSignal
  @return               eEBASignalState_t *
  @glob_in              @ref MEDIC_p_ModHeadOutCustom @ref MEDIC_p_Modwarnings
  @c_switch_part        @ref MEDIC_ARCHITECTURE_VERSION 
  @author               Nagaraja Veerashettappa  | Nagaraja.Veerashettappa@continental-corporation.com
*************************************************************************************************************************/
ALGO_INLINE   eEBASignalState_t * MEDIC_p_ModAcuteDynamicWarnSignal(void)
{
  #if (MEDIC_ARCHITECTURE_VERSION < 0x10)
  return &(MEDIC_p_ModHeadOutCustom()->sWarnings.sAcuteDynamicWarning.eSignal);
  #else
  return &(MEDIC_p_Modwarnings()->sAcuteDynamicWarning.sHypInfo.eSignal);
  #endif 
}

/*************************************************************************************************************************
  Functionname:         MEDIC_p_ModAcuteDynamicWarnActiveHyp                                                            */ /*!
  @brief                Returns AcuteDynamicWarnActiveHyp
  @return               uint8 *
  @glob_in              @ref MEDIC_p_ModHeadOutCustom @ref MEDIC_p_Modwarnings
  @c_switch_part        @ref MEDIC_ARCHITECTURE_VERSION
  @author               Nagaraja Veerashettappa  | Nagaraja.Veerashettappa@continental-corporation.com
*************************************************************************************************************************/
ALGO_INLINE   uint8 * MEDIC_p_ModAcuteDynamicWarnActiveHyp(void)
{
  #if (MEDIC_ARCHITECTURE_VERSION < 0x10)
  return &(MEDIC_p_ModHeadOutCustom()->sWarnings.sAcuteDynamicWarning.uActiveHyp);
  #else
  return &(MEDIC_p_Modwarnings()->sAcuteDynamicWarning.sHypInfo.uActiveHyp);
  #endif 
}

#if (MEDIC_ARCHITECTURE_VERSION >= 0x10)
/*************************************************************************************************************************
  Functionname:         MEDIC_p_ModAcuteDynamicWarnbActive                                                            */ /*!
  @brief                Returns AcuteDynamicWarnbActive
  @return               boolean *
  @glob_in              @ref MEDIC_p_ModHeadOutCustom @ref MEDIC_p_Modwarnings
  @c_switch_part        @ref MEDIC_ARCHITECTURE_VERSION
  @author               Sadhanashree Srinivasa  | Sadhanashree.Srinivasa@continental-corporation.com
*************************************************************************************************************************/
ALGO_INLINE   boolean * MEDIC_p_ModAcuteDynamicWarnbActive(void)
{
  return &(MEDIC_p_Modwarnings()->sAcuteDynamicWarning.bActive);
}
#endif 

#if (MEDIC_ARCHITECTURE_VERSION >= 0x10)
/*************************************************************************************************************************
  Functionname:         MEDIC_p_ModPrefillLevel                                                                     */ /*!
  @brief                Returns a pointer to the prefill level variable
  @return               uint8 *
  @glob_in              @ref MEDIC_p_ModHeadOutCustom @ref MEDIC_p_Modprefill
  @c_switch_part        @ref MEDIC_ARCHITECTURE_VERSION 
  @author               Armin Vogl  | Armin.Vogl@continental-corporation.com
*************************************************************************************************************************/
ALGO_INLINE uint8 * MEDIC_p_ModPrefillLevel(void)
{ 
  return &(MEDIC_p_Modprefill()->uPrefillLevel);
}
#endif

/*************************************************************************************************************************
  Functionname:         MEDIC_p_ModPrefillfctchan                                                            */ /*!
  @brief                Returns Prefillfctchan
  @return               eEBAFctChan_t  *
  @glob_in              @ref MEDIC_p_ModHeadOutCustom @ref MEDIC_p_Modprefill
  @c_switch_part        @ref MEDIC_ARCHITECTURE_VERSION 
  @author               Nagaraja Veerashettappa  | Nagaraja.Veerashettappa@continental-corporation.com
*************************************************************************************************************************/
ALGO_INLINE   eEBAFctChan_t  * MEDIC_p_ModPrefillfctchan(void)
{ 
  #if (MEDIC_ARCHITECTURE_VERSION < 0x10)
  return &(MEDIC_p_ModHeadOutCustom()->sPrefill.eFctChan);
  #else
  return &(MEDIC_p_Modprefill()->HypInfo.eFctChan);
  #endif 
}

/*************************************************************************************************************************
  Functionname:         MEDIC_p_ModPrefillActive                                                            */ /*!
  @brief                Returns PrefillActive
  @return               boolean *
  @glob_in              @ref MEDIC_p_ModHeadOutCustom @ref MEDIC_p_Modprefill
  @c_switch_part        @ref MEDIC_ARCHITECTURE_VERSION 
  @author               Nagaraja Veerashettappa  | Nagaraja.Veerashettappa@continental-corporation.com
*************************************************************************************************************************/
ALGO_INLINE   boolean * MEDIC_p_ModPrefillActive(void)
{ 
  #if (MEDIC_ARCHITECTURE_VERSION < 0x10)
  return &(MEDIC_p_ModHeadOutCustom()->sPrefill.bPrefillActive);
  #else
  return &(MEDIC_p_Modprefill()->bPrefillActive);
  #endif 
}

/*************************************************************************************************************************
  Functionname:         MEDIC_p_ModPrefillPreRunActive                                                            */ /*!
  @brief                Returns PrefillPreRunActive
  @return               boolean *
  @glob_in              @ref MEDIC_p_ModHeadOutCustom @ref MEDIC_p_Modprefill
  @c_switch_part        @ref MEDIC_ARCHITECTURE_VERSION
  @author               Nagaraja Veerashettappa  | Nagaraja.Veerashettappa@continental-corporation.com
*************************************************************************************************************************/
ALGO_INLINE   boolean * MEDIC_p_ModPrefillPreRunActive(void)
{ 
  #if (MEDIC_ARCHITECTURE_VERSION < 0x10)
  return &(MEDIC_p_ModHeadOutCustom()->sPrefill.bPreRunActive);
  #else
  return &(MEDIC_p_Modprefill()->bPreRunActive);
  #endif 
}

/*************************************************************************************************************************
  Functionname:         MEDIC_p_ModPrefillGeneratorControl                                                         */ /*!
  @brief                Returns PrefillGeneratorControl
  @return               boolean  *
  @glob_in              @ref MEDIC_p_ModHeadOutCustom @ref MEDIC_p_Modprefill
  @c_switch_part        @ref MEDIC_ARCHITECTURE_VERSION 
  @author               Nagaraja Veerashettappa  | Nagaraja.Veerashettappa@continental-corporation.com
*************************************************************************************************************************/
ALGO_INLINE   uint8 * MEDIC_p_ModPrefillGeneratorControl(void)
{ 
  #if (MEDIC_ARCHITECTURE_VERSION < 0x10)
  return &(MEDIC_p_ModHeadOutCustom()->sPrefill.eGeneratorControl);
  #else
  return &(MEDIC_p_Modprefill()->eGeneratorControl);
  #endif 
}

/*************************************************************************************************************************
  Functionname:         MEDIC_p_ModPrefillActiveHyp                                                            */ /*!
  @brief                Returns PrefillActiveHyp
  @return               uint8 *
  @glob_in              @ref MEDIC_p_ModHeadOutCustom @ref MEDIC_p_Modprefill
  @c_switch_part        @ref MEDIC_ARCHITECTURE_VERSION
  @author               Nagaraja Veerashettappa  | Nagaraja.Veerashettappa@continental-corporation.com
*************************************************************************************************************************/
ALGO_INLINE  uint8 * MEDIC_p_ModPrefillActiveHyp(void)
{ 
  #if (MEDIC_ARCHITECTURE_VERSION < 0x10)
  return &(MEDIC_p_ModHeadOutCustom()->sPrefill.uActiveHyp);
  #else
  return &(MEDIC_p_Modprefill()->HypInfo.uActiveHyp);
  #endif 
}

/*************************************************************************************************************************
  Functionname:         MEDIC_p_ModHBADecel                                                            */ /*!
  @brief                Returns HBADecel
  @return               float32 *
  @glob_in              @ref MEDIC_p_ModHeadOutCustom @ref MEDIC_p_ModhbaHydrBrkAss
  @c_switch_part        @ref MEDIC_ARCHITECTURE_VERSION
  @author               Nagaraja Veerashettappa  | Nagaraja.Veerashettappa@continental-corporation.com
*************************************************************************************************************************/
ALGO_INLINE  float32 * MEDIC_p_ModHBADecel(void)
{ 
  #if (MEDIC_ARCHITECTURE_VERSION < 0x10)
  return &(MEDIC_p_ModHeadOutCustom()->sHBA.fHBADecel);
  #else
  return &(MEDIC_p_ModhbaHydrBrkAss()->fHBADecel);
  #endif 
}

/*************************************************************************************************************************
  Functionname:         MEDIC_p_ModHBAActiveHyp                                                            */ /*!
  @brief                Returns HBAActiveHyp
  @return               uint8 *
  @glob_in              @ref MEDIC_p_ModHeadOutCustom @ref MEDIC_p_ModhbaHydrBrkAss
  @c_switch_part        @ref MEDIC_ARCHITECTURE_VERSION 
  @author               Nagaraja Veerashettappa  | Nagaraja.Veerashettappa@continental-corporation.com
*************************************************************************************************************************/
ALGO_INLINE  uint8 * MEDIC_p_ModHBAActiveHyp(void)
{ 
  #if (MEDIC_ARCHITECTURE_VERSION < 0x10)
  return &(MEDIC_p_ModHeadOutCustom()->sHBA.uActiveHyp);
  #else
  return &(MEDIC_p_ModhbaHydrBrkAss()->HypInfo.uActiveHyp);
  #endif 
}

/*************************************************************************************************************************
  Functionname:         MEDIC_p_ModHBAFctChan                                                            */ /*!
  @brief                Returns HBAFctChan
  @return               eEBAFctChan_t *
  @glob_in              @ref MEDIC_p_ModHeadOutCustom @ref MEDIC_p_ModhbaHydrBrkAss
  @c_switch_part        @ref MEDIC_ARCHITECTURE_VERSION 
  @author               Nagaraja Veerashettappa  | Nagaraja.Veerashettappa@continental-corporation.com
*************************************************************************************************************************/
ALGO_INLINE  eEBAFctChan_t * MEDIC_p_ModHBAFctChan(void)
{ 
  #if (MEDIC_ARCHITECTURE_VERSION < 0x10)
  return &(MEDIC_p_ModHeadOutCustom()->sHBA.eFctChan);
  #else
  return &(MEDIC_p_ModhbaHydrBrkAss()->HypInfo.eFctChan);
  #endif 
}

/*************************************************************************************************************************
  Functionname:         MEDIC_p_ModHBALevel                                                            */ /*!
  @brief                Returns HBALevel
  @return               uint8 *
  @glob_in              @ref MEDIC_p_ModHeadOutCustom @ref MEDIC_p_ModhbaHydrBrkAss
  @c_switch_part        @ref MEDIC_ARCHITECTURE_VERSION 
  @author               Nagaraja Veerashettappa  | Nagaraja.Veerashettappa@continental-corporation.com
*************************************************************************************************************************/
ALGO_INLINE  uint8 * MEDIC_p_ModHBALevel(void)
{ 
  #if (MEDIC_ARCHITECTURE_VERSION < 0x10)
  return &(MEDIC_p_ModHeadOutCustom()->sHBA.uiHBALevel);
  #else
  return &(MEDIC_p_ModhbaHydrBrkAss()->uiHBALevel);
  #endif 
}

/*************************************************************************************************************************
  Functionname:         MEDIC_p_ModPreBrakeDecelEnabled                                                            */ /*!
  @brief                Returns PreBrakeDecelEnabled
  @return               boolean *
  @glob_in              @ref MEDIC_p_ModHeadOutCustom @ref MEDIC_p_ModpreBrake
  @c_switch_part        @ref MEDIC_ARCHITECTURE_VERSION 
  @author               Nagaraja Veerashettappa  | Nagaraja.Veerashettappa@continental-corporation.com
*************************************************************************************************************************/
ALGO_INLINE  boolean * MEDIC_p_ModPreBrakeDecelEnabled(void)
{ 
  #if (MEDIC_ARCHITECTURE_VERSION < 0x10)
  return &(MEDIC_p_ModHeadOutCustom()->sPreBrake.bPreBrakeDecelEnabled);
  #else
  return &(MEDIC_p_ModpreBrake()->bPreBrakeDecelEnabled);
  #endif 
}

/*************************************************************************************************************************
  Functionname:         MEDIC_p_ModPreBrakeStdstillRequest                                                            */ /*!
  @brief                Returns PreBrakeStdstillRequest
  @return               boolean * 
  @glob_in              @ref MEDIC_p_ModHeadOutCustom @ref MEDIC_p_ModpreBrake
  @c_switch_part        @ref MEDIC_ARCHITECTURE_VERSION 
  @author               Nagaraja Veerashettappa  | Nagaraja.Veerashettappa@continental-corporation.com
*************************************************************************************************************************/
ALGO_INLINE  boolean * MEDIC_p_ModPreBrakeStdstillRequest(void)
{ 
  #if (MEDIC_ARCHITECTURE_VERSION < 0x10)
  #if (FCT_CUSTOM_OUTPUT_INTFVER > 41)
  return &(MEDIC_p_ModHeadOutCustom()->sPreBrake.bPreBrakeStdstillRequest);
  #else
  return NULL;
  #endif
  #else
  return &(MEDIC_p_ModpreBrake()->bPreBrakeStdstillRequest);
  #endif 
}

/*************************************************************************************************************************
  Functionname:         MEDIC_p_ModPreBrakeEmergency                                                            */ /*!
  @brief                Returns PreBrakeEmergency
  @return               boolean * 
  @glob_in              @ref MEDIC_p_ModHeadOutCustom @ref MEDIC_p_ModpreBrake
  @c_switch_part        @ref MEDIC_ARCHITECTURE_VERSION
  @author               Nagaraja Veerashettappa  | Nagaraja.Veerashettappa@continental-corporation.com
*************************************************************************************************************************/
ALGO_INLINE  boolean * MEDIC_p_ModPreBrakeEmergency(void)
{ 
  #if (MEDIC_ARCHITECTURE_VERSION < 0x10)
  return &(MEDIC_p_ModHeadOutCustom()->sPreBrake.bPreBrakeEmergency);
  #else
  return &(MEDIC_p_ModpreBrake()->bPreBrakeEmergency);
  #endif 
}

/*************************************************************************************************************************
  Functionname:         MEDIC_p_ModPreBrakeFctChan                                                            */ /*!
  @brief                Returns PreBrakeFctChan
  @return               eEBAFctChan_t  *
  @glob_in              @ref MEDIC_p_ModHeadOutCustom @ref MEDIC_p_ModpreBrake
  @c_switch_part        @ref MEDIC_ARCHITECTURE_VERSION
  @author               Nagaraja Veerashettappa  | Nagaraja.Veerashettappa@continental-corporation.com
*************************************************************************************************************************/
ALGO_INLINE  eEBAFctChan_t * MEDIC_p_ModPreBrakeFctChan(void)
{ 
  #if (MEDIC_ARCHITECTURE_VERSION < 0x10)
  return &(MEDIC_p_ModHeadOutCustom()->sPreBrake.eFctChan);
  #else
  return &(MEDIC_p_ModpreBrake()->HypInfo.eFctChan);
  #endif 
}

#if (MEDIC_ARCHITECTURE_VERSION >= 0x10)
/*************************************************************************************************************************
  Functionname:         MEDIC_p_ModPreBrakeSigState                                                            */ /*!
  @brief                Returns PreBrakeSigState
  @return               eEBASignalState_t  *
  @glob_in              @ref MEDIC_p_ModHeadOutCustom @ref MEDIC_p_ModpreBrake
  @c_switch_part        @ref MEDIC_ARCHITECTURE_VERSION
  @author               Nagaraja Veerashettappa  | Nagaraja.Veerashettappa@continental-corporation.com
*************************************************************************************************************************/
ALGO_INLINE  eEBASignalState_t * MEDIC_p_ModPreBrakeSigState(void)
{
  return &(MEDIC_p_ModpreBrake()->HypInfo.eSignal);
}
#endif 

/*************************************************************************************************************************
  Functionname:         MEDIC_p_ModPreBrakeDecel                                                                */ /*!
  @brief                Returns PreBrakeDecel
  @return               float32 *
  @glob_in              @ref MEDIC_p_ModHeadOutCustom @ref MEDIC_p_ModpreBrake
  @c_switch_part        @ref MEDIC_ARCHITECTURE_VERSION 
  @author               Nagaraja Veerashettappa  | Nagaraja.Veerashettappa@continental-corporation.com
*************************************************************************************************************************/
ALGO_INLINE  float32 * MEDIC_p_ModPreBrakeDecel(void)
{ 
  #if (MEDIC_ARCHITECTURE_VERSION < 0x10)
  return &(MEDIC_p_ModHeadOutCustom()->sPreBrake.fPreBrakeDecel);
  #else
  return &(MEDIC_p_ModpreBrake()->fPreBrakeDecel);
  #endif 
}

/*************************************************************************************************************************
  Functionname:         MEDIC_p_ModPreBrakeActiveHyp                                                            */ /*!
  @brief                Returns PreBrakeActiveHyp
  @return               uint8 *
  @glob_in              @ref MEDIC_p_ModHeadOutCustom @ref MEDIC_p_ModpreBrake
  @c_switch_part        @ref MEDIC_ARCHITECTURE_VERSION
  @author               Nagaraja Veerashettappa  | Nagaraja.Veerashettappa@continental-corporation.com
*************************************************************************************************************************/
ALGO_INLINE  uint8 * MEDIC_p_ModPreBrakeActiveHyp(void)
{ 
  #if (MEDIC_ARCHITECTURE_VERSION < 0x10)
  return &(MEDIC_p_ModHeadOutCustom()->sPreBrake.uActiveHyp);
  #else
  return &(MEDIC_p_ModpreBrake()->HypInfo.uActiveHyp);
  #endif 
}

/*************************************************************************************************************************
  Functionname:         MEDIC_p_ModPreBrakeLevel                                                            */ /*!
  @brief                Returns PreBrakeLevel
  @return               uint8 *
  @glob_in              @ref MEDIC_p_ModHeadOutCustom @ref MEDIC_p_Modwarnings
  @c_switch_part        @ref MEDIC_ARCHITECTURE_VERSION 
  @author               Nagaraja Veerashettappa  | Nagaraja.Veerashettappa@continental-corporation.com
*************************************************************************************************************************/
ALGO_INLINE  uint8 * MEDIC_p_ModPreBrakeLevel(void)
{ 
  #if (MEDIC_ARCHITECTURE_VERSION < 0x10)
  return &(MEDIC_p_ModHeadOutCustom()->sPreBrake.uPreBrakeLevel);
  #else
  return &(MEDIC_p_ModpreBrake()->uPreBrakeLevel);
  #endif 
}

#if (MEDIC_CFG_EBA_2ND_SENSOR_CONFIRMATION)
/*************************************************************************************************************************
  Functionname:         MEDIC_p_ModPreBrakeCamConfirmed                                                            */ /*!
  @brief                Returns Breakcamera confirmed signal
  @return               uint8 *
  @glob_in              @ref MEDIC_p_ModHeadOutCustom @ref MEDIC_p_Modwarnings
  @c_switch_part        @ref MEDIC_ARCHITECTURE_VERSION
  @author               Nagaraja Veerashettappa  | Nagaraja.Veerashettappa@continental-corporation.com
*************************************************************************************************************************/
ALGO_INLINE  boolean * MEDIC_p_ModPreBrakeCamConfirmed(void)
{ 
  #if (MEDIC_ARCHITECTURE_VERSION < 0x10)
  return &(MEDIC_p_ModHeadOutCustom()->sPreBrake.bPreBrakeCamConfirmed);
  #else
  return &(MEDIC_p_ModpreBrake()->bPreBrakeCamConfirmed);
  #endif 
}
#endif 

/*************************************************************************************************************************
  Functionname:         MEDIC_p_ModPreCrashEMAActive                                                            */ /*!
  @brief                Returns PreCrashEMAActive
  @return               boolean *
  @glob_in              @ref MEDIC_p_ModHeadOutCustom @ref MEDIC_p_ModpreCrash
  @c_switch_part        @ref MEDIC_ARCHITECTURE_VERSION
  @author               Nagaraja Veerashettappa  | Nagaraja.Veerashettappa@continental-corporation.com
*************************************************************************************************************************/
ALGO_INLINE  boolean * MEDIC_p_ModPreCrashEMAActive(void)
{ 
  #if (MEDIC_ARCHITECTURE_VERSION < 0x10)
  return &(MEDIC_p_ModHeadOutCustom()->sPreCrash.bEMAActive);
  #else
  return &(MEDIC_p_ModpreCrash()->bActive);
  #endif 
}
/*************************************************************************************************************************
  Functionname:         MEDIC_p_ModPreCrashEBAFctChan                                                            */ /*!
  @brief                Returns PreCrashEBAFctChan
  @return               eeEBAFctChan_t *
  @glob_in              @ref MEDIC_p_ModHeadOutCustom @ref MEDIC_p_ModpreCrash
  @c_switch_part        @ref MEDIC_ARCHITECTURE_VERSION 
  @author               Nagaraja Veerashettappa  | Nagaraja.Veerashettappa@continental-corporation.com
*************************************************************************************************************************/
ALGO_INLINE  eEBAFctChan_t * MEDIC_p_ModPreCrashEBAFctChan(void)
{ 
  #if (MEDIC_ARCHITECTURE_VERSION < 0x10)
  return &(MEDIC_p_ModHeadOutCustom()->sPreCrash.eEBAFctChan);
  #else
  return &(MEDIC_p_ModpreCrash()->sHypInfo.eFctChan);
  #endif 
}

/*************************************************************************************************************************
  Functionname:         MEDIC_p_ModPreCrashCV                                                            */ /*!
  @brief                Returns PreCrashCV
  @return               float32 *
  @glob_in              @ref MEDIC_p_ModHeadOutCustom @ref MEDIC_p_ModpreCrash
  @c_switch_part        @ref MEDIC_ARCHITECTURE_VERSION
  @author               Nagaraja Veerashettappa  | Nagaraja.Veerashettappa@continental-corporation.com
*************************************************************************************************************************/
ALGO_INLINE  float32 * MEDIC_p_ModPreCrashCV(void)
{ 
  #if (MEDIC_ARCHITECTURE_VERSION < 0x10)
  return &(MEDIC_p_ModHeadOutCustom()->sPreCrash.fPreCrashCV);
  #else
  return &(MEDIC_p_ModpreCrash()->fPreCrashCV);
  #endif 
}

/*************************************************************************************************************************
  Functionname:         MEDIC_p_ModPreCrashTTC                                                            */ /*!
  @brief                Returns PreCrashTT
  @return               float32 *
  @glob_in              @ref MEDIC_p_ModHeadOutCustom @ref MEDIC_p_ModpreCrash
  @c_switch_part        @ref MEDIC_ARCHITECTURE_VERSION
  @author               Nagaraja Veerashettappa  | Nagaraja.Veerashettappa@continental-corporation.com
*************************************************************************************************************************/
ALGO_INLINE  float32 * MEDIC_p_ModPreCrashTTC(void)
{ 
  #if (MEDIC_ARCHITECTURE_VERSION < 0x10)
  return &(MEDIC_p_ModHeadOutCustom()->sPreCrash.fPreCrashTTC);
  #else
  return &(MEDIC_p_ModpreCrash()->fPreCrashTTC);
  #endif 
}

/*************************************************************************************************************************
  Functionname:         MEDIC_p_ModPreCrashActiveHyp                                                            */ /*!
  @brief                Returns PreCrashActiveHyp
  @return               uint8 *
  @glob_in              @ref MEDIC_p_ModHeadOutCustom @ref MEDIC_p_ModpreCrash
  @c_switch_part        @ref MEDIC_ARCHITECTURE_VERSION 
  @author               Nagaraja Veerashettappa  | Nagaraja.Veerashettappa@continental-corporation.com
*************************************************************************************************************************/
ALGO_INLINE  uint8* MEDIC_p_ModPreCrashActiveHyp(void)
{ 
  #if (MEDIC_ARCHITECTURE_VERSION < 0x10)
  return &(MEDIC_p_ModHeadOutCustom()->sPreCrash.uActiveHyp);
  #else
  return &(MEDIC_p_ModpreCrash()->sHypInfo.uActiveHyp);
  #endif 
}

/*************************************************************************************************************************
  Functionname:         MEDIC_p_ModPedFunctionQualifier                                                            */ /*!
  @brief                Returns PedFunctionQualifier
  @return               eFunctionQualifier_t *
  @glob_in              @ref MEDIC_p_ModHeadOutCustom @ref MEDIC_p_ModfctQualifiers
  @c_switch_part        @ref MEDIC_ARCHITECTURE_VERSION
  @author               Nagaraja Veerashettappa  | Nagaraja.Veerashettappa@continental-corporation.com
*************************************************************************************************************************/
ALGO_INLINE  eFunctionQualifier_t * MEDIC_p_ModPedFunctionQualifier(void)
{ 
  #if (MEDIC_ARCHITECTURE_VERSION < 0x10)
  return &(MEDIC_p_ModHeadOutCustom()->sFCTQualifiers.ePedFunctionQualifier);
  #else
  return &(MEDIC_p_ModfctQualifiers()->ePedFunctionQualifier);
  #endif 
}

/*************************************************************************************************************************
  Functionname:         MEDIC_p_ModCyclFunctionQualifier                                                            */ /*!
  @brief                Returns CyclFunctionQualifier
  @return               eFunctionQualifier_t *
  @glob_in              @ref MEDIC_p_ModHeadOutCustom @ref MEDIC_p_ModfctQualifiers
  @c_switch_part        @ref MEDIC_ARCHITECTURE_VERSION
  @author               Nagaraja Veerashettappa  | Nagaraja.Veerashettappa@continental-corporation.com
*************************************************************************************************************************/
ALGO_INLINE  eFunctionQualifier_t * MEDIC_p_ModCyclFunctionQualifier(void)
{ 
  #if (MEDIC_ARCHITECTURE_VERSION < 0x10)
  return &(MEDIC_p_ModHeadOutCustom()->sFCTQualifiers.eCyclFunctionQualifier);
  #else
  return &(MEDIC_p_ModfctQualifiers()->eCyclFunctionQualifier);
  #endif 
}

/*************************************************************************************************************************
  Functionname:         MEDIC_p_ModUnclassifiedFunctionQualifier                                                    */ /*!
  @brief                Returns UnclassifiedFunctionQualifier
  @return               eFunctionQualifier_t *
  @glob_in              @ref MEDIC_p_ModHeadOutCustom @ref MEDIC_p_ModfctQualifiers
  @c_switch_part        @ref MEDIC_ARCHITECTURE_VERSION
  @author               Nagaraja Veerashettappa  | Nagaraja.Veerashettappa@continental-corporation.com
*************************************************************************************************************************/
ALGO_INLINE  eFunctionQualifier_t * MEDIC_p_ModUnclassifiedFunctionQualifier(void)
{ 
  #if (MEDIC_ARCHITECTURE_VERSION < 0x10)
  return &(MEDIC_p_ModHeadOutCustom()->sFCTQualifiers.eUnclassifiedFunctionQualifier);
  #else
  return &(MEDIC_p_ModfctQualifiers()->eUnclassifiedFunctionQualifier);
  #endif 
}

/*************************************************************************************************************************
  Functionname:         MEDIC_p_ModVehFunctionQualifier                                                            */ /*!
  @brief                Returns VehFunctionQualifier
  @return               eFunctionQualifier_t *
  @glob_in              @ref MEDIC_p_ModHeadOutCustom @ref MEDIC_p_ModfctQualifiers
  @c_switch_part        @ref MEDIC_ARCHITECTURE_VERSION 
  @author               Nagaraja Veerashettappa  | Nagaraja.Veerashettappa@continental-corporation.com
*************************************************************************************************************************/
ALGO_INLINE  eFunctionQualifier_t * MEDIC_p_ModVehFunctionQualifier(void)
{ 
  #if (MEDIC_ARCHITECTURE_VERSION < 0x10)
  return &(MEDIC_p_ModHeadOutCustom()->sFCTQualifiers.eVehFunctionQualifier);
  #else
  return &(MEDIC_p_ModfctQualifiers()->eVehFunctionQualifier);
  #endif 
}

/*************************************************************************************************************************
  Functionname:         MEDIC_p_ModrgHypReactions                                                            */ /*!
  @brief                Returns Hypothesis Reactions 
  @return               HEADOutCustHypReactions_t  *
  @glob_in              @ref MEDIC_p_ModHeadOutCustom 
  @c_switch_part        @ref MEDIC_ARCHITECTURE_VERSION
  @author               Nagaraja Veerashettappa  | Nagaraja.Veerashettappa@continental-corporation.com
*************************************************************************************************************************/
ALGO_INLINE  HEADOutCustHypReactions_t  * MEDIC_p_ModrgHypReactions(uint8 uHyp)
{ 
  /* Check range */
  /* Suppress "Msg(3:3112) This statement has no side-effect - it can be removed"  */ /*PRQA S 3112 1*/
  MEDIC_ASSERT(uHyp < MAX_NUM_OF_HYPS); /*PRQA S 3119*/ /*date: 2020-07-06, Reviewer:Rashmi Ramachandra, Reason: Assert used for failsafe*/
  #if (MEDIC_ARCHITECTURE_VERSION < 0x10)
  return &(MEDIC_p_ModHeadOutCustom()->rgHypReactions[uHyp]);
  #else
  return &(MEDIC_p_ModhypReactions()->aHyps[uHyp]);
  #endif
}

#if (MEDIC_ARCHITECTURE_VERSION >= 0x10)
/*************************************************************************************************************************
  Functionname:         MEDIC_p_ModFCTDataVersionNumber                                                            */ /*!
  @brief                Returns the FCTDataVersionNumber
  @return               uint32  *
  @glob_in              @ref  MEDIC_p_ModfctData
  @c_switch_full        @ref MEDIC_ARCHITECTURE_VERSION
  @author               Nagaraja Veerashettappa  | Nagaraja.Veerashettappa@continental-corporation.com
*************************************************************************************************************************/
ALGO_INLINE  uint32  * MEDIC_p_ModFCTDataVersionNumber(void)
{
  return &(MEDIC_p_ModfctData()->versionNumber);
}

/*************************************************************************************************************************
  Functionname:         MEDIC_p_ModFCTDatasigHeader                                                            */ /*!
  @brief                Returns the FCTDatasigHeader
  @return               SignalHeader_t  *
  @glob_in              @ref  MEDIC_p_ModfctData
  @c_switch_full        @ref MEDIC_ARCHITECTURE_VERSION
  @author               Nagaraja Veerashettappa  | Nagaraja.Veerashettappa@continental-corporation.com
*************************************************************************************************************************/
ALGO_INLINE  SignalHeader_t  * MEDIC_p_ModFCTDatasigHeader(void)
{
  return &(MEDIC_p_ModfctData()->sigHeader);
}

/*************************************************************************************************************************
  Functionname:         MEDIC_p_ModFCTDataObjDescription                                                            */ /*!
  @brief                Returns the FCTDatObjectDescriptionNow
  @return               ObjectDescription  *
  @glob_in              @ref  MEDIC_p_ModfctData
  @c_switch_full        @ref MEDIC_ARCHITECTURE_VERSION
  @author               Nagaraja Veerashettappa  | Nagaraja.Veerashettappa@continental-corporation.com
*************************************************************************************************************************/
ALGO_INLINE  ObjectDescription  * MEDIC_p_ModFCTDataObjDescription(void)
{
  return &(MEDIC_p_ModfctData()->ObjectDescriptionNow);
}

/*************************************************************************************************************************
  Functionname:         MEDIC_p_ModFCTDataObjDisColl                                                            */ /*!
  @brief                Returns the FCTDataObjectDescriptionCollision
  @return               ObjectDescription  *
  @glob_in              @ref  MEDIC_p_ModfctData
  @c_switch_full        @ref MEDIC_ARCHITECTURE_VERSION
  @author               Nagaraja Veerashettappa  | Nagaraja.Veerashettappa@continental-corporation.com
*************************************************************************************************************************/
ALGO_INLINE  ObjectDescription  * MEDIC_p_ModFCTDataObjDisColl(void)
{
  return &(MEDIC_p_ModfctData()->ObjectDescriptionCollision);
}
#endif
#if ((MEDIC_ARCHITECTURE_VERSION >= 0x10) && (MEDIC_CFG_ABORT_REASON))
/*************************************************************************************************************************
  Functionname:         MEDIC_p_ModFCTDataAbortReasonParamOutType                                                            */ /*!
  @brief                Returns the FCTDataAbortReasonParamOutType
  @return               uint8  *
  @glob_in              @ref MEDIC_p_ModHeadOutCustom @ref  MEDIC_p_ModfctData
  @c_switch_part        @ref MEDIC_ARCHITECTURE_VERSION
  @author               Nalina M  | Nalina.Muddaveeraiah@continental-corporation.com
*************************************************************************************************************************/
ALGO_INLINE  uint8  * MEDIC_p_ModFCTDataAbortReasonParamOutType(uint8 index)
{
  return &(MEDIC_p_ModfctData()->HeadAbrtResn[index].ParamFailed);
}
/*************************************************************************************************************************
  Functionname:         MEDIC_p_ModFCTDataAbortReasonHypLost                                                            */ /*!
  @brief                Returns the FCTDataAbortReasonHypLost
  @return               boolean  *
  @glob_in              @ref MEDIC_p_ModHeadOutCustom @ref  MEDIC_p_ModfctData
  @c_switch_part        @ref MEDIC_ARCHITECTURE_VERSION
  @author               Nalina M  | Nalina.Muddaveeraiah@continental-corporation.com
*************************************************************************************************************************/
ALGO_INLINE  boolean  * MEDIC_p_ModFCTDataAbortReasonHypLost(uint8 index)
{
  return &(MEDIC_p_ModfctData()->HeadAbrtResn[index].HypLost);
}
#endif

/*************************************************************************************************************************
  Functionname:         MEDIC_p_ModFCTDataVelocityFactor                                                            */ /*!
  @brief                Returns the FCTDataVelocityFactor
  @return               float32  *
  @glob_in              @ref MEDIC_p_ModHeadOutCustom @ref  MEDIC_p_ModfctData
  @c_switch_part        @ref MEDIC_ARCHITECTURE_VERSION
  @author               Nagaraja Veerashettappa  | Nagaraja.Veerashettappa@continental-corporation.com
*************************************************************************************************************************/
ALGO_INLINE  float32  * MEDIC_p_ModFCTDataVelocityFactor(void)
{
  #if (MEDIC_ARCHITECTURE_VERSION < 0x10)
  return &(MEDIC_p_ModHeadOutCustom()->sFCTData.fVelocityFactor);
  #else
  return &(MEDIC_p_ModfctData()->fVelocityFactor);
  #endif
}

/*************************************************************************************************************************
  Functionname:         MEDIC_p_ModFCTDataSafeObjDistance                                                            */ /*!
  @brief                Returns the FCTDataSafeObjDistance
  @return               float32  *
  @glob_in              @ref MEDIC_p_ModHeadOutCustom @ref  MEDIC_p_ModfctData
  @c_switch_part        @ref MEDIC_ARCHITECTURE_VERSION 
  @author               Nagaraja Veerashettappa  | Nagaraja.Veerashettappa@continental-corporation.com
*************************************************************************************************************************/
ALGO_INLINE  float32  * MEDIC_p_ModFCTDataSafeObjDistance(void)
{ 
  #if (MEDIC_ARCHITECTURE_VERSION < 0x10)
  return &(MEDIC_p_ModHeadOutCustom()->sFCTData.fSafeObjDistance);
  #else
  return &(MEDIC_p_ModfctData()->fSafeObjDistance);
  #endif
}

#if (HEAD_USE_TIME_HIGH_OBJ_QUALITY)
/*************************************************************************************************************************
  Functionname:         MEDIC_p_ModFCTDataObjLifeTimeHiQual                                                            */ /*!
  @brief                Returns the FCTDataObjLifeTimeHiQual
  @return               float32  *
  @glob_in              @ref MEDIC_p_ModHeadOutCustom @ref  MEDIC_p_ModfctData
  @c_switch_part        @ref MEDIC_ARCHITECTURE_VERSION
  @author               Nagaraja Veerashettappa  | Nagaraja.Veerashettappa@continental-corporation.com
*************************************************************************************************************************/
ALGO_INLINE  float32  * MEDIC_p_ModFCTDataObjLifeTimeHiQual(void)
{
  #if (MEDIC_ARCHITECTURE_VERSION < 0x10)
  return &(MEDIC_p_ModHeadOutCustom()->sFCTData.fObjLifeTimeHiQual);
  #else
  return &(MEDIC_p_ModfctData()->fObjLifeTimeHiQual);
  #endif
}
#endif 

/*************************************************************************************************************************
  Functionname:         MEDIC_p_ModFCTDataObjTTC                                                            */ /*!
  @brief                Returns the FCTDataObject TTC
  @return               float32  *
  @glob_in              @ref MEDIC_p_ModHeadOutCustom @ref  MEDIC_p_ModfctData
  @c_switch_part        @ref MEDIC_ARCHITECTURE_VERSION
  @author               Nagaraja Veerashettappa  | Nagaraja.Veerashettappa@continental-corporation.com
*************************************************************************************************************************/
ALGO_INLINE  float32  * MEDIC_p_ModFCTDataObjTTC(void)
{ 
  #if (MEDIC_ARCHITECTURE_VERSION < 0x10)
  return &(MEDIC_p_ModHeadOutCustom()->sFCTData.fObjTTC);
  #else
  return &(MEDIC_p_ModfctData()->fObjTTC);
  #endif
}

/*************************************************************************************************************************
  Functionname:         MEDIC_p_ModFCTDataObjDistX                                                            */ /*!
  @brief                Returns the FCTDataObjDistX
  @return               float32  *
  @glob_in              @ref MEDIC_p_ModHeadOutCustom @ref  MEDIC_p_ModfctData
  @c_switch_part        @ref MEDIC_ARCHITECTURE_VERSION
  @author               Nagaraja Veerashettappa  | Nagaraja.Veerashettappa@continental-corporation.com
*************************************************************************************************************************/
ALGO_INLINE  float32  * MEDIC_p_ModFCTDataObjDistX(void)
{
  #if (MEDIC_ARCHITECTURE_VERSION < 0x10)
  return &(MEDIC_p_ModHeadOutCustom()->sFCTData.fObjDistX);
  #else
  return &(MEDIC_p_ModfctData()->fObjDistX);
  #endif
}

#if (MEDIC_ARCHITECTURE_VERSION >= 0x10)
/*************************************************************************************************************************
  Functionname:         MEDIC_p_ModFCTDataObjDistY                                                            */ /*!
  @brief                Returns the FCTDataObjDistY
  @return               float32  *
  @glob_in              @ref  MEDIC_p_ModfctData
  @c_switch_full        @ref MEDIC_ARCHITECTURE_VERSION
  @author               Nagaraja Veerashettappa  | Nagaraja.Veerashettappa@continental-corporation.com
*************************************************************************************************************************/
ALGO_INLINE  float32  * MEDIC_p_ModFCTDataObjDistY(void)
{
  return &(MEDIC_p_ModfctData()->fObjDistY);
}

/*************************************************************************************************************************
  Functionname:         MEDIC_p_ModFCTDataObjVelX                                                            */ /*!
  @brief                Returns the FCTDataObjVelX
  @return               float32  *
  @glob_in              @ref  MEDIC_p_ModfctData
  @c_switch_full        @ref MEDIC_ARCHITECTURE_VERSION
  @author               Nagaraja Veerashettappa  | Nagaraja.Veerashettappa@continental-corporation.com
*************************************************************************************************************************/
ALGO_INLINE  float32  * MEDIC_p_ModFCTDataObjVelX(void)
{
  return &(MEDIC_p_ModfctData()->fObjVelX);
}

/*************************************************************************************************************************
  Functionname:         MEDIC_p_ModFCTDataObjAccelX                                                            */ /*!
  @brief                Returns the FCTDataObjAccelX
  @return               float32  *
  @glob_in              @ref  MEDIC_p_ModfctData
  @c_switch_full        @ref MEDIC_ARCHITECTURE_VERSION
  @author               Nagaraja Veerashettappa  | Nagaraja.Veerashettappa@continental-corporation.com
*************************************************************************************************************************/
ALGO_INLINE  float32  * MEDIC_p_ModFCTDataObjAccelX(void)
{
  return &(MEDIC_p_ModfctData()->fObjAccelX);
}

/*************************************************************************************************************************
  Functionname:         MEDIC_p_ModFCTDataObjVelY                                                            */ /*!
  @brief                Returns the FCTDatafObjVelY
  @return               float32  *
  @glob_in              @ref  MEDIC_p_ModfctData
  @c_switch_full        @ref MEDIC_ARCHITECTURE_VERSION
  @author               Nagaraja Veerashettappa  | Nagaraja.Veerashettappa@continental-corporation.com
*************************************************************************************************************************/
ALGO_INLINE  float32  * MEDIC_p_ModFCTDataObjVelY(void)
{
  return &(MEDIC_p_ModfctData()->fObjVelY);
}

/*************************************************************************************************************************
  Functionname:         MEDIC_p_ModFCTDataObjAccelY                                                            */ /*!
  @brief                Returns the FCTDataObjAccelY
  @return               float32  *
  @glob_in              @ref  MEDIC_p_ModfctData
  @c_switch_full        @ref MEDIC_ARCHITECTURE_VERSION
  @author               Nagaraja Veerashettappa  | Nagaraja.Veerashettappa@continental-corporation.com
*************************************************************************************************************************/
ALGO_INLINE  float32  * MEDIC_p_ModFCTDataObjAccelY(void)
{
  return &(MEDIC_p_ModfctData()->fObjAccelY);
}

/*************************************************************************************************************************
  Functionname:         MEDIC_p_ModFCTDataObjTTB                                                           */ /*!
  @brief                Returns the FCTDataObject TTB
  @return               float32  *
  @glob_in              @ref MEDIC_p_ModHeadOutCustom @ref  MEDIC_p_ModfctData
  @c_switch_part        @ref MEDIC_ARCHITECTURE_VERSION
  @author               Nagaraja Veerashettappa  | Nagaraja.Veerashettappa@continental-corporation.com
*************************************************************************************************************************/
ALGO_INLINE  float32  * MEDIC_p_ModFCTDataObjTTB(void)
{
  return &(MEDIC_p_ModfctData()->fObjTTB);
}
#endif

/*************************************************************************************************************************
  Functionname:         MEDIC_p_ModFCTDaCollisionAvoidAccel                                                            */ /*!
  @brief                Returns the FCTDaCollisionAvoidAccel
  @return               float32  *
  @glob_in              @ref MEDIC_p_ModHeadOutCustom @ref  MEDIC_p_ModfctData
  @c_switch_part        @ref MEDIC_ARCHITECTURE_VERSION
  @author               Nagaraja Veerashettappa  | Nagaraja.Veerashettappa@continental-corporation.com
*************************************************************************************************************************/
ALGO_INLINE  float32  * MEDIC_p_ModFCTDaCollisionAvoidAccel(void)
{
  #if (MEDIC_ARCHITECTURE_VERSION < 0x10)
  return &(MEDIC_p_ModHeadOutCustom()->sFCTData.fCollisionAvoidAccel);
  #else
  return &(MEDIC_p_ModfctData()->fCollisionAvoidAccel);
  #endif
}

#if (MEDIC_ARCHITECTURE_VERSION >= 0x10)
/*************************************************************************************************************************
  Functionname:         MEDIC_p_ModFCTDataObjPoe                                                            */ /*!
  @brief                Returns the FCTDatafObjPoe
  @return               float32  *
  @glob_in              @ref  MEDIC_p_ModfctData
  @c_switch_full        @ref MEDIC_ARCHITECTURE_VERSION
  @author               Nagaraja Veerashettappa  | Nagaraja.Veerashettappa@continental-corporation.com
*************************************************************************************************************************/
ALGO_INLINE  float32  * MEDIC_p_ModFCTDataObjPoe(void)
{
  return &(MEDIC_p_ModfctData()->fObjPoe);
}
#endif

/*************************************************************************************************************************
  Functionname:         MEDIC_p_ModFCTDataObjref                                                            */ /*!
  @brief                Returns the FCTDataObjref
  @return               bjNumber_t  *
  @glob_in              @ref MEDIC_p_ModHeadOutCustom @ref  MEDIC_p_ModfctData
  @c_switch_part        @ref MEDIC_ARCHITECTURE_VERSION
  @author               Nagaraja Veerashettappa  | Nagaraja.Veerashettappa@continental-corporation.com
*************************************************************************************************************************/
ALGO_INLINE  ObjNumber_t  * MEDIC_p_ModFCTDataObjref(void)
{
  #if (MEDIC_ARCHITECTURE_VERSION < 0x10)
  return &(MEDIC_p_ModHeadOutCustom()->sFCTData.iObjRef);
  #else
  return &(MEDIC_p_ModfctData()->iObjRef);
  #endif
}

#if (MEDIC_ARCHITECTURE_VERSION >= 0x10)
/*************************************************************************************************************************
  Functionname:         MEDIC_p_ModFCTDataObjClass                                                            */ /*!
  @brief                Returns the FCTDataObjClassification
  @return               eEBARelObjClass_t  *
  @glob_in              @ref  MEDIC_p_ModfctData
  @c_switch_full        @ref MEDIC_ARCHITECTURE_VERSION
  @author               Nagaraja Veerashettappa  | Nagaraja.Veerashettappa@continental-corporation.com
*************************************************************************************************************************/
ALGO_INLINE  eEBARelObjClass_t  * MEDIC_p_ModFCTDataObjClass(void)
{
  return &(MEDIC_p_ModfctData()->eObjClassification);
}
#endif

/*************************************************************************************************************************
  Functionname:         MEDIC_p_ModFCTDataObjRelQualifier                                                            */ /*!
  @brief                Returns the FCTDataObjRelQualifier
  @return               eEBARelObjQualifier_t  *
  @glob_in              @ref MEDIC_p_ModHeadOutCustom @ref  MEDIC_p_ModfctData
  @c_switch_part        @ref MEDIC_ARCHITECTURE_VERSION
  @author               Nagaraja Veerashettappa  | Nagaraja.Veerashettappa@continental-corporation.com
*************************************************************************************************************************/
ALGO_INLINE  eEBARelObjQualifier_t  * MEDIC_p_ModFCTDataObjRelQualifier (void)
{ 
  #if (MEDIC_ARCHITECTURE_VERSION < 0x10)
  return &(MEDIC_p_ModHeadOutCustom()->sFCTData.eObjRelQualifier);
  #else
  return &(MEDIC_p_ModfctData()->eObjRelQualifier);
  #endif
}

#if (MEDIC_ARCHITECTURE_VERSION >= 0x10)
/*************************************************************************************************************************
  Functionname:         MEDIC_p_ModFCTDataFusionState                                                            */ /*!
  @brief                Returns the FCTDataObjFusionstate
  @return               eSensorSource_t  *
  @glob_in              @ref  MEDIC_p_ModfctData
  @c_switch_full        @ref MEDIC_ARCHITECTURE_VERSION
  @author               Nagaraja Veerashettappa  | Nagaraja.Veerashettappa@continental-corporation.com
*************************************************************************************************************************/
ALGO_INLINE  eSensorSource_t  * MEDIC_p_ModFCTDataFusionState(void)
{
  return &(MEDIC_p_ModfctData()->eObjFusionstate);
}
#endif

#endif //end of check for ((HEAD)||(DIM)|| (MEDIC CFG INCLUDE_UNUSED_INTF)) 

#if((MEDIC_CFG_VEH_SIG_INPUT)|| (MEDIC_CFG_INCLUDE_UNUSED_INTF))
/*************************************************************************************************************************
  Functionname:         MEDIC_p_GetVehSig                                                           */ /*!
  @brief                Returns VehSig_t
  @glob_in              @ref MEDIC_p_GetAccessData
  @return               VehSig_t const*
  @c_switch_full        @ref MEDIC_CFG_VEH_SIG_INPUT @ref MEDIC_CFG_INCLUDE_UNUSED_INTF
  @author               Nagaraja Veerashettappa  | Nagaraja.Veerashettappa@continental-corporation.com
*************************************************************************************************************************/
ALGO_INLINE VehSig_t const* MEDIC_p_GetVehSig(void)
{
#if (MEDIC_ARCHITECTURE_VERSION < 0x10)
  return  MEDIC_p_GetAccessData()->Input.ReqPorts.pVehSig;
#else
  return  MEDIC_p_GetAccessData()->Input.ReqPorts.vehSig;
#endif
}
#endif /* MEDIC_CFG_VEH_SIG_INPUT */

#if ((MEDIC_CFG_CPAR_PARAMS) || (MEDIC_CFG_INCLUDE_UNUSED_INTF))
/*************************************************************************************************************************
  Functionname:         MEDIC_p_GetCPARFCTParameters                                                           */ /*!
  @brief                Returns CPAR FCT parameters
  @glob_in              @ref MEDIC_p_GetAccessData
  @return               CPAR_FCT_Parameters_t const*
  @c_switch_full        @ref MEDIC_CFG_CPAR_PARAMS @ref MEDIC_CFG_INCLUDE_UNUSED_INTF
  @author               Nagaraja Veerashettappa  | Nagaraja.Veerashettappa@continental-corporation.com 
*************************************************************************************************************************/
#if (MEDIC_ARCHITECTURE_VERSION < 0x10)
ALGO_INLINE CPAR_FCT_Parameters_t const* MEDIC_p_GetCPARFCTParameters(void)
{
  return MEDIC_p_GetAccessData()->Input.ReqPorts.pCPAR_FCT_Parameters;
}
#endif 
#endif /* MEDIC_CFG_CPAR_PARAMS */

#if ((MEDIC_CFG_CUSTOMINPUT) || (MEDIC_CFG_INCLUDE_UNUSED_INTF))
/*************************************************************************************************************************
  Functionname:         MEDIC_p_GetFctVehCustInput                                                           */ /*!
  @brief                Returns FCTVehCustomInput_t
  @glob_in              @ref MEDIC_p_GetAccessData
  @return               FCTVehCustomInput_t const *
  @c_switch_full        @ref MEDIC_CFG_CUSTOMINPUT @ref MEDIC_CFG_INCLUDE_UNUSED_INTF
  @author               Nagaraja Veerashettappa  | Nagaraja.Veerashettappa@continental-corporation.com 
*************************************************************************************************************************/
ALGO_INLINE FCTVehCustomInput_t const * MEDIC_p_GetFctVehCustInput(void)
{
  return MEDIC_p_GetAccessData()->Input.ReqPorts.pFctVehCustInput;
}
#endif /* MEDIC_CFG_CUSTOMINPUT */

#if ((MEDIC_CFG_USE_SERVICE_POINTER_FUNCTS)|| (MEDIC_CFG_INCLUDE_UNUSED_INTF))
/*************************************************************************************************************************
  Functionname:         MEDIC_p_GetServiceFuncts                                                              */ /*!
  @brief                Returns the const pointer to the Service Functions.
  @return               AS_t_ServiceFuncts const *
  @glob_in              @ref MEDIC_p_GetInput
  @c_switch_full        @ref MEDIC_CFG_USE_SERVICE_POINTER_FUNCTS @ref MEDIC_CFG_INCLUDE_UNUSED_INTF
  @author               Nagaraja Veerashettappa  | Nagaraja.Veerashettappa@continental-corporation.com 
*************************************************************************************************************************/
#if (MEDIC_ARCHITECTURE_VERSION < 0x10)
ALGO_INLINE AS_t_ServiceFuncts const * MEDIC_p_GetServiceFuncts(void)
#else
ALGO_INLINE MEDIC_Services     const * MEDIC_p_GetServiceFuncts(void)
#endif
{
  return &(MEDIC_p_GetInput()->ServiceFuncts);
}
#endif /* (MEDIC_CFG_USE_SERVICE_POINTER_FUNCTS) */

#if ((MEDIC_CFG_ERROR_OUTPUT_VEH)|| (MEDIC_CFG_INCLUDE_UNUSED_INTF))
#if (MEDIC_ARCHITECTURE_VERSION < 0x10)
/*************************************************************************************************************************
  Functionname:         MEDIC_p_ModErrorOut                                                           */ /*!
  @brief                Returns FCTVehErrorOut_t
  @glob_in              @ref MEDIC_p_GetAccessData
  @return               FCTVehErrorOut_t *
  @c_switch_full        @ref MEDIC_CFG_ERROR_OUTPUT_VEH @ref MEDIC_CFG_INCLUDE_UNUSED_INTF 
  @author               Nagaraja Veerashettappa  | Nagaraja.Veerashettappa@continental-corporation.com 
*************************************************************************************************************************/
ALGO_INLINE FCTVehErrorOut_t * MEDIC_p_ModErrorOut(void)
{
  return MEDIC_p_GetAccessData()->Output.ProPorts.pErrorOut;
}
#endif
#endif /* MEDIC_CFG_ERROR_OUTPUT_VEH */

#if ((MEDIC_CFG_USE_ALGOCOMPSTATE) || (MEDIC_CFG_INCLUDE_UNUSED_INTF))
/*************************************************************************************************************************
  Functionname:         MEDIC_p_GetVehCompState                                                           */ /*!
  @brief                Returns AlgoCompState_t
  @glob_in              @ref MEDIC_p_GetAccessData
  @return               AlgoCompState_t *
  @c_switch_full        @ref MEDIC_CFG_USE_ALGOCOMPSTATE
  @author               Nagaraja Veerashettappa  | Nagaraja.Veerashettappa@continental-corporation.com 
*************************************************************************************************************************/
ALGO_INLINE AlgoCompState_t * MEDIC_p_GetVehCompState(void)
{
  return MEDIC_p_GetAccessData()->Output.ProPorts.pVehCompState;
}
#endif /* MEDIC_CFG_USE_ALGOCOMPSTATE */

#if (MEDIC_ARCHITECTURE_VERSION >= 0x10)
/*************************************************************************************************************************
  Functionname:         MEDIC_p_ModCompState                                                                        */ /*!
  @brief                Returns the component state port (AlgoCompState_t) from MEDIC provide port structure
  @glob_in              @ref MEDICAccessData
  @return               AlgoCompState_t *
  @c_switch_full        @ref MEDIC_ARCHITECTURE_VERSION
  @author               Armin Vogl  | Armin.Vogl@continental-corporation.com 
*************************************************************************************************************************/
ALGO_INLINE AlgoCompState_t * MEDIC_p_ModCompState(void)
{
  return MEDICAccessData.Output.ProPorts.algoCompState;
}
#endif

#if ((MEDIC_CFG_HYPOTHESIS_EVAL_AND_DECISION) || (MEDIC_CFG_INCLUDE_UNUSED_INTF))

/************************************************************************/
/* HEAD                                                                 */
/************************************************************************/

#if (MEDIC_ARCHITECTURE_VERSION < 0x10)
/*************************************************************************************************************************
  Functionname:         MEDIC_p_GetHeadOutCustom                                                           */ /*!
  @brief                Returns HEAD custom out data
  @glob_in              @ref MEDIC_p_GetAccessData
  @return               HEADOutputCustom_t const *
  @c_switch_full        @ref MEDIC_CFG_HYPOTHESIS_EVAL_AND_DECISION @ref MEDIC_CFG_INCLUDE_UNUSED_INTF
  @author               Nagaraja Veerashettappa  | Nagaraja.Veerashettappa@continental-corporation.com 
*************************************************************************************************************************/
ALGO_INLINE HEADOutputCustom_t const * MEDIC_p_GetHeadOutCustom(void)
{
  return MEDIC_p_GetAccessData()->Output.ProPorts.pHEADOutputCustom;
}
#endif

#if (MEDIC_ARCHITECTURE_VERSION < 0x10)
/*************************************************************************************************************************
  Functionname:         MEDIC_p_ModHeadOutCustom                                                           */ /*!
  @brief                Returns HEAD custom out data
  @glob_in              @ref MEDIC_p_GetAccessData
  @return               HEADOutputCustom_t*
  @c_switch_full        @ref MEDIC_CFG_HYPOTHESIS_EVAL_AND_DECISION @ref MEDIC_CFG_INCLUDE_UNUSED_INTF
  @author               Nagaraja Veerashettappa  | Nagaraja.Veerashettappa@continental-corporation.com 
*************************************************************************************************************************/
ALGO_INLINE HEADOutputCustom_t  *   MEDIC_p_ModHeadOutCustom(void)
{
  return MEDIC_p_GetAccessData()->Output.ProPorts.pHEADOutputCustom;
}
#endif

#if (MEDIC_ARCHITECTURE_VERSION < 0x10)
/*************************************************************************************************************************
  Functionname:         MEDIC_p_GetHeadOutGeneric                                                           */ /*!
  @brief                Returns HEAD generic out data
  @glob_in              @ref MEDIC_p_GetAccessData
  @return               HEADOutputGeneric_t const*
  @c_switch_full        @ref MEDIC_CFG_HYPOTHESIS_EVAL_AND_DECISION @ref MEDIC_CFG_INCLUDE_UNUSED_INTF
  @author               Nagaraja Veerashettappa  | Nagaraja.Veerashettappa@continental-corporation.com 
*************************************************************************************************************************/
ALGO_INLINE HEADOutputGeneric_t const* MEDIC_p_GetHeadOutGeneric(void)
{
  return MEDIC_p_GetAccessData()->Output.ProPorts.pHEADOutputGeneric;
}
#endif

#if (MEDIC_ARCHITECTURE_VERSION < 0x10)
/*************************************************************************************************************************
  Functionname:         MEDIC_p_ModHeadOutGeneric                                                           */ /*!
  @brief                Returns HEAD generic out data
  @glob_in              @ref MEDIC_p_GetAccessData
  @return               HEADOutputGeneric_t *
  @c_switch_full        @ref MEDIC_CFG_HYPOTHESIS_EVAL_AND_DECISION @ref MEDIC_CFG_INCLUDE_UNUSED_INTF
  @author               Nagaraja Veerashettappa  | Nagaraja.Veerashettappa@continental-corporation.com 
*************************************************************************************************************************/
ALGO_INLINE HEADOutputGeneric_t * MEDIC_p_ModHeadOutGeneric(void)
{
  return MEDIC_p_GetAccessData()->Output.ProPorts.pHEADOutputGeneric;
}
#endif

#if (MEDIC_ARCHITECTURE_VERSION < 0x10)
/*************************************************************************************************************************
  Functionname:         MEDIC_p_GetHeadInGeneric                                                           */ /*!
  @brief                Returns HEAD generic input data
  @glob_in              @ref MEDIC_p_GetAccessData
  @return               HEADInputGeneric_t const*
  @c_switch_full        @ref MEDIC_CFG_HYPOTHESIS_EVAL_AND_DECISION @ref MEDIC_CFG_INCLUDE_UNUSED_INTF
  @author               Nagaraja Veerashettappa  | Nagaraja.Veerashettappa@continental-corporation.com 
*************************************************************************************************************************/
ALGO_INLINE HEADInputGeneric_t const* MEDIC_p_GetHeadInGeneric(void)
{
  return MEDIC_p_GetAccessData()->Input.ReqPorts.pHEADInputGeneric;
}
#endif

#if (MEDIC_ARCHITECTURE_VERSION < 0x10)
/*************************************************************************************************************************
  Functionname:         MEDIC_p_GetHeadInCustom                                                           */ /*!
  @brief                Returns  HEAD custom input data
  @glob_in              @ref MEDIC_p_GetAccessData
  @return               HEADInputCustom_t const*
  @c_switch_full        @ref MEDIC_CFG_HYPOTHESIS_EVAL_AND_DECISION @ref MEDIC_CFG_INCLUDE_UNUSED_INTF
  @author               Nagaraja Veerashettappa  | Nagaraja.Veerashettappa@continental-corporation.com 
*************************************************************************************************************************/
ALGO_INLINE HEADInputCustom_t const* MEDIC_p_GetHeadInCustom(void)
{
  return MEDIC_p_GetAccessData()->Input.ReqPorts.pHEADInputCustom;
}
#endif

#if (MEDIC_ARCHITECTURE_VERSION < 0x10)
ALGO_INLINE Hypothesis_t     MEDIC_e_GetHyp(uint8 index)
#else
ALGO_INLINE ACDC2_Hypothesis MEDIC_e_GetHyp(uint8 index)
#endif
{
  #if (MEDIC_ARCHITECTURE_VERSION < 0x10)
  return MEDICAccessData.Input.ReqPorts.pFCTCDHypotheses->Hypothesis[index];
  #else
  return MEDICAccessData.Input.ReqPorts.hypothesis->Hypothesis[index];
  #endif
}

/*************************************************************************************************************************
  Functionname:         MEDIC_p_GetEBAStateControl                                                           */ /*!
  @brief                Returns EBAStateControl
  @return               MEDIC_t_EBAStateControl
  @c_switch_part        @ref MEDIC_ARCHITECTURE_VERSION
  @author               Sadhanashree Srinivasa| Sadhanashree.Srinivasa@continental-corporation.com
*************************************************************************************************************************/

#if (MEDIC_ARCHITECTURE_VERSION >= 0x10)
ALGO_INLINE MEDIC_t_EBAStateControl const * MEDIC_p_GetEBAStateControl(void)
{
  return MEDIC_p_GetAccessData()->Input.ReqPorts.ebaStateControl;
}
#endif
/*************************************************************************************************************************
  Functionname:         MEDIC_p_GetEBAStateCtr                                                           */ /*!
  @brief                Returns EBAStatCtr
  @return               EBAStatCtr
  @c_switch_part        @ref MEDIC_ARCHITECTURE_VERSION
  @author               Sadhanashree Srinivasa| Sadhanashree.Srinivasa@continental-corporation.com
*************************************************************************************************************************/
#if (MEDIC_ARCHITECTURE_VERSION >= 0x10)
ALGO_INLINE CPAREBACodingFctMods_t const * MEDIC_p_GetEBAStateCtr(void)
{
  return MEDIC_p_GetAccessData()->Input.ReqPorts.ebaStateControl->EBAStatCtr;
}
#endif
/*************************************************************************************************************************
  Functionname:         MEDIC_i_GetHypObjID                                                           */ /*!
  @brief                Returns Hypothesis Object ID
  @return               ObjNumber_t
  @c_switch_part        @ref MEDIC_ARCHITECTURE_VERSION
  @author               Armin Vogl | armin.vogl@continental-corporation.com
*************************************************************************************************************************/
#if (MEDIC_ARCHITECTURE_VERSION < 0x10)
ALGO_INLINE ObjNumber_t MEDIC_i_GetHypObjID(const HEADHypothesis_t *const pHyp)
#else
ALGO_INLINE sint16      MEDIC_i_GetHypObjID(const HEADHypothesis_t *const pHyp)
#endif
{
  #if (MEDIC_ARCHITECTURE_VERSION < 0x10)
  return pHyp->pHypothesis->uiObjectRef;
  #else
  return pHyp->pHypothesis->CriticalItem.i_itemID;
  #endif
}

/*************************************************************************************************************************
  Functionname:         MEDIC_e_GetHypType                                                           */ /*!
  @brief                Returns Hypothesis Type
  @return               eCDHypothesisType_t
  @c_switch_part        @ref MEDIC_ARCHITECTURE_VERSION
  @author               Armin Vogl | armin.vogl@continental-corporation.com
*************************************************************************************************************************/
#if (MEDIC_ARCHITECTURE_VERSION < 0x10)
ALGO_INLINE eCDHypothesisType_t MEDIC_e_GetHypType(const HEADHypothesis_t *const pHyp)
#else
ALGO_INLINE t_HypothesisType MEDIC_e_GetHypType(const HEADHypothesis_t *const pHyp)
#endif
{
  #if (MEDIC_ARCHITECTURE_VERSION < 0x10)
  return pHyp->pHypothesis->eType;
  #else
  return pHyp->pHypothesis->e_hypType;
  #endif
}

/*************************************************************************************************************************
  Functionname:         MEDIC_u_GetHypObjProbability                                                           */ /*!
  @brief                Returns Hypothesis Object Probability
  @return               uint8
  @c_switch_part        @ref MEDIC_ARCHITECTURE_VERSION
  @author               Armin Vogl | armin.vogl@continental-corporation.com
*************************************************************************************************************************/
ALGO_INLINE uint8 MEDIC_u_GetHypObjProbability(const HEADHypothesis_t *const pHyp)
{
  #if (MEDIC_ARCHITECTURE_VERSION < 0x10)
  return pHyp->pHypothesis->uiObjectProbability;
  #else
  // Interface missing. Will be added ASAP
  _PARAM_UNUSED(pHyp); /*PRQA S 3119 1*/ /*date: 2020-07-06, Reviewer:Sadhanashree Srinivasa, Reason: Assert used for failsafe*/
  return 100u; // need to be change after update of ACDC interface 
  #endif
}

/*************************************************************************************************************************
  Functionname:         MEDIC_e_GetHypObjClass                                                           */ /*!
  @brief                Returns Hypothesis  Object Class
  @return               eEBAObjectClass_t
  @c_switch_part        @ref MEDIC_ARCHITECTURE_VERSION
  @author               Armin Vogl | armin.vogl@continental-corporation.com
*************************************************************************************************************************/
ALGO_INLINE eEBAObjectClass_t MEDIC_e_GetHypObjClass(const HEADHypothesis_t *const pHyp)
{
  #if (MEDIC_ARCHITECTURE_VERSION < 0x10)
  return pHyp->pHypothesis->eEBAObjectClass;
  #else
  return pHyp->pHypothesis->CriticalItem.e_class;
  #endif
}

/*************************************************************************************************************************
  Functionname:         MEDIC_e_GetHypDynProp                                                           */ /*!
  @brief                Returns Hypothesis Dynamic Property
  @return               eEBADynProp_t
  @c_switch_part        @ref MEDIC_ARCHITECTURE_VERSION
  @author               Armin Vogl | armin.vogl@continental-corporation.com
*************************************************************************************************************************/
ALGO_INLINE eEBADynProp_t MEDIC_e_GetHypDynProp(const HEADHypothesis_t *const pHyp)
{
  #if (MEDIC_ARCHITECTURE_VERSION < 0x10)
  return pHyp->pHypothesis->eEBADynProp;
  #else
  return pHyp->pHypothesis->CriticalItem.e_dynProp;
  #endif
}

/*************************************************************************************************************************
  Functionname:         MEDIC_e_GetHypMovDir                                                           */ /*!
  @brief                Returns Hypothesis Moving Direction
  @return               eEBAObjMovDir_t
  @c_switch_part        @ref MEDIC_ARCHITECTURE_VERSION
  @author               Armin Vogl | armin.vogl@continental-corporation.com
*************************************************************************************************************************/
ALGO_INLINE eEBAObjMovDir_t MEDIC_e_GetHypMovDir(const HEADHypothesis_t *const pHyp)
{
  #if (MEDIC_ARCHITECTURE_VERSION < 0x10)
  return pHyp->pHypothesis->eEBAObjMovDir;
  #else
  return pHyp->pHypothesis->CriticalItem.e_movDir;
  #endif
}

/*************************************************************************************************************************
  Functionname:         MEDIC_e_GetHypInhibitionMask                                                           */ /*!
  @brief                Returns Hypothesis Bitfield for Inhibition
  @return               EM_t_GenEbaInhibit
  @c_switch_part        @ref MEDIC_ARCHITECTURE_VERSION
  @author               Armin Vogl | armin.vogl@continental-corporation.com
*************************************************************************************************************************/
#if (MEDIC_ARCHITECTURE_VERSION < 0x10)
ALGO_INLINE EM_t_GenEbaInhibit MEDIC_e_GetHypInhibitionMask(const HEADHypothesis_t *const pHyp)
#else
ALGO_INLINE uint16 MEDIC_e_GetHypInhibitionMask(const HEADHypothesis_t *const pHyp)
#endif
{
  #if (MEDIC_ARCHITECTURE_VERSION < 0x10)
  return pHyp->pHypothesis->eEBAInhibitionMask;
  #else
  _PARAM_UNUSED(pHyp); /*PRQA S 3119 1*/ /*date: 2020-07-06, Reviewer:Sadhanashree Srinivasa, Reason: Assert used for failsafe*/
  return 0u; // not existing anymore, will be replaced by e_enableMask / e_keepMask
  #endif
}

/*************************************************************************************************************************
  Functionname:         MEDIC_u_GetHypProbability                                                           */ /*!
  @brief                Returns Hypothesis Probability
  @return               uint8
  @c_switch_part        @ref MEDIC_ARCHITECTURE_VERSION
  @author               Armin Vogl | armin.vogl@continental-corporation.com
*************************************************************************************************************************/
ALGO_INLINE uint8 MEDIC_u_GetHypProbability(const HEADHypothesis_t *const pHyp)
{
  #if (MEDIC_ARCHITECTURE_VERSION < 0x10)
  return pHyp->pHypothesis->uiHypothesisProbability;
  #else
  return pHyp->pHypothesis->u_hypProbability;
  #endif
}

#if (MEDIC_ARCHITECTURE_VERSION >= 0x10)
/*************************************************************************************************************************
  Functionname:         MEDIC_u_GetSafteyFunctionEnableFlag                                                          */ /*!
  @brief                Returns SafteyFunctionEnableFlag
  @return               uint8
  @c_switch_part        @ref MEDIC_ARCHITECTURE_VERSION
  @author               Komala Boraiah | komala.boraiah@continental-corporation.com
*************************************************************************************************************************/
ALGO_INLINE ACDC2_e_safetyFunctionFlags MEDIC_u_GetSafteyFunctionEnableFlag(const HEADHypothesis_t *const pHyp)
{
  return pHyp->pHypothesis->e_safetyFunctionEnableFlags;
}
#endif

#if (MEDIC_ARCHITECTURE_VERSION >= 0x10)
/*************************************************************************************************************************
  Functionname:         MEDIC_u_GetSafteyFunctionKeepFlag                                                          */ /*!
  @brief                Returns SafteyFunctionKeepFlag
  @return               uint8
  @c_switch_part        @ref MEDIC_ARCHITECTURE_VERSION
  @author               Komala Boraiah | komala.boraiah@continental-corporation.com
*************************************************************************************************************************/
ALGO_INLINE ACDC2_e_safetyFunctionFlags MEDIC_u_GetSafteyFunctionKeepFlag(const HEADHypothesis_t *const pHyp)
{
  return pHyp->pHypothesis->e_safetyFunctionKeepFlags;
}
#endif 
/*************************************************************************************************************************
  Functionname:         MEDIC_e_GetHypSensorSource                                                           */ /*!
  @brief                Returns Hypothesis Bitfield for Sensor participated
  @return               EM_t_GenObjSensorSource
  @c_switch_part        @ref MEDIC_ARCHITECTURE_VERSION
  @author               Armin Vogl | armin.vogl@continental-corporation.com
*************************************************************************************************************************/
#if (MEDIC_ARCHITECTURE_VERSION < 0x10)
ALGO_INLINE EM_t_GenObjSensorSource MEDIC_e_GetHypSensorSource(const HEADHypothesis_t *const pHyp)
#else
ALGO_INLINE ACDC2_e_sensorSource MEDIC_e_GetHypSensorSource(const HEADHypothesis_t *const pHyp)
#endif
{
  #if (MEDIC_ARCHITECTURE_VERSION < 0x10)
  return pHyp->pHypothesis->eSensorSource;
  #else
  return pHyp->pHypothesis->CriticalItem.e_sensorContribution;
  #endif
}

/*************************************************************************************************************************
  Functionname:         MEDIC_f_GetHypLifetime                                                           */ /*!
  @brief                Returns Hypothesis Hypothesis lifetime
  @return               float32
  @c_switch_part        @ref MEDIC_ARCHITECTURE_VERSION
  @author               Armin Vogl | armin.vogl@continental-corporation.com
*************************************************************************************************************************/
ALGO_INLINE float32 MEDIC_f_GetHypLifetime(const HEADHypothesis_t *const pHyp)
{
  #if (MEDIC_ARCHITECTURE_VERSION < 0x10)
  return pHyp->pHypothesis->fHypothesisLifetime;
  #else
  return pHyp->pHypothesis->f_hypLifetime;
  #endif
}

/*************************************************************************************************************************
  Functionname:         MEDIC_f_GetHypTTC                                                           */ /*!
  @brief                Returns Hypothesis Time to collision-1
  @return               float32
  @param[in]            pHyp : Pointer to current Hypothesis
  @c_switch_part        @ref MEDIC_ARCHITECTURE_VERSION
  @author               Armin Vogl | armin.vogl@continental-corporation.com
*************************************************************************************************************************/
ALGO_INLINE float32 MEDIC_f_GetHypTTC(const HEADHypothesis_t *const pHyp)
{
  #if (MEDIC_ARCHITECTURE_VERSION < 0x10)
  return pHyp->pHypothesis->fTTC;
  #else
  return pHyp->pHypothesis->CriticalItem.f_ttc;
  #endif
}

/*************************************************************************************************************************
  Functionname:         MEDIC_f_GetHypTTC2                                                           */ /*!
  @brief                Returns Hypothesis Time to collision-2
  @return               float32
  @param[in]            pHyp : Pointer to current Hypothesis
  @c_switch_part        @ref MEDIC_ARCHITECTURE_VERSION
  @author               Armin Vogl | armin.vogl@continental-corporation.com
*************************************************************************************************************************/
ALGO_INLINE float32 MEDIC_f_GetHypTTC2(const HEADHypothesis_t *const pHyp)
{
  #if (MEDIC_ARCHITECTURE_VERSION < 0x10)
  return pHyp->pHypothesis->fTTC2;
  #else
  return pHyp->pHypothesis->CriticalItem.f_ttc2;
  #endif
}

/*************************************************************************************************************************
  Functionname:         MEDIC_f_GetHypTTC3                                                           */ /*!
  @brief                Returns Hypothesis Time to collision-3
  @return               float32
  @c_switch_part        @ref MEDIC_ARCHITECTURE_VERSION
  @author               Armin Vogl | armin.vogl@continental-corporation.com
*************************************************************************************************************************/
ALGO_INLINE float32 MEDIC_f_GetHypTTC3(const HEADHypothesis_t *const pHyp)
{
  #if (MEDIC_ARCHITECTURE_VERSION < 0x10)
  return pHyp->pHypothesis->fTTC3;
  #else
  return pHyp->pHypothesis->CriticalItem.f_ttc3;
  #endif
}

/*************************************************************************************************************************
  Functionname:         MEDIC_f_GetHypTTC4                                                           */ /*!
  @brief                Returns Hypothesis Time to collision-4
  @return               float32
  @c_switch_part        @ref MEDIC_ARCHITECTURE_VERSION
  @author               Armin Vogl | armin.vogl@continental-corporation.com
*************************************************************************************************************************/
ALGO_INLINE float32 MEDIC_f_GetHypTTC4(const HEADHypothesis_t *const pHyp)
{
  #if (MEDIC_ARCHITECTURE_VERSION < 0x10)
  return pHyp->pHypothesis->fTTC4;
  #else
  return pHyp->pHypothesis->CriticalItem.f_ttc4;
  #endif
}

#if (MEDIC_ARCHITECTURE_VERSION < 0x10)
/*************************************************************************************************************************
  Functionname:         MEDIC_f_GetHypTTBPre                                                                        */ /*!
  @brief                Returns Hypothesis Time to comfort braking
  @return               float32
  @c_switch_part        @ref MEDIC_ARCHITECTURE_VERSION
  @author               Armin Vogl | armin.vogl@continental-corporation.com
*************************************************************************************************************************/
ALGO_INLINE float32 MEDIC_f_GetHypTTBPre(const HEADHypothesis_t *const pHyp)
{
  return pHyp->pHypothesis->fTTBPre;
}
#endif

#if (MEDIC_ARCHITECTURE_VERSION < 0x10)
/*************************************************************************************************************************
  Functionname:         MEDIC_f_GetHypTTBAcute                                                           */ /*!
  @brief                Returns Hypothesis Time to emergency braking
  @return               float32
  @c_switch_part        @ref MEDIC_ARCHITECTURE_VERSION
  @author               Armin Vogl | armin.vogl@continental-corporation.com
*************************************************************************************************************************/
ALGO_INLINE float32 MEDIC_f_GetHypTTBAcute(const HEADHypothesis_t *const pHyp)
{
  return pHyp->pHypothesis->fTTBAcute;
}
#endif

#if (MEDIC_ARCHITECTURE_VERSION >= 0x10)
/*************************************************************************************************************************
  Functionname:         MEDIC_f_GetTTB                                                                              */ /*!
  @brief                Returns Hypothesis Time to comfort braking
  @return               float32
  @c_switch_part        @ref MEDIC_ARCHITECTURE_VERSION
  @author               Armin Vogl | armin.vogl@continental-corporation.com
*************************************************************************************************************************/
ALGO_INLINE float32 MEDIC_f_GetHypTTB(uint8 uiHypNo, uint16 uiCascadeNo)
{
  return MEDICAccessData.Input.ReqPorts.brakeTargets->longTargets[uiHypNo].cascadeDependentValues[uiCascadeNo].f_ttb;
}
#endif

/*************************************************************************************************************************
  Functionname:         MEDIC_f_GetHypTTSPre                                                           */ /*!
  @brief                Returns Hypothesis Time to comfort steering
  @return               float32
  @c_switch_part        @ref MEDIC_ARCHITECTURE_VERSION
  @author               Armin Vogl | armin.vogl@continental-corporation.com
*************************************************************************************************************************/
ALGO_INLINE float32 MEDIC_f_GetHypTTSPre(const HEADHypothesis_t *const pHyp)
{
  #if (MEDIC_ARCHITECTURE_VERSION < 0x10)
  return pHyp->pHypothesis->fTTSPre;
  #else
  return pHyp->pHypothesis->CriticalItem.f_ttsPre;
  #endif
}

/*************************************************************************************************************************
  Functionname:         MEDIC_f_GetHypTTSAcute                                                           */ /*!
  @brief                Returns Hypothesis Time to emergency steering
  @return               float32
  @c_switch_part        @ref MEDIC_ARCHITECTURE_VERSION
  @author               Armin Vogl | armin.vogl@continental-corporation.com
*************************************************************************************************************************/
ALGO_INLINE float32 MEDIC_f_GetHypTTSAcute(const HEADHypothesis_t *const pHyp)
{
  #if (MEDIC_ARCHITECTURE_VERSION < 0x10)
  return pHyp->pHypothesis->fTTSAcute;
  #else
  return pHyp->pHypothesis->CriticalItem.f_ttsAcute;
  #endif
}

#if (MEDIC_ARCHITECTURE_VERSION < 0x10)
/*************************************************************************************************************************
  Functionname:         MEDIC_f_GetHypLongNecAccel                                                           */ /*!
  @brief                Returns Hypothesis Necessary longitudnal acceleration
  @return               float32
  @c_switch_part        @ref MEDIC_ARCHITECTURE_VERSION
  @author               Armin Vogl | armin.vogl@continental-corporation.com
*************************************************************************************************************************/
ALGO_INLINE float32 MEDIC_f_GetHypLongNecAccel(const uint8 uiHypNo)
{
  return MEDIC_p_GetHypothesis(uiHypNo)->fLongNecAccel;
}
#else
/*************************************************************************************************************************
  Functionname:         MEDIC_f_GetHypLongNecAccel                                                           */ /*!
  @brief                Returns Hypothesis Necessary longitudnal acceleration
  @return               float32
  @c_switch_part        @ref MEDIC_ARCHITECTURE_VERSION
  @author               Armin Vogl | armin.vogl@continental-corporation.com
*************************************************************************************************************************/
ALGO_INLINE float32 MEDIC_f_GetHypLongNecAccel(const uint8 uiHypNo)
{
  return MEDICAccessData.Input.ReqPorts.brakeTargets->longTargets[uiHypNo].f_longNecAccel;
}
#endif

#if (MEDIC_ARCHITECTURE_VERSION < 0x10)
/*************************************************************************************************************************
  Functionname:         MEDIC_f_GetHypLatNecAccel                                                           */ /*!
  @brief                Returns Hypothesis Necessary lateral acceleration
  @return               float32
  @c_switch_part        @ref MEDIC_ARCHITECTURE_VERSION
  @author               Armin Vogl | armin.vogl@continental-corporation.com
*************************************************************************************************************************/
ALGO_INLINE float32 MEDIC_f_GetHypLatNecAccel(const HEADHypothesis_t *const pHyp)
{
  return pHyp->pHypothesis->fLatNecAccel;
}
#else
// Not available in new architecture: redundant, because same info as in "time to steer"
#endif

/*************************************************************************************************************************
  Functionname:         MEDIC_f_GetHypDistX                                                           */ /*!
  @brief                Returns Hypothesis longitudnal Distance of object
  @return               float32
  @c_switch_part        @ref MEDIC_ARCHITECTURE_VERSION
  @author               Armin Vogl | armin.vogl@continental-corporation.com
*************************************************************************************************************************/
ALGO_INLINE float32 MEDIC_f_GetHypDistX(const HEADHypothesis_t *const pHyp)
{
  #if (MEDIC_ARCHITECTURE_VERSION < 0x10)
  return pHyp->pHypothesis->fDistX;
  #else
  return pHyp->pHypothesis->CriticalItem.f_distX;
  #endif
}

/*************************************************************************************************************************
  Functionname:         MEDIC_f_GetHypVrelX                                                           */ /*!
  @brief                Returns Hypothesis longitudnal Relative velocity of object
  @return               float32
  @c_switch_part        @ref MEDIC_ARCHITECTURE_VERSION
  @author               Armin Vogl | armin.vogl@continental-corporation.com
*************************************************************************************************************************/
#if (MEDIC_ARCHITECTURE_VERSION < 0x10)
ALGO_INLINE float32 MEDIC_f_GetHypVrelX(const HEADHypothesis_t *const pHyp)
{
  return pHyp->pHypothesis->fVrelX;
}
#else
// Not available in new architecture: transmitted as ABS values
#endif


/*************************************************************************************************************************
  Functionname:         MEDIC_f_GetHypArelX                                                           */ /*!
  @brief                Returns Hypothesis longitudnal Relative acceleration of object
  @return               float32
  @c_switch_part        @ref MEDIC_ARCHITECTURE_VERSION
  @author               Armin Vogl | armin.vogl@continental-corporation.com
*************************************************************************************************************************/
#if (MEDIC_ARCHITECTURE_VERSION < 0x10)
ALGO_INLINE float32 MEDIC_f_GetHypArelX(const HEADHypothesis_t *const pHyp)
{
  return pHyp->pHypothesis->fArelX;
}
#else
// Not available in new architecture: transmitted as ABS values
#endif


/*************************************************************************************************************************
  Functionname:         MEDIC_f_GetHypDistY                                                           */ /*!
  @brief                Returns Hypothesis lateral Distance of object
  @return               float32
  @c_switch_part        @ref MEDIC_ARCHITECTURE_VERSION
  @author               Armin Vogl | armin.vogl@continental-corporation.com
*************************************************************************************************************************/
ALGO_INLINE float32 MEDIC_f_GetHypDistY(const HEADHypothesis_t *const pHyp)
{
  #if (MEDIC_ARCHITECTURE_VERSION < 0x10)
  return pHyp->pHypothesis->fDistY;
  #else
  return pHyp->pHypothesis->CriticalItem.f_distY;
  #endif
}

/*************************************************************************************************************************
  Functionname:         MEDIC_f_GetHypVrelY                                                           */ /*!
  @brief                Returns Hypothesis lateral Relative velocity of object
  @return               float32
  @c_switch_part        @ref MEDIC_ARCHITECTURE_VERSION
  @author               Armin Vogl | armin.vogl@continental-corporation.com
*************************************************************************************************************************/
#if (MEDIC_ARCHITECTURE_VERSION < 0x10)
ALGO_INLINE float32 MEDIC_f_GetHypVrelY(const HEADHypothesis_t *const pHyp)
{
  return pHyp->pHypothesis->fVrelY;
}
#else
// Not available in new architecture: transmitted as absolute values (see MEDIC_f_GetHypVabsY)
#endif

/*************************************************************************************************************************
  Functionname:         MEDIC_f_GetHypVabsY                                                           */ /*!
  @brief                Returns Hypothesis lateral Relative velocity of object
  @return               float32
  @c_switch_part        @ref MEDIC_ARCHITECTURE_VERSION
  @author               Armin Vogl | armin.vogl@continental-corporation.com
*************************************************************************************************************************/
#if (MEDIC_ARCHITECTURE_VERSION >= 0x10)
ALGO_INLINE float32 MEDIC_f_GetHypVabsY(const HEADHypothesis_t *const pHyp)
{
  return pHyp->pHypothesis->CriticalItem.f_vAbsY;
}
#else
// Not available in old architecture: transmitted as relative values (see MEDIC_f_GetHypVrelY)
#endif

/*************************************************************************************************************************
  Functionname:         MEDIC_f_GetHypVabs                                                           */ /*!
  @brief                Returns Hypothesis target velocity
  @return               float32
  @c_switch_part        @ref MEDIC_ARCHITECTURE_VERSION
  @author               Armin Vogl | armin.vogl@continental-corporation.com
*************************************************************************************************************************/
#if (MEDIC_ARCHITECTURE_VERSION >= 0x10)
ALGO_INLINE float32 MEDIC_f_GetHypVabs(const HEADHypothesis_t *const pHyp)
{
  return pHyp->pHypothesis->CriticalItem.f_vAbs;
}
#else
// Not available in old architecture: transmitted as relative values (see MEDIC_f_GetHypVrelY)
#endif

/*************************************************************************************************************************
  Functionname:         MEDIC_f_GetHypAngle                                                           */ /*!
  @brief                Returns Hypothesis target angle
  @return               float32
  @c_switch_part        @ref MEDIC_ARCHITECTURE_VERSION
  @author               Armin Vogl | armin.vogl@continental-corporation.com
*************************************************************************************************************************/
#if (MEDIC_ARCHITECTURE_VERSION >= 0x10)
ALGO_INLINE float32 MEDIC_f_GetHypAngle(const HEADHypothesis_t *const pHyp)
{
  return pHyp->pHypothesis->CriticalItem.f_angle;
}
#else
// Not available in old architecture: transmitted as relative values (see MEDIC_f_GetHypVrelY)
#endif

/*************************************************************************************************************************
  Functionname:         MEDIC_f_GetHypDist                                                           */ /*!
  @brief                Returns Hypothesis shortest distance to target
  @return               float32
  @c_switch_part        @ref MEDIC_ARCHITECTURE_VERSION
  @author               Armin Vogl | armin.vogl@continental-corporation.com
*************************************************************************************************************************/
#if (MEDIC_ARCHITECTURE_VERSION >= 0x10)
ALGO_INLINE float32 MEDIC_f_GetHypDist(const HEADHypothesis_t *const pHyp)
{
  return pHyp->pHypothesis->CriticalItem.f_dist;
}
#else
// Not available in old architecture: transmitted as relative values (see MEDIC_f_GetHypVrelY)
#endif

#if (MEDIC_ARCHITECTURE_VERSION < 0x10)
/*************************************************************************************************************************
  Functionname:         MEDIC_f_GetHypArelY                                                           */ /*!
  @brief                Returns Hypothesis lateral Relative acceleration of object
  @return               float32
  @c_switch_part        @ref MEDIC_ARCHITECTURE_VERSION
  @author               Armin Vogl | armin.vogl@continental-corporation.com
*************************************************************************************************************************/
ALGO_INLINE float32 MEDIC_f_GetHypArelY(const HEADHypothesis_t *const pHyp)
{
  return pHyp->pHypothesis->fArelY;
}
#else
// Not available in new architecture: transmitted as ABS values
#endif

/*************************************************************************************************************************
  Functionname:         MEDIC_f_GetHypVabsX                                                           */ /*!
  @brief                Returns Hypothesis longitudinal Relative velocity of object
  @return               float32
  @c_switch_part        @ref MEDIC_ARCHITECTURE_VERSION
  @author               Armin Vogl | armin.vogl@continental-corporation.com
*************************************************************************************************************************/
#if (MEDIC_ARCHITECTURE_VERSION >= 0x10)
ALGO_INLINE float32 MEDIC_f_GetHypVabsX(const HEADHypothesis_t *const pHyp)
{
  return pHyp->pHypothesis->CriticalItem.f_vAbsX;
}
#else
// Not available in old architecture: transmitted as relative values (see MEDIC_f_GetHypVrelY)
#endif

/*************************************************************************************************************************
  Functionname:         MEDIC_f_GetHypAabsX                                                           */ /*!
  @brief                Returns Hypothesis longitudinal absolute acceleration of object
  @return               float32
  @c_switch_part        @ref MEDIC_ARCHITECTURE_VERSION
  @author               Armin Vogl | armin.vogl@continental-corporation.com
*************************************************************************************************************************/
#if (MEDIC_ARCHITECTURE_VERSION >= 0x10)
ALGO_INLINE float32 MEDIC_f_GetHypAabsX(const HEADHypothesis_t *const pHyp)
{
  return pHyp->pHypothesis->CriticalItem.f_aAbsX;
}
#else
// Not available in old architecture: transmitted as relative values (see MEDIC_f_GetHypVrelY)
#endif

/*************************************************************************************************************************
  Functionname:         MEDIC_f_GetHypAabsy                                                           */ /*!
  @brief                Returns Hypothesis lateral absolute acceleration of object
  @return               float32
  @c_switch_part        @ref MEDIC_ARCHITECTURE_VERSION
  @author               Armin Vogl | armin.vogl@continental-corporation.com
*************************************************************************************************************************/
#if (MEDIC_ARCHITECTURE_VERSION >= 0x10)
ALGO_INLINE float32 MEDIC_f_GetHypAabsy(const HEADHypothesis_t *const pHyp)
{
  return pHyp->pHypothesis->CriticalItem.f_aAbsY;
}
#else
// Not available in old architecture: transmitted as relative values (see MEDIC_f_GetHypVrelY)
#endif

/*************************************************************************************************************************
  Functionname:         MEDIC_f_GetHypClosingVelocity                                                           */ /*!
  @brief                Returns Hypothesis Closing velocity
  @return               float32
  @c_switch_part        @ref MEDIC_ARCHITECTURE_VERSION
  @author               Armin Vogl | armin.vogl@continental-corporation.com
*************************************************************************************************************************/
ALGO_INLINE float32 MEDIC_f_GetHypClosingVelocity(const HEADHypothesis_t *const pHyp)
{
  #if (MEDIC_ARCHITECTURE_VERSION < 0x10)
  return pHyp->pHypothesis->fClosingVelocity;
  #else
  return pHyp->pHypothesis->CriticalItem.f_vRelOnTrajClosing;
  #endif
}

#if ((FCT_HYPOTHESIS_INTFVER >= 28) || (MEDIC_ARCHITECTURE_VERSION >= 0x10))
/*************************************************************************************************************************
  Functionname:         MEDIC_f_GetHypTTMLongPre                                                           */ /*!
  @brief                Returns Hypothesis Time to comfort mitigation
  @return               float32
  @c_switch_part        @ref MEDIC_ARCHITECTURE_VERSION
  @author               Armin Vogl | armin.vogl@continental-corporation.com
*************************************************************************************************************************/
ALGO_INLINE float32 MEDIC_f_GetHypTTMLongPre(const HEADHypothesis_t *const pHyp)
{
  #if (MEDIC_ARCHITECTURE_VERSION < 0x10)
  return pHyp->pHypothesis->fTTMLongPre;
  #else
  return pHyp->pHypothesis->CriticalItem.f_ttaLongPre;
  #endif
}
#endif // end of check for ((FCT HYPOTHESIS_INTFVER >= 28) || (MEDIC ARCHITECTURE_VERSION >= 0x10))


#if ((FCT_HYPOTHESIS_INTFVER >= 28) || (MEDIC_ARCHITECTURE_VERSION >= 0x10))
/*************************************************************************************************************************
  Functionname:         MEDIC_f_GetHypTTMLongAcute                                                           */ /*!
  @brief                Returns Hypothesis Time to acute mitigation
  @return               float32
  @c_switch_part        @ref MEDIC_ARCHITECTURE_VERSION
  @author               Armin Vogl | armin.vogl@continental-corporation.com
*************************************************************************************************************************/
ALGO_INLINE float32 MEDIC_f_GetHypTTMLongAcute(const HEADHypothesis_t *const pHyp)
{
  #if (MEDIC_ARCHITECTURE_VERSION < 0x10)
  return pHyp->pHypothesis->fTTMLongAcute;
  #else
  return pHyp->pHypothesis->CriticalItem.f_ttaLongAcute;
  #endif
}
#endif // end of check for ((FCT HYPOTHESIS_INTFVER >= 28) || (MEDIC ARCHITECTURE_VERSION >= 0x10))

/*************************************************************************************************************************
  Functionname:         MEDIC_f_GetHypItemConfidence                                                           */ /*!
  @brief                Returns item confidence
  @return               uint8
  @c_switch_part        @ref MEDIC_ARCHITECTURE_VERSION
  @author               Sadhanashree Srinivasa | Sadhanashree.Srinivasa@continental-corporation.com
*************************************************************************************************************************/
#if (MEDIC_ARCHITECTURE_VERSION >= 0x10)
ALGO_INLINE uint8 MEDIC_f_GetHypItemConfidence(const HEADHypothesis_t *const pHyp)
{
  return pHyp->pHypothesis->CriticalItem.u_itemConfidence;
}
#else
//Not available in old architecture
#endif

/*************************************************************************************************************************
  Functionname:         MEDIC_f_GetHypInlap                                                           */ /*!
  @brief                Returns Inlap at collision
  @return               float32
  @c_switch_part        @ref MEDIC_ARCHITECTURE_VERSION
  @author               Sadhanashree Srinivasa | Sadhanashree.Srinivasa@continental-corporation.com
*************************************************************************************************************************/
#if (MEDIC_ARCHITECTURE_VERSION >= 0x10)
ALGO_INLINE float32 MEDIC_f_GetHypInlap(const HEADHypothesis_t *const pHyp)
{
  return pHyp->pHypothesis->CriticalItem.f_inlap;
}
#else
//Not available in old architecture
#endif


#if ((FCT_HYPOTHESIS_INTFVER >= 28) || (MEDIC_ARCHITECTURE_VERSION >= 0x10))
/*************************************************************************************************************************
  Functionname:         MEDIC_f_GetHypCorridorStopDist                                                           */ /*!
  @brief                Returns Hypothesis Corridor Stop Distance
  @return               float32
  @c_switch_part        @ref MEDIC_ARCHITECTURE_VERSION
  @author               Armin Vogl | armin.vogl@continental-corporation.com
*************************************************************************************************************************/
#if (MEDIC_ARCHITECTURE_VERSION < 0x10)
ALGO_INLINE float32 MEDIC_f_GetHypCorridorStopDist(const HEADHypothesis_t *const pHyp)
#else
ALGO_INLINE float32 MEDIC_f_GetHypCorridorStopDist(uint8 uiHypNo, uint16 uiCascadeNo)
#endif
{
  #if (MEDIC_ARCHITECTURE_VERSION < 0x10)
  return pHyp->pHypothesis->fCorridorStopDistance;
  #else
   return MEDICAccessData.Input.ReqPorts.brakeTargets->longTargets[uiHypNo].cascadeDependentValues[uiCascadeNo].f_corridorStopDistance;
  #endif
}
#endif // end of check for ((FCT HYPOTHESIS_INTFVER >= 28) || (MEDIC ARCHITECTURE_VERSION >= 0x10))


/*************************************************************************************************************************
  Functionname:         MEDIC_f_GetHypImpactVelEgo                                                                  */ /*!
  @brief                Returns Impact Velocity Ego at collision
  @return               float32
  @c_switch_part        @ref MEDIC_ARCHITECTURE_VERSION
  @author               Balaji Sekar | balaji.2.sekar@continental-corporation.com
*************************************************************************************************************************/
#if (MEDIC_ARCHITECTURE_VERSION >= 0x10)
ALGO_INLINE float32 MEDIC_f_GetHypImpactVelEgo(const uint8 uiHypNo, const uint16 uiCascadeNo)
{
  return MEDICAccessData.Input.ReqPorts.brakeTargets->longTargets[uiHypNo].cascadeDependentValues[uiCascadeNo].f_impactVelEgo;
}
#else
//Not available in old architecture
#endif

/*************************************************************************************************************************
  Functionname:         MEDIC_f_GetHypImpactVelRel                                                                  */ /*!
  @brief                Returns Impact Velocity Relative at collision
  @return               float32
  @c_switch_part        @ref MEDIC_ARCHITECTURE_VERSION
  @author               Balaji Sekar | balaji.2.sekar@continental-corporation.com
*************************************************************************************************************************/
#if (MEDIC_ARCHITECTURE_VERSION >= 0x10)
ALGO_INLINE float32 MEDIC_f_GetHypImpactVelRel(const uint8 uiHypNo, const uint16 uiCascadeNo)
{
  return MEDICAccessData.Input.ReqPorts.brakeTargets->longTargets[uiHypNo].cascadeDependentValues[uiCascadeNo].f_impactVelRel;
}
#else
//Not available in old architecture
#endif

#endif

#if ((MEDIC_CFG_DRIVER_INTENTION_MONITORING)||(MEDIC_CFG_INCLUDE_UNUSED_INTF))
/************************************************************************/
/* DIM                                                                  */
/************************************************************************/

#if (MEDIC_ARCHITECTURE_VERSION < 0x10)
/*************************************************************************************************************************
  Functionname:         MEDIC_p_GetDIMOutCustom                                                           */ /*!
  @brief                Returns  DIM custom output data
  @glob_in              @ref MEDIC_p_GetAccessData
  @return               DIMOutputCustom_t* 
  @c_switch_full        @ref MEDIC_CFG_DRIVER_INTENTION_MONITORING @ref MEDIC_CFG_INCLUDE_UNUSED_INTF
  @author               Nagaraja Veerashettappa  | Nagaraja.Veerashettappa@continental-corporation.com 
*************************************************************************************************************************/
ALGO_INLINE DIMOutputCustom_t const* MEDIC_p_GetDIMOutCustom(void)
{
  return MEDIC_p_GetAccessData()->Output.ProPorts.pDIMOutputCustom;
}
#endif // end of check for (MEDIC ARCHITECTURE_VERSION < 0x10)

#if (MEDIC_ARCHITECTURE_VERSION < 0x10)
/*************************************************************************************************************************
  Functionname:         MEDIC_p_ModDIMOutCustom                                                           */ /*!
  @brief                Returns  DIM custom output data
  @glob_in              @ref MEDIC_p_GetAccessData
  @return               DIMOutputCustom_t* 
  @c_switch_full        @ref MEDIC_CFG_DRIVER_INTENTION_MONITORING @ref MEDIC_CFG_INCLUDE_UNUSED_INTF
  @author               Nagaraja Veerashettappa  | Nagaraja.Veerashettappa@continental-corporation.com 
*************************************************************************************************************************/
ALGO_INLINE DIMOutputCustom_t * MEDIC_p_ModDIMOutCustom(void)
{
  return MEDIC_p_GetAccessData()->Output.ProPorts.pDIMOutputCustom;
}
#endif // end of check for (MEDIC ARCHITECTURE_VERSION < 0x10)

/*************************************************************************************************************************
  Functionname:         MEDIC_p_ModDriverMonitoringState                                                            */ /*!
  @brief                Returns DriverMonitoringState
  @return               uint8 *
  @glob_in              @ref MEDIC_p_ModDIMOutCustom @ref MEDIC_p_ModdimOutput
  @c_switch_part        @ref MEDIC_ARCHITECTURE_VERSION 
  @author               Nagaraja Veerashettappa  | Nagaraja.Veerashettappa@continental-corporation.com
*************************************************************************************************************************/
ALGO_INLINE  uint8 * MEDIC_p_ModDriverMonitoringState(void)
{ 
  #if (MEDIC_ARCHITECTURE_VERSION < 0x10)
  return &(MEDIC_p_ModDIMOutCustom()->eDriverMonitoringState);
  #else
  return &(MEDIC_p_ModdimOutput()->eDriverMonitoringState);
  #endif 
}

/*************************************************************************************************************************
  Functionname:         MEDIC_p_ModDriverAttentionState                                                            */ /*!
  @brief                Returns DriverAttentionState
  @return               uint8 *
  @glob_in              @ref MEDIC_p_ModHeadOutCustom @ref MEDIC_p_ModdimOutput
  @c_switch_part        @ref MEDIC_ARCHITECTURE_VERSION 
  @author               Nagaraja Veerashettappa  | Nagaraja.Veerashettappa@continental-corporation.com
*************************************************************************************************************************/
ALGO_INLINE  uint8 * MEDIC_p_ModDriverAttentionState(void)
{ 
  #if (MEDIC_ARCHITECTURE_VERSION < 0x10)
  return &(MEDIC_p_ModDIMOutCustom()->eDriverAttentionState);
  #else
  return &(MEDIC_p_ModdimOutput()->eDriverAttentionState);
  #endif 
}
/*************************************************************************************************************************
  Functionname:         MEDIC_p_ModDriverFeedbackState                                                            */ /*!
  @brief                Returns DriverFeedbackState
  @return               uint8 *
  @glob_in              @ref MEDIC_p_ModDIMOutCustom @ref MEDIC_p_ModdimOutput
  @c_switch_part        @ref MEDIC_ARCHITECTURE_VERSION
  @author               Nagaraja Veerashettappa  | Nagaraja.Veerashettappa@continental-corporation.com
*************************************************************************************************************************/
ALGO_INLINE  uint8 * MEDIC_p_ModDriverFeedbackState(void)
{ 
  #if (MEDIC_ARCHITECTURE_VERSION < 0x10)
  return &(MEDIC_p_ModDIMOutCustom()->eDriverFeedbackState);
  #else
  return &(MEDIC_p_ModdimOutput()->eDriverFeedbackState);
  #endif 
}

/*************************************************************************************************************************
  Functionname:         MEDIC_p_ModDriverActivityState                                                            */ /*!
  @brief                Returns DriverActivityState
  @return               uint8 *
  @glob_in              @ref MEDIC_p_ModDIMOutCustom @ref MEDIC_p_ModdimOutput
  @c_switch_part        @ref MEDIC_ARCHITECTURE_VERSION 
  @author               Nagaraja Veerashettappa  | Nagaraja.Veerashettappa@continental-corporation.com
*************************************************************************************************************************/
ALGO_INLINE  uint8 * MEDIC_p_ModDriverActivityState(void)
{ 
  #if (MEDIC_ARCHITECTURE_VERSION < 0x10)
  return &(MEDIC_p_ModDIMOutCustom()->eDriverActivityState);
  #else
  return &(MEDIC_p_ModdimOutput()->eDriverActivityState);
  #endif 
}

/*************************************************************************************************************************
  Functionname:         MEDIC_p_ModDimOutSigStatus                                                            */ /*!
  @brief                Returns DimOutSigStatus
  @return               uint8 *
  @glob_in              @ref MEDIC_p_ModDIMOutCustom @ref MEDIC_p_ModdimOutput
  @c_switch_part        @ref MEDIC_ARCHITECTURE_VERSION
  @author               Nagaraja Veerashettappa  | Nagaraja.Veerashettappa@continental-corporation.com
*************************************************************************************************************************/
ALGO_INLINE  uint8 * MEDIC_p_ModDimOutSigStatus(void)
{ 
  #if (MEDIC_ARCHITECTURE_VERSION < 0x10)
  return &(MEDIC_p_ModDIMOutCustom()->sSigHeader.eSigStatus);
  #else
  return &(MEDIC_p_ModdimOutput()->sigHeader.eSigStatus);
  #endif 
}

#if (MEDIC_ARCHITECTURE_VERSION < 0x10)
/*************************************************************************************************************************
  Functionname:         MEDIC_p_GetDIMInCustom                                                           */ /*!
  @brief                Returns  DIM custom input data
  @glob_in              @ref MEDIC_p_GetAccessData
  @return               DIMInputCustom_t const*
  @c_switch_full        @ref MEDIC_CFG_DRIVER_INTENTION_MONITORING @ref MEDIC_CFG_INCLUDE_UNUSED_INTF
  @author               Nagaraja Veerashettappa  | Nagaraja.Veerashettappa@continental-corporation.com 
*************************************************************************************************************************/
ALGO_INLINE DIMInputCustom_t const* MEDIC_p_GetDIMInCustom(void)
{
  return MEDIC_p_GetAccessData()->Input.ReqPorts.pDIMInputCustom;
}
#endif // end of check for (MEDIC ARCHITECTURE_VERSION < 0x10)

#if (MEDIC_ARCHITECTURE_VERSION < 0x10)
/*************************************************************************************************************************
  Functionname:         MEDIC_p_GetDIMInGeneric                                                           */ /*!
  @brief                Returns  DIM generic input data
  @glob_in              @ref MEDIC_p_GetAccessData
  @return               DIMInputGeneric_t const*
  @c_switch_full        @ref MEDIC_CFG_DRIVER_INTENTION_MONITORING @ref MEDIC_CFG_INCLUDE_UNUSED_INTF
  @author               Nagaraja Veerashettappa  | Nagaraja.Veerashettappa@continental-corporation.com 
*************************************************************************************************************************/
ALGO_INLINE DIMInputGeneric_t const* MEDIC_p_GetDIMInGeneric(void)
{
  return MEDIC_p_GetAccessData()->Input.ReqPorts.pDIMInputGeneric;
}
#endif // end of check for (MEDIC ARCHITECTURE_VERSION < 0x10)
#endif // MEDIC_CFG_DRIVER_INTENTION_MONITORING

#endif // MEDIC_CFG_EMERGENCY_BRAKE_ASSIST
#endif // MEDIC_ACCESS_H_INCLUDED




