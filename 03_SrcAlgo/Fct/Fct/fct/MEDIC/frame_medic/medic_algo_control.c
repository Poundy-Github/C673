/*! \file **********************************************************************

COMPANY:                   COPYRIGHT (C) Continental AG

PROJECT:                   Mainstream

CPU:                       CPU-Independent

COMPONENT:                 MEDIC (Monitoring Evaluation And Decision For Intervention Control) 

PACKAGENAME:               medic_algo_control.c

DESCRIPTION:               Functions for MEDIC algo control purpose

AUTHOR:                    $Author: Vogl, Armin (uid19462) $

CREATION DATE:             $Date: 2020/09/14 10:00:56CEST $

VERSION:                   $Revision: 1.34 $

**************************************************************************** */

/*****************************************************************************
  INCLUDES
*****************************************************************************/
#include "frame_medic/medic_int.h"

#if (MEDIC_CFG_EMERGENCY_BRAKE_ASSIST)
/*****************************************************************************
  FUNCTION PROTOTYPES
*****************************************************************************/
static uint8 MEDIC_u_GetStateCriticality  (MEDICCompState_t const eCompState);
static MEDICCompState_t MEDIC_u_GetMostCritCompState(MEDICCompState_t const u_stateA, MEDICCompState_t const u_stateB);

/*****************************************************************************
  FUNCTION DEFINITIONS
*****************************************************************************/

#if (MEDIC_CFG_USE_ALGOCOMPSTATE)
/*************************************************************************************************************************
  Functionname:         MEDIC_v_SetAlgoErrorBuffer                                                               */ /*!

  @brief                Write the current error to the error buffer.

  @description          Write the current error to the error buffer. Condition for this is, that the criticality \n
                        of the current error is higher than the one of the error in the buffer.
                        @startuml MEDIC_v_SetAlgoErrorBuffer_activity.png
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
  @c_switch_full        @ref MEDIC_CFG_EMERGENCY_BRAKE_ASSIST \n
                        @ref MEDIC_CFG_USE_ALGOCOMPSTATE

  @pre                  None
  @post                 Properly buffered Error

  @InOutCorrelation     see description

  @testmethod           @Generic_Testmethods

  @traceability        Design Decision

  @author               Christian Obst
*************************************************************************************************************************/
void MEDIC_v_SetAlgoErrorBuffer (GenAlgoQualifiers_t *const pErrorBuffer, const GenAlgoQualifiers_t ErrorQualifier)
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
  Functionname:         MEDIC_v_SignalErrorShutdown                                                              */ /*!

  @brief                Handles the setting of OpModes in case of a shutdown.

  @description          Handles the shutdown for MEDIC and its subcomponents. Depending on whether an 
                        error was detected or not, the states are set as shown in the table below 
                        (@ref MEDIC_v_SetSubComponentStates).
                        @startuml
                        Start
                          If(Is isRecoveryPossible TRUE) then (yes)
                          #orange:Set the states of the subcomponents
                          <b>HEADGetModule</b> >
                          else
                          #orange:Set the states of the subcomponents
                          <b>HEADGetModule</b> >
                          Endif
                        Stop
                        @enduml
  @return               void

  @param[in]            bIsRecoveryPossible : Flag indicating whether a recovery after a error is possible or not.

  @glob_in              None
  @glob_out             @ref MEDIC_p_ModFrameData

  @c_switch_part        None
  @c_switch_full        @ref MEDIC_CFG_EMERGENCY_BRAKE_ASSIST

  @pre                  None
  @post                 None

  @InOutCorrelation
                        |(Sub)Component |   Recovery is possible     | Recovery is not possible   |
                        |:--------------|:---------------------------|----------------------------|
                        |     MEDIC     |COMPONENT IS NOT INITIALIZED|TEMPORARY ERROR IN COMPONENT|
                        |     HEAD      |COMPONENT IS NOT INITIALIZED|TEMPORARY ERROR IN COMPONENT|
                        |      DIM      |COMPONENT IS NOT INITIALIZED|TEMPORARY ERROR IN COMPONENT|
                       

  @testmethod          Test of output data (dynamic module test) 

  @traceability        
                       @satisfy{doors://rbgs854a:40000/?version=2&prodID=0&urn=urn:telelogic::1-503e822e5ec3651e-O-1122-0007e0f8}

  @author              Sadhanashree Srinivasa | Sadhanashree.Srinivasa@continental-corporation.com | +91-80-66791100-8439
*************************************************************************************************************************/
void MEDIC_v_SignalErrorShutdown(const boolean isRecoveryPossible)
{
  MEDIC_p_ModFrameData()->bIsInitialized = b_FALSE;

  if (isRecoveryPossible != b_TRUE)
  {
    MEDIC_v_SetSubComponentStates(MEDIC_SUB_COMP_ALL, COMP_STATE_TEMPORARY_ERROR);
  }
  else
  {
    MEDIC_v_SetSubComponentStates(MEDIC_SUB_COMP_ALL, COMP_STATE_NOT_INITIALIZED);
  }
}


/*************************************************************************************************************************
  Functionname:         MEDIC_u_GetMostCritCompState                                                                  */ /*!

  @brief                Returns the more critical one of two states.

  @description          Gets the criticality of both given states by calling the function @ref MEDIC_u_GetStateCriticality for each. 
                        Afterwards returns the state with the higher criticality.
                        @startuml
                        Start
                          If(Is u_criticalityB greater than u_criticalityA) then (yes)
                          :update u_critCompState by u_stateB;
                          else
                          :update u_critCompState by u_stateA;
                          Endif
                          :Return the u_critCompState;
                        Stop
                        @enduml
  @return               MEDICCompState_t : More critical of the two input component states

  @param[in]            u_stateA : First component state for the comparison
  @param[in]            u_stateB : Second component state for the comparison

  @glob_in              None
  @glob_out             None

  @c_switch_part        None
  @c_switch_full        @ref MEDIC_CFG_EMERGENCY_BRAKE_ASSIST\n

  @pre                  None
  @post                 None

  @InOutCorrelation     Output the most critical Compstate of u_stateA and u_stateB

  @testmethod           Test of output data (dynamic module test) 

  @traceability         
  @satisfy{doors://rbgs854a:40000/?version=2&prodID=0&urn=urn:telelogic::1-503e822e5ec3651e-O-1121-0007e0f8}

  @author               Sadhanashree Srinivasa | Sadhanashree.Srinivasa@continental-corporation.com | +91-80-66791100-8439
*************************************************************************************************************************/
static MEDICCompState_t MEDIC_u_GetMostCritCompState(MEDICCompState_t const u_stateA, 
                                                     MEDICCompState_t const u_stateB)
{
  uint8 const      u_criticalityA  = MEDIC_u_GetStateCriticality(u_stateA);
  uint8 const      u_criticalityB  = MEDIC_u_GetStateCriticality(u_stateB);
  MEDICCompState_t u_critCompState;

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
  Functionname:         MEDIC_v_SetSubComponentStates                                                                 */ /*!

  @brief                Sets the states of the subcomponents indicated by the bitfield SubCompIndices to the given CompState.

  @description          Sets the desired subcomponents to the desired state. The Bitfield shall be filled with 
                        the values of the type @ref MEDICSubCompIndices_t. \n
                        The subcomponents are only set to states which are worse than their current one. This is 
                        assured by using the function @ref MEDIC_u_GetMostCritCompState
                        @startuml
                        Start
                          If(is SubCompIndices is MEDIC_SUB_COMP_MEDIC) then (yes)
                          #orange:Get the most critical state of the subcomponent
                          <b>MEDIC_u_GetMostCritCompState</b> >
                          :update MEDIC CompState;
                          Endif
                          If(is SubCompIndices is MEDIC_SUB_COMP_HEAD) then (yes)
                          #orange:Get the most critical state of the subcomponent
                          <b>MEDIC_u_GetMostCritCompState</b> >
                          :update HEAD CompState;
                          Endif
                          If(is SubCompIndices is MEDIC_SUB_COMP_DIM) then (yes)
                          #orange:Get the most critical state of the subcomponent
                          <b>MEDIC_u_GetMostCritCompState</b> >
                          :update DIM CompState;
                          Endif
                        Stop
                        @enduml
  @return               void

  @param[in]            SubCompIndices : Bitfield with the indices of the subcomponents. @range [@ref MEDIC_SUB_COMP_NONE, @ref MEDIC_SUB_COMP_ALL]
  @param[in]            CompState :      Comp state to which the subcomponents shall be set.

  @glob_inout             @ref MEDIC_p_ModFrameData

  @c_switch_part        None
  @c_switch_full        @ref MEDIC_CFG_EMERGENCY_BRAKE_ASSIST\n

  @pre                  None
  @post                 None

  @InOutCorrelation     Output the Subcomponent state from Input SubCompIndices and CompState

  @testmethod           Test of output data (dynamic module test) 

  @traceability         
                        @satisfy{doors://rbgs854a:40000/?version=2&prodID=0&urn=urn:telelogic::1-503e822e5ec3651e-O-1100-0007e0f8}

  @author               Nagaraja Veerashettappa  | Nagaraja.Veerashettappa@continental-corporation.com 
*************************************************************************************************************************/
void MEDIC_v_SetSubComponentStates(MEDICSubCompIndices_t const SubCompIndices, 
                                   MEDICCompState_t      const CompState)
{
  MEDICFrame_t * const pFrame = MEDIC_p_ModFrameData();
  if(CML_GetBit(SubCompIndices, MEDIC_SUB_COMP_MEDIC))
  {
    pFrame->eMEDICState = MEDIC_u_GetMostCritCompState(pFrame->eMEDICState,CompState);
  }
  if(CML_GetBit(SubCompIndices, MEDIC_SUB_COMP_HEAD))
  {
    pFrame->eHEADState = MEDIC_u_GetMostCritCompState(pFrame->eHEADState,CompState);
  }
  if(CML_GetBit(SubCompIndices, MEDIC_SUB_COMP_DIM) )
  {
    pFrame->eDIMState = MEDIC_u_GetMostCritCompState(pFrame->eDIMState,CompState);
  }
}

/*************************************************************************************************************************
  Functionname:         MEDIC_e_GetSubCompState                                                                       */ /*!

  @brief                Returns the component state of a given subcomponent.

  @description          Returns the component state of a given subcomponent. 
                        Attention: Does not accept a bitfield with more than one active subcomponent!!
                        @startuml
                        Start
                          If(is SubCompIndex is MEDIC_SUB_COMP_MEDIC) then (yes)
                          :update CompState by MEDICState;
                          Endif
                           If(is SubCompIndex is MEDIC_SUB_COMP_HEAD) then (yes)
                          :update CompState by HEADState;
                          Endif
                           If(is SubCompIndex is MEDIC_SUB_COMP_DIM) then (yes)
                          :update CompState by DIMState;
                          Endif
                          :Return CompState;
                        Stop
                        @enduml
  @return               MEDICCompState_t : State of the requested subcomponent.

  @param[in]            SubCompIndex : Index of the subcomponent of which the state shall be reported.

  @glob_in              @ref MEDIC_p_GetFrameData
  @glob_out             None

  @c_switch_part        None
  @c_switch_full        @ref MEDIC_CFG_EMERGENCY_BRAKE_ASSIST\n

  @pre                  None
  @post                 None

  @InOutCorrelation     Output the CompState from the Input SubCompIndex

  @testmethod           Test of output data (dynamic module test)

  @traceability         
  @satisfy{doors://rbgs854a:40000/?version=2&prodID=0&urn=urn:telelogic::1-503e822e5ec3651e-O-1121-0007e0f8}

  @author               Nagaraja Veerashettappa  | Nagaraja.Veerashettappa@continental-corporation.com 
*************************************************************************************************************************/
MEDICCompState_t MEDIC_e_GetSubCompState(MEDICSubCompIndices_t const SubCompIndex)
{
  MEDICCompState_t           CompState = COMP_STATE_PERMANENT_ERROR;
  MEDICFrame_t const * const pFrame    = MEDIC_p_GetFrameData();
  switch(SubCompIndex)
  {
    /*PRQA S 2205 SWITCHCASE*/ /* date: 2018-08-29, reviewer: Danner Andreas (uid41765), reason: Writing in one line increases readability.*/
    case MEDIC_SUB_COMP_MEDIC:    CompState = pFrame->eMEDICState;  break;
    case MEDIC_SUB_COMP_HEAD:     CompState = pFrame->eHEADState;   break;
    case MEDIC_SUB_COMP_DIM:      CompState = pFrame->eDIMState;    break;
    default:                      MEDIC_ASSERT(FALSE);  /*PRQA S 3112 , 3119*//* date: 2019-1-3, reviewer: Pronnoy Chowdhury, Reason: The statement only comes when logic fails ,it is an assertive failure statement  */
                                  break;                /* The Desired state does not exist, Return Error */
    /*PRQA L:SWITCHCASE*/
  }
  return CompState;
}


/*************************************************************************************************************************
  Functionname:         MEDIC_e_GetWorstSubComponentState                                                             */ /*!

  @brief                Returns the worst of all requested subcomponent states

  @description          Loops through all SubComponent States. If a state is requested by the Bit Filed SubCompIndices 
                        and its criticality is above the current one, the comp state is set to that state.
                        @startuml MEDIC_e_GetWorstSubComponentState
                        start
                          :Current State = Least critical state;
                          partition "Execute for each subcomponent state" {
                            if(State is requested?) then (Yes)
                              #Orange:Get New State criticality:
                              <b>MEDIC_u_GetMostCritCompState</b> >
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

  @return               MEDICCompState_t

  @param[in]            SubCompIndices : Bitfield of all Subcomponents that shall be considered for the   
                                         determination of the most critical state. @range[MEDIC_SUB_COMP_NONE,MEDIC_SUB_COMP_ALL]

  @glob_in              None
  @glob_out             None

  @c_switch_part        None
  @c_switch_full        @ref MEDIC_CFG_EMERGENCY_BRAKE_ASSIST\n

  @pre                  None
  @post                 None

  @InOutCorrelation     Output the CompState from the Input SubCompIndices

  @testmethod           Test of output data (dynamic module test)

  @traceability         
                        @satisfy{doors://rbgs854a:40000/?version=2&prodID=0&urn=urn:telelogic::1-503e822e5ec3651e-O-1121-0007e0f8}

  @author               Sadhanashree Srinivasa | Sadhanashree.Srinivasa@continental-corporation.com | +91-80-66791100-8439
*************************************************************************************************************************/
MEDICCompState_t MEDIC_e_GetWorstSubComponentState(MEDICSubCompIndices_t const SubCompIndices)
{
  MEDICCompState_t CompState = COMP_STATE_SUCCESS;
  uint32           uSubCompNo;

  for(uSubCompNo = 0; uSubCompNo < MEDIC_NOF_SUB_COMPONENTS; ++uSubCompNo)
  {
    MEDICSubCompIndices_t eCurrSubCompIndex = (MEDICSubCompIndices_t)(1u<<uSubCompNo);
    /* Check if the bitfield SubCompIndices contains the current SubComp index */
    if(CML_GetBit(SubCompIndices,eCurrSubCompIndex))
    {
      CompState = MEDIC_u_GetMostCritCompState(CompState,MEDIC_e_GetSubCompState(eCurrSubCompIndex));
    }
  }
  return CompState;
}

/*************************************************************************************************************************
  Functionname:         MEDIC_u_GetStateCriticality                                                                  */ /*!

  @brief                Returns a criticality for a given comp state.

  @description          Returns the criticality of the component states 
                        @startuml
                        Start
                          If(is eCompState is COMP_STATE_PERMANENT_ERROR) then (yes)
                          :update uCriticality by 6u;
                          Endif
                          If(is eCompState is COMP_STATE_TEMPORARY_ERROR) then (yes)
                          :update uCriticality by 5u;
                          Endif
                          If(is eCompState is COMP_STATE_NOT_RUNNING) then (yes)
                          :update uCriticality by 4u;
                          Endif
                          If(is eCompState is COMP_STATE_NOT_INITIALIZED) then (yes)
                          :update uCriticality by 3u;
                          Endif
                          If(is eCompState is COMP_STATE_REDUCED_AVAILABILITY) then (yes)
                          :update uCriticality by 2u;
                          Endif
                          If(is eCompState is COMP_STATE_RUNNING) then (yes)
                          :update uCriticality by 1u;
                          Endif
                          If(is eCompState is COMP_STATE_SUCCESS) then (yes)
                          :update uCriticality by 0u;
                          Endif
                          :Return uCriticality;
                        Stop
                          @enduml
  @return               void

  @param[in]            eCompState : Component state for the the criticality is requested.

  @glob_in              None
  @glob_out             None

  @c_switch_part        None
  @c_switch_full        @ref MEDIC_CFG_EMERGENCY_BRAKE_ASSIST

  @pre                  None
  @post                 None

  @InOutCorrelation
                        |           Name of state         | Criticality|
                        |:--------------------------------|:-----------|
                        | COMP_STATE_PERMANENT_ERROR:     |     6      |
                        | COMP_STATE_TEMPORARY_ERROR:     |     5      |
                        | COMP_STATE_NOT_RUNNING:         |     4      |
                        | COMP_STATE_NOT_INITIALIZED:     |     3      |
                        | COMP_STATE_REDUCED_AVAILABILITY:|     2      |
                        | COMP_STATE_RUNNING:             |     1      |
                        | COMP_STATE_SUCCESS:             |     0      |

  @testmethod           Test of output data (dynamic module test)

  @traceability         
                        @satisfy{doors://rbgs854a:40000/?version=2&prodID=0&urn=urn:telelogic::1-503e822e5ec3651e-O-1121-0007e0f8}

  @author               Sadhanashree Srinivasa | Sadhanashree.Srinivasa@continental-corporation.com | +91-80-66791100-8439
*************************************************************************************************************************/
/*PRQA S 3334 1*/ /* #date: 2023-02-20, reviewer: Veeresh B, reason: No side effect, Generic Implementation */
static uint8 MEDIC_u_GetStateCriticality( MEDICCompState_t const eCompState)
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
  Functionname:         MEDIC_v_InitFrameData                                                                       */ /*!

  @brief                Fills the MEDIC frame data variable.

  @description          The information regarding OpMode, VersionNumber, Project ID and CycleCounter of the MEDIC 
                        Frame data is updated. Also the subcomponent states are initialized to running. Afterwards \n
                        they are set according to the current OpMode (Exception: if MEDIC has not been called in init 
                        yet, all subcomponent states are set to init.)
                        @startuml MEDIC_v_InitFrameData_activity.png
                        start
                          :Initialize all subcomponent states 
                          with **COMP_STATE_RUNNING**;
                          note left
                            This is the only position in the code where 
                            the states are set manually. Later on they must 
                            only be set by using **MEDIC_v_SetSubComponentStates**
                            to assure that the states can only get worse.
                          end note
                          if(MEDIC has been called in init?) then (Yes)
                            :1}
                          else(No)
                            :2}
                            #Orange:Set all subcomponent states to 
                            **COMP_STATE_NOT_INITIALIZED**:
                            <b>MEDIC_v_SetSubComponentStates</b> >
                          endif
                          #Orange:Set the subcomponent states according 
                          to the given OpMode:
                          <b>MEDIC_v_SetSubComponentStates</b> >
                          :Copy information regarding the project ID, 
                          the version number and the current cycle 
                          counter to the MEDIC Frame;
                        stop
                        @enduml
  @return               void

  @param[in]            eOpMode : Current Operation mode in which MEDIC is called. Provided by the FCT component.

  @glob_inout             @ref MEDIC_p_ModFrameData

  @c_switch_part        None
  @c_switch_full        @ref MEDIC_CFG_EMERGENCY_BRAKE_ASSIST

  @pre                  None
  @post                 None

  @InOutCorrelation     Initialize the Frame data from the eOpMode 

  @testmethod          Test of output data (dynamic module test)

  @traceability        
                       @satisfy{doors://rbgs854a:40000/?version=2&prodID=0&urn=urn:telelogic::1-503e822e5ec3651e-O-1100-0007e0f8}

  @author              Nagaraja Veerashettappa  | Nagaraja.Veerashettappa@continental-corporation.com 
*************************************************************************************************************************/
/*PRQA S 3334 3*/ /* #date: 2023-02-20, reviewer: Veeresh B, reason: No side effect, Generic Implementation */
void MEDIC_v_InitFrameData(const MEDICOpMode_t  eOpMode)
{
  MEDICCompState_t    eCompState;
  MEDICFrame_t *const pFrame = MEDIC_p_ModFrameData();
  /* Store operation mode received from outside in sen frame for freezing */
  pFrame->eMEDICOpMode = eOpMode;
  /* Set the states of all subcomponents to the best state, afterwards this state can only change to a more critical state.
  Therefore it is important that this step is done before any subcomponents are called */
  pFrame->eMEDICState  = COMP_STATE_RUNNING;
  pFrame->eDIMState    = COMP_STATE_RUNNING;
  pFrame->eHEADState   = COMP_STATE_RUNNING;

  /* ensure that each component runs in init state at least once */
  if (pFrame->bIsInitialized != b_TRUE)
  {
    MEDIC_v_SetSubComponentStates(MEDIC_SUB_COMP_ALL, COMP_STATE_NOT_INITIALIZED);
  }

  /* set component states according to MEDIC OpMode */
  switch (pFrame->eMEDICOpMode)
  {
  case (MEDICOpMode_t)MEDIC_MOD_STARTUP:
  #if (MEDIC_MOD_STARTUP != MEDIC_MOD_INIT)
  case (MEDICOpMode_t)MEDIC_MOD_INIT:
  #endif
    /* Call of all Subcomponents in INIT Mode */
    eCompState = COMP_STATE_NOT_INITIALIZED;
    break;
  case (MEDICOpMode_t)MEDIC_MOD_RUNNING:
    /* Call of all Subcomponents in RUNNING Mode */
    eCompState = COMP_STATE_RUNNING;
    break;
  case (MEDICOpMode_t)MEDIC_MOD_SHUTDOWN:
  #if (MEDIC_MOD_SHUTDOWN != MEDIC_MOD_PAUSE)
  case (MEDICOpMode_t)MEDIC_MOD_PAUSE:
  #endif
    /* No call of the subcomponents */
    eCompState = COMP_STATE_NOT_RUNNING;
    break;
  default:
    /* This state should not be reached */
    MEDIC_ASSERT(FALSE); /*PRQA S 3112 , 3119*//* date: 2019-1-3, reviewer: Pronnoy Chowdhury, Reason: The statement only comes when logic fails ,it is an assertive failure statement  */
    eCompState = COMP_STATE_TEMPORARY_ERROR;
    break;
  }
  MEDIC_v_SetSubComponentStates(MEDIC_SUB_COMP_ALL, eCompState);
  
  pFrame->uiCycleCounter++;
  #if (MEDIC_CFG_HYPOTHESIS_EVAL_AND_DECISION)
  pFrame->Versions.uiHEAD = HEAD_AUTOVERSION;/*PRQA S 4464 4 #date: 2020-06-09, reviewer: Nalina M, reason: Supressing this as there is no side effect*/
  #endif
  #if (MEDIC_CFG_DRIVER_INTENTION_MONITORING)
  pFrame->Versions.uiDIM  = DIM_AUTOVERSION;
  #endif
  #ifdef __PDO__
  pFrame->Versions.MEDIC_VERSION_AS_TEXT = MEDIC_SW_VERSION_NUMBER;
  #else
  pFrame->Versions.MEDICSwVersionNumVar  = MEDIC_SW_VERSION_NUMBER;
  #endif
  pFrame->Versions.uiMedicReleaseClient  = MEDIC_RELEASE_CLIENT;
  pFrame->Versions.uiMedic               = MEDIC_SW_VERSION_NUMBER;
  pFrame->Versions.uiProjectID           = MEDIC_SW_PROJ_ID;
}

#endif /* MEDIC_CFG_EMERGENCY_BRAKE_ASSIST */


