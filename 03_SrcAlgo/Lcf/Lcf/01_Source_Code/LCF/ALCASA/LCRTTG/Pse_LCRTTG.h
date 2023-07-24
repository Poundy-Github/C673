/*===========================================================*
  Copyright (C) Continental AG
  All Rights Reserved
  PROJECT       : LCF100
  COMPONENT     : LCF
  TASK          : Sensor
  SUB-COMPONENT : ALCASA
  MODULE        : LCRTTG
  AUTHOR        : Module_AuxCodeGen
  VERSION       : 4.0

  Version Management Information
  $File: $
  $Revision: $
  $Author: $
  $Date: $
  $Log: $
**===========================================================*/
//! @file     Pse_LCRTTG.h
//! @brief     (LCRTTG) Module PSE Header.

#ifdef __cplusplus
extern "C"
{
#endif

/*-----------------------------------------------------*
   F U N C T I O N   D E F I N I T I O N S
**-----------------------------------------------------*/

#ifdef	RUNNABLE_ID

#if		RUNNABLE_ID == RUNNABLE_ID_LCRTTG_SenReset
void LCRTTG_SenResetData(void);
void LCRTTG_SenReset(void)
{
	
	LCRTTG_SenResetData();
	
	BI_lcrttg_LogicalOperator = 0U;
	DW_lcrttg_FixPtUnitDelay3_DSTATE = 0U;
	DW_lcrttg_FixPtUnitDelay3_DSTATE_e = 0U;
	DW_lcrttg_Unit_Delay_DSTATE = 0U;
	DW_lcrttg_FixPtUnitDelay1_DSTATE = 0.F;
	DW_lcrttg_FixPtUnitDelay4_DSTATE = 0.F;
	DW_lcrttg_FixPtUnitDelay1_DSTATE_k = 0.F;
	DW_lcrttg_FixPtUnitDelay4_DSTATE_n = 0.F;
	DW_lcrttg_FixPtUnitDelay5_DSTATE = 0.F;
	DW_lcrttg_FixPtUnitDelay2_DSTATE = 0.F;
	DW_lcrttg_FixPtUnitDelay4_DSTATE_e = 0.F;
	DW_lcrttg_Unit_Delay1_DSTATE = 0.F;
	DW_lcrttg_Unit_Delay1_DSTATE_b = 0.F;
	DW_lcrttg_Unit_Delay1_DSTATE_e = 0.F;
	DW_lcrttg_Unit_Delay1_DSTATE_k = 0.F;
	DW_lcrttg_Unit_Delay1_DSTATE_n = 0.F;
	DW_lcrttg_Unit_Delay1_DSTATE_i = 0.F;
	DW_lcrttg_Unit_Delay1_DSTATE_d = 0.F;
	DW_lcrttg_Unit_Delay1_DSTATE_m = 0.F;
	DW_lcrttg_Unit_Delay1_DSTATE_c = 0.F;
	DW_lcrttg_Unit_Delay1_DSTATE_a = 0.F;
	DW_lcrttg_Unit_Delay1_DSTATE_ed = 0.F;
	DW_lcrttg_Unit_Delay1_DSTATE_ns = 0.F;
	DW_lcrttg_Unit_Delay1_DSTATE_p = 0.F;
	DW_lcrttg_Unit_Delay1_DSTATE_df = 0.F;
	DW_lcrttg_Unit_Delay1_DSTATE_m0 = 0.F;
	DW_lcrttg_Unit_Delay1_DSTATE_ix = 0.F;
	DW_lcrttg_Unit_Delay1_DSTATE_aq = 0.F;
	DW_lcrttg_Unit_Delay1_DSTATE_ib = 0.F;
	DW_lcrttg_FixPtUnitDelay2_1_DSTATE = 0.F;
	DW_lcrttg_FixPtUnitDelay2_10_DSTATE = 0.F;
	DW_lcrttg_FixPtUnitDelay2_11_DSTATE = 0.F;
	DW_lcrttg_FixPtUnitDelay2_12_DSTATE = 0.F;
	DW_lcrttg_FixPtUnitDelay2_13_DSTATE = 0.F;
	DW_lcrttg_FixPtUnitDelay2_14_DSTATE = 0.F;
	DW_lcrttg_FixPtUnitDelay2_15_DSTATE = 0.F;
	DW_lcrttg_FixPtUnitDelay2_16_DSTATE = 0.F;
	DW_lcrttg_FixPtUnitDelay2_17_DSTATE = 0.F;
	DW_lcrttg_FixPtUnitDelay2_18_DSTATE = 0.F;
	DW_lcrttg_FixPtUnitDelay2_2_DSTATE = 0.F;
	DW_lcrttg_FixPtUnitDelay2_3_DSTATE = 0.F;
	DW_lcrttg_FixPtUnitDelay2_4_DSTATE = 0.F;
	DW_lcrttg_FixPtUnitDelay2_5_DSTATE = 0.F;
	DW_lcrttg_FixPtUnitDelay2_6_DSTATE = 0.F;
	DW_lcrttg_FixPtUnitDelay2_7_DSTATE = 0.F;
	DW_lcrttg_FixPtUnitDelay2_8_DSTATE = 0.F;
	DW_lcrttg_FixPtUnitDelay2_9_DSTATE = 0.F;
	
}
#define LCRTTG_SenReset LCRTTG_SenResetData
#endif

#undef	RUNNABLE_ID
#endif

#ifdef __cplusplus
}
#endif

