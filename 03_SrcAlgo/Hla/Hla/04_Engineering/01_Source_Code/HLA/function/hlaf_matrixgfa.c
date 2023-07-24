/*! @file ******************************************************************
  COMPANY:                Continental AG, BU ADAS, A.D.C. GmbH
 
  PROJECT:                MFC4xx

  COMPONENT:              HLA

  MODULNAME:              hlaf_matrixgfa.c

  DESCRIPTION:            HLA matrix beam function.
                          Module clusters the vehicle lights to a desired number of glare free areas (1..5).

  CREATION DATE:          2013-03-07
  
  CPU:                    Independent

  VERSION:                $Revision: 1.26 $
**************************************************************************** */

/*****************************************************************************
  INCLUDES
*****************************************************************************/
#include <string.h>
#include "hlaf_type.h"
#include "hlaf_matrix.h"
#include "hlaf_matrixgfa.h"


/*****************************************************************************
  SYMBOLIC CONSTANTS 
*****************************************************************************/
/* #define HLAF_MATRIX_GFA_TTB_HYSTERESIS 0.5 */ /* 0.5sec */
#define HLAF_MATRIX_GFA_TTB_MAX 10.0f ///< \brief maximum time threshold for time to border \phys_unit s
#define HLAF_MATRIX_GFA_TTB_MIN  0.0f ///< \brief minimum time threshold for time to border \phys_unit s
/* #define HLAF_MATRIX_GFA_DX_MIN  2 */ /*  pixel */
/* #define HLAF_MATRIX_GFA_DX_LP_MIN  1 */ /*  pixel */

/*****************************************************************************
  LOCAL TYPEDEFS 
*****************************************************************************/


/*****************************************************************************
  GLOBAL VARIABLES 
*****************************************************************************/


/*****************************************************************************
  LOCAL FUNCTION DECLARATIONS
*****************************************************************************/
/* init one GFA */
static void HLAFMatrixGFA_InitData( HLAFMatrixGFAData_t* const pData );

HLA_GLOBAL_STATIC void HLAFMatrixGFA_AddObj2VC( const HLAObjectDataInt_t*             const pIntObj,
                                                      HLAFMatrixGFA_VehClusterData_t* const pVC
                                              );

HLA_GLOBAL_STATIC void HLAFMatrixGFA_MergeVC( const HLAFMatrixGFA_VehClusterData_t* const pVC,
                                                    HLAFMatrixGFA_VehClusterData_t* const pVCmerged
                                            );

HLA_GLOBAL_STATIC float32 HLAFMatrixGFA_GetOverlapVC2VC(const t_MatrixParametersClusterVeh2GFA* const pPar,
                                                        const HLAFMatrixGFA_VehClusterData_t*   const pVC0,
                                                        const HLAFMatrixGFA_VehClusterData_t*   const pVC1
                                                       );

static float32 HLAFMatrixGFA_GetOverlapVC2Obj( const t_MatrixParameters*             const pPar,
                                               const HLAFMatrixGFA_VehClusterData_t* const pVC,
                                               const HLAObjectDataInt_t*             const pObj0,
                                               const HLAObjectDataInt_t*             const pObj1
                                             );

static void HLAFMatrixGFA_InitVehCluster( HLAFMatrixGFA_VehClusterData_t* const pVC );

static void HLAFMatrixGFA_InitInternalData( HLAFMatrixGFA_VehCluster_t* const pVC );

static void HLAFMatrixGFA_ClusterVehicles(const t_MatrixParameters*         const pPar,
                                                HLAFMatrixData_t*           const pData,
                                                HLAFMatrixGFA_VehCluster_t* const pVC
                                         );

HLA_GLOBAL_STATIC void HLAFMatrixGFA_MergeOverlappingVC( const t_MatrixParameters*         const pPar,
                                                         const uint32                            numRelVehicles,
                                                               HLAFMatrixData_t*           const pData,
                                                               HLAFMatrixGFA_VehCluster_t* const pVC
                                                       );

HLA_GLOBAL_STATIC void HLAFMatrixGFA_ReduceVC2MaxNumGFA(const t_MatrixParameters*         const pPar,
                                                        const uint32                            MaxNumGFA,
                                                        const uint32                            numRelVehicles,
                                                              HLAFMatrixData_t*           const pData,
                                                              HLAFMatrixGFA_VehCluster_t* const pVC
                                                       );

HLA_GLOBAL_STATIC void HLAFMatrixGFA_AssignVC2GFA(const t_MatrixParameters*         const pPar,
                                                  const HLAFMatrixData_t*           const pData,
                                                        HLAFMatrixGFA_VehCluster_t* const pVC
                                                 );

HLA_GLOBAL_STATIC void HLAFMatrixGFA_AssignUnusedVC2FreeGFA(      HLAFMatrixData_t*           const pData,
                                                            const uint32                            MaxNumGFA,
                                                                  HLAFMatrixGFA_VehCluster_t* const pVC
                                                           );

HLA_GLOBAL_STATIC void HLAFMatrixGFA_AssignUnusedVC2LostGFA(const HLAFMatrixData_t*           const pData,
                                                                  HLAFMatrixGFA_VehCluster_t* const pVC
                                                           );

static void HLAFMatrixGFA_UpdateObjAssignment2GFA( const uint32                            numRelVehicles,
                                                   const HLAFMatrixGFA_VehCluster_t* const pVC,
                                                         HLAFMatrixData_t*           const pData
                                                  );

static void HLAFMatrixGFA_UpdateGFAObjLinks( const uint32                  numRelVehicles,
                                                   HLAFMatrixData_t* const pData
                                            );

HLA_GLOBAL_STATIC void HLAFMatrixGFA_UpdateGFAData( const LSD_LightObjectList_t* const pObjectList,
                                                    const LSD_LightList_t*       const pLightList,
                                                    const t_MatrixParameters*    const pPar,
                                                    const float32                      focalLenghtY,
                                                          HLAFMatrixData_t*      const pData
                                                  );

HLA_GLOBAL_STATIC void HLAFMatrixGFA_DeleteGFA( const t_MatrixParameters* const pPar,
                                                const HLAFData_t*         const pFData,
                                                      HLAFMatrixData_t*   const pData
                                              );


/****************************************************************************
 * GLOBAL FUNCTION DEFINTIONS
*****************************************************************************/

/* *******************************************************************************
  Initializing structure for HLA glare free areas
******************************************************************************** */
void HLAFMatrixGFA_Init( HLAFMatrixGFA_t* const pGFA )
{
  uint32 i;

  for(i = 0u; i < (uint32)RTE_HLAF_MATRIX_MAX_NUM_GLARE_FREE_AREAS; i++)
  {
    /* <ArrayOOBCheck> 2016-04-20 */ /* M.Rameez: i is less than the size of pGFA->GFA (RTE_HLAF_MATRIX_MAX_NUM_GLARE_FREE_AREAS) */
    HLAFMatrixGFA_InitData( &pGFA->GFA[i] );
  }

  pGFA->nGFA = 0u;
  pGFA->GFAStatus = RTE_HLAF_SIGSTAT_INIT;
}

/****************************************************************************
 * LOCAL FUNCTION DEFINTIONS
 *****************************************************************************/

/* *******************************************************************************
  @fn             HLAFMatrixGFA_InitData                                     */ /*!

  @brief          Initializes an HLA glare free area

  @description    Sets an HLA glare free area in init state

  @param[in,out]  pData Pointer to glare free area data

  @return         void
******************************************************************************** */
static void HLAFMatrixGFA_InitData( HLAFMatrixGFAData_t* const pData )
{
  /* PRQA S 0315 1 # 2019-05-06 A.Manz: Implicit conversion intended, only way how this is working */
  (void)memset(pData, 0, sizeof(*pData));

  pData->Int.ObjID             = LSD_LIGHT_OBJECT_LIST_LENGTH;
  pData->Ext.BndryLeft_Status  = RTE_HLAF_OBJSTA_NO_OBJ;
  pData->Ext.BndryRight_Status = RTE_HLAF_OBJSTA_NO_OBJ;
  pData->Ext.BndryUpper_Status = RTE_HLAF_OBJSTA_NO_OBJ;
  pData->Ext.BndryLower_Status = RTE_HLAF_OBJSTA_NO_OBJ;
  pData->Ext.ClosestObj_Status = RTE_HLAF_OBJSTA_NO_OBJ;
  pData->Ext.MinLight_Status   = RTE_HLAF_OBJSTA_NO_OBJ;
  pData->Ext.ttb18Left_Status  = RTE_HLAF_TTBSTA_NO_OBJ;
  pData->Ext.ttb18Right_Status = RTE_HLAF_TTBSTA_NO_OBJ;
  pData->Ext.BndryLeft_ObjId   = UI8_T_MAX;
  pData->Ext.BndryRight_ObjId  = UI8_T_MAX;
  pData->Ext.BndryUpper_ObjId  = UI8_T_MAX;
  pData->Ext.BndryLower_ObjId  = UI8_T_MAX;
  pData->Ext.MinLight_ObjId    = UI8_T_MAX;
  pData->Ext.ClosestObj_ObjId  = UI8_T_MAX;
}

/* *******************************************************************************
  @fn             HLAFMatrixGFA_AddObj2VC                                    */ /*!

  @brief          Adds a vehicle to a given vehicle cluster

  @description    Adds the provided vehicle to a given vehicle cluster and updates
                  the cluster with the new gained data.

  @param[in]      pIntObj  Pointer to current object
  @param[in,out]  pVC      Pointer to vehicle cluster

  @return         void
******************************************************************************** */
HLA_GLOBAL_STATIC void HLAFMatrixGFA_AddObj2VC( const HLAObjectDataInt_t*             const pIntObj,
                                                      HLAFMatrixGFA_VehClusterData_t* const pVC
                                              )
{
  float32 Obj_Dist;
  float32 angLeft, angRight;

  /* get pointer to associated light object */
  const LSD_LightObject_t* pObj = pIntObj->pLightObject;

  if(pObj != NULL)
  {
    Obj_Dist = pObj->kinematic.world.x;

    /* Calculate left angle of object */
    angLeft  = pIntObj->leftAng;
    /* Calculate right angle of object */
    angRight = pIntObj->rightAng;

    if(pVC != NULL)
    {
      /* GFA used ? */
      if(   (pVC->BndryLeft_Status == (uint8)RTE_HLAF_OBJSTA_PREC_OBJ)
         || (pVC->BndryLeft_Status == (uint8)RTE_HLAF_OBJSTA_ONC_OBJ)
        )
      {
        /* Check if oncoming object */
        if(pIntObj->bIsRelevantOnc == b_TRUE)
        {
          if(angLeft > pVC->BndryLeft_Ang)
          {
            pVC->BndryLeft_Ang    = angLeft;
            pVC->BndryLeft_Status = RTE_HLAF_OBJSTA_ONC_OBJ;
          }

          if(angRight < pVC->BndryRight_Ang)
          {
            pVC->BndryRight_Ang    = angRight;
            pVC->BndryRight_Status = RTE_HLAF_OBJSTA_ONC_OBJ;
          }

          if(Obj_Dist < pVC->ClosestObj_Dist)
          {
            pVC->ClosestObj_Dist   = Obj_Dist;
            pVC->ClosestObj_Status = RTE_HLAF_OBJSTA_ONC_OBJ;
          }
        }
        else if(pIntObj->bIsRelevantPrec == b_TRUE)
        {
          if(angLeft > pVC->BndryLeft_Ang)
          {
            pVC->BndryLeft_Ang    = angLeft;
            pVC->BndryLeft_Status = RTE_HLAF_OBJSTA_PREC_OBJ;
          }

          if(angRight < pVC->BndryRight_Ang)
          {
            pVC->BndryRight_Ang    = angRight;
            pVC->BndryRight_Status = RTE_HLAF_OBJSTA_PREC_OBJ;
          }

          if(Obj_Dist < pVC->ClosestObj_Dist)
          {
            pVC->ClosestObj_Dist   = Obj_Dist;
            pVC->ClosestObj_Status = RTE_HLAF_OBJSTA_PREC_OBJ;
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

        // Assumption is that only vehicles will be checked. Satisfied through loop from which this function is called
        if(pIntObj->bIsRelevantOnc == b_TRUE)
        {
          pVC->BndryLeft_Ang     = angLeft;
          pVC->BndryLeft_Status  = RTE_HLAF_OBJSTA_ONC_OBJ;
          pVC->BndryRight_Ang    = angRight;
          pVC->BndryRight_Status = RTE_HLAF_OBJSTA_ONC_OBJ;
          pVC->ClosestObj_Dist   = Obj_Dist;
          pVC->ClosestObj_Status = RTE_HLAF_OBJSTA_ONC_OBJ;
        }
        else if(pIntObj->bIsRelevantPrec == b_TRUE)
        {
          pVC->BndryLeft_Ang     = angLeft;
          pVC->BndryLeft_Status  = RTE_HLAF_OBJSTA_PREC_OBJ;
          pVC->BndryRight_Ang    = angRight;
          pVC->BndryRight_Status = RTE_HLAF_OBJSTA_PREC_OBJ;
          pVC->ClosestObj_Dist   = Obj_Dist;
          pVC->ClosestObj_Status = RTE_HLAF_OBJSTA_PREC_OBJ;
        }
        else
        {
          /* Do nothing */
        }
      }
    }
  }
}


/* *******************************************************************************
  @fn             HLAFMatrixGFA_MergeVC                                      */ /*!

  @brief          Merges two vehicle clusters into one

  @description    Merges two vehicle clusters into one, provided that the to be 
                  merged vehicle cluster is a valid one.

  @param[in]      pVC       Pointer to vehicle cluster that will be merged
  @param[in,out]  pVCmerged Pointer to vehicle cluster that will be merged into

  @return         void
******************************************************************************** */
HLA_GLOBAL_STATIC void HLAFMatrixGFA_MergeVC( const HLAFMatrixGFA_VehClusterData_t* const pVC,
                                                    HLAFMatrixGFA_VehClusterData_t* const pVCmerged
                                            )
{
  if(   (pVC != NULL)
     && (pVCmerged != NULL)
    )
  {
    /* GFA used ? */
    if(   (pVC->BndryLeft_Status == (uint8)RTE_HLAF_OBJSTA_PREC_OBJ)
       || (pVC->BndryLeft_Status == (uint8)RTE_HLAF_OBJSTA_ONC_OBJ)
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


/* *******************************************************************************
  @fn             HLAFMatrixGFA_GetOverlapVC2VC                              */ /*!

  @brief          Calculates the overlap angle between two given vehicle clusters

  @description    Depending on the detected vehicles in the vehicle clusters the 
                  ovverlapping angle between the two clusters is calculated.
                  An angle < 0 implies an overlap

  @param[in]      pPar  Pointer to vehicle cluster parameters
  @param[in]      pVC0  Pointer to first vehicle cluster
  @param[in]      pVC1  Pointer to second vehicle cluster

  @return         Float that holds the overlap angle
******************************************************************************** */
HLA_GLOBAL_STATIC float32 HLAFMatrixGFA_GetOverlapVC2VC( const t_MatrixParametersClusterVeh2GFA* const pPar,
                                                         const HLAFMatrixGFA_VehClusterData_t*   const pVC0,
                                                         const HLAFMatrixGFA_VehClusterData_t*   const pVC1
                                                       )
{
  float32 dAng;
  float32 dAng_Thres;
  float32 Ang0, Ang1;
  const float32 closestObjDist = CML_f_Max(1.0f, CML_f_Min(pVC0->ClosestObj_Dist, pVC1->ClosestObj_Dist));
  RTE_HLAF_ObjStatus Status0, Status1;

  if(   (   (pVC0->BndryLeft_Status == (uint8)RTE_HLAF_OBJSTA_PREC_OBJ)
         || (pVC0->BndryLeft_Status == (uint8)RTE_HLAF_OBJSTA_ONC_OBJ)
        )
     && (   (pVC1->BndryLeft_Status == (uint8)RTE_HLAF_OBJSTA_PREC_OBJ)
         || (pVC1->BndryLeft_Status == (uint8)RTE_HLAF_OBJSTA_ONC_OBJ)
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

    dAng = Ang0 - Ang1; /* dAng < 0: overlap */
                        /* dAng > 0: no overlap */

    if(   (Status0 == (uint8)RTE_HLAF_OBJSTA_PREC_OBJ)
       && (Status1 == (uint8)RTE_HLAF_OBJSTA_PREC_OBJ)
      )
    {
      /* <DivByZeroCheck> 2016-06-28 # 2019-05-28 M.Mutschler: closestObjDist is always bigger than 1 cf. initialization at the begging */
      /* preceding with preceding */
      dAng_Thres = CML_f_Max(pPar->dAngPrec, (pPar->WidthPrec/ closestObjDist));
    }
    else if(   (Status0 == (uint8)RTE_HLAF_OBJSTA_ONC_OBJ)
            && (Status1 == (uint8)RTE_HLAF_OBJSTA_ONC_OBJ)
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
    /* PRQA S 3121 1 # 2019-05-28 A.Fischer: Magic number is justified, since this is the max angle */
    dAng = CML_Deg2Rad(90.0f);
  }

  return(dAng);
}


/* *******************************************************************************
  @fn             HLAFMatrixGFA_GetOverlapVC2Obj                             */ /*!

  @brief          Calculates the overlap angle of two objects and a cluster

  @description    The overlap angle will be calculated by adding the two objects
                  to a temporary vehicle cluster and then checking it against the
                  given vehicle cluster.
                  An angle < 0 implies an overlap

  @param[in]      pPar  Pointer to vehicle cluster parameters
  @param[in]      pVC   Pointer to vehicle cluster
  @param[in]      pObj0 Pointer to first object
  @param[in]      pObj1 Pointer to second object

  @return         Float that holds the overlap angle
******************************************************************************** */
static float32 HLAFMatrixGFA_GetOverlapVC2Obj( const t_MatrixParameters*             const pPar,
                                               const HLAFMatrixGFA_VehClusterData_t* const pVC,
                                               const HLAObjectDataInt_t*             const pObj0,
                                               const HLAObjectDataInt_t*             const pObj1
                                             )
{
  HLAFMatrixGFA_VehClusterData_t VC_Obj01; /* GFA of Object 0 and 1 */
  float32 dAng;

  /* PRQA S 0315 1 # 2019-05-06 A.Manz: Implicit conversion intended, only way how this is working */
  (void)memset(&VC_Obj01, 0, sizeof(VC_Obj01));
  
  /* build GFA of Obj0 and Obj1 */
  HLAFMatrixGFA_AddObj2VC( pObj0,
                           &VC_Obj01
                         );

  HLAFMatrixGFA_AddObj2VC( pObj1,
                           &VC_Obj01
                         );
  
  /* check overlap of VC_Obj01 with VC */
  dAng = HLAFMatrixGFA_GetOverlapVC2VC( &pPar->ClusterVeh2GFA,
                                        &VC_Obj01,
                                        pVC
                                      );

  return(dAng);
}


/* *******************************************************************************
  @fn             HLAFMatrixGFA_InitVehCluster                               */ /*!

  @brief          Initializes a vehicle cluster

  @description    Initializes a vehicle cluster

  @param[in]      pVC Pointer to vehicle cluster

  @return         void
******************************************************************************** */
static void HLAFMatrixGFA_InitVehCluster( HLAFMatrixGFA_VehClusterData_t* const pVC )
{
  /* PRQA S 0315 1 # 2019-05-06 A.Manz: Implicit conversion intended, only way how this is working */
  (void)memset( pVC, 0, sizeof(*pVC));
  pVC->Assignment_VC2GFA = UI8_T_MAX;
}


/* *******************************************************************************
  @fn             HLAFMatrixGFA_InitInternalData                             */ /*!

  @brief          Initializes internal vehicle cluster storage structure

  @description    Initializes internal vehicle cluster storage structure

  @param[in,out]  pVC Pointer to vehicle cluster storage structure

  @return         void
******************************************************************************** */
static void HLAFMatrixGFA_InitInternalData( HLAFMatrixGFA_VehCluster_t* const pVC )
{
  uint8 iVC;

  /* Clear GFA to VC assignment */
  for(iVC = 0; iVC < (uint8)RTE_HLAF_MATRIX_MAX_NUM_GLARE_FREE_AREAS; iVC++)
  {
    pVC->Assignment_GFA2VC[iVC] = UI8_T_MAX;
  }

  /* Initialize vehicle cluster */
  for(iVC = 0; iVC < (uint8)LSD_LIGHT_OBJECT_LIST_LENGTH; iVC++)
  {
    HLAFMatrixGFA_InitVehCluster(&pVC->VC[iVC]);
  }

  pVC->nVC = 0;
  pVC->nVC_Max = 0;
}

/* *******************************************************************************
  @fn             HLAFMatrixGFA_AssignVC2GFA                                 */ /*!

  @brief          Step 3: Match vehicle clusters to previous glare free areas

  @description    Assigns vehicle clusters to best matching glare free areas from
                  previous cycle by creating a temporary vehicle cluster from the
                  existing glare free area and calculating the overlap.

  @param[in]      pPar  Pointer to matrix parameters
  @param[in]      pData Pointer to HLA matrix data
  @param[in,out]  pVC   Pointer to vehicle cluster storage structure

  @return         void
******************************************************************************** */
HLA_GLOBAL_STATIC void HLAFMatrixGFA_AssignVC2GFA( const t_MatrixParameters*         const pPar,
                                                   const HLAFMatrixData_t*           const pData,
                                                         HLAFMatrixGFA_VehCluster_t* const pVC
                                                 )
{
  HLAFMatrixGFA_VehClusterData_t VCtemp;
  uint8 iVCnew;
  uint8 iGFA;
  uint8 iGFA_bestMatch;
  float32 dAng_bestMatch;
  float32 dAng;


  for(iVCnew = 0; iVCnew < pVC->nVC_Max; iVCnew++)
  {
    /* used GFA ? */
    /* <ArrayOOBCheck> 2016-04-20 */ /* M.Rameez: pVC->nVC_Max is limited to LSD_LIGHT_OBJECT_LIST_LENGTH which is the size of pVC->VC */
    if(   (pVC->VC[iVCnew].BndryLeft_Status == (uint8)RTE_HLAF_OBJSTA_PREC_OBJ)
       || (pVC->VC[iVCnew].BndryLeft_Status == (uint8)RTE_HLAF_OBJSTA_ONC_OBJ)
      )
    {
      iGFA_bestMatch  = UI8_T_MAX;
      /* PRQA S 3121 1 # 2019-05-28 A.Fischer: magic number is justified since this is max init value */
      dAng_bestMatch  = CML_Deg2Rad(90.0f);
      /* GFA not assigned */

      /* find best match between new GFA and previous GFAs */
      for(iGFA = 0; iGFA < pData->Matrix.GFA.nGFA; iGFA++)
      {
        /* previous GFA not assigned ? */
        /* <ArrayOOBCheck> 2016-04-20 */ /* M.Rameez: pData->Matrix.GFA.nGFA is limited to RTE_HLAF_MATRIX_MAX_NUM_GLARE_FREE_AREAS which is the size of pData->Matrix.GFA.GFA and pVC->Assignment_GFA2VC */
        if(pVC->Assignment_GFA2VC[iGFA] == UI8_T_MAX)
        {
          VCtemp.BndryLeft_Ang      = pData->Matrix.GFA.GFA[iGFA].Ext.BndryLeft_Ang;
          VCtemp.BndryLeft_Status   = pData->Matrix.GFA.GFA[iGFA].Ext.BndryLeft_Status;
          VCtemp.BndryRight_Ang     = pData->Matrix.GFA.GFA[iGFA].Ext.BndryRight_Ang;
          VCtemp.BndryRight_Status  = pData->Matrix.GFA.GFA[iGFA].Ext.BndryRight_Status;
          VCtemp.ClosestObj_Dist    = pData->Matrix.GFA.GFA[iGFA].Ext.ClosestObj_Dist;
          VCtemp.ClosestObj_Status  = pData->Matrix.GFA.GFA[iGFA].Ext.ClosestObj_Status;

          dAng = HLAFMatrixGFA_GetOverlapVC2VC( &pPar->ClusterVeh2GFA,
                                                &VCtemp,
                                                &pVC->VC[iVCnew]
                                              );
          /* PRQA S 3121 1 # 2019-05-28 A.Fischer: 0.0f can not be considered a magic number */
          if(   (dAng < 0.0f)
             && (dAng < dAng_bestMatch)
            )
          {
            dAng_bestMatch = dAng;
            iGFA_bestMatch = iGFA;
          }
        }
      }

      if(iGFA_bestMatch < (uint8)RTE_HLAF_MATRIX_MAX_NUM_GLARE_FREE_AREAS)
      {
        /* save assigned GFA */
        pVC->VC[iVCnew].Assignment_VC2GFA = iGFA_bestMatch;
        pVC->Assignment_GFA2VC[iGFA_bestMatch] = iVCnew;
      }
    }
  }
}


/* *******************************************************************************
  @fn             HLAFMatrixGFA_AssignUnusedVC2FreeGFA                       */ /*!

  @brief          Step 4: Assign unused vehicle clusters to free glare free areas

  @description    Assigns unused vehicle clusters to free glare free areas if there
                  are any available.

  @param[in,out]  pData     Pointer to HLA matrix data
  @param[in]      MaxNumGFA UInt that holds the max number of glare free areas
  @param[in,out]  pVC       Pointer to vehicle cluster storage structure

  @return         void
******************************************************************************* */
HLA_GLOBAL_STATIC void HLAFMatrixGFA_AssignUnusedVC2FreeGFA(      HLAFMatrixData_t*           const pData,
                                                            const uint32                            MaxNumGFA,
                                                                  HLAFMatrixGFA_VehCluster_t* const pVC
                                                           )
{
  uint8 iVCnew;
  uint8 iGFAfree;

  if(pData->Matrix.GFA.nGFA < MaxNumGFA)
  {
    for(iVCnew = 0; iVCnew < pVC->nVC_Max; iVCnew++)
    {
      iGFAfree = pData->Matrix.GFA.nGFA;

      /* used GFA and not assigned ? */
      /* <ArrayOOBCheck> 2016-04-20 */ /* M.Rameez: pVC->nVC_Max is limited to LSD_LIGHT_OBJECT_LIST_LENGTH which is the size of pVC->VC.
                                       iGFAfree < RTE_HLAF_MATRIX_MAX_NUM_GLARE_FREE_AREAS which is the size of pVC->Assignment_GFA2VC */
      if(   (   (pVC->VC[iVCnew].BndryLeft_Status == (uint8)RTE_HLAF_OBJSTA_PREC_OBJ)
             || (pVC->VC[iVCnew].BndryLeft_Status == (uint8)RTE_HLAF_OBJSTA_ONC_OBJ)
            )
         && (pVC->VC[iVCnew].Assignment_VC2GFA == UI8_T_MAX)
         && (iGFAfree < (uint8)RTE_HLAF_MATRIX_MAX_NUM_GLARE_FREE_AREAS)
        )
      {
        pVC->VC[iVCnew].Assignment_VC2GFA = iGFAfree;
        pVC->Assignment_GFA2VC[iGFAfree] = iVCnew;

        pData->Matrix.GFA.nGFA++;
      }
    }
  }
}


/* *******************************************************************************
  @fn             HLAFMatrixGFA_AssignUnusedVC2LostGFA                       */ /*!

  @brief          Step 5: Assign unused vehicle clusters to lost glare free areas

  @description    Assigns unused vehicle clusters to the oldest, lost (no vehicle
                  cluster assigned) and unassigned glare free areas if there are
                  any available.

  @param[in]      pData Pointer to HLA matrix data
  @param[in,out]  pVC   Pointer to vehicle cluster storage structure

  @return         void
******************************************************************************** */
HLA_GLOBAL_STATIC void HLAFMatrixGFA_AssignUnusedVC2LostGFA(const HLAFMatrixData_t*           const pData,
                                                                  HLAFMatrixGFA_VehCluster_t* const pVC
                                                           )
{
  uint8 iVCnew;
  uint8 iGFA;

  uint8 iGFA_bestMatch;
  float32 dTime_bestMatch;

  for(iVCnew = 0; iVCnew < pVC->nVC_Max; iVCnew++)
  {
    /* used GFA and not assigned ? */
    /* <ArrayOOBCheck> 2016-04-20 */ /* M.Rameez: nVC_Max is limited to LSD_LIGHT_OBJECT_LIST_LENGTH which is the size of pVC->VC */
    if(   (   (pVC->VC[iVCnew].BndryLeft_Status == (uint8)RTE_HLAF_OBJSTA_PREC_OBJ)
           || (pVC->VC[iVCnew].BndryLeft_Status == (uint8)RTE_HLAF_OBJSTA_ONC_OBJ)
          )
       && (pVC->VC[iVCnew].Assignment_VC2GFA == UI8_T_MAX)
      )
    {
      /* search oldest unassigned GFA */
      iGFA_bestMatch  = UI8_T_MAX;
      /* PRQA S 3121 1 # 2019-05-28 A.Fischer: 0.0f can not be considered a magic number */
      dTime_bestMatch = 0.0f;

      for(iGFA = 0; iGFA < pData->Matrix.GFA.nGFA; iGFA++)
      {
        /* <ArrayOOBCheck> 2016-04-20 */ /* M.Rameez: pData->Matrix.GFA.nGFA is limited to RTE_HLAF_MATRIX_MAX_NUM_GLARE_FREE_AREAS which
                                         is the size of pVC->Assignment_GFA2VC and pData->Matrix.GFA.GFA */
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

      if(iGFA_bestMatch < (uint8)RTE_HLAF_MATRIX_MAX_NUM_GLARE_FREE_AREAS)
      {
        pVC->VC[iVCnew].Assignment_VC2GFA = iGFA_bestMatch;
        pVC->Assignment_GFA2VC[iGFA_bestMatch] = iVCnew;
      }
    }
  }
}

/* PRQA S 7004 -- */

/* *******************************************************************************
  @fn             HLAFMatrixGFA_DeleteGFA                                    */ /*!

  @brief          Step 9: Delete obsolete glare free areas

  @description    Deletes glare free areas with no objects after a certain time or
                  overlapping glare free areas.

  @param[in]      pPar    Pointer to matrix parameters
  @param[in]      pFData  Pointer to HLA function data
  @param[in,out]  pData   Pointer to HLA matrix data

  @return         void
******************************************************************************** */
HLA_GLOBAL_STATIC void HLAFMatrixGFA_DeleteGFA( const t_MatrixParameters* const pPar,
                                                const HLAFData_t*         const pFData,
                                                      HLAFMatrixData_t*   const pData
                                              )
{
  HLAFMatrixGFA_VehClusterData_t VC0, VC1;
  boolean bOverlapDet;
  boolean bGFADeleted;
  float32 TimerNoVeh_Threshold;
  float32 dAng;
  uint32  j;
  uint8   iGFA = 0u;

  while(iGFA < pData->Matrix.GFA.nGFA)
  {
    bGFADeleted = b_FALSE;
    /* <ArrayOOBCheck> 2016-04-20 */ /* M.Rameez: pData->Matrix.GFA.nGFA is limited to RTE_HLAF_MATRIX_MAX_NUM_GLARE_FREE_AREAS which is the 
                                     size of pData->Matrix.GFA.GFA */
    /* GFA without valid object */
    if(pData->Matrix.GFA.GFA[iGFA].Int.ObjID >= (uint8)LSD_LIGHT_OBJECT_LIST_LENGTH)
    {
      /* overlap with other GFAs ? */
      bOverlapDet = b_FALSE;
      TimerNoVeh_Threshold = CML_f_Min(pPar->GFA.KeepGFAMinTime_s, pData->Matrix.GFA.GFA[iGFA].Int.TTB18Left_max);

      VC0.BndryLeft_Ang     = pData->Matrix.GFA.GFA[iGFA].Ext.BndryLeft_Ang;
      VC0.BndryLeft_Status  = pData->Matrix.GFA.GFA[iGFA].Ext.BndryLeft_Status;
      VC0.BndryRight_Ang    = pData->Matrix.GFA.GFA[iGFA].Ext.BndryRight_Ang;
      VC0.BndryRight_Status = pData->Matrix.GFA.GFA[iGFA].Ext.BndryRight_Status;
      VC0.ClosestObj_Dist   = pData->Matrix.GFA.GFA[iGFA].Ext.ClosestObj_Dist;
      VC0.ClosestObj_Status = pData->Matrix.GFA.GFA[iGFA].Ext.ClosestObj_Status;

      for(j = 0; j < pData->Matrix.GFA.nGFA; j++)
      {
        if(j != iGFA)
        {
          VC1.BndryLeft_Ang     = pData->Matrix.GFA.GFA[j].Ext.BndryLeft_Ang;
          VC1.BndryLeft_Status  = pData->Matrix.GFA.GFA[j].Ext.BndryLeft_Status;
          VC1.BndryRight_Ang    = pData->Matrix.GFA.GFA[j].Ext.BndryRight_Ang;
          VC1.BndryRight_Status = pData->Matrix.GFA.GFA[j].Ext.BndryRight_Status;
          VC1.ClosestObj_Dist   = pData->Matrix.GFA.GFA[j].Ext.ClosestObj_Dist;
          VC1.ClosestObj_Status = pData->Matrix.GFA.GFA[j].Ext.ClosestObj_Status;

          dAng = HLAFMatrixGFA_GetOverlapVC2VC( &pPar->ClusterVeh2GFA,
                                                &VC0,
                                                &VC1
                                              );
          /* PRQA S 3121 1 # 2019-05-28 A.Fischer: 0.0f can not be considered a magic number */
          if(dAng < 0.0f)
          {
            bOverlapDet = b_TRUE;
          }
        }
      }

      pData->Matrix.GFA.GFA[iGFA].Int.TimerNoVeh_s += pFData->CamData.dtime_s;
      /* delete GFA ? */
      if(   /* GFA not updated over long time */
            (pData->Matrix.GFA.GFA[iGFA].Int.TimerNoVeh_s > TimerNoVeh_Threshold)
            /* no global turn off and keep reason active */
         || (   (pFData->DecisionData.TurnOffReason.Reason == 0u)
             && (pFData->DecisionData.KeepOffReason.Reason == 0u)
            )
            /* overlap with other GFA ? */ 
         || (bOverlapDet == b_TRUE)
        )
      {
        /* delete this GFA from array and shift the upper GFA ones downwards */
        /* add objects of deleted GFA to  */
        for(j = iGFA; j < ((uint32)pData->Matrix.GFA.nGFA - 1u); j++)
        {
          /* COU_COV_DISABLE: Defensive programming to make sure that no buffers are overwritten and garbage data is read, respectively. */
          /* PRQA S 0315 1 # 2019-05-06 A.Manz: Implicit conversion intended, only way how this is working */
          (void)memcpy( &pData->Matrix.GFA.GFA[j], &pData->Matrix.GFA.GFA[j + 1u], sizeof(pData->Matrix.GFA.GFA[j]) );
          /* COU_COV_ENABLE */
        }
        HLAFMatrixGFA_InitData(&pData->Matrix.GFA.GFA[pData->Matrix.GFA.nGFA - 1u]);
        /* decrease number of GFA */
        /* COU_COV_DISABLE: 2018-03-12 A.Manz: Defensive programming, nGFA cannot become = 0 before this line */
        pData->Matrix.GFA.nGFA = CML_Max((pData->Matrix.GFA.nGFA - 1u), 0u);
        /* COU_COV_ENABLE */
        /* set flag so counter gets not increased */
        bGFADeleted = b_TRUE;
      }
      else
      {
        /* keep old GFA */
        /* reset ExistenceProb, because no vehicle is in GFA */
        pData->Matrix.GFA.GFA[iGFA].Ext.ExistenceProb = 0u;
      }
    }

    /* check if counter can be increased - in case of a deleted GFA it needs to stay on the same position */ 
    if(bGFADeleted == b_FALSE )
    {
      /* increase counter */
      iGFA++;
    }
  }
}
