/*! \file **********************************************************************

COMPANY:                   COPYRIGHT (C) Continental AG

PROJECT:                   Adaptive Cruise Control (ACC)

CPU:                       CPU-Independent

COMPONENT:                 ACC/LOCC (Adaptive Cruise Control - Longitudinal Cruise Control)

PACKAGENAME:               frame_locc_ver.h

DESCRIPTION:               LOCC Component version header file

AUTHOR:                    Mistry Niraj (uidq5738)

CREATION DATE:             24.06.2017

VERSION:                   $Revision: 1.36.1.1 $

LEGACY VERSION:            Revision: 2.0

**************************************************************************** */

#ifndef _FRAME_LOCC_VER_H_INCLUDED
#define _FRAME_LOCC_VER_H_INCLUDED

/*****************************************************************************
  INCLUDES
*****************************************************************************/

#ifdef __cplusplus
extern "C" {
#endif

#include "fct_project_id.h"

/*****************************************************************************
  Version: LOCC Longitudinal Cruise Control
*****************************************************************************/

/* Component version number as 4 bytes: GEN.IFC.CTT.BFL
  GEN: Generation version number.
       - This number decribes the generation of the component
       - The number starts with 01 for a new component
       - The number is increased after major changes of the 
         component architecture
  IFC: Interface version number.
       - This number describes the version of the whole component interface.
       - The number starts with 00 
       - The number is increased at every release when the interface of
         the component has changed either in its definition or meaning.
       - The number is set back to 00 everytime GEN is incremented.
  CTT: Content version number.
       - This number describes the functional content (component behaviour).
       - The number starts with 00
       - The number is increased at every component release, so far 
         the functional content of the component has changed
       - The number is set back to 00 everytime IFC is incremented
  BFL: Bugfix level or Integration level number.
       - The number decribes the number of integration of the same functional 
         content but with different bugfixes
       - The number starts with 00
       - The number is increased everytime a bugfix release of the component
         is integrated
       - The number is set back to 00 everytime CTT is incremented
*/
#define LOCC_GEN_VER_NO             (0x01U)
#define LOCC_IFC_VER_NO             (0x00U)
#define LOCC_CONTENT_VER_NO         (0x1CU)
#define LOCC_BUG_FIX_LEV            (0x01U)

/*! LOCC Component version number: */
#define LOCC_SW_VERSION_NUMBER          ((LOCC_GEN_VER_NO<<24) | (LOCC_IFC_VER_NO<<16) | (LOCC_CONTENT_VER_NO<<8) | (LOCC_BUG_FIX_LEV))

/*****************************************************************************
  MACROS 
*****************************************************************************/

#define STR_SW_LOCC_VERSION_NUMBER_TEXT(x) #x
#define STR_SW_LOCC_VERSION_INFO(m,s,f,i)  FCT_ALL_SW_PROJECT_NAME STR_SW_LOCC_VERSION_NUMBER_TEXT(m) STR_SW_LOCC_VERSION_NUMBER_TEXT(s) STR_SW_LOCC_VERSION_NUMBER_TEXT(f) STR_SW_LOCC_VERSION_NUMBER_TEXT(i) FCTALL_SW_ALGO_OFFICIAL FCTALL_SW_MODIFICATION_SUMMARY 
#define VERSION_LOCC_INFO_AS_TEXT  STR_SW_LOCC_VERSION_INFO(LOCC_GEN_VER_NO, LOCC_IFC_VER_NO, LOCC_CONTENT_VER_NO, LOCC_BUG_FIX_LEV)

/*****************************************************************************
  TYPEDEFS
*****************************************************************************/


/*****************************************************************************
  VARIABLEN (KOMPONENTENEXTERN)
*****************************************************************************/


/*****************************************************************************
  FUNKTIONEN (KOMPONENTENEXTERN)
*****************************************************************************/

#ifdef __cplusplus
}
#endif

#endif /* _FRAME_LOCC_VER_H_INCLUDED */
