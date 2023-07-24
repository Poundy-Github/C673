/*! @file ******************************************************************
  COMPANY:                Continental AG, BU ADAS, A.D.C. GmbH
 
  PROJECT:                MFC4xx
 
  COMPONENT:              HLA
 
  FILENAME:               hla_cpar_init.h
 
  DESCRIPTION:            Coding parameter initialization service
 
  CREATION DATE:          2013-04-05
 
  CPU:                    Independent
 
  VERSION:                $Revision: 1.6 $
*************************************************************************** */

/* avoid cyclic binding -----------------------------------------------------*/
#ifndef H_HLA_CPAR_INIT_H
#define H_HLA_CPAR_INIT_H

/****************************************************************************
* INCLUDES
*****************************************************************************/
#include "algo_glob.h"
 
/****************************************************************************
* SYMBOLIC CONSTANTS
*****************************************************************************/

/****************************************************************************
* TYPEDEFS
*****************************************************************************/
 
/****************************************************************************
* GLOBAL FUNCTIONS DECLARATION
*****************************************************************************/
/** ************************************************************************************************
  \brief
    Initializes HLAF coding parameters.
  
  \pre
    None

  \post
    None

  \param  [in,out]  pDest  pointer to hlaf parameter

  \return
    void

  \globals
    None

  \InOutCorrelation
    The whole hlaf parameter struct is filled with default parameters. Version number is taken from
    RTE algo type, signal state is set to ok, timestamp and counters are set to zero.

  \callsequence
    @startuml 
    title Sequence diagram of CParInitCPAR_HLAF_Parameter()

    box "Main" #LightBlue
    participant hla_input_checks.c  as Main
    participant hla_cpar_init.c     as this
    end box
                      
    autonumber "<b>[00]"
    Main ->> this: ""**HLA_InputChecks_CPARDiff2DefaultsHlafPar()**"" calls\n""**CParInitCPAR_HLAF_Parameter()**""
    Activate this
    this ->> this: Default parameters are set in pDest
    this -->> Main: void
    Deactivate this
    @enduml

  
  \testmethod
    Module Test

  \traceability
***************************************************************************************************/
#ifdef __cplusplus
extern "C" 
{
#endif
void CParInitCPAR_HLAF_Parameter(CPAR_HLAF_Parameter_t* const pDest);
#ifdef __cplusplus
}
#endif

/* avoid cyclic binding -----------------------------------------------------*/
#endif /* #ifndef H_HLA_CPAR_INIT_H */
