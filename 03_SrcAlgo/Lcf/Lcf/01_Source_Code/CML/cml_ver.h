/*! \file **********************************************************************

  COMPANY:                   Continental AG, A.D.C. GmbH

  CPU:                       CPU-Independent

  COMPONENT:                 CML (Common Math Library)

  MODULNAME:                 cml_ver.h

  DESCRIPTION:               Version file for the CML

  AUTHOR:                    Daniel Meschenmoser

  CREATION DATE:             07.09.2012

  VERSION:                   $Revision: 1.73.1.10 $

**************************************************************************** */

/*****************************************************************************
  INCLUDE PROTECTION
*****************************************************************************/
#ifndef CML_VER_INCLUDED
#define CML_VER_INCLUDED

/* allow inclusion of cml sub-headers only if external cml header is included */
#ifndef CML_EXT_INCLUDED
  #pragma message(__FILE__": Inclusion of cml_ver.h is discouraged. Include cml_ext.h instead.")
#endif /* #ifdef CML_EXT_INCLUDED */

/*****************************************************************************
  CONSTANTS
*****************************************************************************/

/*! CML version number */
#define CML_VERSION_NUMBER  (0x01101309uL)   ///< CML Release Version Number

#endif /* #ifndef CML_VER_INCLUDED */

