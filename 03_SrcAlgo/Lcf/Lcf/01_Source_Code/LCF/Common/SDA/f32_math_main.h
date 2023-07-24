/*~A*/
/*~+:VM Header*/
/* UML source model state: Draft */
/* ## Module Header Start [c768d364-f3d9-4b56-88c0-e0ea8d55b73d] */
/****************************************************************************

COPYRIGHT (C) $Date: 2019/07/03 13:44:20CEST $
$CompanyInfo: CONFIDENTIAL AND PROPRIETARY PROPERTY OF CONTINENTAL AG , A.D.C. GmbH  -  ALL RIGHTS RESERVED $
ALL RIGHTS RESERVED.                                                 
                                                                           
The reproduction, transmission or use of this document or its contents is  
not permitted without express written authority.                           
Offenders will be liable for damages. All rights, including rights created 
by patent grant or registration of a utility model or design, are reserved.
---------------------------------------------------------------------------

$Log: f32_math_main.h  $
Revision 1.1 2019/07/03 13:44:20CEST Nastasa, Elena (uidt4846) 
Initial revision
Member added to project /ADAS/SW/Components/LCF_LateralControlFunctions/04_Engineering/01_Source_Code/LCF/Common/SDA/project.pj
Revision 1.1 2018/07/24 16:50:23CEST Ammermueller Martin (uidv5342) (uidv5342) 
Initial revision
Member added to project /ES/1T/0C/SDA/SDA_Source/SDA_Toolboxes/ACG/Libraries/ecmath_f32/Src/5_2_0/project.pj
Revision 1.12 2018/04/11 08:15:05CEST Ugran Parimala (uid41586) (uid41586) 
Added new functions in F32_math and improvement in accuracy of few of existing functions
Revision 1.11 2018/03/06 08:22:12CET Angadi Hampa (uidu8151) (uidu8151) 
RO : 8197596 : MISRA2012 ANSI VERSIONS
Revision 1.21 2017/06/21 10:56:48CEST Ugran Parimala (uid41586) (uid41586) 
Rework squore check MISRA2012
Revision 1.19 2017/04/14 07:11:06CEST Ganesh Sumangala (uidu8725) (uidu8725) 
FS_0G01_TC2XX_F32MATH_COMP-ABSTRACT
Compiler abstract & validation
Revision 1.18 2017/02/15 10:25:33CET Angadi Hampa (uidu8151) (uidu8151) 
Inline & macros removal from f32_mayh_main.h 
RO : 5728843 : FS_0G01_F32MATH_5.1.0: pow() function correction
Revision 1.17 2017/02/02 05:36:50CET Angadi Hampa (uidu8151) (uidu8151) 
RO : 5728843 : FS_0G01_F32MATH_5.1.0: pow() function correction
Revision 1.16 2016/11/09 06:23:54CET Angadi Hampa (uidu8151) (uidu8151) 
changed to inline : Ceil & floor  fns
Revision 1.15 2016/10/26 10:41:07CEST Angadi Hampa (uidu8151) (uidu8151) 
Correcting the function names of exp & pow
Revision 1.14 2016/09/07 12:52:49CEST Adinarayanagowda Pruthviraj (uidp1961) (uidp1961) 
RO:4786123: FS_0G01_TC2XX_F32_MATH_5.0.0, New req 2
Revision 1.13 2016/09/06 11:01:05CEST Adinarayanagowda Pruthviraj (uidp1961) (uidp1961) 
RO:4786123: FS_0G01_TC2XX_F32_MATH_5.0.0, New req 2

****************************************************************************/
/* ## Module Header End [c768d364-f3d9-4b56-88c0-e0ea8d55b73d] */

/*~E*/
#ifndef F32_MATH_MAIN_H
#define F32_MATH_MAIN_H
/*~A*/
/*~+:Includes*/
#include "f32_math.h"
/*~E*/
/*~A*/
/*~+:Private and Public Operations*/



/*~E*/
#include "iopt_memmap.h"
#endif
