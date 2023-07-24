/*! \file **********************************************************************

COMPANY:                   COPYRIGHT (C) Continental AG

PROJECT:                   Mainstream

CPU:                       CPU-Independent

COMPONENT:                 FCT Sen

MODULNAME:                 fct_sen_access_func.h

DESCRIPTION:               Definitions of inline functions to access global data

AUTHOR:                    Gergely Ungvary

CREATION DATE:             28.10.2015

VERSION:                   $Revision: 1.18 $

LEGACY VERSION:            Revision: 1.11

*****************************************************************************/

/*****************************************************************************
  MACROS 
*****************************************************************************/

#ifndef FCT_SEN_ACCESS_H_INCLUDED
#define FCT_SEN_ACCESS_H_INCLUDED


/************************************************************************/
/*                          INCLUDES                                    */
/************************************************************************/
#include "fct_par.h"
#include "fct_sen_ext.h"


/*****************************************************************************
  GLOBAL VARIABLES
*****************************************************************************/
/*! sub-module state */
#if (FCT_CFG_USE_SERVICE_POINTER_FUNCTS)
extern MEMSEC_REF const AS_t_ServiceFuncts     * pFCTSenServiceFuncts;
#endif
#if (FCT_CFG_USE_BASECTRLDATA)
extern MEMSEC_REF const BaseCtrlData_t         * FCTSEN_pSenCtrlData; /*!< Pointer to FCT control data */
#else
extern MEMSEC_REF const FCTCtrlData_t          * FCTSEN_pSenCtrlData; /*!< Pointer to FCT control data */
#endif
#if (FCT_CFG_EM_FCT_CYCLEMODE)
extern MEMSEC_REF const EmFctCycleMode_t       * FCTSEN_pEmFctCycleMode;   /*!< Global system cycle mode etc. data */
#endif
#if (FCT_CFG_OBJECT_LIST_PROC)
extern MEMSEC_REF const EM_t_GenObjectList     * FCTSEN_pEmGenObjList;     /*!< The generic EM object data */
#if (FCT_USE_EM_CUSTOM_OBJECT_LIST)
extern MEMSEC_REF const EM_t_ObjectList_Custom * FCTSEN_pEmCustObjList;
#endif
#if (FCT_USE_EM_ARS_TECH_OBJECT_LIST)
extern MEMSEC_REF const EM_t_ARSObjectList     * FCTSEN_pEmARSObjList;
#endif
#if (FCT_USE_EM_CAM_TECH_OBJECT_LIST)
extern MEMSEC_REF const EM_t_CamObjectList     * FCTSEN_pEmCamObjList;
#endif
#if (FCT_CFG_INCLUDE_FUSION_OBJECT_LIST)
extern MEMSEC_REF const EM_t_FusionObjectList  * FCTSEN_pEmFusionObjList;
#endif
#if (FCT_CFG_USE_EM_MOVING_OBJECT_TRACES)
extern MEMSEC_REF const MovingObjectTraces_t   * FCTSEN_pMovObjTraces;     /*!< Moving object traces */
#endif
#if (FCT_CFG_NEW_TRACES_INTERFACE)
extern MEMSEC_REF const ObjectTraceList_t      * FCTSEN_pObjectTraces;     /*!< New object traces */
#endif
#if (FCT_CFG_ASSESSED_OBJ_OUT_INTF)
extern MEMSEC_REF AssessedObjList_t            * FCTSEN_pPubFctObjList;    /*!< The public FCT object data */
#endif
#endif
extern MEMSEC_REF const VehDyn_t               * FCTSEN_pEgoDynObjSync;    /*!< The object list synchronized ego dynamic signals */
extern MEMSEC_REF const VehDyn_t               * FCTSEN_pEgoDynRaw;        /*!< The dynamic vehicle ego data raw */
extern MEMSEC_REF const VehPar_t               * FCTSEN_pGlobEgoStatic;    /*!< the static vehicle ego data */
#if (FCT_CFG_SIGNAL_PERF_MONITORING)
extern MEMSEC_REF const PerfDegr_t             * FCTSEN_pPerfDegrData;     /*!< Performance degradation input data */
extern MEMSEC_REF SysPerfMonStates_t           * FCTSEN_pSysPerfMonStates; /*!< System performance monitor output data */
#endif
#if (FCT_CFG_RSP_OUTPUT_PD)
extern MEMSEC_REF const RSPOutputPD_t          * FCTSEN_pRSPOutputPD;      /*!< RSP range output information */
#endif
#if (FCT_CFG_ROAD_INPUT)
extern MEMSEC_REF const Road_t                 * FCTSEN_pRoadData;         /*!< Road/lane information */
#endif
#if (FCT_CFG_RSP_CONTEXT_INPUT)
extern MEMSEC_REF const RSPKontextData_t       * FCTSEN_pRSPContextData;   /*!< RSP Context data needed for FOV tangents */
#endif
#if (FCT_CFG_CUSTOM_IO_INTERFACE)
extern MEMSEC_REF const FCTCustomInput_t       * FCTSEN_pCustomInput;      /*!< FCT custom input */
extern MEMSEC_REF FCTCustomOutput_t            * FCTSEN_pCustomOutput;     /*!< FCT custom output */
#endif
#if (FCT_CFG_CAMERA_OBJECT_DETECTION)
extern MEMSEC_REF const EM_t_ObjectList_Custom * FCTSEN_pCameraObjData;    /*!< EM Camera fusion output data */
#endif
#if ((FCT_CFG_ALIGNMENT_MONITORING_INPUT) || (FCT_CFG_INCLUDE_UNUSED_INTF))
extern MEMSEC_REF const ALN_S_Monitoring_t     * FCTSEN_pAlignmentMonInput; /*!< Alignment monitoring output data */
#endif  /* Provide ports */
#if (FCT_CFG_CD_CUSTOM_OUTPUT_INTERFACE)
extern MEMSEC_REF FCTCDOutputCustom_t          * FCTSEN_pCDCustomOutput;   /*!< CD custom output data */
#endif
#if (FCT_CFG_USE_ALGOCOMPSTATE)
extern MEMSEC_REF AlgoCompState_t              * FCTSEN_pSenCompState;      /*!< FCT Sensor Algorithm Component State */
#endif
#if (FCT_CFG_COLLISION_DETECTION)
extern MEMSEC_REF HypothesisIntf_t             * FCT_pCDHypothesesSen;       /*!< FCT CD hypotheses */
#endif
#if (FCT_CFG_ME_INPUT_FOR_DEBUG)
extern MEMSEC_REF const ME_in_t                * FCTSEN_pME_in;              /*!< FCT mobil-eye input */
#endif
#if (FCT_CFG_BSW_ALGO_PARAMS)
extern MEMSEC_REF const BSW_s_AlgoParameters_t * FCTSEN_pBswAlgoParameters;  /*!< Input algo parameters from BSW */
#endif
#if (FCT_CFG_CPAR_PARAMS)
extern MEMSEC_REF const CPAR_FCT_Parameters_t  * FCTSEN_pCPAR_FCT_Parameters;    /*!< FCT Coding Parameters */
#endif
#if (FCT_CFG_DIM_OUTPUT_CUSTOM_FCT_SEN_INPUT)
extern MEMSEC_REF const DIMOutputCustom_t      * FCTSEN_pDIMOutputCustom;    /*!< DIM output custom from FCT_VEH */
#endif
#if (FCT_CFG_SEN_SIMPLE_NAVI_INTERFACE)
extern MEMSEC_REF const t_NaviInputData        * FCTSEN_pNaviData;           /*!< Simple navi input data */
#endif
#if (FCT_CFG_USE_BUS_DEBUG)
extern MEMSEC_REF const BusDebugData_t         * FCTSEN_pBusDebugData;
#endif
#if (FCT_CFG_SEN_CAM_LANE_INTERFACE)
extern MEMSEC_REF const t_CamLaneInputData     * FCTSEN_pCamLaneData;        /*!< Camera lane input data */
#endif
#if (FCT_CFG_SEN2VEH_ACC_OOI_PORT)
/* Provide OOI Objects from SEN to VEH */
extern MEMSEC_REF FCTSenAccOOI_t               * FCTSEN_pAccOOIData;
#endif
#if (FCT_CFG_SEN2TJA_ACC_OOI_PORT)
/* Provide OOI-0 Object from SLATE to TJA */
extern MEMSEC_REF TJATargetObj_t              * FCTSEN_pOOITJAData;
#endif
#if (defined(TSA_SLATE_INPUT_ENABLE) && defined(TSA_SLATE_Input_INTFVER))
extern MEMSEC_REF const TSA_SLATE_Input_t      * FCTSEN_pTSAInputData;      /*!< TSA input data from camera */
#endif
#if (FCT_CFG_LONG_CTRL_SLA_SUPPORT && defined(CamSLAInputData_INTFVER))
extern MEMSEC_REF const CamSLAInputData_t      * FCTSEN_pCamSLAInputData;      /*!< SLA input data from camera */
#endif
#if (FCT_CFG_SLA_FEATURE)
extern MEMSEC_REF SLAData_t                    * FCTSEN_pSLAData;              /*!< SLA speed limit data from FCT_SEN */
#endif

/*! FCT_SEN frame (cycle time, cycle counter, opmode ...) */
extern MEMSEC_REF FCTSenFrame_t                  FCTSenFrame;

/* Meas freeze reference */
extern MEMSEC_REF FCTSen_SyncRef_t               FCTSenSyncRef;

#if (FCT_CFG_RUNTIME_MEAS)
/* External declaration of FCT ACC runtime measurement info */
extern MEMSEC_REF FCT_t_RuntimeInfo              t_FCTSEN_RuntimeInfo;
#endif

/*****************************************************************************
  INLINE FUNCTIONS
*****************************************************************************/

/* Deactivate QA-C warning 3406; Reviewer: S. Schwarzkopf; Date: 05.12.2014; 
   Reason: Styleguide specifies this as best practice (R231, R238) and 
   ALGO_INLINE is defined compiler dependent for inlining with internal linkage.
   Review-ID: */
/* PRQA S 3406 ALGO_INLINES */
/**************/
#if (FCT_CFG_USE_SERVICE_POINTER_FUNCTS)
ALGO_INLINE AS_t_ServiceFuncts const * FCTSen_p_GetFCTServicePointer(void);
#endif
ALGO_INLINE EM_t_GenObjectList const * FCTSen_p_GetEMGenObjList(void);
ALGO_INLINE EM_t_GenObject const * FCTSen_p_GetEMGenObj(ObjNumber_t iObj);
ALGO_INLINE EM_t_GenObjKinematics const * FCTSen_p_GetEMGenObjKinematics(ObjNumber_t iObj);
ALGO_INLINE EM_t_GenObjQualifiers const * FCTSen_p_GetEMGenObjQualifiers(ObjNumber_t iObj);
ALGO_INLINE EM_t_GenObjAttributes const * FCTSen_p_GetEMGenObjAttributes(ObjNumber_t iObj);
ALGO_INLINE EM_t_GenObjGenerals const * FCTSen_p_GetEMGenObjGeneral(ObjNumber_t iObj);
ALGO_INLINE EM_t_GenObjGeometry const * FCTSen_p_GetEMGenObjGeometry(ObjNumber_t iObj);
#if (FCT_USE_EM_CUSTOM_OBJECT_LIST)
ALGO_INLINE EM_t_ObjectList_Custom const * FCTSen_p_GetEMCustObjList(void);
ALGO_INLINE EM_t_Cust_ObjectData const * FCTSen_p_GetEMCustObj(ObjNumber_t iObj);
#endif
#if (FCT_USE_EM_ARS_TECH_OBJECT_LIST)
ALGO_INLINE EM_t_ARSObjectList const * FCTSen_p_GetEMARSObjList(void);
ALGO_INLINE EM_t_ARSObject const * FCTSen_p_GetEMARSObj(ObjNumber_t iObj);
ALGO_INLINE EM_t_ARS_Attributes  const * FCTSen_p_GetEMARSObjAttributes(ObjNumber_t iObj);
ALGO_INLINE EM_t_ARS_Geometry  const * FCTSen_p_GetEMARSObjGeometry(ObjNumber_t iObj);
ALGO_INLINE EM_t_ARS_Kinematic  const * FCTSen_p_GetEMARSObjKinematic(ObjNumber_t iObj);
ALGO_INLINE EM_t_ARS_Legacy  const * FCTSen_p_GetEMARSObjLegacy(ObjNumber_t iObj);
ALGO_INLINE EM_t_ARS_MotionAttributes  const * FCTSen_p_GetEMARSObjMotionAttributes(ObjNumber_t iObj);
ALGO_INLINE EM_t_ARS_SensorSpecific  const * FCTSen_p_GetEMARSObjSensorSpecific(ObjNumber_t iObj);
#endif
#if (FCT_USE_EM_CAM_TECH_OBJECT_LIST)
ALGO_INLINE EM_t_CamObjectList const * FCTSen_p_GetEMCAMObjList(void);
ALGO_INLINE EM_t_CamObject const * FCTSen_p_GetEMCAMObj(ObjNumber_t iObj);
#endif

#if (FCT_CFG_ASSESSED_OBJ_OUT_INTF)
ALGO_INLINE AssessedObjList_t * FCTSen_p_GetFCTPubObjList(void);
ALGO_INLINE HeaderAssessedObjList_t * FCTSen_p_GetFCTPubObjListHeader(void);
ALGO_INLINE FCTPubObject_t * FCTSen_p_GetFCTPubObj(ObjNumber_t iObj);
ALGO_INLINE LaneInformation_t * FCTSen_p_GetFCTPubObj_LaneInfo(ObjNumber_t iObj);
ALGO_INLINE LegacyAOL_t * FCTSen_p_GetFCTPubObj_LegacyAOL(ObjNumber_t iObj);
ALGO_INLINE ObjOfInterest_t  * FCTSen_p_GetFCTPubObj_OOI(ObjNumber_t iObj);
ALGO_INLINE boolean FCTSen_b_IsObjOOI(ObjNumber_t iObj, eObjOOI_t eObjOOI);
ALGO_INLINE boolean FCTSen_b_IsObjRelevant(ObjNumber_t iObj);
ALGO_INLINE ObjNumber_t FCTSen_i_GetOOIObjIndex(eObjOOI_t eObjOOI);
ALGO_INLINE ObjNumber_t FCTSen_i_GetRelObjIndex(void);
#endif
ALGO_INLINE VehDyn_t const * FCTSen_p_GetVDYDynObjSync(void);
ALGO_INLINE float32 FCTSen_f_GetEgoVelObjSync(void);
ALGO_INLINE float32 FCTSen_f_GetEgoAccelObjSync(void);
ALGO_INLINE VehDyn_t const *  FCTSen_p_GetVDYDynRaw(void);
ALGO_INLINE float32 FCTSen_f_GetEgoVelRaw(void);
ALGO_INLINE float32 FCTSen_f_GetEgoAccelRaw(void);
ALGO_INLINE VehPar_t const *  FCTSen_p_GetVehPar(void);
ALGO_INLINE SensorMounting_t const *  FCTSen_p_GetSensorMounting(void);
#if (FCT_CFG_EM_FCT_CYCLEMODE)
ALGO_INLINE EmFctCycleMode_t  const *  FCTSen_p_GetEmFctCycleMode(void);
#endif
ALGO_INLINE float32 FCTSen_f_GetCycleTime(void);
#if (FCT_CFG_EM_FCT_CYCLEMODE)
#endif
ALGO_INLINE float32 FCTSen_f_GetSICycleTime(void);
ALGO_INLINE float32 FCTSen_f_GetSPMCycleTime(void);
ALGO_INLINE float32 FCTSen_f_GetCPCycleTime(void);
#if (FCT_CFG_ROAD_INPUT)
ALGO_INLINE Road_t const *  FCTSen_p_GetRoad(void);
#endif
#if (FCT_CFG_USE_EM_MOVING_OBJECT_TRACES)
ALGO_INLINE MovingObjectTraces_t const *  FCTSen_p_GetObjTraces(void);
ALGO_INLINE ObjectTrace_t const *  FCTSen_p_GetObjTrace(sint32 iTrace);
#endif
#if (FCT_CFG_RSP_CONTEXT_INPUT)
ALGO_INLINE RSPKontextData_t const *  FCTSen_p_GetRSPContextData(void);
#endif
#if (FCT_CFG_ALIGNMENT_MONITORING_INPUT)
ALGO_INLINE ALN_S_Monitoring_t const *  FCTSen_p_GetAlnMonInput(void);
#endif
#if (FCT_CFG_SIGNAL_PERF_MONITORING)
ALGO_INLINE PerfDegr_t   const *  FCTSen_p_GetPerfDegr(void);
ALGO_INLINE SysPerfMonStates_t *  FCTSen_p_GetSPMStates(void);
#endif
#if (FCT_CFG_RSP_OUTPUT_PD)
ALGO_INLINE RSPOutputPD_t const *  FCTSen_p_GetRSPOutputPD(void);
#endif
#if (FCT_CFG_CUSTOM_IO_INTERFACE)
ALGO_INLINE FCTCustomInput_t const *  FCTSen_p_GetCustomInput(void);
ALGO_INLINE FCTCustomOutput_t *  FCTSen_p_GetCustomOutput(void);
#endif
#if (FCT_CFG_CD_CUSTOM_OUTPUT_INTERFACE)
ALGO_INLINE FCTCDOutputCustom_t *  FCTSen_p_GetCDCustomOutput(void);
#endif
#if (FCT_CFG_COLLISION_DETECTION)
ALGO_INLINE HypothesisIntf_t *  FCTSen_p_GetHypothesisIntf(void);
ALGO_INLINE Hypothesis_t *  FCTSen_p_GetHypothesis(sint32 iHyp);
ALGO_INLINE HypoIntfDegr_t *  FCTSen_p_GetHypDegradation(void);
#endif
#if (FCT_CFG_BSW_ALGO_PARAMS)
ALGO_INLINE BSW_s_AlgoParameters_t const *  FCTSen_p_GetAlgoParameters(void);
#endif
ALGO_INLINE FCTSenFrame_t *  FCTSen_p_GetFCTSenFrame(void);
ALGO_INLINE FCTSen_SyncRef_t *  FCTSen_p_GetFCTSenSyncRef(void);
/**
@addtogroup frame_sen
@{ */


/************************************************************************/
/*                        ASSERT MACRO                                  */
/************************************************************************/
/* Check if we are in QA-C: PRQA_SIZE_T is defined in QA-C environment. */
#ifdef PRQA_SIZE_T
  /* date: 2017-01-11, reviewer: V.Ehrlinspiel, A.Kramer, reason:  
     Macro FCT_ASSERT can be set up platform dependent and is intended to have 
     no side effects here.
     Review-ID: 
  */
  #pragma PRQA_MACRO_MESSAGES_OFF "FCT_ASSERT" 3112
#endif /* #ifdef PRQA_SIZE_T */
/* Define to access assert functions in FCT */
#define FCT_ASSERT(x) CML_ASSERT(x)

/************************************************************************/
/* FCT Service Pointers                                                  */
/************************************************************************/
#if (FCT_CFG_USE_SERVICE_POINTER_FUNCTS)
/*************************************************************************************************************************
  Functionname:    FCTSen_p_GetFCTServicePointer                                                                         */ /*!
  @brief           Return Service Function pointer
  @return          AS_t_ServiceFuncts const *
  @param[in]       void : 
  @author          Huber Veronika |  | +49 (8382) 9699-490
*************************************************************************************************************************/
ALGO_INLINE AS_t_ServiceFuncts const * FCTSen_p_GetFCTServicePointer(void)
{
  return pFCTSenServiceFuncts;
}
#endif

/************************************************************************/
/* EM Gen Object list                                                   */
/************************************************************************/
/*************************************************************************************************************************
  Functionname:    FCTSen_p_GetEMGenObjList                                                                         */ /*!
  @brief           Return GenObject list pointer
  @return          EM_t_GenObjectList const *
  @param[in]       void : 
  @author          Andreas Kramer |  | +49 (8382) 9699-246
*************************************************************************************************************************/
ALGO_INLINE EM_t_GenObjectList const * FCTSen_p_GetEMGenObjList(void)
{
  return FCTSEN_pEmGenObjList;
}

/*************************************************************************************************************************
  Functionname:    FCTSen_p_GetEMGenObj                                                                             */ /*!
  @brief           Returns pointer to Gen object
  @return          EM_t_GenObject const *
  @param[in]       iObj : object index
  @author          Andreas Kramer |  | +49 (8382) 9699-246
*************************************************************************************************************************/
ALGO_INLINE EM_t_GenObject const * FCTSen_p_GetEMGenObj(ObjNumber_t iObj)
{
  /* Perform range check before accessing an object */
  /* Suppress "Msg(3:3112) This statement has no side-effect - it can be removed"  */ /*PRQA S 3112 1*/
  FCT_ASSERT((iObj >= 0) && (iObj < EM_N_OBJECTS));

  return &(FCTSen_p_GetEMGenObjList()->aObject[iObj]);
}


/*************************************************************************************************************************
  Functionname:    FCTSen_p_GetEMGenObjKinematics                                                                   */ /*!
  @brief           Returns pointer to object kinematic structure
  @return          EM_t_GenObjKinematics const *
  @param[in]       iObj : 
  @author          Andreas Kramer |  | +49 (8382) 9699-246
*************************************************************************************************************************/
ALGO_INLINE EM_t_GenObjKinematics const * FCTSen_p_GetEMGenObjKinematics(ObjNumber_t iObj)
{
  return &(FCTSen_p_GetEMGenObj(iObj)->Kinematic);
}

/*************************************************************************************************************************
  Functionname:    FCTSen_p_GetEMGenObjQualifiers                                                                   */ /*!
  @brief           Returns pointer to object qualifier structure
  @return          EM_t_GenObjQualifiers const *
  @param[in]       iObj : object index
  @author          Andreas Kramer |  | +49 (8382) 9699-246
*************************************************************************************************************************/
ALGO_INLINE EM_t_GenObjQualifiers const * FCTSen_p_GetEMGenObjQualifiers(ObjNumber_t iObj)
{
  return &(FCTSen_p_GetEMGenObj(iObj)->Qualifiers);
}

/*************************************************************************************************************************
  Functionname:    FCTSen_p_GetEMGenObjAttributes                                                                   */ /*!
  @brief           Returns EM_t_GenObjAttributes const *
  @return          EM_t_GenObjAttributes const *
  @param[in]       iObj : object index
  @author          Andreas Kramer |  | +49 (8382) 9699-246
*************************************************************************************************************************/
ALGO_INLINE EM_t_GenObjAttributes const * FCTSen_p_GetEMGenObjAttributes(ObjNumber_t iObj)
{
  return &(FCTSen_p_GetEMGenObj(iObj)->Attributes);
}

/*************************************************************************************************************************
  Functionname:    FCTSen_p_GetEMGenObjGeneral                                                                      */ /*!
  @brief           Returns EM_t_GenObjGenerals const *
  @return          EM_t_GenObjGenerals const *
  @param[in]       iObj : object index
  @author          Andreas Kramer |  | +49 (8382) 9699-246
*************************************************************************************************************************/
ALGO_INLINE EM_t_GenObjGenerals const * FCTSen_p_GetEMGenObjGeneral(ObjNumber_t iObj)
{
  return &(FCTSen_p_GetEMGenObj(iObj)->General);
}

/*************************************************************************************************************************
  Functionname:    FCTSen_p_GetEMGenObjGeometry                                                                     */ /*!
  @brief           Returns EM_t_GenObjGeometry const *
  @return          EM_t_GenObjGeometry const *
  @param[in]       iObj : object index
  @author          Andreas Kramer |  | +49 (8382) 9699-246
*************************************************************************************************************************/
ALGO_INLINE EM_t_GenObjGeometry const * FCTSen_p_GetEMGenObjGeometry(ObjNumber_t iObj)
{
  return &(FCTSen_p_GetEMGenObj(iObj)->Geometry);
}

#if (FCT_USE_EM_CUSTOM_OBJECT_LIST)
/************************************************************************/
/* EM Custom Object list                                                */
/************************************************************************/
/*************************************************************************************************************************
  Functionname:    FCTSen_p_GetEMCustObjList                                                                         */ /*!
  @brief           Return EmCustObject list pointer
  @return          EM_t_ObjectList_Custom const *
  @author          Jason Ye |  | +1 (248) 393-4561
*************************************************************************************************************************/
ALGO_INLINE EM_t_ObjectList_Custom const * FCTSen_p_GetEMCustObjList(void)
{
  return FCTSEN_pEmCustObjList;
}

/*************************************************************************************************************************
  Functionname:    FCTSen_p_GetEMCustObj                                                                             */ /*!
  @brief           Returns pointer to EM Cust object
  @return          EM_t_Cust_ObjectData const *
  @param[in]       iObj : object index
  @author          Jason Ye |  | +1 (248) 393-4561
*************************************************************************************************************************/
ALGO_INLINE EM_t_Cust_ObjectData const * FCTSen_p_GetEMCustObj(ObjNumber_t iObj)
{
  /* Perform range check before accessing an object */
  /* Suppress "Msg(3:3112) This statement has no side-effect - it can be removed"  */ /*PRQA S 3112 1*/
  FCT_ASSERT((iObj >= 0) && (iObj < EM_N_OBJECTS));

  return &(FCTSen_p_GetEMCustObjList()->CustObjects[iObj]);
}
#endif

#if (FCT_USE_EM_ARS_TECH_OBJECT_LIST)
/************************************************************************/
/* EM ARS Object list                                                   */
/************************************************************************/
/*************************************************************************************************************************
  Functionname:    FCTSen_p_GetEMARSObjList                                                                         */ /*!
  @brief           Returns EM_t_ARSObjectList const *
  @return          EM_t_ARSObjectList const *
  @author          Andreas Kramer |  | +49 (8382) 9699-246
*************************************************************************************************************************/
ALGO_INLINE EM_t_ARSObjectList const * FCTSen_p_GetEMARSObjList(void)
{
  return FCTSEN_pEmARSObjList;
}

/*************************************************************************************************************************
  Functionname:    FCTSen_p_GetEMARSObj                                                                             */ /*!
  @brief           Returns EM_t_ARSObject const *
  @return          EM_t_ARSObject const *
  @param[in]       iObj : object index
  @author          Andreas Kramer |  | +49 (8382) 9699-246
*************************************************************************************************************************/
ALGO_INLINE EM_t_ARSObject const * FCTSen_p_GetEMARSObj(ObjNumber_t iObj)
{
  /* Perform range check before accessing an object */
  /* Suppress "Msg(3:3112) This statement has no side-effect - it can be removed"  */ /*PRQA S 3112 1*/
  FCT_ASSERT((iObj >= 0) && (iObj < EM_N_OBJECTS));

  return &(FCTSen_p_GetEMARSObjList()->aObject[iObj]);
}

/*************************************************************************************************************************
  Functionname:    FCTSen_p_GetEMARSObjAttributes                                                                   */ /*!
  @brief           Returns EM_t_ARS_Attributes  const *
  @return          EM_t_ARS_Attributes  const *
  @param[in]       iObj : object index
  @author          Andreas Kramer |  | +49 (8382) 9699-246
*************************************************************************************************************************/
ALGO_INLINE EM_t_ARS_Attributes  const * FCTSen_p_GetEMARSObjAttributes(ObjNumber_t iObj)
{
  return &(FCTSen_p_GetEMARSObj(iObj)->Attributes);
}

/*************************************************************************************************************************
  Functionname:    FCTSen_p_GetEMARSObjGeometry                                                                     */ /*!
  @brief           Returns EM_t_ARS_Geometry  const *
  @return          EM_t_ARS_Geometry  const *
  @param[in]       iObj : object index
  @author          Andreas Kramer |  | +49 (8382) 9699-246
*************************************************************************************************************************/
ALGO_INLINE EM_t_ARS_Geometry  const * FCTSen_p_GetEMARSObjGeometry(ObjNumber_t iObj)
{
  return &(FCTSen_p_GetEMARSObj(iObj)->Geometry);
}

/*************************************************************************************************************************
  Functionname:    FCTSen_p_GetEMARSObjKinematic                                                                    */ /*!
  @brief           Returns EM_t_ARS_Kinematic  const *
  @return          EM_t_ARS_Kinematic  const *
  @param[in]       iObj : object index
  @author          Andreas Kramer |  | +49 (8382) 9699-246
*************************************************************************************************************************/
ALGO_INLINE EM_t_ARS_Kinematic  const * FCTSen_p_GetEMARSObjKinematic(ObjNumber_t iObj)
{
  return &(FCTSen_p_GetEMARSObj(iObj)->Kinematic);
}

/*************************************************************************************************************************
  Functionname:    FCTSen_p_GetEMARSObjLegacy                                                                       */ /*!
  @brief           Returns EM_t_ARS_Legacy  const *
  @return          EM_t_ARS_Legacy  const *
  @param[in]       iObj : object index
  @author          Andreas Kramer |  | +49 (8382) 9699-246
*************************************************************************************************************************/
ALGO_INLINE EM_t_ARS_Legacy  const * FCTSen_p_GetEMARSObjLegacy(ObjNumber_t iObj)
{
  return &(FCTSen_p_GetEMARSObj(iObj)->Legacy);
}

/*************************************************************************************************************************
  Functionname:    FCTSen_p_GetEMARSObjMotionAttributes                                                             */ /*!
  @brief           Returns EM_t_ARS_MotionAttributes  const *
  @return          EM_t_ARS_MotionAttributes  const *
  @param[in]       iObj : object index
  @author          Andreas Kramer |  | +49 (8382) 9699-246
*************************************************************************************************************************/
ALGO_INLINE EM_t_ARS_MotionAttributes  const * FCTSen_p_GetEMARSObjMotionAttributes(ObjNumber_t iObj)
{
  return &(FCTSen_p_GetEMARSObj(iObj)->MotionAttributes);
}

/*************************************************************************************************************************
  Functionname:    FCTSen_p_GetEMARSObjSensorSpecific                                                               */ /*!
  @brief           Returns EM_t_ARS_SensorSpecific  const *
  @return          EM_t_ARS_SensorSpecific  const *
  @param[in]       iObj : object index
  @author          Andreas Kramer |  | +49 (8382) 9699-246
*************************************************************************************************************************/
ALGO_INLINE EM_t_ARS_SensorSpecific  const * FCTSen_p_GetEMARSObjSensorSpecific(ObjNumber_t iObj)
{
  return &(FCTSen_p_GetEMARSObj(iObj)->SensorSpecific);
}
#endif

#if (FCT_USE_EM_CAM_TECH_OBJECT_LIST)
/************************************************************************/
/* Camera object list                                                   */
/************************************************************************/
/*************************************************************************************************************************
  Functionname:    FCTSen_p_GetEMCAMObjList                                                                         */ /*!
  @brief           Returns EM_t_CamObjectList const *
  @return          EM_t_CamObjectList const *
  @author          Andreas Kramer |  | +49 (8382) 9699-246
*************************************************************************************************************************/
ALGO_INLINE EM_t_CamObjectList const * FCTSen_p_GetEMCAMObjList(void)
{
  return FCTSEN_pEmCamObjList;
}

/*************************************************************************************************************************
  Functionname:    FCTSen_p_GetEMCAMObj                                                                             */ /*!
  @brief           Returns EM_t_CamObject const *
  @return          EM_t_CamObject const *
  @param[in]       iObj : object index
  @author          Andreas Kramer |  | +49 (8382) 9699-246
*************************************************************************************************************************/
ALGO_INLINE EM_t_CamObject const * FCTSen_p_GetEMCAMObj(ObjNumber_t iObj)
{
  /* Perform range check before accessing an object */
  /* Suppress "Msg(3:3112) This statement has no side-effect - it can be removed"  */ /*PRQA S 3112 1*/
  FCT_ASSERT((iObj >= 0) && (iObj < EM_N_OBJECTS));

  return &(FCTSen_p_GetEMCAMObjList()->aObject[iObj]);
}
#endif


/************************************************************************/
/* Private object list                                                  */
/************************************************************************/
///*************************************************************************************************************************
//  Functionname:    FCTSen_p_GetFCTPrivObj                                                                           */ /*!
//  @brief           Returns FCTObject_t *
//  @return          FCTObject_t *
//  @param[in]       iObj : object index
//  @author          Andreas Kramer |  | +49 (8382) 9699-246
//*************************************************************************************************************************/
//ALGO_INLINE FCTObject_t * FCTSen_p_GetFCTPrivObj(ObjNumber_t iObj)
//{
//  /* Perform range check before accessing an object */
//  /* Suppress "Msg(3:3112) This statement has no side-effect - it can be removed"  */ /*PRQA S 3112 1*/
//  FCT_ASSERT((iObj >= 0) && (iObj < EM_N_OBJECTS));
//
//  return &(FCTObjectList[iObj]);
//}


///*************************************************************************************************************************
//  Functionname:    FCTSen_p_GetFCTPrivObj_CustObjProps                                                              */ /*!
//  @brief           Returns FCTCustomObjectProperties_t *
//  @return          FCTCustomObjectProperties_t *
//  @param[in]       iObj : object index
//  @author          Andreas Kramer |  | +49 (8382) 9699-246
//*************************************************************************************************************************/
//ALGO_INLINE FCTCustomObjectProperties_t * FCTSen_p_GetFCTPrivObj_CustObjProps(ObjNumber_t iObj)
//{
//  return &(FCTSen_p_GetFCTPrivObj(iObj)->FCTCustomObjectProperties);
//}

/************************************************************************/
/* Public object list                                                   */
/************************************************************************/
#if (FCT_CFG_ASSESSED_OBJ_OUT_INTF)
/*************************************************************************************************************************
  Functionname:    FCTSen_p_GetFCTPubObjList                                                                        */ /*!
  @brief           Returns AssessedObjList_t *
  @return          AssessedObjList_t *
  @author          Andreas Kramer |  | +49 (8382) 9699-246
*************************************************************************************************************************/
ALGO_INLINE AssessedObjList_t * FCTSen_p_GetFCTPubObjList(void)
{
  return FCTSEN_pPubFctObjList;
}
/*************************************************************************************************************************
  Functionname:    FCTSen_p_GetFCTPubObjListHeader                                                                  */ /*!
  @brief           Returns HeaderAssessedObjList_t *
  @return          HeaderAssessedObjList_t *
  @author          Andreas Kramer |  | +49 (8382) 9699-246
*************************************************************************************************************************/
ALGO_INLINE HeaderAssessedObjList_t * FCTSen_p_GetFCTPubObjListHeader(void)
{
  return &(FCTSen_p_GetFCTPubObjList()->HeaderAssessedObjList);
}
/*************************************************************************************************************************
  Functionname:    FCTSen_p_GetFCTPubObj                                                                            */ /*!
  @brief           Returns FCTPubObject_t *
  @return          FCTPubObject_t *
  @param[in]       iObj : object index
  @author          Andreas Kramer |  | +49 (8382) 9699-246
*************************************************************************************************************************/
ALGO_INLINE FCTPubObject_t * FCTSen_p_GetFCTPubObj(ObjNumber_t iObj)
{
  /* Perform range check before accessing an object */
  /* Suppress "Msg(3:3112) This statement has no side-effect - it can be removed"  */ /*PRQA S 3112 1*/
  FCT_ASSERT((iObj >= 0) && (iObj < EM_N_OBJECTS));

  return &(FCTSen_p_GetFCTPubObjList()->ObjList[iObj]);
}
/*************************************************************************************************************************
  Functionname:    FCTSen_p_GetFCTPubObj_LaneInfo                                                                   */ /*!
  @brief           Returns LaneInformation_t *
  @return          LaneInformation_t *
  @param[in]       iObj : object index
  @author          Andreas Kramer |  | +49 (8382) 9699-246
*************************************************************************************************************************/
ALGO_INLINE LaneInformation_t * FCTSen_p_GetFCTPubObj_LaneInfo(ObjNumber_t iObj)
{
  return &(FCTSen_p_GetFCTPubObj(iObj)->LaneInformation);
}
/*************************************************************************************************************************
  Functionname:    FCTSen_p_GetFCTPubObj_LegacyAOL                                                                  */ /*!
  @brief           Returns LegacyAOL_t *
  @return          LegacyAOL_t *
  @param[in]       iObj : object index
  @author          Andreas Kramer |  | +49 (8382) 9699-246
*************************************************************************************************************************/
ALGO_INLINE LegacyAOL_t * FCTSen_p_GetFCTPubObj_LegacyAOL(ObjNumber_t iObj)
{
  return &(FCTSen_p_GetFCTPubObj(iObj)->Legacy);
}
/*************************************************************************************************************************
  Functionname:    FCTSen_p_GetFCTPubObj_OOI                                                                        */ /*!
  @brief           Returns ObjOfInterest_t  *
  @return          ObjOfInterest_t  *
  @param[in]       iObj : object index
  @author          Andreas Kramer |  | +49 (8382) 9699-246
*************************************************************************************************************************/
ALGO_INLINE ObjOfInterest_t  * FCTSen_p_GetFCTPubObj_OOI(ObjNumber_t iObj)
{
  return &(FCTSen_p_GetFCTPubObj(iObj)->ObjOfInterest);
}
/*************************************************************************************************************************
  Functionname:    FCTSen_b_IsObjOOI                                                                                */ /*!
  @brief           Returns boolean const
  @return          boolean const
  @param[in]       iObj : object index
  @param[in]       eObjOOI : object index
  @author          Andreas Kramer |  | +49 (8382) 9699-246
*************************************************************************************************************************/
ALGO_INLINE boolean FCTSen_b_IsObjOOI(ObjNumber_t iObj, eObjOOI_t eObjOOI)
{
  return (FCTSen_p_GetFCTPubObj_OOI(iObj)->eObjOOI == eObjOOI) ? TRUE : FALSE;
}
/*************************************************************************************************************************
  Functionname:    FCTSen_b_IsObjRelevant                                                                           */ /*!
  @brief           Returns boolean const
  @return          boolean const
  @param[in]       iObj : object index
  @author          Andreas Kramer |  | +49 (8382) 9699-246
*************************************************************************************************************************/
ALGO_INLINE boolean FCTSen_b_IsObjRelevant(ObjNumber_t iObj)
{
  return FCTSen_b_IsObjOOI(iObj, OBJ_NEXT_OOI);
}

/*************************************************************************************************************************
  Functionname:    FCTSen_i_GetOOIObjIndex                                                                          */ /*!
  @brief           Returns ObjNumber_t const
  @return          ObjNumber_t const
  @param[in]       eObjOOI : object index
  @author          Andreas Kramer |  | +49 (8382) 9699-246
*************************************************************************************************************************/
ALGO_INLINE ObjNumber_t FCTSen_i_GetOOIObjIndex(eObjOOI_t eObjOOI)
{
  /* Suppress "Msg(3:3112) This statement has no side-effect - it can be removed"  */ /*PRQA S 3112 1*/
  FCT_ASSERT((eObjOOI >= 0) && (eObjOOI < 6));
  return FCTSen_p_GetFCTPubObjListHeader()->aiOOIList[eObjOOI];
}
/*************************************************************************************************************************
  Functionname:    FCTSen_i_GetRelObjIndex                                                                          */ /*!
  @brief           Returns ObjNumber_t const
  @return          ObjNumber_t const
  @author          Andreas Kramer |  | +49 (8382) 9699-246
*************************************************************************************************************************/
ALGO_INLINE ObjNumber_t FCTSen_i_GetRelObjIndex(void)
{
  return FCTSen_i_GetOOIObjIndex(OBJ_NEXT_OOI);
}
#endif
/************************************************************************/
/* VDY signals                                                          */
/************************************************************************/

/*************************************************************************************************************************
  Functionname:    FCTSen_p_GetVDYDynObjSync                                                                        */ /*!
  @brief           Returns VehDyn_t const *
  @return          VehDyn_t const *
  @author          Andreas Kramer |  | +49 (8382) 9699-246
*************************************************************************************************************************/
ALGO_INLINE VehDyn_t const * FCTSen_p_GetVDYDynObjSync(void)
{
  return FCTSEN_pEgoDynObjSync;
}

/*************************************************************************************************************************
  Functionname:    FCTSen_f_GetEgoVelObjSync                                                                        */ /*!
  @brief           Returns float32
  @return          float32
  @author          Andreas Kramer |  | +49 (8382) 9699-246
*************************************************************************************************************************/
ALGO_INLINE float32 FCTSen_f_GetEgoVelObjSync(void)
{
#if (VDY_VEH_DYN_INTFVER >= 0x20)	// (0x20 -> 32U)
  return FCTSen_p_GetVDYDynObjSync()->Longitudinal.Velocity;
#else
  return FCTSen_p_GetVDYDynObjSync()->Longitudinal.MotVar.Velocity;
#endif
}

/*************************************************************************************************************************
  Functionname:    FCTSen_f_GetEgoAccelObjSync                                                                      */ /*!
  @brief           Returns float32
  @return          float32
  @author          Andreas Kramer |  | +49 (8382) 9699-246
*************************************************************************************************************************/
ALGO_INLINE float32 FCTSen_f_GetEgoAccelObjSync(void)
{
#if (VDY_VEH_DYN_INTFVER >= 0x20)	// (0x20 -> 32U)
  return FCTSen_p_GetVDYDynObjSync()->Longitudinal.Accel;
#else
  return FCTSen_p_GetVDYDynObjSync()->Longitudinal.MotVar.Accel;
#endif
}

/*************************************************************************************************************************
  Functionname:    FCTSen_p_GetVDYDynRaw                                                                            */ /*!
  @brief           Returns VehDyn_t const *
  @return          VehDyn_t const *
  @author          Andreas Kramer |  | +49 (8382) 9699-246
*************************************************************************************************************************/
ALGO_INLINE VehDyn_t const *  FCTSen_p_GetVDYDynRaw(void)
{
  return FCTSEN_pEgoDynRaw;
}

/*************************************************************************************************************************
  Functionname:    FCTSen_f_GetEgoVelRaw                                                                            */ /*!
  @brief           Returns float32
  @return          float32
  @author          Andreas Kramer |  | +49 (8382) 9699-246
*************************************************************************************************************************/
ALGO_INLINE float32 FCTSen_f_GetEgoVelRaw(void)
{
#if (VDY_VEH_DYN_INTFVER >= 0x20)	// (0x20 -> 32U)
  return FCTSen_p_GetVDYDynRaw()->Longitudinal.Velocity;
#else
  return FCTSen_p_GetVDYDynRaw()->Longitudinal.MotVar.Velocity;
#endif
}

/*************************************************************************************************************************
  Functionname:    FCTSen_f_GetEgoAccelRaw                                                                          */ /*!
  @brief           Returns float32
  @return          float32
  @author          Andreas Kramer |  | +49 (8382) 9699-246
*************************************************************************************************************************/
ALGO_INLINE float32 FCTSen_f_GetEgoAccelRaw(void)
{
#if (VDY_VEH_DYN_INTFVER >= 0x20)	// (0x20 -> 32U)
  return FCTSen_p_GetVDYDynRaw()->Longitudinal.Accel;
#else
  return FCTSen_p_GetVDYDynRaw()->Longitudinal.MotVar.Accel;
#endif
}

/************************************************************************/
/* Vehicle parameter                                                    */
/************************************************************************/

/*************************************************************************************************************************
  Functionname:    FCTSen_p_GetVehPar                                                                               */ /*!
  @brief           Returns VehPar_t const *
  @return          VehPar_t const *
  @author          Andreas Kramer |  | +49 (8382) 9699-246
*************************************************************************************************************************/
ALGO_INLINE VehPar_t const *  FCTSen_p_GetVehPar(void)
{
  return FCTSEN_pGlobEgoStatic;
}

/*************************************************************************************************************************
  Functionname:    FCTSen_p_GetSensorMounting                                                                       */ /*!
  @brief           Returns SensorMounting_t const *
  @return          SensorMounting_t const *
  @author          Andreas Kramer |  | +49 (8382) 9699-246
*************************************************************************************************************************/
ALGO_INLINE SensorMounting_t const *  FCTSen_p_GetSensorMounting(void)
{
  return &(FCTSen_p_GetVehPar()->SensorMounting);
}


/************************************************************************/
/* Misc                                                                 */
/************************************************************************/
#if (FCT_CFG_EM_FCT_CYCLEMODE)
/*************************************************************************************************************************
  Functionname:    FCTSen_p_GetEmFctCycleMode                                                                       */ /*!
  @brief           Returns EmFctCycleMode_t  const *
  @return          EmFctCycleMode_t  const *
  @author          Andreas Kramer |  | +49 (8382) 9699-246
*************************************************************************************************************************/
ALGO_INLINE EmFctCycleMode_t  const *  FCTSen_p_GetEmFctCycleMode(void)
{
  return FCTSEN_pEmFctCycleMode;
}
#endif
/*************************************************************************************************************************
  Functionname:    FCTSen_f_GetCycleTime                                                                            */ /*!
  @brief           Returns float32
  @return          float32
  @author          Andreas Kramer |  | +49 (8382) 9699-246
*************************************************************************************************************************/
ALGO_INLINE float32 FCTSen_f_GetCycleTime(void)
{
#if (FCT_CFG_EM_FCT_CYCLEMODE)
  return FCTSen_p_GetEmFctCycleMode()->fEmFctCycleTime;
#else
  return FCT_SEN_CYCLE_TIME;
#endif
}
/*************************************************************************************************************************
  Functionname:    FCTSen_f_GetSICycleTime                                                                          */ /*!
  @brief           Returns float32
  @return          float32
  @author          Andreas Kramer |  | +49 (8382) 9699-246
*************************************************************************************************************************/
ALGO_INLINE float32 FCTSen_f_GetSICycleTime(void)
{
  return FCTSen_f_GetCycleTime();
}
/*************************************************************************************************************************
  Functionname:    FCTSen_f_GetSPMCycleTime                                                                         */ /*!
  @brief           Returns float32
  @return          float32
  @author          Andreas Kramer |  | +49 (8382) 9699-246
*************************************************************************************************************************/
ALGO_INLINE float32 FCTSen_f_GetSPMCycleTime(void)
{
  return FCTSen_f_GetCycleTime();
}
/*************************************************************************************************************************
  Functionname:    FCTSen_f_GetCPCycleTime                                                                          */ /*!
  @brief           Returns float32
  @return          float32
  @author          Andreas Kramer |  | +49 (8382) 9699-246
*************************************************************************************************************************/
ALGO_INLINE float32 FCTSen_f_GetCPCycleTime(void)
{
  return FCTSen_f_GetCycleTime();
}

#if (FCT_CFG_ROAD_INPUT)
/*************************************************************************************************************************
  Functionname:    FCTSen_p_GetRoad                                                                                 */ /*!
  @brief           Returns Road_t const *
  @return          Road_t const *
  @author          Andreas Kramer |  | +49 (8382) 9699-246
*************************************************************************************************************************/
ALGO_INLINE Road_t const *  FCTSen_p_GetRoad(void)
{
  return FCTSEN_pRoadData;
}
#endif
#if (FCT_CFG_USE_EM_MOVING_OBJECT_TRACES)
/*************************************************************************************************************************
  Functionname:    FCTSen_p_GetObjTraces                                                                            */ /*!
  @brief           Returns MovingObjectTraces_t const *
  @return          MovingObjectTraces_t const *
  @author          Andreas Kramer |  | +49 (8382) 9699-246
*************************************************************************************************************************/
ALGO_INLINE MovingObjectTraces_t const *  FCTSen_p_GetObjTraces(void)
{
  return FCTSEN_pMovObjTraces;
}

/*************************************************************************************************************************
  Functionname:    FCTSen_p_GetObjTrace                                                                             */ /*!
  @brief           Returns ObjectTrace_t const *
  @return          ObjectTrace_t const *
  @param[in]       iTrace : object index
  @author          Andreas Kramer |  | +49 (8382) 9699-246
*************************************************************************************************************************/
ALGO_INLINE ObjectTrace_t const *  FCTSen_p_GetObjTrace(sint32 iTrace)
{
  /* Check range */
  /* Suppress "Msg(3:3112) This statement has no side-effect - it can be removed"  */ /*PRQA S 3112 1*/
  FCT_ASSERT((0 <= iTrace) && (iTrace < MAX_NUM_TRACES));

  return &(FCTSen_p_GetObjTraces()->ObjectTrace[iTrace]);
}
#endif

#if (FCT_CFG_RSP_CONTEXT_INPUT)
/*************************************************************************************************************************
  Functionname:    FCTSen_p_GetRSPContextData                                                                       */ /*!
  @brief           Returns RSPKontextData_t const *
  @return          RSPKontextData_t const *
  @author          Andreas Kramer |  | +49 (8382) 9699-246
*************************************************************************************************************************/
ALGO_INLINE RSPKontextData_t const *  FCTSen_p_GetRSPContextData(void)
{
  return FCTSEN_pRSPContextData;
}
#endif

#if (FCT_CFG_ALIGNMENT_MONITORING_INPUT)
/*************************************************************************************************************************
  Functionname:    FCTSen_p_GetAlnMonInput                                                                          */ /*!
  @brief           Returns ALN_S_Monitoring_t const *
  @return          ALN_S_Monitoring_t const *
  @author          Andreas Kramer |  | +49 (8382) 9699-246
*************************************************************************************************************************/
ALGO_INLINE ALN_S_Monitoring_t const *  FCTSen_p_GetAlnMonInput(void)
{
  return FCTSEN_pAlignmentMonInput;
}
#endif

#if (FCT_CFG_SIGNAL_PERF_MONITORING)
/*************************************************************************************************************************
  Functionname:    FCTSen_p_GetPerfDegr                                                                             */ /*!
  @brief           Returns PerfDegr_t   const *
  @return          PerfDegr_t   const *
  @author          Andreas Kramer |  | +49 (8382) 9699-246
*************************************************************************************************************************/
ALGO_INLINE PerfDegr_t   const *  FCTSen_p_GetPerfDegr(void)
{
  return FCTSEN_pPerfDegrData;
}

/*************************************************************************************************************************
  Functionname:    FCTSen_p_GetSPMStates                                                                            */ /*!
  @brief           Returns SysPerfMonStates_t *
  @return          SysPerfMonStates_t *
  @author          Andreas Kramer |  | +49 (8382) 9699-246
*************************************************************************************************************************/
ALGO_INLINE SysPerfMonStates_t *  FCTSen_p_GetSPMStates(void)
{
  return FCTSEN_pSysPerfMonStates;
}
#endif
#if (FCT_CFG_RSP_OUTPUT_PD)
/*************************************************************************************************************************
  Functionname:    FCTSen_p_GetRSPOutputPD                                                                          */ /*!
  @brief           Returns RSPOutputPD_t const *
  @return          RSPOutputPD_t const *
  @author          Andreas Kramer |  | +49 (8382) 9699-246
*************************************************************************************************************************/
ALGO_INLINE RSPOutputPD_t const *  FCTSen_p_GetRSPOutputPD(void)
{
  return FCTSEN_pRSPOutputPD;
}
#endif


#if (FCT_CFG_CUSTOM_IO_INTERFACE)
/*************************************************************************************************************************
  Functionname:    FCTSen_p_GetCustomInput                                                                          */ /*!
  @brief           Returns FCTCustomInput_t const *
  @return          FCTCustomInput_t const *
  @author          Andreas Kramer |  | +49 (8382) 9699-246
*************************************************************************************************************************/
ALGO_INLINE FCTCustomInput_t const *  FCTSen_p_GetCustomInput(void)
{
  return FCTSEN_pCustomInput;
}

/*************************************************************************************************************************
  Functionname:    FCTSen_p_GetCustomOutput                                                                         */ /*!
  @brief           Returns FCTCustomOutput_t *
  @return          FCTCustomOutput_t *
  @author          Andreas Kramer |  | +49 (8382) 9699-246
*************************************************************************************************************************/
ALGO_INLINE FCTCustomOutput_t *  FCTSen_p_GetCustomOutput(void)
{
  return FCTSEN_pCustomOutput;
}
#endif

#if (FCT_CFG_CD_CUSTOM_OUTPUT_INTERFACE)
/*************************************************************************************************************************
  Functionname:    FCTSen_p_GetCDCustomOutput                                                                       */ /*!
  @brief           Returns FCTCDOutputCustom_t *
  @return          FCTCDOutputCustom_t *
  @author          Andreas Kramer |  | +49 (8382) 9699-246
*************************************************************************************************************************/
ALGO_INLINE FCTCDOutputCustom_t *  FCTSen_p_GetCDCustomOutput(void)
{
  return FCTSEN_pCDCustomOutput;
}
#endif

#if (FCT_CFG_COLLISION_DETECTION)
/*************************************************************************************************************************
  Functionname:    FCTSen_p_GetHypothesisIntf                                                                       */ /*!
  @brief           Returns HypothesisIntf_t *
  @return          HypothesisIntf_t *
  @author          Andreas Kramer |  | +49 (8382) 9699-246
*************************************************************************************************************************/
ALGO_INLINE HypothesisIntf_t *  FCTSen_p_GetHypothesisIntf(void)
{
  return FCT_pCDHypothesesSen;
}

/*************************************************************************************************************************
  Functionname:    FCTSen_p_GetHypothesis                                                                           */ /*!
  @brief           Returns Hypothesis_t *
  @return          Hypothesis_t *
  @param[in]       iHyp : object index
  @author          Andreas Kramer |  | +49 (8382) 9699-246
*************************************************************************************************************************/
ALGO_INLINE Hypothesis_t *  FCTSen_p_GetHypothesis(sint32 iHyp)
{
  /* Check range */
  /* Suppress "Msg(3:3112) This statement has no side-effect - it can be removed"  */ /*PRQA S 3112 1*/
  FCT_ASSERT((0 <= iHyp) && (iHyp < MAX_NUM_OF_HYPS));

  return &(FCT_pCDHypothesesSen->Hypothesis[iHyp]);
}

/*************************************************************************************************************************
  Functionname:    FCTSen_p_GetHypDegradation                                                                       */ /*!
  @brief           Returns HypoIntfDegr_t *
  @return          HypoIntfDegr_t *
  @author          Andreas Kramer |  | +49 (8382) 9699-246
*************************************************************************************************************************/
ALGO_INLINE HypoIntfDegr_t *  FCTSen_p_GetHypDegradation(void)
{
  return &(FCTSen_p_GetHypothesisIntf()->Degradation);
}
#endif

#if (FCT_CFG_BSW_ALGO_PARAMS)
/*************************************************************************************************************************
  Functionname:    FCTSen_p_GetAlgoParameters                                                                       */ /*!
  @brief           Returns BSW_s_AlgoParameters_t const *
  @return          BSW_s_AlgoParameters_t const *
  @author          Andreas Kramer |  | +49 (8382) 9699-246
*************************************************************************************************************************/
ALGO_INLINE BSW_s_AlgoParameters_t const *  FCTSen_p_GetAlgoParameters(void)
{
  return FCTSEN_pBswAlgoParameters;
}
#endif

/*************************************************************************************************************************
  Functionname:    FCTSen_p_GetFCTSenFrame                                                                          */ /*!
  @brief           Returns FCTSenFrame_t *
  @return          FCTSenFrame_t *
  @author          Andreas Kramer |  | +49 (8382) 9699-246
*************************************************************************************************************************/
ALGO_INLINE FCTSenFrame_t *  FCTSen_p_GetFCTSenFrame(void)
{
  return &FCTSenFrame;
}

/*************************************************************************************************************************
  Functionname:    FCTSen_p_GetFCTSenSyncRef                                                                        */ /*!
  @brief           Returns FCTSen_SyncRef_t *
  @return          FCTSen_SyncRef_t *
  @author          Andreas Kramer |  | +49 (8382) 9699-246
*************************************************************************************************************************/
ALGO_INLINE FCTSen_SyncRef_t *  FCTSen_p_GetFCTSenSyncRef(void)
{
  return &FCTSenSyncRef;
}

/* PRQA L:ALGO_INLINES */

#endif
