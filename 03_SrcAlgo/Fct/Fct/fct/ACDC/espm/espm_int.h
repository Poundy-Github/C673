/*! \file **********************************************************************

COMPANY:                   COPYRIGHT (C) Continental AG
  
PROJECT:                   Mainstream

CPU:                       CPU-Independent

COMPONENT:                 ESPM (EBA Signal Performance Monitoring)

PACKAGENAME:               espm_int.h

DESCRIPTION:               Internal header file for EBA Signal Performance Monitoring (ESPM) module

AUTHOR:                    $Author: uidn4751 $

CREATION DATE:             $Date: 2019/06/03 15:27:32CEST $

VERSION:                   $Revision: 1.13 $
**************************************************************************** */

#ifndef ESPM_INCLUDED
#define ESPM_INCLUDED



/*****************************************************************************
  INCLUDES
*****************************************************************************/
#include "acdc_int.h"

#if (ACDC_CFG_ESPM)

/*****************************************************************************
  MODULE DESCRIPTION
*****************************************************************************/
/**
@addtogroup espm
@{ */


#ifdef __cplusplus
extern "C" {
#endif

/*****************************************************************************
  SYMBOLIC CONSTANTS (COMPONENT INTERN)
*****************************************************************************/
#define ESPM_F_DELTA (0.000001f)

  /* Meas Freeze ID */
#ifndef  FCT_MEAS_ID_EBA_DEGRADATION_DATA
#define FCT_MEAS_ID_EBA_DEGRADATION_DATA (0x20273F00u) 
#endif

/*****************************************************************************
  MACROS (COMPONENT INTERN)
*****************************************************************************/


/*****************************************************************************
  TYPEDEFS (COMPONENT INTERN)
*****************************************************************************/

/*****************************************************************************
  CONSTANTS (COMPONENT INTERN)
*****************************************************************************/

/*****************************************************************************
  VARIABLES (COMPONENT INTERN)
*****************************************************************************/
  /*---espm_par.h globals---*/
  /*! Degradation parameters -> degradation distances*/
/*PRQA S 3432 8*/ /* date: 2019-05-15, reviewer: Schnurr, Clemens, reason: Macro does not work with paranthesis*/
ACDC_DECL_FIX_PARAM(MEMSEC_REF float32, ESPM_MAX_LAT_DIST_SAFE)
ACDC_DECL_FIX_PARAM(MEMSEC_REF float32, ESPM_MAX_LAT_DIST_PERF)
ACDC_DECL_FIX_PARAM(MEMSEC_REF float32, ESPM_MAX_LAT_DIST_SAFE_ALN)
ACDC_DECL_FIX_PARAM(MEMSEC_REF float32, ESPM_MAX_LAT_DIST_PERF_ALN)
ACDC_DECL_FIX_PARAM(MEMSEC_REF float32, ESPM_MAX_LAT_DIST_SAFE_VDY)
ACDC_DECL_FIX_PARAM(MEMSEC_REF float32, ESPM_MAX_LAT_DIST_PERF_VDY)
ACDC_DECL_FIX_PARAM(MEMSEC_REF float32, ESPM_PERF_ALN_MAX_QUOTA)
ACDC_DECL_FIX_PARAM(MEMSEC_REF float32, ESPM_PERF_VDY_MAX_QUOTA)

/*****************************************************************************
  FUNCTIONS (COMPONENT INTERN)
*****************************************************************************/

/*--- espm_degradation.c ---*/
extern void  ESPM_v_InitDegradationData(void);
extern void  ESPM_v_InitOutput(HypoIntfDegr_t  *pOutputData, ACDCErrorOutProPort_t *pErrorOut);
#if (ESPM_CFG_USE_SPM_OUTPUT)
extern void  ESPM_v_PerfDegradation(void);
#endif

extern void  ESPM_v_MeasFreezeDegradationData(void);
extern void  ESPM_v_FillOutputports(HypoIntfDegr_t  *pOutputData, ACDCErrorOutProPort_t *pErrorOut);

#ifdef __cplusplus
};
#endif


///@}
#endif /*!< ACDC_CFG_ESPM */

/* End of conditional inclusion */
#endif  /*!< ESPM_INCLUDED */

