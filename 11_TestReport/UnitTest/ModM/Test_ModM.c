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
#include "Qsm_Lcfg.h" 
#include "ModM.h"

static boolean ModM_InitOnce = (Boolean)FALSE;
static s_ModM_InstStruct_t s_ModM_handle;

/** See http://eportx.auto.contiwan.com/ebswiki/index.php/Courage/HowtoWriteUnitTest for further explanations */

 
COU_TEST(test_ModM_InitFunction,"Annotation")
{
	s_ModM_Config_t ConfigPtr; 
	
    COU_CALL(ModM_InitFunction(&ConfigPtr),"");
} 
 
COU_TEST(test_ModM_MainExec,"Annotation")
{   	
    COU_CALL(ModM_MainExec(),"");
} 
               
COU_TEST(test_ModM_u_GetCurrentMode,"Annotation")
{   	
    uint8 mode;
	Std_ReturnType u_RetVal;
	
    COU_CALL(u_RetVal = ModM_u_GetCurrentMode(&mode),"");
} 

COU_TEST(test_ModM_u_GetNextMode,"Annotation")
{   	
    uint8 mode;
	Std_ReturnType u_RetVal;
	
    COU_CALL(u_RetVal = ModM_u_GetNextMode(&mode),"");
} 




/** Unordered list of all test methods of the related suite. */
cou_test_t someTestPackage[] =
{
   COU_ADD_TEST(test_ModM_InitFunction),
   COU_ADD_TEST(test_ModM_MainExec),
   COU_ADD_TEST(test_ModM_u_GetCurrentMode),
   COU_ADD_TEST(test_ModM_u_GetNextMode),
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
