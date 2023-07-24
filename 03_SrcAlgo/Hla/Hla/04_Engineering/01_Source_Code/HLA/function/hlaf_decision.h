/*! @file ******************************************************************
  COMPANY:                Continental AG, BU ADAS, A.D.C. GmbH
 
  PROJECT:                MFC4xx

  COMPONENT:              HLA

  MODULNAME:              hlaf_decision.h

  DESCRIPTION:            HLA decision. This module makes some "pre" decisions.
                          The HLAR outputs will be analysed for the hla light,
                          standard and plus function.
                          e.g.:
                          - brightness analysis (dark enough for high beams ?)  
                          - state machine for highway, city, tunnel detection
                          ...

  CREATION DATE:          2011-02-23
  
  CPU:                    Independent

  VERSION:                $Revision: 1.13.1.2 $
**************************************************************************** */

/* avoid cyclic binding -----------------------------------------------------*/
#ifndef H_HLAF_DECISION_H
#define H_HLAF_DECISION_H

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
    Depending on HLAF internal data the global turn off reasons are set. If no reason is
    present the timer will be reset otherwise the time will be increased by forward_time\n

    Global turn off reasons are:
    \li Speed is not sufficient
    \li City is detected
    \li Tunnel is detected
    \li Brightness is too high
    \li Clearance measurement is ongoing
    \li Blockage is detected
    \li Fog is detected
    \li Bad weather is detected
  
  \pre
    None

  \post
    None

  \param [in]      e_Brightness         Enum that holds brightness state
  \param [in]      pReqPorts            Pointer to algo input ports
  \param [in]      pFData               Pointer to HLA function data
  \param [in,out]  pTurnOffReason       Pointer to store turn off reasons

  \return
    None

  \globals
    None

  \InOutCorrelation
    @startuml
    title Mapping of internal data to turn off reason
    legend left
    Mapping of internal data to turn off reason

    |  | Internal Data | Turn Off Reason|
    | Speed is not sufficient | disableHLABySpeed in Decision Data is set | MinSpeed |
    | Speed is too high | disableHLAByHighSpeed in Decision Data is set | MaxSpeed |
    | City is detected | eCityState in DecisionOut is set to city detected | City |
    | Tunnel is detected | eTunnelState in DecisionOut is set to inside | Tunnel |
    | Brightness is too high | e_Brightness is not set to night\n Test mode is not set to Lab enhanced | Brightness |
    | Clearance measurement is ongoing | eBlockageState in DecisionData is set to clearance measurement\n Test mode is not set to no clearance measurement | NotReleased |
    | Blockage is detected | eBlockageState in DecisionData is set to blockage\n Test mode is not set to no clearance measurement | Blockage |
    | Fog is detected | eWeatherState in DecisionOut is set to heavy fog\n Fog detection active | Fog |
    | Bad Weather is detected | eWeatherState in DecisionOut is set to heavy fog, medium fog or weather bad\n Bad weather detection active | Bad Weather |

    end legend

    @enduml

  \callsequence
    @startuml 
    title Sequence diagram of HLAFDecision_SetTurnOffReasonGlob()

    box "Function" #LightGreen
    participant hlaf.c       as Main
    participant hlaf_decision.c    as this
    end box

    autonumber "<b>[00]"
    Main ->> this: ""**HLAF_EnvironmentDecisions()**"" calls\n""**HLAFDecision_SetTurnOffReasonGlob()**""
    Activate this
    this ->> this: Set turn off reason bit depending on decision data
    this -->> Main: void
    Deactivate this
    @enduml

  \testmethod
    Module Test

  \traceability
***************************************************************************************************/
void HLAFDecision_SetTurnOffReasonGlob( const RTE_HLAR_BrightnessState       e_Brightness,
                                        const reqHlaPrtList_t*         const pReqPorts,
                                        const HLAFData_t*              const pFData,
                                              HLAFTurnOffReason_t*     const pTurnOffReason
                                      );

/** ************************************************************************************************
  \brief
    Loops over all relevant objects and decides if each could be a relevant vehicle for a high beam turn off.
    If the relevant  vehicle fulfills the time-to-border constraints the output structure will be filled with its
    data. Since EM object list is not mandatory, input checks are performed in this function\n

  \pre
    None

  \post
    None

  \param [in]   pReqPorts            Pointer to request port list
  \param [in]   pFData               Pointer to HLA function data
  \param [in]   pDecisionParameters  Pointer to decision parameters
  \param [in]   pObjectList          Pointer to object list
  \param [out]  pRelVeh              Pointer that holds detected relevant vehicle

  \return
    Void

  \globals
    None

  \InOutCorrelation
    Two special scenarios are included here, that can be deactivated via coding. 
    
    \li In HLAFDecision_RelevantVehicle2TurnOff() function the China mode (which was developed for the
    Hyundai project) is realized. When the high beam is off and an oncoming vehicle is within a codeable
    distance threshold it is relevant, but if it is too far away, it becomes no longer relevant. When the
    high beam is on and the oncoming or the preceding vehicles are within a code able distance they are 
    relevant, otherwise they are not relevant. When setting the distance thresholds to a high value this
    logic becomes inactive.\n

    \li In the HLAFDecision_CheckTurnOffDelay() function a turn off delay is introduced. Even when there
    was a relevant object detected, it should be waited for a code able time before the high beam will be
    turned off. When setting the time thresholds to zero this logic becomes deactivated.\n

    @startuml
    title Find relevant vehicle

    start
    :Check if vehicles are relevant for a turn off;
    if(Vehicle is relevant) then (Yes)
      :Calculate turn on delay;
    else(No)
    endif
    :Check for turn off delay;
    :Update internal states;
    end

    @enduml

    Details how the relevant vehicle decision works:

    \image html HlaDecisionRelevantVehicleToTurnOff.png

    Details how decision for the turn off delay works:

    \image html HLAFDecision_CheckTurnOffDelay.png
    
  \callsequence
    @startuml 
    title Sequence diagram of HLAFDecision_FindRelevantVehicle()

    box "Function" #LightGreen
    participant hlaf.c       as Main
    participant hlaf_decision.c    as this
    end box

    autonumber "<b>[00]"
    Main ->> this: ""**HLAF_SetLightStates()**"" calls\n""**HLAFDecision_FindRelevantVehicle()**""
    Activate this
    this ->> this: Check every light object if it is a relevant vehicle
    opt Light object is relevant
    this ->> this: Calculate turn on delay for object
    end
    this ->> this: Check turn off delay for oncoming vehicle
    this ->> this: Check turn off delay for preceding vehicle
    this -->> Main: void
    Deactivate this
    @enduml


  
  \testmethod
    Module Test

  \traceability
***************************************************************************************************/
void HLAFDecision_FindRelevantVehicle( const reqHlaPrtList_t*       const pReqPorts,
                                             HLAFRelevantVehicle_t* const pRelVeh
                                     );
/** ************************************************************************************************
  \brief
    Find relevant vehicles in EM object list.

  \pre
    None

  \post
    None

  \param [in]   pData    Pointer matrix data
  \param [out]  pRelVeh  Pointer that holds detected relevant vehicle

  \return
    Void

  \globals
    None

  \InOutCorrelation
    When relevant EM objects are added to the internal object list the bEMObjOncDetected flag
    is set to true in case of an oncoming. In case of a preceding the bEMObjPrecDetected is set
    to true.

    @startuml
    title Check for relevant EM objects
    
    start
    :set bEMObjOncDetected and bEMObjPrecDetected to false;
    :check every EM object in internal object list;
    if (EMObjID is not UI8_T_MAX) then (True)
      if (objectType is Oncoming) then (True)
        :set bEMObjOncDetected to true;
      else (False)
      endif
      if (objectType is Preceding) then (True)
        :set bEMObjPrecDetected to true;
      else (False)
      endif
    else(False)
    endif
    end
    
    @enduml

  \callsequence
    @startuml 
    title Sequence diagram of HLAFDecision_CheckEMObjectList()

    box "Function" #LightGreen
    participant hlaf.c       as Main
    participant hlaf_decision.c    as this
    end box

    autonumber "<b>[00]"
    Main ->> this: ""**HLAF_SetLightStates()**"" calls\n""**HLAFDecision_CheckEMObjectList()**""
    Activate this
    this ->> this: Check if relevant EM object was detected
    this -->> Main: void
    Deactivate this
    @enduml
  
  \testmethod
    Module Test

  \traceability
***************************************************************************************************/
void HLAFDecision_CheckEMObjectList( const HLAFMatrixData_t*      const pData,
                                           HLAFRelevantVehicle_t* const pRelVeh
                                   );

/** ************************************************************************************************
  \brief
    Depending on the found vehicle the corresponding turn off reason bit is set

  \pre
    Function relevant vehicles (oncoming, preceding, EM objects) were found

  \post
    None

  \param [in]      pRelVeh         Pointer to relevant vehicle
  \param [in,out]  pTurnOffReason  Pointer to store turn off reasons

  \return
    Void

  \globals
    None

  \InOutCorrelation
    Set turn off reason related to detected vehicle, which means oncoming, preceding car or a relevant
    EM or radar object is in the frame. The corresponding reason bit in the HLAFTurnOffReason_t struct is
    set.

    @startuml
    title Set Turn Off Reason
    
    start
    if (Oncoming detected) then (Yes)
      :Set  oncoming reason bit;
    else(No)
    endif
    
    if(Preceding detected) then (Yes)
      :Set  preceding reason bit;
    else(No)
    endif
    
    if(Oncoming EM object detected) then (Yes)
      :Set oncoming EM object reason bit;
    else(No)
    endif
    
    if(Preceding EM object detected) then (Yes)
      :Set preceding EM object reason bit;
    else(No)
    endif
    
    if(radar object detected) then (Yes)
      :Set  radar object reason bit;
    else(No)
    endif
    end
    
    @enduml

  \callsequence
    @startuml 
    title Sequence diagram of HLAFDecision_SetTurnOffReason()

    box "Function" #LightGreen
    participant hlaf.c           as Main
    participant hlaf_decision.c  as this
    end box

    autonumber "<b>[00]"
    Main ->> this: ""**HLAF_SetLightStates()**"" calls\n""**HLAFDecision_SetTurnOffReason()**""
    Activate this
    this ->> this: Set turn off for oncoming if oncoming was detected
    this ->> this: Set turn off for preceding if preceding was detected
    this ->> this: Set turn off for EM object if EM object was detected
    this -->> Main: void
    Deactivate this
    @enduml
  
  \testmethod
    Module Test

  \traceability
***************************************************************************************************/
void HLAFDecision_SetTurnOffReason( const HLAFRelevantVehicle_t* const pRelVeh,
                                          HLAFTurnOffReason_t*   const pTurnOffReason
                                  );
/** ************************************************************************************************
  \brief
    Depending on the found turn off reasons the high beam state will be set

  \pre
    Check for turn off reasons was performed

  \post
    None

  \param [in]      pTurnOffReason       Pointer to turn off reasons
  \param [in]      pKeepOffReason       Pointer to keep off reasons
  \param [in]      eHighBeamStatePrev   Enum that holds the previous high beam state
  \param [in,out]  peHighBeamStateOut   Pointer to enum to store new high beam state

  \return
    Void

  \globals
    None

  \InOutCorrelation
    If any global reason is present, the high beam will turn off.\n
    If any vehicle based reason is present, the high beam will turn off.\n
    If the high beam was off and there is a keep off reason present, the high beam will stay off.\n

    @startuml
    title Set high beam state

    start
    if (No global turn off reason set) then (Yes)
    if(Previous high beam state is on) then (Yes)
    if(Vehicle related turn off reason set) then (Yes)
    :Set high beam state to off;
    else(No)
    :Set high beam state to on;
    endif
    else(No)
    if(No vehicle related turn off reason set and\nNo keep off reson set) then (Yes)
    :Set high beam state to on;
    else(No)
    :Set high beam state to off;
    endif
    endif
    else(No)
    :Set high beam state to off;
    endif
    end
    @enduml

  \callsequence
    @startuml 
    title Sequence diagram of HLAFDecision_SetHBState()

    box "Function" #LightGreen
    participant hlaf.c       as Main
    participant hlaf_decision.c    as this
    end box

    autonumber "<b>[00]"
    Main ->> this: ""**HLAF_SetLightStates()**"" calls\n""**HLAFDecision_SetHBState()**""
    Activate this
    this ->> this: Set high beam state on basis of turn/keep off reason and previous high beam state
    this -->> Main: void
    Deactivate this
    @enduml
  
  \testmethod
    Module Test

  \traceability
***************************************************************************************************/
void HLAFDecision_SetHBState(
#ifdef HLA_CHANGAN_CURVE_FEATURE
                              const HLAFVehData_t*          const pVehData,
#endif
                              const HLAFTurnOffReason_t*    const pTurnOffReason,
                              const HLAFKeepOffReason_t*    const pKeepOffReason,
                              const RTE_HLAF_HighBeamState        eHighBeamStatePrev,
                                    RTE_HLAF_HighBeamState* const peHighBeamStateOut
                            );

/* avoid cyclic binding -----------------------------------------------------*/
#endif /* #fndef __HLAF_DECISION_H */
