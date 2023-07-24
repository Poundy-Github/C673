/*===========================================================*
  Copyright (C) Continental AG
  All Rights Reserved
  PROJECT       : LCF100
  COMPONENT     : LCF
  TASK          : Vehicle
  SUB-COMPONENT : TRJPLN
  MODULE        : TPLFRT
  AUTHOR        : Module_AuxCodeGen
  VERSION       : 4.0

  Version Management Information
  $File: $
  $Revision: $
  $Author: $
  $Date: $
  $Log: $
**===========================================================*/
//! @file     Pse_TPLFRT.h
//! @brief     (TPLFRT) Module PSE Header.

#ifdef __cplusplus
extern "C"
{
#endif

/*-----------------------------------------------------*
   F U N C T I O N   D E F I N I T I O N S
**-----------------------------------------------------*/

#ifdef	RUNNABLE_ID

#if		RUNNABLE_ID == RUNNABLE_ID_TPLFRT_VehReset
void TPLFRT_VehResetData(void);
void TPLFRT_VehReset(void)
{
	uint8 k1;
	
	TPLFRT_VehResetData();
	
	DW_tplfrt_UnitDelay_DSTATE_j = 0U;
	DW_tplfrt_UnitDelay_DSTATE = 0.F;
	DW_tplfrt_UnitDelay1_DSTATE = 0.F;
	DW_tplfrt_UnitDelay2_DSTATE = 0.F;
	DW_tplfrt_UnitDelay3_DSTATE = 0.F;
	
	for(k1 = 0; k1 < 15; k1++)
	{
		DW_tplfrt_UnitDelay6_DSTATE[k1] = 0.F;
		DW_tplfrt_UnitDelay5_DSTATE[k1] = 0.F;
		DW_tplfrt_UnitDelay4_DSTATE[k1] = 0.F;
		DW_tplfrt_UnitDelay1_DSTATE_c[k1] = 0.F;
	}
	
}
#define TPLFRT_VehReset TPLFRT_VehResetData
#endif

#undef	RUNNABLE_ID
#endif

#ifdef __cplusplus
}
#endif

