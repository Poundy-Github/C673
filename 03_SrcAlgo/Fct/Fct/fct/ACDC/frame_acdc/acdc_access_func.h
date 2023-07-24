/*! \file **********************************************************************

COMPANY:                   COPYRIGHT (C) Continental AG
  
PROJECT:                   Mainstream

CPU:                       CPU-Independent

COMPONENT:                 ACDC -(Advanced collision detection and classification)

PACKAGENAME:               acdc_access_func.h

DESCRIPTION:               Definitions of inline functions to access global data

AUTHOR:                    $Author: BORAIAH, KOMALA (uidk2011) (uidk2011) $

CREATION DATE:             $Date: 2020/07/20 09:42:24CEST $

VERSION:                   $Revision: 1.53 $

**************************************************************************** */

#ifndef ACDC_ACCESS_H_INCLUDED
#define ACDC_ACCESS_H_INCLUDED

/*****************************************************************************
  INCLUDES
*****************************************************************************/
#include "acdc_mem.h"

#if (ACDC_CFG_FRAME)
/*****************************************************************************
  MODULE DESCRIPTION
*****************************************************************************/
/**
\addtogroup frame
\{
*/

/*****************************************************************************
  GLOBAL VARIABLES
*****************************************************************************/
extern MEMSEC_REF ACDCAccessData_t                  ACDCAccessData;


/*****************************************************************************
  INLINE FUNCTIONS
*****************************************************************************/

/* Deactivate QA-C warning 3406; Reviewer: S. Schwarzkopf; Date: 05.12.2014; 
   Reason: Styleguide specifies this as best practice (R231, R238) and 
   ALGO_INLINE is defined compiler dependent for inlining with internal linkage.
   Review-ID: */
/* PRQA S 3406 ALGO_INLINES */
/**************/

/* Check if we are in QA-C: PRQA_SIZE_T is defined in QA-C environment. */
#ifdef PRQA_SIZE_T
  /* date: 2017-01-11, reviewer: V.Ehrlinspiel, A.Kramer, reason:  
     Macro ACDC_ASSERT can be set up platform dependent and is intended to have 
     no side effects here.
     Review-ID: 
  */
#pragma PRQA_MACRO_MESSAGES_OFF "ACDC_ASSERT" 3112


  /* Switch off QA-C warnings on side effects for functions, which don't have 
     any side effects and will sure never have some. */
#pragma PRQA_NO_SIDE_EFFECTS ACDC_p_GetWorkingData
#pragma PRQA_NO_SIDE_EFFECTS ACDC_p_GetInput
#pragma PRQA_NO_SIDE_EFFECTS ACDC_p_GetOutput
#pragma PRQA_NO_SIDE_EFFECTS ACDC_p_GetPortHandlerList
#pragma PRQA_NO_SIDE_EFFECTS ACDC_p_GetReqPortList
#pragma PRQA_NO_SIDE_EFFECTS ACDC_p_GetProPortList
#pragma PRQA_NO_SIDE_EFFECTS ACDC_p_GetSLATE_CD_DataPointer
#pragma PRQA_NO_SIDE_EFFECTS ACDC_p_GetServiceFunctionsList
#pragma PRQA_NO_SIDE_EFFECTS ACDC_p_GetFrameData
#pragma PRQA_NO_SIDE_EFFECTS ACDC_p_GetSyncRef
#pragma PRQA_NO_SIDE_EFFECTS ACDC_p_GetRuntimeInfo
#pragma PRQA_NO_SIDE_EFFECTS ACDC_p_GetCDParameters
#pragma PRQA_NO_SIDE_EFFECTS ACDC_p_GetIntHypothesesData
#pragma PRQA_NO_SIDE_EFFECTS ACDC_p_GetEgoDrvScenario
#pragma PRQA_NO_SIDE_EFFECTS ACDC_p_GetCurrentIntHypotheses
#pragma PRQA_NO_SIDE_EFFECTS ACDC_p_GetCurrentIntHypothesis
#pragma PRQA_NO_SIDE_EFFECTS ACDC_p_GetPrevIntHypotheses
#pragma PRQA_NO_SIDE_EFFECTS ACDC_p_GetPrevIntHypothesis
#pragma PRQA_NO_SIDE_EFFECTS ACDC_p_GetObjHypothesisData
#pragma PRQA_NO_SIDE_EFFECTS ACDC_p_GetObjTTXData
#pragma PRQA_NO_SIDE_EFFECTS ACDC_p_GetObjEvasionData
#pragma PRQA_NO_SIDE_EFFECTS ACDC_p_GetObjStaticEvasionData
#pragma PRQA_NO_SIDE_EFFECTS ACDC_p_GetTrafoMatForward
#pragma PRQA_NO_SIDE_EFFECTS ACDC_p_GetTrafoMatBackward
#pragma PRQA_NO_SIDE_EFFECTS ACDC_p_GetMostRelevantEPFHyp
#pragma PRQA_NO_SIDE_EFFECTS ACDC_p_GetEPFCorridorData
#pragma PRQA_NO_SIDE_EFFECTS ACDC_p_GetObjKinematicHistory
#pragma PRQA_NO_SIDE_EFFECTS ACDC_p_GetObjQualifier
#pragma PRQA_NO_SIDE_EFFECTS ACDC_p_GetPerformanceDegrationData
#pragma PRQA_NO_SIDE_EFFECTS ACDC_p_GetEMGenObjList
#pragma PRQA_NO_SIDE_EFFECTS ACDC_p_GetEMGenObj
#pragma PRQA_NO_SIDE_EFFECTS ACDC_p_GetEMGenObjKinematics
#pragma PRQA_NO_SIDE_EFFECTS ACDC_p_GetEMGenObjQualifiers
#pragma PRQA_NO_SIDE_EFFECTS ACDC_p_GetEMGenObjAttributes
#pragma PRQA_NO_SIDE_EFFECTS ACDC_p_GetEMGenObjGeneral
#pragma PRQA_NO_SIDE_EFFECTS ACDC_p_GetEMGenObjGeometry
#pragma PRQA_NO_SIDE_EFFECTS ACDC_b_GetEMGenObjIsDeleted
#pragma PRQA_NO_SIDE_EFFECTS ACDC_b_GetEMGenObjIsNew
#pragma PRQA_NO_SIDE_EFFECTS ACDC_p_GetEMARSObjList
#pragma PRQA_NO_SIDE_EFFECTS ACDC_p_GetEMARSObj
#pragma PRQA_NO_SIDE_EFFECTS ACDC_p_GetEMARSObjAttributes
#pragma PRQA_NO_SIDE_EFFECTS ACDC_p_GetEMARSObjGeometry
#pragma PRQA_NO_SIDE_EFFECTS ACDC_p_GetEMARSObjKinematic
#pragma PRQA_NO_SIDE_EFFECTS ACDC_p_GetEMARSObjLegacy
#pragma PRQA_NO_SIDE_EFFECTS ACDC_p_GetEMARSObjMotionAttributes
#pragma PRQA_NO_SIDE_EFFECTS ACDC_b_GetObjIsMovingToStationary
#pragma PRQA_NO_SIDE_EFFECTS ACDC_p_GetEMARSObjSensorSpecific
#pragma PRQA_NO_SIDE_EFFECTS ACDC_p_GetEMFusionObjList
#pragma PRQA_NO_SIDE_EFFECTS ACDC_p_GetEMFusionObj
#pragma PRQA_NO_SIDE_EFFECTS ACDC_p_GetEMCAMObjList
#pragma PRQA_NO_SIDE_EFFECTS ACDC_p_GetEMCAMObj
#pragma PRQA_NO_SIDE_EFFECTS ACDC_p_GetVDYDynObjSync
#pragma PRQA_NO_SIDE_EFFECTS ACDC_f_GetEgoVelObjSync
#pragma PRQA_NO_SIDE_EFFECTS ACDC_f_GetEgoAccelObjSync
#pragma PRQA_NO_SIDE_EFFECTS ACDC_p_GetVDYDynRaw
#pragma PRQA_NO_SIDE_EFFECTS ACDC_f_GetEgoVelRaw
#pragma PRQA_NO_SIDE_EFFECTS ACDC_f_GetEgoAccelRaw
#pragma PRQA_NO_SIDE_EFFECTS ACDC_p_GetVehPar
#pragma PRQA_NO_SIDE_EFFECTS ACDC_p_GetSensorMounting
#pragma PRQA_NO_SIDE_EFFECTS ACDC_u_GetIOStateEgoSpeedX
#pragma PRQA_NO_SIDE_EFFECTS ACDC_u_GetIOStateEgoAccelX
#pragma PRQA_NO_SIDE_EFFECTS ACDC_u_GetIOStateEgoAccelY
#pragma PRQA_NO_SIDE_EFFECTS ACDC_u_GetIOStateEgoYawRate
#pragma PRQA_NO_SIDE_EFFECTS ACDC_u_GetIOStateEgoCurve
#pragma PRQA_NO_SIDE_EFFECTS ACDC_u_GetIOStateEgoMotion
#pragma PRQA_NO_SIDE_EFFECTS ACDC_u_GetEgoMotionState
#pragma PRQA_NO_SIDE_EFFECTS ACDC_p_GetEmFctCycleMode
#pragma PRQA_NO_SIDE_EFFECTS ACDC_f_GetCycleTime
#pragma PRQA_NO_SIDE_EFFECTS ACDC_p_GetAlnMonInput
#pragma PRQA_NO_SIDE_EFFECTS ACDC_p_GetCDCustomOutput
#pragma PRQA_NO_SIDE_EFFECTS ACDC_p_GetHypothesisIntf
#pragma PRQA_NO_SIDE_EFFECTS ACDC_p_GetExtHypothesis
#pragma PRQA_NO_SIDE_EFFECTS ACDC_p_GetHypDegradation
#pragma PRQA_NO_SIDE_EFFECTS ACDC_p_GetAlgoParameters
#pragma PRQA_NO_SIDE_EFFECTS ACDC_p_GetEgoData
#pragma PRQA_NO_SIDE_EFFECTS ACDC_p_GetEgoGeometry
#pragma PRQA_NO_SIDE_EFFECTS ACDC_p_GetEgoMovementRaw
#pragma PRQA_NO_SIDE_EFFECTS ACDC_p_GetEgoMovementObjSync
#pragma PRQA_NO_SIDE_EFFECTS ACDC_p_GetEgoKinematics
#pragma PRQA_NO_SIDE_EFFECTS ACDC_p_GetEgoTrajCircle
#pragma PRQA_NO_SIDE_EFFECTS ACDC_p_GetObjDesc
#pragma PRQA_NO_SIDE_EFFECTS ACDC_p_GetACDCObjectMain
#pragma PRQA_NO_SIDE_EFFECTS ACDC_p_GetObjMovement
#pragma PRQA_NO_SIDE_EFFECTS ACDC_p_GetObjPositions
#pragma PRQA_NO_SIDE_EFFECTS ACDC_p_GetObjTrajRelation
#pragma PRQA_NO_SIDE_EFFECTS ACDC_a_GetObjShapePointQualities
#pragma PRQA_NO_SIDE_EFFECTS ACDC_p_GetObjGeometry
#pragma PRQA_NO_SIDE_EFFECTS ACDC_a_GetObjLimitedShapePoints
#pragma PRQA_NO_SIDE_EFFECTS ACDC_p_GetObjDescMain
#endif /* #ifdef PRQA_SIZE_T */

/************************************************************************/
/*                      ASSERT MACRO                                    */
/************************************************************************/
#define ACDC_ASSERT(x) CML_ASSERT(x)


ALGO_INLINE ACDCAccessData_t const * ACDC_p_GetAccessData(void);
ALGO_INLINE ACDCAccessData_t * ACDC_p_ModAccessData(void);
ALGO_INLINE ACDC_Working_t  * ACDC_p_ModWorkingData(void);
ALGO_INLINE ACDC_Working_t const * ACDC_p_GetWorkingData(void);
ALGO_INLINE ACDC_Input_t const * ACDC_p_GetInput(void);
ALGO_INLINE ACDC_Output_t const * ACDC_p_GetOutput(void);
ALGO_INLINE ACDC_Output_t * ACDC_p_ModOutput(void);
ALGO_INLINE ACDCPortHandlerList_t const * ACDC_p_GetPortHandlerList(void);
ALGO_INLINE ACDCPortHandlerList_t * ACDC_p_ModPortHandlerList(void);
ALGO_INLINE reqACDCPrtList_t const * ACDC_p_GetReqPortList(void);
ALGO_INLINE provACDCPrtList_t const * ACDC_p_GetProPortList(void);
ALGO_INLINE provACDCPrtList_t * ACDC_p_ModProPortList(void);
#if ((FCT_CFG_COLLISION_DETECTION)&&(FCT_CFG_ADAPTIVE_CRUISE_CONTROL))
ALGO_INLINE SLATE_CD_Data_t const * ACDC_p_GetSLATE_CD_DataPointer(void);
#endif
#if (FCT_CFG_USE_SERVICE_POINTER_FUNCTS)
ALGO_INLINE AS_t_ServiceFuncts const * ACDC_p_GetServiceFunctionsList(void);
#endif
ALGO_INLINE ACDCFrame_t const * ACDC_p_GetFrameData(void);
ALGO_INLINE ACDCFrame_t * ACDC_p_ModFrameData(void);
ALGO_INLINE ACDCSyncRef_t const * ACDC_p_GetSyncRef(void);
ALGO_INLINE ACDCSyncRef_t * ACDC_p_ModSyncRef(void);
#if (FCT_CFG_RUNTIME_MEAS)
ALGO_INLINE ACDCRuntimeInfo_t const * ACDC_p_GetRuntimeInfo (void);
ALGO_INLINE ACDCRuntimeInfo_t  * ACDC_p_ModRuntimeInfo (void);
#endif
#if (ACDC_CFG_AIP)
ALGO_INLINE GDBTrafoMatrix2D_t const * ACDC_p_GetTrafoMatForward       (void);
ALGO_INLINE GDBTrafoMatrix2D_t  * ACDC_p_ModTrafoMatForward       (void);
ALGO_INLINE GDBTrafoMatrix2D_t const * ACDC_p_GetTrafoMatBackward       (void);
ALGO_INLINE GDBTrafoMatrix2D_t  * ACDC_p_ModTrafoMatBackward       (void);
#endif /*(ACDC_CFG_AIP)*/
#if (ACDC_CFG_CD) 
ALGO_INLINE CDParameters_t const * ACDC_p_GetCDParameters (void);
ALGO_INLINE CDParameters_t * ACDC_p_ModCDParameters (void);
ALGO_INLINE CDIntHypothesesData_t const * ACDC_p_GetIntHypothesesData (void);
ALGO_INLINE CDIntHypothesesData_t * ACDC_p_ModIntHypothesesData (void);
#if (CD_USE_TURNINTOVRU_HYPOTHESIS)
ALGO_INLINE CDEgoDrvScenario_t const * ACDC_p_GetEgoDrvScenario (void);
ALGO_INLINE CDEgoDrvScenario_t * ACDC_p_ModEgoDrvScenario (void);
#endif /* (CD_USE_TURNINTOVRU_HYPOTHESIS) */
ALGO_INLINE CDIntHypotheses_t const * ACDC_p_GetCurrentIntHypotheses       (void);
ALGO_INLINE CDIntHypotheses_t * ACDC_p_ModCurrentIntHypotheses       (void);
ALGO_INLINE CDIntHypothesis_t const * ACDC_p_GetCurrentIntHypothesis (uint32 uHypID);
ALGO_INLINE CDIntHypothesis_t * ACDC_p_ModCurrentIntHypothesis (uint32 uHypID);
ALGO_INLINE CDIntHypotheses_t const * ACDC_p_GetPrevIntHypotheses       (void);
ALGO_INLINE CDIntHypotheses_t * ACDC_p_ModPrevIntHypotheses       (void);
ALGO_INLINE CDIntHypothesis_t const * ACDC_p_GetPrevIntHypothesis       (uint32 uHypID);
ALGO_INLINE CDIntHypothesis_t * ACDC_p_ModPrevIntHypothesis       (uint32 uHypID);
ALGO_INLINE CDObj_Hypothesis_t const * ACDC_p_GetObjHypothesisData       (ObjNumber_t const iObj);
ALGO_INLINE CDObj_Hypothesis_t  * ACDC_p_ModObjHypothesisData       (ObjNumber_t const iObj);
ALGO_INLINE CDObj_TTX_t const * ACDC_p_GetObjTTXData       (ObjNumber_t const iObj);
ALGO_INLINE CDObj_TTX_t  * ACDC_p_ModObjTTXData       (ObjNumber_t const iObj);
ALGO_INLINE CDObj_Evasion_t const * ACDC_p_GetObjEvasionData       (ObjNumber_t const iObj);
ALGO_INLINE CDObj_Evasion_t  * ACDC_p_ModObjEvasionData       (ObjNumber_t const iObj);
ALGO_INLINE CDObj_EvasionStatic_t const * ACDC_p_GetObjStaticEvasionData       (ObjNumber_t const iObj);
ALGO_INLINE CDObj_EvasionStatic_t  * ACDC_p_ModObjStaticEvasionData       (ObjNumber_t const iObj);
#if (CD_USE_EPF)
ALGO_INLINE Hypothesis_t const * ACDC_p_GetMostRelevantEPFHyp(void);
#if defined(CD_EPF_CORRIDOR_FREEZE) && (CD_EPF_CORRIDOR_FREEZE == SWITCH_ON)
ALGO_INLINE EPFCorridorData_t const * ACDC_p_GetEPFCorridorData   (void);
ALGO_INLINE EPFCorridorData_t  * ACDC_p_ModEPFCorridorData       (void);
#endif
#endif
#if (CD_USE_GEN_PSC)
ALGO_INLINE CDKinHistObj_t const * ACDC_p_GetObjKinematicHistory       (ObjNumber_t const iObj);
ALGO_INLINE CDKinHistObj_t  * ACDC_p_ModObjKinematicHistory       (ObjNumber_t const iObj);
#endif
#if defined(CD_USE_FUS_OBJ_LIST_FOR_SEN_SOURCE) && (CD_USE_FUS_OBJ_LIST_FOR_SEN_SOURCE==SWITCH_ON)
ALGO_INLINE CDQualifier_t const * ACDC_p_GetObjQualifier       (ObjNumber_t const iObj);
ALGO_INLINE CDQualifier_t * ACDC_p_ModObjQualifier       (ObjNumber_t const iObj);
#endif
#endif /*(ACDC_CFG_CD)*/ 
#if (ACDC_CFG_ESPM)
ALGO_INLINE PerformanceDegrationData_t const * ACDC_p_GetPerformanceDegrationData       (void);
ALGO_INLINE PerformanceDegrationData_t * ACDC_p_ModPerformanceDegrationData       (void);
#endif
ALGO_INLINE EM_t_GenObjectList const * ACDC_p_GetEMGenObjList(void);
ALGO_INLINE EM_t_GenObject const * ACDC_p_GetEMGenObj(ObjNumber_t const iObj);
#if(ACDC_AIP_CFG_SHIFT_COORDINATE)
ALGO_INLINE EM_t_GenObjKinematics * ACDC_p_GetEMGenObjKinematics(ObjNumber_t const iObj);
#else
ALGO_INLINE EM_t_GenObjKinematics const * ACDC_p_GetEMGenObjKinematics(ObjNumber_t const iObj);
#endif
#if(ACDC_CFG_USE_FPS)
ALGO_INLINE EM_t_GenObjQualifiers * ACDC_p_GetEMGenObjQualifiers(ObjNumber_t const iObj);  //For FPS .....@Cheng Long
#else
ALGO_INLINE EM_t_GenObjQualifiers const * ACDC_p_GetEMGenObjQualifiers(ObjNumber_t const iObj);
#endif
ALGO_INLINE EM_t_GenObjAttributes const * ACDC_p_GetEMGenObjAttributes(ObjNumber_t const iObj);
ALGO_INLINE EM_t_GenObjGenerals const * ACDC_p_GetEMGenObjGeneral(ObjNumber_t const iObj);
#if(ACDC_AIP_CFG_SHIFT_COORDINATE)
ALGO_INLINE EM_t_GenObjGeometry * ACDC_p_GetEMGenObjGeometry(ObjNumber_t const iObj);
#else
ALGO_INLINE EM_t_GenObjGeometry const * ACDC_p_GetEMGenObjGeometry(ObjNumber_t const iObj);
#endif
ALGO_INLINE  boolean ACDC_b_GetEMGenObjIsDeleted(ObjNumber_t const iObj);
ALGO_INLINE boolean ACDC_b_GetEMGenObjIsNew(ObjNumber_t const iObj);
#if (FCT_USE_EM_ARS_TECH_OBJECT_LIST)
ALGO_INLINE EM_t_ARSObjectList const * ACDC_p_GetEMARSObjList(void);
ALGO_INLINE EM_t_ARSObject const * ACDC_p_GetEMARSObj(ObjNumber_t const iObj);
ALGO_INLINE EM_t_ARS_Attributes  const * ACDC_p_GetEMARSObjAttributes(ObjNumber_t const iObj);
ALGO_INLINE EM_t_ARS_Geometry  const * ACDC_p_GetEMARSObjGeometry(ObjNumber_t const iObj);
ALGO_INLINE EM_t_ARS_Kinematic  const * ACDC_p_GetEMARSObjKinematic(ObjNumber_t const iObj);
ALGO_INLINE EM_t_ARS_Legacy  const * ACDC_p_GetEMARSObjLegacy(ObjNumber_t const iObj);
ALGO_INLINE EM_t_ARS_MotionAttributes  const * ACDC_p_GetEMARSObjMotionAttributes(ObjNumber_t const iObj);
ALGO_INLINE boolean ACDC_b_GetObjIsMovingToStationary(ObjNumber_t const iObj);
ALGO_INLINE EM_t_ARS_SensorSpecific  const * ACDC_p_GetEMARSObjSensorSpecific(ObjNumber_t const iObj);
#endif /* (FCT_USE_EM_ARS_TECH_OBJECT_LIST) */
#if (FCT_CFG_INCLUDE_FUSION_OBJECT_LIST)
ALGO_INLINE EM_t_FusionObjectList         const * ACDC_p_GetEMFusionObjList            (void            );
ALGO_INLINE EM_t_FusionObject             const * ACDC_p_GetEMFusionObj                (ObjNumber_t const iObj);
#endif
#if (FCT_USE_EM_CAM_TECH_OBJECT_LIST)
ALGO_INLINE EM_t_CamObjectList const * ACDC_p_GetEMCAMObjList(void);
ALGO_INLINE EM_t_CamObject const * ACDC_p_GetEMCAMObj(ObjNumber_t const iObj);
#endif
ALGO_INLINE VehDyn_t const * ACDC_p_GetVDYDynObjSync(void);
ALGO_INLINE float32 ACDC_f_GetEgoVelObjSync(void);
ALGO_INLINE float32 ACDC_f_GetEgoAccelObjSync(void);
ALGO_INLINE VehDyn_t const *  ACDC_p_GetVDYDynRaw(void);
ALGO_INLINE float32 ACDC_f_GetEgoVelRaw(void);
ALGO_INLINE float32 ACDC_f_GetEgoAccelRaw(void);
ALGO_INLINE VehPar_t const *  ACDC_p_GetVehPar(void);
ALGO_INLINE SensorMounting_t const *  ACDC_p_GetSensorMounting(void);
ALGO_INLINE  VDYIoStateTypes_t  ACDC_u_GetIOStateEgoSpeedX(void);
ALGO_INLINE  VDYIoStateTypes_t  ACDC_u_GetIOStateEgoAccelX(void);
ALGO_INLINE  VDYIoStateTypes_t  ACDC_u_GetIOStateEgoAccelY(void);
ALGO_INLINE  VDYIoStateTypes_t  ACDC_u_GetIOStateEgoYawRate(void);
ALGO_INLINE  VDYIoStateTypes_t  ACDC_u_GetIOStateEgoCurve(void);
ALGO_INLINE  VDYIoStateTypes_t  ACDC_u_GetIOStateEgoMotion(void);
ALGO_INLINE  MotState_t  ACDC_u_GetEgoMotionState(void);
#if (FCT_CFG_EM_FCT_CYCLEMODE)
ALGO_INLINE EmFctCycleMode_t  const *  ACDC_p_GetEmFctCycleMode(void);
#endif
ALGO_INLINE float32 ACDC_f_GetCycleTime(void);
#if (FCT_CFG_ALIGNMENT_MONITORING_INPUT)
ALGO_INLINE ALN_S_Monitoring_t const *  ACDC_p_GetAlnMonInput(void);
#endif
#if (FCT_CFG_CD_CUSTOM_OUTPUT_INTERFACE)
ALGO_INLINE FCTCDOutputCustom_t const *  ACDC_p_GetCDCustomOutput(void);
ALGO_INLINE FCTCDOutputCustom_t *  ACDC_p_ModCDCustomOutput(void);
#endif
#if (FCT_CFG_COLLISION_DETECTION)
ALGO_INLINE HypothesisIntf_t const *  ACDC_p_GetHypothesisIntf(void);
ALGO_INLINE HypothesisIntf_t *  ACDC_p_ModHypothesisIntf(void);
ALGO_INLINE Hypothesis_t const *  ACDC_p_GetExtHypothesis(sint32 iHyp);
ALGO_INLINE Hypothesis_t *  ACDC_p_ModExtHypothesis(sint32 iHyp);
ALGO_INLINE HypoIntfDegr_t const *  ACDC_p_GetHypDegradation(void);
ALGO_INLINE HypoIntfDegr_t *  ACDC_p_ModHypDegradation(void);
#endif
#if (FCT_CFG_BSW_ALGO_PARAMS)
ALGO_INLINE BSW_s_AlgoParameters_t const *  ACDC_p_GetAlgoParameters(void);
#endif
#if(ACDC_CFG_AIP)
ALGO_INLINE ACDCEgoData_t const * ACDC_p_GetEgoData (void);
ALGO_INLINE ACDCEgoData_t  * ACDC_p_ModEgoData (void);
ALGO_INLINE ACDCGeometry_t const * ACDC_p_GetEgoGeometry(void);
ALGO_INLINE SFLMovement_t const * ACDC_p_GetEgoMovementRaw(void);
ALGO_INLINE SFLMovement_t const * ACDC_p_GetEgoMovementObjSync(void);
ALGO_INLINE ACDCKinEgo_t const * ACDC_p_GetEgoKinematics(void);
ALGO_INLINE SFLCircle_t const * ACDC_p_GetEgoTrajCircle(void);
ALGO_INLINE ACDCObject_t const * ACDC_p_GetObjDesc(ObjNumber_t const iObjectIndex);
ALGO_INLINE ACDCObject_t * ACDC_p_ModObjDesc(ObjNumber_t const iObjectIndex);
ALGO_INLINE ACDCObjDescMain_t const * ACDC_p_GetObjDescMain(ObjNumber_t const iObjectIndex);
ALGO_INLINE ACDCObjMovement_t const * ACDC_p_GetObjMovement(ObjNumber_t const iObjectIndex);
ALGO_INLINE ACDCObjPositions_t const * ACDC_p_GetObjPositions(ObjNumber_t const iObjectIndex);
ALGO_INLINE ACDCObjToTrajRelation_t const * ACDC_p_GetObjTrajRelation(ObjNumber_t const iObjectIndex);
ALGO_INLINE float32 const * ACDC_a_GetObjShapePointQualities(ObjNumber_t const iObjectIndex);
ALGO_INLINE ACDCGeometry_t const * ACDC_p_GetObjGeometry(ObjNumber_t const iObjectIndex);
ALGO_INLINE SFLVector2D_t const * ACDC_a_GetObjLimitedShapePoints(ObjNumber_t const iObjectIndex);
#endif /* (ACDC_CFG_AIP) */

/*************************************************************************************************************************
  Functionname:         ACDC_p_GetAccessData                                                                         */ /*!
  @brief                Returns the const pointer to the access data structure.
  @glob_in              @ref ACDCAccessData
  @return               ACDCAccessData_t const *

  @pre                  None

  @post                 None

  @InOutCorrelation     see description

  @testmethod           @ref TEST_ACDC_P_GETACCESSDATA_001

  @traceability          Design Decision

  @author               Andreas Kramer
*************************************************************************************************************************/
ALGO_INLINE ACDCAccessData_t const * ACDC_p_GetAccessData(void)
{
  return &ACDCAccessData;
}

/*************************************************************************************************************************
  Functionname:         ACDC_p_ModAccessData                                                                         */ /*!
  @brief                Returns the mutable pointer to the access data structure.
  @glob_in              @ref ACDCAccessData
  @return               ACDCAccessData_t *
  @pre                  None

  @post                 None

  @InOutCorrelation     see description

  @testmethod           @ref TEST_ACDC_P_MODACCESSDATA_001

  @traceability          Design Decision
  @author               Andreas Kramer
*************************************************************************************************************************/
ALGO_INLINE ACDCAccessData_t * ACDC_p_ModAccessData(void)
{
  return &ACDCAccessData;
}

/*************************************************************************************************************************
  Functionname:         ACDC_p_ModWorkingData                                                                         */ /*!
  @brief                Returns the mutable pointer to the working data
  @glob_in              @ref ACDC_p_ModAccessData
  @return               ACDC_Working_t const *

  @pre                  None

  @post                 None

  @InOutCorrelation     see description

  @testmethod           @ref TEST_ACDC_P_MODWORKINGDATA_001

  @traceability          Design Decision

  @author               Andreas Kramer
*************************************************************************************************************************/
ALGO_INLINE ACDC_Working_t  * ACDC_p_ModWorkingData(void)
{
  return &ACDC_p_ModAccessData()->Working;
}

/*************************************************************************************************************************
  Functionname:         ACDC_p_GetWorkingData                                                                         */ /*!
  @brief                Returns the const pointer to the working data
  @glob_in              @ref ACDC_p_GetAccessData
  @return               ACDC_Working_t const *
  
  @pre                  None

  @post                 None

  @InOutCorrelation     see description

  @testmethod           @ref TEST_ACDC_P_GETWORKINGDATA_001

  @traceability          Design Decision
  @author               Andreas Kramer
*************************************************************************************************************************/
ALGO_INLINE ACDC_Working_t const * ACDC_p_GetWorkingData(void)
{
  return &ACDC_p_GetAccessData()->Working;
}

/*************************************************************************************************************************
  Functionname:         ACDC_p_GetInput                                                                         */ /*!
  @brief                Returns the const pointer to the inputs
  @glob_in              @ref ACDC_p_GetAccessData
  @return               ACDC_Input_t const *
  
  @pre                  None

  @post                 None

  @InOutCorrelation     see description

  @testmethod           @ref TEST_ACDC_P_GETINPUT_001

  @traceability          Design Decision

  @author               Andreas Kramer
*************************************************************************************************************************/
ALGO_INLINE ACDC_Input_t const * ACDC_p_GetInput(void)
{
  return &ACDC_p_GetAccessData()->Input;
}

/*************************************************************************************************************************
  Functionname:         ACDC_p_GetOutput                                                                         */ /*!
  @brief                Returns the const pointer to the outputs 
  @glob_in              @ref ACDC_p_GetAccessData
  @return               ACDC_Output_t const *
  
  @pre                  None

  @post                 None

  @InOutCorrelation     see description

  @testmethod           @ref TEST_ACDC_P_GETOUTPUT_001

  @traceability          Design Decision
  @author               Andreas Kramer
*************************************************************************************************************************/
ALGO_INLINE ACDC_Output_t const * ACDC_p_GetOutput(void)
{
  return &ACDC_p_GetAccessData()->Output;
}

/*************************************************************************************************************************
  Functionname:         ACDC_p_ModOutput                                                                         */ /*!
  @brief                Returns the mutable pointer to the outputs 
  @glob_in              @ref ACDC_p_ModAccessData
  @return               ACDC_Output_t *
  
  @pre                  None

  @post                 None

  @InOutCorrelation     see description

  @testmethod           @ref TEST_ACDC_P_MODOUTPUT_001

  @traceability          Design Decision

  @author               Andreas Kramer
*************************************************************************************************************************/
ALGO_INLINE ACDC_Output_t * ACDC_p_ModOutput(void)
{
  return &ACDC_p_ModAccessData()->Output;
}

#ifdef ACDC_SIMU
#if (USE_ACDCWRAPPER_SIMU)
/*************************************************************************************************************************
  Functionname:         ACDC_p_ModSimuData                                                                         */ /*!
  @brief                Returns the mutable pointer to the simu struct 
  @glob_in              @ref ACDC_p_ModWorkingData
  @return               ACDC_Output_t *
  
  @pre                  None

  @post                 None

  @InOutCorrelation     see description

  @testmethod           @ref TEST_ACDC_P_MODSIMUDATA_001

  @traceability         Design Decision
  @author               Andreas Kramer
*************************************************************************************************************************/
ALGO_INLINE ACDC_DataWrapperSimu_t  * ACDC_p_ModSimuData(void)
{
  return ACDC_p_ModWorkingData()->pSimuData;
}
#endif
#endif


/*************************************************************************************************************************
  Functionname:         ACDC_p_GetPortHandlerList                                                                         */ /*!
  @brief                Returns the const pointer to list of all port handlers 
  @glob_in              @ref ACDC_p_GetWorkingData
  @return               ACDCPortHandlerList_t const *
  
  @pre                  None

  @post                 None

  @InOutCorrelation     see description

  @testmethod           @ref TEST_ACDC_P_GETPORTHANDLERLIST_001

  @traceability          Design Decision

  @author               Wenting Huang
*************************************************************************************************************************/
ALGO_INLINE ACDCPortHandlerList_t const * ACDC_p_GetPortHandlerList(void)
{
  return &(ACDC_p_GetWorkingData()->pInterCycle->sGlobData.ACDC.ACDC_PortHandlerList);
}

/*************************************************************************************************************************
  Functionname:         ACDC_p_ModPortHandlerList                                                                         */ /*!
  @brief                Returns the mutable pointer to list of all port handlers 
  @glob_in              @ref ACDC_p_ModWorkingData
  @return               ACDCPortHandlerList_t *
  
  @pre                  None

  @post                 None

  @InOutCorrelation     see description

  @testmethod           @ref TEST_ACDC_P_MODPORTHANDLERLIST_001

  @traceability          Design Decision

  @author               Wenting Huang
*************************************************************************************************************************/
ALGO_INLINE ACDCPortHandlerList_t * ACDC_p_ModPortHandlerList(void)
{
  return &(ACDC_p_ModWorkingData()->pInterCycle->sGlobData.ACDC.ACDC_PortHandlerList);
}

/*************************************************************************************************************************
  Functionname:         ACDC_p_GetReqPortList                                                                         */ /*!
  @brief                Returns the const pointer to the request ports
  @glob_in              @ref ACDC_p_GetInput
  @return               reqACDCPrtList_t const *
  
  @pre                  None

  @post                 None

  @InOutCorrelation     see description

  @testmethod           @ref TEST_ACDC_P_GETREQPORTLIST_001

  @traceability          Design Decision

  @author               Andreas Kramer
*************************************************************************************************************************/
ALGO_INLINE reqACDCPrtList_t const * ACDC_p_GetReqPortList(void)
{
  return &ACDC_p_GetInput()->ReqPorts;
}

/*************************************************************************************************************************
  Functionname:         ACDC_p_GetProPortList                                                                         */ /*!
  @brief                Returns the const pointer to the provide ports
  @glob_in              @ref ACDC_p_GetOutput
  @return               provACDCPrtList_t const *
  
  @pre                  None

  @post                 None

  @InOutCorrelation     see description

  @testmethod           @ref TEST_ACDC_P_GETPROPORTLIST_001

  @traceability          Design Decision

  @author               Andreas Kramer
*************************************************************************************************************************/
ALGO_INLINE provACDCPrtList_t const * ACDC_p_GetProPortList(void)
{
  return &ACDC_p_GetOutput()->ProPorts;
}

/*************************************************************************************************************************
  Functionname:         ACDC_p_ModProPortList                                                                         */ /*!
  @brief                Returns the mutable pointer to the provide ports
  @glob_in              @ref ACDC_p_ModOutput
  @return               provACDCPrtList_t *
  
  @pre                  None

  @post                 None

  @InOutCorrelation     see description

  @testmethod           @ref TEST_ACDC_P_MODPROPORTLIST_001

  @traceability          Design Decision

  @author               Andreas Kramer
*************************************************************************************************************************/
ALGO_INLINE provACDCPrtList_t * ACDC_p_ModProPortList(void)
{
  return &ACDC_p_ModOutput()->ProPorts;
}


/************************************************************************/
/* ACC Port                                                  */
/************************************************************************/
#if ((FCT_CFG_COLLISION_DETECTION)&&(FCT_CFG_ADAPTIVE_CRUISE_CONTROL))
/*************************************************************************************************************************
  Functionname:         ACDC_p_GetSLATE_CD_DataPointer                                                               */ /*!
  @brief                Returns the ACC Port for ACDC internal purposes.
  @return               SLATE_CD_Data_t const *
  @glob_in              @ref ACDC_p_GetAccessData
  @c_switch_full        @ref FCT_CFG_ADAPTIVE_CRUISE_CONTROL \n
                        @ref FCT_CFG_COLLISION_DETECTION
					
  @pre                  None

  @post                 None

  @InOutCorrelation     see description

  @testmethod           @ref TEST_ACDC_P_GETSLATE_CD_DATAPOINTER_001

  @traceability          Design Decision
  @author               Andreas Kramer
*************************************************************************************************************************/
ALGO_INLINE SLATE_CD_Data_t const * ACDC_p_GetSLATE_CD_DataPointer(void)
{
  return ACDC_p_GetAccessData()->Input.ReqPorts.pSLATE_CD_Data;
}
#endif
/************************************************************************/
/* FCT Service Pointers                                                  */
/************************************************************************/

#if (FCT_CFG_USE_SERVICE_POINTER_FUNCTS)
/*************************************************************************************************************************
  Functionname:         ACDC_p_GetServiceFunctionsList                                                              */ /*!
  @brief                Returns the const pointer to the Service Functions.
  @return               AS_t_ServiceFuncts const *
  @glob_in              @ref ACDC_p_GetInput
  @c_switch_full        @ref FCT_CFG_USE_SERVICE_POINTER_FUNCTS

  
  @pre                  None

  @post                 None

  @InOutCorrelation     see description

  @testmethod           @ref GETSERVICEFUNCTIONSLIST_001 

  @traceability          Design Decision

  @author               Andreas Kramer
*************************************************************************************************************************/
ALGO_INLINE AS_t_ServiceFuncts const * ACDC_p_GetServiceFunctionsList(void)
{
  return &(ACDC_p_GetInput()->ServiceFuncts);
}
#endif /* (FCT_CFG_USE_SERVICE_POINTER_FUNCTS) */

/*************************************************************************************************************************
  Functionname:         ACDC_p_GetFrameData                                                           */ /*!
  @brief                Returns the const pointer to the frame data.
  @return               ACDCFrame_t const *
  @glob_in              @ref ACDC_p_GetWorkingData
  @c_switch_full        None
  
  
  @pre                  None

  @post                 None

  @InOutCorrelation     see description

  @testmethod           @ref GETFRAMEDATA_001 

  @traceability          Design Decision

  @author               Andreas Kramer
*************************************************************************************************************************/
ALGO_INLINE ACDCFrame_t const * ACDC_p_GetFrameData(void)
{
  return &(ACDC_p_GetWorkingData()->pInterCycleMeas->sGlobData.ACDC.sFrame);
}

/*************************************************************************************************************************
  Functionname:         ACDC_p_ModFrameData                                                           */ /*!
  @brief                Returns the mutable pointer to the frame data.
  @return               ACDCFrame_t *
  @glob_in              @ref ACDC_p_ModWorkingData
  @c_switch_full        None
  
  
  @pre                  None

  @post                 None

  @InOutCorrelation     see description

  @testmethod           @ref TEST_ACDC_P_MODFRAMEDATA_001

  @traceability          Design Decision

  @author               Andreas Kramer
*************************************************************************************************************************/
ALGO_INLINE ACDCFrame_t * ACDC_p_ModFrameData(void)
{
  return &(ACDC_p_ModWorkingData()->pInterCycleMeas->sGlobData.ACDC.sFrame);
}

/*************************************************************************************************************************
  Functionname:         ACDC_p_GetSyncRef                                                           */ /*!
  @brief                Returns the const pointer to the ACDC_SyncRef.
  @return               ACDCSyncRef_t const *
  @glob_in              @ref ACDC_p_GetWorkingData
  @c_switch_full        None
    
  @pre                  None

  @post                 None

  @InOutCorrelation     see description

  @testmethod           @ref TEST_ACDC_P_GETSYNCREF_001

  @traceability          Design Decision

  @author               Andreas Kramer
*************************************************************************************************************************/
ALGO_INLINE ACDCSyncRef_t const * ACDC_p_GetSyncRef(void)
{
  return &(ACDC_p_GetWorkingData()->pIntraCycleMeas->sGlobData.ACDC.ACDC_SyncRef);
}

/*************************************************************************************************************************
  Functionname:         ACDC_p_ModSyncRef                                                           */ /*!
  @brief                Returns the mutable pointer to the ACDC_SyncRef.
  @return               ACDCSyncRef_t *
  @glob_in              @ref ACDC_p_ModWorkingData
  @c_switch_full        None

  @pre                  None

  @post                 None

  @InOutCorrelation     see description

  @testmethod           @ref TEST_ACDC_P_MODSYNCREF_001

  @traceability          Design Decision


  @author               Andreas Kramer
*************************************************************************************************************************/
ALGO_INLINE ACDCSyncRef_t * ACDC_p_ModSyncRef(void)
{
  return &(ACDC_p_ModWorkingData()->pIntraCycleMeas->sGlobData.ACDC.ACDC_SyncRef);
}

#if (FCT_CFG_RUNTIME_MEAS)
/*************************************************************************************************************************
  Functionname:         ACDC_p_GetRuntimeInfo                                                           */ /*!
  @brief                Returns the const pointer to the ACDC_Runtime structure
  @return               ACDCRuntimeInfo_t const *
  @glob_in              @ref ACDC_p_GetWorkingData
  @c_switch_full        None
    
  @pre                  None

  @post                 None

  @InOutCorrelation     see description

  @testmethod           @ref TEST_ACDC_P_GETRUNTIMEINFO_001

  @traceability          Design Decision

  @author               Andreas Kramer
*************************************************************************************************************************/
ALGO_INLINE ACDCRuntimeInfo_t const * ACDC_p_GetRuntimeInfo (void)
{
  return &(ACDC_p_GetWorkingData()->pIntraCycleMeas->sGlobData.ACDC.sRuntimeInfo);
}


/*************************************************************************************************************************
  Functionname:         ACDC_p_ModRuntimeInfo                                                           */ /*!
  @brief                Returns the mutable pointer to the ACDC_Runtime structure
  @return               ACDCRuntimeInfo_t *
  @glob_in              @ref ACDC_p_ModWorkingData
  @c_switch_full        None
      
  @pre                  None

  @post                 None

  @InOutCorrelation     see description

  @testmethod           @ref TEST_ACDC_P_MODRUNTIMEINFO_001

  @traceability          Design Decision

  @author               Andreas Kramer
*************************************************************************************************************************/
ALGO_INLINE ACDCRuntimeInfo_t  * ACDC_p_ModRuntimeInfo (void)
{
  return &(ACDC_p_ModWorkingData()->pIntraCycleMeas->sGlobData.ACDC.sRuntimeInfo);
}
#endif /* (FCT_CFG_RUNTIME_MEAS) */

#if (ACDC_CFG_AIP)
/*************************************************************************************************************************
  Functionname:         ACDC_p_GetTrafoMatForward                                                             */ /*!
  @brief                Returns the const pointer to transformation matrix 
  @return               GDBTrafoMatrix2D_t const *
  @glob_in              @ref ACDC_p_GetWorkingData
  @c_switch_full        None

      
  @pre                  None

  @post                 None

  @InOutCorrelation     see description

  @testmethod           @ref TEST_ACDC_P_GETTRAFOMATFORWARD_001 

  @traceability          Design Decision
  @author               Andreas Kramer
*************************************************************************************************************************/
ALGO_INLINE GDBTrafoMatrix2D_t const * ACDC_p_GetTrafoMatForward       (void)
{
  return &(ACDC_p_GetWorkingData()->pIntraCycle->sGlobData.AIP.AIP_TrafoMat2DForward);
}

/*************************************************************************************************************************
  Functionname:         ACDC_p_ModTrafoMatForward                                                             */ /*!
  @brief                Returns the mutable pointer to transformation matrix
  @return               GDBTrafoMatrix2D_t *
  @glob_in              @ref ACDC_p_ModWorkingData
  @c_switch_full        None
        
  @pre                  None

  @post                 None

  @InOutCorrelation     see description

  @testmethod           @ref TEST_ACDC_P_MODTRAFOMATFORWARD_001 

  @traceability          Design Decision
  @author               Andreas Kramer
*************************************************************************************************************************/
ALGO_INLINE GDBTrafoMatrix2D_t  * ACDC_p_ModTrafoMatForward       (void)
{
  return &(ACDC_p_ModWorkingData()->pIntraCycle->sGlobData.AIP.AIP_TrafoMat2DForward);
}

/*************************************************************************************************************************
  Functionname:         ACDC_p_GetTrafoMatBackward                                                             */ /*!
  @brief                Returns the const pointer to transformation matrix 
  @return               GDBTrafoMatrix2D_t const *
  @glob_in              @ref ACDC_p_GetWorkingData
  @c_switch_full        None
     
  @pre                  None

  @post                 None

  @InOutCorrelation     see description

  @testmethod           @ref TEST_ACDC_P_GETTRAFOMATBACKWARD_001 

  @traceability          Design Decision
  @author               Andreas Kramer
*************************************************************************************************************************/
ALGO_INLINE GDBTrafoMatrix2D_t const * ACDC_p_GetTrafoMatBackward       (void)
{
  return &(ACDC_p_GetWorkingData()->pIntraCycle->sGlobData.AIP.AIP_TrafoMat2DBackward);
}

/*************************************************************************************************************************
  Functionname:         ACDC_p_ModTrafoMatBackward                                                             */ /*!
  @brief                Returns the mutable pointer to transformation matrix
  @return               GDBTrafoMatrix2D_t *
  @glob_in              @ref ACDC_p_ModWorkingData
  @c_switch_full        None
       
  @pre                  None

  @post                 None

  @InOutCorrelation     see description

  @testmethod           @ref TEST_ACDC_P_MODTRAFOMATBACKWARD_001 

  @traceability          Design Decision
  @author               Andreas Kramer
*************************************************************************************************************************/
ALGO_INLINE GDBTrafoMatrix2D_t  * ACDC_p_ModTrafoMatBackward       (void)
{
  return &(ACDC_p_ModWorkingData()->pIntraCycle->sGlobData.AIP.AIP_TrafoMat2DBackward);
}
#endif /*(ACDC_CFG_AIP)*/

#if (ACDC_CFG_CD)
/*************************************************************************************************************************
  Functionname:         ACDC_p_GetCDParameters                                                           */ /*!
  @brief                Returns the const pointer to the CDParameters structure
  @return               CDParameters_t const *
  @glob_in              @ref ACDC_p_GetWorkingData
  @c_switch_full        None
       
  @pre                  None

  @post                 None

  @InOutCorrelation     see description

  @testmethod           @ref TEST_ACDC_P_GETCDPARAMETERS_001 

  @traceability          Design Decision
  @author               Andreas Kramer
*************************************************************************************************************************/
ALGO_INLINE CDParameters_t const * ACDC_p_GetCDParameters (void)
{
  return &(ACDC_p_GetWorkingData()->pInterCycle->sGlobData.CD.CDParameters);
}

/*************************************************************************************************************************
  Functionname:         ACDC_p_ModCDParameters                                                           */ /*!
  @brief                Returns the mutable pointer to the CDParameters structure
  @return               CDParameters_t *
  @glob_in              @ref ACDC_p_ModWorkingData
  @c_switch_full        None
       
  @pre                  None

  @post                 None

  @InOutCorrelation     see description

  @testmethod           @ref TEST_ACDC_P_MODCDPARAMETERS_001 

  @traceability          Design Decision
  @author               Andreas Kramer
*************************************************************************************************************************/
ALGO_INLINE CDParameters_t * ACDC_p_ModCDParameters (void)
{
  return &(ACDC_p_ModWorkingData()->pInterCycle->sGlobData.CD.CDParameters);
}

/*************************************************************************************************************************
  Functionname:         ACDC_p_GetIntHypothesesData                                                           */ /*!
  @brief                Returns the const pointer to the internal hypothesis structure
  @return               CDIntHypothesesData_t const *
  @glob_in              @ref ACDC_p_GetWorkingData
  @c_switch_full        None
       
  @pre                  None

  @post                 None

  @InOutCorrelation     see description

  @testmethod           @ref TEST_ACDC_P_GETINTHYPOTHESEDATA_001 

  @traceability          Design Decision
  @author               Andreas Kramer
*************************************************************************************************************************/
ALGO_INLINE CDIntHypothesesData_t const * ACDC_p_GetIntHypothesesData (void)
{
  return &(ACDC_p_GetWorkingData()->pInterCycle->sGlobData.CD.sHypothesis);
}

/*************************************************************************************************************************
  Functionname:         ACDC_p_ModIntHypothesesData                                                           */ /*!
  @brief                Returns the mutable pointer to the internal hypothesis structure
  @return               CDIntHypothesesData_t *
  @glob_in              @ref ACDC_p_ModWorkingData
  @c_switch_full        None
         
  @pre                  None

  @post                 None

  @InOutCorrelation     see description

  @testmethod           @ref TEST_ACDC_P_MODINTHYPOTHESEDATA_001 

  @traceability          Design Decision
  @author               Andreas Kramer
*************************************************************************************************************************/
ALGO_INLINE CDIntHypothesesData_t * ACDC_p_ModIntHypothesesData (void)
{
  return &(ACDC_p_ModWorkingData()->pInterCycle->sGlobData.CD.sHypothesis);
}

#if (CD_USE_TURNINTOVRU_HYPOTHESIS)
/*************************************************************************************************************************
  Functionname:         ACDC_p_GetEgoDrvScenario                                                           */ /*!
  @brief                Returns the const pointer to the ego driving scenario
  @return               CDEgoDrvScenario_t const *
  @glob_in              @ref ACDC_p_GetWorkingData
  @c_switch_full        None
  @author               Mohamed Abdelkarim
*************************************************************************************************************************/
ALGO_INLINE CDEgoDrvScenario_t const * ACDC_p_GetEgoDrvScenario (void)
{
  return &(ACDC_p_GetWorkingData()->pInterCycle->sGlobData.CD.sEgoDrvScenario);
}

/*************************************************************************************************************************
  Functionname:         ACDC_p_ModEgoDrvScenario                                                           */ /*!
  @brief                Returns the mutable pointer to the ego driving scenario
  @return               CDEgoDrvScenario_t *
  @glob_in              @ref ACDC_p_ModWorkingData
  @c_switch_full        None
  @author               Mohamed Abdelkarim
*************************************************************************************************************************/
ALGO_INLINE CDEgoDrvScenario_t * ACDC_p_ModEgoDrvScenario (void)
{
  return &(ACDC_p_ModWorkingData()->pInterCycle->sGlobData.CD.sEgoDrvScenario);
}
#endif /* #if (CD_USE_TURNINTOVRU_HYPOTHESIS) */
/*************************************************************************************************************************
  Functionname:         ACDC_p_GetCurrentIntHypotheses                                                           */ /*!
  @brief                Returns the const pointer to the current internal hypothesis list
  @return               CDIntHypotheses_t const *
  @glob_in              @ref ACDC_p_GetIntHypothesesData
  @c_switch_full        None
         
  @pre                  None

  @post                 None

  @InOutCorrelation     see description

  @testmethod           @ref TEST_ACDC_P_GETCURRENTINTHYPOTHESE_001 

  @traceability          Design Decision
  @author               Andreas Kramer
*************************************************************************************************************************/
ALGO_INLINE CDIntHypotheses_t const * ACDC_p_GetCurrentIntHypotheses       (void)
{
  return &ACDC_p_GetIntHypothesesData()->sCurrent;
}
/*************************************************************************************************************************
  Functionname:         ACDC_p_ModCurrentIntHypotheses                                                           */ /*!
  @brief                Returns the mutable pointer to the current internal hypothesis list
  @return               CDIntHypotheses_t  *
  @glob_in              @ref ACDC_p_ModIntHypothesesData
  @c_switch_full        None
           
  @pre                  None

  @post                 None

  @InOutCorrelation     see description

  @testmethod           @ref TEST_ACDC_P_MODCURRENTINTHYPOTHESE_001 

  @traceability          Design Decision
  @author               Andreas Kramer
*************************************************************************************************************************/
ALGO_INLINE CDIntHypotheses_t * ACDC_p_ModCurrentIntHypotheses       (void)
{
  return &ACDC_p_ModIntHypothesesData()->sCurrent;
}

/*************************************************************************************************************************
  Functionname:         ACDC_p_GetCurrentIntHypothesis                                                           */ /*!
  @brief                Returns the const pointer to a specific current internal hypothesis 
  @return               CDIntHypothesis_t const *
  @glob_in              @ref ACDC_p_GetCurrentIntHypotheses
  @c_switch_full        None
           
  @pre                  None

  @post                 None

  @InOutCorrelation     see description

  @testmethod           @ref TEST_ACDC_P_GETCURRENTINTHYPOTHESIS_001 

  @traceability          Design Decision
  @author               Andreas Kramer
*************************************************************************************************************************/
ALGO_INLINE CDIntHypothesis_t const * ACDC_p_GetCurrentIntHypothesis (uint32 uHypID)
{
  ACDC_ASSERT(uHypID < CD_NUMBER_OF_HYPOTHESES);/* PRQA S 3119 # Date:2020-06-02, Reviewer: Praveen Annareddy , Reason: This code is placed for assertive failure and hence cannot be removed */
  return &(ACDC_p_GetCurrentIntHypotheses()->aHyp[uHypID]);
}

/*************************************************************************************************************************
  Functionname:         ACDC_p_ModCurrentIntHypothesis                                                           */ /*!
  @brief                Returns the mutable pointer to a specific current internal hypothesis 
  @return               CDIntHypothesis_t *
  @glob_in              @ref ACDC_p_ModCurrentIntHypotheses
  @c_switch_full        None
           
  @pre                  None

  @post                 None

  @InOutCorrelation     see description

  @testmethod           @ref TEST_ACDC_P_MODCURRENTINTHYPOTHESIS_001 

  @traceability          Design Decision
  @author               Andreas Kramer
*************************************************************************************************************************/
ALGO_INLINE CDIntHypothesis_t * ACDC_p_ModCurrentIntHypothesis (uint32 uHypID)
{
  ACDC_ASSERT(uHypID < CD_NUMBER_OF_HYPOTHESES);/* PRQA S 3119 # Date:2020-06-02, Reviewer: Praveen Annareddy , Reason: This code is placed for assertive failure and hence cannot be removed */
  return &(ACDC_p_ModCurrentIntHypotheses()->aHyp[uHypID]);
}

/*************************************************************************************************************************
  Functionname:         ACDC_p_GetPrevIntHypotheses                                                           */ /*!
  @brief                Returns the const pointer to the previous internal hypothesis list
  @return               CDIntHypotheses_t const *
  @glob_in              @ref ACDC_p_GetIntHypothesesData
  @c_switch_full        None
           
  @pre                  None

  @post                 None

  @InOutCorrelation     see description

  @testmethod           @ref TEST_ACDC_P_GETPREVINTHYPOTHESE_001 

  @traceability          Design Decision
  @author               Andreas Kramer
*************************************************************************************************************************/
ALGO_INLINE CDIntHypotheses_t const * ACDC_p_GetPrevIntHypotheses       (void)
{
  return &ACDC_p_GetIntHypothesesData()->sPrev;
}

/*************************************************************************************************************************
  Functionname:         ACDC_p_ModPrevIntHypotheses                                                           */ /*!
  @brief                Returns the mutable pointer to the previous internal hypothesis list
  @return               CDIntHypotheses_t *
  @glob_in              @ref ACDC_p_ModIntHypothesesData
  @c_switch_full        None
           
  @pre                  None

  @post                 None

  @InOutCorrelation     see description

  @testmethod           @ref TEST_ACDC_P_MODPREVINTHYPOTHESE_001 

  @traceability          Design Decision
  @author               Andreas Kramer
*************************************************************************************************************************/
ALGO_INLINE CDIntHypotheses_t * ACDC_p_ModPrevIntHypotheses       (void)
{
  return &ACDC_p_ModIntHypothesesData()->sPrev;
}

/*************************************************************************************************************************
  Functionname:         ACDC_a_GetPrevIntHypothesis                                                           */ /*!
  @brief                Returns the const pointer to a specific previous internal hypothesis 
  @return               CDIntHypothesis_t const *
  @glob_in              @ref ACDC_p_GetPrevIntHypotheses
  @c_switch_full        None
           
  @pre                  None

  @post                 None

  @InOutCorrelation     see description

  @testmethod           @ref TEST_ACDC_P_GETPREVINTHYPOTHESIS_001 

  @traceability          Design Decision
  @author               Andreas Kramer
*************************************************************************************************************************/
ALGO_INLINE CDIntHypothesis_t const * ACDC_p_GetPrevIntHypothesis       (uint32 uHypID)
{
  ACDC_ASSERT(uHypID < CD_NUMBER_OF_HYPOTHESES);/* PRQA S 3119 # Date:2020-06-02, Reviewer: Praveen Annareddy , Reason: This code is placed for assertive failure and hence cannot be removed */
  return &(ACDC_p_GetPrevIntHypotheses()->aHyp[uHypID]);
}

/*************************************************************************************************************************
  Functionname:         ACDC_p_ModPrevIntHypothesis                                                           */ /*!
  @brief                Returns the mutable pointer to a specific previous internal hypothesis 
  @return               CDIntHypothesis_t *
  @glob_in              @ref ACDC_p_ModPrevIntHypotheses
  @c_switch_full        None
           
  @pre                  None

  @post                 None

  @InOutCorrelation     see description

  @testmethod           @ref TEST_ACDC_P_MODPREVINTHYPOTHESIS_001 

  @traceability          Design Decision
  @author               Andreas Kramer
*************************************************************************************************************************/
ALGO_INLINE CDIntHypothesis_t * ACDC_p_ModPrevIntHypothesis       (uint32 uHypID)
{
  ACDC_ASSERT(uHypID < CD_NUMBER_OF_HYPOTHESES);/* PRQA S 3119 # Date:2020-06-02, Reviewer: Praveen Annareddy , Reason: This code is placed for assertive failure and hence cannot be removed */
  return &(ACDC_p_ModPrevIntHypotheses()->aHyp[uHypID]);
}


/*************************************************************************************************************************
  Functionname:         ACDC_p_GetObjHypothesisData                                                             */ /*!
  @brief                Returns the const pointer to the object specific hypothesis data 
  @return               CDObj_Hypothesis_t const *
  @glob_in              @ref ACDC_p_GetWorkingData
  @c_switch_full        None
           
  @pre                  None

  @post                 None

  @InOutCorrelation     see description

  @testmethod           @ref TEST_ACDC_P_GETOBJHYPOTHESISDATA_001 

  @traceability          Design Decision
  @author               Andreas Kramer
*************************************************************************************************************************/
ALGO_INLINE CDObj_Hypothesis_t const * ACDC_p_GetObjHypothesisData       (ObjNumber_t const iObj)
{
  ACDC_ASSERT((iObj >= 0) && (iObj < EM_N_OBJECTS));/* PRQA S 3119 # Date:2020-06-02, Reviewer: Praveen Annareddy , Reason: This code is placed for assertive failure and hence cannot be removed */
  return &(ACDC_p_GetWorkingData()->pInterCycle->sObjData.aObj[iObj].CD.sHypothesis);
}

/*************************************************************************************************************************
  Functionname:         ACDC_p_ModObjHypothesisData                                                             */ /*!
  @brief                Returns the mutable pointer to the object specific hypothesis data 
  @return               CDObj_Hypothesis_t *
  @glob_in              @ref ACDC_p_ModWorkingData
  @c_switch_full        None
             
  @pre                  None

  @post                 None

  @InOutCorrelation     see description

  @testmethod           @ref TEST_ACDC_P_MODOBJTHYPOTHESISDATA_001 

  @traceability          Design Decision
  @author               Andreas Kramer
*************************************************************************************************************************/
ALGO_INLINE CDObj_Hypothesis_t  * ACDC_p_ModObjHypothesisData       (ObjNumber_t const iObj)
{
  ACDC_ASSERT((iObj >= 0) && (iObj < EM_N_OBJECTS));/* PRQA S 3119 # Date:2020-06-02, Reviewer: Praveen Annareddy , Reason: This code is placed for assertive failure and hence cannot be removed */
  return &(ACDC_p_ModWorkingData()->pInterCycle->sObjData.aObj[iObj].CD.sHypothesis);
}

/*************************************************************************************************************************
  Functionname:         ACDC_p_GetObjTTXData                                                             */ /*!
  @brief                Returns the const pointer to the object specific TTX 
  @return               CDObj_TTX_t const *
  @glob_in              @ref ACDC_p_GetWorkingData
  @c_switch_full        None
             
  @pre                  None

  @post                 None

  @InOutCorrelation     see description

  @testmethod           @ref TEST_ACDC_P_GETOBJTTXDATA_001 

  @traceability          Design Decision
  @author               Andreas Kramer
*************************************************************************************************************************/
ALGO_INLINE CDObj_TTX_t const * ACDC_p_GetObjTTXData       (ObjNumber_t const iObj)
{
  ACDC_ASSERT((iObj >= 0) && (iObj < EM_N_OBJECTS));/* PRQA S 3119 # Date:2020-06-02, Reviewer: Praveen Annareddy , Reason: This code is placed for assertive failure and hence cannot be removed */
  return &(ACDC_p_GetWorkingData()->pIntraCycle->sObjData.aObj[iObj].CD.sTTX);
}

/*************************************************************************************************************************
  Functionname:         ACDC_p_ModObjTTXData                                                             */ /*!
  @brief                Returns the mutable pointer to the object specific TTX 
  @return               CDObj_TTX_t *
  @glob_in              @ref ACDC_p_ModWorkingData
  @c_switch_full        None
             
  @pre                  None

  @post                 None

  @InOutCorrelation     see description

  @testmethod           @ref TEST_ACDC_P_MODOBJTTXDATA_001 

  @traceability          Design Decision
  @author               Andreas Kramer
*************************************************************************************************************************/
ALGO_INLINE CDObj_TTX_t  * ACDC_p_ModObjTTXData       (ObjNumber_t const iObj)
{
  ACDC_ASSERT((iObj >= 0) && (iObj < EM_N_OBJECTS));/* PRQA S 3119 # Date:2020-06-02, Reviewer: Praveen Annareddy , Reason: This code is placed for assertive failure and hence cannot be removed */
  return &(ACDC_p_ModWorkingData()->pIntraCycle->sObjData.aObj[iObj].CD.sTTX);
}

/*************************************************************************************************************************
  Functionname:         ACDC_p_GetObjEvasionData                                                             */ /*!
  @brief                Returns the const pointer to the object specific evasion data
  @return               CDObj_Evasion_t const *
  @glob_in              @ref ACDC_p_GetWorkingData
  @c_switch_full        None
             
  @pre                  None

  @post                 None

  @InOutCorrelation     see description

  @testmethod           @ref TEST_ACDC_P_GETOBJEVASIONDATA_001 

  @traceability          Design Decision
  @author               Andreas Kramer
*************************************************************************************************************************/
ALGO_INLINE CDObj_Evasion_t const * ACDC_p_GetObjEvasionData       (ObjNumber_t const iObj)
{
  ACDC_ASSERT((iObj >= 0) && (iObj < EM_N_OBJECTS));/* PRQA S 3119 # Date:2020-06-02, Reviewer: Praveen Annareddy , Reason: This code is placed for assertive failure and hence cannot be removed */
  return &(ACDC_p_GetWorkingData()->pIntraCycle->sObjData.aObj[iObj].CD.sEvasion);
}

/*************************************************************************************************************************
  Functionname:         ACDC_p_ModObjEvasionData                                                             */ /*!
  @brief                Returns the mutable pointer to the object specific evasion data
  @return               CDObj_Evasion_t *
  @glob_in              @ref ACDC_p_ModWorkingData
  @c_switch_full        None
             
  @pre                  None

  @post                 None

  @InOutCorrelation     see description

  @testmethod           @ref TEST_ACDC_P_MODOBJEVATIONDATA_001 

  @traceability          Design Decision
  @author               Andreas Kramer
*************************************************************************************************************************/
ALGO_INLINE CDObj_Evasion_t  * ACDC_p_ModObjEvasionData       (ObjNumber_t const iObj)
{
  ACDC_ASSERT((iObj >= 0) && (iObj < EM_N_OBJECTS));/* PRQA S 3119 # Date:2020-06-02, Reviewer: Praveen Annareddy , Reason: This code is placed for assertive failure and hence cannot be removed */
  return &(ACDC_p_ModWorkingData()->pIntraCycle->sObjData.aObj[iObj].CD.sEvasion);
}

/*************************************************************************************************************************
  Functionname:         ACDC_p_GetObjStaticEvasionData                                                             */ /*!
  @brief                Returns the const pointer to the object specific static evasion data
  @return               CDObj_EvasionStatic_t const *
  @glob_in              @ref ACDC_p_GetWorkingData
  @c_switch_full        None
             
  @pre                  None

  @post                 None

  @InOutCorrelation     see description

  @testmethod           @ref TEST_ACDC_P_GETOBJSTATICEVASIONDATA_001 

  @traceability          Design Decision
  @author               Andreas Kramer
*************************************************************************************************************************/
ALGO_INLINE CDObj_EvasionStatic_t const * ACDC_p_GetObjStaticEvasionData       (ObjNumber_t const iObj)
{
  ACDC_ASSERT((iObj >= 0) && (iObj < EM_N_OBJECTS));/* PRQA S 3119 # Date:2020-06-02, Reviewer: Praveen Annareddy , Reason: This code is placed for assertive failure and hence cannot be removed */
  return &(ACDC_p_GetWorkingData()->pInterCycle->sObjData.aObj[iObj].CD.sEvasion);
}

/*************************************************************************************************************************
  Functionname:         ACDC_p_ModObjStaticEvasionData                                                             */ /*!
  @brief                Returns the mutable pointer to the object specific static evasion data
  @return               CDObj_EvasionStatic_t *
  @glob_in              @ref ACDC_p_ModWorkingData
  @c_switch_full        None
               
  @pre                  None

  @post                 None

  @InOutCorrelation     see description

  @testmethod           @ref TEST_ACDC_P_MODOBJSTATICEVASIONDATA_001 

  @traceability          Design Decision
  @author               Andreas Kramer
*************************************************************************************************************************/
ALGO_INLINE CDObj_EvasionStatic_t  * ACDC_p_ModObjStaticEvasionData       (ObjNumber_t const iObj)
{
  ACDC_ASSERT((iObj >= 0) && (iObj < EM_N_OBJECTS));/* PRQA S 3119 # Date:2020-06-02, Reviewer: Praveen Annareddy , Reason: This code is placed for assertive failure and hence cannot be removed */
  return &(ACDC_p_ModWorkingData()->pInterCycle->sObjData.aObj[iObj].CD.sEvasion);
}

#if (CD_USE_EPF)
/*************************************************************************************************************************
  Functionname:           ACDC_p_GetMostRelevantEPFHyp                                                                    */ /*!
  @brief                  Returns the most relevant hypothesis for EPF calculation.
  @return                 Hypothesis_t: pointer to the most relevant hypothesis for EPF calculation.
  @glob_in                @ref ACDC_p_GetExtHypothesis
  @switch_full            @ref CD_USE_EPF
  @author                 Wenting Huang
*************************************************************************************************************************/
ALGO_INLINE Hypothesis_t const * ACDC_p_GetMostRelevantEPFHyp(void)
{
  return ACDC_p_GetExtHypothesis(0);
}

#if defined(CD_EPF_CORRIDOR_FREEZE) && (CD_EPF_CORRIDOR_FREEZE == SWITCH_ON)
/*************************************************************************************************************************
  Functionname:         ACDC_p_GetEPFCorridorData                                                             */ /*!
  @brief                Returns the const pointer to the EPF corridor data
  @return               EPFCorridorData_t const *
  @glob_in              @ref ACDC_p_GetWorkingData
  @c_switch_full        @ref CD_USE_EPF \n
                        @ref CD_EPF_CORRIDOR_FREEZE
  @author               Andreas Kramer
*************************************************************************************************************************/
ALGO_INLINE EPFCorridorData_t const * ACDC_p_GetEPFCorridorData   (void)
{
  return &(ACDC_p_GetWorkingData()->pInterCycle->sGlobData.CD.sEPFCorridorData);
}

/*************************************************************************************************************************
  Functionname:         ACDC_p_ModEPFCorridorData                                                             */ /*!
  @brief                Returns the mutable pointer to the EPF corridor data
  @return               EPFCorridorData_t *
  @glob_in              @ref ACDC_p_ModWorkingData
  @c_switch_full        @ref CD_USE_EPF \n
                        @ref CD_EPF_CORRIDOR_FREEZE
  @author               Andreas Kramer
*************************************************************************************************************************/
ALGO_INLINE EPFCorridorData_t  * ACDC_p_ModEPFCorridorData       (void)
{
  return &(ACDC_p_ModWorkingData()->pInterCycle->sGlobData.CD.sEPFCorridorData);
}
#endif /* defined(CD_EPF_CORRIDOR_FREEZE) && (CD_EPF_CORRIDOR_FREEZE == SWITCH_ON) */
#endif /* (CD_USE_EPF) */

#if (CD_USE_GEN_PSC)
/*************************************************************************************************************************
  Functionname:         ACDC_p_GetObjKinematicHistory                                                             */ /*!
  @brief                Returns the const pointer to the object specific kinematic history
  @return               CDKinHistObj_t const *
  @glob_in              @ref ACDC_p_GetWorkingData
  @c_switch_full        None
               
  @pre                  None

  @post                 None

  @InOutCorrelation     see description

  @testmethod           @ref GETOBJKINEMATICHISTORY_001

  @traceability          Design Decision
  @author               Andreas Kramer
*************************************************************************************************************************/
ALGO_INLINE CDKinHistObj_t const * ACDC_p_GetObjKinematicHistory       (ObjNumber_t const iObj)
{
  ACDC_ASSERT((iObj >= 0) && (iObj < EM_N_OBJECTS));/* PRQA S 3119 # Date:2020-06-02, Reviewer: Praveen Annareddy , Reason: This code is placed for assertive failure and hence cannot be removed */
  return &(ACDC_p_GetWorkingData()->pInterCycle->sObjData.aObj[iObj].CD.sKinObjHist);
}

/*************************************************************************************************************************
  Functionname:         ACDC_p_ModObjKinematicHistory                                                             */ /*!
  @brief                Returns the mutable pointer to the object specific kinematic history
  @return               CDKinHistObj_t  *
  @glob_in              @ref ACDC_p_ModWorkingData
  @c_switch_full        None
   @pre                  None

  @post                 None

  @InOutCorrelation     see description

  @testmethod           @ref MODOBJKINEMATICHISTORY_001

  @traceability          Design Decision
  @author               Andreas Kramer
*************************************************************************************************************************/
ALGO_INLINE CDKinHistObj_t  * ACDC_p_ModObjKinematicHistory       (ObjNumber_t const iObj)
{
  ACDC_ASSERT((iObj >= 0) && (iObj < EM_N_OBJECTS));/* PRQA S 3119 # Date:2020-06-02, Reviewer: Praveen Annareddy , Reason: This code is placed for assertive failure and hence cannot be removed */
  return &(ACDC_p_ModWorkingData()->pInterCycle->sObjData.aObj[iObj].CD.sKinObjHist);
}
#endif /* (CD_USE_GEN_PSC) */

#if defined(CD_USE_FUS_OBJ_LIST_FOR_SEN_SOURCE) && (CD_USE_FUS_OBJ_LIST_FOR_SEN_SOURCE==SWITCH_ON)
/*************************************************************************************************************************
  Functionname:         ACDC_p_GetObjQualifier                                                             */ /*!
  @brief                Returns the const pointer to the object specific qualifier data 
  @return               CDQualifier_t const *
  @glob_in              @ref ACDC_p_GetWorkingData
  @c_switch_full        None
  @author               Andreas Kramer
*************************************************************************************************************************/
ALGO_INLINE CDQualifier_t const * ACDC_p_GetObjQualifier       (ObjNumber_t const iObj)
{
  ACDC_ASSERT((iObj >= 0) && (iObj < EM_N_OBJECTS));/* PRQA S 3119 # Date:2020-06-02, Reviewer: Praveen Annareddy , Reason: This code is placed for assertive failure and hence cannot be removed */
  return &(ACDC_p_GetWorkingData()->pIntraCycle->sObjData.aObj[iObj].CD.sQualifier);
}

/*************************************************************************************************************************
  Functionname:         ACDC_p_ModObjQualifier                                                             */ /*!
  @brief                Returns the mutable pointer to the object specific qualifier data 
  @return               CDQualifier_t *
  @glob_in              @ref ACDC_p_ModWorkingData
  @c_switch_full        None
  @author               Andreas Kramer
*************************************************************************************************************************/
ALGO_INLINE CDQualifier_t * ACDC_p_ModObjQualifier       (ObjNumber_t const iObj)
{
  ACDC_ASSERT((iObj >= 0) && (iObj < EM_N_OBJECTS));
  return &(ACDC_p_ModWorkingData()->pIntraCycle->sObjData.aObj[iObj].CD.sQualifier);
}
#endif /* defined(CD_USE_FUS_OBJ_LIST_FOR_SEN_SOURCE) && (CD_USE_FUS_OBJ_LIST_FOR_SEN_SOURCE==SWITCH_ON) */
#endif /*(ACDC_CFG_CD)*/
#if (ACDC_CFG_ESPM)
  /*************************************************************************************************************************
  Functionname:         ACDC_p_GetPerformanceDegrationData                                                             */ /*!
  @brief                Returns the const pointer to the performance degradation data
  @return               PerformanceDegrationData_t const *
  @glob_in              @ref ACDC_p_GetWorkingData
  @c_switch_full        None
  @pre                  None

  @post                 None

  @InOutCorrelation     see description

  @testmethod           @ref TEST_ACDC_P_GETPERFORMANCEDEGRATIONDATA_001 

  @traceability          Design Decision
  @author               Andreas Kramer
*************************************************************************************************************************/
ALGO_INLINE PerformanceDegrationData_t const * ACDC_p_GetPerformanceDegrationData       (void)
{
  return &(ACDC_p_GetWorkingData()->pIntraCycle->sGlobData.ESPM.sPerformanceDegrationData);
}

/*************************************************************************************************************************
  Functionname:         ACDC_p_ModPerformanceDegrationData                                                             */ /*!
  @brief                Returns the mutable pointer to the performance degradation data 
  @return               PerformanceDegrationData_t *
  @glob_in              @ref ACDC_p_ModWorkingData
  @c_switch_full        None
  @pre                  None

  @post                 None

  @InOutCorrelation     see description

  @testmethod           @ref TEST_ACDC_P_MODPERFORMANCEDEGRATIONDATA_001 

  @traceability          Design Decision
  @author               Andreas Kramer
*************************************************************************************************************************/
ALGO_INLINE PerformanceDegrationData_t * ACDC_p_ModPerformanceDegrationData       (void)
{
  return &(ACDC_p_ModWorkingData()->pIntraCycle->sGlobData.ESPM.sPerformanceDegrationData);
}
#endif /* (ACDC_CFG_ESPM) */

/************************************************************************/
/* EM Gen Object list                                                   */
/************************************************************************/
/*************************************************************************************************************************
  Functionname:           ACDC_p_GetEMGenObjList                                                                         */ /*!
  @brief                  Returns the pointer to the GenObject.
  @return                 EM_t_GenObjectList const * : Pointer to the GenObject list
  @glob_in                @ref ACDC_p_GetAccessData

    @pre                  None

  @post                 None

  @InOutCorrelation     see description

  @testmethod           @ref TEST_ACDC_P_GETEMGENOBJLIST_001

  @traceability          Design Decision
  @author                 Andreas Kramer
*************************************************************************************************************************/
ALGO_INLINE EM_t_GenObjectList const * ACDC_p_GetEMGenObjList(void)
{
  return ACDC_p_GetAccessData()->Input.ReqPorts.pEmGenObjList;
}

/*************************************************************************************************************************
  Functionname:           ACDC_p_GetEMGenObj                                                                             */ /*!
  @brief                  Returns a pointer to the Gen object with the given index
  @return                 EM_t_GenObject const * : Pointer to an object
  @glob_in                @ref ACDC_p_GetEMGenObjList
  @param[in]              iObj : Index of the required object. \range[0,+...[
    @pre                  None

  @post                 None

  @InOutCorrelation     see description

  @testmethod           @ref TEST_ACDC_P_GETEMGENOBJ_001 

  @traceability          Design Decision
  @author                 Andreas Kramer
*************************************************************************************************************************/
ALGO_INLINE EM_t_GenObject const * ACDC_p_GetEMGenObj(ObjNumber_t const iObj)
{
  /* Perform range check before accessing an object */
  /* Suppress "Msg(3:3112) This statement has no side-effect - it can be removed"  */ /*PRQA S 3112,3119 1*/
  ACDC_ASSERT((iObj >= 0) && (iObj < EM_N_OBJECTS));
  return &(ACDC_p_GetEMGenObjList()->aObject[iObj]);
 
}

/*************************************************************************************************************************
  Functionname:           ACDC_p_GetEMGenObjKinematics                                                                   */ /*!
  @brief                  Returns a pointer to the kinematic structure of the object with the given index.
  @return                 EM_t_GenObjKinematics const * : Pointer to the kinematics of the object.
  @glob_in                @ref ACDC_p_GetEMGenObj
  @param[in]              iObj : Index of the object for which the kinematic shall be returned. \range [0,+...[
  @pre                  None

  @post                 None

  @InOutCorrelation     see description

  @testmethod           @ref TEST_ACDC_P_GETEMGENOBJKINEMATICS_001  

  @traceability          Design Decision 
 @author                 Andreas Kramer
*************************************************************************************************************************/
#if(ACDC_AIP_CFG_SHIFT_COORDINATE)
ALGO_INLINE EM_t_GenObjKinematics * ACDC_p_GetEMGenObjKinematics(ObjNumber_t const iObj)
{
  return &(ACDCAccessData.Input.ReqPorts.pEmGenObjList->aObject[iObj].Kinematic);
}
#else
ALGO_INLINE EM_t_GenObjKinematics const * ACDC_p_GetEMGenObjKinematics(ObjNumber_t const iObj)
{
  return &(ACDC_p_GetEMGenObj(iObj)->Kinematic);
}
#endif

/*************************************************************************************************************************
  Functionname:           ACDC_p_GetEMGenObjQualifiers                                                                   */ /*!
  @brief                  Returns a pointer to the qualifiers structure of the object with the given index.
  @return                 EM_t_GenObjQualifiers const * : Pointer to the qualifiers of the object.
  @glob_in                @ref ACDC_p_GetEMGenObj
  @param[in]              iObj : Index of the object for which the qualifiers shall be returned. \range [0,+...[
  @pre                  None

  @post                 None

  @InOutCorrelation     see description

  @testmethod           @ref TEST_ACDC_P_GETEMGENOBJQUALIFIERS_001 

  @traceability          Design Decision 
 @author                 Andreas Kramer
*************************************************************************************************************************/

#if(ACDC_CFG_USE_FPS)
ALGO_INLINE EM_t_GenObjQualifiers * ACDC_p_GetEMGenObjQualifiers(ObjNumber_t const iObj)
{
	return &(ACDCAccessData.Input.ReqPorts.pEmGenObjList->aObject[iObj].Qualifiers);     //For FPS .....@Cheng Long
  //return &(EM_GenObjectList.aObject[iObj].Qualifiers);     //For FPS .....@Cheng Long
}
#else
ALGO_INLINE EM_t_GenObjQualifiers const * ACDC_p_GetEMGenObjQualifiers(ObjNumber_t const iObj)
{	
  return &(ACDC_p_GetEMGenObj(iObj)->Qualifiers);
}
#endif

/*************************************************************************************************************************
  Functionname:           ACDC_p_GetEMGenObjAttributes                                                                   */ /*!
  @brief                  Returns a pointer to the attributes structure of the object with the given index.
  @return                 EM_t_GenObjAttributes const * : Pointer to the attributes of the object.
  @glob_in                @ref ACDC_p_GetEMGenObj
  @param[in]              iObj : Index of the object for which the attributes shall be returned. \range [0,+...[
  @pre                  None

  @post                 None

  @InOutCorrelation     see description

  @testmethod           @ref TEST_ACDC_P_GETEMGENOBJATTRIBUTES_001

  @traceability          Design Decision
  @author                 Andreas Kramer
*************************************************************************************************************************/
ALGO_INLINE EM_t_GenObjAttributes const * ACDC_p_GetEMGenObjAttributes(ObjNumber_t const iObj)
{
  return &(ACDC_p_GetEMGenObj(iObj)->Attributes);
}

/*************************************************************************************************************************
  Functionname:           ACDC_p_GetEMGenObjGeneral                                                                   */ /*!
  @brief                  Returns a pointer to the general information structure of the object with the given index.
  @return                 EM_t_GenObjGeneral const * : Pointer to the general data structure of the object.
  @glob_in                @ref ACDC_p_GetEMGenObj
  @param[in]              iObj : Index of the object for which the general data shall be returned. \range [0,+...[
  @pre                  None

  @post                 None

  @InOutCorrelation     see description

  @testmethod           @ref TEST_ACDC_P_GETEMGENOBJGENERAL_001

  @traceability          Design Decision
  @author                 Andreas Kramer
*************************************************************************************************************************/
ALGO_INLINE EM_t_GenObjGenerals const * ACDC_p_GetEMGenObjGeneral(ObjNumber_t const iObj)
{
  return &(ACDC_p_GetEMGenObj(iObj)->General);
}

/*************************************************************************************************************************
  Functionname:           ACDC_p_GetEMGenObjGeometry                                                                   */ /*!
  @brief                  Returns a pointer to the geometry structure of the object with the given index.
  @return                 EM_t_GenObjGeometry const * : Pointer to the geometry structure of the object.
  @glob_in                @ref ACDC_p_GetEMGenObj
  @param[in]              iObj : Index of the object for which the geometry shall be returned. \range [0,+...[
   @pre                  None

  @post                 None

  @InOutCorrelation     see description

  @testmethod           @ref TEST_ACDC_P_GETEMGENOBJGEOMETRY_001

  @traceability          Design Decision
  @author                 Andreas Kramer
*************************************************************************************************************************/
#if(ACDC_AIP_CFG_SHIFT_COORDINATE)
ALGO_INLINE EM_t_GenObjGeometry * ACDC_p_GetEMGenObjGeometry(ObjNumber_t const iObj)
{
  return &(ACDCAccessData.Input.ReqPorts.pEmGenObjList->aObject[iObj].Geometry);
}
#else
ALGO_INLINE EM_t_GenObjGeometry const * ACDC_p_GetEMGenObjGeometry(ObjNumber_t const iObj)
{
  return &(ACDC_p_GetEMGenObj(iObj)->Geometry);
}
#endif


/*************************************************************************************************************************
  Functionname:           ACDC_b_GetEMGenObjIsDeleted                                                                    */ /*!
  @brief                  Returns a flag indicating if an object is deleted or not.
  @return                 boolean : Flag indicating if the objects maintenance state is deleted (True) or not (False)
  @glob_in                @ref ACDC_p_GetEMGenObj
  @param[in]              iObj : Index of the considered object. \range [0,+...[
   @pre                  None

  @post                 None

  @InOutCorrelation     see description

  @testmethod           @ref TEST_ACDC_B_GETEMGENOBJISDELETED_001 \n
                        @ref TEST_ACDC_B_GETEMGENOBJISDELETED_002

  @traceability          Design Decision
  @author                 Andreas Kramer
*************************************************************************************************************************/
ALGO_INLINE  boolean ACDC_b_GetEMGenObjIsDeleted(ObjNumber_t const iObj)
{
  boolean bObjIsDeleted = (boolean)((ACDC_p_GetEMGenObj(iObj)->General.eMaintenanceState == EM_GEN_OBJECT_MT_STATE_DELETED));
  return bObjIsDeleted;
}

/*************************************************************************************************************************
  Functionname:           ACDC_b_GetEMGenObjIsNew                                                                    */ /*!
  @brief                  Returns a flag indicating if an object is new or not.
  @return                 boolean : Flag indicating if the objects maintenance state is new (True) or not (False)
  @glob_in                @ref ACDC_p_GetEMGenObj
  @param[in]              iObj : Index of the considered object. \range [0,+...[
   @pre                  None

  @post                 None

  @InOutCorrelation     see description

  @testmethod           @ref TEST_ACDC_B_GETEMGENOBJISNEW_001 \n
                        @ref TEST_ACDC_B_GETEMGENOBJISNEW_002

  @traceability          Design Decision
  @author                 Andreas Kramer
*************************************************************************************************************************/
ALGO_INLINE boolean ACDC_b_GetEMGenObjIsNew(ObjNumber_t const iObj)
{
  boolean bObjIsNew = (boolean)((ACDC_p_GetEMGenObj(iObj)->General.eMaintenanceState == EM_GEN_OBJECT_MT_STATE_NEW));
  return bObjIsNew;
}

#if (FCT_USE_EM_ARS_TECH_OBJECT_LIST)
/************************************************************************/
/* EM ARS Object list                                                   */
/************************************************************************/
/*************************************************************************************************************************
  Functionname:           ACDC_p_GetEMARSObjList                                                                    */ /*!
  @brief                  Returns a pointer to the ARS Object List
  @return                 EM_t_ARSObjectList const *
  @glob_in                @ref ACDC_p_GetAccessData
  @c_switch_full          @ref FCT_USE_EM_ARS_TECH_OBJECT_LIST
   @pre                  None

  @post                 None

  @InOutCorrelation     see description

  @testmethod           @ref TEST_ACDC_P_GETEMARSOBJLIST_001

  @traceability          Design Decision
  @author                 Andreas Kramer
*************************************************************************************************************************/
ALGO_INLINE EM_t_ARSObjectList const * ACDC_p_GetEMARSObjList(void)
{
  return ACDC_p_GetAccessData()->Input.ReqPorts.pEmARSObjList;
}

/*************************************************************************************************************************
  Functionname:           ACDC_p_GetEMARSObj                                                                             */ /*!
  @brief                  Returns a pointer to the ARS object with the given index.
  @return                 EM_t_ARSObject const *
  @param[in]              iObj : Index of the considered object. \range [0,+...[
  @glob_in                @ref ACDC_p_GetEMARSObjList
  @c_switch_full          @ref FCT_USE_EM_ARS_TECH_OBJECT_LIST
   @pre                  None

  @post                 None

  @InOutCorrelation     see description

  @testmethod           @ref TEST_ACDC_P_GETEMARSOBJ_001 

  @traceability          Design Decision
  @author                 Andreas Kramer
*************************************************************************************************************************/
ALGO_INLINE EM_t_ARSObject const * ACDC_p_GetEMARSObj(ObjNumber_t const iObj)
{
  /* Perform range check before accessing an object */
  /* Suppress "Msg(3:3112) This statement has no side-effect - it can be removed"  */ /*PRQA S 3112 1*/
  ACDC_ASSERT((iObj >= 0) && (iObj < EM_N_OBJECTS));

  return &(ACDC_p_GetEMARSObjList()->aObject[iObj]);
}

/*************************************************************************************************************************
  Functionname:           ACDC_p_GetEMARSObjAttributes                                                                             */ /*!
  @brief                  Returns a pointer to the Attributes of the ARS object with the given index.
  @return                 EM_t_ARS_Attributes  const * : Pointer to an attribute structure.
  @glob_in                @ref ACDC_p_GetEMARSObj
  @param[in]              iObj : Index of the considered object. \range [0,+...[
  @c_switch_full          @ref FCT_USE_EM_ARS_TECH_OBJECT_LIST
   @pre                  None

  @post                 None

  @InOutCorrelation     see description

  @testmethod           @ref TEST_ACDC_P_GETEMARSOBJATTRIBUTES_001

  @traceability          Design Decision
  @author                 Andreas Kramer
*************************************************************************************************************************/
ALGO_INLINE EM_t_ARS_Attributes  const * ACDC_p_GetEMARSObjAttributes(ObjNumber_t const iObj)
{
  return &(ACDC_p_GetEMARSObj(iObj)->Attributes);
}

/*************************************************************************************************************************
  Functionname:           ACDC_p_GetEMARSObjGeometry                                                                     */ /*!
  @brief                  Returns a pointer to the geometry of an ARS Object.
  @return                 EM_t_ARS_Geometry  const * : Pointer to a geometry structure.
  @glob_in                @ref ACDC_p_GetEMARSObj
  @param[in]              iObj : Index of the considered object. \range [0,+...[
  @c_switch_full          @ref FCT_USE_EM_ARS_TECH_OBJECT_LIST
   @pre                  None

  @post                 None

  @InOutCorrelation     see description

  @testmethod           @ref TEST_ACDC_P_GETEMARSOBJGEOMETRY_001 

  @traceability          Design Decision
  @author                 Andreas Kramer
*************************************************************************************************************************/
ALGO_INLINE EM_t_ARS_Geometry  const * ACDC_p_GetEMARSObjGeometry(ObjNumber_t const iObj)
{
  return &(ACDC_p_GetEMARSObj(iObj)->Geometry);
}

/*************************************************************************************************************************
  Functionname:           ACDC_p_GetEMARSObjKinematic                                                               */ /*!
  @brief                  Returns a pointer to the kinematic of an ARS Object.
  @return                 EM_t_ARS_Kinematic const * : Pointer to a kinematic structure.
  @glob_in                @ref ACDC_p_GetEMARSObj
  @param[in]              iObj : Index of the considered object. \range [0,+...[
  @c_switch_full          @ref FCT_USE_EM_ARS_TECH_OBJECT_LIST
   @pre                  None

  @post                 None

  @InOutCorrelation     see description

  @testmethod           @ref TEST_ACDC_P_GETEMARSOBJKINEMATIC_001

  @traceability          Design Decision
  @author                 Andreas Kramer
*************************************************************************************************************************/
ALGO_INLINE EM_t_ARS_Kinematic  const * ACDC_p_GetEMARSObjKinematic(ObjNumber_t const iObj)
{
  return &(ACDC_p_GetEMARSObj(iObj)->Kinematic);
}

/*************************************************************************************************************************
  Functionname:           ACDC_p_GetEMARSObjLegacy                                                               */ /*!
  @brief                  Returns a pointer to the legacy data of an ARS Object.
  @return                 EM_t_ARS_Legacy const * : Pointer to a legacy structure.
  @glob_in                @ref ACDC_p_GetEMARSObj
  @param[in]              iObj : Index of the considered object. \range [0,+...[
  @c_switch_full          @ref FCT_CFG_USE_SERVICE_POINTER_FUNCTS \n
                          @ref FCT_USE_EM_ARS_TECH_OBJECT_LIST
   @pre                  None

  @post                 None

  @InOutCorrelation     see description

  @testmethod           @ref TEST_ACDC_P_GETEMARSOBJLEGACY_001

  @traceability          Design Decision
  @author                 Andreas Kramer
*************************************************************************************************************************/
ALGO_INLINE EM_t_ARS_Legacy  const * ACDC_p_GetEMARSObjLegacy(ObjNumber_t const iObj)
{
  return &(ACDC_p_GetEMARSObj(iObj)->Legacy);
}

/*************************************************************************************************************************
  Functionname:           ACDC_p_GetEMARSObjMotionAttributes                                                               */ /*!
  @brief                  Returns a pointer to the Motion Attributes of an ARS Object.
  @return                 EM_t_ARS_MotionAttributes const * : Pointer to a Motion Attributes structure.
  @glob_in                @ref ACDC_p_GetEMARSObj
  @param[in]              iObj : Index of the considered object. \range [0,+...[
  @c_switch_full          @ref FCT_USE_EM_ARS_TECH_OBJECT_LIST
   @pre                  None

  @post                 None

  @InOutCorrelation     see description

  @testmethod           @ref TEST_ACDC_P_GETEMARSOBJMOTIONATTRIBUTES_001

  @traceability          Design Decision
  @author                 Andreas Kramer
*************************************************************************************************************************/
ALGO_INLINE EM_t_ARS_MotionAttributes  const * ACDC_p_GetEMARSObjMotionAttributes(ObjNumber_t const iObj)
{
  return &(ACDC_p_GetEMARSObj(iObj)->MotionAttributes);
}

/*************************************************************************************************************************
  Functionname:           ACDC_b_GetObjIsMovingToStationary                                                              */ /*!
  @brief                  Returns a flag that indicates if the stopped confidence of an object is above a threshold.
  @return                 boolean : Flag indicating if an object is moving to stationary (True) or not (False) 
  @glob_in                @ref  ACDC_p_GetEMARSObjMotionAttributes
  @param[in]              iObj : Index of the considered object. \range [0,+...[
  @c_switch_full          @ref FCT_USE_EM_ARS_TECH_OBJECT_LIST
   @pre                  None

  @post                 None

  @InOutCorrelation     see description

  @testmethod           @ref TEST_ACDC_B_GETOBJISMOVINGTOSTATIONARY_001 \n
                        @ref TEST_ACDC_B_GETOBJISMOVINGTOSTATIONARY_002

  @traceability          Design Decision
  @author                 Andreas Kramer
*************************************************************************************************************************/
ALGO_INLINE boolean ACDC_b_GetObjIsMovingToStationary(ObjNumber_t const iObj)
{
  boolean b_EMObjIsMovingToStationary = (boolean)(ACDC_p_GetEMARSObjMotionAttributes(iObj)->uiStoppedConfidence > 80u);
  return b_EMObjIsMovingToStationary;
}

/*************************************************************************************************************************
  Functionname:           ACDC_p_GetEMARSObjSensorSpecific                                                               */ /*!
  @brief                  Returns the sensor specific structure of an ARS object.
  @return                 EM_t_ARS_SensorSpecific  const *
  @glob_in                @ref  ACDC_p_GetEMARSObj
  @param[in]              iObj : Index of the considered object. \range [0,+...[
  @c_switch_full          @ref FCT_USE_EM_ARS_TECH_OBJECT_LIST
   @pre                  None

  @post                 None

  @InOutCorrelation     see description

  @testmethod           @ref TEST_ACDC_P_GETEMARSOBJSENSORSPECIFIC_001

  @traceability          Design Decision
  @author                 Andreas Kramer
*************************************************************************************************************************/
ALGO_INLINE EM_t_ARS_SensorSpecific  const * ACDC_p_GetEMARSObjSensorSpecific(ObjNumber_t const iObj)
{
  return &(ACDC_p_GetEMARSObj(iObj)->SensorSpecific);
}
#endif /* (FCT_USE_EM_ARS_TECH_OBJECT_LIST) */

#if (FCT_CFG_INCLUDE_FUSION_OBJECT_LIST)
/************************************************************************/
/* EM fusion object list                                                */
/************************************************************************/
/*************************************************************************************************************************
  Functionname:           ACDC_p_GetEMFusionObjList                                                                    */ /*!
  @brief                  Returns a pointer to the Fusion object List
  @return                 EM_t_FusionObjectList const *
  @glob_in                @ref ACDC_p_GetAccessData
  @c_switch_full          @ref FCT_CFG_INCLUDE_FUSION_OBJECT_LIST
  @author                 Andreas Kramer
*************************************************************************************************************************/
ALGO_INLINE EM_t_FusionObjectList         const * ACDC_p_GetEMFusionObjList            (void            )
{
  return ACDC_p_GetAccessData()->Input.ReqPorts.pEmFusionObjList;
}

/*************************************************************************************************************************
  Functionname:           ACDC_p_GetEMFusionObj                                                                    */ /*!
  @brief                  Returns a pointer to the Fusion object
  @return                 EM_t_FusionObject const *
  @glob_in                @ref ACDC_pEmFusionObjList
  @c_switch_full          @ref FCT_CFG_INCLUDE_FUSION_OBJECT_LIST
  @author                 Andreas Kramer
*************************************************************************************************************************/
ALGO_INLINE EM_t_FusionObject             const * ACDC_p_GetEMFusionObj                (ObjNumber_t const iObj)
{
  /* Perform range check before accessing an object */
  /* Suppress "Msg(3:3112) This statement has no side-effect - it can be removed"  */ /*PRQA S 3112 1*/
  ACDC_ASSERT((iObj >= 0) && (iObj < EM_N_OBJECTS));

  return &(ACDC_p_GetEMFusionObjList()->aObject[iObj]);
}
#endif /* (FCT_CFG_INCLUDE_FUSION_OBJECT_LIST) */

#if (FCT_USE_EM_CAM_TECH_OBJECT_LIST)
/************************************************************************/
/* Camera object list                                                   */
/************************************************************************/
/*************************************************************************************************************************
  Functionname:           ACDC_p_GetEMCAMObjList                                                                         */ /*!
  @brief                  Returns a pointer to the Cam Object List
  @return                 EM_t_CamObjectList const *
  @glob_in                @ref  ACDC_p_GetAccessData
  @c_switch_full          @ref FCT_USE_EM_CAM_TECH_OBJECT_LIST
  @author                 Andreas Kramer
*************************************************************************************************************************/
ALGO_INLINE EM_t_CamObjectList const * ACDC_p_GetEMCAMObjList(void)
{
  return ACDC_p_GetAccessData()->Input.ReqPorts.pEmCamObjList;
}

/*************************************************************************************************************************
  Functionname:           ACDC_p_GetEMCAMObj                                                                             */ /*!
  @brief                  Returns a pointer to the Cam Object with the given index.
  @return                 EM_t_CamObject const *
  @glob_in                @ref ACDC_p_GetEMCAMObjList
  @param[in]              iObj : Index of the considered object. \range [0,+...[
  @c_switch_full          @ref FCT_USE_EM_CAM_TECH_OBJECT_LIST
  @author                 Andreas Kramer
*************************************************************************************************************************/
ALGO_INLINE EM_t_CamObject const * ACDC_p_GetEMCAMObj(ObjNumber_t const iObj)
{
  /* Perform range check before accessing an object */
  /* Suppress "Msg(3:3112) This statement has no side-effect - it can be removed"  */ /*PRQA S 3112,3119 1*/
  ACDC_ASSERT((iObj >= 0) && (iObj < EM_N_OBJECTS));

  return &(ACDC_p_GetEMCAMObjList()->aObject[iObj]);
}
#endif /* (FCT_USE_EM_CAM_TECH_OBJECT_LIST) */



/************************************************************************/
/* VDY signals                                                          */
/************************************************************************/

/*************************************************************************************************************************
  Functionname:           ACDC_p_GetVDYDynObjSync                                                                        */ /*!
  @brief                  Returns a pointer to the synchronized ego vehicle dynamics.
  @return                 VehDyn_t const * : pointer to the synchronized ego vehicle dynamics.
  @glob_in                @ref ACDC_p_GetAccessData
   @pre                  None

  @post                 None

  @InOutCorrelation     see description

  @testmethod           @ref TEST_ACDC_F_GETEGODYNOBJSYNC_001

  @traceability          Design Decision
  @author                 Andreas Kramer
*************************************************************************************************************************/
ALGO_INLINE VehDyn_t const * ACDC_p_GetVDYDynObjSync(void)
{
  return ACDC_p_GetAccessData()->Input.ReqPorts.pEgoDynObjSync;
}

/*************************************************************************************************************************
  Functionname:           ACDC_f_GetEgoVelObjSync                                                                        */ /*!
  @brief                  Returns the synchronized longitudinal velocity of the ego vehicle.
  @return                 float32 : Synchronized longitudinal velocity of the ego vehicle. \unit [m/s] \range ]-...,+...[
  @glob_in                @ref ACDC_p_GetVDYDynObjSync
  @c_switch_part          @ref VDY_VEH_DYN_INTFVER
   @pre                  None

  @post                 None

  @InOutCorrelation     see description

  @testmethod           @ref TEST_ACDC_F_GETEGOVELOBJSYNC_001

  @traceability          Design Decision
  @author                 Andreas Kramer
*************************************************************************************************************************/
ALGO_INLINE float32 ACDC_f_GetEgoVelObjSync(void)
{
#if (VDY_VEH_DYN_INTFVER >= 32)
  return ACDC_p_GetVDYDynObjSync()->Longitudinal.Velocity;
#else
  return ACDC_p_GetVDYDynObjSync()->Longitudinal.MotVar.Velocity;
#endif
}

/*************************************************************************************************************************
  Functionname:           ACDC_f_GetEgoAccelObjSync                                                                      */ /*!
  @brief                  Returns the synchronized longitudinal ego acceleration.
  @return                 float32 : Synchronized longitudinal ego acceleration. \unit [m/s^2] \range ]-...,+...[
  @glob_in                @ref ACDC_p_GetVDYDynObjSync
  @c_switch_part          @ref VDY_VEH_DYN_INTFVER
   @pre                  None

  @post                 None

  @InOutCorrelation     see description

  @testmethod           @ref TEST_ACDC_F_GETEGOACCELOBJSYNC_001

  @traceability          Design Decision
  @author                 Andreas Kramer
*************************************************************************************************************************/
ALGO_INLINE float32 ACDC_f_GetEgoAccelObjSync(void)
{
#if (VDY_VEH_DYN_INTFVER >= 32)
  return ACDC_p_GetVDYDynObjSync()->Longitudinal.Accel;
#else
  return ACDC_p_GetVDYDynObjSync()->Longitudinal.MotVar.Accel;
#endif
}

/*************************************************************************************************************************
  Functionname:           ACDC_p_GetVDYDynRaw                                                                            */ /*!
  @brief                  Returns the ego vehicle dynamics.
  @return                 VehDyn_t const * : Pointer to the dynamics of the ego vehicle.
  @glob_in                @ref ACDC_p_GetAccessData
   @pre                  None

  @post                 None

  @InOutCorrelation     see description

  @testmethod           @ref TEST_ACDC_P_GETVDYDYNRAW_001

  @traceability          Design Decision
  @author                 Andreas Kramer
*************************************************************************************************************************/
ALGO_INLINE VehDyn_t const *  ACDC_p_GetVDYDynRaw(void)
{
  return ACDC_p_GetAccessData()->Input.ReqPorts.pEgoDynRaw;
}

/*************************************************************************************************************************
  Functionname:           ACDC_f_GetEgoVelRaw                                                                            */ /*!
  @brief                  Returns the unsynchronized longitudinal ego velocity.
  @return                 float32 : Unsynchronized longitudinal ego velocity. \unit [m/s] \range ]-...,+...[
  @glob_in                @ref ACDC_p_GetVDYDynRaw
  @c_switch_part          @ref VDY_VEH_DYN_INTFVER
   @pre                  None

  @post                 None

  @InOutCorrelation     see description

  @testmethod           @ref TEST_ACDC_F_GETEGOVELRAW_001

  @traceability          Design Decision
  @author                 Andreas Kramer
*************************************************************************************************************************/
ALGO_INLINE float32 ACDC_f_GetEgoVelRaw(void)
{
#if (VDY_VEH_DYN_INTFVER >= 32)
  return ACDC_p_GetVDYDynRaw()->Longitudinal.Velocity;
#else
  return ACDC_p_GetVDYDynRaw()->Longitudinal.VeloCorr.corrVelo;
#endif
}

/*************************************************************************************************************************
Functionname:             ACDC_f_GetEgoAccelRaw                                                                          */ /*!
  @brief                  Returns the unsynchronized longitudinal ego acceleration.
  @return                 float32 : Unsynchronized longitudinal ego acceleration. \unit [m/s^2] \range ]-...,+...[
  @glob_in                @ref ACDC_p_GetVDYDynRaw
  @c_switch_part          @ref VDY_VEH_DYN_INTFVER
   @pre                  None

  @post                 None

  @InOutCorrelation     see description

  @testmethod           @ref TEST_ACDC_F_GETEGOACCELRAW_001

  @traceability          Design Decision
  @author                 Andreas Kramer
*************************************************************************************************************************/
ALGO_INLINE float32 ACDC_f_GetEgoAccelRaw(void)
{
#if (VDY_VEH_DYN_INTFVER >= 32)
  return ACDC_p_GetVDYDynRaw()->Longitudinal.Accel;
#else
  return ACDC_p_GetVDYDynRaw()->Longitudinal.AccelCorr.corrAccel;
#endif
}

/************************************************************************/
/* Vehicle parameter                                                    */
/************************************************************************/

/*************************************************************************************************************************
  Functionname:           ACDC_p_GetVehPar                                                                               */ /*!
  @brief                  Returns the vehicle parameters.
  @return                 VehPar_t const * : Pointer to the vehicle parameters.
  @glob_in                @ref ACDC_p_GetAccessData
   @pre                  None

  @post                 None

  @InOutCorrelation     see description

  @testmethod           @ref TEST_ACDC_P_GETVEHPAR_001

  @traceability          Design Decision
  @author                 Andreas Kramer
*************************************************************************************************************************/
ALGO_INLINE VehPar_t const *  ACDC_p_GetVehPar(void)
{
  return ACDC_p_GetAccessData()->Input.ReqPorts.pEgoStaticData;
}

/*************************************************************************************************************************
  Functionname:           ACDC_p_GetSensorMounting                                                                       */ /*!
  @brief                  Returns information about the sensor mounting.
  @return                 SensorMounting_t const *: Structure with details about the sensor mounting.
  @glob_in                @ref ACDC_p_GetVehPar
   @pre                  None

  @post                 None

  @InOutCorrelation     see description

  @testmethod           @ref TEST_ACDC_P_GETSENSORMOUNTING_001

  @traceability          Design Decision
  @author                 Andreas Kramer
*************************************************************************************************************************/
ALGO_INLINE SensorMounting_t const *  ACDC_p_GetSensorMounting(void)
{
  return &(ACDC_p_GetVehPar()->SensorMounting);
}

/*************************************************************************************************************************
  Functionname:    ACDC_u_GetIOStateEgoSpeedX                                                                       */ /*!
  @brief           Returns the input/output state of X
  @return          VDYIoStateTypes_t
  @glob_in         @ref ACDC_p_GetVDYDynRaw
   @pre                  None

  @post                 None

  @InOutCorrelation     see description

  @testmethod           @ref TEST_ACDC_U_GETIOSTATEEGOSPEEDX_001

  @traceability          Design Decision
  @author          Andreas Kramer |  | +49 (8382) 9699-246
*************************************************************************************************************************/
ALGO_INLINE  VDYIoStateTypes_t  ACDC_u_GetIOStateEgoSpeedX(void)
{
#if (VDY_VEH_DYN_INTFVER >= 32)
  return VDY_GET_IO_STATE(VDY_SOUT_POS_VELOCITY, ACDC_p_GetVDYDynRaw()->State) ;
#else
  return VDY_GET_IO_STATE(VDY_SOUT_POS_VEL, ACDC_p_GetVDYDynRaw()->State) ;
#endif
}


/*************************************************************************************************************************
  Functionname:    ACDC_u_GetIOStateEgoSpeedX                                                                       */ /*!
  @brief           Returns the input/output state of X
  @return          VDYIoStateTypes_t
  @pre                  None

  @post                 None

  @InOutCorrelation     see description

  @testmethod           @ref TEST_ACDC_U_GETIOSTATEEGOACCELX_001

  @traceability          Design Decision
  @author          Andreas Kramer |  | +49 (8382) 9699-246
*************************************************************************************************************************/
ALGO_INLINE  VDYIoStateTypes_t  ACDC_u_GetIOStateEgoAccelX(void)
{
  return VDY_GET_IO_STATE(VDY_SOUT_POS_ACCEL, ACDC_p_GetVDYDynRaw()->State) ;
}


/*************************************************************************************************************************
  Functionname:    ACDC_u_GetIOStateEgoAccelY                                                                       */ /*!
  @brief           Returns the input/output state of X
  @return          VDYIoStateTypes_t
  @glob_in         @ref ACDC_p_GetVDYDynRaw
   @pre                  None

  @post                 None

  @InOutCorrelation     see description

  @testmethod           @ref TEST_ACDC_U_GETIOSTATEEGOACCELY_001

  @traceability          Design Decision
  @author          Andreas Kramer |  | +49 (8382) 9699-246
*************************************************************************************************************************/
ALGO_INLINE  VDYIoStateTypes_t  ACDC_u_GetIOStateEgoAccelY(void)
{
#if (VDY_VEH_DYN_INTFVER >= 32)
  return VDY_GET_IO_STATE(VDY_SOUT_POS_LATERALACCEL, ACDC_p_GetVDYDynRaw()->State) ;
#else
  return VDY_GET_IO_STATE(VDY_SOUT_POS_LATACC, ACDC_p_GetVDYDynRaw()->State) ;
#endif
}

/*************************************************************************************************************************
  Functionname:    ACDC_u_GetIOStateEgoYawRate                                                                       */ /*!
  @brief           Returns the input/output state of X
  @return          VDYIoStateTypes_t
  @glob_in         @ref ACDC_p_GetVDYDynRaw
  @pre                  None

  @post                 None

  @InOutCorrelation     see description

  @testmethod           @ref TEST_ACDC_U_GETIOSTATEEGOYAWRATE_001

  @traceability          Design Decision

  @author          Andreas Kramer |  | +49 (8382) 9699-246
*************************************************************************************************************************/
ALGO_INLINE  VDYIoStateTypes_t  ACDC_u_GetIOStateEgoYawRate(void)
{
#if (VDY_VEH_DYN_INTFVER >= 32)
  return VDY_GET_IO_STATE(VDY_SOUT_POS_YAWRATE, ACDC_p_GetVDYDynRaw()->State) ;
#else
  return VDY_GET_IO_STATE(VDY_SOUT_POS_YWR, ACDC_p_GetVDYDynRaw()->State) ;
#endif
}

/*************************************************************************************************************************
  Functionname:    ACDC_u_GetIOStateEgoCurve                                                                       */ /*!
  @brief           Returns the input/output state of X
  @return          VDYIoStateTypes_t
  @glob_in         @ref ACDC_p_GetVDYDynRaw
   @pre                  None

  @post                 None

  @InOutCorrelation     see description

  @testmethod           @ref TEST_ACDC_U_GETIOSTATEEGOCURVE_001

  @traceability          Design Decision
  @author          Andreas Kramer |  | +49 (8382) 9699-246
*************************************************************************************************************************/
ALGO_INLINE  VDYIoStateTypes_t  ACDC_u_GetIOStateEgoCurve(void)
{
  return VDY_GET_IO_STATE(VDY_SOUT_POS_CURVE, ACDC_p_GetVDYDynRaw()->State) ;
}

/*************************************************************************************************************************
  Functionname:    ACDC_u_GetIOStateEgoMotion                                                                       */ /*!
  @brief           Returns the input/output state of X
  @return          VDYIoStateTypes_t
  @glob_in         @ref ACDC_p_GetVDYDynRaw
   @pre                  None

  @post                 None

  @InOutCorrelation     see description

  @testmethod           @ref TEST_ACDC_U_GETIOSTATEEGOMOTION_001

  @traceability          Design Decision
  @author          Andreas Kramer |  | +49 (8382) 9699-246
*************************************************************************************************************************/
ALGO_INLINE  VDYIoStateTypes_t  ACDC_u_GetIOStateEgoMotion(void)
{
#if (VDY_VEH_DYN_INTFVER >= 32)
  return VDY_GET_IO_STATE(VDY_SOUT_POS_MOTIONSTATE, ACDC_p_GetVDYDynRaw()->State) ;
#else
  return VDY_GET_IO_STATE(VDY_SOUT_POS_MSTAT, ACDC_p_GetVDYDynRaw()->State) ;
#endif
}

/*************************************************************************************************************************
  Functionname:    ACDC_u_GetEgoMotionState                                                                       */ /*!
  @brief           Returns The motion state of the vehicle *
  @return          MotState_t *
  @glob_in         @ref ACDC_p_GetVDYDynRaw
   @pre                  None

  @post                 None

  @InOutCorrelation     see description

  @testmethod           @ref TEST_ACDC_U_GETEGOMOTIONSTATE_001

  @traceability          Design Decision
  @author          Andreas Kramer |  | +49 (8382) 9699-246
*************************************************************************************************************************/
ALGO_INLINE  MotState_t  ACDC_u_GetEgoMotionState(void)
{
  return ACDC_p_GetVDYDynRaw()->MotionState.MotState;
}

#ifndef IS_SIGNAL_STATUS_OK
#define IS_SIGNAL_STATUS_OK(status)     ( VDY_IO_STATE_VALID == (status) )
#endif

/************************************************************************/
/* Misc                                                                 */
/************************************************************************/
#if (FCT_CFG_EM_FCT_CYCLEMODE)
/*************************************************************************************************************************
  Functionname:           ACDC_p_GetEmFctCycleMode                                                                       */ /*!
  @brief                  Returns the current EM/FCT Cycle Mode
  @return                 EmFctCycleMode_t  const * : Current EM/FCT Cycle mode.
  @glob_in                @ref ACDC_p_GetAccessData
  @switch_full            @ref FCT_CFG_EM_FCT_CYCLEMODE
   @pre                  None

  @post                 None

  @InOutCorrelation     see description

  @testmethod           @ref  TEST_ACDC_P_GETEMFCTCYCLEMODE_001 

  @traceability          Design Decision
  @author                 Andreas Kramer
*************************************************************************************************************************/
ALGO_INLINE EmFctCycleMode_t  const *  ACDC_p_GetEmFctCycleMode(void)
{
  return ACDC_p_GetAccessData()->Input.ReqPorts.pEmFctCycleMode;
}
#endif
/*************************************************************************************************************************
  Functionname:           ACDC_f_GetCycleTime                                                                 */ /*!
  @brief                  Returns the current cycle time (Depending on the configuration 
                          \ref FCT_SEN_CYCLE_TIME or \ref ACDC_p_GetEmFctCycleMode)
  @return                 float32 : Current cycle time. \unit [s] \range ]0,+...[
  @glob_in                @ref ACDC_p_GetEmFctCycleMode
  @switch_part            @ref FCT_CFG_EM_FCT_CYCLEMODE
   @pre                  None

  @post                 None

  @InOutCorrelation     see description

  @testmethod           @ref ACDC_F_GETCYCLETIME_001

  @traceability          Design Decision
  @author                 Andreas Kramer
*************************************************************************************************************************/
ALGO_INLINE float32 ACDC_f_GetCycleTime(void)
{
#if (FCT_CFG_EM_FCT_CYCLEMODE)
  return ACDC_p_GetEmFctCycleMode()->fEmFctCycleTime;
#else
  return FCT_SEN_CYCLE_TIME;
#endif
}

#if (FCT_CFG_ALIGNMENT_MONITORING_INPUT)
/*************************************************************************************************************************
  Functionname:           ACDC_p_GetAlnMonInput                                                                          */ /*!
  @brief                  Returns the alignment monitoring.
  @return                 ALN_S_Monitoring_t const * : Alignment monitoring structure.
  @glob_in                @ref ACDC_p_GetAccessData
  @switch_full            @ref FCT_CFG_ALIGNMENT_MONITORING_INPUT
   @pre                  None

  @post                 None

  @InOutCorrelation     see description

  @testmethod           @ref TEST_ACDC_P_GETALNMONINPUT_001

  @traceability          Design Decision
  @author                 Andreas Kramer
*************************************************************************************************************************/
ALGO_INLINE ALN_S_Monitoring_t const *  ACDC_p_GetAlnMonInput(void)
{
  return ACDC_p_GetAccessData()->Input.ReqPorts.pAlignmentMonInput;
}
#endif

#if (FCT_CFG_CD_CUSTOM_OUTPUT_INTERFACE)
/*************************************************************************************************************************
  Functionname:           ACDC_p_GetCDCustomOutput                                                                 */ /*!
  @brief                  Returns the custom CD output.
  @return                 FCTCDOutputCustom_t const * : Custom CD output structure.
  @glob_in                @ref ACDC_p_GetAccessData
  @switch_full            @ref FCT_CFG_CD_CUSTOM_OUTPUT_INTERFACE
   @pre                  None

  @post                 None

  @InOutCorrelation     see description

  @testmethod           @ref TEST_ACDC_P_GETCDCUSTOMOUTPUT_001 

  @traceability          Design Decision
  @author                 Andreas Kramer
*************************************************************************************************************************/
ALGO_INLINE FCTCDOutputCustom_t const *  ACDC_p_GetCDCustomOutput(void)
{
  return ACDC_p_GetAccessData()->Output.ProPorts.pCDCustomOutput;
}

/*************************************************************************************************************************
  Functionname:           ACDC_p_ModCDCustomOutput                                                                 */ /*!
  @brief                  Returns the custom CD output.
  @return                 FCTCDOutputCustom_t * : Custom CD output structure.
  @glob_in                @ref ACDC_p_ModProPortList
  @switch_full            @ref FCT_CFG_CD_CUSTOM_OUTPUT_INTERFACE
   @pre                  None

  @post                 None

  @InOutCorrelation     see description

  @testmethod           @ref TEST_ACDC_P_MODCDCUSTOMOUTPUT_001

  @traceability          Design Decision
  @author                 Andreas Kramer
*************************************************************************************************************************/
ALGO_INLINE FCTCDOutputCustom_t *  ACDC_p_ModCDCustomOutput(void)
{
  return ACDC_p_ModProPortList()->pCDCustomOutput;
}

#endif /* (FCT_CFG_CD_CUSTOM_OUTPUT_INTERFACE) */

#if (FCT_CFG_COLLISION_DETECTION)
/*************************************************************************************************************************
  Functionname:           ACDC_p_GetHypothesisIntf                                                                 */ /*!
  @brief                  Returns the hypothesis interface of the ACDC component
  @return                 HypothesisIntf_t const * : Structure of the hypothesis interface.
  @glob_in                @ref ACDC_p_GetProPortList
  @switch_full            @ref FCT_CFG_COLLISION_DETECTION
   @pre                  None

  @post                 None

  @InOutCorrelation     see description

  @testmethod           @ref TEST_ACDC_P_GETHYPOTHESISINTF_001

  @traceability          Design Decision
  @author                 Andreas Kramer
*************************************************************************************************************************/
ALGO_INLINE HypothesisIntf_t const *  ACDC_p_GetHypothesisIntf(void)
{
  return ACDC_p_GetProPortList()->pHypotheses;
}

/*************************************************************************************************************************
  Functionname:           ACDC_p_ModHypothesisIntf                                                                 */ /*!
  @brief                  Returns the hypothesis interface of the ACDC component
  @return                 HypothesisIntf_t * : Structure of the hypothesis interface.
  @glob_in                @ref ACDC_p_ModProPortList
  @switch_full            @ref FCT_CFG_COLLISION_DETECTION
   @pre                  None

  @post                 None

  @InOutCorrelation     see description

  @testmethod           @ref TEST_ACDC_P_MODHYPOTHESISINTF_001

  @traceability          Design Decision
  @author                 Andreas Kramer
*************************************************************************************************************************/
ALGO_INLINE HypothesisIntf_t *  ACDC_p_ModHypothesisIntf(void)
{
  return ACDC_p_ModProPortList()->pHypotheses;
}

/*************************************************************************************************************************
  Functionname:           ACDC_p_GetExtHypothesis                                                                    */ /*!
  @brief                  Returns the hypothesis with the given index.
  @return                 Hypothesis_t const * : Pointer to a hypothesis.
  @param[in]              iHyp : Index of the considered object. \range [0,+...[
  @glob_in                @ref ACDC_p_GetHypothesisIntf
  @switch_full            @ref FCT_CFG_COLLISION_DETECTION
   @pre                  None

  @post                 None

  @InOutCorrelation     see description

  @testmethod           @ref TEST_ACDC_P_GETEXTHYPOTHESIS_001

  @traceability          Design Decision
  @author                 Andreas Kramer
*************************************************************************************************************************/
ALGO_INLINE Hypothesis_t const *  ACDC_p_GetExtHypothesis(sint32 iHyp)
{
  /* Check range */
  /* Suppress "Msg(3:3112) This statement has no side-effect - it can be removed"  */ /*PRQA S 3112,3119 1*/
  ACDC_ASSERT((0 <= iHyp) && (iHyp < MAX_NUM_OF_HYPS));

  return &(ACDC_p_GetHypothesisIntf()->Hypothesis[iHyp]);
}

/*************************************************************************************************************************
  Functionname:           ACDC_p_ModExtHypothesis                                                                    */ /*!
  @brief                  Returns the hypothesis with the given index.
  @return                 Hypothesis_t * : Pointer to a hypothesis.
  @param[in]              iHyp : Index of the considered object. \range [0,+...[
  @glob_in                @ref ACDC_p_ModHypothesisIntf
  @switch_full            @ref FCT_CFG_COLLISION_DETECTION
   @pre                  None

  @post                 None

  @InOutCorrelation     see description

  @testmethod           @ref TEST_ACDC_P_MODEXTHYPOTHESIS_001

  @traceability          Design Decision
  @author                 Andreas Kramer
*************************************************************************************************************************/
ALGO_INLINE Hypothesis_t *  ACDC_p_ModExtHypothesis(sint32 iHyp)
{
  /* Check range */
  /* Suppress "Msg(3:3112) This statement has no side-effect - it can be removed"  */ /*PRQA S 3112,3119 1*/
  ACDC_ASSERT((0 <= iHyp) && (iHyp < MAX_NUM_OF_HYPS));

  return &(ACDC_p_ModHypothesisIntf()->Hypothesis[iHyp]);
}

/*************************************************************************************************************************
  Functionname:           ACDC_p_GetHypDegradation                                                                */ /*!
  @brief                  Returns the degradation structure which is in the hypothesis interface.
  @return                 HypoIntfDegr_t const * : Pointer to the degradation structure.
  @glob_in                @ref ACDC_p_GetHypothesisIntf
  @switch_full            @ref FCT_CFG_COLLISION_DETECTION
   @pre                  None

  @post                 None

  @InOutCorrelation     see description

  @testmethod           @ref TEST_ACDC_P_GETHYPDEGRADATION_001 

  @traceability          Design Decision
  @author                 Andreas Kramer
*************************************************************************************************************************/
ALGO_INLINE HypoIntfDegr_t const *  ACDC_p_GetHypDegradation(void)
{
  return &(ACDC_p_GetHypothesisIntf()->Degradation);
}

/*************************************************************************************************************************
  Functionname:           ACDC_p_ModHypDegradation                                                                */ /*!
  @brief                  Returns the degradation structure which is in the hypothesis interface.
  @return                 HypoIntfDegr_t * : Pointer to the degradation structure.
  @glob_in                @ref ACDC_p_ModHypothesisIntf
  @switch_full            @ref FCT_CFG_COLLISION_DETECTION
   @pre                  None

  @post                 None

  @InOutCorrelation     see description

  @testmethod           @ref TEST_ACDC_P_MODHYPDEGRADATION_001

  @traceability          Design Decision
  @author                 Andreas Kramer
*************************************************************************************************************************/
ALGO_INLINE HypoIntfDegr_t *  ACDC_p_ModHypDegradation(void)
{
  return &(ACDC_p_ModHypothesisIntf()->Degradation);
}

#endif /* (FCT_CFG_COLLISION_DETECTION) */

#if (FCT_CFG_BSW_ALGO_PARAMS)
/*************************************************************************************************************************
  Functionname:           ACDC_p_GetAlgoParameters                                                                 */ /*!
  @brief                  Returns the parameters provided from base software.
  @return                 BSW_s_AlgoParameters_t const * : Pointer to the algo parameters.
  @glob_in                @ref ACDC_p_GetAccessData
  @switch_full            @ref FCT_CFG_BSW_ALGO_PARAMS
   @pre                  None

  @post                 None

  @InOutCorrelation     see description

  @testmethod           @ref TEST_ACDC_P_GETALGOPARAMETERS_001

  @traceability          Design Decision
  @author                 Andreas Kramer
*************************************************************************************************************************/
ALGO_INLINE BSW_s_AlgoParameters_t const *  ACDC_p_GetAlgoParameters(void)
{
  return ACDC_p_GetAccessData()->Input.ReqPorts.pBswAlgoParameters;
}
#endif


#if(ACDC_CFG_AIP)

/*************************************************************************************************************************
  Functionname:         ACDC_p_GetEgoData                                                           */ /*!
  @brief                Returns the pointer to the ACDC_Ego structure
  @return               ACDCEgoData_t const * 
  @glob_in              @ref ACDC_p_GetWorkingData
  @c_switch_full        None
   @pre                  None

  @post                 None

  @InOutCorrelation     see description

  @testmethod           @ref TEST_ACDC_P_GETEGODATA_001

  @traceability          Design Decision
  @author               Andreas Kramer
*************************************************************************************************************************/
ALGO_INLINE ACDCEgoData_t const * ACDC_p_GetEgoData (void)
{
  return &(ACDC_p_GetWorkingData()->pIntraCycle->sGlobData.AIP.sEgoData);
}

/*************************************************************************************************************************
  Functionname:         ACDC_p_ModEgoData                                                           */ /*!
  @brief                Returns the pointer to the ACDC_Ego structure
  @return               ACDCEgoData_t  * 
  @glob_in              @ref ACDC_p_ModWorkingData
  @c_switch_full        None
   @pre                  None

  @post                 None

  @InOutCorrelation     see description

  @testmethod           @ref TEST_ACDC_P_MODEGODATA_001

  @traceability          Design Decision
  @author               Andreas Kramer
*************************************************************************************************************************/
ALGO_INLINE ACDCEgoData_t  * ACDC_p_ModEgoData (void)
{
  return &(ACDC_p_ModWorkingData()->pIntraCycle->sGlobData.AIP.sEgoData);
}


/*************************************************************************************************************************
  Functionname:           ACDC_p_GetEgoGeometry                                                                 */ /*!
  @brief                  Returns a pointer to the ego vehicle geometry
  @return                 ACDCGeometry_t
  @glob_in                @ref ACDC_p_GetEgoData
   @pre                  None

  @post                 None

  @InOutCorrelation     see description

  @testmethod           @ref TEST_ACDC_P_GETEGOGEOMETRY_001 

  @traceability          Design Decision
  @author                 Andreas Danner
*************************************************************************************************************************/
ALGO_INLINE ACDCGeometry_t const * ACDC_p_GetEgoGeometry(void)
{
  return &(ACDC_p_GetEgoData()->Geometry);
}

/*************************************************************************************************************************
  Functionname:           ACDC_p_GetEgoMovementRaw                                                              */ /*!
  @brief                  Returns a pointer to the raw ego movement structure
  @return                 SFLMovement_t
  @glob_in                @ref ACDC_p_GetEgoData
   @pre                  None

  @post                 None

  @InOutCorrelation     see description

  @testmethod           @ref TEST_ACDC_P_GETEGOMOVEMENTRAW_001

  @traceability          Design Decision
  @author                 Andreas Danner
*************************************************************************************************************************/
ALGO_INLINE SFLMovement_t const * ACDC_p_GetEgoMovementRaw(void)
{
  return &(ACDC_p_GetEgoData()->MovementRaw);
}

/*************************************************************************************************************************
  Functionname:           ACDC_p_GetEgoMovementObjSync                                                          */ /*!
  @brief                  Returns a pointer to the object synced ego movement structure
  @return                 SFLMovement_t
  @glob_in                @ref ACDC_p_GetEgoData
   @pre                  None

  @post                 None

  @InOutCorrelation     see description

  @testmethod           @ref TEST_ACDC_P_GETEGOMOVEMENTOBJSYNC_001

  @traceability          Design Decision
  @author                 Andreas Danner
*************************************************************************************************************************/
ALGO_INLINE SFLMovement_t const * ACDC_p_GetEgoMovementObjSync(void)
{
  return &(ACDC_p_GetEgoData()->MovementObjSync);
}

/*************************************************************************************************************************
  Functionname:           ACDC_p_GetEgoKinematics                                                               */ /*!
  @brief                  Returns a pointer to the objects ego kinematics
  @return                 ACDCKinEgo_t
  @glob_in                @ref ACDC_p_GetEgoData
   @pre                  None

  @post                 None

  @InOutCorrelation     see description

  @testmethod           @ref TEST_ACDC_P_GETEGOKINEMATICS_001 

  @traceability          Design Decision
  @author                 Andreas Danner
*************************************************************************************************************************/
ALGO_INLINE ACDCKinEgo_t const * ACDC_p_GetEgoKinematics(void)
{
  return &(ACDC_p_GetEgoData()->Kinematics);
}

/*************************************************************************************************************************
  Functionname:           ACDC_p_GetEgoTrajCircle                                                               */ /*!
  @brief                  Returns a pointer to the circle describing the ego kinematics
  @return                 SFLCircle_t
  @glob_in                @ref ACDC_p_GetACDCEgoData
   @pre                  None

  @post                 None

  @InOutCorrelation     see description

  @testmethod           @ref TEST_ACDC_P_GETEGOTRAJCIRCLE_001 

  @traceability          Design Decision
  @author                 Andreas Danner
*************************************************************************************************************************/
ALGO_INLINE SFLCircle_t const * ACDC_p_GetEgoTrajCircle(void)
{

  return &(ACDC_p_GetEgoData()->TrajCircle);
}

/*************************************************************************************************************************
  Functionname:           ACDC_p_GetObjDesc                                                                  */ /*!
  @brief                  Returns a pointer to the ACDC object with the given index.
  @param[in]              iObjectIndex: Index of the requested object. @range [0,EM_N_OBJECTS]
  @return                 ACDCObject_t
  @glob_in                @ref ACDC_p_GetWorkingData
  @c_switch_part          @ref ACDC_CFG_AIP \n
                          @ref USE_AIP_OBJ_INTRA
   @pre                  None

  @post                 None

  @InOutCorrelation     see description

  @testmethod           @ref TEST_ACDC_P_GETOBJDESC_001

  @traceability          Design Decision
  @author                 Andreas Danner
*************************************************************************************************************************/
ALGO_INLINE ACDCObject_t const * ACDC_p_GetObjDesc(ObjNumber_t const iObjectIndex)
{
  /* Range check */
  /* Suppress "Msg(3:3112) This statement has no side-effect - it can be removed"  */ /*PRQA S 3112,3119 1*/
  ACDC_ASSERT((0 <= iObjectIndex) && (iObjectIndex < EM_N_OBJECTS));

  return &(ACDC_p_GetWorkingData()->pIntraCycle->sObjData.aObj[iObjectIndex].AIP.ObjDesc);
}

/*************************************************************************************************************************
  Functionname:           ACDC_p_ModObjDesc                                                                  */ /*!
  @brief                  Returns a pointer to the ACDC object with the given index.
  @param[in]              iObjectIndex: Index of the requested object. @range [0,EM_N_OBJECTS]
  @return                 ACDCObject_t
  @glob_in                @ref ACDC_p_ModWorkingData
  @c_switch_part          @ref ACDC_CFG_AIP \n
                          @ref USE_AIP_OBJ_INTRA
  @pre                  None

  @post                 None

  @InOutCorrelation     see description

  @testmethod           @ref TEST_ACDC_P_MODOBJDESC_001

  @traceability          Design Decision
  @author                 Andreas Danner
*************************************************************************************************************************/
ALGO_INLINE ACDCObject_t * ACDC_p_ModObjDesc(ObjNumber_t const iObjectIndex)
{
  /* Range check */
  /* Suppress "Msg(3:3112) This statement has no side-effect - it can be removed"  */ /*PRQA S 3112,3119 1*/
  ACDC_ASSERT((0 <= iObjectIndex) && (iObjectIndex < EM_N_OBJECTS));

  return &(ACDC_p_ModWorkingData()->pIntraCycle->sObjData.aObj[iObjectIndex].AIP.ObjDesc);
}

/*************************************************************************************************************************
  Functionname:           ACDC_p_GetACDCObjectMain                                                                  */ /*!
  @brief                  Returns a pointer to the "Main" substructure of the ACDC object with the given index.
  @param[in]              iObjectIndex: Index of the requested object. @range [0,EM_N_OBJECTS]
  @return                 ACDCObjDescMain_t
  @glob_in                @ref ACDC_p_GetObjDesc
   @pre                  None

  @post                 None

  @InOutCorrelation     see description

  @testmethod           @ref TEST_ACDC_P_GETACDCOBJECTMAIN_001

  @traceability          Design Decision
  @author                 Andreas Danner
*************************************************************************************************************************/
ALGO_INLINE ACDCObjDescMain_t const * ACDC_p_GetObjDescMain(ObjNumber_t const iObjectIndex)
{
  /* Range check */
  /* Suppress "Msg(3:3112) This statement has no side-effect - it can be removed"  */ /*PRQA S 3112,3119 1*/
  ACDC_ASSERT((0 <= iObjectIndex) && (iObjectIndex < EM_N_OBJECTS));

  return &(ACDC_p_GetObjDesc(iObjectIndex)->ObjDescMain);
}

/*************************************************************************************************************************
  Functionname:           ACDC_p_GetObjMovement                                                                 */ /*!
  @brief                  Returns a pointer to the "Movement" substructure of the ACDC object with the given index.
  @param[in]              iObjectIndex: Index of the requested object. @range [0,EM_N_OBJECTS]
  @return                 ACDCObjMovement_t
  @glob_in                @ref ACDC_p_GetObjDesc
   @pre                  None

  @post                 None

  @InOutCorrelation     see description

  @testmethod           @ref TEST_ACDC_P_GETOBJMOVEMENT_001

  @traceability          Design Decision
  @author                 Andreas Danner
*************************************************************************************************************************/
ALGO_INLINE ACDCObjMovement_t const * ACDC_p_GetObjMovement(ObjNumber_t const iObjectIndex)
{
  /* Range check */
  /* Suppress "Msg(3:3112) This statement has no side-effect - it can be removed"  */ /*PRQA S 3112,3119 1*/
  ACDC_ASSERT((0 <= iObjectIndex) && (iObjectIndex < EM_N_OBJECTS));

  return &(ACDC_p_GetObjDesc(iObjectIndex)->ObjDescMain.Movement);
}

/*************************************************************************************************************************
  Functionname:           ACDC_p_GetObjPositions                                                                */ /*!
  @brief                  Returns a pointer to the "Positions" substructure of the ACDC object with the given index.
  @param[in]              iObjectIndex: Index of the requested object. @range [0,EM_N_OBJECTS]
  @return                 ACDCObjPositions_t
  @glob_in                @ref ACDC_p_GetObjDesc
   @pre                  None

  @post                 None

  @InOutCorrelation     see description

  @testmethod           @ref TEST_ACDC_P_GETOBJPOSITIONS_001

  @traceability          Design Decision
  @author                 Andreas Danner
*************************************************************************************************************************/
ALGO_INLINE ACDCObjPositions_t const * ACDC_p_GetObjPositions(ObjNumber_t const iObjectIndex)
{
  /* Range check */
  /* Suppress "Msg(3:3112) This statement has no side-effect - it can be removed"  */ /*PRQA S 3112,3119 1*/
  ACDC_ASSERT((0 <= iObjectIndex) && (iObjectIndex < EM_N_OBJECTS));

  return &(ACDC_p_GetObjDesc(iObjectIndex)->ObjDescMain.Positions);
}

/*************************************************************************************************************************
  Functionname:           ACDC_p_GetObjTrajRelation                                                             */ /*!
  @brief                  Returns a pointer to the "TrajRelation" substructure of the ACDC object with the given index.
  @param[in]              iObjectIndex: Index of the requested object. @range [0,EM_N_OBJECTS]
  @return                 ACDCObjToTrajRelation_t
  @glob_in                @ref ACDC_p_GetObjDesc
   @pre                  None

  @post                 None

  @InOutCorrelation     see description

  @testmethod           @ref TEST_ACDC_P_GETOBJTRAJRELATION_001

  @traceability          Design Decision
  @author                 Andreas Danner
*************************************************************************************************************************/
ALGO_INLINE ACDCObjToTrajRelation_t const * ACDC_p_GetObjTrajRelation(ObjNumber_t const iObjectIndex)
{
  /* Range check */
  /* Suppress "Msg(3:3112) This statement has no side-effect - it can be removed"  */ /*PRQA S 3112,3119 1*/
  ACDC_ASSERT((0 <= iObjectIndex) && (iObjectIndex < EM_N_OBJECTS));

  return &(ACDC_p_GetObjDesc(iObjectIndex)->ObjDescMain.TrajRelation);
}

/*************************************************************************************************************************
  Functionname:           ACDC_a_GetObjShapePointQualities                                                      */ /*!
  @brief                  Returns a pointer to the first element of the shape point quality array of the ACDC 
                          object with the given index.
  @param[in]              iObjectIndex: Index of the requested object. @range [0,EM_N_OBJECTS]
  @return                 float32 *
  @glob_in                @ref ACDC_p_GetObjDesc
   @pre                  None

  @post                 None

  @InOutCorrelation     see description

  @testmethod           @ref TEST_ACDC_A_GETOBJSHAPEPOINTQUALITIES_001

  @traceability          Design Decision
  @author                 Andreas Danner
*************************************************************************************************************************/
ALGO_INLINE float32 const * ACDC_a_GetObjShapePointQualities(ObjNumber_t const iObjectIndex)
{
  /* Range check */
  /* Suppress "Msg(3:3112) This statement has no side-effect - it can be removed"  */ /*PRQA S 3112,3119 1*/
  ACDC_ASSERT((0 <= iObjectIndex) && (iObjectIndex < EM_N_OBJECTS));

  return ACDC_p_GetObjDesc(iObjectIndex)->ObjDescAdd.afShapePointQualities;
}

/*************************************************************************************************************************
  Functionname:           ACDC_p_GetObjGeometry                                                                 */ /*!
  @brief                  Returns a pointer to the "Geometry" substructure of the ACDC object with the given index.
  @param[in]              iObjectIndex: Index of the requested object. @range [0,EM_N_OBJECTS]
  @return                 ACDCGeometry_t
  @glob_in                @ref ACDC_p_GetObjDesc
   @pre                  None

  @post                 None

  @InOutCorrelation     see description

  @testmethod           @ref TEST_ACDC_P_GETOBJGEOMETRY_001

  @traceability          Design Decision
  @author                 Andreas Danner
*************************************************************************************************************************/
ALGO_INLINE ACDCGeometry_t const * ACDC_p_GetObjGeometry(ObjNumber_t const iObjectIndex)
{
  /* Range check */
  /* Suppress "Msg(3:3112) This statement has no side-effect - it can be removed"  */ /*PRQA S 3112,3119 1*/
  ACDC_ASSERT((0 <= iObjectIndex) && (iObjectIndex < EM_N_OBJECTS));

  return &(ACDC_p_GetObjDesc(iObjectIndex)->ObjDescMain.Geometry);
}

/*************************************************************************************************************************
  Functionname:           ACDC_a_GetObjLimitedShapePoints                                                       */ /*!
  @brief                  Returns a pointer to the first element of the array of limited shape points of the ACDC 
                          object with the given index.
  @param[in]              iObjectIndex: Index of the requested object. @range [0,EM_N_OBJECTS]
  @return                 SFLVector2D_t
  @glob_in                @ref ACDC_p_GetObjDesc
   @pre                  None

  @post                 None

  @InOutCorrelation     see description

  @testmethod           @ref TEST_ACDC_A_GETOBJLIMITEDSHAPEPOINTS_001

  @traceability          Design Decision
  @author                 Andreas Danner
*************************************************************************************************************************/
ALGO_INLINE SFLVector2D_t const * ACDC_a_GetObjLimitedShapePoints(ObjNumber_t const iObjectIndex)
{
  /* Range check */
  /* Suppress "Msg(3:3112) This statement has no side-effect - it can be removed"  */ /*PRQA S 3112,3119 1*/
  ACDC_ASSERT((0 <= iObjectIndex) && (iObjectIndex < EM_N_OBJECTS));

  return ACDC_p_GetObjDesc(iObjectIndex)->ObjDescAdd.asLimitedShapePoints;
}

#endif /* (ACDC_CFG_AIP) */
/* PRQA L:ALGO_INLINES */

#endif /*ACDC_CFG_FRAME*/

#endif /* ACDC_ACCESS_H_INCLUDED */
/**\}*/

