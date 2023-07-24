/*! \file **********************************************************************

  COMPANY:                Continental AG, BU PSAD, Segment ADAS (A.D.C. GmbH)

  PROJECT:                MFC300

  CPU:                    FreeScale Gold Dust

  COMPONENT:              HLA

  MODULNAME:              hla_trackmodel.c

  DESCRIPTION:            Shared model between dynamic, slam and static tracker

  AUTHOR:                 Bertrand Godreau

  CREATION DATE:          2012-01-17

  VERSION:                $Revision: 1.1 $

  CHANGES:                

  ---*/ /*---
  CHANGE:                 $Log: hla_trackmodel.c  $
  CHANGE:                 Revision 1.1 2021/12/13 17:28:10CET Wang, David (Wangd3) 
  CHANGE:                 Initial revision
  CHANGE:                 Member added to project /ADAS/Projects/MFC5xx/MFC5J3/06_Algorithm/DPU/04_Engineering/01_Source_Code/GIA_sim/sim_swc_wrapper/Include/mfc310Hla/tracking/project.pj
  CHANGE:                 Revision 1.0 2017/03/03 10:39:52CET Sorge, Sven (uidg3181) 
  CHANGE:                 Initial revision
  CHANGE:                 Member added to project /ADAS/SW/Integration/06_Simulation_Components/GIA_GenericInterfaceAdapter/04_Engineering/03_Workspace/Component_Workspace/GIA_sim/sim_swc_wrapper/Include/mfc310Hla/tracking/project.pj
  CHANGE:                 Revision 1.1 2014/04/17 16:06:11CEST Sorge, Sven (uidg3181) 
  CHANGE:                 Initial revision
  CHANGE:                 Member added to project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/ETK_EngineeringToolKit/04_Engineering/GIA_GenericInterfaceAdapter/04_Engineering/03_Workspace/algo/gia_sim/wrapper/Include/mfc310Hla/tracking/project.pj
  CHANGE:                 Revision 1.15 2014/03/26 11:27:32CET Mutschler, Matthias (uidv7867) 
  CHANGE:                 Removed some mandatory QAC warnings
  CHANGE:                 --- Added comments ---  uidv7867 [Mar 26, 2014 11:27:33 AM CET]
  CHANGE:                 Change Package : 207432:35 http://mks-psad:7002/im/viewissue?selection=207432
  CHANGE:                 Revision 1.14 2014/03/25 18:44:28CET Mutschler, Matthias (uidv7867) 
  CHANGE:                 Member moved from hla_trackmodel.c in project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/HLA_HeadLightAssist/04_Engineering/01_Source_Code/algo/hla/project.pj to hla_trackmodel.c in project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/HLA_HeadLightAssist/04_Engineering/01_Source_Code/algo/hla/tracking/project.pj.
  CHANGE:                 Revision 1.13 2014/03/19 16:31:06CET Mutschler, Matthias (uidv7867) 
  CHANGE:                 Replace macros from glob_defs.h by the ones defined in cml_ext.h
  CHANGE:                 Fixed hlar input adapter for old recordings (headlamp type)
  CHANGE:                 Clean-up of no longer needed files in simulation
  CHANGE:                 --- Added comments ---  uidv7867 [Mar 19, 2014 4:31:06 PM CET]
  CHANGE:                 Change Package : 225959:1 http://mks-psad:7002/im/viewissue?selection=225959
  CHANGE:                 Revision 1.12 2014/03/04 16:52:10CET Mutschler, Matthias (uidv7867) 
  CHANGE:                 Fixed QAC warnings
  CHANGE:                 Coding style
  CHANGE:                 --- Added comments ---  uidv7867 [Mar 4, 2014 4:52:11 PM CET]
  CHANGE:                 Change Package : 207432:35 http://mks-psad:7002/im/viewissue?selection=207432
  CHANGE:                 Revision 1.11 2014/01/24 13:37:50CET Manz, Alexander (uidv8777) 
  CHANGE:                 Update:
  CHANGE:                  - adapt to HLA coding guidelines (more)
  CHANGE:                 --- Added comments ---  uidv8777 [Jan 24, 2014 1:37:50 PM CET]
  CHANGE:                 Change Package : 207634:1 http://mks-psad:7002/im/viewissue?selection=207634
  CHANGE:                 Revision 1.10 2014/01/24 09:35:02CET Glebov, Roman (uidg4759) 
  CHANGE:                 switched from F32_IS_.* from global_defs.h to HLA_F32_IS_.* from hla_defs.h. 
  CHANGE:                 These are custom versions, which use much smaller Epsilon delta for comparison with 0
  CHANGE:                 --- Added comments ---  uidg4759 [Jan 24, 2014 9:35:02 AM CET]
  CHANGE:                 Change Package : 193435:4 http://mks-psad:7002/im/viewissue?selection=193435
  CHANGE:                 Revision 1.9 2014/01/21 13:57:44CET Glebov, Roman (uidg4759) 
  CHANGE:                 fixed unsafe comparison of float with 0
  CHANGE:                 --- Added comments ---  uidg4759 [Jan 21, 2014 1:57:45 PM CET]
  CHANGE:                 Change Package : 193435:4 http://mks-psad:7002/im/viewissue?selection=193435
  CHANGE:                 Revision 1.8 2014/01/21 13:09:14CET Manz, Alexander (uidv8777) 
  CHANGE:                 Cosmetic changes:
  CHANGE:                  - replaced pT and pTLB with pTrack
  CHANGE:                  - removed unnecessary PC_SIM parts
  CHANGE:                  - realigned code in various places
  CHANGE:                 --- Added comments ---  uidv8777 [Jan 21, 2014 1:09:14 PM CET]
  CHANGE:                 Change Package : 207634:1 http://mks-psad:7002/im/viewissue?selection=207634
  CHANGE:                 Revision 1.7 2014/01/10 18:33:51CET Mutschler, Matthias (uidv7867) 
  CHANGE:                 First part of LRF on EVE (disabled)
  CHANGE:                 Merged LRF inputs into one struct
  CHANGE:                 Fixed exception handling of internal cali 
  CHANGE:                 Removed all tabs in the code and further clean-up
  CHANGE:                 --- Added comments ---  uidv7867 [Jan 10, 2014 6:33:51 PM CET]
  CHANGE:                 Change Package : 198642:7 http://mks-psad:7002/im/viewissue?selection=198642
  CHANGE:                 Revision 1.6 2013/11/21 14:15:26CET Manz, Alexander (uidv8777) 
  CHANGE:                 Fix: 
  CHANGE:                  - slightly changed parameter to reenable a somehow stable pair tracking
  CHANGE:                  - region selection for tracking fixed
  CHANGE:                  - minor bug in pseudo census code generation fixed
  CHANGE:                 Updates:
  CHANGE:                  - some minor cosmetic changes in tracking files
  CHANGE:                  - implemented additional visualizations for tracking (esp. pairs) and calibration
  CHANGE:                 --- Added comments ---  uidv8777 [Nov 21, 2013 2:15:27 PM CET]
  CHANGE:                 Change Package : 207634:1 http://mks-psad:7002/im/viewissue?selection=207634
  CHANGE:                 Revision 1.5 2012/10/18 17:56:00CEST Zechner, Stefan (uidt9253) 
  CHANGE:                 - allocation of array memory by array macro in order to realize a dedicated array boundary check mode
  CHANGE:                 --- Added comments ---  uidt9253 [Oct 18, 2012 5:56:00 PM CEST]
  CHANGE:                 Change Package : 118527:1 http://mks-psad:7002/im/viewissue?selection=118527
  CHANGE:                 Revision 1.4 2012/08/09 12:00:01CEST Godreau, Bertrand (uid28828) 
  CHANGE:                 Anayse Humic code review findings
  CHANGE:                 Set proper priorities
  CHANGE:                 --- Added comments ---  uid28828 [Aug 9, 2012 12:00:01 PM CEST]
  CHANGE:                 Change Package : 135871:2 http://mks-psad:7002/im/viewissue?selection=135871
  CHANGE:                 Revision 1.3 2012/07/23 12:57:55CEST Zechner, Stefan (uidt9253) 
  CHANGE:                 - code review comments from Humic
  CHANGE:                 --- Added comments ---  uidt9253 [Jul 23, 2012 12:57:55 PM CEST]
  CHANGE:                 Change Package : 94931:1 http://mks-psad:7002/im/viewissue?selection=94931
  CHANGE:                 Revision 1.2 2012/04/19 20:02:02CEST Godreau, Bertrand (uid28828) 
  CHANGE:                 integrate ttb18 for each track: time to border for a 18° angle
  CHANGE:                 ttb18 calculations are based on 3D estimations
  CHANGE:                 --- Added comments ---  uid28828 [Apr 19, 2012 8:02:03 PM CEST]
  CHANGE:                 Change Package : 101881:1 http://mks-psad:7002/im/viewissue?selection=101881
  CHANGE:                 Revision 1.1 2012/01/25 17:35:18CET Godreau, Bertrand (uid28828) 
  CHANGE:                 Initial revision
  CHANGE:                 Member added to project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/HLA_HeadLightAssist/04_Engineering/01_Source_Code/algo/hla/project.pj
**************************************************************************** */
#include "hla_trackmodel.h"


/* **************************************************************************** 
  Functionname:     HLATrackModelInit                                         */ /*!  
  Description:      

                    calculate landmark parametrisation (uw,vw) from first observation.

                    Point is seen as an infinite point with depth zinf.
                    his projection on camera is (uk,vk)

                    --------------------------------------
                    3D position of point in camera CS is:

                    xk = uk*zinf
                    yk = vk*zinf
                    zk = zinf

                    Xk = Uk*zinf

                    with Uk = [uk,vk,1]

                    --------------------------------------
                    cam to world transform:
                    Xw(t) = RK'*Xk(t) + TK

                    -----------------------------------------
                    landmark parametrisation for static
                    f = dw
                    xw(t-1) = 1/f
                    yw(t-1) = uw/f
                    zw(t-1) = vw/f

                    landmark parametrisation for dynamic
                    f = exp(odw)
                    xw(t-1) = 1/f
                    yw(t-1) = ouw/f
                    zw(t-1) = ovw/f


                    --------------------------------------
                    A(t) is defined
                    A(t) = RK'*Xk(t)

                    -------------------------------------
                    then considering os=0, ol=0, for dynamic and static

                    uw(t) = ouw(t) = b(t)/a(t)
                    uv(t) = ovw(t) = c(t)/a(t)

                    -------------------------------------
                    or 

                    A(t) = RK'*Xk(t)
                         = RK'*Uk(t)*zinf
                         = An(t)*zinf

                    with An(t) = RK'*Uk(t)

                    then

                    uw(t) = ouw(t) = bn(t)/an(t)
                    uv(t) = ovw(t) = cn(t)/an(t)

  @param[in]        
  @param[out]       
  @return           -
  @pre              -
  @post             -
  @author           Bertrand Godreau
**************************************************************************** */
/* ~CodeReview ~ID:a840ada49ab1a7214b58a780e9809e2d ~Reviewer:PC2357\dijkstg ~Date:11-7-2012 ~Priority:3 ~Comment:General: poorly documented function headers. */
/* ~CodeReview ~ID:c8c3c1b9897ce662967a2f5db0399f64 ~Reviewer:PC2357\dijkstg ~Date:11-7-2012 ~Priority:3 ~Comment:General: pointer parameters of exported functions are not checked for NULL. */
void HLATrackModelInit(       float32*                      puw,
                              float32*                      pvw,
                              float32*                      pfw,
                              float32*                      pHJ,
                              float32*                      pHC,
                        const float32                       uk,
                        const float32                       vk,
                        const float32                       fk,
                        const HLATracking3DDataRotations_t* pDataRotations
                      )
{
  float32 iz;
  float32 xiz2;
  float32 yiz2;
  /* ~CodeReview ~ID:b0487377483208b88345bd82673aa039 ~Reviewer:PC2357\dijkstg ~Date:11-7-2012 ~Priority:3 ~Comment:120938 Commented out code. Consider clean-up (general to this file). */
  /*float32 fiz2;*/

  float32 xw, yw, zw;
  float32 dxw, dyw, dzw;

  const float32* RK;
  const float32* dRK_dcy;
  const float32* dRK_dcp;
  const float32* dRK_dcr;
  
  float32 rk00, rk01, rk02;
  float32 rk10, rk11, rk12;
  float32 rk20, rk21, rk22;

  const float32* TK;
  float32 tkx, tky, tkz;

  /* get world to cam transform */
  RK = &pDataRotations->RK[0];
  dRK_dcy = &pDataRotations->dRK_dcy[0];
  dRK_dcp = &pDataRotations->dRK_dcp[0];
  dRK_dcr = &pDataRotations->dRK_dcr[0];
  rk00 = RK[0];       rk01 = RK[1];   rk02 = RK[2];
  rk10 = RK[3];       rk11 = RK[4];   rk12 = RK[5];
  rk20 = RK[6];       rk21 = RK[7];   rk22 = RK[8];

  TK = &pDataRotations->TK[0];
  tkx = TK[0];
  tky = TK[1];
  tkz = TK[2];

  /* get unscaled world coordinate centered on camera (same axis as camera) */
  xw = (rk00 * uk) + (rk10 * vk) + rk20 + (fk * tkx);
  yw = (rk01 * uk) + (rk11 * vk) + rk21 + (fk * tky);
  zw = (rk02 * uk) + (rk12 * vk) + rk22 + (fk * tkz);

  /* temporary values */
  /* ~CodeReview ~ID:c48d4aeac5ab86c19743b760d3a4dc74 ~Reviewer:PC2357\dijkstg ~Date:11-7-2012 ~Priority:3 ~Comment:Potential division by zero! */
  /* Godreau B, code review findings priority changed from 1 to 3 : it is not possible that the world depth init value of the point is 0 */
  iz = 1 / (xw);

  /* update state */
  *puw = (yw * iz);
  *pvw = (zw * iz);
  *pfw = (fk * iz);
  
  if(   (pHC != 0)
     || (pHJ != 0)
    )
  {
    /* temporary values */
    xiz2 = - ((*puw) * iz);
    yiz2 = - ((*pvw) * iz);
    /*fiz2 = - ((*pfw) * iz);*/

    /*------------------------------------------------------------------------------------*/
    /* X world derivates */
    if(pHC != NULL)
    {
      /* along cal YAW  */
/*
      dxw = (dRK_dcy[0]*uk) + (dRK_dcy[3]*vk) + dRK_dcy[6];
      dyw = (dRK_dcy[1]*uk) + (dRK_dcy[4]*vk) + dRK_dcy[7];
      dzw = (dRK_dcy[2]*uk) + (dRK_dcy[5]*vk) + dRK_dcy[8];
      
      pHC[0] = (dyw*iz) + (dxw*xiz2);
      pHC[3] = (dzw*iz) + (dxw*yiz2);
      pHC[6] = (dxw*fiz2);
*/
      dxw = (dRK_dcy[0]*uk) + (dRK_dcy[3]*vk) + dRK_dcy[6];
      dyw = (dRK_dcy[1]*uk) + (dRK_dcy[4]*vk) + dRK_dcy[7];
      
      pHC[0] = (dyw*iz) + (dxw*xiz2);

      /* along cal PITCH  */
/*
      dxw = (dRK_dcp[0]*uk) + (dRK_dcp[3]*vk) + (dRK_dcp[6]);
      dyw = (dRK_dcp[1]*uk) + (dRK_dcp[4]*vk) + (dRK_dcp[7]);
      dzw = (dRK_dcp[2]*uk) + (dRK_dcp[5]*vk) + (dRK_dcp[8]);

      pHC[1] = (dyw*iz) + (dxw*xiz2);
      pHC[4] = (dzw*iz) + (dxw*yiz2);
      pHC[7] = (dxw*fiz2);
*/
      dxw = (dRK_dcp[3]*vk) + (dRK_dcp[6]);
      dzw = (dRK_dcp[5]*vk) + (dRK_dcp[8]);

      pHC[4] = (dzw*iz) + (dxw*yiz2);

      /* along cal ROLL */
/*
      dxw = (dRK_dcr[0]*uk) + (dRK_dcr[3]*vk) + dRK_dcr[6];
      dyw = (dRK_dcr[1]*uk) + (dRK_dcr[4]*vk) + dRK_dcr[7];
      dzw = (dRK_dcr[2]*uk) + (dRK_dcr[5]*vk) + dRK_dcr[8];

      pHC[2] = (dyw*iz) + (dxw*xiz2);
      pHC[5] = (dzw*iz) + (dxw*yiz2);
      pHC[8] = (dxw*fiz2);
      */

      dxw = (dRK_dcr[0]*uk) + (dRK_dcr[3]*vk) + dRK_dcr[6];
      dyw = (dRK_dcr[1]*uk) + (dRK_dcr[4]*vk) + dRK_dcr[7];
      dzw = (dRK_dcr[2]*uk) + (dRK_dcr[5]*vk) + dRK_dcr[8];

      pHC[2] = (dyw*iz) + (dxw*xiz2);
      pHC[5] = (dzw*iz) + (dxw*yiz2);
    }

    /*------------------------------------------------------------------------------------------*/
    if(pHJ != NULL)
    {
      /* calculate dX/(uk)  */
      /*
      dxw = RK[0];
      dyw = RK[1];
      dzw = RK[2];

      pHJ[0] = (dyw*iz) + (dxw*xiz2);
      pHJ[3] = (dzw*iz) + (dxw*yiz2);
      pHJ[6] = (dxw*fiz2);
      */

      pHJ[0] = (rk01*iz) + (rk00*xiz2);

      /* calculate dX/(vk)  */
      /*
      dxw = rk10;
      dyw = rk11;
      dzw = rk12;

      pHJ[1] = (dyw*iz) + (dxw*xiz2);
      pHJ[4] = (dzw*iz) + (dxw*yiz2);
      pHJ[7] = (dxw*fiz2);
      */

      pHJ[4] = (rk12*iz) + (rk10*yiz2);

      /* calculate dX/(fk)  */
      /*
      dxw = (tkx);
      dyw = (tky);
      dzw = (tkz);

      pHJ[2] = (dyw*iz) + (dxw*xiz2);
      pHJ[5] = (dzw*iz) + (dxw*yiz2);
      pHJ[8] = (iz);     + (dxw*fiz2);
      */

      pHJ[2] = (tky*iz) + (tkx*xiz2);
      pHJ[5] = (tkz*iz) + (tkx*yiz2);
      pHJ[8] = (iz);
    }
  }
}

/* **************************************************************************** 
  Functionname:     HLATrackModelMeasurement                                         */ /*!  
  Description:      
  
                    -----------------------------------------
                    projection Xb(t) of 3D point in camera cs at time t Xk(t)
                      xb(t) = xk(t)/zk(t)
                      yb(t) = yk(t)/zk(t)

                    -----------------------------------------
                    world to cam transform at time t 
                      Xk(t) = RK*(Xw(t) - TK)

                    -----------------------------------------
                    interframe rotation and translation
                      Xw(t) = RE*(Xw(t-1) - RE)

                    -----------------------------------------
                    landmark parametrisation for static
                      f = dw
                      xw(t-1) = 1/f
                      yw(t-1) = uw/f
                      zw(t-1) = vw/f

                    landmark parametrisation for dynamic
                      f = exp(odw)
                      xw(t-1) = 1/f
                      yw(t-1) = ouw/f
                      zw(t-1) = ovw/f

                    -----------------------------------------
                    to sum up:
                      Xw(t-1) = A(t-1)/f
 
                    with for static:
                      a(t-1) = 1
                      b(t-1) = uw
                      c(t-1) = vw
                      and f = dw
                    
                    for dynamic:
                      a(t-1) = 1
                      b(t-1) = ouw
                      c(t-1) = ovw
                      and f = exp(odw)

                    -----------------------------------------
                    Measurement Equation development
                      Xk(t) = RK*(RE*(A(t-1)/f - RE) - TK)

                      Xk(t) = RK*(RE*A(t-1)/f + RE*(- RE) - TK)

                      Xk(t) = RK*RE*A(t-1)/f   +   RK*RE*(- RE)   -   RK*TK

                      Xk(t) = RA*A(t-1)/f   +   TA

                      Xk(t) = (RA*A(t-1)   +   f*TA) / f

                      Xk(t) = (Xkn(t)) / f

                    projection
                      xb(t) = xk(t)/zk(t)
                      yb(t) = yk(t)/zk(t)

                      xb(t) = xkn(t)/zkn(t)
                      yb(t) = ykn(t)/zkn(t)

                    -----------------------------------------
                    Final Measurement equation:
                      xb(t) = xkn(t)/zkn(t)
                      yb(t) = ykn(t)/zkn(t)

                    with
                      Xkn(t) = RA*A(t-1)   +   f*TA

                      RA = RK*RE
                      TA = RA*(- RE)   -   RK*TK

  @param[in]        
  @param[out]       
  @return           -
  @pre              -
  @post             -
  @author           Bertrand Godreau
**************************************************************************** */
void HLATrackModelMeasurement(      float32                       u,
                                    float32                       v,
                                    float32                       factor,
                                    float32                       dfactor_dsd,
                                    float32*                      xb,
                                    float32*                      yb,
                                    float32*                      pHC,
                                    float32*                      pHE,
                                    float32*                      pHJ,
                              const HLATracking3DDataRotations_t* pDataRotations
                             )
{
  float32  iz, xiz2, yiz2;

  float32  xk, yk, zk;
  float32  dxk, dyk, dzk;

  const float32* RA;
  const float32* dRA_dcy;
  const float32* dRA_dcp;
  const float32* dRA_dcr;
  const float32* dRA_dey;
  const float32* dRA_dep;
  const float32* dRA_der;

  float32 ra00, ra01, ra02;
  float32 ra10, ra11, ra12;
  float32 ra20, ra21, ra22;

  const float32* TA;
  const float32* dTA_dcy;
  const float32* dTA_dcp;
  const float32* dTA_dcr;
  /* const float32* dTA_dey; */
  const float32* dTA_dep;
  const float32* dTA_der;
  float32  ta0, ta1, ta2;

  /* get composition matrix */
  RA      = &pDataRotations->RA[0];
  dRA_dcy = &pDataRotations->dRA_dcy[0];
  dRA_dcp = &pDataRotations->dRA_dcp[0];
  dRA_dcr = &pDataRotations->dRA_dcr[0];
  dRA_dey = &pDataRotations->dRA_dey[0];
  dRA_dep = &pDataRotations->dRA_dep[0];
  dRA_der = &pDataRotations->dRA_der[0];
  ra00 = RA[0];   ra01 = RA[1];   ra02 = RA[2];
  ra10 = RA[3];   ra11 = RA[4];   ra12 = RA[5];
  ra20 = RA[6];   ra21 = RA[7];   ra22 = RA[8];

  /* get resulting translation */
  TA = &pDataRotations->TA[0];
  dTA_dcy = &pDataRotations->dTA_dcy[0];
  dTA_dcp = &pDataRotations->dTA_dcp[0];
  dTA_dcr = &pDataRotations->dTA_dcr[0];
  /* dTA_dey = pDataRotations->dTA_dey; */
  dTA_dep = &pDataRotations->dTA_dep[0];
  dTA_der = &pDataRotations->dTA_der[0];
  ta0 = TA[0];
  ta1 = TA[1];
  ta2 = TA[2];


  xk = ra00 + (ra01*u) + (ra02*v) + (factor*(ta0));
  yk = ra10 + (ra11*u) + (ra12*v) + (factor*(ta1));
  zk = ra20 + (ra21*u) + (ra22*v) + (factor*(ta2));
 
  /* temporary values */
  /* ~CodeReview ~ID:cccc62875b0e738f53d3b35dbb7e3910 ~Reviewer:PC2357\dijkstg ~Date:11-7-2012 ~Priority:3 ~Comment:Potential division by zero! */
  /* Godreau B, code review findings priority changed from 1 to 3 : it is not possible that the point depth value is 0 */
  iz = 1/zk;

  /* project on image plane */
  *xb = xk*iz;
  *yb = yk*iz;

  
  if(   (pHC != 0)
     || (pHE != 0)
     || (pHJ != 0)
    )
  {
    /* temporary values */
    xiz2 = - ((*xb) * iz);
    yiz2 = - ((*yb) * iz);

    if(pHC != NULL)
    {
      /*------------------------------------------------------------------------------------*/
      /* along cal YAW  */
      /*
      dxk = dRA_dcy[0] + (dRA_dcy[1]*u) + (dRA_dcy[2]*v) + (factor*(dTA_dcy[0]));
      dyk = dRA_dcy[3] + (dRA_dcy[4]*u) + (dRA_dcy[5]*v) + (factor*(dTA_dcy[1]));
      dzk = dRA_dcy[6] + (dRA_dcy[7]*u) + (dRA_dcy[8]*v) + (factor*(dTA_dcy[2]));

      pHC[0] = (dxk*iz) + (dzk*xiz2);
      pHC[3] = (dyk*iz) + (dzk*yiz2);
      */

      dxk = dRA_dcy[0] + (dRA_dcy[1]*u) + (dRA_dcy[2]*v) + (factor*(dTA_dcy[0]));
      dzk = dRA_dcy[6] + (dRA_dcy[7]*u) + (dRA_dcy[8]*v) + (factor*(dTA_dcy[2]));

      pHC[0] = (dxk*iz) + (dzk*xiz2);

      /*------------------------------------------------------------------------------------*/
      /* along cal PITCH  */
      /*
      dxk = dRA_dcp[0] + (dRA_dcp[1]*u) + (dRA_dcp[2]*v) + (factor*(dTA_dcp[0]));
      dyk = dRA_dcp[3] + (dRA_dcp[4]*u) + (dRA_dcp[5]*v) + (factor*(dTA_dcp[1]));
      dzk = dRA_dcp[6] + (dRA_dcp[7]*u) + (dRA_dcp[8]*v) + (factor*(dTA_dcp[2]));

      pHC[1] = dzk*xiz2;
      pHC[4] = (dyk*iz) + (dzk*yiz2);*/

      dyk = dRA_dcp[3] + (dRA_dcp[4]*u) + (dRA_dcp[5]*v) + (factor*(dTA_dcp[1]));
      dzk = dRA_dcp[6] + (dRA_dcp[7]*u) + (dRA_dcp[8]*v) + (factor*(dTA_dcp[2]));

      pHC[4] = (dyk*iz) + (dzk*yiz2);

      /*------------------------------------------------------------------------------------*/
      /* along cal ROLL  */
      /*
      dxk = dRA_dcr[0]*xw0 + (dRA_dcr[1]*yw0) + (dRA_dcr[2]*zw0) + (factor*(dTA_dcr[0]));
      dyk = dRA_dcr[3] + (dRA_dcr[4]*u) + (dRA_dcr[5]*v) + (factor*(dTA_dcr[1]));
      dzk = dRA_dcr[6] + (dRA_dcr[7]*u) + (dRA_dcr[8]*v) + (factor*(dTA_dcr[2]));

      pHC[2] = (dxk*iz) + (dzk*xiz2);
      pHC[5] = (dyk*iz) + (dzk*yiz2);
      */

      dxk = dRA_dcr[0] + (dRA_dcr[1]*u) + (dRA_dcr[2]*v) + (factor*(dTA_dcr[0]));
      dyk = dRA_dcr[3] + (dRA_dcr[4]*u) + (dRA_dcr[5]*v) + (factor*(dTA_dcr[1]));
      dzk = dRA_dcr[6] + (dRA_dcr[7]*u) + (dRA_dcr[8]*v) + (factor*(dTA_dcr[2]));

      pHC[2] = (dxk*iz) + (dzk*xiz2);
      pHC[5] = (dyk*iz) + (dzk*yiz2);
    }


    if(pHE != NULL)
    {
      /*------------------------------------------------------------------------------------*/
      /* along ego YAW  */
      /*
      dxk = dRA_dey[0] + (dRA_dey[1]*u) + (dRA_dey[2]*v) + (factor*(dTA_dey[0]));
      dyk = dRA_dey[3] + (dRA_dey[4]*u) + (dRA_dey[5]*v) + (factor*(dTA_dey[1]));
      dzk = dRA_dey[6] + (dRA_dey[7]*u) + (dRA_dey[8]*v) + (factor*(dTA_dey[2]));

      pHE[0] = (dxk*iz) + (dzk*xiz2);
      pHE[3] = (dyk*iz) + (dzk*yiz2);*/

      dxk = dRA_dey[0] + (dRA_dey[1]*u);
      dzk = dRA_dey[6] + (dRA_dey[7]*u);

      pHE[0] = (dxk*iz) + (dzk*xiz2);

      /*------------------------------------------------------------------------------------*/
      /* along ego PITCH */
      /*
      dxk = dRA_dep[0] + (dRA_dep[1]*u) + (dRA_dep[2]*v) + (factor*(dTA_dep[0]));
      dyk = dRA_dep[3] + (dRA_dep[4]*u) + (dRA_dep[5]*v) + (factor*(dTA_dep[1]));
      dzk = dRA_dep[6] + (dRA_dep[7]*u) + (dRA_dep[8]*v) + (factor*(dTA_dep[2]));

      pHE[1] = (dxk*iz) + (dzk*xiz2);
      pHE[4] = (dyk*iz) + (dzk*yiz2); 
      */

      dyk = dRA_dep[3] + (dRA_dep[4]*u) + (dRA_dep[5]*v) + (factor*(dTA_dep[1]));
      dzk = dRA_dep[6] + (dRA_dep[7]*u) + (dRA_dep[8]*v) + (factor*(dTA_dep[2]));

      pHE[4] = (dyk*iz) + (dzk*yiz2); 

      /*------------------------------------------------------------------------------------*/
      /* along ego ROLL */
      /*
      dxk = dRA_der[0]*xw0 + (dRA_der[1]*u) + (dRA_der[2]*v) + (factor*(dTA_der[0]));
      dyk = dRA_der[3] + (dRA_der[4]*u) + (dRA_der[5]*v) + (factor*(dTA_der[1]));
      dzk = dRA_der[6] + (dRA_der[7]*u) + (dRA_der[8]*v) + (factor*(dTA_der[2]));

      pHE[2] = (dxk*iz) + (dzk*xiz2);
      pHE[5] = (dyk*iz) + (dzk*yiz2); 
      */

      dyk = dRA_der[3] + (dRA_der[4]*u) + (dRA_der[5]*v) + (factor*(dTA_der[1]));
      dzk = dRA_der[6] + (dRA_der[7]*u) + (dRA_der[8]*v) + (factor*(dTA_der[2]));

      pHE[5] = (dyk*iz) + (dzk*yiz2); 
    }


    if(pHJ != NULL)
    {
      /*------------------------------------------------------------------------------------------*/
      /* along u  */
      pHJ[0] = (ra01*iz) + (ra21*xiz2);
/*      pHJ[3] = (ra11*iz) + (ra21*xiz2);*/
  
      /*------------------------------------------------------------------------------------------*/
      /* along v  */
      /*pHJ[1] = (ra02*iz) + (ra22*yiz2);*/
      pHJ[4] = (ra12*iz) + (ra22*yiz2);
  
      /*------------------------------------------------------------------------------------------*/
      /* along sd */
      pHJ[2] = dfactor_dsd*((ta0*iz) + (ta2*xiz2));
      pHJ[5] = dfactor_dsd*((ta1*iz) + (ta2*yiz2));
    }
  }
}

/* **************************************************************************** 
  Functionname:     HLATrackModelMapUpdate                                         */ /*!  
  Description:      

                    compute landmark state (uw,vw,dw) in the current coorinate system
                    depending on:
                    - previous landmark state (uw(t-1),vw(t-1),dw(t-1))
                    - interframe motion


                    -----------------------------------------
                    interframe rotation and translation
                    Xw(t) = RE*(Xw(t-1) - RE)

                    -----------------------------------------
                    landmark parametrisation for static at (t-1)
                    f(t-1) = dw(t-1)
                    xw(t-1) = 1/f(t-1)
                    yw(t-1) = uw(t-1)/f(t-1)
                    zw(t-1) = vw(t-1)/f(t-1)

                    -----------------------------------------
                    landmark parametrisation for static at (t)
                    xw(t) = 1/dw(t)
                    yw(t) = uw(t)/dw(t)
                    zw(t) = vw(t)/dw(t)


                    -----------------------------------------
                    to sum up:
                    Xw(t-1) = A(t-1)/f(t-1)
 
                    with for static:
                    a(t-1) = 1
                    b(t-1) = uw(t-1)
                    c(t-1) = vw(t-1)
                    and f(t-1) = dw(t-1)

                    Xw(t) = A(t)
 
                    with for static:
                    a(t) = 1/dw(t)
                    b(t) = uw(t)/dw(t)
                    c(t) = vw(t)/dw(t)


                    -----------------------------------------
                    developement of interframe rotation and translation
                    Xw(t) = RE*(Xw(t-1) - RE)

                    A(t) = RE*(A(t-1)/f(t-1) - RE)


                    A(t) = RE*A(t-1)/f(t-1) + RE*(- RE)

                    A(t) = (RE*A(t-1) + f(t-1)*TD)/f(t-1)
                    A(t) = (An(t))/f(t-1)


                    -----------------------------------------
                    final equation
                    dw(t) = f(t-1)/an(t)
                    uw(t) = bn(t)/an(t)
                    vw(t) = cn(t)/an(t)

                    with An(t) = RE*A(t-1) + f(t-1)*TD

                    and TD = RE*(- RE)

  @param[in]        
  @param[out]       
  @return           -
  @pre              -
  @post             -
  @author           Bertrand Godreau
**************************************************************************** */
void HLATrackModelMapUpdate(      float32                       uw_in,
                                  float32                       vw_in,
                                  float32                       dw_in,
                                  float32*                      puw_out,
                                  float32*                      pvw_out,
                                  float32*                      pdw_out,
                                  float32*                      pHE,
                                  float32*                      pHJ,
                            const HLATracking3DDataRotations_t* pDataRotations
                           )
{
  float32 iz;
  float32 xiz2;
  float32 yiz2;
  float32 izw2;

  const float32* RE;
  const float32* dRE_dey;
  const float32* dRE_dep;
  const float32* dRE_der;

  float32 re00, re01, re02;
  float32 re10, re11, re12;
  float32 re20, re21, re22;

  const float32* VE;
  const float32* dVE_dep;
  const float32* dVE_der;
  float32  ve0, ve1, ve2;

  float32  xw,yw,zw;
  float32  dxw, dyw, dzw;

  float32 factor;
  float32 dfactor_dsd;

  RE = &pDataRotations->RE[0];
  dRE_dey = &pDataRotations->dRE_dey[0];
  dRE_dep = &pDataRotations->dRE_dep[0];
  dRE_der = &pDataRotations->dRE_der[0];

  VE = &pDataRotations->VE[0];
  dVE_dep = &pDataRotations->dVE_dep[0];
  dVE_der = &pDataRotations->dVE_der[0];

  /* get factor */
  factor = dw_in;
  dfactor_dsd = 1;

  /* calculate vehicle rotation matrix: Rv */
  re00 = RE[0];       re01 = RE[1];   re02 = RE[2];
  re10 = RE[3];       re11 = RE[4];   re12 = RE[5];
  re20 = RE[6];       re21 = RE[7];   re22 = RE[8];

  /* get resultant translation */
  ve0 = VE[0];
  ve1 = VE[1];
  ve2 = VE[2];

  /* update xw */
  xw = re00 + (re01*uw_in) + (re02*vw_in) + (factor*(ve0));
  yw = re10 + (re11*uw_in) + (re12*vw_in) + (factor*(ve1));
  zw = re20 + (re21*uw_in) + (re22*vw_in) + (factor*(ve2));

  /* temporary values */
  /* ~CodeReview ~ID:1e7782580008b279bd7129eade31bfa8 ~Reviewer:PC2357\dijkstg ~Date:11-7-2012 ~Priority:3 ~Comment:Potential division by zero! */
  /* Godreau B, code review findings priority changed from 1 to 3 : it is not possible that the point depth value is 0 */
  iz = 1/(xw);

  /* update state */
  *puw_out = yw*iz;
  *pvw_out = zw*iz;
  *pdw_out = dw_in*iz;

  if(   (pHE != 0)
     && (pHJ != 0)
    )
  {
    /* temporary values */
    xiz2 = - ((*puw_out) * iz);
    yiz2 = - ((*pvw_out) * iz);
    izw2 = - ((dw_in*iz)*iz);


    /*------------------------------------------------------------------------------------*/
    /* X world derivates */

    /* along ego YAW  */
    /*dxw = dRE_dey[0] + (dRE_dey[1]*uw_in) + (factor*(dVE_dey[0]));
    dyw = dRE_dey[3] + (dRE_dey[4]*uw_in) + (factor*(dVE_dey[1]));
    dzw = dRE_dey[6] + (dRE_dey[7]*uw_in) + (factor*(dVE_dey[2]));

    pHE[0] = (dyw*iz) + (dxw*xiz2);
    pHE[3] = (dzw*iz) + (dxw*yiz2);
     pHE[6] = dxw*izw2;*/

    dxw = dRE_dey[0] + (dRE_dey[1]*uw_in);
    dyw = dRE_dey[3] + (dRE_dey[4]*uw_in);

    pHE[0] = (dyw*iz) + (dxw*xiz2);

    /* along ego PITCH */
    /*
    dxw = (dRE_dep[0]) + (dRE_dep[1]*uw_in) + (dRE_dep[2]*vw_in) + (factor*(dVE_dep[0]));
    dyw = (dRE_dep[3]) + (dRE_dep[4]*uw_in) + (dRE_dep[5]*vw_in) + (factor*(dVE_dep[1]));
    dzw = (dRE_dep[6]) + (dRE_dep[7]*uw_in) + (dRE_dep[8]*vw_in) + (factor*(dVE_dep[2]));

    pHE[1] = (dyw*iz) + (dxw*xiz2);
    pHE[4] = (dzw*iz) + (dxw*yiz2);
    pHE[7] = dxw*izw2;
    */

    dxw = (dRE_dep[0]) + (dRE_dep[1]*uw_in) + (dRE_dep[2]*vw_in) + (factor*(dVE_dep[0]));
    dzw = (dRE_dep[6]) + (dRE_dep[7]*uw_in) + (dRE_dep[8]*vw_in) + (factor*(dVE_dep[2]));

    pHE[4] = (dzw*iz) + (dxw*yiz2);
    
    /* along ego ROLL */
    /*
    dxw = dRE_der[0] + (dRE_der[1]*uw_in) + (dRE_der[2]*vw_in) + (factor*(dVE_der[0]));
    dyw = dRE_der[3] + (dRE_der[4]*uw_in) + (dRE_der[5]*vw_in) + (factor*(dVE_der[1]));
    dzw = dRE_der[6] + (dRE_der[7]*uw_in) + (dRE_der[8]*vw_in) + (factor*(dVE_der[2]));

    pHE[2] = (dyw*iz) + ((dxw*xiz2);
    pHE[5] = (dzw*iz) + (dxw*yiz2);
    pHE[8] = dxw*izw2;
    */

    dzw = dRE_der[6] + (dRE_der[7]*uw_in) + (dRE_der[8]*vw_in) + (factor*(dVE_der[2]));

    pHE[5] = dzw*iz;

    /*------------------------------------------------------------------------------------------*/
    /* calculate dX/(u)  */
    /*dxw = re01;
    dyw = re11;
    dzw = re21;

    pHJ[0] = (dyw*iz) + (dxw*xiz2);
    pHJ[3] = (dzw*iz) + (dxw*yiz2);
    pHJ[6] = dxw*izw2;*/

    pHJ[0] = (re11*iz) + (re01*xiz2);

    /* calculate dX/(v)  */
    /*dxw = re02;
    dyw = re12;
    dzw = re22;

    pHJ[1] = (dyw*iz) + (dxw*xiz2);
    pHJ[4] = (dzw*iz) + (dxw*yiz2);
    pHJ[7] = dxw*izw2;*/

    pHJ[4] = (re22*iz) + (re02*yiz2);

    /* calculate dX/(sd)  */
    dxw = (dfactor_dsd*(ve0));
    dyw = (dfactor_dsd*(ve1));
    dzw = (dfactor_dsd*(ve2));

    pHJ[2] = (dyw*iz) + (dxw*xiz2);
    pHJ[5] = (dzw*iz) + (dxw*yiz2);
    pHJ[8] = iz + (dxw*izw2);
  }
}


/* **************************************************************************** 
  Functionname:     HLATrackModelWorldToCam                                         */ /*!  
  Description:      
                    
  @param[in]        
  @param[out]       
  @return           -
  @pre              -
  @post             -
  @author           Bertrand Godreau
**************************************************************************** */
void HLATrackModelWorldToCam(       float32*                      puk,
                                    float32*                      pvk,
                              const float32                       uw,
                              const float32                       vw,
                              const float32                       factor,
                              const HLATracking3DDataRotations_t* pDataRotations
                            )
{
  /* cam to world transfrom */
  const float32* RK;
  const float32* VK;

  /* camera coordinates */
  float32 xk,yk,zk;

  /* temp value */
  float32 izk;

  /* get world to cam transform */
  RK = &pDataRotations->RK[0];
  VK = &pDataRotations->VK[0];

  /* point camera coordinates */
  xk = RK[0] + (RK[1]*uw) + (RK[2]*vw) + (factor*VK[0]);
  yk = RK[3] + (RK[4]*uw) + (RK[5]*vw) + (factor*VK[1]);
  zk = RK[6] + (RK[7]*uw) + (RK[8]*vw) + (factor*VK[2]);

  /* inverse depth */
  /* ~CodeReview ~ID:ab775c81c8eac44744b4c229317772e1 ~Reviewer:PC2357\dijkstg ~Date:11-7-2012 ~Priority:3 ~Comment:Potential division by zero! */
  /* Godreau B, code review findings priority changed from 1 to 3 : it is not possible that the point depth value is 0 */
  izk = 1/zk;

  /* project on image plane */
  *puk = xk*izk;
  *pvk = yk*izk;
}


/* **************************************************************************** 
  Functionname:     HLATrackModelTTB                                */ /*!  
  Description:      


                    -------------------------------------
                    interframe world transform
                    Xw(t) = RE*(Xw(t-1) - RE)

fB*                   :      [ cos(y)*cos(z)                       ] [ cos(y)*sin(z)                       ] [-sin(y)         ]
fB*                   : RE = [-cos(x)*sin(z) + sin(x)*sin(y)*cos(z)] [ cos(x)*cos(z) + sin(x)*sin(y)*sin(z)] [ sin(x)*cos(y)  ]
fB*                   :      [ sin(x)*sin(z) + cos(x)*sin(y)*cos(z)] [-sin(x)*cos(z) + cos(x)*sin(y)*sin(z)] [ cos(x)*cos(y)  ]

                      x = interframe world roll   = ego_roll                  = er
                      y = interframe world pitch  = ego_pitch                 = ep
                      z = interframe world yaw    = ego_yaw  =  yaw_rate*dt   = ey

fB*                   :      [ cosep*cosey                    ] [ cosep*siney                    ] [-sinep        ]
fB*                   : RE = [-coser*siney + siner*sinep*cosey] [ coser*cosey + siner*sinep*siney] [ siner*cosep  ]
fB*                   :      [ siner*siney + coser*sinep*cosey] [-siner*cosey + coser*sinep*siney] [ coser*cosep  ]

                            [ ego_length*cosey ]
                      TE =  [ ego_length*siney ]
                            [ 0                   ]
  
                      ego_length = speed*dt + acc*(dt²/2)
                      

                    Xw(t) = RE*(Xw(t-1) - TE)

fB*                   :      [  cosey ] [ siney ] [ 0 ]
fB*                   : RE = [ -siney ] [ cosey ] [ 0 ]
fB*                   :      [    0   ] [   0   ] [ 1 ]

                            [ ego_length*cosey ]
                      TE =  [ ego_length*siney ]
                            [ 0                   ]
  
                      ego_length = speed*dt + acc*(dt²/2)

  
                    Xw(t) = RE*(Xw(t-1) - TE)

fB*                   :      [  cos(yr*dt) ] [ sin(yr*dt) ] [ 0 ]
fB*                   : RE = [ -sin(yr*dt) ] [ cos(yr*dt) ] [ 0 ]
fB*                   :      [    0        ] [   0        ] [ 1 ]

                            [ (sp*dt)*cos(yr*dt) ]
                      TE =  [ (sp*dt)*sin(yr*dt) ]
                            [ 0                  ]
                            



                    we have to find time ttb such as:

                    xw(ttb) =   cos(yr*ttb)*( (xw + os*ttb) - (sp*ttb)*cos(yr*ttb)) + sin(yr*ttb)*( (yw + ol*ttb) - (sp*ttb)*sin(yr*ttb))
                    yw(ttb) = - sin(yr*ttb)*( (xw + os*ttb) - (sp*ttb)*cos(yr*ttb)) + cos(yr*ttb)*( (yw + ol*ttb) - (sp*ttb)*sin(yr*ttb))

                    with yw(ttb)/xw(ttb) = tan(a)     ( a = alpha_ttb = 18° )


                    simplify xw expression:
                  
                    xw(ttb) =   cos(yr*ttb)*( (xw + os*ttb) - (sp*ttb)*cos(yr*ttb)) 
                            +   sin(yr*ttb)*( (yw + ol*ttb) - (sp*ttb)*sin(yr*ttb))

                    xw(ttb) =   cos(yr*ttb)*(xw + os*ttb) - (sp*ttb)*cos²(yr*ttb)
                            +   sin(yr*ttb)*(yw + ol*ttb) - (sp*ttb)*sin²(yr*ttb)


                    xw(ttb) =   cos(yr*ttb)*(xw + os*ttb) 
                            +   sin(yr*ttb)*(yw + ol*ttb) 
                            -   (sp*ttb)*cos²(yr*ttb)
                            -   (sp*ttb)*sin²(yr*ttb)

                    xw(ttb) =   cos(yr*ttb)*(xw + os*ttb) 
                            +   sin(yr*ttb)*(yw + ol*ttb) 
                            -   (sp*ttb)*(cos²(yr*ttb) + sin²(yr*ttb))


                    xw(ttb) =   cos(yr*ttb)*(xw + os*ttb) 
                            +   sin(yr*ttb)*(yw + ol*ttb) 
                            -   (sp*ttb)


                    simplify yw expression:

                    yw(ttb) = - sin(yr*ttb)*( (xw + os*ttb) - (sp*ttb)*cos(yr*ttb)) 
                              + cos(yr*ttb)*( (yw + ol*ttb) - (sp*ttb)*sin(yr*ttb))

                    yw(ttb) = - sin(yr*ttb)*(xw + os*ttb) + sin(yr*ttb)*(sp*ttb)*cos(yr*ttb)
                              + cos(yr*ttb)*(yw + ol*ttb) - cos(yr*ttb)*(sp*ttb)*sin(yr*ttb)

                    yw(ttb) = - sin(yr*ttb)*(xw + os*ttb)
                              + cos(yr*ttb)*(yw + ol*ttb)


                    1st order approximation xw:

                    xw(ttb) =   cos(yr*ttb)*(xw + os*ttb) 
                            +   sin(yr*ttb)*(yw + ol*ttb) 
                            -   (sp*ttb)

                    xw(ttb) =   (xw + os*ttb) + (yr*ttb)*(yw + ol*ttb) - (sp*ttb)

                    xw(ttb) =   xw + os*ttb + (yr*ttb)*(yw) + (yr*ttb)*(ol*ttb) - (sp*ttb)

                    xw(ttb) =   xw + (os + yr*yw - sp)*ttb + (yr*ol)*ttb²

                    considering xw(ttb) >> (yr*ol)*ttb²

                    xw(ttb) =   xw + (os + yr*yw - sp)*ttb 


                    1st order approximation yw:

                    yw(ttb) = - sin(yr*ttb)*(xw + os*ttb)
                              + cos(yr*ttb)*(yw + ol*ttb)

                    yw(ttb) = - (yr*ttb)*(xw + os*ttb) + (yw + ol*ttb)

                    yw(ttb) =   yw + (ol - yr*xw)*ttb - (yr*os)*ttb²

                    considering yw(ttb) >> (yr*os)*ttb²

                    yw(ttb) =   yw + (ol - yr*xw)*ttb


                    tan(a) calculation:

                    tan(a) = yw(ttb)/xw(ttb)

                    xw(ttb)*tan(a) - yw(ttb) = 0


                    xw*tan(a) + (os + yr*yw - sp)*tan(a)*ttb - yw - (ol - yr*xw)*ttb  =  0


                    (xw*tan(a) - yw) + ((os + yr*yw - sp)*tan(a) - (ol - yr*xw))*ttb  =  0


                                  - (xw*tan(a) - yw) 
                    ttb = -----------------------------------------
                          ((os + yr*yw - sp)*tan(a) - (ol - yr*xw))



                                     xw*tan(a) - yw
                    ttb = -----------------------------------------
                          (sp - os - yr*yw)*tan(a) + ol - yr*xw



                    !!!!!!!!!!!!!!!!RQ 1!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!:
                    if a=+-90.0°  (ttb==ttc)

                                     xw
                    ttb = -------------------------
                              (sp - os - yr*yw)
                    
                    if static (os=0, ol=0)

                                     xw
                    ttb = -------------------------
                               (sp - yr*yw)

                    if straight road (yr=0)

                                     xw
                    ttb = -------------------------
                                    (sp)


                    !!!!!!!!!!!!!!!!RQ 2!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
                    if vehcile at stand still (sp=0 and yr=0)


                                     xw*tan(a) - yw
                    ttb = -----------------------------------------
                                  (-os)*tan(a) + ol


                    !!!!!!!!!!!!!!!!RQ 3!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
                    
                    for infinite points : 

                                     tan(a) - yw/xw
                    ttb = -----------------------------------------
                          (sp - os - yr*yw)*tan(a)/xw + ol/xw - yr


                                     tan(a) - yw/xw
                    ttb = -----------------------------------------
                          ((sp - os)/xw - yr*yw/xw)*tan(a) + ol/xw - yr


                                     tan(a) - uw
                    ttb = -----------------------------------------
                                 - yr*tan(a)*uw - yr



                    !!!!!!!!!!!!!!!!RQ 4!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
                    
                                     xw*tan(a) - yw
                    ttb = -----------------------------------------
                          (sp - os - yr*yw)*tan(a) + ol - yr*xw



                                     dw*xw*tan(a) - dw*yw
                    ttb = -----------------------------------------
                          (dw*(sp - os) - yr*dw*yw)*tan(a) + dw*ol - yr*dw*xw

                    xw = 1/dw      --->   xw*dw = 1
                    yw = uw/dw    --->   yw*dw = uw



                                     tan(a) - uw
                    ttb = -----------------------------------------
                          (dw*(sp - os) - yr*uw)*tan(a) + (dw*ol - yr)


                                  tan(a) - uw
                    ttb(a) =   -------------------
                                 fa*tan(a) + fb


                   with fa = dw*(sp - os) - yr*uw
                        fb = (dw*ol - yr)


                                  - tan(a) - uw
                    ttb(-a) =   -------------------
                                 - fa*tan(a) + fb
  @param[in]        

  @return           
  @pre              -
  @post             -
  @author           Bertrand Godreau
**************************************************************************** */
void HLATrackModelTTB(      float32*  pTTBHor,
                      const float32   uw,
                      const float32   dw,
                      const float32   os,
                      const float32   ol,
                      const float32   sp,
                      const float32   yr,
                      const float32   tana,
                      const float32   ttbmax
                     )
{
  /* ttb data */
  float32 fa, fb;
  float32 ttbright, ttbleft;
  float32 den;

  /* calculate fa = dw*(sp - os) - yr*uw */
  fa = (dw*(sp - os)) - (yr*uw);

  /* calculate fb = (dw*ol - yr) */
  fb = (dw*ol) - yr;

  /* calculate ttbleft (a>0) */
  den = (fa*tana) + fb;

  if(CML_f_IsNonZero(den))
  {
    if(uw>tana)
    {
      ttbleft = 0.0f;
    }
    else
    {
      ttbleft = CML_f_Min( (tana - uw)/den, ttbmax);

      if(ttbleft<0)
      {
        ttbleft = ttbmax;
      }
    }
  }
  else
  {
    ttbleft = ttbmax;
  }

  /* calculate ttbright (a<0) */
  den = - (fa*tana) + fb;

  if(CML_f_IsNonZero(den))
  {
    if(uw<(-tana))
    {
      ttbright = 0.0f;
    }
    else
    {
      ttbright = CML_f_Min((- tana - uw)/den, ttbmax);

      if(ttbright<0)
      {
        ttbright = ttbmax;
      }
    }
  }
  else
  {
    ttbright = ttbmax;
  }

  /* choose between left and right ttb */  
  *pTTBHor = CML_f_Min(ttbleft, ttbright);
}
