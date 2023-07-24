/*! \file **********************************************************************

  COMPANY:        Continental AG

  PROJECT:        MFC300

  CPU:            

  COMPONENT:      SAC - Stereo Auto Calibration

  MODULNAME:      sac_math.h  

  DESCRIPTION:    maths classes

  AUTHOR:         J. Schmidt

  CREATION DATE:  22.07.2009

  VERSION:        $Revision: 1.1 $

  CHANGES:        $Log: sac_math_types.h  $
  CHANGES:        Revision 1.1 2021/12/13 17:24:36CET Wang, David (Wangd3) 
  CHANGES:        Initial revision
  CHANGES:        Member added to project /ADAS/Projects/MFC5xx/MFC5J3/06_Algorithm/DPU/04_Engineering/01_Source_Code/GIA_sim/sim_swc_wrapper/Include/project.pj
  CHANGES:        Revision 1.0 2017/03/03 10:35:31CET Sorge, Sven (uidg3181) 
  CHANGES:        Initial revision
  CHANGES:        Member added to project /ADAS/SW/Integration/06_Simulation_Components/GIA_GenericInterfaceAdapter/04_Engineering/03_Workspace/Component_Workspace/GIA_sim/sim_swc_wrapper/Include/project.pj
  CHANGES:        Revision 1.1 2014/03/13 15:11:08CET Sorge, Sven (uidg3181) 
  CHANGES:        Initial revision
  CHANGES:        Member added to project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/ETK_EngineeringToolKit/04_Engineering/GIA_GenericInterfaceAdapter/04_Engineering/03_Workspace/algo/gia_sim/wrapper/Include/project.pj
  CHANGES:        Revision 1.3 2011/11/14 16:07:50CET Spruck, Jochen (spruckj) 
  CHANGES:        Init the not learnd buffer entries of yaw angle object median buffer with the yaw angle of the temp model
  CHANGES:        --- Added comments ---  spruckj [Nov 14, 2011 4:07:50 PM CET]
  CHANGES:        Change Package : 87958:1 http://mks-psad:7002/im/viewissue?selection=87958
  CHANGES:        Revision 1.2 2011/09/29 10:43:18CEST Spruck Jochen (spruckj) (spruckj) 
  CHANGES:        Add ring buffer class, used by yaw angle delta mean
  CHANGES:        --- Added comments ---  spruckj [Sep 29, 2011 10:43:18 AM CEST]
  CHANGES:        Change Package : 79035:1 http://mks-psad:7002/im/viewissue?selection=79035
  CHANGES:        Revision 1.1 2011/09/20 14:38:58CEST Spruck Jochen (spruckj) (spruckj) 
  CHANGES:        Initial revision
  CHANGES:        Member added to project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/SAC_StereoAutoCalibration/04_Engineering/01_Source_Code/Kernel/project.pj
  CHANGES:        Revision 1.12 2011/07/26 15:55:46CEST Garcia Lucien (uid26778) (uid26778) 
  CHANGES:        mark safety relevant datas
  CHANGES:        --- Added comments ---  uid26778 [Jul 26, 2011 3:55:46 PM CEST]
  CHANGES:        Change Package : 67298:1 http://mks-psad:7002/im/viewissue?selection=67298
  CHANGES:        Revision 1.11 2011/07/25 19:00:19CEST Garcia Lucien (uid26778) (uid26778) 
  CHANGES:        Mark all safety relevant data and constant
  CHANGES:        --- Added comments ---  uid26778 [Jul 25, 2011 7:00:20 PM CEST]
  CHANGES:        Change Package : 67298:1 http://mks-psad:7002/im/viewissue?selection=67298
  CHANGES:        Revision 1.10 2011/05/30 16:54:29CEST Stache Nicolaj (uidt6711) (uidt6711) 
  CHANGES:        Mod: Heap sort for quality check criterion
  CHANGES:        --- Added comments ---  uidt6711 [May 30, 2011 4:54:29 PM CEST]
  CHANGES:        Change Package : 67326:2 http://mks-psad:7002/im/viewissue?selection=67326
  CHANGES:        Revision 1.9 2011/03/11 15:38:23CET Wagner Ulrich (uid04769) (uid04769) 
  CHANGES:        Bugfix: sqrt() was not defined on DSP
  CHANGES:        --- Added comments ---  uid04769 [Mar 11, 2011 3:38:23 PM CET]
  CHANGES:        Change Package : 37886:2 http://mks-psad:7002/im/viewissue?selection=37886
  CHANGES:        Revision 1.8 2011/02/28 14:06:08CET Stache Nicolaj (uidt6711) (uidt6711) 
  CHANGES:        ROI shift added
  CHANGES:        --- Added comments ---  uidt6711 [Feb 28, 2011 2:06:08 PM CET]
  CHANGES:        Change Package : 58788:1 http://mks-psad:7002/im/viewissue?selection=58788
  CHANGES:        Revision 1.7 2009/09/08 14:03:07CEST jschmidt 
  CHANGES:        replaced glob_type.he by cct_type.h
  CHANGES:        --- Added comments ---  jschmidt [2009/09/08 12:03:08Z]
  CHANGES:        Change Package : 26824:1 http://LISS014:6001/im/viewissue?selection=26824
  CHANGES:        --- Added comments ---  jschmidt [2009/09/08 12:03:08Z]
  CHANGES:        Change Package : 26824:1 http://LISS014:6001/im/viewissue?selection=26824
  CHANGES:        Revision 1.6 2009/08/20 10:14:02CEST Ulrich Wagner (uwagner) 
  CHANGES:        replaced #include "memory.h" by #include "string.h" (memory.h is unknown on DSP)
  CHANGES:        --- Added comments ---  uwagner [2009/08/20 08:14:02Z]
  CHANGES:        Change Package : 26829:1 http://LISS014:6001/im/viewissue?selection=26829
  CHANGES:        --- Added comments ---  uwagner [2009/08/20 08:14:02Z]
  CHANGES:        Change Package : 26829:1 http://LISS014:6001/im/viewissue?selection=26829
  CHANGES:        Revision 1.5 2009/07/29 17:35:11CEST jschmidt 
  CHANGES:        added code
  CHANGES:        --- Added comments ---  jschmidt [2009/07/29 15:35:12Z]
  CHANGES:        Change Package : 26824:1 http://LISS014:6001/im/viewissue?selection=26824
  CHANGES:        --- Added comments ---  jschmidt [2009/07/29 15:35:12Z]
  CHANGES:        Change Package : 26824:1 http://LISS014:6001/im/viewissue?selection=26824
  CHANGES:        Revision 1.4 2009/07/27 17:26:57CEST jschmidt 
  CHANGES:        code update
  CHANGES:        --- Added comments ---  jschmidt [2009/07/27 15:26:57Z]
  CHANGES:        Change Package : 26824:1 http://LISS014:6001/im/viewissue?selection=26824
  CHANGES:        --- Added comments ---  jschmidt [2009/07/27 15:26:57Z]
  CHANGES:        Change Package : 26824:1 http://LISS014:6001/im/viewissue?selection=26824
  CHANGES:        Revision 1.3 2009/07/23 15:48:55CEST jschmidt 
  CHANGES:        added cross and invert functions
  CHANGES:        --- Added comments ---  jschmidt [2009/07/23 13:48:55Z]
  CHANGES:        Change Package : 26824:1 http://LISS014:6001/im/viewissue?selection=26824
  CHANGES:        --- Added comments ---  jschmidt [2009/07/23 13:48:55Z]
  CHANGES:        Change Package : 26824:1 http://LISS014:6001/im/viewissue?selection=26824
  CHANGES:        Revision 1.2 2009/07/23 15:17:47CEST jschmidt 
  CHANGES:        updates
  CHANGES:        --- Added comments ---  jschmidt [2009/07/23 13:17:47Z]
  CHANGES:        Change Package : 26824:1 http://LISS014:6001/im/viewissue?selection=26824
  CHANGES:        --- Added comments ---  jschmidt [2009/07/23 13:17:47Z]
  CHANGES:        Change Package : 26824:1 http://LISS014:6001/im/viewissue?selection=26824
  CHANGES:        Revision 1.1 2009/07/22 17:22:54CEST jschmidt 
  CHANGES:        Initial revision
  CHANGES:        Member added to project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/SAC_StereoAutoCalibration/04_Engineering/01_Source_Code/Kernel/project.pj

**************************************************************************** */

#ifndef SAC_MATH_TYPES_H
#define SAC_MATH_TYPES_H


/*! Statistic measurement interval */ 
typedef struct {
  f32_t Sum;         /*!< Sum of samples */
  f32_t SqSum;       /*!< Square sum of samples */
  f32_t Volume;      /*!< Accumlated weights of samples */
  f32_t Mean;        /*!< Mean of samples */
  f32_t Dev;         /*!< Standard deviation of samples */
} SACStatInterval_t;

/*! Statistic measurement interval */ 
typedef struct {
  f32_t  *pBuffer;         /*!< Pointer to Buffer */
  i32_t  nBufferIndex;     /*!< Actuall Index of the Buffer */
  i32_t  nBufferLoad;      /*!< The load of the Buffer */
  ui32_t  nBufferSize;      /*!< Size of the Buffer */
} SACRingBuffer_t;

#endif /* SAC_MATH_TYPES_H */

