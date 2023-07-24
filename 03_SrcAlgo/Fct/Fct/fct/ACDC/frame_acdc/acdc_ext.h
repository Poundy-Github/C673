/*! \file **********************************************************************

COMPANY:                   COPYRIGHT (C) Continental AG
  
PROJECT:                   Mainstream

CPU:                       CPU-Independent

COMPONENT:                 ACDC - Advanced collision detection and classification 

PACKAGENAME:               acdc_ext.h

DESCRIPTION:               External header file for ACDC evaluation module. This file will become part of GA.

AUTHOR:                    $Author: uidn4751 $

MODIFICATION DATE:         $Date: 2019/06/03 15:23:20CEST $

VERSION:                   $Revision: 1.21 $

**************************************************************************** */
#ifndef ACDC_EXT_INCLUDED
#define ACDC_EXT_INCLUDED

/*****************************************************************************
INCLUDES
*****************************************************************************/
#include "fct_sen_ext.h"
#include "fct_types.h"

#if (FCT_CFG_ACDC_COMPONENT)
#include "acdc_mem_cfg.h"

#ifdef __cplusplus
extern "C" {
#endif


/*!@{
Definition of virtual addresses for each memory type. */
/* TODO: Use VIRT_ADDR_START_ACDC as soon as it is defined  */
#define GA_ACDC_MEAS_ID_RANGE_START                       (0x22500000u) /*!< First virtual address to freeze ACDC related data */
#define GA_ACDC_MEAS_ID_RANGE_END                         (0x22520000u) /*!< Last virtual address to freeze ACDC related data */
#define GA_ACDC_MEAS_ID_RANGE_END_SIMU                    (0x22600000u) /*!< Last virtual address to freeze ACDC related data in Simu */

#define GA_ACDC_MEAS_ID_INTER_CYCLE_MEAS_DATA             (GA_ACDC_MEAS_ID_RANGE_START                                                        )
#define GA_ACDC_MEAS_ID_INTRA_CYCLE_MEAS_DATA             (GA_ACDC_MEAS_ID_INTER_CYCLE_MEAS_DATA + GA_ACDC_SIZE_MEM_DATA_INTER_CYCLE_MEAS     )
#define GA_ACDC_MEAS_ID_INTER_CYCLE_DATA                  (GA_ACDC_MEAS_ID_INTRA_CYCLE_MEAS_DATA + GA_ACDC_SIZE_MEM_DATA_INTRA_CYCLE_MEAS     )
#define GA_ACDC_MEAS_ID_INTRA_CYCLE_DATA                  (GA_ACDC_MEAS_ID_INTER_CYCLE_DATA      + GA_ACDC_SIZE_MEM_DATA_INTER_CYCLE          )
#ifdef ACDC_SIMU
#define GA_ACDC_MEAS_ID_STACK                             (GA_ACDC_MEAS_ID_INTRA_CYCLE_DATA      + GA_ACDC_SIZE_MEM_DATA_INTRA_CYCLE          )
#define GA_ACDC_MEAS_ID_SIMU                              (GA_ACDC_MEAS_ID_STACK                 + GA_ACDC_SIZE_MEM_DATA_STACK                )
/* Check sufficient virtual address range. Compile error C2057 appears if condition is not fulfilled */
/* PRQA S 1271 EXPRESSION */
GA_assert ( ((GA_ACDC_MEAS_ID_SIMU             + GA_ACDC_SIZE_MEM_DATA_SIMU       ) < GA_ACDC_MEAS_ID_RANGE_END_SIMU) );
#endif /* ACDC_SIMU */
GA_assert ( ((GA_ACDC_MEAS_ID_INTRA_CYCLE_DATA + GA_ACDC_SIZE_MEM_DATA_INTRA_CYCLE) < GA_ACDC_MEAS_ID_RANGE_END     ) );
  /* PRQA L:EXPRESSION */
/*!@} */


/* GA: ACDC Process Memory. */

/*! @brief Memory is not kept over cycles. Should only be used for variables which are recalculated in every cycle. 
   No automated freezing is done. Put variables here which should be frozen only in simulation. 
   i.e. results of the get functions */
typedef uint8  GA_ACDC_Mem_DataIntraCycle     [GA_ACDC_SIZE_MEM_DATA_INTRA_CYCLE];
/*! @brief Memory is not kept over cycles, but over multiple runnables of one component. Should only be used for variables which are recalculated in every cycle. 
   Automated freezing is done. Put variables here which should be freezed cyclic in simulation and ECU.*/
typedef uint8  GA_ACDC_Mem_DataIntraCycleMeas [GA_ACDC_SIZE_MEM_DATA_INTRA_CYCLE_MEAS];
/*! @brief Memory is kept over cycles. Should only be used for variables which contain history. 
   Automated freezing is done. Put all variables here which should be freezed in simulation and ECU in every cycles.*/
typedef uint8  GA_ACDC_Mem_DataInterCycleMeas [GA_ACDC_SIZE_MEM_DATA_INTER_CYCLE_MEAS];
/*! @brief Memory is kept over cycles. Should only be used for variables which contain history. 
   Automated freezing is done. Put all variables here which should be freezed in simulation and ECU in every keyframe. This data is used for siminit.*/
typedef uint8  GA_ACDC_Mem_DataInterCycle     [GA_ACDC_SIZE_MEM_DATA_INTER_CYCLE];

#ifdef ACDC_SIMU
/*! @brief Memory is only available in simulation. */
typedef uint8  GA_ACDC_Mem_DataSimu           [GA_ACDC_SIZE_MEM_DATA_SIMU];
#endif

/*! @brief Collection of pointers to the different memory types used in ACDC */
typedef struct ACDC_ProcMem_t 
{
  GA_ACDC_Mem_DataInterCycle          * pMemInterCycle;
  GA_ACDC_Mem_DataInterCycleMeas      * pMemInterCycleMeas;
  GA_ACDC_Mem_DataIntraCycle          * pMemIntraCycle;
  GA_ACDC_Mem_DataIntraCycleMeas      * pMemIntraCycleMeas;
#ifdef ACDC_SIMU
  GA_ACDC_Mem_DataSimu                * pMemSimu;
#endif
} ACDC_ProcMem_t;


/*****************************************************************************
TYPEDEFS (COMPONENT EXTERN)
*****************************************************************************/


/*! @brief    Ports provided by ACDC*/
typedef struct provACDCPrtList{
  ACDCErrorOutProPort_t   * pErrorOut;
#if (FCT_CFG_USE_ALGOCOMPSTATE)
  AlgoCompState_t         * pSenCompState;  /*!< AlgoCompState interface to scheduler */
#endif
#if (FCT_CFG_COLLISION_DETECTION)
  HypothesisIntf_t        * pHypotheses;
#endif
#if (FCT_CFG_CD_CUSTOM_OUTPUT_INTERFACE)
  /* custom output for CD */
  FCTCDOutputCustom_t     * pCDCustomOutput;     /*!< Collision detection custom output */
#endif
}provACDCPrtList_t;

/*! @brief    Inputs required by ACDC*/
typedef struct reqACDCPrtList{
  const VehDyn_t               * pEgoDynRaw;       /*!< The dynamic vehicle ego data raw */
  const VehPar_t               * pEgoStaticData;   /*!< the static vehicle ego data */
  
#if(ACDC_CFG_USE_FPS || ACDC_AIP_CFG_SHIFT_COORDINATE)
  EM_t_GenObjectList     * pEmGenObjList;    /*!< EM generic object list */   //For FPS .....@Cheng Long
#else
  const EM_t_GenObjectList     * pEmGenObjList;    /*!< EM generic object list */
#endif

#if (FCT_CFG_USE_BASECTRLDATA)
  const BaseCtrlData_t         * pSenCtrlData;        /*!< FCT control data */
#else /* (!FCT_CFG_USE_BASECTRLDATA) */
  const FCTCtrlData_t          * pSenCtrlData;        /*!< FCT control data */
#endif /* (FCT_CFG_USE_BASECTRLDATA) */
#if ((FCT_CFG_COLLISION_DETECTION)&&(FCT_CFG_ADAPTIVE_CRUISE_CONTROL))
  const SLATE_CD_Data_t        * pSLATE_CD_Data;
#endif
#if (!FCT_CFG_SHORT_RANGE_FUNCTIONS)
  const VehDyn_t               * pEgoDynObjSync;   /*!< The dynamic vehicle ego data object sync */
#endif
#if (FCT_CFG_EM_FCT_CYCLEMODE)
  const EmFctCycleMode_t       * pEmFctCycleMode;  /*!< The global sensor state */
#endif
#if (FCT_USE_EM_CUSTOM_OBJECT_LIST)
  const EM_t_ObjectList_Custom * pEmCustObjList;   /*!< EM customer specific object list */
#endif
#if (FCT_USE_EM_ARS_TECH_OBJECT_LIST)
  const EM_t_ARSObjectList     * pEmARSObjList;    /*!< EM ARS-technology-specific object list */
#endif
#if (FCT_USE_EM_CAM_TECH_OBJECT_LIST)
  const EM_t_CamObjectList     * pEmCamObjList;    /*!< EM Camera-technology-specific object list */
#endif
#if (FCT_CFG_ALIGNMENT_MONITORING_INPUT)
  const ALN_S_Monitoring_t     * pAlignmentMonInput; /*!< Alignment monitoring output data */
#endif
#if (FCT_CFG_BSW_ALGO_PARAMS)
  /* algo parameters from BSW */
  const BSW_s_AlgoParameters_t * pBswAlgoParameters;  /*!< Input algo parameters from BSW */
#endif
#if (FCT_CFG_INCLUDE_FUSION_OBJECT_LIST)
  const EM_t_FusionObjectList   * pEmFusionObjList; /* EM Fusion Object List */
#endif
}reqACDCPrtList_t;

/*! @brief    Simulation sync structure, contains Signal Headers of every Input Port */
typedef struct ACDCSyncRef{
  SignalHeader_t sSigHeader;      /*!<sSigHeader */
  SignalHeader_t EgoDynRaw;       /*!< The dynamic vehicle ego data raw */
  SignalHeader_t EgoStaticData;   /*!< the static vehicle ego data */
  SignalHeader_t EmGenObjList;    /*!< EM generic object list */
  SignalHeader_t SenCtrlData;     /*!< SenCtrlData */

#if ((FCT_CFG_COLLISION_DETECTION)&&(FCT_CFG_ADAPTIVE_CRUISE_CONTROL))
  SignalHeader_t SLATE_CD_Data;
#endif
#if(!FCT_CFG_SHORT_RANGE_FUNCTIONS)
  SignalHeader_t EgoDynObjSync;   /*!< The dynamic vehicle ego data object sync */
#endif
#if (FCT_USE_EM_CUSTOM_OBJECT_LIST)
  SignalHeader_t EmCustObjList;   /*!< EM customer specific object list */
#endif
#if (FCT_USE_EM_ARS_TECH_OBJECT_LIST)
  SignalHeader_t EmARSObjList;    /*!< EM ARS-technology-specific object list */
#endif
#if (FCT_USE_EM_CAM_TECH_OBJECT_LIST)
  SignalHeader_t EmCamObjList;    /*!< EM Camera-technology-specific object list */
#endif
#if (FCT_CFG_ALIGNMENT_MONITORING_INPUT)
  SignalHeader_t AlignmentMonInput; /*!< Alignment monitoring output data */
#endif
#if (FCT_CFG_BSW_ALGO_PARAMS)
  SignalHeader_t BswAlgoParameters;       /*!< Input algo parameters from Base SW */
#endif
#if (FCT_CFG_EM_FCT_CYCLEMODE)
  SignalHeader_t EmFctCycleMode;  /*!< The global sensor state */
#endif
#if (FCT_CFG_INCLUDE_FUSION_OBJECT_LIST)
  SignalHeader_t EmFusionObjList; /* EM Fusion Object List */
#endif
} ACDCSyncRef_t; 


/*****************************************************************************
FUNCTIONS (COMPONENT EXTERN)
****************************************************************************/
extern void ACDC_v_Exec( reqACDCPrtList_t   const * const p_ACDCRequirePorts 
                        ,provACDCPrtList_t        * const p_ACDCProvidePorts
#if (!FCT_CFG_USE_ACDC_INTERNAL_MEMORY)     
                        ,ACDC_ProcMem_t     const * const p_ACDCProcMem
#endif
#if (FCT_CFG_USE_SERVICE_POINTER_FUNCTS)
                        ,AS_t_ServiceFuncts const * const p_ServiceFuncts
#endif
  );


#ifdef __cplusplus
}
#endif

/// @}
#endif /*!< FCT_CFG_ACDC_COMPONENT*/

#endif  /*!< ACDC_EXT_INCLUDED */

