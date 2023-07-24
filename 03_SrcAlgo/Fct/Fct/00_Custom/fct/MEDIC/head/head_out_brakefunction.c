/*! \file **********************************************************************

COMPANY:                   COPYRIGHT (C) Continental AG

PROJECT:                   Mainstream

CPU:                       CPU-Independent

COMPONENT:                 HEAD (Hypothesis Evaluation And Decision)

PACKAGENAME:               head_out_brakefunction.c

DESCRIPTION:               Implementation of the head generic brake function output(replacement for iBrake5 and iBrak6 Module)

AUTHOR:                    $Author: Muddaveeraiah, Nalina (uidn6869) $

CREATION DATE:             $Date: 2020/06/14 02:14:38CEST $

VERSION:                   $Revision: 1.9.1.13 $

LEGACY VERSION:            1.82

**************************************************************************** */

/**
@defgroup head_out_brakefunction HEAD_OUT_BRAKEFUNCTION
@ingroup Medic_head
@{ **/

/*****************************************************************************
INCLUDES
*****************************************************************************/
#include "frame_medic/medic_int.h"
#if !(MEDIC_CFG_HEAD20)
#if (MEDIC_CFG_HYPOTHESIS_EVAL_AND_DECISION)
#ifndef __PDO__
#include <string.h>
#endif /* #ifndef __PDO__ */
#include "head/head_int.h"

/*****************************************************************************
SYMBOLIC CONSTANTS
*****************************************************************************/

#if (HEAD_USE_CROSSING_BRK && HEAD_USE_RAMP_BRK)

/*! @brief Size of TRANSITION TABLE
 */
#define TRANSITION_TABLE_SIZE (111)
#elif (HEAD_USE_CROSSING_BRK)

/*! @brief Size of TRANSITION TABLE
 */
#define TRANSITION_TABLE_SIZE (100)
#elif (HEAD_USE_RAMP_BRK)

/*! @brief Size of TRANSITION TABLE
 */
#define TRANSITION_TABLE_SIZE (91u)
#else

/*! @brief Size of TRANSITION TABLE
 */
#define TRANSITION_TABLE_SIZE (81)
#endif

#if (HEAD_USE_RAMP_BRK)

/*! @brief Minimum value of Ramp out gradiant 
 */
#define RAMPOUT_GRAD_MIN (1.0f)
#endif

/*! @brief Defination of half
 */
#define ONE_HALF (0.5f) 

/*****************************************************************************
MACROS
*****************************************************************************/

/*****************************************************************************
TYPEDEFS
*****************************************************************************/

/*****************************************************************************
CONSTS
*****************************************************************************/

/*****************************************************************************
VARIABLES
*****************************************************************************/
// ego velocity at last activation of Brake Level1 (last state transition from passive to active Level1)
/*!  @cond Doxygen_Suppress */
SET_MEMSEC_VAR(HeadBrakeHostSpeedLastTransToActive)
static fVelocity_t          HeadBrakeHostSpeedLastTransToActive   = 0.0f;  /* Vehicle velocity */
#if (HEAD_USE_ANEC_CTRL == MEDIC_ON)
SET_MEMSEC_VAR(HeadBrakeRelSpeedTransToActive)
static fVelocity_t          HeadBrakeRelSpeedTransToActive        = 0.0f;  /* Rel. speed of target object */
#endif
SET_MEMSEC_VAR(HEADfDurationVehLevelOne)
static float32              HEADfDurationVehLevelOne              = 0.0f;      /*Duration Level1 active*/
SET_MEMSEC_VAR(HEADfDurationVehLevelTwo)
static float32              HEADfDurationVehLevelTwo              = 0.0f;      /*Duration Level2 active*/
SET_MEMSEC_VAR(HEADfDurationVehLevelThree)
static float32              HEADfDurationVehLevelThree            = 0.0f;      /*Duration Level3 active*/
SET_MEMSEC_VAR(HEADfDurationPedLevelOne)
static float32              HEADfDurationPedLevelOne              = 0.0f;      /*Duration Ped Level1 active*/
SET_MEMSEC_VAR(HEADfDurationPedLevelTwo)
static float32              HEADfDurationPedLevelTwo              = 0.0f;      /*Duration Ped Level2 active*/
SET_MEMSEC_VAR(HEADfDurationPedLevelThree)
static float32              HEADfDurationPedLevelThree            = 0.0f;      /*Duration Ped Level3 active */
SET_MEMSEC_VAR(HEADfDurationLongVruLevelOne)
static float32              HEADfDurationLongVruLevelOne          = 0.0f;    /*Duration LongVru Level1 active */
SET_MEMSEC_VAR(HEADfDurationLongVruLevelTwo)
static float32              HEADfDurationLongVruLevelTwo          = 0.0f;    /*Duration LongVru Level2 active */
#if (HEAD_USE_CROSSING_BRK)
SET_MEMSEC_VAR(HEADfDurationCrossBrk)
static float32              HEADfDurationCrossBrk                 = 0.0f;      /*Duration Level3 active*/
#endif
SET_MEMSEC_VAR(HEADRequestedDeceleration)
static float32              HEADRequestedDeceleration             = 0.0f;      /*Requested Deceleration Value*/
SET_MEMSEC_VAR(HEADbBrakeActiveState)
static boolean              HEADbBrakeActiveState                 = b_FALSE;      /*Breake active state status*/
#if (HEAD_USE_RAMP_BRK)
SET_MEMSEC_VAR(HEADbAlreadyRamped)
static boolean              HEADbAlreadyRamped                    = b_FALSE;  /*Head Ramping status of the head brake function*/
#endif
SET_MEMSEC_VAR(HEADActHypNr)
static HEADHypothesisNr_t   HEADActHypNr                          = HEADNoHypothesis;    /*Store the total number of  HEAD Hypothesis */
SET_MEMSEC_VAR(HEADActualBrakeState)
static BrakeState_t         HEADActualBrakeState                  = eBrakeState_PASSIVE;            /*Actual Brake State*/
SET_MEMSEC_VAR(HEADActivatedBrakeState)
static BrakeState_t         HEADActivatedBrakeState               = eBrakeState_PASSIVE;            /*Actual Brake State*/
SET_MEMSEC_VAR(HEADNextBrakeEvent)
static BrakeEvent_t         HEADNextBrakeEvent                    = eBrake_Event_Passive_Activated; /*next Event to react on*/
/*****************************************************************************
PROTOTYPES
*****************************************************************************/
static eGDBError_t HEADOutBrakeFunctionInit                 ( HEADModuleOutputBrakeFunction_t *pPreBrakeFunction);
static eGDBError_t HEADOutBrakeSM                           ( const struct HEADInputData_t *pInputData, const struct HEADModule_t *pModule, HEADModuleOutputBrakeFunction_t *pPreBrakeFunction, 
                                                              const HEADModOutBrakeFunctionPar_t *pPreBrakeFunctionPar);
// Brake Event get functions
static BrakeEvent_t HEADGet_next_event                      ( const HEADModOutBrakeFunctionPar_t *pPreBrakeFunctionPar, const struct HEADInputData_t *pInputData, 
                                                              const HEADModOutBrakeFunctionPar_t **pActivePreBrakeFunctionPar, const struct HEADModule_t **pActiveModule );
static BrakeEvent_t HEADGetNextEventAtVehBrkLvlOne          ( const struct HEADInputData_t *pInputData, const Hypothesis_t *pKinHyp);
static BrakeEvent_t HEADGetNextEventAtVehBrkLvlTwo          ( const struct HEADInputData_t *pInputData );
static BrakeEvent_t HEADGetNextEventAtVehBrkLvlThree        ( const struct HEADInputData_t *pInputData );
static BrakeEvent_t HEADGetNextEventAtPedLvlOne             ( const struct HEADInputData_t *pInputData );
static BrakeEvent_t HEADGetNextEventAtPedLvlTwo             ( const struct HEADInputData_t *pInputData );
static BrakeEvent_t HEADGetNextEventAtPedLvlThree           ( const struct HEADInputData_t *pInputData );
static BrakeEvent_t HEADGetNextEventAtLongVruLvlOne         ( const struct HEADInputData_t *pInputData );
static BrakeEvent_t HEADGetNextEventAtLongVruLvlTwo         ( const struct HEADInputData_t *pInputData );
#if (HEAD_USE_CROSSING_BRK)
static BrakeEvent_t HEADGetNextEventAtCrossBrk              ( const struct HEADInputData_t *pInputData, HEADModule_t *pVeh_AutoBrk3, HEADModule_t *pVeh_AutoBrk2, HEADModule_t *pVeh_AutoBrk1, 
                                                              HEADModule_t *pVeh_CrossBrk);
#endif
static BrakeEvent_t HEADGetNextEventAtPassive               ( void );
#if (HEAD_USE_RAMP_BRK)
static boolean      HEADIsNextEventRamp                     ( float32 fLongVelocity, float32 dVelRampOut, float32 fDeltaVeloCtrl);
#endif
//Brake Output Functions
static BrakeState_t HEADBrakeLevel_PASSIVE_Output           ( const struct HEADInputData_t *pInputData, const struct HEADModule_t *pModule, HEADModuleOutputBrakeFunction_t *pPreBrakeFunction, 
                                                              const HEADModOutBrakeFunctionPar_t *pPreBrakeFunctionPar );
static BrakeState_t HEADBrakeLevel_PED_1_ACTIVE_Output      ( const struct HEADInputData_t *pInputData, const struct HEADModule_t *pModule, HEADModuleOutputBrakeFunction_t *pPreBrakeFunction,
                                                              const HEADModOutBrakeFunctionPar_t *pPreBrakeFunctionPar);
static BrakeState_t HEADBrakeLevel_PED_2_ACTIVE_Output      ( const struct HEADInputData_t *pInputData, const struct HEADModule_t *pModule, HEADModuleOutputBrakeFunction_t *pPreBrakeFunction,
                                                              const HEADModOutBrakeFunctionPar_t *pPreBrakeFunctionPar);
static BrakeState_t HEADBrakeLevel_PED_3_ACTIVE_Output      ( const struct HEADInputData_t *pInputData, const struct HEADModule_t *pModule, HEADModuleOutputBrakeFunction_t *pPreBrakeFunction,
                                                              const HEADModOutBrakeFunctionPar_t *pPreBrakeFunctionPar);
static BrakeState_t HEADBrakeLevel_1_ACTIVE_Output          ( const struct HEADInputData_t *pInputData, const struct HEADModule_t *pModule, HEADModuleOutputBrakeFunction_t *pPreBrakeFunction, 
                                                              const HEADModOutBrakeFunctionPar_t *pPreBrakeFunctionPar );
static BrakeState_t HEADBrakeLevel_2_ACTIVE_Output          ( const struct HEADInputData_t *pInputData, const struct HEADModule_t *pModule, HEADModuleOutputBrakeFunction_t *pPreBrakeFunction, 
                                                              const HEADModOutBrakeFunctionPar_t *pPreBrakeFunctionPar );
static BrakeState_t HEADBrakeLevel_3_ACTIVE_Output          ( const struct HEADInputData_t *pInputData, const struct HEADModule_t *pModule, HEADModuleOutputBrakeFunction_t *pPreBrakeFunction, 
                                                              const HEADModOutBrakeFunctionPar_t *pPreBrakeFunctionPar );
static BrakeState_t HEADBrakeLevel_LongVru_1_ACTIVE_Output  ( const struct HEADInputData_t *pInputData, const struct HEADModule_t *pModule,  HEADModuleOutputBrakeFunction_t *pPreBrakeFunction,
                                                              const HEADModOutBrakeFunctionPar_t *pPreBrakeFunctionPar);
static BrakeState_t HEADBrakeLevel_LongVru_2_ACTIVE_Output  ( const struct HEADInputData_t *pInputData, const struct HEADModule_t *pModule,  HEADModuleOutputBrakeFunction_t *pPreBrakeFunction,
                                                              const HEADModOutBrakeFunctionPar_t *pPreBrakeFunctionPar);
#if (HEAD_USE_CROSSING_BRK)
static BrakeState_t HEADBrakeLevel_CrossBrk_ACTIVE_Output   ( const struct HEADInputData_t *pInputData, const struct HEADModule_t *pModule, HEADModuleOutputBrakeFunction_t *pPreBrakeFunction, 
                                                              const HEADModOutBrakeFunctionPar_t *pPreBrakeFunctionPar );
#endif
#if (HEAD_USE_RAMP_BRK)
static BrakeState_t HEADBrakeLevel_RAMPOUT_Output           ( const struct HEADInputData_t *pInputData, const struct HEADModule_t *pModule, HEADModuleOutputBrakeFunction_t *pPreBrakeFunction, 
                                                              const HEADModOutBrakeFunctionPar_t *pPreBrakeFunctionPar );
#endif
//Brake Activation Function
static eGDBError_t HEADBrakeActivation                      ( const struct HEADInputData_t *pInputData, const struct HEADModule_t *pModule, HEADModuleOutputBrakeFunction_t *pPreBrakeFunction, 
                                                              const HEADModOutBrakeFunctionPar_t *pPreBrakeFunctionPar );
static void        HEADGetBrakeDecel                        ( const HEADModOutBrakeFunctionPar_t * pPreBrakeFunctionPar, float32 fLongVelocity, 
                                                              const eCDHypothesisType_t *peType, boolean *pbInsideVegoRange, float32 *pfBrakeDecel );
#if (HEAD_USE_ANEC_CTRL)
static void        HEADAnecCtrl                             ( const struct HEADModule_t *pModule, HEADModuleOutputBrakeFunction_t *pPreBrakeFunction,
                                                              const HEADModOutBrakeFunctionPar_t * pPreBrakeFunctionPar, float32 fLongVelocity, 
                                                              const Hypothesis_t* pKinHyp, float32 *pfNeededDecel, const boolean *pbInsideVegoRange, float32 *pfBrakeDecel );
#endif
static void        HEADSetAllBrakeModulesToState            ( eHEADSMState_t HEADSMState, const HEADInputData_t *pInputData, eGDBError_t* retValue);
#if (HEAD_USE_CROSSING_BRK)
static float32     HEADGetAnecLong                          ( const HEADModule_t *pModule, const HEADInputData_t *pInputData);
#endif

/*! @endcond */
/*****************************************************************************
DEFINES
*****************************************************************************/

/*****************************************************************************
FUNCTIONS
*****************************************************************************/
/*************************************************************************************************************************
  Functionname:         HEADOutBrakeFunctionInit                                                                    */ /*!

  @brief                Initialize Brake function Output

  @description          This function is used to initialize all Parameters related to Brake function Output.
                        @startuml
                        Start
                        : Initialize Brake Function;
                        Note right: Initialize all the variables related to Brake function\n to Default value;
                        Stop
                        @enduml

  @return               eGDBError_t : GDB_ERROR_NONE is returned when pointers are okay, otherwise an error code is returned.

  @param[out]           pPreBrakeFunction : Pointer to Break Function

  @glob_in              None
  @glob_out             @ref HEADRequestedDeceleration \n           @ref HeadBrakeHostSpeedLastTransToActive \n
                        @ref HeadBrakeRelSpeedTransToActive \n      @ref HEADfDurationVehLevelOne \n
                        @ref HEADfDurationVehLevelTwo \n            @ref HEADfDurationVehLevelThree \n 
                        @ref HEADfDurationPedLevelOne \n            @ref HEADfDurationPedLevelTwo \n
                        @ref HEADfDurationPedLevelThree \n          @ref HEADfDurationLongVruLevelOne \n
                        @ref HEADfDurationLongVruLevelTwo \n        @ref HEADfDurationCrossBrk \n
                        @ref HEADbBrakeActiveState \n               @ref HEADActualBrakeState \n
                        @ref HEADActivatedBrakeState \n             @ref HEADNextBrakeEvent \n
                        @ref HEADbAlreadyRamped

  @c_switch_part        @ref HEAD_USE_ANEC_CTRL \n @ref HEAD_USE_CROSSING_BRK \n @ref HEAD_USE_RAMP_BRK
  @c_switch_full        @ref MEDIC_CFG_HYPOTHESIS_EVAL_AND_DECISION   

  @pre                  None
  @post                 None

  @InOutCorrelation     Not defined
  
  @testmethod           Test of output data (dynamic module test)

  @traceability         Design Decision
  
  @author               Daniel Deitrich| Daniel.Deitrich@continental-corporation.com
*************************************************************************************************************************/
static eGDBError_t HEADOutBrakeFunctionInit(/*Input*/ HEADModuleOutputBrakeFunction_t *pPreBrakeFunction) 
{
  eGDBError_t eError = GDB_ERROR_NONE;
  HEADRequestedDeceleration               = 0.0f;  /*Brake deceleration value*/
  HeadBrakeHostSpeedLastTransToActive     = 0.0f;  /*Ego Velocity speed at transition to active*/
  #if (HEAD_USE_ANEC_CTRL == MEDIC_ON)
  HeadBrakeRelSpeedTransToActive          = 0.0f;  /*Relative speed at transition to active*/
  #endif
  HEADfDurationVehLevelOne                = 0.0f;  /*Duration Level1 active*/
  HEADfDurationVehLevelTwo                = 0.0f;  /*Duration Level2 active*/
  HEADfDurationVehLevelThree              = 0.0f;  /*Duration Level3 active*/
  HEADfDurationPedLevelOne                = 0.0f;  /*Duration Level1 active*/
  HEADfDurationPedLevelTwo                = 0.0f;  /*Duration Level2 active*/
  HEADfDurationPedLevelThree              = 0.0f;  /*Duration Level3 active*/
  HEADfDurationLongVruLevelOne            = 0.0f;  /*Duration Level1 active*/
  HEADfDurationLongVruLevelTwo            = 0.0f;  /*Duration Level2 active*/

  #if (HEAD_USE_CROSSING_BRK)
  HEADfDurationCrossBrk                = 0.0f;  /*Duration Level3 active*/
  #endif
  HEADbBrakeActiveState                = b_FALSE;  /*Brake deceleration activity indicator*/
  HEADActualBrakeState                 = eBrakeState_PASSIVE;   /*Actual Brake State*/
  HEADActivatedBrakeState              = eBrakeState_PASSIVE;   /*Last Brake State for activation*/
  HEADNextBrakeEvent                   = eBrake_Event_Passive_Activated;
  #if (HEAD_USE_RAMP_BRK)
  HEADbAlreadyRamped                   = b_FALSE;
  #endif

  if(pPreBrakeFunction == NULL)
  {
    eError = GDB_ERROR_POINTER_NULL;
  }
  else
  {
    pPreBrakeFunction->pePreBrakeState         = &HEADActualBrakeState;
    pPreBrakeFunction->pbPreBrakeActive        = &HEADbBrakeActiveState;
    pPreBrakeFunction->pfPreBrakeDeceleration  = &HEADRequestedDeceleration;
    pPreBrakeFunction->pfActiveTimeVeh1        = &HEADfDurationVehLevelOne; 
    pPreBrakeFunction->pfActiveTimeVeh2        = &HEADfDurationVehLevelTwo;
    pPreBrakeFunction->pfActiveTimeVeh3        = &HEADfDurationVehLevelThree;
    pPreBrakeFunction->pfActiveTimePed1        = &HEADfDurationPedLevelOne; 
    pPreBrakeFunction->pfActiveTimePed2        = &HEADfDurationPedLevelTwo;
    pPreBrakeFunction->pfActiveTimePed3        = &HEADfDurationPedLevelThree;
    pPreBrakeFunction->pfActiveTimeLongVru1    = &HEADfDurationLongVruLevelOne;
    pPreBrakeFunction->pfActiveTimeLongVru2    = &HEADfDurationLongVruLevelTwo;

    #if (HEAD_USE_CROSSING_BRK)
    pPreBrakeFunction->pfActiveTimeCrossBrk    = &HEADfDurationCrossBrk;
    #endif
    
    pPreBrakeFunction->pActHypNr               = &HEADActHypNr;
  }
  return eError;
}

/*************************************************************************************************************************
  Functionname:         HEADOutBrakeFunction                                                                        */ /*!

  @brief                Custom output function for brake function
  
  @description          custom output function for a 3Level brake output function (former iBrake 5 and iBrake 6 functions)
                        @startuml
                        Start
                        :Set Error as None;
                        If(Null pointer check?)then (Ok)
                            :Fetch Module Output Function internal informations;
                            :Read Module Output Parameter;
                            If (Output Initialization Needed?) then (yes)     
                                : Do initialization for this output type;
                            Else (no)
                                If (Is input Data valid?) then (yes)
                                    : Run Brake State Machine;
                                Else (no)
                                    : Null Pointer Error;
                                Endif
                            Endif           
                        else(not ok)
                                :Set Null Pointer Error;
                        Endif
                        :Return Error;
                        stop
                        @enduml

  @return                eGDBError_t : GDB_ERROR_NONE is returned when pointers are okay, otherwise an error code is returned.

  @param[in]             pInputData : Pointer to HEAD Input data
  @param[in]             pModule : Pointer to a HEAD Module
  @param[in]             bInit : Boolean variable indicates initialization is needed or not
  
  @glob_in               None 
  @glob_out              None  

  @c_switch_part         None 
  @c_switch_full         @ref MEDIC_CFG_HYPOTHESIS_EVAL_AND_DECISION\n @ref MEDIC_CFG_EBA_2ND_SENSOR_CONFIRMATION  

  @pre                   None 
  @post                  None 

  @InOutCorrelation      Not defined 
  
  @testmethod            Test of output data (dynamic module test) 

  @traceability          Design Decision
  
  @author                Armin Vogl | armin.vogl@continental-corporation.com
*************************************************************************************************************************/
eGDBError_t HEADOutBrakeFunction(  const struct HEADInputData_t * pInputData,  
                                   const struct HEADModule_t    * pModule   , 
                                         boolean           bInit      )
{
  eGDBError_t eError = GDB_ERROR_NONE;

  if ((pModule != NULL) && (pModule->pOutput != NULL) && (pModule->pOutputParams != NULL) )
  {
    HEADModuleOutputBrakeFunction_t    *pPreBrakeFunction = (HEADModuleOutputBrakeFunction_t *)((void *)pModule->pOutput);/*PRQA S 0314 #date: 2020-06-02, reviewer: Nalina M, reason: Case to void intended as use of generic interface */ 
    const HEADModOutBrakeFunctionPar_t *pPreBrakeFunctionPar = (const HEADModOutBrakeFunctionPar_t *)(pModule->pOutputParams);

    if (bInit == b_TRUE)
    {
      // Do initialization for this output type
      eError = HEADOutBrakeFunctionInit(pPreBrakeFunction);
    }
    else
    {
      if(pInputData != NULL)
      {
        // Run Brake State Machine 
        eError = HEADOutBrakeSM(pInputData, pModule, pPreBrakeFunction, pPreBrakeFunctionPar);
      }
      else
      {
        eError = GDB_ERROR_POINTER_NULL;
      }
    }
  }
  else 
  {
    eError = GDB_ERROR_POINTER_NULL;
  }
  return eError;
}

/*************************************************************************************************************************
  Functionname:         HEADOutBrakeSM                                                                              */ /*!

  @brief                Brake Output State Machine 

  @description          Transition table which contains all Possible state transitins for brake state machine is Defined.
                        Runs Brake state machine,
                        ->Fetch the current brake state.
                        ->Find the next brake event that is need to be processed by Brake state machine.
                        ->Call output function to execute the state transition.
                        @startuml
                        Start
                        :Define Brake State Machine\n Transition Table;
                        Note left: Brake State Machine Transition table\n containing all valid transitions.
                        :Get Next Brake Event to process;
                        :Fecth the Current State;
                        Note right: Current state of the Brake state machine.
                        :Call output function; 
                        Note right
                        ->Loop over Transition Table and based on current state 
                           and next Event to process, call output function.
                        ->Update Brake State. 
                        End note
                        Stop
                        @enduml
          
  @return               eGDBError_t : GDB_ERROR_NONE is returned when pointers are okay, otherwise an error code is returned.

  @param[in]            pInputData : Pointer to Input data
  @param[in]            pModule : Pointer to a Module
  @param[in]            pPreBrakeFunction : Pointer to Break Function
  @param[in]            pPreBrakeFunctionPar : Pointer to Break Function Parameter
  
  @glob_in              @ref HEADActualBrakeState
  @glob_out             @ref HEADActualBrakeState

  @c_switch_part        @ref HEAD_USE_CROSSING_BRK \n @ref HEAD_USE_RAMP_BRK
  @c_switch_full        @ref MEDIC_CFG_HYPOTHESIS_EVAL_AND_DECISION   

  @pre                  None
  @post                 None

  @InOutCorrelation     Not defined
  
  @testmethod           Test of output data (dynamic module test)

  @traceability         Design Decision
  
  @author               Daniel Deitrich| Daniel.Deitrich@continental-corporation.com
*************************************************************************************************************************/
static eGDBError_t HEADOutBrakeSM(/*Input*/ const struct HEADInputData_t *pInputData,
                                            const struct HEADModule_t *pModule,
                                            HEADModuleOutputBrakeFunction_t *pPreBrakeFunction,
                                            const HEADModOutBrakeFunctionPar_t *pPreBrakeFunctionPar)
{
  //---------------------------------------------------------------------------------
  // Variable declaration -----------------------------------------------------------
  //---------------------------------------------------------------------------------
  /*initialize eError with GDB_ERROR_UNKNOWN_TYPE - will be set to GDB_ERROR_NONE if everything is valid*/
  eGDBError_t eError = GDB_ERROR_UNKNOWN_TYPE;
  // Brake State Machine Transition table containing all valid transitions
  static const Transitions_t transitionTable[TRANSITION_TABLE_SIZE] =  
  {
    /*-----STATE--------,-------------EVENT-------------------,----------------OUTPUT--------------------*/
    /*-----ACTUAL-------,--------------NEXT-------------------,----------------FUNCTION------------------*/
    { eBrakeState_PASSIVE,     eBrake_Event_Passive_Activated,              &HEADBrakeLevel_PASSIVE_Output             }, /* PASSIVE keep          */
    { eBrakeState_PASSIVE,     eBrake_Event_Veh_Level1_Activated,           &HEADBrakeLevel_1_ACTIVE_Output            }, /* PASSIVE to Level1     */
    { eBrakeState_PASSIVE,     eBrake_Event_Veh_Level2_Activated,           &HEADBrakeLevel_2_ACTIVE_Output            }, /* PASSIVE to Level2     */
    { eBrakeState_PASSIVE,     eBrake_Event_Veh_Level3_Activated,           &HEADBrakeLevel_3_ACTIVE_Output            }, /* PASSIVE to Level3     */
    { eBrakeState_PASSIVE,     eBrake_Event_Ped_Level1_Activated,           &HEADBrakeLevel_PED_1_ACTIVE_Output        }, /* PASSIVE to Ped Level1 */
    { eBrakeState_PASSIVE,     eBrake_Event_Ped_Level2_Activated,           &HEADBrakeLevel_PED_2_ACTIVE_Output        }, /* PASSIVE to Ped Level2 */
    { eBrakeState_PASSIVE,     eBrake_Event_Ped_Level3_Activated,           &HEADBrakeLevel_PED_3_ACTIVE_Output        }, /* PASSIVE to Ped Level3 */
    { eBrakeState_PASSIVE,     eBrake_Event_LongVru_Level1_Activated,       &HEADBrakeLevel_LongVru_1_ACTIVE_Output    }, /* PASSIVE to LongVru Level1 */
    { eBrakeState_PASSIVE,     eBrake_Event_LongVru_Level2_Activated,       &HEADBrakeLevel_LongVru_2_ACTIVE_Output    }, /* PASSIVE to LongVru Level2 */
    #if (HEAD_USE_CROSSING_BRK)
    { eBrakeState_PASSIVE,     eBrake_Event_CrossBrk_Activated,             &HEADBrakeLevel_CrossBrk_ACTIVE_Output     }, /* PASSIVE to Cross Brk  */
    #endif
    { eBrakeState_VEH_LEVEL_1, eBrake_Event_Veh_Level1_Activated,           &HEADBrakeLevel_1_ACTIVE_Output            }, /* Level1 keep           */
    { eBrakeState_VEH_LEVEL_1, eBrake_Event_Veh_Level2_Activated,           &HEADBrakeLevel_2_ACTIVE_Output            }, /* Level1 to Level2      */
    { eBrakeState_VEH_LEVEL_1, eBrake_Event_Veh_Level3_Activated,           &HEADBrakeLevel_3_ACTIVE_Output            }, /* Level1 to Level3      */
    { eBrakeState_VEH_LEVEL_1, eBrake_Event_Ped_Level1_Activated,           &HEADBrakeLevel_PED_1_ACTIVE_Output        }, /* Level1 to Ped Level1  */
    { eBrakeState_VEH_LEVEL_1, eBrake_Event_Ped_Level2_Activated,           &HEADBrakeLevel_PED_2_ACTIVE_Output        }, /* Level1 to Ped Level2  */
    { eBrakeState_VEH_LEVEL_1, eBrake_Event_Ped_Level3_Activated,           &HEADBrakeLevel_PED_3_ACTIVE_Output        }, /* Level1 to Ped Level3  */
    { eBrakeState_VEH_LEVEL_1, eBrake_Event_LongVru_Level1_Activated,       &HEADBrakeLevel_LongVru_1_ACTIVE_Output    }, /* Level1 to LongVru Level1 */
    { eBrakeState_VEH_LEVEL_1, eBrake_Event_LongVru_Level2_Activated,       &HEADBrakeLevel_LongVru_2_ACTIVE_Output    }, /* Level1 to LongVru Level2 */

    #if (HEAD_USE_CROSSING_BRK)
    { eBrakeState_VEH_LEVEL_1, eBrake_Event_CrossBrk_Activated,             &HEADBrakeLevel_CrossBrk_ACTIVE_Output     }, /* Level1 to Cross Brk   */
    #endif
    { eBrakeState_VEH_LEVEL_1, eBrake_Event_Passive_Activated,              &HEADBrakeLevel_PASSIVE_Output             }, /* Level1 to PASSIVE     */
    #if (HEAD_USE_RAMP_BRK)
    { eBrakeState_VEH_LEVEL_1, eBrake_Event_Rampout_Activated,              &HEADBrakeLevel_RAMPOUT_Output             }, /* Level1 to RAMPOUT     */
    #endif
    { eBrakeState_VEH_LEVEL_2, eBrake_Event_Veh_Level1_Activated,           &HEADBrakeLevel_1_ACTIVE_Output            }, /* Level2 to Level1      */
    { eBrakeState_VEH_LEVEL_2, eBrake_Event_Veh_Level2_Activated,           &HEADBrakeLevel_2_ACTIVE_Output            }, /* Level2 keep           */
    { eBrakeState_VEH_LEVEL_2, eBrake_Event_Veh_Level3_Activated,           &HEADBrakeLevel_3_ACTIVE_Output            }, /* Level2 to Level3      */
    { eBrakeState_VEH_LEVEL_2, eBrake_Event_Ped_Level1_Activated,           &HEADBrakeLevel_PED_1_ACTIVE_Output        }, /* Level2 to Ped Level1  */
    { eBrakeState_VEH_LEVEL_2, eBrake_Event_Ped_Level2_Activated,           &HEADBrakeLevel_PED_2_ACTIVE_Output        }, /* Level2 to Ped Level2  */
    { eBrakeState_VEH_LEVEL_2, eBrake_Event_Ped_Level3_Activated,           &HEADBrakeLevel_PED_3_ACTIVE_Output        }, /* Level2 to Ped Level3  */
    { eBrakeState_VEH_LEVEL_2, eBrake_Event_LongVru_Level1_Activated,       &HEADBrakeLevel_LongVru_1_ACTIVE_Output    }, /* Level2 to LongVru Level1 */
    { eBrakeState_VEH_LEVEL_2, eBrake_Event_LongVru_Level2_Activated,       &HEADBrakeLevel_LongVru_2_ACTIVE_Output    }, /* Level2 to LongVru Level2 */

    #if (HEAD_USE_CROSSING_BRK)
    { eBrakeState_VEH_LEVEL_2, eBrake_Event_CrossBrk_Activated,             &HEADBrakeLevel_CrossBrk_ACTIVE_Output     }, /* Level2 to Cross Brk   */
    #endif
    { eBrakeState_VEH_LEVEL_2, eBrake_Event_Passive_Activated,              &HEADBrakeLevel_PASSIVE_Output             }, /* Level2 to PASSIVE     */
    #if (HEAD_USE_RAMP_BRK)
    { eBrakeState_VEH_LEVEL_2, eBrake_Event_Rampout_Activated,              &HEADBrakeLevel_RAMPOUT_Output             }, /* Level2 to RAMPOUT     */
    #endif
    { eBrakeState_VEH_LEVEL_3, eBrake_Event_Veh_Level1_Activated,           &HEADBrakeLevel_1_ACTIVE_Output            }, /* Level3 to Level1      */
    { eBrakeState_VEH_LEVEL_3, eBrake_Event_Veh_Level2_Activated,           &HEADBrakeLevel_2_ACTIVE_Output            }, /* Level3 to Level2      */
    { eBrakeState_VEH_LEVEL_3, eBrake_Event_Veh_Level3_Activated,           &HEADBrakeLevel_3_ACTIVE_Output            }, /* Level3 keep           */
    { eBrakeState_VEH_LEVEL_3, eBrake_Event_Ped_Level1_Activated,           &HEADBrakeLevel_PED_1_ACTIVE_Output        }, /* Level3 to Ped Level1  */
    { eBrakeState_VEH_LEVEL_3, eBrake_Event_Ped_Level2_Activated,           &HEADBrakeLevel_PED_2_ACTIVE_Output        }, /* Level3 to Ped Level2  */
    { eBrakeState_VEH_LEVEL_3, eBrake_Event_Ped_Level3_Activated,           &HEADBrakeLevel_PED_3_ACTIVE_Output        }, /* Level3 to Ped Level3  */
    { eBrakeState_VEH_LEVEL_3, eBrake_Event_LongVru_Level1_Activated,       &HEADBrakeLevel_LongVru_1_ACTIVE_Output    }, /* Level3 to LongVru Level1 */
    { eBrakeState_VEH_LEVEL_3, eBrake_Event_LongVru_Level2_Activated,       &HEADBrakeLevel_LongVru_2_ACTIVE_Output    }, /* Level3 to LongVru Level2 */

    #if (HEAD_USE_CROSSING_BRK)
    { eBrakeState_VEH_LEVEL_3, eBrake_Event_CrossBrk_Activated,             &HEADBrakeLevel_CrossBrk_ACTIVE_Output     }, /* Level3 to Cross Brk   */
    #endif
    { eBrakeState_VEH_LEVEL_3, eBrake_Event_Passive_Activated,              &HEADBrakeLevel_PASSIVE_Output             }, /* Level3 to PASSIVE     */
    #if (HEAD_USE_RAMP_BRK)
    { eBrakeState_VEH_LEVEL_3, eBrake_Event_Rampout_Activated,              &HEADBrakeLevel_RAMPOUT_Output             }, /* Level3 to RAMPOUT     */
    #endif
    { eBrakeState_PED_LEVEL_1, eBrake_Event_Veh_Level1_Activated,           &HEADBrakeLevel_1_ACTIVE_Output            }, /* Ped Level1 to Level1  */
    { eBrakeState_PED_LEVEL_1, eBrake_Event_Veh_Level2_Activated,           &HEADBrakeLevel_2_ACTIVE_Output            }, /* Ped Level1 to Level2  */
    { eBrakeState_PED_LEVEL_1, eBrake_Event_Veh_Level3_Activated,           &HEADBrakeLevel_3_ACTIVE_Output            }, /* Ped Level1 to Level3  */
    { eBrakeState_PED_LEVEL_1, eBrake_Event_Ped_Level1_Activated,           &HEADBrakeLevel_PED_1_ACTIVE_Output        }, /* Ped Level1 keep       */
    { eBrakeState_PED_LEVEL_1, eBrake_Event_Ped_Level2_Activated,           &HEADBrakeLevel_PED_2_ACTIVE_Output        }, /* Ped Level1 to Ped Level 2 */
    { eBrakeState_PED_LEVEL_1, eBrake_Event_Ped_Level3_Activated,           &HEADBrakeLevel_PED_3_ACTIVE_Output        }, /* Ped Level1 to Ped Level 3 */
    { eBrakeState_PED_LEVEL_1, eBrake_Event_Passive_Activated,              &HEADBrakeLevel_PASSIVE_Output             }, /* Ped Level1 to PASSIVE */
    { eBrakeState_PED_LEVEL_1, eBrake_Event_LongVru_Level1_Activated,       &HEADBrakeLevel_LongVru_1_ACTIVE_Output    }, /* Ped Level1 to LongVru Level1 */
    { eBrakeState_PED_LEVEL_1, eBrake_Event_LongVru_Level2_Activated,       &HEADBrakeLevel_LongVru_2_ACTIVE_Output    }, /* Ped Level1 to LongVru Level2 */

    #if (HEAD_USE_RAMP_BRK)
    { eBrakeState_PED_LEVEL_1, eBrake_Event_Rampout_Activated,              &HEADBrakeLevel_RAMPOUT_Output             }, /* Ped Level1 to RAMPOUT */
    #endif
    #if (HEAD_USE_CROSSING_BRK)
    { eBrakeState_PED_LEVEL_1, eBrake_Event_CrossBrk_Activated,             &HEADBrakeLevel_CrossBrk_ACTIVE_Output     }, /* Ped Level1 to Cross Brk */
    #endif
    { eBrakeState_PED_LEVEL_2, eBrake_Event_Veh_Level1_Activated,           &HEADBrakeLevel_1_ACTIVE_Output            }, /* Ped Level2 to Level1  */
    { eBrakeState_PED_LEVEL_2, eBrake_Event_Veh_Level2_Activated,           &HEADBrakeLevel_2_ACTIVE_Output            }, /* Ped Level2 to Level2  */
    { eBrakeState_PED_LEVEL_2, eBrake_Event_Veh_Level3_Activated,           &HEADBrakeLevel_3_ACTIVE_Output            }, /* Ped Level2 to Level3  */
    { eBrakeState_PED_LEVEL_2, eBrake_Event_Ped_Level1_Activated,           &HEADBrakeLevel_PED_1_ACTIVE_Output        }, /* Ped Level2 to Ped Level 1 */
    { eBrakeState_PED_LEVEL_2, eBrake_Event_Ped_Level2_Activated,           &HEADBrakeLevel_PED_2_ACTIVE_Output        }, /* Ped Level2 keep       */
    { eBrakeState_PED_LEVEL_2, eBrake_Event_Ped_Level3_Activated,           &HEADBrakeLevel_PED_3_ACTIVE_Output        }, /* Ped Level2 to Ped Level 3 */
    { eBrakeState_PED_LEVEL_2, eBrake_Event_Passive_Activated,              &HEADBrakeLevel_PASSIVE_Output             }, /* Ped Level2 to PASSIVE */
    { eBrakeState_PED_LEVEL_2, eBrake_Event_LongVru_Level1_Activated,       &HEADBrakeLevel_LongVru_1_ACTIVE_Output    }, /* Ped Level2 to LongVru Level1 */
    { eBrakeState_PED_LEVEL_2, eBrake_Event_LongVru_Level2_Activated,       &HEADBrakeLevel_LongVru_2_ACTIVE_Output    }, /* Ped Level2 to LongVru Level2 */
    #if (HEAD_USE_RAMP_BRK)
    { eBrakeState_PED_LEVEL_2, eBrake_Event_Rampout_Activated,              &HEADBrakeLevel_RAMPOUT_Output             }, /* Ped Level2 to RAMPOUT */
    #endif
    #if (HEAD_USE_CROSSING_BRK)
    { eBrakeState_PED_LEVEL_2, eBrake_Event_CrossBrk_Activated,             &HEADBrakeLevel_CrossBrk_ACTIVE_Output     }, /* Ped Level2 to Cross Brk */
    #endif
    { eBrakeState_PED_LEVEL_3, eBrake_Event_Veh_Level1_Activated,           &HEADBrakeLevel_1_ACTIVE_Output            }, /* Ped Level3 to Level1  */
    { eBrakeState_PED_LEVEL_3, eBrake_Event_Veh_Level2_Activated,           &HEADBrakeLevel_2_ACTIVE_Output            }, /* Ped Level3 to Level2  */
    { eBrakeState_PED_LEVEL_3, eBrake_Event_Veh_Level3_Activated,           &HEADBrakeLevel_3_ACTIVE_Output            }, /* Ped Level3 to Level3  */
    { eBrakeState_PED_LEVEL_3, eBrake_Event_Ped_Level1_Activated,           &HEADBrakeLevel_PED_1_ACTIVE_Output        }, /* Ped Level3 to Ped Level 1 */
    { eBrakeState_PED_LEVEL_3, eBrake_Event_Ped_Level2_Activated,           &HEADBrakeLevel_PED_2_ACTIVE_Output        }, /* Ped Level3 to Ped Level 2 */
    { eBrakeState_PED_LEVEL_3, eBrake_Event_Ped_Level3_Activated,           &HEADBrakeLevel_PED_3_ACTIVE_Output        }, /* Ped Level3 keep       */
    { eBrakeState_PED_LEVEL_3, eBrake_Event_Passive_Activated,              &HEADBrakeLevel_PASSIVE_Output             }, /* Ped Level3 to PASSIVE */
    { eBrakeState_PED_LEVEL_3, eBrake_Event_LongVru_Level1_Activated,       &HEADBrakeLevel_LongVru_1_ACTIVE_Output    }, /* Ped Level3 to LongVru Level1 */
    { eBrakeState_PED_LEVEL_3, eBrake_Event_LongVru_Level2_Activated,       &HEADBrakeLevel_LongVru_2_ACTIVE_Output    }, /* Ped Level3 to LongVru Level2 */

    #if (HEAD_USE_RAMP_BRK)
    { eBrakeState_PED_LEVEL_3, eBrake_Event_Rampout_Activated,              &HEADBrakeLevel_RAMPOUT_Output             }, /* Ped Level3 to RAMPOUT */
    #endif
    #if (HEAD_USE_CROSSING_BRK)
    { eBrakeState_PED_LEVEL_3, eBrake_Event_CrossBrk_Activated,             &HEADBrakeLevel_CrossBrk_ACTIVE_Output     }, /* Ped Level3 to Cross Brk */
    { eBrakeState_CROSSBRK,    eBrake_Event_Veh_Level1_Activated,           &HEADBrakeLevel_1_ACTIVE_Output            }, /* Cross Brk to Level1     */
    { eBrakeState_CROSSBRK,    eBrake_Event_Veh_Level2_Activated,           &HEADBrakeLevel_2_ACTIVE_Output            }, /* Cross Brk to Level2     */
    { eBrakeState_CROSSBRK,    eBrake_Event_Veh_Level3_Activated,           &HEADBrakeLevel_3_ACTIVE_Output            }, /* Cross Brk to Level3     */
    { eBrakeState_CROSSBRK,    eBrake_Event_Ped_Level1_Activated,           &HEADBrakeLevel_PED_1_ACTIVE_Output        }, /* Cross Brk to Ped Level1 */
    { eBrakeState_CROSSBRK,    eBrake_Event_Ped_Level2_Activated,           &HEADBrakeLevel_PED_2_ACTIVE_Output        }, /* Cross Brk to Ped Level2 */
    { eBrakeState_CROSSBRK,    eBrake_Event_Ped_Level3_Activated,           &HEADBrakeLevel_3_ACTIVE_Output            }, /* Cross Brk to Ped Level3 */
    { eBrakeState_CROSSBRK,    eBrake_Event_LongVru_Level1_Activated,       &HEADBrakeLevel_LongVru_1_ACTIVE_Output    }, /* Cross Brk to LongVru Level1 */
    { eBrakeState_CROSSBRK,    eBrake_Event_LongVru_Level2_Activated,       &HEADBrakeLevel_LongVru_2_ACTIVE_Output    }, /* Cross Brk to LongVru Level2 */
    { eBrakeState_CROSSBRK,    eBrake_Event_CrossBrk_Activated,             &HEADBrakeLevel_CrossBrk_ACTIVE_Output     }, /* Cross Brk keep          */
    { eBrakeState_CROSSBRK,    eBrake_Event_Passive_Activated,              &HEADBrakeLevel_PASSIVE_Output             }, /* Cross Brk to PASSIVE    */
    #if (HEAD_USE_RAMP_BRK)       
    { eBrakeState_CROSSBRK,    eBrake_Event_Rampout_Activated,              &HEADBrakeLevel_RAMPOUT_Output             }, /* Cross Brk to RAMPOUT    */
    #endif
    #endif
    { eBrakeState_LongVru_LEVEL_1, eBrake_Event_Veh_Level1_Activated,       &HEADBrakeLevel_1_ACTIVE_Output            }, /* LongVru1 to Level1           */
    { eBrakeState_LongVru_LEVEL_1, eBrake_Event_Veh_Level2_Activated,       &HEADBrakeLevel_2_ACTIVE_Output            }, /* LongVru1 to Level2      */
    { eBrakeState_LongVru_LEVEL_1, eBrake_Event_Veh_Level3_Activated,       &HEADBrakeLevel_3_ACTIVE_Output            }, /* LongVru1 to Level3      */
    { eBrakeState_LongVru_LEVEL_1, eBrake_Event_Ped_Level1_Activated,       &HEADBrakeLevel_PED_1_ACTIVE_Output        }, /* LongVru1 to Ped Level1  */
    { eBrakeState_LongVru_LEVEL_1, eBrake_Event_Ped_Level2_Activated,       &HEADBrakeLevel_PED_2_ACTIVE_Output        }, /* LongVru1 to Ped Level2  */
    { eBrakeState_LongVru_LEVEL_1, eBrake_Event_Ped_Level3_Activated,       &HEADBrakeLevel_PED_3_ACTIVE_Output        }, /* LongVru1 to Ped Level3  */
    { eBrakeState_LongVru_LEVEL_1, eBrake_Event_LongVru_Level1_Activated,   &HEADBrakeLevel_LongVru_1_ACTIVE_Output    }, /* LongVru1 keep */
    { eBrakeState_LongVru_LEVEL_1, eBrake_Event_LongVru_Level2_Activated,   &HEADBrakeLevel_LongVru_2_ACTIVE_Output    }, /* LongVru1 to LongVru Level2 */

    #if (HEAD_USE_CROSSING_BRK)
    { eBrakeState_LongVru_LEVEL_1, eBrake_Event_CrossBrk_Activated,         &HEADBrakeLevel_CrossBrk_ACTIVE_Output     }, /* Level1 to Cross Brk   */
    #endif
    { eBrakeState_LongVru_LEVEL_1, eBrake_Event_Passive_Activated,          &HEADBrakeLevel_PASSIVE_Output             }, /* Level1 to PASSIVE     */
    #if (HEAD_USE_RAMP_BRK)
    { eBrakeState_LongVru_LEVEL_1, eBrake_Event_Rampout_Activated,          &HEADBrakeLevel_RAMPOUT_Output             }, /* Level1 to RAMPOUT     */
    #endif
    { eBrakeState_LongVru_LEVEL_2, eBrake_Event_Veh_Level1_Activated,       &HEADBrakeLevel_1_ACTIVE_Output            }, /* LongVru2 to Level1      */
    { eBrakeState_LongVru_LEVEL_2, eBrake_Event_Veh_Level2_Activated,       &HEADBrakeLevel_2_ACTIVE_Output            }, /* LongVru2 to Level2           */
    { eBrakeState_LongVru_LEVEL_2, eBrake_Event_Veh_Level3_Activated,       &HEADBrakeLevel_3_ACTIVE_Output            }, /* LongVru2 to Level3      */
    { eBrakeState_LongVru_LEVEL_2, eBrake_Event_Ped_Level1_Activated,       &HEADBrakeLevel_PED_1_ACTIVE_Output        }, /* LongVru2 to Ped Level1  */
    { eBrakeState_LongVru_LEVEL_2, eBrake_Event_Ped_Level2_Activated,       &HEADBrakeLevel_PED_2_ACTIVE_Output        }, /* LongVru2 to Ped Level2  */
    { eBrakeState_LongVru_LEVEL_2, eBrake_Event_Ped_Level3_Activated,       &HEADBrakeLevel_PED_3_ACTIVE_Output        }, /* LongVru2 to Ped Level3  */
    { eBrakeState_LongVru_LEVEL_2, eBrake_Event_LongVru_Level1_Activated,   &HEADBrakeLevel_LongVru_1_ACTIVE_Output    }, /* LongVru2 to LongVru Level1 */
    { eBrakeState_LongVru_LEVEL_2, eBrake_Event_LongVru_Level2_Activated,   &HEADBrakeLevel_LongVru_2_ACTIVE_Output    }, /* LongVru2 keep */

    #if (HEAD_USE_CROSSING_BRK)
    { eBrakeState_LongVru_LEVEL_2, eBrake_Event_CrossBrk_Activated,         &HEADBrakeLevel_CrossBrk_ACTIVE_Output     }, /* Level2 to Cross Brk   */
    #endif
    { eBrakeState_LongVru_LEVEL_2, eBrake_Event_Passive_Activated,          &HEADBrakeLevel_PASSIVE_Output             }, /* Level2 to PASSIVE     */
    #if (HEAD_USE_RAMP_BRK)
    { eBrakeState_LongVru_LEVEL_2, eBrake_Event_Rampout_Activated,          &HEADBrakeLevel_RAMPOUT_Output             }, /* Level2 to RAMPOUT     */
    #endif
    #if (HEAD_USE_RAMP_BRK)
    { eBrakeState_RAMP,        eBrake_Event_Rampout_Activated,              &HEADBrakeLevel_RAMPOUT_Output             }, /* RAMPOUT keep         */
    { eBrakeState_RAMP,        eBrake_Event_Passive_Activated,              &HEADBrakeLevel_PASSIVE_Output             }  /* RAMPOUT to PASSIVE   */
    #endif
  };
  // evaluate the maximum index of the state/transition table
  uint8 transTableIndex;
  BrakeState_t currentBrakeState;
  BrakeEvent_t NextBrakeEvent;
  const HEADModule_t *pActiveModule = NULL;
  const HEADModOutBrakeFunctionPar_t *pActivePreBrakeFunctionPar = NULL;

  if((pInputData != NULL) && (pModule != NULL) && (pPreBrakeFunction != NULL) && (pPreBrakeFunctionPar != NULL))
  {

    NextBrakeEvent = HEADGet_next_event (pPreBrakeFunctionPar, pInputData, &pActivePreBrakeFunctionPar, &pActiveModule); /* get the next event to process */
    currentBrakeState = HEADActualBrakeState;

    if(NextBrakeEvent == eBrake_Event_No_New_Event)
    {
      eError = GDB_ERROR_NONE;
    }
    else
    {
      /*loop over transition table - if no transition is valid, (initialized) error will be returned */
      for (transTableIndex = 0; transTableIndex < TRANSITION_TABLE_SIZE; transTableIndex++)
      {
        if (currentBrakeState == transitionTable[transTableIndex].BrakeState)
        {
          if (NextBrakeEvent == transitionTable[transTableIndex].BrakeEvent)
          {
            currentBrakeState = (transitionTable[transTableIndex].pBrakeOutFunction)(pInputData, pActiveModule, pPreBrakeFunction, pActivePreBrakeFunctionPar);
            HEADActualBrakeState = currentBrakeState;
            eError = GDB_ERROR_NONE;
            break;
          }
        }
      }
    }
  }
  else
  {
    eError = GDB_ERROR_POINTER_NULL;
  }
  return eError;
}

/*************************************************************************************************************************
  Functionname:         HEADGet_next_event                                                                          */ /*!

  @brief                Return the next brake event to process

  @description          This function is used to get the Next Brake event that need to be processed by Brake state machine.
                        1)The next brake event is decided on following criteria
                        Active Brake Events:
                          ->If one or more Brake modules are active, based on Active Brake modules and Current Brake state
                            the Next Brake Event is decided, the next brake event can be any event that takes Brake state 
                            Machine to any of the Active Brake state.
                        Brake Event Rampout:
                          ->If none of the Brake modules are active and there is a deceleration request (OR)
                          if necessary deceleration requied to move to ramp out state is achieved, the next brake event is 
                          correspond to Ramp out state 
                        Brake Event Passive:
                          ->If none of the above condiations are true, the brake event corresponds to Passive state is returned.                        
                        2)Update Active module info and Brake input parameter according to event triggered.                         
                        @startuml
                        Start
                        If (Check if all modules have been checked already?) then (yes)
                            : Get Module information;
                        Note left:Get Informations of all the modules related\n to Brake State Machine.
                        partition FindNextEvent {
                        if (Any Brake Module active?) then (yes)
                            : If One or more Brake modules are active
                            ->Based on Active Brake modules and Current Brake state, the Next Brake Event is decided
                            ->Update Active module and Brake function Parameter, based on the module 
                            For which the next event belongs.;
                        elseif ((None of the Brake Module is Active) AND
                                (Requested Deceleration is less than zero) AND
                                (Current brake state is not Passive (or) Current Brake state is Ramp)) then (yes)
                            :->The Next Brake event is correspond to Ramp out state.
                            ->Update Active module and Brake function Parameter, based on Last 
                            Brake state.
                        Note: Ramp out is Possible only if this functionality is enabled.;
                        Else
                            :->The Next Brake event is correspond to Passive state.
                            ->Update Active module and Brake function Parameter as null.;
                        endif
                        }
                        partition ActiveToRamp {
                        If (Is the next event is correspond to passive or Ramp out state?) then (No)
                            :Fetch actual Ego Velocity;
                        Note: Fetch actual Ego velocity from input data.
                            :Fetch actual Ego Acceleration;
                        Note:Fetch actual Ego Acceleration from input data.
                            :Fine Delta Deceleration Velocity Control;
                        Note:It is the maximum Velocity to decelerate.
                            :Get jerk Ramp;
                        Note right:RampOut Gradeient.
                            :Find longitudinal Acceleration limitation;
                        Note left
                        -Use actual vehicle acceleration if pre brake 
                        requested acceleration is below
                        -Else use calculated Decelaration 
                        End note
                            :Calculate the expected velocity reduction\n during ramp-out;
                        If (Check for activation conditions for State RampOut?) then (True)
                            :Next Brake Event is RampOut;
                        Endif
                        Endif
                        }
                        Else (no)
                            :No New Event;
                        Note right
                        ->No new event will be trigerred to Brake State Machine.
                        ->Keep State Machine state and Deceleration from previous run.
                        End note 
                        Endif
                        :Return Next Brake Event;
                        Stop
                        @enduml
     
  @return               BrakeEvent_t : Enum value of Next Brake event to react.

  @param[in]            pPreBrakeFunctionPar : Pointer to Break Function Parameter
  @param[in]            pInputData : Pointer to Input data
  @param[out]           pActivePreBrakeFunctionPar : Pointer to Active Break Function Parameter
  @param[out]           pActiveModule : Pointer to Active Module
  
  @glob_in              @ref HEADActivatedBrakeState \n     @ref HEADActualBrakeState \n
                        @ref HEADbAlreadyRamped \n          @ref HeadBrakeHostSpeedLastTransToActive \n
                        @ref HEADNextBrakeEvent \n          @ref HEADRequestedDeceleration
  @glob_out             @ref HEADNextBrakeEvent \n        

  @c_switch_part        @ref HEAD_USE_RAMP_BRK \n @ref MEDIC_CFG_EBA_2ND_SENSOR_CONFIRMATION \n @ref HEAD_USE_CROSSING_BRK 
  @c_switch_full        @ref MEDIC_CFG_HYPOTHESIS_EVAL_AND_DECISION   

  @pre                  None
  @post                 None

  @InOutCorrelation     Not defined
  
  @testmethod           Test of output data (dynamic module test)

  @traceability         Design Decision
  
  @author               Daniel Deitrich| Daniel.Deitrich@continental-corporation.com
*************************************************************************************************************************/
static BrakeEvent_t HEADGet_next_event(/*Input*/ const HEADModOutBrakeFunctionPar_t *pPreBrakeFunctionPar,
                                                 const struct HEADInputData_t *pInputData, 
                                      /*Output*/ const HEADModOutBrakeFunctionPar_t **pActivePreBrakeFunctionPar,
                                                 const struct HEADModule_t **pActiveModule)
{
  //---------------------------------------------------------------------------------
  // Variable declaration -----------------------------------------------------------
  //---------------------------------------------------------------------------------
  #if (HEAD_USE_RAMP_BRK)
  float32 fLongAcceleration; // current longitudinal acceleration 
  float32 fDeltaVeloCtrl;    // maximum Velocity to decelerate
  fVelocity_t dVelRampOut;   // predicted velocity reduction during ramp-out
  float32 jerkRamp;          // used jerk ramp parameter value
  float32 fLongVelocity = 0.0f; // actual longitudinal velocity
  float32 fLongAccelLim = 0.0f; // longitudinal Acceleration limitation
  #endif
  const Hypothesis_t* pKinHyp = NULL;
  #if (MEDIC_CFG_EBA_2ND_SENSOR_CONFIRMATION)
  uint16 uiModBitF = 0;
  boolean isRunUpStationary  = FALSE; //Flag to indicate if the Hypothesis is RunUp
  #endif
  HEADModule_t *pVeh_AutoBrk1 = NULL;
  HEADModule_t *pVeh_AutoBrk2 = NULL;
  HEADModule_t *pVeh_AutoBrk3 = NULL;
  HEADModule_t *pPed_AutoBrk1 = NULL;
  HEADModule_t *pPed_AutoBrk2 = NULL;
  HEADModule_t *pPed_AutoBrk3 = NULL;
  HEADModule_t *pLongVru_AutoBrk1 = NULL;
  HEADModule_t *pLongVru_AutoBrk2 = NULL;
  #if (HEAD_USE_CROSSING_BRK)
  HEADModule_t *pVeh_CrossBrk = NULL;
  #endif

  /*Check if all modules have been checked already*/
  if(pPreBrakeFunctionPar->HEAD_LAST_MODULE == TRUE)/*PRQA S 1823 #date: 2020-06-11, reviewer: Nalina M, reason: Supressing because while casting a variable, the value can change*/
  {
    /*Get Module information*/
    pVeh_AutoBrk1     = HEADGetModule(pInputData->pModuleList, HEAD_MOD_VEH_BRK_LV1);
    pVeh_AutoBrk2     = HEADGetModule(pInputData->pModuleList, HEAD_MOD_VEH_BRK_LV2);
    pVeh_AutoBrk3     = HEADGetModule(pInputData->pModuleList, HEAD_MOD_VEH_BRK_LV3);
    pPed_AutoBrk1     = HEADGetModule(pInputData->pModuleList, HEAD_MOD_PED_BRK_LV1);
    pPed_AutoBrk2     = HEADGetModule(pInputData->pModuleList, HEAD_MOD_PED_BRK_LV2);
    pPed_AutoBrk3     = HEADGetModule(pInputData->pModuleList, HEAD_MOD_PED_BRK_LV3);
    pLongVru_AutoBrk1 = HEADGetModule(pInputData->pModuleList, HEAD_MOD_LONGVRU_BRK_LV1);
    pLongVru_AutoBrk2 = HEADGetModule(pInputData->pModuleList, HEAD_MOD_LONGVRU_BRK_LV2);
    #if (HEAD_USE_CROSSING_BRK)
    pVeh_CrossBrk = HEADGetModule(pInputData->pModuleList, (uint32) HEAD_MOD_CROSS_BRK);
    #endif
    /*get most critical hypothesis*/
    #if (MEDIC_CFG_EBA_2ND_SENSOR_CONFIRMATION)
    uiModBitF = HEADGetActiveHypothesisForModule(pVeh_AutoBrk1);
    (void) HEADGetMostCritHypOfBitfieldForModule(pInputData, uiModBitF, &pKinHyp, TRUE);
    // Is current Hypothesis Type RunUp Stationary
    if(pKinHyp != NULL)
    {
      isRunUpStationary = (pKinHyp->eType == CDHypothesisType_RunUpStationary);
    }
    #endif

    /*******************************************************/
    /***************** Pedestrian LEVEL 3 ******************/
    /*******************************************************/
    if(  (pPed_AutoBrk3 != NULL)
      && (pPed_AutoBrk3->eSMState == HEADSMState_ACTIVE)
      && (HEADActualBrakeState != eBrakeState_VEH_LEVEL_1)
      && (HEADActualBrakeState != eBrakeState_VEH_LEVEL_2)
      && (HEADActualBrakeState != eBrakeState_VEH_LEVEL_3)
      && (HEADActualBrakeState != eBrakeState_LongVru_LEVEL_1)
      && (HEADActualBrakeState != eBrakeState_LongVru_LEVEL_2)
      #if (HEAD_USE_CROSSING_BRK)
      && (HEADActualBrakeState != eBrakeState_CROSSBRK)
      #endif
      #if (HEAD_USE_RAMP_BRK)
      && (HEADActualBrakeState != eBrakeState_RAMP)
      && (HEADbAlreadyRamped != b_TRUE)
      #endif
      )
    {
      HEADNextBrakeEvent = HEADGetNextEventAtPedLvlThree(pInputData);
      *pActiveModule = pPed_AutoBrk3;
      *pActivePreBrakeFunctionPar = (const HEADModOutBrakeFunctionPar_t *)(pPed_AutoBrk3->pOutputParams);
    }
    /*******************************************************/
    /***************** Pedestrian LEVEL 2 ******************/
    /*******************************************************/
    else if( (pPed_AutoBrk2 != NULL)
      && (pPed_AutoBrk2->eSMState == HEADSMState_ACTIVE)
      && (HEADActualBrakeState != eBrakeState_VEH_LEVEL_1)
      && (HEADActualBrakeState != eBrakeState_VEH_LEVEL_2)
      && (HEADActualBrakeState != eBrakeState_VEH_LEVEL_3)
      && (HEADActualBrakeState != eBrakeState_LongVru_LEVEL_1)
      && (HEADActualBrakeState != eBrakeState_LongVru_LEVEL_2)
      #if (HEAD_USE_CROSSING_BRK)
      && (HEADActualBrakeState != eBrakeState_CROSSBRK)
      #endif
      #if (HEAD_USE_RAMP_BRK)
      && (HEADActualBrakeState != eBrakeState_RAMP)
      && (HEADbAlreadyRamped != b_TRUE)
      #endif
      )
    {
      HEADNextBrakeEvent = HEADGetNextEventAtPedLvlTwo(pInputData);
      *pActiveModule = pPed_AutoBrk2;
      *pActivePreBrakeFunctionPar = (const HEADModOutBrakeFunctionPar_t *)(pPed_AutoBrk2->pOutputParams);
    }
    /*******************************************************/
    /***************** Pedestrian LEVEL 1 ******************/
    /*******************************************************/
    else if( (pPed_AutoBrk1 != NULL)
      && (pPed_AutoBrk1->eSMState == HEADSMState_ACTIVE)
      && (HEADActualBrakeState != eBrakeState_VEH_LEVEL_1)
      && (HEADActualBrakeState != eBrakeState_VEH_LEVEL_2)
      && (HEADActualBrakeState != eBrakeState_VEH_LEVEL_3)
      && (HEADActualBrakeState != eBrakeState_LongVru_LEVEL_1)
      && (HEADActualBrakeState != eBrakeState_LongVru_LEVEL_2)
      #if (HEAD_USE_CROSSING_BRK)
      && (HEADActualBrakeState != eBrakeState_CROSSBRK)
      #endif
      #if (HEAD_USE_RAMP_BRK)
      && (HEADActualBrakeState != eBrakeState_RAMP)
      && (HEADbAlreadyRamped != b_TRUE)
      #endif
      )
    {
      HEADNextBrakeEvent = HEADGetNextEventAtPedLvlOne(pInputData);
      *pActiveModule = pPed_AutoBrk1;
      *pActivePreBrakeFunctionPar = (const HEADModOutBrakeFunctionPar_t *)(pPed_AutoBrk1->pOutputParams);
    }
    /*******************************************************/
    /***************** longitudinal VRU LEVEL 2 ******************/
    /*******************************************************/
    else if(  (pLongVru_AutoBrk2 != NULL)
      && (pLongVru_AutoBrk2->eSMState == HEADSMState_ACTIVE)
      && (HEADActualBrakeState != eBrakeState_VEH_LEVEL_1)
      && (HEADActualBrakeState != eBrakeState_VEH_LEVEL_2)
      && (HEADActualBrakeState != eBrakeState_VEH_LEVEL_3)
      #if (HEAD_USE_CROSSING_BRK)
      && (HEADActualBrakeState != eBrakeState_CROSSBRK)
      #endif
      #if (HEAD_USE_RAMP_BRK)
      && (HEADActualBrakeState != eBrakeState_RAMP)
      && (HEADbAlreadyRamped != b_TRUE)
      #endif
      )
    {
      HEADNextBrakeEvent = HEADGetNextEventAtLongVruLvlTwo(pInputData);
      *pActiveModule = pLongVru_AutoBrk2;
      *pActivePreBrakeFunctionPar = (const HEADModOutBrakeFunctionPar_t *)(pLongVru_AutoBrk2->pOutputParams);
    }
    /*******************************************************/
    /***************** longitudinal VRU LEVEL 1 ******************/
    /*******************************************************/
    else if(  (pLongVru_AutoBrk1 != NULL)
      && (pLongVru_AutoBrk1->eSMState == HEADSMState_ACTIVE)
      && (HEADActualBrakeState != eBrakeState_VEH_LEVEL_1)
      && (HEADActualBrakeState != eBrakeState_VEH_LEVEL_2)
      && (HEADActualBrakeState != eBrakeState_VEH_LEVEL_3)
      #if (HEAD_USE_CROSSING_BRK)
      && (HEADActualBrakeState != eBrakeState_CROSSBRK)
      #endif
      #if (HEAD_USE_RAMP_BRK)
      && (HEADActualBrakeState != eBrakeState_RAMP)
      && (HEADbAlreadyRamped != b_TRUE)
      #endif
      )
    {
      HEADNextBrakeEvent = HEADGetNextEventAtLongVruLvlOne(pInputData);
      *pActiveModule = pLongVru_AutoBrk1;
      *pActivePreBrakeFunctionPar = (const HEADModOutBrakeFunctionPar_t *)(pLongVru_AutoBrk1->pOutputParams);
    }
    #if (HEAD_USE_CROSSING_BRK)
    /*******************************************************/
    /************************ CrossBrk *********************/
    /*******************************************************/
    else if( (pVeh_CrossBrk != NULL)
      &&  (pVeh_CrossBrk->eSMState == HEADSMState_ACTIVE)
      #if (HEAD_USE_RAMP_BRK)
      && (HEADActualBrakeState != eBrakeState_RAMP)
      && (HEADbAlreadyRamped != TRUE)
      #endif
      )
    {
      HEADNextBrakeEvent = HEADGetNextEventAtCrossBrk(pInputData, pVeh_AutoBrk3, pVeh_AutoBrk3, pVeh_AutoBrk3, pVeh_CrossBrk);
      *pActiveModule = pVeh_CrossBrk;
      *pActivePreBrakeFunctionPar = (const HEADModOutBrakeFunctionPar_t *)(pVeh_CrossBrk->pOutputParams);
    }
    #endif
    /*******************************************************/
    /************************* LEVEL 3 *********************/
    /*******************************************************/
    else if ( (pVeh_AutoBrk3 != NULL)
            &&  (pVeh_AutoBrk3->eSMState == HEADSMState_ACTIVE)
            #if (HEAD_USE_CROSSING_BRK)
            && (HEADActualBrakeState != eBrakeState_CROSSBRK)
            #endif
            #if (HEAD_USE_RAMP_BRK)
            && (HEADActualBrakeState != eBrakeState_RAMP)
            && (HEADbAlreadyRamped != b_TRUE)
            #endif
            )
    {
      HEADNextBrakeEvent = HEADGetNextEventAtVehBrkLvlThree(pInputData);
      *pActiveModule = pVeh_AutoBrk3;
      *pActivePreBrakeFunctionPar = (const HEADModOutBrakeFunctionPar_t *)(pVeh_AutoBrk3->pOutputParams);
    }
    /*******************************************************/
    /************************ LEVEL 2 **********************/
    /*******************************************************/
    else if (  (pVeh_AutoBrk2 != NULL)
            && (pVeh_AutoBrk2->eSMState == HEADSMState_ACTIVE)
            #if (HEAD_USE_CROSSING_BRK)
            && (HEADActualBrakeState != eBrakeState_CROSSBRK)
            #endif
            #if (HEAD_USE_RAMP_BRK)
            && (HEADActualBrakeState != eBrakeState_RAMP)
            && (HEADbAlreadyRamped != b_TRUE)
            #endif
            )
    {
      HEADNextBrakeEvent = HEADGetNextEventAtVehBrkLvlTwo(pInputData);
      *pActiveModule = pVeh_AutoBrk2;
      *pActivePreBrakeFunctionPar = (const HEADModOutBrakeFunctionPar_t *)(pVeh_AutoBrk2->pOutputParams);
    }
    /*******************************************************/
    /*********************** LEVEL 1 ***********************/
    /*******************************************************/
    else if (  (pVeh_AutoBrk1 != NULL)
            && (pVeh_AutoBrk1->eSMState == HEADSMState_ACTIVE)
            #if (HEAD_USE_CROSSING_BRK)
            && (HEADActualBrakeState != eBrakeState_CROSSBRK)
            #endif
            #if (HEAD_USE_RAMP_BRK)
            && (HEADActualBrakeState != eBrakeState_RAMP)
            && (HEADbAlreadyRamped != b_TRUE)
            #endif
            )
    {
      HEADNextBrakeEvent = HEADGetNextEventAtVehBrkLvlOne(pInputData, pKinHyp);
      *pActiveModule = pVeh_AutoBrk1;
      *pActivePreBrakeFunctionPar = (const HEADModOutBrakeFunctionPar_t *)(pVeh_AutoBrk1->pOutputParams);
    }

    #if (HEAD_USE_RAMP_BRK)
    /*******************************************************/
    /******************** Ramp out *************************/
    /*******************************************************/

    else if(    (     HEADRequestedDeceleration <  0.0f                    )
             && (    (HEADActualBrakeState      == eBrakeState_RAMP   )
                  || (HEADActualBrakeState      != eBrakeState_PASSIVE) ) )
    {
      HEADNextBrakeEvent = eBrake_Event_Rampout_Activated;
      switch (HEADActivatedBrakeState)
      {
      case eBrakeState_PED_LEVEL_1:
        *pActiveModule = pPed_AutoBrk1;
        if( pPed_AutoBrk1 != NULL )
        {/* PRQA S 0715 *//* date: 2018-10-26, reviewer:Krupa H R, reason: suppressing nesting of control structures   */
          *pActivePreBrakeFunctionPar = (const HEADModOutBrakeFunctionPar_t *)(pPed_AutoBrk1->pOutputParams);
        }
        break;
      case eBrakeState_PED_LEVEL_2:
        *pActiveModule = pPed_AutoBrk2;
        if( pPed_AutoBrk2 != NULL )
        {/* PRQA S 0715 *//* date: 2018-10-26, reviewer:Krupa H R, reason: suppressing nesting of control structures */
          *pActivePreBrakeFunctionPar = (const HEADModOutBrakeFunctionPar_t *)(pPed_AutoBrk2->pOutputParams);
        }
        break;
      case eBrakeState_PED_LEVEL_3:
        *pActiveModule = pPed_AutoBrk3;
        if( pPed_AutoBrk3 != NULL )
        {/* PRQA S 0715 *//* date: 2018-10-26, reviewer:Krupa H R, reason:suppressing nesting of control structures  */
          *pActivePreBrakeFunctionPar = (const HEADModOutBrakeFunctionPar_t *)(pPed_AutoBrk3->pOutputParams);
        }
        break;
      case eBrakeState_VEH_LEVEL_1:
        *pActiveModule = pVeh_AutoBrk1;
        if( pVeh_AutoBrk1 != NULL )
        {/* PRQA S 0715 *//* date: 2018-10-26, reviewer:Krupa H R, reason:suppressing nesting of control structures */
          *pActivePreBrakeFunctionPar = (const HEADModOutBrakeFunctionPar_t *)(pVeh_AutoBrk1->pOutputParams);
        }
        break;
      case eBrakeState_VEH_LEVEL_2:
        *pActiveModule = pVeh_AutoBrk2;
        if( pVeh_AutoBrk2 != NULL )
        {/* PRQA S 0715 *//* date: 2018-10-26, reviewer:Krupa H R, reason: suppressing nesting of control structures */
          *pActivePreBrakeFunctionPar = (const HEADModOutBrakeFunctionPar_t *)(pVeh_AutoBrk2->pOutputParams);
        }
        break;
      case eBrakeState_VEH_LEVEL_3:
        *pActiveModule = pVeh_AutoBrk3;
        if( pVeh_AutoBrk3 != NULL )
        {/* PRQA S 0715 *//* date: 2018-10-26, reviewer:Krupa H R, reason:suppressing nesting of control structures  */
          *pActivePreBrakeFunctionPar = (const HEADModOutBrakeFunctionPar_t *)(pVeh_AutoBrk3->pOutputParams);
        }
        break;
      case eBrakeState_LongVru_LEVEL_1:
        *pActiveModule = pLongVru_AutoBrk1;
        if( pLongVru_AutoBrk1 != NULL )
        {/* PRQA S 0715 *//* date: 2018-10-26, reviewer:Krupa H R, reason: suppressing nesting of control structure*/
          *pActivePreBrakeFunctionPar = (const HEADModOutBrakeFunctionPar_t *)(pLongVru_AutoBrk1->pOutputParams);
        }
        break;
      case eBrakeState_LongVru_LEVEL_2:
        *pActiveModule = pLongVru_AutoBrk2;
        if( pLongVru_AutoBrk2 != NULL )
        {/* PRQA S 0715 *//* date: 2018-10-26, reviewer:Krupa H R, reason: suppressing nesting of control structures */
          *pActivePreBrakeFunctionPar = (const HEADModOutBrakeFunctionPar_t *)(pLongVru_AutoBrk2->pOutputParams);
        }
        break;
      #if (HEAD_USE_CROSSING_BRK)
      case eBrakeState_CROSSBRK:
        *pActiveModule = pVeh_CrossBrk;
        if( pVeh_CrossBrk != NULL)
        {
          *pActivePreBrakeFunctionPar = (const HEADModOutBrakeFunctionPar_t *)(pVeh_CrossBrk->pOutputParams);
        }
        break;
      #endif
      default:
        *pActiveModule = pVeh_AutoBrk1; // Default
        if( pVeh_AutoBrk1 != NULL )
        {/* PRQA S 0715 *//* date: 2018-10-26, reviewer:Krupa H R, reason:  suppressing nesting of control structures */
          *pActivePreBrakeFunctionPar = (const HEADModOutBrakeFunctionPar_t *)(pVeh_AutoBrk1->pOutputParams); // Default
        }
        break;
      }
    }
    #endif /* HEAD_USE_RAMP_BRK */
    /*******************************************************/
    /*********************** Passive ***********************/
    /*******************************************************/
    else
    {
      HEADNextBrakeEvent = HEADGetNextEventAtPassive();
      *pActiveModule = NULL; // Default
      *pActivePreBrakeFunctionPar = NULL; // Default
    }
    #if (HEAD_USE_RAMP_BRK)
    /*******************************************************/
    /******************** Active to Ramp *******************/
    /*******************************************************/
    if(    (HEADNextBrakeEvent != eBrake_Event_Passive_Activated) 
        && (HEADNextBrakeEvent != eBrake_Event_Rampout_Activated))
    {
      /*Calculate Preconditions for Ramp Out*/

      if( (pInputData != NULL)
        &&(*pActivePreBrakeFunctionPar != NULL)
        &&(*pActiveModule != NULL))
      {
        // get actual Ego Velocity
        (void)HEADGetInputValue_float32(pInputData->pInputValueList->LongVelocity, HEAD_DEFAULT_LongVelocity, &fLongVelocity);

        // get actual Ego Acceleration
        (void)HEADGetInputValue_float32(pInputData->pInputValueList->LongAcceleration, HEAD_DEFAULT_LongAccel, &fLongAcceleration);

        // Calculate Preconditions----------------------------
        fDeltaVeloCtrl = HEADCalculatePolygonValuef32((*pActivePreBrakeFunctionPar)->AutoBrkParMaxCtrlVeloReduct_Rows, (*pActivePreBrakeFunctionPar)->AutoBrkParMaxCtrlVeloReduct, HeadBrakeHostSpeedLastTransToActive);
        jerkRamp = MAX_FLOAT((*pActivePreBrakeFunctionPar)->AutoBrkParRampOutGrad, RAMPOUT_GRAD_MIN); // get jerk Ramp Parameter

        // Use actual vehicle acceleration only if pre brake requested acceleration is below
        fLongAccelLim = MAX_FLOAT(fLongAcceleration, HEADRequestedDeceleration);

        // if max. permitted velocity (including ramp-out phase) is reached abort pre brake
        dVelRampOut = (((ONE_HALF * SQR(fLongAccelLim)) / jerkRamp) + ((fABS(fLongAccelLim)* ((*pActivePreBrakeFunctionPar)->AutoBrkParBrakeReactionTime))));
        if (   (HEADIsNextEventRamp(fLongVelocity, dVelRampOut, fDeltaVeloCtrl) == b_TRUE))
        {
          HEADNextBrakeEvent = eBrake_Event_Rampout_Activated;
        }
      }
    }
    #endif
  }
  else
  {
    //do nothing and keep state and decel from previous run
    HEADNextBrakeEvent = eBrake_Event_No_New_Event;
  }
  return HEADNextBrakeEvent;
}/* PRQA S 7004, 7009, 7002 *//* date: 2020-06-01, reviewer:Nalina M, reason: suppressing HIS metrics for better code maintainability*/

/*************************************************************************************************************************
  Functionname:         HEADGetNextEventAtVehBrkLvlOne                                                             */ /*!

  @brief                Get Next Brake Event Corresponds to Vehicle-Brake-Level-1

  @description          This function is used to get the next brake event as the event correspond to Brake state  
                        Vehicle Brake Level-1
                        The Ego velocity is saved during Passive to active brake transition, in order to find achieved
                        decelaration.
                        @startuml
                        Start
                        If (CurrentBrakeState == Passive) then (yes)
                            :Save Ego Vehicle velocity on entry\n to active state;
                        Note
                        Save Vehicle velocity only during transition 
                        from Passive to Active State
                        End note
                        Endif
                        :Return Event correspond to Vehicle-Brake-Level-1;
                        Stop
                        @enduml

  @return               BrakeEvent_t : Enum value of event to Vehicle Brake Level-1.

  @param[in]            pInputData : Pointer to Input data
  @param[in]            pKinHyp : Pointer to  Kinematic Hypotheses
  
  @glob_in              @ref HEADActualBrakeState \n    @ref HeadBrakeHostSpeedLastTransToActive \n
  @glob_out             None 

  @c_switch_part        None
  @c_switch_full        @ref MEDIC_CFG_HYPOTHESIS_EVAL_AND_DECISION   

  @pre                  None
  @post                 None

  @InOutCorrelation     Not defined
  
  @testmethod           Test of output data (dynamic module test)

  @traceability         Design Decision
  
  @author               Daniel Deitrich| Daniel.Deitrich@continental-corporation.com
*************************************************************************************************************************/
static BrakeEvent_t HEADGetNextEventAtVehBrkLvlOne( /*Input*/ const struct HEADInputData_t *pInputData, const Hypothesis_t *pKinHyp)
{
  /************************************* transition level 1 ***************************************************/
  BrakeEvent_t tempNextBrakeEvent = eBrake_Event_Veh_Level1_Activated; // temporary variable to store the next brake event to react on
  _PARAM_UNUSED(pKinHyp);/*PRQA S 3119 #date: 2020-06-02, reviewer: Nalina M, reason: Variable will be used in future. */



  if(pInputData != NULL)
  {
    if(HEADActualBrakeState == eBrakeState_PASSIVE)
    {
      /* save velocity on entry to active state */
      (void)HEADGetInputValue_float32(pInputData->pInputValueList->LongVelocity, HEAD_DEFAULT_LongVelocity, &HeadBrakeHostSpeedLastTransToActive);
    }
  }

  return tempNextBrakeEvent;
}

/*************************************************************************************************************************
  Functionname:         HEADGetNextEventAtVehBrkLvlTwo                                                             */ /*!

  @brief                Get Next Brake Event Corresponds to Vehicle-Brake-Level-2

  @description          This function is used to get the next brake event as the event correspond to Brake state  
                        Vehicle Brake Level-2
                        The Ego velocity is saved during Passive to active brake transition, in order to find achieved
                        decelaration.
                        @startuml
                        Start
                        If (CurrentBrakeState == Passive) then (yes)
                            :Save Ego Vehicle velocity on entry\n to active state;
                        Note
                        Save Vehicle velocity only during transition 
                        from Passive to Active State
                        End note
                        Endif
                        :Return Event correspond to Vehicle-Brake-Level-2;
                        Stop
                        @enduml

  @return               BrakeEvent_t : Enum value of event to Vehicle Brake Level-2.

  @param[in]            pInputData : Pointer to Input data
  
  @glob_in              @ref HEADActualBrakeState \n    @ref HeadBrakeHostSpeedLastTransToActive \n
  @glob_out             None 

  @c_switch_part        None
  @c_switch_full        @ref MEDIC_CFG_HYPOTHESIS_EVAL_AND_DECISION   

  @pre                  None
  @post                 None

  @InOutCorrelation     Not defined
  
  @testmethod           Test of output data (dynamic module test)

  @traceability         Design Decision
  
  @author               Daniel Deitrich| Daniel.Deitrich@continental-corporation.com
*************************************************************************************************************************/
static BrakeEvent_t HEADGetNextEventAtVehBrkLvlTwo( const struct HEADInputData_t *pInputData )
{
  BrakeEvent_t tempNextBrakeEvent = eBrake_Event_Veh_Level2_Activated; // temporary variable to store the next brake event to react on

  if(pInputData != NULL)
  {
    if(HEADActualBrakeState == eBrakeState_PASSIVE)
    {
      /* save velocity on entry to active state */
      (void)HEADGetInputValue_float32(pInputData->pInputValueList->LongVelocity, HEAD_DEFAULT_LongVelocity, &HeadBrakeHostSpeedLastTransToActive);
    }
  }

  return tempNextBrakeEvent;
}

/*************************************************************************************************************************
  Functionname:         HEADGetNextEventAtVehBrkLvlThree                                                             */ /*!

  @brief                Get Next Brake Event Corresponds to Vehicle-Brake-Level-3

  @description          This function is used to get the next brake event as the event correspond to Brake state  
                        Vehicle Brake Level-3
                        The Ego velocity is saved during Passive to active brake transition, in order to find achieved
                        decelaration.
                        @startuml
                        Start
                        If (CurrentBrakeState == Passive) then (yes)
                            :Save Ego Vehicle velocity on entry\n to active state;
                        Note
                        Save Vehicle velocity only during transition 
                        from Passive to Active State
                        End note
                        Endif
                        :Return Event correspond to Vehicle-Brake-Level-3;
                        Stop
                        @enduml

  @return               BrakeEvent_t : Enum value of event to Vehicle Brake Level-3.

  @param[in]            pInputData : Pointer to Input data
  
  @glob_in              @ref HEADActualBrakeState \n    @ref HeadBrakeHostSpeedLastTransToActive \n
  @glob_out             None 

  @c_switch_part        None
  @c_switch_full        @ref MEDIC_CFG_HYPOTHESIS_EVAL_AND_DECISION   

  @pre                  None
  @post                 None

  @InOutCorrelation     Not defined
  
  @testmethod           Test of output data (dynamic module test)

  @traceability         Design Decision
  
  @author               Daniel Deitrich| Daniel.Deitrich@continental-corporation.com
*************************************************************************************************************************/
static BrakeEvent_t HEADGetNextEventAtVehBrkLvlThree( const struct HEADInputData_t *pInputData )
{
  BrakeEvent_t tempNextBrakeEvent = eBrake_Event_Veh_Level3_Activated; // temporary variable to store the next brake event to react on

  if(pInputData != NULL)
  {
    if(HEADActualBrakeState == eBrakeState_PASSIVE)
    {
      /* save velocity on entry to active state */
      (void)HEADGetInputValue_float32(pInputData->pInputValueList->LongVelocity, HEAD_DEFAULT_LongVelocity, &HeadBrakeHostSpeedLastTransToActive);
    }
  }

  return tempNextBrakeEvent;
}

/*************************************************************************************************************************
  Functionname:         HEADGetNextEventAtPedLvlOne                                                                 */ /*!

  @brief                Get Next Brake Event Corresponds to Pedestrian-Brake-Level-1

  @description          This function is used to get the next brake event as the event correspond to Brake state Pedestrian
                        Brake Level-1.
                        The Ego velocity is saved during Passive to active brake transition, in order to find achieved
                        decelaration.
                        @startuml
                        Start
                        If (CurrentBrakeState == Passive) then (yes)
                            :Save Ego Vehicle velocity on entry\n to active state;
                        Note
                        Save Vehicle velocity only during transition 
                        from Passive to Active State
                        End note
                        Endif
                        :Return Event correspond to Pedestrian-Brake-Level-1;
                        Stop
                        @enduml

  @return               BrakeEvent_t : Enum value of event to pedestrian Brake Level-1.

  @param[in]            pInputData : Pointer to Input data
  
  @glob_in              @ref HEADActualBrakeState \n    @ref HeadBrakeHostSpeedLastTransToActive \n
  @glob_out             None 

  @c_switch_part        None
  @c_switch_full        @ref MEDIC_CFG_HYPOTHESIS_EVAL_AND_DECISION   

  @pre                  None
  @post                 None

  @InOutCorrelation     Not defined
  
  @testmethod           Test of output data (dynamic module test)

  @traceability         Design Decision
  
  @author               Daniel Deitrich| Daniel.Deitrich@continental-corporation.com
*************************************************************************************************************************/
static BrakeEvent_t HEADGetNextEventAtPedLvlOne( const struct HEADInputData_t *pInputData )
{
  BrakeEvent_t tempNextBrakeEvent = eBrake_Event_Ped_Level1_Activated; // temporary variable to store the next brake event to react on
  
  if(pInputData != NULL)
  {
    if(HEADActualBrakeState == eBrakeState_PASSIVE)
    {
      /* save velocity on entry to active state */
      (void)HEADGetInputValue_float32(pInputData->pInputValueList->LongVelocity, HEAD_DEFAULT_LongVelocity, &HeadBrakeHostSpeedLastTransToActive);
    }
  }

  return tempNextBrakeEvent;
}

/*************************************************************************************************************************
  Functionname:         HEADGetNextEventAtPedLvlTwo                                                                 */ /*!

  @brief                Get Next Brake Event Corresponds to Pedestrian-Brake-Level-2

  @description          This function is used to get the next brake event as the event correspond to Brake state Pedestrian
                        Brake Level-2.
                        The Ego velocity is saved during Passive to active brake transition, in order to find achieved
                        decelaration.
                        @startuml
                        Start
                        If (CurrentBrakeState == Passive) then (yes)
                            :Save Ego Vehicle velocity on entry\n to active state;
                        Note
                        Save Vehicle velocity only during transition 
                        from Passive to Active State
                        End note
                        Endif
                        :Return Event correspond to Pedestrian-Brake-Level-2;
                        Stop
                        @enduml

  @return               BrakeEvent_t : Enum value of event to pedestrian Brake Level-2.

  @param[in]            pInputData : Pointer to Input data
  
  @glob_in              @ref HEADActualBrakeState \n    @ref HeadBrakeHostSpeedLastTransToActive \n
  @glob_out             None 

  @c_switch_part        None
  @c_switch_full        @ref MEDIC_CFG_HYPOTHESIS_EVAL_AND_DECISION   

  @pre                  None
  @post                 None

  @InOutCorrelation     Not defined
  
  @testmethod           Test of output data (dynamic module test)

  @traceability         Design Decision
  
  @author               Daniel Deitrich| Daniel.Deitrich@continental-corporation.com
*************************************************************************************************************************/
static BrakeEvent_t HEADGetNextEventAtPedLvlTwo( const struct HEADInputData_t *pInputData )
{
  BrakeEvent_t tempNextBrakeEvent = eBrake_Event_Ped_Level2_Activated; // temporary variable to store the next brake event to react on

  if(pInputData != NULL)
  {
    if(HEADActualBrakeState == eBrakeState_PASSIVE)
    {
      /* save velocity on entry to active state */
      (void)HEADGetInputValue_float32(pInputData->pInputValueList->LongVelocity, HEAD_DEFAULT_LongVelocity, &HeadBrakeHostSpeedLastTransToActive);
    }
  }
  return tempNextBrakeEvent;
}

/*************************************************************************************************************************
  Functionname:         HEADGetNextEventAtPedLvlThree                                                               */ /*!

  @brief                Get Next Brake Event Corresponds to Pedestrian-Brake-Level-3

  @description          This function is used to get the next brake event as the event correspond to Brake state Pedestrian
                        Brake Level-3.
                        The Ego velocity is saved during Passive to active brake transition, in order to find achieved
                        decelaration.
                        @startuml
                        Start
                        If (CurrentBrakeState == Passive) then (yes)
                            :Save Ego Vehicle velocity on entry\n to active state;
                        Note
                        Save Vehicle velocity only during transition 
                        from Passive to Active State
                        End note
                        Endif
                        :Return Event correspond to Pedestrian-Brake-Level-3;
                        Stop
                        @enduml

  @return               BrakeEvent_t : Enum value of event to pedestrian Brake Level-3.

  @param[in]            pInputData : Pointer to Input data
  
  @glob_in              @ref HEADActualBrakeState \n    @ref HeadBrakeHostSpeedLastTransToActive \n
  @glob_out             None 

  @c_switch_part        None
  @c_switch_full        @ref MEDIC_CFG_HYPOTHESIS_EVAL_AND_DECISION   

  @pre                  None
  @post                 None

  @InOutCorrelation     Not defined
  
  @testmethod           Test of output data (dynamic module test)

  @traceability         Design Decision
  
  @author               Daniel Deitrich| Daniel.Deitrich@continental-corporation.com
*************************************************************************************************************************/
static BrakeEvent_t HEADGetNextEventAtPedLvlThree( const struct HEADInputData_t *pInputData )
{
  BrakeEvent_t tempNextBrakeEvent = eBrake_Event_Ped_Level3_Activated; // temporary variable to store the next brake event to react on

  if(pInputData != NULL)
  {
    if(HEADActualBrakeState == eBrakeState_PASSIVE)
    {
      /* save velocity on entry to active state */
      (void)HEADGetInputValue_float32(pInputData->pInputValueList->LongVelocity, HEAD_DEFAULT_LongVelocity, &HeadBrakeHostSpeedLastTransToActive);
    }
  }

  return tempNextBrakeEvent;
}

/*************************************************************************************************************************
  Functionname:         HEADGetNextEventAtLongVruLvlOne                                                             */ /*!

  @brief                Get Next Brake Event Corresponds to longitudinal VRU-Brake-Level-1

  @description          This function is used to get the next brake event as the event correspond to Brake state 
                        longitudinal VRU Brake Level-1.
                        The Ego velocity is saved during Passive to active brake transition, in order to find achieved
                        decelaration.
                        @startuml
                        Start
                        If (CurrentBrakeState == Passive) then (yes)
                            :Save Ego Vehicle velocity on entry\n to active state;
                        Note
                        Save Vehicle velocity only during transition 
                        from Passive to Active State
                        End note
                        Endif
                        :Return Event correspond to longitudinal VRU-Brake-Level-1;
                        Stop
                        @enduml

  @return               BrakeEvent_t : Enum value of event to longitudinal VRU Brake Level-1.

  @param[in]            pInputData : Pointer to Input data
  
  @glob_in              @ref HEADActualBrakeState \n    @ref HeadBrakeHostSpeedLastTransToActive \n
  @glob_out             None 

  @c_switch_part        None
  @c_switch_full        @ref MEDIC_CFG_HYPOTHESIS_EVAL_AND_DECISION   

  @pre                  None
  @post                 None

  @InOutCorrelation     Not defined
  
  @testmethod           Test of output data (dynamic module test)

  @traceability         Design Decision
  
  @author               Daniel Deitrich| Daniel.Deitrich@continental-corporation.com
*************************************************************************************************************************/
static BrakeEvent_t HEADGetNextEventAtLongVruLvlOne( const struct HEADInputData_t *pInputData )
{
  BrakeEvent_t tempNextBrakeEvent = eBrake_Event_LongVru_Level1_Activated; // temporary variable to store the next brake event to react on

  if(pInputData != NULL)
  {
    if(HEADActualBrakeState == eBrakeState_PASSIVE)
    {
      /* save velocity on entry to active state */
      (void)HEADGetInputValue_float32(pInputData->pInputValueList->LongVelocity, HEAD_DEFAULT_LongVelocity, &HeadBrakeHostSpeedLastTransToActive);
    }
  }

  return tempNextBrakeEvent;
}

/*************************************************************************************************************************
  Functionname:         HEADGetNextEventAtLongVruLvlTwo                                                             */ /*!

  @brief                Get Next Brake Event Corresponds to longitudinal VRU-Brake-Level-2

  @description          This function is used to get the next brake event as the event correspond to Brake state 
                        longitudinal VRU Brake Level-2.
                        The Ego velocity is saved during Passive to active brake transition, in order to find achieved
                        decelaration.
                        @startuml
                        Start
                        If (CurrentBrakeState == Passive) then (yes)
                            :Save Ego Vehicle velocity on entry\n to active state;
                        Note
                        Save Vehicle velocity only during transition 
                        from Passive to Active State
                        End note
                        Endif
                        :Return Event correspond to longitudinal VRU-Brake-Level-2;
                        Stop
                        @enduml

  @return               BrakeEvent_t : Enum value of event to longitudinal VRU Brake Level-2.

  @param[in]            pInputData : Pointer to Input data
  
  @glob_in              @ref HEADActualBrakeState \n    @ref HeadBrakeHostSpeedLastTransToActive \n
  @glob_out             None 

  @c_switch_part        None
  @c_switch_full        @ref MEDIC_CFG_HYPOTHESIS_EVAL_AND_DECISION   

  @pre                  None
  @post                 None

  @InOutCorrelation     Not defined
  
  @testmethod           Test of output data (dynamic module test)

  @traceability         Design Decision
  
  @author               Daniel Deitrich| Daniel.Deitrich@continental-corporation.com
*************************************************************************************************************************/
static BrakeEvent_t HEADGetNextEventAtLongVruLvlTwo( const struct HEADInputData_t *pInputData )
{
  BrakeEvent_t tempNextBrakeEvent = eBrake_Event_LongVru_Level2_Activated; // temporary variable to store the next brake event to react on

  if(pInputData != NULL)
  {
    if(HEADActualBrakeState == eBrakeState_PASSIVE)
    {
      /* save velocity on entry to active state */
      (void)HEADGetInputValue_float32(pInputData->pInputValueList->LongVelocity, HEAD_DEFAULT_LongVelocity, &HeadBrakeHostSpeedLastTransToActive);
    }
  }

  return tempNextBrakeEvent;
}

#if (HEAD_USE_CROSSING_BRK)
/*************************************************************************************************************************
  Functionname:         HEADGetNextEventAtCrossBrk                                                                  */ /*!

  @brief                Get next event at Crossing-Break

  @description          This function is used to get the next brake event at Cross_Brake. 
                        1)If cross_brake is active with no active Vehicle_Brake Modules, then the 
                        event correspond to Brake state Cross_Brake is returned. (or)
                        2)If cross_brake is active with any of the Vehicle_Brake Modules, then whichever is 
                        having strong needed deceleration the event correspond to that module will be returned.
                        @startuml
                        Start
                        :Set Next brake event as Cross brake;
                        If (Is current Brake state is PASSIVE?) then (yes)
                            : save ego velocity;
                        Note left:save Host speed on entry to active Brake state
                        Endif
                        :Get needed deceleration for Cross break;
                        Floating Note
                        Needed decelerations are fetched from brake module's
                        MostCriticalHypothesis->Needed.acceleration(From CD)
                        End note
                        If (IS VehicleBrakeLevel3 active?) then (yes)
                            :Get needed deceleration for Vehicle Brake Level3;
                        If ((NeededDecelelationCrossBrk >  NeededDecelelationVehicleBrakeLevel3)) then (yes)
                            :Update Next brake event as Vehicle Brake Level3;
                        endif
                        Elseif(Is VehicleBrakeLevel2 active?) then (yes)
                            :Get needed deceleration for Vehicle Brake Level2;
                        If ((NeededDecelelationCrossBrk >  NeededDecelelationVehicleBrakeLevel2)) then (yes)
                            :Update Next brake event as Vehicle Brake Level2;
                        endif
                        Elseif(Is VehicleBrakeLevel1 active?) then (yes)
                            :Get needed deceleration for Vehicle Brake Level1;
                        If ((NeededDecelelationCrossBrk >  NeededDecelelationVehicleBrakeLevel1)) then (yes)
                            :Update Next brake event as Vehicle Brake Level1;
                        endif
                        endif 
                        :Return Next Brake event;
                        Stop
                        @enduml

  @return               BrakeEvent_t : Enum value of Next Brake event to react
  
  @param[in]            pInputData : Pointer to Input data
  @param[in]            pVeh_AutoBrk3 : Pointer to Brake Module Vehicle Brake Level3
  @param[in]            pVeh_AutoBrk2 : Pointer to Brake Module Vehicle Brake Level2
  @param[in]            pVeh_AutoBrk1 : Pointer to Brake Module Vehicle Brake Level1
  @param[in]            pVeh_CrossBrk : Pointer to Brake Module Cross Brake

  @glob_in              @ref HeadBrakeHostSpeedLastTransToActive
  @glob_out             None     

  @c_switch_part        None
  @c_switch_full        @ref MEDIC_CFG_HYPOTHESIS_EVAL_AND_DECISION \n    @ref HEAD_USE_CROSSING_BRK

  @pre                  None
  @post                 None

  @InOutCorrelation     Not defined
  
  @testmethod           Test of output data (dynamic module test)

  @traceability         Design Decision
  
  @author               Daniel Deitrich| Daniel.Deitrich@continental-corporation.com
*************************************************************************************************************************/
static BrakeEvent_t HEADGetNextEventAtCrossBrk( const struct HEADInputData_t *pInputData, HEADModule_t *pVeh_AutoBrk3, HEADModule_t *pVeh_AutoBrk2, HEADModule_t *pVeh_AutoBrk1, HEADModule_t *pVeh_CrossBrk )
{
  float32 fNeededDecelCrossbrk;
  BrakeEvent_t tempNextBrakeEvent = eBrake_Event_CrossBrk_Activated; // temporary variable to store the next brake event to react on

  if(pInputData != NULL)
  {
    if(HEADActualBrakeState == eBrakeState_PASSIVE)
    {
      /* save velocity on entry to active state */
      (void)HEADGetInputValue_float32(pInputData->pInputValueList->LongVelocity, HEAD_DEFAULT_LongVelocity, &HeadBrakeHostSpeedLastTransToActive);
    }
  }

  fNeededDecelCrossbrk = HEADGetAnecLong(pVeh_CrossBrk, pInputData);
  /*Check if a switch to Veh_AutoBrk3 is necessary*/
  if(  (pVeh_AutoBrk3 != NULL)
    && (pVeh_AutoBrk3->eSMState == HEADSMState_ACTIVE)
    )
  {
    float32 fNeededDecelAutoBrk3 = HEADGetAnecLong(pVeh_AutoBrk3, pInputData);
    if (fNeededDecelCrossbrk > fNeededDecelAutoBrk3)
    {
      tempNextBrakeEvent = eBrake_Event_Veh_Level3_Activated;
    }
  }
  else if(   (pVeh_AutoBrk2 != NULL)
          && (pVeh_AutoBrk2->eSMState == HEADSMState_ACTIVE)
         )
  {
    float32 fNeededDecelAutoBrk2 = HEADGetAnecLong(pVeh_AutoBrk2, pInputData);
    if (fNeededDecelCrossbrk > fNeededDecelAutoBrk2)
    {
      tempNextBrakeEvent = eBrake_Event_Veh_Level2_Activated;
    }
  }
  else if(   (pVeh_AutoBrk1 != NULL)
          && (pVeh_AutoBrk1->eSMState == HEADSMState_ACTIVE)
         )
  {
    float32 fNeededDecelAutoBrk1 = HEADGetAnecLong(pVeh_AutoBrk1, pInputData);
    if (fNeededDecelCrossbrk > fNeededDecelAutoBrk1)
    {
      tempNextBrakeEvent = eBrake_Event_Veh_Level1_Activated;
    }
  }
  else
  {
    /*do not change Brake Event in terms of arbitration*/
  }
  return tempNextBrakeEvent;
}
#endif

/*************************************************************************************************************************
  Functionname:         HEADGetNextEventAtPassive                                                                   */ /*!

  @brief                Get Next Brake Event Corresponds to Brake state Passive.

  @description          This function is used to get the next brake event as the event correspond to Brake state  
                        Passive
                        @startuml
                        Start
                        :Return Event correspond to Brake state passive;
                        Stop
                        @enduml

  @return               BrakeEvent_t : Enum value of event to passive state.

  @param[in]            void
  
  @glob_in              None
  @glob_out             None 

  @c_switch_part        None
  @c_switch_full        @ref MEDIC_CFG_HYPOTHESIS_EVAL_AND_DECISION   

  @pre                  None
  @post                 None

  @InOutCorrelation     Not defined
  
  @testmethod           Test of output data (dynamic module test)

  @traceability         Design Decision
  
  @author               Daniel Deitrich| Daniel.Deitrich@continental-corporation.com
*************************************************************************************************************************/
static BrakeEvent_t HEADGetNextEventAtPassive( void )
{
  BrakeEvent_t tempNextBrakeEvent = eBrake_Event_Passive_Activated; // temporary variable to store the next brake event to react on
  return tempNextBrakeEvent;
}

#if (HEAD_USE_RAMP_BRK)
/*************************************************************************************************************************
  Functionname:         HEADIsNextEventRamp                                                                         */ /*!

  @brief                Check for activation of State Ramp Out

  @description          This function is used to check activation condition of state RampOut.
                        Condition for activation of Ramp out State:
                        (HostSpeedDuringTransToActive - CurrentlongitudinalVelocity ) > 
                                                   Max((VelocityToDecelerate-ExpectedVelocityReductionDuringRampOut), 0)
                        @startuml
                        start
                        if(check for Ramp Out activation condition?) then (condition satisfied)
                        :Return True;
                        Else(not satisfied)
                        :Return False;
                        Endif
                        stop
                        @enduml

  @return               boolean : True if the Condition for activation of Ramp is satisfied.

  @param[in]            fLongVelocity : Actual longitudinal velocity
  @param[in]            dVelRampOut : Predicted velocity reduction during ramp-out
  @param[in]            fDeltaVeloCtrl : Velocity to decelerate
  
  @glob_in              @ref HeadBrakeHostSpeedLastTransToActive
  @glob_out             None 

  @c_switch_part        None
  @c_switch_full        @ref MEDIC_CFG_HYPOTHESIS_EVAL_AND_DECISION   

  @pre                  None
  @post                 None

  @InOutCorrelation     Not defined
  
  @testmethod           Test of output data (dynamic module test)

  @traceability         Design Decision
  
  @author               Daniel Deitrich| Daniel.Deitrich@continental-corporation.com
*************************************************************************************************************************/
static boolean HEADIsNextEventRamp( /*Input*/ float32 fLongVelocity,
                                              float32 dVelRampOut,
                                              float32 fDeltaVeloCtrl)
{
  //Variable declaration
  boolean nextEventRamp;       // return value

  /*check for activation conditions of State Ramp Out*/
  if(  ((HeadBrakeHostSpeedLastTransToActive - fLongVelocity) > (MAX_FLOAT((fDeltaVeloCtrl - dVelRampOut), 0.0f)))
    )
  {
    nextEventRamp = b_TRUE;
  }
  else
  {
    nextEventRamp = b_FALSE;
  }

  return nextEventRamp;
}
#endif

/* Transition Functions, declares the actual output and sets the next state */
/*************************************************************************************************************************
  Functionname:         HEADBrakeLevel_PASSIVE_Output                                                               */ /*!

  @brief                Brake Level PASSIVE Output

  @description          This Function is used to reset Brake function output parameters and status bits whenever there is 
                        a transition(Brake Statemachine) from any active brake state or ramp-out state to Passive state.
                        @startuml
                        start
                        :Update Brake State;
                        Note right:Update Brake state as Passive state
                        :Get Module information;
                        Note:Get Informations of all the modules related to Brake State Machine.
                        :Set NoBrakeModuleActive status bit as True;
                        If (Any Brake module is active?) then (yes)
                            :Update NoBrakeModuleActive status bit as False; 
                        Endif
                        If ((Check if Already Ramped) AND 
                            (NoBrakeModuleActive)) then (yes)
                            :Update Ramp status bit as False; 
                        Note:Ramp status bit is needed only if Ramp function is enabled.
                        Endif
                            :Reset Host and Relative speed\n Transition to active;
                        Note right
                        Reset Saved Ego and relative velocity during transition from 
                        Passive to Active State.

                        Note:Relative speed is used only if avoidance deceleration for closed loop control
                        is enabled.
                        End note
                        :Reset timer function;
                        :Update Brake Output function;
                        stop
                        @enduml

  @return               BrakeState_t : Enum value correspond to Brake state passive

  @param[in]            pInputData : Pointer to Input data
  @param[in]            pModule : Pointer to a Module
  @param[out]           pPreBrakeFunction : Pointer to Break Function
  @param[in]            pPreBrakeFunctionPar : Pointer to Break Function Parameter
  
  @glob_in              None
  @glob_out             @ref HEADActualBrakeState \n            @ref HEADActivatedBrakeState \n
                        @ref HEADbAlreadyRamped \n              @ref HeadBrakeHostSpeedLastTransToActive \n
                        @ref HeadBrakeRelSpeedTransToActive \n  @ref HEADbBrakeActiveState \n
                        @ref HEADRequestedDeceleration \n       @ref HEADActHypNr \n
                        @ref HEADfDurationVehLevelOne \n        @ref HEADfDurationVehLevelTwo \n
                        @ref HEADfDurationVehLevelThree \n      @ref HEADfDurationPedLevelOne \n
                        @ref HEADfDurationPedLevelTwo \n        @ref HEADfDurationPedLevelThree \n
                        @ref HEADfDurationLongVruLevelOne \n    @ref HEADfDurationLongVruLevelTwo \n
                        @ref HEADfDurationCrossBrk

  @c_switch_part        @ref HEAD_USE_CROSSING_BRK \n           @ref HEAD_USE_RAMP_BRK \n
                        @ref HEAD_USE_ANEC_CTRL    
  @c_switch_full        @ref MEDIC_CFG_HYPOTHESIS_EVAL_AND_DECISION   

  @pre                  None
  @post                 None

  @InOutCorrelation     Not defined
  
  @testmethod           Test of output data (dynamic module test)

  @traceability         Design Decision
  
  @author               Daniel Deitrich| Daniel.Deitrich@continental-corporation.com
*************************************************************************************************************************/
static BrakeState_t HEADBrakeLevel_PASSIVE_Output( /*Input*/ const struct HEADInputData_t *pInputData,
                                                             const struct HEADModule_t *pModule,
                                                             HEADModuleOutputBrakeFunction_t *pPreBrakeFunction,
                                                             const HEADModOutBrakeFunctionPar_t *pPreBrakeFunctionPar)
{ 
  // Set next Brake State to Passive
  BrakeState_t nextState;
  HEADModule_t *pVeh_AutoBrk1     = NULL;
  HEADModule_t *pVeh_AutoBrk2     = NULL;
  HEADModule_t *pVeh_AutoBrk3     = NULL;
  HEADModule_t *pPed_AutoBrk1     = NULL;
  HEADModule_t *pPed_AutoBrk2     = NULL;
  HEADModule_t *pPed_AutoBrk3     = NULL;
  HEADModule_t *pLongVru_AutoBrk1 = NULL;
  HEADModule_t *pLongVru_AutoBrk2 = NULL;

  #if (HEAD_USE_CROSSING_BRK)
  HEADModule_t *pVeh_CrossBrk = NULL;
  #endif
  HEADActualBrakeState    = eBrakeState_PASSIVE;
  HEADActivatedBrakeState = eBrakeState_PASSIVE;   /*Reset last Brake State for activation*/
  nextState = HEADActualBrakeState;

  // Reset of Ramp out flag of previous ramp out phase
  /*Get Module information*/
  pVeh_AutoBrk1     = HEADGetModule(pInputData->pModuleList, HEAD_MOD_VEH_BRK_LV1);
  pVeh_AutoBrk2     = HEADGetModule(pInputData->pModuleList, HEAD_MOD_VEH_BRK_LV2);
  pVeh_AutoBrk3     = HEADGetModule(pInputData->pModuleList, HEAD_MOD_VEH_BRK_LV3);
  pPed_AutoBrk1     = HEADGetModule(pInputData->pModuleList, HEAD_MOD_PED_BRK_LV1);
  pPed_AutoBrk2     = HEADGetModule(pInputData->pModuleList, HEAD_MOD_PED_BRK_LV2);
  pPed_AutoBrk3     = HEADGetModule(pInputData->pModuleList, HEAD_MOD_PED_BRK_LV3);
  pLongVru_AutoBrk1 = HEADGetModule(pInputData->pModuleList, HEAD_MOD_LONGVRU_BRK_LV1);
  pLongVru_AutoBrk2 = HEADGetModule(pInputData->pModuleList, HEAD_MOD_LONGVRU_BRK_LV2);
  #if (HEAD_USE_CROSSING_BRK)
  pVeh_CrossBrk     = HEADGetModule(pInputData->pModuleList, (uint32) HEAD_MOD_CROSS_BRK);
  #endif

  #if (HEAD_USE_RAMP_BRK)
  {
    boolean bNoBrkModuleActive = b_TRUE;
    if ((pVeh_AutoBrk1 != NULL) && (pVeh_AutoBrk1->eSMState == HEADSMState_ACTIVE))
    {
      bNoBrkModuleActive = b_FALSE;
    }
    if ((pVeh_AutoBrk2 != NULL) && (pVeh_AutoBrk2->eSMState == HEADSMState_ACTIVE))
    {
      bNoBrkModuleActive = b_FALSE;
    }
    if ((pVeh_AutoBrk3 != NULL) && (pVeh_AutoBrk3->eSMState == HEADSMState_ACTIVE))
    {
      bNoBrkModuleActive = b_FALSE;
    }
    if ((pPed_AutoBrk1 != NULL) && (pPed_AutoBrk1->eSMState == HEADSMState_ACTIVE))
    {
      bNoBrkModuleActive = b_FALSE;
    }
    if ((pPed_AutoBrk2 != NULL) && (pPed_AutoBrk2->eSMState == HEADSMState_ACTIVE))
    {
      bNoBrkModuleActive = b_FALSE;
    }
    if ((pPed_AutoBrk3 != NULL) && (pPed_AutoBrk3->eSMState == HEADSMState_ACTIVE))
    {
      bNoBrkModuleActive = b_FALSE;
    }
    if ((pLongVru_AutoBrk1 != NULL) && (pLongVru_AutoBrk1->eSMState == HEADSMState_ACTIVE))
    {
      bNoBrkModuleActive = b_FALSE;
    }
    if ((pLongVru_AutoBrk2 != NULL) && (pLongVru_AutoBrk2->eSMState == HEADSMState_ACTIVE))
    {
      bNoBrkModuleActive = b_FALSE;
    }
    #if (HEAD_USE_CROSSING_BRK)
    if ((pVeh_CrossBrk != NULL) && (pVeh_CrossBrk->eSMState == HEADSMState_ACTIVE))
    { 
      bNoBrkModuleActive = FALSE;
    }
    #endif /* HEAD_USE_CROSSING_BRK */
    if ((HEADbAlreadyRamped && bNoBrkModuleActive ) != b_FALSE )
    {
      HEADbAlreadyRamped = b_FALSE;
    }
  }
  #endif /* HEAD_USE_RAMP_BRK */

  HeadBrakeHostSpeedLastTransToActive       = 0.0f;
  #if (HEAD_USE_ANEC_CTRL == MEDIC_ON)
  HeadBrakeRelSpeedTransToActive            = 0.0f;
  #endif /*HEAD_USE_ANEC_CTRL*/
  HEADbBrakeActiveState                      = b_FALSE;
  pPreBrakeFunction->pePreBrakeState         = &HEADActualBrakeState;
  pPreBrakeFunction->pbPreBrakeActive        = &HEADbBrakeActiveState;
  HEADRequestedDeceleration                  = 0.0f;
  pPreBrakeFunction->pfPreBrakeDeceleration  = &HEADRequestedDeceleration;
  HEADActHypNr                               = HEADNoHypothesis;
  pPreBrakeFunction->pActHypNr               = &HEADActHypNr;
  /************************************* timer handling ********************************************/
  HEADfDurationVehLevelOne                   = 0.0f;
  HEADfDurationVehLevelTwo                   = 0.0f;
  HEADfDurationVehLevelThree                 = 0.0f;
  HEADfDurationPedLevelOne                   = 0.0f;
  HEADfDurationPedLevelTwo                   = 0.0f;
  HEADfDurationPedLevelThree                 = 0.0f;
  HEADfDurationLongVruLevelOne               = 0.0f;
  HEADfDurationLongVruLevelTwo               = 0.0f;

  #if (HEAD_USE_CROSSING_BRK)
  HEADfDurationCrossBrk                      = 0;
  #endif
  pPreBrakeFunction->pfActiveTimeVeh1        = &HEADfDurationVehLevelOne;     /*Timer Module Active*/
  pPreBrakeFunction->pfActiveTimeVeh2        = &HEADfDurationVehLevelTwo;     /*Timer Level 2*/
  pPreBrakeFunction->pfActiveTimeVeh3        = &HEADfDurationVehLevelThree;   /*Timer Level 3*/
  pPreBrakeFunction->pfActiveTimePed1        = &HEADfDurationPedLevelOne;     /*Timer Ped Level 1*/
  pPreBrakeFunction->pfActiveTimePed2        = &HEADfDurationPedLevelTwo;     /*Timer Ped Level 2*/
  pPreBrakeFunction->pfActiveTimePed3        = &HEADfDurationPedLevelThree;   /*Timer Ped Level 3*/
  pPreBrakeFunction->pfActiveTimeLongVru1    = &HEADfDurationLongVruLevelOne; /*Timer LongVru Level 1*/
  pPreBrakeFunction->pfActiveTimeLongVru2    = &HEADfDurationLongVruLevelTwo; /*Timer LongVru Level 2*/
  #if (HEAD_USE_CROSSING_BRK)
  pPreBrakeFunction->pfActiveTimeCrossBrk    = &HEADfDurationCrossBrk;/*Timer Cross Brk*/
  #endif
  _PARAM_UNUSED(pInputData);/*PRQA S 3119 3 #date: 2020-06-02, reviewer: Nalina M, reason: Variable will be used in future. */
  _PARAM_UNUSED(pModule);
  _PARAM_UNUSED(pPreBrakeFunctionPar);
  
  return nextState;
}/*PRQA S 7002 #date: 2020-06-02, reviewer: Nalina M, reason: No side effect, Supressing for better code maintainability*/

/*************************************************************************************************************************
  Functionname:         HEADBrakeLevel_PED_1_ACTIVE_Output                                                          */ /*!

  @brief                Pedestrian Brake Level_1 ACTIVE Output 

  @description          This is a function that handles the transition to Active Brake state PedestrianBrakeLevel_1.
                        Activate brake function for the most critiacl Active Hypothesis of PedestrianBrakeLevel_1
                        and update brake function output parameters and status bits accordingly.
                        @startuml
                        start
                        :Update Brake State as Pedestrian-Brake-Level-1;
                        :Activate Pedestrian-Brake-Level-1;
                        :Update timer handling;
                        Note:Update Pedestrian brake Level-1 active timer.
                        :Update Brake function Output parameters;
                        :Update Brake status bit as active;
                        stop
                        @enduml

  @return               BrakeState_t : Enum value correspond to Brake state Pedestrian_Brake_Level-1

  @param[in]            pInputData : Pointer to Input data
  @param[in]            pModule : Pointer to a Module
  @param[out]           pPreBrakeFunction : Pointer to Break Function
  @param[in]            pPreBrakeFunctionPar : Pointer to Break Function Parameter
  
  @glob_in              None
  @glob_out             @ref HEADActualBrakeState \n            @ref HEADActivatedBrakeState \n
                        @ref HEADbBrakeActiveState \n           @ref HEADfDurationVehLevelOne \n        
                        @ref HEADfDurationVehLevelTwo \n        @ref HEADfDurationVehLevelThree \n
                        @ref HEADfDurationPedLevelOne \n        @ref HEADfDurationPedLevelTwo \n
                        @ref HEADfDurationPedLevelThree \n      @ref HEADfDurationLongVruLevelOne \n
                        @ref HEADfDurationLongVruLevelTwo \n    @ref HEADfDurationCrossBrk

  @c_switch_part        @ref HEAD_USE_CROSSING_BRK  
  @c_switch_full        @ref MEDIC_CFG_HYPOTHESIS_EVAL_AND_DECISION   

  @pre                  None
  @post                 None

  @InOutCorrelation     Not defined
  
  @testmethod           Test of output data (dynamic module test)

  @traceability         Design Decision
  
  @author               Daniel Deitrich| Daniel.Deitrich@continental-corporation.com
*************************************************************************************************************************/
static BrakeState_t HEADBrakeLevel_PED_1_ACTIVE_Output( /*Input*/ const struct HEADInputData_t *pInputData,
                                                              const struct HEADModule_t *pModule,
                                                              HEADModuleOutputBrakeFunction_t *pPreBrakeFunction,
                                                              const HEADModOutBrakeFunctionPar_t *pPreBrakeFunctionPar)
{
  BrakeState_t nextState;

  nextState = eBrakeState_PED_LEVEL_1;
  HEADActualBrakeState = nextState;
  HEADActivatedBrakeState = eBrakeState_PED_LEVEL_1;   /*Last Brake State for activation*/

  /* PED brake activation function call */
  (void)HEADBrakeActivation( pInputData, pModule, pPreBrakeFunction, pPreBrakeFunctionPar );

  /************************************* timer handling ********************************************/
  HEADfDurationVehLevelOne                   = 0.0f;
  HEADfDurationVehLevelTwo                   = 0.0f;
  HEADfDurationVehLevelThree                 = 0.0f;
  HEADfDurationPedLevelOne                  += pInputData->fCycleTime;
  HEADfDurationPedLevelTwo                   = 0.0f;
  HEADfDurationPedLevelThree                 = 0.0f;
  HEADfDurationLongVruLevelOne               = 0.0f;
  HEADfDurationLongVruLevelTwo               = 0.0f;
  #if (HEAD_USE_CROSSING_BRK)
  HEADfDurationCrossBrk                      = 0;
  #endif
  pPreBrakeFunction->pfActiveTimeVeh1        = &HEADfDurationVehLevelOne;     /*Timer Module Active*/
  pPreBrakeFunction->pfActiveTimeVeh2        = &HEADfDurationVehLevelTwo;     /*Timer Level 2*/
  pPreBrakeFunction->pfActiveTimeVeh3        = &HEADfDurationVehLevelThree;   /*Timer Level 3*/
  pPreBrakeFunction->pfActiveTimePed1        = &HEADfDurationPedLevelOne;     /*Timer Ped Level 1*/
  pPreBrakeFunction->pfActiveTimePed2        = &HEADfDurationPedLevelTwo;     /*Timer Ped Level 2*/
  pPreBrakeFunction->pfActiveTimePed3        = &HEADfDurationPedLevelThree;   /*Timer Ped Level 3*/
  pPreBrakeFunction->pfActiveTimeLongVru1    = &HEADfDurationLongVruLevelOne; /*Timer LongVru Level 1*/
  pPreBrakeFunction->pfActiveTimeLongVru2    = &HEADfDurationLongVruLevelTwo; /*Timer LongVru Level 2*/
  #if (HEAD_USE_CROSSING_BRK)
  pPreBrakeFunction->pfActiveTimeCrossBrk    = &HEADfDurationCrossBrk;/*Timer Cross Brk*/
  #endif

  HEADbBrakeActiveState               = b_TRUE;
  pPreBrakeFunction->pbPreBrakeActive = &HEADbBrakeActiveState;
  pPreBrakeFunction->pePreBrakeState  = &HEADActualBrakeState;

  return nextState;
}

/*************************************************************************************************************************
  Functionname:         HEADBrakeLevel_PED_2_ACTIVE_Output                                                          */ /*!

  @brief                Pedestrian Brake Level_2 ACTIVE Output 

  @description          This is a function that handles the transition to Active Brake state PedestrianBrakeLevel_2.
                        Activate brake function for the most critiacl Active Hypothesis of PedestrianBrakeLevel_2 
                        and update brake function output parameters and status bits accordingly.
                        @startuml
                        start
                        :Update Brake State as Pedestrian-Brake-Level-2;
                        :Activate Pedestrian-Brake-Level-2;
                        :Update timer handling;
                        Note:Update Pedestrian brake Level-1 and Level-2 active timer.
                        :Update Brake function Output parameters;
                        :Update Brake status bit as active;
                        stop
                        @enduml

  @return               BrakeState_t : Enum value correspond to Brake state Pedestrian_Brake_Level-2

  @param[in]            pInputData : Pointer to Input data
  @param[in]            pModule : Pointer to a Module
  @param[out]           pPreBrakeFunction : Pointer to Break Function
  @param[in]            pPreBrakeFunctionPar : Pointer to Break Function Parameter
  
  @glob_in              None
  @glob_out             @ref HEADActualBrakeState \n            @ref HEADActivatedBrakeState \n
                        @ref HEADbBrakeActiveState \n           @ref HEADfDurationVehLevelOne \n        
                        @ref HEADfDurationVehLevelTwo \n        @ref HEADfDurationVehLevelThree \n
                        @ref HEADfDurationPedLevelOne \n        @ref HEADfDurationPedLevelTwo \n
                        @ref HEADfDurationPedLevelThree \n      @ref HEADfDurationLongVruLevelOne \n
                        @ref HEADfDurationLongVruLevelTwo \n    @ref HEADfDurationCrossBrk

  @c_switch_part        @ref HEAD_USE_CROSSING_BRK  
  @c_switch_full        @ref MEDIC_CFG_HYPOTHESIS_EVAL_AND_DECISION   

  @pre                  None
  @post                 None

  @InOutCorrelation     Not defined
  
  @testmethod           Test of output data (dynamic module test)

  @traceability         Design Decision
  
  @author               Daniel Deitrich| Daniel.Deitrich@continental-corporation.com
*************************************************************************************************************************/
static BrakeState_t HEADBrakeLevel_PED_2_ACTIVE_Output( /*Input*/ const struct HEADInputData_t *pInputData,
                                                              const struct HEADModule_t *pModule,
                                                              HEADModuleOutputBrakeFunction_t *pPreBrakeFunction,
                                                              const HEADModOutBrakeFunctionPar_t *pPreBrakeFunctionPar)
{
  BrakeState_t nextState;

  nextState = eBrakeState_PED_LEVEL_2;
  HEADActualBrakeState = nextState;
  HEADActivatedBrakeState = eBrakeState_PED_LEVEL_2;   /*Last Brake State for activation*/

  /* PED brake activation function call */
  (void)HEADBrakeActivation( pInputData, pModule, pPreBrakeFunction, pPreBrakeFunctionPar );

  /************************************* timer handling ********************************************/
  HEADfDurationVehLevelOne                   = 0.0f;
  HEADfDurationVehLevelTwo                   = 0.0f;
  HEADfDurationVehLevelThree                 = 0.0f;
  HEADfDurationPedLevelOne                  += pInputData->fCycleTime;
  HEADfDurationPedLevelTwo                  += pInputData->fCycleTime;
  HEADfDurationPedLevelThree                 = 0.0f;
  HEADfDurationLongVruLevelOne               = 0.0f;
  HEADfDurationLongVruLevelTwo               = 0.0f;
  #if (HEAD_USE_CROSSING_BRK)
  HEADfDurationCrossBrk                      = 0;
  #endif
  pPreBrakeFunction->pfActiveTimeVeh1        = &HEADfDurationVehLevelOne;     /*Timer Module Active*/
  pPreBrakeFunction->pfActiveTimeVeh2        = &HEADfDurationVehLevelTwo;     /*Timer Level 2*/
  pPreBrakeFunction->pfActiveTimeVeh3        = &HEADfDurationVehLevelThree;   /*Timer Level 3*/
  pPreBrakeFunction->pfActiveTimePed1        = &HEADfDurationPedLevelOne;     /*Timer Ped Level 1*/
  pPreBrakeFunction->pfActiveTimePed2        = &HEADfDurationPedLevelTwo;     /*Timer Ped Level 2*/
  pPreBrakeFunction->pfActiveTimePed3        = &HEADfDurationPedLevelThree;   /*Timer Ped Level 3*/
  pPreBrakeFunction->pfActiveTimeLongVru1    = &HEADfDurationLongVruLevelOne; /*Timer LongVru Level 1*/
  pPreBrakeFunction->pfActiveTimeLongVru2    = &HEADfDurationLongVruLevelTwo; /*Timer LongVru Level 2*/
  #if (HEAD_USE_CROSSING_BRK)
  pPreBrakeFunction->pfActiveTimeCrossBrk    = &HEADfDurationCrossBrk;/*Timer Cross Brk*/
  #endif

  HEADbBrakeActiveState               = b_TRUE;
  pPreBrakeFunction->pbPreBrakeActive = &HEADbBrakeActiveState;
  pPreBrakeFunction->pePreBrakeState  = &HEADActualBrakeState;

  return nextState;
}

/*************************************************************************************************************************
  Functionname:         HEADBrakeLevel_PED_3_ACTIVE_Output                                                          */ /*!

  @brief                Pedestrian Brake Level_3 ACTIVE Output 

  @description          This is a function that handles the transition to Active Brake state PedestrianBrakeLevel_3.
                        Activate brake function for the most critiacl Active Hypothesis of PedestrianBrakeLevel_3 
                        and update brake function output parameters and status bits accordingly.
                        @startuml
                        start
                        :Update Brake State as Pedestrian-Brake-Level-3;
                        :Activate Pedestrian-Brake-Level-3;
                        :Update timer handling;
                        Note:Update Pedestrian brake Level-1, Level-2 and Level-3 active timer.
                        :Update Brake function Output parameters;
                        :Update Brake status bit as active;
                        stop
                        @enduml

  @return               BrakeState_t : Enum value correspond to Brake state Pedestrian_Brake_Level-3

  @param[in]            pInputData : Pointer to Input data
  @param[in]            pModule : Pointer to a Module
  @param[out]           pPreBrakeFunction : Pointer to Break Function
  @param[in]            pPreBrakeFunctionPar : Pointer to Break Function Parameter
  
  @glob_in              None
  @glob_out             @ref HEADActualBrakeState \n            @ref HEADActivatedBrakeState \n
                        @ref HEADbBrakeActiveState \n           @ref HEADfDurationVehLevelOne \n        
                        @ref HEADfDurationVehLevelTwo \n        @ref HEADfDurationVehLevelThree \n
                        @ref HEADfDurationPedLevelOne \n        @ref HEADfDurationPedLevelTwo \n
                        @ref HEADfDurationPedLevelThree \n      @ref HEADfDurationLongVruLevelOne \n
                        @ref HEADfDurationLongVruLevelTwo \n    @ref HEADfDurationCrossBrk

  @c_switch_part        @ref HEAD_USE_CROSSING_BRK  
  @c_switch_full        @ref MEDIC_CFG_HYPOTHESIS_EVAL_AND_DECISION   

  @pre                  None
  @post                 None

  @InOutCorrelation     Not defined
  
  @testmethod           Test of output data (dynamic module test)

  @traceability         Design Decision
  
  @author               Daniel Deitrich| Daniel.Deitrich@continental-corporation.com
*************************************************************************************************************************/
static BrakeState_t HEADBrakeLevel_PED_3_ACTIVE_Output( /*Input*/ const struct HEADInputData_t *pInputData,
                                                              const struct HEADModule_t *pModule,
                                                              HEADModuleOutputBrakeFunction_t *pPreBrakeFunction,
                                                              const HEADModOutBrakeFunctionPar_t *pPreBrakeFunctionPar)
{
  BrakeState_t nextState;

  nextState = eBrakeState_PED_LEVEL_3;
  HEADActualBrakeState = nextState;
  HEADActivatedBrakeState = eBrakeState_PED_LEVEL_3;   /*Last Brake State for activation*/

  /* PED brake activation function call */
  (void)HEADBrakeActivation( pInputData, pModule, pPreBrakeFunction, pPreBrakeFunctionPar );

  /************************************* timer handling ********************************************/
  HEADfDurationVehLevelOne                   = 0.0f;
  HEADfDurationVehLevelTwo                   = 0.0f;
  HEADfDurationVehLevelThree                 = 0.0f;
  HEADfDurationPedLevelOne                  += pInputData->fCycleTime;
  HEADfDurationPedLevelTwo                  += pInputData->fCycleTime;
  HEADfDurationPedLevelThree                += pInputData->fCycleTime;
  HEADfDurationLongVruLevelOne               = 0.0f;
  HEADfDurationLongVruLevelTwo               = 0.0f;
  #if (HEAD_USE_CROSSING_BRK)
  HEADfDurationCrossBrk                      = 0;
  #endif
  pPreBrakeFunction->pfActiveTimeVeh1        = &HEADfDurationVehLevelOne;  /*Timer Module Active*/
  pPreBrakeFunction->pfActiveTimeVeh2        = &HEADfDurationVehLevelTwo;  /*Timer Level 2*/
  pPreBrakeFunction->pfActiveTimeVeh3        = &HEADfDurationVehLevelThree;  /*Timer Level 3*/
  pPreBrakeFunction->pfActiveTimePed1        = &HEADfDurationPedLevelOne;  /*Timer Ped Level 1*/
  pPreBrakeFunction->pfActiveTimePed2        = &HEADfDurationPedLevelTwo;  /*Timer Ped Level 2*/
  pPreBrakeFunction->pfActiveTimePed3        = &HEADfDurationPedLevelThree; /*Timer Ped Level 3*/
  pPreBrakeFunction->pfActiveTimeLongVru1    = &HEADfDurationLongVruLevelOne;   /*Timer LongVru Level 1*/
  pPreBrakeFunction->pfActiveTimeLongVru2    = &HEADfDurationLongVruLevelTwo; /*Timer LongVru Level 2*/
  #if (HEAD_USE_CROSSING_BRK)
  pPreBrakeFunction->pfActiveTimeCrossBrk    = &HEADfDurationCrossBrk;/*Timer Cross Brk*/
  #endif

  HEADbBrakeActiveState               = b_TRUE;
  pPreBrakeFunction->pbPreBrakeActive = &HEADbBrakeActiveState;
  pPreBrakeFunction->pePreBrakeState  = &HEADActualBrakeState;

  return nextState;
}

/*************************************************************************************************************************
  Functionname:         HEADBrakeLevel_1_ACTIVE_Output                                                               */ /*!

  @brief                Vehicle Brake Level_1 ACTIVE Output 

  @description          This is a function that handles the transition to Active Brake state VehicleBrakeLevel_1.
                        Activate brake function for the most critiacl Active Hypothesis of VehicleBrakeLevel_1 
                        and update brake function output parameters and status bits accordingly.
                        @startuml
                        start
                        :Update Brake State as Vehicle-Brake-Level-1;
                        :Activate Vehicle-Brake-Level-1;
                        :Update timer handling;
                        Note:Update vehicle brake Level-1 active timer.
                        :Update Brake function Output parameters;
                        :Update Brake status bit as active;
                        stop
                        @enduml

  @return               BrakeState_t : Enum value correspond to Brake state Vehicle_Brake_Level-1

  @param[in]            pInputData : Pointer to Input data
  @param[in]            pModule : Pointer to a Module
  @param[out]           pPreBrakeFunction : Pointer to Break Function
  @param[in]            pPreBrakeFunctionPar : Pointer to Break Function Parameter
  
  @glob_in              None
  @glob_out             @ref HEADActualBrakeState \n            @ref HEADActivatedBrakeState \n
                        @ref HEADbBrakeActiveState \n           @ref HEADfDurationVehLevelOne \n        
                        @ref HEADfDurationVehLevelTwo \n        @ref HEADfDurationVehLevelThree \n
                        @ref HEADfDurationPedLevelOne \n        @ref HEADfDurationPedLevelTwo \n
                        @ref HEADfDurationPedLevelThree \n      @ref HEADfDurationLongVruLevelOne \n
                        @ref HEADfDurationLongVruLevelTwo \n    @ref HEADfDurationCrossBrk

  @c_switch_part        @ref HEAD_USE_CROSSING_BRK  
  @c_switch_full        @ref MEDIC_CFG_HYPOTHESIS_EVAL_AND_DECISION   

  @pre                  None
  @post                 None

  @InOutCorrelation     Not defined
  
  @testmethod           Test of output data (dynamic module test)

  @traceability         Design Decision
  
  @author               Daniel Deitrich| Daniel.Deitrich@continental-corporation.com
*************************************************************************************************************************/
static BrakeState_t HEADBrakeLevel_1_ACTIVE_Output( /*Input*/ const struct HEADInputData_t *pInputData,
                                                              const struct HEADModule_t *pModule,
                                                              HEADModuleOutputBrakeFunction_t *pPreBrakeFunction,
                                                              const HEADModOutBrakeFunctionPar_t *pPreBrakeFunctionPar)
{
  BrakeState_t nextState;

  nextState = eBrakeState_VEH_LEVEL_1;
  HEADActualBrakeState = nextState;
  HEADActivatedBrakeState = eBrakeState_VEH_LEVEL_1;   /*Last Brake State for activation*/

  /* Level 1 brake activation function call */
  (void)HEADBrakeActivation( pInputData, pModule, pPreBrakeFunction, pPreBrakeFunctionPar );

  /************************************* timer handling ********************************************/
  HEADfDurationVehLevelOne                  += pInputData->fCycleTime;
  HEADfDurationVehLevelTwo                   = 0.0f;
  HEADfDurationVehLevelThree                 = 0.0f;
  HEADfDurationPedLevelOne                   = 0.0f;
  HEADfDurationPedLevelTwo                   = 0.0f;
  HEADfDurationPedLevelThree                 = 0.0f;
  HEADfDurationLongVruLevelOne               = 0.0f;
  HEADfDurationLongVruLevelTwo               = 0.0f;

  #if (HEAD_USE_CROSSING_BRK)
  HEADfDurationCrossBrk                      = 0;
  #endif
  pPreBrakeFunction->pfActiveTimeVeh1        = &HEADfDurationVehLevelOne;    /*Timer Module Active*/
  pPreBrakeFunction->pfActiveTimeVeh2        = &HEADfDurationVehLevelTwo;    /*Timer Level 2*/
  pPreBrakeFunction->pfActiveTimeVeh3        = &HEADfDurationVehLevelThree;  /*Timer Level 3*/
  pPreBrakeFunction->pfActiveTimePed1        = &HEADfDurationPedLevelOne;    /*Timer Ped Level 1*/
  pPreBrakeFunction->pfActiveTimePed2        = &HEADfDurationPedLevelTwo;    /*Timer Ped Level 2*/
  pPreBrakeFunction->pfActiveTimePed3        = &HEADfDurationPedLevelThree;  /*Timer Ped Level 3*/
  pPreBrakeFunction->pfActiveTimeLongVru1    = &HEADfDurationLongVruLevelOne;   /*Timer LongVru Level 1*/
  pPreBrakeFunction->pfActiveTimeLongVru2    = &HEADfDurationLongVruLevelTwo; /*Timer LongVru Level 2*/
  #if (HEAD_USE_CROSSING_BRK)
  pPreBrakeFunction->pfActiveTimeCrossBrk    = &HEADfDurationCrossBrk;       /*Timer Cross Brk*/
  #endif

  HEADbBrakeActiveState               = b_TRUE;
  pPreBrakeFunction->pbPreBrakeActive = &HEADbBrakeActiveState;
  pPreBrakeFunction->pePreBrakeState  = &HEADActualBrakeState;

  return nextState;
}

/*************************************************************************************************************************
  Functionname:         HEADBrakeLevel_2_ACTIVE_Output                                                              */ /*!

  @brief                Vehicle Brake Level_2 ACTIVE Output 

  @description          This is a function that handles the transition to Active Brake state VehicleBrakeLevel_2.
                        Activate brake function for the most critiacl Active Hypothesis of VehicleBrakeLevel_2
                        and update brake function output parameters and status bits accordingly.
                        @startuml
                        start
                        :Update Brake State as Vehicle-Brake-Level-2;
                        :Activate Vehicle-Brake-Level-2;
                        :Update timer handling;
                        Note:Update vehicle brake Level-1 and Level-2 active timer.
                        :Update Brake function Output parameters;
                        :Update Brake status bit as active;
                        stop
                        @enduml

  @return               BrakeState_t : Enum value correspond to Brake state Vehicle_Brake_Level-2

  @param[in]            pInputData : Pointer to Input data
  @param[in]            pModule : Pointer to a Module
  @param[out]           pPreBrakeFunction : Pointer to Break Function
  @param[in]            pPreBrakeFunctionPar : Pointer to Break Function Parameter
  
  @glob_in              None
  @glob_out             @ref HEADActualBrakeState \n            @ref HEADActivatedBrakeState \n
                        @ref HEADbBrakeActiveState \n           @ref HEADfDurationVehLevelOne \n        
                        @ref HEADfDurationVehLevelTwo \n        @ref HEADfDurationVehLevelThree \n
                        @ref HEADfDurationPedLevelOne \n        @ref HEADfDurationPedLevelTwo \n
                        @ref HEADfDurationPedLevelThree \n      @ref HEADfDurationLongVruLevelOne \n
                        @ref HEADfDurationLongVruLevelTwo \n    @ref HEADfDurationCrossBrk

  @c_switch_part        @ref HEAD_USE_CROSSING_BRK  
  @c_switch_full        @ref MEDIC_CFG_HYPOTHESIS_EVAL_AND_DECISION   

  @pre                  None
  @post                 None

  @InOutCorrelation     Not defined
  
  @testmethod           Test of output data (dynamic module test)

  @traceability         Design Decision
  
  @author               Daniel Deitrich| Daniel.Deitrich@continental-corporation.com
*************************************************************************************************************************/
static BrakeState_t HEADBrakeLevel_2_ACTIVE_Output( /*Input*/ const struct HEADInputData_t *pInputData,
                                                              const struct HEADModule_t *pModule,
                                                              HEADModuleOutputBrakeFunction_t *pPreBrakeFunction,
                                                              const HEADModOutBrakeFunctionPar_t *pPreBrakeFunctionPar)
{
   
  BrakeState_t nextState; 

  nextState = eBrakeState_VEH_LEVEL_2;
  HEADActualBrakeState = nextState;
  HEADActivatedBrakeState = eBrakeState_VEH_LEVEL_2;   /*Last Brake State for activation*/

  (void)HEADBrakeActivation(pInputData, pModule, pPreBrakeFunction, pPreBrakeFunctionPar );

  /************************************* timer handling ********************************************/
  HEADfDurationVehLevelOne                  += pInputData->fCycleTime; 
  HEADfDurationVehLevelTwo                  += pInputData->fCycleTime;
  HEADfDurationVehLevelThree                 = 0.0f;
  HEADfDurationPedLevelOne                   = 0.0f;
  HEADfDurationPedLevelTwo                   = 0.0f;
  HEADfDurationPedLevelThree                 = 0.0f;
  HEADfDurationLongVruLevelOne               = 0.0f;
  HEADfDurationLongVruLevelTwo               = 0.0f;

  #if (HEAD_USE_CROSSING_BRK)
  HEADfDurationCrossBrk                      = 0;
  #endif
  pPreBrakeFunction->pfActiveTimeVeh1        = &HEADfDurationVehLevelOne;   /*Timer Module Active*/
  pPreBrakeFunction->pfActiveTimeVeh2        = &HEADfDurationVehLevelTwo;   /*Timer Level 2*/
  pPreBrakeFunction->pfActiveTimeVeh3        = &HEADfDurationVehLevelThree; /*Timer Level 3*/
  pPreBrakeFunction->pfActiveTimePed1        = &HEADfDurationPedLevelOne;  /*Timer Ped Level 1*/
  pPreBrakeFunction->pfActiveTimePed2        = &HEADfDurationPedLevelTwo;  /*Timer Ped Level 2*/
  pPreBrakeFunction->pfActiveTimePed3        = &HEADfDurationPedLevelThree; /*Timer Ped Level 3*/
  pPreBrakeFunction->pfActiveTimeLongVru1    = &HEADfDurationLongVruLevelOne;   /*Timer LongVru Level 1*/
  pPreBrakeFunction->pfActiveTimeLongVru2    = &HEADfDurationLongVruLevelTwo; /*Timer LongVru Level 2*/
  #if (HEAD_USE_CROSSING_BRK)
  pPreBrakeFunction->pfActiveTimeCrossBrk    = &HEADfDurationCrossBrk;/*Timer Cross Brk*/
  #endif

  nextState = eBrakeState_VEH_LEVEL_2;
  HEADbBrakeActiveState               = b_TRUE;
  pPreBrakeFunction->pbPreBrakeActive = &HEADbBrakeActiveState;
  pPreBrakeFunction->pePreBrakeState  = &HEADActualBrakeState;
  return nextState;
}

/*************************************************************************************************************************
  Functionname:         HEADBrakeLevel_3_ACTIVE_Output                                                               */ /*!

  @brief                Vehicle Brake Level_3 ACTIVE Output 

  @description          This is a function that handles the transition to Active Brake state VehicleBrakeLevel_3.
                        Activate brake function for the most critiacl Active Hypothesis of VehicleBrakeLevel_3 
                        and update brake function output parameters and status bits accordingly.
                        @startuml
                        start
                        :Update Brake State as Vehicle-Brake-Level-3;
                        :Activate Vehicle-Brake-Level-3;
                        :Update timer handling;
                        Note:Update vehicle brake Level-1, Level-2 and Level-3 active timer.
                        :Update Brake function Output parameters;
                        :Update Brake status bit as active;
                        stop
                        @enduml

  @return               BrakeState_t : Enum value correspond to Brake state Vehicle_Brake_Level-3

  @param[in]            pInputData : Pointer to Input data
  @param[in]            pModule : Pointer to a Module
  @param[out]           pPreBrakeFunction : Pointer to Break Function
  @param[in]            pPreBrakeFunctionPar : Pointer to Break Function Parameter
  
  @glob_in              None
  @glob_out             @ref HEADActualBrakeState \n            @ref HEADActivatedBrakeState \n
                        @ref HEADbBrakeActiveState \n           @ref HEADfDurationVehLevelOne \n        
                        @ref HEADfDurationVehLevelTwo \n        @ref HEADfDurationVehLevelThree \n
                        @ref HEADfDurationPedLevelOne \n        @ref HEADfDurationPedLevelTwo \n
                        @ref HEADfDurationPedLevelThree \n      @ref HEADfDurationLongVruLevelOne \n
                        @ref HEADfDurationLongVruLevelTwo \n    @ref HEADfDurationCrossBrk

  @c_switch_part        @ref HEAD_USE_CROSSING_BRK  
  @c_switch_full        @ref MEDIC_CFG_HYPOTHESIS_EVAL_AND_DECISION   

  @pre                  None
  @post                 None

  @InOutCorrelation     Not defined
  
  @testmethod           Test of output data (dynamic module test)

  @traceability         Design Decision
  
  @author               Daniel Deitrich| Daniel.Deitrich@continental-corporation.com
*************************************************************************************************************************/
static BrakeState_t HEADBrakeLevel_3_ACTIVE_Output( /*Input*/ const struct HEADInputData_t *pInputData,
                                                              const struct HEADModule_t *pModule,
                                                              HEADModuleOutputBrakeFunction_t *pPreBrakeFunction,
                                                              const HEADModOutBrakeFunctionPar_t *pPreBrakeFunctionPar)
{
  BrakeState_t nextState;

  nextState = eBrakeState_VEH_LEVEL_3;
  HEADActualBrakeState = nextState;
  HEADActivatedBrakeState = eBrakeState_VEH_LEVEL_3;   /*Last Brake State for activation*/

  (void)HEADBrakeActivation(pInputData, pModule, pPreBrakeFunction, pPreBrakeFunctionPar);

  /************************************* timer handling ********************************************/
  HEADfDurationVehLevelOne                  += pInputData->fCycleTime;
  HEADfDurationVehLevelTwo                  += pInputData->fCycleTime;
  HEADfDurationVehLevelThree                += pInputData->fCycleTime;
  HEADfDurationPedLevelOne                   = 0.0f;
  HEADfDurationPedLevelTwo                   = 0.0f;
  HEADfDurationPedLevelThree                 = 0.0f;
  HEADfDurationLongVruLevelOne               = 0.0f;
  HEADfDurationLongVruLevelTwo               = 0.0f;

  #if (HEAD_USE_CROSSING_BRK)
  HEADfDurationCrossBrk                      = 0;
  #endif
  pPreBrakeFunction->pfActiveTimeVeh1        = &HEADfDurationVehLevelOne;   /*Timer Module Active*/
  pPreBrakeFunction->pfActiveTimeVeh2        = &HEADfDurationVehLevelTwo;   /*Timer Level 2 and Level 3*/
  pPreBrakeFunction->pfActiveTimeVeh3        = &HEADfDurationVehLevelThree; /*Timer Level 2 and Level 3*/
  pPreBrakeFunction->pfActiveTimePed1        = &HEADfDurationPedLevelOne;  /*Timer Ped Level 1*/
  pPreBrakeFunction->pfActiveTimePed2        = &HEADfDurationPedLevelTwo;  /*Timer Ped Level 2*/
  pPreBrakeFunction->pfActiveTimePed3        = &HEADfDurationPedLevelThree; /*Timer Ped Level 3*/
  pPreBrakeFunction->pfActiveTimeLongVru1    = &HEADfDurationLongVruLevelOne;   /*Timer LongVru Level 1*/
  pPreBrakeFunction->pfActiveTimeLongVru2    = &HEADfDurationLongVruLevelTwo; /*Timer LongVru Level 2*/
  #if (HEAD_USE_CROSSING_BRK)
  pPreBrakeFunction->pfActiveTimeCrossBrk    = &HEADfDurationCrossBrk;/*Timer Cross Brk*/
  #endif

  HEADbBrakeActiveState               = b_TRUE;
  pPreBrakeFunction->pbPreBrakeActive = &HEADbBrakeActiveState;
  pPreBrakeFunction->pePreBrakeState  = &HEADActualBrakeState;
  return nextState;
}

/*************************************************************************************************************************
  Functionname:         HEADBrakeLevel_LongVru_1_ACTIVE_Output                                                      */ /*!

  @brief                Longitudinal_VRU Brake Level_1 ACTIVE Output 

  @description          This is a function that handles the transition to Active Brake state Longitudinal_VRU_BrakeLevel_1.
                        Activate brake function for the most critiacl Active Hypothesis of Longitudinal_VRU_BrakeLevel_1 
                        and update brake function output parameters and status bits accordingly.
                        @startuml
                        start
                        :Update Brake State as Longitudinal_VRU-Brake-Level-1;
                        :Activate Longitudinal_VRU-Brake-Level-1;
                        :Update timer handling;
                        Note:Update Longitudinal_VRU brake Level-1 active timer.
                        :Update Brake function Output parameters;
                        :Update Brake status bit as active;
                        stop
                        @enduml

  @return               BrakeState_t : Enum value correspond to Brake state Longitudinal_VRU_Brake_Level-1

  @param[in]            pInputData : Pointer to Input data
  @param[in]            pModule : Pointer to a Module
  @param[out]           pPreBrakeFunction : Pointer to Break Function
  @param[in]            pPreBrakeFunctionPar : Pointer to Break Function Parameter
  
  @glob_in              None
  @glob_out             @ref HEADActualBrakeState \n            @ref HEADActivatedBrakeState \n
                        @ref HEADbBrakeActiveState \n           @ref HEADfDurationVehLevelOne \n        
                        @ref HEADfDurationVehLevelTwo \n        @ref HEADfDurationVehLevelThree \n
                        @ref HEADfDurationPedLevelOne \n        @ref HEADfDurationPedLevelTwo \n
                        @ref HEADfDurationPedLevelThree \n      @ref HEADfDurationLongVruLevelOne \n
                        @ref HEADfDurationLongVruLevelTwo \n    @ref HEADfDurationCrossBrk

  @c_switch_part        @ref HEAD_USE_CROSSING_BRK  
  @c_switch_full        @ref MEDIC_CFG_HYPOTHESIS_EVAL_AND_DECISION   

  @pre                  None
  @post                 None

  @InOutCorrelation     Not defined
  
  @testmethod           Test of output data (dynamic module test)

  @traceability         Design Decision
  
  @author               Daniel Deitrich| Daniel.Deitrich@continental-corporation.com
*************************************************************************************************************************/
static BrakeState_t HEADBrakeLevel_LongVru_1_ACTIVE_Output( /*Input*/ const struct HEADInputData_t *pInputData,
                                                              const struct HEADModule_t *pModule,
                                                              HEADModuleOutputBrakeFunction_t *pPreBrakeFunction,
                                                              const HEADModOutBrakeFunctionPar_t *pPreBrakeFunctionPar)
{
  BrakeState_t nextState;

  nextState = eBrakeState_LongVru_LEVEL_1;
  HEADActualBrakeState = nextState;
  HEADActivatedBrakeState = eBrakeState_LongVru_LEVEL_1;   /*Last Brake State for activation*/

  /* LongVru brake activation function call */
  (void)HEADBrakeActivation( pInputData, pModule, pPreBrakeFunction, pPreBrakeFunctionPar );

  /************************************* timer handling ********************************************/
  HEADfDurationVehLevelOne                   = 0.0f;
  HEADfDurationVehLevelTwo                   = 0.0f;
  HEADfDurationVehLevelThree                 = 0.0f;
  HEADfDurationPedLevelOne                   = 0.0f;
  HEADfDurationPedLevelTwo                   = 0.0f;
  HEADfDurationPedLevelThree                 = 0.0f;
  HEADfDurationLongVruLevelOne               += pInputData->fCycleTime;
  HEADfDurationLongVruLevelTwo               = 0.0f;
  #if (HEAD_USE_CROSSING_BRK)
  HEADfDurationCrossBrk                      = 0;
  #endif
  pPreBrakeFunction->pfActiveTimeVeh1        = &HEADfDurationVehLevelOne;     /*Timer Module Active*/
  pPreBrakeFunction->pfActiveTimeVeh2        = &HEADfDurationVehLevelTwo;     /*Timer Level 2*/
  pPreBrakeFunction->pfActiveTimeVeh3        = &HEADfDurationVehLevelThree;   /*Timer Level 3*/
  pPreBrakeFunction->pfActiveTimePed1        = &HEADfDurationPedLevelOne;     /*Timer Ped Level 1*/
  pPreBrakeFunction->pfActiveTimePed2        = &HEADfDurationPedLevelTwo;     /*Timer Ped Level 2*/
  pPreBrakeFunction->pfActiveTimePed3        = &HEADfDurationPedLevelThree;   /*Timer Ped Level 3*/
  pPreBrakeFunction->pfActiveTimeLongVru1    = &HEADfDurationLongVruLevelOne; /*Timer LongVru Level 1*/
  pPreBrakeFunction->pfActiveTimeLongVru2    = &HEADfDurationLongVruLevelTwo; /*Timer LongVru Level 2*/
  #if (HEAD_USE_CROSSING_BRK)
  pPreBrakeFunction->pfActiveTimeCrossBrk    = &HEADfDurationCrossBrk;/*Timer Cross Brk*/
  #endif

  HEADbBrakeActiveState               = b_TRUE;
  pPreBrakeFunction->pbPreBrakeActive = &HEADbBrakeActiveState;
  pPreBrakeFunction->pePreBrakeState  = &HEADActualBrakeState;

  return nextState;
}

/*************************************************************************************************************************
  Functionname:         HEADBrakeLevel_LongVru_2_ACTIVE_Output                                                      */ /*!

  @brief                Longitudinal_VRU Brake Level_2 ACTIVE Output 

  @description          This is a function that handles the transition to Active Brake state Longitudinal_VRU_BrakeLevel_2.
                        Activate brake function for the most critiacl Active Hypothesis of Longitudinal_VRU_BrakeLevel_2 
                        and update brake function output parameters and status bits accordingly.
                        @startuml
                        start
                        :Update Brake State as Longitudinal_VRU-Brake-Level-2;
                        :Activate Longitudinal_VRU-Brake-Level-2;
                        :Update timer handling;
                        Note:Update Longitudinal_VRU brake Level-1 and Level-2 active timer.
                        :Update Brake function Output parameters;
                        :Update Brake status bit as active;
                        stop
                        @enduml

  @return               BrakeState_t : Enum value correspond to Brake state Longitudinal_VRU_Brake_Level-2

  @param[in]            pInputData : Pointer to Input data
  @param[in]            pModule : Pointer to a Module
  @param[out]           pPreBrakeFunction : Pointer to Break Function
  @param[in]            pPreBrakeFunctionPar : Pointer to Break Function Parameter
  
  @glob_in              None
  @glob_out             @ref HEADActualBrakeState \n            @ref HEADActivatedBrakeState \n
                        @ref HEADbBrakeActiveState \n           @ref HEADfDurationVehLevelOne \n        
                        @ref HEADfDurationVehLevelTwo \n        @ref HEADfDurationVehLevelThree \n
                        @ref HEADfDurationPedLevelOne \n        @ref HEADfDurationPedLevelTwo \n
                        @ref HEADfDurationPedLevelThree \n      @ref HEADfDurationLongVruLevelOne \n
                        @ref HEADfDurationLongVruLevelTwo \n    @ref HEADfDurationCrossBrk

  @c_switch_part        @ref HEAD_USE_CROSSING_BRK  
  @c_switch_full        @ref MEDIC_CFG_HYPOTHESIS_EVAL_AND_DECISION   

  @pre                  None
  @post                 None

  @InOutCorrelation     Not defined
  
  @testmethod           Test of output data (dynamic module test)

  @traceability         Design Decision
  
  @author               Daniel Deitrich| Daniel.Deitrich@continental-corporation.com
*************************************************************************************************************************/
static BrakeState_t HEADBrakeLevel_LongVru_2_ACTIVE_Output( /*Input*/ const struct HEADInputData_t *pInputData,
                                                              const struct HEADModule_t *pModule,
                                                              HEADModuleOutputBrakeFunction_t *pPreBrakeFunction,
                                                              const HEADModOutBrakeFunctionPar_t *pPreBrakeFunctionPar)
{
  BrakeState_t nextState;

  nextState = eBrakeState_LongVru_LEVEL_2;
  HEADActualBrakeState = nextState;
  HEADActivatedBrakeState = eBrakeState_LongVru_LEVEL_2;   /*Last Brake State for activation*/

  /* LongVru brake activation function call */
  (void)HEADBrakeActivation( pInputData, pModule, pPreBrakeFunction, pPreBrakeFunctionPar );

  /************************************* timer handling ********************************************/
  HEADfDurationVehLevelOne                   = 0.0f;
  HEADfDurationVehLevelTwo                   = 0.0f;
  HEADfDurationVehLevelThree                 = 0.0f;
  HEADfDurationPedLevelOne                   = 0.0f;
  HEADfDurationPedLevelTwo                   = 0.0f;
  HEADfDurationPedLevelThree                 = 0.0f;
  HEADfDurationLongVruLevelOne              += pInputData->fCycleTime;
  HEADfDurationLongVruLevelTwo              += pInputData->fCycleTime;
  #if (HEAD_USE_CROSSING_BRK)
  HEADfDurationCrossBrk                      = 0;
  #endif
  pPreBrakeFunction->pfActiveTimeVeh1        = &HEADfDurationVehLevelOne;     /*Timer Module Active*/
  pPreBrakeFunction->pfActiveTimeVeh2        = &HEADfDurationVehLevelTwo;     /*Timer Level 2*/
  pPreBrakeFunction->pfActiveTimeVeh3        = &HEADfDurationVehLevelThree;   /*Timer Level 3*/
  pPreBrakeFunction->pfActiveTimePed1        = &HEADfDurationPedLevelOne;     /*Timer Ped Level 1*/
  pPreBrakeFunction->pfActiveTimePed2        = &HEADfDurationPedLevelTwo;     /*Timer Ped Level 2*/
  pPreBrakeFunction->pfActiveTimePed3        = &HEADfDurationPedLevelThree;   /*Timer Ped Level 3*/
  pPreBrakeFunction->pfActiveTimeLongVru1    = &HEADfDurationLongVruLevelOne; /*Timer LongVru Level 1*/
  pPreBrakeFunction->pfActiveTimeLongVru2    = &HEADfDurationLongVruLevelTwo; /*Timer LongVru Level 2*/
  #if (HEAD_USE_CROSSING_BRK)
  pPreBrakeFunction->pfActiveTimeCrossBrk    = &HEADfDurationCrossBrk;/*Timer Cross Brk*/
  #endif

  HEADbBrakeActiveState               = b_TRUE;
  pPreBrakeFunction->pbPreBrakeActive = &HEADbBrakeActiveState;
  pPreBrakeFunction->pePreBrakeState  = &HEADActualBrakeState;

  return nextState;
}

#if (HEAD_USE_CROSSING_BRK)
/*************************************************************************************************************************
  Functionname:         HEADBrakeLevel_CrossBrk_ACTIVE_Output                                                      */ /*!

  @brief                Cross Brake ACTIVE Output 

  @description          This is a function that handles the transition to Active Brake state Cross_Brake.
                        Activate brake function for the most critiacl Active Hypothesis of Cross_Brake 
                        and update brake function output parameters and status bits accordingly.
                        @startuml
                        start
                        :Update Brake State as Cross-Brake;
                        :Activate Cross-Brake;
                        :Update timer handling;
                        Note:Update Cross brake active timer.
                        :Update Brake function Output parameters;
                        :Update Brake status bit as active;
                        stop
                        @enduml

  @return               BrakeState_t : Enum value correspond to Brake state Cross_Brake
  
  @param[in]            pInputData : Pointer to Input data
  @param[in]            pModule : Pointer to a Module
  @param[out]           pPreBrakeFunction : Pointer to Break Function
  @param[in]            pPreBrakeFunctionPar : Pointer to Break Function Parameter
  
  @glob_in              None
  @glob_out             @ref HEADActualBrakeState \n            @ref HEADActivatedBrakeState \n
                        @ref HEADbBrakeActiveState \n           @ref HEADfDurationVehLevelOne \n        
                        @ref HEADfDurationVehLevelTwo \n        @ref HEADfDurationVehLevelThree \n
                        @ref HEADfDurationPedLevelOne \n        @ref HEADfDurationPedLevelTwo \n
                        @ref HEADfDurationPedLevelThree \n      @ref HEADfDurationLongVruLevelOne \n
                        @ref HEADfDurationLongVruLevelTwo \n    @ref HEADfDurationCrossBrk

  @c_switch_part        None
  @c_switch_full        @ref HEAD_USE_CROSSING_BRK \n           @ref MEDIC_CFG_HYPOTHESIS_EVAL_AND_DECISION   

  @pre                  None
  @post                 None

  @InOutCorrelation     Not defined
  
  @testmethod           Test of output data (dynamic module test)

  @traceability         Design Decision
  
  @author               Daniel Deitrich| Daniel.Deitrich@continental-corporation.com
*************************************************************************************************************************/
static BrakeState_t HEADBrakeLevel_CrossBrk_ACTIVE_Output( /*Input*/ const struct HEADInputData_t *pInputData,
                                                              const struct HEADModule_t *pModule,
                                                              HEADModuleOutputBrakeFunction_t *pPreBrakeFunction,
                                                              const HEADModOutBrakeFunctionPar_t *pPreBrakeFunctionPar)
{
  BrakeState_t nextState;

  nextState = eBrakeState_CROSSBRK;
  HEADActualBrakeState = nextState;
  HEADActivatedBrakeState = eBrakeState_CROSSBRK;   /*Last Brake State for activation*/

  (void)HEADBrakeActivation(pInputData, pModule, pPreBrakeFunction, pPreBrakeFunctionPar);

  /************************************* timer handling ********************************************/
  HEADfDurationVehLevelOne                   = 0;
  HEADfDurationVehLevelTwo                   = 0;
  HEADfDurationVehLevelThree                 = 0;
  HEADfDurationPedLevelOne                   = 0;
  HEADfDurationPedLevelTwo                   = 0;
  HEADfDurationPedLevelThree                 = 0;
  HEADfDurationLongVruLevelOne               = 0;
  HEADfDurationLongVruLevelTwo               = 0;
  HEADfDurationCrossBrk                     += pInputData->fCycleTime;
  pPreBrakeFunction->pfActiveTimeVeh1        = &HEADfDurationVehLevelOne;   /*Timer Module Active*/
  pPreBrakeFunction->pfActiveTimeVeh2        = &HEADfDurationVehLevelTwo;   /*Timer Level 2 and Level 3*/
  pPreBrakeFunction->pfActiveTimeVeh3        = &HEADfDurationVehLevelThree; /*Timer Level 2 and Level 3*/
  pPreBrakeFunction->pfActiveTimePed1        = &HEADfDurationPedLevelOne;  /*Timer Ped Level 1*/
  pPreBrakeFunction->pfActiveTimePed2        = &HEADfDurationPedLevelTwo;  /*Timer Ped Level 2*/
  pPreBrakeFunction->pfActiveTimePed3        = &HEADfDurationPedLevelThree; /*Timer Ped Level 3*/
  pPreBrakeFunction->pfActiveTimeCrossBrk    = &HEADfDurationCrossBrk;   /*Timer Cross Brk*/
  pPreBrakeFunction->pfActiveTimeLongVru1    = &HEADfDurationLongVruLevelOne;   /*Timer LongVru Level 1*/
  pPreBrakeFunction->pfActiveTimeLongVru2    = &HEADfDurationLongVruLevelTwo; /*Timer LongVru Level 2*/

  HEADbBrakeActiveState               = TRUE;
  pPreBrakeFunction->pbPreBrakeActive = &HEADbBrakeActiveState;
  pPreBrakeFunction->pePreBrakeState  = &HEADActualBrakeState;
  return nextState;
}
#endif

#if (HEAD_USE_RAMP_BRK)
/*************************************************************************************************************************
  Functionname:         HEADBrakeLevel_RAMPOUT_Output                                                               */ /*!

  @brief                HEAD Brake Level RAMPOUT Output

  @description          This function is used to activate RampOut state for brake state machine and update brake function 
                        output parameters and status bits accordingly.
                        And also decides when to move from RampOut state to Passive state, based on achieved deceleration 
                        (or) Negative Driver feedback to stop Prebrake.                        
                        @startuml
                        Start
                        :Get Driver Feedback;
                        Note left: Actual Driver Feedback
                        :Get Driver Activity;
                        Note right: Actual Driver Activity.
                        :Get Ego Longitudinal Velocity;
                        Note left: Actual Driver Feedback.
                        :Get Ego Longitudinal Acceleration;
                        Note right: Actual Driver Feedback.
                        :Get Interpolation Value of driver feedback
                        to stop Brake event;
                        Note
                        Negative Driver feedback threshold to stop
                        a prebrake event.
                        End note
                        :Update Next Brake State as Ramp
                        Update Brake status bit as active;
                        If ( (Driver feedback to stop Brake <= 50%) OR
                        (Actual Driver feedback >= Driver activity threshold to stop brake)) then (yes)
                            :Set Req.Brake Deceleration as Zero
                            Update Brake Deceleration
                            Update Next Brake State as PASSIVE
                            Update Brake status bit as False;
                        Else (no)
                            :Find Max allowed Speed reduction;
                        Note right
                        Max allowed speed reduction is the interpolation value of table parameter 
                        MaxAllowVeloReduct based On Host speed during brake active.
                        End note
                        If (check if already ramped?) then (yes)
                            :Get Required brake deceleration
                            MAX(LastcycleDeceleration ,
                            (LastcycleDeceleration+(CycleTime*RampOutGradient)));
                        Else (no)
                            :Get Required brake deceleration
                             MAX(Longitudinal Acceleration,LastcycleDeceleration);
                        Endif
                            :Update Brake status bit as true;
                        If ((Req.deceleration > 0) OR
                        (HostSpeedDuringBrakeActivation-Long.Acceleration)>= Max.AllowedSpeedRedu) Then (yes)
                            :Set Req.Brake Deceleration as Zero
                            Update Next Brake State as PASSIVE
                            Update Brake status bit as False;
                        Endif
                            :Update Brake Deceleration;
                        Endif
                            :Update Ramp status Flag as true;
                            :Move all the Brake module to state wait;
                            :Set Active hypothesisNr for Brake function to default;
                            :Update timer handling; 
                        Note left
                        Count cycle time for all brake modules
                        End note
                        :Update Brake state as Ramp;
                        :Return next Brake state;
                        Stop
                        @enduml

  @return               BrakeState_t : Enum value correspond to a Brake state 
  
  @param[in]            pInputData : Pointer to Input data
  @param[in]            pModule : Pointer to a Module
  @param[out]           pPreBrakeFunction : Pointer to Break Function
  @param[in]            pPreBrakeFunctionPar : Pointer to Break Function Parameter
  
  @glob_in              None
  @glob_out             @ref HEADActualBrakeState \n            @ref HEADbBrakeActiveState \n
                        @ref HEADbAlreadyRamped \n              @ref HeadBrakeHostSpeedLastTransToActive \n
                        @ref HEADRequestedDeceleration \n       @ref HEADActHypNr \n
                        @ref HEADfDurationVehLevelOne \n        @ref HEADfDurationVehLevelTwo \n
                        @ref HEADfDurationVehLevelThree \n      @ref HEADfDurationPedLevelOne \n
                        @ref HEADfDurationPedLevelTwo \n        @ref HEADfDurationPedLevelThree \n
                        @ref HEADfDurationLongVruLevelOne \n    @ref HEADfDurationLongVruLevelTwo \n            

  @c_switch_part        None
  @c_switch_full        @ref MEDIC_CFG_HYPOTHESIS_EVAL_AND_DECISION \n    @ref HEAD_USE_RAMP_BRK

  @pre                  None
  @post                 None

  @InOutCorrelation     Not defined
  
  @testmethod           Test of output data (dynamic module test)

  @traceability         Design Decision
  
  @author               Daniel Deitrich| Daniel.Deitrich@continental-corporation.com
*************************************************************************************************************************/
static BrakeState_t HEADBrakeLevel_RAMPOUT_Output( /*Input*/ const struct HEADInputData_t *pInputData,
                                                             const struct HEADModule_t *pModule,
                                                             HEADModuleOutputBrakeFunction_t *pPreBrakeFunction,
                                                             const HEADModOutBrakeFunctionPar_t *pPreBrakeFunctionPar)
{
  BrakeState_t nextState;
  sint32 actualDriverFeedback;
  sint32 actualDriverActivity;
  float32 fLongVelocity;
  float32 fLongAcceleration;
  float32 fbDriverFeedback;    // actual Driver Feedback bool
  eGDBError_t retValue = GDB_ERROR_NONE;

  /*get actual Longitudinal Velocity, Driver Feedback and Activity*/
  (void)HEADGetInputValue_sint32(pInputData->pInputValueList->DriverFeedback, HEAD_DEFAULT_DriverFeedbackProb, &actualDriverFeedback);
  (void)HEADGetInputValue_sint32(pInputData->pInputValueList->DriverActivity, HEAD_DEFAULT_DriverActivityProb, &actualDriverActivity);
  (void)HEADGetInputValue_float32(pInputData->pInputValueList->LongVelocity, HEAD_DEFAULT_LongVelocity, &fLongVelocity);
  (void)HEADGetInputValue_float32(pInputData->pInputValueList->LongAcceleration, HEAD_DEFAULT_LongAccel, &fLongAcceleration);
  fbDriverFeedback = HEADCalculatePolygonValuef32(pPreBrakeFunctionPar->AutoBrkParTabDrvFdkToRampOut_Rows, &pPreBrakeFunctionPar->AutoBrkParTabDrvFdkToRampOut[0], (float32)actualDriverFeedback);

  nextState = eBrakeState_RAMP;
  HEADbBrakeActiveState = b_TRUE;

  if( ( fbDriverFeedback     <= BOOL_BORDER)
    ||( actualDriverActivity >= ((sint32)(pPreBrakeFunctionPar->AutoBrkParDrvActToRampOut)))
    )
  {
    HEADRequestedDeceleration = 0.0f;
    pPreBrakeFunction->pfPreBrakeDeceleration = &HEADRequestedDeceleration;
    nextState = eBrakeState_PASSIVE;
    *(pPreBrakeFunction->pbPreBrakeActive) = b_FALSE;
  }
  else 
  {
    const float32 fMaxAllowedVelo = HEADCalculatePolygonValuef32(pPreBrakeFunctionPar->AutoBrkParMaxAllowVeloReduct_Rows, &pPreBrakeFunctionPar->AutoBrkParMaxAllowVeloReduct[0], HeadBrakeHostSpeedLastTransToActive);
    if (HEADbAlreadyRamped == b_TRUE)
    {
      HEADRequestedDeceleration = MAX_FLOAT(HEADRequestedDeceleration, HEADRequestedDeceleration + ((pInputData->fCycleTime) * (pPreBrakeFunctionPar->AutoBrkParRampOutGrad)));
    }
    else
    {
      HEADRequestedDeceleration = MAX_FLOAT(fLongAcceleration, HEADRequestedDeceleration);
    }
    *(pPreBrakeFunction->pbPreBrakeActive) = b_TRUE;
    
    if(  (HEADRequestedDeceleration > 0.0f)
       ||((HeadBrakeHostSpeedLastTransToActive - fLongVelocity) >= fMaxAllowedVelo)
      )
    {
      HEADRequestedDeceleration = 0.0f;
      nextState = eBrakeState_PASSIVE;
      *(pPreBrakeFunction->pbPreBrakeActive) = b_FALSE;
    }
    pPreBrakeFunction->pfPreBrakeDeceleration = &HEADRequestedDeceleration;
  }

  HEADbAlreadyRamped = b_TRUE;

  /* Set all Brake Modules to State Wait */
  HEADSetAllBrakeModulesToState(HEADSMState_WAIT, pInputData,&retValue);

  HEADActHypNr                      = HEADNoHypothesis;
  pPreBrakeFunction->pActHypNr      = &HEADActHypNr;
  /************************************* timer handling ********************************************/
  HEADfDurationVehLevelOne                  +=  pInputData->fCycleTime;
  HEADfDurationVehLevelTwo                  +=  pInputData->fCycleTime;
  HEADfDurationVehLevelThree                +=  pInputData->fCycleTime;
  HEADfDurationPedLevelOne                  +=  pInputData->fCycleTime;
  HEADfDurationPedLevelTwo                  +=  pInputData->fCycleTime;
  HEADfDurationPedLevelThree                +=  pInputData->fCycleTime;
  HEADfDurationLongVruLevelOne              +=  pInputData->fCycleTime;
  HEADfDurationLongVruLevelTwo              +=  pInputData->fCycleTime;
  pPreBrakeFunction->pfActiveTimeVeh1        =  &HEADfDurationVehLevelOne;
  pPreBrakeFunction->pfActiveTimeVeh2        =  &HEADfDurationVehLevelTwo;
  pPreBrakeFunction->pfActiveTimeVeh3        =  &HEADfDurationVehLevelThree;
  pPreBrakeFunction->pfActiveTimePed1        =  &HEADfDurationPedLevelOne;  /*Timer Ped Level 1*/
  pPreBrakeFunction->pfActiveTimePed2        =  &HEADfDurationPedLevelTwo;  /*Timer Ped Level 2*/
  pPreBrakeFunction->pfActiveTimePed3        =  &HEADfDurationPedLevelThree; /*Timer Ped Level 3*/
  pPreBrakeFunction->pfActiveTimeLongVru1    = &HEADfDurationLongVruLevelOne;   /*Timer LongVru Level 1*/
  pPreBrakeFunction->pfActiveTimeLongVru2    = &HEADfDurationLongVruLevelTwo; /*Timer LongVru Level 2*/
  
  pPreBrakeFunction->pePreBrakeState  =   &HEADActualBrakeState;
  
  _PARAM_UNUSED(pModule);/*PRQA S 3119 #date: 2020-06-02, reviewer: Nalina M, reason: Variable will be used in future. */

  return nextState;
}
#endif

/*************************************************************************************************************************
  Functionname:         HEADBrakeActivation                                                                         */ /*!

  @brief                Brake activation function 

  @description          This function is used to Set brake deceleration for activated Brake module. 
                        The required Brake deceleration is decided on the following Principle
                        1)Find the most critical Active Hypothesis for the activated Brake Module.
                        2)Based on the most critical Active Hypothesis type the needed Brake deceleration 
                        is set from Anec Control(If Anec is Enabled),else it is set based on Brake Function 
                        Parameter.
                        @startuml
                        Start
                        :Fetch actual Ego Velocity;
                        :Fetch actual Ego Acceleration;
                        :Get Active Hypothesis for the Module;
                        Note:Get active hypothesis for the Module\n for which we need to activate Brake.
                        :Get Most Critical activating Hypothesis for the Module;
                        :Update Active Hypothesis details;
                        Note right
                        ->Update Active Hypothesis number;
                        ->Update Brake function activation hypothesis number;
                        End note
                        If(Is the Most critical activating Hypothesis Valid?) then (yes)
                            :Fetch Hypothesis type and necessary deceleration;
                        Note left
                        Fetch Hypothesis type and necessary deceleration value 
                        corresponds to Active Hypothesis.
                        End note
                        Else (no)
                            :Make Hypothesis type as No_Hypothesis and 
                        Needed deceleration as Zero;
                        Endif
                        :Get Brake Deceleration Value from Brake function parameter;
                        If (Is Anec Control active?) then (yes)
                            :Get Anec deceleration value;
                        Note right
                        ->Deceleration Value is calculated based on Necessary
                        Acceleration value which we get from CD hypothesis.

                        ->It performs closed loop control with target 
                        object using necessary deceleration

                        Note:Anec based deceleration is possible only if Enabled.
                        End note
                        Else (no)
                        endif
                        :Set Brake Deceleration; 
                        Note right
                        ->If Anec is enabled set decelaration based on Anec control
                        ->else Set deceleration based on predefined Brake function parameter.
                        End note
                        stop
                        @enduml

  @return               eGDBError_t : GDB_ERROR_NONE is returned when pointers are okay, otherwise an error code is returned.
  
  @param[in]            pInputData : Pointer to Input data
  @param[in]            pModule : Pointer to a Module
  @param[in,out]        pPreBrakeFunction : Pointer to Break Function
  @param[in]            pPreBrakeFunctionPar : Pointer to Break Function Parameter
  
  @glob_in              None
  @glob_out             @ref HEADActHypNr 
                        

  @c_switch_part        @ref HEAD_USE_ANEC_CTRL
  @c_switch_full        @ref MEDIC_CFG_HYPOTHESIS_EVAL_AND_DECISION   

  @pre                  None
  @post                 None

  @InOutCorrelation     Not defined
  
  @testmethod           Test of output data (dynamic module test)

  @traceability         Design Decision
  
  @author               Daniel Deitrich| Daniel.Deitrich@continental-corporation.com
*************************************************************************************************************************/
static eGDBError_t HEADBrakeActivation( /*Input*/ const struct HEADInputData_t *pInputData,
                                                  const struct HEADModule_t *pModule,
                                                  HEADModuleOutputBrakeFunction_t *pPreBrakeFunction,
                                                  const HEADModOutBrakeFunctionPar_t *pPreBrakeFunctionPar )
{
  /*Variable declaration*/
  eGDBError_t retVal = GDB_ERROR_NONE;
  const Hypothesis_t* pKinHyp = NULL;
  uint16 uiModBitF = 0;
  HEADHypothesisNr_t kinHypNr = HEADNoHypothesis;
  /*PRQA S 3334 1*/ /* #date: 2023-02-20, reviewer: Veeresh B, reason: No side effect, Generic Implementation */
  eCDHypothesisType_t eType = CDHypothesisType_No;
  #if (HEAD_USE_ANEC_CTRL == MEDIC_ON)
  float32 fNeededDecel;
  #endif
  float32 fLongVelocity;
  float32 fLongAccleration;
  float32 fBrakeDecel;
  
  boolean bInsideVegoRange = b_FALSE;

  if(   (pInputData != NULL)
     && (pModule != NULL)
     && (pPreBrakeFunction!= NULL)
     && (pPreBrakeFunctionPar != NULL))
  {
    (void)HEADGetInputValue_float32(pInputData->pInputValueList->LongVelocity, HEAD_DEFAULT_LongVelocity, &fLongVelocity);
    (void)HEADGetInputValue_float32(pInputData->pInputValueList->LongAcceleration, HEAD_DEFAULT_LongAccel, &fLongAccleration);

    uiModBitF = HEADGetActiveHypothesisForModule(pModule);
    kinHypNr  = HEADGetMostCritHypOfBitfieldForModule(pInputData, uiModBitF, &pKinHyp, b_TRUE);
    HEADActHypNr = kinHypNr;
    pPreBrakeFunction->pActHypNr = &HEADActHypNr;

    if( kinHypNr != HEADNoHypothesis )
    {
      eType           = pKinHyp->eType;
      #if (HEAD_USE_ANEC_CTRL == MEDIC_ON)
      fNeededDecel    = pKinHyp->fLongNecAccel;
      #endif
    }
    else
    {
      eType           =  CDHypothesisType_No;
      #if (HEAD_USE_ANEC_CTRL == MEDIC_ON)
      fNeededDecel    = 0.0f;
      #endif
    }

    /* Get Brake Deceleration Value from Parameters */
    HEADGetBrakeDecel( pPreBrakeFunctionPar, fLongVelocity, &eType, &bInsideVegoRange, &fBrakeDecel);

    #if (HEAD_USE_ANEC_CTRL == MEDIC_ON)
    if (pPreBrakeFunctionPar->HEAD_BRK_ANEC_CTRL == TRUE)/*PRQA S 1823 #date: 2020-06-11, reviewer: Nalina M, reason: Supressing because while casting a variable, the value can change*/
    {
      /* Set Brake Deceleration output with Anec Control */
      HEADAnecCtrl( pModule, pPreBrakeFunction, pPreBrakeFunctionPar, fLongVelocity, pKinHyp, &fNeededDecel, &bInsideVegoRange, &fBrakeDecel );
    }
    else
    {
      pPreBrakeFunction->pfPreBrakeDeceleration  = &HEADRequestedDeceleration;
    }
    #else /*HEAD_USE_ANEC_CTRL*/
    pPreBrakeFunction->pfPreBrakeDeceleration  = &HEADRequestedDeceleration;
    #endif
  }
  else
  {
    retVal = GDB_ERROR_POINTER_NULL;
  }
  return retVal;
}

/*************************************************************************************************************************
  Functionname:         HEADGetBrakeDecel                                                                           */ /*!

  @brief                Get Deceleration Value from Brake function Parameter. 

  @description          This Function is used to get needed deceleration value from Brake function Parameter.
                        The needed deceleration is decided on hypothesis type and current ego velocity.
                        ->Based on hypothesis type, which brake function parameter to be considered for calulating  
                        deceleration value is decided.
                        ->Based on current Ego velocity, the needed deceleration is interpolted from the 
                        Brake function parameter.
                        @startuml
                        Start
                        if (Is the current CD Hypothesis Type is valid?) then (yes)
                        if ((HypothesisType == RunUpBraking)) then (yes)
                            :Fetch Required deceleration value from interpolation table
                            correspond to Brake Deceleration;
                            :Update status bit for closed loop control;
                        Floating Note left
                         ->True if the Ego velocity during Brake activation is less than 
                            Max control velocity of corresponding Brake.
                        End note
                        elseif ((HypothesisType == RunUpStationary)) then (yes)
                            :Fetch Required deceleration value from interpolation table
                            correspond to stationary Deceleration;
                            :Update status bit for closed loop control;
                        elseif ((HypothesisType == RunUp)) then (yes)
                            :Fetch Required deceleration value from interpolation table
                            correspond to Moving Deceleration;
                            :Update status bit for closed loop control;
                        else(no)
                            :Fetch Required deceleration value from common 
                            interpolation table for deceleration;
                            :Update status bit for closed loop control;
                        endif
                        else (no)
                            :Reset Deceleration Request;
                        Endif
                        :Update HEAD Requested deceleration; 
                        stop
                        @enduml

  @return               void
  
  @param[in]            pPreBrakeFunctionPar : Pointer to Break Function Parameter
  @param[in]            fLongVelocity : Actual longitudinal velocity
  @param[in]            peType : Pointer to CD Hypothesis Type
  @param[out]           pbInsideVegoRange :Boolean variable indicates Ego velocity is within Max Range or not during brake activation.
  @param[out]           pfBrakeDecel : pointer to required deceleration
  
  @glob_in              None
  @glob_out             @ref HeadBrakeHostSpeedLastTransToActive \n     @ref HEADRequestedDeceleration
                        

  @c_switch_part        None
  @c_switch_full        @ref MEDIC_CFG_HYPOTHESIS_EVAL_AND_DECISION   

  @pre                  None
  @post                 None

  @InOutCorrelation     Not defined
  
  @testmethod           Test of output data (dynamic module test)

  @traceability         Design Decision
  
  @author               Daniel Deitrich| Daniel.Deitrich@continental-corporation.com
*************************************************************************************************************************/
static void HEADGetBrakeDecel( /*Input*/ const HEADModOutBrakeFunctionPar_t *pPreBrakeFunctionPar, 
                                         float32 fLongVelocity,
                                         const eCDHypothesisType_t *peType,
                                         boolean *pbInsideVegoRange,
                                         float32 *pfBrakeDecel )
{
  *pbInsideVegoRange = b_FALSE;
  *pfBrakeDecel = 0.0f;

  if(*peType != CDHypothesisType_No)
  {
    if(*peType == CDHypothesisType_RunUpBraking)
    {
      *pfBrakeDecel = HEADCalculatePolygonValuef32(pPreBrakeFunctionPar->AutoBrkParTabBrakeDecel_Rows, &pPreBrakeFunctionPar->AutoBrkParTabBrakeDecel[0], fLongVelocity);

      if ( HeadBrakeHostSpeedLastTransToActive < pPreBrakeFunctionPar->AutoBrkParCtrlMaxVelBrake)
      {
        *pbInsideVegoRange = b_TRUE;
      }
    }
    else if(*peType == CDHypothesisType_RunUpStationary)
    {
      /* in case of stationary object use needed deceleration */
      *pfBrakeDecel = HEADCalculatePolygonValuef32(pPreBrakeFunctionPar->AutoBrkParTabStatDecel_Rows, &pPreBrakeFunctionPar->AutoBrkParTabStatDecel[0], fLongVelocity);

      if (HeadBrakeHostSpeedLastTransToActive < pPreBrakeFunctionPar->AutoBrkParCtrlMaxVelStat)
      {
        *pbInsideVegoRange = b_TRUE;
      }
    }
    else if(*peType == CDHypothesisType_RunUp)
    {
      *pfBrakeDecel = HEADCalculatePolygonValuef32(pPreBrakeFunctionPar->AutoBrkParTabMovDecel_Rows, &pPreBrakeFunctionPar->AutoBrkParTabMovDecel[0], fLongVelocity);

      if (HeadBrakeHostSpeedLastTransToActive < pPreBrakeFunctionPar->AutoBrkParCtrlMaxVelMov) 
      {
        *pbInsideVegoRange = b_TRUE;
      }
    }
    else if(*peType == CDHypothesisType_PedCollision)
    {
      *pfBrakeDecel = HEADCalculatePolygonValuef32(pPreBrakeFunctionPar->AutoBrkParTabCommonDecel_Rows, &pPreBrakeFunctionPar->AutoBrkParTabCommonDecel[0], fLongVelocity);

      if (HeadBrakeHostSpeedLastTransToActive < pPreBrakeFunctionPar->AutoBrkParCtrlMaxVelBrake) 
      {
        *pbInsideVegoRange = b_TRUE;
      }
    }
    else
    {
      *pfBrakeDecel = HEADCalculatePolygonValuef32(pPreBrakeFunctionPar->AutoBrkParTabCommonDecel_Rows, &pPreBrakeFunctionPar->AutoBrkParTabCommonDecel[0], fLongVelocity);

      if (HeadBrakeHostSpeedLastTransToActive < pPreBrakeFunctionPar->AutoBrkParCtrlMaxVelStat) 
      {
        *pbInsideVegoRange = b_TRUE;
      }
    }
  }
  HEADRequestedDeceleration = *pfBrakeDecel;
}

#if (HEAD_USE_ANEC_CTRL == MEDIC_ON)
/*************************************************************************************************************************
  Functionname:         HEADAnecCtrl                                                                                */ /*!

  @brief                Anec Control function for all 3 Levels 

  @description          This Function is used to get needed deceleration value based on Anec Control.
                        @startuml
                        Start
                        :Find Min and Max deceleration for
                        Current Ego velocity;
                        Note
                         ->Min deceleration is the interpolation value of Ego velocity from 
                           Common deceleration table parameter.
                         ->Max deceleration is the interpolation value of Ego velocity from 
                           Max_Deceleration table parameter.
                        End note
                        :Initialize Active Hypothesis Iterator;
                        Note right
                         -> Get Active Hypothesis for the Active brake module.
                         -> Initialize Current Hypothesis
                        End note
                        while (Iterate through all active Hypothesis?)
                        if ((valid Hypothesis?)  AND 
                        (Needed.decel > critical_hyp.AccelerationNecessary)) then (yes)
                            :Update Needed Deceleration value to\n critical_hyp.AccelerationNecessary;
                        endif
                        :Go to Next hypothesis;
                        Endwhile
                        If ((Brake state != Passive) And (Brake state != Ramp)) then (yes)
                        If ((Ego_Velocty_Inside_Max_Range) AND
                        (-RelativeSpeedOfVehicle< AutoBrkParCtrlMaxStartVrel)) then (yes)
                            :Clip needed deceleration value based on Brake 
                            deceleraton(Brake function Parameter) and max 
                            deceleration for current ego velocity.;
                            :Update Needed deceleration to HEAD Requested deceleration;
                        Endif
                        Else (no)
                            :Clip needed deceleration value based on min and 
                            max deceleration for current ego velocity.;
                            :Update Needed deceleration to HEAD Requested deceleration;
                        Endif
                        stop
                        @enduml

  @return               void
  
  @param[in]            pModule : Pointer to a Module
  @param[in]            pPreBrakeFunction : Pointer to Break Function
  @param[in]            pPreBrakeFunctionPar : Pointer to Break Function Parameter
  @param[in]            fLongVelocity : Actual longitudinal velocity
  @param[in]            pKinHyp : Pointer to  Kinematic Hypotheses
  @param[in]            pfNeededDecel : Pointer to Necessary acceleration from CD Hypotheses
  @param[out]           pbInsideVegoRange :Boolean variable indicates Ego velocity is within Max Range or not during brake activation.
  @param[out]           pfBrakeDecel : pointer to required deceleration
  
  @glob_in              None
  @glob_out             @ref HEADActualBrakeState \n     @ref HeadBrakeRelSpeedTransToActive \n
                        @ref HEADRequestedDeceleration
                        

  @c_switch_part        @ref HEAD_USE_RAMP_BRK
  @c_switch_full        @ref MEDIC_CFG_HYPOTHESIS_EVAL_AND_DECISION \n    @ref HEAD_USE_ANEC_CTRL

  @pre                  None
  @post                 None

  @InOutCorrelation     Not defined
  
  @testmethod           Test of output data (dynamic module test)

  @traceability         Design Decision
  
  @author               Daniel Deitrich| Daniel.Deitrich@continental-corporation.com
*************************************************************************************************************************/
static void HEADAnecCtrl( /*Input*/ const struct HEADModule_t * pModule,
                                    HEADModuleOutputBrakeFunction_t * pPreBrakeFunction,
                                    const HEADModOutBrakeFunctionPar_t * pPreBrakeFunctionPar, 
                                    float32 fLongVelocity, 
                                    const Hypothesis_t* pKinHyp, 
                                    float32 *pfNeededDecel, 
                                    const boolean *pbInsideVegoRange, 
                                    float32 *pfBrakeDecel )
{
  /*Variable declaration*/ 
  float32 fAccelLimMin; /* Maximum allowed deceleration*/
  float32 fAccelLimMax; /* Minimum required deceleration*/
  HEADActiveHypIterator_t pIterator;
  const HEADORGroupBitField_t OrGroupIndicator = 255; /* All Or Groups */
  HEADHypothesisNr_t ActiveHypoNr = HEADNoHypothesis;
  float32 fBrkDecelStep;
  
  /* Maximum allowed deceleration*/
  fAccelLimMin = HEADCalculatePolygonValuef32(pPreBrakeFunctionPar->AutoBrkParTabCommonDecel_Rows, &pPreBrakeFunctionPar->AutoBrkParTabCommonDecel[0], fLongVelocity);
  fAccelLimMax = HEADCalculatePolygonValuef32(pPreBrakeFunctionPar->AutoBrkParTabMaxDecel_Rows,    &pPreBrakeFunctionPar->AutoBrkParTabMaxDecel[0],    fLongVelocity);

  HEADInitActiveHypoIterator(pModule, OrGroupIndicator, &pIterator);
  while(HEADActiveHypoIteratorGetNext(&pIterator, &ActiveHypoNr) == b_TRUE)
  {
    if( (pKinHyp!= NULL)
      &&(ActiveHypoNr != HEADNoHypothesis)
      &&(pKinHyp->fLongNecAccel < *pfNeededDecel )
      )
    {
      *pfNeededDecel  = pKinHyp->fLongNecAccel;
    }
  }

  if(  (HEADActualBrakeState != eBrakeState_PASSIVE)
    #if (HEAD_USE_RAMP_BRK)
    && (HEADActualBrakeState != eBrakeState_RAMP)
    #endif
    )
  {
    if (   (*pbInsideVegoRange != b_FALSE)
      && ((-HeadBrakeRelSpeedTransToActive) < pPreBrakeFunctionPar->AutoBrkParCtrlMaxStartVrel))
    {
      /* Perform closed loop control with target object using necessary deceleration unless it's between the
      level1 and level2 curve */
      fBrkDecelStep = MAX_FLOAT(*pfBrakeDecel, fAccelLimMax);
      *pfBrakeDecel = MINMAX_FLOAT(*pfBrakeDecel, fBrkDecelStep, *pfNeededDecel);
      HEADRequestedDeceleration = *pfBrakeDecel;
      pPreBrakeFunction->pfPreBrakeDeceleration = &HEADRequestedDeceleration;
    }
  }
  else
  {
    HEADRequestedDeceleration = MINMAX_FLOAT(fAccelLimMin, fAccelLimMax, *pfNeededDecel);
    pPreBrakeFunction->pfPreBrakeDeceleration = &HEADRequestedDeceleration;
  }
}
#endif /*HEAD_USE_ANEC_CTRL*/

/*************************************************************************************************************************
  Functionname:         HEADSetAllBrakeModulesToState                                                               */ /*!

  @brief                Set all Brake Modules to same state

  @description          This Function is used to set all the Brake Modules to same state.
                        E.g.,Set all the brake modules to state wait.
                        @startuml
                        Start
                        :Get all brake modules;
                        Note left
                        Get information of all Brake Modules;
                        End note
                        :Do state transition;
                        Stop
                        @enduml

  @return               void
  
  @param[in]            HEADSMState : State to which all brake modules need to be moved.
  @param[in]            pInputData : Pointer to Input data
  @param[out]           retValue : GDB_ERROR_NONE is returned if State is okay, otherwise an error code is returned.

  @glob_in              None
  @glob_out             None     

  @c_switch_part        @ref HEAD_USE_CROSSING_BRK
  @c_switch_full        @ref MEDIC_CFG_HYPOTHESIS_EVAL_AND_DECISION 

  @pre                  None
  @post                 None

  @InOutCorrelation     Not defined
  
  @testmethod           Test of output data (dynamic module test)

  @traceability         Design Decision
  
  @author               Daniel Deitrich| Daniel.Deitrich@continental-corporation.com
*************************************************************************************************************************/
static void HEADSetAllBrakeModulesToState(eHEADSMState_t HEADSMState, const HEADInputData_t *pInputData, eGDBError_t* retValue)
{
  HEADModule_t* pVeh_AutoBrk1     = NULL;
  HEADModule_t* pVeh_AutoBrk2     = NULL;
  HEADModule_t* pVeh_AutoBrk3     = NULL;
  HEADModule_t* pPed_AutoBrk1     = NULL;
  HEADModule_t* pPed_AutoBrk2     = NULL;
  HEADModule_t* pPed_AutoBrk3     = NULL;
  HEADModule_t* pLongVru_AutoBrk1 = NULL;
  HEADModule_t* pLongVru_AutoBrk2 = NULL;
  #if (HEAD_USE_CROSSING_BRK)
  HEADModule_t* pVeh_CrossBrk = NULL;
  #endif

  *retValue = GDB_ERROR_NONE;
  /*Get Module information*/
  pVeh_AutoBrk1     = HEADGetModule(pInputData->pModuleList, HEAD_MOD_VEH_BRK_LV1);
  pVeh_AutoBrk2     = HEADGetModule(pInputData->pModuleList, HEAD_MOD_VEH_BRK_LV2);
  pVeh_AutoBrk3     = HEADGetModule(pInputData->pModuleList, HEAD_MOD_VEH_BRK_LV3);
  pPed_AutoBrk1     = HEADGetModule(pInputData->pModuleList, HEAD_MOD_PED_BRK_LV1);
  pPed_AutoBrk2     = HEADGetModule(pInputData->pModuleList, HEAD_MOD_PED_BRK_LV2);
  pPed_AutoBrk3     = HEADGetModule(pInputData->pModuleList, HEAD_MOD_PED_BRK_LV3);
  pLongVru_AutoBrk1 = HEADGetModule(pInputData->pModuleList, HEAD_MOD_LONGVRU_BRK_LV1);
  pLongVru_AutoBrk2 = HEADGetModule(pInputData->pModuleList, HEAD_MOD_LONGVRU_BRK_LV2);
  #if (HEAD_USE_CROSSING_BRK)
  pVeh_CrossBrk = HEADGetModule(pInputData->pModuleList, (uint32) HEAD_MOD_CROSS_BRK);
  #endif

  if (pVeh_AutoBrk1 != NULL)
  {
    HEADDoStateTransition(HEADSMState, pInputData, pVeh_AutoBrk1, retValue);
  }
  if (pVeh_AutoBrk2 != NULL)
  {
  HEADDoStateTransition(HEADSMState, pInputData, pVeh_AutoBrk2, retValue);
  }
  if (pVeh_AutoBrk3 != NULL)
  {
  HEADDoStateTransition(HEADSMState, pInputData, pVeh_AutoBrk3, retValue);
  }
  if (pPed_AutoBrk1 != NULL)
  {
  HEADDoStateTransition(HEADSMState, pInputData, pPed_AutoBrk1, retValue);
  }
  if (pPed_AutoBrk2 != NULL)
  {
  HEADDoStateTransition(HEADSMState, pInputData, pPed_AutoBrk2, retValue);
  }
  if (pPed_AutoBrk3 != NULL)
  {
  HEADDoStateTransition(HEADSMState, pInputData, pPed_AutoBrk3, retValue);
  }
  if (pLongVru_AutoBrk1 != NULL)
  {
    HEADDoStateTransition(HEADSMState, pInputData, pLongVru_AutoBrk1, retValue);
  }
  if (pLongVru_AutoBrk2 != NULL)
  {
    HEADDoStateTransition(HEADSMState, pInputData, pLongVru_AutoBrk2, retValue);
  }
  #if (HEAD_USE_CROSSING_BRK)
  if (pVeh_CrossBrk != NULL)
  {
  HEADDoStateTransition(HEADSMState, pInputData, pVeh_CrossBrk, retValue);
  }
  #endif
}/*PRQA S 7002 #date: 2020-06-02, reviewer: Nalina M, reason: No side effect, Supressing for better code maintainability*/


#if (HEAD_USE_CROSSING_BRK)
/*************************************************************************************************************************
  Functionname:         HEADGetAnecLong                                                                             */ /*!

  @brief                Get Needed Deceleration from CD Hypothesis

  @description          This function is used to get Needed Deceleration from CD Hypothesis
                        1)Find the most critical Active Hypothesis for the activated Brake Module.                        
                        2)Fetch needed deceleration from the most critical Active Hypothesis.
                        @startuml
                        Start
                        :Get Active Hypothesis for the Module;
                        :Find the Most Critical Hypothesis;
                        If ((MostCriticalHypothesis != NoHypothesis)) then (yes)
                        :Fetch needed deceleration from 
                        Most critical hypothesis;
                        Else (no)
                        :set needed deceleration as zero;
                        Endif
                        :Return needed deceleration;
                        Stop
                        @enduml

  @return               float32 : Enum value of Next Brake event to react
  
  @param[in]            pModule : Pointer to a Module
  @param[in]            pInputData : Pointer to Input data

  @glob_in              None
  @glob_out             None     

  @c_switch_part        None
  @c_switch_full        @ref MEDIC_CFG_HYPOTHESIS_EVAL_AND_DECISION \n    @ref HEAD_USE_CROSSING_BRK

  @pre                  None
  @post                 None

  @InOutCorrelation     Not defined
  
  @testmethod           Test of output data (dynamic module test)

  @traceability         Design Decision
  
  @author               Daniel Deitrich| Daniel.Deitrich@continental-corporation.com
*************************************************************************************************************************/
static float32 HEADGetAnecLong (const HEADModule_t *pModule, const HEADInputData_t *pInputData)
{
  float32 fNeededDecel;
  HEADHypothesisNr_t kinHypNr = HEADNoHypothesis;
  const Hypothesis_t* pKinHyp = NULL;
  uint16 uiModBitF = 0;

  uiModBitF = HEADGetActiveHypothesisForModule(pModule);
  
  if (pInputData != NULL)
  {
    kinHypNr  = HEADGetMostCritHypOfBitfieldForModule(pInputData, uiModBitF, &pKinHyp, TRUE);
  }
  else
  {
    kinHypNr = HEADNoHypothesis;
  }

  if(   (kinHypNr != HEADNoHypothesis )
     && (pKinHyp != NULL) 
    )
  {
    fNeededDecel    = pKinHyp->fLongNecAccel;
  }
  else
  {
    fNeededDecel    = 0;
  }
  return fNeededDecel;
}
#endif /* HEAD_USE_CROSSING_BRK */
#endif /* MEDIC_CFG_HYPOTHESIS_EVAL_AND_DECISION */
#endif /* !(MEDIC_CFG_HEAD20) */

/**@}*//* PRQA S 7013, 0861 *//* date: 2018-10-26, reviewer:Krupa H R, reason:suppressing nesting of control structures */
