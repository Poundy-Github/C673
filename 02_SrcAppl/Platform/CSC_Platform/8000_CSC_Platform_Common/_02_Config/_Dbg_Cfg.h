/**
 * \file Dbg_Cfg.h
 *
 * \brief
 *
 * \version refer Dbg.h
 * 
 */

#ifndef _DBG_CFG_H_
#define _DBG_CFG_H_

/*==================[macros]=================================================*/
/*==================[macros:Software Functions enable switch]=*/
/*
 * brief    following definition the SWC function enable switch
 *          STD_ON :  the function enable,
 *          STD_OFF : the function disable
 * 
 * Notes    1.the macros name shall definition to DBG_<SWCs>_<Function>_ENABLE
 *          2.Each software funtion enable switch shall comments indication the function description
 *
 * */
#define DBG_VDYADAPTER_ALGO_ENABLE				                STD_OFF      /*Vdy Algo enable switch*/
#define DBG_VDYADAPTER_MEASFREEZE_ENABLE            			STD_OFF      /*Vdy Adapter related MTS data meas freeze*/
#define DBG_FCTADAPTER_ALGO_ENABLE				                STD_OFF     /*Fct Algo enable switch*/
#define DBG_FCTADAPTER_MEASFREEZE_ENABLE   			            STD_OFF      /*Fct Adapter related MTS data meas freeze*/
#define DBG_LCFADAPTER_ALGO_ENABLE				                STD_OFF     /*Lcf Algo enable switch*/
#define DBG_LCFADAPTER_MEASFREEZE_ENABLE   			            STD_OFF     /*Lcf Adapter related MTS data meas freeze*/
#define DBG_HLAADAPTER_ALGO_ENABLE				                STD_OFF     /*Hla Algo enable switch*/
#define DBG_HLAADAPTER_MEASFREEZE_ENABLE               			STD_OFF     /*Hla Adapter releated MTS data meas freeze*/
#define DBG_SDC_MEASFREEZE_ENABLE               				STD_OFF      /*Sdc releated MTS data meas freeze*/




/*==================[macros:debug enable switch]=============================*/
/*
 * \brief 	DBG_MCU_SW_DEBUG_ENABLE,
 * 			When this switch is OFF,all of software components will disable the debug function.
 * */
#define DBG_MCU_SW_DEBUG_ENABLE				                    STD_OFF

#if (DBG_MCU_SW_DEBUG_ENABLE == STD_ON)
/*
 * brief    following definition the SWC debug switch
 *          STD_ON : Enable the debug variable and debug function, can be view the debug variable via trace32,and called the debug function; 
 *          STD_OFF : Disable the debug variable and debug function, can not view the debug variable via trace32,and the not called the debug function; 
 * 
 * Notes    the macros name shall definition to DBG_<SWCs>_DEBUG_ENABLE
 *
 * */
#define DBG_CSCPLATFORM_DEBUG_ENABLE						    STD_OFF
#define DBG_CPR_DEBUG_ENABLE						            STD_OFF
#define DBG_CPS_DEBUG_ENABLE						            STD_OFF
#define DBG_MED_DEBUG_ENABLE						            STD_OFF
#define DBG_SED_DEBUG_ENABLE						            STD_OFF
#define DBG_SDC_DEBUG_ENABLE						            STD_OFF
#define DBG_ESM_DEBUG_ENABLE						            STD_OFF
#define DBG_CDM_DEBUG_ENABLE						            STD_OFF
#define DBG_VDYADAPTER_DEBUG_ENABLE						        STD_OFF
#define DBG_FCTADAPTER_DEBUG_ENABLE						        STD_OFF
#define DBG_LCFADAPTER_DEBUG_ENABLE						        STD_OFF
#define DBG_HLAADAPTER_DEBUG_ENABLE						        STD_OFF
#define DBG_MTSIADAPTER_DEBUG_ENABLE					        STD_OFF
#endif

/*==================[macros:integration test enable switch]==================*/
/*
 * \brief 	DBG_MCU_SW_INTEGRATION_TEST_ENABLE,
 * 			When this switch is OFF,all of software components will disable the integration code;
 *          When you write the integration test code,you shall use this macro;
 * */
#define DBG_MCU_SW_INTEGRATION_TEST_ENABLE                      STD_OFF
#if (DBG_MCU_SW_INTEGRATION_TEST_ENABLE == STD_ON)
/*
 * brief    following definition the SWC integration test switch
 *          STD_ON : Enable the integration function,may be the developer can be write integration code(include variable and code) 
 *          STD_OFF : Enable the integration function 
 * 
 * Notes    the macros name shall definition to DBG_<SWCs>_INTEGRATION_TEST_ENABLE
 *
 * */
#define DBG_CSCPLATFORM_INTEGRATION_TEST_ENABLE					STD_OFF
#define DBG_CPR_INTEGRATION_TEST_ENABLE						    STD_OFF
#define DBG_CPS_INTEGRATION_TEST_ENABLE						    STD_OFF
#define DBG_MED_INTEGRATION_TEST_ENABLE						    STD_OFF
#define DBG_SED_INTEGRATION_TEST_ENABLE						    STD_OFF
#define DBG_SDC_INTEGRATION_TEST_ENABLE						    STD_OFF
#define DBG_ESM_INTEGRATION_TEST_ENABLE						    STD_OFF
#define DBG_CDM_INTEGRATION_TEST_ENABLE						    STD_OFF
#define DBG_VDYADAPTER_INTEGRATION_TEST_ENABLE					STD_OFF
#define DBG_FCTADAPTER_INTEGRATION_TEST_ENABLE					STD_OFF
#define DBG_LCFADAPTER_INTEGRATION_TEST_ENABLE					STD_OFF
#define DBG_HLAADAPTER_INTEGRATION_TEST_ENABLE					STD_OFF
#define DBG_MTSIADAPTER_INTEGRATION_TEST_ENABLE					STD_OFF
#endif

/*==================[macros:unit test enable switch]=========================*/
/*
 * \brief 	DBG_MCU_SW_UNIT_TEST_ENABLE,
 * 			When this switch is OFF,all of software components will disable the bench function.
 * */
#define DBG_MCU_SW_UNIT_TEST_ENABLE                             STD_OFF
#if (DBG_MCU_SW_UNIT_TEST_ENABLE == STD_ON)
/*
 * brief    following definition the SWC unit test switch
 *          STD_ON : Enable the unit test function,may be the developer can be write unit code(include variable and code) 
 *          STD_OFF : Enable the unit test function 
 * 
 * Notes    the macros name shall definition to DBG_<SWCs>_DEBUG_ENABLE
 *
 * */
#define DBG_CSCPLATFORM_UNIT_TEST_ENABLE						STD_OFF
#define DBG_CPR_UNIT_TEST_ENABLE						        STD_OFF
#define DBG_CPS_UNIT_TEST_ENABLE						        STD_OFF
#define DBG_MED_UNIT_TEST_ENABLE						        STD_OFF
#define DBG_SED_UNIT_TEST_ENABLE						        STD_OFF
#define DBG_SDC_UNIT_TEST_ENABLE						        STD_OFF
#define DBG_ESM_UNIT_TEST_ENABLE						        STD_OFF
#define DBG_CDM_UNIT_TEST_ENABLE						        STD_OFF
#define DBG_VDYADAPTER_UNIT_TEST_ENABLE						    STD_OFF
#define DBG_FCTADAPTER_UNIT_TEST_ENABLE						    STD_OFF
#define DBG_LCFADAPTER_UNIT_TEST_ENABLE						    STD_OFF
#define DBG_HLAADAPTER_UNIT_TEST_ENABLE						    STD_OFF
#define DBG_MTSIADAPTER_UNIT_TEST_ENABLE					    STD_OFF
#endif

/*==================[macros:misc enable switch]=========================*/
#define DBG_MCU_SW_DV_TEST_ENABLE					            STD_OFF     /*Use for control DV monitor info output*/

#endif /*_DBG_CFG_H_*/
