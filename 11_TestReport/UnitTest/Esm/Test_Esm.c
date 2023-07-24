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
#include "WdgM.h"


static boolean b_SocPowerOnRequest = TRUE; 
static boolean b_SocShutdownReuqest = FALSE; 
static boolean b_RunSocshutdownLoop = FALSE; 
static boolean b_SocSafetyPoweroff = FALSE; 
static boolean b_CameraPowerOnRequest = TRUE; 
static boolean b_CameraPowerOffRequest = FALSE; 
static boolean b_SocStartupCompleted = FALSE; 

/** See http://eportx.auto.contiwan.com/ebswiki/index.php/Courage/HowtoWriteUnitTest for further explanations */

 
COU_TEST(test_Esm_InitFunction,"Annotation")
{
    COU_CALL(Esm_InitFunction(),"");
} 
 
COU_TEST(test_Esm_MainFunction,"Annotation")
{   	
    COU_CALL(Esm_MainFunction(),"");
	
	COU_CALL(Esm_MainFunction(),"");

	COU_CALL(Esm_MainFunction(),"");
} 
               
COU_TEST(test_Esm_v_Soc_PowerOff,"Annotation")
{   	
    COU_CALL(Esm_v_Soc_PowerOff(),"");
} 

COU_TEST(test_Esm_v_Soc_PowerOn,"Annotation")
{   	
    COU_CALL(Esm_v_Soc_PowerOn(),"");
} 

COU_TEST(test_Esm_v_Soc_Reset,"Annotation")
{   	
    COU_CALL(Esm_v_Soc_Reset(),"");
} 

COU_TEST(test_Esm_v_Camera_PowerOff,"Annotation")
{   	
    COU_CALL(Esm_v_Camera_PowerOff(),"");
}

COU_TEST(test_Esm_v_Camera_PowerOn,"Annotation")
{   	
    COU_CALL(Esm_v_Camera_PowerOn(),"");
}

COU_TEST(test_Esm_v_Ecu_SoftReset,"Annotation")
{   	
    COU_CALL(Esm_v_Ecu_SoftReset(),"");
}

COU_TEST(test_Esm_v_Ecu_HardReset,"Annotation")
{   	
    COU_CALL(Esm_v_Ecu_HardReset(),"");
}

COU_TEST(test_Esm_v_System_Shutdown,"Annotation")
{   	
    COU_CALL(Esm_v_System_Shutdown(),"");
}

COU_TEST(test_Esm_v_Safety_Shutdown,"Annotation")
{   	
    b_SocSafetyPoweroff = TRUE;
    COU_CALL(Esm_v_Safety_Shutdown(),"");
}

COU_TEST(test_Esm_GetSocStartupFlag,"Annotation")
{   	
    COU_CALL(Esm_GetSocStartupFlag(),"");
}

/** Unordered list of all test methods of the related suite. */
cou_test_t someTestPackage[] =
{
   COU_ADD_TEST(test_Esm_InitFunction),
   COU_ADD_TEST(test_Esm_MainFunction),
   COU_ADD_TEST(test_Esm_v_Soc_PowerOff),
   COU_ADD_TEST(test_Esm_v_Soc_PowerOn),
   COU_ADD_TEST(test_Esm_v_Soc_Reset),
   COU_ADD_TEST(test_Esm_v_Camera_PowerOff),
   COU_ADD_TEST(test_Esm_v_Camera_PowerOn),
   COU_ADD_TEST(test_Esm_v_Ecu_SoftReset),
   COU_ADD_TEST(test_Esm_v_Ecu_HardReset),
   COU_ADD_TEST(test_Esm_v_System_Shutdown),
   COU_ADD_TEST(test_Esm_v_Safety_Shutdown),
   COU_ADD_TEST(test_Esm_GetSocStartupFlag),
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
   COU_ADD_SUITE(someSuite, someTestPackage, someTestInit, "Esm.c"),
   COU_ADD_SUITE_END,
};
