/*! @file ******************************************************************
  COMPANY:                Continental AG, BU ADAS, A.D.C. GmbH
 
  PROJECT:                MFC4xx
 
  COMPONENT:              HLA
 
  FILENAME:               hla_utils.h
 
  DESCRIPTION:            Collection of commonly used utilities like ...
                          ... trigonometric functions
                          ... other mathematical functions
                          ... time measurement
 
  CREATION DATE:          2014-05-28
 
  CPU:                    Independent
 
  VERSION:                $Revision: 1.8 $
**************************************************************************** */

/* avoid cyclic binding -----------------------------------------------------*/
#ifndef H_HLA_UTILS_H
#define H_HLA_UTILS_H

/*****************************************************************************
  INCLUDES
*****************************************************************************/
#include "hla_defs.h"


/*****************************************************************************
  SYMBOLIC CONSTANTS 
*****************************************************************************/


/*****************************************************************************
  MACROS 
*****************************************************************************/


/*****************************************************************************
  TYPEDEFS 
*****************************************************************************/



/*****************************************************************************
  VARIABLES 
*****************************************************************************/


/*****************************************************************************
  FUNCTION 
*****************************************************************************/
#ifdef HLA_TIME_MEAS_DETAILED
void HLAUtilsRegisterRtaService(const AS_t_RTAAlgoServiceAddEvent rtaServiceFunction);
#endif /* #ifdef HLA_TIME_MEAS_DETAILED */
/** ************************************************************************************************
  \brief
    Adds an RTA event to RTE buffer via corresponding service function.

  \pre
    None

  \post
    None

  \param[in]  RtaEvtType  Type of RTA event, e.g. start or stop event
  \param[in]  IdGlobal    Global ID, i.e. component ID
  \param[in]  IdLocal     Local ID, i.e. event specific ID
  \param[in]  OptData     Additional debug data

  \return
    void

  \globals
    RTA Service Function at \c HlaUtilsRtaServiceFunction will be accessed

  \InOutCorrelation
    In case the RTA service function is available it gets called, with the RTA event, global and
    local ID and optional data. his approach is chosen to avoid many ifdef HLA_TIME_MEAS_DETAILED
    in the code.

  \callsequence
    @startuml 
    title Sequence diagram of HLAUtilsAddDetailedRtaEvent()

    box "Function" #LightGreen
    participant hlaf.c       as Main
    participant hla_utils.c    as this
    end box

    autonumber "<b>[00]"
    Main ->> this: ""**HLAF_v_Exec()\HLAF_v_Init()**"" calls\n""**HLAUtilsAddDetailedRtaEvent()**""
    Activate this
    opt time measurement function available
    this ->> this: Add RTA event
    end
    this -->> Main: void
    Deactivate this
    @enduml

  
  \testmethod
    Module test

  \traceability
***************************************************************************************************/
void HLAUtilsAddDetailedRtaEvent( const AS_t_RtaEventType RtaEvtType,
                                  const uint8             IdGlobal,
                                  const uint8             IdLocal,
                                  const uint8             OptData
                                 );

/** ************************************************************************************************
  \brief
    Checks whether a floating point number is not-a-number - platform independent.

  \pre
    None

  \post
    None

  \param[in]  x       floating point number

  \return
    \c b_TRUE in case bit pattern of \c x represents a valid floating point number.
    \c b_FALSE in all other cases.

  \globals
    None

  \InOutCorrelation
    Using platform specific implementation of not-a-number (NAN) check. 

  \callsequence
    @startuml 
      title Sequence diagram of HLAUtilsIsNAN()
      
      box "Function" #LightGreen
      participant hla_input_checks.c  as InputChecks
      participant hla_utils.c         as this
      end box
      
      autonumber "<b>[00]"
      InputChecks ->> this: ""**HLA_InputChecks_CriticalInputData()**"" calls\n""**HLAUtilsIsNAN()**""
      Activate this
        this ->> this: Calls platform specific\n version of NAN check
        this -->> InputChecks: boolean
      Deactivate this
    @enduml

  
  \testmethod
    Module test

  \traceability
***************************************************************************************************/
#ifdef HLA_QAC_ACTIVE
  #pragma PRQA_NO_SIDE_EFFECTS HLAUtilsIsNAN
#endif
boolean HLAUtilsIsNAN(const float32 x);

/** ************************************************************************************************
  \brief
    Checks whether a floating point number is finite - platform independent.

  \pre
    None

  \post
    None

  \param[in]  x       floating point number

  \return
    \c b_FALSE in case \c x is positive or negative infinity. 
    \c b_TRUE in all other cases.

  \globals
    None

  \InOutCorrelation
    Using platform specific implementation of isFinite check. 

  \callsequence
    @startuml 
      title Sequence diagram of HLAUtilsIsFinite()
      
      box "Function" #LightGreen
      participant hla_input_checks.c  as InputChecks
      participant hla_utils.c         as this
      end box
      
      autonumber "<b>[00]"
      InputChecks ->> this: ""**HLA_InputChecks_CriticalInputData()**"" calls\n""**HLAUtilsIsFinite()**""
      Activate this
        this ->> this: Calls platform specific\n version of isFinite check
        this -->> InputChecks: boolean
      Deactivate this
    @enduml

  
  \testmethod
    Module test

  \traceability
***************************************************************************************************/
#ifdef HLA_QAC_ACTIVE
  #pragma PRQA_NO_SIDE_EFFECTS HLAUtilsIsFinite
#endif
boolean HLAUtilsIsFinite(const float32 x);

/* avoid cyclic binding ---------------------------------------------------*/
#endif /* #ifndef H_HLA_UTILS_H */


