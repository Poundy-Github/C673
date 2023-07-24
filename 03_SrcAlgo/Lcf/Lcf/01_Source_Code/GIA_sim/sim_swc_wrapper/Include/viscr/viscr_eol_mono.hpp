/*! \file **********************************************************************

  COMPANY:        Continental AG

  PROJECT:        MFC300

  CPU:            

  COMPONENT:      SAC - Stereo Auto Calibration

  MODULNAME:      viscr_eol_mono.hpp  

  DESCRIPTION:    viscr_eol_mono

  AUTHOR:         L. GARCIA
  Last Author     $Author: Wang, David (Wangd3) $

  CREATION DATE:  19.01.2012

  VERSION:        $Revision: 1.1 $
  CHANGES:        $Log: viscr_eol_mono.hpp  $
  CHANGES:        Revision 1.1 2021/12/13 17:28:28CET Wang, David (Wangd3) 
  CHANGES:        Initial revision
  CHANGES:        Member added to project /ADAS/Projects/MFC5xx/MFC5J3/06_Algorithm/DPU/04_Engineering/01_Source_Code/GIA_sim/sim_swc_wrapper/Include/viscr/project.pj
  CHANGES:        Revision 1.0 2017/03/03 10:40:13CET Sorge, Sven (uidg3181) 
  CHANGES:        Initial revision
  CHANGES:        Member added to project /ADAS/SW/Integration/06_Simulation_Components/GIA_GenericInterfaceAdapter/04_Engineering/03_Workspace/Component_Workspace/GIA_sim/sim_swc_wrapper/Include/viscr/project.pj
  CHANGES:        Revision 1.4 2012/05/21 20:04:05CEST Garcia, Lucien (uid26778) 
  CHANGES:        Add error code for eol calibration function
  CHANGES:        - Added comments -  uid26778 [May 21, 2012 8:04:06 PM CEST]
  CHANGES:        Change Package : 94275:1 http://mks-psad:7002/im/viewissue?selection=94275
  CHANGES:        Revision 1.3 2012/04/26 10:49:26CEST Garcia, Lucien (uid26778) 
  CHANGES:        Stereo end of line update
  CHANGES:        --- Added comments ---  uid26778 [Apr 26, 2012 10:49:26 AM CEST]
  CHANGES:        Change Package : 94275:1 http://mks-psad:7002/im/viewissue?selection=94275
  CHANGES:        Revision 1.2 2012/03/06 15:29:32CET Konarski-EXT, Witek (uidt8403) 
  CHANGES:        Removed PC-Lint/Misra errors
  CHANGES:        --- Added comments ---  uidt8403 [Mar 6, 2012 3:29:32 PM CET]
  CHANGES:        Change Package : 101150:1 http://mks-psad:7002/im/viewissue?selection=101150
  CHANGES:        Revision 1.1 2012/01/19 14:20:53CET Garcia, Lucien (uid26778) 
  CHANGES:        Initial revision
  CHANGES:        Member added to project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/SAC_StereoAutoCalibration/04_Engineering/01_Source_Code/Kernel/project.pj


**************************************************************************** */

#ifndef _viscr_eol_mono_hpp_
#define _viscr_eol_mono_hpp_
#include <viscr_image.hpp>
#include <viscr_matrix.hpp>
#include <viscr_eol_types.hpp>

////////////////////////////////////////
// Coordinate systems :
// 1 = target
// 2 = world (ground front axes)
// C = camera
////////////////////////////////////////

static const viscr_int filer1_border=20; /* px */

struct C_EOL_MONO_Errors {
  static const viscr_uint EOL_MONO_NO_ERROR=0;
 // static const viscr_uint EOL_MONO_FILTER1=1;      
 // static const viscr_uint EOL_MONO_FILTER2=2;  
 // static const viscr_uint EOL_MONO_CALIB=4; 
  };

struct viscr_eol_mono_input
{
  viscr_float f;
  viscr_float u0;
  viscr_float v0;
  viscr_image image;
  viscr_vec3 R_2_C_mean;
  viscr_vec3 R_2_C_std;
  viscr_vec3 T_2_C;
  viscr_vec3 T_2_1;
  viscr_float PatDistCircle2Circle;
  viscr_float PatDistCircle2Center;
  viscr_float PatOutCircleDiameter;
  viscr_float PatInnerCircleDiameter;
  viscr_vec3 T_2_3_std;
  viscr_vec3 T_2_1_std;
};


struct viscr_eol_mono_output
{
  viscr_vec3 RA_2_C;
  viscr_uint Errors;
};


void viscr_eol_mono_init( );
void viscr_eol_mono_run( const viscr_eol_mono_input * const p_eol_mono_input, viscr_eol_mono_output * const p_eol_mono_output);
void viscr_eol_mono_exit( );

#endif
