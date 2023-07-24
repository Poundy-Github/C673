/*===========================================================*
  Copyright (C) Continental AG
  All Rights Reserved
  PROJECT       : LCF100
  COMPONENT     : LCF
  TASK          : Vehicle
  SUB-COMPONENT : TRJPLN
  MODULE        : TPLLCO
  AUTHOR        : Module_AuxCodeGen
  VERSION       : 4.0

  Version Management Information
  $File: $
  $Revision: $
  $Author: $
  $Date: $
  $Log: $
**===========================================================*/
//! @file     Pse_TPLLCO.h
//! @brief     (TPLLCO) Module PSE Header.

#ifdef __cplusplus
extern "C"
{
#endif

/*-----------------------------------------------------*
   F U N C T I O N   D E F I N I T I O N S
**-----------------------------------------------------*/

#ifdef	RUNNABLE_ID

#if		RUNNABLE_ID == RUNNABLE_ID_TPLLCO_VehReset
void TPLLCO_VehResetData(void);
void TPLLCO_VehReset(void)
{
	uint8 k1;
	
	TPLLCO_VehResetData();
	
	BI_tpllco_DTC_out = 0U;
	BI_tpllco_DataTypeConversion = 0U;
	BI_tpllco_DataTypeConversion_g = 0U;
	BI_tpllco_DataTypeConversion_m = 0U;
	BI_tpllco_LogicalOperator = 0U;
	BI_tpllco_Unit_Delay10 = 0U;
	BI_tpllco_DataTypeConversion_n = 0U;
	BI_tpllco_DataTypeConversion_c = 0U;
	DW_tpllco_UnitDelay1_DSTATE = 0U;
	DW_tpllco_Unit_Delay_DSTATE_b = 0U;
	DW_tpllco_Unit_Delay1_DSTATE_c = 0U;
	DW_tpllco_Unit_Delay_DSTATE_h = 0U;
	DW_tpllco_Unit_Delay2_DSTATE_j = 0U;
	DW_tpllco_Unit_Delay4_DSTATE = 0U;
	DW_tpllco_Unit_Delay10_DSTATE = 0U;
	DW_tpllco_Unit_Delay4_DSTATE_j = 0U;
	DW_tpllco_Unit_Delay7_DSTATE = 0U;
	DW_tpllco_Unit_Delay6_DSTATE = 0U;
	DW_tpllco_Unit_Delay2_DSTATE_lz = 0U;
	DW_tpllco_Subsystem_MODE = 0U;
	DW_tpllco_Set_Dev_ReplanDelta_MODE = 0U;
	DW_tpllco_Plausibility_Check_MODE = 0U;
	DW_tpllco_Calc_ReplanDelta_MODE = 0U;
	BI_tpllco_Div = 0.F;
	BI_tpllco_Div_b = 0.F;
	BI_tpllco_Div_c = 0.F;
	BI_tpllco_Div_e = 0.F;
	BI_tpllco_Div_f = 0.F;
	BI_tpllco_Div_d = 0.F;
	BI_tpllco__TPLLCO_RightOri_rad = 0.F;
	BI_tpllco_Sum_j = 0.F;
	BI_tpllco_Div_i = 0.F;
	BI_tpllco_Switch = 0.F;
	BI_tpllco_Switch_f = 0.F;
	BI_tpllco_Sum_o = 0.F;
	BI_tpllco_Div_l = 0.F;
	BI_tpllco_Sum_n = 0.F;
	BI_tpllco_Sum_f = 0.F;
	BI_tpllco_Sum_np = 0.F;
	BI_tpllco_Sum_ji = 0.F;
	BI_tpllco_Sum_f5 = 0.F;
	BI_tpllco_Switch_o = 0.F;
	BI_tpllco_Switch_h = 0.F;
	BI_tpllco_Switch_of = 0.F;
	BI_tpllco_Div_fo = 0.F;
	BI_tpllco_Div_dc = 0.F;
	BI_tpllco_Div_fb = 0.F;
	BI_tpllco_Div_k = 0.F;
	BI_tpllco_Sum_d = 0.F;
	BI_tpllco_Switch_m = 0.F;
	BI_tpllco_Switch_e = 0.F;
	BI_tpllco_Switch_mv = 0.F;
	BI_tpllco_Div_m = 0.F;
	BI_tpllco_Div_bt = 0.F;
	BI_tpllco_Div_g = 0.F;
	BI_tpllco_Sum_je = 0.F;
	BI_tpllco_Div_ei = 0.F;
	BI_tpllco_Switch_j = 0.F;
	BI_tpllco_Div_gx = 0.F;
	BI_tpllco_Div_eq = 0.F;
	BI_tpllco_Div_g1 = 0.F;
	BI_tpllco_Mul = 0.F;
	BI_tpllco_Unit_Delay = 0.F;
	BI_tpllco_Unit_Delay1 = 0.F;
	BI_tpllco_Unit_Delay2 = 0.F;
	BI_tpllco_SignalConversion1 = 0.F;
	BI_tpllco_Sum_o4 = 0.F;
	BI_tpllco_Switch_l = 0.F;
	BI_tpllco_Switch_k = 0.F;
	BI_tpllco_S_CSCLTA_TgtTrajPosX0_met_f = 0.F;
	BI_tpllco_S_CSCLTA_TgtTrajPosY0_met_p = 0.F;
	BI_tpllco_S_CSCLTA_TgtTrajHeadAng_rad_k = 0.F;
	BI_tpllco_S_CSCLTA_TgtTrajCrv_1pm_i = 0.F;
	BI_tpllco_S_CSCLTA_TgtTrajCrvChng_1pm2_d = 0.F;
	BI_tpllco_Sum_b = 0.F;
	BI_tpllco_S_CSCLTA_LeCridrBndPosX0_met_h = 0.F;
	BI_tpllco_S_CSCLTA_RiCridrBndCrv_1pm_d = 0.F;
	BI_tpllco_S_CSCLTA_RiCridrBndCrvChng_1pm2_l = 0.F;
	BI_tpllco_S_CSCLTA_RiCridrBndLength_met_j = 0.F;
	BI_tpllco_S_CSCLTA_TgtTrajLength_met_d = 0.F;
	BI_tpllco_S_CSCLTA_LeCridrBndPosY0_met_j = 0.F;
	BI_tpllco_S_CSCLTA_LeCridrBndHeadAng_rad_l = 0.F;
	BI_tpllco_S_CSCLTA_LeCridrBndCrv_1pm_o = 0.F;
	BI_tpllco_S_CSCLTA_LeCridrBndCrvChng_1pm2_f = 0.F;
	BI_tpllco_S_CSCLTA_LeCridrBndLength_met_o = 0.F;
	BI_tpllco_S_CSCLTA_RiCridrBndPosX0_met_a = 0.F;
	BI_tpllco_S_CSCLTA_RiCridrBndPosY0_met_g = 0.F;
	BI_tpllco_S_CSCLTA_RiCridrBndHeadAng_rad_h = 0.F;
	BI_tpllco_Div_p = 0.F;
	BI_tpllco_Div_fc = 0.F;
	BI_tpllco_Div_fp = 0.F;
	DW_tpllco_Unit_Delay2_DSTATE = 0.F;
	DW_tpllco_Unit_Delay_DSTATE_f = 0.F;
	DW_tpllco_Unit_Delay_1_DSTATE = 0.F;
	DW_tpllco_Unit_Delay_2_DSTATE = 0.F;
	DW_tpllco_Unit_Delay_3_DSTATE = 0.F;
	DW_tpllco_Unit_Delay_4_DSTATE = 0.F;
	DW_tpllco_Unit_Delay_5_DSTATE = 0.F;
	DW_tpllco_UnitDelay3_DSTATE = 0.F;
	DW_tpllco_Unit_Delay1_DSTATE_g = 0.F;
	DW_tpllco_Unit_Delay3_DSTATE = 0.F;
	DW_tpllco_Unit_Delay_DSTATE_d = 0.F;
	DW_tpllco_Unit_Delay3_DSTATE_l = 0.F;
	DW_tpllco_Unit_Delay1_DSTATE_a3 = 0.F;
	DW_tpllco_Unit_Delay9_DSTATE = 0.F;
	DW_tpllco_Unit_Delay13_13_DSTATE = 0.F;
	DW_tpllco_Unit_Delay13_14_DSTATE = 0.F;
	DW_tpllco_Unit_Delay13_15_DSTATE = 0.F;
	DW_tpllco_Unit_Delay13_16_DSTATE = 0.F;
	DW_tpllco_Unit_Delay13_17_DSTATE = 0.F;
	DW_tpllco_Unit_Delay13_1_DSTATE = 0.F;
	DW_tpllco_Unit_Delay13_10_DSTATE = 0.F;
	DW_tpllco_Unit_Delay13_11_DSTATE = 0.F;
	DW_tpllco_Unit_Delay13_12_DSTATE = 0.F;
	DW_tpllco_Unit_Delay13_18_DSTATE = 0.F;
	DW_tpllco_Unit_Delay13_2_DSTATE = 0.F;
	DW_tpllco_Unit_Delay13_3_DSTATE = 0.F;
	DW_tpllco_Unit_Delay13_4_DSTATE = 0.F;
	DW_tpllco_Unit_Delay13_5_DSTATE = 0.F;
	DW_tpllco_Unit_Delay13_6_DSTATE = 0.F;
	DW_tpllco_Unit_Delay13_7_DSTATE = 0.F;
	DW_tpllco_Unit_Delay13_8_DSTATE = 0.F;
	DW_tpllco_Unit_Delay13_9_DSTATE = 0.F;
	
	for(k1 = 0; k1 < 4; k1++)
	{
		BI_tpllco_Assignment[k1] = 0U;
		BI_tpllco_Assignment_b[k1] = 0U;
		BI_tpllco_Assignment_a[k1] = 0U;
	}
	
	for(k1 = 0; k1 < 2; k1++)
	{
		BI_tpllco_copy1[k1] = 0.F;
		BI_tpllco_copy1_l[k1] = 0.F;
		BI_tpllco_Sum[k1] = 0.F;
		BI_tpllco_VectorConcatenate[k1] = 0.F;
		BI_tpllco_VectorConcatenate_d[k1] = 0.F;
		BI_tpllco_Sum_g[k1] = 0.F;
		BI_tpllco_VectorConcatenate_i[k1] = 0.F;
		BI_tpllco_VectorConcatenate_o[k1] = 0.F;
		BI_tpllco_VectorConcatenate_a[k1] = 0.F;
		BI_tpllco__EgoDist[k1] = 0.F;
		DW_tpllco_Unit_Delay1_DSTATE[k1] = 0.F;
	}
	
	for(k1 = 0; k1 < 25; k1++)
	{
		DW_tpllco_VehDeltaOriArray_DSTATE[k1] = 0.F;
		DW_tpllco_VehDeltaDistArray_DSTATE[k1] = 0.F;
	}
	
}
#define TPLLCO_VehReset TPLLCO_VehResetData
#endif

#undef	RUNNABLE_ID
#endif

#ifdef __cplusplus
}
#endif

