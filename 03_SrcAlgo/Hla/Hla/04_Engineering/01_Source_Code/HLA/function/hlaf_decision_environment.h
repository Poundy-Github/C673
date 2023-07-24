/*! @file ******************************************************************
  COMPANY:                Continental AG, BU ADAS, A.D.C. GmbH
 
  PROJECT:                MFC4xx

  COMPONENT:              HLA

  MODULNAME:              hlaf_decision_environment.h

  DESCRIPTION:            HLA decision on environment states.
                           - City
                           - Brightness
                           - ...

  CREATION DATE:          2014-11-03
    
  CPU:                    Independent

  VERSION:                $Revision: 1.12 $
**************************************************************************** */

/* avoid cyclic binding -----------------------------------------------------*/
#ifndef H_HLAF_DECISION_ENVIRONMENT_H
#define H_HLAF_DECISION_ENVIRONMENT_H

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
    Based on weather reported from camera blockage the visibility is deduced.
  
  \pre
    None

  \post
    None

  \param [in]      pCbOutputs         Pointer to blockage output
  \param [in]      pWiperStage        Pointer to wiper state
  \param [in]      pCamData           Pointer to camera data
  \param [in]      pWeatherData       Pointer to weather data
  \param [in,out]  peWeatherStateOut  Pointer to weather state output

  \return
    Void

  \globals
    None

  \InOutCorrelation
    The mapping is done in the following way:\n

    @startuml
    title Mapping of blockage states to weather state
    legend left
    Ideal mapping of blockage states to weather state

    | Weather Condition \ Visibility | Unkown Visibility Range | Clear Visibility Range | High Visibility Range | Medium Visibility Range | Low Visibility Range | Default         |
    | Heavy Fog                      | Weather Unkown          | Weather Good           | Weather Light Fog     | Weather Medium Fog      | Weather Heavy Fog    | Weather Invalid |
    | Fog                            | Weather Unkown          | Weather Good           | Weather Light Fog     | Weather Medium Fog      | Weather Heavy Fog    | Weather Invalid |
    | Heavy Rain / Snow              | Weather Unkown          | Weather Good           | Weather Good          | Weather Bad             | Weather Bad          | Weather Invalid |
    | Rain                           | Weather Unkown          | Weather Good           | Weather Good          | Weather Bad             | Weather Bad          | Weather Invalid |

    Current mapping since blockage is not providing visibility nor detecting heavy snow

    | Weather Condition     | Result            |
    | Heavy Fog             | Weather Heavy Fog |
    | Heavy Rain / --Snow-- | Weather Bad       |

    end legend

    @enduml

    In case of wiper stage > VEH_SIG_ADD_WIPER_STAGE1 (5) for more than 10 seconds, the weather state will also be set to Weather Bad. It will be reset if the wiper stage <= VEH_SIG_ADD_WIPER_STAGE1 (5) for more than 60 seconds.

  \callsequence
    @startuml 
    title Sequence diagram of HLAFDecisionEnv_Weather()

    box "Function" #LightGreen
    participant hlaf.c       as Main
    participant hlaf_decision_environment.c    as this
    end box

    autonumber "<b>[00]"
    Main ->> this: ""**HLAF_EnvironmentDecisions()**"" calls\n""**HLAFDecisionEnv_Weather()**""
    Activate this
    this ->> this: Update weather state based on blockage input or wiper stage
    this -->> Main: void
    Deactivate this
    @enduml
  
  \testmethod
    Module Test

  \traceability
***************************************************************************************************/
void HLAFDecisionEnv_Weather( const CB_t_ProvidedOutputs_t* const pCbOutputs,
                              const WiperStage_t*           const pWiperStage,
                              const HLAFCameraData_t*       const pCamData,
                                    HLAWeatherData_t*       const pWeatherData,
                                    RTE_HLAR_WeatherState*  const peWeatherStateOut
                            );
/** ************************************************************************************************
  \brief
    Set the scene info flag depending if an oncoming or preceding is leaving the ROI and no other
    vehicle is inside of the ROI
  
  \pre
    None

  \post
    None

  \param[in]      pFData                Pointer to HLA function data
  \param[in]      pSceneInfoParameters  Pointer to scene info parameters
  \param[in]      pOutNext              Pointer to output matrix structure
  \param[in]      pObjectList           Pointer to object list
  \param[in,out]  pSceneInfo            Pointer to scene info

  \return
    Void

  \globals
    None

  \InOutCorrelation
    The default output value is for the scene info is RTE_HLA_SCENEINFO_UNKNOWN. The turn off reason is
    checked and no oncoming and preceding shall be set.  Then the internal object list is checked. When
    the object is no longer in the HLA ROI (left or right area) and is closer than 100m for oncoming or
    50m for preceding the corresponding scene info flag is set.
    RTE_HLA_SCENEINFO_ONCOMING_PASSING for oncoming
    RTE_HLA_SCENEINFO_PRECEDING_OVERTAKING for preceding
    At the moment this logic is only relevant for the TA19 project.

    @startuml
    title Scene info decision
    
    start
    :Set Scene Info flag to unkown;
    if(Oncoming and Preceding turn off reason not set) then (Yes)
      :Check every object in internal object list;
      if(Object is oncoming \n Object is outside of ROI \n distance is closer than distanceOncoming) then (Yes)
        :set scene info to RTE_HLA_SCENEINFO_ONCOMING_PASSING;
      else if (Object is preceding \n Object is outside of ROI \n distance is closer than distancePreceding) then (Yes)
        :set scene info to RTE_HLA_SCENEINFO_PRECEDING_OVERTAKING;
      else (No)
      endif
    else (No)
    endif
    end
    @enduml

  \callsequence
    @startuml 
    title Sequence diagram of HLAFDecisionEnv_SceneInfo()

    box "Function" #LightGreen
    participant hlaf.c                         as Main
    participant hlaf_decision_environment.c    as this
    end box

    autonumber "<b>[00]"
    Main ->> this: ""**HLAF_SetLightStates()**"" calls\n""**HLAFDecisionEnv_SceneInfo()**""
    Activate this
    this ->> this: Update scene info flag
    this -->> Main: void
    Deactivate this
    @enduml
  
  \testmethod
    Module Test

  \traceability
***************************************************************************************************/
void HLAFDecisionEnv_SceneInfo( const HLAFData_t*                     const pFData,
                                const t_DecisionParametersSceneInfo*  const pSceneInfoParameters,
                                const HLAFMatrixOut_t*                const pOutNext,
                                const LSD_LightObjectList_t*          const pObjectList,
                                      RTE_HLA_SceneInfo*              const pSceneInfo
                              );
/** ************************************************************************************************
  \brief
    Decision of the internal city state.
  
  \pre
    City detection was executed

  \post
    None

  \param [in]      eCity         Enum that holds city state
  \param [in]      e_Brightness  Enum that holds brightness state
  \param [in]      pPar          Pointer to city parameters
  \param [in,out]  pFData        Pointer to store city history
  \param [in,out]  peCityOut     Pointer to city state output (enum)

  \return
    Void

  \globals
    None

  \InOutCorrelation
    Based on last state from city history the state machine kicks in \n
    
    a) CITY_IDLE, no city is present. If a city is reported and the ambient brightness is not NIGHT,
       city state changes to CITY_DETECTED. If a maybe_city is reported and the ambient brightness is
       not NIGHT, city state changes to CITY_MAYBE.\n
    b) CITY_MAYBE, a possible city is present, but not sure yet. If a city is reported and ambient
       brightness is not NIGHT, city state changes to CITY_DETECTED. If maybe_city is kept for more
       than a parameter based distance (currently 200 m), city state changes to CITY_MAYBE_WAIT4IDLE.
       If no city gets reported and thresholds for time and distance are met (currently 1 s and 50 m)
       and ambient brightness is not NIGHT or speed is high enough, city state changes to CITY_IDLE\n
    c) CITY_MAYBE_WAIT4IDLE, even though a city or no city gets reported, city state changes to
       CITY_IDLE\n
    d) CITY_DETECTED, if no city is reported and time and distance are above the according parameter
       based thresholds (currently 6 s and 100 m), ambient brightness is not night or speed is no turn
       off reason, algo counts and waits until city is far enough away (provided by dTurnOnDelay)\n

    @startuml
    title City decision state machine
    state City_Idle

    City_Idle --> City_Detected : CITY_DTCD
    City_Idle --> City_Maybe : CITY_MAYBE

    City_Maybe --> City_Detected : CITY_DTCD
    City_Maybe --> City_Maybe_Wait_For_Idle : CITY_NOT_DTCD
    City_Maybe --> City_Idle : CITY_NOT_DTCD

    City_Maybe_Wait_For_Idle --> City_Idle : CITY_NOT_DTCD

    City_Detected --> City_Idle : CITY_NOT_DTCD

    City_Last --> City_Idle : CITY_NOT_DTCD

    @enduml

    @startuml
    title City Idle
    
    start
    :Initialize internal city time and distance counters;
    if(City is detected and\nBrightness state is night) then (Yes)
      :Go to City_Detected;
      : City output: Detected;
    elseif( City maybe detected and\nBrightness state is night) then (Yes)
      :Go to City_Maybe;
      :City output: Maybe;
    else(No)
    endif
    end
    
    @enduml

    @startuml
    title City Maybe
    
    start
    :Increase time and distance counters;
    if(City is detected and\nBrightness state is night) then (Yes)
      :Go to City_Detected;
      :Decision output: City detected;
      : Reset time and distance counters;
    elseif(City maybe detected) then (Yes)
      if(Distance counter is above internal threshold) then (Yes)
        :Go to City_Maybe_Wait_For_Idle;
        :Decision output: City not detected;
      else(No)
      endif
    elseif(City not detected and\nDistance and Time counters above internal thresholds and\nBrightness state is night or Speed is above minSpeed) then (Yes)
      :Go to City_Idle;
      :Decision output: City not detected;
    else(No)
    endif
    end
    
    @enduml

    @startuml
    title City Maybe Wait For Idle
    
    start
    if(City not detected or City detected) then (Yes)
      :Go to City Idle;
      :Decision output: City not detected;
    else(No)
    endif
    end
    
    @enduml

    @startuml
    title City Detected
    
    start
    if(City not detected and\nTime and distance counters above internal thresholds and\nBrightness state is night or Speed is above minSpeed) then (Yes)
      :Go to City Idle;
      :Decision output: City not detected;
      :Increase distance outside city counter;
    else(No)
      :Reset distance outside city counter;
    endif
    :Increase distance and time counter;
    
    end
    
    @enduml

    @startuml
    title City Last

    start
    :Go to City Idle;
    :Decision output: City not detected;
    end

    @enduml

  \callsequence
    @startuml 
    title Sequence diagram of HLAFDecisionEnv_City()

    box "Function" #LightGreen
    participant hlaf.c       as Main
    participant hlaf_decision_environment.c    as this
    end box

    autonumber "<b>[00]"
    Main ->> this: ""**HLAF_EnvironmentDecisions()**"" calls\n""**HLAFDecisionEnv_City()**""
    Activate this
    this ->> this: Update city state based on city detection input
    this -->> Main: void
    Deactivate this
    @enduml
  
  \testmethod
    Module Test

  \traceability
***************************************************************************************************/
void HLAFDecisionEnv_City( const LSD_e_EnvironmentData_CityState              eCity,
                           const LSD_e_EnvironmentData_BrightnessState        e_Brightness,
                           const t_DecisionParametersCity*              const pPar,
                                 HLAFData_t*                            const pFData,
                                 RTE_HLAR_CityState*                    const peCityOut
                         );
/** ************************************************************************************************
  \brief
    Tests the current speed and motion state against various parameter based thresholds to determine
    if HLA is allowed to operate.
  
  \pre
    None

  \post
    None

  \param [in]      pVehDyn    Pointer to vehicle dynamic data
  \param [in]      pVehSig    Pointer to vehicle signals like raw yaw rate, steering wheel angle
  \param [in]      pRTEPar    Pointer to speed parameters (RTE)
  \param [in]      dT         Float that holds the timer decrement
  \param [in,out]  pDat       Pointer to store speed output
  \param [in]      numRelObj  Number of relevant objects

  \return
    Void

  \globals
    None

  \InOutCorrelation
    @startuml
    title Speed Decision
    
    start
    if(Display speed is above always activate speed and\nMotion state is forward) then (Yes)
      :Internal speed state: Always active;
    else if(Display speed is above activate speed and\nMotion state is forward) then (Yes)
      if(Internal speed state is low)
        if(Any keep off bit set)
          :Set penalty timer to keep off delay;
        else(No)
          :Reset penalty timer;
        endif
      else(No)
      endif
      :Internal speed state: High;
    elseif(Display speed is equal or below deactivation speed or\nMotion state is not forward) then (Yes)
      :Internal speed state: Low;
    else(No)
    endif
    
    if(Internal speed state is Low) then (Yes)
      :Set VerySlow Keep Off Bit if display speed\n is below keep off very low coding parameter;
      :Set RecentVehicleDetection Keep Off Bit\n if there is at least one relevant object;
      :Set High Curvature Keep Off Bit\n if radius is below codeable paramter;
      :Set High Acceleration Keep Off Bit if acceleration is above\n codeable paramter and display speed is bigger than 1;
      :Set Disable HLA by Speed flag;
    elseif(Internal speed state is High) then (Yes)
      :Decrease penatly timer;
      if(Penalty timer is below zero) then (Yes)
        :Unset Disable HLA by Speed flag;
        :Remove keep off events;
      else(No)
         :reset timer when acceleration indicates\n that velocity will fall below activation speed;
      endif
    else(No)
      :Unset Disable HLA by Speed flag;
      :Remove keep off events;
    endif
    
    if(acceleration indicates that velocity will fall below activation speed) then (Yes)
      :Set keep off HLA by Speed flag;
    else(No)
      :Unset keep off HLA by Speed flag;
    endif
    
    if(Display speed is above high speed deactivation threshold AND vehicle is moving forward) then (Yes)
      :Set Disable HLA by High Speed flag;
    elseif(Display speed is below high speed activation threshold) then (Yes)
      :Unset Disable HLA by High Speed flag;
    else(No)
    endif
    end
    @enduml

  \callsequence
    @startuml 
    title Sequence diagram of HLAFDecisionEnv_Speed()

    box "Function" #LightGreen
    participant hlaf.c       as Main
    participant hlaf_decision_environment.c    as this
    end box

    autonumber "<b>[00]"
    Main ->> this: ""**HLAF_EnvironmentDecisions()**"" calls\n""**HLAFDecisionEnv_Speed()**""
    Activate this
    this ->> this: Update speed state based on vdy input
    this -->> Main: void
    Deactivate this
    @enduml
  
  \testmethod
    Module Test

  \traceability
***************************************************************************************************/
void HLAFDecisionEnv_Speed( const VehDyn_t*                   const pVehDyn,
                            const VehSig_t*                   const pVehSig,
                            const RTE_HLAF_ParameterSpeed_t*  const pRTEPar,
                            const float32                           dT,
                                  HLAFSpeed_t*                const pDat
                          );
/* avoid cyclic binding -----------------------------------------------------*/
#endif /* #ifndef H_HLAF_DECISION_ENVIRONMENT_H */ 
