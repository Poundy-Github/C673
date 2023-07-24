/*===========================================================*
  Copyright (C) Continental AG
  All Rights Reserved
  PROJECT       : LCF100
  COMPONENT     : LCF
  TASK          : Vehicle
  SUB-COMPONENT : TRJPLN
  MODULE        : TPLFBT
  AUTHOR        : Module_AuxCodeGen
  VERSION       : 4.0

  Version Management Information
  $File: $
  $Revision: $
  $Author: $
  $Date: $
  $Log: $
**===========================================================*/
//! @file     Pse_TPLFBT.h
//! @brief     (TPLFBT) Module PSE Header.

#ifdef __cplusplus
extern "C"
{
#endif

/*-----------------------------------------------------*
   F U N C T I O N   D E F I N I T I O N S
**-----------------------------------------------------*/

#ifdef	RUNNABLE_ID

#if		RUNNABLE_ID == RUNNABLE_ID_TPLFBT_VehReset
void TPLFBT_VehResetData(void);
void TPLFBT_VehReset(void)
{
	
	TPLFBT_VehResetData();
	
	BI_tplfbt_DataTypeConversion = 0U;
	BI_tplfbt_SignalConversion1_a = 0U;
	BI_tplfbt_RelationalOperator1 = 0U;
	DW_tplfbt_Unit_Delay3_DSTATE = 0U;
	DW_tplfbt_Unit_Delay_DSTATE_e = 0U;
	DW_tplfbt_Unit_Delay1_DSTATE_n = 0U;
	DW_tplfbt_TargetValueSelection_MODE = 0U;
	DW_tplfbt_Unit_Delay_DSTATE_pl = 0U;
	BI_tplfbt_SignalConversion1 = 0.F;
	BI_tplfbt_SignalConversion1_d = 0.F;
	BI_tplfbt_SignalConversion1_c = 0.F;
	BI_tplfbt_SignalConversion1_dg = 0.F;
	BI_tplfbt_copy1 = 0.F;
	BI_tplfbt_copy1_k = 0.F;
	BI_tplfbt_copy1_n = 0.F;
	DW_tplfbt_Unit_Delay_DSTATE = 0.F;
	DW_tplfbt_Unit_Delay1_DSTATE = 0.F;
	DW_tplfbt_Unit_Delay2_DSTATE = 0.F;
	DW_tplfbt_Unit_Delay_DSTATE_d = 0.F;
	DW_tplfbt_Unit_Delay_DSTATE_k = 0.F;
	DW_tplfbt_Unit_Delay2_DSTATE_f = 0.F;
	DW_tplfbt_Unit_Delay_DSTATE_p = 0.F;
	DW_tplfbt_Unit_Delay_DSTATE_m = 0.F;
	
}
#define TPLFBT_VehReset TPLFBT_VehResetData
#endif

#undef	RUNNABLE_ID
#endif

#ifdef __cplusplus
}
#endif

