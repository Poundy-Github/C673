/*! \file **********************************************************************

  COMPANY:              Continental

  PROJECT:              Simulation

  COMPONENT:            sim_adapter

  MODULNAME:            sim_conv_fct_cam_lane_input_data.cpp

  DESCRIPTION:          Convert

  AUTHOR:               Thomas Berndt

  CREATION DATE:        14.01.2016

  VERSION:              $Revision: 1.1 $

  ---*/ /*---
  CHANGES:              $Log: sim_conv_fct_cam_lane_input_data.cpp  $
  CHANGES:              Revision 1.1 2021/12/13 17:20:58CET Wang, David (Wangd3) 
  CHANGES:              Initial revision
  CHANGES:              Member added to project /ADAS/Projects/MFC5xx/MFC5J3/06_Algorithm/DPU/04_Engineering/01_Source_Code/GIA_sim/sim_adapter/fct/project.pj
  CHANGES:              Revision 1.1 2017/08/10 13:15:15CEST uid34177 
  CHANGES:              Initial revision
  CHANGES:              Member added to project /ADAS/SW/Integration/06_Simulation_Components/GIA_GenericInterfaceAdapter/04_Engineering/03_Workspace/Component_Workspace/GIA_sim/sim_adapter/fct/project.pj
  CHANGES:              Revision 1.2 2016/10/17 07:45:42CEST Berndt, Thomas01 (berndtt1) 
  CHANGES:              * Version V4 and V5 for ARS430BW18
  CHANGES:              Revision 1.1 2016/03/30 10:53:24CEST Berndt, Thomas01 (berndtt1) 
  CHANGES:              Initial revision
  CHANGES:              Member added to project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/CRT_CommonRadarToolbox/04_Engineering/03_Workspace/algo/sim_adapter/fct/project.pj

**************************************************************************** */

/* includes ---------------------------------------------------------------- */
#include <atlbase.h>                                                 // ATL includes, used by CSimConverterBase
#include "sim_adapter_cfg.h"
#include "sim_conv_fct_cam_lane_input_data.h"

#include "sim_versioninfo_impl.h"

// Makros

#define _MINI(x,y) (x<y?x:y)

/* Changes 13.10.2016: Introducing a switch, which must be moved to "sim_adapter_cfg.h" and a separate Dev-Path if necessary */
#define ARS430BW18 (SWITCH_ON)

// Structure and type definitions that are used by all namespaces and are common.
/* typedef t_CamLaneMarkerEnum */
#ifndef   CL_CAM_LANE_MK_ADJ_LEFT
  #define CL_CAM_LANE_MK_ADJ_LEFT 0U
#endif
#ifndef   CL_CAM_LANE_MK_LEFT
  #define CL_CAM_LANE_MK_LEFT 1U
#endif
#ifndef   CL_CAM_LANE_MK_RIGHT
  #define CL_CAM_LANE_MK_RIGHT 2U
#endif
#ifndef   CL_CAM_LANE_MK_ADJ_RIGHT
  #define CL_CAM_LANE_MK_ADJ_RIGHT 3U
#endif


typedef unsigned long AlgoDataTimeStamp_t;                           /* Algo data time-stamp type (32 bit variant) @min:0 @max:4294967295 */ /* [Satisfies_rte sws 1188] */
typedef unsigned short AlgoCycleCounter_t;                           /* Algo cycle counter @min:0 @max:65535 */ /* [Satisfies_rte sws 1188] */
typedef unsigned char AlgoSignalState_t;                             /* Algo signal state enumeration @min: 0 @max:2 @values: enum { AL_SIG_STATE_INVALID=2,AL_SIG_STATE_INIT=0,AL_SIG_STATE_OK=1,} */ /* [Satisfies_rte sws 1188] */

typedef struct SignalHeader_t                                        /* [Satisfies_rte sws 1191] */
{
  AlgoDataTimeStamp_t uiTimeStamp;
  AlgoCycleCounter_t uiMeasurementCounter;
  AlgoCycleCounter_t uiCycleCounter;
  AlgoSignalState_t eSigStatus;
} SignalHeader_t;                                                    /* Common header for all structured data types */

// Namespaces with the versioned structure(s)

namespace FCT_CamLaneInputData_V2
{
#pragma pack (push, 1)
  typedef struct SignalHeader1_t                                     /* [Satisfies_rte sws 1191] */
  {
    unsigned __int32 uiTimeStamp;
    unsigned __int16 uiMeasurementCounter;
    unsigned __int16 uiCycleCounter;
    unsigned __int8 eSigStatus;
  } SignalHeader1_t;                                                 /* Common header for all structured data types */

#pragma pack (1)
  typedef struct Marker1_t
  {
    unsigned __int32 uiQuality;
    float fDistance;
    float fCurvature;
    float fCurvatureRate;
    float fYaw;
    float fLookaheadDistance;
    unsigned __int32 aiMarkerTypes[3];
    unsigned __int32 aiMarkerColors[3];
  } Marker1_t;

#pragma pack (1)
  typedef struct                                                     /* [Satisfies_rte sws 1191] */
  {
    __int32 CS_MULTIPLE_MARKER;
    __int32 CS_LEFT_BARRIER;
    __int32 CS_RIGHT_BARRIER;
    __int32 CS_CROSSING_MARKER;
    __int32 CS_INHIBIT_SINGLE_LINE;
    __int32 CS_HOLD;
  } ConstructionSite1_t;                                             /* Information if lane markers indicate a construction site */

#pragma pack (1)
  typedef struct
  {
    unsigned long uiVersionNumber;
    SignalHeader1_t sSigHeader;
    Marker1_t LeftMarker;
    Marker1_t RightMarker;
    Marker1_t LeftAdjacentMarker;
    Marker1_t RightAdjacentMarker;
    ConstructionSite1_t sConstructionSite;
  } FCT_CamLaneInputData_t;
#pragma pack (pop)
} // end of namespace FCT_CamLaneInputData_V2


namespace FCT_CamLaneInputData_V3
{
  typedef unsigned char t_MarkerType;                                /* Type of lane marker @min: 0 @max:17 @values: enum { CL_MARKER_TYPE_DASHED=1,CL_MARKER_TYPE_RESERVED1=2,CL_MARKER_TYPE_RESERVED2=3,CL_MARKER_TYPE_ROADSHOULDER=14,CL_MARKER_TYPE_DECORATION=7,CL_MARKER_TYPE_LOWCURB=10,CL_MARKER_TYPE_NARROWDASHED=9,CL_MARKER_TYPE_SNA=15,CL_MARKER_TYPE_UNCLASSIFIED=5,CL_MARKER_TYPE_CONTINUOUS=0,CL_MARKER_TYPE_GRASS=16,CL_MARKER_TYPE_SEPARATING=8,CL_MARKER_TYPE_MISCELLANEOUS=17,CL_MARKER_TYPE_CRASHBARRIER=12,CL_MARKER_TYPE_WALL=13,CL_MARKER_TYPE_HIGHCURB=11,CL_MARKER_TYPE_NOLINEDETECTED=4,CL_MARKER_TYPE_DOTTED=6,} */ /* [Satisfies_rte sws 1188] */
  typedef unsigned char t_MarkerColor;                               /* Lane marker color @min: 0 @max:9 @values: enum { CL_MARKER_COLOR_WHITE=1,CL_MARKER_COLOR_GREEN=4,CL_MARKER_COLOR_RED=5,CL_MARKER_COLOR_UNKNOWN=0,CL_MARKER_COLOR_BLUE=3,CL_MARKER_COLOR_UNDEFINED3=9,CL_MARKER_COLOR_UNDEFINED2=8,CL_MARKER_COLOR_UNDEFINED1=7,CL_MARKER_COLOR_SNA=6,CL_MARKER_COLOR_YELLOW=2,} */ /* [Satisfies_rte sws 1188] */

  typedef struct                                                     /* [Satisfies_rte sws 1191] */
  {
    float f_C0;
    float f_C1;
    float f_Length;
  } t_CourseInfoSeg;                                                 /* Information about the detected course of the camera lane (CL) for the first segement */

  typedef struct                                                     /* [Satisfies_rte sws 1191] */
  {
    float f_Angle;
    t_CourseInfoSeg CourseInfoSegNear;
  } t_CourseInfo;                                                    /* Information about the detected course of the camera lane (CL) */

  typedef struct                                                     /* [Satisfies_rte sws 1191] */
  {
    float f_MarkerDist;
    t_MarkerColor MarkerColor;
    t_MarkerType MarkerType;
    unsigned char u_ExistanceProbability;
  } t_LaneMarkerInfo;                                                /* Information about the detected camera lane markers */

  typedef struct                                                     /* [Satisfies_rte sws 1191] */
  {
    boolean b_MultipleMarker;
    boolean b_LeftBarrier;
    boolean b_RightBarrier;
    boolean b_CrossingMarker;
    boolean b_InhibitSingleLane;
    boolean b_Hold;
  } t_ConstructionSite;                                              /* Information if lane markers indicate a construction site */

  typedef t_CourseInfo CourseInfo_array_t[4];                        /* Information about the detected course of the camera lane (CL) */ /* [Satisfies_rte sws 1189] */

  typedef t_LaneMarkerInfo LaneMarkerInfo_array_t[4];                /* Information about the detected camera lane markers */ /* [Satisfies_rte sws 1189] */

  typedef struct
  {
    unsigned long uiVersionNumber;
    SignalHeader_t sSigHeader;
    CourseInfo_array_t CourseInfo;
    LaneMarkerInfo_array_t LaneMarkerInfo;
    t_ConstructionSite ConstructionSite;
  } FCT_CamLaneInputData_t;
} // end of namespace FCT_CamLaneInputData_V3


namespace FCT_CamLaneInputData_V4
{
  typedef unsigned char t_MarkerType;                                /* Type of lane marker @min: 0 @max:17 @values: enum { CL_MARKER_TYPE_DASHED=1,CL_MARKER_TYPE_RESERVED1=2,CL_MARKER_TYPE_RESERVED2=3,CL_MARKER_TYPE_ROADSHOULDER=14,CL_MARKER_TYPE_DECORATION=7,CL_MARKER_TYPE_LOWCURB=10,CL_MARKER_TYPE_NARROWDASHED=9,CL_MARKER_TYPE_SNA=15,CL_MARKER_TYPE_UNCLASSIFIED=5,CL_MARKER_TYPE_CONTINUOUS=0,CL_MARKER_TYPE_GRASS=16,CL_MARKER_TYPE_SEPARATING=8,CL_MARKER_TYPE_MISCELLANEOUS=17,CL_MARKER_TYPE_CRASHBARRIER=12,CL_MARKER_TYPE_WALL=13,CL_MARKER_TYPE_HIGHCURB=11,CL_MARKER_TYPE_NOLINEDETECTED=4,CL_MARKER_TYPE_DOTTED=6,} */ /* [Satisfies_rte sws 1188] */
  typedef unsigned char t_MarkerColor;                               /* Lane marker color @min: 0 @max:9 @values: enum { CL_MARKER_COLOR_WHITE=1,CL_MARKER_COLOR_GREEN=4,CL_MARKER_COLOR_RED=5,CL_MARKER_COLOR_UNKNOWN=0,CL_MARKER_COLOR_BLUE=3,CL_MARKER_COLOR_UNDEFINED3=9,CL_MARKER_COLOR_UNDEFINED2=8,CL_MARKER_COLOR_UNDEFINED1=7,CL_MARKER_COLOR_SNA=6,CL_MARKER_COLOR_YELLOW=2,} */ /* [Satisfies_rte sws 1188] */

  typedef struct                                                     /* [Satisfies_rte sws 1191] */
  {
    float f_C0;
    float f_C1;
#if (ARS4A0 == (SWITCH_ON))
    float f_StartDistX;
#endif
    float f_Length;
  } t_CourseInfoSeg;                                                 /* Information about the detected course of the camera lane (CL) for the first segement */

  typedef struct                                                     /* [Satisfies_rte sws 1191] */
  {
    float f_Angle;
    t_CourseInfoSeg CourseInfoSegNear;
#if (ARS430BW18 == (SWITCH_ON)) || (ARS4B0 == (SWITCH_ON)) || (ARS4R0 == (SWITCH_ON))
    t_CourseInfoSeg CourseInfoSegFar;
#endif
  } t_CourseInfo;                                                    /* Information about the detected course of the camera lane (CL) */

  typedef struct                                                     /* [Satisfies_rte sws 1191] */
  {
    float f_MarkerDist;
#if (ARS430BW18 == (SWITCH_ON)) || (ARS4B0 == (SWITCH_ON)) || (ARS410EUNCAP == (SWITCH_ON)) || (ARS4T0 == (SWITCH_ON)) || (ARS4E0 == (SWITCH_ON)) || (ARS4J0 == (SWITCH_ON)) || (ARS4A0 == (SWITCH_ON)) || (ARS4R0 == (SWITCH_ON))
    t_MarkerColor MarkerColor;
    t_MarkerType MarkerType;
#endif
    unsigned char u_ExistanceProbability;
#if (ARS430BW18 == (SWITCH_ON)) || (ARS4B0 == (SWITCH_ON)) || (ARS4R0 == (SWITCH_ON)) || (MFC431 == (SWITCH_ON))
    boolean b_MarkerElevated;
#endif
  } t_LaneMarkerInfo;                                                /* Information about the detected camera lane markers */

  typedef t_CourseInfo CourseInfo_array_t[4];                        /* Information about the detected course of the camera lane (CL) */ /* [Satisfies_rte sws 1189] */

  typedef t_LaneMarkerInfo LaneMarkerInfo_array_t[4];                /* Information about the detected camera lane markers */ /* [Satisfies_rte sws 1189] */

  typedef struct
  {
    unsigned long uiVersionNumber;
    SignalHeader_t sSigHeader;
    CourseInfo_array_t CourseInfo;
    LaneMarkerInfo_array_t LaneMarkerInfo;
    FCT_CamLaneInputData_V3::t_ConstructionSite ConstructionSite;
  } FCT_CamLaneInputData_t;
} // end of namespace FCT_CamLaneInputData_V4


namespace FCT_CamLaneInputData_V5
{
  typedef unsigned char t_MarkerType;                                /* Type of lane marker @min: 0 @max:17 @values: enum { CL_MARKER_TYPE_DASHED=1,CL_MARKER_TYPE_RESERVED1=2,CL_MARKER_TYPE_RESERVED2=3,CL_MARKER_TYPE_ROADSHOULDER=14,CL_MARKER_TYPE_DECORATION=7,CL_MARKER_TYPE_LOWCURB=10,CL_MARKER_TYPE_NARROWDASHED=9,CL_MARKER_TYPE_SNA=15,CL_MARKER_TYPE_UNCLASSIFIED=5,CL_MARKER_TYPE_CONTINUOUS=0,CL_MARKER_TYPE_GRASS=16,CL_MARKER_TYPE_SEPARATING=8,CL_MARKER_TYPE_MISCELLANEOUS=17,CL_MARKER_TYPE_CRASHBARRIER=12,CL_MARKER_TYPE_WALL=13,CL_MARKER_TYPE_HIGHCURB=11,CL_MARKER_TYPE_NOLINEDETECTED=4,CL_MARKER_TYPE_DOTTED=6,} */ /* [Satisfies_rte sws 1188] */
  typedef unsigned char t_MarkerColor;                               /* Lane marker color @min: 0 @max:9 @values: enum { CL_MARKER_COLOR_WHITE=1,CL_MARKER_COLOR_GREEN=4,CL_MARKER_COLOR_RED=5,CL_MARKER_COLOR_UNKNOWN=0,CL_MARKER_COLOR_BLUE=3,CL_MARKER_COLOR_UNDEFINED3=9,CL_MARKER_COLOR_UNDEFINED2=8,CL_MARKER_COLOR_UNDEFINED1=7,CL_MARKER_COLOR_SNA=6,CL_MARKER_COLOR_YELLOW=2,} */ /* [Satisfies_rte sws 1188] */
  typedef unsigned char t_MarkerMergeSplit;                          /* Information if two camera lanes merge or if camera lane splits into two lanes @min: 0 @max:4 @values: enum { CL_MARKER_MERGE_SPLIT_UNKNOWN=0,CL_MARKER_NO_MERGE_SPLIT=1,CL_MARKER_SPLIT=2,CL_MARKER_MERGE=3,CL_MARKER_MERGE_SPLIT_SNA=4 } */

  typedef struct                                                     /* [Satisfies_rte sws 1191] */
  {
    float f_C0;
    float f_C1;
#if (ARS430BW18 == (SWITCH_ON)) || (ARS4A0 == (SWITCH_ON))
    float f_StartDistX;
#endif
    float f_Length;
  } t_CourseInfoSeg;                                                 /* Information about the detected course of the camera lane (CL) for the first segement */

  typedef struct                                                     /* [Satisfies_rte sws 1191] */
  {
    float f_Angle;
#if (ARS430BW18 == (SWITCH_ON))
    float f_AngleSegFar;
#endif
    t_CourseInfoSeg CourseInfoSegNear;
#if (ARS430BW18 == (SWITCH_ON)) || (ARS4B0 == (SWITCH_ON)) || (ARS4R0 == (SWITCH_ON))
    t_CourseInfoSeg CourseInfoSegFar;
#endif
  } t_CourseInfo;                                                    /* Information about the detected course of the camera lane (CL) */

  typedef struct                                                     /* [Satisfies_rte sws 1191] */
  {
    float f_MarkerDist;
#if (ARS430BW18 == (SWITCH_ON)) || (ARS4B0 == (SWITCH_ON)) || (ARS410EUNCAP == (SWITCH_ON)) || (ARS4T0 == (SWITCH_ON)) || (ARS4E0 == (SWITCH_ON)) || (ARS4J0 == (SWITCH_ON)) || (ARS4A0 == (SWITCH_ON)) || (ARS4R0 == (SWITCH_ON))
    t_MarkerColor MarkerColor;
    t_MarkerType MarkerType;
#endif
    unsigned char u_ExistanceProbability;
#if (ARS430BW18 == (SWITCH_ON))
    unsigned char u_ExistanceProbMarkerType;
#endif
#if (ARS430BW18 == (SWITCH_ON)) || (ARS4B0 == (SWITCH_ON)) || (ARS4R0 == (SWITCH_ON)) || (MFC431 == (SWITCH_ON))
    boolean b_MarkerElevated;
#endif
#if (ARS430BW18 == (SWITCH_ON))
    unsigned char u_LaneID;
    t_MarkerMergeSplit MarkerMergeSplit;
    float f_DistMarkerMergeSplit;
    unsigned char u_LaneMergeSplitToID;
#endif
  } t_LaneMarkerInfo;                                                /* Information about the detected camera lane markers */

  typedef t_CourseInfo CourseInfo_array_t[4];                        /* Information about the detected course of the camera lane (CL) */ /* [Satisfies_rte sws 1189] */

  typedef t_LaneMarkerInfo LaneMarkerInfo_array_t[4];                /* Information about the detected camera lane markers */ /* [Satisfies_rte sws 1189] */

  typedef struct
  {
    unsigned long uiVersionNumber;
    SignalHeader_t sSigHeader;
    CourseInfo_array_t CourseInfo;
    LaneMarkerInfo_array_t LaneMarkerInfo;
    FCT_CamLaneInputData_V3::t_ConstructionSite ConstructionSite;
  } FCT_CamLaneInputData_t;
} // end of namespace FCT_CamLaneInputData_V5


// Generic namespace and structure, which includes all variances of the versioned namespaces

namespace FCT_CamLaneInputData_GenAll
{
  typedef struct
  {
    unsigned long uiVersionNumber;
    SignalHeader_t sSigHeader;
    FCT_CamLaneInputData_V2::Marker1_t LeftMarker;
    FCT_CamLaneInputData_V2::Marker1_t RightMarker;
    FCT_CamLaneInputData_V2::Marker1_t LeftAdjacentMarker;
    FCT_CamLaneInputData_V2::Marker1_t RightAdjacentMarker;
    FCT_CamLaneInputData_V2::ConstructionSite1_t sConstructionSite;
    FCT_CamLaneInputData_V3::CourseInfo_array_t CourseInfo;
    FCT_CamLaneInputData_V3::LaneMarkerInfo_array_t LaneMarkerInfo;
    FCT_CamLaneInputData_V3::t_ConstructionSite ConstructionSite;
    FCT_CamLaneInputData_V4::CourseInfo_array_t CourseInfoV4;
    FCT_CamLaneInputData_V4::LaneMarkerInfo_array_t LaneMarkerInfoV4;
    FCT_CamLaneInputData_V5::CourseInfo_array_t CourseInfoV5;
    FCT_CamLaneInputData_V5::LaneMarkerInfo_array_t LaneMarkerInfoV5;
  } FCT_CamLaneInputData_t;
}


class CConvFctCamLaneInputData : public CSimConverterBase
{
  // the list of dependency names used inside by the converter
  //static const TCHAR *DEP_NAMES[];

  // here we define the index of each dependency for quick acces
  // the order here should match with the order from DEP_NAMES array
  enum eDepIdx
  {
    // add new dependencies here
    DEP_COUNT
  };

  FCT_CamLaneInputData_GenAll::FCT_CamLaneInputData_t m_Buf_GenAll;
  FCT_CamLaneInputData_V2::FCT_CamLaneInputData_t m_Buf_V2;
  FCT_CamLaneInputData_V3::FCT_CamLaneInputData_t m_Buf_V3;
  FCT_CamLaneInputData_V4::FCT_CamLaneInputData_t m_Buf_V4;
  FCT_CamLaneInputData_V5::FCT_CamLaneInputData_t m_Buf_V5;

public:

  CConvFctCamLaneInputData(void) : CSimConverterBase(NULL/*DEP_NAMES*/, DEP_COUNT)
  {
    InitFctCamLaneInputData(m_Buf_V2, 1);
    InitFctCamLaneInputData(m_Buf_V3, 2);
    InitFctCamLaneInputData(m_Buf_V4, 4);
    InitFctCamLaneInputData(m_Buf_GenAll, 2);
  };


  // Not implemented copy constructor to get linker error
  CConvFctCamLaneInputData(const CConvFctCamLaneInputData & init);

  virtual ~CConvFctCamLaneInputData(void)
  {
  };

  // IConverterDestroy::Destroy implementation
  virtual void Destroy()
  {
    delete this;
  };

  // IConverter::GetTypeName implementation
  virtual const char *GetTypeName(void)
  {
    return "t_CamLaneInputData";
  };

  // Initialization of header
  template <typename T> static void InitFctCamLaneInputData (T & Dest, unsigned long VersionNumber)
  {
    ::memset(&(Dest), 0, sizeof(Dest));
    Dest.uiVersionNumber = VersionNumber;
  }

  /* **************************************************************************** 
    @fn            IsPortSupported */ /*!  
    @brief         Check Port for support
    @description   Used to check if a given port is in the list(s) of supported versions.
                   The version info is in the arrays VERSION_NUMBERS and SUPPORTED_SIZE
    @return        bool
    @param[in]     unsigned long ulPortSize
    @param[in]     const IVersionInfo *pPortVersion
    @pre           
    @post          (no changes)
    @date          14.01.2016
    @todo          
    @author        Thomas Berndt
  **************************************************************************** */
  bool IsPortSupported(unsigned long ulPortSize, const IVersionInfo *pPortVersion) const
  {
    for (int nI = 0; nI < FCT_CAMLANEINPUTDATA_VERSION_COUNT; nI++)
    {
      if ((pPortVersion == NULL) || pPortVersion->Equals(VERSION_NUMBERS[nI]))
      {
        if (ulPortSize == SUPPORTED_SIZE[nI])
        {
          return true;
        }
      }
    };
    return false;
  };

  /** returns:
   *   SIM_ERR_OK - when this value can be used
   *   SIM_ERR_USE_VALUE_FROM_PPORT - when the conversion is not implemented here
   *                                  and the value from Provide Port must be used
   *   SIM_ERR_UNADAPTABLE_DATA_PORTS - if a conversion is needed but isn't possible (not implemented)
   */
  long ConvertData(
    SimPortDataTypes_t eRPortType, unsigned long ulRPortSize, const IVersionInfo &requestPortVersionInfo,
    SimPortDataTypes_t ePPortType, unsigned long ulPPortSize, const IVersionInfo *pProvidePortVersionInfo,
    void *pPPortData,
    void **pOutData, unsigned long &ulOutSize);

  /** returns:
   *   SIM_ERR_OK - when this value can be used
   *   SIM_ERR_USE_DEFAULT_VALUE_FROM_RPORT - when the default vaule is not implemented here
   *                                          and the default value from Request Port must be used
   */
  long GetDefaultValue(
    SimPortDataTypes_t eRPortType, unsigned long ulRPortSize, const IVersionInfo& requestPortVersionInfo,
    void **pDefaultData, unsigned long& ulDefaultSize);

protected:

  // used to check if an unversioned PPort is compatible with a certain version of RPort
  bool IsVersionCompatibleWithType(
    SimPortDataTypes_t eRPortType, unsigned long ulRPortSize, const IVersionInfo& requestPortVersionInfo,
    SimPortDataTypes_t ePPortType, unsigned long ulPPortSize);

  // used to check if ports are compatible between different versions
  bool AreVersionsCompatible(
    SimPortDataTypes_t eRPortType, unsigned long ulRPortSize, const IVersionInfo& requestPortVersionInfo,
    SimPortDataTypes_t ePPortType, unsigned long ulPPortSize, const IVersionInfo& providePortVersionInfo);
private:
  static void Convert_V2_to_Gen(FCT_CamLaneInputData_GenAll::FCT_CamLaneInputData_t & Dest, const FCT_CamLaneInputData_V2::FCT_CamLaneInputData_t & Src);
  static void Convert_V3_to_Gen(FCT_CamLaneInputData_GenAll::FCT_CamLaneInputData_t & Dest, const FCT_CamLaneInputData_V3::FCT_CamLaneInputData_t & Src);
  static void Convert_V4_to_Gen(FCT_CamLaneInputData_GenAll::FCT_CamLaneInputData_t & Dest, const FCT_CamLaneInputData_V4::FCT_CamLaneInputData_t & Src);
  static void Convert_V5_to_Gen(FCT_CamLaneInputData_GenAll::FCT_CamLaneInputData_t & Dest, const FCT_CamLaneInputData_V5::FCT_CamLaneInputData_t & Src);
  static void Convert_Gen_to_V3(FCT_CamLaneInputData_V3::FCT_CamLaneInputData_t & Dest, const FCT_CamLaneInputData_GenAll::FCT_CamLaneInputData_t & Src);
  static void Convert_Gen_to_V2(FCT_CamLaneInputData_V2::FCT_CamLaneInputData_t & Dest, const FCT_CamLaneInputData_GenAll::FCT_CamLaneInputData_t & Src);
  static void Convert_Gen_to_V4(FCT_CamLaneInputData_V4::FCT_CamLaneInputData_t & Dest, const FCT_CamLaneInputData_GenAll::FCT_CamLaneInputData_t & Src);
  static void Convert_Gen_to_V5(FCT_CamLaneInputData_V5::FCT_CamLaneInputData_t & Dest, const FCT_CamLaneInputData_GenAll::FCT_CamLaneInputData_t & Src);

  static CVersionInfoImpl BASE_VERSION;
  static CVersionInfoImpl Version2;
  static CVersionInfoImpl Version3;
  static CVersionInfoImpl Version4;
  static CVersionInfoImpl Version5;

  enum eFCT_CAMLANEINPUTDATA
  {
    FCT_CAMLANEINPUTDATA_V2,
    FCT_CAMLANEINPUTDATA_V3,
    FCT_CAMLANEINPUTDATA_V4,
    FCT_CAMLANEINPUTDATA_V5,
    FCT_CAMLANEINPUTDATA_VERSION_COUNT
  };

  static const unsigned long SUPPORTED_SIZE[FCT_CAMLANEINPUTDATA_VERSION_COUNT];

  static const CVersionInfoImpl * const VERSION_NUMBERS[FCT_CAMLANEINPUTDATA_VERSION_COUNT];
};

//const TCHAR *CConvFctCamLaneInputData::DEP_NAMES[CConvFctCamLaneInputData::DEP_COUNT] = {_T(""), _T(""), _T("")};

CVersionInfoImpl CConvFctCamLaneInputData::BASE_VERSION(0, 0, 0);
CVersionInfoImpl CConvFctCamLaneInputData::Version2(0, 0, 2);
CVersionInfoImpl CConvFctCamLaneInputData::Version3(0, 0, 3);
CVersionInfoImpl CConvFctCamLaneInputData::Version4(0, 0, 4);
CVersionInfoImpl CConvFctCamLaneInputData::Version5(0, 0, 5);

const unsigned long CConvFctCamLaneInputData::SUPPORTED_SIZE[CConvFctCamLaneInputData::FCT_CAMLANEINPUTDATA_VERSION_COUNT]=
{
  sizeof(FCT_CamLaneInputData_V2::FCT_CamLaneInputData_t),
  sizeof(FCT_CamLaneInputData_V3::FCT_CamLaneInputData_t),
  sizeof(FCT_CamLaneInputData_V4::FCT_CamLaneInputData_t),
  sizeof(FCT_CamLaneInputData_V5::FCT_CamLaneInputData_t)
};

const CVersionInfoImpl * const CConvFctCamLaneInputData::VERSION_NUMBERS[CConvFctCamLaneInputData::FCT_CAMLANEINPUTDATA_VERSION_COUNT] =
{
  &Version2,
  &Version3,
  &Version4,
  &Version5
};

// conversion functions: For every version there is one to convert to generic structure and one to convert from generic

void CConvFctCamLaneInputData::Convert_V2_to_Gen(FCT_CamLaneInputData_GenAll::FCT_CamLaneInputData_t & Dest, const FCT_CamLaneInputData_V2::FCT_CamLaneInputData_t & Src)
{
  Dest.uiVersionNumber = Src.uiVersionNumber;
  Dest.sSigHeader.uiTimeStamp = Src.sSigHeader.uiTimeStamp;
  Dest.sSigHeader.uiMeasurementCounter = Src.sSigHeader.uiMeasurementCounter;
  Dest.sSigHeader.uiCycleCounter = Src.sSigHeader.uiCycleCounter;
  Dest.sSigHeader.eSigStatus = Src.sSigHeader.eSigStatus;

  Dest.LeftMarker = Src.LeftMarker;
  Dest.RightMarker = Src.RightMarker;
  Dest.LeftAdjacentMarker = Src.LeftAdjacentMarker;
  Dest.RightAdjacentMarker = Src.RightAdjacentMarker;
  Dest.sConstructionSite = Src.sConstructionSite;

  Dest.CourseInfo[CL_CAM_LANE_MK_LEFT].f_Angle                    = Src.LeftMarker.fYaw;
  Dest.CourseInfo[CL_CAM_LANE_MK_LEFT].CourseInfoSegNear.f_C0     = Src.LeftMarker.fCurvature;
  Dest.CourseInfo[CL_CAM_LANE_MK_LEFT].CourseInfoSegNear.f_C1     = Src.LeftMarker.fCurvatureRate;
  Dest.CourseInfo[CL_CAM_LANE_MK_LEFT].CourseInfoSegNear.f_Length = Src.LeftMarker.fLookaheadDistance;
  Dest.LaneMarkerInfo[CL_CAM_LANE_MK_LEFT].f_MarkerDist           = Src.LeftMarker.fDistance;
  Dest.LaneMarkerInfo[CL_CAM_LANE_MK_LEFT].MarkerColor            = Src.LeftMarker.aiMarkerColors[0];
  Dest.LaneMarkerInfo[CL_CAM_LANE_MK_LEFT].MarkerType             = Src.LeftMarker.aiMarkerTypes[0];
  Dest.LaneMarkerInfo[CL_CAM_LANE_MK_LEFT].u_ExistanceProbability = Src.LeftMarker.uiQuality;

  Dest.CourseInfo[CL_CAM_LANE_MK_RIGHT].f_Angle                    = Src.RightMarker.fYaw;
  Dest.CourseInfo[CL_CAM_LANE_MK_RIGHT].CourseInfoSegNear.f_C0     = Src.RightMarker.fCurvature;
  Dest.CourseInfo[CL_CAM_LANE_MK_RIGHT].CourseInfoSegNear.f_C1     = Src.RightMarker.fCurvatureRate;
  Dest.CourseInfo[CL_CAM_LANE_MK_RIGHT].CourseInfoSegNear.f_Length = Src.RightMarker.fLookaheadDistance;
  Dest.LaneMarkerInfo[CL_CAM_LANE_MK_RIGHT].f_MarkerDist           = Src.RightMarker.fDistance;
  Dest.LaneMarkerInfo[CL_CAM_LANE_MK_RIGHT].MarkerColor            = Src.RightMarker.aiMarkerColors[0];
  Dest.LaneMarkerInfo[CL_CAM_LANE_MK_RIGHT].MarkerType             = Src.RightMarker.aiMarkerTypes[0];
  Dest.LaneMarkerInfo[CL_CAM_LANE_MK_RIGHT].u_ExistanceProbability = Src.RightMarker.uiQuality;

  Dest.CourseInfo[CL_CAM_LANE_MK_ADJ_LEFT].f_Angle                    = Src.LeftAdjacentMarker.fYaw;
  Dest.CourseInfo[CL_CAM_LANE_MK_ADJ_LEFT].CourseInfoSegNear.f_C0     = Src.LeftAdjacentMarker.fCurvature;
  Dest.CourseInfo[CL_CAM_LANE_MK_ADJ_LEFT].CourseInfoSegNear.f_C1     = Src.LeftAdjacentMarker.fCurvatureRate;
  Dest.CourseInfo[CL_CAM_LANE_MK_ADJ_LEFT].CourseInfoSegNear.f_Length = Src.LeftAdjacentMarker.fLookaheadDistance;
  Dest.LaneMarkerInfo[CL_CAM_LANE_MK_ADJ_LEFT].f_MarkerDist           = Src.LeftAdjacentMarker.fDistance;
  Dest.LaneMarkerInfo[CL_CAM_LANE_MK_ADJ_LEFT].MarkerColor            = Src.LeftAdjacentMarker.aiMarkerColors[0];
  Dest.LaneMarkerInfo[CL_CAM_LANE_MK_ADJ_LEFT].MarkerType             = Src.LeftAdjacentMarker.aiMarkerTypes[0];
  Dest.LaneMarkerInfo[CL_CAM_LANE_MK_ADJ_LEFT].u_ExistanceProbability = Src.LeftAdjacentMarker.uiQuality;

  Dest.CourseInfo[CL_CAM_LANE_MK_ADJ_RIGHT].f_Angle                    = Src.RightAdjacentMarker.fYaw;
  Dest.CourseInfo[CL_CAM_LANE_MK_ADJ_RIGHT].CourseInfoSegNear.f_C0     = Src.RightAdjacentMarker.fCurvature;
  Dest.CourseInfo[CL_CAM_LANE_MK_ADJ_RIGHT].CourseInfoSegNear.f_C1     = Src.RightAdjacentMarker.fCurvatureRate;
  Dest.CourseInfo[CL_CAM_LANE_MK_ADJ_RIGHT].CourseInfoSegNear.f_Length = Src.RightAdjacentMarker.fLookaheadDistance;
  Dest.LaneMarkerInfo[CL_CAM_LANE_MK_ADJ_RIGHT].f_MarkerDist           = Src.RightAdjacentMarker.fDistance;
  Dest.LaneMarkerInfo[CL_CAM_LANE_MK_ADJ_RIGHT].MarkerColor            = Src.RightAdjacentMarker.aiMarkerColors[0];
  Dest.LaneMarkerInfo[CL_CAM_LANE_MK_ADJ_RIGHT].MarkerType             = Src.RightAdjacentMarker.aiMarkerTypes[0];
  Dest.LaneMarkerInfo[CL_CAM_LANE_MK_ADJ_RIGHT].u_ExistanceProbability = Src.RightAdjacentMarker.uiQuality;

  Dest.ConstructionSite.b_MultipleMarker    = (boolean) (Src.sConstructionSite.CS_MULTIPLE_MARKER     & 0xff);
  Dest.ConstructionSite.b_LeftBarrier       = (boolean) (Src.sConstructionSite.CS_LEFT_BARRIER        & 0xff);
  Dest.ConstructionSite.b_RightBarrier      = (boolean) (Src.sConstructionSite.CS_RIGHT_BARRIER       & 0xff);
  Dest.ConstructionSite.b_CrossingMarker    = (boolean) (Src.sConstructionSite.CS_CROSSING_MARKER     & 0xff);
  Dest.ConstructionSite.b_InhibitSingleLane = (boolean) (Src.sConstructionSite.CS_INHIBIT_SINGLE_LINE & 0xff);
  Dest.ConstructionSite.b_Hold              = (boolean) (Src.sConstructionSite.CS_HOLD                & 0xff);

  for (int nI = 0; nI < 4; nI++)
  {
    Dest.CourseInfoV4[nI].f_Angle                    = Dest.CourseInfo[nI].f_Angle;
    Dest.CourseInfoV4[nI].CourseInfoSegNear.f_C0     = Dest.CourseInfo[nI].CourseInfoSegNear.f_C0;
    Dest.CourseInfoV4[nI].CourseInfoSegNear.f_C1     = Dest.CourseInfo[nI].CourseInfoSegNear.f_C1;
    Dest.CourseInfoV4[nI].CourseInfoSegNear.f_Length = Dest.CourseInfo[nI].CourseInfoSegNear.f_Length;
    Dest.LaneMarkerInfoV4[nI].f_MarkerDist           = Dest.LaneMarkerInfo[nI].f_MarkerDist;
    Dest.LaneMarkerInfoV4[nI].MarkerColor            = Dest.LaneMarkerInfo[nI].MarkerColor;
    Dest.LaneMarkerInfoV4[nI].MarkerType             = Dest.LaneMarkerInfo[nI].MarkerType;
    Dest.LaneMarkerInfoV4[nI].u_ExistanceProbability = Dest.LaneMarkerInfo[nI].u_ExistanceProbability;

    Dest.CourseInfoV5[nI].f_Angle                    = Dest.CourseInfo[nI].f_Angle;
    Dest.CourseInfoV5[nI].CourseInfoSegNear.f_C0     = Dest.CourseInfo[nI].CourseInfoSegNear.f_C0;
    Dest.CourseInfoV5[nI].CourseInfoSegNear.f_C1     = Dest.CourseInfo[nI].CourseInfoSegNear.f_C1;
    Dest.CourseInfoV5[nI].CourseInfoSegNear.f_Length = Dest.CourseInfo[nI].CourseInfoSegNear.f_Length;
    Dest.LaneMarkerInfoV5[nI].f_MarkerDist           = Dest.LaneMarkerInfo[nI].f_MarkerDist;
    Dest.LaneMarkerInfoV5[nI].MarkerColor            = Dest.LaneMarkerInfo[nI].MarkerColor;
    Dest.LaneMarkerInfoV5[nI].MarkerType             = Dest.LaneMarkerInfo[nI].MarkerType;
    Dest.LaneMarkerInfoV5[nI].u_ExistanceProbability = Dest.LaneMarkerInfo[nI].u_ExistanceProbability;
  }
}

void CConvFctCamLaneInputData::Convert_V3_to_Gen(FCT_CamLaneInputData_GenAll::FCT_CamLaneInputData_t & Dest, const FCT_CamLaneInputData_V3::FCT_CamLaneInputData_t & Src)
{
  Dest.uiVersionNumber = Src.uiVersionNumber;
  Dest.sSigHeader = Src.sSigHeader;
  memcpy(Dest.CourseInfo, Src.CourseInfo, sizeof(Dest.CourseInfo));
  memcpy(Dest.LaneMarkerInfo, Src.LaneMarkerInfo, sizeof(Dest.LaneMarkerInfo));
  Dest.ConstructionSite = Src.ConstructionSite;
}

void CConvFctCamLaneInputData::Convert_V4_to_Gen(FCT_CamLaneInputData_GenAll::FCT_CamLaneInputData_t & Dest, const FCT_CamLaneInputData_V4::FCT_CamLaneInputData_t & Src)
{
  Dest.uiVersionNumber = Src.uiVersionNumber;
  Dest.sSigHeader = Src.sSigHeader;
  memcpy(Dest.CourseInfoV4, Src.CourseInfo, sizeof(Dest.CourseInfo));
  memcpy(Dest.LaneMarkerInfoV4, Src.LaneMarkerInfo, sizeof(Dest.LaneMarkerInfo));
  Dest.ConstructionSite = Src.ConstructionSite;
  for (int nI = 0; nI < 4; nI++)
  {
    Dest.CourseInfo[nI].f_Angle                        = Dest.CourseInfoV4[nI].f_Angle;
    Dest.CourseInfo[nI].CourseInfoSegNear.f_C0         = Dest.CourseInfoV4[nI].CourseInfoSegNear.f_C0;
    Dest.CourseInfo[nI].CourseInfoSegNear.f_C1         = Dest.CourseInfoV4[nI].CourseInfoSegNear.f_C1;
    Dest.CourseInfo[nI].CourseInfoSegNear.f_Length     = Dest.CourseInfoV4[nI].CourseInfoSegNear.f_Length;
    Dest.LaneMarkerInfo[nI].f_MarkerDist               = Dest.LaneMarkerInfoV4[nI].f_MarkerDist;
    Dest.LaneMarkerInfo[nI].MarkerColor                = Dest.LaneMarkerInfoV4[nI].MarkerColor;
    Dest.LaneMarkerInfo[nI].MarkerType                 = Dest.LaneMarkerInfoV4[nI].MarkerType;
    Dest.LaneMarkerInfo[nI].u_ExistanceProbability     = Dest.LaneMarkerInfoV4[nI].u_ExistanceProbability;

    Dest.CourseInfoV5[nI].f_Angle                        = Dest.CourseInfoV4[nI].f_Angle;
    Dest.CourseInfoV5[nI].CourseInfoSegNear.f_C0         = Dest.CourseInfoV4[nI].CourseInfoSegNear.f_C0;
    Dest.CourseInfoV5[nI].CourseInfoSegNear.f_C1         = Dest.CourseInfoV4[nI].CourseInfoSegNear.f_C1;
#if (ARS4A0 == (SWITCH_ON))
    Dest.CourseInfoV5[nI].CourseInfoSegNear.f_StartDistX = Dest.CourseInfoV4[nI].CourseInfoSegNear.f_StartDistX;
#endif
    Dest.CourseInfoV5[nI].CourseInfoSegNear.f_Length     = Dest.CourseInfoV4[nI].CourseInfoSegNear.f_Length;
#if (ARS430BW18 == (SWITCH_ON)) || (ARS4B0 == (SWITCH_ON)) || (ARS4R0 == (SWITCH_ON))
    Dest.CourseInfoV5[nI].CourseInfoSegFar.f_C0          = Dest.CourseInfoV4[nI].CourseInfoSegFar.f_C0;
    Dest.CourseInfoV5[nI].CourseInfoSegFar.f_C1          = Dest.CourseInfoV4[nI].CourseInfoSegFar.f_C1;
#if (ARS4A0 == (SWITCH_ON))
    Dest.CourseInfoV5[nI].CourseInfoSegFar.f_StartDistX  = Dest.CourseInfoV4[nI].CourseInfoSegFar.f_StartDistX;
#endif
    Dest.CourseInfoV5[nI].CourseInfoSegFar.f_Length      = Dest.CourseInfoV5[nI].CourseInfoSegNear.f_Length;
#endif
    Dest.LaneMarkerInfoV5[nI].f_MarkerDist               = Dest.LaneMarkerInfoV4[nI].f_MarkerDist;
    Dest.LaneMarkerInfoV5[nI].MarkerColor                = Dest.LaneMarkerInfoV4[nI].MarkerColor;
    Dest.LaneMarkerInfoV5[nI].MarkerType                 = Dest.LaneMarkerInfoV4[nI].MarkerType;
    Dest.LaneMarkerInfoV5[nI].u_ExistanceProbability     = Dest.LaneMarkerInfoV4[nI].u_ExistanceProbability;
  }
}

void CConvFctCamLaneInputData::Convert_V5_to_Gen(FCT_CamLaneInputData_GenAll::FCT_CamLaneInputData_t & Dest, const FCT_CamLaneInputData_V5::FCT_CamLaneInputData_t & Src)
{
  Dest.uiVersionNumber = Src.uiVersionNumber;
  Dest.sSigHeader = Src.sSigHeader;
  memcpy(Dest.CourseInfoV5, Src.CourseInfo, sizeof(Dest.CourseInfo));
  memcpy(Dest.LaneMarkerInfoV5, Src.LaneMarkerInfo, sizeof(Dest.LaneMarkerInfo));
  Dest.ConstructionSite = Src.ConstructionSite;
  for (int nI = 0; nI < 4; nI++)
  {
    Dest.CourseInfo[nI].f_Angle                        = Dest.CourseInfoV5[nI].f_Angle;
    Dest.CourseInfo[nI].CourseInfoSegNear.f_C0         = Dest.CourseInfoV5[nI].CourseInfoSegNear.f_C0;
    Dest.CourseInfo[nI].CourseInfoSegNear.f_C1         = Dest.CourseInfoV5[nI].CourseInfoSegNear.f_C1;
    Dest.CourseInfo[nI].CourseInfoSegNear.f_Length     = Dest.CourseInfoV5[nI].CourseInfoSegNear.f_Length;
    Dest.LaneMarkerInfo[nI].f_MarkerDist               = Dest.LaneMarkerInfoV5[nI].f_MarkerDist;
    Dest.LaneMarkerInfo[nI].MarkerColor                = Dest.LaneMarkerInfoV5[nI].MarkerColor;
    Dest.LaneMarkerInfo[nI].MarkerType                 = Dest.LaneMarkerInfoV5[nI].MarkerType;
    Dest.LaneMarkerInfo[nI].u_ExistanceProbability     = Dest.LaneMarkerInfoV5[nI].u_ExistanceProbability;

    Dest.CourseInfoV4[nI].f_Angle                        = Dest.CourseInfoV5[nI].f_Angle;
    Dest.CourseInfoV4[nI].CourseInfoSegNear.f_C0         = Dest.CourseInfoV5[nI].CourseInfoSegNear.f_C0;
    Dest.CourseInfoV4[nI].CourseInfoSegNear.f_C1         = Dest.CourseInfoV5[nI].CourseInfoSegNear.f_C1;
#if (ARS4A0 == (SWITCH_ON))
    Dest.CourseInfoV4[nI].CourseInfoSegNear.f_StartDistX = Dest.CourseInfoV5[nI].CourseInfoSegNear.f_StartDistX;
#endif
    Dest.CourseInfoV4[nI].CourseInfoSegNear.f_Length     = Dest.CourseInfoV5[nI].CourseInfoSegNear.f_Length;
#if (ARS430BW18 == (SWITCH_ON)) || (ARS4B0 == (SWITCH_ON)) || (ARS4R0 == (SWITCH_ON))
    Dest.CourseInfoV4[nI].CourseInfoSegFar.f_C0          = Dest.CourseInfoV5[nI].CourseInfoSegFar.f_C0;
    Dest.CourseInfoV4[nI].CourseInfoSegFar.f_C1          = Dest.CourseInfoV5[nI].CourseInfoSegFar.f_C1;
#if (ARS4A0 == (SWITCH_ON))
    Dest.CourseInfoV4[nI].CourseInfoSegFar.f_StartDistX  = Dest.CourseInfoV5[nI].CourseInfoSegFar.f_StartDistX;
#endif
    Dest.CourseInfoV4[nI].CourseInfoSegFar.f_Length      = Dest.CourseInfoV5[nI].CourseInfoSegNear.f_Length;
#endif
    Dest.LaneMarkerInfoV4[nI].f_MarkerDist               = Dest.LaneMarkerInfoV5[nI].f_MarkerDist;
    Dest.LaneMarkerInfoV4[nI].MarkerColor                = Dest.LaneMarkerInfoV5[nI].MarkerColor;
    Dest.LaneMarkerInfoV4[nI].MarkerType                 = Dest.LaneMarkerInfoV5[nI].MarkerType;
    Dest.LaneMarkerInfoV4[nI].u_ExistanceProbability     = Dest.LaneMarkerInfoV5[nI].u_ExistanceProbability;
  }
}

void CConvFctCamLaneInputData::Convert_Gen_to_V2(FCT_CamLaneInputData_V2::FCT_CamLaneInputData_t & Dest, const FCT_CamLaneInputData_GenAll::FCT_CamLaneInputData_t & Src)
{
  //Dest.uiVersionNumber = Src.uiVersionNumber; Is set by InitFctCamLaneInputData(m_Buf_V2, 2);
  Dest.sSigHeader.uiTimeStamp = Src.sSigHeader.uiTimeStamp;
  Dest.sSigHeader.uiMeasurementCounter = Src.sSigHeader.uiMeasurementCounter;
  Dest.sSigHeader.uiCycleCounter = Src.sSigHeader.uiCycleCounter;
  Dest.sSigHeader.eSigStatus = Src.sSigHeader.eSigStatus;
}

void CConvFctCamLaneInputData::Convert_Gen_to_V3(FCT_CamLaneInputData_V3::FCT_CamLaneInputData_t & Dest, const FCT_CamLaneInputData_GenAll::FCT_CamLaneInputData_t & Src)
{
  //Dest.uiVersionNumber = Src.uiVersionNumber; Is set by InitFctCamLaneInputData(m_Buf_V3, 3);
  Dest.sSigHeader = Src.sSigHeader;
  memcpy(Dest.CourseInfo, Src.CourseInfo, sizeof(Dest.CourseInfo));
  memcpy(Dest.LaneMarkerInfo, Src.LaneMarkerInfo, sizeof(Dest.LaneMarkerInfo));
}

void CConvFctCamLaneInputData::Convert_Gen_to_V4(FCT_CamLaneInputData_V4::FCT_CamLaneInputData_t & Dest, const FCT_CamLaneInputData_GenAll::FCT_CamLaneInputData_t & Src)
{
  //Dest.uiVersionNumber = Src.uiVersionNumber; Is set by InitFctCamLaneInputData(m_Buf_V4, 4);
  Dest.sSigHeader = Src.sSigHeader;
  memcpy(Dest.CourseInfo, Src.CourseInfoV4, sizeof(Dest.CourseInfo));
  memcpy(Dest.LaneMarkerInfo, Src.LaneMarkerInfoV4, sizeof(Dest.LaneMarkerInfo));
  Dest.ConstructionSite = Src.ConstructionSite;
}

void CConvFctCamLaneInputData::Convert_Gen_to_V5(FCT_CamLaneInputData_V5::FCT_CamLaneInputData_t & Dest, const FCT_CamLaneInputData_GenAll::FCT_CamLaneInputData_t & Src)
{
  //Dest.uiVersionNumber = Src.uiVersionNumber; Is set by InitFctCamLaneInputData(m_Buf_V5, 5);
  Dest.sSigHeader = Src.sSigHeader;
  memcpy(Dest.CourseInfo, Src.CourseInfoV5, sizeof(Dest.CourseInfo));
  memcpy(Dest.LaneMarkerInfo, Src.LaneMarkerInfoV5, sizeof(Dest.LaneMarkerInfo));
  Dest.ConstructionSite = Src.ConstructionSite;
}


long CConvFctCamLaneInputData::ConvertData(
    SimPortDataTypes_t eRPortType, unsigned long ulRPortSize, const IVersionInfo &requestPortVersionInfo,
    SimPortDataTypes_t ePPortType, unsigned long ulPPortSize, const IVersionInfo *pProvidePortVersionInfo,
    void *pPPortData,
    void **pOutData, unsigned long &ulOutSize)
{
  long lRet = SIM_ERR_UNADAPTABLE_DATA_PORTS;
  bool bGenBufferFilled = false;

  const unsigned __int32 uDataVer1 = ((pPPortData != NULL) && (ulPPortSize >= 4) && (ePPortType == simOPAQUE_t))?(*reinterpret_cast<unsigned __int32*>(pPPortData)):(0);
  const unsigned __int32 uDataVer2 = ((pPPortData != NULL) && (ulPPortSize >= 4) && (ePPortType == simREFERENCE_t))?(*reinterpret_cast<unsigned __int32*>(pPPortData)):(0);

  // First decide which version we are converting to
  if ((eRPortType == simOPAQUE_t) && ((ePPortType == simOPAQUE_t) || (ePPortType == simREFERENCE_t)))
  {
    // If ports equal, then always compatible
    if (ulRPortSize+1 == ulPPortSize)
    {
      lRet = SIM_ERR_USE_VALUE_FROM_PPORT;
    }
    // First decide from which version we are converting and fill the generic buffer accordingly
    else if ((ulPPortSize == SUPPORTED_SIZE[FCT_CAMLANEINPUTDATA_V5])
      && ((pProvidePortVersionInfo == NULL) || (pProvidePortVersionInfo->Equals(VERSION_NUMBERS[FCT_CAMLANEINPUTDATA_V5])) || (pProvidePortVersionInfo->Equals(&BASE_VERSION)))
      && (uDataVer1 == 5u))
    {
      // Source Port V5 of ARS4xx
      InitFctCamLaneInputData(m_Buf_GenAll, 5);
      const FCT_CamLaneInputData_V5::FCT_CamLaneInputData_t & Src = *reinterpret_cast<FCT_CamLaneInputData_V5::FCT_CamLaneInputData_t*>(pPPortData);
      Convert_V5_to_Gen(m_Buf_GenAll, Src);
      bGenBufferFilled = true;
    }
    else if ((ulPPortSize == SUPPORTED_SIZE[FCT_CAMLANEINPUTDATA_V4])
      && ((pProvidePortVersionInfo == NULL) || (pProvidePortVersionInfo->Equals(VERSION_NUMBERS[FCT_CAMLANEINPUTDATA_V4])) || (pProvidePortVersionInfo->Equals(&BASE_VERSION)))
      && ((uDataVer1 == 4u) || (uDataVer1 == 3u)))
      // The version 3 is also used in ARS430BW18 for FCT_CamLaneInputData_V4::FCT_CamLaneInputData_t
    {
      // Source Port V4 of ARS4xx
      InitFctCamLaneInputData(m_Buf_GenAll, 4);
      const FCT_CamLaneInputData_V4::FCT_CamLaneInputData_t & Src = *reinterpret_cast<FCT_CamLaneInputData_V4::FCT_CamLaneInputData_t*>(pPPortData);
      Convert_V4_to_Gen(m_Buf_GenAll, Src);
      bGenBufferFilled = true;
    }

    else if ((ulPPortSize == SUPPORTED_SIZE[FCT_CAMLANEINPUTDATA_V3])
      && ((pProvidePortVersionInfo == NULL) || (pProvidePortVersionInfo->Equals(VERSION_NUMBERS[FCT_CAMLANEINPUTDATA_V3])) || (pProvidePortVersionInfo->Equals(&BASE_VERSION)))
      && (uDataVer1 == 3u))
    {
      // Source Port V3 of ARS4xx
      InitFctCamLaneInputData(m_Buf_GenAll, 4);
      const FCT_CamLaneInputData_V3::FCT_CamLaneInputData_t & Src = *reinterpret_cast<FCT_CamLaneInputData_V3::FCT_CamLaneInputData_t*>(pPPortData);
      Convert_V3_to_Gen(m_Buf_GenAll, Src);
      bGenBufferFilled = true;
    }
    else if ((ulPPortSize == SUPPORTED_SIZE[FCT_CAMLANEINPUTDATA_V2])
      && ((pProvidePortVersionInfo == NULL) || (pProvidePortVersionInfo->Equals(VERSION_NUMBERS[FCT_CAMLANEINPUTDATA_V2])) || (pProvidePortVersionInfo->Equals(&BASE_VERSION)))
      && (uDataVer2 == 2u))
    {
      // Source Port V2 of ARS4xx
      InitFctCamLaneInputData(m_Buf_GenAll, 4);
      const FCT_CamLaneInputData_V2::FCT_CamLaneInputData_t & Src = *reinterpret_cast<FCT_CamLaneInputData_V2::FCT_CamLaneInputData_t*>(pPPortData);
      Convert_V2_to_Gen(m_Buf_GenAll, Src);
      bGenBufferFilled = true;
    }

    if (bGenBufferFilled == true)
    {
      // Second decide to which version we are converting
      // and take the generic buffer to fill the destination buffer
      if ((ulRPortSize == SUPPORTED_SIZE[FCT_CAMLANEINPUTDATA_V5]) && (requestPortVersionInfo.Equals(VERSION_NUMBERS[FCT_CAMLANEINPUTDATA_V5])))
      {
        // Destination port of V5 of ARS4xx
        InitFctCamLaneInputData(m_Buf_V5, 5);
        Convert_Gen_to_V5(m_Buf_V5, m_Buf_GenAll);
        *pOutData = &m_Buf_V5;
        ulOutSize = sizeof(m_Buf_V5);
        lRet = SIM_ERR_OK;
      }
      else if ((ulRPortSize == SUPPORTED_SIZE[FCT_CAMLANEINPUTDATA_V4]) && (requestPortVersionInfo.Equals(VERSION_NUMBERS[FCT_CAMLANEINPUTDATA_V4])))
      {
        // Destination port of V4 of ARS4xx
        InitFctCamLaneInputData(m_Buf_V4, 3);
        Convert_Gen_to_V4(m_Buf_V4, m_Buf_GenAll);
        *pOutData = &m_Buf_V4;
        ulOutSize = sizeof(m_Buf_V4);
        lRet = SIM_ERR_OK;
      }
      else if ((ulRPortSize == SUPPORTED_SIZE[FCT_CAMLANEINPUTDATA_V3]) && (requestPortVersionInfo.Equals(VERSION_NUMBERS[FCT_CAMLANEINPUTDATA_V3])))
      {
        // Destination port of V3 of ARS4xx
        InitFctCamLaneInputData(m_Buf_V3, 2);
        Convert_Gen_to_V3(m_Buf_V3, m_Buf_GenAll);
        *pOutData = &m_Buf_V3;
        ulOutSize = sizeof(m_Buf_V3);
        lRet = SIM_ERR_OK;
      }
      else if ((ulRPortSize == SUPPORTED_SIZE[FCT_CAMLANEINPUTDATA_V2]) && (requestPortVersionInfo.Equals(VERSION_NUMBERS[FCT_CAMLANEINPUTDATA_V2])))
      {
        // Destination port of V2 of ARS4xx
        InitFctCamLaneInputData(m_Buf_V2, 4);
        Convert_Gen_to_V2(m_Buf_V2, m_Buf_GenAll);
        *pOutData = &m_Buf_V2;
        ulOutSize = sizeof(m_Buf_V2);
        lRet = SIM_ERR_OK;
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
long CConvFctCamLaneInputData::GetDefaultValue(
  SimPortDataTypes_t eRPortType, unsigned long ulRPortSize, const IVersionInfo &requestPortVersionInfo,
  void **pDefaultData, unsigned long &ulDefaultSize)
{
  long lRet = SIM_ERR_USE_DEFAULT_VALUE_FROM_RPORT;
  if (eRPortType == simOPAQUE_t)
  {
    if ((ulRPortSize == SUPPORTED_SIZE[FCT_CAMLANEINPUTDATA_V3]) &&
      (VERSION_NUMBERS[FCT_CAMLANEINPUTDATA_V3]->Equals(&requestPortVersionInfo)))
    {
      FCT_CamLaneInputData_V3::FCT_CamLaneInputData_t & Dest = m_Buf_V3;
      InitFctCamLaneInputData(Dest, 3);
      *pDefaultData = &Dest;
      ulDefaultSize = sizeof(Dest);
      lRet = SIM_ERR_OK;
    }
    else if ((ulRPortSize == SUPPORTED_SIZE[FCT_CAMLANEINPUTDATA_V2]) &&
      (VERSION_NUMBERS[FCT_CAMLANEINPUTDATA_V2]->Equals(&requestPortVersionInfo)))
    {
      FCT_CamLaneInputData_V2::FCT_CamLaneInputData_t & Dest = m_Buf_V2;
      InitFctCamLaneInputData(Dest, 2);
      *pDefaultData = &Dest;
      ulDefaultSize = sizeof(Dest);
      lRet = SIM_ERR_OK;
    }
  }
  return lRet;
}

// used to check if an unversioned PPort is compatible with a certain version of RPort
bool CConvFctCamLaneInputData::IsVersionCompatibleWithType(
    SimPortDataTypes_t eRPortType, unsigned long ulRPortSize, const IVersionInfo& requestPortVersionInfo,
    SimPortDataTypes_t ePPortType, unsigned long ulPPortSize)
{
  bool bResult = false;
  // Equal ports are always compatible (at least assumed to be)
  if ((ulRPortSize == ulPPortSize) && (eRPortType == ePPortType))
  {
    bResult = true;
  }
  else if ((IsPortSupported(ulRPortSize, &requestPortVersionInfo)) && (IsPortSupported(ulPPortSize, NULL)))
  {
    bResult = true;
  }
  else
  {
    if ((eRPortType == simOPAQUE_t) && (ePPortType == simREFERENCE_t) &&
      IsPortSupported(ulRPortSize, &requestPortVersionInfo))
    {
      bResult = true;
    }
  }
  return bResult;
}

// used to check if ports are compatible between different versions
bool CConvFctCamLaneInputData::AreVersionsCompatible(
  SimPortDataTypes_t eRPortType, unsigned long ulRPortSize, const IVersionInfo& requestPortVersionInfo,
  SimPortDataTypes_t ePPortType, unsigned long ulPPortSize, const IVersionInfo& providePortVersionInfo)
{
  bool bResult = false;
  // If ports equal, then always compatible
  if ((eRPortType == ePPortType) && (ulRPortSize == ulPPortSize) && (requestPortVersionInfo.Equals(&providePortVersionInfo)))
  {
    bResult = true;
  }
  else
  {
    if ((IsPortSupported(ulRPortSize, &requestPortVersionInfo)) && (IsPortSupported(ulPPortSize, &providePortVersionInfo)))
    {
      bResult = true;
    }
  }
  return bResult;
}

//
// The one and only externally visible factory function
//
IConverter * CreateFctCamLaneInputDataConvInstance(void)
{
  return new CConvFctCamLaneInputData();
}