/*! \file **********************************************************************

COMPANY:                   COPYRIGHT (C) Continental AG

PROJECT:                   Adaptive Cruise Control (ACC)

CPU:                       CPU-Independent

COMPONENT:                 SLATE_LA (Lane Association)

PACKAGENAME:               la_ver.h

DESCRIPTION:               Version File for ACC Lane Association (LA) module

AUTHOR:                    Boll Marie-Theres (uidu1091)

CREATION DATE:             20.06.2016

VERSION:                   $Revision: 1.2 $

LEGACY VERSION:            Revision: 2.0

**************************************************************************** */
#ifndef LA_VER_H_INCLUDED
#define LA_VER_H_INCLUDED
/*****************************************************************************
  MODULE DESCRIPTION
*****************************************************************************/
/*!
@defgroup la_ver Version
@ingroup la
@brief           Comprises the component's version number of current software.
@description     LA ACC Lane Association version number is provided.
@{
*/
/*****************************************************************************
  LA ACC Lane Association version number
*****************************************************************************/

/*! LA Main version number*/
#define LA_SW_MAIN_VER_NO       (0x01)
/*! LA Sub version number*/
#define LA_SW_SUB_VER_NO        (0x01)
/*! LA Bug Fix version number */
#define LA_SW_BUG_FIX_LEV       (0x00)
/*! LA INT Level version number */
#define LA_SW_INT_VER_NO        (0x00)

/*! LA version number */
#define LA_SW_VERSION_NUMBER     (   ( ( (uint32)LA_SW_MAIN_VER_NO ) << 24) \
  | ( ( (uint32)LA_SW_SUB_VER_NO  ) << 16) \
  | ( ( (uint32)LA_SW_BUG_FIX_LEV ) <<  8) \
  | ( ( (uint32)LA_SW_INT_VER_NO  )      ) )
/** @} end defgroup */
#endif /* LA_VER_H_INCLUDED */
