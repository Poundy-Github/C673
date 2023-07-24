 /*! \file **********************************************************************

  COMPANY:                Continental AG, BU ADAS, A.D.C. GmbH

  PROJECT:                

  COMPONENT:              

  MODULNAME:              polyspace_stubs_algo_services.c

  DESCRIPTION:            Polyspace Code Prover specific stub functions
                          for algo service functions.

  AUTHOR:                 Matthias Mutschler

  CREATION DATE:          2016-01-08

  VERSION:                $Revision: 1.3 $


*/

/*---------------------------------------------------*/
/*  INCLUDES                                         */
/*---------------------------------------------------*/
#include "polyspace_helper.h"
#include "polyspace_stubs_algo_services.h"

/*---------------------------------------------------*/
/*  MACROS                                           */
/*---------------------------------------------------*/



/*---------------------------------------------------*/
/*  TYPEDEFS                                         */
/*---------------------------------------------------*/


/*---------------------------------------------------*/
/*  GLOBAL VARIABLES                                 */
/*---------------------------------------------------*/

/*---------------------------------------------------*/
/*  LOCAL FUNCTION DECLARATIONS                      */
/*---------------------------------------------------*/
static sint32 psStub_RtaAlgoServiceAddEvent(AS_t_RtaEventType RtaEvtType, uint8 u_IdGlobal, uint8 u_IdLocal, uint8 u_OptData);
static AS_t_MeasErrors psStub_MeasStartFuncCycle(const AS_t_MeasFuncID measFuncChannelId);
static AS_t_MeasReturn psStub_MeasHdlr(const AS_t_MeasInfo *p_MeasInfo, const void *p_Buff, AS_t_MeasCallback pf_MeasCallback);
static AS_t_Dem_ReturnType psStub_Dem_SetEventStatus(const AS_t_Dem_EventIDType u_Dem_EventIdRaw, const AS_t_Dem_EventStatusType u_Dem_EventStatus);
static AS_t_Dem_ReturnType psStub_Dem_SetEventStatusPreExtData(const AS_t_Dem_EventIDType u_Dem_EventIdRaw, const AS_t_Dem_EventStatusType u_Dem_EventStatus, const uint8* const p_Dem_pui8_PreExtData, uint8 u_Dem_PreExtDataSize);


/*---------------------------------------------------*/
/*  GLOBAL FUNCTION DEFINITIONS                      */
/*---------------------------------------------------*/


void init_AlgoServices(AS_t_ServiceFuncts* algoServices)
{
  /* Initialize service functions struct to NULL pointer by default */
  (void)memset((void*)algoServices, 0, sizeof(AS_t_ServiceFuncts));

  /* Let polyspace decide whether function pointers are set to already implemented services or NULL*/
  algoServices->pfRTAAlgoServiceAddEvent             = full_range_uint8 ? &psStub_RtaAlgoServiceAddEvent             : NULL;  
  algoServices->pfMeasFreeze                         = full_range_uint8 ? &psStub_MeasHdlr                           : NULL;  
  algoServices->pfMeasStartFuncCycle                 = full_range_uint8 ? &psStub_MeasStartFuncCycle                 : NULL;  
  algoServices->pfDem_SetEventStatus                 = full_range_uint8 ? &psStub_Dem_SetEventStatus                 : NULL;  
  algoServices->pfDem_SetEventStatusPreExtData       = full_range_uint8 ? &psStub_Dem_SetEventStatusPreExtData       : NULL; 
}


/*---------------------------------------------------*/
/*  LOCAL FUNCTION DEFINITIONS                       */
/*---------------------------------------------------*/
sint32 psStub_RtaAlgoServiceAddEvent(AS_t_RtaEventType RtaEvtType, uint8 u_IdGlobal, uint8 u_IdLocal, uint8 u_OptData)
{
  return full_range_sint32;
}

static AS_t_MeasErrors psStub_MeasStartFuncCycle(const AS_t_MeasFuncID measFuncChannelId)
{
  return (AS_t_MeasErrors)full_range_uint32;
}

static AS_t_MeasReturn psStub_MeasHdlr(const AS_t_MeasInfo *p_MeasInfo, const void *p_Buff, AS_t_MeasCallback pf_MeasCallback)
{
  return (AS_t_MeasReturn)full_range_uint32;
}
 
static AS_t_Dem_ReturnType psStub_Dem_SetEventStatus(const AS_t_Dem_EventIDType u_Dem_EventIdRaw, const AS_t_Dem_EventStatusType u_Dem_EventStatus)
{
  return full_range_uint8;
}

static AS_t_Dem_ReturnType psStub_Dem_SetEventStatusPreExtData(const AS_t_Dem_EventIDType u_Dem_EventIdRaw, const AS_t_Dem_EventStatusType u_Dem_EventStatus, const uint8* const p_Dem_pui8_PreExtData, uint8 u_Dem_PreExtDataSize)
{
  return full_range_uint8;
}

