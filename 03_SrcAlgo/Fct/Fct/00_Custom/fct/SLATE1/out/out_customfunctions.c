/*! \file **********************************************************************

COMPANY:                   COPYRIGHT (C) Continental AG

PROJECT:                   Adaptive Cruise Control (ACC)

CPU:                       CPU-Independent

COMPONENT:                 SLATE_OUT (Output)

PACKAGENAME:               out_customfunctions.c

DESCRIPTION:               Custom Functions for ACC Output (OUT) module

AUTHOR:                    Boll Marie-Theres (uidu1091)

CREATION DATE:             17.06.2016

VERSION:                   $Revision: 1.32 $

LEGACY VERSION:            Revision: 1.16

**************************************************************************** */


/*****************************************************************************
  INCLUDES
*****************************************************************************/

#include "out.h"
#include "out_custom.h"

#if (FCT_CFG_ACC_OUTPUT)
/*****************************************************************************
  MODULE DESCRIPTION
*****************************************************************************/

/**
@defgroup out_customfunctions Custom functions
@ingroup out
@brief          This module contains customer specific functions for ACC OUT module.
@{
*/
/*****************************************************************************
  GLOBAL CONSTANTS (MODULE SCOPE)
*****************************************************************************/


/*****************************************************************************
  GLOBAL VARIABLES (MODULE SCOPE)
*****************************************************************************/



/*****************************************************************************
  LOCAL SYMOBLIC CONSTANTS
*****************************************************************************/

#if (FCT_CFG_CAMERA_OBJECT_DETECTION) && (OUT_CFG_CUSTOM_XY_RELEVANCE)
/*! The camera confirmation gate used to decide if a given object is
camera confirmed or not */
#define OUT_PAR_CAM_CONF_X_RELEVANCE_GATE      10u
/*! X relevance parameter for camera confirmed objects:
this specifies the X relevance for an object that has non-zero
X relevance based on radar data and is confirmed by the camera */
#define OUT_PAR_CAM_CONF_DEFAULT_X_RELEVANCE  15u
/*! X relevance parameter for camera confirmed objects that
are seen to be performing a cut-out maneauver by the camera */
#define OUT_PAR_CAM_CONF_CUT_OUT_X_RELEVANCE  22u
/*! Maximal X relevance parameter for an object not confirmed by
the camera */
#define OUT_PAR_NO_CAM_CONF_MAX_X_RELEVANCE   8u
#endif


/*****************************************************************************
  LOCAL MACROS
*****************************************************************************/

#if OUT_CFG_CUSTOM_DRIVING_TUBE_MAPPING
#define OUT_DRIVING_TUBE_MAPPING(iObj) pSLATE_CustomOutput->CustObjData[iObj].Relevance.DrivingTubeMapping 
#endif

#if OUT_CFG_CUSTOM_XY_RELEVANCE
/* <ln_offset:+1 MISRA Rule 19.7: reviewer name: Ungvary date: 24-09-2012 reason: well defined function like macro for accessing i-th object */
#define OUT_OBJ_RELEVANCE_X(iObj)      pSLATE_CustomOutput->CustObjData[iObj].Relevance.fRelevanceX
/* <ln_offset:+1 MISRA Rule 19.7: reviewer name: Ungvary date: 24-09-2012 reason: well defined function like macro for accessing i-th object */
#define OUT_OBJ_RELEVANCE_Y(iObj)      pSLATE_CustomOutput->CustObjData[iObj].Relevance.fRelevanceY
#endif


/*****************************************************************************
  LOCAL CONSTANTS
*****************************************************************************/

#if OUT_CFG_CUSTOM_XY_RELEVANCE
/*! value for invalid distance */
#define DIST_INVALID                    (999.0F)
/*! interface scale factor from float to int*/
#define OUT_RELEVANCE_SCALE              (100.f)
#endif

#if OUT_CFG_CUSTOM_XY_RELEVANCE
/*************************************/
/* longitudinal relevance parameters */
/*************************************/

/* longitudinal relevance X: fMin, fMax */
#define OUT_CUSTOM_REL_X_MIN              (0.0F)  /* minimum longitudinal relevance */
#define OUT_CUSTOM_REL_X_MAX              (1.0F)  /* maximum longitudinal relevance */

/* switch to use distance for longitudinal relevance: bUseDist */
#define OUT_CUSTOM_REL_X_DIST_USE         (SWITCH_ON)

/* longitudinal relevance X by Distance: fDistMin, fDistMax, fDistStep */
#define OUT_CUSTOM_REL_X_DIST_MIN         (0.1F)    /* minimum longitudinal relevance for distance criterion */
#define OUT_CUSTOM_REL_X_DIST_MAX         (1.0F)    /* maximum longitudinal relevance for distance criterion */
#define OUT_CUSTOM_REL_X_DIST_STEP        (0.2F)    /* decrement longitudinal relevance by step from object to object */

/* KEEP IN MIND: NOT AUTOSAR!!! increasing distance --> neg. v_rel */
/* actual disable (y_n = 0) */

/********************************/
/* lateral relevance parameters */
/********************************/

/* lateral relevance Y: fMin, fMax */
#define OUT_CUSTOM_REL_Y_MIN              (0.0F)  /* minimum lateral relevance */
#define OUT_CUSTOM_REL_Y_MAX              (1.0F)  /* maximum lateral relevance */

/* lateral relevance threshold - according to customer spec (P_OBR_Rel_y_Grenze) */
/* - an object within ego lane must have lateral relevance > threshold */
/* - an object outside ego lane must have lateral relevance <= threshold */
#define OUT_CUSTOM_REL_Y_THRESHOLD        (0.5F)

/* switch to use cut-in/out potential for lateral relevance: bUseCutPotential */
#define OUT_CUSTOM_REL_Y_LANE_CUT_USE     (SWITCH_ON)

/* lateral relevance Y with cut-in/out potential: fLaneInCut100 */
/* - lateral relevance for objects in ego lane with 100% cut out potential */
/* - value is customer min threshold + 0.1 => 0.6 */
#define OUT_CUSTOM_REL_Y_LANE_IN_CUT_100  (OUT_CUSTOM_REL_Y_THRESHOLD + 0.1F)

/* lateral relevance Y with cut-in/out potential: fLaneInCut0 */
/* - lateral relevance for objects in ego lane with 0% cut out potential */
/* - value is maximum lateral relevance => 1.0 */
#define OUT_CUSTOM_REL_Y_LANE_IN_CUT_0    (OUT_CUSTOM_REL_Y_MAX)

/* lateral relevance Y with cut-in/out potential: fLaneInCut50 */
/* - lateral relevance for objects in ego lane with 0% < cut out potential < 100% */
/* - value must be between Cut0 and Cut100 => Cut0 > value > Cut100 */
/* - value is Cut0 - 0.5*(Cut0-Cut100) => 0.8 */
#define OUT_CUSTOM_REL_Y_LANE_IN_CUT_50   (OUT_CUSTOM_REL_Y_LANE_IN_CUT_0 - (0.5F*(OUT_CUSTOM_REL_Y_LANE_IN_CUT_0-OUT_CUSTOM_REL_Y_LANE_IN_CUT_100)))

/* lateral relevance Y with cut-in/out potential: fLaneOutCut100 */
/* - lateral relevance for objects not in ego lane with 100% cut in potential */
/* - value is customer min threshold => 0.5 */
#define OUT_CUSTOM_REL_Y_LANE_OUT_CUT_100 (OUT_CUSTOM_REL_Y_THRESHOLD)

/* lateral relevance Y with cut-in/out potential: fLaneOutCut0 */
/* - lateral relevance for objects not in ego lane with 0% cut in potential */
/* - value is minimum lateral relevance + 0.1 => 0.1 */
#define OUT_CUSTOM_REL_Y_LANE_OUT_CUT_0   (OUT_CUSTOM_REL_Y_MIN + 0.1F)

/* lateral relevance Y with cut-in/out potential: fLaneOutCut50 */
/* - lateral relevance for objects not in ego lane with 0% < cut in potential < 100% */
/* - value must be between Cut0 and Cut100 => Cut0 < value < Cut100 */
/* - value is Cut0 + 0.5*(Cut100-Cut0) => 0.3 */
#define OUT_CUSTOM_REL_Y_LANE_OUT_CUT_50  (OUT_CUSTOM_REL_Y_LANE_OUT_CUT_0 + (0.5F*(OUT_CUSTOM_REL_Y_LANE_OUT_CUT_100-OUT_CUSTOM_REL_Y_LANE_OUT_CUT_0)))

/*! Define for obtaining the gate from which camera confirmation allows
higher X relevance values */
/*#define OUT_CAM_CONF_X_RELEVANCE_GATE    OUT_PAR_CAM_CONF_X_RELEVANCE_GATE*/
#define OUT_CAM_CONF_X_RELEVANCE_GATE    OOIRelevanceParameter.CustomRelevanceX.uCamConfRelevanceGate
#endif

/*! Value for extension brackets that are not filled */
#ifndef INITVALUE_BRACKETPOSITION       
#define INITVALUE_BRACKETPOSITION       (999.f)
#endif

/* Measurement message for timegap filling function (OUT_v_CustomControlDistanceInfo) defines */
#define OUT_BMW_MIN_CONTROL_DIST   40.f    /*Minimum Control Distance*/
#define OUT_BMW_MAX_CONTROL_DIST   168.33f  /*Maximum Control Distance*/
#define OUT_BMW_SLOPE_FACTOR       2.2f    /*Slope of Control Distance*/

/*****************************************************************************
  LOCAL TYPEDEFS
*****************************************************************************/

#if (OUT_CFG_CUSTOM_CRITERIA_MATRIX_PROCESSING)
/*! Trace bracket extentions debugging information */
typedef struct { // PRQA S 635
  /* date: 2015-07-06, reviewer: Rachit Sharma, reason: Project specific type definition */
#if (defined(_MSC_VER))
  uint32 TrackWidthSeek_Left              :1; /* RadiusUndFahrbahnbreite mask: 0x0001 */
  uint32 TrackWidthSeek_Right             :1; /* RadiusUndFahrbahnbreite mask: 0x0002 */
  uint32 TrackWidthTrck_Left              :1; /* Fahrbahnbreite mask: 0x0004 */
  uint32 TrackWidthTrck_Right             :1; /* Fahrbahnbreite mask: 0x0008 */
#if (LA_CFG_EXT_RELEVANT_OBJECT)
  uint32 AddExtRelevantObject_Left        :1; /* VorbeifahrtRelObjekt mask: 0x0010 */
  uint32 AddExtRelevantObject_Right       :1; /* VorbeifahrtRelObjekt mask: 0x0020 */
#else
  ubit32 NotUsed                          :2; /*! Default bit field entry for keeping the same mask */
#endif
  uint32 AddExtObjApprox_Left             :1; /* Approx mask: 0x0040 */
  uint32 AddExtObjApprox_Right            :1; /* Approx mask: 0x0080 */

  uint32 AddRestCurveOuterBorder_Left     :1; /* KurveAussenrand mask: 0x0100 */
  uint32 AddRestCurveOuterBorder_Right    :1; /* KurveAussenrand mask: 0x0200 */
  uint32 RestTargetOutsideBrackets_Left   :1; /* ZielAblage mask: 0x0400 */
  uint32 RestTargetOutsideBrackets_Right  :1; /* ZielAblage mask: 0x0800 */
  uint32 RestAnalogRoadBorder_Left        :1; /* AnalogerStrassenrand mask: 0x1000 */
  uint32 RestAnalogRoadBorder_Right       :1; /* AnalogerStrassenrand mask: 0x2000 */

  uint32 RestNeighbourhoodRelObj_Left     :1; /* UmfeldRelevantesObjekt mask: 0x4000 */
  uint32 RestNeighbourhoodRelObj_Right    :1; /* UmfeldRelevantesObjekt mask: 0x8000 */
#if (LA_CFG_ADD_RESTRICTION_OBJ_TRACE)
  uint32 RestObjectTrace_Left             :1;
  uint32 RestObjectTrace_Right            :1;
#endif
  uint32 ExtRoadBorder_Left               :1; /* Richtungsfahrspuren mask: 0x10000 */
  uint32 ExtRoadBorder_Right              :1; /* Richtungsfahrspuren mask: 0x20000 */
  uint32 ExtCurveInnerBorder_Left         :1; /* KurveInnenrand mask: 0x40000 */
  uint32 ExtCurveInnerBorder_Right        :1; /* KurveInnenrand mask: 0x80000 */

  uint32 ExtRoadBorderCI_Left             :1; /* RIchtungsfahrspurenKI mask: 0x100000 */
  uint32 ExtRoadBorderCI_Right            :1; /* RIchtungsfahrspurenKI mask: 0x200000 */
  uint32 ExtFollowObjectIntoCurve_Left    :1; /* ObjektWinkelVerfolgung mask: 0x400000 */
  uint32 ExtFollowObjectIntoCurve_Right   :1; /* ObjektWinkelVerfolgung mask: 0x800000 */

  uint32 ExtRoadWorksRoadBorder_Left      :1; /* RoadWorksRoadBorder mask: 0x1000000 */
  uint32 ExtRoadWorksRoadBorder_Right     :1; /* RoadWorksRoadBorder mask: 0x2000000 */
#else
  uint32 Reserved                         :6; /* mask: 0xFC000000 */

  uint32 ExtRoadWorksRoadBorder_Right     :1; /* RoadWorksRoadBorder mask:0x2000000 */
  uint32 ExtRoadWorksRoadBorder_Left      :1; /* RoadWorksRoadBorder mask:0x1000000 */

  uint32 ExtFollowObjectIntoCurve_Right   :1; /* ObjektWinkelVerfolgung mask:0x800000 */
  uint32 ExtFollowObjectIntoCurve_Left    :1; /* ObjektWinkelVerfolgung mask:0x400000 */
  uint32 ExtRoadBorderCI_Right            :1; /* RIchtungsfahrspurenKI mask:0x200000 */
  uint32 ExtRoadBorderCI_Left             :1; /* RIchtungsfahrspurenKI mask:0x100000 */

  uint32 ExtCurveInnerBorder_Right        :1; /* KurveInnenrand mask: 0x80000 */
  uint32 ExtCurveInnerBorder_Left         :1; /* KurveInnenrand mask: 0x40000 */
  uint32 ExtRoadBorder_Right              :1; /* Richtungsfahrspuren mask: 0x20000 */
  uint32 ExtRoadBorder_Left               :1; /* Richtungsfahrspuren mask: 0x10000 */
  uint32 RestNeighbourhoodRelObj_Right    :1; /* UmfeldRelevantesObjekt mask: 0x8000 */
  uint32 RestNeighbourhoodRelObj_Left     :1; /* UmfeldRelevantesObjekt mask: 0x4000 */

  uint32 RestAnalogRoadBorder_Right       :1; /* AnalogerStrassenrand mask: 0x2000 */
  uint32 RestAnalogRoadBorder_Left        :1; /* AnalogerStrassenrand mask: 0x1000 */
  uint32 RestTargetOutsideBrackets_Right  :1; /* ZielAblage mask: 0x800 */
  uint32 RestTargetOutsideBrackets_Left   :1; /* ZielAblage mask: 0x400 */
#if (LA_CFG_ADD_RESTRICTION_OBJ_TRACE)
  uint32 RestObjectTrace_Left             :1;
  uint32 RestObjectTrace_Right            :1;
#endif
  uint32 AddRestCurveOuterBorder_Right    :1; /* KurveAussenrand mask: 0x200 */
  uint32 AddRestCurveOuterBorder_Left     :1; /* KurveAussenrand mask: 0x100 */

  uint32 AddExtObjApprox_Right            :1; /* Approx mask: 0x80 */
  uint32 AddExtObjApprox_Left             :1; /* Approx mask: 0x40 */
#if (LA_CFG_EXT_RELEVANT_OBJECT)
  uint32 AddExtRelevantObject_Right       :1; /* VorbeifahrtRelObjekt mask: 0x20 */
  uint32 AddExtRelevantObject_Left        :1; /* VorbeifahrtRelObjekt mask: 0x10 */
#else
  ubit32 NotUsed                          :2; /*! Default bit field entry for keeping the same mask */
#endif
  uint32 TrackWidthTrck_Right             :1; /* Fahrbahnbreite mask: 0x08 */
  uint32 TrackWidthTrck_Left              :1; /* Fahrbahnbreite mask: 0x04 */
  uint32 TrackWidthSeek_Right             :1; /* RadiusUndFahrbahnbreite mask: 0x02 */
  uint32 TrackWidthSeek_Left              :1; /* RadiusUndFahrbahnbreite mask: 0x01 */
#endif
} OUT_t_TraceBracketExtInfo;
#endif /* #if (OUT_CFG_CUSTOM_CRITERIA_MATRIX_PROCESSING) */

#if (OUT_CFG_CUSTOM_CRITERIA_MATRIX_PROCESSING)
/*! Union storing trace bracket debug information */
/* <ln_offset:+1 MISRA Rule 18.4: reviewer name: Ungvary date: 24-09-2012 reason: necessary for accessing all flags word-wise */
typedef union
{
  OUT_t_TraceBracketExtInfo TrExtInfo;
  uint32                  TrExtWord;
} OUT_t_CustObjData;
#endif  /* #if (OUT_CFG_CUSTOM_CRITERIA_MATRIX_PROCESSING) */

#if OUT_CFG_CUSTOM_XY_RELEVANCE
/*! application parameters for custom longitudinal (X) relevance */
typedef struct
{
  float32 fMin;
  float32 fMax;

  boolean bUseDist;

  float32 fDistMin;
  float32 fDistMax;
  float32 fDistStep;

#if (FCT_CFG_CAMERA_OBJECT_DETECTION)
  uint8 uCamConfRelevanceGate;  /*!< The camera/radar object matching confidence from which relevances over 0.08 are allowed @min:0 @max:99 */
#endif

} OUT_t_CustomParameterRelevanceX;

/*! application parameters for custom lateral (Y) relevance */
typedef struct
{
  float32 fMin;

  boolean bUseCutPotential;

  float32 fLaneInCut0;
  float32 fLaneInCut50;
  float32 fLaneInCut100;

  float32 fLaneOutCut0;
  float32 fLaneOutCut50;
  float32 fLaneOutCut100;

} OUT_t_CustomParameterRelevanceY;

/*! application parameters for custom relevance */
typedef struct
{
  OUT_t_CustomParameterRelevanceX CustomRelevanceX;
  OUT_t_CustomParameterRelevanceY CustomRelevanceY;

} OUT_t_CustomParameter;
#endif /*END IF (OUT_CFG_CUSTOM_XY_RELEVANCE) */ 

/*****************************************************************************
  LOCAL VARIABLES
*****************************************************************************/

#if (OUT_CFG_CUSTOM_CRITERIA_MATRIX_PROCESSING)
/*! Array storing custom processing/state information per object */
SET_MEMSEC_VAR(OUTCustObjData)
  static OUT_t_CustObjData OUTCustObjData[EM_N_OBJECTS];
#endif


#if OUT_CFG_CUSTOM_XY_RELEVANCE
/*! relevance application parameters @allow: all_cust */
SET_MEMSEC_VAR(OOIRelevanceParameter)
static OUT_t_CustomParameter OOIRelevanceParameter =
{
  /* CustomRelevanceX */
  {
    /* fMin */
    OUT_CUSTOM_REL_X_MIN,
      /* fMax */
      OUT_CUSTOM_REL_X_MAX,
      /* bUseDist */
      (boolean)OUT_CUSTOM_REL_X_DIST_USE,
      /* fDistMin */
      OUT_CUSTOM_REL_X_DIST_MIN,
      /* fDistMax */
      OUT_CUSTOM_REL_X_DIST_MAX,
      /* fDistStep */
      OUT_CUSTOM_REL_X_DIST_STEP
#if (FCT_CFG_CAMERA_OBJECT_DETECTION)
      ,
      /* .uCamConfRelevanceGate = */
      OUT_PAR_CAM_CONF_X_RELEVANCE_GATE
#endif
  },
  /* CustomRelevanceY */
  { 
    /* fMin */
    OUT_CUSTOM_REL_Y_MIN,
      /* bUseCutPotential */
      (boolean)OUT_CUSTOM_REL_Y_LANE_CUT_USE,
      /* fLaneInCut0 */
      OUT_CUSTOM_REL_Y_LANE_IN_CUT_0,
      /* fLaneInCut50 */
      OUT_CUSTOM_REL_Y_LANE_IN_CUT_50,
      /* fLaneInCut100 */
      OUT_CUSTOM_REL_Y_LANE_IN_CUT_100,
      /* fLaneOutCut0 */
      OUT_CUSTOM_REL_Y_LANE_OUT_CUT_0,
      /* fLaneOutCut50 */
      OUT_CUSTOM_REL_Y_LANE_OUT_CUT_50,
      /* fLaneOutCut100 */
      OUT_CUSTOM_REL_Y_LANE_OUT_CUT_100
    }
};
#endif /*END IF OUT_CFG_CUSTOM_XY_RELEVANCE*/

/*****************************************************************************
 STATIC-FUNCTION PROTOTYPES
*****************************************************************************/
#if OUT_CFG_CUSTOM_DRIVING_TUBE_MAPPING
static void OUT_v_CustomSetDrivingTubeMapping(void);
#endif

#if OUT_CFG_CUSTOM_MEAS_STATUS_MAPPING
/*! Translate internal object information to CAN-output*/
static void OUT_v_CustomDynamicMeasStatus (void);
/*! Translate internal object information to CAN-output*/
static eObjMeasStatus_t OUT_t_ClassifyObjectMeasStatus (ObjNumber_t iObj);
/*! ARS350 specific: Translate internal object property to CAN-output.  */
static eDynamicMeasStatus_t OUT_t_ClassifyDynamicMeasStatus(ObjNumber_t iObj);
#endif

#if (OUT_CFG_CUSTOM_OBJ_WIDTH_OUTPUT)
/*! Fill custom object width information */
static void OUT_v_CustomFillObjWidthOut(void);
#endif

#if (FCT_CFG_CUSTOM_IO_INTERFACE)
static void OUT_v_CustomControlDistanceInfo(void);
#endif /*END IF FCT_CFG_CUSTOM_IO_INTERFACE*/

#if (OUT_CFG_CUSTOM_CRITERIA_MATRIX_PROCESSING)
static boolean OUT_b_TestTraceBracketPosition(float32 fBracketPos);
static void OUT_v_StoreTraceBracketExts(void);
#endif /*END IF OUT_CFG_CUSTOM_CRITERIA_MATRIX_PROCESSING */

#if (SIT_CFG_TRAFFIC_ESTIMATION)
static void OUT_v_CustomTrafficJamProbability(void);
#endif /*END IF SIT_CFG_TRAFFIC_ESTIMATION*/

#if ((FCT_CFG_CUSTOM_IO_INTERFACE) && (OUT_CFG_CUSTOM_TO_OUTPUT))
static void OUT_v_CustomTrafficOrientation(void);
#endif  /* ((FCT_CFG_CUSTOM_IO_INTERFACE) && (OUT_CFG_CUSTOM_TO_OUTPUT)) */

#if (SIT_CFG_CUSTOM_COLECTIVE_VEL_POSTPROCESSING && SIT_CFG_TRAFFIC_ESTIMATION)
static void OUT_v_CustomCollectiveVelocityPostProcessing(void);
#endif /*END IF SIT_CFG_CUSTOM_COLECTIVE_VEL_POSTPROCESSING && SIT_CFG_TRAFFIC_ESTIMATION*/

#if OUT_CFG_CUSTOM_XY_RELEVANCE
static void OUT_v_CustomSort(const float32 Input[], ObjNumber_t SortedIndices[]);
#endif
#if OUT_CFG_CUSTOM_XY_RELEVANCE
static void OUT_v_CustomRelevanceXDist(void);
static void OUT_v_CustomRelevanceXTotal(void);
static void OUT_v_CustomRelevanceX(void);
static void OUT_v_CustomRelevanceYLane(void);
static void OUT_v_CustomRelevanceYCutInOut(void);
static void OUT_v_CustomRelevanceY(void);
#endif

#if (FCT_CFG_SEN2TJA_ACC_OOI_PORT)
static void OUT_v_CustomInitSEN2TJAOOI(void);
static void OUT_v_CustomFillSEN2TJAOOI(void);
static void OUT_v_CustomFillTJAObjectClass(ObjNumber_t t_ObjNr_OBJ_NEXT_OOI);
static void OUT_v_CustomFillTJAObjectState(ObjNumber_t t_ObjNr_OBJ_NEXT_OOI);
#endif /*END IF FCT_CFG_SEN2TJA_ACC_OOI_PORT*/

/*****************************************************************************
  NONSTATIC-FUNCTION DEFINITIONS
*****************************************************************************/
/*************************************************************************************************************************
  Functionname:    OUT_v_CustomProcess                                                                                 */ /*!

  @brief           Custom Process Output

  @description     this function generates custom process output

                    @startuml
                        Start
                            Partition OUT_v_CustomProcess {
                                -Fill custom provide port for TJA with OOI-0 data
                            }
                        End
                    @enduml

  @return          -

  @param[in]       -
  @param[out]      -

  @glob_in         -
  @glob_out        -

  @c_switch_part   OUT_CFG_CUSTOM_DRIVING_TUBE_MAPPING         : Configuration switch for activating the calculation of the driving tube mapping of an object
  @c_switch_part   OUT_CFG_CUSTOM_XY_RELEVANCE                 : Configuration switch for activating the calculation of the 
  @c_switch_part   OUT_CFG_CUSTOM_MEAS_STATUS_MAPPING          : Configuration switch for activating the calculation of the object meas status mapping of an object
  @c_switch_part   OUT_CFG_CUSTOM_OBJ_WIDTH_OUTPUT             : Internal configuration switch enabling custom object width output
  @c_switch_part   FCT_CFG_CUSTOM_IO_INTERFACE                 : FCT custom I/O interface
  @c_switch_part   OUT_CFG_CUSTOM_CRITERIA_MATRIX_PROCESSING   : Configuration switch for activating additional call to custom SICustProcessCriteriaMatrix after all other trace bracket processing took place
  @c_switch_part   SIT_CFG_TRAFFIC_ESTIMATION                  : Configuration switch to enable/disable the calculation of a traffic flow and traffic jam probability
  @c_switch_part   SIT_CFG_CUSTOM_COLECTIVE_VEL_POSTPROCESSING : Configuration switch for enabling custom output of the collective velocity
  @c_switch_full   FCT_CFG_ACC_OUTPUT                          : Configuration switch to configure OUT (Output) sub-component for FCT_ACC

  @pre             - 
  @post            No changes

  @created         05.09.2016
  @changed         06.09.2016

  @author          Amir Jabbari | amir.jabbari@continental-corporation.com | 
*************************************************************************************************************************/
void OUT_v_CustomProcess(void)
{
#if OUT_CFG_CUSTOM_DRIVING_TUBE_MAPPING
  /*! Set driving tube mapping for custom output */
  OUT_v_CustomSetDrivingTubeMapping();
#endif

#if OUT_CFG_CUSTOM_XY_RELEVANCE
  /* call longitudinal (X) relevance processing function */
  OUT_v_CustomRelevanceX();
  /* call lateral (Y) relevance processing function */
  OUT_v_CustomRelevanceY();
#endif

#if OUT_CFG_CUSTOM_MEAS_STATUS_MAPPING
  /* Calculate extern Dynamic Meas Status */
  OUT_v_CustomDynamicMeasStatus();
#endif

#if (OUT_CFG_CUSTOM_OBJ_WIDTH_OUTPUT)
  /* Fill custom object width output */
  OUT_v_CustomFillObjWidthOut();
#endif

#if (FCT_CFG_CUSTOM_IO_INTERFACE)
  /*Calculate Control and Visibility Distance*/
  OUT_v_CustomControlDistanceInfo();
#endif

#if (OUT_CFG_CUSTOM_CRITERIA_MATRIX_PROCESSING)
  /* Store trace bracket extensions per object */
  OUT_v_StoreTraceBracketExts();
#endif

#if (SIT_CFG_TRAFFIC_ESTIMATION && FCT_CFG_CUSTOM_IO_INTERFACE)
  /* Set traffic jam probability for custom output */
  OUT_v_CustomTrafficJamProbability();

#if (SIT_CFG_CUSTOM_COLECTIVE_VEL_POSTPROCESSING)
  /* Custom post-processing of collective velocity */
  OUT_v_CustomCollectiveVelocityPostProcessing();
#endif  /* (SIT_CFG_CUSTOM_COLECTIVE_VEL_POSTPROCESSING) */
#endif  /* (SIT_CFG_TRAFFIC_ESTIMATION && FCT_CFG_CUSTOM_IO_INTERFACE) */

#if ((FCT_CFG_CUSTOM_IO_INTERFACE) && (OUT_CFG_CUSTOM_TO_OUTPUT))
  /* Set traffic orientation */
  OUT_v_CustomTrafficOrientation();
#endif  /* ((FCT_CFG_CUSTOM_IO_INTERFACE) && (OUT_CFG_CUSTOM_TO_OUTPUT)) */

#if (FCT_CFG_SEN2TJA_ACC_OOI_PORT)
  /* Fill custom provide port for TJA with OOI-0 data */
  OUT_v_CustomFillSEN2TJAOOI();
#endif  /* END IF (FCT_CFG_SEN2TJA_ACC_OOI_PORT) */
}

#if (OUT_CFG_CUSTOM_CRITERIA_MATRIX_PROCESSING)
/*************************************************************************************************************************
  Functionname:    OUT_v_CustStoreBracketExtensions                                                                     */ /*!

  @brief           Store trace bracket extension information

  @description     Store trace bracket debug information based on passed criteria matrix for the given object

  @return          -

  @param[in]       iObj - Object ID [0u ... EM_N_OBJECTS-1] 
  @param[in]       pCriteriaMatrix : Criteria matrix for a given object containing the trace bracket information
                      AddExtensionRelevantObject.BracketPositionLeft        [-PI/2*RW_FCT_MAX ... PI/2*RW_FCT_MAX] m 
                      AddExtensionRelevantObject.BracketPositionRight       [-PI/2*RW_FCT_MAX ... PI/2*RW_FCT_MAX] m 
                      AddExtensionObjectApproximation.BracketPositionLeft   [-PI/2*RW_FCT_MAX ... PI/2*RW_FCT_MAX] m 
                      AddExtensionObjectApproximation.BracketPositionRight  [-PI/2*RW_FCT_MAX ... PI/2*RW_FCT_MAX] m 
                      AddRestrictionCurveOuterBorder.BracketPositionLeft    [-PI/2*RW_FCT_MAX ... PI/2*RW_FCT_MAX] m 
                      AddRestrictionCurveOuterBorder.BracketPositionRight   [-PI/2*RW_FCT_MAX ... PI/2*RW_FCT_MAX] m 
                      RestrictionTargetOutsideBrackets.BracketPositionLeft  [-PI/2*RW_FCT_MAX ... PI/2*RW_FCT_MAX] m 
                      RestrictionTargetOutsideBrackets.BracketPositionRight [-PI/2*RW_FCT_MAX ... PI/2*RW_FCT_MAX] m 
                      RestrictionAnalogRoadBorder.BracketPositionLeft       [-PI/2*RW_FCT_MAX ... PI/2*RW_FCT_MAX] m 
                      RestrictionAnalogRoadBorder.BracketPositionRight      [-PI/2*RW_FCT_MAX ... PI/2*RW_FCT_MAX] m 
                      RestrictionNeighbourhoodRelObj.BracketPositionLeft    [-PI/2*RW_FCT_MAX ... PI/2*RW_FCT_MAX] m 
                      RestrictionNeighbourhoodRelObj.BracketPositionRight   [-PI/2*RW_FCT_MAX ... PI/2*RW_FCT_MAX] m 
                      RestrictionObjectTrace.BracketPositionLeft            [-PI/2*RW_FCT_MAX ... PI/2*RW_FCT_MAX] m 
                      RestrictionObjectTrace.BracketPositionRight           [-PI/2*RW_FCT_MAX ... PI/2*RW_FCT_MAX] m 
                      ExtensionRoadBorder.BracketPositionLeft               [-PI/2*RW_FCT_MAX ... PI/2*RW_FCT_MAX] m 
                      ExtensionRoadBorder.BracketPositionRight              [-PI/2*RW_FCT_MAX ... PI/2*RW_FCT_MAX] m 
                      ExtensionCurveInnerBorder.BracketPositionLeft         [-PI/2*RW_FCT_MAX ... PI/2*RW_FCT_MAX] m 
                      ExtensionCurveInnerBorder.BracketPositionRight        [-PI/2*RW_FCT_MAX ... PI/2*RW_FCT_MAX] m 
                      ExtensionRoadBorderCI.BracketPositionLeft             [-PI/2*RW_FCT_MAX ... PI/2*RW_FCT_MAX] m 
                      ExtensionRoadBorderCI.BracketPositionRight            [-PI/2*RW_FCT_MAX ... PI/2*RW_FCT_MAX] m 
                      ExtensionFollowObjectIntoCurve.BracketPositionLeft    [-PI/2*RW_FCT_MAX ... PI/2*RW_FCT_MAX] m 
                      ExtensionFollowObjectIntoCurve.BracketPositionRight   [-PI/2*RW_FCT_MAX ... PI/2*RW_FCT_MAX] m 
                      ExtensionGuardRailRoadBorder.BracketPositionLeft      [-PI/2*RW_FCT_MAX ... PI/2*RW_FCT_MAX] m 
                      ExtensionGuardRailRoadBorder.BracketPositionRight     [-PI/2*RW_FCT_MAX ... PI/2*RW_FCT_MAX] m 
  @param[out]      -

  @glob_in         - 
  @glob_out        OUTCustObjData[i].TrExtInfo : Trace bracket extensions debugging information with i in [0u ... EM_N_OBJECTS-1]
                      AddExtRelevantObject_Left       [-PI/2*RW_FCT_MAX ... PI/2*RW_FCT_MAX] m 
                      AddExtRelevantObject_Right      [-PI/2*RW_FCT_MAX ... PI/2*RW_FCT_MAX] m 
                      AddExtObjApprox_Left            [-PI/2*RW_FCT_MAX ... PI/2*RW_FCT_MAX] m 
                      AddExtObjApprox_Right           [-PI/2*RW_FCT_MAX ... PI/2*RW_FCT_MAX] m 
                      AddRestCurveOuterBorder_Left    [-PI/2*RW_FCT_MAX ... PI/2*RW_FCT_MAX] m 
                      AddRestCurveOuterBorder_Right   [-PI/2*RW_FCT_MAX ... PI/2*RW_FCT_MAX] m 
                      RestTargetOutsideBrackets_Left  [-PI/2*RW_FCT_MAX ... PI/2*RW_FCT_MAX] m 
                      RestTargetOutsideBrackets_Right [-PI/2*RW_FCT_MAX ... PI/2*RW_FCT_MAX] m 
                      RestAnalogRoadBorder_Left       [-PI/2*RW_FCT_MAX ... PI/2*RW_FCT_MAX] m 
                      RestAnalogRoadBorder_Right      [-PI/2*RW_FCT_MAX ... PI/2*RW_FCT_MAX] m 
                      RestNeighbourhoodRelObj_Left    [-PI/2*RW_FCT_MAX ... PI/2*RW_FCT_MAX] m 
                      RestNeighbourhoodRelObj_Right   [-PI/2*RW_FCT_MAX ... PI/2*RW_FCT_MAX] m 
                      RestObjectTrace_Left            [-PI/2*RW_FCT_MAX ... PI/2*RW_FCT_MAX] m 
                      RestObjectTrace_Right           [-PI/2*RW_FCT_MAX ... PI/2*RW_FCT_MAX] m 
                      ExtRoadBorder_Left              [-PI/2*RW_FCT_MAX ... PI/2*RW_FCT_MAX] m 
                      ExtRoadBorder_Right             [-PI/2*RW_FCT_MAX ... PI/2*RW_FCT_MAX] m 
                      ExtCurveInnerBorder_Left        [-PI/2*RW_FCT_MAX ... PI/2*RW_FCT_MAX] m 
                      ExtCurveInnerBorder_Right       [-PI/2*RW_FCT_MAX ... PI/2*RW_FCT_MAX] m 
                      ExtRoadBorderCI_Left            [-PI/2*RW_FCT_MAX ... PI/2*RW_FCT_MAX] m 
                      ExtRoadBorderCI_Right           [-PI/2*RW_FCT_MAX ... PI/2*RW_FCT_MAX] m 
                      ExtFollowObjectIntoCurve_Left   [-PI/2*RW_FCT_MAX ... PI/2*RW_FCT_MAX] m 
                      ExtFollowObjectIntoCurve_Right  [-PI/2*RW_FCT_MAX ... PI/2*RW_FCT_MAX] m 
                      ExtRoadWorksRoadBorder_Left     [-PI/2*RW_FCT_MAX ... PI/2*RW_FCT_MAX] m 
                      ExtRoadWorksRoadBorder_Right    [-PI/2*RW_FCT_MAX ... PI/2*RW_FCT_MAX] m 

  @c_switch_part   LA_CFG_EXT_RELEVANT_OBJECT : Configuration switch to enable/disable relevant object extension as defined in out_cfg.h
  @c_switch_part   LA_CFG_ADD_RESTRICTION_OBJ_TRACE : Configuration switch to enable restriction based on relevant object trace
  @c_switch_part   FCT_CFG_ROAD_INPUT : Road estimation input to FCT
  @c_switch_full   FCT_CFG_ACC_OUTPUT : Configuration switch to configure OUT (Output) sub-component for FCT_ACC
  @c_switch_full   OUT_CFG_CUSTOM_CRITERIA_MATRIX_PROCESSING : Configuration switch for activating additional call to custom SICustProcessCriteriaMatrix after all other trace bracket processing took place

  @pre             -
  @post            -

  @created         -
  @changed         20.04.2016

  @author          Thomas Kleintje/Gergely Ungvary
*************************************************************************************************************************/
void OUT_v_CustStoreBracketExtensions(ObjNumber_t iObj, const LA_t_CriteriaMatrix * pCriteriaMatrix)
{

  /*Set Bracket Status*/
#if (LA_CFG_EXT_RELEVANT_OBJECT)
  OUTCustObjData[iObj].TrExtInfo.AddExtRelevantObject_Left         = OUT_b_TestTraceBracketPosition(pCriteriaMatrix->AddExtensionRelevantObject.BracketPositionLeft);
  OUTCustObjData[iObj].TrExtInfo.AddExtRelevantObject_Right        = OUT_b_TestTraceBracketPosition(pCriteriaMatrix->AddExtensionRelevantObject.BracketPositionRight);
#endif
  OUTCustObjData[iObj].TrExtInfo.AddExtObjApprox_Left    = OUT_b_TestTraceBracketPosition(pCriteriaMatrix->AddExtensionObjectApproximation.BracketPositionLeft); 
  OUTCustObjData[iObj].TrExtInfo.AddExtObjApprox_Right   = OUT_b_TestTraceBracketPosition(pCriteriaMatrix->AddExtensionObjectApproximation.BracketPositionRight);

  OUTCustObjData[iObj].TrExtInfo.AddRestCurveOuterBorder_Left     = OUT_b_TestTraceBracketPosition(pCriteriaMatrix->AddRestrictionCurveOuterBorder.BracketPositionLeft);
  OUTCustObjData[iObj].TrExtInfo.AddRestCurveOuterBorder_Right    = OUT_b_TestTraceBracketPosition(pCriteriaMatrix->AddRestrictionCurveOuterBorder.BracketPositionRight);
  OUTCustObjData[iObj].TrExtInfo.RestTargetOutsideBrackets_Left   = OUT_b_TestTraceBracketPosition(pCriteriaMatrix->RestrictionTargetOutsideBrackets.BracketPositionLeft);
  OUTCustObjData[iObj].TrExtInfo.RestTargetOutsideBrackets_Right  = OUT_b_TestTraceBracketPosition(pCriteriaMatrix->RestrictionTargetOutsideBrackets.BracketPositionRight);

  OUTCustObjData[iObj].TrExtInfo.RestAnalogRoadBorder_Left        = OUT_b_TestTraceBracketPosition(pCriteriaMatrix->RestrictionAnalogRoadBorder.BracketPositionLeft);
  OUTCustObjData[iObj].TrExtInfo.RestAnalogRoadBorder_Right       = OUT_b_TestTraceBracketPosition(pCriteriaMatrix->RestrictionAnalogRoadBorder.BracketPositionRight);

  OUTCustObjData[iObj].TrExtInfo.RestNeighbourhoodRelObj_Left     = OUT_b_TestTraceBracketPosition(pCriteriaMatrix->RestrictionNeighbourhoodRelObj.BracketPositionLeft);
  OUTCustObjData[iObj].TrExtInfo.RestNeighbourhoodRelObj_Right    = OUT_b_TestTraceBracketPosition(pCriteriaMatrix->RestrictionNeighbourhoodRelObj.BracketPositionRight);
#if (LA_CFG_ADD_RESTRICTION_OBJ_TRACE)
  OUTCustObjData[iObj].TrExtInfo.RestObjectTrace_Left             = OUT_b_TestTraceBracketPosition(pCriteriaMatrix->RestrictionObjectTrace.BracketPositionLeft);
  OUTCustObjData[iObj].TrExtInfo.RestObjectTrace_Right            = OUT_b_TestTraceBracketPosition(pCriteriaMatrix->RestrictionObjectTrace.BracketPositionRight);
#endif
  OUTCustObjData[iObj].TrExtInfo.ExtRoadBorder_Left                = OUT_b_TestTraceBracketPosition(pCriteriaMatrix->ExtensionRoadBorder.BracketPositionLeft);
  OUTCustObjData[iObj].TrExtInfo.ExtRoadBorder_Right               = OUT_b_TestTraceBracketPosition(pCriteriaMatrix->ExtensionRoadBorder.BracketPositionRight);
  OUTCustObjData[iObj].TrExtInfo.ExtCurveInnerBorder_Left          = OUT_b_TestTraceBracketPosition(pCriteriaMatrix->ExtensionCurveInnerBorder.BracketPositionLeft);
  OUTCustObjData[iObj].TrExtInfo.ExtCurveInnerBorder_Right         = OUT_b_TestTraceBracketPosition(pCriteriaMatrix->ExtensionCurveInnerBorder.BracketPositionRight);

  OUTCustObjData[iObj].TrExtInfo.ExtRoadBorderCI_Left              = OUT_b_TestTraceBracketPosition(pCriteriaMatrix->ExtensionRoadBorderCI.BracketPositionLeft);
  OUTCustObjData[iObj].TrExtInfo.ExtRoadBorderCI_Right             = OUT_b_TestTraceBracketPosition(pCriteriaMatrix->ExtensionRoadBorderCI.BracketPositionRight);
  OUTCustObjData[iObj].TrExtInfo.ExtFollowObjectIntoCurve_Left     = OUT_b_TestTraceBracketPosition(pCriteriaMatrix->ExtensionFollowObjectIntoCurve.BracketPositionLeft);
  OUTCustObjData[iObj].TrExtInfo.ExtFollowObjectIntoCurve_Right    = OUT_b_TestTraceBracketPosition(pCriteriaMatrix->ExtensionFollowObjectIntoCurve.BracketPositionRight);

#if (FCT_CFG_ROAD_INPUT)
  OUTCustObjData[iObj].TrExtInfo.ExtRoadWorksRoadBorder_Left       = OUT_b_TestTraceBracketPosition(pCriteriaMatrix->ExtensionGuardRailRoadBorder.BracketPositionLeft);
  OUTCustObjData[iObj].TrExtInfo.ExtRoadWorksRoadBorder_Right      = OUT_b_TestTraceBracketPosition(pCriteriaMatrix->ExtensionGuardRailRoadBorder.BracketPositionRight);
#endif
}
#endif /* #if OUT_CFG_CUSTOM_CRITERIA_MATRIX_PROCESSING */

#if (OUT_CFG_CUSTOM_OOI_MEAS_DATA)
/*************************************************************************************************************************
  Functionname:    OUT_v_CustFillMeasOOI                                                                                */ /*!

  @brief           Fill custom measurement data on OOI list

  @description     Fills custom measurement data attached to SI OOI list for visualization and debugging

  @return          -

  @param[in]       ObjId : the object ID correctly being filled (note: may be OBJ_INDEX_NO_OBJECT if no object selected)
                                  [OBJ_INDEX_NO_OBJECT ... EM_N_OBJECTS-1]
  @param[out]      pDestMeasData : pointer to the buffer to fill
                        fAbsSpeedX : absolute velocity                          [-330.f ... +330.f] m/s
                        fAbsAccelX : absolute acceleration                      [-100.f ... +100.f] m/s2
                        DrivingTubeMapping : Driving tube mapping of the object [t_DrivingTubeMapping as defined in Rte]
                        RelevanceX : X relevance of the object                  [0u...100u]
                        RelevanceY : Y relevance of the object                  [0u...100u]
                        fTTC : TTC (time to collision)                          [Full range of datatype float32 with >= 0.f]
                        fTimeGap : Time gap                                     [Full range of datatype float32 with >= 0.f]

  @glob_in         pt_OUTInput : Reference to OUT input data structure                                        
                      t_FIPInput.pf_ObjAbsVelX(i) : absolute velocity from FCTCustomOutput for object i       [-330.f ... +330.f] m/s
                                                    with i in [0u ... EM_N_OBJECTS-1]
                      t_FIPInput.pf_ObjAbsAccelX(i) : absolute acceleration from FCTCustomOutput for object i [-100.f ... +100.f] m/s2
                                                      with i in [0u ... EM_N_OBJECTS-1]
                      t_RTE.pf_ObjVrelX(i) : Relative velocity of object i                                    [-330.f ... 330.f] m/s
                                             with i in [0u ... EM_N_OBJECTS-1]
                      t_RTE.pf_ObjLongDisp(i) : Longitudinal displacement of an object i                      [-5*RW_FCT_MAX ... 5*RW_FCT_MAX] m                 
                                                with i in [0u ... EM_N_OBJECTS-1]
  @glob_in         OUT_DRIVING_TUBE_MAPPING(i) : DrivingTubeMapping from pSLATE_CustomOutput for object i    [Full range of datatype t_DrivingTubeMapping as defined in Rte_Type.h]
                                                 with i in [0u ... EM_N_OBJECTS-1]
  @glob_in         OUT_OBJ_RELEVANCE_X(i) : X relevance of the object i                                       [0u...100u]
                                            with i in [0u ... EM_N_OBJECTS-1]
  @glob_in         OUT_OBJ_RELEVANCE_Y(i) : Y relevance of the object i                                       [0u...100u]
                                            with i in [0u ... EM_N_OBJECTS-1]
  @glob_in         EGO_SPEED_X_OBJ_SYNC : Ego vehicle speed         [-330.f ... 330.f] m/s
  @glob_out        -

  @c_switch_part   OUT_CFG_CUSTOM_DRIVING_TUBE_MAPPING : Configuration switch for activating the calculation of the driving tube mapping of an object
  @c_switch_part   OUT_CFG_CUSTOM_XY_RELEVANCE : Configuration switch for activating the calculation of the x-relevance and y-relevance of an object
  @c_switch_part   OUT_CFG_OOI_TTC_TG_DEBUG_CRITERIA : SI OOI with debug TTC/TG information in meas-freeze (simplifies quick performance evaluation)
  @c_switch_full   OUT_CFG_CUSTOM_OOI_MEAS_DATA : Configuration switch for enabling custom output type (OUT_t_CustMeasOOI) output over measurement interface for each OOI object. 
                   This allows application-project specific data to be attached to the OOI measurement objects for validation or visualization.
  @c_switch_full   FCT_CFG_ACC_OUTPUT : Configuration switch to configure OUT (Output) sub-component for FCT_ACC

  @pre             -
  @post            -

  @created         -
  @changed         22.03.2016

  @author          Gergely Ungvary | Gergely.Ungvary@continental-corporation.com | +36 88548-671
*************************************************************************************************************************/
void OUT_v_CustFillMeasOOI(ObjNumber_t ObjId, OUT_t_CustMeasOOI * pDestMeasData)
{
  if (ObjId > OBJ_INDEX_NO_OBJECT)
  {
    pDestMeasData->fAbsSpeedX = pt_OUTInput->pt_FIPOA->t_ObjList[ObjId].fAbsVelocity;
    pDestMeasData->fAbsAccelX = pt_OUTInput->pt_FIPOA->t_ObjList[ObjId].fAbsAcceleration;
#if OUT_CFG_CUSTOM_DRIVING_TUBE_MAPPING
    pDestMeasData->DrivingTubeMapping = OUT_DRIVING_TUBE_MAPPING(ObjId);
#endif
#if OUT_CFG_CUSTOM_XY_RELEVANCE
    pDestMeasData->RelevanceX = OUT_OBJ_RELEVANCE_X(ObjId);
    pDestMeasData->RelevanceY = OUT_OBJ_RELEVANCE_Y(ObjId);
#endif
#if (OUT_CFG_OOI_TTC_TG_DEBUG_CRITERIA)
    /* Calculate simple TTC (without relative acceleration) for given object when possible */
    if (*pt_OUTInput->t_RTE.pf_ObjVrelX(ObjId) < -C_F32_DELTA)
    {
      pDestMeasData->fTTC = (*(pt_OUTInput->t_RTE.pf_ObjLongDisp(ObjId)) / -(*pt_OUTInput->t_RTE.pf_ObjVrelX(ObjId)));
    }
    else
    {
      pDestMeasData->fTTC = 0.f;
    }
    /* Calculate ego-speed based time-gap time in seconds for given object when possible */
    if (SLATE_f_GetEgoVelObjSync() > C_F32_DELTA)
    {
      pDestMeasData->fTimeGap = (*(pt_OUTInput->t_RTE.pf_ObjLongDisp(ObjId)) / SLATE_f_GetEgoVelObjSync());
    }
    else
    {
      pDestMeasData->fTimeGap = 0.f;
    }
#endif
  }
  else
  {
    pDestMeasData->fAbsSpeedX = 0.f;
    pDestMeasData->fAbsAccelX = 0.f;
#if OUT_CFG_CUSTOM_DRIVING_TUBE_MAPPING
    pDestMeasData->DrivingTubeMapping = FCT_DTM_UNKNOWN_LANE;
#endif
#if OUT_CFG_CUSTOM_XY_RELEVANCE
    pDestMeasData->RelevanceX = 0u;
    pDestMeasData->RelevanceY = 0u;
#endif
#if (OUT_CFG_OOI_TTC_TG_DEBUG_CRITERIA)
    pDestMeasData->fTTC       = 0.f;
    pDestMeasData->fTimeGap   = 0.f;
#endif
  }
}
#endif  /* (OUT_CFG_CUSTOM_OOI_MEAS_DATA) */

/*************************************************************************************************************************
  Functionname:    OUT_v_MergeCustomObjects                                                                                 */ /*!

  @brief           merge custom output

  @description     It generates the output of merged custom objects

                    @startuml
                        Start
                            Partition OUT_v_MergeCustomObjects {
                                - merge customer specific object data when it is available
                            }
                        End
                    @enduml

  @return          -

  @param[in]       ObjNumber : Object ID [0u ... EM_N_OBJECTS-1]
  @param[in]       uiObjectToKeep : Information describing the object to keep     [ 0u ... EM_N_OBJECTS-1]
  @param[in]       uiObjectToDelete : Information describing the object to delete [ 0u ... EM_N_OBJECTS-1]

  @glob_in         -
  @glob_out        -

  @c_switch_part   -
  @c_switch_full   FCT_CFG_ACC_OUTPUT : Configuration switch to configure OUT (Output) sub-component for FCT_ACC
  @pre             - 
  @post            No changes

  @created         05.09.2016
  @changed         06.09.2016

  @author          Amir Jabbari | amir.jabbari@continental-corporation.com | 
*************************************************************************************************************************/
void OUT_v_MergeCustomObjects( ObjNumber_t uiObjectToKeep,ObjNumber_t uiObjectToDelete )
{
  /* merge customer specific object data */
  uiObjectToKeep = uiObjectToKeep; // PRQA S 3199
  /* date: 2015-06-15, reviewer: Lonard jaison Manohar, reason: Redundant.But may be kept for future use */
  uiObjectToDelete = uiObjectToDelete;// PRQA S 3199
  /* date: 2015-06-15, reviewer: Lonard jaison Manohar, reason: Redundant.But may be kept for future use */
#if (OUT_CFG_FUNC_LANEASSOC_LA)
  pt_OUTOutput->t_FuncLA_LC[uiObjectToKeep] = pt_OUTOutput->t_FuncLA_LC[uiObjectToDelete];
#endif /* OUT_CFG_FUNC_LANEASSOC_LA */
}

/*************************************************************************************************************************
  Functionname:    OUT_v_InitCustom                                                                                 */ /*!

  @brief           Output custom initialization

  @description     It initializes the custom output

                    @startuml
                        Start
                            Partition OUT_v_InitCustom {
                                -Initializes the custom output 
                            }
                        End
                    @enduml

  @return          -

  @param[in]       -
  @param[out]      -

  @glob_in         -
  @glob_out        pSLATE_CustomOutput : Custom Outputs for FCT component
                      AccSelectionInfo.fLongControlDistance : 40+2.2*vego as required pick-up range                     [-5*RW_FCT_MAX ... 5*RW_FCT_MAX] m
                      AccSelectionInfo.fRangeFactor : Range factor to reduce required pick-up range in curvy situations [0.f ... 1.f]        
                      AccSelectionInfo.fVisibilityRestriction : Custom max pickup distance including curve reduction    [-5*RW_FCT_MAX ... 5*RW_FCT_MAX] m  
                      PredictedTrajectory.fCurveC0 : Curvature of ACC-trajectory                                        [-1.f ... +1.f] m^(-1)
                      PredictedTrajectory.fCurveC1 : Curvature change of ACC-trajectory                                 [-1.f ... +1.f] m^(-1)
                      PredictedTrajectory.fAngle : Side slip angle                                                      [-PI   +PI] rad
                      PredictedTrajectory.ucPredictState : Prediction state based on input for ACC trajectory           [Full range of datatype ucPredictState_t as defined in Rte_Type.h]
                      TrafficDensityData.TrafficJamProbability : probability, that ego vehicle is in a traffic jam based on observation of surrounding vehicles [0.f ... 1.f] 
  @glob_out        OUTCustObjData[i].TrExtWord : Bits indicating active trace bracket information                       [Full range of datatype TrExtWord (uint32) as defined in out_customfunctions.h]
                                               with i in [0 ... EM_N_OBJECTS-1]

  @c_switch_part   OUT_CFG_CUSTOM_CRITERIA_MATRIX_PROCESSING : activating additional call to custom LA_b_CustProcessCriteriaMatrix
  @c_switch_part   SIT_CFG_TRAFFIC_ESTIMATION : Configuration switch to enable/disable the calculation of a traffic flow and traffic jam probability
  @c_switch_full   FCT_CFG_ACC_OUTPUT : Configuration switch to configure OUT (Output) sub-component for FCT_ACC

  @pre             - 
  @post            No changes

  @created         05.09.2016
  @changed         06.09.2016

  @author          Amir Jabbari | amir.jabbari@continental-corporation.com | 
*************************************************************************************************************************/
void OUT_v_InitCustom(void)
{
#if (OUT_CFG_CUSTOM_CRITERIA_MATRIX_PROCESSING)
  ObjNumber_t iObj;
#endif /* (OUT_CFG_CUSTOM_CRITERIA_MATRIX_PROCESSING) */

#if (FCT_CFG_CUSTOM_IO_INTERFACE)
  pSLATE_CustomOutput->AccSelectionInfo.fLongControlDistance = 0.f;
  pSLATE_CustomOutput->AccSelectionInfo.fRangeFactor = 0.f;
  pSLATE_CustomOutput->AccSelectionInfo.fVisibilityRestriction = 0.f;

  pSLATE_CustomOutput->PredictedTrajectory.fCurveC0   = 0.f;
  pSLATE_CustomOutput->PredictedTrajectory.fCurveC1   = 0.f;
  pSLATE_CustomOutput->PredictedTrajectory.fAngle     = 0.f;
  pSLATE_CustomOutput->PredictedTrajectory.ucPredictState = PRED_ACC_TRAJ_EGO_ONLY;

#if (SIT_CFG_TRAFFIC_ESTIMATION)
  pSLATE_CustomOutput->TrafficDensityData.TrafficJamProbability = 0.f;
#endif /* (SIT_CFG_TRAFFIC_ESTIMATION) */
#endif /* (FCT_CFG_CUSTOM_IO_INTERFACE) */

#if (OUT_CFG_CUSTOM_CRITERIA_MATRIX_PROCESSING)
  for (iObj=0; iObj<EM_N_OBJECTS; iObj++)
  {
    OUTCustObjData[iObj].TrExtWord = 0u;
  }
#endif /* (OUT_CFG_CUSTOM_CRITERIA_MATRIX_PROCESSING) */

  /* TODO Move this to custom init for provide ports when such a function is available */
#if (FCT_CFG_SEN2TJA_ACC_OOI_PORT)
  OUT_v_CustomInitSEN2TJAOOI();
#endif /* (FCT_CFG_SEN2TJA_ACC_OOI_PORT) */
}

#if (FCT_CFG_SEN2VEH_ACC_OOI_PORT)
/*************************************************************************************************************************
  Functionname:    OUT_v_CustomInitSEN2VEHOOI                                                                     */ /*!

  @brief           Initialize provide port ACC six object list to FCT_VEH when the operation mode is INIT

  @description     Initialize provide port ACC six object list to FCT_VEH when the operation mode is INIT

                    @startuml
                        Start
                            Partition OUT_v_CustomInitSEN2VEHOOI {
                                -Initialize provide port ACC six object list to FCT_VEH when the operation mode is INIT
                            }
                        End
                    @enduml

  @return          -

  @param[in]       -

  @glob_in         -
  @glob_out        -

  @c_switch_part   -
  @c_switch_full   FCT_CFG_SEN2VEH_ACC_OOI_PORT : Provide port from SEN to VEH

  @pre             -
  @post            -

  @created         26.06.2017
  @changed         26.06.2017

  @author          Bharadwaj Gobichettipalayam Sankar| bharadwaj.gobichettipalayam.sankar@continental-corporation.com | +49 (8382) 9699-4977
*************************************************************************************************************************/
void OUT_v_CustomInitSEN2VEHOOI(void)
{
  /* Initialize SEN2VEH OOI provide ports */
  pSLATE_AccOOIData->sSigHeader.uiTimeStamp          = GET_EM_PUB_OBJ_DATA_PTR->sSigHeader.uiTimeStamp;
  pSLATE_AccOOIData->sSigHeader.uiMeasurementCounter = GET_EM_PUB_OBJ_DATA_PTR->sSigHeader.uiMeasurementCounter;
  pSLATE_AccOOIData->sSigHeader.uiCycleCounter       = FCTSenFrame.uiCycleCounter;
  pSLATE_AccOOIData->sSigHeader.eSigStatus           = ((OUT_t_State == COMP_STATE_NOT_INITIALIZED)?AL_SIG_STATE_INIT:AL_SIG_STATE_INVALID);
  pSLATE_AccOOIData->uiVersionNumber = 0u;

  /* Initialize OOI attributes*/
  OUT_v_CustomInitOOIAttributes(&pSLATE_AccOOIData->AccOOIHiddenNextLeft.Attributes);
  OUT_v_CustomInitOOIAttributes(&pSLATE_AccOOIData->AccOOIHiddenNextLong.Attributes);
  OUT_v_CustomInitOOIAttributes(&pSLATE_AccOOIData->AccOOINextLeft.Attributes);
  OUT_v_CustomInitOOIAttributes(&pSLATE_AccOOIData->AccOOINextRight.Attributes);
  OUT_v_CustomInitOOIAttributes(&pSLATE_AccOOIData->AccOOIHiddenNextRight.Attributes);
  OUT_v_CustomInitOOIAttributes(&pSLATE_AccOOIData->AccOOINextLong.Attributes);

  /* Initialize kinematic attributes */
  OUT_v_CustomInitOOIKinematic(&pSLATE_AccOOIData->AccOOIHiddenNextLeft.Kinematic);
  OUT_v_CustomInitOOIKinematic(&pSLATE_AccOOIData->AccOOIHiddenNextLong.Kinematic);
  OUT_v_CustomInitOOIKinematic(&pSLATE_AccOOIData->AccOOINextLeft.Kinematic);
  OUT_v_CustomInitOOIKinematic(&pSLATE_AccOOIData->AccOOINextRight.Kinematic);
  OUT_v_CustomInitOOIKinematic(&pSLATE_AccOOIData->AccOOIHiddenNextRight.Kinematic);
  OUT_v_CustomInitOOIKinematic(&pSLATE_AccOOIData->AccOOINextLong.Kinematic);
  pSLATE_AccOOIData->AccOOINextLong.eRelObjLossReason = OBJ_LOSS_NO_INFO;
#if (OBJLOSS_NUMBER_OF_OOI > 1)
  pSLATE_AccOOIData->AccOOIHiddenNextLong.Attributes.eLostReason = OBJ_LOSS_NO_INFO;
#endif /* (OBJLOSS_NUMBER_OF_OOI > 1) */
}
#endif  /* (FCT_CFG_SEN2VEH_ACC_OOI_PORT) */

#if (FCT_CFG_SEN2VEH_ACC_OOI_PORT)
/*************************************************************************************************************************
  Functionname:    OUT_v_CustomInitOOIAttributes                                                                     */ /*!

  @brief           Initialize provide port ACC six object list attributes when the operation mode is INIT

  @description     Initialize provide port ACC six object list attributes when the operation mode is INIT

                    @startuml
                        Start
                            Partition OUT_v_CustomInitOOIAttributes {
                                -Initialize ACC six object list attributes when operation mode is INIT
                            }
                        End
                    @enduml

  @return          -

  @param[in]       -

  @glob_in         -
  @glob_out        -

  @c_switch_part   -
  @c_switch_full   FCT_CFG_SEN2VEH_ACC_OOI_PORT : Provide port from SEN to VEH

  @pre             -
  @post            -

  @created         26.06.2017
  @changed         26.06.2017

  @author          Bharadwaj Gobichettipalayam Sankar| bharadwaj.gobichettipalayam.sankar@continental-corporation.com | +49 (8382) 9699-4977
*************************************************************************************************************************/
void OUT_v_CustomInitOOIAttributes(AccOOIGenAttributes_t * pt_AccOOIAttributes)
{
  pt_AccOOIAttributes->uiCutInOutProbability = 0u;
  pt_AccOOIAttributes->eDynamicProperty = EM_GEN_OBJECT_DYN_PROPERTY_UNKNOWN;
  pt_AccOOIAttributes->fLifeTime = 0.f;
  pt_AccOOIAttributes->eMaintenanceState = EM_GEN_OBJECT_MT_STATE_INACTIVE;
  pt_AccOOIAttributes->uiObjectID = OBJ_INDEX_NO_OBJECT;
  pt_AccOOIAttributes->uiLifeCycles = 0u;
#if (OUT_CFG_CUSTOM_OBSTACLE_PROBABILITY)
  pt_AccOOIAttributes->uObstacleProbability = 0u;
#endif /* (OUT_CFG_CUSTOM_OBSTACLE_PROBABILITY) */
#if (OUT_CFG_OVERTAKE_PREVENTION_FEATURE)
  pt_AccOOIAttributes->b_PreventOvertake = FALSE;
#endif /* END IF OUT_CFG_OVERTAKE_PREVENTION_FEATURE */
}
#endif  /* (FCT_CFG_SEN2VEH_ACC_OOI_PORT) */

#if (FCT_CFG_SEN2VEH_ACC_OOI_PORT)
/*************************************************************************************************************************
  Functionname:    OUT_v_CustomInitOOIKinematic                                                                     */ /*!

  @brief           Initialize provide port ACC six object list kinematic attributes when the operation mode is INIT

  @description     Initialize provide port ACC six object list kinematic attributes when the operation mode is INIT

                    @startuml
                        Start
                            Partition OUT_v_CustomInitOOIKinematic {
                                -Initialize ACC object list Kinematic attributes when operationmode is INIT
                            }
                        End
                    @enduml

  @return          -

  @param[in]       -

  @glob_in         -
  @glob_out        -

  @c_switch_part   -
  @c_switch_full   FCT_CFG_SEN2VEH_ACC_OOI_PORT : Provide port from SEN to VEH

  @pre             -
  @post            -

  @created         26.06.2017
  @changed         26.06.2017

  @author          Bharadwaj Gobichettipalayam Sankar| bharadwaj.gobichettipalayam.sankar@continental-corporation.com | +49 (8382) 9699-4977
*************************************************************************************************************************/
void OUT_v_CustomInitOOIKinematic(AccOOIGenKinematics_t * pt_AccOOIKinematic)
{
  pt_AccOOIKinematic->fAabsX = 0.f;
  pt_AccOOIKinematic->fAabsY = 0.f;
  pt_AccOOIKinematic->fArelX = 0.f;
  pt_AccOOIKinematic->fArelY = 0.f;
  pt_AccOOIKinematic->fDistX = 0.f;
  pt_AccOOIKinematic->fDistY = 0.f;
  pt_AccOOIKinematic->fVabsX = 0.f;
  pt_AccOOIKinematic->fVabsY = 0.f;
  pt_AccOOIKinematic->fVrelX = 0.f;
  pt_AccOOIKinematic->fVrelY = 0.f;
}
#endif  /* (FCT_CFG_SEN2VEH_ACC_OOI_PORT) */

/*****************************************************************************
  Static FUNCTIONS
*****************************************************************************/
#if (OUT_CFG_CUSTOM_DRIVING_TUBE_MAPPING)
/*************************************************************************************************************************
  Functionname:    OUT_v_CustomSetDrivingTubeMapping                                                                 */ /*!

  @brief           Calculates the driving tube mapping as custom representation of the lane association of each object

  @description     Calculates the driving tube mapping as custom representation of the lane association of each object:
                    -Unknown lane: No ACC-Quality, out-of max. pick-up distance
                    -Oncoming objects: Not on ego lane except rolling back objects
                    -Other: The driving tube mapping is based on functional lane assignment (e_ObjFuncLane)  
                        -> lane association that considers timer, the object quality of stationary objects and "stationary oncoming" objects 
                   Function updates the parameter SIT_DRIVING_TUBE_MAPPING of each objects.

  @return          -

  @param[in]       -
  @param[out]      -

  @glob_in         LA_SUFFICIENT_FUN_PRESEL_QUALITY(i) : Boolean if object fulfills the ACC pre-selection                             [TRUE, FALSE]
                                                         with i in [0u ... EM_N_OBJECTS-1]
  @glob_in         OBJ_GET_FUNC_LANE(i) : Functional lane association of an object i                                                  [Full range of datatype eAssociatedLane_t as defined in Rte_Type.h] 
                                          with i in [0u ... EM_N_OBJECTS-1]
  @glob_in         pt_OUTInput  : Reference to OUT input data structure                                                               
                      t_RTE.pt_ObjDynProperty(i) : Dynamic property of an object iObjNr                                               [Full range of datatype SLATE_t_Obj_DynamicProperty as defined in Rte_Type.h] 
                                                   with i in [0u ... EM_N_OBJECTS-1]
                      t_LAInput.pf_ObjToRefDistMeas(i) : Pointer to object to reference distance measurement                          [-PI/2*RW_FCT_MAX ... PI/2*RW_FCT_MAX] m
                                                         with i in [0u ... EM_N_OBJECTS-1]
                      t_LAInput.pf_ObjToRefDistFiltVar(i) : Pointer to variance of object to reference distance measurement           [0 ... PI/2*RW_FCT_MAX] m
                                                            with i in [0u ... EM_N_OBJECTS-1]
  @glob_out        OUT_DRIVING_TUBE_MAPPING(i) : Drive tube mapping as custom representation of the lane association of each object i [Full range of datatype t_DrivingTubeMapping as in Rte_Type.h]
                                                 with i in [0u ... EM_N_OBJECTS-1]

  @c_switch_part   FCT_CFG_ACC_LANE_ASSOCIATION        : FCT support for ACC LA (Lane Association) sub-component
  @c_switch_full   OUT_CFG_CUSTOM_DRIVING_TUBE_MAPPING : Configuration switch for activating the calculation of the driving tube mapping of an object
  @c_switch_full   FCT_CFG_ACC_OUTPUT                  : Configuration switch to configure OUT (Output) sub-component for FCT_ACC

  @pre             -
  @post            -

  @created         -
  @changed         20.04.2016

  @author          Marie-Theres Boll | marie-theres.boll@continental-corporation.com | +49 (8382) 9699-632
*************************************************************************************************************************/
static void OUT_v_CustomSetDrivingTubeMapping(void)
{
  ObjNumber_t iObj;
  eAssociatedLane_t t_ObjFuncLane;

  for (iObj = 0u; iObj < (uint8)EM_N_OBJECTS; iObj++)
  {
    /*! Set default */
    OUT_DRIVING_TUBE_MAPPING(iObj) = FCT_DTM_UNKNOWN_LANE;

    /*! Unknown lane: No ACC-Quality, out-of max. pick-up distance 
        Oncoming objects: Not on ego lane (except cars rolling back) */
    if (LA_SUFFICIENT_FUN_PRESEL_QUALITY(iObj) == TRUE)
    {
      /*! By checking the object's relevance it is implicitly tested if the object is a rolling back oncoming object or 
      if it fulfilles the corridor criteria (blocked path) -> in both cases the object should be assigned to the ego lane */
      if(SLATE_b_GetObjIsRelevant(iObj))
      {
        OUT_DRIVING_TUBE_MAPPING(iObj) = FCT_DTM_EGO_LANE;
      }
      else
      {
        t_ObjFuncLane = pt_OUTInput->t_LAInput.pt_LAObjectList(iObj)->ObjFuncLane;

        /*! The driving tube mapping is based on functional lane assignment (e_ObjFuncLane)  
            -> lane association that considers timer, the object quality of stationary objects and "stationary oncoming" objects */
        switch(t_ObjFuncLane)
        {
        case ASSOC_LANE_EGO:
          /*! Oncoming objects are not allowed to be assigned to the ego lane (except rolling back vehicles which are considered before by FCTSen_b_GetObjIsRelevant(iObj)) */
          if(*pt_OUTInput->t_RTE.pt_ObjDynProperty(iObj) != SLATE_OBJECT_PROPERTY_ONCOMING)
          {
            OUT_DRIVING_TUBE_MAPPING(iObj) = FCT_DTM_EGO_LANE;
          }
          else
          {
            float32 f_DistanceToTraj;
            float32 f_DistanceToTrajVar;
#if (FCT_CFG_ACC_LANE_ASSOCIATION)
            f_DistanceToTraj = *(pt_OUTInput->t_LAInput.pf_ObjToRefDistMeas(iObj));
            f_DistanceToTrajVar = *(pt_OUTInput->t_LAInput.pf_ObjToRefDistFiltVar(iObj));
#endif
            if (f_DistanceToTraj < 0.f)
            {
              OUT_DRIVING_TUBE_MAPPING(iObj) = FCT_DTM_RIGHT_LANE;
            }
            else
            {
              OUT_DRIVING_TUBE_MAPPING(iObj) = FCT_DTM_LEFT_LANE;
            }
          }
          break;
        case ASSOC_LANE_LEFT:
          OUT_DRIVING_TUBE_MAPPING(iObj) = FCT_DTM_LEFT_LANE;
          break;
        case ASSOC_LANE_FAR_LEFT:
          OUT_DRIVING_TUBE_MAPPING(iObj) = FCT_DTM_ADJ_LEFT_LANE;
          break;
        case ASSOC_LANE_RIGHT:
          OUT_DRIVING_TUBE_MAPPING(iObj) = FCT_DTM_RIGHT_LANE;
          break;
        case ASSOC_LANE_FAR_RIGHT:
          OUT_DRIVING_TUBE_MAPPING(iObj) = FCT_DTM_ADJ_RIGHT_LANE;
          break;
        default:
          OUT_DRIVING_TUBE_MAPPING(iObj) = FCT_DTM_UNKNOWN_LANE;
          break;
        }
      }
    }
  }
}
#endif  /* (OUT_CFG_CUSTOM_DRIVING_TUBE_MAPPING) */

#if (OUT_CFG_CUSTOM_MEAS_STATUS_MAPPING)
/*************************************************************************************************************************
  Functionname:    OUT_v_CustomDynamicMeasStatus                                                                        */ /*!

  @brief           Fill the FCT object output list with the measurement status of an object and 
                   the dynamic measurement state of an object.

  @description     Fill the FCT object output list with the measurement status of an object and 
                   the dynamic measurement state of an object

  @return          -

  @param[in]       -
  @param[out]      -

  @glob_in         -
  @glob_out        GET_FCT_OBJ_PUB(i).Legacy.eObjMeasStatus : Object measurement status                                                    [Full range of datatype eObjMeasStatus_t as defined in Rte_Type.h]
  @glob_out        GET_FCT_OBJ_PUB(i).Legacy.eDynamicMeasStatus : Combination of the dynamic state and the measurement status of an object [Full range of datatype eDynamicMeasStatus_t as defined in Rte_Type.h]

  @c_switch_part   -
  @c_switch_full   FCT_CFG_ACC_OUTPUT                 : Configuration switch to configure OUT (Output) sub-component for FCT_ACC
  @c_switch_full   OUT_CFG_CUSTOM_MEAS_STATUS_MAPPING : Configuration switch for activating the calculation of the object meas status mapping of an object

  @pre             -
  @post            -

  @created         30.06.2010
  @changed         08.09.2015

  @author          Marie-Theres Boll | marie-theres.boll@continental-corporation.com | +49 (8382) 9699-632
*************************************************************************************************************************/
static void OUT_v_CustomDynamicMeasStatus(void)
{
  ObjNumber_t iObj;

  for (iObj = 0; iObj < EM_N_OBJECTS; iObj++)
  {
    if (!FCTSen_b_GetObjIsDeleted(iObj))
    {
      GET_FCT_OBJ_PUB(iObj).Legacy.eObjMeasStatus = OUT_t_ClassifyObjectMeasStatus (iObj);
      GET_FCT_OBJ_PUB(iObj).Legacy.eDynamicMeasStatus = OUT_t_ClassifyDynamicMeasStatus(iObj);
    }
    else
    {
      GET_FCT_OBJ_PUB(iObj).Legacy.eObjMeasStatus = OBJ_NONE;
      GET_FCT_OBJ_PUB(iObj).Legacy.eDynamicMeasStatus = NO_OBJ;
    }
  }
}
#endif  /* (OUT_CFG_CUSTOM_MEAS_STATUS_MAPPING) */

#if (OUT_CFG_CUSTOM_MEAS_STATUS_MAPPING)
/*************************************************************************************************************************
  Functionname:    OUT_t_ClassifyObjectMeasStatus                                                                       */ /*!

  @brief           Mapping of maintenance state of an object as defined in EM to the FCT output object measurement status

  @description     Mapping of maintenance state of an object as defined in EM to the FCT output object measurement status

  @return          MeasStatus : Object measurement status [Full range of datatype eObjMeasStatus_t as defined in Rte_Type.h]

  @param[in]       iObj : Object ID of datatype ObjNumber_t as defined in Rte_type.h                             [0u ... EM_N_OBJECTS-1]
  @param[out]      -

  @glob_in         pt_OUTInput->t_RTE.pt_ObjMaintenanceState(i) : Maintenance state of object i as defined in EM [Full range of datatype EM_t_GenObjMaintenanceState as defined in Rte_Type.h]
                                                                  with i in [0u ... EM_N_OBJECTS-1]
  @glob_in         OBJ_IS_MEASURED(iObj, (MEAS_SEN_FARSCAN | MEAS_SEN_NEARSCAN) : Boolean                        [TRUE, FALSE]
  @glob_out        -

  @c_switch_part   -
  @c_switch_full   FCT_CFG_ACC_OUTPUT                 : Configuration switch to configure OUT (Output) sub-component for FCT_ACC
  @c_switch_full   OUT_CFG_CUSTOM_MEAS_STATUS_MAPPING : Configuration switch for activating the calculation of the object meas status mapping of an object

  @pre             Only call this function for real (existing non-deleted) objects!
  @post            -

  @created         30.06.2010
  @changed         08.09.2015

  @author          Marie-Theres Boll | marie-theres.boll@continental-corporation.com | +49 (8382) 9699-632
*************************************************************************************************************************/
static eObjMeasStatus_t OUT_t_ClassifyObjectMeasStatus (ObjNumber_t iObj)
{
  eObjMeasStatus_t MeasStatus = OBJ_NONE;

  if ((iObj >= 0) && (iObj < EM_N_OBJECTS))
  {
    /* Use object maintenance state from EM to determine meas status */
    switch (*pt_OUTInput->t_RTE.pt_ObjMaintenanceState(iObj))
    {
    case EM_GEN_OBJECT_MT_STATE_INACTIVE:
#if EM_GEN_OBJECT_MT_STATE_DELETED != EM_GEN_OBJECT_MT_STATE_INACTIVE
    case EM_GEN_OBJECT_MT_STATE_DELETED: 
#endif
      MeasStatus = OBJ_NONE;
      break;
    case EM_GEN_OBJECT_MT_STATE_NEW:
      MeasStatus = OBJ_NEW;
      break;
    case EM_GEN_OBJECT_MT_STATE_MEASURED:
      MeasStatus = OBJ_CONFIRMED_MEASURED;
      break;
    case EM_GEN_OBJECT_MT_STATE_PREDICTED:
      MeasStatus = OBJ_NOT_MEASURED;
      break;
#if (EM_GEN_OBJECT_INTFVER < 3)
    case EM_GEN_OBJECT_MT_STATE_MERGE_DELETED:
      MeasStatus = OBJ_NONE;
      break;
    case EM_GEN_OBJECT_MT_STATE_MERGE_NEW:
      MeasStatus = OBJ_NEW;
      break;
#endif
    default:
      MeasStatus = OBJ_NONE;
      break;
    }
#if 0
    /* Alternative code: */
    if (!FCTSen_b_GetObjIsDeleted(iObj))
    {
      if (OBJ_LIFETIME(iObj) == 1u)
      {
        MeasStatus = OBJ_NEW;
      }
      else if (OBJ_IS_MEASURED(iObj, (MEAS_SEN_FARSCAN | MEAS_SEN_NEARSCAN)))
      {
        MeasStatus = OBJ_CONFIRMED_MEASURED;
      }
      else
      {
        MeasStatus = OBJ_NOT_MEASURED;
      }
    }
#endif
  }

  return MeasStatus;
}
#endif  /* (OUT_CFG_CUSTOM_MEAS_STATUS_MAPPING) */

#if (OUT_CFG_CUSTOM_MEAS_STATUS_MAPPING)
/*************************************************************************************************************************
  Functionname:    OUT_t_ClassifyDynamicMeasStatus                                                                      */ /*!

  @brief           Set the combination of the dynamic state and the measurement status of an object

  @description     Set the combination of the dynamic state and the measurement status of an object

  @return          DynamicMeasStatus : Combination of the dynamic state and the measurement status of an object [Full range of datatype eDynamicMeasStatus_t as defined in Rte_Type.h]

  @param[in]       iObj : Object ID of datatype ObjNumber_t as defined in Rte_type.h                                       [0u ... EM_N_OBJECTS-1]
  @param[out]      -

  @glob_in         pt_OUTInput : Reference to OUT input data structure                                                     
                      t_RTE.pt_ObjDynProperty(i) : Dynamic property of an object iObjNr                                    [Full range of datatype SLATE_t_Obj_DynamicProperty as defined in Rte_Type.h] 
                                                   with i in [0u ... EM_N_OBJECTS-1]
                      t_RTE.pt_ObjMaintenanceState(i) : Maintenance state of object i as defined in EM                     [Full range of datatype EM_t_GenObjMaintenanceState as defined in Rte_Type.h]
                                                        with i in [0u ... EM_N_OBJECTS-1]
  @glob_in         SLATE_b_GetObjIsMovingToStationary(i) : Boolean if an stationary object i was seen moving by the radar earlier [TRUE, FALSE]
                                                    with i in [0u ... EM_N_OBJECTS-1]
  @glob_out        -

  @c_switch_part   EM_GEN_OBJECT_INTFVER              : Interface version of generic object list
  @c_switch_full   FCT_CFG_ACC_OUTPUT                 : Configuration switch to configure OUT (Output) sub-component for FCT_ACC
  @c_switch_full   OUT_CFG_CUSTOM_MEAS_STATUS_MAPPING : Configuration switch for activating the calculation of the object meas status mapping of an object

  @pre             Only call this function for real (existing non-deleted) objects!
  @post            -

  @created         30.06.2010
  @changed         09.09.2015

  @author          Marie-Theres Boll | marie-theres.boll@continental-corporation.com | +49 (8382) 9699-632
*************************************************************************************************************************/
static eDynamicMeasStatus_t OUT_t_ClassifyDynamicMeasStatus(ObjNumber_t iObj)
{
  const EM_t_ARS_DynamicProperty DynamicProp = *pt_OUTInput->t_RTE.pt_ObjDynProperty(iObj);
  eDynamicMeasStatus_t DynamicMeasStatus;

  switch (*pt_OUTInput->t_RTE.pt_ObjMaintenanceState(iObj))
  {
  case EM_GEN_OBJECT_MT_STATE_PREDICTED:
    switch (DynamicProp)
    {
    case SLATE_OBJECT_PROPERTY_STATIONARY :   DynamicMeasStatus = NOT_MEASURED_STANDING_OBJ; break;
    case SLATE_OBJECT_PROPERTY_ONCOMING   :   DynamicMeasStatus = NOT_MEASURED_ONCOMING_OBJ; break;
    case SLATE_OBJECT_PROPERTY_MOVING     :   DynamicMeasStatus = NOT_MEASURED_MOVING_OBJ;   break;
    default                             :   DynamicMeasStatus = IMPLAUSIBLE_OBJ;           break;
    }
    if (SLATE_b_GetObjIsMovingToStationary(iObj))
    {
      DynamicMeasStatus = NOT_MEASURED_STOPPED_OBJ;
    }
    break;
  case EM_GEN_OBJECT_MT_STATE_MEASURED:
    switch (DynamicProp)
    {
    case SLATE_OBJECT_PROPERTY_STATIONARY :   DynamicMeasStatus = MEASURED_STANDING_OBJ; break;
    case SLATE_OBJECT_PROPERTY_ONCOMING   :   DynamicMeasStatus = MEASURED_ONCOMING_OBJ; break;
    case SLATE_OBJECT_PROPERTY_MOVING     :   DynamicMeasStatus = MEASURED_MOVING_OBJ;   break;
    default                             :   DynamicMeasStatus = IMPLAUSIBLE_OBJ;       break;
    }
    if (SLATE_b_GetObjIsMovingToStationary(iObj))
    {
      DynamicMeasStatus = MEASURED_STOPPED_OBJ;
    }
    break;
  case EM_GEN_OBJECT_MT_STATE_NEW:
#if (EM_GEN_OBJECT_INTFVER < 3)
  case EM_GEN_OBJECT_MT_STATE_MERGE_NEW:
#endif
    switch (DynamicProp)
    {
    case SLATE_OBJECT_PROPERTY_STATIONARY :   DynamicMeasStatus = NEW_STANDING_OBJ; break;
    case SLATE_OBJECT_PROPERTY_ONCOMING   :   DynamicMeasStatus = NEW_ONCOMING_OBJ; break;
    case SLATE_OBJECT_PROPERTY_MOVING     :   DynamicMeasStatus = NEW_MOVING_OBJ;   break;
    default                             :   DynamicMeasStatus = IMPLAUSIBLE_OBJ;  break;
    }
    if (SLATE_b_GetObjIsMovingToStationary(iObj))
    {
      DynamicMeasStatus = NEW_STOPPED_OBJ;
    }
    break;
  case EM_GEN_OBJECT_MT_STATE_DELETED:
#if EM_GEN_OBJECT_MT_STATE_DELETED != EM_GEN_OBJECT_MT_STATE_INACTIVE
   case EM_GEN_OBJECT_MT_STATE_INACTIVE: 
#endif
#if (EM_GEN_OBJECT_INTFVER < 3)
  case EM_GEN_OBJECT_MT_STATE_MERGE_DELETED:
#endif
  default:
    DynamicMeasStatus = NO_OBJ;
    break;
  }

  return DynamicMeasStatus ;
}
#endif  /* (OUT_CFG_CUSTOM_MEAS_STATUS_MAPPING) */

#if (OUT_CFG_CUSTOM_OBJ_WIDTH_OUTPUT)
/*************************************************************************************************************************
  Functionname:    OUT_v_CustomFillObjWidthOut                                                                          */ /*!

  @brief           Fill the custom object width output

  @description     Fill custom object width output (BMW CR for traffic jam assist)
                      - If mobil-eye raw input data supplied, then fill in camera object position information
                      - Otherwise: determine width classification based on internal class

  @return          -

  @param[in]       -
  @param[out]      -

  @glob_in         pSLATE_CameraObjData->CamObjectData[i].cCamConfirmationProb : Probability of camera confirmation of object i [0.f ... 100.f]
                                                                                  with i in [0u ... EM_N_OBJECTS-1]
  @glob_in         pSLATE_ME_in : Mobile Eye (ME) camera object list                                    
                      MEObjectListData.MEObjectList.CameraOutObjects : ME camera objects                 
                      MEObjectListData.MEObjectList.CameraOutObjects[i].iObjID : Object ID               [0u ... EM_N_OBJECTS-1]
                      MEObjectListData.MEObjectList.CameraOutObjects[i].cExternalID : External Object ID [0u ... EM_N_OBJECTS-1]
                      MEObjectListData.MEObjectList.CameraOutObjects[i].eMEClassification                [Full range of datatype of eMEClass_t as defined in interfacemeinputdata.h]
  @glob_in         pt_OUTInput->t_RTE.pt_ObjClassification(i) : Object class of object i                 [Full range of datatype SLATE_t_Obj_CLassification defined in Rte_Type.h]
                                                                with i in [0u ... EM_N_OBJECTS-1]
  @glob_out        pSLATE_CustomOutput->CustObjData[i].Relevance.eCustObjWidth : Custom object width    [Full range of datatype eCustObjWidth_t as defined in Rte_Type.h]

  @c_switch_part   FCT_CFG_CAMERA_OBJECT_DETECTION : FCT camera object/lane detection inputs
  @c_switch_part   OUT_CFG_USE_ME_CLASS_DIRECTLY   : Internal configuration switch to directly access ME input structure to output ME object class based wide object output
  @c_switch_full   FCT_CFG_ACC_OUTPUT              : Configuration switch to configure OUT (Output) sub-component for FCT_ACC
  @c_switch_full   OUT_CFG_CUSTOM_OBJ_WIDTH_OUTPUT : Internal configuration switch enabling custom object width output
  
  @pre             -
  @post            -

  @created         -
  @changed         21.04.2016

  @author          Gergely Ungvary
*************************************************************************************************************************/
static void OUT_v_CustomFillObjWidthOut(void)
{
  ObjNumber_t iObj;

  for (iObj = 0; iObj < EM_N_OBJECTS; iObj++)
  {
    eCustObjWidth_t eCustWid = CUST_OBJ_WIDTH_INVALID;
#if ((FCT_CFG_CAMERA_OBJECT_DETECTION) && (OUT_CFG_USE_ME_CLASS_DIRECTLY))
  percentage_t t_camConfirmationProb = pt_OUTInput->pt_FIPOA->t_ObjList[iObj].t_CamObjectData.t_CamConfirmationProb;
  uint8 t_ExternalIDCam = pt_OUTInput->pt_FIPOA->t_ObjList[iObj].u_ExternalID_Cam;
#endif

    if (!SLATE_b_GetObjIsDeleted(iObj))
    {
#if ((FCT_CFG_CAMERA_OBJECT_DETECTION) && (OUT_CFG_USE_ME_CLASS_DIRECTLY))
      /* If mobil-eye raw input data supplied, then fill in camera object position information */
      if ((t_camConfirmationProb > 0) && (pSLATE_ME_in != NULL))
      {
        ObjNumber_t iCamObjIdx;
        /* Use object class from camera confirmation */
        /* We need to find the mobil-eye object with the given ID */
        for (iCamObjIdx = 0; (iCamObjIdx < (ObjNumber_t)(sizeof(pSLATE_ME_in->MEObjectListData.MEObjectList.CameraOutObjects)/sizeof(pSLATE_ME_in->MEObjectListData.MEObjectList.CameraOutObjects[0]))) && (eCustWid == CUST_OBJ_WIDTH_INVALID); iCamObjIdx++)
        {
          if (t_ExternalIDCam == pSLATE_ME_in->MEObjectListData.MEObjectList.CameraOutObjects[iCamObjIdx].iObjID)
          {
            switch (pSLATE_ME_in->MEObjectListData.MEObjectList.CameraOutObjects[iCamObjIdx].eMEClassification)
            {
            case ME_CL_TRUCK:
            case ME_CL_BUS:
              eCustWid = CUST_OBJ_WIDTH_WIDE;
              break;
            case ME_CL_CAR:
              eCustWid = CUST_OBJ_WIDTH_MEDIUM;
              break;
            case ME_CL_BIKE:
              eCustWid = CUST_OBJ_WIDTH_SMALL;
              break;
            case ME_CL_CLOSE_CUTIN:
            case ME_CL_ONLY_DETECTED:
            case ME_CL_INVALID:
            case ME_CL_UNKNOWN:
            default:
              /* These classes currently don't get used */
              eCustWid = CUST_OBJ_WIDTH_INVALID;
              break;
            }
          }
        }
      }
      /* If first branch did not find an ME object with proper class, then
      use radar class as fall-back */
      if (eCustWid == CUST_OBJ_WIDTH_INVALID)
#endif
      {
        /* Perform width classification based on internal class */
        switch (*pt_OUTInput->t_RTE.pt_ObjClassification(iObj))
        {
        case SLATE_OBJCLASS_POINT:
        case SLATE_OBJCLASS_BICYCLE:
        case SLATE_OBJCLASS_PEDESTRIAN:
        case SLATE_OBJCLASS_MOTORCYCLE:
          /* Motorcycles, bicycles, pedestrians and points are small */
          eCustWid = CUST_OBJ_WIDTH_SMALL;
          break;
        case SLATE_OBJCLASS_CAR:
        case SLATE_OBJCLASS_UNCLASSIFIED:
          /* Cars become medium width */
          eCustWid = CUST_OBJ_WIDTH_MEDIUM;
          break;
        case SLATE_OBJCLASS_TRUCK:
        case ARS_OBJCLASS_WIDE:
          /* Trucks and wide objects are set to wide */
          eCustWid = CUST_OBJ_WIDTH_WIDE;
          break;
        default:
          eCustWid = CUST_OBJ_WIDTH_INVALID;
          break;
        }
      }
    }
    else
    {
      /* Object deleted : set cust object width to invalid */
      eCustWid = CUST_OBJ_WIDTH_INVALID;
    }
    /* Fill output interface width width information */
    pSLATE_CustomOutput->CustObjData[iObj].Relevance.eCustObjWidth = eCustWid;
  }
}
#endif  /* (OUT_CFG_CUSTOM_OBJ_WIDTH_OUTPUT) */

#if (FCT_CFG_CUSTOM_IO_INTERFACE)
/*************************************************************************************************************************
  Functionname:    OUT_v_CustomControlDistanceInfo                                                                      */ /*!

  @brief           Set customer specific output information

  @description     Set customer specific output information
                   In particular, 
                   - fVisibilityRestriction: custom max pickup distance including curve reduction
                   - fLongControlDistance: 40+2.2*vego as required pick-up range
                   - Seek lane width
                   - fRangeFactor : factor to reduce pick up distance based on curve observer
                   - PredictedTrajectory : ACC trajectory information
                   - BlockageInfo : Blockage information

  @return          -

  @param[in,out]   pFCTCustomOutput : reference to Custom Output structure                                               
                      AccSelectionInfo.fLongControlDistance : 40+2.2*vego as required pick-up range                       [-5*RW_FCT_MAX ... 5*RW_FCT_MAX] m                                                                        
                      AccSelectionInfo.fRangeFactor : Range factor to reduce required pick-up range in curvy situations   [0.f ... 1.f]        
                      AccSelectionInfo.fVisibilityRestriction : Custom max pickup distance including curve reduction      [-5*RW_FCT_MAX ... 5*RW_FCT_MAX] m                                                          
                      AccSelectionInfo.fSeekLaneWidth : The ACC seek lane width                                           [-PI/2*RW_FCT_MAX ... PI/2*RW_FCT_MAX] m                                                             
                      PredictedTrajectory.fCurveC0 : Curvature of ACC-trajectory                                          [-1.f ... +1.f] m^(-1)
                      PredictedTrajectory.fCurveC1 : Curvature change of ACC-trajectory                                   [-1.f ... +1.f] m^(-1)
                      PredictedTrajectory.fAngle : Side slip angle                                                        [-PI   +PI] rad
                      PredictedTrajectory.ucPredictState : Prediction state based on input for ACC trajectory             [Full range of datatype ucPredictState_t as defined in Rte_Type.h]
                      BlockageInfo.eSPMBlockageState : Blockage state                                                     [Full range of datatype uSYSDampState_t as defined in Rte_Type.h]
                      BlockageInfo.eSPMSelfTestState : Self test state                                                    [Full range of datatype ueGDBPDStates_t as defined in Rte_Type.h]
                      BlockageInfo.ucEstiRange : Estimation range                                                         [Full range of datatype uint8]
                      BlockageInfo.ucEstiRangeConf : Estimation range confidence                                          [0u ... 100u]
                      BlockageInfo.ucEstiRangeProb : Estimation range probability                                         [0u ... 100u]
                      BlockageInfo.ucObjLossProb : Object loss probability                                                [0u ... 100u]
                      BlockageInfo.ucObjLossConf : Object loss confidence                                                 [0u ... 100u]
                      BlockageInfo.ucOverallProb : Overall probability                                                    [0u ... 100u]
                      BlockageInfo.ucOverallConf : Overall confidence                                                     [0u ... 100u]
                      BlockageInfo.usRoadbeamTimeCnt : Roadbeam time counter                                              [Full range of datatype uint16]
                      BlockageInfo.usTimeoutWayCnt :  Timeout way counter                                                 [Full range of datatype uint16]
                      BlockageInfo.ucTimeoutTimeCnt : Timeout time counter                                                [Full range of datatype uint8]
                      BlockageInfo.ucTimeoutBlkProb : Timeout blockage probability                                        [0u ... 100u]
                      BlockageInfo.ucTimeoutBlkConf : Timeout blockage confidence                                         [0u ... 100u]
                      BlockageInfo.usFullBlkTimer : Full blockage timer                                                   [Full range of datatype uint16]

  @glob_in         pt_OUTInput->t_RTE.pf_EgoVelObjSync : Ego vehicle speed                                                               [-330.f ... 330.f] m/s
  @glob_in         pt_OUTInput : Reference to OUT input data structure                                                    
                      t_FIPInput.pf_ObjAbsVelX(iObj) : Absolute longitudinal velocity of object iObj                      [-330f   330f] m/s 
                                                       where iObj is in range [0u ... EM_N_OBJECTS-1]
                      t_FIPInput.pf_ObjAbsAccelX(iObj) : Absolute longitudinal acceleration of object iObj                [-100f   100f] m/s^2
                                                         where iObj is in range [0u ... EM_N_OBJECTS-1]
                      t_LAInput.pf_Rangefac : Range Factor                                                                [0.f, 1.f]
                      t_LAInput.pt_MovingObjPickUpRange : Pickup range of moving object                                   [-5*RW_FCT_MAX ... 5*RW_FCT_MAX] m
                      t_LAInput.pf_SeekLaneWidth : pointer to global seek lane width                                      [-PI/2*RW_FCT_MAX ... PI/2*RW_FCT_MAX] m
                      t_CP.pt_TrajectoryCurrent->fTrajC0 : Curvature                                                      [-1.f   +1.f]m^-1
                      t_CP.pt_TrajectoryCurrent->fTrajC1 : Curvature change                                               [-1.f   +1.f]m^-1
                      t_CP.pt_TrajectoryCurrent->fTrajAngle : Side slip angle                                             [-PI   +PI] rad
                      t_CP.pt_TrajectoryState->EgoCourseOnly : Bit indicating that only ego course used for trajectory    [0u, 1u]
                      t_CP.pt_TrajectoryState->FusionRoadstimation : Bit indicating that RE is used for trajectory fusion [0u, 1u]
                      t_CP.pt_TrajectoryState->FusionTraces : Bit indicating that Traces are used for trajectory fusion   [0u, 1u]
  
  @glob_out        pSLATE_CustomOutput->CustObjData[iObj].AbsolutKinematics.fAbsVelocityX : Absolute longitudinal velocity         [-330f   330f] m/s  
  @glob_out        pSLATE_CustomOutput->CustObjData[iObj].AbsolutKinematics.fAbsAccelerationX : Absolute longitudinal acceleration [-100f   100f] m/s^2 

  @c_switch_part   FCT_CFG_SIGNAL_PERF_MONITORING  : FCT signal performance monitoring
  @c_switch_part   FCT_CFG_CUSTOM_IO_ABS_KINEMATIC : FCT absolute kinematic data in custom interface
  @c_switch_part   FCT_CFG_ACC_LANE_ASSOCIATION    : FCT support for ACC LA (Lane Association) sub-component
  @c_switch_full   FCT_CFG_ACC_OUTPUT              : Configuration switch to configure OUT (Output) sub-component for FCT_ACC
  @c_switch_full   FCT_CFG_CUSTOM_IO_INTERFACE     : FCT custom I/O interface

  @pre             -
  @post            -

  @created         22.03.2016
  @changed         22.03.2016

  @author          Benoit Bagot | benoit.bagot@continental-corporation.com | +49 (8382) 9699-376
*************************************************************************************************************************/
static void OUT_v_CustomControlDistanceInfo(void)
{
  float32 Control_Dist;
#if (FCT_CFG_CUSTOM_IO_ABS_KINEMATIC)
  ObjNumber_t iObj;
#endif /* FCT_CFG_CUSTOM_IO_ABS_KINEMATIC */
  float32 f_EgoVel = (*pt_OUTInput->t_RTE.pf_EgoVelObjSync);
  
  Control_Dist = OUT_BMW_SLOPE_FACTOR * f_EgoVel;
  Control_Dist += OUT_BMW_MIN_CONTROL_DIST;

  pSLATE_CustomOutput->AccSelectionInfo.fLongControlDistance = MIN_FLOAT(Control_Dist,OUT_BMW_MAX_CONTROL_DIST);

#if (FCT_CFG_CUSTOM_IO_ABS_KINEMATIC)
  /* Copying object velocity and acceleration as output. Replacement for macro OBJ_ABS_VELO_X and OBJ_ABS_ACCEL_X */
  for (iObj = 0; iObj<EM_N_OBJECTS; iObj++)
  {
    pSLATE_CustomOutput->CustObjData[iObj].AbsolutKinematics.fAbsVelocityX = pt_OUTInput->pt_FIPOA->t_ObjList[iObj].fAbsVelocity;
    pSLATE_CustomOutput->CustObjData[iObj].AbsolutKinematics.fAbsAccelerationX = pt_OUTInput->pt_FIPOA->t_ObjList[iObj].fAbsAcceleration;
  }
#endif /* FCT_CFG_CUSTOM_IO_ABS_KINEMATIC */
#if (FCT_CFG_ACC_LANE_ASSOCIATION)
  pSLATE_CustomOutput->AccSelectionInfo.fRangeFactor = *(pt_OUTInput->t_LAInput.pf_Rangefac);

  pSLATE_CustomOutput->AccSelectionInfo.fVisibilityRestriction = *(pt_OUTInput->t_LAInput.pt_MovingObjPickUpRange);
#endif
#if (FCT_CFG_ACC_LANE_ASSOCIATION)
  pSLATE_CustomOutput->AccSelectionInfo.fSeekLaneWidth = *(pt_OUTInput->t_LAInput.pf_SeekLaneWidth);
#endif /*FCT_CFG_ACC_LANE_ASSOCIATION*/
  pSLATE_CustomOutput->PredictedTrajectory.fCurveC0   = pt_OUTInput->t_CP.pt_TrajectoryCurrent->fTrajC0;
  pSLATE_CustomOutput->PredictedTrajectory.fCurveC1   = pt_OUTInput->t_CP.pt_TrajectoryCurrent->fTrajC1;
  pSLATE_CustomOutput->PredictedTrajectory.fAngle     = pt_OUTInput->t_CP.pt_TrajectoryCurrent->fTrajAngle;
  pSLATE_CustomOutput->PredictedTrajectory.ucPredictState = PRED_ACC_TRAJ_EGO_ONLY;
  /* Decode the ego course information */
  if (!pt_OUTInput->t_CP.pt_TrajectoryState->EgoCourseOnly)
  {
    if (pt_OUTInput->t_CP.pt_TrajectoryState->FusionRoadstimation)
    {
      pSLATE_CustomOutput->PredictedTrajectory.ucPredictState |= PRED_ACC_TRAJ_ROAD_ESTI;
    }
    if (pt_OUTInput->t_CP.pt_TrajectoryState->FusionTraces)
    {
      pSLATE_CustomOutput->PredictedTrajectory.ucPredictState |= PRED_ACC_TRAJ_OBJ_TRACES;
    }
  }
}
#endif  /* (FCT_CFG_CUSTOM_IO_INTERFACE) */

#if (OUT_CFG_CUSTOM_CRITERIA_MATRIX_PROCESSING)
/*************************************************************************************************************************
  Functionname:    OUT_v_StoreTraceBracketExts                                                                          */ /*!

  @brief           Fill custom measurement data on OOI list

  @description     Fills custom measurement data attached to SI OOI list
                      - Copy away the trace brackets for debugging

  @return          -

  @param[in]       -
  @param[out]      -

  @glob_in         -
  @glob_out        OUTCustObjData[i].TrExtWord : Bits indicating active trace bracket information [Full range of datatype TrExtWord (uint32) as defined in out_customfunctions.h]
                                                 with i in [0 ... EM_N_OBJECTS-1]
  @glob_out        pSLATE_CustomOutput->CustObjData[i].Relevance.uiTraceBracketBits : Bits indicating the active trace brackets extension for object iObj 
                                                                                       with i in [0 ... EM_N_OBJECTS-1] [Full range of uint32] 
 
  @c_switch_part   -
  @c_switch_full   OUT_CFG_CUSTOM_CRITERIA_MATRIX_PROCESSING : Configuration switch for activating additional call to custom SICustProcessCriteriaMatrix after all other trace bracket processing took place
  @c_switch_full   FCT_CFG_ACC_OUTPUT                        : Configuration switch to configure OUT (Output) sub-component for FCT_ACC

  @pre             -
  @post            -

  @created         -
  @changed         20.04.2016

  @author          Gergely Ungvary
*************************************************************************************************************************/
static void OUT_v_StoreTraceBracketExts(void)
{
  ObjNumber_t iObj;

  for (iObj=0; iObj < EM_N_OBJECTS; iObj++)
  {
    if (SLATE_b_GetObjIsDeleted(iObj))
    {
      OUTCustObjData[iObj].TrExtWord = 0u;
    }
    /* Now copy away the trace brackets for debugging */
    pSLATE_CustomOutput->CustObjData[iObj].Relevance.uiTraceBracketBits  = OUTCustObjData[iObj].TrExtWord;
  }
}
#endif  /* (OUT_CFG_CUSTOM_CRITERIA_MATRIX_PROCESSING) */

#if (OUT_CFG_CUSTOM_CRITERIA_MATRIX_PROCESSING)
/*************************************************************************************************************************
  Functionname:    OUT_b_TestTraceBracketPosition                                                                       */ /*!

  @brief           Test the bracket position for validity

  @description     Test the bracket position for validity. If the absolute value for position is close to zero or greater
                   than half of the init value,  then the value is considered as invalid.

  @return          bRetVal : Information if trace bracket value within valid range [TRUE, FALSE]

  @param[in]       fBracketPos : Position of trace bracket                         [-PI/2*RW_FCT_MAX ... PI/2*RW_FCT_MAX] m
  @param[out]      -

  @glob_in         -
  @glob_out        -

  @c_switch_part   -
  @c_switch_full   OUT_CFG_CUSTOM_CRITERIA_MATRIX_PROCESSING : Configuration switch for activating additional call to custom SICustProcessCriteriaMatrix after all other trace bracket processing took place
  @c_switch_full   FCT_CFG_ACC_OUTPUT                        : Configuration switch to configure OUT (Output) sub-component for FCT_ACC

  @pre             -
  @post            - 

  @created         08.03.2016
  @changed         08.03.2016

  @author          Thomas Bock | thomas.2.bock@continental-corporation.com | +49 (8382) 9699-755
*************************************************************************************************************************/
static boolean OUT_b_TestTraceBracketPosition(float32 fBracketPos)
{
  const float32 fBracketPosAbs = fABS(fBracketPos);
  boolean bRetVal = FALSE;
  if ((fBracketPosAbs < C_F32_DELTA) || (fBracketPosAbs > (INITVALUE_BRACKETPOSITION * 0.5f)))
  {
    bRetVal = FALSE;
  }
  else
  {
    bRetVal = TRUE;
  }
  return bRetVal;
}
#endif /* #if OUT_CFG_CUSTOM_CRITERIA_MATRIX_PROCESSING */

#if (SIT_CFG_TRAFFIC_ESTIMATION && FCT_CFG_CUSTOM_IO_INTERFACE)
/*************************************************************************************************************************
  Functionname:    OUT_v_CustomTrafficJamProbability                                                                    */ /*!

  @brief           Fills custom traffic jam probability

  @description     Fills custom traffic jam probability (copy from internal structure)

  @return          -

  @param[in]       -
  @param[out]      -

  @glob_in         SITGlobalDensityData : Global structure to store traffic density and traffic estimation data 
                      uiJamProbability : probability, that ego vehicle is in a traffic jam based on observation of surrounding vehicles                         [0.f ... 1.f]    
  @glob_out        pSLATE_CustomOutput : Custom Outputs from FCT component                                     
                      TrafficDensityData.TrafficJamProbability : probability, that ego vehicle is in a traffic jam based on observation of surrounding vehicles [0.f ... 1.f] 

  @c_switch_part   - 
  @c_switch_full   FCT_CFG_ACC_OUTPUT         : Configuration switch to configure OUT (Output) sub-component for FCT_ACC
  @c_switch_full   SIT_CFG_TRAFFIC_ESTIMATION : Configuration switch to enable/disable the calculation of a traffic flow and traffic jam probability (sit_traffic_estimation.c)
  
  @pre             -
  @post            -

  @created         08.03.2016
  @changed         08.03.2016

  @author          Thomas Bock | thomas.2.bock@continental-corporation.com | +49 (8382) 9699-755
*************************************************************************************************************************/
static void OUT_v_CustomTrafficJamProbability(void)
{
  pSLATE_CustomOutput->TrafficDensityData.TrafficJamProbability = SITGlobalDensityData.uiJamProbability;
}
#endif  /* (SIT_CFG_TRAFFIC_ESTIMATION && FCT_CFG_CUSTOM_IO_INTERFACE) */

#if ((FCT_CFG_CUSTOM_IO_INTERFACE) && (OUT_CFG_CUSTOM_TO_OUTPUT))
/*************************************************************************************************************************
  Functionname:         OUT_v_CustomTrafficOrientation                                                               */ /*!

  @brief                Fills out custom traffic orientation provide port signal

  @description          Fills out custom traffic orientation provide port signal

  @return               


  @glob_in              None
  @glob_out             None

  @c_switch_part        None  
  @c_switch_full        FCT_CFG_CUSTOM_IO_INTERFACE : FCT custom I/O interface

  @pre                  None 
  @post                 None 

  @author               Harsha Umesh Babu | Harsha.Umesh.Babu@continental-corporation.com | +49 (8382) 9699-474
*************************************************************************************************************************/
static void OUT_v_CustomTrafficOrientation(void)
{
  pSLATE_CustomOutput->TrafficDensityData.e_FusedTrOrientation = FIP_pt_TO_GetTrafficOrientation()->t_FIPTrafficOrientation;
}
#endif  /* END IF ((FCT_CFG_CUSTOM_IO_INTERFACE) && (OUT_CFG_CUSTOM_TO_OUTPUT)) */

#if (SIT_CFG_CUSTOM_COLECTIVE_VEL_POSTPROCESSING && SIT_CFG_TRAFFIC_ESTIMATION)
/*************************************************************************************************************************
  Functionname:    OUT_v_CustomCollectiveVelocityPostProcessing                                                         */ /*!

  @brief           Custom post processing of collective velocity

  @description     Custom post processing of collective velocity
                   The standard deviation of collective velocity is low pass filtered for the custom output f_TrafficRegularity

  @return          -

  @param[in]       -
  @param[out]      -

  @glob_in         SITGlobalDensityData.t_CollectiveObject.dStdAbw : Standard deviation of collective velocity                             [-330.f ... 330.f] m/s             
  @glob_out        pSLATE_CustomOutput->TrafficDensityData.f_TrafficRegularity: New value of trafic regularity (Mean Abs. Speed Variance) [-330.f ... 330.f] m/s
                     
  @c_switch_part   -
  @c_switch_full   SIT_CFG_CUSTOM_COLECTIVE_VEL_POSTPROCESSING : Configuration switch for enabling custom output of the collective velocity
  @c_switch_full   SIT_CFG_TRAFFIC_ESTIMATION                  : Configuration switch to enable/disable the calculation of a traffic flow and traffic jam probability
  @c_switch_full   FCT_CFG_ACC_OUTPUT                          : Configuration switch to configure OUT (Output) sub-component for FCT_ACC

  @pre             -
  @post            -

  @created         21.03.2016
  @changed         21.03.2016

  @author          Christopher Knievel | Christopher.Knievel@continental-corporation.com | +49 (8382) 9699-399
*************************************************************************************************************************/
static void OUT_v_CustomCollectiveVelocityPostProcessing(void)
{
  /* do something here */
  pSLATE_CustomOutput->TrafficDensityData.f_TrafficRegularity = SITGlobalDensityData.t_CollectiveObject.dStdAbw;
}
#endif  /* (SIT_CFG_CUSTOM_COLECTIVE_VEL_POSTPROCESSING && SIT_CFG_TRAFFIC_ESTIMATION) */

#if (OUT_CFG_CUSTOM_XY_RELEVANCE)
/*************************************************************************************************************************
  Functionname:    OUT_v_CustomSort                                                                                     */ /*!

  @brief           Generated a sorted list of indices of input data

  @description     Generated a sorted list of indices of input data. Important: SortedIndices has to contain values in the
                      range of [0 ... EM_N_OBJECTS-1]

  @return          -

  @param[in]       Input : Array of EM_N_OBJECTS floats according to which the second input/output array is sorted according to current usage [-5*RW_FCT_MAX ... 5*RW_FCT_MAX] m                 
  @param[in,out]   SortedIndices : Array of EM_N_OBJECTS values in the range of [0u ... EM_N_OBJECTS-1] in increasing order on input (i.e. [0, 1, 2, 3 ... 39]). 
                      On output the indices are ordered according to the first input array's values in ascending order

  @glob_in         -
  @glob_out        -

  @c_switch_part   -
  @c_switch_full   FCT_CFG_ACC_OUTPUT          : Configuration switch to configure OUT (Output) sub-component for FCT_ACC
  @c_switch_full   OUT_CFG_CUSTOM_XY_RELEVANCE : Configuration switch for activating the calculation of the x-relevance and y-relevance of an object

  @pre             -
  @post            -

  @created         -
  @changed         08.04.2016

  @author          Juergen Brugger, Carsten Schmitz
*************************************************************************************************************************/
static void OUT_v_CustomSort(const float32 Input[], ObjNumber_t SortedIndices[])
{
  ObjNumber_t i, j, k;

  /*! @todo use a better/faster sorting algorithm than bubble-sort */
  for (i = 1; i < EM_N_OBJECTS; i++)
  {
    for (j = 0; j < (EM_N_OBJECTS-i); j++)
    {
      if (Input[SortedIndices[j]] > Input[SortedIndices[j+1L]])
      {
        k = SortedIndices[j];
        SortedIndices[j]   = SortedIndices[j+1L];
        SortedIndices[j+1L] = k;
      }
    }
  }
}
#endif  /* (OUT_CFG_CUSTOM_XY_RELEVANCE) */

#if (OUT_CFG_CUSTOM_XY_RELEVANCE)
/*************************************************************************************************************************
  Functionname:    OUT_v_CustomRelevanceXDist                                                                           */ /*!

  @brief           Calculates longitudinal (X) relevance depending on polar distance

  @description     1. Calculate polar distance given by dist_x and dist_y
                   2. Sort object list by polar distance
                   3. Assign relevance to sort list according parameter

                    Longitudinal relevance by Distance:
                    - maximum relevance will be assigned to nearest object
                    - relevance decreases by step from object to object
                    - relevance will not decrease below minimum value

                    OOIRelevanceParameter.CustomRelevanceX.bUseDist
                    switch to use longitudinal relevance by distance

                    OOIRelevanceParameter.CustomRelevanceX.fDistMax
                    maximum relevance value (assigned to nearest object)

                    OOIRelevanceParameter.CustomRelevanceX.fDistMin
                    minimum relevance value

                    OOIRelevanceParameter.CustomRelevanceX.fDistStep
                    step (reduction from object to object)

  @return          -

  @param[in]       -
  @param[out]      -

  @glob_in         LA_SUFFICIENT_FUN_PRESEL_QUALITY(i)  : Boolean if object fulfills the ACC pre-selection        [TRUE, FALSE]
                                                          with i in [0u ... EM_N_OBJECTS-1]
  @glob_in         pt_OUTInput->t_RTE.pf_ObjLongDisp(i) : Longitudinal displacement of an object i                [-5*RW_FCT_MAX ... 5*RW_FCT_MAX] 
                                                          with i in [0u ... EM_N_OBJECTS-1]
  @glob_in         pt_OUTInput->t_RTE.pf_ObjLatDisp(i)  : Lateral displacement of an object i                     [-PI/2*RW_FCT_MAX ... PI/2*RW_FCT_MAX] m 
                                                          with i in [0u ... EM_N_OBJECTS-1]
  @glob_in         OOIRelevanceParameter : Relevance application parameters
                      CustomRelevanceX.fMin : minimum longitudinal relevance                                      [-5*RW_FCT_MAX ... 5*RW_FCT_MAX] m
                      CustomRelevanceX.fDistMax : maximum longitudinal relevance for distance criterion           [-5*RW_FCT_MAX ... 5*RW_FCT_MAX] m
                      CustomRelevanceX.fDistMin : minimum longitudinal relevance for distance criterion           [-5*RW_FCT_MAX ... 5*RW_FCT_MAX] m
                      CustomRelevanceX.fDistStep : decrement longitudinal relevance by step from object to object [-5*RW_FCT_MAX ... 5*RW_FCT_MAX] m
  @glob_out        OUT_OBJ_RELEVANCE_X(i) : X-Relevance of an object i                                            [0.f ... 1.f]
                                            with i in [0u ... EM_N_OBJECTS-1]

  @c_switch_part   -
  @c_switch_full   OUT_CFG_CUSTOM_XY_RELEVANCE : Configuration switch for activating the calculation of the x-relevance and y-relevance of an object
  @c_switch_full   FCT_CFG_ACC_OUTPUT          : Configuration switch to configure OUT (Output) sub-component for FCT_ACC

  @pre             -
  @post            -

  @created         -
  @changed         08.04.2016

  @author          Carsten Schmitz
*************************************************************************************************************************/
static void OUT_v_CustomRelevanceXDist(void)
{
  ObjNumber_t iObj;
  ObjNumber_t CustomRelevantObjects = 0;
  float32 DistPolarSq[EM_N_OBJECTS];
  ObjNumber_t SortedIndices[EM_N_OBJECTS];
  float32 Relevance;
  float32 fTemp;

  /* create polar distance */
  /* loop over object list */
  for (iObj = 0; iObj < EM_N_OBJECTS; iObj++)
  {
    /* object valid for customer function */
    if (LA_SUFFICIENT_FUN_PRESEL_QUALITY(iObj) == TRUE)
    {
      /* create polar distance square (we don't need the polar distance itself,
      since we will merely sort according to distance) */
      DistPolarSq[iObj] = (SQR(*(pt_OUTInput->t_RTE.pf_ObjLongDisp(iObj))) + SQR(*pt_OUTInput->t_RTE.pf_ObjLatDisp(iObj)));
      /* increase number of valid/relevant objects */
      CustomRelevantObjects++;
    }
    else
    {
      /* set polar distance to invalid */
      DistPolarSq[iObj] = SQR(DIST_INVALID);

      /* reset relevance for all invalid objects */
      fTemp = OOIRelevanceParameter.CustomRelevanceX.fMin * OUT_RELEVANCE_SCALE;

      OUT_OBJ_RELEVANCE_X(iObj) = (uint8)(fTemp);
    }

    /* init indices array for calling sort function */
    SortedIndices[iObj] = iObj;
  }

  /* sort array by distance --> increasing */
  #pragma message(__FILE__"("STRING_QUOTE(__LINE__)"): TODO: Check if an custom sort is still needed!")
  OUT_v_CustomSort(DistPolarSq, SortedIndices);

  /* set initial relevance */
  Relevance = OOIRelevanceParameter.CustomRelevanceX.fDistMax;

  /* create relevance */
  /* run through sorted list;
     sorted list has no gaps with invalid entries; first elements are valid/relevant objects */
  for (iObj = 0; iObj < CustomRelevantObjects; iObj++)
  {
    fTemp = MAX_FLOAT(Relevance, OOIRelevanceParameter.CustomRelevanceX.fDistMin)* OUT_RELEVANCE_SCALE;
    OUT_OBJ_RELEVANCE_X(SortedIndices[iObj]) = (uint8)(fTemp);

    /* update relevance */
    Relevance -= OOIRelevanceParameter.CustomRelevanceX.fDistStep;
  }
}
#endif  /* (OUT_CFG_CUSTOM_XY_RELEVANCE) */

#if (OUT_CFG_CUSTOM_XY_RELEVANCE)
/*************************************************************************************************************************
  Functionname:    OUT_v_CustomRelevanceXTotal                                                                          */ /*!

  @brief           Combines all single results to one total result

  @description     Longitudinal relevance
                    - sum of relevances by distance/relative speed/ttc
                    - relevances by relative speed and ttc are not used (default),
                    but can be switched on

                    OOIRelevanceParameter.CustomRelevanceX.fMin
                    minimum relevance value

                    OOIRelevanceParameter.CustomRelevanceX.fMax
                    maximum relevance value

  @return          -

  @param[in]       -
  @param[out]      -

  @glob_in         OOIRelevanceParameter : Relevance application parameters
                      CustomRelevanceX.fMin : minimum longitudinal relevance                                             [-5*RW_FCT_MAX ... 5*RW_FCT_MAX] m
                      CustomRelevanceX.fMax : maximum lateral relevance                                                  [-PI/2*RW_FCT_MAX ... PI/2*RW_FCT_MAX] m
  @glob_in         LA_SUFFICIENT_FUN_PRESEL_QUALITY(i) : Boolean if object fulfills the ACC pre-selection                [TRUE, FALSE]
                                                         with i in [0u ... EM_N_OBJECTS-1]
  @glob_in         OUT_OBJ_RELEVANCE_X(i) : X-Relevance of an object i                                                   [0.f ... 1.f]
                                            with i in [0u ... EM_N_OBJECTS-1]
  @glob_in         pSLATE_CameraObjData
                      CustObjects[i].CamObjectData.cCamConfirmationProb : Probability of camera confirmation of object i [0 ... 100.f]
                                                                          with i in [0u ... EM_N_OBJECTS-1]
                      CustObjects[iObj].CamObjectData.eObjManeuver : Maneuver of camera object i                         [Full range of datatype eCamObjManeuver_t as defined in interfaceemcodoutput.h]
                                                                     with i in [0u ... EM_N_OBJECTS-1]
  @glob_in         OUT_CAM_CONF_X_RELEVANCE_GATE : The camera/radar object matching confidence from which relevances over 0.08 are allowed [Full range of datatype uCamConfRelevanceGate as defined in out_customfunctions.h]
..@glob_out        OUT_OBJ_RELEVANCE_X(i) : X-Relevance of an object i                                                   [0.f ... 1.f]
                                            with i in [0u ... EM_N_OBJECTS-1]

  @c_switch_part   FCT_CFG_CAMERA_OBJECT_DETECTION : FCT camera object/lane detection inputs
  @c_switch_full   FCT_CFG_ACC_OUTPUT              : Configuration switch to configure OUT (Output) sub-component for FCT_ACC
  @c_switch_full   OUT_CFG_CUSTOM_XY_RELEVANCE     : Configuration switch for activating the calculation of the x-relevance and y-relevance of an object

  @pre             OUT_OBJ_RELEVANCE_X(i) filled for all ACC selectable objects with a valid X relevance value
  @post            -

  @created         -
  @changed         08.04.2016

  @author          Carsten Schmitz
*************************************************************************************************************************/
static void OUT_v_CustomRelevanceXTotal(void)
{
  sint32 iObj;
  uint8 uSelectableMinRel;
  uint8 uSelectableMaxRel;
  float32 fTemp;

  /* Calculate the integer arithmetic minimum and maximum relevance values
  for selectable objects */
  fTemp = OOIRelevanceParameter.CustomRelevanceX.fMin * OUT_RELEVANCE_SCALE;
  uSelectableMinRel = (uint8)(fTemp);
  fTemp = OOIRelevanceParameter.CustomRelevanceX.fMax * OUT_RELEVANCE_SCALE;
  uSelectableMaxRel = (uint8)(fTemp);

  /* loop over object list */
  for (iObj = 0L; iObj < EM_N_OBJECTS; iObj++)
  {
    uint8 ObjRelevance;
#if (FCT_CFG_CAMERA_OBJECT_DETECTION)
  percentage_t t_camConfirmationProb = pt_OUTInput->pt_FIPOA->t_ObjList[iObj].t_CamObjectData.t_CamConfirmationProb;
  FIP_t_CamObjManeuver t_eObjManeuver = pt_OUTInput->pt_FIPOA->t_ObjList[iObj].t_CamObjectData.eObjManeuver;
#endif
    /* object is valid for customer relevance */
    if (LA_SUFFICIENT_FUN_PRESEL_QUALITY(iObj) == TRUE)
    {
      /* keep in range */
      ObjRelevance = (uint8)(MINMAX(uSelectableMinRel, uSelectableMaxRel, OUT_OBJ_RELEVANCE_X(iObj)));
    }
    /* object is invalid for customer relevance */
    else
    {
      /* reset relevance for all invalid objects */
      ObjRelevance = uSelectableMinRel;
    }

#if (FCT_CFG_CAMERA_OBJECT_DETECTION)
    /* The SF-CAN specification for signal RVLNC_X_HDWOBS_xx specifies that a longitudinal relevance
    smaller 0.1 means only radar object, while all larger relevance values mean camera and radar
    object.
    This was modified after I-300 to the following: a range of [0.1 .. 0.2] means video confirmed
    while [0.2 .. 0.25] means video confirmed and a cut-out */
   if (t_camConfirmationProb > OUT_CAM_CONF_X_RELEVANCE_GATE)
    {
      /* Object is confirmed by camera */
      if (t_eObjManeuver == FIP_CAM_OM_CUT_OUT)
      {
        ObjRelevance = OUT_PAR_CAM_CONF_CUT_OUT_X_RELEVANCE;
      }
      else
      {
        ObjRelevance = OUT_PAR_CAM_CONF_DEFAULT_X_RELEVANCE;
      }
    }
    else
    {
      /* Object is not confirmed by camera, the maximal relevance must be less then 0.1 (10) */
      ObjRelevance = MIN(ObjRelevance, OUT_OBJ_RELEVANCE_X);
    }
#endif

    OUT_OBJ_RELEVANCE_X(iObj) = ObjRelevance;
  }
}
#endif  /* (OUT_CFG_CUSTOM_XY_RELEVANCE) */

#if (OUT_CFG_CUSTOM_XY_RELEVANCE)
/*************************************************************************************************************************
  Functionname:    OUT_v_CustomRelevanceX                                                                               */ /*!

  @brief           Calculates longitudinal (X) relevance for each object

  @description     Calculates longitudinal (X) relevance for each object
                   First, calculates longitudinal (X) relevance depending on polar distance 
                   Second, combine all single results to one total result.

  @return          -

  @param[in]       -
  @param[out]      -

  @glob_in         OOIRelevanceParameter.CustomRelevanceX.bUseDist : Distance for longitudinal relevance, Boolean [TRUE, FALSE]
  @glob_out        -

  @c_switch_part   -
  @c_switch_full   FCT_CFG_ACC_OUTPUT          : Configuration switch to configure OUT (Output) sub-component for FCT_ACC
  @c_switch_full   OUT_CFG_CUSTOM_XY_RELEVANCE : Configuration switch for activating the calculation of the x-relevance and y-relevance of an object

  @pre             -
  @post            -

  @created         -
  @changed         19.04.2016

  @author          Carsten Schmitz
*************************************************************************************************************************/
static void OUT_v_CustomRelevanceX(void)
{
  /* relevance depending on distance */
  if (OOIRelevanceParameter.CustomRelevanceX.bUseDist == TRUE)
  {
    OUT_v_CustomRelevanceXDist();
  }
  #pragma message(__FILE__"("STRING_QUOTE(__LINE__)"): TODO: As vrel and ttc calculation is not needed  OUT_v_CustomRelevanceXTotal() could be improved !")
  /* combine all single results to one total result */
  OUT_v_CustomRelevanceXTotal();
}
#endif  /* OUT_CFG_CUSTOM_XY_RELEVANCE */

#if (OUT_CFG_CUSTOM_XY_RELEVANCE)
/*************************************************************************************************************************
  Functionname:    OUT_v_CustomRelevanceYLane                                                                           */ /*!

  @brief           Calculates lateral (Y) relevance depending on lane occupancy

  @description     Lateral relevance by Lane:
                   - digital decision if object is inside ego lane or not

                   OOIRelevanceParameter.CustomRelevanceY.fLaneInCut0
                   - relevance value if object is inside ego lane
                     must be > OUT_CUSTOM_REL_Y_THRESHOLD
                   - parameter is also used for cut-in/out potential
                     (inside lane with 0% cut-out potential)

                   OOIRelevanceParameter.CustomRelevanceY.fLaneOutCut0
                   - relevance value if object is not inside ego lane
                     must be <= OUT_CUSTOM_REL_Y_THRESHOLD
                   - parameter is also used for cut-in/out potential
                     (not inside lane with 0% cut-in potential)

  @return          -

  @param[in]       -
  @param[out]      -

  @glob_in         LA_SUFFICIENT_FUN_PRESEL_QUALITY(i) : Boolean if object fulfills the ACC pre-selection [TRUE, FALSE]
                                                         with i in [0u ... EM_N_OBJECTS-1]
  @glob_in         OBJ_GET_FUNC_LANE(i) : Functional lane association of an object i                                          [Full range of datatype eAssociatedLane_t as defined in Rte_Type.h]
                                          with i in [0u ... EM_N_OBJECTS-1]
  @glob_in         OOIRelevanceParameter
                      CustomRelevanceY.fLaneInCut0 : lateral relevance for objects in ego lane with 0% cut out potential      [-PI/2*RW_FCT_MAX ... PI/2*RW_FCT_MAX] m
                      CustomRelevanceY.fLaneOutCut0 : lateral relevance for objects not in ego lane with 0% cut in potential  [-PI/2*RW_FCT_MAX ... PI/2*RW_FCT_MAX] m
                      CustomRelevanceY.fMin : minimum longitudinal relevance                                                  [-5*RW_FCT_MAX ... 5*RW_FCT_MAX] m
  @glob_out        OUT_OBJ_RELEVANCE_Y(i) : Y-relevance of object i [0u ... 1u] with i in [0u ... EM_N_OBJECTS-1]

  @c_switch_part   -
  @c_switch_full   FCT_CFG_ACC_OUTPUT          : Configuration switch to configure OUT (Output) sub-component for FCT_ACC
  @c_switch_full   OUT_CFG_CUSTOM_XY_RELEVANCE : Configuration switch for activating the calculation of the x-relevance and y-relevance of an object

  @pre             -
  @post            -

  @created         -
  @changed         19.04.2016

  @author          Carsten Schmitz
*************************************************************************************************************************/
static void OUT_v_CustomRelevanceYLane(void)
{
  sint32 iObj;
  float32 fTemp;
  eAssociatedLane_t t_ObjFuncLane;

  /* loop over object list */
  for (iObj = 0L; iObj < EM_N_OBJECTS; iObj++)
  {
    /* object is valid for customer relevance */
    if (LA_SUFFICIENT_FUN_PRESEL_QUALITY(iObj) == TRUE)
    {
      t_ObjFuncLane = pt_OUTInput->t_LAInput.pt_LAObjectList(iObj)->ObjFuncLane;

      /* object is inside ego lane or set as relevant by occupied lane */
      if ((t_ObjFuncLane == ASSOC_LANE_EGO) || (SLATE_b_GetObjIsRelevant(iObj)))
      {
        fTemp = OOIRelevanceParameter.CustomRelevanceY.fLaneInCut0 * OUT_RELEVANCE_SCALE;
        OUT_OBJ_RELEVANCE_Y(iObj) = (uint8)(fTemp);
      }
      /* object is outside ego lane */
      else
      {
        fTemp = OOIRelevanceParameter.CustomRelevanceY.fLaneOutCut0 * OUT_RELEVANCE_SCALE;
        OUT_OBJ_RELEVANCE_Y(iObj) = (uint8)(fTemp);
      }
    }
    /* object is invalid for customer relevance */
    else
    {
      /* reset relevance value for all invalid objects */
      fTemp = OOIRelevanceParameter.CustomRelevanceY.fMin * OUT_RELEVANCE_SCALE;
      OUT_OBJ_RELEVANCE_Y(iObj) = (uint8)(fTemp);
    }
  }
}
#endif  /* (OUT_CFG_CUSTOM_XY_RELEVANCE) */

#if (OUT_CFG_CUSTOM_XY_RELEVANCE)
/*************************************************************************************************************************
  Functionname:    OUT_v_CustomRelevanceYCutInOut                                                                       */ /*!

  @brief           Calculates lateral (Y) relevance depending on cut-in/out potential

  @description     Lateral relevance by Cut-in/out potential:
                   - relevance for objects inside ego lane 
                     must be > OUT_CUSTOM_REL_Y_THRESHOLD
                   - relevance for objects not inside ego lane
                     must be <= OUT_CUSTOM_REL_Y_THRESHOLD

                   OOIRelevanceParameter.CustomRelevanceY.fLaneInCut0
                   - relevance for object inside ego lane with cut-out potential = 0%
                   - identical to relevance when not using cut-in/out potential
                     (for objects inside ego lane)

                   OOIRelevanceParameter.CustomRelevanceY.fLaneInCut100
                   - relevance for object inside ego lane with cut-out potential = 100%

                   OOIRelevanceParameter.CustomRelevanceY.fLaneInCut50
                   - relevance for object inside ego lane with 0% < cut-out potential < 100%
                   - relevance = fLaneInCut50 - (fLaneInCut50 - fLaneInCut100) * cut-in potential

                   OOIRelevanceParameter.CustomRelevanceY.fLaneOutCut0
                   - relevance for object not inside ego lane with cut-in potential = 0%
                   - identical to relevance when not using cut-in/out potential
                     (for objects not inside ego lane)

                   OOIRelevanceParameter.CustomRelevanceY.fLaneOutCut100
                   - relevance for object not inside ego lane with cut-in potential = 100%

                   OOIRelevanceParameter.CustomRelevanceY.fLaneOutCut50
                   - relevance for object not inside ego lane with 0% < cut-in potential < 100%
                   - relevance = fLaneInCut50 + (fLaneInCut100 - fLaneInCut50) * cut-in potential

                   Examples (with default parameters):
                   - object is inside ego lane
                       cut-out potential = 0% -> lateral relevance = 1.0
                       cut-out potential = 100% -> lateral relevance = 0.6
                       cut-out potential = 50% -> lateral relevance = 0.8 - (0.8 - 0.6) * 50% = 0.7
                   - object is not inside ego lane
                       cut-in potential = 0% -> lateral relevance = 0.1
                       cut-in potential = 100% -> lateral relevance = 0.5
                       cut-in potential = 50% -> lateral relevance = 0.3 + (0.5 - 0.3) * 50% = 0.4

  @return          -

  @param[in]       -
  @param[out]      -

  @glob_in         LA_SUFFICIENT_FUN_PRESEL_QUALITY(i) : Boolean if object fulfills the ACC pre-selection                        [TRUE, FALSE]
                                                         with i in [0u ... EM_N_OBJECTS-1]
  @glob_in         OBJ_GET_FUNC_LANE(i) : Functional lane association of an object i                                             [Full range of datatype eAssociatedLane_t as defined in Rte_Type.h] 
                                          with i in [0u ... EM_N_OBJECTS-1]
  @glob_in         OBJ_GET_CUT_OUT_POTENTIAL(i) : Cut out potential of object i                                                  [0u ... 100u]
                                                  with i in [0u ... EM_N_OBJECTS-1]
  @glob_in         OOIRelevanceParameter.
                      CustomRelevanceY.fLaneInCut0 : lateral relevance for objects in ego lane with 0% cut out potential         [-PI/2*RW_FCT_MAX ... PI/2*RW_FCT_MAX] m
                      CustomRelevanceY.fLaneInCut100 : lateral relevance for objects in ego lane with 100% cut out potential     [-PI/2*RW_FCT_MAX ... PI/2*RW_FCT_MAX] m
                      CustomRelevanceY.fLaneInCut50 : lateral relevance for objects in ego lane with 50% cut out potential       [-PI/2*RW_FCT_MAX ... PI/2*RW_FCT_MAX] m
                      CustomRelevanceY.fLaneOutCut0 : lateral relevance for objects not in ego lane with 0% cut in potential     [-PI/2*RW_FCT_MAX ... PI/2*RW_FCT_MAX] m
                      CustomRelevanceY.fLaneOutCut100 : lateral relevance for objects not in ego lane with 100% cut in potential [-PI/2*RW_FCT_MAX ... PI/2*RW_FCT_MAX] m
                      CustomRelevanceY.fLaneOutCut50 : lateral relevance for objects not in ego lane with 50% cut in potential   [-PI/2*RW_FCT_MAX ... PI/2*RW_FCT_MAX] m
                      CustomRelevanceY.fMin : minimum longitudinal relevance                                                     [-5*RW_FCT_MAX ... 5*RW_FCT_MAX] m
  @glob_in         OBJ_GET_CUT_IN_POTENTIAL(i) : Cut in potential of object i                                                    [0u ... 100u]
                                                 with i in [0u ... EM_N_OBJECTS-1]
  @glob_in         pt_OUTInput->t_RTE.pt_ObjClassification(i) : Object class of object i                                         [Full range of datatype SLATE_t_Obj_CLassification defined in Rte_Type.h]
                                                                with i in [0u ... EM_N_OBJECTS-1]
  @glob_in         TPObject[i].OT.fPedestrianProbability : Probability threshold for pedestrians                                 
                                                           with i in [0u ... EM_N_OBJECTS-1]                     
  @glob_out        OUT_OBJ_RELEVANCE_Y(i) : Y-relevance of object i [0u ... 1u] with i in [0u ... EM_N_OBJECTS-1]

  @c_switch_part   -
  @c_switch_full   FCT_CFG_ACC_OUTPUT : Configuration switch to configure OUT (Output) sub-component for FCT_ACC
  @c_switch_full   OUT_CFG_CUSTOM_XY_RELEVANCE : Configuration switch for activating the calculation of the x-relevance and y-relevance of an object

  @pre             -
  @post            -

  @created         -
  @changed         20.04.2016

  @author          Carsten Schmitz
*************************************************************************************************************************/
static void OUT_v_CustomRelevanceYCutInOut(void)
{
  sint32 iObj;
  uint8 ObjRelevance;
  float32 fTemp;
  eAssociatedLane_t t_ObjFuncLane;

  /* loop over object list */
  for (iObj = 0L; iObj < EM_N_OBJECTS; iObj++)
  {
    /* object is valid for customer relevance */
    if (LA_SUFFICIENT_FUN_PRESEL_QUALITY(iObj) == TRUE)
    {
      t_ObjFuncLane = pt_OUTInput->t_LAInput.pt_LAObjectList(iObj)->ObjFuncLane;

      /* object is inside ego lane */
      if ((t_ObjFuncLane == ASSOC_LANE_EGO)|| (SLATE_b_GetObjIsRelevant(iObj)))
      {
        if (OBJ_GET_CUT_OUT_POTENTIAL(iObj) == 0u)
        {
          fTemp = OOIRelevanceParameter.CustomRelevanceY.fLaneInCut0 * OUT_RELEVANCE_SCALE;
          ObjRelevance = (uint8)(fTemp);
        }
        else if (OBJ_GET_CUT_OUT_POTENTIAL(iObj) == 100u)
        {
          fTemp = OOIRelevanceParameter.CustomRelevanceY.fLaneInCut100 * OUT_RELEVANCE_SCALE;
          ObjRelevance = (uint8)(fTemp);
        }
        else
        {
          fTemp = (OOIRelevanceParameter.CustomRelevanceY.fLaneInCut50 - ((OOIRelevanceParameter.CustomRelevanceY.fLaneInCut50-OOIRelevanceParameter.CustomRelevanceY.fLaneInCut100) * (((float32)OBJ_GET_CUT_OUT_POTENTIAL(iObj))*(1.0F/100.0F))))* OUT_RELEVANCE_SCALE;
          ObjRelevance = (uint8)(fTemp);
        }
      }
      /* object is outside ego lane */
      else
      {
        if (*SIT_pu_GetCutInProbability(iObj) == 0u)
        {
          fTemp = OOIRelevanceParameter.CustomRelevanceY.fLaneOutCut0 * OUT_RELEVANCE_SCALE;
          ObjRelevance = (uint8)(fTemp);
        }
        else if (*SIT_pu_GetCutInProbability(iObj) >= 100u)
        {
          fTemp = OOIRelevanceParameter.CustomRelevanceY.fLaneOutCut100 * OUT_RELEVANCE_SCALE;
          ObjRelevance = (uint8)(fTemp);
        }
        else
        {
          fTemp = (OOIRelevanceParameter.CustomRelevanceY.fLaneOutCut50 + ((OOIRelevanceParameter.CustomRelevanceY.fLaneOutCut100-OOIRelevanceParameter.CustomRelevanceY.fLaneOutCut50) * (((float32)*SIT_pu_GetCutInProbability(iObj))/100.0F)))* OUT_RELEVANCE_SCALE;
          ObjRelevance = (uint8)(fTemp);
        }
      }
    }
    /* object is invalid for customer relevance */
    else
    {
      if
        (
         (*pt_OUTInput->t_RTE.pt_ObjClassification(iObj) == SLATE_OBJCLASS_PEDESTRIAN)


#pragma message(__FILE__"("STRING_QUOTE(__LINE__)"): TODO: Check Probability threshold for pedestrians")
#if 0
         ||
         (TPObject[i].OT.fPedestrianProbability > OT_PED_PROBABILITY_THRESHOLD)
#endif
        )
      {
        fTemp = 0.42F * OUT_RELEVANCE_SCALE;
        ObjRelevance = (uint8)(fTemp);
        /*OOIRelevanceParameter.CustomRelevanceY.fMin;*/
      }
      else
      {
        /* reset relevance value for all invalid objects */
        fTemp = OOIRelevanceParameter.CustomRelevanceY.fMin *OUT_RELEVANCE_SCALE;
        ObjRelevance = (uint8)(fTemp);
      }
    }
    /* Store the calculated Y relevance value in out output */
    OUT_OBJ_RELEVANCE_Y(iObj) = ObjRelevance;
  }
}
#endif  /* (OUT_CFG_CUSTOM_XY_RELEVANCE) */

#if (OUT_CFG_CUSTOM_XY_RELEVANCE)
/*************************************************************************************************************************
  Functionname:    OUT_v_CustomRelevanceY                                                                               */ /*!

  @brief           Calculates lateral (Y) relevance for each object

  @description     Lateral relevance is calculated:
                   - relevance depending on cut-in/cut-out potential
                   - relevance depending on lane occupancy

  @return          -

  @param[in]       -
  @param[out]      -

  @glob_in         OOIRelevanceParameter.CustomRelevanceY.bUseCutPotential : cut-in/out potential for lateral relevance, Boolean [TRUE, FAlSE]
  @glob_out        -

  @c_switch_part   -
  @c_switch_full   FCT_CFG_ACC_OUTPUT          : Configuration switch to configure OUT (Output) sub-component for FCT_ACC
  @c_switch_full   OUT_CFG_CUSTOM_XY_RELEVANCE : Configuration switch for activating the calculation of the x-relevance and y-relevance of an object

  @pre             -
  @post            -

  @created         -
  @changed         20.04.2016

  @author          Marie-Theres Boll | marie-theres.boll@continental-corporation.com | +49 (8382) 9699-632
*************************************************************************************************************************/
static void OUT_v_CustomRelevanceY(void)
{
  if (OOIRelevanceParameter.CustomRelevanceY.bUseCutPotential == TRUE)
  {
    /* relevance depending on cut-in/cut-out potential */
    OUT_v_CustomRelevanceYCutInOut();
  }
  else
  {
    /* relevance depending on lane occupancy */
    OUT_v_CustomRelevanceYLane();
  }
}
#endif  /* (OUT_CFG_CUSTOM_XY_RELEVANCE) */

#if (FCT_CFG_SEN2TJA_ACC_OOI_PORT)
/*************************************************************************************************************************
  Functionname:    OUT_v_CustomFillSEN2TJAOOI                                                                       */ /*!

  @brief           Fill out provide port OOI-0 to TJA when the operation mode is OK

  @description     Fill out provide port OOI-0 to TJA when the operation mode is OK

                    @startuml
                        Start
                            Partition OUT_v_CustomFillSEN2TJAOOI {
                                If(Object is detected) then (True)
                                    -update the Object TJA attribute 
                                Else(False)
                                    -Reset the Object TJA attribute 
                                endif
                            }
                        End
                    @enduml

  @return          void

  @param[in]       void : 

  @glob_in         None 
  @glob_out        pSLATE_TJAOOIData : Reference to Provide port where OOI-0 is sent out to TJA

  @c_switch_part   None 
  @c_switch_full   FCT_CFG_SEN2TJA_ACC_OOI_PORT : Switch for enabling Provide Port to TJA

  @pre             None 
  @post            No changes 

  @created         17.10.2017
  @changed         17.10.2017

  @author          Harsha Umesh Babu | harsha.umesh.babu@continental-corporation.com | +49 (8382) 9699-474
*************************************************************************************************************************/
static void OUT_v_CustomFillSEN2TJAOOI(void)
{
  ObjNumber_t ObjNr_OBJ_NEXT_OOI;     

#if (FCT_TJA_TARGET_OBJ_INTFVER == 1u)
  TJATargetObj_t * pt_SLATE_TJAOOIDataLocal = pSLATE_TJAOOIData;
#elif (FCT_TJA_TARGET_OBJ_INTFVER >= 2u)
  TJAObjGen_t * pt_SLATE_TJAOOIDataLocal  = &(pSLATE_TJAOOIData->TJAObjGen);
#endif /* (FCT_TJA_TARGET_OBJ_INTFVER == 1u) */

  /* Initialize SEN2TJA OOI provide ports */
  pSLATE_TJAOOIData->sSigHeader.uiTimeStamp          = SLATE_p_GetEMGenObjList()->sSigHeader.uiTimeStamp;
  pSLATE_TJAOOIData->sSigHeader.uiMeasurementCounter = SLATE_p_GetEMGenObjList()->sSigHeader.uiMeasurementCounter;
  pSLATE_TJAOOIData->sSigHeader.uiCycleCounter       = FCTSenFrame.uiCycleCounter;
  pSLATE_TJAOOIData->sSigHeader.eSigStatus           = AL_SIG_STATE_OK;
  pSLATE_TJAOOIData->uiVersionNumber                 = FCT_TJA_TARGET_OBJ_INTFVER;

  ObjNr_OBJ_NEXT_OOI = SLATE_i_GetOOIObjIndex(OBJ_NEXT_OOI);  // Replace with SLATE_i_GetOOIObjIndex()
  if (ObjNr_OBJ_NEXT_OOI > OBJ_INDEX_NO_OBJECT)
  {
    pt_SLATE_TJAOOIDataLocal->SelectedTargetObjDetected_nu   = TJA_TARGET_OBJ_DETECTED;
    
    /* Position and Kinematic Attributes */
    pt_SLATE_TJAOOIDataLocal->MovementRelAclX_mps2           = *(pt_OUTInput->t_RTE.pf_ObjArelX(ObjNr_OBJ_NEXT_OOI));
    pt_SLATE_TJAOOIDataLocal->MovementRelAclY_mps2           = *(pt_OUTInput->t_RTE.pf_ObjArelY(ObjNr_OBJ_NEXT_OOI));
    pt_SLATE_TJAOOIDataLocal->MovementRelVelX_mps            = *(pt_OUTInput->t_RTE.pf_ObjVrelX(ObjNr_OBJ_NEXT_OOI));
    pt_SLATE_TJAOOIDataLocal->MovementRelVelY_mps            = *(pt_OUTInput->t_RTE.pf_ObjVrelY(ObjNr_OBJ_NEXT_OOI));
    pt_SLATE_TJAOOIDataLocal->PositionPosX_m                 = *(pt_OUTInput->t_RTE.pf_ObjLongDisp(ObjNr_OBJ_NEXT_OOI));
    pt_SLATE_TJAOOIDataLocal->PositionPosY_m                 = *(pt_OUTInput->t_RTE.pf_ObjLatDisp(ObjNr_OBJ_NEXT_OOI));
    /* TODO Replace the FCTSen_p_GetEMGenObjKinematics with member specific IO through OUTInput->t_RTE */
    pt_SLATE_TJAOOIDataLocal->PositionPosXStdDev_m           = SLATE_p_GetEMGenObjKinematics(ObjNr_OBJ_NEXT_OOI)->fAabsXStd;
    pt_SLATE_TJAOOIDataLocal->PositionPosYStdDev_m           = SLATE_p_GetEMGenObjKinematics(ObjNr_OBJ_NEXT_OOI)->fAabsYStd;

    /* Object Attributes */
    pt_SLATE_TJAOOIDataLocal->ObjQuality_nu                  = SLATE_u_GetAccQuality(ObjNr_OBJ_NEXT_OOI); //*(FCTSen_pu_GetAccObjQuality(ObjNr_OBJ_NEXT_OOI));
    OUT_v_CustomFillTJAObjectClass(ObjNr_OBJ_NEXT_OOI);
    OUT_v_CustomFillTJAObjectState(ObjNr_OBJ_NEXT_OOI);
    /* TODO Replace the FIP_pt_OA_GetWidth with member specific IO through OUTInput->t_RTE */
    pt_SLATE_TJAOOIDataLocal->DimensionsWidth_m              = FIP_pt_GetObjAttributes()->t_ObjList[ObjNr_OBJ_NEXT_OOI].fWidth;
    pt_SLATE_TJAOOIDataLocal->SensorSource_nu                = SLATE_p_GetEMGenObjGeneral(ObjNr_OBJ_NEXT_OOI)->eSensorSource;

    /* Miscellaneous Attributes */
    pt_SLATE_TJAOOIDataLocal->ObjRecognExtendedQualifier_nu  = (uint8)ObjNr_OBJ_NEXT_OOI;
	
#if (FCT_TJA_TARGET_OBJ_INTFVER >= 2u)
    /* Export ACC Trace Trajectory */
    pSLATE_TJAOOIData->ACCTraceTrajectory.fCurve              = pt_OUTInput->t_CP.pt_TraceTrajectory->fCurve;
    pSLATE_TJAOOIData->ACCTraceTrajectory.fMaxDist            = pt_OUTInput->t_CP.pt_TraceTrajectory->fMaxDist;
    pSLATE_TJAOOIData->ACCTraceTrajectory.fWeight             = pt_OUTInput->t_CP.pt_TraceTrajectory->fWeight;
#endif /* (FCT_TJA_TARGET_OBJ_INTFVER >= 2u) */
  } 
  else
  {
    pt_SLATE_TJAOOIDataLocal->SelectedTargetObjDetected_nu   = TJA_TARGET_OBJ_NOT_DETECTED;   /* TJA Object NOT Detected */

    /* Position and Kinematic Attributes */
    pt_SLATE_TJAOOIDataLocal->MovementRelAclX_mps2           = 0.f;
    pt_SLATE_TJAOOIDataLocal->MovementRelAclY_mps2           = 0.f;
    pt_SLATE_TJAOOIDataLocal->MovementRelVelX_mps            = 0.f;
    pt_SLATE_TJAOOIDataLocal->MovementRelVelY_mps            = 0.f;
    pt_SLATE_TJAOOIDataLocal->PositionPosX_m                 = 0.f;
    pt_SLATE_TJAOOIDataLocal->PositionPosY_m                 = 0.f;
    pt_SLATE_TJAOOIDataLocal->PositionPosXStdDev_m           = 0.f;
    pt_SLATE_TJAOOIDataLocal->PositionPosYStdDev_m           = 0.f;

    /* Object Attributes */
    pt_SLATE_TJAOOIDataLocal->ObjQuality_nu                  = 0u;
    pt_SLATE_TJAOOIDataLocal->ObjRecognClassType_nu          = TJA_EM_GEN_OBJECT_CLASS_UNCLASSIFIED;
    pt_SLATE_TJAOOIDataLocal->ObjRecognMeasState_nu          = TJA_EM_GEN_OBJECT_MT_STATE_INACTIVE;
    pt_SLATE_TJAOOIDataLocal->DimensionsWidth_m              = 0.f;
    pt_SLATE_TJAOOIDataLocal->SensorSource_nu                = TJA_EM_GEN_OBJECT_MS_NONE;

    /* Miscellaneous Attributes */
    pt_SLATE_TJAOOIDataLocal->ObjRecognExtendedQualifier_nu  = TJA_DEFAULT_OBJECT_ID;

#if (FCT_TJA_TARGET_OBJ_INTFVER >= 2u)    
    /* Export ACC Trace Trajectory */
    pSLATE_TJAOOIData->ACCTraceTrajectory.fCurve              = 0.0001f;
    pSLATE_TJAOOIData->ACCTraceTrajectory.fMaxDist            = 0.f;
    pSLATE_TJAOOIData->ACCTraceTrajectory.fWeight             = 1.0f;
#endif /* (FCT_TJA_TARGET_OBJ_INTFVER >= 2u) */
  }

  /* Miscellaneous Attributes */
  pt_SLATE_TJAOOIDataLocal->Tstamp_us                        = SLATE_p_GetEMGenObjList()->sSigHeader.uiTimeStamp;
  
}
#endif  /* (FCT_CFG_SEN2TJA_ACC_OOI_PORT) */

#if (FCT_CFG_SEN2TJA_ACC_OOI_PORT)
/*************************************************************************************************************************
  Functionname:    OUT_v_CustomFillTJAObjectClass                                                                   */ /*!

  @brief           Fill out the object classification for OOI-0 based on the ARS Object Classification

  @description     Fill out the object classification for OOI-0 based on the ARS Object Classification.
                   NOTE: This classification can be different from the GEN Object Classification, which can be accessed 
                   using SLATE_p_GetEMGenObjList(iObj)->Attributes.eClassification

                    @startuml
                        Start
                            Partition OUT_v_CustomFillTJAObjectClass {
                                -Fill out the object classification for OOI-0 based on the ARS Object Classification
                            }
                        End
                    @enduml

  @return          void


  @glob_in         None 
  @glob_out        None 

  @c_switch_part   FCT_USE_EM_ARS_TECH_OBJECT_LIST : Configuration switch that enables ARS-technology specific object list
  @c_switch_full   FCT_CFG_SEN2TJA_ACC_OOI_PORT : Switch for enabling Provide Port to TJA

  @pre             None 
  @post            No changes

  @created         17.10.2017
  @changed         17.10.2017

  @author          Harsha Umesh Babu | harsha.umesh.babu@continental-corporation.com | +49 (8382) 9699-474
*************************************************************************************************************************/
static void OUT_v_CustomFillTJAObjectClass(ObjNumber_t t_ObjNr_OBJ_NEXT_OOI)
{
#if (FCT_TJA_TARGET_OBJ_INTFVER == 1u)
  TJATargetObj_t * pt_SLATE_TJAOOIDataLocal = pSLATE_TJAOOIData;
#elif (FCT_TJA_TARGET_OBJ_INTFVER >= 2u)
  TJAObjGen_t * pt_SLATE_TJAOOIDataLocal  = &(pSLATE_TJAOOIData->TJAObjGen);
#endif 

  /* Get the ARS Object Class */
#if (FCT_USE_EM_ARS_TECH_OBJECT_LIST)
  EM_t_ARS_Classification t_OOI_0_Classification = *(pt_OUTInput->t_RTE.pt_ObjClassification(t_ObjNr_OBJ_NEXT_OOI));
  /* Switch through the ARS Classification and assign the corresponding TJA Classification */
  switch(t_OOI_0_Classification)
  {
  case ARS_OBJCLASS_POINT:
    pt_SLATE_TJAOOIDataLocal->ObjRecognClassType_nu = TJA_EM_GEN_OBJECT_CLASS_POINT;
    break;
  case ARS_OBJCLASS_CAR:
    pt_SLATE_TJAOOIDataLocal->ObjRecognClassType_nu = TJA_EM_GEN_OBJECT_CLASS_CAR;
    break;
  case ARS_OBJCLASS_TRUCK:
    pt_SLATE_TJAOOIDataLocal->ObjRecognClassType_nu = TJA_EM_GEN_OBJECT_CLASS_TRUCK;
    break;
  case ARS_OBJCLASS_PEDESTRIAN:
    pt_SLATE_TJAOOIDataLocal->ObjRecognClassType_nu = TJA_EM_GEN_OBJECT_CLASS_PEDESTRIAN;
    break;
  case ARS_OBJCLASS_MOTORCYCLE:
    pt_SLATE_TJAOOIDataLocal->ObjRecognClassType_nu = TJA_EM_GEN_OBJECT_CLASS_MOTORCYCLE;
    break;
  case ARS_OBJCLASS_BICYCLE:
    pt_SLATE_TJAOOIDataLocal->ObjRecognClassType_nu = TJA_EM_GEN_OBJECT_CLASS_BICYCLE;
    break;
  case ARS_OBJCLASS_WIDE:
    pt_SLATE_TJAOOIDataLocal->ObjRecognClassType_nu = TJA_EM_GEN_OBJECT_CLASS_WIDE;
    break;
  case ARS_OBJCLASS_UNCLASSIFIED:
  default:
    pt_SLATE_TJAOOIDataLocal->ObjRecognClassType_nu = TJA_EM_GEN_OBJECT_CLASS_UNCLASSIFIED;
    break;
  }
#else
  /* In case GEN Object classification has to be used, a switch case similar to the one above,
     will have to be implemented here within the #else part */
  pSLATE_TJAOOIData->ObjRecognClassType__nu = TJA_EM_GEN_OBJECT_CLASS_UNCLASSIFIED;
#endif  /* FCT_USE_EM_ARS_TECH_OBJECT_LIST */
}
#endif  /* END IF FCT_CFG_SEN2TJA_ACC_OOI_PORT */

#if (FCT_CFG_SEN2TJA_ACC_OOI_PORT)
/*************************************************************************************************************************
  Functionname:    OUT_v_CustomFillTJAObjectState                                                                   */ /*!

  @brief           Fill out the object Maintenance State for OOI-0 based on the GEN Object Maintenance State

  @description     Fill out the object Maintenance State for OOI-0 based on the GEN Object Maintenance State

                    @startuml
                        Start
                            Partition OUT_v_CustomFillTJAObjectState {
                                -Fill out the object Maintenance State for OOI-0 based on the GEN Object Maintenance State
                            }
                        End
                    @enduml

  @return          void


  @glob_in         None 
  @glob_out        None 

  @c_switch_part   None 
  @c_switch_full   FCT_CFG_SEN2TJA_ACC_OOI_PORT : Switch for enabling Provide Port to TJA

  @pre             None
  @post            No changes

  @created         17.10.2017
  @changed         17.10.2017

  @author          Harsha Umesh Babu | harsha.umesh.babu@continental-corporation.com | +49 (8382) 9699-474
*************************************************************************************************************************/
static void OUT_v_CustomFillTJAObjectState(ObjNumber_t t_ObjNr_OBJ_NEXT_OOI)
{
#if (FCT_TJA_TARGET_OBJ_INTFVER == 1u)
  TJATargetObj_t * pt_SLATE_TJAOOIDataLocal = pSLATE_TJAOOIData;
#elif (FCT_TJA_TARGET_OBJ_INTFVER >= 2u)
  TJAObjGen_t * pt_SLATE_TJAOOIDataLocal  = &(pSLATE_TJAOOIData->TJAObjGen);
#endif /* (FCT_TJA_TARGET_OBJ_INTFVER == 1u) */

  /* Get the Maintenance State  */
  EM_t_GenObjMaintenanceState t_Obj_MaintenanceState = *(SLATE_pt_GetObjMaintenanceState(t_ObjNr_OBJ_NEXT_OOI));	//*(FCTSen_pt_GetObjMaintenanceState(t_ObjNr_OBJ_NEXT_OOI));
  _PARAM_UNUSED(t_ObjNr_OBJ_NEXT_OOI);

  /* Switch through the Maintenance States and assign the corresponding TJA Maintenance States */
  switch (t_Obj_MaintenanceState)
  {
  case EM_GEN_OBJECT_MT_STATE_DELETED:
    pt_SLATE_TJAOOIDataLocal->ObjRecognMeasState_nu          = TJA_EM_GEN_OBJECT_MT_STATE_DELETED;
    break;
  case EM_GEN_OBJECT_MT_STATE_NEW:
    pt_SLATE_TJAOOIDataLocal->ObjRecognMeasState_nu          = TJA_EM_GEN_OBJECT_MT_STATE_NEW;
    break;
  case EM_GEN_OBJECT_MT_STATE_MEASURED:
    pt_SLATE_TJAOOIDataLocal->ObjRecognMeasState_nu          = TJA_EM_GEN_OBJECT_MT_STATE_MEASURED;
    break;
  case EM_GEN_OBJECT_MT_STATE_PREDICTED:
    pt_SLATE_TJAOOIDataLocal->ObjRecognMeasState_nu          = TJA_EM_GEN_OBJECT_MT_STATE_PREDICTED;
    break;
  case EM_GEN_OBJECT_MT_STATE_MAX_DIFF_TYPES:
    pt_SLATE_TJAOOIDataLocal->ObjRecognMeasState_nu          = TJA_EM_GEN_OBJECT_MT_STATE_MAX_DIFF_TYPES;
    break;
  case EM_GEN_OBJECT_MT_STATE_INACTIVE:
  default:
    pt_SLATE_TJAOOIDataLocal->ObjRecognMeasState_nu          = TJA_EM_GEN_OBJECT_MT_STATE_INACTIVE;
    break;
  }
}
#endif /* END IF (FCT_CFG_SEN2TJA_ACC_OOI_PORT) */


#if (FCT_CFG_SEN2TJA_ACC_OOI_PORT)
/*************************************************************************************************************************
  Functionname:    OUT_v_CustomInitSEN2TJAOOI                                                                       */ /*!

  @brief           Initialize provide port OOI-0 to TJA when the operation mode is INIT or SHUTDOWN

  @description     Initialize provide port OOI-0 to TJA when the operation mode is INIT or SHUTDOWN

                    @startuml
                        Start
                            Partition OUT_v_CustomInitSEN2TJAOOI {
                                -Initialize provide port OOI-0 to TJA when the operation mode is INIT or SHUTDOWN
                            }
                        End
                    @enduml

  @return          void

  @param[in]       void : 

  @glob_in         None 
  @glob_out        pSLATE_TJAOOIData : Reference to Provide port where OOI-0 is sent out to TJA

  @c_switch_part   None 
  @c_switch_full   FCT_CFG_SEN2TJA_ACC_OOI_PORT : Switch for enabling Provide Port to TJA

  @pre             None 
  @post            No changes 

  @created         17.10.2017
  @changed         17.10.2017

  @author          Harsha Umesh Babu | harsha.umesh.babu@continental-corporation.com | +49 (8382) 9699-474
*************************************************************************************************************************/
static void OUT_v_CustomInitSEN2TJAOOI(void)
{
#if (FCT_TJA_TARGET_OBJ_INTFVER == 1u)
  TJATargetObj_t * pt_SLATE_TJAOOIDataLocal = pSLATE_TJAOOIData;
#elif (FCT_TJA_TARGET_OBJ_INTFVER >= 2u)
  TJAObjGen_t * pt_SLATE_TJAOOIDataLocal  = &(pSLATE_TJAOOIData->TJAObjGen);
#endif /* (FCT_TJA_TARGET_OBJ_INTFVER == 1u) */

  /* Initialize SEN2TJA OOI provide ports */
  pSLATE_TJAOOIData->sSigHeader.uiTimeStamp          = SLATE_p_GetEMGenObjList()->sSigHeader.uiTimeStamp;
  pSLATE_TJAOOIData->sSigHeader.uiMeasurementCounter = SLATE_p_GetEMGenObjList()->sSigHeader.uiMeasurementCounter;
  pSLATE_TJAOOIData->sSigHeader.uiCycleCounter       = FCTSenFrame.uiCycleCounter;
  pSLATE_TJAOOIData->sSigHeader.eSigStatus           = ((OUT_t_State == COMP_STATE_NOT_INITIALIZED)?AL_SIG_STATE_INIT:AL_SIG_STATE_INVALID);
  pSLATE_TJAOOIData->uiVersionNumber                 = FCT_TJA_TARGET_OBJ_INTFVER;

  pt_SLATE_TJAOOIDataLocal->SelectedTargetObjDetected_nu   = TJA_TARGET_OBJ_NOT_DETECTED;   /* TJA Object NOT Detected */
  
  /* Position and Kinematic Attributes */
  pt_SLATE_TJAOOIDataLocal->MovementRelAclX_mps2           = 0.f;
  pt_SLATE_TJAOOIDataLocal->MovementRelAclY_mps2           = 0.f;
  pt_SLATE_TJAOOIDataLocal->MovementRelVelX_mps            = 0.f;
  pt_SLATE_TJAOOIDataLocal->MovementRelVelY_mps            = 0.f;
  pt_SLATE_TJAOOIDataLocal->PositionPosX_m                 = 0.f;
  pt_SLATE_TJAOOIDataLocal->PositionPosY_m                 = 0.f;
  pt_SLATE_TJAOOIDataLocal->PositionPosXStdDev_m           = 0.f;
  pt_SLATE_TJAOOIDataLocal->PositionPosYStdDev_m           = 0.f;

  /* Object Attributes */
  pt_SLATE_TJAOOIDataLocal->ObjQuality_nu                  = 0u;
  pt_SLATE_TJAOOIDataLocal->ObjRecognClassType_nu          = TJA_EM_GEN_OBJECT_CLASS_UNCLASSIFIED;
  pt_SLATE_TJAOOIDataLocal->ObjRecognMeasState_nu          = TJA_EM_GEN_OBJECT_MT_STATE_INACTIVE;
  pt_SLATE_TJAOOIDataLocal->DimensionsWidth_m              = 0.f;
  pt_SLATE_TJAOOIDataLocal->SensorSource_nu                = TJA_EM_GEN_OBJECT_MS_NONE;

#if (FCT_TJA_TARGET_OBJ_INTFVER >= 2u)    
  /* Export ACC Trace Trajectory */
  pSLATE_TJAOOIData->ACCTraceTrajectory.fCurve              = 0.0001f;
  pSLATE_TJAOOIData->ACCTraceTrajectory.fMaxDist            = 0.f;
  pSLATE_TJAOOIData->ACCTraceTrajectory.fWeight             = 1.0f;
#endif /* (FCT_TJA_TARGET_OBJ_INTFVER >= 2u)   */

  /* Miscellaneous Attributes */
  pt_SLATE_TJAOOIDataLocal->Tstamp_us                      = SLATE_p_GetEMGenObjList()->sSigHeader.uiTimeStamp;
  pt_SLATE_TJAOOIDataLocal->ObjRecognExtendedQualifier_nu  = TJA_DEFAULT_OBJECT_ID;
}
#endif  /* (FCT_CFG_SEN2TJA_ACC_OOI_PORT) */
/** @} end defgroup */
#endif /*!< FCT_CFG_ACC_OUTPUT */

