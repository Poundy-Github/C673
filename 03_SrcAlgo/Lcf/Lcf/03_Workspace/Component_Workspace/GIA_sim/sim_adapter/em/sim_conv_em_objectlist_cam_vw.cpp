/*! \file **********************************************************************

  COMPANY:         Continental

  PROJECT:         Simulation

  COMPONENT:       sim_adapter em

  MODULNAME:       sim_conv_em_objectlist_cam_vw.cpp

  DESCRIPTION:

  AUTHOR:          Thomas Berndt

  CREATION DATE:   09.12.2014

  VERSION:         $Revision: 1.1 $

  ---*/ /*---
  CHANGES:         $Log: sim_conv_em_objectlist_cam_vw.cpp  $
  CHANGES:         Revision 1.1 2017/08/10 13:15:04CEST uid34177 
  CHANGES:         Initial revision
  CHANGES:         Member added to project /ADAS/SW/Integration/06_Simulation_Components/GIA_GenericInterfaceAdapter/04_Engineering/03_Workspace/Component_Workspace/GIA_sim/sim_adapter/em/project.pj
  CHANGES:         Revision 1.2 2014/12/09 18:04:06CET Berndt, Thomas01 (berndtt1) 
  CHANGES:         minor changes
  CHANGES:         - Added comments -  berndtt1 [Dec 10, 2014 8:02:09 AM CET]
  CHANGES:         Change Package : 221167:43 http://mks-psad:7002/im/viewissue?selection=221167
  CHANGES:         Revision 1.1 2014/12/09 16:10:24CET Berndt, Thomas01 (berndtt1) 
  CHANGES:         Initial revision
  CHANGES:         Member added to project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/CRT_CommonRadarToolbox/04_Engineering/03_Workspace/algo/sim_adapter/em/project.pj

**************************************************************************** */
/* includes ---------------------------------------------------------------- */
#include "sim_adapter_cfg.h"
#include "sim_conv_em_objectlist_cam_vw.h"
#include "sim_versioninfo_impl.h"

/* Definea */
#ifndef AL_SIG_STATE_INIT
  #define AL_SIG_STATE_INIT (0U)
#endif

/* Common definitions/declarations */
typedef unsigned long AlgoInterfaceVersionNumber_t                   /* Algo interface version nummbers @min:0 @max:4294967295 */ /* [Satisfies_rte sws 1188] */;
typedef unsigned long AlgoDataTimeStamp_t                            /* Algo data time-stamp type (32 bit variant) @min:0 @max:4294967295 */  /* [Satisfies_rte sws 1188] */;
typedef unsigned short AlgoCycleCounter_t                            /* Algo cycle counter @min:0 @max:65535 */  /* [Satisfies_rte sws 1188] */;
typedef unsigned char AlgoSignalState_t                              /* Algo signal state enumeration @min: 0 @max:2 @values: enum { AL_SIG_STATE_INVALID=2,AL_SIG_STATE_INIT=0,AL_SIG_STATE_OK=1,} */  /* [Satisfies_rte sws 1188] */;

typedef struct SignalHeader_t                                        /* [Satisfies_rte sws 1191] */
{
  AlgoDataTimeStamp_t uiTimeStamp;
  AlgoCycleCounter_t uiMeasurementCounter;
  AlgoCycleCounter_t uiCycleCounter;
  AlgoSignalState_t eSigStatus;
} SignalHeader_t;                                                    /* Common header for all structured data types */

/* Namespaces */
namespace EMVW_t_ObjectList_CAM_V1                                   /* Length of EMVW_t_ObjectList_CAM = 1636 */
{
  typedef unsigned char EMVW_t_CamMeasType                           /* Object measurement @min: 0 @max:3 @values: enum { EMVW_CAM_MEAS_OBJEKT_GEMESSEN=1,EMVW_CAM_MEAS_OBJEKT_PRAEDIZIERT=0,EMVW_CAM_MEAS_NAHEINSCHERER_ODER_UEBERHOLER=3,EMVW_CAM_MEAS_OBJEKT_PER_FEATURE_TRACKING=2,} */			/* [Satisfies_rte sws 1180], [Satisfies_rte sws 1265] */;
  typedef unsigned char EMVW_t_ClassificationType                    /* Object classification @min: 0 @max:15 @values: enum { EMVW_CAM_CLASS_UEBERFAHRBAR=1,EMVW_CAM_CLASS_PKW=7,EMVW_CAM_CLASS_RETROREFLEKTOR=12,EMVW_CAM_CLASS_TIER=11,EMVW_CAM_CLASS_FAHRRAD=5,EMVW_CAM_CLASS_FUSSGAENGERGRUPPE=4,EMVW_CAM_CLASS_INIT=15,EMVW_CAM_CLASS_MOTORRAD=6,EMVW_CAM_CLASS_RANDBEBAUUNG=10,EMVW_CAM_CLASS_FUSSGAENGER=3,EMVW_CAM_CLASS_UNTERFAHRBAR=2,EMVW_CAM_CLASS_UNBEKANNT=0,EMVW_CAM_CLASS_VAN=8,EMVW_CAM_CLASS_LKW=9,} */			/* [Satisfies_rte sws 1180], [Satisfies_rte sws 1265] */;
  typedef unsigned char EMVW_t_ReferencePoint                        /* Object reference point @min: 0 @max:15 @values: enum { EMVW_CAM_RP_HINTEN_RECHTS=5,EMVW_CAM_RP_OBJEKTMITTE=9,EMVW_CAM_RP_VORNE_RECHTS=3,EMVW_CAM_RP_INIT=15,EMVW_CAM_RP_VORNE_LINKS=1,EMVW_CAM_RP_LINKS_MITTE=8,EMVW_CAM_RP_UNBESTIMMT=0,EMVW_CAM_RP_VORNE_MITTE=2,EMVW_CAM_RP_HINTEN_LINKS=7,EMVW_CAM_RP_RECHTS_MITTE=4,EMVW_CAM_RP_HINTEN_MITTE=6,} */			/* [Satisfies_rte sws 1180], [Satisfies_rte sws 1265] */;
  typedef unsigned char EMVW_t_BreakLightStatus                      /* Break lights @min: 0 @max:1 @values: enum { EMVW_CAM_BRKLGHT_BREMSLICHTER_ERKANNT=1,EMVW_CAM_BRKLGHT_KEINE_BREMSLICHTER_ERKANNT=0,} */			/* [Satisfies_rte sws 1180], [Satisfies_rte sws 1265] */;
  typedef unsigned char EMVW_t_IntruderDetState                      /* Camera status regarding intruder detection @min: 0 @max:3 @values: enum { EMVW_CAM_INTR_INTRUDER_NICHT_VERFUEGBAR=1,EMVW_CAM_INTR_INTRUDER_VERFUEGBAR=0,EMVW_CAM_INTR_FEHLER=3,} */			/* [Satisfies_rte sws 1180], [Satisfies_rte sws 1265] */;
  typedef unsigned char EMVW_t_PedestrianWarnState                   /* System state of pedestrian warning @min: 0 @max:3 @values: enum { EMVW_CAM_FGW_FEHLER=3,EMVW_CAM_FGW_AUSGESCHALTET=0,EMVW_CAM_FGW_EINGESCHALTET=1,EMVW_CAM_FGW_NICHT_VERFUEGBAR=2,} */			/* [Satisfies_rte sws 1180], [Satisfies_rte sws 1265] */;

  typedef struct                                                     /* [Satisfies_rte sws 1191] */
  {
    float f_RadialDist;                                              /* Radial distance to object reference point.  Coordianate system:  USK */
    float f_RadialDistStdA;                                          /* Standard deviation of radial distance */
    float f_WnklMitte;                                               /* Angle of object middle point. Coordianate system:  shifted USK with origin in camera */
    float f_WnklMitteStdA;                                           /* Standard deviation of angle */
    EMVW_t_CamMeasType e_Gemessen;                                   /* Object measurement */
    EMVW_t_ClassificationType e_Klasse;                              /* Object classification */
    EMVW_t_ReferencePoint e_Bezugspunkt;                             /* Object reference point */
    float f_ExistenzMass;                                            /* Probability of existence */
    float f_WnklBreite;                                              /* Angle width of object  Coordianate system:  shifted USK with origin in camera */
    float f_WnklBreiteStdA;                                          /* Standard deviation of angle width */
    float f_WnklGeschw;                                              /* Angular velocity in image Coordianate system:  shifted USK with origin in camera */
    float f_WnklGeschwStdA;                                          /* Standard deviation of angular velocity */
    float f_InvTTCBildeb;                                            /* Inverse Time-To-Collision to image plane */
    float f_InvTTCBildebStdA;                                        /* Standard deviation of  Inverse Time-To-Collision to image plane */
    float f_UeberdWnklEgoSpurL;                                      /* Object overlap to own lane from left */
    float f_UeberdWnklEgoSpurR;                                      /* Object overlap to own lane from right */
    unsigned long ui_Alter;                                          /* Age of object in cycles */
    EMVW_t_BreakLightStatus e_BremsLicht;                            /* Break lights */
    float f_phi_left;                                                /* Angle of object edge left */
    float f_sdv_phi_left;                                            /* Standard deviation of object edge angle left */
    float f_phi_right;                                               /* Angle of object edge right */
    float f_sdv_phi_right;                                           /* Standard deviation of object edge angle right */
    unsigned char ui_ID;                                             /* Object ID : 0             no object 1..254  valid objects  255       Init */
    float f_RadialGeschw;                                            /* Radial velocity in m/s */
    float f_RadialGeschw_StdA;                                       /* Standard deviation of radial velocity in m/s */
    float f_ScaleChange;                                             /* ScaleChange value to reach higher ranges */
    unsigned char ui_Reserved1;                                      /* Reserved byte for 4 Byte alignment */
    unsigned char ui_Reserved2;                                      /* Reserved byte for 4 Byte alignment */
    unsigned char ui_Reserved3;                                      /* Reserved byte for 4 Byte alignment */
  } EMVW_t_ObjectInfo;

  typedef struct                                                     /* [Satisfies_rte sws 1191] */
  {
    float f_Objektdatenalter;                                        /* The age of the object list (Delta of middle of image capturing and transmission on bus) */
    unsigned char ui_Update_Zaehler;                                 /* The age of the object list (Delta of middle of image capturing and transmission on bus) */
    unsigned char b_ValidCRC;                                        /* True if CRC is valid */
    unsigned char b_RFD_intruder;                                    /* Object entering FOV :  0  no object detected 1   at least 1 object detected */
    unsigned char ui_MOD_Counter;                                    /* Image Counter */
    EMVW_t_PedestrianWarnState e_FGW_Status;                         /* System state of pedestrian warning */
    EMVW_t_IntruderDetState e_RFD_nicht_verfuegbar;                  /* Camera status regarding intruder detection */
    unsigned char b_FGS_Konfiguration;                               /* Flag if FGS is active 0    off  1    on */
    unsigned char b_Obj_NaheinschererLinks;                          /* Close Cut-In left */
    unsigned char b_Obj_NaheinschererRechts;                         /* Close Cut-In right */
    unsigned char b_blindness_detected;                              /* Blindness detected */
    unsigned char b_Freisicht_niO;                                   /* Free view : 0    OK 1    not OK */
    unsigned char b_relevanter_Fehler;                               /* Relevant error in with error entry 0   no error 1   relevant error */
    unsigned char b_relevante_Nichtverfuegbarkeit;                   /* Relevant not availability of camera 0   available  1    not available */
    unsigned char ui_Reserved1;                                      /* Reserved byte for 4 Byte alignment */
    unsigned char ui_Reserved2;                                      /* Reserved byte for 4 Byte alignment */
    unsigned char ui_Reserved3;                                      /* Reserved byte for 4 Byte alignment */
  } EMVW_t_ObjectListHeader;

  static const unsigned int NumEMVW_t_MCamObjArray = 16;

  typedef EMVW_t_ObjectInfo EMVW_t_MCamObjArray[NumEMVW_t_MCamObjArray];

  typedef struct                                                     /* [Satisfies_rte sws 1191] */
  {
    AlgoInterfaceVersionNumber_t u_VersionNumber;                    /* Interface version number (increased when changed) @min:0 @max:16277215 */
    SignalHeader_t sSigHeader;                                       /* information for synchronisation of SIL simulation */
    EMVW_t_ObjectListHeader objectListHeader;
    EMVW_t_MCamObjArray a_ObjInfo;
  } EMVW_t_ObjectList_CAM;                                           /* @vaddr:0x20198000 @vaddr_defs: EM_MEAS_ID_VW_OBJECT_LIST_CAM @cycleid:EM_ENV @vname:EMVWObjDataCam */

} // end of namespace EMVW_t_ObjectList_CAM_V1


namespace EMVW_t_ObjectList_CAM_V3                                   /* Length of EMVW_t_ObjectList_CAM = 1640 */
{
  typedef unsigned char EMVW_t_CamMeasType                           /* Object measurement @min: 0 @max:3 @values: enum { EMVW_CAM_MEAS_OBJEKT_GEMESSEN=1,EMVW_CAM_MEAS_OBJEKT_PRAEDIZIERT=0,EMVW_CAM_MEAS_NAHEINSCHERER_ODER_UEBERHOLER=3,EMVW_CAM_MEAS_OBJEKT_PER_FEATURE_TRACKING=2,} */			/* [Satisfies_rte sws 1180], [Satisfies_rte sws 1265] */;
  typedef unsigned char EMVW_t_ClassificationType                    /* Object classification @min: 0 @max:15 @values: enum { EMVW_CAM_CLASS_UEBERFAHRBAR=1,EMVW_CAM_CLASS_PKW=7,EMVW_CAM_CLASS_RETROREFLEKTOR=12,EMVW_CAM_CLASS_TIER=11,EMVW_CAM_CLASS_FAHRRAD=5,EMVW_CAM_CLASS_FUSSGAENGERGRUPPE=4,EMVW_CAM_CLASS_INIT=15,EMVW_CAM_CLASS_MOTORRAD=6,EMVW_CAM_CLASS_RANDBEBAUUNG=10,EMVW_CAM_CLASS_FUSSGAENGER=3,EMVW_CAM_CLASS_UNTERFAHRBAR=2,EMVW_CAM_CLASS_UNBEKANNT=0,EMVW_CAM_CLASS_VAN=8,EMVW_CAM_CLASS_LKW=9,} */			/* [Satisfies_rte sws 1180], [Satisfies_rte sws 1265] */;
  typedef unsigned char EMVW_t_ReferencePoint                        /* Object reference point @min: 0 @max:15 @values: enum { EMVW_CAM_RP_HINTEN_RECHTS=5,EMVW_CAM_RP_OBJEKTMITTE=9,EMVW_CAM_RP_VORNE_RECHTS=3,EMVW_CAM_RP_INIT=15,EMVW_CAM_RP_VORNE_LINKS=1,EMVW_CAM_RP_LINKS_MITTE=8,EMVW_CAM_RP_UNBESTIMMT=0,EMVW_CAM_RP_VORNE_MITTE=2,EMVW_CAM_RP_HINTEN_LINKS=7,EMVW_CAM_RP_RECHTS_MITTE=4,EMVW_CAM_RP_HINTEN_MITTE=6,} */			/* [Satisfies_rte sws 1180], [Satisfies_rte sws 1265] */;
  typedef unsigned char EMVW_t_BreakLightStatus                      /* Break lights @min: 0 @max:1 @values: enum { EMVW_CAM_BRKLGHT_BREMSLICHTER_ERKANNT=1,EMVW_CAM_BRKLGHT_KEINE_BREMSLICHTER_ERKANNT=0,} */			/* [Satisfies_rte sws 1180], [Satisfies_rte sws 1265] */;
  typedef unsigned char EMVW_t_IntruderDetState                      /* Camera status regarding intruder detection @min: 0 @max:3 @values: enum { EMVW_CAM_INTR_INTRUDER_NICHT_VERFUEGBAR=1,EMVW_CAM_INTR_INTRUDER_VERFUEGBAR=0,EMVW_CAM_INTR_FEHLER=3,} */			/* [Satisfies_rte sws 1180], [Satisfies_rte sws 1265] */;

  typedef struct                                                     /* [Satisfies_rte sws 1191] */
  {
    float f_LongitudinalDist;                                        /* Longitudinal distance to object reference point.  Coordianate system:  USK */
    float f_LongitudinalDistStdA;                                    /* Standard deviation of Longitudinal distance */
    float f_WnklMitte;                                               /* Angle of object middle point. Coordianate system:  shifted USK with origin in camera */
    float f_WnklMitteStdA;                                           /* Standard deviation of angle */
    EMVW_t_CamMeasType e_Gemessen;                                   /* Object measurement */
    EMVW_t_ClassificationType e_Klasse;                              /* Object classification */
    EMVW_t_ReferencePoint e_Bezugspunkt;                             /* Object reference point */
    float f_ExistenzMass;                                            /* Probability of existence */
    float f_WnklBreite;                                              /* Angle width of object  Coordianate system:  shifted USK with origin in camera */
    float f_WnklBreiteStdA;                                          /* Standard deviation of angle width */
    float f_WnklGeschw;                                              /* Angular velocity in image Coordianate system:  shifted USK with origin in camera */
    float f_WnklGeschwStdA;                                          /* Standard deviation of angular velocity */
    float f_InvTTCBildeb;                                            /* Inverse Time-To-Collision to image plane */
    float f_InvTTCBildebStdA;                                        /* Standard deviation of  Inverse Time-To-Collision to image plane */
    float f_UeberdWnklEgoSpurL;                                      /* Object overlap to own lane from left */
    float f_UeberdWnklEgoSpurR;                                      /* Object overlap to own lane from right */
    unsigned long ui_Alter;                                          /* Age of object in cycles */
    EMVW_t_BreakLightStatus e_BremsLicht;                            /* Break lights */
    float f_phi_left;                                                /* Angle of object edge left */
    float f_sdv_phi_left;                                            /* Standard deviation of object edge angle left */
    float f_phi_right;                                               /* Angle of object edge right */
    float f_sdv_phi_right;                                           /* Standard deviation of object edge angle right */
    unsigned char ui_ID;                                             /* Object ID : 0             no object 1..254  valid objects  255       Init */
    float f_RadialGeschw;                                            /* Radial velocity in m/s */
    float f_RadialGeschw_StdA;                                       /* Standard deviation of radial velocity in m/s */
    float f_ScaleChange;                                             /* ScaleChange value to reach higher ranges */
    unsigned char ui_Reserved1;                                      /* Reserved byte for 4 Byte alignment */
    unsigned char ui_Reserved2;                                      /* Reserved byte for 4 Byte alignment */
    unsigned char ui_Reserved3;                                      /* Reserved byte for 4 Byte alignment */
  } EMVW_t_ObjectInfo;

  typedef struct                                                     /* [Satisfies_rte sws 1191] */
  {
    float f_Objektdatenalter;                                        /* The age of the object list (Delta of middle of image capturing and transmission on bus) */
    unsigned char ui_Update_Zaehler;                                 /* The age of the object list (Delta of middle of image capturing and transmission on bus) */
    unsigned char b_ValidCRC;                                        /* True if CRC is valid */
    unsigned char b_RFD_intruder;                                    /* Object entering FOV :  0  no object detected 1   at least 1 object detected */
    unsigned char ui_MOD_Counter;                                    /* Image Counter */
    EMVW_t_IntruderDetState e_RFD_nicht_verfuegbar;                  /* Camera status regarding intruder detection */
    unsigned char b_blindness_detected;                              /* Blindness detected */
    unsigned char b_Freisicht_niO;                                   /* Free view : 0    OK 1    not OK */
    unsigned char b_relevanter_Fehler;                               /* Relevant error in with error entry 0   no error 1   relevant error */
    unsigned char b_relevante_Nichtverfuegbarkeit;                   /* Relevant not availability of camera 0   available  1    not available */
    unsigned char ui_Reserved1;                                      /* Reserved byte for 4 Byte alignment */
    unsigned char ui_Reserved2;                                      /* Reserved byte for 4 Byte alignment */
    unsigned char ui_Reserved3;                                      /* Reserved byte for 4 Byte alignment */
  } EMVW_t_ObjectListHeader;

  typedef struct                                                     /* [Satisfies_rte sws 1191] */
  {
    float f_CamPosX;                                                 /* Longitudinal position of camera */
    float f_CamPosY;                                                 /* Lateral position of camera */
  } EMVW_t_CameraParamInfo;

  static const unsigned int NumEMVW_t_MCamObjArray = 16;

  typedef EMVW_t_ObjectInfo EMVW_t_MCamObjArray[NumEMVW_t_MCamObjArray];

  typedef struct                                                     /* [Satisfies_rte sws 1191] */
  {
    AlgoInterfaceVersionNumber_t u_VersionNumber;                    /* Interface version number (increased when changed) @min:0 @max:16277215 */
    SignalHeader_t sSigHeader;                                       /* information for synchronisation of SIL simulation */
    EMVW_t_ObjectListHeader objectListHeader;
    EMVW_t_CameraParamInfo CamParamInfo;
    EMVW_t_MCamObjArray a_ObjInfo;
  } EMVW_t_ObjectList_CAM;                                           /* @vaddr:0x20198000 @vaddr_defs: EM_MEAS_ID_VW_OBJECT_LIST_CAM @cycleid:EM_ENV @vname:EMVWObjDataCam */

} // end of namespace EMVW_t_ObjectList_CAM_V3


class CConvEmObjectListCamVW : public CSimConverterBase
{
  // the list of dependency names used inside by the converter
  /*
  static const char *DEP_NAMES[];
  */

  // here we define the index of each dependency for quick acces
  // the order here should match with the order from DEP_NAMES array
  enum eDepIdx
  {
    // add new dependencies here
    DEP_COUNT
  };

  EMVW_t_ObjectList_CAM_V1::EMVW_t_ObjectList_CAM m_BufV1;
  EMVW_t_ObjectList_CAM_V3::EMVW_t_ObjectList_CAM m_BufV3;

  static void InitV1(EMVW_t_ObjectList_CAM_V1::EMVW_t_ObjectList_CAM &Params);
  static void InitV3(EMVW_t_ObjectList_CAM_V3::EMVW_t_ObjectList_CAM &Params);

public:

  static const char *GetConverterTypeName()
  {
    return "EMVW_t_ObjectList_CAM";
  }

  CConvEmObjectListCamVW(void);
  virtual ~CConvEmObjectListCamVW(void);

  const char *GetTypeName()
  {
    return GetConverterTypeName();
  }

  void Destroy()
  {
    delete this;
  }

  /** returns:
   *   SIM_ERR_OK - when this value can be used
   *   SIM_ERR_USE_VALUE_FROM_PPORT - when the conversion is not implemented here
   *                                  and the value from Provide Port must be used
   */
  long ConvertData(
    SimPortDataTypes_t eRPortType, unsigned long ulRPortSize, const IVersionInfo &requestPortVersionInfo,
    SimPortDataTypes_t ePPortType, unsigned long ulPPortSize, const IVersionInfo *pProvidePortVersionInfo,
    void *pPPortData,
    void **pOutData, unsigned long &ulOutSize);

  /** returns:
   *   SIM_ERR_OK - when this value can be used
   *   SIM_ERR_USE_DEFAULT_VALUE_FROM_RPORT - when the default vaule is not implemented here
   *                                            and the default value from Request Port must be used
   */
  long GetDefaultValue(
    SimPortDataTypes_t eRPortType, unsigned long ulRPortSize, const IVersionInfo &requestPortVersionInfo,
    void **pDefaultData, unsigned long &ulDefaultSize);

protected:

  // used to check if an unversioned PPort is compatible with a certain version of RPort
  bool IsVersionCompatibleWithType(
    SimPortDataTypes_t eRPortType, unsigned long ulRPortSize, const IVersionInfo &requestPortVersionInfo,
    SimPortDataTypes_t ePPortType, unsigned long ulPPortSize);

  // used to check if ports are compatible between different versions
  bool AreVersionsCompatible(
    SimPortDataTypes_t eRPortType, unsigned long ulRPortSize, const IVersionInfo &requestPortVersionInfo,
    SimPortDataTypes_t ePPortType, unsigned long ulPPortSize, const IVersionInfo &providePortVersionInfo);

private:
  enum EM_ObjectList_Cam
  {
    EMVW_T_OBJECTLIST_CAM_V1,
    EMVW_T_OBJECTLIST_CAM_V3,
    EMVW_OBJECTLIST_CAM_VERSION_COUNT
  };

  static CVersionInfoImpl BASE_VERSION;
  static CVersionInfoImpl VERSION1;
  static CVersionInfoImpl VERSION3;
  static const CVersionInfoImpl * const EM_OBJECTLIST_CAM_INPUT_VERSIONS[EMVW_OBJECTLIST_CAM_VERSION_COUNT];

  static const unsigned long SUPPORTED_SIZE[EMVW_OBJECTLIST_CAM_VERSION_COUNT];

  bool IsPortSupported(unsigned long ulPortSize, const IVersionInfo *pPortVersion) const
  {
    for (int nI = 0; nI < EMVW_OBJECTLIST_CAM_VERSION_COUNT; nI++)
    {
      if ((pPortVersion == NULL) || pPortVersion->Equals(EM_OBJECTLIST_CAM_INPUT_VERSIONS[nI]))
      {
        if (ulPortSize == SUPPORTED_SIZE[nI])
        {
          return true;
        }
      }
    };
    return false;
  };
};

CVersionInfoImpl CConvEmObjectListCamVW::BASE_VERSION(0, 0, 0);
CVersionInfoImpl CConvEmObjectListCamVW::VERSION1    (0, 0, 1);
CVersionInfoImpl CConvEmObjectListCamVW::VERSION3    (0, 0, 3);

const CVersionInfoImpl * const CConvEmObjectListCamVW::EM_OBJECTLIST_CAM_INPUT_VERSIONS[CConvEmObjectListCamVW::EMVW_OBJECTLIST_CAM_VERSION_COUNT] =
{
  &VERSION1,
  &VERSION3
};

const unsigned long CConvEmObjectListCamVW::SUPPORTED_SIZE[CConvEmObjectListCamVW::EMVW_OBJECTLIST_CAM_VERSION_COUNT] =
{
  sizeof(EMVW_t_ObjectList_CAM_V1::EMVW_t_ObjectList_CAM),
  sizeof(EMVW_t_ObjectList_CAM_V3::EMVW_t_ObjectList_CAM)
};

__inline void v_Convert_v1_to_v3 (EMVW_t_ObjectList_CAM_V3::EMVW_t_ObjectList_CAM * const pDest,
  const EMVW_t_ObjectList_CAM_V1::EMVW_t_ObjectList_CAM * const pSrc)
{
  pDest->u_VersionNumber = 3u;
  pDest->sSigHeader = pSrc->sSigHeader;

  pDest->objectListHeader.f_Objektdatenalter              = pSrc->objectListHeader.f_Objektdatenalter;
  pDest->objectListHeader.ui_Update_Zaehler               = pSrc->objectListHeader.ui_Update_Zaehler;
  pDest->objectListHeader.b_ValidCRC                      = pSrc->objectListHeader.b_ValidCRC;
  pDest->objectListHeader.b_RFD_intruder                  = pSrc->objectListHeader.b_RFD_intruder;
  pDest->objectListHeader.ui_MOD_Counter                  = pSrc->objectListHeader.ui_MOD_Counter;
  pDest->objectListHeader.e_RFD_nicht_verfuegbar          = pSrc->objectListHeader.e_RFD_nicht_verfuegbar;
  pDest->objectListHeader.b_blindness_detected            = pSrc->objectListHeader.b_blindness_detected;
  pDest->objectListHeader.b_Freisicht_niO                 = pSrc->objectListHeader.b_Freisicht_niO;
  pDest->objectListHeader.b_relevanter_Fehler             = pSrc->objectListHeader.b_relevanter_Fehler;
  pDest->objectListHeader.b_relevante_Nichtverfuegbarkeit = pSrc->objectListHeader.b_relevante_Nichtverfuegbarkeit;
  pDest->objectListHeader.ui_Reserved1                    = pSrc->objectListHeader.ui_Reserved1;
  pDest->objectListHeader.ui_Reserved2                    = pSrc->objectListHeader.ui_Reserved2;
  pDest->objectListHeader.ui_Reserved3                    = pSrc->objectListHeader.ui_Reserved3;

  pDest->CamParamInfo.f_CamPosX                           = -1.6f;
  pDest->CamParamInfo.f_CamPosY                           = 0.f;

  memcpy(&(pDest->a_ObjInfo), &(pSrc->a_ObjInfo), sizeof (pDest->a_ObjInfo));
}

CConvEmObjectListCamVW::CConvEmObjectListCamVW(void) : CSimConverterBase(NULL/*DEP_NAMES*/, DEP_COUNT), m_BufV1(), m_BufV3()
{
  InitV1(m_BufV1);
  InitV3(m_BufV3);
}

CConvEmObjectListCamVW::~CConvEmObjectListCamVW(void)
{
}

void CConvEmObjectListCamVW::InitV1(EMVW_t_ObjectList_CAM_V1::EMVW_t_ObjectList_CAM &Params)
{
  ::memset(&Params, 0, sizeof(Params));
  Params.u_VersionNumber       = 1u;
  // Signal Header
  Params.sSigHeader.eSigStatus = AL_SIG_STATE_INIT;
}

void CConvEmObjectListCamVW::InitV3(EMVW_t_ObjectList_CAM_V3::EMVW_t_ObjectList_CAM &Params)
{
  ::memset(&Params, 0, sizeof(Params));
  Params.u_VersionNumber       = 3u;
  // Signal Header
  Params.sSigHeader.eSigStatus = AL_SIG_STATE_INIT;
}

long CConvEmObjectListCamVW::ConvertData(
  SimPortDataTypes_t eRPortType, unsigned long ulRPortSize, const IVersionInfo &requestPortVersionInfo,
  SimPortDataTypes_t ePPortType, unsigned long ulPPortSize, const IVersionInfo *pProvidePortVersionInfo,
  void *pPPortData,
  void **pOutData, unsigned long &ulOutSize)
{
  long lRet = SIM_ERR_UNADAPTABLE_DATA_PORTS;
  const unsigned int uDataVer = ((pPPortData != NULL) && (ulPPortSize >= 4) && (ePPortType == simOPAQUE_t))?(*reinterpret_cast<unsigned int*>(pPPortData)):(0);

  if (eRPortType == ePPortType)
  {
    if ((ulRPortSize == ulPPortSize) && ((pProvidePortVersionInfo == NULL) || requestPortVersionInfo.Equals(pProvidePortVersionInfo)))
    {
      // Use data directly from provide port
      lRet = SIM_ERR_USE_VALUE_FROM_PPORT;
    }
    else
    {
      // First decide which version we are converting from
      if ((ulPPortSize == SUPPORTED_SIZE[0]) &&
        ((pProvidePortVersionInfo == NULL) || pProvidePortVersionInfo->Equals(&VERSION1) || pProvidePortVersionInfo->Equals(&BASE_VERSION)) &&
        (uDataVer == 0x1u))
      {
        const EMVW_t_ObjectList_CAM_V1::EMVW_t_ObjectList_CAM *pSrc = reinterpret_cast<EMVW_t_ObjectList_CAM_V1::EMVW_t_ObjectList_CAM *>(pPPortData);
        // The decide which version we are converting to
        if ((ulRPortSize == SUPPORTED_SIZE[1]) &&
          (requestPortVersionInfo.Equals(&VERSION3) ||
          requestPortVersionInfo.Equals(&BASE_VERSION)))
        {
          // Destination port of V3 is m_BufV3
          v_Convert_v1_to_v3(&m_BufV3, pSrc);
          *pOutData = &m_BufV3;
          ulOutSize = sizeof(m_BufV3);
          lRet = SIM_ERR_OK;
        }
      }
    }
  }
  return lRet;
}

/** returns:
 *   SIM_ERR_OK - when this value can be used
 *   SIM_ERR_USE_DEFAULT_VALUE_FROM_RPORT - when the default vaule is not implememnted here
 *                                            and the default value from Request Port must be used
 */
long CConvEmObjectListCamVW::GetDefaultValue(
  SimPortDataTypes_t eRPortType, unsigned long ulRPortSize, const IVersionInfo &requestPortVersionInfo,
  void **pDefaultData, unsigned long &ulDefaultSize)
{
  long lRet = SIM_ERR_USE_DEFAULT_VALUE_FROM_RPORT;
  if (eRPortType == simOPAQUE_t)
  {
    if ((ulRPortSize == sizeof(EMVW_t_ObjectList_CAM_V3::EMVW_t_ObjectList_CAM)) && ((BASE_VERSION.Equals(&requestPortVersionInfo)) || (VERSION3.Equals(&requestPortVersionInfo))))
    {
      InitV3(m_BufV3);
      *pDefaultData = &m_BufV3;
      ulDefaultSize = sizeof(EMVW_t_ObjectList_CAM_V3::EMVW_t_ObjectList_CAM);
      lRet = SIM_ERR_OK;
    }
    else if ((ulRPortSize == sizeof(EMVW_t_ObjectList_CAM_V1::EMVW_t_ObjectList_CAM)) && ((BASE_VERSION.Equals(&requestPortVersionInfo)) || (VERSION1.Equals(&requestPortVersionInfo))))
    {
      InitV1(m_BufV1);
      *pDefaultData = &m_BufV1;
      ulDefaultSize = sizeof(EMVW_t_ObjectList_CAM_V1::EMVW_t_ObjectList_CAM);
      lRet = SIM_ERR_OK;
    }
    else
    {
      // No conversion available
    }
  }
  return lRet;
}

// used to check if an unversioned PPort is compatible with a certain version of RPort
bool CConvEmObjectListCamVW::IsVersionCompatibleWithType(
  SimPortDataTypes_t eRPortType, unsigned long ulRPortSize, const IVersionInfo &requestPortVersionInfo,
  SimPortDataTypes_t ePPortType, unsigned long ulPPortSize)
{
  bool bResult = false;
  // Equal ports are always compatible (at least assumed to be)
  if ((ulRPortSize == ulPPortSize) && (eRPortType == ePPortType))
  {
    bResult = true;
  }
  else if ((eRPortType == simOPAQUE_t) && (ePPortType == simOPAQUE_t))
  {
    if ((IsPortSupported(ulRPortSize, &requestPortVersionInfo)) && (IsPortSupported(ulPPortSize, NULL)))
    {
      bResult = true;
    }
  }
  // Data package for the sim_fusion_sync connection (byte aligned structures!)
  else if ((eRPortType == simOPAQUE_t) && (ePPortType == simREFERENCE_t))
  {
  }
  return bResult;
}

// used to check if ports are compatible between different versions
bool CConvEmObjectListCamVW::AreVersionsCompatible(
  SimPortDataTypes_t eRPortType, unsigned long ulRPortSize, const IVersionInfo &requestPortVersionInfo,
  SimPortDataTypes_t ePPortType, unsigned long ulPPortSize, const IVersionInfo &providePortVersionInfo)
{
  bool bResult = false;
  // Equal ports are always compatible (at least assumed to be)
  if ((ulRPortSize == ulPPortSize) && (eRPortType == ePPortType))
  {
    bResult = true;
  }
  else if ((eRPortType == simOPAQUE_t) && (ePPortType == simOPAQUE_t))
  {
    if ((IsPortSupported(ulRPortSize, &requestPortVersionInfo)) && (IsPortSupported(ulPPortSize, &providePortVersionInfo)))
    {
      bResult = true;
    }
  }
  // Data package for the sim_fusion_sync connection (byte aligned structures!)
  else if ((eRPortType == simOPAQUE_t) && (ePPortType == simREFERENCE_t))
  {
  }
  return bResult;
}

//
// Main factory class returning conversion class
//
IConverter * CreateEmObjectListCamVWConvClass(void)
{
  return new CConvEmObjectListCamVW();
}
