
/* ==================[Includes]=============================================== */
#include "Fcu.h"
#include <math.h>
#include "algo_service_types.h"
#include "SchM_StbM.h"
#include "Com_SymbolicNames_PBcfg.h"
#include "P_TrajPlanMathDefs.h"
#include "Cdm.h"
#include "Fcu_Type.h"
#include "Rte_Fcu.h"
#include "Os_api.h"
#include "Fcu_Vdy.h"
#include "Fcu_Hla.h"
#include "Fcu_Lcf.h"
#include "Fcu_Fct.h"
#include "Fcu_Common.h"
#include "Cps_Lcfg.h"
/*==================[macros]=================================================*/
/*TODO : Following use for function of Fcu_DataProcess_CalcObstacleTTC*/

/*==================[external data]=========================================*/
/*Replenish VDY signal mapping*/
//extern boolean Cps_SignalPhyData_FC_HMAEnableStatus;
//extern boolean Cps_SignalPhyData_FC_AEBTargetDetection;
//extern boolean Cps_SignalPhyData_LatAngReqActive;

/*==================[internal data]=========================================*/
static s_Fcu_Rte_Input_SignalData_t ptr_Fcu_Rte_input_Signal;
static s_Fcu_Rte_Output_SignalData_t ptr_Fcu_Rte_Output_Signal;
/*==================[internal function declarations]========================*/
 
//static void Fcu_MEASFreezeData(void);
//static void Fcu_Mtsi(uint32 VirtAdd, uint32 length, uint8 funcid, pvoid data_p);
//static void Fcu_Rte_Cps_testcode();
/*==================[internal function definitions]=========================*/


/*==================[external function definitions]=========================*/
/**
 * \functions Fcu_InitFunction
 *
 * \brief
 *
 * \parameters-in none
 *
 * \parameters-out none
 *
 * \return 	none
 *
 * \comments
 *
 */
FUNC(void, RTE_CODE) Fcu_InitFunction (void)
{
	(void)TS_MemSet(&ptr_Fcu_Rte_input_Signal, 0, sizeof(s_Fcu_Rte_Input_SignalData_t));
	Fcu_Common_InitFunction(&ptr_Fcu_Rte_Output_Signal);
}


/**
 * \functions Fcu_MainFunction
 *
 * \brief
 *
 * \parameters-in none
 *
 * \parameters-out none
 *
 * \return 	none
 *
 * \comments
 *
 */
FUNC(void, RTE_CODE) Fcu_MainFunction (void)
{

	//Can Receive Signal Read
	Fcu_Adas_Data_Process(&ptr_Fcu_Rte_input_Signal.AdasDomain_Data); 
	Fcu_Body_Data_Process(&ptr_Fcu_Rte_input_Signal.BodyDomain_Data);
	Fcu_Chassis_Data_Process(&ptr_Fcu_Rte_input_Signal.ChassisDomain_Data);
	Fcu_Powertrain_Data_Process(&ptr_Fcu_Rte_input_Signal.PowertrainDomain_Data);

	//HMI BaseCtrlData FIM Module 
	Fcu_Common_MainFunction();

	//Algo signal main function process
	Fcu_Vdy_MainFunction(&ptr_Fcu_Rte_input_Signal);
	Fcu_Fct_MainFunction(&ptr_Fcu_Rte_input_Signal,&ptr_Fcu_Rte_Output_Signal);
	Fcu_Lcf_MainFunction(&ptr_Fcu_Rte_input_Signal,&ptr_Fcu_Rte_Output_Signal);
	Fcu_Hla_MainFunction(&ptr_Fcu_Rte_input_Signal,&ptr_Fcu_Rte_Output_Signal);

	//Can Send Signal Write
	Fcu_Aeb_Data_Process(&ptr_Fcu_Rte_Output_Signal.Aeb_Data); 
	Fcu_Lcf_Data_Process(&ptr_Fcu_Rte_Output_Signal.Lcf_Data);
	Fcu_Acc_Data_Process(&ptr_Fcu_Rte_Output_Signal.Acc_Data);
	Fcu_Hla_Data_Process(&ptr_Fcu_Rte_Output_Signal.Hla_Data);

	//This funcation specifically designed for interactive signal use
	Fcu_Interaction_Process(&ptr_Fcu_Rte_Output_Signal); 
}

/**
 * \functions Fcu_MainFunction_Rx
 *
 * \brief
 *
 * \parameters-in none
 *
 * \parameters-out none
 *
 * \return 	none
 *
 * \comments
 *
 */
FUNC(void, RTE_CODE) Fcu_MainFunction_Rx (void)
{

}

/**
 * \functions Fcu_MainFunction_Tx
 *
 * \brief
 *
 * \parameters-in none
 *
 * \parameters-out none
 *
 * \return 	none
 *
 * \comments
 *
 */
FUNC(void, RTE_CODE) Fcu_MainFunction_Tx (void)
{

}


/*==================[internal function definitions]=========================*/
#if 0
static void Fcu_MEASFreezeData(void)
{
	static uint32 Fcu_MeasFreeze_Control = 0x00;
	AS_t_MeasInfo meas_info;

}
static void Fcu_Mtsi(uint32 VirtAdd, uint32 length, uint8 funcid, pvoid data_p)
{
	AS_t_MeasInfo meas_info;
	meas_info.VirtualAddress = VirtAdd;
	meas_info.Length = length;
	meas_info.FuncID = funcid;
	MEASFreezeDataMTS(&meas_info, data_p, NULL_PTR);
}
#endif