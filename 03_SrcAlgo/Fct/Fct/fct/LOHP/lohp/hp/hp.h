/*! \file **********************************************************************

COMPANY:                   COPYRIGHT (C) Continental AG

PROJECT:                   Adaptive Cruise Control (ACC)

CPU:                       CPU-Independent

COMPONENT:                 ACC/LOHP/HP (Adaptive Cruise Control - Longitudinal Headway Planner - Headway Planner)

PACKAGENAME:               hp.h

DESCRIPTION:               Internal header file for function HP in LOHP 

AUTHOR:                    Mistry Niraj (uidq5738)

CREATION DATE:             24.02.2017

VERSION:                   $Revision: 1.16 $

LEGACY VERSION:            Revision: 1.10.1.2

**************************************************************************** */

#ifndef HP_H_INCLUDED
#define HP_H_INCLUDED

/*****************************************************************************
  MODULE DESCRIPTION
*****************************************************************************/
/** 
@defgroup   hp_h Hp_h
@ingroup    hp
@brief      HP internal header file
@{ */ 

/*****************************************************************************
  INCLUDES
*****************************************************************************/

#include "lohp.h"

#if ((FCT_CFG_LOHP_COMPONENT) && (FCT_CFG_ACC_HEADWAY_PLANNER))

#include "hp_cfg.h"
#include "hp_par.h"
#include "hp_frules.h"
#include "hp_lib.h"
#include "hp_lib_ext.h"

/*****************************************************************************
  SYMBOLIC CONSTANTS 
*****************************************************************************/
/* Aliasas for new object OOI positions */
#define Obj_first_host_lane     OBJ_NEXT_OOI
#define Obj_hidden_host_lane    OBJ_HIDDEN_NEXT_OOI
#define Obj_first_left_lane     OBJ_NEXT_LONG_LEFT_OOI
#define Obj_second_left_lane    OBJ_NEXT_LAT_LEFT_OOI
#define Obj_first_right_lane    OBJ_NEXT_LONG_RIGHT_OOI
#define Obj_second_right_lane   OBJ_NEXT_LAT_RIGHT_OOI

/*****************************************************************************
  MACROS
*****************************************************************************/

/*****************************************************************************
  TYPEDEFS
*****************************************************************************/
typedef /*const*/ acc_object_t* acc_object_ptr_t;

typedef struct CopyObjInput{
  const SLATE_HC_Data_t   * pSLATEData;
  const FCTSenAccOOI_t    * pFCTAccOOIData;
  const AccOOIGenKinematics_t * pOOIKinematics;
  const AccOOIGenAttributes_t * pOOIAttribute;
  const FctVeh2SenInfo_t  * pFctVehLongOut;
  const acc_input_data_t  * acc_input_data_ptr;
  times_t                 cycle_time;
  ObjNumber_t             ObjNr;
}CopyObjInput_t;

typedef struct CopyObjOutput{
  acc_object_t      * pDestObj;
}CopyObjOutput_t;

/*****************************************************************************
  CONSTANTS 
*****************************************************************************/

/*****************************************************************************
  VARIABLES
*****************************************************************************/
extern acc_object_t ACC_NO_OBJECT;

/*****************************************************************************
  FUNCTION PROTOTYPES 
*****************************************************************************/
extern void HP_v_EstimateTrafficSituation(const times_t cycle_time, acc_object_t object_list[Acc_max_number_ooi], const acc_input_data_t* input, acc_status_t* status, acc_output_data_t* output);
extern void HP_v_EstimateDriverIntention(const times_t cycle_time, const acc_object_t object_list[Acc_max_number_ooi], const acc_input_data_t* input, acc_driver_intention_t* output, acc_status_t* status);
extern void HP_v_AlertInit(acc_alert_data_t *acc_alert_data);
extern void HP_v_AlertProcess(const acc_input_data_t* input, const acc_object_t* alert_object, acc_output_data_t* output, acc_alert_data_t *acc_alert_data, times_t cycle_time);
extern void HP_v_SelectObjectsOfInterest(acc_driver_intention_t* driver_intention, const acc_input_data_t *acc_input, acc_object_t object_list[Acc_max_number_ooi], acc_status_t *status, times_t cycle_time);
extern void HP_v_SelectRelevantObject(acc_object_t object_list[Acc_max_number_ooi], acc_object_t* control_object, acc_object_t* alert_object, acc_object_t* display_object, const acc_input_data_t* input, acc_output_data_t* output, acc_status_t *status);
extern void HP_v_EgoDataWapper(const VehDyn_t* pVehDyn, const FctVeh2SenInfo_t* pFctVehLongOut, acc_input_data_t* acc_input_data_ptr);
extern void HP_v_ObjDataWapper(const CopyObjInput_t t_CopyObjInput, acc_object_t * pDestObj, uint8 u8_OOINr);
extern void HP_v_PlanOvertakeManoeuvreCustom(const acc_input_data_t* acc_input, const acc_object_t object_list[Acc_max_number_ooi], acc_status_t* status, times_t cycle_time);
extern void HP_v_SetMaxDecelCustom(const acc_input_data_t* acc_input, acc_driver_intention_t* driver_intention, acc_object_t object_list[Acc_max_number_ooi], acc_status_t* status, times_t cycle_time);
#if (CFG_FCT_ACC_PARAMS_DEBUG)
extern void HP_v_FreezeACCParams(void);
#endif

#endif  /* FCT_CFG_ACC_HEADWAY_PLANNER */

/** @} end defgroup */

#endif /* HP_H_INCLUDED */
