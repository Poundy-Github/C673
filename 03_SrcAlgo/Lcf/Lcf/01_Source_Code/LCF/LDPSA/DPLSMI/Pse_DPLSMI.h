/*===========================================================*
  Copyright (C) Continental AG
  All Rights Reserved
  PROJECT       : LCF100
  COMPONENT     : LCF
  TASK          : Sensor
  SUB-COMPONENT : LDPSA
  MODULE        : DPLSMI
  AUTHOR        : Module_AuxCodeGen
  VERSION       : 4.0

  Version Management Information
  $File: $
  $Revision: $
  $Author: $
  $Date: $
  $Log: $
**===========================================================*/
//! @file     Pse_DPLSMI.h
//! @brief     (DPLSMI) Module PSE Header.

#ifdef __cplusplus
extern "C"
{
#endif

/*-----------------------------------------------------*
   F U N C T I O N   D E F I N I T I O N S
**-----------------------------------------------------*/

#ifdef	RUNNABLE_ID

#if		RUNNABLE_ID == RUNNABLE_ID_DPLSMI_SenReset
void DPLSMI_SenResetData(void);
void DPLSMI_SenReset(void)
{
	
	DPLSMI_SenResetData();
	
	BI_dplsmi_SysState_nu = 0U;
	DW_dplsmi_Unit_Delay_DSTATE_n = 0U;
	DW_dplsmi_Unit_Delay_DSTATE_j = 0U;
	DW_dplsmi_Unit_Delay_DSTATE_b = 0U;
	DW_dplsmi_Unit_Delay_DSTATE_d = 0U;
	DW_dplsmi_Template_DSTATE = 0U;
	DW_dplsmi_Unit_Delay1_DSTATE = 0U;
	DW_dplsmi_UnitDelay5_DSTATE = 0U;
	DW_dplsmi_Unit_Delay4_DSTATE = 0U;
	DW_dplsmi_Unit_Delay1_DSTATE_d = 0U;
	DW_dplsmi_Template_DSTATE_d = 0U;
	DW_dplsmi_Template1_DSTATE = 0U;
	DW_dplsmi_Unit_Delay1_DSTATE_a = 0U;
	DW_dplsmi_Template_DSTATE_j = 0U;
	DW_dplsmi_Template1_DSTATE_a = 0U;
	DW_dplsmi_is_active_c5_DPLSMI_cg = 0U;
	DW_dplsmi_is_c5_DPLSMI_cg = 0U;
	DW_dplsmi_is_PRESENT = 0U;
	DW_dplsmi_UnitDelay1_DSTATE = 0.F;
	DW_dplsmi_Unit_Delay2_DSTATE = 0.F;
	DW_dplsmi_Unit_Delay_DSTATE = 0.F;
	DW_dplsmi_UnitDelay1_DSTATE_n = 0.F;
	DW_dplsmi_Unit_Delay2_DSTATE_g = 0.F;
	DW_dplsmi_Unit_Delay_DSTATE_f = 0.F;
	DW_dplsmi_Unit_Delay_DSTATE_o = 0.F;
	DW_dplsmi_Unit_Delay_DSTATE_m = 0.F;
	DW_dplsmi_UnitDelay1_DSTATE_nj = 0.F;
	DW_dplsmi_Unit_Delay3_DSTATE = 0.F;
	DW_dplsmi_Unit_Delay_DSTATE_a = 0.F;
	
}
#define DPLSMI_SenReset DPLSMI_SenResetData
#endif

#undef	RUNNABLE_ID
#endif

#ifdef __cplusplus
}
#endif

