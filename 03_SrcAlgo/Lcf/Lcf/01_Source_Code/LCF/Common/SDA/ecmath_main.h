/*~A*/
/*~+:VM Header*/
/* Used UML Profile version  */
/* ## Module Header Start [1d09789f-0cdd-4387-8fe8-a6aeaddd7201] */
/****************************************************************************

COPYRIGHT (C) $Date: 2019/07/03 13:44:18CEST $
$CompanyInfo: CONFIDENTIAL AND PROPRIETARY PROPERTY OF CONTINENTAL AG , A.D.C. GmbH  -  ALL RIGHTS RESERVED $
ALL RIGHTS RESERVED.                                                 
                                                                           
The reproduction, transmission or use of this document or its contents is  
not permitted without express written authority.                           
Offenders will be liable for damages. All rights, including rights created 
by patent grant or registration of a utility model or design, are reserved.
---------------------------------------------------------------------------

$Log: ecmath_main.h  $
Revision 1.1 2019/07/03 13:44:18CEST Nastasa, Elena (uidt4846) 
Initial revision
Member added to project /ADAS/SW/Components/LCF_LateralControlFunctions/04_Engineering/01_Source_Code/LCF/Common/SDA/project.pj
Revision 1.1 2018/07/24 16:50:38CEST Ammermueller Martin (uidv5342) (uidv5342) 
Initial revision
Member added to project /ES/1T/0C/SDA/SDA_Source/SDA_Toolboxes/ACG/Libraries/Ecmath/Src/3_1_0/project.pj
Revision 1.6 2018/03/06 08:32:30CET Angadi Hampa (uidu8151) (uidu8151) 
RO : 8197610 : MISRA2012 ANSI VERSIONS
Revision 1.5 2015/12/31 11:11:38CET Ganesh Sumangala (uidu8725) (uidu8725) 
reveiw updates
Revision 1.4 2015/12/29 11:07:58CET Ganesh Sumangala (uidu8725) (uidu8725) 
ecmath create ansi version
reveiw updates
Revision 1.2 2015/12/14 07:56:35CET Ganesh Sumangala (uidu8725) (uidu8725) 
RO : 3550598:MATH: Create ANSI version
Initial archive
Revision 1.14 2015/11/18 04:31:50CET Angadi Hampa (uidu8151) (uidu8151) 
RO: 2875029; FS_0G01_TC2XX_MATH_3.0.0; Merge EMS2 and EMS3 math ; After Review
Revision 1.13 2015/11/06 11:44:42CET Angadi Hampa (uidu8151) (uidu8151) 
RO: 2875029; FS_0G01_TC2XX_MATH_3.0.0; Merge EMS2 and EMS3 math ; Lint save & restore
Revision 1.12 2015/11/05 12:16:16CET Angadi Hampa (uidu8151) (uidu8151) 
RO: 2875029 ; Merge EMS2 and EMS3 math ; inital checkin
Revision 1.11 2015/11/03 09:54:31CET Angadi Hampa (uidu8151) (uidu8151) 
RO: 2875029 ; Merge EMS2 and EMS3 math ; inital checkin
Revision 1.10 2015/07/20 13:16:21CEST Ganesh Sumangala (uidu8725) (uidu8725) 
RO : 2875029 : FS_0G01_TC2XX_MATH_2.1.0
Update missing functions from EMS2 to EMS3
Revision 1.9 2014/07/24 12:15:18CEST uidu8151 
RO: 1081294 : FS_0G01_TC2XX_MATH_200 : design doc and lint solve
Revision 1.8 2014/02/03 13:43:30CET Angadi Hampa (uidu8151) (uidu8151) 
RO:1024108:FS_0G01_TC2XX_AR_MATH_200: Bug Correction & Lint removal
Revision 1.7 2014/01/30 10:47:33CET Angadi Hampa (uidu8151) (uidu8151) 
Bug Correction & Lint removal
Revision 1.6 2013/08/23 13:04:13CEST Angadi Hampa (uidu8151) (uidu8151) 
for release RO 429653 FS_0G01_TC2XX_MATH_100
Revision 1.5 2013/08/20 09:59:33IST Angadi Hampa (uidu8151) (uidu8151) 
for release RO 429653 FS_0G01_TC2XX_MATH_100
Revision 1.4 2013/08/20 09:29:24IST Angadi Hampa (uidu8151) (uidu8151) 
Member renamed from ecmath.h_code to ecmath_main.h in project /ES/FS/0A/bsw/stdlib/math/pd_tc2xx/i/project.pj.
Revision 1.3 2013/08/09 04:37:07CEST Angadi Hampa (uidu8151) (uidu8151) 
for release RO 429653 FS_0G01_TC2XX_MATH_100
Revision 1.2 2013/08/08 10:37:10IST Angadi Hampa (uidu8151) (uidu8151) 
for release RO 429653 FS_0G01_TC2XX_MATH_100
Revision 1.1 2013/08/05 17:33:54IST Angadi Hampa (uidu8151) (uidu8151) 
Initial revision
Member added to project /ES/FS/0D/bsw/stdlib/tc2xx/math/src_pd/i/project.pj
Revision 1.1 2013/04/04 10:46:52CEST Grabow Marcus (uid08755) (uid08755) 
Initial revision
Member added to project /ES/FS/1T/03/UML_Development/DevelopmentSpace/Appl_Uml_ToolBox/Exporters/Uml_Exporter_C/Data/project.pj
Revision 1.1 2013/03/20 08:07:52CET Grabow Marcus (uid08755) (uid08755) 
Initial revision
Member added to project /ES/FS/1T/03/UML_Development/DevelopmentSpace/Appl_Uml_ToolBox/Exporters/Uml_Exporter_C/Core/Data/project.pj
Revision 1.3 2012/01/17 10:50:32CET Grabow Marcus (uid08755) (uid08755) 
-
Revision 1.2 2011/03/10 12:17:55CET Grabow Marcus (uid08755) (uid08755) 
-

****************************************************************************/
/* ## Module Header End [1d09789f-0cdd-4387-8fe8-a6aeaddd7201] */

/*~E*/
#ifndef ECMATH_MAIN_H
#define ECMATH_MAIN_H
/*~T*/
#include "ecmath.h"
/*~T*/
/*lint -restore : (of 715,704,530 before) */
#include "iopt_memmap.h"
#endif
