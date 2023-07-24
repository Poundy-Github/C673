/*! @file ******************************************************************
  COMPANY:                Continental AG, BU ADAS, A.D.C. GmbH
 
  PROJECT:                MFC4xx

  COMPONENT:              HLA

  MODULNAME:              hla_input_checks.h

  DESCRIPTION:            Headlight assist input checks.

  CREATION DATE:          2014-04-10
  
  CPU:                    Independent

  VERSION:                $Revision: 1.4 $
**************************************************************************** */

/* avoid cyclic binding -----------------------------------------------------*/
#ifndef H_HLA_INPUT_CHECKS_H
#define H_HLA_INPUT_CHECKS_H
#define HLA_REMOVE_SERVICEFCT

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
    Performs input checks specified by algo architecture

  \pre
    None

  \post
    Input check according to architectural design was performed. If an error occurred it is stored in the
    internal error stack variable.

  \param [in]  eOpMode               Operation mode (reset, run)
  \param [in]  pReqPorts             Pointer to request port list
  \param [in]  pHlaSyncRefPrevCycle  Pointer to sync ref struct of previous cycle

  \return
    Void

  \globals
    Errors are stored in global error stack variable

  \InOutCorrelation
    Performs input checks, which are mainly specified by algo architecture. In case one check failed an error in the internal
    error list will be set. EM object list is not a mandatory input, so in case one of the checks for this port
    fails only a warning will be set. In parts of the code where the em object list is used these warnings
    are checked and these parts are not executed.\n
    Mandatory input checks:\n
    - request ports NULL pointers\n
      Request ports are checked for null pointers
    - request port version number\n
      Version number of request ports compared to the one from the RTE interface. A mismatch is not allowed.
    - request port sig state\n
      Signal status of request ports is checked
    - request port time stamps\n
      Time stamp of request ports is checked
    - request port measurement counter\n
      Measurement counter of request ports are checked.
    - bus signal states\n
      Bus signal states of these inputs which are used by the algo of vdy signals are checked
    - generic mandatory input data\n
      These checks are defined by the algo component, to prevent invalid inputs, which could lead to div/0 exceptions

    @startuml
    title Input Checks
        
    start
    :Null pointer check for all HLA request ports \nSet internal error if not passed \nFor EM object list only a warning is set, since it is not mandatory;
    if (No Error was set) then (Yes)
      :Checks request ports for interface version mismatch;
      if (No Error was set) then (Yes)
        :Check request ports for signal state errors;
        if(No Error was set and not in Soft Error sate) then (Yes)
          :Check timestamps of request ports;
          :Check measurement counters of request ports;
          if(No Error was set and not in Soft Error sate) then (Yes)
            if(OpMode is run) then (Yes)
              :Check Bus signal state;
            else(No)
            endif
            :Check critical input data;
          else(No)
          endif
        else(No)
        endif
      else(No)
      endif
    else (No)
    endif
    
    stop
        
    @enduml

    Details of null pointer checks for request ports:

    \image html HLA_InputChecks_ReqPortsAvailability.png

    Details of request ports version number checks:

    \image html HLA_InputChecks_ReqPortsVersion.png

    Details of request ports signal status check:

    \image html HLA_InputChecks_ReqPortsSigStatus.png

    Details of request ports timestamp check:

    \image html HLA_InputChecks_ReqPortsTimestamps.png

    Details of request port measurement counter check:

    \image html HLA_InputChecks_ReqPortsMeasCounter.png

    Details of request port bus signal state

    \image html HLA_InputChecks_BusSignalState.png

    Details of critical input data check

    \image html HLA_InputChecks_CriticalInputData.png

  \callsequence
    @startuml 
    title Sequence diagram of HLA_InputChecks()
    
    box "Main" #LightBlue
    participant hla_main.c          as Main
    participant hla_input_checks.c  as this
    end box
                      
    autonumber "<b>[00]"
     Main ->> this: ""**HLA_OpModeRun()/HLA_OpModeReset**"" calls\n""**HLA_InputChecks()**""
    Activate this
    this ->> this: Check if request ports are available
    opt No error set
      this ->> this: Check request ports version number
    end
    opt No error set
      this ->> this: Check request ports signal status
    end
    opt No error set and not in soft error state
      this ->> this: Check request ports timestamps
      this ->> this: Check request ports measurement counters
    end
    opt No error set and not in soft error state
    opt OpMode is run
      this ->> this: Check bus signal state
    end
      this ->> this: Check critical input data
    end
    this -->> Main: void
    Deactivate this
    @enduml
  
  \testmethod
    Module Test

  \traceability
***************************************************************************************************/
void HLA_InputChecks( const BaseOpMode_t           eOpMode,
                      const reqHlaPrtList_t* const pReqPorts, 
                      const Hla_SyncRef_t*   const pHlaSyncRefPrevCycle
                    );
/** ************************************************************************************************
  \brief
    Minimum check to ensure a proper algo execution.
  
  \pre
    None

  \post
    Minimum input check was performed. If an error occurred it is stored in the internal error stack
    variable.

  \param [in]  pReqPorts  request port pointer list
  \param [in]  pProPorts  provide port pointer list
  \param [in]  Services   algo services provided by frame SW 

  \return
    b_TRUE in case no error was found

  \globals
    Errors are stored in global error stack variable

  \InOutCorrelation
    In case of a null pointer in one of the above mentioned checks the return value will be false, 
    otherwise true\n
    This check ensures the following:\n
    - all provide ports are available\n
    - all used service functions are available\n
    - BSW control data is available and valid\n

    @startuml
    title Minimum Inputs Error Check

    start
    :Null pointer check for all HLA provide ports \nSet internal error if not passed;
    :Null pointer check for used service functions \nSet internal error if not passed;
    :Null pointer check of request ports including version number and signal status \nSet internal error if not passed;
    :Return true if at least on error was set;
    stop

    @enduml

  \callsequence
    @startuml 
    title Sequence diagram of HLA_InputChecks_MinimumInputs()

    box "Main" #LightBlue
    participant hla_main.c          as Main
    participant hla_input_checks.c  as this
    end box

    autonumber "<b>[00]"
    Main ->> this: ""**HlaExec()**"" calls\n""**HLA_InputChecks_MinimumInputs()**""
    Activate this
    this ->> this: Check if provide ports are available
    this ->> this: Check if service functions are available
    this ->> this: Check base control data
    this -->> Main: true if at least one error was found
    Deactivate this
    @enduml
  
  \testmethod
    Module Test

  \traceability
***************************************************************************************************/
boolean HLA_InputChecks_MinimumInputs( const reqHlaPrtList_t*    const pReqPorts, 
                                       const proHlaPrtList_t*    const pProPorts,
                                       const AS_t_ServiceFuncts* const Services
                                     );

/* avoid cyclic binding -----------------------------------------------------*/
#endif /* #ifndef H_HLA_INPUT_CHECKS_H */
