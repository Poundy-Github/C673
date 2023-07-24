/*===========================================================*
  Copyright (C) Continental AG
  All Rights Reserved
  PROJECT       : LCF100
  COMPONENT     : LCF
  TASK          : Sensor
  SUB-COMPONENT : ABPR
  MODULE        : ABPREP
  AUTHOR        : Module_AuxCodeGen
  VERSION       : 4.0

  Version Management Information
  $File: $
  $Revision: $
  $Author: $
  $Date: $
  $Log: $
**===========================================================*/
//! @file     Pse_ABPREP.h
//! @brief     (ABPREP) Module PSE Header.

#ifdef __cplusplus
extern "C"
{
#endif

/*-----------------------------------------------------*
   F U N C T I O N   D E F I N I T I O N S
**-----------------------------------------------------*/

#ifdef	RUNNABLE_ID

#if		RUNNABLE_ID == RUNNABLE_ID_ABPREP_SenReset
void ABPREP_SenResetData(void);
void ABPREP_SenReset(void)
{
	uint8 k1;
	
	ABPREP_SenResetData();
	
	BI_abprep__T_ABPREP_ReBnd_Type_enum = 0U;
	BI_abprep__T_ABPREP_ReBnd_Type_enum_b = 0U;
	DW_abprep_Unit_Delay_DSTATE_e = 0U;
	DW_abprep_Unit_Delay4_DSTATE_l = 0U;
	DW_abprep_Unit_Delay_DSTATE_al = 0U;
	DW_abprep_Unit_Delay_DSTATE_mn = 0U;
	DW_abprep_Unit_Delay_1_DSTATE_k = 0U;
	DW_abprep_Unit_Delay4_DSTATE_b = 0U;
	DW_abprep_Unit_Delay_DSTATE_k1 = 0U;
	DW_abprep_Unit_Delay_2_DSTATE_m = 0U;
	DW_abprep_Unit_Delay4_DSTATE_g = 0U;
	DW_abprep_Unit_Delay_DSTATE_p = 0U;
	DW_abprep_Unit_Delay_1_DSTATE_d = 0U;
	DW_abprep_Unit_Delay4_DSTATE_f = 0U;
	DW_abprep_Unit_Delay_DSTATE_kt = 0U;
	DW_abprep_Unit_Delay_2_DSTATE_g = 0U;
	DW_abprep_Unit_Delay5_DSTATE_e = 0U;
	DW_abprep_Unit_Delay3_DSTATE_o = 0U;
	DW_abprep_Unit_Delay4_DSTATE_bs = 0U;
	DW_abprep_Unit_Delay5_DSTATE_eq = 0U;
	DW_abprep_Unit_Delay2_DSTATE_e = 0U;
	DW_abprep_Unit_Delay3_DSTATE_b = 0U;
	DW_abprep_Unit_Delay4_DSTATE_d = 0U;
	DW_abprep_Unit_Delay5_DSTATE_l = 0U;
	DW_abprep_Unit_Delay2_DSTATE_ch = 0U;
	DW_abprep_Unit_Delay5_DSTATE_m = 0U;
	DW_abprep_Unit_Delay3_DSTATE_jb = 0U;
	DW_abprep_Unit_Delay4_DSTATE_j = 0U;
	DW_abprep_Unit_Delay5_DSTATE_k = 0U;
	DW_abprep_Unit_Delay2_DSTATE_i = 0U;
	DW_abprep_Unit_Delay3_DSTATE_a = 0U;
	DW_abprep_Unit_Delay4_DSTATE_i = 0U;
	DW_abprep_Unit_Delay5_DSTATE_h = 0U;
	DW_abprep_Unit_Delay2_DSTATE_j = 0U;
	DW_abprep_Unit_Delay4_DSTATE = 0.F;
	DW_abprep_Unit_Delay_DSTATE_c = 0.F;
	DW_abprep_Unit_Delay6_DSTATE = 0.F;
	DW_abprep_Unit_Delay2_DSTATE_o = 0.F;
	DW_abprep_Unit_Delay5_DSTATE = 0.F;
	DW_abprep_Unit_Delay1_DSTATE_g = 0.F;
	DW_abprep_Unit_Delay1_DSTATE_l = 0.F;
	DW_abprep_Unit_Delay6_DSTATE_e = 0.F;
	DW_abprep_Unit_Delay1_DSTATE_n = 0.F;
	DW_abprep_Unit_Delay9_DSTATE = 0.F;
	DW_abprep_Unit_Delay5_DSTATE_p = 0.F;
	DW_abprep_Unit_Delay8_DSTATE = 0.F;
	DW_abprep_Unit_Delay4_DSTATE_k = 0.F;
	DW_abprep_Unit_Delay7_DSTATE = 0.F;
	DW_abprep_Unit_Delay3_DSTATE_j = 0.F;
	DW_abprep_Unit_Delay2_DSTATE_n = 0.F;
	DW_abprep_Unit_Delay7_DSTATE_m = 0.F;
	DW_abprep_Unit_Delay1_DSTATE_p = 0.F;
	DW_abprep_Unit_Delay_DSTATE_k = 0.F;
	DW_abprep_Unit_Delay_DSTATE_f = 0.F;
	DW_abprep_Unit_Delay1_DSTATE_m = 0.F;
	DW_abprep_Unit_Delay1_DSTATE_o = 0.F;
	DW_abprep_Unit_Delay2_DSTATE_c = 0.F;
	DW_abprep_Unit_Delay2_DSTATE_ce = 0.F;
	DW_abprep_Unit_Delay1_DSTATE_f = 0.F;
	DW_abprep_Unit_Delay_DSTATE_l = 0.F;
	DW_abprep_Unit_Delay_DSTATE_cv = 0.F;
	DW_abprep_Unit_Delay1_DSTATE_j = 0.F;
	DW_abprep_Unit_Delay1_DSTATE_lx = 0.F;
	DW_abprep_Unit_Delay2_DSTATE_l = 0.F;
	DW_abprep_Unit_Delay2_DSTATE_b = 0.F;
	DW_abprep_Unit_Delay1_DSTATE_fa = 0.F;
	DW_abprep_Unit_Delay3_DSTATE_i = 0.F;
	DW_abprep_Unit_Delay2_DSTATE_p = 0.F;
	DW_abprep_Unit_Delay1_DSTATE_h = 0.F;
	DW_abprep_Unit_Delay_DSTATE_h = 0.F;
	DW_abprep_Unit_Delay_2_DSTATE = 0.F;
	DW_abprep_Unit_Delay_DSTATE_hx = 0.F;
	DW_abprep_Unit_Delay1_DSTATE_d = 0.F;
	DW_abprep_Unit_Delay_2_DSTATE_j = 0.F;
	DW_abprep_Unit_Delay_DSTATE_g = 0.F;
	DW_abprep_Unit_Delay1_DSTATE_op = 0.F;
	DW_abprep_Unit_Delay3_DSTATE_h = 0.F;
	DW_abprep_Unit_Delay2_DSTATE_ol = 0.F;
	DW_abprep_Unit_Delay1_DSTATE_fr = 0.F;
	DW_abprep_Unit_Delay_DSTATE_n5 = 0.F;
	DW_abprep_Unit_Delay_DSTATE_nv = 0.F;
	DW_abprep_Unit_Delay1_DSTATE_hm = 0.F;
	DW_abprep_Unit_Delay_DSTATE_o = 0.F;
	DW_abprep_Unit_Delay_1_DSTATE = 0.F;
	DW_abprep_Unit_Delay1_DSTATE_d5 = 0.F;
	DW_abprep_Unit_Delay_DSTATE_hb = 0.F;
	DW_abprep_Unit_Delay1_DSTATE_pf = 0.F;
	DW_abprep_Unit_Delay_DSTATE_a = 0.F;
	DW_abprep_Unit_Delay_1_DSTATE_e = 0.F;
	DW_abprep_Unit_Delay1_DSTATE_h4 = 0.F;
	
	for(k1 = 0; k1 < 2; k1++)
	{
		DW_abprep_Unit_Delay_DSTATE_cvn[k1] = 0U;
		DW_abprep_Unit_Delay4_DSTATE_e[k1] = 0U;
		DW_abprep_Unit_Delay_DSTATE_hs[k1] = 0U;
		DW_abprep_Unit_Delay1_DSTATE_os[k1] = 0U;
		DW_abprep_Unit_Delay2_DSTATE_bb[k1] = 0U;
		DW_abprep_Unit_Delay3_DSTATE_m[k1] = 0U;
		DW_abprep_Unit_Delay4_DSTATE_o[k1] = 0U;
		DW_abprep_Unit_Delay_DSTATE[k1] = 0.F;
		DW_abprep_Unit_Delay_DSTATE_m[k1] = 0.F;
		DW_abprep_Unit_Delay_DSTATE_n[k1] = 0.F;
		DW_abprep_Unit_Delay1_DSTATE[k1] = 0.F;
		DW_abprep_Unit_Delay3_DSTATE[k1] = 0.F;
		DW_abprep_Unit_Delay2_DSTATE[k1] = 0.F;
	}
	
}
#define ABPREP_SenReset ABPREP_SenResetData
#endif

#undef	RUNNABLE_ID
#endif

#ifdef __cplusplus
}
#endif

