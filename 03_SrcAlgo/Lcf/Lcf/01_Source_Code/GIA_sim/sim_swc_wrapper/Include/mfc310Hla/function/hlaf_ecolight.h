/*! \file ********************************************************************

  COMPANY:                Continental, BC DAS, A.D.C. GmbH

  PROJECT:                MFC4xx

  CPU:                    FreeScale Gold Dust

  COMPONENT:              HLA

  MODULNAME:              hlaf_ecolight.h

  DESCRIPTION:            Functions for ecolight feature.

  AUTHOR:                 Alexander Manz

  CREATION DATE:          22.07.2013

  VERSION:                $Revision: 1.1 $ 

  CHANGES:                

  ---*/ /*---
  CHANGE:  
*****************************************************************************/

/* avoid cyclic binding */
#ifndef HLAF_ECOLIGHT_INCLUDED
#define HLAF_ECOLIGHT_INCLUDED

/*****************************************************************************
  INCLUDES
*****************************************************************************/
#include "hla_base.h"
#include "hlaf_ext.h"

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
#if (HLA_PROJECT == HLA_PROJECT_SMFC4B0)
void HLAF_FillEcoLight(const HLAF_t_InputSignals  *pObjectInput,
                       float32                    operationDistance,
                       float32                    operationTangent,
                       HLAF_EcoLight_t            *pEcoLightOutput);
#endif
#endif /* #ifndef HLAF_ECOLIGHT_INCLUDED */
