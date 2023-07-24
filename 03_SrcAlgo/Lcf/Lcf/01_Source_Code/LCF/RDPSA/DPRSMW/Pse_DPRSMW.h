/*===========================================================*
  Copyright (C) Continental AG
  All Rights Reserved
  PROJECT       : LCF100
  COMPONENT     : LCF
  TASK          : Sensor
  SUB-COMPONENT : RDPSA
  MODULE        : DPRSMW
  AUTHOR        : Module_AuxCodeGen
  VERSION       : 4.0

  Version Management Information
  $File: $
  $Revision: $
  $Author: $
  $Date: $
  $Log: $
**===========================================================*/
//! @file     Pse_DPRSMW.h
//! @brief     (DPRSMW) Module PSE Header.

#ifdef __cplusplus
extern "C"
{
#endif

/*-----------------------------------------------------*
   F U N C T I O N   D E F I N I T I O N S
**-----------------------------------------------------*/

#ifdef	RUNNABLE_ID

#if		RUNNABLE_ID == RUNNABLE_ID_DPRSMW_SenReset
void DPRSMW_SenResetData(void);
void DPRSMW_SenReset(void)
{
	
	DPRSMW_SenResetData();
	
	BI_dprsmw_SysState_nu = 0U;
	DW_dprsmw_Unit_Delay_DSTATE_c = 0U;
	DW_dprsmw_Unit_Delay_DSTATE_a = 0U;
	DW_dprsmw_Unit_Delay_DSTATE_f = 0U;
	DW_dprsmw_Unit_Delay_DSTATE_k = 0U;
	DW_dprsmw_Unit_Delay_DSTATE_ks = 0U;
	DW_dprsmw_Unit_Delay_DSTATE_o = 0U;
	DW_dprsmw_Unit_Delay_DSTATE_g = 0U;
	DW_dprsmw_Unit_Delay_DSTATE_de = 0U;
	DW_dprsmw_Unit_Delay_DSTATE_n = 0U;
	DW_dprsmw_Unit_Delay_DSTATE_ki = 0U;
	DW_dprsmw_Template_DSTATE = 0U;
	DW_dprsmw_UnitDelay2_DSTATE_j = 0U;
	DW_dprsmw_UnitDelay5_DSTATE = 0U;
	DW_dprsmw_Unit_Delay_DSTATE_ga = 0U;
	DW_dprsmw_UnitDelay4_DSTATE = 0U;
	DW_dprsmw_Unit_Delay4_DSTATE = 0U;
	DW_dprsmw_Unit_Delay_DSTATE_p = 0U;
	DW_dprsmw_Template_DSTATE_m = 0U;
	DW_dprsmw_Template1_DSTATE = 0U;
	DW_dprsmw_Template1_DSTATE_g = 0U;
	DW_dprsmw_Template_DSTATE_d = 0U;
	DW_dprsmw_Template_DSTATE_n = 0U;
	DW_dprsmw_Template1_DSTATE_e = 0U;
	DW_dprsmw_is_active_c14_DPRSMW_cg = 0U;
	DW_dprsmw_is_c14_DPRSMW_cg = 0U;
	DW_dprsmw_is_PRESENT = 0U;
	DW_dprsmw_UnitDelay1_DSTATE = 0.F;
	DW_dprsmw_Unit_Delay2_DSTATE = 0.F;
	DW_dprsmw_Unit_Delay1_DSTATE = 0.F;
	DW_dprsmw_Unit_Delay_DSTATE = 0.F;
	DW_dprsmw_UnitDelay1_DSTATE_e = 0.F;
	DW_dprsmw_Unit_Delay2_DSTATE_d = 0.F;
	DW_dprsmw_Unit_Delay_DSTATE_d = 0.F;
	DW_dprsmw_UnitDelay1_DSTATE_k = 0.F;
	DW_dprsmw_Unit_Delay2_DSTATE_db = 0.F;
	DW_dprsmw_Unit_Delay1_DSTATE_p = 0.F;
	DW_dprsmw_Unit_Delay_DSTATE_h = 0.F;
	DW_dprsmw_UnitDelay1_DSTATE_b = 0.F;
	DW_dprsmw_Unit_Delay2_DSTATE_c = 0.F;
	DW_dprsmw_Unit_Delay_DSTATE_b = 0.F;
	DW_dprsmw_Unit_Delay_DSTATE_bk = 0.F;
	DW_dprsmw_UnitDelay1_DSTATE_d = 0.F;
	DW_dprsmw_UnitDelay1_DSTATE_ez = 0.F;
	DW_dprsmw_Unit_Delay3_DSTATE = 0.F;
	DW_dprsmw_UnitDelay1_DSTATE_o = 0.F;
	
}
#define DPRSMW_SenReset DPRSMW_SenResetData
#endif

#undef	RUNNABLE_ID
#endif

#ifdef __cplusplus
}
#endif

