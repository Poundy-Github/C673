/*===========================================================*
  Copyright (C) Continental AG
  All Rights Reserved
  PROJECT       : LCF100
  COMPONENT     : LCF
  TASK          : Vehicle
  SUB-COMPONENT : DRVMN
  MODULE        : DRMDAE
  AUTHOR        : Module_AuxCodeGen
  VERSION       : 4.0

  Version Management Information
  $File: $
  $Revision: $
  $Author: $
  $Date: $
  $Log: $
**===========================================================*/
//! @file     Pse_DRMDAE.h
//! @brief     (DRMDAE) Module PSE Header.

#ifdef __cplusplus
extern "C"
{
#endif

/*-----------------------------------------------------*
   F U N C T I O N   D E F I N I T I O N S
**-----------------------------------------------------*/

#ifdef	RUNNABLE_ID

#if		RUNNABLE_ID == RUNNABLE_ID_DRMDAE_VehReset
void DRMDAE_VehResetData(void);
void DRMDAE_VehReset(void)
{
	
	DRMDAE_VehResetData();
	
	BI_drmdae_DRMDAE_SysWarning_nu = 0U;
	DW_drmdae_Unit_Delay_DSTATE_c = 0U;
	DW_drmdae_Unit_Delay1_DSTATE = 0U;
	DW_drmdae_Unit_Delay_DSTATE_ca = 0U;
	DW_drmdae_Unit_Delay_DSTATE_l = 0U;
	DW_drmdae_Unit_Delay_DSTATE_j = 0U;
	DW_drmdae_Unit_Delay_DSTATE_d = 0U;
	DW_drmdae_Unit_Delay_DSTATE_e = 0U;
	DW_drmdae_Unit_Delay_DSTATE_k = 0U;
	DW_drmdae_Unit_Delay_DSTATE_jm = 0U;
	DW_drmdae_UnitDelay2_DSTATE = 0U;
	DW_drmdae_UnitDelay1_DSTATE_h = 0U;
	DW_drmdae_UnitDelay1_DSTATE_b = 0U;
	DW_drmdae_UnitDelay1_DSTATE_ga = 0U;
	DW_drmdae_is_active_c14_DRMDAE_cg = 0U;
	DW_drmdae_is_c14_DRMDAE_cg = 0U;
	DW_drmdae_UnitDelay1_DSTATE = 0.F;
	DW_drmdae_UnitDelay1_DSTATE_o = 0.F;
	DW_drmdae_UnitDelay1_DSTATE_g = 0.F;
	DW_drmdae_UnitDelay_DSTATE = 0.F;
	DW_drmdae_UnitDelay_DSTATE_d = 0.F;
	DW_drmdae_UnitDelay_DSTATE_h = 0.F;
	DW_drmdae_Unit_Delay_DSTATE = 0U;
	
}
#define DRMDAE_VehReset DRMDAE_VehResetData
#endif

#undef	RUNNABLE_ID
#endif

#ifdef __cplusplus
}
#endif

