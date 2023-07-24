/*! \file **********************************************************************

COMPANY:                   COPYRIGHT (C) Continental AG

PROJECT:                   Adaptive Cruise Control (ACC)

CPU:                       CPU-Independent

COMPONENT:                 LOPC_TCI (Traffic Continuation Indication)

PACKAGENAME:               tci_main.c

DESCRIPTION:               Main functions for TCI (Traffic Continuation Indication)

AUTHOR:                    Mistry Niraj (uidq5738)

CREATION DATE:             22.06.2017

VERSION:                   $Revision: 1.38 $

LEGACY VERSION:            Revision: 1.1
**************************************************************************** */

/*****************************************************************************
  MODULE DESCRIPTION
*****************************************************************************/

/** 
@defgroup   tci_main Tci_main
@ingroup    tci
@brief      TCI main function file
@{ */ 


/*****************************************************************************
  INCLUDES
*****************************************************************************/
#include "tci.h"

#if ((FCT_CFG_TCI==SWITCH_ON) && (FCT_CFG_ACT_CODE_VERSION == SWITCH_OFF))

/*****************************************************************************
  GLOBAL CONSTANTS (MODULE SCOPE)
*****************************************************************************/


/*****************************************************************************
  GLOBAL VARIABLES (MODULE SCOPE)
*****************************************************************************/


/*****************************************************************************
  LOCAL SYMOBLIC CONSTANTS
*****************************************************************************/


/*****************************************************************************
  LOCAL MACROS
*****************************************************************************/


/*****************************************************************************
  LOCAL CONSTANTS
*****************************************************************************/


/*****************************************************************************
  LOCAL TYPEDEFS
*****************************************************************************/


/*****************************************************************************
  LOCAL VARIABLES
*****************************************************************************/

#if (TCI_CFG_AUTOCODE == SWITCH_OFF) 

SET_MEMSEC_VAR(TCI_GlobalData)
/*PRQA S 3218 1*/ /* date: 2018-08-06, reviewer: Bibin Mathew, reason: kept here for better maintainability */
static TCI_GlobalData_t TCI_GlobalData;

#if (TCIACCCOORDINATION == SWITCH_ON)
SET_MEMSEC_VAR(TCIACC_GlobalData)
/*PRQA S 3218 1*/ /* date: 2018-11-19, reviewer: Bibin Mathew, reason: kept here for better maintainability */
static TCI_GlobalData_t TCIACC_GlobalData;
#endif




/*! SIT Simulation meas info */
#ifdef FCT_SIMU
SET_MEMSEC_VAR(TCI_SimMeasInfo)
static TCI_SimMeasInfo_t TCI_SimMeasInfo;
#endif

#endif
/*****************************************************************************
  FUNCTION PROTOTYPES
*****************************************************************************/

#if (TCI_CFG_AUTOCODE == SWITCH_OFF) 
/*************************************************************************************************************************
  Functionname:    TCI_v_SetInput                                                                                   */ /*!

  @brief           Function for setting the inputs related to TCI functionality

  @description     Function for setting inputs related to TCI inhibition,sensor valid,ACC coordination,TCI activation,drive off distance,
                    cyceltime,Ego Motion state,parameters related to OOI's
  @startuml 
  Start
	  Partition TCI_Setinput {
		  -Declare Variables for Custom & Technology specific structures
		  -TCI Input Inhibit signals and sensor related signals are updated with respective values
			  Partition CheckforInhibitionReason {
				  If(Reason for Inhibition is Selftest) then (true)
					  -make Initialization signal as TRUE
				  Else(false)
					  -make Initialization signal as FALSE
				  endif
			  }
             -Load TCIActivated & DriveoffDistance signals from RTE
			  Partition CheckforDriveoffDistance {
				  If(TCI_NoticeMode is 1) then (true)
					  -make Driveoff distance as 2m
				  Elseif(TCI_NoticeMode is 2) then (true)
					  -make Driveoff distance as 4m
          Elseif(TCI_NoticeMode is 3) then (true)
					  -make Driveoff distance as 6m
				  Else(false)
					  -make Driveoff distance as 2m
				  Endif
			  }
        note left :  Toyota specific implemenation for simulation of toyota recording
		  -Load EgoMotionState & ObjLossReason signals from RTE
			  Partition CheckforValidityofObject {
				  If(ObjectID is positive) then (true)
					  -Load all the TCI Input signals for OOI0 from RTE
				  Else(false)
					  -Load TCI Input signlas for OOI0 with default values      
				  Endif
			  }
		  -Set TCI Inputs for OOI1,OOI2,OOI3,OOI4,OOI5 from RTE
	  } 
  End 
  @enduml

  @return          static void

  @param[in]       pLongCtrlResp : Long control input as defined in RTE of type LongCtrlInput_t
  @param[in]       pVehDyn : Ego vehicle dynamic as defined in RTE of type VehDyn_t
  @param[in]       pAccOutput : ACC output data as port between SEN and VEH defined in RTE of type acc_output_data_t
  @param[in]       pFCTAccOOIData : ACC port between SEN and VEH defined in RTE of type FCTSenAccOOI_t
  @param[in]       pLongCtrlCmd : Long control output defined in RTE of type LongCtrlOutput_t
  @param[in]       pTCIInputExt : TCI inputs defined in RTE of type TCIInput_t
  @param[out]      pt_TCIInput : Inputs internally used in TCI Module [as defined in tci.h]


  @glob_in         -
  @glob_out        -

  @c_switch_part   FCT_CFG_ACC_HEADWAY_PLANNER : Configuration Switch needed for Enable/Disable (Headway Planner) sub-component
  @c_switch_part   FCT_CFG_SEN2VEH_ACC_OOI_PORT : FCT config for sensor to vehicle ACC Object of interest Port as defined in Rte_Algo_Type.h
  @c_switch_full   TCI_CFG_AUTOCODE : Configuration switch to Enable/Disable TCI Autocode

  @pre             -
  @post            -

  @created         3/21/2018
  @changed         3/21/2018

 @author           Marie-Theres Boll | Marie-Theres.Boll@continental-corporation.com | +49-8382-9699-632
                   Bibin Mathew | bibin.mathew@continental-corporation.com | +91 (80) 6679-6524
*************************************************************************************************************************/
static void TCI_v_SetInput(const LongCtrlInput_t * pLongCtrlResp,
                             const VehDyn_t * pVehDyn,
#if (FCT_CFG_ACC_HEADWAY_PLANNER)
                             const acc_output_data_t * pAccOutput,
#if (FCT_CFG_SEN2VEH_ACC_OOI_PORT)
                             const FCTSenAccOOI_t * pFCTAccOOIData,
#endif
#endif
                             const LongCtrlOutput_t * pLongCtrlCmd,
#if (FCT_VEH_CFG_VEH_SIG_INPUT)
                             const PowerTrain_t * pPowerTrain,
#endif
                             const TCIInput_t * pTCIInputExt,
                             TCIInputConst_t * const pt_TCIInput
                             );
#endif

#if (TCI_CFG_AUTOCODE == SWITCH_OFF) 
/*************************************************************************************************************************
  Functionname:    TCI_b_TCISetInputSensorValid                                                                     */ /*!

  @brief           Function for setting inputs related to validity of sensor

  @description     Function for setting inputs related to validity of sensor

  @startuml 
  Start
	  Partition TCI_SetInputsensorvalid{ 
			     :Setting Input related to sensor validity(AlnselftestBlockage) from status of ACCOutput Inhibition ;
	  }
	
  End 
  @enduml

  @return          static void

  @param[in]       pAccOutput : ACC output data as port between SEN and VEH defined in RTE of type acc_output_data_t
  @param[out]      pt_TCIInputSensorValid : SensorValidity related parameters [as defined in  tci.h]
 : 
  @glob_in         -
  @glob_out        -

  @c_switch_part   FCT_CFG_ACC_HEADWAY_PLANNER : Configuration Switch needed for Enable/Disable (Headway Planner) sub-component
  @c_switch_full   TCI_CFG_AUTOCODE : Configuration switch to Enable/Disable TCI Autocode

  @pre             -
  @post            -

  @created         3/21/2018
  @changed         3/21/2018


  @author          Marie-Theres Boll | Marie-Theres.Boll@continental-corporation.com | +49-8382-9699-632
                   Bibin Mathew | bibin.mathew@continental-corporation.com | +91 (80) 6679-6524
*************************************************************************************************************************/

static void TCI_b_TCISetInputSensorValid(
#if (FCT_CFG_ACC_HEADWAY_PLANNER)
                             const acc_output_data_t * pAccOutput,
#endif
                             TCIInputSensorValid_t * const pt_TCIInputSensorValid
                             );
#endif

#if (TCI_CFG_AUTOCODE == SWITCH_OFF) 
/*************************************************************************************************************************
  Functionname:    TCI_b_TCICheckInputSensorValid                                                                   */ /*!

  @brief           Function for checking inputs related to sensor validity

  @description     Function for checking inputs related to sensor validity

  @startuml 
  Start
	  Partition TCI_CheckingValidityOfSensor{
			  : Initialize InputsensorValid to FALSE;
		  Partition CheckInputSensorValid {
				  If((AlnselfBlockage is TRUE))
					  -set Inputsensorvalid as TRUE
				  endif
			  }
  
	  } 
  End 
  @enduml

  @return          static boolean

  @param[in]       pTCIInputSensorValid : Input for checking validty of sensor [as defined in tci.h]

  @glob_in         -
  @glob_out        -

  @c_switch_full   TCI_CFG_AUTOCODE : Configuration switch to Enable/Disable TCI Autocode
  @pre             -
  @post            -

  @created         3/21/2018
  @changed         3/21/2018

  @author          Marie-Theres Boll | Marie-Theres.Boll@continental-corporation.com | +49-8382-9699-632
                   Bibin Mathew | bibin.mathew@continental-corporation.com | +91 (80) 6679-6524
*************************************************************************************************************************/
static boolean TCI_b_TCICheckInputSensorValid(const TCIInputSensorValid_t * pTCIInputSensorValid);
#endif

#if (TCI_CFG_AUTOCODE == SWITCH_OFF) 
/*************************************************************************************************************************
  Functionname:    TCI_v_SetInputOOIObject                                                                          */ /*!

  @brief           Functional for setting inputs related to OOI's

  @description     Functional for setting inputs related to OOI's

  @startuml 
  Start
	  Partition TCI_SetInputOOIObject {
			  Partition SettingInputOOIObjects {
				  If((OOIID <= OBJ_NEXT_LAT_RIGHT_OOI) and (ObjectID >  
                        OBJ _INDEX_NO_OBJECT))then (true)
					  -Set TCI Inputs related to OOIs
				  Elseif(OOIID <= OBJ_NEXT_LAT_RIGHT_OOI) then (true)
					  -Set TCI Inputs related to OOIs to default values.
				  Else(false)

				  Endif
			  }
         
	  } 
  End 
  @enduml


  @return          static void

  @param[in]       OOIID : Input mentioning which OOI 
  @param[in]       pAccOOI :ACC port between SEN and VEH defined in RTE of type FCTSenAccOOI_t 
  @param[in,out]   pt_TCIInput :Inputs internally used in TCI Module [as defined in tci.h]

  @glob_in         -
  @glob_out        -

  @c_switch_part   -
  @c_switch_full   TCI_CFG_AUTOCODE : Configuration switch to Enable/Disable TCI Autocode

  @pre             -
  @post            -

  @created         3/20/2018
  @changed         3/20/2018

  @author          Marie-Theres Boll | Marie-Theres.Boll@continental-corporation.com | +49-8382-9699-632
                   Bibin Mathew | bibin.mathew@continental-corporation.com | +91 (80) 6679-6524
*************************************************************************************************************************/
static void TCI_v_SetInputOOIObject(const uint8 OOIID, const AccOOI_t * pAccOOI,TCIInputConst_t * const pt_TCIInput);
#endif

#if (TCI_CFG_AUTOCODE == SWITCH_OFF)
/*************************************************************************************************************************
  Functionname:    TCI_v_PreProcess                                                                                 */ /*!

  @brief           Preprocess / Set inputs to TCI module

  @description      Preprocess / Set inputs to TCI module

  @startuml 
  Start
	  Partition TCI_PreProcess { 
			     :Setting Inputs to TCI by calling SetInput function;
	  }
	
  End 
  @enduml

  @return          static void

  @param[in]       pLongCtrlResp : Long control input as defined in RTE of type LongCtrlInput_t
  @param[in]       pVehDyn : Ego vehicle dynamic as defined in RTE of type VehDyn_t
  @param[in]       pAccOutput : ACC output data as port between SEN and VEH defined in RTE of type acc_output_data_t
  @param[in]       pFCTAccOOIData : ACC port between SEN and VEH defined in RTE of type FCTSenAccOOI_t
  @param[in]       pLongCtrlCmd : Long control output defined in RTE of type LongCtrlOutput_t
  @param[in]       pTCIInputExt : TCI inputs defined in RTE of type TCIInput_t
  @param[in]       pTCIInput : Inputs internally used in TCI Module [as defined in tci.h]

  @c_switch_part   FCT_CFG_ACC_HEADWAY_PLANNER : Configuration Switch needed for Enable/Disable (Headway Planner) sub-component
  @c_switch_part   FCT_CFG_SEN2VEH_ACC_OOI_PORT : FCT config for sensor to vehicle ACC Object of interest Port as defined in Rte_Algo_Type.h
  @c_switch_full   TCI_CFG_AUTOCODE : Configuration switch to Enable/Disable TCI Autocode

  @pre             -
  @post            -

  @created         3/21/2018
  @changed         3/21/2018

  @author          Marie-Theres Boll | Marie-Theres.Boll@continental-corporation.com | +49-8382-9699-632
                   Bibin Mathew | bibin.mathew@continental-corporation.com | +91 (80) 6679-6524
*************************************************************************************************************************/
static void TCI_v_PreProcess(const LongCtrlInput_t * pLongCtrlResp,
                             const VehDyn_t * pVehDyn,
#if (FCT_CFG_ACC_HEADWAY_PLANNER)
                             const acc_output_data_t * pAccOutput,
#if (FCT_CFG_SEN2VEH_ACC_OOI_PORT)
                             const FCTSenAccOOI_t * pFCTAccOOIData,
#endif
#endif
                             const LongCtrlOutput_t * pLongCtrlCmd,
#if (FCT_VEH_CFG_VEH_SIG_INPUT)
                             const PowerTrain_t * pPowerTrain,
#endif
                             const TCIInput_t  * pTCIInputExt,
                             TCIInputConst_t * const pTCIInput
                             );
#endif

#if (TCI_CFG_AUTOCODE == SWITCH_OFF) 
/*************************************************************************************************************************
  Functionname:         TCI_v_MeasFreeze                                                                           */ /*!

  @brief                (TCI Meas Freeze)

  @description          (TCI Meas freeze explains about what and all data is getting freezed)

  @startuml
  Start
  Partition TCI_MeasFreeze {
	- Get data for measurement freeze in simulation
	- Freeze simulation data
	- Freeze device data
  }
  End
  @enduml

  @return               static void

  @param[in]            pTCIInput : Inputs internally used in TCI Module [as defined in tci.h]
  @param[in,out]        pt_TCI_GlobalData : Globaldata internally used in TCI Module [as defined in tci.h]

  @glob_in              -
  @glob_out             -

  @c_switch_part        -
  @c_switch_full        TCI_CFG_AUTOCODE : Configuration switch to Enable/Disable TCI Autocode

  @pre                  -
  @post                 -

  @author               Marie-Theres Boll | Marie-Theres.Boll@continental-corporation.com | +49-8382-9699-632
                        Anil Penigalapati | Anil.Penigalapati@continental-corporation.com | +91 (80) 6679-7468
*************************************************************************************************************************/
static void TCI_v_MeasFreeze(const TCIInputConst_t * p_TCIInput,const TCI_GlobalData_t *p_TCI_GlobalData
#if (TCIACCCOORDINATION == SWITCH_ON)
  ,const TCI_GlobalData_t *p_TCIACC_GlobalData
#endif  
 );
#endif
#if (TCI_CFG_AUTOCODE == SWITCH_OFF) 
/*************************************************************************************************************************
  Functionname:         TCI_v_StateMachine                                                                           */ /*!

  @brief                (TCI Statemachine.)

  @description          (TCI Statemachine explains about the workflow of TCI.Here it explains about the state and
                         conditions for each state.)

  @startuml 
  Start
				
	  Partition TCI_StateMachine {
                       : Setting ValidTarget signal to FALSE;
			  Partition CheckForStoppedTargetTimer {
				  If((standstill==egostate) and (Object dynamic property is stationary) then (true)
				      if(stoppedtargettimer < (MINIMUMSTOPPEDTARGETTIME+1)) then (true)
					  - incrementing  the stoppedtargettimer by adding fct vehicle cycle time to it
				      Endif
				  Else(False)
					  - Set stoppedtargettimer to zero;
				  Endif
				  If ( -1<ObjectID<40) then (true)
					  - Setting ValidTarget signal to TRUE;
				  Endif
			  } 
			  Partition CheckForTCIState {
				  If(TCI State is Inactive) then (true)
					  -Call TCI Inactive state
				  Elseif(TCI State is StoppedSubjectTarget)
					  -Call TCI StoppedSubjectTarget state
				  Elseif(TCI State is DriveoffTarget)
					  -Call TCI DriveoffTargete state
                       Elseif(TCI State is StoppedTarget)
					  -Call TCI StoppedTarget state
				  Elseif(TCI State is Indication)
					  - Call TCI Indication state
				  Else(False)
					  -Do nothing & come out;
				  Endif
                 }
         : Storing DistonTraj and ObjectID of current cycle;
	  }
  End 
  @enduml


  @return               static void

  @param[in]            pTCIInput : Inputs internally used in TCI Module [as defined in tci.h]
  @param[in,out]        pTCIOutput : Outputs of TCI Module [as defined in Rte_Type.h]
  @param[in,out]        pt_TCI_GlobalData : Globaldata internally used in TCI Module [as defined in tci.h]

  @glob_in              -
  @glob_out             -

  @c_switch_part        -
  @c_switch_full        TCI_CFG_AUTOCODE : Configuration switch to Enable/Disable TCI Autocode

  @pre                  -
  @post                 -

  @author               Marie-Theres Boll | Marie-Theres.Boll@continental-corporation.com | +49-8382-9699-632
                        Bibin Mathew | bibin.mathew@continental-corporation.com | +91 (80) 6679-6524
*************************************************************************************************************************/
static void TCI_v_StateMachine(const TCIInputConst_t *const pTCIInput,TCIOutput_t * const pTCIOutput,TCI_GlobalData_t * const pt_TCI_GlobalData  ,TCIMode_t_e e_Mode);
#endif
#if (TCI_CFG_AUTOCODE == SWITCH_OFF) 
/*************************************************************************************************************************
  Functionname:         TCI_v_StateInActive                                                                          */ /*!

  @brief                (Function for the TCI state INACTIVE.)

  @description          (Checking for condition TC0 is done here.if the conditions of TC0 is achieved TCI state will be changed to 
                        STOPPEDSUBJECTANDTARGET from INACTIVE state)
  @startuml 
  Start
				
	  Partition TCI_StateInActive {
          : Initializing the TCI input for Notification as none
				  : Initializing the stoppedtargettimer to zero;

			  Partition TCIVISUALNOTIFICATION==ENABLED {
				  If((0<indicationtimer<( MINIMUMVISUALTIME +1)) and (indicationtimer>0) ) then (true)
					  -incrementing  the indicationtimer by adding fct vehicle cycle time to it
				  Endif
			     	  If(indicationtimer > MINIMUMVISUALTIME) then (true)
					  If(standstill!=egostate) then (true)
					
						  If(interfaceversion>=4) then (true)
							  -load tci state to visual end
						  Else(false)
						  Endif
					  Endif
					  -set the indicationtimer to zero
				  Endif
			  }
			  Partition Checkforwhetherdriveoffisrequired {
				  If((object loss==disappeared) or (target is valid) and (objmovement is not plausible)) then (true)
					  - Set subjectdriveoff to true
				  Endif
				  if(standstill!=egostate) then (true)
				        - Set subjectdriveoff to false
				  Endif
			  }
			  Partition TC0 {
				  If((TCIActivated==True) and (Sensorvalid==True) and (Inhibition==False) and (standstill==egostate)\n
          and (Target is valid) and (stoppedtargettimer >=MINIMUMSTOPPEDTARGETTIME)\n 
          and (Distontraj<=MAXSTOPPEDTARGETTIME) and (Objectlossreason != Disppeared)\n 
          and (ObjMovement is plausible) and (subjectDriveoff==False)) then (true)
					  -Set state=STOPPEDSUBJECTANDTARGET, Initialdistance & Driveenddistance with respective values
				  Else(false)
					  -do nothing;
				  Endif
			  } 
	  }
  End 
  @enduml

  @return               static void

  @param[in]            pTCIInput : Inputs internally used in TCI Module [as defined in tci.h]
  @param[in,out]        pTCIOutput : Outputs of TCI Module [as defined in Rte_Type.h]
  @param[in,out]        pt_TCI_GlobalData : Globaldata internally used in TCI Module [as defined in tci.h]
  @param[in]            b_ValidTarget : Boolean giving info that Target is valid or not[TRUE/FALSE]

  @glob_in              -
  @glob_out             -

  @c_switch_part        TCI_VISUALNOTIFICATION : Configuration switch to Enable/Disable Visualization Notification of TCI
  @c_switch_full        TCI_CFG_AUTOCODE : Configuration switch to Enable/Disable TCI Autocode

  @pre                  -
  @post                 -

  @author               Marie-Theres Boll | Marie-Theres.Boll@continental-corporation.com | +49-8382-9699-632
                        Bibin Mathew | bibin.mathew@continental-corporation.com | +91 (80) 6679-6524
*************************************************************************************************************************/
static void TCI_v_StateInActive(const TCIInputConst_t *const pTCIInput,TCIOutput_t * const pTCIOutput,TCI_GlobalData_t * const pt_TCI_GlobalData,boolean b_ValidTarget,TCIMode_t_e e_Mode);
#endif

#if (TCI_CFG_AUTOCODE == SWITCH_OFF) 
/*************************************************************************************************************************
  Functionname:         TCI_v_StateStoppedSubjectAndTarget                                                           */ /*!

  @brief                (Function for the TCI state STOPPEDSUBJECTANDTARGET .)

  @description          (Checking for condition TC1 and TC2  is done here.
                        if the conditions of TC1 is achieved, TCI state will be INACTIVE or else
                        if the conditions of TC2 is achieved, TCI state will be DRIVEOFFTARGET
                        )

  @startuml 
  Start
				
	  Partition TCI_StateStoppedSubjectandTarget {
                       : Initializing checkoff condition and New object detection to FALSE
				  : Updating TCI Global data stoppedtargetstatetimer,Stoppedtargettimer,Driveoffdistance and accumulate Drivendistance 
				  : Setting Checkoff condition & New object detection ;
			  Partition TC1,TC2 {
				  If((standstill!=egostate) or (Inhibition==True) or (Checkoffcond==True)\n or (Newobjectdetection is TRUE) or (Target is not valid) \n
          or(Distontraj>MAXSTOPPEDTARGEDIST) or ((Objectlossreason == Disppeared)\n or (ObjMovement is not plausible)) then (true)
					  -Set TCI state to INACTIVE
				  Elseif(Object dynamic property is not stationary)
					  - Set TCI state to DRIVEOFFTARGET
				  Else(False)
					  -Do nothing
				  Endif
			  } 
	  }
  End 
  @enduml

  @return               static void

  @param[in]            pTCIInput : Inputs internally used in TCI Module [as defined in tci.h]
  @param[in,out]        pt_TCI_GlobalData : Globaldata internally used in TCI Module [as defined in tci.h]
  @param[in]            b_ValidTarget : Boolean giving info that Target is valid or not[TRUE/FALSE]

  @glob_in              -
  @glob_out             -

  @c_switch_part        -
  @c_switch_full        TCI_CFG_AUTOCODE : Configuration switch to Enable/Disable TCI Autocode

  @pre                  -
  @post                 -

  @author               Marie-Theres Boll | Marie-Theres.Boll@continental-corporation.com | +49-8382-9699-632
                        Bibin Mathew | bibin.mathew@continental-corporation.com | +91 (80) 6679-6524
*************************************************************************************************************************/
static void TCI_v_StateStoppedSubjectAndTarget(const TCIInputConst_t *const pTCIInput,TCI_GlobalData_t * const pt_TCI_GlobalData,boolean b_ValidTarget,TCIMode_t_e e_Mode);
#endif

#if (TCI_CFG_AUTOCODE == SWITCH_OFF) 
/*************************************************************************************************************************
  Functionname:         TCI_v_StateDriveOffTarget                                                                    */ /*!

  @brief                (Function for the TCI state DRIVEOFFTARGET .)

  @description           (Checking for condition TC4,TC5,TC3 and TC9  is done here.
                        if the conditions of TC4 is achieved, TCI state will be INACTIVE or else
                        if the conditions of TC5 is achieved, TCI state will be STOPPEDTARGET
                        if the conditions of TC3 is achieved, TCI state will be STOPPEDSUBJECTANDTARGET
                        if the conditions of TC9 is achieved, TCI state will be INDICATION
                        
                        )

  @startuml 
  scale max 2000 width
  Start
				
	  Partition TCI_StateDriveofftarget {
        : Initializing the Checkoffcondition, partofooi, indicationcondition, targetooiid, stoppedtargetstatetimer signals to false;
        : Updating Checkoffcondition and partofooi;
				     If (partofooi is true) then (true)
				   	     If (notification type is cutout) then (true)
					     -Target ooi data is set to cutout;
               	Else (false)
					     -Target ooi data to TCI obj next long;
					     Endif
					     Else (false)
					     -Target ooi data to TCI obj next long;
					     Endif			    
			  Partition TC3,TC4,TC5,TC9 {
				  If((partofooi is false) or (distontraj is greater than maxtargettcidistance) or \n(Incase of TARGETLEAVESSUBJLANE feature is disabled have to check then any of 6 ooi’s object id 
          is equal to their object id’s of last cycle) or (checkoffcondition is true)\n or (ego motion state is not standstill) or (inhibition is true)\n or (objmovement is not plausible)) then (true)
					  -Set TCIstate to INACTIVE;
				  Elseif ((object dyn property is stationary) and\n (driveenddistance is < driveoff distance) and\n (notification type is not cutout)
					  -Set TCI state to STOPPEDTARGET;
					  -Update target state timer with fct vehicle time;
          Note right
				   if feature INTERRUPTEDDRIVEOFFFEATURE
           is SWITCH ON then have to 
           check following above conditions
			    End note 
				  Elseif ((object dyn property is stationary) and\n (driveenddistance is < driveoff distance) and\n (notification type is not cutout)
					  -Set TCI state to STOPPEDSUBJECTANDTARGET;
					  -set driveend distance to zero;
					  -set initial distance to dist on traj;
           Note left
				   if feature INTERRUPTEDDRIVEOFFFEATURE
           is SWITCH OFF then have to 
           check following above conditions
			    End note 
				  Elseif(Indication Condition is true)
					  -set TCI state to INDICATION;
					  -set TCI buzreq signal to true;
					  -update indication timer by adding veh cycle time to it;
				  If(interface version is >0x04) then (true)
					  -Set TCI state to Acoustical visual start
				  Endif
				  Elseif(Object loss reason is disappeared)
					  -Set TCI state to INACTIVE;
				  Else
					  -Do nothing;
				  Endif
			  } 
	  }
  End 
  @enduml

  @return               static void

  @param[in]            pTCIInput : Inputs internally used in TCI Module [as defined in tci.h]
  @param[in,out]        pTCIOutput : Outputs of TCI Module [as defined in Rte_Type.h]
  @param[in,out]        pt_TCI_GlobalData : Globaldata internally used in TCI Module [as defined in tci.h]

  @glob_in              -
  @glob_out             -

  @c_switch_part        TCI_TARGETLEAVESSUBJLANE : Configuration switch to Enable/Disable Target Leaving SubjectLane subfeature
  @c_switch_part        TCI_INTERRUPTEDDRIVEOFFFEATURE : Configuration switch to Enable/Disable Interrupted driveoff subfeature
  @c_switch_full        TCI_CFG_AUTOCODE : Configuration switch to Enable/Disable TCI Autocode

  @pre                  -
  @post                 -

  @author               Marie-Theres Boll | Marie-Theres.Boll@continental-corporation.com | +49-8382-9699-632
                        Bibin Mathew | bibin.mathew@continental-corporation.com | +91 (80) 6679-6524
*************************************************************************************************************************/
static void TCI_v_StateDriveOffTarget(const TCIInputConst_t *const pTCIInput,TCIOutput_t * const pTCIOutput,TCI_GlobalData_t * const pt_TCI_GlobalData,TCIMode_t_e e_Mode);
#endif

#if (TCI_CFG_AUTOCODE == SWITCH_OFF) 
/*************************************************************************************************************************
  Functionname:         TCI_v_StateStoppedTarget                                                                     */ /*!

  @brief                (Function for the TCI state STOPPEDTARGET .)

  @description          (Checking for condition TC8,TC6 and TC7  is done here.
                        if the conditions of TC8 is achieved, TCI state will be INACTIVE 
                        if the conditions of TC6 is achieved, TCI state will be DRIVEOFFTARGET
                        if the conditions of TC7 is achieved, TCI state will be STOPPEDSUBJECTANDTARGET
                        )

  @startuml 
  Start
				
	  Partition TCI_StateStoppedTarget {
                       : Setting checkoff condition to FALSE;
				  : Setting New object detection to FALSE;
				  : incrementing  the indicationtimer considering fct vehicle;
				  : Checkoff condition & New object detection functions are called;
			  Partition TC8,TC7,TC6 {
				  If((standstill!=egostate) or (Inhibition==True) or\n (Checkoffcond==True) or (Newobjectdetection is TRUE) or\n (Objectlossreason == Disppeared) or (ObjMovement is plausible)) then (true)
					  -Set TCI state to Inactive;
				  Elseif((Object dynamic property is not stationary)\n and (stoppedtargettimer <=DRIVEDISTTTIME))
					  - Set TCI state to Driveoff target;
				  Elseif(stoppedtargettimer >DRIVEDISTTTIME))
					  - Set TCI global structure signals\n to respective values;
				  Else(False)
					  -Do nothing;
				  Endif
			  } 
	  }
  End 
  @enduml

  @return               static void

  @param[in]            pTCIInput : Inputs internally used in TCI Module [as defined in tci.h]
  @param[in,out]        pt_TCI_GlobalData : Globaldata internally used in TCI Module [as defined in tci.h]

  @glob_in              -
  @glob_out             -

  @c_switch_part        -
  @c_switch_full        TCI_CFG_AUTOCODE : Configuration switch to Enable/Disable TCI Autocode

  @pre                  -
  @post                 -

  @author               Marie-Theres Boll | Marie-Theres.Boll@continental-corporation.com | +49-8382-9699-632
                        Bibin Mathew | bibin.mathew@continental-corporation.com | +91 (80) 6679-6524
*************************************************************************************************************************/
static void TCI_v_StateStoppedTarget(const TCIInputConst_t *const pTCIInput,TCI_GlobalData_t * const pt_TCI_GlobalData);
#endif

#if (TCI_CFG_AUTOCODE == SWITCH_OFF) 
/*************************************************************************************************************************
  Functionname:         TCI_v_StateIndication                                                                        */ /*!

  @brief                (Function for the TCI state INDICATION.)

  @description          (Checking for condition TC10  is done here.
                        if the conditions of TC10 is achieved, TCI state will be INACTIVE 
                        )
  @startuml 
  Start
				
	  Partition TCI_StateIndication {
                       : Setting the Checkoffcondition, Newobjectdetection, cutoutnewobjectdetectin signals to false;
				  : Call the respective functions and update Checkoffcondition, Newobjectdetection, cutoutnewobjectdetectin signals;

				     If (Indicationtimer <= Indicationrepeattime) then (true)
					  - incrementing  the Indicationtimer considering fct vehicle cycle time;
				     Endif
			  Partition CheckforStatusofAcousticalNotification {
				  If(AcousticalNotification is turned on) then (true)
					   If(Indicationtimer > Indicationrepeattime) then (true)
                                -Set TCI Buzzer signal to true;
					                       If(Interface version > 0x04) then (true)
					                         -Set TCI state to Accoustial state;
				                          Endif
             Endif
				  Endif
                  }
			  Partition TC10 {
				  If((ACOUSTICALNOTIFICATION==OFF) or (CHECKOFFCONDITION==True) or (Inhibition==TRUE) or (standstill!=egostate) \n
          or (Notification==nonstopdriveoff) or (Indicationtimer >=INDICATIONREPEATTTIME) \n
          or (Notification==nonstopdriveoff) or (Notification==nonstopdriveofffixeddistance) or (ObjMovement is not plausible) \n
          and (newobjectdetection==True) or (Notificationtype is cutout) and (Objloss is disappeared) and (Cutout new object detection is true)) then (true)
					  -Set TCIstate to Inactive;
				  If (visual notification is turned on) then (true)
					  If(Indicationtimer > minvisualnotificationtime) then (true)
               If(EgoMotion!=STANDSTILL) then (true)
					         If(interface version >0x04) then (true)
						    -  set TCI state to visual end;
					         Endif
					     Else (false)
						    -Set indication timer to zero;
					     Endif
           Endif
					 Endif
				  Endif
			  } 
	  }
  End 
  @enduml

  @return               static void

  @param[in]            pTCIInput : Inputs internally used in TCI Module [as defined in tci.h]
  @param[in,out]        pTCIOutput : Outputs of TCI Module [as defined in Rte_Type.h]
  @param[in,out]        pt_TCI_GlobalData : Globaldata internally used in TCI Module [as defined in tci.h]

  @glob_in              -
  @glob_out             -

  @c_switch_part        TCI_VISUALNOTIFICATION : Configuration switch to Enable/Disable Visualization Notification of TCI
  @c_switch_part        TCI_ACCOUSTICALNTIFICATION : Configuration switch to Enable/Disable Acoustical Notification of TCI
  @c_switch_full        TCI_CFG_AUTOCODE : Configuration switch to Enable/Disable TCI Autocode

  @pre                  -
  @post                 -

  @author               Marie-Theres Boll | Marie-Theres.Boll@continental-corporation.com | +49-8382-9699-632
                        Bibin Mathew | bibin.mathew@continental-corporation.com | +91 (80) 6679-6524
*************************************************************************************************************************/

static void TCI_v_StateIndication(const TCIInputConst_t *const pTCIInput,TCIOutput_t * const pTCIOutput,TCI_GlobalData_t * const pt_TCI_GlobalData,TCIMode_t_e e_Mode);
#endif

#if (TCI_CFG_AUTOCODE == SWITCH_OFF) 
/*************************************************************************************************************************
  Functionname:         TCI_b_CheckOffConditions                                                                     */ /*!

  @brief                (To check off conditions.)

  @description          (Off condition will be set if TCI is not activated or sensor is not valid)

  @return               static boolean

  @startuml 
  Start
	  Partition TCI_CheckOffConditions{
			  : Initialize offcondition to FALSE;
		  Partition CheckforSensorvalidityandTCIactivation {
				  If((sensor is not valid) or (TCI is not activated)) then (true)
					  -set offcondition as TRUE
				  endif
			  }
  
	  } 
  End 
  @enduml

  @param[in]            pTCIInput : Inputs internally used in TCI Module [as defined in tci.h]

  @glob_in              -
  @glob_out             -

  @c_switch_part        -
  @c_switch_full        TCI_CFG_AUTOCODE : Configuration switch to Enable/Disable TCI Autocode

  @pre                  -
  @post                 -

  @author               Marie-Theres Boll | Marie-Theres.Boll@continental-corporation.com | +49-8382-9699-632
                        Bibin Mathew | bibin.mathew@continental-corporation.com | +91 (80) 6679-6524
*************************************************************************************************************************/
static boolean TCI_b_CheckOffConditions(const TCIInputConst_t *const pTCIInput);
#endif
#if (TCI_CFG_AUTOCODE == SWITCH_OFF) 
/*************************************************************************************************************************
  Functionname:         TCI_b_NewObjectDetection                                                                     */ /*!

  @brief                (To check new object is detecterd or not.)

  @description          (Here a new object is detected if object id of last cycle and current object ID of OOI0 differs.)

  @startuml 
  Start
	  Partition TCI_CheckNewObjectDetection{
			  : Initialize Newobjectdetection to FALSE;
		  Partition CheckforNewObject {
				  If((ObjectIDLastcycle!=CurrentOOI0ObjectID)) then (true)
					  -set Newobjectdetection as TRUE
				  endif
			  }
  
	  } 
  End 
  @enduml

  @return               static boolean

  @param[in]            pTCIInput : Inputs internally used in TCI Module [as defined in tci.h]
  @param[in,out]        pt_TCI_GlobalData : Globaldata internally used in TCI Module [as defined in tci.h]

  @glob_in              -
  @glob_out             -

  @c_switch_part        -
  @c_switch_full        TCI_CFG_AUTOCODE : Configuration switch to Enable/Disable TCI Autocode

  @pre                  -
  @post                 -

  @author               Marie-Theres Boll | Marie-Theres.Boll@continental-corporation.com | +49-8382-9699-632
                        Bibin Mathew | bibin.mathew@continental-corporation.com | +91 (80) 6679-6524
*************************************************************************************************************************/
static boolean TCI_b_NewObjectDetection(const TCIInputConst_t *const pTCIInput,const TCI_GlobalData_t *const pt_TCI_GlobalData);
#endif
#if (TCI_CFG_AUTOCODE == SWITCH_OFF) 
/*************************************************************************************************************************
  Functionname:         TCI_v_InitPersistentData                                                                     */ /*!

  @brief                (To reset all the global variables to default values.)

  @description          (To reset all the global variables to default values.)

  @startuml 
  Start
	  Partition TCI_InitPersistentData { 
			     :Setting Globalvariables to default values;
	  }
	
  End 
  @enduml

  @return               static void

  @param[in,out]        pt_TCI_GlobalData : Globaldata internally used in TCI Module [as defined in tci.h]

  @glob_in              -
  @glob_out             -

  @c_switch_part        -
  @c_switch_full        TCI_CFG_AUTOCODE : Configuration switch to Enable/Disable TCI Autocode

  @pre                  -
  @post                 -

  @author               Marie-Theres Boll | Marie-Theres.Boll@continental-corporation.com | +49-8382-9699-632
                        Bibin Mathew | bibin.mathew@continental-corporation.com | +91 (80) 6679-6524
*************************************************************************************************************************/
static void TCI_v_InitPersistentData(TCI_GlobalData_t * const pt_TCI_GlobalData);

#endif
#if (TCI_CFG_AUTOCODE == SWITCH_OFF) 
/*************************************************************************************************************************
  Functionname:         TCI_b_CheckForOOI                                                                            */ /*!

  @brief                (To check whether last cycle OOI0 is a part of current OOI List.)

  @description          (To check whether last cycle OOI0 is a part of current OOI List.)

  @startuml
	Start 
		Partition TCI_CheckForOOI {
			Repeat 
				If (LastcycleObjectID == OOIObjID) then (true)
					- Set PartofOOI as TRUE and exit the loop
				Else (false)
				Endif
			Repeat while (looping through OOIs till it reaches TCI_OBJ_HIDDENNEXTRIGHT)
		}
	End 
 @enduml


  @return               static boolean

  @param[in]            pTCIInput : Inputs internally used in TCI Module [as defined in tci.h]
  @param[in]            pt_TCI_GlobalData : Globaldata internally used in TCI Module [as defined in tci.h]

  @glob_in              -
  @glob_out             -

  @c_switch_part        -
  @c_switch_full        TCI_CFG_AUTOCODE : Configuration switch to Enable/Disable TCI Autocode

  @pre                  -
  @post                 -

  @author               Marie-Theres Boll | Marie-Theres.Boll@continental-corporation.com | +49-8382-9699-632
                        Bibin Mathew | bibin.mathew@continental-corporation.com | +91 (80) 6679-6524
*************************************************************************************************************************/
static boolean TCI_b_CheckForOOI(const TCIInputConst_t *const pTCIInput,const TCI_GlobalData_t * const pt_TCI_GlobalData);
#endif
#if (TCI_CFG_AUTOCODE == SWITCH_OFF) 
/*************************************************************************************************************************
  Functionname:         TCI_b_IndicationConditions                                                                   */ /*!

  @brief                (Function for determining the indication conditions.)

  @description          (Indication conditions for all the TCI features is determined here.)

  @startuml 
  Start
				
	  Partition TCI_IndicationConditions {
				  : Initializing IndicationCondition as FALSE;

			  Partition TCIVISUALNOTIFICATION==ENABLED {
				  If(LastcycleObjectID is any of object ID OOI2,OOI3,OOI4,OOI5) then (true)
					  -incrementing  the indicationtimer by adding fct vehicle cycle time to it
				  Endif
			     	  If(indicationtimer > MINIMUMVISUALTIME) then (true)
					  If(standstill!=egostate) then (true)
					
						  If(interfaceversion>=4) then (true)
							  -load tci state to visual end
						  Else(false)
						  Endif
					  Endif
					  -set the indicationtimer to zero
				  Endif
			  }
			  Partition Checkforwhetherdriveoffisrequired {
				  If((object loss==disappeared) or (target is valid) and (objmovement is not plausible)) then (true)
					  - Set subjectdriveoff to true
				  Endif
				  if(standstill!=egostate) then (true)
				        - Set subjectdriveoff to false
				  Endif
			  }
			  Partition TC0 {
				  If((TCIActivated==True) and (Sensorvalid==True) and (Inhibition==False) and (standstill==egostate) \n
          and (Target is valid) and (stoppedtargettimer >=MINIMUMSTOPPEDTARGETTIME) and (Distontraj<=MAXSTOPPEDTARGETTIME) \n
          and (Objectlossreason != Disppeared) and (ObjMovement is plausible) and (subjectDriveoff==False)) then (true)
					  -Set state=STOPPEDSUBJECTANDTARGET, Initialdistance & Driveenddistance with respective values
				  Else(false)
					  -do nothing;
				  Endif
			  } 
	  }
  End 
  @enduml


  @return               static boolean

  @param[in]            pTCIInput : Inputs internally used in TCI Module [as defined in tci.h]
  @param[in,out]        pt_TCI_GlobalData : Globaldata internally used in TCI Module [as defined in tci.h]

  @glob_in              -
  @glob_out             -

  @c_switch_part        TCI_TARGETLEAVESSUBJLANE : Configuration switch to Enable/Disable Target Leaves Subject Lane feature
  @c_switch_part        TCI_NONSTOPDRIVEOFFFEATURE : Configuration switch to Enable/Disable Nonstop driveoff feature
  @c_switch_part        TCI_INTERRUPTEDDRIVEOFFFEATURE : Configuration switch to Enable/Disable Interrupted drive off feature
  @c_switch_full        TCI_INTERRUPTEDDRIVEOFFFIXNOT : Configuration switch to Enable/Disable Interrupted drive off fix notification sub feature

  @pre                  -
  @post                 -

  @author               Marie-Theres Boll | Marie-Theres.Boll@continental-corporation.com | +49-8382-9699-632
                        Bibin Mathew | bibin.mathew@continental-corporation.com | +91 (80) 6679-6524
*************************************************************************************************************************/
static boolean TCI_b_IndicationConditions(const TCIInputConst_t *const pTCIInput,TCI_GlobalData_t * const pt_TCI_GlobalData);
#endif
#if (TCI_CFG_AUTOCODE == SWITCH_OFF) 
/*************************************************************************************************************************
  Functionname:    TCI_b_CutoutNewObjectDetection                                                                   */ /*!

  @brief           To check a new object is detected in the cutout scenario

  @description     To check a new object is detected in the cutout scenario.it's detected by comparing the last cycel iD to the current
 
  @startuml 
  Start
	  Partition TCI_CutoutNewObjectDetection{
			  : Initialize CutoutNewobjectdetection to FALSE;
		  Partition CheckforCutOutNewObject {
				  If((ObjectIDLastcycle!=CurrentCutoutObjectID) and
				      (CutOutID >OBJ_INDEX_NO_OBJECT)) then (true)
					  -set Newobjectdetection as TRUE
				  endif
			  }
  
	  } 
  End 
  @enduml

  @return          static boolean

  @param[in]       pTCIInput : Inputs internally used in TCI Module [as defined in tci.h]
  @param[in]       pt_TCI_GlobalData : Globaldata internally used in TCI Module [as defined in tci.h]

  @glob_in              -
  @glob_out             -

  @c_switch_part        -
  @c_switch_full        TCI_CFG_AUTOCODE : Configuration switch to Enable/Disable TCI Autocode

  @pre                  -
  @post                 -

  @created         6/8/2018
  @changed         6/8/2018

  @author               Marie-Theres Boll | Marie-Theres.Boll@continental-corporation.com | +49-8382-9699-632
                        Bibin Mathew | bibin.mathew@continental-corporation.com | +91 (80) 6679-6524

*************************************************************************************************************************/
static boolean TCI_b_CutoutNewObjectDetection(const TCIInputConst_t *const pTCIInput,const TCI_GlobalData_t * const pt_TCI_GlobalData);
#endif

void TCI_v_Process(const LongCtrlInput_t * pLongCtrlResp,
                             const VehDyn_t * pVehDyn,
#if (FCT_CFG_ACC_HEADWAY_PLANNER)
                             const acc_output_data_t * pAccOutput,
#if (FCT_CFG_SEN2VEH_ACC_OOI_PORT)
                             const FCTSenAccOOI_t * pFCTAccOOIData,
#endif
                             const acc_object_t * pAccDisplayObj,
#endif
                             const LongCtrlOutput_t * pLongCtrlCmd,
#if (FCT_VEH_CFG_VEH_SIG_INPUT)
                             const PowerTrain_t * pPowerTrain,
#endif
                             const TCIInput_t * pTCIInputExt,
                             TCIOutput_t * pTCIOutput)
{


#if (TCI_CFG_AUTOCODE == SWITCH_OFF) 
  TCIInputConst_t TCIInput;
  TCI_GlobalData_t * pt_TCI_GlobalData;
#if (TCIACCCOORDINATION == SWITCH_ON)
  TCI_GlobalData_t * pt_TCIACC_GlobalData;
  pt_TCIACC_GlobalData= &TCIACC_GlobalData;
#endif
  pt_TCI_GlobalData = &TCI_GlobalData;
#endif
  
  /*! Call custom specific input wrapper */
  TCI_v_InputWrapper(pLongCtrlResp,
                   pVehDyn,
#if (FCT_CFG_ACC_HEADWAY_PLANNER)
                   pAccOutput,
#if (FCT_CFG_SEN2VEH_ACC_OOI_PORT)
                   pFCTAccOOIData,
#endif
                   pAccDisplayObj,
#endif
                   pLongCtrlCmd,
                   pTCIInputExt,
                   pTCIOutput
                  );

#if (TCI_CFG_AUTOCODE == SWITCH_OFF) 

  /*set outputs to default values*/
#if(TCIOutput_INTFVER >= 0x04)
  pTCIOutput->TCI_State=TCI_State_Default;
#elif (TCIOutput_INTFVER == 0x03)
  pTCIOutput->TCI_State=TCI_State_NO_INIT;
#elif (TCIOutput_INTFVER == 0x02)
  pTCIOutput->TCI_State=TCI_State_NO_INIT;
#endif

  pTCIOutput->TCI_b_BuzReq=FALSE;
#if (TCIACCCOORDINATION == SWITCH_ON)
#if (TCIOutput_INTFVER >= 0x04)
              pTCIOutput->TCI_HMIDriveOffState=TCI_HMIDriveOffState_Default;
              pTCIOutput->TCI_b_HMIDriveOff=FALSE;
#endif
#endif

  if (LOPC_STATIC_MEMORY.LOPC_Frame.eLOPCState == LOPC_INIT)
  {    
    TCI_v_InitPersistentData(pt_TCI_GlobalData);
#if (TCIACCCOORDINATION == SWITCH_ON)	
    TCI_v_InitPersistentData(pt_TCIACC_GlobalData);
#endif
  }
  else if(LOPC_STATIC_MEMORY.LOPC_Frame.eLOPCState == LOPC_RUN)
  {
     TCI_v_PreProcess(pLongCtrlResp,
                       pVehDyn,
#if (FCT_CFG_ACC_HEADWAY_PLANNER)
                       pAccOutput,
#if (FCT_CFG_SEN2VEH_ACC_OOI_PORT)
                       pFCTAccOOIData,
#endif
#endif
                        pLongCtrlCmd,
#if (FCT_VEH_CFG_VEH_SIG_INPUT)
                        pPowerTrain,
#else
    #error FCT_CFG_LOPC_COMPONENT requires access to VehSigs PowerTrain sub-struct!
#endif
                       pTCIInputExt,
                       &TCIInput);

TCI_v_StateMachine(&TCIInput,pTCIOutput,pt_TCI_GlobalData,DRIVEOFFDISTANCECANINPUT);
#if ((TCIACCCOORDINATION == SWITCH_ON)&&(TCIOutput_INTFVER >= 0x04))
    if(DAS_STATUS_ACTIVE == TCIInput.DAS_status )
    {
        
        TCI_v_StateMachine(&TCIInput,pTCIOutput,pt_TCIACC_GlobalData,DRIVEOFFFIXED);
    }
#endif

#if (TCIOutput_INTFVER >= 0x02)
    if(TCIInput.b_Initialization==TRUE)
    {
      pTCIOutput->TCI_State=TCI_State_INIT;
    }
#endif

    /* Meas Freeze TCIInput*/
    TCI_v_MeasFreeze(&TCIInput,&TCI_GlobalData
#if (TCIACCCOORDINATION == SWITCH_ON)
      ,&TCIACC_GlobalData
#endif
      );

#if ((TCIACCCOORDINATION == SWITCH_ON)&&(TCIOutput_INTFVER < 0x04))
      _PARAM_UNUSED(pt_TCIACC_GlobalData);
#endif

  }
  else
  {

  }
#endif
#if (TCI_CFG_AUTOCODE == SWITCH_ON)
 	_PARAM_UNUSED(pPowerTrain);
#endif
}

#if (TCI_CFG_AUTOCODE == SWITCH_OFF) 

static void TCI_v_PreProcess(const LongCtrlInput_t * pLongCtrlResp,
                             const VehDyn_t * pVehDyn,
#if (FCT_CFG_ACC_HEADWAY_PLANNER)
                             const acc_output_data_t * pAccOutput,
#if (FCT_CFG_SEN2VEH_ACC_OOI_PORT)
                             const FCTSenAccOOI_t * pFCTAccOOIData,
#endif
#endif
                             const LongCtrlOutput_t * pLongCtrlCmd,
#if (FCT_VEH_CFG_VEH_SIG_INPUT)
                             const PowerTrain_t * pPowerTrain,
#endif
                             const TCIInput_t  * pTCIInputExt,
                             TCIInputConst_t * const pTCIInput
                             )
{
  /*All preprocess functions */
  /*Setting input for TCI*/
  TCI_v_SetInput(pLongCtrlResp,
                   pVehDyn,
#if (FCT_CFG_ACC_HEADWAY_PLANNER)
                   pAccOutput,
#if (FCT_CFG_SEN2VEH_ACC_OOI_PORT)
                   pFCTAccOOIData,
#endif

#endif
                   pLongCtrlCmd,
#if (FCT_VEH_CFG_VEH_SIG_INPUT)
                   pPowerTrain,
#endif
                   pTCIInputExt,
                   pTCIInput);
}
#endif


#if (TCI_CFG_AUTOCODE == SWITCH_OFF) 


static void TCI_b_TCISetInputSensorValid(
#if (FCT_CFG_ACC_HEADWAY_PLANNER)
                             const acc_output_data_t * pAccOutput,
#endif
                            TCIInputSensorValid_t * const pt_TCIInputSensorValid
                             )
{
  /*Setting TCI input for status of sensor */
  if(pAccOutput->ACC_OUTPUT_STATUS.INHIBITION_REASON!=0)
  {
    pt_TCIInputSensorValid->b_AlnSelftstBlockage=TRUE;
  }
  else
  {
    pt_TCIInputSensorValid->b_AlnSelftstBlockage=FALSE;
  }


}
#endif

#if (TCI_CFG_AUTOCODE == SWITCH_OFF) 
static boolean TCI_b_TCICheckInputSensorValid(const TCIInputSensorValid_t * pTCIInputSensorValid)
{
  boolean b_TCIInputSensorValid;
  
  b_TCIInputSensorValid=TRUE;
  /*Checking TCI input sensor valid is set or not*/
  if( TRUE == pTCIInputSensorValid->b_AlnSelftstBlockage )
  {
    b_TCIInputSensorValid=FALSE;
  }

  return b_TCIInputSensorValid;
}
#endif

#if (TCI_CFG_AUTOCODE == SWITCH_OFF) 
static void TCI_v_SetInput(const LongCtrlInput_t * pLongCtrlResp,
                             const VehDyn_t * pVehDyn,
#if (FCT_CFG_ACC_HEADWAY_PLANNER)
                             const acc_output_data_t * pAccOutput,
#if (FCT_CFG_SEN2VEH_ACC_OOI_PORT)
                             const FCTSenAccOOI_t * pFCTAccOOIData,
#endif
#endif
                             const LongCtrlOutput_t * pLongCtrlCmd,
#if (FCT_VEH_CFG_VEH_SIG_INPUT)
                             const PowerTrain_t * pPowerTrain,
#endif
                             const TCIInput_t * pTCIInputExt,
                             TCIInputConst_t * const pt_TCIInput
                             )
{
  TCIInputInhibit_t TCIInputInhibit;
  TCIInputSensorValid_t TCIInputSensorValid;
  /*Setting TCI Inputs for inhibition conditions*/
  TCI_b_TCISetInputInhibit(pLongCtrlResp,pVehDyn,
    pLongCtrlCmd,&TCIInputInhibit);
  /*Checking Inhibition condition is set or not*/
  pt_TCIInput->b_Inhibit=TCI_b_TCICheckInhibitStatus(&TCIInputInhibit);

  /*Setting TCI Inputs for Sensor valid conditions*/
  TCI_b_TCISetInputSensorValid(
#if (FCT_CFG_ACC_HEADWAY_PLANNER)
    pAccOutput,
#endif
    &TCIInputSensorValid
  );

  /*Checking sensor is valid*/
  pt_TCIInput->b_SensorValid=TCI_b_TCICheckInputSensorValid(&TCIInputSensorValid);
#if (FCT_CFG_ACC_HEADWAY_PLANNER)
  /*Checking the inhibition reason */
#if (FCT_ACC_OUTPUT_DATA_INTFVER <= 3)
    /*Checking the inhibition reason is set */
  if(pAccOutput->ACC_OUTPUT_STATUS.INHIBITION_REASON != Acc_inhibition_none) // to be removed in later version
#else
  /*Checking the inhibition reason is  selftest*/
  if((pAccOutput->ACC_OUTPUT_STATUS.INHIBITION_REASON & Acc_inhibition_selftest)!=0)
#endif
  {
    pt_TCIInput->b_Initialization = TRUE;
  }
  else
  {
    pt_TCIInput->b_Initialization = FALSE;
  }
#endif
  pt_TCIInput->b_TCIActivated = pTCIInputExt->TCI_b_On;
  /*Setting Drive off distance*/
  pt_TCIInput->f_DriveOffDistance = pTCIInputExt->f_DriveOffDistance;
#if (TCIACCCOORDINATION == SWITCH_ON)
#if (TCIOutput_INTFVER >= 0x04)
  pt_TCIInput->f_DriveOffDistanceFixed = TCI_FIXEDRIVEOFFDISTANCE;
#endif
#endif
  /*Setting Ego Motion state*/
  pt_TCIInput->e_EgoMotionState=pVehDyn->MotionState.MotState;
#if (TCIACCCOORDINATION == SWITCH_ON)
  pt_TCIInput->b_stand_still_detected=pLongCtrlResp->KinCtrlDynInput.stand_still_detected;
  if(fABS((float32)pLongCtrlCmd->KinOutput.MinRequestedLongAcceleration) > CML_f_Delta)
  {
    pt_TCIInput->f_MinRequestedLongAcceleration=((float32)pLongCtrlCmd->KinOutput.MinRequestedLongAcceleration/(float32)Acceleration_s);
  }
  else
  {
    pt_TCIInput->f_MinRequestedLongAcceleration=(float32)(pLongCtrlCmd->KinOutput.MinRequestedLongAcceleration);
  }
#endif
  /*Setting Object Loss reason*/
  pt_TCIInput->e_ObjLossReasonOOI0=pFCTAccOOIData->AccOOINextLong.eRelObjLossReason;
  pt_TCIInput->b_FrontObstacleDetected=pFCTAccOOIData->bFrontObstacleDetected;
  /*If object ID is valid*/
  if(pFCTAccOOIData->AccOOINextLong.Attributes.uiObjectID > OBJ_INDEX_NO_OBJECT )
  {
    /*Setting TCI Inputs related to OOI0*/
    pt_TCIInput->t_OOIObj[TCI_OBJ_NEXT_LONG].ObjID=pFCTAccOOIData->AccOOINextLong.Attributes.uiObjectID;
    pt_TCIInput->t_OOIObj[TCI_OBJ_NEXT_LONG].f_LongDisplacement=pFCTAccOOIData->AccOOINextLong.Kinematic.fDistX;
    pt_TCIInput->t_OOIObj[TCI_OBJ_NEXT_LONG].f_LatDisplacement=pFCTAccOOIData->AccOOINextLong.Kinematic.fDistY;
    pt_TCIInput->t_OOIObj[TCI_OBJ_NEXT_LONG].f_VrelLong=pFCTAccOOIData->AccOOINextLong.Kinematic.fVrelX;
    pt_TCIInput->t_OOIObj[TCI_OBJ_NEXT_LONG].f_VrelLat=pFCTAccOOIData->AccOOINextLong.Kinematic.fVrelY;
    pt_TCIInput->t_OOIObj[TCI_OBJ_NEXT_LONG].e_ObjDynProb=pFCTAccOOIData->AccOOINextLong.Attributes.eDynamicProperty;
    pt_TCIInput->t_OOIObj[TCI_OBJ_NEXT_LONG].b_PlausibleObjMovement= pFCTAccOOIData->AccOOINextLong.Attributes.b_PlausibleObjMovement;
    pt_TCIInput->t_OOIObj[TCI_OBJ_NEXT_LONG].f_DistOnTraj=pFCTAccOOIData->AccOOINextLong.Kinematic.fDistX;
    pt_TCIInput->f_VabsXOOI0=pFCTAccOOIData->AccOOINextLong.Kinematic.fVabsX;
    //->future: pAccOOI->Kinematic.f_DistOnTraj;@TODO
  }
  else
  {
    /*Setting default values*/
    pt_TCIInput->t_OOIObj[TCI_OBJ_NEXT_LONG].ObjID=OBJ_INDEX_NO_OBJECT;
    pt_TCIInput->t_OOIObj[TCI_OBJ_NEXT_LONG].f_LongDisplacement=TCI_INITDISTANCE;
    pt_TCIInput->t_OOIObj[TCI_OBJ_NEXT_LONG].f_LatDisplacement=TCI_INITDISTANCE;
    pt_TCIInput->t_OOIObj[TCI_OBJ_NEXT_LONG].f_VrelLong=TCI_INITVELOCITY;
    pt_TCIInput->t_OOIObj[TCI_OBJ_NEXT_LONG].f_VrelLat=TCI_INITVELOCITY;
    pt_TCIInput->t_OOIObj[TCI_OBJ_NEXT_LONG].e_ObjDynProb=EM_GEN_OBJECT_DYN_PROPERTY_UNKNOWN;
    pt_TCIInput->t_OOIObj[TCI_OBJ_NEXT_LONG].b_PlausibleObjMovement= FALSE;
    pt_TCIInput->t_OOIObj[TCI_OBJ_NEXT_LONG].f_DistOnTraj= TCI_INITDISTANCE;
    pt_TCIInput->f_VabsXOOI0=TCI_INITVELOCITY;
  }
  /*Setting TCI Inputs related to OOI1,OOi2,OOI3,OOI4,OOI5*/
  TCI_v_SetInputOOIObject(TCI_OBJ_HIDDENNEXT_LONG,&(pFCTAccOOIData->AccOOIHiddenNextLong),pt_TCIInput);
  TCI_v_SetInputOOIObject(TCI_OBJ_NEXTLEFT,&(pFCTAccOOIData->AccOOINextLeft),pt_TCIInput);
  TCI_v_SetInputOOIObject(TCI_OBJ_NEXTRIGHT,&(pFCTAccOOIData->AccOOINextRight),pt_TCIInput);
  TCI_v_SetInputOOIObject(TCI_OBJ_HIDDENNEXTLEFT,&(pFCTAccOOIData->AccOOIHiddenNextLeft),pt_TCIInput);
  TCI_v_SetInputOOIObject(TCI_OBJ_HIDDENNEXTRIGHT,&(pFCTAccOOIData->AccOOIHiddenNextRight),pt_TCIInput);

#if (TCIACCCOORDINATION == SWITCH_ON) 
  pt_TCIInput->DAS_status=pLongCtrlCmd->KinOutput.DAS_status;
#else
  _PARAM_UNUSED(pLongCtrlCmd);
#endif
  _PARAM_UNUSED(pPowerTrain);
}
#endif


#if (TCI_CFG_AUTOCODE == SWITCH_OFF) 
static void TCI_v_SetInputOOIObject(const uint8 OOIID, const AccOOI_t * pAccOOI,TCIInputConst_t * const pt_TCIInput)
{
  /*Setting TCI inputs related to OOI's */
  if((OOIID <= OBJ_NEXT_LAT_RIGHT_OOI) && (pAccOOI->Attributes.uiObjectID > OBJ_INDEX_NO_OBJECT) )/*OOIID is uint8 and it's always greaterthan or equal to zero*/
  {
    pt_TCIInput->t_OOIObj[OOIID].ObjID=pAccOOI->Attributes.uiObjectID;
    pt_TCIInput->t_OOIObj[OOIID].f_LongDisplacement=pAccOOI->Kinematic.fDistX;
    pt_TCIInput->t_OOIObj[OOIID].f_LatDisplacement=pAccOOI->Kinematic.fDistY;
    pt_TCIInput->t_OOIObj[OOIID].f_VrelLong=pAccOOI->Kinematic.fVrelX;
    pt_TCIInput->t_OOIObj[OOIID].f_VrelLat=pAccOOI->Kinematic.fVrelY;
    pt_TCIInput->t_OOIObj[OOIID].e_ObjDynProb=pAccOOI->Attributes.eDynamicProperty;
    pt_TCIInput->t_OOIObj[OOIID].b_PlausibleObjMovement=pAccOOI->Attributes.b_PlausibleObjMovement;
    pt_TCIInput->t_OOIObj[OOIID].f_DistOnTraj=  pAccOOI->Kinematic.fDistX;
  }
  else
  {
    /*Setting default values*/
    if(OOIID <= OBJ_NEXT_LAT_RIGHT_OOI)/*OOIID is uint8 and it's always greaterthan or equal to zero*/
    {
      pt_TCIInput->t_OOIObj[OOIID].ObjID=OBJ_INDEX_NO_OBJECT;
      pt_TCIInput->t_OOIObj[OOIID].f_LongDisplacement=TCI_INITDISTANCE;
      pt_TCIInput->t_OOIObj[OOIID].f_LatDisplacement=TCI_INITDISTANCE;
      pt_TCIInput->t_OOIObj[OOIID].f_VrelLong=TCI_INITVELOCITY;
      pt_TCIInput->t_OOIObj[OOIID].f_VrelLat=TCI_INITVELOCITY;
      pt_TCIInput->t_OOIObj[OOIID].e_ObjDynProb=EM_GEN_OBJECT_DYN_PROPERTY_UNKNOWN;
      pt_TCIInput->t_OOIObj[OOIID].b_PlausibleObjMovement= FALSE; 
      pt_TCIInput->t_OOIObj[OOIID].f_DistOnTraj= TCI_INITDISTANCE;
    }
  }
}
#endif

#if (TCI_CFG_AUTOCODE == SWITCH_OFF) 
static void TCI_v_StateMachine(const TCIInputConst_t *const pTCIInput,TCIOutput_t * const pTCIOutput,TCI_GlobalData_t * const pt_TCI_GlobalData,TCIMode_t_e e_Mode)
{

  boolean b_ValidTarget=FALSE;
  /*Checking both subject and target are stationary*/
  if((( EM_GEN_OBJECT_DYN_PROPERTY_STATIONARY == pTCIInput->t_OOIObj[TCI_OBJ_NEXT_LONG].e_ObjDynProb)||( EM_GEN_OBJECT_DYN_PROPERTY_STOPPED == pTCIInput->t_OOIObj[TCI_OBJ_NEXT_LONG].e_ObjDynProb))&&
     (VDY_LONG_MOT_STATE_STDST == pTCIInput->e_EgoMotionState)
    )
  { 
    /*Checking stopped target timer is less than threshold  */
    if( pt_TCI_GlobalData->f_Stoppedtargettimer < (TCI_MINSTOPPEDTARGETTIME+1.0f))
    {
      /*Accumulating stopped target timer by adding fct vehicle cycle time to previous value*/
      pt_TCI_GlobalData->f_Stoppedtargettimer += FCT_VEH_CYCLE_TIME;
    }
  }
  else 
  {
    /*setting stopped target timer to zero*/
    pt_TCI_GlobalData->f_Stoppedtargettimer=0.0f;
  }
#if (TCIACCCOORDINATION == SWITCH_ON)
  if(TRUE == pTCIInput->b_stand_still_detected)
  { 
        /*Checking stopped Ego timer is less than threshold  */
    if( pt_TCI_GlobalData->f_StoppedEgoTimer < (TCI_MINSTOPPEDEGOTIME+1.0f))
    {
      /*Accumulating stopped Ego timer by adding fct vehicle cycle time to previous value*/
      pt_TCI_GlobalData->f_StoppedEgoTimer += FCT_VEH_CYCLE_TIME;
    }
  }
  else
  {
    pt_TCI_GlobalData->f_StoppedEgoTimer=0.0f;
  }
#endif
  /*checking Target is valid or not*/
  if( (pTCIInput->t_OOIObj[TCI_OBJ_NEXT_LONG].ObjID > OBJ_INDEX_NO_OBJECT) && (pTCIInput->t_OOIObj[TCI_OBJ_NEXT_LONG].ObjID < EM_N_OBJECTS ) )
  {
    /*Setting as TRUE if target is valid*/
    b_ValidTarget=TRUE;
  }
  /*Switch case for diffferent TCI states*/
  switch(pt_TCI_GlobalData->e_TCIState)
  {
    /*INACTIVE state*/
    case INACTIVE:
    {
 
      TCI_v_StateInActive(pTCIInput,pTCIOutput,pt_TCI_GlobalData,b_ValidTarget,e_Mode);
      break;
    }
    /*Stopped Subject and target state*/
    case STOPPEDSUBJECTANDTARGET:
    {

      TCI_v_StateStoppedSubjectAndTarget(pTCIInput,pt_TCI_GlobalData,b_ValidTarget,e_Mode);   
      break;
    }
    /*Drive Off Target state*/
    case DRIVEOFFTARGET:
    {
      TCI_v_StateDriveOffTarget(pTCIInput,pTCIOutput,pt_TCI_GlobalData,e_Mode);
      break;
    }
    /*Stopped Target state*/
    case STOPPEDTARGET:
    {
      TCI_v_StateStoppedTarget(pTCIInput,pt_TCI_GlobalData);
      break;
    }
    /*Indication state*/
    case INDICATION:
    {
      TCI_v_StateIndication(pTCIInput,pTCIOutput,pt_TCI_GlobalData,e_Mode);
      break;
    }
    default:
    {

      break;
    }
  }
  /*Storing current DistOntraj and Object ID for the next cycle */
  pt_TCI_GlobalData->f_DistOnTrajLastCycle=pTCIInput->t_OOIObj[TCI_OBJ_NEXT_LONG].f_DistOnTraj;

  if( (pt_TCI_GlobalData->s_OOICutout == OBJ_INDEX_NO_OBJECT) ||(pt_TCI_GlobalData->e_NotificationType!=CUTOUT) )
  {
     pt_TCI_GlobalData->ObjIDLastCycle = pTCIInput->t_OOIObj[TCI_OBJ_NEXT_LONG].ObjID;
  }
  else
  {
     pt_TCI_GlobalData->ObjIDLastCycle = pTCIInput->t_OOIObj[pt_TCI_GlobalData->s_OOICutout].ObjID;
  }
}
#endif
#if (TCI_CFG_AUTOCODE == SWITCH_OFF) 
/*PRQA S 3673 1*/ /* date: 2018-08-06, reviewer: Bibin Mathew, reason: pTCIOutput will get modified if TCIOutput_INTFVER >=4 */
static void TCI_v_StateInActive(const TCIInputConst_t *const pTCIInput,TCIOutput_t * const pTCIOutput,TCI_GlobalData_t * const pt_TCI_GlobalData,boolean b_ValidTarget,TCIMode_t_e e_Mode)
{

      pt_TCI_GlobalData->e_NotificationType=NOTIFICATIONTYPENONE;
      pt_TCI_GlobalData->f_Stoppedtargetstatetimer=0.0f;
      pt_TCI_GlobalData->s_OOICutout=OBJ_INDEX_NO_OBJECT;


/*Feature only if VISUALNOTIFICATION is SWITCH_ON*/  
#if (TCI_VISUALNOTIFICATION == SWITCH_ON||TCIACCCOORDINATION == SWITCH_ON)
      /*Checking indication timer (related to Buzzer and Visual and Accoustical)is less than threshold*/
      if((pt_TCI_GlobalData->f_Indicationtimer <= (TCI_MINVISUALNOTIFICATIONTIME+1.0f))&&(pt_TCI_GlobalData->f_Indicationtimer > 0.0f))
      {
        /*Accumalating indication timer by adding fct vehicle cycle time to previous value */
        pt_TCI_GlobalData->f_Indicationtimer+=FCT_VEH_CYCLE_TIME;
      }
      /*Checking indication timer is greater than minimum visual notification time*/
      if(pt_TCI_GlobalData->f_Indicationtimer > TCI_MINVISUALNOTIFICATIONTIME)
      {  
        /*checking EGO is not standstill*/
       
        if (
#if (TCIACCCOORDINATION == SWITCH_ON)
          ((DAS_STATUS_ACTIVE == pTCIInput->DAS_status) && (pTCIInput->f_MinRequestedLongAcceleration >= CML_f_Delta))
          ||
#endif
          (VDY_LONG_MOT_STATE_STDST != pTCIInput->e_EgoMotionState))/*Remark:Need to handle if subject vehicle starts off and stops again within TCI_MINVISUALNOTIFICATIONTIME sec*/
        {
          /*IF TCIOutput version is greater than or equal to four then setting TCI state as Visual End notification */
          if(e_Mode==DRIVEOFFDISTANCECANINPUT)
          {
#if(TCIOutput_INTFVER >= 0x04)
          pTCIOutput->TCI_State=TCI_State_Visual_End;
#else
           _PARAM_UNUSED(pTCIOutput);		  
#endif  
          }
          else
          {
#if (TCIACCCOORDINATION == SWITCH_ON)
#if(TCIOutput_INTFVER >= 0x04)
            pTCIOutput->TCI_HMIDriveOffState=TCI_HMIDriveOffState_Visual_End;
#endif  			
#endif
          }
          /*Initializing indication timer to zero*/
          pt_TCI_GlobalData->f_Indicationtimer=0.0f;
        }
      }
#endif


      /*Setting of subject drive off condition by checking target object loss condition and plausibleobjmovement*/
      /*Here checking of object is valid or not is considered*/
      if( (OBJ_LOSS_DISAPPEARED==pTCIInput->e_ObjLossReasonOOI0)||
          ((TRUE==b_ValidTarget)&&(FALSE==pTCIInput->t_OOIObj[TCI_OBJ_NEXT_LONG].b_PlausibleObjMovement))||(TRUE==pTCIInput->b_FrontObstacleDetected)
        )
      {
        pt_TCI_GlobalData->b_subjectdriveoffrequired =TRUE;
      }
      /*Checking if Ego is not standstill*/
      if(VDY_LONG_MOT_STATE_STDST != pTCIInput->e_EgoMotionState)
      {
         pt_TCI_GlobalData->b_subjectdriveoffrequired =FALSE;
      }

      /*TC0*/
      /*Checking TCO conditions*/
      if((TRUE == pTCIInput->b_TCIActivated)
          &&(TRUE == pTCIInput->b_SensorValid)&&(FALSE == pTCIInput->b_Inhibit)
            &&(VDY_LONG_MOT_STATE_STDST == pTCIInput->e_EgoMotionState)
            &&(TRUE==b_ValidTarget)
             &&(pt_TCI_GlobalData->f_Stoppedtargettimer >= TCI_MINSTOPPEDTARGETTIME)
              &&(pTCIInput->t_OOIObj[TCI_OBJ_NEXT_LONG].f_DistOnTraj <= TCI_MAXSTOPPEDTARGETDIST)
                &&((OBJ_LOSS_DISAPPEARED!=pTCIInput->e_ObjLossReasonOOI0)
                  &&(TRUE==pTCIInput->t_OOIObj[TCI_OBJ_NEXT_LONG].b_PlausibleObjMovement )
                  &&(FALSE == pTCIInput->b_FrontObstacleDetected))
                    &&(FALSE == pt_TCI_GlobalData->b_subjectdriveoffrequired)
                    
        )
      {
        /*Setting TCI state to STOPPPEDSUBJECTANDTARGET*/
        pt_TCI_GlobalData->e_TCIState = STOPPEDSUBJECTANDTARGET;
        pt_TCI_GlobalData->f_Initialdistance=pTCIInput->t_OOIObj[TCI_OBJ_NEXT_LONG].f_DistOnTraj;
        pt_TCI_GlobalData->f_Drivendistance=0.0f;
      }
      else
      {

      }
}
#endif

#if (TCI_CFG_AUTOCODE == SWITCH_OFF) 
static void TCI_v_StateStoppedSubjectAndTarget(const TCIInputConst_t *const pTCIInput,TCI_GlobalData_t * const pt_TCI_GlobalData,boolean b_ValidTarget,TCIMode_t_e e_Mode)
{
  boolean b_CheckOffCondition=FALSE;
  boolean b_NewObjectDetection=FALSE;
  /*Initializing stopped target state timer and stopped target timer to zero*/
  pt_TCI_GlobalData->f_Stoppedtargetstatetimer=0.0f;
  pt_TCI_GlobalData->f_Stoppedtargettimer=0.0f;
  /*Setting Drive off distance to TCI Global*/
  if(DRIVEOFFDISTANCECANINPUT == e_Mode)
  {
    pt_TCI_GlobalData->f_Driveoffdistance=pTCIInput->f_DriveOffDistance;
  }
#if (TCIACCCOORDINATION == SWITCH_ON)
#if (TCIOutput_INTFVER >= 0x04)
  else
  {
    pt_TCI_GlobalData->f_Driveoffdistance=pTCIInput->f_DriveOffDistanceFixed;
  }
#endif
#endif
  /*Accumulating driven distance by taking differences of OOI0's DistOnTraj of current and last cycle  */
  pt_TCI_GlobalData->f_Drivendistance+= (pTCIInput->t_OOIObj[TCI_OBJ_NEXT_LONG].f_DistOnTraj - pt_TCI_GlobalData->f_DistOnTrajLastCycle);

  /*Setting TCI off condition by checking senssor valid condition and TCI activation*/
  b_CheckOffCondition=TCI_b_CheckOffConditions(pTCIInput);
  /*Checking a new object is detected*/
  b_NewObjectDetection=TCI_b_NewObjectDetection(pTCIInput,pt_TCI_GlobalData);

  /*TC1*/
  /*Checking TC1 conditions for setting TCI state to INACTIVE*/
  if((VDY_LONG_MOT_STATE_STDST != pTCIInput->e_EgoMotionState)||(TRUE == pTCIInput->b_Inhibit)
  ||(TRUE==b_CheckOffCondition)||(FALSE==b_ValidTarget)
  ||((OBJ_LOSS_DISAPPEARED==pTCIInput->e_ObjLossReasonOOI0)
        ||(FALSE==pTCIInput->t_OOIObj[TCI_OBJ_NEXT_LONG].b_PlausibleObjMovement )
        ||(TRUE == pTCIInput->b_FrontObstacleDetected))
  || (TRUE == b_NewObjectDetection)
  )
  {
  pt_TCI_GlobalData->e_TCIState = INACTIVE;
  }
  /*TC2*/
  /*Checking TC2 conditions for setting TCI state to DRIVEOFFTARGET*/
  /*Here if the above conditions failed this condtion for OOI0 is not stationary is checking*/
  else if(((pTCIInput->t_OOIObj[TCI_OBJ_NEXT_LONG].e_ObjDynProb != EM_GEN_OBJECT_DYN_PROPERTY_STATIONARY)&&(pTCIInput->t_OOIObj[TCI_OBJ_NEXT_LONG].e_ObjDynProb != EM_GEN_OBJECT_DYN_PROPERTY_STOPPED))||(pTCIInput->f_VabsXOOI0 >=TCI_MINABSVELOCITYOOI0))
  {
    pt_TCI_GlobalData->e_TCIState = DRIVEOFFTARGET;
  }
  else
  {

  }
}
#endif
#if (TCI_CFG_AUTOCODE == SWITCH_OFF) 
static void TCI_v_StateDriveOffTarget(const TCIInputConst_t *const pTCIInput,TCIOutput_t * const pTCIOutput,TCI_GlobalData_t * const pt_TCI_GlobalData,TCIMode_t_e e_Mode)
{

  boolean b_CheckOffCondition=FALSE;
  boolean b_PartOfOOI=FALSE;
  boolean b_IndicationCondition=FALSE;
  boolean b_driveofftoindication=FALSE;
  ObjNumber_t t_TargetOOIID = OBJ_INDEX_NO_OBJECT;

      pt_TCI_GlobalData->f_Stoppedtargetstatetimer=0.0f;
      /*Setting TCI off condition by checking sensor valid condition and TCI activation*/
      b_CheckOffCondition=TCI_b_CheckOffConditions(pTCIInput);
      /*@TODO check later if we dont have a valid target condition*/
      /*Checking whether last cycle object ID is apart of current OOI List*/
      b_PartOfOOI=TCI_b_CheckForOOI(pTCIInput,pt_TCI_GlobalData);
      if (b_PartOfOOI== TRUE)
      {
        /*Checking indicationconditioon flag is set or not*/
        b_IndicationCondition=TCI_b_IndicationConditions(pTCIInput,pt_TCI_GlobalData);
        if((pt_TCI_GlobalData->e_NotificationType==CUTOUT))
        {
            t_TargetOOIID = pt_TCI_GlobalData->s_OOICutout;
        }
        else/*NOTIFICATIONTYPENONE or NONSTOPDRIVEOFF or INTERRUPTEDDRIVEOFF or INTERRUPTEDDRIVEOFFFIXEDDISTANCE*/
        {
           t_TargetOOIID=TCI_OBJ_NEXT_LONG;
        }
      }
      else
      {
        t_TargetOOIID=TCI_OBJ_NEXT_LONG; /* set OOI-0 id for peventing assessing an array with id -1, from functional point of view okay, 
                                         since (FALSE==b_PartOfOOI) is true in this case and INACTIVE state will be set anyway */
      }

      /*TC4*/
      /*Checking TC4 conditions for setting TCI state to INACTIVE*/
      if((FALSE==b_PartOfOOI) 
        ||(pTCIInput->t_OOIObj[t_TargetOOIID].f_DistOnTraj > TCI_MAXTARGETTCIDIST)
        ||(pTCIInput->t_OOIObj[TCI_OBJ_HIDDENNEXT_LONG].ObjID == pt_TCI_GlobalData->ObjIDLastCycle)
#if (TCI_TARGETLEAVESSUBJLANE == SWITCH_OFF)
        ||
        ((pTCIInput->t_OOIObj[TCI_OBJ_NEXTLEFT].ObjID == pt_TCI_GlobalData->ObjIDLastCycle)
        ||(pTCIInput->t_OOIObj[TCI_OBJ_NEXTRIGHT].ObjID == pt_TCI_GlobalData->ObjIDLastCycle)
        ||(pTCIInput->t_OOIObj[TCI_OBJ_HIDDENNEXTLEFT].ObjID == pt_TCI_GlobalData->ObjIDLastCycle)
        ||(pTCIInput->t_OOIObj[TCI_OBJ_HIDDENNEXTRIGHT].ObjID == pt_TCI_GlobalData->ObjIDLastCycle)
        )
#endif
        ||(TRUE==b_CheckOffCondition)
        ||(VDY_LONG_MOT_STATE_STDST != pTCIInput->e_EgoMotionState)
        ||(TRUE == pTCIInput->b_Inhibit)
        ||(FALSE==pTCIInput->t_OOIObj[t_TargetOOIID].b_PlausibleObjMovement) 
        )
      {
        pt_TCI_GlobalData->e_TCIState = INACTIVE;
      }
#if (TCI_INTERRUPTEDDRIVEOFFFEATURE == SWITCH_ON)
      /*TC5*/
      /*Checking TC5 conditions for setting TCI state to STOPPEDTARGET*/
      else if(((pTCIInput->t_OOIObj[t_TargetOOIID].e_ObjDynProb == EM_GEN_OBJECT_DYN_PROPERTY_STATIONARY)||(pTCIInput->t_OOIObj[t_TargetOOIID].e_ObjDynProb == EM_GEN_OBJECT_DYN_PROPERTY_STOPPED))&&(pTCIInput->f_VabsXOOI0 <=TCI_MINABSVELOCITYOOI0)
        && (pt_TCI_GlobalData->f_Drivendistance < pt_TCI_GlobalData->f_Driveoffdistance)
        && (pt_TCI_GlobalData->e_NotificationType != CUTOUT)
        )
      {
        pt_TCI_GlobalData->e_TCIState = STOPPEDTARGET;
        pt_TCI_GlobalData->f_Stoppedtargetstatetimer=FCT_VEH_CYCLE_TIME;
      }
#else
      /*TC3*/
      /*Checking TC3 conditions for setting TCI state to STOPPEDSUBJECTANDTARGET*/
       else if(((pTCIInput->t_OOIObj[t_TargetOOIID].e_ObjDynProb == EM_GEN_OBJECT_DYN_PROPERTY_STATIONARY)||(pTCIInput->t_OOIObj[t_TargetOOIID].e_ObjDynProb == EM_GEN_OBJECT_DYN_PROPERTY_STOPPED))&&(pTCIInput->f_VabsXOOI0 <=TCI_MINABSVELOCITYOOI0)
        &&(pt_TCI_GlobalData->f_Drivendistance < pt_TCI_GlobalData->f_Driveoffdistance)
        &&(pt_TCI_GlobalData->e_NotificationType != CUTOUT)
        )
      {
        pt_TCI_GlobalData->e_TCIState = STOPPEDSUBJECTANDTARGET;
        pt_TCI_GlobalData->f_Initialdistance=pTCIInput->t_OOIObj[t_TargetOOIID].f_DistOnTraj;
        pt_TCI_GlobalData->f_Drivendistance=0.0f;
      }
#endif
       /*TC9*/
       /*Checking indication condition and setting Buzzer request as TRUE and 
       setting VISUALStart state to TCI*/
       else if(TRUE==b_IndicationCondition)
       {
#if (TCIACCCOORDINATION == SWITCH_ON)
        if(((DAS_STATUS_ACTIVE == pTCIInput->DAS_status) && (pTCIInput->f_MinRequestedLongAcceleration >= CML_f_Delta)) ||
          ((DAS_STATUS_ACTIVE == pTCIInput->DAS_status) &&(pt_TCI_GlobalData->f_StoppedEgoTimer <= TCI_MINSTOPPEDEGOTIME)))
        {
          b_driveofftoindication=FALSE;
          pt_TCI_GlobalData->e_TCIState = INACTIVE;/*Comment:Assumption is this condition is not hit, since target vehicle is already moving*/
          pt_TCI_GlobalData->e_NotificationType=NOTIFICATIONTYPENONE;
        }
        else 
        {
            b_driveofftoindication=TRUE;

        }
#else
        b_driveofftoindication=TRUE;
#endif
        if(TRUE==b_driveofftoindication)/* PRQA S 3355, 3358 1 */ /* date: 2018-06-08, reviewer: Bibin Mathew, reason: b_driveofftoindication is always TRUE
        while the conditional switch above is disabled */
        {           
		      if(DRIVEOFFDISTANCECANINPUT==e_Mode)
		      {
		          pt_TCI_GlobalData->e_TCIState = INDICATION;
              pTCIOutput->TCI_b_BuzReq=TRUE;
              pt_TCI_GlobalData->f_Indicationtimer=FCT_VEH_CYCLE_TIME;
#if(TCIOutput_INTFVER >= 0x04)
              pTCIOutput->TCI_State=TCI_State_Acoustical_Visual_Start;

#endif
          }
          else
          {
#if (TCIACCCOORDINATION == SWITCH_ON)
#if (TCIOutput_INTFVER >= 0x04)
              pTCIOutput->TCI_HMIDriveOffState=TCI_HMIDriveOffState_Visual_Start;
              pTCIOutput->TCI_b_HMIDriveOff=TRUE;
              pt_TCI_GlobalData->e_TCIState = INDICATION;
              pt_TCI_GlobalData->f_Indicationtimer=FCT_VEH_CYCLE_TIME;
#endif
#endif
          }
		    }
       }
       /*Setting TCI state as INACTIVE if object loss disappeared is found*/
       else if((OBJ_LOSS_DISAPPEARED==pTCIInput->e_ObjLossReasonOOI0 )||(TRUE == pTCIInput->b_FrontObstacleDetected))
       {
           pt_TCI_GlobalData->e_TCIState = INACTIVE;
       }
      else 
      {

      }

}
#endif

#if (TCI_CFG_AUTOCODE == SWITCH_OFF) 
static void TCI_v_StateStoppedTarget(const TCIInputConst_t *const pTCIInput,TCI_GlobalData_t * const pt_TCI_GlobalData)
{
    boolean b_CheckOffCondition=FALSE;
    boolean b_NewObjectDetection=FALSE;

    /*Setting TCI off condition by checking sensor valid condition and TCI activation*/
    b_CheckOffCondition=TCI_b_CheckOffConditions(pTCIInput);
    /*Checking a new object is detected*/
    b_NewObjectDetection=TCI_b_NewObjectDetection(pTCIInput,pt_TCI_GlobalData);
    /*Accumulating stopped target state timer by adding fct vehicle cycle timew to it */
    pt_TCI_GlobalData->f_Stoppedtargetstatetimer+=FCT_VEH_CYCLE_TIME;
    /*TC8*/
    /*Checking conditions for state TC8 and setting state to INACTIVE*/
    if((VDY_LONG_MOT_STATE_STDST != pTCIInput->e_EgoMotionState)
      ||(TRUE == pTCIInput->b_Inhibit)
      ||(TRUE==b_CheckOffCondition)
      ||(OBJ_LOSS_DISAPPEARED == pTCIInput->e_ObjLossReasonOOI0)
      ||(FALSE==pTCIInput->t_OOIObj[TCI_OBJ_NEXT_LONG].b_PlausibleObjMovement )
      ||(TRUE == pTCIInput->b_FrontObstacleDetected)
      ||(TRUE==b_NewObjectDetection)
      )
    {
          pt_TCI_GlobalData->e_TCIState = INACTIVE;
    }
    /*TC6*/
     /*Checking conditions for state TC6 and setting state to DRIVEOFFTARGET*/
    else if((((pTCIInput->t_OOIObj[TCI_OBJ_NEXT_LONG].e_ObjDynProb != EM_GEN_OBJECT_DYN_PROPERTY_STATIONARY)&&(pTCIInput->t_OOIObj[TCI_OBJ_NEXT_LONG].e_ObjDynProb != EM_GEN_OBJECT_DYN_PROPERTY_STOPPED))||(pTCIInput->f_VabsXOOI0 >=TCI_MINABSVELOCITYOOI0))
      &&(pt_TCI_GlobalData->f_Stoppedtargetstatetimer <= TCI_MINSTOPPEDTARGETRESETDRIVENDISTTIME)
      )
    {
        pt_TCI_GlobalData->e_TCIState = DRIVEOFFTARGET;
    }
    /*TC7*/
    /*Checking conditions for state TC7 and setting state to DRIVEOFFTARGET*/
    else if(pt_TCI_GlobalData->f_Stoppedtargetstatetimer > TCI_MINSTOPPEDTARGETRESETDRIVENDISTTIME)
    {
      pt_TCI_GlobalData->e_TCIState = STOPPEDSUBJECTANDTARGET;
      pt_TCI_GlobalData->f_Initialdistance=pTCIInput->t_OOIObj[TCI_OBJ_NEXT_LONG].f_DistOnTraj;
      pt_TCI_GlobalData->f_Drivendistance=0.0f;
    }
    else
    {

    }
}
#endif
#if (TCI_CFG_AUTOCODE == SWITCH_OFF) 
static void TCI_v_StateIndication(const TCIInputConst_t *const pTCIInput,TCIOutput_t * const pTCIOutput,TCI_GlobalData_t * const pt_TCI_GlobalData,TCIMode_t_e e_Mode)
{
  boolean b_CheckOffCondition=FALSE;
  boolean b_NewObjectDetection=FALSE;
  boolean b_CutoutNewObjectDetection=FALSE;
  boolean b_OOI0Present=FALSE;

#if(TCI_TARGETLEAVESSUBJLANE)

  if( pt_TCI_GlobalData->e_NotificationType != CUTOUT)
  {
    /*Checking Last cycle Object ID is currently any of this OOI2,OOI3,OOI4,OOI5 and it's not stationary*/
    if(
      ((pTCIInput->t_OOIObj[TCI_OBJ_NEXTLEFT].ObjID == pt_TCI_GlobalData->ObjIDLastCycle)&&((pTCIInput->t_OOIObj[TCI_OBJ_NEXTLEFT].e_ObjDynProb!=EM_GEN_OBJECT_DYN_PROPERTY_STATIONARY)&&(pTCIInput->t_OOIObj[TCI_OBJ_NEXTLEFT].e_ObjDynProb!=EM_GEN_OBJECT_DYN_PROPERTY_STOPPED)))
      ||((pTCIInput->t_OOIObj[TCI_OBJ_NEXTRIGHT].ObjID == pt_TCI_GlobalData->ObjIDLastCycle)&&((pTCIInput->t_OOIObj[TCI_OBJ_NEXTRIGHT].e_ObjDynProb!=EM_GEN_OBJECT_DYN_PROPERTY_STATIONARY)&&(pTCIInput->t_OOIObj[TCI_OBJ_NEXTRIGHT].e_ObjDynProb!=EM_GEN_OBJECT_DYN_PROPERTY_STOPPED)))
      ||((pTCIInput->t_OOIObj[TCI_OBJ_HIDDENNEXTLEFT].ObjID == pt_TCI_GlobalData->ObjIDLastCycle)&&((pTCIInput->t_OOIObj[TCI_OBJ_HIDDENNEXTLEFT].e_ObjDynProb!=EM_GEN_OBJECT_DYN_PROPERTY_STATIONARY)&&(pTCIInput->t_OOIObj[TCI_OBJ_HIDDENNEXTLEFT].e_ObjDynProb!=EM_GEN_OBJECT_DYN_PROPERTY_STOPPED)))
      ||((pTCIInput->t_OOIObj[TCI_OBJ_HIDDENNEXTRIGHT].ObjID == pt_TCI_GlobalData->ObjIDLastCycle)&&((pTCIInput->t_OOIObj[TCI_OBJ_HIDDENNEXTRIGHT].e_ObjDynProb!=EM_GEN_OBJECT_DYN_PROPERTY_STATIONARY)&&(pTCIInput->t_OOIObj[TCI_OBJ_HIDDENNEXTRIGHT].e_ObjDynProb!=EM_GEN_OBJECT_DYN_PROPERTY_STOPPED)))
      )
    {

       /*Checking Object ID  is valid or not*/
      if(pTCIInput->t_OOIObj[TCI_OBJ_NEXT_LONG].ObjID!= OBJ_INDEX_NO_OBJECT)
      {
        /*if Object ID is valid check for its longitudnal distance is less than Fixed distance threshold*/
        if(pTCIInput->t_OOIObj[TCI_OBJ_NEXT_LONG].f_LongDisplacement < TCI_FIXIDISTTHRESHOLD)
        {
          /*Setting Indication to TRUE*/
            b_OOI0Present=TRUE;
        }
        else
        {
          /*Setting Indication to FALSE*/
          b_OOI0Present=FALSE;
        }
      }
      else
      {
        /*Setting Indication to FALSE*/
          b_OOI0Present=FALSE;
      }


      pt_TCI_GlobalData->e_NotificationType=CUTOUT;
      /*Checking Last Cycle ObjectID and setting OOICutout according to it*/
      if(pTCIInput->t_OOIObj[TCI_OBJ_NEXTLEFT].ObjID == pt_TCI_GlobalData->ObjIDLastCycle)
      {
        pt_TCI_GlobalData->s_OOICutout=TCI_OBJ_NEXTLEFT;
      }
      else if(pTCIInput->t_OOIObj[TCI_OBJ_NEXTRIGHT].ObjID == pt_TCI_GlobalData->ObjIDLastCycle)
      {
        pt_TCI_GlobalData->s_OOICutout=TCI_OBJ_NEXTRIGHT;
      }
      else if(pTCIInput->t_OOIObj[TCI_OBJ_HIDDENNEXTLEFT].ObjID == pt_TCI_GlobalData->ObjIDLastCycle)
      {
        pt_TCI_GlobalData->s_OOICutout=TCI_OBJ_HIDDENNEXTLEFT;
      }
      else 
      {
        pt_TCI_GlobalData->s_OOICutout=TCI_OBJ_HIDDENNEXTRIGHT;
      }
    }
  }
  if( pt_TCI_GlobalData->e_NotificationType == CUTOUT)
  {
    /*Checking Object ID  is valid or not*/
    if(pTCIInput->t_OOIObj[TCI_OBJ_NEXT_LONG].ObjID!= OBJ_INDEX_NO_OBJECT)
    {
      /*if Object ID is valid check for its longitudnal distance is less than Fixed distance threshold*/
      if(pTCIInput->t_OOIObj[TCI_OBJ_NEXT_LONG].f_LongDisplacement < TCI_FIXIDISTTHRESHOLD)
      {
        /*Setting Indication to TRUE*/
          b_OOI0Present=TRUE;
      }
      else
      {
        /*Setting Indication to FALSE*/
        b_OOI0Present=FALSE;
      }
    }
    else
    {
      /*Setting Indication to TRUE*/
        b_OOI0Present=FALSE;
    }
  }
#endif


  /*Checking a new object is detected*/
  b_NewObjectDetection=TCI_b_NewObjectDetection(pTCIInput,pt_TCI_GlobalData);
  /*Setting TCI off condition by checking senssor valid condition and TCI activation*/
  b_CheckOffCondition=TCI_b_CheckOffConditions(pTCIInput);
  /*Checking a new cut out object is detected comparing to Last cycle */
  b_CutoutNewObjectDetection=TCI_b_CutoutNewObjectDetection(pTCIInput,pt_TCI_GlobalData); 

  if(e_Mode == DRIVEOFFDISTANCECANINPUT)
  {
     /*Checking Indication Timer reached its threshold*/
    if(pt_TCI_GlobalData->f_Indicationtimer <= (TCI_INDICATIONREPEATTIME+1.0f))
    {
      pt_TCI_GlobalData->f_Indicationtimer+=FCT_VEH_CYCLE_TIME;
    }

  /*Feature only if ACCOUSTICALNTIFICATION is SWITCH_ON*/  
  #if (TCI_ACCOUSTICALNTIFICATION==SWITCH_ON)
    /*After first buzzer is set 3.5 sec later second buzzer request is set.This is only if accoustical notification is SWITCHED ON*/
    if (pt_TCI_GlobalData->f_Indicationtimer >=TCI_INDICATIONREPEATTIME)
    {
        pTCIOutput->TCI_b_BuzReq=TRUE;
  #if(TCIOutput_INTFVER >= 0x04)
    pTCIOutput->TCI_State=TCI_State_Acoustical_Start;
  #endif
    }
  #endif

    /*TC10*/
    /*Checking conditions for state TC10and setting state to INACTIVE*/
    if ((pt_TCI_GlobalData->f_Indicationtimer >=TCI_INDICATIONREPEATTIME)
      ||(
#if (TCIACCCOORDINATION == SWITCH_ON)
      ((DAS_STATUS_ACTIVE == pTCIInput->DAS_status) && (pTCIInput->f_MinRequestedLongAcceleration >= CML_f_Delta))
      ||
#endif
      (VDY_LONG_MOT_STATE_STDST != pTCIInput->e_EgoMotionState))
  #if (TCI_ACCOUSTICALNTIFICATION==SWITCH_OFF)
      ||(TRUE) /*In case of Visual Notification only first notification is given and INDICATION state is left directly*/
  #endif
      ||(TRUE == b_CheckOffCondition)
      ||(TRUE == pTCIInput->b_Inhibit)
      ||
      ( 
        ((pt_TCI_GlobalData->e_NotificationType==NONSTOPDRIVEOFF)||(pt_TCI_GlobalData->e_NotificationType==INTERRUPTEDDRIVEOFF)
        ||(pt_TCI_GlobalData->e_NotificationType==INTERRUPTEDDRIVEOFFFIXEDDISTANCE))
        &&(  (OBJ_LOSS_DISAPPEARED==pTCIInput->e_ObjLossReasonOOI0) /*Remark:Object Loss Reason is avalable only for OOI0*/
        ||(FALSE==pTCIInput->t_OOIObj[TCI_OBJ_NEXT_LONG].b_PlausibleObjMovement )
        ||(TRUE == pTCIInput->b_FrontObstacleDetected)
        ||(TRUE==b_NewObjectDetection)
        ))
        ||(
        (pt_TCI_GlobalData->e_NotificationType==CUTOUT)
        &&(
        ((TRUE==b_CutoutNewObjectDetection)&&(pt_TCI_GlobalData->f_Indicationtimer > TCI_INDICATIONREPEATTIME))
        ||((TRUE==b_OOI0Present)||(TRUE == pTCIInput->b_FrontObstacleDetected))
        ))
      )
      {
       
      pt_TCI_GlobalData->e_TCIState = INACTIVE;
 
#if(TCI_VISUALNOTIFICATION == SWITCH_ON)
           /*Checking indication timer is greater than minimum visual notification time*/
          if(pt_TCI_GlobalData->f_Indicationtimer > TCI_MINVISUALNOTIFICATIONTIME)
          {
            /*checking EGO is not standstill*/
            if(
#if (TCIACCCOORDINATION == SWITCH_ON)
              ((DAS_STATUS_ACTIVE == pTCIInput->DAS_status) && (pTCIInput->f_MinRequestedLongAcceleration >= CML_f_Delta))
              ||
#endif
              (VDY_LONG_MOT_STATE_STDST != pTCIInput->e_EgoMotionState))/*Remark:Need to handle if subject vehicle starts off and stops again within TCI_MINVISUALNOTIFICATIONTIME sec*/
            {
                  /*IF TCIOutput version is greater than or equal to four then setting TCI state as Visual End notification */
#if (TCIACCCOORDINATION == SWITCH_ON)
#if(TCIOutput_INTFVER >= 0x04)
              pTCIOutput->TCI_State=TCI_State_Visual_End;
#endif
#endif
              pt_TCI_GlobalData->f_Indicationtimer=0.0f;
            }

          }
        

#else
         pt_TCI_GlobalData->f_Indicationtimer=0.0f;
#endif
        

      }
  }
  else
  {

    pt_TCI_GlobalData->e_TCIState = INACTIVE;
    pt_TCI_GlobalData->f_Indicationtimer+=FCT_VEH_CYCLE_TIME;

  }
}
#endif
#if (TCI_CFG_AUTOCODE == SWITCH_OFF) 
static boolean TCI_b_CheckOffConditions(const TCIInputConst_t *const pTCIInput)
{
  boolean b_offCondition=FALSE;
  /*Checking Sensor is valid or not or TCI is activated or not*/
  if((FALSE == pTCIInput->b_SensorValid)||(FALSE == pTCIInput->b_TCIActivated))
  {
    b_offCondition=TRUE;
  }
  return b_offCondition;
}
#endif

#if (TCI_CFG_AUTOCODE == SWITCH_OFF) 
static boolean TCI_b_NewObjectDetection(const TCIInputConst_t *const pTCIInput,const TCI_GlobalData_t *const pt_TCI_GlobalData)
{
  boolean b_NewObjectDetection=FALSE;
  /*To check a new OOI object is detected comparing to last cycle object ID*/
  if(pt_TCI_GlobalData->ObjIDLastCycle != pTCIInput->t_OOIObj[TCI_OBJ_NEXT_LONG].ObjID)/*This implies OOI changes from OOI0 to another*/
  {
    b_NewObjectDetection=TRUE;
  }
  return b_NewObjectDetection;
}
#endif

#if (TCI_CFG_AUTOCODE == SWITCH_OFF) 
static boolean TCI_b_CutoutNewObjectDetection(const TCIInputConst_t *const pTCIInput,const TCI_GlobalData_t * const pt_TCI_GlobalData)
{
 /*Remarks:if Cutout to OOI4 or OOI5 object might not be selected as OOI due to other close objects to the subject lane therefore it mightbe necessary not to check the following condition 
 for OOI4 and OOI5
 it might be necessary not to check function TCI_b_CheckForOOI() for OOi4 and OOI5*/
    /*To check whether a new cut out object is detected comparing to Last cycle */
    boolean b_CutoutNewObjectDetection=FALSE;
    if((pt_TCI_GlobalData->s_OOICutout > OBJ_INDEX_NO_OBJECT) && (pt_TCI_GlobalData->ObjIDLastCycle != pTCIInput->t_OOIObj[pt_TCI_GlobalData->s_OOICutout].ObjID))
    {
      b_CutoutNewObjectDetection=TRUE;
    }
  return b_CutoutNewObjectDetection;
}
#endif
#if (TCI_CFG_AUTOCODE == SWITCH_OFF) 
static boolean TCI_b_IndicationConditions(const TCIInputConst_t *const pTCIInput,TCI_GlobalData_t * const pt_TCI_GlobalData)
{
  boolean b_IndicationCondition=FALSE;
/*This part of code is only if Target Leave Subject Lane Feature is active*/
#if(TCI_TARGETLEAVESSUBJLANE)
 
  /*Checking Last cycle Object ID is currently any of this OOI2,OOI3,OOI4,OOI5 and it's not stationary*/
  if(
     ((pTCIInput->t_OOIObj[TCI_OBJ_NEXTLEFT].ObjID == pt_TCI_GlobalData->ObjIDLastCycle)&&((pTCIInput->t_OOIObj[TCI_OBJ_NEXTLEFT].e_ObjDynProb!=EM_GEN_OBJECT_DYN_PROPERTY_STATIONARY)&&(pTCIInput->t_OOIObj[TCI_OBJ_NEXTLEFT].e_ObjDynProb!=EM_GEN_OBJECT_DYN_PROPERTY_STOPPED)))
      ||((pTCIInput->t_OOIObj[TCI_OBJ_NEXTRIGHT].ObjID == pt_TCI_GlobalData->ObjIDLastCycle)&&((pTCIInput->t_OOIObj[TCI_OBJ_NEXTRIGHT].e_ObjDynProb!=EM_GEN_OBJECT_DYN_PROPERTY_STATIONARY)&&(pTCIInput->t_OOIObj[TCI_OBJ_NEXTRIGHT].e_ObjDynProb!=EM_GEN_OBJECT_DYN_PROPERTY_STOPPED)))
      ||((pTCIInput->t_OOIObj[TCI_OBJ_HIDDENNEXTLEFT].ObjID == pt_TCI_GlobalData->ObjIDLastCycle)&&((pTCIInput->t_OOIObj[TCI_OBJ_HIDDENNEXTLEFT].e_ObjDynProb!=EM_GEN_OBJECT_DYN_PROPERTY_STATIONARY)&&(pTCIInput->t_OOIObj[TCI_OBJ_HIDDENNEXTLEFT].e_ObjDynProb!=EM_GEN_OBJECT_DYN_PROPERTY_STOPPED)))
      ||((pTCIInput->t_OOIObj[TCI_OBJ_HIDDENNEXTRIGHT].ObjID == pt_TCI_GlobalData->ObjIDLastCycle)&&((pTCIInput->t_OOIObj[TCI_OBJ_HIDDENNEXTRIGHT].e_ObjDynProb!=EM_GEN_OBJECT_DYN_PROPERTY_STATIONARY)&&(pTCIInput->t_OOIObj[TCI_OBJ_HIDDENNEXTRIGHT].e_ObjDynProb!=EM_GEN_OBJECT_DYN_PROPERTY_STOPPED)))
     )
  {
    /*Checking Object ID  is valid or not*/
    if(pTCIInput->t_OOIObj[TCI_OBJ_NEXT_LONG].ObjID!= OBJ_INDEX_NO_OBJECT)
    {
      /*if Object ID is valid check for its longitudnal distance is less than Fixed distance threshold*/
      if(pTCIInput->t_OOIObj[TCI_OBJ_NEXT_LONG].f_LongDisplacement > TCI_FIXIDISTTHRESHOLD)
      {
        /*Setting Indication to TRUE*/
          b_IndicationCondition=TRUE;
      }
      else
      {
        /*Setting Indication to FALSE*/
        b_IndicationCondition=FALSE;
      }
    }
    else
    {
      /*Setting Indication to TRUE*/
        b_IndicationCondition=TRUE;
    }
    pt_TCI_GlobalData->e_NotificationType=CUTOUT;
    /*Checking Last Cycle ObjectID and setting OOICutout according to it*/
    if(pTCIInput->t_OOIObj[TCI_OBJ_NEXTLEFT].ObjID == pt_TCI_GlobalData->ObjIDLastCycle)
    {
      pt_TCI_GlobalData->s_OOICutout=TCI_OBJ_NEXTLEFT;
    }
    else if(pTCIInput->t_OOIObj[TCI_OBJ_NEXTRIGHT].ObjID == pt_TCI_GlobalData->ObjIDLastCycle)
    {
      pt_TCI_GlobalData->s_OOICutout=TCI_OBJ_NEXTRIGHT;
    }
    else if(pTCIInput->t_OOIObj[TCI_OBJ_HIDDENNEXTLEFT].ObjID == pt_TCI_GlobalData->ObjIDLastCycle)
    {
      pt_TCI_GlobalData->s_OOICutout=TCI_OBJ_HIDDENNEXTLEFT;
    }
    else 
    {
      pt_TCI_GlobalData->s_OOICutout=TCI_OBJ_HIDDENNEXTRIGHT;
    }
  }
  
#endif
  /*Accumulating driven distance by taking differences of OOI0's DistOnTraj of current and last cycle  */
  if(b_IndicationCondition == FALSE)
  {
    pt_TCI_GlobalData->f_Drivendistance += (pTCIInput->t_OOIObj[TCI_OBJ_NEXT_LONG].f_DistOnTraj - pt_TCI_GlobalData->f_DistOnTrajLastCycle);
  }
/*If feature like NONSTOPDRIVEOFF and INTERRUPTEDDRIVEOFF is SWITCH_ON,by checking driven distaance is greater or equal to drive off distance 
indicationcondition flag is set to TRUE*/
#if ((TCI_NONSTOPDRIVEOFFFEATURE == SWITCH_ON)||(TCI_INTERRUPTEDDRIVEOFFFEATURE == SWITCH_ON))
  if( (b_IndicationCondition == FALSE) && (pt_TCI_GlobalData->f_Drivendistance >= pt_TCI_GlobalData->f_Driveoffdistance))
  {
    b_IndicationCondition=TRUE;
    /*setting notificaton type according to the feature enabled*/
#if ((TCI_NONSTOPDRIVEOFFFEATURE == SWITCH_ON))
    pt_TCI_GlobalData->e_NotificationType=NONSTOPDRIVEOFF;
#else
    pt_TCI_GlobalData->e_NotificationType=INTERRUPTEDDRIVEOFF;
#endif
  }
#endif
/*if feature like INTERRUPTEDDRIVEOFFFIXNOTIFICATION is enabled and diston traj is greater than or equal to FIXEDDISTANCETHRESHOLD
indicationcondition flag is set to TRUE*/
#if (TCI_INTERRUPTEDDRIVEOFFFIXNOTIFICATION)
  if((b_IndicationCondition == FALSE) && (pTCIInput->t_OOIObj[TCI_OBJ_NEXT_LONG].f_DistOnTraj >=TCI_FIXIDISTTHRESHOLD))
  {
    b_IndicationCondition=TRUE;
    /*setting notificaton type as INTERRUPTEDDRIVEOFFFIXEDDISTANCE*/
    pt_TCI_GlobalData->e_NotificationType=INTERRUPTEDDRIVEOFFFIXEDDISTANCE;
  }
#endif

#if((TCI_INTERRUPTEDDRIVEOFFFIXNOTIFICATION == SWITCH_OFF)&&(TCI_TARGETLEAVESSUBJLANE == SWITCH_OFF ))
    _PARAM_UNUSED(pTCIInput);
#endif
   return b_IndicationCondition;
}
#endif

#if (TCI_CFG_AUTOCODE == SWITCH_OFF) 
static boolean TCI_b_CheckForOOI(const TCIInputConst_t *const pTCIInput,const TCI_GlobalData_t * const pt_TCI_GlobalData)
{
  boolean b_PartOfOOI = FALSE;
  uint8 obj=0u;
  /*Looping through OOI list*/
  for(obj=0u; obj <= TCI_OBJ_HIDDENNEXTRIGHT; obj++)
  {
    /*Checking whether last cycle object ID is a part of current OOI List*/
    if(pt_TCI_GlobalData->ObjIDLastCycle == pTCIInput->t_OOIObj[obj].ObjID)
    {
      b_PartOfOOI=TRUE;
      break;
    }
  }
  return b_PartOfOOI;
}
#endif

#if (TCI_CFG_AUTOCODE == SWITCH_OFF) 

static void TCI_v_InitPersistentData(TCI_GlobalData_t * const pt_TCI_GlobalData)
{
  /*Initializing all Global datas to default values*/
  pt_TCI_GlobalData->f_Driveoffdistance=0.f;
  pt_TCI_GlobalData->f_Indicationtimer=0.0f;
  pt_TCI_GlobalData->f_Drivendistance=0.f;
  pt_TCI_GlobalData->f_Initialdistance=0.f;
  pt_TCI_GlobalData->f_Stoppedtargettimer=0.0f;
#if (TCIACCCOORDINATION == SWITCH_ON)
  pt_TCI_GlobalData->f_StoppedEgoTimer=0.0f;
#endif
  pt_TCI_GlobalData->f_Stoppedtargetstatetimer=0.0f;
  pt_TCI_GlobalData->f_DistOnTrajLastCycle=0.f;
  pt_TCI_GlobalData->e_TCIState=INACTIVE;
  pt_TCI_GlobalData->e_NotificationType=NOTIFICATIONTYPENONE;
  pt_TCI_GlobalData->ObjIDLastCycle=OBJ_INDEX_NO_OBJECT;
  pt_TCI_GlobalData->s_OOICutout = -1;
  pt_TCI_GlobalData->b_subjectdriveoffrequired=FALSE;
}

#endif

#if (TCI_CFG_AUTOCODE == SWITCH_OFF) 
static void TCI_v_MeasFreeze(const TCIInputConst_t * p_TCIInput,const TCI_GlobalData_t *p_TCI_GlobalData
#if (TCIACCCOORDINATION == SWITCH_ON)
  ,const TCI_GlobalData_t *p_TCIACC_GlobalData
#endif  
 )
{
  /* Get data for measurement freeze in simulation */
#ifdef FCT_SIMU
  TCI_SimMeasInfo.t_TCI_InternalInput = *p_TCIInput;
  TCI_SimMeasInfo.t_TCI_GlobalData = *p_TCI_GlobalData;
#if (TCIACCCOORDINATION == SWITCH_ON)
  TCI_SimMeasInfo.t_TCIACC_GlobalData=*p_TCIACC_GlobalData;
#endif
#endif
#ifdef FCT_SIMU
  /*! Freeze simulation data */
   (void)MeasFreeze_Lopc_StackVar(FCT_MEAS_ID_TCI_SIM, (void*)&TCI_SimMeasInfo, sizeof(TCI_SimMeasInfo_t));
#endif /* END IF FCT_SIMU */

  /*! Freeze device data */

#ifndef FCT_SIMU
  _PARAM_UNUSED(p_TCIInput);
  _PARAM_UNUSED(p_TCI_GlobalData);
#if (TCIACCCOORDINATION == SWITCH_ON)
  _PARAM_UNUSED(p_TCIACC_GlobalData);
#endif
#endif
}
#endif
#endif  /* FCT_CFG_TCI && (FCT_CFG_ACT_CODE_VERSION == SWITCH_OFF) */
/** @} end defgroup */
/* date: 2019-04-02, reviewer: Bibin Mathew, reason: Number of lines exceeded per file, not safety critical */
// PRQA S 7013