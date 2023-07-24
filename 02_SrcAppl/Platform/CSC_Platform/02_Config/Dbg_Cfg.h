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

#include "comcoordinator.h"
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

#define CUSTOMER_VERSION                                STD_OFF   //AEB Value -2
#define AEB_VERSION                                     STD_ON   //AEB Value -10
#define FOT_VERSION                                     STD_OFF    //AEB Value -2

#if((CUSTOMER_VERSION == STD_ON && AEB_VERSION == STD_ON && FOT_VERSION == STD_ON) \
    ||(CUSTOMER_VERSION == STD_ON && AEB_VERSION == STD_ON && FOT_VERSION == STD_OFF)\
    ||(CUSTOMER_VERSION == STD_ON && AEB_VERSION == STD_OFF && FOT_VERSION == STD_ON)\
    ||(CUSTOMER_VERSION == STD_OFF && AEB_VERSION == STD_ON && FOT_VERSION == STD_ON))
#error "Only one marco can be open"
#elif(CUSTOMER_VERSION == STD_OFF && AEB_VERSION == STD_OFF && FOT_VERSION == STD_OFF) 
#error "At least one marco shoule be open"
#else
//Do nothing
#endif


#if (CUSTOMER_VERSION == STD_ON)

#define DBG_VDYADAPTER_ALGO_ENABLE				                STD_ON      /*Vdy Algo enable switch*/
#define DBG_VDYADAPTER_MEASFREEZE_ENABLE            			STD_OFF      /*Vdy Adapter related MTS data meas freeze*/
#define DBG_FCTADAPTER_ALGO_ENABLE				                STD_ON     /*Fct Algo enable switch*/
#define DBG_FCTADAPTER_MEASFREEZE_ENABLE   			            STD_OFF      /*Fct Adapter related MTS data meas freeze*/
#define DBG_LCFADAPTER_ALGO_ENABLE				                STD_ON     /*Lcf Algo enable switch*/
#define DBG_LCFADAPTER_MEASFREEZE_ENABLE   			            STD_OFF     /*Lcf Adapter related MTS data meas freeze*/
#define DBG_HLAADAPTER_ALGO_ENABLE				                STD_OFF     /*Hla Algo enable switch(Not used in C673)*/
#define DBG_HLAADAPTER_MEASFREEZE_ENABLE               			STD_OFF     /*Hla Adapter releated MTS data meas freeze*/
#define DBG_AEB_DEBUG_ENABLE                                    STD_OFF      /*STD_ON == AEB Value -10, STD_OFF == AEB Value -2*/
#define DBG_CDM_EOL_MODE_ENABLE                                 STD_ON      /*EOL mode gate Swtich for AEB*/
#define DBG_FIM_MODULE_ENABLE                                   STD_ON      /*STD_ON == Enable Fim, STD_OFF == Disable Fim*/   
#define DBG_ALL_MTSI_ID_FILTER_ENABLE                           STD_OFF     /*STD_ON == Disable FILTER, STD_OFF == FILTER All ID*/
#define DBG_LOGGINGIF_CAN_ENABLE                                STD_OFF     /*STD_ON == Disable LOGGINGIF, STD_OFF == Open LOGGINGIF*/
#define DBG_FUSA_TEST_ENABLE                                    STD_OFF     /*STD_ON == OPEN FUSA, STD_OFF == Disable FUSA*/

#endif

#if (FOT_VERSION == STD_ON)

#define DBG_VDYADAPTER_ALGO_ENABLE				                STD_ON      /*Vdy Algo enable switch*/
#define DBG_VDYADAPTER_MEASFREEZE_ENABLE            			STD_ON      /*Vdy Adapter related MTS data meas freeze*/
#define DBG_FCTADAPTER_ALGO_ENABLE				                STD_ON     /*Fct Algo enable switch*/
#define DBG_FCTADAPTER_MEASFREEZE_ENABLE   			            STD_ON      /*Fct Adapter related MTS data meas freeze*/
#define DBG_LCFADAPTER_ALGO_ENABLE				                STD_ON     /*Lcf Algo enable switch*/
#define DBG_LCFADAPTER_MEASFREEZE_ENABLE   			            STD_ON     /*Lcf Adapter related MTS data meas freeze*/
#define DBG_HLAADAPTER_ALGO_ENABLE				                STD_OFF     /*Hla Algo enable switch(Not used in C673)*/
#define DBG_HLAADAPTER_MEASFREEZE_ENABLE               			STD_OFF     /*Hla Adapter releated MTS data meas freeze*/
#define DBG_AEB_DEBUG_ENABLE                                    STD_OFF      /*STD_ON == AEB Value -10, STD_OFF == AEB Value -2*/
#define DBG_CDM_EOL_MODE_ENABLE                                 STD_ON     /*EOL mode gate Swtich for AEB*/
#define DBG_FIM_MODULE_ENABLE                                   STD_ON     /*STD_ON == Enable Fim, STD_OFF == Disable Fim*/   
#define DBG_ALL_MTSI_ID_FILTER_ENABLE                           STD_ON     /*STD_ON == Disable FILTER, STD_OFF == FILTER All ID*/
#define DBG_LOGGINGIF_CAN_ENABLE                                STD_OFF     /*STD_ON == Disable LOGGINGIF, STD_OFF == Open LOGGINGIF*/
#define DBG_FUSA_TEST_ENABLE                                    STD_OFF     /*STD_ON == OPEN FUSA, STD_OFF == Disable FUSA*/

#endif


#if (AEB_VERSION == STD_ON)

#define DBG_VDYADAPTER_ALGO_ENABLE				                STD_ON      /*Vdy Algo enable switch*/
#define DBG_VDYADAPTER_MEASFREEZE_ENABLE            			STD_ON      /*Vdy Adapter related MTS data meas freeze*/
#define DBG_FCTADAPTER_ALGO_ENABLE				                STD_ON     /*Fct Algo enable switch*/
#define DBG_FCTADAPTER_MEASFREEZE_ENABLE   			            STD_ON      /*Fct Adapter related MTS data meas freeze*/
#define DBG_LCFADAPTER_ALGO_ENABLE				                STD_ON     /*Lcf Algo enable switch*/
#define DBG_LCFADAPTER_MEASFREEZE_ENABLE   			            STD_ON     /*Lcf Adapter related MTS data meas freeze*/
#define DBG_HLAADAPTER_ALGO_ENABLE				                STD_OFF     /*Hla Algo enable switch(Not used in C673)*/
#define DBG_HLAADAPTER_MEASFREEZE_ENABLE               			STD_OFF     /*Hla Adapter releated MTS data meas freeze*/
#define DBG_AEB_DEBUG_ENABLE                                    STD_ON      /*STD_ON == AEB Value -10, STD_OFF == AEB Value -2*/
#define DBG_CDM_EOL_MODE_ENABLE                                 STD_ON     /*EOL mode gate Swtich for AEB*/
#define DBG_FIM_MODULE_ENABLE                                   STD_ON     /*STD_ON == Enable Fim, STD_OFF == Disable Fim*/   
#define DBG_ALL_MTSI_ID_FILTER_ENABLE                           STD_ON     /*STD_ON == Disable FILTER, STD_OFF == FILTER All ID*/
#define DBG_LOGGINGIF_CAN_ENABLE                                STD_OFF     /*STD_ON == Disable LOGGINGIF, STD_OFF == Open LOGGINGIF*/
#define DBG_FUSA_TEST_ENABLE                                    STD_ON      /*STD_ON == OPEN FUSA, STD_OFF == Disable FUSA*/

#endif

/**
 * The Macro use for configurated the Fusa related function
 * DBG_FUSA_ENABLE is STD_ON,The release folder name shall be added suffix for "_F"
 * DBG_FUSA_ENABLE is STD_OFF,The release folder name keep in origin name
 * DBG_FUSA_MTS_ENABLE is the Fusa releted data meas freeze data to MTS via HSSL bus.
 * 
 * Notes:
 * 1.The non-fusa release version,the DBG_FUSA_ENABLE shall set to STD_OFF
 * 2.The internal test version(shall be enable MTS),the DBG_FUSA_MTS_ENABLE shall set to STD_ON.
 *   The internal test version,test data for reec,The SWE shall analysis,to fixed the fusa related issue.
 * 3.The customer version,the DBG_FUSA_MTS_ENABLE shall set to STD_OFF.
*/
#if (STD_ON==DBG_FUSA_TEST_ENABLE)
    #define DBG_FUSA_ENABLE                                         STD_ON
    /*DBG_FUSA_MTS_ENABLE == STD_ON:Enable store reset reason in to NVM and can be read via UDS.RID.0xFD2A*/
    #define DBG_FUSA_MTS_ENABLE                                     STD_ON
#else
    #define DBG_FUSA_ENABLE                                         STD_OFF
    /*DBG_FUSA_MTS_ENABLE == STD_ON:Enable store reset reason in to NVM and can be read via UDS.RID.0xFD2A*/
    #define DBG_FUSA_MTS_ENABLE                                     STD_OFF
#endif 

/*==================[macros:debug enable switch]=============================*/
/*
 * \brief 	DBG_MCU_SW_DEBUG_ENABLE,
 * 			When this switch is OFF,all of software components will disable the debug function.
 * */
#define DBG_MCU_SW_DEBUG_ENABLE				                    STD_ON

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
#define DBG_FCTADAPTER_DEBUG_ENABLE						        STD_ON
#define DBG_LCFADAPTER_DEBUG_ENABLE						        STD_ON
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
#define DBG_ESH_UNIT_TEST_ENABLE                                STD_OFF

#endif

/*==================[macros:misc enable switch]=========================*/
#define DBG_MCU_SW_DV_TEST_ENABLE					            STD_OFF     /*Use for control DV monitor info output*/

//Please don't remove the below macros, use to fix abnormal wakeup issue.
#define DBG_CANIF_TRANSMIT_ENTRY(CanTxPduId,PduInfoPtr)       CanIfTransmit_UserCallout()


#endif /*_DBG_CFG_H_*/
