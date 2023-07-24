/*! \file **********************************************************************

COMPANY:                   COPYRIGHT (C) Continental AG

PROJECT:                   Adaptive Cruise Control (ACC)

CPU:                       CPU-Independent

COMPONENT:                 SLATE_OOI (Object of Interest selection)

MODULNAME:                 ooi_select_moving.c
    
DESCRIPTION:               This module inherits the algorithms for selecting moving
                           objects for ACC function.


AUTHOR:                    Fridolin Kolb

CREATION DATE:             23.08.2007

  VERSION:                   $Revision: 1.17 $

LEGACY VERSION:            Revision: 2.2

**************************************************************************** */

/*****************************************************************************
  INCLUDES
*****************************************************************************/

#include "ooi.h"//PRQA S 0380
/* date: 2019-07-28, reviewer:Prabhu Sundaramurthy, reason: Arises due to inclusion of multiple header files in this header file which has multiple macros*/
#if (FCT_CFG_ACC_OOI)
/*****************************************************************************
  MODULE DESCRIPTION
*****************************************************************************/

/**
@defgroup ooi_select_moving Moving objects
@ingroup ooi
@brief          This module inherits the algorithms for selecting moving objects for ACC function
                which is closer to the ego vehicle. \n\n
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


/*****************************************************************************
  VARIABLES 
*****************************************************************************/


/*****************************************************************************
  FUNCTION 
*****************************************************************************/
static boolean OOI_b_CheckObjectDetected(const ObjNumber_t ObjId);
static boolean OOI_b_CheckObjectNextLong(const ObjNumber_t NewObjId, const ObjNumber_t OldObjId);
static boolean OOI_b_CheckObjectNextLat(const ObjNumber_t NewObjId, const ObjNumber_t OldObjId);


/*************************************************************************************************************************
  Functionname:    OOI_t_SelectNextObjectMoving                                                                         */ /*!

  @brief           This function selects a moving object in the given lane

  @description     This function selects a moving object in the given lane
                    - Check if object fulfills OOI_b_CheckObjectDetected, i.e. if it is moving and fulfills crossing conditions
                    - Check if object is on given lane
                    - Check conditions based on selection type (OOI_OBJ_SELECTION_NEXT_LONG, OOI_OBJ_SELECTION_NEXT_LATERAL)
                    - SelectedAsOOI is set
					
		@startuml
		Start
		Partition OOI_t_SelectNextObjectMoving {
		Repeat
			If (if Object is detected) then (true)
				If (Lane is in given associated lane) then (true)
					If (Object selection type is next longitudinal object) then (true)
						If (given object is nearest longitudinal object) then (true)
							- Select given object as nearest longitudinal object
						Endif
					Else if (Object selection type is next lateral object) then (true)
						If (given object is nearest lateral object) then (true)
							- Select given object as nearest lateral object
						Endif
					Else (false)
						- Do Nothing
					Endif
				Endif
			Endif
		Repeat While(for entire object list)
		If (object is selected as nearest object) then (true)
			- Object is candidate for OOI list
		Endif
		}
		End
		@enduml

  @return          returnObject : ID of object that is the next selected moving object           [OBJ_INDEX_NO_OBJECT ... EM_N_OBJECTS-1]

  @param[in]       Lane : Lane information on which lane the object is at                        [Full range of datatype eAssociatedLane_t as in Rte_Type.h]
  @param[in]       SelectionType : type of function that shall be analysed                       [Full range of datatype OOI_ObjSelectionType_t as in ooi.h]
  @param[out]      -

  @glob_in         OBJ_GET_FUNC_LANE(i) : Lane information on which lane the object i is         [Full range of datatype eAssociatedLane_t as in Rte_Type.h]
                                          with i in [0u ... EM_N_OBJECTS-1]
  @glob_out        t_OOI_ObjectList[i].t_Bool.SelectedAsOOI : Bit if object i is selected as OOI [0u, 1u]
                                                              with i in [0u ... EM_N_OBJECTS-1]
                   
  @c_switch_part   -
  @c_switch_full   FCT_CFG_ACC_OOI : Configuration switch to configure OOI sub-component for FCT_ACC

  @pre             Lane association of the objects has to be finished for the current cycle. Predicted distance to trajectory has to be computed.
  @post            -

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).
  
  @traceability    179:doors://rbgs854a:40000/?version=2&prodID=0&urn=urn:telelogic::1-503e822e5ec3651e-O-179-00061542 \n
                   180:doors://rbgs854a:40000/?version=2&prodID=0&urn=urn:telelogic::1-503e822e5ec3651e-O-180-00061542 \n
                   
  @created         -
  @changed         3/3/2016

  @author          Robert Thiel
*************************************************************************************************************************/
ObjNumber_t OOI_t_SelectNextObjectMoving(eAssociatedLane_t Lane, OOI_ObjSelectionType_t SelectionType)
{
  ObjNumber_t returnObject = OBJ_INDEX_NO_OBJECT;
  ObjNumber_t nr;
  boolean b_ObjectDetected;
  boolean b_ObjectNextLong;
  boolean b_ObjectNextLat;
  
  /*search for nearest object*/
  for(nr = (ObjNumber_t)(EM_N_OBJECTS - 1); nr >= (ObjNumber_t)0; nr--)
  {
    /*object available and usable for this function*/
    b_ObjectDetected = OOI_b_CheckObjectDetected(nr);
    if(b_ObjectDetected == TRUE)
    {
      /*check if the lane is the given lane*/
      if(pt_OOI_Input->t_LAInput.pt_LAObjectList(nr)->ObjFuncLane == Lane)
      {
        /*compare to returnObject using the right compare function*/
        switch(SelectionType)
        {
          /*return next longitudinal object*/
          case OOI_OBJ_SELECTION_NEXT_LONG:
            b_ObjectNextLong = OOI_b_CheckObjectNextLong(nr, returnObject);
            if(b_ObjectNextLong == TRUE)
            {
              returnObject = nr;
            }
              break;

          /*return next lateral object*/
          case OOI_OBJ_SELECTION_NEXT_LATERAL:
            b_ObjectNextLat = OOI_b_CheckObjectNextLat(nr, returnObject);
            if(b_ObjectNextLat == TRUE)
            {             
              returnObject = nr;
            }
            break;

          default:
            /*do nothing*/
            break;
        }
      }
    }
  }

  /*if object was found --> mark object as selected*/
  if(returnObject >= 0)
  {
    t_OOI_ObjectList[returnObject].t_Bool.SelectedAsOOI = 1u;
  }

  /*return the object if available*/
  return returnObject;
}


/*************************************************************************************************************************
  Functionname:    OOI_b_CheckObjectDetected                                                                            */ /*!

  @brief           This function checks if the object fulfills conditions for selection of moving objects

  @description     This function checks if the object fulfills conditions for selection of moving objects, i.e.
                      - if object is moving
                      - if object fulfills crossing conditions
                      - if object not OOI yet
					
		@startuml
		Start
		Partition OOI_b_CheckObjectDetected {
			If (the dynamic property of the object should not be equal to Crossing and within given distance threshold OOI_MAX_DIST_FOR_CROSSING_REPORT) then (true)
				If (Object is moving object or crossing object) then (true)
					If (Object is already not OOI) then (true)
						: moving object is candidate as OOI;
					Else (false)
						: Do nothing;
					Endif 
				Else (false)
					: Do nothing;
				Endif 
			Else (false)
				: Do nothing;
			Endif
			If (increased angle thresholds for object crossing detection switch is enabled) then (true)
				If (the object is crossing object and ego vehicle speed is zero)then (true)
					- object is not selected as OOI Object
						Note left: the object is not selected if is detected as crossing while the speed of the ego vehicle is zero
				Else (false)
					: DO nothing;
				Endif 
			Else (false)
				: Do nothing;
			Endif 
		}
		End 	
		@enduml


  @return          returnVal : Boolean if object shall be used for object selection                             [TRUE, FALSE]

  @param[in]       ObjId : Object-ID of object to be checked for object selection (has to be a valid object ID) [0u ... EM_N_OBJECTS-1]
  @param[out]      -

  @glob_in         *SLATE_pt_GetObjDynSubProperty(i) : Dynamic sub-property of object i                               [Full range of datatype SLATE_t_Obj_DynamicProperty as defined is Rte_Type.h]
                                                 with i in [0u ... EM_N_OBJECTS-1]
  @glob_in         *pt_OOIInput->t_RTE.pf_ObjLongDisp(i) : Longitudinal displacement of object i                             [-5*RW_FCT_MAX ... 5*RW_FCT_MAX] m
                                              with i in [0u ... EM_N_OBJECTS-1]
  @glob_in         *SLATE_pt_GetObjDynProperty(i) : Dynamic property of object i                                       [Full range of datatype SLATE_t_Obj_DynamicProperty as defined in Rte_Type.h]
                                             with i in [0u ... EM_N_OBJECTS-1]
  @glob_in         t_OOI_ObjectList[i].t_Bool.SelectedAsOOI : Bit if object i is selected as OOI                [0u, 1u]
                                                              with i in [0u ... EM_N_OBJECTS-1]

  @glob_out        -
                   
  @c_switch_part   OOI_CFG_OBJCROSSING_INCREASED_THRESHOLD: Config switch for using different thresholds to determine crossing objects
  @c_switch_full   FCT_CFG_ACC_OOI : Configuration switch to configure OOI sub-component for FCT_ACC

  @pre             Lane association of the objects has to be finished for the current cycle
  @post            -

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @traceability    437:doors://rbgs854a:40000/?version=2&prodID=0&urn=urn:telelogic::1-503e822e5ec3651e-O-437-00061542 \n

  @created         -
  @changed         3/3/2016

  @author          Robert Thiel
*************************************************************************************************************************/
static boolean OOI_b_CheckObjectDetected(const ObjNumber_t ObjId)
{
  boolean returnVal = FALSE;
  SLATE_t_Obj_DynamicProperty t_ObjDynProperty;
  const float32 f_ObjLongDisp = *pt_OOI_Input->t_RTE.pf_ObjLongDisp(ObjId);
#if (OOI_CFG_OBJCROSSING_INCREASED_THRESHOLD)
  float32 f_EgoVelObjSync;
#endif
#if (FCT_USE_EM_ARS_TECH_OBJECT_LIST)
  const SLATE_t_Obj_DynamicSubProperty t_ObjDynamicSubProperty = *SLATE_pt_GetObjDynSubProperty(ObjId);
#endif

  /* crossing traffic only in distances smaller OOI_MAX_DIST_FOR_CROSSING_REPORT ( defined in si_par.h) */
  if (
#if (FCT_USE_EM_ARS_TECH_OBJECT_LIST)
    ( t_ObjDynamicSubProperty != SLATE_OBJECT_SUBPROP_CROSSING) ||
#else
    (TRUE) || /* Temporary fix for Video ACC, if FCT_USE_EM_ARS_TECH_OBJECT_LIST is FALSE in order to select object as OOI at all */
#endif
     ( f_ObjLongDisp < OOI_MAX_DIST_FOR_CROSSING_REPORT))
  {
    /* select only moving objects in the same direction or crossing traffic*/
    t_ObjDynProperty = *SLATE_pt_GetObjDynProperty(ObjId);
    if(( t_ObjDynProperty == SLATE_OBJECT_PROPERTY_MOVING)
#if (FCT_USE_EM_ARS_TECH_OBJECT_LIST)
      ||( t_ObjDynamicSubProperty == SLATE_OBJECT_SUBPROP_CROSSING)
#endif
      )
    {
      /*check if object is not selected*/
      if(t_OOI_ObjectList[ObjId].t_Bool.SelectedAsOOI == FALSE)
      {
        returnVal = TRUE;
      }
    }
  }
#if (OOI_CFG_OBJCROSSING_INCREASED_THRESHOLD)
  /* the object is not selected if is detected as crossing while the speed of the ego vehicle is zero */
  f_EgoVelObjSync = CML_f_Abs(*pt_OOI_Input->t_RTE.pf_EgoVelObjSync);
  if ( (f_EgoVelObjSync <= CML_f_Delta) && (pt_OOI_Output->OOI_CrossingFlag[ObjId] == TRUE) )
  {
    returnVal = FALSE;
  }
#endif
  return returnVal;
}


/*************************************************************************************************************************
  Functionname:    OOI_b_CheckObjectNextLong                                                                            */ /*!

  @brief           Checks if new object is longitudinal closer to ego vehicle than old object

  @description     Checks if new object is longitudinal closer to ego vehicle than old object. 
                    Returns true if new object is closer to ego vehicle the old object
					
		@startuml
		Start 
		Partition OOI_b_CheckObjectNextLong {
			If (already exists a longitudinal Object) then (true)
				If (longitudinal distance of given object is closer to ego than distance to already existing object) then (true)
					- new object is closer than existing object and selected as next relevant longitudinal object;
				Else (false)
					- keep old object as next relevant longitudinal object;
				Endif 
			Else (false)
				- no longitudinal object exists and thus consider next relevant longitudinal object;
				Note left: if there is no old object selected then selecting the new object 
			Endif 
		}
		End 
		@enduml

  @return          returnVal : Boolean if new object is closer than old object [TRUE, FALSE]

  @param[in]       NewObjId : ID of possible new object to test  [0u ... EM_N_OBJECTS-1]
  @param[in]       OldObjId : ID of already selected object      [OBJ_INDEX_NO_OBJECT] 
  @param[out]      -

  @glob_in         *pt_OOIInput->t_RTE.pf_ObjLongDisp(i) : Longitudinal displacement of object i  [-5*RW_FCT_MAX ... 5*RW_FCT_MAX] m                                              
  @glob_out        -

  @c_switch_part   -
  @c_switch_full   FCT_CFG_ACC_OOI : Configuration switch to configure OOI sub-component for FCT_ACC

  @pre             NewObjId must be valid (must be non-negative)! OldObjectId may be invalid (negative)
  @post            -

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @created         -
  @changed         3/3/2016

  @author          Robert Thiel
*************************************************************************************************************************/
static boolean OOI_b_CheckObjectNextLong(const ObjNumber_t NewObjId, const ObjNumber_t OldObjId)
{
  boolean returnVal;
  returnVal = FALSE;

  if(OldObjId >= 0)
  {
    /*if distance to new object is shorter than distance to old object --> new object is more relevant*/
    if( *pt_OOI_Input->t_RTE.pf_ObjLongDisp(NewObjId) < *pt_OOI_Input->t_RTE.pf_ObjLongDisp(OldObjId))
    {
      returnVal = TRUE;
    }
  }
  else
  {
    /*no object was previously selected --> select new object*/
    returnVal = TRUE;
  }

  return returnVal;
}


/*************************************************************************************************************************
  Functionname:    OOI_b_CheckObjectNextLat                                                                             */ /*!

  @brief           Checks if the new object is lateral closer to ego vehicle than the old object based on a prediction time.

  @description     Checks if the new object is lateral closer to ego vehicle than the old object based on a prediction time.
                   Returns true if the new object is lateral closer to the ego vehicle than the old object
                   - Calculate predicted lateral displacement based on a prediction time
                   - Check which object is closer to ego vehicle
				   
		@startuml
		Start
		Partition OOI_b_CheckObjectNextLat {
		: Get distance to trajectory for new object;
		If (already an other object exists which is selected as nearest lateral object) then (true)
			If (distances are positive, i.e Left side case) then (true)
				If (Lateral displacement of new object is closer than distance to existing old object) then (true)
					: select new object as nearest relavant lateral object;
				Endif
			Else (false)
				If (Lateral displacement of new object is closer than distance to existing old object) then (true)
					: select new object as nearest relavant object;
				Endif
			Endif
		Else (false)
			: new object as relevant object;
		Endif
		}
		end
		@enduml

  @return          returnVal : Boolean if new object is lateral closer to the ego vehicle than old object [TRUE, FALSE]

  @param[in]       NewObjId : ID of possible new object to test                         [0u ... EM_N_OBJECTS-1]
  @param[in]       OldObjId : ID of already selected object                             [OBJ_INDEX_NO_OBJECT]
  @param[out]      -

  @glob_in         pt_OOI_Input : Reference to OOI input data structure                                                                            
                      t_LAInput.pf_ObjToRefDistMeas(i): Pointer to object to reference distance measurement                                        [-PI/2*RW_FCT_MAX ... PI/2*RW_FCT_MAX] m
                                                        with i in [0u ... EM_N_OBJECTS-1]
                      f_PredictedLatDispl[i]: Object predicted distance to trajectory [-PI/2*RW_FCT_MAX ... PI/2*RW_FCT_MAX] m
                                                        with i in [0u ... EM_N_OBJECTS-1]

                   
  @c_switch_part   FCT_CFG_ACC_LANE_ASSOCIATION : FCT support for ACC LA (Lane Association) sub-component
  @c_switch_full   FCT_CFG_ACC_OOI              : Configuration switch to configure OOI sub-component for FCT_ACC

  @pre             Lane association has to be finished for the current cycle
                   NewObjId must be valid (non-negative)!!!
                   OldObjectId may be invalid (negative)
  @post            -

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @created         -
  @changed         3/3/2016

  @author          Robert Thiel
*************************************************************************************************************************/
static boolean OOI_b_CheckObjectNextLat(const ObjNumber_t NewObjId, const ObjNumber_t OldObjId)
{
  float32 f_DistanceToTraj;
  boolean b_returnVal = FALSE;

  /* Get distance to trajectory for new object */
#if (FCT_CFG_ACC_LANE_ASSOCIATION)
  f_DistanceToTraj = *(pt_OOI_Input->t_LAInput.pf_ObjToRefDistMeas(NewObjId));
#else
  f_DistanceToTraj = *(pt_OOI_Input->t_RTE.pf_ObjLatDisp(NewObjId));
#endif

  /* Already object selected before? */
  if(OldObjId >= 0)
  {
    /* differ between left and right side case */
    if(f_DistanceToTraj > 0.0f)
    {
      /* In left side case, distances are positive, so closer distance is mathematically smaller */
      /*if lateral displacement to new object is shorter than distance to old object --> new object is more relevant*/
      if(pt_OOI_Output->f_PredictedLatDispl[NewObjId] < pt_OOI_Output->f_PredictedLatDispl[OldObjId] )
      {
        b_returnVal = TRUE;
      }
    }
    else
    {
      /* In right side case, distances are negative, so closer distance is mathematically bigger */
      /*if lateral displacement to new object is shorter than distance to old object --> new object is more relevant*/
      if(pt_OOI_Output->f_PredictedLatDispl[NewObjId]  > pt_OOI_Output->f_PredictedLatDispl[OldObjId])
      {
        b_returnVal = TRUE;
      }
    }
  }
  else
  {
    /*no previously object was selected --> select new object*/
    b_returnVal = TRUE;
  }
  return b_returnVal;
}
/** @} end defgroup ooi*/
#endif /* (FCT_CFG_ACC_OOI) */
/* ************************************************************************* */
/*   Copyright ADC-GmbH, Lindau                                              */
/* ************************************************************************* */

