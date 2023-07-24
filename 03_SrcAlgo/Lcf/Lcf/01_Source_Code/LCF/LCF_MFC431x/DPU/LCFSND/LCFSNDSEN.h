/*===========================================================*
  Copyright (C) Continental AG
  All Rights Reserved
  PROJECT       : LCF100
  COMPONENT     : LCF
  TASK          : Sensor
  WRAPPER       : LCFSND
  AUTHOR        : Send_AuxCodeGen
  VERSION       : 4.0

  Version Management Information
  $File: $
  $Revision: 1.1 $
  $Author: Asong, Wedndah Asaha (uidj2187) $
  $Date: 2019/03/24 17:37:35CET $
  $Log: LCFSNDSEN.h  $
  Revision 1.1 2019/03/24 17:37:35CET Asong, Wedndah Asaha (uidj2187) 
  Initial revision
  Member added to project /ADAS/SW/Projects/MFC431x/MFC431/DPU/04_Engineering/01_Source_Code/LCF/LCF_MFC431x/DPU/LCFSND/project.pj
  Revision 1.1 2019/03/24 08:39:36CET Asong, Wedndah Asaha (uidj2187) 
  Initial revision
  Member added to project /ADAS/SW/Projects/MFC431x/MFC431/DPU/04_Engineering/01_Source_Code/LCF/LCF_MFC431x/DPU/LCFSND/project.pj
  Revision 1.2 2019/02/20 14:03:16CET Asong, Wedndah Asaha (uidj2187) 
  AuxCodeGen 4.0
**===========================================================*/
//! @file     LCFSNDSEN.h
//! @brief    Lateral Control Functions - Send (LCFSND) Wrapper Sensor Header.

#ifndef _LCFSNDSEN_H_
#define _LCFSNDSEN_H_

/*-----------------------------------------------------*
   I N C L U D E S
**-----------------------------------------------------*/

#include "lcf_sen_iface.h"
#include "LCFSND/LCFSNDSEN_custom.h"
#include "LCFSNDSEN_common.h"

#ifdef __cplusplus
extern "C"
{
#endif

/*-----------------------------------------------------*
   F U N C T I O N   P R O T O T Y P E S
**-----------------------------------------------------*/

/*! LCFSNDSEN wrapper sensor reset function. */
extern void LCFSND_SenReset(void);

/*! LCFSNDSEN wrapper sensor process function. */
extern void LCFSND_SenProcess(void);

#ifdef __cplusplus
}
#endif

#endif // _LCFSNDSEN_H_
