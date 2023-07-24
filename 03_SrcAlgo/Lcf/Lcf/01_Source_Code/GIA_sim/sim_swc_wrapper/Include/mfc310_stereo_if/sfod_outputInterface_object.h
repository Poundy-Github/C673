/*! \file **********************************************************************

  COMPANY:        Continental AG

  PROJECT:        MFC300

  CPU:

  COMPONENT:      SFOD - Stereo Fast Object Detection

  MODULNAME:      sfod_outputInterface_object.h

  DESCRIPTION:    subset of input/output structure handling for SFOD data
                  /temporary interface to SPOD

  AUTHOR:         A. Bachmann

  CREATION DATE:  09.01.2011

  VERSION:

  CHANGES:

**************************************************************************** */

#ifndef SFOD_OUTPUTINTERFACE_OBJECT_H
#define SFOD_OUTPUTINTERFACE_OBJECT_H

#if defined(PC_SIM) && !defined(GUYS_BUILD_MESSAGE_COMPRESSOR)
    #pragma message ("- Including [" __TIMESTAMP__ "] " __FILE__ )
#endif //#ifdef PC_SIM

#define SFOD_MAXNUMOBJS                 32   /*! \brief  maximum number of objects in output list */
#define SFOD_MAXNUMOBJS_TO_FLEXRAY      14   /*! \brief  maximum number of objects in Flex Ray list */

#include "common_interface_defines.h"
#include "cct_type.h"
#include "sfod_outputInterface_baseTypes.h"


#ifdef __cplusplus
  extern "C" {
#endif // __cplusplus

/*****************************************************************************************************************
 * object struct define
 *****************************************************************************************************************/

static const ui32_t SFODObjectList_VersionNumber = 9;      /*!< version of structure SFODObjectList_t */
                                                           /*!< 2: */
                                                           /*!< 3: extended signal list accoring to FROP REL2.4.0 */
                                                           /*!< 4: pedestrian relevant data for REL2.5.0 */
                                                           /*!< 5: PEDCriticalSection added */
                                                           /*!< 6: introduced <SFODObjectRelevancePOD_t>*/
                                                           /*!< 7: introduced <InternalID>*/
                                                           /*!< 8: introduced <PedInternalID>*/
                                                           /*!< 9: introduced <sendToFlexRay>*/


//*! \brief tbd */
typedef struct _SFODObjectList_t
{
  DEFINE_VERSION_MEMBER(SFODObjectList);

  ui32_t   FrameID;                                         /*!< frame ID of input data for synchronisation */

  /* ID, splitflag, mergeflag see Stereo FLH Stereo-797*/
  SFODSignalState_t SignalStateObjectData;                  /*!< OK if data valid, NOK if data invalid */
  ui32_t   ObjID;                                           /*!< object ID */
  i32_t    SplitFlag;                                       /*!< split flag, 0 = false, 1 = true, 2 = SNA */
  i32_t    MergeFlag;                                       /*!< merge flag, 0 = false, 1 = true, 2 = SNA */

  i32_t    ObservedFlag;                                    /*!< object observed in current cycle?  0 = false, 1 = true, 2 = SNA, Stereo-816 */
  SFODObjectRelevancePOD_t    RelevantObjectFlag;           /*!< POD relevance {0,1,2,3} */

  ui32_t   Lifetime;                                        /*!< lifetime of object, Stereo-800, unit frames */

  /* edge flags, Stereo-801 */
  i32_t    EdgeFlagLeft;                                    /*!< edge flag left,  0 = false, 1 = true, 2 = SNA */
  i32_t    EdgeFlagRight;                                   /*!< edge flag right, 0 = false, 1 = true, 2 = SNA */

  /* occlusion flags, Stereo-802 */
  i32_t    OcclusionFlagLeft;                               /*!< occlusion flag left,  0 = false, 1 = true, 2 = SNA */
  i32_t    OcclusionFlagRight;                              /*!< occlusion flag right, 0 = false, 1 = true, 2 = SNA */

  i32_t    ReferencePointIndex;                             /*!< index of reference point for relative velocity, 0, 1, 2 or 3, Stereo-805 */

  /* coordinates of points for object representation, Stereo-806, 807
     in vehicle coordinates */
  f32_t    XLeft_m, YLeft_m;                                 /*!< coordinates of leftmost point [m] */
  f32_t    XRight_m, YRight_m;                               /*!< coordinates of rightmost point [m] */
  f32_t    XInter_m, YInter_m;                               /*!< coordinates of intermediate point [m] */

  f32_t    SigmaX;                                           /*!< standard deviation (1-sigma) for worst of the 3 points in X direction, Stereo-799 */
  f32_t    SigmaY;                                           /*!< standard deviation (1-sigma) for worst of the 3 points in Y direction, Stereo-818 */

  f32_t    HeightBottom_m, HeightTop_m;                      /*!< height above ground of bottom/top edge of object [m] */

  f32_t    Width_m;                                          /*!< width of object [m] */

  f32_t    RelativeVelocityX_ms;                             /*!< relative velocity of one of the reference points in longitudinal direction, Stereo-809 [m/s]*/
  f32_t    SigmaRelVX;                                       /*!< standard deviation (1-sigma) for relative velocity in X direction, Stereo-817 */

  f32_t    RelativeVelocityYLeft_ms, RelativeVelocityYRight_ms; /*!< relative velocity of left/right reference point in lateral direction, Stereo-810 [m/s] */
  f32_t    RelativeVelocityConfidence_percent;               /*!< confidence of relative velocity, Stereo-1002 [%] */
  f32_t    SigmaRelVY;                                       /*!< standard deviation (1-sigma) for relative velocity in Y direction, best of the 2 points, Stereo-1012 */

  f32_t    QualityDisparity_percent;                         /*!< quality of disparities used for object detection, Stereo-814 [%] */
  f32_t    QualityFlow_percent;                              /*!< quality of optical flow used for object detection, Stereo-815 [%] */

  SFODDynamicProperty_e DynamicProperty;

  ui32_t   xTL_px, yTL_px, xBR_px, yBR_px;                      /*!< 2d object bounding box in image coords */

  ui32_t   xLI_b_px, yLI_b_px, xZW_b_px, yZW_b_px, xRE_b_px, yRE_b_px;      /*!< 3d object bounding box in image coords */
  ui32_t   xLI_t_px, yLI_t_px, xZW_t_px, yZW_t_px, xRE_t_px, yRE_t_px;

  ui32_t   Priority;                                           /*!< object priority [1...9] */

  //additional signals for REL 2.4.0
  f32_t    FloxelDensity;
  i32_t    Streetflag;
  i32_t    Tunnelflag;

  //additional signals for REL 2.5.0 + REL 2.5.1
  i8_t    PedFlag;                                 /*!< pedestrian flag, 0 = false, 1 = true, 2 = SNA */
  i8_t    PedQuality;                              /*!< overall quality of the detected pedestrian (0-100%)*/
  i8_t    PedGroupID;                              /*!< group id the ped belongs to*/
  ui8_t   PEDCriticalSection;                      /*!< position relative to the vehicles corridor in 3 classes*/
  ui16_t  PedImgPos_xTL_px,PedImgPos_yTL_px,PedImgPos_xBR_px,PedImgPos_yBR_px;  /*!< debug output: ped box in image coordinates*/

  //additional signals for REL3.1.0 (+PED)
  ui32_t  InternalID;                            /*!< internal object ID, aka obstacle ID */
  i32_t   PedInternalID;                          /*!< internal object ID of PED module, handled internally by PED */

  //additional signals for REL4.5.0
  i32_t   SendToFlexRay;                        /*!< flag that signals, if object needs to be sent to Flex Ray interface*/ 

} SFODObjectList_t;


static const ui32_t SFODObject_VersionNumber = 2;      /*!< version of structure SFODObject_t */
                                                       /*!< 2: extend object list to account for PED specification: #14 => #42 */
//*! \brief tbd */
// ~CodeReview ~ID:dd2927ad22857c2a9a6a424b52ef3db9 ~Reviewer:F.Stein/O.Vogel ~Date:7/4/2012 ~Priority:3 ~Comment:Rename to SFODObjectContainer_t.//B.Ramirez(uid07705) [2012/7/25, 15:37]: Original Prio:1 New Prio:3 Reason:Agree, but topic is not Prio1
typedef struct _SFODObject_t
{
  DEFINE_VERSION_MEMBER(SFODObject);

  ui8_t             NumberOfObjects_ui8;                  /*!< number of valid objects in output list */
  SFODObjectList_t  SFODObject[SFOD_MAXNUMOBJS];          /*!< List of object descriptions */

} SFODObject_t;


#ifdef __cplusplus
  }
#endif // __cplusplus

#endif /* SFOD_OUTPUTINTERFACE_OBJECT_H */

