/*! \file **********************************************************************

  COMPANY:                Continental Temic, PC DAS, A.D.C. GmbH

  PROJECT:                All

  CPU:                    All

  COMPONENT:              RTE

  MODULNAME:              algo_glob.h

  DESCRIPTION:            


  CREATION DATE:          11.09.2007

  VERSION:                $Revision: 1.8 $

  ---*/ /*---
  CHANGES:                   $Log: algo_type.h  $
  CHANGES:                   Revision 1.8 2013/08/01 16:41:37CEST Eisenacher, Michael (eisenacherm) 
  CHANGES:                   included rte_common.h
  CHANGES:                   - Added comments -  eisenacherm [Aug 1, 2013 4:41:38 PM CEST]
  CHANGES:                   Change Package : 180551:1 http://mks-psad:7002/im/viewissue?selection=180551
  CHANGES:                   Revision 1.7 2013/07/25 08:27:00CEST Eisenacher, Michael (eisenacherm) 
  CHANGES:                   merged ARS400 and SRR300 with compiler switches
  CHANGES:                   --- Added comments ---  eisenacherm [Jul 25, 2013 8:27:00 AM CEST]
  CHANGES:                   Change Package : 180551:1 http://mks-psad:7002/im/viewissue?selection=180551
  CHANGES:                   Revision 1.6 2013/07/09 17:10:56CEST Fuentes, Juan-Carlos (uidu2446) 
  CHANGES:                   - added type ubit32 for backwards compatibility.
  CHANGES:                   --- Added comments ---  uidu2446 [Jul 9, 2013 5:10:57 PM CEST]
  CHANGES:                   Change Package : 187998:1 http://mks-psad:7002/im/viewissue?selection=187998
  CHANGES:                   Revision 1.5 2013/05/21 10:10:22CEST Foelster, Florian (foelsterf) 
  CHANGES:                   remove old class definition GDBObjectClass_t
  CHANGES:                   - in EM internal replaced by eClassification_t
  CHANGES:                   - at EM - FCT (NORM) interface replaced by EM_t_ARS_Classification
  CHANGES:                   --- Added comments ---  foelsterf [May 21, 2013 10:10:22 AM CEST]
  CHANGES:                   Change Package : 182066:5 http://mks-psad:7002/im/viewissue?selection=182066
  CHANGES:                   Revision 1.4 2013/03/12 09:22:37CET Ungvary, Gergely (ungvaryg) 
  CHANGES:                   Remove FCT-only types (moved to fct_types.h header file revision 1.5)
  CHANGES:                   --- Added comments ---  ungvaryg [Mar 12, 2013 9:22:37 AM CET]
  CHANGES:                   Change Package : 176952:1 http://mks-psad:7002/im/viewissue?selection=176952
  CHANGES:                   Revision 1.3 2013/02/05 10:28:48CET Oprisan, Dan (oprisand) 
  CHANGES:                   - add/correct file header
  CHANGES:                   --- Added comments ---  oprisand [Feb 5, 2013 10:28:49 AM CET]
  CHANGES:                   Change Package : 139701:25 http://mks-psad:7002/im/viewissue?selection=139701
                  
**************************************************************************** */
#ifndef ALGO_TYPE_HE_INCLUDED
#define ALGO_TYPE_HE_INCLUDED

/*****************************************************************************
  INCLUDES
*****************************************************************************/

#include "algo_cfg.h"
#include "algo_sensor_params.h"
#include "Rte_Common.h"

/*****************************************************************************
  MACROS 
*****************************************************************************/

/*****************************************************************************
  (SYMBOLIC) CONSTANTS 
*****************************************************************************/

/*****************************************************************************
  TYPEDEFS
*****************************************************************************/

typedef UInt8 ui8_t;
typedef UInt16 ui16_t;
typedef UInt32 ui32_t;

typedef SInt8  i8_t;
typedef SInt16 i16_t;
typedef SInt32 i32_t;

typedef Flt32 f32_t;
typedef Boolean bool_t;
#ifdef __cplusplus
typedef bool boolean_t;
#endif

typedef signed int      sbit32_t;
typedef signed short    sbit16_t;
typedef signed char     sbit8_t;
typedef unsigned int    ubit32_t;
typedef unsigned short  ubit16_t;
typedef unsigned char   ubit8_t;

#define ubit32 ubit32_t
/*! Pointer to unsigned 32 bit value */
typedef ui32_t * pui32_t;

typedef ui8_t     enum_t;

/* Defines used by FCT */
#define False                 (0u)
#define True                  (1u)

#define Pi                    ((angle_t)31416)

#define Speed_conv_factor_mph ((factor_t)2237)
#define Speed_conv_factor_kmh ((factor_t)3600)

/* ------------- basic types ---------------------- */
/*! Angle in degrees! @todo: verify if this is realy needed, if not unify used
angles in code to radians and use fAngle_t type instead! @unit:° */
typedef fAngle_t fDegAngle_t;

/*! Object lifetime type. Note: use macros CONV_CYCLES_TO_LIFETIME and CONV_TIME_TO_LIFETIME
to convert between lifetime and cycles/time representation @unit:s @resolution: 0.066 */
typedef ui16_t GDBLifeTime_t;

#if ALGO_ARS400Sensor
  typedef eTrafficOrientation_t GDBTrafficOrientation_t;
  typedef eLaneWidthClass_t GDBLaneWidthClass_t;
#endif

typedef RoadEstimation_t GDBRoadEstimation_t;

/*! Reflektionsquerschnittstyp */
typedef f32_t RADRRCS_t;

/*! ACC object quality. Objects below FUN_PRESEL_ACC_MIN_OBJ_QUAL are
not taken into account in ACC object selection. Objects below
FUN_PRESEL_ACC_MIN_INLANE_OBJ_QUAL can not be selected as in-lane
objects @min:0 @max:100 */
typedef ucConfidence_t ACCObjectQuality_t;

/* roadbeam data */
typedef struct
{
  i8_t   SPMRoadVisibility;           /* (0...100) */
  i8_t   SPMRoadVisibilityQuality;    /* (0...100) */
  i8_t   SPMSensorTilted;             /* (0, 1) */
} GDBRoadbeam_t;

/*! Percentage:  Range 0 .. 100
@description:  Percentage
@resolution: 1        @unit: [%]
@min: 0          @max: 100 */
/* percentage_t now generated by Cessar */
/*typedef UInt8 percentage_t;*/     /*%unit:%*/
#define Percentage_s Scale_1
#ifndef Percentage_min
#define Percentage_min (0U)
#endif
#ifndef Percentage_max
#define Percentage_max (100U)
#endif

/*! Switch Far-NearRange */
typedef enum 
{
  /*! FarRange */    
  RSP_ANT_FAR = 0,          
  /*! NearRange */    
  RSP_ANT_NEAR = 1
} eRSPAntennaFarNear_t;

#ifdef HINWEIS
#pragma message(__FILE__"("STRING_QUOTE(__LINE__)"): add the folowing struct to the xls file")
#endif

/*! Forward looking sensor speed reference interface sizes */
#define REF_SPEED_MIN_RATIO        0.6F         /*< Minimum ratio of target velocity to uncorrected ego velocity */
#define REF_SPEED_MAX_RATIO        1.4F         /*< Maximum ratio of target velocity to uncorrected ego velocity */
//#define REF_SPEED_NO_BINS          81uL         /*< Number of bins containing occurrences of sampled ratios   */

/*! Alias for velocity */
typedef fVelocity_t fSpeed_t;

/*! @todo: New algo base types only declares fAccel_t, on long run transition code to that type! */
typedef fAccel_t fAcceleration_t;


#define IS_SIGNAL_STATUS_OK(status)     (status == VDY_IO_STATE_VALID)

#endif
