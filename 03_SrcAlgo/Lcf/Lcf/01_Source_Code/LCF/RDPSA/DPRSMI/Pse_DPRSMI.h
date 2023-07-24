/*===========================================================*
  Copyright (C) Continental AG
  All Rights Reserved
  PROJECT       : LCF100
  COMPONENT     : LCF
  TASK          : Sensor
  SUB-COMPONENT : RDPSA
  MODULE        : DPRSMI
  AUTHOR        : Module_AuxCodeGen
  VERSION       : 4.0

  Version Management Information
  $File: $
  $Revision: $
  $Author: $
  $Date: $
  $Log: $
**===========================================================*/
//! @file     Pse_DPRSMI.h
//! @brief     (DPRSMI) Module PSE Header.

#ifdef __cplusplus
extern "C"
{
#endif

/*-----------------------------------------------------*
   F U N C T I O N   D E F I N I T I O N S
**-----------------------------------------------------*/

#ifdef	RUNNABLE_ID

#if		RUNNABLE_ID == RUNNABLE_ID_DPRSMI_SenReset
void DPRSMI_SenResetData(void);
void DPRSMI_SenReset(void)
{
	
	DPRSMI_SenResetData();
	
	BI_dprsmi_SysState_nu = 0U;
	DW_dprsmi_Unit_Delay_DSTATE_i = 0U;
	DW_dprsmi_Unit_Delay_DSTATE_g = 0U;
	DW_dprsmi_Unit_Delay_DSTATE_as = 0U;
	DW_dprsmi_Unit_Delay_DSTATE_kr = 0U;
	DW_dprsmi_Unit_Delay_DSTATE_in = 0U;
	DW_dprsmi_Unit_Delay_DSTATE_b = 0U;
	DW_dprsmi_Unit_Delay_DSTATE_e = 0U;
	DW_dprsmi_Unit_Delay_DSTATE_n = 0U;
	DW_dprsmi_Unit_Delay_DSTATE_m = 0U;
	DW_dprsmi_Unit_Delay_DSTATE_f = 0U;
	DW_dprsmi_Template_DSTATE = 0U;
	DW_dprsmi_Unit_Delay1_DSTATE_o = 0U;
	DW_dprsmi_UnitDelay5_DSTATE = 0U;
	DW_dprsmi_UnitDelay2_DSTATE = 0U;
	DW_dprsmi_Unit_Delay4_DSTATE = 0U;
	DW_dprsmi_Unit_Delay1_DSTATE_b = 0U;
	DW_dprsmi_Template_DSTATE_n = 0U;
	DW_dprsmi_Template1_DSTATE = 0U;
	DW_dprsmi_Unit_Delay1_DSTATE_p = 0U;
	DW_dprsmi_Template_DSTATE_k = 0U;
	DW_dprsmi_Template1_DSTATE_b = 0U;
	DW_dprsmi_Template_DSTATE_g = 0U;
	DW_dprsmi_Template1_DSTATE_i = 0U;
	DW_dprsmi_is_active_c14_DPRSMI_cg = 0U;
	DW_dprsmi_is_c14_DPRSMI_cg = 0U;
	DW_dprsmi_is_PRESENT = 0U;
	DW_dprsmi_UnitDelay1_DSTATE = 0.F;
	DW_dprsmi_Unit_Delay2_DSTATE = 0.F;
	DW_dprsmi_Unit_Delay1_DSTATE = 0.F;
	DW_dprsmi_Unit_Delay_DSTATE = 0.F;
	DW_dprsmi_UnitDelay1_DSTATE_e = 0.F;
	DW_dprsmi_Unit_Delay2_DSTATE_d = 0.F;
	DW_dprsmi_Unit_Delay_DSTATE_d = 0.F;
	DW_dprsmi_UnitDelay1_DSTATE_d = 0.F;
	DW_dprsmi_Unit_Delay2_DSTATE_b = 0.F;
	DW_dprsmi_Unit_Delay1_DSTATE_e = 0.F;
	DW_dprsmi_Unit_Delay_DSTATE_p = 0.F;
	DW_dprsmi_UnitDelay1_DSTATE_c = 0.F;
	DW_dprsmi_Unit_Delay2_DSTATE_p = 0.F;
	DW_dprsmi_Unit_Delay_DSTATE_dy = 0.F;
	DW_dprsmi_Unit_Delay_DSTATE_l = 0.F;
	DW_dprsmi_Unit_Delay_DSTATE_a = 0.F;
	DW_dprsmi_UnitDelay1_DSTATE_n = 0.F;
	DW_dprsmi_Unit_Delay3_DSTATE = 0.F;
	DW_dprsmi_Unit_Delay_DSTATE_k = 0.F;
	
}
#define DPRSMI_SenReset DPRSMI_SenResetData
#endif

#undef	RUNNABLE_ID
#endif

#ifdef __cplusplus
}
#endif

