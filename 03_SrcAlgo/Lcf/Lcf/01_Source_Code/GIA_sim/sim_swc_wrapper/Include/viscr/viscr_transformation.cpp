/*! \file **********************************************************************

  COMPANY:        Continental AG

  PROJECT:        MFC300

  CPU:            

  COMPONENT:      SAC - Stereo Auto Calibration

  MODULNAME:      viscr_transformation.cpp  

  DESCRIPTION:    transformation

  AUTHOR:         L. GARCIA
  Last Author     $Author: Wang, David (Wangd3) $

  CREATION DATE:  17.06.2011

  VERSION:        $Revision: 1.1 $
  CHANGES:        $Log: viscr_transformation.cpp  $
  CHANGES:        Revision 1.1 2021/12/13 17:28:40CET Wang, David (Wangd3) 
  CHANGES:        Initial revision
  CHANGES:        Member added to project /ADAS/Projects/MFC5xx/MFC5J3/06_Algorithm/DPU/04_Engineering/01_Source_Code/GIA_sim/sim_swc_wrapper/Include/viscr/project.pj
  CHANGES:        Revision 1.0 2017/03/03 10:40:40CET Sorge, Sven (uidg3181) 
  CHANGES:        Initial revision
  CHANGES:        Member added to project /ADAS/SW/Integration/06_Simulation_Components/GIA_GenericInterfaceAdapter/04_Engineering/03_Workspace/Component_Workspace/GIA_sim/sim_swc_wrapper/Include/viscr/project.pj
  CHANGES:        Revision 1.11 2013/10/18 10:06:29CEST Ruland, Thomas (uidw0251) 
  CHANGES:        - fixing SRoi pose by applying rectifying rotation onto the croi pose
  CHANGES:        - Added comments -  uidw0251 [Oct 18, 2013 10:06:30 AM CEST]
  CHANGES:        Change Package : 200304:1 http://mks-psad:7002/im/viewissue?selection=200304
  CHANGES:        Revision 1.10 2013/08/15 14:29:09CEST Daiber-EXT, Sebastian (uidw3458) 
  CHANGES:        reduce calls to dsp rte and number of divisions
  CHANGES:        --- Added comments ---  uidw3458 [Aug 15, 2013 2:29:09 PM CEST]
  CHANGES:        Change Package : 191881:1 http://mks-psad:7002/im/viewissue?selection=191881
  CHANGES:        Revision 1.9 2013/03/15 19:14:58CET Ruland, Thomas (uidw0251) 
  CHANGES:        - first complete version of wrapper
  CHANGES:        --- Added comments ---  uidw0251 [Mar 15, 2013 7:14:59 PM CET]
  CHANGES:        Change Package : 173649:1 http://mks-psad:7002/im/viewissue?selection=173649
  CHANGES:        Revision 1.8 2012/06/19 14:53:31CEST Godreau, Bertrand (uid28828) 
  CHANGES:        add findings from code review
  CHANGES:        --- Added comments ---  uid28828 [Jun 19, 2012 2:53:31 PM CEST]
  CHANGES:        Change Package : 130169:2 http://mks-psad:7002/im/viewissue?selection=130169
  CHANGES:        Revision 1.7 2012/04/06 16:36:09CEST Garcia, Lucien (uid26778) 
  CHANGES:        Test and implement 3D box for distance test
  CHANGES:        --- Added comments ---  uid26778 [Apr 6, 2012 4:36:09 PM CEST]
  CHANGES:        Change Package : 106059:1 http://mks-psad:7002/im/viewissue?selection=106059
  CHANGES:        Revision 1.6 2012/03/29 11:29:09CEST Garcia, Lucien (uid26778) 
  CHANGES:        Implement distance test and merge eol calibration function
  CHANGES:        --- Added comments ---  uid26778 [Mar 29, 2012 11:29:09 AM CEST]
  CHANGES:        Change Package : 94275:2 http://mks-psad:7002/im/viewissue?selection=94275
  CHANGES:        Revision 1.5 2012/03/02 11:04:20CET Garcia, Lucien (uid26778) 
  CHANGES:        Remove unused code
  CHANGES:        --- Added comments ---  uid26778 [Mar 2, 2012 11:04:20 AM CET]
  CHANGES:        Change Package : 80273:2 http://mks-psad:7002/im/viewissue?selection=80273
  CHANGES:        Revision 1.4 2012/02/21 15:25:13CET Garcia, Lucien (uid26778) 
  CHANGES:        Remove unused code
  CHANGES:        --- Added comments ---  uid26778 [Feb 21, 2012 3:25:13 PM CET]
  CHANGES:        Change Package : 80273:2 http://mks-psad:7002/im/viewissue?selection=80273
  CHANGES:        Revision 1.3 2011/10/04 16:27:33CEST Garcia, Lucien (uid26778) 
  CHANGES:        Remove lint warnings
  CHANGES:        --- Added comments ---  uid26778 [Oct 4, 2011 4:27:33 PM CEST]
  CHANGES:        Change Package : 80273:1 http://mks-psad:7002/im/viewissue?selection=80273


**************************************************************************** */

#include <viscr_transformation.hpp>

/* ~CodeReview ~ID:c9f754ec123c0e6055187014a89e1afb ~Reviewer:CW01\uid28828 ~Date:19/06/2012 ~Priority:3 ~Comment:Remove dead code for readability */


void
viscr_transformation_invert(viscr_mat44 & HInv, const viscr_mat44 & H)
{
  // H=[R t ; 0 0 0 1]
  // Hinv = [R' -R'*t]

  for (viscr_uint r = 0U; r < 3U; ++r)
  {
    HInv.m(3U, r) = 0.0F;
    HInv.m(r, 3U) = 0.0F;
    for (viscr_uint c = 0U; c < 3U; ++c)
    {
      HInv.m(r, c) = H.m(c, r);
      HInv.m(r, 3U) -= H.m(c, r) * H.m(c, 3U);
    }
  }
  HInv.m(3U, 3U) = 1.0F;
}

void
viscr_transformation_decompose_tPrime(viscr_mat33 & R, viscr_vec3 & t_prime,
    const viscr_mat44 & T)
{
  //R_A = T(1:3,1:3);
  for (viscr_uint row = 0U; row < 3U; row++)
  {
    for (viscr_uint col = 0U; col < 3U; col++)
    {
      R.m(row, col) = T.m(row, col);
    }
  }

  //t_A = T(1:3,4);
  viscr_vec3 t;
  for (viscr_uint row = 0U; row < 3U; row++)
  {
    t.v[row] = T.m(row, 3U);
  }

  //t_A_prime = -R_A' * t_A;
  viscr_mat33 R_transposed;
  viscr_mat_transpose_copy(R_transposed.m, R.m);
  viscr_mat_mult_vec(t_prime.v, R_transposed.m, t.v);
  viscr_vec_mult_scalar(t_prime.v, -1.);
}

void
viscr_transformation_compose_tPrime(viscr_mat44 & T, const viscr_mat33 & R,
    const viscr_vec3 & t_prime)
{
  viscr_mat_zero(T.m);
  //t = -R * t_prime
  viscr_vec3 t;
  viscr_mat_mult_vec(t.v,R.m,t_prime.v);
  viscr_vec_negate(t.v);

  //R_A = T(1:3,1:3);
  for (viscr_uint row = 0U; row < 3U; row++)
  {
    for (viscr_uint col = 0U; col < 3U; col++)
    {
      T.m(row, col) = R.m(row, col);
    }
  }
  //t_A = T(1:3,4);
  for (viscr_uint row = 0U; row < 3U; row++)
  {
    T.m(row, 3U) = t.v[row];
  }

  T.m(3U, 3U) = 1.;
}

void
viscr_transformation_compose(viscr_mat44 & T, const viscr_mat33 & R,
    const viscr_vec3 & t)
{
  viscr_mat_zero(T.m);
  //R_A = T(1:3,1:3);
  for (viscr_uint row = 0U; row < 3U; row++)
  {
    for (viscr_uint col = 0U; col < 3U; col++)
    {
      T.m(row, col) = R.m(row, col);
    }
  }
  //t_A = T(1:3,4);
  for (viscr_uint row = 0U; row < 3U; row++)
  {
    T.m(row, 3U) = t.v[row];
  }

  T.m(3U, 3U) = 1.;
}



//#endif
#if (VISCR_SMPC_REMOVE_YAW_IN_FINE==0) 
viscr_float
viscr_transformation_translationNorm(const viscr_mat44 & H)
{
  viscr_float s = 0.0F;
  for (viscr_uint i = 0U; i < 3U; ++i)
    {s += H.m(i, 3U) * H.m(i, 3U);}
  return sqrtf(s);
}
#endif
#if 0 // CODE NOT USED
void
viscr_transformation_tXToTXPrime(viscr_vec3 & t_X_prime,
    const viscr_mat33 & R_X, const viscr_vec3 & t_X)
{
  viscr_mat33 R_X_transposed;
  viscr_mat_transpose_copy(R_X_transposed.m, R_X.m);

  viscr_mat_mult_vec(t_X_prime.v, R_X_transposed.m, t_X.v);

  viscr_vec_negate(t_X_prime.v);
}
#endif
#if 0 // CODE NOT USED
void
viscr_transformation_tXPrimeToTX(viscr_vec3 & t_X, const viscr_mat33 & R_X,
    const viscr_vec3 & t_X_prime)
{
  viscr_mat_mult_vec(t_X.v, R_X.m, t_X_prime.v);
  viscr_vec_negate(t_X.v);
}
#endif
#if 0 // CODE NOT USED
void
viscr_transformation_euclidean(viscr_vec3 & v, const viscr_mat33 & R,
    const viscr_vec3 & t)
{
  viscr_vec3 tmp;
  //inplace usage in viscr_mat_mult_vec is not allowed
  viscr_mat_mult_vec(tmp.v, R.m, v.v);
  viscr_vec_add(tmp.v, t.v);
  v = tmp;
}
#endif
