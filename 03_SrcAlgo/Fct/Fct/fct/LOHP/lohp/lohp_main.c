/*! \file **********************************************************************

COMPANY:                   COPYRIGHT (C) Continental AG

PROJECT:                   Adaptive Cruise Control (ACC)

CPU:                       CPU-Independent

COMPONENT:                 ACC/LOHP (Adaptive Cruise Control - Longitudinal Headway Planner)

PACKAGENAME:               lohp_main.c

DESCRIPTION:               Main functions for LOHP

AUTHOR:                    Mistry Niraj (uidq5738)

CREATION DATE:             24.02.2017

VERSION:                   $Revision: 1.31 $

LEGACY VERSION:            Revision: 2.2

**************************************************************************** */

/*****************************************************************************
  MODULE DESCRIPTION
*****************************************************************************/
/*!
@defgroup   lohp_main Lohp_main
@ingroup    lohp_base_lohp
@brief      Main functions for LOHP base module
@{ */ 

/*****************************************************************************
  INCLUDES
*****************************************************************************/

#include "lohp.h"

#if ((FCT_CFG_LOHP_COMPONENT) && (FCT_CFG_ACC_HEADWAY_PLANNER))


#include "fct_par.h"

#if ((!FCT_CFG_CC) && (FCT_CFG_ACC_HEADWAY_PLANNER))
#error "FCT_CFG_ACC_HEADWAY_PLANNER needs FCT_CFG_CC!"
#endif

#if (((FCT_CFG_FCA) || (FCT_CFG_DM)) && (!FCT_SEN_CFG_VEH_SIG_INPUT))
#error The DM/FCA function depends on direct access to vehicle signals! Please enable FCT_SEN_CFG_VEH_SIG_INPUT!
#endif

/*****************************************************************************
  MODULE LOCAL SYMBOLIC CONSTANTS
*****************************************************************************/

/*****************************************************************************
  MODULE LOCAL MACROS
*****************************************************************************/

/*****************************************************************************
  MODULE GLOBAL TYPEDEFS
*****************************************************************************/

/*****************************************************************************
  MODULE GLOBAL VARIABLES
*****************************************************************************/

SET_MEMSEC_VAR(HP_t_State)
HPState_t HP_t_State;       /*!< Operating modes of HP sub-component */

/* HP static memory union containing all HP, FCA and DM Inputs and Outputs */
static hp_static_mem_u_t HP_STATIC_MEM_UNION;

#if ( LOHP_CFG_PRED )
  static PRED_StaticMemUnion_u_t PRED_STATIC_MEM_UNION;
#endif


/*****************************************************************************
  MODULE LOCAL TYPES
*****************************************************************************/
  
/*****************************************************************************
  MODULE LOCAL CONSTANTS
*****************************************************************************/

/*****************************************************************************
  MODULE LOCAL VARIABLES
*****************************************************************************/

/*****************************************************************************
  MODULE LOCAL FUNCTIONS
*****************************************************************************/



/*************************************************************************************************************************
  Functionname:    LOHP_v_Init                                                                                    */ /*!

  @brief           Initialize LOHP internal data

  @description     Initialize LOHP internal data

					@startuml
					Start
						Partition LOHP_v_Init {
						 -initialize acc output data to neutral values
						 -Initialize internal module static data 
						 -Reset ooi UsageState of all six object 
					}
					End	
					@enduml

  @return          -

  @param[in,out]   pAccDisplayObj
  @param[in,out]   pAccOutput
  @param[in,out]   pLOHPUsageState
                  
  @c_switch_part   FCT_CFG_DM : Configuration switch for enabling DM processing
  @c_switch_part   FCT_CFG_FCA : Configuration switch for enabling FCA processing
  @c_switch_full   FCT_CFG_ACC_HEADWAY_PLANNER : Configuration switch for enabling ACC processing
  @c_switch_full   FCT_CFG_LOHP_COMPONENT : Configuration switch for LOHP component
                   
  @pre             -
  @post            -
                   
  @created         -
  @changed         4/20/2016

  @author          -
*************************************************************************************************************************/
void LOHP_v_Init(acc_object_t* pAccDisplayObj, acc_output_data_t* pAccOutput, LOHP_ObjUsageState_t * pLOHPUsageState)
{
#if (FCT_CFG_DM)
  DM_v_OutInit(&HP_STATIC_MEM_UNION.HP_STATIC_MEMORY.DM_OUTPUT_DATA);
  DM_v_Init(&HP_STATIC_MEM_UNION.HP_STATIC_MEMORY.DM_STATUS);
#endif

#if (FCT_CFG_FCA)
  FCA_v_OutInit(&HP_STATIC_MEM_UNION.HP_STATIC_MEMORY.FCA_OUTPUT_DATA);
#endif

#if (LOHP_CFG_PRED)
  PRED_v_Init( &PRED_STATIC_MEM_UNION.PRED_StaticMemory );
#endif
  
  HP_v_Init
  (  &HP_STATIC_MEM_UNION.HP_STATIC_MEMORY.ACC_ALERT_OBJECT
   , &HP_STATIC_MEM_UNION.HP_STATIC_MEMORY.ACC_STATUS
   , &HP_STATIC_MEM_UNION.HP_STATIC_MEMORY.ACC_INPUT_DATA
   , HP_STATIC_MEM_UNION.HP_STATIC_MEMORY.ACC_OBJECT_LIST
  );

    HP_v_OutInit
  (  pAccDisplayObj
   , pAccOutput
  );

  /* Initialization of LOHP provide port which is fused with FCTSenACCOOI Port */
  pLOHPUsageState->UsageState_OOI_0 = 0u;
  pLOHPUsageState->UsageState_OOI_1 = 0u;
  pLOHPUsageState->UsageState_OOI_2 = 0u;
  pLOHPUsageState->UsageState_OOI_3 = 0u;
  pLOHPUsageState->UsageState_OOI_4 = 0u;
  pLOHPUsageState->UsageState_OOI_5 = 0u;
}

/*****************************************************************************

  @fn             LOHP_v_Process */ /*!

  @description    Execute longitudinal headway planner functions (object dependent functions)

				  @startuml
					Start
						Partition LOHP_v_Process {
						 If(Is there software or Hardware rest \n  or HP init mode request) then (True)
	 						-Execute initialization function for LOHP
						Else (False)
						Endif	
	
						If(HP state in init mode) Then (True)
							-Execute initialization function for LOHP
						Elseif(Normal operation mode)
							If(If uSPMBlockageState flag is set) then (Yes)
							-Set the blockage flag for ACC inputdata Inhibition
							Else(No)
							-Clear the blockage flag
							Endif 

							If(uSPMSelfTestState is not set to AL_ERR_STATE_INACTIVE)then(True)
							-Set the selftest flag 
							Else(False)
							-Clear the selftest flag 
							endif

							-Set the CheckState flag based on blockage,\n Selftest flag or alignment state
							-Set output inhibition reason based on blockage,selftest and alignment state 

							-Call the HP pre-process function 
							-Call the HP process function 

							- Reset ooi UsageState of all six object
							- Set usage state for OOi to control object 
							- Set usage state for OOi to display object
							- Set usage state for OOi to alert object
						  Else(Default)		
							- Execute the Initialization of LOHP function.
						Endif
						- Set the output port version numbers
						- Freeze HP Data
					}	
					End	
				 @enduml



  @param[in]      cycle_time: the cycle time since last call
  @param[in]      pSysPerfMonStates: SPM output struct
  @param[in]      pAlnMon: pointer to the alignment monitoring output
*/
#if (FCT_USE_EM_GENERIC_OBJECT_LIST)
/*!
  @param[in]      pEmGenObjList: EM Object List
*/
#if (FCT_USE_EM_ARS_TECH_OBJECT_LIST)
/*!
  @param[in]      pEmARSObjList: EM Object List
*/
#endif
#else
/*!
  @param[in]      pEmObjList: EM Object List
*/
#endif
/*!
  @param[in]      pFctObjList: FCT Object List
  @param[in]      pVehDyn
*/
#if (FCT_SEN_CFG_VEH_SIG_INPUT)
/*!
  @param[in]      pVehSig
*/
#endif
#if (FCT_CFG_SLATE_COMPONENT)
/*!
  @param[in]      pSLATEData: SLATE output data struct
*/
#endif
#if (FCT_CFG_CUSTOM_IO_INTERFACE)
/*!
  @param[in]      pCustomInput: Custom Input port to FCT
*/
#if (FCT_CFG_CUSTOM_IO_ABS_KINEMATIC)
/*!
  @param[in]      pCustomOutputInput: Custom output port from FCT
  */
#endif
#endif
/*!
  @param[in]      pFctVehLongOut
*/
#if (FCT_CFG_SEN2VEH_ACC_OOI_PORT)
/*!
  @param[in]      pFCTAccOOIData: SLATE 6 ACC object list port
  @param[in]      pLOHPUsageState: LOHP output port for object state of usage
*/
#endif
/*!
  @param[out]     pAccDisplayObj pointer to the ACC display object passed to LOPC
  @param[out]     pAccOutput pointer to the ACC control output data passed to LOPC

  @return         void

  @traceability   doors://rbgs854a:40000/?version=2&prodID=0&view=00000002&urn=urn:telelogic::1-503e822e5ec3651e-O-114-0008a201

*****************************************************************************/
void LOHP_v_Process(const times_t             cycle_time,
#if (FCT_CFG_SIGNAL_PERF_MONITORING)
                    const SysPerfMonStates_t * pSysPerfMonStates,
#endif
                    const ALN_S_Monitoring_t * pAlnMon,
#if (FCT_USE_EM_GENERIC_OBJECT_LIST)
                    const EM_t_GenObjectList * pEmGenObjList,
#if (FCT_USE_EM_ARS_TECH_OBJECT_LIST)
                    const EM_t_ARSObjectList * pEmARSObjList,
#endif
#else
                    const ObjectList_t      * pEmObjList,
#endif
                    const AssessedObjList_t * pFctObjList,
                    const VehDyn_t          * pVehDyn,
#if (FCT_SEN_CFG_VEH_SIG_INPUT)
                    const VehSig_t          * pVehSig,
#endif
#if (FCT_CFG_SLATE_COMPONENT)
                    const SLATE_HC_Data_t   * pSLATEData,
#endif
#if (FCT_CFG_CUSTOM_IO_INTERFACE)
                    const FCTCustomInput_t  * pCustomInput,
#if (FCT_CFG_CUSTOM_IO_ABS_KINEMATIC)
                    const FCTCustomOutput_t * pCustomOutputInput,
#endif
#endif
                    const FctVeh2SenInfo_t  * pFctVehLongOut,
#if (FCT_CFG_SEN2VEH_ACC_OOI_PORT)
                    const FCTSenAccOOI_t    * pFCTAccOOIData,
                    LOHP_ObjUsageState_t    * pLOHPUsageState,
#endif
                    acc_object_t            * pAccDisplayObj,
                    acc_output_data_t       * pAccOutput)
{
#if (FCT_CFG_ACC_HEADWAY_PLANNER) || (FCT_CFG_FCA) || (FCT_CFG_DM)
  acc_input_data_t * const acc_input_data_ptr = &HP_STATIC_MEM_UNION.HP_STATIC_MEMORY.ACC_INPUT_DATA;

#if (FCT_CFG_FCA)
  fca_output_data_t fca_output_data;
#endif
#if (FCT_CFG_DM)
  dm_output_data_t dm_output_data;
#endif
#endif

  boolean CheckState;
  boolean b_Blockage;
  boolean b_SelfTest;

  switch(HP_t_State)
  {
    case HP_INIT:
    {
      /*! Initialization */
      LOHP_v_Init(pAccDisplayObj, pAccOutput, pLOHPUsageState);
      break;
    }

    case HP_OK:
    { /*! Functions calls for normal operation mode */

      if (pSysPerfMonStates->uSPMBlockageState == AL_ERR_STATE_ACTIVE)
      {
        b_Blockage = TRUE;
      }
      else
      {
        b_Blockage = FALSE;
      }
      if (pSysPerfMonStates->uSPMSelfTestState != AL_ERR_STATE_INACTIVE)
      { /* Self test is in progress or failed */
        b_SelfTest = TRUE;
      }
      else
      {
        b_SelfTest = FALSE;
      }

      /* Check sensor system state */
      CheckState =  (boolean)
                    (
                      (pAlnMon->e_AlignState != ALNMonNormal) ||  /*!< alignment not in normal state */
                      (b_Blockage) ||                             /*!< sensor is blocked */
                      (b_SelfTest)                                /*!< Self test is running or failed */
                    );
      /* Do not check the blockage and alignment states during simulation */
#if (defined(_MSC_VER))
      CheckState = FALSE;
#endif

      /*! Determine alignment inhibition reason */
      /*! Attention INHIBITION_REASON is a Bit Field */
      if(pAlnMon->e_AlignState == ALNMonInit) // PRQA S 505
      /* date: 2015-09-16, reviewer: Chirag Patel, reason: being checked before calling this function  */
      {
        pAccOutput->ACC_OUTPUT_STATUS.INHIBITION_REASON = Acc_inhibition_alignment_init;
      }
      else if(pAlnMon->e_AlignState == ALNMonPermanentlyNotAligned)
      {
        pAccOutput->ACC_OUTPUT_STATUS.INHIBITION_REASON = Acc_inhibition_alignment;
      }
#if (ALN_MONITORING_VERSION < 100)
      else if(pAlnMon->e_AlignState == ALNMonPartialBlockage)
      {
        pAccOutput->ACC_OUTPUT_STATUS.INHIBITION_REASON = Acc_inhibition_partial_blockage;
      }
#endif
      else
      {
        pAccOutput->ACC_OUTPUT_STATUS.INHIBITION_REASON = Acc_inhibition_none;
      }
      /*! Add blockage inhibition reason if exists */
      if(b_Blockage)
      {
        pAccOutput->ACC_OUTPUT_STATUS.INHIBITION_REASON |= Acc_inhibition_blockage;
      }
      else
      {
        pAccOutput->ACC_OUTPUT_STATUS.INHIBITION_REASON |= Acc_inhibition_none;
      }
#if (FCT_ACC_OUTPUT_DATA_INTFVER >= 4)
      if(b_SelfTest)
      {
        pAccOutput->ACC_OUTPUT_STATUS.INHIBITION_REASON |= Acc_inhibition_selftest;
      }
#endif

      /*end reading data from VDATA*/

      HP_v_PreProcess(cycle_time,
                      pFctVehLongOut,
                      pVehDyn,
                      pSLATEData,
                      pFCTAccOOIData,
#if (FCT_CFG_CUSTOM_IO_INTERFACE)
                      pCustomInput,
#endif
                      HP_STATIC_MEM_UNION.HP_STATIC_MEMORY.ACC_OBJECT_LIST,
                      acc_input_data_ptr,
                      pAccOutput);

      /*------------------------------- data wrapping done ----------------------------------------------*/

      /* Inhibition buffer replaced by boolean to test if signals are correct.  */
      acc_input_data_ptr->INPUT_STATUS.INHIBIT = CheckState;

      HP_v_Process
      (  cycle_time
       , acc_input_data_ptr
       , HP_STATIC_MEM_UNION.HP_STATIC_MEMORY.ACC_OBJECT_LIST
       , pAccOutput
       , &HP_STATIC_MEM_UNION.HP_STATIC_MEMORY.ACC_ALERT_OBJECT
       , pAccDisplayObj
       , &HP_STATIC_MEM_UNION.HP_STATIC_MEMORY.ACC_STATUS
      );

#if ( LOHP_CFG_PRED )
      PRED_v_PreProcess
      (  acc_input_data_ptr->LONG_VELOCITY
       , &pSLATEData->t_SLATE_Navi
       , &PRED_STATIC_MEM_UNION.PRED_StaticMemory
      );
      
      PRED_v_Process
      (  acc_input_data_ptr->LONG_VELOCITY
       , &PRED_STATIC_MEM_UNION.PRED_StaticMemory
       , pAccOutput
      );
#endif

#if (FCT_CFG_SEN2VEH_ACC_OOI_PORT)
      /* Initialisation of LOHP provide port which is fused with FCTSenACCOOI Port, is done every cycle */
      pLOHPUsageState->UsageState_OOI_0 = 0u;
      pLOHPUsageState->UsageState_OOI_1 = 0u;
      pLOHPUsageState->UsageState_OOI_2 = 0u;
      pLOHPUsageState->UsageState_OOI_3 = 0u;
      pLOHPUsageState->UsageState_OOI_4 = 0u;
      pLOHPUsageState->UsageState_OOI_5 = 0u;

      /*! Copy usage attribute to FCTSenAccOOI Port */
      /*! CONTROL_OBJECT */
      HP_v_CopyObjectUsage
      (  pFCTAccOOIData
       , HP_STATIC_MEM_UNION.HP_STATIC_MEMORY.ACC_STATUS.ACC_CONTROL_OBJECT.AUTOSAR.OBJECT_ID
       , OBJ_USAGE_CONTROL
       , pLOHPUsageState
      );
      /*! DISPLAY__OBJECT */
      HP_v_CopyObjectUsage
      (  pFCTAccOOIData
       , pAccDisplayObj->AUTOSAR.OBJECT_ID
       , OBJ_USAGE_DISPLAY
       , pLOHPUsageState
      );
      /*! ALERT__OBJECT */
      HP_v_CopyObjectUsage
      (  pFCTAccOOIData
       , HP_STATIC_MEM_UNION.HP_STATIC_MEMORY.ACC_ALERT_OBJECT.AUTOSAR.OBJECT_ID
       , OBJ_USAGE_ALERT
       , pLOHPUsageState
      );
#endif

#if (FCT_CFG_FCA) 
      fca_output_data = HP_STATIC_MEM_UNION.HP_STATIC_MEMORY.FCA_OUTPUT_DATA;
      /*wrapper for FCA_INPUT_DATA*/
#if 1
#pragma COMPILEMSG("FCA_INPUT_DATA does not have an INPUT_STATUS field in any revision I can find! Confirm removal!")
#else
      HP_STATIC_MEM_UNION.HP_STATIC_MEMORY.FCA_INPUT_DATA.INPUT_STATUS.INHIBIT            = FALSE;
#endif
      /* @todo: Note: pLongCtrlResp pointer has been removed, if the information about driver braking still
      necessary here, then add to FctVeh2Sen_t */
#error Clarify if BRAKE_STATUS bits can be/need be set!
      HP_STATIC_MEM_UNION.HP_STATIC_MEMORY.FCA_INPUT_DATA.BRAKE_STATUS.PEDAL_INIT_TRAVEL  = (pLongCtrlResp != NULL && pLongCtrlResp->KinCtrlDynInput.driver_braking);
      HP_STATIC_MEM_UNION.HP_STATIC_MEMORY.FCA_INPUT_DATA.BRAKE_STATUS.BRAKE_FAILED       = 0; /*!!!where to find?*/
      HP_STATIC_MEM_UNION.HP_STATIC_MEMORY.FCA_INPUT_DATA.BRAKE_STATUS.OVER_HEATED        = 0;  /*!!!where to find?*/
      HP_STATIC_MEM_UNION.HP_STATIC_MEMORY.FCA_INPUT_DATA.CONTROL.FCA_ON                  = TRUE; /*!!! use driver inputs and cfg to determine if fca is activated*/
      HP_STATIC_MEM_UNION.HP_STATIC_MEMORY.FCA_INPUT_DATA.CONTROL.INHIBIT                 = FALSE; /*!!! where to find?*/
#if (CFG_FCT_USE_VDY_HOST_VELOCITY)
      HP_STATIC_MEM_UNION.HP_STATIC_MEMORY.FCA_INPUT_DATA.LONG_VELOCITY                   = (velocity_t)(pVehDyn->Longitudinal.VeloCorr.corrVelo * Velocity_s);
#else
      HP_STATIC_MEM_UNION.HP_STATIC_MEMORY.FCA_INPUT_DATA.LONG_VELOCITY                   = (velocity_t)(CAN0InputData.VxVehicle * Velocity_s);
#endif
#if (CFG_FCT_USE_VDY_HOST_ACCEL)
      HP_STATIC_MEM_UNION.HP_STATIC_MEMORY.FCA_INPUT_DATA.LONG_ACCELERATION               = (acceleration_t)(pVehDyn->Longitudinal.MotVar.Accel * Acceleration_s);
#else
      HP_STATIC_MEM_UNION.HP_STATIC_MEMORY.FCA_INPUT_DATA.LONG_ACCELERATION               = pLongCtrlResp->KinCtrlDynInput.longi_initialization_accel;
#endif
      HP_STATIC_MEM_UNION.HP_STATIC_MEMORY.FCA_INPUT_DATA.SPEEDO_SPEED                    = (speedometer_speed_t)(C_KMH_MS * pVehSig->VehSigMain.VehVelocityExt * Speedo_speed_s);
#if 1
#pragma COMPILEMSG("No FCT_INPUT_DATA version found with INPUT_STATUS field - verify that removal OK!")
#else
      HP_STATIC_MEM_UNION.HP_STATIC_MEMORY.FCA_INPUT_DATA.INPUT_STATUS.INHIBIT= CheckState;
#endif
      FCA_v_Process
      (  cycle_time
       , &HP_STATIC_MEM_UNION.HP_STATIC_MEMORY.FCA_INPUT_DATA
       , &fca_output_data
       , &HP_STATIC_MEM_UNION.HP_STATIC_MEMORY.ACC_ALERT_OBJECT
      );
      HP_STATIC_MEM_UNION.HP_STATIC_MEMORY.FCA_OUTPUT_DATA = fca_output_data;
#endif /*FCT_CFG_FCA*/

#if (FCT_CFG_DM)
      dm_output_data = HP_STATIC_MEM_UNION.HP_STATIC_MEMORY.DM_OUTPUT_DATA;
      /*wrapper fo DM_INPUT_DATA*/
      HP_STATIC_MEM_UNION.HP_STATIC_MEMORY.DM_INPUT_DATA.CONTROL.DM_ON      = TRUE; /*!!! where to find?*/
      HP_STATIC_MEM_UNION.HP_STATIC_MEMORY.DM_INPUT_DATA.CONTROL.INHIBIT    = FALSE; /*!!! where to find?*/
#if (CFG_FCT_USE_VDY_HOST_ACCEL)
      HP_STATIC_MEM_UNION.HP_STATIC_MEMORY.DM_INPUT_DATA.LONG_ACCELERATION  = (acceleration_t)(pVehDyn->Longitudinal.MotVar.Accel * Acceleration_s);
#else
      HP_STATIC_MEM_UNION.HP_STATIC_MEMORY.DM_INPUT_DATA.LONG_ACCELERATION  = pFctVehLongOut->CurLongCtrlAccel; /* Replacement for longi_initialization_accel from Veh2SenInfo */
#endif
      HP_STATIC_MEM_UNION.HP_STATIC_MEMORY.DM_INPUT_DATA.LONG_VELOCITY      = (velocity_t)(pVehDyn->Longitudinal.VeloCorr.corrVelo * Velocity_s);
      HP_STATIC_MEM_UNION.HP_STATIC_MEMORY.DM_INPUT_DATA.SPEEDO_SPEED       = (speedometer_speed_t)(C_KMH_MS *pVehDyn->Longitudinal.MotVar.Velocity * Speedo_speed_s);
#if (defined(_MSC_VER))
#pragma COMPILEMSG("The below line was commented out, since I haven't found a DM_INPUT_DATA type with an INPUT_STATUS field")
#endif
      /*HP_STATIC_MEM_UNION.HP_STATIC_MEMORY.DM_INPUT_DATA.INPUT_STATUS.INHIBIT= CheckState;*/
      DM_v_Process
      (  cycle_time
       , &HP_STATIC_MEM_UNION.HP_STATIC_MEMORY.DM_INPUT_DATA
       , &dm_output_data
       , pAccDisplayObj
       , &HP_STATIC_MEM_UNION.HP_STATIC_MEMORY.DM_STATUS
      );
      HP_STATIC_MEM_UNION.HP_STATIC_MEMORY.DM_OUTPUT_DATA = dm_output_data;
#endif /*FCT_CFG_DM*/

#if ( FCT_CFG_DEBUG_FUZZY_CONTROLLER )      
      HP_STATIC_MEM_UNION.HP_STATIC_MEMORY.FUZZY_DATA_CTL_OBJ = FuzzyDebugDataControlObject;
#endif

      break;
    } /* case HP_OK */

    default:
    {
      /*! Initialization */
      HP_v_SetOperationMode(HP_INIT);
      LOHP_v_Init(pAccDisplayObj, pAccOutput, pLOHPUsageState);
      break;
    }
  } /* switch(HP_t_State) */

  /* Set the output port version numbers */
  pAccOutput->uiVersionNumber = FCT_ACC_OUTPUT_DATA_INTFVER;
  pAccDisplayObj->uiVersionNumber = ACC_DISPLAY_OBJECT_INTFVER;

  /* Freeze HP Data */
  ( void )MeasFreeze_Lohp_GlobVar
  (  FCT_MEAS_ID_LOHP_HP_STATIC_MEM
   , ( void* )&HP_STATIC_MEM_UNION.MTS_DUMMY
   , sizeof( hp_static_mem_u_t )
  );

#if (LOHP_CFG_PRED)
  (void)MeasFreeze_Lohp_GlobVar(FCT_MEAS_ID_LOHP_PRED_OUTPUT_DATA,   (void*)&PRED_STATIC_MEM_UNION.MTS_DUMMY,     sizeof(PRED_STATIC_MEM_UNION));
#endif
#if (FCT_CFG_CUSTOM_IO_INTERFACE && FCT_CFG_CUSTOM_IO_ABS_KINEMATIC)
  _PARAM_UNUSED(pCustomOutputInput);
#endif
#if (FCT_USE_EM_GENERIC_OBJECT_LIST)
  _PARAM_UNUSED(pEmGenObjList);
#if (FCT_USE_EM_ARS_TECH_OBJECT_LIST)
  _PARAM_UNUSED(pEmARSObjList);
#endif
#else
  _PARAM_UNUSED(pEmObjList);
#endif
  _PARAM_UNUSED(pFctObjList);

}


/*----- global functions-----*/
/*************************************************************************************************************************
  Functionname:    HP_v_SetOperationMode                                                                            */ /*!

  @brief           Set operation mode of HP sub-component

  @description     Set operation mode of HP sub-component based on given value
			
					@startuml
					Start
						Partition HP_v_SetOperationMode {
						 Note Left:State:\nHP_OK\nHP_INIT
						-Set operation mode of HP sub-component	
					}
					End	
					@enduml

  @return          -

  @param[in]       t_HPOpModeValue : HP operation mode value [full range of datatype HPState_t as in lohp_ext.h]

  @glob_in         -
  @glob_out        HP_t_State : HP operation mode variable [full range of datatype HPState_t as in lohp_ext.h]

  @c_switch_full   FCT_CFG_ACC_HEADWAY_PLANNER : Configuration switch for enabling ACC processing
  @c_switch_full   FCT_CFG_LOHP_COMPONENT : Configuration switch for LOHP component

  @pre             -
  @post            -

  @created         11.07.2017
  @changed         11.07.2017

  @traceability	   doors://rbgs854a:40000/?version=2&prodID=0&view=00000002&urn=urn:telelogic::1-503e822e5ec3651e-O-115-0008a201

  @author          Niraj Mistry | niraj.mistry@continental-corporation.com | +49 (8382) 9699-5631
*************************************************************************************************************************/
void HP_v_SetOperationMode(const HPState_t t_HPOpModeValue)
{
  HP_t_State = t_HPOpModeValue;
}

/** @} end defgroup */

#endif  /* (FCT_CFG_LOHP_COMPONENT) && FCT_CFG_ACC_HEADWAY_PLANNER) */

