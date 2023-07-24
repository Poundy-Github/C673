/*! \file **********************************************************************

COMPANY:                   COPYRIGHT (C) Continental AG

PROJECT:                   Adaptive Cruise Control (ACC)

CPU:                       CPU-Independent

COMPONENT:                 SLATE

MODULNAME:                 slate_algocontrol.c

DESCRIPTION:               set FCT SLATE State Matrix (states of FCT sub-components)

AUTHOR:                    $Author: uib05783 $

CREATION DATE:             07.09.2016

VERSION:                   $Revision: 1.8 $

LEGACY VERSION:            Revision: 2.2

**************************************************************************** */



/*****************************************************************************
  INCLUDES
*****************************************************************************/

#include "slate.h" /*  PRQA S 0380 */
/* date: 2019-07-01, reviewer: Karthik Chittepu, reason: This will not have any effect on functionality  */
#if (FCT_CFG_ADAPTIVE_CRUISE_CONTROL)
#if (FCT_CFG_SLATE_COMPONENT)
/*****************************************************************************
  MODULE DESCRIPTION
*****************************************************************************/
/**
@defgroup frame_algocontrol Algo Control
@ingroup frame
@brief          Provides functions to control the information flow inside of the SLATE Component\n\n
@description    The module provides the following functionalities:
                - Setting of the ACC Error Buffer: @ref SLATE_v_SetAlgoErrorBuffer
                - Setting of the OpModes of SLATE and its subcomponents according to a given OpMode: @ref SLATE_v_ProcessStates
                - Setting of the SLATE OpModes in case of a shutdown: @ref SLATE_v_SignalErrorShutdown

@{

*/

/*****************************************************************************
  FUNCTION PROTOTYPES
*****************************************************************************/
/*! @cond Doxygen_Suppress */
#if (FCT_CFG_USE_ALGOCOMPSTATE)
void FCTSenSetAlgoErrorBuffer (GenAlgoQualifiers_t *const pErrorBuffer, const GenAlgoQualifiers_t ErrorQualifier);
#endif
/*! @endcond Doxygen_Suppress */

#if (FCT_CFG_USE_ALGOCOMPSTATE)


/*************************************************************************************************************************
  Functionname:    SLATE_v_SetAlgoErrorBuffer                                                                   */ /*!

  @brief           Set the SLATE Algo Error Buffer
  @description     Set the SLATE Algo Error in priority
                  not possible to change to a lower priority than already set
				  @startuml
	              Start
	              	Partition  SLATE_v_SetAlgoErrorBuffer  {
	              		If (ErrorBuffer is not NULL) AND (Alogo quality is not ok) )then (true )
	              			if (ErrorBuffer is equal to ALGO QUALITY OK) then (true)
	              				-Set ErrorBuffer to ErrorQualifier
	              			Else (false)
	              				if (ErrorQualifier is less that ErrorBuffer) 
	              					-Set ErrorBuffer to ErrorQualifier;
	              				endif
	              			endif
	              		endif
	              	}
	              end
                  @enduml


  @return          void
  @param[in,out]   pErrorBuffer   : pointer to the buffered error [full range of datatype GenAlgoQualifiers_t as in Rte_Type.h]
  @param[in]       ErrorQualifier : the Error to set [full range of datatype GenAlgoQualifiers_t as in Rte_Type.h] 

  @glob_in         None ? : Global input used in this function
  @glob_out        None ? : Global output filled in this function

  @c_switch_part   None ? : Compiler switch used only within this function
  @c_switch_full   None ? : Compiler switch used around this function/file

  @pre             nothing
  @post            properly buffered Error

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @created         26.01.2017
  @changed         26.01.2017
  
  @author          Hanyu Shang | hanyu.shang@continental-corporation.com | +49 (8382) 9699-5801
************************************************************************************************************************/
void SLATE_v_SetAlgoErrorBuffer (GenAlgoQualifiers_t *const pErrorBuffer, const GenAlgoQualifiers_t ErrorQualifier)
{
  if ( (pErrorBuffer != NULL) && (ErrorQualifier != ALGO_QUAL_OK) ) /*pointer check and entry condition*/
  {
    if (*pErrorBuffer == ALGO_QUAL_OK)
    {
      *pErrorBuffer = ErrorQualifier;
    }
    else
    {
      if (ErrorQualifier < *pErrorBuffer)
      {
        *pErrorBuffer = ErrorQualifier;
      }
    }
  }
}
#endif
/*************************************************************************************************************************
  Functionname:    SLATE_v_ProcessStates                                                                       */ /*!

  @brief           Set operation modes of all sub-components in SLATE

  @description     Sets the operational modes of the subcomponents to the states shown in the table 
                   below by calling the following functions:
                    - SLATE: @ref SLATE_v_SetOperationMode
                    - FIP: @ref FIP_v_SetOperationMode
                    - CP: @ref CP_v_SetOperationMode
                    - LA @ref LA_v_SetOperationMode
                    - OOI @ref OOI_v_SetOperationMode
                    - SIT @ref SIT_v_SetOperationMode
                    - OUT @ref OUT_v_SetOperationMode
                    - APM @ref APM_v_SetOperationMode
					@startuml
	                start
	                	Partition SLATE_v_ProcessStates  {
	                		if(FCT Operation Mode is initilization mode) then(True)
	                			-Initilize elements of the meascycle monitor in the required port handler list.
   	                			- Set CycleCounter to 0u;
	                		Endif
	                	  If(component is not in init state at least once) then (True)
	                		-Set Operation Mode of FCT to initilization mode
	                	  Endif
	                	  If(FCT Operation Mode is in start up mode)or(FCT Operation Mode is in initilization mode)then(True)
                                - Set operation mode of FIP, LA, CP, OOI, SIT,OUT and APM sub-component to state not initilized mode
	                		- Set operation mode of ACC sub-component in FCT_SEN task to state not initilized mode             
	                	  Else if (FCT Operation Mode is in Running mode) then(True)
                                - Set operation mode of FIP, LA, CP, OOI, SIT,OUT and APM sub-component to running mode
	                		- Set operation mode of ACC sub-component in FCT_SEN task to running mode		  
                             Else if(FCT Operation Mode is in Shut down mode)
	                		- Set operation mode of FIP, LA, CP, OOI, SIT,OUT and APM sub-component to not running mode
	                		- Set operation mode of ACC sub-component in FCT_SEN task to not running mode		  
	                	 Else
	                		- Set operation mode of FIP, LA, CP, OOI, SIT,OUT and APM sub-component to temporary error mode
	                		- Set operation mode of ACC sub-component in FCT_SEN task to temporary error mode			
	                	endif
	                	}	
	                end
                   @enduml
  @return          void

  @param[in]       eOpMode : the operation mode of FCT to use         [FCT_OP_MODE_t as in Rte_Type.h]

  @glob_in         @ref t_SLATEFrame
  
  @c_switch_part   FCT_CFG_SIGNAL_PERF_MONITORING : FCT signal performance monitoring
  @c_switch_full   @ref FCT_CFG_SLATE_COMPONENT

  @pre             -
  @post            -

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @InOutCorrelation     
                        | (Sub)Component | FCT_MOD_STARTUP | FCT_MOD_INIT    | FCT_MOD_RUNNING | FCT_MOD_SHUTDOWN |      OTHER      |
                        |:---------------|:----------------|:----------------|:----------------|:-----------------|:----------------|
                        | SLATE          | NOT_INITIALIZED | NOT_INITIALIZED |     RUNNING     |   NOT RUNNING    | TEMPORARY_ERROR |
                        | FIP            | NOT_INITIALIZED | NOT_INITIALIZED |     RUNNING     |   NOT RUNNING    | TEMPORARY_ERROR |
                        | CP             | NOT_INITIALIZED | NOT_INITIALIZED |     RUNNING     |   NOT RUNNING    | TEMPORARY_ERROR |
                        | LA             | NOT_INITIALIZED | NOT_INITIALIZED |     RUNNING     |   NOT RUNNING    | TEMPORARY_ERROR |
                        | OOI            | NOT_INITIALIZED | NOT_INITIALIZED |     RUNNING     |   NOT RUNNING    | TEMPORARY_ERROR |
                        | SIT            | NOT_INITIALIZED | NOT_INITIALIZED |     RUNNING     |   NOT RUNNING    | TEMPORARY_ERROR |
                        | OUT            | NOT_INITIALIZED | NOT_INITIALIZED |     RUNNING     |   NOT RUNNING    | TEMPORARY_ERROR |
                        | APM            | NOT_INITIALIZED | NOT_INITIALIZED |     RUNNING     |   NOT RUNNING    | TEMPORARY_ERROR |

  @changed         12.12.2017

  @author          Bharadwaj Gobichettipalayam Sankar| bharadwaj.gobichettipalayam.sankar@continental-corporation.com | +49 (8382) 9699-4977
*************************************************************************************************************************/
void SLATE_v_ProcessStates (FCT_OP_MODE_t eOpMode)
{
  /*The port handler list shall be reseted if SLATE is called in INIT mode.
  This has to be done before the check of the bIsInitialized flag to 
  assure that the struct is not reseted in case of an error.*/
  if (eOpMode == FCT_MOD_INIT)
  {
    SLATE_v_InitReqPortHandlerListMeasCycleData(FALSE);
    t_SLATEFrame.uiCycleCounter   = 0u;
  }

  /* ensure that each component runs in init state at least once */
/* date: 2019-07-01, reviewer: Karthik Chittepu, reason: Integral promotion is fine  */
  if (t_SLATEFrame.bIsInitialized != TRUE)/* PRQA S 1863 */
  {
    eOpMode = FCT_MOD_INIT;
  }

  switch (eOpMode)
  {
  /*  FIP        CP        LA        OOI        SIT        OUT        APM        SLATE  */
  case (FCT_OP_MODE_t)FCT_MOD_STARTUP:
  case (FCT_OP_MODE_t)FCT_MOD_INIT:
    {
#if (FCT_CFG_INPUT_PREPROCESSSING)
      FIP_v_SetOperationMode(COMP_STATE_NOT_INITIALIZED);
#endif
#if (FCT_CFG_COURSE_PREDICTION)
      CP_v_SetOperationMode(COMP_STATE_NOT_INITIALIZED);
#endif
#if (FCT_CFG_ACC_LANE_ASSOCIATION)
      LA_v_SetOperationMode(COMP_STATE_NOT_INITIALIZED);
#endif
#if (FCT_CFG_ACC_OOI)
      OOI_v_SetOperationMode(COMP_STATE_NOT_INITIALIZED);
#endif
#if (FCT_CFG_ACC_SITUATION)
      SIT_v_SetOperationMode(COMP_STATE_NOT_INITIALIZED);
#endif
#if (FCT_CFG_ACC_OUTPUT)
      OUT_v_SetOperationMode(COMP_STATE_NOT_INITIALIZED);
#endif
#if (SLATE_CFG_ACC_PERF_MONITORING)
      APM_v_SetOperationMode(COMP_STATE_NOT_INITIALIZED);
#endif 
      SLATE_v_SetOperationMode(COMP_STATE_NOT_INITIALIZED);
      break;
    }
  case (FCT_OP_MODE_t)FCT_MOD_RUNNING:
#if (FCT_CFG_INPUT_PREPROCESSSING)
    FIP_v_SetOperationMode(COMP_STATE_RUNNING);
#endif
#if (FCT_CFG_COURSE_PREDICTION)
    CP_v_SetOperationMode(COMP_STATE_RUNNING);
#endif
#if (FCT_CFG_ACC_LANE_ASSOCIATION)
      LA_v_SetOperationMode(COMP_STATE_RUNNING);
#endif
#if (FCT_CFG_ACC_OOI)
      OOI_v_SetOperationMode(COMP_STATE_RUNNING);
#endif
#if (FCT_CFG_ACC_SITUATION)
    SIT_v_SetOperationMode(COMP_STATE_RUNNING);
#endif
#if (FCT_CFG_ACC_OUTPUT)
      OUT_v_SetOperationMode(COMP_STATE_RUNNING);
#endif
#if (SLATE_CFG_ACC_PERF_MONITORING)
    APM_v_SetOperationMode(COMP_STATE_RUNNING);
#endif
    SLATE_v_SetOperationMode(COMP_STATE_RUNNING);

    break;
  case (FCT_OP_MODE_t)FCT_MOD_SHUTDOWN:
#if (FCT_CFG_INPUT_PREPROCESSSING)
    FIP_v_SetOperationMode(COMP_STATE_NOT_RUNNING);
#endif
#if (FCT_CFG_COURSE_PREDICTION)
    CP_v_SetOperationMode(COMP_STATE_NOT_RUNNING);
#endif
#if (FCT_CFG_ACC_LANE_ASSOCIATION)
      LA_v_SetOperationMode(COMP_STATE_NOT_RUNNING);
#endif
#if (FCT_CFG_ACC_OOI)
      OOI_v_SetOperationMode(COMP_STATE_NOT_RUNNING);
#endif
#if (FCT_CFG_ACC_SITUATION)
    SIT_v_SetOperationMode(COMP_STATE_NOT_RUNNING);
#if (FCT_CFG_ACC_OUTPUT)
      OUT_v_SetOperationMode(COMP_STATE_NOT_RUNNING);
#endif
#endif
#if (SLATE_CFG_ACC_PERF_MONITORING)
    APM_v_SetOperationMode(COMP_STATE_NOT_RUNNING);
#endif
    SLATE_v_SetOperationMode(COMP_STATE_NOT_RUNNING);

    break;
  default:
    /*This state should not be reached*/
    SLATE_ASSERT(FALSE);
#if (FCT_CFG_INPUT_PREPROCESSSING)
    FIP_v_SetOperationMode(COMP_STATE_TEMPORARY_ERROR);
#endif
#if (FCT_CFG_COURSE_PREDICTION)
    CP_v_SetOperationMode(COMP_STATE_TEMPORARY_ERROR);
#endif
#if (FCT_CFG_ACC_LANE_ASSOCIATION)
      LA_v_SetOperationMode(COMP_STATE_TEMPORARY_ERROR);
#endif
#if (FCT_CFG_ACC_OOI)
      OOI_v_SetOperationMode(COMP_STATE_TEMPORARY_ERROR);
#endif
#if (FCT_CFG_ACC_SITUATION)
    SIT_v_SetOperationMode(COMP_STATE_TEMPORARY_ERROR);
#endif
#if (FCT_CFG_ACC_OUTPUT)
      OUT_v_SetOperationMode(COMP_STATE_TEMPORARY_ERROR);
#endif
#if (SLATE_CFG_ACC_PERF_MONITORING)
    APM_v_SetOperationMode(COMP_STATE_TEMPORARY_ERROR);
#endif
    SLATE_v_SetOperationMode(COMP_STATE_TEMPORARY_ERROR);
    break;
  }
}


/*************************************************************************************************************************
  Functionname:    SLATE_v_SignalErrorShutdown                                                                        */ /*!

  @brief           Set operation modes of all sub-components in case of Error

  @description     Set operation modes of all sub-components in case of Error
                   @startuml
	               Start
	               	Partition  SLATE_v_SignalErrorShutdown {
	               	- Initialize the recovery status to false
	               	if (Recovery status is not TRUE) then (True)
	               		- Set operation mode of FIP, LA, CP, OOI, SIT,OUT and APM sub-component to temporary error mode
	               		- Set operation mode of ACC sub-component in FCT_SEN task to temporary error mode		
	               	Else (false)
	               		- Set operation mode of FIP, LA, CP, OOI, SIT,OUT and APM sub-component to not initilized mode
	               		- Set operation mode of ACC sub-component in FCT_SEN task to not initilized mode
	               	endif
	               	}
	               end
                   @enduml
  @return          void

  @param[in]       isRecoveryPossible : Status to inform whether the shutdown should takes place or not [TRUE, FASLE]

  @glob_in         GET_PERF_DEG_DATA_PTR->sSigHeader.eSigStatus :                                       [AlgoSignalState_t as in Rte_Type.h]
  @glob_out        b_FCTSenSLATEIsInitialized : FCT_SEN and it's subcomponents initialization status           [TRUE, FALSE]

  @c_switch_part   FCT_CFG_COURSE_PREDICTION : FCT switch for CP sub-component
  @c_switch_part   SLATE_CFG_ACC_PERF_MONITORING : FCT switch for ACC Performance Monitoring (APM)
  @c_switch_part   FCT_CFG_INPUT_PREPROCESSSING : FCT support for FCT Input Preprocessing (FIP): Need to be switched on for ACC
  @c_switch_full   None 

  @pre             None 
  @post            No changes 

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @created         21.05.2013
  @changed         23.10.2015

  @author          Clemens Schnurr | Clemens.Schnurr@continental-corporation.com
*************************************************************************************************************************/
void SLATE_v_SignalErrorShutdown(const boolean isRecoveryPossible)
{
  t_SLATEFrame.bIsInitialized = FALSE;
/* date: 2019-07-01, reviewer: Karthik Chittepu, reason: Integral promotion is fine  */
  if (isRecoveryPossible != TRUE) /* PRQA S 1863 */
  {

#if (FCT_CFG_INPUT_PREPROCESSSING)
    FIP_v_SetOperationMode(COMP_STATE_TEMPORARY_ERROR);
#endif
#if (FCT_CFG_COURSE_PREDICTION)
    CP_v_SetOperationMode(COMP_STATE_TEMPORARY_ERROR);
#endif
#if (FCT_CFG_ACC_LANE_ASSOCIATION)
    LA_v_SetOperationMode(COMP_STATE_TEMPORARY_ERROR);
#endif
#if (FCT_CFG_ACC_OOI)
    OOI_v_SetOperationMode(COMP_STATE_TEMPORARY_ERROR);
#endif
#if (FCT_CFG_ACC_SITUATION)
    SIT_v_SetOperationMode(COMP_STATE_TEMPORARY_ERROR);
#endif
#if (SLATE_CFG_ACC_PERF_MONITORING)
    APM_v_SetOperationMode(COMP_STATE_TEMPORARY_ERROR);
#endif
#if (FCT_CFG_ACC_OUTPUT)
    OUT_v_SetOperationMode(COMP_STATE_TEMPORARY_ERROR);
#endif
    SLATE_v_SetOperationMode(COMP_STATE_TEMPORARY_ERROR);
  }
  else
  {
    /**
     * this path is currently reached in case of an invalid 'ObjectList' which can be caused by EM_MOD_INVALID_INPUTS.
     * check if this is the case by investigating status of 'PerformanceDegradation' data.
     * this structure should have the status of the 'ObjectList', namely AL_SIG_STATE_INIT.
     * except the situation where BlockageInformation should be hold.
     * this is signaled by setting SigHeaderStatus of 'PerfDegr_t' struct to 'AL_SIG_STATE_OK.
     * Freezing BlockageInformation is only allowed in EmFctCycleMode EM_FCT_CYCLE_INIT to prevent
     * false freezing in 'RunningMode'.
     *
     * this is only valid in case of having EM and FCT running synchronously which seems currently 
     * not to be the case -> skip second condition temporarily since 'EmFctCycleMode' data is currently used from recording
     * instead of the one from simulation!
     */
#if (FCT_CFG_INPUT_PREPROCESSSING)
    FIP_v_SetOperationMode(COMP_STATE_NOT_INITIALIZED);
#endif
#if (FCT_CFG_COURSE_PREDICTION)
    CP_v_SetOperationMode(COMP_STATE_NOT_INITIALIZED);
#endif
#if (FCT_CFG_ACC_LANE_ASSOCIATION)
    LA_v_SetOperationMode(COMP_STATE_NOT_INITIALIZED);
#endif
#if (FCT_CFG_ACC_OOI)
    OOI_v_SetOperationMode(COMP_STATE_NOT_INITIALIZED);
#endif
#if (FCT_CFG_ACC_SITUATION)
    SIT_v_SetOperationMode(COMP_STATE_NOT_INITIALIZED);
#endif
#if (SLATE_CFG_ACC_PERF_MONITORING)
    APM_v_SetOperationMode(COMP_STATE_NOT_INITIALIZED);
#endif
#if (FCT_CFG_ACC_OUTPUT)
    OUT_v_SetOperationMode(COMP_STATE_NOT_INITIALIZED);
#endif
    SLATE_v_SetOperationMode(COMP_STATE_NOT_INITIALIZED);
  }
}
/// @}
#endif /* FCT_CFG_SLATE_COMPONENT */
#endif /*!< (FCT_CFG_ADAPTIVE_CRUISE_CONTROL) */

/* ************************************************************************* */
/*   Copyright ADC-GmbH, Lindau                                              */
/* ************************************************************************* */

