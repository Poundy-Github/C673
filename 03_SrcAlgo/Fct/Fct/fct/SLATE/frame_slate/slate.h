/*! \file **********************************************************************

COMPANY:                   COPYRIGHT (C) Continental AG

PROJECT:                   Adaptive Cruise Control (ACC)

CPU:                       CPU-Independent

COMPONENT:                 Adaptive Cruise Control (ACC)

PACKAGENAME:               slate.h

DESCRIPTION:               Internal header file for Adaptive Cruise Control (ACC) in SLATE task

AUTHOR:                    Boll Marie-Theres (uidu1091)

CREATION DATE:             07.09.2016

VERSION:                   $Revision: 1.22 $

LEGACY VERSION:            Revision: 2.3


**************************************************************************** */
#ifndef SLATE_H_INCLUDED
#define SLATE_H_INCLUDED

/*****************************************************************************
  INCLUDES
*****************************************************************************/

#include "fct_sen.h"
#include "slate_ver.h"
#include "slate_access_func.h"


#if (FCT_CFG_ADAPTIVE_CRUISE_CONTROL)

#ifdef __cplusplus
extern "C" {
#endif
/*****************************************************************************
  MODULE DESCRIPTION
*****************************************************************************/
/*!
@addtogroup slate
@{
*/


#if (FCT_CFG_INPUT_PREPROCESSSING)
#include "fip_custom_ext.h"
#include "fip_ext.h"
#include "fip_access_func.h"
#endif

#if (FCT_CFG_ACC_SITUATION)
#include "sit_ext.h"
#include "sit_access_func.h"
#endif

#if (FCT_CFG_COURSE_PREDICTION)
#include "cp_custom_ext.h"
#include "cp_ext.h"
#include "cp_access_func.h"
#endif

#if (FCT_CFG_ACC_LANE_ASSOCIATION)
#include "la_custom_ext.h"
#include "la_ext.h"
#include "la_access_func.h"
#endif

#if (FCT_CFG_ACC_OOI)
#include "ooi_custom_ext.h"
#include "ooi_ext.h"
#include "ooi_access_func.h"
#endif

#if (FCT_CFG_ACC_OUTPUT)
#include "out_custom_ext.h"
#include "out_ext.h"
#include "out_access_func.h"
#endif
#if (SLATE_CFG_ACC_PERF_MONITORING)
#include "apm_ext.h"
#endif
  
#if (SLATE_CFG_USE_EXT_OBJ_ID)
#include "slate_calc_ext_obj_id.h"
#endif

/*****************************************************************************
  SYMBOLIC CONSTANTS (COMPONENT INTERN)
*****************************************************************************/


/*****************************************************************************
  MACROS (COMPONENT INTERN)
*****************************************************************************/

#if defined(FCT_SIMU) && !defined(FCT_MEAS_ID_PRIVATE_OBJECT_LIST)
#define FCT_MEAS_ID_PRIVATE_OBJECT_LIST   0x20211000uL
#endif

#define GET_PRIV_OBJ_DATA                         FCTObjectList // ACC
#define GET_FCT_OBJ(iObj)                         FCTObjectList[iObj] // ACC

#define GET_EM_FCT_CYCLE_MODE_PTR                 pSLATE_EmFctCycleMode
#define GET_EM_PUB_OBJ_DATA_PTR                   pSLATE_EmGenObjList
#define GET_EM_ARS_OBJ_LIST_PTR                   pSLATE_EmARSObjList
#define GET_EGO_OBJ_SYNC_DATA_PTR                 pSLATE_EgoDynObjSync
#define GET_EGO_RAW_DATA_PTR                      pSLATE_EgoDynRaw
#define GET_EGO_STATIC_DATA_PTR                   pSLATE_EgoStaticData
#define GET_PERF_DEG_DATA_PTR                     pSLATE_PerfDegrData
#define GET_ROAD_DATA_PTR                         pSLATE_RoadData
#if (SLATE_CFG_USE_EM_MOVING_OBJECT_TRACES)
#define GET_MOV_OBJ_TRACE_DATA_PTR                pSLATE_MovObjTraces
#endif
//#if (FCT_CFG_NEW_TRACES_INTERFACE)
//#define GET_OBJ_TRACE_LIST_DATA_PTR               FCTSEN_pObjectTraces
//#endif
#define RSP_GET_KONTEXT_DATA_PTR                  pSLATE_RSPContextData
#define ALN_MON_INPUT_PTR                         pSLATE_AlignmentMonInput

#define GET_FCT_PUB_OBJ_DATA_PTR                  pSLATE_PubFctObjList
//#define GET_SPM_DATA_PTR                          FCTSEN_pSysPerfMonStates
//
//#define GET_RSP_PD_OUTPUT_DATA_PTR                FCTSEN_pRSPOutputPD
//
#if (FCT_CFG_SEN2VEH_ACC_OOI_PORT)
#define GET_FCT_ACC_OOI_DATA_PTR                  pSLATE_AccOOIData
#endif

#define FCT_BSW_ALGO_PARAM_PTR                    pSLATE_BswAlgoParameters // ACC


#if ((FCT_CFG_CUSTOM_IO_INTERFACE) && (FCT_CFG_CUSTOM_IO_ABS_KINEMATIC))
#define OBJ_ABS_VELO_X(iObj)                  pSLATE_CustomOutput->CustObjData[iObj].AbsolutKinematics.fAbsVelocityX
#define OBJ_ABS_ACCEL_X(iObj)                 pSLATE_CustomOutput->CustObjData[iObj].AbsolutKinematics.fAbsAccelerationX
#else
#define OBJ_ABS_VELO_X(iObj)                  OBJ_GET_SI(iObj).fAbsVelocity
#define OBJ_ABS_ACCEL_X(iObj)                 OBJ_GET_SI(iObj).fAbsAcceleration
#endif

#if (FCT_CFG_SLATE_COMPONENT)
/*! Macros for accessing ACC Assessed Object List per object (based on GET_FCT_OBJ_PUB(iObj)) */
#define OBJ_GET_ASSOCIATED_LANE(iObj)             GET_FCT_OBJ_PUB(iObj).LaneInformation.eAssociatedLane /*!< Remark: SIGetAssociateLane */ // ACC, sim
#define OBJ_GET_FUNC_LANE(iObj)                   GET_FCT_OBJ_PUB(iObj).LaneInformation.eFuncAssociatedLane // ACC
#define OBJ_GET_OOI_POS(iObj)                     GET_FCT_OBJ_PUB(iObj).ObjOfInterest.eObjOOI // SPM, ACC, Simulation
#define OBJ_GET_RELEVANT(iObj)                    (OBJ_GET_OOI_POS(iObj) == OBJ_NEXT_OOI) // ACC /*!< Remark: ((iObj >= 0) && (iObj == EMRelObjPrevCycle)) */
#define OBJ_GET_OBJ_TO_REF_DISTANCE(iObj)         GET_FCT_OBJ_PUB(iObj).Legacy.fDistToRef //ACC/*!< Remark: SITrajGetObjToRefDistance((ui32_t)i_Obj, &fDistLat, &fDistLatVar) */
#define OBJ_GET_CUT_IN_POTENTIAL(iObj)            GET_FCT_OBJ_PUB(iObj).LaneInformation.uiCutInProbability // ACC, Simulation
#define OBJ_GET_CUT_OUT_POTENTIAL(iObj)           GET_FCT_OBJ_PUB(iObj).LaneInformation.uiCutOutProbability// ACC
#define OBJ_GET_EXTERNAL_OBJ_ID(iObj)             GET_FCT_OBJ_PUB(iObj).ObjOfInterest.cExternalID //ACC

/*! Macros for accessing ACC Assessed Object List object of interest array (based on GET_FCT_PUB_OBJ_DATA_PTR) */
#define OBJ_GET_OOI_LIST_OBJ_IDX(iOoiPos)         GET_FCT_PUB_OBJ_DATA_PTR->HeaderAssessedObjList.aiOOIList[iOoiPos] // SPM, ACC, Sim
#endif

/*! The function ID used for SI measurement data output */
#define OOI_MEAS_FUNC_ID         FCT_MEAS_FUNC_ID // Shang 13.02.2017 added as temp solution

/*! The func channel ID used for SI measurement data output */
#define OOI_MEAS_FUNC_CHAN_ID    FCT_MEAS_FUNC_CHAN_ID // Shang 13.02.2017 added as temp solution

  /*! The FCT-Sen FuncID used for meas-freezes */
#ifdef ALGO_ARS400Sensor 
#if (ALGO_ARS400Sensor) /* ARS4xx case */
#define FCT_ACC_MEAS_FUNC_ID        TASK_ID_ALGO_SEN_CYCLE
  /*! The FCT-Sen FuncChannelID used for meas-freezes @todo: Clarify later */
#define FCT_ACC_MEAS_FUNC_CHAN_ID   60u
#else /* SRR case */
#define FCT_ACC_MEAS_FUNC_ID        COMP_ID_FCT60
  /*! The FCT-Sen FuncChannelID used for meas-freezes */
#define FCT_ACC_MEAS_FUNC_CHAN_ID   TASK_ID_FCT60
#endif
#else /* camera case */
#define FCT_ACC_MEAS_FUNC_ID        TASK_ID_FCT60
  /*! The FCT-Sen FuncChannelID used for meas-freezes */
#define FCT_ACC_MEAS_FUNC_CHAN_ID   TASK_ID_FCT60
#endif

/*****************************************************************************
  TYPEDEFS (COMPONENT INTERN)
*****************************************************************************/



/*****************************************************************************
  CONSTANTS (COMPONENT INTERN)
*****************************************************************************/


/*****************************************************************************
  VARIABLES (COMPONENT INTERN)
*****************************************************************************/



/*****************************************************************************
  FUNCTIONS (COMPONENT INTERN)
*****************************************************************************/
/*--- slate.h ---*/
#if defined(_MSC_VER) /* Microsoft compiler */
ALGO_INLINE void Meas_Freeze_Stack_Var(uint32 VADDR_, void * ADDR_, uint32 SIZE_);
ALGO_INLINE void Meas_Freeze_Slate_Glob_Var(uint32 VADDR_,  void * ADDR_, uint32 SIZE_);
ALGO_INLINE void Meas_Freeze_Slate_SI_Glob_Var(uint32 VADDR_,  void * ADDR_, uint32 SIZE_);
#elif (defined(__GNUC__)) /* Courage Compiler */
ALGO_INLINE void Meas_Freeze_Stack_Var(uint32 VADDR_, void * ADDR_, uint32 SIZE_);
ALGO_INLINE void Meas_Freeze_Slate_Glob_Var(uint32 VADDR_,  void * ADDR_, uint32 SIZE_);
ALGO_INLINE void Meas_Freeze_Slate_SI_Glob_Var(uint32 VADDR_,  void * ADDR_, uint32 SIZE_);
#endif

/*--- slate_obj_main.c ---*/
#if (FCT_CFG_ERROR_OUTPUT_SEN)
extern void SLATE_v_FillErrorOut(SLATEErrorOutProPort_t * pt_ErrorOut);
#endif /* END IF (FCT_CFG_ERROR_OUTPUT_SEN) */
extern void SLATE_v_SetOperationMode(SLATECompState_t const t_ACCOpModeValue);
extern void SLATE_v_FillProPortHeaders(void);

#if (defined(RTA_INTERFACE_VERSION))
#if (RTA_INTERFACE_VERSION >= 4)
 extern void FCTSEN_SLATE_SERVICE_ADD_EVENT( const RTA_t_Events      RtaEvtType, const uint8 u_IdLocal, const uint8 u_OptData);
#else
 extern void FCTSEN_SLATE_SERVICE_ADD_EVENT( const AS_t_RtaEventType RtaEvtType, const uint8 u_IdLocal, const uint8 u_OptData);
#endif
#else
 extern void FCTSEN_SLATE_SERVICE_ADD_EVENT( const AS_t_RtaEventType RtaEvtType, const uint8 u_IdLocal, const uint8 u_OptData);
#endif

/*--- slate_algocontrol.c ---*/
#if (FCT_CFG_USE_ALGOCOMPSTATE)
extern void SLATE_v_SetAlgoErrorBuffer (GenAlgoQualifiers_t *const pErrorBuffer, const GenAlgoQualifiers_t ErrorQualifier);
#endif
extern void SLATE_v_ProcessStates (FCT_OP_MODE_t eOpMode);
extern void SLATE_v_SignalErrorShutdown(const boolean isRecoveryPossible);

/*--- slate_io.c ---*/
extern void SLATE_v_InitReqPortHandlerListMeasCycleData(boolean b_KeepMeasCycleData);
extern void SLATE_v_InitPortHandlerList(void);
extern void SLATE_v_ProcessPorts(   reqSLATEPortList_t const * const pRequirePorts,
                                   provSLATEPortList_t const * const pProvidePorts
#if (FCT_CFG_USE_SERVICE_POINTER_FUNCTS)
                                 , AS_t_ServiceFuncts const * const pServiceFuncts
#endif
#if (FCT_CFG_USE_ALGOCOMPSTATE)
                                 , GenAlgoQualifiers_t       * const pErrorBuffer
#endif
  );
extern void SLATE_v_ProcessInput(fTime_t fCycleTime, const VehDyn_t * pEgoDyn);

#ifdef PRQA_SIZE_T
  /* Switch off QA-C warnings on side effects for functions, which don't have 
     any side effects and will sure never have some. */
#pragma PRQA_NO_SIDE_EFFECTS SLATE_p_GetTrafoMatrix2DCOFForward
#pragma PRQA_NO_SIDE_EFFECTS SLATE_p_GetTrafoMatrix2DCOFBackward
#endif
extern const GDBTrafoMatrix2D_t * SLATE_p_GetTrafoMatrix2DCOFForward(void);
extern const GDBTrafoMatrix2D_t * SLATE_p_GetTrafoMatrix2DCOFBackward(void);

/*--- slate_meas.c ---*/
extern void FCTSen_v_ACCProcessMeasFreeze(void);
extern void FCTSen_v_ACCMeasCallback(void); // switch on Shang 27.01.2016
#if (FCT_MEASUREMENT)
extern void FCTSen_v_ACCFrameFreeze(void);
#endif
#if (FCT_MEASUREMENT)
extern void SIT_v_MeasCallback(void); // added Shang 27.01.2016
#endif
/* date: 2019-07-01, reviewer: Karthik Chittepu, reason:ALGO_INLINE is defined compiler dependent for inlining with internal linkage. */
/* PRQA S 3406 ALGO_INLINES */
/* ****************************************************************************

  Functionname:     Meas_Freeze_Stack_Var                                */ /*!

  @brief            Freeze copies data immediately to internal buffer 
                    -> buffer sized is limited

  @description      WARNING: this is the BUFFERED MEASFREEZE!!
                    - to be renamed in future
                    Populates descriptor and freezes the data at given virtual 
                    address. If freeze is not successful, throws error and increments 
                    counter to detect measurement failures.

  @param[in]        VADDR_ : virtual address to which data will be copied.
  @param[in]        ADDR_ : pointer to the data
  @param[in]        SIZE_ : size of the data.

  @return           void
  
  @pre              None
  @post             No changes

  @author           Author: Gobichettipalayam Sankar, Bharadwaj (uidk9952)

**************************************************************************** */
ALGO_INLINE void Meas_Freeze_Stack_Var(uint32 VADDR_, void * ADDR_, uint32 SIZE_)
{
  MEASInfo_t   desc;
  desc.VirtualAddress = (VADDR_);
  desc.Length         = (SIZE_);
  desc.FuncID         = FCT_MEAS_FUNC_ID;
  desc.FuncChannelID  = FCT_MEAS_FUNC_CHAN_ID;

#if (FCT_CFG_USE_SERVICE_POINTER_FUNCTS)
  if (pSLATE_ServiceFuncts != NULL)
  {
    if (pSLATE_ServiceFuncts->pfMeasFreeze != NULL)
    {
      (pSLATE_ServiceFuncts->pfMeasFreeze)(&desc, ADDR_, NULL);
    }
  }
#else
  (void)MEASFreezeDataMTS(&desc, ADDR_, NULL);/* PRQA S 3004 */
#endif /* date: 2019-07-01, reviewer: Karthik Chittepu, reason: safe to have integral constant expression with NULL */
}

/* ****************************************************************************

  Functionname:     Meas_Freeze_Slate_Glob_Var                            */ /*!

  @brief            Freeze job uses application buffer  
                    -> referenced data has to be kept global or static

  @description      WARNING: this is the UNBUFFERED MEASFREEZE!!  
                    - to be renamed in future.
                    Populates descriptor of the data and address to freeze the data.
                    Throws error if freeze is not successful.

  @param[in]        VADDR_ : Virtual address to copy the data.
  @param[in]        ADDR_ : pointer of the data.
  @param[in]        SIZE_ : size of the data.

  @return           void

  @pre              None
  @post             No changes

  @author           Author: Gobichettipalayam Sankar, Bharadwaj (uidk9952)

**************************************************************************** */
ALGO_INLINE void Meas_Freeze_Slate_Glob_Var(uint32 VADDR_,  void * ADDR_, uint32 SIZE_)
{

  MEASInfo_t   desc;
  desc.VirtualAddress = (VADDR_);
  desc.Length         = (SIZE_);
  desc.FuncID         = FCT_MEAS_FUNC_ID;
  desc.FuncChannelID  = FCT_MEAS_FUNC_CHAN_ID;

#if (FCT_CFG_USE_SERVICE_POINTER_FUNCTS)
  if (pSLATE_ServiceFuncts != NULL)
  {
    if (pSLATE_ServiceFuncts->pfMeasFreeze != NULL)
    {
      (pFCTSenServiceFuncts->pfMeasFreeze)(&desc, ADDR_, &FCTSen_v_ACCMeasCallback);
    }
  }
#else
  (void)MEASFreezeDataMTS(&desc, ADDR_, &FCTSen_v_ACCMeasCallback);
#endif
}

/* ****************************************************************************

  Functionname:     Meas_Freeze_Slate_SI_Glob_Var                         */ /*!

  @brief            Freeze job uses application buffer  
                    -> referenced data has to be kept global or static

  @description      WARNING: this is the UNBUFFERED MEASFREEZE!!  
                    - to be renamed in future.
                    Populates descriptor of the data and address to freeze the data.
                    Throws error if freeze is not successful.

  @param[in]        VADDR_ : Virtual address to copy the data.
  @param[in]        ADDR_ : pointer of the data.
  @param[in]        SIZE_ : size of the data.

  @return           void

  @pre              None
  @post             No changes

  @author           Author: Gobichettipalayam Sankar, Bharadwaj (uidk9952)

**************************************************************************** */
ALGO_INLINE void Meas_Freeze_Slate_SI_Glob_Var(uint32 VADDR_,  void * ADDR_, uint32 SIZE_)
{

  MEASInfo_t   desc;
  desc.VirtualAddress = (VADDR_);
  desc.Length         = (SIZE_);
  desc.FuncID         = FCT_MEAS_FUNC_ID;
  desc.FuncChannelID  = FCT_MEAS_FUNC_CHAN_ID;

#if (FCT_CFG_USE_SERVICE_POINTER_FUNCTS)
  (pFCTSenServiceFuncts->pfMeasFreeze)(&desc, ADDR_, &SIT_v_MeasCallback);
#else
  (void)MEASFreezeDataMTS(&desc, ADDR_, &SIT_v_MeasCallback);
#endif
}


#ifdef __cplusplus
};
#endif

#endif /*!< FCT_CFG_ADAPTIVE_CRUISE_CONTROL */

/* End of conditional inclusion */

#endif  /*!< _SLATE_H_INCLUDED */
/* PRQA L:ALGO_INLINES */
/** @} end defgroup */
