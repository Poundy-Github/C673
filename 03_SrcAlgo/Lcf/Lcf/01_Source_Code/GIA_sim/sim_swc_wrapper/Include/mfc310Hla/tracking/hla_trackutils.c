/*! \file **********************************************************************

  COMPANY:                Continental AG, BU PSAD, Segment ADAS (A.D.C. GmbH)

  PROJECT:                MFC300

  CPU:                    FreeScale Gold Dust

  COMPONENT:              HLA

  MODULNAME:              hla_trackutils.c

  DESCRIPTION:            Definition file for head light assist.

  AUTHOR:                 Bertrand Godreau

  CREATION DATE:          2012-01-17

  VERSION:                $Revision: 1.1 $

  CHANGES:                

  ---*/ /*---
  CHANGE:                 $Log: hla_trackutils.c  $
  CHANGE:                 Revision 1.1 2021/12/13 17:28:13CET Wang, David (Wangd3) 
  CHANGE:                 Initial revision
  CHANGE:                 Member added to project /ADAS/Projects/MFC5xx/MFC5J3/06_Algorithm/DPU/04_Engineering/01_Source_Code/GIA_sim/sim_swc_wrapper/Include/mfc310Hla/tracking/project.pj
  CHANGE:                 Revision 1.0 2017/03/03 10:39:57CET Sorge, Sven (uidg3181) 
  CHANGE:                 Initial revision
  CHANGE:                 Member added to project /ADAS/SW/Integration/06_Simulation_Components/GIA_GenericInterfaceAdapter/04_Engineering/03_Workspace/Component_Workspace/GIA_sim/sim_swc_wrapper/Include/mfc310Hla/tracking/project.pj
  CHANGE:                 Revision 1.1 2014/04/17 16:06:14CEST Sorge, Sven (uidg3181) 
  CHANGE:                 Initial revision
  CHANGE:                 Member added to project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/ETK_EngineeringToolKit/04_Engineering/GIA_GenericInterfaceAdapter/04_Engineering/03_Workspace/algo/gia_sim/wrapper/Include/mfc310Hla/tracking/project.pj
  CHANGE:                 Revision 1.10 2014/03/25 18:44:28CET Mutschler, Matthias (uidv7867) 
  CHANGE:                 Member moved from hla_trackutils.c in project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/HLA_HeadLightAssist/04_Engineering/01_Source_Code/algo/hla/project.pj to hla_trackutils.c in project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/HLA_HeadLightAssist/04_Engineering/01_Source_Code/algo/hla/tracking/project.pj.
  CHANGE:                 Revision 1.9 2014/03/19 16:30:14CET Mutschler, Matthias (uidv7867) 
  CHANGE:                 Replace macros from glob_defs.h by the ones defined in cml_ext.h
  CHANGE:                 Fixed hlar input adapter for old recordings (headlamp type)
  CHANGE:                 Clean-up of no longer needed files in simulation
  CHANGE:                 --- Added comments ---  uidv7867 [Mar 19, 2014 4:30:14 PM CET]
  CHANGE:                 Change Package : 225959:1 http://mks-psad:7002/im/viewissue?selection=225959
  CHANGE:                 Revision 1.8 2014/01/24 13:37:57CET Manz, Alexander (uidv8777) 
  CHANGE:                 Update:
  CHANGE:                  - adapt to HLA coding guidelines (more)
  CHANGE:                 --- Added comments ---  uidv8777 [Jan 24, 2014 1:37:58 PM CET]
  CHANGE:                 Change Package : 207634:1 http://mks-psad:7002/im/viewissue?selection=207634
  CHANGE:                 Revision 1.7 2014/01/24 09:35:03CET Glebov, Roman (uidg4759) 
  CHANGE:                 switched from F32_IS_.* from global_defs.h to HLA_F32_IS_.* from hla_defs.h. 
  CHANGE:                 These are custom versions, which use much smaller Epsilon delta for comparison with 0
  CHANGE:                 --- Added comments ---  uidg4759 [Jan 24, 2014 9:35:04 AM CET]
  CHANGE:                 Change Package : 193435:4 http://mks-psad:7002/im/viewissue?selection=193435
  CHANGE:                 Revision 1.6 2014/01/21 13:58:23CET Glebov, Roman (uidg4759) 
  CHANGE:                 fixed unsafe comparison of float with 0
  CHANGE:                 --- Added comments ---  uidg4759 [Jan 21, 2014 1:58:24 PM CET]
  CHANGE:                 Change Package : 193435:4 http://mks-psad:7002/im/viewissue?selection=193435
  CHANGE:                 Revision 1.5 2014/01/21 13:09:21CET Manz, Alexander (uidv8777) 
  CHANGE:                 Cosmetic changes:
  CHANGE:                  - replaced pT and pTLB with pTrack
  CHANGE:                  - removed unnecessary PC_SIM parts
  CHANGE:                  - realigned code in various places
  CHANGE:                 --- Added comments ---  uidv8777 [Jan 21, 2014 1:09:21 PM CET]
  CHANGE:                 Change Package : 207634:1 http://mks-psad:7002/im/viewissue?selection=207634
  CHANGE:                 Revision 1.4 2014/01/10 18:33:14CET Mutschler, Matthias (uidv7867) 
  CHANGE:                 First part of LRF on EVE (disabled)
  CHANGE:                 Merged LRF inputs into one struct
  CHANGE:                 Fixed exception handling of internal cali 
  CHANGE:                 Removed all tabs in the code and further clean-up
  CHANGE:                 --- Added comments ---  uidv7867 [Jan 10, 2014 6:33:15 PM CET]
  CHANGE:                 Change Package : 198642:7 http://mks-psad:7002/im/viewissue?selection=198642
  CHANGE:                 Revision 1.3 2012/07/23 12:58:08CEST Zechner, Stefan (uidt9253) 
  CHANGE:                 - code review comments from Humic
  CHANGE:                 --- Added comments ---  uidt9253 [Jul 23, 2012 12:58:08 PM CEST]
  CHANGE:                 Change Package : 94931:1 http://mks-psad:7002/im/viewissue?selection=94931
  CHANGE:                 Revision 1.2 2012/03/27 16:41:33CEST Godreau, Bertrand (uid28828) 
  CHANGE:                 Findings for code review tracking PART 1  (Algo review partner, Stefan Zechner)
  CHANGE:                 --- Added comments ---  uid28828 [Mar 27, 2012 4:41:33 PM CEST]
  CHANGE:                 Change Package : 94916:1 http://mks-psad:7002/im/viewissue?selection=94916
  CHANGE:                 Revision 1.1 2012/01/25 17:36:26CET Godreau, Bertrand (uid28828) 
  CHANGE:                 Initial revision
  CHANGE:                 Member added to project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/HLA_HeadLightAssist/04_Engineering/01_Source_Code/algo/hla/project.pj
**************************************************************************** */
#include "hla_trackutils.h"



/* **************************************************************************** 
  Functionname:     HLATrackUtilsAddCoupleToList                     */ /*!  
  Description:      Add a light to the possible association list of the track.
                    Sort them from the closest light to prediction to the further one.

  @param[in]        

  @return           
  @pre              -
  @post             -
  @author           Bertrand Godreau
**************************************************************************** */
void HLATrackUtilsAddCoupleToList(      HLACoupleData_t*  pAssocDataList,
                                        uint32*           n,
                                  const HLACoupleData_t*  pAssocData2insert,
                                  const uint32            maxTableSize
                                 )
{
  uint16 dist2insert;

  HLACoupleData_t* pADi;
  HLACoupleData_t* pADinsert;
  HLACoupleData_t* pADEnd;

  pADEnd = pAssocDataList + maxTableSize;
  pADinsert = pAssocDataList + (*n);
  pADi = pADinsert - 1;

  dist2insert = pAssocData2insert->ui_dist;

  /* <ln_offset:+1 MISRA Rule  17.2, 17.3: reviewer name: Bertrand Godreau date: 09.05.2011 reason: pointer comparison wanted to save runtime */
  while(pADi >= pAssocDataList)
  {
    if(dist2insert < pADi->ui_dist)
    {
      pADinsert = pADi;
      /* <ln_offset:+1 MISRA Rule  17.2, 17.3: reviewer name: Bertrand Godreau date: 09.05.2011 reason: pointer comparison wanted to save runtime */
      if( (pADi + 1) < pADEnd )
      { 
        *(pADi + 1) = (*pADi);
      }
    }
    else
    {
      break;
    }
    pADi--;
  }

  /* <ln_offset:+1 MISRA Rule  17.2, 17.3: reviewer name: Bertrand Godreau date: 09.05.2011 reason: pointer comparison wanted to save runtime */
  if(pADinsert < pADEnd)
  {
    *pADinsert = *pAssocData2insert;

    if( (*n) < maxTableSize )
    {
      (*n) = (*n) + 1;
    }
    else
    {
      /* Do nothing */
    }
  }
}


/* **************************************************************************** 
  Functionname:     HLATrackUtilsInverseInnovation
  Description:      

                    inverse 2x2 matrix

 
  @param[in]        
  @param[out]       
  @return           -
  @pre              -
  @post             -
  @author           Bertrand Godreau
****************************************************************************/
boolean HLATrackUtilsInverseInnovation( float32   sxx,
                                        float32   syy,
                                        float32   sxy,
                                        float32*  isxx,
                                        float32*  isyy,
                                        float32*  isxy
                                       )
{
  boolean bRet;
  float32 det,idet;

  bRet = b_FALSE;

  /* calculate innovation matrix inverse Sinv = inv(S)*/
  det = (sxx * syy) - (sxy * sxy);

  if(CML_f_IsNonZero(det))
  {
    idet = 1 / det;
    *isxx =   syy * idet;
    *isxy = - sxy * idet;
    *isyy =   sxx * idet;

    bRet = b_TRUE;
  }

  return(bRet);
}

/* **************************************************************************** 
  Functionname:     HLATrackUtilsMaha11
  Description:      

                    Mahalanobis distance (1 dimension)
 

  @param[in]        
  @param[out]       
  @return           -
  @pre              -
  @post             -
  @author           Bertrand Godreau
****************************************************************************/
void HLATrackUtilsMaha11( float32*  pdist,
                          float32   dx,
                          float32   sxx
                        )
{
  if(CML_f_IsNonZero(sxx))
  {
    *pdist = (dx * dx) / sxx;
  }
  else
  {
    *pdist = -1;
  }
}

/* **************************************************************************** 
  Functionname:     HLATrackUtilsMaha22                                       
  Description:      

                    Mahalanobis distance (2 dimensions)
 

  @param[in]        
  @param[out]       
  @return           -
  @pre              -
  @post             -
  @author           Bertrand Godreau
****************************************************************************/
void HLATrackUtilsMaha22( float32*  pdist,
                          float32   dx,
                          float32   dy,
                          float32   sxx,
                          float32   syy,
                          float32   sxy
                        )
{
  float32 det;

  /* calculate innovation matrix inverse Sinv = inv(S)*/
  det = (sxx * syy) - (sxy * sxy);

  if(CML_f_IsNonZero(det))
  {
    (*pdist) =  dx * dx * syy;
    (*pdist) += dy * dy * sxx;

    (*pdist) -= dx * dy * (sxy + sxy);

    (*pdist) = (*pdist) / det;
  }
  else
  {
    (*pdist) = -1;
  }
}

/* **************************************************************************** 
  Functionname:     HLATrackUtilsMaha22Diag
  Description:      

                    Mahalanobis distance (2 dimensions, no cross corr)
 

  @param[in]        
  @param[out]       
  @return           -
  @pre              -
  @post             -
  @author           Bertrand Godreau
****************************************************************************/
void HLATrackUtilsMaha22Diag( float32*  pdist,
                              float32   dx,
                              float32   dy,
                              float32   sxx,
                              float32   syy
                            )
{
  float32 det;

  /* calculate innovation matrix inverse Sinv = inv(S)*/
  det = (sxx * syy);

  if(CML_f_IsNonZero(det))
  {
    (*pdist) =  dx * dx * syy;
    (*pdist) += dy * dy * sxx;

    (*pdist) = (*pdist) / det;
  }
  else
  {
    (*pdist) = -1;
  }
}


/* **************************************************************************** 
  Functionname:     HLATrackUtilsMaha33
  Description:      

                    Mahalanobis distance (3 dimensions)

 
  @param[in]        
  @param[out]       
  @return           -
  @pre              -
  @post             -
  @author           Bertrand Godreau
****************************************************************************/
void HLATrackUtilsMaha33(       float32*  pdist,
                          const float32   dx,
                          const float32   dy,
                          const float32   dh,
                          const float32   sxx,
                          const float32   syx,
                          const float32   shx,
                          const float32   syy,
                          const float32   shy,
                          const float32   shh
                        )
{
  float32 detS0;
  float32 detS1;
  float32 detS2;
  float32 detS4;
  float32 detS5;
  float32 detS8;
  float32 det,idet;
  float32 a,b,c;

  float32 sixx;
  float32 siyx,siyy;
  float32 sihx,sihy,sihh;
  
  detS0 = (syy * shh) - (shy * shy);
  detS1 = (syx * shh) - (shx * shy);
  detS2 = (syx * shy) - (shx * syy);

  det = (sxx * detS0) + (-syx * detS1) + (shx * detS2);

  if(CML_f_IsNonZero(det))
  {
    idet = 1/det;

    detS4 = (sxx * shh) - (shx * shx);
    detS5 = (sxx * shy) - (shx * syx);
    detS8 = (sxx * syy) - (syx * syx);

    sixx =   detS0 * idet;
    siyx = - detS1 * idet;
    sihx =   detS2 * idet;

    siyy =   detS4 * idet;
    sihy = - detS5 * idet;

    sihh =   detS8 * idet;


    a = (sixx * dx) + (siyx * dy) + (sihx * dh);
    b = (siyx * dx) + (siyy * dy) + (sihy * dh);
    c = (sihx * dx) + (sihy * dy) + (sihh * dh);

    *pdist = (a * dx) + (b * dy) + (c * dh);
  }
  else
  {
    *pdist = -1;
  }
}
