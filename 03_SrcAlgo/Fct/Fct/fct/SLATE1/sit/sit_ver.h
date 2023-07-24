/*! \file **********************************************************************

COMPANY:                   COPYRIGHT (C) Continental AG

PROJECT:                   Adaptive Cruise Control (ACC)

CPU:                       CPU-Independent

COMPONENT:                 SLATE_SIT (Situation)

PACKAGENAME:               sit_ver.h

DESCRIPTION:               Version File for ACC Situation (SIT) module

AUTHOR:                    Boll Marie-Theres (uidu1091)

CREATION DATE:             20.06.2016

VERSION:                   $Revision: 1.2 $

LEGACY VERSION:            Revision: 2.0

**************************************************************************** */
#ifndef SIT_VER_H_INCLUDED
#define SIT_VER_H_INCLUDED
/*****************************************************************************
  MODULE DESCRIPTION
*****************************************************************************/
/*!
@defgroup sit_ver Version
@ingroup sit
@brief           Comprises the component's version number of current software.
@description     sit version number is provided.
@{
*/
/*****************************************************************************
  SIT ACC situation version number
*****************************************************************************/

/*! SIT Main version number*/
#define SIT_SW_MAIN_VER_NO       (0x01)
/*! SIT Sub version number*/
#define SIT_SW_SUB_VER_NO        (0x01)
/*! SIT Bug Fix version number */
#define SIT_SW_BUG_FIX_LEV       (0x00)
/*! SIT INT Level version number */
#define SIT_SW_INT_VER_NO        (0x00)

/*! SIT version number */
#define SIT_SW_VERSION_NUMBER     (   ( ( (uint32)SIT_SW_MAIN_VER_NO ) << 24) \
  | ( ( (uint32)SIT_SW_SUB_VER_NO  ) << 16) \
  | ( ( (uint32)SIT_SW_BUG_FIX_LEV ) <<  8) \
  | ( ( (uint32)SIT_SW_INT_VER_NO  )      ) )
/// @}
#endif /* SIT_VER_H_INCLUDED */
