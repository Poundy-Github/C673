/*===========================================================*
  Copyright (C) Continental AG
  All Rights Reserved
  PROJECT       : LCF100
  COMPONENT     : LCF
  TASK          : Sensor
  SUB-COMPONENT : RDPSA
  MODULE        : DPRSIA
  AUTHOR        : Module_AuxCodeGen
  VERSION       : 4.0

  Version Management Information
  $File: $
  $Revision: $
  $Author: $
  $Date: $
  $Log: $
**===========================================================*/
//! @file     Pse_DPRSIA.h
//! @brief     (DPRSIA) Module PSE Header.

#ifdef __cplusplus
extern "C"
{
#endif

/*-----------------------------------------------------*
   F U N C T I O N   D E F I N I T I O N S
**-----------------------------------------------------*/

#ifdef	RUNNABLE_ID

#if		RUNNABLE_ID == RUNNABLE_ID_DPRSIA_SenReset
void DPRSIA_SenResetData(void);
void DPRSIA_SenReset(void)
{
	uint8 k1;
	
	DPRSIA_SenResetData();
	
	DW_dprsia_UnitDelay2_DSTATE_g = 0U;
	DW_dprsia_UnitDelay2_DSTATE_d = 0U;
	DW_dprsia_UnitDelay2_DSTATE_kh = 0U;
	DW_dprsia_UnitDelay2_DSTATE_j = 0U;
	DW_dprsia_UnitDelay2_DSTATE_jw = 0U;
	DW_dprsia_UnitDelay2_DSTATE_e1 = 0U;
	DW_dprsia_UnitDelay2_DSTATE_a = 0U;
	DW_dprsia_UnitDelay2_DSTATE_l = 0U;
	DW_dprsia_UnitDelay2_DSTATE_pa = 0U;
	DW_dprsia_UnitDelay2_DSTATE_nz = 0U;
	DW_dprsia_UnitDelay2_DSTATE_j0 = 0U;
	DW_dprsia_UnitDelay2_DSTATE_f = 0U;
	DW_dprsia_Unit_Delay_DSTATE = 0U;
	DW_dprsia_Unit_Delay_DSTATE_e = 0U;
	DW_dprsia_UnitDelay2_DSTATE_jv = 0U;
	DW_dprsia_UnitDelay2_DSTATE_oz = 0U;
	DW_dprsia_UnitDelay2_DSTATE_nr = 0U;
	DW_dprsia_UnitDelay1_DSTATE_n = 0U;
	DW_dprsia_UnitDelay2_DSTATE_ey = 0U;
	DW_dprsia_UnitDelay1_DSTATE_f0 = 0U;
	DW_dprsia_UnitDelay2_DSTATE_h = 0U;
	DW_dprsia_UnitDelay2_DSTATE_lw = 0U;
	DW_dprsia_UnitDelay2_DSTATE_km = 0U;
	DW_dprsia_UnitDelay2_DSTATE_es = 0U;
	DW_dprsia_UnitDelay2_DSTATE_an = 0U;
	DW_dprsia_UnitDelay2_DSTATE_ew = 0U;
	DW_dprsia_UnitDelay2_DSTATE_pu = 0U;
	DW_dprsia_UnitDelay2_DSTATE_cc = 0U;
	DW_dprsia_UnitDelay2_DSTATE_ou = 0U;
	DW_dprsia_UnitDelay2_DSTATE_jx = 0U;
	DW_dprsia_UnitDelay2_DSTATE_j4 = 0U;
	DW_dprsia_UnitDelay2_DSTATE_h4 = 0U;
	DW_dprsia_UnitDelay2_DSTATE_m = 0U;
	DW_dprsia_UnitDelay2_DSTATE_ic = 0U;
	DW_dprsia_UnitDelay2_DSTATE_fm = 0U;
	DW_dprsia_UnitDelay1_DSTATE_h = 0U;
	DW_dprsia_UnitDelay2_DSTATE_k0 = 0U;
	DW_dprsia_UnitDelay1_DSTATE_d = 0U;
	DW_dprsia_UnitDelay2_DSTATE_f2 = 0U;
	DW_dprsia_UnitDelay2_DSTATE_nc = 0U;
	DW_dprsia_UnitDelay2_DSTATE_nk = 0U;
	DW_dprsia_UnitDelay1_DSTATE_ds = 0U;
	DW_dprsia_UnitDelay3_DSTATE_d = 0U;
	DW_dprsia_UnitDelay1_DSTATE_k = 0U;
	DW_dprsia_UnitDelay1_DSTATE_i = 0U;
	DW_dprsia_UnitDelay1_DSTATE_o = 0U;
	DW_dprsia_UnitDelay1_DSTATE_mz = 0U;
	DW_dprsia_UnitDelay1_DSTATE = 0.F;
	DW_dprsia_UnitDelay2_DSTATE = 0.F;
	DW_dprsia_UnitDelay3_DSTATE = 0.F;
	DW_dprsia_UnitDelay4_DSTATE = 0.F;
	DW_dprsia_UnitDelay1_DSTATE_j = 0.F;
	DW_dprsia_UnitDelay2_DSTATE_n = 0.F;
	DW_dprsia_UnitDelay3_DSTATE_e = 0.F;
	DW_dprsia_UnitDelay4_DSTATE_l = 0.F;
	DW_dprsia_UnitDelay2_DSTATE_c = 0.F;
	DW_dprsia_UnitDelay2_DSTATE_p = 0.F;
	DW_dprsia_UnitDelay2_DSTATE_e = 0.F;
	DW_dprsia_UnitDelay2_DSTATE_k = 0.F;
	DW_dprsia_UnitDelay1_DSTATE_f = 0.F;
	DW_dprsia_UnitDelay1_DSTATE_m = 0.F;
	DW_dprsia_UnitDelay2_DSTATE_o = 0.F;
	DW_dprsia_UnitDelay2_DSTATE_ej = 0.F;
	DW_dprsia_UnitDelay2_DSTATE_pt = 0.F;
	DW_dprsia_UnitDelay2_DSTATE_i = 0.F;
	DW_dprsia_Unit_Delay1_DSTATE = 0.F;
	
	for(k1 = 0; k1 < 2; k1++)
	{
		DW_dprsia_UnitDelay2_DSTATE_khn[k1] = 0U;
		DW_dprsia_UnitDelay2_DSTATE_jm[k1] = 0U;
	}
	
	for(k1 = 0; k1 < 8; k1++)
	{
		DW_dprsia_Unit_Delay1_DSTATE_d[k1] = 0.F;
	}
	
}
#define DPRSIA_SenReset DPRSIA_SenResetData
#endif

#undef	RUNNABLE_ID
#endif

#ifdef __cplusplus
}
#endif

