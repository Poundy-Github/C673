/*! \file **********************************************************************

  COMPANY:           Continental, A.D.C. GmbH

  COMPONENT:         Error handling SFOD

  MODULNAME:         sfod_errorState.h

  DESCRIPTION:       definition of error entry ids
  
  CREATION DATE:     01.09.2011

  VERSION:           $Revision: 1.1 $

  CHANGES:                

  ---*/ /*---

 CHANGE:                 $Log: sfod_errorState.h  $
 CHANGE:                 Revision 1.1 2021/12/13 17:26:25CET Wang, David (Wangd3) 
 CHANGE:                 Initial revision
 CHANGE:                 Member added to project /ADAS/Projects/MFC5xx/MFC5J3/06_Algorithm/DPU/04_Engineering/01_Source_Code/GIA_sim/sim_swc_wrapper/Include/mfc310_stereo_if/project.pj
 CHANGE:                 Revision 1.0 2017/03/03 10:37:32CET Sorge, Sven (uidg3181) 
 CHANGE:                 Initial revision
 CHANGE:                 Member added to project /ADAS/SW/Integration/06_Simulation_Components/GIA_GenericInterfaceAdapter/04_Engineering/03_Workspace/Component_Workspace/GIA_sim/sim_swc_wrapper/Include/mfc310_stereo_if/project.pj
 CHANGE:                 Revision 1.1 2014/03/13 15:12:59CET Sorge, Sven (uidg3181) 
 CHANGE:                 Initial revision
 CHANGE:                 Member added to project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/ETK_EngineeringToolKit/04_Engineering/GIA_GenericInterfaceAdapter/04_Engineering/03_Workspace/algo/gia_sim/wrapper/Include/mfc310_stereo_if/project.pj
 CHANGE:                 Revision 1.10 2012/07/26 14:57:48CEST Bachmann, Alexander (uidt5584) 
 CHANGE:                 Functional Review Comments of Priority 1 analyzed and fixed in agreement with B.Ramirez (only comments, no code changes)
 CHANGE:                 --- Added comments ---  uidt5584 [Jul 26, 2012 2:57:48 PM CEST]
 CHANGE:                 Change Package : 141706:1 http://mks-psad:7002/im/viewissue?selection=141706
 CHANGE:                 Revision 1.9 2012/07/05 14:48:31CEST Vogel-EXT, Oliver (uidu7284) 
 CHANGE:                 Code Review (Stein/Vogel)
 CHANGE:                 --- Added comments ---  uidu7284 [Jul 5, 2012 2:48:31 PM CEST]
 CHANGE:                 Change Package : 125408:1 http://mks-psad:7002/im/viewissue?selection=125408
 CHANGE:                 Revision 1.8 2011/12/16 10:49:51CET Bachmann, Alexander (uidt5584) 
 CHANGE:                 removed :  warning #230-D: trailing comma is nonstandard
 CHANGE:                 --- Added comments ---  uidt5584 [Dec 16, 2011 10:49:52 AM CET]
 CHANGE:                 Change Package : 52130:10 http://mks-psad:7002/im/viewissue?selection=52130
 CHANGE:                 Revision 1.7 2011/09/15 11:36:08CEST Bachmann, Alexander (uidt5584) 
 CHANGE:                 new state added; beautifying
 CHANGE:                 --- Added comments ---  uidt5584 [Sep 15, 2011 11:36:08 AM CEST]
 CHANGE:                 Change Package : 52130:1 http://mks-psad:7002/im/viewissue?selection=52130
 CHANGE:                 Revision 1.6 2011/09/08 07:58:18CEST Ramirez-Araya Bernard (uid07705) (uid07705) 
 CHANGE:                 Added include of cct_type.h to enable usage of standard data type names.
 CHANGE:                 --- Added comments ---  uid07705 [Sep 8, 2011 7:58:18 AM CEST]
 CHANGE:                 Change Package : 74657:1 http://mks-psad:7002/im/viewissue?selection=74657
 CHANGE:                 Revision 1.5 2011/09/07 14:11:22CEST Ramirez-Araya Bernard (uid07705) (uid07705) 
 CHANGE:                 Restored serialization version numbers after loss in Revision 1.4 due to merge error
 CHANGE:                 --- Added comments ---  uid07705 [Sep 7, 2011 2:11:22 PM CEST]
 CHANGE:                 Change Package : 74657:1 http://mks-psad:7002/im/viewissue?selection=74657
 CHANGE:                 Revision 1.4 2011/09/07 14:03:28CEST Ramirez-Araya Bernard (uid07705) (uid07705) 
 CHANGE:                 Added SFOD Output category as well as a "no error" category needed in sfod_errors.h
 CHANGE:                 --- Added comments ---  uid07705 [Sep 7, 2011 2:03:28 PM CEST]
 CHANGE:                 Change Package : 74657:1 http://mks-psad:7002/im/viewissue?selection=74657
 CHANGE:                 Revision 1.3 2011/09/06 18:58:51CEST Bachmann Alexander (uidt5584) (uidt5584) 
 CHANGE:                 SERIALIZATION: added version number to systemInfo struct
 CHANGE:                 --- Added comments ---  uidt5584 [Sep 6, 2011 6:58:51 PM CEST]
 CHANGE:                 Change Package : 52130:1 http://mks-psad:7002/im/viewissue?selection=52130
 CHANGE:                 Revision 1.2 2011/09/05 17:18:07CEST Ramirez-Araya Bernard (uid07705) (uid07705) 
 CHANGE:                 Added category for Non-Error situations "SFOD_ERROR_NO_ERROR" in SFODErrorId_t. Needed in sfod_errors.h for special error values like i32_SFOD_NO_ERROR, i32_SFOD_IDLE, among others.
 CHANGE:                 --- Added comments ---  uid07705 [Sep 5, 2011 5:18:07 PM CEST]
 CHANGE:                 Change Package : 74657:1 http://mks-psad:7002/im/viewissue?selection=74657
 CHANGE:                 Revision 1.1 2011/09/01 17:36:43CEST Bachmann Alexander (uidt5584) (uidt5584) 
 CHANGE:                 Initial revision
 CHANGE:                 Member added to project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/SFOD_StereoFastObjectDetection/04_Engineering/01_Source_Code/common/project.pj
**************************************************************************** */

#ifndef _SFOD_ERRORSTATE_H_
#define _SFOD_ERRORSTATE_H_    

#include "common_interface_defines.h"
//-> B.Ramirez(uid07705)[2011/9/8, 7:54]:added header for using standard data type names
#include "cct_type.h"
//<- B.Ramirez(uid07705)[2011/9/8, 7:54]

#ifdef __cplusplus
extern "C" {
#endif

/*===========================*/
/*        DEFINES            */
/*===========================*/

/*===========================*/
/*        TYPEDEFS           */
/*===========================*/

/* -------------------- */
/* error output section */
/* -------------------- */

/*!
 * definition of external error check status type
 * check failed means that the check was performed and an error detected
 */
typedef enum
{
  SFOD_ERROR_CHECK_NOT_DONE         = 0,  /*!< = 0,status of error unknown, i.e. error was not (completely) checked */
  SFOD_ERROR_CHECK_DONE_AND_PASSED     ,  /*!< = 1,error did not occur */
  SFOD_ERROR_CHECK_DONE_AND_FAILED        /*!< = 2, error did occur */
} SFODErrorStatus_t;

/*!
 * definition of external error ids (basic categories; algo can define additional ones)
 * parameter: erroneous input parameter (static  "configuration" data)
 * blockage : function not available due to blockage
 * vehicle data : erroneous vehicle data input (speed, yaw rate, ...)
 * image data : erroneous image data (wrong size, timestamp delta too large/small, non-incrementing frame counter ...)
 * calibration: calibration data error (special case of input error since often encountered)
 * input: erroneous dynamic input data (other sources)
 * software: internal software error (index, pointer, function parameter etc.)
 * fatal: serious, non-recoverable error
 * NOTE: Assumption is that first error has value 0
 */
typedef enum
{
  SFOD_ERROR_PARAMETER        = 0,  /*!< = 0, error group: parameter --> error occurred during init */
  SFOD_ERROR_BLOCKAGE            ,  /*!< = 1, error group: blockage */
  SFOD_ERROR_VEHICLE_DATA        ,  /*!< = 2, error group: error in vehicle input data */
  SFOD_ERROR_IMAGE_DATA          ,  /*!< = 3, error group: error in image input data */
  SFOD_ERROR_CALIBRATION         ,  /*!< = 4, error group: error in calibration input */
  SFOD_ERROR_INPUT               ,  /*!< = 5, error group: (other) input error*/
  SFOD_ERROR_OUTPUT              ,  /*!< = 6, error group: output error*/
  SFOD_ERROR_SOFTWARE            ,  /*!< = 7, error group: software */
  SFOD_ERROR_FATAL               ,  /*!< = 8, error group: fatal, e.g. HW-error */
  // ~CodeReview ~ID:d812e77ecd9e2a7200948f2c418fb11f ~Reviewer:F.Stein/O.Vogel ~Date:7/4/2012 ~Priority:2 ~Comment:Dangerous! SFOD_NUM_ERROR_LIST_ENTRIES should be last entry in enum.//B.Ramirez(uid07705) [2012/7/25, 15:33]: Original Prio:1 New Prio:2 Reason:SFOD_NUM_LIST_ENTRIES is indeed not the last element of the list, but the end of the ERROR enumerators, therefore the implementation is OK. Still, the enum design can be improved to avoid confusion
  SFOD_NUM_ERROR_LIST_ENTRIES    ,  /*!< = 9, pseudo entry for number of errors */
  SFOD_ERROR_NO_ERROR               /*   =10, No error at all, needed by SFOD for SFOD_Error list initialization in sfod_errors.h*/
} SFODErrorId_t;

/*!
 * definition of external error list entry type
 */
static const ui32_t SFODError_VersionNumber = 1; /*!< version of structure SFODError_t */

typedef struct _SFODError_t
{
  DEFINE_VERSION_MEMBER(SFODError);

  SFODErrorStatus_t status;      /*!< status of error */
  ui32_t            optData;      /*!< optional data */
} SFODError_t;

/*!
 * definition of external error list
 */
static const ui32_t SFODOutputErrors_VersionNumber = 1; /*!< version of structure SFODOutputErrors_t */

typedef struct _SFODOutputErrors_t
{
  DEFINE_VERSION_MEMBER(SFODOutputErrors);

  // ~CodeReview ~ID:7850e82befca43d6993f3e4d2a7fd631 ~Reviewer:F.Stein/O.Vogel ~Date:7/5/2012 ~Priority:3 ~Comment:Array reserved too small. SFOD_NUM_ERROR_LIST_ENTRIES is not the size of the enum. Fix urgently!//B.Ramirez(uid07705) [2012/7/25, 15:35]: Original Prio:1 New Prio:3 Reason:SFOD_NUM_LIST_ENTRIES is indeed not the last element of the list, but the end of the ERROR enumerators, therefore the implementation is OK. Still, the enum design can be improved to avoid confusion
  SFODError_t     error[SFOD_NUM_ERROR_LIST_ENTRIES];  /*!< error entries, indexed by XXXErrorId_t defined above */
} SFODOutputErrors_t;


/*!
 * definition of algo state type
 */
typedef enum
{
  SFOD_STATE_NOT_INITIALIZED     = 0,  /*!< = 0, algo has not been initialized yet, state before init() function */
  SFOD_STATE_RUNNING                ,  /*!< = 1, algo has been initialized and is running fine */
  SFOD_STATE_TEMP_NOT_AVAILABLE     ,  /*!< = 2, algo has been initialized but is temporarily not available */
  SFOD_STATE_FAILURE                ,  /*!< = 3, algo is in failure mode, needs to be reinitialized by frame SW */
  SFOD_STATE_POSTRUN                   /*!< = 4, algo has been running in main cycle and is collecting PED relevant data in post run */
} SFODState_t;

/*!
 * definition of system info type
 * this structure is passed to algo init() and run() functions as output argument, algo updates it at each call.
 * e.g. init(..., XXXSystemInfo_t *sysInfo, ...);
 */
static const ui32_t SFODSystemInfo_VersionNumber = 1; /*!< version of structure SFODSystemInfo_t */
                                                    
typedef struct _SFODSystemInfo_t
{
  DEFINE_VERSION_MEMBER(SFODSystemInfo);

  SFODOutputErrors_t   errors;
  SFODState_t          state;
} SFODSystemInfo_t;


#ifdef __cplusplus
 }
#endif

#endif /* _SFOD_ERRORSTATE_H_ */

