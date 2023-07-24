/*! \file **********************************************************************

COMPANY:                   COPYRIGHT (C) Continental AG
  
PROJECT:                   Mainstream

CPU:                       CPU-Independent

COMPONENT:                 CD Collision Detection

PACKAGENAME:               cd_merging.c

DESCRIPTION:               merging function for CD

AUTHOR:                    $Author: Kramer, Andreas (uidv8254) $

CREATION DATE:             $Date: 2018/10/10 17:57:35CEST $

VERSION:                   $Revision: 1.7 $

LEGACY VERSION:            Revision: 2.2

**************************************************************************** */


/*****************************************************************************
  INCLUDES
*****************************************************************************/


#include "cd_int.h"

#if (ACDC_CFG_CD)
/*****************************************************************************
  MODULE DESCRIPTION
*****************************************************************************/
/**

\defgroup cd_merging Merging
\ingroup cd
\brief          The module Merging contains functions, that are used to decide which information of two merged objects is kept.\n\n

\description    If two objects get merged in EM, their historical information in CD also has to be merged. 
                Therefore the module is called at the beginning of each cycle. \n
                The main function of the module is: \ref CDMergeInternalObjects.

\{
*/


#endif  /* #if (ACDC_CFG_CD) */

///\}
