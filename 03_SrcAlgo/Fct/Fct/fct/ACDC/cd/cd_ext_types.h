/*! \file **********************************************************************

COMPANY:                   COPYRIGHT (C) Continental AG
  
PROJECT:                   Mainstream

CPU:                       CPU-Independent

COMPONENT:                 CD Collision Detection (CG situation analysis)

PACKAGENAME:               cd_ext_types.h

DESCRIPTION:               Typdefs of the CD subcomonent, which shall be usable in the complete ACDC component.

AUTHOR:                    $Author: uidn3976 $

CREATION DATE:             $Date: 2020/09/09 07:14:46CEST $

VERSION:                   $Revision: 1.25 $

LEGACY VERSION:            Revision: 2.18

**************************************************************************** */

#ifndef CD_TYPES_INCLUDED
#define CD_TYPES_INCLUDED

/*****************************************************************************
  INCLUDES
*****************************************************************************/
#include "cd_par.h"

#if (ACDC_CFG_CD)
/*****************************************************************************
  MODULE DESCRIPTION
*****************************************************************************/
/**
\addtogroup cd
\{
*/

#define USE_CD_OBJ_STACK             SWITCH_OFF
#define USE_CD_GLOB_STACK            SWITCH_OFF

#define USE_CD_OBJ_INTER             SWITCH_ON
#define USE_CD_GLOB_INTER            SWITCH_ON

#define USE_CD_OBJ_INTERMEAS         SWITCH_OFF
#define USE_CD_GLOB_INTERMEAS        SWITCH_OFF

#define USE_CD_OBJ_INTRAMEAS         SWITCH_OFF
#define USE_CD_GLOB_INTRAMEAS        SWITCH_ON

#define USE_CD_OBJ_INTRA             SWITCH_ON
#define USE_CD_GLOB_INTRA            SWITCH_OFF

#define USE_CD_OBJ_SIMU              SWITCH_ON
#define USE_CD_GLOB_SIMU             SWITCH_ON


/*****************************************************************************
  TYPEDEFS 
*****************************************************************************/

/*! @brief       CDSide_t
    @general     Enum to distinguish between left and right hand side */
typedef enum 
{
  CD_LEFT,
  CD_RIGHT
}CDSide_t;

#if defined(CD_USE_FUS_OBJ_LIST_FOR_SEN_SOURCE) && ( CD_USE_FUS_OBJ_LIST_FOR_SEN_SOURCE == SWITCH_ON )

/*! @brief        Structure to store the mapping between the uiSensorConfirmation and the eSensorSource
    @description  Structure to store the mapping between the uiSensorConfirmation structure in \n
                  the EM Fusion object list and the eSensorSource bitfield in the CD hypothesis\n
                  along with the confirmation thresholds. 
    @attention    The mapping is project specific and has to be set in cd_par.c.*/
typedef struct
{
  EM_t_FusionSensorIndices eFusionSenIdx;     /*!< Sensor index in the fusion object list */
  EM_t_GenObjSensorSource  eSensorSource;     /*!< Bit in the sensor source interface matching the fusion sensor */
  uint8                    uSenConfThresOn;   /*!< Sensor confirmation threshold to set SensorSource Bit. */
  uint8                    uSenConfThresOff;  /*!< Sensor confirmation threshold to delete SensorSource Bit. */
} CDFusionSenConf_t;

extern MEMSEC_REF const CDFusionSenConf_t CDFusionSenConf[EM_N_FUSION_SENSORS];

#endif

typedef struct {
  SFLVector2D_t normalizedNormalToFrontEdge;  /*!< Normalized vector perpendicular to object's front edge pointing away from object's body  @typical @phys_unit [m x m]*/
  SFLVector2D_t centerOfFront;                /*!< Vector to object's center of front                                                       @typical @phys_unit [m x m]*/
  float32       fWidth;                       /*!< Object's width                                                                           @typical @phys_unit [m]*/
  float32       fLength;                      /*!< Object's length                                                                          @typical @phys_unit [m]*/
  uint8         uFrontEdgeIndex;              /*!< Index of the object's front edge                                                         @typical @phys_unit []*/
} CDObjectsCenterOfFront_t; /*!< Contains information about object's center of front, width, length, orientation and the index of the front edge */

/* ****************************************************************
    TYPEDEF STRUCT
    **************************************************************** */
/*! @brief          Structure to describe the kinematics of an object
    */
typedef struct
{
  float32 fX;     /*!< Position in X direction (=Longitudinal).                 @typical @phys_unit [m]*/
  float32 fY;     /*!< Position in Y direction (=Lateral, Left = +, Right = -). @typical @phys_unit [m]*/
  float32 fVx;    /*!< Velocity in X direction.                                 @typical @phys_unit [m/s]*/
  float32 fVy;    /*!< Velocity in Y direction.                                 @typical @phys_unit [m/s]*/
  float32 fAx;    /*!< Acceleration in X direction.                             @typical @phys_unit [m/s^2] */
  float32 fAy;    /*!< Acceleration in Y direction.                             @typical @phys_unit [m/s^2] */
} CDMovement_t;


#if ((CD_USE_GEN_PSC))
/*------Probability of Speed Concept -----------------*/

/* ****************************************************************
    TYPEDEF STRUCT
   **************************************************************** */
/*! @brief     Describes \ref CD_PSC_PROB_OBSERVE_Y_DIST_N steps of the history of a value.
    */
typedef struct CDHistoryFloat
{
  uint8   uiLastID;                                    /*!< ID of the latest stored value of the history.*/
  uint8   uiValidValueCount;                           /*!< Total number of valid history values.*/
  float32 afValues[CD_PSC_PROB_OBSERVE_Y_DIST_N];      /*!< Array containing all history values.*/
} CDHistoryFloat_t;

/* ****************************************************************
    TYPEDEF STRUCT
    **************************************************************** */
/*! @brief     Structure stores the kinematic history of an object. Mainly used in the module \ref cd_calculatepsc.
    */
typedef struct CDKinHistObj
{
  CDHistoryFloat_t sPosY;              /*!< Y distance of the target object and ego vehicle.                  @typical @phys_unit [m]*/
  CDHistoryFloat_t sPosX;              /*!< X distance of the target object and ego vehicle.                  @typical @phys_unit [m]*/
  CDHistoryFloat_t sPosYVar;           /*!< Variation in Y distance of the target object and the ego vehicle. @typical @phys_unit [m]
                                            Do not store sPosXVar as it is currently not needed and each history value requires a lot of storage */
} CDKinHistObj_t;

#endif /* ((CD_USE_GEN_PSC))*/

/*--------- internal data --------------*/

/*! Hypothesis history flag
 *
 * @remark One bit per hypothesis type (used for a 1 loop history)
 */
/* ****************************************************************
    TYPEDEF STRUCT
    **************************************************************** */
/*! @brief  Describes the hypothesis history of an object. A set flag indicates 
            that a hypothesis of the equivalent type was calculated on the object 
            in the previous cycle.
    */
typedef struct /* PRQA S 0635 18*/
{ /* date: 2017-10-19, reviewer: Stenmanns, David, reason: Type ubit16_t used to save memory and has been used since a long time.*/
  ubit16_t RunUpMoving     :1;               /*!< Run up moving */
  ubit16_t Following       :1;               /*!< Following */
  ubit16_t CutIn           :1;               /*!< Cut In */
  ubit16_t Pass            :1;               /*!< Pass */
  ubit16_t RunUpStationary :1;               /*!< Run Up Stationary */
  ubit16_t WasOncomming    :1;               /*!< Was Oncoming */
  ubit16_t PedColl         :1;               /*!< Pedestrian Collision */
  ubit16_t CrossingLeft    :1;               /*!< Crossing Left */
  ubit16_t CrossingRight   :1;               /*!< Crossing Right */
  ubit16_t WasCrossing     :1;               /*!< Was Crossing */
  ubit16_t BicycleColl     :1;               /*!< Bicycle Collision */
  ubit16_t RunUpLong       :1;               /*!< Longitudinal */
  ubit16_t TurnIntoVRU     :1;               /*!< Turn into oncoming VRU (CPTA) */
  ubit16_t DriveIntoSloMo  :1;               /*!< Drive into slow moving */
} CDHypothesisHist_t;

#if(CD_USE_GEN_PSC)

#ifdef ACDC_SIMU
typedef struct {
  SFLVector2D_t collPtEgoFront;
  SFLVector2D_t collPtToGenObjPos;
  float32  afPSCVelocityProb[CD_PSC_PROB_VELO_STEPS_N];
  float32  afPSCVelocitySteps[CD_PSC_PROB_VELO_STEPS_N];
  float32  fPSCProb;
  float32  fPSCProbGauss;
  float32  fPSCProbGaussFused;
  float32  fCollCorrVeloLeft;
  float32  fCollCorrVeloRight;
  float32  fCollCorrToCollPtVelLeft;
  float32  fCollCorrToCollPtVelRight;
  float32  fCenterVelocity;
  float32  fCenterVelocityStd;
  float32  fCenterToCollPtVel;
  float32  fCenterToCollPtVelStd;
  float32  fVelocityGate;
} CDPSCObjDataDebug_t;
#endif /*ACDC_SIMU*/

/*! @brief Identify the used reference point for the calculation of PSC distributions */
typedef enum
{
  CD_PSC_USE_TO_TRAJ         /*!< Use the reference point orthogonal to trajectory tangent*/
  /* functionality in PSC only if CD_USE_TURNINTOVRU_HYPOTHESIS is switched on */
#if (CD_USE_TURNINTOVRU_HYPOTHESIS)
  ,CD_PSC_USE_TO_COLL_POINT    /*!< Use the predicted collision point considering the object kinematics*/
#endif
} CDPSCRefPointType_t;

#endif /* CD_USE_GEN_PSC*/

/*! @brief        Minimum value of the current object occupancy

    - @typical   -32768
    - @phys_unit:      []
    */
#define CD_OBJ_OCCUPANCY_MIN (-32768)

/*! @brief        Maximum value of the current object occupancy

    - @typical   32768
    - @phys_unit:      []
    */
#define CD_OBJ_OCCUPANCY_MAX ( 32767)

/*! @brief        Scaling value of the current object occupancy from (0 - 1) to (0 - X)

    - @typical   1000.0
    - @phys_unit:      [ ]
    */
#define CD_OBJ_OCCUPANCY_SCALE_FACTOR 1000.0F

/*! @brief        Value describing a occupancy

    - @range      [0, \ref CD_OBJ_OCCUPANCY_SCALE_FACTOR]
    - @phys_unit:      []
    */
typedef sint16 iOccupancy_t;


/*! Object information for RunUp/RunUpBraking Hypotheses */
/* ****************************************************************
    TYPEDEF STRUCT
    **************************************************************** */
/*! @brief    Structure containing all data required to calculate the probability 
              of the RunUp/RunUpBraking hypothesis.
    */
typedef struct
{
  float32               fInlapNow;             /*!< Current Inlap of the object. @phys_unit [m]*/
  float32               fInlapTTC;             /*!< Inlap of the object at TTC. @phys_unit [m]*/
  float32               fInlapVarNow;          /*!< Variance of current Inlap of the object. @phys_unit [m^2]*/
  float32               fInlapVarTTC;          /*!< Variance of the inlap of the object at TTC. @phys_unit [m^2]*/
  percentage_t          uInlapHypProbNow;      /*!< Current inlap run up hypothesis probability. @typical @range [0,100]*/
  percentage_t          uInlapHypProbTTC;      /*!< Inlap run up hypothesis probability at TTC. @typical @range [0,100]*/
  sint8                 iTimeBasedProb;        /*!< Time based probability to determine the inlap value corresponding to 100% hyp. prob. @range[0,100] */
} CDInternalObjHypRunUpData_t;

/* ****************************************************************
    TYPEDEF STRUCT
    **************************************************************** */
/*! @brief    Information regarding side lane objects of stationary objects 
              for the RunUp Stationary Hypothesis.
    */
typedef struct 
{
  boolean bObstacleAtLeft;                      /*!< there is an obstacle at the left side of this object*/
  boolean bObstacleAtRight;                     /*!< there is an obstacle at the right side of this object*/
  uint8   uDummy;
#if (CD_HYP_RUN_UP_STAT_USE_OBJ_CHAIN_DETECTION == SWITCH_ON)
  sint8   iObjInvalidCnt;
#else
  uint8   uDummy1;
#endif

} CDInternalObjHypRunUpStatData_t;

#ifdef ACDC_SIMU
typedef struct 
{
  #if (CD_HYP_RUN_UP_STAT_USE_OBJ_CHAIN_DETECTION == SWITCH_ON)
    sint8   aiStatObjChainID[EM_N_OBJECTS];
  #else
    // Can be removed if at least one member is guaranteed.
    uint32 uDummy;
  #endif
} CDInternalObjHypRunUpStatDataSimu_t;
#endif

#if (CD_USE_LONG_COLL_HYPOTHESIS)
/* ****************************************************************
    TYPEDEF STRUCT
    **************************************************************** */
/*! @brief    Stores data related to the time based part of the Longitudinal 
              collision hypothesis (\ref cd_hyplong)
    */
typedef struct{
#if (CD_HYP_LONG_COLL_TIME_BASED_HYP_PROB_ENABLE)
  uint8  uTimeBasedProb; /*!< Time used to increase the hypothesis probability if the objects orientation points in the same direction as its movement.*/
  uint8  uDummy;
  uint8  uDummy1;
  uint8  uDummy2;
#else
  uint32 uDummy; 
#endif
} CDInternalObjHypLongCollData_t;
#endif


#if (CD_USE_CROSSING_HYPOTHESIS)
/* ****************************************************************
    TYPEDEF ENUM
    **************************************************************** */
/*! @brief Object states regarding the crossing hypothesis
    */
typedef enum
{
  CD_CROSSING_NO_STATUS,          ///< No crossing status is available.
  CD_CROSSING_OBJECT_INVALID,     ///< The current crossing objects status is invalid.
  CD_CROSSING_OBJECT_VALID,       ///< The current crossing objects status is valid.
  CD_CROSSING_OBJECT_CONFIRMED    ///< The current crossing object has been confirmed.
} eCDHypCrossingObjectStatus;

/* ****************************************************************
    TYPEDEF STRUCT
    **************************************************************** */
/*! @brief    Object information for crossing hypothesis
    */
typedef struct 
{
  eCDHypCrossingObjectStatus  eObjectStatus;        /*!< The state of a crossing object */
  uint8                       uiObjCrossingCounter; /*!< Counts the number of cycles that an object has been detected as crossing.*/
  uint8                       uiLastSeenAsOncoming; /*!< Counts the number of cycles that an object has been detected as oncoming. 
                                                         Is reseted if DynProb is not oncoming for at least one cycle.*/
} CDInternalObjHypCrossingData_t;
#endif /* CD_USE_CROSSING_HYPOTHESIS */

#if (CD_USE_CUT_IN_HYPOTHESIS)
typedef struct 
{
  uint8         uiNeighborCutInProb;            /*!< Cut-in probability for neighbor object */
  ObjNumber_t   uiNeighborRunUpObjIndex;        /*!< Neighbor Cut-in run-up object */
} CDInternalObjHypCutInData_t;
#endif

#if (SWITCH_ON == CD_USE_DRIVE_INTO_ONCOMING_HYPOTHESIS)
/*PRQA S 3332 1*/ /* date: 2019-06-01, reviewer: Praveen Annareddy, reason: Macro shall be defined in certain configurations(ONC), so keep this structure same in all configs*/
#if (CD_HYP_DRIVE_INTO_ONCOMING_USE_SMOOTHENED_ORIENTATION)
/* ****************************************************************
    TYPEDEF STRUCT
    **************************************************************** */
/*! @brief    Stores internal hypothesis data for a hypothesis of type 
 *! \ref CDHypothesisType_DriveIntoOncoming*/
typedef struct{
  /*!< Object's orientation smoothened with the value from the previous cycle
   *!< @range [0; 2*pi[ , @phys_unit [rad] .*/
  float32 fSmObjectOrientationRad;
} CDInternalObjHypDrvIntoOncoming_t;
#endif /* CD_HYP_DRIVE_INTO_ONCOMING_USE_SMOOTHENED_ORIENTATION */
#endif

/* ****************************************************************
    TYPEDEF STRUCT
    **************************************************************** */
/*! @brief    Structure containing all relevant information about an internal hypothesis.
    */
typedef struct  
{
  float32                    fHypothesisProbability; /*!< Probability of the hypothesis*/
  float32                    fRelevance;             /*!< relevance of the hypothesis */  
  fTime_t                    fHypothesisLifetime;    /*!< hypothesis lifetime */ 
  ObjNumber_t                iObjectRef;             /*!< Reference to the object related to the hypothesis*/
#if( (EM_GEN_OBJECT_INTFVER >= 0x0D) && (CD_USE_EM_FPS_OBJCLASS == SWITCH_ON) )
  eEBAObjectClass_t          eObjectClass;           /*!< Classification of the related object.*/
#else
  EM_t_GenObjClassification  eObjectClass;           /*!< Classification of the related object*/
#endif
  eCDHypothesisType_t        eType;                  /*!< Hypothesis  Type*/
  EM_t_GenEbaInhibit         eEBAInhibitionMask;     /*!< Hypothesis  inhibition mask*/
  sint8                      iExtHypID;              /*!< Corresponding external hypothesis */
} CDIntHypothesis_t;


#if CD_USE_HYPOTHESIS_RELATION
#if CD_HYP_RUN_UP_STAT_USE_ACC_HYPOTHESIS_SUPPORT
/*! @brief      Contains all data related to the hypothesis relation between RunUp and ACC */
typedef struct
{
  float32 fACCHypTimer; /*! Timer how long ago an ACC object was present */
} CDHypRelationAcc2RunUpStat_t;
#endif

/*! @brief      Contains all data related to the hypothesis relations */
typedef struct
{
#if CD_HYP_RUN_UP_STAT_USE_ACC_HYPOTHESIS_SUPPORT
  CDHypRelationAcc2RunUpStat_t Acc2RunUpStat;
#endif
} CDHypRelations_t;
#endif

typedef struct CDIntHypotheses_t
{
  CDIntHypothesis_t aHyp[CD_NUMBER_OF_HYPOTHESES];
  uint8             uNumOfHyps;
  uint16            uDummy16;
  uint8             uDummy8;
}  CDIntHypotheses_t;

typedef struct CDIntHypothesesData_t
{
  CDIntHypotheses_t   sCurrent;
  CDIntHypotheses_t   sPrev;
#if CD_USE_HYPOTHESIS_RELATION
  CDHypRelations_t sHypRelations;
#endif
}  CDIntHypothesesData_t;


#if defined(CD_USE_FUS_OBJ_LIST_FOR_SEN_SOURCE) && (CD_USE_FUS_OBJ_LIST_FOR_SEN_SOURCE==SWITCH_ON)
typedef struct CDQualifier_t
{
  EM_t_GenObjSensorSource         eSensorSource;    /*!< Bitfield for Sensors by which an object has been detected*/
}CDQualifier_t;
#endif


#if defined(CD_USE_BRAKE_JERK_TTC) && (CD_USE_BRAKE_JERK_TTC == SWITCH_ON)
typedef struct CDObj_BrakeJerk_t 
{
  float32           fTTCBrakeJerk;        /*!< Time to collision assuming a brake jerk                            @typical @phys_unit [s]*/
  float32           fTTCBrakeJerkFactor;  /*!< Hypothesis Prob reduction factor based on the TTCBrakeJerk         @typical @phys_unit [-]*/
}CDObj_BrakeJerk_t;
#endif 


/*! @brief      CD Internal object. Contains all object information that is relevant for a collision detection.*/
typedef struct CDObj_TTX_t
{
#if defined(CD_USE_BRAKE_JERK_TTC) && (CD_USE_BRAKE_JERK_TTC == SWITCH_ON)
  CDObj_BrakeJerk_t     sBrakeJerk;
#endif
  float32               TTC;                  /*!< Time to collision (assuming that the object is in the course of the ego vehicle).   @typical @phys_unit [s]*/
  float32               TTC2;                 /*!< Time to collision 2 (assuming that the object is in the course of the ego vehicle). @typical @phys_unit [s]*/
  float32               TTC3;                 /*!< Time to collision 3 (assuming that the object is in the course of the ego vehicle). @typical @phys_unit [s]*/
  float32               TTC4;                 /*!< Time to collision 4 (assuming that the object is in the course of the ego vehicle). @typical @phys_unit [s]*/
#if defined(CD_USE_TTM_LONG) && (CD_USE_TTM_LONG == SWITCH_ON)
  float32               TTMLongPre;           /*!< Time to comfort mitigation by longitudinal acceleration in 2D scenario.             @typical @phys_unit [s]*/
  float32               TTMLongAcute;         /*!< Time to emergency mitigation by longitudinal acceleration in 2D scenario.           @typical @phys_unit [s]*/
#endif //defined(CD_USE_TTM_LONG) && (CD_USE_TTM_LONG == SWITCH_ON)
  float32               TTBPre;               /*!< Time to brake for comfort braking.                                 @typical @phys_unit [s]*/
  float32               TTBAcute;             /*!< Time to brake for emergency braking.                               @typical @phys_unit [s]*/
  float32               TTSPre;               /*!< Time to steer for comfort steering.                                @typical @phys_unit [s]*/ 
  float32               TTSAcute;             /*!< Time to steer for emergency steering.                              @typical @phys_unit [s]*/
  float32               TTSPreRight;          /*!< Time to steer for comfort steering right.                          @typical @phys_unit [s]*/
  float32               TTSPreLeft;           /*!< Time to steer for comfort steering left.                           @typical @phys_unit [s]*/
  float32               TTSAcuteRight;        /*!< Time to steer for emergency steering right.                        @typical @phys_unit [s]*/
  float32               TTSAcuteLeft;         /*!< Time to steer for emergency steering left.                         @typical @phys_unit [s]*/

} CDObj_TTX_t;

typedef struct CDObj_Hypothesis_t
{
#if (CD_USE_RUN_UP_HYPOTHESIS)
  CDInternalObjHypRunUpData_t     sHypRunUpData;      /*!< Object data regarding the run up hypothesis*/
#endif
#if (CD_USE_RUN_UP_STAT_HYPOTHESIS)
  CDInternalObjHypRunUpStatData_t sHypRunUpStatData;  /*!< Object data regarding the run up stationary hypothesis*/
#endif
#if (CD_USE_CROSSING_HYPOTHESIS)
  CDInternalObjHypCrossingData_t sHypCrossingData;    /*! Object data regarding the crossing hypothesis*/
#endif /* CD_USE_CROSSING_HYPOTHESIS */

#if (CD_USE_LONG_COLL_HYPOTHESIS)
  CDInternalObjHypLongCollData_t sHypLongCollData;    /*! Object data regarding the longitudinal hypothesis*/
#endif /* CD_USE_CROSSING_HYPOTHESIS */

#if (SWITCH_ON == CD_USE_DRIVE_INTO_ONCOMING_HYPOTHESIS)
/*PRQA S 3332 1*/ /* date: 2019-06-01, reviewer: Praveen Annareddy, reason: Macro shall be defined in certain configurations(ONC), so keep this structure same in all configs*/
#if (CD_HYP_DRIVE_INTO_ONCOMING_USE_SMOOTHENED_ORIENTATION)
  /*! Internal data for hypothesis of type
   *! \ref CDHypothesisType_DriveIntoOncoming*/
  CDInternalObjHypDrvIntoOncoming_t sHypDrvIntoOncomingInternals;
#endif /* CD_HYP_DRIVE_INTO_ONCOMING_USE_SMOOTHENED_ORIENTATION */
#endif
  CDHypothesisHist_t              HypothesisHist;      /*!< Bitfield describing which hypotheses were calculated on the object in the last cycle*/
  uint32                          bitHypPresel;       /*!< Bitfield indicating preselected hypotheses @values:
                                                      struct { 
                                                      .offset(0) = uint32 Bits; 
                                                      .offset(0).mask(1<<(CDHypothesisType_RunUp-1)) = uint32 bRunUp; 
                                                      .offset(0).mask(1<<(CDHypothesisType_RunUpBraking-1)) = uint32 bRunUpBraking; 
                                                      .offset(0).mask(1<<(CDHypothesisType_RunUpStationary-1)) = uint32 bRunUpStationary; 
                                                      .offset(0).mask(1<<(CDHypothesisType_Static-1)) = uint32 bStatic; 
                                                      .offset(0).mask(1<<(CDHypothesisType_ACC-1)) = uint32 bACC; 
                                                      .offset(0).mask(1<<(CDHypothesisType_Pass-1)) = uint32 bPass; 
                                                      .offset(0).mask(1<<(CDHypothesisType_CutIn-1)) = uint32 bCutIn; 
                                                      .offset(0).mask(1<<(CDHypothesisType_Collision-1)) = uint32 Collision; 
                                                      .offset(0).mask(1<<(CDHypothesisType_CollisionUnavoidable-1)) = uint32 CollisionUnAv;
                                                      .offset(0).mask(1<<(CDHypothesisType_PedCollision-1)) = uint32 PedColl; 
                                                      .offset(0).mask(1<<(CDHypothesisType_PedPass-1)) = uint32 PedPass; 
                                                      .offset(0).mask(1<<(CDHypothesisType_Crossing-1)) = uint32 PedCross; 
                                                      .offset(0).mask(1<<(CDHypothesisType_CyclColl-1)) = uint32 CycleColl; 
                                                      .offset(0).mask(1<<(CDHypothesisType_TurnIntoVRU-1)) = uint32 bTurnIntoVRU;
                                                      .offset(0).mask(1<<(CDHypothesisType_DriveIntoSloMo-1)) = uint32 bDriveIntoSloMo;
                                                      }*/
  uint32                          bitHypActive;       /*!< Bitfield indicating active hypotheses @values:
                                                      struct { 
                                                      .offset(0) = uint32 Bits; 
                                                      .offset(0).mask(1<<(CDHypothesisType_RunUp-1)) = uint32 bRunUp; 
                                                      .offset(0).mask(1<<(CDHypothesisType_RunUpBraking-1)) = uint32 bRunUpBraking; 
                                                      .offset(0).mask(1<<(CDHypothesisType_RunUpStationary-1)) = uint32 bRunUpStationary; 
                                                      .offset(0).mask(1<<(CDHypothesisType_Static-1)) = uint32 bStatic; 
                                                      .offset(0).mask(1<<(CDHypothesisType_ACC-1)) = uint32 bACC; 
                                                      .offset(0).mask(1<<(CDHypothesisType_Pass-1)) = uint32 bPass; 
                                                      .offset(0).mask(1<<(CDHypothesisType_CutIn-1)) = uint32 bCutIn; 
                                                      .offset(0).mask(1<<(CDHypothesisType_Collision-1)) = uint32 Collision; 
                                                      .offset(0).mask(1<<(CDHypothesisType_CollisionUnavoidable-1)) = uint32 CollisionUnAv;
                                                      .offset(0).mask(1<<(CDHypothesisType_PedCollision-1)) = uint32 PedColl; 
                                                      .offset(0).mask(1<<(CDHypothesisType_PedPass-1)) = uint32 PedPass; 
                                                      .offset(0).mask(1<<(CDHypothesisType_Crossing-1)) = uint32 PedCross; 
                                                      .offset(0).mask(1<<(CDHypothesisType_CyclColl-1)) = uint32 CycleColl; 
                                                      .offset(0).mask(1<<(CDHypothesisType_TurnIntoVRU-1)) = uint32 bTurnIntoVRU;
                                                      .offset(0).mask(1<<(CDHypothesisType_DriveIntoSloMo-1)) = uint32 bDriveIntoSloMo;
                                                      }*/

} CDObj_Hypothesis_t;


#ifdef ACDC_SIMU
typedef struct CDObj_HypothesisSimu_t
{
#if (CD_USE_RUN_UP_STAT_HYPOTHESIS)
  CDInternalObjHypRunUpStatDataSimu_t sHypRunUpStatData;  /*!< Object data regarding the run up stationary hypothesis*/
#endif
} CDObj_HypothesisSimu_t;
#endif


typedef struct CDObj_Evasion_t
{
  float32           LongNecAccel;          /*!< Necessary longitudinal acceleration (of the ego vehicle) to avoid a collision.      @typical @phys_unit [m/s^2]*/
#if (CD_USE_ANECLONG_PASS)                 
  float32           AnecLongCutOut;        /*!< Necessary longitudinal acceleration to avoid a collision by cutting behind object when leaving the ego corridor. @typical @phys_unit [m/s^2]*/
#endif                                     
  float32           LatNecAccel;           /*!< Necessary lateral acceleration to avoid a collision.               @typical @phys_unit [m/s^2]*/
  float32           ClosingVelocity;       /*!< Relative speed at time of collision (not AUTOSAR).                 @typical @phys_unit [m/s]*/
  float32           LatNecAccelRight;      /*!< Necessary lateral acceleration to right side to avoid a collision. @typical @phys_unit [m/s^2]*/
  float32           LatNecAccelLeft;       /*!< Necessary lateral acceleration to left side to avoid a collision.  @typical @phys_unit [m/s^2]*/
#if (ACDC_CFG_TURN_ASSIST)
  float32           fCorridorStopDistance; /*!< Depth at which the target-vehicle's corridor gets penetrated by the ego-vehicle assuming Turn Assist's intervention (ego-vehicle brakes). Used for functional safety. */
#endif /* #if ACDC_CFG_TURN_ASSIST */
}CDObj_Evasion_t;

typedef struct CDObj_EvasionStatic_t
{
#if (CD_USE_HIGH_QUALITY_LIFETIME)
  float32           fObjLifeCycleTimeHiQual;                /*!< Time for which an object has been detected with a high eba quality (\ref CDCalculateHiQualityLifetime). @typical @phys_unit [s]*/
#endif
  uint8             TrackAssigned;         /*!< Shifting Register for Track Assignment */
#if (CD_USE_TURNINTOVRU_HYPOTHESIS)
  uint8             PSCCollProbHist;       /*!< Shifting Register for PSC collision probability */
#endif
}CDObj_EvasionStatic_t;

/* ****************************************************************
    TYPEDEF STRUCT
    **************************************************************** */
/* ------------ function pointer data ----------------*/

/*--------- hypothesis handlers --------------*/
/*! @brief Function pointer to a Hypothesis handler*/
typedef void (*CDHypothesisHandler_fpt)(ObjNumber_t const iObjectIndex, boolean const bObjFilterMatched);
/*! Hypothesis post handler function pointer */
typedef void (*CDHypothesisPostHandler_fpt)(void);


/*! @brief Structure to describe the classes allowed for an hypothesis  */
#if (EM_GEN_OBJECT_INTFVER >= 13)
typedef  EM_t_GenEbaObjClass           CDHypFilterClass_t;
#else
typedef  EM_t_GenObjClassification     CDHypFilterClass_t; 
#endif
/* ****************************************************************
    TYPEDEF STRUCT
    **************************************************************** */
/*! @brief CDHypoHandlerClassFilter_t
    @general Contains all necessary information to filter objects according to their class */
typedef struct 
{
  const CDHypFilterClass_t * aClassFilter;
  const uint8   uNumOfClasses;
  const uint8   uMinClassConfidence;
} CDHypoHandlerClassFilter_t;


/*! @brief  Contains all required data for the check of the hypothesis specific object filter*/
typedef struct 
{
  const CDHypothesisHandler_fpt       fpHypHandler;       /*!< A function pointer to a hypothesis handler. */
  const CDHypothesisPostHandler_fpt   fpHypPostHandler;   /*!< A function pointer to a post processing function for hypothesis */
  const CDHypoHandlerClassFilter_t  * pClassFilter;       /*!< Hypothesis specific object class filter (If NULL-Pointer: All objects will pass the filter).*/
  const uint32                        uiHypTypes;         /*!< The hypothesis types which can be set. */
  const EM_t_GenEbaHypCat             bitHypCat;          /*!< Bitfield for the required hypothesis category. */
  const uint8                         uiGenObjQuality;    /*!< The minimum eba object quality. */ 
  const uint8                         uiStatObjQuality;   /*!< The minimum stationary quality. */
  const uint8                         uiPedObjQuality;    /*!< The minimum pedestrian quality. */
  const ACDC_t_RtaMapping             uRTACheckpoint;     /*!< ID of the corresponding RTA checkpoint (Runtime Analysis).*/
} CDHypoHandler_t;

/*--- External declaration of hypothesis handlers ---*/
#if (CD_HYP_HANDLERS_NO > 0u)
/*PRQA S 3493,3494 1*/ /* date: 2019-05-14, reviewer: Schnurr, Clemens, reason: defensive programming with parameters*/
extern const CDHypoHandler_t * const CD_HYP_HANDLERS[CD_HYP_HANDLERS_NO];
#else
extern const CDHypoHandler_t * const CD_HYP_HANDLERS;
#endif

#ifdef FASTSIM
extern CDInternalObjectList_t  CDExtObjectsInt;
#endif

/*! @brief    Structure for setting min. required safety distances in 
              lateral/longitudinal direction 
    */
typedef struct 
{
  float32 fLongNecRemainDist; /*!< Safety distance for calculation of Necessary long. deceleration. @phys_unit:m */
  float32 fLatNecRemainDist;  /*!< Safety distance for calculation of Necessary lat. acceleration.  @phys_unit:m */
} CDAdjSafeDistance_t;

/*! @brief   Contains parameters used in the calculation of the cd module*/
typedef struct 
{
  CDAdjSafeDistance_t       AdjSafeDistance;       /*!< Adjustable safety distance between object and ego vehicle. @typical @phys_unit [m]*/
} CDParameters_t;

#if (CD_USE_EPF)
#if defined(CD_EPF_CORRIDOR_FREEZE) && (CD_EPF_CORRIDOR_FREEZE == SWITCH_ON)
typedef struct EPFCorridorData_t
{
  boolean                     bCorridorFreezeActive;
  EPFEvasionCorridor_array_t  asFrozenCorridors;
}EPFCorridorData_t;
#endif /* CD_EPF_CORRIDOR_FREEZE */
#endif

typedef struct 
{
  CDObj_EvasionStatic_t EvasionStatic;
  CDObj_Evasion_t       Evasion;
  CDObj_TTX_t           TTX;
}CDDebugObj_t;

#if (CD_USE_TURNINTOVRU_HYPOTHESIS)
/*! @brief Object states regarding the crossing hypothesis
    */
typedef enum
{
  CD_EGO_TURNING_NO,    ///< No Turning scenario detected.
  CD_EGO_TURNING_LEFT,  ///< Left Turning scenario detected.
  CD_EGO_TURNING_RIGHT  ///< Right Turning scenario detected.
} CDEgoTurningState_t;

typedef struct
{
  CDEgoTurningState_t eEgoCurrentTurnState;
  float32             fEgoCurveLowPassOut;
#if(CD_BLK_DIST_TURN_OPST_DIR)
  float32             fDistBlockLeftTurn;
  float32             fDistBlockRightTurn;
#endif
}CDEgoDrvScenario_t;

#endif /* #if (CD_USE_TURNINTOVRU_HYPOTHESIS) */










/************************************************************************/
/* CD Stack types                                                       */
/************************************************************************/

/* CD object data */
#if (USE_CD_OBJ_STACK)
typedef struct  CD_ObjStack_t  
{
}CD_ObjStack_t;
#endif /* USE_CD_OBJ_STACK */

/* CD global data */
#if (USE_CD_GLOB_STACK)
typedef struct  CD_GlobDataStack_t  
{

}CD_GlobDataStack_t;
#endif /* USE_CD_GLOB_STACK */

/************************************************************************/
/* CD Inter types                                                       */
/************************************************************************/

/* CD object data */
#if (USE_CD_OBJ_INTER)
typedef struct  CD_ObjInter_t  
{
  CDObj_Hypothesis_t    sHypothesis;
#if (CD_USE_GEN_PSC)
  CDKinHistObj_t        sKinObjHist;
#endif
  CDObj_EvasionStatic_t sEvasion;
}CD_ObjInter_t;
#endif /* USE_CD_OBJ_INTER */

/* CD global data */
#if (USE_CD_GLOB_INTER)
typedef struct  CD_GlobDataInter_t  
{
  CDParameters_t        CDParameters;
  CDIntHypothesesData_t sHypothesis;
#if (CD_USE_TURNINTOVRU_HYPOTHESIS)
  CDEgoDrvScenario_t    sEgoDrvScenario;
#endif
#if (CD_USE_EPF)
#if defined(CD_EPF_CORRIDOR_FREEZE) && (CD_EPF_CORRIDOR_FREEZE == SWITCH_ON)
  EPFCorridorData_t  sEPFCorridorData;
#endif /* CD_EPF_CORRIDOR_FREEZE */
#endif
#if(ACDC_CFG_CALC_TRAJ_OCCUPANCY)
  SFLTrajOccupancy_t TrajOccupancy;
  float32 fTTC_TrajOcc;
  float32 fTTB_TrajOcc;
#endif
}CD_GlobDataInter_t;
#endif /* USE_CD_GLOB_INTER */

/************************************************************************/
/* CD InterMeas types                                                   */
/************************************************************************/

/* CD object data */
#if (USE_CD_OBJ_INTERMEAS)
typedef struct  CD_ObjInterMeas_t  
{

}CD_ObjInterMeas_t;
#endif /* USE_CD_OBJ_INTERMEAS */

/* CD global data */
#if (USE_CD_GLOB_INTERMEAS)
typedef struct  CD_GlobDataInterMeas_t  
{
}CD_GlobDataInterMeas_t;
#endif /* USE_CD_GLOB_INTERMEAS */


/************************************************************************/
/* CD IntraMeas types                                                   */
/************************************************************************/
/* CD object data */
#if (USE_CD_OBJ_INTRAMEAS)
typedef struct  CD_ObjIntraMeas_t  
{
}CD_ObjIntraMeas_t;
#endif /* USE_CD_OBJ_INTRAMEAS */

/* CD global data */
#if (USE_CD_GLOB_INTRAMEAS)
typedef struct  CD_GlobDataIntraMeas_t  
{
    CDDebugObj_t DebugRelObj;
}CD_GlobDataIntraMeas_t;
#endif /* USE_CD_GLOB_INTRAMEAS */


/************************************************************************/
/* CD Intra types                                                       */
/************************************************************************/
/* CD object data */
#if (USE_CD_OBJ_INTRA)
typedef struct  CD_ObjIntra_t  
{
  CDObj_Evasion_t        sEvasion;
  CDObj_TTX_t            sTTX;
#if defined(CD_USE_FUS_OBJ_LIST_FOR_SEN_SOURCE) && (CD_USE_FUS_OBJ_LIST_FOR_SEN_SOURCE==SWITCH_ON)
  CDQualifier_t          sQualifier;
#endif
}CD_ObjIntra_t;
#endif /* USE_CD_OBJ_INTRA */

/* CD global data */
#if (USE_CD_GLOB_INTRA)
typedef struct  CD_GlobDataIntra_t  
{

}CD_GlobDataIntra_t;
#endif /* USE_CD_GLOB_INTRA */


#ifdef ACDC_SIMU
/************************************************************************/
/* CD Simu types                                                        */
/************************************************************************/
/* CD object data */
#if (USE_CD_OBJ_SIMU)
typedef struct  CD_ObjSimu_t  
{
#if (CD_USE_GEN_PSC)
  CDPSCObjDataDebug_t                 sPSCObjDataDebug;  /*!< PSC Object Data for simulation*/
#endif /* #if (CD_USE_GEN_PSC) */
  CDInternalObjHypRunUpStatDataSimu_t sHypRunupStatDebug;
}CD_ObjSimu_t;
#endif /* USE_CD_OBJ_SIMU */

/* CD global data */
#if (USE_CD_GLOB_SIMU)
typedef struct  CD_GlobDataSimu_t  
{
#if ACDC_CFG_CALC_TRAJ_OCCUPANCY
  ACDCTrajOccupancySimu_t TrajOccupancySimuData;
#endif
#if (CD_USE_EPF)
  ACDCEPFTargetSimu_t     sEPFTargetSimuData;
#endif
uint8 Dummy; // To be removed if the structure contains at least one unswitched member
}CD_GlobDataSimu_t;
#endif /* USE_CD_GLOB_SIMU */
#endif /* ACDC_SIMU */


/* PRQA L:ALGO_INLINES */
/** \} */

#else /*(ACDC_CFG_CD)*/

#define USE_CD_OBJ_STACK             SWITCH_OFF
#define USE_CD_GLOB_STACK            SWITCH_OFF

#define USE_CD_OBJ_INTER             SWITCH_OFF
#define USE_CD_GLOB_INTER            SWITCH_OFF

#define USE_CD_OBJ_INTERMEAS         SWITCH_OFF
#define USE_CD_GLOB_INTERMEAS        SWITCH_OFF

#define USE_CD_OBJ_INTRAMEAS         SWITCH_OFF
#define USE_CD_GLOB_INTRAMEAS        SWITCH_OFF

#define USE_CD_OBJ_INTRA             SWITCH_OFF
#define USE_CD_GLOB_INTRA            SWITCH_OFF

#define USE_CD_OBJ_SIMU              SWITCH_OFF
#define USE_CD_GLOB_SIMU             SWITCH_OFF

#endif /*(ACDC_CFG_CD)*/

#endif /* CD_TYPES_INCLUDED*/


