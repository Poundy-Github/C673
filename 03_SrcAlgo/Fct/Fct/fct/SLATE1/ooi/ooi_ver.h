/*! \file **********************************************************************

COMPANY:                   COPYRIGHT (C) Continental AG

PROJECT:                   Adaptive Cruise Control (ACC)

CPU:                       CPU-Independent

COMPONENT:                 SLATE_OOI (Object of Interest selection)

MODULNAME:                 ooi_ver.h

DESCRIPTION:               Version File for ACC Object Of Interest (OOI) selection module

AUTHOR:                    Boll Marie-Theres (uidu1091)

CREATION DATE:             20.06.2016

VERSION:                   $Revision: 1.3 $

LEGACY VERSION:            Revision: 2.0

**************************************************************************** */


#ifndef OOI_VER_H_INCLUDED
#define OOI_VER_H_INCLUDED
/*****************************************************************************
  MODULE DESCRIPTION
*****************************************************************************/
/*!
@defgroup ooi_ver Version
@ingroup ooi
@brief           Comprises the component's version number of current software.
@description     ooi version number is provided.
@{
*/
/*****************************************************************************
  OOI ACC Object Of Interest selection version number
*****************************************************************************/

/*! OOI Main version number*/
#define OOI_SW_MAIN_VER_NO       (0x01)
/*! OOI Sub version number*/
#define OOI_SW_SUB_VER_NO        (0x01)
/*! OOI Bug Fix version number */
#define OOI_SW_BUG_FIX_LEV       (0x00)
/*! OOI INT Level version number */
#define OOI_SW_INT_VER_NO        (0x00)

/*! OOI version number */
#define OOI_SW_VERSION_NUMBER     (   ( ( (uint32)OOI_SW_MAIN_VER_NO ) << 24) \
  | ( ( (uint32)OOI_SW_SUB_VER_NO  ) << 16) \
  | ( ( (uint32)OOI_SW_BUG_FIX_LEV ) <<  8) \
  | ( ( (uint32)OOI_SW_INT_VER_NO  )      ) )
/** @} end defgroup ooi*/
#endif /* OOI_VER_H_INCLUDED */


