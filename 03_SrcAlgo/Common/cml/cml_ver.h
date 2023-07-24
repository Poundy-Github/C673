/*! \file **********************************************************************

  COMPANY:                   Continental AG, A.D.C. GmbH

  CPU:                       CPU-Independent

  COMPONENT:                 CML (Common Math Library)

  MODULNAME:                 cml_ver.h

  DESCRIPTION:               Version file for the CML

  AUTHOR:                    Daniel Meschenmoser

  CREATION DATE:             07.09.2012

  VERSION:                   $Revision: 1.61 $

**************************************************************************** */

/*****************************************************************************
  INCLUDE PROTECTION
*****************************************************************************/

/* allow inclusion of cml sub-headers only if external cml header is included */
#ifndef _CML_EXT_INCLUDED
  #pragma message(__FILE__": Inclusion of cml_ver.h is discouraged. Include cml_ext.h instead.")
#endif /* #ifdef _CML_EXT_INCLUDED */

#ifndef _CML_VER_INCLUDED
#define _CML_VER_INCLUDED


/*****************************************************************************
  CONSTANTS
*****************************************************************************/

/*! CML version number */
#define CML_VERSION_NUMBER  (0x01091501uL)   ///< CML Release Version Number

#endif /* #ifndef _CML_VER_INCLUDED */

