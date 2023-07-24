/*===========================================================*
  Copyright (C) Continental AG
  All Rights Reserved
  PROJECT       : LCF100
  COMPONENT     : LCF
  TASK          : Sensor
  WRAPPER       : LCFRCV
  AUTHOR        : Receive_AuxCodeGen
  VERSION       : 4.0

  Version Management Information
  $File: $
  $Revision: 1.1 $
  $Author: Asong, Wedndah Asaha (uidj2187) $
  $Date: 2019/03/24 17:37:13CET $
  $Log: LCFRCVSEN.h  $
  Revision 1.1 2019/03/24 17:37:13CET Asong, Wedndah Asaha (uidj2187) 
  Initial revision
  Member added to project /ADAS/SW/Projects/MFC431x/MFC431/DPU/04_Engineering/01_Source_Code/LCF/LCF_MFC431x/DPU/LCFRCV/project.pj
  Revision 1.1 2019/03/24 08:39:32CET Asong, Wedndah Asaha (uidj2187) 
  Initial revision
  Member added to project /ADAS/SW/Projects/MFC431x/MFC431/DPU/04_Engineering/01_Source_Code/LCF/LCF_MFC431x/DPU/LCFRCV/project.pj
  Revision 1.2 2019/02/20 14:03:11CET Asong, Wedndah Asaha (uidj2187) 
  AuxCodeGen 4.0
**===========================================================*/
//! @file     LCFRCVSEN.h
//! @brief    Lateral Control Functions - Receive (LCFRCV) Wrapper Header.

#ifndef _LCFRCVSEN_H_
#define _LCFRCVSEN_H_

/*-----------------------------------------------------*
   I N C L U D E S
**-----------------------------------------------------*/
#ifndef LCF_COURAGE
#include "lcf_sen_iface.h"
#include "LCFRCV/LCFRCVSEN_custom.h"
#include "LCFRCVSEN_common.h"
#else
#include "LCFRCV/LCFRCVSEN_mock.h"
#endif // LCF_COURAGE

#ifdef __cplusplus
extern "C"
{
#endif

/*-----------------------------------------------------*
   F U N C T I O N   P R O T O T Y P E S
**-----------------------------------------------------*/

/*! LCFRCVSEN wrapper reset function. */
extern void LCFRCV_SenReset(void);

/*! LCFRCVSEN wrapper process function. */
extern void LCFRCV_SenProcess(void);

#ifdef __cplusplus
}
#endif

#endif // _LCFRCVSEN_H_
