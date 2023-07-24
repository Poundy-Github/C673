/*! \file **********************************************************************

  COMPANY:        Continental AG

  PROJECT:        MFC300

  CPU:            

  COMPONENT:      SAC - Stereo Auto Calibration

  MODULNAME:      viscr_eol_calib.hpp  

  DESCRIPTION:    viscr_eol_calib

  AUTHOR:         L. GARCIA
  Last Author     $Author: Wang, David (Wangd3) $

  CREATION DATE:  19.01.2012

  VERSION:        $Revision: 1.1 $
  CHANGES:        $Log: viscr_eol_calib.hpp  $
  CHANGES:        Revision 1.1 2021/12/13 17:28:26CET Wang, David (Wangd3) 
  CHANGES:        Initial revision
  CHANGES:        Member added to project /ADAS/Projects/MFC5xx/MFC5J3/06_Algorithm/DPU/04_Engineering/01_Source_Code/GIA_sim/sim_swc_wrapper/Include/viscr/project.pj
  CHANGES:        Revision 1.0 2017/03/03 10:40:09CET Sorge, Sven (uidg3181) 
  CHANGES:        Initial revision
  CHANGES:        Member added to project /ADAS/SW/Integration/06_Simulation_Components/GIA_GenericInterfaceAdapter/04_Engineering/03_Workspace/Component_Workspace/GIA_sim/sim_swc_wrapper/Include/viscr/project.pj
  CHANGES:        Revision 1.6 2012/06/26 14:09:19CEST Godreau, Bertrand (uid28828) 
  CHANGES:        Add code review findings
  CHANGES:        - Added comments -  uid28828 [Jun 26, 2012 2:09:19 PM CEST]
  CHANGES:        Change Package : 130169:2 http://mks-psad:7002/im/viewissue?selection=130169
  CHANGES:        Revision 1.5 2012/05/21 20:03:58CEST Garcia, Lucien (uid26778) 
  CHANGES:        Add error code for eol calibration function
  CHANGES:        --- Added comments ---  uid26778 [May 21, 2012 8:03:59 PM CEST]
  CHANGES:        Change Package : 94275:1 http://mks-psad:7002/im/viewissue?selection=94275
  CHANGES:        Revision 1.4 2012/04/26 10:49:24CEST Garcia, Lucien (uid26778) 
  CHANGES:        Stereo end of line update
  CHANGES:        --- Added comments ---  uid26778 [Apr 26, 2012 10:49:24 AM CEST]
  CHANGES:        Change Package : 94275:1 http://mks-psad:7002/im/viewissue?selection=94275
  CHANGES:        Revision 1.3 2012/03/13 18:21:27CET Garcia, Lucien (uid26778) 
  CHANGES:        Add robustness to eol calibration function and parameter tuning
  CHANGES:        --- Added comments ---  uid26778 [Mar 13, 2012 6:21:27 PM CET]
  CHANGES:        Change Package : 94275:1 http://mks-psad:7002/im/viewissue?selection=94275
  CHANGES:        Revision 1.2 2012/02/22 17:28:50CET Garcia, Lucien (uid26778) 
  CHANGES:        Remove unused code
  CHANGES:        --- Added comments ---  uid26778 [Feb 22, 2012 5:28:50 PM CET]
  CHANGES:        Change Package : 80273:2 http://mks-psad:7002/im/viewissue?selection=80273
  CHANGES:        Revision 1.1 2012/01/19 14:20:51CET Garcia, Lucien (uid26778) 
  CHANGES:        Initial revision
  CHANGES:        Member added to project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/SAC_StereoAutoCalibration/04_Engineering/01_Source_Code/Kernel/project.pj


**************************************************************************** */

#ifndef _viscr_eol_calib_hpp_
#define _viscr_eol_calib_hpp_
#include <viscr_image.hpp>
#include <viscr_matrix.hpp>
#include <viscr_eol_types.hpp>

static const viscr_float VISCR_EOL_CALIB_MAX_ERROR=2.0F;

struct C_EOL_CALIB_Errors {
  static const viscr_uint EOL_CALIB_NO_ERROR=0;
  //static const viscr_uint EOL_CALIB_WRONG_TARGET=1;   // The reprojection error is too big
  //static const viscr_uint EOL_CALIB_NO_SOLUTION=2; 
  };

struct viscr_eol_calib_input
{
  viscr_float f;
  viscr_float u0;
  viscr_float v0;

  viscr_vec3 RA_2_C;
  viscr_vec3 T_2_C;

  viscr_mat22 PI_C;
  viscr_vec3 P_2[2];

  viscr_vec3 T_2_3_std;
  viscr_vec3 T_2_1_std;
  
};

struct viscr_eol_calib_output
{
  viscr_vec3 RA_2_C;
  viscr_uint Errors;
};

/* ~CodeReview ~ID:0adc0f229011dd8df4c39393e395ee6e ~Reviewer:CW01\uid28828 ~Date:26/06/2012 ~Priority:3 ~Comment:unused init and exit functions */
void viscr_eol_calib_init( );
void viscr_eol_calib_run( viscr_eol_calib_input *  const p_eol_calib_input, viscr_eol_calib_output *  const p_eol_calib_output);
void viscr_eol_calib_exit( );

#endif
