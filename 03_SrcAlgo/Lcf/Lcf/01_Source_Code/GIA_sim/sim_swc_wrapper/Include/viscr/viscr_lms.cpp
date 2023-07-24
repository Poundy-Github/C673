/*! \file **********************************************************************

  COMPANY:        Continental AG

  PROJECT:        MFC300

  CPU:            

  COMPONENT:      SAC - Stereo Auto Calibration

  MODULNAME:      viscr_lms.cpp  

  DESCRIPTION:    Methods for least-mean squares estimations

  AUTHOR:         L. GARCIA
  Last Author     $Author: Wang, David (Wangd3) $

  CREATION DATE:  17.06.2011

  VERSION:        $Revision: 1.1 $
  CHANGES:        $Log: viscr_lms.cpp  $
  CHANGES:        Revision 1.1 2021/12/13 17:28:30CET Wang, David (Wangd3) 
  CHANGES:        Initial revision
  CHANGES:        Member added to project /ADAS/Projects/MFC5xx/MFC5J3/06_Algorithm/DPU/04_Engineering/01_Source_Code/GIA_sim/sim_swc_wrapper/Include/viscr/project.pj
  CHANGES:        Revision 1.0 2017/03/03 10:40:18CET Sorge, Sven (uidg3181) 
  CHANGES:        Initial revision
  CHANGES:        Member added to project /ADAS/SW/Integration/06_Simulation_Components/GIA_GenericInterfaceAdapter/04_Engineering/03_Workspace/Component_Workspace/GIA_sim/sim_swc_wrapper/Include/viscr/project.pj
  CHANGES:        Revision 1.5 2012/06/26 14:09:19CEST Godreau, Bertrand (uid28828) 
  CHANGES:        Add code review findings
  CHANGES:        - Added comments -  uid28828 [Jun 26, 2012 2:09:20 PM CEST]
  CHANGES:        Change Package : 130169:2 http://mks-psad:7002/im/viewissue?selection=130169
  CHANGES:        Revision 1.4 2012/03/30 14:06:12CEST Garcia, Lucien (uid26778) 
  CHANGES:        Lint warning corrections : Bitexactness test and MTS simulation OK
  CHANGES:        --- Added comments ---  uid26778 [Mar 30, 2012 2:06:12 PM CEST]
  CHANGES:        Change Package : 80273:1 http://mks-psad:7002/im/viewissue?selection=80273
  CHANGES:        Revision 1.3 2012/02/22 17:28:53CET Garcia, Lucien (uid26778) 
  CHANGES:        Remove unused code
  CHANGES:        --- Added comments ---  uid26778 [Feb 22, 2012 5:28:53 PM CET]
  CHANGES:        Change Package : 80273:2 http://mks-psad:7002/im/viewissue?selection=80273
  CHANGES:        Revision 1.2 2011/10/04 16:05:46CEST Garcia, Lucien (uid26778) 
  CHANGES:        Remove Lint warnings
  CHANGES:        --- Added comments ---  uid26778 [Oct 4, 2011 4:05:46 PM CEST]
  CHANGES:        Change Package : 80273:1 http://mks-psad:7002/im/viewissue?selection=80273

**************************************************************************** */


#include <cassert>
#include <viscr_lms.hpp>

#if 0 // NOT USED
void
viscr_lms_addRow( 
    viscr_matrix & AtA,
    viscr_vector & Atb,
    const viscr_vector & A,
    const viscr_float b)
{
  assert( AtA.rows==AtA.cols);
  assert( AtA.rows==A.length);
  assert( AtA.rows==Atb.length);
  assert( AtA.rows==A.length);

  for( viscr_uint i=0U; i<AtA.rows; ++i)
  {
    Atb.data[i]+=A.data[i]*b;
    for( viscr_uint j=0U; j<AtA.rows; ++j)
      {AtA(i,j)+=A.data[i]*A.data[j];}
  }
}
#endif

void
viscr_lms_addRow_weight( 
    viscr_matrix & AtA,
    viscr_vector & Atb,
    const viscr_vector & A,
    /* ~CodeReview ~ID:15f3dcedc774076765da6741002e28cb ~Reviewer:CW01\uid28828 ~Date:21/06/2012 ~Priority:3 ~Comment:Use of generic float. No guarantee it is a f32_t type */
    const viscr_float b,
    const viscr_float wt)
{
  /* ~CodeReview ~ID:c398d11aa2f56d707de5ea3ba371545e ~Reviewer:CW01\uid28828 ~Date:21/06/2012 ~Priority:3 ~Comment:use of assert function for error management. Unknown behavior in case of errors.  */  
  assert( AtA.rows==AtA.cols);
  assert( AtA.rows==A.length);
  assert( AtA.rows==Atb.length);
  assert( AtA.rows==A.length);

  viscr_float * pfloat_i_for_misra;
  viscr_float * pfloat_j_for_misra;
  viscr_float * pfloat_atb_for_misra;
  pfloat_i_for_misra = A.data;
  pfloat_atb_for_misra = Atb.data;
  for( viscr_uint i=0U; i<AtA.rows; ++i)
  {
    *pfloat_atb_for_misra += wt*(*pfloat_i_for_misra)*b;
//    Atb.data[i]+=wt*A.data[i]*b;
    pfloat_j_for_misra = A.data;
    for( viscr_uint j=0U; j<AtA.rows; ++j)
      {
		  AtA(i,j)+=wt*(*pfloat_i_for_misra)*(*pfloat_j_for_misra);
//		  AtA(i,j)+=wt*A.data[i]*A.data[j];
          pfloat_j_for_misra++;
	  }
	pfloat_i_for_misra++;
	pfloat_atb_for_misra++;
  }
}

