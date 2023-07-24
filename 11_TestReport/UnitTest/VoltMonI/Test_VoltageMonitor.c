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
#include "VoltageMonitor.h" 

#define VOLTAGEMONITOR_FUNCTION_ENABLED  STD_ON

static s_VoltMonI_voltmonitor_t s_VoltMonitor;
/** \brief Intialization information of VoltMonI module */
static boolean VoltMonI_Initialized = (Boolean)FALSE;
/** \brief The internal volatge state of VoltMonI module */
static e_VoltMonI_voltageState_t e_InternalVoltState = VoltMonI_VoltageInit;
/** \brief The internal previous volatge state of VoltMonI module */
static e_VoltMonI_voltageState_t e_LastInternalVoltState = VoltMonI_VoltageInit;

/** See http://eportx.auto.contiwan.com/ebswiki/index.php/Courage/HowtoWriteUnitTest for further explanations */

 
COU_TEST(test_VoltMonI_InitFunction,"Annotation")
{
    COU_CALL(VoltMonI_InitFunction(),"");
} 
 
COU_TEST(test_VoltMonI_MainFunction,"Annotation")
{   	
    COU_CALL(VoltMonI_MainFunction(),"");
} 
               
COU_TEST(test_VoltMonI_u_SetInputVoltage,"Annotation")
{   	
    float f_InputVolt;
	Std_ReturnType u_RetVal;
	
    COU_CALL(u_RetVal = VoltMonI_u_SetInputVoltage(f_InputVolt),"");
} 

COU_TEST(test_VoltMonI_u_GetCurrentVoltageState,"Annotation")
{   	
    COU_CALL(VoltMonI_u_GetCurrentVoltageState(),"");
} 

COU_TEST(test_VoltMonI_u_GetAction_Disablecommunication,"Annotation")
{   	
    COU_CALL(VoltMonI_u_GetAction_Disablecommunication(),"");
} 

COU_TEST(test_VoltMonI_u_SetAction_Disablecommunication,"Annotation")
{   	
    boolean b_State;
    Std_ReturnType u_RetVal;
	
	COU_CALL(u_RetVal = VoltMonI_u_SetAction_Disablecommunication(b_State),"");
}

COU_TEST(test_VoltMonI_u_GetAction_DisableECU,"Annotation")
{   	
    COU_CALL(VoltMonI_u_GetAction_DisableECU(),"");
}

COU_TEST(test_VoltMonI_u_SetAction_DisableECU,"Annotation")
{   	
    boolean b_State;
    Std_ReturnType u_RetVal;
	
	COU_CALL(u_RetVal = VoltMonI_u_SetAction_DisableECU(b_State),"");
}

COU_TEST(test_VoltMonI_u_GetAction_DisableSoc,"Annotation")
{   	
    COU_CALL(VoltMonI_u_GetAction_DisableSoc(),"");
}

COU_TEST(test_VoltMonI_u_SetAction_DisableSoc,"Annotation")
{   	
    boolean b_State;
    Std_ReturnType u_RetVal;
	
	COU_CALL(u_RetVal = VoltMonI_u_SetAction_DisableSoc(b_State),"");
}


/** Unordered list of all test methods of the related suite. */
cou_test_t someTestPackage[] =
{
   COU_ADD_TEST(test_VoltMonI_InitFunction),
   COU_ADD_TEST(test_VoltMonI_MainFunction),
   COU_ADD_TEST(test_VoltMonI_u_SetInputVoltage),
   COU_ADD_TEST(test_VoltMonI_u_GetCurrentVoltageState),
   COU_ADD_TEST(test_VoltMonI_u_GetAction_Disablecommunication),
   COU_ADD_TEST(test_VoltMonI_u_SetAction_Disablecommunication),
   COU_ADD_TEST(test_VoltMonI_u_GetAction_DisableECU),
   COU_ADD_TEST(test_VoltMonI_u_SetAction_DisableECU),
   COU_ADD_TEST(test_VoltMonI_u_GetAction_DisableSoc),
   COU_ADD_TEST(test_VoltMonI_u_SetAction_DisableSoc),
   COU_ADD_TEST_END,
}; /* someTestPackage */

/**
 * Called by testrunner directly before each of all tests of the suite.
 * When called before the very first test, it will be called after suite_SomeComposite_suiteIdHere_SuiteInitFunc.
 * See http://eportx.auto.contiwan.com/ebswiki/index.php/Courage/HowtoWriteUnitTest for further documentation on test execution sequence.
 */
COU_INIT(someTestInit, "Annotation")
{

} /* someTestInit */

cou_suite_t suites[] =
{
   COU_ADD_SUITE(someSuite, someTestPackage, someTestInit, "VoltageMonitor.c"),
   COU_ADD_SUITE_END,
};
