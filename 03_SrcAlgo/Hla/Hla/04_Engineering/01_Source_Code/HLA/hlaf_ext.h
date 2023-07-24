/*! @file ******************************************************************
  COMPANY:                Continental AG, BU ADAS, A.D.C. GmbH
 
  PROJECT:                MFC4xx

  COMPONENT:              HLA

  MODULNAME:              hlaf_ext.h

  DESCRIPTION:            Head light assist function interfaces.

  CREATION DATE:          2010-01-07
  
  CPU:                    Independent

  VERSION:                $Revision: 1.9 $
**************************************************************************** */

/* avoid cyclic binding -----------------------------------------------------*/
#ifndef H_HLAF_EXT_H
#define H_HLAF_EXT_H

/*****************************************************************************
  INCLUDES
*****************************************************************************/
#include "hla_defs.h"
#include "hlaf_type.h"
/*****************************************************************************
  SYMBOLIC CONSTANTS 
*****************************************************************************/


/*****************************************************************************
  TYPEDEFS 
*****************************************************************************/


/*****************************************************************************
  GLOBAL FUNCTION DECLARATIONS
*****************************************************************************/
/* Needed for HIL since it is written in c++ */
#ifdef __cplusplus
extern "C" {
#endif

/** ************************************************************************************************
  \brief
    Initializes the HLAF-component during reset mode.
  
  \pre
    request ports are available and valid. Input checks were performed.

  \post
    None
    
  \param[in]  pReqPorts   Pointer to request port list

  \return
    Void

  \globals
    \ref timeStampPrevCycle
    \ref hlafData

  \InOutCorrelation
    At the beginning and end of this function the start and end of the HLA_RTA_HLAF_INIT rta event is set.

    Current timestamp is stored to global variable \ref timeStampPrevCycle for later usage.

    The \ref hlafData gets initialized next. The whole internal struct is set to zero. Then the measurement counter 
    and timestamp is set by using base control data request port. Blockage state in decision data is set to clearance measurement.

    Then initialization functions of following modules are called:
    - camera2world rotation matrices 
    - matrix
    - dimming

    @startuml
    title HLAF init function

    start
    :Add init start RTA event;
    :Initialize hlaf data;
    :Initialize matrix data;
    :Initialize dimming areas;
    :Add init end RTA event;
    end

    @enduml

  \callsequence
    @startuml 
    title Sequence diagram of HLAF_v_Init()
    
    box "Function" #LightGreen
    participant hla_main.c       as Main
    participant hlaf.c          as this
    participant hla_utils.c     as utils
    participant hlaf_matrix.c   as matrix
    participant hlaf_dimming.c  as dimming
    end box
                      
    autonumber "<b>[00]"
    Main ->> this: ""**HLA_OpModeReset()**"" calls\n""**HLAF_v_Init()**""
    Activate this
      this ->> utils: Add hlaf init RTA event
      Activate utils
        utils -->> this: void
      Deactivate utils
      this ->> this: Init hlaf data
      this ->> matrix: Init matrix data
      Activate matrix
        matrix -->> this: void
      Deactivate matrix
      this ->> dimming: Init dimming data
      Activate dimming
        dimming -->> this: void
      Deactivate dimming
      this ->> utils: Add hlaf init RTA event
      Activate utils
        utils -->> this: void
      Deactivate utils
      this -->> Main: void
    Deactivate this
    @enduml
  
  \testmethod
    Module Test

  \traceability
***************************************************************************************************/
void HLAF_v_Init( const reqHlaPrtList_t*    const pReqPorts
#ifdef HLA_TIME_MEAS_DETAILED
                , const AS_t_ServiceFuncts* const Services
#endif /* #ifdef HLA_TIME_MEAS_DETAILED */
                );

/** ************************************************************************************************
  \brief
    Executes HLAF function.\n

  \pre
    Hlaf initialization was executed. Error checks were passed.

  \post
    None

  \param [in]      pReqPorts  Pointer to request port list
  \param [in,out]  pProPorts  Pointer to provide ports structure
  \param [in]      Services   Pointer to service function handles

  \return
    Void

  \globals
    \ref hlafData

  \InOutCorrelation
    
    At the very beginning camera2world rotation matrices are initialized by providing corresponding data from 
    external calibration.
    
    After that \ref hlafData is filled. 

    Decisions regarding the environment are performed afterwards followed by the hla matrix main function. 

    Subsequently, the internal function \ref HLAF_SetLightStates() is executed to set high beam recommendation and
    GFAs and all other outputs.

    Then the meas freeze function is called to meas freeze the internal hlaf data.

    @startuml
    title HLAF init function
    
    start
    if(Scheduling mode is not degraded) then (Yes)
      :Fill hlaf data;
      :Make environment decisions;
      :Call hlaf matrix function part;
      :Set light states;
    else(No)
      :Set signal state to invalid;
    endif
    :Make hlaf measfreeze;
    end
    
    @enduml

  \callsequence
    @startuml 
    title Sequence diagram of HLAF_v_Exec()
    
    box "Function" #LightGreen
    participant hla_main.c       as Main
    participant hlaf.c    as this
    participant hla_utils.c    as utils
    participant hlaf_matrix.c    as matrix
    end box
                      
    autonumber "<b>[00]"
    Main ->> this: ""**HLA_OpModeRun()**"" calls\n""**HLAF_v_Init()**""
    Activate this
    
    this ->> utils: Add hlaf exec RTA event
    Activate utils
    utils -->> this: void
    Deactivate utils
    
    opt not scheduled in degraded mode
    this ->> this: Fill internal data \ncalls HLAF_FillData()
    
    this ->> utils: Add hlaf decision RTA event
    Activate utils
    utils -->> this: void
    Deactivate utils
    
    this ->> this: Environment decision\ncalls HLAF_EnvironmentDecisions()
    
    this ->> utils: Add hlaf decision RTA event
    Activate utils
    utils -->> this: void
    Deactivate utils
    
    this ->> utils: Add hlaf matrix RTA event
    Activate utils
    utils -->> this: void
    Deactivate utils
    
    this ->> matrix:Call matrix GFA calculation
    Activate matrix
    matrix -->> this:void
    Deactivate matrix
    
    this ->> utils: Add hlaf matrix RTA event
    Activate utils
    utils -->> this: void
    Deactivate utils
    
    this ->> this: Set light state\ncalls HLAF_SetLightStates()
    
    end
    
    this ->> utils: Add hlaf exec RTA event
    Activate utils
    utils -->> this: void
    Deactivate utils
    
    this ->> this: meas freeze hlaf data/parameter
    
    this -->> Main: void
    Deactivate this
    @enduml
  
  \testmethod
    Module Test

  \traceability
***************************************************************************************************/
void HLAF_v_Exec( const reqHlaPrtList_t*    const pReqPorts,
                        proHlaPrtList_t*    const pProPorts,
                  const AS_t_ServiceFuncts* const Services
                 );

#ifdef __cplusplus
}
#endif /* __cplusplus */

/* avoid cyclic binding -----------------------------------------------------*/
#endif /* #ifndef H_HLAF_EXT_H */
