/*===========================================================*
  Copyright (C) Continental AG
  All Rights Reserved
  PROJECT       : LCF100
  COMPONENT     : LCF
  TASK          : Sensor
  SUB-COMPONENT : TJASA
  MODULE        : TJATTG
  AUTHOR        : Module_AuxCodeGen
  VERSION       : 4.0

  Version Management Information
  $File: $
  $Revision: $
  $Author: $
  $Date: $
  $Log: $
**===========================================================*/
//! @file     Pse_TJATTG.h
//! @brief     (TJATTG) Module PSE Header.

#ifdef __cplusplus
extern "C"
{
#endif

/*-----------------------------------------------------*
   F U N C T I O N   D E F I N I T I O N S
**-----------------------------------------------------*/

#ifdef	RUNNABLE_ID

#if		RUNNABLE_ID == RUNNABLE_ID_TJATTG_SenReset
void TJATTG_SenResetData(void);
void TJATTG_SenReset(void)
{
	
	TJATTG_SenResetData();
	
	BI_tjattg_LogicalOperator_p = 0U;
	BI_tjattg_LogicalOperator_e = 0U;
	BI_tjattg_LogicalOperator_e0 = 0U;
	BI_tjattg_LogicalOperator_i = 0U;
	BI_tjattg_LogicalOperator_i0 = 0U;
	BI_tjattg_LogicalOperator_b = 0U;
	DW_tjattg_Unit_Delay2_DSTATE_a = 0U;
	DW_tjattg_Unit_Delay1_DSTATE_f = 0U;
	DW_tjattg_Unit_Delay5_DSTATE_k = 0U;
	DW_tjattg_Unit_Delay5_DSTATE_i = 0U;
	DW_tjattg_Unit_Delay4_DSTATE_l = 0U;
	DW_tjattg_Unit_Delay7_DSTATE = 0U;
	DW_tjattg_Unit_Delay6_DSTATE_h = 0U;
	DW_tjattg_Unit_Delay3_DSTATE_l = 0U;
	DW_tjattg_Unit_Delay2_DSTATE_cx = 0U;
	DW_tjattg_Unit_Delay1_DSTATE_j = 0U;
	DW_tjattg_Unit_Delay_DSTATE_l = 0U;
	DW_tjattg_Unit_Delay9_DSTATE = 0U;
	DW_tjattg_Unit_Delay8_DSTATE = 0U;
	DW_tjattg_Unit_Delay_DSTATE_fj = 0U;
	DW_tjattg_Unit_Delay1_DSTATE_p = 0U;
	DW_tjattg_Unit_Delay3_DSTATE_m = 0U;
	DW_tjattg_Unit_Delay5_DSTATE_j = 0U;
	DW_tjattg_Unit_Delay_DSTATE_az = 0U;
	DW_tjattg_Unit_Delay2_DSTATE_l = 0U;
	DW_tjattg_Unit_Delay2_DSTATE_f = 0U;
	DW_tjattg_Unit_Delay2_DSTATE_p = 0U;
	DW_tjattg_Unit_Delay_DSTATE_lt = 0U;
	DW_tjattg_Unit_Delay1_DSTATE_a = 0U;
	DW_tjattg_Unit_Delay1_DSTATE_b = 0U;
	DW_tjattg_Unit_Delay_DSTATE_fi = 0U;
	DW_tjattg_Unit_Delay_DSTATE_o0 = 0U;
	DW_tjattg_Unit_Delay_DSTATE_kt = 0U;
	DW_tjattg_Unit_Delay_DSTATE_g = 0U;
	DW_tjattg_Unit_Delay_DSTATE_na = 0U;
	DW_tjattg_Unit_Delay_DSTATE_nk = 0U;
	DW_tjattg_Unit_Delay_DSTATE = 0.F;
	DW_tjattg_Unit_Delay_DSTATE_e = 0.F;
	DW_tjattg_Unit_Delay_DSTATE_o = 0.F;
	DW_tjattg_Unit_Delay1_DSTATE = 0.F;
	DW_tjattg_Unit_Delay_DSTATE_n = 0.F;
	DW_tjattg_Unit_Delay_DSTATE_m = 0.F;
	DW_tjattg_Unit_Delay_DSTATE_d = 0.F;
	DW_tjattg_Unit_Delay_DSTATE_c = 0.F;
	DW_tjattg_Unit_Delay_DSTATE_a = 0.F;
	DW_tjattg_Unit_Delay_DSTATE_cg = 0.F;
	DW_tjattg_Unit_Delay_DSTATE_i = 0.F;
	DW_tjattg_Unit_Delay2_DSTATE = 0.F;
	DW_tjattg_Unit_Delay_DSTATE_b = 0.F;
	DW_tjattg_Unit_Delay_DSTATE_n5 = 0.F;
	DW_tjattg_Unit_Delay_DSTATE_oj = 0.F;
	DW_tjattg_Unit_Delay_DSTATE_f = 0.F;
	DW_tjattg_Unit_Delay_DSTATE_h = 0.F;
	DW_tjattg_Unit_Delay_DSTATE_p = 0.F;
	DW_tjattg_Unit_Delay_DSTATE_hs = 0.F;
	DW_tjattg_Unit_Delay_DSTATE_ie = 0.F;
	DW_tjattg_Unit_Delay_DSTATE_eg = 0.F;
	DW_tjattg_Unit_Delay_DSTATE_ij = 0.F;
	DW_tjattg_Unit_Delay_DSTATE_k = 0.F;
	DW_tjattg_Unit_Delay_DSTATE_h4 = 0.F;
	DW_tjattg_Unit_Delay_DSTATE_ba = 0.F;
	DW_tjattg_Unit_Delay2_DSTATE_n = 0.F;
	DW_tjattg_Unit_Delay_2_DSTATE = 0.F;
	DW_tjattg_Unit_Delay1_DSTATE_n = 0.F;
	DW_tjattg_Unit_Delay5_DSTATE = 0.F;
	DW_tjattg_Unit_Delay1_DSTATE_k = 0.F;
	DW_tjattg_Unit_Delay_3_DSTATE = 0.F;
	DW_tjattg_Unit_Delay3_DSTATE = 0.F;
	DW_tjattg_Unit_Delay_4_DSTATE = 0.F;
	DW_tjattg_Unit_Delay4_DSTATE = 0.F;
	DW_tjattg_Unit_Delay_5_DSTATE = 0.F;
	DW_tjattg_Unit_Delay5_DSTATE_g = 0.F;
	DW_tjattg_Unit_Delay_6_DSTATE = 0.F;
	DW_tjattg_Unit_Delay6_DSTATE = 0.F;
	DW_tjattg_Unit_Delay_1_DSTATE = 0.F;
	DW_tjattg_Unit_Delay2_DSTATE_h = 0.F;
	DW_tjattg_Unit_Delay_8_DSTATE = 0.F;
	DW_tjattg_Unit_Delay1_DSTATE_kv = 0.F;
	DW_tjattg_Unit_Delay_9_DSTATE = 0.F;
	DW_tjattg_Unit_Delay3_DSTATE_i = 0.F;
	DW_tjattg_Unit_Delay_10_DSTATE = 0.F;
	DW_tjattg_Unit_Delay4_DSTATE_b = 0.F;
	DW_tjattg_Unit_Delay_11_DSTATE = 0.F;
	DW_tjattg_Unit_Delay5_DSTATE_l = 0.F;
	DW_tjattg_Unit_Delay_12_DSTATE = 0.F;
	DW_tjattg_Unit_Delay6_DSTATE_a = 0.F;
	DW_tjattg_Unit_Delay_7_DSTATE = 0.F;
	DW_tjattg_Unit_Delay2_DSTATE_c = 0.F;
	DW_tjattg_Unit_Delay_14_DSTATE = 0.F;
	DW_tjattg_Unit_Delay1_DSTATE_d = 0.F;
	DW_tjattg_Unit_Delay_15_DSTATE = 0.F;
	DW_tjattg_Unit_Delay3_DSTATE_if = 0.F;
	DW_tjattg_Unit_Delay_16_DSTATE = 0.F;
	DW_tjattg_Unit_Delay4_DSTATE_a = 0.F;
	DW_tjattg_Unit_Delay_17_DSTATE = 0.F;
	DW_tjattg_Unit_Delay5_DSTATE_b = 0.F;
	DW_tjattg_Unit_Delay_18_DSTATE = 0.F;
	DW_tjattg_Unit_Delay6_DSTATE_f = 0.F;
	DW_tjattg_Unit_Delay_13_DSTATE = 0.F;
	DW_tjattg_Unit_Delay1_1_DSTATE = 0.F;
	DW_tjattg_Unit_Delay1_2_DSTATE = 0.F;
	DW_tjattg_Unit_Delay1_3_DSTATE = 0.F;
	DW_tjattg_Unit_Delay1_4_DSTATE = 0.F;
	DW_tjattg_Unit_Delay1_5_DSTATE = 0.F;
	DW_tjattg_Unit_Delay1_6_DSTATE = 0.F;
	DW_tjattg_Unit_Delay1_7_DSTATE = 0.F;
	DW_tjattg_Unit_Delay1_8_DSTATE = 0.F;
	DW_tjattg_Unit_Delay1_9_DSTATE = 0.F;
	DW_tjattg_Unit_Delay1_10_DSTATE = 0.F;
	DW_tjattg_Unit_Delay1_11_DSTATE = 0.F;
	DW_tjattg_Unit_Delay1_12_DSTATE = 0.F;
	DW_tjattg_Unit_Delay1_13_DSTATE = 0.F;
	DW_tjattg_Unit_Delay1_14_DSTATE = 0.F;
	DW_tjattg_Unit_Delay1_15_DSTATE = 0.F;
	DW_tjattg_Unit_Delay1_16_DSTATE = 0.F;
	DW_tjattg_Unit_Delay1_17_DSTATE = 0.F;
	DW_tjattg_Unit_Delay1_18_DSTATE = 0.F;
	
}
#define TJATTG_SenReset TJATTG_SenResetData
#endif

#undef	RUNNABLE_ID
#endif

#ifdef __cplusplus
}
#endif

