/*===========================================================*
  Copyright (C) Continental AG
  All Rights Reserved
  PROJECT       : LCF100
  COMPONENT     : LCF
  TASK          : Sensor
  SUB-COMPONENT : VDPR
  MODULE        : VDPDRV
  AUTHOR        : Module_AuxCodeGen
  VERSION       : 4.0

  Version Management Information
  $File: $
  $Revision: $
  $Author: $
  $Date: $
  $Log: $
**===========================================================*/
//! @file     Pse_VDPDRV.h
//! @brief     (VDPDRV) Module PSE Header.

#ifdef __cplusplus
extern "C"
{
#endif

/*-----------------------------------------------------*
   F U N C T I O N   D E F I N I T I O N S
**-----------------------------------------------------*/

#ifdef	RUNNABLE_ID

#if		RUNNABLE_ID == RUNNABLE_ID_VDPDRV_SenReset
void VDPDRV_SenResetData(void);
void VDPDRV_SenReset(void)
{
	uint8 k1;
	
	VDPDRV_SenResetData();
	
	DW_vdpdrv_Unit_Delay_DSTATE_ce = 0U;
	DW_vdpdrv_Unit_Delay_DSTATE_g = 0U;
	DW_vdpdrv_Unit_Delay_DSTATE = 0.F;
	DW_vdpdrv_Unit_Delay1_DSTATE = 0.F;
	DW_vdpdrv_Unit_Delay_DSTATE_o = 0.F;
	DW_vdpdrv_Unit_Delay3_DSTATE_o = 0.F;
	DW_vdpdrv_Unit_Delay_DSTATE_l = 0.F;
	DW_vdpdrv_Unit_Delay2_DSTATE = 0.F;
	DW_vdpdrv_Unit_Delay_DSTATE_e = 0.F;
	DW_vdpdrv_Unit_Delay2_DSTATE_g = 0.F;
	
	for(k1 = 0; k1 < 8; k1++)
	{
		DW_vdpdrv_Unit_Delay2_DSTATE_m[k1] = 0U;
		DW_vdpdrv_Unit_Delay1_DSTATE_f[k1] = 0U;
		DW_vdpdrv_Unit_Delay_DSTATE_f[k1] = 0.F;
		DW_vdpdrv_Unit_Delay7_DSTATE[k1] = 0.F;
		DW_vdpdrv_Unit_Delay3_DSTATE[k1] = 0.F;
	}
	
	for(k1 = 0; k1 < 2; k1++)
	{
		DW_vdpdrv_Unit_Delay_DSTATE_k[k1] = 0.F;
	}
	
	for(k1 = 0; k1 < 7; k1++)
	{
		DW_vdpdrv_Unit_Delay_DSTATE_c[k1] = 0.F;
	}
	
}
#define VDPDRV_SenReset VDPDRV_SenResetData
#endif

#undef	RUNNABLE_ID
#endif

#ifdef __cplusplus
}
#endif

