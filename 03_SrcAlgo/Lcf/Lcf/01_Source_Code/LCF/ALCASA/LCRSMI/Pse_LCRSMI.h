/*===========================================================*
  Copyright (C) Continental AG
  All Rights Reserved
  PROJECT       : LCF100
  COMPONENT     : LCF
  TASK          : Sensor
  SUB-COMPONENT : ALCASA
  MODULE        : LCRSMI
  AUTHOR        : Module_AuxCodeGen
  VERSION       : 4.0

  Version Management Information
  $File: $
  $Revision: $
  $Author: $
  $Date: $
  $Log: $
**===========================================================*/
//! @file     Pse_LCRSMI.h
//! @brief     (LCRSMI) Module PSE Header.

#ifdef __cplusplus
extern "C"
{
#endif

/*-----------------------------------------------------*
   F U N C T I O N   D E F I N I T I O N S
**-----------------------------------------------------*/

#ifdef	RUNNABLE_ID

#if		RUNNABLE_ID == RUNNABLE_ID_LCRSMI_SenReset
void LCRSMI_SenResetData(void);
void LCRSMI_SenReset(void)
{
	
	LCRSMI_SenResetData();
	
	BI_lcrsmi_SysState_nu = 0U;
	DW_lcrsmi_Unit_Delay_DSTATE_a = 0U;
	DW_lcrsmi_Unit_Delay_DSTATE_b = 0U;
	DW_lcrsmi_Unit_Delay_DSTATE_g = 0U;
	DW_lcrsmi_Unit_Delay_DSTATE_p = 0U;
	DW_lcrsmi_Template_DSTATE = 0U;
	DW_lcrsmi_Unit_Delay1_DSTATE = 0U;
	DW_lcrsmi_Unit_Delay2_DSTATE_m = 0U;
	DW_lcrsmi_UnitDelay5_DSTATE = 0U;
	DW_lcrsmi_Unit_Delay4_DSTATE = 0U;
	DW_lcrsmi_Unit_Delay1_DSTATE_n = 0U;
	DW_lcrsmi_Template_DSTATE_o = 0U;
	DW_lcrsmi_Template1_DSTATE = 0U;
	DW_lcrsmi_Unit_Delay1_DSTATE_f = 0U;
	DW_lcrsmi_Template_DSTATE_a = 0U;
	DW_lcrsmi_Template1_DSTATE_e = 0U;
	DW_lcrsmi_is_active_c3_LCRSMI_cg = 0U;
	DW_lcrsmi_is_c3_LCRSMI_cg = 0U;
	DW_lcrsmi_is_PRESENT = 0U;
	DW_lcrsmi_Unit_Delay2_DSTATE = 0.F;
	DW_lcrsmi_UnitDelay1_DSTATE = 0.F;
	DW_lcrsmi_Unit_Delay_DSTATE = 0.F;
	DW_lcrsmi_Unit_Delay2_DSTATE_o = 0.F;
	DW_lcrsmi_UnitDelay1_DSTATE_b = 0.F;
	DW_lcrsmi_Unit_Delay_DSTATE_e = 0.F;
	DW_lcrsmi_Unit_Delay_DSTATE_l = 0.F;
	DW_lcrsmi_Unit_Delay_DSTATE_m = 0.F;
	DW_lcrsmi_UnitDelay1_DSTATE_j = 0.F;
	DW_lcrsmi_Unit_Delay3_DSTATE = 0.F;
	DW_lcrsmi_Unit_Delay_DSTATE_c = 0.F;
	
}
#define LCRSMI_SenReset LCRSMI_SenResetData
#endif

#undef	RUNNABLE_ID
#endif

#ifdef __cplusplus
}
#endif

