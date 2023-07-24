/*! \file **********************************************************************

COMPANY:                   COPYRIGHT (C) Continental AG

PROJECT:                   Adaptive Cruise Control (ACC)

CPU:                       CPU-Independent

COMPONENT:                 ACC/LOHP (Adaptive Cruise Control - Longitudinal Headway Planner)

PACKAGENAME:               lohp_ext.h

DESCRIPTION:               External header file for LOHP

AUTHOR:                    Mistry Niraj (uidq5738)

CREATION DATE:             24.02.2017

VERSION:                   $Revision: 1.9 $

LEGACY VERSION:            Revision: 2.1

**************************************************************************** */

#ifndef LOHP_EXT_H_INCLUDED
#define LOHP_EXT_H_INCLUDED

/*****************************************************************************
  MODULE DESCRIPTION
*****************************************************************************/
/*!
@defgroup   lohp_ext_h Lohp_ext_h
@ingroup    lohp_base_lohp
@brief      External header file for LOHP base module
@{ */ 

/*****************************************************************************
  INCLUDES
*****************************************************************************/
#include "frame_lohp_ext.h"

#if ((FCT_CFG_ADAPTIVE_CRUISE_CONTROL) && (FCT_CFG_LOHP_COMPONENT))

#ifdef __cplusplus
extern "C" {
#endif

#if (FCT_CFG_ACC_HEADWAY_PLANNER)

/*****************************************************************************
  TYPEDEFS
*****************************************************************************/
  /*! Operating modes of sub-component headway planner (HP) Opmodes of FCA and DM are also pinned to the same */
typedef enum {
  HP_INIT,                /*!< Initialize all */
  HP_OK                   /*!< Normal processing */
} HPState_t;

/*****************************************************************************
  CONSTANTS
*****************************************************************************/

/*****************************************************************************
  VARIABLES
*****************************************************************************/
extern HPState_t HP_t_State;


/*****************************************************************************
  FUNCTIONS
*****************************************************************************/

extern void LOHP_v_Process(const times_t              cycle_time,
#if (FCT_CFG_SIGNAL_PERF_MONITORING)
                          const SysPerfMonStates_t    * pSysPerfMonStates,
#endif
                          const ALN_S_Monitoring_t    * pAlnMon,
#if (FCT_USE_EM_GENERIC_OBJECT_LIST)
                          const EM_t_GenObjectList    * pEmGenObjList,
#if (FCT_USE_EM_ARS_TECH_OBJECT_LIST)
                          const EM_t_ARSObjectList    * pEmARSObjList,
#endif
#else
                          const ObjectList_t          * pEmObjList,
#endif
                          const AssessedObjList_t     * pFctObjList,
                          const VehDyn_t              * pVehDyn,
#if (FCT_SEN_CFG_VEH_SIG_INPUT)
                          const VehSig_t              * pVehSig,
#endif
#if (FCT_CFG_SLATE_COMPONENT)
                          const SLATE_HC_Data_t       * pSLATEData,
#endif
#if (FCT_CFG_CUSTOM_IO_INTERFACE)
                          const FCTCustomInput_t      * pCustomInput,
#if (FCT_CFG_CUSTOM_IO_ABS_KINEMATIC)
                          const FCTCustomOutput_t     * pCustomOutputInput,
#endif
#endif
                          const FctVeh2SenInfo_t      * pFctVehLongOut,
#if (FCT_CFG_SEN2VEH_ACC_OOI_PORT)
                          const FCTSenAccOOI_t        * pFCTAccOOIData,
                          LOHP_ObjUsageState_t        * pLOHPUsageState,
#endif
                          acc_object_t                * pAccDisplayObj,
                          acc_output_data_t           * pAccOutput);

extern void HP_v_SetOperationMode(const HPState_t t_HPOpModeValue);

extern void LOHP_v_Init(acc_object_t* pAccDisplayObj, acc_output_data_t* pAccOutput, LOHP_ObjUsageState_t * pLOHPUsageState);

#endif /* FCT_CFG_ACC_HEADWAY_PLANNER */

#ifdef __cplusplus
};
#endif

#endif /*!< ((FCT_CFG_ADAPTIVE_CRUISE_CONTROL) && (FCT_CFG_LOHP_COMPONENT)) */

/** @} end defgroup */

#endif /* LOHP_EXT_H_INCLUDED */
