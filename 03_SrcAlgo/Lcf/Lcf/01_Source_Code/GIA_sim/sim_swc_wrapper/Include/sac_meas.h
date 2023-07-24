/*! \file **********************************************************************

COMPANY:        Continental AG

PROJECT:        MFC300

CPU:            

COMPONENT:      SAC - Stereo Auto Calibration

MODULNAME:      sac_meas.h  

DESCRIPTION:    MeasFreeze output for SAC

AUTHOR:         J. Schmidt

CREATION DATE:  31.07.2009

VERSION:        $Revision: 1.1 $

CHANGES:        $Log: sac_meas.h  $
CHANGES:        Revision 1.1 2021/12/13 17:24:36CET Wang, David (Wangd3) 
CHANGES:        Initial revision
CHANGES:        Member added to project /ADAS/Projects/MFC5xx/MFC5J3/06_Algorithm/DPU/04_Engineering/01_Source_Code/GIA_sim/sim_swc_wrapper/Include/project.pj
CHANGES:        Revision 1.0 2017/03/03 10:35:32CET Sorge, Sven (uidg3181) 
CHANGES:        Initial revision
CHANGES:        Member added to project /ADAS/SW/Integration/06_Simulation_Components/GIA_GenericInterfaceAdapter/04_Engineering/03_Workspace/Component_Workspace/GIA_sim/sim_swc_wrapper/Include/project.pj
CHANGES:        Revision 1.1 2014/03/13 15:11:09CET Sorge, Sven (uidg3181) 
CHANGES:        Initial revision
CHANGES:        Member added to project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/ETK_EngineeringToolKit/04_Engineering/GIA_GenericInterfaceAdapter/04_Engineering/03_Workspace/algo/gia_sim/wrapper/Include/project.pj
CHANGES:        Revision 1.36 2012/07/12 19:20:46CEST Stache, Nicolaj (uidt6711) 
CHANGES:        update 4.7.1 lib
CHANGES:        --- Added comments ---  uidt6711 [Jul 12, 2012 7:20:46 PM CEST]
CHANGES:        Change Package : 67326:3 http://mks-psad:7002/im/viewissue?selection=67326
CHANGES:        Revision 1.35 2012/06/19 14:53:29CEST Godreau, Bertrand (uid28828) 
CHANGES:        add findings from code review
CHANGES:        --- Added comments ---  uid28828 [Jun 19, 2012 2:53:30 PM CEST]
CHANGES:        Change Package : 130169:2 http://mks-psad:7002/im/viewissue?selection=130169
CHANGES:        Revision 1.34 2012/04/19 15:19:07CEST Garcia, Lucien (uid26778) 
CHANGES:        Lint warning corrections
CHANGES:        --- Added comments ---  uid26778 [Apr 19, 2012 3:19:07 PM CEST]
CHANGES:        Change Package : 80273:1 http://mks-psad:7002/im/viewissue?selection=80273
CHANGES:        Revision 1.33 2012/02/15 09:55:52CET Spruck, Jochen (spruckj) 
CHANGES:        Add calib interface meas freeze
CHANGES:        --- Added comments ---  spruckj [Feb 15, 2012 9:55:53 AM CET]
CHANGES:        Change Package : 98074:2 http://mks-psad:7002/im/viewissue?selection=98074
CHANGES:        Revision 1.32 2012/01/24 20:47:58CET Stache, Nicolaj (uidt6711) 
CHANGES:        4.4.0 interface freeze update
CHANGES:        --- Added comments ---  uidt6711 [Jan 24, 2012 8:47:58 PM CET]
CHANGES:        Change Package : 67326:3 http://mks-psad:7002/im/viewissue?selection=67326
CHANGES:        Revision 1.31 2011/11/25 19:06:48CET Stache, Nicolaj (uidt6711) 
CHANGES:        update
CHANGES:        --- Added comments ---  uidt6711 [Nov 25, 2011 7:06:48 PM CET]
CHANGES:        Change Package : 67326:3 http://mks-psad:7002/im/viewissue?selection=67326
CHANGES:        Revision 1.30 2011/11/25 15:01:29CET Garcia, Lucien (uid26778) 
CHANGES:        Split LUT generation in 2 frames (runtime improvement)
CHANGES:        --- Added comments ---  uid26778 [Nov 25, 2011 3:01:29 PM CET]
CHANGES:        Change Package : 87584:1 http://mks-psad:7002/im/viewissue?selection=87584
CHANGES:        Revision 1.29 2011/11/10 20:29:00CET Stache Nicolaj (uidt6711) (uidt6711) 
CHANGES:        interface freeze
CHANGES:        --- Added comments ---  uidt6711 [Nov 10, 2011 8:29:00 PM CET]
CHANGES:        Change Package : 67326:1 http://mks-psad:7002/im/viewissue?selection=67326
CHANGES:        Revision 1.28 2011/10/04 08:46:57CEST Spruck Jochen (spruckj) (spruckj) 
CHANGES:        Remove misra issues
CHANGES:        --- Added comments ---  spruckj [Oct 4, 2011 8:46:58 AM CEST]
CHANGES:        Change Package : 79035:2 http://mks-psad:7002/im/viewissue?selection=79035
CHANGES:        Revision 1.27 2011/09/29 15:42:59CEST Stache Nicolaj (uidt6711) (uidt6711) 
CHANGES:        Input check of vehicle kilometers input.
CHANGES:        bugfix: kilometers now in measfreeze
CHANGES:        --- Added comments ---  uidt6711 [Sep 29, 2011 3:42:59 PM CEST]
CHANGES:        Change Package : 67326:1 http://mks-psad:7002/im/viewissue?selection=67326
CHANGES:        Revision 1.26 2011/09/26 18:17:11CEST Spruck Jochen (spruckj) (spruckj) 
CHANGES:        Freeze all in the sacMeasObj
CHANGES:        --- Added comments ---  spruckj [Sep 26, 2011 6:17:11 PM CEST]
CHANGES:        Change Package : 79035:1 http://mks-psad:7002/im/viewissue?selection=79035
CHANGES:        Revision 1.25 2011/09/20 18:57:15CEST Stache Nicolaj (uidt6711) (uidt6711) 
CHANGES:        3.2.0 Lib 2 Interface change
CHANGES:        --- Added comments ---  uidt6711 [Sep 20, 2011 6:57:16 PM CEST]
CHANGES:        Change Package : 67326:1 http://mks-psad:7002/im/viewissue?selection=67326
CHANGES:        Revision 1.24 2011/09/20 14:42:34CEST Spruck Jochen (spruckj) (spruckj) 
CHANGES:        Add meas freeze funktionality for the Temp model and the yaw angle calib with yaw rate
CHANGES:        --- Added comments ---  spruckj [Sep 20, 2011 2:42:34 PM CEST]
CHANGES:        Change Package : 79035:1 http://mks-psad:7002/im/viewissue?selection=79035
CHANGES:        Revision 1.23 2011/09/12 17:05:25CEST Garcia Lucien (uid26778) (uid26778) 
CHANGES:        Add extended fine mode
CHANGES:        --- Added comments ---  uid26778 [Sep 12, 2011 5:05:25 PM CEST]
CHANGES:        Change Package : 77279:2 http://mks-psad:7002/im/viewissue?selection=77279
CHANGES:        Revision 1.22 2011/08/26 19:47:58CEST Stache Nicolaj (uidt6711) (uidt6711) 
CHANGES:        3.2.0 Interface change
CHANGES:        --- Added comments ---  uidt6711 [Aug 26, 2011 7:47:58 PM CEST]
CHANGES:        Change Package : 67326:1 http://mks-psad:7002/im/viewissue?selection=67326
CHANGES:        Revision 1.21 2011/07/15 17:16:46CEST Stache Nicolaj (uidt6711) (uidt6711) 
CHANGES:        MOD: Status inputs isRain etc. added to measfreeze
CHANGES:        --- Added comments ---  uidt6711 [Jul 15, 2011 5:16:46 PM CEST]
CHANGES:        Change Package : 67326:1 http://mks-psad:7002/im/viewissue?selection=67326
CHANGES:        Revision 1.20 2011/07/05 19:54:13CEST Stache Nicolaj (uidt6711) (uidt6711) 
CHANGES:        SAC interface change
CHANGES:        Revision 1.19 2011/05/12 20:30:27CEST Stache Nicolaj (uidt6711) (uidt6711) 
CHANGES:        Interface freezes 2.5.1 revision
CHANGES:        --- Added comments ---  uidt6711 [May 12, 2011 8:30:27 PM CEST]
CHANGES:        Change Package : 58788:2 http://mks-psad:7002/im/viewissue?selection=58788
CHANGES:        Revision 1.18 2011/04/17 21:16:25CEST Stache Nicolaj (uidt6711) (uidt6711) 
CHANGES:        Interface change, coarse calibration
CHANGES:        Revision 1.17 2011/03/25 16:37:15CET Stache Nicolaj (uidt6711) (uidt6711) 
CHANGES:        interface adaptation
CHANGES:        Revision 1.16 2011/02/17 14:34:06CET Stache Nicolaj (uidt6711) (uidt6711) 
CHANGES:        Widths, heights, start, stop for rectified and powerflow images provided
CHANGES:        struct version number for powerflow removed, roi-offset added to the interface
CHANGES:        --- Added comments ---  uidt6711 [Feb 17, 2011 2:34:07 PM CET]
CHANGES:        Change Package : 58788:1 http://mks-psad:7002/im/viewissue?selection=58788
CHANGES:        Revision 1.15 2011/02/14 18:18:27CET Stache Nicolaj (uidt6711) (uidt6711) 
CHANGES:        version number for each struct is provided
CHANGES:        Revision 1.14 2011/02/14 13:05:08CET Stache Nicolaj (uidt6711) (uidt6711) 
CHANGES:        parameter ID added to the LUT interface
CHANGES:        Revision 1.13 2011/02/11 16:29:32CET Stache Nicolaj (uidt6711) (uidt6711) 
CHANGES:        Interface adaptation finished (no crash in MTS)
CHANGES:        Revision 1.12 2011/02/10 20:19:50CET Stache Nicolaj (uidt6711) (uidt6711) 
CHANGES:        SAC interface fully integrated, however MTS crashes
CHANGES:        Revision 1.11 2011/02/10 13:46:49CET Stache Nicolaj (uidt6711) (uidt6711) 
CHANGES:        Provide preliminary interface
CHANGES:        Revision 1.10 2011/02/08 19:45:22CET Stache Nicolaj (uidt6711) (uidt6711) 
CHANGES:        Provide Interface for Odometry, SGM, Powerflow, timestamp, Temperature, shiftedROI, ImagerSyncOffset
CHANGES:        Revision 1.9 2010/12/13 13:48:58CET Wagner Ulrich (uid04769) (uid04769) 
CHANGES:        Bugfix for B1 2.3.1 release
CHANGES:        --- Added comments ---  uid04769 [Dec 13, 2010 1:48:58 PM CET]
CHANGES:        Change Package : 37886:1 http://mks-psad:7002/im/viewissue?selection=37886
CHANGES:        Revision 1.8 2010/11/30 16:23:46CET Wagner Ulrich (uid04769) (uid04769) 
CHANGES:        Added version numbers
CHANGES:        --- Added comments ---  uid04769 [Nov 30, 2010 4:23:46 PM CET]
CHANGES:        Change Package : 37886:1 http://mks-psad:7002/im/viewissue?selection=37886
CHANGES:        Revision 1.7 2010/09/06 13:04:00CEST Jochen Schmidt (schmidtj10) 
CHANGES:        added output time stamp
CHANGES:        --- Added comments ---  schmidtj10 [Sep 6, 2010 1:04:01 PM CEST]
CHANGES:        Change Package : 37155:1 http://mks-psad:7002/im/viewissue?selection=37155
CHANGES:        Revision 1.6 2010/08/13 11:07:13CEST Jochen Schmidt (schmidtj10) 
CHANGES:        interface update
CHANGES:        Revision 1.5 2010/08/11 16:46:30CEST Jochen Schmidt (schmidtj10) 
CHANGES:        - interface update (run mode switches, extended output,...)
CHANGES:        - generate test data set
CHANGES:        - run in MeaseFreeze Mode only
CHANGES:        Revision 1.4 2010/05/18 11:04:05CEST jschmidt 
CHANGES:        added rectified baseline to MeasFreeze output
CHANGES:        --- Added comments ---  jschmidt [2010/05/18 09:04:05Z]
CHANGES:        Change Package : 39263:1 http://LISS014:6001/im/viewissue?selection=39263
CHANGES:        Revision 1.3 2009/11/20 09:37:53CET jschmidt 
CHANGES:        changed virtual address
CHANGES:        --- Added comments ---  jschmidt [2009/11/20 08:37:54Z]
CHANGES:        Change Package : 26824:1 http://LISS014:6001/im/viewissue?selection=26824
CHANGES:        Revision 1.2 2009/11/09 16:37:57CET jschmidt 
CHANGES:        added support for MeasFreeze output
CHANGES:        --- Added comments ---  jschmidt [2009/11/09 15:37:57Z]
CHANGES:        Change Package : 26824:1 http://LISS014:6001/im/viewissue?selection=26824
CHANGES:        Revision 1.1 2009/07/31 11:43:26CEST jschmidt 
CHANGES:        Initial revision
CHANGES:        Member added to project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/SAC_StereoAutoCalibration/04_Engineering/01_Source_Code/Kernel/project.pj

**************************************************************************** */

#ifndef SAC_MEAS_H
#define SAC_MEAS_H

#include "sac_interface.h"
#include "sac_math_types.h"
#include "sac_temperatur_model_types.h"
#include "viscr_smpc_depth_types.h"

#ifdef __cplusplus
extern "C" {
#endif

#define SAC_MEAS_NumRadDistCoeff 10

#define SAC_MEAS_ID_MEAS_OBJ             (0x30040000UL)

#define SAC_MEAS_ID_CALIB_ANGLES         (0x30050000uL)
#define SAC_MEAS_ID_NVM_ANGLE_TABLE      (0x30051000uL)
#define SAC_MEAS_ID_TEMPMOD_DATA         (0x30052000uL)
#define SAC_MEAS_ID_TEMPMOD_OUTPUT       (0x30053000uL)
#define SAC_MEAS_ID_YAW_DEPTH_DATA       (0x30054000uL)

#define SAC_MEAS_ID_CALIBRATION_DATA     (0x30055000uL)

#define SAC_MEAS_ID_LUT_LEFT             (0x30000000uL)
#define SAC_MEAS_ID_LUT_RIGHT            (0x30020000uL)


  static const ui32_t SACMeasIntrinsicCalibrationData_VersionNumber = 2;  /*!< version number of struct SACMeasIntrinsicCalibrationData */
  /*! \brief camera calibration data (intrinsic) */
  typedef struct
  {
    DEFINE_VERSION_MEMBER( SACMeasIntrinsicCalibrationData );

    f32_t FocalX;	            	/*!< camera X-coordinate focal length [pixel] */
    f32_t FocalY;		            /*!< camera Y-coordinate focal length [pixel] */
    f32_t CenterX;	           	/*!< X-coordinate of camera center point in image [pixel] */
    f32_t CenterY;           		/*!< Y-coordinate of camera center point in image [pixel] */
    f32_t RadialDistortion[SAC_MEAS_NumRadDistCoeff];  	/*!< array containing radial distortion coefficient k0 ... k9 */
    ui16_t  NumRadDistCoeff;      /*!< number of elements in array RadialDistortion[] */
  }SACMeasIntrinsicCalibrationData_t;

  
  static const ui32_t SACMeasIntrinsicCalibrationDataRect_VersionNumber = 2;  /*!< version number of struct SACMeasIntrinsicCalibrationDataRect */
  /*! \brief camera calibration data (intrinsic, rectified images) */
  typedef struct
  {
    DEFINE_VERSION_MEMBER( SACMeasIntrinsicCalibrationDataRect );

    f32_t FocalX;	            	/*!< camera X-coordinate focal length [pixel] */
    f32_t FocalY;		            /*!< camera Y-coordinate focal length [pixel] */
    f32_t CenterX;	           	/*!< X-coordinate of camera center point in image [pixel] */
    f32_t CenterY;           		/*!< Y-coordinate of camera center point in image [pixel] */
  }SACMeasIntrinsicCalibrationDataRect_t;

  
  static const ui32_t SACMeasExtrinsicCalibrationData_VersionNumber = 2;  /*!< version number of struct SACMeasExtrinsicCalibrationData */
  /*! \brief camera calibration data (extrinsic ) x_left = R * x_right + t*/
  typedef struct
  {
    DEFINE_VERSION_MEMBER( SACMeasExtrinsicCalibrationData );

    f32_t Baseline;     /*!< camera stereo baseline [m] */

    /* translation vector right to left [m]*/
    f32_t tx;           /*!< x-translation [m] */
    f32_t ty;           /*!< y-translation [m] */
    f32_t tz;           /*!< z-translation [m] */

    /* rotation matrix 3x3, stored rowwise*/
    f32_t RotMat[9];		      	/*!< rotation matrix stored colum-major (i.e., col1, col2, col3), 9 elements */
  }SACMeasExtrinsicCalibrationData_t;


  
  static const ui32_t SACMeasCalibrationData_VersionNumber = 3;  /*!< version number of struct SACMeasCalibrationData */
  typedef struct
  {
    DEFINE_VERSION_MEMBER( SACMeasCalibrationData );

    SACImageData_t                    ImageDataLeft;        /*!< ROI position and size, left image */
    SACImageData_t                    ImageDataRight;       /*!< ROI position and size, right image */
    SACMeasIntrinsicCalibrationData_t IntrinsicLeft;        /*!< intrinsic parameters left camera */
    SACMeasIntrinsicCalibrationData_t IntrinsicRight;       /*!< intrinsic parameters right camera */
    SACMeasExtrinsicCalibrationData_t ExtrinsicRightToLeft; /*!< stereo transformation right to left camera */
    SACMountingCalibrationData_t      MountRight;           /*!< transformation vehicle to right camera coordinate system */
    f32_t                             WshieldModelCoeff[5]; /*!< Model coefficients of windshield distortion model 0..4 i.e.: M[4]*u*v^2 + M[3]*v^2 + M[2]*u*v + M[1]*v + M[0] = dv  */
  }SACMeasCalibrationData_t;




  static const ui32_t SACMeasDynamicInputData_VersionNumber = 11;  /*!< version number of struct SACMeasDynamicInputData */
  typedef struct 
  {
    DEFINE_VERSION_MEMBER( SACMeasDynamicInputData );

    SACMeasCalibrationData_t CalibrationData;
    SACDisparity_t disparityMapCurrent;
    SACDisparity_t disparityMapPrev;
    f32_t VehicleSpeed;									              /*!< Vehicle Speed in m/s */			
	  f32_t YawRate;										                /*!< Yaw Rate in rad/s */
    f32_t VehicleAcceleration;                        /*!< Acceleration in m/(s^2) */
    f32_t VehicleKilometers;                          /*!< Vehicle kilometers in km */
    i32_t isRain;                                     /*!< if >0: rain, if ==0: no rain */
    i32_t isDay;                                      /*!< if >0; night, if==0: day */
    //f32_t ImgCurrTemperature;                       /*!< Imager temperature in degree centigrade */
    f32_t DistFrontToRearAxis;                        /*!< Distance between front and rear axis in meters */
    f32_t exposureTime;                               /*!< exposure time of imagers in us */
    SACModes_t diagnosisTriggerSACMode;               /*!< set SAC into specific mode via diagnosis (only supported: SAC_Mode_Default (i.e. do nothing) SAC_Mode_AutoCalCoarse (i.e. do coarse calibration) */
    SACImage_t RectImgLeftCurrent;                    /*!< Timestamp and framecount imformation for rectified input image left, current image */
    SACImage_t RectImgLeftPrev;                       /*!< Timestamp and framecount imformation for rectified input image left, previous image */
    SACImage_t RectImgRightCurrent;                   /*!< Timestamp and framecount imformation for rectified input image right, current image */
    SACImage_t RectImgRightPrev;                      /*!< Timestamp and framecount imformation for rectified input image right, previous image */
    SAC_Powerflow_t imageDataTimePowerflow;           /*!< Time Powerflow image (Right) */	
	  SAC_Powerflow_t imageDataRightLeftPowerflow;      /*!< Right Left Powerflow  image */	
    FromToNVM_t InputFromNVM;                         /*!< access to calibration data which is stored in NVM */
    SacUpdEolInput_t EOLupdateInput;                  /*!< input from Diagnosis and PPARs for executing the EOL-Update mode */
    SacDistTestInput_t DistTestInput;                 /*!< input from Diagnosis and PPARs for executing the DistTest mode */
    ui32_t ui_DiagnoseDebugFlags;                     /*!< Diagnosis debug input */
    TempArray_t temperatures;                         /*!< Array of temperatures e.g. of imagers, MCU, DSP, FPGA,... */
    //SACEvalInput_t EvaluationInp;                   /*!< contains distance measurements of other modules which help to assess the performance of SAC */
    SACRadarDistInput_t radarDist;                    /*!< radar distance data for yaw angle computation */
    SACStereoDistInput_t stereoDist;                  /*!< stereo distance data for yaw angle computation */
    SAC_GB_t_FctBlockage SAC_GB_FctBlockage;          /*!< camera blockage information */
    SACComponentTimeout_t timeout;                    /*!< define SAC-Timeouts */
/* ~CodeReview ~ID:31a9c77c1917119fb8f0bb4654667265 ~Reviewer:CW01\uid28828 ~Date:19/06/2012 ~Priority:3 ~Comment:Magic number in table definition */
    SACQthres_t qThresholds[20];                      /*!< Array of Quality thresholds tbd. */
  } SACMeasDynamicInputData_t;



  static const ui32_t SACMeasRectCamPars_VersionNumber = 2;  /*!< version number of struct SACMeasRectCamPars */
  /* camera parameters of rectified stereo system */
  typedef struct
  {
    DEFINE_VERSION_MEMBER( SACMeasRectCamPars );

    SACMeasIntrinsicCalibrationDataRect_t IntrinsicLeft;
    SACMeasIntrinsicCalibrationDataRect_t IntrinsicRight;
    SACMountingCalibrationData_t          MountRightRect;       /*!< pitch, roll, yaw angle to rotate rectified to orig camera in Autosar Coordinates. 1st rotation axis: x, 2nd: y, 3rd z., x,y,z coordinates are identical to MountRight*/
    f32_t                                 BaselineRect; /*!< camera stereo baseline (rectified) [m] */
    SACBBox_t                             BBoxLeft;             /*!< bounding box of left rectified image */
    SACBBox_t                             BBoxRight;            /*!< bounding box of right rectified image */
  }SACMeasRectCamPars_t;

  
  static const ui32_t SACMeasInternalPars_VersionNumber = 2;  /*!< version number of struct SACMeasInternalPars */
  /* internal algo parameters (sac_defs.h) */
  typedef struct
  {
    DEFINE_VERSION_MEMBER( SACMeasInternalPars );

    ui32_t IMGWIDTH;
    ui32_t IMGHEIGHT;
    ui32_t LUTWIDTH;
    ui32_t LUTHEIGHT;
    ui32_t LUTSTEP;
  }SACMeasInternalPars_t;


  

  static const ui32_t SAC_MEASOBJ_VersionNumber = 8;

  typedef struct
  {
    //i32_t      version;     /* version of MeasFreeze structure */
    DEFINE_VERSION_MEMBER(SAC_MEASOBJ); /* version of MeasFreeze structure */

    i32_t      major;       /*!<  */
    i32_t      minor;       /*!<  */
    i32_t      bugfix;      /*!<  */
    ui32_t     outstanding; /*!<  */
    i32_t      customer;    /*!<  */
    
    i32_t                             usePowerflowLRMode;
    SACModes_t                        SACRunMode;                 /*!< run mode in input interface */
    SACSFModeOut_t                    SACSFMode;                  /*!< Defines standalone / run in parallel computation for the software framework */
    SACSFModeIn_t                     SFrameworkMode;             /*!< current mode of software framework */
    SACReturnState_t                  SACState;                   /*!< return state in output */
    TimeFrameStamp_t                  TFStamp;                    /*!< time stamp when output data was generated in msec and frame number*/
    SACResult_t                       SACResult;                  /*!< Defines whether SAC-result is valid or not */
    i32_t                             SACError;                   /*!< Number of SAC-Error */

    SACMeasDynamicInputData_t         dynamicInputData;
    SACMeasRectCamPars_t              rectCamPars;
    SACMeasInternalPars_t             internalPars;
    SACExtrinsicCalibrationDataOut_t  ExtrinsicRightToLeftUpdate;
    SACSignalState_t                  ExtrinsicRightToLeftUpdateValid;
    SACshiftedROIData_t               shiftedROIData;
    SACDebug_t                        DebugDataOutput;
    SACStatistics_t                   SACStatistics;
    FromToNVM_t                       OutputToNVM;
    //ui16_t                            parameterIdLUTs;
    ui16_t                            parameterIdLUTRight;
    ui16_t                            parameterIdLUTLeft;
    ui16_t                            parameterIdRectPars;
    SacUpdEolFromToNVM_t              EOLupdateFromNVM;            /*!< previously determined update values of rotation by SAC */
    SacUpdEolFromToNVM_t              EOLupdateToNVM;              /*!< determined update values of rotation by SAC */               
    SacDistTestFromToNVM_t            DistTestToNVM;               /*!< result of the disttest which shall be stored in NVM */
    SacDistTestFromToNVM_t            DistTestFromNVM;             /*!< data which have been saved by a previously conducted dist test in NVM */

    ui64_t                            SACWarnings;                       /*!< bitwise coding of warnings. Value 0 means everything is OK, 
                                                                         LSB= Bit 1: ROIshift out of range
                                                                              Bit 2: SAC resulting angles pitch, roll, yaw go beyond security boarders
                                                                              Bit 3-64: To be defined */
    ui64_t                            FlexrayBitfield;          /*!< Bitfield for Flexray output */

    SACCalibAngles_t                  SACCalibAngles;
    SACNvAngleData_t                  SACNvAngleData;
    SACTempModelData_t                SACTempModelData;
    SACTempModelOutput_t              SACTempModelOutput;

    SACDepthYawAngleData_t            SACDepthYawAngleData;

    SAC_SystemInfo_t                  sysInfo;                     /* Errors */
  }SAC_MEASOBJ_t;

/* ~CodeReview ~ID:2ce256c490e0b40b35e31284cede721b ~Reviewer:CW01\uid28828 ~Date:19/06/2012 ~Priority:3 ~Comment:Magic number in table definition */
  typedef sac_lut_fixedpoint_t SACMeasObjLUTLeft[2*33*16];      /*!< @vaddr: SAC_MEAS_ID_LUT_LEFT @VNAME: SACMeasObjLUTLeft @cycleid: sac_cycle_id        */
  typedef sac_lut_fixedpoint_t SACMeasObjLUTRight[2*33*16];      /*!< @vaddr: SAC_MEAS_ID_LUT_RIGHT @VNAME: SACMeasObjLUTRight @cycleid: sac_cycle_id        */

  /* output objects for SAC */
  /* increment version when measurement output changed */
#define SAC_MEAS_VERSION 4
#define VADDR_SAC_MEASOBJ SAC_MEAS_ID_MEAS_OBJ
  extern SAC_MEASOBJ_t SACMeasObj;

#ifdef __cplusplus
}
#endif

#endif /* SAC_MEAS_H */

