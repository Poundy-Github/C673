/**
@file
$RCSfile: hal_base_type_if.he $
$Revision: 1.1 $
$Date: 2018/01/24 16:29:41CET $

Confidential and proprietary. This document and its contents are the
exclusive property of Continental Teves AG & Co. OHG (Teves) and Conti Temic
microelectronic GmbH (Temic) and their associated companies. They are not to
be copied, distributed, or otherwise disclosed or used without the prior
written consent of Teves and Temic. All rights reserved.

@author RaviR

@brief Base type definitions for all models

@details base_types Global Base Type Definitions

@defgroup HAL_IF  Hardware Abstraction Layer Interfaces
@ingroup HAL

@defgroup base_types Global Base Type Definitions
@ingroup HAL_IF
*/

#ifndef hal_base_type_if_h_included
#define hal_base_type_if_h_included



/**
@defgroup    ct_base_types CT generic base data types
@ingroup     base_types
*/




/**
@addtogroup  ct_base_types
@{
*/


   /**
   @name CT generic 8 Bit data types
   */
   /** @{ */


/**
@brief  8 bit data type

@details
*/
typedef signed char             signed_char_t;

/**
@brief  8 bit data type

@details
*/
typedef unsigned char           unsigned_char_t;

/* satisfies Coding Standard SEV E-001-4.0 Page 8/47 */
/* Autosar compatible */

/**
@brief Autosar and CT generic data type

@details     char 8 bit (pchar -> plain char)
*/
typedef char                    pchar;


/**
@brief CT generic const 8bit data type

@details
*/
typedef const unsigned_char_t   const_unsigned_char_t;


   /**
   @}
   */ /* name CT generic 8 Bit data types */


   /**
   @name CT generic 16 Bit data types
   */
   /** @{ */


/**
@brief 16 bit data type

@details
*/
typedef signed short int        signed_int16_t;

/**
@brief 16 bit data type

@details
*/
typedef unsigned short int      unsigned_int16_t;

/**
@brief CT generic const 16 bit data type

@details
*/
typedef const unsigned_int16_t  const_unsigned_int16_t;


   /**
   @}
   */ /* name CT generic 16 Bit data types */


   /**
   @name CT generic 32 Bit data types
   */
   /** @{ */


/**
@brief 32 bit data type

@details
*/
typedef signed int              signed_int32_t;

/**
@brief CT generic 32 bit data type

@details
*/
typedef unsigned int            unsigned_int32_t;



/**
@brief

@details for arthmetic with wsr pointer cast wsr as 32 bit integer
*/
typedef unsigned_int32_t        wsr_arithmetic_t;

   /**
   @}
   */ /* name CT generic 32 Bit data types */



   /**
   @name CT generic pointer types
   */
   /** @{ */



/**
@brief void pointer type

@details
*/

typedef void                    *void_ptr_t;

/**
@brief CT generic pointer type

@details Pointer to unsigned char
*/
typedef unsigned_char_t         *unsigned_char_ptr_t;

/**
@brief CT generic pointer type to const data (8 bit)

@details
*/
typedef const_unsigned_char_t   *const_unsigned_char_ptr_t;

/**
@brief CT generic pointer type to 16 bit data

@details
*/
typedef unsigned_int16_t        *unsigned_int16_ptr_t;

/**
@brief CT generic pointer type to 16 bit const data

@details
*/
typedef const_unsigned_int16_t  *const_unsigned_int16_ptr_t;


   /**
   @}
   */  /* name CT generic pointer types */



   /**
   @name CT generic array types
   */
   /** @{ */


/**
@brief CT generic array type

@details 
*/
typedef unsigned_char_t         unsigned_char_array_t[];



/**
@brief CT generic 16 bit array type

@details
*/
typedef unsigned_int16_t        unsigned_int16_array_t[];

   /**
   @}
   */  /* name CT generic array types */
#if (SIM_SCT_STATIC_AS_EXTERN_CFG)
/**
@brief

@details  all global static variables and functions in C modules
          shall be defined by using "Global_static" instead of "static"
          to support read (or also write) access to these variables in
          a software simulation and component testing environment.
*/ 
#define Global_static extern

#elif ((!SIM_TOTAL_CFG) && (!SIM_SCT_CFG))

/**
@brief

@details  all global static variables and functions in C modules
          shall be defined by using "Global_static" instead of "static"
          to support read (or also write) access to these variables in
          a software simulation and component testing environment.
*/ 
#define Global_static       static

#else

/**
@brief

@details  all global static variables and functions in C modules 
          shall be defined by using "Global_static" instead of "static"
          to support read (or also write) access to these variables in 
          a software simulation and component testing environment.
*/ 
#define Global_static
#endif


/**
@}
*/ /* addtogroup  ct_base_types */


#ifndef OSEK_MODEL

/**
@defgroup    autosar_types Autosar base data types
@ingroup     base_types
*/

/**
@addtogroup  autosar_types
@{
*/


/* OSEK uses its own typedefs for uint{8,16,32} */

   /**
   @name Autosar 8 Bit data types
   */
   /** @{ */


/**
@brief

@details     char 8 bit signed
*/
typedef signed char             sint8;

/**
@brief

@details     char 8 bit unsigned
*/
typedef unsigned char           uint8;

   /**
   @}
   */  /* name Autosar 8 Bit data types */


   /**
   @name Autosar 16 Bit data types
   */
   /** @{ */


/**
@brief

@details     integer 16 Bit signed
*/
typedef signed short            sint16;

/**
@brief

@details     integer 16 Bit unsigned
*/
typedef unsigned short          uint16;

   /**
   @}
   */  /* name Autosar 16 Bit data types */


   /**
   @name Autosar 32 Bit data types
   */
   /** @{ */


/**
@brief

@details     integer 32 Bit signed
*/
//typedef signed long             sint32; //ClPr: removed here because already defined in glob_type.h

/**
@brief

@details     integer 32 Bit unsigned
*/
//typedef unsigned long           uint32; //ClPr: removed here because already defined in glob_type.h

   /**
   @}
   */  /* name Autosar 32 Bit data types */


   /**
   @name Autosar boolean data types
   */
   /** @{ */


/**
@brief

@details     boolean

@note        OSEK defines boolean with unsigned char
*/
typedef unsigned char           boolean;
#endif


   /**
   @}
   */  /* name Autosar boolean data types */

   /**
   @name Autosar real floating data types
   */
   /** @{ */


/**
@brief

@details     float 32 Bit
*/
typedef float                   float32;

/**
@brief

@details     float 64 Bit
*/
typedef double                  float64;


/* typedef long double             float128; */ /* float 128 Bit */ /* 128 bit not supported by FSC MCORE, SPACE & TI compiler */

   /**
   @}
   */  /*  name Autosar real floating data types */


/**
@}
*/ /* addtogroup  autosar_types */


#if (defined(BFU_MODEL) && (SILICON_TI))
    #ifndef osdSuppressPosixTypes
    #define osdSuppressPosixTypes               /**< @brief suppress Posix Types */
/**
@defgroup    posix_types Posix conform base data types

@details     workaround for TI compiler warning of conflicting types for uint{8,16,32} 
             which are typedef'd in osek.h. Disable them with osdSuppressPosixTypes 
             but then you have to define int{8,16,32}.
             !!!!Don't use int{8,16,32} in BFU!!!!!

@ingroup     base_types
*/    

/**
@addtogroup  posix_types
@{
*/



/**
@brief

@details     integer 8 Bit signed
*/
typedef signed char int8;

/**
@brief

@details     integer 16 Bit signed
*/
typedef signed short int16;

/**
@brief

@details     integer 32 Bit signed
*/
typedef signed long int32;
    #endif

/**
@}
*/ /*  addtogroup posix_types */

#endif

/**
@defgroup    system_types CT system specific types

@ingroup     base_types
*/

#ifndef CFG_WHEEL_VELO_RANGE_32BIT
#define CFG_WHEEL_VELO_RANGE_32BIT 0   /**< @brief set if wheel speed types are of size 32 bit */
#endif

#ifndef CFG_UNLIMITED_VELOCITY_BFU
#define CFG_UNLIMITED_VELOCITY_BFU 0   /**< @brief set if UNLIMITED_WHEEL_VELOCITY_A interface is enabled */
#endif

/**
@addtogroup  system_types  
@{
*/

#if (CFG_UNLIMITED_VELOCITY_BFU)
/**
@brief

@details
*/
typedef signed_int32_t          wheel_velocity_s32bit_t;
#endif

#if (CFG_WHEEL_VELO_RANGE_32BIT)
/**
@brief type of all wheel velocity interfaces, i.e. UNCHANGED_WHEEL_VELOCITY_A

@details
*/
typedef signed_int32_t          wheel_velocity_t;
#else
/**
@brief type of all wheel velocity interfaces, i.e. UNCHANGED_WHEEL_VELOCITY_A

@details
*/
typedef signed_int16_t          wheel_velocity_t;
#endif

/**
@brief type of vehicle acceleration interfaces

@details
*/
typedef signed_char_t           vehicle_acceleration_t;

/**
@brief type of wheel acceleration interfaces

@details
*/
typedef signed_int16_t          wheel_acceleration_t;

/**
@brief

@details
*/
/*typedef unsigned_char_t         tcs_tf_torque_t;*/

/**
@brief type of axle engine torque

@details
*/
typedef signed_int16_t          tcs_axle_engine_torque_t;

/**
@brief

@details
*/
/*typedef unsigned_int16_t        model_temperature_t;*/

/**
@brief type of model pressure

@details
*/
typedef unsigned_int16_t        model_pressure_t;

/**
@brief type of filtered slip acceleration

@details
*/
typedef signed_int16_t          filtered_slip_acceleration_t;

/**
@brief type of vehicle acceleration

@details
*/
typedef signed_char_t           abs_vehicle_acceleration_t;

/**
@}
*/ /* addtogroup  system_types  */


/**
@defgroup    inline_types Inline functionality
@ingroup     base_types
*/


/**
@addtogroup  inline_types
@{
*/



   /**
   @name Microprocessor specific inline keywords
   */
   /** @{ */


    #if (SILICON_TI)
#define _inline_            inline   /**< @brief TI microprocessor */
    #elif (SILICON_MOT)
#define _inline_            __inline__  /* PRQA S 3431 */ /* Justification 3431: accepted, mapping needed for different compiler keywords */ /**< @brief inline keyword for FSL microprocessor */ 
    #else
#define _inline_            /**< @brief neither TI nor FSL microprocessor */
    #endif


   /**
   @}
   */  /*  name Microprocessor specific inline keywords */



#define Local               static                    /**< @brief  local variable of type static */

   /**
   @name CT inline macros
   */
   /** @{ */



#define Local_inline        static _inline_           /**< @brief Declare/define inline function(s). inline function(s) used only locally */

#define Global_inline       static _inline_           /**< @brief Declare/define inline function(s). inline functions(s) used globally */

#define Inline_body         1                        /**< @brief Inline body needed */

   /**
   @}
   */  /*  name CT inline macros */


   /**
   @name CT runtime optimzation inline approach
   */
   /** @{ */



    #if(1==CFG_RUNTIME_OPTIMIZATION)

#define Global_inline_or_extern    static _inline_     /**< @brief "switch" to declare/define inline function or normal function. Here switch set to mode "inline mode" */

#define Inline_or_extern_body      1                   /**< @brief "switch" to define function body or not. Here function body is visible */

    #else

#define Global_inline_or_extern    extern      /**< @brief "switch" to declare inline function or normal function. Here switch set to mode "normal function"inline function used only local */

#define Inline_or_extern_body      0           /**< @brief "switch" to define function body or not. Here function body isn't visible */

    #endif

   /**
   @}
   */  /*  name CT runtime optimzation inline approach */


   /**
    * @name CT inline approach considering modul test requirement(s)
    * @details     The following macros are used to enable inlining functionality. Impact on Modul test functionality is considered by this macros.
    *              Function inlining needs function definition (function body) at compile time. Therefore function definition is 
    *              put into include files (*.h* files). If such a design is chosen, non inlining by compiler leads probably to a linker failure.
    *              Following approach is taken
    * - Strap CFG_USE_INLINE_FUNCTION defines whether tagged functions are inlined or not. Strap will be set to 0 (no inline) if strap SIM_SCT_CFG is True. This is done to ensure, that modul test can access all functions.
    * - Strap SIM_SCT_CFG defines whether sources are used in modul test environment or not.
    * - Use macro  #Decl_inline_or_extern as function specifier (for inline function declaration in *.h* file)
    * - Use macro  #Decl_inline_or_extern as function specifier (for inline function definition in *.h* file)
    * - Strap Function definition with Macro #Body_inline logical ored with additional component specific macro xxx (this macro allows the usage of this component for modul test)
    * - Define speficic macro xxx in one c-file of your component.
    *
    * example foo.h File 
    * @code

      #include "..\hal\hal_base_type_if.he"

      Decl_inline_or_extern unsigned_int32_t FOO(void);



      #if ( ( Body_inline ) || ( defined Foo_inline ))

      #ifdef PRQA_SIZE_T
      #pragma PRQA_MESSAGES_OFF 3219
      #pragma PRQA_MESSAGES_OFF 3480
      #pragma PRQA_MESSAGES_OFF 3406
      #endif

      Decl_inline_or_extern unsigned_int32_t FOO(void)
      {
         return (1);
      }

      #ifdef PRQA_SIZE_T
      #pragma PRQA_MESSAGES_ON 3219
      #pragma PRQA_MESSAGES_ON 3480
      #pragma PRQA_MESSAGES_ON 3406
      #endif

      #endif

    * @endcode 
    * example foo.c File 
    * @code
      #define  Foo_inline  

      #include "foo.h"
    * @endcode 
    */
   /** @{ */



#if(CFG_USE_INLINE_FUNCTION)        /* Functions declared as inline are inlined */ 

#define Decl_inline_or_extern      Global_inline  /**< @brief set function spezifier inline -> define inline function */
#define Body_inline                (1)            /**< @brief function body will be visible in *.h* File. Function(s) is(are) defined in *.h* file  */

#else /* Functions declared as inline are not inlined */
 
#define Decl_inline_or_extern      extern         /**< @brief set function spezifier inline -> define inline function */
#define Body_inline                (0)            /**< @brief function body will be not visible in *.h* File. Function(s) is(are) declared in *.h* file */

#endif  /* CFG_USE_INLINE_FUNCTION */

   /**
   @}
   */  /*  name CT inline approach considering modul test requirement(s) */



/**
@}
*/ /* addtogroup  inline_types */

/**
@defgroup    class_types CT class functionality and data types

@ingroup     base_types

@details
*/

/**
@addtogroup  class_types
@{
*/

/**
@brief Type qualifier of class object

*/ 
#define Store_class         const

/**
@brief Type qualifier of static/constant configuration object(s), which is member of class object

@details
*/
#define Store_config        const

/**
@brief Type qualifier of non constant object(s) (variables) of class

@details
*/ 
#define Store_memory


/**
@brief Class Object

@details
*/
typedef Store_class struct class_s class_t;


/**
@brief Complex class data type

@details Class with Subobjects (Configuration Object, Object containing Functions, Object containing non constant data
*/
struct class_s
{
   Store_config void * Store_class config_data;    /*!< @ASAP_NAME   pSTR_CLASS_CONFIG_DATA @UNIT   @LSB   @MIN   @MAX   @OFFSET   @brief Pointer to static/constant configuration object  */
   Store_config void * Store_class function_data;  /*!< @ASAP_NAME   pSTR_CLASS_FUNC_DATA @UNIT     @LSB   @MIN   @MAX   @OFFSET   @brief Pointer to function(s)  */
   Store_memory void * Store_class static_data;    /*!< @ASAP_NAME   pSTR_CLASS_STATIC_DATA @UNIT   @LSB   @MIN   @MAX   @OFFSET   @brief Pointer to object containing non constant data (variables)  */
};

/**
@}
*/ /* addtogroup  class_types */

/**
@defgroup    util_macro Utility Macros
@ingroup     base_types
@details
*/

/**
@addtogroup  util_macro
@{
*/


/**
@brief   Macro to prevent compiler warnings

@details  Macro to work around the compilers warning about unused parameters, fixes QAC warning as well.

@param[in] var  name of local variable
*/
#define ReferenceUnusedParameter(var) ((var) = (var))



/**
@brief    Macro to calculate the size of an object

@return   nr of members of array object

@param[in] object_ptr pointer to array of simple/complex data type
*/ 
#define object_size(object_ptr)   (sizeof(object_ptr)/sizeof((object_ptr)[0]))

/**
@}
*/ /* addtogroup  util_macro */


#endif /* hal_base_type_if_he_included */                                        

/*==================================================================
$Log: hal_base_type_if.he  $
Revision 1.1 2018/01/24 16:29:41CET Asong, Wedndah Asaha (uidj2187) 
Initial revision
Member added to project /ADAS/SW/Components/LCF_LateralControlFunctions/04_Engineering/01_Source_Code/LCF/LATDMC/latdmc_veh_ang/project.pj
Revision 1.1 2017/04/20 10:33:24CEST Feick, Stefan (uidw0691) 
Initial revision
Member added to project /C_ST/CMP/C_A_LATDMC/30_Software_Engineering/30_SW_Environment/20_SourceCode/project.pj
Revision 1.2 2017/02/22 20:41:14CET Feick, Stefan (uidw0691) 
steering wheel vibration related
Revision 1.2 2017/01/19 11:29:56CET Prajescu, Claudia (uidl9533) 
Function and performance improvements during 2.0 demo in Korea
Revision 1.1 2017/01/11 06:02:54CET Babar, Ketan (uidj9168) 
Initial revision
Member added to project /C_ST/A_HI_LCF_1802/20_System_Design/40_Implementation/10_Sources/10_Models/20_System_Function/LateralControlFunctions/C_A_LATDMC/30_Software_Engineering/30_SW_Environment/20_SoCo/project.pj
Revision 1.1 2016/08/03 20:43:24CEST Prajescu, Claudia (uidl9533) 
LaDMC algo code update
Revision 1.21 2012/07/25 13:53:52CEST Volz, Alexander (Volz) 
Doxygen formatting changed
Revision 1.20 2012/04/17 16:25:52CEST Kuethe, Harald (KuetheH) 
QAC: adapt to max rule set
Revision 1.19 2011/06/10 12:53:21CEST Kuethe, Harald (KuetheH) 
QAC: added Justification token
Revision 1.18 2011/02/15 07:09:42CET LAXMINARAYANA-EXT, AVINASH (UIDT7377) 
Reverted back @defgroup changes
Revision 1.17 2011/02/09 11:57:32CET LAXMINARAYANA-EXT, AVINASH (UIDT7377) 
remove old @defgroups
Revision 1.16 2010/12/20 15:04:02CET Volz, Alexander (volz) 
.#1503044:1av201210. Define Global_static as extern if Strap SIM_SCT_STATIC_AS_EXTERN_CFG is set
Revision 1.15 2010/12/13 14:13:33CET Kuethe, Harald (KuetheH) 
doxygen fixes, removed unused typedefs for tcs_tf_torque_t and model_temperature_t
Revision 1.14 2010/11/01 13:13:22CET Volz, Alexander (volz) 
.#1334487:1av011110. Include config96.h
Revision 1.13 2010/06/02 10:00:30CEST Lakhotia, Banvari (LakhotiaB) 
Provide access to Global_static with strap SIM_SCT_CFG for component testing.
Revision 1.12 2009/12/15 17:34:33CET Volz, Alexander (volz) 
.#713292:1av151209. Doxygen grouping changed. Doxygen comments added
Revision 1.11 2009/11/23 13:48:18CET Lakhotia, Banvari (LakhotiaB) 
ASAP and Doxygen comments updated.
Revision 1.10 2009/11/10 16:04:04CET Volz, Alexander (volz) 
.#713292:1av101109. Add test to doxygen group
Revision 1.9 2009/11/10 11:38:09CET Volz, Alexander (volz) 
.#713292:1av101109. New doxygen group HAL_IF introduced
Revision 1.8 2009/11/02 08:45:23CET Küthe, Harald (KuetheH) 
Updated for new inline function definition method.
Revision 1.7 2009/09/22 17:16:07CEST Küthe, Harald (KuetheH) 
enable ReferenceUnusedParameter() as well for SPACE projects. Space compiler warns about a = a but not about (a) = (a)
Revision 1.6 2009/08/14 11:37:01CEST Günther, Karsten (guenther) 
QAC is happy now.
Revision 1.5 2009/08/13 14:37:30CEST Günther, Karsten (guenther) 
Object size calculation macro shifted from qspi_handling.h to here.
Revision 1.4 2009/06/18 16:59:05CEST Raghavendra C S  Satyanarayan (Raghavendra) 
Updated  Model.he includes  with respective Layer.he include paths
Revision 1.3 2009/02/20 10:23:57CET Küthe, Harald (KuetheH) 
Doxygen: restore grouping
Revision 1.2 2009/02/18 12:34:52CET Ravi, Bhuvanahalli Ramachandra (RaviR) 
HAL: New template provided
Revision 1.1 2008/12/18 10:22:16CET Volz, Alexander (volz) 
Initial revision
Member added to project d:/mks/archives/src/HAL/HAL.pj
Former Log of file: BASE_TYP.HE
Revision 1.22 2008/12/17 17:32:10CET Küthe, Harald (KuetheH) 
QAC: fix double include check
Revision 1.21 2008/09/26 12:01:46CEST Kasar, Pankaj (pankaj42) 
Improved ASAP names
Revision 1.20 2008/09/12 12:39:46CEST Küthe, Harald (KuetheH) 
Doxygen: fixed grouping structure
Revision 1.19 2008/09/09 10:36:45CEST Küthe, Harald (KuetheH) 
corrected doxygen documentation
Revision 1.18 2008/09/01 14:44:48CEST Nagarajan, Senthilnathan (sentna59) 
BFU: Doxygen Documentation Part B
Revision 1.17 2008/06/23 16:16:59CEST Günther, Karsten (guenther) 
Naming of global groups standardized.
Revision 1.16 2008/06/12 14:24:45CEST Küthe, Harald (KuetheH) 
add typedef for char - pchar according to SEV_E001
Revision 1.15 2008/05/28 08:34:43CEST Günther, Karsten (guenther) 
Doxygen standardization.
Revision 1.14 2008/05/08 17:31:03CEST Küthe, Harald (KuetheH) 
QAC fix
Revision 1.13 2008/05/08 09:50:06CEST Küthe, Harald (KuetheH) 
corrected strapping
Revision 1.12 2008/05/08 09:47:42CEST Küthe, Harald (KuetheH) 
added ReferenceUnusedParameter() which can be used to avoid compiler warnings about unused function parameters
Revision 1.11 2008/05/07 14:00:58CEST Küthe, Harald (KuetheH) 
added workarond for conflicting types with TI osek.h
Revision 1.10 2008/05/05 13:16:17CEST Küthe, Harald (KuetheH) 
.#70673:5hku050508. merge: QAC fixes, add Autosar compatible basic types
Revision 1.9 2008/03/17 11:53:35CET Günther, Karsten (guenther) 
Merge of MS restructuring for 2008CW14. PC support removed.
Revision 1.8 2007/07/20 13:58:10CEST guenther 
.#35185:1kg200707. Define 'Global_static' added for simulation support.
Revision 1.7 2005/06/10 15:19:40CEST kleineberg 
.#13625:3skl100605. new type wheel_velocity_s32bit_t for CFG_UNLIMITED_VELOCITY_BFU
Revision 1.6 2005/02/09 14:54:50CET guzijan 
Code cleanup: all TEM-Tools put and create entries removed
Revision 1.5 2003/12/16 17:30:43CET braumann 
.#6294:7mbr101203.: improve time stamp measurement
Revision 1.4 2003/02/12 15:17:07CET sabine 
3955:1 merge .!b001smi110302. from 2000CW16 to MKS (32 bit wheel velocities instead of 16 bit)
Revision 1.3 2002/11/04 16:37:19CET braumann 
.#b002mbr301002.:2737:1: implementation of inline functioning in base_type.he 
for global usage
Revision 1.2 2002/08/27 10:13:20CEST regh 
.#b001mre270802.:1799:1 Add log entries into all BFU sources
==================================================================*/
/* EOF */
