//* **********************************************************************
//  COMPANY:         $CompanyInfo: CONFIDENTIAL AND PROPRIETARY PROPERTY OF CONTINENTAL AG , A.D.C. GmbH  -  ALL RIGHTS RESERVED $
//  
//  PROJECT:         MFC30x_MCU
//  CPU:             MPC5675K
//  
//  PACKAGE:         $Source: ic_initdata.h $ $Revision: 1.1 $
//  MKS Date:        $Date: 2021/12/13 17:25:54CET $
//  
//  RHAPSODY:        7.5.3
//  COMPONENT:       IC
//  CONFIGURATION:   DefaultConfig
//  MODEL ELEMENT:   ic_initdata
//  MODULNAME:       ..\..\..\04_Engineering\01_Source_Code\Algo\ic\ic_initdata.h
//  LOGIN:           uidt3974  
//  
//  ==========================================================================================
//  The following QAC messages are suppressed for this module:
//  
//  Array size defined implicitly by the number of initializers:
//    PRQA S 3674,3684 EOF
//  
//  We have of course tons of 'magic numbers':
//    PRQA S 3120 EOF
//  
//  Initializer arrays are used in other modules:
//    PRQA S 3211 EOF
//  
//  
//  AUTHOR:          $Author: Wang, David (Wangd3) $
//! CREATION DATE:   Thu, 19, Jul 2012  5:43 W. Europe Daylight Time PM 
//**************************************************************************** */

#ifndef ic_initdata_H
#define ic_initdata_H

/*## dependency ic_types */
#include "ic_types.h"
/*## package Ic_Pkg */

/*## class TopLevel::ic_initdata */
/*#[ ignore */
//  ==========================================================================================
//  The following QAC messages are suppressed for this module:
//  
//  Array size defined implicitly by the number of initializers:
//    PRQA S 3674,3684 EOF
//  
//  We have of course tons of 'magic numbers':
//    PRQA S 3120 EOF
//  
//  Initializer arrays are used in other modules:
//    PRQA S 3211 EOF
/*#]*/


/*#[ ignore */

#ifdef __cplusplus
extern "C"
{
#endif

/*#]*/


/*## attribute ICINIT_caui16_SensorInitData */
extern const IC_S_RegDataPair ICINIT_caui16_SensorInitData[];

/*## attribute ICINIT_caui16_SensorExitATestInitData */
extern const IC_S_RegDataPair ICINIT_caui16_SensorExitATestInitData[];

/*## attribute ICINIT_caui16_SensorEnterATestInitData */
extern const IC_S_RegDataPair ICINIT_caui16_SensorEnterATestInitData[];

/*## attribute ICINIT_caui16_SensorInitDataEntries */
extern const uint16 ICINIT_caui16_SensorInitDataEntries;

/*## attribute ICINIT_caui16_SensorEnterATestInitDataEntries */
extern const uint16 ICINIT_caui16_SensorEnterATestInitDataEntries;

/*## attribute ICINIT_caui16_SensorExitATestInitDataEntries */
extern const uint16 ICINIT_caui16_SensorExitATestInitDataEntries;

/***    User explicit entries    ***/



/*#[ ignore */

#ifdef __cplusplus
}
#endif

/*#]*/


#endif
/*********************************************************************
	File Path: ..\..\..\04_Engineering\01_Source_Code\Algo\ic\ic_initdata.h
*********************************************************************/
