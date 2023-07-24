/*===========================================================*
  Copyright (C) Continental AG
  All Rights Reserved
  PROJECT       : LCF100
  COMPONENT     : LCF
  TASK          : Vehicle
  WRAPPER       : LCFSND
  AUTHOR        : Send_AuxCodeGen
  VERSION       : 4.0

  Version Management Information
  $File: $
  $Revision: 1.1 $
  $Author: Asong, Wedndah Asaha (uidj2187) $
  $Date: 2019/03/24 17:37:36CET $
  $Log: LCFSNDVEH.h  $
  Revision 1.1 2019/03/24 17:37:36CET Asong, Wedndah Asaha (uidj2187) 
  Initial revision
  Member added to project /ADAS/SW/Projects/MFC431x/MFC431/DPU/04_Engineering/01_Source_Code/LCF/LCF_MFC431x/DPU/LCFSND/project.pj
  Revision 1.1 2019/03/24 08:39:37CET Asong, Wedndah Asaha (uidj2187) 
  Initial revision
  Member added to project /ADAS/SW/Projects/MFC431x/MFC431/DPU/04_Engineering/01_Source_Code/LCF/LCF_MFC431x/DPU/LCFSND/project.pj
  Revision 1.2 2019/02/20 14:03:18CET Asong, Wedndah Asaha (uidj2187) 
  AuxCodeGen 4.0
**===========================================================*/
//! @file     LCFSNDVEH.h
//! @brief    Lateral Control Functions - Send (LCFSND) Wrapper Vehicle Header.

#ifndef _LCFSNDVEH_H_
#define _LCFSNDVEH_H_

/*-----------------------------------------------------*
   I N C L U D E S
**-----------------------------------------------------*/

#include "lcf_veh_iface.h"
#include "LCFSND/LCFSNDVEH_custom.h"
#include "LCFSNDVEH_common.h"

#ifdef __cplusplus
extern "C"
{
#endif

/*-----------------------------------------------------*
   F U N C T I O N   P R O T O T Y P E S
**-----------------------------------------------------*/

/*! LCFSNDVEH wrapper vehicle reset function. */
extern void LCFSND_VehReset(void);

/*! LCFSNDVEH wrapper vehicle process function. */
extern void LCFSND_VehProcess(void);

#ifdef __cplusplus
}
#endif

#endif // _LCFSNDVEH_H_
