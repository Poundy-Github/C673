/**
@file
$RCSfile: sde_memset.h $
$Revision: 1.1 $
$Date: 2018/01/24 16:30:07CET $

Confidential and proprietary. This document and its contents are the
exclusive property of Continental Teves AG & Co. OHG (Teves) and Conti Temic
microelectronic GmbH (Temic) and their associated companies. They are not to
be copied, distributed, or otherwise disclosed or used without the prior
written consent of Teves and Temic. All rights reserved.

@author $Setting file_owner: ???? $

@brief       Dummy memset function needed for SDE which is auto generated.
@details     
The autogenerated SDE initialise the local ram by calling memset.
The routine memset is not supported, so the call is redirected to sde_memset.

@ingroup     SDE
*/

#ifndef Sde_memset_h_included
#define Sde_memset_h_included

/*==================================================================
                            INCLUDES
==================================================================*/
#include "hal_base_type_if.h"


/*==================================================================
                            TYPES
===================================================================*/


/*==================================================================
                            VARIABLES
==================================================================*/


/*==================================================================
                            DEFINES
===================================================================*/


/*==================================================================
                            MACROS
==================================================================*/


/*==================================================================
                           FUNCTIONS
==================================================================*/
void* sde_memset( void * ptr, unsigned_char_t byte_value, signed_int16_t num );


#endif   /* Sde_memset_h_included */
/*==================================================================
$Log: sde_memset.h  $
Revision 1.1 2018/01/24 16:30:07CET Asong, Wedndah Asaha (uidj2187) 
Initial revision
Member added to project /ADAS/SW/Components/LCF_LateralControlFunctions/04_Engineering/01_Source_Code/LCF/LATDMC/latdmc_veh_ang/project.pj
Revision 1.1 2017/04/20 10:33:35CEST Feick, Stefan (uidw0691) 
Initial revision
Member added to project /C_ST/CMP/C_A_LATDMC/30_Software_Engineering/30_SW_Environment/20_SourceCode/project.pj
Revision 1.1 2017/01/11 06:03:37CET Babar, Ketan (uidj9168) 
Initial revision
Member added to project /C_ST/A_HI_LCF_1802/20_System_Design/40_Implementation/10_Sources/10_Models/20_System_Function/LateralControlFunctions/C_A_LATDMC/30_Software_Engineering/30_SW_Environment/20_SoCo/project.pj
Revision 1.1 2016/08/03 20:43:52CEST Prajescu, Claudia (uidl9533) 
LaDMC algo code update
Revision 1.1 2015/07/23 12:33:07CEST Bretzigheimer, Kai (tfts06) 
Initial revision
Member added to project d:/mks/archives/src/LVC/2009CW35_LVC.pj
Revision 1.4 2015/05/13 15:25:29CEST Roempert, Martin (roempertm) 
- provide possibility to change include file name for base types in MATLAB environment
Revision 1.3 2014/08/11 19:37:45CEST Orians, Andreas (Orians) 
Restructure SDE Memset for TB, VC and Matlab sfun
Revision 1.2 2014/07/01 16:22:26CEST Orians, Andreas (Orians) 
Use c-base types instead of unsigned_char_t and signed_int16_t.

The former ifndef typedef part does not work (linker problems because of multiple typedefs: hal_base_type_if.he)
Include of hal_base_type_if.he is not allowed to ensure compartibility between VisionControls and old Technology Branches.
Revision 1.1 2014/06/14 12:48:52CEST Zhang, Chen02 (TFETCB) 
Initial revision
Member added to project d:/mks/archives/other/autocode/SDE/project.pj
Revision 1.3 2013/06/21 16:01:01CEST Zhang, Chen02 (TFETCB) 
QAC fix
Revision 1.2 2013/06/21 15:48:34CEST Zhang, Chen02 (TFETCB) 
QAC fix
Revision 1.1 2012/10/19 10:55:44CEST Zhang, Chen02 (TFETCB) 
Initial revision
Member added to project d:/mks/archives/other/autocode/VSE/VSE.pj
*/
