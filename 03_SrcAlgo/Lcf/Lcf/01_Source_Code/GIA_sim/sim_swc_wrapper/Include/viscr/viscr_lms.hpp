/*! \file **********************************************************************

  COMPANY:        Continental AG

  PROJECT:        MFC300

  CPU:            

  COMPONENT:      SAC - Stereo Auto Calibration

  MODULNAME:      viscr_lms.hpp  

  DESCRIPTION:    Methods for least-mean squares estimations

  AUTHOR:         L. GARCIA
  Last Author     $Author: Wang, David (Wangd3) $

  CREATION DATE:  17.06.2011

  VERSION:        $Revision: 1.1 $
  CHANGES:        $Log: viscr_lms.hpp  $
  CHANGES:        Revision 1.1 2021/12/13 17:28:30CET Wang, David (Wangd3) 
  CHANGES:        Initial revision
  CHANGES:        Member added to project /ADAS/Projects/MFC5xx/MFC5J3/06_Algorithm/DPU/04_Engineering/01_Source_Code/GIA_sim/sim_swc_wrapper/Include/viscr/project.pj
  CHANGES:        Revision 1.0 2017/03/03 10:40:19CET Sorge, Sven (uidg3181) 
  CHANGES:        Initial revision
  CHANGES:        Member added to project /ADAS/SW/Integration/06_Simulation_Components/GIA_GenericInterfaceAdapter/04_Engineering/03_Workspace/Component_Workspace/GIA_sim/sim_swc_wrapper/Include/viscr/project.pj
  CHANGES:        Revision 1.4 2012/06/26 14:09:20CEST Godreau, Bertrand (uid28828) 
  CHANGES:        Add code review findings
  CHANGES:        - Added comments -  uid28828 [Jun 26, 2012 2:09:20 PM CEST]
  CHANGES:        Change Package : 130169:2 http://mks-psad:7002/im/viewissue?selection=130169
  CHANGES:        Revision 1.3 2012/02/22 17:28:53CET Garcia, Lucien (uid26778) 
  CHANGES:        Remove unused code
  CHANGES:        --- Added comments ---  uid26778 [Feb 22, 2012 5:28:53 PM CET]
  CHANGES:        Change Package : 80273:2 http://mks-psad:7002/im/viewissue?selection=80273
  CHANGES:        Revision 1.2 2011/10/04 16:05:47CEST Garcia, Lucien (uid26778) 
  CHANGES:        Remove Lint warnings
  CHANGES:        --- Added comments ---  uid26778 [Oct 4, 2011 4:05:47 PM CEST]
  CHANGES:        Change Package : 80273:1 http://mks-psad:7002/im/viewissue?selection=80273

**************************************************************************** */

#ifndef _viscr_lms_hpp_
#define _viscr_lms_hpp_

#include <viscr_vector.hpp>
#include <viscr_matrix.hpp>

/** @name Methods for least-mean squares estimations.
 *
 * Can be used to solve Ax=b for overdetermined systems of equations.
 *
 * Assumes all matrices and vectors are pre-allocated and of proper size.
 */
/*@{*/

/* ~CodeReview ~ID:41b845b7afdfdcc53fad483b6ae25410 ~Reviewer:CW01\uid28828 ~Date:21/06/2012 ~Priority:3 ~Comment:remove dead code for readability */

/// Compute AtA += A' * A, Atb += A' * b
#if 0 // CODE NOT USED
extern void
viscr_lms_addRow( 
    viscr_matrix & AtA,
    viscr_vector & Atb,
    const viscr_vector & A,
    const viscr_float b);
#endif

/// Compute AtA += wt * (A' * A), Atb += wt * (A' * b)
extern void
viscr_lms_addRow_weight( 
    viscr_matrix & AtA,
    viscr_vector & Atb,
    const viscr_vector & A,
    const viscr_float b,
    const viscr_float wt);

/*@}*/

#endif

