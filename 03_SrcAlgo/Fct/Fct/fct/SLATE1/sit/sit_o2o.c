/*! \file **********************************************************************

COMPANY:                   COPYRIGHT (C) Continental AG

PROJECT:                   Adaptive Cruise Control (ACC)

CPU:                       CPU-Independent

COMPONENT:                 SIT

PACKAGENAME:               sit_o2o.c

DESCRIPTION:               ACC Object-to-Object Lane Association

AUTHOR:                    Bharadwaj Gobichettipalayam Sankar (uidk9952)

CREATION DATE:             03.03.2017

VERSION:                   $Revision: 1.9 $

*****************************************************************************/



/*****************************************************************************
  INCLUDES
*****************************************************************************/
#include "sit.h"//PRQA S 0380
/* date: 2019-07-28, reviewer:Prabhu Sundaramurthy, reason: Arises due to inclusion of multiple header files in this header file which has multiple macros*/
#include "sit_o2o.h"
#include "sit_custom.h"
#if (FCT_CFG_ACC_SITUATION)
#if (SIT_O2O_ANALYSIS)
/*****************************************************************************
  MODULE DESCRIPTION
*****************************************************************************/

/**
@defgroup sit_o2o Object-to-Object Lane Association
@ingroup sit
@brief          This module does Object-to-Object Lane Association.\n\n
@{
*/
/*****************************************************************************
  MACROS 
*****************************************************************************/


/*****************************************************************************
  TYPEDEFS
*****************************************************************************/

/*****************************************************************************
  (SYMBOLIC) CONSTANTS
*****************************************************************************/
#define SIT_O2O_DEFAULTOBJDISTONTRAJ          (0.0f)
#define SIT_O2O_DEFAULTOBJLATDISP             (0.0f)
/* Trace parameters */
#define SIT_O2O_TRACE_MIN_SAMPLES             ((sint8)4)
#define SIT_MIN_STD_DEV_CURVE_START           0.7f
#define SIT_MAX_STD_DEV_CURVE                 1.7f

/*****************************************************************************
  MODULE LOCAL CONSTANTS
*****************************************************************************/

#define SIT_O2O_OBJ_DIST_TO_ROADBORDER_CONF_MIN            (70u)   /*<! Minimal confidence for the Road Estimation to be considered */
#define SIT_O2O_OBJ_DIST_TO_ROADBORDER_STATUS_MIN          (100u)  /*<! Minimum road border stat left/right to compute object distance to road border */
#define SIT_O2O_OBJ_DIST_TO_ROADBORDER_DEFAULT             (999.F) /*<! Default distance of object to road border */
#define SIT_O2O_SECONDARY_OBJ_SEARCH_DEFAULT_LENGTH        (20.f) /* Default length threshold for searching of second object close to the object under investigation */

/*****************************************************************************
  EXTERN VARIABLES
*****************************************************************************/


/*****************************************************************************
  MODULE LOCAL VARIABLES
*****************************************************************************/
SET_MEMSEC_VAR(t_SIT_O2O_ObjRoadBorderData)
/*! Object to road border distance data for every object */
static SIT_O2O_Analysis_t t_SIT_O2O_ObjRoadBorderData[EM_N_OBJECTS];

/*****************************************************************************
FUNCTION PROTOTYPES
*****************************************************************************/
/* Road Border approach */
static void SIT_v_CalcO2OObjToBorderDist(void);
static void SIT_v_InitObjToBorderData(void);
static void SIT_v_FindO2ONearObj(void);

/*************************************************************************************************************************
  Functionname:    SIT_v_O2OAnalysis                                                                                */ /*!

  @brief           

  @description     

		@startuml
		Start
		Partition SIT_v_O2OAnalysis {
			#Orange :<b>SIT_v_CalcO2OObjToBorderDist</b> : Calculate distance to road border for objects;
			If (enable new object scoring module) then (yes)
				#Orange :<b>SIT_v_CalculateObjectScores</b> : Object Scoring for O2O absolute lane association;
			Endif
		}
		End 
		@enduml

  @return          -

  @param[in]       -

  @glob_in         OBJ_DYNAMIC_PROPERTY(i) : Dynamic property of an object i [EM_t_ARS_DynamicProperty as in Rte_Type.h]
  @glob_out        

  @c_switch_part   -
  @c_switch_full   

  @pre             -
  @post            -

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @created         
  @changed         

  @todo            

  @author          Bharadwaj Gobichettipalayam Sankar| bharadwaj.gobichettipalayam.sankar@continental-corporation.com | +49 (8382) 9699-4977
*************************************************************************************************************************/
void SIT_v_O2OAnalysis(void)
{
  /* Calculate distance to road border for objects */
  SIT_v_CalcO2OObjToBorderDist();

#if (SIT_CFG_OBJECT_SCORING)
  /* Object Scoring for O2O absolute lane association */
  SIT_v_CalculateObjectScores();
#endif
}

/*************************************************************************************************************************
  Functionname:    SIT_v_CalcO2OObjToBorderDist                                                                      */ /*!

  @brief           Calculate the orthogonal distance of objects to road border

  @description     Calculate the orthogonal distance of objects to road border

		@startuml 
		Start
		Partition SIT_v_CalcO2OObjToBorderDist {
		#Orange: <b>SIT_v_InitObjToBorderData</b>: Initialize the object to road border data structure;
		If (Road estimation input to FCT) then (yes)
			Repeat
				If (Absolute value of Lateral Displacement of Object is less\n than estimated distance to the left or \n right fused road border and Status of left and right fused \n road border estimation is greater than\n or equals to minimum status road border estimation and Confidence\n of right and left side estimation of road is more than \nMinimum road border confidence and Object Quality is \ngreater or equals to minimum ACC \nQuality level  and Object is On Coming \nand Object Longitudinal Displacement is \nless than or equal to Estimate of max\n range of road border on left or right) then (yes)
					: Orthogonal distance of object to the road polynomial;
					: Estimate object distance relative to left and right road borders;
					: Set the values of output pointers;
				Else
					: Do Nothing;
				Endif
			Repeat while (for entire object list)
			: Calculate distance between objects that are close to each other;
		Else (no)
			: Do Nothing;
		Endif
		End
		}
		@enduml

  @return          -

  @param[in]       -

  @glob_in         OBJ_NUMBER_OF_OBJ_USED : number of objects [0 ... EM_N_OBJECTS[ with EM_N_OBJECTS as in Rte_SWCEmAdapt_Type.h
  @glob_in         pt_SITInput->t_RTE.pu_DistXSortedObj : Objects sorted according to x distance, defined in algo_glob.h               [-1 ... EM_N_OBJECTS-1]
  @glob_in         pt_SITInput->t_RTE.pu_AccObjQuality : ACC object quality [0u ... 100u] 
                    with i in [0 ... EM_N_OBJECTS[ with EM_N_OBJECTS as in Rte_SWCEmAdapt_Type.h
  @glob_in         pt_SITInput->t_RTE.pf_ObjLatDisp : object's latitudinal  displacement [-PI/2*RW_FCT_MAX ... PI/2*RW_FCT_MAX] m
  @glob_in         pt_SITInput->t_RTE.pt_ObjDynProperty : Dynamic property of object i [EM_t_ARS_DynamicProperty as defined in rte_type.h]
                    with i in [0 ... EM_N_OBJECTS[ and EM_N_OBJECTS as in Rte_SWCEmAdapt_Type.h
  @glob_in         pt_SITInput->t_RTE.pf_ObjLongDisp : object's longitudinal displacement [-5*RW_FCT_MAX ... 5*RW_FCT_MAX] m

  @glob_out        -

  @c_switch_part   -
  @c_switch_full   SIT_O2O_ANALYSIS : Configuration switch for enabling O2O based analysis as defined in sit_custom_ext.h

  @pre             -
  @post            -

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @created         23.03.17
  @changed         23.03.17

  @todo            -

  @author          Bharadwaj Gobichettipalayam Sankar| bharadwaj.gobichettipalayam.sankar@continental-corporation.com | +49 (8382) 9699-4977
*************************************************************************************************************************/
static void SIT_v_CalcO2OObjToBorderDist(void)
{
  sint8 i;
  uint8 u_ObjQuality; /* ACC object quality */
  ObjNumber_t t_ObjNr;
  CML_t_TrajRefPoint t_referencePoint; /* Structure with distance of object from road course */
  EM_t_ARS_DynamicProperty t_ObjDynProp; /* Object dynamic property */
  float32 f_ObjLatDisp, f_ObjLongDisp;

#if (SIT_CFG_O2O_USE_ROAD_LEFT)
  float32 f_c0 = pSLATE_RoadData->RoadEstimation.RoadBorderLeft.ClothoidParams.f_Curvature;
  float32 f_c1 = pSLATE_RoadData->RoadEstimation.RoadBorderLeft.ClothoidParams.f_ClothoidParam1;
#elif (SIT_CFG_O2O_USE_ROAD_RIGHT)
  float32 f_c0 = pSLATE_RoadData->RoadEstimation.RoadBorderRight.ClothoidParams.f_Curvature;
  float32 f_c1 = pSLATE_RoadData->RoadEstimation.RoadBorderRight.ClothoidParams.f_ClothoidParam1;
#else /* Coupled road */
  float32 f_c0 = pt_SITInput->pt_FIPRoad->t_FIPRoadEstimation.fC0;                                   /* Road curvature */
  float32 f_c1 = pt_SITInput->pt_FIPRoad->t_FIPRoadEstimation.fC1;                                   /* Road curvature gradient*/
#endif /* END IF SIT_CFG_O2O_USE_ROAD_LEFT and SIT_CFG_O2O_USE_ROAD_RIGHT */
  float32 f_RoadDistLeft = pt_SITInput->pt_FIPRoad->t_FIPRoadFusedBorder.fDistLeft;                  /* Estimated distance to the left fused road border  */
  float32 f_RoadDistRight = pt_SITInput->pt_FIPRoad->t_FIPRoadFusedBorder.fDistRight;                /* Estimated distance to the right fused road border */
  float32 f_LeftRoadStat = pt_SITInput->pt_FIPRoad->t_FIPRoadFusedBorder.bStatusLeft;                /* Status of right fused road border estimation */
  float32 f_RightRoadStat = pt_SITInput->pt_FIPRoad->t_FIPRoadFusedBorder.bStatusRight;              /* Status of left fused road border estimation */
  float32 f_LeftRoadConf = pt_SITInput->pt_FIPRoad->t_FIPRoadEstimation.fConfidenceLeft;
  float32 f_RightRoadConf = pt_SITInput->pt_FIPRoad->t_FIPRoadEstimation.fConfidenceRight;
  float32 f_MaxRoadOnRight = pt_SITInput->pt_FIPRoad->t_FIPRoadEstimation.fmaxXRightCompensated;     /* Estimate of max range of road border on right */
  float32 f_MaxRoadOnLeft = pt_SITInput->pt_FIPRoad->t_FIPRoadEstimation.fmaxXLeftCompensated;       /* Estimate of max range of road border on left */

  /* Initialize the object to road border data structure */
  SIT_v_InitObjToBorderData();

#if (FCT_CFG_ROAD_INPUT)
  {
    for (i=0;i<OBJ_NUMBER_OF_OBJ_USED;i++)
    {
      t_ObjNr = *pt_SITInput->t_RTE.pu_DistXSortedObj(i);
      f_ObjLatDisp = *pt_SITInput->t_RTE.pf_ObjLatDisp(t_ObjNr);
      f_ObjLongDisp = *pt_SITInput->t_RTE.pf_ObjLongDisp(t_ObjNr);
      t_ObjDynProp = *pt_SITInput->t_RTE.pt_ObjDynProperty(t_ObjNr);
      u_ObjQuality = pt_SITInput->t_RTE.pu_AccObjQuality(t_ObjNr);

      if ( (((ABS(f_ObjLatDisp)) < (ABS(f_RoadDistLeft))) || ((ABS(f_ObjLatDisp)) < (ABS(f_RoadDistRight))))
        && ((f_LeftRoadStat >= SIT_O2O_OBJ_DIST_TO_ROADBORDER_STATUS_MIN) && (f_RightRoadStat >= SIT_O2O_OBJ_DIST_TO_ROADBORDER_STATUS_MIN))
        && ((f_RightRoadConf > SIT_O2O_OBJ_DIST_TO_ROADBORDER_CONF_MIN) && (f_LeftRoadConf > SIT_O2O_OBJ_DIST_TO_ROADBORDER_CONF_MIN))
        && (u_ObjQuality >= FUN_PRESEL_ACC_MIN_OBJ_QUAL)
        && (t_ObjDynProp != ARS_OBJECT_PROPERTY_ONCOMING)
        && ((f_ObjLongDisp <= f_MaxRoadOnLeft) || (f_ObjLongDisp <= f_MaxRoadOnRight)) )
      {
        t_SIT_O2O_ObjRoadBorderData[t_ObjNr].f_LongDist = f_ObjLongDisp; 
        t_referencePoint = CML_CalculateDistancePoint2Clothoid(f_ObjLongDisp,f_ObjLatDisp,f_c0,f_c1);
        /* Orthogonal distance of object to the road polynomial */
        t_SIT_O2O_ObjRoadBorderData[t_ObjNr].f_LatDist = t_referencePoint.f_DistToTraj; 
        t_SIT_O2O_ObjRoadBorderData[t_ObjNr].t_ObjID = t_ObjNr;

        /* Estimate object distance relative to left and right road borders */
        t_SIT_O2O_ObjRoadBorderData[t_ObjNr].f_DistBorderLeft = f_RoadDistLeft - t_SIT_O2O_ObjRoadBorderData[t_ObjNr].f_LatDist;
        t_SIT_O2O_ObjRoadBorderData[t_ObjNr].f_DistBorderRight = f_RoadDistRight - t_SIT_O2O_ObjRoadBorderData[t_ObjNr].f_LatDist;

        /* Set the values of output pointers */
        pt_SITOutput->t_ObjList[t_ObjNr].t_SIT_O2O_Analysis.f_LongDist = t_SIT_O2O_ObjRoadBorderData[t_ObjNr].f_LongDist;
        pt_SITOutput->t_ObjList[t_ObjNr].t_SIT_O2O_Analysis.f_LatDist = t_SIT_O2O_ObjRoadBorderData[t_ObjNr].f_LatDist;
        pt_SITOutput->t_ObjList[t_ObjNr].t_SIT_O2O_Analysis.t_ObjID = t_ObjNr;
        pt_SITOutput->t_ObjList[t_ObjNr].t_SIT_O2O_Analysis.f_DistBorderLeft = t_SIT_O2O_ObjRoadBorderData[t_ObjNr].f_DistBorderLeft;
        pt_SITOutput->t_ObjList[t_ObjNr].t_SIT_O2O_Analysis.f_DistBorderRight = t_SIT_O2O_ObjRoadBorderData[t_ObjNr].f_DistBorderRight;
      }
      else
      {
        /* else: Road border information not reliable, so object distance to road borders cannot be computed ; Set to default values */
      }
    }
    /* Calculate distance between objects that are close to each other */
    SIT_v_FindO2ONearObj();
  }
#else
  {
    /* do nothing */
  }
#endif
}

/*************************************************************************************************************************
  Functionname:    SIT_v_InitObjToBorderData                                                                        */ /*!

  @brief           Function for initializing the structure for object road border distance calculation

  @description     Function for initializing the structure for object road border distance calculation

		@startuml
		Start
		Partition SIT_v_InitObjToBorderData {
			Repeat 
				: Initialize Object to road border distance data for all object;
			Repeat While (for entire Object list)
		}
		End 
		@enduml

  @return          -

  @param[in]       -

  @glob_in         -
  @glob_out        -

  @c_switch_part   -
  @c_switch_full   -

  @pre             -
  @post            -

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @created         23.03.17
  @changed         23.03.17

  @todo            -

  @author          Bharadwaj Gobichettipalayam Sankar| bharadwaj.gobichettipalayam.sankar@continental-corporation.com | +49 (8382) 9699-4977
************************************************************************************************************************/
static void SIT_v_InitObjToBorderData(void)
{
  uint8 i;

  for (i = 0u; i<EM_N_OBJECTS; i++)
  {
    t_SIT_O2O_ObjRoadBorderData[i].f_DistBorderLeft = SIT_O2O_OBJ_DIST_TO_ROADBORDER_DEFAULT;
    t_SIT_O2O_ObjRoadBorderData[i].f_DistBorderRight = -SIT_O2O_OBJ_DIST_TO_ROADBORDER_DEFAULT;
    t_SIT_O2O_ObjRoadBorderData[i].f_LatDist = SIT_O2O_DEFAULTOBJLATDISP;
    t_SIT_O2O_ObjRoadBorderData[i].f_LongDist = SIT_O2O_DEFAULTOBJDISTONTRAJ;
    t_SIT_O2O_ObjRoadBorderData[i].t_NearObjIDLeft[0u] = OBJ_INDEX_NO_OBJECT;
    t_SIT_O2O_ObjRoadBorderData[i].t_NearObjIDLeft[1u] = OBJ_INDEX_NO_OBJECT;
    t_SIT_O2O_ObjRoadBorderData[i].t_NearObjIDLeft[2u] = OBJ_INDEX_NO_OBJECT;
    t_SIT_O2O_ObjRoadBorderData[i].t_NearObjIDRight[0u] = OBJ_INDEX_NO_OBJECT;
    t_SIT_O2O_ObjRoadBorderData[i].t_NearObjIDRight[1u] = OBJ_INDEX_NO_OBJECT;
    t_SIT_O2O_ObjRoadBorderData[i].t_NearObjIDRight[2u] = OBJ_INDEX_NO_OBJECT;
    t_SIT_O2O_ObjRoadBorderData[i].t_ObjID = OBJ_INDEX_NO_OBJECT;
  }
}

/*************************************************************************************************************************
Functionname:      SIT_v_FindO2ONearObj                                                                         */ /*!

  @brief           Find adjacent objects relative to a particular object

  @description     Find adjacent objects that are inside a particular region, which are relevant to the object under investigation 

		@startuml
		Start
		Partition SIT_v_FindO2ONearObj {
			Repeat 
				: Distance-x sorted object number;
				: Get Lateral displacement of object;
				: Get Longitudinal displacement of object;
				: Get ACC Object Quality;
				If(ACC Object Quality is greater or equal to Min Object Quality level)then (yes)
					Repeat 
						: Distance-x sorted object number;
						: Set Longitudinal displacement of object;
						: Set ACC Object Quality;
						: Set Dynamic property of object;
						: Set Lateral displacement of object;
						If (Nearer Object is not Equal to Distance X Stored Object) then (yes)
							If (searched Objects are closed to the object under investigation) then (yes)
								If (Lateral displacement of Nearer object is more than Lateral displacement of object) then (yes)
									If (Secondary objects are to the left of the primary object) then (yes)
										: Update Nearer Objects as Left Objects;
									Else (no)
										: Do Nothing;
									Endif
								Else (no)
									If (Secondary objects are to the right of the primary object) then (yes)
										: Update Nearer Objects as Right Objects;
									Else (no)
										: Do Nothing;
									Endif
								Endif
							Endif
						Endif
					Repeat While (For All Secondary Objects)
				Endif
			Repeat While (For All Primary Objects)
		}
		End
		@enduml

  @return          -

  @param[in]       -
  @glob_in         OBJ_NUMBER_OF_OBJ_USED : number of objects [0 ... EM_N_OBJECTS[ with EM_N_OBJECTS as in Rte_SWCEmAdapt_Type.h
  @glob_in         pt_SITInput->t_RTE.pu_DistXSortedObj : Objects sorted according to x distance, defined in algo_glob.h               [-1 ... EM_N_OBJECTS-1]
  @glob_in         pt_SITInput->t_RTE.pu_AccObjQuality : ACC object quality [0u ... 100u] 
                    with i in [0 ... EM_N_OBJECTS[ with EM_N_OBJECTS as in Rte_SWCEmAdapt_Type.h
  @glob_in         pt_SITInput->t_RTE.pf_ObjLongDisp : object's longitudinal displacement [-5*RW_FCT_MAX ... 5*RW_FCT_MAX] m
  @glob_in         pt_SITInput->t_RTE.pt_ObjDynProperty : Dynamic property of object i [EM_t_ARS_DynamicProperty as defined in rte_type.h]
                    with i in [0 ... EM_N_OBJECTS[ and EM_N_OBJECTS as in Rte_SWCEmAdapt_Type.h
  @glob_in         pt_SITInput->t_RTE.pf_ObjLatDisp : object's latitudinal  displacement [-PI/2*RW_FCT_MAX ... PI/2*RW_FCT_MAX] m
  @glob_out        -

  @c_switch_part   -
  @c_switch_full   -

  @pre             -
  @post            -

  @created         23.03.17
  @changed         23.03.17

  @todo            -

  @author          Bharadwaj Gobichettipalayam Sankar| bharadwaj.gobichettipalayam.sankar@continental-corporation.com | +49 (8382) 9699-4977
*************************************************************************************************************************/
static void SIT_v_FindO2ONearObj(void)
{
  sint8 i,j;
  ObjNumber_t t_ObjNr,t_NearObjNr;
  uint8 u_ObjQuality, u_NearObjQuality; /* ACC object quality */
  EM_t_ARS_DynamicProperty t_NearObjDynProp; /* Object dynamic property */
  float32 f_ObjLatDispObj, f_ObjLongDispObj, f_ObjLatDispNearObj, f_ObjLongDispNearObj;

  /* Iterating over the primary object */
  for (i=0;i<OBJ_NUMBER_OF_OBJ_USED;i++)
  {
    t_ObjNr = *pt_SITInput->t_RTE.pu_DistXSortedObj(i);        /* Dist-x sorted object number */

    f_ObjLatDispObj = *pt_SITInput->t_RTE.pf_ObjLatDisp(t_ObjNr); /* Lateral displacement of object */
    f_ObjLongDispObj = *pt_SITInput->t_RTE.pf_ObjLongDisp(t_ObjNr); /* Longitudinal displacement of object */
    u_ObjQuality = pt_SITInput->t_RTE.pu_AccObjQuality(t_ObjNr); /* ACC object quality */

    if ( (u_ObjQuality >= FUN_PRESEL_ACC_MIN_OBJ_QUAL))
    {
      /* Iterating over the secondary object */
      for (j=0;j<OBJ_NUMBER_OF_OBJ_USED;j++)
      {
        t_NearObjNr = *pt_SITInput->t_RTE.pu_DistXSortedObj(j); /* Dist-x sorted object number */

        f_ObjLongDispNearObj = *pt_SITInput->t_RTE.pf_ObjLongDisp(t_NearObjNr); /* Longitudinal displacement of object */
        u_NearObjQuality = pt_SITInput->t_RTE.pu_AccObjQuality(t_NearObjNr); /* ACC object quality */
        t_NearObjDynProp = *pt_SITInput->t_RTE.pt_ObjDynProperty(t_NearObjNr); /* Dynamic property of object */
        f_ObjLatDispNearObj = *pt_SITInput->t_RTE.pf_ObjLatDisp(t_NearObjNr); /* Lateral displacement of object */

        if (t_NearObjNr != t_ObjNr)
        {
          /* Search for objects that is close to the object under investigation */
          if (((f_ObjLongDispNearObj) <= ((f_ObjLongDispObj) + SIT_O2O_SECONDARY_OBJ_SEARCH_DEFAULT_LENGTH))
            && ((f_ObjLongDispNearObj) >= ((f_ObjLongDispObj) - SIT_O2O_SECONDARY_OBJ_SEARCH_DEFAULT_LENGTH))
            && ((u_NearObjQuality) >= (FUN_PRESEL_ACC_MIN_OBJ_QUAL))
            && ((t_NearObjDynProp) != (ARS_OBJECT_PROPERTY_ONCOMING)) )
          {
            if (f_ObjLatDispNearObj > f_ObjLatDispObj)
            {
              /* Secondary objects are to the left of the primary object */
              if (t_SIT_O2O_ObjRoadBorderData[t_ObjNr].t_NearObjIDLeft[0] == OBJ_INDEX_NO_OBJECT)
              {
                t_SIT_O2O_ObjRoadBorderData[t_ObjNr].t_NearObjIDLeft[0] = t_NearObjNr;
                pt_SITOutput->t_ObjList[t_ObjNr].t_SIT_O2O_Analysis.t_NearObjIDLeft[0] = t_NearObjNr;
              }
              else if (t_SIT_O2O_ObjRoadBorderData[t_ObjNr].t_NearObjIDLeft[1] == OBJ_INDEX_NO_OBJECT)
              {
                t_SIT_O2O_ObjRoadBorderData[t_ObjNr].t_NearObjIDLeft[1] = t_NearObjNr;
                pt_SITOutput->t_ObjList[t_ObjNr].t_SIT_O2O_Analysis.t_NearObjIDLeft[1] = t_NearObjNr;
              }
              else if (t_SIT_O2O_ObjRoadBorderData[t_ObjNr].t_NearObjIDLeft[2] == OBJ_INDEX_NO_OBJECT)
              {
                t_SIT_O2O_ObjRoadBorderData[t_ObjNr].t_NearObjIDLeft[2] = t_NearObjNr;
                pt_SITOutput->t_ObjList[t_ObjNr].t_SIT_O2O_Analysis.t_NearObjIDLeft[2] = t_NearObjNr;
              }
              else
              {
                /* do nothing */
              }
            }
            else
            {
              /* Secondary object is to the right of the object */
              if (t_SIT_O2O_ObjRoadBorderData[t_ObjNr].t_NearObjIDRight[0] == OBJ_INDEX_NO_OBJECT)
              {
                t_SIT_O2O_ObjRoadBorderData[t_ObjNr].t_NearObjIDRight[0] = t_NearObjNr;
                pt_SITOutput->t_ObjList[t_ObjNr].t_SIT_O2O_Analysis.t_NearObjIDRight[0] = t_NearObjNr;
              }
              else if (t_SIT_O2O_ObjRoadBorderData[t_ObjNr].t_NearObjIDRight[1] == OBJ_INDEX_NO_OBJECT)
              {
                t_SIT_O2O_ObjRoadBorderData[t_ObjNr].t_NearObjIDRight[1] = t_NearObjNr;
                pt_SITOutput->t_ObjList[t_ObjNr].t_SIT_O2O_Analysis.t_NearObjIDRight[1] = t_NearObjNr;
              }
              else if (t_SIT_O2O_ObjRoadBorderData[t_ObjNr].t_NearObjIDRight[2] == OBJ_INDEX_NO_OBJECT)
              {
                t_SIT_O2O_ObjRoadBorderData[t_ObjNr].t_NearObjIDRight[2] = t_NearObjNr;
                pt_SITOutput->t_ObjList[t_ObjNr].t_SIT_O2O_Analysis.t_NearObjIDRight[2] = t_NearObjNr;
              }
              else
              {
                /* do nothing */
              }
            }
          }
        }
      }
    }
  }
}
///@}
#endif /* END IF SIT_O2O_ANALYSIS */
#endif /* END IF FCT_CFG_ACC_SITUATION */
/* ************************************************************************* */
/*   Copyright ADC-GmbH, Lindau                                              */
/* ************************************************************************* */
