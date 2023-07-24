/*! \file **********************************************************************

COMPANY:                   COPYRIGHT (C) Continental AG

PROJECT:                   Adaptive Cruise Control (ACC)

CPU:                       CPU-Independent

COMPONENT:                 SLATE_SIT (Situation)

PACKAGENAME:               sit.h

DESCRIPTION:               Internal header file for ACC Situation (SIT) module

AUTHOR:                    Boll Marie-Theres (uidu1091)

CREATION DATE:             17.06.2016

VERSION:                   $Revision: 1.19 $

LEGACY VERSION:            Revision: 2.0.1.1

**************************************************************************** */
#ifndef SIT_H_INCLUDED
#define SIT_H_INCLUDED

/*****************************************************************************
  INCLUDES
*****************************************************************************/

#include "slate.h"
#if (FCT_CFG_ACC_SITUATION)
/*****************************************************************************
  MODULE DESCRIPTION
*****************************************************************************/
/**
@addtogroup sit
@{ */
#include "sit_par.h"

#ifdef __cplusplus
extern "C" {
#endif

/*****************************************************************************
  SYMOBLIC CONSTANTS (COMPONENT INTERNAL SCOPE)
*****************************************************************************/
/* Default value for the distance of the ego front to object in blocked path scenario*/
#define SIT_PATH_OCCUPATION_LENGTH_TRAJEGO_FRONT_TO_OBJECT     (250.0f) 
/*****************************************************************************
  MACROS (COMPONENT INTERNAL SCOPE)
*****************************************************************************/


/*****************************************************************************
  TYPEDEFS (COMPONENT INTERNAL SCOPE)
*****************************************************************************/
/* cutin potential debug data */
#ifdef FCT_SIMU
#if (SIT_CUTINPOTENTIAL_MULTIOBJECTANALYSE)

  typedef struct {
    float32 fUsedPredTime;      /*!< Used prediction time */
    float32 fCorrDist;          /*!< Variance corrected distance from course */
    float32 fCorrRelVel;        /*!< Variance corrected relative speed to course */
    float32 fPotential;         /*!< The calculated potential */
    float32 fHiPotLine;         /*!< High potential line */
    float32 fLowPotLine;        /*!< Low potential line */
    float32 fPredictedLatDispl; 
    float32 CurveScale;
    float32 fCrossingDist;
    float32 fCrossingScale;
    float32 fTGScale;
    boolean BeamShift;         /*!< Beam shift */
  } SITCutInPotLatKinDebug_t;

  typedef struct {
    float32 fPotential;         /*!< The calculated potential */
    float32 obj2ahead_il;
    float32 obj2ego_il;
    float32 ramp_il;
    float32 delta_dis; 
    float32 delta_vel; 
    float32 delta_acc; 
    float32 ttc_obj_ahead;
    uint8   ttc_case;
    float32 ramp_ttc_e2o;
    uint8   ramp_ttc_e2o_case;
    float32 ramp_relvel;
    float32 ramp_offsetlat;
    uint8 ahead_veh; 
  } SITCutInPotMultiObjAnalyseDebug_t;

  /*! Structure describing the potential calculation extra debug data per object */
  typedef struct {
    float32 ttc_ego_obj;
    float32 tg_ego_obj;
    float32 fDistY;
    float32 fDistX;               /*!< Distance to object (roughly X distance with curvature) */
    float32 fRelVelX;             /*!< Object relative velocity X */
    float32 fDistFromCourse;      /*!< Distance object to course */
    float32 fDistFromCourseVar;   /*!< Distance object to course variance */
    float32 fRelVelocityTraj;     /*!< Object velocity relative to course */
    float32 fRelVelocityTrajVar;  /*!< Object velocity relative to course variance */
    SITCutInPotLatKinDebug_t LatKinPot;        /*!< data from lateral kinematics analyse */
    SITCutInPotMultiObjAnalyseDebug_t MultiObjAnalysePot;  /*!< data from multi object analyse */
    ObjNumber_t ObjID;
    ObjNumber_t nextLongObjID;
    boolean plausible_lateral_position;
    uint8   CutinObjClass;
  } SITPotentialObjDebugData_t;

  /*! Structure describing the potential calculation extra data for relevant objects */
  typedef struct {
    SITPotentialObjDebugData_t Objects[EM_N_OBJECTS];
  } SITPotentialDebugData_t;
#endif /*(SIT_CUTINPOTENTIAL_MULTIOBJECTANALYSE)*/
#endif  /* FCT_SIMU */
/*****************************************************************************
  CONSTANTS (COMPONENT INTERNAL SCOPE)
*****************************************************************************/
#ifdef FCT_SIMU
#define SIT_POTENTIAL_DEBUG_DATA_VADDR     0x70100000uL
#endif

#define SIT_CUT_IN_OUT_POT_MIN       (0.0f)
#define SIT_CUT_IN_OUT_POT_MAX       (100.0f)
#define SIT_CUT_IN_OUT_DIST_IN_OUT_LAP_LOWER    0.0f
#define SIT_CUT_IN_OUT_DIST_IN_OUT_LAP_UPPER    (LA_PRED_DIST_INIT_HIGH)

/* weight defining 0% potential line dependent on LA_f_GetPredTimeThreshold */
/* the 100 potential line is defined in LA in the function LA_f_GetPredTimeThreshold */
#if SIT_CUTIN_POT_LIMIT
#define SIT_POT_PRED_TIME_FAC         (3.f)
#define SIT_POT_HIGH_PRED_LIMIT       (2.f)
#else
#define SIT_POT_PRED_TIME_FAC         (2.f)
#endif
#if (SLATE_CFG_CAMERA_TURN_INDICATOR_USAGE)
#define SIT_POT_PRED_TIME_FAC_TURNIND (3.f)
#endif

/*****************************************************************************
  VARIABLES (COMPONENT INTERNAL SCOPE)
*****************************************************************************/
/*! External declaration of component internal pointer to SIT Input structure for global access within SIT */
extern MEMSEC_REF SITInputConst_t * pt_SITInput;

extern MEMSEC_REF SITInputModify_t * pt_SITInputModify;

/*! External declaration of SIT output structure whose content is filled in this component*/
extern MEMSEC_REF SITOutput_t * pt_SITOutput;

/*****************************************************************************
  FUNCTION PROTOTYPES (COMPONENT INTERNAL SCOPE)
*****************************************************************************/

/*--- sit_main.c ---*/
//extern void SIT_v_MeasCallback(void);

/*--- sit_lanechange.c ----*/
extern void SIT_v_InitLaneChange(void);
extern void SIT_v_DetectLaneChange(void);

/*--- sit_objfeatures ----*/
extern void SIT_v_CalcBaseFeatures(void);
extern void SIT_v_CalcObjectFeaturesPre(void);
extern uint8 SIT_u_CutOutPotCalcKinematic(const ObjNumber_t ObjId);
extern uint8 SIT_u_CutOutPotCalcDist(const ObjNumber_t ObjId);
extern uint8 SIT_u_CutOutPotFusion(const ObjNumber_t ObjId, const uint8 u_KinematicCutOutPot, const uint8 u_PotentialDistanceCutInOut);
extern uint8 SIT_u_CutInPotCalcKinematic(const ObjNumber_t ObjId);
extern uint8 SIT_u_CutInPotCalcDist(const ObjNumber_t ObjId);
extern uint8 SIT_u_CutInPotFusion(const ObjNumber_t ObjId, const uint8 u_KinematicCutInPot, const uint8 u_PotentialDistanceCutInOut);

#if (SIT_CUTINPOTENTIAL_MULTIOBJECTANALYSE)
#ifdef FCT_SIMU
extern void SIT_v_CutInDebugDataInit(void);
extern void SIT_v_CutInDebugDataFreeze(void);
#endif
#endif /*(SIT_CUTINPOTENTIAL_MULTIOBJECTANALYSE)*/

#if ((SLATE_CFG_TCI_BASE) && (SLATE_CFG_TCI_FRONT_OBST_DETCD))

extern boolean SIT_b_FrontObstacleFilling(void);
#endif /* END IF (SLATE_CFG_TCI_BASE) && (SLATE_CFG_TCI_FRONT_OBST_DETCD) */

/*--- sit_check_occupied_lane.c ----*/
extern void SIT_v_InitBlockedPath(void);
extern void SIT_v_SelectCorridorObjects(void);
/*--- sit_trafficdensity.c ---*/
#if (SIT_CFG_TRAFFIC_DENSITY)
extern void SIT_v_TrafficProcess(void);
#endif

/*--- sit_traffic_density_objhistcalc.c ---*/
#if (SIT_CFG_TRAFFIC_DENSITY)
extern void SIT_v_TrafficInit(void);
#endif

/*--- sit_traffic_estimation ---*/
#if (SIT_CFG_TRAFFIC_ESTIMATION)
extern void SIT_v_TrafficJamInit(void);
extern void SIT_v_TrafficJamEstimationMain(void);
#endif
#if (SIT_CFG_TRAFFIC_DENSITY)
extern void SIT_v_TrafficEstiInit(void);
extern void SIT_v_TrafficEstiProcess(void);
extern void SIM_v_DrawTrafficDensity(void);
#endif

/*--- sit_o2o.c ---*/
#if (SIT_O2O_ANALYSIS)
extern void SIT_v_O2OAnalysis(void);
#endif

/*--- sit_objscore ---*/
#if (SIT_CFG_OBJECT_SCORING)
extern void SIT_v_CalculateObjectScores(void);
extern void SIT_v_InitObjectScores(void);
#endif


/*--- sit_calc_cutin_pot.c ---*/
extern void SIT_v_CutInObjectDataInit(void);

/*--- sit_calc_cutout_pot.c ---*/

/*--- sit_customfunctions.c ---*/
extern void SIT_v_MergeCustomObjects( ObjNumber_t uiObjectToKeep,ObjNumber_t uiObjectToDelete );


#ifdef __cplusplus
};
#endif
/// @}
#endif  /*!< FCT_CFG_ACC_SITUATION */
/* End of conditional inclusion */
#endif  /*!< _SIT_H_INCLUDED */
