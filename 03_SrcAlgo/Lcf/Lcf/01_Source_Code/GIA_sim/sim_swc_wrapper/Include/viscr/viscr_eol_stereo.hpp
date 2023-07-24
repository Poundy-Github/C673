/*! \file **********************************************************************

  COMPANY:        Continental AG

  PROJECT:        MFC300

  CPU:            

  COMPONENT:      SAC - Stereo Auto Calibration

  MODULNAME:      viscr_eol_stereo.hpp  

  DESCRIPTION:    viscr_eol_stereo

  AUTHOR:         L. GARCIA
  Last Author     $Author: Wang, David (Wangd3) $

  CREATION DATE:  19.01.2012

  VERSION:        $Revision: 1.1 $
  CHANGES:        $Log: viscr_eol_stereo.hpp  $
  CHANGES:        Revision 1.1 2021/12/13 17:28:28CET Wang, David (Wangd3) 
  CHANGES:        Initial revision
  CHANGES:        Member added to project /ADAS/Projects/MFC5xx/MFC5J3/06_Algorithm/DPU/04_Engineering/01_Source_Code/GIA_sim/sim_swc_wrapper/Include/viscr/project.pj
  CHANGES:        Revision 1.0 2017/03/03 10:40:14CET Sorge, Sven (uidg3181) 
  CHANGES:        Initial revision
  CHANGES:        Member added to project /ADAS/SW/Integration/06_Simulation_Components/GIA_GenericInterfaceAdapter/04_Engineering/03_Workspace/Component_Workspace/GIA_sim/sim_swc_wrapper/Include/viscr/project.pj
  CHANGES:        Revision 1.6 2012/06/25 09:39:43CEST uidk7517 
  CHANGES:        Added code review comments
  CHANGES:        - Added comments -  uidk7517 [Jun 25, 2012 9:39:44 AM CEST]
  CHANGES:        Change Package : 127722:1 http://mks-psad:7002/im/viewissue?selection=127722
  CHANGES:        Revision 1.5 2012/05/21 20:03:48CEST Garcia, Lucien (uid26778) 
  CHANGES:        Add error code for eol calibration function
  CHANGES:        --- Added comments ---  uid26778 [May 21, 2012 8:03:50 PM CEST]
  CHANGES:        Change Package : 94275:1 http://mks-psad:7002/im/viewissue?selection=94275
  CHANGES:        Revision 1.4 2012/03/13 11:53:04CET Garcia, Lucien (uid26778) 
  CHANGES:        Add Robustess Test for EOL calibration
  CHANGES:        --- Added comments ---  uid26778 [Mar 13, 2012 11:53:04 AM CET]
  CHANGES:        Change Package : 94275:1 http://mks-psad:7002/im/viewissue?selection=94275
  CHANGES:        Revision 1.3 2012/03/07 10:30:53CET Konarski-EXT, Witek (uidt8403) 
  CHANGES:        Removed PC-Lint/Misra errors.
  CHANGES:        --- Added comments ---  uidt8403 [Mar 7, 2012 10:30:54 AM CET]
  CHANGES:        Change Package : 101150:2 http://mks-psad:7002/im/viewissue?selection=101150
  CHANGES:        Revision 1.2 2012/03/06 11:54:11CET Garcia, Lucien (uid26778) 
  CHANGES:        Update EOL mode
  CHANGES:        --- Added comments ---  uid26778 [Mar 6, 2012 11:54:11 AM CET]
  CHANGES:        Change Package : 94275:1 http://mks-psad:7002/im/viewissue?selection=94275
  CHANGES:        Revision 1.1 2012/01/19 14:20:54CET Garcia, Lucien (uid26778) 
  CHANGES:        Initial revision
  CHANGES:        Member added to project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/SAC_StereoAutoCalibration/04_Engineering/01_Source_Code/Kernel/project.pj



**************************************************************************** */

#ifndef _viscr_eol_stereo_hpp_
#define _viscr_eol_stereo_hpp_
#include <viscr_image.hpp>
#include <viscr_matrix.hpp>
#include <viscr_eol_types.hpp>

////////////////////////////////////////
// Coordinate systems :
// 1 = target
// 2 = world (ground front axes)
// 3 = right camera
// 4 = left camera
// 5 = right rectified camera
// 6 = left recified camera
////////////////////////////////////////


struct C_EOL_STEREO_Errors {
  static const viscr_uint EOL_STEREO_NO_ERROR=0;
  // ~CodeReview ~ID:b204127814180f3e7bfc9ed330b0267b ~Reviewer:CW01\uidk7517 ~Date:23.06.2012 ~Priority:3 ~Comment:Remove dead code or document why it is disabled
  //static const viscr_uint EOL_STEREO_ERROR=1;
  };


struct viscr_eol_stereo_input
{
  viscr_float f;
  viscr_float u0;
  viscr_float v0;
  viscr_image image_right;
  viscr_image image_left;

  viscr_vec3 T_2_1_mean;
  viscr_vec3 T_2_1_std;
  viscr_vec3 RA_2_1_mean;
  viscr_vec3 RA_2_1_std;

  viscr_vec3 T_2_3_mean;
  viscr_vec3 T_2_3_std;
  viscr_vec3 RA_2_3_mean;
  viscr_vec3 RA_2_3_std;

  viscr_vec3 T_5_6_mean;
  viscr_vec3 T_5_6_std;
  viscr_vec3 RA_4_3_mean;
  viscr_vec3 RA_4_3_std;

  viscr_vec3 RA_5_3;
  viscr_vec3 RA_6_4;

  viscr_float PatDistCircle2Circle;
  viscr_float PatDistCircle2Center;
  viscr_float PatOutCircleDiameter;
  viscr_float PatInnerCircleDiameter;
  
};

struct viscr_eol_stereo_output
{
  viscr_vec3 RA_4_3;
  viscr_uint Errors_right;
  viscr_uint Errors_left;
  viscr_uint Errors;
};

extern void viscr_eol_stereo_init( );
extern void viscr_eol_stereo_run( const viscr_eol_stereo_input *  const p_eol_stereo_input, viscr_eol_stereo_output * const p_eol_stereo_output);
extern void viscr_eol_stereo_exit( );


#endif
