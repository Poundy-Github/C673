/*===========================================================*
  Copyright (C) Continental AG
  All Rights Reserved
  PROJECT       : LCF100
  COMPONENT     : LCF
  TASK          : Sensor
  SUB-COMPONENT : RDPSA
  MODULE        : DPRTTG
  AUTHOR        : Module_AuxCodeGen
  VERSION       : 4.0

  Version Management Information
  $File: $
  $Revision: $
  $Author: $
  $Date: $
  $Log: $
**===========================================================*/
//! @file     Pse_DPRTTG.h
//! @brief     (DPRTTG) Module PSE Header.

#ifdef __cplusplus
extern "C"
{
#endif

/*-----------------------------------------------------*
   F U N C T I O N   D E F I N I T I O N S
**-----------------------------------------------------*/

#ifdef	RUNNABLE_ID

#if		RUNNABLE_ID == RUNNABLE_ID_DPRTTG_SenReset
void DPRTTG_SenResetData(void);
void DPRTTG_SenReset(void)
{
	
	DPRTTG_SenResetData();
	
	BI_dprttg_LogicalOperator = 0U;
	DW_dprttg_FixPtUnitDelay4_DSTATE_d = 0U;
	DW_dprttg_FixPtUnitDelay1_DSTATE = 0U;
	DW_dprttg_FixPtUnitDelay1_DSTATE_f = 0U;
	DW_dprttg_FixPtUnitDelay1_DSTATE_m = 0U;
	DW_dprttg_FixPtUnitDelay1_DSTATE_m0 = 0U;
	DW_dprttg_FixPtUnitDelay1_DSTATE_p = 0U;
	DW_dprttg_Unit_Delay_DSTATE = 0U;
	DW_dprttg_FixPtUnitDelay2_DSTATE = 0.F;
	DW_dprttg_FixPtUnitDelay4_DSTATE = 0.F;
	DW_dprttg_FixPtUnitDelay4_DSTATE_f = 0.F;
	DW_dprttg_FixPtUnitDelay4_DSTATE_m = 0.F;
	DW_dprttg_FixPtUnitDelay4_DSTATE_j = 0.F;
	DW_dprttg_FixPtUnitDelay2_DSTATE_f = 0.F;
	DW_dprttg_FixPtUnitDelay5_DSTATE = 0.F;
	DW_dprttg_FixPtUnitDelay4_DSTATE_h = 0.F;
	DW_dprttg_FixPtUnitDelay5_DSTATE_b = 0.F;
	DW_dprttg_FixPtUnitDelay4_DSTATE_c = 0.F;
	DW_dprttg_Unit_Delay1_DSTATE = 0.F;
	DW_dprttg_Unit_Delay1_DSTATE_c = 0.F;
	DW_dprttg_Unit_Delay1_DSTATE_i = 0.F;
	DW_dprttg_Unit_Delay1_DSTATE_b = 0.F;
	DW_dprttg_Unit_Delay1_DSTATE_e = 0.F;
	DW_dprttg_Unit_Delay1_DSTATE_ik = 0.F;
	DW_dprttg_Unit_Delay1_DSTATE_a = 0.F;
	DW_dprttg_Unit_Delay1_DSTATE_ac = 0.F;
	DW_dprttg_Unit_Delay1_DSTATE_o = 0.F;
	DW_dprttg_Unit_Delay1_DSTATE_bh = 0.F;
	DW_dprttg_Unit_Delay1_DSTATE_l = 0.F;
	DW_dprttg_Unit_Delay1_DSTATE_n = 0.F;
	DW_dprttg_Unit_Delay1_DSTATE_p = 0.F;
	DW_dprttg_Unit_Delay1_DSTATE_nr = 0.F;
	DW_dprttg_Unit_Delay1_DSTATE_e1 = 0.F;
	DW_dprttg_Unit_Delay1_DSTATE_pg = 0.F;
	DW_dprttg_Unit_Delay1_DSTATE_ar = 0.F;
	DW_dprttg_Unit_Delay1_DSTATE_g = 0.F;
	DW_dprttg_Unit_Delay_1_DSTATE = 0.F;
	DW_dprttg_Unit_Delay_10_DSTATE = 0.F;
	DW_dprttg_Unit_Delay_11_DSTATE = 0.F;
	DW_dprttg_Unit_Delay_12_DSTATE = 0.F;
	DW_dprttg_Unit_Delay_13_DSTATE = 0.F;
	DW_dprttg_Unit_Delay_14_DSTATE = 0.F;
	DW_dprttg_Unit_Delay_15_DSTATE = 0.F;
	DW_dprttg_Unit_Delay_16_DSTATE = 0.F;
	DW_dprttg_Unit_Delay_17_DSTATE = 0.F;
	DW_dprttg_Unit_Delay_18_DSTATE = 0.F;
	DW_dprttg_Unit_Delay_2_DSTATE = 0.F;
	DW_dprttg_Unit_Delay_3_DSTATE = 0.F;
	DW_dprttg_Unit_Delay_4_DSTATE = 0.F;
	DW_dprttg_Unit_Delay_5_DSTATE = 0.F;
	DW_dprttg_Unit_Delay_6_DSTATE = 0.F;
	DW_dprttg_Unit_Delay_7_DSTATE = 0.F;
	DW_dprttg_Unit_Delay_8_DSTATE = 0.F;
	DW_dprttg_Unit_Delay_9_DSTATE = 0.F;
	
}
#define DPRTTG_SenReset DPRTTG_SenResetData
#endif

#undef	RUNNABLE_ID
#endif

#ifdef __cplusplus
}
#endif

