/*! \file **********************************************************************
  COMPANY:                   Continental AG, ADAS, A.D.C. GmbH
  PROJECT:                   MFC431
  CPU:                       CPU-Independent
  COMPONENT:                 VDY
  MODULNAME:                 vdy_nvm_init.h
  DESCRIPTION:               NVM Learning Values Initialization Service
  AUTHOR:                    Jayashree K Jahagirdar
  CREATION DATE:             2017-02-02
  VERSION:                   $$
  ---*/ /*---
  CHANGES:                   $$
**************************************************************************** */

#ifndef vdy_nvm_init_h__
#define vdy_nvm_init_h__

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

void NvmInitVDYNvIoData( VDYNvIoData_t* const Dest, boolean bCalibReset );

#endif

/* EOF */
