/*===========================================================*
  Copyright (C) Continental AG
  All Rights Reserved
  PROJECT       : LCF100
  COMPONENT     : LCF
  TASK          : Sensor
  SUB-COMPONENT : LDPSA
  MODULE        : DPLSMW
  AUTHOR        : Module_AuxCodeGen
  VERSION       : 4.0

  Version Management Information
  $File: $
  $Revision: $
  $Author: $
  $Date: $
  $Log: $
**===========================================================*/
//! @file     Pse_DPLSMW.h
//! @brief     (DPLSMW) Module PSE Header.

#ifdef __cplusplus
extern "C"
{
#endif

/*-----------------------------------------------------*
   F U N C T I O N   D E F I N I T I O N S
**-----------------------------------------------------*/

#ifdef	RUNNABLE_ID

#if		RUNNABLE_ID == RUNNABLE_ID_DPLSMW_SenReset
void DPLSMW_SenResetData(void);
void DPLSMW_SenReset(void)
{
	
	DPLSMW_SenResetData();
	
	BI_dplsmw_SysState_nu = 0U;
	DW_dplsmw_Unit_Delay_DSTATE_p = 0U;
	DW_dplsmw_Unit_Delay_DSTATE_n = 0U;
	DW_dplsmw_Unit_Delay_DSTATE_p0 = 0U;
	DW_dplsmw_Unit_Delay_DSTATE_m = 0U;
	DW_dplsmw_Template_DSTATE = 0U;
	DW_dplsmw_UnitDelay2_DSTATE_o = 0U;
	DW_dplsmw_UnitDelay5_DSTATE = 0U;
	DW_dplsmw_Unit_Delay_DSTATE_c = 0U;
	DW_dplsmw_Unit_Delay4_DSTATE = 0U;
	DW_dplsmw_Unit_Delay_DSTATE_b = 0U;
	DW_dplsmw_Template_DSTATE_e = 0U;
	DW_dplsmw_Template1_DSTATE = 0U;
	DW_dplsmw_Template_DSTATE_g = 0U;
	DW_dplsmw_Template1_DSTATE_g = 0U;
	DW_dplsmw_is_active_c12_DPLSMW_cg = 0U;
	DW_dplsmw_is_c12_DPLSMW_cg = 0U;
	DW_dplsmw_is_PRESENT = 0U;
	DW_dplsmw_UnitDelay1_DSTATE = 0.F;
	DW_dplsmw_Unit_Delay2_DSTATE = 0.F;
	DW_dplsmw_Unit_Delay_DSTATE = 0.F;
	DW_dplsmw_UnitDelay1_DSTATE_l = 0.F;
	DW_dplsmw_Unit_Delay2_DSTATE_f = 0.F;
	DW_dplsmw_Unit_Delay_DSTATE_l = 0.F;
	DW_dplsmw_Unit_Delay_DSTATE_d = 0.F;
	DW_dplsmw_UnitDelay1_DSTATE_n = 0.F;
	DW_dplsmw_UnitDelay1_DSTATE_i = 0.F;
	DW_dplsmw_Unit_Delay3_DSTATE = 0.F;
	DW_dplsmw_UnitDelay1_DSTATE_o = 0.F;
	
}
#define DPLSMW_SenReset DPLSMW_SenResetData
#endif

#undef	RUNNABLE_ID
#endif

#ifdef __cplusplus
}
#endif

