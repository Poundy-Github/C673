/*! \file **********************************************************************

COMPANY:                   COPYRIGHT (C) Continental AG

PROJECT:                   Adaptive Cruise Control (ACC)

CPU:                       CPU-Independent

COMPONENT:                 ACC_FIP (Adaptive Cruise Control - Function Input Preprocessing)

PACKAGENAME:               fip_ver.h

DESCRIPTION:               Version File for ACC FCT Input Preprocessing (ACC FIP) module

AUTHOR:                    Marie-Theres Boll (uidu1091)

CREATION DATE:             12.11.2012

VERSION:                   $Revision: 1.3 $

LEGACY VERSION:            Revision: 2.0

**************************************************************************** */

#ifndef FIP_VER_H_INCLUDED
#define FIP_VER_H_INCLUDED

/*****************************************************************************
  MODULE DESCRIPTION
*****************************************************************************/
/*!
@defgroup fip_ver Version
@ingroup fip
@brief           Comprises the component's version number of current software.
@{
*/

/*****************************************************************************
  FIP (FCT Input Preprocessing) version number
*****************************************************************************/

/*! FIP Main version number*/
#define FIP_SW_MAIN_VER_NO       (0x01)
/*! FIP Sub version number*/
#define FIP_SW_SUB_VER_NO        (0x01)
/*! FIP Bug Fix version number */
#define FIP_SW_BUG_FIX_LEV       (0x00)
/*! FIP INT Level version number */
#define FIP_SW_INT_VER_NO        (0x00)

/*! FIP version number */
#define FIP_SW_VERSION_NUMBER     (   ( ( (uint32)FIP_SW_MAIN_VER_NO ) << 24) \
  | ( ( (uint32)FIP_SW_SUB_VER_NO  ) << 16) \
  | ( ( (uint32)FIP_SW_BUG_FIX_LEV ) <<  8) \
  | ( ( (uint32)FIP_SW_INT_VER_NO  )      ) )

///@}
#endif /*!< FIP_VER_H_INCLUDED */

/* ************************************************************************* */
/*   Copyright ADC-GmbH, Lindau                                              */
/* ************************************************************************* */
