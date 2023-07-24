/*! \file **********************************************************************

  TEMPLATE VERSION:          1.2
                             changed parameters in cpp version to be a struct/class
                             added version management for template

  COMPANY:                   Continental AG, ADAS, A.D.C. GmbH

  PROJECT:                   MFC4xx

  CPU:                       CPU-Independent

  COMPONENT:                 LCF

  MODULNAME:                 lcf_ver.h

  DESCRIPTION:               -

  AUTHOR:                    -

  CREATION DATE:             -

  VERSION:                   $Revision: 1.49.1.49 $


  ---*/ /*---
  CHANGES:                   $Log: lcf_ver.h  

**************************************************************************** */
#ifndef lcf_ver_h__
#define lcf_ver_h__

/*****************************************************************************
  SYMBOLIC CONSTANTS
*****************************************************************************/


/* Component version number as 4 byte BCD MM.SS.F1.F2
  MM: Main version number. This number is dependent on the external component 
      interface i.e. interface change enforces an increase. The number 
      starts with "01".
  SS: Sub version number. This number reflects functional changes within the main
      version of the component. The number starts with "00" at every new main 
      version number step. 
  F1: Bug fix level number. This number indicates exclusively error-correcting changes.
      If the sub version number in incremented the bug fix level restarts with "00".
  F2: Bug fix sub-level number.
*/
/* Fill following values according to the CP name AL_LCF_MM.SS.F1_INT-F2 */
#define LCFALL_SW_MAIN_VER_NO             0x05U
#define LCFALL_SW_SUB_VER_NO              0x10U
#define LCFALL_SW_BUG_FIX_LEV             0x52U
#define LCFALL_SW_BUG_FIX_LEV2            0x00U//reserved for eng. drops (00 = official CP)

/*! LCF_ALL version number: */
#define LCFALL_SW_VERSION_NUMBER          ((LCFALL_SW_MAIN_VER_NO<<24u) |(LCFALL_SW_SUB_VER_NO<<16u) \
												| (LCFALL_SW_BUG_FIX_LEV<<8u) | (LCFALL_SW_BUG_FIX_LEV2))

/*! LCF_ALL checkpoint name: */
#define LCF_CHECKPOINT "SW_LCF_05.10.52"

#ifndef NDEBUG
/*! LCF_ALL build name: */
#define LCF_BUILD LCF_CHECKPOINT "_DEBUG"
#else
/*! LCF_ALL build name: */
#define LCF_BUILD LCF_CHECKPOINT "_RELEASE"
#endif

#endif // lcf_ver_h__

