/*! @file ******************************************************************
  COMPANY:                Continental AG, BU ADAS, A.D.C. GmbH
 
  PROJECT:                MFC4xx

  COMPONENT:              HLA

  MODULNAME:              hla_output_checks.h

  DESCRIPTION:            Headlight assist output checks.

  CREATION DATE:          2016-10-01
  
  CPU:                    Independent

  VERSION:                $Revision: 1.4 $
**************************************************************************** */

/* avoid cyclic binding -----------------------------------------------------*/
#ifndef H_HLA_OUTPUT_CHECKS_H
#define H_HLA_OUTPUT_CHECKS_H

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
/** ************************************************************************************************
  \brief
    Checks all outputs of HLA if they are in valid ranges.
  
  \pre
    Algo was executed, output data was filled in corresponding algo parts.

  \post
    If a check failed a error or warning is stored in the global error stack variable.

  \param [in,out]  pProPorts  Pointer to provide ports

  \return
    Void

  \globals
    Warnings and errors are stored in global error stack variable

  \InOutCorrelation
    The values of the following two output ports
    are checked:\n
    \li pAlgoCompState
    \li pHlaf_HeadlightControl

    The algo comp state is only checked if the signal status is not set to invalid. The following checks
    are performed:

    \li Version number must match the COMP_STATE_INTFVER
    \li eSigStatus needs to be a state from the RTE definitions
    \li eCompState needs to be a state from the RTE definitions
    \li eShedulerSubModeRequest needs to be a state from the RTE definitions
    \li no higher bit then ALGO_QUAL_CALIBRATION_RUNNING is allowed to be set in the eGenAlgoQualifier

    pHlaf_HeadlightControl is always checked. The following checks are performed:

    \li eSigStatus needs to be a state from the RTE definitions --> leads to error
    \li TrafficStyle needs to be a state from the RTE definitions
    \li SensMode needs to be a state from the RTE definitions
    \li SpeedState needs to be a state from the RTE definitions
    \li For every GFA the following signals are checked
    - BndryLeft_Ang must be between -20 ... 20
    - BndryLeft_Dist must be between 0 ...450
    - BndryLeft_Ang_Cam must be between -20 ... 20
    - BndryLeft_ObjId must not exceed LSD_LIGHT_OBJECT_LIST_LENGTH --> leads to error
    - BndryRight_Ang must be between -20 ... 20
    - BndryRight_Dist must be between 0 ...450
    - BndryRight_Ang_Cam must be between -20 ... 20
    - BndryRight_ObjId must not exceed LSD_LIGHT_OBJECT_LIST_LENGTH --> leads to error
    - BndryLower_Ang_Cam must be between -5 ... 5
    - BndryLower_ObjId must not exceed LSD_LIGHT_OBJECT_LIST_LENGTH --> leads to error
    - BndryUpper_Ang_Cam must be between -10 ... 5
    - BndryUpper_ObjId must not exceed LSD_LIGHT_OBJECT_LIST_LENGTH --> leads to error
    - ClosestObj_Dist must be between 0 ...450
    - ClosestObj_Ang must be between -20 ... 20
    - ClosestObj_ObjId must not exceed LSD_LIGHT_OBJECT_LIST_LENGTH --> leads to error
    - MinLight_Dist must be between 0 ...450
    - MinLight_Ang must be between -20 ... 20
    - MinLight_ObjId must not exceed LSD_LIGHT_OBJECT_LIST_LENGTH --> leads to error
    - ttb18Left must be between 0 ... 10
    - ttb18Right must be between 0 ... 10
    - ExistenceProb must not exceed 100
    - ttb18Right_Status needs to be a state from the RTE definitions
    - ttb18Left_Status needs to be a state from the RTE definitions
    - MinLight_DistState needs to be a state from the RTE definitions
    - MinLight_Status needs to be a state from the RTE definitions
    - ClosestObj_DistState needs to be a state from the RTE definitions
    - ClosestObj_Status needs to be a state from the RTE definitions
    - BndryUpper_DistState needs to be a state from the RTE definitions
    - BndryUpper_Status needs to be a state from the RTE definitions
    - BndryLower_DistState needs to be a state from the RTE definitions
    - BndryLower_Status needs to be a state from the RTE definitions
    - BndryRight_DistState needs to be a state from the RTE definitions
    - BndryRight_Status needs to be a state from the RTE definitions
    - BndryLeft_DistState needs to be a state from the RTE definitions
    - BndryLeft_Status needs to be a state from the RTE definitions
    \li nGFA must not exceed RTE_HLAF_MATRIX_MAX_NUM_GLARE_FREE_AREAS
    \li GFAStatus needs to be a state from the RTE definitions
    \li HighBeamState needs to be a state from the RTE definitions
    \li LowBeam_Dist must be between 0 ... 600
    \li LowBeam_Ang must be between -20 ... 20
    \li LowBeam_Status needs to be a state from the RTE definitions
    \li TurnOffReason needs to be a state from the RTE definitions
    \li DimmingStatus
    \li For every dimming area the following signals are checked
    - DimmingArea needs to be a state from the RTE definitions

    In case of an error the signal status is set to invalid.

  \callsequence
    @startuml 
    title Sequence diagram of HLA_OutputChecks()
    
    box "Main" #LightBlue
    participant hla_main.c           as Main
    participant hla_output_checks.c  as this
    end box
                      
    autonumber "<b>[00]"
    Main ->> this: <b><<HLA_OpModeRun()>> calls\n<b> <<HLA_OutputChecks()>>
    Activate this
    opt sigstatus of algo comp state is not invalid
      this ->> this: <b>Check comp state
    end
    this ->> this: <b>Check headlight control struct
    this -->> Main: <b>void
    Deactivate this
    @enduml
  
  \testmethod
    Module Test

  \traceability
***************************************************************************************************/
void HLA_OutputChecks(proHlaPrtList_t* const pProPorts);


/* avoid cyclic binding -----------------------------------------------------*/
#endif /* #ifndef H_HLA_OUTPUT_CHECKS_H */
