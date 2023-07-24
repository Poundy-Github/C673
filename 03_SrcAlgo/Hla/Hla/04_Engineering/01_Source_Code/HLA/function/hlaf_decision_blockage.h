/*! @file ******************************************************************
  COMPANY:                Continental AG, BU ADAS, A.D.C. GmbH
 
  PROJECT:                MFC4xx

  COMPONENT:              HLA

  MODULNAME:              hlaf_decision_blockage.h

  DESCRIPTION:            HLA decision on blockage state.

  CREATION DATE:          2014-10-31
    
  CPU:                    Independent

  VERSION:                $Revision: 1.7 $
**************************************************************************** */

/* avoid cyclic binding -----------------------------------------------------*/
#ifndef H_HLAF_DECISION_BLOCKAGE_H
#define H_HLAF_DECISION_BLOCKAGE_H

/*****************************************************************************
  INCLUDES
*****************************************************************************/
#include "hlaf_type.h"
#include "HLA_DecisionParameters.h"

/*****************************************************************************
  SYMBOLIC CONSTANTS 
*****************************************************************************/


/*****************************************************************************
  TYPEDEFS 
*****************************************************************************/


/*****************************************************************************
  GLOBAL FUNCTION DECLARATIONS 
*****************************************************************************/
/** ************************************************************************************************
  \brief
    Decision of the internal blockage status based on the input by camera blockage algorithm.
  
  \pre
    None

  \post
    None

  \param [in]      pCbOutputs          Pointer to blockage output
  \param [in]      pRTETurnOnDelayPar  Pointer to RTE TurnOnDelay parameters
  \param [in]      pParams             Pointer to internal parameters
  \param [in]      pCamData            Pointer to camera data
  \param [in,out]  pData               Pointer to store blockage history

  \return
    Void

  \globals
    None

  \InOutCorrelation
    Based on the input from camera blockage the current blockage situation is assessed and according
    to the result the blockage output is set and possibly an error will be stored. For each blockage
    input the blockage output will be set and the transition for the next frame will be done. There
    are four internal state possible: Clearance Measurement, Blockage, No Blockage, Condensation.\n

    @startuml

    title State transitions of HLA blockage state

    [*] --> ClearanceMeasurement

    ClearanceMeasurement --> ClearanceMeasurement
    ClearanceMeasurement --> NoBlockage
    ClearanceMeasurement --> Blockage
    ClearanceMeasurement --> Condensation

    NoBlockage --> Blockage
    NoBlockage --> Condensation
    NoBlockage --> NoBlockage

    Blockage --> NoBlockage
    Blockage --> Condensation
    Blockage --> Blockage

    Condensation --> NoBlockage
    Condensation --> Blockage
    Condensation --> Condensation

    @enduml
    
    \li Clearance Measurement \n
      Blockage transition from Clearance Measurement to \n
      a) No Blockage: if NO_BLOCKAGE has been reported and a parameter based distance has been driven
         (currently 50 m) \n
      b) Blockage, if BLOCKAGE has been reported \n
      c) Condensation, if CONDENSATION has been reported and a parameter based distance has been
         driven (currently 50m)\n
      When there is no valid output by camera blockage algo after a parameter based distance (500m)
      and time (30s) an error will be set, which causes HLA to go into temp error. While clearance
      measurement is legally ongoing, elapsed time and covered distance are increased and the manual
      override is done.

      @startuml
      skinparam defaultTextAlignment left

      title Clearance Measurement state transitions

      state ClearanceMeasurement

      ClearanceMeasurement --> ClearanceMeasurement : keep state

      ClearanceMeasurement --> NoBlockage : No Blockage reported \ndriven at least a parameter based distance

      ClearanceMeasurement --> Blockage : Blockage reported

      ClearanceMeasurement --> Condensation : Condensation reported \ndriven at least a parameter based distance

      @enduml

    \li Blockage \n
      Blockage transition from BLOCKAGE to \n
      a) No Blockage, if NO_BLOCKAGE is reported and the vehicle is above activation speed for longer
         than a parameter based threshold (currently 2 s) \n
      b) Condensation, if CONDENSATION is reported and the vehicle is above activation speed for longer
         than a parameter based threshold (currently 2 s) \n
      Otherwise BLOCKAGE is kept.

      @startuml
      skinparam defaultTextAlignment left

      title Blockage state transitions

      state Blockage

      Blockage --> Blockage :keep state

      Blockage --> NoBlockage :  No Blockage reported \nNoBlockage state is kept for longer than codeable parameter

      Blockage --> Condensation : Condensation reported \nCondensation state is kept for longer than codeable parameter

      @enduml

    \li No Blockage \n
      Blockage transition from NO_BLOCKAGE to \n
      a) Blockage, if BLOCKAGE has been reported \n
      b) Condensation, if CONDENSATION is reported \n
      Otherwise NO_BLOCKAGE is kept.

      @startuml

      title No Blockage state transitions

      state NoBlockage

      NoBlockage --> NoBlockage :keep state

      NoBlockage --> Blockage : Blockage reported

      NoBlockage --> Condensation : Condensation reported

      @enduml

    \li Condensation \n
      Blockage transition from CONDENSTATION to \n
      a) No Blockage if NO_BLOCKAGE was reported \n
      b) Blockage if BLOCKAGE was reported \n
      Otherwise CONDENSTATION is kept.

      @startuml

      title Condensation state transitions

      state Condensation

      Condensation --> Condensation :keep state

      Condensation --> NoBlockage : No Blockage reported

      Condensation --> Blockage : Blockage reported

      @enduml
  
  \callsequence
    @startuml 
    title Sequence diagram of HLAFDecisionBlockage_Main()

    box "Function" #LightGreen
    participant hlaf.c       as Main
    participant hlaf_decision_blockage.c    as this
    end box

    autonumber "<b>[00]"
    Main ->> this: ""**HLAF_EnvironmentDecisions()**"" calls\n""**HLAFDecision_SetHBState()**""
    Activate this
    opt blockage state is clearance measurement
    this ->> this: Call HLAFDecisionBlockage_TransitionsClearMeas()
    end
    opt blockage state is no blockage
    this ->> this: Call HLAFDecisionBlockage_TransitionsNoBlockage()
    end
    opt blockage state is blockage
    this ->> this: Call HLAFDecisionBlockage_TransitionsBlockage()
    end
    opt blockage state is condensation
    this ->> this: Call HLAFDecisionBlockage_TransitionsCondensation()
    end
    this -->> Main: void
    Deactivate this
    @enduml


  \testmethod
    Module Test

  \traceability
***************************************************************************************************/
void HLAFDecisionBlockage_Main( const CB_t_ProvidedOutputs_t*          const pCbOutputs,
                                const RTE_HLAF_ParameterTurnOnDelay_t* const pRTETurnOnDelayPar,
                                const t_DecisionParametersBlockage*    const pParams,
                                const HLAFCameraData_t*                const pCamData,
                                      HLAFBlockage_t*                  const pData
                              );

/* avoid cyclic binding -----------------------------------------------------*/
#endif /* #ifndef H_HLAF_DECISION_BLOCKAGE_H */ 
