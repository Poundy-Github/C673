/*! \file *********************************************************************

  @defgroup VDYHandCode VDY Hand Code

  @{

  $Company:			Continental AG $

  $Component:		VDY (Vehicle Dynamics Observer) $

  $Module:			vdy_glob.h $

  @brief			This Module contains all types, definitions and prototypes also needed for this component

  $Descripion:		Interface to the component VDY. The component VDY is responsible for the determenation of all vehicle dynamics parameters. $
  
  $Revision: 1.7 $
  
  CHANGES:
  ---*/ /*---

*****************************************************************************/

#ifndef VDY_GLOB_HE_INCLUDED
#define VDY_GLOB_HE_INCLUDED
/*** START OF SINGLE INCLUDE SECTION ****************************************/

/**  */ 

/*****************************************************************************
  INCLUDES
*****************************************************************************/
#include "algo_glob.h"
#include "vdy_cfg_ext.h"


/*****************************************************************************
  (SYMBOLIC) CONSTANTS 
*****************************************************************************/



/*****************************************************************************
  MACROS 
*****************************************************************************/
#ifndef C_KMH_MS 
/// Constant conversion km/h to m/s 
#define C_KMH_MS      (3.6F) 
#endif

/*****************************************************************************
  TYPEDEFS 
*****************************************************************************/


/*****************************************************************************
  GLOBAL CONSTANTS
*****************************************************************************/



/*** END OF SINLGE INCLUDE SECTION ******************************************/
#endif

/** @} end defgroup */

/* EOF */
