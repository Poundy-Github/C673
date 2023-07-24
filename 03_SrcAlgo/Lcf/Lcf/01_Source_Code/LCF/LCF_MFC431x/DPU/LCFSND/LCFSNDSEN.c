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
  $Date: 2019/03/24 17:37:34CET $
  $Log: LCFSNDSEN.c  $
  Revision 1.1 2019/03/24 17:37:34CET Asong, Wedndah Asaha (uidj2187) 
  Initial revision
  Member added to project /ADAS/SW/Projects/MFC431x/MFC431/DPU/04_Engineering/01_Source_Code/LCF/LCF_MFC431x/DPU/LCFSND/project.pj
  Revision 1.1 2019/03/24 08:39:36CET Asong, Wedndah Asaha (uidj2187) 
  Initial revision
  Member added to project /ADAS/SW/Projects/MFC431x/MFC431/DPU/04_Engineering/01_Source_Code/LCF/LCF_MFC431x/DPU/LCFSND/project.pj
  Revision 1.2 2019/02/20 14:03:15CET Asong, Wedndah Asaha (uidj2187) 
  AuxCodeGen 4.0
  Revision 1.1 2019/01/31 18:56:13CET Asong, Wedndah Asaha (uidj2187) 
  Initial revision
  Member added to project /ADAS/SW/Components/LCF_LateralControlFunctions/04_Engineering/01_Source_Code/LCF/LCF_MFC/DPU/LCFSND/project.pj
**===========================================================*/
//! @file     LCFSNDSEN.c
//! @brief    Lateral Control Functions - Send (LCFSND) Wrapper Sensor C-File.

/*-----------------------------------------------------*
   I N C L U D E S
**-----------------------------------------------------*/

#include "LCFSNDSEN.h"

#ifdef __cplusplus
extern "C"
{
#endif

/*-------------------------------------------------*
   F U N C T I O N   D E F I N I T I O N S
**-------------------------------------------------*/

void LCFSND_SenReset(void)
{
	LCFSND_SenCommonReset();
	LCFSND_SenCustomReset();
}

void LCFSND_SenProcess(void)
{
	LCFSND_SenCommonProcess();
	LCFSND_SenCustomProcess();
}

#ifdef __cplusplus
}
#endif

