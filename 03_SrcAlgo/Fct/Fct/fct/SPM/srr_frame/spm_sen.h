/*! \file **********************************************************************

  COPYRIGHT (C) CONTINENTAL

  $FILENAME:                 spm_sen.h $

  $PROJECT:                  SRR5xx $

  $DESCRIPTION:              SPM component intern header FCT_SEN $

  LAST REVISION:             $Revision: 1.3 $

  LAST AUTHOR:               $Author: Pallo, Istvan (palloi) $

  ---*/ /*---
  CHANGES:                   $Log: spm_sen.h  $
  CHANGES:                   Revision 1.3 2020/06/26 09:54:08CEST Pallo, Istvan (palloi) 
  CHANGES:                   Fix devgate compile errors
  CHANGES:                   Revision 1.2 2020/06/25 18:10:21CEST Pallo, Istvan (palloi) 
  CHANGES:                   Remove unused globals and unused functions
  CHANGES:                   Revision 1.1 2020/06/25 07:02:33CEST Pallo, Istvan (palloi) 
  CHANGES:                   Initial revision
  CHANGES:                   Member added to project /ADAS/SW/Components/SPM_SensorPerformanceMonitoring/04_Engineering/01_Source_Code/SPM/srr_frame/project.pj


**************************************************************************** */
#pragma once 

/* Bedingte Einbindung */
#ifndef SPM_SEN_H_INCLUDED
#define SPM_SEN_H_INCLUDED

/* Additional check to assure that the FCT pars running in two different task
contexts do not try to access the same data - possibly corrupting each other's
states, leading to reproducibility issues in simulation */
#if defined(_FCT_VEH_H_INCLUDED)
#error fct_sen.h and fct_veh.h shall not be included in the same context!
#endif


/*
  @defgroup SPM_SEN Function

  Receives input data as explicit parameter passed to the main SPMSen_Exec
  function. This function also gets pointers to all output parameters.

    \todo : revise naming of functions and component itself.

use assertions to check critical conditions - only in simulation */
#define __SPM_ASSERT SPM_ASSERT
#if (defined(WIN32) && !defined(__PDO__))
#define SPM_ASSERT(cond) assert(cond)
#else
#define SPM_ASSERT(cond) ((void)0)
#endif


/* define to remove static declaration when building source code for unit test */
/************************************************************************************/
/* date: 2018-05-08, reviewer: M. Musat, reason:                                    */
/* The #define of static is on purpose so that functions can be declared non-static */
/* during unit test                                                                 */
/************************************************************************************/
/* PRQA S 3414 L1 */
#if defined(BUILD_WITH_UNIT_TEST)
#define ALGO_STATIC
#else
#define ALGO_STATIC static
#endif
/* PRQA L:L1 */
/*****************************************************************************
  INCLUDES
*****************************************************************************/
#include "spm_cfg.h"
#include "spm_types.h"
#include "spm_ver.h"

#if(SPM_SRR_TECHNOLOGY == SWITCH_ON)
#include "spm_access_macros.h"
#include "spm_sen_ext.h"


#ifndef COURAGE_TEST
#include "ga_spm_wrapper.h"
#else
#include "RTE_Cougate.h"
#endif
#include "cml_ext.h"
/*****************************************************************************
  INLINE FUNCTIONS / MACROS
*****************************************************************************/

/* includes for access macros and inline functions */


/*****************************************************************************
  MACROS
*****************************************************************************/


#define SPM_MEAS_FUNC_ID                         TASK_ID_ALGO_SEN_CYCLE
/*! The FCT-Sen FuncChannelID used for meas-freezes */
#define SPM_MEAS_FUNC_CHAN_ID                    TASK_ID_ALGO_SEN_CYCLE
/*****************************************************************************
  TYPEDEFS
*****************************************************************************/
/*! Type used for storing CROSS component version */
typedef uint32 SPMSwVersion_t;

/*! operating modes of component */
typedef enum {
  SPM_SEN_INIT,       /*!< initialize all    */
  SPM_SEN_RUN,        /*!< normal processing */
  SPM_SEN_SHUTDOWN,   /*!< shutdown (system in error) */
  SPM_SEN_ERROR,      /*!< fatal error, no recovery*/
  SPM_SEN_PAUSE       /*!< pause processing  */
} SPMSenState_t;

/*! The function frame @VADDR:FCT_MEAS_ID_SEN_FRAME_DATA @VNAME:SPMSenFrameData @CYCLEID: FCT_ENV */
typedef struct {
  AlgoCycleCounter_t  uiCycleCounter;    /*!< The FCT_SEN cycle counter */
  boolean             bFirstCycleDone;   /*!< Boolean showing if first cycle was done */
  SPM_OpMode          eSPMOpMode;        /*!< SPM requested operation mode */
  SPMSenState_t       eSPMState;         /*!< SPM current operation mode */
  SPMSwVersion_t      Version;           /*!< SPM versions */
  fTime_t             fCycleTime;        /*!< Cycle time got from PRIME*/
} SPM_SenFrame_t;

/*****************************************************************************
  TYPEDEFS (KOMPONENTENEXTERN)
*****************************************************************************/


/*****************************************************************************
  (SYMBOLIC) CONSTANTS
*****************************************************************************/

/*****************************************************************************
  VARIABLES
*****************************************************************************/

/*! FCT_SEN frame (cycle time, cycle counter, opmode ...) */
extern SPM_SenFrame_t SPMFrameData;

/* Meas freeze reference */
extern SpmWrapperSyncRefSPM_Exec SPMSenSyncRef;


/*****************************************************************************
  FUNCTION
*****************************************************************************/

/*! set states of subcomponents according to SPM_OP_MODE */
ALGO_STATIC void SPM_v_ProcessStates(SPM_OpMode eOpMode);

#if(SPM_USE_SERVICE_POINTER_FUNCTS == SWITCH_ON)
ALGO_STATIC void SPM_v_CheckPorts(const SpmReqPortsSPM_Exec * reqPorts, const SpmProPortsSPM_Exec * proPorts, const SPM_Services_SPM_EXEC * services);
#else
ALGO_STATIC void SPM_v_CheckPorts(const SpmReqPortsSPM_Exec *reqPorts, const SpmProPortsSPM_Exec * proPorts);
#endif

//init frame data
ALGO_STATIC void SPM_v_AlgoInit(void);

//init error out
ALGO_STATIC void SPM_v_InitErrorOut(SPM_t_SenErrorOutType * pErrorOut);

//set provide ports headers
ALGO_STATIC void SPM_v_SetProPortsHeader(const SpmReqPortsSPM_Exec * reqPorts, const SpmProPortsSPM_Exec * proPorts);

//pre process
ALGO_STATIC void SPM_v_PreProcess(const SpmReqPortsSPM_Exec * reqPorts, const SpmProPortsSPM_Exec * proPorts);

//post process
ALGO_STATIC void SPM_v_PostProcess(const SpmReqPortsSPM_Exec * reqPorts, const SpmProPortsSPM_Exec * proPorts);

//set signal header with specific signal status
ALGO_STATIC void SPM_v_FillSigHeaderNoHeader(SignalHeader_t * const pSigHeader, const SignalHeader_t *pSourceHdr, SigState_t eSigStatus);

//set signal header based on other port signal header
ALGO_STATIC void SPM_v_FillSigHeaderSigStatus(SignalHeader_t * const pSigHeader,const SignalHeader_t * pSourceHdr, SigState_t eSigStatus);

//set SPM version on provide ports
ALGO_STATIC void SPM_v_SetVersion(const SpmProPortsSPM_Exec * proPorts);

//set provide ports sig header based on SPM state
ALGO_STATIC void SPM_v_SetProPortsSigHeader(const SpmReqPortsSPM_Exec * reqPorts,const SpmProPortsSPM_Exec * proPorts, SigState_t sigState);
#endif //SPM_SRR_TECHNOLOGY

#endif
/* END of #ifndef SPM_SEN_H_INCLUDED */

