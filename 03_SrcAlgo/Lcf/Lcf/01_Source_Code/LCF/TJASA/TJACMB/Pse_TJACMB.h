/*===========================================================*
  Copyright (C) Continental AG
  All Rights Reserved
  PROJECT       : LCF100
  COMPONENT     : LCF
  TASK          : Sensor
  SUB-COMPONENT : TJASA
  MODULE        : TJACMB
  AUTHOR        : Module_AuxCodeGen
  VERSION       : 4.0

  Version Management Information
  $File: $
  $Revision: 1.3 $
  $Author: Nastasa, Elena (uidt4846) $
  $Date: 2019/09/13 10:33:54CEST $
  $Log: Pse_TJACMB.h  $
  Revision 1.3 2019/09/13 10:33:54CEST Nastasa, Elena (uidt4846) 
  Update LCF files for Sprint 10.08
**===========================================================*/
//! @file     Pse_TJACMB.h
//! @brief     (TJACMB) Module PSE Header.

#ifdef __cplusplus
extern "C"
{
#endif

/*-----------------------------------------------------*
   F U N C T I O N   D E F I N I T I O N S
**-----------------------------------------------------*/

#ifdef	RUNNABLE_ID

#if		RUNNABLE_ID == RUNNABLE_ID_TJACMB_SenReset
void TJACMB_SenResetData(void);
void TJACMB_SenReset(void)
{
	
	TJACMB_SenResetData();
	
	BI_tjacmb_CombinedMode_nu = 0U;
	DW_tjacmb_Unit_Delay_DSTATE_gs = 0U;
	DW_tjacmb_Unit_Delay1_DSTATE_c = 0U;
	DW_tjacmb_Unit_Delay2_DSTATE_l = 0U;
	DW_tjacmb_Unit_Delay2_DSTATE_dm = 0U;
	DW_tjacmb_Unit_Delay_DSTATE_fr = 0U;
	DW_tjacmb_Unit_Delay1_DSTATE_k = 0U;
	DW_tjacmb_Unit_Delay1_DSTATE_ch = 0U;
	DW_tjacmb_Unit_Delay2_DSTATE_g = 0U;
	DW_tjacmb_Unit_Delay_DSTATE_p = 0U;
	DW_tjacmb_Unit_Delay1_DSTATE_i = 0U;
	DW_tjacmb_Unit_Delay2_DSTATE_b = 0U;
	DW_tjacmb_Unit_Delay2_DSTATE_j = 0U;
	DW_tjacmb_Unit_Delay_DSTATE_l = 0U;
	DW_tjacmb_Unit_Delay_DSTATE_fi = 0U;
	DW_tjacmb_Unit_Delay1_DSTATE_p = 0U;
	DW_tjacmb_Unit_Delay2_DSTATE_os = 0U;
	DW_tjacmb_Unit_Delay2_DSTATE_gn = 0U;
	DW_tjacmb_Unit_Delay4_DSTATE = 0U;
	DW_tjacmb_Unit_Delay1_DSTATE_ke = 0U;
	DW_tjacmb_Unit_Delay3_DSTATE = 0U;
	DW_tjacmb_Unit_Delay1_DSTATE_bhr = 0U;
	DW_tjacmb_Unit_Delay2_DSTATE_a = 0U;
	DW_tjacmb_is_active_c14_TJACMB_cg = 0U;
	DW_tjacmb_is_c14_TJACMB_cg = 0U;
	DW_tjacmb_Unit_Delay1_DSTATE = 0.F;
	DW_tjacmb_Unit_Delay2_DSTATE = 0.F;
	DW_tjacmb_Unit_Delay2_DSTATE_d = 0.F;
	DW_tjacmb_Unit_Delay1_DSTATE_b = 0.F;
	DW_tjacmb_Unit_Delay_DSTATE = 0.F;
	DW_tjacmb_Unit_Delay_DSTATE_h = 0.F;
	DW_tjacmb_Unit_Delay2_DSTATE_e = 0.F;
	DW_tjacmb_Unit_Delay_DSTATE_g = 0.F;
	DW_tjacmb_Unit_Delay_DSTATE_d = 0.F;
	DW_tjacmb_Unit_Delay1_DSTATE_bv = 0.F;
	DW_tjacmb_Unit_Delay5_DSTATE = 0.F;
	DW_tjacmb_Unit_Delay2_DSTATE_f = 0.F;
	DW_tjacmb_Unit_Delay_2_DSTATE = 0.F;
	DW_tjacmb_Unit_Delay_3_DSTATE = 0.F;
	DW_tjacmb_Unit_Delay_4_DSTATE = 0.F;
	DW_tjacmb_Unit_Delay_5_DSTATE = 0.F;
	DW_tjacmb_Unit_Delay1_DSTATE_bh = 0.F;
	DW_tjacmb_Unit_Delay5_DSTATE_k = 0.F;
	DW_tjacmb_Unit_Delay1_DSTATE_m = 0.F;
	DW_tjacmb_Unit_Delay2_DSTATE_o = 0.F;
	DW_tjacmb_Unit_Delay_DSTATE_f = 0.F;
	
}
#define TJACMB_SenReset TJACMB_SenResetData
#endif

#undef	RUNNABLE_ID
#endif

#ifdef __cplusplus
}
#endif

