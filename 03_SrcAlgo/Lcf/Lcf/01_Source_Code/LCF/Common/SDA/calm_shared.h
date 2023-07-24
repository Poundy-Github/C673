/*~A*/
/*~+:VM Header*/
/* Used UML Profile version  */
/* ## Module Header Start [3d2b4456-f7c8-40fa-a005-6d3751f876bb] */
/****************************************************************************

COPYRIGHT (C) $Date: 2019/07/03 13:45:17CEST $
$CompanyInfo: CONFIDENTIAL AND PROPRIETARY PROPERTY OF CONTINENTAL AG , A.D.C. GmbH  -  ALL RIGHTS RESERVED $
ALL RIGHTS RESERVED.                                                 
                                                                           
The reproduction, transmission or use of this document or its contents is  
not permitted without express written authority.                           
Offenders will be liable for damages. All rights, including rights created 
by patent grant or registration of a utility model or design, are reserved.
---------------------------------------------------------------------------

$Log: calm_shared.h  $
Revision 1.3 2019/07/03 13:45:17CEST Nastasa, Elena (uidt4846) 
Update SDA Library files
Revision 1.1 2018/07/24 16:49:47CEST Ammermueller Martin (uidv5342) (uidv5342) 
Initial revision
Member added to project /ES/1T/0C/SDA/SDA_Source/SDA_Toolboxes/ACG/Libraries/calm/Src/3_1_0/project.pj
Revision 1.1 2015/11/30 11:53:42CET Ganesh Sumangala (uidu8725) (uidu8725) 
Initial revision
Member added to project /ES/FS/0A/bsw/stdlib-ansi/calm/if_pi/i/project.pj
Revision 1.1 2013/08/09 11:25:48CEST Angadi Hampa (uidu8151) (uidu8151) 
Initial revision
Member added to project /ES/FS/0D/bsw/stdlib/tc2xx/calm/calm/if/i/project.pj
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
/* ## Module Header End [3d2b4456-f7c8-40fa-a005-6d3751f876bb] */

/*~E*/
/*~A*/
/*~+:SW module (UML class) description*/
/* This component provides the definition for the structure DPS_RESULT. */
/*~E*/
#ifndef CALM_SHARED_H
#define CALM_SHARED_H
/*~A*/
/*~+:Structure TypeDefs*/
/** A structure including line_count, line_index and line_factor as its elements
These elements will be set by the search operations and will be used for interpolaiton and table value search operations
To access these elements access functions are available */
typedef struct DPS_RESULT_tag DPS_RESULT;
/*~E*/
/*~A*/
/*~+:Structure Definitions*/
struct DPS_RESULT_tag
{
uint8 line_count;                                /** This element stores the number of data points in a DPA i.e. the first element of DPA */
uint8 line_index;                                /** This element stores the interplation index for a DPA */
uint16 line_factor;                              /** This element stores the interplation factor for a DPA */
};

/*~E*/
#include "iopt_memmap.h"
#endif
