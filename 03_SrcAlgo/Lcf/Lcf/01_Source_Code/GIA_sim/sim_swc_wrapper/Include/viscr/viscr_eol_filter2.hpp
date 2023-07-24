/*! \file **********************************************************************

  COMPANY:        Continental AG

  PROJECT:        MFC300

  CPU:            

  COMPONENT:      SAC - Stereo Auto Calibration

  MODULNAME:      viscr_eol_filter2.hpp  

  DESCRIPTION:    viscr_eol_filter2

  AUTHOR:         L. GARCIA
  Last Author     $Author: Wang, David (Wangd3) $

  CREATION DATE:  19.01.2012

  VERSION:        $Revision: 1.1 $
  CHANGES:        $Log: viscr_eol_filter2.hpp  $
  CHANGES:        Revision 1.1 2021/12/13 17:28:28CET Wang, David (Wangd3) 
  CHANGES:        Initial revision
  CHANGES:        Member added to project /ADAS/Projects/MFC5xx/MFC5J3/06_Algorithm/DPU/04_Engineering/01_Source_Code/GIA_sim/sim_swc_wrapper/Include/viscr/project.pj
  CHANGES:        Revision 1.0 2017/03/03 10:40:12CET Sorge, Sven (uidg3181) 
  CHANGES:        Initial revision
  CHANGES:        Member added to project /ADAS/SW/Integration/06_Simulation_Components/GIA_GenericInterfaceAdapter/04_Engineering/03_Workspace/Component_Workspace/GIA_sim/sim_swc_wrapper/Include/viscr/project.pj
  CHANGES:        Revision 1.5 2012/06/25 09:38:45CEST uidk7517 
  CHANGES:        Added code review comments
  CHANGES:        - Added comments -  uidk7517 [Jun 25, 2012 9:38:45 AM CEST]
  CHANGES:        Change Package : 127722:1 http://mks-psad:7002/im/viewissue?selection=127722
  CHANGES:        Revision 1.4 2012/05/21 20:03:55CEST Garcia, Lucien (uid26778) 
  CHANGES:        Add error code for eol calibration function
  CHANGES:        --- Added comments ---  uid26778 [May 21, 2012 8:03:56 PM CEST]
  CHANGES:        Change Package : 94275:1 http://mks-psad:7002/im/viewissue?selection=94275
  CHANGES:        Revision 1.3 2012/04/26 10:49:25CEST Garcia, Lucien (uid26778) 
  CHANGES:        Stereo end of line update
  CHANGES:        --- Added comments ---  uid26778 [Apr 26, 2012 10:49:25 AM CEST]
  CHANGES:        Change Package : 94275:1 http://mks-psad:7002/im/viewissue?selection=94275
  CHANGES:        Revision 1.2 2012/01/24 17:01:38CET Garcia, Lucien (uid26778) 
  CHANGES:        Update stereo EOL configuration
  CHANGES:        --- Added comments ---  uid26778 [Jan 24, 2012 5:01:38 PM CET]
  CHANGES:        Change Package : 94275:1 http://mks-psad:7002/im/viewissue?selection=94275
  CHANGES:        Revision 1.1 2012/01/19 14:20:53CET Garcia, Lucien (uid26778) 
  CHANGES:        Initial revision
  CHANGES:        Member added to project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/SAC_StereoAutoCalibration/04_Engineering/01_Source_Code/Kernel/project.pj


**************************************************************************** */

#ifndef _viscr_eol_filter2_hpp_
#define _viscr_eol_filter2_hpp_
#include <viscr_image.hpp>
#include <viscr_matrix.hpp>
#include <viscr_types.hpp>
#include <viscr_eol_mono.hpp>

static const viscr_int VISCR_EOL_FILTER2_HEIGHT=9;
static const viscr_int VISCR_EOL_FILTER2_WIDTH=9;

struct C_EOL_FILTER2_Errors {
  static const viscr_uint EOL_FILTER2_NO_ERROR=0;
 // ~CodeReview ~ID:561871784e8ba7d2cbf62c49fe4c8370 ~Reviewer:CW01\uidk7517 ~Date:23.06.2012 ~Priority:3 ~Comment:Remove dead code or document why it is disabled
 // static const viscr_uint EOL_FILTER2_MAX_MISSING=1;        
  };


struct viscr_eol_filter2
{
  viscr_uint32  filter[VISCR_EOL_FILTER2_HEIGHT*VISCR_EOL_FILTER2_WIDTH];
  viscr_int filter_width;
  viscr_int filter_height;
  viscr_int filter_start_width;
  viscr_int filter_start_height;
};

struct viscr_eol_filter2_input
{
  viscr_image image;  
  S_SL_POINT as_PointList[2];
  viscr_float TargetDist;
  viscr_float PatInnerCircleDiameter;
  viscr_float f;
};

struct viscr_eol_filter2_output
{
  S_F_POINT as_PointList[2];
  viscr_uint Errors;
};

extern void viscr_eol_filter2_init( );
extern void viscr_eol_filter2_run( const viscr_eol_filter2_input *  const p_eol_filter2_input, viscr_eol_filter2_output *  p_eol_filter2_output);
extern void viscr_eol_filter2_exit( );
#endif
