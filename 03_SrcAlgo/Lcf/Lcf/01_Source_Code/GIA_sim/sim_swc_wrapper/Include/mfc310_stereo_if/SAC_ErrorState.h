/*! \file **********************************************************************

  COMPANY:           Continental, A.D.C. GmbH

  COMPONENT:         SAC

  MODULNAME:         SAC_ErrorState.h

  DESCRIPTION:       definition of error entry ids
  
  CREATION DATE:     01.09.2011

  VERSION:           $Revision: 1.1 $

  CHANGES:                

  ---*/ /*---

 CHANGE:                 $Log: SAC_ErrorState.h  $
 CHANGE:                 Revision 1.1 2021/12/13 17:26:25CET Wang, David (Wangd3) 
 CHANGE:                 Initial revision
 CHANGE:                 Member added to project /ADAS/Projects/MFC5xx/MFC5J3/06_Algorithm/DPU/04_Engineering/01_Source_Code/GIA_sim/sim_swc_wrapper/Include/mfc310_stereo_if/project.pj
 CHANGE:                 Revision 1.0 2017/03/03 10:37:31CET Sorge, Sven (uidg3181) 
 CHANGE:                 Initial revision
 CHANGE:                 Member added to project /ADAS/SW/Integration/06_Simulation_Components/GIA_GenericInterfaceAdapter/04_Engineering/03_Workspace/Component_Workspace/GIA_sim/sim_swc_wrapper/Include/mfc310_stereo_if/project.pj
 CHANGE:                 Revision 1.1 2014/03/13 15:12:55CET Sorge, Sven (uidg3181) 
 CHANGE:                 Initial revision
 CHANGE:                 Member added to project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/ETK_EngineeringToolKit/04_Engineering/GIA_GenericInterfaceAdapter/04_Engineering/03_Workspace/algo/gia_sim/wrapper/Include/mfc310_stereo_if/project.pj
 CHANGE:                 Revision 1.7 2012/10/11 16:37:18CEST Garcia, Lucien (uid26778) 
 CHANGE:                 Add first sac error
 CHANGE:                 --- Added comments ---  uid26778 [Oct 11, 2012 4:37:18 PM CEST]
 CHANGE:                 Change Package : 161044:2 http://mks-psad:7002/im/viewissue?selection=161044
 CHANGE:                 Revision 1.6 2012/06/20 15:23:10CEST Stache, Nicolaj (uidt6711) 
 CHANGE:                 mod: new error category Calibration World added
 CHANGE:                 --- Added comments ---  uidt6711 [Jun 20, 2012 3:23:10 PM CEST]
 CHANGE:                 Change Package : 67326:3 http://mks-psad:7002/im/viewissue?selection=67326
 CHANGE:                 Revision 1.2 2012/06/18 16:15:45CEST Garcia, Lucien (uid26778) 
 CHANGE:                 Add SAC_ERR_CALIBRATION_WORLD DEM error
 CHANGE:                 --- Added comments ---  uid26778 [Jun 18, 2012 4:15:45 PM CEST]
 CHANGE:                 Change Package : 123892:1 http://mks-psad:7002/im/viewissue?selection=123892
 CHANGE:                 Revision 1.1 2012/05/25 15:53:53CEST Stache, Nicolaj (uidt6711) 
 CHANGE:                 Initial revision
 CHANGE:                 Member added to project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/SAC_StereoAutoCalibration/04_Engineering/01_Source_Code/Kernel/project.pj
 CHANGE:                 Revision 1.5 2012/02/14 12:31:52CET Stache, Nicolaj (uidt6711) 
 CHANGE:                 update
 CHANGE:                 --- Added comments ---  uidt6711 [Feb 14, 2012 12:31:53 PM CET]
 CHANGE:                 Change Package : 67326:3 http://mks-psad:7002/im/viewissue?selection=67326
 CHANGE:                 Revision 1.4 2012/01/24 20:47:57CET Stache Nicolaj (uidt6711) (uidt6711) 
 CHANGE:                 4.4.0 interface freeze update
 CHANGE:                 --- Added comments ---  uidt6711 [Jan 24, 2012 8:47:58 PM CET]
 CHANGE:                 Change Package : 67326:3 http://mks-psad:7002/im/viewissue?selection=67326
 CHANGE:                 Revision 1.3 2011/09/20 15:24:47CEST Garcia Lucien (uid26778) (uid26778) 
 CHANGE:                 ADD DEM error when SAC rectification is not good in fine mode
 CHANGE:                 --- Added comments ---  uid26778 [Sep 20, 2011 3:24:47 PM CEST]
 CHANGE:                 Change Package : 77279:1 http://mks-psad:7002/im/viewissue?selection=77279
 CHANGE:                 Revision 1.2 2011/09/20 13:36:06CEST Garcia Lucien (uid26778) (uid26778) 
 CHANGE:                 Add errors in case of bad rectification quality for FOD, POD, SLNE and PV functions
 CHANGE:                 --- Added comments ---  uid26778 [Sep 20, 2011 1:36:06 PM CEST]
 CHANGE:                 Change Package : 77279:1 http://mks-psad:7002/im/viewissue?selection=77279
 CHANGE:                 Revision 1.1 2011/09/02 17:12:29CEST Garcia Lucien (uid26778) (uid26778) 
 CHANGE:                 Initial revision
 CHANGE:                 Member added to project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/SAC_StereoAutoCalibration/04_Engineering/01_Source_Code/common/project.pj
**************************************************************************** */

#ifndef _SAC_ERRORSTATE_H_
#define _SAC_ERRORSTATE_H_     

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
  SAC_ERROR_CHECK_NOT_DONE         = 0,  /*!< status of error unknown, i.e. error was not (completely) checked */
  SAC_ERROR_CHECK_DONE_AND_PASSED  = 1,  /*!< error did not occur */
  SAC_ERROR_CHECK_DONE_AND_FAILED  = 2   /*!< error did occur */
} SAC_ErrorStatus_t;

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
  SAC_ERROR_PARAMETER             = 0,  /*!< = 0, error group: parameter --> error occurred during init */
  SAC_ERROR_BLOCKAGE              = 1,  /*!< = 1, error group: blockage */
  SAC_ERROR_VEHICLE_DATA          = 2,  /*!< = 2, error group: error in vehicle input data */
  SAC_ERROR_IMAGE_DATA            = 3,  /*!< = 3, error group: error in image input data */
  SAC_ERROR_CALIBRATION           = 4,  /*!< = 4, error group: error in calibration input */
  SAC_ERROR_INPUT                 = 5,  /*!< = 5, error group: (other) input error*/
  SAC_ERROR_SOFTWARE              = 6,  /*!< = 6, error group: software */
  //SAC_ERROR_FATAL                 = 7,  /*!< = 7, error group: fatal, e.g. HW-error */
  SAC_ERROR_OUTPUT                = 8,  /*!< = 8, error group: (other) input error*/
  SAC_ERROR_SAC_FINE_OUT_OF_RANGE = 9,  /*!< = 9, error group: rectification error is too big for fine calibration */
  SAC_ERROR_EOL_UPDATE            = 15,
  SAC_ERROR_DISTTEST              = 16,
  SAC_ERR_CALIBRATION_WORLD       = 17, 
  /////////////// ERROR FOR OTHERS FUNCTIONS /////////////////////////////////////
  SAC_ERROR_FOD_DISP_QUALITY      = 10, /*!< = 10, error group: rectification quality not enough good for FOD */
  SAC_ERROR_POD_DISP_QUALITY      = 11, /*!< = 11, error group: rectification quality not enough good for POD */
  SAC_ERROR_SLNE_DISP_QUALITY     = 12, /*!< = 12, error group: rectification quality not enough good for SLNE */
  SAC_ERROR_PV_DISP_QUALITY       = 13, /*!< = 13, error group: rectification quality not enough good for PV */
  SAC_ERROR_FIRST_ERROR           = 14, /*!< = 14, error group: First SAC error */
  SAC_NUM_ERROR_LIST_ENTRIES      = 18  /*!< = 18, pseudo entry for number of errors */

} SAC_ErrorId_t;

/*!
 * definition of external error list entry type
 */
typedef struct
{
  SAC_ErrorStatus_t status;      /*!< status of error */
  ui32_t           optData;	    /*!< optional data */
} SAC_Error_t;

/*!
 * definition of external error list
 */
typedef struct
{
  SAC_Error_t     error[SAC_NUM_ERROR_LIST_ENTRIES];  /*!< error entries, indexed by SACErrorId_t defined above */
} SAC_OutputErrors_t;


/*!
 * definition of algo state type
 */
typedef enum
{
  SAC_STATE_NOT_INITIALIZED     = 0,  /*!< algo has not been initialized yet, state before init() function */
  SAC_STATE_RUNNING	            = 1,  /*!< algo has been initialized and is running fine */
  SAC_STATE_TEMP_NOT_AVAILABLE  = 2,  /*!< algo has been initialized but is temporarily not available */
  SAC_STATE_FAILURE             = 3   /*!< algo is in failure mode, needs to be reinitialized by frame SW */
} SAC_State_t;

/*!
 * definition of system info type
 * this structure is passed to algo init() and run() functions as output argument, algo updates it at each call.
 * e.g. init(..., SAC_SystemInfo_t *sysInfo, ...);
 */
typedef struct
{
  SAC_OutputErrors_t	  errors;
  SAC_State_t          state;
} SAC_SystemInfo_t;


#ifdef __cplusplus
 }
#endif

#endif /* _SAC_ERRORSTATE_H_ */

