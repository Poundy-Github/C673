/*! \file **********************************************************************
  COMPANY:                   Continental AG, ADAS, A.D.C. GmbH
  PROJECT:                   MFC431
  CPU:                       CPU-Independent
  COMPONENT:                 VDY
  MODULNAME:                 vdy_cpar_init.h
  DESCRIPTION:               Initializer code for CodingParameters (CPar)
  AUTHOR:                    Jayashree K Jahagirdar
  CREATION DATE:             2017-02-01
  VERSION:                   $$
  ---*/ /*---
  CHANGES:                   $$
**************************************************************************** */

#ifndef VDY_cpar_init_h__
#define VDY_cpar_init_h__

/****************************************************************************
* INCLUDES
*****************************************************************************/
#include "algo_glob.h"

#ifdef __cplusplus
extern "C" 
{
#endif
 
/****************************************************************************
* SYMBOLIC CONSTANTS
*****************************************************************************/

/****************************************************************************
* TYPEDEFS
*****************************************************************************/
 
/****************************************************************************
* GLOBAL FUNCTIONS DECLARATION
*****************************************************************************/

void CParInitVehPar_HA2HF ( VehPar_t* const Dest );
void CParInitVehPar_HA2EM ( VehPar_t* const Dest );

#ifdef __cplusplus
}
#endif

#endif

/* EOF */
