/*! \file **********************************************************************

COMPANY:                   COPYRIGHT (C) Continental AG
  
PROJECT:                   Mainstream

CPU:                       CPU-Independent

COMPONENT:                 CD (Collision Detection)

PACKAGENAME:               cd_wrapper.c

DESCRIPTION:               Implementation of the CD process

AUTHOR:                    $Author: Kanthi, Sheetal (uia80691) (uia80691) $

CREATION DATE:             $Date: 2019/07/17 12:00:22CEST $

VERSION:                   $Revision: 1.56 $

**************************************************************************** */
  
/*****************************************************************************
  INCLUDES
*****************************************************************************/
#include "cd_int.h"
#if (ACDC_CFG_CD)


/*****************************************************************************
  MODULE DESCRIPTION
*****************************************************************************/
/*!
@defgroup cd_wrapper Wrapper
@ingroup cd
@brief              Provides supporting functions for the call of the cd subcomponent. \n\n
@description        This module provides the following functionalities:
                    - Access functions for several global variables: \n
                      @ref GetCDInputData                   \n
                      @ref GetCDStatusInternal              \n
                      @ref GetCDParameters                  \n
                    - Main function of the cd subcomponent: @ref CDProcess
                    - Initialization of the cd subcomponent: @ref CDInit
                    - Deleting and merging of objects: @ref CDDeleteObject, @ref CDMergeObjects, @ref CDMergeDeleteObjectsSameFCTID

@{
*/

/*****************************************************************************
  (SYMBOLIC) CONSTANTS 
*****************************************************************************/

/*****************************************************************************
  FUNCTION 
*****************************************************************************/

static void CDPreProcessing( void );
static void CDPostProcessing(void);


/*************************************************************************************************************************
  Functionname:         CDDeleteObject                                                                               */ /*!

  @brief                Deletes all information of a CD internal objects.

  @description          Checks if the given index is valid. If this is the case the function 
                        @ref CDDeleteInternalObject is called. This function should be called each time an \n
                        object is deleted, to assure that all outdated object information is deleted.

  @return               void

  @param[in]            iObjectToDelete : Index of the object that shall be deleted. @range [0,+...[

  @glob_in              None
  @glob_out             None

  @c_switch_part        None
  @c_switch_full        @ref ACDC_CFG_CD

  @pre                  None
  @post                 None

  @author               Andreas Hartmann
*************************************************************************************************************************/
void CDDeleteObject (ObjNumber_t iObjectToDelete)
{
  if( iObjectToDelete < EM_N_OBJECTS )
  { 
    CDDeleteInternalObject(iObjectToDelete);
  }

  return;
}

/*************************************************************************************************************************
  Functionname:         CDMergeObjects                                                                               */ /*!

  @brief                Handles the merging of CD internal object information in case two objects were merged externally.

  @description          The hypothesis history of the object to be deleted after the merge is added to the object that
                        is kept after the merge. The resulting history is the union of the two merging objects' histories.\n

  @return               void

  @param[in]            iObjectToKeep :   Index of the object that shall be kept after merge. @range [0,+...[
  @param[in]            iObjectToDelete : Index of the object that shall be deleted by merge. @range [0,+...[

  @glob_in              @ref ACDC_p_GetObjHypothesisData \n
                        @ref ACDC_p_ModObjHypothesisData
  @glob_out             @ref ACDC_p_ModObjHypothesisData

  @c_switch_part        None
  @c_switch_full        @ref ACDC_CFG_CD

  @pre                  None
  @post                 None

  @InOutCorrelation     \f$History_{ObjMerged} = History_{ObjKeep} \cup History_{ObjDelete}\f$

  @testmethod           @Generic_Testmethods

  @author               Lukas Stein
*************************************************************************************************************************/
void CDMergeObjects (ObjNumber_t iObjectToKeep, ObjNumber_t iObjectToDelete)
{
  CDHypothesisHist_t const * const pHypHistToDelete = &(ACDC_p_GetObjHypothesisData(iObjectToDelete)->HypothesisHist);
  CDHypothesisHist_t       * const pHypHistToKeep   = &(ACDC_p_ModObjHypothesisData(iObjectToKeep)->HypothesisHist);

  pHypHistToKeep->CutIn           |= pHypHistToDelete->CutIn;
  pHypHistToKeep->Following       |= pHypHistToDelete->Following;
  pHypHistToKeep->Pass            |= pHypHistToDelete->Pass;
  pHypHistToKeep->RunUpLong       |= pHypHistToDelete->RunUpLong;
  pHypHistToKeep->RunUpMoving     |= pHypHistToDelete->RunUpMoving;
  pHypHistToKeep->RunUpStationary |= pHypHistToDelete->RunUpStationary;
  pHypHistToKeep->WasOncomming    |= pHypHistToDelete->WasOncomming;
  pHypHistToKeep->PedColl         |= pHypHistToDelete->PedColl;
  pHypHistToKeep->CrossingLeft    |= pHypHistToDelete->CrossingLeft;
  pHypHistToKeep->CrossingRight   |= pHypHistToDelete->CrossingRight;
  pHypHistToKeep->WasCrossing     |= pHypHistToDelete->WasCrossing;
  pHypHistToKeep->BicycleColl     |= pHypHistToDelete->BicycleColl;
  pHypHistToKeep->TurnIntoVRU     |= pHypHistToDelete->TurnIntoVRU;
  pHypHistToKeep->DriveIntoSloMo  |= pHypHistToDelete->DriveIntoSloMo;


}

/*************************************************************************************************************************
  Functionname:         CDMergeDeleteObjectsSameFCTID                                                                */ /*!

  @brief                CD specific merging and deleting of objects if the object which is merged and 
                        the object into which the old object was merged have the same FCT-ID

  @description          Deletes an object (@ref CDDeleteObject) without loosing the information about its hypotheses history. 

  @return               void

  @param[in]            ObjNr : Index of the considered object. @range [0,+...[

  @glob_in              @ref CDExtObjectsInt
  @glob_out             @ref CDExtObjectsInt

  @c_switch_part        None
  @c_switch_full        @ref ACDC_CFG_CD

  @pre                  None
  @post                 None

  @InOutCorrelation     see description

  @testmethod           @Generic_Testmethods

  @author               Andreas Hartmann
*************************************************************************************************************************/
void CDMergeDeleteObjectsSameFCTID(ObjNumber_t const ObjNr)
{
  /*! Take care: If new information considered here, check if the same information should be considered in CDMergeObjects(...) !!! */
  CDHypothesisHist_t * pObjHypHist = &(ACDC_p_ModObjHypothesisData(ObjNr)->HypothesisHist);

  /*! First: Store the information locally which is considered for merging */
  ubit16_t bCrossingLeft     = pObjHypHist->CrossingLeft;
  ubit16_t bCrossingRight    = pObjHypHist->CrossingRight;
  ubit16_t b_CutIn           = pObjHypHist->CutIn;
  ubit16_t b_Following       = pObjHypHist->Following;
  ubit16_t b_Pass            = pObjHypHist->Pass;
  ubit16_t b_RunUpLong       = pObjHypHist->RunUpLong;
  ubit16_t b_RunUpMoving     = pObjHypHist->RunUpMoving;
  ubit16_t b_RunUpStationary = pObjHypHist->RunUpStationary;
  ubit16_t b_WasOncomming    = pObjHypHist->WasOncomming;
  ubit16_t b_WasCrossing     = pObjHypHist->WasCrossing;
  ubit16_t b_PedColl         = pObjHypHist->PedColl;
  ubit16_t b_BicycleColl     = pObjHypHist->BicycleColl;
  ubit16_t b_TurnIntoVRU     = pObjHypHist->TurnIntoVRU;
  ubit16_t b_DriveIntoSloMo  = pObjHypHist->DriveIntoSloMo;

  /*! Second: Delete the FCT-object */
  CDDeleteObject (ObjNr);

  /*PRQA S 4461 16*/ /* date: 2019-05-20, reviewer: Schnurr, Clemens, reason: Type differences only due to autopropagation due to different typing in connection with bit fields.*/
  /*! Third: Copy merge-information */
  pObjHypHist->CrossingLeft    |= bCrossingLeft;
  pObjHypHist->CrossingRight   |= bCrossingRight;
  pObjHypHist->CutIn           |= b_CutIn;
  pObjHypHist->Following       |= b_Following;
  pObjHypHist->Pass            |= b_Pass;
  pObjHypHist->RunUpLong       |= b_RunUpLong;
  pObjHypHist->RunUpMoving     |= b_RunUpMoving;
  pObjHypHist->RunUpStationary |= b_RunUpStationary;
  pObjHypHist->WasOncomming    |= b_WasOncomming;
  pObjHypHist->WasCrossing     |= b_WasCrossing;
  pObjHypHist->PedColl         |= b_PedColl;
  pObjHypHist->BicycleColl     |= b_BicycleColl;
  pObjHypHist->TurnIntoVRU     |= b_TurnIntoVRU;
  pObjHypHist->DriveIntoSloMo  |= b_DriveIntoSloMo;
}

/*************************************************************************************************************************
  Functionname:         CDInit                                                                                       */ /*!

  @brief                Initializes all cd modules and cd global variables. 

  @description          All global variables listen in the global out tag are initialized. Also all initialization 
                        functions of the Modules inside CD are called. CDInit should be called if CD is in the operation mode INIT.
                        @startuml CDInit_activity.png
                        start
                          #Orange:Delete the external object input:
                          <b>CDDeleteInternalObject</b> >
                          :Initialize the internal status and the output data;
                          #Orange: Initialize the Customer specific data:
                          <b>CDInitCustomerData</b> >

                        stop
                        @enduml
  @return               void

  @param[in]            void

  @glob_in              None
  @glob_out             @ref CDInputData \n
                        @ref CDAdjSafeDistanceInt \n
                        @ref CDParameters \n
                        @ref CDExtObjectsInt \n
                        @ref CDStatusInt

  @c_switch_part        @ref CD_USE_HYPOTHESIS_RELATION \n
  @c_switch_full        @ref ACDC_CFG_CD

  @pre                  None
  @post                 All cd modules and global variables are initialized.

  @InOutCorrelation     see description

  @testmethod           @Generic_Testmethods

  @author               Dominik Froehlich
*************************************************************************************************************************/
/*PRQA S 1505 1*//*CDInit is also called by simulation functions*/
void CDInit( void )
{
  ObjNumber_t iObjectIndex;
  uint32      uiHypIndex;

  /* Parameter for longitudinal acceleration*/
  ACDC_p_ModCDParameters()->AdjSafeDistance.fLongNecRemainDist = CD_LONG_SAFETY_DISTANCE;
  /* Parameter for lateral acceleration*/
  ACDC_p_ModCDParameters()->AdjSafeDistance.fLatNecRemainDist  = CD_LAT_SAFETY_DISTANCE;

  /* --- State --- */

  for( uiHypIndex = 0u; uiHypIndex < CD_NUMBER_OF_HYPOTHESES; uiHypIndex++ )
  {
    ACDC_p_ModCurrentIntHypothesis(uiHypIndex)->eType     = CDHypothesisType_No;
    ACDC_p_ModPrevIntHypothesis(uiHypIndex)->eType = CDHypothesisType_No;
  }
  
  /* initialize internal objects */
  for(iObjectIndex=0 ; iObjectIndex < EM_N_OBJECTS ; iObjectIndex++)
  {
    CDDeleteInternalObject( iObjectIndex );
  }

  /* Initialize customer specific data */
  CDInitCustomerData();

}


/*************************************************************************************************************************
  Functionname:         CDProcess                                                                                    */ /*!

  @brief                The function is called by the global main routine and calls all necessary functions of the CD component.

  @description          Depending on the operation mode, CD follows two different sequences:
                        - OpMode OK: \n
                          Calls the functions @ref CDPreProcessing and @ref CDRun.
                        - OpMode INIT: \n
                          Calls the function @ref CDInit.
                        .
                        In both cases afterwards the Error Flag is checked. If it has not been set by CDRun, 
                        the function @ref CDPostProcessing is called and the MeasData is freezed. Otherwise CDInit is called.
                        @startuml CDProcess_activity.png
                        start
                          :Set CDState init, if CDInit 
                          has not been called;
                          if(Check CDState) then (Ok)
                            #Orange:Trigger PreProcessing of CD:
                            <b>CDPreProcessing</b> >
                            #Orange:Execute main Function of CD:
                            <b>CDRun</b> >
                          else (Init)
                            #Orange:Initialize CD:
                            <b>CDInit</b> >
                          endif
                          if(Error detected during main function call?) then (Yes)
                            #Orange:Initialize CD:
                            <b>CDInit</b> >
                          else(No)
                            #Orange:Execute the CD PostProcessing:
                            <b>CDPostProcessing</b> >
                          endif
                        stop
                        @enduml
  @return               void

  @param[in]            void

  @glob_in              @ref ACDC_e_GetSubCompState \n
                        @ref ACDC_p_GetMostRelevantEPFHyp
  @glob_out             None

  @c_switch_part        @ref CD_USE_EPF
  @c_switch_full        @ref ACDC_CFG_CD

  @pre                  None
  @post                 None

  @InOutCorrelation     see description

  @testmethod           @Generic_Testmethods

  @author               Dominik Froehlich
*************************************************************************************************************************/
void CDProcess( void )
{
  ACDCCompState_t                 CDState         = ACDC_e_GetSubCompState(ACDC_SUB_COMP_CD);
  eGDBError_t                     locError        = GDB_ERROR_NONE;

  switch (CDState)
  {
    case COMP_STATE_RUNNING:
      /* Pre processing */
      /*PRQA S 2987 1*/ /* date: 2019-05-14, reviewer: Schnurr, Clemens, reason: May be without side effect in certain configurations. Keep it to keep structure same in all configs*/
      CDPreProcessing();

      /* Run algo */
      locError = CDRun();
      break;

    case COMP_STATE_NOT_INITIALIZED:
    case COMP_STATE_TEMPORARY_ERROR:
    case COMP_STATE_PERMANENT_ERROR:
    default:
      /* Initialize CD */
      CDInit();
      break;
  }

  if(locError == GDB_ERROR_NONE)
  {
#if (CD_USE_EPF)
    {
      /* Determine relevant object */
      ObjNumber_t RelObjID                        = OBJ_INDEX_NO_OBJECT;
      eCDHypothesisType_t eMostRelevantEPFHypType = ACDC_p_GetMostRelevantEPFHyp()->eType;
      
      if (    (eMostRelevantEPFHypType == CDHypothesisType_Collision           )
           || (eMostRelevantEPFHypType == CDHypothesisType_CollisionUnavoidable)
           || (eMostRelevantEPFHypType == CDHypothesisType_RunUpStationary     )
           || (eMostRelevantEPFHypType == CDHypothesisType_RunUp               )
           || (eMostRelevantEPFHypType == CDHypothesisType_RunUpBraking        )
           || (eMostRelevantEPFHypType == CDHypothesisType_RunupCoMoving       )
           || (eMostRelevantEPFHypType == CDHypothesisType_PedCollision        )
           || (eMostRelevantEPFHypType == CDHypothesisType_PedPass             )
           || (eMostRelevantEPFHypType == CDHypothesisType_CyclColl            ) )
      {
        RelObjID = ACDC_p_GetMostRelevantEPFHyp()->uiObjectRef;
      }
      EPFProcess(RelObjID, &(ACDC_p_ModCDCustomOutput()->EPFOutput));
    }
#endif /* CD_USE_EPF */

    /* Post processing */
    CDPostProcessing();

  }
  else
  {
    /*reinit in case of error*/
    CDInit();
  }

  ACDC_v_SetSubComponentStates(ACDC_SUB_COMP_CD,CDState);
}

/*************************************************************************************************************************
  Functionname:         CDPreProcessing                                                                              */ /*!

  @brief                Processing before CD hypothesis calculation

  @description          Currently empty
                        
  @return               void

  @glob_in              None
  @glob_out             @ref CDExtObjectsInt

  @c_switch_part        None
  @c_switch_full        @ref ACDC_CFG_CD

  @pre                  None
  @post                 None

  @InOutCorrelation     - **Formulas Ego Kinematics:**\n
                          \f$A_{X,ACDC} = A_{VDY}\f$\n
                          \f$A_{Y,ACDC} = V_{VDY} \cdot YawRate_{VDY}\f$\n
                          \f$V_{X,ACDC} = V_{VDY}\f$\n
                          \f$V_{Y,ACDC} = 0\f$

  @testmethod           @Generic_Testmethods

  @author               Dominik Froehlich
*************************************************************************************************************************/
static void CDPreProcessing(void)
{

}

/*************************************************************************************************************************
  Functionname:         CDPostProcessing                                                                             */ /*!

  @brief                Handles all post processing steps at the end of the call of the cd subcomponent.

  @description          The following tasks are covered by this function:
                        - Writing of the sensor source information to the output. 
                          (=which sensors participated in the measurement)
                        - Recalculation of the AnecLong on base of customer specific safety distance for all 
                          hypothesis relevant objects: @ref CDCalculateAnecLongLatency
                        @startuml CDPostProcessing_activity.png
                        start
                          :Write degradation and sensor 
                          source information to the output;
partition #LightBlue "**FCT_CFG_CD_CUSTOM_OUTPUT_INTERFACE &&**\n**CFG_FCT_VEH_EBA_INTF**" {
                          partition "Execute for all hypotheses"{
                            if(Hypothesis and corresponding object are valid?) then (Yes)
                              :1}
                              #Orange:Recalculate the ANecLong:
                              <b>CDCalculateAnecLongLatency</b> >
                            else(No)
                              :2}
                              :fAccel = 0;
                            endif
                          :Write output;
                          }
}
                        stop
                        @enduml
  @return               void

  @param[in]            None

  @glob_in              @ref ACDC_p_GetExtHypothesis\n
                        @ref ACDC_p_GetEMFusionObjList\n
                        @ref ACDC_p_GetEMGenObjList\n
  @glob_out             @ref ACDC_p_ModCDCustomOutput \n
                        @ref ACDC_p_ModExtHypothesis

  @c_switch_part        @ref CD_USE_CUSTOM_ANEC_LONG            \n
                        @ref FCT_CFG_CD_CUSTOM_OUTPUT_INTERFACE \n
                        @ref EM_GEN_OBJECT_LIST_INTFVER         \n
                        @ref FCT_CFG_INCLUDE_FUSION_OBJECT_LIST
  @c_switch_full        @ref ACDC_CFG_CD

  @pre                  None
  @post                 None

  @InOutCorrelation     see description

  @testmethod           @Generic_Testmethods

  @author               Dominik Froehlich
*************************************************************************************************************************/
static void CDPostProcessing(void)
{
    
#if (FCT_CFG_INCLUDE_FUSION_OBJECT_LIST == SWITCH_ON)
    ACDC_p_ModHypothesisIntf()->Header.eObjListDegraded = ACDC_p_GetEMFusionObjList()->HeaderObjList.eObjListDegraded;
#endif
#if (EM_GEN_OBJECT_LIST_INTFVER >= 0x30000)
    ACDC_p_ModHypothesisIntf()->Header.eObjListSource   = ACDC_p_GetEMGenObjList()->HeaderObjList.eObjListSource;
#endif
#if (FCT_CFG_CD_CUSTOM_OUTPUT_INTERFACE && CFG_FCT_VEH_EBA_INTF)
  { /* Output iBrake specific long. acceleration (collision prevention) */ 
    sint32 ii;
    float32 fAccel;
    CDAdjSafeDistance_t safe_dist;

    /* set customer safety distance */
    safe_dist.fLongNecRemainDist = CD_LONG_SAFETY_DIST_CUST;
    safe_dist.fLatNecRemainDist  = 0.f;

    for (ii = 0; ii< (sint32)CD_NUMBER_OF_HYPOTHESES; ii++)
    {
      Hypothesis_t * const pCurrHypo = ACDC_p_ModExtHypothesis(ii);

      if (    (pCurrHypo->eType       != (eCDHypothesisType_t)CDHypothesisType_No)
           && (pCurrHypo->uiObjectRef >= 0                                       ) )
      {
        /* Select object */
        const ObjNumber_t objIdx = pCurrHypo->uiObjectRef;

        /* set object movement */
        if (objIdx != OBJ_INDEX_NO_OBJECT)
        {
          /* Calculate acceleration */
          (void)CDCalculateAnecLongLatency( &safe_dist, objIdx, &fAccel );
        }
        else
        {
          /* This case may never happen */
          ACDC_ASSERT(FALSE);
          fAccel = 0.f;
        }
      }
      else
      {
        fAccel = 0.f;
      }
      /* Write output */
#if(FCT_CFG_CD_CUSTOM_OUTPUT_INTERFACE)
      ACDC_p_ModCDCustomOutput()->iBrkOutput.AnecLong[ii] = fAccel;
#endif
#if defined (CD_USE_CUSTOM_ANEC_LONG) && (CD_USE_CUSTOM_ANEC_LONG == SWITCH_ON)
      pCurrHypo->Custom.fLongNecAccelCustom = fAccel;
#endif
    }
    /* Make signal available for data acquisition support over vehicle network 
     *
     * @attention Check if the iBrkOutput.AllowedDistance distance matches the
     * max. distance configured in the PreBrake function activation conditions.
     */
#if defined (ESPM_CFG_USE_SPM_OUTPUT)
#if(ESPM_CFG_USE_SPM_OUTPUT) && (FCT_CFG_CD_CUSTOM_OUTPUT_INTERFACE)
    ACDC_p_ModCDCustomOutput()->iBrkOutput.AllowedDistance = ACDC_p_GetHypothesisIntf()->Degradation.Safety.fMaxDist;
#endif
#endif

  }
#endif  /* #if (FCT_CFG_CD_CUSTOM_OUTPUT_INTERFACE) */
}


///@}
#endif  /* ACDC_CFG_CD */

