/*! \file **********************************************************************

COMPANY:                   COPYRIGHT (C) Continental AG

PROJECT:                   Adaptive Cruise Control (ACC)

CPU:                       CPU-Independent

COMPONENT:                 SLATE_OOI (Object of Interest selection)

MODULNAME:                 ooi_select_oncoming.c
  
DESCRIPTION:               This module inherits the algorithms for selecting oncoming
                           objects for ACC function.


AUTHOR:                    Fridolin Kolb

CREATION DATE:             06.12.2007

  VERSION:                   $Revision: 1.14 $

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
@defgroup ooi_select_oncoming Oncoming objects
@ingroup ooi
@brief          This module inherits the algorithms for selecting Oncoming objects for
                ACC function which is closer to the ego vehicle. \n\n
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


/*************************************************************************************************************************
  Functionname:    OOI_v_SelectOncomingObject                                                                           */ /*!

  @brief           This function handles the selection of the oncoming objects for the six object of interest (OOI) interface

  @description     This function handles the selection of the oncoming objects for the six object of interest (OOI) interface.
                   An oncoming object is selected if no other moving or stationary object is found in the asked OOI position.
                   - Set lane which has to be considered
                   - Check for oncoming objects: Oncoming object mustn't be crossing, 
                     it has to be on the considered lane and it has to be the longitudinal closest oncoming object. 
                     Only consider objects not yet selected as OOI.
                   If another object (stationary or moving) was already selected, choose the closer object.
					
					@startuml
						Start
							Partition OOI_SelectOncomingObject {
								- Determine the Lane based on the OOI-position for object selection
								If (OOI-position for object selection is occluded or hidden by OOI0) then (TRUE)
									: Associated Lane is EGO;
								Else if (OOI-position is for object selection is next longitudinal left OOI or next lateral left OOI) then (TRUE)
									: Associated Lane is LEFT;
								Else (FALSE)
									: Associated Lane is RIGHT;
								Endif

								repeat
									if(object is oncoming) then (TRUE)
										if (object is non-crossing) then (TRUE)							
											if (the object is associated with the given lane) then (TRUE)
												if(Objects are not selected as OOI object) then (TRUE)
													if (oncoming object is found) then (TRUE)
														if (new object is closer than prior selected oncoming object) then (TRUE)
															- select the closer object as oncoming object
														Else (FALSE)
															- Do nothing
														Endif
													Else (FALSE)
														- select the new object as oncoming object
													Endif
												Else (FALSE)
													-Do nothing
												Endif 
											Else (FALSE)
												-Do nothing
											Endif
										Else (FALSE)
											-Do nothing
										Endif
									Else (FALSE)
										-Do nothing
									Endif 
								repeat while (go through the entire object list)

								If (Oncoming object is found) then (TRUE)
									If (Moving and Stationary object already selected) then (TRUE)
										If (oncoming object distance is closer than the previously slected object) then (TRUE)
											: Set oncoming object as OOI;
										Else
											: Do nothing;
										Endif 
									Else (FALSE)
										: Set oncoming object as OOI;
									Endif 
								Else (FALSE)
									: Do nothing;
								Endif
							}
						stop
					@enduml
		
  @return          -

  @param[in,out]   pNewObjId : Pointer to currently selected object ID for the given 'eRelObjType' OOI-position 
                               [0u ... EM_N_OBJECTS-1]
                               In case of an oncoming object selection, the object ID pNewObjId is overwritten.
  @param[in]       eRelObjType : Enumerator specifying the OOI-position for object selection                                [Full range of datatype eObjOOI_t as defined in Rte_Type.h]
  
  @glob_in         *SLATE_pt_GetObjDynProperty(i) : Dynamic property of an object i                                                [Full range of datatype SLATE_t_Obj_DynamicProperty as in Rte_Type.h] 
                                             with i [0u ... EM_N_OBJECTS-1]
  @glob_in         *SLATE_pt_GetObjDynSubProperty(i) : Dynamic property of an object i                                            [Full range of datatype SLATE_t_Obj_DynamicProperty as in Rte_Type.h]
                                                 with i [0u ... EM_N_OBJECTS-1]
  @glob_in         pt_OOI_Input : Reference to OOI input data structure                                                     
                      t_LAInput.pf_ObjToRefDistMeas(i) : Pointer to object to reference distance measurement                [-PI/2*RW_FCT_MAX ... PI/2*RW_FCT_MAX] m
                                                         with i [0u ... EM_N_OBJECTS-1]
  @glob_in         OBJ_GET_FUNC_LANE(i) : Functional lane association of an object i                                        [Full range of datatype eAssociatedLane_t as in Rte_Type.h]
                                          with i in [0u ... EM_N_OBJECTS-1]
  @glob_in         t_OOI_ObjectList[i].t_Bool.SelectedAsOOI : Bit if object i is selected as OOI                            [0u, 1u]
                                                              with i in [0u ... EM_N_OBJECTS-1]
  @glob_in         *pt_OOIInput->t_RTE.pf_ObjLongDisp(i) : Longitudinal displacement of object i                                         [-5*RW_FCT_MAX ... +5*RW_FCT_MAX]
                                              with i in [0u ... EM_N_OBJECTS-1]
  @glob_out        t_OOI_ObjectList[i].t_Bool.SelectedAsOOI : Bit if object i is selected as OOI                            [0u, 1u]
                                                              with i in [0u ... EM_N_OBJECTS-1]

  @c_switch_part   FCT_CFG_ACC_LANE_ASSOCIATION     : FCT support for ACC LA (Lane Association) sub-component
  @c_switch_full   FCT_CFG_ACC_OOI                  : Configuration switch to configure OOI sub-component for FCT_ACC
  
  @pre             Lane association of the objects has to be finished for the current cycle
  @post            -

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @created         -
  @changed         3/4/2016

  @author          Fridolin Kolb
*************************************************************************************************************************/
void OOI_v_SelectOncomingObject(ObjNumber_t * const pNewObjId, OOI_RelObjEnum_t eRelObjType)
{
  ObjNumber_t i;
  ObjNumber_t iOncomeObj = OBJ_INDEX_NO_OBJECT;
  eAssociatedLane_t Lane;
  SLATE_t_Obj_DynamicProperty t_ObjDynProperty;
  float32 f_ObjLongDisp;
  float32 f_OncomeObjLongDisp;
  float32 fObjLongDisp;
  float32 fOncomeObjLongDisp;
  
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

  /* Check for oncoming objects */
  for (i = (ObjNumber_t)(EM_N_OBJECTS - 1); i>= 0; i--)
  {
    t_ObjDynProperty = *SLATE_pt_GetObjDynProperty(i);
    if( t_ObjDynProperty == SLATE_OBJECT_PROPERTY_ONCOMING)
    {
      /* crossing traffic already selected as moving object !!!! */
#if (FCT_USE_EM_ARS_TECH_OBJECT_LIST)
      SLATE_t_Obj_DynamicSubProperty t_ObjDynSubProperty = *SLATE_pt_GetObjDynSubProperty(i);
      if (t_ObjDynSubProperty != SLATE_OBJECT_SUBPROP_CROSSING)
      {
#endif
        if((pt_OOI_Input->t_LAInput.pt_LAObjectList(i)->ObjFuncLane == Lane)
           &&(pt_OOI_Input->t_LAInput.pt_LAObjectList(i)->ObjFuncLane != ASSOC_LANE_UNKNOWN)
          )
        {
          /* Only consider objects not yet selected as OOI */
          if (t_OOI_ObjectList[i].t_Bool.SelectedAsOOI == FALSE)
          {
            /* If we already have a prior selected oncoming object, check if the
            new object has a higher priority (closer X distance), and only replace
            it if it does. Otherwise if no oncoming object selected so far, then
            always take the new one */
            if (iOncomeObj >= 0)
            {
              f_ObjLongDisp = *pt_OOI_Input->t_RTE.pf_ObjLongDisp(i);
              f_OncomeObjLongDisp = *pt_OOI_Input->t_RTE.pf_ObjLongDisp(iOncomeObj);
              if (f_ObjLongDisp <  f_OncomeObjLongDisp)
              {
                iOncomeObj = i;
              }
            }
            else
            {
              iOncomeObj = i;
            }
          }
        }
#if (FCT_USE_EM_ARS_TECH_OBJECT_LIST)
      }
#endif
    } 
  }

  /* check if the loop over all objects selected an oncoming object */
  if(iOncomeObj >= 0)
  {
    /* Check, if previous algorithms for moving and stationary object already selected an object */
    if (*pNewObjId >= 0)
    {
      /* Verify that oncoming traffic closer than previously selected one */
      fObjLongDisp = *pt_OOI_Input->t_RTE.pf_ObjLongDisp(*pNewObjId);
      fOncomeObjLongDisp = *pt_OOI_Input->t_RTE.pf_ObjLongDisp(iOncomeObj);
      if (fObjLongDisp > fOncomeObjLongDisp)
      {
        /* Replace previously selected stationary/moving with oncoming object */
        t_OOI_ObjectList[*pNewObjId].t_Bool.SelectedAsOOI = 0u;
        *pNewObjId = iOncomeObj;
        t_OOI_ObjectList[iOncomeObj].t_Bool.SelectedAsOOI = 1u;
      }
    }
    else
    {
      *pNewObjId = iOncomeObj;
      t_OOI_ObjectList[iOncomeObj].t_Bool.SelectedAsOOI = 1u;
    }
  }
}
/** @} end defgroup ooi*/
#endif /* (FCT_CFG_ACC_OOI) */
 
/* ************************************************************************* */
/*   Copyright ADC-GmbH, Lindau                                              */
/* ************************************************************************* */

