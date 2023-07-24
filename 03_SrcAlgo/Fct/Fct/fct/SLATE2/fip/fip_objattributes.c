/*! \file **********************************************************************

COMPANY:                   COPYRIGHT (C) Continental AG

PROJECT:                   Adaptive Cruise Control (ACC)

CPU:                       CPU-Independent

COMPONENT:                 ACC_FIP (Adaptive Cruise Control - Function Input Preprocessing)

PACKAGENAME:               fip_objattributes.c

DESCRIPTION:               ACC FIP Object attributes calculation module

AUTHOR:                    Gergely Ungvary (based on code from Fridolin Kolb & Robert Thiel)

CREATION DATE:             2009.12.03

  VERSION:                  $Revision: 1.30 $

LEGACY VERSION:            Revision: 2.2.1.1

**************************************************************************** */

/*****************************************************************************
  INCLUDES
*****************************************************************************/

#include "fip.h"//PRQA S 0380 
/* date: 2019-07-28, reviewer:Prabhu Sundaramurthy, reason: Arises due to inclusion of multiple header files in this header file which has multiple macros*/
#if (FCT_CFG_INPUT_PREPROCESSSING)

/*****************************************************************************
  MODULE DESCRIPTION
*****************************************************************************/
/**
@defgroup fip_objattributes FIP Object Attributes
@ingroup fip
@brief          Pre Processing of object attribute data. FIP object attributes are updated with EM data and a few
	            object attributes are calculated.\n\n

@{

*/
#include "fip_par.h"

/*****************************************************************************
  MODULE GLOBAL CONSTANTS
*****************************************************************************/


/*****************************************************************************
  MODULE GLOBAL VARIABLES
*****************************************************************************/


/*****************************************************************************
  MODULE LOCAL SYMBOLIC CONSTANTS
*****************************************************************************/

#define TP_SI_VDY_A_OBJ_FILTER_TIME         200.0F
#define TP_SI_MERGED_A_OBJ_FILTER_TIME_MIN  0.0F
#define TP_SI_MERGED_A_OBJ_STD_DEV_MAX      1.0F

#define SI_OBJLENGTH_CAR                   (5.f)
#define SI_OBJLENGTH_TRUCK                 (18.f)
#define SI_OBJLENGTH_SHORT                 (1.5f)
#define SI_OBJLENGTH_DEFAULT               (5.f)

#define FIP_MIN_OBJ_WIDTH_CAR_STAT         (1.8f)
#define FIP_MAX_OBJ_WIDTH_CAR_STAT         (3.0f)
#define FIP_OBJ_WIDTH_CAR_MOVE             (1.8f)
#define FIP_OBJ_WIDTH_TRUCK                (2.5f)
#define FIP_OBJ_WIDTH_SMALL_OBJ            (0.8f)
#define FIP_OBJ_WIDTH_MOVE                 (2.0f)
#define FIP_ACC_MIN_DIST_OBJ_WIDTH_DIST_ADAPTED    (110.0f)
#define FIP_ACC_MIN_OBJ_WIDTH_FAR_DIST     (1.8f)
#define FIP_MIN_OBJ_WIDTH_STAT             (0.8f)
#define FIP_MAX_OBJ_WIDTH_STAT             (2.0f)

#define FIP_MIN_OBJ_WIDTH_OTHER_CLASS_STAT       FIP_MIN_OBJ_WIDTH_CAR_STAT
#define FIP_MAX_OBJ_WIDTH_OTHER_CLASS_STAT       FIP_MAX_OBJ_WIDTH_CAR_STAT

/*! Parameter to determine when a stationary object is not selected as OOI 
    since it is an oncoming and stopped object */
#define SI_STATOBJ_ONCOMINGCOUNTER_MAX            (100u)

#if (FIP_CFG_CHECK_STAT_OBJ_WAS_ONCOMING)
#define SI_STATOBJ_ONCOMINGCOUNTER_MIN                    (30u)
#define SI_STATOBJ_ONCOMING_XDIST_HYSTERESIS              (5.f)
#endif
#define SI_PAR_STOPPED_ONCOMING_INLANE_DISTX_MAX          (2.f * FIP_PAR_ONCOMMING_KEEP_RELEV_DISTX_MAX)


/* definition of classification dependent minimum, maximum and default dimensions */
/* class car minimum, maximum and default dimensions */
#define FIP_CLASS_CAR_MIN_LENGTH              3.0f
#define FIP_CLASS_CAR_MAX_LENGTH              7.0f
#define FIP_CLASS_CAR_DEFAULT_LENGTH          5.0f
#define FIP_CLASS_CAR_MIN_WIDTH               1.4f
#define FIP_CLASS_CAR_MAX_WIDTH               2.2f
#define FIP_CLASS_CAR_DEFAULT_WIDTH           1.8f
/* class truck minimum, maximum and default dimensions */
#define FIP_CLASS_TRUCK_MIN_LENGTH            5.0f
#define FIP_CLASS_TRUCK_MAX_LENGTH            25.0f
#define FIP_CLASS_TRUCK_DEFAULT_LENGTH        18.0f
#define FIP_CLASS_TRUCK_MIN_WIDTH             2.0f
#define FIP_CLASS_TRUCK_MAX_WIDTH             2.8f
#define FIP_CLASS_TRUCK_DEFAULT_WIDTH         2.5f
/* class pedestrian minimum, maximum and default dimensions length and width treated same */
#define FIP_CLASS_PED_MIN_DIMENSION           0.4f
#define FIP_CLASS_PED_MAX_DIMENSION           0.8f
#define FIP_CLASS_PED_DEFAULT_DIMENSION       0.6f
/* class motorcycle minimum, maximum and default dimensions */
#define FIP_CLASS_MOTORCYCLE_MIN_LENGTH       2.0f
#define FIP_CLASS_MOTORCYCLE_MAX_LENGTH       4.0f
#define FIP_CLASS_MOTORCYCLE_DEFAULT_LENGTH   2.5f
#define FIP_CLASS_MOTORCYCLE_MIN_WIDTH        0.5f
#define FIP_CLASS_MOTORCYCLE_MAX_WIDTH        1.2f
#define FIP_CLASS_MOTORCYCLE_DEFAULT_WIDTH    1.0f
/* class bicile minimum, maximum and default dimensions */
#define FIP_CLASS_BICICLE_MIN_LENGTH          FIP_CLASS_MOTORCYCLE_MIN_LENGTH    
#define FIP_CLASS_BICICLE_MAX_LENGTH          FIP_CLASS_MOTORCYCLE_MAX_LENGTH    
#define FIP_CLASS_BICICLE_DEFAULT_LENGTH      FIP_CLASS_MOTORCYCLE_DEFAULT_LENGTH
#define FIP_CLASS_BICICLE_MIN_WIDTH           FIP_CLASS_MOTORCYCLE_MIN_WIDTH     
#define FIP_CLASS_BICICLE_MAX_WIDTH           FIP_CLASS_MOTORCYCLE_MAX_WIDTH     
#define FIP_CLASS_BICICLE_DEFAULT_WIDTH       FIP_CLASS_MOTORCYCLE_DEFAULT_WIDTH 
/* class point minimum, maximum and default dimensions length and width treated same */
#define FIP_CLASS_POINT_MIN_DIMENSION         0.1f
#define FIP_CLASS_POINT_MAX_DIMENSION         0.5f
#define FIP_CLASS_POINT_DEFAULT_DIMENSION     0.4f
/* class unclassified minimum, maximum and default dimensions length and width treated same */
#define FIP_CLASS_UNCLASSIFIED_MIN_DIMENSION     0.1f
#define FIP_CLASS_UNCLASSIFIED_MAX_DIMENSION     50.0f
#define FIP_CLASS_UNCLASSIFIED_DEFAULT_DIMENSION 50.0f



/*****************************************************************************
  MODULE LOCAL MACROS
*****************************************************************************/


/*****************************************************************************
  MODULE LOCAL TYPES
*****************************************************************************/


/*****************************************************************************
  MODULE LOCAL CONSTANTS
*****************************************************************************/


/*****************************************************************************
  MODULE LOCAL TYPEDEFS
*****************************************************************************/


/*****************************************************************************
  MODULE LOCAL VARIABLES
*****************************************************************************/


/*! Definition of module local pointer to output structure for global access within module */
SET_MEMSEC_VAR(pt_FIP_OA_Input)
static FIP_OA_InputConst_t * pt_FIP_OA_Input;


/*! Definition of module local pointer to output structure for global access within module */
SET_MEMSEC_VAR(pt_FIP_OA_Output)
static FIP_OA_Output_t * pt_FIP_OA_Output;

/*****************************************************************************
  FUNCTION PROTOTYPES
*****************************************************************************/

static void FIP_v_ObjDynamicProperty(const ObjNumber_t ObjNr);
static void FIP_v_ObjWasOncoming(const ObjNumber_t ObjNr);
static void FIP_v_OA_InitEveryCycle(void);
static void FIP_v_OA_InitPersistentData(void);
static void FIP_v_OA_SetInput(void);
static void FIP_v_SetObjWidthForCorridor(const ObjNumber_t iObj);
static void FIP_v_CalculateObjLengthandWidth(const ObjNumber_t ObjNr);
static void FIP_f_GetObjectLength(const ObjNumber_t uiObject);

#if (SIT_CFG_FILTER_ABS_OBJ_SPEED)
static fVelocity_t FIP_f_DetermineObjectAbsSpeed(const ObjNumber_t ObjId);
#endif
#if (SIT_CFG_FILTER_ABS_OBJ_ACCEL)
static float32 FIP_f_DetermineObjectAbsAccel(const ObjNumber_t ObjId);
#endif

#if (FCT_CFG_CAMERA_OBJECT_DETECTION)
static void FIP_v_InitCameraObjData(const ObjNumber_t ObjNr);  
#endif

/*****************************************************************************
  FUNCTION DEFINITIONS
*****************************************************************************/

/*************************************************************************************************************************
  Functionname:    FIP_v_InitGlobalObjAttributes                                                           */ /*!

  @brief           Init Function to be called in INIT state

  @description     Initialize ObjAttributes global data in INIT state

  @startuml 
  Partition FIP_v_InitGlobalObjAttributes
  Start
	  Note right: This function initializes Object Attributes global data in INIT state
	  - Depending on the available sources initialize persistent data and non-persistent data in FIP Object Attributes
  Stop
  @enduml

  @return          -

  @param[in]       pt_FIP_OA_InputGlobal : Reference to FIP OA input structure instantiated in Frame module
  @param[in]       pt_FIP_OA_OutputGlobal : Reference to FIP OA output structure instantiated in Frame module

  @glob_in         -
  @glob_out        -

  @c_switch_part   -
  @c_switch_full   FCT_CFG_INPUT_PREPROCESSSING : FCT support for FCT Input Preprocessing (FIP): Need to be switched on for ACC

  @pre             -
  @post            -

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @created         06.10.2016
  @changed         -

  @author          Gangadhar Badiger | gangadhar.badiger-EXT@continental-corporation.com | +91 (80) 6679-6055
*************************************************************************************************************************/
void FIP_v_InitGlobalObjAttributes(FIP_OA_InputConst_t * pt_FIP_OA_InputGlobal, FIP_OA_Output_t * pt_FIP_OA_OutputGlobal)
{
  
  /* Assign local pointers */
  pt_FIP_OA_Input = pt_FIP_OA_InputGlobal;
  pt_FIP_OA_Output = pt_FIP_OA_OutputGlobal;

  /*! Initialize persistent data of the component */
  FIP_v_OA_InitPersistentData();

  /*! Initialize static data of the component in each cycle */
  FIP_v_OA_InitEveryCycle();

  /* Reset local pointers */
  pt_FIP_OA_Input = NULL;
  pt_FIP_OA_Output = NULL;
}

/*************************************************************************************************************************
  Functionname:    FIP_v_OA_PreProcess                                                                              */ /*!

  @brief           Preprocess inputs for FIP Object Attributes sub-module

  @description     Preprocess inputs for FIP Object Attributes sub-module

  @startuml 
  Partition FIP_v_OA_PreProcess
  Start
	  Note right: This function preprocesses inputs for FIP Object Attributes sub-module
	  - Depending on the available sources set the input for FIP Object Attributes module
  Stop
  @enduml

  @return          -

  @param[in]   pt_FIP_OA_InputGlobal : Reference to FIP OA input structure instantiated in Frame

  @glob_in         None
  @glob_out        None

  @c_switch_part   None
  @c_switch_full   FCT_CFG_INPUT_PREPROCESSSING : FCT support for FCT Input Preprocessing (FIP): Need to be switched on for ACC

  @pre             None
  @post            No changes

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @created         23.10.2016
  @changed         23.10.2016

  @author          Harsha Umesh Babu | harsha.umesh.babu@continental-corporation.com | +49 (8382) 9699-474
*************************************************************************************************************************/
void FIP_v_OA_PreProcess(FIP_OA_InputConst_t * pt_FIP_OA_InputGlobal)
{
  /* Assign local pointers */
  pt_FIP_OA_Input = pt_FIP_OA_InputGlobal;

  /* Set Inputs */
  FIP_v_OA_SetInput();

  /* Reset local pointers */
  pt_FIP_OA_Input = NULL;
}

#if (SIT_CFG_FILTER_ABS_OBJ_SPEED)
/*************************************************************************************************************************
  Functionname:    FIP_f_DetermineObjectAbsSpeed                                                                        */ /*!

  @brief           This function determines the absolute object speed

  @description     This function determines the absolute object speed

  @startuml 
    Partition FIP_f_DetermineObjectAbsSpeed
    Start
  	  Note right: This function determines the absolute object speed of object
  	  - Absolute Velocity of object is computed by adding \n Longitudinal Velocity of the object and the \n radar corrected speed from VDY synchronized
    Stop
  @enduml

  @return          fAbsSpd : The object's absolute speed                          [-330.f ... 330.f] m/s

  @param[in]       ObjId : The index of the object                                [OBJ_INDEX_NO_OBJECT ... EM_N_OBJECTS[

  @glob_in         OBJ_LONG_VREL(i) : Relative longitudinal velocity of object i  [-330.f ... 330.f] m/s
                      with i in [0u ... EM_N_OBJECTS[
  @glob_in         pt_FIP_RTE_Input->pf_EgoVelObjSync : Velocity of the ego vehicle             [-330.f ... 330.f] m/s
  @glob_out        -

  @c_switch_part   -
  @c_switch_full   FCT_CFG_INPUT_PREPROCESSSING : FCT support for FCT Input Preprocessing (FIP)
  @c_switch_full   SIT_CFG_FILTER_ABS_OBJ_SPEED : configuration switch for enabling absolute speed calculation
                                                 per object in SI

  @pre             Vehicle speed object sync and relative long velocity have to be available for the object
  @post            -

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @created         -
  @changed         01.03.2016

  @author          Robert Thiel
*************************************************************************************************************************/
static fVelocity_t FIP_f_DetermineObjectAbsSpeed(const ObjNumber_t ObjId)
{
  fVelocity_t fAbsSpd;
  fAbsSpd = *pt_FIP_RTE_Input->pf_ObjVRelX(ObjId) + *pt_FIP_RTE_Input->pf_EgoVelObjSync;
  return fAbsSpd;
}
#endif


#if (SIT_CFG_FILTER_ABS_OBJ_ACCEL)
/*************************************************************************************************************************
  Functionname:    FIP_f_DetermineObjectAbsAccel                                                                        */ /*!

  @brief           Filters the object acceleration

  @description     Filters the object acceleration.
                   Determined as the previous abs acceleration and the new raw value, with the previous value weighted 
                   with a filter constant. In order to do so, the filter constants are determined before based on 
                   variances ant cycle time.
  
  @startuml 
    Partition FIP_f_DetermineObjectAbsAccel
    Start
    	Note right: This function determines the object acceleration
  	  If (Object is New)then (True)
  		  - Set object’s absolute acceleration to Zero
  	  Else (False)
  		- Object is old enough, start filtering it's absolute acceleration
  		- Get previous absolute acceleration of object for filtering
  		If (Configuration switch to correct the absolute object \n acceleration value is enabled) then (True)
  			- Calculate corrected raw absolute acceleration of object
  		Else (False)
  			- Calculate raw absolute acceleration of object \n (Object longitudinal acceleration added with \n Radar corrected acceleration for synchronization)
  		Endif
  		- Get the standard deviation of Ego vehicle \n acceleration and limit it to one
  		- Calculate a filtering constant
  		- Normalize the filter constant
  		- The final absolute acceleration is the previous absolute \n acceleration and the new raw value, with the previous value \n weighted with the filter constant
  	  Endif
    Stop
  @enduml

  @return          fAbsAccel : absolute acceleration of the object after filtering.

  @param[in]       ObjId : The object index to determine acceleration for                     [OBJ_INDEX_NO_OBJECT ... EM_N_OBJECTS[

  @glob_in         OBJ_ABS_ACCEL_X(i) : Absolute acceleration of object i                     [-100.f ... 100.f] m/s^2
                      with i in [0u ... EM_N_OBJECTS[
  @glob_in         SLATE_b_GetObjIsNew(i) : Information if administration state of object i is EM_GEN_OBJECT_MT_STATE_NEW
                      with i in [0u ... EM_N_OBJECTS[                                         [TRUE, FALSE]
  @glob_in         OBJ_KINEMATIC(i) : Information about the kinematics of object i with i in [0u ... EM_N_OBJECTS[
                      fVabsY                                                                  [-330.f ... 330.f] m/s
                      fAabsX                                                                  [-100.f ... 100.f] m/s^2
  @glob_in         pt_FIP_RTE_Input->pf_ObjVRelX(i) : Relative longitudinal velocity of object i              [-330.f ... 330.f] m/s
                      with i in [0u ... EM_N_OBJECTS[
  @glob_in         SLATE_f_GetEgoYawRateObjSync() : Ego yaw rate                                       [-100.f ... 100.f] rad/s
                      with i in [0u ... EM_N_OBJECTS[
  @glob_in         OBJ_LAT_DISPLACEMENT(i) : Lateral displacement of obejct i                 [-PI/2*RW_FCT_MAX ... PI/2*RW_FCT_MAX] m
                      with i in [0u ... EM_N_OBJECTS[
  @glob_in         pt_FIP_RTE_Input->pf_ObjArelX(i) : Longitudinal acceleration of object i                   [-100.f ... 100.f] m/s^2
                      with i in [0u ... EM_N_OBJECTS[
  @glob_in         EGO_MERGED_EGO_ACCEL_X_OBJ_SYNC : Longitudinal acceleration correction :   [-100.f ... 100.f] m/s^2
  @glob_in         EGO_MERGED_EGO_ACCEL_X_STD_OBJ_SYNC : Standard deviation of longitudinal acceleration correction 
                                                                                              [-100.f ... 100.f] m/s^2
  @glob_in         SLATE_f_GetSITCycleTime() : SI cycle time                                              [0.f ... 1.f] s
  @glob_out        -

  @c_switch_part   SIT_CFG_CORR_ABS_OBJ_ACCEL : Configuration switch to correct the absolute object acceleration value 
                                               because of assumption of longitudinal movement only in the tracking. That 
                                               assumption leads to wrong calculated object abs. acceleration in narrow curves
  @c_switch_full   FCT_CFG_INPUT_PREPROCESSSING : FCT support for FCT Input Preprocessing (FIP)
  @c_switch_full   SIT_CFG_FILTER_ABS_OBJ_ACCEL : Configuration switch for enabling filtered absolute acceleration
                                                 calculation per object in SI

  @pre             Vehicle acceleration object sync and it's standard deviation have to be available
  @post            -

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @created         -
  @changed         01.03.2016

  @author          Robert Thiel, robert.thiel@contiautomotive.com
*************************************************************************************************************************/
static float32 FIP_f_DetermineObjectAbsAccel(const ObjNumber_t ObjId)
{
  float32 fAbsAccel = 0.0F;
  boolean b_ObjIsNew;

  b_ObjIsNew = SLATE_b_GetObjIsNew(ObjId);
  if(b_ObjIsNew)
  {
    /*set accel always to 0*/
    fAbsAccel = 0.0F;
  }
  else
  {
    /* Object old enough, start filtering it's absolute acceleration */
    /* Get previous absolute acceleration of object for filtering */
    const float32 fPrevAbsAccel =  pt_FIP_OA_Output->t_ObjList[ObjId].fAbsAcceleration;
    float32 fFilterConst;
    float32 fEgoAccelXStd;
#if (SIT_CFG_CORR_ABS_OBJ_ACCEL)
    float32 fOrientation;
    /*! Calculate corrected raw absolut acceleration of object */
    fOrientation = ATAN2_ (*SLATE_pf_GetObjVabsY(ObjId), (*pt_FIP_RTE_Input->pf_ObjVRelX(ObjId) - (SLATE_f_GetEgoYawRateObjSync() * (*pt_FIP_RTE_Input->pf_ObjLatDisp(ObjId)))));
    fAbsAccel = (*SLATE_pf_GetObjAabsX(ObjId)) *CML_f_Abs( COS_(fOrientation));
#else
    /* Calculate raw absolute acceleration of object */
    fAbsAccel = *pt_FIP_RTE_Input->pf_ObjArelX(ObjId) + SLATE_f_GetEgoCorrectedAccel();
#endif

    /* Get standard deviation of ego acceleration in X direction */
    fEgoAccelXStd = SLATE_f_GetEgoCorrectedSTDAccel();

    /* Limit standard deviation to a given maximum */
    if(fEgoAccelXStd > TP_SI_MERGED_A_OBJ_STD_DEV_MAX)
    {
      fEgoAccelXStd = TP_SI_MERGED_A_OBJ_STD_DEV_MAX;
    }

    /* Calculate a filtering constant: the value will be between
    [TP_SI_MERGED_A_OBJ_FILTER_TIME_MIN .. TP_SI_VDY_A_OBJ_FILTER_TIME] 
    depending on the ego acceleration standard deviation */
    /* <ln_offset:+1 PCLINT Error 835: reviewer name: Boll date: 05-10-2012 reason: TP_SI_MERGED_A_OBJ_FILTER_TIME_MIN set to zero */
    fFilterConst = TP_SI_MERGED_A_OBJ_FILTER_TIME_MIN + (fEgoAccelXStd * ((TP_SI_VDY_A_OBJ_FILTER_TIME - TP_SI_MERGED_A_OBJ_FILTER_TIME_MIN) / (TP_SI_MERGED_A_OBJ_STD_DEV_MAX)));

    /* Normalize the filter constant */
    fFilterConst/= (float32)(SLATE_f_GetSITCycleTime()*1000.0F);

    /* The final absolute acceleration is the previous abs acceleration and
    the new raw value, with the previous value weighted with the filter constant */
    fAbsAccel = ((fPrevAbsAccel*fFilterConst) + fAbsAccel) / (fFilterConst + 1.0F);
  }

  return fAbsAccel;
}
#endif

/*************************************************************************************************************************
  Functionname:    FIP_v_OA_CalcObjAttributes                                                                              */ /*!

  @brief           Calculates and filters the object acceleration

  @description     Calculates and filters the objects absolute speed and filtered acceleration.

  @startuml 
    Partition FIP_v_OA_CalcObjAttributes
    Start
  	  Note right: This function calculates object attributes
  	  - Initialize non-persistent data 
  	  - Iterate through each of the 40 Objects
  	  - Assign object dynamic property in FIP \n object list based on EM dynamic property
  	  - Determine if an stationary object was seen oncoming before
  	  - Compute Length and Width of object \n based on Classification and Shape Points
  	
    	If (Absolute speed calculation per \n object in SI switch is enabled) then (True)
  	  	- Compute the object’s absolute speed
  	  Else (False)
  	  Endif
  
  	If (Absolute acceleration calculation \n per object in SI switch is enabled) then (True)
  		- Compute the object’s abosulte acceleration
  	Else (False)
  	Endif
  
  	If (FCT camera object/lane detection inputs switch is enabled) then (True)	
  		- Compute the Object attributes from \n the Camera Object information
  	Else (False)
  	Endif
  
  	If (Camera based cut in probability for ooi lane association switch \n OR \n Camera based cut in probability for ooi lane association is enabled) then (True)	
  		- Compute Object overlap from Camera \n object data and Camera object width
  	Else (False)
  	Endif
    Stop
  @enduml

  @return          -

  @param[in]       pt_FIP_OA_InputGlobal : Reference to the sub module input structure instantiated in Frame
  @param[in]       pt_FIP_OA_OutputGlobal : Reference to the sub module output structure instantiated in Frame

  @glob_in         -
  @glob_out        OBJ_ABS_VELO_X(i) : Absolute velocity of object i        [-330.f ... 330.f] m/s
                      with i in [0u ... EM_N_OBJECTS[
  @glob_out        OBJ_ABS_ACCEL_X(i) : Absolute acceleration of object i   [-100.f ... 100.f] m/s^2
                      with i in [0u ... EM_N_OBJECTS[

  @c_switch_part   SIT_CFG_FILTER_ABS_OBJ_SPEED : configuration switch for enabling absolute speed calculation per object in SI
  @c_switch_part   SIT_CFG_FILTER_ABS_OBJ_ACCEL : Configuration switch to enable SI external object ID assignment
  @c_switch_part   FCT_CFG_CAMERA_CUTIN_POTENTIAL : activate camera based cut in detection
  @c_switch_part   FCT_CFG_CAMERA_CUTOUT_POTENTIAL : activate camera based cut out detection
  @c_switch_full   FCT_CFG_INPUT_PREPROCESSSING : FCT support for FCT Input Preprocessing (FIP)

  @pre             -
  @post            -

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @created         -
  @changed         01.03.2016
  
  @author          Robert Thiel
*************************************************************************************************************************/
void FIP_v_OA_CalcObjAttributes(FIP_OA_InputConst_t * pt_FIP_OA_InputGlobal, FIP_OA_Output_t * pt_FIP_OA_OutputGlobal)
{
  ObjNumber_t ObjNr;

  /* Assign local pointers */
  pt_FIP_OA_Input = pt_FIP_OA_InputGlobal;
  pt_FIP_OA_Output = pt_FIP_OA_OutputGlobal;

  /* Initialize variables/outputs that are not persistent in nature */
  FIP_v_OA_InitEveryCycle();

  for (ObjNr = (ObjNumber_t)(EM_N_OBJECTS - 1); ObjNr >= 0; ObjNr--)
  {
    FIP_v_ObjDynamicProperty(ObjNr);
    FIP_v_ObjWasOncoming(ObjNr);
    FIP_v_CalculateObjLengthandWidth(ObjNr);
    FIP_f_GetObjectLength(ObjNr);
    FIP_v_SetObjWidthForCorridor(ObjNr);

#if (SIT_CFG_FILTER_ABS_OBJ_SPEED)
    pt_FIP_OA_Output->t_ObjList[ObjNr].fAbsVelocity = FIP_f_DetermineObjectAbsSpeed(ObjNr);
#endif
#if (SIT_CFG_FILTER_ABS_OBJ_ACCEL)
    pt_FIP_OA_Output->t_ObjList[ObjNr].fAbsAcceleration = FIP_f_DetermineObjectAbsAccel(ObjNr);
#endif  
#if (FCT_CFG_CAMERA_OBJECT_DETECTION)
#if (FCT_CFG_INCLUDE_FUSION_OBJECT_LIST)
  /*Updating Camera object to the FIP data*/
  FIP_v_SetCameraObjData(pt_FIP_OA_Output,ObjNr);
#endif
#endif

  } /* END FOR EM_N_OBJECTS */
  /* Reset local pointers */
  pt_FIP_OA_Input = NULL;
  pt_FIP_OA_Output = NULL;
}

/*************************************************************************************************************************
  Functionname:    FIP_v_OA_InitEveryCycle                                                                        */ /*!

  @brief           Initialize static data of the component in each cycle

  @description     Initialize static data (inputs and outputs) of component each cycle 

  @startuml 
    Partition FIP_v_OA_InitEveryCycle
    Start
  	  Note right: This function initializes non-persistent \n output data structures and variables with \n the default values every cycle	
  	  - Initialization of FIP camera object data and camera object External ID
    Stop
  @enduml

  @return          -

  @param[in]       -

  @glob_in         -
  @glob_out        pt_FIP_OA_Output->t_ObjList[t_ObjNr].f_ObjectWidthCorridor : object width for corridor calculations [0.f]
                   with t_ObjNr in [0...EM_N_OBJECTS[
  @c_switch_part   -
  @c_switch_full   FCT_CFG_INPUT_PREPROCESSSING : FCT support for FCT Input Preprocessing (FIP)

  @pre             -
  @post            -

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @created         03.10.2016
  @changed         03.10.2016

  @author          Gangadhar Badiger | gangadhar.badiger-EXT@continental-corporation.com | +91 (80) 6679-6055
*************************************************************************************************************************/
static void FIP_v_OA_InitEveryCycle(void)
{
  /*! Initialize output, input structure */
  ObjNumber_t t_ObjNr;
  for (t_ObjNr = (ObjNumber_t)0; t_ObjNr < EM_N_OBJECTS; t_ObjNr++)
  {
    pt_FIP_OA_Output->t_ObjList[t_ObjNr].f_ObjectWidthCorridor = 0.f;
    pt_FIP_OA_Output->t_ObjList[t_ObjNr].fObjectLength = 0.f;
    pt_FIP_OA_Output->t_ObjList[t_ObjNr].fLength = 0.f;
    pt_FIP_OA_Output->t_ObjList[t_ObjNr].fWidth = 0.f;
    
#if (FCT_CFG_CAMERA_OBJECT_DETECTION)
  /* Initialize Camera object FIP data*/
  FIP_v_InitCameraObjData(t_ObjNr); 
#endif
  } /* END FOR EM_N_OBJECTS */
}

/*************************************************************************************************************************
  Functionname:    FIP_v_OA_InitPersistentData                                                                        */ /*!

  @brief           Initialize persistent data of the component

  @description     Initialize persistent data of the component only in INIT mode. 
                   This is data which need to be retained over several cycles.
  
  @startuml 
    Partition FIP_v_OA_InitPersistentData
    Start
  	  Note right: This function initializes FIP object attributes \n only once in the first cycle
  	  - Iterate through each of the EM Objedts
  	  - Delete object information in FIP object attributes output
  
    Stop
  @enduml

  @return          -

  @param[in]       -

  @glob_in         -
  @glob_out        pt_FIP_OA_Output->t_ObjList[i].t_Bool.bit_StatObjWasOncoming : Bit if stationary object was seen oncomming [0u] 
                      with i in [0u ... EM_N_OBJECTS[

  @c_switch_part   -
  @c_switch_full   FCT_CFG_INPUT_PREPROCESSSING : FCT support for FCT Input Preprocessing (FIP)

  @pre             -
  @post            -

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @created         03.10.2016
  @changed         03.10.2016

  @author          Gangadhar Badiger | gangadhar.badiger-EXT@continental-corporation.com | +91 (80) 6679-6055
*************************************************************************************************************************/
static void FIP_v_OA_InitPersistentData(void)
{
  ObjNumber_t t_ObjNr;

  /*! Note: Inputs received from RTE ports are not initialised */

  /*! Initialize output structure */
  for (t_ObjNr = (ObjNumber_t)0; t_ObjNr < EM_N_OBJECTS; t_ObjNr++)
  {
    /*! Delete object information in FIP object attributes output */
    FIP_v_OA_DeleteObject(t_ObjNr);
  }
}

/*************************************************************************************************************************
  Functionname:    FIP_v_OA_SetInput                                                                        */ /*!

  @brief           Set the input for FIP Object Attributes module

  @description     Set the input for the sub module

  @startuml 
    Partition FIP_v_OA_SetInput
    Start
  	  Note right: This function sets the input for FIP Object Attributes module	
  	  - Set the value of FIP Object Attributes Input
    Stop
  @enduml

  @return          -

  @param[in]       -

  @glob_in         None
  @glob_out        None

  @c_switch_part   None
  @c_switch_full   FCT_CFG_INPUT_PREPROCESSSING : FCT support for FCT Input Preprocessing (FIP)

  @pre             None
  @post            No changes

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @created         03.10.2016
  @changed         03.10.2016

  @author          Gangadhar Badiger | gangadhar.badiger-EXT@continental-corporation.com | +91 (80) 6679-6055
*************************************************************************************************************************/
static void FIP_v_OA_SetInput(void)
{
  pt_FIP_OA_Input->b_ObjIsMovingToStationary = &SLATE_b_GetObjIsMovingToStationary;
}

/*************************************************************************************************************************
  Functionname:    FIP_f_GetObjectLength                                                                                */ /*!

  @brief           Get object length used in SI for object 'uiObject'

  @description     Get object length used in SI for object 'uiObject'. Since length measurement unreliable, 
                    derive an SI internal object length based on the class of the object.
  
  @startuml 
    Partition FIP_f_GetObjectLength
    Start
  	Note right: This function computes object length based on classification	
  	If (Object is CAR) then (True)
  		- Set Object length as 5m
  	Else (False)
  	if (Object is TRUCK) then (True)
  		- Object length is 18m
  	Else (False)
  	if (Object is POINT or \n MOTORCYCLE or \n BICYCLE or \n PEDESTRIAN) then (True)
  		- Object length is 1.5m
  	Else (False)
  		If (Object is STATIONARY) then (False)
  			- Object length is set to \n Object Length (from Shape Point) \n if it is in between \n Truck Length (18m) \n and Car length (5m)
  		Else (False)
  			- Object length is assigned \n with default length (5m)
  		Endif
  	Endif
  	Endif
  	Endif
    Stop
  @enduml

  @return          fObjectLength : The length of the object to use in SI        [0.f ... 100.f] m

  @param[in]       uiObject : The object index to determine the length for      [0u ... EM_N_OEBJECTS[

  @glob_in         *SLATE_pt_GetObjClassification(i) : Object class of object i             [EM_t_GenObjClassification as in Rte_Type.h]
                      with i in [0u ... EM_N_OBJECTS[
  @glob_in         *SLATE_pt_GetObjDynProperty(i) : Dynamic property of object i       [SLATE_t_Obj_DynamicProperty as in Rte_Type.h]
                      with i in [0u ... EM_N_OBJECTS[
  @glob_in         SLATE_f_GetObjectLength(i) : Length of object i                    [0.f ... 100.f] m
                      with i in [0u ... EM_N_OBJECTS[
  @glob_out        -

  @c_switch_part   -
  @c_switch_full   FCT_CFG_INPUT_PREPROCESSSING : FCT support for FCT Input Preprocessing (FIP)

  @pre             -
  @post            -

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @created         -
  @changed         01.03.2016

  @todo            Object width should be derived from measured values of OT, if available
                   Check if default length is realistic for all of the types assigned to

  @author          Fridolin Kolb
*************************************************************************************************************************/
static void FIP_f_GetObjectLength(const ObjNumber_t uiObject)
{
  float32 fObjectLength; 
  float32 f_Length = pt_FIP_OA_Output->t_ObjList[uiObject].fLength;
  SLATE_t_Obj_DynamicProperty t_ObjDynProperty = *SLATE_pt_GetObjDynProperty(uiObject);
  const SLATE_t_Obj_CLassification t_ObjClassification = *SLATE_pt_GetObjClassification(uiObject);
  /*! @todo : Object width should be derived from measured values of OT, if available */
  if (t_ObjClassification == SLATE_OBJCLASS_CAR)
  {
     fObjectLength = SI_OBJLENGTH_CAR;
  }
  else if (t_ObjClassification == SLATE_OBJCLASS_TRUCK)
  {
    fObjectLength = SI_OBJLENGTH_TRUCK;
  }
  else if (    (t_ObjClassification == SLATE_OBJCLASS_POINT)
            || (t_ObjClassification == SLATE_OBJCLASS_MOTORCYCLE )
            || (t_ObjClassification == SLATE_OBJCLASS_BICYCLE )
            || (t_ObjClassification == SLATE_OBJCLASS_PEDESTRIAN))
  {
    fObjectLength = SI_OBJLENGTH_SHORT;
  }
  else
  {
    if((t_ObjDynProperty == SLATE_OBJECT_PROPERTY_STATIONARY) 
#if (FCT_CFG_SENSOR_TYPE_CAMERA)
    || (t_ObjDynProperty == SLATE_OBJECT_PROPERTY_STOPPED) 
#endif /* FCT_CFG_SENSOR_TYPE_CAMERA */
      )
    {
      fObjectLength = MINMAX_FLOAT(SI_OBJLENGTH_CAR, SI_OBJLENGTH_TRUCK, f_Length);
    }
    else
    {
      fObjectLength = SI_OBJLENGTH_DEFAULT;
      /*!    OBJCLASS_UNDEFINED   = 0U,
            ARS_OBJCLASS_WIDE        = 5U,
            OBJCLASS_BRIDGE      = 7U  
      @todo: realistic for all of these types ? */
    }  
  }  
  pt_FIP_OA_Output->t_ObjList[uiObject].fObjectLength =  fObjectLength;
}

/*************************************************************************************************************************
  Functionname:    FIP_v_ObjDynamicProperty                                                                         */ /*!

  @brief           Assign object dynamic property in FIP object list based on EM dynamic property.

  @description     Set Moving/Stationary/Oncoming bit in FIP object list based on EM dynamic property. 
                   Remark: Former information is not reset to 0 (history information retained).
  
  @startuml 
    Partition FIP_v_ObjDynamicProperty
    Start
  	Note right: This function assigns object dynamic property \n in FIP object list based on EM dynamic property	
  	:Object dynamic property |
  	split
  	-EM Object is moving
  		- Set Moving bit in FIP object list \n based on EM dynamic property
  	split again
  	-EM Object is stationary
  		- Set Stationary bit in FIP object list \n based on EM dynamic property
  	split again
  	-EM Object is oncoming
  		- Set Oncoming bit in FIP object list \n based on EM dynamic property
  	end split 
    Stop
  @enduml

  @return          -

  @param[in]       ObjNr : object number [0 ... EM_N_OBJECTS[

  @glob_in         *SLATE_pt_GetObjDynProperty(i) : Dynamic property of object i [SLATE_t_Obj_DynamicProperty as defined in rte_type.h]
                   with i in [0 ... EM_N_OBJECTS[ and EM_N_OBJECTS as in Rte_SWCEmAdapt_Type.h
  @glob_out        t_FIP_ObjectList[i].t_Bool : Reference to bit field for object i with i in [0 ... EM_N_OBJECTS[
                   with i in [0 ... EM_N_OBJECTS[ and EM_N_OBJECTS as in Rte_SWCEmAdapt_Type.h
                                                Moving : Info if object was moving once [TRUE, FALSE]
                                                Oncoming : Info if object was oncoming once [TRUE, FALSE]
                                                Stationary :  Info if object was Stationary once [TRUE, FALSE]

  @c_switch_part   -
  @c_switch_full   FCT_CFG_INPUT_PREPROCESSSING : FCT support for FCT Input Preprocessing (FIP)

  @pre             -
  @post            -

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @created         21.11.2016
  @changed         21.11.2016
*************************************************************************************************************************/
static void FIP_v_ObjDynamicProperty(const ObjNumber_t ObjNr)
{

    /* In old version this bit update was only done for object that
  pass the sensor pre-selection phase. As we only have a single
  pre-selection information out of EM, we can not separate objects
  that only pass sensor preselection. This means that objects can
  be updated with dynamic property states before passing sensor
  preselection. This should only be a minor issue, but can lead to
  differences nonetheless */
  switch (*SLATE_pt_GetObjDynProperty(ObjNr))
  {
    case SLATE_OBJECT_PROPERTY_MOVING:
      pt_FIP_OA_Output->t_ObjList[ObjNr].t_Bool.bit_ObjWasMoving = 1u;
      break; 
    case SLATE_OBJECT_PROPERTY_STATIONARY:
      pt_FIP_OA_Output->t_ObjList[ObjNr].t_Bool.bit_ObjWasStationary = 1u;
      break; 
    case SLATE_OBJECT_PROPERTY_ONCOMING:
      pt_FIP_OA_Output->t_ObjList[ObjNr].t_Bool.bit_ObjWasOncoming = 1u;
      break; 
#if (FCT_CFG_SENSOR_TYPE_CAMERA)
    case SLATE_OBJECT_PROPERTY_STOPPED:
      pt_FIP_OA_Output->t_ObjList[ObjNr].t_Bool.bit_ObjWasStationary = 1u;
      break; 
#endif /* FCT_CFG_SENSOR_TYPE_CAMERA */
    default:
      /* default = do nothing */
      break; 
  }

}

/*************************************************************************************************************************
  Functionname:    FIP_v_ObjWasOncoming                                                                             */ /*!

  @brief           Determine if an stationary object was seen oncoming before.

  @description     Determine if an stationary object was seen oncoming before and set bit_StatObjWasOncoming in this case. 
                   As a consequence, these objects cannot be assigned to the ego lane in the lane association module.
                    - Increment oncoming counter in case of oncoming objects and if distance above a threshold
                    - Stopped objects that have not been seen moving may are not set to bit_StatObjWasOncoming 
                      if they are either below a given distance or were only seen oncoming for a short period of time
                    - First determine maximum X distance up to which object is considered as "bit_StatObjWasOncoming".
                      Set default maximum distance for oncoming stopped object.
                    - If stationary object was seen oncoming for SI_STATOBJ_ONCOMINGCOUNTER_MIN cycles and
                      is over a given distance (with hysteresis), then set bit_StatObjWasOncoming
                    - If stationary object is seen as oncoming is over given distance then set bit_StatObjWasOncoming, 
                      otherwise reset information
  
  @startuml 
    Partition FIP_v_ObjWasOncoming
    Start
  	Note right: This function determines if an stationary object was seen oncoming before	
  	If (Object is oncoming and its distance are above a threshold) then (True)
  	 	- Increment oncoming counter
  	Else (False)
  	Endif
  	 
  	If (Object has Stopped Dynamic Property) then (True)
  	- Set default maximum distance for oncoming stopped object inline
  		If(Oncoming counter greater than threshold) then (True)
  			If(Object State was oncoming) then (True)
  				- Distance for oncoming object max will be set \n as Maximum X distance for an oncoming object \n subtracted with hysteresis distance for an staionary object
  			Else (False)
  				- Distance for oncoming object max will be set \n as Maximum X distance for an oncoming object
  			Endif
  		Else (False)
  		Endif
  		If(Oncoming object distance is greater than maximum distance) then (True)
  			- Set Stationary Oncoming bit in FIP object list to TRUE
  		Else (False)
  			- Set Stationary Oncoming bit in FIP object list to FALSE
  		Endif
  	Else (False)
  	Endif
    Stop
  @enduml

  @return          -

  @param[in]       ObjNr : object number [0 ... EM_N_OBJECTS[

  @glob_in         *SLATE_pt_GetObjDynProperty(i) : Dynamic property of object i [SLATE_t_Obj_DynamicProperty as defined in rte_type.h]
                   with i in [0 ... EM_N_OBJECTS[ and EM_N_OBJECTS as in Rte_SWCEmAdapt_Type.h
  @glob_in         OBJ_LONG_DISPLACEMENT(i) : OBJ_LONG_DISPLACEMENT(i) : Longitudinal displacement of an object i [-5*RW_FCT_MAX ... 5*RW_FCT_MAX] m with i in [0 ... FIP_STATIC_TRACE_NO_OF_TRACES[
                   with i in [0 ... EM_N_OBJECTS[ and EM_N_OBJECTS as in Rte_SWCEmAdapt_Type.h
  @glob_in         pt_FIP_OA_Output->t_ObjList[i].b_ObjIsMovingToStationary : Info if object i is moving to stationary [TRUE, FALSE]
                   with i in [0 ... EM_N_OBJECTS[ and EM_N_OBJECTS as in Rte_SWCEmAdapt_Type.h
  @glob_out        t_FIP_ObjectList[i].t_Bool : Reference to bit field for object i with i in [0 ... EM_N_OBJECTS[
                   with i in [0 ... EM_N_OBJECTS[ and EM_N_OBJECTS as in Rte_SWCEmAdapt_Type.h
                                                Moving : Info if object was moving once [TRUE, FALSE]
                                                Oncoming : Info if object was oncoming once [TRUE, FALSE]
                                                StatObjWasOncoming.uiOncomingCounter : No. of cycles which an object was seen oncoming [full range uint8]
  @glob_out        pt_FIP_OA_Output->t_ObjList[i].t_Bool.bit_StatObjWasOncoming: Boolean if stationary object was treated as oncoming [TRUE, FALSE]
                   with i in [0 ... EM_N_OBJECTS[ and EM_N_OBJECTS as in Rte_SWCEmAdapt_Type.h

  @c_switch_part   -
  @c_switch_full   FCT_CFG_INPUT_PREPROCESSSING : FCT support for FCT Input Preprocessing (FIP)

  @pre             -
  @post            -

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @created         21.11.2016
  @changed         21.11.2016
*************************************************************************************************************************/
static void FIP_v_ObjWasOncoming(const ObjNumber_t ObjNr)
{
  boolean b_ObjIsMovingToStationary = pt_FIP_OA_Input->b_ObjIsMovingToStationary(ObjNr);
  ubit8_t bit_ObjWasMoving = pt_FIP_OA_Output->t_ObjList[ObjNr].t_Bool.bit_ObjWasMoving;
  ubit8_t bit_ObjWasOncoming = pt_FIP_OA_Output->t_ObjList[ObjNr].t_Bool.bit_ObjWasOncoming;
  uint8 u_OnComingCounter = pt_FIP_OA_Output->t_ObjList[ObjNr].StatObjWasOncoming.uiOncomingCounter;
  const float32 f_ObjLongDisplacement = * pt_FIP_RTE_Input->pf_ObjLongDisp(ObjNr);
  SLATE_t_Obj_DynamicProperty t_ObjDynProperty = *SLATE_pt_GetObjDynProperty(ObjNr);

  /* Increment oncoming counter in case of oncoming objects and if distance above a threshold */
  if( (t_ObjDynProperty == SLATE_OBJECT_PROPERTY_ONCOMING) && 
    ( u_OnComingCounter < SI_STATOBJ_ONCOMINGCOUNTER_MAX) && 
      (f_ObjLongDisplacement > FIP_PAR_ONCOMMING_KEEP_RELEV_DISTX_MAX) 
    )
  {
    pt_FIP_OA_Output->t_ObjList[ObjNr].StatObjWasOncoming.uiOncomingCounter ++;
  }

  /* Stopped objects that have not been seen moving may only become
    ego lane if they are either below a given distance or were only
    seen oncoming for a short period of time */
  if ( 
#if (FCT_CFG_SENSOR_TYPE_RADAR)
    (t_ObjDynProperty == SLATE_OBJECT_PROPERTY_STATIONARY) && 
    (b_ObjIsMovingToStationary) &&
#else /* !FCT_CFG_SENSOR_TYPE_RADAR */
    (b_ObjIsMovingToStationary) &&
#endif /* !FCT_CFG_SENSOR_TYPE_RADAR */
    (bit_ObjWasMoving == 0u) && 
    (bit_ObjWasOncoming != 0u)
    )
  {
    /* First determine maximum X distance up to which object can become in-lane.
    Set default maximum distance for oncoming stopped object inlane. */
    float32 fMaxDistX = SI_PAR_STOPPED_ONCOMING_INLANE_DISTX_MAX;

    /* If stationary object was seen oncoming for SI_STATOBJ_ONCOMINGCOUNTER_MIN cycles and
    is over a given distance (with hysteresis), then do not allow the object to become in-lane */
    if (pt_FIP_OA_Output->t_ObjList[ObjNr].StatObjWasOncoming.uiOncomingCounter > SI_STATOBJ_ONCOMINGCOUNTER_MIN)
    {
      if (pt_FIP_OA_Output->t_ObjList[ObjNr].t_Bool.bit_StatObjWasOncoming)
      {
        fMaxDistX = (FIP_PAR_ONCOMMING_KEEP_RELEV_DISTX_MAX - SI_STATOBJ_ONCOMING_XDIST_HYSTERESIS);
      }
      else
      {
        fMaxDistX = FIP_PAR_ONCOMMING_KEEP_RELEV_DISTX_MAX;
      }
    }
    /* If stopped object only seen as oncoming is over given distance then do
    not allow it to go into ego-lane */
    if (f_ObjLongDisplacement > fMaxDistX)
    {
      pt_FIP_OA_Output->t_ObjList[ObjNr].t_Bool.bit_StatObjWasOncoming = TRUE;
    }
    else
    {
      pt_FIP_OA_Output->t_ObjList[ObjNr].t_Bool.bit_StatObjWasOncoming = FALSE;
    }
  }
}


/*************************************************************************************************************************
  Functionname:    FIP_v_ObjAttr_DeleteObject                                                                         */ /*!

  @brief           Initialize FIP object attributes in FIP attribute output structure

  @description     Initialize FIP object attributes in FIP attribute output structure
   
  @startuml 
    Partition FIP_v_OA_DeleteObject
    Start
  	  Note right: This function initializes FIP object attributes in FIP attribute output structure	
  	  - Initialize FIP object attributes
    Stop
  @enduml

  @return          -

  @param[in]       t_ObjNr : Object number [0 ... EM_N_OBJECTS[

  @glob_in         -
  @glob_out        t_FIP_ObjAttr_Output.t_ObjList[i].t_Bool.bit_StatObjWasOncoming : Bit indicating if stationary object i was seen omcoming [TRUE, FALSE] 
                   with i in [0 ... EM_N_OBJECTS[ and EM_N_OBJECTS as in Rte_SWCEmAdapt_Type.h

  @c_switch_part   -
  @c_switch_full   FCT_CFG_INPUT_PREPROCESSSING : FCT support for FCT Input Preprocessing (FIP)

  @pre             -
  @post            -

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @created         06.10.2016
  @changed         06.10.2016

  @author          Marie-Theres Boll | marie-theres.boll@continental-corporation.com | +49 (8382) 9699-632
*************************************************************************************************************************/
void FIP_v_OA_DeleteObject(const ObjNumber_t t_ObjNr)
{
  pt_FIP_OA_Output->t_ObjList[t_ObjNr].t_Bool.bit_StatObjWasOncoming        = 0u;
  pt_FIP_OA_Output->t_ObjList[t_ObjNr].t_Bool.bit_ObjWasMoving              = 0u;
  pt_FIP_OA_Output->t_ObjList[t_ObjNr].t_Bool.bit_ObjWasOncoming            = 0u;
  pt_FIP_OA_Output->t_ObjList[t_ObjNr].t_Bool.bit_ObjWasStationary          = 0u;

  pt_FIP_OA_Output->t_ObjList[t_ObjNr].fAbsVelocity                         = 0.f;
  pt_FIP_OA_Output->t_ObjList[t_ObjNr].fAbsAcceleration                     = 0.f;
  pt_FIP_OA_Output->t_ObjList[t_ObjNr].StatObjWasOncoming.uiOncomingCounter = (uint8)0;
#if (FCT_CFG_CAMERA_CUTIN_POTENTIAL || FCT_CFG_CAMERA_CUTOUT_POTENTIAL)
  pt_FIP_OA_Output->t_ObjList[t_ObjNr].f_CamOverlapDst = 0.f;
  pt_FIP_OA_Output->t_ObjList[t_ObjNr].f_CamObjWidth = 0.f;
  pt_FIP_OA_Output->t_ObjList[t_ObjNr].f_Cam_overlap_diff_left_and_right = 0.f;
  pt_FIP_OA_Output->t_ObjList[t_ObjNr].u_Cam_overlap_compensation_cnt = 0U;
#endif

}


/*************************************************************************************************************************
  Functionname:    FIP_f_SetObjWidthForCorridor                                                            */ /*!

  @brief           Set width of object for corridor calculations

  @description     Set width of object for corridor calculations. Object width should be derived from measured values of Object Tracking, 
                   if available. Currently derived from Object Class.
  
  @startuml 
    Partition FIP_f_SetObjWidthForCorridor
    Start
  	Note right: This function computes width of object based on classification	
  	If (Object class is Car) then (True)
  		If (Object is stationary) then (True)
  			-  Object width is set to \n Object Width (from Shape Point) \n if it is in between 1.8m and 3m
  		Else (False)
  			- Object Width will be set \n with width of car moving (1.8m)
  		endif
  	Else (False)
  	if(Object class is truck) then (True)
  		- Object Width for Corridor \n will be set with \n Truck Object width (2.5m)
  	Else (False)
  	if(Object Class is Point OR Motorcycle OR Pedestrian) then (True)
  		- Object Width for Corridor \n will be set with \n Small Object width (0.8m)
  	Else (False)
  		If (Object property is Staionary) Then (True)
  			- Object width is set to \n Object Width (from Shape Point) \n if it is in between 1.8m and 3m
  		Else (False)
  			- Object Width for Corridor \n will be set with \n Object width moving (2m)
  		Endif
  	Endif
  	Endif
  	Endif
  
  	If (Object longitudinal distance greater than threshold (110m)) then (True)
  		- Object Width for Corridor \n will be set with \n Maximum of 1.8m and \n above updated Object Width
  	Else (Flase)
  	Endif
  
  	If (Object property is Staionary) then (True)
  		- Limit and Set Object width to \n Object Width (values set above) \n if it is in between 0.8m and 2m
  	Else (False)
  	endif
    Stop
  @enduml

  @return          fObjectWidth : Width of the object iObj to use in corridor [0.f ... 10.f]

  @param[in]       iObj : internal object number (Object ID) of a valid object [0 ... EM_N_OBJECTS[
                           with EM_N_OBJECTS as in Rte_SWCEmAdapt_Type.h
  @param[out]      -

  @glob_in         *SLATE_pt_GetObjClassification(i) : object class of object i [EM_t_GenObjClassification as in Rte_Type.h]
                            with i in [0 ... EM_N_OBJECTS[ and EM_N_OBJECTS as in Rte_SWCEmAdapt_Type.h
  @glob_in         *SLATE_pt_GetObjDynProperty(i) : Dynamic property of object i [SLATE_t_Obj_DynamicProperty as defined in rte_type.h]
                            with i in [0 ... EM_N_OBJECTS[ and EM_N_OBJECTS as in Rte_SWCEmAdapt_Type.h
  @glob_in         pt_FIP_OA_Output->t_ObjList[ObjNr].b_ObjIsMovingToStationary(i) : Info if object i is moving to stationary [TRUE, FALSE]
                            with i in [0 ... EM_N_OBJECTS[ and EM_N_OBJECTS as in Rte_SWCEmAdapt_Type.h
  @glob_in         OT_GET_OBJ_WIDTH(i) : width of object i [0.f ... 10.f]
                            with i in [0 ... EM_N_OBJECTS[ and EM_N_OBJECTS as in Rte_SWCEmAdapt_Type.h

  @glob_out        pt_FIP_OA_Output->t_ObjList[t_ObjNr].f_ObjectWidthCorridor : object width for corridor calculations [0.f   10.f]

  @c_switch_part   -
  @c_switch_full   FCT_CFG_SLATE_ACC_OBJECT_SELECTION : FCT support for ACC object selection

  @pre             EM object list data filled (dynamic property, moving to stationary, object class)
  @post            -

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @created         -
  @changed         -

  @author          Norman Apel | norman.apel@continental-corporation.com | +49 (8382) 9699-365
*************************************************************************************************************************/
static void FIP_v_SetObjWidthForCorridor(const ObjNumber_t iObj)
{
  const SLATE_t_Obj_CLassification eObjClass = *SLATE_pt_GetObjClassification(iObj);
  boolean b_ObjIsMovingToStationary = pt_FIP_OA_Input->b_ObjIsMovingToStationary(iObj);
  SLATE_t_Obj_DynamicProperty t_ObjDynProperty = *SLATE_pt_GetObjDynProperty(iObj);
  float32 f_ObjLongDisp = *pt_FIP_RTE_Input->pf_ObjLongDisp(iObj);
#if (FCT_USE_EM_ARS_TECH_OBJECT_LIST)
  float32 f_Width = pt_FIP_OA_Output->t_ObjList[iObj].fWidth;
#endif
  if (eObjClass == SLATE_OBJCLASS_CAR)
  {
    if (  (t_ObjDynProperty == SLATE_OBJECT_PROPERTY_STATIONARY)
       && (b_ObjIsMovingToStationary == FALSE) 
       )
    {
#if (FCT_USE_EM_ARS_TECH_OBJECT_LIST)
      /*! stationary (not stopped) objects get a variable width */
      pt_FIP_OA_Output->t_ObjList[iObj].f_ObjectWidthCorridor = MINMAX_FLOAT(FIP_MIN_OBJ_WIDTH_CAR_STAT, FIP_MAX_OBJ_WIDTH_CAR_STAT,f_Width);
#else
      /*! stationary (not stopped) objects get a variable width, in VACC just take the average of min-max allowed for a particular case */
      pt_FIP_OA_Output->t_ObjList[iObj].f_ObjectWidthCorridor = (FIP_MIN_OBJ_WIDTH_CAR_STAT + FIP_MAX_OBJ_WIDTH_CAR_STAT) * 0.5F;
#endif /* END IF (FCT_USE_EM_ARS_TECH_OBJECT_LIST) */
    }
    else
    {
      /*! moving/stopped object seems to be a car, so calculate an object width of 1.8m */
      pt_FIP_OA_Output->t_ObjList[iObj].f_ObjectWidthCorridor = FIP_OBJ_WIDTH_CAR_MOVE;
    }
  }
  else if (eObjClass == SLATE_OBJCLASS_TRUCK)
  {
    /*! object seems to be a truck, so calculate an object width of 2.5 */
    pt_FIP_OA_Output->t_ObjList[iObj].f_ObjectWidthCorridor = FIP_OBJ_WIDTH_TRUCK; 
  }
  else if (   (eObjClass == SLATE_OBJCLASS_POINT)
    || (eObjClass == SLATE_OBJCLASS_MOTORCYCLE )
    || (eObjClass == SLATE_OBJCLASS_PEDESTRIAN)
    || (eObjClass == SLATE_OBJCLASS_BICYCLE )
    )
  {
    pt_FIP_OA_Output->t_ObjList[iObj].f_ObjectWidthCorridor = FIP_OBJ_WIDTH_SMALL_OBJ;
  }
  else
  {
    if( (t_ObjDynProperty == SLATE_OBJECT_PROPERTY_STATIONARY)
#if (FCT_CFG_SENSOR_TYPE_CAMERA)
      || (t_ObjDynProperty == SLATE_OBJECT_PROPERTY_STOPPED)
#endif /* FCT_CFG_SENSOR_TYPE_CAMERA */
      )
    {
#if (FCT_USE_EM_ARS_TECH_OBJECT_LIST)
      /*! stationary (not stopped) objects get a variable width */
      pt_FIP_OA_Output->t_ObjList[iObj].f_ObjectWidthCorridor = MINMAX_FLOAT(FIP_MIN_OBJ_WIDTH_OTHER_CLASS_STAT, FIP_MAX_OBJ_WIDTH_OTHER_CLASS_STAT, f_Width);
#else
      /*! stationary (not stopped) objects get a variable width, in VACC just take the average of min-max allowed for a particular case */
      pt_FIP_OA_Output->t_ObjList[iObj].f_ObjectWidthCorridor = (FIP_MIN_OBJ_WIDTH_OTHER_CLASS_STAT + FIP_MAX_OBJ_WIDTH_OTHER_CLASS_STAT) * 0.5F;
#endif  /* END IF (FCT_USE_EM_ARS_TECH_OBJECT_LIST) */
    }
    else
    {
      /*    ARS_OBJCLASS_UNCLASSIFIED = 7U,
            ARS_OBJCLASS_WIDE         = 6U */

      pt_FIP_OA_Output->t_ObjList[iObj].f_ObjectWidthCorridor = FIP_OBJ_WIDTH_MOVE;

    }
  }

  if (f_ObjLongDisp > FIP_ACC_MIN_DIST_OBJ_WIDTH_DIST_ADAPTED)
  {
    pt_FIP_OA_Output->t_ObjList[iObj].f_ObjectWidthCorridor = MAX_FLOAT(FIP_ACC_MIN_OBJ_WIDTH_FAR_DIST, pt_FIP_OA_Output->t_ObjList[iObj].f_ObjectWidthCorridor);
  }

  /* Limit the Width of the stationary Objects that is used to calculate the Overlaps */
  if( (t_ObjDynProperty == SLATE_OBJECT_PROPERTY_STATIONARY)
    &&(!b_ObjIsMovingToStationary))
  {
    pt_FIP_OA_Output->t_ObjList[iObj].f_ObjectWidthCorridor = MINMAX_FLOAT(FIP_MIN_OBJ_WIDTH_STAT, FIP_MAX_OBJ_WIDTH_STAT, pt_FIP_OA_Output->t_ObjList[iObj].f_ObjectWidthCorridor);
  }
}

#if (FCT_CFG_CAMERA_OBJECT_DETECTION)
/*************************************************************************************************************************
  Functionname:    FIP_v_InitCameraObjData                                                           */ /*!

  @brief           Init Function

  @description     Initialization of FIP camera object data and camera object External ID.

  @startuml 
    Partition FIP_v_InitCameraObjData
    Start
  	  Note right: This function initializes FIP camera object attributes	
  	- Initialization of FIP camera object Confirmation \n Probability, Assigned Lane Quality Left/Right \n and camera object External ID with zero 
    	- Initialization of FIP camera object \n Associated Lane, Brake Light, Object Maneuver \n and Turn Lights State to Unknown
    Stop
  @enduml

  @return          -

  @param[in]       -

  @glob_in         -
  @glob_out        pt_FIP_OA_Output->t_ObjList[ObjNr].t_CamObjectData : Camera object data.

  @glob_out        pt_FIP_OA_Output->t_ObjList[ObjNr].u_ExternalID_Cam : Camera object External ID.

  @c_switch_part   OUT_CFG_CUSTOM_OBJ_WIDTH_OUTPUT : Internal configuration switch enabling custom object width output.
  @c_switch_part   OUT_CFG_USE_ME_CLASS_DIRECTLY : Internal configuration switch to directly access ME input structure to 
           output ME object class based wide object output.
  @c_switch_full   FCT_CFG_CAMERA_OBJECT_DETECTION : FCT camera object detection inputs.

  @pre             -
  @post            -

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @created         15.02.2017
  @changed         15.02.2017

  @author          Ajay Talakadu | Ajay.Talakadu@continental-corporation.com | +91 (80) 6679-1170
*************************************************************************************************************************/
static void FIP_v_InitCameraObjData(const ObjNumber_t ObjNr)
{

    pt_FIP_OA_Output->t_ObjList[ObjNr].u_ExternalID_Cam = 0u;
    pt_FIP_OA_Output->t_ObjList[ObjNr].t_CamObjectData.t_CamConfirmationProb = 0u;
    pt_FIP_OA_Output->t_ObjList[ObjNr].t_CamObjectData.t_AssignedLaneQual = 0u;
    pt_FIP_OA_Output->t_ObjList[ObjNr].t_CamObjectData.t_AssLaneLeftQual = 0u;
    pt_FIP_OA_Output->t_ObjList[ObjNr].t_CamObjectData.t_AssLaneRightQual = 0u;
    pt_FIP_OA_Output->t_ObjList[ObjNr].t_CamObjectData.t_BrakeLightConf = 0u;
    pt_FIP_OA_Output->t_ObjList[ObjNr].t_CamObjectData.t_TurnLightsStateConf = 0u;
    pt_FIP_OA_Output->t_ObjList[ObjNr].t_CamObjectData.t_AssociatedLaneConf = 0u;
    pt_FIP_OA_Output->t_ObjList[ObjNr].t_CamObjectData.eAssociatedLane = FIP_CAM_ASSOC_LANE_UNKNOWN;
    pt_FIP_OA_Output->t_ObjList[ObjNr].t_CamObjectData.eBrakeLight =FIP_CAM_BRAKE_LIGHT_UNKNOWN;
    pt_FIP_OA_Output->t_ObjList[ObjNr].t_CamObjectData.eObjManeuver = FIP_CAM_OM_NONE;
    pt_FIP_OA_Output->t_ObjList[ObjNr].t_CamObjectData.eTurnLightsState = FIP_CAM_TURN_LIGHT_UNKNOWN;
}
#endif /* END IF (FCT_CFG_CAMERA_OBJECT_DETECTION) */

/*************************************************************************************************************************
  Functionname:    FIP_v_CalculateObjLengthandWidth                                                                 */ /*!

  @brief           Calculation of Object Length and Width

  @description     Calculation of Object Length and Width by using shape coordinates

  @return          static void

  @param[in]       ObjNr : object number [0 ... EM_N_OBJECTS-1]

  @glob_in         OBJ_GEOMETRY(ObjNr) : Give  Geometry of object ie shape coordinates  and it's state.
                        OBJ_GEOMETRY(ObjNr).aShapePointStates      : State of shape point as defined in Rte_Type.h
                        OBJ_GEOMETRY(ObjNr).aShapePointCoordinates : Coordinates of the object  
  @glob_in         GET_EM_GEN_OBJ(ObjNr).Attributes.eClassification :This signal indicates the class of the object as defined in  Rte_type.h
  @glob_out        pt_FIP_OA_Output->t_ObjList[ObjNr].fLength : Length of the Object (Full Range of float )
  @glob_out        pt_FIP_OA_Output->t_ObjList[ObjNr].fWidth  : Width of the Object  (Full Range of float )

  @c_switch_part   FIP_SHAPEPOINT_STATE_AVAILABLE : Enable this CS if shapepoint states are available 
  @c_switch_full   FCT_CFG_INPUT_PREPROCESSSING   :  FCT support for FCT Input Preprocessing (FIP): Need to be switched on for ACC

  @pre             -
  @post            -

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @created         4/10/2017
  @changed         4/10/2017

  @author          Bibin Mathew | bibin.mathew@continental-corporation.com | +91 (80) 6679-6524
*************************************************************************************************************************/
static void FIP_v_CalculateObjLengthandWidth(const ObjNumber_t ObjNr)
{
  float32 fPosX1, fPosX2, fPosY1, fPosY2;
  float32 fDist1, fDist2, fDist3, fDist4, fLength = 0.f, fWidth = 0.f;

  float32 fMinWidth = 0.f;
  float32 fMaxWidth = 0.f;
  float32 fMinLength = 0.f;
  float32 fMaxLength = 0.f;
  boolean b_ObjIsDeleted = SLATE_b_GetObjIsDeleted(ObjNr);

#ifdef   FIP_SHAPEPOINT_STATE_AVAILABLE 
  uint8 uiPointCounter;           /*generic running variable for points*/
  uint8 uiValidShapePoints = 0;   /*number of existing shape points*/
  EM_t_GenObjShapePointCoord 	ShapeCoordArray_t[4];
#endif

  if (!b_ObjIsDeleted)
  {
    /* set pointer to the EM-Generic objects */
    const EM_t_GenObjGeometry* p_GenObjDataGeometry = SLATE_p_GetEMGenObjGeometry(ObjNr);

#ifdef FIP_SHAPEPOINT_STATE_AVAILABLE

    uiValidShapePoints = 0;

    /*check shape point status */
    for (uiPointCounter=0; uiPointCounter < 4u; uiPointCounter++)
    {                
      if(p_GenObjDataGeometry.aShapePointStates[uiPointCounter] != EM_GEN_OBJECT_SHAPE_POINT_STATE_INVALID)
      {   
        /*Assigning XY coordinates to local array*/
        ShapeCoordArray_t[uiValidShapePoints].fPosX = p_GenObjDataGeometry.aShapePointCoordinates[uiPointCounter].fPosX ;
        ShapeCoordArray_t[uiValidShapePoints].fPosY = p_GenObjDataGeometry.aShapePointCoordinates[uiPointCounter].fPosY ;
        uiValidShapePoints++;
      }
    }

    switch (uiValidShapePoints)
    {
      case 2u:

        fLength = fABS(ShapeCoordArray_t[1].fPosX - ShapeCoordArray_t[0].fPosX); 
        fWidth  = fABS(ShapeCoordArray_t[1].fPosY - ShapeCoordArray_t[0].fPosY); 
        break;

      case 3u:
        /*In this case after calculating distances between coordinates larger distance is not considred as it will be always diagonal */

        fPosX2 = ShapeCoordArray_t[1].fPosX ;
        fPosX1 = ShapeCoordArray_t[0].fPosX ;
        fPosY2 = ShapeCoordArray_t[1].fPosY ;
        fPosY1 = ShapeCoordArray_t[0].fPosY ;
        
         /*Distance formule to calculate distance between coordinates */
        fDist1 = SQRT( SQR(fPosX2-fPosX1) + SQR(fPosY2-fPosY1));
        
        fPosX2 = ShapeCoordArray_t[2].fPosX ;
        fPosX1 = ShapeCoordArray_t[1].fPosX ;
        fPosY2 = ShapeCoordArray_t[2].fPosY ;
        fPosY1 = ShapeCoordArray_t[1].fPosY ;
        
         /*Distance formule to calculate distance between coordinates */
        fDist2 = SQRT( SQR(fPosX2-fPosX1) + SQR(fPosY2-fPosY1));
        
        fPosX2 = ShapeCoordArray_t[2].fPosX ;
        fPosX1 = ShapeCoordArray_t[0].fPosX ;
        fPosY2 = ShapeCoordArray_t[2].fPosY ;
        fPosY1 = ShapeCoordArray_t[0].fPosY ;

        /*Distance formule to calculate distance between coordinates */
        fDist3 = SQRT( SQR(fPosX2-fPosX1) + SQR(fPosY2-fPosY1));

        /*Width will be the minimum comparing to Length and Diagonal*/
        fWidth = MIN(fDist3, MIN(fDist1, fDist2));
        
        if(fWidth == fDist1)
        {
          fLength = MIN(fDist2,fDist3) ;
        }
        else if( fWidth == fDist2)
        {
          fLength = MIN(fDist1,fDist3) ;
        }
        else
        {
          fLength = MIN(fDist1,fDist2) ;
        }
        
        break;

      case 4u:
#endif

        fPosX2 = p_GenObjDataGeometry->aShapePointCoordinates[1].fPosX ;
        fPosX1 = p_GenObjDataGeometry->aShapePointCoordinates[0].fPosX ;
        fPosY2 = p_GenObjDataGeometry->aShapePointCoordinates[1].fPosY ;
        fPosY1 = p_GenObjDataGeometry->aShapePointCoordinates[0].fPosY ;
        
         /*Distance formule to calculate distance between coordinates */
        fDist1 = SQRT( SQR(fPosX2-fPosX1) + SQR(fPosY2-fPosY1));
        
        fPosX2 = p_GenObjDataGeometry->aShapePointCoordinates[2].fPosX ;
        fPosX1 = p_GenObjDataGeometry->aShapePointCoordinates[1].fPosX ;
        fPosY2 = p_GenObjDataGeometry->aShapePointCoordinates[2].fPosY ;
        fPosY1 = p_GenObjDataGeometry->aShapePointCoordinates[1].fPosY ;
        
        /*Distance formule to calculate distance between coordinates */
        fDist2 = SQRT( SQR(fPosX2-fPosX1) + SQR(fPosY2-fPosY1));
        
        fPosX2 = p_GenObjDataGeometry->aShapePointCoordinates[3].fPosX ;
        fPosX1 = p_GenObjDataGeometry->aShapePointCoordinates[2].fPosX ;
        fPosY2 = p_GenObjDataGeometry->aShapePointCoordinates[3].fPosY ;
        fPosY1 = p_GenObjDataGeometry->aShapePointCoordinates[2].fPosY ;
        
        /*Distance formule to calculate distance between coordinates */
        fDist3 = SQRT( SQR(fPosX2-fPosX1) + SQR(fPosY2-fPosY1));
        
        fPosX2 = p_GenObjDataGeometry->aShapePointCoordinates[3].fPosX ;
        fPosX1 = p_GenObjDataGeometry->aShapePointCoordinates[0].fPosX ;
        fPosY2 = p_GenObjDataGeometry->aShapePointCoordinates[3].fPosY ;
        fPosY1 = p_GenObjDataGeometry->aShapePointCoordinates[0].fPosY ;
        
        /*Distance formule to calculate distance between coordinates */
        fDist4 = SQRT( SQR(fPosX2-fPosX1) + SQR(fPosY2-fPosY1));
        
        /*Averaging the distances*/
        fDist1 = (fDist1 + fDist3)/2.f;
        fDist2 = (fDist2 + fDist4)/2.f;
        
        if( fDist1 > fDist2 )
        {
          fLength = fDist1;
          fWidth  = fDist2;
        }
        else
        {
          fLength = fDist2;
          fWidth  = fDist1;
        }
#ifdef FIP_SHAPEPOINT_STATE_AVAILABLE  
        break;
      default:
        fLength = 0;
        fWidth  = 0;
        break;

      }
#endif
      /* check sanity of dimensions based on object classification */
      switch (SLATE_p_GetEMGenObj(ObjNr)->Attributes.eClassification)
      {
        /*! @todo define default length and width for object classes */
        /*! @todo concept to handle standard deviations in default dimension case */
        case (EM_t_GenObjClassification)(EM_GEN_OBJECT_CLASS_POINT):
          fMinWidth   = FIP_CLASS_POINT_MIN_DIMENSION;
          fMaxWidth   = FIP_CLASS_POINT_MAX_DIMENSION;
          fMinLength  = FIP_CLASS_POINT_MIN_DIMENSION;
          fMaxLength  = FIP_CLASS_POINT_MAX_DIMENSION;
          break;

        case (EM_t_GenObjClassification)(EM_GEN_OBJECT_CLASS_CAR):
          fMinWidth   = FIP_CLASS_CAR_MIN_WIDTH;
          fMaxWidth   = FIP_CLASS_CAR_MAX_WIDTH;        
          fMinLength  = FIP_CLASS_CAR_MIN_LENGTH;
          fMaxLength  = FIP_CLASS_CAR_MAX_LENGTH;
          break;

        case (EM_t_GenObjClassification)(EM_GEN_OBJECT_CLASS_TRUCK):
          fMinWidth   = FIP_CLASS_TRUCK_MIN_WIDTH;
          fMaxWidth   = FIP_CLASS_TRUCK_MAX_WIDTH;        
          fMinLength  = FIP_CLASS_TRUCK_MIN_LENGTH;
          fMaxLength  = FIP_CLASS_TRUCK_MAX_LENGTH;
          break;

        case (EM_t_GenObjClassification)(EM_GEN_OBJECT_CLASS_PEDESTRIAN):
          fMinWidth   = FIP_CLASS_PED_MIN_DIMENSION;
          fMaxWidth   = FIP_CLASS_PED_MAX_DIMENSION;        
          fMinLength  = FIP_CLASS_PED_MIN_DIMENSION;
          fMaxLength  = FIP_CLASS_PED_MAX_DIMENSION;
          break;

        case (EM_t_GenObjClassification)(EM_GEN_OBJECT_CLASS_MOTORCYCLE):
          fMinWidth   = FIP_CLASS_MOTORCYCLE_MIN_WIDTH;
          fMaxWidth   = FIP_CLASS_MOTORCYCLE_MAX_WIDTH;    
          fMinLength  = FIP_CLASS_MOTORCYCLE_MIN_LENGTH;
          fMaxLength  = FIP_CLASS_MOTORCYCLE_MAX_LENGTH;
          break;

        case (EM_t_GenObjClassification)(EM_GEN_OBJECT_CLASS_BICYCLE):
          fMinWidth   = FIP_CLASS_BICICLE_MIN_WIDTH;
          fMaxWidth   = FIP_CLASS_BICICLE_MAX_WIDTH;      
          fMinLength  = FIP_CLASS_BICICLE_MIN_LENGTH;
          fMaxLength  = FIP_CLASS_BICICLE_MAX_LENGTH;
          break;

        case (EM_t_GenObjClassification)(EM_GEN_OBJECT_CLASS_WIDE):
        case (EM_t_GenObjClassification)(EM_GEN_OBJECT_CLASS_UNCLASSIFIED):
        default:
          fMinWidth   = FIP_CLASS_UNCLASSIFIED_MIN_DIMENSION;
          fMaxWidth   = FIP_CLASS_UNCLASSIFIED_MAX_DIMENSION;
          fMinLength  = FIP_CLASS_UNCLASSIFIED_MIN_DIMENSION;
          fMaxLength  = FIP_CLASS_UNCLASSIFIED_MAX_DIMENSION;
          break;
      }

      /* check for dimension boundaries */
      if (fWidth > fMaxWidth)
      {
        fWidth = fMaxWidth;
      }
      if (fWidth < fMinWidth)
      {
        fWidth = fMinWidth;
      }
      if (fLength > fMaxLength)
      {
        fLength = fMaxLength;
      }
      if (fLength < fMinLength)
      {
        fLength = fMinLength;
      }

      /*Assigning calculated Length and Width to output Structures*/
      pt_FIP_OA_Output->t_ObjList[ObjNr].fLength = fLength;
      pt_FIP_OA_Output->t_ObjList[ObjNr].fWidth = fWidth;
#if (FCT_CFG_SIGNAL_PERF_MONITORING)
      pSLATE_SPM_Data->t_ObjList[ObjNr].fWidth = fWidth;
#endif
  }
}
///@}
#endif /* (FCT_CFG_INPUT_PREPROCESSSING) */

/* ************************************************************************* */
/*   Copyright ADC-GmbH, Lindau                                              */
/* ************************************************************************* */

