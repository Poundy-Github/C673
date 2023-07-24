/*! \file **********************************************************************

  COMPANY:           Continental, A.D.C. GmbH

  COMPONENT:         SR - sign recognition

  MODULNAME:         sr_glob_type.h

  DESCRIPTION:       @brief definition of sr global types

  CREATION DATE:     12.04.2010

  VERSION:           $Revision: 1.1 $

  CHANGES:

  ---*/ /*---

 CHANGE:                 $Log: sr_glob_type.h  $
 CHANGE:                 Revision 1.1 2021/12/13 17:26:17CET Wang, David (Wangd3) 
 CHANGE:                 Initial revision
 CHANGE:                 Member added to project /ADAS/Projects/MFC5xx/MFC5J3/06_Algorithm/DPU/04_Engineering/01_Source_Code/GIA_sim/sim_swc_wrapper/Include/mfc310_sr/project.pj
 CHANGE:                 Revision 1.0 2017/03/03 10:37:23CET Sorge, Sven (uidg3181) 
 CHANGE:                 Initial revision
 CHANGE:                 Member added to project /ADAS/SW/Integration/06_Simulation_Components/GIA_GenericInterfaceAdapter/04_Engineering/03_Workspace/Component_Workspace/GIA_sim/sim_swc_wrapper/Include/mfc310_sr/project.pj
 CHANGE:                 Revision 1.1 2014/03/13 15:12:54CET Sorge, Sven (uidg3181) 
 CHANGE:                 Initial revision
 CHANGE:                 Member added to project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/ETK_EngineeringToolKit/04_Engineering/GIA_GenericInterfaceAdapter/04_Engineering/03_Workspace/algo/gia_sim/wrapper/Include/mfc310_sr/project.pj
 CHANGE:                 Revision 1.5 2012/06/29 16:23:05CEST Roth, Axel01 (rotha1) 
 CHANGE:                 added SRBool_t
 CHANGE:                 --- Added comments ---  rotha1 [Jun 29, 2012 4:23:07 PM CEST]
 CHANGE:                 Change Package : 54002:1 http://mks-psad:7002/im/viewissue?selection=54002
 CHANGE:                 Revision 1.4 2011/09/20 09:57:38CEST Zobel, Matthias (zobelm) 
 CHANGE:                 - updated doxygen comments
 CHANGE:                 --- Added comments ---  zobelm [Sep 20, 2011 9:57:38 AM CEST]
 CHANGE:                 Change Package : 78978:1 http://mks-psad:7002/im/viewissue?selection=78978
 CHANGE:                 Revision 1.3 2011/01/26 17:48:46CET Axel Roth (rotha1) 
 CHANGE:                 - added synchronization data for simulation
 CHANGE:                 --- Added comments ---  rotha1 [Jan 26, 2011 5:48:46 PM CET]
 CHANGE:                 Change Package : 57979:1 http://mks-psad:7002/im/viewissue?selection=57979
 CHANGE:                 Revision 1.2 2010/04/13 11:05:05MESZ mzobel 
 CHANGE:                 - adapted to use sr_glob_type.h instead of glob_type.he
 CHANGE:                 - many minor corrections
 CHANGE:                 --- Added comments ---  mzobel [2010/04/13 09:05:06Z]
 CHANGE:                 Change Package : 36262:3 http://LISS014:6001/im/viewissue?selection=36262
 CHANGE:                 Revision 1.1 2010/04/12 16:03:54CEST mzobel 
 CHANGE:                 Initial revision
 CHANGE:                 Member added to project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/SR_SignRecognition/04_Engineering/01_Source_Code/algo/sr/project.pj

**************************************************************************** */


#ifndef _SR_GLOB_TYPE_H_
#define _SR_GLOB_TYPE_H_

#if 1

#ifdef __cplusplus
extern "C" {
#endif

/*===========================*/
/*        INCLUDES           */
/*===========================*/

#if 1
#include "glob_type.h"    /* currently this file is just a wrapper for the external glob_type.h header */

typedef unsigned long long ui64_t;

/* 8 bit types cause several problems and in general dont have benefits. */
/* typedef ui8_t     bool_t; */

/* TODO: use this instead of int, replace the SR_TRUE/FALSE defines. */
#if 0
typedef enum
{
  SR_FALSE = 0,
  SR_TRUE  = 1
} SRBool_t;
#else
typedef int SRBool_t;
#endif

#else


/*! @description:   unsigned 8 bit value                           
@resolution: 8 bits @accuracy:                @unit: decimal     

@min:  0            @max: 255                 @refreshtime:         */

typedef unsigned char ui8_t;
/*! @description:   signed 8 bit value                           
                                                                       
@resolution: 8 bits @accuracy:                @unit: decimal           
                                                                       
@min:  -128         @max: 127                 @refreshtime:         */ 
typedef signed char i8_t;
/*! @description:   unsigned 16 bit value
                                                                       
@resolution:16 bits @accuracy:                @unit: decimal           
                                                                       
@min:  0            @max: 65535               @refreshtime:         */ 
typedef unsigned short ui16_t;
/*! @description:   signed 16 bit value                         
                                                                      
@resolution:16 bits @accuracy:                @unit: decimal          
                                                                      
@min:  -32768       @max: 32767               @refreshtime:         */
typedef signed short int i16_t;
/*! @description:   unsigned 32 bit value                    
                                                                       
@resolution:32 bits @accuracy:                @unit: decimal           
                                                                       
@min:  0            @max: 4294967295          @refreshtime:         */ 
typedef unsigned int ui32_t;
/*! @description:   signed 32 bit value                           
                                                                        
@resolution:32 bits @accuracy:                @unit: decimal            
                                                                        
@min:  -2147483648  @max: 2147483647          @refreshtime:         */  
typedef signed int i32_t;

typedef float f32_t;
typedef signed char    sc_t;
typedef double f64_t;
typedef unsigned int unsigned_int32_t;

typedef ui8_t     bool_t;

#endif


/*===========================*/
/*        TYPEDEFS           */
/*===========================*/

/* none yet */

#ifdef __cplusplus
 }
#endif

#endif

#endif /* _SR_GLOB_TYPE_H_ */
