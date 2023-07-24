/*! \file **********************************************************************

  COMPANY:                Continental Automotive

  PROJECT:                MFC300

  CPU:                    MPC5673

  PACKAGE:                MEAS

  MODULNAME:              meas_ext.h

  DESCRIPTION:         	  External interface functions of measurement interface

  AUTHOR:                 Matthias Limbrunner (b-plus GmbH)

  CREATION DATE:          27.09.2010

  VERSION:                $Revision: 1.1 $

                  
  ---*/ /*---
  CHANGES:                $Log: meas_ext.h  $
  CHANGES:                Revision 1.1 2021/12/13 17:24:43CET Wang, David (Wangd3) 
  CHANGES:                Initial revision
  CHANGES:                Member added to project /ADAS/Projects/MFC5xx/MFC5J3/06_Algorithm/DPU/04_Engineering/01_Source_Code/GIA_sim/sim_swc_wrapper/Include/mfc310_common/project.pj
  CHANGES:                Revision 1.0 2017/03/03 10:35:41CET Sorge, Sven (uidg3181) 
  CHANGES:                Initial revision
  CHANGES:                Member added to project /ADAS/SW/Integration/06_Simulation_Components/GIA_GenericInterfaceAdapter/04_Engineering/03_Workspace/Component_Workspace/GIA_sim/sim_swc_wrapper/Include/mfc310_common/project.pj
  CHANGES:                Revision 1.1 2014/03/13 15:11:16CET Sorge, Sven (uidg3181) 
  CHANGES:                Initial revision
  CHANGES:                Member added to project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/ETK_EngineeringToolKit/04_Engineering/GIA_GenericInterfaceAdapter/04_Engineering/03_Workspace/algo/gia_sim/wrapper/Include/mfc310_common/project.pj
  CHANGES:                Revision 1.8 2012/08/02 12:42:50CEST Nagy, Zsolt (uidt4723) 
  CHANGES:                Return type of MEASGetBuffer changed to 16bit pointer.
  CHANGES:                --- Added comments ---  uidt4723 [Aug 2, 2012 12:42:53 PM CEST]
  CHANGES:                Change Package : 137037:1 http://mks-psad:7002/im/viewissue?selection=137037
  CHANGES:                Revision 1.7 2012/07/10 17:59:46CEST Limbrunner-EXT, Matthias (x-limbrunnem) 
  CHANGES:                Added return code
  CHANGES:                --- Added comments ---  x-limbrunnem [Jul 10, 2012 5:59:46 PM CEST]
  CHANGES:                Change Package : 98927:1 http://mks-psad:7002/im/viewissue?selection=98927
  CHANGES:                Revision 1.6 2012/06/28 09:28:37CEST Limbrunner-EXT, Matthias (x-limbrunnem) 
  CHANGES:                Removed QAC findings
  CHANGES:                --- Added comments ---  x-limbrunnem [Jun 28, 2012 9:28:38 AM CEST]
  CHANGES:                Change Package : 98927:1 http://mks-psad:7002/im/viewissue?selection=98927
  CHANGES:                Revision 1.5 2012/05/03 16:02:49CEST Nagy, Zsolt (uidt4723) 
  CHANGES:                Added functions to gain acces to MEAS buffer.
  CHANGES:                Implemented in meas.c revision 1.28.
  CHANGES:                --- Added comments ---  uidt4723 [May 3, 2012 4:02:50 PM CEST]
  CHANGES:                Change Package : 100434:1 http://mks-psad:7002/im/viewissue?selection=100434
  CHANGES:                Revision 1.4 2011/05/01 15:56:34CEST Limbrunner-EXT, Matthias (x-limbrunnem) 
  CHANGES:                Introduced asynchronous call of measurement interface
  CHANGES:                -> performed asynchronously on level of measurement task
  CHANGES:                -> using callback function
  CHANGES:                --- Added comments ---  x-limbrunnem [May 1, 2011 3:56:34 PM CEST]
  CHANGES:                Change Package : 61316:2 http://mks-psad:7002/im/viewissue?selection=61316
  CHANGES:                Revision 1.3 2010/10/26 17:37:19CEST Perske Lars (uidk7799) (uidk7799) 
  CHANGES:                Added MEAS_DEFAULT_CYCLE_ID
  CHANGES:                --- Added comments ---  uidk7799 [Oct 26, 2010 5:37:19 PM CEST]
  CHANGES:                Change Package : 52444:1 http://mks-psad:7002/im/viewissue?selection=52444
  CHANGES:                Revision 1.2 2010/10/01 11:42:41CEST Perske Lars (uidk7799) (uidk7799) 
  CHANGES:                Added member
  CHANGES:                --- Added comments ---  uidk7799 [Oct 1, 2010 11:42:42 AM CEST]
  CHANGES:                Change Package : 46207:1 http://mks-psad:7002/im/viewissue?selection=46207

**************************************************************************** */
#ifndef MEAS_EXT_INC
#define MEAS_EXT_INC

/**
  @defgroup MEAS Measurement interface

  The MEAS component passes measurement data of other components to the measurement
  interface for development purposes.
        
@{ */ 

/*****************************************************************************
  INCLUDES
*****************************************************************************/
#include "glob_type.h"

/*****************************************************************************
  MACROS 
*****************************************************************************/

/*****************************************************************************
  TYPEDEFS 
*****************************************************************************/

typedef uint8  MEASFuncCount_t;
typedef uint8  MEASFuncID_t;
typedef uint8  MEASFuncChannelID_t;

typedef uint32 MEASVirtualAdress_t;
typedef uint32 MEASLength_t;

/*! Detailed header information of measurement data */
typedef struct
{
  MEASVirtualAdress_t VirtualAddress; /*!< Location of data in virtual address space */
  MEASLength_t        Length;         /*!< Length of data in bytes */
  MEASFuncID_t        FuncID;         /*!< Identifier of data source */
  MEASFuncChannelID_t FuncChannelID;  /*!< Data classification (e.g. input, output) */
}MEASInfo_t;

typedef void (*MEAS_Callback_t)(void);

/*! Return values of interface functions */
typedef enum
{
  MEAS_OK                = 0u, /*!< No error */
  MEAS_FULL_BUFFER       = 1u, /*!< Error: Data buffer is full */
  MEAS_NO_RESOURCE       = 2u, /*!< Error: No OSEK resource could be occupied */
  MEAS_TRANSMIT_ERROR    = 3u, /*!< Error: Transmission of data impossible */
  MEAS_NO_INIT           = 4u, /*!< Error: MEAS not initialized */
  MEAS_CB_NOT_REGISTERED = 5u, /*!< Error: No buffer for callback available */
  MEAS_INVALID_INFO      = 6u, /*!< Error: Invalid pointer to MTS info */
  MEAS_INVALID_POINTER   = 7u  /*!< Error: Invalid pointer to MTS data */
}MEASReturn_t;

typedef MEASReturn_t (*MeasHdlr_t)(const MEASInfo_t *, void *, MEAS_Callback_t );

/*****************************************************************************
  (SYMBOLIC) CONSTANTS 
*****************************************************************************/
/*! Component Software Version */
/*! 3 bytes in BCD format (00, 01, 02, ..., 09, 10 ...99). 
    e.g.: 0x010203 => Version 1.2.3 => main version = 1, sub version = 2, Bugfix level = 3 */

/*! 01.00.00  Initial revision <BR>
    01.00.01  xxx
 */
#define MEAS_SW_VERSION_NUMBER  (0x010000uL)

/*! cycle ID for MCU (default) */
#define MEAS_DEFAULT_CYCLE_ID   (61u)
/*! cycle ID for measurement interface */
#define MEAS_MEAS_CYCLE_ID      (62u)
/*! cycle ID for vehicle dynamics */
#define MEAS_VDY_CYCLE_ID       (20u)
/*! cycle ID for lane detection */
#define MEAS_LD_ALGO_CYCLE_ID   (49u)
/*! cycle ID for state freeze of lane detection */
#define MEAS_LD_STATE_CYCLE_ID  (53u)
/*! cycle ID for verified lane */
#define MEAS_VLN_CYCLE_ID       (81u)

/*****************************************************************************
  VARIABLES 
*****************************************************************************/

/*****************************************************************************
  FUNCTIONS 
*****************************************************************************/
/* Interface functions for users of measurement interface */
extern MEASReturn_t    MEASFreezeDataMTS(const MEASInfo_t *pInfo, void *pData, MEAS_Callback_t Callback);

extern MEASFuncCount_t MEASGetFuncCycle(const MEASFuncID_t FuncID);
extern void            MEASStartFuncCycle(const MEASFuncID_t FuncID);

extern MEASReturn_t    MEASRegisterCallback(const MEAS_Callback_t Callback);
extern MEASReturn_t    MEASUnregisterCallback(const MEAS_Callback_t Callback);

/* Interface functions for system cycle */
extern void MEASCycleStartNotification(const MEASFuncCount_t CycleCount);

/* Interface functions for RTE */
extern void MEASTaskFunc(void);

/* Functions to gain acces to MEAS buffer */
extern uint16* MEASGetBufferAddress(void);
extern void    MEASDeactivate(void);

#endif /* #ifndef MEAS_EXT_INC */

/** @} end defgroup */

