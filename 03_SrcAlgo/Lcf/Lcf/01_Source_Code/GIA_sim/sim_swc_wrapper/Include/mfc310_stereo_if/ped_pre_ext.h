/*! \file **********************************************************************

  COMPANY:        Continental AG

  PROJECT:        MFC300

  CPU:            

  COMPONENT:      PED - Pedestrian Recognition

  MODULNAME:      ped_pre_ext.h  

  DESCRIPTION:    input/output structure handling for PEDPre data

  AUTHOR:         Robert Thiel

  CREATION DATE:  20.01.2011

  VERSION:        $Revision: 1.1 $

  CHANGES:        $Log: ped_pre_ext.h  $
  CHANGES:        Revision 1.1 2021/12/13 17:26:25CET Wang, David (Wangd3) 
  CHANGES:        Initial revision
  CHANGES:        Member added to project /ADAS/Projects/MFC5xx/MFC5J3/06_Algorithm/DPU/04_Engineering/01_Source_Code/GIA_sim/sim_swc_wrapper/Include/mfc310_stereo_if/project.pj
  CHANGES:        Revision 1.0 2017/03/03 10:37:30CET Sorge, Sven (uidg3181) 
  CHANGES:        Initial revision
  CHANGES:        Member added to project /ADAS/SW/Integration/06_Simulation_Components/GIA_GenericInterfaceAdapter/04_Engineering/03_Workspace/Component_Workspace/GIA_sim/sim_swc_wrapper/Include/mfc310_stereo_if/project.pj
  CHANGES:        Revision 1.1 2014/03/13 15:12:58CET Sorge, Sven (uidg3181) 
  CHANGES:        Initial revision
  CHANGES:        Member added to project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/ETK_EngineeringToolKit/04_Engineering/GIA_GenericInterfaceAdapter/04_Engineering/03_Workspace/algo/gia_sim/wrapper/Include/mfc310_stereo_if/project.pj
  CHANGES:        Revision 1.27 2012/04/23 10:48:13CEST Thiel, Robert (thielr) 
  CHANGES:        added HOG threshold for PEDPost
  CHANGES:        --- Added comments ---  thielr [Apr 23, 2012 10:48:13 AM CEST]
  CHANGES:        Change Package : 19018:5 http://mks-psad:7002/im/viewissue?selection=19018
  CHANGES:        Revision 1.26 2012/04/20 17:12:20CEST Thiel, Robert (thielr) 
  CHANGES:        fixes in IDIADA
  CHANGES:        --- Added comments ---  thielr [Apr 20, 2012 5:12:20 PM CEST]
  CHANGES:        Change Package : 60040:19 http://mks-psad:7002/im/viewissue?selection=60040
  CHANGES:        Revision 1.25.1.1 2012/04/12 16:15:10CEST Westhofen, Daniel (uidt2642) 
  CHANGES:        Added custom image brightness detection
  CHANGES:        --- Added comments ---  uidt2642 [Apr 12, 2012 4:15:13 PM CEST]
  CHANGES:        Change Package : 103896:1 http://mks-psad:7002/im/viewissue?selection=103896
  CHANGES:        Revision 1.25 2012/03/22 12:39:41CET Thiel, Robert (thielr) 
  CHANGES:        removed MISRA errors that couldn't be removed within the last release because of the interface freeze
  CHANGES:        --- Added comments ---  thielr [Mar 22, 2012 12:39:41 PM CET]
  CHANGES:        Change Package : 60040:18 http://mks-psad:7002/im/viewissue?selection=60040
  CHANGES:        Revision 1.24 2012/03/22 08:43:04CET Thiel, Robert (thielr) 
  CHANGES:        added u_HOGNorm_Blacklevel and u_HOGNorm_ShiftBits to pedpreoutputdata struct
  CHANGES:        --- Added comments ---  thielr [Mar 22, 2012 8:43:05 AM CET]
  CHANGES:        Change Package : 60040:18 http://mks-psad:7002/im/viewissue?selection=60040
  CHANGES:        Revision 1.23 2012/03/19 17:13:33CET Thiel, Robert (thielr) 
  CHANGES:        for 4.5
  CHANGES:        --- Added comments ---  thielr [Mar 19, 2012 5:13:33 PM CET]
  CHANGES:        Change Package : 60040:15 http://mks-psad:7002/im/viewissue?selection=60040
  CHANGES:        Revision 1.22 2012/03/01 09:24:45CET Bachmann, Alexander (uidt5584) 
  CHANGES:        removed superfluid switches
  CHANGES:        --- Added comments ---  uidt5584 [Mar 1, 2012 9:24:45 AM CET]
  CHANGES:        Change Package : 52130:1 http://mks-psad:7002/im/viewissue?selection=52130
  CHANGES:        Revision 1.21 2012/02/15 13:29:34CET Spruck, Jochen (spruckj) 
  CHANGES:        Change include header
  CHANGES:        --- Added comments ---  spruckj [Feb 15, 2012 1:29:34 PM CET]
  CHANGES:        Change Package : 98074:2 http://mks-psad:7002/im/viewissue?selection=98074
  CHANGES:        Revision 1.20 2011/10/06 13:06:21CEST Thiel, Robert (thielr) 
  CHANGES:        added interfaces to get default image
  CHANGES:        --- Added comments ---  thielr [Oct 6, 2011 1:06:21 PM CEST]
  CHANGES:        Change Package : 60040:13 http://mks-psad:7002/im/viewissue?selection=60040
  CHANGES:        Revision 1.19 2011/09/27 16:25:12CEST Thiel Robert (thielr) (thielr) 
  CHANGES:        added fpga cycle id from ped to make sure fpga results match ped inputs
  CHANGES:        --- Added comments ---  thielr [Sep 27, 2011 4:25:12 PM CEST]
  CHANGES:        Change Package : 60040:13 http://mks-psad:7002/im/viewissue?selection=60040
  CHANGES:        Revision 1.18 2011/09/20 11:18:58CEST Thiel Robert (thielr) (thielr) 
  CHANGES:        added lrf disparity information to memget function
  CHANGES:        --- Added comments ---  thielr [Sep 20, 2011 11:18:58 AM CEST]
  CHANGES:        Change Package : 60040:13 http://mks-psad:7002/im/viewissue?selection=60040
  CHANGES:        Revision 1.17 2011/09/08 10:18:48CEST Thiel Robert (thielr) (thielr) 
  CHANGES:        added new error
  CHANGES:        added new interface to get classifier information
  CHANGES:        Revision 1.16 2011/09/02 09:22:20CEST Thiel Robert (thielr) (thielr) 
  CHANGES:        added new error interface
  CHANGES:        added new 64 bit information to output
  CHANGES:        --- Added comments ---  thielr [Sep 2, 2011 9:22:20 AM CEST]
  CHANGES:        Change Package : 60040:12 http://mks-psad:7002/im/viewissue?selection=60040
  CHANGES:        Revision 1.15 2011/08/03 16:51:52CEST Thiel Robert (thielr) (thielr) 
  CHANGES:        removed MISRA warnings
  CHANGES:        Revision 1.14 2011/08/02 08:18:47CEST Thiel Robert (thielr) (thielr) 
  CHANGES:        changed member names of the patch (b_Valid, b_Used) -> b_ValidForPedPost, b_UsedForFPGA
  CHANGES:        --- Added comments ---  thielr [Aug 2, 2011 8:18:47 AM CEST]
  CHANGES:        Change Package : 60040:10 http://mks-psad:7002/im/viewissue?selection=60040
  CHANGES:        Revision 1.13 2011/07/25 15:00:34CEST Thiel Robert (thielr) (thielr) 
  CHANGES:        added valid flag to interface
  CHANGES:        Revision 1.12 2011/07/01 14:01:38CEST Thiel Robert (thielr) (thielr) 
  CHANGES:        corrected a comment
  CHANGES:        removed an unsued define
  CHANGES:        --- Added comments ---  thielr [Jul 1, 2011 2:01:39 PM CEST]
  CHANGES:        Change Package : 60040:10 http://mks-psad:7002/im/viewissue?selection=60040
  CHANGES:        Revision 1.11 2011/05/24 14:49:12CEST Thiel Robert (thielr) (thielr) 
  CHANGES:        changed image height to 448 due to alignment to 16 lines constraint
  CHANGES:        --- Added comments ---  thielr [May 24, 2011 2:49:13 PM CEST]
  CHANGES:        Change Package : 60040:9 http://mks-psad:7002/im/viewissue?selection=60040
  CHANGES:        Revision 1.10 2011/05/12 15:33:34CEST Thiel Robert (thielr) (thielr) 
  CHANGES:        added some properties for patches
  CHANGES:        --- Added comments ---  thielr [May 12, 2011 3:33:35 PM CEST]
  CHANGES:        Change Package : 60040:9 http://mks-psad:7002/im/viewissue?selection=60040
  CHANGES:        Revision 1.9 2011/05/12 11:09:41CEST Thiel Robert (thielr) (thielr) 
  CHANGES:        added fpga registers to set some parameters - Interface change for 2.5.1!
  CHANGES:        --- Added comments ---  thielr [May 12, 2011 11:09:42 AM CEST]
  CHANGES:        Change Package : 60040:8 http://mks-psad:7002/im/viewissue?selection=60040
  CHANGES:        Revision 1.8 2011/04/19 15:25:37CEST Thiel Robert (thielr) (thielr) 
  CHANGES:        added FPGA raw stream interface
  CHANGES:        --- Added comments ---  thielr [Apr 19, 2011 3:25:37 PM CEST]
  CHANGES:        Change Package : 60040:4 http://mks-psad:7002/im/viewissue?selection=60040
  CHANGES:        Revision 1.7 2011/04/18 13:59:33CEST Thiel Robert (thielr) (thielr) 
  CHANGES:        changed image height to 2.5 release
  CHANGES:        Revision 1.5 2011/04/07 11:13:27CEST Thiel Robert (thielr) (thielr) 
  CHANGES:        added 2 more constants for byte stream generation
  CHANGES:        Revision 1.4 2011/04/06 15:52:36CEST Thiel Robert (thielr) (thielr) 
  CHANGES:        removed dependencies
  CHANGES:        Revision 1.3 2011/04/06 15:50:07CEST Thiel Robert (thielr) (thielr) 
  CHANGES:        added interface to output version info
  CHANGES:        Revision 1.2 2011/03/17 10:42:23CET Thiel Robert (thielr) (thielr) 
  CHANGES:        removed FPGA output data since they will be created in the adapter
  CHANGES:        --- Added comments ---  thielr [Mar 17, 2011 10:42:23 AM CET]
  CHANGES:        Change Package : 60040:1 http://mks-psad:7002/im/viewissue?selection=60040
  
**************************************************************************** */

#ifndef PED_PRE_EXT_H
#define PED_PRE_EXT_H

#include "common_stereointerface_types.h"
#include "cct_type.h"
#include "ped_basetypes_ext.h"
#include "sfod_outputInterface.h"

#ifdef __cplusplus
  extern "C" {
#endif // __cplusplus

//! max allowed number of patches
#define PED_MAX_PATCHES (100U)

//! max allowed reference objects per patch
#define PED_MAX_REF_OBJECTS_PER_PATCH (10U)

//! max allowed number of FPGA register settings
#define PED_MAX_FPGA_REGISTERS (100U)

//! HOG classifier defines for border
#define PED_HOG_FPGA_SOBLE_XBORDER (2U)
#define PED_HOG_FPGA_SOBLE_YBORDER (2U)
#define PED_HOG_FPGA_NUM_XCELLS_PER_HYP (6U)
#define PED_HOG_FPGA_NUM_YCELLS_PER_HYP (12U)
#define PED_HOG_FPGA_NUM_XMINICELLS_PER_CELL (2U)
#define PED_HOG_FPGA_NUM_YMINICELLS_PER_CELL (4U)
#define PED_HOG_FPGA_NUM_XMINICELLS_PER_HYP  (PED_HOG_FPGA_NUM_XMINICELLS_PER_CELL * PED_HOG_FPGA_NUM_XCELLS_PER_HYP)
#define PED_HOG_FPGA_NUM_YMINICELLS_PER_HYP  (PED_HOG_FPGA_NUM_YMINICELLS_PER_CELL * PED_HOG_FPGA_NUM_YCELLS_PER_HYP)
#define PED_HOG_FPGA_NUM_XPIXELS_PER_MINICELL (4U)
#define PED_HOG_FPGA_NUM_YPIXELS_PER_MINICELL (2U)
#define PED_HOG_FPGA_MIN_NUM_XMINICELLS ((PED_HOG_FPGA_NUM_XCELLS_PER_HYP*PED_HOG_FPGA_NUM_XMINICELLS_PER_CELL)+(PED_HOG_FPGA_NUM_XMINICELLS_PER_CELL-1U))
#define PED_HOG_FPGA_MIN_NUM_YMINICELLS ((PED_HOG_FPGA_NUM_YCELLS_PER_HYP*PED_HOG_FPGA_NUM_YMINICELLS_PER_CELL)+(PED_HOG_FPGA_NUM_YMINICELLS_PER_CELL-1U))
#define PED_HOG_FPGA_MIN_NUM_XPIXELS ((PED_HOG_FPGA_MIN_NUM_XMINICELLS*PED_HOG_FPGA_NUM_XPIXELS_PER_MINICELL) + PED_HOG_FPGA_SOBLE_XBORDER)
#define PED_HOG_FPGA_MIN_NUM_YPIXELS ((PED_HOG_FPGA_MIN_NUM_YMINICELLS*PED_HOG_FPGA_NUM_YPIXELS_PER_MINICELL) + PED_HOG_FPGA_SOBLE_YBORDER)
#define PED_HOG_FPGA_MAX_NUM_XPIXELS ((((PED_HOG_FPGA_IMAGE_WIDTH - PED_HOG_FPGA_MIN_NUM_XPIXELS) / (PED_HOG_FPGA_NUM_XMINICELLS_PER_CELL * PED_HOG_FPGA_NUM_XPIXELS_PER_MINICELL)) * (PED_HOG_FPGA_NUM_XMINICELLS_PER_CELL * PED_HOG_FPGA_NUM_XPIXELS_PER_MINICELL)) + PED_HOG_FPGA_MIN_NUM_XPIXELS)
#define PED_HOG_FPGA_MAX_NUM_YPIXELS ((((PED_HOG_FPGA_IMAGE_HEIGHT- PED_HOG_FPGA_MIN_NUM_YPIXELS) / (PED_HOG_FPGA_NUM_YMINICELLS_PER_CELL * PED_HOG_FPGA_NUM_YPIXELS_PER_MINICELL)) * (PED_HOG_FPGA_NUM_YMINICELLS_PER_CELL * PED_HOG_FPGA_NUM_YPIXELS_PER_MINICELL)) + PED_HOG_FPGA_MIN_NUM_YPIXELS)
#define PED_HOG_FPGA_IMAGE_HEIGHT (448U)
#define PED_HOG_FPGA_IMAGE_WIDTH  (1024U)
#define PED_NR_OF_BYTES_PER_PATCH (16U)

static const ui32_t PEDPreDynamicInputData_VersionNumber = 2; /*!< Version Number of struct PEDPreDynamicInputData 
                                                                   2: added environmental data*/
/*! PEDPre dynamic input data*/   
typedef struct _PEDPre_t_DynamicInputData
{
  DEFINE_VERSION_MEMBER(PEDPreDynamicInputData);

  PED_t_MountingCalibrationData  MountRight;                /*!< transformation vehicle to right camera coordinate system */
  PED_t_RectifiedCalibrationData RectifiedCalibrationData;  /*!< camera parameters of rectified stereo system */

  PED_t_VehicleData              VehicleData;               /*!< vehicle data required by PEDPre */
  PED_t_ImageInformation         ImageInformation;          /*!< information of the image */

  PED_t_EnvironmentalData        EnvData;                   /*!< environmental data */

} PEDPre_t_DynamicInputData;


/*! defines one patch*/  
typedef struct _PEDPre_t_Patch
{
  ui16_t u_X0;                                        /*!< top left corner of the patch - X position @unit:pix*/
  ui16_t u_Y0;                                        /*!< top left corner of the patch - Y position @unit:pix*/
  ui16_t u_X1;                                        /*!< bottom right corner of the patch - X position @unit:pix*/
  ui16_t u_Y1;                                        /*!< bottom right corner of the patch - Y position @unit:pix*/  
  ui8_t  u_NrOfRefObjects;                            /*!< number of reference objects */
  ui32_t a_RefObject[PED_MAX_REF_OBJECTS_PER_PATCH];  /*!< SFOD object id list for this patch*/
  f32_t  f_Scale;                                     /*!< scale*/
  ui16_t u_NrOfHOGX;                                  /*!< the number of HOG results in X direction */
  ui16_t u_NrOfHOGY;                                  /*!< the number of HOG results in Y direction */
  ui16_t u_NrOfHOGTotal;                              /*!< the number of HOG results in this patch*/
  bool_t b_ValidForPedPost;                                     /*!< patch is valid after all checks */
  bool_t b_UsedForFPGA;                                      /*!< patch is used for FPGA classifier */
} PEDPre_t_Patch;

static const ui32_t PEDPreOutputData_VersionNumber = 6; /*!< Version Number of struct PEDPreOutputData 
                                                             3: added data valid flag
                                                             4: added u_CycleIDForFPGA
                                                             5: added u_HOGNorm_Blacklevel, u_HOGNorm_ShiftBits
                                                             6: added HOGThreshold*/

/*! PEDPre output data*/   
typedef struct _PEDPre_t_OutputData
{
  DEFINE_VERSION_MEMBER(PEDPreOutputData);

  ui64_t              u_Timestamp_usec;                       /*!< time stamp the data is connected to %unit:µs */

  ui32_t              u_NrOfUsedPatches;                      /*!< number of generated patches */
  PEDPre_t_Patch      Patch[PED_MAX_PATCHES];                 /*!< patches */

  ui32_t              u_NrOfValidRegisters;                   /*!< Nr of valid FPGA registers*/
  ui16_t              a_RegisterAddrValuePair[2*PED_MAX_FPGA_REGISTERS]; /*!< array of FPGA resiter settings (always a pair of address and value) --> [addr0, val0, addr1, val1, ..., addrn, valn]*/
  
  PED_t_eSignalState  e_DataValid;                            /*!< output data is valid?*/

  ui16_t              u_CycleIDForFPGA;                       /*!< Cycle ID for FPGA */
  
  ui16_t              u_HOGNorm_Blacklevel;                   /*!< Blacklevel value that needs to be substracted (saturated) from each pixel for HOG calculation*/
  ui16_t              u_HOGNorm_ShiftBits;                    /*!< bits each pixel value needs to be shifted (saturated) for HOG calculation*/
  f32_t               f_HOGThreshold;                         /*!< hog threshold */

} PEDPre_t_OutputData;


static const ui32_t PEDPrePatchesFPGAStream_VersionNumber = 1; /*!< Version Number of struct PEDPre_t_PatchesFPGAStream */
/*! PEDPre output data*/   
typedef struct _PEDPre_t_PatchesFPGAStream
{
  DEFINE_VERSION_MEMBER(PEDPrePatchesFPGAStream);

  ui8_t a_Stream[PED_NR_OF_BYTES_PER_PATCH * PED_MAX_PATCHES]; /*!< raw data stream for FPGA */
} PEDPre_t_PatchesFPGAStream;


//          u_ImgPosX  :
//                     :
//           ..........:..........................................................
//           |         :                Rectified Image                          |
//           |         :                                                         |
// u_ImshPosY|         :                                                         |
//       ...............------------.u                                           |
//           |         |   Image    |_                                           |
//           |         |            |I                                           |
//           |         |            |m                                           |
//           |         |            |g                                           |
//           |         |  a_Image   |H                                           |
//           |         |            |e                                           |
//           |         |            |i                                           |
//           |         |            |g                                           |
//           |         |            |h                                           |
//           |         `------------'t                                           |
//           |           u_ImgWidth                                              |
//           |                                                                   |
//           |                                                                   |
//           |                                                                   |
//           |                                                                   |
//           |                                                                   |
//           |                                                                   |
//           |                                                                   |
//           |                                                                   |
//           |...................................................................|
//           
static const ui32_t PEDPreDefaultImageInfo_VersionNumber = 1; /*!< Version Number of struct PEDPre_t_DefaultImageInfo */
/*! PEDPre output data*/   
typedef struct _PEDPre_t_DefaultImageInfo
{
  DEFINE_VERSION_MEMBER(PEDPreDefaultImageInfo);
  ui16_t u_ImgPosX;   /*!< x position of the top left corner of the image in the rectified image */
  ui16_t u_ImgPosY;   /*!< y position of the top left corner of the image in the rectified image */
  ui16_t u_ImgWidth;  /*!< width of the image*/
  ui16_t u_ImgHeight; /*!< height of the image*/
  ui16_t const *a_Image;    /*!< iamge data (16 bit greyscale data (x*y)*/
} PEDPre_t_DefaultImageInfo;

/***************************************************************************************************************************/



/* *****************************************************************************
@fn            PEDPreInit                                                    */ /*!
@description   initialize PEDPre algorithm with FW services

@param[in]     function pointers
@return        PED_eErrorCode_NoError or error code
@pre           -
@post          -
@author        Robert Thiel
**************************************************************************** */
extern PED_t_eErrorCode PEDPreInit(
    const Fct_v_CacheInvalidateAll pfct_v_CacheInvalidateAll,
    const Fct_sl_DMACopy           pfct_sl_DMACopy,
    const Fct_sl_DMACopy_2D        pfct_sl_DMACopy_2D,
    const Fct_sl_DMACopyChained    pfct_sl_DMACopyChained,
    const Fct_sl_DMAWait           pfct_sl_DMAWait,
    const Fct_sl_MEASFreeze        pfct_sl_MEASFreeze
);


/* *****************************************************************************
@fn            PEDPreOpen                                                    */ /*!
@description   open PEDPre algorithm

@param[in]     -
@return        PED_eErrorCode_NoError or error code
@pre           -
@post          -
@author        Robert Thiel
**************************************************************************** */
extern PED_t_eErrorCode PEDPreOpen(PEDSystemInfo_t *pPedSystemInfo);


/* *****************************************************************************
@fn            PEDPreRun                                          */ /*!
@description   run PEDPre algorithm

@param[in]     pDynInputData:  dynamic input data
@param[out]    pOutputData: output data to fill
@return        PED_eErrorCode_NoError or error code
@pre           -
@post          -
@author        Robert Thiel
**************************************************************************** */
extern PED_t_eErrorCode PEDPreRun(const PEDPre_t_DynamicInputData  *const p_DynInputData,
                                  const SFODOutputData_t           *const p_SFODOOutputData,						   
			                                  PEDPre_t_OutputData        *const p_OutputData,
                                        PEDPre_t_PatchesFPGAStream *const p_FPGAStream,
                                        PEDSystemInfo_t                  *pPedSystemInfo,
                                  const ui16_t                     *const p_Image); 



/* *****************************************************************************
@fn            PEDPreClose                                          */ /*!
@description   close PEDPre algorithm

@param[in]     -
@return        PED_eErrorCode_NoError or error code
@pre           -
@post          -
@author        Robert Thiel
**************************************************************************** */
extern PED_t_eErrorCode PEDPreClose(void);



/* **************************************************************************** 
@fn            PEDPreGetInternalState
@description   Acessor of PEDPre algorithm state data

               The framework software will make a memcopy of the current algo state after execution of 
               the run function and the state will be freezed in severals chunks over more than one frame. 
               The simulation will later on collect these chunks and provide an initialization vector for 
               the simulation of an algo component.

               This function can be called every cycle after the execution of the run function. Framework 
               software will make a memcpy of the state referenced in PV_AlgoState and freeze the data over 
               several frames. Once the full state is freezed the procedure starts again.

               The Integrators will moderate the discussion for each processor how large the algo states 
               are allowed to be (restircitions are memory bandwidth, measfreeze bandwidthm etc.


@return        PED_eErrorCode_NoError or error code

@pre           pp_PV_AlgoState points to a legal pointer variable

@post          return value is PED_eErrorCode_ZeroPointer or 
               return value is PED_eErrorCode_NoError and (*pp_PV_AlgoState) points to state data

@author        Robert Thiel
**************************************************************************** */
extern PED_t_eErrorCode PEDPreGetInternalState (const void ** pp_PV_AlgoState, ui32_t* u_Length);

/*! **************************************************************************** 
@fn            PEDGetAlgoVersion
@description   Acessor of pointer to persistent Algorithm Version Entity

               During the startup phase of the ECU the framework software will collect the version 
               information from each component. This version information is transmitted via the database 
               to the Golddust controller. GD will transmitt the collected information via MTS and 
               will make it available via diagosis.


@return        PED_eErrorCode_NoError or error code 

@pre           p_AlgoVersion points to a legal pointer variable

@post          *pAlgoVersion is the a valid PED_t_AlgoVersion instance
               representing data

@author        Robert Thiel
**************************************************************************** */
extern PED_t_eErrorCode PEDPreGetAlgoVersion( PED_t_AlgoVersion * const p_AlgoVersion );



/*************************************
fn:        PEDPreGetFPGAClassifier
FullName:  PEDPreGetFPGAClassifier
Access:    private 
Returns:   extern PED_t_eErrorCode
Qualifier: returns pointers and data counts of HOG/LRF/LRF Disparity classifier data --> to be sent to FPGA
Parameter: ui32_t * p_HogDataCnt
Parameter: ui32_t * a_HOGData
Parameter: ui32_t * p_LRFDataCnt
Parameter: ui32_t * a_LRFData
Parameter: ui32_t * p_LRFDisparityDataCnt
Parameter: ui32_t * a_LRFDisparityData
*************************************/
extern PED_t_eErrorCode PEDPreGetFPGAClassifier( ui32_t        * const p_HogDataCnt,
                                                 const ui32_t ** const a_HOGData,
                                                 ui32_t        * const p_LRFDataCnt,
                                                 const ui32_t ** const a_LRFData,
                                                 ui32_t        * const p_LRFDisparityDataCnt,
                                                 const ui32_t ** const a_LRFDisparityData );



/*************************************
fn:        PEDPreGetDefaultPedestrianData
FullName:  PEDPreGetDefaultPedestrianData
Access:    public 
Returns:   PED_t_eErrorCode
Qualifier: returns pedestrian default image including position information
Parameter: PEDPre_t_DefaultImageInfo * pDefaultImageInfo
*************************************/
extern PED_t_eErrorCode PEDPreGetDefaultPedestrianData(PEDPre_t_DefaultImageInfo  * const pDefaultImageInfo);

/*************************************
fn:        PEDPreGetDefaultPedestrianImageComlete
FullName:  PEDPreGetDefaultPedestrianImageComlete
Access:    public 
Returns:   PED_t_eErrorCode
Qualifier: writes default image into given memory - make sure to set image memory
Parameter: ui16_t * a_Image
Parameter: ui16_t u_ImgWidth
Parameter: ui16_t u_ImgHeight
*************************************/
extern PED_t_eErrorCode PEDPreGetDefaultPedestrianImageComplete(       ui16_t      * const a_Image,
                                                                 const ui16_t              u_ImgWidth,
                                                                 const ui16_t              u_ImgHeight );

#ifdef __cplusplus
  }
#endif // __cplusplus



#endif /* PED_PRE_EXT_H */

