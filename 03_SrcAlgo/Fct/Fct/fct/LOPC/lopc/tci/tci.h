/*! \file **********************************************************************

COMPANY:                   COPYRIGHT (C) Continental AG

PROJECT:                   Adaptive Cruise Control (ACC)

CPU:                       CPU-Independent

COMPONENT:                 ACC_TCI (Traffic Continuation Indication)

PACKAGENAME:               tci.h

DESCRIPTION:               Internal header file for Traffic Continuation Indication function

AUTHOR:                    Boll Marie-Theres (uidu1091)

CREATION DATE:             12.02.2018

VERSION:                   $Revision: 1.17 $

LEGACY VERSION:            Revision: 1.0

**************************************************************************** */

#ifndef _TCI_H_INCLUDED
#define _TCI_H_INCLUDED

/*****************************************************************************
  MODULE DESCRIPTION
*****************************************************************************/

/** 
@defgroup   tci_h Tci_h
@ingroup    tci
@brief      Internal header file for Traffic Continuation Indication function
@{ */ 

/*****************************************************************************
  INCLUDES
*****************************************************************************/

#include "frame_lopc.h"
#include "tci_cfg.h"

#if (FCT_CFG_TCI==SWITCH_ON)

#include "tci_custom.h"
#if TCI_CFG_AUTOCODE
#include "tci_autocode.h"
#endif

#ifdef __cplusplus
extern "C" {
#endif

/*****************************************************************************
  SYMOBLIC CONSTANTS (COMPONENT INTERNAL SCOPE)
*****************************************************************************/


/*****************************************************************************
  MACROS (COMPONENT INTERNAL SCOPE)
*****************************************************************************/
#if (TCI_CFG_AUTOCODE == SWITCH_OFF) 
#define TCI_OBJ_NEXT_LONG          (0u)
#define TCI_OBJ_HIDDENNEXT_LONG    (1u)
#define TCI_OBJ_NEXTLEFT           (2u)
#define TCI_OBJ_NEXTRIGHT          (3u)
#define TCI_OBJ_HIDDENNEXTLEFT     (4u)
#define TCI_OBJ_HIDDENNEXTRIGHT    (5u)

#define TCI_EGOCURVE              (0.1f)
#define TCI_INITDISTANCE          (0.0f)
#define TCI_INITVELOCITY          (0.0f)
#define TCI_ALLDOORSCLOSED        (0u)
#define TCI_MAXSTOPPEDTARGETDIST  (7.0f)
#define TCI_MINSTOPPEDTARGETTIME  (1.0f)
#define TCI_MINSTOPPEDEGOTIME     (3.0f)
#define TCI_MINSTOPPEDTARGETRESETDRIVENDISTTIME  (5.0f)
#define TCI_MAXTARGETTCIDIST      (15.0f)
#define TCI_FIXIDISTTHRESHOLD     (11.0f)
#define TCI_INDICATIONREPEATTIME  (3.5f)
#define TCI_MINVISUALNOTIFICATIONTIME (0.5f)
#define TCI_FIXEDRIVEOFFDISTANCE  (2.0f)
#define TCI_MINABSVELOCITYOOI0    (0.6f)

#ifdef FCT_SIMU
#define FCT_MEAS_ID_TCI_SIM (540002944U)
#endif
#endif
/*****************************************************************************
  TYPEDEFS (COMPONENT INTERNAL SCOPE)
*****************************************************************************/
 #if (TCI_CFG_AUTOCODE == SWITCH_OFF) 
typedef enum {
  INACTIVE,                    
  STOPPEDSUBJECTANDTARGET,           
  DRIVEOFFTARGET,          
  STOPPEDTARGET,           
  INDICATION               
} TCIState_t_e;


typedef enum {
DRIVEOFFDISTANCECANINPUT,
DRIVEOFFFIXED
} TCIMode_t_e;



#endif


/*****************************************************************************
  CONSTANTS (COMPONENT INTERNAL SCOPE)
*****************************************************************************/


/*****************************************************************************
  VARIABLES (COMPONENT INTERNAL SCOPE)
*****************************************************************************/

#if (TCI_CFG_AUTOCODE == SWITCH_OFF)
/*typedef enum // to be used in case of simulation of ARS510TA19 data
{
  SEATBELT_DRIVER_CLOSED=1 ,
}TCI_t_SeatBelt;*/

typedef enum
{
  NOTIFICATIONTYPENONE=0 ,
  NONSTOPDRIVEOFF=1,
  INTERRUPTEDDRIVEOFF=2,
  INTERRUPTEDDRIVEOFFFIXEDDISTANCE=3,
  CUTOUT=4
}TCI_t_NotificationType;
#endif


#if (TCI_CFG_AUTOCODE == SWITCH_OFF)
typedef struct TCIInputObject
{
  float32 f_LongDisplacement;
  float32 f_LatDisplacement;
  float32 f_VrelLong;
  float32 f_VrelLat;
  float32 f_DistOnTraj;
  ObjNumber_t ObjID;
  EM_t_GenObjDynamicProperty e_ObjDynProb; 
  boolean b_PlausibleObjMovement;
}TCIInputObject_t;
#endif

#if (TCI_CFG_AUTOCODE == SWITCH_OFF)
typedef struct TCIInputInhibit // Custom specific
{
  boolean b_Airbag;
  TransmissionGear_t e_Gear;
  door_state_t e_DoorState;
  seatbelt_state_t e_SeatBeltState;
  boolean b_DriverBraking;
  boolean b_AccEnable;
  float32 f_EgoCurve;
}TCIInputInhibit_t;
#endif

#if (TCI_CFG_AUTOCODE == SWITCH_OFF)
typedef struct TCIInputSensorValid // Technology specific
{
  boolean b_AlnSelftstBlockage; //InhibitFlag, Alignment, Selftest, Blockage, 
}TCIInputSensorValid_t;
#endif

#if (TCI_CFG_AUTOCODE == SWITCH_OFF)
typedef struct TCIGlobal
{
  float32 f_Driveoffdistance;
  float32 f_Indicationtimer;
  float32 f_Drivendistance;
  float32 f_Initialdistance;
  float32 f_Stoppedtargettimer;
#if (TCIACCCOORDINATION == SWITCH_ON)
  float32 f_StoppedEgoTimer;
#endif
  float32 f_Stoppedtargetstatetimer;
  float32 f_DistOnTrajLastCycle;
  TCIState_t_e e_TCIState;
  TCI_t_NotificationType e_NotificationType;
  ObjNumber_t ObjIDLastCycle;
  sint8 s_OOICutout;
  boolean b_subjectdriveoffrequired;
} TCI_GlobalData_t;
#endif

#if (TCI_CFG_AUTOCODE == SWITCH_OFF)
typedef struct TCIInputConst
{
  TCIInputObject_t t_OOIObj[6];
  float32 f_DriveOffDistance;
  float32 f_DriveOffDistanceFixed;
  float32 f_VabsXOOI0;
#if (TCIACCCOORDINATION == SWITCH_ON) 
  float32 f_MinRequestedLongAcceleration;
#endif
  MotState_t e_EgoMotionState; 
  eRelObjLossReason_t e_ObjLossReasonOOI0;
#if (TCIACCCOORDINATION == SWITCH_ON) 
  DAS_status_t DAS_status;
#endif
  boolean b_FrontObstacleDetected;
  boolean b_Inhibit;
  boolean b_SensorValid; 
  boolean b_Initialization; 
  boolean b_TCIActivated;
#if (TCIACCCOORDINATION == SWITCH_ON)
  boolean b_stand_still_detected;
#endif
} TCIInputConst_t;
#endif

#if (TCI_CFG_AUTOCODE == SWITCH_OFF) 
#ifdef FCT_SIMU
typedef struct TCI_SimMeasInfo{
  TCIInputConst_t t_TCI_InternalInput;
  TCI_GlobalData_t t_TCI_GlobalData;
#if (TCIACCCOORDINATION == SWITCH_ON)
  TCI_GlobalData_t t_TCIACC_GlobalData;
#endif
}TCI_SimMeasInfo_t;
#endif
#endif

/*****************************************************************************
  FUNCTION PROTOTYPES (COMPONENT INTERNAL SCOPE)
*****************************************************************************/

/*--- tci_customfunctions.c ---*/
extern void TCI_v_InputWrapper(const LongCtrlInput_t * pLongCtrlResp,
                             const VehDyn_t * pVehDyn,
#if (FCT_CFG_ACC_HEADWAY_PLANNER)
                             const acc_output_data_t* acc_output,
#if (FCT_CFG_SEN2VEH_ACC_OOI_PORT)
                             const FCTSenAccOOI_t* pFCTAccOOIData,
#endif
                             const acc_object_t * pAccDisplayObj,
#endif
                             const LongCtrlOutput_t * pLongCtrlCmd,
                             const TCIInput_t* pTCIInput,
                             TCIOutput_t* pTCIOutput);

#if (TCI_CFG_AUTOCODE == SWITCH_OFF) 
/*************************************************************************************************************************
  Functionname:    TCI_b_TCICheckInhibitStatus                                                                      */ /*!

  @brief           Check Inhibit status

  @description     -

  @startuml 
  Start
			     :Initialize TCIinhibit signal as FALSE;
	  Partition TCI_CheckInhibitStatus {    
			  If( (parking== gearstate) or (reverse== gearstate) or (Seatbeltdriverclosed != seatbeltstate) or (doorstate != alldoorsclosed) or (egocurve >tciegocurve) ) then (true)
			     :Set TCInhibit signal as TRUE;
			  else(false)
			     :Set TCIInhibit signal as FALSE;
			  Endif
	  }
			     :Return TCIInhibit value;
	
  End 
  @enduml

  @return          boolean

  @param[in]       pt_TCIInputInhibit :Inputs related to inhibition [as defined in tci.h]

  @glob_in         -
  @glob_out        -

  @c_switch_part   -
  @c_switch_full   FCT_CFG_TCI : FCT support for TCI module
  @c_switch_full   TCI_CFG_AUTOCODE : Configuration switch to Enable/Disable TCI Autocode

  @pre             -
  @post            -

  @created        27.03.2018
  @changed        27.03.2018

  @traceability    doors://rbgs854a:40000/?version=2&prodID=0&view=00000002&urn=urn:telelogic::1-503e822e5ec3651e-O-164-0008a220 
  @author          Marie-Theres Boll | Marie-Theres.Boll@continental-corporation.com | +49-8382-9699-632
                   Bibin Mathew | bibin.mathew@continental-corporation.com | +91 (80) 6679-6524
*************************************************************************************************************************/
extern boolean TCI_b_TCICheckInhibitStatus(const TCIInputInhibit_t * pTCIInputInhibit);
#endif

#if (TCI_CFG_AUTOCODE == SWITCH_OFF) 
/*************************************************************************************************************************
  Functionname:    TCI_b_TCISetInputInhibit                                                                         */ /*!

  @brief           Function to update the TCIInputInhibit values

  @description     Function to update the TCIInputInhibit values

  @startuml 
  Start
	  Partition TCI_Setinputinhibit {    
			      : Setting the input for Inhibition airbag from RTE;
			      : Setting the input for Inhibition gear from RTE;
			      : Setting the input for Inhibition doorstate from RTE;
			      : Setting the input for Inhibition seatbeltstate from RTE;
			      : Setting the input for driverbraking,accenable&egocurve from RTE;
	  }
			   	
  End 
  @enduml

  @return          void

  @param[in]       pLongCtrlResp :Long control input as defined in RTE of type LongCtrlInput_t
  @param[in]       pVehDyn :Ego vehicle dynamic as defined in RTE of type VehDyn_t
  @param[out]      pt_TCIInputInhibit :inputs related to inhibition [as defined in tci.h]

  @glob_in         -
  @glob_out        -

  @c_switch_part   -
  @c_switch_full   FCT_CFG_TCI : FCT support for TCI module
  @c_switch_full   TCI_CFG_AUTOCODE : Configuration switch to Enable/Disable TCI Autocode

  @pre             -
  @post            -

  @created         27.03.2018
  @changed         27.03.2018

  @traceability    doors://rbgs854a:40000/?version=2&prodID=0&view=00000002&urn=urn:telelogic::1-503e822e5ec3651e-O-165-0008a220
  @author          Marie-Theres Boll | Marie-Theres.Boll@continental-corporation.com | +49-8382-9699-632
                   Bibin Mathew | bibin.mathew@continental-corporation.com | +91 (80) 6679-6524
*************************************************************************************************************************/
extern void TCI_b_TCISetInputInhibit(const LongCtrlInput_t * pLongCtrlResp,
  const VehDyn_t * pVehDyn,
   const LongCtrlOutput_t * pLongCtrlCmd,
  TCIInputInhibit_t * pt_TCIInputInhibit);
#endif

#ifdef __cplusplus
};
#endif

#endif /*!< FCT_CFG_TCI */

/** @} end defgroup */

/* End of conditional inclusion */
#endif  /*!< _TCI_H_INCLUDED */

