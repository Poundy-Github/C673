/*! \file **********************************************************************

COMPANY:                   COPYRIGHT (C) Continental AG

PROJECT:                   Mainstream

CPU:                       CPU-Independent

COMPONENT:                 MEDIC (Monitoring Evaluation And Decision For Intervention Control)

PACKAGENAME:               medic_ext.h

DESCRIPTION:               External header file for MEDIC  evaluation module in FCT_VEH task

AUTHOR:                    $Author: Vogl, Armin (uid19462) $

CREATION DATE:             $Date: 2020/09/03 17:04:40CEST $

VERSION:                   $Revision: 1.69 $

**************************************************************************** */

#ifndef MEDIC_EXT_INCLUDED
#define MEDIC_EXT_INCLUDED

/*****************************************************************************
  GLOBAL DEFINES
*****************************************************************************/
#define MEDIC_OFF (0u)
#define MEDIC_ON  (1u)

#ifdef SIL_SIMU
#define MEDIC_SIMU
#endif

/*****************************************************************************
  INCLUDES
*****************************************************************************/
#include "frame_medic/medic_cfg.h"
#if(MEDIC_CFG_EMERGENCY_BRAKE_ASSIST)

#include "frame_medic/medic_project_id.h"
#include "frame_medic/medic_ver.h"
#include "frame_medic/medic_mem_cfg.h"
#if ((defined FCT_CFG_H_INCLUDED) && (MEDIC_ARCHITECTURE_VERSION < 0x10))
#include "fct_glob_ext.h"
#endif

#include "frame_medic/medic_custom_types.h"
#include "frame_medic/medic_types.h"
#include "frame_medic/medic_main.h"

#if MEDIC_CFG_HEAD20
#include "head20/head20_ext.h"
#else
#include "head/head_ext.h"
#endif
#if MEDIC_CFG_DIM20
#include "dim20/dim20_ext.h"
#else
#include "dim/dim_ext.h"
#endif

#ifdef __cplusplus
extern "C" {
#endif

/*****************************************************************************
  SYMBOLIC CONSTANTS (COMPONENT EXTERN)
*****************************************************************************/

/*****************************************************************************
  MACROS (COMPONENT EXTERN)
*****************************************************************************/

#ifndef GA_assert
/* Copy of GA assert from GA_common.h. To be removed when global architecture is used */

/* ---- macro definitions -------------------------------------------------- */
/* PRQA S 2053 COMMENT*/
/* Deactivate QA-C warning 3412; Reviewer: A. Schlensag; 
   Date: 28.11.2016;
   Reason: This macro shall only avoid compilation when static mem is insufficient
*/
  /* PRQA L:COMMENT*/
    /* PRQA S 3412 MACRO */
#define GA_ASSERT_CONCAT_(a, b)     a##b
#define GA_ASSERT_CONCAT(a, b)      GA_ASSERT_CONCAT_(a, b)
#define GA_assert(e)                enum { GA_ASSERT_CONCAT(assert_line_, __LINE__) = 1/(sint32)(!!(e)) }
/* PRQA L:MACRO */
#endif 
/*PRQA S 1840,1842,3493,3494 EOF*/ /* date: 2020-01-21, Reviewer: Nagaraja Veerashettappa, Reason: Implementation is intended */
/*!@{
/Definition of virtual addresses for each memory type. */
#define GA_MEDIC_MEAS_ID_RANGE_START                       (0x20900400u)
#define GA_MEDIC_MEAS_ID_RANGE_END                         (0x209FFFFFu)
#define GA_MEDIC_MEAS_ID_INTER_CYCLE_MEAS_DATA             (GA_MEDIC_MEAS_ID_RANGE_START                                                         )
#define GA_MEDIC_MEAS_ID_INTRA_CYCLE_MEAS_DATA             (GA_MEDIC_MEAS_ID_INTER_CYCLE_MEAS_DATA + GA_MEDIC_SIZE_MEM_DATA_INTER_CYCLE_MEAS     )
#define GA_MEDIC_MEAS_ID_INTER_CYCLE_DATA                  (GA_MEDIC_MEAS_ID_INTRA_CYCLE_MEAS_DATA + GA_MEDIC_SIZE_MEM_DATA_INTRA_CYCLE_MEAS     )
#ifdef MEDIC_SIMU
#define GA_MEDIC_MEAS_ID_STACK                             (GA_MEDIC_MEAS_ID_INTER_CYCLE_DATA      + GA_MEDIC_SIZE_MEM_DATA_INTER_CYCLE          )
/* Check sufficient virtual address range. Compile error C2057 appears if condition is not fulfilled */
#endif
GA_assert ( ((GA_MEDIC_MEAS_ID_INTRA_CYCLE_MEAS_DATA + GA_MEDIC_SIZE_MEM_DATA_INTRA_CYCLE_MEAS) < GA_MEDIC_MEAS_ID_RANGE_END     ) );
  /* PRQA L:EXPRESSION */
/*!@} */

/*****************************************************************************
  VARIABLES
*****************************************************************************/
/* GA: MEDIC Process Memory. */

/*! @brief Memory is not kept over cycles. Should only be used for variables which are recalculated in every cycle. 
   Automated freezing is done. Put variables here which should be freezed in simulation and ECU.*/
typedef uint32  GA_MEDIC_Mem_DataIntraCycleMeas [(GA_MEDIC_SIZE_MEM_DATA_INTRA_CYCLE_MEAS + 3u) / 4u];
/*! @brief Memory is kept over cycles. Should only be used for variables which contain history. 
   Automated freezing is done. Put all variables here which should be freezed in simulation and ECU in every cycles.*/
typedef uint32  GA_MEDIC_Mem_DataInterCycleMeas [(GA_MEDIC_SIZE_MEM_DATA_INTER_CYCLE_MEAS + 3u) / 4u];

/*! @brief Memory is kept over cycles. Should only be used for variables which contain history. 
   Automated freezing is done. Put all variables here which should be freezed in simulation and ECU in every keyframe. This data is used for siminit.*/
typedef uint32  GA_MEDIC_Mem_DataInterCycle     [(GA_MEDIC_SIZE_MEM_DATA_INTER_CYCLE      + 3u) / 4u];

/*****************************************************************************
  TYPEDEFS
*****************************************************************************/
/*! @brief Collection of pointers to the different memory types used in MEDIC */
typedef struct MEDIC_ProcMem_t 
{
  GA_MEDIC_Mem_DataInterCycle          * pMemInterCycle;
  GA_MEDIC_Mem_DataInterCycleMeas      * pMemInterCycleMeas;
  GA_MEDIC_Mem_DataIntraCycleMeas      * pMemIntraCycleMeas;
} MEDIC_ProcMem_t;

/*****************************************************************************
  TYPEDEFS (COMPONENT EXTERN)
*****************************************************************************/

/*! @brief MEDIC provide ports struct */
#if (MEDIC_ARCHITECTURE_VERSION < 0x10)
typedef struct 
{
  #if (MEDIC_CFG_USE_ALGOCOMPSTATE)
  AlgoCompState_t             * pVehCompState;      /*!< AlgoCompState interface to scheduler */
  #endif
  #if ((MEDIC_CFG_DRIVER_INTENTION_MONITORING) || (MEDIC_CFG_INCLUDE_UNUSED_INTF))
  DIMOutputCustom_t           * pDIMOutputCustom;   /*!< Custom DIM output */
  #endif
  #if ((MEDIC_CFG_HYPOTHESIS_EVAL_AND_DECISION) || (MEDIC_CFG_INCLUDE_UNUSED_INTF))
  HEADOutputGeneric_t         * pHEADOutputGeneric; /*!< Generic HEAD output */
  HEADOutputCustom_t          * pHEADOutputCustom;  /*!< Custom HEAD output */
  #endif
  #if (MEDIC_CFG_ERROR_OUTPUT_VEH)
  FCTVehErrorOut_t            * pErrorOut;          /*!< FCT error output */
  #endif
  #if ((!MEDIC_CFG_INCLUDE_UNUSED_INTF) && (!MEDIC_CFG_USE_ALGOCOMPSTATE) && (!MEDIC_CFG_ERROR_OUTPUT_VEH) && (!MEDIC_CFG_DRIVER_INTENTION_MONITORING) && (!MEDIC_CFG_HYPOTHESIS_EVAL_AND_DECISION))
  #if !defined(__NO_ARS_COMPILER_MESSAGES)
  #endif
  unsigned int dummy;
  #endif
} proMEDICPtrList_t;
#endif

/*! @brief MEDIC required port struct  Inputs required by MEDIC component for vehicle cycle processing */
#if (MEDIC_ARCHITECTURE_VERSION < 0x10)
typedef struct 
{
  #if (MEDIC_CFG_USE_BASECTRLDATA)
  const BaseCtrlData_t        *pVehCtrlData;         /*!< FCT control data                    */
  #else
  const FCTCtrlData_t         *pVehCtrlData;         /*!< FCT control data                    */
  #endif
  const VehDyn_t              *pEgoDynRaw;           /*!< The dynamic vehicle ego data raw    */
  #if ((MEDIC_CFG_DRIVER_INTENTION_MONITORING) || (MEDIC_CFG_INCLUDE_UNUSED_INTF))
  const DIMInputGeneric_t     *pDIMInputGeneric;     /*!< Generic DIM input                   */
  const DIMInputCustom_t      *pDIMInputCustom;      /*!< Custom DIM input                    */
  #endif 
  #if ((MEDIC_CFG_HYPOTHESIS_EVAL_AND_DECISION) || (MEDIC_CFG_INCLUDE_UNUSED_INTF))
  const HypothesisIntf_t      *pFCTCDHypotheses;     /*!< CD hypotheses                       */
  #endif
  #if ((MEDIC_CFG_HYPOTHESIS_EVAL_AND_DECISION) || (MEDIC_CFG_INCLUDE_UNUSED_INTF))
  const HEADInputGeneric_t    *pHEADInputGeneric;    /*!< Generic HEAD input                  */
  const HEADInputCustom_t     *pHEADInputCustom;     /*!< Custom HEAD input                   */
  #endif
  #if ((MEDIC_CFG_CPAR_PARAMS) || (MEDIC_CFG_INCLUDE_UNUSED_INTF))
  const CPAR_FCT_Parameters_t *pCPAR_FCT_Parameters; /*!< FCT Coding Parameters               */
  #endif
  #if ((MEDIC_CFG_VEH_SIG_INPUT) || (MEDIC_CFG_INCLUDE_UNUSED_INTF))
  const VehSig_t              *pVehSig;              /*!< Direct access to vehicle signals    */
  #endif
  #if ((MEDIC_CFG_BSW_ALGO_PARAMS) || (MEDIC_CFG_INCLUDE_UNUSED_INTF))
  const BSW_s_AlgoParameters_t *pBswAlgoParameters; /*!< Input algo parameters from BSW       */
  #endif
  #if ((MEDIC_CFG_CUSTOMINPUT) || (MEDIC_CFG_INCLUDE_UNUSED_INTF))
  const FCTVehCustomInput_t    *pFctVehCustInput;   /*!< Custom input for FCT_VEH             */
  #endif
} reqMEDICPtrList_t;
#endif 

/*****************************************************************************
  CONSTANTS (COMPONENT EXTERN)
*****************************************************************************/

/*****************************************************************************
  VARIABLES (COMPONENT EXTERN)
*****************************************************************************/

/*****************************************************************************
  FUNCTIONS (COMPONENT EXTERN)
*****************************************************************************/

#if (MEDIC_ARCHITECTURE_VERSION < 0x10)
extern void MEDIC_v_Exec(const reqMEDICPtrList_t * p_MedicRequirePorts, 
                         proMEDICPtrList_t * p_MedicProvidePorts 
                         #if (MEDIC_CFG_USE_SERVICE_POINTER_FUNCTS)
                         ,const AS_t_ServiceFuncts *p_ServiceFuncts
                         #endif
                         #if (!MEDIC_CFG_USE_MEDIC_INTERNAL_MEMORY)
                         ,MEDIC_ProcMem_t    const * const p_MedicProcMem
                         #endif
                        );
#endif

/*****************************************************************************
  INCLUDES
*****************************************************************************/
#include "frame_medic/medic_memory_interface.h"
#include "frame_medic/medic_access_func.h"

/*****************************************************************************
  FUNCTIONS (COMPONENT EXTERN)
*****************************************************************************/
#ifdef MEDIC_SIMU
extern void MEDIC_v_SetSimulationOutputCallback(void (*func)(MEDICAccessData_t*));
#endif


#ifdef __cplusplus
};
#endif
#endif
#endif /*!< MEDIC_EXT_INCLUDED */

