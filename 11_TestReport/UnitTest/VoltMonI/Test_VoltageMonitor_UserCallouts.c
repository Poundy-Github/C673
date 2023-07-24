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
#include <Rte_VoltMonI.h>
#include "Esm.h"

static s_VoltMonI_voltmonitor_t s_VoltMonitor;

/** See http://eportx.auto.contiwan.com/ebswiki/index.php/Courage/HowtoWriteUnitTest for further explanations */

 
COU_TEST(test_VoltMonI_u_StateChangeNotificationCallout,"Annotation")
{
	Std_ReturnType ui8_RetVal;
	e_VoltMonI_voltageState_t VoltMonI_PreviousState;
	e_VoltMonI_voltageState_t VoltMonI_CurrentState;
	 
    COU_CALL(ui8_RetVal = VoltMonI_u_StateChangeNotificationCallout(VoltMonI_PreviousState,VoltMonI_CurrentState),"");
} 
 
COU_TEST(test_VoltMonI_u_StartupPrecondition,"Annotation")
{   	
    COU_CALL(VoltMonI_u_StartupPrecondition(),"");
} 
               
COU_TEST(test_VoltMonI_u_Input,"Annotation")
{   	
    COU_CALL(VoltMonI_u_Input(),"");
} 

COU_TEST(test_VoltMonI_u_Output,"Annotation")
{   	
    COU_CALL(VoltMonI_u_Output(),"");
} 

COU_TEST(test_VoltMonI_u_EntryInitVolt_CallBack,"Annotation")
{   	
    COU_CALL(VoltMonI_u_EntryInitVolt_CallBack(),"");
} 

COU_TEST(test_VoltMonI_u_EntryNormalVolt_CallBack,"Annotation")
{   	
    COU_CALL(VoltMonI_u_EntryNormalVolt_CallBack(),"");
}

COU_TEST(test_VoltMonI_u_EntryLowVolt_CallBack,"Annotation")
{   	
    COU_CALL(VoltMonI_u_EntryLowVolt_CallBack(),"");
}

COU_TEST(test_VoltMonI_u_EntryUnderLowVolt_CallBack,"Annotation")
{   	
    COU_CALL(VoltMonI_u_EntryUnderLowVolt_CallBack(),"");
}

COU_TEST(test_VoltMonI_u_EntryHighVolt_CallBack,"Annotation")
{   	
    COU_CALL(VoltMonI_u_EntryHighVolt_CallBack(),"");
}

COU_TEST(test_VoltMonI_u_EntryOverHighVolt_CallBack,"Annotation")
{   	
    COU_CALL(VoltMonI_u_EntryOverHighVolt_CallBack(),"");
}

COU_TEST(test_VoltMonI_u_EntryMinVolt_CallBack,"Annotation")
{   	
    COU_CALL(VoltMonI_u_EntryMinVolt_CallBack(),"");
}

COU_TEST(test_VoltMonI_u_EntryMaxVolt_CallBack,"Annotation")
{   	
    s_VoltMonitor.globalVoltState = VoltMonI_VoltageMax;
    COU_CALL(VoltMonI_u_EntryMaxVolt_CallBack(),"");
}

/** Unordered list of all test methods of the related suite. */
cou_test_t someTestPackage[] =
{
   COU_ADD_TEST(test_VoltMonI_u_StateChangeNotificationCallout),
   COU_ADD_TEST(test_VoltMonI_u_StartupPrecondition),
   COU_ADD_TEST(test_VoltMonI_u_Input),
   COU_ADD_TEST(test_VoltMonI_u_Output),
   COU_ADD_TEST(test_VoltMonI_u_EntryInitVolt_CallBack),
   COU_ADD_TEST(test_VoltMonI_u_EntryNormalVolt_CallBack),
   COU_ADD_TEST(test_VoltMonI_u_EntryLowVolt_CallBack),
   COU_ADD_TEST(test_VoltMonI_u_EntryUnderLowVolt_CallBack),
   COU_ADD_TEST(test_VoltMonI_u_EntryHighVolt_CallBack),
   COU_ADD_TEST(test_VoltMonI_u_EntryOverHighVolt_CallBack),
   COU_ADD_TEST(test_VoltMonI_u_EntryMinVolt_CallBack),
   COU_ADD_TEST(test_VoltMonI_u_EntryMaxVolt_CallBack),
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
   COU_ADD_SUITE(someSuite, someTestPackage, someTestInit, "VoltageMonitor_UserCallouts.c"),
   COU_ADD_SUITE_END,
};
