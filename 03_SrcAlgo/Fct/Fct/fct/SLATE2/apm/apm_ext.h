/*! \file **********************************************************************

COMPANY:                   COPYRIGHT (C) Continental AG

PROJECT:                   Adaptive Cruise Control (ACC)

CPU:                       CPU-Independent

COMPONENT:                 Adaptive Cruise Control (ACC)

PACKAGENAME:               apm_ext.h

DESCRIPTION:               External header file for ACC Performance Monitoring (APM) module in FCT_SEN task

AUTHOR:                    Boll Marie-Theres (uidu1091)

CREATION DATE:             21.10.2016

VERSION:                   $Revision: 1.9 $

LEGACY VERSION:            Revision: 2.0

**************************************************************************** */

#ifndef APM_EXT_INCLUDED
#define APM_EXT_INCLUDED


/*****************************************************************************
  INCLUDES
*****************************************************************************/

#include "apm_cfg.h"
#include "apm_ver.h"
#include "slate_ext.h"

#if (SLATE_CFG_ACC_PERF_MONITORING)

#ifdef __cplusplus
extern "C" {
#endif

/*****************************************************************************
  MODULE DESCRIPTION
*****************************************************************************/
/**
@addtogroup apm
@{ */


/*****************************************************************************
  SYMBOLIC CONSTANTS (COMPONENT EXTERN)
*****************************************************************************/


/*****************************************************************************
  MACROS (COMPONENT EXTERN)
*****************************************************************************/


/*****************************************************************************
  TYPEDEFS (COMPONENT EXTERN)
*****************************************************************************/
//
//typedef struct APM_Data
//{
//  /*********************/
//  /* Interference data */
//  /*********************/
//  boolean SPMInterferenceState; // apm.h
//  float32 SPMInterferenceRange; // apm.h
//  uint32 SPMInterference;
//  uint32 SPMInterferenceHoldCnt;
//
//
//  /*********************/
//  /*ARS4xx Degradation*/
//  /*********************/
//  //uint32 SPMDegradationACC;
//  //SPM_t_a_Degradation a_DegradationACC;
//  //SPM_t_a_Degradation a_DegradationEBA;
//
//} APM_Data_t;

/*****************************************************************************
  CONSTANTS (COMPONENT EXTERN)
*****************************************************************************/


/*****************************************************************************
  VARIABLES (COMPONENT EXTERN)
*****************************************************************************/

//extern MEMSEC_REF APMState_t t_APM_State;

/*****************************************************************************
  FUNCTIONS (COMPONENT EXTERN)
*****************************************************************************/

/*--- amp_main.c ---*/
extern void APM_v_Process(void);
#if (FCT_CFG_ERROR_OUTPUT_SEN)
extern void APM_v_FillSenErrors(SLATEErrorOutProPort_t * pDest);
#endif /* END IF (FCT_CFG_ERROR_OUTPUT_SEN) */
extern void APM_v_SetOperationMode(SLATECompState_t const t_APMOpModeValue);

/*--- apm_degradation.c ---*/
extern fDistance_t APM_f_GetMaxDistSafeACC(void); // unused
//extern fDistance_t SPM_f_GetMaxDistSafeEBA(void);
extern fDistance_t APM_f_GetMaxDistPerfACC(void); // unused
//extern fDistance_t SPM_f_GetMaxDistPerfEBA(void);
extern fDistance_t APM_f_GetMaxDistPerfMinACC(void);
//extern fDistance_t SPM_f_GetMaxDistPerfMinEBA(void);
//extern fDistance_t SPM_f_GetMaxDistSafeALN(void);
//extern fDistance_t SPM_f_GetMaxDistPerfALN(void);
extern fDistance_t APM_f_GetMaxDistSafeACC_ALN(void); // unused
extern fDistance_t APM_f_GetMaxDistPerfACC_ALN(void);

#ifdef __cplusplus
};
#endif
///@}
#endif /*!< SLATE_CFG_ACC_PERF_MONITORING */

/* End of conditional inclusion */
#else

#endif  /*!< _APM_EXT_INCLUDED */

