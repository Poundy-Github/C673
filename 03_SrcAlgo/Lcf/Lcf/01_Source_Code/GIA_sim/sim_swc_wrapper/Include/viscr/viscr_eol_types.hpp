/*! \file **********************************************************************

  COMPANY:        Continental AG

  PROJECT:        MFC300

  CPU:            

  COMPONENT:      SAC - Stereo Auto Calibration

  MODULNAME:      viscr_eol_types.hpp  

  DESCRIPTION:    viscr_eol_types

  AUTHOR:         L. GARCIA
  Last Author     $Author: Wang, David (Wangd3) $

  CREATION DATE:  19.01.2012

  VERSION:        $Revision: 1.1 $
  CHANGES:        $Log: viscr_eol_types.hpp  $
  CHANGES:        Revision 1.1 2021/12/13 17:28:29CET Wang, David (Wangd3) 
  CHANGES:        Initial revision
  CHANGES:        Member added to project /ADAS/Projects/MFC5xx/MFC5J3/06_Algorithm/DPU/04_Engineering/01_Source_Code/GIA_sim/sim_swc_wrapper/Include/viscr/project.pj
  CHANGES:        Revision 1.0 2017/03/03 10:40:15CET Sorge, Sven (uidg3181) 
  CHANGES:        Initial revision
  CHANGES:        Member added to project /ADAS/SW/Integration/06_Simulation_Components/GIA_GenericInterfaceAdapter/04_Engineering/03_Workspace/Component_Workspace/GIA_sim/sim_swc_wrapper/Include/viscr/project.pj
  CHANGES:        Revision 1.4 2012/06/19 14:53:30CEST Godreau, Bertrand (uid28828) 
  CHANGES:        add findings from code review
  CHANGES:        - Added comments -  uid28828 [Jun 19, 2012 2:53:30 PM CEST]
  CHANGES:        Change Package : 130169:2 http://mks-psad:7002/im/viewissue?selection=130169
  CHANGES:        Revision 1.3 2012/03/26 11:25:44CEST Garcia, Lucien (uid26778) 
  CHANGES:        Add define for simulation
  CHANGES:        --- Added comments ---  uid26778 [Mar 26, 2012 11:25:44 AM CEST]
  CHANGES:        Change Package : 94275:1 http://mks-psad:7002/im/viewissue?selection=94275
  CHANGES:        Revision 1.2 2012/03/15 16:45:15CET Garcia, Lucien (uid26778) 
  CHANGES:        Integrate EOL function on SAC branch
  CHANGES:        --- Added comments ---  uid26778 [Mar 15, 2012 4:45:15 PM CET]
  CHANGES:        Change Package : 94275:1 http://mks-psad:7002/im/viewissue?selection=94275
  CHANGES:        Revision 1.1 2012/01/19 14:20:55CET Garcia, Lucien (uid26778) 
  CHANGES:        Initial revision
  CHANGES:        Member added to project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/SAC_StereoAutoCalibration/04_Engineering/01_Source_Code/Kernel/project.pj


**************************************************************************** */

#ifndef _viscr_eol_types_hpp_
#define _viscr_eol_types_hpp_
#include <viscr_image.hpp>
#include <viscr_matrix.hpp>
#include <viscr_types.hpp>


#define VISCR_EOL_DEBUG 0
#define VISCR_EOL_DEBUG_PC_SIM 1

#if (VISCR_EOL_DEBUG==1)
#include <stdio.h>
#endif

/* ~CodeReview ~ID:55d5900eca5ddca09fb942369a210f44 ~Reviewer:CW01\uid28828 ~Date:19/06/2012 ~Priority:3 ~Comment:magic numbers */
const viscr_int image_width = 1024;
const viscr_int image_height = 460;

struct S_INTERNAL_IMAGE_POINT
{
  /* ~CodeReview ~ID:168f433aaa64c7069b859c70119a3665 ~Reviewer:CW01\uid28828 ~Date:19/06/2012 ~Priority:3 ~Comment:Use of generic int. No guarantee it is a i32_t type */
  viscr_int sl_X;
	viscr_int sl_Y;
	viscr_uint8 ub_Max;
	viscr_uint ul_No;
};

struct S_SL_POINT
{
  /* ~CodeReview ~ID:955e029b8fe8b98759385254b901aa7b ~Reviewer:CW01\uid28828 ~Date:19/06/2012 ~Priority:3 ~Comment:Use of generic int. No guarantee it is a i32_t type */
	viscr_int sl_X;
	viscr_int sl_Y;
};

struct S_F_POINT
{
  /* ~CodeReview ~ID:d19f4c4715c1e566522b39238c70d775 ~Reviewer:CW01\uid28828 ~Date:19/06/2012 ~Priority:3 ~Comment:Use of generic float. No guarantee it is a f32_t type */
  viscr_float sl_X;
	viscr_float sl_Y;
};

//maximum allowed number of points found in the image
static const viscr_int sl_MAX_NO_OF_POINTS = 50;

//stack used for finding the objects
static S_SL_POINT m_as_Stack[sl_MAX_NO_OF_POINTS];


#endif
