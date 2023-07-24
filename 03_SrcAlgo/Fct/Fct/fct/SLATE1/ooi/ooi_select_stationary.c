/*! \file **********************************************************************

COMPANY:                   COPYRIGHT (C) Continental AG

PROJECT:                   Adaptive Cruise Control (ACC)

CPU:                       CPU-Independent

COMPONENT:                 SLATE_OOI (Object of Interest selection)

MODULNAME:                 ooi_select_stationary.c
    
DESCRIPTION:               This module inherits the algorithms for selecting stationary
                           objects for ACC function.


AUTHOR:                    Fridolin Kolb

CREATION DATE:             23.08.2007

VERSION:                   $Revision: 1.13 $

LEGACY VERSION:            Revision: 2.1

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
@defgroup ooi_select_stationary Stationary objects
@ingroup ooi
@brief          This module inherits the algorithms for selecting stationary
                           objects for ACC function. \n\n
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

static ObjNumber_t OOI_t_SelectNextStatObjForLane( eAssociatedLane_t Lane );

/*************************************************************************************************************************
  Functionname:    OOI_v_SelectStationaryObject                                                                         */ /*!

  @brief           This function handles the selection of the stationary object for the six object of interest (OOI) interface

  @description     This function handles the selection of the stationary object for the six object of interest (OOI) interface 
                      - Set lane which has to be considered
                      - Select next stationary object for given lane
                      - If both stationary and moving object were found, select the closer object
                      - In case of LA_CFG_NBS_DIAGNOSE_TEST, reset the selection of the stationary object
					  
		@startuml
			Start
			Partition OOI_v_SelectStationaryObject {
			- Determine the Lane based on the OOI-position for object selection
			If (OOI-position for object selection is occluded or hidden by OOI0) then (true)
							: Associated Lane is EGO;
					Else if (OOI-position is for object selection is next longitudinal left OOI or next lateral left OOI) then (true)
					: Associated Lane is LEFT;
			Else (false)
					: Associated Lane is RIGHT;
			Endif
			- Select next stationary object for the given lane;
			If (NBS Diagnose test is Enabled) then (true)
				If (ABA_TEST_MODE is active) then (true)
					If (Stationary object is present) then (true)
						: reset the selection of the stationary object;
					Else (false)
						: Do nothing;
					Endif
				Endif
			Endif
			Partition OOI_CFG_STAT_OBJ_FROM_GUARDRAIL_SUPRESS {
				: Updates a counter if a moving object is detected in OOI0 position for consecutive cycles;
		}
			If (New Moving object is found) then (true)
				If (Stationary object is found) then (true)
					If (Stationary object displacement is closer than Moving object displacement)then (true)
						If(Stationary Object is closer than moving Object)
							: Set Stationary object as OOI;
							Note left
								Take Stationary and release Moving Object as OOI
								First Unselect Old Object
								Store New Object ID in location pointed by caller
								Set the new Object’s selection marks
							End Note
						Endif
					Else (false)
						- moving object is closer, so keep it
					Endif  
				Else
					: No stationary object found, so keep moving object;
				Endif 
			Else (false)
				: no moving object found;
				If (Stationary object is found) then (true)
					: Set Stationary object as OOI;
					Note left
					Moving object is not found and only Stationary object is found
					End note
				Else
					: no object found at all, Do nothing;
				Endif
			Endif
		}
		stop
		@enduml

  @return          -

  @param[in,out]   pNewObjId : ID of the already selected moving object in the current cycle [0u ... EM_N_OBJECTS-1] for the OOI-position 'eRelObjType'. 
                               In case of a closer stationary object, the object ID pNewObjId is overwritten.
                               Note: The ID itself may be negative to indicate no object selected yet. If this function selects an object it writes it into the pointed OOI position.
  @param[in]       eRelObjType : Enumerator specifying the OOI-position for object selection.                               [Full range of datatype eObjOOI_t as defined in Rte_Type.h]
  
  @glob_in         FCT_BSW_ALGO_PARAM_PTR->Fct.General.FnSwitchBits : Coding paramter indicating if ABA_TEST_MODE is active [Full range of datatype FnSwitchBits_t as defined in Rte_Type.h]
  @glob_in         SLATE_b_GetObjIsMovingToStationary(i) : Boolean, if a stationary object i was seen moving                       [TRUE, FALSE]
                                                     with i in [0u ... EM_N_OBJECTS-1]
  @glob_in         *pt_OOIInput->t_RTE.pf_ObjLongDisp(i) : Longitudinal displacement of an object i                                      [-5*RW_FCT_MAX ... 5*RW_FCT_MAX] m
                                              with i in [0u ... EM_N_OBJECTS-1]
  @glob_out        t_OOI_ObjectList[i].t_Bool.SelectedAsOOI : Bit, if an object i is selected as OOI                        [0u, 1u]
                                                              with i in [0u ... EM_N_OBJECTS-1]

  @c_switch_part   LA_CFG_NBS_DIAGNOSE_TEST : Configuration switch for enabling NBS Diagnose Test.
  @c_switch_full   FCT_CFG_ACC_OOI          : Configuration switch to configure OOI sub-component for FCT_ACC

  @pre             Lane association of the objects has to be finished for the current cycle
  @post            -

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @created         -
  @changed         3/23/2016

  @todo            -

  @author          Robert Thiel / Fridolin Kolb
*************************************************************************************************************************/
void OOI_v_SelectStationaryObject(ObjNumber_t * const pNewObjId, OOI_RelObjEnum_t eRelObjType)
{
  ObjNumber_t SiIndexStehend;
  eAssociatedLane_t Lane;
  float32 f_ObjLongDisp;
  float32 f_SiIndexObjLongDisp;

  /* Look for stationary objects */

  /* Determine Lane */
  if (eRelObjType <= OBJ_HIDDEN_NEXT_OOI)
  {
    Lane = ASSOC_LANE_EGO;
  }
  else if ((eRelObjType == OBJ_NEXT_LONG_LEFT_OOI) || (eRelObjType == OBJ_NEXT_LAT_LEFT_OOI))
  {
    Lane = ASSOC_LANE_LEFT;
  }
  else
  {
    Lane = ASSOC_LANE_RIGHT;
  }

  /* Select next stationary object for given lane */
  SiIndexStehend = OOI_t_SelectNextStatObjForLane(Lane);


#if (LA_CFG_NBS_DIAGNOSE_TEST)
  /* ABA_EOL_MODE should just report on moving or stopped objects. Therefore, check if
     any stationary objects are found and remove the index if needed  */
  if (FCT_BSW_ALGO_PARAM_PTR->Fct.General.FnSwitchBits == FN_AP_BIT_ABA_TEST_MODE)
  {
    /* Check if stationary object present */
    if((SiIndexStehend >= 0 ) 
      &&
      (SLATE_b_GetObjIsMovingToStationary(SiIndexStehend) == FALSE))
    {
      SiIndexStehend = OBJ_INDEX_NO_OBJECT;
    }
  }
#endif

#if (OOI_CFG_STAT_OBJ_FROM_GUARDRAIL_SUPRESS)
    OOI_v_UpdateMovingObjectCounter( pNewObjId, eRelObjType);
#endif 

  /* Note: detailed comparison of the old complex code showed that tracking the OOI object
  states with a state machine was completely overblown as each state had the same logic (but
  in different order of evaluation, which in this context has no influence) */
  if (*pNewObjId >= 0)/* moving object found */
  {
    if (SiIndexStehend >= 0)/* stationary object found */
    {
      /* Both stationary and moving object were found : select the closer one */
      f_ObjLongDisp = *pt_OOI_Input->t_RTE.pf_ObjLongDisp( *pNewObjId);
      f_SiIndexObjLongDisp = *pt_OOI_Input->t_RTE.pf_ObjLongDisp(SiIndexStehend);
      if ( f_ObjLongDisp > f_SiIndexObjLongDisp)
      {

#if (OOI_CFG_STAT_OBJ_FROM_GUARDRAIL_SUPRESS)
        if (OOI_b_CheckPartofGaurdRail(eRelObjType) != FALSE)
        {
#endif
          /* if stationary object is closer than moving object, take stationary and release
              moving object as OOI, first unselect old object */
          t_OOI_ObjectList[*pNewObjId].t_Bool.SelectedAsOOI = 0u;
          /* Store new object ID in location pointed to by caller */
          *pNewObjId = SiIndexStehend;
          /* And set the new object's selection marks */  
          t_OOI_ObjectList[SiIndexStehend].t_Bool.SelectedAsOOI = 1u;
#if (OOI_CFG_STAT_OBJ_FROM_GUARDRAIL_SUPRESS)
        }
#endif
      }
      else
      {
        /* moving object is closer, so keep it */
      }
    }
    else
    {
      /* no stationary object found, so keep moving object */
    }
  }
  else /* no moving object found */
  {
    if (SiIndexStehend >= 0)/* stationary object found */
    {
#if (OOI_CFG_STAT_OBJ_FROM_GUARDRAIL_SUPRESS)
      if (OOI_b_CheckPartofGaurdRail(eRelObjType) != FALSE)
      {
#endif
        /* Take stationary object */
        *pNewObjId = SiIndexStehend;
        t_OOI_ObjectList[SiIndexStehend].t_Bool.SelectedAsOOI = 1u;
#if (OOI_CFG_STAT_OBJ_FROM_GUARDRAIL_SUPRESS)
      }
#endif
    }
    else
    {
      /* no object found at all, do nothing */
    }
  }
}



/*************************************************************************************************************************
  Functionname:    OOI_t_SelectNextStatObjForLane                                                                       */ /*!

  @brief           Select next stationary object for given lane

  @description     Select next stationary object for given lane if
                    - the object is stationary 
                    - the object is non-crossing 
                    - the object is the next longitudinal stationary object
                    - the object is in the given lane, 
                    - the object has not yet been selected as OOI object (t_OOI_ObjectList[i].t_Bool.SelectedAsOOI not set).

		@startuml
		Start
			Partition OOI_t_SelectNextStationaryObjectForLane {
				Repeat
					If (object is stationary) then (true)
						If (object dynamic sub property != SLATE_OBJECT_SUBPROP_CROSSING or OOI Object is OOI-0 or OOI-2 or OOI-3) then (true)
							If (Check if objects were assigned the lane) then (true) 	
								If(Object is already not OOI object) then (true)
									If (Number of Stationary Objects >= 0) then (yes)
										If (Object Longitudinal Displacement < Stationary Object Longitudinal Displacement) then (yes)	
											:Given object is closest stationary object;
										Endif
									Else (no)
										: Given object is closest stationary object;	
									Endif
								Endif
							Endif
						Endif
					Endif
				repeat while (go through the entire object list)
			}
		Stop
		@enduml

  @return          iStatObj : The object ID of the selected stationary non-crossing object           [OBJ_INDEX_NO_OBJECT ... EM_N_OBJECTS-1]

  @param[in]       Lane : The lane for which the selection shall take place                          [Full range of datatype eAssociatedLane_t as in Rte_Type.h]
  @param[out]      -

  @glob_in         *SLATE_pt_GetObjDynProperty(i) : Dynamic property of an object i                         [Full range of datatype SLATE_t_Obj_DynamicProperty as in Rte_Type.h]
                                             with i in [0u ... EM_N_OBJECTS-1]
  @glob_in         *SLATE_pt_GetObjDynSubProperty(i) : Dynamic sub property of an object i                 [Full range of datatype SLATE_t_Obj_DynamicProperty as in Rte_Type.h]
                                                 with i in [0u ... EM_N_OBJECTS-1]
  @glob_in         t_OOI_LastCycleOOIObjID[i] : Array representing 6-OOI Object IDs of last cycle    [0u ... EM_N_OBJECTS-1]
                                                with i in [0u ... OOI_NUMBER_OF_OOI] and OOI_NUMBER_OF_OOI in ooi_ext.h
  @glob_in         OBJ_GET_FUNC_LANE(i) : Functional lane association of the given object i          [Full range of datatype eAssociatedLane_t as in Rte_Type.h]
                                          with i in [0u ... EM_N_OBJECTS-1]
  @glob_in         t_OOI_ObjectList[i].t_Bool.SelectedAsOOI : Bit, if an object i is selected as OOI [0u, 1u]
                                                              with i in [0u ... EM_N_OBJECTS-1]
  @glob_in         *pt_OOIInput->t_RTE.pf_ObjLongDisp(i) : Longitudinal displacement of an object i               [-5*RW_FCT_MAX ... 5*RW_FCT_MAX] m
                                              with i in [0u ... EM_N_OBJECTS-1]
  @glob_in         OBJ_GET_ID_I(i) : ID of object i                                                  [0u ... EM_N_OBJECTS-1]
                                     with i in [0u ... EM_N_OBJECTS-1]
  @glob_out        -

  @c_switch_part   -
  @c_switch_full   FCT_CFG_ACC_OOI : Configuration switch to configure OOI sub-component for FCT_ACC

  @pre             -
  @post            -

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @created         -
  @changed         3/23/2016

  @todo            -

  @author          Fridolin Kolb
*************************************************************************************************************************/
static ObjNumber_t OOI_t_SelectNextStatObjForLane( eAssociatedLane_t Lane )
{
  ObjNumber_t i;
  ObjNumber_t iStatObj = OBJ_INDEX_NO_OBJECT;
  SLATE_t_Obj_DynamicProperty t_ObjDynProperty;
  float32 f_Obj_LongDisp;
  float32 f_StatObjLongDisp;

  /* Go through entire object list */
  for (i = (ObjNumber_t)(EM_N_OBJECTS - 1); i>= 0; i--)
  {
    /* This is for selection of stationary objects, thus only take those; but only if objects were not seen as oncoming and stationary only */
    t_ObjDynProperty = *SLATE_pt_GetObjDynProperty(i);
    if ( (t_ObjDynProperty == SLATE_OBJECT_PROPERTY_STATIONARY)
#if (FCT_CFG_SENSOR_TYPE_CAMERA)
      || (t_ObjDynProperty == SLATE_OBJECT_PROPERTY_STOPPED)
#endif /* FCT_CFG_SENSOR_TYPE_CAMERA */
      )
    {
      /* The stationary classified objects shall not be crossing; if 
        the object was aleady OBJ_NEXT_OOI, OBJ_NEXT_LONG_LEFT_OOI, OBJ_NEXT_LONG_RIGHT_OOI, 
        also consider crossing stationary objects due to a toggling false crossing  
        classification of stationary objects */
#if (FCT_USE_EM_ARS_TECH_OBJECT_LIST)
      SLATE_t_Obj_DynamicSubProperty t_ObjDynSubProperty = *SLATE_pt_GetObjDynSubProperty(i);
#endif
      if ( 
#if (FCT_USE_EM_ARS_TECH_OBJECT_LIST)	
           (t_ObjDynSubProperty != SLATE_OBJECT_SUBPROP_CROSSING) || 
#else /* !FCT_USE_EM_ARS_TECH_OBJECT_LIST */
        (TRUE) || /* Object is crossing or stopped, not crossing */
#endif /* !FCT_USE_EM_ARS_TECH_OBJECT_LIST */
           (t_OOI_LastCycleOOIObjID[OBJ_NEXT_OOI] == i) ||
           (t_OOI_LastCycleOOIObjID[OBJ_NEXT_LONG_LEFT_OOI] == i) ||
           (t_OOI_LastCycleOOIObjID[OBJ_NEXT_LONG_RIGHT_OOI] == i)
         )
      {
        /* Only take objects that were assigned the lane we are looking at */
        if (pt_OOI_Input->t_LAInput.pt_LAObjectList(i)->ObjFuncLane == Lane)
        {
          /* Only consider objects not already selected as OOI */
          if (t_OOI_ObjectList[i].t_Bool.SelectedAsOOI == FALSE)
          {
            if (iStatObj >= 0)
            {
              f_Obj_LongDisp = *pt_OOI_Input->t_RTE.pf_ObjLongDisp(i);
              f_StatObjLongDisp = *pt_OOI_Input->t_RTE.pf_ObjLongDisp(iStatObj);
              if ( f_Obj_LongDisp < f_StatObjLongDisp)
              {
                iStatObj = i;
              }
            }
            else
            {
              iStatObj = i;
            }
          }
        }
      }
    }
  }
  return( iStatObj );
}


/*****************************************************************************
  AUFHEBUNG MODULLOKALER SYMBOLISCHE KONSTANTEN
*****************************************************************************/
/** @} end defgroup ooi*/
#endif /* (FCT_CFG_ACC_OOI) */
/* ************************************************************************* */
/*   Copyright ADC-GmbH, Lindau                                              */
/* ************************************************************************* */

