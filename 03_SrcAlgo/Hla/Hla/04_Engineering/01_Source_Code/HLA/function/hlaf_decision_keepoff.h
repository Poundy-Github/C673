/*! @file ******************************************************************
  COMPANY:                Continental AG, BU ADAS, A.D.C. GmbH
 
  PROJECT:                MFC4xx

  COMPONENT:              HLA

  MODULNAME:              hlaf_decision_keepoff.h

  DESCRIPTION:            HLAF decision for KeepOffReasons.

  CREATION DATE:          2014-11-03
    
  CPU:                    Independent

  VERSION:                $Revision: 1.7 $
**************************************************************************** */

/* avoid cyclic binding -----------------------------------------------------*/
#ifndef H_HLAF_DECISION_KEEPOFF_H
#define H_HLAF_DECISION_KEEPOFF_H

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
    The keep off reasons are updated depending on the various inputs.
  
  \pre
    None

  \post
    None

  \param [in]      pReqPorts           Pointer to request port list
  \param [in]      pFData              Pointer to HLA function data
  \param [in]      pParKeepOff         Pointer to function parameters
  \param [in]      pParTurnOnDelay     Pointer to function parameters
  \param [in]      eHighBeamStatePrev  Enum that holds the previous high beam state
  \param [in]      pRelVeh             Pointer to relevant vehicle
  \param [in]      pTurnOffReason      Pointer to turn off reasons
  \param [in,out]  pKeepOffReason      Pointer to keep off reasons

  \return
    void

  \globals
    None

  \InOutCorrelation
    Function controls the flow to set all keep off reasons according to the current situation. Every
    keep off reason corresponds to a bit in a bit field within the KeepOffReason struct. If one the
    reasons is valid the corresponding bit will be set. As long as at least one bit is set the high 
    beam will be kept off.

    The keep off reasons are:
    \li Speed \n based on the decision in the HLAFDecisionEnv_Speed() function the keep off reason
        will be set

    \li Maybe City \n when maybe city was detected and a relevant vehicle is in the frame a delay is 
        set and the high beam kept off or this time. This logic should prevent a toggling of the high
        beam before entering a city, since the maybe city state indicates that a potential city is ahead.

    \li Small Radius \n When driving through a small curve, which is defined via the coding parameter 
        smallRadiusRadius2TurnsOnThres, the high beam will be kept off for a delay time, which is
        defined by the parameter smallRadiusTurnOnDelay

    \li Minimum Time HB off \n The high beam shall be off for minimum time, to avoid fast toggling. This 
        time is defined in an internal coding parameter.

    \li Turn on Delay \n When an oncoming or preceding vehicle disappear a turn on delay timer is set.
        The high beam will be activated when this timer expired. There are different times for oncoming
        and preceding vehicles. The delay time is set in the HLAFDecision_FindRelevantVehicle() function
        in the hlaf_decision.c part.

    \li Turn on Delay for Truck Lights \n When the high beam is deactivated due to an oncoming vehicle
        delay and a truck light was detected, another delay for (potential) truck lights is set, which
        basically means that the oncoming delay gets extended.

    \li Turn on Delay for Slow Overtakers \n In case the ego vehicle is slowly overtaking a preceding
        vehicle the slow overtaker turn on delay is set. This is a coding parameter.

    \li Preceding Vehicle Lost \n When the light object of a preceding vehicle gets removed, the high
        beam will be kept off until the ego car reaches the position where the vehicle disappeared (only 
        up to 2s)

    \li Potential Vehicle \n The confidences of all the light objects are checked. If one of the
        confidences is above an internal threshold value the high beam will be kept off. Depending on
        other turn off reasons (oncoming, preceding) a delay time will be set, to keep the high beam off.

    There is a special logic implemented for Toyota AHS that only the keep off reasons for Minimum Time HB off and 
    Turn on Delays for oncoming, preceding and slow overtakers are kept. The others are removed. This needs to
    be activated by coding (bUseMinimumKOR is set to true) and the MaxNumGlarefreeArea must not be zero.
  
  \callsequence
    @startuml 
    title Sequence diagram of HLAFDecision_SetKeepOffReason()

    box "Function" #LightGreen
    participant hlaf.c       as Main
    participant hlaf_decision_keepoff.c    as this
    end box

    autonumber "<b>[00]"
    Main ->> this: ""**HLAF_EnvironmentDecisions()**"" calls\n""**HLAFDecision_SetKeepOffReason()**""
    Activate this
    this ->> this: Check for speed keep off reason
    this ->> this: Check for maybe city keep off reason\n calls HLAFDecSetKOR_MayBeCity()
    this ->> this: Check for small radius keep off reason\n calls HLAFDecSetKOR_SmallRadius()
    this ->> this: Check for min time high beam off keep off reason\n calls HLAFDecSetKOR_MinTimeHBoff()
    this ->> this: Check for turn on delay keep off reason\n calls HLAFDecSetKOR_TurnOnDelay()
    this ->> this: Check for turn on delay truck lights keep off reason\n calls HLAFDecSetKOR_TurnOnDelayTruckLights()
    this ->> this: Check for slow overtaker keep off reason\n calls HLAFDecSetKOR_TurnOnDelaySlowOvertaker()
    this ->> this: Check for preceding vehicle lost keep off reason\n calls HLAFDecSetKOR_PrecedingVehLost()
    this ->> this: Check for potential vehicle keep off reason\n calls HLAFDecSetKOR_PotentialVehicle()
    this ->> this: Remove some of the keep off reasons (if activated by coding)
    this -->> Main: void
    Deactivate this
    @enduml

  \testmethod
    Module test

  \traceability
***************************************************************************************************/
void HLAFDecision_SetKeepOffReason( const reqHlaPrtList_t*                 const pReqPorts,
                                    const HLAFData_t*                      const pFData,
                                    const t_DecisionParametersKeepOff*     const pParKeepOff,
                                    const t_DecisionParametersTurnOnDelay* const pParTurnOnDelay,
                                    const RTE_HLAF_HighBeamState                 eHighBeamStatePrev,
                                    const HLAFRelevantVehicle_t*           const pRelVeh,
                                    const HLAFTurnOffReason_t*             const pTurnOffReason,
                                          HLAFKeepOffReason_t*             const pKeepOffReason
                                   );

/* avoid cyclic binding -----------------------------------------------------*/
#endif /* #ifndef H_HLAF_DECISION_KEEPOFF_H */ 
