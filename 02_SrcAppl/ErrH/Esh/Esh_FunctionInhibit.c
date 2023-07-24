/**
 * \file   Esh_FunctionInhibit.c
 *
 * \brief  Set Enable condition of Dem Event to inhibited report DTC.
 *
 * \version refer the Rte_Esh.h.
 * 
 * \copyright  2022 - 2023 Conti Smart Core
 *
 */
/*==================[inclusions]============================================*/
#include <Rte_Esh.h>
#include "Esh_Main.h"
#include "Dbg_Cfg.h"


/*==================[external constants definition]=========================*/
extern uint8 FCU_SwitchData[7];


/*==================[internal constants definition]=========================*/


/*==================[external data definition]==============================*/
boolean Esh_FIMSts_U17A1F0 = TRUE;


/*==================[internal data definition]==============================*/
static s_Esh_ErrorStatusInfo_t s_ErrorStatusInfo;



/*==================[internal function declarations]========================*/
static FUNC(void, RTE_CODE) Esh_Core_FunctionInhibitionMainLogic(void);




/*==================[external function definitions]=========================*/
/**
 * \functions Esh_Core_FunctionInhibitionMainFunction
 *
 * \brief   This is the main function for used to process Function inhibition.
 *
 ** \param[in] none,
 *
 ** \param[out] none,
 *
 ** \return none, 
 * \comments
 *
 */
FUNC(void, RTE_CODE) Esh_Core_FunctionInhibitionMainFunction(void)
{
	Esh_Core_FunctionInhibitionMainLogic();
}

/*==================[internal function definitions]=========================*/
/**
 * \functions Esh_Core_FunctionInhibitionMainLogic
 *
 * \brief   This is the main logic of function inhibition.
 *
 ** \param[in] none,
 *
 ** \param[out] none,
 *
 ** \return none, 
 * \comments
 *
 */
static FUNC(void, RTE_CODE) Esh_Core_FunctionInhibitionMainLogic(void)
{
#if (ESH_FEAT_FUNCTIONINHIBITIION_ENABLE == STD_ON)
	uint8_t u8_HU_AutoBrakeEnable = 0;
	uint8_t u8_HU_ELKEnable = 0;
	uint8_t u8_HU_FCW_Setting = 0;
	uint8_t u8_HU_LASModeSelection = 0;
	uint8_t u8_HU_HMAEnable = 0;
	Com_SignalSts_t u8_AccIaccHWAMode_Sts;
	uint8_t u8_AccIaccHWAMode;
	
	u8_HU_AutoBrakeEnable = FCU_SwitchData[5]; //GW_507(0x00:Off 0x01:On)
	u8_HU_ELKEnable = FCU_SwitchData[4];  //GW_3BD(0x00:Inactive 0x01:Off 0x02:On 0x03:Reserved)
	u8_HU_FCW_Setting = FCU_SwitchData[0]; //GW_507(0x00:Early 0x01:Normal 0x02:Late 0x03:off 0x07: Invalid)
	u8_HU_LASModeSelection = FCU_SwitchData[2];//GW_507(0x00:Inactive 0x01:LDW 0x02:LKA 0x03:LCS 0x07: OFF)
    u8_HU_HMAEnable = FCU_SwitchData[1];//GW_507(0x00:Off 0x01:On)

	(void)Rte_Read_RP_Cpr_Body_Data_AccIaccHWAMode_Status(&u8_AccIaccHWAMode_Sts);

	if(E_SIG_STATUS_VALID == u8_AccIaccHWAMode_Sts)
	{
        (void)Rte_Read_RP_Cpr_Body_Data_AccIaccHWAMode(&u8_AccIaccHWAMode);
	}
	else
	{
        u8_AccIaccHWAMode = 0;//Default value
	}
	
	if(0x01u == u8_HU_AutoBrakeEnable)	
	{
	    /*When the function active, the function permission shall be enable*/
	    (void)Rte_Call_RP_FIM_FunctionInhibition_AEB_GetFunctionPermission(&s_ErrorStatusInfo.AEB);
	}
	else
	{
        s_ErrorStatusInfo.AEB = TRUE; //FID has permission to run
	}

	if(0x02u == u8_HU_ELKEnable)
	{
	    (void)Rte_Call_RP_FIM_FunctionInhibition_ELK_GetFunctionPermission(&s_ErrorStatusInfo.ELK);
	}
	else
	{
        s_ErrorStatusInfo.ELK = TRUE; 
	}

    if((0x00u == u8_HU_FCW_Setting) || (0x01u == u8_HU_FCW_Setting) || (0x02u == u8_HU_FCW_Setting))
	{
	    (void)Rte_Call_RP_FIM_FunctionInhibition_FCW_GetFunctionPermission(&s_ErrorStatusInfo.FCW);
	}
	else
	{
        s_ErrorStatusInfo.FCW = TRUE;
	}
			
	if(0x01u == u8_HU_LASModeSelection)
	{
	    (void)Rte_Call_RP_FIM_FunctionInhibition_LDW_GetFunctionPermission(&s_ErrorStatusInfo.LDW);//Not include DTC_U17AF0
		(void)Rte_Call_RP_FIM_FunctionInhibition_LDW_U17A1F0_GetFunctionPermission(&Esh_FIMSts_U17A1F0);
	}
	else
	{
        s_ErrorStatusInfo.LDW = TRUE;
		SET_Esh_FIMSts_U17A1F0(TRUE);
	}

	if(0x02u == u8_HU_LASModeSelection)
	{
	    (void)Rte_Call_RP_FIM_FunctionInhibition_LKA_GetFunctionPermission(&s_ErrorStatusInfo.LKA);
	}
	else
	{
        s_ErrorStatusInfo.LKA = TRUE;
	}
		
    if((0x01u == u8_HU_HMAEnable) ||(0x03 == u8_AccIaccHWAMode) || (0x04 == u8_AccIaccHWAMode))
    {
	    (void)Rte_Call_RP_FIM_FunctionInhibition_FAB_GetFunctionPermission(&s_ErrorStatusInfo.FAB);
    }
	else
	{
        s_ErrorStatusInfo.FAB = TRUE;
	}

	(void)Rte_Call_RP_FIM_FunctionInhibition_HLA_GetFunctionPermission(&s_ErrorStatusInfo.HLA);
	(void)Rte_Call_RP_FIM_FunctionInhibition_TSA_GetFunctionPermission(&s_ErrorStatusInfo.TSA);
#else
    s_ErrorStatusInfo.AEB = TRUE;
    s_ErrorStatusInfo.ELK = TRUE;
    s_ErrorStatusInfo.FAB = TRUE;
	s_ErrorStatusInfo.FCW = TRUE;
	s_ErrorStatusInfo.HLA = TRUE;
	s_ErrorStatusInfo.LDW = TRUE;
	s_ErrorStatusInfo.LKA = TRUE;
	s_ErrorStatusInfo.TSA = TRUE;
#endif
	
	(void)Rte_Write_PP_Esh_SRI_Esh_ErrorStatusInfo_DE_Esh_ErrorStatusInfo(&s_ErrorStatusInfo);

}










