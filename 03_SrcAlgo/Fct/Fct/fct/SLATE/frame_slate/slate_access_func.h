/*! \file **********************************************************************

COMPANY:                   COPYRIGHT (C) Continental AG

PROJECT:                All

CPU:                    All

COMPONENT:              SLATE

MODULNAME:              slate_access_func.h

DESCRIPTION:            Definitions of inline functions to access global data

CREATION DATE:          28.10.2015

VERSION:                $Revision: 1.33 $

LEGACY VERSION:            Revision: 1.9.1.4


  *****************************************************************************/

/*****************************************************************************
  MACROS 
*****************************************************************************/

#ifndef SLATE_ACCESS_FUNC_H_INCLUDED
#define SLATE_ACCESS_FUNC_H_INCLUDED

/*****************************************************************************
  MODULE DESCRIPTION
*****************************************************************************/
/**
\addtogroup frame
\{
*/

#include "slate_ext.h"
#include "fct_sen_access_func.h"
#include "slate_par.h"

/*****************************************************************************
  GLOBAL VARIABLES
*****************************************************************************/
#if (FCT_CFG_SLATE_COMPONENT)
extern MEMSEC_REF SLATEFrame_t t_SLATEFrame;

extern MEMSEC_REF SLATESyncRef_t t_SLATESyncRef;

//extern MEMSEC_REF boolean b_FCTSenSLATEIsInitialized;

extern MEMSEC_REF float32 FCT_fBumperToCoG;

/*! Definition of merge delete object information */
/* Merge Delete Object List */
extern MEMSEC_REF FCTSen_MergeDeleteList_t t_FCTSen_MDObjList;

#if (FCT_CFG_RUNTIME_MEAS)
/* External declaration of FCT ACC runtime measurement info */
extern MEMSEC_REF SLATERuntimeInfo_t t_SLATERuntimeInfo;
#endif

extern MEMSEC_REF SLATEPortHandlerList_t             t_SLATEPortHandlerList;   /*!< List of all Port handlers*/

/*! sub-module state */
#if (FCT_CFG_USE_SERVICE_POINTER_FUNCTS)
extern MEMSEC_REF const AS_t_ServiceFuncts *pSLATE_ServiceFuncts;
#endif
#if (FCT_CFG_USE_BASECTRLDATA)
extern MEMSEC_REF const BaseCtrlData_t        * pSLATE_SenCtrlData;        /*!< FCT control data */
#else
extern MEMSEC_REF const FCTCtrlData_t         * pSLATE_SenCtrlData;        /*!< FCT control data */
#endif
extern MEMSEC_REF const VehDyn_t               * pSLATE_EgoDynObjSync;    /*!< The object list synchronized ego dynamic signals */
extern MEMSEC_REF const VehDyn_t               * pSLATE_EgoDynRaw;        /*!< The dynamic vehicle ego data raw */
extern MEMSEC_REF const VehPar_t               * pSLATE_EgoStaticData;    /*!< the static vehicle ego data */
#if (FCT_CFG_EM_FCT_CYCLEMODE)
extern MEMSEC_REF const EmFctCycleMode_t       * pSLATE_EmFctCycleMode;   /*!< Global system cycle mode etc. data */
#endif
#if (FCT_CFG_OBJECT_LIST_PROC)

extern MEMSEC_REF const EM_t_GenObjectList     * pSLATE_EmGenObjList;     /*!< The generic EM object data */
#if (FCT_USE_EM_CUSTOM_OBJECT_LIST)
extern MEMSEC_REF const EM_t_ObjectList_Custom * pSLATE_EmCustObjList;
#endif
#if (FCT_USE_EM_ARS_TECH_OBJECT_LIST)
extern MEMSEC_REF const EM_t_ARSObjectList     * pSLATE_EmARSObjList;
#endif
#if (FCT_USE_EM_CAM_TECH_OBJECT_LIST)
extern MEMSEC_REF const EM_t_CamObjectList     * pSLATE_EmCamObjList;
#endif


#if (SLATE_CFG_USE_EM_MOVING_OBJECT_TRACES)
extern MEMSEC_REF const MovingObjectTraces_t   * pSLATE_MovObjTraces;     /*!< Moving object traces */
#endif
//#if (FCT_CFG_NEW_TRACES_INTERFACE)
//extern MEMSEC_REF const ObjectTraceList_t      * FCTSEN_pObjectTraces;     /*!< New object traces */
//#endif
#endif
#if (FCT_CFG_SIGNAL_PERF_MONITORING)
extern MEMSEC_REF const PerfDegr_t             * pSLATE_PerfDegrData;     /*!< Performance degradation input data */
//extern MEMSEC_REF SysPerfMonStates_t           * FCTSEN_pSysPerfMonStates; /*!< System performance monitor output data */
#endif
#if (FCT_CFG_ROAD_INPUT)
extern MEMSEC_REF const Road_t                 * pSLATE_RoadData;         /*!< Road/lane information */
#endif
#if (FCT_CFG_RSP_CONTEXT_INPUT)
extern MEMSEC_REF const RSPKontextData_t       * pSLATE_RSPContextData;   /*!< RSP Context data needed for FOV tangents */
#endif
#if (FCT_CFG_CUSTOM_IO_INTERFACE)
extern MEMSEC_REF const FCTCustomInput_t       * pSLATE_CustomInput;      /*!< FCT custom input */
#endif
#if (FCT_CFG_CAMERA_OBJECT_DETECTION)
extern MEMSEC_REF const EM_t_ObjectList_Custom * pSLATE_CameraObjData;    /*!< EM Camera fusion output data */
#endif
#if ((FCT_CFG_ALIGNMENT_MONITORING_INPUT) || (FCT_CFG_INCLUDE_UNUSED_INTF))
extern MEMSEC_REF const ALN_S_Monitoring_t     * pSLATE_AlignmentMonInput; /*!< Alignment monitoring output data */
#endif
#if (FCT_CFG_ME_INPUT_FOR_DEBUG)
extern MEMSEC_REF const ME_in_t                * pSLATE_ME_in;              /*!< FCT mobil-eye input */
#endif
#if (FCT_CFG_BSW_ALGO_PARAMS)
extern MEMSEC_REF const BSW_s_AlgoParameters_t * pSLATE_BswAlgoParameters;  /*!< Input algo parameters from BSW */
#endif
//#if (FCT_CFG_CPAR_PARAMS)
//extern MEMSEC_REF const CPAR_FCT_Parameters_t * FCTSEN_pCPAR_FCT_Parameters;    /*!< FCT Coding Parameters */
//#endif
//#if (FCT_CFG_DIM_OUTPUT_CUSTOM_FCT_SEN_INPUT)
//extern MEMSEC_REF const DIMOutputCustom_t      * FCTSEN_pDIMOutputCustom;    /*!< DIM output custom from FCT_VEH */
//#endif
#if (FCT_CFG_SEN_SIMPLE_NAVI_INTERFACE)
extern MEMSEC_REF const t_NaviInputData        * pSLATE_NaviData;           /*!< Simple navi input data */
#endif
//#if (FCT_CFG_USE_BUS_DEBUG)
//extern MEMSEC_REF const BusDebugData_t         * FCTSEN_pBusDebugData;
//#endif
#if (FCT_CFG_INCLUDE_FUSION_OBJECT_LIST)
extern MEMSEC_REF const EM_t_FusionObjectList  * pSLATE_FusionObjList;      /*! EM Fusion Object List */
#endif
#if (SLATE_CFG_CAM_LANE_INTERFACE)
extern MEMSEC_REF const t_CamLaneInputData     * pSLATE_CamLaneData;        /*!< Camera lane input data */
#endif
#if (defined(TSA_SLATE_INPUT_ENABLE) && defined(TSA_SLATE_Input_INTFVER))
extern MEMSEC_REF const TSA_SLATE_Input_t  * pSLATE_TSAInputData;            /*!< Required port pointer, TSA input data from camera */
#elif (FCT_CFG_LONG_CTRL_SLA_SUPPORT && defined(CamSLAInputData_INTFVER))
extern MEMSEC_REF const CamSLAInputData_t   * pSLATE_CamSLAInputData;      /*!< SLA input data from camera */
#endif
#if ((FCT_CFG_ACT_CODE_VERSION) && (FCT_CFG_LOHP_COMPONENT))
extern MEMSEC_REF const LongCtrlInput_t  * pSLATE_LongCtrlResp;           /* Dynamic controller response, in SLATE currently used to get drivemode input */
#endif /* ((FCT_CFG_ACT_CODE_VERSION) && (FCT_CFG_LOHP_COMPONENT)) */
/* Provide ports */

#if (FCT_CFG_USE_ALGOCOMPSTATE)
extern MEMSEC_REF AlgoCompState_t             * pSLATE_SenCompState;      /*!< FCT Sensor Algorithm Component State */
#endif

#if (FCT_CFG_OBJECT_LIST_PROC)
#if (FCT_CFG_ASSESSED_OBJ_OUT_INTF)
extern MEMSEC_REF AssessedObjList_t            * pSLATE_PubFctObjList;    /*!< The public FCT object data */
#endif
#endif

#if (FCT_CFG_LOHP_COMPONENT)
extern MEMSEC_REF SLATE_HC_Data_t *       pSLATE_HC_Data;
#endif
#if (FCT_CFG_SIGNAL_PERF_MONITORING)
extern MEMSEC_REF SLATE_SPM_Data_t *       pSLATE_SPM_Data;
#endif
#if (FCT_CFG_COLLISION_DETECTION)
extern MEMSEC_REF SLATE_CD_Data_t *       pSLATE_CD_Data;
#endif

#if (FCT_CFG_CUSTOM_IO_INTERFACE)
extern MEMSEC_REF FCTCustomOutput_t            * pSLATE_CustomOutput;     /*!< FCT custom output */
#endif

/* State of SLATE at the end of current cycles */
//extern MEMSEC_REF SLATECompState_t                   * pSLATE_FinalState;

#if ((FCT_CFG_ERROR_OUTPUT_SEN) || (FCT_CFG_INCLUDE_UNUSED_INTF))
//FCTSenErrorOut_t            * pErrorOut;          /*!< FCT error output */
extern MEMSEC_REF SLATEErrorOutProPort_t             * pSLATE_ErrorOut;
#endif

#if (FCT_CFG_USE_BUS_DEBUG)
//BusDebugData_t              * pFCTSenBusDebugData; /*!< Debug data */
extern MEMSEC_REF BusDebugData_t             * pSLATE_FCTSenBusDebugData;
#endif

#if (FCT_CFG_SEN2VEH_ACC_OOI_PORT)
/* Provide OOI Objects from SEN to VEH */
extern MEMSEC_REF FCTSenAccOOI_t             * pSLATE_AccOOIData;
#endif

#if (FCT_CFG_SEN2TJA_ACC_OOI_PORT)
/* TJA OOI objects from SLATE */
extern MEMSEC_REF TJATargetObj_t            * pSLATE_TJAOOIData;
#endif

#if (FCT_CFG_SLA_FEATURE)
extern MEMSEC_REF SLAData_t                 * pSLATE_SLAData;              /*!< SLA speed limit data from FCT_SEN */
#endif

/*****************************************************************************
  EXTERN VARIABLES
*****************************************************************************/

/*****************************************************************************
  INLINE FUNCTIONS
*****************************************************************************/

/* Deactivate QA-C warning 3406; Reviewer: S. Schwarzkopf; Date: 05.12.2014; 
   Reason: Styleguide specifies this as best practice (R231, R238) and 
   ALGO_INLINE is defined compiler dependent for inlining with internal linkage.
   Review-ID: */
/* PRQA S 3406 ALGO_INLINES */
/**************/
ALGO_INLINE AS_t_ServiceFuncts const * SLATE_p_GetFCTServicePointer(void);

ALGO_INLINE float32 SLATE_f_GetSensorYPosition(void);
ALGO_INLINE float32 SLATE_f_GetMaxCoverageAngle(void);
ALGO_INLINE float32 SLATE_f_GetLobeAngle(void);
ALGO_INLINE float32 SLATE_f_GetSensorXPosToCOG(void);
ALGO_INLINE MotState_t SLATE_t_GetEGOMotionState(void);
ALGO_INLINE  VDYIoStateTypes_t  SLATE_u_EgoMotionState(void);

ALGO_INLINE EM_t_GenObjectList const * SLATE_p_GetEMGenObjList(void);
ALGO_INLINE EM_t_GenObject const * SLATE_p_GetEMGenObj(ObjNumber_t iObj);
ALGO_INLINE EM_t_GenObjKinematics const * SLATE_p_GetEMGenObjKinematics(ObjNumber_t iObj);
ALGO_INLINE EM_t_GenObjQualifiers const * SLATE_p_GetEMGenObjQualifiers(ObjNumber_t iObj);
ALGO_INLINE EM_t_GenObjAttributes const * SLATE_p_GetEMGenObjAttributes(ObjNumber_t iObj);
ALGO_INLINE EM_t_GenObjGenerals const * SLATE_p_GetEMGenObjGeneral(ObjNumber_t iObj);
ALGO_INLINE EM_t_GenObjGeometry const * SLATE_p_GetEMGenObjGeometry(ObjNumber_t iObj);
ALGO_INLINE float32 SLATE_f_GetObjectLength(ObjNumber_t iObj);
ALGO_INLINE ObjNumber_t SLATE_t_GetNumOfObjectsUsed(void);
ALGO_INLINE float32 SLATE_f_GetObjectAngle(ObjNumber_t iObj);
ALGO_INLINE AlgoCycleCounter_t SLATE_u_GetObjLifeCycles(ObjNumber_t iObj);
ALGO_INLINE uint8 SLATE_u_GetAccQuality(ObjNumber_t iObj);
#if (OUT_CFG_CUSTOM_OBSTACLE_PROBABILITY)
ALGO_INLINE percentage_t const * SLATE_pt_GetObjObstacleProbability(ObjNumber_t iObj);
#endif /* (OUT_CFG_CUSTOM_OBSTACLE_PROBABILITY) */

#if (FCT_USE_EM_ARS_TECH_OBJECT_LIST)
ALGO_INLINE EM_t_ARSObjectList const * SLATE_p_GetEMARSObjList(void);
ALGO_INLINE EM_t_ARSObject const * SLATE_p_GetEMARSObj(ObjNumber_t iObj);
ALGO_INLINE TraceID_t const * SLATE_pu_GetEMARSObjTraceID(const ObjNumber_t iObj);
ALGO_INLINE EM_t_ARS_Attributes  const * SLATE_p_GetEMARSObjAttributes(ObjNumber_t iObj);
ALGO_INLINE EM_t_ARS_Geometry  const * SLATE_p_GetEMARSObjGeometry(ObjNumber_t iObj);
ALGO_INLINE EM_t_ARS_Kinematic  const * SLATE_p_GetEMARSObjKinematic(ObjNumber_t iObj);
ALGO_INLINE EM_t_ARS_Legacy  const * SLATE_p_GetEMARSObjLegacy(ObjNumber_t iObj);
ALGO_INLINE EM_t_ARS_MotionAttributes  const * SLATE_p_GetEMARSObjMotionAttributes(ObjNumber_t iObj);
ALGO_INLINE EM_t_ARS_SensorSpecific  const * SLATE_p_GetEMARSObjSensorSpecific(ObjNumber_t iObj);
#endif
#if (FCT_USE_EM_CAM_TECH_OBJECT_LIST)
ALGO_INLINE EM_t_CamObjectList const * SLATE_p_GetEMCAMObjList(void);
ALGO_INLINE EM_t_CamObject const * SLATE_p_GetEMCAMObj(ObjNumber_t iObj);
#endif
#if (FCT_CFG_ASSESSED_OBJ_OUT_INTF)
ALGO_INLINE AssessedObjList_t * SLATE_p_GetFCTPubObjList(void);
ALGO_INLINE HeaderAssessedObjList_t * SLATE_p_GetFCTPubObjListHeader(void);
ALGO_INLINE FCTPubObject_t * SLATE_p_GetFCTPubObj(ObjNumber_t iObj);
ALGO_INLINE LaneInformation_t * SLATE_p_GetFCTPubObj_LaneInfo(ObjNumber_t iObj);
ALGO_INLINE LegacyAOL_t * SLATE_p_GetFCTPubObj_LegacyAOL(ObjNumber_t iObj);
ALGO_INLINE ObjOfInterest_t  * SLATE_p_GetFCTPubObj_OOI(ObjNumber_t iObj);
ALGO_INLINE boolean SLATE_b_IsObjOOI(ObjNumber_t iObj, eObjOOI_t eObjOOI);
ALGO_INLINE boolean SLATE_b_IsObjRelevant(ObjNumber_t iObj);
ALGO_INLINE ObjNumber_t SLATE_i_GetOOIObjIndex(eObjOOI_t eObjOOI);
ALGO_INLINE ObjNumber_t SLATE_i_GetRelObjIndex(void);
#endif
ALGO_INLINE float32 SLATE_f_GetEGORawYawRateQuality(void);
ALGO_INLINE VehDyn_t const * SLATE_p_GetVDYDynObjSync(void);
ALGO_INLINE float32 SLATE_f_GetEgoVelObjSync(void);
ALGO_INLINE float32 SLATE_f_GetEgoAccelObjSync(void);
ALGO_INLINE VehDyn_t const *  SLATE_p_GetVDYDynRaw(void);
ALGO_INLINE float32 SLATE_f_GetEgoVelRaw(void);
ALGO_INLINE float32 SLATE_f_GetEgoAccelRaw(void);
ALGO_INLINE float32 SLATE_f_GetEgoCorrectedAccel(void);
ALGO_INLINE float32 SLATE_f_GetEgoCorrectedSTDAccel(void);
ALGO_INLINE VehPar_t const *  SLATE_p_GetVehPar(void);
ALGO_INLINE SensorMounting_t const *  SLATE_p_GetSensorMounting(void);
#if (FCT_CFG_EM_FCT_CYCLEMODE)
ALGO_INLINE EmFctCycleMode_t  const *  SLATE_p_GetEmFctCycleMode(void);
#endif
ALGO_INLINE float32 SLATE_f_GetCycleTime(void);
ALGO_INLINE float32 SLATE_f_GetSITCycleTime(void);
ALGO_INLINE float32 SLATE_f_GetSPMCycleTime(void);
ALGO_INLINE float32 SLATE_f_GetCPCycleTime(void);
#if (FCT_CFG_ROAD_INPUT)
ALGO_INLINE Road_t const *  SLATE_p_GetRoad(void);
#endif
#if (SLATE_CFG_USE_EM_MOVING_OBJECT_TRACES)
ALGO_INLINE MovingObjectTraces_t const *  SLATE_p_GetObjTraces(void);
ALGO_INLINE ObjectTrace_t const *  SLATE_p_GetObjTrace(sint32 iTrace);
#endif
#if (FCT_CFG_RSP_CONTEXT_INPUT)
ALGO_INLINE RSPKontextData_t const *  SLATE_p_GetRSPContextData(void);
#endif
#if (FCT_CFG_ALIGNMENT_MONITORING_INPUT)
ALGO_INLINE ALN_S_Monitoring_t const *  SLATE_p_GetAlnMonInput(void);
#endif
#if (FCT_CFG_SIGNAL_PERF_MONITORING)
ALGO_INLINE PerfDegr_t   const *  SLATE_p_GetPerfDegr(void);
ALGO_INLINE SysPerfMonStates_t *  SLATE_p_GetSPMStates(void);
#endif
#if (FCT_CFG_RSP_OUTPUT_PD)
ALGO_INLINE RSPOutputPD_t const *  SLATE_p_GetRSPOutputPD(void);
#endif
#if (FCT_CFG_CUSTOM_IO_INTERFACE)
ALGO_INLINE FCTCustomInput_t const *  SLATE_p_GetCustomInput(void);
ALGO_INLINE FCTCustomOutput_t *  SLATE_p_GetCustomOutput(void);
#endif
#if (FCT_CFG_COLLISION_DETECTION)
ALGO_INLINE HypothesisIntf_t *  SLATE_p_GetHypothesisIntf(void);
ALGO_INLINE Hypothesis_t *  SLATE_p_GetHypothesis(sint32 iHyp);
ALGO_INLINE HypoIntfDegr_t *  SLATE_p_GetHypDegradation(void);
#endif
#if (FCT_CFG_BSW_ALGO_PARAMS)
ALGO_INLINE BSW_s_AlgoParameters_t const *  SLATE_p_GetAlgoParameters(void);
#endif
ALGO_INLINE FCTSenFrame_t *  SLATE_p_GetFCTSenFrame(void);
ALGO_INLINE FCTSen_SyncRef_t *  SLATE_p_GetFCTSenSyncRef(void);

extern float32 const * SLATE_pf_GetObjLongDisp(ObjNumber_t iObj);
extern float32 const * SLATE_pf_GetObjLatDisp(ObjNumber_t iObj);
extern float32 const * SLATE_pf_GetObjVrelX(ObjNumber_t iObj);
extern float32 const * SLATE_pf_GetObjVrelY(ObjNumber_t iObj);
extern float32 const * SLATE_pf_GetObjArelX(ObjNumber_t iObj);
ALGO_INLINE float32 const * SLATE_pf_GetObjArelY(ObjNumber_t iObj);
ALGO_INLINE float32 const * SLATE_pf_GetObjVabsY(ObjNumber_t iObj);
ALGO_INLINE float32 const * SLATE_pf_GetObjAabsY(ObjNumber_t iObj);
ALGO_INLINE float32 const * SLATE_pf_GetObjAabsX(ObjNumber_t iObj);
ALGO_INLINE uint16 const * SLATE_pu_GetObjLifeCycles(ObjNumber_t iObj);
ALGO_INLINE boolean SLATE_b_GetObjIsNew(ObjNumber_t iObj);
ALGO_INLINE boolean SLATE_b_GetObjIsDeleted(ObjNumber_t iObj);
extern boolean SLATE_b_GetObjIsRelevant(ObjNumber_t iObj);
ALGO_INLINE float32 const * SLATE_pf_GetObjVrelYStd(ObjNumber_t iObj);
ALGO_INLINE ObjNumber_t const * SLATE_pu_GetDistXSortedObj(ObjNumber_t iObj);
ALGO_INLINE uint8 const * SLATE_pu_GetObjExistProbability(ObjNumber_t iObj);
ALGO_INLINE float32 const * SLATE_pf_GetEgoLongVel(void);
ALGO_INLINE float32 const * SLATE_pf_GetEgoLongAccel(void);
ALGO_INLINE float32 const * SLATE_pf_GetEgoSideSlip(void);
ALGO_INLINE float32 const * SLATE_pf_GetEgoSideSlipVar(void);
ALGO_INLINE float32 const * SLATE_pf_GetEgoCurve(void);
ALGO_INLINE float32 const * SLATE_pf_GetEgoCurveRaw(void);
ALGO_INLINE float32 const * SLATE_pf_GetEgoCurveGrad(void);
ALGO_INLINE float32 const * SLATE_pf_GetEgoCurveVar(void);
ALGO_INLINE float32 const * SLATE_pf_GetEgoDrvIntCurve(void);
ALGO_INLINE float32 const * SLATE_pf_GetEgoDrvIntCurveVar(void);
ALGO_INLINE float32 SLATE_f_GetEgoYawRateObjSync(void);
ALGO_INLINE float32 SLATE_f_GetEgoYawRateVarObjSync(void);
ALGO_INLINE float32 SLATE_f_GetEgoYawRateMaxJitterSync(void);
ALGO_INLINE float32 const * SLATE_pf_GetObjDistYStd(ObjNumber_t iObj);
extern float32 SLATE_f_GetObjDistYVar(ObjNumber_t iObj);
extern float32 SLATE_f_GetObjDistYStd(ObjNumber_t iObj);
extern float32 SLATE_f_GetObjVrelYStd(ObjNumber_t iObj);

ALGO_INLINE float32 const * SLATE_pt_GetObjLifeTime(ObjNumber_t iObj);
ALGO_INLINE AlgoCycleCounter_t const * SLATE_pt_GetObjLifeCycles(ObjNumber_t iObj);
ALGO_INLINE EM_t_GenObjMaintenanceState const * SLATE_pt_GetObjMaintenanceState(ObjNumber_t iObj);
#if (FCT_CFG_EMERGENCY_BRAKE_ASSIST)
ALGO_INLINE EM_t_GenEbaObjClass const * SLATE_pt_GetEbaObjClass(ObjNumber_t iObj);
#endif

#if (FCT_USE_EM_CUSTOM_OBJECT_LIST)
ALGO_INLINE EM_t_Cust_ObjectData const * SLATE_p_GetEMCustObjData(ObjNumber_t iObj);
#endif /* FCT_USE_EM_CUSTOM_OBJECT_LIST */
#if (SLATE_CFG_CAM_LANE_INTERFACE)
ALGO_INLINE t_CamLaneInputData const * SLATE_pt_GetCamLaneData(void);
#endif
ALGO_INLINE float32 const * SLATE_pf_GetSensorYPos(void);
extern boolean SLATE_b_GetObjIsMovingToStationary(ObjNumber_t iObj);
extern boolean SLATE_b_GetObjIsShadow(ObjNumber_t iObj);
extern SLATE_t_Obj_DynamicProperty const * SLATE_pt_GetObjDynProperty(ObjNumber_t iObj);
extern SLATE_t_Obj_CLassification const * SLATE_pt_GetObjClassification(ObjNumber_t iObj);

#if (FCT_USE_EM_ARS_TECH_OBJECT_LIST)
ALGO_INLINE uint8 SLATE_u_GetStoppedConfidence(ObjNumber_t iObj);
extern SLATE_t_Obj_DynamicSubProperty const * SLATE_pt_GetObjDynSubProperty(ObjNumber_t iObj);
#endif

#if (FCT_CFG_INCLUDE_FUSION_OBJECT_LIST)
ALGO_INLINE EM_t_FusionObjectList const * SLATE_pt_GetFusionObjList(void);
#endif

extern float32 SLATE_f_GetObjOrientation(ObjNumber_t iObj);
ALGO_INLINE float32 SLATE_f_GetObjOrientationStd(ObjNumber_t iObj);

#if (FCT_CFG_CUSTOM_IO_INTERFACE)
ALGO_INLINE eTurnIndicator_t const * SLATE_pt_GetTurnIndicator(void);
#endif

#if ((FCT_CFG_ACT_CODE_VERSION) && (FCT_CFG_LOHP_COMPONENT))
ALGO_INLINE DriveMode_t_e const * SLATE_pt_GetDrivemode(void);
#endif /* (FCT_CFG_ACT_CODE_VERSION) && (FCT_CFG_LOHP_COMPONENT) */

#if (SLATE_CFG_USE_EXT_OBJ_ID)
ALGO_INLINE unsigned char const * SLATE_pt_GetExtObjID(ObjNumber_t iObj);
#endif /* ENDIF (FCT_SEN_CFG_USE_EXT_OBJ_ID) */



/************************************************************************/
/*                      ASSERT MACRO                                    */
/************************************************************************/
/* Check if we are in QA-C: PRQA_SIZE_T is defined in QA-C environment. */
#ifdef PRQA_SIZE_T
  /* date: 2017-01-11, reviewer: V.Ehrlinspiel, A.Kramer, reason:  
     Macro SLATE_ASSERT can be set up platform dependent and is intended to have 
     no side effects here.
     Review-ID: 
  */
  #pragma PRQA_MACRO_MESSAGES_OFF "SLATE_ASSERT" 3112
#endif /* #ifdef PRQA_SIZE_T */
#define SLATE_ASSERT(x) FCT_ASSERT(x)

/************************************************************************/
/* FCT Service Pointers                                                 */
/************************************************************************/
#if (FCT_CFG_USE_SERVICE_POINTER_FUNCTS)
/*************************************************************************************************************************
  Functionname:    SLATE_p_GetFCTServicePointer                                                                         */ /*!
  @brief           Return Service Function pointer
  @return          AS_t_ServiceFuncts const *
  @param[in]       void : 
  @author          Huber Veronika |  | +49 (8382) 9699-490
*************************************************************************************************************************/
ALGO_INLINE AS_t_ServiceFuncts const * SLATE_p_GetFCTServicePointer(void)
{
  return pFCTSenServiceFuncts;
}
#endif
/************************************************************************/
/* Vehicle Parameters                                                   */
/************************************************************************/
/*************************************************************************************************************************
  Functionname:    SLATE_f_GetSensorYPosition                                                                       */ /*!
  @brief           Return Sensor Y Position
  @return          float32
  @param[in]       void : 
  @author          Harsha Umesh Babu| harsha.umesh.babu@continental-corporation.com | +49 (8382) 9699-474
*************************************************************************************************************************/
ALGO_INLINE float32 SLATE_f_GetSensorYPosition(void)
{
  return pSLATE_EgoStaticData->SensorMounting.LatPos;
}
/*************************************************************************************************************************
  Functionname:    SLATE_f_GetMaxCoverageAngle                                                                      */ /*!
  @brief           Return Sensor Maximum Coverage angle
  @return          float32
  @param[in]       void : 
  @author          Harsha Umesh Babu| harsha.umesh.babu@continental-corporation.com | +49 (8382) 9699-474
*************************************************************************************************************************/
ALGO_INLINE float32 SLATE_f_GetMaxCoverageAngle(void)
{
  float32 fMaxCoverageAngle = 0.F;
#if (FCT_CFG_SENSOR_TYPE_RADAR)
  fMaxCoverageAngle = ((pSLATE_EgoStaticData->Sensor.fLobeAngle + (pSLATE_EgoStaticData->Sensor.fCoverageAngle * 0.5F)) * 0.5F);
#endif
#if (FCT_CFG_SENSOR_TYPE_CAMERA)
  fMaxCoverageAngle = (15.0F); // In VACC, a little less than FOV? (36deg) or pSLATE_EgoStaticData->Sensor.fCoverageAngle;
#endif
  return fMaxCoverageAngle;
}
/*************************************************************************************************************************
  Functionname:    SLATE_f_GetLobeAngle                                                                             */ /*!
  @brief           Return Sensor lobe angle
  @return          float32
  @param[in]       void : 
  @author          Harsha Umesh Babu| harsha.umesh.babu@continental-corporation.com | +49 (8382) 9699-474
*************************************************************************************************************************/
ALGO_INLINE float32 SLATE_f_GetLobeAngle(void)
{
  float32 fLobeAngle = 0.F;
#if (FCT_CFG_SENSOR_TYPE_RADAR)
  fLobeAngle = pSLATE_EgoStaticData->Sensor.fLobeAngle;
#endif
#if (FCT_CFG_SENSOR_TYPE_CAMERA)
  fLobeAngle = (53.0f/4.0f);// make it smaller
#endif
  return fLobeAngle;
}
/*************************************************************************************************************************
  Functionname:    SLATE_f_GetSensorXPosToCOG                                                                       */ /*!
  @brief           Return Sensor to COG in X axis
  @return          float32
  @param[in]       void : 
  @author          Harsha Umesh Babu| harsha.umesh.babu@continental-corporation.com | +49 (8382) 9699-474
*************************************************************************************************************************/
ALGO_INLINE float32 SLATE_f_GetSensorXPosToCOG(void)
{
  return pSLATE_EgoStaticData->SensorMounting.LongPosToCoG;
}

/*************************************************************************************************************************
  Functionname:    SLATE_f_GetEGOVehicleWidth                                                                       */ /*!
  @brief           Return EGO Vehicle Width
  @return          float32
  @param[in]       void : 
  @author          Harsha Umesh Babu| harsha.umesh.babu@continental-corporation.com | +49 (8382) 9699-474
*************************************************************************************************************************/
ALGO_INLINE float32 SLATE_f_GetEGOVehicleWidth(void)
{
  return pSLATE_EgoStaticData->VehParAdd.VehicleWidth;
}
/*************************************************************************************************************************
  Functionname:    SLATE_p_GetVDYDynRaw                                                                            */ /*!
  @brief           Returns VehDyn_t const *
  @return          VehDyn_t const *
  @author          Andreas Kramer |  | +49 (8382) 9699-246
*************************************************************************************************************************/
ALGO_INLINE VehDyn_t const *  SLATE_p_GetVDYDynRaw(void)
{
  return pSLATE_EgoDynRaw;
}

/*************************************************************************************************************************
  Functionname:    SLATE_t_GetEGOMotionState                                                                       */ /*!
  @brief           Return EGO Vehicle Motion State
  @return          float32
  @param[in]       void : 
  @author          Harsha Umesh Babu| harsha.umesh.babu@continental-corporation.com | +49 (8382) 9699-474
*************************************************************************************************************************/
ALGO_INLINE MotState_t SLATE_t_GetEGOMotionState(void)
{
  return pSLATE_EgoDynRaw->MotionState.MotState;
}

/*************************************************************************************************************************
  Functionname:    ACDC_p_GetSensorMounting                                                                       */ /*!
  @brief           Returns SensorMounting_t const *
  @return          SensorMounting_t const *
  @author          Andreas Kramer |  | +49 (8382) 9699-246
*************************************************************************************************************************/
ALGO_INLINE  VDYIoStateTypes_t  SLATE_u_EgoMotionState(void)
{
#if (VDY_VEH_DYN_INTFVER >= 0x20)   // 0x20 -> 18
  return VDY_GET_IO_STATE(VDY_SOUT_POS_MOTIONSTATE, SLATE_p_GetVDYDynRaw()->State) ;
#else
  return VDY_GET_IO_STATE(VDY_SOUT_POS_MSTAT, SLATE_p_GetVDYDynRaw()->State) ;
#endif
}

#ifndef IS_SIGNAL_STATUS_OK
#define IS_SIGNAL_STATUS_OK(status)     ( VDY_IO_STATE_VALID == (status) )
#endif
/************************************************************************/
/* EM Gen Object list                                                   */
/************************************************************************/
/*************************************************************************************************************************
  Functionname:    SLATE_p_GetEMGenObjList                                                                         */ /*!
  @brief           Return GenObject list pointer
  @return          EM_t_GenObjectList const *
  @param[in]       void : 
  @author          Andreas Kramer |  | +49 (8382) 9699-246
*************************************************************************************************************************/
ALGO_INLINE EM_t_GenObjectList const * SLATE_p_GetEMGenObjList(void)
{
  return pSLATE_EmGenObjList;
}

/*************************************************************************************************************************
  Functionname:    SLATE_p_GetEMGenObj                                                                             */ /*!
  @brief           Returns pointer to Gen object
  @return          EM_t_GenObject const *
  @param[in]       iObj : object index
  @author          Andreas Kramer |  | +49 (8382) 9699-246
*************************************************************************************************************************/
ALGO_INLINE EM_t_GenObject const * SLATE_p_GetEMGenObj(ObjNumber_t iObj)
{
  /* Perform range check before accessing an object */
  /* Suppress "Msg(3:3112) This statement has no side-effect - it can be removed"  */ /*PRQA S 3112 1*/
  SLATE_ASSERT((iObj >= 0) && (iObj < EM_N_OBJECTS));

  return &(SLATE_p_GetEMGenObjList()->aObject[iObj]);
}


/*************************************************************************************************************************
  Functionname:    SLATE_p_GetEMGenObjKinematics                                                                   */ /*!
  @brief           Returns pointer to object kinematic structure
  @return          EM_t_GenObjKinematics const *
  @param[in]       iObj : 
  @author          Andreas Kramer |  | +49 (8382) 9699-246
*************************************************************************************************************************/
ALGO_INLINE EM_t_GenObjKinematics const * SLATE_p_GetEMGenObjKinematics(ObjNumber_t iObj)
{
  return &(SLATE_p_GetEMGenObj(iObj)->Kinematic);
}

/*************************************************************************************************************************
  Functionname:    SLATE_p_GetEMGenObjQualifiers                                                                   */ /*!
  @brief           Returns pointer to object qualifier structure
  @return          EM_t_GenObjQualifiers const *
  @param[in]       iObj : object index
  @author          Andreas Kramer |  | +49 (8382) 9699-246
*************************************************************************************************************************/
ALGO_INLINE EM_t_GenObjQualifiers const * SLATE_p_GetEMGenObjQualifiers(ObjNumber_t iObj)
{
  return &(SLATE_p_GetEMGenObj(iObj)->Qualifiers);
}

/*************************************************************************************************************************
  Functionname:    SLATE_p_GetEMGenObjAttributes                                                                   */ /*!
  @brief           Returns EM_t_GenObjAttributes const *
  @return          EM_t_GenObjAttributes const *
  @param[in]       iObj : object index
  @author          Andreas Kramer |  | +49 (8382) 9699-246
*************************************************************************************************************************/
ALGO_INLINE EM_t_GenObjAttributes const * SLATE_p_GetEMGenObjAttributes(ObjNumber_t iObj)
{
  return &(SLATE_p_GetEMGenObj(iObj)->Attributes);
}

/*************************************************************************************************************************
  Functionname:    SLATE_p_GetEMGenObjGeneral                                                                      */ /*!
  @brief           Returns EM_t_GenObjGenerals const *
  @return          EM_t_GenObjGenerals const *
  @param[in]       iObj : object index
  @author          Andreas Kramer |  | +49 (8382) 9699-246
*************************************************************************************************************************/
ALGO_INLINE EM_t_GenObjGenerals const * SLATE_p_GetEMGenObjGeneral(ObjNumber_t iObj)
{
  return &(SLATE_p_GetEMGenObj(iObj)->General);
}

/*************************************************************************************************************************
  Functionname:    SLATE_p_GetEMGenObjGeometry                                                                     */ /*!
  @brief           Returns EM_t_GenObjGeometry const *
  @return          EM_t_GenObjGeometry const *
  @param[in]       iObj : object index
  @author          Andreas Kramer |  | +49 (8382) 9699-246
*************************************************************************************************************************/
ALGO_INLINE EM_t_GenObjGeometry const * SLATE_p_GetEMGenObjGeometry(ObjNumber_t iObj)
{
  return &(SLATE_p_GetEMGenObj(iObj)->Geometry);
}

/*************************************************************************************************************************
  Functionname:    SLATE_f_GetObjectLength                                                                     */ /*!
  @brief           Returns length of object
  @return          float32
  @param[in]       iObj : object index
  @author          Andreas Kramer |  | +49 (8382) 9699-246
*************************************************************************************************************************/
ALGO_INLINE float32 SLATE_f_GetObjectLength(ObjNumber_t iObj)
{
  float32 fObjLength;
  /* Perform range check before accessing an object */
  /* Suppress "Msg(3:3112) This statement has no side-effect - it can be removed"  */ /*PRQA S 3112 1*/
  SLATE_ASSERT((iObj >= 0) && (iObj < EM_N_OBJECTS));
#if (FCT_USE_EM_ARS_TECH_OBJECT_LIST)
  fObjLength = SLATE_p_GetEMARSObjList()->aObject[iObj].Geometry.fLength;
#else
  fObjLength = 0.F;  // in VACC we need to compute object length from shape points like how they do it in ACDC
  _PARAM_UNUSED(iObj);
#endif
  return fObjLength;
}
/*************************************************************************************************************************
  Functionname:    SLATE_t_GetNumOfObjectsUsed                                                                     */ /*!
  @brief           Returns number of objects used in GEN OBJECT list
  @return          ObjNumber_t
  @param[in]       void
  @author          Andreas Kramer |  | +49 (8382) 9699-246
*************************************************************************************************************************/
ALGO_INLINE ObjNumber_t SLATE_t_GetNumOfObjectsUsed(void)
{
  return SLATE_p_GetEMGenObjList()->HeaderObjList.iNumOfUsedObjects;
}
/*************************************************************************************************************************
  Functionname:    SLATE_f_GetObjectAngle                                                                         */ /*!
  @brief           Returns Object Angle
  @return          float32
  @author          Andreas Kramer |  | +49 (8382) 9699-246
*************************************************************************************************************************/
ALGO_INLINE float32 SLATE_f_GetObjectAngle(ObjNumber_t iObj)
{
  float32 fAngle;
  /* Perform range check before accessing an object */
  /* Suppress "Msg(3:3112) This statement has no side-effect - it can be removed"  */ /*PRQA S 3112 1*/
  SLATE_ASSERT((iObj >= 0) && (iObj < EM_N_OBJECTS));

#if (FCT_USE_EM_ARS_TECH_OBJECT_LIST)
  fAngle = SLATE_p_GetEMARSObjList()->aObject[iObj].Legacy.fAngle;
#else
  fAngle = 0.F;   // VACC there is no object angle, it must be computed from shape points as done in ACDC
  _PARAM_UNUSED(iObj);
#endif
  return fAngle;
}
/*************************************************************************************************************************
  Functionname:    SLATE_f_GetObjectAngle                                                                         */ /*!
  @brief           Returns Object LifeCycles
  @return          uint8
  @author          Andreas Kramer |  | +49 (8382) 9699-246
*************************************************************************************************************************/
ALGO_INLINE AlgoCycleCounter_t SLATE_u_GetObjLifeCycles(ObjNumber_t iObj)
{
  /* Perform range check before accessing an object */
  SLATE_ASSERT((iObj >= 0) && (iObj < EM_N_OBJECTS));
  return SLATE_p_GetEMGenObjList()->aObject[iObj].General.uiLifeCycles;
}

/*************************************************************************************************************************
  Functionname:    SLATE_u_GetAccQuality                                                                         */ /*!
  @brief           Returns Object Acc Quality
  @return          uint8
  @author          Friedrich Kenda-Erbs |  | +49 (8382) 9699-388
*************************************************************************************************************************/
ALGO_INLINE uint8 SLATE_u_GetAccQuality(ObjNumber_t iObj)
{
  /* Perform range check before accessing an object */
  SLATE_ASSERT((iObj >= 0) && (iObj < EM_N_OBJECTS));
#if (FCT_CFG_SENSOR_TYPE_RADAR)
  return SLATE_p_GetEMGenObjQualifiers(iObj)->uiAccObjQuality;
#elif (FCT_CFG_SENSOR_TYPE_CAMERA)
  /* This is a workaround since uiAccObjQuality is currently not properly set from Camera EM. */
  return (((SLATE_p_GetEMGenObjQualifiers(iObj)->uiEbaObjQuality + SLATE_p_GetEMGenObjQualifiers(iObj)->uiProbabilityOfExistence))/2U);
#else
  SLATE_ASSERT(0 && "Invalid sensor configuration!");
  return 0U;
#endif
}

#if (OUT_CFG_CUSTOM_OBSTACLE_PROBABILITY)
/*************************************************************************************************************************
  Functionname:    SLATE_pt_GetObjObstacleProbability                                                                         */ /*!
  @brief           Returns obstacle probability
  @return          uint8
  @author          Gowthama P
*************************************************************************************************************************/
ALGO_INLINE percentage_t const * SLATE_pt_GetObjObstacleProbability(ObjNumber_t iObj)
{
  /* Perform range check before accessing an object */
  SLATE_ASSERT((iObj >= 0) && (iObj < EM_N_OBJECTS));
  return &(pSLATE_EmCustObjList->CustObjects[iObj].uObstacleProbability);
}
#endif /* (OUT_CFG_CUSTOM_OBSTACLE_PROBABILITY) */

#if (FCT_USE_EM_ARS_TECH_OBJECT_LIST)
/************************************************************************/
/* EM ARS Object list                                                   */
/************************************************************************/
/*************************************************************************************************************************
  Functionname:    SLATE_p_GetEMARSObjList                                                                         */ /*!
  @brief           Returns EM_t_ARSObjectList const *
  @return          EM_t_ARSObjectList const *
  @author          Andreas Kramer |  | +49 (8382) 9699-246
*************************************************************************************************************************/
ALGO_INLINE EM_t_ARSObjectList const * SLATE_p_GetEMARSObjList(void)
{
  return pSLATE_EmARSObjList;
}

/*************************************************************************************************************************
  Functionname:    SLATE_p_GetEMARSObj                                                                             */ /*!
  @brief           Returns EM_t_ARSObject const *
  @return          EM_t_ARSObject const *
  @param[in]       iObj : object index
  @author          Andreas Kramer |  | +49 (8382) 9699-246
*************************************************************************************************************************/
ALGO_INLINE EM_t_ARSObject const * SLATE_p_GetEMARSObj(ObjNumber_t iObj)
{
  /* Perform range check before accessing an object */
  /* Suppress "Msg(3:3112) This statement has no side-effect - it can be removed"  */ /*PRQA S 3112 1*/
  SLATE_ASSERT((iObj >= 0) && (iObj < EM_N_OBJECTS));

  return &(SLATE_p_GetEMARSObjList()->aObject[iObj]);
}

/*************************************************************************************************************************
  Functionname:    SLATE_pu_GetEMARSObjTraceID                                                                     */ /*!

  @brief           Inline function for accessing the pointer to Trace ID for object from EM list

  @description     Inline function for accessing the pointer to Trace ID for object from EM list

  @return          Reference to pointer to Trace ID for EM object

  @param[in]       iObj : EM Object number [0 ... EM_N_OBJECTS)

  @glob_in         -
  @glob_out        -

  @c_switch_part   -
  @c_switch_full   FCT_USE_EM_ARS_TECH_OBJECT_LIST : Configuration switch that enables ARS-technology specific object list

  @created         21.11.2016
  @changed         21.11.2016

  @author          Niraj Mistry | niraj.mistry@continental-corporation.com | +49 (8382) 9699-5631
*************************************************************************************************************************/
ALGO_INLINE TraceID_t const * SLATE_pu_GetEMARSObjTraceID(const ObjNumber_t iObj)
{
  /* Perform range check before accessing an object */
  SLATE_ASSERT((iObj >= 0) && (iObj < EM_N_OBJECTS));

  return &(SLATE_p_GetEMARSObjList()->aObject[iObj].Attributes.uiReferenceToTrace);
}

/*************************************************************************************************************************
  Functionname:    SLATE_p_GetEMARSObjAttributes                                                                   */ /*!
  @brief           Returns EM_t_ARS_Attributes  const *
  @return          EM_t_ARS_Attributes  const *
  @param[in]       iObj : object index
  @author          Andreas Kramer |  | +49 (8382) 9699-246
*************************************************************************************************************************/
ALGO_INLINE EM_t_ARS_Attributes  const * SLATE_p_GetEMARSObjAttributes(ObjNumber_t iObj)
{
  return &(SLATE_p_GetEMARSObj(iObj)->Attributes);
}

/*************************************************************************************************************************
  Functionname:    SLATE_p_GetEMARSObjGeometry                                                                     */ /*!
  @brief           Returns EM_t_ARS_Geometry  const *
  @return          EM_t_ARS_Geometry  const *
  @param[in]       iObj : object index
  @author          Andreas Kramer |  | +49 (8382) 9699-246
*************************************************************************************************************************/
ALGO_INLINE EM_t_ARS_Geometry  const * SLATE_p_GetEMARSObjGeometry(ObjNumber_t iObj)
{
  return &(SLATE_p_GetEMARSObj(iObj)->Geometry);
}

/*************************************************************************************************************************
  Functionname:    SLATE_p_GetEMARSObjKinematic                                                                    */ /*!
  @brief           Returns EM_t_ARS_Kinematic  const *
  @return          EM_t_ARS_Kinematic  const *
  @param[in]       iObj : object index
  @author          Andreas Kramer |  | +49 (8382) 9699-246
*************************************************************************************************************************/
ALGO_INLINE EM_t_ARS_Kinematic  const * SLATE_p_GetEMARSObjKinematic(ObjNumber_t iObj)
{
  return &(SLATE_p_GetEMARSObj(iObj)->Kinematic);
}

/*************************************************************************************************************************
  Functionname:    SLATE_p_GetEMARSObjLegacy                                                                       */ /*!
  @brief           Returns EM_t_ARS_Legacy  const *
  @return          EM_t_ARS_Legacy  const *
  @param[in]       iObj : object index
  @author          Andreas Kramer |  | +49 (8382) 9699-246
*************************************************************************************************************************/
ALGO_INLINE EM_t_ARS_Legacy  const * SLATE_p_GetEMARSObjLegacy(ObjNumber_t iObj)
{
  return &(SLATE_p_GetEMARSObj(iObj)->Legacy);
}

/*************************************************************************************************************************
  Functionname:    SLATE_p_GetEMARSObjMotionAttributes                                                             */ /*!
  @brief           Returns EM_t_ARS_MotionAttributes  const *
  @return          EM_t_ARS_MotionAttributes  const *
  @param[in]       iObj : object index
  @author          Andreas Kramer |  | +49 (8382) 9699-246
*************************************************************************************************************************/
ALGO_INLINE EM_t_ARS_MotionAttributes  const * SLATE_p_GetEMARSObjMotionAttributes(ObjNumber_t iObj)
{
  return &(SLATE_p_GetEMARSObj(iObj)->MotionAttributes);
}

/*************************************************************************************************************************
  Functionname:    SLATE_p_GetEMARSObjSensorSpecific                                                               */ /*!
  @brief           Returns EM_t_ARS_SensorSpecific  const *
  @return          EM_t_ARS_SensorSpecific  const *
  @param[in]       iObj : object index
  @author          Andreas Kramer |  | +49 (8382) 9699-246
*************************************************************************************************************************/
ALGO_INLINE EM_t_ARS_SensorSpecific  const * SLATE_p_GetEMARSObjSensorSpecific(ObjNumber_t iObj)
{
  return &(SLATE_p_GetEMARSObj(iObj)->SensorSpecific);
}
#endif  /* END IF (FCT_USE_EM_ARS_TECH_OBJECT_LIST) */

#if (FCT_USE_EM_CAM_TECH_OBJECT_LIST)
/************************************************************************/
/* Camera object list                                                   */
/************************************************************************/
/*************************************************************************************************************************
  Functionname:    SLATE_p_GetEMCAMObjList                                                                         */ /*!
  @brief           Returns EM_t_CamObjectList const *
  @return          EM_t_CamObjectList const *
  @author          Andreas Kramer |  | +49 (8382) 9699-246
*************************************************************************************************************************/
ALGO_INLINE EM_t_CamObjectList const * SLATE_p_GetEMCAMObjList(void)
{
  return pSLATE_EmCamObjList;
}

/*************************************************************************************************************************
  Functionname:    SLATE_p_GetEMCAMObj                                                                             */ /*!
  @brief           Returns EM_t_CamObject const *
  @return          EM_t_CamObject const *
  @param[in]       iObj : object index
  @author          Andreas Kramer |  | +49 (8382) 9699-246
*************************************************************************************************************************/
ALGO_INLINE EM_t_CamObject const * SLATE_p_GetEMCAMObj(ObjNumber_t iObj)
{
  /* Perform range check before accessing an object */
  /* Suppress "Msg(3:3112) This statement has no side-effect - it can be removed"  */ /*PRQA S 3112 1*/
  SLATE_ASSERT((iObj >= 0) && (iObj < EM_N_OBJECTS));

  return &(SLATE_p_GetEMCAMObjList()->aObject[iObj]);
}
#endif  /* END IF (FCT_USE_EM_CAM_TECH_OBJECT_LIST) */

/************************************************************************/
/* EM Fusion Object List                                                */
/************************************************************************/
#if (FCT_CFG_INCLUDE_FUSION_OBJECT_LIST)
/*************************************************************************************************************************
  Functionname:    SLATE_pt_GetFusionObjList                                                                          */ /*!

  @brief           Inline function for accessing the pointer the Em fusion object list
  @return          Reference to the fusion object list
  @param[in]       -
  @c_switch_part   FCT_CFG_INCLUDE_FUSION_OBJECT_LIST
  @created         23.02.2018
  @author          Bharadwaj Gobichettipalayam Sankar| bharadwaj.gobichettipalayam.sankar@continental-corporation.com | +49 (8382) 9699-4977
*************************************************************************************************************************/
ALGO_INLINE EM_t_FusionObjectList const * SLATE_pt_GetFusionObjList(void)
{
  return pSLATE_FusionObjList;
}
#endif
/************************************************************************/
/* Public object list                                                   */
/************************************************************************/
#if (FCT_CFG_ASSESSED_OBJ_OUT_INTF)
/*************************************************************************************************************************
  Functionname:    SLATE_p_GetFCTPubObjList                                                                        */ /*!
  @brief           Returns AssessedObjList_t *
  @return          AssessedObjList_t *
  @author          Andreas Kramer |  | +49 (8382) 9699-246
*************************************************************************************************************************/
ALGO_INLINE AssessedObjList_t * SLATE_p_GetFCTPubObjList(void)
{
  return FCTSEN_pPubFctObjList;
}
/*************************************************************************************************************************
  Functionname:    SLATE_p_GetFCTPubObjListHeader                                                                  */ /*!
  @brief           Returns HeaderAssessedObjList_t *
  @return          HeaderAssessedObjList_t *
  @author          Andreas Kramer |  | +49 (8382) 9699-246
*************************************************************************************************************************/
ALGO_INLINE HeaderAssessedObjList_t * SLATE_p_GetFCTPubObjListHeader(void)
{
  return &(SLATE_p_GetFCTPubObjList()->HeaderAssessedObjList);
}
/*************************************************************************************************************************
  Functionname:    SLATE_p_GetFCTPubObj                                                                            */ /*!
  @brief           Returns FCTPubObject_t *
  @return          FCTPubObject_t *
  @param[in]       iObj : object index
  @author          Andreas Kramer |  | +49 (8382) 9699-246
*************************************************************************************************************************/
ALGO_INLINE FCTPubObject_t * SLATE_p_GetFCTPubObj(ObjNumber_t iObj)
{
  /* Perform range check before accessing an object */
  /* Suppress "Msg(3:3112) This statement has no side-effect - it can be removed"  */ /*PRQA S 3112 1*/
  SLATE_ASSERT((iObj >= 0) && (iObj < EM_N_OBJECTS));

  return &(SLATE_p_GetFCTPubObjList()->ObjList[iObj]);
}
/*************************************************************************************************************************
  Functionname:    SLATE_p_GetFCTPubObj_LaneInfo                                                                   */ /*!
  @brief           Returns LaneInformation_t *
  @return          LaneInformation_t *
  @param[in]       iObj : object index
  @author          Andreas Kramer |  | +49 (8382) 9699-246
*************************************************************************************************************************/
ALGO_INLINE LaneInformation_t * SLATE_p_GetFCTPubObj_LaneInfo(ObjNumber_t iObj)
{
  return &(SLATE_p_GetFCTPubObj(iObj)->LaneInformation);
}
/*************************************************************************************************************************
  Functionname:    SLATE_p_GetFCTPubObj_LegacyAOL                                                                  */ /*!
  @brief           Returns LegacyAOL_t *
  @return          LegacyAOL_t *
  @param[in]       iObj : object index
  @author          Andreas Kramer |  | +49 (8382) 9699-246
*************************************************************************************************************************/
ALGO_INLINE LegacyAOL_t * SLATE_p_GetFCTPubObj_LegacyAOL(ObjNumber_t iObj)
{
  return &(SLATE_p_GetFCTPubObj(iObj)->Legacy);
}
/*************************************************************************************************************************
  Functionname:    SLATE_p_GetFCTPubObj_OOI                                                                        */ /*!
  @brief           Returns ObjOfInterest_t  *
  @return          ObjOfInterest_t  *
  @param[in]       iObj : object index
  @author          Andreas Kramer |  | +49 (8382) 9699-246
*************************************************************************************************************************/
ALGO_INLINE ObjOfInterest_t  * SLATE_p_GetFCTPubObj_OOI(ObjNumber_t iObj)
{
  return &(SLATE_p_GetFCTPubObj(iObj)->ObjOfInterest);
}
/*************************************************************************************************************************
  Functionname:    SLATE_b_IsObjOOI                                                                                */ /*!
  @brief           Returns boolean const
  @return          boolean const
  @param[in]       iObj : object index
  @param[in]       eObjOOI : object index
  @author          Andreas Kramer |  | +49 (8382) 9699-246
*************************************************************************************************************************/
ALGO_INLINE boolean SLATE_b_IsObjOOI(ObjNumber_t iObj, eObjOOI_t eObjOOI)
{
  return (SLATE_p_GetFCTPubObj_OOI(iObj)->eObjOOI == eObjOOI) ? TRUE : FALSE;/* PRQA S 4434 */
/* date: 2019-07-01, reviewer: Karthik Chittepu, reason: Doesnot have any effect on functionality */
}
/*************************************************************************************************************************
  Functionname:    SLATE_b_IsObjRelevant                                                                           */ /*!
  @brief           Returns boolean const
  @return          boolean const
  @param[in]       iObj : object index
  @author          Andreas Kramer |  | +49 (8382) 9699-246
*************************************************************************************************************************/
ALGO_INLINE boolean SLATE_b_IsObjRelevant(ObjNumber_t iObj)
{
  return SLATE_b_IsObjOOI(iObj, OBJ_NEXT_OOI);
}

/*************************************************************************************************************************
  Functionname:    SLATE_i_GetOOIObjIndex                                                                          */ /*!
  @brief           Returns ObjNumber_t const
  @return          ObjNumber_t const
  @param[in]       eObjOOI : object index
  @author          Andreas Kramer |  | +49 (8382) 9699-246
*************************************************************************************************************************/
ALGO_INLINE ObjNumber_t SLATE_i_GetOOIObjIndex(eObjOOI_t eObjOOI)
{
  /* Suppress "Msg(3:3112) This statement has no side-effect - it can be removed"  */ /*PRQA S 3112 1*/
  SLATE_ASSERT((eObjOOI >= 0) && (eObjOOI < 6));
  return SLATE_p_GetFCTPubObjListHeader()->aiOOIList[eObjOOI];
}
/*************************************************************************************************************************
  Functionname:    SLATE_i_GetRelObjIndex                                                                          */ /*!
  @brief           Returns ObjNumber_t const
  @return          ObjNumber_t const
  @author          Andreas Kramer |  | +49 (8382) 9699-246
*************************************************************************************************************************/
ALGO_INLINE ObjNumber_t SLATE_i_GetRelObjIndex(void)
{
  return SLATE_i_GetOOIObjIndex(OBJ_NEXT_OOI);
}
#endif
/************************************************************************/
/* VDY signals                                                          */
/************************************************************************/
/*************************************************************************************************************************
  Functionname:    SLATE_f_GetEGORawYawRateQuality                                                                        */ /*!
  @brief           Returns Yaw Rate Quality
  @return          flaot32
  @author          Andreas Kramer |  | +49 (8382) 9699-246
*************************************************************************************************************************/
ALGO_INLINE float32 SLATE_f_GetEGORawYawRateQuality(void)
{
  float32 fEGOYawRateQ = 1.0f;
#if (VDY_VEH_DYN_INTFVER >= 0x20)   // 0x20 -> 18
  fEGOYawRateQ = 1.0f;  // TODO
#else
  fEGOYawRateQ = 1.0f;//GET_EGO_RAW_DATA_PTR->Lateral.YawRate.Quality;
#endif
  return fEGOYawRateQ;
}
/*************************************************************************************************************************
  Functionname:    SLATE_p_GetVDYDynObjSync                                                                        */ /*!
  @brief           Returns VehDyn_t const *
  @return          VehDyn_t const *
  @author          Andreas Kramer |  | +49 (8382) 9699-246
*************************************************************************************************************************/
ALGO_INLINE VehDyn_t const * SLATE_p_GetVDYDynObjSync(void)
{
  return pSLATE_EgoDynObjSync;
}

/*************************************************************************************************************************
  Functionname:    SLATE_f_GetEgoVelObjSync                                                                        */ /*!
  @brief           Returns float32
  @return          float32
  @author          Andreas Kramer |  | +49 (8382) 9699-246
*************************************************************************************************************************/
ALGO_INLINE float32 SLATE_f_GetEgoVelObjSync(void)
{
#if (VDY_VEH_DYN_INTFVER >= 0x20)   // 0x20 -> 18
  return SLATE_p_GetVDYDynObjSync()->Longitudinal.Velocity;
#else
  return SLATE_p_GetVDYDynObjSync()->Longitudinal.MotVar.Velocity;
#endif
}

/*************************************************************************************************************************
  Functionname:    SLATE_f_GetEgoAccelObjSync                                                                      */ /*!
  @brief           Returns float32
  @return          float32
  @author          Andreas Kramer |  | +49 (8382) 9699-246
*************************************************************************************************************************/
ALGO_INLINE float32 SLATE_f_GetEgoAccelObjSync(void)
{
  float32 fEgoAccelObj;
#if (VDY_VEH_DYN_INTFVER >= 0x20)   // 0x20 -> 18
  fEgoAccelObj = SLATE_p_GetVDYDynObjSync()->Longitudinal.Accel;
#else
  fEgoAccelObj = SLATE_p_GetVDYDynObjSync()->Longitudinal.MotVar.Accel;
#endif
  return fEgoAccelObj;
}

/*************************************************************************************************************************
  Functionname:    SLATE_f_GetEgoVelRaw                                                                            */ /*!
  @brief           Returns float32
  @return          float32
  @author          Andreas Kramer |  | +49 (8382) 9699-246
*************************************************************************************************************************/
ALGO_INLINE float32 SLATE_f_GetEgoVelRaw(void)
{
#if (VDY_VEH_DYN_INTFVER >= 0x20)   // 0x20 -> 18
  return SLATE_p_GetVDYDynRaw()->Longitudinal.Velocity;
#else
  return SLATE_p_GetVDYDynRaw()->Longitudinal.MotVar.Velocity;
#endif
}

/*************************************************************************************************************************
  Functionname:    SLATE_f_GetEgoAccelRaw                                                                          */ /*!
  @brief           Returns float32
  @return          float32
  @author          Andreas Kramer |  | +49 (8382) 9699-246
*************************************************************************************************************************/
ALGO_INLINE float32 SLATE_f_GetEgoAccelRaw(void)
{
#if (VDY_VEH_DYN_INTFVER >= 0x20)   // 0x20 -> 18
  return SLATE_p_GetVDYDynRaw()->Longitudinal.Accel;
#else
  return SLATE_p_GetVDYDynRaw()->Longitudinal.MotVar.Accel;
#endif
}

/*************************************************************************************************************************
  Functionname:    SLATE_f_GetEgoCorrectedAccel                                                                          */ /*!
  @brief           Returns float32
  @return          float32
  @author          Andreas Kramer |  | +49 (8382) 9699-246
*************************************************************************************************************************/
ALGO_INLINE float32 SLATE_f_GetEgoCorrectedAccel(void)
{
#if (VDY_VEH_DYN_INTFVER >= 0x20)   // 0x20 -> 18
  return SLATE_p_GetVDYDynObjSync()->Longitudinal.Accel;
#else
  return SLATE_p_GetVDYDynObjSync()->Longitudinal.AccelCorr.corrAccel;
#endif
}

/*************************************************************************************************************************
  Functionname:    SLATE_f_GetEgoCorrectedSTDAccel                                                                          */ /*!
  @brief           Returns float32
  @return          float32
  @author          Andreas Kramer |  | +49 (8382) 9699-246
*************************************************************************************************************************/
ALGO_INLINE float32 SLATE_f_GetEgoCorrectedSTDAccel(void)
{
#if (VDY_VEH_DYN_INTFVER >= 0x20)   // 0x20 -> 18
  return SQRT_(SLATE_p_GetVDYDynObjSync()->Longitudinal.varAccel);
#else
  return SQRT_(SLATE_p_GetVDYDynObjSync()->Longitudinal.AccelCorr.corrAccelVar);
#endif
}


/************************************************************************/
/* Vehicle parameter                                                    */
/************************************************************************/

/*************************************************************************************************************************
  Functionname:    SLATE_p_GetVehPar                                                                               */ /*!
  @brief           Returns VehPar_t const *
  @return          VehPar_t const *
  @author          Andreas Kramer |  | +49 (8382) 9699-246
*************************************************************************************************************************/
ALGO_INLINE VehPar_t const *  SLATE_p_GetVehPar(void)
{
  return pSLATE_EgoStaticData;
}

/*************************************************************************************************************************
  Functionname:    SLATE_p_GetSensorMounting                                                                       */ /*!
  @brief           Returns SensorMounting_t const *
  @return          SensorMounting_t const *
  @author          Andreas Kramer |  | +49 (8382) 9699-246
*************************************************************************************************************************/
ALGO_INLINE SensorMounting_t const *  SLATE_p_GetSensorMounting(void)
{
  return &(SLATE_p_GetVehPar()->SensorMounting);
}


/************************************************************************/
/* Misc                                                                 */
/************************************************************************/
#if (FCT_CFG_EM_FCT_CYCLEMODE)
/*************************************************************************************************************************
  Functionname:    SLATE_p_GetEmFctCycleMode                                                                       */ /*!
  @brief           Returns EmFctCycleMode_t  const *
  @return          EmFctCycleMode_t  const *
  @author          Andreas Kramer |  | +49 (8382) 9699-246
*************************************************************************************************************************/
ALGO_INLINE EmFctCycleMode_t  const *  SLATE_p_GetEmFctCycleMode(void)
{
  return pSLATE_EmFctCycleMode;
}
#endif
/*************************************************************************************************************************
  Functionname:    SLATE_f_GetCycleTime                                                                            */ /*!
  @brief           Returns float32
  @return          float32
  @author          Andreas Kramer |  | +49 (8382) 9699-246
*************************************************************************************************************************/
ALGO_INLINE float32 SLATE_f_GetCycleTime(void)
{
#if (FCT_CFG_EM_FCT_CYCLEMODE)
  return SLATE_p_GetEmFctCycleMode()->fEmFctCycleTime;
#else
  return TASK_CYCLE_TIME;
#endif
}
/*************************************************************************************************************************
  Functionname:    SLATE_f_GetSITCycleTime                                                                          */ /*!
  @brief           Returns float32
  @return          float32
  @author          Andreas Kramer |  | +49 (8382) 9699-246
*************************************************************************************************************************/
ALGO_INLINE float32 SLATE_f_GetSITCycleTime(void)
{
  return SLATE_f_GetCycleTime();
}
/*************************************************************************************************************************
  Functionname:    SLATE_f_GetSPMCycleTime                                                                         */ /*!
  @brief           Returns float32
  @return          float32
  @author          Andreas Kramer |  | +49 (8382) 9699-246
*************************************************************************************************************************/
ALGO_INLINE float32 SLATE_f_GetSPMCycleTime(void)
{
  return SLATE_f_GetCycleTime();
}
/*************************************************************************************************************************
  Functionname:    SLATE_f_GetCPCycleTime                                                                          */ /*!
  @brief           Returns float32
  @return          float32
  @author          Andreas Kramer |  | +49 (8382) 9699-246
*************************************************************************************************************************/
ALGO_INLINE float32 SLATE_f_GetCPCycleTime(void)
{
  return SLATE_f_GetCycleTime();
}

#if (FCT_CFG_ROAD_INPUT)
/*************************************************************************************************************************
  Functionname:    SLATE_p_GetRoad                                                                                 */ /*!
  @brief           Returns Road_t const *
  @return          Road_t const *
  @author          Andreas Kramer |  | +49 (8382) 9699-246
*************************************************************************************************************************/
ALGO_INLINE Road_t const *  SLATE_p_GetRoad(void)
{
  return pSLATE_RoadData;
}
#endif
#if (SLATE_CFG_USE_EM_MOVING_OBJECT_TRACES)
/*************************************************************************************************************************
  Functionname:    SLATE_p_GetObjTraces                                                                            */ /*!
  @brief           Returns MovingObjectTraces_t const *
  @return          MovingObjectTraces_t const *
  @author          Andreas Kramer |  | +49 (8382) 9699-246
*************************************************************************************************************************/
ALGO_INLINE MovingObjectTraces_t const *  SLATE_p_GetObjTraces(void)
{
  return pSLATE_MovObjTraces;
}

/*************************************************************************************************************************
  Functionname:    SLATE_p_GetObjTrace                                                                             */ /*!
  @brief           Returns ObjectTrace_t const *
  @return          ObjectTrace_t const *
  @param[in]       iTrace : object index
  @author          Andreas Kramer |  | +49 (8382) 9699-246
*************************************************************************************************************************/
ALGO_INLINE ObjectTrace_t const *  SLATE_p_GetObjTrace(sint32 iTrace)
{
  /* Check range */
  /* Suppress "Msg(3:3112) This statement has no side-effect - it can be removed"  */ /*PRQA S 3112 1*/
  SLATE_ASSERT((0 <= iTrace) && (iTrace < MAX_NUM_TRACES));

  return &(SLATE_p_GetObjTraces()->ObjectTrace[iTrace]);
}
#endif

#if (FCT_CFG_RSP_CONTEXT_INPUT)
/*************************************************************************************************************************
  Functionname:    SLATE_p_GetRSPContextData                                                                       */ /*!
  @brief           Returns RSPKontextData_t const *
  @return          RSPKontextData_t const *
  @author          Andreas Kramer |  | +49 (8382) 9699-246
*************************************************************************************************************************/
ALGO_INLINE RSPKontextData_t const *  SLATE_p_GetRSPContextData(void)
{
  return pSLATE_RSPContextData;
}
#endif

#if (FCT_CFG_ALIGNMENT_MONITORING_INPUT)
/*************************************************************************************************************************
  Functionname:    SLATE_p_GetAlnMonInput                                                                          */ /*!
  @brief           Returns ALN_S_Monitoring_t const *
  @return          ALN_S_Monitoring_t const *
  @author          Andreas Kramer |  | +49 (8382) 9699-246
*************************************************************************************************************************/
ALGO_INLINE ALN_S_Monitoring_t const *  SLATE_p_GetAlnMonInput(void)
{
  return pSLATE_AlignmentMonInput;
}
#endif

#if (FCT_CFG_SIGNAL_PERF_MONITORING)
/*************************************************************************************************************************
  Functionname:    SLATE_p_GetPerfDegr                                                                             */ /*!
  @brief           Returns PerfDegr_t   const *
  @return          PerfDegr_t   const *
  @author          Andreas Kramer |  | +49 (8382) 9699-246
*************************************************************************************************************************/
ALGO_INLINE PerfDegr_t   const *  SLATE_p_GetPerfDegr(void)
{
  return pSLATE_PerfDegrData;
}

/*************************************************************************************************************************
  Functionname:    SLATE_p_GetSPMStates                                                                            */ /*!
  @brief           Returns SysPerfMonStates_t *
  @return          SysPerfMonStates_t *
  @author          Andreas Kramer |  | +49 (8382) 9699-246
*************************************************************************************************************************/
ALGO_INLINE SysPerfMonStates_t *  SLATE_p_GetSPMStates(void)
{
  return FCTSEN_pSysPerfMonStates;
}
#endif
#if (FCT_CFG_RSP_OUTPUT_PD)
/*************************************************************************************************************************
  Functionname:    SLATE_p_GetRSPOutputPD                                                                          */ /*!
  @brief           Returns RSPOutputPD_t const *
  @return          RSPOutputPD_t const *
  @author          Andreas Kramer |  | +49 (8382) 9699-246
*************************************************************************************************************************/
ALGO_INLINE RSPOutputPD_t const *  SLATE_p_GetRSPOutputPD(void)
{
  return FCTSEN_pRSPOutputPD;
}
#endif


#if (FCT_CFG_CUSTOM_IO_INTERFACE)
/*************************************************************************************************************************
  Functionname:    SLATE_p_GetCustomInput                                                                          */ /*!
  @brief           Returns FCTCustomInput_t const *
  @return          FCTCustomInput_t const *
  @author          Andreas Kramer |  | +49 (8382) 9699-246
*************************************************************************************************************************/
ALGO_INLINE FCTCustomInput_t const *  SLATE_p_GetCustomInput(void)
{
  return pSLATE_CustomInput;
}

/*************************************************************************************************************************
  Functionname:    SLATE_p_GetCustomOutput                                                                         */ /*!
  @brief           Returns FCTCustomOutput_t *
  @return          FCTCustomOutput_t *
  @author          Andreas Kramer |  | +49 (8382) 9699-246
*************************************************************************************************************************/
ALGO_INLINE FCTCustomOutput_t *  SLATE_p_GetCustomOutput(void)
{
  return FCTSEN_pCustomOutput;
}
#endif

#if (FCT_CFG_COLLISION_DETECTION)
/*************************************************************************************************************************
  Functionname:    SLATE_p_GetHypothesisIntf                                                                       */ /*!
  @brief           Returns HypothesisIntf_t *
  @return          HypothesisIntf_t *
  @author          Andreas Kramer |  | +49 (8382) 9699-246
*************************************************************************************************************************/
ALGO_INLINE HypothesisIntf_t *  SLATE_p_GetHypothesisIntf(void)
{
  return FCT_pCDHypothesesSen;
}

/*************************************************************************************************************************
  Functionname:    SLATE_p_GetHypothesis                                                                           */ /*!
  @brief           Returns Hypothesis_t *
  @return          Hypothesis_t *
  @param[in]       iHyp : object index
  @author          Andreas Kramer |  | +49 (8382) 9699-246
*************************************************************************************************************************/
ALGO_INLINE Hypothesis_t *  SLATE_p_GetHypothesis(sint32 iHyp)
{
  /* Check range */
  /* Suppress "Msg(3:3112) This statement has no side-effect - it can be removed"  */ /*PRQA S 3112 1*/
  SLATE_ASSERT((0 <= iHyp) && (iHyp < MAX_NUM_OF_HYPS));

  return &(FCT_pCDHypothesesSen->Hypothesis[iHyp]);
}

/*************************************************************************************************************************
  Functionname:    SLATE_p_GetHypDegradation                                                                       */ /*!
  @brief           Returns HypoIntfDegr_t *
  @return          HypoIntfDegr_t *
  @author          Andreas Kramer |  | +49 (8382) 9699-246
*************************************************************************************************************************/
ALGO_INLINE HypoIntfDegr_t *  SLATE_p_GetHypDegradation(void)
{
  return &(SLATE_p_GetHypothesisIntf()->Degradation);
}
#endif

#if (FCT_CFG_BSW_ALGO_PARAMS)
/*************************************************************************************************************************
  Functionname:    SLATE_p_GetAlgoParameters                                                                       */ /*!
  @brief           Returns BSW_s_AlgoParameters_t const *
  @return          BSW_s_AlgoParameters_t const *
  @author          Andreas Kramer |  | +49 (8382) 9699-246
*************************************************************************************************************************/
ALGO_INLINE BSW_s_AlgoParameters_t const *  SLATE_p_GetAlgoParameters(void)
{
  return pSLATE_BswAlgoParameters;
}
#endif

/*************************************************************************************************************************
  Functionname:    SLATE_p_GetFCTSenFrame                                                                          */ /*!
  @brief           Returns FCTSenFrame_t *
  @return          FCTSenFrame_t *
  @author          Andreas Kramer |  | +49 (8382) 9699-246
*************************************************************************************************************************/
ALGO_INLINE FCTSenFrame_t *  SLATE_p_GetFCTSenFrame(void)
{
  return &FCTSenFrame;
}

/*************************************************************************************************************************
  Functionname:    SLATE_p_GetFCTSenSyncRef                                                                        */ /*!
  @brief           Returns SLATE_SyncRef_t *
  @return          SLATE_SyncRef_t *
  @author          Andreas Kramer |  | +49 (8382) 9699-246
*************************************************************************************************************************/
ALGO_INLINE FCTSen_SyncRef_t *  SLATE_p_GetFCTSenSyncRef(void)
{
  return &FCTSenSyncRef;
}

/*************************************************************************************************************************
  Functionname:    SLATE_p_GetFCTObjectToKeep                                                                      */ /*!
  @brief           Returns ObjNumber_t *
  @return          ObjNumber_t *
  @author          Harsha Umesh Babu | harsha.umesh.babu@continental-corporation.com | +49 (8382) 9699-246
*************************************************************************************************************************/
ALGO_INLINE ObjNumber_t *  SLATE_p_GetFCTObjectToKeep(ObjNumber_t iObj)
{
  return &(t_FCTSen_MDObjList[iObj].t_ObjectToKeep);
}





/*************************************************************************************************************************
  Functionname:    SLATE_pf_GetObjVabsY                                                                         */ /*!

  @brief           Inline function for accessing the pointer to absolute lateral velocity of object
  @return          Reference to absolute lateral velocity of object
  @param[in]       iObj : EM Object number [0 ... EM_N_OBJECTS)
  @c_switch_part   FCT_USE_EM_GENERIC_OBJECT_LIST
  @created         21.12.2016
  @author          Bharadwaj Gobichettipalayam Sankar| bharadwaj.gobichettipalayam.sankar@continental-corporation.com | +49 (8382) 9699-4977
*************************************************************************************************************************/
ALGO_INLINE float32 const * SLATE_pf_GetObjVabsY(ObjNumber_t iObj)
{
  float32 const* pf_VabsY;
  /* Perform range check before accessing an object */
  SLATE_ASSERT((iObj >= 0) && (iObj < EM_N_OBJECTS));

  pf_VabsY = (float32 const*)&(pSLATE_EmGenObjList->aObject[iObj].Kinematic.fVabsY);


  return pf_VabsY;
}

/*************************************************************************************************************************
  Functionname:    SLATE_pf_GetObjAabsY                                                                         */ /*!

  @brief           Inline function for accessing the pointer to absolute lateral velocity of object
  @return          Reference to absolute lateral velocity of object
  @param[in]       iObj : EM Object number [0 ... EM_N_OBJECTS)
  @c_switch_part   FCT_USE_EM_GENERIC_OBJECT_LIST
  @created         21.12.2016
  @author          Bharadwaj Gobichettipalayam Sankar| bharadwaj.gobichettipalayam.sankar@continental-corporation.com | +49 (8382) 9699-4977
*************************************************************************************************************************/
ALGO_INLINE float32 const * SLATE_pf_GetObjAabsY(ObjNumber_t iObj)
{
  float32 const* pf_AabsY;
  /* Perform range check before accessing an object */
  SLATE_ASSERT((iObj >= 0) && (iObj < EM_N_OBJECTS));

  pf_AabsY = (float32 const*)&(pSLATE_EmGenObjList->aObject[iObj].Kinematic.fAabsY);


  return pf_AabsY;
}

/*************************************************************************************************************************
  Functionname:    SLATE_pf_GetObjAabsX                                                                         */ /*!

  @brief           Inline function for accessing the pointer to absolute longitudinal acceleration of object
  @return          Reference to absolute lateral velocity of object
  @param[in]       iObj : EM Object number [0 ... EM_N_OBJECTS)
  @c_switch_part   FCT_USE_EM_GENERIC_OBJECT_LIST
  @created         21.12.2016
  @author          Bharadwaj Gobichettipalayam Sankar| bharadwaj.gobichettipalayam.sankar@continental-corporation.com | +49 (8382) 9699-4977
*************************************************************************************************************************/
ALGO_INLINE float32 const * SLATE_pf_GetObjAabsX(ObjNumber_t iObj)
{
  float32 const* pf_AabsX;
  /* Perform range check before accessing an object */
  SLATE_ASSERT((iObj >= 0) && (iObj < EM_N_OBJECTS));

  pf_AabsX = (float32 const*)&(pSLATE_EmGenObjList->aObject[iObj].Kinematic.fAabsX);


  return pf_AabsX;
}

/*************************************************************************************************************************
  Functionname:    SLATE_pc_GetObjExistProbability                                                                 */ /*!

  @brief           Inline function for accessing the pointer to probability of existence of object
  @return          Reference to probability of existence of object
  @param[in]       iObj : EM Object number [0 ... EM_N_OBJECTS)
  @c_switch_part   FCT_USE_EM_GENERIC_OBJECT_LIST
  @created         09.12.2016
  @author          Niraj Mistry | niraj.mistry@continental-corporation.com | +49 (8382) 9699-5631
*************************************************************************************************************************/
ALGO_INLINE uint8 const * SLATE_pu_GetObjExistProbability(ObjNumber_t iObj)
{
  uint8 const* pu_ObjExistProb;
  /* Perform range check before accessing an object */
  SLATE_ASSERT((iObj >= 0) && (iObj < EM_N_OBJECTS));


  pu_ObjExistProb = (uint8 const*) &(pSLATE_EmGenObjList->aObject[iObj].Qualifiers.uiProbabilityOfExistence);

  return pu_ObjExistProb;
}

/*************************************************************************************************************************
  Functionname:    SLATE_pf_GetObjArelY                                                                            */ /*!

  @brief           Inline function for accessing the pointer to relative lateral acceleration of object
  @return          Reference to relative lateral acceleration of object
  @param[in]       iObj : EM Object number [0 ... EM_N_OBJECTS)
  @c_switch_part   FCT_USE_EM_GENERIC_OBJECT_LIST
  @created         21.12.2016
  @author          Bharadwaj Gobichettipalayam Sankar| bharadwaj.gobichettipalayam.sankar@continental-corporation.com | +49 (8382) 9699-4977
*************************************************************************************************************************/
ALGO_INLINE float32 const * SLATE_pf_GetObjArelY(ObjNumber_t iObj)
{
  float32 const* pf_ArelY;
  /* Perform range check before accessing an object */
  SLATE_ASSERT((iObj >= 0) && (iObj < EM_N_OBJECTS));

  pf_ArelY = (float32 const*)&(pSLATE_EmGenObjList->aObject[iObj].Kinematic.fArelY);

  return pf_ArelY;
}

/*************************************************************************************************************************
  Functionname:    SLATE_pf_GetObjLifeCycles                                                                       */ /*!

  @brief           Inline function for accessing the pointer to life cycles of object
  @return          Reference to number of life cycles of object
  @param[in]       iObj : EM Object number [0 ... EM_N_OBJECTS)
  @c_switch_part   FCT_USE_EM_GENERIC_OBJECT_LIST
  @created         15.12.2016
  @author          Niraj Mistry | niraj.mistry@continental-corporation.com | +49 (8382) 9699-5631
*************************************************************************************************************************/
ALGO_INLINE uint16 const * SLATE_pu_GetObjLifeCycles(ObjNumber_t iObj)
{
  uint16 const* pu_Lifecycles;
  /* Perform range check before accessing an object */
  SLATE_ASSERT((iObj >= 0) && (iObj < EM_N_OBJECTS));

  pu_Lifecycles = (uint16 const*)&(pSLATE_EmGenObjList->aObject[iObj].General.uiLifeCycles);

  return pu_Lifecycles;
}

/*************************************************************************************************************************
  Functionname:    SLATE_b_GetObjIsNew                                                                            */ /*!

  @brief           Inline function for accessing the boolean if object is new
  @return          Boolean if object is new
  @param[in]       iObj : EM Object number [0 ... EM_N_OBJECTS)
  @c_switch_part   FCT_USE_EM_GENERIC_OBJECT_LIST
  @created         15.12.2016
  @author          Niraj Mistry | niraj.mistry@continental-corporation.com | +49 (8382) 9699-5631
*************************************************************************************************************************/
ALGO_INLINE boolean SLATE_b_GetObjIsNew(ObjNumber_t iObj)
{
  boolean b_ObjIsNew;
  /* Perform range check before accessing an object */
  SLATE_ASSERT((iObj >= 0) && (iObj < EM_N_OBJECTS));

  b_ObjIsNew = (boolean)(pSLATE_EmGenObjList->aObject[iObj].General.eMaintenanceState == EM_GEN_OBJECT_MT_STATE_NEW);

  return b_ObjIsNew;
}

/*************************************************************************************************************************
  Functionname:    SLATE_b_GetObjIsDeleted                                                                         */ /*!

  @brief           Inline function for accessing the boolean if object is deleted
  @return          Boolean if object is deleted
  @param[in]       iObj : EM Object number [0 ... EM_N_OBJECTS)
  @c_switch_part   FCT_USE_EM_GENERIC_OBJECT_LIST
  @created         15.12.2016
  @author          Niraj Mistry | niraj.mistry@continental-corporation.com | +49 (8382) 9699-5631
*************************************************************************************************************************/
ALGO_INLINE boolean SLATE_b_GetObjIsDeleted(ObjNumber_t iObj)
{
  boolean b_ObjIsDel;
  /* Perform range check before accessing an object */
  SLATE_ASSERT((iObj >= 0) && (iObj < EM_N_OBJECTS));

  b_ObjIsDel = (boolean)(pSLATE_EmGenObjList->aObject[iObj].General.eMaintenanceState == EM_GEN_OBJECT_MT_STATE_DELETED);

  return b_ObjIsDel;
}

/*************************************************************************************************************************
  Functionname:    SLATE_pf_GetObjVrelYStd                                                                         */ /*!

  @brief           Inline function for accessing the pointer to standard deviation of relative lateral velocity of object
  @return          Reference to standard deviation of relative lateral velocity of object
  @param[in]       iObj : EM Object number [0 ... EM_N_OBJECTS)
  @c_switch_part   FCT_USE_EM_GENERIC_OBJECT_LIST
  @created         15.12.2016
  @author          Niraj Mistry | niraj.mistry@continental-corporation.com | +49 (8382) 9699-5631
*************************************************************************************************************************/
ALGO_INLINE float32 const * SLATE_pf_GetObjVrelYStd(ObjNumber_t iObj)
{
  float32 const* pf_VrelYStd;
  /* Perform range check before accessing an object */
  SLATE_ASSERT((iObj >= 0) && (iObj < EM_N_OBJECTS));

  pf_VrelYStd = (float32 const*)&(pSLATE_EmGenObjList->aObject[iObj].Kinematic.fVrelYStd);

  return pf_VrelYStd;
}

/*************************************************************************************************************************
  Functionname:    SLATE_pu_GetDistXSortedObj                                                                      */ /*!

  @brief           Inline function for accessing the distance sorted object list
  @return          Reference to the distance sorted object list
  @param[in]       iObj : EM Object number [0 ... EM_N_OBJECTS)
  @c_switch_part   FCT_USE_EM_GENERIC_OBJECT_LIST
  @created         15.12.2016
  @author          Niraj Mistry | niraj.mistry@continental-corporation.com | +49 (8382) 9699-5631
*************************************************************************************************************************/
ALGO_INLINE ObjNumber_t const * SLATE_pu_GetDistXSortedObj(ObjNumber_t iObj)
{
  const ObjNumber_t * pu_SortedObjList;
  /* Perform range check before accessing an object */
  SLATE_ASSERT((iObj >= 0) && (iObj < EM_N_OBJECTS));

  pu_SortedObjList = &(pSLATE_EmGenObjList->HeaderObjList.iSortedObjectList[iObj]);

  return pu_SortedObjList;
}

/*************************************************************************************************************************
  Functionname:    SLATE_pf_GetEgoLongVel                                                                          */ /*!

  @brief           Inline function for accessing the pointer to ego longitudinal velocity
  @return          Reference to ego longitudinal velocity
  @param[in]       -
  @created         09.12.2016
  @author          Niraj Mistry | niraj.mistry@continental-corporation.com | +49 (8382) 9699-5631
*************************************************************************************************************************/
ALGO_INLINE float32 const * SLATE_pf_GetEgoLongVel(void)
{
   const float32* pf_EgoLongVel;

#if (VDY_VEH_DYN_INTFVER >= 0x20)   // 0x20 -> 18
   pf_EgoLongVel = (const float32 *)&(pSLATE_EgoDynObjSync->Longitudinal.Velocity);
#else
   pf_EgoLongVel = (const float32 *)&(pSLATE_EgoDynObjSync->Longitudinal.MotVar.Velocity);
#endif
   return pf_EgoLongVel;
}

/*************************************************************************************************************************
  Functionname:    SLATE_pf_GetEgoLongAccel                                                                        */ /*!

  @brief           Inline function for accessing the pointer to ego longitudinal acceleration
  @return          Reference to ego longitudinal acceleration
  @param[in]       -
  @created         09.12.2016
  @author          Niraj Mistry | niraj.mistry@continental-corporation.com | +49 (8382) 9699-5631
*************************************************************************************************************************/
ALGO_INLINE float32 const * SLATE_pf_GetEgoLongAccel(void)
{
   const float32* pf_EgoLongAccel;

#if (VDY_VEH_DYN_INTFVER >= 0x20)   // 0x20 -> 18
  pf_EgoLongAccel = (const float32 *) &(pSLATE_EgoDynObjSync->Longitudinal.Accel);
#else
   pf_EgoLongAccel = (const float32 *) &(pSLATE_EgoDynObjSync->Longitudinal.MotVar.Accel);
#endif

   return pf_EgoLongAccel;
}

/*************************************************************************************************************************
  Functionname:    SLATE_pf_GetEgoSideSlip                                                                         */ /*!

  @brief           Inline function for accessing the pointer to ego side slip angle
  @return          Reference to ego side slip angle
  @param[in]       -
  @created         09.12.2016
  @author          Niraj Mistry | niraj.mistry@continental-corporation.com | +49 (8382) 9699-5631
*************************************************************************************************************************/
ALGO_INLINE float32 const * SLATE_pf_GetEgoSideSlip(void)
{
  return (float32 const*) &(pSLATE_EgoDynObjSync->Lateral.SlipAngle.SideSlipAngle);
}

/*************************************************************************************************************************
  Functionname:    SLATE_pf_GetEgoSideSlipVar                                                                      */ /*!

  @brief           Inline function for accessing the pointer to ego side slip angle variance
  @return          Reference to ego side slip angle variance
  @param[in]       -
  @created         09.12.2016
  @author          Niraj Mistry | niraj.mistry@continental-corporation.com | +49 (8382) 9699-5631
*************************************************************************************************************************/
ALGO_INLINE float32 const * SLATE_pf_GetEgoSideSlipVar(void)
{
  return (float32 const*) &(pSLATE_EgoDynObjSync->Lateral.SlipAngle.Variance);
}

/*************************************************************************************************************************
  Functionname:    SLATE_pf_GetEgoCurve                                                                            */ /*!

  @brief           Inline function for accessing the pointer to ego path curvature
  @return          Reference to ego path curvature
  @param[in]       -
  @created         09.12.2016
  @author          Niraj Mistry | niraj.mistry@continental-corporation.com | +49 (8382) 9699-5631
*************************************************************************************************************************/
ALGO_INLINE float32 const * SLATE_pf_GetEgoCurve(void)
{
  return (float32 const*) &(pSLATE_EgoDynObjSync->Lateral.Curve.Curve);
}

/*************************************************************************************************************************
  Functionname:    SLATE_pf_GetEgoCurveRaw                                                                            */ /*!

  @brief           Inline function for accessing the pointer to raw ego path curvature
  @return          Reference to raw ego path curvature
  @param[in]       -
  @created         17.03.2017
  @author          Bharadwaj Gobichettipalayam Sankar | bharadwaj.gobichettipalayam.sankar@continental-corporation.com | +49 (8382) 9699-4977
*************************************************************************************************************************/
ALGO_INLINE float32 const * SLATE_pf_GetEgoCurveRaw(void)
{
  return (float32 const*) &(pSLATE_EgoDynRaw->Lateral.Curve.Curve);
}

/*************************************************************************************************************************
  Functionname:    SLATE_pf_GetEgoCurveGrad                                                                        */ /*!

  @brief           Inline function for accessing the pointer to ego path curvature gradient
  @return          Reference to ego path curvature gradient
  @param[in]       -
  @created         09.12.2016
  @author          Niraj Mistry | niraj.mistry@continental-corporation.com | +49 (8382) 9699-5631
*************************************************************************************************************************/
ALGO_INLINE float32 const * SLATE_pf_GetEgoCurveGrad(void)
{
  const float32* pf_EgoCurveGrad;

#if (VDY_VEH_DYN_INTFVER >= 0x20)   // 0x20 -> 18
  pf_EgoCurveGrad = (const float32 *)&(pSLATE_EgoDynObjSync->Lateral.DrvIntCurve.Gradient);
#else
  pf_EgoCurveGrad = (const float32 *)&(pSLATE_EgoDynObjSync->Lateral.Curve.Gradient);
#endif

  return pf_EgoCurveGrad;
}

/*************************************************************************************************************************
  Functionname:    SLATE_pf_GetEgoCurveVar                                                                         */ /*!

  @brief           Inline function for accessing the pointer to ego path curvature variance
  @return          Reference to ego path curvature variance 
  @param[in]       -
  @created         09.12.2016
  @author          Niraj Mistry | niraj.mistry@continental-corporation.com | +49 (8382) 9699-5631
*************************************************************************************************************************/
ALGO_INLINE float32 const * SLATE_pf_GetEgoCurveVar(void)
{
  const float32* pf_EgoCurveVar;

#if (VDY_VEH_DYN_INTFVER >= 0x20)   // 0x20 -> 18
  pf_EgoCurveVar = (const float32 *)&(pSLATE_EgoDynObjSync->Lateral.Curve.VarCurve);
#else
  pf_EgoCurveVar = (const float32 *)&(pSLATE_EgoDynObjSync->Lateral.Curve.varC0);
#endif

  return pf_EgoCurveVar;
}

/*************************************************************************************************************************
  Functionname:    SLATE_pf_GetEgoDrvIntCurve                                                                      */ /*!

  @brief           Inline function for accessing the pointer to ego drive into curve curvature
  @return          Reference to ego drive into curve curvature
  @param[in]       -
  @created         09.12.2016
  @author          Niraj Mistry | niraj.mistry@continental-corporation.com | +49 (8382) 9699-5631
*************************************************************************************************************************/
ALGO_INLINE float32 const * SLATE_pf_GetEgoDrvIntCurve(void)
{
  return (const float32 *) &(pSLATE_EgoDynObjSync->Lateral.DrvIntCurve.Curve);
}

/*************************************************************************************************************************
  Functionname:    SLATE_pf_GetEgoDrvIntCurveVar                                                                   */ /*!

  @brief           Inline function for accessing the pointer to ego drive into curve curvature
  @return          Reference to ego drive into curve curvature
  @param[in]       -
  @created         09.12.2016
  @author          Niraj Mistry | niraj.mistry@continental-corporation.com | +49 (8382) 9699-5631
*************************************************************************************************************************/
ALGO_INLINE float32 const * SLATE_pf_GetEgoDrvIntCurveVar(void)
{
  return (const float32 *) &(pSLATE_EgoDynObjSync->Lateral.DrvIntCurve.Variance);
}

/*************************************************************************************************************************
  Functionname:    SLATE_f_GetEgoYawRateObjSync                                                                   */ /*!

  @brief           Inline function for accessing the ego yaw rate
  @return          Reference to ego yaw rate
  @param[in]       -
  @created         09.12.2016
  @author          Niraj Mistry | niraj.mistry@continental-corporation.com | +49 (8382) 9699-5631
*************************************************************************************************************************/
ALGO_INLINE float32 SLATE_f_GetEgoYawRateObjSync(void)
{
  return pSLATE_EgoDynObjSync->Lateral.YawRate.YawRate;
}

/*************************************************************************************************************************
  Functionname:    SLATE_f_GetEgoYawRateVarObjSync                                                                   */ /*!

  @brief           Inline function for accessing the ego yaw rate
  @return          Reference to ego yaw rate
  @param[in]       -
  @created         09.12.2016
  @author          Niraj Mistry | niraj.mistry@continental-corporation.com | +49 (8382) 9699-5631
*************************************************************************************************************************/
ALGO_INLINE float32 SLATE_f_GetEgoYawRateVarObjSync(void)
{
  return pSLATE_EgoDynObjSync->Lateral.YawRate.Variance;
}

/*************************************************************************************************************************
  Functionname:    SLATE_f_GetEgoYawRateMaxJitterSync                                                                   */ /*!

  @brief           Inline function for accessing the ego yaw rate maximum jitter
  @return          Reference to ego yaw rate jitter
  @param[in]       -
  @created         09.12.2016
  @author          Niraj Mistry | niraj.mistry@continental-corporation.com | +49 (8382) 9699-5631
*************************************************************************************************************************/
ALGO_INLINE float32 SLATE_f_GetEgoYawRateMaxJitterSync(void)
{
  float32 fYRMaxJitter;
#if (VDY_VEH_DYN_INTFVER >= 0x20)   // 0x20 -> 18
  fYRMaxJitter = 0.f; /* Temporary workaround as interface has been removed */
#else
  fYRMaxJitter = pSLATE_EgoDynObjSync->Legacy.YawRateMaxJitter;              //
#endif
  return fYRMaxJitter;
}


/*************************************************************************************************************************
  Functionname:    SLATE_pt_GetObjLifeTime                                                                      */ /*!

  @brief           Inline function for accessing the pointer to life time of object
  @return          Reference to life time of object
  @param[in]       iObj : EM Object number [0 ... EM_N_OBJECTS)
  @c_switch_full   FCT_USE_EM_GENERIC_OBJECT_LIST
  @created         21.12.2016
  @author          Bharadwaj Gobichettipalayam Sankar| bharadwaj.gobichettipalayam.sankar@continental-corporation.com | +49 (8382) 9699-4977
*************************************************************************************************************************/
ALGO_INLINE float32 const * SLATE_pt_GetObjLifeTime(ObjNumber_t iObj)
{
  /* Perform range check before accessing an object */
  SLATE_ASSERT((iObj >= 0) && (iObj < EM_N_OBJECTS));

  return &(pSLATE_EmGenObjList->aObject[iObj].General.fLifeTime);
}

/*************************************************************************************************************************
  Functionname:    SLATE_pt_GetObjLifeCycles                                                                      */ /*!

  @brief           Inline function for accessing the pointer to life cycles of object
  @return          Reference to life cycles of object
  @param[in]       iObj : EM Object number [0 ... EM_N_OBJECTS)
  @c_switch_full   FCT_USE_EM_GENERIC_OBJECT_LIST
  @created         21.12.2016
  @author          Bharadwaj Gobichettipalayam Sankar| bharadwaj.gobichettipalayam.sankar@continental-corporation.com | +49 (8382) 9699-4977
*************************************************************************************************************************/
ALGO_INLINE AlgoCycleCounter_t const * SLATE_pt_GetObjLifeCycles(ObjNumber_t iObj)
{
  /* Perform range check before accessing an object */
  SLATE_ASSERT((iObj >= 0) && (iObj < EM_N_OBJECTS));

  return &(pSLATE_EmGenObjList->aObject[iObj].General.uiLifeCycles);
}

/*************************************************************************************************************************
  Functionname:    SLATE_pt_GetObjMaintenanceState                                                                      */ /*!

  @brief           Inline function for accessing the pointer to maintenance state of object
  @return          Reference to maintenance state of object
  @param[in]       iObj : EM Object number [0 ... EM_N_OBJECTS)
  @c_switch_full   FCT_USE_EM_GENERIC_OBJECT_LIST
  @created         21.12.2016
  @author          Bharadwaj Gobichettipalayam Sankar| bharadwaj.gobichettipalayam.sankar@continental-corporation.com | +49 (8382) 9699-4977
*************************************************************************************************************************/
ALGO_INLINE EM_t_GenObjMaintenanceState const * SLATE_pt_GetObjMaintenanceState(ObjNumber_t iObj)
{
  /* Perform range check before accessing an object */
  SLATE_ASSERT((iObj >= 0) && (iObj < EM_N_OBJECTS));

  return &(pSLATE_EmGenObjList->aObject[iObj].General.eMaintenanceState);
}
#if (FCT_CFG_EMERGENCY_BRAKE_ASSIST)
/*************************************************************************************************************************
  Functionname:    SLATE_pt_GetEbaObjClass                                                                          */ /*!

  @brief           Inline function for accessing the pointer to EBA object class of object
  @return          Reference to EBA object class of object
  @param[in]       iObj : EM Object number [0 ... EM_N_OBJECTS)
  @c_switch_full   FCT_USE_EM_GENERIC_OBJECT_LIST
  @created         1/24/2018
  @author          Jason Ye | jason.ye@continental-corporation.com | +1 (248) 393-4561
*************************************************************************************************************************/
ALGO_INLINE EM_t_GenEbaObjClass const * SLATE_pt_GetEbaObjClass(ObjNumber_t iObj)
{
  /* Perform range check before accessing an object */
  SLATE_ASSERT((iObj >= 0) && (iObj < EM_N_OBJECTS));
  return &(pSLATE_EmGenObjList->aObject[iObj].Qualifiers.eEbaObjClass);
}
#endif /* END IF (FCT_CFG_EMERGENCY_BRAKE_ASSIST) */


#if (FCT_USE_EM_CUSTOM_OBJECT_LIST)

/*************************************************************************************************************************
  Functionname:    SLATE_p_GetEMCustObjData                                                                         */ /*!

  @brief           Inline function for accessing the pointer to EM custom object
  @return          Reference to EM custom object
  @param[in]       iObj : EM Object number [0 ... EM_N_OBJECTS)
  @c_switch_full   FCT_USE_EM_CUSTOM_OBJECT_LIST
  @created         1/24/2018
  @author          Jason Ye | jason.ye@continental-corporation.com | +1 (248) 393-4561
*************************************************************************************************************************/
ALGO_INLINE EM_t_Cust_ObjectData const * SLATE_p_GetEMCustObjData(ObjNumber_t iObj)
{
  /* Perform range check before accessing an object */
  SLATE_ASSERT((iObj >= 0) && (iObj < EM_N_OBJECTS));
  return &(pSLATE_EmCustObjList->CustObjects[iObj]);
}

#endif /* (FCT_USE_EM_CUSTOM_OBJECT_LIST) */

#if (SLATE_CFG_CAM_LANE_INTERFACE)
/*************************************************************************************************************************
  Functionname:    SLATE_pt_GetCamLaneData                                                                         */ /*!

  @brief           Inline function for accessing the pointer to camera lane input data
  @return          Reference to camera lane input data
  @param[in]       -
  @c_switch_full   SLATE_CFG_CAM_LANE_INTERFACE
  @created         09.12.2016
  @author          Niraj Mistry | niraj.mistry@continental-corporation.com | +49 (8382) 9699-5631
*************************************************************************************************************************/
ALGO_INLINE t_CamLaneInputData const * SLATE_pt_GetCamLaneData(void)
{
  return pSLATE_CamLaneData;
}
#endif /* End if (SLATE_CFG_CAM_LANE_INTERFACE) */

/*************************************************************************************************************************
  Functionname:    SLATE_pf_GetSensorYPos                                                                          */ /*!

  @brief           Inline function for accessing the pointer to lateral position of sensor mounting
  @return          Reference to lateral position of sensor mounting
  @param[in]       -
  @created         09.12.2016
  @author          Niraj Mistry | niraj.mistry@continental-corporation.com | +49 (8382) 9699-5631
*************************************************************************************************************************/
ALGO_INLINE float32 const * SLATE_pf_GetSensorYPos(void)
{
  return (float32 const*) &(pSLATE_EgoStaticData->SensorMounting.LatPos);
}

/*************************************************************************************************************************
  Functionname:    SLATE_pf_GetBumperToCoG                                                                         */ /*!

  @brief           Inline function for accessing the pointer to sensor position relative to CoG
  @return          Reference to to sensor position relative to CoG
  @param[in]       -
  @created         09.12.2016
  @author          Niraj Mistry | niraj.mistry@continental-corporation.com | +49 (8382) 9699-5631
*************************************************************************************************************************/
ALGO_INLINE float32 const * SLATE_pf_GetBumperToCoG(void)
{
  return &(FCT_fBumperToCoG);
}


#if (FCT_USE_EM_ARS_TECH_OBJECT_LIST)
/*************************************************************************************************************************
  Functionname:    SLATE_u_GetStoppedConfidence                                                                   */ /*!

  @brief           Inline function for object's stopped confidence
  @return          Reference to object classification
  @param[in]       -
  @c_switch_full   FCT_USE_EM_ARS_TECH_OBJECT_LIST
  @created         14.12.2016
  @author          Niraj Mistry | niraj.mistry@continental-corporation.com | +49 (8382) 9699-5631
*************************************************************************************************************************/
ALGO_INLINE uint8 SLATE_u_GetStoppedConfidence(ObjNumber_t iObj)
{
  /* Perform range check before accessing an object */
  SLATE_ASSERT((iObj >= 0) && (iObj < EM_N_OBJECTS));
  return pSLATE_EmARSObjList->aObject[iObj].MotionAttributes.uiStoppedConfidence;
}
#endif

/*************************************************************************************************************************
  Functionname:    SLATE_f_GetObjOrientationStd                                                                      */ /*!

  @brief           Inline function for accessing the pointer to object orientation std
  @return          Reference to object orientation std
  @param[in]       -
  @c_switch_part   FCT_USE_EM_ARS_TECH_OBJECT_LIST
  @created         17.03.2017
  @author          Bharadwaj Gobichettipalayam Sankar| bharadwaj.gobichettipalayam.sankar@continental-corporation.com | +49 (8382) 9699-4977
*************************************************************************************************************************/
ALGO_INLINE float32 SLATE_f_GetObjOrientationStd(ObjNumber_t iObj)
{
  float32 f_OrientationStd;
  SLATE_ASSERT((iObj >= 0) && (iObj < EM_N_OBJECTS));
#if (FCT_USE_EM_ARS_TECH_OBJECT_LIST)
  /* Perform range check before accessing an object */
  f_OrientationStd = (pSLATE_EmARSObjList->aObject[iObj].Geometry.fOrientationStd);
#else
  f_OrientationStd = 0.F; /* VACC is not available, should be computed from shape points as done in ACDC */
  _PARAM_UNUSED(iObj);
#endif /* END IF FCT_USE_EM_ARS_TECH_OBJECT_LIST */
  return f_OrientationStd;
}

#if (FCT_CFG_CUSTOM_IO_INTERFACE)
/*************************************************************************************************************************
  Functionname:    SLATE_pt_GetTurnIndicator                                                                       */ /*!

  @brief           Inline function for accessing the turn indicator input
  @return          Reference to turn indicator input
  @param[in]       -
  @c_switch_part   FCT_CFG_CUSTOM_IO_INTERFACE
  @created         15.12.2016
  @author          Niraj Mistry | niraj.mistry@continental-corporation.com | +49 (8382) 9699-5631
*************************************************************************************************************************/
ALGO_INLINE eTurnIndicator_t const * SLATE_pt_GetTurnIndicator(void)
{
  return &(pSLATE_CustomInput->eTurnIndicator);
}
#endif /* ENDIF (FCT_CFG_CUSTOM_IO_INTERFACE) */

#if (SLATE_CFG_USE_EXT_OBJ_ID)
/*************************************************************************************************************************
  Functionname:    SLATE_pt_GetExtObjID                                                                       */ /*!

  @brief           Inline function for accessing the external ID of the object of interest
  @return          Reference to external ID of OOI
  @param[in]       -
  @c_switch_part   SLATE_CFG_USE_EXT_OBJ_ID
  @created         21.12.2016
  @author          Bharadwaj Gobichettipalayam Sankar| bharadwaj.gobichettipalayam.sankar@continental-corporation.com | +49 (8382) 9699-4977
*************************************************************************************************************************/
ALGO_INLINE unsigned char const * SLATE_pt_GetExtObjID(ObjNumber_t iObj)
{
  /* Perform range check before accessing an object */
  SLATE_ASSERT((iObj >= 0) && (iObj < EM_N_OBJECTS));

  return &(FCTSEN_pPubFctObjList->ObjList[iObj].ObjOfInterest.cExternalID);
}
#endif /* ENDIF (SLATE_CFG_USE_EXT_OBJ_ID) */

/*************************************************************************************************************************
  Functionname:    SLATE_pf_GetObjDistYStd                                                                          */ /*!

  @brief           Inline function for accessing the pointer to std deviation of lateral dispalcement
  @return          Reference to std deviation of lateral dispalcement
  @param[in]       iObj : EM Object number [0 ... EM_N_OBJECTS)
  @c_switch_part   FCT_USE_EM_GENERIC_OBJECT_LIST
  @created         21.12.2016
  @author          Bharadwaj Gobichettipalayam Sankar| bharadwaj.gobichettipalayam.sankar@continental-corporation.com | +49 (8382) 9699-4977
*************************************************************************************************************************/
ALGO_INLINE float32 const * SLATE_pf_GetObjDistYStd(ObjNumber_t iObj)
{
  float32 const* pf_DistYStd;
  /* Perform range check before accessing an object */
  SLATE_ASSERT((iObj >= 0) && (iObj < EM_N_OBJECTS));

  pf_DistYStd = (float32 const*)&(pSLATE_EmGenObjList->aObject[iObj].Kinematic.fDistYStd);

  return pf_DistYStd;
}

#if ((FCT_CFG_ACT_CODE_VERSION) && (FCT_CFG_LOHP_COMPONENT))
/*************************************************************************************************************************
  Functionname:    SLATE_pt_GetDrivemode                                                                       */ /*!
  @brief           Inline function for accessing the pointer to drivemode input
  @return          Reference to drivemode input
  @param[in]       -
  @c_switch_full   FCT_CFG_ACT_CODE_VERSION - Configuration switch for enabling revised ACT Code
                   FCT_CFG_LOHP_COMPONENT - Configuration switch for enabling LOHP Code
  @created         19.11.2018
  @author          Midhun Daniel | midhun.daniel@continental-corporation.com
*************************************************************************************************************************/
ALGO_INLINE DriveMode_t_e const * SLATE_pt_GetDrivemode(void)
{
  return &(pSLATE_LongCtrlResp->KinCtrlDynInput.eDriveMode);
}
#endif /*(FCT_CFG_ACT_CODE_VERSION) && (FCT_CFG_LOHP_COMPONENT) */
/// @}
#endif /* IFNDEF SLATE_ACCESS_FUNC_H_INCLUDED */
#endif
/* PRQA L:ALGO_INLINES */
