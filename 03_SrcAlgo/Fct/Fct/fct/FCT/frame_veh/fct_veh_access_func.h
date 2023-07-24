/*! \file **********************************************************************

COMPANY:                   COPYRIGHT (C) Continental AG

PROJECT:                   Mainstream

CPU:                       CPU-Independent

COMPONENT:                 FCTVEH (Frame Vehicle)

MODULNAME:                 fct_veh_access_func.h

DESCRIPTION:               Definitions for inline functions to access glocal data for vehicle frame

AUTHOR:                    Mistry Niraj (uidq5738)

CREATION DATE:             24.02.2017

VERSION:                   $Revision: 1.13 $

LEGACY VERSION:            Revision: 1.4

*****************************************************************************/
#ifndef FCT_VEH_ACCESS_H_INCLUDED
#define FCT_VEH_ACCESS_H_INCLUDED

/************************************************************************/
/*                           INCLUDES                                   */
/************************************************************************/
#include "fct_par.h"
#include "fct_veh_ext.h"
/**
@addtogroup frame_veh
@{ */


/************************************************************************/
/*                     GLOBAL VARIABLES                                 */
/************************************************************************/
#if (FCT_CFG_USE_SERVICE_POINTER_FUNCTS)
extern MEMSEC_REF const AS_t_ServiceFuncts *pFCTVehServiceFuncts;
#endif
extern MEMSEC_REF const VehDyn_t               * FCTVEH_pEgoDynRaw;      
#if (FCT_VEH_CFG_VEH_PAR_INPUT)
extern MEMSEC_REF const VehPar_t               * FCTVEH_pGlobEgoStatic;  /* The static vehicle ego data */
#endif
#if (FCT_CFG_CD_CUSTOM_OUTPUT_INTERFACE)
extern MEMSEC_REF FCTCDOutputCustom_t          * FCTSEN_pCDCustomOutput; /* CD custom output data */
#endif
#if (FCT_CFG_VEH_HMI_INTERFACE)
extern MEMSEC_REF const t_HMI_Data_t           * FCT_pHMIData;            /* HMI data output */
#endif

#if (FCT_VEH_CFG_ALIGNMENT_MONITORING_INPUT) 
extern MEMSEC_REF const ALN_S_Monitoring_t     * FCTVEH_pAlignmentMonInput; /*!< Alignment monitoring output data */
#endif  /* Provide ports */

#if (FCT_CFG_BSW_ALGO_PARAMS)
extern MEMSEC_REF const BSW_s_AlgoParameters_t * FCTVEH_pBswAlgoParameters;  /* Input algo parameters from BSW */
#endif
#if (FCT_VEH_CFG_EM_CLD_INPUT)
extern MEMSEC_REF const EM_CLD_Output_t        * FCTVEH_pEmCldOutput;        /* EM camera lane detection output */
#endif
#if (FCT_CFG_USE_BUS_DEBUG)
extern MEMSEC_REF BusDebugData_t              * FCTVEH_pEbaBusDebugData; /* Debug data */
#endif
#if (FCT_CFG_LOPC_COMPONENT)
#if (FCT_VEH_CFG_VEH_SIG_INPUT)
extern MEMSEC_REF const PowerTrain_t          * FCTVEH_pVehSigPowerTrain;
#else
#error FCT_CFG_LOPC_COMPONENT requires access to VehSigs PowerTrain sub-struct!
#endif
extern MEMSEC_REF const AccLeverInput_t       * FCTVEH_pAccLever;
extern MEMSEC_REF const LongCtrlInput_t       * FCTVEH_pLongCtrlResp;
extern MEMSEC_REF const acc_object_t          * FCTVEH_pAccDisplayObj;
extern MEMSEC_REF const acc_output_data_t     * FCTVEH_pAccOutput;
extern MEMSEC_REF FctVeh2SenInfo_t            * FCTVEH_pFctVehLongOut;
extern MEMSEC_REF LongCtrlOutput_t            * FCTVEH_pLongCtrlOutput;
#endif
#if (FCT_CFG_SEN2VEH_ACC_OOI_PORT)
extern MEMSEC_REF const FCTSenAccOOI_t        * FCTVEH_pAccOOIData;
#endif
#if (FCT_VEH_CFG_CUSTOMINPUT)
extern MEMSEC_REF const FCTVehCustomInput_t    * FCTVEH_pFctVehCustInput;
#endif
#if (FCT_VEH_CFG_CUSTOMOUTPUT)
extern MEMSEC_REF FCTVehOutArbitrated_t       * FCTVEH_pFCTVehOutArbitrated;
#endif

/*! frame (cycle time, cycle counter, opmode ...) */
extern MEMSEC_REF FCTVehFrame_t FCTVehFrame;

#if (FCT_CFG_USE_ALGO_SIGSTATE_INPUT_CHECK)
/*! Soft Error Counter to count init cycles of require ports  */
extern MEMSEC_REF FCTVehSoftErrorCounter_t FCTVehSoftErrorCounter;
#endif

#if (FCT_VEH_CFG_USE_LODMC_OUTPUT)
extern MEMSEC_REF const Lodmc_output_t      * FCTVEH_pLoDmcOutput;
#endif /* ENDIF FCT_VEH_CFG_USE_LODMC_OUTPUT */

/************************************************************************/
/*                      MACROS                                          */
/************************************************************************/
ALGO_INLINE VehDyn_t const *  FCTVeh_p_GetVDYDynRaw(void);
ALGO_INLINE float32 FCTVeh_f_GetEgoVelRaw(void);
ALGO_INLINE float32 FCTVeh_f_GetEgoAccelRaw(void);
#if (FCT_VEH_CFG_VEH_PAR_INPUT)
ALGO_INLINE VehPar_t const *  FCTVeh_p_GetVehPar(void);
#endif
ALGO_INLINE float32 FCTVeh_f_GetCycleTime(void);
ALGO_INLINE FCTVehFrame_t *  FCTVeh_p_GetFCTVehFrame(void);
#if (FCT_CFG_COLLISION_DETECTION)
ALGO_INLINE HypothesisIntf_t const *  FCTVeh_p_GetHypothesisIntf(void);
ALGO_INLINE Hypothesis_t const *  FCTVeh_p_GetHypothesis(sint32 iHyp);
ALGO_INLINE HypoIntfDegr_t const *  FCTVeh_p_GetHypDegradation(void);
#endif
#if (FCT_CFG_BSW_ALGO_PARAMS)
ALGO_INLINE BSW_s_AlgoParameters_t const *  FCTVeh_p_GetAlgoParameters(void);
#endif
#if (FCT_CFG_CPAR_PARAMS)
ALGO_INLINE CPAR_FCT_Parameters_t  const *  FCTSen_p_GetCPARFCTParameters(void);
#endif
#if (FCT_CFG_HYPOTHESIS_EVAL_AND_DECISION)
ALGO_INLINE HEADOutputCustom_t const *  FCTVeh_p_GetHeadOutCustom(void);
ALGO_INLINE HEADOutputGeneric_t *  FCTVeh_p_GetHeadOutGeneric(void);
ALGO_INLINE HEADInputGeneric_t const *  FCTVeh_p_GetHeadInGeneric(void);
ALGO_INLINE HEADInputCustom_t const *  FCTVeh_p_GetHeadInCustom(void);
#endif

#if (FCT_CFG_DRIVER_INTENTION_MONITORING)
ALGO_INLINE DIMOutputCustom_t             *  FCTVeh_p_GetDIMOutCustom(void);
ALGO_INLINE DIMInputCustom_t        const *  FCTVeh_p_GetDIMInCustom(void);
ALGO_INLINE DIMInputGeneric_t      const  *  FCTVeh_p_GetDIMInGeneric(void);
#endif
#if (FCT_CFG_VEH_HMI_INTERFACE)
ALGO_INLINE t_HMI_Data_t      const  *  FCTVeh_p_GetHMIInput(void);
#endif

#if (FCT_VEH_CFG_USE_LODMC_OUTPUT)
ALGO_INLINE Lodmc_output_t const *  FCTVeh_p_GetLodmcOutput(void);
#endif  /*  FCT_VEH_CFG_USE_LODMC_OUTPUT  */

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

/*****************************************************************************
  INLINE FUNCTIONS
*****************************************************************************/

/* Deactivate QA-C warning 3406; Reviewer: S. Schwarzkopf; Date: 05.12.2014; 
   Reason: Styleguide specifies this as best practice (R231, R238) and 
   ALGO_INLINE is defined compiler dependent for inlining with internal linkage.
   Review-ID: */
/* PRQA S 3406 ALGO_INLINES */
/**************/



/************************************************************************/
/* VDY signals                                                          */
/************************************************************************/

/*************************************************************************************************************************
  Functionname:    FCTVeh_p_GetVDYDynRaw                                                                            */ /*!
  @brief           Returns VehDyn_t const *
  @return          VehDyn_t const *
  @author          Andreas Kramer |  | +49 (8382) 9699-246
*************************************************************************************************************************/
ALGO_INLINE VehDyn_t const *  FCTVeh_p_GetVDYDynRaw(void)
{
  return FCTVEH_pEgoDynRaw;
}

/*************************************************************************************************************************
  Functionname:    FCTVeh_f_GetEgoVelRaw                                                                            */ /*!
  @brief           Returns float32
  @return          float32
  @author          Andreas Kramer |  | +49 (8382) 9699-246
*************************************************************************************************************************/
ALGO_INLINE float32 FCTVeh_f_GetEgoVelRaw(void)
{
#if (VDY_VEH_DYN_INTFVER >= 32)
  return FCTVeh_p_GetVDYDynRaw()->Longitudinal.Velocity;
#else
  return FCTVeh_p_GetVDYDynRaw()->Longitudinal.MotVar.Velocity;
#endif
}

/*************************************************************************************************************************
  Functionname:    FCTVeh_f_GetEgoAccelRaw                                                                          */ /*!
  @brief           Returns float32
  @return          float32
  @author          Andreas Kramer |  | +49 (8382) 9699-246
*************************************************************************************************************************/
ALGO_INLINE float32 FCTVeh_f_GetEgoAccelRaw(void)
{
#if (VDY_VEH_DYN_INTFVER >= 32)
  return FCTVeh_p_GetVDYDynRaw()->Longitudinal.Accel;
#else
  return FCTVeh_p_GetVDYDynRaw()->Longitudinal.MotVar.Accel;
#endif
}

#if (FCT_VEH_CFG_VEH_PAR_INPUT)
/************************************************************************/
/* Vehicle parameter                                                    */
/************************************************************************/
/*************************************************************************************************************************
  Functionname:    FCTVeh_p_GetVehPar                                                                               */ /*!
  @brief           Returns VehPar_t const *
  @return          VehPar_t const *
  @author          Andreas Kramer |  | +49 (8382) 9699-246
*************************************************************************************************************************/
ALGO_INLINE VehPar_t const *  FCTVeh_p_GetVehPar(void)
{
  return FCTVEH_pGlobEgoStatic;
}
#endif


/************************************************************************/
/* Misc                                                                 */
/************************************************************************/
/*************************************************************************************************************************
  Functionname:    FCTVeh_p_GetCycleTime                                                                            */ /*!
  @brief           Returns float32
  @return          float32
  @author          Andreas Kramer |  | +49 (8382) 9699-246
*************************************************************************************************************************/
ALGO_INLINE float32 FCTVeh_f_GetCycleTime(void)
{
  /* Todo: Use calculated cycle time instead */
  return (FCT_VEH_CYCLE_TIME);
}
/*************************************************************************************************************************
  Functionname:    FCTVeh_p_GetFCTVehFrame                                                                          */ /*!
  @brief           Returns FCTVehFrame_t *
  @return          FCTVehFrame_t *
  @author          Andreas Kramer |  | +49 (8382) 9699-246
*************************************************************************************************************************/
ALGO_INLINE FCTVehFrame_t *  FCTVeh_p_GetFCTVehFrame(void)
{
  return &FCTVehFrame;
}



/************************************************************************/
/* Parameter                                                            */
/************************************************************************/
#if (FCT_CFG_BSW_ALGO_PARAMS)
/*************************************************************************************************************************
  Functionname:    FCTVeh_p_GetAlgoParameters                                                                       */ /*!
  @brief           Returns BSW_s_AlgoParameters_t const *
  @return          BSW_s_AlgoParameters_t const *
  @author          Andreas Kramer |  | +49 (8382) 9699-246
*************************************************************************************************************************/
ALGO_INLINE BSW_s_AlgoParameters_t const *  FCTVeh_p_GetAlgoParameters(void)
{
  return FCTVEH_pBswAlgoParameters;
}
#endif

#if (FCT_CFG_VEH_HMI_INTERFACE)
/************************************************************************/
/* HMI                                                                  */
/************************************************************************/
/*************************************************************************************************************************
  Functionname:    FCTVeh_p_GetHMIInput                                                                             */ /*!
  @brief           Returns t_HMI_Data_t      const  *
  @return          t_HMI_Data_t      const  *
  @author          Andreas Kramer |  | +49 (8382) 9699-246
*************************************************************************************************************************/
ALGO_INLINE t_HMI_Data_t      const  *  FCTVeh_p_GetHMIInput(void)
{
  return FCT_pHMIData;
}
#endif

#if (FCT_VEH_CFG_USE_LODMC_OUTPUT)
ALGO_INLINE Lodmc_output_t const *  FCTVeh_p_GetLodmcOutput(void)
{
  return FCTVEH_pLoDmcOutput;
}
#endif  /* (FCT_VEH_CFG_USE_LODMC_OUTPUT)  */
/* PRQA L:ALGO_INLINES */

#endif
