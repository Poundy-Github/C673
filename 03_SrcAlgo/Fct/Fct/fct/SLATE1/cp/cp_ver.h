/*! \file **********************************************************************

COMPANY:                   COPYRIGHT (C) Continental AG

PROJECT:                   Adaptive Cruise Control (ACC)

CPU:                       CPU-Independent

COMPONENT:                 SLATE_CP (Course Prediction)

PACKAGENAME:               cp_ver.h

DESCRIPTION:               Version File for ACC Course Prediction (CP) module

AUTHOR:                    Boll Marie-Theres (uidu1091)

CREATION DATE:             20.06.2016

VERSION:                   $Revision: 1.2 $

LEGACY VERSION:            Revision: 2.0

**************************************************************************** */
#ifndef CP_VER_H_INCLUDED
#define CP_VER_H_INCLUDED
/*****************************************************************************
  MODULE DESCRIPTION
*****************************************************************************/
/*!
@defgroup cp_ver Version
@ingroup cp
@brief           Comprises the component's version number of current software.
@description     CP ACC Course Prediction version number is provided.
@{
*/
/*****************************************************************************
  CP ACC Course Prediction version number
*****************************************************************************/
/*! CP version number */
#define CP_SW_VERSION_NUMBER    0x000203u

/*! CP Main version number*/
#define CP_SW_MAIN_VER_NO       (0x00)
/*! CP Sub version number*/
#define CP_SW_SUB_VER_NO        (0x00)
/*! CP Bug Fix version number */
#define CP_SW_BUG_FIX_LEV       (0x02)
/*! CP INT Level version number */
#define CP_SW_INT_VER_NO        (0x03)
/// @} 
#endif /* CP_VER_H_INCLUDED */
