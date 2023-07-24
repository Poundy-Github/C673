/**
 * \file   ModM.c
 *
 * \brief  
 *
 * \version refer the ModM_Cfg.h.
 * 
 * \copyright  2021 - 2023 Conti Smart Core
 *
 */
/*==================[inclusions]============================================*/
#include <Rte_ModM.h>
#include "ModM.h"
#include "SystemData_CustomerCoding.h"

/*==================[internal function declarations]========================*/
#define ModM_START_SEC_CODE_LOCAL
#include <ModM_MemMap.h>
static FUNC(void, RTE_CODE) ModM_Action_OperationMode_Normal(void);
static FUNC(void, RTE_CODE) ModM_Action_OperationMode_Trans(void);
static FUNC(void, RTE_CODE) ModM_Action_OperationMode_Test(void);
static FUNC(void, RTE_CODE) ModM_Action_OperationMode_Debug(void);
static FUNC(void, RTE_CODE) ModM_Action_OperationMode_Factory(void);
#define ModM_STOP_SEC_CODE_LOCAL
#include <ModM_MemMap.h>

/*==================[internal constants definition]=========================*/
#define ModM_START_SEC_CONST
#include <ModM_MemMap.h>

const s_ModM_Config_t s_ModM_Config[MODM_MODEINDEX] =
{
    { ModM_Normal,  &ModM_Action_OperationMode_Normal},
    { ModM_Trans,   &ModM_Action_OperationMode_Trans},
    { ModM_Test,    &ModM_Action_OperationMode_Test},
    { ModM_Debug,   &ModM_Action_OperationMode_Debug},
    { ModM_Factory, &ModM_Action_OperationMode_Factory}
};

#define ModM_STOP_SEC_CONST
#include <ModM_MemMap.h>

/*==================[external function definitions]=========================*/
#define ModM_START_SEC_CODE
#include <ModM_MemMap.h>
/**
 * \functions ModM_GetCurrentOperationMode
 *
 * \brief 
 *
 ** \param[in] none, 
 *
 ** \param[out] none,
 **                
 ** \return RTE_E_OK, 
 * \comments 
 */
FUNC(Std_ReturnType, RTE_CODE) ModM_GetCurrentOperationMode (P2VAR(uint8_t, AUTOMATIC, RTE_APPL_DATA) mode)/* PRQA S 3432,3227,2 # 2023-07-17 Z.J.L:Add parenthesized in include files, not any affect: accept */
{
    /* suppress compiler warnings about unused arguments */
    (void)ModM_u_GetCurrentMode(mode);
    return RTE_E_OK;
} /* FUNC(Std_ReturnType, RTE_CODE) ModM_GetCurrentOperationMode (P2VAR(uint8_t, AUTOMATIC, RTE_APPL_DATA) mode) */

/**
 * \functions ModM_GetNextOperationMode
 *
 * \brief 
 *
 ** \param[in] none, 
 *
 ** \param[out] none,
 **                
 ** \return RTE_E_OK, 
 * \comments 
 */
FUNC(Std_ReturnType, RTE_CODE) ModM_GetNextOperationMode (P2VAR(uint8_t, AUTOMATIC, RTE_APPL_DATA) mode)/* PRQA S 3432,3227,2 # 2023-07-17 Z.J.L:Add parenthesized in include files, not any affect: accept */
{
    /* suppress compiler warnings about unused arguments */
    (void)ModM_u_GetNextMode(mode);
    return RTE_E_OK;
} /* FUNC(Std_ReturnType, RTE_CODE) ModM_GetNextOperationMode (P2VAR(uint8_t, AUTOMATIC, RTE_APPL_DATA) mode) */

/**
 * \functions ModM_MainFunction
 *
 * \brief 
 *
 ** \param[in] none, 
 *
 ** \param[out] none,
 **                
 ** \return RTE_E_OK, 
 * \comments 
 */
FUNC(void, RTE_CODE) ModM_MainFunction (void)
{
    ModM_MainExec();
} /* FUNC(void, RTE_CODE) ModM_MainFunction (void) */

#define ModM_STOP_SEC_CODE
#include <ModM_MemMap.h>

/*==================[internal function definitions]=========================*/
#define ModM_START_SEC_CODE_LOCAL
#include <ModM_MemMap.h>
/**
 * \functions ModM_Action_OperationMode_Normal
 *
 * \brief 
 *
 ** \param[in] none, 
 *
 ** \param[out] none,
 **                
 ** \return RTE_E_OK, 
 * \comments 
 */
static FUNC(void, RTE_CODE) ModM_Action_OperationMode_Normal(void)
{
	/*SWRS_MFC5J3_SysM_30: In the Normal Mode,the software shall disable MTS function.*/
    WR_MTS_FUNCT_NOT_ACTIVATED 
	/*SWRS_MFC5J3_SysM_31: In the Normal Mode,the software shall disable XCP function if customer not have requirements.*/
	WR_XCP_FUNCT_NOT_ACTIVATED
	/*SWRS_MFC5J3_SysM_32: In the Normal Mode,the software shall not sent the dev message via CAN bus by all of channel.*/
	/*SWRS_MFC5J3_SysM_33: In the Normal Mode,the software shall not received the dev message via CAN bus by all of channel.*/
    WR_DBM_FUNCT_NOT_ACTIVATED
	/*SWRS_MFC5J3_SysM_34: In the Normal Mode,the J3 software shall only output error and warning information via log system.*/
	/*In the Normal Mode,the software shall enable error handling.*/
    WR_MED_FUNCT_ACTIVATED
    WR_SED_FUNCT_ACTIVATED
	/*SWRS_MFC5J3_SysM_35: In the Normal Mode,all ADAS functions are available.*/
	WR_AEB_FUNCT_ACTIVATED
	WR_ACC_FUNCT_ACTIVATED
	WR_LCF_FUNCT_ACTIVATED
	WR_ELK_FUNCT_ACTIVATED
	WR_HLA_FUNCT_ACTIVATED
	WR_TSA_FUNCT_ACTIVATED
	WR_PERCEPTION_FUNCT_ACTIVATED
	WR_FUNSION_FUNCT_ACTIVATED
	/*SWRS_MFC5J3_SysM_29: In the Normal Mode,the software shall implement communication,diagnostic,Network Management ,all of ADAS function and etc.*/
	WR_CSL_FUNCT_ACTIVATED //Open communciation control to fill in data to com buffer
	//Open Function Degradation	
	WR_FIM_FUNCT_ACTIVATED //PRQA S 1281
}

/**
 * \functions ModM_Action_OperationMode_Trans
 *
 * \brief The Trans mode means that the vehicle is in transit,mainly to suppress the ADAS functions trigger to prenent accidental 
 * transmission and also to reduce energy consumption.
 *
 ** \param[in] none, 
 *
 ** \param[out] none,
 **                
 ** \return RTE_E_OK, 
 * \comments 
 */
static FUNC(void, RTE_CODE) ModM_Action_OperationMode_Trans(void)
{
    /*SWRS_MFC5J3_SysM_38: In the Trans Mode,all ADAS functions are suppressed.*/
	WR_AEB_FUNCT_NOT_ACTIVATED
	WR_ACC_FUNCT_NOT_ACTIVATED
	WR_LCF_FUNCT_NOT_ACTIVATED
	WR_ELK_FUNCT_NOT_ACTIVATED
	WR_HLA_FUNCT_NOT_ACTIVATED
	WR_TSA_FUNCT_NOT_ACTIVATED
	WR_PERCEPTION_FUNCT_NOT_ACTIVATED
	WR_FUNSION_FUNCT_NOT_ACTIVATED
	/*SWRS_MFC5J3_SysM_40: In the Trans Mode,the software shall suppressed error handling.*/
	WR_MED_FUNCT_NOT_ACTIVATED
    WR_SED_FUNCT_NOT_ACTIVATED
    /*SWRS_MFC5J3_SysM_41: In the Trans Mode,the software shall suppressed functionity degradation.*/
	WR_FIM_FUNCT_NOT_ACTIVATED //PRQA S 1281
	/*SWRS_MFC5J3_SysM_42: In the Trans Mode,the software shall disable MTS function.*/
	WR_MTS_FUNCT_NOT_ACTIVATED
	/*SWRS_MFC5J3_SysM_43: In the Trans Mode,the software shall disable XCP function if customer not have requirements.*/
	WR_XCP_FUNCT_NOT_ACTIVATED	
	/*SWRS_MFC5J3_SysM_44: In the Trans Mode,the software shall not sent the dev message via can bus by all of channel.*/   
	/*SWRS_MFC5J3_SysM_45: In the Trans Mode,the software shall shall not received the dev message via can bus by all of channel.*/
	WR_DBM_FUNCT_NOT_ACTIVATED
	/*<TBD>In the Trans Mode,the can signal shall sent default value,Excluding special requirements, see the list below:*/

	/*<TBD>In the Trans Mode,the software shall power off J3.*/
}

/**
 * \functions ModM_Action_OperationMode_Test
 *
 * \brief The Test Mode means that all requirements of testing can be implemented,such as Xcp,Mts,Fault injection,etc.
 *
 ** \param[in] none, 
 *
 ** \param[out] none,
 **                
 ** \return RTE_E_OK, 
 * \comments 
 */
static FUNC(void, RTE_CODE) ModM_Action_OperationMode_Test(void)
{   
    WR_CSL_FUNCT_ACTIVATED
	/*SWRS_MFC5J3_SysM_xx: In the Test Mode,all ADAS functions are available.*/
	WR_AEB_FUNCT_ACTIVATED
	WR_ACC_FUNCT_ACTIVATED
	WR_LCF_FUNCT_ACTIVATED
	WR_ELK_FUNCT_ACTIVATED
	WR_HLA_FUNCT_ACTIVATED
	WR_TSA_FUNCT_ACTIVATED
	WR_PERCEPTION_FUNCT_ACTIVATED
	WR_FUNSION_FUNCT_ACTIVATED	
	/*SWRS_MFC5J3_SysM_49: In the Test Mode,the software shall implement fault injection requirements.*/
	WR_FIT_FUNCT_ACTIVATED	
	/*SWRS_MFC5J3_SysM_50: In the Test Mode,the software shall implement MTS function that its include Mcu and J3.*/
	WR_MTS_FUNCT_ACTIVATED
	/*SWRS_MFC5J3_SysM_51: In the Test Mode,the software shall implement Xcp function if customer not have requirements.*/
	WR_XCP_FUNCT_ACTIVATED	
	/*SWRS_MFC5J3_SysM_52: In the Test Mode,the software shall send dev message via can bus by all of channel.*/	
	/*SWRS_MFC5J3_SysM_53: In the Test Mode,the software shall receive dev message via can bus by all of channel.*/
	WR_DBM_FUNCT_ACTIVATED

	WR_FIM_FUNCT_ACTIVATED //PRQA S 1281
}

/**
 * \functions ModM_Action_OperationMode_Debug
 *
 * \brief The Debug Mode means that all requirements for debugging,such as log level updates,can be debugged through the debug interface. 
 *
 ** \param[in] none, 
 *
 ** \param[out] none,
 **                
 ** \return RTE_E_OK, 
 * \comments 
 */
static FUNC(void, RTE_CODE) ModM_Action_OperationMode_Debug(void)
{
    WR_CSL_FUNCT_ACTIVATED // Open communication state
	/*SWRS_MFC5J3_SysM_xx: In the debug Mode,all ADAS functions are available.*/
	WR_AEB_FUNCT_ACTIVATED
	WR_ACC_FUNCT_ACTIVATED
	WR_LCF_FUNCT_ACTIVATED
	WR_ELK_FUNCT_ACTIVATED
	WR_HLA_FUNCT_ACTIVATED
	WR_TSA_FUNCT_ACTIVATED
	WR_PERCEPTION_FUNCT_ACTIVATED
	WR_FUNSION_FUNCT_ACTIVATED
	/*SWRS_MFC5J3_SysM_56: In the Debug Mode,the software shall implement fault injection requirements.*/
	WR_FIT_FUNCT_ACTIVATED
	/*SWRS_MFC5J3_SysM_57: In the Debug Mode,the software shall implement MTS function that its include Mcu and J3.*/
	WR_MTS_FUNCT_ACTIVATED
	/*SWRS_MFC5J3_SysM_58: In the Debug Mode,the software shall implement Xcp function if customer not have requirements.*/
	WR_XCP_FUNCT_ACTIVATED
	/*SWRS_MFC5J3_SysM_59: In the Debug Mode,the software shall send dev message via can bus by all of channel.*/
	/*SWRS_MFC5J3_SysM_60: In the Debug Mode,the software shall receive dev message via can bus by all of channel.*/
	WR_DBM_FUNCT_ACTIVATED
	/*SWRS_MFC5J3_SysM_61: In the Debug Mode,the software shall implement debugging interface and output debugging information.*/
	WR_PRT_FUNCT_ACTIVATED  //Enable Printf
	WR_RTM_FUNCT_ACTIVATED  //Enable runtime measurement
    WR_FIM_FUNCT_ACTIVATED  //PRQA S 1281
}

/**
 * \functions ModM_Action_OperationMode_Factory
 *
 * \brief The Factory Mode means that all requirements for factory,such as factory line testing can be supported.
 *
 ** \param[in] none, 
 *
 ** \param[out] none,
 **                
 ** \return RTE_E_OK, 
 * \comments 
 */
static FUNC(void, RTE_CODE) ModM_Action_OperationMode_Factory(void)
{
	/*SWRS_MFC5J3_SysM_64: In the Factory Mode,the software shall implement factory related requirement.*/
}

#define ModM_STOP_SEC_CODE_LOCAL
#include <ModM_MemMap.h>



