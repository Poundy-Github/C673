#ifndef ACDC_FPS_TYPES_INCLUDED
#define ACDC_FPS_TYPES_INCLUDED

#include "acdc_custom_types.h"

#if (ACDC_CFG_SFL)
#include "sfl_ext.h"
#endif


/*----------------------------------------*/
/* TypeDEF for FPS implementation */
/*----------------------------------------*/
typedef uint8 FPSEBA_ObjectMovState_t;
/*! enum for defining the possible object moving states */
typedef uint8 FPSEBA_ObjectCrossingState_t;

#define FPSSQR(x)  ((x)*(x))        ///< Calculating the square (x*x) of a number
#define FPSfABS(x)    CML_f_AbsGen(x)  ///< absolute value for floating point 

/* typedef eClassification_t */
#ifndef   OBJCLASS_POINT
#define OBJCLASS_POINT  (0U)
#endif
#ifndef   OBJCLASS_CAR
#define OBJCLASS_CAR  (1U)
#endif
#ifndef   OBJCLASS_TRUCK
#define OBJCLASS_TRUCK  (2U)
#endif
#ifndef   OBJCLASS_PEDESTRIAN
#define OBJCLASS_PEDESTRIAN  (3U)
#endif
#ifndef   OBJCLASS_MOTORCYCLE
#define OBJCLASS_MOTORCYCLE  (4U)
#endif
#ifndef   OBJCLASS_BICYCLE
#define OBJCLASS_BICYCLE  (5U)
#endif
#ifndef   OBJCLASS_WIDE
#define OBJCLASS_WIDE  (6U)
#endif
#ifndef   OBJCLASS_UNCLASSIFIED
#define OBJCLASS_UNCLASSIFIED  (7U)
#endif
#ifndef   OBJCLASS_OTHER_VEHICLE
#define OBJCLASS_OTHER_VEHICLE (8U)
#endif
/* typedef ODObj_t_DynamicProperty */
    #ifndef ODOBJ_DYNPROP_MOVING
        #define ODOBJ_DYNPROP_MOVING 0U
    #endif
    #ifndef ODOBJ_DYNPROP_STATIONARY
        #define ODOBJ_DYNPROP_STATIONARY 1U
    #endif
    #ifndef ODOBJ_DYNPROP_ONCOMING
        #define ODOBJ_DYNPROP_ONCOMING 2U
    #endif
    #ifndef ODOBJ_DYNPROP_UNKNOWN
        #define ODOBJ_DYNPROP_UNKNOWN 3U
    #endif

#define FPSEBA_CROSS_STATE_UNKNOWN       (FPSEBA_ObjectCrossingState_t)0u  /*!< the object is on crossing*/
#define FPSEBA_CROSS_STATE_NOT_CROSSING  (FPSEBA_ObjectCrossingState_t)1u  /*!< the object is on crossing*/
#define FPSEBA_CROSS_STATE_CROSSING_SOFT (FPSEBA_ObjectCrossingState_t)2u  /*!< the object is on crossing*/
#define FPSEBA_CROSS_STATE_CROSSING      (FPSEBA_ObjectCrossingState_t)3u  /*!< the object is on crossing*/


typedef uint8 eClassification_t;
/*! Object number type for usage as function argument or at points where storage is important (NOT as loop variable in for loops) */
typedef OD_t_ObjNumber  EM_t_ObjNumber;
//typedef struct
//{
//  EM_t_GenEbaObjMovState   aFPSObjCurrMovState[EM_NR_PUBLIC_OBJECTS];
//  EM_t_GenEbaObjMovState   aFPSObjPrevMovState[EM_NR_PUBLIC_OBJECTS];
//}FPSEBA_ObjectMovement_t;

typedef struct
{
	EM_t_GenEbaObjMovState   aFPSObjCurrMovState[EM_N_OBJECTS];
	EM_t_GenEbaObjMovState   aFPSObjPrevMovState[EM_N_OBJECTS];
}FPSEBA_ObjectMovement_t;


/*! Function pointer to FPS EBA Observer Update function */
typedef float32 (*FctPreselEBAObserverUpd_fpt)   (EM_t_ObjNumber ObjNr, boolean bObsFulfilled);
typedef float32 (*FctPreselEBAObserverFusion_fpt)(EM_t_ObjNumber ObjNr, boolean bObsFulfilled, float32 fProb);
typedef void    (*FctPreselEBAObserverInit_fpt)  (EM_t_ObjNumber ObjNr );
/*! Struct to define an FPS EBA Observer */
typedef uint16 FPSEBA_ObsResults_t;
typedef uint8 FPSEBA_ObsGroup_t;

#define  FPS_EBA_OBSGROUP_NONE       (FPSEBA_ObsGroup_t)0
#define  FPS_EBA_OBSGROUP_QUAL       (FPSEBA_ObsGroup_t)1
#define  FPS_EBA_OBSGROUP_INHIB      (FPSEBA_ObsGroup_t)2
#define  FPS_EBA_OBSGROUP_QUAL_INHIB (FPSEBA_ObsGroup_t)3

/*! Length of observer name */
#define FPS_EBA_OBSNAME_LENGTH (12u)
#define COF_NUM_CAM_OBJECTS     12
/* ***********************************************************************/ /*!
  Base Observer Switches
************************************************************************** */
#define FPS_EBA_ENABLE_OBS_OBSERVER           SWITCH_ON
#define FPS_EBA_ENABLE_RCS_OBSERVER           SWITCH_OFF
#define FPS_EBA_ENABLE_POE_OBSERVER           SWITCH_ON
#define FPS_EBA_ENABLE_LFT_OBSERVER           SWITCH_ON
#define FPS_EBA_ENABLE_ROAD_OBSERVER          SWITCH_OFF
#define FPS_EBA_ENABLE_MTF_OBSERVER           SWITCH_OFF
#define FPS_EBA_ENABLE_SHADOW_OBSERVER        SWITCH_OFF
#define FPS_EBA_ENABLE_DEGRADATION_OBSERVER   SWITCH_OFF
#define FPS_EBA_ENABLE_UPDQUAL_OBSERVER       SWITCH_OFF
#define FPS_EBA_ENABLE_LASTUPDATE_OBSERVER    SWITCH_OFF
#define FPS_EBA_ENABLE_LASTUPDATE_FUSION_OBSERVER    SWITCH_OFF
#define FPS_EBA_ENABLE_MOVSAFE_OBSERVER       SWITCH_OFF
#define FPS_EBA_ENABLE_FOV_OBSERVER           SWITCH_ON
#define FPS_EBA_ENABLE_STOPPED_OBSERVER       SWITCH_OFF
#define FPS_EBA_ENABLE_MIRRORGHOST_OBSERVER   SWITCH_OFF
#define FPS_EBA_ENABLE_DRIVEOFFSTAT_OBSERVER  SWITCH_ON
#define FPS_EBA_ENABLE_VRELAMBIG_OBSERVER     SWITCH_OFF

/************************************************************************/
/* Base observer parameters                                             */
/************************************************************************/
/*! Number of base observers */
#define FPS_EBA_NUMBER_OF_BASE_OBSERVERS (  (0                                    ) \
                                          + (FPS_EBA_ENABLE_OBS_OBSERVER          ) \
                                          + (FPS_EBA_ENABLE_RCS_OBSERVER          ) \
                                          + (FPS_EBA_ENABLE_POE_OBSERVER          ) \
                                          + (FPS_EBA_ENABLE_LFT_OBSERVER          ) \
                                          + (FPS_EBA_ENABLE_ROAD_OBSERVER         ) \
                                          + (FPS_EBA_ENABLE_MTF_OBSERVER          ) \
                                          + (FPS_EBA_ENABLE_SHADOW_OBSERVER       ) \
                                          + (FPS_EBA_ENABLE_DEGRADATION_OBSERVER  ) \
                                          + (FPS_EBA_ENABLE_UPDQUAL_OBSERVER      ) \
                                          + (FPS_EBA_ENABLE_LASTUPDATE_OBSERVER   ) \
                                          + (FPS_EBA_ENABLE_MOVSAFE_OBSERVER      ) \
                                          + (FPS_EBA_ENABLE_FOV_OBSERVER          ) \
                                          + (FPS_EBA_ENABLE_STOPPED_OBSERVER      ) \
                                          + (FPS_EBA_ENABLE_MIRRORGHOST_OBSERVER  ) \
                                          + (FPS_EBA_ENABLE_DRIVEOFFSTAT_OBSERVER ) \
                                          + (FPS_EBA_ENABLE_VRELAMBIG_OBSERVER    ) )


#if FPS_EBA_ENABLE_OBS_OBSERVER
#define FPS_EBA_OBS_OBSERVER_FUNCTION       (&FPSEBA_OBS_Observer       )
#define FPS_EBA_OBS_OBSERVER_INIT           (NULL                       )
#define FPS_EBA_OBS_OBSERVER_FUSION         (&FPSEBA_OBS_FusionObserver )
#define FPS_EBA_OBS_OBSERVER_INHIBMASK      (FPS_EBA_INH_ALL            )
#define FPS_EBA_OBS_OBSERVER_GROUP          (FPS_EBA_OBSGROUP_QUAL_INHIB)
#define FPS_EBA_OBS_OBSERVER_THRES          (10u                        )
#define FPS_EBA_OBSTPROB_LOWER_THRESHOLD_FUSED_OBJECT (SWITCH_ON)
#define OD_CONSIDER_STOPPED_THRESHOLD             (80u)
/*! @brief       Minimal probability of existence to increase the observer probability
    @conseq      @incp  Higher POE of the camera object is necessary to get a observer probability above 0
    @typical     85   @min 0   @max 1   */

#define FPS_EBA_OBS_FUSE_MIN_EXPECTED_CAM_POE           (   0.96f)
/*! @brief       Minimal probability of existence to increase the observer probability
    @conseq      @incp  Higher POE of the camera object is necessary to get a observer probability of 1
    @typical     85   @min 0   @max 1   */
#define FPS_EBA_OBS_FUSE_MAX_EXPECTED_CAM_POE           (   0.97f)
/* ***********************************************************************/ /*!
  Obstacle Observer (OBS) Parameters
**************************************************************************** */
/** @cond */
/*! @brief       Obstacle probability pickup threshold for moving objects
    @attention   All changes have to be aligned with the obstacle probability calculation */
#define FPS_EBA_OBSPROB_THRES_MOVE_PICKUP               (      53u)
/*! @brief       Obstacle probability drop threshold for moving objects
    @attention   All changes have to be aligned with the obstacle probability calculation */
#define FPS_EBA_OBSPROB_THRES_MOVE_DROP                 (      51u)
/*! @brief       Obstacle probability pickup threshold for stopped objects
    @general     Stopped objects are handled equally as moving objects in the obstacle probability calculation
    @attention   All changes have to be aligned with the obstacle probability calculation */
#define FPS_EBA_OBSPROB_THRES_STOPPED_PICKUP            FPS_EBA_OBSPROB_THRES_MOVE_PICKUP
/*! @brief       Obstacle probability drop threshold for stopped objects
    @general     Stopped objects are handled equally as moving objects in the obstacle probability calculation
    @attention   All changes have to be aligned with the obstacle probability calculation */
#define FPS_EBA_OBSPROB_THRES_STOPPED_DROP              FPS_EBA_OBSPROB_THRES_MOVE_DROP
/*! @brief       Obstacle probability pickup threshold for stationary objects
    @attention   All changes have to be aligned with the obstacle probability calculation */
#define FPS_EBA_OBSPROB_THRES_STAT_PICKUP               (      60u)
/*! @brief       Obstacle probability drop threshold for stationary objects
    @attention   All changes have to be aligned with the obstacle probability calculation */
#define FPS_EBA_OBSPROB_THRES_STAT_DROP                 (      53u)
/*! @brief       Minimal association probability which is necessary to assume that an object is fused
    @conseq      @incp  Less usecases, better false alert rate
    @typical     95   @min 0   @max 100   */
#define FPS_EBA_OBS_FUSE_MIN_CAM_CONFIRMATION_PROB            95u
/*! @brief       Minimal association probability which is necessary to assume that an object which
                 already fulfilled the obstacle observer is fused
    @conseq      @incp  Less usecases, better false alert rate
    @typical     85   @min 0   @max 1   */
#define FPS_EBA_OBS_FUSE_MIN_CAM_CONFIRMATION_PROB_HYST       90u
/*! @brief       Obstacle probability pickup threshold for stationary objects with camera confirmed
    @attention   All changes have to be aligned with the obstacle probability calculation */
#define FPS_EBA_OBSPROB_STAT_PICKUP_FUSED               (      45u)
/*! @brief       Obstacle probability drop threshold for stationary objects with camera confirmed
    @attention   All changes have to be aligned with the obstacle probability calculation */
#define FPS_EBA_OBSPROB_STAT_DROP_FUSED                 (      38u)
#endif

/* ***********************************************************************/ /*!
  Probability of Existence Observer (PoE) Parameters
**************************************************************************** */
/** @cond */
#if (FPS_EBA_ENABLE_POE_OBSERVER)
/** @endcond */

#define FPS_EBA_POE_OBSERVER_FUNCTION       (&FPSEBA_POE_Observer  )
#define FPS_EBA_POE_OBSERVER_FUSION         (NULL                  )
#define FPS_EBA_POE_OBSERVER_INIT           (NULL                  )
#define FPS_EBA_POE_OBSERVER_INHIBMASK      (FPS_EBA_INH_NONE      )
#define FPS_EBA_POE_OBSERVER_GROUP          (FPS_EBA_OBSGROUP_QUAL )
#define FPS_EBA_POE_OBSERVER_THRES          (10u                   )

/*! @brief       Above this POE the observer probability reaches values above 0
    @typical     0.9   @min 0 @max 1  */
#define FPS_EBA_POE_OBS_MIN_POE_FOR_OBS_PROB    (   0.95F )
/*! @brief       Above this POE the observer probability reaches it´s maximum
    @typical     0.9   @min 0 @max 1  */
#define FPS_EBA_POE_OBS_MAX_POE_FOR_OBS_PROB    (   0.99F )

/** @cond */
#endif /* FPS_EBA_ENABLE_POE_OBSERVER */
/** @endcond */


/* ***********************************************************************/ /*!
  Lifetime Observer (LFT) Parameters
**************************************************************************** */
/** @cond */
#if (FPS_EBA_ENABLE_LFT_OBSERVER)
/** @endcond */
#define FPS_EBA_LFT_OBSERVER_FUNCTION       (&FPSEBA_LFT_Observer                                            )
#define FPS_EBA_LFT_OBSERVER_FUSION         (NULL                                                            )
#define FPS_EBA_LFT_OBSERVER_INIT           (NULL                                                            )
#define FPS_EBA_LFT_OBSERVER_INHIBMASK      ((FPS_EBA_INH_BRAKE_L1|FPS_EBA_INH_BRAKE_L2|FPS_EBA_INH_BRAKE_L3))
#define FPS_EBA_LFT_OBSERVER_GROUP          (FPS_EBA_OBSGROUP_QUAL_INHIB                                     )
#define FPS_EBA_LFT_OBSERVER_THRES          (10u                                                             )
/*! @brief       At specified lifetime the observer probability is increased
    @conseq      @incp  Less usecases, better false alert rate
    @typical     2   @unit cycles   @min 1 */
#define FPS_EBA_LFT_OBS_MIN_LIFETIME            (   2u   )
/*! @brief       At specified lifetime the observer probability reaches the maximum
    @conseq      @incp  Less usecases, better false alert rate
    @typical     6   @unit cycles   @min 1   */
#define FPS_EBA_LFT_OBS_MAX_LIFETIME            (   6u   )
/*! @brief       This is the minimal value set for lifetime observer
    @typical     0.9   @min 0 @max 1  */
#define FPS_EBA_LFT_OBS_MIN_PROB                (   0.3F )
/*! @brief       This is the maximal value reached for lifetime observer
    @typical     0.9   @min 0 @max 1  */
#define FPS_EBA_LFT_OBS_MAX_PROB                (   1.0F )

/** @cond */
#endif /* FPS_EBA_ENABLE_LFT_OBSERVER */
/** @endcond */

/************************************************************************/
/* Update quality observer                                              */
/************************************************************************/
/** @cond */
#if (FPS_EBA_ENABLE_UPDQUAL_OBSERVER)
/** @endcond */
#define FPS_EBA_UPDQUAL_OBSERVER_FUNCTION   (&FPSEBA_UpdateQual_Observer  )
#define FPS_EBA_UPDQUAL_OBSERVER_FUSION     (NULL                         )
#define FPS_EBA_UPDQUAL_OBSERVER_INIT       (NULL                         )
#define FPS_EBA_UPDQUAL_OBSERVER_INHIBMASK  (FPS_EBA_INH_NONE             )
#define FPS_EBA_UPDQUAL_OBSERVER_GROUP      (FPS_EBA_OBSGROUP_QUAL        )
#define FPS_EBA_UPDQUAL_OBSERVER_THRES      (10u                          )
/*! @brief       Above this update quality the observer probability can reach values above 0
    @typical     0.9   @min 0 @max 1*/
#define FPS_EBA_UPDQUAL_OBS_MIN_QUAL_FOR_OBS_PROB   (   0.9F )
/*! @brief       Above this update quality the observer probability reaches its maximum probability
    @typical     0.98   @min 0 @max 1*/
#define FPS_EBA_UPDQUAL_OBS_MAX_QUAL_FOR_OBS_PROB   (   0.98F )

/** @cond */
#endif
/** @endcond */

/************************************************************************/
/* FoV observer                                              */
/************************************************************************/
#if FPS_EBA_ENABLE_FOV_OBSERVER
#define FPS_EBA_FOV_OBSERVER_FUNCTION      (&FPSEBA_FoV_Observer                                                 )
#define FPS_EBA_FOV_OBSERVER_FUSION        (NULL                                                                 )
#define FPS_EBA_FOV_OBSERVER_INIT          (NULL                                                                 )
//#define FPS_EBA_FOV_OBSERVER_INHIBMASK     ((FPS_EBA_INH_ALL) & ~((FPS_EBA_INH_HBA_TBRK | FPS_EBA_INH_HBA_THRD)))
#define FPS_EBA_FOV_OBSERVER_INHIBMASK     (FPS_EBA_INH_NONE													 )  //For FPS .....@Cheng Long
#define FPS_EBA_FOV_OBSERVER_GROUP         (FPS_EBA_OBSGROUP_INHIB                                               )
#define FPS_EBA_FOV_OBSERVER_THRES         (50u                                                                  )

/*! @brief       Below this distance all objects are suppressed by the FoV observer
	@typical     0.5   @unit m     @min 0    */
#define FPS_EBA_FOV_MIN_OBJDIST  (0.5F)

	/*! @brief       maximal object distance to evaluate object using the FoV observer
		@typical     20   @unit m     @min 0    */
#define FPS_EBA_FOV_MAX_OBJDIST  (20.0F)

		/*! @brief       This angle is cut at the edge of FoV, because the detections here are assumed as not that reliable.
			@attention   For EuNCAP18 a minimum FOV of 37� is needed.
			@typical     5   @unit deg */
#define FPS_EBA_FOV_EGDGE_ANGLE   (5.0F)

#endif


#if FPS_EBA_ENABLE_DRIVEOFFSTAT_OBSERVER
#define FPS_EBA_DRIVEOFFSTAT_OBSERVER_FUNCTION     (&FPSEBA_DriveOffStat_Observer                                                        )
#define FPS_EBA_DRIVEOFFSTAT_OBSERVER_FUSION       (NULL                                                                                 )
#define FPS_EBA_DRIVEOFFSTAT_OBSERVER_INIT         (NULL                                                                                 )
//#define FPS_EBA_DRIVEOFFSTAT_OBSERVER_INHIBMASK    ((FPS_EBA_INH_ALL) & ~((FPS_EBA_INH_HBA_TBRK | FPS_EBA_INH_HBA_THRD))                 )
#define FPS_EBA_DRIVEOFFSTAT_OBSERVER_INHIBMASK    (FPS_EBA_INH_NONE																	 )  //For FPS .....@Cheng Long
#define FPS_EBA_DRIVEOFFSTAT_OBSERVER_GROUP        (FPS_EBA_OBSGROUP_INHIB                                                               )
#define FPS_EBA_DRIVEOFFSTAT_OBSERVER_THRES        (50u                                                                                  )

#define FPS_EBA_DRIVEOFFSTAT_EGOVEL_STANDSTILL_THRESH ( 0.1F)
#define FPS_EBA_DRIVEOFFSTAT_MAX_DISTX                (10.0F)
#define FPS_EBA_DRIVEOFFSTAT_MAX_DISTY                ( 5.0F)
#endif

typedef struct FctPreselEBAObserverTag
{
  uint8                           szObsName[ FPS_EBA_OBSNAME_LENGTH ];      /*!< Observer name */
  FctPreselEBAObserverUpd_fpt     fptUpdate;                                /*!< Pointer to the actual observer update function */
  FctPreselEBAObserverFusion_fpt  fptFusion;
  FctPreselEBAObserverInit_fpt    fptInit;
  FPSEBA_ObsGroup_t               uiGroupID;                                /*!< Group of the observer */
  uint8                           uCondFulfilledThres;                      /*!< Quality threshold for a fulfilled observer */
  EM_t_GenEbaInhibit              uInhibitMask;                             /*!< Inhibition Mask */
} FPSEBA_Observer_t;
/* PRQA L:OBSERVER_DEFINES */



/* PRQA S 3211  OBSERVER_ARRAY */
/* PRQA S 3111 OBSERVER_ARRAY */

/* ***********************************************************************/ /*!
  Common Observer Parameters
**************************************************************************** */
/*! @brief       Filter constant for increasing the object quality
    @conseq      @incp  If 1 the internal value will be taken directly
                 @decp  If 0 the value can not increase
    @typical     0.5     @min 0   @max 1   */
#define FPSEBA_QUALITY_FILTERCONSTANT_UP                (        0.5f)
/*! @brief       Filter constant for decreasing the object quality
    @conseq      @incp  If 1 the internal value will be taken directly
                 @decp  If 0 the value can not decrease
    @typical     0.1     @min 0   @max 1   */
#define FPSEBA_QUALITY_FILTERCONSTANT_DOWN              (        0.1f)
/*! Struct to define the FPS Object Quality and inhibition mask for the base part*/
typedef struct
{
  FPSEBA_ObsResults_t             uObserverResults;       /* The results of all observers as bitfield */
  EM_t_GenEbaInhibit              uInhibitMask;           /* The calculated inhibition mask in the base part */
#ifdef EM_SIMU
  float32                        afObsQuality[MAX(FPS_EBA_NUMBER_OF_CUST_OBSERVERS, FPS_EBA_NUMBER_OF_BASE_OBSERVERS)];
  float32                        fObjectQuality;         /* The calculated object quality in the base part*/
#endif
}FPSEBA_ObjQuality_t;

typedef struct
{
  FPSEBA_ObjQuality_t      Quality [EM_N_OBJECTS];
  /* FPSEBA_ObjQualityData_t contains only members of size 2 byte. To force 4 byte alignment of start address for MTS meas freeze, a dummy member of 4 byte alignment has to be added. */
  uint32 uDummy;
} FPSEBA_ObjQualityData_t;

/*! Additional camera sensor object data */
typedef struct {
  uint8  ucVideoID;                               /*!< ID of associated video object */
  uint8  ucVideoIdx;                              /*!< Index of associated video object (will not be cleared every cycle) */
  uint8  ucVideoLastID;                           /*!< ID of last associated video object */
  uint8  uiCurrentVideoIdx;                       /*!< Index of current video target */

  uint8  CamConfirmationProb;                     /*!< Confirmation probability */
  ui16_t uiVideoAssocTime;                        /*!< Number of continuing video updates with same ID */
  uint8  ucCamClassifiedCycles;                   /*!< Number of confirmation cycles, where camera class was not unclassified */

  uint8  ucPredCycleCount;                        /*!< number of prediction cycles */

  uint8  bfCamDataContent;                        /*!< Flags to signal camera data content in object */
  uint8  ucFusionLevel;                           /*!< fusion "level" of object, specifies whether an object is
                                                        0 - not associated to a camera object at all or
                                                        1 - only camera confirmed (association with camera object) or
                                                        2 - also fused with associated camera object (lateral improved object model)
                                                        with the current camera object */
  uint8  eCamConfirmationType;                    /*!< confirmation type  */
  uint8  ucOcclQual;                              /*!< occlusion quality counter (increase when objects quality mainly POBST is higher threshold */

  eClassification_t   eClassCamera;     /*!< class of associated video object */
} COF_t_ObjectData;
/*! Type definition for target list header */
typedef struct
{
  uint32 Version;                   /*!< Number of interface header */
  uint32 CycleCountRadar;           /*!< Cycle counter of triggering radar sensor */
  uint32 CycleCountVideo;           /*!< Camera internal cycle counter */

  //fTime_t CycleTime;                 /*!< Cycle time of external COD processing */
  float32 MeasDelay;                 /*!< actual delay between measurement and call of TP */

  //EMExtTimeDiff_t MeasTime;          /*!< Measurement time based on external vehicle clock */

  uint16 NumOfObjects;              /*!< Number of objects at input interface */
  uint16 NumOfUsedObjects;           /*!< Number of used objects for fusion */
  // EMCodCameraEnvironment_t Environment; /*!< State of the detected environment conditions */
  boolean bDelayValid;                /*!< Indicator to identify valid delay*/
  boolean bIsNewData;                /*!< Indicator to identify new input data */
  boolean bUseCameraData;            /*< flag to indicate a running fusion processing */

  uint8 uiFusedToValidObjRatio;      /*< Ratio of fused/associated Objects and Valid objects*/

  float32 fDynamicMaxRange;         /*< dynamically updated maximum range of camera objects  */
  float32 fDynamicApertureAngle;    /*< dynamically updated maximum aperture angle of camera objects */

  float32 fCamPos_X;                /*< x position of camera */
  float32 fCamPos_Y;                /*< y position of camera */
  float32 fCamPos_Z;                /*< z position of camera */
} COF_t_CamObjListHeader;

/*! Type definition for target list entry */
typedef struct
{
  f32_t fDistX;               /*!< X-Position world [m] */
  f32_t fDistY;               /*!< Y-Position world [m] */

  f32_t fDistPolarCamOrigin;  /*!< polar distance in m */
  f32_t fDistPolarRdrOrigin;  /*!< polar distance in m */
  f32_t fAngleCamOrigin;      /*!< polar angle from camera origin [rad] */
  f32_t fAngleRdrOrigin;      /*!< polar angle from radar origin [rad] */
  f32_t fWidthAngle;          /*!< polar width in rad */
  f32_t fAngleRate;           /*!< polar angle rate in rad / s */

  f32_t fDistPolarVar;        /*!< polar distance in m */
  f32_t fAngleVar;            /*!< polar angle in rad */
  f32_t fWidthAngleVar;       /*!< polar width in rad */

  f32_t fRelSpeedX;           /*!< relative velocity in X world [m/s] */
  f32_t fRelSpeedY;           /*!< relative velocity in Y world [m/s] */


  f32_t fWidth;               /*!< width of object [m] */
  f32_t fLength;              /*!< length of object [m] */

  f32_t fDistXVar;            /*!< variance X-Position world [m^2] */
  f32_t fDistYVar;            /*!< variance Y-Position world [m^2] */
  f32_t fDistZVar;            /*!< variance Z-Position world [m^2] */

  f32_t fRelSpeedXVar;        /*!< variance relative velocity in X world [m/s]^2 */
  f32_t fRelSpeedYVar;        /*!< variance relative velocity in Y world [m/s]^2 */

  f32_t fWidthVar;            /*!< tolerance width  of object [m] */
  f32_t fLengthVar;           /*!< tolerance length of object [m] */

  f32_t                    ObjProb;        /*!< probability of existance [0..1] */
  f32_t                    fOrientation;   /*!< orientation of object []  */
  ODObj_t_RefPointPos      eRefPointPos;   /*!< orientation of object []  */

  eClassification_t        eClassCamera;   /*!< object class   */
  ODObj_t_MaintenanceState eMeasState;     /*!< Measurement state  */
  ODObj_t_DynamicProperty  eDynProp;       /*!< Dynamic propert  */

  uint8                    ObjID;          /*!< object name, object ID from input camera object list, not index in list */
  uint8                    SensObjID;      /*!< object ID from validated input object */

  boolean                   bCamObjUsed;   /*!< bool indicating if camera object was used for final association to a radar object */


}COF_t_CamObject;
typedef struct
{
  COF_t_CamObject          camObj[COF_NUM_CAM_OBJECTS];  /*!< camera object list */
  COF_t_CamObjListHeader   camObjLstHeader;              /*!< camera object list header */
} COF_t_CamObjList;

/*! Array[Nr. of EM private objects] for the object movement data */
typedef struct
{
  FPSEBA_ObjectMovement_t Movement;
  /* FPSEBA_MovementData_t contains only members of size 1 byte. To force 4 byte alignment of start address for MTS meas freeze, a dummy member of 4 byte alignment has to be added. */
  uint32 uDummy;
} FPSEBA_MovementData_t;
typedef struct
{
  percentage_t          confidenceStatus;
  percentage_t          probability;
  Bitfield16            type;
} GA_Observer;
typedef struct
{
   uint32                         versionNumber;                               /*!< Version  */
   SignalHeader_t                 sigHeader;                                   /*!< Signal Header  */
   GA_Observer                    vehicleClassification[EM_NR_PUBLIC_OBJECTS];    /*!< vehicleClassification[EM_NR_PRIVOBJECTS]  */
} VC_ObjectListExtension;           /* @versionstr: VC_OBJECT_LIST_EXTENSION_INTVER */

/*! the EM data struct with public and private data */
typedef struct
{
  /* internal data*/
  //EMGlob_t                  * pPrivGlob;            /*!< the em private glob data */
  //EMFrame_t                 * pFrame;               /*!< frame (cycle time, cycle counter, opmode ...) */

  /* input global read only data */
#if (ALN_MONITORING_VERSION >= 100)
  const ALN_Monitoring_t*         p_ALNMonitoring;
#else
  const ALN_AzimuthCorrection_t*  p_ALNAzimuthCorrection;
#endif
  const RSP_t_ClusterListNS*      p_RSPCluListNear;
  //const EM_t_RSP_ClusterListFS*   p_RSPCluListFar;

  const AssessedObjList_t       * pPubFctObj;           /*!< The FCT object list info from previous cycle */
  const SysPerfMonStates_t      * pSysPerfMonStates;    /*!< The system performance monitoring input data */
  const VehDyn_t                * pEgoDynRaw;           /*!< The ego dynamic data raw, use GET_EGO_RAW_DATA_PTR to access */
  const VehPar_t                * pGlobEgoStatic;       /*!< the static vehicle ego data, use GET_EGO_STATIC_DATA_PTR to access */

  const EmNvmIn_t               * pNvmIn;               /*!< NVM input data (so far unsed) */
  const BSW_s_AlgoParameters_t  * pAlgoParameters;      /*!< The global algo parameters structure */

#if (ALGO_SensorType==ALGO_CFG_ARS510)
  const PPAR_t_Decay_rel_max    * p_AntennaPar;          /*!< TargetDecay Pointer, this signal should come from the PPAR file and be provided by BSW */
#else
  const AntennaPar_BaseType_t   * pAntennaPar;          /*!< TargetDecay Pointer, this signal should come from the PPAR file and be provided by BSW*/
  const ProductionParameter_t   * p_ProductionParameter;/*!< Full access to production parameters */
#endif
  const SYS_t_HWSample          * p_HWSample;           /*!< Hardware sample version. */

  /* output global data*/
  EM_t_detectionsNear       * p_EMDetectionsNear;    /* pointer for EM near detection list */
#if (!ALGO_CFG_FarScanAvailable)
  EM_t_elevAttributesNear   * p_EMElevAttribNear;    /* pointer for EM near elevation attributes */
#else
  EM_t_detectionsFar        * p_EMDetectionsFar;     /* pointer for EM far detection list */
  EM_t_elevAttributesFar    * p_EMElevAttribFar;     /* pointer for EM far elevation attributes */
#endif
#if (CFG_EM_GENERIC_OBJECT_INTERFACE_ACTIVE)
  EMObjListDataPointer_t    * p_ObjListPointers;    /*!< The public EM object output data */
#endif
  ODObjectList_t            * pPrivObjList;            /*!< The public EM internal object data */
  ObjectTraceList_t         * pObjTraceList;        /*!< The moving object traces, use GET_OBJ_TRACE_LIST_DATA_PTR to access */
  MovingObjectTraces_t      * pMovObjTraces;        /*!< The moving object traces, use GET_MOV_OBJ_TRACE_DATA_PTR to access */
  Road_t                    * pRoadGlob;            /*!< The road global data, use GET_ROAD_DATA_PTR to access */
  RoadCustomOutput_t        * pRoadCustomOutput;    /*!< The road custom data, use  EM_GET_ROAD_CUSTOM_OUT_PTR to access */
  PerfDegr_t                * pGlobPD;              /*!< the global performance deg description, use GET_PERF_DEG_DATA_PTR to access */
  VehDyn_t                  * pEgoDynObjSync;       /*!< The ego dynamic synchronized with objects, use GET_EGO_OBJ_SYNC_DATA_PTR to access */
  VehDyn_t                  * pEgoDynTgtSync;       /*!< The ego dynamic synchronized with targets, use GET_EGO_TGT_SYNC_DATA_PTR to access */
  EmFctCycleMode_t          * pEmFctCycleMode;      /*!< the global data depend not on object (ego, road, ..) */
  EmNvmOut_t                * pNvmOut;              /*!< NVM input and output data    */
  //CustEMData_t              * pCustomData;          /*!< Custom data In and output data, use EM_GET_CUSTOM_PTR (EM_GET_CUSTOM_OBJ_OUT_PTR) to access  */
  //CEMData_t                 * pCEMData;             /*!< Common environment model data (sensor fusion with camera), use GET_CEM_DATA_PTR to access */
 // EMDemOut_t                * pDemEvents;           /*!< Dem events */
  const AS_t_ServiceFuncts  * p_AS_t_ServiceFuncts; /*!< Pointer to ECU service functions */
#if (CFG_EM_RTB_INTERFACE_ACTIVE)
  EM_t_RTBRecognition       * pEMRtbR;               /*!< roller test bench recognition */
#endif
  VC_ObjectListExtension    * p_vcObjectList;
 // RD_t_objectList           * p_rdObjectList;
  //PCC_ObjectListExtension   * p_pccObjectList;      /*!< Pedestrian Cyclist classification: Object List */
  //PCC_TargetList            * p_pccTargetList;      /*!< Pedestrian Cyclist classification: Target List */
#if (ALGO_CFG_FarScanAvailable)
  OD_t_TrafoMatrices        * p_odTrafoMatrices;    /*!< Trafo Matrices for EGO compensation */
#endif
  //EC_TunnelClassification   * p_ecTunnelClassification;  /*!< Tunnel detection state */
  //GA_ObserverOutput         * p_gaObserverOutput;   /*!< Tunnel probability information */
  //EC_CarparkClassification  * p_ecCarparkResult;    /*!< Car park detection state */
  //GA_TunnelDistanceOutput   * p_gaTunnelDistanceOutput;   /*!< Tunnel probability information */
  //GA_ObserverOutput         * p_ecProductionMode;   /*!<Production mode observer */
#if (GA_CFG_FROOP > 0)
  FroopIndexList_t          * p_froopindexlist;
#endif
} EMData_t;




#endif