/*! @file ******************************************************************
  COMPANY:                Continental AG, BU ADAS, A.D.C. GmbH
 
  PROJECT:                MFC4xx

  COMPONENT:              HLA

  MODULNAME:              hla_main.h

  DESCRIPTION:            Headlight assist main.

  CREATION DATE:          2012-12-13
  
  CPU:                    Independent

  VERSION:                $Revision: 1.5 $
**************************************************************************** */

/* avoid cyclic binding -----------------------------------------------------*/
#ifndef H_HLA_MAIN_H
#define H_HLA_MAIN_H

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

#ifdef __cplusplus
extern "C" {
#endif

/** ************************************************************************************************
  \brief  
    Resets algo in a state like it would be right after start-up. 
    Used in simulation only.
  
  \pre
    None

  \post
    None

  \param
    None

  \return
    void

  \globals
    \ref bGlobVarsInitialized

  \InOutCorrelation
   Resets indicator that controls global variable initialization. This will lead at the very first call 
   of HlaExec() to a reset of all global variables.

  \callsequence
  
  \testmethod
    Module Test

  \traceability
***************************************************************************************************/
void HLA_FirstStatupState(void);

#ifdef __cplusplus
 }
#endif

/* avoid cyclic binding -----------------------------------------------------*/
#endif /* #ifndef H_HLA_MAIN_H */
