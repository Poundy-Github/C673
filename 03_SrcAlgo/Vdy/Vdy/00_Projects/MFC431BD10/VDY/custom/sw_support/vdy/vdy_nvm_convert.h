/*! \file **********************************************************************
  COMPANY:                   Continental AG, ADAS, A.D.C. GmbH
  PROJECT:                   MFC431
  CPU:                       CPU-Independent
  COMPONENT:                 VDY
  MODULNAME:                 vdy_nvm_convert.h
  DESCRIPTION:               NVM Learning Values Version Conversion Service
  AUTHOR:                    Jayashree K Jahagirdar
  CREATION DATE:             2017-02-03
  VERSION:                   $$
  ---*/ /*---
  CHANGES:                   $$
**************************************************************************** */

#ifndef vdy_nvm_convert_h__
#define vdy_nvm_convert_h__

/****************************************************************************
* INCLUDES
*****************************************************************************/
#include "algo_glob.h"
 
/****************************************************************************
* SYMBOLIC CONSTANTS
*****************************************************************************/
#ifndef   NVM_VDY_INTFVER_V0
  #define NVM_VDY_INTFVER_V0	(0U)
#endif
/****************************************************************************
* TYPEDEFS
*****************************************************************************/
 
/****************************************************************************
* GLOBAL FUNCTIONS DECLARATION
*****************************************************************************/

sint32 NvmConvertVDYNvIoData( const void* const pSource, VDYNvIoData_t* const pDest);

#endif

/* EOF */
