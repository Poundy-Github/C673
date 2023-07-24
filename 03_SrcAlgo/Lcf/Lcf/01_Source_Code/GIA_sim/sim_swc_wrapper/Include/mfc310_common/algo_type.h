/*! \file **********************************************************************

  COMPANY:                Continental Temic, PC DAS, A.D.C. GmbH

  PROJECT:                All

  CPU:                    All

  COMPONENT:              RTE

  MODULNAME:              algo_glob.h

  DESCRIPTION:            


  CREATION DATE:          11.09.2007

  VERSION:                $Revision: 1.1 $

                  
  ---*/ /*---
  CHANGES:                $Log: algo_type.h  $
  CHANGES:                Revision 1.1 2021/12/13 17:24:42CET Wang, David (Wangd3) 
  CHANGES:                Initial revision
  CHANGES:                Member added to project /ADAS/Projects/MFC5xx/MFC5J3/06_Algorithm/DPU/04_Engineering/01_Source_Code/GIA_sim/sim_swc_wrapper/Include/mfc310_common/project.pj
  CHANGES:                Revision 1.0 2017/03/03 10:35:38CET Sorge, Sven (uidg3181) 
  CHANGES:                Initial revision
  CHANGES:                Member added to project /ADAS/SW/Integration/06_Simulation_Components/GIA_GenericInterfaceAdapter/04_Engineering/03_Workspace/Component_Workspace/GIA_sim/sim_swc_wrapper/Include/mfc310_common/project.pj
  CHANGES:                Revision 1.1 2014/03/13 15:11:13CET Sorge, Sven (uidg3181) 
  CHANGES:                Initial revision
  CHANGES:                Member added to project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/ETK_EngineeringToolKit/04_Engineering/GIA_GenericInterfaceAdapter/04_Engineering/03_Workspace/algo/gia_sim/wrapper/Include/mfc310_common/project.pj
  CHANGES:                Revision 1.1.1.2 2010/06/15 14:36:29CEST jfuehrman 
  CHANGES:                removed unnecessary colons
  CHANGES:                --- Added comments ---  jfuehrman [2010/06/15 12:36:29Z]
  CHANGES:                Change Package : 45222:1 http://LISS014:6001/im/viewissue?selection=45222
  CHANGES:                Revision 1.1.1.1 2010/04/13 12:30:46CEST jfuehrman 
  CHANGES:                removed typedefs based on missing types
  CHANGES:                --- Added comments ---  jfuehrman [2010/04/13 10:30:47Z]
  CHANGES:                Change Package : 36194:1 http://LISS014:6001/im/viewissue?selection=36194
  CHANGES:                Revision 1.11 2010/03/24 17:39:14CET Jochen Spruck (jspruck) 
  CHANGES:                - seperate sim reset and int functions for em and fct
  CHANGES:                - move GED_CYCLE_TIME to EmFctCycleMode
  CHANGES:                --- Added comments ---  jspruck [2010/03/24 16:39:14Z]
  CHANGES:                Change Package : 33263:4 http://LISS014:6001/im/viewissue?selection=33263
  CHANGES:                Revision 1.10 2010/03/24 11:16:41CET gungvary 
  CHANGES:                Move CFG_USE_COMPACT_ENUMS switch to algo_cfg.h
  CHANGES:                Include algo_cfg.h in algo_glob.h and algo_type.h
  CHANGES:                Move SWITCH_ON and SWITCH_OFF definitions to algo_cfg.h, to assure that the corresponding defines
  CHANGES:                are always set, prior to any other definitions.
  CHANGES:                --- Added comments ---  gungvary [2010/03/24 10:16:41Z]
  CHANGES:                Change Package : 39685:1 http://LISS014:6001/im/viewissue?selection=39685
  CHANGES:                Revision 1.9 2010/03/10 13:25:34CET gungvary 
  CHANGES:                Move CFG_USE_COMPACT_ENUMS from algo_glob.h to algo_type.h (since already referenced there)
  CHANGES:                --- Added comments ---  gungvary [2010/03/10 12:25:34Z]
  CHANGES:                Change Package : 33458:1 http://LISS014:6001/im/viewissue?selection=33458
  CHANGES:                Revision 1.8 2010/02/12 15:09:45CET gungvary 
  CHANGES:                Remove commented out type GDBObjNumber_t (no longer needed anyway) - since use of undefined macros in comments for it lead to warnings
  CHANGES:                from PDO-tools
  CHANGES:                --- Added comments ---  gungvary [2010/02/12 14:09:45Z]
  CHANGES:                Change Package : 33458:1 http://LISS014:6001/im/viewissue?selection=33458
  CHANGES:                Revision 1.7 2010/01/25 16:14:34CET Jochen Spruck (jspruck) 
  CHANGES:                typedef fRSPRcsLog_t fReqSmallTarThres_t moved to rte_type.h
  CHANGES:                --- Added comments ---  jspruck [2010/01/25 15:14:35Z]
  CHANGES:                Change Package : 33263:2 http://LISS014:6001/im/viewissue?selection=33263
  CHANGES:                Revision 1.6 2010/01/12 14:13:39CET gungvary 
  CHANGES:                Remove types now already defined in rte_type.h (multiple definitions being problematic)
  CHANGES:                --- Added comments ---  gungvary [2010/01/12 13:13:39Z]
  CHANGES:                Change Package : 33458:1 http://LISS014:6001/im/viewissue?selection=33458
  CHANGES:                Revision 1.5 2010/01/07 13:52:14CET gungvary 
  CHANGES:                Merge revision 1.3's changes back into trunk
  CHANGES:                --- Added comments ---  gungvary [2010/01/07 12:52:15Z]
  CHANGES:                Change Package : 33458:1 http://LISS014:6001/im/viewissue?selection=33458
  CHANGES:                Revision 1.4 2009/12/17 15:20:20CET Jochen Spruck (jspruck) 
  CHANGES:                Update algo_glob.h and algo_type.h to new rte interface
  CHANGES:                --- Added comments ---  jspruck [2009/12/17 14:20:20Z]
  CHANGES:                Change Package : 33263:2 http://LISS014:6001/im/viewissue?selection=33263
  CHANGES:                Revision 1.2 2009/12/11 18:37:05CET gungvary 
  CHANGES:                Add temporary defines & types needed to get FCT to compile
  CHANGES:                --- Added comments ---  gungvary [2009/12/11 17:37:05Z]
  CHANGES:                Change Package : 33458:1 http://LISS014:6001/im/viewissue?selection=33458
  CHANGES:                Revision 1.1 2009/12/09 15:36:31CET Jochen Spruck (jspruck) 
  CHANGES:                Initial revision
  CHANGES:                Member added to project /nfs/projekte1/PROJECTS/ARS301/05_Software/04_Engineering/01_Source_Code/rte/project.pj


**************************************************************************** */
#ifndef ALGO_TYPE_HE_INCLUDED
#define ALGO_TYPE_HE_INCLUDED

/*****************************************************************************
  INCLUDES
*****************************************************************************/

#include "algo_cfg.h"

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

typedef signed int      sbit32_t;
typedef signed short    sbit16_t;
typedef signed char     sbit8_t;
typedef unsigned int    ubit32_t;
typedef unsigned short  ubit16_t;
typedef unsigned char   ubit8_t;

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

/*! Trace index type @min:0 @maximum:TRACE_NO_OF_TRACES */
typedef ui8_t GDBTraceID_t;

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
#define Percentage_min (0)
#define Percentage_max (100)

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
#define REF_SPEED_NO_BINS          81uL         /*< Number of bins containing occurrences of sampled ratios   */

/*! Alias for velocity */
typedef fVelocity_t fSpeed_t;

/*! @todo: New algo base types only declares fAccel_t, on long run transition code to that type! */
typedef fAccel_t fAcceleration_t;

/*! blockage data definition @todo: move to rte_type.h! */
typedef enum {
  GDB_PD_OFF                      = 0,
  GDB_PD_ON                       = 1,
  GDB_PD_STARTUP                  = 2,
  GDB_PD_ROADBEAM_TEST            = 3
} eGDBPDStates_t;

#if (CFG_USE_COMPACT_ENUMS)
typedef ui8_t GDBPDStates_t;      /*!< using 8bit type for the real enum (32bit type) eGDBPDStates_t to save memory*/
#else
typedef eGDBPDStates_t GDBPDStates_t;
#endif

/*! selftest data @todo: clarify if supersseded by PerfDegr_t or move to rte_type.h! */
typedef struct
{
  f32_t  SPMSelftestRangeMov;             /* [m] */
  f32_t  SPMSelftestRangeMovConf;         /* (0...1) */
  f32_t  SPMSelftestRangeSta;             /* [m] */
  f32_t  SPMSelftestRangeStaMax;          /* [m] */
  f32_t  SPMSelftestRangeStaConf;         /* (0...1) */
} GDBSelftest_t; 


/* ----------- dm hypothesis type --------------------*/
/*! enum to define labels for driver monitoring Hypothesis types */
typedef enum
{
  GDB_DMHypothesisType_No               = 0u,      /*!< empty hypothesis*/
  GDB_DMHypothesisType_Feedback         = 1u,      /*!< driver feedback - value -100: strong negative feedback, +100 strong positive feedback*/
  GDB_DMHypothesisType_Activity         = 2u,      /*!< driver activity - value 0: no activity, 100: high activity*/
  GDB_DMHypothesisType_Attention        = 3u,      /*!< driver attention - value -100: distracted, +100: high attention*/
  GDB_DMHypothesisType_LaneChangeLeft   = 4u,      /*!< driver wants to change the lane to the left - value 0: no lane change, 100: high probability*/
  GDB_DMHypothesisType_LaneChangeRight  = 5u,      /*!< driver wants to change the lane to the right - value 0: no lane change, 100: high probability*/
  GDB_DMHypothesisType_Drowsieness      = 6u,      /*!< driver is drowsy: 0: low probability, 100: high probability*/
  GDB_DMHypothesisType_Overtake         = 7u,      /*!< driver plans to overtake: 0: driver will not overtake, driver will overtake*/
  
  GDB_DMHypothesisType_Max              = 8u       /*!< counter for the enum*/
} eGDB_DMHypothesisType_t;

#if (CFG_USE_COMPACT_ENUMS)
typedef ui8_t GDB_DMHypothesisType_t;              /*!< using 8bit type for the real enum (32bit type) eGDB_CDHypothesisType_t to save memory*/
#else
typedef eGDB_DMHypothesisType_t GDB_DMHypothesisType_t;
#endif



/*! typedef for CD hypothesis data */
typedef struct 
{     
  i8_t                       Probability;          /*!< -100 -> +100%*/
  percentage_t               Confidence;           /*!< hypothesis confidence*/  
  GDB_DMHypothesisType_t     eType;                /*!< type of the hypothesis (see eGDB_DMHypothesisType_t)*/
} GDB_DMHypothesis_t;

/* ----------- cd hypothesis type --------------------*/

/*! enum to define labels for Hypothesis types @todo: move to rte_type.h! */
typedef enum
{
  GDB_CDHypothesis_No                   = 0u,      /*!<empty hypothesis*/
  GDB_CDHypothesis_RunUp                = 1u,      /*!<run up hypothesis - critical situation where the object is slower than the host*/
  GDB_CDHypothesis_RunUpBraking         = 2u,      /*!<run up braking hypothesis - critical situation where the object is braking*/
  GDB_CDHypothesis_RunUpStationary      = 3u,      /*!<run up stationary hypothesis - critical situation where the object is stationary*/
  GDB_CDHypothesis_Static               = 4u,      /*!<static hypothesis - critical situation due to very close headway*/
  GDB_CDHypothesis_Acc                  = 5u,      /*!<acc hypothesis - in case the relevant object is braking, it could become critical*/
  GDB_CDHypothesis_Pass                 = 6u,      /*!<pass hypothesis - critical because of passing a slower object at low lateral distance*/
  GDB_CDHypothesis_CutIn                = 7u,      /*!<cut in hypothesis - critical situation due to an object thats cutting into the host path*/
  GDB_CDHypothesis_Collision            = 8u,      /*!<collision hypothesis - very critical situation that will lead into a collision*/
  GDB_CDHypothesis_CollisionUnavoidable = 9u,      /*!<collision hypothesis - very critical situation that will definitely lead into a collision*/

  GDB_CDHypothesis_Max                  = 10u      /*!<counter for the enum*/
} eGDB_CDHypothesisType_t;

#if (CFG_USE_COMPACT_ENUMS)
typedef ui8_t GDBCDHypothesisType_t;              /*!< using 8bit type for the real enum (32bit type) eGDB_CDHypothesisType_t to save memory*/
#else
typedef eGDB_CDHypothesisType_t GDBCDHypothesisType_t;
#endif

/*! typedef for CD hypothesis data @todo: move to rte_type.h */
typedef struct 
{   
  f32_t                      fTTBPre;                /*!< The TTBPre (depending on hypothesis type) */  
  f32_t                      fTTBAcute;              /*!< The TTBAcute (depending on hypothesis type) */  
  f32_t                      fTTSPre;                /*!< The TTSPre (depending on hypothesis type) */  
  f32_t                      fTTSAcute;              /*!< The TTSAcute (depending on hypothesis type) */  
  f32_t                      fTTC;                   /*!< The Time To Collision*/  
  f32_t                      fLongNecAccel;          /*!< The needed longitudinal deceleration to avoid a collision */  
  f32_t                      fLatNecAccel;           /*!< The needed lateral deceleration to avoid a collision */  
  f32_t                      fClosingVelocity;       /*!< closing velocity at time to collision*/ 
  f32_t                      fDistX;                 /*!< current longitudinal distance of the relevant hypothesis object*/
  ui8_t                      uiHypothesisProbability;/*!< probability of the classification */
  ui8_t                      uiObjectProbability;    /*!< probability of the object*/
  ui8_t                      uiObjectRef;            /*!< reference to the object*/  
  GDBCDHypothesisType_t      eType;                  /*!< type of the hypothesis (see eApiaHypothesisType_t)*/
/* !!! needed?? then we also need stopped information eDynamicProperty_t         eDynamicProperty;      /*!< dynamic property of the hypothesis object - see eGDBObjectDynProp_t*/
} GDBCDHypothesis_t;

/*! Error type, currently only used by CD @todo: TBD if needed on global level */
typedef enum
{
  GDB_ERROR_NONE               = 0u,   /*!< no error*/
  GDB_ERROR_POINTER_NULL       = 1u,   /*!< null pointer error*/
  GDB_ERROR_FUNC_POINTER_NULL  = 2u,   /*!< null function pointer error*/
  GDB_ERROR_CAST_VALUE_TO_HIGH = 3u,   /*!< while casting a variable, the value would be truncated because it was to high (example (signed char)200)*/
  GDB_ERROR_CAST_VALUE_TO_LOW  = 4u,   /*!< while casting a variable, the value would be truncated because it was to low  (example (signed char)-200)*/
  GDB_ERROR_UNKNOWN_TYPE       = 5u,   /*!< enum type handling unknown*/
  GDB_ERROR_FILTER_DOESNT_MATCH= 6u,   /*!< a filter function doesn't match any result*/
  GDB_ERROR_LOW_QUAILITY       = 7u,   /*!< at least one signal didn't have a sufficient quality*/
  GDB_ERROR_ARRAY_OVERFLOW     = 8u    /*!< the array index is out of bounds*/
} eGDBError_t;

#if (CFG_USE_COMPACT_ENUMS)
typedef ui8_t GDBError_t;              /*!< using 8bit type for the real enum (32bit type) eGDBError_t to save memory*/
#else
typedef eGDBError_t GDBError_t;
#endif

/*! signal states. @todo: moved to rte_types.h! */
typedef enum {
  GDB_SIG_STATUS_INIT                   = 0u,  /*! Definition for signal is not received in the
                                                 this ignition cycle. Parameter is on initialization value. */
  
  GDB_SIG_STATUS_OK                     = 1u,  /*! Definition for signal quality is OK. */
  
  GDB_SIG_STATUS_NOT_OK                 = 2u,  /*! Definition for signal quality is _NOT_ OK.
                                                 NOT_OK is set by external component (signal not available) */
  
  GDB_SIG_STATUS_TIMEOUT                = 3u,  /*! Definition for signal quality is TIMEOUT.
                                                 TIMEOUT can have the reasons: Message Timeout, DLC, CRC, MC -error */

  GDB_SIG_STATUS_OUT_OF_RANGE           = 4u   /*! Definition for signal value is out of defined range. */
} eGDBSigStatus_t;

#if (CFG_USE_COMPACT_ENUMS)
typedef ui8_t GDBSigStatus_t;      /*!< using 8bit type for the real enum (32bit type) eGDBSigStatus_t to save memory @values: eGDBSigStatus_t */
#else
typedef eGDBSigStatus_t GDBSigStatus_t;
#endif

#define IS_SIGNAL_STATUS_OK(status)     (status == GDB_SIG_STATUS_OK)

#endif
