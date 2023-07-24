/*===========================================================*
  Copyright (C) Continental AG
  All Rights Reserved
  PROJECT       : LCF100
  COMPONENT     : LCF
  TASK          : Sensor
  SUB-COMPONENT : LDPSA
  MODULE        : DPLTTG
  AUTHOR        : Module_AuxCodeGen
  VERSION       : 4.0

  Version Management Information
  $File: $
  $Revision: $
  $Author: $
  $Date: $
  $Log: $
**===========================================================*/
//! @file     Pse_DPLTTG.h
//! @brief     (DPLTTG) Module PSE Header.

#ifdef __cplusplus
extern "C"
{
#endif

/*-----------------------------------------------------*
   F U N C T I O N   D E F I N I T I O N S
**-----------------------------------------------------*/

#ifdef	RUNNABLE_ID

#if		RUNNABLE_ID == RUNNABLE_ID_DPLTTG_SenReset
void DPLTTG_SenResetData(void);
void DPLTTG_SenReset(void)
{
	
	DPLTTG_SenResetData();
	
	BI_dplttg_LogicalOperator = 0U;
	DW_dplttg_Unit_Delay_DSTATE = 0U;
	DW_dplttg_FixPtUnitDelay3_DSTATE = 0U;
	DW_dplttg_FixPtUnitDelay3_DSTATE_f = 0U;
	DW_dplttg_Unit_Delay1_DSTATE = 0.F;
	DW_dplttg_FixPtUnitDelay1_DSTATE = 0.F;
	DW_dplttg_Unit_Delay1_DSTATE_c = 0.F;
	DW_dplttg_Unit_Delay1_DSTATE_o = 0.F;
	DW_dplttg_Unit_Delay1_DSTATE_m = 0.F;
	DW_dplttg_Unit_Delay1_DSTATE_b = 0.F;
	DW_dplttg_Unit_Delay1_DSTATE_n = 0.F;
	DW_dplttg_Unit_Delay1_DSTATE_g = 0.F;
	DW_dplttg_Unit_Delay1_DSTATE_o1 = 0.F;
	DW_dplttg_Unit_Delay1_DSTATE_ch = 0.F;
	DW_dplttg_Unit_Delay1_DSTATE_mq = 0.F;
	DW_dplttg_Unit_Delay1_DSTATE_d = 0.F;
	DW_dplttg_Unit_Delay1_DSTATE_bc = 0.F;
	DW_dplttg_Unit_Delay1_DSTATE_e = 0.F;
	DW_dplttg_FixPtUnitDelay4_DSTATE = 0.F;
	DW_dplttg_FixPtUnitDelay1_DSTATE_o = 0.F;
	DW_dplttg_FixPtUnitDelay4_DSTATE_f = 0.F;
	DW_dplttg_FixPtUnitDelay5_DSTATE = 0.F;
	DW_dplttg_FixPtUnitDelay2_DSTATE = 0.F;
	DW_dplttg_FixPtUnitDelay4_DSTATE_g = 0.F;
	DW_dplttg_Unit_Delay1_DSTATE_i = 0.F;
	DW_dplttg_Unit_Delay1_DSTATE_me = 0.F;
	DW_dplttg_Unit_Delay1_DSTATE_j = 0.F;
	DW_dplttg_Unit_Delay1_DSTATE_dv = 0.F;
	DW_dplttg_Unit_Delay1_DSTATE_nh = 0.F;
	DW_dplttg_FixPtUnitDelay2_1_DSTATE = 0.F;
	DW_dplttg_FixPtUnitDelay2_10_DSTATE = 0.F;
	DW_dplttg_FixPtUnitDelay2_11_DSTATE = 0.F;
	DW_dplttg_FixPtUnitDelay2_12_DSTATE = 0.F;
	DW_dplttg_FixPtUnitDelay2_13_DSTATE = 0.F;
	DW_dplttg_FixPtUnitDelay2_14_DSTATE = 0.F;
	DW_dplttg_FixPtUnitDelay2_15_DSTATE = 0.F;
	DW_dplttg_FixPtUnitDelay2_16_DSTATE = 0.F;
	DW_dplttg_FixPtUnitDelay2_17_DSTATE = 0.F;
	DW_dplttg_FixPtUnitDelay2_18_DSTATE = 0.F;
	DW_dplttg_FixPtUnitDelay2_2_DSTATE = 0.F;
	DW_dplttg_FixPtUnitDelay2_3_DSTATE = 0.F;
	DW_dplttg_FixPtUnitDelay2_4_DSTATE = 0.F;
	DW_dplttg_FixPtUnitDelay2_5_DSTATE = 0.F;
	DW_dplttg_FixPtUnitDelay2_6_DSTATE = 0.F;
	DW_dplttg_FixPtUnitDelay2_7_DSTATE = 0.F;
	DW_dplttg_FixPtUnitDelay2_8_DSTATE = 0.F;
	DW_dplttg_FixPtUnitDelay2_9_DSTATE = 0.F;
	
}
#define DPLTTG_SenReset DPLTTG_SenResetData
#endif

#undef	RUNNABLE_ID
#endif

#ifdef __cplusplus
}
#endif

