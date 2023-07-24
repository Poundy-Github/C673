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
  $Log: LCFRCVSEN.c  $
  Revision 1.1 2019/03/24 17:37:13CET Asong, Wedndah Asaha (uidj2187) 
  Initial revision
  Member added to project /ADAS/SW/Projects/MFC431x/MFC431/DPU/04_Engineering/01_Source_Code/LCF/LCF_MFC431x/DPU/LCFRCV/project.pj
  Revision 1.1 2019/03/24 08:39:31CET Asong, Wedndah Asaha (uidj2187) 
  Initial revision
  Member added to project /ADAS/SW/Projects/MFC431x/MFC431/DPU/04_Engineering/01_Source_Code/LCF/LCF_MFC431x/DPU/LCFRCV/project.pj
  Revision 1.2 2019/02/20 14:03:10CET Asong, Wedndah Asaha (uidj2187) 
  AuxCodeGen 4.0
**===========================================================*/
//! @file     LCFRCVSEN.c
//! @brief    Lateral Control Functions - Receive (LCFRCV) Wrapper C-File.

/*-----------------------------------------------------*
   I N C L U D E S
**-----------------------------------------------------*/

#include "LCFRCVSEN.h"

#ifdef __cplusplus
extern "C"
{
#endif

/*-------------------------------------------------*
   F U N C T I O N   D E F I N I T I O N S
**-------------------------------------------------*/

void LCFRCV_SenReset(void)
{
	LCFRCV_SenCommonReset();
	LCFRCV_SenCustomReset();
}

void LCFRCV_SenProcess(void)
{
	LCFRCV_SenCommonProcess();
	LCFRCV_SenCustomProcess();
}

#ifdef __cplusplus
}
#endif

