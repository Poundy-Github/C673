/*===========================================================*
  Copyright (C) Continental AG
  All Rights Reserved
  PROJECT       : LCF100
  COMPONENT     : LCF
  TASK          : Sensor
  SUB-COMPONENT : ABPR
  MODULE        : ABPLBP
  AUTHOR        : Module_AuxCodeGen
  VERSION       : 4.0

  Version Management Information
  $File: $
  $Revision: $
  $Author: $
  $Date: $
  $Log: $
**===========================================================*/
//! @file     Pse_ABPLBP.h
//! @brief     (ABPLBP) Module PSE Header.

#ifdef __cplusplus
extern "C"
{
#endif

/*-----------------------------------------------------*
   F U N C T I O N   D E F I N I T I O N S
**-----------------------------------------------------*/

#ifdef	RUNNABLE_ID

#if		RUNNABLE_ID == RUNNABLE_ID_ABPLBP_SenReset
void ABPLBP_SenResetData(void);
void ABPLBP_SenReset(void)
{
	uint8 k1;
	
	ABPLBP_SenResetData();
	
	DW_abplbp_Unit_Delay2_DSTATE_l0 = 0U;
	DW_abplbp_Unit_Delay4_DSTATE_e = 0U;
	DW_abplbp_Unit_Delay2_DSTATE_p4 = 0U;
	DW_abplbp_Unit_Delay_DSTATE_lv = 0U;
	DW_abplbp_Unit_Delay_12_DSTATE = 0U;
	DW_abplbp_Unit_Delay5_DSTATE_dv = 0U;
	DW_abplbp_Unit_Delay3_DSTATE_o = 0U;
	DW_abplbp_Unit_Delay4_DSTATE_og = 0U;
	DW_abplbp_Unit_Delay_DSTATE_gg = 0U;
	DW_abplbp_Unit_Delay3_DSTATE_fw = 0U;
	DW_abplbp_Unit_Delay16_DSTATE = 0U;
	DW_abplbp_Unit_Delay1_DSTATE_o = 0U;
	DW_abplbp_Unit_Delay3_DSTATE_oq = 0U;
	DW_abplbp_Unit_Delay2_DSTATE_p4h = 0U;
	DW_abplbp_Unit_Delay1_DSTATE_ny = 0U;
	DW_abplbp_Unit_Delay1_DSTATE_nq = 0U;
	DW_abplbp_Unit_Delay_12_DSTATE_j = 0U;
	DW_abplbp_Unit_Delay5_DSTATE_lz = 0U;
	DW_abplbp_Unit_Delay3_DSTATE_l = 0U;
	DW_abplbp_Unit_Delay4_DSTATE_jm = 0U;
	DW_abplbp_Unit_Delay_DSTATE_ok = 0U;
	DW_abplbp_Unit_Delay3_DSTATE_fyd = 0U;
	DW_abplbp_Unit_Delay16_DSTATE_g = 0U;
	DW_abplbp_Unit_Delay1_DSTATE_pg = 0U;
	DW_abplbp_Unit_Delay3_DSTATE_oe = 0U;
	DW_abplbp_Unit_Delay2_DSTATE_ns = 0U;
	DW_abplbp_Unit_Delay9_DSTATE_d5 = 0U;
	DW_abplbp_Unit_Delay11_DSTATE_l = 0U;
	DW_abplbp_Unit_Delay12_DSTATE_b = 0U;
	DW_abplbp_Unit_Delay1_DSTATE_h1 = 0U;
	DW_abplbp_Unit_Delay3_DSTATE_i = 0U;
	DW_abplbp_Unit_Delay4_DSTATE_iv = 0U;
	DW_abplbp_Unit_Delay10_3_DSTATE = 0U;
	DW_abplbp_Unit_Delay10_4_DSTATE = 0U;
	DW_abplbp_Unit_Delay2_DSTATE_cc = 0U;
	DW_abplbp_Unit_Delay1_DSTATE_ng = 0U;
	DW_abplbp_Unit_Delay_DSTATE_gh = 0U;
	DW_abplbp_Unit_Delay10_3_DSTATE_k = 0U;
	DW_abplbp_Unit_Delay10_4_DSTATE_g = 0U;
	DW_abplbp_Unit_Delay1_DSTATE_kx = 0U;
	DW_abplbp_Unit_Delay_12_DSTATE_jd = 0U;
	DW_abplbp_Unit_Delay5_DSTATE_lg = 0U;
	DW_abplbp_Unit_Delay3_DSTATE_fa = 0U;
	DW_abplbp_Unit_Delay4_DSTATE_oa = 0U;
	DW_abplbp_Unit_Delay_DSTATE_fu = 0U;
	DW_abplbp_Unit_Delay3_DSTATE_lp = 0U;
	DW_abplbp_Unit_Delay_12_DSTATE_i = 0U;
	DW_abplbp_Unit_Delay5_DSTATE_ld = 0U;
	DW_abplbp_Unit_Delay3_DSTATE_oa = 0U;
	DW_abplbp_Unit_Delay4_DSTATE_n = 0U;
	DW_abplbp_Unit_Delay_DSTATE_lw = 0U;
	DW_abplbp_Unit_Delay3_DSTATE_m = 0U;
	DW_abplbp_Unit_Delay12_DSTATE_e = 0U;
	DW_abplbp_Unit_Delay11_DSTATE_f = 0U;
	DW_abplbp_Unit_Delay2_DSTATE_ky = 0U;
	DW_abplbp_Unit_Delay4_DSTATE_k = 0U;
	DW_abplbp_Unit_Delay16_DSTATE_k = 0U;
	DW_abplbp_Unit_Delay1_DSTATE_as = 0U;
	DW_abplbp_Unit_Delay12_DSTATE_e2 = 0U;
	DW_abplbp_Unit_Delay11_DSTATE_n = 0U;
	DW_abplbp_Unit_Delay3_DSTATE_pk = 0U;
	DW_abplbp_Unit_Delay2_DSTATE_f = 0U;
	DW_abplbp_Unit_Delay16_DSTATE_p = 0U;
	DW_abplbp_Unit_Delay1_DSTATE_jc = 0U;
	DW_abplbp_Unit_Delay3_DSTATE_n2 = 0U;
	DW_abplbp_Unit_Delay2_DSTATE_jw = 0U;
	DW_abplbp_Unit_Delay1_DSTATE_fn = 0U;
	DW_abplbp_Unit_Delay7_DSTATE_p = 0U;
	DW_abplbp_Unit_Delay6_DSTATE_f = 0U;
	DW_abplbp_Unit_Delay7_DSTATE_n = 0U;
	DW_abplbp_Unit_Delay6_DSTATE_m = 0U;
	DW_abplbp_Unit_Delay7_DSTATE_h = 0U;
	DW_abplbp_Unit_Delay6_DSTATE_k = 0U;
	DW_abplbp_Unit_Delay7_DSTATE_d = 0U;
	DW_abplbp_Unit_Delay6_DSTATE_p = 0U;
	DW_abplbp_Unit_Delay_10_DSTATE = 0U;
	DW_abplbp_Unit_Delay12_DSTATE_bq = 0U;
	DW_abplbp_Unit_Delay11_DSTATE_p = 0U;
	DW_abplbp_Unit_Delay12_DSTATE_c = 0U;
	DW_abplbp_Unit_Delay11_DSTATE_e = 0U;
	DW_abplbp_Unit_Delay14_DSTATE = 0U;
	DW_abplbp_Unit_Delay13_DSTATE_l = 0U;
	DW_abplbp_Unit_Delay14_DSTATE_i = 0U;
	DW_abplbp_Unit_Delay13_DSTATE_e = 0U;
	DW_abplbp_Unit_Delay14_DSTATE_o = 0U;
	DW_abplbp_Unit_Delay13_DSTATE_ls = 0U;
	DW_abplbp_Unit_Delay14_DSTATE_n = 0U;
	DW_abplbp_Unit_Delay13_DSTATE_d = 0U;
	DW_abplbp_Unit_Delay9_DSTATE_m = 0U;
	DW_abplbp_Unit_Delay9_DSTATE_g = 0U;
	DW_abplbp_Unit_Delay5_DSTATE_m = 0U;
	DW_abplbp_Unit_Delay_DSTATE_je = 0U;
	DW_abplbp_Unit_Delay_DSTATE_ch = 0U;
	DW_abplbp_Unit_Delay1_DSTATE_c = 0U;
	DW_abplbp_Unit_Delay5_DSTATE_g = 0U;
	DW_abplbp_Unit_Delay6_DSTATE_b = 0U;
	DW_abplbp_Unit_Delay_DSTATE_fk = 0U;
	DW_abplbp_Unit_Delay_DSTATE_at = 0U;
	DW_abplbp_Unit_Delay1_DSTATE_cz = 0U;
	DW_abplbp_Unit_Delay1_DSTATE_gv = 0U;
	DW_abplbp_Unit_Delay6_DSTATE_n = 0U;
	DW_abplbp_Unit_Delay_DSTATE_bt = 0U;
	DW_abplbp_Unit_Delay_DSTATE_ia = 0U;
	DW_abplbp_Unit_Delay1_DSTATE_pm = 0U;
	DW_abplbp_Unit_Delay1_DSTATE_og = 0U;
	DW_abplbp_Unit_Delay_DSTATE_m5 = 0U;
	DW_abplbp_Unit_Delay_DSTATE_hk = 0U;
	DW_abplbp_Unit_Delay_DSTATE_df = 0U;
	DW_abplbp_Unit_Delay2_DSTATE_pa = 0U;
	DW_abplbp_Unit_Delay4_DSTATE_k1 = 0U;
	DW_abplbp_Unit_Delay6_DSTATE_om = 0U;
	DW_abplbp_Unit_Delay_DSTATE_da = 0U;
	DW_abplbp_Unit_Delay2_DSTATE_d = 0U;
	DW_abplbp_Unit_Delay4_DSTATE_pj = 0U;
	DW_abplbp_Unit_Delay6_DSTATE_g = 0U;
	DW_abplbp_Unit_Delay_DSTATE_nv = 0U;
	DW_abplbp_Unit_Delay2_DSTATE_dn = 0U;
	DW_abplbp_Unit_Delay4_DSTATE_iq = 0U;
	DW_abplbp_Unit_Delay6_DSTATE_ha = 0U;
	DW_abplbp_Unit_Delay4_DSTATE_ac = 0U;
	DW_abplbp_Unit_Delay1_DSTATE_jq = 0U;
	DW_abplbp_Unit_Delay1_DSTATE_dp = 0U;
	DW_abplbp_Unit_Delay_DSTATE_nn = 0U;
	DW_abplbp_Unit_Delay1_DSTATE_c5 = 0U;
	DW_abplbp_Unit_Delay4_DSTATE_g = 0U;
	DW_abplbp_Unit_Delay3_DSTATE_k = 0U;
	DW_abplbp_Unit_Delay5_DSTATE_k = 0U;
	DW_abplbp_Unit_Delay1_DSTATE_gd = 0U;
	DW_abplbp_Unit_Delay_DSTATE_jm = 0U;
	DW_abplbp_Unit_Delay1_DSTATE_c4 = 0U;
	DW_abplbp_Unit_Delay4_DSTATE_jw = 0U;
	DW_abplbp_Unit_Delay3_DSTATE_m3 = 0U;
	DW_abplbp_headingStepSafetyDebounceRi_bool = 0U;
	DW_abplbp_crvStepSafetyDebounceRi_bool = 0U;
	DW_abplbp_Unit_Delay5_DSTATE = 0.F;
	DW_abplbp_Unit_Delay3_DSTATE = 0.F;
	DW_abplbp_Unit_Delay3_DSTATE_c = 0.F;
	DW_abplbp_Unit_Delay1_DSTATE_l = 0.F;
	DW_abplbp_Unit_Delay_DSTATE_g = 0.F;
	DW_abplbp_Unit_Delay4_9_DSTATE = 0.F;
	DW_abplbp_Unit_Delay1_DSTATE_m = 0.F;
	DW_abplbp_Unit_Delay_17_DSTATE = 0.F;
	DW_abplbp_Unit_Delay1_DSTATE_d = 0.F;
	DW_abplbp_Unit_Delay4_3_DSTATE = 0.F;
	DW_abplbp_Unit_Delay4_6_DSTATE = 0.F;
	DW_abplbp_Unit_Delay4_8_DSTATE = 0.F;
	DW_abplbp_Unit_Delay4_9_DSTATE_i = 0.F;
	DW_abplbp_Unit_Delay4_16_DSTATE = 0.F;
	DW_abplbp_Unit_Delay4_17_DSTATE = 0.F;
	DW_abplbp_Unit_Delay_DSTATE_i = 0.F;
	DW_abplbp_Unit_Delay17_DSTATE = 0.F;
	DW_abplbp_Unit_Delay18_DSTATE = 0.F;
	DW_abplbp_Unit_Delay_17_DSTATE_a = 0.F;
	DW_abplbp_Unit_Delay1_DSTATE_f = 0.F;
	DW_abplbp_Unit_Delay4_3_DSTATE_n = 0.F;
	DW_abplbp_Unit_Delay4_6_DSTATE_j = 0.F;
	DW_abplbp_Unit_Delay4_8_DSTATE_h = 0.F;
	DW_abplbp_Unit_Delay4_9_DSTATE_b = 0.F;
	DW_abplbp_Unit_Delay4_16_DSTATE_i = 0.F;
	DW_abplbp_Unit_Delay4_17_DSTATE_b = 0.F;
	DW_abplbp_Unit_Delay_DSTATE_f = 0.F;
	DW_abplbp_Unit_Delay17_DSTATE_g = 0.F;
	DW_abplbp_Unit_Delay18_DSTATE_i = 0.F;
	DW_abplbp_Unit_Delay_DSTATE_dz = 0.F;
	DW_abplbp_Unit_Delay2_DSTATE_c = 0.F;
	DW_abplbp_Unit_Delay1_DSTATE_fm = 0.F;
	DW_abplbp_Unit_Delay_DSTATE_h = 0.F;
	DW_abplbp_Unit_Delay2_DSTATE_i = 0.F;
	DW_abplbp_Unit_Delay1_DSTATE_g = 0.F;
	DW_abplbp_Unit_Delay_DSTATE_d4 = 0.F;
	DW_abplbp_Unit_Delay1_DSTATE_dw = 0.F;
	DW_abplbp_Unit_Delay5_DSTATE_l = 0.F;
	DW_abplbp_Unit_Delay6_DSTATE = 0.F;
	DW_abplbp_Unit_Delay1_DSTATE_a = 0.F;
	DW_abplbp_Unit_Delay_17_DSTATE_j = 0.F;
	DW_abplbp_Unit_Delay1_DSTATE_g3 = 0.F;
	DW_abplbp_Unit_Delay1_DSTATE_ft = 0.F;
	DW_abplbp_Unit_Delay_17_DSTATE_i = 0.F;
	DW_abplbp_Unit_Delay1_DSTATE_j = 0.F;
	DW_abplbp_Unit_Delay6_DSTATE_o = 0.F;
	DW_abplbp_Unit_Delay9_DSTATE = 0.F;
	DW_abplbp_Unit_Delay6_DSTATE_h = 0.F;
	DW_abplbp_Unit_Delay3_DSTATE_gm = 0.F;
	DW_abplbp_Unit_Delay4_3_DSTATE_c = 0.F;
	DW_abplbp_Unit_Delay4_6_DSTATE_k = 0.F;
	DW_abplbp_Unit_Delay4_8_DSTATE_m = 0.F;
	DW_abplbp_Unit_Delay4_9_DSTATE_g = 0.F;
	DW_abplbp_Unit_Delay4_16_DSTATE_g = 0.F;
	DW_abplbp_Unit_Delay4_17_DSTATE_n = 0.F;
	DW_abplbp_Unit_Delay17_DSTATE_b = 0.F;
	DW_abplbp_Unit_Delay18_DSTATE_k = 0.F;
	DW_abplbp_Unit_Delay9_DSTATE_h = 0.F;
	DW_abplbp_Unit_Delay5_DSTATE_de = 0.F;
	DW_abplbp_Unit_Delay_DSTATE_o = 0.F;
	DW_abplbp_Unit_Delay4_3_DSTATE_b = 0.F;
	DW_abplbp_Unit_Delay4_6_DSTATE_c = 0.F;
	DW_abplbp_Unit_Delay4_8_DSTATE_i = 0.F;
	DW_abplbp_Unit_Delay4_9_DSTATE_k = 0.F;
	DW_abplbp_Unit_Delay4_16_DSTATE_h = 0.F;
	DW_abplbp_Unit_Delay4_17_DSTATE_j = 0.F;
	DW_abplbp_Unit_Delay_DSTATE_a = 0.F;
	DW_abplbp_Unit_Delay17_DSTATE_h = 0.F;
	DW_abplbp_Unit_Delay18_DSTATE_a = 0.F;
	DW_abplbp_Unit_Delay4_DSTATE = 0.F;
	DW_abplbp_Unit_Delay4_DSTATE_j = 0.F;
	DW_abplbp_Unit_Delay4_DSTATE_o = 0.F;
	DW_abplbp_Unit_Delay4_DSTATE_a = 0.F;
	DW_abplbp_Unit_Delay3_2_DSTATE = 0.F;
	DW_abplbp_Unit_Delay9_DSTATE_k = 0.F;
	DW_abplbp_Unit_Delay9_DSTATE_d = 0.F;
	DW_abplbp_Unit_Delay15_DSTATE = 0.F;
	DW_abplbp_Unit_Delay15_DSTATE_g = 0.F;
	DW_abplbp_Unit_Delay15_DSTATE_m = 0.F;
	DW_abplbp_Unit_Delay15_DSTATE_a = 0.F;
	DW_abplbp_Unit_Delay1_9_DSTATE = 0.F;
	DW_abplbp_Unit_Delay1_DSTATE_p = 2.5F;
	DW_abplbp_Unit_Delay2_DSTATE_px = 0.F;
	DW_abplbp_Unit_Delay2_DSTATE_l = 0.12F;
	DW_abplbp_Unit_Delay1_DSTATE_ew = 3.5F;
	DW_abplbp_Unit_Delay1_7_DSTATE = 0.F;
	DW_abplbp_Unit_Delay1_8_DSTATE = 0.F;
	DW_abplbp_Unit_Delay1_10_DSTATE = 0.F;
	DW_abplbp_Unit_Delay1_DSTATE_n = 0.F;
	DW_abplbp_Unit_Delay2_DSTATE_m = 0.F;
	DW_abplbp_Unit_Delay_DSTATE_gf = 0.F;
	DW_abplbp_Unit_Delay_DSTATE_d2 = 0.F;
	DW_abplbp_Unit_Delay1_DSTATE_k = 0.F;
	DW_abplbp_Unit_Delay1_DSTATE_ei = 0.F;
	DW_abplbp_Unit_Delay_DSTATE_hm = 0.F;
	DW_abplbp_Unit_Delay1_DSTATE_mc = 0.F;
	DW_abplbp_Unit_Delay_DSTATE_l = 0.F;
	DW_abplbp_Unit_Delay2_DSTATE_g = 0.F;
	DW_abplbp_Unit_Delay3_DSTATE_b = 0.F;
	DW_abplbp_Unit_Delay1_DSTATE_m2 = 0.F;
	DW_abplbp_Unit_Delay1_DSTATE_ly = 0.F;
	DW_abplbp_Unit_Delay_DSTATE_cl = 0.F;
	DW_abplbp_Unit_Delay3_DSTATE_f = 0.F;
	DW_abplbp_Unit_Delay1_DSTATE_i = 0.F;
	DW_abplbp_Unit_Delay5_DSTATE_h = 0.F;
	DW_abplbp_Unit_Delay3_DSTATE_fy = 0.F;
	DW_abplbp_Unit_Delay7_DSTATE = 0.F;
	DW_abplbp_Unit_Delay2_DSTATE_mq = 0.F;
	DW_abplbp_Unit_Delay1_DSTATE_im = 0.F;
	DW_abplbp_Unit_Delay1_DSTATE_ee = 0.F;
	DW_abplbp_Unit_Delay3_DSTATE_d = 0.F;
	DW_abplbp_Unit_Delay_DSTATE_n = 0.F;
	DW_abplbp_Unit_Delay2_DSTATE_j = 0.F;
	DW_abplbp_Unit_Delay1_DSTATE_lo = 0.F;
	DW_abplbp_Unit_Delay3_DSTATE_a = 0.F;
	DW_abplbp_Unit_Delay5_DSTATE_a = 0.F;
	DW_abplbp_Unit_Delay7_DSTATE_l = 0.F;
	DW_abplbp_Unit_Delay1_DSTATE_b = 0.F;
	DW_abplbp_Unit_Delay1_DSTATE_dv = 0.F;
	DW_abplbp_Unit_Delay3_DSTATE_fk = 0.F;
	DW_abplbp_Unit_Delay_DSTATE_k1 = 0.F;
	DW_abplbp_Unit_Delay2_DSTATE_nb = 0.F;
	DW_abplbp_Unit_Delay1_DSTATE_hk = 0.F;
	DW_abplbp_Unit_Delay3_DSTATE_no = 0.F;
	DW_abplbp_Unit_Delay5_DSTATE_p = 0.F;
	DW_abplbp_Unit_Delay7_DSTATE_j = 0.F;
	DW_abplbp_Unit_Delay_DSTATE_dm = 0.F;
	DW_abplbp_Unit_Delay_DSTATE_ac = 0.F;
	DW_abplbp_Unit_Delay4_DSTATE_f = 0.F;
	DW_abplbp_Unit_Delay_DSTATE_oe = 0.F;
	DW_abplbp_Unit_Delay6_DSTATE_c = 0.F;
	DW_abplbp_Unit_Delay1_DSTATE_bq = 0.F;
	DW_abplbp_Unit_Delay7_DSTATE_k = 0.F;
	DW_abplbp_Unit_Delay2_DSTATE_k = 0.F;
	DW_abplbp_Unit_Delay4_DSTATE_p = 0.F;
	DW_abplbp_Unit_Delay_DSTATE_gm = 0.F;
	DW_abplbp_Unit_Delay6_DSTATE_e = 0.F;
	DW_abplbp_Unit_Delay1_DSTATE_hn = 0.F;
	DW_abplbp_Unit_Delay7_DSTATE_jd = 0.F;
	DW_abplbp_Unit_Delay2_DSTATE_gg = 0.F;
	
	for(k1 = 0; k1 < 2; k1++)
	{
		BI_abplbp_LogicalOperator_kw[k1] = 0U;
		DW_abplbp_Unit_Delay4_DSTATE_l[k1] = 0U;
		DW_abplbp_Unit_Delay_DSTATE_oq[k1] = 0U;
		DW_abplbp_Unit_Delay4_DSTATE_oq[k1] = 0U;
		DW_abplbp_Unit_Delay4_DSTATE_lk[k1] = 0U;
		DW_abplbp_Unit_Delay2_DSTATE_bv[k1] = 0U;
		DW_abplbp_Unit_Delay4_DSTATE_a2[k1] = 0U;
		DW_abplbp_Unit_Delay1_DSTATE_mx[k1] = 0U;
		DW_abplbp_Unit_Delay_DSTATE_cj[k1] = 0U;
		DW_abplbp_Unit_Delay2_DSTATE_b2[k1] = 0U;
		DW_abplbp_Unit_Delay3_DSTATE_ix[k1] = 0U;
		DW_abplbp_Unit_Delay1_DSTATE_dvo[k1] = 0U;
		DW_abplbp_Unit_Delay_DSTATE_pj[k1] = 0U;
		DW_abplbp_Unit_Delay1_DSTATE_ob[k1] = 0U;
		DW_abplbp_Unit_Delay2_DSTATE_ko[k1] = 0U;
		DW_abplbp_Unit_Delay3_DSTATE_px[k1] = 0U;
		DW_abplbp_Unit_Delay4_DSTATE_m[k1] = 0U;
		DW_abplbp_Unit_Delay_DSTATE_oh[k1] = 0U;
		DW_abplbp_Unit_Delay_DSTATE_b[k1] = 0U;
		DW_abplbp_unitDelay_CheckLaneBridging_ER[k1] = 0U;
		DW_abplbp_unitDelay_CheckLaneBridging_EF_timeBridging[k1] = 0U;
		DW_abplbp_Unit_Delay1_DSTATE_oz[k1] = 0U;
		DW_abplbp_Unit_Delay_DSTATE_mt[k1] = 0U;
		DW_abplbp_unitDelay_CheckLaneBridging_EF_LnBndValid[k1] = 0U;
		DW_abplbp_unitDelay_CheckLaneBrid_PrevLaneBridged[k1] = 0U;
		DW_abplbp_unitDelay_CheckLaneBridging_ER_d[k1] = 0U;
		DW_abplbp_unitDelay_CheckLaneBridging_EF_timeBridging_j[k1] = 0U;
		DW_abplbp_Unit_Delay_DSTATE[k1] = 0.F;
		DW_abplbp_Unit_Delay_DSTATE_c[k1] = 0.F;
		DW_abplbp_Unit_Delay_DSTATE_j[k1] = 0.F;
		DW_abplbp_Unit_Delay1_DSTATE[k1] = 0.F;
		DW_abplbp_Unit_Delay3_DSTATE_p[k1] = 0.F;
		DW_abplbp_Unit_Delay2_DSTATE[k1] = 0.F;
		DW_abplbp_Unit_Delay_DSTATE_p[k1] = 0.F;
		DW_abplbp_Unit_Delay_DSTATE_d[k1] = 0.F;
		DW_abplbp_Unit_Delay_DSTATE_m[k1] = 0.F;
		DW_abplbp_Unit_Delay1_DSTATE_h[k1] = 0.F;
		DW_abplbp_Unit_Delay3_DSTATE_g[k1] = 0.F;
		DW_abplbp_Unit_Delay2_DSTATE_b[k1] = 0.F;
		DW_abplbp_Unit_Delay_DSTATE_ca[k1] = 0.F;
		DW_abplbp_Unit_Delay_DSTATE_jl[k1] = 0.F;
		DW_abplbp_Unit_Delay1_DSTATE_e[k1] = 0.F;
		DW_abplbp_Unit_Delay3_DSTATE_n[k1] = 0.F;
		DW_abplbp_Unit_Delay2_DSTATE_n[k1] = 0.F;
		DW_abplbp_Unit_Delay3_DSTATE_ch[k1] = 0.F;
		DW_abplbp_Unit_Delay_DSTATE_k[k1] = 0.F;
		DW_abplbp_Unit_Delay1_DSTATE_mo[k1] = 0.F;
		DW_abplbp_Unit_Delay_DSTATE_fl[k1] = 0.F;
		DW_abplbp_Unit_Delay2_DSTATE_p[k1] = 0.F;
		DW_abplbp_Unit_Delay1_DSTATE_jg[k1] = 0.F;
		DW_abplbp_Unit_Delay_DSTATE_jb[k1] = 0.F;
		DW_abplbp_Unit_Delay_DSTATE_h0[k1] = 0.F;
		DW_abplbp_Unit_Delay4_DSTATE_i[k1] = 0.F;
		DW_abplbp_Unit_Delay_DSTATE_mz[k1] = 0.F;
		DW_abplbp_Unit_Delay_DSTATE_jr[k1] = 0.F;
	}
	
	for(k1 = 0; k1 < 20; k1++)
	{
		BI_abplbp_Assignment[k1] = 0.F;
		BI_abplbp_Assignment_m[k1] = 0.F;
		BI_abplbp_Assignment_h[k1] = 0.F;
		BI_abplbp_Assignment_g[k1] = 0.F;
		BI_abplbp_Assignment_o[k1] = 0.F;
		BI_abplbp_Assignment_i[k1] = 0.F;
		BI_abplbp_Assignment_d[k1] = 0.F;
		BI_abplbp_Assignment_ml[k1] = 0.F;
		BI_abplbp_Assignment_b[k1] = 0.F;
		BI_abplbp_Assignment_mj[k1] = 0.F;
		BI_abplbp_Assignment_c[k1] = 0.F;
		BI_abplbp_Assignment_a[k1] = 0.F;
		BI_abplbp_Assignment_im[k1] = 0.F;
		BI_abplbp_Assignment_f[k1] = 0.F;
		BI_abplbp_Assignment_mt[k1] = 0.F;
		BI_abplbp_Assignment_dt[k1] = 0.F;
		BI_abplbp_Assignment_a2[k1] = 0.F;
		BI_abplbp_Assignment_ch[k1] = 0.F;
		BI_abplbp_Assignment_an[k1] = 0.F;
		BI_abplbp_Assignment_i0[k1] = 0.F;
		BI_abplbp_Assignment_h1[k1] = 0.F;
		BI_abplbp_Assignment_dr[k1] = 0.F;
		BI_abplbp_Assignment_e[k1] = 0.F;
		BI_abplbp_Assignment_gj[k1] = 0.F;
		BI_abplbp_Assignment_is[k1] = 0.F;
		BI_abplbp_Assignment_mr[k1] = 0.F;
		BI_abplbp_Assignment_g5[k1] = 0.F;
		BI_abplbp_Assignment_a3[k1] = 0.F;
		BI_abplbp_Assignment_fz[k1] = 0.F;
		BI_abplbp_Assignment_p[k1] = 0.F;
	}
	
	for(k1 = 0; k1 < 4; k1++)
	{
		DW_abplbp_Unit_Delay5_DSTATE_f[k1] = 0.F;
		DW_abplbp_Unit_Delay5_DSTATE_d[k1] = 0.F;
		DW_abplbp_Unit_Delay1_DSTATE_kv[k1] = 0.F;
		DW_abplbp_Unit_Delay11_DSTATE[k1] = 0.F;
		DW_abplbp_Unit_Delay12_DSTATE[k1] = 0.F;
		DW_abplbp_Unit_Delay13_DSTATE[k1] = 0.F;
		DW_abplbp_Unit_Delay2_DSTATE_e[k1] = 0.F;
		DW_abplbp_Unit_Delay3_DSTATE_e[k1] = 0.F;
		DW_abplbp_Unit_Delay4_DSTATE_j3[k1] = 0.F;
		DW_abplbp_Unit_Delay1_DSTATE_ak[k1] = 0.F;
		DW_abplbp_Unit_Delay11_DSTATE_m[k1] = 0.F;
		DW_abplbp_Unit_Delay12_DSTATE_a[k1] = 0.F;
		DW_abplbp_Unit_Delay13_DSTATE_j[k1] = 0.F;
		DW_abplbp_Unit_Delay2_DSTATE_ce[k1] = 0.F;
		DW_abplbp_Unit_Delay3_DSTATE_j[k1] = 0.F;
		DW_abplbp_Unit_Delay4_DSTATE_b[k1] = 0.F;
	}
	
}
#define ABPLBP_SenReset ABPLBP_SenResetData
#endif

#undef	RUNNABLE_ID
#endif

#ifdef __cplusplus
}
#endif

