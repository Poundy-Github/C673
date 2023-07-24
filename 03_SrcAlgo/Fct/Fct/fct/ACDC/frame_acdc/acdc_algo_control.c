/*! \file **********************************************************************

COMPANY:                   COPYRIGHT (C) Continental AG
  
PROJECT:                   Mainstream

CPU:                       CPU-Independent

COMPONENT:                 ACDC -(Advanced collision detection and classification)

PACKAGENAME:               acdc_algo_control.c

DESCRIPTION:               Functions for ACDC algo control purpose

AUTHOR:                    $Author: BORAIAH, KOMALA (uidk2011) (uidk2011) $

CREATION DATE:             $Date: 2020/07/20 09:46:00CEST $

VERSION:                   $Revision: 1.34 $

**************************************************************************** */

/*****************************************************************************
  INCLUDES
*****************************************************************************/

#include "acdc_int.h"

#if(ACDC_CFG_FRAME)
/*****************************************************************************
  MODULE DESCRIPTION
*****************************************************************************/
/**
@defgroup frame_algocontrol Algo Control
@ingroup frame
@brief          Provides functions to control the information flow inside of the ACDC Component\n\n
@description    The module provides the following functionalities:
                - Setting of the EBA Error Buffer: @ref ACDC_v_SetAlgoErrorBuffer
                - Setting of the OpModes of ACDC and its subcomponents according to a given OpMode: @ref ACDC_v_ProcessStates
                - Setting of the ACDC OpModes in case of a shutdown: @ref ACDC_v_SignalErrorShutdown

@{

*/
/*****************************************************************************
  FUNCTION PROTOTYPES
*****************************************************************************/
static uint8 ACDC_u_GetStateCriticality  (ACDCCompState_t eCompState);
static ACDCCompState_t ACDC_u_GetMostCritCompState(ACDCCompState_t const u_stateA, ACDCCompState_t const u_stateB);

#if (FCT_CFG_USE_ALGOCOMPSTATE)
/*************************************************************************************************************************
  Functionname:         ACDC_v_SetAlgoErrorBuffer                                                               */ /*!

  @brief                Write the current error to the error buffer.

  @description          Write the current error to the error buffer. Condition for this is, that the criticality \n
                        of the current error is higher than the one of the error in the buffer.
                        @startuml ACDC_v_SetAlgoErrorBuffer_activity.png
                        start
                          if (Currently no error in buffer?) then (Yes)
                            :1}
                            :Write current error to buffer;
                          elseif(Current Error is more critical than the one in the buffer?) then (Yes)
                            :2}
                            :Overwrite error in buffer with current error;
                          else(No)
                            :3}
                            :Do not write current error to buffer;
                          endif
                        stop
                        @enduml
  @return               void

  @param[in,out]        pErrorBuffer :    the Error to set [full range of datatype GenAlgoQualifiers_t as in Rte_Type.h]
  @param[in]            ErrorQualifier :  pointer to the buffered error [full range of datatype GenAlgoQualifiers_t as in Rte_Type.h]

  @glob_in              None
  @glob_out             None

  @c_switch_part        None
  @c_switch_full        @ref FCT_CFG_USE_ALGOCOMPSTATE \n
                        @ref ACDC_CFG_FRAME

  @pre                  None
  @post                 Properly buffered Error

  @InOutCorrelation     see description

  @testmethod           @Generic_Testmethods

  @author               Christian Obst
*************************************************************************************************************************/
void ACDC_v_SetAlgoErrorBuffer (GenAlgoQualifiers_t *const pErrorBuffer, const GenAlgoQualifiers_t ErrorQualifier)
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
#endif /* (FCT_CFG_USE_ALGOCOMPSTATE) */


/*************************************************************************************************************************
  Functionname:         ACDC_v_SignalErrorShutdown                                                              */ /*!

  @brief                Handles the setting of OpModes in case of a shutdown.

  @description          Handles the shutdown for ACDC and its subcomponents. Depending on whether an 
                        error was detected or not, the states are set as shown in the table below 
                        (@ref ACDC_v_SetSubComponentStates).

  @return               void

  @param[in]            bIsRecoveryPossible : Flag indicating whether a recovery after a error is possible or not.

  @glob_in              None
  @glob_out             @ref ACDC_p_ModFrameData

  @c_switch_part        None
  @c_switch_full        @ref ACDC_CFG_FRAME

  @pre                  None
  @post                 None

  @InOutCorrelation
                        |(Sub)Component |   Recovery is possible   | Recovery is not possible |
                        |:--------------|:-------------------------|:-------------------------|
                        |     ACDC      |COMP_STATE_NOT_INITIALIZED|COMP_STATE_TEMPORARY_ERROR|
                        |     ESPM      |COMP_STATE_NOT_INITIALIZED|COMP_STATE_TEMPORARY_ERROR|
                        |      CD       |COMP_STATE_NOT_INITIALIZED|COMP_STATE_TEMPORARY_ERROR|
                        |     AIP       |COMP_STATE_NOT_INITIALIZED|COMP_STATE_TEMPORARY_ERROR|

  @testmethod           @ref TEST_ACDC_V_SIGNALERRORSHUTDOWN_001\n
                        @ref TEST_ACDC_V_SIGNALERRORSHUTDOWN_002

  @traceability          Design Decision

  @author               Veronika Ehrlinspiel | veronika.ehrlinspiel@continental-corporation.com | +49 (8382) 9699-490
*************************************************************************************************************************/
void ACDC_v_SignalErrorShutdown(const boolean bIsRecoveryPossible)
{
  ACDC_p_ModFrameData()->bIsInitialized = b_FALSE;

  if (bIsRecoveryPossible != b_TRUE)
  {
    ACDC_v_SetSubComponentStates(ACDC_SUB_COMP_ALL, COMP_STATE_TEMPORARY_ERROR);
  }
  else
  {
    ACDC_v_SetSubComponentStates(ACDC_SUB_COMP_ALL, COMP_STATE_NOT_INITIALIZED);
  }
}


/*************************************************************************************************************************
  Functionname:         ACDC_u_GetMostCritCompState                                                                  */ /*!

  @brief                Returns the more critical one of two states.

  @description          Gets the criticality of both given states by calling the function @ref ACDC_u_GetStateCriticality for each. 
                        Afterwards returns the state with the higher criticality.

  @return               ACDCCompState_t : More critical of the two input component states

  @param[in]            u_stateA : First component state for the comparison
  @param[in]            u_stateB : Second component state for the comparison

  @glob_in              None
  @glob_out             None

  @c_switch_part        None
  @c_switch_full        @ref ACDC_CFG_FRAME\n

  @pre                  None
  @post                 None

  @InOutCorrelation     see description

  @testmethod           @ref TEST_ACDC_U_GETMOSTCRITCOMPSTATE_001\n
                        @ref TEST_ACDC_U_GETMOSTCRITCOMPSTATE_002

  @traceability          Design Decision

  @author               Andreas Danner | Andreas.Danner@continental-corporation.com | +49 (8382) 9699-4995
*************************************************************************************************************************/
static ACDCCompState_t ACDC_u_GetMostCritCompState(ACDCCompState_t const u_stateA, 
                                                   ACDCCompState_t const u_stateB)
{
  uint8 const u_criticalityA  = ACDC_u_GetStateCriticality(u_stateA);
  uint8 const u_criticalityB  = ACDC_u_GetStateCriticality(u_stateB);
  ACDCCompState_t u_critCompState;
  if(u_criticalityB > u_criticalityA)
  {
    u_critCompState = u_stateB;
  }
  else
  {
    u_critCompState = u_stateA;
  }

  return u_critCompState;
}



/*************************************************************************************************************************
  Functionname:         ACDC_v_SetSubComponentStates                                                                 */ /*!

  @brief                Sets the states of the subcomponents indicated by the bitfield SubCompIndices to the given CompState.

  @description          Sets the desired subcomponents to the desired state. The Bitfield shall be filled with 
                        the values of the type @ref ACDCSubCompIndices_t. \n
                        The subcomponents are only set to states which are worse than their current one. This is 
                        assured by using the function @ref ACDC_u_GetMostCritCompState

  @return               void

  @param[in]            SubCompIndices : Bitfield with the indices of the subcomponents. @range [@ref ACDC_SUB_COMP_NONE, @ref ACDC_SUB_COMP_ALL]
  @param[in]            CompState :      Comp state to which the subcomponents shall be set.

  @glob_in              None
  @glob_out             @ref ACDC_p_ModFrameData

  @c_switch_part        None
  @c_switch_full        @ref ACDC_CFG_FRAME\n

  @pre                  None
  @post                 None

  @InOutCorrelation     see description

  @testmethod           @ref TEST_ACDC_V_SETSUBCOMPONENTSTATES_001\n
                        @ref TEST_ACDC_V_SETSUBCOMPONENTSTATES_002\n
						@ref TEST_ACDC_V_SETSUBCOMPONENTSTATES_003\n
						@ref TEST_ACDC_V_SETSUBCOMPONENTSTATES_004
 
 @traceability          Design Decision

  @author               Andreas Danner | Andreas.Danner@continental-corporation.com | +49 (8382) 9699-4995
*************************************************************************************************************************/
void ACDC_v_SetSubComponentStates(ACDCSubCompIndices_t const SubCompIndices, 
                                  ACDCCompState_t      const CompState)
{
  ACDCFrame_t * const pFrame = ACDC_p_ModFrameData();
  if(CML_GetBit(SubCompIndices, ACDC_SUB_COMP_ACDC))
  {
    pFrame->eACDCState = ACDC_u_GetMostCritCompState(pFrame->eACDCState,CompState);
  }
  if(CML_GetBit(SubCompIndices, ACDC_SUB_COMP_AIP))
  {
    pFrame->eAIPState = ACDC_u_GetMostCritCompState(pFrame->eAIPState,CompState);
  }
  if(CML_GetBit(SubCompIndices, ACDC_SUB_COMP_CD) )
  {
    pFrame->eCDState = ACDC_u_GetMostCritCompState(pFrame->eCDState,CompState);
  }
  if(CML_GetBit(SubCompIndices, ACDC_SUB_COMP_ESPM))
  {
    pFrame->eESPMState = ACDC_u_GetMostCritCompState(pFrame->eESPMState,CompState);
  }
}

/*************************************************************************************************************************
  Functionname:         ACDC_e_GetSubCompState                                                                       */ /*!

  @brief                Returns the component state of a given subcomponent.

  @description          Returns the component state of a given subcomponent. 
                        Attention: Does not accept a bitfield with more than one active subcomponent!!

  @return               ACDCCompState_t : State of the requested subcomponent.

  @param[in]            SubCompIndex : Index of the subcomponent of which the state shall be reported.

  @glob_in              @ref ACDC_p_GetFrameData
  @glob_out             None

  @c_switch_part        None
  @c_switch_full        @ref ACDC_CFG_FRAME\n

  @pre                  None
  @post                 None

  @InOutCorrelation     see description

  @testmethod           @ref TEST_ACDC_E_GETSUBCOMPSTATE_001 \n
                        @ref TEST_ACDC_E_GETSUBCOMPSTATE_002

  @traceability          Design Decision

  @author               Andreas Danner | Andreas.Danner@continental-corporation.com | +49 (8382) 9699-4995
*************************************************************************************************************************/
ACDCCompState_t ACDC_e_GetSubCompState(ACDCSubCompIndices_t const SubCompIndex)
{
  ACDCCompState_t CompState = COMP_STATE_PERMANENT_ERROR;
  ACDCFrame_t const * const pFrame = ACDC_p_GetFrameData();
  switch(SubCompIndex)
  {
    /*PRQA S 2205 SWITCHCASE*/ /* date: 2018-08-29, reviewer: Danner Andreas (uid41765), reason: Writing in one line increases readability.*/
    case ACDC_SUB_COMP_ACDC:     CompState = pFrame->eACDCState; break;
    case ACDC_SUB_COMP_CD:       CompState = pFrame->eCDState;   break;
    case ACDC_SUB_COMP_AIP:      CompState = pFrame->eAIPState;  break;
    case ACDC_SUB_COMP_ESPM:     CompState = pFrame->eESPMState; break;
    case ACDC_SUB_COMP_SFL:      CompState = COMP_STATE_RUNNING; break;
    case ACDC_SUB_COMP_EMP:      CompState = COMP_STATE_RUNNING; break;
   /* PRQA S 3119 1 #Date:2020-06-01, Reviewer: Praveen Annareddy , Reason: This code is placed for assertive failure and hence cannot be removed */
    default:                     ACDC_ASSERT(FALSE);             break; /* The Desired state does not exist, Return Error */
    /*PRQA L:SWITCHCASE*/
  }
  return CompState;
}


/*************************************************************************************************************************
  Functionname:         ACDC_e_GetWorstSubComponentState                                                             */ /*!

  @brief                Returns the worst of all requested subcomponent states

  @description          Loops through all SubComponent States. If a state is requested by the Bit Filed SubCompIndices 
                        and its criticality is above the current one, the comp state is set to that state.
                        @startuml ACDC_e_GetWorstSubComponentState
                        start
                          :Current State = Least critical state;
                          partition "Execute for each subcomponent state" {
                            if(State is requested?) then (Yes)
                              #Orange:Get New State criticality:
                              <b>ACDC_u_GetMostCritCompState</b> >
                              if(New state criticality is above the current one?) then (Yes)
                                :1}
                                :Current State = New State;
                              else
                                :2}
                              endif
                            else
                              :3}
                            endif
                          }
                        stop
                        @enduml

  @return               ACDCCompState_t

  @param[in]            SubCompIndices : Bitfield of all Subcomponents that shall be considered for the   
                                         determination of the most critical state. @range[ACDC_SUB_COMP_NONE,ACDC_SUB_COMP_ALL]

  @glob_in              None
  @glob_out             None

  @c_switch_part        None
  @c_switch_full        @ref ACDC_CFG_FRAME\n

  @pre                  None
  @post                 None

  @InOutCorrelation     See description

  @testmethod           @ref TEST_ACDC_E_GETWORSTSUBCOMPONENTSTATE_001 

  @traceability         Design Decision

  @author               Andreas Danner | Andreas.Danner@continental-corporation.com | +49 (8382) 9699-4995
*************************************************************************************************************************/
ACDCCompState_t ACDC_e_GetWorstSubComponentState(ACDCSubCompIndices_t const SubCompIndices)
{
  ACDCCompState_t CompState = COMP_STATE_SUCCESS;
  uint32 uSubCompNo;

  for(uSubCompNo = 0; uSubCompNo < ACDC_NOF_SUB_COMPONENTS; ++uSubCompNo)
  {
    ACDCSubCompIndices_t eCurrSubCompIndex = (ACDCSubCompIndices_t)(1u<<uSubCompNo);
    /* Check if the bitfield SubCompIndices contains the current SubComp index */
    if(CML_GetBit(SubCompIndices,eCurrSubCompIndex))
    {
      CompState = ACDC_u_GetMostCritCompState(CompState,ACDC_e_GetSubCompState(eCurrSubCompIndex));
    }
  }
  return CompState;
}

/*************************************************************************************************************************
  Functionname:         ACDC_u_GetStateCriticality                                                                  */ /*!

  @brief                Returns a criticality for a given comp state.

  @description          The criticality of the states is:
                        |           State                 | Criticality|
                        |:--------------------------------|:-----------|
                        | COMP_STATE_PERMANENT_ERROR:     |     6      |
                        | COMP_STATE_TEMPORARY_ERROR:     |     5      |
                        | COMP_STATE_NOT_RUNNING:         |     4      |
                        | COMP_STATE_NOT_INITIALIZED:     |     3      |
                        | COMP_STATE_REDUCED_AVAILABILITY:|     2      |
                        | COMP_STATE_RUNNING:             |     1      |
                        | COMP_STATE_SUCCESS:             |     0      |

  @return               uCriticality for a given Comp State

  @param[in]            eCompState : Component state for the the criticality is requested.

  @glob_in              None
  @glob_out             None

  @c_switch_part        None
  @c_switch_full        @ref ACDC_CFG_FRAME

  @pre                  None
  @post                 None

  @InOutCorrelation     see description

  @testmethod           @ref TEST_ACDC_U_GETSTATECRITICALITY_001 \n
                        @ref TEST_ACDC_U_GETSTATECRITICALITY_002 \n
						@ref TEST_ACDC_U_GETSTATECRITICALITY_003

  @traceability          Design Decision

  @author               Andreas Danner | andreas.danner@continental-corporation.com
*************************************************************************************************************************/
/*PRQA S 3334 1*/ /* #date: 2023-02-20, reviewer: Veeresh B, reason: No side effect, Generic Implementation */
static uint8 ACDC_u_GetStateCriticality(ACDCCompState_t eCompState)
{
  uint8 uCriticality;
  switch(eCompState)
  {
    /*PRQA S 3120,2205 SWITCHCASE*/ /* date: 2018-08-29, reviewer: Danner Andreas (uid41765), reason: Definition of macros would degrade readability.*/
    case COMP_STATE_PERMANENT_ERROR:      uCriticality = 6u; break;
    case COMP_STATE_TEMPORARY_ERROR:      uCriticality = 5u; break;
    case COMP_STATE_NOT_RUNNING:          uCriticality = 4u; break;
    case COMP_STATE_NOT_INITIALIZED:      uCriticality = 3u; break;
    case COMP_STATE_REDUCED_AVAILABILITY: uCriticality = 2u; break;
    case COMP_STATE_RUNNING:              uCriticality = 1u; break;
    case COMP_STATE_SUCCESS:              uCriticality = 0u; break;
    default:                              uCriticality = 0u; break;
    /*PRQA L:SWITCHCASE*/
  }

  return uCriticality;
}


/*************************************************************************************************************************
  Functionname:         ACDC_v_InitFrameData                                                                       */ /*!

  @brief                Fills the ACDC frame data variable.

  @description          The information regarding OpMode, VersionNumber, Project ID and CycleCounter of the ACDC 
                        Frame data is updated. Also the subcomponent states are initialized to running. Afterwards \n
                        they are set according to the current OpMode (Exception: if ACDC has not been called in init 
                        yet, all subcomponent states are set to init.)
                        @startuml ACDC_v_SetFrameData_activity.png
                        start
                          :Initialize all subcomponent states 
                          with **COMP_STATE_RUNNING**;
                          note left
                            This is the only position in the code where 
                            the states are set manually. Later on they must 
                            only be set by using **ACDC_v_SetSubComponentStates**
                            to assure that the states can only get worse.
                          end note
                          if(ACDC has been called in init?) then (Yes)
                            :1}
                          else(No)
                            :2}
                            #Orange:Set all subcomponent states to 
                            **COMP_STATE_NOT_INITIALIZED**:
                            <b>ACDC_v_SetSubComponentStates</b> >
                          endif
                          #Orange:Set the subcomponent states according 
                          to the given OpMode:
                          <b>ACDC_v_SetSubComponentStates</b> >
                          :Copy information regarding the project ID, 
                          the version number and the current cycle 
                          counter to the ACDC Frame;
                        stop
                        @enduml
  @return               void

  @param[in]            eOpMode : Current Operation mode in which ACDC is called. Provided by the FCT component.

  @glob_in              @ref ACDC_p_ModFrameData
  @glob_out             @ref ACDC_p_ModFrameData

  @c_switch_part        None
  @c_switch_full        @ref ACDC_CFG_FRAME

  @pre                  None
  @post                 None

  @InOutCorrelation     see description

  @testmethod          @ref TEST_ACDC_V_INITFRAMEDATA_001 \n
                       @ref TEST_ACDC_V_INITFRAMEDATA_002

  @traceability          Design Decision

  @author               Veronika Ehrlinspiel | veronika.ehrlinspiel@continental-corporation.com | +49 (8382) 9699-490
*************************************************************************************************************************/
/*PRQA S 3334 3*/ /* #date: 2023-02-20, reviewer: Veeresh B, reason: No side effect, Generic Implementation */
void ACDC_v_InitFrameData(FCT_OP_MODE_t eOpMode)
{
  ACDCCompState_t eCompState;
  ACDCFrame_t *const pFrame = ACDC_p_ModFrameData();

  /* Store operation mode received from outside in sen frame for freezing */
  pFrame->eOpMode    = eOpMode;
  
  /* Set the states of all subcomponents to the best state, afterwards this state can only change to a more critical state.
  Therefore it is important that this step is done before any subcomponents are called*/
  pFrame->eACDCState = COMP_STATE_RUNNING;
  pFrame->eAIPState  = COMP_STATE_RUNNING;
  pFrame->eCDState   = COMP_STATE_RUNNING;
  pFrame->eESPMState = COMP_STATE_RUNNING;



  /* ensure that each component runs in init state at least once */
  if (pFrame->bIsInitialized != b_TRUE)
  {
    ACDC_v_SetSubComponentStates(ACDC_SUB_COMP_ALL, COMP_STATE_NOT_INITIALIZED);
  }

  /*set component states according to FCT state */
  switch (pFrame->eOpMode)
  {
  case (FCT_OP_MODE_t)FCT_MOD_STARTUP:
  case (FCT_OP_MODE_t)FCT_MOD_INIT:

    /*Call of all Subcomponents in INIT Mode*/
    pFrame->uiVDYSigErrorCnt = 0u;
    eCompState = COMP_STATE_NOT_INITIALIZED;
    
    break;

  case (FCT_OP_MODE_t)FCT_MOD_RUNNING:

    /*Call of all Subcomponents in RUNNING Mode*/
    eCompState = COMP_STATE_RUNNING;
    
    break;

  case (FCT_OP_MODE_t)FCT_MOD_SHUTDOWN:
  case (FCT_OP_MODE_t)FCT_MOD_PAUSE:
    
    /*No call of the subcomponents*/
    eCompState = COMP_STATE_NOT_RUNNING;

    break;

  default:
    
    /*This state should not be reached*/
    ACDC_ASSERT(FALSE); /* PRQA S 3119 # Date:2020-06-01, Reviewer: Praveen Annareddy , Reason: This code is placed for assertive failure and hence cannot be removed */
    eCompState = COMP_STATE_TEMPORARY_ERROR;
    
    break;

  }
  ACDC_v_SetSubComponentStates(ACDC_SUB_COMP_ALL, eCompState);
  
  pFrame->uiCycleCounter++;
  pFrame->Versions.uProjectID           = ACDC_SW_PROJ_ID;
  pFrame->Versions.ACDC_VERSION_AS_TEXT = ACDC_SW_VERSION_NUMBER;
  pFrame->Versions.ACDCSwVersion        = ACDC_SW_VERSION_NUMBER;
}


#endif /*< (ACDC_CFG_FRAME) */

/* ************************************************************************* */
/*   Copyright ADC-GmbH, Lindau                                              */
/* ************************************************************************* */

///\}

