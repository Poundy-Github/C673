/**
 * @file
 * $RCSfile: mockup__template_test.c $
 * $Revision: 1.0 $
 * $Date: 2022/11/09 14:29:56CEST $
 * Confidential and proprietary. This document and its contents are the
 * exclusive property of Continental Teves AG & Co. OHG (Teves) and Conti Temic
 * microelectronic GmbH (Temic) and their associated companies. They are not to
 * be copied, distributed, or otherwise disclosed or used without the prior
 * written consent of Teves and Temic. All rights reserved.
 *
 * @author
 * Jinlong Zhang (luif30295)
 * @brief
 * Used for MFC5J3 C673
 * Courage test suite file of SomeComposite
 * 
 */

#include <courage.h>
#include <mockup.h>

#include "Std_Types.h" 
#include <Rte_Type.h>
#include <Rte_Comco.h>
#include "comcoordinator.h"

static s_Comco_StatusInfo_t  s_Comco_StatusInfoData;


/** See http://eportx.auto.contiwan.com/ebswiki/index.php/Courage/HowtoWriteUnitTest for further explanations */

/// test_Comco_Init 
/// @description        
/// glob_in                  
/// @pre                     
/// @result 
//COU_TEST(test_Comco_Init,"Annotation")
//{
    //COU_CALL(Comco_Init(),"");
//} 

/// test_Comco_MainFunction 
/// @description        
/// glob_in                  
/// @pre                     
/// @result 
COU_TEST(test_Comco_MainFunction,"Annotation")
{   	
	COU_SET(s_Comco_StatusInfoData.GlobVarsInitialized, 0x01u, "s_Comco_StatusInfoData.GlobVarsInitialized is initialized to TRUE");	
	COU_ASSERT_EQUAL(s_Comco_StatusInfoData.GlobVarsInitialized, 0x01u, "Result should be some");
    COU_CALL(Comco_MainFunction(),"");
	
	COU_SET(s_Comco_StatusInfoData.GlobVarsInitialized, 0x00u, "s_Comco_StatusInfoData.GlobVarsInitialized is initialized to FALSE");	
	COU_ASSERT_EQUAL(s_Comco_StatusInfoData.GlobVarsInitialized, 0x00u, "Result should be some");
    COU_CALL(Comco_MainFunction(),"");
} 

/// test_Comco_u_NMWakupFlag_Read_01 
/// @description        
/// glob_in                  
/// @pre                     
/// @result                 
COU_TEST(test_Comco_u_NMWakupFlag_Read,"Annotation")
{
    /* Inputs */                
    /* Tester data declarations */ 
    uint8_t u_WakeupFlag;	
    Std_ReturnType	u_Retval;
    /* Initialization of data Structures */     
    /* Assigning address to pointers */       
    /* Input Initialization */ 
	COU_CALL(u_Retval = Comco_u_NMWakupFlag_Read(&u_WakeupFlag),"Call the function Comco_u_NMWakupFlag_Read");
	 
	COU_SET(s_Comco_StatusInfoData.WakeupFlag, TRUE, "s_Comco_StatusInfoData.WakeupFlag is initialized to TRUE");	
	COU_ASSERT_EQUAL(s_Comco_StatusInfoData.WakeupFlag, TRUE, "Result should be some");
    /* Output Pre initialization */
    COU_SET(u_Retval, RTE_E_OK, "u_Retval is initialized to RTE_E_OK");	
	COU_SET(u_WakeupFlag, 0, "u_Retval is initialized to RTE_E_OK");	
    /* Call the tested function */                  
    COU_CALL(u_Retval = Comco_u_NMWakupFlag_Read(&u_WakeupFlag),"Call the function Comco_u_NMWakupFlag_Read");
	/* Compare the function output with the expected one */ 
	COU_ASSERT_EQUAL(u_WakeupFlag, 1, "Result should be some");
} 

/// test_Comco_u_NMWakupFlag_Read_02 
/// @description        
/// glob_in                  
/// @pre                     
/// @result                 
// COU_TEST(test_Comco_u_NMWakupFlag_Read_02,"Annotation")
// {
    // /* Inputs */                
    // /* Tester data declarations */ 
    // uint8_t u_WakeupFlag;	
    // Std_ReturnType	u_Retval;
    // /* Initialization of data Structures */     
    // /* Assigning address to pointers */       
    // /* Input Initialization */ 
	// COU_SET(s_Comco_StatusInfoData.WakeupFlag, FALSE, "s_Comco_StatusInfoData.WakeupFlag is initialized to TRUE");	
    // /* Output Pre initialization */
    // COU_SET(u_Retval, RTE_E_OK, "u_Retval is initialized to RTE_E_OK");	 
    // /* Call the tested function */                  
    // COU_CALL(u_Retval = Comco_u_NMWakupFlag_Read(&u_WakeupFlag),"Call the function Comco_u_NMWakupFlag_Read");
	// /* Compare the function output with the expected one */ 
	// COU_ASSERT_EQUAL(u_WakeupFlag, 0, "Result should be some");
// } 

COU_TEST(test_Comco_u_nmPreviousState_Read,"Annotation")
{
    /* Inputs */                
    /* Tester data declarations */ 
    uint8_t u_PreNmState;	
    Std_ReturnType	u_Retval;
    /* Initialization of data Structures */     
    /* Assigning address to pointers */       
    /* Input Initialization */ 
	//COU_SET(s_Comco_StatusInfoData.WakeupFlag, FALSE, "s_Comco_StatusInfoData.WakeupFlag is initialized to TRUE");	
    /* Output Pre initialization */
    COU_SET(u_Retval, RTE_E_OK, "u_Retval is initialized to RTE_E_OK");	
    /* Call the tested function */                  
    COU_CALL(u_Retval = Comco_u_nmPreviousState_Read(&u_PreNmState),"Call the function Comco_u_NMWakupFlag_Read");
	/* Compare the function output with the expected one */ 
	//COU_ASSERT_EQUAL(u_PreNmState, 0, "Result should be some");
}
COU_TEST(test_Comco_u_nmCurrentState_Read,"Annotation")
{
    /* Inputs */                
    /* Tester data declarations */ 
    uint8_t u_CurNmState;	
    Std_ReturnType	u_Retval;
    /* Initialization of data Structures */     
    /* Assigning address to pointers */       
    /* Input Initialization */ 
	//COU_SET(s_Comco_StatusInfoData.WakeupFlag, FALSE, "s_Comco_StatusInfoData.WakeupFlag is initialized to TRUE");	
    /* Output Pre initialization */
    COU_SET(u_Retval, RTE_E_OK, "u_Retval is initialized to RTE_E_OK");	
    /* Call the tested function */                  
    COU_CALL(u_Retval = Comco_u_nmCurrentState_Read(&u_CurNmState),"Call the function Comco_u_NMWakupFlag_Read");
	/* Compare the function output with the expected one */ 
	//COU_ASSERT_EQUAL(u_PreNmState, 0, "Result should be some");
}
COU_TEST(test_Nm_PduRxIndication,"Annotation")
{
    /* Inputs */                
    /* Tester data declarations */ 
    NetworkHandleType nmNetworkHandle;	
	
    /* Call the tested function */                  
    COU_CALL(Nm_PduRxIndication(nmNetworkHandle),"Call the function Nm_PduRxIndication");
	/* Compare the function output with the expected one */ 

}
COU_TEST(test_Nm_StateChangeNotificationCallout,"Annotation")
{
	/* Tester data declarations */ 
    uint8 nmNetworkHandle;	
	uint8 nmPreviousState;
	uint8 nmCurrentState;
	
	COU_SET(nmCurrentState, 0, "nmCurrentState is initialized to NM_STATE_UNINIT");
    /* Call the tested function */                  
    COU_CALL(Nm_StateChangeNotificationCallout(nmNetworkHandle, nmPreviousState, nmCurrentState),"Call the function Nm_StateChangeNotificationCallout");
	/* Compare the function output with the expected one */ 
	COU_ASSERT_EQUAL(s_Comco_StatusInfoData.nmCurrentState, nm_state_unit, "Result should be some");
	
	COU_SET(nmCurrentState, 2, "nmCurrentState is initialized to NM_STATE_PREPARE_BUS_SLEEP");
    /* Call the tested function */                  
    COU_CALL(Nm_StateChangeNotificationCallout(nmNetworkHandle, nmPreviousState, nmCurrentState),"Call the function Nm_StateChangeNotificationCallout");
	
	COU_SET(nmCurrentState, 3, "nmCurrentState is initialized to NM_STATE_READY_SLEEP");
    /* Call the tested function */                  
    COU_CALL(Nm_StateChangeNotificationCallout(nmNetworkHandle, nmPreviousState, nmCurrentState),"Call the function Nm_StateChangeNotificationCallout");
	
	COU_SET(nmCurrentState, 4, "nmCurrentState is initialized to NM_STATE_NORMAL_OPERATION");
    /* Call the tested function */                  
    COU_CALL(Nm_StateChangeNotificationCallout(nmNetworkHandle, nmPreviousState, nmCurrentState),"Call the function Nm_StateChangeNotificationCallout");
	
	COU_SET(nmCurrentState, 5, "nmCurrentState is initialized to NM_STATE_REPEAT_MESSAGE");
    /* Call the tested function */                  
    COU_CALL(Nm_StateChangeNotificationCallout(nmNetworkHandle, nmPreviousState, nmCurrentState),"Call the function Nm_StateChangeNotificationCallout");
	
	COU_SET(nmCurrentState, 6, "nmCurrentState is initialized to other invalid value");
    /* Call the tested function */                  
    COU_CALL(Nm_StateChangeNotificationCallout(nmNetworkHandle, nmPreviousState, nmCurrentState),"Call the function Nm_StateChangeNotificationCallout");
	
	COU_SET(nmCurrentState, 1, "nmCurrentState is initialized to NM_STATE_BUS_SLEEP");
	COU_SET(s_Comco_StatusInfoData.nmPreviousState, nm_state_Prepare_bus_sleep, "nmPreviousState is initialized to nm_state_Prepare_bus_sleep");
    /* Call the tested function */                  
    COU_CALL(Nm_StateChangeNotificationCallout(nmNetworkHandle, nmPreviousState, nmCurrentState),"Call the function Nm_StateChangeNotificationCallout");
	
	COU_SET(nmCurrentState, 1, "nmCurrentState is initialized to NM_STATE_BUS_SLEEP");
	s_Comco_StatusInfoData.nmPreviousState = 0;
    /* Call the tested function */                  
    COU_CALL(Nm_StateChangeNotificationCallout(nmNetworkHandle, nmPreviousState, nmCurrentState),"Call the function Nm_StateChangeNotificationCallout");
}

COU_TEST(test_CanIfTransmit_UserCallout,"Annotation")
{
    COU_CALL(CanIfTransmit_UserCallout(),"");
}

/** Unordered list of all test methods of the related suite. */
cou_test_t someTestPackage[] =
{
   //COU_ADD_TEST(test_Comco_Init),
   COU_ADD_TEST(test_Comco_MainFunction),
   COU_ADD_TEST(test_Comco_u_NMWakupFlag_Read),
   COU_ADD_TEST(test_Comco_u_nmPreviousState_Read),
   COU_ADD_TEST(test_Comco_u_nmCurrentState_Read),
   COU_ADD_TEST(test_Nm_PduRxIndication),
   COU_ADD_TEST(test_Nm_StateChangeNotificationCallout),
   COU_ADD_TEST(test_CanIfTransmit_UserCallout),
   COU_ADD_TEST_END,
}; /* someTestPackage */

/**
 * Called by testrunner directly before each of all tests of the suite.
 * When called before the very first test, it will be called after suite_SomeComposite_suiteIdHere_SuiteInitFunc.
 * See http://eportx.auto.contiwan.com/ebswiki/index.php/Courage/HowtoWriteUnitTest for further documentation on test execution sequence.
 */
COU_INIT(someTestInit, "Annotation")
{
	COU_CALL(Comco_Init(),"");
} /* someTestInit */

cou_suite_t suites[] =
{
   COU_ADD_SUITE(someSuite, someTestPackage, someTestInit, "comcoordinator.c"),
   COU_ADD_SUITE_END,
};
