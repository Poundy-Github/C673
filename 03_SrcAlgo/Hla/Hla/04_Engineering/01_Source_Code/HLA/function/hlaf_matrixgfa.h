/*! @file ******************************************************************
  COMPANY:                Continental AG, BU ADAS, A.D.C. GmbH
 
  PROJECT:                MFC4xx

  COMPONENT:              HLA

  MODULNAME:              hlaf_matrixgfa.h

  DESCRIPTION:            HLA matrix beam function.
                          Module clusters the vehicle lights to a desired number of glare free areas (1..5).

  CREATION DATE:          2013-03-07
  
  CPU:                    Independent

  VERSION:                $Revision: 1.7 $
**************************************************************************** */

/* avoid cyclic binding -----------------------------------------------------*/
#ifndef H_HLAF_MATRIXGFA_H
#define H_HLAF_MATRIXGFA_H

/*****************************************************************************
  INCLUDES
*****************************************************************************/
#include "hlaf_type.h"
#include "HLA_MatrixParameters.h"

/*****************************************************************************
  SYMBOLIC CONSTANTS 
*****************************************************************************/


/*****************************************************************************
  TYPEDEFS 
*****************************************************************************/
/// \brief Matrix GFA vehicle cluster data
typedef struct
{
  float32 BndryLeft_Ang;                ///< Left boundary angle
  float32 BndryRight_Ang;               ///< Right boundary angle
  float32 ClosestObj_Dist;              ///< closest object distance
  RTE_HLAF_ObjStatus BndryLeft_Status;  ///< object status of left boundary: no obj, oncoming, preceding vehicle
  RTE_HLAF_ObjStatus BndryRight_Status; ///< object status of left boundary: no obj, oncoming, preceding vehicle
  RTE_HLAF_ObjStatus ClosestObj_Status; ///< closest object status: no obj, oncoming, preceding vehicle
  uint8 Assignment_VC2GFA;              ///< GFA assignment: VC 2 previous GFA
} HLAFMatrixGFA_VehClusterData_t; /* VehCluster = VC */

/// \brief Matrix GFA vehicle cluster
typedef struct  
{
  HLAFMatrixGFA_VehClusterData_t VC[LSD_LIGHT_OBJECT_LIST_LENGTH];    ///< Vehicle cluster data array
  uint8 nVC_Max;                                                      ///< number of vehicle cluster before reduction to max number of GFAs
  uint8 nVC;                                                          ///< current number of vehicle clusters
  uint8 Assignment_GFA2VC[RTE_HLAF_MATRIX_MAX_NUM_GLARE_FREE_AREAS];  ///< GFA assignment: GFA 2 Vehicle Cluster (VC)
}HLAFMatrixGFA_VehCluster_t; /* VehCluster = VC */


/*****************************************************************************
  GLOBAL FUNCTION DECLARATIONS 
*****************************************************************************/
/** ************************************************************************************************
  \brief
    Initializing structure for HLA glare free areas.
  
  \pre
    None

  \post
    None

  \param [in,out]  pGFA  Pointer to glare free areas

  \return
    Void

  \globals
    None

  \InOutCorrelation
    The GFAs in the matrix data struct are initialized to zero by a memset and then setting every
    status to no object and every object ID to UI8_T_MAX.\n
    The internal object ID is set to LSD_LIGHT_OBJECT_LIST_LENGTH. The number of GFAs is set to zero and
    the GFA status to init. The internal object list is also memset to zero, then ObjNext, LiObjID,
    LiObjIDPair and GFA of every object are set to UI8_T_MAX.

    @startuml
    title HLAF GFA init function

    start
    :memset every GFA;
    :Set every status of every GFA to no object;
    :Set every ID of every GFA to UI8_T_MAX;
    :Set internal object ID of every GFA to LSD_LIGHT_OBJECT_LIST_LENGTH;
    :Set number of GFAs to zero;
    :Set GFA status to init;
    end

    @enduml

  \callsequence
    @startuml 
    title Sequence diagram of HLAFMatrixGFA_Init()

    box "Function" #LightGreen
    participant hlaf_matrix.c       as Main
    participant hlaf_matrixgfa.c    as this
    end box

    autonumber "<b>[00]"
    Main ->> this: ""**HLAFMatrix_Init()\HLAFMatrix_Main()**"" calls\n""**HLAFMatrixGFA_Init()**""
    Activate this
    this ->> this: Internal GFA data is initialized
    this -->> Main: void
    Deactivate this
    @enduml
  
  \testmethod
    Module Test

  \traceability
***************************************************************************************************/
void HLAFMatrixGFA_Init( HLAFMatrixGFA_t* const pGFA );

/** ************************************************************************************************
  \brief
    Glare free areas are clusters of vehicles that should not be blinded by the high beam. Function
    will control how the vehicles are clustered to the various areas.\n

    @startuml
    title HLAF GFA main function

    start
    :initialize vehicle cluster;
    :build vehicle clusters;
    :reduce Vehicle Clusters to max number of GFA;
    :assign vehicle cluster to best matching GFAs from previous cycle;
    :assign unused vehicle cluster to free GFAs (if available);
    :assign unused vehicle cluster to the oldest, lost (no vehicle cluster assigned), unassigned GFAs (if available);
    :update GFA assignment of objects;
    :update object links in GFAs;
    :update GFA data like boundaries, TTBs, closest object, ...;
    :delete GFAs with no objects after a certain time or overlapping GFAs;
    end

    @enduml
  
  \pre
    None

  \post
    GFA Data was updated.

  \param [in]     pReqPorts  Pointer to ReqPorts
  \param[in]      pPar       Pointer to matrix parameters
  \param[in]      pFData     Pointer to HLA function data
  \param[in,out]  pData      Pointer to HLA matrix data

  \return
    Void

  \globals
    None

  \InOutCorrelation
    The basic idea is that all light objects are grouped into vehicle clusters. A vehicle cluster is
    defined by a left, right and lower border. Depending on how close objects are together are new
    cluster is created or they are added to a pre-existing cluster.\n
    In a next step the vehicle clusters are reduced to the maximum number of GFAs, which is a coding
    parameter.\n
    Vehicle clusters are assigned to the best matching glare free areas from previous cycle by creating
    a temporary vehicle cluster from the existing glare free area and calculating the overlap.\n
    Then unused vehicle clusters are assigned to free glare free areas if there are any available.\n
    After that unused vehicle clusters are assigned to the oldest, lost (no vehicle cluster assigned)
    and unassigned glare free areas if there are any available.\n
    For every object in the internal object list the  glare free area assignment is updated
    (pData->Object[iObj].GFA is set for every object).\n
    Then the linkage of the objects within a glare free area is updated.\n
    Finally for every glare free area the internal data is updated by looping over every objects
    within the glare free area and setting things like left, right, lower border and the corresponding
    statuses.\n
    As a last step glare free areas with no objects are deleted after a certain time.\n

  \callsequence
    @startuml 
    title Sequence diagram of HLAFMatrixGFA_Main()

    box "Function" #LightGreen
    participant hlaf_matrix.c       as Main
    participant hlaf_matrixgfa.c    as this
    end box

    autonumber "<b>[00]"
    Main ->> this: ""**HLAFMatrix_Main()**"" calls\n""**HLAFMatrixGFA_Main()**""
    Activate this
    this ->> this: Init internal data \ncalls HLAFMatrixGFA_InitInternalData()
    this ->> this: build vehicle clusters \ncalls HLAFMatrixGFA_ClusterVehicles()
    this ->> this: reduce Vehicle Clusters to max number of GFA \ncalls HLAFMatrixGFA_ReduceVC2MaxNumGFA()
    this ->> this: assign vehicle cluster to best matching GFAs from previous cycle \ncalls HLAFMatrixGFA_AssignVC2GFA()
    this ->> this: assign unused vehicle cluster to free GFAs \ncalls HLAFMatrixGFA_AssignUnusedVC2FreeGFA()
    this ->> this: assign unused vehicle cluster to the oldest, lost (no vehicle cluster assigned), unassigned GFAs \ncalls HLAFMatrixGFA_AssignUnusedVC2LostGFA()
    this ->> this: update GFA assignment of objects \ncalls HLAFMatrixGFA_UpdateObjAssignment2GFA()
    this ->> this: update object links in GFAs \ncalls HLAFMatrixGFA_UpdateGFAObjLinks()
    this ->> this: update GFA data like boundaries, TTBs, closest object, ... \ncalls HLAFMatrixGFA_UpdateGFAData()
    this ->> this: delete GFAs with no objects after a certain time or overlapping GFAs \ncalls HLAFMatrixGFA_DeleteGFA()
    this -->> Main: void
    Deactivate this
    @enduml
  
  \testmethod
    Module Test

  \traceability
***************************************************************************************************/
void HLAFMatrixGFA_Main( const reqHlaPrtList_t*    const pReqPorts,
                         const t_MatrixParameters* const pPar,
                         const HLAFData_t*         const pFData,
                               HLAFMatrixData_t*   const pData
                       );

/* avoid cyclic binding -----------------------------------------------------*/
#endif /* #ifndef H_HLAF_MATRIXGFA_H */ 
