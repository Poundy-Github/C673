/*===========================================================*
  Copyright (C) Continental AG
  All Rights Reserved
  PROJECT       : LCF100
  COMPONENT     : LCF
  TASK          : Vehicle
  WRAPPER       : LCFRCV
  AUTHOR        : Receive_AuxCodeGen
  VERSION       : 4.0

  Version Management Information
  $File: $
  $Revision: 1.1 $
  $Author: Asong, Wedndah Asaha (uidj2187) $
  $Date: 2019/03/24 17:37:14CET $
  $Log: LCFRCVVEH.c  $
  Revision 1.1 2019/03/24 17:37:14CET Asong, Wedndah Asaha (uidj2187) 
  Initial revision
  Member added to project /ADAS/SW/Projects/MFC431x/MFC431/DPU/04_Engineering/01_Source_Code/LCF/LCF_MFC431x/DPU/LCFRCV/project.pj
  Revision 1.1 2019/03/24 08:39:33CET Asong, Wedndah Asaha (uidj2187) 
  Initial revision
  Member added to project /ADAS/SW/Projects/MFC431x/MFC431/DPU/04_Engineering/01_Source_Code/LCF/LCF_MFC431x/DPU/LCFRCV/project.pj
  Revision 1.2 2019/02/20 14:03:12CET Asong, Wedndah Asaha (uidj2187) 
  AuxCodeGen 4.0
**===========================================================*/
//! @file     LCFRCVVEH.c
//! @brief    Lateral Control Functions - Receive (LCFRCV) Wrapper C-File.

/*-----------------------------------------------------*
   I N C L U D E S
**-----------------------------------------------------*/

#include "LCFRCVVEH.h"

#ifdef __cplusplus
extern "C"
{
#endif

/*-------------------------------------------------*
   F U N C T I O N   D E F I N I T I O N S
**-------------------------------------------------*/

void LCFRCV_VehReset(void)
{
	LCFRCV_VehCommonReset();
	LCFRCV_VehCustomReset();
}

void LCFRCV_VehProcess(void)
{
	LCFRCV_VehCommonProcess();
	LCFRCV_VehCustomProcess();
}

#ifdef __cplusplus
}
#endif

