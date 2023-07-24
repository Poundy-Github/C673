/*! \file **********************************************************************

COMPANY:                   COPYRIGHT (C) Continental AG

PROJECT:                   Adaptive Cruise Control (ACC)

CPU:                       CPU-Independent

COMPONENT:                 Adaptive Cruise Control (ACC)

PACKAGENAME:               apm_main.c

DESCRIPTION:               Main functions for ACC Performance Monitoring (APM) Processing in FCT_SEN task

AUTHOR:                    Boll Marie-Theres (uidu1091)

CREATION DATE:             21.10.2016

VERSION:                   $Revision: 1.10 $

LEGACY VERSION:            Revision: 2.0

**************************************************************************** */

/*****************************************************************************
  INCLUDES
*****************************************************************************/

#include "apm.h"//PRQA S 0380 
/* date: 2019-07-28, reviewer:Prabhu Sundaramurthy, reason: Arises due to inclusion of multiple header files in this header file which has multiple macros*/

#if (SLATE_CFG_ACC_PERF_MONITORING)

/*****************************************************************************
  MODULE DESCRIPTION
*****************************************************************************/

/**
@defgroup apm_main Main
@ingroup apm
@brief          This module provides amongst others the main function of the SLATE Component. \n\n

@description    The following functionalities are provided by this module:
                - Main function to call all ACC Performance Monitoring (APM) functionalities
                - Set APM error state: Set given error state for given APM error type in APM error state struct
				- Set ACC error output structure based on APM errors for FCT_SEN task
				- Initialize APM static data in APM init operation mode
				- Set operation mode of APM sub-component
@{
*/

/*****************************************************************************
  GLOBAL CONSTANTS (MODULE SCOPE)
*****************************************************************************/


/*****************************************************************************
  GLOBAL VARIABLES (MODULE SCOPE)
*****************************************************************************/

SET_MEMSEC_VAR(t_APM_State)
static SLATECompState_t t_APM_State;       /*!< Operating mode of APM sub-component */

/*****************************************************************************
  LOCAL SYMOBLIC CONSTANTS
*****************************************************************************/


/*****************************************************************************
  LOCAL MACROS
*****************************************************************************/


/*****************************************************************************
  LOCAL TYPES
*****************************************************************************/


/*****************************************************************************
  LOCAL CONSTANTS
*****************************************************************************/


/*****************************************************************************
  LOCAL TYPEDEFS
*****************************************************************************/


/*****************************************************************************
  LOCAL VARIABLES
*****************************************************************************/

/*! APM error states */
SET_MEMSEC_VAR(t_APMErrStates)
static AlgoErrorState_t t_APMErrStates[APM_ERREV_NUM_ERRORS];


/*****************************************************************************
  FUNCTION PROTOTYPES
*****************************************************************************/

static void APM_v_Init(void);

/*****************************************************************************
  FUNCTION DEFINITIONS
*****************************************************************************/


/*************************************************************************************************************************
  Functionname:    APM_v_Process                                                                                    */ /*!

  @brief           Main function to call all ACC Performance Monitoring (APM) functionalities

  @description     Main function to call all ACC Performance Monitoring (APM) functionalities based on
                   APM operation mode:
                      - Process interference range
                      - Process degradation based on ALN and VDY
                      - Initialize static memory
                      - Call measurement freeze
  
  @startuml 
    Partition APM_v_Process
    Start
  	Note right: Main function to call all ACC Performance \n Monitoring (APM) functionalities
  	If (APM_State is APM_OK) then (True)
  		- Process ACC degradation based on ALN and VDY
  	Else (False)
  	if (APM_State is APM_INIT) then (True)
  		- Initialize the pointers
  	Else (False)
  		- Initialize APM static data \n in APM init operation mode
  	Endif
  	Endif
  	- Freeze Degradaiton data
    End
  @enduml

  @return          -

  @param[in]       -

  @glob_in         t_APM_State : Operating mode of APM sub-component [full range of datatype APMState_t as in apm_ext.h]
  @glob_out        -

  @c_switch_part   -
  @c_switch_full   SLATE_CFG_ACC_PERF_MONITORING : FCT switch for ACC Performance Monitoring (APM)

  @pre             -
  @post            -

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @created         28.10.2016
  @changed         28.10.2016

  @author          Marie-Theres Boll | marie-theres.boll@continental-corporation.com | +49 (8382) 9699-632
*************************************************************************************************************************/
void APM_v_Process(void)
{
  switch (t_APM_State)
  {
  case COMP_STATE_RUNNING:
    /*! Process interference range */
    //SPMInterferenceRange();
    /*! Process degradation based on ALN and VDY */
    APM_v_PerfDegradation();
  break;

  case COMP_STATE_NOT_INITIALIZED:
  case COMP_STATE_TEMPORARY_ERROR:
  case COMP_STATE_PERMANENT_ERROR:
  default:
    /*! Initialization */
    /*! Default */
    APM_v_Init();
    break;
  }

  /*! Measfreeze */
  /*! Freeze degradation data */
  APM_v_MeasFreezeDegradationData();
  /* Interference Freeze missing !!! */
}


/*************************************************************************************************************************
  Functionname:    APM_v_SetErrorState                                                                              */ /*!

  @brief           Set APM error state

  @description     Set APM error state: Set given error state for given APM error type in APM error state struct

  @startuml 
  Partition APM_v_SetErrorState
  Start
	  - Update APM Error State array with provided error state given if it’s a valid error
  end
  @enduml

  @return          -

  @param[in]       t_APM_Error : APM error enumerator[full range of datatype APMErrorEvents_t as in apm.h]
  @param[in]       t_Err_State : Error state [full range of datatype AlgoErrorState_t as in Rte_Type.h]

  @glob_in         -
  @glob_out        t_APMErrStates : APM error states [full range of datatype AlgoErrorState_t as in Rte_Type.h] 
                                    for i different APM error types with i in [0 ... APM_ERREV_NUM_ERRORS[ and 
                                    APM_ERREV_NUM_ERRORS as in apm.h

  @c_switch_part   -
  @c_switch_full   SLATE_CFG_ACC_PERF_MONITORING : FCT switch for ACC Performance Monitoring (APM)

  @pre             -
  @post            -

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @created         28.10.2016
  @changed         28.10.2016

  @author          Marie-Theres Boll | marie-theres.boll@continental-corporation.com | +49 (8382) 9699-632
*************************************************************************************************************************/
void APM_v_SetErrorState(APMErrorEvents_t t_APM_Error, AlgoErrorState_t t_Err_State)
{
  /*! Set given error state for given APM error type in APM error state struct */
  if (t_APM_Error < APM_ERREV_NUM_ERRORS)
  {
    t_APMErrStates[t_APM_Error] = t_Err_State;
  }
}

#if (FCT_CFG_ERROR_OUTPUT_SEN)
/*************************************************************************************************************************
  Functionname:    APM_v_FillSenErrors                                                                              */ /*!

  @brief           Set ACC error output structure based on APM errors for FCT_SEN task

  @description     Set FCT_SEN ACC error output structure based on APM errors, i.e. 
                    - degradation based on azimuth alignment input
                    - degradation based on elevation alignment input
                    - degradation based on vdy input
  
  @startuml 
    Partition APM_v_FillSenErrors
    Start
	Note right: This function sets ACC error output structure based on APM errors
          - Update ACC minimum performance distance based on azimuth alignment input
          - Update ACC minimum performance distance based on elevation alignment input
          - Update ACC minimum performance distance based on vdy input
    End
  @enduml

  @return          -

  @param[out]      pDest : ACC error output structure in FCT_SEN task
                      pt_BelowMinPerfDist_AZ : Below minimum performance distance based on azimuth alignment input
                        [full range of datatype AlgoErrorState_t as in Rte_Type.h]
                      pt_BelowMinPerfDist_EL : Below minimum performance distance based on elevation alignment input
                        [full range of datatype AlgoErrorState_t as in Rte_Type.h]
                      pt_BelowMinPerfDist_VDY : Below minimum performance distance based on vdy input
                        [full range of datatype AlgoErrorState_t as in Rte_Type.h]

  @glob_in         t_APMErrStates : APM error states [full range of datatype AlgoErrorState_t as in Rte_Type.h] 
                                    for i different APM error types with i in [0 ... APM_ERREV_NUM_ERRORS[ and 
                                    APM_ERREV_NUM_ERRORS as in apm.h
  @glob_out        -

  @c_switch_part   -
  @c_switch_full   SLATE_CFG_ACC_PERF_MONITORING : FCT switch for ACC Performance Monitoring (APM)

  @pre             -
  @post            -

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @created         28.10.2016
  @changed         28.10.2016

  @author          Marie-Theres Boll | marie-theres.boll@continental-corporation.com | +49 (8382) 9699-632
*************************************************************************************************************************/
void APM_v_FillSenErrors(SLATEErrorOutProPort_t * pDest)
{
  //*(pDest->pt_InterferenceRange)    = t_APMErrStates[APM_ERREV_INTERFERENCE_RANGE];
#if (FCT_SEN_ERROR_OUT_INTFVER >= 0x0C)
  (pDest->t_BelowMinPerfDist_AZ)  = t_APMErrStates[APM_ERREV_ACC_DEGRADATION_AZ];
  (pDest->t_BelowMinPerfDist_EL)  = t_APMErrStates[APM_ERREV_ACC_DEGRADATION_EL];
  (pDest->t_BelowMinPerfDist_VDY) = t_APMErrStates[APM_ERREV_ACC_DEGRADATION_VDY];
#endif
}
#endif /* END IF (FCT_CFG_ERROR_OUTPUT_SEN) */


/*************************************************************************************************************************
  Functionname:    APM_v_Init                                                                                       */ /*!

  @brief           Initialize APM static data in APM init operation mode

  @description     Initialize APM static data in APM init operation mode: call underlying initialization functions
                     - Initialize degradation data
                     - Initialize error outputs
  
  @startuml 
  Partition APM_v_Init
  Start
	Note right: This function Initializes APM static \n data in APM init operation mode
	- Initialize degradation data
	- Initialize error outputs
  end
  @enduml

  @return          -

  @param[in]       -

  @glob_in         -
  @glob_out        -

  @c_switch_part   -
  @c_switch_full   SLATE_CFG_ACC_PERF_MONITORING : FCT switch for ACC Performance Monitoring (APM)

  @pre             -
  @post            -

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @created         28.10.2016
  @changed         28.10.2016

  @author          Marie-Theres Boll | marie-theres.boll@continental-corporation.com | +49 (8382) 9699-632
*************************************************************************************************************************/
static void APM_v_Init(void)
{
  /*! Initialize interference data */
  //APM_v_InitInterferenceData();

  /*! Initialize degradation data */
  APM_v_InitDegradationData();

  /*! Initialize error outputs */
  //APM_v_SetErrorState(APM_ERREV_INTERFERENCE_RANGE, AL_ERR_STATE_UNKNOWN);
  APM_v_SetErrorState(APM_ERREV_ACC_DEGRADATION_AZ, AL_ERR_STATE_UNKNOWN);
  APM_v_SetErrorState(APM_ERREV_ACC_DEGRADATION_EL, AL_ERR_STATE_UNKNOWN);
  APM_v_SetErrorState(APM_ERREV_ACC_DEGRADATION_VDY, AL_ERR_STATE_UNKNOWN);
}


/*************************************************************************************************************************
  Functionname:    APM_v_SetOperationMode                                                                           */ /*!

  @brief           Set operation mode of APM sub-component

  @description     Set operation mode of APM sub-component based on given value

  @startuml 
  Partition APM_v_SetOperationMode
  Start
	Note right: This function sets operation mode of APM \n sub-component based on given value
	- Update APM State with APM operation mode variable
  end
  @enduml

  @return          -

  @param[in]       t_APMOpModeValue : APM operation mode value [full range of datatype SLATECompState_t as in slate_types.h]

  @glob_in         -
  @glob_out        @ref t_APM_State

  @c_switch_part   -
  @c_switch_full   SLATE_CFG_ACC_PERF_MONITORING : FCT switch for ACC Performance Monitoring (APM)

  @pre             -
  @post            -

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @created         28.10.2016
  @changed         28.10.2016

  @author          Marie-Theres Boll | marie-theres.boll@continental-corporation.com | +49 (8382) 9699-632
*************************************************************************************************************************/
void APM_v_SetOperationMode(SLATECompState_t const t_APMOpModeValue)
{
  t_APM_State = t_APMOpModeValue;
}
///@}
#endif /*!< SLATE_CFG_ACC_PERF_MONITORING */

