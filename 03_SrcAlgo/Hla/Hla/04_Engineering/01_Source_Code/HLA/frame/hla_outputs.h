/*! @file ******************************************************************
  COMPANY:                Continental AG, BU ADAS, A.D.C. GmbH
 
  PROJECT:                MFC4xx

  COMPONENT:              HLA

  MODULNAME:              hla_outputs.h

  DESCRIPTION:            Headlight assist output.

  CREATION DATE:          2014-01-20
  
  CPU:                    Independent

  VERSION:                $Revision: 1.4 $
**************************************************************************** */

/* avoid cyclic binding -----------------------------------------------------*/
#ifndef H_HLA_OUTPUTS_H
#define H_HLA_OUTPUTS_H

/*****************************************************************************
  INCLUDES
*****************************************************************************/
#include "hla_defs.h"

/*****************************************************************************
  SYMBOLIC CONSTANTS 
*****************************************************************************/
 

/*****************************************************************************
  TYPEDEFS 
*****************************************************************************/

/*****************************************************************************
  GLOBAL FUNCTIONS (DECLARATION)
*****************************************************************************/
#ifdef __cplusplus
extern "C" {
#endif
/** ************************************************************************************************
  \brief
    Filles the provide ports with defined data.
  
  \pre
    None

  \post
    Comp state and headlight control are filled with defined values

  \param [in]   compState           Algo comp state.
  \param [in]   errorCode           Component return error code.
  \param [in]   algoQualifier       Component qualifier.
  \param [in]   sigState            Signal state for all signal headers.
  \param [in]   timeStamp           Current timestamp for all signal headers.
  \param [in]   measurementCounter  Current measurement counter for all signal headers.
  \param [in]   cycleCounter        Current cycle counter for all signal headers.
  \param [out]  pHlaSyncRef         Pointer to sync ref struct
  \param [out]  pProPorts           Pointer to provide port list

  \return
    Void

  \globals
    None

  \InOutCorrelation
    The following data of the algo comp state is set. The version number from the RTE, signal status
    is set to ok, cycle counter, measurement counter timestamp, comp sate, error code and algo qualifier
    are used from input, algo version number from hla_ver.h, application number and algo version info
    from hla_project_defs.h, ShedulerSubModeRequest is set to none.\n
    pHlaf_HeadlightControl is memset to zero. Then version number from RTE is used and signal status,
    cycle counter, measurement counter and timestamp from input are used.\n
    The signal header from the HLA sync ref is filled with the signal status, cycle counter, measurement
    counter and timestamp from the input.

  \callsequence
    @startuml 
    title Sequence diagram of HLA_SetOutputDefaults()

    box "Main" #LightBlue
    participant hla_main.c     as Main
    participant hla_outputs.c  as this
    end box

    autonumber "<b>[00]"
    Main ->> this: ""**HLA_OpModeDemo()/HLA_OpModeError()/HLA_OpModeIdel()/HLA_OpModeReset()/HLA_OpModeRun()**"" calls\n""**HLA_OutputChecks()**""
    Activate this
    this ->> this: Default values are set
    this -->> Main: void
    Deactivate this
    @enduml

  
  \testmethod
    Module Test

  \traceability
***************************************************************************************************/
void HLA_SetOutputDefaults( const CompState_t               compState,
                            const CompErrorCode_t           errorCode,
                            const GenAlgoQualifiers_t       algoQualifier,
                            const AlgoSignalState_t         sigState,
                            const AlgoDataTimeStamp_t       timeStamp,
                            const AlgoCycleCounter_t        measurementCounter,
                            const AlgoCycleCounter_t        cycleCounter,
                                  Hla_SyncRef_t*      const pHlaSyncRef,
                                  proHlaPrtList_t*    const pProPorts
                           ); 

#ifdef __cplusplus
 }
#endif
/** ************************************************************************************************
  \brief
    Random data for headlight control provide port for demonstration reasons.
  
  \pre
    None

  \post
    None

  \param [out]  pProPorts  Pointer to provide port list

  \return
    Void

  \globals
    None

  \InOutCorrelation
    For headlight control provide port random data overwrites default data. This is just for functionality
    demonstration during testing, for instance. Signals in the pHlaf_HeadlightControl struct are
    filled with the following values:

    \li GFA status is set to valid
    \li High beam state is set to partial
    \li low beam angle to C_HALFPI
    \li low beam dist to 42
    \li low beam status to unknown
    \li number of GFAs to 1
    \li Turn off reason to 1
    \li BndryLeft_Ang is set to C_HALFPI
    \li BndryLeft_Ang_Cam is set to CML_f_Pi / 4
    \li BndryLeft_Dist is set to 42
    \li BndryLeft_Status is set to RTE_HLAF_OBJSTA_UNKNOWN_OBJ
    \li BndryLeft_ObjId is set to 0u
    \li BndryLeft_DistState is set to RTE_HLAF_DISTSTATE_PAIRLIGHT
    \li BndryLower_Ang_Cam is set to 1.3f
    \li BndryLower_Status is set to RTE_HLAF_OBJSTA_UNKNOWN_OBJ
    \li BndryLower_ObjId is set to 1u
    \li BndryLower_DistState is set to RTE_HLAF_DISTSTATE_SINGLELIGHT
    \li BndryRight_Ang is set to -(C_HALFPI)
    \li BndryRight_Ang_Cam is set to -(CML_f_Pi / 4)
    \li BndryRight_Dist is set to 42
    \li BndryRight_Status is set to RTE_HLAF_OBJSTA_UNKNOWN_OBJ
    \li BndryRight_ObjId is set to 2u
    \li BndryRight_DistState is set to RTE_HLAF_DISTSTATE_PAIRLIGHT
    \li ClosestObj_Ang is set to 1.5f
    \li ClosestObj_Dist is set to 42
    \li ClosestObj_Status is set to RTE_HLAF_OBJSTA_UNKNOWN_OBJ
    \li ClosestObj_ObjId is set to 3u
    \li ClosestObj_DistState is set to RTE_HLAF_DISTSTATE_PAIRLIGHT
    \li ExistenceProb is set to 21
    \li MinLight_Ang is set to 1.25f
    \li MinLight_Dist is set to 42
    \li MinLight_Status is set to RTE_HLAF_OBJSTA_UNKNOWN_OBJ
    \li ttb18Left is set to 1
    \li ttb18Left_Status is set to RTE_HLAF_TTBSTA_DIR_LEFT
    \li ttb18Right is set to 1
    \li ttb18Right_Status is set to RTE_HLAF_TTBSTA_DIR_RIGHT
    \li all dimming areas are set to RTE_HLAF_DIMM_LEVEL_NO_REDUCT
    \li dimming status is set to RTE_HLAF_DIMM_STATE_AVL

  \callsequence
    @startuml 
    title Sequence diagram of HLA_SetOutputDemo()

    box "Main" #LightBlue
    participant hla_main.c       as Main
    participant hla_outputs.c    as this
    end box

    autonumber "<b>[00]"
    Main ->> this: ""**HLA_OpModeDemo()**"" calls\n""**HLA_SetOutputDemo()**""
    Activate this
    this ->> this: Demonstration values are set in headlight control struct
    this -->> Main: void
    Deactivate this
    @enduml

  \testmethod
    Module Test

  \traceability
***************************************************************************************************/
void HLA_SetOutputDemo( proHlaPrtList_t* const pProPorts );

/* avoid cyclic binding -----------------------------------------------------*/
#endif /* #ifndef H_HLA_OUTPUTS_H */
