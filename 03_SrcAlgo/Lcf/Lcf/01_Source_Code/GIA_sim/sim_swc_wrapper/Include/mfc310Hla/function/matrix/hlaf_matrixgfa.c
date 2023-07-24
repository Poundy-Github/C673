/*! \file ****.***************************************************************

  COMPANY:                Continental AG, BU PSAD, Segment ADAS (A.D.C. GmbH)

  PROJECT:                MFC400

  CPU:                    FreeScale Gold Dust

  COMPONENT:              HLA

  MODULNAME:              hlaf_matrixgfa.c

  DESCRIPTION:            HLA matrix beam function.
                          Module clusters the vehicle lights to a desired number of glare free areas (1..5).

  AUTHOR:                 Marcus Brunn

  CREATION DATE:          2013-03-07

  VERSION:                $Revision: 1.1 $
   
  ---*/ /*---
  CHANGE:                 $Log: hlaf_matrixgfa.c  $
  CHANGE:                 Revision 1.1 2021/12/13 17:27:22CET Wang, David (Wangd3) 
  CHANGE:                 Initial revision
  CHANGE:                 Member added to project /ADAS/Projects/MFC5xx/MFC5J3/06_Algorithm/DPU/04_Engineering/01_Source_Code/GIA_sim/sim_swc_wrapper/Include/mfc310Hla/function/matrix/project.pj
  CHANGE:                 Revision 1.0 2017/03/03 10:39:01CET Sorge, Sven (uidg3181) 
  CHANGE:                 Initial revision
  CHANGE:                 Member added to project /ADAS/SW/Integration/06_Simulation_Components/GIA_GenericInterfaceAdapter/04_Engineering/03_Workspace/Component_Workspace/GIA_sim/sim_swc_wrapper/Include/mfc310Hla/function/matrix/project.pj
  CHANGE:                 Revision 1.1 2014/04/17 16:05:42CEST Sorge, Sven (uidg3181) 
  CHANGE:                 Initial revision
  CHANGE:                 Member added to project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/ETK_EngineeringToolKit/04_Engineering/GIA_GenericInterfaceAdapter/04_Engineering/03_Workspace/algo/gia_sim/wrapper/Include/mfc310Hla/function/matrix/project.pj
  CHANGE:                 Revision 1.13 2014/03/26 11:27:28CET Mutschler, Matthias (uidv7867) 
  CHANGE:                 Removed some mandatory QAC warnings
  CHANGE:                 --- Added comments ---  uidv7867 [Mar 26, 2014 11:27:28 AM CET]
  CHANGE:                 Change Package : 207432:35 http://mks-psad:7002/im/viewissue?selection=207432
  CHANGE:                 Revision 1.12 2014/03/25 18:38:57CET Mutschler, Matthias (uidv7867) 
  CHANGE:                 Member moved from hlaf_matrixgfa.c in project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/HLA_HeadLightAssist/04_Engineering/01_Source_Code/algo/hla/project.pj to hlaf_matrixgfa.c in project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/HLA_HeadLightAssist/04_Engineering/01_Source_Code/algo/hla/function/matrix/project.pj.
  CHANGE:                 Revision 1.11 2014/03/19 16:31:26CET Mutschler, Matthias (uidv7867) 
  CHANGE:                 Replace macros from glob_defs.h by the ones defined in cml_ext.h
  CHANGE:                 Fixed hlar input adapter for old recordings (headlamp type)
  CHANGE:                 Clean-up of no longer needed files in simulation
  CHANGE:                 --- Added comments ---  uidv7867 [Mar 19, 2014 4:31:26 PM CET]
  CHANGE:                 Change Package : 225959:1 http://mks-psad:7002/im/viewissue?selection=225959
  CHANGE:                 Revision 1.10 2014/03/10 13:20:46CET Mutschler, Matthias (uidv7867) 
  CHANGE:                 Fixed some new critical QAC warnings
  CHANGE:                 Moved suppressions from .hoc file to comment in source code
  CHANGE:                 --- Added comments ---  uidv7867 [Mar 10, 2014 1:20:46 PM CET]
  CHANGE:                 Change Package : 207432:35 http://mks-psad:7002/im/viewissue?selection=207432
  CHANGE:                 Revision 1.9 2014/03/04 16:52:24CET Mutschler, Matthias (uidv7867) 
  CHANGE:                 Fixed QAC warnings
  CHANGE:                 Coding style
  CHANGE:                 --- Added comments ---  uidv7867 [Mar 4, 2014 4:52:24 PM CET]
  CHANGE:                 Change Package : 207432:35 http://mks-psad:7002/im/viewissue?selection=207432
  CHANGE:                 Revision 1.8 2014/02/14 15:33:12CET Schillinger, Patrick (uidv8776) 
  CHANGE:                 fixed possible endless loop in glare free area merging
  CHANGE:                 --- Added comments ---  uidv8776 [Feb 14, 2014 3:33:12 PM CET]
  CHANGE:                 Change Package : 219182:1 http://mks-psad:7002/im/viewissue?selection=219182
  CHANGE:                 Revision 1.7 2013/12/18 15:19:44CET Schillinger, Patrick (uidv8776) 
  CHANGE:                 bugfix to prevent endless loop in HLAFMatrixGFA_ReduceVC2MaxNumGFA
  CHANGE:                 --- Added comments ---  uidv8776 [Dec 18, 2013 3:19:44 PM CET]
  CHANGE:                 Change Package : 199150:1 http://mks-psad:7002/im/viewissue?selection=199150
  CHANGE:                 Revision 1.6 2013/04/04 10:27:11CEST Brunn, Marcus (brunnm) 
  CHANGE:                 added ExistenceProb to GFA and object list
  CHANGE:                 --- Added comments ---  brunnm [Apr 4, 2013 10:27:12 AM CEST]
  CHANGE:                 Change Package : 167112:1 http://mks-psad:7002/im/viewissue?selection=167112
  CHANGE:                 Revision 1.5 2013/03/13 19:11:42CET Brunn, Marcus (brunnm) 
  CHANGE:                 HLAF: used Matrix.MaxNumGlarefreeArea from HLAF Parameter input
  CHANGE:                 --- Added comments ---  brunnm [Mar 13, 2013 7:11:42 PM CET]
  CHANGE:                 Change Package : 167112:1 http://mks-psad:7002/im/viewissue?selection=167112
  CHANGE:                 Revision 1.4 2013/03/12 10:59:00CET Mutschler, Matthias (uidv7867) 
  CHANGE:                 Replaced no longer needed types by RTE ones
  CHANGE:                 --- Added comments ---  uidv7867 [Mar 12, 2013 10:59:00 AM CET]
  CHANGE:                 Change Package : 167173:28 http://mks-psad:7002/im/viewissue?selection=167173
  CHANGE:                 Revision 1.3 2013/03/11 18:01:52CET Mutschler, Matthias (uidv7867) 
  CHANGE:                 Replace some types by RTE ones
  CHANGE:                 --- Added comments ---  uidv7867 [Mar 11, 2013 6:01:53 PM CET]
  CHANGE:                 Change Package : 167173:28 http://mks-psad:7002/im/viewissue?selection=167173
  CHANGE:                 Revision 1.2 2013/03/11 16:48:12CET Mutschler, Matthias (uidv7867) 
  CHANGE:                 Replaced  no longer needed macros by RTE ones
  CHANGE:                 - HLAR_MAX_NUM_DEFECT_PIXEL
  CHANGE:                 - HLAF_MATRIX_MAX_NUM_GLARE_FREE_AREAS
  CHANGE:                 - HLAF_NIGHTVIEW_OBJECTS
  CHANGE:                 - HLA_FINGERPRINT_PIXELS
  CHANGE:                 --- Added comments ---  uidv7867 [Mar 11, 2013 4:48:13 PM CET]
  CHANGE:                 Change Package : 167173:28 http://mks-psad:7002/im/viewissue?selection=167173
  CHANGE:                 Revision 1.1 2013/03/11 10:39:34CET Brunn, Marcus (brunnm) 
  CHANGE:                 Initial revision
  CHANGE:                 Member added to project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/HLA_HeadLightAssist/04_Engineering/01_Source_Code/algo/hla/project.pj
  CHANGE:                 
  CHANGE:
**************************************************************************** */

/*****************************************************************************
  INCLUDES
*****************************************************************************/
/* J.Häfer: Redundant including of math.h is checked */
#include <math.h>
#include <string.h>
#include "hlaf_defs.h"
#include "hlaf_type.h"
#include "hlaf_matrix.h"
#include "hlaf_matrixgfa.h"




/*****************************************************************************
  SYMBOLIC CONSTANTS 
*****************************************************************************/


/*****************************************************************************
  MACROS 
*****************************************************************************/


/*****************************************************************************
  TYPEDEFS 
*****************************************************************************/
typedef struct
{
  float32 BndryLeft_Ang;
  float32 BndryRight_Ang;
  float32 ClosestObj_Dist; /* closest object distance */
  RTE_HLAF_ObjStatus BndryLeft_Status; /* object status of left boundary: no obj, oncoming, preceding vehicle */
  RTE_HLAF_ObjStatus BndryRight_Status; /* object status of left boundary: no obj, oncoming, preceding vehicle */
  RTE_HLAF_ObjStatus ClosestObj_Status; /* closest object status: no obj, oncoming, preceding vehicle */
  uint8 Assignment_VC2GFA; /* GFA assignment: VC 2 previous GFA */
} HLAFMatrixGFA_VehClusterData_t; /* VehCluster = VC */

typedef struct  
{
  ARRAY(HLAFMatrixGFA_VehClusterData_t, RTE_HLAR_OBJECT_LIST_LENGTH, VC);
  uint8 nVC_Max; /* number of vehicle cluster before reduction to max number of GFAs */
  uint8 nVC; /* current number of vehicle clusters */

  uint8  Assignment_GFA2VC[RTE_HLAF_MATRIX_MAX_NUM_GLARE_FREE_AREAS]; /* GFA assignment: GFA 2 Vehicle Cluster (VC) */
}HLAFMatrixGFA_VehCluster_t; /* VehCluster = VC */

/*****************************************************************************
  VARIABLES 
*****************************************************************************/



/*****************************************************************************
  FUNCTION 
*****************************************************************************/
/* init one GFA */
static void HLAFMatrixGFA_InitData(HLAFMatrixGFAData_t *pData);
static void HLAFMatrixGFA_AddObj2VC( const HLA_t_Object *pObj,
                                     HLAFMatrixGFA_VehClusterData_t *pVC
                                   );
static void HLAFMatrixGFA_MergeVC( const HLAFMatrixGFA_VehClusterData_t *pVC,
                                   HLAFMatrixGFA_VehClusterData_t *pVCmerged
                                 );
static float32 HLAFMatrixGFA_GetOverlapVC2VC( const HLAFMatrixParClusterVeh2GFA_t *pPar,
                                              const HLAFMatrixGFA_VehClusterData_t *pVC0,
                                              const HLAFMatrixGFA_VehClusterData_t *pVC1
                                             );
static float32 HLAFMatrixGFA_GetOverlapVC2Obj( const HLAFMatrixParClusterVeh2GFA_t *pPar,
                                               const HLAFMatrixGFA_VehClusterData_t *pVC,
                                               const HLA_t_Object *pObj0,
                                               const HLA_t_Object *pObj1
                                             );
static void HLAFMatrixGFA_InitVehCluster(HLAFMatrixGFA_VehClusterData_t *pVC);


static void HLAFMatrixGFA_InitInternalData(HLAFMatrixGFA_VehCluster_t *pVC);
static void HLAFMatrixGFA_ClusterVehicles( const HLAF_t_RequiredInputs *ps_In,
                                           const HLAFMatrixParameter_t *pPar,
                                           HLAFMatrixData_t *pData,
                                           HLAFMatrixGFA_VehCluster_t *pVC
                                         );
static void HLAFMatrixGFA_ReduceVC2MaxNumGFA( const HLAF_t_RequiredInputs *ps_In,
                                              const HLAFMatrixParameter_t *pPar,
                                              HLAFMatrixData_t *pData,
                                              const uint32 MaxNumGFA,
                                              HLAFMatrixGFA_VehCluster_t *pVC
                                            );
static void HLAFMatrixGFA_AssignVC2GFA( const HLAFMatrixParameter_t *pPar,
                                        const HLAFMatrixData_t *pData,
                                        HLAFMatrixGFA_VehCluster_t *pVC
                                      );
static void HLAFMatrixGFA_AssignUnusedVC2FreeGFA( HLAFMatrixData_t *pData,
                                                  const uint32 MaxNumGFA,
                                                  HLAFMatrixGFA_VehCluster_t *pVC
                                                );
static void HLAFMatrixGFA_AssignUnusedVC2LostGFA( const HLAFMatrixData_t *pData,
                                                  HLAFMatrixGFA_VehCluster_t *pVC
                                                );
static void HLAFMatrixGFA_UpdateObjAssignment2GFA( const HLAF_t_RequiredInputs *ps_In,
                                                   const HLAFMatrixGFA_VehCluster_t *pVC,
                                                   HLAFMatrixData_t *pData
                                                 );
static void HLAFMatrixGFA_UpdateGFAObjLinks( const HLAF_t_RequiredInputs *ps_In,
                                             HLAFMatrixData_t *pData
                                           );
static void HLAFMatrixGFA_UpdateGFAData( const HLAF_t_RequiredInputs  *ps_In,
                                         HLAFMatrixData_t      *pData
                                       );
static void HLAFMatrixGFA_DeleteGFA( const HLAFMatrixParameter_t *pPar,
                                     const HLAFData_t *pFData,
                                     HLAFMatrixData_t *pData
                                   );






static void HLAFMatrixGFA_InitData(HLAFMatrixGFAData_t *pData)
{
  memset(pData, 0, sizeof(HLAFMatrixGFAData_t));

  pData->Int.ObjID = RTE_HLAR_OBJECT_LIST_LENGTH;
  pData->Ext.BndryLeft_Status = RTE_HLAF_OBJSTA_NO_OBJ;
  pData->Ext.BndryRight_Status = RTE_HLAF_OBJSTA_NO_OBJ;
  pData->Ext.BndryLower_Status = RTE_HLAF_OBJSTA_NO_OBJ;
  pData->Ext.ClosestObj_Status = RTE_HLAF_OBJSTA_NO_OBJ;
  pData->Ext.MinLight_Status = RTE_HLAF_OBJSTA_NO_OBJ;
  pData->Ext.ttb18Left_Status = RTE_HLAF_TTBSTA_NO_OBJ;
  pData->Ext.ttb18Right_Status = RTE_HLAF_TTBSTA_NO_OBJ;
}

void HLAFMatrixGFAInit(HLAFMatrixGFA_t *pGFA)
{
  uint32 i;

  for(i=0; i<RTE_HLAF_MATRIX_MAX_NUM_GLARE_FREE_AREAS; i++)
  {
    HLAFMatrixGFA_InitData(&pGFA->GFA[i]);
  }

  pGFA->nGFA = 0;
  pGFA->GFAStatus = RTE_HLAF_SIGSTAT_DATA_VALID;
}


static void HLAFMatrixGFA_AddObj2VC( const HLA_t_Object *pObj,
                                     HLAFMatrixGFA_VehClusterData_t *pVC
                                   )
{
  if(pObj != NULL)
  {
    float32 Obj_Dist = 0.005f*(pObj->s_ObjectPos_xw.ui16_distMin_cm+pObj->s_ObjectPos_xw.ui16_distMax_cm);
    
    if(pVC != NULL)
    {
      /* GFA used ? */
      if(    (pVC->BndryLeft_Status == RTE_HLAF_OBJSTA_PREC_OBJ)
          || (pVC->BndryLeft_Status == RTE_HLAF_OBJSTA_ONC_OBJ)
        )      
      {
        if(pObj->s_Status.isVehicleOncoming == 1)
        {
          if(pObj->f32_ObjectHorAng_rad > pVC->BndryLeft_Ang)
          {
            pVC->BndryLeft_Ang = pObj->f32_ObjectHorAng_rad;
            pVC->BndryLeft_Status = RTE_HLAF_OBJSTA_ONC_OBJ;
          }
          if(pObj->f32_ObjectHorAng_rad < pVC->BndryRight_Ang)
          {
            pVC->BndryRight_Ang = pObj->f32_ObjectHorAng_rad;
            pVC->BndryRight_Status = RTE_HLAF_OBJSTA_ONC_OBJ;
          }
          if(Obj_Dist < pVC->ClosestObj_Dist)
          {
            pVC->ClosestObj_Dist = Obj_Dist;
            pVC->BndryLeft_Status = RTE_HLAF_OBJSTA_ONC_OBJ;
          }
        }
        else if(pObj->s_Status.isVehicleAhead == 1)
        {
          if(pObj->f32_ObjectHorAng_rad > pVC->BndryLeft_Ang)
          {
            pVC->BndryLeft_Ang = pObj->f32_ObjectHorAng_rad;
            pVC->BndryLeft_Status = RTE_HLAF_OBJSTA_PREC_OBJ;
          }
          if(pObj->f32_ObjectHorAng_rad < pVC->BndryRight_Ang)
          {
            pVC->BndryRight_Ang = pObj->f32_ObjectHorAng_rad;
            pVC->BndryRight_Status = RTE_HLAF_OBJSTA_PREC_OBJ;
          }
          if(Obj_Dist < pVC->ClosestObj_Dist)
          {
            pVC->ClosestObj_Dist = Obj_Dist;
            pVC->BndryLeft_Status = RTE_HLAF_OBJSTA_PREC_OBJ;
          }
        }
        else
        {
          /* Do nothing */
        }
      }    
      else
      {
        /* init GFA */
        if(pObj->s_Status.isVehicleOncoming == 1)
        {
          pVC->BndryLeft_Ang = pObj->f32_ObjectHorAng_rad;
          pVC->BndryLeft_Status = RTE_HLAF_OBJSTA_ONC_OBJ;
          pVC->BndryRight_Ang = pObj->f32_ObjectHorAng_rad;
          pVC->BndryRight_Status = RTE_HLAF_OBJSTA_ONC_OBJ;
          pVC->ClosestObj_Dist = Obj_Dist;
          pVC->BndryLeft_Status = RTE_HLAF_OBJSTA_ONC_OBJ;
        }
        else if(pObj->s_Status.isVehicleAhead == 1)
        {
          pVC->BndryLeft_Ang = pObj->f32_ObjectHorAng_rad;
          pVC->BndryLeft_Status = RTE_HLAF_OBJSTA_PREC_OBJ;
          pVC->BndryRight_Ang = pObj->f32_ObjectHorAng_rad;
          pVC->BndryRight_Status = RTE_HLAF_OBJSTA_PREC_OBJ;
          pVC->ClosestObj_Dist = Obj_Dist;
          pVC->BndryLeft_Status = RTE_HLAF_OBJSTA_PREC_OBJ;
        }
        else
        {
          /* Do nothing */
        }
      }
    }
  }
}


static void HLAFMatrixGFA_MergeVC( const HLAFMatrixGFA_VehClusterData_t *pVC,
                                   HLAFMatrixGFA_VehClusterData_t *pVCmerged
                                 )
{
  if((pVC != NULL) && (pVCmerged != NULL))
  {
    /* GFA used ? */
    if(    (pVC->BndryLeft_Status == RTE_HLAF_OBJSTA_PREC_OBJ)
        || (pVC->BndryLeft_Status == RTE_HLAF_OBJSTA_ONC_OBJ)
      )      
    {
      if(pVC->BndryLeft_Ang > pVCmerged->BndryLeft_Ang)
      {
        pVCmerged->BndryLeft_Ang = pVC->BndryLeft_Ang;
        pVCmerged->BndryLeft_Status = pVC->BndryLeft_Status;
      }
      if(pVC->BndryRight_Ang < pVCmerged->BndryRight_Ang)
      {
        pVCmerged->BndryRight_Ang = pVC->BndryRight_Ang;
        pVCmerged->BndryRight_Status = pVC->BndryRight_Status;
      }
      if(pVC->ClosestObj_Dist < pVCmerged->ClosestObj_Dist)
      {
        pVCmerged->ClosestObj_Dist = pVC->ClosestObj_Dist;
        pVCmerged->ClosestObj_Status = pVC->ClosestObj_Status;
      }
    }
  }
}


static float32 HLAFMatrixGFA_GetOverlapVC2VC( const HLAFMatrixParClusterVeh2GFA_t *pPar,
                                                 const HLAFMatrixGFA_VehClusterData_t *pVC0,
                                                 const HLAFMatrixGFA_VehClusterData_t *pVC1
                                               )
{
  /* return overlap angle between two GFAs */
  /* dAng < 0: overlap between VC0 and VC1 */
  float32 dAng;
  float32 dAng_Thres;
  RTE_HLAF_ObjStatus Status0, Status1;
  float32 Ang0, Ang1;
  float32 closestObjDist = CML_f_Max(1.0f, CML_f_Min(pVC0->ClosestObj_Dist, pVC1->ClosestObj_Dist));
  

  if(    (    (pVC0->BndryLeft_Status == RTE_HLAF_OBJSTA_PREC_OBJ)
           || (pVC0->BndryLeft_Status == RTE_HLAF_OBJSTA_ONC_OBJ)
         )
      && (    (pVC1->BndryLeft_Status == RTE_HLAF_OBJSTA_PREC_OBJ)
           || (pVC1->BndryLeft_Status == RTE_HLAF_OBJSTA_ONC_OBJ)
         )
    )
  {
    if(pVC0->BndryRight_Ang >= pVC1->BndryRight_Ang)
    {
      Status0 = pVC0->BndryRight_Status;
      Ang0 = pVC0->BndryRight_Ang;
    } 
    else
    {
      Status0 = pVC1->BndryRight_Status;
      Ang0 = pVC1->BndryRight_Ang;
    } 

    if(pVC0->BndryLeft_Ang <= pVC1->BndryLeft_Ang)
    {
      Status1 = pVC0->BndryLeft_Status;
      Ang1 = pVC0->BndryLeft_Ang;
    } 
    else
    {
      Status1 = pVC1->BndryLeft_Status;
      Ang1 = pVC1->BndryLeft_Ang;
    }
      
    dAng = Ang0-Ang1; /* dAng < 0: overlap */
                      /* dAng > 0: no overlap */

    if(    (Status0 == RTE_HLAF_OBJSTA_PREC_OBJ)
        && (Status1 == RTE_HLAF_OBJSTA_PREC_OBJ)
      )
    {
      /* preceding with preceding */
      dAng_Thres = CML_f_Max(pPar->dAngPrec, (pPar->WidthPrec/ closestObjDist));
    }
    else if(    (Status0 == RTE_HLAF_OBJSTA_ONC_OBJ)
             && (Status1 == RTE_HLAF_OBJSTA_ONC_OBJ)
           )
    {
      /* oncoming with oncoming */
      dAng_Thres = CML_f_Max(pPar->dAngOnc, (pPar->WidthOnc/ closestObjDist));
    }
    else
    {
      /* preceding with oncoming */
      dAng_Thres = CML_f_Max(pPar->dAng, (pPar->Width/ closestObjDist));
    }

    dAng = dAng - dAng_Thres;
  }
  else
  {
    /* VC0 or VC1 not valid */
    dAng = CML_Deg2Rad(90.0f);
  }     
  
  return(dAng);
}


static float32 HLAFMatrixGFA_GetOverlapVC2Obj( const HLAFMatrixParClusterVeh2GFA_t *pPar,
                                                 const HLAFMatrixGFA_VehClusterData_t *pVC,
                                                 const HLA_t_Object *pObj0,
                                                 const HLA_t_Object *pObj1
                                               )
{
  /* function returns overlap (dAng) of Obj0 and Obj1 with GFA */
  /* overlap -> dAng < 0                                       */
  HLAFMatrixGFA_VehClusterData_t VC_Obj01; /* GFA of Object 0 and 1 */
  float32 dAng;


  memset(&VC_Obj01, 0, sizeof(HLAFMatrixGFA_VehClusterData_t));
  
  /* build GFA of Obj0 and Obj1 */
  HLAFMatrixGFA_AddObj2VC(pObj0, &VC_Obj01);
  HLAFMatrixGFA_AddObj2VC(pObj1, &VC_Obj01);
  
  /* check overlap of VC_Obj01 with VC */
  dAng = HLAFMatrixGFA_GetOverlapVC2VC( pPar,
                                        &VC_Obj01,
                                        pVC        
                                       );

  return(dAng);
}


static void HLAFMatrixGFA_InitVehCluster(HLAFMatrixGFA_VehClusterData_t *pVC)
{
  memset(pVC, 0, sizeof(HLAFMatrixGFA_VehClusterData_t));
  pVC->Assignment_VC2GFA = UI8_T_MAX;
}


/* 1. init internal data */
static void HLAFMatrixGFA_InitInternalData(HLAFMatrixGFA_VehCluster_t *pVC)
{
  uint8 iVC;


  for(iVC=0; iVC<RTE_HLAF_MATRIX_MAX_NUM_GLARE_FREE_AREAS; iVC++)
  {
    pVC->Assignment_GFA2VC[iVC] = UI8_T_MAX;
  }

  for(iVC=0; iVC<RTE_HLAR_OBJECT_LIST_LENGTH; iVC++)
  {
    HLAFMatrixGFA_InitVehCluster(&pVC->VC[iVC]);
  }
  
  pVC->nVC = 0;
  pVC->nVC_Max = 0;
  
}


/* 2. build vehicle clusters (max. RTE_HLAR_OBJECT_LIST_LENGTH GFAs) */
static void HLAFMatrixGFA_ClusterVehicles( const HLAF_t_RequiredInputs *ps_In,
                                           const HLAFMatrixParameter_t *pPar,
                                           HLAFMatrixData_t *pData,
                                           HLAFMatrixGFA_VehCluster_t *pVC
                                         )
{
  uint8 iObj;
  uint8 iVC;

  pVC->nVC_Max = 0;
  

  for(iObj=0; iObj < CML_Min(ps_In->s_Sig.ps_ObjectList->ui32_NumVehicles, RTE_HLAR_OBJECT_LIST_LENGTH); iObj++)
  {
    uint8 iVCfree = pVC->nVC_Max;
    boolean bObjAssigned = FALSE;
    uint32 iObjPair;


    if(pData->Object[iObj].ObjIDPair < RTE_HLAR_OBJECT_LIST_LENGTH)
    {
      /* pair light */
      iObjPair = pData->Object[iObj].ObjIDPair;
    }
    else
    {
      /* single light */
      iObjPair = iObj;
    }


    /* check against existing GFAs */
    for(iVC=0; ((iVC<pVC->nVC_Max) && (bObjAssigned == b_FALSE)); iVC++)
    {
      /* overlap ?*/
      float32 dAng;


      dAng = HLAFMatrixGFA_GetOverlapVC2Obj( &pPar->ClusterVeh2GFA,
        &pVC->VC[iVC],
        &ps_In->s_Sig.ps_ObjectList->as_Object[iObj],
        &ps_In->s_Sig.ps_ObjectList->as_Object[iObjPair]
      );

      if(dAng < 0.0f)
      {
        pData->Object[iObj].GFA = iVC;
        pData->Object[iObjPair].GFA = iVC;
        /* update GFA boundary */
        HLAFMatrixGFA_AddObj2VC( &ps_In->s_Sig.ps_ObjectList->as_Object[iObj],
          &pVC->VC[iVC]
        );
        HLAFMatrixGFA_AddObj2VC( &ps_In->s_Sig.ps_ObjectList->as_Object[iObjPair],
          &pVC->VC[iVC]
        );
        /* object assigned to GFA */
        bObjAssigned = b_TRUE;
      }
    }


    /* free GFA available and object not assigned to GFA ?  */
    /* -> build new GFA                                     */
    if(    (iVCfree < RTE_HLAR_OBJECT_LIST_LENGTH)
        && (bObjAssigned == b_FALSE)
      )
    {
      /* build new GFA */
      uint32 iObj1, iObjPair1;

      pData->Object[iObj].GFA = iVCfree;
      pData->Object[iObjPair].GFA = iVCfree;
      /* init new GFA: angles, min object distance, Status, ... */
      HLAFMatrixGFA_AddObj2VC( &ps_In->s_Sig.ps_ObjectList->as_Object[iObj],
        &pVC->VC[iVCfree]
      );
      HLAFMatrixGFA_AddObj2VC( &ps_In->s_Sig.ps_ObjectList->as_Object[iObjPair],
        &pVC->VC[iVCfree]
      );

      /* search for overlap with other unused vehicles */
      for(iObj1=iObj+1; iObj1 < CML_Min(ps_In->s_Sig.ps_ObjectList->ui32_NumVehicles, RTE_HLAR_OBJECT_LIST_LENGTH); iObj1++)
      { 
        /* unused iObj1 ? */
        if(pData->Object[iObj1].GFA >= RTE_HLAR_OBJECT_LIST_LENGTH)
        {
          if(pData->Object[iObj1].ObjIDPair < RTE_HLAR_OBJECT_LIST_LENGTH)
          {
            iObjPair1 = pData->Object[iObj1].ObjIDPair;
          }
          else
          {
            iObjPair1 = iObj1;
          }

          /* overlap between new GFA and Obj1 ? */
          {
            float32 dAng;


            dAng = HLAFMatrixGFA_GetOverlapVC2Obj( &pPar->ClusterVeh2GFA,
              &pVC->VC[iVCfree],
              &ps_In->s_Sig.ps_ObjectList->as_Object[iObj1],
              &ps_In->s_Sig.ps_ObjectList->as_Object[iObjPair1]
            );

            if(dAng < 0.0f)
            {
              pData->Object[iObj1].GFA = iVCfree;
              pData->Object[iObjPair1].GFA = iVCfree;
              /* update GFA boundary */
              /* update GFA boundary */
              HLAFMatrixGFA_AddObj2VC( &ps_In->s_Sig.ps_ObjectList->as_Object[iObj1],
                &pVC->VC[iVCfree]
              );
              HLAFMatrixGFA_AddObj2VC( &ps_In->s_Sig.ps_ObjectList->as_Object[iObjPair1],
                &pVC->VC[iVCfree]
              );
            }      
          }
        }
      }
      pVC->nVC_Max = pVC->nVC_Max+1;
    }
  }

  pVC->nVC = pVC->nVC_Max;
}


/* 3. reduce Vehicle Clusters (VC) to max number of GFA (=RTE_HLAF_MATRIX_MAX_NUM_GLARE_FREE_AREAS) */
static void HLAFMatrixGFA_ReduceVC2MaxNumGFA( const HLAF_t_RequiredInputs *ps_In,
                                              const HLAFMatrixParameter_t *pPar,
                                              HLAFMatrixData_t *pData,
                                              const uint32 MaxNumGFA,
                                              HLAFMatrixGFA_VehCluster_t *pVC
                                            )
{
  if(pVC->nVC_Max > MaxNumGFA)
  {
    uint8 iVC1, iVC2;
    uint8 iObj;


    pVC->nVC = pVC->nVC_Max;
    while(pVC->nVC > MaxNumGFA)
    {
      uint8 iVC1_merge = 0;
      uint8 iVC2_merge = 1;
      float32 dAng_merge = CML_Deg2Rad(360.0f);

      /* find the two closest GFAs and merge them */
      for(iVC1=0; iVC1<(pVC->nVC_Max-1); iVC1++)
      {
        for(iVC2=iVC1+1; iVC2<pVC->nVC_Max; iVC2++)
        {
          float32 dAng;

          dAng = HLAFMatrixGFA_GetOverlapVC2VC( &pPar->ClusterVeh2GFA,
                                                &pVC->VC[iVC1],
                                                &pVC->VC[iVC2]
                                              );
          if(dAng <= dAng_merge)
          {
            iVC1_merge = iVC1;
            iVC2_merge = iVC2;
            dAng_merge = dAng;
          }
        }
      }
      /* merge the two GFAs */
      if(    (iVC1_merge < RTE_HLAR_OBJECT_LIST_LENGTH)
          && (iVC2_merge < RTE_HLAR_OBJECT_LIST_LENGTH)
        )
      {
        /* merge iVC2_merge into iVC1_merge */
        HLAFMatrixGFA_MergeVC( &pVC->VC[iVC2_merge], &pVC->VC[iVC1_merge]);
        /* delete iVC2_merge */
        HLAFMatrixGFA_InitVehCluster(&pVC->VC[iVC2_merge]);

        /* update merged GFA in object list */
        for(iObj=0; iObj < CML_Min(ps_In->s_Sig.ps_ObjectList->ui32_NumVehicles, RTE_HLAR_OBJECT_LIST_LENGTH); iObj++)
        {
          if(pData->Object[iObj].GFA == iVC2_merge)
          {
            pData->Object[iObj].GFA = iVC1_merge;
          }
        }
        /* decrement number of GFAs */
        pVC->nVC--;
      }
    }
  }
}


/* 4. assign vehicle cluster (VC) to best matching GFAs from previous cycle */
static void HLAFMatrixGFA_AssignVC2GFA( const HLAFMatrixParameter_t *pPar,
                                        const HLAFMatrixData_t *pData,
                                        HLAFMatrixGFA_VehCluster_t *pVC
                                      )
{
  uint8 iVCnew;
  
  for(iVCnew=0; iVCnew<pVC->nVC_Max; iVCnew++)
  {
    /* used GFA ? */
    if(    (pVC->VC[iVCnew].BndryLeft_Status == RTE_HLAF_OBJSTA_PREC_OBJ)
        || (pVC->VC[iVCnew].BndryLeft_Status == RTE_HLAF_OBJSTA_ONC_OBJ)
      )
    {
      uint8 iGFA;
      uint8 iGFA_bestMatch = UI8_T_MAX;
      float32 dAng_bestMatch = CML_Deg2Rad(90.0f);
      /* GFA not assigned */

      /* find best match between new GFA and previous GFAs */
      for(iGFA=0; iGFA<pData->Matrix.GFA.nGFA; iGFA++)
      {
        /* previous GFA not assigned ? */
        if(pVC->Assignment_GFA2VC[iGFA] == UI8_T_MAX)
        {
          HLAFMatrixGFA_VehClusterData_t VCtemp;
          float32 dAng;


          VCtemp.BndryLeft_Ang = pData->Matrix.GFA.GFA[iGFA].Ext.BndryLeft_Ang;
          VCtemp.BndryLeft_Status = pData->Matrix.GFA.GFA[iGFA].Ext.BndryLeft_Status;
          VCtemp.BndryRight_Ang = pData->Matrix.GFA.GFA[iGFA].Ext.BndryRight_Ang;
          VCtemp.BndryRight_Status = pData->Matrix.GFA.GFA[iGFA].Ext.BndryRight_Status;
          VCtemp.ClosestObj_Dist = pData->Matrix.GFA.GFA[iGFA].Ext.ClosestObj_Dist;
          VCtemp.ClosestObj_Status = pData->Matrix.GFA.GFA[iGFA].Ext.ClosestObj_Status;

          dAng = HLAFMatrixGFA_GetOverlapVC2VC( &pPar->ClusterVeh2GFA,
                                                &VCtemp,
                                                &pVC->VC[iVCnew]
                                              );

          if(    (dAng < 0.0f)
              && (dAng < dAng_bestMatch)
            )
          {
            dAng_bestMatch = dAng;
            iGFA_bestMatch = iGFA;
          }
        }
      }
      if(iGFA_bestMatch < RTE_HLAF_MATRIX_MAX_NUM_GLARE_FREE_AREAS)
      {
        /* save assigned GFA */
        pVC->VC[iVCnew].Assignment_VC2GFA = iGFA_bestMatch;
        pVC->Assignment_GFA2VC[iGFA_bestMatch] = iVCnew;
      }
    }
  }
}


/* 5. assign unused vehicle cluster (VC) to free GFAs (if available) */
static void HLAFMatrixGFA_AssignUnusedVC2FreeGFA( HLAFMatrixData_t *pData,
                                                  const uint32 MaxNumGFA,
                                                  HLAFMatrixGFA_VehCluster_t *pVC
                                                )
{
  if(pData->Matrix.GFA.nGFA < MaxNumGFA)
  {
    uint8 iVCnew;

    for(iVCnew=0; iVCnew<pVC->nVC_Max; iVCnew++)
    {
      uint8 iGFAfree = (uint8)pData->Matrix.GFA.nGFA;

      /* used GFA and not assigned ? */
      if(    (    (pVC->VC[iVCnew].BndryLeft_Status == RTE_HLAF_OBJSTA_PREC_OBJ)
               || (pVC->VC[iVCnew].BndryLeft_Status == RTE_HLAF_OBJSTA_ONC_OBJ)
             ) 
          && (pVC->VC[iVCnew].Assignment_VC2GFA == UI8_T_MAX)
          && (iGFAfree < RTE_HLAF_MATRIX_MAX_NUM_GLARE_FREE_AREAS)
        )
      {
        pVC->VC[iVCnew].Assignment_VC2GFA = iGFAfree;
        pVC->Assignment_GFA2VC[iGFAfree] = iVCnew;

        pData->Matrix.GFA.nGFA++;
      }
    }
  }
}


/* 6. assign unused vehicle cluster (VC) to the oldest, lost(no vehicle cluster assigned), unassigned GFAs (if available) */
static void HLAFMatrixGFA_AssignUnusedVC2LostGFA( const HLAFMatrixData_t *pData,
                                                  HLAFMatrixGFA_VehCluster_t *pVC
                                                )
{
  uint8 iVCnew;

  for(iVCnew=0; iVCnew<pVC->nVC_Max; iVCnew++)
  {
    /* used GFA and not assigned ? */
    if(    (    (pVC->VC[iVCnew].BndryLeft_Status == RTE_HLAF_OBJSTA_PREC_OBJ)
             || (pVC->VC[iVCnew].BndryLeft_Status == RTE_HLAF_OBJSTA_ONC_OBJ)
           )
        && (pVC->VC[iVCnew].Assignment_VC2GFA == UI8_T_MAX)
      )
    {
      /* search oldest unassigned GFA */
      uint8 iGFA;
      uint8 iGFA_bestMatch = UI8_T_MAX;
      float32 dTime_bestMatch = 0.0f;

      for(iGFA=0; iGFA<pData->Matrix.GFA.nGFA; iGFA++)
      {
        if(pVC->Assignment_GFA2VC[iGFA] == UI8_T_MAX)
        {
          /* not assigned */
          if(pData->Matrix.GFA.GFA[iGFA].Int.TimerNoVeh_s >= dTime_bestMatch)
          {
            dTime_bestMatch = pData->Matrix.GFA.GFA[iGFA].Int.TimerNoVeh_s;
            iGFA_bestMatch = iGFA;
          }
        }
      }
      if(iGFA_bestMatch < RTE_HLAF_MATRIX_MAX_NUM_GLARE_FREE_AREAS)
      {
        pVC->VC[iVCnew].Assignment_VC2GFA = iGFA_bestMatch;
        pVC->Assignment_GFA2VC[iGFA_bestMatch] = iVCnew;
      }
    }
  }
}


/* 7. update GFA assignment of objects */
/*    (-> pData->Object[iObj].GFA)     */
static void HLAFMatrixGFA_UpdateObjAssignment2GFA( const HLAF_t_RequiredInputs *ps_In,
                                                   const HLAFMatrixGFA_VehCluster_t *pVC,
                                                   HLAFMatrixData_t *pData
                                                 )
{
  uint8 iObj;


  for(iObj=0; iObj < CML_Min(ps_In->s_Sig.ps_ObjectList->ui32_NumVehicles, RTE_HLAR_OBJECT_LIST_LENGTH); iObj++)
  {
    pData->Object[iObj].GFA = pVC->VC[pData->Object[iObj].GFA].Assignment_VC2GFA;
  }
} 


/* 8. update object links in GFAs */
static void HLAFMatrixGFA_UpdateGFAObjLinks( const HLAF_t_RequiredInputs *ps_In,
                                             HLAFMatrixData_t *pData
                                           )
{
  uint8 iGFA;


  for(iGFA=0; iGFA<pData->Matrix.GFA.nGFA; iGFA++)
  {
    uint8 iObj;
    uint8 iObj_prev = UI8_T_MAX;


    pData->Matrix.GFA.GFA[iGFA].Int.ObjID = UI8_T_MAX;

    /* search for objects for current GFA and update object links in GFA */
    for(iObj=0; iObj < CML_Min(ps_In->s_Sig.ps_ObjectList->ui32_NumVehicles, RTE_HLAR_OBJECT_LIST_LENGTH); iObj++)
    {
      if(pData->Object[iObj].GFA == iGFA)
      {
        /* object of current GFA */
        if(iObj_prev >= RTE_HLAR_OBJECT_LIST_LENGTH)
        {
          /* first object in list */
          pData->Matrix.GFA.GFA[iGFA].Int.ObjID = iObj;
          /* reset no vehicle timer */
          pData->Matrix.GFA.GFA[iGFA].Int.TimerNoVeh_s = 0.0f;
        }
        else
        {
          /* not the first object in list */
          pData->Object[iObj_prev].ObjNext = iObj;
        }      
        iObj_prev = iObj;
      }
    }
  }
}


/* 9. update GFA data like boundaries, TTBs, closest object, ... */
/* #define HLAF_MATRIX_GFA_TTB_HYSTERESIS 0.5 */ /* 0.5sec */
#define HLAF_MATRIX_GFA_TTB_MAX 10.0f /* 10sec */
#define HLAF_MATRIX_GFA_TTB_MIN  0.0f /*  0sec */
/* #define HLAF_MATRIX_GFA_DX_MIN  2 */ /*  pixel */
/* #define HLAF_MATRIX_GFA_DX_LP_MIN  1 */ /*  pixel */
static void HLAFMatrixGFA_UpdateGFAData( const HLAF_t_RequiredInputs  *ps_In,
                                         HLAFMatrixData_t      *pData
                                       )
{
  uint8 iGFA;


  /* analyse all GFAs and set description data */
  for(iGFA = 0; iGFA < CML_Min(pData->Matrix.GFA.nGFA, RTE_HLAF_MATRIX_MAX_NUM_GLARE_FREE_AREAS); iGFA++)
  {
    HLAFMatrixGFAData_t  *pGFA = &pData->Matrix.GFA.GFA[iGFA];
    uint8 iObj;
    float32 TTB18Left_min  = HLAF_MATRIX_GFA_TTB_MAX;
    float32 TTB18Right_min = HLAF_MATRIX_GFA_TTB_MAX;
    float32 TTB18Left_max  = HLAF_MATRIX_GFA_TTB_MIN;
    float32 TTB18Right_max = HLAF_MATRIX_GFA_TTB_MIN;
    boolean bTTBUpdated = b_FALSE;
    

    iObj = pGFA->Int.ObjID;
    while(iObj < RTE_HLAR_OBJECT_LIST_LENGTH)
    {
      HLA_t_Object *pObj = &ps_In->s_Sig.ps_ObjectList->as_Object[iObj];
      float32 HorObj_Ang_Cam     = atanf((ps_In->s_Sig.ps_ObjectList->s_ObjectFOE.ui16_X - pObj->si16_xcenter)/ps_In->s_Par.ps_CameraParameter->s_FocalLength.f32_y);
      float32 HorObj_Ang         = pObj->f32_ObjectHorAng_rad;
      float32 ObjLower_Ang_Cam   = atanf((float32)(pObj->si16_ycenter - ps_In->s_Sig.ps_ObjectList->s_ObjectFOE.ui16_Y)/ps_In->s_Par.ps_CameraParameter->s_FocalLength.f32_y);
      float32 Obj_Dist           = 0.005f*(pObj->s_ObjectPos_xw.ui16_distMin_cm + pObj->s_ObjectPos_xw.ui16_distMax_cm);
      float32 Light_Dist         = 0.005f*(pObj->s_LightDist.ui16_distMin_cm + pObj->s_LightDist.ui16_distMax_cm);
      float32 TTB18Left          = 0.001f*pObj->ui16_ttb18_ms;
      float32 TTB18Right         = 0.001f*pObj->ui16_ttb18_ms;
      RTE_HLAF_ObjStatus ObjStatus;

      if(pObj->s_Status.isVehicleOncoming == 1)
      {
        ObjStatus = RTE_HLAF_OBJSTA_ONC_OBJ;
      }
      else 
      {
        ObjStatus = RTE_HLAF_OBJSTA_PREC_OBJ;
      }


#if 0
      /* plausibility check for TTB */
      if(pObj->si16_delta_x < -HLAF_MATRIX_GFA_DX_MIN)
      {
        /* object moves to left side */
        TTB18Right = HLAF_MATRIX_GFA_TTB_MAX;
      }
      else if(pObj->si16_delta_x > HLAF_MATRIX_GFA_DX_MIN)
      {
        /* object moves to right side */
        TTB18Left = HLAF_MATRIX_GFA_TTB_MAX;
      }
      else if(pObj->si16_delta_x_lp < -HLAF_MATRIX_GFA_DX_LP_MIN)
      {
        /* object moves to left side */
        TTB18Right = HLAF_MATRIX_GFA_TTB_MAX;
      }
      else if(pObj->si16_delta_x_lp > HLAF_MATRIX_GFA_DX_LP_MIN)
      {
        /* object moves to right side */
        TTB18Left = HLAF_MATRIX_GFA_TTB_MAX;
      }
      else
      {
        TTB18Left  = HLAF_MATRIX_GFA_TTB_MAX;
        TTB18Right = HLAF_MATRIX_GFA_TTB_MAX;
      }
#endif       
      /* min/max TTB18 */
      if(pObj->ui8_lost_time == 0)
      {
        /* track alive */
        bTTBUpdated = b_TRUE;
        TTB18Left_min  = CML_f_Min(TTB18Left_min,  TTB18Left);
        TTB18Right_min = CML_f_Min(TTB18Right_min, TTB18Right);
        TTB18Left_max  = CML_f_Max(TTB18Left_max,  TTB18Left);
        TTB18Right_max = CML_f_Max(TTB18Right_max, TTB18Right);
      }
      /* min/max TTB18 */

      if(iObj == pGFA->Int.ObjID)
      {
        /* first object in GFA */

        /* left boundary */
        pGFA->Ext.BndryLeft_Ang      = HorObj_Ang;
        pGFA->Ext.BndryLeft_Dist     = Obj_Dist;
        pGFA->Ext.BndryLeft_Ang_Cam  = HorObj_Ang_Cam;
        pGFA->Ext.BndryLeft_Status   = ObjStatus;

        /* right boundary */
        pGFA->Ext.BndryRight_Ang     = HorObj_Ang;
        pGFA->Ext.BndryRight_Dist    = Obj_Dist;
        pGFA->Ext.BndryRight_Ang_Cam = HorObj_Ang_Cam;
        pGFA->Ext.BndryRight_Status  = ObjStatus;

        /* lower boundary */
        pGFA->Ext.BndryLower_Ang_Cam = ObjLower_Ang_Cam;
        pGFA->Ext.BndryLower_Status  = ObjStatus;

        /* closest object distance */
        pGFA->Ext.ClosestObj_Dist    = Obj_Dist;
        pGFA->Ext.ClosestObj_Ang     = HorObj_Ang;
        pGFA->Ext.ClosestObj_Status  = ObjStatus;

        /* min lightning distance */
        pGFA->Ext.MinLight_Dist      = Light_Dist;
        pGFA->Ext.MinLight_Ang       = HorObj_Ang;
        pGFA->Ext.MinLight_Status    = ObjStatus;

        /* max ExistenceProb */
        pGFA->Ext.ExistenceProb = pObj->ui8_ExistenceProb;
      }
      else
      {
        /* not the first object in GFA */

        /* left boundary */
        if(pGFA->Ext.BndryLeft_Ang < HorObj_Ang)
        {
          pGFA->Ext.BndryLeft_Ang      = HorObj_Ang;
          pGFA->Ext.BndryLeft_Dist     = Obj_Dist;
          pGFA->Ext.BndryLeft_Ang_Cam  = HorObj_Ang_Cam;
          pGFA->Ext.BndryLeft_Status   = ObjStatus;
        }


        /* right boundary */
        if(pGFA->Ext.BndryRight_Ang > HorObj_Ang)
        {
          pGFA->Ext.BndryRight_Ang     = HorObj_Ang;
          pGFA->Ext.BndryRight_Dist    = Obj_Dist;
          pGFA->Ext.BndryRight_Ang_Cam = HorObj_Ang_Cam;
          pGFA->Ext.BndryRight_Status  = ObjStatus;
        }

        /* lower boundary */
        if(pGFA->Ext.BndryLower_Ang_Cam < ObjLower_Ang_Cam)
        {
          pGFA->Ext.BndryLower_Ang_Cam = ObjLower_Ang_Cam;
          pGFA->Ext.BndryLower_Status  = ObjStatus;
        }

        /* closest object distance */
        if(pGFA->Ext.ClosestObj_Dist > Obj_Dist)
        {
          pGFA->Ext.ClosestObj_Dist    = Obj_Dist;
          pGFA->Ext.ClosestObj_Ang     = HorObj_Ang;
          pGFA->Ext.ClosestObj_Status  = ObjStatus;
        }

        /* min lightning distance */
        if(pGFA->Ext.MinLight_Dist > Light_Dist)
        {
          pGFA->Ext.MinLight_Dist      = Light_Dist;
          pGFA->Ext.MinLight_Ang       = HorObj_Ang;
          pGFA->Ext.MinLight_Status    = ObjStatus;
        }
        
        /* max. ExistenceProb */
        pGFA->Ext.ExistenceProb = CML_Max(pGFA->Ext.ExistenceProb, pObj->ui8_ExistenceProb);
      }

      /* goto next object in GFA */
      iObj = pData->Object[iObj].ObjNext;
    }

    if(bTTBUpdated == b_TRUE)
    {
      pGFA->Int.TTB18Left_min  = TTB18Left_min;
      pGFA->Int.TTB18Right_min = TTB18Right_min;
      pGFA->Int.TTB18Left_max  = TTB18Left_max;
      pGFA->Int.TTB18Right_max = TTB18Right_max;
    }



#if 0
    /* implement state machine for TTB direction */

    /* save TTB18Left */
    if(    (TTB18Left_min < (TTB18Right_min + HLAF_MATRIX_GFA_TTB_HYSTERESIS))
      && (TTB18Left_min < HLAF_MATRIX_GFA_TTB_MAX)
      )
    {
      /* left edge moves left */
      pGFA->Ext.TTB18Left        = TTB18Left_min;
      pGFA->Ext.TTB18Left_Status = HLAF_TTB18DIR_LEFT;
    }
    else if(TTB18Right_max < HLAF_MATRIX_GFA_TTB_MAX)
    {
      /* left edge moves right */
      pGFA->Ext.TTB18Left        = TTB18Right_max;
      pGFA->Ext.TTB18Left_Status = HLAF_TTB18DIR_RIGHT;
    }
    else
    {
      pGFA->Ext.TTB18Left        = HLAF_MATRIX_GFA_TTB_MAX;
      pGFA->Ext.TTB18Left_Status = HLAF_TTB18DIR_UNKNOWN;
    }

    /* save TTB18Right */
    if(    (TTB18Right_min < (TTB18Left_min + HLAF_MATRIX_GFA_TTB_HYSTERESIS))
      && (TTB18Right_min < HLAF_MATRIX_GFA_TTB_MAX)
      ) 
    {
      /* right edge moves right */
      pGFA->Ext.TTB18Right        = TTB18Right_min;
      pGFA->Ext.TTB18Right_Status = HLAF_TTB18DIR_RIGHT;
    }
    else if(TTB18Left_max < HLAF_MATRIX_GFA_TTB_MAX)
    {
      /* right edge moves left */
      pGFA->Ext.TTB18Right        = TTB18Left_max;
      pGFA->Ext.TTB18Right_Status = HLAF_TTB18DIR_LEFT;
    }
    else
    {
      pGFA->Ext.TTB18Right        = HLAF_MATRIX_GFA_TTB_MAX;
      pGFA->Ext.TTB18Right_Status = HLAF_TTB18DIR_UNKNOWN;
    }
#endif
  }
}


/* 10. delete GFAs with no objects after a certain time or overlapping GFAs */
static void HLAFMatrixGFA_DeleteGFA( const HLAFMatrixParameter_t *pPar,
                                     const HLAFData_t *pFData,
                                     HLAFMatrixData_t *pData
                                   )
{
  uint8 iGFA;


  for(iGFA=0; iGFA<pData->Matrix.GFA.nGFA; iGFA++)
  {
    /* GFA without valid object */
    if(pData->Matrix.GFA.GFA[iGFA].Int.ObjID >= RTE_HLAR_OBJECT_LIST_LENGTH)
    {
      /* overlap with other GFAs ? */
      HLAFMatrixGFA_VehClusterData_t VC0, VC1;
      boolean bOverlapDet = b_FALSE;
      uint32 j;
      float32 TimerNoVeh_Threshold = CML_f_Min(pPar->GFA.KeepGFAMinTime_s, pData->Matrix.GFA.GFA[iGFA].Int.TTB18Left_max);


      VC0.BndryLeft_Ang = pData->Matrix.GFA.GFA[iGFA].Ext.BndryLeft_Ang;
      VC0.BndryLeft_Status = pData->Matrix.GFA.GFA[iGFA].Ext.BndryLeft_Status;
      VC0.BndryRight_Ang = pData->Matrix.GFA.GFA[iGFA].Ext.BndryRight_Ang;
      VC0.BndryRight_Status = pData->Matrix.GFA.GFA[iGFA].Ext.BndryRight_Status;
      VC0.ClosestObj_Dist = pData->Matrix.GFA.GFA[iGFA].Ext.ClosestObj_Dist;
      VC0.ClosestObj_Status = pData->Matrix.GFA.GFA[iGFA].Ext.ClosestObj_Status;

      for(j=0; j<pData->Matrix.GFA.nGFA; j++)
      {
        if(j != iGFA)
        {
          float32 dAng;


          VC1.BndryLeft_Ang = pData->Matrix.GFA.GFA[j].Ext.BndryLeft_Ang;
          VC1.BndryLeft_Status = pData->Matrix.GFA.GFA[j].Ext.BndryLeft_Status;
          VC1.BndryRight_Ang = pData->Matrix.GFA.GFA[j].Ext.BndryRight_Ang;
          VC1.BndryRight_Status = pData->Matrix.GFA.GFA[j].Ext.BndryRight_Status;
          VC1.ClosestObj_Dist = pData->Matrix.GFA.GFA[j].Ext.ClosestObj_Dist;
          VC1.ClosestObj_Status = pData->Matrix.GFA.GFA[j].Ext.ClosestObj_Status;

          dAng = HLAFMatrixGFA_GetOverlapVC2VC( &pPar->ClusterVeh2GFA,
                                                &VC0,
                                                &VC1
                                              );

          if(dAng < 0.0f)
          {
            bOverlapDet = b_TRUE;
          }
        }
      }


      pData->Matrix.GFA.GFA[iGFA].Int.TimerNoVeh_s += pFData->CamData.dtime_s;
      /* delete GFA ? */
      if(    /* GFA not updated over long time */
             (pData->Matrix.GFA.GFA[iGFA].Int.TimerNoVeh_s > TimerNoVeh_Threshold)
             /* no global turn off and keep reason active */
          || (    (pFData->DecisionData.TurnOffReason_glob.Reason.u32 == 0)
               && (pData->KeepOffReason.Reason.u32 == 0)
             )
             /* overlap with other GFA ? */ 
          || (bOverlapDet == b_TRUE)
        )
      {
        /* delete this GFA from array and shift the upper GFA ones downwards */
        /* add objects of deleted GFA to  */
        for(j=iGFA; j<(pData->Matrix.GFA.nGFA-1u); j++)
        {
          memcpy(&pData->Matrix.GFA.GFA[j], &pData->Matrix.GFA.GFA[j+1], sizeof(HLAFMatrixGFAData_t));
        }
        HLAFMatrixGFA_InitData(&pData->Matrix.GFA.GFA[pData->Matrix.GFA.nGFA-1]);
        /* decrease number of GFA */
        pData->Matrix.GFA.nGFA = CML_Max((pData->Matrix.GFA.nGFA-1u), 0u);
      }
      else
      {
        /* keep old GFA */

        /* reset ExistenceProb, because no vehicle is in GFA */
        pData->Matrix.GFA.GFA[iGFA].Ext.ExistenceProb = 0;
      }
    }
  }    
}


/* cluster vehicles to GFAs */
void HLAFMatrixGFAMain( const HLAF_t_RequiredInputs *ps_In,
                         const HLAFMatrixParameter_t *pPar,
                         const HLAFData_t *pFData,
                         HLAFMatrixData_t *pData
                       )
{
  /* build up to "MaxNumGFA" GFAs */
  HLAFMatrixGFA_VehCluster_t VC;
  uint32 MaxNumGFA = CML_MinMax(1, RTE_HLAF_MATRIX_MAX_NUM_GLARE_FREE_AREAS, ps_In->s_Par.s_HlafPar.Matrix.MaxNumGlarefreeArea);
  

  /* 1. init internal data */
  HLAFMatrixGFA_InitInternalData(&VC);

  /* 2. build vehicle clusters (max. RTE_HLAR_OBJECT_LIST_LENGTH GFAs) */
  HLAFMatrixGFA_ClusterVehicles( ps_In,
                                 pPar,
                                 pData,
                                 &VC
                                );

  /* 3. reduce Vehicle Clusters (VC) to max number of GFA (=RTE_HLAF_MATRIX_MAX_NUM_GLARE_FREE_AREAS) */
  HLAFMatrixGFA_ReduceVC2MaxNumGFA( ps_In,
                                    pPar,
                                    pData,
                                    MaxNumGFA,
                                    &VC
                                  );

  /* 4. assign vehicle cluster (VC) to best matching GFAs from previous cycle */
  HLAFMatrixGFA_AssignVC2GFA( pPar,
                              pData,
                              &VC
                             );

  /* 5. assign unused vehicle cluster (VC) to free GFAs (if available) */
  HLAFMatrixGFA_AssignUnusedVC2FreeGFA( pData,
                                        MaxNumGFA,
                                        &VC
                                      );
  
  /* 6. assign unused vehicle cluster (VC) to the oldest, lost(no vehicle cluster assigned), unassigned GFAs (if available) */
  HLAFMatrixGFA_AssignUnusedVC2LostGFA( pData,
                                        &VC
                                      );

  /* 7. update GFA assignment of objects */
  /*    (-> pData->Object[iObj].GFA)     */
  HLAFMatrixGFA_UpdateObjAssignment2GFA( ps_In,
                                         &VC,
                                         pData
                                       );

  /* 8. update object links in GFAs */
  HLAFMatrixGFA_UpdateGFAObjLinks( ps_In,
                                   pData
                                 );

  /* 9. update GFA data like boundaries, TTBs, closest object, ... */
  HLAFMatrixGFA_UpdateGFAData( ps_In,
                               pData
                             );

  /* 10. delete GFAs with no objects after a certain time or overlapping GFAs */
  HLAFMatrixGFA_DeleteGFA( pPar,
                           pFData,
                           pData
                         );
  
}/* PRQA S 861 1 */
