/*! \file **********************************************************************

COMPANY:                   COPYRIGHT (C) Continental AG

PROJECT:                   Adaptive Cruise Control (ACC)

CPU:                       CPU-Independent

COMPONENT:                 SLATE_OUT (Output)

PACKAGENAME:               out_ver.h

DESCRIPTION:               Version File for ACC Output (OUT) module

AUTHOR:                    Boll Marie-Theres (uidu1091)

CREATION DATE:             20.06.2016

VERSION:                   $Revision: 1.2 $

LEGACY VERSION:            Revision: 2.0

**************************************************************************** */
#ifndef OUT_VER_H_INCLUDED
#define OUT_VER_H_INCLUDED
/*****************************************************************************
  MODULE DESCRIPTION
*****************************************************************************/
/*!
@defgroup out_ver Version
@ingroup out
@brief           Comprises the component's version number of current software.
@description     out version number is provided.
@{
*/
/*****************************************************************************
  OUT ACC Output version number
*****************************************************************************/

/*! OUT Main version number*/
#define OUT_SW_MAIN_VER_NO       (0x01)
/*! OUT Sub version number*/
#define OUT_SW_SUB_VER_NO        (0x01)
/*! OUT Bug Fix version number */
#define OUT_SW_BUG_FIX_LEV       (0x00)
/*! OUT INT Level version number */
#define OUT_SW_INT_VER_NO        (0x00)

/*! OUT version number */
#define OUT_SW_VERSION_NUMBER     (   ( ( (uint32)OUT_SW_MAIN_VER_NO ) << 24) \
  | ( ( (uint32)OUT_SW_SUB_VER_NO  ) << 16) \
  | ( ( (uint32)OUT_SW_BUG_FIX_LEV ) <<  8) \
  | ( ( (uint32)OUT_SW_INT_VER_NO  )      ) )
/** @} end defgroup */
#endif /* OUT_VER_H_INCLUDED */
