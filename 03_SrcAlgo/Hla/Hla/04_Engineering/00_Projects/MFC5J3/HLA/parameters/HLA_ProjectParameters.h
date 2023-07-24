/** \file ******************************************************************
COMPANY:                Continental AG, BU ADAS, A.D.C. GmbH

PROJECT:                MFC5xx

COMPONENT:              HLA

FILENAME:               HLA_DecisionParameters.c

DESCRIPTION:            Parameters of decision module

CREATION DATE:          2022-06-16

CPU:                    Independent

VERSION:                $Revision: 1.0.0.1 $

/****************************************************************************
/* avoid cyclic binding -----------------------------------------------------*/
#ifndef H_HLA_PROJECT_PARAMETERS_H
#define H_HLA_PROJECT_PARAMETERS_H

/****************************************************************************
* INCLUDES
*****************************************************************************/
#include "Rte_Type.h"
#include "Rte_Algo_Type.h"

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
    Return pointer to HLA decision parameters
  
  \pre
    none
  \post
    none
  
  \return
    pointer to analysis parameter
  
  \globals
   None
  
  \InOutCorrelation
   None
  
  \callsequence
  
  \testmethod 
  
  \traceability 
***************************************************************************************************/
const CPAR_HLAF_Parameter_t* GetProjectParameters(void);

/* avoid cyclic binding -----------------------------------------------------*/
#endif /* #ifndef H_HLA_PROJECT_PARAMETERS_H */
