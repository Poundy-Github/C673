/*===========================================================*
  Copyright (C) Continental AG
  All Rights Reserved
  PROJECT       : LCF100
  COMPONENT     : LCF
  TASK          : Vehicle
  SUB-COMPONENT : TRJPLN
  MODULE        : TPLTJC
  AUTHOR        : Module_AuxCodeGen
  VERSION       : 4.0

  Version Management Information
  $File: $
  $Revision: $
  $Author: $
  $Date: $
  $Log: $
**===========================================================*/
//! @file     Pse_TPLTJC.h
//! @brief     (TPLTJC) Module PSE Header.

#ifdef __cplusplus
extern "C"
{
#endif

/*-----------------------------------------------------*
   F U N C T I O N   D E F I N I T I O N S
**-----------------------------------------------------*/

#ifdef	RUNNABLE_ID

#if		RUNNABLE_ID == RUNNABLE_ID_TPLTJC_VehReset
void TPLTJC_VehResetData(void);
void TPLTJC_VehReset(void)
{
	uint8 k1;
	
	TPLTJC_VehResetData();
	
	BI_tpltjc_sfunc_MatrixInverseOK_nu = 0U;
	BI_tpltjc_sfunc_MaxJerkOK_nu = 0U;
	BI_tpltjc_Switch = 0.F;
	BI_tpltjc_Switch_l = 0.F;
	BI_tpltjc_sfunc_MaxJerkTraj_mps3 = 0.F;
	BI_tpltjc_sfunc_MaxAclTraj_mps2 = 0.F;
	BI_tpltjc_sfunc_TrajCalcTimeTrajEnd_sec = 0.F;
	BI_tpltjc_sfunc_ArcLengthTrajEnd_met = 0.F;
	BI_tpltjc_sfunc_OptimalCost_nu = 0.F;
	BI_tpltjc_P0 = 0.F;
	DW_tpltjc_UnitDelay_1_DSTATE = 0.F;
	DW_tpltjc_UnitDelay_2_DSTATE = 0.F;
	DW_tpltjc_UnitDelay_3_DSTATE = 0.F;
	DW_tpltjc_Unit_Delay3_DSTATE = 0.F;
	DW_tpltjc_Unit_Delay_DSTATE_b = 0.F;
	DW_tpltjc_Unit_Delay_DSTATE_i = 0.F;
	DW_tpltjc_Unit_Delay2_DSTATE = 0.F;
	DW_tpltjc_Unit_Delay1_DSTATE = 0.F;
	DW_tpltjc_UnitDelay1_DSTATE = 0.F;
	DW_tpltjc_UnitDelay2_DSTATE = 0.F;
	DW_tpltjc_UnitDelay_DSTATE = 0.F;
	DW_tpltjc_UnitDelay3_DSTATE = 0.F;
	
	for(k1 = 0; k1 < 6; k1++)
	{
		BI_tpltjc_sfunc_TrajParam_nu[k1] = 0.F;
		DW_tpltjc_Unit_Delay_DSTATE[k1] = 0.F;
	}
	
}
#define TPLTJC_VehReset TPLTJC_VehResetData
#endif

#undef	RUNNABLE_ID
#endif

#ifdef __cplusplus
}
#endif

