 /*! \file **********************************************************************
  COMPANY:                Continental AG, BU ADAS, A.D.C. GmbH
  PROJECT:                
  COMPONENT:              
  MODULNAME:              testdriver_template.txt
  
  DESCRIPTION:            Template of a test-driver file. 
                          This test-driver is used to verify the code of >AlgoComponent< as a whole in Polyspace CodeProver.
                          To do so, copy this template file into the polyspace-project-folder of the AlgoComponent and rename it.
                          After that, modify this template in your Visual Studio Project (search for TODOs).
                          
  TEMPLATE-LINK:          ../Base_Development/05_Algorithm/ETK_EngineeringToolKit/04_Engineering/PST_PolyspaceTools/
                          
  AUTHOR:                 $Author: Fischer, Alexander (uidv8778) $
  CREATION DATE:          $Date: 2017/11/28 11:18:26CET $
  VERSION:                $Revision: 1.3 $
*/

/*---------------------------------------------------*/
/*  INCLUDES                                         */
/*---------------------------------------------------*/
#include "polyspace_helper.h"
#include "polyspace_stubs_algo_services.h"
/* Include HLA interface */
#include "hla_ext.h"
#include <string.h>

/*---------------------------------------------------*/
/*  TYPEDEFS                                         */
/*---------------------------------------------------*/

/* Big buffer that contains whole RTE request port buffers */
typedef struct
{
  BaseCtrlData_t               BaseCtrlData;
  AbdOutputData_t              AbdOutputData;
  CPAR_HLAF_Parameter_t        CPar_HlafPar;
  CB_t_ProvidedOutputs_t       Sig_Blockage;
  EM_t_GenObjectList           Sig_EMObjectsList;
  HLA_BusInputSignals_t        HlaBusInputSignals;
  MonoCalibration_t            Sig_MonoCalibration;
  LdOutputData_t               Sig_LDOut;
  VehDyn_t                     SigVeh_VDYData;
  VehSig_t                     SigVeh_VehSig;
  LSD_EnvironmentData_t        LsdEnvironmentData;
  LSD_LightObjectList_t        LsdLightObjectList;
} SimHlaReqPrtBuffers_t;

/* Big buffer that contains whole RTE provide port buffers */
typedef struct  
{
  AlgoCompState_t             AlgoCompState;
  RTE_HLAF_HeadlightControl_t Hlaf_HeadlightControl;
} SimHlaProPrtBuffers_t;

/*---------------------------------------------------*/
/*  GLOBAL VARIABLES                                 */
/*---------------------------------------------------*/
/* Input data structs */
static reqHlaPrtList_t    reqPorts;  // TODO set correct type
static proHlaPrtList_t    proPorts;  // TODO set correct type
static AS_t_ServiceFuncts services;

/* request ports */
static SimHlaReqPrtBuffers_t reqPortsBuffers;
/* provide ports */
static SimHlaProPrtBuffers_t proPortsBuffers;

/*---------------------------------------------------*/
/*  LOCAL FUNCTION DECLARATIONS                      */
/*---------------------------------------------------*/
void mapReqPortsToAllocMem();
void mapProPortsToAllocMem();
void fillAllocMemOfReqPorts();
void fillAllocMemOfProPorts();

/*---------------------------------------------------*/
/*  MAIN FUNCTION CALL                               */
/*---------------------------------------------------*/
void main()
{
  /*----------*/
  /*   INIT   */
  /*----------*/

  mapReqPortsToAllocMem();
  mapProPortsToAllocMem();

  fillAllocMemOfReqPorts();
  fillAllocMemOfProPorts();  
  
  /* Define service functions */
  init_AlgoServices(&services);

  /* Call algo in reset mode firstly */
  reqPorts.pBaseCtrlData->eOpMode = BASE_OM_RESET;
  // TODO set correct function to call ...
  //_Exec( (full_range_uint8 ? &reqPorts : NULL), (full_range_uint8 ? &proPorts : NULL), (full_range_uint8 ? &services : NULL) );
  HlaExec(&reqPorts, &proPorts, &services);

  /*----------------*/
  /*    MAIN CALL   */
  /*----------------*/
  /* Call algo with all possible inputs (for an uncertain number of iterations - Polyspace will analyze each case) */
  while(full_range_uint32)
  {
    fillAllocMemOfReqPorts();
    fillAllocMemOfProPorts();
    // TODO set correct function to call ...
    HlaExec( (full_range_uint8 ? &reqPorts : NULL), (full_range_uint8 ? &proPorts : NULL), (full_range_uint8 ? &services : NULL) );
  }
  
}

/*---------------------------------------------------*/
/*  LOCAL FUNCTION DEFINITION                        */
/*---------------------------------------------------*/

/* Link all pointers (inside the struct) to the allocated memory (and to NULL) */
/* Otherwise the pointers will point anywhere. This could result in a lot of warnings or a crash of Polyspace Code Prover*/
/* Polyspace will analyze both cases! */
void mapReqPortsToAllocMem()
{
  reqPorts.pBaseCtrlData            = full_range_uint8 ? &reqPortsBuffers.BaseCtrlData        : NULL;
  reqPorts.pAbdOutputData           = full_range_uint8 ? &reqPortsBuffers.AbdOutputData       : NULL;
  reqPorts.pCPar_HlafPar            = full_range_uint8 ? &reqPortsBuffers.CPar_HlafPar        : NULL;   
  reqPorts.pSig_Blockage            = full_range_uint8 ? &reqPortsBuffers.Sig_Blockage        : NULL;
  reqPorts.pSig_EMObjectsList       = full_range_uint8 ? &reqPortsBuffers.Sig_EMObjectsList   : NULL;
  reqPorts.pHlaBusInputSignals      = full_range_uint8 ? &reqPortsBuffers.HlaBusInputSignals  : NULL;
  reqPorts.pSig_MonoCalibration     = full_range_uint8 ? &reqPortsBuffers.Sig_MonoCalibration : NULL;
  reqPorts.pSig_LDOut               = full_range_uint8 ? &reqPortsBuffers.Sig_LDOut           : NULL;
  reqPorts.pSigVeh_VDYData          = full_range_uint8 ? &reqPortsBuffers.SigVeh_VDYData      : NULL;
  reqPorts.pSigVeh_VehSig           = full_range_uint8 ? &reqPortsBuffers.SigVeh_VehSig       : NULL;
  reqPorts.pLsdEnvironmentData      = full_range_uint8 ? &reqPortsBuffers.LsdEnvironmentData  : NULL;
  reqPorts.pLsdLightObjectList      = full_range_uint8 ? &reqPortsBuffers.LsdLightObjectList  : NULL;
}


/* Link all pointers (inside the struct) to the allocated memory (and to NULL) */
/* Polyspace will analyze both cases! */
void mapProPortsToAllocMem()
{
  proPorts.pAlgoCompState          = full_range_uint8 ? &proPortsBuffers.AlgoCompState         : NULL; 
  proPorts.pHlaf_HeadlightControl  = full_range_uint8 ? &proPortsBuffers.Hlaf_HeadlightControl : NULL; 
}

  
/* Fill the allocated memory, where the request ports point to, with values. */
/* Random values (full_range) can be set by using memset != 0. */
void fillAllocMemOfReqPorts()
{
  (void)memset((void*)&reqPortsBuffers, 1, sizeof(reqPortsBuffers));
  
  // TODO if necessary, define ranges more precisely by using Macros defined in file "testdriver_helper.h"
}


/* Fill the allocated memory, where the provide ports point to, with values. */
/* Random values (full_range) can be set by using memset != 0. */
void fillAllocMemOfProPorts()
{
  if(proPorts.pAlgoCompState != NULL)
  {
    memset((void*)proPorts.pAlgoCompState,          1, sizeof(AlgoCompState_t));
  }
  if(proPorts.pHlaf_HeadlightControl != NULL)
  {
    memset((void*)proPorts.pHlaf_HeadlightControl,  1, sizeof(RTE_HLAF_HeadlightControl_t));
  }
}

