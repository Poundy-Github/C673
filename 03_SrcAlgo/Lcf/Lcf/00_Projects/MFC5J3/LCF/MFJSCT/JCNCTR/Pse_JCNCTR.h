/*===========================================================*
  Copyright (C) Continental AG
  All Rights Reserved
  PROJECT       : MFC5J3
  COMPONENT     : LCF
  TASK          : Sensor
  SUB-COMPONENT : MFJSCT
  MODULE        : JCNCTR
  AUTHOR        : Module_AuxCodeGen
  VERSION       : 4.0

  Version Management Information
  $File: $
  $Revision: $
  $Author: $
  $Date: $
  $Log: $
**===========================================================*/
//! @file     Pse_JCNCTR.h
//! @brief     (JCNCTR) Module PSE Header.

#ifdef __cplusplus
extern "C"
{
#endif

/*-----------------------------------------------------*
   F U N C T I O N   D E F I N I T I O N S
**-----------------------------------------------------*/

#ifdef	RUNNABLE_ID

#if RUNNABLE_ID == RUNNABLE_ID_JCNCTR_SenReset
  void JCNCTR_SenResetData(void);
  void JCNCTR_SenReset(void)
  {

    JCNCTR_SenResetData();

    DW_jcnctr_Unit_Delay2_DSTATE_h = 0u;
    DW_jcnctr_Unit_Delay2_DSTATE_c = 0u;
    DW_jcnctr_Unit_Delay2_DSTATE_k = 0u;
    DW_jcnctr_Unit_Delay2_DSTATE_b = 0u;
    DW_jcnctr_Unit_Delay2_DSTATE_i = 0u;
    DW_jcnctr_Unit_Delay2_DSTATE_f = 0u;
    DW_jcnctr_Unit_Delay2_DSTATE_l = 0u;
    DW_jcnctr_Unit_Delay2_DSTATE_d = 0u;
    DW_jcnctr_Unit_Delay2_DSTATE_fk = 0u;
    DW_jcnctr_Unit_Delay2_DSTATE_m = 0u;
    DW_jcnctr_Unit_Delay2_DSTATE_lx = 0u;
    DW_jcnctr_Unit_Delay2_DSTATE_ba = 0u;
    DW_jcnctr_Unit_Delay2_DSTATE_it = 0u;
    DW_jcnctr_Unit_Delay2_DSTATE_j = 0u;
    DW_jcnctr_Unit_Delay2_DSTATE_bw = 0u;
    DW_jcnctr_Unit_Delay2_DSTATE_dl = 0u;
    DW_jcnctr_Unit_Delay2_DSTATE_g = 0u;
    DW_jcnctr_Unit_Delay2_DSTATE_o = 0u;
    DW_jcnctr_Unit_Delay2_DSTATE_p = 0u;
    DW_jcnctr_Unit_Delay2_DSTATE_a = 0u;
    DW_jcnctr_Unit_Delay2_DSTATE_c3 = 0u;
    DW_jcnctr_Unit_Delay2_DSTATE_bj = 0u;
    DW_jcnctr_Unit_Delay2_DSTATE_dy = 0u;
    DW_jcnctr_Unit_Delay2_DSTATE_e = 0u;
    DW_jcnctr_Unit_Delay2_DSTATE_g5 = 0u;
    DW_jcnctr_Unit_Delay2_DSTATE_bv = 0u;
    DW_jcnctr_Unit_Delay2_DSTATE_ck = 0u;
    DW_jcnctr_Unit_Delay2_DSTATE_dn = 0u;
    DW_jcnctr_Unit_Delay2_DSTATE_mo = 0u;
    DW_jcnctr_Unit_Delay2_DSTATE_n = 0u;
    DW_jcnctr_Unit_Delay2_DSTATE_h1 = 0u;
    DW_jcnctr_Unit_Delay2_DSTATE_gb = 0u;
    DW_jcnctr_Unit_Delay2_DSTATE_gn = 0u;
    DW_jcnctr_Unit_Delay2_DSTATE_me = 0u;
    DW_jcnctr_Unit_Delay2_DSTATE_pb = 0u;

    DW_jcnctr_Unit_Delay_DSTATE = 0.f;
    DW_jcnctr_Unit_Delay1_DSTATE = 0.f;
    DW_jcnctr_Unit_Delay_DSTATE_o = 0.f;
    DW_jcnctr_Unit_Delay1_DSTATE_g = 0.f;
    DW_jcnctr_Unit_Delay_DSTATE_g = 0.f;
    DW_jcnctr_Unit_Delay1_DSTATE_i = 0.f;
    DW_jcnctr_Unit_Delay_DSTATE_oh = 0.f;
    DW_jcnctr_Unit_Delay1_DSTATE_d = 0.f;
    DW_jcnctr_Unit_Delay_DSTATE_n = 0.f;
    DW_jcnctr_Unit_Delay1_DSTATE_go = 0.f;
    DW_jcnctr_Unit_Delay_DSTATE_i = 0.f;
    DW_jcnctr_Unit_Delay1_DSTATE_p = 0.f;
    DW_jcnctr_Unit_Delay_DSTATE_l = 0.f;
    DW_jcnctr_Unit_Delay1_DSTATE_h = 0.f;
    DW_jcnctr_Unit_Delay_DSTATE_m = 0.f;
    DW_jcnctr_Unit_Delay1_DSTATE_pp = 0.f;
    DW_jcnctr_Unit_Delay_DSTATE_f = 0.f;
    DW_jcnctr_Unit_Delay1_DSTATE_c = 0.f;
    DW_jcnctr_Unit_Delay_DSTATE_go = 0.f;
    DW_jcnctr_Unit_Delay1_DSTATE_f = 0.f;
    DW_jcnctr_Unit_Delay_DSTATE_p = 0.f;
    DW_jcnctr_Unit_Delay1_DSTATE_a = 0.f;
    DW_jcnctr_Unit_Delay_DSTATE_mt = 0.f;
    DW_jcnctr_Unit_Delay1_DSTATE_o = 0.f;
    DW_jcnctr_Unit_Delay_DSTATE_ph = 0.f;
    DW_jcnctr_Unit_Delay1_DSTATE_hu = 0.f;
    DW_jcnctr_Unit_Delay_DSTATE_gn = 0.f;
    DW_jcnctr_Unit_Delay1_DSTATE_j = 0.f;
    DW_jcnctr_Unit_Delay_DSTATE_d = 0.f;
    DW_jcnctr_Unit_Delay1_DSTATE_p3 = 0.f;
    DW_jcnctr_Unit_Delay_DSTATE_b = 0.f;
    DW_jcnctr_Unit_Delay1_DSTATE_b = 0.f;
    DW_jcnctr_Unit_Delay_DSTATE_n4 = 0.f;
    DW_jcnctr_Unit_Delay2_DSTATE = 0.f;
    DW_jcnctr_Unit_Delay1_DSTATE_ge = 0.f;
    DW_jcnctr_Unit_Delay_DSTATE_ma = 0.f;
    DW_jcnctr_Unit_Delay1_DSTATE_gf = 0.f;
    DW_jcnctr_Unit_Delay_DSTATE_h = 0.f;
    DW_jcnctr_Unit_Delay1_DSTATE_dc = 0.f;
    DW_jcnctr_Unit_Delay_DSTATE_pv = 0.f;
    DW_jcnctr_Unit_Delay1_DSTATE_pa = 0.f;
    DW_jcnctr_Unit_Delay_DSTATE_hh = 0.f;
    DW_jcnctr_Unit_Delay1_DSTATE_hb = 0.f;
    DW_jcnctr_Unit_Delay_DSTATE_e = 0.f;
    DW_jcnctr_Unit_Delay1_DSTATE_iu = 0.f;
    DW_jcnctr_Unit_Delay_DSTATE_da = 0.f;
    DW_jcnctr_Unit_Delay1_DSTATE_dg = 0.f;
    DW_jcnctr_Unit_Delay_DSTATE_oy = 0.f;
    DW_jcnctr_Unit_Delay1_DSTATE_bf = 0.f;
    DW_jcnctr_Unit_Delay_DSTATE_oyh = 0.f;
    DW_jcnctr_Unit_Delay1_DSTATE_jz = 0.f;
    DW_jcnctr_Unit_Delay_DSTATE_db = 0.f;
    DW_jcnctr_Unit_Delay1_DSTATE_n = 0.f;
    DW_jcnctr_Unit_Delay_DSTATE_os = 0.f;
    DW_jcnctr_Unit_Delay1_DSTATE_e = 0.f;
    DW_jcnctr_Unit_Delay_DSTATE_pb = 0.f;
    DW_jcnctr_Unit_Delay1_DSTATE_h1 = 0.f;
    DW_jcnctr_Unit_Delay_DSTATE_ov = 0.f;
    DW_jcnctr_Unit_Delay1_DSTATE_o4 = 0.f;
    DW_jcnctr_Unit_Delay_DSTATE_il = 0.f;
    DW_jcnctr_Unit_Delay1_DSTATE_nb = 0.f;
    DW_jcnctr_Unit_Delay_DSTATE_bs = 0.f;
    DW_jcnctr_Unit_Delay1_DSTATE_iv = 0.f;
    DW_jcnctr_Unit_Delay_DSTATE_bv = 0.f;
    DW_jcnctr_Unit_Delay1_DSTATE_k = 0.f;
    DW_jcnctr_Unit_Delay_DSTATE_iv = 0.f;
    DW_jcnctr_Unit_Delay1_DSTATE_ke = 0.f;
    DW_jcnctr_Unit_Delay_DSTATE_hy = 0.f;
    DW_jcnctr_Unit_Delay1_DSTATE_dq = 0.f;
    DW_jcnctr_Unit_Delay_DSTATE_c = 0.f;
    DW_jcnctr_Unit_Delay1_DSTATE_m = 0.f;
  }
#define JCNCTR_SenReset JCNCTR_SenResetData
#endif

#undef	RUNNABLE_ID
#endif

#ifdef __cplusplus
}
#endif

