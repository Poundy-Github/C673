/*! \file **********************************************************************

  COMPANY:        Continental AG

  PROJECT:        MFC300

  CPU:            

  COMPONENT:      SAC - Stereo Auto Calibration

  MODULNAME:      viscr_rotation.cpp  

  DESCRIPTION:    rotation

  AUTHOR:         L. GARCIA
  Last Author     $Author: Wang, David (Wangd3) $

  CREATION DATE:  17.06.2011

  VERSION:        $Revision: 1.1 $
  CHANGES:        $Log: viscr_rotation.cpp  $
  CHANGES:        Revision 1.1 2021/12/13 17:28:34CET Wang, David (Wangd3) 
  CHANGES:        Initial revision
  CHANGES:        Member added to project /ADAS/Projects/MFC5xx/MFC5J3/06_Algorithm/DPU/04_Engineering/01_Source_Code/GIA_sim/sim_swc_wrapper/Include/viscr/project.pj
  CHANGES:        Revision 1.0 2017/03/03 10:40:26CET Sorge, Sven (uidg3181) 
  CHANGES:        Initial revision
  CHANGES:        Member added to project /ADAS/SW/Integration/06_Simulation_Components/GIA_GenericInterfaceAdapter/04_Engineering/03_Workspace/Component_Workspace/GIA_sim/sim_swc_wrapper/Include/viscr/project.pj
  CHANGES:        Revision 1.10 2013/10/18 10:06:07CEST Ruland, Thomas (uidw0251) 
  CHANGES:        - fixing SRoi pose by applying rectifying rotation onto the croi pose
  CHANGES:        - Added comments -  uidw0251 [Oct 18, 2013 10:06:08 AM CEST]
  CHANGES:        Change Package : 200304:1 http://mks-psad:7002/im/viewissue?selection=200304
  CHANGES:        Revision 1.9 2013/06/06 16:08:16CEST Ruland, Thomas (uidw0251) 
  CHANGES:        - fix of rotation reference implementation
  CHANGES:        --- Added comments ---  uidw0251 [Jun 6, 2013 4:08:17 PM CEST]
  CHANGES:        Change Package : 184641:1 http://mks-psad:7002/im/viewissue?selection=184641
  CHANGES:        Revision 1.8 2013/04/19 16:03:31CEST Ruland, Thomas (uidw0251) 
  CHANGES:        - changes for SacTest
  CHANGES:        --- Added comments ---  uidw0251 [Apr 19, 2013 4:03:32 PM CEST]
  CHANGES:        Change Package : 173649:1 http://mks-psad:7002/im/viewissue?selection=173649
  CHANGES:        Revision 1.7 2013/03/15 19:14:52CET Ruland, Thomas (uidw0251) 
  CHANGES:        - first complete version of wrapper
  CHANGES:        --- Added comments ---  uidw0251 [Mar 15, 2013 7:14:53 PM CET]
  CHANGES:        Change Package : 173649:1 http://mks-psad:7002/im/viewissue?selection=173649
  CHANGES:        Revision 1.6 2012/06/26 14:09:21CEST Godreau, Bertrand (uid28828) 
  CHANGES:        Add code review findings
  CHANGES:        --- Added comments ---  uid28828 [Jun 26, 2012 2:09:21 PM CEST]
  CHANGES:        Change Package : 130169:2 http://mks-psad:7002/im/viewissue?selection=130169
  CHANGES:        Revision 1.5 2012/03/08 08:53:16CET Konarski-EXT, Witek (uidt8403) 
  CHANGES:        Removed PC-Lint/Misra errors.
  CHANGES:        --- Added comments ---  uidt8403 [Mar 8, 2012 8:53:17 AM CET]
  CHANGES:        Change Package : 101150:5 http://mks-psad:7002/im/viewissue?selection=101150
  CHANGES:        Revision 1.4 2012/02/22 17:28:49CET Garcia, Lucien (uid26778) 
  CHANGES:        Remove unused code
  CHANGES:        --- Added comments ---  uid26778 [Feb 22, 2012 5:28:49 PM CET]
  CHANGES:        Change Package : 80273:2 http://mks-psad:7002/im/viewissue?selection=80273
  CHANGES:        Revision 1.3 2011/10/04 10:13:07CEST Garcia, Lucien (uid26778) 
  CHANGES:        Remove PC lints
  CHANGES:        --- Added comments ---  uid26778 [Oct 4, 2011 10:13:07 AM CEST]
  CHANGES:        Change Package : 80273:1 http://mks-psad:7002/im/viewissue?selection=80273


**************************************************************************** */

#include <cmath>
#include <viscr_rotation.hpp>

void
viscr_XYZFixedAngles2RotationMatrix(
    viscr_mat33 & R,
    /* ~CodeReview ~ID:4a834355990ca1f38d69eac98c0f7bb6 ~Reviewer:CW01\uid28828 ~Date:21/06/2012 ~Priority:3 ~Comment:Use of generic float. No guarantee it is a f32_t type */
    const viscr_float X,
    const viscr_float Y,
    const viscr_float Z)
{
  viscr_float a=Z;
  viscr_float b=Y;
  viscr_float g=X;

  viscr_float ca = std::cosf(a);
  viscr_float sa = std::sinf(a);
  viscr_float cb = std::cosf(b);
  viscr_float sb = std::sinf(b);
  viscr_float cg = std::cosf(g);
  viscr_float sg = std::sinf(g);

  R.m( 0U, 0U) = ca*cb;
  R.m( 1U, 0U) = sa*cb;
  R.m( 2U, 0U) = -sb;
  R.m( 0U, 1U) = (ca*sb*sg) - (sa*cg);
  R.m( 1U, 1U) = (sa*sb*sg) + (ca*cg);
  R.m( 2U, 1U) = cb*sg;
  R.m( 0U, 2U) = (ca*sb*cg) + (sa*sg);
  R.m( 1U, 2U) = (sa*sb*cg) - (ca*sg);
  R.m( 2U, 2U) = cb*cg;
}

void
viscr_rotation_composeMatrix_mobileFramePassiveCompositionZYprimeXprimeprime(
  viscr_mat33 & R,
  const viscr_float xRoll,
  const viscr_float yPitch,
  const viscr_float zYaw)
{
  viscr_float cZYaw   = std::cosf(zYaw);
  viscr_float sZYaw   = std::sinf(zYaw);
  viscr_float cYPitch = std::cosf(yPitch);
  viscr_float sYPitch = std::sinf(yPitch);
  viscr_float cXRoll  = std::cosf(xRoll);
  viscr_float sXRoll  = std::sinf(xRoll);

  R.m( 0U, 0U) = cZYaw*cYPitch;
  R.m( 0U, 1U) = sZYaw*cYPitch;
  R.m( 0U, 2U) = -sYPitch;
  R.m( 1U, 0U) = (cZYaw*sYPitch*sXRoll) - (sZYaw*cXRoll);
  R.m( 1U, 1U) = (sZYaw*sYPitch*sXRoll) + (cZYaw*cXRoll);
  R.m( 1U, 2U) = cYPitch*sXRoll;
  R.m( 2U, 0U) = (cZYaw*sYPitch*cXRoll) + (sZYaw*sXRoll);
  R.m( 2U, 1U) = (sZYaw*sYPitch*cXRoll) - (cZYaw*sXRoll);
  R.m( 2U, 2U) = cYPitch*cXRoll;
}

#if 0 // CODE NOT USED
void
viscr_RodriguesVector2RotationMatrix(
    viscr_mat33 & R,
    const viscr_vector & r)
{
  assert( r.length==3U);
  viscr_float theta=viscr_vec_norm(r);
  if( theta< FLT_EPSILON)
  {
    R.m(0U,0U)=1.0F;
    R.m(0U,1U)=0.0F;
    R.m(0U,2U)=0.0F;

    R.m(1U,0U)=0.0F;
    R.m(1U,1U)=1.0F;
    R.m(1U,2U)=0.0F;

    R.m(2U,0U)=0.0F;
    R.m(2U,1U)=0.0F;
    R.m(2U,2U)=1.0F;
  }
  else
  {
    viscr_float k0=r.data[0]/theta;
    viscr_float k1=r.data[1]/theta;
    viscr_float k2=r.data[2]/theta;

    viscr_float c=cos( theta);
    viscr_float s=sin( theta);
    viscr_float v=1.0F-c;

    R.m(0U,0U)=(k0*k0*v)+c;
    R.m(0U,1U)=(k0*k1*v)-(k2*s);
    R.m(0U,2U)=(k0*k2*v)+(k1*s);

    R.m(1U,0U)=(k0*k1*v)+(k2*s);
    R.m(1U,1U)=(k1*k1*v)+c;
    R.m(1U,2U)=(k1*k2*v)-(k0*s);

    R.m(2U,0U)=(k0*k2*v)-(k1*s);
    R.m(2U,1U)=(k1*k2*v)+(k0*s);
    R.m(2U,2U)=(k2*k2*v)+c;
  }
}
#endif

void 
viscr_RotationMatrix2XYZFixedAngles( 
    viscr_float & X, 
    viscr_float & Y, 
    viscr_float & Z, 
    const viscr_mat33 & R)
{
  // This is one option. See 
  // @BOOK{Craig89,
  //   title = {Introduction to Robotics},
  //   publisher = {Addison-Wesley Publishing Company},
  //   year = {1989},
  //   author = {John J. Craig},
  //   edition = {2.},
  //   owner = {marckon},
  //   pdf = {Craig89_Chapter2.pdf},
  //   timestamp = {2008.01.11}
  // }

  /* ~CodeReview ~ID:34cd2256f0801d9b12c8bdacf351e7eb ~Reviewer:CW01\uid28828 ~Date:21/06/2012 ~Priority:2 ~Comment:very low value in the denominator of the arctan function may have impact on function */
  Y=std::atan2f( -R.m(2U,0U), std::sqrtf((R.m(0U,0U)*R.m(0U,0U))+(R.m(1U,0U)*R.m(1U,0U))));
  Z=std::atan2f(  R.m(1U,0U), R.m(0U,0U));
  X=std::atan2f(  R.m(2U,1U), R.m(2U,2U));
}

/* ~CodeReview ~ID:401e2fa93c5f2cc70c2da0a0badd21fc ~Reviewer:CW01\uid28828 ~Date:21/06/2012 ~Priority:3 ~Comment:same function as viscr_transformation_invert */
void
viscr_invert_transformation(
    viscr_mat44 & Hinv,
    const viscr_mat44 & H)
{
  // H=[R t ; 0 0 0 1]
  // Hinv = [R' -R'*t]

  for( viscr_uint r=0U; r<3U; ++r)
  {
    Hinv.m(3U,r)=0.0F;
    Hinv.m(r,3U)=0.0F;
    for( viscr_uint c=0U; c<3U; ++c)
    {
      Hinv.m(r,c)=H.m(c,r);
      Hinv.m(r,3U) -= H.m(c,r)*H.m(c,3U);
    }
  }
  Hinv.m(3U,3U)=1.0F;
}

void viscr_rotation_decomposeMatrix_mobileFramePassiveCompositionZYprimeXprimeprime(
  viscr_float & xRoll, viscr_float & yPitch, viscr_float & zYaw, const viscr_mat33 & R)
// order of rotation: roll (x-axis), pitch (y-axis), yaw (z-axis)
// see also publication "Computing Euler angles from a rotation matrix" form Gregory G. Slabaugh
// also according to Doors specification 2.1.2 Definition of Extrinsic Parameters, ID :  3496

{ 
  // Decomposition of R_Vcl_Rect. This is valid since the angles are in a range of \pm 10 degree around 0
  yPitch = -asinf(R.m(0,2));
  xRoll  =  atan2f((R.m(1,2) / cosf(yPitch)), (R.m(2,2) / cosf(yPitch)));
  zYaw   =  atan2f((R.m(0,1) / cosf(yPitch)), (R.m(0,0) / cosf(yPitch)));
}

void viscr_rotation_addA(viscr_mat33 & AR, const viscr_mat33 & R) {
  viscr_mat33 A;
  A.m(0,0) = 0;
  A.m(0,1) = -1;
  A.m(0,2) = 0;

  A.m(1,0) = 0;
  A.m(1,1) = 0;
  A.m(1,2) = -1;

  A.m(2,0) = 1;
  A.m(2,1) = 0;
  A.m(2,2) = 0;
  viscr_mat_mult_mat(AR.m, A.m, R.m);
}

void viscr_rotation_removeA(viscr_mat33 & R, const viscr_mat33 & AR) {
  viscr_mat33 AInv;
  AInv.m(0,0) = 0;
  AInv.m(0,1) = 0;
  AInv.m(0,2) = 1;

  AInv.m(1,0) = -1;
  AInv.m(1,1) = 0;
  AInv.m(1,2) = 0;

  AInv.m(2,0) = 0;
  AInv.m(2,1) = -1;
  AInv.m(2,2) = 0;
  viscr_mat_mult_mat(R.m, AInv.m, AR.m);
}
