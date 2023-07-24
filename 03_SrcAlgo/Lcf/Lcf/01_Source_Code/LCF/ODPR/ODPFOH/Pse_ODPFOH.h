/*===========================================================*
  Copyright (C) Continental AG
  All Rights Reserved
  PROJECT       : LCF100
  COMPONENT     : LCF
  TASK          : Sensor
  SUB-COMPONENT : ODPR
  MODULE        : ODPFOH
  AUTHOR        : Module_AuxCodeGen
  VERSION       : 4.0

  Version Management Information
  $File: $
  $Revision: 1.4 $
  $Author: Nastasa, Elena (uidt4846) $
  $Date: 2019/09/13 10:32:22CEST $
  $Log: Pse_ODPFOH.h  $
  Revision 1.4 2019/09/13 10:32:22CEST Nastasa, Elena (uidt4846) 
  Update LCF files for Sprint 10.08
**===========================================================*/
//! @file     Pse_ODPFOH.h
//! @brief     (ODPFOH) Module PSE Header.

#ifdef __cplusplus
extern "C"
{
#endif

/*-----------------------------------------------------*
   F U N C T I O N   D E F I N I T I O N S
**-----------------------------------------------------*/

#ifdef	RUNNABLE_ID

#if		RUNNABLE_ID == RUNNABLE_ID_ODPFOH_SenReset
void ODPFOH_SenResetData(void);
void ODPFOH_SenReset(void)
{
	
	ODPFOH_SenResetData();
	
	BI_odpfoh_LogicalOperator_m = 0U;
	BI_odpfoh_LogicalOperator_k = 0U;
	DW_odpfoh_Unit_Delay2_DSTATE_f = 0U;
	DW_odpfoh_Unit_Delay_DSTATE_bc = 0U;
	DW_odpfoh_Unit_Delay_DSTATE_d = 0U;
	DW_odpfoh_Unit_Delay_DSTATE_c = 0U;
	DW_odpfoh_Unit_Delay4_DSTATE_g = 1U;
	DW_odpfoh_Unit_Delay4_DSTATE_b = 0U;
	DW_odpfoh_Unit_Delay4_DSTATE_e = 0U;
	DW_odpfoh_Unit_Delay3_DSTATE_d = 0U;
	DW_odpfoh_Unit_Delay_DSTATE_e = 0U;
	DW_odpfoh_Unit_Delay1_DSTATE_d = 0U;
	DW_odpfoh_Unit_Delay4_DSTATE_gn = 1U;
	DW_odpfoh_Unit_Delay2_DSTATE_ow = 1U;
	DW_odpfoh_Unit_Delay1_DSTATE_e0 = 1U;
	DW_odpfoh_Unit_Delay_DSTATE_jh = 1U;
	DW_odpfoh_Unit_Delay1_DSTATE_ej = 1U;
	DW_odpfoh_Unit_Delay2_DSTATE_jw = 0U;
	DW_odpfoh_Unit_Delay1_DSTATE_cw = 0U;
	DW_odpfoh_Unit_Delay5_DSTATE_m = 0U;
	DW_odpfoh_Unit_Delay_DSTATE_k = 0U;
	DW_odpfoh_Unit_Delay3_DSTATE_n = 1U;
	DW_odpfoh_Unit_Delay1_DSTATE_f = 0U;
	DW_odpfoh_Unit_Delay_DSTATE_i = 1U;
	DW_odpfoh_Unit_Delay1_DSTATE_ci = 0U;
	DW_odpfoh_Unit_Delay2_DSTATE_a = 0U;
	DW_odpfoh_Unit_Delay1_DSTATE_k = 0U;
	DW_odpfoh_Unit_Delay3_DSTATE_es = 0U;
	DW_odpfoh_Unit_Delay1_DSTATE_p = 0U;
	DW_odpfoh_Unit_Delay2_DSTATE_jl = 0U;
	DW_odpfoh_Unit_Delay1_DSTATE_d5 = 0U;
	DW_odpfoh_Unit_Delay2_DSTATE_ay = 0U;
	DW_odpfoh_Unit_Delay1_DSTATE_if = 0U;
	DW_odpfoh_Unit_Delay2_DSTATE_ob = 0U;
	DW_odpfoh_Unit_Delay1_DSTATE_kx = 0U;
	DW_odpfoh_Unit_Delay2_DSTATE_ap = 0U;
	DW_odpfoh_Unit_Delay_DSTATE_gw = 1U;
	DW_odpfoh_Unit_Delay1_DSTATE_b3 = 0U;
	DW_odpfoh_Unit_Delay2_DSTATE_m = 0U;
	DW_odpfoh_Unit_Delay5_DSTATE_l = 1U;
	DW_odpfoh_Unit_Delay1_DSTATE_l2 = 0U;
	DW_odpfoh_Unit_Delay_DSTATE = 96.0F;
	DW_odpfoh_Unit_Delay_DSTATE_b = 0.F;
	DW_odpfoh_Unit_Delay_DSTATE_h = 0.F;
	DW_odpfoh_Unit_Delay_DSTATE_g = 0.F;
	DW_odpfoh_Unit_Delay_DSTATE_j = 0.F;
	DW_odpfoh_Unit_Delay2_DSTATE = 0.F;
	DW_odpfoh_Unit_Delay3_DSTATE = 0.F;
	DW_odpfoh_Unit_Delay1_DSTATE = 0.F;
	DW_odpfoh_Unit_Delay2_DSTATE_e = 0.F;
	DW_odpfoh_Unit_Delay4_DSTATE = 0.F;
	DW_odpfoh_Unit_Delay5_DSTATE = 0.F;
	DW_odpfoh_Unit_Delay6_DSTATE = 0.F;
	DW_odpfoh_Unit_Delay1_DSTATE_b = 0.F;
	DW_odpfoh_Unit_Delay2_DSTATE_b = 0.F;
	DW_odpfoh_Unit_Delay1_DSTATE_j = 0.F;
	DW_odpfoh_Unit_Delay1_DSTATE_c = 0.F;
	DW_odpfoh_Unit_Delay5_DSTATE_i = 0.F;
	DW_odpfoh_Unit_Delay3_DSTATE_p = 1.0F;
	DW_odpfoh_Unit_Delay2_DSTATE_j = 0.F;
	DW_odpfoh_Unit_Delay3_DSTATE_j = 0.F;
	DW_odpfoh_Unit_Delay1_DSTATE_a = 0.F;
	DW_odpfoh_Unit_Delay_DSTATE_f = 1.0F;
	DW_odpfoh_Unit_Delay_DSTATE_a = 0.F;
	DW_odpfoh_Unit_Delay2_DSTATE_bl = 0.F;
	DW_odpfoh_Unit_Delay1_DSTATE_e = 0.F;
	DW_odpfoh_Unit_Delay1_DSTATE_l = 0.F;
	DW_odpfoh_Unit_Delay1_DSTATE_jc = 0.F;
	DW_odpfoh_Unit_Delay2_DSTATE_h = 0.F;
	DW_odpfoh_Unit_Delay1_DSTATE_o = 0.F;
	DW_odpfoh_Unit_Delay1_DSTATE_ek = 0.F;
	DW_odpfoh_Unit_Delay_DSTATE_n = 0.F;
	DW_odpfoh_Unit_Delay2_DSTATE_ho = 0.F;
	DW_odpfoh_Unit_Delay2_DSTATE_o = 0.F;
	DW_odpfoh_Unit_Delay2_DSTATE_k = 0.F;
	DW_odpfoh_Unit_Delay1_DSTATE_n = 0.F;
	DW_odpfoh_Unit_Delay1_DSTATE_i = 0.F;
	DW_odpfoh_Unit_Delay2_DSTATE_jh = 0.F;
	DW_odpfoh_Unit_Delay1_DSTATE_cm = 0.F;
	DW_odpfoh_Unit_Delay2_DSTATE_ko = 0.F;
	DW_odpfoh_Unit_Delay2_DSTATE_i = 0.F;
	DW_odpfoh_Unit_Delay2_DSTATE_ki = 0.F;
	DW_odpfoh_Unit_Delay1_DSTATE_h = 0.F;
	DW_odpfoh_Unit_Delay1_DSTATE_g = 0.F;
	DW_odpfoh_Unit_Delay2_DSTATE_kk = 0.F;
	DW_odpfoh_Unit_Delay2_DSTATE_k3 = 0.F;
	DW_odpfoh_Unit_Delay1_DSTATE_g3 = 0.F;
	DW_odpfoh_Unit_Delay3_DSTATE_e = 0.F;
	DW_odpfoh_Unit_Delay2_DSTATE_kq = 0.F;
	DW_odpfoh_Unit_Delay1_DSTATE_is = 0.F;
	DW_odpfoh_Unit_Delay2_DSTATE_c = 0.F;
	
}
#define ODPFOH_SenReset ODPFOH_SenResetData
#endif

#undef	RUNNABLE_ID
#endif

#ifdef __cplusplus
}
#endif

