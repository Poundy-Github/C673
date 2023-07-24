/*! \file **********************************************************************

  COMPANY:        Continental AG

  PROJECT:        MFC300

  CPU:            

  COMPONENT:      SAC - Stereo Auto Calibration

  MODULNAME:      viscr_rotation.hpp  

  DESCRIPTION:    rotation

  AUTHOR:         L. GARCIA
  Last Author     $Author: Wang, David (Wangd3) $

  CREATION DATE:  17.06.2011

  VERSION:        $Revision: 1.1 $
  CHANGES:        $Log: viscr_rotation.hpp  $
  CHANGES:        Revision 1.1 2021/12/13 17:28:34CET Wang, David (Wangd3) 
  CHANGES:        Initial revision
  CHANGES:        Member added to project /ADAS/Projects/MFC5xx/MFC5J3/06_Algorithm/DPU/04_Engineering/01_Source_Code/GIA_sim/sim_swc_wrapper/Include/viscr/project.pj
  CHANGES:        Revision 1.0 2017/03/03 10:40:27CET Sorge, Sven (uidg3181) 
  CHANGES:        Initial revision
  CHANGES:        Member added to project /ADAS/SW/Integration/06_Simulation_Components/GIA_GenericInterfaceAdapter/04_Engineering/03_Workspace/Component_Workspace/GIA_sim/sim_swc_wrapper/Include/viscr/project.pj
  CHANGES:        Revision 1.6 2013/10/18 10:06:09CEST Ruland, Thomas (uidw0251) 
  CHANGES:        - fixing SRoi pose by applying rectifying rotation onto the croi pose
  CHANGES:        - Added comments -  uidw0251 [Oct 18, 2013 10:06:09 AM CEST]
  CHANGES:        Change Package : 200304:1 http://mks-psad:7002/im/viewissue?selection=200304
  CHANGES:        Revision 1.5 2013/04/19 16:03:30CEST Ruland, Thomas (uidw0251) 
  CHANGES:        - changes for SacTest
  CHANGES:        --- Added comments ---  uidw0251 [Apr 19, 2013 4:03:30 PM CEST]
  CHANGES:        Change Package : 173649:1 http://mks-psad:7002/im/viewissue?selection=173649
  CHANGES:        Revision 1.4 2013/03/15 19:14:53CET Ruland, Thomas (uidw0251) 
  CHANGES:        - first complete version of wrapper
  CHANGES:        --- Added comments ---  uidw0251 [Mar 15, 2013 7:14:53 PM CET]
  CHANGES:        Change Package : 173649:1 http://mks-psad:7002/im/viewissue?selection=173649
  CHANGES:        Revision 1.3 2012/02/22 17:28:50CET Garcia, Lucien (uid26778) 
  CHANGES:        Remove unused code
  CHANGES:        --- Added comments ---  uid26778 [Feb 22, 2012 5:28:50 PM CET]
  CHANGES:        Change Package : 80273:2 http://mks-psad:7002/im/viewissue?selection=80273
  CHANGES:        Revision 1.2 2011/10/04 10:13:08CEST Garcia, Lucien (uid26778) 
  CHANGES:        Remove PC lints
  CHANGES:        --- Added comments ---  uid26778 [Oct 4, 2011 10:13:08 AM CEST]
  CHANGES:        Change Package : 80273:1 http://mks-psad:7002/im/viewissue?selection=80273


**************************************************************************** */

#ifndef _viscr_rotation_hpp_
#define _viscr_rotation_hpp_

#include <viscr_matrix.hpp>

/// Compute rotation matrix R from XYZ-fixed angles
extern void
viscr_XYZFixedAngles2RotationMatrix(
    viscr_mat33 & R,
    const viscr_float X,
    const viscr_float Y,
    const viscr_float Z);

/// Checked rotation composition according to DIN9300
extern void
viscr_rotation_composeMatrix_mobileFramePassiveCompositionZYprimeXprimeprime(
  viscr_mat33 & R,
  const viscr_float xRoll,
  const viscr_float yPitch,
  const viscr_float zYaw);

extern 
void viscr_rotation_decomposeMatrix_mobileFramePassiveCompositionZYprimeXprimeprime(
  viscr_float & xRoll, viscr_float & yPitch, viscr_float & zYaw, const viscr_mat33 & R);

#if 0 // CODE NOT USED
/// Compute rotation matrix from Rodrigues vector.
/// The length of the vector gives the angle in radians.
extern void
viscr_RodriguesVector2RotationMatrix(
    viscr_mat33 & R,
    const viscr_vector & r);
#endif

/// Compute the XYZ-fiex angles from the rotation matrix
extern void 
viscr_RotationMatrix2XYZFixedAngles( 
    viscr_float & X, 
    viscr_float & Y, 
    viscr_float & Z, 
    const viscr_mat33 & R);


/// Invert a homogeneous transformation
extern void
viscr_invert_transformation(
    viscr_mat44 & Hinv,
    const viscr_mat44 & H);

/// Add the basic rotation matrix between ASAR and physical camera frame to a rotation R
extern void 
viscr_rotation_addA(viscr_mat33 & AR, const viscr_mat33 & R);

/// Remove the basic rotation matrix between ASAR and physical camera frame from a rotation R
extern void 
viscr_rotation_removeA(viscr_mat33 & R, const viscr_mat33 & AR);

#endif
