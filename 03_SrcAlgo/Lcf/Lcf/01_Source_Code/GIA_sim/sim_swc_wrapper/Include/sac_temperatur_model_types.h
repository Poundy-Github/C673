/*! \file **********************************************************************

COMPANY:        Continental AG

PROJECT:        MFC300

CPU:            

COMPONENT:      SAC - Stereo Auto Calibration

MODULNAME:      sac_temperatur_model_types.h

DESCRIPTION:    temperatur model types for yaw pitch and roll angle

AUTHOR:         J. Spruck

CREATION DATE:  16.09.2011

VERSION:        $Revision: 1.1 $

CHANGES:        $Log: sac_temperatur_model_types.h  $
CHANGES:        Revision 1.1 2021/12/13 17:24:36CET Wang, David (Wangd3) 
CHANGES:        Initial revision
CHANGES:        Member added to project /ADAS/Projects/MFC5xx/MFC5J3/06_Algorithm/DPU/04_Engineering/01_Source_Code/GIA_sim/sim_swc_wrapper/Include/project.pj
CHANGES:        Revision 1.0 2017/03/03 10:35:33CET Sorge, Sven (uidg3181) 
CHANGES:        Initial revision
CHANGES:        Member added to project /ADAS/SW/Integration/06_Simulation_Components/GIA_GenericInterfaceAdapter/04_Engineering/03_Workspace/Component_Workspace/GIA_sim/sim_swc_wrapper/Include/project.pj
CHANGES:        Revision 1.1 2014/03/13 15:11:09CET Sorge, Sven (uidg3181) 
CHANGES:        Initial revision
CHANGES:        Member added to project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/ETK_EngineeringToolKit/04_Engineering/GIA_GenericInterfaceAdapter/04_Engineering/03_Workspace/algo/gia_sim/wrapper/Include/project.pj
CHANGES:        Revision 1.14 2012/08/06 15:53:30CEST Cui, Baomin (cuib) 
CHANGES:        - added comment in order to get 100% Coverage in SAC release AL_SAC_04.07.00_INT-5
CHANGES:        --- Added comments ---  cuib [Aug 6, 2012 3:53:30 PM CEST]
CHANGES:        Change Package : 151187:1 http://mks-psad:7002/im/viewissue?selection=151187
CHANGES:        Revision 1.13 2012/06/25 09:33:38CEST Visscher-EXT, Eric (uidk7517) 
CHANGES:        Added code review comments
CHANGES:        --- Added comments ---  uidk7517 [Jun 25, 2012 9:33:39 AM CEST]
CHANGES:        Change Package : 127722:1 http://mks-psad:7002/im/viewissue?selection=127722
CHANGES:        Revision 1.12 2012/03/14 17:50:03CET Exner, Christian (uidt8578) 
CHANGES:        - made angle_type_convert() template inlinable -> so no explicit template instanciation is needed for the ti-compiler
CHANGES:        --- Added comments ---  uidt8578 [Mar 14, 2012 5:50:04 PM CET]
CHANGES:        Change Package : 101435:5 http://mks-psad:7002/im/viewissue?selection=101435
CHANGES:        Revision 1.11 2012/03/14 17:37:17CET Exner, Christian (uidt8578) 
CHANGES:        - fixed #endif followed by non-comment issue
CHANGES:        --- Added comments ---  uidt8578 [Mar 14, 2012 5:37:17 PM CET]
CHANGES:        Change Package : 101435:5 http://mks-psad:7002/im/viewissue?selection=101435
CHANGES:        Revision 1.10 2011/11/15 12:23:33CET Stache, Nicolaj (uidt6711) 
CHANGES:        update
CHANGES:        --- Added comments ---  uidt6711 [Nov 15, 2011 12:23:33 PM CET]
CHANGES:        Change Package : 67326:3 http://mks-psad:7002/im/viewissue?selection=67326
CHANGES:        Revision 1.9 2011/11/10 17:51:11CET Spruck Jochen (spruckj) (spruckj) 
CHANGES:        Add check for driven distance to set the write flags for the temp table
CHANGES:        --- Added comments ---  spruckj [Nov 10, 2011 5:51:11 PM CET]
CHANGES:        Change Package : 87605:1 http://mks-psad:7002/im/viewissue?selection=87605
CHANGES:        Revision 1.8 2011/11/09 18:15:59CET Stache Nicolaj (uidt6711) (uidt6711) 
CHANGES:        Bugfix-Papenburg
CHANGES:        --- Added comments ---  uidt6711 [Nov 9, 2011 6:16:00 PM CET]
CHANGES:        Change Package : 87467:1 http://mks-psad:7002/im/viewissue?selection=87467
CHANGES:        Revision 1.7 2011/09/29 12:08:24CEST Spruck Jochen (spruckj) (spruckj) 
CHANGES:        - change validity check of calib angles from nvm
CHANGES:        - add some missing cases for casting temp model anlge type
CHANGES:        --- Added comments ---  spruckj [Sep 29, 2011 12:08:24 PM CEST]
CHANGES:        Change Package : 79035:1 http://mks-psad:7002/im/viewissue?selection=79035
CHANGES:        Revision 1.6 2011/09/28 15:41:34CEST Spruck Jochen (spruckj) (spruckj) 
CHANGES:        - Remove not needed pc-lint review tags
CHANGES:        - Use nvm calib angle if temp diff is small
CHANGES:        - Use eol calib angles if no nvm calib angles are available, and init the temp table with the eol
CHANGES:        --- Added comments ---  spruckj [Sep 28, 2011 3:41:34 PM CEST]
CHANGES:        Change Package : 79035:1 http://mks-psad:7002/im/viewissue?selection=79035
CHANGES:        Revision 1.5 2011/09/26 18:17:12CEST Spruck Jochen (spruckj) (spruckj) 
CHANGES:        Freeze all in the sacMeasObj
CHANGES:        Revision 1.4 2011/09/26 11:46:04CEST Spruck Jochen (spruckj) (spruckj) 
CHANGES:        remove pdo error
CHANGES:        Revision 1.3 2011/09/23 16:59:35CEST Spruck Jochen (spruckj) (spruckj) 
CHANGES:        - Remove misra issues
CHANGES:        Revision 1.2 2011/09/20 14:48:36CEST Spruck Jochen (spruckj) (spruckj) 
CHANGES:        Move temp model input from interface to temp model interface
CHANGES:        Revision 1.1 2011/09/20 14:39:00CEST Spruck Jochen (spruckj) (spruckj) 
CHANGES:        Initial revision
CHANGES:        Member added to project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/SAC_StereoAutoCalibration/04_Engineering/01_Source_Code/Kernel/project.pj

**************************************************************************** */
#ifndef SAC_TEMPERATUR_MODEL_TYPES
#define SAC_TEMPERATUR_MODEL_TYPES

#define CFG_USE_COMPACT_ENUMS     (1U)

  /*****************************************************************************
    TYPEDEFS
  *****************************************************************************/

  /*! Yaw rate zero point offset types */
#define  ENUM_ANGLE_NON              (0U)
#define  ENUM_ANGLE_CALIB            (1U)
#define  ENUM_ANGLE_TEMPER_TABLE     (2U)
#define  ENUM_ANGLE_DYN_APPRX        (3U)
#define  ENUM_ANGLE_LAST_IGN_CYCLE   (4U)
#define  ENUM_ANGLE_EOL              (5U)
typedef enum {                           
     ANGLE_NON            = ENUM_ANGLE_NON               /*!< No angle type present */
    ,ANGLE_CALIB          = ENUM_ANGLE_CALIB             /*!< Angle acquired from sac */
    ,ANGLE_TEMPER_TABLE   = ENUM_ANGLE_TEMPER_TABLE      /*!< Angle acquired from temperature table */ 
    ,ANGLE_DYN_APPRX      = ENUM_ANGLE_DYN_APPRX         /*!< Angle intepolated, use angle table to adapt last calibration angle */
    ,ANGLE_LAST_IGN_CYCLE = ENUM_ANGLE_LAST_IGN_CYCLE    /*!< Angle from last igniction cycle */
    ,ANGLE_EOL            = ENUM_ANGLE_EOL               /*!< Angle from EOL */
  } eSACTempModelAngleType_t;

#if (CFG_USE_COMPACT_ENUMS)
  typedef ui8_t SACTempModelAngleType_t;      /*!< using 8bit type for the real enum (32bit type) eSACTempModelAngleType_t to save memory*/
#else
  typedef eSACTempModelAngleType_t SACTempModelAngleType_t;
#endif

// ~CodeReview ~ID:eed462d463e433831de2c533bb8ded50 ~Reviewer:CW01\uidk7517 ~Date:24.06.2012 ~Priority:3 ~Comment:justify need for inline and switch mechanism (polymorphim as alternative?)
#if !defined(__PDO__) && defined(__cplusplus)
  template<typename T>
  inline
  T angle_type_convert(eSACTempModelAngleType_t in) {
    switch(in) {/* <ln_offset:+1to+8 COVERAGE reviewer name: Baomin Cui date: 03.08.2012 reason: Function should be covered by module test. */
        case ANGLE_NON:
        default:
          return ENUM_ANGLE_NON;
        case ANGLE_CALIB:           return ENUM_ANGLE_CALIB;
        case ANGLE_TEMPER_TABLE:    return ENUM_ANGLE_TEMPER_TABLE;
        case ANGLE_DYN_APPRX:       return ENUM_ANGLE_DYN_APPRX;
        case ANGLE_LAST_IGN_CYCLE:  return ENUM_ANGLE_LAST_IGN_CYCLE;
        case ANGLE_EOL:             return ENUM_ANGLE_EOL;
    }
  }
#endif

  /*! Angle offset table node */
  typedef struct {
    f32_t Angle;             /*!< Learned angle minimum value         */
    f32_t Conf;              /*!< Confidence of learned angle values  */
    ui8_t No;                /*!< Node number (=index) of angle table */
  } SACTempModelAngleLearnNode_t;

  /*! Yaw angle table data */
  typedef struct {
    SACTempModelAngleLearnNode_t Left;           /*!< Nearest left (lower) table node at current temperature */
    SACTempModelAngleLearnNode_t Right;          /*!< Nearest right (higher) table node at current temperature */
    SACStatInterval_t  SmpAngle;        /*!< Sample interval angle  */
    SACStatInterval_t  SmpTemp;        /*!< Sample interval angle temperature */
    fAngle_t           Angle;            /*!< Current angle offset based on correction table */
    fConfidence_t      Conf;             /*!< Current confidence of angle */
    ui16_t             LearnCnt;         /*!< Learn progress counter during calibration */
    ui16_t             LearnAgainCnt;    /*!< Relearn (max. confidence has been reached) counter */
    fTemperature_t     LastAngleTemp;    /*!< Temperature of last angle learn iteration  */
    bool_t             bWrLeft;          /*!< Left table node write non-volatile memory flag */
    bool_t             bWrRight;         /*!< Right table node write non-volatile memory flag */
    bool_t             Valid;            /*!< Validity for angle offset */
    bool_t             Checked;          /*!< Flag to indicate that table interpolation values has been checked */
  } SACTempModelAngleTblData_t;

  /*! Angle data */
  typedef struct {
    SACTempModelAngleTblData_t Tbl;              /*!< Angle temperature table */
    SACTempModelAngleType_t    AngleType;        /*!< Active final angle type */
    fAngle_t                   Angle;            /*!< Current angle */
    fQuality_t                 MaxQuality;       /*!< Confidence of last calibration */
    fQuality_t                 Quality;          /*!< Current confidence of angle */
    fTemperature_t             Temperature;      /*!< Temperature during last calibration */
    fConfidence_t              confTbl;          /*!< Current confidence of table angle */
    fConfidence_t              confCalib;        /*!< Current confidence of calib angle */
  } SACTempModelAngleData_t;

  typedef struct {
    SACTempModelAngleData_t    YawAngle;            /*!< Angle Data                */
    SACTempModelAngleData_t    PitchAngle;          /*!< Angle Data                */
    SACTempModelAngleData_t    RollAngle;           /*!< Angle Data                */
  } SACTempModelData_t;

  typedef struct {
    fAngle_t                Angle;           /*!< Current calibration angle */
    fQuality_t              Quality;         /*!< Quality of angle */
    SACTempModelAngleType_t AngleType;       /*!< The aktual offset type */
  } SACTempModelAngleOutput_t;


  typedef struct {
    SACTempModelAngleOutput_t    YawAngle;            /*!< Angle Data                */
    SACTempModelAngleOutput_t    PitchAngle;          /*!< Angle Data                */
    SACTempModelAngleOutput_t    RollAngle;           /*!< Angle Data                */
  } SACTempModelOutput_t;

  typedef struct {
    fAngle_t          Angle;            /*!< Current calibration angle */
    fQuality_t        MaxQuality;       /*!< Maximum confidence reached at calibration */
    SACSignalState_t  SignalState;      /*!< Enables observation, If current calibration angle should be used for the temptable */
  } SACCalibAngle_t;

  static const ui32_t SACCalibAngles_VersionNumber = 1; /*!< version number of struct SACCalibAngles_t */
  /*! \brief angle estimated by the sac input for the temp model */
  typedef struct {
    DEFINE_VERSION_MEMBER(SACCalibAngles);
    SACCalibAngle_t CalibYawAngle;     /*!< Current yaw calibration angle   */
    SACCalibAngle_t CalibPitchAngle;   /*!< Current pitch calibration angle */
    SACCalibAngle_t CalibRollAngle;    /*!< Current roll calibration angle  */
    fTemperature_t  Temperatur;        /*!< Current Temperatur              */
    fDistance_t     VehicleKilometers; /*!< Current Odometer distance       */
    bool_t          StandstillOK;      /*!< Vehicle standstill flag         */
  } SACCalibAngles_t;

#endif // SAC_TEMPERATUR_MODEL_TYPES
