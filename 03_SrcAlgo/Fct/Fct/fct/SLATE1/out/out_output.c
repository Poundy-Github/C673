/*! \file **********************************************************************

COMPANY:                   Continental Temic, PC DAS, A.D.C. GmbH

PROJECT:                   ARS3xx

CPU:                       CPU-Independent

COMPONENT:                 SLATE_OUT (Output)

MODULNAME:                 out_output.c

DESCRIPTION:               Generate outputs of OUT 

AUTHOR:                    R.Ehrhardt

CREATION DATE:             17.10.01

VERSION:                   $Revision: 1.55 $

LEGACY VERSION:            Revision: 2.2.1.1

**************************************************************************** */


/*****************************************************************************
  INCLUDES
*****************************************************************************/
#include "out_custom.h"//PRQA S 0380
/* date: 2019-07-28, reviewer:Prabhu Sundaramurthy, reason: Arises due to inclusion of multiple header files in this header file which has multiple macros*/
#include "out.h"
/*****************************************************************************
  MODULE DESCRIPTION
*****************************************************************************/

/**
@defgroup out_output Output
@ingroup out
@brief          This module generates the outputs for OUT module. \n\n
@{
*/
#if (FCT_CFG_ACC_OUTPUT)

#if (SLATE_CFG_USE_EXT_OBJ_ID)
#include "slate_calc_ext_obj_id.h"
#endif

#ifdef FCT_SIMU
#ifndef __PDO__
#include <string.h>
#endif /* #ifndef __PDO__ */
#endif  /* FCT_SIMU */

/*****************************************************************************
  MODULGLOBALE KONSTANTEN
*****************************************************************************/

/*****************************************************************************
  MODULLOKALE TYPEDEFS 
*****************************************************************************/

/*****************************************************************************
  MODULGLOBALE VARIABLEN
*****************************************************************************/


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
/*! Minimum lane change time gap probability based on the input signals
    turn signal indicator and lane matrix */
#define OUT_LC_MIN_TI_TIMEGAP_PROB (60)

/*****************************************************************************
  MODULLOKALE TYPEDEFS 
*****************************************************************************/


/*****************************************************************************
  MODULLOKALE VARIABLEN
*****************************************************************************/

static ObjNumber_t iTRCKGetracktesObjekt;

/*****************************************************************************
  FUNCTION PROTOTYPES
*****************************************************************************/

#if (FCT_CFG_SEN2VEH_ACC_OOI_PORT)
static void OUT_v_FillOOIKinematic(const ObjNumber_t ObjId, AccOOIGenKinematics_t* pKinematic);
static void OUT_v_FillOOIAttributes(const ObjNumber_t ObjId, const eObjOOI_t eObjOOI, AccOOIGenAttributes_t* pAttributes);
static void OUT_v_DeleteOOIData(AccOOIGenKinematics_t* pKinematic, AccOOIGenAttributes_t* pAttributes);
#if (OUT_CFG_OVERTAKE_PREVENTION_FEATURE)
static void OUT_v_SetPreventOvertake(void);
#endif /* OUT_CFG_OVERTAKE_PREVENTION_FEATURE */
#endif /* ENDIF FCT_CFG_SEN2VEH_ACC_OOI_PORT */


#if (FCT_MEASUREMENT)
/*************************************************************************************************************************
  Functionname:    OUT_v_FreezeData                                                                                     */ /*!

  @brief           This function generates measurement output data from the OUT (6 objects)

  @description     This function generates measurement output data from the OUT (6 objects). LA, FIP, OOI and SIT access functions 
                   are used directly since output freeze functions are called outside the switch {STATE_OK, STATE_INIT} and inputs
                   to OUT module are initialized in STATE_INIT

				   @startuml
                   Partition OUT_v_FreezeData{
                   Start
                   Repeat
                   : Get Object ID;
                   If (Object ID is Greater) then (TRUE)
                   : Get Object Associated Lane, class, type;
                   If (Object number greater Object Hidden Next OOI) then (TRUE)
                   : cut-out potential for inlane ones;
                   Else (FALSE)
                   : cut-in potential for outlane objects;
                   Endif
                   : Get data for moving object is stationary;
                   If (moving object is stationary) then (TRUE)
                   : Object is stopped;
                   Else (FALSE)
                   : object is not stopped;
                   Endif
                   : Get external object ID;
                   Partition #LightBlue FCT_CFG_CAMERA_OBJECT_DETECTION {
                   : Fill in camera association related fields;
                   : If mobil-eye raw input data supplied, then fill in camera object position information;
                   }
                   : Get Predicted lateral displacement from ego course;
                   : Get Distance of object in X and Y direction;
                   : Get Object's relative acceleration in X direction;
                   : Get Object's relative speed in X direction;
                   Partition #LightBlue FCT_CFG_ACC_LANE_ASSOCIATION {
                   : Get Object's relative speed in X direction;
                   }
                   Partition #LightBlue FCT_CFG_ACC_LANE_ASSOCIATION {
                   : Get left and right trace bracket offset to course estimation;
                   }
                   Else (FALSE)
                   : Initialize all object data;
                   Endif
                   Repeat while (Object number greater than OBJ_NEXT_LAT_RIGHT_OOI)
                   End
                   }
                   @enduml

  @return          -

  @param[in]       pMeasObjs  [Full range of structure of datatype OUT_t_Meas as defined in out_ext.h]
  @param[out]      -

  @glob_in         OBJ_GET_OOI_LIST_OBJ_IDX(  ) : Accessing ACC Assessed Object List object of interest array         [0u   39u]
  @glob_in         pt_OUTInput->t_FIPInput.pt_CamConfirmationProb(i) :        [0u ... 100u]
  @glob_in         pt_OUTInput->t_FIPInput.pt_AssignedLaneQual(i)             [0u ... 100u]
  @glob_in         pt_OUTInput->t_FIPInput.pt_eAssociatedLane(i)              [type eAssociatedLane as defined in Rte_Type.h]
  @glob_in         pt_OUTInput->t_FIPInput.pt_ExternalIDCam(i)                [full rage of unsigned char]
  @glob_in         pSLATE_ME_in : CT mobil-eye input                                                                 
                      MEObjectListData.MEObjectList.CameraOutObjects : Camera object list entry                       
                      MEObjectListData.MEObjectList.CameraOutObjects[ ].iObjID : Identification number of the object  [Full range of datatype ObjNumber_t as defined in interfacemeinputdata.h]
                      MEObjectListData.MEObjectList.CameraOutObjects[ ].fDistX : Longitudinal displacement            [-5*RW_FCT_MAX   5*RW_FCT_MAX] m
                      MEObjectListData.MEObjectList.CameraOutObjects[ ].fDistY : Lateral displacement                 [-PI/2*RW_FCT_MAX   PI/2*RW_FCT_MAX] m 
  @glob_in         pt_OUTInput : Reference to OUT input data structure
                      t_OUT_OOI_Input.pf_PredictedLatDispl(i) : Object predicted distance to trajectory [-PI/2*RW_FCT_MAX ... PI/2*RW_FCT_MAX] m
                                                      with i in [0u ... EM_N_OBJECTS-1]
                      t_RTE.pt_ObjClassification(i) : Object class of object CurObjId                                 [Full range of datatype SLATE_t_Obj_CLassification as defined in Rte_Type.h]
                                                      with i in [0u ... EM_N_OBJECTS-1]
                      t_RTE.pt_ObjDynProperty(i)  : Dynamic property of an object CurObjId                            [Full range of datatype SLATE_t_Obj_DynamicProperty as defined in Rte_Type.h]
                                                    with i in [0u ... EM_N_OBJECTS-1]
                      t_RTE.pt_ObjDynSubProperty(i) : Dynamic sub property of object CurObjId                         [Full range of datatype SLATE_t_Obj_DynamicProperty as defined in Rte_Type.h]
                                                      with i in [0u ... EM_N_OBJECTS-1]
                      t_RTE.pu_ObjExtID(i) : External Object ID of object CurObjId                                    [Full range of datatype unsigned char]
                                             with i in [0u ... EM_N_OBJECTS-1]
                      t_RTE.pf_ObjLongDisp(i) : Longitudinal displacement of object with id CurObjId                  [-5*RW_FCT_MAX   5*RW_FCT_MAX] m
                                                with i in [0u ... EM_N_OBJECTS-1]
                      t_RTE.pf_ObjLatDisp(i) : lateral dispcement of object with id CurObjId                          [-PI/2*RW_FCT_MAX   PI/2*RW_FCT_MAX] m
                                               with i in [0u ... EM_N_OBJECTS-1]
                      t_RTE.pf_ObjArelX(i) : Longitudinal (relative) acceleration of object with id CurObjId          [-100f   100f] m/s^2
                                             with i in [0u ... EM_N_OBJECTS-1]
                      t_RTE.pf_ObjVrelX(i) : Longitudinal (relative) velocity of object with id CurObjId              [-330f   330f] m/s
                                             with i in [0u ... EM_N_OBJECTS-1]
                      t_LAInput.pf_SeekLaneWidth : pointer to global seek lane width                                  [-PI/2*RW_FCT_MAX ... PI/2*RW_FCT_MAX] m
  @glob_in         OBJ_GET_ASSOCIATED_LANE(  )                                                                        [Full range of datatype eAssociatedLane_t defined in Rte_Type.h]
  @glob_in         OBJ_GET_CUT_IN_POTENTIAL(i)  : cut in potential of object "i"                                      [0u   100u]
                                                  with i in [0u ... EM_N_OBJECTS-1]
  @glob_in         OBJ_GET_CUT_OUT_POTENTIAL(i) : cut out potential of object "i"                                     [0u   100u]
                                                  with i in [0u ... EM_N_OBJECTS-1]
  @glob_out        -

  
  @c_switch_part   FCT_CFG_CAMERA_OBJECT_DETECTION : FCT camera object/lane detection inputs
  @c_switch_part   SLATE_CFG_USE_EXT_OBJ_ID      : Configuration switch to enable SI external object ID assignment
  @c_switch_part   FCT_CFG_ME_INPUT_FOR_DEBUG      : FCT configuration for debugging input of mobil-eye data
  @c_switch_part   FCT_CFG_ACC_LANE_ASSOCIATION    : FCT support for ACC LA (Lane Association) sub-component
  @c_switch_part   OUT_CFG_CUSTOM_OOI_MEAS_DATA    : Configuration switch for enabling custom output type (OUT_t_CustMeasOOI) output over measurement interface for each OOI object
  @c_switch_full   FCT_MEASUREMENT                 : Activate Measurement Output Code 
  @c_swtich_full   FCT_CFG_ACC_OUTPUT              : Configuration switch to configure OUT (Output) sub-component for FCT_ACC

  @pre             -
  @post            Nothing

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @created         -
  @changed         3/19/2016

  @author          Robert Thiel
*************************************************************************************************************************/
void OUT_v_FreezeData(OUT_t_Meas * const pMeasObjs)
{

  eObjOOI_t onr;
  boolean b_ObjIsMovingToStationary;

  for(onr = OBJ_NEXT_OOI;onr <= OBJ_NEXT_LAT_RIGHT_OOI; onr++)
  {
    OUT_t_Meas * const pMeasObj = &(pMeasObjs[onr]);// PRQA S 492 
/* date: 2017-01-6, reviewer: Rahul Raj R (uid41599), reason: Checked that array index is within boundary values */
    const ObjNumber_t CurObjId = OBJ_GET_OOI_LIST_OBJ_IDX(onr);

    if(CurObjId >= 0)
    { 
      pMeasObj->object_id       = CurObjId;
      pMeasObj->lane            = pt_OUTInput->t_LAInput.pt_LAObjectList(CurObjId)->ObjAssociatedLane;
      //pMeasObj->object_class    = *SLATE_pt_GetObjClassification(CurObjId);
      pMeasObj->object_class    = *(pt_OUTInput->t_RTE.pt_ObjClassification(CurObjId));
      //pMeasObj->object_type     = *SLATE_pt_GetObjDynProperty(CurObjId);
      pMeasObj->object_type     = *(pt_OUTInput->t_RTE.pt_ObjDynProperty(CurObjId));
      //pMeasObj->object_sub_prop = *SLATE_pt_GetObjDynSubProperty(CurObjId);
#if (FCT_USE_EM_ARS_TECH_OBJECT_LIST)
      pMeasObj->object_sub_prop = *(pt_OUTInput->t_RTE.pt_ObjDynSubProperty(CurObjId));
#endif
      if (onr > OBJ_HIDDEN_NEXT_OOI)
      {
        pMeasObj->potential = pt_OUTInput->t_SIT.pt_SITObjectList(CurObjId)->u_ObjCutInPotential;
      }
      else
      {
        pMeasObj->potential = pt_OUTInput->t_SIT.pt_SITObjectList(CurObjId)->u_ObjCutOutPotential;
      }
      b_ObjIsMovingToStationary = SLATE_b_GetObjIsMovingToStationary(CurObjId);
      if (b_ObjIsMovingToStationary)
      {
        pMeasObj->seen_moving = TRUE;
      }
      else
      {
        pMeasObj->seen_moving = FALSE;
      }

#if (SLATE_CFG_USE_EXT_OBJ_ID)
      //pMeasObj->ext_id = OBJ_GET_EXTERNAL_OBJ_ID(CurObjId);
      pMeasObj->ext_id = *(pt_OUTInput->t_RTE.pu_ObjExtID(CurObjId));
#endif

#if (FCT_CFG_CAMERA_OBJECT_DETECTION)
      /* And fill in camera association related fields */
      pMeasObj->cam_obj_id          = (ObjNumber_t)pt_OUTInput->pt_FIPOA->t_ObjList[CurObjId].u_ExternalID_Cam;
      pMeasObj->cam_conf            = (percentage_t)pt_OUTInput->pt_FIPOA->t_ObjList[CurObjId].t_CamObjectData.t_CamConfirmationProb;
      pMeasObj->cam_assoc_lane      = (eAssociatedLane_t)pt_OUTInput->pt_FIPOA->t_ObjList[CurObjId].t_CamObjectData.eAssociatedLane;
      pMeasObj->cam_assoc_lane_qual = (percentage_t)pt_OUTInput->pt_FIPOA->t_ObjList[CurObjId].t_CamObjectData.t_AssignedLaneQual;
#if (FCT_CFG_ME_INPUT_FOR_DEBUG)
      pMeasObj->cam_long_dist       = 0.f;
      pMeasObj->cam_lat_dist        = 0.f;
      /* If mobil-eye raw input data supplied, then fill in camera object position information */
      if (pSLATE_ME_in != NULL)
      {
        /* We need to find the mobil-eye object with the given ID */
        ObjNumber_t iCamObjIdx;
        unsigned char t_ExternalIDCam = pt_OUTInput->pt_FIPOA->t_ObjList[CurObjId].u_ExternalID_Cam;
        for (iCamObjIdx = 0; iCamObjIdx < (ObjNumber_t)(sizeof(pSLATE_ME_in->MEObjectListData.MEObjectList.CameraOutObjects)/sizeof(pSLATE_ME_in->MEObjectListData.MEObjectList.CameraOutObjects[0])); iCamObjIdx++)
        {
          if (t_ExternalIDCam == pSLATE_ME_in->MEObjectListData.MEObjectList.CameraOutObjects[iCamObjIdx].iObjID)
          {
            pMeasObj->cam_long_dist       = pSLATE_ME_in->MEObjectListData.MEObjectList.CameraOutObjects[iCamObjIdx].fDistX;
            pMeasObj->cam_lat_dist        = pSLATE_ME_in->MEObjectListData.MEObjectList.CameraOutObjects[iCamObjIdx].fDistY;
          }
        }
      }
#endif
#endif

      pMeasObj->pred_lat_displ        = *(pt_OUTInput->t_OUT_OOI_Input.pf_PredictedLatDispl(CurObjId));
      //pMeasObj->long_displacement     = OBJ_LONG_DISPLACEMENT(CurObjId);
      pMeasObj->long_displacement     = *(pt_OUTInput->t_RTE.pf_ObjLongDisp(CurObjId));
      //pMeasObj->lat_displacement      = OBJ_LAT_DISPLACEMENT(CurObjId);
      pMeasObj->lat_displacement      = *(pt_OUTInput->t_RTE.pf_ObjLatDisp(CurObjId));
      //pMeasObj->rel_long_acceleration = OBJ_LONG_AREL(CurObjId);
      pMeasObj->rel_long_acceleration = *(pt_OUTInput->t_RTE.pf_ObjArelX(CurObjId));
      //pMeasObj->rel_long_velocity     = OBJ_LONG_VREL(CurObjId);
      pMeasObj->rel_long_velocity     = *(pt_OUTInput->t_RTE.pf_ObjVrelX(CurObjId));
#if (FCT_CFG_ACC_LANE_ASSOCIATION)
      pMeasObj->rel_lat_velocity = *(LA_pf_TrajGetObjToRefDistGradFilt(CurObjId));
#endif

#if (defined(_MSC_VER))
#pragma COMPILEMSG("Remove negation, when visualization adapted to AUTOSAR coordinates!")// PRQA S 3116
/* date: 2015-06-12, reviewer: Gangadhar Badiger, reason: Not QAC related but required */
#endif
#if (FCT_CFG_ACC_LANE_ASSOCIATION)
      pMeasObj->fTraceBracketLeft  = -(LA_pt_GetLAObjOutputList(CurObjId)->ObjCor.TrckFahr.dAblage_SpurGrenze_L);
      pMeasObj->fTraceBracketRight = -(LA_pt_GetLAObjOutputList(CurObjId)->ObjCor.TrckFahr.dAblage_SpurGrenze_R);
#endif	  
    }
    else
    {
      pMeasObj->object_id       = OBJ_INDEX_NO_OBJECT;
      pMeasObj->lane            = ASSOC_LANE_UNKNOWN;
      pMeasObj->object_class    = SLATE_OBJCLASS_UNCLASSIFIED;
      pMeasObj->object_type     = SLATE_OBJECT_PROPERTY_MOVING;
#if (FCT_USE_EM_ARS_TECH_OBJECT_LIST)
      pMeasObj->object_sub_prop = SLATE_OBJECT_SUBPROP_NORMAL;
#endif
      pMeasObj->potential       = 0u;
      pMeasObj->seen_moving     = FALSE;

#if (SLATE_CFG_USE_EXT_OBJ_ID)
      pMeasObj->ext_id = (FCTSenExtObjId_t)FCT_EXTERN_OBJ_ID_NO_OBJECT;
#endif

#if (FCT_CFG_CAMERA_OBJECT_DETECTION)
      pMeasObj->cam_obj_id          = OBJ_INDEX_NO_OBJECT;
      pMeasObj->cam_conf            = 0u;
      pMeasObj->cam_assoc_lane      = ASSOC_LANE_UNKNOWN;
      pMeasObj->cam_assoc_lane_qual = 0u;
#if (FCT_CFG_ME_INPUT_FOR_DEBUG)
      pMeasObj->cam_long_dist       = 0.f;
      pMeasObj->cam_lat_dist        = 0.f;
#endif
#endif

      pMeasObj->pred_lat_displ        = 0.f;
      pMeasObj->long_displacement     = 0.f;
      pMeasObj->lat_displacement      = 0.f;
      pMeasObj->rel_long_acceleration = 0.f;
      pMeasObj->rel_long_velocity     = 0.f;
      pMeasObj->rel_lat_velocity      = 0.f;

#if (FCT_CFG_ACC_LANE_ASSOCIATION)
      if (pt_OUTInput->t_LAInput.pf_SeekLaneWidth == NULL)
      {
		pMeasObj->fTraceBracketLeft = 0.f;/* PRQA S 2200 *//* Date: 2020-04-02, Reviewer:Tejaswini M , Reason:This warning is suppressed as Indentation does not have any critical impact on the functionality. */
      }
	  else
	  {
		pMeasObj->fTraceBracketLeft  = *(LA_pf_SeekLaneWidth());
	  }
#endif /*FCT_CFG_ACC_LANE_ASSOCIATION*/

      pMeasObj->fTraceBracketRight = 0.f;
    }

#if (OUT_CFG_CUSTOM_OOI_MEAS_DATA)
    /* Call custom function to fill custom meas data field */
    OUT_v_CustFillMeasOOI(CurObjId, &pMeasObj->custom);
#endif
  }
}
#endif

/*************************************************************************************************************************
  Functionname:    OUT_v_GenerateOutputData                                                                             */ /*!

  @brief           this function generates output data from the OUT (6 objects)

  @description     this function generates output data from the OUT (6 objects)

                    @startuml
                    Partition OUT_v_GenerateOutputData{
                    Start
                    :  Get Object number;
                    :  Fill lost reason even if no OOI0;
                    Partition #LightBlue FCT_CFG_SEN2VEH_ACC_OOI_PORT{
                    : Fill the boolean Front Obstacle Detected signal;
                    If (ObjNr_OBJ_NEXT_OOI is greater than OBJ_INDEX_NO_OBJECT) then (TRUE)
                    : Get OOI Object kinematics;
                    : Get OOI Object Attributes;
                    Else (FALSE)
                    : Delete OOI data from last cycle;
                    Endif
                    If (OBJ_HIDDEN_NEXT_OOI) then (TRUE)
                    : Get OOI Object kinematics;
                    : Get OOI Object Attributes;
                    Else (FALSE)
                    : Delete OOI data from last cycle;
                    Endif
                    If (OBJ_NEXT_LAT_LEFT_OOI) then (TRUE)
                    : Get OOI Object kinematics;
                    : Get OOI Object Attributes;
                    Else (FALSE)
                    : Delete OOI data from last cycle;
                    Endif
                    If (OBJ_NEXT_LAT_RIGHT_OOI) then (TRUE)
                    : Get OOI Object kinematics;
                    : Get OOI Object Attributes;
                    Else (FALSE)
                    : Delete OOI data from last cycle;
                    Endif
                    : Prevent Overtake Feature;
                    }
                    Partition #LightBlue FCT_CFG_LOHP_COMPONENT{
                    : Fill provide ports to LOHP;
                    }
                    Partition #LightBlue FCT_CFG_ACC_SITUATION{
                    Partition SIT_LC_CFG_USE_OVERTAKE_IN_LANECHANGE{
                    If (Overtake support not allowed) then (TRUE)
                    : In case of no overtake direction of lanechange is based on\n the most probable direction otherwise check the overtake direction;
                    Else (FALSE)
                    : set LC direction from overtake which is mainly dependant on\n traffic orientation and turn indicator;
                    Endif
                    }
                    : map LC phase to slate output;
                    : map lane change probability to slate output;
                    }
                    : Writing lopc outputs;
                    : Change outputs to SPM from restructuring;
                    End
                    }
                    @enduml

  @return          -

  @param[in]       -
  @param[out]      -

  @glob_in         pt_OUTInput->t_OUT_OOI_Input.OOI_t_eRelObjLossReason_Zero : Object loss reason for zeroth element 
  @glob_in         OBJ_GET_OOI_LIST_OBJ_IDX( ) : Accessing ACC Assessed Object List object of interest array         [0u   39u]
  @glob_in         pSLATE_AccOOIData
                      AccOOINextLong.Kinematic         : Kinematic object properties          
                      AccOOINextLong.Attributes        : Dynamic object properties           
                      AccOOIHiddenNextLong.Kinematic   : Kinematic object properties          
                      AccOOIHiddenNextLong.Attributes  : Dynamic object properties            
                      AccOOINextLeft.Kinematic         : Kinematic object properties          
                      AccOOINextLeft.Attributes        : Dynamic object properties            
                      AccOOINextRight.Kinematic        : Kinematic object properties          
                      AccOOINextRight.Attributes       : Dynamic object properties            
                      AccOOIHiddenNextLeft.Kinematic   : Kinematic object properties          
                      AccOOIHiddenNextLeft.Attributes  : Dynamic object properties            
                      AccOOIHiddenNextRight.Kinematic  : Kinematic object properties         
                      AccOOIHiddenNextRight.Attributes : Dynamic object properties            
  @glob_out        pSLATE_AccOOIData->AccOOINextLong.eRelObjLossReason : Relevant obj loss reason           [Full range of datatype eRelObjLossReason_t defined in Rte_Type.h]
  
  @c_switch_part   FCT_CFG_SEN2VEH_ACC_OOI_PORT          : switch for OOI port to vehicle task
  @c_switch_part   SIT_LC_CFG_USE_OVERTAKE_IN_LANECHANGE : Configuration switch for enabling overtake support for controller
  @c_switch_part   FCT_CFG_ACC_OOI                       : FCT support for ACC OOI sub-component
  @c_switch_part   OUT_CFG_FUNC_LANEASSOC_LA             : Configuration switch which provides Functional Lane Association during pre lane change to LOHP
  @c_switch_full   FCT_CFG_ACC_OUTPUT                    : Configuration switch to configure OUT (Output) sub-component for FCT_ACC 

  @pre             -
  @post            -

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @traceability    436:doors://rbgs854a:40000/?version=2&prodID=0&urn=urn:telelogic::1-503e822e5ec3651e-O-436-00061542 \n
                   435:doors://rbgs854a:40000/?version=2&prodID=0&urn=urn:telelogic::1-503e822e5ec3651e-O-435-00061542 \n

  @created         -
  @changed         3/28/2016


  @author          Robert Thiel
*************************************************************************************************************************/
void OUT_v_GenerateOutputData(void)
{
#if (FCT_CFG_LOHP_COMPONENT) 
  
#if (SLATE_CFG_PARALLEL_LANE_CHANGE)
  ObjNumber_t t_OOI_ObjID;
  TraceID_t iTraceID; 
#endif /* (SLATE_CFG_PARALLEL_LANE_CHANGE) */
#endif /* END IF FCT_CFG_LOHP_COMPONENT */
#if ((FCT_CFG_LOHP_COMPONENT) && (FCT_CFG_ACC_OOI))
  uint8 i;
#endif
#if (OUT_CFG_FUNC_LANEASSOC_LA)
  eObjOOI_t OOIObj; /* 6 OOIs */
  ObjNumber_t iObj; /* 40 EM objects */
#endif /* OUT_CFG_FUNC_LANEASSOC_LA */

  /* Defining local variables from global inputs */
  ObjNumber_t ObjNr_OBJ_NEXT_OOI, ObjNr_OBJ_HIDDEN_NEXT_OOI, ObjNr_OBJ_NEXT_LONG_LEFT_OOI, ObjNr_OBJ_NEXT_LONG_RIGHT_OOI, ObjNr_OBJ_NEXT_LAT_LEFT_OOI, ObjNr_OBJ_NEXT_LAT_RIGHT_OOI;// PRQA S 3203
  /* date: 2017-11-02, reviewer: Dyuthi Varier, reason: Redundant, but may be used in future*/

  ObjNr_OBJ_NEXT_OOI = OBJ_GET_OOI_LIST_OBJ_IDX(OBJ_NEXT_OOI); /* Object number of OOI-0 */
  ObjNr_OBJ_HIDDEN_NEXT_OOI = OBJ_GET_OOI_LIST_OBJ_IDX(OBJ_HIDDEN_NEXT_OOI);// PRQA S 3199
  /* date: 2017-11-02, reviewer: Dyuthi Varier, reason: Redundant, but may be used in future*/
  ObjNr_OBJ_NEXT_LONG_LEFT_OOI = OBJ_GET_OOI_LIST_OBJ_IDX(OBJ_NEXT_LONG_LEFT_OOI);// PRQA S 3199
  /* date: 2017-11-02, reviewer: Dyuthi Varier, reason: Redundant, but may be used in future*/
  ObjNr_OBJ_NEXT_LONG_RIGHT_OOI = OBJ_GET_OOI_LIST_OBJ_IDX(OBJ_NEXT_LONG_RIGHT_OOI);// PRQA S 3199
  /* date: 2017-11-02, reviewer: Dyuthi Varier, reason: Redundant, but may be used in future*/
  ObjNr_OBJ_NEXT_LAT_LEFT_OOI = OBJ_GET_OOI_LIST_OBJ_IDX(OBJ_NEXT_LAT_LEFT_OOI);// PRQA S 3199
  /* date: 2017-11-02, reviewer: Dyuthi Varier, reason: Redundant, but may be used in future*/
  ObjNr_OBJ_NEXT_LAT_RIGHT_OOI = OBJ_GET_OOI_LIST_OBJ_IDX(OBJ_NEXT_LAT_RIGHT_OOI);// PRQA S 3199
  /* date: 2017-11-02, reviewer: Dyuthi Varier, reason: Redundant, but may be used in future*/

  /*! Fill FCTAccOOIData*/
#if (FCT_CFG_SEN2VEH_ACC_OOI_PORT)
  /*! Reset all structures */

#if (FCT_CFG_ACC_OOI)
  /* OBJ_NEXT_OOI */
  /*! Fill lost reason even if no OOI0*/
  pSLATE_AccOOIData->AccOOINextLong.eRelObjLossReason = *(pt_OUTInput->t_OUT_OOI_Input.pt_OOIObjLossReason(OBJ_NEXT_OOI));
#if (OBJLOSS_NUMBER_OF_OOI > 1)
  pSLATE_AccOOIData->AccOOIHiddenNextLong.Attributes.eLostReason = *(pt_OUTInput->t_OUT_OOI_Input.pt_OOIObjLossReason(OBJ_HIDDEN_NEXT_OOI));
#endif /* (OBJLOSS_NUMBER_OF_OOI > 1) */
#endif  /* (FCT_CFG_ACC_OOI) */

#if ((SLATE_CFG_TCI_BASE) && (SLATE_CFG_TCI_FRONT_OBST_DETCD))
 
  /* ! Fill the boolean Front Obstacle Detected signal */
  pSLATE_AccOOIData->bFrontObstacleDetected = *(pt_OUTInput->t_SIT.pb_FrontObstSigVal);
#endif /* END IF (SLATE_CFG_TCI_BASE) && (SLATE_CFG_TCI_FRONT_OBST_DETCD) */

  if(ObjNr_OBJ_NEXT_OOI > OBJ_INDEX_NO_OBJECT)
  {
    OUT_v_FillOOIKinematic(ObjNr_OBJ_NEXT_OOI, &pSLATE_AccOOIData->AccOOINextLong.Kinematic);
    OUT_v_FillOOIAttributes(ObjNr_OBJ_NEXT_OOI, OBJ_NEXT_OOI, &pSLATE_AccOOIData->AccOOINextLong.Attributes);
  }
  else
  {
    OUT_v_DeleteOOIData(&pSLATE_AccOOIData->AccOOINextLong.Kinematic, &pSLATE_AccOOIData->AccOOINextLong.Attributes);
  }

  /* OBJ_HIDDEN_NEXT_OOI */
  if(ObjNr_OBJ_HIDDEN_NEXT_OOI > OBJ_INDEX_NO_OBJECT)
  {
  OUT_v_FillOOIKinematic(ObjNr_OBJ_HIDDEN_NEXT_OOI, &pSLATE_AccOOIData->AccOOIHiddenNextLong.Kinematic);
  OUT_v_FillOOIAttributes(ObjNr_OBJ_HIDDEN_NEXT_OOI, OBJ_HIDDEN_NEXT_OOI, &pSLATE_AccOOIData->AccOOIHiddenNextLong.Attributes);
  }
  else
  {
    OUT_v_DeleteOOIData(&pSLATE_AccOOIData->AccOOIHiddenNextLong.Kinematic, &pSLATE_AccOOIData->AccOOIHiddenNextLong.Attributes);
  }

  /* OBJ_NEXT_LONG_LEFT_OOI */
  if(ObjNr_OBJ_NEXT_LONG_LEFT_OOI > OBJ_INDEX_NO_OBJECT)
  {
  OUT_v_FillOOIKinematic(ObjNr_OBJ_NEXT_LONG_LEFT_OOI, &pSLATE_AccOOIData->AccOOINextLeft.Kinematic);
  OUT_v_FillOOIAttributes(ObjNr_OBJ_NEXT_LONG_LEFT_OOI, OBJ_NEXT_LONG_LEFT_OOI, &pSLATE_AccOOIData->AccOOINextLeft.Attributes);
  }
  else
  {
    OUT_v_DeleteOOIData(&pSLATE_AccOOIData->AccOOINextLeft.Kinematic, &pSLATE_AccOOIData->AccOOINextLeft.Attributes);
  }

  /* OBJ_NEXT_LONG_RIGHT_OOI */
  if(ObjNr_OBJ_NEXT_LONG_RIGHT_OOI > OBJ_INDEX_NO_OBJECT)
  {
  OUT_v_FillOOIKinematic(ObjNr_OBJ_NEXT_LONG_RIGHT_OOI, &pSLATE_AccOOIData->AccOOINextRight.Kinematic);
  OUT_v_FillOOIAttributes(ObjNr_OBJ_NEXT_LONG_RIGHT_OOI, OBJ_NEXT_LONG_RIGHT_OOI, &pSLATE_AccOOIData->AccOOINextRight.Attributes);
  }
  else
  {
    OUT_v_DeleteOOIData(&pSLATE_AccOOIData->AccOOINextRight.Kinematic, &pSLATE_AccOOIData->AccOOINextRight.Attributes);
  }

  /* OBJ_NEXT_LAT_LEFT_OOI */
  if(ObjNr_OBJ_NEXT_LAT_LEFT_OOI > OBJ_INDEX_NO_OBJECT)
  {
  OUT_v_FillOOIKinematic(ObjNr_OBJ_NEXT_LAT_LEFT_OOI, &pSLATE_AccOOIData->AccOOIHiddenNextLeft.Kinematic);
  OUT_v_FillOOIAttributes(ObjNr_OBJ_NEXT_LAT_LEFT_OOI, OBJ_NEXT_LAT_LEFT_OOI, &pSLATE_AccOOIData->AccOOIHiddenNextLeft.Attributes);
  }
  else
  {
    OUT_v_DeleteOOIData(&pSLATE_AccOOIData->AccOOIHiddenNextLeft.Kinematic, &pSLATE_AccOOIData->AccOOIHiddenNextLeft.Attributes);
  }

  /* OBJ_NEXT_LAT_RIGHT_OOI */
  if(ObjNr_OBJ_NEXT_LAT_RIGHT_OOI > OBJ_INDEX_NO_OBJECT)
  {
  OUT_v_FillOOIKinematic(ObjNr_OBJ_NEXT_LAT_RIGHT_OOI, &pSLATE_AccOOIData->AccOOIHiddenNextRight.Kinematic);
  OUT_v_FillOOIAttributes(ObjNr_OBJ_NEXT_LAT_RIGHT_OOI, OBJ_NEXT_LAT_RIGHT_OOI, &pSLATE_AccOOIData->AccOOIHiddenNextRight.Attributes);
  }
  else
  {
    OUT_v_DeleteOOIData(&pSLATE_AccOOIData->AccOOIHiddenNextRight.Kinematic, &pSLATE_AccOOIData->AccOOIHiddenNextRight.Attributes);
  }

  /* Prevent Overtake Feature */
#if (OUT_CFG_OVERTAKE_PREVENTION_FEATURE)
  OUT_v_SetPreventOvertake();
#endif /* END IF OUT_CFG_OVERTAKE_PREVENTION_FEATURE */
#endif  /* END IF FCT_CFG_SEN2VEH_ACC_OOI_PORT */

  /* Fill provide ports to LOHP */
#if (FCT_CFG_LOHP_COMPONENT)

#if (FCT_CFG_ACC_PERF_MONITORING)
  pSLATE_HC_Data->t_APM_Data.f_MaxDistPerfMin = APM_f_GetMaxDistPerfMinACC(); /* To be replaced by access functions from APM */
  pSLATE_HC_Data->t_APM_Data.f_MaxDistALN = APM_f_GetMaxDistPerfACC_ALN(); /* To be replaced by access functions from APM */
#endif

#if (FCT_CFG_ACC_OOI)
  for (i = 0u; i < OOI_NUMBER_OF_OOI; i++)
  {
    pSLATE_HC_Data->t_ObjLossReasonACCOOI[i] = *pt_OUTInput->t_OUT_OOI_Input.pt_OOIObjLossReason((OOI_RelObjEnum_t)i);
#if (SLATE_CFG_PARALLEL_LANE_CHANGE)
    t_OOI_ObjID = *(pt_OUTInput->t_OUT_OOI_Input.pu_OOIListObjId(i));    
    if (t_OOI_ObjID > (ObjNumber_t)-1)
    {
      iTraceID = *pt_OUTInput->t_FIPTraceId.pt_ObjTraceID(t_OOI_ObjID);      	   
      if (iTraceID < FIP_u_TRACE_VALID_NO_OBJ_ID)
      {    
        pSLATE_HC_Data->t_OOILCState[i] = pt_OUTInput->t_CP.pt_ObjLaneChangeInfo(iTraceID)->t_TraceLaneChange;
      }
      else
      {
        /* Do nothing - Default initialization habdled in SLATE_v_InitProvidePorts() */
      }
    }
    else
    {
      /* Do nothing - Default initialization habdled in SLATE_v_InitProvidePorts() */
    }
#endif /* (SLATE_CFG_PARALLEL_LANE_CHANGE) */
  }
#endif

#if (FCT_CFG_ACC_SITUATION)
#if (SIT_LC_CFG_USE_OVERTAKE_IN_LANECHANGE)
  if(pt_OUTInput->t_SIT.pt_LaneChangePhaseInfo->t_AllowOvertake == LC_ALLOW_NO_OVERTAKE)
  {/*In case of no overtake direction of lanechange is based on the most probable direction otherwise check the overtake direction*/
    pSLATE_HC_Data->t_SLATE_LC.b_AllowOvertake = FALSE;
    switch(pt_OUTInput->t_SIT.pt_LaneChangePhaseInfo->t_LCPhaseState)
    {
      case LC_FOLLOW:
        pSLATE_HC_Data->t_SLATE_LC.e_LCDirection = SLATE_LC_NONE;
        break;
      case LC_LEFT:
        pSLATE_HC_Data->t_SLATE_LC.e_LCDirection = SLATE_LC_LEFT;
        break;
      case LC_RIGHT:
        pSLATE_HC_Data->t_SLATE_LC.e_LCDirection = SLATE_LC_RIGHT;
        break;
      default:
        pSLATE_HC_Data->t_SLATE_LC.e_LCDirection = SLATE_LC_NONE;
        break;
    }
  }
  else
  {/*set LC direction from overtake which is mainly dependant on traffic orientation and turn indicator*/
    if (pt_OUTInput->t_SIT.pt_LaneChangePhaseInfo->t_AllowOvertake == LC_ALLOW_OVERTAKE_RIGHT)
    {
      pSLATE_HC_Data->t_SLATE_LC.e_LCDirection = SLATE_LC_RIGHT;
    }
    else
    {
      pSLATE_HC_Data->t_SLATE_LC.e_LCDirection = SLATE_LC_LEFT;
    }

    pSLATE_HC_Data->t_SLATE_LC.b_AllowOvertake = TRUE;
  }
#endif /*SIT_LC_CFG_USE_OVERTAKE_IN_LANECHANGE*/
/*map LC phase to slate output*/
  switch (pt_OUTInput->t_SIT.pt_LaneChangePhaseInfo->t_LCPhase)
  {
  case LC_NO_LANECHANGE:
    pSLATE_HC_Data->t_SLATE_LC.e_LCPhase = SLATE_LC_NO_LANECHANGE;
    break;
  case LC_PRELANECHANGE:
    pSLATE_HC_Data->t_SLATE_LC.e_LCPhase = SLATE_LC_PRELANECHANGE;
    break;
  case LC_LANECHANGE:
    pSLATE_HC_Data->t_SLATE_LC.e_LCPhase = SLATE_LC_LANECHANGE;
    break;
  case LC_STEERBACK:
    pSLATE_HC_Data->t_SLATE_LC.e_LCPhase = SLATE_LC_STEERBACK;
    break;
  default:
    pSLATE_HC_Data->t_SLATE_LC.e_LCPhase = SLATE_LC_NO_LANECHANGE;
    break;
  }
  /*map lane change probability to slate output*/
  pSLATE_HC_Data->t_SLATE_LC.u_LCPhaseProb = pt_OUTInput->t_SIT.pt_LaneChangePhaseInfo->u_LCPhaseProb;

#endif

#if (OUT_CFG_FUNC_LANEASSOC_LA)
/* Provide Functional lane association of 6 OOIs during Pre Lane change phase */
for (iObj = 0; iObj < (ObjNumber_t)EM_N_OBJECTS; iObj++)
{
  if ( (  ( *pt_OUTInput->t_RTE.pt_TurnIndicator == eTurnIndicator_Left)
       ||( *pt_OUTInput->t_RTE.pt_TurnIndicator == eTurnIndicator_Right))
      && (pt_OUTInput->t_SIT.pt_LaneChangePhaseInfo->t_LCPhase == LC_PRELANECHANGE)
      && (pt_OUTOutput->b_flag_LaneAss_LC == FALSE)
     )
  {
    /* Store Functional lane association of 40 objects during transition from no lane change to Pre Lane change phase */
    pt_OUTOutput->t_FuncLA_LC[iObj] = pt_OUTInput->t_LAInput.pt_LAObjectList(iObj)->ObjFuncLane;
    
    if (iObj == (EM_N_OBJECTS-1))
    {
      pt_OUTOutput->b_flag_LaneAss_LC = TRUE;
    }
  }
  else if (pt_OUTInput->t_SIT.pt_LaneChangePhaseInfo->t_LCPhase == LC_NO_LANECHANGE)
  {
    pt_OUTOutput->t_FuncLA_LC[iObj] = pt_OUTInput->t_LAInput.pt_LAObjectList(iObj)->ObjFuncLane;
    pt_OUTOutput->b_flag_LaneAss_LC = FALSE;
  }
  else
  {
    /* Do nothing */
  }
  /* Provide Functional lane association of 6 OOIs during transition from no lane change to Pre Lane change phase */
  if (t_OOI_ObjectList[iObj].t_Bool.SelectedAsOOI == TRUE)
  {
    if (SLATE_p_GetFCTPubObj_OOI(iObj)->eObjOOI != OBJ_NOT_OOI)
    {
      OOIObj = SLATE_p_GetFCTPubObj_OOI(iObj)->eObjOOI;
      pSLATE_HC_Data->t_FuncLaneAss_LC[OOIObj] = pt_OUTOutput->t_FuncLA_LC[iObj];
    }
  }
}

#endif /* OUT_CFG_FUNC_LANEASSOC_LA */

/* Writing lopc outputs */
#if (defined(TSA_SLATE_INPUT_ENABLE) && defined(TSA_SLATE_Input_INTFVER) && FCT_CFG_SLA_FEATURE)
  switch(pSLATE_TSAInputData->spdLmt[0].signType)
  {
  case SLA_OUTPUT_SIGN_NO:
    pSLATE_SLAData->u_SLA_SpeedLimitNow = 0u;
    pSLATE_SLAData->e_StreetType = NAV_STT_UNKNOWN;
    break;
  case SLA_OUTPUT_SIGN_SL:
    pSLATE_SLAData->u_SLA_SpeedLimitNow = pSLATE_TSAInputData->spdLmt[0].spdLmtValue;
    break;
  case SLA_OUTPUT_SIGN_SLE:
    pSLATE_SLAData->u_SLA_SpeedLimitNow = 253u;
    break;

  case SLA_OUTPUT_SIGN_HIGHWAY_START:
    pSLATE_SLAData->u_SLA_SpeedLimitNow = 130u;
    pSLATE_SLAData->e_StreetType = NAV_STT_FEDERAL_HIGHWAY;
    break;
  case SLA_OUTPUT_SIGN_HIGHWAY_END:
    pSLATE_SLAData->u_SLA_SpeedLimitNow = 253u;
    pSLATE_SLAData->e_StreetType = NAV_STT_UNKNOWN;
    break;
  case SLA_OUTPUT_SIGN_CITYLIMIT_START:
    pSLATE_SLAData->u_SLA_SpeedLimitNow = 50u;
    pSLATE_SLAData->e_StreetType = NAV_STT_URBAN_BIDIRECTION;
    break;
  case SLA_OUTPUT_SIGN_CITYLIMIT_END:
    pSLATE_SLAData->u_SLA_SpeedLimitNow = 253u;
    pSLATE_SLAData->e_StreetType = NAV_STT_UNKNOWN;
    break;
  case SLA_OUTPUT_SIGN_PLAYSTREET_START:
    pSLATE_SLAData->u_SLA_SpeedLimitNow = 10u;
    pSLATE_SLAData->e_StreetType = NAV_STT_UNKNOWN;
    break;
  case SLA_OUTPUT_SIGN_PLAYSTREET_END:
    pSLATE_SLAData->u_SLA_SpeedLimitNow = 253u;
    pSLATE_SLAData->e_StreetType = NAV_STT_UNKNOWN;
    break;
  default:
    pSLATE_SLAData->u_SLA_SpeedLimitNow = 0u;
    pSLATE_SLAData->e_StreetType = NAV_STT_UNKNOWN;
    break;
  }
  pSLATE_SLAData->u_SLA_SpeedLimitNext = 0u;
  pSLATE_SLAData->e_SLA_SpeedLimitNextType = SLA_TYPE_IDLE;
  pSLATE_SLAData->b_SLA_ConsiderNewNowSign = FALSE;
  pSLATE_SLAData->u_SLA_SpeedLimitNextDistance = (t_u_DistanceLong)0;
  pSLATE_SLAData->e_SLA_SpeedLimitUnit = SPD_UNIT_KMH;
#elif  (FCT_CFG_LONG_CTRL_SLA_SUPPORT && defined(CamSLAInputData_INTFVER) && FCT_CFG_SLA_FEATURE)
  switch(pSLATE_CamSLAInputData->spdLmt[0].signType)
  {
  case SLA_OUTPUT_SIGN_NO:
    pSLATE_SLAData->u_SLA_SpeedLimitNow = 0u;
	pSLATE_SLAData->e_StreetType = NAV_STT_UNKNOWN;
    break;
  case SLA_OUTPUT_SIGN_SL:
    pSLATE_SLAData->u_SLA_SpeedLimitNow = pSLATE_CamSLAInputData->spdLmt[0].spdLmtValue;
    break;
  case SLA_OUTPUT_SIGN_SLE:
    pSLATE_SLAData->u_SLA_SpeedLimitNow = 253u;
    break;
  case SLA_OUTPUT_SIGN_HIGHWAY_START:
    pSLATE_SLAData->u_SLA_SpeedLimitNow = 130u;
    pSLATE_SLAData->e_StreetType = NAV_STT_FEDERAL_HIGHWAY;
    break;
  case SLA_OUTPUT_SIGN_HIGHWAY_END:
    pSLATE_SLAData->u_SLA_SpeedLimitNow = 253u;
    pSLATE_SLAData->e_StreetType = NAV_STT_UNKNOWN;
    break;
  case SLA_OUTPUT_SIGN_CITYLIMIT_START:
    pSLATE_SLAData->u_SLA_SpeedLimitNow = 50u;
	pSLATE_SLAData->e_StreetType = NAV_STT_URBAN_BIDIRECTION;
    break;
  case SLA_OUTPUT_SIGN_CITYLIMIT_END:
    pSLATE_SLAData->u_SLA_SpeedLimitNow = 253u;
	pSLATE_SLAData->e_StreetType = NAV_STT_UNKNOWN;
    break;
  case SLA_OUTPUT_SIGN_PLAYSTREET_START:
    pSLATE_SLAData->u_SLA_SpeedLimitNow = 10u;
    pSLATE_SLAData->e_StreetType = NAV_STT_UNKNOWN;
    break;
  case SLA_OUTPUT_SIGN_PLAYSTREET_END:
    pSLATE_SLAData->u_SLA_SpeedLimitNow = 253u;
    pSLATE_SLAData->e_StreetType = NAV_STT_UNKNOWN;
    break;
  default:
    pSLATE_SLAData->u_SLA_SpeedLimitNow = 0u;
	pSLATE_SLAData->e_StreetType = NAV_STT_UNKNOWN;
    break;
  }
  pSLATE_SLAData->u_SLA_SpeedLimitNext = 0u;
  pSLATE_SLAData->e_SLA_SpeedLimitNextType = SLA_TYPE_IDLE;
  pSLATE_SLAData->b_SLA_ConsiderNewNowSign = FALSE;
  pSLATE_SLAData->u_SLA_SpeedLimitNextDistance = (t_u_DistanceLong)0;
  pSLATE_SLAData->e_SLA_SpeedLimitUnit = SPD_UNIT_KMH;
#endif /* FCT_CFG_LONG_CTRL_SLA_SUPPORT && defined(CamSLAInputData_INTFVER) && defined(SLAData_INTFVER) */
#endif /* FCT_CFG_LOHP_COMPONENT */

#if (FCT_CFG_SIGNAL_PERF_MONITORING)
  /* Todo: Change outputs to SPM from restructuring! */
  if (t_OOI_LastCycleOOIObjID[OBJ_NEXT_OOI] > OBJ_INDEX_NO_OBJECT)
  {
    pSLATE_SPM_Data->FctPreselTGACCLastRelObj = pt_OUTInput->t_LAInput.pt_LAObjectList(0)->t_Bool.FctPreselTG;
  }
  else
  {
    pSLATE_SPM_Data->FctPreselTGACCLastRelObj = 0u;
  }
  pSLATE_SPM_Data->t_ObjLossReasonACCRelObj = *pt_OUTInput->t_OUT_OOI_Input.pt_OOIObjLossReason(OBJ_NEXT_OOI);
  if(ObjNr_OBJ_NEXT_OOI > OBJ_INDEX_NO_OBJECT)
  {
    pSLATE_SPM_Data->f_Dist2TrajACCRelObj = *pt_OUTInput->t_LAInput.pf_ObjToRefDistMeas(ObjNr_OBJ_NEXT_OOI);
    pSLATE_SPM_Data->f_Dist2TrajVarACCRelObj = *pt_OUTInput->t_LAInput.pf_ObjToRefDistFiltVar(ObjNr_OBJ_NEXT_OOI);
  }
  else
  {
    pSLATE_SPM_Data->f_Dist2TrajACCRelObj = 0.f; // ???
    pSLATE_SPM_Data->f_Dist2TrajVarACCRelObj = 0.f; // ???
  }
#endif

#if (FCT_CFG_COLLISION_DETECTION)
  pSLATE_CD_Data->t_ACCRelObjID = ObjNr_OBJ_NEXT_OOI;
#endif
}/* PRQA S 7004 */
/* date: 2018-03-26, reviewer: Ravi Kiran Gurrala, reason : Cyclomatic complexity. Not Safety critical*/

/*************************************************************************************************************************
  Functionname:    OUT_v_FillOOIKinematic                                                                               */ /*!

  @brief           Fill OOI Object kinematics

  @description     Fill OOI Object kinematics

                   @startuml
                   Partition #LightBlue FCT_CFG_SEN2VEH_ACC_OOI_PORT{
                   Partition OUT_v_FillOOIKinematic{
                   Start
                   : Fill Kinematics;
                   End
                   }
                   }
                   @enduml

  @return          static void

  @param[in]       ObjId : Object ID of datatype ObjNumber_t as defined in Rte_Type.h  [0u   39u]
  @param[out]      pKinematic                                          
                      fDistX : Longitudinal displacement                               [-5*RW_FCT_MAX   5*RW_FCT_MAX] m
                      fDistY : Lateral displacement                                    [-PI/2*RW_FCT_MAX   PI/2*RW_FCT_MAX] m
                      fVrelY : Lateral (relative) velocity                             [-330f   330f] m/s
                      fVrelX : Longitudinal (relative) velocity                        [-330f   330f] m/s
                      fArelX : Longitudinal (relative) acceleration                    [-100f   100f] m/s^2
                      fArelY : Lateral (relative) acceleration                         [-100f   100f] m/s^2
                      fVabsX : Velocity (absolute) in X direction                      [-330f   330f] m/s
                      fVabsY : Velocity (absolute) in Y direction                      [-330f   330f] m/s
                      fAabsX : Acceleration (absolute) in X direction                  [-100f   100f] m/s^2
                      fAabsY : Acceleration (absolute) in Y direction                  [-100f   100f] m/s^2

  @glob_in         pt_OUTInput
                      t_RTE.pf_ObjLongDisp(i)    : Longitudinal displacement of object with id "i"               [-5*RW_FCT_MAX   5*RW_FCT_MAX] m
                      t_RTE.pf_ObjLatDisp(i)     : lateral dispcement of object with id "i"                      [-PI/2*RW_FCT_MAX   PI/2*RW_FCT_MAX] m
                      t_RTE.pf_ObjVrelX(i)       : Longitudinal (relative) velocity of object with id "i"        [-330f   330f] m/s
                      t_RTE.pf_ObjVrelY(i)       : Lateral (relative) velocity of object with id "i"             [-330f   330f] m/s
                      t_RTE.pf_ObjArelX(i)       : Longitudinal (relative) acceleration of object with id "i"    [-100f   100f] m/s^2
                      t_RTE.pf_ObjArelY(i)       : Lateral (relative) acceleration of object with id "i"         [-100f   100f] m/s^2
                      t_FIPInput.pf_ObjAbsVelX(i): Velocity (absolute) in X direction of object with id "i"      [-330f   330f] m/s
                      t_RTE.pf_ObjVabsY(i)       : Velocity (absolute) in Y direction of object with id "i"      [-330f   330f] m/s
                      t_FIPOA.pf_ObjAbsAccelX(i) : Acceleration (absolute) in X direction of object with id "i"  [-100f   100f] m/s^2
                      t_RTE.pf_ObjAabsY(i)       : Acceleration (absolute) in Y direction of object with id "i"  [-100f   100f] m/s^2      

  @glob_out        -

  @c_switch_part   -
  @c_switch_full   FCT_CFG_SEN2VEH_ACC_OOI_PORT : Switch for OOI port to vehicle task
  @c_switch_full   FCT_CFG_ACC_OUTPUT           : Configuration switch to configure OUT (Output) sub-component for FCT_ACC
  @post            -

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @created         -
  @changed         3/21/2016


  @author          Simon Sinnstein

*****************************************************************************/
#if (FCT_CFG_SEN2VEH_ACC_OOI_PORT)
static void OUT_v_FillOOIKinematic(const ObjNumber_t ObjId, AccOOIGenKinematics_t* pKinematic)
{
  /*! Fill Kinematics */
  //pKinematic->fDistX = OBJ_LONG_DISPLACEMENT(ObjId);
  pKinematic->fDistX = *(pt_OUTInput->t_RTE.pf_ObjLongDisp(ObjId));
  //pKinematic->fDistY = OBJ_LAT_DISPLACEMENT(ObjId);
  pKinematic->fDistY = *(pt_OUTInput->t_RTE.pf_ObjLatDisp(ObjId));
  //pKinematic->fVrelX = OBJ_LONG_VREL(ObjId);
  pKinematic->fVrelX = *(pt_OUTInput->t_RTE.pf_ObjVrelX(ObjId));
  //pKinematic->fVrelY = OBJ_LAT_VREL(ObjId);
  pKinematic->fVrelY = *(pt_OUTInput->t_RTE.pf_ObjVrelY(ObjId));
  //pKinematic->fArelX = OBJ_LONG_AREL(ObjId);
  pKinematic->fArelX = *(pt_OUTInput->t_RTE.pf_ObjArelX(ObjId));
  //pKinematic->fArelY = OBJ_LAT_AREL(ObjId);
  pKinematic->fArelY = *(pt_OUTInput->t_RTE.pf_ObjArelY(ObjId));
  pKinematic->fVabsX = pt_OUTInput->pt_FIPOA->t_ObjList[ObjId].fAbsVelocity;
  //pKinematic->fVabsY = OBJ_KINEMATIC(ObjId).fVabsY;
  pKinematic->fVabsY = *(pt_OUTInput->t_RTE.pf_ObjVabsY(ObjId));
  pKinematic->fAabsX = pt_OUTInput->pt_FIPOA->t_ObjList[ObjId].fAbsAcceleration;
  //pKinematic->fAabsY = OBJ_KINEMATIC(ObjId).fAabsY;
  pKinematic->fAabsY = *(pt_OUTInput->t_RTE.pf_ObjAabsY(ObjId));
#if (SLATE_CFG_TCI_BASE)
  pKinematic->fDistOnTraj = *(pt_OUTInput->t_LAInput.pf_ObjDistOnTraj(ObjId));
#endif
}
#endif

#if (FCT_CFG_SEN2VEH_ACC_OOI_PORT)
/*************************************************************************************************************************
  Functionname:    OUT_v_FillOOIAttributes                                                                              */ /*!

  @brief           Fill OOI Object Attributes

  @description     Fill OOI Object Attributes

                    @startuml
                    Partition #LightBlue FCT_CFG_SEN2VEH_ACC_OOI_PORT{
                    Partition OUT_v_FillOOIAttributes{
                    Start
                    : Fill Attributes CutInOut, Obstacle Probability, Dynamic Property, Life Time, Cycles;
                    End
                    }
                    }
                    @enduml

  @return          -

  @param[in]       ObjId : Objct ID of datatype ObjNumber_t as defined in Rte_Type.h                      [0u   39u]
  @param[in]       eObjOOI : Object of interest enumeration                                               [Full range of datatype eObjOOI_t defined in Rte_Type.h]
  @param[out]      pAttributes                                                                            
                      uiCutInOutProbability : Information describing cut-in/cut-out potential of object   [0u   100u]
                      eDynamicProperty : Indicates whether the object is moving, stationary or oncoming   [type EM_t_GenObjDynamicProperty defined in Rte_Type.h]
                      fLifeTime : Time period since object creation                                       [Full range of datatype float32>=0]
                      uiLifeCycles : Lifetime in terms of number of cycles                                [Full range of AlgoCycleCounter_t defined in Rte_Type.h]
                      eMaintenanceState : Administration state of the object                              [Full range of datatype EM_t_GenObjMaintenanceState defined in Rte_Type.h]
                      uiObjectID : Object ID                                                              [Full range of datatype ObjNumber_t defined in Rte_Type.h] [0u   39u]
                    
  @glob_in         OBJ_GET_CUT_OUT_POTENTIAL(i) : Macro to retrieve cut-out potential of object i with given ObjectID   [0u ... 100u]
  @glob_in         OBJ_GET_CUT_IN_POTENTIAL(i) : Macro to retrieve cut-in potential of object i with given ObjectID     [0u ... 100u]
  @glob_in         pt_OUTInput : Reference to OUT input data structure
                      t_RTE.pt_ObjDynProperty(i) : dynamic property of object "i"               [Full range of datatype SLATE_t_Obj_DynamicProperty as defined in Rte_Type.h]
                      t_RTE.pf_ObjLifeTime(i) : Lifetime of object "i"                          [-2.8595 ... +2.8595]
                      t_RTE.pt_ObjLifeCycles(i) : Lifetime in terms of number of cycles         [Full range of AlgoCycleCounter_t defined in Rte_Type.h]
                      t_RTE.pt_ObjMaintenanceState(i) : Administration state of the object      [Full range of datatype EM_t_GenObjMaintenanceState as defined in Rte_Type.h]
  @glob_out        -

  @c_switch_part   -
  @c_switch_full   FCT_CFG_SEN2VEH_ACC_OOI_PORT : Switch for OOI port to vehicle task
  @c_switch_full   FCT_CFG_ACC_OUTPUT           : Configuration switch to configure OUT (Output) sub-component for FCT_ACC

  @pre             -
  @post            -

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @created         -
  @changed         3/21/2016


  @author          Simon Sinnstein
*************************************************************************************************************************/
static void OUT_v_FillOOIAttributes(const ObjNumber_t ObjId, const eObjOOI_t eObjOOI, AccOOIGenAttributes_t* pAttributes)
{
  /*! Fill Attributes */
  if((eObjOOI == OBJ_NEXT_OOI) || (eObjOOI == OBJ_HIDDEN_NEXT_OOI))
  {
    pAttributes->uiCutInOutProbability = pt_OUTInput->t_SIT.pt_SITObjectList(ObjId)->u_ObjCutOutPotential;
  }
  else
  {
    pAttributes->uiCutInOutProbability = pt_OUTInput->t_SIT.pt_SITObjectList(ObjId)->u_ObjCutInPotential;
  }
  
  pAttributes->eDynamicProperty = SLATE_p_GetEMGenObjAttributes(ObjId)->eDynamicProperty;
  //pAttributes->eDynamicProperty = *pt_OUTInput->t_RTE.pt_ObjDynProperty(ObjId);
  //pAttributes->fLifeTime = OBJ_LIFETIME_SEC(ObjId);
  pAttributes->fLifeTime = *pt_OUTInput->t_RTE.pf_ObjLifeTime(ObjId);
  //pAttributes->uiLifeCycles = SLATE_u_GetObjLifeCycles(ObjId);
  pAttributes->uiLifeCycles = *pt_OUTInput->t_RTE.pt_ObjLifeCycles(ObjId);
#if (OUT_CFG_CUSTOM_OBSTACLE_PROBABILITY)
  pAttributes->uObstacleProbability = *pt_OUTInput->t_RTE.pt_ObjObstacleProbability(ObjId);
#endif /* (OUT_CFG_CUSTOM_OBSTACLE_PROBABILITY) */
  //pAttributes->eMaintenanceState = OBJ_MAINTENANCE_STATE(ObjId);
  pAttributes->eMaintenanceState = *pt_OUTInput->t_RTE.pt_ObjMaintenanceState(ObjId);
  pAttributes->uiObjectID = ObjId;
#if (SLATE_CFG_TCI_BASE)
  pAttributes->b_PlausibleObjMovement = TRUE;
#endif
}
#endif

#if (FCT_CFG_SEN2VEH_ACC_OOI_PORT)
/*************************************************************************************************************************
  Functionname:    OUT_v_DeleteOOIData                                                                                  */ /*!

  @brief           Delete OOI data from last cycle

  @description     Delete OOI data from last cycle

                    @startuml
                    Partition #LightBlue FCT_CFG_SEN2VEH_ACC_OOI_PORT{
                    Partition OUT_v_DeleteOOIData{
                    Start
                    :  Reset Kinematics;
                    : Reset Attributes CutInOut Probability, Dynamic Property,\n LifeTime, LifeCycles, MaintenanceState;
                    End
                    }
                    }
                    @enduml

  @return          -

  @param[in]       -
  @param[out]      pKinematic                                          
                      fDistX : Longitudinal displacement               [-5*RW_FCT_MAX   5*RW_FCT_MAX] m
                      fDistY : Lateral displacement                    [-PI/2*RW_FCT_MAX   PI/2*RW_FCT_MAX] m
                      fVrelY : Lateral (relative) velocity             [-330f   330f] m/s
                      fVrelX : Longitudinal (relative) velocity        [-330f   330f] m/s
                      fArelX : Longitudinal (relative) acceleration    [-100f   100f] m/s^2
                      fArelY : Lateral (relative) acceleration         [-100f   100f] m/s^2
                      fVabsX : Velocity (absolute) in X direction      [-330f   330f] m/s
                      fVabsY : Velocity (absolute) in Y direction      [-330f   330f] m/s
                      fAabsX : Acceleration (absolute) in X direction  [-100f   100f] m/s^2
                      fAabsY : Acceleration (absolute) in Y direction  [-100f   100f] m/s^2
  @param[out]      pAttributes                                                                            
                      uiCutInOutProbability : Information describing cut-in/cut-out potential of object   [0u   100u]
                      eDynamicProperty : Indicates whether the object is moving, stationary or oncoming   [Full range of datatype EM_t_GenObjDynamicProperty as defined in Rte_Type.h]
                      fLifeTime : Time period since object creation                                       [-2.8595 ... +2.8595]
                      uiLifeCycles : Lifetime in terms of number of cycles                                [Full range of AlgoCycleCounter_t as defined in Rte_Type.h]
                      eMaintenanceState : Administration state of the object                              [Full range of datatype EM_t_GenObjMaintenanceState as defined in Rte_Type.h]
                      uiObjectID : Object ID of datatype ObjNumber_t defined in Rte_Type.h                [0u   39u]
                      eUsageState : Usage state of object                                                 [Full range of datatype FCTObjUsageState_t defined in Rte_Type.h]

  @glob_in         -
  @glob_out        -

  @c_switch_part   FCT_CFG_LOHP_COMPONENT      : Configuration switch for enabling LOHP processing
  @c_switch_full   FCT_CFG_SEN2VEH_ACC_OOI_PORT : Switch for OOI port to vehicle task
  @c_switch_full   FCT_CFG_ACC_OUTPUT           : Configuration switch to configure OUT (Output) sub-component for FCT_ACC

  @pre             -
  @post            -

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @created         -
  @changed         3/22/2016


  @author          Simon Sinnstein
*************************************************************************************************************************/
static void OUT_v_DeleteOOIData(AccOOIGenKinematics_t* pKinematic, AccOOIGenAttributes_t* pAttributes)
{
  /*! Reset Kinematics */
  pKinematic->fDistX = 0.f;
  pKinematic->fDistY = 0.f;
  pKinematic->fVrelX = 0.f;
  pKinematic->fVrelY = 0.f;
  pKinematic->fArelX = 0.f;
  pKinematic->fArelY = 0.f;
  pKinematic->fVabsX = 0.f;
  pKinematic->fVabsY = 0.f;
  pKinematic->fAabsX = 0.f;
  pKinematic->fAabsY = 0.f;

  /*! Reset Attributes */
  pAttributes->uiCutInOutProbability = 0u;
  pAttributes->eDynamicProperty = EM_GEN_OBJECT_DYN_PROPERTY_UNKNOWN;
  pAttributes->fLifeTime = 0.f;
  pAttributes->uiLifeCycles = 0u;
  pAttributes->eMaintenanceState = EM_GEN_OBJECT_MT_STATE_DELETED;
  pAttributes->uiObjectID = OBJ_INDEX_NO_OBJECT;
#if (FCT_CFG_LOHP_COMPONENT)
  pAttributes->eUsageState = OBJ_USAGE_IDLE;
#endif
}
#endif

/*************************************************************************************************************************
  Functionname:    OUT_v_SeReObGetRelTrckObjNumber                                                                      */ /*!

  @brief           Get information regarding the tracked relevant objects

  @description     Get information regarding the tracked relevant objects

                   @startuml
                   Partition SISeReObGetRelTrckObjNumber{
                   Start
                   : Return tracked relevant objects;
                   End
                   }
                   @enduml

  @return          iTRCKGetracktesObjekt : Object ID (number) of the tracked object of datatype ObjNumber_t as defined in Rte_Type.h  [-1   39]

  @param[in]       -
  @param[out]      -

  @glob_in         -
  @glob_out        -

  @c_switch_part   -
  @c_switch_full   FCT_CFG_ACC_OUTPUT : Configuration switch to configure OUT (Output) sub-component for FCT_ACC

  @pre             -
  @post            -

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @created         10/22/2001
  @changed         3/23/2016

  @todo            !!!!
                   This function is temporarily renamed to the old prefix structure (with SI) due to compatibility issues with 
                   EBA. The file cd_hypacc.c is using this function. Once FCT400 code is completely restructured (including
                   input/output variables), this function as well as the EBA file have to be updated.
                   !!!!

  @author          R.Ehrhardt
*************************************************************************************************************************/
ObjNumber_t SISeReObGetRelTrckObjNumber( void )
{
  return iTRCKGetracktesObjekt;
}


/*************************************************************************************************************************
  Functionname:    OUT_v_SeReObPutRelTrckObjNumber                                                                      */ /*!

  @brief           Write function for the relevant tracked objects

  @description     Write function for the relevant tracked objects

                   @startuml
                   Partition OUT_v_SeReObPutRelTrckObjNumber{
                   Start
                   : Get Object number of the tracked object;
                   stop
                   }
                   @enduml

  @return          -

  @param[in]       RelTrckObjNr : Tracked relevant object of datatype ObjNumber_t as defined in Rte_Type.h                           [-1   39]
  @param[out]      -

  @glob_in         -
  @glob_out        iTRCKGetracktesObjekt : Object ID (number) of the tracked object of datatype ObjNumber_t as defined in Rte_Type.h [-1   39]

  @c_switch_part   -
  @c_switch_full   FCT_CFG_ACC_OUTPUT : Configuration switch to configure OUT (Output) sub-component for FCT_ACC
  @pre             -
  @post            -

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @created         10/22/2001
  @changed         3/28/2016

  @author          R.Ehrhardt
*************************************************************************************************************************/
void OUT_v_SeReObPutRelTrckObjNumber( ObjNumber_t RelTrckObjNr )
{
  iTRCKGetracktesObjekt = RelTrckObjNr;
}


#endif /* (FCT_CFG_ACC_OUTPUT) */

#if ((FCT_CFG_SEN2VEH_ACC_OOI_PORT) && (OUT_CFG_OVERTAKE_PREVENTION_FEATURE))
/*************************************************************************************************************************
  Functionname:         OUT_v_SetPreventOvertake                                                                     */ /*!

  @brief                Set PreventOvertake feature for relevant OOI

  @description          Set PreventOvertake feature attributes for objects on left and right lane depending on traffic orientation, 
                        and in case of a Highway scenario

                        @startuml
                        Partition #LightBlue FCT_CFG_SEN2VEH_ACC_OOI_PORT&&OUT_CFG_OVERTAKE_PREVENTION_FEATURE{
                        Partition OUT_v_SetPreventOvertake{
                        Start
                        : Get Traffic Orientation, Fused Road Type;
                        If (TRAFFIC ORIENTATION RIGHT) then (TRUE)
                        : Set Attribute PreventOvertake for OOI NEXT LEFT to TRUE;
                        Elseif (TRAFFIC ORIENTATION LEFT) then (TRUE)
                        : Set Attribute PreventOvertake for OOI NEXT RIGHT to TRUE;
                        Else (FALSE)
                        : Set Attribute PreventOvertake for OOI NEXT RIGHT and LEFT to FALSE;
                        Endif
                        End
                        }
                        }
                        @enduml

  @return               -

  @param[in]            - 

  @glob_in              pt_OUTInput->t_FIPInput.pt_FIPTrafficOrientation: FIP Fused Traffic Orientation Value [Full Range of datatype eTrafficOrientation_t as defined in Rte_Type.h] 
  @glob_in              pt_OUTInput->pt_FIPRoadType->t_FIPFusedRoadType:  Reference to FIP road type [Full range of FIP_t_FusedRoadType as defned in fip_ext.h]
  @glob_out             -

  @c_switch_part        FCT_SIM_EXT
  @c_switch_full        OUT_CFG_OVERTAKE_PREVENTION_FEATURE : Activation of Prevent Overtake feature 
  @c_switch_full        FCT_CFG_SEN2VEH_ACC_OOI_PORT : Provide port from SEN to VEH

  @pre                  
  @post                 

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @traceability       287:doors://rbgs854a:40000/?version=2&prodID=0&urn=urn:telelogic::1-503e822e5ec3651e-O-287-00061542 \n
                      288:doors://rbgs854a:40000/?version=2&prodID=0&urn=urn:telelogic::1-503e822e5ec3651e-O-288-00061542 \n 

  @todo                This function considers only the Highway scenario. For a general case solution, the logic should be reviewed and 
                       reconstructed, considering the city scenarios 
 
  @author               Marouane Ben Romdhane | marouane.ben.romdhane@continental-corporation.com | +49 (8382) 9699-402
*************************************************************************************************************************/
static void OUT_v_SetPreventOvertake(void)
{
  SLATE_t_TrafficOrientation t_TrafficOrientation = pt_OUTInput->pt_FIPTO->t_FIPTrafficOrientation;
  FIP_t_FusedRoadType t_FusedRoadType = pt_OUTInput->pt_FIPRoadType->t_FIPFusedRoadType;
  sint8   sNumOfLanesLeft = pt_OUTInput->pt_FIPLaneMatrix->s_NumOfLaneLeft; 
  sint8   sNumOfLanesRight = pt_OUTInput->pt_FIPLaneMatrix->s_NumOfLaneRight;

#ifdef FCT_SIM_EXT
/* FCT_SIM_EXT To have the features (Overtake Support and Prevention) active in carmaker simulation, 
     these hacks are added along with the preprocessor directive that is only existing in the carmaker fct visual studio solution.
     The reason being that all inputs are not provided to SLATE in the carmaker environment. */
  t_TrafficOrientation = SLATE_TRAFFIC_ORIENTATION_RIGHT;
  t_FusedRoadType = FIP_ROAD_TYPE_HIGHWAY;
  sNumOfLanesLeft = (sint8)1;
  sNumOfLanesRight = (sint8)1;
#endif

  switch (t_TrafficOrientation)
  {
  case SLATE_TRAFFIC_ORIENTATION_RIGHT : 
    if (  (pSLATE_AccOOIData->AccOOINextLeft.Attributes.uiObjectID != OBJ_INDEX_NO_OBJECT)
      &&(pSLATE_AccOOIData->AccOOINextLeft.Attributes.eDynamicProperty == EM_GEN_OBJECT_DYN_PROPERTY_MOVING)
      &&(t_FusedRoadType == FIP_ROAD_TYPE_HIGHWAY)
      && (sNumOfLanesLeft > 0))

    {
      pSLATE_AccOOIData->AccOOINextLeft.Attributes.b_PreventOvertake = TRUE;
    }
    break;
  case SLATE_TRAFFIC_ORIENTATION_LEFT :
    if (  (pSLATE_AccOOIData->AccOOINextRight.Attributes.uiObjectID != OBJ_INDEX_NO_OBJECT)
      &&(pSLATE_AccOOIData->AccOOINextRight.Attributes.eDynamicProperty == EM_GEN_OBJECT_DYN_PROPERTY_MOVING)
      &&(t_FusedRoadType == FIP_ROAD_TYPE_HIGHWAY)
      && (sNumOfLanesRight > 0))
    {
      pSLATE_AccOOIData->AccOOINextRight.Attributes.b_PreventOvertake = TRUE;
    }
    break;
  default:
    pSLATE_AccOOIData->AccOOINextLeft.Attributes.b_PreventOvertake = FALSE;
    pSLATE_AccOOIData->AccOOINextRight.Attributes.b_PreventOvertake = FALSE;
    break;
  }
  /* OOI 4 and OOI 5 need not be relevant in some cases as the selection is based on min lateral distance and more longitudinal distance than OOI2 */
  pSLATE_AccOOIData->AccOOIHiddenNextLeft.Attributes.b_PreventOvertake = FALSE;
  pSLATE_AccOOIData->AccOOIHiddenNextRight.Attributes.b_PreventOvertake = FALSE;
}
#endif /* END IF (FCT_CFG_SEN2VEH_ACC_OOI_PORT) && (OUT_CFG_OVERTAKE_PREVENTION_FEATURE) */

/*****************************************************************************
  AUFHEBUNG MODULLOKALER SYMBOLISCHE KONSTANTEN
*****************************************************************************/

/* ************************************************************************* */
/*   Copyright ADC-GmbH, Lindau                                              */
/* ************************************************************************* */
/** @} end defgroup */
