/* avoid cyclic binding -----------------------------------------------------*/
#ifndef __MOCKUP_SERVICES_H
#define __MOCKUP_SERVICES_H

/* Ensure that this file is only used by Courage */
#ifdef __COURAGE_TEST_SWITCH__

#include <courage.h>
/* include the files that shall be tested */
#include <string.h>

#include "hla_defs.h"

#define TEST_MOCKUP_INIT_BYTE       0x55
#define TEST_MOCKUP_INIT_SHORT      (uint16)(TEST_MOCKUP_INIT_BYTE | (TEST_MOCKUP_INIT_BYTE << 8))
#define TEST_MOCKUP_INIT_INT        (uint32)(TEST_MOCKUP_INIT_SHORT | (TEST_MOCKUP_INIT_SHORT << 16))
#define TEST_MOCKUP_INIT_FLOAT      (float32)(TEST_MOCKUP_INIT_INT)

#define TEST_MOCKUP_DEM_STACK_SIZE  10
#define TEST_MOCKUP_DEM_DATA_SIZE   8     // re-definition of HLA_DEM_MAX_NUM_ADDITIONAL_BYTES from hla_main.c

// Type definitions
typedef struct
{
  AS_t_Dem_EventIDType     eventIds[TEST_MOCKUP_DEM_STACK_SIZE];
  AS_t_Dem_EventStatusType eventStatus[TEST_MOCKUP_DEM_STACK_SIZE];
  uint8                    eventData[TEST_MOCKUP_DEM_STACK_SIZE][TEST_MOCKUP_DEM_DATA_SIZE];
} t_MockupDemStack;

// Define global variables
extern reqHlaPrtList_t              ReqPorts;
extern proHlaPrtList_t              ProPorts;
extern AS_t_ServiceFuncts           Services;

extern BaseCtrlData_t               BaseCtrlData;
extern AbdOutputData_t              AbdOutputData;
extern CPAR_HLAF_Parameter_t        CPar_HlafPar;
extern HLA_BusInputSignals_t        HlaBusInputSignals;
extern HLA_RadarObjectList_t        HlaRadarObjectList;
extern LSD_EnvironmentData_t        LsdEnvironmentData;
extern LSD_LightList_t              LsdLightList;
extern LSD_LightObjectList_t        LsdLightObjectList;
extern CB_t_ProvidedOutputs_t       Blockage;
extern EM_t_GenObjectList           EMObjectsList;
extern LdOutputData_t               LDOut;
extern MonoCalibration_t            MonoCalibration;
extern VehDyn_t                     VDYData;
extern VehSig_t                     VehSig;

extern AlgoCompState_t              AlgoCompState;
extern RTE_HLAF_HeadlightControl_t  HeadlightControl;

extern t_MockupDemStack             DemStack;
extern uint8                        DemStackFreeIndex;

// Unusual floats
extern const float32 f_NAN;
extern const float32 f_INF;
// Function declaration
// Local functions
void Mockup_InitGlobVars(void);


#endif /* #ifdef __COURAGE_TEST_SWITCH__ */

#endif /* #ifndef __MOCKUP_SERVICES_H*/
