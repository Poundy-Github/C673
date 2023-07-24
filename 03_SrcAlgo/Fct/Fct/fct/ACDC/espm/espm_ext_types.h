/*! \file **********************************************************************

COMPANY:                   COPYRIGHT (C) Continental AG
  
PROJECT:                   Mainstream

CPU:                       CPU-Independent

COMPONENT:                 ESPM (EBA Signal Performance Monitoring)

PACKAGENAME:               ESPM_ext_types.h

DESCRIPTION:               Typdefs of the ESPM subcomonent, which shall be usable in the complete ACDC component.

AUTHOR:                    $Author: uidn4751 $

CREATION DATE:             $Date: 2019/06/03 15:27:31CEST $

VERSION:                   $Revision: 1.3 $
**************************************************************************** */

#ifndef ESPM_TYPES_INCLUDED
#define ESPM_TYPES_INCLUDED



/*****************************************************************************
  INCLUDES
*****************************************************************************/
#include "espm_par.h"


#ifdef __cplusplus
extern "C" {
#endif

#if (ACDC_CFG_ESPM)

/*****************************************************************************
  MODULE DESCRIPTION
*****************************************************************************/
/**
@addtogroup espm
@{ */

#define USE_ESPM_OBJ_STACK           SWITCH_OFF
#define USE_ESPM_GLOB_STACK          SWITCH_OFF

#define USE_ESPM_OBJ_INTER           SWITCH_OFF
#define USE_ESPM_GLOB_INTER          SWITCH_OFF

#define USE_ESPM_OBJ_INTERMEAS       SWITCH_OFF
#define USE_ESPM_GLOB_INTERMEAS      SWITCH_OFF

#define USE_ESPM_OBJ_INTRAMEAS       SWITCH_OFF
#define USE_ESPM_GLOB_INTRAMEAS      SWITCH_OFF

#define USE_ESPM_OBJ_INTRA           SWITCH_OFF
#define USE_ESPM_GLOB_INTRA          SWITCH_ON

#define USE_ESPM_OBJ_SIMU            SWITCH_OFF
#define USE_ESPM_GLOB_SIMU           SWITCH_OFF

/*****************************************************************************
  TYPEDEFS 
*****************************************************************************/
/* Degradation data */
/*! @brief     Data Type to describe maximal lateral safety or performance distances*/
typedef struct 
{
  float32 f_MaxLatDist;       /*!<Maximum Lateral Distance. @phys_unit [m]*/
  float32 f_MaxLatDistALN;    /*!<Maximum Lateral Distance according to the alignment. @phys_unit [m]*/
  float32 f_MaxLatDistVDY;    /*!<Maximum Lateral Distance according to VDY. @phys_unit [m]*/
} ESPM_ThresQuotas_t;

/*! @brief     Data Type to describe maximal safety or performance distances*/
typedef struct 
{
  float32 f_MaxQuotaALN; /*!<Maximum Quota according to the alignment.*/
  float32 f_MaxQuotaVDY; /*!<Maximum Quota according to VDY. */
  float32 f_MaxLatDist;  /*!<Maximum Lateral Distance. @phys_unit [m]*/
} ESPM_Quotas_t;

/*! @brief     Data Type to describe maximal safety or performance distances*/
typedef struct 
{
  float32 f_MaxDistALN; /*!<Maximum Distance according to the alignment. @phys_unit [m]*/
  float32 f_MaxDistVDY; /*!<Maximum Distance according to VDY. @phys_unit [m]*/
  float32 f_MaxDistELV; /*!<Maximum Distance according to ELV. @phys_unit [m]*/
  float32 f_MaxDist;    /*!<Maximum Overall Distance. @phys_unit [m]*/
} ESPM_MaxDist_t;

/*! @brief     Data Type to describe the current degradation state*/
typedef struct
{
  ESPM_MaxDist_t  DegrDistSafe;     /*!Current degradation state regarding Safety functions */
  ESPM_MaxDist_t  DegrDistPerf;     /*!Current degradation state regarding Performance functions */
  fDistance_t     f_MaxDistPerfMin;
  ESPM_Quotas_t   QuotasSafe;       /*!Quotas of the Safety degradation state*/
  ESPM_Quotas_t   QuotasPerf;       /*!Quotas of the Performance degradation state*/
  boolean         b_LoudDegrdation; /*!Flag indicating whether the degradation will be reported to the driver or not*/
}ESPM_Degradation_t;

/*! @brief     Data Type contains all relevant information for the Degradation calculation*/
typedef struct
{
  ESPM_Degradation_t DegradationEBA; /*!Current EBA Degradation state*/
  float32 EBABlockageRange;          /*!Blockage range of the Eba function. @phys_unit [m] */
#if (ESPM_CFG_USE_SPM_OUTPUT)
  SYSDampState_t EBABlockageState;
#endif
}PerformanceDegrationData_t;


/************************************************************************/
/* ESPM Stack types                                                     */
/************************************************************************/
/* ESPM object data */
#if (USE_ESPM_OBJ_STACK)
typedef struct  ESPM_ObjStack_t  
{

}ESPM_ObjStack_t;
#endif /* USE_ESPM_OBJ_STACK */

/* ESPM global data */
#if (USE_ESPM_GLOB_STACK)
typedef struct  ESPM_GlobDataStack_t  
{
}ESPM_GlobDataStack_t;
#endif /* USE_ESPM_GLOB_STACK */

/************************************************************************/
/* ESPM Inter types                                                     */
/************************************************************************/
/* ESPM object data */
#if (USE_ESPM_OBJ_INTER)
typedef struct  ESPM_ObjInter_t  
{

}ESPM_ObjInter_t;
#endif /* USE_ESPM_OBJ_INTER */

/* ESPM global data */
#if (USE_ESPM_GLOB_INTER)
typedef struct  ESPM_GlobDataInter_t  
{

}ESPM_GlobDataInter_t;
#endif /* USE_ESPM_GLOB_INTER */

/************************************************************************/
/* ESPM InterMeas types                                                 */
/************************************************************************/
/* ESPM object data */
#if (USE_ESPM_OBJ_INTERMEAS)
typedef struct  ESPM_ObjInterMeas_t  
{

}ESPM_ObjInterMeas_t;
#endif /* USE_ESPM_OBJ_INTERMEAS */

/* ESPM global data */
#if (USE_ESPM_GLOB_INTERMEAS)
typedef struct  ESPM_GlobDataInterMeas_t  
{

}ESPM_GlobDataInterMeas_t;
#endif /* USE_ESPM_GLOB_INTERMEAS */



/************************************************************************/
/* ESPM IntraMeas types                                                 */
/************************************************************************/
/* ESPM object data */
#if (USE_ESPM_OBJ_INTRAMEAS)
typedef struct  ESPM_ObjIntraMeas_t  
{

}ESPM_ObjIntraMeas_t;
#endif /* USE_ESPM_OBJ_INTRAMEAS */

/* ESPM global data */
#if (USE_ESPM_GLOB_INTRAMEAS)
typedef struct  ESPM_GlobDataIntraMeas_t  
{

}ESPM_GlobDataIntraMeas_t;
#endif /* USE_ESPM_GLOB_INTRAMEAS */



/************************************************************************/
/* ESPM Intra types                                                     */
/************************************************************************/
/* ESPM object data */
#if (USE_ESPM_OBJ_INTRA)
typedef struct  ESPM_ObjIntra_t  
{

}ESPM_ObjIntra_t;
#endif /* USE_ESPM_OBJ_INTRA */

/* ESPM global data */
#if (USE_ESPM_GLOB_INTRA)
typedef struct  ESPM_GlobDataIntra_t  
{
  PerformanceDegrationData_t sPerformanceDegrationData;
}ESPM_GlobDataIntra_t;
#endif /* USE_ESPM_GLOB_INTRA */


#ifdef ACDC_SIMU
/************************************************************************/
/* ESPM Simu types                                                      */
/************************************************************************/
/* ESPM object data */
#if (USE_ESPM_OBJ_SIMU)
typedef struct  ESPM_ObjSimu_t  
{

}ESPM_ObjSimu_t;
#endif /* USE_ESPM_OBJ_SIMU */

/* ESPM global data */
#if (USE_ESPM_GLOB_SIMU)
typedef struct  ESPM_GlobDataSimu_t  
{

}ESPM_GlobDataSimu_t;
#endif /* USE_ESPM_GLOB_SIMU */
#endif /* ACDC_SIMU */

///@}
#else /*!< ACDC_CFG_ESPM */

#define USE_ESPM_OBJ_STACK           SWITCH_OFF
#define USE_ESPM_GLOB_STACK          SWITCH_OFF

#define USE_ESPM_OBJ_INTER           SWITCH_OFF
#define USE_ESPM_GLOB_INTER          SWITCH_OFF

#define USE_ESPM_OBJ_INTERMEAS       SWITCH_OFF
#define USE_ESPM_GLOB_INTERMEAS      SWITCH_OFF

#define USE_ESPM_OBJ_INTRAMEAS       SWITCH_OFF
#define USE_ESPM_GLOB_INTRAMEAS      SWITCH_OFF

#define USE_ESPM_OBJ_INTRA           SWITCH_OFF
#define USE_ESPM_GLOB_INTRA          SWITCH_OFF

#define USE_ESPM_OBJ_SIMU            SWITCH_OFF
#define USE_ESPM_GLOB_SIMU           SWITCH_OFF

#endif /*!< ACDC_CFG_ESPM */

#ifdef __cplusplus
};
#endif

/* End of conditional inclusion */
#endif  /*!< ESPM_INCLUDED */

