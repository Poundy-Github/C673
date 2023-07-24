/*! \file **********************************************************************

COMPANY:                   COPYRIGHT (C) Continental AG
  
PROJECT:                   Mainstream

CPU:                       CPU-Independent

COMPONENT:                 ACDC - Advanced collision detection and classification

PACKAGENAME:               acdc_types.h

DESCRIPTION:               Header file for the ACDC types

AUTHOR:                    $Author: Kramer, Andreas (uidv8254) $

CREATION DATE:             $Date: 2018/12/17 15:05:09CET $

VERSION:                   $Revision: 1.2 $

**************************************************************************** */
#ifndef ACDC_MEM_INCLUDED
#define ACDC_MEM_INCLUDED

/************************************************************************/
/*                        INCLUDES                                      */
/************************************************************************/
#include "acdc_types.h"
#include "aip_ext_types.h"
#include "cd_ext_types.h"
#include "emp_ext_types.h"
#include "espm_ext_types.h"

#if (ACDC_CFG_FRAME)

/*!
@defgroup type_framework Memory
@ingroup frame_types

@brief    Contains the framework of the memory structure.  \n\n
@description 
          The typedefs of the subcomponents are included with ACDC_types.h and the "subX_ext_types.h" headers. In this file all the structures are put together to one structure.\nThis structure is used for the GA global memorys concept.
          All static memory is handled in this structure. Each subcomponent has a separate substructure where all calculated results shall be stored.\n
          All subcomponents have access to everything in the memory structure.\n\n
          To put variables into substructures the corresponding switch has to be activated.\n\n
          Take care to put the variables into the structure which supports the expected behavior
          .
          | Memory block           | STACK                                    | INTER                                    | INTERMEAS               | INTRA                                  | INTRAMEAS                              | SIMU                             |
          | :-----------           | :----                                    | :----                                    | :-------                | :----                                  | :--------                              | :--                              |
          | <b>Purpose        </b> | - Data contains no history \n - It has to be accessed \n in multiple functions. |- Data contains history. \n - It has to be initialized in simulation. \n - It <b>is not</b> needed for visualization \n or debugging of the ECU behavior.|- Data contains history. \n - It has to be initialized in simulation. \n - It <b>is</b> needed for visualization \n or debugging of the ECU behavior.|- Similar to Stack data \n but data is needed for multiple runnables. \n - It <b>is not</b> needed for visualization \n or debugging of the ECU behavior.|- Similar to Stack data \n but data is needed for multiple runnables. \n - It <b>is</b> needed for visualization \n or debugging of the ECU behavior.| - Debugging data \n which is not \n needed in the ECU.|
          | <b>Persists during</b> | the execution \n of ACDC_Exec            | the ECU power cycle                      | the ECU power cycle     | multiple runnables \n of one component | multiple runnables \n of one component | one load cycle \n of the SIM dll |
          | <b>ECU Freeze     </b> | None                                     | keyframes are frozen\n in multiple slices| cyclic                  | none                                   | cyclic                                 | none                             |
          | <b>SIMU Freeze    </b> | cyclic                                   | cyclic                                   | cyclic                  | cyclic                                 | cyclic                                 | cyclic                           |
          | <b>Hints          </b> |                                          |                                          | Should be as small \n as possible | Not to be used \n if component has one runnable | Not to be used \n if component has one runnable. \n Should be as small \n as possible |  |


@{*/

/*********************************************************************/
/* ACDC Memory                                                       */
/*********************************************************************/

/*! This version numbers has to be adapted on every update of the INTER cycle memory */
#define ACDC_INTER_CYCLE_MEMORY_VERSION      (         1)
#define ACDC_INTER_CYCLEMEAS_MEMORY_VERSION  (         1)


/* Switches for the integration of substructs */
#define USE_ACDCWRAPPER_OBJ_STACK       ((USE_ACDC_OBJ_STACK)  || (ACDC_CFG_AIP && USE_AIP_OBJ_STACK)  || (ACDC_CFG_ESPM && USE_ESPM_OBJ_STACK)  || (ACDC_CFG_CD && USE_CD_OBJ_STACK)  || (ACDC_CFG_EMP && USE_EMP_OBJ_STACK) )
#define USE_ACDCWRAPPER_GLOB_STACK      ((USE_ACDC_GLOB_STACK) || (ACDC_CFG_AIP && USE_AIP_GLOB_STACK) || (ACDC_CFG_ESPM && USE_ESPM_GLOB_STACK) || (ACDC_CFG_CD && USE_CD_GLOB_STACK) || (ACDC_CFG_EMP && USE_EMP_GLOB_STACK) )
#define USE_ACDCWRAPPER_STACK           (USE_ACDCWRAPPER_OBJ_STACK || USE_ACDCWRAPPER_GLOB_STACK)

#define USE_ACDCWRAPPER_OBJ_INTRA       ((USE_ACDC_OBJ_INTRA)  || (ACDC_CFG_AIP && USE_AIP_OBJ_INTRA)  || (ACDC_CFG_ESPM && USE_ESPM_OBJ_INTRA)  || (ACDC_CFG_CD && USE_CD_OBJ_INTRA)  || (ACDC_CFG_EMP && USE_EMP_OBJ_INTRA) )
#define USE_ACDCWRAPPER_GLOB_INTRA      ((USE_ACDC_GLOB_INTRA) || (ACDC_CFG_AIP && USE_AIP_GLOB_INTRA) || (ACDC_CFG_ESPM && USE_ESPM_GLOB_INTRA) || (ACDC_CFG_CD && USE_CD_GLOB_INTRA) || (ACDC_CFG_EMP && USE_EMP_GLOB_INTRA) )
#define USE_ACDCWRAPPER_INTRA           (USE_ACDCWRAPPER_OBJ_INTRA || USE_ACDCWRAPPER_GLOB_INTRA)

#define USE_ACDCWRAPPER_OBJ_INTRAMEAS   ((USE_ACDC_OBJ_INTRAMEAS)  || (ACDC_CFG_AIP && USE_AIP_OBJ_INTRAMEAS)  || (ACDC_CFG_ESPM && USE_ESPM_OBJ_INTRAMEAS)  || (ACDC_CFG_CD && USE_CD_OBJ_INTRAMEAS)  || (ACDC_CFG_EMP && USE_EMP_OBJ_INTRAMEAS) )
#define USE_ACDCWRAPPER_GLOB_INTRAMEAS  ((USE_ACDC_GLOB_INTRAMEAS) || (ACDC_CFG_AIP && USE_AIP_GLOB_INTRAMEAS) || (ACDC_CFG_ESPM && USE_ESPM_GLOB_INTRAMEAS) || (ACDC_CFG_CD && USE_CD_GLOB_INTRAMEAS) || (ACDC_CFG_EMP && USE_EMP_GLOB_INTRAMEAS) )
#define USE_ACDCWRAPPER_INTRAMEAS       (USE_ACDCWRAPPER_OBJ_INTRAMEAS || USE_ACDCWRAPPER_GLOB_INTRAMEAS)

#define USE_ACDCWRAPPER_OBJ_INTER       ((USE_ACDC_OBJ_INTER)  || (ACDC_CFG_AIP && USE_AIP_OBJ_INTER)  || (ACDC_CFG_ESPM && USE_ESPM_OBJ_INTER)  || (ACDC_CFG_CD && USE_CD_OBJ_INTER)  || (ACDC_CFG_EMP && USE_EMP_OBJ_INTER) )
#define USE_ACDCWRAPPER_GLOB_INTER      ((USE_ACDC_GLOB_INTER) || (ACDC_CFG_AIP && USE_AIP_GLOB_INTER) || (ACDC_CFG_ESPM && USE_ESPM_GLOB_INTER) || (ACDC_CFG_CD && USE_CD_GLOB_INTER) || (ACDC_CFG_EMP && USE_EMP_GLOB_INTER) )
#define USE_ACDCWRAPPER_INTER           (USE_ACDCWRAPPER_OBJ_INTER || USE_ACDCWRAPPER_GLOB_INTER)

#define USE_ACDCWRAPPER_OBJ_INTERMEAS   ((USE_ACDC_OBJ_INTERMEAS)  || (ACDC_CFG_AIP && USE_AIP_OBJ_INTERMEAS)  || (ACDC_CFG_ESPM && USE_ESPM_OBJ_INTERMEAS)  || (ACDC_CFG_CD && USE_CD_OBJ_INTERMEAS)  || (ACDC_CFG_EMP && USE_EMP_OBJ_INTERMEAS) )
#define USE_ACDCWRAPPER_GLOB_INTERMEAS  ((USE_ACDC_GLOB_INTERMEAS) || (ACDC_CFG_AIP && USE_AIP_GLOB_INTERMEAS) || (ACDC_CFG_ESPM && USE_ESPM_GLOB_INTERMEAS) || (ACDC_CFG_CD && USE_CD_GLOB_INTERMEAS) || (ACDC_CFG_EMP && USE_EMP_GLOB_INTERMEAS) )
#define USE_ACDCWRAPPER_INTERMEAS       (USE_ACDCWRAPPER_OBJ_INTERMEAS || USE_ACDCWRAPPER_GLOB_INTERMEAS)

#define USE_ACDCWRAPPER_OBJ_SIMU        ((USE_ACDC_OBJ_SIMU)  || (ACDC_CFG_AIP && USE_AIP_OBJ_SIMU)  || (ACDC_CFG_ESPM && USE_ESPM_OBJ_SIMU)  || (ACDC_CFG_CD && USE_CD_OBJ_SIMU)  || (ACDC_CFG_EMP && USE_EMP_OBJ_SIMU) )
#define USE_ACDCWRAPPER_GLOB_SIMU       ((USE_ACDC_GLOB_SIMU) || (ACDC_CFG_AIP && USE_AIP_GLOB_SIMU) || (ACDC_CFG_ESPM && USE_ESPM_GLOB_SIMU) || (ACDC_CFG_CD && USE_CD_GLOB_SIMU) || (ACDC_CFG_EMP && USE_EMP_GLOB_SIMU) )
#define USE_ACDCWRAPPER_SIMU            (USE_ACDCWRAPPER_OBJ_SIMU || USE_ACDCWRAPPER_GLOB_SIMU)
/* End of switches for the integration of substructs */



/************************************************************************/
/* ACDC wrapper Stack types                                             */
/************************************************************************/

#if (USE_ACDCWRAPPER_OBJ_STACK)
typedef struct ACDC_ObjDataWrapperStackHeader_t
{
  float32 Dummy;
}ACDC_ObjDataWrapperStackHeader_t;

typedef struct ACDC_ObjDataWrapperStackObj_t
{
#if (USE_ACDC_OBJ_STACK)
  ACDC_ObjStack_t     ACDC;
#endif
#if (ACDC_CFG_AIP && USE_AIP_OBJ_STACK)
  AIP_ObjStack_t      AIP;
#endif
#if (ACDC_CFG_ESPM && USE_ESPM_OBJ_STACK)
  ESPM_ObjStack_t     ESPM;
#endif
#if (ACDC_CFG_CD && USE_CD_OBJ_STACK)
  CD_ObjStack_t       CD;
#endif
#if (ACDC_CFG_EMP && USE_EMP_OBJ_STACK)
  EMP_ObjStack_t      EMP;
#endif
}ACDC_ObjDataWrapperStackObj_t;

typedef struct ACDC_ObjDataWrapperStack_t
{
  ACDC_ObjDataWrapperStackHeader_t sHeader;
  ACDC_ObjDataWrapperStackObj_t    aObj[EM_N_OBJECTS];
}ACDC_ObjDataWrapperStack_t;
#endif

#if (USE_ACDCWRAPPER_GLOB_STACK)
typedef struct ACDC_GlobDataWrapperStack_t
{
#if (USE_ACDC_GLOB_STACK)
  ACDC_GlobDataStack_t     ACDC;
#endif
#if (ACDC_CFG_AIP && USE_AIP_GLOB_STACK)
  AIP_GlobDataStack_t      AIP;
#endif
#if (ACDC_CFG_ESPM && USE_ESPM_GLOB_STACK)
  ESPM_GlobDataStack_t     ESPM;
#endif
#if (ACDC_CFG_CD && USE_CD_GLOB_STACK)
  CD_GlobDataStack_t       CD;
#endif
#if (ACDC_CFG_EMP && USE_EMP_GLOB_STACK)
  EMP_GlobDataStack_t      EMP;
#endif
}ACDC_GlobDataWrapperStack_t;
#endif

#if (USE_ACDCWRAPPER_STACK)
typedef struct  ACDC_DataWrapperStack_t  
{
  SignalHeader_t              sSigHeader;
#if (USE_ACDCWRAPPER_OBJ_STACK)
  ACDC_ObjDataWrapperStack_t  sObjData;
#endif
#if (USE_ACDCWRAPPER_GLOB_STACK)
  ACDC_GlobDataWrapperStack_t sGlobData;
#endif
}ACDC_DataWrapperStack_t;
#endif

/************************************************************************/
/* ACDC wrapper Inter types                                             */
/************************************************************************/

#if (USE_ACDCWRAPPER_OBJ_INTER)
typedef struct ACDC_ObjDataWrapperInterHeader_t
{
  float32 Dummy;
}ACDC_ObjDataWrapperInterHeader_t;

typedef struct ACDC_ObjDataWrapperInterObj_t
{
#if (USE_ACDC_OBJ_INTER)
  ACDC_ObjInter_t     ACDC;
#endif
#if (ACDC_CFG_AIP && USE_AIP_OBJ_INTER)
  AIP_ObjInter_t      AIP;
#endif
#if (ACDC_CFG_ESPM && USE_ESPM_OBJ_INTER)
  ESPM_ObjInter_t     ESPM;
#endif
#if (ACDC_CFG_CD && USE_CD_OBJ_INTER)
  CD_ObjInter_t       CD;
#endif
#if (ACDC_CFG_EMP && USE_EMP_OBJ_INTER)
  EMP_ObjInter_t      EMP;
#endif
}ACDC_ObjDataWrapperInterObj_t;

typedef struct ACDC_ObjDataWrapperInter_t
{
  ACDC_ObjDataWrapperInterHeader_t sHeader;
  ACDC_ObjDataWrapperInterObj_t    aObj[EM_N_OBJECTS];
}ACDC_ObjDataWrapperInter_t;
#endif

#if (USE_ACDCWRAPPER_GLOB_INTER)
typedef struct ACDC_GlobDataWrapperInter_t
{
#if (USE_ACDC_GLOB_INTER)
  ACDC_GlobDataInter_t     ACDC;
#endif
#if (ACDC_CFG_AIP && USE_AIP_GLOB_INTER)
  AIP_GlobDataInter_t      AIP;
#endif
#if (ACDC_CFG_ESPM && USE_ESPM_GLOB_INTER)
  ESPM_GlobDataInter_t     ESPM;
#endif
#if (ACDC_CFG_CD && USE_CD_GLOB_INTER)
  CD_GlobDataInter_t       CD;
#endif
#if (ACDC_CFG_EMP && USE_EMP_GLOB_INTER)
  EMP_GlobDataInter_t      EMP;
#endif
}ACDC_GlobDataWrapperInter_t;
#endif

#if (USE_ACDCWRAPPER_INTER)
typedef struct  ACDC_DataWrapperInter_t  
{
  uint32                          uVersion;
  SignalHeader_t                  sSigHeader;
#if (USE_ACDCWRAPPER_OBJ_INTER)
  ACDC_ObjDataWrapperInter_t  sObjData;
#endif
#if (USE_ACDCWRAPPER_GLOB_INTER)
  ACDC_GlobDataWrapperInter_t sGlobData;
#endif
}ACDC_DataWrapperInter_t;
#endif


/************************************************************************/
/* ACDC wrapper InterMeas types                                         */
/************************************************************************/

#if (USE_ACDCWRAPPER_OBJ_INTERMEAS)
typedef struct ACDC_ObjDataWrapperInterMeasHeader_t
{
  float32 Dummy;
}ACDC_ObjDataWrapperInterMeasHeader_t;

typedef struct ACDC_ObjDataWrapperInterMeasObj_t
{
#if (USE_ACDC_OBJ_INTERMEAS)
  ACDC_ObjInterMeas_t     ACDC;
#endif
#if (ACDC_CFG_AIP && USE_AIP_OBJ_INTERMEAS)
  AIP_ObjInterMeas_t      AIP;
#endif
#if (ACDC_CFG_ESPM && USE_ESPM_OBJ_INTERMEAS)
  ESPM_ObjInterMeas_t     ESPM;
#endif
#if (ACDC_CFG_CD && USE_CD_OBJ_INTERMEAS)
  CD_ObjInterMeas_t       CD;
#endif
#if (ACDC_CFG_EMP && USE_EMP_OBJ_INTERMEAS)
  EMP_ObjInterMeas_t      EMP;
#endif
}ACDC_ObjDataWrapperInterMeasObj_t;

typedef struct ACDC_ObjDataWrapperInterMeas_t
{
  ACDC_ObjDataWrapperInterMeasHeader_t sHeader;
  ACDC_ObjDataWrapperInterMeasObj_t    aObj[EM_N_OBJECTS];
}ACDC_ObjDataWrapperInterMeas_t;
#endif

#if (USE_ACDCWRAPPER_GLOB_INTERMEAS)
typedef struct ACDC_GlobDataWrapperInterMeas_t
{
#if (USE_ACDC_GLOB_INTERMEAS)
  ACDC_GlobDataInterMeas_t     ACDC;
#endif
#if (ACDC_CFG_AIP && USE_AIP_GLOB_INTERMEAS)
  AIP_GlobDataInterMeas_t      AIP;
#endif
#if (ACDC_CFG_ESPM && USE_ESPM_GLOB_INTERMEAS)
  ESPM_GlobDataInterMeas_t     ESPM;
#endif
#if (ACDC_CFG_CD && USE_CD_GLOB_INTERMEAS)
  CD_GlobDataInterMeas_t       CD;
#endif
#if (ACDC_CFG_EMP && USE_EMP_GLOB_INTERMEAS)
  EMP_GlobDataInterMeas_t      EMP;
#endif
}ACDC_GlobDataWrapperInterMeas_t;
#endif

#if (USE_ACDCWRAPPER_INTERMEAS)
typedef struct  ACDC_DataWrapperInterMeas_t  
{
  uint32                          uVersion;
  SignalHeader_t                  sSigHeader;
#if (USE_ACDCWRAPPER_OBJ_INTERMEAS)
  ACDC_ObjDataWrapperInterMeas_t  sObjData;
#endif
#if (USE_ACDCWRAPPER_GLOB_INTERMEAS)
  ACDC_GlobDataWrapperInterMeas_t sGlobData;
#endif
}ACDC_DataWrapperInterMeas_t;
#endif



/************************************************************************/
/* ACDC wrapper IntraMeas types                                         */
/************************************************************************/

#if (USE_ACDCWRAPPER_OBJ_INTRAMEAS)
typedef struct ACDC_ObjDataWrapperIntraMeasHeader_t
{
  float32 Dummy;
}ACDC_ObjDataWrapperIntraMeasHeader_t;

typedef struct ACDC_ObjDataWrapperIntraMeasObj_t
{
#if (USE_ACDC_OBJ_INTRAMEAS)
  ACDC_ObjIntraMeas_t     ACDC;
#endif
#if (ACDC_CFG_AIP && USE_AIP_OBJ_INTRAMEAS)
  AIP_ObjIntraMeas_t      AIP;
#endif
#if (ACDC_CFG_ESPM && USE_ESPM_OBJ_INTRAMEAS)
  ESPM_ObjIntraMeas_t     ESPM;
#endif
#if (ACDC_CFG_CD && USE_CD_OBJ_INTRAMEAS)
  CD_ObjIntraMeas_t       CD;
#endif
#if (ACDC_CFG_EMP && USE_EMP_OBJ_INTRAMEAS)
  EMP_ObjIntraMeas_t      EMP;
#endif
}ACDC_ObjDataWrapperIntraMeasObj_t;

typedef struct ACDC_ObjDataWrapperIntraMeas_t
{
  ACDC_ObjDataWrapperIntraMeasHeader_t sHeader;
  ACDC_ObjDataWrapperIntraMeasObj_t    aObj[EM_N_OBJECTS];
}ACDC_ObjDataWrapperIntraMeas_t;
#endif

#if (USE_ACDCWRAPPER_GLOB_INTRAMEAS)
typedef struct ACDC_GlobDataWrapperIntraMeas_t
{
#if (USE_ACDC_GLOB_INTRAMEAS)
  ACDC_GlobDataIntraMeas_t     ACDC;
#endif
#if (ACDC_CFG_AIP && USE_AIP_GLOB_INTRAMEAS)
  AIP_GlobDataIntraMeas_t      AIP;
#endif
#if (ACDC_CFG_ESPM && USE_ESPM_GLOB_INTRAMEAS)
  ESPM_GlobDataIntraMeas_t     ESPM;
#endif
#if (ACDC_CFG_CD && USE_CD_GLOB_INTRAMEAS)
  CD_GlobDataIntraMeas_t       CD;
#endif
#if (ACDC_CFG_EMP && USE_EMP_GLOB_INTRAMEAS)
  EMP_GlobDataIntraMeas_t      EMP;
#endif
}ACDC_GlobDataWrapperIntraMeas_t;
#endif

#if (USE_ACDCWRAPPER_INTRAMEAS)
typedef struct  ACDC_DataWrapperIntraMeas_t  
{
  SignalHeader_t                  sSigHeader;
#if (USE_ACDCWRAPPER_OBJ_INTRAMEAS)
  ACDC_ObjDataWrapperIntraMeas_t  sObjData;
#endif
#if (USE_ACDCWRAPPER_GLOB_INTRAMEAS)
  ACDC_GlobDataWrapperIntraMeas_t sGlobData;
#endif
}ACDC_DataWrapperIntraMeas_t;
#endif



/************************************************************************/
/* ACDC wrapper Intra types                                             */
/************************************************************************/

#if (USE_ACDCWRAPPER_OBJ_INTRA)
typedef struct ACDC_ObjDataWrapperIntraHeader_t
{
  float32 Dummy;
}ACDC_ObjDataWrapperIntraHeader_t;

typedef struct ACDC_ObjDataWrapperIntraObj_t
{
#if (USE_ACDC_OBJ_INTRA)
  ACDC_ObjIntra_t     ACDC;
#endif
#if (ACDC_CFG_AIP && USE_AIP_OBJ_INTRA)
  AIP_ObjIntra_t      AIP;
#endif
#if (ACDC_CFG_ESPM && USE_ESPM_OBJ_INTRA)
  ESPM_ObjIntra_t     ESPM;
#endif
#if (ACDC_CFG_CD && USE_CD_OBJ_INTRA)
  CD_ObjIntra_t       CD;
#endif
#if (ACDC_CFG_EMP && USE_EMP_OBJ_INTRA)
  EMP_ObjIntra_t      EMP;
#endif
}ACDC_ObjDataWrapperIntraObj_t;

typedef struct ACDC_ObjDataWrapperIntra_t
{
  ACDC_ObjDataWrapperIntraHeader_t sHeader;
  ACDC_ObjDataWrapperIntraObj_t    aObj[EM_N_OBJECTS];
}ACDC_ObjDataWrapperIntra_t;
#endif

#if (USE_ACDCWRAPPER_GLOB_INTRA)
typedef struct ACDC_GlobDataWrapperIntra_t
{
#if (USE_ACDC_GLOB_INTRA)
  ACDC_GlobDataIntra_t     ACDC;
#endif
#if (ACDC_CFG_AIP && USE_AIP_GLOB_INTRA)
  AIP_GlobDataIntra_t      AIP;
#endif
#if (ACDC_CFG_ESPM && USE_ESPM_GLOB_INTRA)
  ESPM_GlobDataIntra_t     ESPM;
#endif
#if (ACDC_CFG_CD && USE_CD_GLOB_INTRA)
  CD_GlobDataIntra_t       CD;
#endif
#if (ACDC_CFG_EMP && USE_EMP_GLOB_INTRA)
  EMP_GlobDataIntra_t      EMP;
#endif
}ACDC_GlobDataWrapperIntra_t;
#endif

#if (USE_ACDCWRAPPER_INTRA)
typedef struct  ACDC_DataWrapperIntra_t  
{
  SignalHeader_t                  sSigHeader;
#if (USE_ACDCWRAPPER_OBJ_INTRA)
  ACDC_ObjDataWrapperIntra_t  sObjData;
#endif
#if (USE_ACDCWRAPPER_GLOB_INTRA)
  ACDC_GlobDataWrapperIntra_t sGlobData;
#endif
}ACDC_DataWrapperIntra_t;
#endif


#ifdef ACDC_SIMU
/************************************************************************/
/* ACDC wrapper Simu types                                              */
/************************************************************************/

#if (USE_ACDCWRAPPER_OBJ_SIMU)
typedef struct ACDC_ObjDataWrapperSimuHeader_t
{
  float32 Dummy;
}ACDC_ObjDataWrapperSimuHeader_t;

typedef struct ACDC_ObjDataWrapperSimuObj_t
{
#if (USE_ACDC_OBJ_SIMU)
  ACDC_ObjSimu_t     ACDC;
#endif
#if (ACDC_CFG_AIP && USE_AIP_OBJ_SIMU)
  AIP_ObjSimu_t      AIP;
#endif
#if (ACDC_CFG_ESPM && USE_ESPM_OBJ_SIMU)
  ESPM_ObjSimu_t     ESPM;
#endif
#if (ACDC_CFG_CD && USE_CD_OBJ_SIMU)
  CD_ObjSimu_t       CD;
#endif
#if (ACDC_CFG_EMP && USE_EMP_OBJ_SIMU)
  EMP_ObjSimu_t      EMP;
#endif
}ACDC_ObjDataWrapperSimuObj_t;

typedef struct ACDC_ObjDataWrapperSimu_t
{
  ACDC_ObjDataWrapperSimuHeader_t sHeader;
  ACDC_ObjDataWrapperSimuObj_t    aObj[EM_N_OBJECTS];
}ACDC_ObjDataWrapperSimu_t;
#endif

#if (USE_ACDCWRAPPER_GLOB_SIMU)
typedef struct ACDC_GlobDataWrapperSimu_t
{
#if (USE_ACDC_GLOB_SIMU)
  ACDC_GlobDataSimu_t     ACDC;
#endif
#if (ACDC_CFG_AIP && USE_AIP_GLOB_SIMU)
  AIP_GlobDataSimu_t      AIP;
#endif
#if (ACDC_CFG_ESPM && USE_ESPM_GLOB_SIMU)
  ESPM_GlobDataSimu_t     ESPM;
#endif
#if (ACDC_CFG_CD && USE_CD_GLOB_SIMU)
  CD_GlobDataSimu_t       CD;
#endif
#if (ACDC_CFG_EMP && USE_EMP_GLOB_SIMU)
  EMP_GlobDataSimu_t      EMP;
#endif
}ACDC_GlobDataWrapperSimu_t;
#endif

#if (USE_ACDCWRAPPER_SIMU)
typedef struct  ACDC_DataWrapperSimu_t  
{
  SignalHeader_t             sSigHeader;
#if (USE_ACDCWRAPPER_OBJ_SIMU)
  ACDC_ObjDataWrapperSimu_t  sObjData;
#endif
#if (USE_ACDCWRAPPER_GLOB_SIMU)
  ACDC_GlobDataWrapperSimu_t sGlobData;
#endif
}ACDC_DataWrapperSimu_t;
#endif
#endif /* ACDC_SIMU */

/************************************************************************/
/* Data access types                                                    */
/************************************************************************/

/*! @brief Structure which contains pointers to all input structures used in ACDC */
typedef struct ACDC_Input_t 
{
  reqACDCPrtList_t    ReqPorts; /*!< Use a copy of the pointer list here. Using a copy instead of a pointer here, is necessary because otherwise the data access in the draw function is not possible (req port pointer becomes invalid if FCTSen_Exec is left, but not the contained memory addresses). */
#if (FCT_CFG_USE_SERVICE_POINTER_FUNCTS)
  AS_t_ServiceFuncts  ServiceFuncts;
#endif
} ACDC_Input_t;

/*! @brief Structure which contains pointers to all output structures used in ACDC */
typedef struct ACDC_Output_t 
{
  provACDCPrtList_t ProPorts; /*!< Use a copy of the pointer list here. Using a copy instead of a pointer here, is necessary because otherwise the data access in the draw function is not possible (pro port pointer becomes invalid if FCTSen_Exec is left, but not the contained memory addresses). */
} ACDC_Output_t;

/*! @brief Structure which contains pointers to the different memory types used in ACDC */
typedef struct ACDC_Working_t
{
#if USE_ACDCWRAPPER_STACK
  ACDC_DataWrapperStack_t      * pStackData;
#endif
#if (USE_ACDCWRAPPER_INTER)
  ACDC_DataWrapperInter_t      * pInterCycle;
#endif
#if (USE_ACDCWRAPPER_INTERMEAS)
  ACDC_DataWrapperInterMeas_t  * pInterCycleMeas;
#endif
#if (USE_ACDCWRAPPER_INTRA)
  ACDC_DataWrapperIntra_t      * pIntraCycle;
#endif
#if (USE_ACDCWRAPPER_INTRAMEAS)
  ACDC_DataWrapperIntraMeas_t  * pIntraCycleMeas;
#endif
#ifdef ACDC_SIMU
#if (USE_ACDCWRAPPER_SIMU)
  ACDC_DataWrapperSimu_t       * pSimuData;
#endif
#endif
} ACDC_Working_t;

/*! @brief Structure which contains pointers to all data structures used in ACDC. \n
An instance of this structure is used to grant access in the complete code. */
typedef struct ACDCAccessData_t 
{
  ACDC_Input_t       Input;
  ACDC_Working_t     Working;
  ACDC_Output_t      Output;
} ACDCAccessData_t;

/*!@}*/ 





/*! @}*/
#endif /* ACDC_CFG_FRAME */

#endif
