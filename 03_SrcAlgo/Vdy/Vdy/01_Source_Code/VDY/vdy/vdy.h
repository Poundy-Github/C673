/*! \file *********************************************************************

  @defgroup VDYParameters VDY Types Definitions Prototype
	@ingroup VDYHandCode
   @{

  $Company:			Continental AG $

  $Component:		VDY (Vehicle Dynamics Observer) $

  $Module:			vdy.h $

  @brief			This file contains all types, definitions and prototypes needed inside of this component

  $Descripion:		$
  
  $Revision: 1.22.1.2 $

  CHANGES:
  ---*/ /*---



*****************************************************************************/
/* PRQA S 3453 EOF */
/* date: Unknown, reviewer: Suggested TCI Code Review, reason: It is legacy code of ARS301 , alreay reviewed and working fine without any critical issue " */


/* QAC Level 1 & 2 Warning Suppression */
/* PRQA S 1535 EOF */
/* date: 2019-06-10, reviewer: Mahesh Patle (uidr0487), reason: This operation is intended */

/* PRQA S 3414, 3428, 3456 EOF */
/* date: 2019-12-30, reviewer: Ramachandra Chinnaswamy (uids4735), reason: Fucntional Safe */

#ifndef VDY_H_INCLUDED
/// Define VDY includes
#define VDY_H_INCLUDED
/*** START OF SINGLE INCLUDE SECTION ****************************************/

/*****************************************************************************
  INCLUDES
*****************************************************************************/
#include "vdy_ext.h"
#include "vdy_cfg_ext.h"
#if (CFG_VDY_MFC)
#include "vdy_internal_ext.h"
#include <stddef.h>
#endif

#ifndef  GLOB_MEMSEC_H
#ifndef _ALGO_MEMSEC_H_

/// Empty macro for if memsec is not included 
#define SET_MEMSEC_VAR_A(v)		
/// Empty macro for if memsec is not included 
#define SET_MEMSEC_VAR(v)		
/// Empty macros for if memsec is not included 
#define SET_MEMSEC_CONST_A(v)	
/// Empty macros for if memsec is not included 
#define SET_MEMSEC_CONST(v)		
#endif
#endif

#include "vdy_par.h"
#include "vdy_internal_types.h"

#if defined(VDY_SIMU)
#if ( (!defined(CFG_VDY_DIS_WHEEL_PRE_PROCESSING)) || (!CFG_VDY_DIS_WHEEL_PRE_PROCESSING) )
#include "vdy_wpp.h"
#include "vdy_ve.h"
#include "vdy_wye.h"
#endif

#if ( (!defined(CFG_VDY_DIS_YAW_SENSOR_PRE_PROCESSING)) || (!CFG_VDY_DIS_YAW_SENSOR_PRE_PROCESSING) )
#include "vdy_gye.h"
#endif

#if ( (!defined(CFG_VDY_DIS_LAT_ACCEL_SENSOR_PRE_PROCESSING)) || (!CFG_VDY_DIS_LAT_ACCEL_SENSOR_PRE_PROCESSING) )
#include "vdy_aye.h"
#endif

#if ( (!defined(CFG_VDY_DIS_STW_ANGLE_SENSOR_PRE_PROCESSING)) || (!CFG_VDY_DIS_STW_ANGLE_SENSOR_PRE_PROCESSING) )
#include "vdy_sye.h"
#endif

#if ( (!defined(CFG_VDY_USE_EXT_PROC_YAW_RATE)) || (!CFG_VDY_USE_EXT_PROC_YAW_RATE) )
#include "vdy_ye.h"
#endif

#if ( (!defined(CFG_VDY_DIS_SIDE_SLIP_ANGLE_ESTIMATION)) || (!CFG_VDY_DIS_SIDE_SLIP_ANGLE_ESTIMATION) )
#include "vdy_sae.h"
#endif

#if (CFG_VDY_MOT_STATE)
#include "vdy_mot_st.h"
#endif

#endif

#ifdef __cplusplus
extern "C" {
#endif


/*****************************************************************************
  SYMBOLIC CONSTANTS 
*****************************************************************************/
#ifndef VDY_ZERO
/// Symbolic constant signed 0
#define VDY_ZERO		(0)		
#endif

#ifndef VDY_ZERO_U
/// Symbolic constant unsigned 0
#define VDY_ZERO_U		(0U)	
#endif

#ifndef VDY_ZERO_F
/// Symbolic constant float 0.0
#define VDY_ZERO_F		(0.0F)	
#endif

#ifndef VDY_ONE
/// Symbolic constant signed 1
#define VDY_ONE			(1)		
#endif

#ifndef VDY_ONE_U
/// Symbolic constant unsigned 1
#define VDY_ONE_U		(1U)	
#endif

#ifndef VDY_ONE_F
/// Symbolic constant float 1.0
#define VDY_ONE_F		(1.0F)	
#endif

#ifndef VDY_TWO
/// Symbolic constant signed 2
#define VDY_TWO			(2)		
#endif

#ifndef VDY_TWO_U
/// Symbolic constant unsigned 2
#define VDY_TWO_U		(2U)	
#endif

#ifndef VDY_TWO_F
/// Symbolic constant float 2.0
#define VDY_TWO_F		(2.0F)	
#endif

#ifndef VDY_THREE
/// Symbolic constant signed 3
#define VDY_THREE		(3)		
#endif

#ifndef VDY_THREE_U
/// Symbolic constant unsigned 3
#define VDY_THREE_U		(3U)	
#endif

#ifndef VDY_THREE_F
/// Symbolic constant float 3.0
#define VDY_THREE_F		(3.0F)	
#endif

#ifndef VDY_FOUR
/// Symbolic constant signed 4
#define VDY_FOUR		(4)		
#endif

#ifndef VDY_FOUR_U
/// Symbolic constant unsigned 4
#define VDY_FOUR_U		(4U)	
#endif

#ifndef VDY_FOUR_F
/// Symbolic constant float 4.0
#define VDY_FOUR_F		(4.0F)	
#endif

#ifndef VDY_FIVE
/// Symbolic constant signed 5
#define VDY_FIVE		(5)		
#endif

#ifndef VDY_FIVE_U
/// Symbolic constant unsigned 5
#define VDY_FIVE_U		(5U)	
#endif

#ifndef VDY_FIVE_F
/// Symbolic constant float 5.0
#define VDY_FIVE_F		(5.0F)
#endif

#ifndef VDY_SIX
/// Symbolic constant signed 6
#define VDY_SIX			(6)		
#endif

#ifndef VDY_SIX_U
/// Symbolic constant unsigned 6
#define VDY_SIX_U		(6U)
#endif

#ifndef VDY_SIX_F
/// Symbolic constant float 6.0
#define VDY_SIX_F		(6.0F)	
#endif

#ifndef VDY_SEVEN
/// Symbolic constant signed 7
#define VDY_SEVEN		(7)		
#endif

#ifndef VDY_SEVEN_U
/// Symbolic constant unsigned 7
#define VDY_SEVEN_U		(7U)	
#endif

#ifndef VDY_SEVEN_F
/// Symbolic constant float 7.0
#define VDY_SEVEN_F		(7.0F)	
#endif

#ifndef VDY_EIGHT
/// Symbolic constant signed 8
#define VDY_EIGHT		(8)		
#endif

#ifndef VDY_EIGHT_U
/// Symbolic constant unsigned 8
#define VDY_EIGHT_U		(8U)	
#endif

#ifndef VDY_EIGHT_F
/// Symbolic constant float 8.0
#define VDY_EIGHT_F		(8.0F)	
#endif

#ifndef VDY_NINE
/// Symbolic constant signed 9
#define VDY_NINE		(9)		
#endif

#ifndef VDY_NINE_U
/// Symbolic constant unsigned 9
#define VDY_NINE_U		(9U)	
#endif

#ifndef VDY_NINE_F
/// Symbolic constant float 9.0
#define VDY_NINE_F		(9.0F)	
#endif

#ifndef VDY_TEN_U
/// Symbolic constant unsigned 10
#define VDY_TEN_U		(10U)	
#endif

#ifndef VDY_ELEVEN_U
/// Symbolic constant unsigned 11
#define VDY_ELEVEN_U	(11U)	
#endif

#ifndef VDY_TWELVE_U
/// Symbolic constant unsigned 12
#define VDY_TWELVE_U	(12U)	
#endif

#ifndef VDY_THIRTEEN_U
/// Symbolic constant unsigned 13
#define VDY_THIRTEEN_U	(13U)	
#endif

#ifndef VDY_FOURTEEN_U
/// Symbolic constant unsigned 14
#define VDY_FOURTEEN_U	(14U)	
#endif

#ifndef VDY_FIFTEEN_U
/// Symbolic constant unsigned 15
#define VDY_FIFTEEN_U	(15U)	
#endif

#ifndef VDY_SIXTEEN
/// Symbolic constant signed 16
#define VDY_SIXTEEN		(16)	
#endif

#ifndef VDY_SIXTEEN_U
/// Symbolic constant unsigned 16
#define VDY_SIXTEEN_U	(16U)	
#endif

#ifndef VDY_TWENTY_THREE_U
/// Symbolic constant unsigned 23
#define VDY_TWENTY_THREE_U		(23U)	
#endif

#ifndef VDY_THIRTY_TWO
/// Symbolic constant signed 32
#define VDY_THIRTY_TWO			(32)	
#endif

#ifndef VDY_X_FF
/// Symbolic constant signed 0xFF
#define VDY_X_FF				(0xFF)	
#endif

#ifndef VDY_X_FF_U
/// Symbolic constant unsigned FF
#define VDY_X_FF_U				(0x000000FFU)	
#endif

#ifndef VDY_FIFTY
/// Symbolic constant signed 50
#define VDY_FIFTY				(50)			
#endif

#ifndef VDY_FIFTY_U
/// Symbolic constant unsigned 50
#define VDY_FIFTY_U				(50U)			
#endif

#ifndef VDY_FIFTY_F
/// Symbolic constant float 50.0
#define VDY_FIFTY_F				(50.0F)			
#endif

#ifndef VDY_HUNDRED_F
/// Symbolic constant float 100.0
#define VDY_HUNDRED_F			(100.0F)		
#endif

#ifndef VDY_MAX_U
/// Symbolic constant unsigned 255 (max)
#define VDY_MAX_U				(255U)			
#endif

#ifndef VDY_THOUSAND_F
/// Symbolic constant float 1000.0
#define VDY_THOUSAND_F			(1000.0F)		
#endif

#ifndef VDY_FIVE_CENT
/// Symbolic constant float 0.05
#define VDY_FIVE_CENT			(0.05F)			
#endif

#ifndef VDY_TEN_CENT
/// Symbolic constant float 0.1
#define VDY_TEN_CENT			(0.1F)			
#endif

#ifndef VDY_FIFTEEN_CENT
/// Symbolic constant float 0.15
#define VDY_FIFTEEN_CENT		(0.15F)			
#endif

#ifndef VDY_TWENTY_CENT
/// Symbolic constant float 0.2
#define VDY_TWENTY_CENT			(0.20F)			
#endif

#ifndef VDY_THIRTY_CENT
/// Symbolic constant float 0.3
#define VDY_THIRTY_CENT			(0.3F)			
#endif

#ifndef VDY_THIRTY_FIVE_CENT
/// Symbolic constant float 0.35
#define VDY_THIRTY_FIVE_CENT	(0.35F)			
#endif

#ifndef VDY_FORTY_FIVE_CENT
/// Symbolic constant float 0.45
#define VDY_FORTY_FIVE_CENT		(0.45F)			
#endif

#ifndef VDY_FIFTY_CENT
/// Symbolic constant float 0.5
#define VDY_FIFTY_CENT			(0.5F)			
#endif

#ifndef VDY_SEVENTY_FIVE_CENT
/// Symbolic constant float 0.75
#define VDY_SEVENTY_FIVE_CENT	(0.75F)			
#endif

#ifndef VDY_ONE_FIFTY_CENT
/// Symbolic constant float 1.5
#define VDY_ONE_FIFTY_CENT		(1.5F)			
#endif

#ifndef VDY_ONE_FIFTY_SEVEN_CENT
/// Symbolic constant float 1.5
#define VDY_ONE_FIFTY_SEVEN_CENT		(1.57F)			
#endif

#ifndef VDY_ONE_NE_FIVE
/// Symbolic constant float 0.00001
#define VDY_ONE_NE_FIVE			(0.00001F)		
#endif

#ifndef VDY_ONE_NE_NINE
/// Symbolic constant float 0.000000001
#define VDY_ONE_NE_NINE			(0.000000001F)	
#endif

#ifndef VDY_MAGIC_NUM
/// Symbolic constant unsigned 0x5F375A86U
#define VDY_MAGIC_NUM			(0x5F375A86U)	
#endif

/// Minimum velocity for curvature estimation  
#define VDY_CURVE_V_MIN	((3.0F/C_KMH_MS)) 

/// Filter time constant for quality of single curvatures
#define VDY_QUALITY_FT	(1.0F) 

/* Minimum and maximum output curvature as radius  */

/// Maximum output curvature as radius 
#define VDY_MAX_RADIUS	(30000.F) 

/// Minimum output curvature as radius 
#define VDY_MIN_RADIUS	(4.0F) 

/* Definitionen fuer Stillstandabgleich */

/// Maximum standard deviation for takeover standstill adjustment
#define STANDST_STDABW_MAX              (DEG2RAD(0.20F))           

/// Number of speed ranges of the RDZ offset
#define WHS_SPEEED_RANGE_VOLUME   (sint32) 4

/// Number of histogram bins for steering wheel angle calibration  
#define SWA_OFFS_HIST_NO_BINS     (29U)

/// Maximum bin index for steering wheel angle histogram            
#define SWA_OFFS_HIST_MAX_IDX     (SWA_OFFS_HIST_NO_BINS - 1U)   

/// Number of histogram bins for lateral acceleration sensor calibration  
#define AY_OFFS_HIST_NO_BINS      (41U)

/// Maximum bin index for lateral acceleration angle histograms    
#define AY_OFFS_HIST_MAX_IDX      (AY_OFFS_HIST_NO_BINS - 1U)   
       
/// Minimum offset confidence for standstill calibration start 
#define VDY_YWR_OFF_STST_CALC_TIME_Q_MIN  (0.6F) 

/// Maximum offset confidence for standstill calibration end   
#define VDY_YWR_OFF_STST_CALC_TIME_Q_MAX  (1.0F)    
  

/* Time constraints for yaw rate offset calibration  */

/// Maximum ECU running time 10 days 
#define YWR_ECU_ELPSD_TIME_MAX     (10.0F * 24.0F * 60.0F * 60.0F)       
/// Maximum time since last calibration  
#define YWR_OFFS_ELPSD_TIME_MAX    (60.0F * 60.0F)                

/*! Virtual addresses or related records IDs (in case of framework lookup table) for 
    data acquisition interface. The addresses or IDs values must correspond to addresses 
    specified in data description file (SDL, A2L etc.) */
#define VDY_MEAS_ID_INTDATA     0x2030069CU          /*!< Group VDYInternal    */


#if (CFG_VDY_INT_GYRO)
/// Set all table node flags
#define VDY_YWRT_NODES_MASK_ALL(stat_)         ((void)(((stat_)[0] |= VDY_YWRT_NODES_MAKS_ALL_LO) & ((stat_)[1] |= VDY_YWRT_NODES_MAKS_ALL_HI)))
/// Clear all table node flags
#define VDY_YWRT_NODES_CLEAR_ALL(stat_)        ((void)(((stat_)[0] &= ~VDY_YWRT_NODES_MAKS_ALL_LO) | ((stat_)[1] &= ~VDY_YWRT_NODES_MAKS_ALL_HI)))
/// Clear all status flags
#define VDY_YWRT_CLEAR_ALL(stat_)              ((void)(((stat_)[0] = 0UL) | ((stat_)[1] =0UL)))
/// Signals that offset is not available
#define VDY_YWRT_PROD_OFFSET_SNA               ((sint16) -32768L)
/// Yaw rate production offset scale factors   MEM -> PHYS
#define VDY_YWRT_PROD_SCALE                    (1.F/VDY_YWRT_PROD_INV_SCALE)
/// Yaw rate production offset scale factors   PHYS -> MEM
#define VDY_YWRT_PROD_INV_SCALE                (1E4F)
#endif

 
#ifndef REF_SPEED_NO_BINS
/// number of bins in velocity correction histogram 
#define REF_SPEED_NO_BINS                      (81) 
#endif

/// Number of velocity ranges for velocity correction
#define VDY_CORR_VEL_RANGES                    (3U)
/// Generated velo variance is calculate by this parabolic function v_var(a) = m*a^2 +b \n Min Generated velo variance, b of var(a)
#define VDY_GEN_VELO_VAR_B (0.03030F)
/// Generated velo variance is calculate by this parabolic function v_var(a) = m*a^2 +b   \n m of parabolic function v_var(a)
#define VDY_GEN_VELO_VAR_M (0.06970F) 

#if (CFG_VDY_FPM_754)
/// Use optimized functions dependent on IEEE754 float format   - SQRT
#define VDY_SQRT(x_)          CML_f_Sqrt(x_)
/// Use optimized functions dependent on IEEE754 float format  - Exp
#define VDY_EXP(x_)           vdyExp(x_)
#else
/// Use standard math functions from compiler - sqrt
#define VDY_SQRT(x_)          (float32) sqrt((float32)x_)
/// Use standard math functions from compiler - exp
#define VDY_EXP(x_)           (float32) exp((float32)x_)
#endif

///Macro for strlen
#define VDY_STRLEN(STR_) (( (sizeof(STR_)) / (sizeof((STR_)[0])) ) - (1))


#if (     ( (!defined(CFG_VDY_DIS_YWR_OFFSET_COMP)) || (!CFG_VDY_DIS_YWR_OFFSET_COMP) ) \
       || ( (!defined(CFG_VDY_DIS_YAW_SENSOR_PRE_PROCESSING)) || (!CFG_VDY_DIS_YAW_SENSOR_PRE_PROCESSING) ) )
/// yawrate offset types for dynamic offset compensation in autocode model \n do not take over use last type   
#define VDY_YAWRATE_STATE_KEEP_TYPE      (0U)
/// yawrate offset types for dynamic offset compensation in autocode model \n dynamic offset is stand still offset
#define VDY_YAWRATE_STATE_STANDSTILL     (1U)      
/// yawrate offset types for dynamic offset compensation in autocode model \n dynamic offset taken from NVM
#define VDY_YAWRATE_STATE_NVM            (2U)
/// yawrate offset types for dynamic offset compensation in autocode model \n yaw rate stand still offset never ever estimated  
#define VDY_YAWRATE_STATE_NOT_ESTIMATED  (3U)
/// yawrate offset types for dynamic offset compensation in autocode model \n max difference between old dyn offset and new offset
#define VDY_YAWRATE_DYN_MAX_DIFF         (0.00395F)
#endif

/*****************************************************************************
  MACROS 
*****************************************************************************/

/// courage environment 
#if defined(CFG_DISABLE_STATIC_MTD)
 /// Keyword for static methods /functions
 #define STATIC_MTD
 /// Keyword for inline functions
 #define ALGO_STATIC_INLINE
#else
 /// Keyword for static methods /functions
 #define STATIC_MTD static
 /// Keyword for inline functions
 #define ALGO_STATIC_INLINE ALGO_STATIC_INLINE_C
#endif

/// courage environment 
#if defined(CFG_DISABLE_STATIC_VAR)
  /// Keyword for static variables
  #define STATIC_VAR
#else
  /// Keyword for static variables
  #define STATIC_VAR static
#endif

/// Simple low pass filter, first order 
#define VDY_IIR_FILTER(NEW_, OLD_, FT_, ST_)  ( ((((FT_)/(ST_))*(OLD_))+(NEW_))/(1.0F+((FT_)/(ST_))) ) 

/// Simple low pass filter differentiator, first order
#define VDY_IIR_DIFF(NIN_, OIN_, OOUT_, FT_, ST_)  ( (1.F /((ST_)+(FT_))) * (((NIN_)-(OIN_)) + ((FT_)*(OOUT_))) )    

/// IIR filter second order   (no trailing ; )  
#define VDY_IIR_FILTER2(IN_,OUT_,C_,M_)   do  { \
  (OUT_) = ( ((C_)[0].num*(IN_)) +  ((C_)[1].num*(M_)[0].fin)  + ((C_)[2].num*(M_)[1].fin) ) \
                           - (((C_)[1].den*(M_)[0].fout) + ((C_)[2].den*(M_)[1].fout)); \
  (M_)[1].fin  = (M_)[0].fin;   \
  (M_)[0].fin  = (IN_);         \
  (M_)[1].fout = (M_)[0].fout;  \
  (M_)[0].fout = (OUT_);        \
} while(0) 


/// set the state of control mode 
#define VDY_CTRL_SET_STATE(mask_, val_)        ((val_) |= (mask_)) 

/// clear the state of control mode
#define VDY_CTRL_CLR_STATE(mask_, val_)        ((val_) &= ~(mask_)) 

/// Getting the state of control mode
//#define VDY_CTRL_GET_STATE(mask_, val_)        ((boolean)( (val_) & (mask_) ) != FALSE ) 
#define VDY_CTRL_GET_STATE(mask_, val_)        ((val_) == (mask_)) 

#if (VDY_VEH_DYN_INTFVER <= 5)
/// init vdy io states */
#ifndef VDY_VEH_DYN_IO_STATE_INIT
#define VDY_VEH_DYN_IO_STATE_INIT              ((VDYIoState_t) 0xFFFFFFFFUL)
#endif
#endif

#ifdef __PDO__
///  NOT USED
#define VDY_SET_IO_STATE_VAL(name_,val_)

///  NOT USED  
#define VDY_GET_IO_STATE_VAL(name_)             0 
#else

///  NOT USED
#define VDY_SET_IO_STATE_VAL(name_, val_)  ((name_) = (val_))

///  NOT USED
#define VDY_GET_IO_STATE_VAL(name_)            (name_)
#endif

/*----- Data acquisition interface definition, only active if configured and new MTS setup is used */
#if ( defined(CFG_VDY_MEASUREMENT) && (CFG_VDY_MEASUREMENT == 1) )
  #ifdef AS_SERVICEFUNC_VERSION
    #if ( defined (CFG_VDY_USE_ALGOCOMPSTATE) && (CFG_VDY_USE_ALGOCOMPSTATE == 1) )
		/// VDY MTS Funtion ID
      #define VDY_MTS_FUNC_ID              COMP_ID_VDY 
		/// VDY MTS Funtion Channel ID
      #define VDY_MTS_FUNC_CHANNEL_ID      TASK_ID_VDY 
    #else
		/// VDY MTS Funtion ID
      #define VDY_MTS_FUNC_ID              TASK_ID_ALGO_VEH_CYCLE 
		/// VDY MTS Funtion Channel ID
      #define VDY_MTS_FUNC_CHANNEL_ID      TASK_ID_ALGO_VEH_CYCLE 
    #endif
  #endif
#endif

/* macros for profiling   */
#if ( defined(VDY_PROFILING_ENABLED) && (VDY_PROFILING_ENABLED == 1) )
#ifdef AS_SERVICEFUNC_VERSION


/// Start VDY Profiling
#define VDY_PROF_START(fct_, u_IdLocal)     ((void)((fct_)(e_RTA_EVT_AlgoStart, COMP_ID_VDY, (uint8)(u_IdLocal), 0U)))
//#define VDY_PROF_START(fct_, u_IdLocal)     (((fct_) != (void *)NULL) ? ((void)((fct_)(e_RTA_EVT_AlgoStart, COMP_ID_VDY, (uint8)(u_IdLocal), 0U))) : (void)(0L)) 

/// Stop VDY Profiling
#define VDY_PROF_STOP(fct_, u_IdLocal)      ((void)(services->pfRTAAlgoServiceAddEvent(e_RTA_EVT_AlgoEnd, COMP_ID_VDY, (uint8)(u_IdLocal), 0U)))
//#define VDY_PROF_STOP(fct_, u_IdLocal)      (((fct_) != (void *)NULL) ? ((void)(services->pfRTAAlgoServiceAddEvent(e_RTA_EVT_AlgoEnd, COMP_ID_VDY, (uint8)(u_IdLocal), 0U))) : (void)(0L))

/// VDY Profiling Marker
#define VDY_PROF_MARKER(fct_, u_IdLocal)    ((void)(services->pfRTAAlgoServiceAddEvent(e_RTA_EVT_Marker, COMP_ID_VDY, (uint8)(u_IdLocal), 0U)))
//#define VDY_PROF_MARKER(fct_, u_IdLocal)    (((fct_) != (void *)NULL) ? ((void)(services->pfRTAAlgoServiceAddEvent(e_RTA_EVT_Marker, COMP_ID_VDY, (uint8)(u_IdLocal), 0U))) : (void)(0L)) 


#else
	
/// Start VDY Profiling
#define VDY_PROF_START(fct_)   (void) ((((fct_) != NO_VDY_CALLBACK) && ((fct_)->pfProfTimer->Start != NO_VDY_TIME_START_STOP_CALL))  ? ((fct_)->pfProfTimer->Start(),0L) : 0L) 

/// Stop VDY Profiling
#define VDY_PROF_STOP(fct_)    (void) ((((fct_) != NO_VDY_CALLBACK) && ((fct_)->pfProfTimer->Stop  != NO_VDY_TIME_START_STOP_CALL)) ? ((fct_)->pfProfTimer->Stop(),0L) : 0L) 
#endif
#else

/// Start VDY Profiling
#define VDY_PROF_START(fct_, u_IdLocal) 

/// Stop VDY Profiling
#define VDY_PROF_STOP(fct_, u_IdLocal) 

/// VDY Profiling Marker
#define VDY_PROF_MARKER(fct_, u_IdLocal) 
#endif

/* macros for sequence  */

/// VDY Sequencing initiated
#define VDY_SEQUENCE_INIT_MODULE_INIT              (1U) 

/// VDY Sequencing not initiated
#define VDY_SEQUENCE_INIT_MODULE_NOT_INIT          (0U) 

/// VDY set sequencing state to  init
#define VDY_SET_SEQUENCE_STATE_TO_INIT(module)     ((module) = (uint32)VDY_SEQUENCE_INIT_MODULE_INIT) 

/// VDY reset sequencing state to  init
#define VDY_RESET_SEQUENCE_STATES(state)           ((state).states = 0U) 

/// VDY set all sequencing state to  init
#define VDY_SET_ALL_SEQUENCE_STATES_TO_INIT(InitStates) ((InitStates).states = 0xFFFFFFFFU) 

/// VDY Sequencing initiated or not 
#define VDY_IS_MODULE_SEQU_INITALIZED(module)      (((module) == (uint32)VDY_SEQUENCE_INIT_MODULE_INIT)?(TRUE):(FALSE) ) 


/*****************************************************************************
  TYPEDEFS 
*****************************************************************************/

/// bitfield definition to have commen definition in different projects and setups 
typedef unsigned int    vdy_ubit32_t;

/* dummy for pdo tool */
#ifdef __PDO__

#ifndef BIT_FIELD_MSB_FIRST
#define BIT_FIELD_MSB_FIRST  1
#endif

/// \brief VDY Output Signal Validity State
/// \details VDY_IO_STATE_VALID = 0 \n VDY_IO_STATE_INVALID = 1 \n VDY_IO_STATE_NOTAVAIL = 2 \n VDY_IO_STATE_DECREASED = 3 \n VDY_IO_STATE_SUBSTITUE = 4 \n VDY_IO_STATE_INPLAUSIBLE = 5 \n VDY_IO_STATE_INIT = 15 \n VDY_IO_STATE_MAX = 255
typedef struct VDYOutState
{
#if (BIT_FIELD_MSB_FIRST)
    uint32      Pad                 : 14;		///< Padding
    uint32      LatAccel            : 2;		///< Estimated lateral accleration      
    uint32      BodySideSlipAngle   : 2;		///< Side slip angle                    
    uint32      VelocityCorr        : 2;		///< Velocity Correction                
    uint32      LongMotState        : 2;		///< Vehicle motion state               
    uint32      LongAccel           : 2;		///< Vehicle long. acceleration         
    uint32      LongVelocity        : 2;		///< Vehicle long. velocity             
    uint32      DrvIntCurve         : 2;		///< Driver intended curvature          
    uint32      YawRate             : 2;		///< Estimated vehicle yaw velocity     
    uint32      Curve               : 2;		///< Curvature of vehicle tracetory     
#else
    uint32      Curve               : 2;		///< Curvature of vehicle tracetory     
    uint32      YawRate             : 2;		///< Estimated vehicle yaw velocity     
    uint32      DrvIntCurve         : 2;		///< Driver intended curvature          
    uint32      LongVelocity        : 2;		///< Vehicle long. velocity             
    uint32      LongAccel           : 2;		///< Vehicle long. acceleration         
    uint32      LongMotState        : 2;		///< Vehicle motion state               
    uint32      VelocityCorr        : 2;		///< Velocity Correction                
    uint32      BodySideSlipAngle   : 2;		///< Side slip angle                    
    uint32      LatAccel            : 2;		///< Estimated lateral accleration      
    uint32      Pad                 : 14;		///< Padding
#endif
} VDYOutSignalState_t;

/// \brief VDY Parameters Validity State
/// \details VDY_IO_STATE_VALID = 0 \n VDY_IO_STATE_INVALID = 1 \n VDY_IO_STATE_NOTAVAIL = 2 \n VDY_IO_STATE_DECREASED = 3 \n VDY_IO_STATE_SUBSTITUE = 4 \n VDY_IO_STATE_INPLAUSIBLE = 5 \n VDY_IO_STATE_INIT = 15 \n VDY_IO_STATE_MAX = 255
typedef struct VDYParaState
{
#if (BIT_FIELD_MSB_FIRST)
  uint32   Total                : 2;     ///< Total summary para state                     
  uint32   ReCrnrStiff          : 2;     /*!< Rear axle cornering stiffness @NAME: CornStiffRe  */
  uint32   FrCrnrStiff          : 2;     /*!< Front axle cornering stiffness @NAME: CornStiffFr  */
  uint32   WhlTcksPerRev        : 2;     /*!< Impulse counter ticks per wheel revolution @NAME: WhlTicksPRev  */
  uint32   DrvAxle              : 2;     ///< Powered Axle                                 
  uint32   WhlCircumference     : 2;     /*!< Effective dynamic rolling circumference @NAME: WhlCircum  */
  uint32   WhlLoadDepRearAxle   : 2;     /*!< Wheel load dependency rear axle @NAME: WhlLdDepRe  */
  uint32   WhlLoadDepFrontAxle  : 2;     /*!< Wheel load dependency front axle @NAME: WhlLdDepFr  */
  uint32   AxisLoadDistr        : 2;     /*!< Ratio between rear axle load and total load @NAME: AxleLdDistr  */
  uint32   CntrOfGravHeight     : 2;     ///< Center of gravity height                     
  uint32   VehWeight            : 2;     /*!< Vehicle weight @NAME: VehicleWeight  */
  uint32   TrackWidthRear       : 2;     ///< Track width rear axle                        
  uint32   TrackWidthFront      : 2;     ///< Track width front axle                       
  uint32   WheelBase            : 2;     ///< Distance between front and rear axle         
  uint32   SteeringRatio        : 2;     ///< Overall steering ratio                       
  uint32   SelfSteerGrad        : 2;     ///< Understeer/Oversteer gradient                
#else
  uint32   SelfSteerGrad        : 2;     ///< Understeer/Oversteer gradient                
  uint32   SteeringRatio        : 2;     ///< Overall steering ratio                       
  uint32   WheelBase            : 2;     ///< Distance between front and rear axle         
  uint32   TrackWidthFront      : 2;     ///< Track width front axle                       
  uint32   TrackWidthRear       : 2;     ///< Track width rear axle                        
  uint32   VehWeight            : 2;     /*!< Vehicle weight @NAME: VehicleWeight          */
  uint32   CntrOfGravHeight     : 2;     ///< Center of gravity height                     
  uint32   AxisLoadDistr        : 2;     /*!< Ratio between rear axle load and total load @NAME: AxleLdDistr  */
  uint32   WhlLoadDepFrontAxle  : 2;     /*!< Wheel load dependency front axle @NAME: WhlLdDepFr  */
  uint32   WhlLoadDepRearAxle   : 2;     /*!< Wheel load dependency rear axle @NAME: WhlLdDepRe   */
  uint32   WhlCircumference     : 2;     /*!< Effective dynamic rolling circumference @NAME: WhlCircum  */
  uint32   DrvAxle              : 2;     ///< Powered Axle                                 
  uint32   WhlTcksPerRev        : 2;     /*!< Impulse counter ticks per wheel revolution @NAME: WhlTicksPRev  */
  uint32   FrCrnrStiff          : 2;     /*!< Front axle cornering stiffness @NAME: CornStiffFr */ 
  uint32   ReCrnrStiff          : 2;     /*!< Rear axle cornering stiffness @NAME: CornStiffRe  */
  uint32   Pad                  : 2;     ///< Total summary para state                     
#endif
  uint32 RES : 32;
} VDYParaState_t;

/// \brief VDY Sensor Parameters validity states 
/// \details VDY_IO_STATE_VALID = 0 \n VDY_IO_STATE_INVALID = 1 \n VDY_IO_STATE_NOTAVAIL = 2 \n VDY_IO_STATE_DECREASED = 3 \n VDY_IO_STATE_SUBSTITUE = 4 \n VDY_IO_STATE_INPLAUSIBLE = 5 \n VDY_IO_STATE_INIT = 15 \n VDY_IO_STATE_MAX = 255
typedef struct VDYParaSensorState
{
#if (BIT_FIELD_MSB_FIRST)
  uint32   Pad                 : 22;    ///< padding to 32 bit                      
  uint32   uNoOfScans          : 2;     ///< Number of scans  
  uint32   fCycleTime          : 2;     ///< Global Cycle Time of the radar cycle used by the components in the radar cycle task 
  uint32   fLobeAngle          : 2;     ///< Lobe Angle  
  uint32   fCoverageAngle      : 2;     ///< Coverage Angle  
  uint32   CoverDamping        : 2;     ///< Attenuation of secondary surface (two-way) in dB  
#else
  uint32   CoverDamping        : 2;     ///< Attenuation of secondary surface (two-way) in dB  
  uint32   fCoverageAngle      : 2;     ///< Coverage Angle  
  uint32   fLobeAngle          : 2;     ///< Lobe Angle  
  uint32   fCycleTime          : 2;     ///< Global Cycle Time of the radar cycle used by the components in the radar cycle task 
  uint32   uNoOfScans          : 2;     ///< Number of scans  
  uint32   Pad                 : 22;    ///< padding to 32 bit                      
#endif
  uint32 RES : 32;
} VDYParaSensorState_t;

/// \brief VDY Sensor Mounting Parameters Validity States
/// \details VDY_IO_STATE_VALID = 0 \n VDY_IO_STATE_INVALID = 1 \n VDY_IO_STATE_NOTAVAIL = 2 \n VDY_IO_STATE_DECREASED = 3 \n VDY_IO_STATE_SUBSTITUE = 4 \n VDY_IO_STATE_INPLAUSIBLE = 5 \n VDY_IO_STATE_INIT = 15 \n VDY_IO_STATE_MAX = 255
typedef struct VDYParaSensorMountingState
{
#if (BIT_FIELD_MSB_FIRST)
  uint32   Pad                 : 18;    ///< padding to 32 bit                      
  uint32   YawAngle            : 2;     ///< Angular displacemnt about vehicle vertical axis 
  uint32   Orientation         : 2;     ///< Angular displacement about sensor longitudinal axis  
  uint32   PitchAngle          : 2;     ///< Angular displacment about sensor lateral axis  
  uint32   LongPosToCoG        : 2;     ///< Longitudinal displacment related to vehicle center of gravity (+ fwd)  
  uint32   VertPos             : 2;     ///< Vertical displacemnt (height) over ground  
  uint32   LongPos             : 2;     ///< Longitudinal displacment related to vehicle reference point (+ fwd)  
  uint32   LatPos              : 2;     ///< Lateral displacment related to vehicle reference point (+ left)  
#else
  uint32   LatPos              : 2;     ///< Lateral displacment related to vehicle reference point (+ left)  
  uint32   LongPos             : 2;     ///< Longitudinal displacment related to vehicle reference point (+ fwd)  
  uint32   VertPos             : 2;     ///< Vertical displacemnt (height) over ground  
  uint32   LongPosToCoG        : 2;     ///< Longitudinal displacment related to vehicle center of gravity (+ fwd)  
  uint32   PitchAngle          : 2;     ///< Angular displacment about sensor lateral axis  
  uint32   Orientation         : 2;     ///< Angular displacement about sensor longitudinal axis  
  uint32   YawAngle            : 2;     ///< Angular displacemnt about vehicle vertical axis  
  uint32   Pad                 : 18;    ///< padding to 32 bit                      
#endif
  uint32 RES : 32;
} VDYParaSensorMountingState_t;

/// \brief VDY Additional Parametes States
/// \details VDY_IO_STATE_VALID = 0 \n VDY_IO_STATE_INVALID = 1 \n VDY_IO_STATE_NOTAVAIL = 2 \n VDY_IO_STATE_DECREASED = 3 \n VDY_IO_STATE_SUBSTITUE = 4 \n VDY_IO_STATE_INPLAUSIBLE = 5 \n VDY_IO_STATE_INIT = 15 \n VDY_IO_STATE_MAX = 255
typedef struct VDYParaAddState
{
#if (BIT_FIELD_MSB_FIRST)
  uint32   Pad                 : 24;    ///< padding to 32 bit                      
  uint32   OverhangFront       : 2;     ///< Longitudinal distance from the center of front axle group to the front most point  
  uint32   CurbWeight          : 2;     ///< The weight of a fueled automobile with standard equipment but without cargo or passengers  
  uint32   VehicleLength       : 2;     ///< Vehicle length  
  uint32   VehicleWidth        : 2;     ///< Vehicle width  
#else
  uint32   VehicleWidth        : 2;     ///< Vehicle width  
  uint32   VehicleLength       : 2;     ///< Vehicle length  
  uint32   CurbWeight          : 2;     ///< The weight of a fueled automobile with standard equipment but without cargo or passengers  
  uint32   OverhangFront       : 2;     ///< Longitudinal distance from the center of front axle group to the front most point  
  uint32   Pad                 : 24;    ///< padding to 32 bit                     
#endif
  uint32 RES : 32;
} VDYParaAddState_t;

/// \brief VDY Input Signal States 
/// \details VDY_IO_STATE_VALID = 0 \n VDY_IO_STATE_INVALID = 1 \n VDY_IO_STATE_NOTAVAIL = 2 \n VDY_IO_STATE_DECREASED = 3 \n VDY_IO_STATE_SUBSTITUE = 4 \n VDY_IO_STATE_INPLAUSIBLE = 5 \n VDY_IO_STATE_INIT = 15 \n VDY_IO_STATE_MAX = 255
typedef struct VDYInSignalState
{
#if (BIT_FIELD_MSB_FIRST)
  uint32   WhlDirFrRight       :2;   ///< Wheel rolling direction front right                     
  uint32   WhlDirFrLeft        :2;   ///< Wheel rolling direction front left                      
  uint32   VehLongAccelExt     :2;   /*!< External longitudinal vehicle acceleration @NAME: VehAccExt  */
  uint32   VehVelocityExt      :2;   /*!< External provided longitudinal velocity @NAME: VehVelExt  */
  uint32   RearWhlAngle        :2;   ///< Steering wheel angle velocity                           
  uint32   LongAccel           :2;   ///< Longitudinal acceleration sensor signal                 
  uint32   YawRateIntTemp      :2;   ///< Temperature of yaw rate sensor signal                   
  uint32   YawRateInt          :2;   ///< Yaw rate sensor signal                                  
  uint32   WhlVelReRight       :2;   ///< Wheel circumferential velocity rear right               
  uint32   WhlVelReLeft        :2;   ///< Wheel circumferential velocity rear left                
  uint32   WhlVelFrRight       :2;   ///< Wheel circumferential velocity front right              
  uint32   WhlVelFrLeft        :2;   ///< Wheel circumferential velocity front left               
  uint32   LatAccel            :2;   ///< Lateral acceleration sensor signal                      
  uint32   StWheelAngle        :2;   /*!< Steering wheel angle sensor signal @NAME: StWhAngle     */
  uint32   YawRateTemp         :2;   ///< Temperature of yaw rate sensor signal                   
  uint32   YawRate             :2;   ///< Yaw rate sensor signal                                  

  uint32   Pad                 :6; 
  uint32   SideSlipAngleExt    :2;   /*!< External proveded side slip angle @NAME: SideSlipAngle  */
  uint32   Curve               :2;   ///< External provided curvature 1/R                         
  uint32   VehLongMotStateExt  :2;   /*!< External vehicle standstill @NAME: VehLongMotExt  */      
  uint32   VehLongDirExt       :2;   ///< External longitudinal direction state                   
  uint32   ParkBrakeState      :2;   ///< Status of park brake (false->released, true -> locked)  
  uint32   BrakeActLevel       :2;   /*!< Brake activity level (torque or pressure) @NAME: BrakeActLevel  */
  uint32   ActGearPos          :2;   ///< Actual gear position  
  uint32   WhlTicksDevReRight  :2;   /*!< Wheel ticks deviation rear right to last cycle @NAME: WhlIcDevReRight  */
  uint32   WhlTicksDevReLeft   :2;   /*!< Wheel ticks deviation rear left to last cycle @NAME: WhlIcDevReLeft  */
  uint32   WhlTicksDevFrRight  :2;   /*!< Wheel ticks deviation front right to last cycle @NAME: WhlIcDevFrRight  */
  uint32   WhlTicksDevFrLeft   :2;   /*!< Wheel ticks deviation front left to last cycle @NAME: WhlIcDevFrLeft  */
  uint32   WhlDirReRight       :2;   ///< Wheel rolling direction rear right                      
  uint32   WhlDirReLeft        :2;   ///< Wheel rolling direction rear left                       
#else
  uint32   YawRate             :2;   ///< Yaw rate sensor signal                                  
  uint32   YawRateTemp         :2;   ///< Temperature of yaw rate sensor signal                   
  uint32   StWheelAngle        :2;   /*!< Steering wheel angle sensor signal @NAME: StWhAngle     */
  uint32   LatAccel            :2;   ///< Lateral acceleration sensor signal                      
  uint32   WhlVelFrLeft        :2;   ///< Wheel circumferential velocity front left               
  uint32   WhlVelFrRight       :2;   ///< Wheel circumferential velocity front right              
  uint32   WhlVelReLeft        :2;   ///< Wheel circumferential velocity rear left                
  uint32   WhlVelReRight       :2;   ///< Wheel circumferential velocity rear right               
  uint32   YawRateInt          :2;   ///< Yaw rate sensor signal                                  
  uint32   YawRateIntTemp      :2;   ///< Temperature of yaw rate sensor signal                   
  uint32   LongAccel           :2;   ///< Longitudinal acceleration sensor signal                 
  uint32   RearWhlAngle        :2;   ///< Steering wheel angle velocity                           
  uint32   VehVelocityExt      :2;   /*!< External provided longitudinal velocity @NAME: VehVelExt  */
  uint32   VehLongAccelExt     :2;   /*!< External longitudinal vehicle acceleration @NAME: VehAccExt */ 
  uint32   WhlDirFrLeft        :2;   ///< Wheel rolling direction front left                      
  uint32   WhlDirFrRight       :2;   ///< Wheel rolling direction front right                     

  uint32   WhlDirReLeft        :2;   ///< Wheel rolling direction rear left                       
  uint32   WhlDirReRight       :2;   ///< Wheel rolling direction rear right                      
  uint32   WhlTicksDevFrLeft   :2;   /*!< Wheel ticks deviation front left to last cycle @NAME: WhlIcDevFrLeft  */
  uint32   WhlTicksDevFrRight  :2;   /*!< Wheel ticks deviation front right to last cycle @NAME: WhlIcDevFrRight  */
  uint32   WhlTicksDevReLeft   :2;   /*!< Wheel ticks deviation rear left to last cycle @NAME: WhlIcDevReLeft  */
  uint32   WhlTicksDevReRight  :2;   /*!< Wheel ticks deviation rear right to last cycle @NAME: WhlIcDevReRight  */
  uint32   ActGearPos          :2;   ///< Actual gear position  
  uint32   BrakeActLevel       :2;   /*!< Brake activity level (torque or pressure) @NAME: BrakeActLevel  */
  uint32   ParkBrakeState      :2;   ///< Status of park brake (false -- released, true - locked)  
  uint32   VehLongDirExt       :2;   ///< External longitudinal direction state                   
  uint32   VehLongMotStateExt  :2;   /*!< External vehicle standstill @NAME: VehLongMotExt  */      
  uint32   Curve               :2;   ///< External provided curvature 1/R                         
  uint32   SideSlipAngleExt    :2;   /*!< External proveded side slip angle @NAME: SideSlipAngle  */
  uint32   Pad                 :6; 
#endif
} VDYInSignalState_t;


#endif


/*<---------------------------------------------------------------------------
  Commonly used function
----------------------------------------------------------------------------->*/

/// \brief bit field Configuration of the VDY Component 
typedef struct
{
  uint32       Version;                                          ///< Component version number         */
  vdy_ubit32_t cfg_vdy_yw_dyn_avg                            :1; ///< Enable dynamic gyro offst compensation */
  vdy_ubit32_t cfg_vdy_ex_ywr_nvm                            :1; ///< Enable offset storage  in nonvolatile Memory */
  vdy_ubit32_t cfg_vdy_int_gyro                              :1; ///< Enable internal yaw rate sensor processing */
  vdy_ubit32_t cfg_vdy_fpm_754                               :1; ///< Enable optimized math functio approximation  */
  vdy_ubit32_t cfg_vdy_use_ex_long_accel                     :1; ///< Use external provided longitudinal acceleration signal  */
  vdy_ubit32_t cfg_vdy_use_ex_long_velo                      :1; ///< Use external provided longitudinal velocity signal  */
  vdy_ubit32_t cfg_vdy_mot_state                             :1; ///< Enable motion state processing */
  vdy_ubit32_t cfg_vdy_do_velocity_corr                      :1; ///< Enables the velocity correction   */
  vdy_ubit32_t vel_corr_aln                                  :1; ///< Enables ALN calculated velocity as input for velocity correction   */
  vdy_ubit32_t vel_corr_hist_stationary_targets              :1; ///< Enables stationary targets as input for velocity correction   */
  vdy_ubit32_t cfg_vdy_use_correct_velo_corr_var             :1; ///< Enable lower max. variance of velocity correction factor variance if one measurement update is available */
  vdy_ubit32_t cfg_vdy_rollbench_detection                   :1; ///< Enables the roll bench detection   */								
  vdy_ubit32_t cfg_vdy_use_ext_proc_curvature                :1; ///< Enables usage of external curve as vdy output curve  */
  vdy_ubit32_t cfg_vdy_use_ext_proc_yaw_rate                 :1; ///< Enables usage of external yaw rate as vdy output yaw rate  */
  vdy_ubit32_t cfg_vdy_use_ext_proc_side_slip_angle          :1; ///< Enables usage of external side slip angle as vdy ouput side slip angle  */
  vdy_ubit32_t cfg_vdy_dis_swa_offset_comp                   :1; ///< disable steering wheel sensor offset compensation*/
  vdy_ubit32_t cfg_vdy_dis_ywr_offset_comp                   :1; ///< disable yaw rate sensor offset compensation */
  vdy_ubit32_t cfg_vdy_dis_whs_offset_comp                   :1; ///< disable wheel speed sensor offset compenpensation */ 
  vdy_ubit32_t cfg_vdy_dis_lat_offset_comp                   :1; ///< disable lateral accleration sensor offset compensation */
  vdy_ubit32_t cfg_vdy_use_ext_proc_understeer_grad          :1; ///< Enables usage of external understeer gradient as vdy input parameter  */
  vdy_ubit32_t vdy_use_learned_understeer_grad               :1; ///< If the learned understeer gradiend should be used */
  vdy_ubit32_t vdy_use_est_wld_dep                           :1; ///< If the estimated wheel laod dep should be used */
  vdy_ubit32_t cfg_vdy_use_velo_monitor                      :1; ///< disable wheel speed sensor pre processing */
  vdy_ubit32_t cfg_vdy_ywr_offset_monitor                    :1; ///< disable wheel speed sensor pre processing */
  vdy_ubit32_t cfg_vdy_dis_wheel_pre_processing              :1; ///< disable wheel speed sensor pre processing */
  vdy_ubit32_t cfg_vdy_dis_yaw_sensor_pre_processing         :1; ///< disable yaw rate sensor pre processing */
  vdy_ubit32_t cfg_vdy_dis_yaw_sensor_offs_pre_filtering     :1; ///< disable yaw rate sensor offset pre filtering */
  vdy_ubit32_t cfg_vdy_dis_yaw_sensor_output                 :1; ///< disable yaw rate sensor output */
  vdy_ubit32_t cfg_vdy_dis_lat_accel_sensor_pre_processing   :1; ///< disable lateral acceleration sensor pre processing */
  vdy_ubit32_t cfg_vdy_dis_stw_angle_sensor_pre_processing   :1; ///< disable steering wheel angle pre processing */
  vdy_ubit32_t cfg_vdy_dis_side_slip_angle_estimation        :1; ///< disable the internal side slip angle estimation */
  vdy_ubit32_t cfg_vdy_gen_velocity_variance                 :1; ///< Generated a velocity variance by deviation of the acceleration */
  vdy_ubit32_t cfg_vdy_alignment_offset_monitor              :1; ///< Do yaw rate offset monitoring with alignment offset estimation input */
  vdy_ubit32_t cfg_vdy_dis_functional_safety_mon             :1; ///< Disable functional safety monitoring  */ 
  vdy_ubit32_t cfg_vdy_calc_vdy_timing                       :1; ///< If the timing should be calculated */
  vdy_ubit32_t cfg_vdy_64bit_timestamp_interv                :1; ///< Enables the 64 bit Timestamp interface */ 
  vdy_ubit32_t cfg_vdy_dis_curve_output                      :1; ///< Disable the additional VDY curve output */  
  vdy_ubit32_t cfg_vdy_fs_velo_corr_mon                      :1; ///< Enables the fast velocity to stationary targets monitor  */ 
  vdy_ubit32_t cfg_vdy_mon_output_peaks                      :1; ///< Enables the output peak monitoring */
  vdy_ubit32_t vdy_profiling_enabled                         :1; ///< Enables runtime measurement and profiling */ 
  vdy_ubit32_t cfg_vdy_use_algocompstate                     :1; ///< Enables the compstate output */ 
  vdy_ubit32_t cfg_vdy_set_dem_events                        :1; ///< Enables setting DEM events by VDY, otherwise only the VDYError flags are set */              
  vdy_ubit32_t cfg_vdy_fs_velo_conf_mon_fault                :1; ///< Enables setting DEM event VelMon*/                
  vdy_ubit32_t cfg_vdy_truck_corrfact                        :1; ///< Enables the increase of correction factor for trucks */                            
  vdy_ubit32_t cfg_vdy_debounce_outputs                      :1; ///< Enables the max debouncing ouput counter */                          
  vdy_ubit32_t cfg_vdy_turntable_detection                   :1; ///< Enables the Turn Table detection and limit max. delta 4deg/sec yaw rate offset compensation at one learning cycle */                       
  vdy_ubit32_t cfg_vdy_corrfact_ars4d2                       :1; ///< Enables the increase of correction factor to 30% for ARS4D2 */                           
  vdy_ubit32_t cfg_vdy_swa_ay_yaw_ssd_wld_dis_nvm_valid_check:1; ///< Disables Valid Or Invalid check before reading NVM and writes NVM data  in every vdy cycle to the provide port for camera(MDB) projects for steering wheel angle , Ay ,Yaw offset also SSD and WLD data */    
  vdy_ubit32_t cfg_vdy_velo_variance_check                   :1; ///< Enables the velocity variance check for setting the velocity not available DEM  */                       
  vdy_ubit32_t cfg_vdy_velo_monitor_min_max                  :1; ///< Enables the corrected velocity monitoring based on the new minimum and maximum velocity signals   */                      
  vdy_ubit32_t cfg_vdy_reduce_curve_error                    :1; ///< Enables the code for reducing the curve error after software reset*/                        
  vdy_ubit32_t cfg_vdy_nvm_learn_data_error                  :1; ///< Enable DEM relates NVM learning values to ensure no corrupted data is written to flash memory */                      
  vdy_ubit32_t cfg_vdy_polyspace_error_disable               :1; ///< Disable unused function throwing red error in polyspace  */                  
  vdy_ubit32_t cfg_vdy_vdynviodatard_measfreez_enable        :1; ///< Enable measfreezing of VDY Structure VDYNvIoDataRD  */            
  vdy_ubit32_t cfg_vdy_init_mode_as_startup_mode             :1; ///< Enables the switch to stop toggling the DEM for trucks */                 
  vdy_ubit32_t cfg_vdy_rear_wheel_steering                   :1; ///< Enables the switch to Rear Wheel Steer */                       
  vdy_ubit32_t cfg_vdy_fs_yr_vs_wsp_enable                   :1; ///< Enables the FS_YR_VS_WSP DEM  */                       
  vdy_ubit32_t cfg_vdy_bmw_long_accel_model                  :1; ///< Enables the BMW acceleration Model  */                      
  vdy_ubit32_t cfg_vdy_yawrate_variance_check                :1; ///< Enables the yaw rate variance check for yaw rate not available DEM */                   
  vdy_ubit32_t cfg_vdy_fs_velo_corr_mon_error                :1; ///< Enables the monitor of corrected velocity and ALN velocity error */                    
  vdy_ubit32_t cfg_vdy_fs_veh_corr_mon_toggling              :1; ///< Enables the code to stop toggling of FS_VEH_CORR_MON DEM*/                   
  vdy_ubit32_t cfg_vdy_mfc                                   :1; ///< Enables MFC specific logic */                               
  vdy_ubit32_t cfg_vdy_int_tcs_abs                           :1; ///< Enables usage of ABS/TCS info in velocity and accel estimation */
  vdy_ubit32_t cfg_vdy_mfc_vx                                :1; ///< MFC5xx specific switch */
} VDYConfig_t; 

#if ( defined(VDY_PROFILING_ENABLED) && (VDY_PROFILING_ENABLED == 1) )
#ifdef AS_SERVICEFUNC_VERSION
/*! Profiling IDs and marker */
typedef uint8 VDYProfID_t;

/// \brief
typedef enum eVDYProfID_t
{
  VDY_PROF_ID_ALL          = 0, ///< 0

  VDY_PROF_MARKER_HANDCODE = 10, ///< 10
  VDY_PROF_MARKER_YWRT     = 11, ///< 11
  VDY_PROF_MARKER_VELCORR  = 12, ///< 12
  VDY_PROF_MARKER_YWR      = 13, ///< 13
  VDY_PROF_MARKER_AY_SWA   = 14, ///< 14
  VDY_PROF_MARKER_WHS      = 15, ///< 15

  VDY_PROF_MARKER_AUTOCODE = 20, ///< 20
  VDY_PROF_MARKER_VELOCITY = 21, ///< 21
  VDY_PROF_MARKER_WYE      = 22, ///< 22
  VDY_PROF_MARKER_GYE      = 23, ///< 23
  VDY_PROF_MARKER_AYE      = 24, ///< 24
  VDY_PROF_MARKER_SYE      = 25, ///< 25
  VDY_PROF_MARKER_YE       = 26, ///< 26
  VDY_PROF_MARKER_SAE      = 27, ///< 27
  VDY_PROF_MARKER_MOT_ST   = 28, ///< 28

  VDY_PROF_ID_UNDEF        = 255 ///< 255
} eVDYProfID_t;
#endif
#endif

/// \brief Statistic measurement interval 
typedef struct
{
  float32 Sum;         ///< Sum of samples 
  float32 SqSum;       ///< Square sum of samples 
  float32 Volume;      ///< Accumlated weights of samples 
  float32 Mean;        ///< Mean of samples 
  float32 Dev;         ///< Standard deviation of samples 
} VDYStatInterval_t;
 

/// \brief  Statistic histogram database 
typedef struct
{
  uint32        Size;         ///< Number of bins       
  float32       InvBinWidth;  ///< Inverse of bin width 
  float32       Mean;         ///< Arithmetic mean      
  float32       Dev;          ///< Standard deviation   
  float32       Sum;          ///< Sum of bin volumes    
  float32       *Range;       /*!< Bin ranges @NAME: PRange */
  float32       *Volume;      /*!< Bin volumes @NAME: PVolume */
} VDYHistogram_t;


/// \brief  Curvature signal status 
typedef enum
{
  VDY_CRV_NOTOK,               ///< Curvature outside the limits 
  VDY_CRV_OK,                  ///< Curvature inside the limits 
  VDY_CRV_DONT_KNOW            ///< Signal invalid or uncalibrated 
} eVDYCrvStatus_t;

#if (CFG_USE_COMPACT_ENUMS)
typedef uint8 VDYCrvStatus_t;      ///< using 8bit type for the real enum (32bit type) eVDYCrvStatus_t to save memory
#else
typedef eVDYCrvStatus_t VDYCrvStatus_t; ///< Curvature signal status 
#endif

/// \brief  Curvature direction status 
typedef enum
{
  CRV_DIR_STRAIGHT,            ///< Curvature points straight ahead 
  CRV_DIR_LEFT,                ///< Curvature points to the left side 
  CRV_DIR_RIGHT,               ///< Curvature points to the right side 
  CRV_DIR_DONT_KNOW            ///< Curvature directions can not be determined 
} eVDYCrvDirStatus_t;

#if (CFG_USE_COMPACT_ENUMS)
typedef uint8 VDYCrvDirStatus_t;      ///< using 8bit type for the real enum (32bit type) eVDYCrvDirStatus_t to save memory
#else
typedef eVDYCrvDirStatus_t VDYCrvDirStatus_t; ///< Curvature direction status 
#endif

/// \brief  IIR filter structure 2nd order 
typedef struct
{
  float32 fin;    ///< delayed input samples 
  float32 fout;   ///< delayed ouput samples 
} VDY_IIR2Buff_t[VDY_TWO];


/// \brief  IIR Koeffizienten fuer 2.Ordnung 
typedef struct
{
  float32 num;    ///< numerator coefficients 
  float32 den;    ///< denomintor coefficients first is assumed equal 1 
} VDY_IIR2Coeff_t[VDY_THREE];



/*<---------------------------------------------------------------------------
  Component internal module interfaces
---------------------------------------------------------------------------->*/

/// \brief  Longitudinal motion variables 
typedef struct
{
  fVelocity_t            VehVelocityCorr;	///< Velocity Velocity Correction
  fRatio_t               VelCorrFact;		///< Velocity Correction Factor
  fVelocity_t            VehVelo;			///< Vehicle Velocity
  fVariance_t            VehVeloVar;		///< Vehicle Velocity Variance
  fAccel_t               VehAccel;			///< Vehicle Acceleration
  fVariance_t            VehAccelVar;		///< Vehicle Acceleration Variance
  fVelocity_t            FLWhlVelo;			///< Front Left Wheel Velocity
  fVelocity_t            FRWhlVelo;			///< Front Right Wheel Velocity
  fVelocity_t            RLWhlVelo;			///< Rear Left Wheel Velocity
  fVelocity_t            RRWhlVelo;			///< Rear Right Wheel Velocity
  fVelocity_t            corrVar;			///< Correction Variable
  fVelocity_t            corrVeloVar;		///< Velocity Correction Variable
  MotionStateVehDyn_t    MotState;			///< Vehicle Motion State
} VDYVelAccOut_t;

/// \brief Data Internal Curvature Estimation 
typedef struct 			
{
  float32 C1;			///< Estimated Curve
  float32 Gradient;		///< Curve Gradient
  float32 varC1;		///<
  float32 Quality;		///< Curve Quality
 } CurveInternal_t;	

/// \brief  Component internal intra module interface 
typedef struct
{
  boolean                FirstCycleDone;	///< Indicator if first Cycle is finished
  fTime_t                CycleTime;			///< Cycle Time
  vdy_swa_offset_t       SwaOffset;			///< Steering Wheel Angle Offset
  vdy_yaw_offset_t       YwrOffset;			///< Yax Rate Offset
  vdy_swa_offset_t       AyOffset;			///< Lateral Acceleration Offset
  VDYVelAccOut_t         LongMot;			///< Longitudinal Vehicle Dynamics 
  LatAccelVehDyn_t       LatAcc;			///< Lateral Acceleration
  CurveVehDyn_t          Curve;				///< Curve
  CurveInternal_t        CurveInt;			///< Curve Internal Data
  YawRateVehDyn_t        YawRate;			///< Yax Rate 
  SideSlipVehDyn_t       SideSlipAngle;		///< Side Slip Angle
} VDYModIf_t;

/*<---------------------------------------------------------------------------
  Monitoring data types
----------------------------------------------------------------------------->*/

/// \brief Some last valid Input Signals 
typedef struct
{
#if (BSW_VEH_SIG_INTFVER <= VDY_SEVEN)
  VDYIoState_t        State[VDY_TWO];                ///< io states of the last input signals                    
#else
  VDYIoStateTypes_t   State[VDY_THIRTY_TWO];               ///< io states of the last input signals                    
#endif
  fYawRate_t          YawRate;                 ///< Yaw rate signal                                        
  fAngle_t            StWheelAngle;            ///< Steering wheel angle signal                            
  fAccel_t            LatAccel;                ///< Lateral acceleration sensor signal                     
  fAccel_t            VehLongAccelExt;         ///< Longitudinal acceleration sensor signal                
  fVelocity_t         VehVelocityExt;          ///< Vehicle velocity signal                                
  fVelocity_t         WhlVelFrLeft;            ///< Wheel circumferential velocity front left              
  fVelocity_t         WhlVelFrRight;           ///< Wheel circumferential velocity front right             
  fVelocity_t         WhlVelReLeft;            ///< Wheel circumferential velocity rear left               
  fVelocity_t         WhlVelReRight;           ///< Wheel circumferential velocity rear right              
  fAngle_t            RearWhlAngle;            ///< Rear Steering wheel angle signal                       */
} VDYLastInSig_t;

#if ( (defined(CFG_VDY_MON_OUTPUT_PEAKS)) && (CFG_VDY_MON_OUTPUT_PEAKS) )
/// \brief Some last valid Output Signals 
typedef struct
{
  fCurve_t Curve;                              ///< Yaw rate signal                                        
  VDYErrState_t CurveState;                    ///< io states of the last yawrate output signal            
  VDYActState_t OutputPeakError;               ///< fault state of peak filter                             
  VDYErrState_t InputStwState;                 ///< fault state of last steering wheel input signal        
  boolean LimitCurve;                          ///< flag to activate output limiting                       
} VDYLastOutSig_t;
#endif

#if !(defined(CFG_VDY_DIS_FUNCTIONAL_SAFETY_MON) && (CFG_VDY_DIS_FUNCTIONAL_SAFETY_MON))
/// \brief Functional safety yaw rate check data 
typedef struct
{
  float32 fYawWheelDelta;                        ///< gye-wye                                                
  float32 fYawLatAccelDelta;                     ///< gye-aye                                                
  float32 fYawSteerDelta;                        ///< gye-sye                                                
  float32 fYawWheelOutDist;                      ///< fabs(gye-wye) > xx out of bounce driven distance       
  float32 fYawLatAccelOutDist;                   ///< fabs(gye-aye) > xx out of bounce driven distance       
  float32 fYawSteerOutDist;                      ///< fabs(gye-sye) > xx out of bounce driven distance       
  uint16  nWheelErrorCounter;                    ///< total error counter                                    
  uint16  nLatAccelErrorCounter;                 ///< total error counter                                   
  uint16  nSwaErrorCounter;                      ///< total error counter                                    
} VDYFSYawRateCheck_t;

/// \brief Functional safety curve check  data 
typedef struct
{
  VDYStatInterval_t   VDYFSWyeGyeStat;          ///< Statistic between the wheel yaw rate and the gier yaw rate signale           
  VDYStatInterval_t   VDYFSAyeGyeStat;          ///< Statistic between the lateral accel yaw rate and the gier yaw rate signale   
  VDYStatInterval_t   VDYFSSyeGyeStat;          ///< Statistic between the steering wheel yaw rate and the gier yaw rate signale  
  VDYStatInterval_t   VDYFSAllOverIntervall;    ///< The mean of the three above                                                  
  float32             fDeltaY;                  ///< The actual Delta y for the yaw rate error from VDYFSAllOverIntervall         
  uint16              nCurveErrorCounter;       ///< total error counter                                                          
  uint8               nDeltaYCounter;           ///< If the actual Delta y is above a threshold higher the counter                
} VDYFSCurveCheck_t;

/// \brief Functional safety fault states 
typedef struct
{
  VDYErrState_t  FSIntExtVeloCheck;             ///< Functional safety internal external veloc plausibilty check error         
  VDYErrState_t  FSCorrVeloCheck;               ///< Functional safety corrected velocity plausibilty check error              
  VDYErrState_t  FSMaxLatDisplacementError;     ///< Functional safety lateral displacement error check                        
} VDYFSErrorStates_t;

/// \brief Functional safety internal data 
typedef struct
{
  VDYFSYawRateCheck_t VDYFSYawRateCheck;        ///< Functional safety yaw rate check datas                                       
  VDYFSCurveCheck_t   VDYFSCurveCheck;          ///< Functional safety curve check datas                                          
  VDYFSErrorStates_t  FSMonErrorStates;         ///< The functional safety error states                                           
} VDYFSData_t;
#endif

/*<---------------------------------------------------------------------------
  Sequence init data struct
----------------------------------------------------------------------------->*/

/// \brief Sequence init data struct
typedef union
{
  uint32 states;                              ///< all states  
  struct
  {
    vdy_ubit32_t      vdy_wpp_sequ_init        : 1;         ///< 1 if the vdy wpp module is sequence initialized 
    vdy_ubit32_t      vdy_ve_sequ_init         : 1;         ///< 1 if the vdy ve module is sequence initialized 
    vdy_ubit32_t      vdy_wye_sequ_init        : 1;         ///< 1 if the vdy wye module is sequence initialized 
    vdy_ubit32_t      vdy_gye_sequ_init        : 1;         ///< 1 if the vdy gye module is sequence initialized 
    vdy_ubit32_t      vdy_aye_sequ_init        : 1;         ///< 1 if the vdy aye module is sequence initialized 
    vdy_ubit32_t      vdy_sye_sequ_init        : 1;         ///< 1 if the vdy sye module is sequence initialized 
    vdy_ubit32_t      vdy_ye_sequ_init         : 1;         ///< 1 if the vdy ye module is sequence initialized 
    vdy_ubit32_t      vdy_sae_sequ_init        : 1;         ///< 1 if the vdy sae module is sequence initialized 
    vdy_ubit32_t      vdy_mot_state_sequ_init  : 1;         ///< 1 if the vdy mot state module is sequence initialized 
    vdy_ubit32_t      Pad                      : 23;		///< Padding
  } initStates;
} VDYSequenceInitStates_t;


/*<---------------------------------------------------------------------------
  Steering wheel angle sensor data types
----------------------------------------------------------------------------->*/

/// \brief Steering wheel angle sensor data
typedef struct
{
  fAngle_t         StrgAngle;             /*!< Current measured steering wheel angle @NAME: Angle		*/
  fAngle_t         StrgAngleOld;          /*!< Steering wheel angle measured last cycle @NAME: AngleOld */
  float32          Gradient;              ///< Steering angle gradient non-filtered 
  float32          StrgGradAbsOld;        /*!< Absolute value of swa gradient @NAME: GradAbs */
  fDistance_t      StrgDeltaDist;         /*!< Driven distance with constant swa @NAME: DeltaDist */
  boolean          Valid;                 ///< Steering wheel angle signal validity 
} VDYSwaSenData_t; 
 
/// \brief Steering wheel angle Offset
typedef struct
{
  fAngle_t        Offset;              ///< Steering wheel offset 
  sint32          State;               /*!< Steering wheel offset state @NAME: Status */
  float32         Dev;                 ///< Steering wheel offset standard deviation 
} VDYSwaOffset_t;

/// \brief Steering wheel angle offset NVM read / write 
typedef struct
{
  VDYSwaOffset_t       EEPromStrgOffs;     /*!< NVM steering wheel angle offset @NAME: SwaOffs */
  boolean              EEPromReadOk;       /*!< NVM swa offset access state @NAME: ReadOK */
  boolean              EEPromWriteRequ;    /*!< NVM swa offset access request @NAME: WriteReq */
} VDYSwaOffsEEprom_t;

/// \brief Steering wheel angle offset calibration histogram bins 
typedef struct
{
  float32 Range[SWA_OFFS_HIST_NO_BINS];     ///< Range  
  float32 Volume[SWA_OFFS_HIST_NO_BINS];    ///< Counts 
} VDYSwaHistBin_t;

/// \brief Steering wheel angle offset calibration 
typedef struct
{
  VDYHistogram_t     Hist;            ///< Histogram 
  VDYSwaHistBin_t    Bin;             ///< Histogram bins 
  fAngle_t           Offs;            /*!< Estimated offset value @NAME: Offset */
  float32            ThrldDev;        /*!< Maximum deviation for new offset estimation @NAME: ThrhdDev */
  fDistance_t        ThrldDist;       /*!< Mininum distance for new offset estimation @NAME: ThrhdDist */
  fQuality_t         Conf;            /*!< Confidence of new estimation @NAME: Confidence */
} VDYSwaOffsEst_t;

/// \brief Steering wheel angle offset data
typedef struct
{
  boolean            StrgOffsReadOk;         /*!< Flag signaling correction read of swa offset @NAME: ReadOK */
  fAngle_t           StrgOffset;             /*!< Active steering wheel angle offset @NAME: Offset */
  fAngle_t           StrgOffsetNorm;         /*!< Current steering wheel offset normalized @NAME: OffsetNorm */
  sint32             OffsState;              /*!< Calibration state steering wheel angle offset @NAME: Status */
  float32            Dev;                    ///< Standard deviation                                 
  uint32             OvrTakeCntr;            ///< Number of taken offset estimation during ignitions cycle 
  fVelocity_t        WhlFrDiffFilt;          ///< Filtered wheel velocity differences front axle 
  fVelocity_t        WhlReDiffFilt;          /*!< Filtered wheel velocity differences rear axle @NAME: WhlReDiffFlt */
  fAccel_t           LatAccel;               ///< Integrated lateral acceleration 
  boolean            OffsInterimOk;          /*!< Offset zwischengespeichert in der Hochlaufphase  @NAME: StatOffsIntOK  */
  VDYSwaOffsEst_t    Est;                    /*!< Offset estimation section @NAME: SwaOffsEst */
  boolean            ErrStrgOffsOutOfRange;  /*!< Error indication swa offset out of range @NAME: ErrOffsRg */
  uint8              ReInitCntr;             ///< Repeat reinit counter of Histogramm 
} VDYSwaOffsData_t; 

/// \brief Fast offset estimation data  
typedef struct
{
  float32 f_WhlVelFrDiffFilt;	///< Front wheel speeds difference
  float32 f_WhlVelReDiffFilt;	///< Rear wheel speeds difference
  float32 f_Sum;				///< Sum of Short Term  Steering Angle Offset
  float32 f_Mean;				///< Mean of Short Term  Steering Angle Offset
  float32 f_Offset;				///< Long Term Steering Angle Offset
  uint16  u_Number;				///< Number of samples of Short Term  Steering Angle Offset
  uint16  Vol;
  float32 SumVol;
  uint8   Fast_Offset_State;
} s_VDYFastSwaOffset_t; 

/// \brief Input/Output interface 
typedef struct
{
  const VDYInputData_t *in;					///< VDY Input Data
  VDYModIf_t           *mif;				///< Component internal intra module interface
  VDYErrState_t        *errOffsRg;			///< Error offset range
  VDYErrState_t        *NVMerrOffsRg;		///< NVM Error offset range
#if ( (defined(CFG_VDY_NVM_LEARN_DATA_ERROR)) && (CFG_VDY_NVM_LEARN_DATA_ERROR) )
  VDYErrState_t        *SwaNVMErrOffsRg;    ///< check for valid values written into NVM  
#endif
} VDYSwaIo_t;

/* Last Cycle Steering ,Ay and Yaw Offset written to NVM */
#if( (defined(CFG_VDY_SWA_AY_YAW_SSD_WLD_DIS_NVM_VALID_CHECK))&&(CFG_VDY_SWA_AY_YAW_SSD_WLD_DIS_NVM_VALID_CHECK))

/// \brief
typedef struct
{
  fAngle_t ZeroAngle; ///< Zero point reference stored in NVM - SWA offset
  uint32 CalStatus; ///< Quality of the signal at zero point
 } VDYLastNvStWhlAngCal_t; ///< 

/// \brief
typedef struct
{
  fAngle_t ZeroAngle; ///< Zero point reference stored in NVM - Lateral Acceleration offset
  uint32 CalStatus; ///<
 } VDYLastNvAyCal_t; ///< Quality of the signal at zero point

/// \brief
typedef struct
{
  fYawRate_t ZeroRate; ///< Zero point reference stored in NVM - yaw rate offset
  fYawRate_t ZeroRateMin; ///< 
  fYawRate_t ZeroRateMax; ///<
  uint32 CalStatus; ///< Quality of the signal at zero point
 } VDYLastNvYawCal_t;

#endif

/// \brief Steering wheel angle processing database  
typedef struct
{
  VDYSwaSenData_t      Sensor;            /*!< Sensor signal processing @NAME: Sen */ 
  VDYSwaOffsData_t     Offset;            /*!< Offset estimation @NAME: Offs        */
  VDYSwaOffsEEprom_t   NVValue;           /*!< Nonvolatile memory data @NAME: Nv    */
  s_VDYFastSwaOffset_t FastSwaOffset;     ///< Fast offset estimation data          
  VDYSwaIo_t           Io;                ///< Input/Output interface               
} VDYSwaData_t;


/*<---------------------------------------------------------------------------
  Lateral Accleration sensor data types
----------------------------------------------------------------------------->*/

/// \brief Lateral acceleration sensor data  
typedef struct
{
  fAccel_t         Ay;                    ///< Current lateral acceleration              
  fAccel_t         AyOld;                 ///< Last cycle lateral acceleration           
  float32          Gradient;              ///< Raw acceleration gradient                 
  float32          AyGradAbsOld;          ///< Last cycle absolute gradient value        
  boolean          Valid;                 ///< Lateral Acceleration  valid (TRUE|FALSE)  
} VDYAySenData_t; 

/// \brief Lateral acceleration offset calibration histogram bins  
typedef struct
{
  float32 Range[AY_OFFS_HIST_NO_BINS];      ///< Range   
  float32 Volume[AY_OFFS_HIST_NO_BINS];     ///< Counts  
} VDYAyHistBin_t;

/// \brief Lateral acceleration offset estimation  
typedef struct
{
  VDYHistogram_t      Hist;              ///< Histogram  
  VDYAyHistBin_t      Bin;               ///< Histogram bins  
  fAccel_t            Offs;              ///< Estimated offset value  
  float32             ThrldDev;          ///< Maximum deviation for new offset estimation   
  fDistance_t         ThrldDist;         ///< Mininum distance for new offset estimation    
  fConfidence_t       Conf;              ///< Confidence of new estimation  
} VDYAyOffsEst_t;

/// \brief Lateral acceleration offset calibration  
typedef struct
{
  fAccel_t            AyOffset;			///< Current lateral acceleration sensor offset                
  sint32              OffsState;		///< Calibration state lateral acceleration offset             
  float32             Dev;				///< Standard deviation                                        
  uint32              OvrTakeCntr;		///< Number of taken offset estimation during ignitions cycle  
  VDYAyOffsEst_t      Est;				///< Offset estimation section                                 
  boolean             AyOffsReadOk;		///< Singnalize that nonvolatile offset has been read          
  boolean             Interims;			///< Interims offst active  
} VDYAyOffsData_t; 

/// \brief Lateral Accelaration Input/Output interface   
typedef struct
{
  const VDYInputData_t *in;				///< VDY Input Data
  VDYModIf_t           *mif;			///< Component internal intra module interface
  const VDYNvIoData_t  *nv_read;		///< nvm read data interface
  VDYNvIoData_t        *nv_write;		///< nvm write data interface
  VDYErrState_t        *errOffsRg;		///< Lateral Acceleration Offset Error Range
  VDYErrState_t        *NVMerrOffsRg;	///< NVM Offset Error Range
#if ( (defined(CFG_VDY_NVM_LEARN_DATA_ERROR)) && (CFG_VDY_NVM_LEARN_DATA_ERROR) )
  VDYErrState_t        *AyNVMerrOffsRg;	///< check for valid values written into NVM  
#endif
} VDYAyIo_t;

/// \brief Lateral Acceleration Data 
typedef struct
{
  VDYAySenData_t      Sensor;            ///< Lateral Acceleration Sensor signal processing           
  VDYAyOffsData_t     Offset;            ///< Lateral Acceleration Offset estimation                  
  VDYAyIo_t           Io;                ///< Lateral Acceleration Input/Output interface             
} VDYAyData_t;


/*<---------------------------------------------------------------------------
  Yaw rate sensor data types
----------------------------------------------------------------------------->*/
/// \brief Yaw rate zero point offset types  
typedef enum
{                           
   OFFS_NON            = 0               ///< No offset type present  
  ,OFFS_STANDST        = 1               ///< Offset acquired from standstill  
  ,OFFS_DYN_APPRX      = 3               ///< Offset merged standstill and temp table  
  ,OFFS_TEMPER_TABLE   = 4               ///< Offset acquired from temperature table   
#if (CFG_VDY_EX_YWR_NVM)
  ,OFFS_STANDST_EEPROM = 5               ///< Offset acquired from non-volatile memory  
#endif
  ,OFFS_DYN_AVG        = 6               ///< Offset estimated by averaging  
  ,OFFS_DYN_INTER      = 7
} eVDYYwrOffsType_t;

#if (CFG_USE_COMPACT_ENUMS)
typedef uint8 VDYYwrOffsType_t;      ///< using 8bit type for the real enum (32bit type) eVDYYwrOffsType_t to save memory 
#else
typedef eVDYYwrOffsType_t VDYYwrOffsType_t; ///< Yaw rate zero point offset types  
#endif

/// \brief Yaw rate standstill offset compensation  
typedef struct
{
  fYawRate_t          YawRateOffset;        /*!< Current standstill offset @NAME: StOffset  */
  fQuality_t          MaxQuality;           /*!< Maximum confidence reached at calibration @NAME: StMaxQual  */
  fTime_t             AdjustTime;           /*!< Time elapsed since last calibration @NAME: AdjTime  */
  VDYStatInterval_t   SampleInterval_1;     /*!< Sample gathering interval @NAME: SplInt_1  */
  VDYStatInterval_t   SampleInterval_2;     /*!< Sample delay  interval @NAME: SplInt_2  */
  VDYStatInterval_t   SampleInterval;       /*!< Sample offset evaluation interval @NAME: SplInt  */
  boolean             StandstillOK;         /*!< Standstill for offset calibration  @NAME: StStOK  */
  boolean             Observable;           ///< Observation of yaw rate offset possible  
} VDYYwrStandStillOffs_t;

/// \brief Yaw rate EEPROM offset   
typedef struct
{
  fYawRate_t         Offset1;           ///< Current StandStill Offset 1                              
  uint8              Status1;           ///< Number of learning values corresponds to a value of the stored offset 1
  fYawRate_t         Offset2;           ///< Current StandStill Offset 2                              
  uint8              Status2;           ///< Number of learning values corresponds to a value of the stored offset 2 
} VDYYwrEepromOffset_t;

/// \brief Yaw rate standstill EEPROM offset  
typedef struct
{
  VDYYwrEepromOffset_t YawRateOffset;                 ///< Offset from EEPROM  
  fTime_t              TimeLastWrittenEepromOffset;   /*!< Time since last standstill offset @NAME: TimeLstWr   */
  fQuality_t           MaxQuality;                    /*!< Quality of the offset, increases as the number of readings increases @NAME: MaxQual  */
  uint8                NumOfWrittenOffsets;           /*!< Number of offsets written in this delivery cycle @NAME: NoWrOffs  */
} VDYYwrStandStillEepromOffs_t;


/// \brief Dynamic Yaw Rate-Interims-Offset for Initial state
typedef struct
{
  fYawRate_t      YawRateOffset;	/*!< Estimated Offset @NAME: Offset  */
  VDY_IIR2Buff_t  YwFiltInt;		///< Filter Element
  fQuality_t      MaxQuality;		///< Quality of the Estimated Offset  
  fDistance_t     DistThrd;			///< Threshold
} VDYYwrDynOffsInter_t;

/// \brief Dynamic yaw rate Matching data over averaged yaw rate  
typedef struct
{
  fYawRate_t           YawRateOffset;		/*!< Estimated Dynamic Yaw Rate Offset @NAME: DynOffset  */
  fQuality_t           MaxQuality;			/*!< Quality of Estimated Dynamic Yaw Rate Offset @NAME: DynMaxQual  */
  fDistance_t          accYwDist;			///< Accumulated distance for pre-filtering  
  fDistance_t          YwDist;				///< Distance that goes into averaging  
  fDistance_t          StDrv;				///< Distance for steering angle test 
  fDistance_t          YwDrvDistThr;		/*!< Counter @NAME: DisThrd  */
  VDY_IIR2Buff_t       YwFilt;				/*!< Filter Element @NAME: AvgFilt  */
  uint32               cntCycle;			///< Cycle Count (Einschwingen FIR-Fitler)  
  fTime_t              LastEcuTime;			///< Current ECU-Time  
  fDistance_t          DrvDistRed;			/*!< Distance traveled to reduce the asymmetry @NAME: DrvDstRed  */
  fYawRate_t           YawRateDet;			/*!< Detection filter value @NAME: DetOffs   */
  VDY_IIR2Buff_t       YwFiltDet;			/*!< Filter Element @NAME: DetFilt  */
  fQuality_t           QReduce;				///< Quality Reduction  
  boolean               FlStwAStat;			/*!< Steering Angle Offset Sufficient Quality  Flag @NAME: FlStwStat  */
  VDYYwrDynOffsInter_t IntOffs;				/*!< Dynamic Yaw Rate-Interims-Offset for Initial state \n @NAME: IntFilt  */
} VDYYwrDynOffsAvg_t;


/// \brief Latch for offset averaged offset from various dynamic offset types  
typedef struct
{
  fYawRate_t           YawRateOffset;        ///< Estimated Offset  
  fQuality_t           Quality;              ///< Quality of the estimated Offsets  
} VDYYwrDynOffsCache_t;

/// \brief Interface to Autocode
typedef struct
{
  vdy_yaw_offset_t OffsData;				///< The actual offset  
  boolean          IsDynamic;				///< If it is an old dynamic offset (mean filter)  
} ToAutocode_t;


/// \brief Zero point offset
typedef struct
{
  fYawRate_t                   YawRateOffset;			/*!< Estimated Yaw Rate Offset @NAME: Offset  */
  fQuality_t                   Quality;					///< Quality of Estimated Yaw Rate 
  fQuality_t                   MaxQuality;				/*!< Maximum Quality in offset calculation @NAME:MaxQual  */
  fTime_t                      OffsElpsdTime;			/*!< Time since the last reconciliation in s @NAME: OffsElpTime  */
  fTemperature_t               Temperature;				///< Temperature when determining the offset 
  VDYYwrStandStillOffs_t       StandStillOffset;		/*!< Standstill offset data @NAME: StandStill  */
  VDYYwrStandStillEepromOffs_t StandStillEepromOffset;	/*!< EEPROM-Offset Data @NAME: StandStillNvm  */
  VDYYwrDynOffsAvg_t           DynOffsAvg;				/*!< @NAME: Dynamic  */
  fQuality_t                   QualNoRed;				/*!< @NAME: QNoRed  */
  VDYYwrDynOffsCache_t         Cache;					///< Latch for offset averaged offset from various dynamic offset types
  fTime_t                      EcuElpsdTime;			/*!< Time Since ECU Start in s @NAME: ElpTime  */
  boolean                      OffsCompOK;				///< Kompensation erfolgt  
  boolean                      TemperOK;				/*!< Getemperte Kompensation erfolgt @NAME: TempCompOK */
  VDYYwrOffsType_t             OffsType;				/*!< Yaw rate zero point offset types @NAME:Type  */
  ToAutocode_t                 ToAutocode;				///< Interface to autocode  
}VDYYwrOffsData_t;



/// \brief Noch nicht benoetigt \n Vorgesehen fuer internen Drehratensensor  
typedef enum 
{
  YWR_INTERN,
  YWR_EXTERN
} eVDYYwrSensorType_t;

#if (CFG_USE_COMPACT_ENUMS)
typedef uint8 VDYYwrSensorType_t;      ///< using 8bit type for the real enum (32bit type) eVDYYwrSensorType_t to save memory 
#else
typedef eVDYYwrSensorType_t VDYYwrSensorType_t; ///< Noch nicht benoetigt \n Vorgesehen fuer internen Drehratensensor  
#endif

/// \brief Yaw rate sensor data  
typedef struct
{
  fYawRate_t    YawRate;             ///< Measured yaw rate  
  fYawRate_t    YawRateOld;          /*!< Yaw rate previous cycle @NAME: YawRtOld  */
  fCurve_t      YawRateCurveFilt1;   /*!< Drehrate Kuemmung Filter @NAME: YawRtCrvFlt1 */  
  fCurve_t      YawRateCurveFilt2;   /*!< Drehrate Kuemmung Filter @NAME: YawRtCrvFlt2  */
  fCurve_t      YawRateCurveFilt3;   /*!< Drehrate Kuemmung Filter @NAME: YawRtCrvFlt3  */
  fCurve_t      YwCurveOld;          /*!< Kruemmung letzter Zyklus fuer Gradientberechnung @NAME: YawRtCrvOld           */
  float32       Gradient;            ///< Drehraten Gradient ungefiltert  
  float32       GradientAbsOld;      ///< Drehraten Gradien vorhergehender Zyklus  
  float32       DeltaDist;           ///< Weg mit const Drehrate 0 ... 150 m  
  boolean       Valid;               ///< Gueltigkeitsbit fuer Drehrate  
  boolean       YwFirstCycleDone;    /*!< Zyklus nach nach Init durchgefuehrt @NAME: CycleDone */
  fTime_t       FilterTime;          /*!< Filterzeit der Drehratenspur @NAME: FTime */
} VDYYwrSenData_t;

/// \brief Schnelle Drehraten Spur
typedef struct
{
  const VDYInputData_t *in;			///< VDY Input Data
  VDYModIf_t           *mif;		///< Component internal intra module interface
  const VDYNvIoData_t  *nv_read;	///< NVM read data
  VDYNvIoData_t        *nv_write;	///< NVM write data
#if ( (defined(CFG_VDY_NVM_LEARN_DATA_ERROR)) && (CFG_VDY_NVM_LEARN_DATA_ERROR) )
  VDYErrState_t        *YwrNVMerrOffsRg;    ///< check for valid values written into NVM  
#endif
} VDYYwrIo_t;

/// \brief Yaw rate sensor data processing  
typedef struct
{
  VDYYwrSenData_t    Sensor;               /*!< Yaw rate sensor data  @NAME: Sen  */
  VDYYwrOffsData_t   Offset;               /*!< Zero point offset @NAME: Offs  */
  CurveVehDyn_t      CrsYwRt;              /*!< Drehraten Spur @NAME: Crv  */
  CurveVehDyn_t      CrsYwRtFast;          /*!< Schnelle Drehraten Spur @NAME: CrvFast  */
  VDYYwrIo_t         Io;
} VDYYwrData_t;

/*<---------------------------------------------------------------------------
  Internal yaw rate sensor data types
----------------------------------------------------------------------------->*/

/// \brief Internal yaw rate sensor data types
typedef struct
{
  fYawRate_t      YawRate;             ///< Current yaw rate     
  fYawRate_t      YawRateOld;          ///< Yaw rate last cycle  
  float32         Gradient;            ///< Yaw rate gradient    
  fTemperature_t  Tempr;               ///< Current yaw rate sensor temperature  
  fTemperature_t  TemprOld;            ///< Yaw rate sensor temperature last cycle  
  fGradient_t     TempGrad;            ///< Yaw rate temperature gradient  
  boolean         Valid;               ///< Validity  of yaw rate signal  
  boolean         StandstillOK;        ///< Vehicle standstill flag  
  boolean         obsOffs;             ///< Yaw rate offset during standstill observable  
  boolean         YwFirstCycleDone;    ///< First non-init cycle completed  
} VDYYwrtSenData_t;

/// \brief Yaw rate offset table node  
typedef struct
{
  float32 Offset;            ///< Learned offset minimum value          
  float32 Conf;              ///< Confidence of learned offset values   
  uint8   No;                ///< Node number (=index) of offset table  
} VDYYwrtLearnNode_t;

/// \brief Yaw rate table offset data  
typedef struct
{
  VDYYwrtLearnNode_t Left;           ///< Nearest left (lower) table node at current temperature  
  VDYYwrtLearnNode_t Right;          ///< Nearest right (higher) table node at current temperature  
  VDYStatInterval_t  SmpYwRt;        ///< Sample interval internal gyro yaw rate   
  VDYStatInterval_t  SmpTemp;        ///< Sample interval internal gyro temperature  
  fYawRate_t         Offset;         ///< Current yaw rate offset based on correction table  
  fConfidence_t      Conf;           ///< Current confidence of yaw rate offset  
  uint16             LearnCnt;       ///< Learn progress counter during standstill  
  uint16             LearnAgainCnt;  ///< Relearn (max. confidence has been reached) counter  
  fTemperature_t     LastOffsTemp;   ///< Temperature of last offset learn iteration   
  boolean            bWrLeft;        ///< Left table node write non-volatile memory flag  
  boolean            bWrRight;       ///< Right table node write non-volatile memory flag  
  boolean            Valid;          ///< Validity for yaw rate offset  
  boolean            Checked;        ///< Flag to indicate that table interpolation values has been checked  
} VDYYwrtOffsTblData_t;

/// \brief Yaw rate offset data  
typedef struct
{
  VDYYwrtOffsTblData_t   Tbl;                    ///< Offset temperature table  
  VDYYwrStandStillOffs_t StSt;                   ///< Standstill offset data  
  VDYYwrOffsType_t       OffsType;               ///< Active final offset  
  fYawRate_t             YawRateOffset;          ///< Current yaw rate offset  
  fQuality_t             MaxQuality;             ///< Confidence of last standstill calibration  
  fQuality_t             Quality;                ///< Current confidence of offset  
  fTime_t                OffsElpsdTime;          ///< Time elapsed since last standstill calibration  
  fTemperature_t         Temperature;            ///< Temperature during last standstill calibration  
  fConfidence_t          confTbl;                ///< Current confidence of table offset  
  fConfidence_t          confStSt;               ///< Current confidence of standstill offset  
  fYawRate_t             YwRtTblOffsStSt;        ///< Table offset during standstill calibration  
  ToAutocode_t           ToAutocode;             ///< Interface to autocode  
} VDYYwrtOffsData_t;

/// \brief internal interface between modules 
typedef struct
{
  VDYModIf_t           *mif;  ///< Component internal intra module interface
} VDYYwrtIo_t;

/// \brief Internal yaw rate temperature data structure
typedef struct
{
  VDYYwrtSenData_t   Sensor;    ///< module internal yawrate data  
  VDYYwrtOffsData_t  Offset;    ///< offset Data                 
  VDYYwrtIo_t        Io;		///< 
} VDYYwrtData_t;


/*<---------------------------------------------------------------------------
 Yaw rate sensor offset monitoring
----------------------------------------------------------------------------->*/

/// \brief Yaw rate offset monitoring database during vehicle halt  
typedef struct
{
  fTime_t timeAboveThrhd;  ///< Elapsed time with yaw rate above allowed thershold  
} VDYYwrMonVehHalt_t;

/// \brief Yaw rate offset monitoring database before vehicle drive-off  
typedef struct
{
  fTime_t timeAboveThrhd;  ///< Elapsed time with yaw rate above allowed thershold  
} VDYYwrMonVehDriveOff_t;

/// \brief Yaw rate offset monitoring state after vehicle-halt and before drive-off  
typedef enum
{
  VDY_YWR_MON_STATE_HALTING  = 0,  ///< Acquire data for offset after vehicle halt  
  VDY_YWR_MON_STATE_STANDING = 1,  ///< Acquire data for first offset during vehicle halt  
  VDY_YWR_MON_STATE_WAITING  = 2   ///< Acquire data for future vehicle drive-off  
} eVDYYwrMonVehHaltDrvState_t;

#if (CFG_USE_COMPACT_ENUMS)
typedef uint8 VDYYwrMonVehHaltDrvState_t;      ///< using 8bit type for the real enum (32bit type) eVDYYwrMonVehHaltDrvState_t to save memory 
#else
typedef eVDYYwrMonVehHaltDrvState_t VDYYwrMonVehHaltDrvState_t; ///< Yaw rate offset monitoring state after vehicle-halt and before drive-off 
#endif

/// \brief Yaw rate offset monitoring database after vehicle-halt and before drive-off  
typedef struct
{
  VDYStatInterval_t          ivSample;    ///< Sample window to get offset values  
  VDYYwrMonVehHaltDrvState_t State;       ///< Monitor state  
  fYawRate_t                 ywrStStOn;   ///< Yaw rate offset after standstill  
  fYawRate_t                 ywrStStOff;  ///< Yaw rate offset befor drive-off  
} VDYYwrMonVehHaltDrv_t;


typedef uint8 VDYYwrMonVehHaltCalState_t; ///< Yaw rate offset calibration monitoring state during vehicle halt  

#define VDY_YWR_MON_CAL_STATE_MUTE     ((VDYYwrMonVehHaltCalState_t) 0UL) ///< VDY Yaw rate monitor calibration state mute
#define VDY_YWR_MON_CAL_STATE_ARMED    ((VDYYwrMonVehHaltCalState_t) 1UL) ///< VDY Yaw rate monitor calibration state armed

/// \brief Yaw rate offset calibration monitoring database during vehicle halt  
typedef struct
{
  VDYStatInterval_t ivSample;             ///< Sample window to get offset values  
  fTime_t timeStStToCalib;                ///< Time elpased since standstill to first calibration  
  uint8 cntCalCycle;
  VDYYwrMonVehHaltCalState_t State;
} VDYYwrMonVehHaltCal_t;

/// \brief Yaw rate offset monitoring database  
typedef struct
{
  fTime_t                timeVehHalt;     ///< Elapsed time since standstill start  
  fYawRate_t             ywRateOld;       ///< Yaw rate value from last cycle  
  fGradient_t            Gradient;        ///< Yaw rate gradient  
  VDYYwrMonVehHalt_t     VehHalt;         ///< Monitor during vehicle-halt  
  VDYYwrMonVehDriveOff_t VehDriveOff;     ///< Monitor before vehicle-drive-off  
  VDYYwrMonVehHaltDrv_t  VehHaltDrv;      ///< Monitor at standstill start and end  
  VDYYwrMonVehHaltCal_t  VehHaltCal;      ///< Monitor calibration during vehicle-halt   
} VDYYwrMonData_t;


/*<---------------------------------------------------------------------------
  Wheel speed sensor data types
----------------------------------------------------------------------------->*/

/// \brief Wheel speed axle raw data  
typedef struct
{ 
  fVelocity_t    WspLeft;          /*!< Wheel velocity left @NAME: Left  */
  fVelocity_t    WspRight;         /*!< Wheel velocity right @NAME: Right  */
  boolean        WspValid;         /*!< Wheel velocity on axle valid @NAME: Valid  */
  float32        Ratio;            /*!< Wheel velocity ration left / right  */
  fVelocity_t    WspLeftFilt1;     /*!< Wheel velocity left filter stage 1 @NAME: LeftFilt1  */
  fVelocity_t    WspRightFilt1;    /*!< Wheel velocity right filter stage 1 @NAME: RightFilt1  */
  fVelocity_t    WspLeftFilt2;     /*!< Wheel velocity left filter stage 2 @NAME: LeftFilt2   */
  fVelocity_t    WspRightFilt2;    /*!< Wheel velocity left filter stage 2 @NAME: RightFilt2   */
} VDYWhsAxisData_t;

/// \brief Wheel velocities left and right per axle  
typedef struct
{
  fVelocity_t   WspLeft;    /*!< Wheel velocity left @NAME: Left  */
  fVelocity_t   WspRight;   /*!< Wheel velocity right @NAME: Right  */
} VDYWhsSpeedsAxle_t;
  
/// \brief Wheel speed sensor data  
typedef struct
{ 
  VDYWhsSpeedsAxle_t WspFrontRaw;           /*!< Wheel speed front axle raw @NAME: FrontRaw  */
  VDYWhsSpeedsAxle_t WspRearRaw;            /*!< Wheel speed rear axle raw @NAME: RearRaw   */
  fVelocity_t        WspRawRL;              /*!< Wheel speed raw rear left @NAME: RawRL  */
  fVelocity_t        WspRawRR;              /*!< Wheel speed raw rear right @NAME: RawRR  */ 
  VDYWhsAxisData_t   WspFornt;              /*!< Wheel speed front axle @NAME: Front  */
  VDYWhsAxisData_t   WspRear;               /*!< Wheel speed rear axle @NAME: Rear   */
  fCurve_t           CurveOld;              /*!< Ungefilterte Kruemmung letzter Zyklus @NAME: CrvOld */
  fVelocity_t        VehSpeedOld;           /*!< Ego velodity of last cycle  */
  float32            VehAcceleration;       /*!< Vehicle acceleration @NAME: VehAccel */
  boolean            Aquaplaning;           /*!< Hydroplaning detected @NAME: Hydroplan  */
} VDYWhsSenData_t;

/// \brief Wheel velocity offset axle data  
typedef struct
{ 
  VDYStatInterval_t   Interval[WHS_SPEEED_RANGE_VOLUME]; /*!< Averaging velocity ranges @NAME: Intv */
  VDYStatInterval_t   SampleInterval;                    /*!< Sample interval  @NAME: IntvSpl  */
  float32             SampleIntFiltMean;                 /*!< Mean filtered mean of sample Intervall  */
  float32             Factor;                            /*!< Tune factor, to rise sample interval weight  */
  sint32              IntervalRangeVolume;               /*!< Reference to velocity range @NAME: Volume    */
}VDYWhsAxleOffs_t;

/// \brief Wheel velocity offset data  
typedef struct
{ 
  VDYWhsAxleOffs_t  OffsFront;        /*!< Offset front axle @NAME: Front  */
  VDYWhsAxleOffs_t  OffsRear;         /*!< Offset rear axle @NAME: Rear  */
  VDYCrvStatus_t    ExWspStatus;      /*!< Gesammtspur ohne RDZ Geradeausfahrt (OK|NOTOK|DONT_KNOW)  */
  fDistance_t       WspDeltaDist;     /*!< Weg mit const RDZ-Kruemmung @NAME: DeltaDist  */
  float32           GradAbsOld;       /*!< Peak filtered absolute value of gradient  */
  sint32            SpeedRange;       /*!< Velocity range  */
  sint32            LastSpeedRange;   /*!< Velocity range last cycle  */
} VDYWhsOffsData_t;

/// \brief Wheel speeds data interface
typedef struct
{
  const VDYInputData_t *in;		///< VDY Input Data
  VDYModIf_t           *mif;	///< Component internal intra module interface
} VDYWhsIo_t;

/// \brief Wheel speed processing database  
typedef struct
{
  VDYWhsSenData_t  Sensor;        /*!< Wheel speed sensor data @NAME: Sen  */
  VDYWhsOffsData_t Offset;        /*!< Wheel speed offset data @NAME: Offs  */
  VDYWhsIo_t       Io;			/*!< */
} VDYWhsData_t;


/*<---------------------------------------------------------------------------
  Curve / Yaw rate estimation 
----------------------------------------------------------------------------->*/

/// \brief Gewichte fuer Standard-Spur 
typedef struct
{
  float32 Yw;		///< Not Used
  float32 Wsp;		///< Not Used
  float32 Strg;		///< Not Used
  float32 StrgLog;	///< Not Used
} VDYCrvWghtStd_t;

/// \brief Gewichte fuer Schnelle-Spur
typedef struct
{
  float32 Yw; ///< Not Used
  float32 Strg; ///< Not Used
} VDYCrvWghtFast_t;

/// \brief merged (mean) curve data
typedef struct
{
  fCurve_t         CurveStandardOld;     ///< Gesamtkruemmung letzter Zyklus Standard-Spur       
  fCurve_t         CurveFastOld;         ///< Gesamtkruemmung letzter Zyklus Schnelle-Spur       
  fQuality_t       CurveGradQuality;     ///< Spur Gradient Guete                                
  VDYCrvWghtStd_t  Weight;               ///< Gewichte fuer Standard-Spur                        
  VDYCrvWghtFast_t WeightFast;           ///< Gewichte fuer Schnelle-Spur                        
  fVelocity_t      VehSpeedOld;          ///< Eigengeschwindigkeit letzter Zyklus                
  fAccel_t         VehAcceleration;      ///< Fzg. Beschleunigung                                
  float32          WspWeightFact;        ///< Situationsabhaengiger Gewichtungsfaktor WSP        
  boolean          ErrCanNotCalcTrack;   ///< Status Fehler "ERR_LP_TRACKMERGE_CANT_CALC_TRACK"  
} VDYCrvMergeData_t;

/// \brief VDY curve interface
typedef struct
{
  const VDYInputData_t *in;			///< VDY Input Data
  VDYModIf_t           *mif;		///< Component internal intra module interface
  VDYErrState_t        *errNotCalc;	///< Error Statr
} VDYCrvIo_t;


/*<---------------------------------------------------------------------------
  Ego velocity correction
----------------------------------------------------------------------------->*/
#if ( (defined(CFG_VDY_DO_VELOCITY_CORR)) && (CFG_VDY_DO_VELOCITY_CORR) )
/// \brief
typedef enum
{
  VEL_CORR_INIT    = 0, ///< 0
  VEL_CORR_STARTUP = 1, ///< 1
  VEL_CORR_BACKUP  = 2, ///< 2
  VEL_CORR_READY   = 3  ///< 3
} eVDYCorrState_t;

#if (CFG_USE_COMPACT_ENUMS)
typedef uint8 VDYCorrState_t;      ///< using 8bit type for the real enum (32bit type) eVDYCorrState_t to save memory
#else
typedef eVDYCorrState_t VDYCorrState_t;
#endif

#if (VEL_CORR_HIST_STATIONARY_TARGETS)
/// \brief
typedef struct
{
  uint16             binVelRatio[REF_SPEED_NO_BINS];  ///< Occurences of velocity ratios within bounds       
  uint16             binVelRatOutLo;                  ///< Occurrences of velocity ratios below lower bound  
  uint16             binVelRatOutHi;                  ///< Occurrences of velocity ratios below upper bound  
  uint8              cntSample;                       ///< Sample counter of input histogram                 
  float32            Median;                          ///< Arithmetic mean                                   
  float32            Dev;                             ///< Standard deviation                                
  float32            Sum;                             ///< Sum of bin volumes                                
  VDYStatInterval_t  EgoVel;                          ///< Referenced, uncorrected ego velocity              
} VDYRefSpeed_t;
#elif (VEL_CORR_ALN)
/// \brief
typedef struct
{
  float32            binVelRatio[REF_SPEED_NO_BINS];  ///< Occurences of velocity ratios within bounds       
  uint16             binVelRatOutLo;                  ///< Occurrences of velocity ratios below lower bound  
  uint16             binVelRatOutHi;                  ///< Occurrences of velocity ratios below upper bound  
  uint8              cntSample;                       ///< Sample counter of input value                     
  float32            Median;                          ///< Arithmetic mean                                   
  float32            Dev;                             ///< Standard deviation                                
  float32            Sum;                             ///< Sum of bin volumes                                
  VDYStatInterval_t  EgoVel;                          ///< Referenced, uncorrected ego velocity              
} VDYRefSpeed_t;
#else
#pragma message(__FILE__"("STRING_QUOTE(__LINE__)"): no velocity correction method defined")
#endif

/// \brief
typedef struct
{
  float32        CorrFact; ///<
  fVariance_t    CorrDev; ///<
  fVelocity_t    CorrVel; ///<
  VDYCorrState_t State; ///<
  fTime_t        LastNvmWrt; ///<
} VDYVelCorrNode_t;

/// \brief
typedef struct
{
  uint32      Timer;           ///< Timer for non-observable ego velocity   
  fVelocity_t minVelMeas;      ///< Minimum reference velocity for measured distributions  
  fVelocity_t maxVelMeas;      ///< Maximum reference velocity for measured distributions  
  fVelocity_t lastEgoVel;      ///< Ego velocity from previous cycle  
  fTime_t     EcuTime;         ///< Runtime since ignition start  
  uint32      cntMeasAmb;      ///< Counter for measured ambigous velocity distributions   
  uint32      cntMeasRng;      ///< Counter for measured velocity outside permitted range  
} VDYVelCorrAux_t;

/// \brief
typedef struct
{
  fVariance_t P[4];   ///< Error covariance matrix  
  fVariance_t H[2];   ///< Observation matrix       
  float32     X[2];   ///< State matrix             
} VDYVelCorrEst_t;

/// \brief VDY Velocity Correction Input data 
typedef struct
{
  VDYModIf_t           *mif;       ///< Component internal intra module interface
  VDYErrState_t        *errFactRg; ///< Velocity correction factor range error
  VDYErrState_t        *errWin;    ///< Velocity correction factor window error
} VDYVelCorrIo_t;

/// \brief Velocity Correction Data
typedef struct
{
  VDYRefSpeed_t     Hist[VDY_CORR_VEL_RANGES]; 	///< long-term histograms
  VDYVelCorrNode_t  Node[VDY_CORR_VEL_RANGES]; 	///< velocity correction data
  VDYVelCorrEst_t   Est; 						///< velocity correction Offset estimation section
  VDYVelCorrAux_t   Aux; 						///< velocity correction Auxiliary node
  VDYVelCorrIo_t    Io; 						///< VDY Velocity Correction Input data 
} VDYVelCorr_t;

#if (VEL_CORR_HIST_STATIONARY_TARGETS)
/// \brief FS monitoring of velocity based on histogram of stationary objects  
typedef struct
{
  float32 sum;      ///< sum of correction factors  
  float32 mean;     ///< mean of sum  
  float32 sqsum;    ///< sum of squares  
  float32 sqmean;   ///< mean of the sum of squares  
  float32 sa;       ///< standard deviation  
  float32 number;   ///< amount of added correction factors  
  uint8   counter;  ///< number of added histograms  
  VDYErrState_t fault;  ///< fault state  
} VDYFSVelCorrMon_t;
#elif (VEL_CORR_ALN)

/// \brief	FS monitoring of velocity based on ALN calculated velocity of stationary targets  
typedef struct
{
  float32 f_velDiff;		///< difference of input velocities  
  float32 f_varRange;       ///< max. tolerance based on variances  
  float32 f_threshold;      ///< threshold for accepting external velocity  
  float32 f_curVelCorr;     ///< velocity correction factor of current sample  
  float32 f_VelConfDiff;    ///< velocity confirmation check difference of current sample  
  uint16 u_UpConfCounter;	///< number of failed checks of confirmed check
  uint16 u_DownConfCounter;	///< number of passed checks of confirmed check
  uint16   u_counter;		///< number of failed checks  
  uint16   u_ConfCounter;	///< number of failed checks of confirmation check 
  VDYErrState_t fault;      ///< fault state  
  VDYErrState_t confFault;  ///< fault state of confirmation check  
} VDYFSVelCorrMon_t;
#endif
#endif

/// \brief Velocity Monitor Counter
typedef struct
{
  uint32 cntOutSide;		///<  error count 
} VDYVelMon_t;


/*<---------------------------------------------------------------------------
  Yaw rate offset output 
----------------------------------------------------------------------------->*/

/// \brief Yaw rate offset types 
typedef enum
{                           
   OUT_YWR_OFFS_NON            = 0               ///< No offset type present                   
  ,OUT_YWR_OFFS_STANDST_SHORT  = 1               ///< Offset short acquired from standstill    
  ,OUT_YWR_OFFS_STANDST_FULL   = 2               ///< Offset full acquired from standstill     
  ,OUT_YWR_OFFS_STANDST_EEPROM = 3               ///< Offset acquired from non-volailte memory 
  ,OUT_YWR_OFFS_DYN            = 4               ///< Dynamic estimated yaw rate offset        
} eVDYOutYwrOffsType_t;

#if (CFG_USE_COMPACT_ENUMS)
	
/// using 8bit type for the real enum (32bit type) eVDYCorrState_t to save memory
typedef uint8 VDYOutYwrOffsType_t;      
#else
	
/// using 8bit type for the real enum (32bit type) eVDYCorrState_t to save memory
typedef eVDYOutYwrOffsType_t VDYOutYwrOffsType_t;
#endif

/// Kalman gain data from YE Kalman filter 
typedef struct
{
  float32 K_yaw[VDY_EIGHT];     ///< Kalman gain of yaw rate
  float32 K_curve[VDY_FOUR];    ///< Kalman gain of curvature
  uint8  K_yaw_fault;           ///< Yaw rate Kalman Gain Fault (0 - ok 1 - Not Ok) 
  uint8  K_curve_fault;         ///< Curvature Kalman Gain Fault (0 - ok 1 - Not Ok) 
  uint8 u_CurveFaultCounter;    ///< Fault counter to set the Curve fault
  uint8 u_YawFaultCounter;      ///< Fault counter to set the Yaw fault
  uint8 u_DICurveFaultCounter;  ///< Fault counter to set the Driver intended curve fault
} VDYYe_K_t;

/// Timestamp differences 
typedef struct
{
  uint32 ui_DeltaTimeBetweenCalls;      ///< Time difference between the last 2 VDY calls
  uint32 ui_DeltaTimeDataAndExecution;  ///< Time difference between VehSig input data and system time at processing
} VDYDeltaTimeStamp_t;

/*<---------------------------------------------------------------------------
  Final curvature
----------------------------------------------------------------------------->*/
/*---- Output Data ----------------------------------------------------------*/
/// \brief Estimated curvature of vehicle trajectory 
typedef struct
{
  fCurve_t     Curve;     ///< Course curvature in 1/Radius, 1/R greater than 0 - left turn 
  fVariance_t  Variance;  ///< Variance of estimation 
  fGradient_t  Gradient;  ///< Course curvature gradient d/dt (1/R) 
} VDYOutCurve_t;


/*<---------------------------------------------------------------------------
  Signal headers of input ports
----------------------------------------------------------------------------->*/
#ifdef AS_SERVICEFUNC_VERSION
/// Input sync structure providing info about received inputs on measfreeze channel
typedef struct
{
#if (CFG_VDY_MFC)
 Vdy_SyncRef_t  vdy_SyncRef;
#else
  SignalHeader_t sSigHeader;
  SignalHeader_t BSW_s_VDYCtrlData;
  SignalHeader_t VehPar;
  SignalHeader_t VehSig;
  SignalHeader_t VDYNVMRead;
#endif
  

#if ( (defined(CFG_VDY_DO_VELOCITY_CORR)) && (CFG_VDY_DO_VELOCITY_CORR) )
#if ( (defined(VEL_CORR_HIST_STATIONARY_TARGETS)) && (VEL_CORR_HIST_STATIONARY_TARGETS) )
  /// Reference speed histogram
  SignalHeader_t VelStatObj;
#endif
#if ( (defined(VEL_CORR_ALN)) && (VEL_CORR_ALN) )
  /// Velocity information from ALN 
  SignalHeader_t ALN_Monitoring; 
#endif
#endif
#if ( (defined(CFG_VDY_ROLLBENCH_DETECTION)) && (CFG_VDY_ROLLBENCH_DETECTION) )
  /// Roll bench detection information from EM
  SignalHeader_t EM_RTBRecognition; 	
#endif
#if ( (defined(CFG_VDY_64BIT_TIMESTAMP_INTERV)) && (CFG_VDY_64BIT_TIMESTAMP_INTERV) )
  /// VDY Time stamp
  SignalHeader_t VDYLongLongTimeStamp;
#endif
} VDY_SM_t_SyncRef;
#endif


/*<---------------------------------------------------------------------------
  Service functions (defined locally if not available in RTE)
  type is defined to keep parameters in function calls the same for both options
----------------------------------------------------------------------------->*/
#ifndef AS_SERVICEFUNC_VERSION
/// \brief Service Function (Not Used)
typedef struct
{
	uint32 u_Version; ///< Version Number
} AS_t_ServiceFuncts;
#endif

/*<---------------------------------------------------------------------------
  VDY all Internal structures
----------------------------------------------------------------------------->*/
typedef struct
{
  VDYSwaData_t            VDYSwa;            ///< Steering wheel angle processing data
  VDYAyData_t             VDYAy;             ///< Lateral Acceleration Data 
  VDYYwrData_t            VDYYwr;            ///< Yaw rate sensor data  
  VDYWhsData_t            VDYWhs;
#if ( (defined(CFG_VDY_DO_VELOCITY_CORR)) && (CFG_VDY_DO_VELOCITY_CORR) )
  VDYVelCorr_t            VDYVelCorr;        ///< Velocity Correction Data
  VDYFSVelCorrMon_t       VDYFSVelCorrMon;   ///< FS monitoring of velocity based on histogram of stationary objects 
#endif
  VDYInternalData_t       VDYIntData;        ///< VDY Internal Data
  vdy_bayes_mot_states_t  VDYBayesOut;       ///< Motion State Estimation Structure after Bayes application
  VDYFSData_t             VDYFSMon;          ///< Functional safety internal data
  VDYYe_K_t               VDYYeK;            ///< Kalman gain data from YE Kalman filter 
  VDYDeltaTimeStamp_t     VDYDeltaTimeStamp; ///< Timestamp differences 
  VDY_SM_t_SyncRef        VDY_SyncRef;       ///< Input sync structure providing info about received inputs on measfreeze channel
  VDYConfig_t             VDYConfig;         ///< bit field Configuration of the VDY Component 
  VDYInputData_t          VDYIn;             ///< Input of the Vehicle Dynamics Module 
  #if (CFG_VDY_INT_GYRO)
  VDYYwrtData_t           VDYYwrt;           ///< Internal yaw rate temperature data structure
  #endif
  #if (CFG_VDY_YWR_OFFSET_MONITOR)
  VDYYwrMonData_t         VDYYwrMonData;     ///< Yaw rate offset monitoring database  
  #endif
} VDYInternal_t;  /*!< @VADDR: VDY_MEAS_ID_INTDATA @VNAME: VDYInternal @ALLOW: vdy_priv @cycleid: vdy_cycle_id*/


/*****************************************************************************
  GLOBAL VARIABLES (COMPONENT INTERNAL SCOPE)
*****************************************************************************/
extern VDYInternalData_t vdy_internal_data;         
extern vdy_bayes_mot_states_t vdy_bayes_mot_states; 


/*****************************************************************************
  FUNCTION PROTOTYPES (COMPONENT INTERNAL SCOPE)
*****************************************************************************/

/*<--- Model entry function prototypes -----------------------------------> */

/* **********************************************************************
  @fn               vdyYwrExec */ /*!
  @brief           Main function to execute yaw rate offset calculation

  @description     Initializes yaw rate module \n 
                   Takes yaw rate offset from NVM \n
                   Filters input yaw rate and calculates gradient \n
                   Calculates standstill offset \n
                   Calculates another dynamic offset for plausibilisation with dynamic offset from wheel module \n
                   Prepares data for autocode module 

  @return          void

  @param[in]       *reqPorts : Request Ports
  @param[in]       *input : Current Input Signal
  @param[in,out]   *mif : Module Interface Data
  @param[in]       *proPorts : Provide Ports
  @param[in]       RawVelo : Raw Velocity

  @glob_in         
				   - YWR_GET_DATA : Yaw rate sensor data
				   - YWR_GET_OFFS : offset data
  @glob_out        - YWR_GET_ME : Yaw rate sensor data processing

  @c_switch_part   
				   - CFG_VDY_EX_YWR_NVM : Enable offset storage  in nonvolatile memory  
				   - CFG_VDY_YW_DYN_AVG : Enable dynamic gyro offst compensation
  @c_switch_full   None 

  @pre             None
  @post            No changes
  @InOutCorrelation
					- When operating state is Run (BASE_OM_RUN)
						- Get yaw rate data and compute yaw rate offset data
						- Calculate time variables which have to be calculated even if offset calculation is not done because input yaw rate is invalid
						- When offset storage in nonvolatile memory enabled and NVM data is valid
							- read NVM data and store it in StandStillEepromOffset.YawRateOffset
						- When input yaw rate signal data is valid 
							- Store it in yaw rate data and set yaw rate data state to valid
						- otherwise set yaw rate data state it to invalid
						- When Valid Or Invalid check before reading NVM and writes NVM data disabled in every vdy cycle Set VDY_NVM_POS_YWR invalid
						- When yaw rate data is valid
							- in case of first cycle, init old filtered yaw rate with actual yaw rate
							- Calculate filtered yaw rate and yaw rate gradient
							- Check filtered yaw rate for high gradients over distance (only for dynamic offset calculation)
							- Calculate Offset
							- When dynamic gyro offst compensation enabled calculate mean value between effective and interims offset in case of drift
							- Write Yaw offset into NVM in every excution cycle
							- First cycle done with valid yaw rate, filter are initialised now so set YwFirstCycleDone = TRUE;
						- When yaw rate data is invalid Initialise general yaw rate and standstill offset data to reset filter values and distance
					- For other operating states initialize yaw rate data
					- Fill the autocode interface
  
					@startuml
						start
							if (check CtrlMode ==VDY_CTRL_STATE_RUNNING or BASE_OM_RUN) then (YES)
								:Calculation of time variables which have to be calculated even if offset calculation is not done because input yaw rate is invalid;
								if (NVM_READ->State of VDY_NVM_POS_YWR  is VDY_IO_STATE_VALID) then (YES)
									:read yaw rate offset from Eeprom VDYYwrEepromReadYwOffset();
									:calculate EepromOffsetQuality VDYYwrCalcEepromOffsetQuality();
								endif
								if (input yaw rate state is valid) then (YES)
								  :set YawRateData->YawRate = input->Signals.YawRate;
								  :set YawRateData->Valid = TRUE;
								else (No)
								  :set YawRateData->Valid = FALSE;
								endif
								if (YawRateData->Valid == (boolean)TRUE) then (YES)
									if (YawRateData->YwFirstCycleDone == (boolean)FALSE) then (YES)
										:in case of first cycle, init old filt yaw rate with actual yaw rate, YawRateData->YawRateOld = YawRateData->YawRate;
									endif
									:YawRateFilt = vdyFilterCycleTime(YawRateData->YawRate, YawRateData->YawRateOld, VDY_PAR_YWR_YAWRATE_FT);
									:YawRateData->Gradient = vdyCalcGradient(YawRateFilt, YawRateData->YawRateOld);
									:YawRateData->YawRateOld = YawRateFilt;
									:Check filtered yaw rate for high gradients over distance (only for dynamic offset calculation);
									:start Offset calculation VDYYwrCalcOffset(YawRateData,OffsData,input,proPorts,RawVelo);
									:Calculate mean value between effective and interims offset in case of drift
									:VDYNvIoData_t *nvout = YWR_GET_NVM_WRITE;
									:nvout->YwRate.ZeroRate = LastYawNvmData.ZeroRate;
									:nvout->YwRate.CalStatus = LastYawNvmData.CalStatus;
									:nvout->YwRate.ZeroRateMin = LastYawNvmData.ZeroRateMin;
									:nvout->YwRate.ZeroRateMax = LastYawNvmData.ZeroRateMax;
									:First cycle done with valid yaw rate, filter are initialised now;
								else(No)
									:VDYNvIoData_t *nvout = YWR_GET_NVM_WRITE;
									:nvout->YwRate.ZeroRate = LastYawNvmData.ZeroRate;
									:nvout->YwRate.CalStatus = LastYawNvmData.CalStatus;
									:nvout->YwRate.ZeroRateMin = LastYawNvmData.ZeroRateMin;
									:nvout->YwRate.ZeroRateMax = LastYawNvmData.ZeroRateMax;
									:yaw rate invalid, Initialise general yaw rate and standstill offset data to reset filter values and distance VDYYwrInitYawRateData(YawRateData);;
								endif
							else (No)
								:Calculation of time variables VDYYwrCalcRunnigTime();
								:initialize VDYYwrCommonInit();
								:check for valid values written into NVM  YWR_GET_ME->Io.YwrNVMerrOffsRg = NULL;
							endif
						stop
					@enduml
  @testmethod		- Module Testing \n
                            This function has to be tested for statement and branch coverage. \n
                            For detailed unit test description follow the caller graph to the test function \n
                            test_vdy_ywr.c -> TEST_vdyYwrExec_001(), TEST_vdyYwrExec_002(), TEST_vdyYwrExec_003(), TEST_vdyYwrExec_004()
  @traceability		
  - L3
    - doors://RBGS854A:40000/?version=2&prodID=0&view=000000b9&urn=urn:telelogic::1-503e822e5ec3651e-O-1164-000221c8
    - doors://rbgs854a:40000/?version=2&prodID=0&view=0000012f&urn=urn:telelogic::1-503e822e5ec3651e-O-285-000221c8
  - L4
    - doors://rbgs854a:40000/?version=2&prodID=0&urn=urn:telelogic::1-503e822e5ec3651e-O-657-00026448
    - doors://rbgs854a:40000/?version=2&prodID=0&urn=urn:telelogic::1-503e822e5ec3651e-O-568-00026448
    - doors://rbgs854a:40000/?version=2&prodID=0&urn=urn:telelogic::1-503e822e5ec3651e-O-879-00026448
**************************************************************************** */
#if (CFG_VDY_MFC)
extern void vdyYwrExec(const reqVdyPrtList_t *reqPorts,const VDYInputData_t *input, VDYModIf_t *mif, const proVdyPrtList_t *proPorts, const float32 RawVelo);
#else
extern void vdyYwrExec(const reqVdyPrtList_t *reqPorts,const VDYInputData_t *input, VDYModIf_t *mif, const proVdyPrtList_t *proPorts);
#endif


/* **********************************************************************
  @fn               vdyAySwaExec */ /*!

  @brief            Determine operating sequence for vehicle dynamics observer
  @description      Execution of steering wheel angle and lateral acceleration sensor signal processing. Detect out of range error for Steering wheel angle and lateral acceleration. Check distinction between different operating states.

	@return          void

  @param[in]       *reqPorts : Request Ports
  @param[in]       *input : Current Input Data
  @param[in,out]   *mif : Module Interface Data
  @param[in]       *proPorts : Provide Ports

  @glob_in         
			  - SWA_GET_SEN_DATA : Sensor signal processing of Steering wheel angle
			  - SWA_GET_OFF_DATA : Offset estimation of Steering wheel angle
			  - SWA_GET_ME : Steering wheel angle processing database       
			  - AY_GET_SEN_DATA : Sensor signal processing of Lateral acceleration        
			  - AY_GET_OFF_DATA : Offset estimation of Lateral acceleration       
			  - AY_GET_ME : Lateral acceleration processing database       
			  - VDY_ERR_STATE_UNKNOWN : unknown vdy error state type
  @glob_out        None

  @c_switch_part   None
  @c_switch_full   None

  @pre             None
  @post            No changes
  @InOutCorrelation	
					  Execution of Lateral Acceleration and Steering Wheel Angle Offset Calculation in Run and Init Mode
							- Init Mode
									- Initialization of lateral acceleration & steering wheel angle data Set lateral acceleration & steering wheel angle Input/Output interface error states
							- Run Mode
									- Reads Steering Wheel Angle and Lateral Acceleration Sensor Signals
									- Checks for validity of the Lateral Acceleration & Steering Wheel Angle and calculates gradients if signals are valid
									- Calculates steering wheel angle and lateral acceleration sensor offset
									- Export Ay and Swa ofsets to module interface, mif->AyOffset & mif->SwaOffset
									- Fetches Non Volatile Start values for writing Ay & Swa Offsets into NVM in every execution cycle 
  
							@startuml
								start
									if(Operating modes == BASE_OM_RUN) then (YES)
										:Upload offset form nv memory to internal nvm offset buffer;
										:Read steering wheel angle signal;
										:Read lateral acceleration sensor signal;
										if (pAySen->Valid != (boolean)FALSE) then (YES)
											:Calculate Ay gradient;
										endif
										if (pSwaSen->Valid != (boolean)FALSE ) then (YES)
											:Calculate SWA gradient;
											:calculate steering wheel angle and lateral acceleration sensor offset;
											:Export Ay and Swa offsets , states and variance to module interface
												mif->SwaOffset.offset,mif->SwaOffset.state and mif->SwaOffset.var
												mif->AyOffset.offset,mif->AyOffset.state and mif->AyOffset.var;
										endif
										:write new offset to non volatile memory;				
									else (NO)
										:Initialize steering wheel angle (SWA) data;
										:Init SWA error states
											pSwaData->Io.errOffsRg  = NULL
											pSwaData->Io.NVMerrOffsRg  = NULL
											pSwaData->Io.SwaNVMErrOffsRg  = NULL;
										:Initialize Lateral acceleration (Ay)data;
										:Init Ay error states
											pAyData->Io.errOffsRg = NULL
											pAyData->Io.NVMerrOffsRg = NULL
											pAyData->Io.AyNVMerrOffsRg = NULL;
				
									endif
								stop
						@enduml

  @testmethod			- Module Testing \n
                            This function has to be tested for statement and branch coverage. \n
                            For detailed unit test description follow the caller graph to the test function \n
                            test_vdy_ay_swa.c ->   
                            TEST_vdyAySwaExec_001(),
                            TEST_vdyAySwaExec_002(),
                            TEST_vdyAySwaExec_003(),
                            TEST_vdyAySwaExec_004(),
                            TEST_vdyAySwaExec_005()

  @traceability			  
  - L3
    - doors://RBGS854A:40000/?version=2&prodID=0&view=000000b9&urn=urn:telelogic::1-503e822e5ec3651e-O-1166-000221c8
    - doors://rbgs854a:40000/?version=2&prodID=0&view=000000b9&urn=urn:telelogic::1-503e822e5ec3651e-O-1167-000221c8
  - L4
    - doors://rbgs854a:40000/?version=2&prodID=0&urn=urn:telelogic::1-503e822e5ec3651e-O-49-00026448
    - doors://rbgs854a:40000/?version=2&prodID=0&urn=urn:telelogic::1-503e822e5ec3651e-O-615-00026448
    - doors://rbgs854a:40000/?version=2&prodID=0&urn=urn:telelogic::1-503e822e5ec3651e-O-1107-00026448
    - doors://rbgs854a:40000/?version=2&prodID=0&urn=urn:telelogic::1-503e822e5ec3651e-O-682-00026448
    - doors://rbgs854a:40000/?version=2&prodID=0&urn=urn:telelogic::1-503e822e5ec3651e-O-683-00026448
**************************************************************************** */
extern void vdyAySwaExec(const reqVdyPrtList_t *reqPorts, const VDYInputData_t *input, VDYModIf_t *mif, const proVdyPrtList_t *proPorts);


/* **********************************************************************
  @fn               vdyWhsExec */ /*!

  @brief           Determine operating sequence for vehicle dynamics observer

  @description     Inits WHS module during INIT

  @return          void

  @param[in]       input : Current Input Data
  @param[in,out]   *mif : Module Interface Data

  @glob_in         
					  - WHS_GET_DATA : Wheel speed sensor data     
					  - WHS_GET_MIF_DATA : Component internal intra module interface       
					  - VDY_TRACK_EX_WSP_VAR : defaults for externally provided whs curve
  @glob_out        None 

  @c_switch_part   None 
  @c_switch_full   None 

  @pre             None
  @post            No changes
  @InOutCorrelation
					- If it is in runningv operating mode
						- get pointer to general wheel speed data and offset data
						- get curve calculated without wheel speeds
						- get ego velocity
						- get wheel speeds from module interface
						- Check for front (left & right) and rear (left & right) wheel speeds validity and update WspData
						- detect driving straight ahead for offset calculation
						- if TrackExWsp variance is greater than delta then check gradient for offset calculation
						- else set delta distance to 0
						- save last Speed Range
						- determine speed range for offset calculation
						- check if next SpeedRange was reached
							- Set front offset to interval mean of last speed range
							- Set rear offset to interval mean of last speed range
						- If Minimum Vego to calculate the WSP curve is reached
							- check if wheel speeds front are valid
								- calculate ratio left/righ
								- calculate offset, curvature and quality of wheel speeds front
							- check if wheel speeds rear are valid 
								- calculate ratio left/right
								- calculate offset, curvature and quality of wheel speeds rear
					- else
						- Initialises the wheel speed data without the offset data
  
	@startuml
	start
		if ( Execution path for normal operating mode \n VDY_CTRL_GET_STATE((VDYCtrlState_t)VDY_CTRL_STATE_RUNNING, input->Frame.CtrlMode)) then (YES)
			:Wheel speeds sensor data \n VDYWhsSenData_t     *WspData;
			:offset data  \n VDYWhsOffsData_t    *WspOffsData;
			:corrected vehicle velocity \n fVelocity_t         VehicleSpeed;
			:overall curve of vehicle \n  VDYOutCurve_t       TrackExWsp;
			:get pointer to general wheel speed data \n WspData = WHS_GET_DATA;
			:get pointer to offset data \n WspOffsData = WHS_GET_OFFS;
			:get curve calculated without wheel speeds \n TrackExWsp.Gradient = WHS_GET_MIF_DATA->CurveInt.Gradient \n TrackExWsp.Variance = VDY_TRACK_EX_WSP_VAR \n TrackExWsp.Curve    = WHS_GET_MIF_DATA->Curve.Curve;
			:get ego velocity \n VehicleSpeed = WHS_GET_MIF_DATA->LongMot.VehVelocityCorr;
			:get wheel speeds from module interface \n WspData->WspFornt.WspLeft  = WHS_GET_MIF_DATA->LongMot.FLWhlVelo \n WspData->WspFornt.WspRight = WHS_GET_MIF_DATA->LongMot.FRWhlVelo;
			if (   ((sint32)VDY_GET_IO_STATE(VDY_SIN_POS_WVEL_FL, input->Signals.State) == VDY_IO_STATE_VALID) && ((sint32)VDY_GET_IO_STATE(VDY_SIN_POS_WVEL_FR, input->Signals.State) == VDY_IO_STATE_VALID)) then (YES)
				:WspData->WspFornt.WspValid = TRUE;
			else (NO)
				:WspData->WspFornt.WspValid = FALSE;
			endif
			:WspData->WspRear.WspLeft  = WHS_GET_MIF_DATA->LongMot.RLWhlVelo;
			:WspData->WspRear.WspRight = WHS_GET_MIF_DATA->LongMot.RRWhlVelo;
			if (   ((sint32)VDY_GET_IO_STATE(VDY_SIN_POS_WVEL_RL, input->Signals.State) == VDY_IO_STATE_VALID) && ((sint32)VDY_GET_IO_STATE(VDY_SIN_POS_WVEL_RR, input->Signals.State) == VDY_IO_STATE_VALID)) then (YES)
				:WspData->WspRear.WspValid = TRUE;
			else (NO)
				:WspData->WspRear.WspValid = FALSE;
			endif
			:detect driving straight ahead for offset calculation \n VDYWhsTrackStraight(&WspOffsData->ExWspStatus, &TrackExWsp);
			if (TrackExWsp.Variance >= C_F32_DELTA) then (YES)
				:check gradient for offset calculation \n vdyCalcDistStblGrad(WHS_DELTA_DIST_GRAD_MAX , TrackExWsp.Gradient, &WspOffsData->GradAbsOld, &WspOffsData->WspDeltaDist, VehicleSpeed);
			else (NO)
				:WspOffsData->WspDeltaDist = VDY_ZERO_F;
			endif
			:save last Speed Range \n WspOffsData->LastSpeedRange = WspOffsData->SpeedRange;
			:determine speed range for offset calculation \n WspOffsData->SpeedRange = VDYWhsVehSpeedRange(VehicleSpeed);
			if ( check if next SpeedRange was reached \n WspOffsData->SpeedRange != WspOffsData->LastSpeedRange) then (YES)
				:Set front offset to interval mean of last speed range \n VDYWhsSetOffIntLastRange(&WspOffsData->OffsFront,WspOffsData->SpeedRange,WspOffsData->LastSpeedRange);
				:Set rear offset to interval mean of last speed range \n VDYWhsSetOffIntLastRange(&WspOffsData->OffsRear,WspOffsData->SpeedRange,WspOffsData->LastSpeedRange);
			endif
			if(VehicleSpeed >= WHS_VEH_SPEED_MIN ) then (YES)
				if (check if wheel speeds front are valid \n WspData->WspFornt.WspValid == (boolean)TRUE) then (YES)
					:calculate ratio left/right \n VDYWhsAxleCalcRatioLeftRight(&WspData->WspFornt);
					:calculate offset, curvature and quality of wheel speeds front \n VDYWhsCalcOffsetAxle(&WspOffsData->OffsFront , WspData->WspFornt.Ratio, WspOffsData->SpeedRange, WspOffsData->ExWspStatus, WspOffsData->WspDeltaDist);
				endif
				if ( check if wheel speeds rear are valid \n WspData->WspRear.WspValid == (boolean)TRUE) then (YES)
					:calculate ratio left/right \n VDYWhsAxleCalcRatioLeftRight(&WspData->WspRear);
					:alculate offset, curvature and quality of wheel speeds rear \n VDYWhsCalcOffsetAxle(&WspOffsData->OffsRear , WspData->WspRear.Ratio, WspOffsData->SpeedRange, WspOffsData->ExWspStatus, WspOffsData->WspDeltaDist);
				endif
			endif
		else (NO)
			:Execution path for initialization mode \n VDYWhsCommonInit(pWhsdata);
		endif
		:return;
	stop
	@enduml
  @testmethod		- Module Testing \n
                            This function has to be tested for statement and branch coverage. \n
                            For detailed unit test description follow the caller graph to the test function \n
                            test_vdy_whs.c -> \n
                            TEST_vdyWhsExec_001(),
                            TEST_vdyWhsExec_002(),
                            TEST_vdyWhsExec_003(),
                            TEST_vdyWhsExec_004(),
                            TEST_vdyWhsExec_005(),
                            TEST_vdyWhsExec_006()
  @traceability			  
  - L3
    - doors://RBGS854A:40000/?version=2&prodID=0&view=000000b9&urn=urn:telelogic::1-503e822e5ec3651e-O-1168-000221c8
    - doors://rbgs854a:40000/?version=2&prodID=0&view=0000012f&urn=urn:telelogic::1-503e822e5ec3651e-O-289-000221c8
    - doors://rbgs854a:40000/?version=2&prodID=0&view=0000012f&urn=urn:telelogic::1-503e822e5ec3651e-O-1520-000221c8
  - L4
    - doors://rbgs854a:40000/?version=2&prodID=0&urn=urn:telelogic::1-503e822e5ec3651e-O-481-00026448
**************************************************************************** */
extern void vdyWhsExec(const VDYInputData_t* input, VDYModIf_t *mif);



extern void VDYVelCorrExec(const reqVdyPrtList_t *reqPorts, const VDYInputData_t *input, VDYModIf_t *mif, const proVdyPrtList_t *proPorts, boolean b_RTBDetection);


#if(CFG_VDY_INT_GYRO)
extern void VDYYwrtExec(const reqVdyPrtList_t *reqPorts, VDYModIf_t *mif, const proVdyPrtList_t *proPorts);
#endif
#if (CFG_VDY_YWR_OFFSET_MONITOR)
/* **********************************************************************
  @fn                 vdyYwrMonExec */ /*!
  @brief           Yaw rate zero point monitoring

  @description     A yaw rate sensor offset failure is detected, if the
                   zero point offset of the yaw rate exceeds during 
                   standstill

  @return          void

  @param[in]       *input : Current Input Data
  @param[in]       *mif : Module Interface Data
  @param[in]       *proPorts : Provide Ports

  @c_switch_part   CFG_VDY_INT_GYRO : Enable internal yaw rate sensor processing
  @c_switch_full   CFG_VDY_YWR_OFFSET_MONITOR : Enables monitoring of yaw rate at vehicle-stop, during vehicle-stop and vehicle drive-off. During this driving
                                                conditions zero point offset is roughly observeable. Exceedance of limits are indicated by error events

  @pre             None
  @post            No changes
  @InOutCorrelation		  - 
  
  @testmethod			  -	NA
  @traceability			  -	NA
**************************************************************************** */
extern void vdyYwrMonExec(const VDYInputData_t *input, const VDYModIf_t *mif, const proVdyPrtList_t *proPorts);
#endif

/* **********************************************************************
  @fn               vdyYwrInit */ /*!
  @brief           Initialize yaw rate offset estimation module data

  @description     Initialize yaw rate offset estimation module data

  @return          void

  @param[in]       *reqPorts : Request Ports
  @param[in]	   *proPorts : Provide Ports

  @glob_in         None 
  @glob_out        PrevYawRateOffset : Yaw Rate Offset Cycle of previous cycle

  @c_switch_part   CFG_VDY_TURNTABLE_DETECTION : Enables the Turn Table detection and limit max. delta 4deg/sec yaw rate offset compensation at one learning cycle
  @c_switch_full   None 

  @pre             None
  @post            No changes
  @InOutCorrelation 
					- Initialize Yaw Rate Sensor Data
                    - Initialize Yaw Rate offset Data
                    - When the Turn Table detection is enabled initialize PrevYawRateOffset to 0
                    - Check for Nan errors of NVM data
					- When Valid Or Invalid check before reading NVM and writes NVM data disabled in every vdy cycle to the provide port is disabled
						- When NVM is cleared (init mode) or YwRate.CalStatus is greater than YWR_NVM_OFFSET_STATUS_MAX(100) or if there in NaN error in NVM data initialize yaw rate nvm data an provide port NVM data to 0
						- Otherwise store request port NVM data into yaw rate nvm data an provide port NVM data
  
					@startuml
						start
							:Initialize Yaw Rate Sensor Data;
                            :Initialize Yaw Rate offset Data;
                            :Reinitialize Previous Estimated Yaw Rate Offset Value when CFG_VDY_TURNTABLE_DETECTION is on;
                            :YAW offset writing in init mode;
                            :Check for Nan errors \n NAN_Err |= ((CML_f_Abs(reqPorts->pNVMRead->YwRate.ZeroRate) < VDY_PAR_YWR_OFFSET_LIMIT_MAX) ? 0U : 1U) \n 
                                NAN_Err |= ((CML_f_Abs(reqPorts->pNVMRead->YwRate.ZeroRateMax) < VDY_PAR_YWR_OFFSET_LIMIT_MAX) ? 0U : 1U) \n 
                                NAN_Err |= ((CML_f_Abs(reqPorts->pNVMRead->YwRate.ZeroRateMin) < VDY_PAR_YWR_OFFSET_LIMIT_MAX) ? 0U : 1U);
							if((reqPorts->pNVMRead->State == NVM_CLEARED)|| (reqPorts->pNVMRead->YwRate.CalStatus >= YWR_NVM_OFFSET_STATUS_MAX)	|| (NAN_Err == 1U)) then (YES)
								:LastYawNvmData.ZeroRate       = 0.0f;
								:LastYawNvmData.CalStatus       = 0;
								:LastYawNvmData.ZeroRateMax       = 0.0f;
								:LastYawNvmData.ZeroRateMin       = 0.0f;
								:proPorts->pNVMWrite->YwRate.ZeroRate = 0.0f;
								:proPorts->pNVMWrite->YwRate.CalStatus = 0;
								:proPorts->pNVMWrite->YwRate.ZeroRateMax = 0.0f;
								:proPorts->pNVMWrite->YwRate.ZeroRateMin = 0.0f;
							else (No)
								:LastYawNvmData.ZeroRate       = reqPorts->pNVMRead->YwRate.ZeroRate;
								:LastYawNvmData.CalStatus       = reqPorts->pNVMRead->YwRate.CalStatus;
								:LastYawNvmData.ZeroRateMax       = reqPorts->pNVMRead->YwRate.ZeroRateMax;
								:LastYawNvmData.ZeroRateMin       = reqPorts->pNVMRead->YwRate.ZeroRateMin;
								:proPorts->pNVMWrite->YwRate.ZeroRate = reqPorts->pNVMRead->YwRate.ZeroRate;
								:proPorts->pNVMWrite->YwRate.CalStatus = reqPorts->pNVMRead->YwRate.CalStatus;
								:proPorts->pNVMWrite->YwRate.ZeroRateMax = reqPorts->pNVMRead->YwRate.ZeroRateMax;
								:proPorts->pNVMWrite->YwRate.ZeroRateMin = reqPorts->pNVMRead->YwRate.ZeroRateMin;
								:ioStateYaw = VDY_GET_NVM_IO_STATE(VDY_NVM_POS_YWR, &reqPorts->pNVMRead->State);
								:VDY_SET_NVM_IO_STATE(VDY_NVM_POS_YWR, ioStateYaw, &proPorts->pNVMWrite->State);
							endif
						stop
					@enduml
  @testmethod		- Module Testing \n
                            This function has to be tested for statement and branch coverage. \n
                            For detailed unit test description follow the caller graph to the test function \n
                            test_vdy_ywr.c -> TEST_vdyYwrInit_001(), TEST_vdyYwrInit_002(), TEST_vdyYwrInit_003(), TEST_vdyYwrInit_004()
  @traceability		- NA
**************************************************************************** */
extern void vdyYwrInit(const reqVdyPrtList_t *reqPorts, const proVdyPrtList_t *proPorts);


/* **********************************************************************
  @fn               vdyAySwaInit */ /*!

  @brief           Initialize module data

  @description     Initialzation of steering wheel angle data
                   Initialzation of lateral acceleration data

  @return          void

  @glob_in         
				  - SWA_GET_ME : Steering wheel angle processing database 
				  - AY_GET_ME : Lateral acceleration processing database
  @glob_out        None

  @pre             None
  @post            No changes
  @InOutCorrelation
					  -Initialzation of steering wheel angle data
						-Initialzation of lateral acceleration data
						-if NVM read state is CLEARED
								Update previous cycle offset of NVM and proport data with default
						else
								Update previous cycle offset of NVM and proport data with request port data

  
						@startuml
								start
									:Initialzation of steering wheel angle data;
									:Initialzation of lateral acceleration data;
									if(reqPorts->pNVMRead->State == SWA_NVM_CLEARED) then (YES)
										:LastSwaNvmData.ZeroAngle       = 0.0f
										LastSwaNvmData.CalStatus       = (uint32)0
										proPorts->pNVMWrite->StWhlAng.ZeroAngle = 0.0f
										proPorts->pNVMWrite->StWhlAng.CalStatus = (uint32)0
										\n
										LastAyNvmData.ZeroAngle        = 0.0f
										LastAyNvmData.CalStatus       = (uint32)0
										proPorts->pNVMWrite->LatAcc.ZeroAccel = 0.0f
										proPorts->pNVMWrite->LatAcc.CalStatus = (uint32)0;
									else (NO)
										:SWA offset writing in init mode
											LastSwaNvmData.ZeroAngle       = reqPorts->pNVMRead->StWhlAng.ZeroAngle
											LastSwaNvmData.CalStatus       = reqPorts->pNVMRead->StWhlAng.CalStatus
											proPorts->pNVMWrite->StWhlAng.ZeroAngle = reqPorts->pNVMRead->StWhlAng.ZeroAngle
											proPorts->pNVMWrite->StWhlAng.CalStatus = reqPorts->pNVMRead->StWhlAng.CalStatus
											ioStateSwa = VDY_GET_NVM_IO_STATE(VDY_NVM_POS_SWA, &reqPorts->pNVMRead->State)
											VDY_SET_NVM_IO_STATE(VDY_NVM_POS_SWA, ioStateSwa, &proPorts->pNVMWrite->State);
										:Ay offset writing in init mode
											LastAyNvmData.ZeroAngle        = reqPorts->pNVMRead->LatAcc.ZeroAccel
											LastAyNvmData.CalStatus       = reqPorts->pNVMRead->LatAcc.CalStatus
											proPorts->pNVMWrite->LatAcc.ZeroAccel = reqPorts->pNVMRead->LatAcc.ZeroAccel
											proPorts->pNVMWrite->LatAcc.CalStatus = reqPorts->pNVMRead->LatAcc.CalStatus
											ioStateAy = VDY_GET_NVM_IO_STATE(VDY_NVM_POS_LATACC, &reqPorts->pNVMRead->State)
											VDY_SET_NVM_IO_STATE(VDY_NVM_POS_LATACC, ioStateAy, &proPorts->pNVMWrite->State);
									endif
								stop
						@enduml

  @testmethod			  - Module Testing \n
                            This function has to be tested for statement and branch coverage. \n
                            For detailed unit test description follow the caller graph to the test function \n
                            test_vdy_ay_swa.c -> TEST_vdyAySwaInit_001(), TEST_vdyAySwaInit_002()
  @traceability			  - 
  - L4
    - doors://rbgs854a:40000/?version=2&prodID=0&urn=urn:telelogic::1-503e822e5ec3651e-O-1029-00026448
**************************************************************************** */
extern void vdyAySwaInit(const reqVdyPrtList_t *reqPorts, const proVdyPrtList_t *proPorts);


/* **********************************************************************
  @fn               vdyWhsInit */ /*!

  @brief           Initialize module data

  @description     Initialize module data

  @return          void

  @glob_in         WHS_GET_ME : Wheel speed processing database
  @glob_out        None 

  @c_switch_part   None 
  @c_switch_full   None 

  @pre             None
  @post            No changes
  @InOutCorrelation
					- Initialize module data
  
	@startuml
	start
		:VDYWhsData_t *pWhsdata = WHS_GET_ME;
		:VDYWhsInitWspOffsData(&pWhsdata->Offset);
		:VDYWhsCommonInit(pWhsdata);
		:return;
	stop
	@enduml
  @testmethod			  - Module Testing \n
                            This function has to be tested for statement and branch coverage. \n
                            For detailed unit test description follow the caller graph to the test function \n
                            test_vdy_whs.c -> TEST_vdyWhsInit_001()
  @traceability			  - NA
**************************************************************************** */
extern void vdyWhsInit(void);
extern void VDYVelCorrInit(const proVdyPrtList_t *proPorts);
#if(CFG_VDY_INT_GYRO)
extern void VDYYwrtInit(const proVdyPrtList_t *proPorts );
#endif
#if (CFG_VDY_YWR_OFFSET_MONITOR)
/* **********************************************************************
  @fn                 vdyYwrMonInit */ /*!
  @brief           Yaw rate zero point monitoring initialization

  @description     A yaw rate sensor offset failure is detected, if the
                   zero point offset of the yaw rate exceeds during 
                   standstill

  @return          void

  @param[in]       *input : Current input signal
  @param[in]       *mif : module interface data
  @param[in,out]   *VDYErrors : VDY Error signals

  @c_switch_part   None 
  @c_switch_full   CFG_VDY_YWR_OFFSET_MONITOR : Enables monitoring of yaw rate at vehicle-stop, during vehicle-stop and vehicle drive-off. During this driving
                                                conditions zero point offset is roughly observeable. Exceedance of limits are indicated by error events

  @pre             None
  @post            No changes
  @InOutCorrelation		  - 
  
  @testmethod			  - NA
  @traceability			  - NA
**************************************************************************** */
void vdyYwrMonInit(const VDYInputData_t *input, const VDYModIf_t *mif, VDYErrors_t *VDYErrors);
#endif

/* Functional safety monitoring functions */
#if !(defined(CFG_VDY_DIS_FUNCTIONAL_SAFETY_MON) && (CFG_VDY_DIS_FUNCTIONAL_SAFETY_MON))
/* **********************************************************************
  @fn               vdyFSMonitor */ /*!
  @brief           Functional safety monitoring

  @description     Calls functional safety fault monitors (yaw rate, velocity and curve)

  @return          void

  @param[in]       *IntData : VDY Internal Data
  @param[in]       *VDYModIf : Module Interface Data
  @param[in]       *proPorts : Provide Ports

  @c_switch_part   None 
  @c_switch_full   None 

  @pre             None
  @post            No changes
  @InOutCorrelation - 
  
	@startuml
	start
		:Do the functional safety velocity monitoring \n VDYFSVelocityMonitoring(proPorts, &gVDYFSData);
		:Do the functional safety yawrate monitoring \n VDYFSYawRateMonitoring(IntData, proPorts, VDYModIf, &gVDYFSData);
		:Do the functional safety curve prediction monitoring \n VDYFSCurvePredictionMonitoring(IntData, &gVDYFSData);
	stop
	@enduml
  @testmethod			  - Module Testing \n
                            This function has to be tested for statement and branch coverage. \n
                            For detailed unit test description follow the caller graph to the test function \n
                            test_vdy_mon.c -> TEST_vdyFSMonitor_001()
  @traceability
  - Respective doors links are found in function descriptions 
    - VDYFSVelocityMonitoring(proPorts, &gVDYFSData);
    - VDYFSYawRateMonitoring(IntData, proPorts, VDYModIf, &gVDYFSData);
    - VDYFSCurvePredictionMonitoring(IntData, &gVDYFSData);

**************************************************************************** */
extern void vdyFSMonitor(const VDYInternalData_t *IntData, const VDYModIf_t *VDYModIf, const proVdyPrtList_t *proPorts);


/* **********************************************************************
  @fn               vdyFSInit */ /*!
  @brief           Initalize the functional safety monitoring

  @description     Initializes the FuSi related fault monitor data
                   (yaw rate, velocity and curve)

  @return          void

  @glob_in         None 
  @glob_out        gVDYFSData : Functional safety internal data

  @c_switch_part   None 
  @c_switch_full   None 

  @pre             None
  @post            No changes
  @InOutCorrelation
				  - Initializes the statistic data buffers
				  - Initializes yaw rate monitoring
				  - Initializes all error states to unknown
  
	@startuml
	start
		:vdyStatIntervalInit(&(gVDYFSData.VDYFSCurveCheck.VDYFSWyeGyeStat));
		:vdyStatIntervalInit(&(gVDYFSData.VDYFSCurveCheck.VDYFSAyeGyeStat));
		:vdyStatIntervalInit(&(gVDYFSData.VDYFSCurveCheck.VDYFSSyeGyeStat));
		:gVDYFSData.VDYFSCurveCheck.nCurveErrorCounter    = VDY_ZERO_U;
		:gVDYFSData.VDYFSYawRateCheck.fYawWheelDelta      = VDY_ZERO_F;
		:gVDYFSData.VDYFSYawRateCheck.fYawWheelOutDist    = VDY_ZERO_F;
		:gVDYFSData.VDYFSYawRateCheck.fYawLatAccelDelta   = VDY_ZERO_F;
		:gVDYFSData.VDYFSYawRateCheck.fYawLatAccelOutDist = VDY_ZERO_F;
		:gVDYFSData.VDYFSYawRateCheck.fYawSteerDelta      = VDY_ZERO_F;
		:gVDYFSData.VDYFSYawRateCheck.fYawSteerOutDist    = VDY_ZERO_F;
		:gVDYFSData.VDYFSYawRateCheck.nWheelErrorCounter    = VDY_ZERO_U;
		:gVDYFSData.VDYFSYawRateCheck.nLatAccelErrorCounter = VDY_ZERO_U;
		:gVDYFSData.VDYFSYawRateCheck.nSwaErrorCounter      = VDY_ZERO_U;
		:gVDYFSData.FSMonErrorStates.FSIntExtVeloCheck            = VDY_ERR_STATE_UNKNOWN;
		:gVDYFSData.FSMonErrorStates.FSCorrVeloCheck              = VDY_ERR_STATE_UNKNOWN;
		:gVDYFSData.FSMonErrorStates.FSMaxLatDisplacementError    = VDY_ERR_STATE_UNKNOWN;
	stop
	@enduml
  @testmethod			  - Module Testing \n
                            This function has to be tested for statement and branch coverage. \n
                            For detailed unit test description follow the caller graph to the test function \n
                            test_vdy_mon.c -> TEST_vdyFSInit_001()
  @traceability			  - NA
**************************************************************************** */
extern void vdyFSInit(void);
#endif

/*<--- Prototpyes of main function module -------------------------------> */
/* **********************************************************************
  @fn               vdyIsFirstCycleDone */ /*!
  @brief           Test if one complete cycle has been executed after exiting
                    initialization state
  @description     Test if one complete cycle has been executed after exiting
                    initialization state

  @return          boolean, false: first cycle not done, true: first cycle completed

  @glob_in         None 
  @glob_out        None

  @c_switch_part   None 
  @c_switch_full   None 

  @pre             None
  @post            No changes
  @InOutCorrelation Return false: first cycle not done, true: first cycle completed
  
  @startuml
  start
	:return(VDY_IS_FIRST_CYCLE_DONE);
  stop
  @enduml
  @testmethod			  - Module Testing \n
                            This function has to be tested for statement and branch coverage. \n
                            For detailed unit test description follow the caller graph to the test function \n
                            test_vdy_main.c -> TEST_vdyIsFirstCycleDone_001()
  @traceability			  - NA
**************************************************************************** */
extern boolean vdyIsFirstCycleDone(void);

/* **********************************************************************
  @fn               vdyGetCycleTime */ /*!
  @brief           Return component cycle time

  @description     Return component cycle time

  @return          fTime_t: Return component cycle time

  @glob_in         None 
  @glob_out        None

  @c_switch_part   None 
  @c_switch_full   None 

  @pre             None
  @post            No changes
  @InOutCorrelation - Return component cycle time
  
	@startuml
	start
		:return(VDY_GET_CYCLE_TIME);
	stop
	@enduml
  @testmethod			  - NA
  @traceability			  - NA
**************************************************************************** */
extern fTime_t vdyGetCycleTime(void);

/* <--- Prototypes of common function module ----------------------------> */


/* **********************************************************************
  @fn                     vdyHistInit */ /*!
  @brief                  Initialize internal histogram properties

  @description            Sets all bins to 0
                          Sets ranges and volume properties
                          The histogram must be set up correctly, min and max
                          must not be the same, size must be > 0
                          Histograms should be defined by constant values to
                          ensure a valid histogram

  @param[in]              size     : number of bins
  @param[in]              minValue : minimum value of covered range
  @param[in]              maxValue : maximum value of covered range
  @param[in]              volume : Volume of the histogram
  @param[in]              range : Range of histogram
  @param[in, out]         hist: pointer histogram database (valid by definition at calling function)
  @return                 void

  @pre                    -
  @post                   -
  @InOutCorrelation
	- binWidth = (maxValue - minValue) / (float32) size;
	- hist->InvBinWidth = 1.F / binWidth;
	- for bin No, 0 to size of the histogram 
		- hist->Range[binNo]  = (binWidth * ((float32)binNo + ROUNDING_OFFSET)) + minValue;
		- hist->Volume[binNo] = 0.F;

  
	@startuml
	start
		:hist->Mean = VDY_ZERO_F;
		:hist->Dev  = VDY_ZERO_F;
		:hist->Sum  = VDY_ZERO_F;
		:hist->Size = size;
		:hist->Range  = range;
		:hist->Volume = volume;
		:binWidth = (maxValue - minValue) / (float32) size;
		:hist->InvBinWidth = VDY_ONE_F / binWidth;
		:binNo = VDY_ZERO_U;
		repeat
			:hist->Range[binNo]  = (binWidth * ((float32)binNo + ROUNDING_OFFSET)) + minValue;
			:hist->Volume[binNo] = VDY_ZERO_F;
			:binNo = binNo + 1;
		repeat while (binNo < size)
		:return (void);
	stop
	@enduml
  @testmethod			  - Module Testing \n
                            This function has to be tested for statement and branch coverage. \n
                            For detailed unit test description follow the caller graph to the test function \n
                            test_vdy_cofct.c -> TEST_vdyHistInit_001()
  @traceability			  - NA
**************************************************************************** */
extern void vdyHistInit(VDYHistogram_t *hist, float32 *range, float32 *volume, uint32 size, float32 minValue, float32 maxValue);


/* **********************************************************************
  @fn                     vdyHistAdd */ /*!
  @brief                  Add new sample to histogram

  @description            Adds a value into histogram and recalculates range,
                          volume and sum
                          Takes the weight of the value into calculation
                          Histogram pointer is linked static through macro 
                          and therefore valid at runtime
                          Weight is checked to be > 0 and volumes are >= 0,
                          so no division by zero can occur

  @param[in]              value : Value to be added to the histogram
  @param[in]              weight : weight of the histogram
  @param[out]             hist histogram database
  @return                 void

  @pre
  @post                   -
  @InOutCorrelation
	- vdyHistAdd: 
		- invWeight = 1.0F / (weight + hist->Volume[idx]);
		- hist->Range[idx] = (hist->Range[idx] * (hist->Volume[idx] * invWeight)) + ((weight * value) * invWeight);
		- hist->Volume[idx] += weight;
		- hist->Sum         += weight;

  
		@startuml
		start
			:Get Index \n idx = VDYHistGetIndex(hist, value);
			if ( (CML_f_Abs(weight) > C_F32_DELTA) && (idx >= 0L) && (idx < (sint32)hist->Size)) then (YES)
				:invWeight = VDY_ONE_F / (weight + hist->Volume[idx]);
				:hist->Range[idx] = (hist->Range[idx] * (hist->Volume[idx] * invWeight)) + ((weight * value) * invWeight);
				:hist->Volume[idx] += weight;
				:hist->Sum         += weight;
			endif
			:return (void);
		stop
		@enduml

		VDY_ONE_F = 0.0F
		C_F32_DELTA = CML_f_Delta (0.0001F)

  @testmethod			  - Module Testing \n
                            This function has to be tested for statement and branch coverage. \n
                            For detailed unit test description follow the caller graph to the test function \n
                            test_vdy_cofct.c -> TEST_vdyHistAdd_001(), TEST_vdyHistAdd_002(), TEST_vdyHistAdd_003(), TEST_vdyHistAdd_004()
  @traceability			  - 
  - L4
    - doors://rbgs854a:40000/?version=2&prodID=0&urn=urn:telelogic::1-503e822e5ec3651e-O-829-00026448
    - doors://rbgs854a:40000/?version=2&prodID=0&urn=urn:telelogic::1-503e822e5ec3651e-O-1018-00026448
**************************************************************************** */
extern void vdyHistAdd(VDYHistogram_t *hist, float32 value, float32 weight);


/* **********************************************************************
  @fn                     vdyHistGetMaxBin */ /*!
  @brief                  Find bin with maximum content of a hisogram. 

  @description            Returns volume (content) of the largest bin
                          Histogram pointer is linked static through macro 
                          and therefore valid at runtime

  @param[in]              -
  @param[out]             hist histogram database (valid by definition at calling function)
  @return                 void

  @pre
  @post                   -
  @InOutCorrelation
	- Returns volume (content) of the largest bin
  
		@startuml
		start
			:idxMax = VDY_ZERO_U \n maxBin = hist->Volume[idxMax];
			:idx = VDY_ZERO_U;
			repeat
				if (hist->Volume[idx] > maxBin) then (YES)
					:maxBin = hist->Volume[idx];
					:idxMax = idx;
				endif
				:idx = idx + 1;
			repeat while (idx < hist->Size)
			:return (idxMax);
		stop
		@enduml
  @testmethod			  - Module Testing \n
                            This function has to be tested for statement and branch coverage. \n
                            For detailed unit test description follow the caller graph to the test function \n
                            test_vdy_cofct.c -> TEST_vdyHistGetMaxBin_001()
  @traceability			  - NA
**************************************************************************** */
extern uint32 vdyHistGetMaxBin(const VDYHistogram_t *hist);


/* ***********************************************************************
  @fn                     vdyHistCalcMeanDev */ /*!
  @brief                  Calculate mean and standard deviation of a histogram

  @description            see brief description
                          Histogram pointer is linked static through macro 
                          and therefore valid at runtime

  @param[in, out]         hist: pointer to histogram database
  @return                 void

  @pre
  @post                   -
  @InOutCorrelation
	- Calculate mean and standard deviation of a histogram 

  
		@startuml
		start
			:idx = VDY_ZERO_U;
			repeat
			:mean   += hist->Volume[idx] * hist->Range[idx];
			:volSum += hist->Volume[idx];
			:idx = idx + 1;
			repeat while (idx < hist->Size)
			if (CML_f_IsNonZero(volSum)) then (YES)
				:mean  /= volSum;
			else (NO)
				:mean = VDY_ZERO_F;
			endif
			:idx = VDY_ZERO_U;
			repeat
				:stdev += SQR(hist->Range[idx] - mean) * hist->Volume[idx];
				:idx = idx + 1;
			repeat while (idx < hist->Size)
			if (CML_f_IsNonZero(volSum)) then (YES)
				:stdev = VDY_SQRT(stdev/volSum);
			else (NO)
				:stdev = VDY_ZERO_F;
			endif
			:copy values to output \n hist->Mean = mean \n hist->Dev  = stdev;
			:return (void);
		stop
		@enduml

		- VDY_ZERO_U = 0U
		- VDY_ZERO_F = 0.0F
		.
  @testmethod			  - Module Testing \n
                            This function has to be tested for statement and branch coverage. \n
                            For detailed unit test description follow the caller graph to the test function \n
                            test_vdy_cofct.c -> TEST_vdyHistCalcMeanDev_001(), TEST_vdyHistCalcMeanDev_002()
  @traceability			  - 
  - L4
    - doors://rbgs854a:40000/?version=2&prodID=0&urn=urn:telelogic::1-503e822e5ec3651e-O-830-00026448
    - doors://rbgs854a:40000/?version=2&prodID=0&urn=urn:telelogic::1-503e822e5ec3651e-O-1019-00026448
**************************************************************************** */
extern void vdyHistCalcMeanDev(VDYHistogram_t *hist);


/* ***********************************************************************
  @fn                     vdyHistCalcSum */ /*!
  @brief                  Calculate the sum of all bins

  @description            see brief description

  @param[in]              hist histogram database (valid by definition at calling function)
  @param[out]             -
  @return                 sum of all bins

  @pre                    -
  @post                   -
  @InOutCorrelation
  - Calculate the sum of all bins

  
	@startuml
	start
		:sum = VDY_ZERO_F;
		:idx = VDY_ZERO_U;
		while(idx < hist->Size)
			:sum += hist->Volume[idx];
			:idx = idx + 1;
		endwhile
		:return (sum);

	stop
	@enduml
  @testmethod			  - Module Testing \n
                            This function has to be tested for statement and branch coverage. \n
                            For detailed unit test description follow the caller graph to the test function \n
                            test_vdy_cofct.c -> TEST_vdyHistCalcSum_001()
  @traceability			  - NA
**************************************************************************** */
extern float32 vdyHistCalcSum(const VDYHistogram_t *hist);


/* ***********************************************************************
  @fn                     vdyHistCalcMeanCenter */ /*!
  @brief                  Calculate mean around center with counts raised 
                          to a power
  @description            see brief description
                          In case the power is > 1, the values are prescaled
                          by 1/1000 to avoid large numbers and possible overflow
                          In case of an empty histogram, 0 is returned as mean

  @param[in]              idxCenter center bin
  @param[in]              width around the center
  @param[in]              pwr
  @param[out]             hist histogram database (valid by definition at calling function)
  @return                 mean

  @pre
  @post                   -
  @InOutCorrelation
  - Calculate mean around center with counts raised to a power

  
	@startuml
	start
		if (idxCenter >= width) the (YES)
			:idx_start = idxCenter - width;
		else (NO)
			:idx_start = VDY_ZERO_U;
		endif
		if ( (idxCenter + width) < hist->Size ) the (YES)
			:idx_stop = idxCenter + width;
		else (NO)
			:idx_stop = hist->Size - VDY_ONE_U;
		endif
		:idx=idx_start;
		repeat
		:Prescale to avoid large values in case of power > 1 \n preScale_c = 0.001F;
		:vol = hist->Volume[idx] * ((pwr > VDY_ONE_U) ? (hist->Volume[idx] * preScale_c) : (float32) pwr);
		:mean   += vol * hist->Range[idx];
		:volSum += vol;
		:idx = idx + 1;
		repeat while (idx <= idx_stop)
		if (volSum > VDY_ZERO_F) then (YES)
			:mean  /= volSum; 
		else (NO)
			:mean = VDY_ZERO_F;
		endif
		:return (mean);
	stop
	@enduml

	- VDY_ZERO_U = 0U
	- VDY_ONE_U = 1U
  @testmethod			  - Module Testing \n
                            This function has to be tested for statement and branch coverage. \n
                            For detailed unit test description follow the caller graph to the test function \n
                            test_vdy_cofct.c -> TEST_vdyHistCalcMeanCenter_001(), TEST_vdyHistCalcMeanCenter_002(), TEST_vdyHistCalcMeanCenter_003()
  @traceability			  - NA
**************************************************************************** */
extern float32 vdyHistCalcMeanCenter(const VDYHistogram_t *hist, uint32 idxCenter, uint32 width, uint32 pwr);


/* ***********************************************************************
  @fn                     vdyHistReInit */ /*!
  @brief                  Reinitialize internal histogram properties

  @description            Erases content data (bins and mean/dev/sum)
                          but not fixed data (e.g. range)
                          Histogram pointer is linked static through macro 
                          and therefore valid at runtime

  @param[in]              -
  @param[out]             hist histogram database (valid by definition at calling function)
  @return                 void

  @pre                    -
  @post                   -
  @InOutCorrelation
  - step through all bins and clear their volumes 

  
	@startuml
	start
		:hist->Mean = VDY_ZERO_F \n hist->Dev  = VDY_ZERO_F \n hist->Sum  = VDY_ZERO_F;
		:binNo = VDY_ZERO_U;
		repeat
			: step through all bins and clear their volumes \n hist->Volume[binNo] = VDY_ZERO_F;
			: binNo = binNo + 1;
		repeat while(binNo < hist->Size)
		:return (void);
	stop
	@enduml
  @testmethod			  - Module Testing \n
                            This function has to be tested for statement and branch coverage. \n
                            For detailed unit test description follow the caller graph to the test function \n
                            test_vdy_cofct.c -> TEST_vdyHistReInit_001()

  @traceability			  - NA
**************************************************************************** */
extern void vdyHistReInit(VDYHistogram_t *hist);


/* ***********************************************************************
  @fn                     vdyHistReduce */ /*!
  @brief                  Reduces histogram data

  @description            Reduces histogram bins and sum by using a reduction factor
                          Histogram pointer is linked static through macro 
                          and therefore valid at runtime

  @param[in]              weight
  @param[out]             hist histogram database (valid by definition at calling function)
  @return                 void

  @pre
  @post                   -
  @InOutCorrelation
	- vdyHistReduce
		- for binNo, 0 to histogram size
			- hist->Volume[binNo] *= weight;
		- hist->Sum *= weight;
  
	@startuml
	start
		:binNo = VDY_ZERO_U;
		repeat
			:hist->Volume[binNo] *= weight;
			:binNo = binNo + 1;
		repeat while (binNo<hist->Size)
		:hist->Sum *= weight;
		:return (void);
	stop
	@enduml
  @testmethod			  - Module Testing \n
                            This function has to be tested for statement and branch coverage. \n
                            For detailed unit test description follow the caller graph to the test function \n
                            test_vdy_cofct.c -> TEST_vdyHistReduce_001()
  @traceability			  - NA
**************************************************************************** */
extern void vdyHistReduce(VDYHistogram_t *hist, float32 weight);


/* ***********************************************************************
  @fn                     vdyHistCalcMedian */ /*!
  @brief                  Calculate linear interpolated median value
                          
  @description            gets median value by summing up the bins until
                          half of the sum is exceeded, index of median
                          is then that found index minus 1
                          Bin of the median index cannot be 0, at least one
                          value is in the histogram (must be ensured by caller)
                          Median value is improved by a linear aproximation

  @param[in]              hist histogram database (valid by definition at calling function)
  @param[out]             -
  @return                 median

  @pre                    -
  @post                   -
  @InOutCorrelation
  - Calculate linear interpolated median value

  
	@startuml
	start
		:Calculate median rank \n rank = VDY_FIFTY_CENT * hist->Sum;
		:To avoid floating point comparison in for loop Misra issue using checkagain \n checkagain = (boolean)((volSum < rank) ? TRUE : FALSE );
		:idx = VDY_ZERO_U;
		repeat
			:volSum += hist->Volume[idx];
			:checkagain = (boolean)((volSum < rank) ? TRUE : FALSE );
			:idx = idx + 1;
		repeat while ((idx < hist->Size) && (checkagain == (boolean)TRUE))
		if (get median range value \n idx > VDY_ZERO_U) then (YES) 
			:idx = idx - 1;
		endif
		:median = hist->Range[idx];
		:Determine current bin width \n bwdth = hist->Range[idx + VDY_ONE_U] - hist->Range[idx];
		:improve value by linear interpolation \n median += (-(VDY_FIFTY_CENT) * bwdth) + ((((rank - (volSum - hist->Volume[idx])) - VDY_FIFTY_CENT) * bwdth) / hist->Volume[idx]);
		:return (median);
	stop
	@enduml
	- VDY_FIFTY_CENT = 0.5F
	- VDY_ZERO_U = 0U
	- TRUE = 1
	- FALSE = 0
  @testmethod			  - Module Testing \n
                            This function has to be tested for statement and branch coverage. \n
                            For detailed unit test description follow the caller graph to the test function \n
                            test_vdy_cofct.c -> TEST_vdyHistCalcMedian_001(), TEST_vdyHistCalcMedian_002(), TEST_vdyHistCalcMedian_003()
  @traceability			  - 
  - L4
    - doors://rbgs854a:40000/?version=2&prodID=0&urn=urn:telelogic::1-503e822e5ec3651e-O-830-00026448
    - doors://rbgs854a:40000/?version=2&prodID=0&urn=urn:telelogic::1-503e822e5ec3651e-O-1019-00026448
**************************************************************************** */
extern float32 vdyHistCalcMedian(const VDYHistogram_t *hist);


/* **********************************************************************
  @fn                     vdyHistGetVolume */ /*!
  @brief                  Get volume / counts for specified range/bin

  @description            Returns volume for bin if index is in range of
                          histogram, otherwise returns 0
                          Histogram pointer is linked static through macro 
                          and therefore valid at runtime

  @param[in]              value weight
  @param[out]             hist histogram database (valid by definition at calling function)
  @return                 void

  @pre                    -
  @post                   -
  @InOutCorrelation
	- Returns volume for bin if index is in range of histogram, otherwise returns 0
	@startuml
	start
		:idx = VDYHistGetIndex(hist, value);
		if ( (idx >= VDY_ZERO) && (idx < (sint32)hist->Size) ) then (YES)
			:ret = hist->Volume[idx];
		else (NO)
			:ret = VDY_ZERO_F;
		endif
		:return (ret);
	stop
	@enduml
  @testmethod			  - Module Testing \n
                            This function has to be tested for statement and branch coverage. \n
                            For detailed unit test description follow the caller graph to the test function \n
                            test_vdy_cofct.c -> TEST_vdyHistGetVolume_001(), TEST_vdyHistGetVolume_002(), TEST_vdyHistGetVolume_003()
  @traceability			  - NA
**************************************************************************** */
extern float32 vdyHistGetVolume(const VDYHistogram_t *hist, float32 value);

#if (CFG_VDY_FPM_754)
	
/* **********************************************************************
  @fn               vdySqrt */ /*!
  @brief            Fast square root approximation

  @description      Approximation by fast inverse square root approximation

  @param[in]        x
  @param[out]       -
  @return           Approximation by fast inverse square root approximation

  @pre              x > 0, IEEE754 Floating Point format
  @post             none
  @InOutCorrelation
  - Fast square root approximation
  
  @testmethod			  - Module Testing \n
                            This function has to be tested for statement and branch coverage. \n
                            For detailed unit test description follow the caller graph to the test function \n
                            test_vdy_cofct.c -> TEST_vdySqrt_001(), TEST_vdySqrt_002()
  @traceability			  - NA
**************************************************************************** */
extern float32 vdySqrt(float32 x);


/* **********************************************************************
  @fn               vdyInvSqrt */ /*!
  @brief            Fast inverse square root approximation

  @description      Newton iteration,

  @param[in]        x
  @param[out]       -
  @return           Approximation of x^-1/2

  @pre              x > 0, IEEE754 Floating Point format
  @post             none
  @InOutCorrelation
  - Fast inverse square root approximation
  
  @testmethod			  - Module Testing \n
                            This function has to be tested for statement and branch coverage. \n
                            For detailed unit test description follow the caller graph to the test function \n
                            test_vdy_cofct.c -> TEST_vdyInvSqrt_001()
  @traceability			  - NA
**************************************************************************** */
extern float32 vdyInvSqrt(float32 x);

/* **********************************************************************
  @fn               vdyExp */ /*!
  @brief            Fast approximation exponential function

  @description      see brief description

  @param[in]        x
  @param[out]       -
  @return           Approximation of exp(x)

  @pre              x < 80, IEEE754 Floating Point format
  @post             Postcondition: none
  @InOutCorrelation
  - Fast approximation exponential function
  
  @testmethod			  - Module Testing \n
                            This function has to be tested for statement and branch coverage. \n
                            For detailed unit test description follow the caller graph to the test function \n
                            test_vdy_cofct.c -> TEST_vdyExp_001(), TEST_vdyExp_002()
  @traceability			  - NA
**************************************************************************** */
extern float32 vdyExp(float32 x);
#endif

/* ***********************************************************************
  @fn                     vdyStatIntervalInit */ /*!
  @brief                  Initialize all attributes (mean, deviation etc.)

  @description            Erases calculated data of given histogram

  @param[in]              -
  @param[out]             StatInterval interval = observation database
  @return                 void

  @pre
  @post                   -
  @InOutCorrelation
  - Initialize all attributes (mean, deviation etc.)
  
	@startuml
	start
		:StatInterval->Sum         = VDY_ZERO_F;
		:StatInterval->SqSum       = VDY_ZERO_F;
		:StatInterval->Volume      = VDY_ZERO_F;
		:StatInterval->Mean        = VDY_ZERO_F;
		:StatInterval->Dev         = VDY_ZERO_F;
		:return (void);
	stop
	@enduml
  @testmethod			  - Module Testing \n
                            This function has to be tested for statement and branch coverage. \n
                            For detailed unit test description follow the caller graph to the test function \n
                            test_vdy_cofct.c -> TEST_vdyStatIntervalInit_001()
  @traceability			  - NA
**************************************************************************** */
extern void vdyStatIntervalInit(VDYStatInterval_t *StatInterval);


/* **********************************************************************
  @fn                     vdyStatIntervalInitInput */ /*!
  @brief                  Initialize internal attributes used for acquisition
                          Result mean, dev are not initialized
  @description            see brief description

  @param[in]              -
  @param[out]             StatInterval interval = observation database
  @return                 void

  @pre
  @post                   -
  @InOutCorrelation
  - Initialize internal attributes used for acquisition; Result mean, dev are not initialized
  
	@startuml
	start
		  :StatInterval->Sum         = VDY_ZERO_F;
		  :StatInterval->SqSum       = VDY_ZERO_F;
		  :StatInterval->Volume      = VDY_ZERO_F;
		  :return (void);

	stop
	@enduml
  @testmethod			  - Module Testing \n
                            This function has to be tested for statement and branch coverage. \n
                            For detailed unit test description follow the caller graph to the test function \n
                            test_vdy_cofct.c -> TEST_vdyStatIntervalInitInput_001()
  @traceability			  - NA
**************************************************************************** */
extern void vdyStatIntervalInitInput(VDYStatInterval_t *StatInterval);


/* ***********************************************************************
  @fn                     vdyStatIntervalAdd */ /*!
  @brief                  Add new input value to interval

  @description            see brief description, updates calculated data,
                          considers the weight

  @param[in]              Value     = input value
  @param[in]              Weight    = weight of input value
  @param[in,out]          StatInterval interval  = observation database
  @return                 void

  @pre                    If value is not weighted, weightning must be 1.0
  @post                   -
  @InOutCorrelation
  - Add new input value to interval
  
	@startuml
	start
		:StatInterval->Sum       += Value * Weight;
		:StatInterval->SqSum     += SQR(Value) * Weight;
		:StatInterval->Volume    += Weight;
		:return (void);
	stop
	@enduml
  @testmethod			  - Module Testing \n
                            This function has to be tested for statement and branch coverage. \n
                            For detailed unit test description follow the caller graph to the test function \n
                            test_vdy_cofct.c -> TEST_vdyStatIntervalAdd_001()
  @traceability			  - 
  - L4
    - doors://rbgs854a:40000/?version=2&prodID=0&urn=urn:telelogic::1-503e822e5ec3651e-O-1037-00026448
**************************************************************************** */
extern void vdyStatIntervalAdd(VDYStatInterval_t *StatInterval,float32 Value , float32 Weight);


/* ***********************************************************************
  @fn                     vdyStatIntervalReduce */ /*!
  @brief                  Reduction of interval

  @description            see brief description

  @param[in]              Factor    = Reduction factor
  @param[in,out]          StatInterval interval  = observation database
                   
  @param[out]             -
  @return                 void

  @pre                    -
  @post                   -
  @InOutCorrelation
  - Divide by factor
  
	@startuml
	start
		:StatInterval->Sum       *= Factor;
		:StatInterval->SqSum     *= Factor;
		:StatInterval->Volume    *= Factor;
		:return (void);
	stop
	@enduml

  @testmethod			  - Module Testing \n
                            This function has to be tested for statement and branch coverage. \n
                            For detailed unit test description follow the caller graph to the test function \n
                            test_vdy_cofct.c -> TEST_vdyStatIntervalReduce_001()
  @traceability			  - 
  - L4
    - doors://rbgs854a:40000/?version=2&prodID=0&urn=urn:telelogic::1-503e822e5ec3651e-O-1040-00026448
    - doors://rbgs854a:40000/?version=2&prodID=0&urn=urn:telelogic::1-503e822e5ec3651e-O-1042-00026448
**************************************************************************** */
extern void vdyStatIntervalReduce(VDYStatInterval_t *StatInterval, float32 Factor);


/* ***********************************************************************
  @fn                     vdyStatIntervalMerge */ /*!
  @brief                  Combine two intervals to one resulting interval 

  @description            adds one statistic measurement interval
                          to another interval

  @param[in]              StatInterval_2  = 2nd observation interval
  @param[in,out]          StatInterval_1  = 1st onservation interval and result
  @return                 void

  @pre                    -
  @post                   -
  @InOutCorrelation
  - Combine two intervals to one resulting interval
  
	@startuml
	start
		:StatInterval_1->Sum    += StatInterval_2->Sum;
		:StatInterval_1->SqSum  += StatInterval_2->SqSum;
		:StatInterval_1->Volume += StatInterval_2->Volume;
		:return (void);		
	stop
	@enduml

  @testmethod			  - Module Testing \n
                            This function has to be tested for statement and branch coverage. \n
                            For detailed unit test description follow the caller graph to the test function \n
                            test_vdy_cofct.c -> TEST_vdyStatIntervalMerge_001()
  @traceability			  - 
  - L4
    - doors://rbgs854a:40000/?version=2&prodID=0&urn=urn:telelogic::1-503e822e5ec3651e-O-1040-00026448
**************************************************************************** */
extern void vdyStatIntervalMerge( VDYStatInterval_t *StatInterval_1,  const VDYStatInterval_t *StatInterval_2 );


/* ***********************************************************************
  @fn                     vdyStatIntervalMeanDev */ /*!
  @brief                  Calculate mean and deviation of interval

  @description            see brief description
                          deviation is set to 0 if it cannot be calculated

  @param[in,out]          StatInterval = observation interval
  @param[out]             -
  @return                 void

  @pre                    -
  @post                   -
  @InOutCorrelation
  - Calculate mean and deviation of interval
  
	@startuml
	start
		if (CML_f_IsNonZero(StatInterval->Volume)) then (YES) 
			:StatInterval->Mean = StatInterval->Sum / StatInterval->Volume \n Varianz = (StatInterval->SqSum / StatInterval->Volume) - SQR(StatInterval->Mean);
			if ((CML_f_IsNonZero(Varianz)) && (Varianz > VDY_ZERO_F)) then (YES)
				:StatInterval->Dev = VDY_SQRT(Varianz);
			else (NO)
				:StatInterval->Dev = VDY_ZERO_F;
			endif
		else (NO)
		:StatInterval->Dev   = VDY_ZERO_F;
		endif
		:return (void);
	stop
	@enduml
  @testmethod			  - Module Testing \n
                            This function has to be tested for statement and branch coverage. \n
                            For detailed unit test description follow the caller graph to the test function \n
                            test_vdy_cofct.c -> TEST_vdyStatIntervalMeanDev_001(), TEST_vdyStatIntervalMeanDev_002(), TEST_vdyStatIntervalMeanDev_003(), TEST_vdyStatIntervalMeanDev_004()
  @traceability			  - 
  - L4
    - doors://rbgs854a:40000/?version=2&prodID=0&urn=urn:telelogic::1-503e822e5ec3651e-O-1037-00026448
    - doors://rbgs854a:40000/?version=2&prodID=0&urn=urn:telelogic::1-503e822e5ec3651e-O-1041-00026448
**************************************************************************** */
extern void vdyStatIntervalMeanDev(VDYStatInterval_t *StatInterval);


/* ***********************************************************************
  @fn                     vdyStatIntervalPrealloc */ /*!
  @brief                  Preallocate interval 

  @description            Sets interval to defined preallocation values
                          and calculated derived values

  @param[in]              Mean         = predefined mean value
  @param[in]              Volume       = predefined volume
  @param[in]              Dev          = predefined standard deviation
  @param[out]             StatInterval = observation interval
  @return                 void

  @pre                    -
  @post                   -
  @InOutCorrelation
  - Preallocate interval
  
	@startuml
	start
		:Sum from mean with the assumption that volume equal to number \n StatInterval->Sum  = Mean * Volume;
		:Recalculate the square sum for standard deviation \n StatInterval->SqSum = SQR(Dev) + SQR(Mean) \n StatInterval->SqSum = StatInterval->SqSum * Volume;
		:Weightning is not considered \n StatInterval->Volume = Volume;
		:return (void);
	stop
	@enduml
  @testmethod			  - Module Testing \n
                            This function has to be tested for statement and branch coverage. \n
                            For detailed unit test description follow the caller graph to the test function \n
                            test_vdy_cofct.c -> TEST_vdyStatIntervalPrealloc_001()
  @traceability			  - NA
**************************************************************************** */
extern void vdyStatIntervalPrealloc(VDYStatInterval_t *StatInterval,float32 Mean, float32 Volume, float32 Dev);


/* ***********************************************************************
  @fn                vdyHpSort */ /*!
  @brief             Heapsort algorithm (see Numerical Recipes)

  @description       Sorts an array into ascending numerical order
                     Because of the upper bound on heapsort's running time and 
                     constant upper bound on its auxiliary storage, heap sort 
                     is used instead of quick sort

  @param[in]         no  = number of samples
  @param[out]        ra  = sorted rearrangement
  @return            void

  @pre               -
  @post              -
  @InOutCorrelation
  - Heapsort algorithm 
  
	@startuml
	start
		if (no > 1u) then (YES)
			:finish = FALSE;
			:k  = no>>1uL;
			:ir = no - 1u;
			while (finish == FALSE)
				if (k > 0u) then (Still in hiring phase)
					:k= k - 1;
					:rra = ra[k];
				else (In retirement-and-promotion phase)
					:Clear a space at end of array \n rra    = ra[ir];
					:Retire the top of the heap into it \n ra[ir] = ra[0];
					if (ir > 0u) then (YES) 
						:ir = ir -1;
					endif
					if (ir == 0u) then (Done with the last promotion )
						:The least component worker of all \n ra[0] = rra;
						:finish = TRUE;
					endif
				endif
				if (finish == FALSE) then (YES)
					:b_Aborted = FALSE;
					:Whether in the hiring phase or promotion phase, we here set up to sift down element rra to its proper level \n i = k; \n j = k + k;
					while ( (b_Aborted == FALSE) && (j <= ir) )
						if (Compare to the better underling \n (j < ir) && (ra[j] < ra[j+1u])) then (YES)
							: j = j +1;
						endif
						if (Demote rra \n rra < ra[j]) then (YES)
							:ra[i] = ra[j];
							:i = j;
							if (j > 0U) then (YES)
								:j = j << 1U;
							else (NO)
								:j = 1U;
							endif
						else (Found rra's level. Terminate the sift-down)
							:b_Aborted = TRUE;
						endif
					endwhile
					:Put rra into its slot \n ra[i] = rra;
				endif
			endwhile
		endif
		:return (void);
	stop
	@enduml
  @testmethod			  - Module Testing \n
                            This function has to be tested for statement and branch coverage. \n
                            For detailed unit test description follow the caller graph to the test function \n
                            test_vdy_cofct.c -> TEST_vdyHpSort_001(), TEST_vdyHpSort_002(), TEST_vdyHpSort_003()
  @traceability			  - 
  - L4
    - doors://rbgs854a:40000/?version=2&prodID=0&urn=urn:telelogic::1-503e822e5ec3651e-O-403-00026448
**************************************************************************** */
extern void vdyHpSort(uint32 no, float32 ra[]);


/* ***********************************************************************
  @fn                     vdyHpSortInd */ /*!
  @brief                  Heapsort algorithm (see Numerical Recipes)

  @description            Sorts an index array referncing a numerical array 
                          into ascending numerical order

  @param[in]              no  = number of samples
  @param[in]              ra  = array of samples
  @param[out]             idx = sorted index rearrangement
  @return                 void

  @pre                    -
  @post                   -
  @InOutCorrelation
  - Heapsort algorithm 
  
	@startuml
	start
		if (no > 1u) then (YES)
			:finish = FALSE;
			:k  = no>>1uL;
			:ir = no - 1u;
			while (finish == FALSE)
				if (k > 0u) then (Still in hiring phase)
					:k= k - 1;
					:rra = ra[k];
				else (In retirement-and-promotion phase)
					:Clear a space at end of array \n rra    = ra[ir];
					:Retire the top of the heap into it \n ra[ir] = ra[0];
					if (ir > 0u) then (YES) 
						:ir = ir -1;
					endif
					if (ir == 0u) then (Done with the last promotion )
						:The least component worker of all \n ra[0] = rra;
						:finish = TRUE;
					endif
				endif
				if (finish == FALSE) then (YES)
					:b_Aborted = FALSE;
					:Whether in the hiring phase or promotion phase, we here set up to sift down element rra to its proper level \n i = k; \n j = k + k;
					while ( (b_Aborted == FALSE) && (j <= ir) )
						if (Compare to the better underling \n (j < ir) && (ra[j] < ra[j+1u])) then (YES)
							: j = j +1;
						endif
						if (Demote rra \n rra < ra[j]) then (YES)
							:ra[i] = ra[j];
							:i = j;
							if (j > 0U) then (YES)
								:j = j << 1U;
							else (NO)
								:j = 1U;
							endif
						else (Found rra's level. Terminate the sift-down)
							:b_Aborted = TRUE;
						endif
					endwhile
					:Put rra into its slot \n ra[i] = rra;
				endif
			endwhile
		endif
		:return (void);
	stop
	@enduml
  @testmethod			  - Module Testing \n
                            This function has to be tested for statement and branch coverage. \n
                            For detailed unit test description follow the caller graph to the test function \n
                            test_vdy_cofct.c -> TEST_vdyHpSortInd_001(), TEST_vdyHpSortInd_002(), TEST_vdyHpSortInd_003()
  @traceability			  - 
  - L4
    - doors://rbgs854a:40000/?version=2&prodID=0&urn=urn:telelogic::1-503e822e5ec3651e-O-403-00026448
**************************************************************************** */
extern void vdyHpSortInd(uint32 no, const float32 ra[], uint32 idx[]);


/* ***********************************************************************
  @fn                     vdyHpSortIndU16 */ /*!
  @brief                  Heapsort algorithm (see Numerical Recipes)

  @description            Sorts an index array referencing a numerical array 
                          into ascending numerical order

  @param[in]              no  = number of samples
  @param[in]              ra  = array of samples
  @param[out]             idx = sorted index rearrangement
  @return                 void

  @pre                    -
  @post                   -
  @InOutCorrelation
  - Heapsort algorithm 
  
	@startuml
	start
		if (no > 1u) then (YES)
			:finish = FALSE;
			:k  = no>>1uL;
			:ir = no - 1u;
			while (finish == FALSE)
				if (k > 0u) then (Still in hiring phase)
					:k= k - 1;
					:rra = ra[k];
				else (In retirement-and-promotion phase)
					:Clear a space at end of array \n rra    = ra[ir];
					:Retire the top of the heap into it \n ra[ir] = ra[0];
					if (ir > 0u) then (YES) 
						:ir = ir -1;
					endif
					if (ir == 0u) then (Done with the last promotion )
						:The least component worker of all \n ra[0] = rra;
						:finish = TRUE;
					endif
				endif
				if (finish == FALSE) then (YES)
					:b_Aborted = FALSE;
					:Whether in the hiring phase or promotion phase, we here set up to sift down element rra to its proper level \n i = k; \n j = k + k;
					while ( (b_Aborted == FALSE) && (j <= ir) )
						if (Compare to the better underling \n (j < ir) && (ra[j] < ra[j+1u])) then (YES)
							: j = j +1;
						endif
						if (Demote rra \n rra < ra[j]) then (YES)
							:ra[i] = ra[j];
							:i = j;
							if (j > 0U) then (YES)
								:j = j << 1U;
							else (NO)
								:j = 1U;
							endif
						else (Found rra's level. Terminate the sift-down)
							:b_Aborted = TRUE;
						endif
					endwhile
					:Put rra into its slot \n ra[i] = rra;
				endif
			endwhile
		endif
		:return (void);
	stop
	@enduml
  @testmethod			  - Module Testing \n
                            This function has to be tested for statement and branch coverage. \n
                            For detailed unit test description follow the caller graph to the test function \n
                            test_vdy_cofct.c -> TEST_vdyHpSortIndU16_001(), TEST_vdyHpSortIndU16_002(), TEST_vdyHpSortIndU16_003()
  @traceability			  - 
  - L4
    - doors://rbgs854a:40000/?version=2&prodID=0&urn=urn:telelogic::1-503e822e5ec3651e-O-403-00026448
**************************************************************************** */
extern void vdyHpSortIndU16(uint32 no, const uint16 ra[], uint8 idx[]);


/* **********************************************************************
  @fn                     vdyHpSortIndF32 */ /*!
  @brief                  Heapsort algorithm (see Numerical Recipes)

  @description            Sorts an index array referencing a numerical array 
                          into ascending numerical order

  @param[in]              no  = number of samples
  @param[in]              ra  = array of samples
  @param[out]             idx = sorted index rearrangement
  @return                 void

  @pre                    -
  @post                   -
  @InOutCorrelation
  - Heapsort algorithm 
  
	@startuml
	start
		if (no > 1u) then (YES)
			:finish = FALSE;
			:k  = no>>1uL;
			:ir = no - 1u;
			while (finish == FALSE)
				if (k > 0u) then (Still in hiring phase)
					:k= k - 1;
					:rra = ra[k];
				else (In retirement-and-promotion phase)
					:Clear a space at end of array \n rra    = ra[ir];
					:Retire the top of the heap into it \n ra[ir] = ra[0];
					if (ir > 0u) then (YES) 
						:ir = ir -1;
					endif
					if (ir == 0u) then (Done with the last promotion )
						:The least component worker of all \n ra[0] = rra;
						:finish = TRUE;
					endif
				endif
				if (finish == FALSE) then (YES)
					:b_Aborted = FALSE;
					:Whether in the hiring phase or promotion phase, we here set up to sift down element rra to its proper level \n i = k; \n j = k + k;
					while ( (b_Aborted == FALSE) && (j <= ir) )
						if (Compare to the better underling \n (j < ir) && (ra[j] < ra[j+1u])) then (YES)
							: j = j +1;
						endif
						if (Demote rra \n rra < ra[j]) then (YES)
							:ra[i] = ra[j];
							:i = j;
							if (j > 0U) then (YES)
								:j = j << 1U;
							else (NO)
								:j = 1U;
							endif
						else (Found rra's level. Terminate the sift-down)
							:b_Aborted = TRUE;
						endif
					endwhile
					:Put rra into its slot \n ra[i] = rra;
				endif
			endwhile
		endif
		:return (void);
	stop
	@enduml
  @testmethod			  - Module Testing \n
                            This function has to be tested for statement and branch coverage. \n
                            For detailed unit test description follow the caller graph to the test function \n
                            test_vdy_cofct.c -> TEST_vdyHpSortIndF32_001(), TEST_vdyHpSortIndF32_002(), TEST_vdyHpSortIndF32_003()
  @traceability			  - 
  - L4
    - doors://rbgs854a:40000/?version=2&prodID=0&urn=urn:telelogic::1-503e822e5ec3651e-O-403-00026448
**************************************************************************** */
extern void vdyHpSortIndF32(uint32 no, const float32 ra[], uint8 idx[]);


/* ***********************************************************************
  @fn                     vdyDiscretize */ /*!
  @brief                  Discretize input value at given interval

  @description            Creates discretized value with given quantization 
                          Caller must ensure that quantization interval is not 0,
                          should be a constant value

  @param[in]              value input value
  @param[in]              interval quantization interval
  @param[out]             -
  @return                 disretized value
  
  @pre                    input value within -2^31 .. 2^31-1
  @post                   -
  @InOutCorrelation
  - Discretize input value at given interval
  
	@startuml
	start
		:value = value / interval;
		:intValue  = ROUND_TO_INT( value );
		:value  = interval * (float32) intValue;
		:return (value);
	stop
	@enduml

  @testmethod			  - Module Testing \n
                            This function has to be tested for statement and branch coverage. \n
                            For detailed unit test description follow the caller graph to the test function \n
                            test_vdy_cofct.c -> TEST_vdyDiscretize_001()
  @traceability			  - NA
**************************************************************************** */
extern float32 vdyDiscretize(float32 value, float32 interval);


/* ***********************************************************************
  @fn                     vdyLFunction */ /*!
  @brief                  Linear ramp function

  @description            Calculates function value of input for
                          a linear function defined by 2 points (min and max).
                          The function value is limited to the interval
                          given by the min and max points

  @param[in]              Input   Current input value
  @param[in]              InputMin 
  @param[in]              OutputMin  1st node
  @param[in]              InputMax
  @param[in]              OutputMax  2nd node
  @param[out]             -
  @return                 Value between/equal to output min and max value 

  @pre                    -
  @post                   -
  @InOutCorrelation
  - Linear ramp function
  
	@startuml
	start
		:slope \n Gradient = (OutputMax-OutputMin)/(InputMax-InputMin);
		:y-axis intercept \n Section  = OutputMin - (Gradient * InputMin);
		:Linear equation \n Output = (Gradient * Input) + Section;
		if (OutputMin < OutputMax) then (YES)
			:Limit values \n Output = MINMAX_FLOAT(OutputMin, OutputMax, Output);
		else (NO)
			:Limit values \n Output = MINMAX_FLOAT(OutputMax, OutputMin, Output);
		endif
		:return (Output);
	stop
	@enduml
  @testmethod			  - Module Testing \n
                            This function has to be tested for statement and branch coverage. \n
                            For detailed unit test description follow the caller graph to the test function \n
                            test_vdy_cofct.c -> TEST_vdyLFunction_001(), TEST_vdyLFunction_002()
  @traceability			  - NA
**************************************************************************** */
extern float32 vdyLFunction(float32 Input, float32 InputMin,float32 InputMax, float32 OutputMin,float32 OutputMax);


/* **********************************************************************
  @fn               vdyCalcGradient */ /*!
  @brief            Calculate the gradient

  @description      Calculates gradient for one VDY cycle
                    Note: The cycle time is given from system and checked
                    at the beginning of VDY.  If a cycle time of 0ms was detected,
                    the cylce time was set to the default of 20ms and will 
                    never be 0 within VDY

  @param[in]        NewValue : New Value
  @param[in]        OldValue : Old Value
  @return           Gradient : Gradient

  @pre              -
  @post             -
  @InOutCorrelation
  - Calculate the gradient
  
		@startuml
		start
			:Get cycle time \n CycleTime = vdyGetCycleTime();
			:Calculate gradient (cycletime cannot be zero, has been set to 20ms in that case) \n Gradient = (NewValue - OldValue) / (CycleTime);
			:return (Gradient);
		stop
		@enduml

  @testmethod			  - Module Testing \n
                            This function has to be tested for statement and branch coverage. \n
                            For detailed unit test description follow the caller graph to the test function \n
                            test_vdy_cofct.c -> TEST_vdyCalcGradient_001()
  @traceability			  - NA
**************************************************************************** */
extern fGradient_t vdyCalcGradient(float32 NewValue, float32 OldValue);


/* **********************************************************************
  @fn                     vdyCheckCurve */ /*!
  @brief                  Verify whether the curvature is within limit or not

  @description            Checks if curve value is less than max curve value
                          If curve quality is less than min curve quality,
                          the curve value cannot be checked and an unknown
                          status is returned

  @param[in]              Course      Input curvature
  @param[in]              MaxCurve    Maximum curvature
  @param[in]              MinQuality  Minimum quality for test
  @param[out]             -
  @return                 status OK, NOT_OK, DONT_KNOW

  @pre                    -
  @post                   -
  @InOutCorrelation
  - Verify whether the curvature is within limit or not
  
	@startuml
	start
		if (Course->Variance >= MinQuality) then (YES)
			if (Curve has sufficient quality for range test \n CML_f_Abs(Course->Curve) <= MaxCurve ) then (YES)
				:Curvature within limit \n Status = (VDYCrvStatus_t) VDY_CRV_OK;
			else (NO)
				:Curvature outside the limit \n Status = (VDYCrvStatus_t) VDY_CRV_NOTOK;
			endif
		else (NO)
			:Insufficient quality \n Status = (VDYCrvStatus_t) VDY_CRV_DONT_KNOW;
		endif
		:return (Status);
	stop
	@enduml
		
  @testmethod			  - Module Testing \n
                            This function has to be tested for statement and branch coverage. \n
                            For detailed unit test description follow the caller graph to the test function \n
                            test_vdy_cofct.c -> TEST_vdyCheckCurve_001(), TEST_vdyCheckCurve_002(), TEST_vdyCheckCurve_003()
  @traceability			  - NA
**************************************************************************** */
extern VDYCrvStatus_t vdyCheckCurve(const VDYOutCurve_t *Course, fCurve_t MaxCurve, fQuality_t MinQuality);


/* **********************************************************************
  @fn                     vdyGetCurveDir */ /*!
  @brief                  Determination of curvature direction

  @description            Checks the direction of a curve, curve is straight
                          if within straightforward threshold, otherwise
                          left or right based on sign
                          If curve quality is less than min curve quality,
                          the curve value cannot be checked and an unknown
                          status is returned

  @param[in]              Course      Input course
  @param[in]              ThrdCurve   Straightforward threshold
  @param[in]              MinQuality  Minimum quality for determination
  @param[out]             -
  @return                 Left, Right, Straightforward, Unknown

  @pre                    -
  @post                   -
  @InOutCorrelation
  - Determination of curvature direction
  
	@startuml
	start
		:Direction output value \n Status;
		if (Curve has sufficient quality for direction decision \n Course->Variance >= MinQuality ) then (YES)
			if (Course->Curve < -ThrdCurve) then (YES)
				:Right Direction \n Status = (VDYCrvDirStatus_t) CRV_DIR_RIGHT;
			else if (Course->Curve > ThrdCurve) then (YES)
				:Left Direction \n Status = (VDYCrvDirStatus_t) CRV_DIR_LEFT;
			else (NO)
				:Straight Direction \n Status = (VDYCrvDirStatus_t) CRV_DIR_STRAIGHT;
			endif
		else (NO)
			:insufficient quality and Unknown Direction \n Status = (VDYCrvDirStatus_t) CRV_DIR_DONT_KNOW;
		endif
		:return (Status);
	stop
	@enduml
  @testmethod			  - Module Testing \n
                            This function has to be tested for statement and branch coverage. \n
                            For detailed unit test description follow the caller graph to the test function \n
                            test_vdy_cofct.c -> TEST_vdyGetCurveDir_001(), TEST_vdyGetCurveDir_002(), TEST_vdyGetCurveDir_003(), TEST_vdyGetCurveDir_004()
  @traceability			  - NA
**************************************************************************** */
extern VDYCrvDirStatus_t vdyGetCurveDir(const VDYOutCurve_t *Course, fCurve_t ThrdCurve, fQuality_t MinQuality);


/* **********************************************************************
  @fn                     vdyInitCurve */ /*!
  @brief                  Initialization of curvature data

  @description            see brief description

  @param[in]              Course
  @param[out]             -
  @return                 void

  @pre                    -
  @post                   -
  @InOutCorrelation
  - Initialization of curvature data
  
	@startuml
	start
		:Course->Curve     = VDY_ZERO_F;
		:Course->Gradient  = VDY_ZERO_F;
		:Course->Variance  = VDY_ZERO_F;
		:return (void);
	stop
	@enduml
	- VDY_ZERO_F = 0.0F
  @testmethod			  - Module Testing \n
                            This function has to be tested for statement and branch coverage. \n
                            For detailed unit test description follow the caller graph to the test function \n
                            test_vdy_cofct.c -> TEST_vdyInitCurve_001()
  @traceability			  - NA
**************************************************************************** */
extern void vdyInitCurve(VDYOutCurve_t *Course);


 /* ***********************************************************************
  @fn                     vdyCalcDistStblGrad */ /*!
  @brief                  Calculation of driven distance with stable gradient

  @description            Filters the value and adds driven distance to distance
                          if gradient is stable (calculated gradient is smaller
                          than given max gradient), otherwise the driven distance
                          is reset to 0m.
                          The driven distance is limited to 150m.

  @param[in]              GradMax    Maximum abolute value for stable range
  @param[in]              Grad       Absolut value of current gradient
  @param[in]              VehSpeed     Old driven distance with steady gradient
  @param[in,out]          GradAbsOld    Absolut value of last cycle gradient
  @param[out]             DeltaDist     Distance with steady gradient 
  @return                 void

  @pre                    -
  @post                   -
  @InOutCorrelation
  - Calculate of driven distance with stable gradient
  
		@startuml
		start
			:Calculate Cycle Time \n Cycle Time = vdyGetCycleTime();
			if ( Peak filtering of absolute gradient value \n CML_f_Abs(Grad) > *GradAbsOld) then (YES)
				:*GradAbsOld = CML_f_Abs(Grad);
			else (NO)
				:*GradAbsOld = VDY_IIR_FILTER(CML_f_Abs(Grad), *GradAbsOld, PeakFilterTime_c, CycleTime);
			endif
			stop
			@enduml
				
  @testmethod			  - Module Testing \n
                            This function has to be tested for statement and branch coverage. \n
                            For detailed unit test description follow the caller graph to the test function \n
                            test_vdy_cofct.c -> TEST_vdyCalcDistStblGrad_001(), TEST_vdyCalcDistStblGrad_002(), TEST_vdyCalcDistStblGrad_003(), TEST_vdyCalcDistStblGrad_004()
  @traceability			  - 
  - L4
    - doors://rbgs854a:40000/?version=2&prodID=0&urn=urn:telelogic::1-503e822e5ec3651e-O-1033-00026448
**************************************************************************** */
extern void vdyCalcDistStblGrad(fGradient_t GradMax, fGradient_t Grad, fGradient_t *GradAbsOld, fDistance_t *DeltaDist, fVelocity_t VehSpeed);


/* ***********************************************************************
  @fn                     vdyCalcCycleDistance */ /*!
  @brief                  Calculate the driven distance during cycle

  @description            Distance calculation via zero order approximation

  @param[in]              VehSpeed	Vehicle Speed
  @param[out]             -
  @return                 Driven distance

  @pre                    -
  @post                   -
  @InOutCorrelation
  - Calculate the driven distance during cycle
  

		@startuml
		start
			:Cycle Time = vdyGetCycleTime();
			:Driven Distance [m] = Cycle Time * Vehicle Speed;
			:return (Driven Distance [m]);
		stop
		@enduml

  @testmethod			  - Module Testing \n
                            This function has to be tested for statement and branch coverage. \n
                            For detailed unit test description follow the caller graph to the test function \n
                            test_vdy_cofct.c -> TEST_vdyCalcCycleDistance_001()
  @traceability			  - NA
**************************************************************************** */
extern fDistance_t vdyCalcCycleDistance(fVelocity_t VehSpeed);


/* ***********************************************************************
  @fn                     vdyFilterCycleTime */ /*!
  @brief                  First order IIR lowpass filter.

  @description            Internal filter coefficients are calculated with
                          respect to cycle time

  @param[in]              New :       new input value
  @param[in]              Old :       old output value
  @param[in]              TimeConst : Filter time constant in seconds
  @param[out]             -
  @return                 filter output value

  @pre                    -
  @post                   -
  @InOutCorrelation
  - First order IIR lowpass filter.
  
	@startuml
	start
		:Get Cycle Time \n CycleTime = vdyGetCycleTime();
		:Value = VDY_IIR_FILTER(New, Old, TimeConst, CycleTime);
		:return (Value);

	stop
	@enduml

  @testmethod			  - Module Testing \n
                            This function has to be tested for statement and branch coverage. \n
                            For detailed unit test description follow the caller graph to the test function \n
                            test_vdy_cofct.c -> TEST_vdyFilterCycleTime_001()
  @traceability			  - 
  - L4
    - doors://rbgs854a:40000/?version=2&prodID=0&urn=urn:telelogic::1-503e822e5ec3651e-O-403-00026448
**************************************************************************** */
extern float32 vdyFilterCycleTime(float32 New, float32 Old, fTime_t TimeConst);


/* ***********************************************************************
  @fn                     vdyFormatCurve */ /*!
  @brief                  Format the curvature

  @description            Limit the curvature within mininum and maximum value

  @param[in,out]          Curve Curvature
  @return                 void

  @pre                    -
  @post                   -
  @InOutCorrelation
  - Format the curvature
  
	@startuml
	start
		if (CML_f_Abs(Curve) < (VDY_ONE_F / VDY_MAX_RADIUS)) then (YES)
			:Curve = VDY_ZERO_F;
		else if (Curve > (VDY_ONE_F / VDY_MIN_RADIUS)) then (YES)
			:Curve = VDY_ONE_F / VDY_MIN_RADIUS;
		else if (Curve < (-(VDY_ONE_F) / VDY_MIN_RADIUS)) then (YES)
			:Curve = -(VDY_ONE_F) / VDY_MIN_RADIUS;
		endif
		:return (void);
	stop
	@enduml
  @testmethod			  - Module Testing \n
                            This function has to be tested for statement and branch coverage. \n
                            For detailed unit test description follow the caller graph to the test function \n
                            test_vdy_cofct.c -> TEST_vdyFormatCurve_001(), TEST_vdyFormatCurve_002(), TEST_vdyFormatCurve_003(), TEST_vdyFormatCurve_004()
  @traceability			  - NA
**************************************************************************** */
extern void vdyFormatCurve(fCurve_t *Curve);


/* ***********************************************************************
  @fn                     vdyCurveToRadius */ /*!
  @brief                  Conversion from curvature to radius

  @description            Calculates radius out of curvature
                          Very small curvature values are set to a radius of 0
                          The radius is also limited to a min radius for small
                          curve values (a car has a minimum turning radius)

  @param[in]              Curve
  @param[out]             Radius
  @return                 void

  @pre                    none
  @post                   none
  @InOutCorrelation
  - Conversion from curvature to radius
  
	@startuml
	start
		if ( CML_f_Abs(Curve) < (VDY_ONE_F/VDY_MAX_RADIUS)) then (YES)
			:Absolute curvature below minimum zero threshold value \n Radius = VDY_ZERO_F;
		else if (Curve > (VDY_ONE_F/VDY_MIN_RADIUS)) then (YES)
			:Curvature above pos. maximum threshold value \n Radius = VDY_MIN_RADIUS;
		else if ( Curve < (-(VDY_ONE_F)/VDY_MIN_RADIUS) ) then (YES)
			:Curvature below neg. maximum threshold value \n Radius = -VDY_MIN_RADIUS;
		else (NO)
			:Radius = VDY_ONE_F / Curve;
		endif
		:return (void);
	stop
	@enduml
  @testmethod			  - Module Testing \n
                            This function has to be tested for statement and branch coverage. \n
                            For detailed unit test description follow the caller graph to the test function \n
                            test_vdy_cofct.c -> TEST_vdyCurveToRadius_001(), TEST_vdyCurveToRadius_002(), TEST_vdyCurveToRadius_003(), TEST_vdyCurveToRadius_004()
  @traceability			  - NA
**************************************************************************** */
extern void vdyCurveToRadius(fCurve_t Curve, fRadius_t *Radius);


/*****************************************************************************
  @fn             vdyLinInterp1 */ /*!
  @brief          Linear interpolation function

  @description    Calculation of y(x) in a param table with interpolation

  @param[in]      xn table	pointers to param table [x1,x2,..], [y1,y2,..]
  @param[in]      yn table	pointers to param table [x1,x2,..], [y1,y2,..]
  @param[in]      num number of points [x,y] in param table
  @param[in]      xi value
  @return         y(x)

  @pre            -
  @post           -
  @InOutCorrelation
  - Linear interpolation function
  
	@startuml
	start
		:ni = VDY_ONE_U;
		while ( (ni < num) && (xi > *xn) )
			:xn++;
			:yn++;
			:ni++;
		endwhile
		if (ni > VDY_ONE_U) then (YES)
			:take current table position and previous table position for interpolation \n x1 = *(xn - 1UL) \n y1 = *(yn - 1UL) \n x2 = *(xn) \n y2 = *(yn);
			if (x1 < x2) then (YES)
				if ( xi < x2 ) then (YES)
				:interpolation \n yi = ((( xi - x1) * (y2 - y1)) / (x2 - x1)) + y1;
				else (NO)
				:if x > current (last) table position use last y value from table \n yi = y2;
				endif
			else (NO)
				:yi = y1;
			endif
		else (NO)
			:if x was smaller than than first value in table --> take first y value from table \n yi = *(yn);
		endif
		:return (yi);
	stop
	@enduml
  @testmethod			  - Module Testing \n
                            This function has to be tested for statement and branch coverage. \n
                            For detailed unit test description follow the caller graph to the test function \n
                            test_vdy_cofct.c -> TEST_vdyLinInterp1_001(), TEST_vdyLinInterp1_002(), TEST_vdyLinInterp1_003(), TEST_vdyLinInterp1_004(), TEST_vdyLinInterp1_005()
  @traceability			  - NA
*****************************************************************************/
extern float32 vdyLinInterp1(const float32 *xn, const float32 *yn, const uint32 num, float32 xi);


/* ***********************************************************************
  @fn                vdyFilterOffset */ /*!
  @brief             First order IIR lowpass filter for offset estimation

  @description       IIR-Filter discretized PT1 with zero-order hold

  @param[in]         newin :   new measured input value
  @param[in]         oldflt :  last filter output value
  @param[in]         fconst :  filter constant with respect to increment
                              time domain     : time const / time step
                              distance domain : dist const / dist step 
  @param[out]        -
  @return            filtered output value

  @pre               -
  @post              -
  @InOutCorrelation
  - IIR-Filter discretized PT1 with zero-order hold
  
	@startuml
	start
		:coeff = VDY_ONE_F - VDY_EXP(-fconst);
		:fltVal = oldflt + (coeff * (newin - oldflt));
		:return (fltVal);
	stop
	@enduml
  @testmethod			  - Module Testing \n
                            This function has to be tested for statement and branch coverage. \n
                            For detailed unit test description follow the caller graph to the test function \n
                            test_vdy_cofct.c -> TEST_vdyFilterOffset_001()
  @traceability			  - 
  - L4
    - doors://rbgs854a:40000/?version=2&prodID=0&urn=urn:telelogic::1-503e822e5ec3651e-O-403-00026448
**************************************************************************** */
extern float32 vdyFilterOffset(float32 newin, float32 oldflt, float32 fconst);


/* ***********************************************************************
  @fn                     vdyDifferentiateCycleTime */ /*!
  @brief                  IIR lowpass differentiator (DT1)

  @description            Internal filter coefficients are calculated with
                          respect to cycle time

  @param[in]              newIn :     current input value
  @param[in]              oldIn :     previous input value
  @param[in]              oldOut :    previous output value
  @param[in]              TimeConst: Filter time constant in seconds
  @param[out]             -
  @return                 filter output value

  @pre                    -
  @post                   -
  @InOutCorrelation
  - IIR lowpass differentiator (DT1)
  
	@startuml
	start
		:Get cycle time \n CycleTime = vdyGetCycleTime();
		:Calculate new filter output \n Value = CycleTime + TimeConst;
		if (CML_f_IsNonZero(Value) && (Value > VDY_ZERO_F)) then (YES)
			:Value = (VDY_ONE_F / Value) * ( (newIn - oldIn) + (TimeConst * oldOut));
		else (NO)
			:Value = oldOut; 
		endif
		:return (Value);
	stop
	@enduml



  @testmethod			  - Module Testing \n
                            This function has to be tested for statement and branch coverage. \n
                            For detailed unit test description follow the caller graph to the test function \n
                            test_vdy_cofct.c -> TEST_vdyDifferentiateCycleTime_001(), TEST_vdyDifferentiateCycleTime_002(), TEST_vdyDifferentiateCycleTime_003()
  @traceability			  - NA
**************************************************************************** */
extern float32 vdyDifferentiateCycleTime(float32 newIn, float32 oldIn, float32 oldOut, fTime_t TimeConst);


/*! Prototpyes of steering wheel angle */

/* **********************************************************************
  @fn                     vdySwaIsValid */ /*!
  @brief           checks the quality of the lateral acceleration offset

  @description     Returns TRUE if quality of steering wheel offset
                   is sufficient

  @return          boolean

  @glob_in         SWA_GET_SEN_DATA : Steering wheel angle processing database
  @glob_out        None

  @c_switch_part   None
  @c_switch_full   None
  @InOutCorrelation
	- Return the validity of the Swa sensor data
  
	@startuml
	start
		:VDYSwaSenData_t *StrgData = SWA_GET_SEN_DATA;
		:return (StrgData->Valid);
	stop
	@enduml
  @testmethod			  - Module Testing \n
                            This function has to be tested for statement and branch coverage. \n
                            For detailed unit test description follow the caller graph to the test function \n
                            test_vdy_ay_swa.c -> TEST_vdySwaIsValid_001()
  @traceability			  - NA
**************************************************************************** */
extern boolean              vdySwaIsValid(void);
extern const VDYOutCurve_t *VDYSwaGetCurveADTR(void);
extern const VDYOutCurve_t *VDYSwaGetCurve(void);
extern const VDYOutCurve_t *VDYSwaGetCurveLog(void);

/* *************************************************************************
  @fn             vdyCalcFastSwaOffset */ /*!
  @brief           Calculates a first SWA offset for new ECUs without learn values

  @description     Calculation of a SWA offset based on the averaging of steering angle

  @return          void

  @param[in]       p_InputData : Input of the Vehicle Dynamics Module 

  @c_switch_part   None
  @c_switch_full   None

  @pre             None
  @post            No changes
  @InOutCorrelation
					  - get the steering angle offset data
					  - if new estimation cycle was started, delete short term data
					  - get signals
					  - get parameters
					  - get wheel information
					  - filter wheel speed differences
					  - get absolute values for test locally as the signed values are needed in the filter in the next cycle
					  - only calculate offset if all conditions are met (input signals showing static situation, wheels show straight driving, steering wheel input signal is valid)
						- calculate the steering angle offset
						- collect offset data
						- are necessary samples collected?
							- calculate long term data
							- If limit long term data to prevent overflow
								- reduce long term data 
							- If save offset as first calculated offset - only one time if state signals no offset available yet
								- use offset and store data in nonvolatile memory
  
						@startuml
								start
										:get the steering angle offset data;
										:get signals;
										:get wheel information;
										:filter wheel speed differences;
										:get absolute values for test locally as the signed values are needed in the filter in the next cycle;
										:First time required sample should be 250 and then 500;
										if(p_SwaData->FastSwaOffset.Vol == 0U) then (YES)
												:u_samples = 250U;
										else (NO)
												:u_samples = 500U;
										endif
										if (p_SwaData->FastSwaOffset.u_Number == 500U) then (YES)
												:p_SwaData->FastSwaOffset.f_Sum    = 0.0f
												 p_SwaData->FastSwaOffset.u_Number = 0U;
										endif
										:only calculate offset if all conditions are met;
										if (   (f_LongAccel < 0.5f) \n
												&& (f_LatAccel < 1.8f) \n                                                                           
												&& (VDY_GET_IO_STATE(VDY_SIN_POS_SWA, p_InputData->Signals.State) == (VDYIoStateTypes_t)VDY_IO_STATE_VALID)   \n
												&& (f_SteeringAngle < (DEG2RAD(30.F)) ) \n
												&& (f_EgoVel > 5.0f)     \n
												&& (f_WhlVelFrDiffFiltAbs < 0.3f)  && (f_WhlVelReDiffFiltAbs < 0.3f)        \n                
												&& (u_BankRoad == (uint8)0)  \n                                                                                    
												&& (VDY_GET_IO_STATE(VDY_SIN_POS_YWR, p_InputData->Signals.State) == (VDYIoStateTypes_t)VDY_IO_STATE_VALID) \n
												&& (f_yaw_gye < (DEG2RAD(0.1146F)) ) ) then (YES)
														:collect offset data
															p_SwaData->FastSwaOffset.f_Sum += p_InputData->Signals.StWheelAngle
															p_SwaData->FastSwaOffset.u_Number += 1;				
														if (p_SwaData->FastSwaOffset.u_Number == u_samples) then (YES)
																:p_SwaData->FastSwaOffset.SumVol       = p_SwaData->FastSwaOffset.SumVol + p_SwaData->FastSwaOffset.f_Sum
																p_SwaData->FastSwaOffset.Vol          = p_SwaData->FastSwaOffset.Vol + p_SwaData->FastSwaOffset.u_Number
																p_SwaData->FastSwaOffset.f_Offset     = p_SwaData->FastSwaOffset.SumVol / (float32)p_SwaData->FastSwaOffset.Vol;
														endif
										endif
										if ((p_SwaData->Offset.OffsState < SWA_STATE_2) && \n
										(((p_SwaData->FastSwaOffset.Vol == SWA_FAST_OFFS_SAMP_1) ||  \n
												(p_SwaData->FastSwaOffset.Vol == SWA_FAST_OFFS_SAMP_2) ||  \n
												(p_SwaData->FastSwaOffset.Vol == SWA_FAST_OFFS_SAMP_3) ||  \n
												(p_SwaData->FastSwaOffset.Vol == SWA_FAST_OFFS_SAMP_4) ||  \n
												(p_SwaData->FastSwaOffset.Vol == SWA_FAST_OFFS_SAMP_5) ||  \n
												(p_SwaData->FastSwaOffset.Vol == SWA_FAST_OFFS_SAMP_6) ||  \n
												(p_SwaData->FastSwaOffset.Vol == SWA_FAST_OFFS_SAMP_7) ||  \n
												(p_SwaData->FastSwaOffset.Vol == SWA_FAST_OFFS_SAMP_8) ||  \n
												(p_SwaData->FastSwaOffset.Vol == SWA_FAST_OFFS_SAMP_9)) && \n
												(p_SwaData->FastSwaOffset.u_Number == u_samples)) ) then (YES)
														:p_SwaData->Offset.Est.Offs = p_SwaData->FastSwaOffset.f_Offset
														 p_SwaData->Offset.Est.Conf = 0.2f;
														 if(p_SwaData->Offset.OffsState > 0) then (YES)
																:p_SwaData->FastSwaOffset.Fast_Offset_State = 1U;
														endif
														:use offset and store data in nonvolatile memory;
										else (NO)
												:p_SwaData->FastSwaOffset.Fast_Offset_State = 0U;
										endif
										:Clean Vol and Sum by after 19750 samples;
										if(p_SwaData->FastSwaOffset.Vol > 19750) then (YES)
												:p_SwaData->FastSwaOffset.SumVol = 0.0f;
												:p_SwaData->FastSwaOffset.Vol    = 0U;
										endif
								stop
						@enduml
  @testmethod		- Module Testing \n
                            This function has to be tested for statement and branch coverage. \n
                            For detailed unit test description follow the caller graph to the test function \n
                            test_vdy_ay_swa.c ->	   \n
                            TEST_vdyCalcFastSwaOffset_001(),
                            TEST_vdyCalcFastSwaOffset_002(),
                            TEST_vdyCalcFastSwaOffset_003(),
                            TEST_vdyCalcFastSwaOffset_004(),
                            TEST_vdyCalcFastSwaOffset_005(),
                            TEST_vdyCalcFastSwaOffset_006(),
                            TEST_vdyCalcFastSwaOffset_007(),
                            TEST_vdyCalcFastSwaOffset_008(),
                            TEST_vdyCalcFastSwaOffset_009(),
                            TEST_vdyCalcFastSwaOffset_010(),
                            TEST_vdyCalcFastSwaOffset_011(),
                            TEST_vdyCalcFastSwaOffset_012(),
                            TEST_vdyCalcFastSwaOffset_013(),
                            TEST_vdyCalcFastSwaOffset_014(),
                            TEST_vdyCalcFastSwaOffset_015(),
                            TEST_vdyCalcFastSwaOffset_016(),
                            TEST_vdyCalcFastSwaOffset_017(),
                            TEST_vdyCalcFastSwaOffset_018(),
                            TEST_vdyCalcFastSwaOffset_019(),
                            TEST_vdyCalcFastSwaOffset_020(),
                            TEST_vdyCalcFastSwaOffset_021(),
                            TEST_vdyCalcFastSwaOffset_022()

  @traceability		
  - L3
    - doors://rbgs854a:40000/?version=2&prodID=0&view=000000b9&urn=urn:telelogic::1-503e822e5ec3651e-O-1826-000221c8
  - L4
    - doors://rbgs854a:40000/?version=2&prodID=0&urn=urn:telelogic::1-503e822e5ec3651e-O-612-00026448
    - doors://rbgs854a:40000/?version=2&prodID=0&urn=urn:telelogic::1-503e822e5ec3651e-O-1091-00026448

  @author         Frank Wolter
**************************************************************************** */
extern void vdyCalcFastSwaOffset(const VDYInputData_t * p_InputData);

/*! Prototpyes of yaw rate sensor processing  */

/* **********************************************************************
  @fn               vdyYwrEstStandstillOffset */ /*!
  @brief           Estimate standstill offset

  @description     Estimate standstill offset

  @return          void

  @param[in]       YwRate : 
  @param[in]       valYwr : 
  @param[in,out]   *pStStOff : 

  @c_switch_part   CFG_VDY_TURNTABLE_DETECTION : Enables the Turn Table detection and limit max. delta 4deg/sec yaw rate offset compensation at one learning cycle
  @c_switch_full   None

  @pre             None
  @post            No changes
  @InOutCorrelation
					- Get cycle time
					- Initialize maximum quality to 0
					- Test if yaw rate offset is observable
						- Get inverse cycle time
						- Add Yaw rate offset to interval
						- Test if offset samples collection time has been elapsed
							- When Enough yaw rate offset samples (min 30) are available
								- Add delay interval to evaluation interval
								- Reset elapsed time since last offset adjust
								- If deviation of sampled data is too large, discard all data
								- Check if enough time has been elapsed for offset calibration
									- Calculate quality by means of used samples
								- If offset calibration last a long time fade memory data to preserve dynamic
							- Copy gathering inverval to delay interval and Initialize gathering interval
					- If Yaw rate offset is not observable 
						- Vehicle is not in stand still
							- Initialize gathering and delay interval because of possibly wrong sampled data during drive-off
						- Preserve evaluation interval for certain time to prevent initialization during stop and go driving situations. This reduces the time to complete the learning of offset value

  
						@startuml
							start
								if (yaw rate offset is observable) then (YES)
									:Get inverse cycle time;
									:Yaw rate offset is observable, start collecting the samples vdyStatIntervalAdd();
									if(SampleInterval_1 offset samples collection time has been elapsed) then (YES)
										:Add delay interval to evaluation interval;
										:Calculate mean and deveation on SampleInterval;
										:Reset elapsed time since last offset adjust;
										if(deviation of sampled data is too large, discard all data) then (YES)
											:Initialize all intervals to zero;
										endif
										if(Check if enough time has been elapsed for offset calibration, that is minimum 30 samples) then (YES)
											if(if it the delta offset difference is under the MAX limit that is 4degree) then (YES)
												:Take over new zero point offset, that is mean value;
											else (No)
												if(Mean > PrevYawRateOffset) then (YES)
													:take delta offset as previous offset + 4deg/sec;
												else (No)
													:take delta offset as previous offset -  4deg/sec;
												endif
											endif
											:Take over new zero point offset;
											:Calculate quality by means of used samples that is MaxQuality;
										endif
										if (offset calibration last a long time) then (YES)
											:fade memory data to preserve dynamic by factor 0.9f;
										endif
										:Init SampleInterval_2 with 0;
										:Copy gathering interval to delay interval vdyStatIntervalMerge(&pStStOff->SampleInterval_2,  &pStStOff->SampleInterval_1 );
										:Initialize gathering interval to 0, SampleInterval_1;
									endif
								else (No)
									if(Yaw rate offset is not observable) then (YES)
										:Vehicle doesn't stand still;
										:Initialize gathering and delay interval because of possibly wrong sampled data during drive-off;
									endif
									if(pStStOff->SampleInterval.Volume > 0) then (YES)
										:Preserve evaluation interval for certain time to prevent initialization during stop and go driving situations. This reduces the time to complete the learning of offset value AdjustTime += CycleTime;
										if(pStStOff->AdjustTime >= 60) then (YES)
											:Initialize the SampleInterval;
											:reset AdjustTime;
										endif
									endif
								endif
							stop
						@enduml

  @testmethod			- Module Testing \n
                            This function has to be tested for statement and branch coverage. \n
                            For detailed unit test description follow the caller graph to the test function \n
                            test_vdy_ywr.c ->  \n
                            TEST_vdyYwrEstStandstillOffset_001(),
                            TEST_vdyYwrEstStandstillOffset_002(),
                            TEST_vdyYwrEstStandstillOffset_003(),
                            TEST_vdyYwrEstStandstillOffset_004(),
                            TEST_vdyYwrEstStandstillOffset_005(),
                            TEST_vdyYwrEstStandstillOffset_006(),
                            TEST_vdyYwrEstStandstillOffset_007(),
                            TEST_vdyYwrEstStandstillOffset_008(),
                            TEST_vdyYwrEstStandstillOffset_009(),
                            TEST_vdyYwrEstStandstillOffset_010()

  @traceability			
  - L3
    - doors://RBGS854A:40000/?version=2&prodID=0&view=000000b9&urn=urn:telelogic::1-503e822e5ec3651e-O-1431-000221c8
  - L4
    - doors://rbgs854a:40000/?version=2&prodID=0&urn=urn:telelogic::1-503e822e5ec3651e-O-888-00026448
    - doors://rbgs854a:40000/?version=2&prodID=0&urn=urn:telelogic::1-503e822e5ec3651e-O-889-00026448
    - doors://rbgs854a:40000/?version=2&prodID=0&urn=urn:telelogic::1-503e822e5ec3651e-O-890-00026448
    - doors://rbgs854a:40000/?version=2&prodID=0&urn=urn:telelogic::1-503e822e5ec3651e-O-881-00026448
    - doors://rbgs854a:40000/?version=2&prodID=0&urn=urn:telelogic::1-503e822e5ec3651e-O-885-00026448
**************************************************************************** */
extern void vdyYwrEstStandstillOffset(fYawRate_t YwRate, boolean valYwr, VDYYwrStandStillOffs_t *pStStOff);


/* **********************************************************************
  @fn                     vdyYwrInitStandStillOffset */ /*!
  @brief           Initializes Dyn. Offset

  @description     Initializes Dyn. Offset

  @return          void

  @param[in,out]   *StandStOffs : Ywr Standstill Offset Data

  @c_switch_part   None 
  @c_switch_full   None 

  @pre             None
  @post            No changes
  @InOutCorrelation
					- Initializes Dyn. Offset
  
					@startuml
						start
							:vdyStatIntervalInit(&StandStOffs->SampleInterval_1);
							:vdyStatIntervalInit(&StandStOffs->SampleInterval_2);
							:vdyStatIntervalInit(&StandStOffs->SampleInterval);
							:StandStOffs->AdjustTime          = 0.0f;
							:StandStOffs->MaxQuality          = 0.0f;
							:StandStOffs->YawRateOffset       = 0.0f;
							:StandStOffs->StandstillOK        = FALSE;
						stop
					@enduml
  @testmethod			  - NA
  @traceability			  - NA
**************************************************************************** */
extern void vdyYwrInitStandStillOffset(VDYYwrStandStillOffs_t *StandStOffs);


/* **********************************************************************
  @fn                     vdyYwrIsValid */ /*!
  @brief           Provides correctness of the yaw rate

  @description     Provides correctness of the yaw rate

  @return          boolean

  @glob_in         None 
  @glob_out        Valid : Validity bit for yaw rate

  @c_switch_part   None 
  @c_switch_full   None 

  @pre             None
  @post            No changes
  @InOutCorrelation	
					 - Return the validity of yaw rate data
  
					 @startuml
						start
							:return (YWR_GET_DATA->Valid);
						stop
					@enduml
  @testmethod			  - Module Testing \n
                            This function has to be tested for statement and branch coverage. \n
                            For detailed unit test description follow the caller graph to the test function \n
                            test_vdy_ywr.c -> TEST_vdyYwrIsValid_001()
  @traceability			  - NA

  @author                 M.Sachs
**************************************************************************** */
extern boolean vdyYwrIsValid(void);


/* **********************************************************************
  @fn                     vdyYwrGetDynReduced         */ /*!
  @brief           Return the current possible reduction

  @description     Return the current possible reduction

  @return          float32

  @glob_in         YWR_GET_OFFS : Zero point offset
  @glob_out        None 

  @c_switch_part   None 
  @c_switch_full   CFG_VDY_YW_DYN_AVG : Enable dynamic gyro offst compensation

  @pre             None
  @post            No changes
  @InOutCorrelation
					 -  Return the current possible reduction
  
  @testmethod			  - Module Testing \n
                            This function has to be tested for statement and branch coverage. \n
                            For detailed unit test description follow the caller graph to the test function \n
                            test_vdy_ywr.c -> NA
  @traceability			  - NA
**************************************************************************** */
extern float32 vdyYwrGetDynReduced(void);

/* **********************************************************************
  @fn               vdyYwrGetYawRate */ /*!

  @brief           Get offset compensated yaw rate

  @description     Get offset compensated yaw rate

  @return          void

  @param[in,out]   *yawrate : Yaw Rate Data

  @glob_in         YWR_GET_OFFS : Zero point offset
  @glob_in         YWR_GET_DATA : Yaw rate sensor data
  @glob_out        None 

  @c_switch_part   None 
  @c_switch_full   None 

  @pre             None
  @post            No changes
  @InOutCorrelation	
					- Calculate yaw rate offset corrected (yawrate->YawRate = pSen->YawRate - pOffs->YawRateOffset)
  
					@startuml
						start
							:VDYYwrOffsData_t *pOffs = YWR_GET_OFFS;
							:VDYYwrSenData_t  *pSen  = YWR_GET_DATA;
							:yawrate->YawRate = pSen->YawRate - pOffs->YawRateOffset;
							:yawrate->Variance = VDY_ZERO_F;
                            :return;
						stop
					@enduml
  @testmethod			  - Module Testing \n
                            This function has to be tested for statement and branch coverage. \n
                            For detailed unit test description follow the caller graph to the test function \n
                            test_vdy_ywr.c -> TEST_vdyYwrGetYawRate_001()
  @traceability			  - NA
**************************************************************************** */
extern void vdyYwrGetYawRate(YawRateVehDyn_t *yawrate);

/*! Prototpyes of wheel speed sensor processing  */

/* **********************************************************************
  @fn                     vdyWhsIsValid */ /*!
  @brief           Returns validity of wheel data

  @description     Returns validity of wheel data

  @return          boolean 

  @glob_in         WHS_GET_DATA : Wheel speed sensor data
  @glob_out        None 

  @c_switch_part   None 
  @c_switch_full   None 

  @pre             None 
  @post            No changes 
  @InOutCorrelation
					- Return the validity of the wheen data
  
	@startuml
	start
		:VDYWhsSenData_t *WspData = WHS_GET_DATA;
		:return (WspData->WspFornt.WspValid);
	stop
	@enduml
  @testmethod			  - Module Testing \n
                            This function has to be tested for statement and branch coverage. \n
                            For detailed unit test description follow the caller graph to the test function \n
                            test_vdy_whs.c -> TEST_vdyWhsIsValid_001()
  @traceability			  - NA

  @author                 T.Stephan
**************************************************************************** */
extern boolean vdyWhsIsValid(void);


/* **********************************************************************
  @fn                     vdyWhsGetWspAquaplaning */ /*!
  @brief           Access to aquaplaning BOOL from Wsp 

  @description     Access to aquaplaning BOOL from Wsp

  @return          boolean 

  @glob_in         WHS_GET_DATA : Wheel speed sensor data
  @glob_out        None 

  @c_switch_part   None 
  @c_switch_full   None 

  @pre             None
  @post            No changes
  @InOutCorrelation
					- retun Hydroplaning status
  
	@startuml
	start
		:VDYWhsSenData_t *WspData = WHS_GET_DATA;
		:return (WspData->Aquaplaning);
	stop
	@enduml
  @testmethod			  - Module Testing \n
                            This function has to be tested for statement and branch coverage. \n
                            For detailed unit test description follow the caller graph to the test function \n
                            test_vdy_whs.c -> TEST_vdyWhsGetWspAquaplaning_001()
  @traceability			  - NA
**************************************************************************** */
extern boolean vdyWhsGetWspAquaplaning(void);


/* **********************************************************************
  @fn                     vdySwaCheckOffsetGoodEnough */ /*!
  @brief           checks the quality of the steering wheel offset

  @description     Returns TRUE if quality of steering wheel offset
                   is sufficient

  @return          boolean

  @glob_in         
			  - SWA_GET_SEN_DATA : Sensor signal processing of Steering wheel angle       
			  - SWA_GET_OFF_DATA : Offset estimation of Steering wheel angle
  @glob_out        None

  @c_switch_part   None
  @c_switch_full   CFG_VDY_YW_DYN_AVG : Enable dynamic gyro offst compensation

  @pre             None
  @post            No changes

  @InOutCorrelation
					- CFG_VDY_YW_DYN_AVG : Enable dynamic gyro offst compensation
  
  @testmethod			  - Module Testing \n
                            This function has to be tested for statement and branch coverage. \n
                            For detailed unit test description follow the caller graph to the test function \n
                            test_vdy_whs.c -> \n
                            TEST_vdySwaCheckOffsetGoodEnough_001(),
                            TEST_vdySwaCheckOffsetGoodEnough_002(),
                            TEST_vdySwaCheckOffsetGoodEnough_003(),
                            TEST_vdySwaCheckOffsetGoodEnough_004()
  @traceability			  - NA
**************************************************************************** */
extern boolean vdySwaCheckOffsetGoodEnough(void);


/*! Prototpyes of lateral acceleration sensor processing  */

/// Prototpyes of curve estimation
extern fQuality_t VDYCrvGradQuality(void);

/// Prototpyes of curve estimation
extern const VDYOutCurve_t *VDYCrvGetStandard(void);

/// Prototpyes of curve estimation
extern const VDYOutCurve_t *VDYCrvGetExWsp(void);

/// Prototpyes of curve estimation
extern const VDYOutCurve_t *VDYCrvGetFast(void);

/// Prototpyes of velocity and acceleration estimation
extern fAccel_t  VDYVelAccGetLongAcc(void);

/// Prototypes for mat probabilty tool box
extern percentage_t VDY_MAT_PROB_BAYES2(percentage_t ProbabilityA, percentage_t ProbabilityB, const percentage_t CPT[VDY_FOUR]);

/// Prototypes for mat probabilty tool box
extern percentage_t VDY_MAT_PROB_BAYES3(percentage_t ProbabilityA, percentage_t ProbabilityB, percentage_t ProbabilityC, const percentage_t CPT[VDY_EIGHT]);

/// Prototypes for mat probabilty tool box
extern percentage_t VDY_MAT_PROB_BAYES4(percentage_t ProbabilityA, percentage_t ProbabilityB, percentage_t ProbabilityC, percentage_t ProbabilityD, const percentage_t CPT[VDY_SIXTEEN]);


/* **********************************************************************
  @fn                     vdySwaGetOffsData */ /*!
  @brief           Access to internal offset data

  @description     Allows accessing the steering wheel offset data
                   from outside of this module

  @return          const VDYSwaOffsData_t

  @c_switch_part   None
  @c_switch_full   None

  @pre             None
  @post            No changes
  @InOutCorrelation 
					- returns SWA offset data
  
	@startuml
	start
		:return (SWA_GET_OFF_DATA);
	stop
	@enduml
  @testmethod			  - Module Testing \n
                            This function has to be tested for statement and branch coverage. \n
                            For detailed unit test description follow the caller graph to the test function \n
                            test_vdy_ay_swa.c -> TEST_vdySwaGetOffsData_001()
  @traceability			  - NA
**************************************************************************** */
extern const VDYSwaOffsData_t *vdySwaGetOffsData(void);


/* **********************************************************************
  @fn                     vdyYwrGetOffsData */ /*!
  @brief           Access to Yaw Rate offset data

  @description     Access to Yaw Rate offset data

  @return          const VDYYwrOffsData_t

  @glob_in         None 
  @glob_out        YWR_GET_OFFS : Zero point offset

  @c_switch_part   None
  @c_switch_full   None

  @pre             None
  @post            No changes
  @InOutCorrelation
					 - return yaw rate offset data
  
					 @startuml
						start
							:return YWR_GET_OFFS;
						stop
					@enduml
  @testmethod			  - Module Testing \n
                            This function has to be tested for statement and branch coverage. \n
                            For detailed unit test description follow the caller graph to the test function \n
                            test_vdy_ywr.c -> TEST_vdyYwrGetOffsData_001()
  @traceability			  - NA
**************************************************************************** */
extern const VDYYwrOffsData_t *vdyYwrGetOffsData(void);


/* **********************************************************************
  @fn                     vdyWhsGetOffsData */ /*!
  @brief           Access to wheel speed offset data

  @description     Provides access to module internal data by
                   providing a pointer to that data

  @return          const VDYWhsOffsData_t

  @glob_in         None 
  @glob_out        WHS_GET_OFFS : Wheel velocity offset data

  @c_switch_part   None 
  @c_switch_full   None 

  @pre             None
  @post            No changes
  @InOutCorrelation
					- returns VDY Wheel speeds global sensor offset data
  
	@startuml
	start
		:return (WHS_GET_OFFS);
	stop
	@enduml
  @testmethod			  - NA
  @traceability			  - Module Testing \n
                            This function has to be tested for statement and branch coverage. \n
                            For detailed unit test description follow the caller graph to the test function \n
                            test_vdy_whs.c -> TEST_vdyWhsGetOffsData_001()

  @author                 M.Sachs
**************************************************************************** */
extern const VDYWhsOffsData_t *vdyWhsGetOffsData(void);


/* **********************************************************************
  @fn                     vdyWhsOffset */ /*!
  @brief           Return the offset data used by the autocode

  @description     Return the offset data used by the autocode

  @return          vdy_whs_offset_t

  @glob_in         WHS_GET_OFFS : Wheel velocity offset data
  @glob_out        None 

  @c_switch_part   None 
  @c_switch_full   None 

  @pre             None
  @post            No changes
  @InOutCorrelation
					- Return the offset data used by the autocode
  

	@startuml
	start
		:const VDYWhsOffsData_t *pWhsOffsData = WHS_GET_OFFS; 
		:velocity range \n vdy_whs_offset.SpeedRange = pWhsOffsData->SpeedRange;
		:front axle offset ratio \n fRatio     = pWhsOffsData->OffsFront.Interval[pWhsOffsData->SpeedRange].Mean;
		:fDeviation = pWhsOffsData->OffsFront.Interval[pWhsOffsData->SpeedRange].Dev;

		if (CML_f_IsZero(fRatio)) then (YES)
			:vdy_whs_offset.offset_ratio_front      = VDY_ONE_F;
			:vdy_whs_offset.offset_ratio_front_dev  = VDY_ONE_F;
		else (NO)
			:vdy_whs_offset.offset_ratio_front      = fRatio;
			:vdy_whs_offset.offset_ratio_front_dev  = fDeviation;
		endif
		:rear axle offset ratio \n fRatio     = pWhsOffsData->OffsRear.Interval[pWhsOffsData->SpeedRange].Mean;
		:fDeviation = pWhsOffsData->OffsRear.Interval[pWhsOffsData->SpeedRange].Dev;
		if (CML_f_IsZero(fRatio)) then (YES)
			:vdy_whs_offset.offset_ratio_rear      = VDY_ONE_F;
			:vdy_whs_offset.offset_ratio_rear_dev  = VDY_ONE_F;
		else (NO)
			:vdy_whs_offset.offset_ratio_rear      = fRatio;
			:vdy_whs_offset.offset_ratio_rear_dev  = fDeviation;
		endif
		:return vdy_whs_offset;
	stop
	@enduml
  @testmethod		- Module Testing \n
                            This function has to be tested for statement and branch coverage. \n
                            For detailed unit test description follow the caller graph to the test function \n
                            test_vdy_whs.c -> TEST_vdyWhsOffset_001(), TEST_vdyWhsOffset_002()
	
  @traceability			  
	- NA
  @author                 Jochen Spruck
  **************************************************************************** */
extern vdy_whs_offset_t vdyWhsOffset(void);
extern const VDYAyOffsData_t *VDYAyGetOffsData(void);

/// Access to yaw rate offset data
extern const VDYYwrtOffsData_t *VDYYwrtGetOffsData(void);

/* ***********************************************************************
  @fn               VDYYwrtGetYawRateOffset */ /*!
  @brief            Hand over leanred offset and confidence value

  @description      Currently Not used in VDY

  @param[out]       *offset: pointer to offset table
  @param[out]       *conf: pointer to confidence table
  @return           void

  @pre              - NA
  @post             - NA
**************************************************************************** */
extern void VDYYwrtGetYawRateOffset(fYawRate_t *offset, fConfidence_t *conf);


/* Prototpyes of Monitoring */

/* **********************************************************************
  @fn               vdyInitMon */ /*!
  @brief           Init Monitoring

  @description     Sets output and internal values to 0
                   Sets fault states to unknown
                   Sets outputs to invalid

  @return          void

  @c_switch_part   
				  - CFG_VDY_ALIGNMENT_OFFSET_MONITOR : Do yaw rate offset monitoring with alignment offset estimation input
				  - CFG_VDY_MON_OUTPUT_PEAKS : Enables the output peak monitoring
				  - CFG_VDY_DIS_YWR_OFFSET_COMP : Disables zero point offset compensation of input yaw rate signal
				  - CFG_VDY_DEBOUNCE_OUTPUTS : Enables the max debouncing ouput counter
  @c_switch_full   None

  @pre             None
  @post            No changes
  @InOutCorrelation
					- Init alignment monitoring offsets
  
  @startuml
  start
	if ( (defined(CFG_VDY_ALIGNMENT_OFFSET_MONITOR)) && (CFG_VDY_ALIGNMENT_OFFSET_MONITOR) ) then (YES)
		:ACCThldTime = 0U \n CGThldTime  = 0U;
	endif
	if ( (defined(CFG_VDY_MON_OUTPUT_PEAKS)) && (CFG_VDY_MON_OUTPUT_PEAKS) ) then (YES)
		:Init the lastoutput signals to safe defaults setting CurveState to INVALID will deactivate peak monitoring in the very first cycle \n 
			LastOutputSignals.Curve = VDY_ZERO_F \n 
			LastOutputSignals.CurveState = (VDYErrState_t)VDY_IO_STATE_INVALID \n
			LastOutputSignals.OutputPeakError = VDY_STAT_INACTIVE \n
			LastOutputSignals.InputStwState = (VDYErrState_t)VDY_IO_STATE_VALID \n 
			LastOutputSignals.LimitCurve = FALSE;
	endif
	if ( (!defined(CFG_VDY_DIS_YWR_OFFSET_COMP)) || (!CFG_VDY_DIS_YWR_OFFSET_COMP) ) then (YES)
		:oldOffset = VDY_ZERO_F; \n StandStillOffset = VDY_ZERO_F;
	endif
	:u_velMonitorOFFCounter_ABS = VDY_ZERO_U;
	:u_velMonitorOFFCounter_TSC = VDY_ZERO_U;
	if ( (defined(CFG_VDY_DEBOUNCE_OUTPUTS)) && (CFG_VDY_DEBOUNCE_OUTPUTS) ) then (YES)
		:u_Debouce_VDY_VEH_VEL_NOT_AVAILABLE = VDY_ZERO_U;
	endif
  stop
  @enduml

  @testmethod			  - Module Testing \n
                            This function has to be tested for statement and branch coverage. \n
                            For detailed unit test description follow the caller graph to the test function \n
                            test_vdy_mon.c -> TEST_vdyInitMon_001()
  @traceability			  - NA
**************************************************************************** */
extern void vdyInitMon(void);


/* **********************************************************************
  @fn               vdyInitForCheckSignalPeakErrors */ /*!
  @brief           Monitors input signals for peak errors

  @description     All input signals are analysed and if any of them
                   are considered active the Input Signal Peak Error
                   is set to active.

  @return          void

  @param[in]       *pInput : Current Input Signal

  @c_switch_part   CFG_VDY_BMW_LONG_ACCEL_MODEL : Enables the new Long Accel estimation method only for BMW projects
  @c_switch_full   None

  @pre             None
  @post            No changes
  @InOutCorrelation 
					- Check for peak error for all signals 
  

	@startuml
	start
		:LastInputSignals.YawRate              = pInput->Signals.YawRate VDY_SET_IO_STATE(VDY_SIN_POS_YWR,VDY_GET_IO_STATE(VDY_SIN_POS_YWR, pInput->Signals.State),LastInputSignals.State);
		:LastInputSignals.StWheelAngle         = pInput->Signals.StWheelAngle \n VDY_SET_IO_STATE(VDY_SIN_POS_SWA,VDY_GET_IO_STATE(VDY_SIN_POS_SWA, pInput->Signals.State),LastInputSignals.State);
		:LastInputSignals.VehVelocityExt       = pInput->Signals.VehVelocityExt \n VDY_SET_IO_STATE(VDY_SIN_POS_VEHVEL_EXT,VDY_GET_IO_STATE(VDY_SIN_POS_VEHVEL_EXT, pInput->Signals.State),LastInputSignals.State);
		:LastInputSignals.LatAccel             = pInput->Signals.LatAccel \n VDY_SET_IO_STATE(VDY_SIN_POS_LATA,VDY_GET_IO_STATE(VDY_SIN_POS_LATA, pInput->Signals.State),LastInputSignals.State);
		:LastInputSignals.WhlVelFrLeft         = pInput->Signals.WhlVelFrLeft \n VDY_SET_IO_STATE(VDY_SIN_POS_WVEL_FL,VDY_GET_IO_STATE(VDY_SIN_POS_WVEL_FL, pInput->Signals.State),LastInputSignals.State);
		:LastInputSignals.WhlVelFrRight        = pInput->Signals.WhlVelFrRight \n VDY_SET_IO_STATE(VDY_SIN_POS_WVEL_FR,VDY_GET_IO_STATE(VDY_SIN_POS_WVEL_FR, pInput->Signals.State),LastInputSignals.State);
		:LastInputSignals.WhlVelReLeft         = pInput->Signals.WhlVelReLeft \n VDY_SET_IO_STATE(VDY_SIN_POS_WVEL_RL,VDY_GET_IO_STATE(VDY_SIN_POS_WVEL_RL, pInput->Signals.State),LastInputSignals.State);
		:LastInputSignals.WhlVelReRight        = pInput->Signals.WhlVelReRight \n VDY_SET_IO_STATE(VDY_SIN_POS_WVEL_RR,VDY_GET_IO_STATE(VDY_SIN_POS_WVEL_RR, pInput->Signals.State),LastInputSignals.State);
		:LastInputSignals.VehLongAccelExt      = pInput->Signals.VehLongAccelExt \n VDY_SET_IO_STATE(VDY_SIN_POS_VEHACL_EXT,VDY_GET_IO_STATE(VDY_SIN_POS_VEHACL_EXT, pInput->Signals.State),LastInputSignals.State);
		:LastInputSignals.RearWhlAngle         = pInput->Signals.RearWhlAngle \n VDY_SET_IO_STATE(VDY_SIN_POS_RSTA,VDY_GET_IO_STATE(VDY_SIN_POS_RSTA, pInput->Signals.State),LastInputSignals.State);
	stop
	@enduml
  @testmethod			  - Module Testing \n
                            This function has to be tested for statement and branch coverage. \n
                            For detailed unit test description follow the caller graph to the test function \n
                            test_vdy_mon.c -> TEST_vdyInitForCheckSignalPeakErrors_001()
  @traceability			  - NA
  @author           Witek Konarski
**************************************************************************** */
extern void vdyInitForCheckSignalPeakErrors(const VDYInputData_t *pInput);

/* **********************************************************************
  @fn               vdyMonitorInput */ /*!
  @brief           Monitor input signals and parameters

  @description     Calls signal and parameter monitoring functions
                   Calls signal peak monitoring function

  @return          void

  @param[in,out]   *input : Current Input Data
  @param[in,out]   *VDYErrors : VDY Error Signals

  @c_switch_part   None 
  @c_switch_full   None 

  @pre             None
  @post            No changes
  @InOutCorrelation -
  
	@startuml
	start
		:check for invalid parameter values or undefined parameters \n VDYMonitorInputParameters(input, VDYErrors);
		:check for invalid signal values \n VDYMonitorInputSignals(input, VDYErrors);
		:check for signal peaks between the actual and the last cycle \n VDYCheckForSignalPeakErrors(input, VDYErrors);
	stop
	@enduml
  @testmethod			  - Module Testing \n
                            This function has to be tested for statement and branch coverage. \n
                            For detailed unit test description follow the caller graph to the test function \n
                            test_vdy_mon.c -> TEST_vdyMonitorInput_001()
  @traceability
    - L3
        - doors://rbgs854a:40000/?version=2&prodID=0&view=0000012f&urn=urn:telelogic::1-503e822e5ec3651e-O-1398-000221c8
    - L4
        - doors://rbgs854a:40000/?version=2&prodID=0&urn=urn:telelogic::1-503e822e5ec3651e-O-637-00026448
**************************************************************************** */
extern void vdyMonitorInput(VDYInputData_t *input, VDYErrors_t *VDYErrors);


/* **********************************************************************
  @fn               vdyMonitorOutput */ /*!

  @brief           Check the vdy output data if values are in physical range

  @description     Calls the output peak and range check function
                   Calls the yawrate and velocity monitoring function

  @return          void

  @param[in]       *input : Current Input Signals
  @param[in]       *proPorts : Provide Ports
  @param[in]       *reqPorts : Request Ports

  @glob_in         None 
  @glob_out        u_velMonitorOFFCounter_ABS : Velocity Monitor when ABS is active
  @glob_out        u_velMonitorOFFCounter_TSC : Velocity Monitor when TSC is active

  @c_switch_part   CFG_VDY_MON_OUTPUT_PEAKS : Enables the output peak monitoring
  @c_switch_full   None 

  @pre             None
  @post            No changes
  @InOutCorrelation
					  - monitor of the yaw rate/lat accel and velocity/long accel output value range
					  - global monitoring of the velocity output, if the velocity is not sufficient for the other components
					  - When ABS / TSC is active set the Vehicle velocity not available error as Inactive for 20 sec
					  - global monitoring of the yaw rate output, if the yaw rate is not sufficient for the other components
  

	@startuml
	start
		:monitoring of the yaw rate/lat accel and velocity/long accel output value range \n VDYMonitorOutputRanges(proPorts);
		if ( ABS Control is off \n (((sint32)VDY_GET_IO_STATE(VEH_SIG_BRAKE_ABS, reqPorts->pVehicleInputSignals->Brake.State) == VDY_IO_STATE_VALID) && (reqPorts->pVehicleInputSignals->Brake.ABSCtrl == (boolean)FALSE))) then (YES)
			:u_velMonitorOFFCounter_ABS = 0U;
		endif
		if ( TCS Control is off \n (((sint32)VDY_GET_IO_STATE(VEH_SIG_BRAKE_TSC, reqPorts->pVehicleInputSignals->Brake.State) == VDY_IO_STATE_VALID) && (reqPorts->pVehicleInputSignals->Brake.TCSCtrl == (boolean)FALSE))) then (YES)
			:u_velMonitorOFFCounter_TSC = 0U;
		endif

		if ( When ABS / TSC is active set the Vehicle velocity not available error as Inactive for 20 sec  \n ((((sint32)VDY_GET_IO_STATE(VEH_SIG_BRAKE_ABS, reqPorts->pVehicleInputSignals->Brake.State) == VDY_IO_STATE_VALID) &&
      (reqPorts->pVehicleInputSignals->Brake.ABSCtrl == (boolean)TRUE) &&
      ((float32)u_velMonitorOFFCounter_ABS < OUTPUT_VEL_MON_DEACTIVATION_ABS)) ||

      (((sint32)VDY_GET_IO_STATE(VEH_SIG_BRAKE_TSC, reqPorts->pVehicleInputSignals->Brake.State) == VDY_IO_STATE_VALID) &&
       (reqPorts->pVehicleInputSignals->Brake.TCSCtrl == (boolean)TRUE) &&
       ((float32)u_velMonitorOFFCounter_TSC < OUTPUT_VEL_MON_DEACTIVATION_TSC))) ) then (YES)
		:proPorts->pVDYErrors->OutPutErrors.VDY_VEH_VEL_NOT_AVAILABLE = VDY_ERR_STATE_INACTIVE;  
			if(((sint32)VDY_GET_IO_STATE(VEH_SIG_BRAKE_ABS, reqPorts->pVehicleInputSignals->Brake.State) == VDY_IO_STATE_VALID) && (reqPorts->pVehicleInputSignals->Brake.ABSCtrl == (boolean)TRUE)) then (YES)
				:u_velMonitorOFFCounter_ABS ++;
			endif
			if(((sint32)VDY_GET_IO_STATE(VEH_SIG_BRAKE_TSC, reqPorts->pVehicleInputSignals->Brake.State) == VDY_IO_STATE_VALID) && (reqPorts->pVehicleInputSignals->Brake.TCSCtrl == (boolean)TRUE)) then (YES)
				:u_velMonitorOFFCounter_TSC ++;
			endif
		else
			:VDYMonitorVelocityOutput(proPorts, input);
		endif
		:VDYMonitorYawrateOutput(proPorts);
	stop
	@enduml
  @testmethod			  - Module Testing \n
                            This function has to be tested for statement and branch coverage. \n
                            For detailed unit test description follow the caller graph to the test function \n
                            test_vdy_mon.c -> \n 
                            TEST_vdyMonitorOutput_001(), \n
                            TEST_vdyMonitorOutput_002(), \n
                            TEST_vdyMonitorOutput_003(), \n
                            TEST_vdyMonitorOutput_004(), \n
                            TEST_vdyMonitorOutput_005(), \n
                            TEST_vdyMonitorOutput_006(), \n
                            TEST_vdyMonitorOutput_007(), \n
                            TEST_vdyMonitorOutput_008()
  @traceability			  - 
  - L3
  - doors://rbgs854a:40000/?version=2&prodID=0&view=0000012f&urn=urn:telelogic::1-503e822e5ec3651e-O-1433-000221c8
  - doors://rbgs854a:40000/?version=2&prodID=0&view=0000012f&urn=urn:telelogic::1-503e822e5ec3651e-O-1499-000221c8
  - L4
  - doors://rbgs854a:40000/?version=2&prodID=0&urn=urn:telelogic::1-503e822e5ec3651e-O-638-00026448
**************************************************************************** */
extern void vdyMonitorOutput(const VDYInputData_t *input, const proVdyPrtList_t *proPorts, const reqVdyPrtList_t *reqPorts);


/* **********************************************************************
  @fn               vdyMonitorDynYwrOffset */ /*!

  @brief           Monitor the dynamic yaw rate offset, check with the old dynamic offset

  @description     Checks that yawrate offset is not changed more than a threshold value
                   by the dynamic offset correction, keeps old offset value otherwise

  @return          void

  @param[in]       *Input : Current Input Data
  @param[in,out]   *IntData : VDY Internal Data

  @glob_in         oldOffset : old offset
  @glob_out        oldOffset : old offset

  @c_switch_part   None 
  @c_switch_full   CFG_VDY_DIS_YWR_OFFSET_COMP : Disables zero point offset compensation of input yaw rate signal

  @pre             None
  @post            No changes
  @InOutCorrelation
						- If dynamic offset taken from NVM or dynamic offset is stand still offset
							- set old offset to stand still offset and store stand still offset
						- If difference between estimated raw yaw rate offset and yaw rate offset
							- Set internal data input yaw rate offset temporarily to the old offset (one step byside the stand still offset)
							- reinit the dynamic yaw rate offset state with the oldOffset
						- Otherwise, 
							- Reset internal data input yaw rate offset to original stand still offset
							- Set oldoffset to actual estimated dynamic offset
  
	@startuml
	start
		if (  (   (CML_f_Abs(IntData->vdy_offsets_in.vdy_yaw_offset.offset - Input->OffsData.offset) > DEG2RAD(VDY_TEN_CENT)) && eeprom offset \n (Input->OffsData.state == (uint8)(VDY_YAWRATE_STATE_NVM)) ) || stand still offset \n (Input->OffsData.state == (uint8)(VDY_YAWRATE_STATE_STANDSTILL))    ) then (YES)
			:(void)memcpy(&IntData->vdy_offsets_in.vdy_yaw_offset, &Input->OffsData, sizeof(vdy_yaw_offset_t));
			:set old offset to stand still offset \n oldOffset = Input->OffsData.offset;
			:store stand still offset \n StandStillOffset = oldOffset;
		else (NO)
			:(void)memcpy(&IntData->vdy_offsets_in.vdy_yaw_offset, &Input->OffsData, sizeof(vdy_yaw_offset_t));
		endif
		if (    ( CML_f_Abs(IntData->vdy_wye_out.raw_est_yaw_offset - IntData->vdy_offsets_in.vdy_yaw_offset.offset) > VDY_YAWRATE_DYN_MAX_DIFF) && ( (IntData->vdy_offsets_in.vdy_yaw_offset.state == (uint8)(VDY_YAWRATE_STATE_KEEP_TYPE)) && (Input->IsDynamic == (boolean)FALSE) )  ) then (YES)
			:Set internal data input yaw rate offset temporarily to the old offset (one step byside the stand still offset) \n IntData->vdy_offsets_in.vdy_yaw_offset.offset = oldOffset;
			:reinit the dynamic yaw rate offset state with the oldOffset \n IntData->vdy_offsets_in.vdy_yaw_offset.state  = VDY_YAWRATE_STATE_STANDSTILL;
		else (NO)
			:Reset internal data input yaw rate offset to original stand still offset \n IntData->vdy_offsets_in.vdy_yaw_offset.offset = StandStillOffset;
			:Set oldoffset to actual estimated dynamic offset \n oldOffset = IntData->vdy_wye_out.gier_yaw_rate_offset;
		endif
	stop
	@enduml
  @testmethod		- Module Testing \n
                            This function has to be tested for statement and branch coverage. \n
                            For detailed unit test description follow the caller graph to the test function \n
                            test_vdy_mon.c ->	  \n
                            TEST_vdyMonitorDynYwrOffset_001(), \n
                            TEST_vdyMonitorDynYwrOffset_002(), \n
                            TEST_vdyMonitorDynYwrOffset_003(), \n
                            TEST_vdyMonitorDynYwrOffset_004(), \n
                            TEST_vdyMonitorDynYwrOffset_005()

  @traceability			  
	- NA
**************************************************************************** */
extern void vdyMonitorDynYwrOffset(const ToAutocode_t *Input, VDYInternalData_t *IntData);


/* **********************************************************************
  @fn               vdyVelMonExec */ /*!
  @brief           Calls velocity monitoring routines

  @description     Main function to execute velocity monitoring
                   Inits monitoring data if VDY mode is init, otherwise
                   executes monitoring

  @return          void

  @param[in]       *input : Input of the Vehicle Dynamics Module 
  @param[in]       *ve : Ve module data
  @param[in,out]   *pErr : VDY Errors

  @c_switch_part   
				  - CFG_VDY_DIS_WHEEL_PRE_PROCESSING : Disables the wheel speed pre processing, 
																	- wheel offset estimation
																	- wheel velocity <-> puls fusion
																	- vehicle speed estimation
																	- wheel load dependancy estimation
																	- dynamic (drift) sensor yaw rate offset estimation
																	- wheel velocity yaw rate estimation 
				  - CFG_VDY_FS_VELO_CORR_MON : Enables the fast velocity to stationary targets monitor
  @c_switch_full   CFG_VDY_USE_VELO_MONITOR : Enables monitoring of external vehicle velocity. The velocity is compared with estimated 
                                              velocity based on wheel speeds

	@startuml
	start
		if ( vdy control mode is init \n VDY_CTRL_GET_STATE( (BaseOpMode_t)BASE_OM_RESET, input->Frame.OpMode)) then (YES)
			:vdyVelMonInit(pErr);
		else (NO)
			:VDYVelMon(&input->Signals, ve, pErr);
		endif
	stop
	@enduml
  @pre             None
  @post            No changes
  @InOutCorrelation		  - 
  
  @testmethod			  - Module Testing \n
                            This function has to be tested for statement and branch coverage. \n
                            For detailed unit test description follow the caller graph to the test function \n
                            test_vdy_mon.c -> TEST_vdyVelMonExec_001(), TEST_vdyVelMonExec_002()
  @traceability			  - NA , please refer function VDYVelMon(const VehSigMain_t *in, const vdy_ve_out_t *ve, VDYErrors_t *pErr);
**************************************************************************** */
extern void vdyVelMonExec(const VDYInputData_t *input, const vdy_ve_out_t *ve, VDYErrors_t *pErr);


/* **********************************************************************
  @fn               vdyVelMonInit */ /*!
  @brief           Initializes Velocity Monitoring

  @description     Sets fault states to unknown and fault counter to 0

  @return          void

  @param[in,out]   *pErr :   VDY Errors

  @glob_in         None 
  @glob_out        VMON_GET_ME : velocity monitor data

  @c_switch_part   None 
  @c_switch_full   CFG_VDY_USE_VELO_MONITOR : Enables monitoring of external vehicle velocity. The velocity is compared with estimated 
                                              velocity based on wheel speeds
	@startuml
	start
		:VDYVelMon_t *pVelMon = VMON_GET_ME;
		:pErr->OutPutErrors.VelMon   = VDY_ERR_STATE_UNKNOWN;
		:pErr->OutPutErrors.VelMonLt = VDY_ERR_STATE_UNKNOWN;
		:pVelMon->cntOutSide = 0U;
		:return;
	stop
	@enduml

  @pre             None
  @post            No changes
  @InOutCorrelation		  - 
  
  @testmethod			  - Module Testing \n
                            This function has to be tested for statement and branch coverage. \n
                            For detailed unit test description follow the caller graph to the test function \n
                            test_vdy_mon.c ->
  @traceability			  - NA
**************************************************************************** */
extern void vdyVelMonInit(VDYErrors_t *pErr);

#if ( (defined(CFG_VDY_ALIGNMENT_OFFSET_MONITOR)) && (CFG_VDY_ALIGNMENT_OFFSET_MONITOR) )
/* **********************************************************************
  @fn               vdyAlignmentYawOffsMonitor */ /*!
  @brief           Monitor the alignment monitoring yaw rate error

  @description     Compares yaw rate offset calculated by VDY and ALN
                   Fault is set if difference is above threshold
                   Note: This functionality was never activated or tested
                   in ARS301 based projects
                   Functionality will be removed as obsolete in ARS400

  @return          void

  @param[in]       *reqPorts : Request Ports
  @param[in]       *input : Current Input Data
  @param[in]       *IntData : Internal Data
  @param[in,out]   *VDYErrors : VDY Error Signals

  @glob_in         ACCThldTime : ACC absolute threshold time
  @glob_in         CGThldTime : CG absolute threshold time
  @glob_out        ACCThldTime : ACC absolute threshold time
  @glob_out        CGThldTime : CG absolute threshold time

  @c_switch_part   None 
  @c_switch_full   CFG_VDY_ALIGNMENT_OFFSET_MONITOR : Do yaw rate offset monitoring with alignment offset estimation input

  @pre             None
  @post            No changes
  @post             -
**************************************************************************** */
extern void vdyAlignmentYawOffsMonitor(const reqVdyPrtList_t *reqPorts, const VDYInputData_t *input, const VDYInternalData_t *IntData, VDYErrors_t *VDYErrors);
#endif

/*****************************************************************************
  DATA ACCQUISITION AND SIMULATION INTERFACE 
*****************************************************************************/

#if defined(VDY_SIMU) || defined(VDY_DACQ_IF) 
/*! These functions are intended for data acquisition and simulation purpose only 
    i. e. this interface must no be used by regular functional code */
#if ( (!defined(CFG_VDY_DIS_YAW_SENSOR_PRE_PROCESSING)) || (!CFG_VDY_DIS_YAW_SENSOR_PRE_PROCESSING) )
	
/* **********************************************************************
Unit Design for vdyYwrGetPrivateData is found in vdy_ywr.c
**************************************************************************** */
extern VDYYwrData_t      *vdyYwrGetPrivateData(void);
#endif

#if (CFG_VDY_INT_GYRO)
extern VDYYwrtData_t     *VDYYwrtGetPrivateData(void);
#endif

#if ( (!defined(CFG_VDY_DIS_STW_ANGLE_SENSOR_PRE_PROCESSING)) || (!CFG_VDY_DIS_STW_ANGLE_SENSOR_PRE_PROCESSING) )
extern VDYSwaData_t      *vdySwaGetPrivateData(void);
#endif

extern VDYAyData_t       *vdyAyGetPrivateData(void);
#if ( (!defined(CFG_VDY_DIS_WHEEL_PRE_PROCESSING)) || (!CFG_VDY_DIS_WHEEL_PRE_PROCESSING) )
/* **********************************************************************
 Unit Design for vdyWhsGetPrivateData is found in vdy_whs.c
**************************************************************************** */
extern VDYWhsData_t      *vdyWhsGetPrivateData(void);
#endif

#if ( (defined(CFG_VDY_DO_VELOCITY_CORR)) && (CFG_VDY_DO_VELOCITY_CORR) )
extern VDYVelCorr_t      *VDYVelCorrGetPrivateData(void);
#if ( (defined(CFG_VDY_FS_VELO_CORR_MON)) && (CFG_VDY_FS_VELO_CORR_MON) )
extern VDYFSVelCorrMon_t *VDYFSVelCorrMonGetPrivateData(void);
#endif
#endif

/* **********************************************************************
  @fn                 vdyYwrMonGetPrivateData */ /*!
  @brief           Get data of yaw rate monitoring

  @description     Returns pointer to internal yaw rate monitoring data
                   to allow MTS output of the data

  @return          VDYYwrMonData_t

  @param[in]       void : 

  @glob_in         None 
  @glob_out        YWR_GET_MON_DATA : Yaw rate monitor database

  @c_switch_part   None 
  @c_switch_full   CFG_VDY_YWR_OFFSET_MONITOR : Enables monitoring of yaw rate at vehicle-stop, during vehicle-stop and vehicle drive-off. During this driving
                                                conditions zero point offset is roughly observeable. Exceedance of limits are indicated by error events

  @pre             None
  @post            No changes
  @InOutCorrelation		  - 
  
  @testmethod			  - NA
  @traceability			  - NA
**************************************************************************** */
extern VDYYwrMonData_t   *vdyYwrMonGetPrivateData(void);
extern VDYCrvMergeData_t *VDYCrvGetMergeData(void);


/* **********************************************************************
  @fn                     vdyVelMonGetPrivateData */ /*!
  @brief           Get access to internal velocity monitoring data

  @description     Returns pointer to velocity monitor data to allow MTS output

  @return          VDYVelMon_t

  @glob_in         None 
  @glob_out        VMON_GET_ME : velocity monitor data

  @c_switch_part   None 
  @c_switch_full   CFG_VDY_USE_VELO_MONITOR : Enables monitoring of external vehicle velocity. The velocity is compared with estimated 
                                              velocity based on wheel speeds

	@startuml
	start
		:return (VMON_GET_ME);
	stop
	@enduml

  @pre             None
  @post            No changes
  @InOutCorrelation		  - 
  
  @testmethod			  - Module Testing \n
                            This function has to be tested for statement and branch coverage. \n
                            For detailed unit test description follow the caller graph to the test function \n
                            test_vdy_mon.c -> -> TEST_vdyVelMonGetPrivateData_001()
  @traceability			  - NA
**************************************************************************** */
extern VDYVelMon_t       *vdyVelMonGetPrivateData(void);


/* **********************************************************************
  @fn               vdyInitDynYwrOffsetMonitor */ /*!

  @brief           Init the dynamic yaw rate offset Monitor

  @description     Initalizes the dynamic montoring data in the simulation

  @return          void

  @param[in]       YwrOffset : Yaw Rate Offset Data

  @glob_in         None 
  @glob_out        oldOffset : old offset
  @glob_out        StandStillOffset : stand still offset

  @c_switch_part   None 
  @c_switch_full   
					  VDY_SIMU :   
					  CFG_VDY_DIS_YWR_OFFSET_COMP : Disables zero point offset compensation of input yaw rate signal

  @pre             None
  @post            No changes
  @InOutCorrelation		  - 
  
  @testmethod			  - NA
  @traceability			  - NA
**************************************************************************** */
extern void vdyInitDynYwrOffsetMonitor( float32 YwrOffset );

#if !(defined(CFG_VDY_DIS_FUNCTIONAL_SAFETY_MON) && (CFG_VDY_DIS_FUNCTIONAL_SAFETY_MON))
extern VDYFSData_t       *vdyFSMonGetPrivateData(void);
#endif

#endif

#if defined(VDY_SIMU)
extern VDYLastInSig_t    *vdyGetMonitorInput(void);
#if ( (defined(CFG_VDY_MON_OUTPUT_PEAKS)) && (CFG_VDY_MON_OUTPUT_PEAKS) )
	
/* **********************************************************************
  @fn               vdyGetMonitorOutputPeaksData */ /*!
  @brief           Get the vdy Monitor output peaks signals and parameters

  @description     Returns pointer to the output signals peak monitor data
                   to allow access to this data in the simulation

  @return          VDYLastOutSig_t *

  @param[in]       void : 

  @glob_in         None 
  @glob_out        LastOutputSignals : Some last valid Output Signals

  @c_switch_part   None 
  @c_switch_full   VDY_SIMU :
  @c_switch_full   CFG_VDY_MON_OUTPUT_PEAKS : Enables the output peak monitoring

  @pre             None
  @post            No changes
  @InOutCorrelation		  - 
  
  @testmethod			  - NA
  @traceability			  - NA
**************************************************************************** */
extern VDYLastOutSig_t * vdyGetMonitorOutputPeaksData(void);
#endif

/* ***********************************************************************
  @fn               vdyGetModulIf */ /*!
  @brief           Get pointer to interface data of the internal modules

  @description     Get pointer to interface data of the internal modules

  @return          VDYModIf_t pointer to interface data

  @glob_in         None 
  @glob_out        VDYModIf : interface data of the internal modules

  @c_switch_part   None  
  @c_switch_full   VDY_SIMU

  @pre             None
  @post            No changes
  @InOutCorrelation		  - 
  
	@startuml
	start
		:return(&VDYModIf);
	stop
	@enduml
  @testmethod			  - NA
  @traceability			  - NA
**************************************************************************** */
extern VDYModIf_t        *vdyGetModulIf(void);

/* ***********************************************************************
  @fn               vdyGetVDYIntData */ /*!
  @brief           Get pointer to internal data

  @description     Get pointer to internal data

  @return          VDYInternalData_t pointer to internal data

  @glob_in         None
  @glob_out        vdy_internal_data : internal data

  @c_switch_part   None  
  @c_switch_full   VDY_SIMU

  @pre             None
  @post            No changes
  @InOutCorrelation		  - 
  
	@startuml
	start
		:return (&vdy_internal_data);
	stop
	@enduml
  @testmethod			  - NA
  @traceability			  - NA
**************************************************************************** */
extern VDYInternalData_t *vdyGetVDYIntData(void);

#if ( (!defined(CFG_VDY_DIS_WHEEL_PRE_PROCESSING)) || (!CFG_VDY_DIS_WHEEL_PRE_PROCESSING) )

/* ***********************************************************************
  @fn               vdyGet_D_Work_vdy_wpp */ /*!
  @brief           Get pointer to estimated vdy_wpp internal data

  @description     Get pointer to estimated vdy_wpp internal data

  @return          D_Work_vdy_wpp pointer to wheel speed data

  @glob_in         None
  @glob_out        vdy_wpp_DWork : estimated vdy_wpp internal data

  @c_switch_part   None  
  @c_switch_full   VDY_SIMU
  @c_switch_full   
  - CFG_VDY_DIS_WHEEL_PRE_PROCESSING : Disables the wheel speed pre processing, 
                                                    - wheel offset estimation
                                                    - wheel velocity <-> puls fusion
                                                    - vehicle speed estimation
                                                    - wheel load dependancy estimation
                                                    - dynamic (drift) sensor yaw rate offset estimation
                                                    - wheel velocity yaw rate estimation

  @pre             None
  @post            No changes 
  @InOutCorrelation		  - 
  
	@startuml
	start
		:return (&vdy_wpp_DWork);
	stop
	@enduml
  @testmethod			  - NA
  @traceability			  - NA
**************************************************************************** */
extern D_Work_vdy_wpp    *vdyGet_D_Work_vdy_wpp(void);

/* ***********************************************************************
  @fn               vdyGet_D_Work_vdy_ve */ /*!
  @brief           Get pointer to estimated vdy_ve internal data

  @description     Get pointer to estimated vdy_ve internal data

  @return          D_Work_vdy_ve pointer to yaw rate fusion data

  @glob_in         None 
  @glob_out        vdy_ve_DWork : estimated vdy_ve internal data

  @c_switch_part   None 
  @c_switch_full   VDY_SIMU
  @c_switch_full   
  - CFG_VDY_DIS_WHEEL_PRE_PROCESSING : Disables the wheel speed pre processing, 
                                                    - wheel offset estimation
                                                    - wheel velocity <-> puls fusion
                                                    - vehicle speed estimation
                                                    - wheel load dependancy estimation
                                                    - dynamic (drift) sensor yaw rate offset estimation
                                                    - wheel velocity yaw rate estimation
  @pre             None
  @post            No changes
  @InOutCorrelation		  - 
  
	@startuml
	start
		:return (&vdy_ve_DWork);
	stop
	@enduml
  @testmethod			  - NA
  @traceability			  - NA
**************************************************************************** */
extern D_Work_vdy_ve     *vdyGet_D_Work_vdy_ve(void);

/* ***********************************************************************
  @fn               vdyGet_D_Work_vdy_wye */ /*!
  @brief           Get pointer to estimated vdy_wye internal data

  @description     Get pointer to estimated vdy_wye internal data

  @return          D_Work_vdy_wye pointer to wheel speed yaw rate data

  @glob_in         None 
  @glob_out        vdy_wye_DWork : estimated vdy_wye internal data

  @c_switch_part   None  
  @c_switch_full   VDY_SIMU
  @c_switch_full   
  - CFG_VDY_DIS_WHEEL_PRE_PROCESSING : Disables the wheel speed pre processing, 
                                                    - wheel offset estimation
                                                    - wheel velocity <-> puls fusion
                                                    - vehicle speed estimation
                                                    - wheel load dependancy estimation
                                                    - dynamic (drift) sensor yaw rate offset estimation
                                                    - wheel velocity yaw rate estimation


  @pre             None
  @post            No changes
  @InOutCorrelation		  - 
  
	@startuml
	start
		:return (&vdy_wye_DWork);
	stop
	@enduml
  @testmethod			  - NA
  @traceability			  - NA
**************************************************************************** */
extern D_Work_vdy_wye    *vdyGet_D_Work_vdy_wye(void);
#endif

#if ( (!defined(CFG_VDY_DIS_YAW_SENSOR_PRE_PROCESSING)) || (!CFG_VDY_DIS_YAW_SENSOR_PRE_PROCESSING) )

/* ***********************************************************************
  @fn               vdyGet_D_Work_vdy_gye */ /*!
  @brief           Get pointer to estimated vdy_gye internal data

  @description     Get pointer to estimated vdy_gye internal data

  @return          D_Work_vdy_gye pointer to gyro yaw rate data

  @glob_in         None 
  @glob_out        vdy_gye_DWork : estimated vdy_gye internal data

  @c_switch_part   None  
  @c_switch_full   VDY_SIMU
  @c_switch_full   
  - CFG_VDY_DIS_YAW_SENSOR_PRE_PROCESSING : Disables the sensor yaw rate pre processing, 
                                                         - static (stand still)yaw rate offset
                                                         - yaw rate from yaw rate sensor estimation

  @pre             None
  @post            No changes
  @InOutCorrelation		  - 
  
	@startuml
	start
		:return (&vdy_gye_DWork);
	stop
	@enduml
  @testmethod			  - NA
  @traceability			  - NA
**************************************************************************** */
extern D_Work_vdy_gye    *vdyGet_D_Work_vdy_gye(void);

/* ***********************************************************************
  @fn               vdyGet_D_Work_vdy_gye_filt */ /*!
  @brief           Get pointer to estimated vdy_gye_filt internal data

  @description     Get pointer to estimated vdy_gye_filt internal data

  @return          D_Work_vdy_gye : Pointer to Gyro yaw rate data

  @glob_in         None
  @glob_out        vdy_gye_DWork_FILT : estimated vdy_gye_filt internal data

  @c_switch_part   None  
  @c_switch_full   VDY_SIMU
  @c_switch_full   
  - CFG_VDY_DIS_YAW_SENSOR_OFFS_PRE_FILTERING : Disables the alignment yaw rate offset pre filtering, 
                                                             - yaw rate from yaw rate sensor with filtered offset estimation

  @pre             None
  @post            No changes
  @InOutCorrelation		  - 
  
	@startuml
	start
		:return (&vdy_gye_DWork_FILT);
	stop
	@enduml
  @testmethod			  - NA
  @traceability			  - NA
**************************************************************************** */
extern D_Work_vdy_gye    *vdyGet_D_Work_vdy_gye_filt(void);
#endif

#if ( (!defined(CFG_VDY_DIS_LAT_ACCEL_SENSOR_PRE_PROCESSING)) || (!CFG_VDY_DIS_LAT_ACCEL_SENSOR_PRE_PROCESSING) )

/* ***********************************************************************
  @fn               vdyGet_D_Work_vdy_aye */ /*!
  @brief           Get pointer to estimated vdy_aye internal data

  @description     Get pointer to estimated vdy_aye internal data

  @return          D_Work_vdy_aye pointer to lat accel yaw rate data

  @glob_in         None  
  @c_switch_full   VDY_SIMU
  @glob_out        vdy_aye_DWork :estimated vdy_aye internal data

  @c_switch_part   None 
  @c_switch_full   
  - CFG_VDY_DIS_LAT_ACCEL_SENSOR_PRE_PROCESSING : Disables the lateral acceleration sensor pre processing, 
                                                               - lateral sensor offset estimation
                                                               - yaw rate from lateral acceleration sensor estimation

  @pre             None
  @post            No changes
  @InOutCorrelation		  - 
  
	@startuml
	start
		:return (&vdy_aye_DWork);
	stop
	@enduml
  @testmethod			  - NA
  @traceability			  - NA
**************************************************************************** */
extern D_Work_vdy_aye    *vdyGet_D_Work_vdy_aye(void);
#endif

#if ( (!defined(CFG_VDY_DIS_STW_ANGLE_SENSOR_PRE_PROCESSING)) || (!CFG_VDY_DIS_STW_ANGLE_SENSOR_PRE_PROCESSING) )
/* ***********************************************************************
  @fn               vdyGet_D_Work_vdy_sye */ /*!
  @brief           Get pointer to estimated vdy_sye internal data

  @description     Get pointer to estimated vdy_sye internal data

  @return          D_Work_vdy_sye pointer to steering wheel yaw rate data

  @glob_in         None 
  @glob_out        vdy_sye_DWork : estimated vdy_sye internal data

  @c_switch_part   None  
  @c_switch_full   VDY_SIMU
  @c_switch_full   
  - CFG_VDY_DIS_STW_ANGLE_SENSOR_PRE_PROCESSING : Disables the steering wheel angle sensor pre processing, 
                                                               - steering wheel angle sensor offset estimation
                                                               - estimation of self steering gradient
                                                               - driver intended curvature
                                                               - yaw rate from steering wheel sensor estimation

  @pre             None
  @post            No changes
  @InOutCorrelation		  - 
  
	@startuml
	start
		:return (&vdy_sye_DWork);
	stop
	@enduml
  @testmethod			  - NA
  @traceability			  - NA
**************************************************************************** */
extern D_Work_vdy_sye    *vdyGet_D_Work_vdy_sye(void);
#endif

#if ( (!defined(CFG_VDY_USE_EXT_PROC_YAW_RATE)) || (!CFG_VDY_USE_EXT_PROC_YAW_RATE) )
/* ***********************************************************************
  @fn               vdyGet_D_Work_vdy_ye */ /*!
  @brief           Get pointer to estimated vdy_ye internal data

  @description     Get pointer to estimated vdy_ye internal data

  @return          D_Work_vdy_ye pointer to yaw rate and curve fusion data

  @glob_in         None 
  @glob_out        vdy_ye_DWork : estimated vdy_ye internal data

  @c_switch_part   None  
  @c_switch_full   VDY_SIMU
  @c_switch_full   
  - CFG_VDY_USE_EXT_PROC_YAW_RATE : Enables usage of external yaw rate as vdy output yaw rate

  @pre             None
  @post            No changes
  @InOutCorrelation		  - 
  
	@startuml
	start
		:return (&vdy_ye_DWork);
	stop
	@enduml
  @testmethod			  - NA
  @traceability			  - NA
**************************************************************************** */
extern D_Work_vdy_ye     *vdyGet_D_Work_vdy_ye(void);
#endif

#if ( (!defined(CFG_VDY_DIS_SIDE_SLIP_ANGLE_ESTIMATION)) || (!CFG_VDY_DIS_SIDE_SLIP_ANGLE_ESTIMATION) )
/* ***********************************************************************
  @fn               vdyGet_D_Work_vdy_sae */ /*!
  @brief           Get pointer to estimated vdy_sae internal data

  @description     Get pointer to estimated vdy_sae internal data

  @return          D_Work_vdy_sae pointer to slip angle data

  @glob_in         None 
  @glob_out        vdy_sae_DWork : estimated vdy_sae internal data

  @c_switch_part   None 
  @c_switch_full   VDY_SIMU
  @c_switch_full   
  - CFG_VDY_DIS_SIDE_SLIP_ANGLE_ESTIMATION : Disables the side slip angle estimation

  @pre             None
  @post            No changes
  @InOutCorrelation		  - 
  
	 @startuml
  start
	:return (&vdy_sae_DWork);
  stop
  @enduml
  @testmethod			  - NA
  @traceability			  - NA
**************************************************************************** */
extern D_Work_vdy_sae    *vdyGet_D_Work_vdy_sae(void);
#endif

#if (CFG_VDY_MOT_STATE)
/* ***********************************************************************
  @fn               vdyGetVDYBayesOut */ /*!
  @brief           Get pointer to estimated curves 

  @description     Get pointer to estimated curves 

  @return          vdy_bayes_mot_states_t pointer to curve data

  @glob_in         None 
  @glob_out        vdy_mot_st_DWork : estimated vdy_sae internal data

  @c_switch_part   None  
  @c_switch_full   VDY_SIMU
  @c_switch_full   

  @pre             None
  @post            No changes
  @InOutCorrelation		  - 
  
  @testmethod			  - NA
  @traceability			  - NA
**************************************************************************** */
extern vdy_bayes_mot_states_t *vdyGetVDYBayesOut(void);

/* ***********************************************************************
  @fn               vdyGet_D_Work_vdy_mot_st */ /*!
  @brief           Get pointer to estimated vdy_sae internal data

  @description     Get pointer to estimated vdy_sae internal data

  @return          D_Work_vdy_mot_st pointer to motion state data

  @glob_in         None 
  @glob_out        vdy_mot_st_DWork : estimated vdy_sae internal data

  @c_switch_part   None  
  @c_switch_full   VDY_SIMU
  @c_switch_full   
  - CFG_VDY_MOT_STATE : Enable motion state processing

  @pre             None
  @post            No changes
  @InOutCorrelation		  - 
  
  @testmethod			  - NA
  @traceability			  - NA
**************************************************************************** */
extern D_Work_vdy_mot_st *vdyGet_D_Work_vdy_mot_st(void);
#endif

 
/* ***********************************************************************
  @fn               vdySetSequenceInitState */ /*!
  @brief           Set the sequence initalization state

  @description     Set the sequence initalization state

  @return          void

  @param[in]       _sSequenceInitState : Sequence Init State

  @c_switch_part   None  
  @c_switch_full   VDY_SIMU

  @pre             None
  @post            No changes
  @InOutCorrelation -  Set the sequence init state to the local variable 
  
	@startuml
	start
		:Set the sequence init state to the local variable \n sSequenceInitState = _sSequenceInitState;	
	stop
	@enduml
  @testmethod			  - NA
  @traceability			  - NA
**************************************************************************** */
extern void vdySetSequenceInitState( VDYSequenceInitStates_t _sSequenceInitState );
#endif

#ifdef __cplusplus
};
#endif

/*** END OF SINLGE INCLUDE SECTION ******************************************/
#endif

/** @} */ 
/* EOF */
