/*! \file **********************************************************************

  COMPANY:         Continental

  PROJECT:         Simulation

  COMPONENT:       sim_adapter fct

  MODULNAME:       sim_conv_navi_input_data.cpp

  DESCRIPTION:

  AUTHOR:          Thomas Berndt

  CREATION DATE:   05.12.2014

  VERSION:         $Revision: 1.1 $

  ---*/ /*---
  CHANGES:         $Log: sim_conv_navi_input_data.cpp  $
  CHANGES:         Revision 1.1 2017/08/10 13:15:20CEST uid34177 
  CHANGES:         Initial revision
  CHANGES:         Member added to project /ADAS/SW/Integration/06_Simulation_Components/GIA_GenericInterfaceAdapter/04_Engineering/03_Workspace/Component_Workspace/GIA_sim/sim_adapter/fct/project.pj
  CHANGES:         Revision 1.3 2016/09/21 13:28:30CEST Berndt, Thomas01 (berndtt1) 
  CHANGES:         + V8_2 for ARS430BW18
  CHANGES:         Revision 1.2 2016/02/04 06:50:58CET Berndt, Thomas01 (berndtt1) 
  CHANGES:         + V6
  CHANGES:         + V8
  CHANGES:         Revision 1.1 2014/12/09 17:53:28CET Berndt, Thomas01 (berndtt1) 
  CHANGES:         Initial revision
  CHANGES:         Member added to project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/CRT_CommonRadarToolbox/04_Engineering/03_Workspace/algo/sim_adapter/fct/project.pj

**************************************************************************** */
/* includes ---------------------------------------------------------------- */
#include "sim_adapter_cfg.h"
#include "sim_conv_navi_input_data.h"
#include "sim_versioninfo_impl.h"

/* Defines */
#ifndef AL_SIG_STATE_INIT
  #define AL_SIG_STATE_INIT (0U)
#endif

/* Common definitions/declarations */
typedef unsigned __int8 boolean;
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
namespace NaviInputData_V4                                           /* Length of t_NaviInputData = 232 */
{
  typedef unsigned char t_NavStreetType                              /* Segment's street type @min: 0 @max:255 @values: enum { NAV_STT_URBAN_BIDIRECTION=6,NAV_STT_INTERSTATE_HIGHWAY_RAMP=19,NAV_STT_RESIDENTIAL_ONEWAY=5,NAV_STT_INTERSTATE_HIGHWAY=18,NAV_STT_FEDERAL_HIGHWAY_EXIT=16,NAV_STT_INTERSTATE_HIGHWAY_EXIT=20,NAV_STT_TRAFFICCALMZONE_ONEWAY=3,NAV_STT_SIGNAL_UNFILLED=255,NAV_STT_COUNTRY_ROAD=11,NAV_STT_UNKNOWN=0,NAV_STT_FEDERAL_HIGHWAY_RAMP=15,NAV_STT_URBAN_INTERSTATE_HIGHWAY=9,NAV_STT_TRAFFICCALMZONE_BIDIRECTION=2,NAV_STT_FEDERAL_HIGHWAY=13,NAV_STT_FEDERAL_HIGHWAY_DIVIDER=14,NAV_STT_FEDERAL_HIGHWAY_RAMP_EXIT=17,NAV_STT_INTERSTATE_HIGHWAY_RAMP_EXIT=21,NAV_STT_URBAN_INTERSTATE_HIGHWAY_DIVIDER=10,NAV_STT_FERRY=22,NAV_STT_RAILTRACK=1,NAV_STT_RESIDENTIAL_BIDIRECTION=4,NAV_STT_URBAN_ONEWAY=7,NAV_STT_COUNTRY_ROAD_DIVIDER=12,NAV_STT_URBAN_DIVIDER=8,NAV_STT_RACETRACK=23,} */ /* [Satisfies_rte sws 1188] */;
  typedef unsigned char t_NavRoutingType                             /* Info if navi routing not active/planned @min: 0 @max:255 @values: enum { NAV_ROUTING_ACTIVE_PLANNED=2,NAV_ROUTING_NOT_ACTIVE=0,NAV_ROUTING_ACTIVE_ESTIMATED=1,NAV_ROUNTING_SNA=255,} */ /* [Satisfies_rte sws 1188] */;

  typedef struct                                                     /* [Satisfies_rte sws 1191] */
  {
    unsigned char u_QuanLanes;
    unsigned char u_ProbEgoTakesBranch;
    t_NavStreetType TypStreet;
    float f_Length;
    float f_Curvature;
    float f_AnglePrevSeg;
    t_NavStreetType TypStreetBranch;
    float f_AnglePrevBranch;
  } t_NavSegment;                                                    /* Navigation segments */

  typedef t_NavSegment Segments_array_t[8];                          /* Navigation segments */ /* [Satisfies_rte sws 1189] */

  typedef struct                                                     /* [Satisfies_rte sws 1191] */
  {
    unsigned long uiVersionNumber;
    SignalHeader_t sSigHeader;
    Segments_array_t Segments;
    boolean b_MppNew;
    unsigned char u_NumUsedSegments;
    unsigned char u_QualityNavData;
    unsigned short u_DistNextRoundabout;
    unsigned short u_DistNextTunnelStart;
    unsigned short u_DistNextTunnelEnd;
    unsigned short u_DistNextTollbooth;
    unsigned short u_DistNextExitLaneStart;
    unsigned short u_DistNextExitLaneEnd;
    unsigned short u_DistNextBridge;
    t_NavRoutingType NavRoutingActive;
    float f_AngleClothStart;
  } t_NaviInputData;                                                 /* FCT Navigation input data @vaddr:0x20286000 @vaddr_defs: FCT_MEAS_ID_NAVI_INPUT_VADDR @cycleid:FCT_ENV @vname:NaviInputData */

} // end of namespace NaviInputData_V4


namespace NaviInputData_V5                                           /* Length of t_NaviInputData = 264 */
{
  typedef unsigned char t_NavStreetType                              /* Segment's street type @min: 0 @max:255 @values: enum { NAV_STT_URBAN_BIDIRECTION=6,NAV_STT_INTERSTATE_HIGHWAY_RAMP=19,NAV_STT_RESIDENTIAL_ONEWAY=5,NAV_STT_INTERSTATE_HIGHWAY=18,NAV_STT_FEDERAL_HIGHWAY_EXIT=16,NAV_STT_INTERSTATE_HIGHWAY_EXIT=20,NAV_STT_TRAFFICCALMZONE_ONEWAY=3,NAV_STT_SIGNAL_UNFILLED=255,NAV_STT_COUNTRY_ROAD=11,NAV_STT_UNKNOWN=0,NAV_STT_FEDERAL_HIGHWAY_RAMP=15,NAV_STT_URBAN_INTERSTATE_HIGHWAY=9,NAV_STT_TRAFFICCALMZONE_BIDIRECTION=2,NAV_STT_FEDERAL_HIGHWAY=13,NAV_STT_FEDERAL_HIGHWAY_DIVIDER=14,NAV_STT_FEDERAL_HIGHWAY_RAMP_EXIT=17,NAV_STT_INTERSTATE_HIGHWAY_RAMP_EXIT=21,NAV_STT_URBAN_INTERSTATE_HIGHWAY_DIVIDER=10,NAV_STT_FERRY=22,NAV_STT_RAILTRACK=1,NAV_STT_RESIDENTIAL_BIDIRECTION=4,NAV_STT_URBAN_ONEWAY=7,NAV_STT_COUNTRY_ROAD_DIVIDER=12,NAV_STT_URBAN_DIVIDER=8,NAV_STT_RACETRACK=23,} */ /* [Satisfies_rte sws 1188] */;
  typedef unsigned char t_NavRoutingType                             /* Info if navi routing not active/planned @min: 0 @max:255 @values: enum { NAV_ROUTING_ACTIVE_PLANNED=2,NAV_ROUTING_NOT_ACTIVE=0,NAV_ROUTING_ACTIVE_ESTIMATED=1,NAV_ROUNTING_SNA=255,} */ /* [Satisfies_rte sws 1188] */;

  typedef struct                                                     /* [Satisfies_rte sws 1191] */
  {
    unsigned short u_SegmentID;
    unsigned char u_QuanLanes;
    unsigned char u_ProbEgoTakesBranch;
    t_NavStreetType TypStreet;
    float f_Length;
    float f_Curvature;
    float f_AnglePrevSeg;
    t_NavStreetType TypStreetBranch;
    float f_AnglePrevBranch;
  } t_NavSegment;                                                    /* Navigation segments */

  typedef t_NavSegment Segments_array_t[8];                          /* Navigation segments */ /* [Satisfies_rte sws 1189] */

  typedef struct                                                     /* [Satisfies_rte sws 1191] */
  {
    unsigned long uiVersionNumber;
    SignalHeader_t sSigHeader;
    Segments_array_t Segments;
    boolean b_MppNew;
    unsigned char u_NumUsedSegments;
    unsigned char u_QualityNavData;
    unsigned short u_DistNextRoundabout;
    unsigned short u_DistNextTunnelStart;
    unsigned short u_DistNextTunnelEnd;
    unsigned short u_DistNextTollbooth;
    unsigned short u_DistNextExitLaneStart;
    unsigned short u_DistNextExitLaneEnd;
    unsigned short u_DistNextBridge;
    t_NavRoutingType NavRoutingActive;
    float f_AngleClothStart;
  } t_NaviInputData;                                                 /* FCT Navigation input data @vaddr:0x20286000 @vaddr_defs: FCT_MEAS_ID_NAVI_INPUT_VADDR @cycleid:FCT_ENV @vname:NaviInputData */

} // end of namespace NaviInputData_V5


namespace NaviInputData_V6                                           /* Length of t_NaviInputData = 268 */
{
  typedef unsigned char t_NavRoutingType;                            /* Info if navi routing not active/planned @min: 0 @max:255 @values: enum { NAV_ROUTING_ACTIVE_PLANNED=2,NAV_ROUTING_NOT_ACTIVE=0,NAV_ROUTING_ACTIVE_ESTIMATED=1,NAV_ROUNTING_SNA=255,} */ /* [Satisfies_rte sws 1188] */
  typedef unsigned char eTrafficOrientation_t;                       /* left-hand / right-hand traffic @min: 0 @max:2 @values: enum { GDB_TRAFFICORIENTATION_RIGHT_HAND=1,GDB_TRAFFICORIENTATION_LEFT_HAND=2,TRAFFICORIENTATION_UNKNOWN=0,} */ /* [Satisfies_rte sws 1180], [Satisfies_rte sws 1265] */

  typedef struct                                                     /* [Satisfies_rte sws 1191] */
  {
    unsigned long uiVersionNumber;
    SignalHeader_t sSigHeader;
    NaviInputData_V5::Segments_array_t Segments;
    boolean b_MppNew;
    unsigned char u_NumUsedSegments;
    unsigned char u_QualityNavData;
    unsigned short u_DistNextRoundabout;
    unsigned short u_DistNextTunnelStart;
    unsigned short u_DistNextTunnelEnd;
    unsigned short u_DistNextTollbooth;
    unsigned short u_DistNextExitLaneStart;
    unsigned short u_DistNextExitLaneEnd;
    unsigned short u_DistNextBridge;
    t_NavRoutingType NavRoutingActive;
    float f_AngleClothStart;
    eTrafficOrientation_t e_NaviTrafficOrientation;                  /* Traffic Orientation from Navi */ /* NEW */
  } t_NaviInputData;                                                 /* FCT Navigation input data @vaddr:0x20286000 @vaddr_defs: FCT_MEAS_ID_NAVI_INPUT_VADDR @cycleid:FCT_ENV @vname:NaviInputData */

} // end of namespace NaviInputData_V6


namespace NaviInputData_V8                                           /* Length of t_NaviInputData = 300 */
{
  typedef unsigned char t_NavStreetType                              /* Segment's street type @min: 0 @max:255 @values: enum { NAV_STT_URBAN_BIDIRECTION=6,NAV_STT_INTERSTATE_HIGHWAY_RAMP=19,NAV_STT_RESIDENTIAL_ONEWAY=5,NAV_STT_INTERSTATE_HIGHWAY=18,NAV_STT_FEDERAL_HIGHWAY_EXIT=16,NAV_STT_INTERSTATE_HIGHWAY_EXIT=20,NAV_STT_TRAFFICCALMZONE_ONEWAY=3,NAV_STT_SIGNAL_UNFILLED=255,NAV_STT_COUNTRY_ROAD=11,NAV_STT_UNKNOWN=0,NAV_STT_FEDERAL_HIGHWAY_RAMP=15,NAV_STT_URBAN_INTERSTATE_HIGHWAY=9,NAV_STT_TRAFFICCALMZONE_BIDIRECTION=2,NAV_STT_FEDERAL_HIGHWAY=13,NAV_STT_FEDERAL_HIGHWAY_DIVIDER=14,NAV_STT_FEDERAL_HIGHWAY_RAMP_EXIT=17,NAV_STT_INTERSTATE_HIGHWAY_RAMP_EXIT=21,NAV_STT_URBAN_INTERSTATE_HIGHWAY_DIVIDER=10,NAV_STT_FERRY=22,NAV_STT_RAILTRACK=1,NAV_STT_RESIDENTIAL_BIDIRECTION=4,NAV_STT_URBAN_ONEWAY=7,NAV_STT_COUNTRY_ROAD_DIVIDER=12,NAV_STT_URBAN_DIVIDER=8,NAV_STT_RACETRACK=23,} */ /* [Satisfies_rte sws 1188] */;
  typedef unsigned char t_NavRoutingType                             /* Info if navi routing not active/planned @min: 0 @max:255 @values: enum { NAV_ROUTING_ACTIVE_PLANNED=2,NAV_ROUTING_NOT_ACTIVE=0,NAV_ROUTING_ACTIVE_ESTIMATED=1,NAV_ROUNTING_SNA=255,} */ /* [Satisfies_rte sws 1188] */;
  typedef unsigned char eTrafficOrientation_t;                       /* left-hand / right-hand traffic @min: 0 @max:2 @values: enum { GDB_TRAFFICORIENTATION_RIGHT_HAND=1,GDB_TRAFFICORIENTATION_LEFT_HAND=2,TRAFFICORIENTATION_UNKNOWN=0,} */ /* [Satisfies_rte sws 1180], [Satisfies_rte sws 1265] */

  typedef struct                                                     /* [Satisfies_rte sws 1191] */
  {
    unsigned short u_SegmentID;
    unsigned char u_QuanLanes;
    unsigned char u_ProbEgoTakesBranch;
    t_NavStreetType TypStreet;
    float f_Length;
    float f_Curvature;
    float f_CurvatureChange;                                         /* Linear curvature change over segment length @min:-2 @max:2 */ /* NEW */
    float f_AnglePrevSeg;
    t_NavStreetType TypStreetBranch;
    float f_AnglePrevBranch;
  } t_NavSegment;                                                    /* Navigation segments */

  typedef t_NavSegment Segments_array_t[8];                          /* Navigation segments */ /* [Satisfies_rte sws 1189] */

  typedef struct                                                     /* [Satisfies_rte sws 1191] */
  {
    unsigned long uiVersionNumber;
    SignalHeader_t sSigHeader;
    Segments_array_t Segments;
    boolean b_MppNew;
    boolean b_NoPassingSign;                                         /* Info if NoPassingSign is valid for current ego-position */ /* NEW */
    boolean b_HangNaviTree;                                          /* Info if Navi tree is hanging */ /* NEW */
    unsigned char u_NumUsedSegments;
    unsigned char u_QualityNavData;
    unsigned char u_PosLongitudinalError;                            /* Longitudinal ego-position error due to matching on ADAS-map @min:0 @max:7 */ /* NEW */
    unsigned char u_NumADASQualSegments;                             /* Number of segments with ADAS-quality from ego-position till first segment with no ADAS-quality @min:0 @max:8 */ /* NEW */
    unsigned short u_DistNextRoundabout;
    unsigned short u_DistNextTunnelStart;
    unsigned short u_DistNextTunnelEnd;
    unsigned short u_DistNextTollbooth;
    unsigned short u_DistNextExitLaneStart;
    unsigned short u_DistNextExitLaneEnd;
    unsigned short u_DistNextBridge;
    t_NavRoutingType NavRoutingActive;
    eTrafficOrientation_t e_NaviTrafficOrientation;                  /* Traffic Orientation from Navi */ /* NEW */
    float f_AngleClothStart;
  } t_NaviInputData;                                                 /* FCT Navigation input data @vaddr:0x20286000 @vaddr_defs: FCT_MEAS_ID_NAVI_INPUT_VADDR @cycleid:FCT_ENV @vname:NaviInputData */

} // end of namespace NaviInputData_V8


namespace NaviInputData_V8_2                                         /* Length of t_NaviInputData = 300 */
{
  typedef unsigned char t_NavStreetType                              /* Segment's street type @min: 0 @max:255 @values: enum { NAV_STT_URBAN_BIDIRECTION=6,NAV_STT_INTERSTATE_HIGHWAY_RAMP=19,NAV_STT_RESIDENTIAL_ONEWAY=5,NAV_STT_INTERSTATE_HIGHWAY=18,NAV_STT_FEDERAL_HIGHWAY_EXIT=16,NAV_STT_INTERSTATE_HIGHWAY_EXIT=20,NAV_STT_TRAFFICCALMZONE_ONEWAY=3,NAV_STT_SIGNAL_UNFILLED=255,NAV_STT_COUNTRY_ROAD=11,NAV_STT_UNKNOWN=0,NAV_STT_FEDERAL_HIGHWAY_RAMP=15,NAV_STT_URBAN_INTERSTATE_HIGHWAY=9,NAV_STT_TRAFFICCALMZONE_BIDIRECTION=2,NAV_STT_FEDERAL_HIGHWAY=13,NAV_STT_FEDERAL_HIGHWAY_DIVIDER=14,NAV_STT_FEDERAL_HIGHWAY_RAMP_EXIT=17,NAV_STT_INTERSTATE_HIGHWAY_RAMP_EXIT=21,NAV_STT_URBAN_INTERSTATE_HIGHWAY_DIVIDER=10,NAV_STT_FERRY=22,NAV_STT_RAILTRACK=1,NAV_STT_RESIDENTIAL_BIDIRECTION=4,NAV_STT_URBAN_ONEWAY=7,NAV_STT_COUNTRY_ROAD_DIVIDER=12,NAV_STT_URBAN_DIVIDER=8,NAV_STT_RACETRACK=23,} */ /* [Satisfies_rte sws 1188] */;
  typedef unsigned char t_NavRoutingType                             /* Info if navi routing not active/planned @min: 0 @max:255 @values: enum { NAV_ROUTING_ACTIVE_PLANNED=2,NAV_ROUTING_NOT_ACTIVE=0,NAV_ROUTING_ACTIVE_ESTIMATED=1,NAV_ROUNTING_SNA=255,} */	/* [Satisfies_rte sws 1188] */;

typedef struct 			                                                 /* [Satisfies_rte sws 1191] */
{
	unsigned short u_SegmentID;
 	unsigned char u_QuanLanes;
 	unsigned char u_ProbEgoTakesBranch;
 	t_NavStreetType TypStreet;
 	float f_Length;
 	float f_Curvature;
 	float f_AnglePrevSeg;
 	t_NavStreetType TypStreetBranch;
 	float f_AnglePrevBranch;
 } t_NavSegment;			                                               /* Navigation segments */

  typedef t_NavSegment Segments_array_t[8];                          /* Navigation segments */ /* [Satisfies_rte sws 1189] */

typedef struct 			/* [Satisfies_rte sws 1191] */
{
	unsigned long uiVersionNumber;
 	SignalHeader_t sSigHeader;
 	Segments_array_t Segments;
 	boolean b_MppNew;
 	unsigned char u_NumUsedSegments;
 	unsigned char u_QualityNavData;
 	unsigned short u_DistNextRoundabout;
 	unsigned short u_DistNextTunnelStart;
 	unsigned short u_DistNextTunnelEnd;
 	unsigned short u_DistNextTollbooth;
 	unsigned short u_DistNextExitLaneStart;
 	unsigned short u_DistNextExitLaneEnd;
 	unsigned short u_DistNextBridge;
 	t_NavRoutingType NavRoutingActive;
 	float f_AngleClothStart;
 } t_NaviInputData;			                                             /* FCT Navigation input data @vaddr:0x20286000 @vaddr_defs: FCT_MEAS_ID_NAVI_INPUT_VADDR @cycleid:FCT_ENV @vname:NaviInputData */

} // end of namespace NaviInputData_V8_2


class CConvNaviInputData : public CSimConverterBase
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

  NaviInputData_V4::t_NaviInputData m_BufV4;
  NaviInputData_V5::t_NaviInputData m_BufV5;
  NaviInputData_V6::t_NaviInputData m_BufV6;
  NaviInputData_V8::t_NaviInputData m_BufV8;
  NaviInputData_V8_2::t_NaviInputData m_BufV8_2;

  static void InitV4(NaviInputData_V4::t_NaviInputData &Params);
  static void InitV5(NaviInputData_V5::t_NaviInputData &Params);
  static void InitV6(NaviInputData_V6::t_NaviInputData &Params);
  static void InitV8(NaviInputData_V8::t_NaviInputData &Params);
  static void InitV8_2(NaviInputData_V8_2::t_NaviInputData &Params);

public:

  static const char *GetConverterTypeName()
  {
    return "t_NaviInputData";
  }

  CConvNaviInputData(void);
  virtual ~CConvNaviInputData(void);

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
  enum Navi_Input_Data
  {
    NAVI_INPUT_DATA_V4,
    NAVI_INPUT_DATA_V5,
    NAVI_INPUT_DATA_V6,
    NAVI_INPUT_DATA_V8,
    NAVI_INPUT_DATA_V8_2,
    NAVI_INPUT_DATA_VERSION_COUNT
  };

  static CVersionInfoImpl BASE_VERSION;
  static CVersionInfoImpl VERSION4;
  static CVersionInfoImpl VERSION5;
  static CVersionInfoImpl VERSION6;
  static CVersionInfoImpl VERSION8;
  static CVersionInfoImpl VERSION8_2;
  static const CVersionInfoImpl * const NAVI_INPUT_DATA_VERSIONS[NAVI_INPUT_DATA_VERSION_COUNT];

  static const unsigned long SUPPORTED_SIZE[NAVI_INPUT_DATA_VERSION_COUNT];

  bool IsPortSupported(unsigned long ulPortSize, const IVersionInfo *pPortVersion) const
  {
    for (int nI = 0; nI < NAVI_INPUT_DATA_VERSION_COUNT; nI++)
    {
      if ((pPortVersion == NULL) || pPortVersion->Equals(NAVI_INPUT_DATA_VERSIONS[nI]))
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

CVersionInfoImpl CConvNaviInputData::BASE_VERSION(0, 0, 0);
CVersionInfoImpl CConvNaviInputData::VERSION4    (0, 0, 4);
CVersionInfoImpl CConvNaviInputData::VERSION5    (0, 0, 5);
CVersionInfoImpl CConvNaviInputData::VERSION6    (0, 0, 6);
CVersionInfoImpl CConvNaviInputData::VERSION8    (0, 0, 8);
CVersionInfoImpl CConvNaviInputData::VERSION8_2  (0, 0, 8);

const CVersionInfoImpl * const CConvNaviInputData::NAVI_INPUT_DATA_VERSIONS[CConvNaviInputData::NAVI_INPUT_DATA_VERSION_COUNT] =
{
  &VERSION4,
  &VERSION5,
  &VERSION6,
  &VERSION8,
  &VERSION8_2
};

const unsigned long CConvNaviInputData::SUPPORTED_SIZE[CConvNaviInputData::NAVI_INPUT_DATA_VERSION_COUNT] =
{
  sizeof(NaviInputData_V4::t_NaviInputData),
  sizeof(NaviInputData_V5::t_NaviInputData),
  sizeof(NaviInputData_V6::t_NaviInputData),
  sizeof(NaviInputData_V8::t_NaviInputData),
  sizeof(NaviInputData_V8_2::t_NaviInputData)
};

__inline void v_Convert_v4_to_v5 (NaviInputData_V5::t_NaviInputData * const pDest,
  const NaviInputData_V4::t_NaviInputData * const pSrc)
{
  pDest->uiVersionNumber = 5u;
  pDest->sSigHeader = pSrc->sSigHeader;

  for (int nI=0; nI < 8; nI++)
  {
    pDest->Segments[nI].u_SegmentID          = 0u;
    pDest->Segments[nI].u_QuanLanes          = pSrc->Segments[nI].u_QuanLanes;
    pDest->Segments[nI].u_ProbEgoTakesBranch = pSrc->Segments[nI].u_ProbEgoTakesBranch;
    pDest->Segments[nI].TypStreet            = pSrc->Segments[nI].TypStreet;
    pDest->Segments[nI].f_Length             = pSrc->Segments[nI].f_Length;
    pDest->Segments[nI].f_Curvature          = pSrc->Segments[nI].f_Curvature;
    pDest->Segments[nI].f_AnglePrevSeg       = pSrc->Segments[nI].f_AnglePrevSeg;
    pDest->Segments[nI].TypStreetBranch      = pSrc->Segments[nI].TypStreetBranch;
    pDest->Segments[nI].f_AnglePrevBranch    = pSrc->Segments[nI].f_AnglePrevBranch;
  }

  pDest->b_MppNew                            = pSrc->b_MppNew;
  pDest->u_NumUsedSegments                   = pSrc->u_NumUsedSegments;
  pDest->u_QualityNavData                    = pSrc->u_QualityNavData;
  pDest->u_DistNextRoundabout                = pSrc->u_DistNextRoundabout;
  pDest->u_DistNextTunnelStart               = pSrc->u_DistNextTunnelStart;
  pDest->u_DistNextTunnelEnd                 = pSrc->u_DistNextTunnelEnd;
  pDest->u_DistNextTollbooth                 = pSrc->u_DistNextTollbooth;
  pDest->u_DistNextExitLaneStart             = pSrc->u_DistNextExitLaneStart;
  pDest->u_DistNextExitLaneEnd               = pSrc->u_DistNextExitLaneEnd;
  pDest->u_DistNextBridge                    = pSrc->u_DistNextBridge;
  pDest->NavRoutingActive                    = pSrc->NavRoutingActive;
  pDest->f_AngleClothStart                   = pSrc->f_AngleClothStart;
}

__inline void v_Convert_v5_to_v6 (NaviInputData_V6::t_NaviInputData * const pDest,
  const NaviInputData_V5::t_NaviInputData * const pSrc)
{
  pDest->uiVersionNumber = 6u;
  pDest->sSigHeader = pSrc->sSigHeader;

  for (int nI=0; nI < 8; nI++)
  {
    pDest->Segments[nI].u_SegmentID          = pSrc->Segments[nI].u_SegmentID;
    pDest->Segments[nI].u_QuanLanes          = pSrc->Segments[nI].u_QuanLanes;
    pDest->Segments[nI].u_ProbEgoTakesBranch = pSrc->Segments[nI].u_ProbEgoTakesBranch;
    pDest->Segments[nI].TypStreet            = pSrc->Segments[nI].TypStreet;
    pDest->Segments[nI].f_Length             = pSrc->Segments[nI].f_Length;
    pDest->Segments[nI].f_Curvature          = pSrc->Segments[nI].f_Curvature;
    pDest->Segments[nI].f_AnglePrevSeg       = pSrc->Segments[nI].f_AnglePrevSeg;
    pDest->Segments[nI].TypStreetBranch      = pSrc->Segments[nI].TypStreetBranch;
    pDest->Segments[nI].f_AnglePrevBranch    = pSrc->Segments[nI].f_AnglePrevBranch;
  }

  pDest->b_MppNew                            = pSrc->b_MppNew;
  pDest->u_NumUsedSegments                   = pSrc->u_NumUsedSegments;
  pDest->u_QualityNavData                    = pSrc->u_QualityNavData;
  pDest->u_DistNextRoundabout                = pSrc->u_DistNextRoundabout;
  pDest->u_DistNextTunnelStart               = pSrc->u_DistNextTunnelStart;
  pDest->u_DistNextTunnelEnd                 = pSrc->u_DistNextTunnelEnd;
  pDest->u_DistNextTollbooth                 = pSrc->u_DistNextTollbooth;
  pDest->u_DistNextExitLaneStart             = pSrc->u_DistNextExitLaneStart;
  pDest->u_DistNextExitLaneEnd               = pSrc->u_DistNextExitLaneEnd;
  pDest->u_DistNextBridge                    = pSrc->u_DistNextBridge;
  pDest->NavRoutingActive                    = pSrc->NavRoutingActive;
  pDest->f_AngleClothStart                   = pSrc->f_AngleClothStart;
  pDest->e_NaviTrafficOrientation            = 0;
}

__inline void v_Convert_v6_to_v8 (NaviInputData_V8::t_NaviInputData * const pDest,
  const NaviInputData_V6::t_NaviInputData * const pSrc)
{
  pDest->uiVersionNumber = 8u;
  pDest->sSigHeader = pSrc->sSigHeader;

  for (int nI=0; nI < 8; nI++)
  {
    pDest->Segments[nI].u_SegmentID          = pSrc->Segments[nI].u_SegmentID;
    pDest->Segments[nI].u_QuanLanes          = pSrc->Segments[nI].u_QuanLanes;
    pDest->Segments[nI].u_ProbEgoTakesBranch = pSrc->Segments[nI].u_ProbEgoTakesBranch;
    pDest->Segments[nI].TypStreet            = pSrc->Segments[nI].TypStreet;
    pDest->Segments[nI].f_Length             = pSrc->Segments[nI].f_Length;
    pDest->Segments[nI].f_Curvature          = pSrc->Segments[nI].f_Curvature;
    pDest->Segments[nI].f_CurvatureChange    = 0.f;
    pDest->Segments[nI].f_AnglePrevSeg       = pSrc->Segments[nI].f_AnglePrevSeg;
    pDest->Segments[nI].TypStreetBranch      = pSrc->Segments[nI].TypStreetBranch;
    pDest->Segments[nI].f_AnglePrevBranch    = pSrc->Segments[nI].f_AnglePrevBranch;
  }

  pDest->b_MppNew                            = pSrc->b_MppNew;
  pDest->b_NoPassingSign                     = 0;
  pDest->b_HangNaviTree                      = 0;
  pDest->u_NumUsedSegments                   = pSrc->u_NumUsedSegments;
  pDest->u_QualityNavData                    = pSrc->u_QualityNavData;
  pDest->u_PosLongitudinalError              = 0;
  pDest->u_NumADASQualSegments               = 0;
  pDest->u_DistNextRoundabout                = pSrc->u_DistNextRoundabout;
  pDest->u_DistNextTunnelStart               = pSrc->u_DistNextTunnelStart;
  pDest->u_DistNextTunnelEnd                 = pSrc->u_DistNextTunnelEnd;
  pDest->u_DistNextTollbooth                 = pSrc->u_DistNextTollbooth;
  pDest->u_DistNextExitLaneStart             = pSrc->u_DistNextExitLaneStart;
  pDest->u_DistNextExitLaneEnd               = pSrc->u_DistNextExitLaneEnd;
  pDest->u_DistNextBridge                    = pSrc->u_DistNextBridge;
  pDest->NavRoutingActive                    = pSrc->NavRoutingActive;
  pDest->f_AngleClothStart                   = pSrc->f_AngleClothStart;
  pDest->e_NaviTrafficOrientation            = pSrc->e_NaviTrafficOrientation;
}

__inline void v_Convert_v8_to_v8_2 (NaviInputData_V8_2::t_NaviInputData * const pDest,
  const NaviInputData_V8::t_NaviInputData * const pSrc)
{
  pDest->uiVersionNumber = 8u;
  pDest->sSigHeader = pSrc->sSigHeader;

  for (int nI=0; nI < 8; nI++)
  {
    pDest->Segments[nI].u_SegmentID          = pSrc->Segments[nI].u_SegmentID;
    pDest->Segments[nI].u_QuanLanes          = pSrc->Segments[nI].u_QuanLanes;
    pDest->Segments[nI].u_ProbEgoTakesBranch = pSrc->Segments[nI].u_ProbEgoTakesBranch;
    pDest->Segments[nI].TypStreet            = pSrc->Segments[nI].TypStreet;
    pDest->Segments[nI].f_Length             = pSrc->Segments[nI].f_Length;
    pDest->Segments[nI].f_Curvature          = pSrc->Segments[nI].f_Curvature;
    pDest->Segments[nI].f_AnglePrevSeg       = pSrc->Segments[nI].f_AnglePrevSeg;
    pDest->Segments[nI].TypStreetBranch      = pSrc->Segments[nI].TypStreetBranch;
    pDest->Segments[nI].f_AnglePrevBranch    = pSrc->Segments[nI].f_AnglePrevBranch;
  }

  pDest->b_MppNew                            = pSrc->b_MppNew;
  pDest->u_NumUsedSegments                   = pSrc->u_NumUsedSegments;
  pDest->u_QualityNavData                    = pSrc->u_QualityNavData;
  pDest->u_DistNextRoundabout                = pSrc->u_DistNextRoundabout;
  pDest->u_DistNextTunnelStart               = pSrc->u_DistNextTunnelStart;
  pDest->u_DistNextTunnelEnd                 = pSrc->u_DistNextTunnelEnd;
  pDest->u_DistNextTollbooth                 = pSrc->u_DistNextTollbooth;
  pDest->u_DistNextExitLaneStart             = pSrc->u_DistNextExitLaneStart;
  pDest->u_DistNextExitLaneEnd               = pSrc->u_DistNextExitLaneEnd;
  pDest->u_DistNextBridge                    = pSrc->u_DistNextBridge;
  pDest->NavRoutingActive                    = pSrc->NavRoutingActive;
  pDest->f_AngleClothStart                   = pSrc->f_AngleClothStart;
}

__inline void v_Convert_v8_2_to_v8 (NaviInputData_V8::t_NaviInputData * const pDest,
  const NaviInputData_V8_2::t_NaviInputData * const pSrc)
{
  pDest->uiVersionNumber = 8u;
  pDest->sSigHeader = pSrc->sSigHeader;

  for (int nI=0; nI < 8; nI++)
  {
    pDest->Segments[nI].u_SegmentID          = pSrc->Segments[nI].u_SegmentID;
    pDest->Segments[nI].u_QuanLanes          = pSrc->Segments[nI].u_QuanLanes;
    pDest->Segments[nI].u_ProbEgoTakesBranch = pSrc->Segments[nI].u_ProbEgoTakesBranch;
    pDest->Segments[nI].TypStreet            = pSrc->Segments[nI].TypStreet;
    pDest->Segments[nI].f_Length             = pSrc->Segments[nI].f_Length;
    pDest->Segments[nI].f_Curvature          = pSrc->Segments[nI].f_Curvature;
    pDest->Segments[nI].f_AnglePrevSeg       = pSrc->Segments[nI].f_AnglePrevSeg;
    pDest->Segments[nI].TypStreetBranch      = pSrc->Segments[nI].TypStreetBranch;
    pDest->Segments[nI].f_AnglePrevBranch    = pSrc->Segments[nI].f_AnglePrevBranch;
  }

  pDest->b_MppNew                            = pSrc->b_MppNew;
  pDest->b_NoPassingSign                     = 0;
  pDest->b_HangNaviTree                      = 0;
  pDest->u_NumUsedSegments                   = pSrc->u_NumUsedSegments;
  pDest->u_QualityNavData                    = pSrc->u_QualityNavData;
  pDest->u_PosLongitudinalError              = 0;
  pDest->u_NumADASQualSegments               = 0;
  pDest->u_DistNextRoundabout                = pSrc->u_DistNextRoundabout;
  pDest->u_DistNextTunnelStart               = pSrc->u_DistNextTunnelStart;
  pDest->u_DistNextTunnelEnd                 = pSrc->u_DistNextTunnelEnd;
  pDest->u_DistNextTollbooth                 = pSrc->u_DistNextTollbooth;
  pDest->u_DistNextExitLaneStart             = pSrc->u_DistNextExitLaneStart;
  pDest->u_DistNextExitLaneEnd               = pSrc->u_DistNextExitLaneEnd;
  pDest->u_DistNextBridge                    = pSrc->u_DistNextBridge;
  pDest->NavRoutingActive                    = pSrc->NavRoutingActive;
  pDest->e_NaviTrafficOrientation            = 0;
  pDest->f_AngleClothStart                   = pSrc->f_AngleClothStart;
}

__inline void v_Convert_v8_to_v6 (NaviInputData_V6::t_NaviInputData * const pDest,
  const NaviInputData_V8::t_NaviInputData * const pSrc)
{
  pDest->uiVersionNumber = 6u;
  pDest->sSigHeader = pSrc->sSigHeader;

  for (int nI=0; nI < 8; nI++)
  {
    pDest->Segments[nI].u_SegmentID          = pSrc->Segments[nI].u_SegmentID;
    pDest->Segments[nI].u_QuanLanes          = pSrc->Segments[nI].u_QuanLanes;
    pDest->Segments[nI].u_ProbEgoTakesBranch = pSrc->Segments[nI].u_ProbEgoTakesBranch;
    pDest->Segments[nI].TypStreet            = pSrc->Segments[nI].TypStreet;
    pDest->Segments[nI].f_Length             = pSrc->Segments[nI].f_Length;
    pDest->Segments[nI].f_Curvature          = pSrc->Segments[nI].f_Curvature;
    pDest->Segments[nI].f_AnglePrevSeg       = pSrc->Segments[nI].f_AnglePrevSeg;
    pDest->Segments[nI].TypStreetBranch      = pSrc->Segments[nI].TypStreetBranch;
    pDest->Segments[nI].f_AnglePrevBranch    = pSrc->Segments[nI].f_AnglePrevBranch;
  }

  pDest->b_MppNew                            = pSrc->b_MppNew;
  pDest->u_NumUsedSegments                   = pSrc->u_NumUsedSegments;
  pDest->u_QualityNavData                    = pSrc->u_QualityNavData;
  pDest->u_DistNextRoundabout                = pSrc->u_DistNextRoundabout;
  pDest->u_DistNextTunnelStart               = pSrc->u_DistNextTunnelStart;
  pDest->u_DistNextTunnelEnd                 = pSrc->u_DistNextTunnelEnd;
  pDest->u_DistNextTollbooth                 = pSrc->u_DistNextTollbooth;
  pDest->u_DistNextExitLaneStart             = pSrc->u_DistNextExitLaneStart;
  pDest->u_DistNextExitLaneEnd               = pSrc->u_DistNextExitLaneEnd;
  pDest->u_DistNextBridge                    = pSrc->u_DistNextBridge;
  pDest->NavRoutingActive                    = pSrc->NavRoutingActive;
  pDest->f_AngleClothStart                   = pSrc->f_AngleClothStart;
  pDest->e_NaviTrafficOrientation            = pSrc->e_NaviTrafficOrientation;
}

__inline void v_Convert_v6_to_v5 (NaviInputData_V5::t_NaviInputData * const pDest,
  const NaviInputData_V6::t_NaviInputData * const pSrc)
{
  pDest->uiVersionNumber = 5u;
  pDest->sSigHeader = pSrc->sSigHeader;

  for (int nI=0; nI < 8; nI++)
  {
    pDest->Segments[nI].u_SegmentID          = pSrc->Segments[nI].u_SegmentID;
    pDest->Segments[nI].u_QuanLanes          = pSrc->Segments[nI].u_QuanLanes;
    pDest->Segments[nI].u_ProbEgoTakesBranch = pSrc->Segments[nI].u_ProbEgoTakesBranch;
    pDest->Segments[nI].TypStreet            = pSrc->Segments[nI].TypStreet;
    pDest->Segments[nI].f_Length             = pSrc->Segments[nI].f_Length;
    pDest->Segments[nI].f_Curvature          = pSrc->Segments[nI].f_Curvature;
    pDest->Segments[nI].f_AnglePrevSeg       = pSrc->Segments[nI].f_AnglePrevSeg;
    pDest->Segments[nI].TypStreetBranch      = pSrc->Segments[nI].TypStreetBranch;
    pDest->Segments[nI].f_AnglePrevBranch    = pSrc->Segments[nI].f_AnglePrevBranch;
  }

  pDest->b_MppNew                            = pSrc->b_MppNew;
  pDest->u_NumUsedSegments                   = pSrc->u_NumUsedSegments;
  pDest->u_QualityNavData                    = pSrc->u_QualityNavData;
  pDest->u_DistNextRoundabout                = pSrc->u_DistNextRoundabout;
  pDest->u_DistNextTunnelStart               = pSrc->u_DistNextTunnelStart;
  pDest->u_DistNextTunnelEnd                 = pSrc->u_DistNextTunnelEnd;
  pDest->u_DistNextTollbooth                 = pSrc->u_DistNextTollbooth;
  pDest->u_DistNextExitLaneStart             = pSrc->u_DistNextExitLaneStart;
  pDest->u_DistNextExitLaneEnd               = pSrc->u_DistNextExitLaneEnd;
  pDest->u_DistNextBridge                    = pSrc->u_DistNextBridge;
  pDest->NavRoutingActive                    = pSrc->NavRoutingActive;
  pDest->f_AngleClothStart                   = pSrc->f_AngleClothStart;
}

__inline void v_Convert_v5_to_v4 (NaviInputData_V4::t_NaviInputData * const pDest,
  const NaviInputData_V5::t_NaviInputData * const pSrc)
{
  pDest->uiVersionNumber = 4u;
  pDest->sSigHeader = pSrc->sSigHeader;

  for (int nI=0; nI < 8; nI++)
  {
    pDest->Segments[nI].u_QuanLanes          = pSrc->Segments[nI].u_QuanLanes;
    pDest->Segments[nI].u_ProbEgoTakesBranch = pSrc->Segments[nI].u_ProbEgoTakesBranch;
    pDest->Segments[nI].TypStreet            = pSrc->Segments[nI].TypStreet;
    pDest->Segments[nI].f_Length             = pSrc->Segments[nI].f_Length;
    pDest->Segments[nI].f_Curvature          = pSrc->Segments[nI].f_Curvature;
    pDest->Segments[nI].f_AnglePrevSeg       = pSrc->Segments[nI].f_AnglePrevSeg;
    pDest->Segments[nI].TypStreetBranch      = pSrc->Segments[nI].TypStreetBranch;
    pDest->Segments[nI].f_AnglePrevBranch    = pSrc->Segments[nI].f_AnglePrevBranch;
  }

  pDest->b_MppNew                            = pSrc->b_MppNew;
  pDest->u_NumUsedSegments                   = pSrc->u_NumUsedSegments;
  pDest->u_QualityNavData                    = pSrc->u_QualityNavData;
  pDest->u_DistNextRoundabout                = pSrc->u_DistNextRoundabout;
  pDest->u_DistNextTunnelStart               = pSrc->u_DistNextTunnelStart;
  pDest->u_DistNextTunnelEnd                 = pSrc->u_DistNextTunnelEnd;
  pDest->u_DistNextTollbooth                 = pSrc->u_DistNextTollbooth;
  pDest->u_DistNextExitLaneStart             = pSrc->u_DistNextExitLaneStart;
  pDest->u_DistNextExitLaneEnd               = pSrc->u_DistNextExitLaneEnd;
  pDest->u_DistNextBridge                    = pSrc->u_DistNextBridge;
  pDest->NavRoutingActive                    = pSrc->NavRoutingActive;
  pDest->f_AngleClothStart                   = pSrc->f_AngleClothStart;
}

CConvNaviInputData::CConvNaviInputData(void) : CSimConverterBase(NULL/*DEP_NAMES*/, DEP_COUNT), m_BufV4(), m_BufV5(), m_BufV6(), m_BufV8(), m_BufV8_2()
{
  InitV4(m_BufV4);
  InitV5(m_BufV5);
  InitV6(m_BufV6);
  InitV8(m_BufV8);
  InitV8_2(m_BufV8_2);
}

CConvNaviInputData::~CConvNaviInputData(void)
{
}

void CConvNaviInputData::InitV4(NaviInputData_V4::t_NaviInputData &Params)
{
  ::memset(&Params, 0, sizeof(Params));
  Params.uiVersionNumber       = 4u;
  // Signal Header
  Params.sSigHeader.eSigStatus = AL_SIG_STATE_INIT;
}

void CConvNaviInputData::InitV5(NaviInputData_V5::t_NaviInputData &Params)
{
  ::memset(&Params, 0, sizeof(Params));
  Params.uiVersionNumber       = 5u;
  // Signal Header
  Params.sSigHeader.eSigStatus = AL_SIG_STATE_INIT;
}

void CConvNaviInputData::InitV6(NaviInputData_V6::t_NaviInputData &Params)
{
  ::memset(&Params, 0, sizeof(Params));
  Params.uiVersionNumber       = 6u;
  // Signal Header
  Params.sSigHeader.eSigStatus = AL_SIG_STATE_INIT;
}

void CConvNaviInputData::InitV8(NaviInputData_V8::t_NaviInputData &Params)
{
  ::memset(&Params, 0, sizeof(Params));
  Params.uiVersionNumber       = 8u;
  // Signal Header
  Params.sSigHeader.eSigStatus = AL_SIG_STATE_INIT;
}

void CConvNaviInputData::InitV8_2(NaviInputData_V8_2::t_NaviInputData &Params)
{
  ::memset(&Params, 0, sizeof(Params));
  Params.uiVersionNumber       = 8u;
  // Signal Header
  Params.sSigHeader.eSigStatus = AL_SIG_STATE_INIT;
}

long CConvNaviInputData::ConvertData(
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
      if ((ulPPortSize == SUPPORTED_SIZE[NAVI_INPUT_DATA_V4]) &&
        ((pProvidePortVersionInfo == NULL) ||
        pProvidePortVersionInfo->Equals(NAVI_INPUT_DATA_VERSIONS[NAVI_INPUT_DATA_V4]) || 
        pProvidePortVersionInfo->Equals(&BASE_VERSION)) &&
        (uDataVer == 0x4u))
      {
        const NaviInputData_V4::t_NaviInputData *pSrc = reinterpret_cast<NaviInputData_V4::t_NaviInputData *>(pPPortData);
        // The decide which version we are converting to
        if ((ulRPortSize == SUPPORTED_SIZE[NAVI_INPUT_DATA_V8_2]) &&
          (requestPortVersionInfo.Equals(NAVI_INPUT_DATA_VERSIONS[NAVI_INPUT_DATA_V8_2]) ||
          requestPortVersionInfo.Equals(&BASE_VERSION)))
        {
          // Destination port of V8_2 is m_BufV8_2
          v_Convert_v4_to_v5(&m_BufV5, pSrc);
          v_Convert_v5_to_v6(&m_BufV6, &m_BufV5);
          v_Convert_v6_to_v8(&m_BufV8, &m_BufV6);
          v_Convert_v8_to_v8_2(&m_BufV8_2, &m_BufV8);
          *pOutData = &m_BufV8_2;
          ulOutSize = sizeof(m_BufV8_2);
          lRet = SIM_ERR_OK;
        }
        else if ((ulRPortSize == SUPPORTED_SIZE[NAVI_INPUT_DATA_V8]) &&
          (requestPortVersionInfo.Equals(NAVI_INPUT_DATA_VERSIONS[NAVI_INPUT_DATA_V8]) ||
          requestPortVersionInfo.Equals(&BASE_VERSION)))
        {
          // Destination port of V8 is m_BufV8
          v_Convert_v4_to_v5(&m_BufV5, pSrc);
          v_Convert_v5_to_v6(&m_BufV6, &m_BufV5);
          v_Convert_v6_to_v8(&m_BufV8, &m_BufV6);
          *pOutData = &m_BufV8;
          ulOutSize = sizeof(m_BufV8);
          lRet = SIM_ERR_OK;
        }
        else if ((ulRPortSize == SUPPORTED_SIZE[NAVI_INPUT_DATA_V6]) &&
          (requestPortVersionInfo.Equals(NAVI_INPUT_DATA_VERSIONS[NAVI_INPUT_DATA_V6]) ||
          requestPortVersionInfo.Equals(&BASE_VERSION)))
        {
          // Destination port of V6 is m_BufV6
          v_Convert_v4_to_v5(&m_BufV5, pSrc);
          v_Convert_v5_to_v6(&m_BufV6, &m_BufV5);
          *pOutData = &m_BufV6;
          ulOutSize = sizeof(m_BufV6);
          lRet = SIM_ERR_OK;
        }
        else if ((ulRPortSize == SUPPORTED_SIZE[NAVI_INPUT_DATA_V5]) &&
          (requestPortVersionInfo.Equals(NAVI_INPUT_DATA_VERSIONS[NAVI_INPUT_DATA_V5]) ||
          requestPortVersionInfo.Equals(&BASE_VERSION)))
        {
          // Destination port of V5 is m_BufV5
          v_Convert_v4_to_v5(&m_BufV5, pSrc);
          *pOutData = &m_BufV5;
          ulOutSize = sizeof(m_BufV5);
          lRet = SIM_ERR_OK;
        }
      }
      else if ((ulPPortSize == SUPPORTED_SIZE[NAVI_INPUT_DATA_V5]) &&
        ((pProvidePortVersionInfo == NULL) ||
        pProvidePortVersionInfo->Equals(NAVI_INPUT_DATA_VERSIONS[NAVI_INPUT_DATA_V5]) || 
        pProvidePortVersionInfo->Equals(&BASE_VERSION)) &&
        (uDataVer == 0x5u))
      {
        const NaviInputData_V5::t_NaviInputData *pSrc = reinterpret_cast<NaviInputData_V5::t_NaviInputData *>(pPPortData);
        // The decide which version we are converting to
        if ((ulRPortSize == SUPPORTED_SIZE[NAVI_INPUT_DATA_V8_2]) &&
          (requestPortVersionInfo.Equals(NAVI_INPUT_DATA_VERSIONS[NAVI_INPUT_DATA_V8_2]) ||
          requestPortVersionInfo.Equals(&BASE_VERSION)))
        {
          // Destination port of V8_2 is m_BufV8_2
          v_Convert_v5_to_v6(&m_BufV6, pSrc);
          v_Convert_v6_to_v8(&m_BufV8, &m_BufV6);
          v_Convert_v8_to_v8_2(&m_BufV8_2, &m_BufV8);
          *pOutData = &m_BufV8_2;
          ulOutSize = sizeof(m_BufV8_2);
          lRet = SIM_ERR_OK;
        }
        else if ((ulRPortSize == SUPPORTED_SIZE[NAVI_INPUT_DATA_V8]) &&
          (requestPortVersionInfo.Equals(NAVI_INPUT_DATA_VERSIONS[NAVI_INPUT_DATA_V8]) ||
          requestPortVersionInfo.Equals(&BASE_VERSION)))
        {
          // Destination port of V8 is m_BufV8
          v_Convert_v5_to_v6(&m_BufV6, pSrc);
          v_Convert_v6_to_v8(&m_BufV8, &m_BufV6);
          *pOutData = &m_BufV8;
          ulOutSize = sizeof(m_BufV8);
          lRet = SIM_ERR_OK;
        }
        else if ((ulRPortSize == SUPPORTED_SIZE[NAVI_INPUT_DATA_V6]) &&
          (requestPortVersionInfo.Equals(NAVI_INPUT_DATA_VERSIONS[NAVI_INPUT_DATA_V6]) ||
          requestPortVersionInfo.Equals(&BASE_VERSION)))
        {
          // Destination port of V6 is m_BufV6
          v_Convert_v5_to_v6(&m_BufV6, pSrc);
          *pOutData = &m_BufV6;
          ulOutSize = sizeof(m_BufV6);
          lRet = SIM_ERR_OK;
        }
        else if ((ulRPortSize == SUPPORTED_SIZE[NAVI_INPUT_DATA_V4]) &&
          (requestPortVersionInfo.Equals(NAVI_INPUT_DATA_VERSIONS[NAVI_INPUT_DATA_V4]) ||
          requestPortVersionInfo.Equals(&BASE_VERSION)))
        {
          // Destination port of V4 is m_BufV4
          v_Convert_v5_to_v4(&m_BufV4, pSrc);
          *pOutData = &m_BufV4;
          ulOutSize = sizeof(m_BufV4);
          lRet = SIM_ERR_OK;
        }
      }
      else if ((ulPPortSize == SUPPORTED_SIZE[NAVI_INPUT_DATA_V6]) &&
        ((pProvidePortVersionInfo == NULL) ||
        pProvidePortVersionInfo->Equals(NAVI_INPUT_DATA_VERSIONS[NAVI_INPUT_DATA_V6]) ||
        pProvidePortVersionInfo->Equals(&BASE_VERSION)) &&
        (uDataVer == 0x6u))
      {
        const NaviInputData_V6::t_NaviInputData *pSrc = reinterpret_cast<NaviInputData_V6::t_NaviInputData *>(pPPortData);
        // The decide which version we are converting to
        if ((ulRPortSize == SUPPORTED_SIZE[NAVI_INPUT_DATA_V8_2]) &&
          (requestPortVersionInfo.Equals(NAVI_INPUT_DATA_VERSIONS[NAVI_INPUT_DATA_V8_2]) ||
          requestPortVersionInfo.Equals(&BASE_VERSION)))
        {
          // Destination port of V8_2 is m_BufV8_2
          v_Convert_v6_to_v8(&m_BufV8, pSrc);
          v_Convert_v8_to_v8_2(&m_BufV8_2, &m_BufV8);
          *pOutData = &m_BufV8_2;
          ulOutSize = sizeof(m_BufV8_2);
          lRet = SIM_ERR_OK;
        }
        else if ((ulRPortSize == SUPPORTED_SIZE[NAVI_INPUT_DATA_V8]) &&
          (requestPortVersionInfo.Equals(NAVI_INPUT_DATA_VERSIONS[NAVI_INPUT_DATA_V8]) ||
          requestPortVersionInfo.Equals(&BASE_VERSION)))
        {
          // Destination port of V8 is m_BufV8
          v_Convert_v6_to_v8(&m_BufV8, pSrc);
          *pOutData = &m_BufV8;
          ulOutSize = sizeof(m_BufV8);
          lRet = SIM_ERR_OK;
        }
        else if ((ulRPortSize == SUPPORTED_SIZE[NAVI_INPUT_DATA_V5]) &&
          (requestPortVersionInfo.Equals(NAVI_INPUT_DATA_VERSIONS[NAVI_INPUT_DATA_V5]) ||
          requestPortVersionInfo.Equals(&BASE_VERSION)))
        {
          // Destination port of V5 is m_BufV5
          v_Convert_v6_to_v5(&m_BufV5, pSrc);
          *pOutData = &m_BufV5;
          ulOutSize = sizeof(m_BufV5);
          lRet = SIM_ERR_OK;
        }
        else if ((ulRPortSize == SUPPORTED_SIZE[NAVI_INPUT_DATA_V4]) &&
          (requestPortVersionInfo.Equals(NAVI_INPUT_DATA_VERSIONS[NAVI_INPUT_DATA_V4]) ||
          requestPortVersionInfo.Equals(&BASE_VERSION)))
        {
          // Destination port of V4 is m_BufV4
          v_Convert_v6_to_v5(&m_BufV5, pSrc);
          v_Convert_v5_to_v4(&m_BufV4, &m_BufV5);
          *pOutData = &m_BufV4;
          ulOutSize = sizeof(m_BufV4);
          lRet = SIM_ERR_OK;
        }
      }
      else if ((ulPPortSize == SUPPORTED_SIZE[NAVI_INPUT_DATA_V8]) &&
        ((pProvidePortVersionInfo == NULL) ||
        pProvidePortVersionInfo->Equals(NAVI_INPUT_DATA_VERSIONS[NAVI_INPUT_DATA_V8]) ||
        pProvidePortVersionInfo->Equals(&BASE_VERSION)) &&
        (uDataVer == 0x8u))
      {
        const NaviInputData_V8::t_NaviInputData *pSrc = reinterpret_cast<NaviInputData_V8::t_NaviInputData *>(pPPortData);
        // The decide which version we are converting to
        if ((ulRPortSize == SUPPORTED_SIZE[NAVI_INPUT_DATA_V8_2]) &&
          (requestPortVersionInfo.Equals(NAVI_INPUT_DATA_VERSIONS[NAVI_INPUT_DATA_V8_2]) ||
          requestPortVersionInfo.Equals(&BASE_VERSION)))
        {
          // Destination port of V8_2 is m_BufV8_2
          v_Convert_v8_to_v8_2(&m_BufV8_2, pSrc);
          *pOutData = &m_BufV8_2;
          ulOutSize = sizeof(m_BufV8_2);
          lRet = SIM_ERR_OK;
        }
        else if ((ulRPortSize == SUPPORTED_SIZE[NAVI_INPUT_DATA_V6]) &&
          (requestPortVersionInfo.Equals(NAVI_INPUT_DATA_VERSIONS[NAVI_INPUT_DATA_V6]) ||
          requestPortVersionInfo.Equals(&BASE_VERSION)))
        {
          // Destination port of V6 is m_BufV6
          v_Convert_v8_to_v6(&m_BufV6, pSrc);
          *pOutData = &m_BufV6;
          ulOutSize = sizeof(m_BufV6);
          lRet = SIM_ERR_OK;
        }
        else if ((ulRPortSize == SUPPORTED_SIZE[NAVI_INPUT_DATA_V5]) &&
          (requestPortVersionInfo.Equals(NAVI_INPUT_DATA_VERSIONS[NAVI_INPUT_DATA_V5]) ||
          requestPortVersionInfo.Equals(&BASE_VERSION)))
        {
          // Destination port of V5 is m_BufV5
          v_Convert_v8_to_v6(&m_BufV6, pSrc);
          v_Convert_v6_to_v5(&m_BufV5, &m_BufV6);
          *pOutData = &m_BufV5;
          ulOutSize = sizeof(m_BufV5);
          lRet = SIM_ERR_OK;
        }
        else if ((ulRPortSize == SUPPORTED_SIZE[NAVI_INPUT_DATA_V4]) &&
          (requestPortVersionInfo.Equals(NAVI_INPUT_DATA_VERSIONS[NAVI_INPUT_DATA_V4]) ||
          requestPortVersionInfo.Equals(&BASE_VERSION)))
        {
          // Destination port of V4 is m_BufV4
          v_Convert_v8_to_v6(&m_BufV6, pSrc);
          v_Convert_v6_to_v5(&m_BufV5, &m_BufV6);
          v_Convert_v5_to_v4(&m_BufV4, &m_BufV5);
          *pOutData = &m_BufV4;
          ulOutSize = sizeof(m_BufV4);
          lRet = SIM_ERR_OK;
        }
      }
      else if ((ulPPortSize == SUPPORTED_SIZE[NAVI_INPUT_DATA_V8_2]) &&
        ((pProvidePortVersionInfo == NULL) ||
        pProvidePortVersionInfo->Equals(NAVI_INPUT_DATA_VERSIONS[NAVI_INPUT_DATA_V8_2]) ||
        pProvidePortVersionInfo->Equals(&BASE_VERSION)) &&
        (uDataVer == 0x8u))
      {
        const NaviInputData_V8_2::t_NaviInputData *pSrc = reinterpret_cast<NaviInputData_V8_2::t_NaviInputData *>(pPPortData);
        // The decide which version we are converting to
        if ((ulRPortSize == SUPPORTED_SIZE[NAVI_INPUT_DATA_V8]) &&
          (requestPortVersionInfo.Equals(NAVI_INPUT_DATA_VERSIONS[NAVI_INPUT_DATA_V8]) ||
          requestPortVersionInfo.Equals(&BASE_VERSION)))
        {
          // Destination port of V8 is m_BufV8
          v_Convert_v8_2_to_v8(&m_BufV8, pSrc);
          *pOutData = &m_BufV8;
          ulOutSize = sizeof(m_BufV8);
          lRet = SIM_ERR_OK;
        }
        else if ((ulRPortSize == SUPPORTED_SIZE[NAVI_INPUT_DATA_V6]) &&
          (requestPortVersionInfo.Equals(NAVI_INPUT_DATA_VERSIONS[NAVI_INPUT_DATA_V6]) ||
          requestPortVersionInfo.Equals(&BASE_VERSION)))
        {
          // Destination port of V6 is m_BufV6
          v_Convert_v8_2_to_v8(&m_BufV8, pSrc);
          v_Convert_v8_to_v6(&m_BufV6, &m_BufV8);
          *pOutData = &m_BufV6;
          ulOutSize = sizeof(m_BufV6);
          lRet = SIM_ERR_OK;
        }
        else if ((ulRPortSize == SUPPORTED_SIZE[NAVI_INPUT_DATA_V5]) &&
          (requestPortVersionInfo.Equals(NAVI_INPUT_DATA_VERSIONS[NAVI_INPUT_DATA_V5]) ||
          requestPortVersionInfo.Equals(&BASE_VERSION)))
        {
          // Destination port of V5 is m_BufV5
          v_Convert_v8_2_to_v8(&m_BufV8, pSrc);
          v_Convert_v8_to_v6(&m_BufV6, &m_BufV8);
          v_Convert_v6_to_v5(&m_BufV5, &m_BufV6);
          *pOutData = &m_BufV5;
          ulOutSize = sizeof(m_BufV5);
          lRet = SIM_ERR_OK;
        }
        else if ((ulRPortSize == SUPPORTED_SIZE[NAVI_INPUT_DATA_V4]) &&
          (requestPortVersionInfo.Equals(NAVI_INPUT_DATA_VERSIONS[NAVI_INPUT_DATA_V4]) ||
          requestPortVersionInfo.Equals(&BASE_VERSION)))
        {
          // Destination port of V4 is m_BufV4
          v_Convert_v8_2_to_v8(&m_BufV8, pSrc);
          v_Convert_v8_to_v6(&m_BufV6, &m_BufV8);
          v_Convert_v6_to_v5(&m_BufV5, &m_BufV6);
          v_Convert_v5_to_v4(&m_BufV4, &m_BufV5);
          *pOutData = &m_BufV4;
          ulOutSize = sizeof(m_BufV4);
          lRet = SIM_ERR_OK;
        }
      }
    }
  }
  return lRet;
}

/** returns:
 *   SIM_ERR_OK - when this value can be used
 *   SIM_ERR_USE_DEFAULT_VALUE_FROM_RPORT - when the default value is not implemented here
 *                                          and the default value from Request Port must be used
 */
long CConvNaviInputData::GetDefaultValue(
  SimPortDataTypes_t eRPortType, unsigned long ulRPortSize, const IVersionInfo &requestPortVersionInfo,
  void **pDefaultData, unsigned long &ulDefaultSize)
{
  long lRet = SIM_ERR_USE_DEFAULT_VALUE_FROM_RPORT;
  if (eRPortType == simOPAQUE_t)
  {
    if ((ulRPortSize == SUPPORTED_SIZE[NAVI_INPUT_DATA_V8_2]) && ((BASE_VERSION.Equals(&requestPortVersionInfo)) || (requestPortVersionInfo.Equals(NAVI_INPUT_DATA_VERSIONS[NAVI_INPUT_DATA_V8_2]))))
    {
      InitV8_2(m_BufV8_2);
      *pDefaultData = &m_BufV8_2;
      ulDefaultSize = SUPPORTED_SIZE[NAVI_INPUT_DATA_V8_2];
      lRet = SIM_ERR_OK;
    }
    else if ((ulRPortSize == SUPPORTED_SIZE[NAVI_INPUT_DATA_V8]) && ((BASE_VERSION.Equals(&requestPortVersionInfo)) || (requestPortVersionInfo.Equals(NAVI_INPUT_DATA_VERSIONS[NAVI_INPUT_DATA_V8]))))
    {
      InitV8(m_BufV8);
      *pDefaultData = &m_BufV8;
      ulDefaultSize = SUPPORTED_SIZE[NAVI_INPUT_DATA_V8];
      lRet = SIM_ERR_OK;
    }
    else if ((ulRPortSize == SUPPORTED_SIZE[NAVI_INPUT_DATA_V6]) && ((BASE_VERSION.Equals(&requestPortVersionInfo)) || (requestPortVersionInfo.Equals(NAVI_INPUT_DATA_VERSIONS[NAVI_INPUT_DATA_V6]))))
    {
      InitV6(m_BufV6);
      *pDefaultData = &m_BufV6;
      ulDefaultSize = SUPPORTED_SIZE[NAVI_INPUT_DATA_V6];
      lRet = SIM_ERR_OK;
    }
    else if ((ulRPortSize == SUPPORTED_SIZE[NAVI_INPUT_DATA_V5]) && ((BASE_VERSION.Equals(&requestPortVersionInfo)) || (requestPortVersionInfo.Equals(NAVI_INPUT_DATA_VERSIONS[NAVI_INPUT_DATA_V5]))))
    {
      InitV5(m_BufV5);
      *pDefaultData = &m_BufV5;
      ulDefaultSize = SUPPORTED_SIZE[NAVI_INPUT_DATA_V5];
      lRet = SIM_ERR_OK;
    }
    else if ((ulRPortSize == SUPPORTED_SIZE[NAVI_INPUT_DATA_V4]) && ((BASE_VERSION.Equals(&requestPortVersionInfo)) || (requestPortVersionInfo.Equals(NAVI_INPUT_DATA_VERSIONS[NAVI_INPUT_DATA_V4]))))
    {
      InitV4(m_BufV4);
      *pDefaultData = &m_BufV4;
      ulDefaultSize = SUPPORTED_SIZE[NAVI_INPUT_DATA_V4];
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
bool CConvNaviInputData::IsVersionCompatibleWithType(
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
bool CConvNaviInputData::AreVersionsCompatible(
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
IConverter * CreateNaviInputDataConvInstance(void)
{
  return new CConvNaviInputData();
}
