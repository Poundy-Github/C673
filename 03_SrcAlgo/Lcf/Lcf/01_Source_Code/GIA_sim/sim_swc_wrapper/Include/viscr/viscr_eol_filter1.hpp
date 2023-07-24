/*! \file **********************************************************************

  COMPANY:        Continental AG

  PROJECT:        MFC300

  CPU:            

  COMPONENT:      SAC - Stereo Auto Calibration

  MODULNAME:      viscr_eol_filter1.hpp  

  DESCRIPTION:    viscr_eol_filter1

  AUTHOR:         L. GARCIA
  Last Author     $Author: Wang, David (Wangd3) $

  CREATION DATE:  19.01.2012

  VERSION:        $Revision: 1.1 $
  CHANGES:        $Log: viscr_eol_filter1.hpp  $
  CHANGES:        Revision 1.1 2021/12/13 17:28:27CET Wang, David (Wangd3) 
  CHANGES:        Initial revision
  CHANGES:        Member added to project /ADAS/Projects/MFC5xx/MFC5J3/06_Algorithm/DPU/04_Engineering/01_Source_Code/GIA_sim/sim_swc_wrapper/Include/viscr/project.pj
  CHANGES:        Revision 1.0 2017/03/03 10:40:10CET Sorge, Sven (uidg3181) 
  CHANGES:        Initial revision
  CHANGES:        Member added to project /ADAS/SW/Integration/06_Simulation_Components/GIA_GenericInterfaceAdapter/04_Engineering/03_Workspace/Component_Workspace/GIA_sim/sim_swc_wrapper/Include/viscr/project.pj
  CHANGES:        Revision 1.9 2012/06/25 09:38:41CEST uidk7517 
  CHANGES:        Added code review comments
  CHANGES:        - Added comments -  uidk7517 [Jun 25, 2012 9:38:42 AM CEST]
  CHANGES:        Change Package : 127722:1 http://mks-psad:7002/im/viewissue?selection=127722
  CHANGES:        Revision 1.8 2012/05/21 20:04:00CEST Garcia, Lucien (uid26778) 
  CHANGES:        Add error code for eol calibration function
  CHANGES:        --- Added comments ---  uid26778 [May 21, 2012 8:04:01 PM CEST]
  CHANGES:        Change Package : 94275:1 http://mks-psad:7002/im/viewissue?selection=94275
  CHANGES:        Revision 1.7 2012/04/26 10:49:25CEST Garcia, Lucien (uid26778) 
  CHANGES:        Stereo end of line update
  CHANGES:        --- Added comments ---  uid26778 [Apr 26, 2012 10:49:25 AM CEST]
  CHANGES:        Change Package : 94275:1 http://mks-psad:7002/im/viewissue?selection=94275
  CHANGES:        Revision 1.6 2012/04/19 15:19:09CEST Garcia, Lucien (uid26778) 
  CHANGES:        Lint warning corrections
  CHANGES:        --- Added comments ---  uid26778 [Apr 19, 2012 3:19:09 PM CEST]
  CHANGES:        Change Package : 80273:1 http://mks-psad:7002/im/viewissue?selection=80273
  CHANGES:        Revision 1.5 2012/04/19 14:31:36CEST Garcia, Lucien (uid26778) 
  CHANGES:        Remove static variables on SAC kernel
  CHANGES:        --- Added comments ---  uid26778 [Apr 19, 2012 2:31:36 PM CEST]
  CHANGES:        Change Package : 106188:1 http://mks-psad:7002/im/viewissue?selection=106188
  CHANGES:        Revision 1.4 2012/04/06 16:49:35CEST Garcia, Lucien (uid26778) 
  CHANGES:        Tuning on target distance parameter
  CHANGES:        --- Added comments ---  uid26778 [Apr 6, 2012 4:49:35 PM CEST]
  CHANGES:        Change Package : 106060:1 http://mks-psad:7002/im/viewissue?selection=106060
  CHANGES:        Revision 1.3 2012/04/06 16:34:48CEST Garcia, Lucien (uid26778) 
  CHANGES:        EOL calibration could manage target at 4m (from front vehicle axe)
  CHANGES:        --- Added comments ---  uid26778 [Apr 6, 2012 4:34:48 PM CEST]
  CHANGES:        Change Package : 106060:1 http://mks-psad:7002/im/viewissue?selection=106060
  CHANGES:        Revision 1.2 2012/03/01 15:00:40CET Exner, Christian (uidt8578) 
  CHANGES:        - added debugging adaptation code
  CHANGES:        --- Added comments ---  uidt8578 [Mar 1, 2012 3:00:40 PM CET]
  CHANGES:        Change Package : 90232:1 http://mks-psad:7002/im/viewissue?selection=90232
  CHANGES:        Revision 1.1 2012/01/19 14:20:52CET Garcia, Lucien (uid26778) 
  CHANGES:        Initial revision
  CHANGES:        Member added to project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/SAC_StereoAutoCalibration/04_Engineering/01_Source_Code/Kernel/project.pj



**************************************************************************** */

#ifndef _viscr_eol_filter1_hpp_
#define _viscr_eol_filter1_hpp_

#include <viscr_image.hpp>
#include <viscr_matrix.hpp>
#include <viscr_types.hpp>
#include <viscr_eol_mono.hpp>

//static const viscr_float VISCR_EOL_FILTER1_T_2_1_Z= 3.25F; /* m */
static const viscr_uint8 VISCR_EOL_FILTER1_MIN_SCORE= 40U;

struct C_EOL_FILTER1_Errors {
  static const viscr_uint EOL_FILTER1_NO_ERROR=0;
  // ~CodeReview ~ID:4778e1fb25aa599e070af40aae63c704 ~Reviewer:CW01\uidk7517 ~Date:23.06.2012 ~Priority:3 ~Comment:Remove dead code or document why it is disabled
  //static const viscr_uint EOL_FILTER1_ERROR=1;        
  };

struct viscr_eol_filter1
{
  // ~CodeReview ~ID:1f1dcd9b5e0bc837c05a64fa7c26e1a1 ~Reviewer:CW01\uidk7517 ~Date:23.06.2012 ~Priority:3 ~Comment:Use meaningful defines instead of magic numbers
  viscr_uint8  filter[image_width*image_height/4];
  viscr_uint8  m_aub_TempImage[(image_width*image_height)/4];

  viscr_int filter_width;
  viscr_int filter_height;
  viscr_int filter_start_width;
  viscr_int filter_start_height;
  viscr_int filter_sampling_width;    // should be 2
  viscr_int filter_sampling_height;   // should be 2
};


struct viscr_eol_filter1_input
{
  viscr_image image;
  viscr_int filter_width;
  viscr_int filter_height;
  viscr_int filter_start_width; 
  viscr_int filter_start_height;
  viscr_float TargetDist;
  viscr_float PatOutCircleDiameter;
  viscr_float PatInnerCircleDiameter;
  viscr_float f;
};


struct viscr_eol_filter1_output
{
  S_SL_POINT as_PointList[2];
  viscr_int32 sl_PointListSize;
  viscr_uint Errors;
};

void viscr_eol_filter1_init( );
void viscr_eol_filter1_run( const viscr_eol_filter1_input * const p_eol_filter1_input, viscr_eol_filter1_output *  const p_eol_filter1_output);
void viscr_eol_filer1_exit( );

#endif
