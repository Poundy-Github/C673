/*! \file **********************************************************************

  COMPANY:        Continental AG

  PROJECT:        MFC300

  CPU:            

  COMPONENT:      SAC - Stereo Auto Calibration

  MODULNAME:      viscr_disttest.hpp 

  DESCRIPTION:    viscr_disttest

  AUTHOR:         L. GARCIA
  Last Author     $Author: Wang, David (Wangd3) $

  CREATION DATE:  19.01.2012

  VERSION:        $Revision: 1.1 $
  CHANGES:        $Log: viscr_disttest.hpp  $
  CHANGES:        Revision 1.1 2021/12/13 17:28:26CET Wang, David (Wangd3) 
  CHANGES:        Initial revision
  CHANGES:        Member added to project /ADAS/Projects/MFC5xx/MFC5J3/06_Algorithm/DPU/04_Engineering/01_Source_Code/GIA_sim/sim_swc_wrapper/Include/viscr/project.pj
  CHANGES:        Revision 1.0 2017/03/03 10:40:07CET Sorge, Sven (uidg3181) 
  CHANGES:        Initial revision
  CHANGES:        Member added to project /ADAS/SW/Integration/06_Simulation_Components/GIA_GenericInterfaceAdapter/04_Engineering/03_Workspace/Component_Workspace/GIA_sim/sim_swc_wrapper/Include/viscr/project.pj
  CHANGES:        Revision 1.8 2014/02/06 13:44:52CET Ruland, Thomas (uidw0251) 
  CHANGES:        Adaption to changed stereo image map sizes
  CHANGES:        - Added comments -  uidw0251 [Feb 6, 2014 1:44:52 PM CET]
  CHANGES:        Change Package : 216853:1 http://mks-psad:7002/im/viewissue?selection=216853
  CHANGES:        Revision 1.7 2013/08/01 11:39:33CEST Mueller, Reik (muellerr5) 
  CHANGES:        - introduced disparity image type from CCT
  CHANGES:        --- Added comments ---  muellerr5 [Aug 1, 2013 11:39:33 AM CEST]
  CHANGES:        Change Package : 184575:2 http://mks-psad:7002/im/viewissue?selection=184575
  CHANGES:        Revision 1.6 2013/07/09 13:31:27CEST Ruland, Thomas (uidw0251) 
  CHANGES:        - replacing SacFlowImage by Rte's FlowImage_t inside the sac kernel
  CHANGES:          (this makes flow warpping obsolete)
  CHANGES:        --- Added comments ---  uidw0251 [Jul 9, 2013 1:31:28 PM CEST]
  CHANGES:        Change Package : 184641:1 http://mks-psad:7002/im/viewissue?selection=184641
  CHANGES:        Revision 1.5 2012/08/21 13:58:13CEST Lugez, Boris (uidt2765) 
  CHANGES:        -> First disparity refinement implementation
  CHANGES:        --- Added comments ---  uidt2765 [Aug 21, 2012 1:58:14 PM CEST]
  CHANGES:        Change Package : 156068:1 http://mks-psad:7002/im/viewissue?selection=156068
  CHANGES:        Revision 1.4 2012/06/26 14:09:18CEST Godreau, Bertrand (uid28828) 
  CHANGES:        Add code review findings
  CHANGES:        --- Added comments ---  uid28828 [Jun 26, 2012 2:09:18 PM CEST]
  CHANGES:        Change Package : 130169:2 http://mks-psad:7002/im/viewissue?selection=130169
  CHANGES:        Revision 1.3 2012/05/24 09:54:36CEST Garcia, Lucien (uid26778) 
  CHANGES:        Add distance test debug data to sac output
  CHANGES:        --- Added comments ---  uid26778 [May 24, 2012 9:54:36 AM CEST]
  CHANGES:        Change Package : 94275:2 http://mks-psad:7002/im/viewissue?selection=94275
  CHANGES:        Revision 1.2 2012/04/27 16:41:58CEST Garcia, Lucien (uid26778) 
  CHANGES:        Add low pass filter for yaw computation
  CHANGES:        --- Added comments ---  uid26778 [Apr 27, 2012 4:41:58 PM CEST]
  CHANGES:        Change Package : 106059:1 http://mks-psad:7002/im/viewissue?selection=106059
  CHANGES:        Revision 1.1 2012/03/29 11:30:33CEST Garcia, Lucien (uid26778) 
  CHANGES:        Initial revision
  CHANGES:        Member added to project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/SAC_StereoAutoCalibration/04_Engineering/01_Source_Code/Kernel/project.pj


**************************************************************************** */

#ifndef _viscr_disttest_hpp_
#define _viscr_disttest_hpp_
#include <viscr_image.hpp>
#include <viscr_matrix.hpp>
#include <viscr_defs.h>
#include <viscr_SMPC.hpp>

////////////////////////////////////////
// Coordinate systems :
// 1 = target
// 2 = world (ground front axes)
// 3 = right camera
// 4 = left camera
// 5 = right rectified camera
// 6 = left recified camera
////////////////////////////////////////

#define VISCR_DISTTEST_T_5_1_z_accuracy_min 0.05F
#define VISCR_DISTTEST_DENSITY_MIN 0.001F
//#define VISCR_DISTTEST_YAW_ACCURACY DEG2RAD(0.022F)
#define VISCR_DISTTEST_DEBUG 0
#define VISCR_DISTTEST_DV_MAX 2
#define VISCR_DISTTEST_DU_MAX 2
#define VISCR_DISTTEST_KLTSHIFTMAX_SU 2.0F
#define VISCR_DISTTEST_KLTSHIFTMAX_SV 1.0F


struct C_DISTTEST_Errors {
  static const viscr_uint DISTTEST_NO_ERROR=0U;
  static const viscr_uint DISTTEST_ERROR=1U;
  };

struct C_DISTTEST_Mode {
  static const viscr_uint DISTTEST_Mode_Evaluate=0U;
  static const viscr_uint DISTTEST_Mode_Calibrate=1U;
  };

 struct C_DISTTEST_Coordinate {
    static const viscr_uint DISTTEST_CoordinateSystem_None = 0u;                      /*!< No coordinate system           */
    static const viscr_uint DISTTEST_CoordinateSystem_Vehicle  = 2u;                  /*!< Direction : Camera Coordinate system, Position : Ground below front axles, Unit : Meter  */
    static const viscr_uint DISTTEST_CoordinateSystem_Camera_rectified_image = 50u;   /*!< Direction : Image Coordinate system, Position : Rectified right Camera, Unit : Pixel     */
    static const viscr_uint DISTTEST_CoordinateSystem_Camera_disparity_image = 70u;   /*!< Direction : Image Coordinate system, Position : Disparity Image, Unit : Pixel            */
  };


struct viscr_disttest_input
{
  viscr_float f;
  viscr_float u0;
  viscr_float v0;
  viscr_float b;

  const DisparityImage_t * pDispImage;

  viscr_uint CoordinateSystem;
  viscr_float TopLeft[2];                /*!< X,Y-Position of top left corner */
  viscr_float BottomRight[2];            /*!< X-Position of bottom right corner */
  viscr_float TargetDistanceNorm;

  viscr_uint mode;
  /*********************************************************/
  /* if (mode == C_DISTTEST_Mode::DISTTEST_Mode_Calibrate) */
  /*********************************************************/

  viscr_mat33 R_4_3;
  viscr_mat33 R_5_3;
  viscr_mat33 R_6_4;

  viscr_mat33 R_2_3;
  viscr_vec3 T_2_3;  

  /* Inputs necessary for klt shift */
  viscr_image g_image_DistTest_rect_k0;
  viscr_image g_image_DistTest_rect_k1;
  viscr_SMPC_param g_smpc_DistTest_param;

  /* Powerflow left -> right */
  const FlowImage_t * pFlowImageSpatial;
};

struct viscr_disttest_output
{
  viscr_vec3 T_5_1_mean;
  viscr_float T_5_1_norm;
  viscr_float T_5_1_z_std;
  viscr_float T_5_1_z_min;
  viscr_float T_5_1_z_max;
  viscr_float RA_6_5_y;
  /*********************************************************/
  /* if (mode == C_DISTTEST_Mode::DISTTEST_Mode_Calibrate) */
  /*********************************************************/
  viscr_mat33 R_4_3;
  viscr_uint Errors;

  //  debug datas
  viscr_float disparity_mean;
  viscr_pixel disparity_min;
  viscr_pixel disparity_max;
  viscr_float disparity_std;
  viscr_float disparity_density; /* from 0 to 100% */

  viscr_coord TopLeft_image_disp[2];                /*!< U,V-Position of top left corner on disparity map */
  viscr_coord BottomRight_image_disp[2];           /*!< U,V-Position of bottom right corner on disparity map */
  viscr_float T_5_1_z_input;

  /* Outputs coming from klt shift */
  viscr_pixel_accu DistTest_klt_accu[2*KLT_SHIFT_RAD+1];

};

extern void viscr_disttest_run( const viscr_disttest_input * const p_disttest_input, viscr_disttest_output * const p_disttest_output);
extern void viscr_disttest_run_reset_output(viscr_disttest_output * const p_disttest_output);

#endif
