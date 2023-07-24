/*~A*/
/*~+:VM Header*/
/* Used UML Profile version  */
/* ## Module Header Start [5930e086-6b60-412b-a82c-0a8723e9646a] */
/****************************************************************************

COPYRIGHT (C) $Date: 2019/07/03 13:44:17CEST $
$CompanyInfo: CONFIDENTIAL AND PROPRIETARY PROPERTY OF CONTINENTAL AG , A.D.C. GmbH  -  ALL RIGHTS RESERVED $
ALL RIGHTS RESERVED.                                                 

The reproduction, transmission or use of this document or its contents is  
not permitted without express written authority.                           
Offenders will be liable for damages. All rights, including rights created 
by patent grant or registration of a utility model or design, are reserved.
---------------------------------------------------------------------------

$Log: calm_main.h  $
Revision 1.1 2019/07/03 13:44:17CEST Nastasa, Elena (uidt4846) 
Initial revision
Member added to project /ADAS/SW/Components/LCF_LateralControlFunctions/04_Engineering/01_Source_Code/LCF/Common/SDA/project.pj
Revision 1.1 2018/07/24 16:49:47CEST Ammermueller Martin (uidv5342) (uidv5342) 
Initial revision
Member added to project /ES/1T/0C/SDA/SDA_Source/SDA_Toolboxes/ACG/Libraries/calm/Src/3_1_0/project.pj
Revision 1.2 2017/10/04 07:47:26CEST Angadi Hampa (uidu8151) (uidu8151) 
Calm : LINT MISRA2012 for ANSI
Revision 1.1 2015/12/01 05:06:25CET Ganesh Sumangala (uidu8725) (uidu8725) 
Initial revision
Member added to project /ES/FS/0A/bsw/stdlib-ansi/calm/pd_ansi/i/project.pj
Revision 1.1 2015/11/30 11:54:15CET Ganesh Sumangala (uidu8725) (uidu8725) 
Initial revision
Member added to project /ES/FS/0A/bsw/stdlib-ansi/calm/pd_tc2xx/i/project.pj
Revision 1.8 2015/11/20 03:30:13CET Ganesh Sumangala (uidu8725) (uidu8725) 
RO : 2806846 : Merging - reveiw updates
Revision 1.7 2015/11/19 05:43:23CET Ganesh Sumangala (uidu8725) (uidu8725) 
RO:2806846: EMS2-EMS3 Merging
reveiw updates
Revision 1.4 2015/05/25 13:16:43CEST Angadi Hampa (uidu8151) (uidu8151) 
RO:2806846;FS_0G01_TC2XX_CALM-3.0.0; Lint correction
Revision 1.3 2014/09/19 05:37:09CEST uidu8151 
Ro: 1081869 : FS_0G01_TC2XX_CALM_200: Review comments update
Revision 1.2 2013/08/22 05:10:23CEST Angadi Hampa (uidu8151) (uidu8151) 
for release RO_429651 :FS_0G01_TC2XX_CALM_100
Revision 1.1 2013/08/09 14:57:30IST Angadi Hampa (uidu8151) (uidu8151) 
Initial revision
Member added to project /ES/FS/0D/bsw/stdlib/tc2xx/calm/src_pd/i/project.pj
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
/* ## Module Header End [5930e086-6b60-412b-a82c-0a8723e9646a] */

/*~E*/
/*~A*/
/*~+:SW module (UML class) description*/
/* The CALM component supports a generic interface for fixed point interpolations and table access including data point search in a microcontroller independent way.  */
/*~E*/
#ifndef CALM_MAIN_H
#define CALM_MAIN_H
/*~A*/
/*~+:Includes*/
#include <calm_main_shared.h>
#include <calm_main_private.h>
#include <calm.h>
/*~E*/
/*~A*/
/*~+:TypeDefs*/

/*~E*/
/*~A*/
/*~+:Macro Operations*/

/*~E*/
/*~A*/
/*~+:Private and Public Operations*/

/*~E*/
#include "iopt_memmap.h"
#endif
