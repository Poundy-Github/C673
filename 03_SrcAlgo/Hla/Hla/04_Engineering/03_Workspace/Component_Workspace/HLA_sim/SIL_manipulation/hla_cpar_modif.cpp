/* \file **********************************************************************

  COMPANY:                Continental AG, BU ADAS (A.D.C. GmbH)

  PROJECT:                MFC4xx

  CPU:                    CPU-Independent

  COMPONENT:              HLA

  MODULNAME:              hla_cpar_modif.cpp
  
  DESCRIPTION:            Coding parameter manipulation functions

  CREATION DATE:          2018-10-02

  VERSION:                $Revision: 1.2 $

**************************************************************************** */

/****************************************************************************
* INCLUDES
*****************************************************************************/
#include "hla_cpar_modif.h" 

/****************************************************************************
* SYMBOLIC CONSTANTS
*****************************************************************************/

/****************************************************************************
* LOCAL TYPEDEFS
*****************************************************************************/
 
/****************************************************************************
* GLOBAL VARIABLES
*****************************************************************************/
 
/****************************************************************************
* LOCAL FUNCTIONS DECLARATION
*****************************************************************************/

/****************************************************************************
* GLOBAL FUNCTIONS DEFINTION
*****************************************************************************/
/* *******************************************************************************
  Initializes HLA coding parameters
******************************************************************************** */
void CParModifCPAR_HLA( const CPAR_HLAF_Parameter_t& cparsFromRec, 
                              CPAR_HLAF_Parameter_t& cparsInitialized
                       )
{
  /* Overwrite recording dependent values */
  cparsInitialized.AlgoCfg.sensitivityMode = cparsFromRec.AlgoCfg.sensitivityMode;
}

/*****************************************************************************
  LOCAL FUNCTIONS 
*****************************************************************************/