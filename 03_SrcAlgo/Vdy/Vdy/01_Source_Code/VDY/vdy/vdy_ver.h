/*! \file *********************************************************************

  @defgroup VDYVersion VDY Version
	@ingroup VDYHandCode
  @{

  $Company:			Continental AG $

  $Component:		VDY (Vehicle Dynamics Observer) $

  $Module:			vdy_ver.h $

  @brief			This file contains the vdy version and subversions
  
  $Descripion:		$

  $Revision: 1.20 $

  CHANGES:
  ---*/ /*---
  
*****************************************************************************/

#ifndef VDY_VER_HE_INCLUDED
#define VDY_VER_HE_INCLUDED

/*! Component version number as 3 byte BCD MM.SS.FF 
  MM: Main version number. This number is dependent on generation of Project.
      For fifth generation it should be "0x15"
  SS: Sub version number. This is unused in Mainstream.
  FF: Bug fix level number. This number indicates exclusively error-correcting changes.
      If the subversion number in incremented, the bug fix level restarts with "00".
*/

/// Component version number as 3 byte BCD MM.SS.FF \n  MM: Main version number. This number is dependent on the external component interface i.e. interface change enforces an increase. \n The number starts with "01".
#define VDY_SW_MAIN_VER_NO             0x15U

/// Component version number as 3 byte BCD MM.SS.FF \n SS: Sub version number. This number reflects functional changes within the main version of the component. \n The number starts with "00" at every new main version number step.
#define VDY_SW_SUB_VER_NO              0x00U

/// Component version number as 3 byte BCD MM.SS.FF \n FF: Bug fix level number. This number indicates exclusively error-correcting changes. \n If the subversion number in incremented, the bug fix level restarts with "00".
#define VDY_SW_BUG_FIX_LEV             0x17U

#endif

/** @} */ 
/* EOF */
