/*! \file **********************************************************************

COMPANY:                   COPYRIGHT (C) Continental AG

PROJECT:                   Adaptive Cruise Control (ACC)

CPU:                       CPU-Independent

COMPONENT:                 SLATE_LA (Lane Association)

PACKAGENAME:               la_corridor_navi.c

DESCRIPTION:               ACC object corridor brackets' adaptation implementation based on Navi information

AUTHOR:                    Norman Apel
                           Gergely Ungvary

CREATION DATE:             15.05.2014

VERSION:                   $Revision: 1.13 $

LEGACY VERSION:            Revision: 2.0

**************************************************************************** */

/*****************************************************************************
  INCLUDES
*****************************************************************************/


#include "la.h"//PRQA S 0380
/* date: 2019-07-28, reviewer:Prabhu Sundaramurthy, reason: Arises due to inclusion of multiple header files in this header file which has multiple macros*/
#if (FCT_CFG_ACC_LANE_ASSOCIATION)
#if ((SLATE_CFG_SIMPLE_NAVI_INTERFACE) && (FCT_CFG_INPUT_PREPROCESSSING))
/*****************************************************************************
  MODULE DESCRIPTION
*****************************************************************************/
/**
@defgroup la_corridor_navi LA Corridor Navi
@ingroup la_corridor
@brief          ACC object corridor brackets' adaptation implementation based on Navi information. \n\n

@{

*/

#include "la_corridor_crit.h"
/*****************************************************************************
  MODULGLOBALE KONSTANTEN
*****************************************************************************/

/*****************************************************************************
  MODULGLOBALE VARIABLEN
*****************************************************************************/

/*! Variables for navi SI meas freeze */
static boolean b_NaviLAExternalSwitchMeas = FALSE;

/*****************************************************************************
  MODULLOKALE SYMBOLISCHE KONSTANTEN
*****************************************************************************/

/*****************************************************************************
  MODULLOKALE MAKROS
*****************************************************************************/

/*****************************************************************************
  MODULLOKALE TYPEN
*****************************************************************************/

/*****************************************************************************
  MODULLOKALE KONSTANTEN
*****************************************************************************/

#if (LA_CFG_NAVI_COUNTRYROAD_EXTENSION)
/*! Country road extension relative to longitudinal distance to object */
SET_MEMSEC_CONST(LA_TRCK_Navi_Countryroad_Ext)
static const GDBLFunction_t LA_TRCK_Navi_Countryroad_Ext = { // PRQA S 3218
/* date: 2015-06-17, reviewer: Rachit Sharma (uidr5426), reason: static local for saving data across function calls */
  LA_NAVI_COUNTRYROAD_EXT_MIN,/*!< A1 */
  LA_NAVI_COUNTRYROAD_EXT_MAX,/*!< A2 */
  /*! (A2-A1)/(E2-E1) */
  ( LA_NAVI_COUNTRYROAD_EXT_MAX - LA_NAVI_COUNTRYROAD_EXT_MIN ) / ( LA_DISTX_NAVI_COUNTRYROAD_EXT_MAX - LA_DISTX_NAVI_COUNTRYROAD_EXT_MIN ),
  /*! A1 - (A2-A1)/(E2-E1) * E1 */
  LA_NAVI_COUNTRYROAD_EXT_MIN
  -( (( LA_NAVI_COUNTRYROAD_EXT_MAX - LA_NAVI_COUNTRYROAD_EXT_MIN ) / ( LA_DISTX_NAVI_COUNTRYROAD_EXT_MAX - LA_DISTX_NAVI_COUNTRYROAD_EXT_MIN ))
  * LA_DISTX_NAVI_COUNTRYROAD_EXT_MIN )
};
#endif

#if (LA_CFG_NAVI_OBJ_CLOSE_TO_EXIT_RESTRICTION)
/*! Factor for restriction when object is close to an exit relative to longitudinal distance to object */
SET_MEMSEC_CONST(LA_TRCK_Navi_Exit_Restic)
static const GDBLFunction_t LA_TRCK_Navi_Exit_Restic = {
  LA_NAVI_EXIT_SCALE_RESTIC_MIN,/*!< A1 */
  LA_NAVI_EXIT_SCALE_RESTIC_MAX,/*!< A2 */
  /*! (A2-A1)/(E2-E1) */
  ( LA_NAVI_EXIT_SCALE_RESTIC_MAX - LA_NAVI_EXIT_SCALE_RESTIC_MIN ) / ( LA_DISTX_NAVI_EXIT_SCALE_RESTIC_MAX - LA_DISTX_NAVI_EXIT_SCALE_RESTIC_MIN ),
  /*! A1 - (A2-A1)/(E2-E1) * E1 */
  LA_NAVI_EXIT_SCALE_RESTIC_MIN
  -( (( LA_NAVI_EXIT_SCALE_RESTIC_MAX - LA_NAVI_EXIT_SCALE_RESTIC_MIN ) / ( LA_DISTX_NAVI_EXIT_SCALE_RESTIC_MAX - LA_DISTX_NAVI_EXIT_SCALE_RESTIC_MIN ))
  * LA_DISTX_NAVI_EXIT_SCALE_RESTIC_MIN )
};
#endif

/*****************************************************************************
  MODULLOKALE TYPEDEFS
*****************************************************************************/

/*****************************************************************************
  MODULLOKALE VARIABLEN
*****************************************************************************/

/*****************************************************************************
  FUNCTION PROTOTYPES
*****************************************************************************/

#if( (LA_CFG_NAVI_OBJ_CLOSE_TO_EXIT_RESTRICTION) || (LA_CFG_NAVI_COUNTRYROAD_EXTENSION) )
static void LA_v_ObjCloseToExit(float32 const fDistObj, boolean * pbCloseToExitLeft, boolean * pbCloseToExitRight);
#if 0
static boolean LA_b_CheckZOOvertakingManoeuvre(void);
#endif
#endif
#if(LA_CFG_NAVI_OBJ_CLOSE_TO_EXIT_RESTRICTION)
static void LA_v_RelTraRestrictionNaviObjCloseToExit(LA_t_RelTraObjInput const *pObjInput, LA_t_BracketOutput *pBracketOut);
#endif
#if (LA_CFG_NAVI_COUNTRYROAD_EXTENSION)
static void LA_v_RelTraExtensionNaviCountryroad(LA_t_RelTraObjInput const *pObjInput, LA_t_BracketOutput *pBracketOut);
#endif

/*************************************************************************************************************************
  Functionname:    LA_v_ExecuteNaviBracketFunctions                                                                    */ /*!

  @brief           Execute navi / cam related bracket functions

  @description     Execute navi / cam related bracket functions

                   @startuml
                   Partition LA_v_ExecuteNaviBracketFunctions{
                   Start 
                   : Initialize Navi External Switch;
                   If (navi country road feature is enabled and\n Navi Fusion Presel bits) then (TRUE)
                   : Update Navi External Switch;
                   Else (FALSE)
                   Endif 
                   If (restriction Navi objects is enabled AND\n Navi External Switch avail) then (TRUE)	
                   : Get trace bracket restriction Navi objects close to exit;
                   Else (FALSE)
                   Endif 
                   : Country road extension based on navi info;
                   : Set navi SI freeze data;
                   End 
                   }
                   @enduml

  @return          Execute navi / cam related bracket functions comprising extensions and
                   restrictions

  @param[in]       pObjectProperties : Object properties                                  [Pointer to structure LA_t_RelTraObjInput defined la_corridor_crit.h]

  @param[in,out]   pBracketFuncResults : Preliminary results of each bracket function     [Pointer to structure LA_t_CriteriaMatrix defined in la_corridor_crit.h]
                    pBracketFuncResults->RestrictionNaviObjCloseToExit                    [srtucture LA_t_BracketOutput defined in la_corridor_crit.h]
                    pBracketFuncResults->ExtensionNaviCountryroad                         [structure LA_t_BracketOutput defined in la_corridor_crit.h]

  @param[in]       pBracketFuncEnableFlags : Switches to enable/disable bracket functions [Pointer to structure LA_t_BracketFuncEnable defined in la_corridor_crit.h]
                    pBracketFuncEnableFlags->bEnableRestrictionNaviObjCloseToExit         [type boolean defined in Platform_Types.h] [TRUE,FALSE]
                    pBracketFuncEnableFlags->bEnableExtensionNaviCountryroad              [type boolean defined in Platform_Types.h] [TRUE,FALSE]

  @glob_in         FCT_BSW_ALGO_PARAM_PTR->Fct.Acc.NaviFusionPreselBits                   [type NaviFusionPreselBits_t defined in Rte_Type.h]
  @glob_out        -

  @c_switch_part   LA_CFG_NAVI_OBJ_CLOSE_TO_EXIT_RESTRICTION    : Configuration switch enabling the trace bracket restriction close to an exit (based on navi information)
  @c_switch_part   LA_CFG_NAVI_COUNTRYROAD_EXTENSION            : Configuration switch enabling the trace bracket extension on country roads (based on navi information)
  @c_switch_part   FCT_CFG_BSW_ALGO_PARAMS                      : Configuration switch enabling the passing of algo parameters to the FCT component

  @c_switch_full   FCT_CFG_ACC_LANE_ASSOCIATION       : FCT switch for ACC LA (Lane Association) sub-component
  @c_switch_full   FCT_CFG_INPUT_PREPROCESSSING       : FCT support for FCT Input Preprocessing (FIP)
  @c_switch_full   SLATE_CFG_SIMPLE_NAVI_INTERFACE  : Configuration switch enabling simple navi input data to FCT_SEN

  @pre             -
  @post            -

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @created         -
  @changed         3/3/2016

  @author          Christopher Knievel
                   Fabian Killus
*************************************************************************************************************************/
void LA_v_ExecuteNaviBracketFunctions(const LA_t_RelTraObjInput * pObjectProperties, LA_t_CriteriaMatrix * pBracketFuncResults, 
                                   const LA_t_BracketFuncEnable * pBracketFuncEnableFlags)
{
  boolean bNaviCRExternalSwitch = FALSE;

#if( (LA_CFG_NAVI_OBJ_CLOSE_TO_EXIT_RESTRICTION) || (LA_CFG_NAVI_COUNTRYROAD_EXTENSION) )
  /*! Check if navi country road feature is enabled using external switch */
#if ((FCT_CFG_BSW_ALGO_PARAMS) && (BSW_ALGOPARAMETERS_INTFVER >= 16u))
  if((FCT_BSW_ALGO_PARAM_PTR->Fct.Acc.NaviFusionPreselBits & ACC_NAV_FUSION_SEL_COUNTRY_ROAD) != 0)
  {
    bNaviCRExternalSwitch = TRUE;
  }
#else
  bNaviCRExternalSwitch = TRUE;
#endif
#endif

  /*********************** RESTRICTIONS ******************************/
  
  /* RestrictionNaviObjCloseToExit */
#if(LA_CFG_NAVI_OBJ_CLOSE_TO_EXIT_RESTRICTION)
  if ((pBracketFuncEnableFlags->bEnableRestrictionNaviObjCloseToExit != LA_CORR_BRACKET_FUNC_DISABLED) &&
      (bNaviCRExternalSwitch == TRUE)
     )
  {
    LA_v_RelTraRestrictionNaviObjCloseToExit(pObjectProperties, &(pBracketFuncResults->RestrictionNaviObjCloseToExit));
  }
#endif
  

  /*********************** EXTENSIONS ******************************/

  /*! Country road extension based on navi info */
#if (LA_CFG_NAVI_COUNTRYROAD_EXTENSION)
  if( (pBracketFuncEnableFlags->bEnableExtensionNaviCountryroad != LA_CORR_BRACKET_FUNC_DISABLED) &&
      (bNaviCRExternalSwitch == TRUE)
    )
  {
    LA_v_RelTraExtensionNaviCountryroad(pObjectProperties, &(pBracketFuncResults->ExtensionNaviCountryroad));
  }
#endif

#if ((LA_CFG_NAVI_COUNTRYROAD_EXTENSION == SWITCH_OFF) && (LA_CFG_NAVI_OBJ_CLOSE_TO_EXIT_RESTRICTION == SWITCH_OFF))
  _PARAM_UNUSED(pBracketFuncEnableFlags);
  _PARAM_UNUSED(pObjectProperties);
  _PARAM_UNUSED(pBracketFuncResults);
#endif

  /*! Set navi SI freeze data */
  b_NaviLAExternalSwitchMeas = bNaviCRExternalSwitch;
}

#if(LA_CFG_NAVI_OBJ_CLOSE_TO_EXIT_RESTRICTION)

/*************************************************************************************************************************
  Functionname:    LA_v_RelTraRestrictionNaviObjCloseToExit                                                            */ /*!

  @brief           Determine the trace bracket restriction if an object is close to an exit identified by the navi

  @description     Restrict the trace brackets if an object is close to an exit identified by the navi

                   @startuml
                   Partition LA_v_RelTraRestrictionNaviObjCloseToExit{
                   Start
                   : Get Seek and Track Lane Width;
                   : Determine if object is close to the next exit;
                   If (object is close to next left or right exit\n AND displacement is lower than a threshold AND\n relative velocity is lower than threshold) then (TRUE)
                   : Get number of lane object based on Navi Info;
                   If (Only one lane) then (TRUE)
                   : Get derivation of the ACC-Trajectory at the distance of the object;
                   : Get orientation of the ACC-Trajectory at the distance of the object;
                   : Get scale factor for restricting the track lane width;
                   : Get Extension and width;
                   If (object is close the exit for left AND\n object is diving in a different direction than the ACC-Trajectory) then (TRUE)
                   : Get Bracket position for left;
                   Else (FALSE)
                   Endif
                   If (object is close the exit for right AND\n object is diving in a different direction than the ACC-Trajectory) then (TRUE)
                   : Get Bracket position for right;
                   Else (FALSE)
                   Endif
                   Else (FALSE)
                   Endif
                   Else (FALSE)
                   Endif
                   End
                   }
                   @enduml

  @return          static void

  @param[in]       *pObjInput : Information about current object    [Pointer to structure LA_t_RelTraObjInput defined in la_corridor_crit.h]
                     pObjInput->iObjNr                              [type ObjNumber_t defined in Rte_Type.h] [0   39]
                     pObjInput->dRelSpurErweiterungsFaktor          [0f   1f]
                     pObjInput->dAblage_Radius                      [-PI/2*RW_FCT_MAX   PI/2*RW_FCT_MAX] m

  @param[out]      *pBracketOut : Trace bracket extension for the current object (absolute values for left and right trace bracket)    [Pointer to structure LA_t_BracketOutput defined in la_corridor_crit.h]
                     pBracketOut->BracketPositionLeft  : Lane/Corridor Bracket in left position                                        [-PI/2*RW_FCT_MAX   PI/2*RW_FCT_MAX] m
                     pBracketOut->BracketPositionRight : Lane/Corridor Bracket in right position                                       [-PI/2*RW_FCT_MAX   PI/2*RW_FCT_MAX] m

  @glob_in         *pt_LAInput->t_RTE.pf_ObjLongDisp  (  )        : Longitudinal displacement of object   [-5*RW_FCT_MAX    5*RW_FCT_MAX] m
  @glob_in         pt_LAInput->t_RTE.pf_ObjVrelX(  )                : Relative velocity of object           [-330f   330f] m/s
  @glob_in         CP_TrajectoryData.Current.fTrajC0 : curvature of trajectory               [-1f   1f] m^-1
  @glob_in         LA_TRCK_Navi_Exit_Restic                                                 [Stactic constant structure of type GDBLFunction_t defined in cml_mapping.h]
  @glob_in         pt_LAInput->t_RTE.pf_ObjOrientation(  )              :orienatation of the object             [-PI   PI] rad
  @glob_in         pt_LAOutput->f_LA_SeekLaneWidth : global seek lane width variable        [-PI/2*RW_FCT_MAX ... PI/2*RW_FCT_MAX] m
  @glob_in         pt_LAOutput->f_LA_TrackLaneWidth : global track lane width variable      [-PI/2*RW_FCT_MAX ... PI/2*RW_FCT_MAX] m

  @glob_out        -

  @c_switch_part   FCT_USE_EM_ARS_TECH_OBJECT_LIST            : FCT switch for EM ARS object list
  @c_switch_full   LA_CFG_NAVI_OBJ_CLOSE_TO_EXIT_RESTRICTION  : Configuration switch enabling the trace bracket restriction close to an exit (based on navi information)
  @c_switch_full   FCT_CFG_ACC_LANE_ASSOCIATION               : FCT switch for ACC LA (Lane Association) sub-component
  @c_switch_full   FCT_CFG_INPUT_PREPROCESSSING               : FCT support for FCT Input Preprocessing (FIP)
  @c_switch_full   SLATE_CFG_SIMPLE_NAVI_INTERFACE          : Configuration switch enabling simple navi input data to FCT_SEN

  @pre             LA_v_CalculateBaseLaneWidths has to be calculated for ptLA_Output->f_LA_SeekLaneWidth and ptLA_Output->f_LA_TrackLaneWidth values
  @post            -

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @created         -
  @changed         3/3/2016

  @author          Marie-Theres Boll
*************************************************************************************************************************/
static void LA_v_RelTraRestrictionNaviObjCloseToExit(LA_t_RelTraObjInput const *pObjInput, LA_t_BracketOutput *pBracketOut)
{
  /*! If the navi path bends (i.e. ego vehicle follows object when turning), don't apply the restriction */
  /*! Restriction is applied only if the object is close to the next exit (exits further away are not considered yet) */

  boolean bCloseToExitLeft, bCloseToExitRight;
  float32 fLASeekLaneWidth = pt_LAOutput->f_LA_SeekLaneWidth;
  float32 fLATrackLaneWidth = pt_LAOutput->f_LA_TrackLaneWidth;

  /*! Determine if object is close to the next exit */
  LA_v_ObjCloseToExit((*pt_LAInput->t_RTE.pf_ObjLongDisp(pObjInput->iObjNr)), &bCloseToExitLeft, &bCloseToExitRight);

  /*! Apply restriction only if the object is close at least to the next left or right exit 
        if displacement is lower than a threshold
        if the relative velocity is lower than a threshold */
  if( ( (bCloseToExitLeft == TRUE) ||
        (bCloseToExitRight == TRUE)
      ) &&
      (*pt_LAInput->t_RTE.pf_ObjLongDisp(pObjInput->iObjNr) < LA_MAX_DISTX_NAVI_EXIT) &&
      (*pt_LAInput->t_RTE.pf_ObjVrelX(pObjInput->iObjNr) < LA_MAX_VREL_NAVI_EXIT)
    )
  {
    uint8 u_NumLaneObj;
    
    /*! Get number of lanes at the distance of the object based on the navi information */
    u_NumLaneObj = (pt_LAInput->pt_FIPNaviData->t_ObjList[pObjInput->iObjNr].u_NumLane);

    /*! Only if one lane (object are driving in the same direction), apply restriction */
    if (u_NumLaneObj == 1u)
    {
      float32 fDivTrajAtObjDist, fOrientTrajObj;
      float32 fTBWidth, fTBExtention, fScaleTBWidth;

      /*! Determine derivation of the ACC-Trajectory at the distance of the object */
      fDivTrajAtObjDist = (CP_TrajectoryData.Current.fTrajC0 * (*pt_LAInput->t_RTE.pf_ObjLongDisp(pObjInput->iObjNr)))+ 
                          (0.5f * CP_TrajectoryData.Current.fTrajC0 * SQR(*pt_LAInput->t_RTE.pf_ObjLongDisp(pObjInput->iObjNr)));
      /*! Determine orientation of the ACC-Trajectory at the distance of the object */
      fOrientTrajObj = ATAN_(fDivTrajAtObjDist);

      /* Determine scale factor (based on the longitudinal distance) for restricting the track lane width */
      fScaleTBWidth = dGDBmathLineareFunktion(&LA_TRCK_Navi_Exit_Restic, *pt_LAInput->t_RTE.pf_ObjLongDisp(pObjInput->iObjNr));

      /*! Determine SIRelTraTrackWidthTrck and consider scale factor fScaleTBWidth */
      fTBExtention = MAX_FLOAT(0.f, MAX_FLOAT(pObjInput->dRelSpurErweiterungsFaktor, pObjInput->dRelSpurAbstandErweitFaktor));
      fTBWidth = ((( fLATrackLaneWidth - fLASeekLaneWidth ) * fTBExtention) + fLASeekLaneWidth ) * 0.5f * fScaleTBWidth;

      /*! Apply restriction only 
            if object is close the exit and
            if object is diving in a different direction than the ACC-Trajectory suggests (indicator that object is turning) 
              based on the difference between the object orientation and the deviation of the ACC-Trajectory */
      if( (bCloseToExitLeft == TRUE) &&
          (pt_LAInput->t_RTE.pf_ObjOrientation(pObjInput->iObjNr) - fOrientTrajObj > LA_MIN_DIFF_ORIENT_OBJ_NAVI_EXIT_RESTIC)
        )
      {
        pBracketOut->BracketPositionLeft = pObjInput->dAblage_Radius + fTBWidth;
      }
      if( (bCloseToExitRight == TRUE) &&
          (pt_LAInput->t_RTE.pf_ObjOrientation(pObjInput->iObjNr) - fOrientTrajObj < -LA_MIN_DIFF_ORIENT_OBJ_NAVI_EXIT_RESTIC)
        )
      {
        pBracketOut->BracketPositionRight = pObjInput->dAblage_Radius - fTBWidth;
      }
    }
  }
}
#endif

#if (LA_CFG_NAVI_COUNTRYROAD_EXTENSION)

/*************************************************************************************************************************
  Functionname:    LA_v_RelTraExtensionNaviCountryroad                                                                 */ /*!

  @brief           Determine the trace bracket extension for the country road based on the navi input

  @description     If the navi identifies "countryroad" for all path segments and if there is no exit identified by the navi,
                   the trace brackets are extended.

				   @startuml
				   Partition LA_v_RelTraExtensionNaviCountryroad{
				   Start
				   : Get relevant Object, Ego Velocity;
				   If (Object is relevant AND Ego velocity less than Max Speed OR relevant Object is Minimal vrel of object) then (TRUE)
				   : Get info of all segments for type Country road;
				   : Get info navi path ADAS quality;
				   : Get lane change probability and camlane-visibility;
				   : Get Trace Intersect Crit;
				   If (Traffic Orientation is Right Orientation) then (TRUE)
				   If (right hand traffic OR valid second right lane) then (TRUE)
				   : Set Second lane by cam;
				   Else (FALSE)
				   Endif
				   Elseif (Traffic Orientation is left Orientation) then (TRUE)
				   If (left hand traffic OR valid second left lane) then (TRUE)
				   : Set Second lane by cam;
				   Else (FALSE)
				   Endif
				   Else (FALSE)
				   Endif
				   : Get derivation of the ACC-Trajectory at the distance of the object;
				   : Get orientation of the ACC-Trajectory at the distance of the object;
				   : Get overtake manoeuvre;
				   If (moving objects OR on a country road OR navi path ADAS quality OR\n trace-y-intersection indicates ego is following target object OR\n distance of the object is smaller than a threshold AND\n lane change probability is low OR no second lane is seen by the camera AND\n no hidden next object available) then (TRUE)
				   : If object is close to the next exit, no extension is applied;
				   : Extension based on distance to object;
				   : Extension to left or right side based on Close to exit;
				   Else (FALSE)
				   Endif
				   Else (FALSE)
				   Endif
				   End
				   }
				   @enduml

  @return          static void

  @param[in]       *pObjInput : Information about current object  [Pointer to structure LA_t_RelTraObjInput defned in la_corridor_crit.h]
                     pObjInput->iRelevant                         [ubit8_t defined in algo_type.h]    [TRUE,FALSE]
                     pObjInput->iObjNr                            [ObjNumber_t defined in Rte_Type.h] [0   39]
                     pObjInput->ucDynamicProperty                 [SLATE_t_Obj_DynamicProperty defined in Rte_Type.h]
                     pObjInput->dAblage_Radius                    [-PI/2*RW_FCT_MAX   PI/2*RW_FCT_MAX] m
                     pObjInput->dYIntersec                        [-PI/2*RW_FCT_MAX ... PI/2*RW_FCT_MAX] m

  @param[out]      *pBracketOut : Trace bracket extension for the current object-      [Pointer to LA_t_BracketOutput defined in la_corridor_crit.h]
                                  -(absolute values for left and right trace bracket)
                      pBracketOut->BracketPositionLeft                                 [-PI/2*RW_FCT_MAX   PI/2*RW_FCT_MAX] m
                      pBracketOut->BracketPositionRight                                [-PI/2*RW_FCT_MAX   PI/2*RW_FCT_MAX] m


  @glob_in         GET_ROAD_DATA_PTR->Traffic.eTrafficOrientation                 [type eTrafficOrientation_t defined in Rte_Type.h]
  @glob_in         pSLATE_CamLaneData->LaneMarkerInfo[  ].MarkerType             [type t_MarkerType defined in Rte_Type.h]
  @glob_in         pSLATE_CamLaneData->LaneMarkerInfo[  ].u_ExistanceProbability [type unsigned char] [0   100]
  @glob_in         pSLATE_CamLaneData->sSigHeader.eSigStatus                     [type AlgoSignalState_t defined in Rte_Type.h]
  @glob_in         pSLATE_CamLaneData->LaneMarkerInfo[  ].f_MarkerDist           [-PI/2*RW_FCT_MAX   PI/2*RW_FCT_MAX] m
  @glob_in         pSLATE_CamLaneData->LaneMarkerInfo[  ].MarkerType             [type t_MarkerType defined in Rte_Type.h]
  @glob_in         CP_TrajectoryData.Current.fTrajC0                               [-1f   1f] m^-1
  @glob_in         CP_TrajectoryData.Current.fTrajC1                               [-1f   1f] m^-1
  @glob_in         *pt_LAInput->t_RTE.pf_ObjLongDisp  (  )                                      [-5*RW_FCT_MAX   5*RW_FCT_MAX] m 
  @glob_in         pt_LAInput->t_RTE.pf_ObjOrientation(  )                                            [-PI   PI] rad
  @glob_in         OBJ_GET_OOI_LIST_OBJ_IDX(  )                                   [type ObjNumber_t defined in Rte_Type.h] [0  39]
  @glob_in         pt_LAInput->t_RTE.pf_EgoVelObjSync : Ego velocity                            [-330.f ... 330.f] m/s
  @glob_in         pt_LAInput->t_RTE.pf_ObjVrelX(i) : Relative velocity of an object i            [-330.f ... 330.f] m/s
  @glob_in         pt_LAInput->t_RTE.pf_EgoCurve : Ego curve                                 [-1.f ... 1.f] 1/m
  @glob_in         CP_CourseData : structure of type CPCourseData_t, describes the Course.Defined in si_main.c.
                    CP_CourseData.fCurveGradient                                   [-1 … +1] m^-2

  @glob_out        -

  @c_switch_part   SLATE_CFG_CAM_LANE_INTERFACE     : Configuration switch enabling camera lane input data to FCT_SEN
  @c_switch_part   FCT_USE_EM_ARS_TECH_OBJECT_LIST    : FCT switch for EM ARS object list
  @c_switch_full   FCT_CFG_ACC_LANE_ASSOCIATION       : FCT switch for ACC LA (Lane Association) sub-component
  @c_switch_full   FCT_CFG_INPUT_PREPROCESSSING       : FCT support for FCT Input Preprocessing (FIP)
  @c_switch_full   SLATE_CFG_SIMPLE_NAVI_INTERFACE  : Configuration switch enabling simple navi input data to FCT_SEN
  @c_switch_full   LA_CFG_NAVI_COUNTRYROAD_EXTENSION  : Configuration switch enabling the trace bracket extension on country roads (based on navi information)

  @pre             -
  @post            -

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @created         -
  @changed         3/4/2016

  @author          Marie-Theres Boll
*************************************************************************************************************************/
static void LA_v_RelTraExtensionNaviCountryroad(LA_t_RelTraObjInput const *pObjInput, LA_t_BracketOutput *pBracketOut)
{
  boolean bAllSegCountryroad, bNaviPathQuality, bTraceYIntersecCrit; 
  uint8 u_SILaneChangeProb;
  float32 fObjVrelX;
  float32 fEgoVelObjSync;
#if (FCT_CFG_SEN_CAM_LANE_INTERFACE) 
  float32 f_CamLaneVisibilityDist;
#endif
#if 0  
   float32 fDivTrajAtObjDist, fOrientTrajObj, f_ABSOrientation; 
   boolean bZOInOvertakingManoeuvre;
   boolean bSecondLaneByCam = FALSE;
#endif

  /*! Remark: Extension is discarded if the object is close to the next exit (exits further away are not considered yet) */
  /*! Apply extension only to relevant objects which are moving with sufficient speed to avoid critical drop-ins on pedestrians or cyclists*/
   fObjVrelX = (*pt_LAInput->t_RTE.pf_ObjVrelX(pObjInput->iObjNr));
   fEgoVelObjSync = (*pt_LAInput->t_RTE.pf_EgoVelObjSync);

  if( (pObjInput->iRelevant == (ubit8_t)TRUE) &&
    ( (fEgoVelObjSync < LA_NAVI_COUNTRYROAD_EGO_SPEED_MAX ) ||
      (fObjVrelX > LA_NAVI_COUNTRYROAD_VREL_MIN) ))
  {
    /*! Get info if all segments are of the type "Country road" */
    bAllSegCountryroad = (pt_LAInput->pt_FIPNaviData->b_NaviPathIsCountryRoadOneLane);
    /*! Get info if navi path ADAS quality is given */
    bNaviPathQuality   = (pt_LAInput->pt_FIPNaviData->b_NaviPathIsADASQuality);
    /*! Get lane change probability and camlane-visibility*/
    //iSILaneChangeProb = SIT_s_LCGetLaneChangeProbability();
    u_SILaneChangeProb = pt_LAInput->t_SIT.pt_GetLaneChangeInfo->u_LCPhaseProb;
#if (FCT_CFG_SEN_CAM_LANE_INTERFACE)
f_CamLaneVisibilityDist = (pt_LAInput->pt_FIPCamLane->f_VisibilityDist);/*!< Visibility distance of camera lane */
#endif

    /*! Get info if ego-vehicle object is following the target object based on the trace-y-intersection. If the ego-vehicle or target object is 
        located on the lane for oncoming traffic (examples: overtaking without usage of turn indicator, target object performs cutout towards departure lane, 
        which is not included in the navi map), the country road corridor extension should be de-plausibilized (Exceptional case: narrow curves and high 
        ego-course gradient, which indicate following an object on winding road).  */
    if((fABS(pObjInput->dYIntersec) > LA_NAVI_TRACE_YINTERSECT_DEFAULT_THRESHOLD) || 
       (fABS(pObjInput->dYIntersec) < LA_MAX_TRACE_Y_INTERSECT_NAVI_EXTENSION) || 
       (fABS(*pt_LAInput->t_RTE.pf_EgoCurve) > LA_MAX_EGO_CURVE_TRACE_INTERSECT_NAVI_EXTENSION) ||
       (fABS(*(pt_LAInput->t_CP.pf_CourseCurveGradient)) > LA_MAX_COURSE_GRADIENT_TRACE_INTERSECT_NAVI_EXTENSION))
    {
      bTraceYIntersecCrit = TRUE;
    }
    else
    {
      bTraceYIntersecCrit = FALSE;
    }
   
#if 0
    /*! Determine if a second lane (cars driving in the same direction) is determined by the camera) */
    bSecondLaneByCam = FALSE;
    if((pt_LAInput->pt_FIPTO->t_FIPTrafficOrientation) == SLATE_TRAFFIC_ORIENTATION_RIGHT)
    {
      /*! In case of right hand traffic, check if there is a valid second right lane */
      if( (f_CamLaneVisibilityDist > LA_NAVI_MIN_CAM_VISIBILITY) &&
        ( (pSLATE_CamLaneData->LaneMarkerInfo[FIP_CL_MK_RIGHT].MarkerType == CL_MARKER_TYPE_DASHED) ||
        (pSLATE_CamLaneData->LaneMarkerInfo[FIP_CL_MK_RIGHT].MarkerType == CL_MARKER_TYPE_DOTTED) ||
        (pSLATE_CamLaneData->LaneMarkerInfo[FIP_CL_MK_RIGHT].MarkerType == CL_MARKER_TYPE_NARROWDASHED)
        ) &&
        (pSLATE_CamLaneData->LaneMarkerInfo[FIP_CL_MK_ADJ_RIGHT].u_ExistanceProbability >= FIP_CAM_LANE_POE_LEVEL) &&
        (pSLATE_CamLaneData->sSigHeader.eSigStatus == AL_SIG_STATE_OK) &&
        ((pSLATE_CamLaneData->LaneMarkerInfo[FIP_CL_MK_RIGHT].f_MarkerDist - pSLATE_CamLaneData->LaneMarkerInfo[FIP_CL_MK_ADJ_RIGHT].f_MarkerDist) > LA_NAVI_MIN_CAM_LANE_WIDTH) &&
        ((pSLATE_CamLaneData->LaneMarkerInfo[FIP_CL_MK_RIGHT].f_MarkerDist - pSLATE_CamLaneData->LaneMarkerInfo[FIP_CL_MK_ADJ_RIGHT].f_MarkerDist) < LA_NAVI_MAX_CAM_LANE_WIDTH)
        )
      {
        bSecondLaneByCam = TRUE;
      }
    }
    else if((pt_LAInput->pt_FIPTO->t_FIPTrafficOrientation) == SLATE_TRAFFIC_ORIENTATION_LEFT)
    {
      /*! In case of left hand traffic, check if there is a valid second left lane */
      if( (f_CamLaneVisibilityDist > LA_NAVI_MIN_CAM_VISIBILITY) &&
        ( (pSLATE_CamLaneData->LaneMarkerInfo[FIP_CL_MK_LEFT].MarkerType == CL_MARKER_TYPE_DASHED) ||
        (pSLATE_CamLaneData->LaneMarkerInfo[FIP_CL_MK_LEFT].MarkerType == CL_MARKER_TYPE_DOTTED) ||
        (pSLATE_CamLaneData->LaneMarkerInfo[FIP_CL_MK_LEFT].MarkerType == CL_MARKER_TYPE_NARROWDASHED)
        ) &&
        (pSLATE_CamLaneData->LaneMarkerInfo[FIP_CL_MK_ADJ_LEFT].u_ExistanceProbability >= FIP_CAM_LANE_POE_LEVEL) &&
        (pSLATE_CamLaneData->sSigHeader.eSigStatus == AL_SIG_STATE_OK) &&
        ((pSLATE_CamLaneData->LaneMarkerInfo[FIP_CL_MK_ADJ_LEFT].f_MarkerDist - pSLATE_CamLaneData->LaneMarkerInfo[FIP_CL_MK_LEFT].f_MarkerDist) > LA_NAVI_MIN_CAM_LANE_WIDTH) &&
        ((pSLATE_CamLaneData->LaneMarkerInfo[FIP_CL_MK_ADJ_LEFT].f_MarkerDist - pSLATE_CamLaneData->LaneMarkerInfo[FIP_CL_MK_LEFT].f_MarkerDist) < LA_NAVI_MAX_CAM_LANE_WIDTH)
        )
      {
        bSecondLaneByCam = TRUE;
      }
    }
    else
    {
      /* QAC fix*/
    }

#endif

#if 0
    /*! Determine derivation of the ACC-Trajectory at the distance of the object */
    fDivTrajAtObjDist = CP_TrajectoryData.Current.fTrajC0 * (*pt_LAInput->t_RTE.pf_ObjLongDisp(pObjInput->iObjNr)) + 
      0.5f * CP_TrajectoryData.Current.fTrajC1 * SQR(*pt_LAInput->t_RTE.pf_ObjLongDisp(pObjInput->iObjNr));
    /*! Determine orientation of the ACC-Trajectory at the distance of the object */
    fOrientTrajObj = ATAN_(fDivTrajAtObjDist);
    f_ABSOrientation = fABS(pt_LAInput->t_RTE.pf_ObjOrientation(pObjInput->iObjNr) - fOrientTrajObj);
#endif

#if 0
    /*! Get info if ZO is doing an overtake manoeuvre */
    bZOInOvertakingManoeuvre = LA_b_CheckZOOvertakingManoeuvre(); // PRQA S 3199
    /* date: 2015-06-17, reviewer: Rachit Sharma (uidr5426), reason: Possible future use */
#endif
    
    /*! Apply the extension only 
    for moving objects
    if on a country road
    if navi path ADAS quality is given
    if the trace-y-intersection indicates, that the ego-vehicle is following the target object
    if the difference of the object orientation to the deviation of the ACC-Trajectory at the distance of the object is smaller than a threshold (object is not turning) 
    if the lane change probability is low (different thresholds if camera lane available)
    if no second lane is seen by the camera (driving in the same direction)
    if no hidden next object available (a drop out would occur -> risk minimation: otherwise a object witch overtakes the object in front would be released very late)
    */
    if ( (pObjInput->ucDynamicProperty == SLATE_OBJECT_PROPERTY_MOVING)
      && (bAllSegCountryroad == TRUE)
      && (bNaviPathQuality== TRUE) 
      && (bTraceYIntersecCrit == TRUE) 
   /* (f_ABSOrientation < SI_MAX_DIFF_ORIENT_OBJ_NAVI_COUNTRYROAD_EXT) && */
#if (SLATE_CFG_CAM_LANE_INTERFACE)
      && ( ( (f_CamLaneVisibilityDist > LA_NAVI_MIN_CAM_VISIBILITY) 
          && (u_SILaneChangeProb <= LA_MAX_LC_PROB_CAM_LANE_NAVI_COUNTRYROAD_EXT) 
           ) 
        || ( (f_CamLaneVisibilityDist <= LA_NAVI_MIN_CAM_VISIBILITY)
          && (u_SILaneChangeProb <= LA_MAX_LC_PROB_NO_CAM_LANE_NAVI_COUNTRYROAD_EXT) 
           )
         )
#else
      && (u_SILaneChangeProb <= LA_MAX_LC_PROB_NO_CAM_LANE_NAVI_COUNTRYROAD_EXT)
#endif
      /* (bSecondLaneByCam == FALSE) && */
      && (OBJ_GET_OOI_LIST_OBJ_IDX(OBJ_HIDDEN_NEXT_OOI) == OBJ_NOT_OOI)
       )
    {
      boolean bCloseToExitLeft, bCloseToExitRight;
      float32 fExt;

      /*! If object is close to the next exit, no extension is applied (no objects further away considered) */
      LA_v_ObjCloseToExit((*pt_LAInput->t_RTE.pf_ObjLongDisp(pObjInput->iObjNr)), &bCloseToExitLeft, &bCloseToExitRight);

      /*! Extension based on distance to object */
      fExt = dGDBmathLineareFunktion(&LA_TRCK_Navi_Countryroad_Ext, *pt_LAInput->t_RTE.pf_ObjLongDisp(pObjInput->iObjNr));

      /*! Apply extension to left and/or right side */
      if(bCloseToExitLeft == FALSE)
      {
        pBracketOut->BracketPositionLeft = pObjInput->dAblage_Radius + fExt;
      }
      if(bCloseToExitRight == FALSE)
      {
        pBracketOut->BracketPositionRight = pObjInput->dAblage_Radius - fExt;
      }
    }
  } /* End of IF condition, Object relevancy */
}

#if 0
/*************************************************************************************************************************
  Functionname:    LA_b_CheckZOOvertakingManoeuvre                                                                  */ /*!

  @brief           Determine if an target object is doing or about to do an overtaking manoeuvre

  @description     Determine if an target object is doing or about to do an overtaking manoeuvre.
                   All processing in this function uses object data from previous cycle. 
                   Call this function only when NAVI indicates one lane roads.

				   @startuml
				   Partition LA_b_CheckZOOvertakingManoeuvre{
				   Start
				   : Initialize ZO overtaking;
				   : Get Object ID of ZO and distance to EGO;
				   : Get Object ID of next lane object;
				   If (next lane object is High) then (TRUE)
				   If (object moving and not oncoming) then (TRUE)
				   : Get Longitudinal displacement of object;
				   : Set ZO being overtaken;
				   Else (FALSE)
				   Endif
				   Else (FALSE)
				   Endif
				   If (ZO being overtaken) then (TRUE)
				   : exit;
				   Else (FALSE)
				   Endif
				   End
				   }
				   @enduml

  @return          bZOIsOvertaking: boolean indicating if ZO is in overtaking manoeuvre  [TRUE, FALSE]

  @param[in]       - 

  @glob_in         OBJ_GET_OOI_LIST_OBJ_IDX(  )    : Macro for accessing ACC Assessed Object List object of interest array     [type ObjNumber_t defined in Rte_Type.h] [0   39]
  @glob_in         *pt_LAInput->t_RTE.pf_ObjLongDisp  (  )       : Lonigtudinal distance to object                                           [-5*RW_FCT_MAX    5*RW_FCT_MAX] m
  @glob_in         *SLATE_pt_GetObjDynProperty(  )        : Dynamic property of the object                                            [full range of type EM_t_GenObjDynamicProperty defined in Rte_Type.h]
  @glob_in         SLATE_b_GetObjIsMovingToStationary(  ) : Macro to check if a moving object is stopping                             [0, 1]

  @glob_out        -

  @c_switch_part   -
  @c_switch_full   LA_CFG_NAVI_COUNTRYROAD_EXTENSION  : Configuration switch enabling the trace bracket extension on country roads (based on navi information)
  @c_switch_full   FCT_CFG_ACC_LANE_ASSOCIATION       : FCT switch for ACC LA (Lane Association) sub-component
  @c_switch_full   FCT_CFG_INPUT_PREPROCESSSING       : FCT support for FCT Input Preprocessing (FIP)
  @c_switch_full   SLATE_CFG_SIMPLE_NAVI_INTERFACE  : Configuration switch enabling simple navi input data to FCT_SEN

  @pre             -
  @post            -

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @changed         3/3/2016

  @author          Harsha Umesh Babu
*************************************************************************************************************************/
static boolean LA_b_CheckZOOvertakingManoeuvre(void)
{
  boolean bZOIsOvertaking = FALSE;  /* Default FALSE */
  float32 fZOLong, fNSLong;
  ObjNumber_t zObject, nsObject;
  eObjOOI_t OOInumber;

  /* Get Object ID of ZO followed by its distance to EGO */
  zObject = OBJ_GET_OOI_LIST_OBJ_IDX(OBJ_NEXT_OOI);
  fZOLong = *pt_LAInput->t_RTE.pf_ObjLongDisp(zObject);

  /* Ideally use switch(TRAFFIC_ORIENTATION)
  case SLATE_TRAFFIC_ORIENTATION_RIGHT  : Check for objects on right hand side & hidden OOI -OOI 1, OOI 3 & OOI 5, which would indicate that they might be overtaken
  case SLATE_TRAFFIC_ORIENTATION_LEFT   : Check for objects on left hand side & hidden OOI -OOI 1, OOI 2 & OOI 4, which would indicate that they might be overtaken
  case SLATE_TRAFFIC_ORIENTATION_UNKNOWN         : Default - go through all the OOI list from 1-5. Currently only the this case is implemented
  */
  for(OOInumber = OBJ_HIDDEN_NEXT_OOI;OOInumber <= OBJ_NEXT_LAT_RIGHT_OOI; OOInumber++)
  {
    /* Get Object ID of next lane object */
    nsObject = OBJ_GET_OOI_LIST_OBJ_IDX(OOInumber);
    if (nsObject > 0)
    {
      /* There exists a valid object on right lane, now check if it is moving and not oncoming! */
      if ((*SLATE_pt_GetObjDynProperty(nsObject) == SLATE_OBJECT_PROPERTY_MOVING) ||
          (SLATE_b_GetObjIsMovingToStationary(nsObject)))
      {
        fNSLong = *pt_LAInput->t_RTE.pf_ObjLongDisp(nsObject);
        if (fABS(fNSLong - fZOLong) <= LA_MIN_DIFF_ZO_OVERTAKE_NSO)
        {
          /* Longitudinal distance between nsObject and ZO is within threshold, where it can be deemed as being overtaken */
          bZOIsOvertaking = TRUE;
        } /* END IF (fNSLong - fZOLong) > LA_MIN_DIFF_ZO_OVERTAKE_NSO) */
      } /* END IF Object is either moving or moving to stationary and certainly NOT oncoming */
    } /* IF nsObject > 0 - OOI existence Check */

    if (bZOIsOvertaking == TRUE)
    {
      /* As long as one object has been identified as being a probable candidate for overtaking by ZO, exit! */
      break;
    }
  } /* END FOR LOOP over all OOI other than ZO */
  return bZOIsOvertaking;
}

#endif
#endif /*LA_CFG_NAVI_COUNTRYROAD_EXTENSION*/

#if( (LA_CFG_NAVI_OBJ_CLOSE_TO_EXIT_RESTRICTION) || (LA_CFG_NAVI_COUNTRYROAD_EXTENSION) )

/*************************************************************************************************************************
  Functionname:    LA_v_ObjCloseToExit                                                                                 */ /*!

  @brief           Determine if an object is close to an exit identified by the navi

  @description     Determine if an object is close to an exit identified by the navi

                   @startuml
                   Partition LA_v_ObjCloseToExit{
                   Start
                   : Initialize close to an exit on left and right;
                   : Get distance to the next exit left or right;
                   If (distance of object to the next left exit) then (TRUE)
                   : Set close to an exit on left;
                   Else (FALSE)
                   Endif
                   If (distance of object to the next right exit) then (TRUE)
                   : Set close to an exit on right;
                   Else (FALSE)
                   Endif
                   End
                   }
                   @enduml

  @return          static void

  @param[in]       fDistObj : Distance to object  [-5*RW_FCT_MAX    5*RW_FCT_MAX] m

  @param[out]      pbCloseToExitLeft  : Boolean to indicate if object is close to an exit on left  [type boolean defined in Platform_Types.h] [TRUE,FALSE]
  @param[out]      pbCloseToExitRight : Boolean to indicate if object is close to an exit on right [type boolean defined in Platform_Types.h] [TRUE,FALSE]

  @glob_in        -
  @glob_out        -

  @c_switch_part   -
  @c_switch_full   LA_CFG_NAVI_OBJ_CLOSE_TO_EXIT_RESTRICTION  : Configuration switch enabling the trace bracket restriction close to an exit (based on navi information)
  @c_switch_full   LA_CFG_NAVI_COUNTRYROAD_EXTENSION          : Configuration switch enabling the trace bracket extension on country roads (based on navi information)
  @c_switch_full   FCT_CFG_ACC_LANE_ASSOCIATION               : FCT switch for ACC LA (Lane Association) sub-component
  @c_switch_full   FCT_CFG_INPUT_PREPROCESSSING               : FCT support for FCT Input Preprocessing (FIP)
  @c_switch_full   SLATE_CFG_SIMPLE_NAVI_INTERFACE          : Configuration switch enabling simple navi input data to FCT_SEN


  @pre             -
  @post            -

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @created         -
  @changed         3/3/2016

  @author          Marie-Theres Boll
*************************************************************************************************************************/
static void LA_v_ObjCloseToExit(float32 const fDistObj, boolean * pbCloseToExitLeft, boolean * pbCloseToExitRight)
{
  /*! Only the first exit on the left/right side is considered, no further exists */

  float32 f_DistNextLeftExit, f_DistNextRightExit;

  /*! Set default to FALSE */
  *(pbCloseToExitLeft) = FALSE;
  *(pbCloseToExitRight) = FALSE;

  /*! Get distance to the next exit left/right */
  f_DistNextLeftExit = (pt_LAInput->pt_FIPNaviData->f_DistNextLeftExit);
  f_DistNextRightExit = (pt_LAInput->pt_FIPNaviData->f_DistNextRightExit);

  /*! If distance of object to the next left exit, set the return value to TRUE */
  if( (f_DistNextLeftExit < LA_NAVI_MAX_EGO_DISTX_TO_EXIT) &&
      ((f_DistNextLeftExit - fDistObj) < LA_NAVI_MAX_OBJ_DISTX_TO_EXIT) && 
      ((f_DistNextLeftExit - fDistObj) > LA_NAVI_MIN_OBJ_DISTX_TO_EXIT) 
    )
  {
    *(pbCloseToExitLeft) = TRUE;
  }
  /*! If distance of object to the next right exit, set the return value to TRUE */
  if( (f_DistNextRightExit < LA_NAVI_MAX_EGO_DISTX_TO_EXIT) &&
      ((f_DistNextRightExit - fDistObj) < LA_NAVI_MAX_OBJ_DISTX_TO_EXIT) && 
      ((f_DistNextRightExit - fDistObj) > LA_NAVI_MIN_OBJ_DISTX_TO_EXIT) 
    )
  {
    *(pbCloseToExitRight) = TRUE;
  }
}
#endif


/*************************************************************************************************************************
  Functionname:    LA_v_NaviSetMeasData                                                                             */ /*!

  @brief           Set navi LA meas freeze data

  @description     Set navi LA meas freeze data

                   @startuml
                   Partition LA_v_NaviSetMeasData{
                   Start
                   : Get Navi Country External Switch;
                   End
                   }
                   @enduml

  @return          -

  @param[out]      p_NaviDebugMeasFreeze : Debug structure for navigation LA measurement freeze  [Pointer to structure SI_NaviDebugMeasInfo_t defined in si_ext.h]
                    p_NaviDebugMeasFreeze->b_NaviCountryExternalSwitch                           [type boolean defined in Platform_Types.h] [TRUE,FALSE]

  @glob_in         b_NaviLAExternalSwitchMeas     : Variable for navi LA meas freeze  [type boolean defined in Platform_Types.h] [TRUE,FALSE]
  @glob_out        -

  @c_switch_part   -
  @c_switch_full   FCT_CFG_ACC_LANE_ASSOCIATION       : FCT switch for ACC LA (Lane Association) sub-component
  @c_switch_full   FCT_CFG_INPUT_PREPROCESSSING       : FCT support for FCT Input Preprocessing (FIP)
  @c_switch_full   SLATE_CFG_SIMPLE_NAVI_INTERFACE  : Configuration switch enabling simple navi input data to FCT_SEN

  @pre             -
  @post            -

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @created         -
  @changed         3/3/2016

  @author          Marie-Theres Boll
*************************************************************************************************************************/
void LA_v_NaviSetMeasData(LA_NaviDebugMeasInfo_t * p_NaviDebugMeasFreeze)
{
  p_NaviDebugMeasFreeze->b_NaviCountryExternalSwitch = b_NaviLAExternalSwitchMeas;
}
/** @} end defgroup */
#endif /* (SLATE_CFG_SIMPLE_NAVI_INTERFACE) && (FCT_CFG_INPUT_PREPROCESSSING) */
#endif /* (FCT_CFG_ACC_LANE_ASSOCIATION) */

/* ************************************************************************* */
/*   Copyright ADC-GmbH, Lindau                                              */
/* ************************************************************************* */
