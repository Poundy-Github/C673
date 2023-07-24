/*! \file **********************************************************************

COMPANY:                   COPYRIGHT (C) Continental AG

PROJECT:                   Adaptive Cruise Control (ACC)

CPU:                       CPU-Independent

COMPONENT:                 ACC/LOPC (Adaptive Cruise Control - Longitudinal Planner and Controller)

PACKAGENAME:               frame_lopc_func.h

DESCRIPTION:               Definitions of inline functions to access global data in LOPC

AUTHOR:                    Mistry Niraj (uidq5738)

CREATION DATE:             24.02.2017

VERSION:                   $Revision: 1.11 $

LEGACY VERSION:            Revision: 1.1
**************************************************************************** */

#ifndef FRAME_LOPC_ACCESS_H_INCLUDED
#define FRAME_LOPC_ACCESS_H_INCLUDED

/*****************************************************************************
  MODULE DESCRIPTION
*****************************************************************************/
/*!
@defgroup   frame_lopc_accessfunc Frame_lopc_accessfunctions
@ingroup    lopc_base_frame
@brief      Access functions for LOPC
@{ */ 

/*****************************************************************************
  INCLUDES
*****************************************************************************/
#include "frame_lopc_types.h"
#include "frame_lopc_ext.h"

/* Only process rest of file if ACC enabled and long control enabled */
#if ((FCT_CFG_ADAPTIVE_CRUISE_CONTROL) && (FCT_CFG_LOPC_COMPONENT))


/*****************************************************************************
  EXTERN VARIABLES
*****************************************************************************/
extern MEMSEC_REF boolean b_LopcIsInitialized;

#if (FCT_CFG_ACT_CODE_VERSION == SWITCH_OFF)
/*! sub-module state */
extern MEMSEC_REF const VehDyn_t  * LOPC_pEgoDynRaw; /*!<internal pointer to external raw ego dynamics INPUT interface.*/
#if (FCT_VEH_CFG_VEH_SIG_INPUT)
extern MEMSEC_REF const VehSig_t  * LOPC_pVehSig;             /* Pointer to raw vehicle signals */
#endif

extern MEMSEC_REF const AccLeverInput_t       * LOPC_pAccLever;
extern MEMSEC_REF const LongCtrlInput_t       * LOPC_pLongCtrlResp;
#if ((FCT_CFG_ACC_HEADWAY_PLANNER) && (FCT_CFG_LOHP_COMPONENT))
extern MEMSEC_REF const acc_object_t          * LOPC_pAccDisplayObj;
extern MEMSEC_REF const acc_output_data_t     * LOPC_pAccOutput;
extern MEMSEC_REF FctVeh2SenInfo_t            * LOPC_pFctVehLongOut;
#endif
extern MEMSEC_REF LongCtrlOutput_t            * LOPC_pLongCtrlOutput;
#if (FCT_CFG_TCI)
extern MEMSEC_REF const TCIInput_t            * LOPC_pTCIInput;
extern MEMSEC_REF TCIOutput_t                 * LOPC_pTCIOutput;
#endif
#if (FCT_CFG_SLA_FEATURE)
extern MEMSEC_REF const SLAData_t             * LOPC_pSLAData;
#endif
#if (FCT_CFG_SEN2VEH_ACC_OOI_PORT)
extern MEMSEC_REF const FCTSenAccOOI_t        * LOPC_pAccOOIData;
#endif
#if (FCT_VEH_CFG_CUSTOMINPUT)
extern MEMSEC_REF const FCTVehCustomInput_t   * LOPC_pFctVehCustInput;
#endif
#if (FCT_CFG_BSW_ALGO_PARAMS)
extern MEMSEC_REF const BSW_s_AlgoParameters_t * LOPC_pBswAlgoParameters;
#endif
#if (FCT_CFG_USE_ALGOCOMPSTATE)
extern MEMSEC_REF AlgoCompState_t              * LOPC_pCompState;
#endif 
#if (FCT_CFG_ERROR_OUTPUT_VEH)
extern MEMSEC_REF LOPCErrorOut_t               * LOPC_pErrorOut;  
#endif
#if (FCT_VEH_CFG_CUSTOMOUTPUT)
extern MEMSEC_REF FCTVehOutArbitrated_t        * LOPC_pFctVehOutArbitrated;
#endif

#if (FCT_VEH_CFG_USE_LODMC_OUTPUT)
extern MEMSEC_REF const Lodmc_output_t * LOPC_pLoDmcOut;
#endif

#if (FCT_VEH_CFG_LOPC_SM_USE_EBA_OUTPUT)
extern MEMSEC_REF const HEADOutputCustom_t * LOPC_pHeadOutputCustom;
#endif

#else  /* FCT_CFG_ACT_CODE_VERSION */

#if (FCT_CFG_HP_TFC_PORT_CNT)
  extern MEMSEC_REF TargetFollowStatePort_t     *pt_LOPC_OUT_HP_TFSP;
#endif

#endif /* FCT_CFG_ACT_CODE_VERSION */

/*!< Static Memory for LOPC component containing Framedata and Syncrefs*/
extern MEMSEC_REF lopc_static_mem_t LOPC_STATIC_MEMORY;

/*****************************************************************************
  INLINE FUNCTIONS
*****************************************************************************/

/* Deactivate QA-C warning 3406; Reviewer: S. Schwarzkopf; Date: 05.12.2014; 
   Reason: Styleguide specifies this as best practice (R231, R238) and 
   ALGO_INLINE is defined compiler dependent for inlining with internal linkage.
   Review-ID: */
/* PRQA S 3406 ALGO_INLINES */
/**************/
#if (FCT_CFG_ACT_CODE_VERSION)
/* Todo: Write for new ports */

#else /* Legacy code */

/* Check if we are in QA-C: PRQA_SIZE_T is defined in QA-C environment. */
#ifdef PRQA_SIZE_T
  /* Switch off QA-C warnings on side effects for functions, which don't have 
     any side effects and will sure never have some. */
#pragma PRQA_NO_SIDE_EFFECTS LOPC_p_GetVDYDynRaw
#pragma PRQA_NO_SIDE_EFFECTS LOPC_pf_GetEgoLongVel
#pragma PRQA_NO_SIDE_EFFECTS LOPC_pf_GetEgoLongAccel
#pragma PRQA_NO_SIDE_EFFECTS LOPC_pt_GetBswAlgoParameters
#endif /* ifdef PRQA_SIZE_T */

ALGO_INLINE VehDyn_t const *  LOPC_p_GetVDYDynRaw(void);
ALGO_INLINE float32 LOPC_f_GetEgoLongVel(void);
ALGO_INLINE float32 LOPC_f_GetEgoLongAccel(void);
ALGO_INLINE BSW_s_AlgoParameters_t const * LOPC_pt_GetBswAlgoParameters(void);


/************************************************************************/
/* VDY signals                                                          */
/************************************************************************/

/*************************************************************************************************************************
  Functionname:    LOPC_p_GetVDYDynRaw                                                                              */ /*!
  @brief           Returns VehDyn_t const *
  @return          VehDyn_t const *
  @traceability    doors://rbgs854a:40000/?version=2&prodID=0&view=00000002&urn=urn:telelogic::1-503e822e5ec3651e-O-141-0008a220
  @author          Andreas Kramer |  | +49 (8382) 9699-246
*************************************************************************************************************************/
ALGO_INLINE VehDyn_t const *  LOPC_p_GetVDYDynRaw(void)
{
  return LOPC_pEgoDynRaw;
}

/*************************************************************************************************************************
  Functionname:    LOPC_f_GetEgoLongVel                                                                            */ /*!

  @brief           Inline function for accessing the ego longitudinal velocity
  @return          Ego longitudinal velocity
  @param[in]       -
  @created         28.03.2017
  @traceability    doors://rbgs854a:40000/?version=2&prodID=0&view=00000002&urn=urn:telelogic::1-503e822e5ec3651e-O-142-0008a220
  @author          Niraj Mistry | niraj.mistry@continental-corporation.com | +49 (8382) 9699-5631
*************************************************************************************************************************/
ALGO_INLINE float32 LOPC_f_GetEgoLongVel(void)
{
  float32 f_EgoLongVel;
#if (VDY_VEH_DYN_INTFVER >= 0x20)   // 0x20 -> 18
  f_EgoLongVel = LOPC_pEgoDynRaw->Longitudinal.Velocity;
#else
  f_EgoLongVel = LOPC_pEgoDynRaw->Longitudinal.MotVar.Velocity;
#endif
  return f_EgoLongVel;
}

/*************************************************************************************************************************
  Functionname:    LOPC_f_GetEgoLongAccel                                                                          */ /*!

  @brief           Inline function for accessing the ego longitudinal acceleration
  @return          Ego longitudinal acceleration
  @param[in]       -
  @created         28.03.2017
  @traceability    doors://rbgs854a:40000/?version=2&prodID=0&view=00000002&urn=urn:telelogic::1-503e822e5ec3651e-O-143-0008a220
  @author          Niraj Mistry | niraj.mistry@continental-corporation.com | +49 (8382) 9699-5631
*************************************************************************************************************************/
ALGO_INLINE float32 LOPC_f_GetEgoLongAccel(void)
{
  float32 f_EgoLongAccel;
#if (VDY_VEH_DYN_INTFVER >= 0x20)   // 0x20 -> 18
  f_EgoLongAccel = LOPC_pEgoDynRaw->Longitudinal.Accel;
#else
  f_EgoLongAccel= LOPC_pEgoDynRaw->Longitudinal.MotVar.Accel;
#endif
  return f_EgoLongAccel;
}

/*************************************************************************************************************************
  Functionname:    LOPC_pt_GetBswAlgoParameters                                                                     */ /*!

  @brief           Inline function for accessing the pointer to input algo parameters from BSW
  @return          Reference to input algo parameters from BSW
  @param[in]       -
  @created         28.03.2017
  @traceability    doors://rbgs854a:40000/?version=2&prodID=0&view=00000002&urn=urn:telelogic::1-503e822e5ec3651e-O-144-0008a220
  @author          Niraj Mistry | niraj.mistry@continental-corporation.com | +49 (8382) 9699-5631
*************************************************************************************************************************/
ALGO_INLINE BSW_s_AlgoParameters_t const * LOPC_pt_GetBswAlgoParameters(void)
{
  return LOPC_pBswAlgoParameters;
}
/* PRQA L:ALGO_INLINES */


#endif /* FCT_CFG_ACT_CODE_VERSION */

#endif /*!< (FCT_CFG_ADAPTIVE_CRUISE_CONTROL) && (FCT_CFG_LOPC_COMPONENT) */

/** @} end defgroup */

#endif /* ifndef FRAME_LOPC_ACCESS_H_INCLUDED */
