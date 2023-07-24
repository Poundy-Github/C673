/*! \file **********************************************************************

// COMPANY:   Continental Automotive
// COMPONENT: SPM_SensorPerformanceMonitoring
// VERSION:   $Revision: 1.24 $

---*/ /*---
CHANGES:                   $Log: spm_objectloss.c  $
CHANGES:                   Revision 1.24 2021/02/16 14:17:39CET Oprea, Ionut02 (OpreaI01) 
CHANGES:                   Fix review findings regarding objects which are classified as pedestrian
CHANGES:                   Revision 1.23 2021/02/15 17:01:23CET Oprea, Ionut02 (OpreaI01) 
CHANGES:                   Compute damping probability for situation when we have near scan and ars510 sensor
CHANGES:                   Revision 1.22 2021/02/04 13:51:08CET Oprea, Ionut02 (OpreaI01) 
CHANGES:                   Fix QAC boolean issue
CHANGES:                   Revision 1.21 2021/01/22 09:16:28CET Pallo, Istvan (palloi) 
CHANGES:                   Add custom implementation for filter pedestrians out of object loss.
CHANGES:                   Revision 1.20 2020/06/25 08:14:34CEST Pallo, Istvan (palloi) 
CHANGES:                   Update code for SPM split - SRR
CHANGES:                   Revision 1.19 2020/04/23 14:55:15CEST Oprea, Ionut02 (OpreaI01) 
CHANGES:                   Fix QAC level 3 warnings
CHANGES:                   Revision 1.18 2020/04/08 13:19:02CEST Oprea, Ionut02 (OpreaI01) 
CHANGES:                   Fix QAC level 4 warnings
CHANGES:                   Revision 1.17 2020/03/17 09:27:44CET Oprea, Ionut02 (OpreaI01) 
CHANGES:                   Fix QAC
CHANGES:                   Revision 1.16 2020/03/05 08:09:58CET Pallo, Istvan (palloi) 
CHANGES:                   Update CBO with new config switches
CHANGES:                   Revision 1.15 2018/09/24 14:56:47CEST Pallo, Istvan (palloi) 
CHANGES:                   Add config switch and code for SRR technology
CHANGES:                   Revision 1.14 2018/06/26 12:25:25CEST Olaru, Marian (OlaruM02) 
CHANGES:                   check ALGO_CFG_ARS510
CHANGES:                   Revision 1.13 2018/06/21 14:21:25CEST Olaru, Marian (OlaruM02) 
CHANGES:                   move SPMInitObjectLoss out of configuration switch for object loss observer in order to be used in blockage probability fusion
CHANGES:                   Revision 1.12 2018/06/21 12:45:07CEST Olaru, Marian (OlaruM02) 
CHANGES:                   add configuration for object loss observer
CHANGES:                   Revision 1.11 2018/04/20 10:14:50CEST Pallo, Istvan (palloi) 
CHANGES:                   Add missed config swithc for fHelpRcs
CHANGES:                   Revision 1.10 2018/04/19 13:09:15CEST Pallo, Istvan (palloi) 
CHANGES:                   Add check for ARS510 project when setting RCS for near/far
CHANGES:                   Revision 1.9 2018/02/27 17:07:35CET Pallo, Istvan (palloi) 
CHANGES:                   Remove PDO comment from object loss observer
CHANGES:                   Revision 1.8 2017/11/14 13:55:11CET Pallo, Istvan (palloi) 
CHANGES:                   Aling function parameters
CHANGES:                   Revision 1.7 2017/09/14 09:30:00CEST Raj, Rahul (uid41599) 
CHANGES:                   FCT-ACC-FIP Object Width and Length using Shape Point
CHANGES:                   Revision 1.6 2017/08/18 10:17:41CEST Pallo, Istvan (palloi) 
CHANGES:                   Remove LA config switch from SPM
CHANGES:                   Revision 1.5 2017/08/02 11:37:15CEST Pallo, Istvan (palloi) 
CHANGES:                   Spell mistake correction
CHANGES:                   Revision 1.4 2017/07/28 06:54:01CEST Pallo, Istvan (palloi) 
CHANGES:                   Add functionality from AL_FCT_ARS400_02.86.00. Code refactoring & QAC cleaning.
CHANGES:                   Revision 1.3 2017/07/10 08:36:50CEST Umesh Babu, Harsha (uidj3583) 
CHANGES:                   Moved function declarations
CHANGES:                   Revision 1.2 2017/06/16 10:33:07CEST Pallo, Istvan (palloi) 
CHANGES:                   Remove functions headers from the file
CHANGES:                   Revision 1.1 2017/03/17 13:16:51CET Kober, Manfred (uidv8885) 
CHANGES:                   Initial revision
CHANGES:                   Member added to project /ADAS/SW/Components/SPM_SensorPerformanceMonitoring/04_Engineering/01_Source_Code/SPM/blockage/project.pj

**************************************************************************** */


/*****************************************************************************
  INCLUDES
*****************************************************************************/

#include "spm.h"
#include "spm_par.h"


#if(SPM_SRR_TECHNOLOGY == SWITCH_OFF)
#if (FCT_CFG_SIGNAL_PERF_MONITORING)
/*****************************************************************************
  MACROS
*****************************************************************************/

/*****************************************************************************
  TYPEDEFS
*****************************************************************************/


/*****************************************************************************
  (SYMBOLIC) CONSTANTS
*****************************************************************************/

/* constants for relevance loss detection and timer handling */
#define SPM_OBJLOSS_NO_REL_OBJECT                     (OBJ_INDEX_NO_OBJECT)
#define SPM_OBJLOSS_TIMER_INIT                        (20.0F)
#define SPM_OBJLOSS_TIMER_STEP_BIG                    (10.0F)
#define SPM_OBJLOSS_TIMER_STEP_SMALL                  (5.0F)
#define SPM_OBJLOSS_TIMER_MAX                         (60.0F)
#define SPM_OBJLOSS_DAMP_PROB_THLD                    (0.5F)
#define SPM_OBJLOSS_RCS_FILTER_ALPHA                  (0.1F)
#define SPM_OBJLOSS_DEAD_TIME                         (1.0F)
#define SPM_OBJLOSS_MAXVEGO_FOR_RELOBJ_TIMER          (60.0F)
#define SPM_OBJLOSS_TIMER_COUNTDOWN_MULTIPLICATOR     (1.0F)
#define SPM_OBJLOSS_RCS_INIT_VALUE                    (-999.0F)
#define SPM_OBJLOSS_RANGE_MAX_NEAR_RCS_CRITERIA       (100.0F)

/* constants for decision if loss of relevance was because of damping */
#define SPM_OBJLOSS_RCS_UPPER_THLD                    (10.0F)
#define SPM_OBJLOSS_RCS_LOWER_THLD                    (0.0F)
#define SPM_OBJLOSS_LAT_DIST_UPPER_THLD               (3.0F)
#define SPM_OBJLOSS_LAT_DIST_LOWER_THLD               (0.5F)
#define SPM_OBJLOSS_DISTX_UPPER_THLD                  (120.0F)
#define SPM_OBJLOSS_DISTX_LOWER_THLD                  (80.0F)
#define SPM_OBJLOSS_RANGE_UPPER_THLD_FAR              (350.0F)
#define SPM_OBJLOSS_RANGE_LOWER_THLD_FAR              (250.0F)
#define SPM_OBJLOSS_RANGE_UPPER_THLD_NEAR             (180.0F)
#define SPM_OBJLOSS_RANGE_LOWER_THLD_NEAR             (140.0F)
#define SPM_OBJLOSS_MIN_DISTX_FOR_CURVE               (50.0F)
#define SPM_OBJLOSS_MIN_DISTX_FOR_CURVE_LOW_SPEED     (5.0F)
#define SPM_OBJLOSS_CURVE_UPPER_THLD                  (0.005F)
#define SPM_OBJLOSS_CURVE_LOWER_THLD                  (0.0003F)
#define SPM_OBJLOSS_STRONG_CURVE_UPPER_THLD           (0.0125F)
#define SPM_OBJLOSS_STAT_RANGE_MAX_FAR                (300.0F)
#define SPM_OBJLOSS_STAT_RANGE_MIN_FAR                (250.0F)
#define SPM_OBJLOSS_STAT_RANGE_MAX_NEAR               (150.0F)
#define SPM_OBJLOSS_STAT_RANGE_MIN_NEAR               (100.0F)
#define SPM_OBJLOSS_STAT_TGTRATE_MAX                  (30.0F)
#define SPM_OBJLOSS_STAT_TGTRATE_MIN                  (20.0F)
#define SPM_EGO_SPEED_TRESHOLD_CURVE_CRITERIA         (40.0F / C_KMH_MS)
#define SPM_MIN_DIST_THRESHOLD_DROP_OUT_OBJECT        (0.30F)
#define SPM_OBJLOSS_HIDDEN_OBJ_ANGLE_OFFSET           (CML_f_Pi/4.0F)
#define SPM_OBJLOSS_OVERLAP_TOLLERANCE                (1.5F * (CML_f_Pi/180.0F))
#define SPM_PROBABILITY_OBJLOSS_CURVE_LANE_CHANGED    (0.1F)
#define SPM_PROBABILITY_OBJLOSS_DEFAULT               (0.5F)

#define SPM_OBJLOSS_FILTER_THLDUP_X                   (10.0F)
#define SPM_OBJLOSS_FILTER_THLDDOWN_X                 (-10.0F)

/* constants for ex-relevant object observation */
#define SPM_OBJLOSS_X_GATE                            (5.0F)
#define SPM_OBJLOSS_Y_GATE                            (2.0F)
#define SPM_OBJLOSS_MIN_LIFECYCLES                    (5U)
#define SPM_OBJLOSS_FOV_MIN_DISTX                     (10.0F)
#define SPM_OBJLOSS_FOV_MAX_DISTX                     (100.0F)
#define SPM_OBJLOSS_FOV_MAX_ANGLE                     (8.0F)
#define SPM_OBJLOSS_XPOS_INVALID                      (-999.0F)
#define SPM_OBJLOSS_YPOS_INVALID                      (-999.0F)
#define SPM_OBJLOSS_INVALID_ANGLE                     (-99.0F)
#define SPM_OBJLOSS_FOLLOWTIMER_MAX                   (10.0F)
#define SPM_OBJLOSS_MIN_DISTX_DROPOUT_THRESHOLD       (6.0F)
#define SPM_OBJLOSS_GRADIENT_NEAR_SCAN_THRESHOLD      (130.0F)
#define SPM_OBJLOSS_GRADIENT_FAR_SCAN_THRESHOLD       (250.0F)
#define SPM_OBJLOSS_GRADIENT_FAR_SCAN_THRESHOLD_RAIN  (300.0F)
#define SPM_OBJLOSS_GRADIENT_CONF_VARIATION_THD       (-0.08F)
#define SPM_OBJLOSS_CONF_FILTER_FACTOR                (0.01F)

#define SPM_OVERLAP_ANGLE_DIV_FACTOR                  (2.0F)

#if(SPM_ENABLE_FAST_BLOCKAGE_TRIGGER)
  #define SPM_FAST_BLOCKAGE_TIMER_VAL                 (10.0F)
#endif
#if(SPM_OBJLOSS_USE_CUSTOM_FILTER_PARAMETER == SWITCH_ON)
  /*! custom objectloss low pass filter parameter*/
  #define SPM_OBJLOSS_FILTER_PARAMETER                (0.21F)
#else
  #define SPM_OBJLOSS_FILTER_PARAMETER                (0.1F)
#endif

#if(SPM_PREVENT_LOW_SPEED_LOSSES == SWITCH_ON)
  #define SPM_OBJ_LOSS_SPEED_THLD                     (8.0F / C_KMH_MS)
  #define SPM_OBJ_LOSS_MIN_DIST_THLD                  (10.0F)
#endif

#define EM_ARS_OBJECT_LIST_INT_VER_THLD               (5U)
#define EM_PERF_DEGR_WIPER_INFO_INT_VER_THLD          (10U)

/*****************************************************************************
  MODULEGLOBAL VARIABLES
*****************************************************************************/
SPMObjectLoss_t SPMObjectLoss;
#if(SPM_USE_OBJECTLOSS_OBSERVER )
#if( (SPM_USE_RANGE_GRADIENT == SWITCH_ON) || (SPM_PREVENT_LOW_SPEED_LOSSES == SWITCH_ON))
 static float32 fHelpRelObjLastDistX;
#endif
#if(SPM_ENABLE_FAST_BLOCKAGE_TRIGGER == SWITCH_ON)
 float32 fObjLostTimer;
#endif

/*****************************************************************************
  MODULELOKAL VARIABLES
*****************************************************************************/

/*****************************************************************************
  FUNCTION PROTOTYPES
*****************************************************************************/
/*****************************************************************************
  FUNCTION
*****************************************************************************/
void SPMDetermineOverLapFlag(void)
{
    float32 fMinAngleACC[OOI_NUMBER_OF_OOI];
    float32 fMaxAngleACC[OOI_NUMBER_OF_OOI];
    uint8 idx;
    //for MISRA happy
    boolean bHelp;
    float32 fHelpDistanceACCObject;
    float32 fHelpDistanceRelevantObj;
    
    /* reset old result of overlap calculation */
    SPMObjectLoss.bPredictPositionOverlap = b_FALSE;

    /* Get angle for ACC objects if they are  existing */
    for(idx = (uint8)OBJ_NEXT_OOI; idx < (uint8)OOI_NUMBER_OF_OOI; idx ++)
    {
      if(SPM_OBJ_GET_OOI_LIST_OBJ_IDX(idx) != SPM_OBJLOSS_NO_REL_OBJECT)
      {
        fMinAngleACC[idx] = SPMPredictAngleComputation( SPM_OBJ_LONG_DISPLACEMENT((uint8)SPM_OBJ_GET_OOI_LIST_OBJ_IDX(idx)), 
                                          SPM_OBJ_LAT_DISPLACEMENT((uint8)SPM_OBJ_GET_OOI_LIST_OBJ_IDX(idx)), 
                                          SPM_OBJ_LONG_VREL((uint8)SPM_OBJ_GET_OOI_LIST_OBJ_IDX(idx)), 
                                          SPM_OBJ_LAT_VREL((uint8)SPM_OBJ_GET_OOI_LIST_OBJ_IDX(idx)), 
                                          SPM_OBJ_LONG_AREL((uint8)SPM_OBJ_GET_OOI_LIST_OBJ_IDX(idx)), 
                                          SPM_OBJ_LAT_AREL((uint8)SPM_OBJ_GET_OOI_LIST_OBJ_IDX(idx)), 
                                          - FCTSEN_pSLATE_SPM_Data->t_ObjList[SPM_OBJ_GET_OOI_LIST_OBJ_IDX(idx)].fWidth);
        fMaxAngleACC[idx] = SPMPredictAngleComputation(SPM_OBJ_LONG_DISPLACEMENT((uint8)SPM_OBJ_GET_OOI_LIST_OBJ_IDX(idx)), 
                                          SPM_OBJ_LAT_DISPLACEMENT((uint8)SPM_OBJ_GET_OOI_LIST_OBJ_IDX(idx)), 
                                          SPM_OBJ_LONG_VREL((uint8)SPM_OBJ_GET_OOI_LIST_OBJ_IDX(idx)), 
                                          SPM_OBJ_LAT_VREL((uint8)SPM_OBJ_GET_OOI_LIST_OBJ_IDX(idx)), 
                                          SPM_OBJ_LONG_AREL((uint8)SPM_OBJ_GET_OOI_LIST_OBJ_IDX(idx)), 
                                          SPM_OBJ_LAT_AREL((uint8)SPM_OBJ_GET_OOI_LIST_OBJ_IDX(idx)), 
                                           FCTSEN_pSLATE_SPM_Data->t_ObjList[SPM_OBJ_GET_OOI_LIST_OBJ_IDX(idx)].fWidth);
      }
      else
      {
        fMinAngleACC[idx] = SPM_OBJLOSS_INVALID_ANGLE;
        fMaxAngleACC[idx] = SPM_OBJLOSS_INVALID_ANGLE;
      }
    }
    SPMObjectLoss.fPredictAngleMax = fMaxAngleACC[OBJ_NEXT_OOI];
    SPMObjectLoss.fPredictAngleMin = fMinAngleACC[OBJ_NEXT_OOI];

    /*check if prediction for some ACC object cover object 0 only if ACC is behind to object 0*/
    for(idx = (uint8)OBJ_NEXT_LONG_LEFT_OOI; idx < (uint8)OOI_NUMBER_OF_OOI; idx ++)
    {
      // if predicted longitudinal distance for ACC  is under predicted longitudinal distance for object 0
     if(SPM_OBJ_GET_OOI_LIST_OBJ_IDX(idx) != SPM_OBJLOSS_NO_REL_OBJECT )
     {
      fHelpDistanceACCObject = SPM_OBJ_LONG_DISPLACEMENT(SPM_OBJ_GET_OOI_LIST_OBJ_IDX(idx)) + (SPM_OBJ_LONG_VREL(SPM_OBJ_GET_OOI_LIST_OBJ_IDX(idx)) * fCycleTime) + (SPM_OBJ_LONG_AREL(SPM_OBJ_GET_OOI_LIST_OBJ_IDX(idx)) * fCycleTime * fCycleTime / SPM_OVERLAP_ANGLE_DIV_FACTOR);
      fHelpDistanceRelevantObj = SPMObjectLoss.fLastRelObjDistX + (SPMObjectLoss.fLastRelObjVrelX * fCycleTime) + (SPMObjectLoss.fLastRelObjArelX * fCycleTime * fCycleTime/SPM_OVERLAP_ANGLE_DIV_FACTOR);
      if(
          (fHelpDistanceACCObject < fHelpDistanceRelevantObj)
        &&(CML_f_IsNonZero(SPMObjectLoss.fPredictAngleMin - SPM_OBJLOSS_INVALID_ANGLE))
        &&(CML_f_IsNonZero(SPMObjectLoss.fPredictAngleMax - SPM_OBJLOSS_INVALID_ANGLE))
       )
       {
        bHelp = SPMDetermineOverlapAngle(fMinAngleACC[idx], fMaxAngleACC[idx], SPMObjectLoss.fPredictAngleMin, SPMObjectLoss.fPredictAngleMax);
        SPMObjectLoss.bPredictPositionOverlap = bHelp;
       }
     }
     else
     {
       /*do nothing*/
     }
    }
}


float32 SPMPredictAngleComputation(const float32 fCurrLong,
                                   const float32 fCurrLat, 
                                   const float32 fVelLong, 
                                   const float32 fVelLat, 
                                   const float32 fAccLong, 
                                   const float32 fAccLat, 
                                   const float32 fWidth)
  {
   float32 fAngle,fTemp1,fTemp2;
   /* lateral prediction */
   fTemp1 = fCurrLat + (fVelLat *fCycleTime) + (fAccLat * fCycleTime * fCycleTime) / SPM_OVERLAP_ANGLE_DIV_FACTOR + (fWidth / SPM_OVERLAP_ANGLE_DIV_FACTOR);

   /* longitudinal prediction */
   fTemp2 = fCurrLong + (fVelLong *fCycleTime) + (fAccLong * fCycleTime * fCycleTime) / SPM_OVERLAP_ANGLE_DIV_FACTOR;

   /*predicted angle */
   fAngle = GDBatan2_66(fTemp1, fTemp2);
   fAngle = CML_f_MinMax(-SPM_OBJLOSS_HIDDEN_OBJ_ANGLE_OFFSET, SPM_OBJLOSS_HIDDEN_OBJ_ANGLE_OFFSET, fAngle);
   return fAngle;
  }


boolean SPMDetermineOverlapAngle( const float32 fMinAngleACCObj, 
                                         const float32 fMaxAngleACCObj,
                                         const float32 fMinAngleRelObj,
                                         const float32 fMaxAngleRelObj)
{
  boolean bResult= b_FALSE;
  if(
      ((fMinAngleACCObj <= fMinAngleRelObj) || (CML_f_Abs(fMinAngleACCObj-fMinAngleRelObj) < SPM_OBJLOSS_OVERLAP_TOLLERANCE))
    &&((fMaxAngleRelObj <= fMaxAngleACCObj) || (CML_f_Abs(fMaxAngleACCObj-fMaxAngleRelObj) < SPM_OBJLOSS_OVERLAP_TOLLERANCE))
    )
  {
    bResult = b_TRUE;
  }
  return bResult;
}

void SPMProcessObjectLoss(const fSpeed_t fOwnSpeed
                        , const float32 fProbStepWidth
                        , const PerfDegr_t *pPerfDegrData)
{
#if(SPM_USE_RANGE_GRADIENT)
  GDB_Math_Point_t  RangeGradientThldUp, RangeGradientThldDown;
  float32 ftemp_AbsolutRangeThreshold;
#endif
  /* Check if there is a moving object seen by the radar */
  boolean bDetectObjectDeletion = b_FALSE;
  float32 fFilteredValue = 0.0f;
  boolean bIsMovingObjectDetected = b_FALSE;
  ObjNumber_t j;
  for (j=0; ((j < EM_N_OBJECTS) && (bIsMovingObjectDetected == b_FALSE)); j++)
  {
   if((SPM_OBJ_LIFECYCLES(j) >= SPM_OBJLOSS_MIN_LIFECYCLES) && (SPM_OBJ_DYNAMIC_PROPERTY(j) != ARS_OBJECT_PROPERTY_STATIONARY))
    {
      bIsMovingObjectDetected = b_TRUE;
    }
  }

  /* copy current rel. Obj. ID into last rel. Obj. ID */
  SPMObjectLoss.cLastRelObjID = SPMObjectLoss.cCurrRelObjID;

  /* Get ID of current relevant object */
  SPMObjectLoss.cCurrRelObjID = SPM_OBJ_GET_OOI_LIST_OBJ_IDX(OBJ_NEXT_OOI);//SISeReObGetRelTrckObjNumber();

  if(SPMObjectLoss.cLastRelObjID != SPM_OBJLOSS_NO_REL_OBJECT)
  {
     SPMObjectLoss.uRelObjPresInAccRange = FCTSEN_pSLATE_SPM_Data->FctPreselTGACCLastRelObj;//ACC_b_TempGetDataToSPM(SPMObjectLoss.cLastRelObjID);//OBJ_GET_SI(SPMObjectLoss.cLastRelObjID).Bool.FctPreselTG;
  }
  else
  {
    SPMObjectLoss.uRelObjPresInAccRange = FALSE; 
  }
  /* Get clasification  of current relevant object */
  #if(SPM_USE_LAST_CLASSIFICATION == SWITCH_ON)
    if (SPMObjectLoss.cCurrRelObjID != SPM_OBJLOSS_NO_REL_OBJECT) 
    {
    SPMObjectLoss.uCurrentClasification = OBJ_CLASSIFICATION(SPMObjectLoss.cCurrRelObjID);
    }
    else
    {
      SPMObjectLoss.uCurrentClasification = ARS_OBJCLASS_UNCLASSIFIED; 
    }
  #endif

  /**************************************************************************/
  /*              Relevance was set for an object in this cycle             */
  /**************************************************************************/
  if((SPMObjectLoss.cCurrRelObjID != SPM_OBJLOSS_NO_REL_OBJECT) && (SPMObjectLoss.cLastRelObjID == SPM_OBJLOSS_NO_REL_OBJECT))
  {
    /* Set start values for relevance observation */
    SPMObjectLoss.fRelObjRCSFiltered = SPM_OBJ_RCS(SPMObjectLoss.cCurrRelObjID);
    #if(EM_ARS_OBJECT_LIST_INTFVER >= EM_ARS_OBJECT_LIST_INT_VER_THLD)
      #if ((ALGO_SensorType != ALGO_CFG_ARS400Entry) && (ALGO_SensorType != ALGO_CFG_ARS510))
        /* check if near measured value is available*/
        if(SPM_OBJ_IS_MEASURED(SPMObjectLoss.cCurrRelObjID, ARS_MEAS_SEN_NEARSCAN) == TRUE)
        {
          SPMObjectLoss.fRelObjRCSNear = OBJ_RCS_NEAR(SPMObjectLoss.cCurrRelObjID);
        }
        /* check if far measured value is available*/
        if(SPM_OBJ_IS_MEASURED(SPMObjectLoss.cCurrRelObjID, ARS_MEAS_SEN_FARSCAN) == TRUE)
        {
          SPMObjectLoss.fRelObjRCSFar = OBJ_RCS_FAR(SPMObjectLoss.cCurrRelObjID);
        }
      #endif
    #endif

    #if(SPM_USE_CAMERA_OBSERVER_BLK == SWITCH_ON)
      SPMObjectLoss.bObjWasSelected = b_FALSE;
      SPMObjectLoss.bObjNowSelected = b_TRUE;
    #endif

    SPMObjectLoss.bRelevanceLossDetected = b_FALSE;
    SPMObjectLoss.bObjectWasPresent = b_TRUE;
    SPMObjectLoss.fDeadTimeCounter = 0.0F;
    SPMObjectLoss.fLastRelObjDistX = SPM_OBJ_LONG_DISPLACEMENT(SPMObjectLoss.cCurrRelObjID);
    SPMObjectLoss.fLastRelObjDistY = SPM_OBJ_LAT_DISPLACEMENT(SPMObjectLoss.cCurrRelObjID);
    SPMObjectLoss.fLastRelObjVrelX = SPM_OBJ_LONG_VREL(SPMObjectLoss.cCurrRelObjID);
    SPMObjectLoss.fLastRelObjVrelY = SPM_OBJ_LAT_VREL(SPMObjectLoss.cCurrRelObjID);
    SPMObjectLoss.fLastRelObjArelX = SPM_OBJ_LONG_AREL(SPMObjectLoss.cCurrRelObjID);
    SPMObjectLoss.fLastRelObjArelY = SPM_OBJ_LAT_AREL(SPMObjectLoss.cCurrRelObjID);
    SPMObjectLoss.fLastWidth 	     = FCTSEN_pSLATE_SPM_Data->t_ObjList[SPMObjectLoss.cCurrRelObjID].fWidth;
    SPMObjectLoss.fLastRelObjDistFromLane = FCTSEN_pSLATE_SPM_Data->f_Dist2TrajACCRelObj;
    SPMObjectLoss.fRelObjObsTimer       = 0.0F;

    /* check if predicted position of relevant oject is covered by other predicted ACC objects*/
    SPMDetermineOverLapFlag();
    if(SPM_OBJ_DYNAMIC_PROPERTY(SPMObjectLoss.cCurrRelObjID) == ARS_OBJECT_PROPERTY_STATIONARY)
    {
      SPMObjectLoss.bRelObjWasMov = b_FALSE;
    }
    else
    {
      SPMObjectLoss.bRelObjWasMov = b_TRUE;
    }
  }
  /***************************************************************************/
  /*                                Relevance was lost                       */
  /***************************************************************************/
  else if(
           (SPMObjectLoss.cCurrRelObjID == SPM_OBJLOSS_NO_REL_OBJECT) && (SPMObjectLoss.cLastRelObjID != SPM_OBJLOSS_NO_REL_OBJECT)
        #if(SPM_USE_LAST_CLASSIFICATION == SWITCH_ON)
         &&(SPMObjectLoss.uLastClasification != ARS_OBJCLASS_POINT)
         &&(SPMObjectLoss.uLastClasification != ARS_OBJCLASS_BICYCLE)
        #endif
         )
  {
    /* Check losses of relevance only if relevance was set for at least x seconds for the first time */
    if(
        (
          (SPMObjectLoss.fRelObjObsTimer >= (float32)(SPM_OBJLOSS_MINRELOBJ_TIMER))
        ||(SPM_OBJECT_LOST)
        )
      ||(fOwnSpeed > (SPM_OBJLOSS_MAXVEGO_FOR_RELOBJ_TIMER / C_KMH_MS))
      )
    {
      /* determine probability that this loss of relevance was because of damping */
      SPMObjectLoss.fDampingProbability = SPMDetermineDampProb(pPerfDegrData
                                                            #if(SPM_PREVENT_LOW_SPEED_LOSSES == SWITCH_ON)
                                                              , fOwnSpeed
                                                            #endif
                                                              );

      /* follow instructions if loss of relevance was because of damping */
      if(
          (SPMObjectLoss.fDampingProbability > SPM_OBJLOSS_DAMP_PROB_THLD)
        &&(SPMObjectLoss.bPredictPositionOverlap != b_TRUE)
        )
      {
        SPMObjectLoss.uiNoOfObjLosses += 1U;
        SPMObjectLoss.bRelevanceLossDetected = b_TRUE;
        SPMObjectLoss.fResetTimer += SPM_OBJLOSS_TIMER_STEP_BIG; 
        SPMObjectLoss.fResetTimer = MIN_FLOAT(SPMObjectLoss.fResetTimer, SPM_OBJLOSS_TIMER_MAX);
        #if( (SPM_USE_RANGE_GRADIENT == SWITCH_ON) || (SPM_PREVENT_LOW_SPEED_LOSSES == SWITCH_ON))
          fHelpRelObjLastDistX = SPMObjectLoss.fLastRelObjDistX;
        #endif
      }
      else
      {
        /* loss of relevance was NOT because of damping, do not observe position for new rel. objects */
        SPMCancelObjLossObservation();
      }

      /* check if ex-relevant object is still alive or has been deleted */
      #if(defined(_MSC_VER))
        #pragma COMPILEMSG("potential bug from old SW: checking last object position for deleted object may fail (if new object opened in same position!") // PRQA S 3116
        /* date: 2015-05-18, reviewer: Lonard jaison Manohar, reason: Non QAC related but required.*/
      #endif
      if(SPMObjectLoss.cLastRelObjID >= 0)
      {
        if(!SPM_OBJ_IS_DELETED(SPMObjectLoss.cLastRelObjID))
        {
          /* object is still alive but no longer relevant*/
          SPMObjectLoss.bObjectWasPresent = b_TRUE;
        }
      }
      #if(SPM_USE_CAMERA_OBSERVER_BLK == SWITCH_ON)
        SPMObjectLoss.bObjWasSelected = b_TRUE;
        SPMObjectLoss.bObjNowSelected = b_FALSE;
      #endif
    }
  }

  /**************************************************************************/
  /*        Relevance is still present and was also in the last cycle       */
  /**************************************************************************/
  /* PRQA S 2995 1 */ /* 2020-04-27, reviewer:Opreai01, Popam05, reason: Is not always true ( Current = -1 and Last = -1)*/
  else if((SPMObjectLoss.cCurrRelObjID != SPM_OBJLOSS_NO_REL_OBJECT) && (SPMObjectLoss.cLastRelObjID != SPM_OBJLOSS_NO_REL_OBJECT))
  {
    /* check if the relevant object is still the same as before */
    if(SPMObjectLoss.cCurrRelObjID == SPMObjectLoss.cLastRelObjID)
    {
      /* update data of relevant object */
      GDB_Math_LowPassFilter(&SPMObjectLoss.fRelObjRCSFiltered, SPM_OBJ_RCS(SPMObjectLoss.cCurrRelObjID), SPM_OBJLOSS_RCS_FILTER_ALPHA);
      #if(EM_ARS_OBJECT_LIST_INTFVER >= 5u)
        #if ((ALGO_SensorType != ALGO_CFG_ARS400Entry) && (ALGO_SensorType != ALGO_CFG_ARS510))
          /* check if measured value is available.->filter only measured value*/
          if(SPM_OBJ_IS_MEASURED(SPMObjectLoss.cCurrRelObjID, ARS_MEAS_SEN_NEARSCAN) == TRUE)
          {
            /* update near data of relevant object */
            if(CML_f_IsNonZero(SPMObjectLoss.fRelObjRCSNear - SPM_OBJLOSS_RCS_INIT_VALUE))
            {
              GDB_Math_LowPassFilter(&SPMObjectLoss.fRelObjRCSNear, OBJ_RCS_NEAR(SPMObjectLoss.cCurrRelObjID), SPM_OBJLOSS_RCS_FILTER_ALPHA);
            }
            else
            {
              SPMObjectLoss.fRelObjRCSNear = OBJ_RCS_NEAR(SPMObjectLoss.cCurrRelObjID);
            }
          }
          if(SPM_OBJ_IS_MEASURED(SPMObjectLoss.cCurrRelObjID, ARS_MEAS_SEN_FARSCAN) == TRUE)
          {
            /* update far data of relevant object */
            if(CML_f_IsNonZero(SPMObjectLoss.fRelObjRCSFar - SPM_OBJLOSS_RCS_INIT_VALUE))
            {
              GDB_Math_LowPassFilter(&SPMObjectLoss.fRelObjRCSFar, OBJ_RCS_FAR(SPMObjectLoss.cCurrRelObjID), SPM_OBJLOSS_RCS_FILTER_ALPHA);
            }
            else
            {
              SPMObjectLoss.fRelObjRCSFar = OBJ_RCS_FAR(SPMObjectLoss.cCurrRelObjID);
            }
          }
        #endif
      #endif
      SPMObjectLoss.fLastRelObjDistFromLane = FCTSEN_pSLATE_SPM_Data->f_Dist2TrajACCRelObj;
      SPMObjectLoss.fLastRelObjDistX = SPM_OBJ_LONG_DISPLACEMENT(SPMObjectLoss.cCurrRelObjID);
      SPMObjectLoss.fLastRelObjDistY = SPM_OBJ_LAT_DISPLACEMENT(SPMObjectLoss.cCurrRelObjID);
      SPMObjectLoss.fLastRelObjVrelX = SPM_OBJ_LONG_VREL(SPMObjectLoss.cCurrRelObjID);
      SPMObjectLoss.fLastRelObjVrelY = SPM_OBJ_LAT_VREL(SPMObjectLoss.cCurrRelObjID);
      SPMObjectLoss.fLastRelObjArelX = SPM_OBJ_LONG_AREL(SPMObjectLoss.cCurrRelObjID);
      SPMObjectLoss.fLastRelObjArelY = SPM_OBJ_LAT_AREL(SPMObjectLoss.cCurrRelObjID);
      SPMObjectLoss.fLastWidth 		   = FCTSEN_pSLATE_SPM_Data->t_ObjList[SPMObjectLoss.cCurrRelObjID].fWidth;
      SPMObjectLoss.fRelObjObsTimer += SPM_CYCLE_TIME;
      #if(SPM_USE_CAMERA_OBSERVER_BLK == SWITCH_ON)
        SPMObjectLoss.bObjWasSelected = b_TRUE;
        SPMObjectLoss.bObjNowSelected = b_TRUE;
      #endif
      /* check if predicted position of relevant oject is covered by other predicted ACC objects*/
      SPMDetermineOverLapFlag();
    }
    /* relevant object has changed, reset all parameters */
    else
    {
      #if(SPM_CHECK_OBJ_LOSS_REL_CHANGE == SWITCH_ON)
        /*check first for object lost because of damping*/
        SPMObjectLoss.fDampingProbability = SPMDetermineDampProb(pPerfDegrData
                                                            #if(SPM_PREVENT_LOW_SPEED_LOSSES == SWITCH_ON)
                                                              , fOwnSpeed
                                                            #endif
                                                                );
        if((SPMObjectLoss.fDampingProbability > SPM_OBJLOSS_DAMP_PROB_THLD)&& (SPMObjectLoss.bPredictPositionOverlap != b_TRUE))
        {
          SPMObjectLoss.uiNoOfObjLosses       += 1U;
          SPMObjectLoss.bRelevanceLossDetected = b_TRUE;
          SPMObjectLoss.fResetTimer            += SPM_OBJLOSS_TIMER_STEP_BIG; 
          SPMObjectLoss.fResetTimer            = MIN_FLOAT(SPMObjectLoss.fResetTimer, SPM_OBJLOSS_TIMER_MAX);
          #if(SPM_USE_RANGE_GRADIENT)
            fHelpRelObjLastDistX = SPMObjectLoss.fLastRelObjDistX;
          #endif
        }
      #endif

      /* Set start values for relevance observation */
      SPMObjectLoss.fRelObjRCSFiltered = SPM_OBJ_RCS(SPMObjectLoss.cCurrRelObjID);
      #if(EM_ARS_OBJECT_LIST_INTFVER >= EM_ARS_OBJECT_LIST_INT_VER_THLD)
        #if((ALGO_SensorType != ALGO_CFG_ARS400Entry) &&(ALGO_SensorType != ALGO_CFG_ARS510))
          /* check if near measured value is available*/
          if(SPM_OBJ_IS_MEASURED(SPMObjectLoss.cCurrRelObjID, ARS_MEAS_SEN_NEARSCAN) == TRUE)
          {
            SPMObjectLoss.fRelObjRCSNear = OBJ_RCS_NEAR(SPMObjectLoss.cCurrRelObjID);
          }
          /* check if far measured value is available*/
          if(SPM_OBJ_IS_MEASURED(SPMObjectLoss.cCurrRelObjID, ARS_MEAS_SEN_FARSCAN) == TRUE)
          {
            SPMObjectLoss.fRelObjRCSFar = OBJ_RCS_FAR(SPMObjectLoss.cCurrRelObjID);
          }
        #endif
      #endif

      SPMObjectLoss.bRelevanceLossDetected = b_FALSE;
      SPMObjectLoss.bObjectWasPresent = b_TRUE;
      SPMObjectLoss.fDeadTimeCounter = 0.0F;
      SPMObjectLoss.fLastRelObjDistX = SPM_OBJ_LONG_DISPLACEMENT(SPMObjectLoss.cCurrRelObjID);
      SPMObjectLoss.fLastRelObjDistY = SPM_OBJ_LAT_DISPLACEMENT(SPMObjectLoss.cCurrRelObjID);
      SPMObjectLoss.fLastRelObjVrelX = SPM_OBJ_LONG_VREL(SPMObjectLoss.cCurrRelObjID);
      SPMObjectLoss.fLastRelObjArelX = SPM_OBJ_LONG_AREL(SPMObjectLoss.cCurrRelObjID);
      SPMObjectLoss.fLastRelObjArelY = SPM_OBJ_LAT_AREL(SPMObjectLoss.cCurrRelObjID);
      SPMObjectLoss.fLastRelObjVrelY = SPM_OBJ_LAT_VREL(SPMObjectLoss.cCurrRelObjID);
      SPMObjectLoss.fLastWidth 	     = FCTSEN_pSLATE_SPM_Data->t_ObjList[SPMObjectLoss.cCurrRelObjID].fWidth;
      SPMObjectLoss.fRelObjObsTimer = 0.0F;
    
      /* check if predicted position of relevant oject is covered by other predicted ACC objects*/
      SPMDetermineOverLapFlag();
      SPMObjectLoss.fLastRelObjDistFromLane = FCTSEN_pSLATE_SPM_Data->f_Dist2TrajACCRelObj;

      if(SPM_OBJ_DYNAMIC_PROPERTY(SPMObjectLoss.cCurrRelObjID) == ARS_OBJECT_PROPERTY_STATIONARY)
      {
        SPMObjectLoss.bRelObjWasMov = b_FALSE;
      }
      else
      {
        SPMObjectLoss.bRelObjWasMov = b_TRUE;
      }
      #if(SPM_USE_CAMERA_OBSERVER_BLK == SWITCH_ON)
        SPMObjectLoss.bObjWasSelected = b_FALSE;
        SPMObjectLoss.bObjNowSelected = b_TRUE;
      #endif
    }
  }

  /**************************************************************************/
  /* No relevance was present and no relevance is present in this cycle too */
  /**************************************************************************/
  else
  {
    if(SPMObjectLoss.bRelevanceLossDetected == b_TRUE)
    {
      /* check if an object was deleted at this position -> former relevant object */
      bDetectObjectDeletion = SPMDetectObjectDeletion();
      if((bDetectObjectDeletion == b_TRUE) && (SPMObjectLoss.fDeadTimeCounter >= SPM_OBJLOSS_DEAD_TIME))
      {
        SPMObjectLoss.uiNoOfObjLosses += 1U;
        SPMObjectLoss.fResetTimer += SPM_OBJLOSS_TIMER_STEP_SMALL;
        SPMObjectLoss.fResetTimer = MIN_FLOAT(SPMObjectLoss.fResetTimer, SPM_OBJLOSS_TIMER_MAX);
        SPMObjectLoss.bRelevanceLossDetected = b_FALSE;
      }
      else if(SPMObjectLoss.fDeadTimeCounter < SPM_OBJLOSS_DEAD_TIME)
      {
        SPMObjectLoss.fDeadTimeCounter += SPM_CYCLE_TIME;
      }
      else
      {
        /*nop*/
      }
    }
    else
    {
      /*nop*/
    }
    #if(SPM_USE_CAMERA_OBSERVER_BLK == SWITCH_ON)
      SPMObjectLoss.bObjNowSelected = b_FALSE;
    #endif
  }

  /**************************************************************************/
  /*                      End of relevance observation                      */
  /**************************************************************************/

  #if(SPM_USE_LAST_CLASSIFICATION == SWITCH_ON)
    /* copy current clasification of  Obj. into last clasification Obj. */
    SPMObjectLoss.uLastClasification = SPMObjectLoss.uCurrentClasification;
  #endif

  /* as long as object losses are present, the cycle time is subtracted from the reset timer */
  if(SPM_OBJECT_LOST)
  {
    /* Count down twice as fast if moving objects are detected */
    if(bIsMovingObjectDetected == b_TRUE)
    {
      SPMObjectLoss.fResetTimer -= (float32)(SPM_OBJLOSS_TIMER_COUNTDOWN_MULTIPLICATOR * SPM_CYCLE_TIME);
    }
    else
    {
      SPMObjectLoss.fResetTimer -= (float32)SPM_CYCLE_TIME;
    }
  }

  /* if the reset timer has expired, reset Object Loss criterion */
  if(SPMObjectLoss.fResetTimer <= 0.0F)
  {
    if(SPM_OBJECT_LOST)
    {
      SPMObjectLoss.uiNoOfObjLosses -= 1U;
    }
    SPMObjectLoss.fResetTimer = SPM_OBJLOSS_TIMER_INIT;
  }
  #if(SPM_USE_CAMERA_OBSERVER_BLK == SWITCH_ON)
    if((SPMObjectLoss.bObjWasSelected == b_TRUE) && (SPMObjectLoss.bObjNowSelected == b_FALSE))
    {
      /*since we had a selected relevant object  but now not=> increase deselection timer*/
      SPMObjectLoss.fDeselectionTimer += (float32)SPM_CYCLE_TIME;
      SPMObjectLoss.fDeselectionTimer = MIN_FLOAT(SPMObjectLoss.fDeselectionTimer,  10.0F * SPM_CYCLE_TIME );
    }
    else
    {
      /*reset deselection timer*/
      SPMObjectLoss.fDeselectionTimer -= SPM_CYCLE_TIME;
      SPMObjectLoss.fDeselectionTimer = MAX_FLOAT(0.0F, SPMObjectLoss.fDeselectionTimer);
    }
  #endif

  /*if a loss of relevance is detected then check range variation (on heavy rain was remarked that when relevance is lost there is a quickly decreasing of range without reach the             threshold for full blk.) go into FULL_DAMP if a loss of relevance is detected and there was detected  a decreasing of range  more then 50 degree with slow variation of confidence but     over thereshold (0.4)*/
  #if(SPM_USE_RANGE_GRADIENT == SWITCH_ON)
    /* initialize values for NEAR and FAR */
    SPMObjectLoss.fObjectLossMapGradient[SYS_SCAN_NEAR] = 0.0f;
    #if(ALGO_CFG_FarScanAvailable)
      SPMObjectLoss.fObjectLossMapGradient[SYS_SCAN_FAR] = 0.0f;
    #endif

    /* check general criteria for using range gradient */
    if(
        (SPM_OBJECT_LOST)
      &&(fHelpRelObjLastDistX > SPM_OBJLOSS_MIN_DISTX_DROPOUT_THRESHOLD )
      )
    {
      RangeGradientThldUp.X = -0.17F;
      RangeGradientThldUp.Y = 0.0F;
      RangeGradientThldDown.X = -1.7075F;
      RangeGradientThldDown.Y = 1.0F;

      #if 0 /*  do not use Gradient of near scan so far. Fusion of NS extrapolated ranges with FL-ranges cause misleading grandients, that lead to FAlse Positive FULL_DAMP events */
        /* solution could be to introduce a fused range in EM, that only includes extrapolated ranges from nearscan */

        /* check scan specific criteria for using range gradient */
        if(
            (SPMData.SPMBlockageCurrentRange[SYS_SCAN_NEAR] < SPM_OBJLOSS_GRADIENT_NEAR_SCAN_THRESHOLD)
          /*if there is a slow variation of range confidence and and range confidence is over 40% for both scans */
          &&(SPMData.SPMBlockageRangeConfidenceGradient[SYS_SCAN_NEAR] > SPM_OBJLOSS_GRADIENT_CONF_VARIATION_THD) 
          &&(SPMData.SPMScanRangeConfidence[SYS_SCAN_NEAR] >= SPM_STATE_CONF_MIN)
          )
        {
          SPMObjectLoss.fObjectLossMapGradient[SYS_SCAN_NEAR] = GDB_Math_LinInterpol(RangeGradientThldDown, RangeGradientThldUp, SPMData.SPMBlockageRangeGradient[SYS_SCAN_NEAR]);
        }
      #endif

      #if(ALGO_CFG_FarScanAvailable)
        #if( (SPM_USE_WIPERS_RANGE_GRADIENT == SWITCH_ON) && (BSW_ALGOPARAMETERS_INTFVER >= 20u) ) 
        /*if is rain*/
          if(
              (pPerfDegrData->Blockage.bWisherRainDetected == b_TRUE) 
          #if(EM_PERF_DEGR_INTFVER >= EM_PERF_DEGR_WIPER_INFO_INT_VER_THLD)
            &&(pPerfDegrData->Blockage.bWisherInformationValid == b_TRUE)
          #endif
            )
          {
            ftemp_AbsolutRangeThreshold = SPM_OBJLOSS_GRADIENT_FAR_SCAN_THRESHOLD_RAIN; 
          }
          else
          {
            ftemp_AbsolutRangeThreshold = SPM_OBJLOSS_GRADIENT_FAR_SCAN_THRESHOLD; 
          }
        #else
          ftemp_AbsolutRangeThreshold = SPM_OBJLOSS_GRADIENT_FAR_SCAN_THRESHOLD; 
        #endif

      /* check scan specific criteria for using range gradient */
        if(
            (SPMData.SPMBlockageCurrentRange[SYS_SCAN_FAR] < ftemp_AbsolutRangeThreshold)
            /*if there is a slow variation of range confidence and and range confidence is over 40% for both scans */
          &&(SPMData.SPMBlockageRangeConfidenceGradient[SYS_SCAN_FAR]  > SPM_OBJLOSS_GRADIENT_CONF_VARIATION_THD) 
          &&(SPMData.SPMScanRangeConfidence[SYS_SCAN_FAR] >= SPM_STATE_CONF_MIN)
          )
        {
          SPMObjectLoss.fObjectLossMapGradient[SYS_SCAN_FAR] = GDB_Math_LinInterpol(RangeGradientThldDown, RangeGradientThldUp, SPMData.SPMBlockageRangeGradient[SYS_SCAN_FAR]);
        }
      #endif
    }
  #endif

  /* filter and limit output values */
  fFilteredValue = SPMDetermineFilterValue();
  GDB_Math_LowPassFilter(&SPMObjectLoss.fObjectLossConfidence, fFilteredValue, SPM_OBJLOSS_CONF_FILTER_FACTOR);
  #if(SPM_OBJLOSS_USE_CUSTOM_FILTER_PARAMETER == SWITCH_ON)
    GDB_Math_LowPassFilter(&SPMObjectLoss.fObjectLossProbability, (float32)SPMObjectLoss.uiNoOfObjLosses * fProbStepWidth, SPM_OBJLOSS_FILTER_PARAMETER);
  #else
    GDB_Math_LowPassFilter(&SPMObjectLoss.fObjectLossProbability, (float32)SPMObjectLoss.uiNoOfObjLosses * fProbStepWidth, SPM_OBJLOSS_FILTER_PARAMETER);
  #endif

  #if(SPM_USE_RANGE_GRADIENT == SWITCH_ON)
    /* in case range gradient should not be used for one scan or both scans, 
    fObjectLossMapGradient[scan] would be zero, and the maximum generation here does not harm */
    #if(ALGO_CFG_FarScanAvailable)
      SPMObjectLoss.fObjectLossProbability = MAX_FLOAT(SPMObjectLoss.fObjectLossProbability, MAX_FLOAT(SPMObjectLoss.fObjectLossMapGradient[SYS_SCAN_NEAR], SPMObjectLoss.fObjectLossMapGradient[SYS_SCAN_FAR]));
    #else
      SPMObjectLoss.fObjectLossProbability = MAX_FLOAT(SPMObjectLoss.fObjectLossProbability, SPMObjectLoss.fObjectLossMapGradient[SYS_SCAN_NEAR]);
    #endif
  #endif

  /* set objectloss prob to 1 if there are fast losses of objects */
  #if(SPM_ENABLE_FAST_BLOCKAGE_TRIGGER == SWITCH_ON)
    if(SPM_OBJECT_LOST)
    {
      fObjLostTimer -= fCycleTime;
    }
    if( (SPMObjectLoss.uiNoOfObjLosses > 2u) && (fObjLostTimer > CML_f_AlmostZero) )
    {
      SPMObjectLoss.fObjectLossProbability = 1.0F;
    }
    if(fObjLostTimer <= CML_f_AlmostZero)
    {
      fObjLostTimer = CML_f_Max(fObjLostTimer, CML_f_AlmostZero);
    }
    if(
        (SPMObjectLoss.uiNoOfObjLosses == 0) 
      &&(CML_f_IsNonZero( (fObjLostTimer - SPM_FAST_BLOCKAGE_TIMER_VAL)))
      )
    {
      fObjLostTimer = SPM_FAST_BLOCKAGE_TIMER_VAL;
    }
  #endif

  SPMObjectLoss.fObjectLossProbability = CML_f_MinMax(SPM_PROBABILITY_MIN, SPM_PROBABILITY_MAX, SPMObjectLoss.fObjectLossProbability);
  SPMObjectLoss.fObjectLossConfidence = CML_f_MinMax(SPM_PROBABILITY_MIN, SPM_PROBABILITY_MAX, SPMObjectLoss.fObjectLossConfidence);
  SPMObjectLoss.uiNoOfObjLosses = CML_Min(CML_Min(SPM_NUMBER_OBJLOSSES_UNTIL_FULL_DAMP_c + 2U, 254U), SPMObjectLoss.uiNoOfObjLosses);
} // PRQA S 7004, 7002
 /* date: 2011-05-18, reviewer: Lonard Jaison Manohar, reason: Cyclometric complexity, Not safety critical */


float32 SPMStationaryCriteria(const PerfDegr_t *pPerfDegrData, 
                                     const float32 RangeMax,  
                                     const float32 RangeMin, 
                                     const float32 RateMax, 
                                     const float32 RateMin, 
                                     const uint8 uScanIndex)
{
  float32 fProbability;
  GDB_Math_Point_t StatRangeUp, StatRangeDown;
  GDB_Math_Point_t StatTgtRateUp, StatTgtRateDown;

  #if (EM_PERF_DEGR_INTFVER >= EM_PERF_INT_VER_THLD)
    if(pPerfDegrData->RangeFiltered[uScanIndex].fStatMeanConfFiltered >= SPM_STATE_CONF_MIN)
  #else
    if(pPerfDegrData->RangeFiltered.fStatMeanConfFiltered >= SPM_STATE_CONF_MIN)
  #endif
    {
      /* stationary extrapolated statistics available -> use it */
      StatRangeUp.X = RangeMax;
      StatRangeUp.Y = SPM_PROBABILITY_STATIONARY_LOW;
      StatRangeDown.X = RangeMin;
      StatRangeDown.Y = SPM_PROBABILITY_STATIONARY_HIGH;
      #if (EM_PERF_DEGR_INTFVER  >= EM_PERF_INT_VER_THLD)
        fProbability = GDB_Math_LinInterpol(StatRangeDown, StatRangeUp, pPerfDegrData->RangeFiltered[uScanIndex].fStatMeanFiltered);
      #else
        fProbability = GDB_Math_LinInterpol(StatRangeDown, StatRangeUp, pPerfDegrData->RangeFiltered.fStatMeanFiltered);
      #endif
    }
    else
    {
      /* stationary extrapolated statistics not available -> use stationary target rate instead */
      StatTgtRateUp.X = RateMax;
      StatTgtRateUp.Y = SPM_PROBABILITY_STATIONARY_LOW;
      StatTgtRateDown.X = RateMin;
      StatTgtRateDown.Y = SPM_PROBABILITY_STATIONARY_HIGH;
      #if (EM_PERF_DEGR_INTFVER  >= EM_PERF_INT_VER_THLD)
        fProbability = GDB_Math_LinInterpol(StatTgtRateDown, StatTgtRateUp, pPerfDegrData->TargetRate[uScanIndex].fTargetRateStat);
      #else
        fProbability = GDB_Math_LinInterpol(StatTgtRateDown, StatTgtRateUp, pPerfDegrData->TargetRate.fTargetRateStat);
      #endif
    }
  return fProbability;
}


float32 SPMDetermineDampProb(const PerfDegr_t *pPerfDegrData 
                             #if(SPM_PREVENT_LOW_SPEED_LOSSES == SWITCH_ON)
                             , float32 fOwnSpeed
                             #endif
                            )
{
  #if( (ALGO_SensorType != ALGO_CFG_ARS400Entry) &&(ALGO_SensorType != ALGO_CFG_ARS510) && (SPM_USE_RCS_CRITERION == SWITCH_ON))
    float32 fHelpRCS;
  #endif
  float32 fTempRangeFused;
  float32 fProbability = SPM_PROBABILITY_MAX; /* initial probability is 100% */
  float32 fProbabilityTemp = SPM_PROBABILITY_MAX; /* initial probability is 100% */
  float32 fPartialProbability[SYS_NUM_OF_SCANS]; /*PRQA S 3203 */ /* 2020-03-17, reviewer:Opreai01, OlaruM, PalloI, reason: Is used below and is activated by config switch statement */
  float32 fCurve = CML_f_Abs(SPM_EGO_CURVE_RAW); /* current curve */
  #if(SPM_USE_RCS_CRITERION == SWITCH_ON)
    GDB_Math_Point_t RCSUp, RCSDown;
  #endif
  GDB_Math_Point_t LatDistUp, LatDistDown;
  GDB_Math_Point_t DistXUp, DistXDown;
  GDB_Math_Point_t RangeUp, RangeDown;
  GDB_Math_Point_t CurveUp, CurveDown;
  #if(SPM_USE_LANE_ASSOCIATION == SWITCH_ON)
    eAssociatedLane_t uLaneAssociation = ASSOC_LANE_EGO;
  #endif
#if(SPM_USE_CUSTOM_OBJECT_SELECTION == SWITCH_ON)
    boolean bPedestrianConfirmed = b_FALSE;
  #endif

  /*****************************************************************/
  /* ex-relevant object must not be a new relevant adjacent object */
  /*****************************************************************/

  #if(SPM_USE_LANE_ASSOCIATION == SWITCH_ON)
    uLaneAssociation = SPM_OBJ_GET_FUNC_LANE_ASSOC(SPMObjectLoss.cLastRelObjID);
  #endif
  
  if(
      (
        (SPM_OBJ_GET_OOI_POS(SPMObjectLoss.cLastRelObjID) <= OBJ_NEXT_LAT_RIGHT_OOI)
      &&(SPM_OBJ_GET_OOI_POS(SPMObjectLoss.cLastRelObjID) >= OBJ_HIDDEN_NEXT_OOI)
      )
    ||(SPMObjectLoss.bRelObjWasMov == b_FALSE)
  #if(SPM_USE_LANE_ASSOCIATION == SWITCH_ON)
    ||(
        (
          (uLaneAssociation == ASSOC_LANE_LEFT)
        ||(uLaneAssociation == ASSOC_LANE_RIGHT)
        ||(uLaneAssociation == ASSOC_LANE_FAR_LEFT)
        ||(uLaneAssociation == ASSOC_LANE_FAR_RIGHT)
        )
      )
  #endif
    )
  {
    fProbability = 0.0F;
  }
  else
  {
    /**********************************************************/
    /* Stationary plausibilization */
    /**********************************************************/
    fPartialProbability[SYS_SCAN_NEAR] = SPMStationaryCriteria(pPerfDegrData, 
                                                               SPM_OBJLOSS_STAT_RANGE_MAX_NEAR, 
                                                               SPM_OBJLOSS_STAT_RANGE_MIN_NEAR, 
                                                               SPM_OBJLOSS_STAT_TGTRATE_MAX, 
                                                               SPM_OBJLOSS_STAT_TGTRATE_MIN, SYS_SCAN_NEAR);

    #if(ALGO_SensorType != ALGO_CFG_ARS400Entry)
      #if(ALGO_CFG_FarScanAvailable)
        fPartialProbability[SYS_SCAN_FAR] = SPMStationaryCriteria(pPerfDegrData, 
                                                                  SPM_OBJLOSS_STAT_RANGE_MAX_FAR, 
                                                                  SPM_OBJLOSS_STAT_RANGE_MIN_FAR, 
                                                                  SPM_OBJLOSS_STAT_TGTRATE_MAX, 
                                                                  SPM_OBJLOSS_STAT_TGTRATE_MIN,SYS_SCAN_FAR);

        fProbability *= CML_f_Max(fPartialProbability[SYS_SCAN_FAR], fPartialProbability[SYS_SCAN_NEAR]);
      #endif
    #else
      fProbability *= fPartialProbability[SYS_SCAN_NEAR];
    #endif


    /**********************************************************/
    /* RCS criterion, weak RCS -> high possibility of damping */
    /**********************************************************/
  #if(SPM_USE_RCS_CRITERION == SWITCH_ON)
    /* 0dB -> 1, 10dB -> 0 */
    RCSUp.X = SPM_OBJLOSS_RCS_UPPER_THLD;
    RCSUp.Y = SPM_PROBABILITY_MIN;
    RCSDown.X = SPM_OBJLOSS_RCS_LOWER_THLD;
    RCSDown.Y = SPM_PROBABILITY_MAX;
    #if((ALGO_SensorType != ALGO_CFG_ARS400Entry) &&(ALGO_SensorType != ALGO_CFG_ARS510))
      if(SPMObjectLoss.fLastRelObjDistX < SPM_OBJLOSS_RANGE_MAX_NEAR_RCS_CRITERIA)
      {
        /*check if we have saved the inial value for RCSNear/Far: false ->take minimum of both filtered values*/
        if(
            (CML_f_IsNonZero(SPMObjectLoss.fRelObjRCSNear - SPM_OBJLOSS_RCS_INIT_VALUE))
          &&(CML_f_IsNonZero(SPMObjectLoss.fRelObjRCSFar - SPM_OBJLOSS_RCS_INIT_VALUE))
          )
        {
          fHelpRCS = MIN_FLOAT(SPMObjectLoss.fRelObjRCSNear,SPMObjectLoss.fRelObjRCSFar);
        }
        else
        {
          /*if RCSNear has not the initial value-> consider RCSNear*/
          if(
              (CML_f_IsNonZero(SPMObjectLoss.fRelObjRCSNear - SPM_OBJLOSS_RCS_INIT_VALUE))
            &&(CML_f_IsZero(SPMObjectLoss.fRelObjRCSFar - SPM_OBJLOSS_RCS_INIT_VALUE))
            )
          {
            fHelpRCS=SPMObjectLoss.fRelObjRCSNear;
          }
          else
          {
            fHelpRCS=SPMObjectLoss.fRelObjRCSFar;
          }
        }
        /*interpolate fHelpRCS*/
        fProbability *= GDB_Math_LinInterpol(RCSDown, RCSUp, fHelpRCS);
      }
      else
      {
        fProbability*=GDB_Math_LinInterpol(RCSDown, RCSUp, SPMObjectLoss.fRelObjRCSFar); 	  
      }
    #else
      fProbability*= GDB_Math_LinInterpol(RCSDown, RCSUp, SPMObjectLoss.fRelObjRCSFiltered);
    #endif
  #endif

  /*************************************************************************************/
  /* Distance from ego lane criterion, far distance -> high possibility of lane change */
  /*************************************************************************************/

  /* 0.5m -> 1, 3m -> 0 */
  LatDistUp.X   = SPM_OBJLOSS_LAT_DIST_UPPER_THLD;
  LatDistUp.Y   = SPM_PROBABILITY_MIN;
  LatDistDown.X = SPM_OBJLOSS_LAT_DIST_LOWER_THLD;
  LatDistDown.Y = SPM_PROBABILITY_MAX;

  fProbability *= GDB_Math_LinInterpol(LatDistDown, LatDistUp, fABS(SPMObjectLoss.fLastRelObjDistFromLane));

  /************************************************************************/
  /* Distance criterion, near x distance -> higher possibility of damping */
  /************************************************************************/
  if(SPMObjectLoss.fLastRelObjDistX > SPM_MIN_DIST_THRESHOLD_DROP_OUT_OBJECT)
  {
    /* 120m -> 0, 80m -> 1 */
    DistXUp.X   = SPM_OBJLOSS_DISTX_UPPER_THLD;
    DistXUp.Y   = SPM_PROBABILITY_MIN;
    DistXDown.X = SPM_OBJLOSS_DISTX_LOWER_THLD;
    DistXDown.Y = SPM_PROBABILITY_MAX;

    fProbability *= GDB_Math_LinInterpol(DistXDown, DistXUp, SPMObjectLoss.fLastRelObjDistX);
  }
  else
  {
    fProbability = 0.0F;
  }

  /****************************************************************************/
  /* extrapolated range criterion, low range -> higher possibility of damping */
  /*            (only increasing of probability possible here)                */
  /****************************************************************************/

  /* 180m -> 1.0, 140m -> 1.5 */
  RangeUp.X   = SPM_OBJLOSS_RANGE_UPPER_THLD_NEAR;
  RangeUp.Y   = SPM_PROBABILITY_MAX;
  RangeDown.X = SPM_OBJLOSS_RANGE_LOWER_THLD_NEAR;
  RangeDown.Y = 1.5F;
  #if(EM_PERF_DEGR_INTFVER  >= EM_PERF_INT_VER_THLD)
    fTempRangeFused = SPM_PD_GET_FUSED_RANGE_NEAR_VALUE;
  #else
    fTempRangeFused = SPM_PD_GET_FUSED_RANGE_VALUE;
  #endif
  fProbabilityTemp = fProbability;
  fProbabilityTemp *= GDB_Math_LinInterpol(RangeDown, RangeUp, fTempRangeFused);

  #if(ALGO_SensorType != ALGO_CFG_ARS400Entry)
    #if(ALGO_CFG_FarScanAvailable)
      /* 350m -> 1.0, 250m -> 1.5 */
      RangeUp.X = SPM_OBJLOSS_RANGE_UPPER_THLD_FAR;
      RangeUp.Y = SPM_PROBABILITY_MAX;
      RangeDown.X = SPM_OBJLOSS_RANGE_LOWER_THLD_FAR;
      RangeDown.Y = SPM_PROBABILITY_INCREASE_FACTOR;
      #if(EM_PERF_DEGR_INTFVER >= EM_PERF_INT_VER_THLD)
        fTempRangeFused = SPM_PD_GET_FUSED_RANGE_FAR_VALUE;
      #else
        fTempRangeFused = SPM_PD_GET_FUSED_RANGE_VALUE;
      #endif
      fProbability *= GDB_Math_LinInterpol(RangeDown, RangeUp, fTempRangeFused);
      fProbability = CML_f_Max(fProbabilityTemp, fProbability);
    #else
      fProbability = CML_f_Max(fProbabilityTemp, fProbability);
    #endif
  #else
    fProbability = fProbabilityTemp;
  #endif

    /************************************************************************************/
    /* Curve criterion, high curve -> higher possibility of object loss without damping */
    /*          (but only for relevant objects with DistX > 50m)                        */ 
    /************************************************************************************/

    if(
        (SPMObjectLoss.fLastRelObjDistX > SPM_OBJLOSS_MIN_DISTX_FOR_CURVE) 
      ||(
          (fEgoSpeed < SPM_EGO_SPEED_TRESHOLD_CURVE_CRITERIA)
        &&(SPMObjectLoss.fLastRelObjDistX > SPM_OBJLOSS_MIN_DISTX_FOR_CURVE_LOW_SPEED)
        )
      )
    {
      /* 0.0003 1/m (radius 3333m) -> 1, 0.005 1/m (radius 200m) -> 0 */
      CurveUp.X = SPM_OBJLOSS_CURVE_UPPER_THLD;
      CurveUp.Y = SPM_PROBABILITY_MIN;
      CurveDown.X = SPM_OBJLOSS_CURVE_LOWER_THLD;
      CurveDown.Y = SPM_PROBABILITY_MAX;

      fProbability *= GDB_Math_LinInterpol(CurveDown, CurveUp, fCurve);
    }
  }

  /*ACC range criterion - If object left ACC range there is no need to count it as loss of object*/
  if(SPMObjectLoss.uRelObjPresInAccRange == FALSE)
  {
    fProbability = 0.0F;
  }

  #if(SPM_PREVENT_LOW_SPEED_LOSSES == SWITCH_ON)
  /*reset damping probability if object was lost at max. 8kph and at over 10m*/
    if(
        (fProbability > SPM_OBJLOSS_DAMP_PROB_THLD)
      &&(fOwnSpeed <= SPM_OBJ_LOSS_SPEED_THLD)
      &&(fHelpRelObjLastDistX > SPM_OBJ_LOSS_MIN_DIST_THLD)
      )
      {
        SPMObjectLoss.fDampingProbability = 0.0F;
      }
  #endif

  /*if pedestrian was confirmed do not count it as lost*/
  #if(SPM_USE_CUSTOM_OBJECT_SELECTION == SWITCH_ON)
    bPedestrianConfirmed = SPMGetPedestrianConfirmation(pEmCustObjList);
    if(bPedestrianConfirmed == b_TRUE)
    {
      fProbability = 0.0F;
    }
  #endif

#if(SPM_FILTER_PEDESTRIANS == SWITCH_ON)
    //filter out objects which are classified as pedestrian after consolidation.
    if(FCTSEN_pEmCustObjList->CustObjects[SPMObjectLoss.cLastRelObjID].e_Classification == EM_VW_OBJECT_CLASS_PEDESTRIAN)
    {
        //set probability to 0 as object is confirmed pedestrian
        fProbability = 0.0F;
    }
#endif

  /* limit probability within 0 and 1 */
  fProbability = MINMAX_FLOAT(SPM_PROBABILITY_MIN, SPM_PROBABILITY_MAX, fProbability);
  /* return probability that this loss of relevance was because of damping */
  return fProbability;
}


boolean SPMDetectObjectDeletion(void)
{
  float32 TempObjAngle;
  boolean bDeletionDetected = b_FALSE;
  uint8 i;
  float32 fABS_OBJ_ANGLE_i;
  float32 fABS_OBJ_LONG_DISPLACEMENT_i;
  float32 fABS_OBJ_LAT_DISPLACEMENT_i;
  /* reset object detector for this cycle */
  SPMObjectLoss.bObjectNowPresent = b_FALSE;

  /* check if there is a moving object at the position of the last relevant object (+ tolerance gates) */
  for(i = 0u; i < (uint8)EM_N_OBJECTS; i++)
  {
    fABS_OBJ_LONG_DISPLACEMENT_i = CML_f_Abs(SPM_OBJ_LONG_DISPLACEMENT(i) - SPMObjectLoss.fLastRelObjDistX);
    fABS_OBJ_LAT_DISPLACEMENT_i = CML_f_Abs(SPM_OBJ_LAT_DISPLACEMENT(i) - SPMObjectLoss.fLastRelObjDistY);
    if(
        (fABS_OBJ_LONG_DISPLACEMENT_i < SPM_OBJLOSS_X_GATE)
      &&(fABS_OBJ_LAT_DISPLACEMENT_i < SPM_OBJLOSS_Y_GATE)
      &&(SPM_OBJ_DYNAMIC_PROPERTY(i) == ARS_OBJECT_PROPERTY_MOVING)
      &&(SPM_OBJ_LIFECYCLES(i) >= SPM_OBJLOSS_MIN_LIFECYCLES)
      )
    {
      /* object found */
      SPMObjectLoss.bObjectNowPresent = b_TRUE;
      /* reset position follow timer */
      SPMObjectLoss.fExRelObjPosFollowTimer = 0.0F;

      /* update x and y distance and VrelX if object is inside FOV */
      fABS_OBJ_ANGLE_i = CML_f_Abs(SPM_OBJ_ANGLE(i));
      if(
          (SPM_OBJ_LONG_DISPLACEMENT(i) > SPM_OBJLOSS_FOV_MIN_DISTX)
        &&(SPM_OBJ_LONG_DISPLACEMENT(i) < SPM_OBJLOSS_FOV_MAX_DISTX)
        &&(fABS_OBJ_ANGLE_i < SPM_OBJLOSS_FOV_MAX_ANGLE)
        )
      {
        SPMObjectLoss.fLastRelObjDistX = SPM_OBJ_LONG_DISPLACEMENT(i);
        SPMObjectLoss.fLastRelObjDistY = SPM_OBJ_LAT_DISPLACEMENT(i);
        SPMObjectLoss.fLastRelObjVrelX = SPM_OBJ_LONG_VREL(i);
      }
      /* if object has left the FOV, end follow mode and set focus on an invalid position */
      else
      {
        SPMCancelObjLossObservation();
      }
    }
  }

  /* no object found, predict position of deleted relevant object but only in x-direction, keep y-position constant */
  if(SPMObjectLoss.bObjectNowPresent == b_FALSE)
  {
    SPMObjectLoss.fLastRelObjDistX += SPMObjectLoss.fLastRelObjVrelX * SPM_CYCLE_TIME;
    /* increment follow timer in prediction mode */
    SPMObjectLoss.fExRelObjPosFollowTimer += SPM_CYCLE_TIME;

    /* Calculate predicated angle of object if it is farther away than SPM_OBJLOSS_FOV_MIN_DISTX */
    if (SPMObjectLoss.fLastRelObjDistX >= C_F32_DELTA)
    {
      TempObjAngle = CML_Rad2Deg(GDBatan_66(CML_f_Abs(SPMObjectLoss.fLastRelObjDistY / SPMObjectLoss.fLastRelObjDistX)));
    }
    else
    {
      TempObjAngle = SPM_OBJLOSS_FOV_MAX_ANGLE;
    }

    /* if prediction has left the FOV or timer has reached max value, end follow mode and set focus on an invalid position */
    if(
        (SPMObjectLoss.fLastRelObjDistX <= SPM_OBJLOSS_FOV_MIN_DISTX)
      ||(SPMObjectLoss.fLastRelObjDistX >= SPM_OBJLOSS_FOV_MAX_DISTX)
      ||(TempObjAngle >= SPM_OBJLOSS_FOV_MAX_ANGLE)
      ||(SPMObjectLoss.fExRelObjPosFollowTimer >= SPM_OBJLOSS_FOLLOWTIMER_MAX)
      )
    {
      SPMCancelObjLossObservation();
    }
  }

  /* new object created at the position of the deleted relevant object */
  if((SPMObjectLoss.bObjectWasPresent == b_FALSE) && (SPMObjectLoss.bObjectNowPresent == b_TRUE))
  {
    SPMObjectLoss.bObjectWasPresent = b_TRUE;
  }
  /* ex-relevant object deleted */ 
  else if((SPMObjectLoss.bObjectWasPresent == b_TRUE) && (SPMObjectLoss.bObjectNowPresent == b_FALSE))
  {
    SPMObjectLoss.bObjectWasPresent = b_FALSE;
    bDeletionDetected = b_TRUE;
  }
  else
  {
    /*nop*/
  }

  return bDeletionDetected;
}


float32 SPMDetermineFilterValue(void)
{
  float32           fFilterValue;
  GDB_Math_Point_t  RCSThldUp, RCSThldDown;

  if(SPMObjectLoss.uiNoOfObjLosses > 0UL)
  {
    fFilterValue = 1.0F;
  }
  else if((SPMObjectLoss.uiNoOfObjLosses == 0UL) && (SPMObjectLoss.cCurrRelObjID != OBJ_INDEX_NO_OBJECT)) // PRQA S 3355, 2995
  /* date: 2015-05-22, reviewer: Lonard jaison Manohar, reason: It has been verified manually and the logic expression is not true always.*/
  {
    RCSThldUp.X = SPM_OBJLOSS_FILTER_THLDUP_X;
    RCSThldUp.Y = 1.0F;
    RCSThldDown.X = SPM_OBJLOSS_FILTER_THLDDOWN_X;
    RCSThldDown.Y = 0.1F;
    fFilterValue = GDB_Math_LinInterpol(RCSThldDown, RCSThldUp, SPMObjectLoss.fRelObjRCSFiltered);
  }
  else
  {
    fFilterValue = 0.0F;
  }

  /* limit and return filter value */
  fFilterValue = CML_f_MinMax(SPM_MINMAX_LOW_THLD, SPM_MINMAX_HIGH_THLD, fFilterValue);
  return fFilterValue;
}


void SPMCancelObjLossObservation(void)
{
  SPMObjectLoss.bObjectWasPresent        = b_FALSE;
  SPMObjectLoss.bObjectNowPresent        = b_FALSE;
  SPMObjectLoss.bPredictPositionOverlap  = b_FALSE;
  SPMObjectLoss.fLastRelObjDistX         = SPM_OBJLOSS_XPOS_INVALID;
  SPMObjectLoss.fLastRelObjDistY         = SPM_OBJLOSS_YPOS_INVALID;
  SPMObjectLoss.fLastRelObjVrelX         = 0.0F;
  SPMObjectLoss.fLastRelObjVrelY         = 0.0F;
  SPMObjectLoss.fLastWidth               = 0.0F;
  SPMObjectLoss.fLastRelObjArelX         = 0.0F;
  SPMObjectLoss.fLastRelObjArelY         = 0.0F;
  SPMObjectLoss.fPredictAngleMin         = SPM_OBJLOSS_INVALID_ANGLE;
  SPMObjectLoss.fPredictAngleMax         = SPM_OBJLOSS_INVALID_ANGLE;
  SPMObjectLoss.fExRelObjPosFollowTimer  = 0.0F;
  SPMObjectLoss.fRelObjRCSFiltered       = 0.0F;
  #if((ALGO_SensorType != ALGO_CFG_ARS400Entry) && (ALGO_SensorType != ALGO_CFG_ARS510))
  SPMObjectLoss.fRelObjRCSFar            = SPM_OBJLOSS_RCS_INIT_VALUE;
  SPMObjectLoss.fRelObjRCSNear           = SPM_OBJLOSS_RCS_INIT_VALUE;
  #endif
  SPMObjectLoss.cCurrRelObjID            = SPM_OBJLOSS_NO_REL_OBJECT;
  SPMObjectLoss.cLastRelObjID            = SPM_OBJLOSS_NO_REL_OBJECT;
  #if(SPM_USE_LAST_CLASSIFICATION == SWITCH_ON)
  SPMObjectLoss.uCurrentClasification = ARS_OBJCLASS_UNCLASSIFIED;
  SPMObjectLoss.uLastClasification = ARS_OBJCLASS_UNCLASSIFIED;
  #endif
}

#if(SPM_USE_CUSTOM_OBJECT_SELECTION == SWITCH_ON)
  boolean SPMGetPedestrianConfirmation(const EM_t_ObjectList_Custom  * pEmCustObjList)
  {
    boolean bPedestrianConfirmed = b_FALSE;
    uint8 objClass;
    objClass = (uint8)pEmCustObjList->CustObjects[SPMObjectLoss.cLastRelObjID].DTR_Obj_Class;
    if(objClass == DTR_CLASS_PEDESTRIAN_HIGH)
    {
      bPedestrianConfirmed = b_TRUE;
    }
    else
    {
      bPedestrianConfirmed = b_FALSE;
    }
    return bPedestrianConfirmed;
  }
#endif
#endif

void SPMInitObjectLoss(void)
{
  #if(SPM_USE_RANGE_GRADIENT)
    uint8 uIndex;
    for(uIndex = SYS_SCAN_NEAR; uIndex < SYS_NUM_OF_SCANS; uIndex ++)
    {
      SPMObjectLoss.fObjectLossProbabilityUsingRangeGradient[uIndex] = 0.0F;
      SPMObjectLoss.fObjectLossMapGradient[uIndex] = 0.0F;
    }
  #endif

  #if( (SPM_USE_RANGE_GRADIENT == SWITCH_ON) || (SPM_PREVENT_LOW_SPEED_LOSSES == SWITCH_ON))
    fHelpRelObjLastDistX          = 0.0F;
  #endif

  #if(SPM_ENABLE_FAST_BLOCKAGE_TRIGGER == SWITCH_ON)
    fObjLostTimer = SPM_FAST_BLOCKAGE_TIMER_VAL;
  #endif
  #if(SPM_USE_CAMERA_OBSERVER_BLK == SWITCH_ON)
    SPMObjectLoss.bObjWasSelected = b_FALSE;
    SPMObjectLoss.bObjNowSelected = b_FALSE;
    SPMObjectLoss.fDeselectionTimer = 0.0F;
  #endif
  SPMObjectLoss.cCurrRelObjID            = SPM_OBJLOSS_NO_REL_OBJECT;
  SPMObjectLoss.cLastRelObjID            = SPM_OBJLOSS_NO_REL_OBJECT;
  SPMObjectLoss.fObjectLossProbability   = 0.0F;
  SPMObjectLoss.fObjectLossConfidence    = 0.0F; 
  SPMObjectLoss.fRelObjRCSFiltered       = 0.0F;
  #if((ALGO_SensorType != ALGO_CFG_ARS400Entry) && (ALGO_SensorType != ALGO_CFG_ARS510))
   SPMObjectLoss.fRelObjRCSNear           = SPM_OBJLOSS_RCS_INIT_VALUE;
   SPMObjectLoss.fRelObjRCSFar            = SPM_OBJLOSS_RCS_INIT_VALUE;
  #endif
  #if(SPM_USE_LAST_CLASSIFICATION == SWITCH_ON)
    SPMObjectLoss.uCurrentClasification = ARS_OBJCLASS_UNCLASSIFIED;
    SPMObjectLoss.uLastClasification = ARS_OBJCLASS_UNCLASSIFIED;
  #endif
  SPMObjectLoss.fLastRelObjDistX         = 0.0F;
  SPMObjectLoss.fLastRelObjDistY         = 0.0F;
  SPMObjectLoss.fLastRelObjDistFromLane  = 0.0F;
  SPMObjectLoss.fDampingProbability      = 0.0F;
  SPMObjectLoss.bRelevanceLossDetected   = b_FALSE;
  SPMObjectLoss.bObjectWasPresent        = b_FALSE;
  SPMObjectLoss.bObjectNowPresent        = b_FALSE;
  SPMObjectLoss.fResetTimer              = SPM_OBJLOSS_TIMER_INIT;
  SPMObjectLoss.fDeadTimeCounter         = 0.0F;
  SPMObjectLoss.uiNoOfObjLosses         = 0U;
  SPMObjectLoss.bRelObjWasMov           = b_TRUE;
  SPMObjectLoss.bPredictPositionOverlap = b_FALSE;
  SPMObjectLoss.fRelObjObsTimer         = 0.0F;
  SPMObjectLoss.fExRelObjPosFollowTimer  = 0.0F;
  SPMObjectLoss.fLastRelObjVrelX         = 0.0F;
  SPMObjectLoss.fLastRelObjArelX         = 0.0F;
  SPMObjectLoss.fLastRelObjVrelY         = 0.0F;
  SPMObjectLoss.fLastRelObjArelY         = 0.0F;
  SPMObjectLoss.fLastWidth               = 0.0F;
  SPMObjectLoss.fPredictAngleMax         = SPM_OBJLOSS_INVALID_ANGLE;
  SPMObjectLoss.fPredictAngleMin         = SPM_OBJLOSS_INVALID_ANGLE;
  SPMObjectLoss.uRelObjPresInAccRange    = FALSE;
}

/* ************************************************************************* */
/*   Copyright ADC-GmbH, Lindau                                              */
/* ************************************************************************* */
#else
/* if Object Loss observer is activated, compute object loss flag for blockage state determination */
  #if SPM_CFG_USE_OBJECTLOSS
  /*****************************************************************************
    (SYMBOLIC) CONSTANTS
  *****************************************************************************/
  /* constants for relevance loss detection and timer handling */
  #define SPM_OBJLOSS_NO_REL_OBJECT             OBJ_INDEX_NO_OBJECT
  #define SPM_OBJLOSS_BSD_TIMER_INIT            300.0F
  #define SPM_OBJLOSS_LCA_TIMER_INIT            300.0F
  #define SPM_OBJLOSS_BSD_TIMER_STEP_BIG        300.0F
  #define SPM_OBJLOSS_LCA_TIMER_STEP_BIG        300.0F
  //#define SPM_OBJLOSS_TIMER_STEP_SMALL           5.0F
  #define SPM_OBJLOSS_BSD_TIMER_MAX             600.0F
  #define SPM_OBJLOSS_LCA_TIMER_MAX             600.0F
  #define SPM_OBJLOSS_DEAD_TIME                  1.0F
  #define SPM_OBJLOSS_MAXVEGO_FOR_RELOBJ_TIMER  20.0F
  
  /* constants for decision if loss of relevance was because of damping */
  #define SPM_OBJLOSS_LCA_DISTX_UPPER_THLD     (-7.0F)
  #define SPM_OBJLOSS_LCA_DISTX_LOWER_THLD     (-60.0F)
  #define SPM_OBJLOSS_BSD_ZONE_XMAX_CUT          2.0F
  #define SPM_OBJLOSS_BSD_ZONE_XMIN_CUT        (-0.5F)
  #define SPM_OBJLOSS_BSD_ZONE_YMAX_CUT          0.25F
  #define SPM_OBJLOSS_ARELX_LOWER_THLD         (-1.0F)
  #define SPM_OBJLOSS_LATDIST_UPPER_THLD         1.5F 
  #define SPM_OBJLOSS_MIN_REL_OBJ_OBSTIMER       0.3F
  #define SPM_OBJLOSS_MIN_VRELX                (-3.0F)
  #define SPM_OBJLOSS_LCA_YMAX                   3.25F
  
  /* constants for ex-relevant object observation */
  #define SPM_OBJLOSS_X_GATE                  2.0F
  #define SPM_OBJLOSS_Y_GATE                  2.0F
  #define SPM_OBJLOSS_MIN_LIFETIME        CONV_CYCLES_TO_LIFETIME(4)
  #define SPM_OBJLOSS_XPOS_INVALID        (-999.0F)
  #define SPM_OBJLOSS_YPOS_INVALID        (-999.0F)
  #define SPM_OBJLOSS_RCS_INVALID         (-999.0F)
  #define SPM_OBJLOSS_TTC_INVALID         (-999.0F)
  #define SPM_OBJLOSS_DIST2COURSE_INVALID (-999.0F)
  #define SPM_OBJLOSS_FOLLOWTIMER_MAX        10.0F
  
  /*Object Loss Parameter*/
  #define SPM_OBJLOSS_CURVE_UPPER_THLD    0.01F
  
  #define SPM_BSD_OBJ_OBSERVATION                    0U
  #define SPM_LCA_OBJ_OBSERVATION                    1U
  #define SPM_LIMIT_MAX_OBJECTS_OBSORVED           254U
  #define SPM_OBJLOSS_MIN_REL_OBJECTS_FOR_RECOVERY   3U
  /*****************************************************************************
    MODULEGLOBAL VARIABLES
  *****************************************************************************/
  SPMObjectLossGeneralInfo_t    SPMObjectLossGeneralInfo;
  /*****************************************************************************
    MODULELOKAL VARIABLES
  *****************************************************************************/
  
  /*****************************************************************************
    FUNCTION PROTOTYPES
  *****************************************************************************/
  /// Detection of object deletions of ex-relevant objects
  ///
  /// @pre                    None
  /// @post                   None 
  /// @param[in]              uObjectLossIndex      Object Observer Index
  /// @param[in]              uBSDorLCAObj          Observer Type LCA or BSD
  ///
  /// @return                 -
  ///
  /// @InOutCorrelation       Detection of object deletions of ex-relevant objects
  ///    
  static boolean SPMDetectObjectDeletion(uint8 uObjectLossIndex, uint8 uBSDorLCAObj);
  /// Check if there is a moving object at the position of the last relevant object
  ///
  /// @pre                    None
  /// @post                   None
  /// @param[in]              uObjectLossIndex      Object Observer Index
  /// @param[in]              uBSDorLCAObj          Observer Type LCA or BSD
  ///
  /// @return                 -
  ///
  /// @InOutCorrelation       Check if there is a moving object at the position of the last relevant object (+ tolerance gates)
  ///  
  static void SPMCheckMovingObjExistatPosOfLastRelObj(uint8 uObjectLossIndex, uint8 uBSDorLCAObj);
  /// Cancel the observation of the ex-relevant object or the ex-relevant object prediction
  ///
  /// @pre                    None
  /// @post                   None 
  /// @param[in]              uObjectLossIndex      Object Observer Index
  /// @param[in]              uBSDorLCAObj          Observer Type LCA or BSD
  ///
  /// @return                 -
  ///
  /// @InOutCorrelation       Cancel the observation of the ex-relevant object or the ex-relevant object prediction, if oberservation leaves the FOV, \n
  ///                         and set focus on an invalid position but keep the number of detected loss up to now
  ///  
  static void SPMProcessObjectLossBSDorLCA(const fSpeed_t fOwnSpeed,uint8 uObjectLossIndex, uint8 uBSDorLCAObj);
  /// Set start values for relevance observation
  ///
  /// @pre                    None
  /// @post                   None 
  /// @param[in]              uObjectLossIndex      Object Observer Index
  /// @param[in]              uBSDorLCAObj          Observer Type LCA or BSD
  /// @param[in]              fOwnSpeed             Ego speed 
  ///
  /// @return                 -
  ///
  /// @InOutCorrelation       Set start values for relevance observation
  ///
  static void SPMSetStartValuesForRelevanceObservation(uint8 uObjectLossIndex, uint8 uBSDorLCAObj);
  /// Check losses of relevance 
  ///
  /// @pre                    None
  /// @post                   None 
  /// @param[in]              uObjectLossIndex      Object Observer Index
  /// @param[in]              uBSDorLCAObj          Observer Type LCA or BSD
  ///
  /// @return                 -
  ///
  /// @InOutCorrelation       Check losses of relevance only if relevance was set for at least x seconds for the first time
  ///
  static void SPMCheckObjectLossReason(const fSpeed_t fOwnSpeed, uint8 uObjectLossIndex, uint8 uBSDorLCAObj);
  /// Check if the relevant object is still the same as before
  ///
  /// @pre                    None
  /// @post                   None
  /// @param[in]              uObjectLossIndex      Object Observer Index
  /// @param[in]              uBSDorLCAObj          Observer Type LCA or BSD
  /// @param[in]              fOwnSpeed             Ego speed 
  ///
  /// @return                 -
  ///
  /// @InOutCorrelation       Check if the relevant object is still the same as before
  ///
  static void SPMCheckObjectRelevanceStillPresent(uint8 uObjectLossIndex);
  /// Check if an object was deleted at this position
  ///
  /// @pre                    None
  /// @post                   None
  /// @param[in]              uObjectLossIndex      Object Observer Index
  ///
  /// @return                 -
  ///
  /// @InOutCorrelation       Check if an object was deleted at this position -> former relevant object
  ///
  static void SPMCheckDeletedFormerRelevantObject(uint8 uObjectLossIndex, uint8 uBSDorLCAObj);
  /// Search for relevant LCA Object with nearest distance
  ///
  /// @pre                    None
  /// @post                   None
  ///
  /// @return                 -
  ///
  /// @InOutCorrelation       Search for relevant LCA Object with nearest distance in x-deriction to Subject
  ///
  static void SPMPGetLCARelObjectsID(void);
  /// Determination of BSD and LCA Performance Degradation in case of Object Loss 
  ///
  /// @pre                    None
  /// @post                   None
  /// @param[in]              uBSDorLCAObj          Observer Type LCA or BSD
  ///
  /// @return                 -
  ///
  /// @InOutCorrelation       Function to Derminate Performace Degradation for BSD and LCA based of relevance object Loss results
  ///
  static void SPMDetermineObjectLossDampingFlag(uint8 uBSDorLCAObj);
  /// BSD and LCA Object Loss function, detection the loss of relevance object 
  ///
  /// @pre                    None
  /// @post                   None
  /// @param[in]              uObjectLossIndex      Object Observer Index
  /// @param[in]              uBSDorLCAObj          Observer Type LCA or BSD
  /// @param[in]              fOwnSpeed             Ego speed 
  ///
  /// @return                 -
  ///
  /// @InOutCorrelation       BSD and LCA Object Loss function, detection the loss of relevance object
  ///
  static void SPMCheckObjectLossOfRelevance(uint8 uObjectLossIndex, uint8 uBSDorLCAObj, const fSpeed_t fOwnSpeed);
  /// Cancel the observation of the ex-relevant object
  ///
  /// @pre                    None
  /// @post                   None
  /// @param[in]              uObjectLossIndex      Object Observer Index
  ///
  /// @return                 -
  ///
  /// @InOutCorrelation       Cancel the observation of the ex-relevant object or the ex-relevant object prediction, if oberservation leaves the FOV, \n 
  ///                         and set focus on an invalid position but keep the number of detected loss up to now.
  ///
  static void SPMCancelObjLossObservation(uint8 uObjectLossIndex);
  /// Update values for relevance observation
  ///
  /// @pre                    None
  /// @post                   None
  /// @param[in]              uObjectLossIndex      Object Observer Index
  ///
  /// @return                 -
  ///
  /// @InOutCorrelation       Update values for relevance observation
  ///
  static void  SPMUpdateObserverValues(uint8 uObjectLossIndex);
  /// Check if the deleted relevant Object was merged
  ///
  /// @pre                    None
  /// @post                   None
  ///
  /// @return                 -
  ///
  /// @InOutCorrelation       Check if the deleted relevant Object was merged
  ///
  static void SPMCheckIfDeletedRelObjectIsMerged(void);
  #if (SPM_MAX_NUM_USED_REL_OBJ_BSD != 0U) 
  static void SPMPGetBSDRelObjectsID(void);
  /// Check if there are relevant BSD objects
  ///
  /// @pre                    None
  /// @post                   None 
  /// @param[in]              iHelpArray        Help array
  ///
  /// @return                 iIndexRelObj      Index of revelant object
  ///
  /// @InOutCorrelation       Check if there are relevant BSD objects
  ///
  static ObjNumber_t SPMPCheckBSDRelevantObjectsExist(ObjNumber_t iHelpArray[]);
  /// Check if the relevant objects from previous cycle still present
  ///
  /// @pre                    None
  /// @post                   None 
  /// @param[in]              iHelpArray        Help array
  /// @param[in]              iIndexRelObj      Index of revelant object
  ///
  /// @return                 bEqualRelObjFound
  ///
  /// @InOutCorrelation       Check if the relevant objects from previous cycle still present
  ///
  static void SPMPCheckBSDRelevantObjectStillPresent(const ObjNumber_t iHelpArray[], const ObjNumber_t iIndexRelObj);
  /// Check if new relevant objects found in this cycle
  ///
  /// @pre                    None
  /// @post                   None 
  /// @param[in]              iHelpArray        Help array
  /// @param[in]              iIndexRelObj      Index of revelant object
  ///
  /// @return                 bEqualRelObjFound
  ///
  /// @InOutCorrelation       Check if new relevant objects found in this cycle
  ///
  static void SPMPCheckBSDNewRelevantObjectFound(const ObjNumber_t iHelpArray[], const ObjNumber_t iIndexRelObj);
  #endif
  /*****************************************************************************
    FUNCTION
  *****************************************************************************/
  
  
  /* ***********************************************************************/ /*!
    @fn               void SPMInitObjectLoss(void)
  
    @brief            Init of Object Loss data
  
  **************************************************************************** */
  void SPMInitObjectLoss(void)
  {
    uint8 iIndexRelObj;
    for(iIndexRelObj=0u; iIndexRelObj<SPM_MAX_NUM_USED_REL_OBJ; iIndexRelObj++)
    {
      SPMObjectLossGeneralInfo.Observer[iIndexRelObj].iCurrRelObjID             = SPM_OBJLOSS_NO_REL_OBJECT;
      SPMObjectLossGeneralInfo.Observer[iIndexRelObj].iLastRelObjID             = SPM_OBJLOSS_NO_REL_OBJECT;
      SPMObjectLossGeneralInfo.Observer[iIndexRelObj].fRelObjRCSFiltered        = 0.0F;
      SPMObjectLossGeneralInfo.Observer[iIndexRelObj].fLastRelObjDistX          = 0.0F;
      SPMObjectLossGeneralInfo.Observer[iIndexRelObj].fLastRelObjDistY          = 0.0F;
      SPMObjectLossGeneralInfo.Observer[iIndexRelObj].fLastRelObjTTC            = 0.0F;
      SPMObjectLossGeneralInfo.Observer[iIndexRelObj].fLastRelObjTTCThreshold   = 0.0F;
      SPMObjectLossGeneralInfo.Observer[iIndexRelObj].bRelevanceLossDetected    = FALSE;
      SPMObjectLossGeneralInfo.Observer[iIndexRelObj].bObjectWasPresent         = FALSE;
      SPMObjectLossGeneralInfo.Observer[iIndexRelObj].bObjectNowPresent         = FALSE;
      SPMObjectLossGeneralInfo.Observer[iIndexRelObj].bMergedState              = FALSE;
      SPMObjectLossGeneralInfo.Observer[iIndexRelObj].fDeadTimeCounter          = 0.0F;
      SPMObjectLossGeneralInfo.Observer[iIndexRelObj].bRelObjWasMov             = TRUE;
      SPMObjectLossGeneralInfo.Observer[iIndexRelObj].fRelObjObsTimer           = 0.0F;
      SPMObjectLossGeneralInfo.Observer[iIndexRelObj].fExRelObjPosFollowTimer   = 0.0F;
      SPMObjectLossGeneralInfo.Observer[iIndexRelObj].fLastRelObjVrelX          = 0.0F;
      SPMObjectLossGeneralInfo.Observer[iIndexRelObj].uLastRelObjAssociatedLane = 0U;
      SPMObjectLossGeneralInfo.Observer[iIndexRelObj].fDist2Course              = 0.0F;
      SPMObjectLossGeneralInfo.Observer[iIndexRelObj].fArelX                    = 0.0F;
    }
    SPMObjectLossGeneralInfo.CommonData.fBSDResetTimer             = SPM_OBJLOSS_BSD_TIMER_INIT;
    SPMObjectLossGeneralInfo.CommonData.fLCAResetTimer             = SPM_OBJLOSS_LCA_TIMER_INIT;
    SPMObjectLossGeneralInfo.CommonData.uBSDNoOfRelObjLosses       = 0U;
    SPMObjectLossGeneralInfo.CommonData.uLCANoOfRelObjLosses       = 0U;
    SPMObjectLossGeneralInfo.CommonData.uBSDOverallNoRelObj     = 0U;
    SPMObjectLossGeneralInfo.CommonData.uLCAOverallNoRelObj     = 0U;
    SPMObjectLossGeneralInfo.CommonData.bBSDPerfDegrFlag        = FALSE;
    SPMObjectLossGeneralInfo.CommonData.bLCAPerfDegrFlag        = FALSE;
    SPMObjectLossGeneralInfo.CommonData.fBSDDampRecoveryCounter = 0.0F;
    SPMObjectLossGeneralInfo.CommonData.fLCADampRecoveryCounter = 0.0F;
  }
  
  /* ***********************************************************************/ /*!
    @fn               void SPMProcessObjectLoss(const fSpeed_t fOwnSpeed)
  
    @brief            Object Loss main function, detection of loss of relevance 
                      for BSD and LCA Objects
  
  **************************************************************************** */
  void SPMProcessObjectLoss(const fSpeed_t fOwnSpeed)
  {
    uint8 iIndexRelObj;
    /*check if there a relevant object which deleted in case of Merging*/
    SPMCheckIfDeletedRelObjectIsMerged();
  
  #if (SPM_MAX_NUM_USED_REL_OBJ_BSD != 0U) 
  /********************************BSD Object Loss Observer********************************/
    /* Get IDs of current 3 BSD relevant objects */
    SPMPGetBSDRelObjectsID();
    for(iIndexRelObj=0u; iIndexRelObj < SPM_MAX_NUM_USED_REL_OBJ_BSD; iIndexRelObj++)
    { 
      /*check loss of relevance for BSD Objects*/
      SPMProcessObjectLossBSDorLCA(fOwnSpeed, iIndexRelObj, SPM_BSD_OBJ_OBSERVATION);
    }
    /*set or reset BSD Damping flag in case of Object Loss*/
    SPMDetermineObjectLossDampingFlag(SPM_BSD_OBJ_OBSERVATION);
  #endif 
  /********************************LCA Object Loss Observer********************************/
    /* Get ID of current LCA relevant object */
    SPMPGetLCARelObjectsID();
    /*check loss of relevance for LCA Object*/
    SPMProcessObjectLossBSDorLCA(fOwnSpeed,SPM_INDEX_USED_REL_OBJ_LCA, SPM_LCA_OBJ_OBSERVATION);
    /*set or reset LCA Damping flag in case of Object Loss*/
    SPMDetermineObjectLossDampingFlag(SPM_LCA_OBJ_OBSERVATION);
    
    /*Object Loss Data coppied in SPMData wil be used in State machine to determine current blockage state in spm_main Modul*/
    SPMData.uObjLossBSDNoOfRelObjLosses = SPMObjectLossGeneralInfo.CommonData.uBSDNoOfRelObjLosses;
    SPMData.uObjLossLCANoOfRelObjLosses = SPMObjectLossGeneralInfo.CommonData.uLCANoOfRelObjLosses;
    SPMData.bObjectLossBSDPerfDegrFlag  = SPMObjectLossGeneralInfo.CommonData.bBSDPerfDegrFlag;
    SPMData.bObjectLossLCAPerfDegrFlag  = SPMObjectLossGeneralInfo.CommonData.bLCAPerfDegrFlag;
  }
  
  /* ***********************************************************************/ /*!
    @fn               static void SPMCheckIfDeletedRelObjectIsMerged(void)
  
    @brief            Check if the deleted relevant Object was merged
  
  **************************************************************************** */
  static void SPMCheckIfDeletedRelObjectIsMerged(void)
  {
   
    uint8 iIndexRelObj;
    for(iIndexRelObj = 0; iIndexRelObj<SPM_MAX_NUM_USED_REL_OBJ; iIndexRelObj++)
    {
      /*check if in Last Cycle an object was relvant*/
      if(SPMObjectLossGeneralInfo.Observer[iIndexRelObj].iLastRelObjID != SPM_OBJLOSS_NO_REL_OBJECT)
      {
        /*check  if the relvant object is deleted*/
        if (FCT_b_GetObjIsDeleted(SPMObjectLossGeneralInfo.Observer[iIndexRelObj].iLastRelObjID))
        {
          /*check  if the relvant object is deleted in case of merging*/
          if(GET_OBJ_GEN_GENERAL(SPMObjectLossGeneralInfo.Observer[iIndexRelObj].iLastRelObjID).eSplitMergeState == EM_GEN_OBJECT_SM_STATE_MERGE)
          {
            SPMObjectLossGeneralInfo.Observer[iIndexRelObj].bMergedState = TRUE;
          }
        }
      }
    }
  }
  
  /* ***********************************************************************/ /*!
    @fn               static void SPMProcessObjectLossBSDorLCA(const fSpeed_t fOwnSpeed, uint8 uObjectLossIndex, ui8_t uBSDorLCAObj)
  
    @brief            BSD and LCA Object Loss function, detection the state of relevance object
  
  **************************************************************************** */
  static void  SPMProcessObjectLossBSDorLCA(const fSpeed_t fOwnSpeed, uint8 uObjectLossIndex, uint8 uBSDorLCAObj)
  {
    /**************************************************************************/
    /*              Relevance was set for an object in this cycle             */
    /**************************************************************************/
    if(   (SPMObjectLossGeneralInfo.Observer[uObjectLossIndex].iCurrRelObjID != SPM_OBJLOSS_NO_REL_OBJECT) 
        &&(SPMObjectLossGeneralInfo.Observer[uObjectLossIndex].iLastRelObjID == SPM_OBJLOSS_NO_REL_OBJECT)
      )
    {
      /* Set start values for relevance observation */
      SPMSetStartValuesForRelevanceObservation(uObjectLossIndex, uBSDorLCAObj);
    }
    /***************************************************************************/
    /*                                Relevance was lost                       */
    /***************************************************************************/
    else if(   (SPMObjectLossGeneralInfo.Observer[uObjectLossIndex].iCurrRelObjID == SPM_OBJLOSS_NO_REL_OBJECT) 
             &&(SPMObjectLossGeneralInfo.Observer[uObjectLossIndex].iLastRelObjID != SPM_OBJLOSS_NO_REL_OBJECT)
           )
    {
      /* Check losses of relevance only if relevance was set for at least x seconds for the first time */
      SPMCheckObjectLossReason(fOwnSpeed, uObjectLossIndex, uBSDorLCAObj);
    }
    /**************************************************************************/
    /*        Relevance is still present and was also in the last cycle       */
    /**************************************************************************/
    else if(   (SPMObjectLossGeneralInfo.Observer[uObjectLossIndex].iCurrRelObjID != SPM_OBJLOSS_NO_REL_OBJECT) 
             &&(SPMObjectLossGeneralInfo.Observer[uObjectLossIndex].iLastRelObjID != SPM_OBJLOSS_NO_REL_OBJECT)
           )
    {
      /* check if the relevant object is still the same as before */
      SPMCheckObjectRelevanceStillPresent(uObjectLossIndex);
    }
    /**************************************************************************/
    /* No relevance was present and no relevance is present in this cycle too */
    /**************************************************************************/
    else
    {
      SPMCheckDeletedFormerRelevantObject(uObjectLossIndex, uBSDorLCAObj);
    }
  
    /**************************************************************************/
    /*                      End of relevance observation                      */
    /**************************************************************************/
  
    /* copy current rel. Obj. ID into last rel. Obj. ID */
    SPMObjectLossGeneralInfo.Observer[uObjectLossIndex].iLastRelObjID = SPMObjectLossGeneralInfo.Observer[uObjectLossIndex].iCurrRelObjID;
   /********************************BSD Object Loss Observer********************************/
    if((uBSDorLCAObj == SPM_BSD_OBJ_OBSERVATION) && (uObjectLossIndex == (SPM_MAX_NUM_USED_REL_OBJ_BSD-1)))
    {
      if(SPMObjectLossGeneralInfo.CommonData.uBSDNoOfRelObjLosses > 0U)
      {
        /* as long as object losses are present, the cycle time is subtracted from the reset timer */
        SPMObjectLossGeneralInfo.CommonData.fBSDResetTimer            -= SPM_CYCLE_TIME;
  //      SPMObjectLossGeneralInfo.CommonData.fBSDDampRecoveryCounter = 0.0F;
      }
  
      /* if the reset timer has expired, reset Object Loss criterion */
      if(SPMObjectLossGeneralInfo.CommonData.fBSDResetTimer <= 0.0F)
      {
        SPMObjectLossGeneralInfo.CommonData.uBSDNoOfRelObjLosses            = 0U;
        SPMObjectLossGeneralInfo.CommonData.fBSDResetTimer        = SPM_OBJLOSS_BSD_TIMER_INIT;
        SPMObjectLossGeneralInfo.CommonData.uBSDOverallNoRelObj= 0U;
      }
  
    }
  /********************************LCA Object Loss Observer********************************/
    else if(uBSDorLCAObj == SPM_LCA_OBJ_OBSERVATION)
    {
      if(SPMObjectLossGeneralInfo.CommonData.uLCANoOfRelObjLosses > 0U)
      {
        /* as long as object losses are present, the cycle time is subtracted from the reset timer */
        SPMObjectLossGeneralInfo.CommonData.fLCAResetTimer            -= SPM_CYCLE_TIME;
  //      SPMObjectLossGeneralInfo.CommonData.fLCADampRecoveryCounter = 0.0F;
      }
  
      /* if the reset timer has expired, reset Object Loss criterion */
      if(SPMObjectLossGeneralInfo.CommonData.fLCAResetTimer <= 0.0F)
      {
        SPMObjectLossGeneralInfo.CommonData.uLCANoOfRelObjLosses             = 0U;
        SPMObjectLossGeneralInfo.CommonData.fLCAResetTimer         = SPM_OBJLOSS_LCA_TIMER_INIT;
        SPMObjectLossGeneralInfo.CommonData.uLCAOverallNoRelObj = 0U;
      }
    }
    else
    {
      /*nop*/
    }
  
  }
  
  /* ***********************************************************************/ /*!
    @fn               static void SPMSetStartValuesForRelevanceObservation(uint8 uObjectLossIndex, uint8 uBSDorLCAObj)
  
    @brief            Set start values for relevance observation
  
  **************************************************************************** */
  static void SPMSetStartValuesForRelevanceObservation(uint8 uObjectLossIndex, uint8 uBSDorLCAObj)
  {
    /* Set start values for relevance observation */
    SPMUpdateObserverValues(uObjectLossIndex);
    SPMObjectLossGeneralInfo.Observer[uObjectLossIndex].bRelevanceLossDetected    = FALSE;
    SPMObjectLossGeneralInfo.Observer[uObjectLossIndex].bObjectWasPresent         = TRUE;
    SPMObjectLossGeneralInfo.Observer[uObjectLossIndex].fDeadTimeCounter          = 0.0F;
    SPMObjectLossGeneralInfo.Observer[uObjectLossIndex].fRelObjObsTimer           = 0.0F;
  
    if(uBSDorLCAObj == SPM_BSD_OBJ_OBSERVATION)
    {
      SPMObjectLossGeneralInfo.CommonData.uBSDOverallNoRelObj++;
      SPMObjectLossGeneralInfo.CommonData.uBSDOverallNoRelObj = MIN(SPM_LIMIT_MAX_OBJECTS_OBSORVED, SPMObjectLossGeneralInfo.CommonData.uBSDOverallNoRelObj);
    }
    else if(uBSDorLCAObj == SPM_LCA_OBJ_OBSERVATION)
    {
      SPMObjectLossGeneralInfo.CommonData.uLCAOverallNoRelObj++;
      SPMObjectLossGeneralInfo.CommonData.uLCAOverallNoRelObj = MIN(SPM_LIMIT_MAX_OBJECTS_OBSORVED, SPMObjectLossGeneralInfo.CommonData.uLCAOverallNoRelObj);
    }
    else
    {
      /*nop*/
    }
  }
  
  /* ***********************************************************************/ /*!
    @fn               static void SPMCheckObjectLossReason(const fSpeed_t fOwnSpeed, uint8 uObjectLossIndex, uint8 uBSDorLCAObj)
  
    @brief            Check losses of relevance only if relevance was set for at least x seconds for the first time 
  
  **************************************************************************** */
  static void SPMCheckObjectLossReason(const fSpeed_t fOwnSpeed, uint8 uObjectLossIndex, uint8 uBSDorLCAObj)
  {
    /* Check losses of relevance only if relevance was set for at least x seconds for the first time */
    if(   (   (SPMObjectLossGeneralInfo.Observer[uObjectLossIndex].fRelObjObsTimer >= (f32_t)(SPM_OBJLOSS_MINRELOBJ_TIMER) ) 
            ||( SPMObjectLossGeneralInfo.CommonData.uBSDNoOfRelObjLosses           >  0UL                                  )    
            ||( SPMObjectLossGeneralInfo.CommonData.uLCANoOfRelObjLosses           >  0UL                                  ) )
        ||(fOwnSpeed                                                  >  (SPM_OBJLOSS_MAXVEGO_FOR_RELOBJ_TIMER * C_MS_KMH)   )   
      )
    {
      SPMCheckObjectLossOfRelevance(uObjectLossIndex, uBSDorLCAObj, fOwnSpeed);
    
      /* check if ex-relevant object is still alive or has been deleted */
      if(!FCT_b_GetObjIsDeleted(SPMObjectLossGeneralInfo.Observer[uObjectLossIndex].iLastRelObjID))
      {
        /* object is still alive but no longer relevant*/
        SPMObjectLossGeneralInfo.Observer[uObjectLossIndex].bObjectWasPresent = TRUE;
      }
    }
  }
  
  /* ***********************************************************************/ /*!
    @fn               static void SPMCheckObjectRelevanceStillPresent(uint8 uObjectLossIndex)
  
    @brief           check if the relevant object is still the same as before
  
  **************************************************************************** */
  static void SPMCheckObjectRelevanceStillPresent(uint8 uObjectLossIndex)
  {
    /* check if the relevant object is still the same as before */
    if(    (SPMObjectLossGeneralInfo.Observer[uObjectLossIndex].iCurrRelObjID                             == SPMObjectLossGeneralInfo.Observer[uObjectLossIndex].iLastRelObjID)
        && ( OBJ_PROBABILITY_OF_EXIST(SPMObjectLossGeneralInfo.Observer[uObjectLossIndex].iCurrRelObjID)   > 0.0F                                                             )
      )
    {
      /* update data of relevant object */
      SPMUpdateObserverValues(uObjectLossIndex);
      SPMObjectLossGeneralInfo.Observer[uObjectLossIndex].fRelObjObsTimer += SPM_CYCLE_TIME;
    }
    /* relevant object has changed, reset all parameters */
    else if (OBJ_PROBABILITY_OF_EXIST(SPMObjectLossGeneralInfo.Observer[uObjectLossIndex].iCurrRelObjID) >  0.0F )
    {
      /* Set start values for relevance observation */
      SPMUpdateObserverValues(uObjectLossIndex);
      SPMObjectLossGeneralInfo.Observer[uObjectLossIndex].bRelevanceLossDetected = FALSE;
      SPMObjectLossGeneralInfo.Observer[uObjectLossIndex].bObjectWasPresent      = TRUE;
      SPMObjectLossGeneralInfo.Observer[uObjectLossIndex].fDeadTimeCounter       = 0.0F;
      SPMObjectLossGeneralInfo.Observer[uObjectLossIndex].fRelObjObsTimer        = 0.0F;
    }
    else
    {
      /*nop*/
    }
  }
  
  /* ***********************************************************************/ /*!
    @fn               static void SPMCheckDeletedFormerRelevantObject(uint8 uObjectLossIndex, uint8 uBSDorLCAObj)
  
    @brief           check if an object was deleted at this position -> former relevant object
  
  **************************************************************************** */
  static void SPMCheckDeletedFormerRelevantObject(uint8 uObjectLossIndex, uint8 uBSDorLCAObj)
  {
    if(SPMObjectLossGeneralInfo.Observer[uObjectLossIndex].bRelevanceLossDetected == TRUE)
    {
      /* check if an object was deleted at this position -> former relevant object */
      if((SPMDetectObjectDeletion(uObjectLossIndex, uBSDorLCAObj) == TRUE) && (SPMObjectLossGeneralInfo.Observer[uObjectLossIndex].fDeadTimeCounter >= SPM_OBJLOSS_DEAD_TIME))
      {
        SPMObjectLossGeneralInfo.Observer[uObjectLossIndex].fDeadTimeCounter = 0.0F;
        if(uBSDorLCAObj == SPM_BSD_OBJ_OBSERVATION)
        {
          SPMObjectLossGeneralInfo.CommonData.uBSDNoOfRelObjLosses += 1U;
          SPMObjectLossGeneralInfo.CommonData.uBSDNoOfRelObjLosses  = MIN(SPM_LIMIT_MAX_OBJECTS_OBSORVED, SPMObjectLossGeneralInfo.CommonData.uBSDNoOfRelObjLosses);
        }
        else if(uBSDorLCAObj == SPM_LCA_OBJ_OBSERVATION)
        {
          SPMObjectLossGeneralInfo.CommonData.uLCANoOfRelObjLosses += 1U;
          SPMObjectLossGeneralInfo.CommonData.uLCANoOfRelObjLosses  = MIN(SPM_LIMIT_MAX_OBJECTS_OBSORVED, SPMObjectLossGeneralInfo.CommonData.uLCANoOfRelObjLosses);
        }
        else
        {
          /*nop*/
        }
      }
      else if(SPMObjectLossGeneralInfo.Observer[uObjectLossIndex].fDeadTimeCounter < SPM_OBJLOSS_DEAD_TIME)
      {
        SPMObjectLossGeneralInfo.Observer[uObjectLossIndex].fDeadTimeCounter += SPM_CYCLE_TIME;
      }
      else
      {
        /*nop*/
      }
    }
    else
    {
      /*nop*/
    }
  }
  
  /* ***********************************************************************/ /*!
    @fn               static void SPMCheckObjectLossOfRelevance(uint8 uObjectLossIndex, uint8 uBSDorLCAObj, const fSpeed_t fOwnSpeed)
  
    @brief            BSD and LCA Object Loss function, detection the loss of relevance object
  
  **************************************************************************** */
  static void SPMCheckObjectLossOfRelevance(uint8 uObjectLossIndex, uint8 uBSDorLCAObj, const fSpeed_t fOwnSpeed)
  {
    const float32 fLastRelObjDistY = fABS(SPMObjectLossGeneralInfo.Observer[uObjectLossIndex].fLastRelObjDistY);
      /*use abs value of Curve radius */
    const float32 fEgoCurve = fABS(GET_EGO_CURVE);
  /********************************BSD Object Loss Observer********************************/
    if(uBSDorLCAObj == SPM_BSD_OBJ_OBSERVATION)
    {
      /* follow instructions if loss of relevance was because of damping */
      if(   (fOwnSpeed                                                            >   SPM_SPEED_MIN_OBJ_LOSS                                           )
          &&(fEgoCurve                                                            <   SPM_OBJLOSS_CURVE_UPPER_THLD                                     )
          &&(SPMObjectLossGeneralInfo.Observer[uObjectLossIndex].bMergedState     ==  FALSE                                                            )
          &&(SPMObjectLossGeneralInfo.Observer[uObjectLossIndex].fLastRelObjDistX >= (SRF_BSD_Globals.fBSDZoneXMin-SPM_OBJLOSS_BSD_ZONE_XMIN_CUT)      )
          &&(SPMObjectLossGeneralInfo.Observer[uObjectLossIndex].fLastRelObjDistX <= (SRF_BSD_Globals.fBSDZoneXMax-SPM_OBJLOSS_BSD_ZONE_XMAX_CUT)      )
          &&(SPMObjectLossGeneralInfo.Observer[uObjectLossIndex].fLastRelObjDistY <= (SRF_BSD_Globals.fBSDZoneYMax-SPM_OBJLOSS_BSD_ZONE_YMAX_CUT)      )
          &&(SPMObjectLossGeneralInfo.Observer[uObjectLossIndex].fLastRelObjDistY >= SRF_BSD_Globals.fBSDZoneYMin                                      )
          &&(SPMObjectLossGeneralInfo.Observer[uObjectLossIndex].fRelObjObsTimer  >  SPM_OBJLOSS_MIN_REL_OBJ_OBSTIMER                                  )
          &&(SPMObjectLossGeneralInfo.Observer[uObjectLossIndex].fLastRelObjVrelX >  SPM_OBJLOSS_MIN_VRELX                                             )
        )
      {
        /*Object is loss increment number of BSD loss objects*/
        SPMObjectLossGeneralInfo.CommonData.uBSDNoOfRelObjLosses                   += 1U;
        SPMObjectLossGeneralInfo.Observer[uObjectLossIndex].bRelevanceLossDetected  = TRUE;
        SPMObjectLossGeneralInfo.CommonData.fBSDResetTimer                         += SPM_OBJLOSS_BSD_TIMER_STEP_BIG; 
        SPMObjectLossGeneralInfo.CommonData.fBSDResetTimer                          = MIN_FLOAT(SPMObjectLossGeneralInfo.CommonData.fBSDResetTimer, SPM_OBJLOSS_BSD_TIMER_MAX);
      }
      else
      {
        /* loss of relevance was NOT because of damping, do not observe position for new rel. objects */
        SPMCancelObjLossObservation(uObjectLossIndex);
      }
    }
  /********************************LCA Object Loss Observer********************************/
    else if(uBSDorLCAObj == SPM_LCA_OBJ_OBSERVATION)
    {
      /* follow instructions if loss of relevance was because of damping */
      if(   (fOwnSpeed                                                                      > SPM_SPEED_MIN_OBJ_LOSS                                                     )
          &&(fEgoCurve                                                                      < SPM_OBJLOSS_CURVE_UPPER_THLD                                               )
          &&(SPMObjectLossGeneralInfo.Observer[uObjectLossIndex].bMergedState              == FALSE                                                                      )
          &&(SPMObjectLossGeneralInfo.Observer[uObjectLossIndex].uLastRelObjAssociatedLane == ASSOC_LANE_LEFT                                                            )
          &&(SPMObjectLossGeneralInfo.Observer[uObjectLossIndex].fLastRelObjDistX           < SPM_OBJLOSS_LCA_DISTX_UPPER_THLD                                           )
          &&(SPMObjectLossGeneralInfo.Observer[uObjectLossIndex].fLastRelObjDistX           > SPM_OBJLOSS_LCA_DISTX_LOWER_THLD                                           )
          &&(SPMObjectLossGeneralInfo.Observer[uObjectLossIndex].fLastRelObjTTC             < SPMObjectLossGeneralInfo.Observer[uObjectLossIndex].fLastRelObjTTCThreshold)
          &&(SPMObjectLossGeneralInfo.Observer[uObjectLossIndex].fDist2Course               > SPM_OBJLOSS_LATDIST_UPPER_THLD                                             )
          &&(SPMObjectLossGeneralInfo.Observer[uObjectLossIndex].fArelX                     > SPM_OBJLOSS_ARELX_LOWER_THLD                                               )
          &&(fLastRelObjDistY                                                               < SPM_OBJLOSS_LCA_YMAX                                                       )
        )
      {
        /*Object is loss increment number of LCA loss objects*/
        SPMObjectLossGeneralInfo.CommonData.uLCANoOfRelObjLosses                   += 1U;
        SPMObjectLossGeneralInfo.Observer[uObjectLossIndex].bRelevanceLossDetected  = TRUE;
        SPMObjectLossGeneralInfo.CommonData.fLCAResetTimer                         += SPM_OBJLOSS_LCA_TIMER_STEP_BIG; 
        SPMObjectLossGeneralInfo.CommonData.fLCAResetTimer                          = MIN_FLOAT(SPMObjectLossGeneralInfo.CommonData.fLCAResetTimer, SPM_OBJLOSS_LCA_TIMER_MAX);
      }
      else
      {
        /* loss of relevance was NOT because of damping, do not observe position for new rel. objects */
        SPMCancelObjLossObservation(uObjectLossIndex);
      }
    }
    else
    {
      /*nop*/
    }
  
  }
  /* ***********************************************************************/ /*!
    @fn               static void SPMDetermineObjectLossDampingFlag(uint8 uBSDorLCAObj)
  
    @brief                  Determination of BSD and LCA Performance Degradation  in case of Object Loss                          
  
  **************************************************************************** */
  static void SPMDetermineObjectLossDampingFlag(uint8 uBSDorLCAObj)
  {
  /********************************BSD Object Loss Observer********************************/
      if(uBSDorLCAObj == SPM_BSD_OBJ_OBSERVATION)
      {
        if(   (SPMObjectLossGeneralInfo.CommonData.bBSDPerfDegrFlag     == FALSE                                       )
            &&(SPMObjectLossGeneralInfo.CommonData.uBSDNoOfRelObjLosses >= SPMBlockageParameters.uiNoOfAllowedObjLosses)
           )
        {
          /*the Object Loss max number of BSD relevance objects is reached set BSD Damping Flag */
          SPMObjectLossGeneralInfo.CommonData.bBSDPerfDegrFlag        = TRUE;
          SPMObjectLossGeneralInfo.CommonData.uBSDNoOfRelObjLosses    = 0U;
          /*Reset Overall counter of found relevant object*/
          SPMObjectLossGeneralInfo.CommonData.uBSDOverallNoRelObj     = 0U;
          /*initialize  the timers*/
          SPMObjectLossGeneralInfo.CommonData.fBSDResetTimer          = SPM_OBJLOSS_BSD_TIMER_INIT;
          SPMObjectLossGeneralInfo.CommonData.fBSDDampRecoveryCounter = 0.0F;
        }
        else if(   (SPMObjectLossGeneralInfo.CommonData.bBSDPerfDegrFlag     == TRUE                                    )
                 &&(SPMObjectLossGeneralInfo.CommonData.uBSDNoOfRelObjLosses == 0U                                      )
                 &&(SPMObjectLossGeneralInfo.CommonData.uBSDOverallNoRelObj  >  SPM_OBJLOSS_MIN_REL_OBJECTS_FOR_RECOVERY)
               )
        {
          if(SPMObjectLossGeneralInfo.CommonData.fBSDDampRecoveryCounter >= SPM_BLOCKAGE_REACTIVATION_DELAY)
          {
            /*BSD Object Loss Damping Recovery timer reached, reset BSD Object Loss Damping Flag*/
            SPMObjectLossGeneralInfo.CommonData.bBSDPerfDegrFlag        = FALSE;
            /*initialize the recovery counter*/
            SPMObjectLossGeneralInfo.CommonData.fBSDDampRecoveryCounter = 0.0F;
            SPMObjectLossGeneralInfo.CommonData.uBSDOverallNoRelObj     = 0U;
          }
          else
          {
            /* increment Recovery Counter */
            SPMObjectLossGeneralInfo.CommonData.fBSDDampRecoveryCounter += SPM_CYCLE_TIME;
          }   
        }
        else
        {
          /*nop*/
        }
      }
  /********************************LCA Object Loss Observer********************************/
      else if(uBSDorLCAObj == SPM_LCA_OBJ_OBSERVATION)
      {
        if(   (SPMObjectLossGeneralInfo.CommonData.bLCAPerfDegrFlag     == FALSE                                       )
            &&(SPMObjectLossGeneralInfo.CommonData.uLCANoOfRelObjLosses >= SPMBlockageParameters.uiNoOfAllowedObjLosses)
          )
        {
          /*the Object Loss max number of LCA relevance objects is reached set LCA Damping Flag */
          SPMObjectLossGeneralInfo.CommonData.bLCAPerfDegrFlag        = TRUE;
          SPMObjectLossGeneralInfo.CommonData.uLCANoOfRelObjLosses    = 0U;
          /*Reset Overall counter of found relevant object*/
          SPMObjectLossGeneralInfo.CommonData.uLCAOverallNoRelObj     = 0U;
          /*initialize  the timers*/                                  
          SPMObjectLossGeneralInfo.CommonData.fLCAResetTimer          = SPM_OBJLOSS_LCA_TIMER_INIT;
          SPMObjectLossGeneralInfo.CommonData.fLCADampRecoveryCounter = 0.0F;
        }
        else if(   (SPMObjectLossGeneralInfo.CommonData.bLCAPerfDegrFlag     == TRUE                                    )
                 &&(SPMObjectLossGeneralInfo.CommonData.uLCANoOfRelObjLosses == 0U                                      )
                 &&(SPMObjectLossGeneralInfo.CommonData.uLCAOverallNoRelObj  >  SPM_OBJLOSS_MIN_REL_OBJECTS_FOR_RECOVERY)
               )
        {
          if((SPMObjectLossGeneralInfo.CommonData.fLCADampRecoveryCounter >= SPM_BLOCKAGE_REACTIVATION_DELAY))
          {
            /*LCA Object Loss Damping Recovery timer reached, reset LCA Object Loss Damping Flag*/
            SPMObjectLossGeneralInfo.CommonData.bLCAPerfDegrFlag        = FALSE;
            /*initialize the recovery counter*/
            SPMObjectLossGeneralInfo.CommonData.fLCADampRecoveryCounter = 0.0F;
            SPMObjectLossGeneralInfo.CommonData.uLCAOverallNoRelObj     = 0U;
          }
          else
          {
            /* increment Recovery Counter */
            SPMObjectLossGeneralInfo.CommonData.fLCADampRecoveryCounter += SPM_CYCLE_TIME;
          }
        }
        else
        {
          /*nop*/
        }
      }
      else
      {
        /*nop*/
      }
  }
  
  /* ***********************************************************************/ /*!
    @fn               bool_t SPMDetectObjectDeletion(uint8 uObjectLossIndex, uint8 uBSDorLCAObj)
  
    @brief            Detection of object deletions of ex-relevant objects 
  
  **************************************************************************** */
  static boolean SPMDetectObjectDeletion(uint8 uObjectLossIndex, uint8 uBSDorLCAObj)
  {
    boolean bDeletionDetected = FALSE;
    /* reset object detector for this cycle */
    SPMObjectLossGeneralInfo.Observer[uObjectLossIndex].bObjectNowPresent = FALSE;
  
    /* check if there is a moving object at the position of the last relevant object (+ tolerance gates) */
    SPMCheckMovingObjExistatPosOfLastRelObj(uObjectLossIndex, uBSDorLCAObj);
  
    /* no object found, predict position of deleted relevant object but only in x-direction, keep y-position constant */
    if(   (SPMObjectLossGeneralInfo.Observer[uObjectLossIndex].bObjectNowPresent == FALSE                   )
        &&(SPMObjectLossGeneralInfo.Observer[uObjectLossIndex].fLastRelObjDistX  >  SPM_OBJLOSS_XPOS_INVALID)
      )
    {
      SPMObjectLossGeneralInfo.Observer[uObjectLossIndex].fLastRelObjDistX += SPMObjectLossGeneralInfo.Observer[uObjectLossIndex].fLastRelObjVrelX * SPM_CYCLE_TIME;
      /* increment follow timer in prediction mode */
      SPMObjectLossGeneralInfo.Observer[uObjectLossIndex].fExRelObjPosFollowTimer += SPM_CYCLE_TIME;
  
      /* if prediction has left the FOV or timer has reached max value, end follow mode and set focus on an invalid position */
      if(   (SPMObjectLossGeneralInfo.Observer[uObjectLossIndex].fLastRelObjDistX        >= (SRF_BSD_Globals.fBSDZoneXMax - SPM_OBJLOSS_BSD_ZONE_XMAX_CUT))
          ||(SPMObjectLossGeneralInfo.Observer[uObjectLossIndex].fExRelObjPosFollowTimer >=  SPM_OBJLOSS_FOLLOWTIMER_MAX                                  )
          ||(SPMObjectLossGeneralInfo.Observer[uObjectLossIndex].fLastRelObjDistX        <= (SRF_BSD_Globals.fBSDZoneXMin - SPM_OBJLOSS_BSD_ZONE_XMIN_CUT))
        )
      {
        SPMCancelObjLossObservation(uObjectLossIndex);
      }
    }
  
    /* new object created at the position of the deleted relevant object */
    if(   (SPMObjectLossGeneralInfo.Observer[uObjectLossIndex].bObjectWasPresent == FALSE) 
        &&(SPMObjectLossGeneralInfo.Observer[uObjectLossIndex].bObjectNowPresent == TRUE )
      )
    {
      SPMObjectLossGeneralInfo.Observer[uObjectLossIndex].bObjectWasPresent = TRUE;
    }
    /* ex-relevant object deleted */ 
    else if(   (SPMObjectLossGeneralInfo.Observer[uObjectLossIndex].bObjectWasPresent == TRUE) 
             &&(SPMObjectLossGeneralInfo.Observer[uObjectLossIndex].bObjectNowPresent == FALSE)
           )
    {
      SPMObjectLossGeneralInfo.Observer[uObjectLossIndex].bObjectWasPresent = FALSE;
      bDeletionDetected = TRUE;
    }
    else
    {
      /*nop*/
    }
  
    return bDeletionDetected;
  }
  
  /* ***********************************************************************/ /*!
    @fn               static void SPMCheckMovingObjExistatPosOfLastRelObj(uint8 uObjectLossIndex, uint8 uBSDorLCAObj)
  
    @brief            check if there is a moving object at the position of the last relevant object (+ tolerance gates)
  
  **************************************************************************** */
  static void SPMCheckMovingObjExistatPosOfLastRelObj(uint8 uObjectLossIndex, uint8 uBSDorLCAObj)
  {
    uint8   i;
    float32 fXDiffAbs;
    float32 fYDiffAbs;
    /* check if there is a moving object at the position of the last relevant object (+ tolerance gates) */
    for(i=0u; i<(ui8_t)EM_N_OBJECTS; i++)
    {
      fXDiffAbs = fABS(FCT_f_GetObjLongDisplacement(i) - SPMObjectLossGeneralInfo.Observer[uObjectLossIndex].fLastRelObjDistX);
      fYDiffAbs = fABS(FCT_f_GetObjLatDisplacement(i)  - SPMObjectLossGeneralInfo.Observer[uObjectLossIndex].fLastRelObjDistY);
      if(    (FCT_b_GetObjIsDeleted(i)       ==         FALSE                            )
          && (fXDiffAbs               <          SPM_OBJLOSS_X_GATE               )
          && (fYDiffAbs               <          SPM_OBJLOSS_Y_GATE               )
          && (OBJ_DYNAMIC_PROPERTY(i) ==         EM_GEN_OBJECT_DYN_PROPERTY_MOVING)
          && (OBJ_LIFETIME(i)         >= (ui16_t)SPM_OBJLOSS_MIN_LIFETIME         ) )
      {
        /* object found */
        SPMObjectLossGeneralInfo.Observer[uObjectLossIndex].bObjectNowPresent = TRUE;
        /* reset position follow timer */
        SPMObjectLossGeneralInfo.Observer[uObjectLossIndex].fExRelObjPosFollowTimer = 0.0F;
  /******************************BSD Object Loss Observer********************************/
        /* follow instructions if loss of relevance was because of damping */
        if(    (uBSDorLCAObj             == SPM_BSD_OBJ_OBSERVATION     )
            && (FCT_f_GetObjLongDisplacement(i) >= SRF_BSD_Globals.fBSDZoneXMin)
            && (FCT_f_GetObjLongDisplacement(i) <= SRF_BSD_Globals.fBSDZoneXMax)
            && (FCT_f_GetObjLatDisplacement(i)  <= SRF_BSD_Globals.fBSDZoneYMax)
            && (FCT_f_GetObjLatDisplacement(i)  >= SRF_BSD_Globals.fBSDZoneYMin)
          )
        {
          /* update x and y distance and VrelX if object is in BSD Warning Zone */
          SPMObjectLossGeneralInfo.Observer[uObjectLossIndex].fLastRelObjDistX = FCT_f_GetObjLongDisplacement(i);
          SPMObjectLossGeneralInfo.Observer[uObjectLossIndex].fLastRelObjDistY = FCT_f_GetObjLatDisplacement(i);
          SPMObjectLossGeneralInfo.Observer[uObjectLossIndex].fLastRelObjVrelX = FCT_f_GetObjLongVrel(i);
          SPMObjectLossGeneralInfo.Observer[uObjectLossIndex].fDist2Course     = OBJ_DIST2COURSE(i);
          SPMObjectLossGeneralInfo.Observer[uObjectLossIndex].fArelX           = OBJ_LONG_AREL(i);
        }
  /********************************LCA Object Loss Observer********************************/
        /* follow instructions if loss of relevance was because of damping */
        else if(    (uBSDorLCAObj                                                                  == SPM_LCA_OBJ_OBSERVATION                                                    )
                 && (SPMObjectLossGeneralInfo.Observer[uObjectLossIndex].uLastRelObjAssociatedLane == ASSOC_LANE_LEFT                                                            )
                 && (SPMObjectLossGeneralInfo.Observer[uObjectLossIndex].fLastRelObjDistX           < SPM_OBJLOSS_LCA_DISTX_UPPER_THLD                                           )
                 && (SPMObjectLossGeneralInfo.Observer[uObjectLossIndex].fLastRelObjDistX           > SPM_OBJLOSS_LCA_DISTX_LOWER_THLD                                           )
                 && (SPMObjectLossGeneralInfo.Observer[uObjectLossIndex].fLastRelObjTTC             < SPMObjectLossGeneralInfo.Observer[uObjectLossIndex].fLastRelObjTTCThreshold)
          )
        {
          /* update x and y distance and VrelX if object is in LCA Warning Zone */
          SPMObjectLossGeneralInfo.Observer[uObjectLossIndex].fLastRelObjDistX = FCT_f_GetObjLongDisplacement(i);
          SPMObjectLossGeneralInfo.Observer[uObjectLossIndex].fLastRelObjDistY = FCT_f_GetObjLatDisplacement(i);
          SPMObjectLossGeneralInfo.Observer[uObjectLossIndex].fLastRelObjVrelX = FCT_f_GetObjLongVrel(i);
          SPMObjectLossGeneralInfo.Observer[uObjectLossIndex].fDist2Course     = OBJ_DIST2COURSE(i);
          SPMObjectLossGeneralInfo.Observer[uObjectLossIndex].fArelX           = OBJ_LONG_AREL(i);
        }
        else
        {
          /* if object has left the FOV, end follow mode and set focus on an invalid position */
          SPMCancelObjLossObservation(uObjectLossIndex);
        }
      }
    }
  }
  
  /* ***********************************************************************/ /*!
    @fn               void SPMCancelObjLossObservation(uint8 uObjectLossIndex)
  
    @brief            Cancel the observation of the ex-relevant object or the ex-relevant object
                      prediction, if oberservation leaves the FOV, and set focus on an invalid position
                      but keep the number of detected loss up to now
  
  **************************************************************************** */
  static void SPMCancelObjLossObservation(uint8 uObjectLossIndex)
  {
    SPMObjectLossGeneralInfo.Observer[uObjectLossIndex].bRelevanceLossDetected    = FALSE;
    SPMObjectLossGeneralInfo.Observer[uObjectLossIndex].bObjectWasPresent         = FALSE;
    SPMObjectLossGeneralInfo.Observer[uObjectLossIndex].bObjectNowPresent         = FALSE;
    SPMObjectLossGeneralInfo.Observer[uObjectLossIndex].bMergedState              = FALSE;
    SPMObjectLossGeneralInfo.Observer[uObjectLossIndex].fLastRelObjDistX          = SPM_OBJLOSS_XPOS_INVALID;
    SPMObjectLossGeneralInfo.Observer[uObjectLossIndex].fLastRelObjDistY          = SPM_OBJLOSS_YPOS_INVALID;
    SPMObjectLossGeneralInfo.Observer[uObjectLossIndex].fRelObjRCSFiltered        = SPM_OBJLOSS_RCS_INVALID;
    SPMObjectLossGeneralInfo.Observer[uObjectLossIndex].uLastRelObjAssociatedLane = ASSOC_LANE_UNKNOWN;
    SPMObjectLossGeneralInfo.Observer[uObjectLossIndex].fLastRelObjVrelX          = 0.0F;
    SPMObjectLossGeneralInfo.Observer[uObjectLossIndex].fExRelObjPosFollowTimer   = 0.0F;
    SPMObjectLossGeneralInfo.Observer[uObjectLossIndex].iCurrRelObjID             = SPM_OBJLOSS_NO_REL_OBJECT;
    SPMObjectLossGeneralInfo.Observer[uObjectLossIndex].iLastRelObjID             = SPM_OBJLOSS_NO_REL_OBJECT;
    SPMObjectLossGeneralInfo.Observer[uObjectLossIndex].fLastRelObjTTC            = SPM_OBJLOSS_TTC_INVALID;
    SPMObjectLossGeneralInfo.Observer[uObjectLossIndex].fLastRelObjTTCThreshold   = SPM_OBJLOSS_TTC_INVALID;
    SPMObjectLossGeneralInfo.Observer[uObjectLossIndex].fDist2Course              = SPM_OBJLOSS_DIST2COURSE_INVALID;
    SPMObjectLossGeneralInfo.Observer[uObjectLossIndex].fArelX                    = 0.0F;
  }
  
  /* ***********************************************************************/ /*!
    @fn               void SPMPGetLCARelObjectsID(void)
  
    @brief            search for relevant LCA Object with nearest distance in x-deriction to Subject
  
  **************************************************************************** */
  static void SPMPGetLCARelObjectsID(void)
  {
    ObjNumber_t iObj;
    SPMObjectLossGeneralInfo.Observer[SPM_INDEX_USED_REL_OBJ_LCA].iCurrRelObjID = SPM_OBJLOSS_NO_REL_OBJECT;
  
    /* check if there is a relevant object object (+ tolerance gates) */
    for(iObj=0; iObj<(ObjNumber_t)EM_N_OBJECTS; iObj++)
    {
      if(GET_FCT_PUB_OBJ(iObj).SRFObjSharedInfo.bLCAWarning == TRUE)
      {
        if(SPMObjectLossGeneralInfo.Observer[SPM_INDEX_USED_REL_OBJ_LCA].iCurrRelObjID == SPM_OBJLOSS_NO_REL_OBJECT)
        {
          /*Save the first detected relevant Object*/
          SPMObjectLossGeneralInfo.Observer[SPM_INDEX_USED_REL_OBJ_LCA].iCurrRelObjID = iObj;
        }
        else if(FCT_f_GetObjLongDisplacement(iObj) < FCT_f_GetObjLongDisplacement(SPMObjectLossGeneralInfo.Observer[SPM_INDEX_USED_REL_OBJ_LCA].iCurrRelObjID))
        {
          /*compare the x-Distance to Subject Vehicle of the Previous Object in Object list */
          /*with next one and save the ID of the nearest Object in x Direction to Subject Vehicle */
          SPMObjectLossGeneralInfo.Observer[SPM_INDEX_USED_REL_OBJ_LCA].iCurrRelObjID = iObj;
        }
        else
        {
          /*nop*/
        }
      }
    }
  }
  
  /* ***********************************************************************/ /*!
    @fn               void SPMPGetBSDRelObjectsID(void)
  
    @brief            search for 3 first relevant BSD Objects in Object List
  
  **************************************************************************** */
  #if (SPM_MAX_NUM_USED_REL_OBJ_BSD != 0U) 
  static void SPMPGetBSDRelObjectsID(void)
  {
  
    ObjNumber_t iIndexRelObj;
    ObjNumber_t iHelpArray[SPM_MAX_NUM_USED_REL_OBJ_BSD];
    
    for(iIndexRelObj=0; iIndexRelObj<(ObjNumber_t)SPM_MAX_NUM_USED_REL_OBJ_BSD; iIndexRelObj++)
    {
      /*initialize the help array with invalid object ID*/
      iHelpArray[iIndexRelObj]        = SPM_OBJLOSS_NO_REL_OBJECT; 
    }
    iIndexRelObj      = 0;
  
    /* check if there are relevant BSD objects */
    iIndexRelObj = SPMPCheckBSDRelevantObjectsExist(iHelpArray);
  
    /*check if the relevant objects from previous cycle still present*/
    SPMPCheckBSDRelevantObjectStillPresent(iHelpArray, iIndexRelObj);
  
    /*check if new relevant objects found in this cycle*/
    SPMPCheckBSDNewRelevantObjectFound(iHelpArray, iIndexRelObj);
  }
  
  /* ***********************************************************************/ /*!
    @fn              SPMPCheckBSDRelevantObjectsExist(ObjNumber_t iHelpArray[])
  
    @brief            check if there are relevant BSD objects
  
  **************************************************************************** */
  
  static ObjNumber_t SPMPCheckBSDRelevantObjectsExist(ObjNumber_t iHelpArray[])
  {
    ObjNumber_t iObj;
    ObjNumber_t iObjHelp;
    ObjNumber_t iHelpIndex;
    boolean     bObjAlreadyExist  = FALSE;
    boolean     bEqualRelObjFound = FALSE;
    ObjNumber_t iIndexRelObj = 0;
  
    for(iObjHelp=0; iObjHelp<(ObjNumber_t)SPM_MAX_NUM_USED_REL_OBJ_BSD; iObjHelp++)
    {
      iObj=0;
      while(   (iObj         < (ObjNumber_t)EM_N_OBJECTS                )
             &&(iIndexRelObj < (ObjNumber_t)SPM_MAX_NUM_USED_REL_OBJ_BSD)
           )
      {
        if(GET_FCT_PUB_OBJ(iObj).SRFObjSharedInfo.bBSDWarning == TRUE)
        {
          /*Save the IDs of relevant objects which found in this cycle*/
          iHelpIndex = 0;
          while(iHelpIndex < iIndexRelObj)
          {
            /*Check if the found object already saved*/
            if(iHelpArray[iHelpIndex] == iObj)
            {
              /*found object already saved*/
              bObjAlreadyExist = TRUE;
              iHelpIndex       = iIndexRelObj;
            }
            iHelpIndex++;
          }
          if(bObjAlreadyExist == FALSE)
          {
            /*found object not saved*/
            /*check if the found was present*/
            if(SPMObjectLossGeneralInfo.Observer[iObjHelp].iCurrRelObjID == iObj)
            {
              /*object was present save object ID and Incraese Index of Rel Object and breack search function*/
              iHelpArray[iIndexRelObj] = iObj;
              bEqualRelObjFound = TRUE;
              iObj = EM_N_OBJECTS;
              /*Increase Number of relevant objects found in this cycle*/
              iIndexRelObj++;
            }
            /*check if this is the first new rel object*/
            else if(iHelpArray[iIndexRelObj] == SPM_OBJLOSS_NO_REL_OBJECT)
            {
              /*Save the first new rel found object*/
              iHelpArray[iIndexRelObj] = iObj;
              iObj++;
            }
            else
            {
              iObj++;
            }
          }
          else
          {
            iObj++;
            bObjAlreadyExist = FALSE;
          }
        }
        else
        {
          iObj++;
        }
      }
      if(   (iIndexRelObj              < (ObjNumber_t)SPM_MAX_NUM_USED_REL_OBJ_BSD)
          &&(iHelpArray[iIndexRelObj] != SPM_OBJLOSS_NO_REL_OBJECT                )
          &&(bEqualRelObjFound         == FALSE                                    )
        )
      {
        /*if new rel found object increase Number of relevant objects found in this cycle*/
        iIndexRelObj++;
      }
      bEqualRelObjFound = FALSE;
      bObjAlreadyExist  = FALSE;
    }
    return  iIndexRelObj;
  }
  
  /* ***********************************************************************/ /*!
    @fn              SPMPCheckBSDRelevantObjectStillPresent(const ObjNumber_t iHelpArray[], const ObjNumber_t iIndexRelObj)
  
    @brief            check if the relevant objects from previous cycle still present
  
  **************************************************************************** */
  
  static void SPMPCheckBSDRelevantObjectStillPresent(const ObjNumber_t iHelpArray[], const ObjNumber_t iIndexRelObj)
  {
    boolean     bEqualRelObjFound = FALSE;
    ObjNumber_t iObjHelp;
    ObjNumber_t iObj;
    for(iObjHelp=0; iObjHelp<(ObjNumber_t)SPM_MAX_NUM_USED_REL_OBJ_BSD; iObjHelp++)
    {
      iObj = 0;
      while(iObj < iIndexRelObj)
  
      {
        /*if the object still present not change*/
        if(SPMObjectLossGeneralInfo.Observer[iObjHelp].iCurrRelObjID == iHelpArray[iObj] )
        {
          bEqualRelObjFound = TRUE;
          iObj = iIndexRelObj;
        }
        else
        {
          iObj++; 
        }
      }
      if(  (bEqualRelObjFound                                         == FALSE                    )
         &&(SPMObjectLossGeneralInfo.Observer[iObjHelp].iCurrRelObjID != SPM_OBJLOSS_NO_REL_OBJECT))
      {
        /*delete the object if it not exist anymore in this cycle */
        SPMObjectLossGeneralInfo.Observer[iObjHelp].iCurrRelObjID = SPM_OBJLOSS_NO_REL_OBJECT;
      }
      else
      {
        bEqualRelObjFound = FALSE;
      }
    }
  }
  
  /* ***********************************************************************/ /*!
    @fn               void SPMPCheckBSDNewRelevantObjectFound(ObjNumber_t iHelpArray[], const ObjNumber_t iIndexRelObj)
  
    @brief            check if new relevant objects found in this cycle
  
  **************************************************************************** */
  
  static void SPMPCheckBSDNewRelevantObjectFound(const ObjNumber_t iHelpArray[], const ObjNumber_t iIndexRelObj)
  {
    ObjNumber_t iObjHelp;
    ObjNumber_t iObj;
    boolean bObjAlreadyExist = FALSE;
  
    for(iObjHelp=0; iObjHelp<iIndexRelObj; iObjHelp++)
    {
      /*check if the found object is a new one*/
      iObj=0;
      while(iObj<(ObjNumber_t)SPM_MAX_NUM_USED_REL_OBJ_BSD)
      {
        if(iHelpArray[iObjHelp] == SPMObjectLossGeneralInfo.Observer[iObj].iCurrRelObjID)
        {
          /*the object already exist not change*/
          bObjAlreadyExist = TRUE;
          iObj = (ObjNumber_t)SPM_MAX_NUM_USED_REL_OBJ_BSD;
        }
        else
        {
          iObj++; 
        }
      }
  
      /*if new one found*/
      if(bObjAlreadyExist == FALSE)
      {
        /*new relevant object found*/
        iObj=0;
        while(iObj<(ObjNumber_t)SPM_MAX_NUM_USED_REL_OBJ_BSD )
        {
          if(SPMObjectLossGeneralInfo.Observer[iObj].iCurrRelObjID == SPM_OBJLOSS_NO_REL_OBJECT)
          {
            /*Save the new object in empty observer*/
            SPMObjectLossGeneralInfo.Observer[iObj].iCurrRelObjID = iHelpArray[iObjHelp];
            iObj = (ObjNumber_t)SPM_MAX_NUM_USED_REL_OBJ_BSD;
          }
          else
          {
            iObj++; 
          }
        }
      }
      else
      {
        bObjAlreadyExist = FALSE;
      }
    }
  }
  #endif 
  
  /* ***********************************************************************/ /*!
    @fn               static void SPMUpdateObserverValues(uint8 uObjectLossIndex)
  
    @brief            update values for relevance observation
  
  **************************************************************************** */
  static void  SPMUpdateObserverValues(uint8 uObjectLossIndex)
  {
    SPMObjectLossGeneralInfo.Observer[uObjectLossIndex].fRelObjRCSFiltered        = GET_OBJ_SRR_SENSOR_SPECIFIC(SPMObjectLossGeneralInfo.Observer[uObjectLossIndex].iCurrRelObjID).fRCS;
    SPMObjectLossGeneralInfo.Observer[uObjectLossIndex].fLastRelObjDistX          = FCT_f_GetObjLongDisplacement(SPMObjectLossGeneralInfo.Observer[uObjectLossIndex].iCurrRelObjID);
    SPMObjectLossGeneralInfo.Observer[uObjectLossIndex].fLastRelObjDistY          = FCT_f_GetObjLatDisplacement(SPMObjectLossGeneralInfo.Observer[uObjectLossIndex].iCurrRelObjID);
    SPMObjectLossGeneralInfo.Observer[uObjectLossIndex].fLastRelObjVrelX          = FCT_f_GetObjLongVrel(SPMObjectLossGeneralInfo.Observer[uObjectLossIndex].iCurrRelObjID);
    SPMObjectLossGeneralInfo.Observer[uObjectLossIndex].fLastRelObjTTC            = GET_FCT_PUB_OBJ(SPMObjectLossGeneralInfo.Observer[uObjectLossIndex].iCurrRelObjID).SRFObjSharedInfo.fTTC;
    SPMObjectLossGeneralInfo.Observer[uObjectLossIndex].fLastRelObjTTCThreshold   = FCT_p_GetFCT_CAFObjPointer(SPMObjectLossGeneralInfo.Observer[uObjectLossIndex].iCurrRelObjID).LCAObjInfo.fTTCThreshold;
    SPMObjectLossGeneralInfo.Observer[uObjectLossIndex].uLastRelObjAssociatedLane = FCT_p_GetFCTPubObjPointer(SPMObjectLossGeneralInfo.Observer[uObjectLossIndex].iCurrRelObjID)->LaneInformation.eAssociatedLane;
    SPMObjectLossGeneralInfo.Observer[uObjectLossIndex].fDist2Course              = OBJ_DIST2COURSE(SPMObjectLossGeneralInfo.Observer[uObjectLossIndex].iCurrRelObjID);
    SPMObjectLossGeneralInfo.Observer[uObjectLossIndex].fArelX                    = OBJ_LONG_AREL(SPMObjectLossGeneralInfo.Observer[uObjectLossIndex].iCurrRelObjID);
  }
#endif

#endif /*(FCT_CFG_SIGNAL_PERF_MONITORING)*/
#endif /*SPM_SRR_TECHNOLOGY*/

