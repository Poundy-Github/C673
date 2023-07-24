/*! \file **********************************************************************

  COMPANY:        Continental AG

  PROJECT:        MFC300

  CPU:            

  COMPONENT:      PED - Pedestrian Recognition

  MODULNAME:      ped_post_ext.h  

  DESCRIPTION:    input/output structure handling for PEDPost data

  AUTHOR:         Robert Thiel

  CREATION DATE:  20.01.2011

  VERSION:        $Revision: 1.1 $

  CHANGES:        $Log: ped_post_ext.h  $
  CHANGES:        Revision 1.1 2021/12/13 17:26:24CET Wang, David (Wangd3) 
  CHANGES:        Initial revision
  CHANGES:        Member added to project /ADAS/Projects/MFC5xx/MFC5J3/06_Algorithm/DPU/04_Engineering/01_Source_Code/GIA_sim/sim_swc_wrapper/Include/mfc310_stereo_if/project.pj
  CHANGES:        Revision 1.0 2017/03/03 10:37:29CET Sorge, Sven (uidg3181) 
  CHANGES:        Initial revision
  CHANGES:        Member added to project /ADAS/SW/Integration/06_Simulation_Components/GIA_GenericInterfaceAdapter/04_Engineering/03_Workspace/Component_Workspace/GIA_sim/sim_swc_wrapper/Include/mfc310_stereo_if/project.pj
  CHANGES:        Revision 1.1 2014/03/13 15:12:58CET Sorge, Sven (uidg3181) 
  CHANGES:        Initial revision
  CHANGES:        Member added to project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/ETK_EngineeringToolKit/04_Engineering/GIA_GenericInterfaceAdapter/04_Engineering/03_Workspace/algo/gia_sim/wrapper/Include/mfc310_stereo_if/project.pj
  CHANGES:        Revision 1.28 2012/04/02 17:07:56CEST Thiel, Robert (thielr) 
  CHANGES:        added new member f_DistanceTracked
  CHANGES:        --- Added comments ---  thielr [Apr 2, 2012 5:07:56 PM CEST]
  CHANGES:        Change Package : 60040:19 http://mks-psad:7002/im/viewissue?selection=60040
  CHANGES:        Revision 1.27 2012/03/30 07:50:47CEST Thiel, Robert (thielr) 
  CHANGES:        bugfix in version number of input data for pedpost
  CHANGES:        --- Added comments ---  thielr [Mar 30, 2012 7:50:47 AM CEST]
  CHANGES:        Change Package : 60040:18 http://mks-psad:7002/im/viewissue?selection=60040
  CHANGES:        Revision 1.26 2012/03/22 12:39:40CET Thiel, Robert (thielr) 
  CHANGES:        removed MISRA errors that couldn't be removed within the last release because of the interface freeze
  CHANGES:        --- Added comments ---  thielr [Mar 22, 2012 12:39:40 PM CET]
  CHANGES:        Change Package : 60040:18 http://mks-psad:7002/im/viewissue?selection=60040
  CHANGES:        Revision 1.25 2012/03/20 14:37:36CET Westhofen Daniel (uidt2642) (uidt2642) 
  CHANGES:        MISRA Fix
  CHANGES:        --- Added comments ---  uidt2642 [Mar 20, 2012 2:37:38 PM CET]
  CHANGES:        Change Package : 103896:1 http://mks-psad:7002/im/viewissue?selection=103896
  CHANGES:        Revision 1.24 2012/03/20 14:07:23CET Westhofen Daniel (uidt2642) (uidt2642) 
  CHANGES:        Interface-Change for 4.5 (Added GroupID, Priority)
  CHANGES:        --- Added comments ---  uidt2642 [Mar 20, 2012 2:07:24 PM CET]
  CHANGES:        Change Package : 103896:1 http://mks-psad:7002/im/viewissue?selection=103896
  CHANGES:        Revision 1.22.1.1 2012/03/09 15:06:38CET Thiel, Robert (thielr) 
  CHANGES:        modifications for mono pedestrian detection
  CHANGES:        --- Added comments ---  thielr [Mar 9, 2012 3:06:39 PM CET]
  CHANGES:        Change Package : 60040:17 http://mks-psad:7002/im/viewissue?selection=60040
  CHANGES:        Revision 1.22 2012/03/01 09:24:44CET Bachmann, Alexander (uidt5584) 
  CHANGES:        removed superfluid switches
  CHANGES:        --- Added comments ---  uidt5584 [Mar 1, 2012 9:24:44 AM CET]
  CHANGES:        Change Package : 52130:1 http://mks-psad:7002/im/viewissue?selection=52130
  CHANGES:        Revision 1.21 2012/02/14 16:40:58CET Thiel, Robert (thielr) 
  CHANGES:        minor code style changes
  CHANGES:        --- Added comments ---  thielr [Feb 14, 2012 4:40:58 PM CET]
  CHANGES:        Change Package : 60040:15 http://mks-psad:7002/im/viewissue?selection=60040
  CHANGES:        Revision 1.20 2011/11/14 11:23:20CET Mueller Reik (muellerr5) (muellerr5) 
  CHANGES:        - added u_CyclesToCollision to _PEDPost_t_StaticHyp
  CHANGES:        --- Added comments ---  muellerr5 [Nov 14, 2011 11:23:20 AM CET]
  CHANGES:        Change Package : 87961:1 http://mks-psad:7002/im/viewissue?selection=87961
  CHANGES:        Revision 1.19 2011/10/08 15:04:26CEST Thiel Robert (thielr) (thielr) 
  CHANGES:        added comments for PDO tool to make the 64 bit diag message readable
  CHANGES:        --- Added comments ---  thielr [Oct 8, 2011 3:04:26 PM CEST]
  CHANGES:        Change Package : 60040:13 http://mks-psad:7002/im/viewissue?selection=60040
  CHANGES:        Revision 1.18 2011/09/27 16:26:07CEST Thiel Robert (thielr) (thielr) 
  CHANGES:        changed order of critical zone enum to ensure to be equal to flexray
  CHANGES:        --- Added comments ---  thielr [Sep 27, 2011 4:26:07 PM CEST]
  CHANGES:        Change Package : 60040:13 http://mks-psad:7002/im/viewissue?selection=60040
  CHANGES:        Revision 1.17 2011/09/20 14:43:32CEST Thiel Robert (thielr) (thielr) 
  CHANGES:        bugfix in deserialization
  CHANGES:        --- Added comments ---  thielr [Sep 20, 2011 2:43:32 PM CEST]
  CHANGES:        Change Package : 60040:13 http://mks-psad:7002/im/viewissue?selection=60040
  CHANGES:        Revision 1.16 2011/09/20 09:01:56CEST Thiel Robert (thielr) (thielr) 
  CHANGES:        merge with 1.13.1.1
  CHANGES:        --- Added comments ---  thielr [Sep 20, 2011 9:01:56 AM CEST]
  CHANGES:        Change Package : 60040:13 http://mks-psad:7002/im/viewissue?selection=60040
  CHANGES:        Revision 1.15 2011/09/19 16:04:35CEST Mueller Reik (muellerr5) (muellerr5) 
  CHANGES:        - updated _PEDPost_t_StaticHyp (new quality measures)
  CHANGES:        --- Added comments ---  muellerr5 [Sep 19, 2011 4:04:35 PM CEST]
  CHANGES:        Change Package : 78002:1 http://mks-psad:7002/im/viewissue?selection=78002
  CHANGES:        Revision 1.14 2011/09/02 09:22:20CEST Thiel Robert (thielr) (thielr) 
  CHANGES:        added new error interface
  CHANGES:        added new 64 bit information to output
  CHANGES:        --- Added comments ---  thielr [Sep 2, 2011 9:22:20 AM CEST]
  CHANGES:        Change Package : 60040:12 http://mks-psad:7002/im/viewissue?selection=60040
  CHANGES:        Revision 1.13 2011/08/03 16:51:52CEST Thiel Robert (thielr) (thielr) 
  CHANGES:        removed MISRA warnings
  CHANGES:        Revision 1.12 2011/07/25 16:32:48CEST Thiel Robert (thielr) (thielr) 
  CHANGES:        added init call of static hyp in init of static data to ensure version info to be defined correctly
  CHANGES:        --- Added comments ---  thielr [Jul 25, 2011 4:32:49 PM CEST]
  CHANGES:        Change Package : 60040:10 http://mks-psad:7002/im/viewissue?selection=60040
  CHANGES:        Revision 1.11 2011/07/25 15:00:33CEST Thiel Robert (thielr) (thielr) 
  CHANGES:        added valid flag to interface
  CHANGES:        Revision 1.10 2011/07/25 13:00:03CEST Thiel Robert (thielr) (thielr) 
  CHANGES:        bugfix - need to set the number of used internal ped objects to 0 in init!
  CHANGES:        --- Added comments ---  thielr [Jul 25, 2011 1:00:03 PM CEST]
  CHANGES:        Change Package : 60040:10 http://mks-psad:7002/im/viewissue?selection=60040
  CHANGES:        Revision 1.9 2011/07/22 14:46:17CEST Thiel Robert (thielr) (thielr) 
  CHANGES:        Bugfix - added new member initialization
  CHANGES:        --- Added comments ---  thielr [Jul 22, 2011 2:46:17 PM CEST]
  CHANGES:        Change Package : 60040:10 http://mks-psad:7002/im/viewissue?selection=60040
  CHANGES:        Revision 1.8 2011/07/05 15:23:08CEST Thiel Robert (thielr) (thielr) 
  CHANGES:        added ped static data to interface and removed it from output data
  CHANGES:        added some more elements to output struct and static struct due to ped->fod backchannel
  CHANGES:        --- Added comments ---  thielr [Jul 5, 2011 3:23:08 PM CEST]
  CHANGES:        Change Package : 60040:10 http://mks-psad:7002/im/viewissue?selection=60040
  CHANGES:        Revision 1.7 2011/05/24 14:49:31CEST Thiel Robert (thielr) (thielr) 
  CHANGES:        added first "init" methodes instead of constructors
  CHANGES:        --- Added comments ---  thielr [May 24, 2011 2:49:31 PM CEST]
  CHANGES:        Change Package : 60040:9 http://mks-psad:7002/im/viewissue?selection=60040
  CHANGES:        Revision 1.6 2011/05/23 16:48:44CEST Thiel Robert (thielr) (thielr) 
  CHANGES:        added interface for 2.5.1
  CHANGES:        --- Added comments ---  thielr [May 23, 2011 4:48:45 PM CEST]
  CHANGES:        Change Package : 64290:1 http://mks-psad:7002/im/viewissue?selection=64290
  CHANGES:        Revision 1.5 2011/04/19 15:25:36CEST Thiel Robert (thielr) (thielr) 
  CHANGES:        added FPGA raw stream interface
  CHANGES:        --- Added comments ---  thielr [Apr 19, 2011 3:25:37 PM CEST]
  CHANGES:        Change Package : 60040:4 http://mks-psad:7002/im/viewissue?selection=60040
  CHANGES:        Revision 1.3 2011/04/06 15:50:07CEST Thiel Robert (thielr) (thielr) 
  CHANGES:        added interface to output version info
  CHANGES:        Revision 1.2 2011/03/17 10:42:22CET Thiel Robert (thielr) (thielr) 
  CHANGES:        removed FPGA output data since they will be created in the adapter
  CHANGES:        --- Added comments ---  thielr [Mar 17, 2011 10:42:23 AM CET]
  CHANGES:        Change Package : 60040:1 http://mks-psad:7002/im/viewissue?selection=60040
  
**************************************************************************** */

#ifndef PED_POST_EXT_H
#define PED_POST_EXT_H

#include "common_interface_defines.h"
#include "cct_type.h"
#include "ped_basetypes_ext.h"
#include "ped_pre_ext.h"

#ifdef __cplusplus
  extern "C" {
#endif // __cplusplus


/*!!!!!!!!!! BE AWARE, WHEN CHANGING THE CONSTANTS FOR OF THE ARRAY LENGTHS, YOU HAVE TO INCREASE THE VERSIONNUMBER OF THE STRUCTS !!!!!!!!!!!!!!*/

/*! max nr of output pedestrian information*/
#define PEDPOST_OUTPUT_MAX_HYPS (16U)

/*! max nr of reference objects per pedestrian hypothesis*/
#define PEDPOST_MAX_REF_OBJ     (8U)

/*! max number of classifier results*/
#define PED_MAX_RESULTS         (200)

/*! max number of FPGA header words */
#define PEDPOST_FPGA_STREAM_HEADER_CNT (64)

/*! max number of FPGA HOG elements */
#define PEDPOST_FPGA_STREAM_HOG_CNT    (10000)

/*! max number of FPGA LRF elements */
#define PEDPOST_FPGA_STREAM_LRF_CNT    (100)
/*! size of FPGA LRF element*/
#define PEDPOST_FPGA_STREAM_LRF_SIZE   (4)
    /*! size of FPGA LRF Disparity element*/
#define PEDPOST_FPGA_STREAM_LRF_DISP_SIZE (1)

/*! max number of FPGA trailer elements */
#define PEDPOST_FPGA_STREAM_TRAILER_CNT (100)

/*! size if the fpga return stream */
#define PEDPOST_FPGA_STREAM_LEN (PEDPOST_FPGA_STREAM_HEADER_CNT+PEDPOST_FPGA_STREAM_HOG_CNT+PEDPOST_FPGA_STREAM_LRF_CNT*PEDPOST_FPGA_STREAM_LRF_SIZE+PEDPOST_FPGA_STREAM_LRF_CNT*PEDPOST_FPGA_STREAM_LRF_DISP_SIZE+PEDPOST_FPGA_STREAM_TRAILER_CNT)

/*! default value for group id for SNA */
#define PEDPOST_GROUPID_SNA (15U)

/*! default value for group id for PED alone object */
#define PEDPOST_GROUPID_SINGLEPED (0U)

/*! max cycles to collision */
#define PEDPOST_MAX_CYC_TO_COLL (200U)


/*! structure for one result
    this structure is not under version control!*/
typedef struct _PEDPost_t_Result
{    
  ui32_t u_PatchNum;                                                        /*!< number of corresponding patch*/
  f32_t f_X0;                                                               /*!< top left corner of the patch - X position @unit:pix*/
  f32_t f_Y0;                                                               /*!< top left corner of the patch - Y position @unit:pix*/
  f32_t f_Scale;                                                            /*!< scale factor for the patch*/
  f32_t f_HOGQuality;                                                       /*!< hog classifier quality*/
  f32_t f_LRFQuality;                                                       /*!< lrf classifier quality*/
  f32_t f_LRFDispQuality;                                                   /*!< lrf disparity classifier quality*/
  ui32_t u_InitialScale;                                                    /*!< initial scale of the result */
} PEDPost_t_Result;



static const ui32_t PEDPostClassifierResults_VersionNumber = 2; /*!< Version Number of struct PEDPost_t_PEDClassifierHOGResults 
                                                                     2: added lrf disparity results, added initial scale*/
/*! Classifier Results*/   
typedef struct _PEDPost_t_ClassifierResults
{
  DEFINE_VERSION_MEMBER(PEDPostClassifierResults);

  ui32_t                u_NrOfUsedResults;                                  /*!< nr of classifier results */
  PEDPost_t_Result      Result[PED_MAX_RESULTS];                            /*!< Classifier Results */

} PEDPost_t_ClassifierResults;


static const ui32_t PEDPostClassifierFPGAStream_VersionNumber = 2; /*!< Verison Number of struct PEDPost_t_ClassifierFPGAStream 
                                                                        2: increased number of elements from 10000+4*100+64 to 10000+4*100+64+100+100*/
/*! Classifier FPGA raw results */
typedef struct _PEDPost_t_ClassifierFPGAStream
{
  DEFINE_VERSION_MEMBER(PEDPostClassifierFPGAStream);

  //raw stream from FPGA
  ui32_t                u_StreamNrOfElements_Header;                        /*!< nr of words reserved for header */
  ui32_t                u_StreamNrOfElements_HOG;                           /*!< max nr of HOG results*/
  ui32_t                u_StreamNrOfElements_LRF;                           /*!< max nr of LRF results*/
  ui16_t                a_FPGAClassifierOutStream[PEDPOST_FPGA_STREAM_LEN]; /*!< Classifier output stream from FPGA -> header | HOG results | LRF Results */
} PEDPost_t_ClassifierFPGAStream;


static const ui32_t PEDPostDynamicInputData_VersionNumber = 2; /*!< Version Number of struct PEDPost_t_DynamicInputData 
                                                                    2: added EnvData*/
/*! PEDPost dynamic input data*/   
typedef struct _PEDPost_t_DynamicInputData
{
  DEFINE_VERSION_MEMBER(PEDPostDynamicInputData);

  PED_t_MountingCalibrationData   MountRight;                              /*!< transformation vehicle to right camera coordinate system */
  PED_t_RectifiedCalibrationData  RectifiedCalibrationData;                /*!< camera parameters of rectified stereo system */

  PED_t_VehicleData               VehicleData;                             /*!< vehicle data required by PEDPost */
  PED_t_ImageInformation          ImageInformation;                        /*!< information of the image */

  PED_t_EnvironmentalData         EnvData;                                 /*!< environmental data */
    
} PEDPost_t_DynamicInputData;




/*! defines the ciritcal zone types (where on the road the pedestrian is)*/
typedef enum
{
  PEDPost_eCriticalZone_undef = 0,                                          /*!< should never be set*/
  PEDPost_eCriticalZone_C     = 1,                                          /*!< zone defined as least critical*/
  PEDPost_eCriticalZone_B     = 2,                                          /*!< zone defined as less critical*/ 
  PEDPost_eCriticalZone_A     = 3,                                          /*!< zone defined as most critical*/  
  PEDPost_eCriticalZoneCnt   = 4
} PEDPost_t_eCrticalZone;


/*! defines the pedestrian output probability*/
typedef enum
{
  PEDPost_eClassProb_Default = 0,                                          /*!< no pedestrian */
  PEDPost_eClassProb_Low     = 1,                                          /*!< low pedestrian probability*/
  PEDPost_eClassProb_Med     = 2,                                          /*!< medium pedestrian probability*/
  PEDPost_eClassProb_High    = 3,                                          /*!< high pedestrian probability*/
  PEDPost_eClassProb_Cnt     = 4
} PEDPost_t_eClassProb;


static const ui32_t PEDPostStaticHyp_VersionNumber = 5; /*!< Version Number of struct PEDPost_t_StaticHyp 
                                                             3: renamed iquality to i_LRFQuality, added LRFDispQuality
                                                             4: added u_CyclesToCollision
                                                             5: added f_DistanceTracked*/
/*! type for one pedestrian static data*/
typedef struct _PEDPost_t_StaticHyp
{
  DEFINE_VERSION_MEMBER(PEDPostStaticHyp);

  bool_t                 b_Valid;                                         /*!< defines if the pedestrian information is valid */
  i32_t                  s_PedID;                                         /*!< ID of this pedestrian information, usually equal to array index*/

  f32_t                  f_DistanceFirstSeen;                             /*!< longitudinal distance where the pedestrian was detected first*/
  f32_t                  f_DistanceTracked;                               /*!< longitudinal distance where the pedestrian was detected first*/

  ui32_t                 u_bitLastCyclesDetected;                         /*!< every bit defines if the pedestrian was detected at the specific frame in the past (31. bit: current cycle, 0. bit: 31 cycles before)*/
  
  ui16_t                 u_CyclesSinceFirstSeen;                          /*!< counts the cycles an pedestrian is "tracked"*/
  ui16_t                 u_CyclesToCollision;                             /*!< number of cycles until collision with the pedestrian, if breaking maneuver is issued immediately*/
  ui16_t                 u_CyclesSeen;                                    /*!< counts the cycles an pedestrian was detected*/  
  
  i8_t                   i_LRFQuality;                                    /*!< LRF Quality of the detected pedestrian (0-100%)*/
  i8_t                   i_LRFDispQuality;                                /*!< LRF Disparity Quality of the detected pedestrian (0-100%)*/
  
  bool_t                 b_PedToClose;                                    /*!< bool: pedestrian is too close for classifier*/

  PEDPost_t_eClassProb   eLastClassProb;                                  /*!< last sent class probability*/
  PEDPost_t_eCrticalZone eLastCriticalZone;                               /*!< last sent critical zone*/
  ui32_t                 u_lastGroupID;                                   /*!< last group id */

  /*-------------------------------------------------------------------------------------------*/
#if defined(__cplusplus) && !defined(__PDO__)
  void init(void)
  {
    VersionNumber           = PEDPostStaticHyp_VersionNumber;
    f_DistanceFirstSeen     = 99.9F;
    f_DistanceTracked       = 0.0F;
    u_bitLastCyclesDetected = 0;
    u_CyclesSinceFirstSeen  = 0xffff;
    u_CyclesToCollision     = 80;
    u_CyclesSeen            = 0;
    i_LRFQuality            = 0;
    i_LRFDispQuality        = 0;
    b_PedToClose            = 0;
    s_PedID                 = -1;
    b_Valid                 = 0;
    eLastClassProb          = PEDPost_eClassProb_Default;
    eLastCriticalZone       = PEDPost_eCriticalZone_undef;
    u_lastGroupID           = PEDPOST_GROUPID_SNA;

  }
#endif

} PEDPost_t_StaticHyp;


static const ui32_t PEDPostStaticData_VersionNumber = 1; /*!< Version Number of struct PEDPost_t_StaticData */
/*! type for one pedestrian hypothesis*/
typedef struct _PEDPost_t_StaticData
{
  DEFINE_VERSION_MEMBER(PEDPostStaticData);
  ui32_t               u_NrOfPeds;                            /*!< nr of used peds in array, it is not necessarily given, that the first "u_NrOfPeds" in the array are used! Check all (PEDPOST_OUTPUT_MAX_HYPS) elements for having the b_Valid flag set!*/
  PEDPost_t_StaticHyp  a_PedData[PEDPOST_OUTPUT_MAX_HYPS];    /*!< ped array for static information */



  /*-------------------------------------------------------------------------------------------*/
#if defined(__cplusplus) && !defined(__PDO__)
  void init(void)
  {
    u_NrOfPeds = 0;
    for(ui32_t i = 0; i < PEDPOST_OUTPUT_MAX_HYPS; i++)
    {
      a_PedData[i].init();
    }
    VersionNumber     = PEDPostStaticData_VersionNumber;    
  }
#endif

} PEDPost_t_StaticData;


static const ui32_t PEDPostOutputHyp_VersionNumber = 4; /*!< Version Number of struct PEDPost_t_OutputHyp 
                                                             3: removed static data, added pedid, framestamp, boxvalid
                                                             4: added f_LRFQuality, f_LRFDispQuality, f_HOGQuality*/
/*! type for one pedestrian hypothesis*/
typedef struct _PEDPost_t_OutputHyp
{
  DEFINE_VERSION_MEMBER(PEDPostOutputHyp);

  i32_t                     i_InternalPedID;                              /*!< reference to the internal ped id - used in fod*/
  ui32_t                    u_NrOfRefObjIDs;                              /*!< nr of valid object IDs*/
  ui32_t                    a_RefObjID[PEDPOST_MAX_REF_OBJ];              /*!< list of object ids the pedestrian may belong*/
  
  ui16_t                    u_ImgX0;                                      /*!< top left corner (x) of the pedestrian hypothesis (in image coordinates)*/
  ui16_t                    u_ImgY0;                                      /*!< top left corner (y) of the pedestrian hypothesis (in image coordinates)*/
  ui16_t                    u_ImgX1;                                      /*!< bottom right corner (x) of the pedestrian hypothesis (in image coordinates)*/
  ui16_t                    u_ImgY1;                                      /*!< bottom right corner (y) of the pedestrian hypothesis (in image coordinates)*/
  ui8_t                     b_BoxValid;                                   /*!< defines if the above box (X0, Y0, X1, Y1) is valid (a current detection is available) */
  
  PEDPost_t_eCrticalZone    e_CriticalSection;                            /*!< position relative to the vehicles corridor in 3 classes*/
  PEDPost_t_eClassProb      e_ClassProb;                                  /*!< pedestrian class probability*/
  ui8_t                     u_GroupID;                                    /*!< pedestrian group ID */
  
  f32_t                     f_LRFQuality;                                 /*!< lrf classifier quality*/      
  f32_t                     f_LRFDispQuality;                             /*!< lrf classifier quality on disparity*/
  f32_t                     f_HOGQuality;                                 /*!< hog classifier quality*/

  ui16_t                    u_Priority;                                   /*!< priority of the hyp, lower value = higher prioritiy*/
  ui16_t                    u_CyclesToCollision;                          /*!< number of cycles until collision with the pedestrian, if breaking maneuver is issued immediately*/
  

  /*-------------------------------------------------------------------------------------------*/
#if defined(__cplusplus) && !defined(__PDO__)
  void init(void)
  {
    for(ui32_t i = 0; i < PEDPOST_MAX_REF_OBJ; i++)
    {
      a_RefObjID[i]   = 0;
    }
    VersionNumber     = PEDPostOutputHyp_VersionNumber;
    u_NrOfRefObjIDs   = 0;    
    u_ImgX0           = 0;
    u_ImgX1           = 0;
    u_ImgY0           = 0;
    u_ImgY1           = 0;
    b_BoxValid        = 0;
    e_CriticalSection = PEDPost_eCriticalZone_undef;
    e_ClassProb       = PEDPost_eClassProb_Default;
    u_GroupID         = 0;
    i_InternalPedID   = -1; //default for non ped object
    f_LRFQuality          = 0.0F;
    f_LRFDispQuality      = 0.0F;
    f_HOGQuality          = 0.0F;
    u_Priority            = 16U;
    u_CyclesToCollision   = PEDPOST_MAX_CYC_TO_COLL;
  }
#endif
} PEDPost_t_OutputHyp;


static const ui32_t PEDPostOutputData_VersionNumber = 3; /*!< Version Number of struct PEDPost_t_OutputData   
                                                            2: added DataValid Flag
                                                            3: added u_PEDDiagOut*/
/*! PEDPre dynamic input data*/   
typedef struct _PEDPost_t_OutputData
{
  DEFINE_VERSION_MEMBER(PEDPostOutputData);

  ui64_t               u_Timestamp_usec;                      /*!< time stamp the data is connected to %unit:µs */

  ui32_t               u_NrOfReturnedPedHyps;                 /*!< number of returned pedestrian hypotheses */
  PEDPost_t_OutputHyp  a_OutputHyp[PEDPOST_OUTPUT_MAX_HYPS];  /*!< ped output hypotheses*/

  PED_t_eSignalState   e_DataValid;                           /*!< output data is valid?*/

  ui64_t               u_PEDDiagOut;                          /*!< 64 bit diag output for ped @values:
                                                              struct { 
                                                              .offset(0) = ui64_t Bits; 
                                                              .offset(0).mask(   15ULL<<60ULL) = ui64_t FuncID4Bit; 
                                                              .offset(0).mask(  127ULL<<53ULL) = ui64_t PedVersionNr7Bit; 
                                                              .offset(0).mask(    1ULL<<52ULL) = ui64_t PEDPreSuccessful1Bit; 
                                                              .offset(0).mask(    1ULL<<51ULL) = ui64_t PEDPostSuccessful1Bit; 
                                                              .offset(0).mask(    3ULL<<49ULL) = ui64_t NrOfValidPatchesToFPGA2Bit; 
                                                              .offset(0).mask(    7ULL<<46ULL) = ui64_t NrOfMissedPatchesToFPGA3Bit; 
                                                              .offset(0).mask(    3ULL<<44ULL) = ui64_t NrOfInValidPatchesToFPGA2Bit; 
                                                              .offset(0).mask(    7ULL<<41ULL) = ui64_t NrOfCalcLRF3Bit; 
                                                              .offset(0).mask(    7ULL<<38ULL) = ui64_t NrOfLRFAboveThres3Bit; 
                                                              .offset(0).mask(    7ULL<<35ULL) = ui64_t NrOfPedsAfterNMS3Bit; 
                                                              .offset(0).mask(    7ULL<<32ULL) = ui64_t NrOfReturnedPeds3Bit; 
                                                              .offset(0).mask(   15ULL<<28ULL) = ui64_t MeasFreezeSyncID4Bit; 
                                                              .offset(0).mask(    7ULL<<25ULL) = ui64_t LRFGrey1stPed3Bit; 
                                                              .offset(0).mask(    7ULL<<22ULL) = ui64_t LRFDisp1stPed3Bit; 
                                                              .offset(0).mask(    7ULL<<19ULL) = ui64_t LRFGrey2stPed3Bit; 
                                                              .offset(0).mask(    7ULL<<16ULL) = ui64_t LRFDisp2stPed3Bit;                                                               
                                                              .offset(0).mask(65535ULL)        = ui64_t PedPostError16Bit; 
                                                              
                                                              }*/

  /*-------------------------------------------------------------------------------------------*/
#if defined(__cplusplus) && !defined(__PDO__)
  void init(ui64_t u_TimeStamp)
  {
    for(ui32_t i = 0; i < PEDPOST_OUTPUT_MAX_HYPS; i++)
    {
      a_OutputHyp[i].init();
    }
    VersionNumber         = PEDPostOutputData_VersionNumber;
    u_NrOfReturnedPedHyps = 0;
    u_Timestamp_usec      = u_TimeStamp;
    e_DataValid           = PED_eSignalState_SigNotOK;
    u_PEDDiagOut          = 0;
  }
#endif
  
} PEDPost_t_OutputData;


/* *****************************************************************************
@fn            PEDPostInit                                                    */ /*!
@description   initialize PEDPost algorithm with FW services

@param[in]     function pointers
@return        PED_eErrorCode_NoError or error code
@pre           -
@post          -
@author        Robert Thiel
**************************************************************************** */
PED_t_eErrorCode PEDPostInit(
    const Fct_v_CacheInvalidateAll pfct_v_CacheInvalidateAll,
    const Fct_sl_DMACopy           pfct_sl_DMACopy,
    const Fct_sl_DMACopy_2D        pfct_sl_DMACopy_2D,
    const Fct_sl_DMACopyChained    pfct_sl_DMACopyChained,
    const Fct_sl_DMAWait           pfct_sl_DMAWait,
    const Fct_sl_MEASFreeze        pfct_sl_MEASFreeze
);


/* *****************************************************************************
@fn            PEDPostOpen                                                    */ /*!
@description   open PEDPost algorithm

@param[in]     -
@return        PED_eErrorCode_NoError or error code
@pre           -
@post          -
@author        Robert Thiel
**************************************************************************** */
PED_t_eErrorCode PEDPostOpen(PEDSystemInfo_t *pPedSystemInfo);


/* *****************************************************************************
@fn            PEDPostRun                                          */ /*!
@description   run PEDPost algorithm

@param[in]     p_DynInputData:  dynamic input data
@param[in]     p_Image:  rectified right camera image pointer (16bit grey pixels)
@param[in]     p_SFODOOutputData:  SFOD data
@param[in]     p_FPGAStream: FPGA output stream
@param[out]    p_OutputData: output data to fill
@return        PED_eErrorCode_NoError or error code
@pre           -
@post          -
@author        Robert Thiel
**************************************************************************** */
PED_t_eErrorCode PEDPostRun(const PEDPost_t_DynamicInputData     * const p_DynInputData,      /*!< const pointer to PEDPost Dyn Input Data */
                            const ui16_t                         * const p_Image,             /*!< const pointer to rectified right camera image */
                            PEDPost_t_ClassifierResults          * const p_ClassifierResults, /*!< const pointer to classifier results */
                            const PEDPost_t_ClassifierFPGAStream * const p_FPGAStream,        /*!< const pointer to FPGA output stream data */
                            const PEDPre_t_OutputData            * const p_PEDPreOutpuData,   /*!< const pointer to PEDPre patches */
                            const SFODOutputData_t               * const p_SFODOOutputData,   /*!< const pointer to SFOD output data */			
                            PEDPost_t_OutputData                 * const p_OutputData,        /*!< pointer to PEDPost output data*/
                            PEDPost_t_StaticData                 * const p_StaticData,        /*!< pointer to static ped data struct */
                            PEDSystemInfo_t                      *       pPedSystemInfo       /*!< pointer to ped system info struct*/
                            );



/* *****************************************************************************
@fn            PEDPostClose                                          */ /*!
@description   close PEDPost algorithm

@param[in]     -
@return        PED_eErrorCode_NoError or error code
@pre           -
@post          -
@author        Robert Thiel
**************************************************************************** */
PED_t_eErrorCode PEDPostClose(void);



/* **************************************************************************** 
@fn            PEDPostGetInternalState
@description   Acessor of PEDPost algorithm state data

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
PED_t_eErrorCode PEDPostGetInternalState (const void ** const pp_PV_AlgoState, ui32_t * const u_Length);

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
PED_t_eErrorCode PEDPostGetAlgoVersion( PED_t_AlgoVersion * p_AlgoVersion );

#ifdef __cplusplus
  }
#endif // __cplusplus



#endif /* PED_POST_EXT_H */

