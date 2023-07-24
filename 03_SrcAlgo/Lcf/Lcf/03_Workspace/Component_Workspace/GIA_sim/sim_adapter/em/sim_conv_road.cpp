/*! \file **********************************************************************

  COMPANY:              Continental

  PROJECT:              Simulation

  COMPONENT:            sim_adapter_fct

  MODULNAME:            sim_conv_road.cpp

  DESCRIPTION:          Converter class for Road

  AUTHOR:               Teodora Cretu

  CREATION DATE:        13.01.2017

  VERSION:              $$

  ---*/ /*---
  CHANGES:              $Log: sim_conv_road.cpp  $
  CHANGES:              Revision 1.1 2017/08/10 13:15:09CEST uid34177 
  CHANGES:              Initial revision
  CHANGES:              Member added to project /ADAS/SW/Integration/06_Simulation_Components/GIA_GenericInterfaceAdapter/04_Engineering/03_Workspace/Component_Workspace/GIA_sim/sim_adapter/em/project.pj
  CHANGES:              Revision 1.1 2017/01/13 13:32:14CET Cretu, Teodora (CretuT) 
  CHANGES:              Initial revision
  CHANGES:              Member added to project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/CRT_CommonRadarToolbox/04_Engineering/03_Workspace/algo/sim_adapter/em/project.pj

**************************************************************************** */
/* includes ---------------------------------------------------------------- */
#include "stdafx.h"
#include "sim_conv_road.h"
#include "sim_versioninfo_impl.h"
#include "interfacedriverinput.h"

namespace EM_ROAD_V0
{
  typedef unsigned long AlgoDataTimeStamp_t       /* Algo data time-stamp type (32 bit variant) @min:0 @max:4294967295 */	/* [Satisfies_rte sws 1188] */;
  typedef unsigned short AlgoCycleCounter_t        /* Algo cycle counter @min:0 @max:65535 */	/* [Satisfies_rte sws 1188] */;
  typedef signed char eLaneWidthClass_t         /* Classification of different lane width categories @min: -1 @max:2 @values: enum { LANE_WIDTH_CLASS_NARROW=1,LANE_WIDTH_CLASS_MORE_NARROW=2,LANE_WIDTH_CLASS_UNKNOWN=-1,LANE_WIDTH_CLASS_NORMAL=0,} */	/* [Satisfies_rte sws 1188] */;
  typedef unsigned char eLaneWidthSource_t        /* ??? @min: 0 @max:1 @values: enum { Source0=0,Source1=1,} */	/* [Satisfies_rte sws 1188] */;
  typedef unsigned char e_BorderType_t            /* @min: 0 @max:2 @values: enum { ROAD_BORDERTYPE_OTHER=2,ROAD_BORDERTYPE_UNKNOWN=0,ROAD_BORDERTYPE_GUARDRAIL=1,} */	/* [Satisfies_rte sws 1188] */;
  typedef unsigned char eTrafficOrientation_t     /* left-hand / right-hand traffic @min: 0 @max:2 @values: enum { GDB_TRAFFICORIENTATION_RIGHT_HAND=1,GDB_TRAFFICORIENTATION_LEFT_HAND=2,TRAFFICORIENTATION_UNKNOWN=0,} */	/* [Satisfies_rte sws 1188] */;
  typedef unsigned char eRoadTypeClass_t          /* @min: 0 @max:3 @values: enum { ROAD_TYPE_UNKNOWN=0,ROAD_TYPE_HIGHWAY=3,ROAD_TYPE_COUNTRY=2,ROAD_TYPE_CITY=1,} */	/* [Satisfies_rte sws 1188] */;
  typedef unsigned char eRoadWorksClass_t         /* @min: 0 @max:2 @values: enum { ROAD_TYPE_LEVEL2_NOINFO=0,ROAD_TYPE_LEVEL2_ROADWORKS=2,} */	/* [Satisfies_rte sws 1188] */;

  typedef struct 			/* [Satisfies_rte sws 1191] */
{
	AlgoDataTimeStamp_t uiTimeStamp;
 	AlgoCycleCounter_t uiMeasurementCounter;
 	AlgoCycleCounter_t uiCycleCounter;
 	AlgoSignalState_t eSigStatus;
 } SignalHeader_t;			/* Common header for all structured data types */

  typedef struct 			/* [Satisfies_rte sws 1191] */
{
	eLaneWidthClass_t eLaneWidthClass;
 	float fLaneWidth;
 	eLaneWidthSource_t eLaneWidthSource;
 } LaneWidth_t;			/* Lane width properties */

  typedef struct 			/* [Satisfies_rte sws 1191] */
{
	signed char iNumOfLaneRight;
 	signed char iNumOfLaneLeft;
 	float NoLaneProbLeft;
 	float NoLaneProbRight;
 } LaneMatrix_t;			/* Adjacent lanes in same direction */

  typedef struct 			/* [Satisfies_rte sws 1191] */
{
	float f_YawAngle;
 	float f_Curvature;
 	float f_ClothoidParam1;
 	float f_TransitionPoint;
 	float f_ClothoidParam2;
 } ClothoidParameters_t;			/* Clothoid parameters for the coupled road */

  typedef struct 			/* [Satisfies_rte sws 1191] */
{
	float f_Confidence;
 	float f_MinX;
 	float f_MaxX;
 	float f_MaxXCompensated;
 	e_BorderType_t e_BorderType;
 	unsigned char u_TrackingStatus;
 } QualityMeasures_t;			/* Quality measures for the left side of the coupled road */

  typedef struct 			/* [Satisfies_rte sws 1191] */
{
	ClothoidParameters_t ClothoidParams;
 	QualityMeasures_t QualityMeasLeft;
 	QualityMeasures_t QualityMeasRight;
 	float f_LateralOffsetLeft;
 	float f_LateralOffsetRight;
 	float f_LatStdDevFiltered;
 	unsigned char u_GlobalConfidence;
 	unsigned char u_GlobalTrackingStatus;
 } CoupledRoad_t;			/* Coupled borders road */

  typedef struct 			/* [Satisfies_rte sws 1191] */
{
	ClothoidParameters_t ClothoidParams;
 	QualityMeasures_t QualityMeas;
 	float f_LateralOffset;
 	float f_LatStdDevFiltered;
 } RoadBorder_t;			/* Independent border left */

  typedef struct 			/* [Satisfies_rte sws 1191] */
{
	CoupledRoad_t CoupledRoad;
 	RoadBorder_t RoadBorderLeft;
 	RoadBorder_t RoadBorderRight;
 } RoadEstimation_t;			/* Road clothoids */

  typedef struct 			/* [Satisfies_rte sws 1191] */
{
	float fDistRight;
 	float fDistRightStd;
 	float fDistLeft;
 	float fDistLeftStd;
 	unsigned char bStatusRight;
 	unsigned char bStatusLeft;
 } FusedRoadBorder_t;			/* Boundary of road */

  typedef struct 			/* [Satisfies_rte sws 1191] */
{
	eTrafficOrientation_t eTrafficOrientation;
 	float fTimeToNextWriteAllowed;
 	boolean bWriteToNVM;
 } Traffic_t;			/* Traffic dependent properties */

  typedef struct 			/* [Satisfies_rte sws 1191] */
{
	eRoadTypeClass_t eRoadTypeClass;
 	float fRoadTypeClassConf;
 	eRoadWorksClass_t eRoadWorksClass;
 	float fRoadWorksClassConf;
 } RoadType_t;			

  typedef struct 			/* [Satisfies_rte sws 1191] */
{
	unsigned long uiVersionNumber;
 	SignalHeader_t sSigHeader;
 	LaneWidth_t LaneWidth;
 	LaneMatrix_t LaneMatrix;
 	RoadEstimation_t RoadEstimation;
 	FusedRoadBorder_t FusedRoadBorder;
 	Traffic_t Traffic;
 	RoadType_t RoadType;
 } Road_t;			/* Road data @vaddr:0x20112100 @vaddr_defs: MEAS_ID_ROAD_PUBLIC_GLOB_DATA @cycleid:EM_ENV @vname:Road */
}
namespace EM_ROAD_V1
{
  typedef unsigned long AlgoDataTimeStamp_t       /* Algo data time-stamp type (32 bit variant) @min:0 @max:4294967295 */	/* [Satisfies_rte sws 1188] */;
  typedef unsigned short AlgoCycleCounter_t        /* Algo cycle counter @min:0 @max:65535 */	/* [Satisfies_rte sws 1188] */;
  typedef unsigned char AlgoSignalState_t         /* Algo signal state enumeration @min: 0 @max:2 @values: enum { AL_SIG_STATE_INVALID=2,AL_SIG_STATE_INIT=0,AL_SIG_STATE_OK=1,} */	/* [Satisfies_rte sws 1188] */;
  typedef unsigned char eRoadType_t               /* Classification of different road catagories @min: 0 @max:3 @values: enum { ROAD_TYPE_UNKNOWN=0,ROAD_TYPE_HIGHWAY=3,ROAD_TYPE_COUNTRY=2,ROAD_TYPE_CITY=1,} */	/* [Satisfies_rte sws 1188] */;
  typedef signed char eLaneWidthClass_t         /* Classification of different lane width categories @min: -1 @max:2 @values: enum { LANE_WIDTH_CLASS_NARROW=1,LANE_WIDTH_CLASS_MORE_NARROW=2,LANE_WIDTH_CLASS_UNKNOWN=-1,LANE_WIDTH_CLASS_NORMAL=0,} */	/* [Satisfies_rte sws 1188] */;
  typedef unsigned char eLaneWidthSource_t        /* ??? @min: 0 @max:1 @values: enum { Source0=0,Source1=1,} */	/* [Satisfies_rte sws 1188] */;
  typedef unsigned char eTrafficOrientation_t     /* left-hand / right-hand traffic @min: 0 @max:2 @values: enum { GDB_TRAFFICORIENTATION_RIGHT_HAND=1,GDB_TRAFFICORIENTATION_LEFT_HAND=2,TRAFFICORIENTATION_UNKNOWN=0,} */	/* [Satisfies_rte sws 1188] */;
  typedef unsigned char eRoadTypeLevel1_t         /* @min: 0 @max:3 @values: enum { ROAD_TYPE_MARKOV_HIGHWAY=3,ROAD_TYPE_MARKOV_NOINFO=0,ROAD_TYPE_MARKOV_CITY=1,ROAD_TYPE_MARKOV_COUNTYROAD=2,} */	/* [Satisfies_rte sws 1188] */;
  typedef unsigned char eRoadTypeLevel2_t         /* @min: 0 @max:2 @values: enum { ROAD_TYPE_LEVEL2_NOINFO=0,ROAD_TYPE_LEVEL2_ROADWORKS=2,} */	/* [Satisfies_rte sws 1188] */;

  typedef struct 			/* [Satisfies_rte sws 1191] */
{
	AlgoDataTimeStamp_t uiTimeStamp;
 	AlgoCycleCounter_t uiMeasurementCounter;
 	AlgoCycleCounter_t uiCycleCounter;
 	AlgoSignalState_t eSigStatus;
 } SignalHeader_t;			/* Common header for all structured data types */

 typedef struct 			/* [Satisfies_rte sws 1191] */
{
	eRoadType_t eRoadType;
 } RoadType_t;			/* Road catagory */

 typedef struct 			/* [Satisfies_rte sws 1191] */
{
	eLaneWidthClass_t eLaneWidthClass;
 	float fLaneWidth;
 	eLaneWidthSource_t eLaneWidthSource;
 } LaneWidth_t;			/* Lane width properties */

 typedef struct 			/* [Satisfies_rte sws 1191] */
{
	float NoLaneProbLeft;
 	float NoLaneProbRight;
 } LegacyLM_t;			/* Boundary of road */

 typedef struct 			/* [Satisfies_rte sws 1191] */
{
	signed char iNumOfLaneRight;
 	signed char iNumOfLaneLeft;
 	LegacyLM_t Legacy;
 } LaneMatrix_t;			/* Adjacent lanes in same direction */

 typedef struct 			/* [Satisfies_rte sws 1191] */
{
	float fYLeft;
 	float fYRight;
 	unsigned char uiTrackingStatus;
 	unsigned char uiTrackingStatusLeft;
 	unsigned char uiTrackingStatusRight;
 	unsigned char uiConfidence;
 } LegacyRE_t;			/* Boundary of road */

 typedef struct 			/* [Satisfies_rte sws 1191] */
{
	float fC0;
 	float fC1;
 	float fYawAngle;
 	float fConfRight;
 	float fConfLeft;
 	float fRangeMaxRight;
 	float fRangeMaxLeft;
 	float fLateralVarianceMax;
 	LegacyRE_t Legacy;
 } RoadEstimation_t;			/* Road curvature bend (anticipatory) */

 typedef struct 			/* [Satisfies_rte sws 1191] */
{
	float fDistRight;
 	float fDistRightStd;
 	float fDistLeft;
 	float fDistLeftStd;
 	unsigned char bStatusRight;
 	unsigned char bStatusLeft;
 } FusedRoadBorder_t;			/* Boundary of road */

 typedef struct 			/* [Satisfies_rte sws 1191] */
{
	signed long left;
 	signed long right;
 } LaneChange_t;			/* Lane change detection */

 typedef struct 			/* [Satisfies_rte sws 1191] */
{
	boolean bWriteToNVM;
 	float fTimeToNextWriteAllowed;
 } LegacyTraffic_t;			/* Traffic dependent Legacy */

 typedef struct 			/* [Satisfies_rte sws 1191] */
{
	eTrafficOrientation_t eTrafficOrientation;
 	float TrafficDensity;
 	LegacyTraffic_t Legacy;
 } Traffic_t;			/* Traffic dependent properties */

 typedef struct 			/* [Satisfies_rte sws 1191] */
{
	eRoadTypeLevel1_t eRoadTypeLevel1;
 	float fRoadConfLevel1;
 	eRoadTypeLevel2_t eRoadTypeLevel2;
 	float fRoadConfLevel2;
 } RoadTypeClass_t;	

 typedef struct 			/* [Satisfies_rte sws 1191] */
{
	float fminXLeft;
 	float fminXRight;
 	float fmaxXLeftCompensated;
 	float fmaxXRightCompensated;
 	float fLatStdDevFiltered;
 	float fConfidenceLeft;
 	float fConfidenceRight;
 } RoadIntData_t;	

 typedef struct 			/* [Satisfies_rte sws 1191] */
{
	RoadTypeClass_t RoadTypeClass;
 	RoadIntData_t RoadIntData;
 } LegacyRoad_t;			/* Road Legacy */

  typedef struct Road_t                          /* [Satisfies_rte sws 1191] */
  {
    unsigned long uiVersionNumber;
    SignalHeader_t sSigHeader;
    RoadType_t RoadType;
    LaneWidth_t LaneWidth;
    unsigned char Roadworks;
    LaneMatrix_t LaneMatrix;
    RoadEstimation_t RoadEstimation;
    FusedRoadBorder_t FusedRoadBorder;
    LaneChange_t LaneChange;
    Traffic_t Traffic;
    LegacyRoad_t Legacy;
  } Road_t;
}

namespace EM_ROAD_GenAll
{
  typedef unsigned char e_BorderType_t            /* @min: 0 @max:2 @values: enum { ROAD_BORDERTYPE_OTHER=2,ROAD_BORDERTYPE_UNKNOWN=0,ROAD_BORDERTYPE_GUARDRAIL=1,} */	/* [Satisfies_rte sws 1188] */;
  typedef unsigned char eTrafficOrientation_t     /* left-hand / right-hand traffic @min: 0 @max:2 @values: enum { GDB_TRAFFICORIENTATION_RIGHT_HAND=1,GDB_TRAFFICORIENTATION_LEFT_HAND=2,TRAFFICORIENTATION_UNKNOWN=0,} */	/* [Satisfies_rte sws 1188] */;
  typedef unsigned char eRoadTypeClass_t          /* @min: 0 @max:3 @values: enum { ROAD_TYPE_UNKNOWN=0,ROAD_TYPE_HIGHWAY=3,ROAD_TYPE_COUNTRY=2,ROAD_TYPE_CITY=1,} */	/* [Satisfies_rte sws 1188] */;
  typedef unsigned char eRoadWorksClass_t         /* @min: 0 @max:2 @values: enum { ROAD_TYPE_LEVEL2_NOINFO=0,ROAD_TYPE_LEVEL2_ROADWORKS=2,} */	/* [Satisfies_rte sws 1188] */;
  typedef unsigned char eRoadType_t               /* Classification of different road catagories @min: 0 @max:3 @values: enum { ROAD_TYPE_UNKNOWN=0,ROAD_TYPE_HIGHWAY=3,ROAD_TYPE_COUNTRY=2,ROAD_TYPE_CITY=1,} */	/* [Satisfies_rte sws 1188] */;

  typedef struct 			/* [Satisfies_rte sws 1191] */
{
	float f_YawAngle;
 	float f_Curvature;
 	float f_ClothoidParam1;
 	float f_TransitionPoint;
 	float f_ClothoidParam2;
 } ClothoidParameters_t;			/* Clothoid parameters for the coupled road */

  typedef struct 			/* [Satisfies_rte sws 1191] */
{
	float f_Confidence;
 	float f_MinX;
 	float f_MaxX;
 	float f_MaxXCompensated;
 	e_BorderType_t e_BorderType;
 	unsigned char u_TrackingStatus;
 } QualityMeasures_t;			/* Quality measures for the left side of the coupled road */

  typedef struct 			/* [Satisfies_rte sws 1191] */
{
	ClothoidParameters_t ClothoidParams;
 	QualityMeasures_t QualityMeasLeft;
 	QualityMeasures_t QualityMeasRight;
 	float f_LateralOffsetLeft;
 	float f_LateralOffsetRight;
 	float f_LatStdDevFiltered;
 	unsigned char u_GlobalConfidence;
 	unsigned char u_GlobalTrackingStatus;
 } CoupledRoad_t;			/* Coupled borders road */

  typedef struct 			/* [Satisfies_rte sws 1191] */
{
	ClothoidParameters_t ClothoidParams;
 	QualityMeasures_t QualityMeas;
 	float f_LateralOffset;
 	float f_LatStdDevFiltered;
 } RoadBorder_t;			/* Independent border left */

  typedef struct 			/* [Satisfies_rte sws 1191] */
{
	float fYLeft;
 	float fYRight;
 	unsigned char uiTrackingStatus;
 	unsigned char uiTrackingStatusLeft;
 	unsigned char uiTrackingStatusRight;
 	unsigned char uiConfidence;
 } LegacyRE_t;			/* Boundary of road */

  typedef struct 			/* [Satisfies_rte sws 1191] */
{
	CoupledRoad_t CoupledRoad;
 	RoadBorder_t RoadBorderLeft;
 	RoadBorder_t RoadBorderRight;
  float fC0;
 	float fC1;
 	float fYawAngle;
 	float fConfRight;
 	float fConfLeft;
 	float fRangeMaxRight;
 	float fRangeMaxLeft;
 	float fLateralVarianceMax;
 	LegacyRE_t Legacy;
 } RoadEstimation_t;			/* Road curvature bend (anticipatory) */

  typedef struct 			/* [Satisfies_rte sws 1191] */
{
	boolean bWriteToNVM;
 	float fTimeToNextWriteAllowed;
 } LegacyTraffic_t;			/* Traffic dependent Legacy */

  typedef struct 			/* [Satisfies_rte sws 1191] */
{
	eTrafficOrientation_t eTrafficOrientation;
 	float fTimeToNextWriteAllowed;
 	boolean bWriteToNVM;
  float TrafficDensity;
 	LegacyTraffic_t Legacy;
 } Traffic_t;			/* Traffic dependent properties */

  typedef struct 			/* [Satisfies_rte sws 1191] */
{
	eRoadTypeClass_t eRoadTypeClass;
 	float fRoadTypeClassConf;
 	eRoadWorksClass_t eRoadWorksClass;
 	float fRoadWorksClassConf;
  eRoadType_t eRoadType;
 } RoadType_t;

  typedef struct 			/* [Satisfies_rte sws 1191] */
{
	float NoLaneProbLeft;
 	float NoLaneProbRight;
 } LegacyLM_t;			/* Boundary of road */

  typedef struct 			/* [Satisfies_rte sws 1191] */
{
	signed char iNumOfLaneRight;
 	signed char iNumOfLaneLeft;
 	float NoLaneProbLeft;
 	float NoLaneProbRight;
  LegacyLM_t Legacy;
 } LaneMatrix_t;			/* Adjacent lanes in same direction */

  typedef struct Road_t                          /* [Satisfies_rte sws 1191] */
  {
    unsigned long uiVersionNumber;
    EM_ROAD_V0::SignalHeader_t sSigHeader;
    EM_ROAD_V0::LaneWidth_t LaneWidth;
    unsigned char Roadworks;
    LaneMatrix_t LaneMatrix;
    RoadEstimation_t RoadEstimation;
    EM_ROAD_V0::FusedRoadBorder_t FusedRoadBorder;
    EM_ROAD_V1::LaneChange_t LaneChange;
    Traffic_t Traffic;
    RoadType_t RoadType;
    EM_ROAD_V1::LegacyRoad_t Legacy;
  } Road_t;
}

class CConvRoad : public CSimConverterBase
{
  
  // the list of dependency names used inside by the converter
  /*
  static const char* DEP_NAMES[];
  */

  // here we define the index of each dependency for quick acces
  // the order here should match with the order from DEP_NAMES array
  enum eDepIdx
  {
    // add new dependencies here 
    DEP_COUNT
  };

  EM_ROAD_V0::Road_t m_RoadV0;
  EM_ROAD_V1::Road_t m_RoadV1;
  EM_ROAD_GenAll::Road_t m_BufGen;

  void InitV0(EM_ROAD_V0::Road_t & Dest);
  void InitV1(EM_ROAD_V1::Road_t & Dest);
  void InitGen(EM_ROAD_GenAll::Road_t & Dest, unsigned long VersionNumber);

public:

  static const char* GetConverterTypeName()
  {
    return "Init_Road";
  }

  CConvRoad(void);
  virtual ~CConvRoad(void);

  const char* GetTypeName()
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
    SimPortDataTypes_t eRPortType, unsigned long ulRPortSize, const IVersionInfo& requestPortVersionInfo, 
    SimPortDataTypes_t ePPortType, unsigned long ulPPortSize, const IVersionInfo* pProvidePortVersionInfo, 
    void* pPPortData,
    void** pOutData, unsigned long& ulOutSize);
  
  /** returns: 
   *   SIM_ERR_OK - when this value can be used
   *   SIM_ERR_USE_DEFAULT_VALUE_FROM_RPORT - when the default vaule is not implemented here
   *                                            and the default value from Request Port must be used
   */
  long GetDefaultValue(
    SimPortDataTypes_t eRPortType, unsigned long ulRPortSize, const IVersionInfo& requestPortVersionInfo, 
    void** pDefaultData, unsigned long& ulDefaultSize);

protected:

  // used to check if an unversioned PPort is compatible with a certain version of RPort
  bool IsVersionCompatibleWithType(
    SimPortDataTypes_t eRPortType, unsigned long ulRPortSize, const IVersionInfo& requestPortVersionInfo, 
    SimPortDataTypes_t ePPortType, unsigned long ulPPortSize);

  // used to check if ports are compatible between different versions
  bool AreVersionsCompatible(
    SimPortDataTypes_t eRPortType, unsigned long ulRPortSize, const IVersionInfo& requestPortVersionInfo,
    SimPortDataTypes_t ePPortType, unsigned long ulPPortSize, const IVersionInfo& providePortVersionInfo);

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
    for (int nI = 0; nI < EM_ROAD_VERSION_COUNT; nI++)
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
private:
  static void Convert_V0_to_Gen(EM_ROAD_GenAll::Road_t & Dest, const EM_ROAD_V0::Road_t & Src);
  static void Convert_V1_to_Gen(EM_ROAD_GenAll::Road_t & Dest, const EM_ROAD_V1::Road_t & Src);
  static void Convert_Gen_to_V0(EM_ROAD_V0::Road_t & Dest, const EM_ROAD_GenAll::Road_t & Src);
  static void Convert_Gen_to_V1(EM_ROAD_V1::Road_t & Dest, const EM_ROAD_GenAll::Road_t & Src);

  static CVersionInfoImpl BASE_VERSION;
  static CVersionInfoImpl VERSION0;
  static CVersionInfoImpl VERSION1;

  enum eRoadVersions
  {
    EM_ROAD_GenAll,
    EM_ROAD_V0,
    EM_ROAD_V1,
    EM_ROAD_VERSION_COUNT
  };
  static unsigned long SUPPORTED_SIZE[EM_ROAD_VERSION_COUNT];
  static const CVersionInfoImpl * const VERSION_NUMBERS[CConvRoad::EM_ROAD_VERSION_COUNT];
};

CVersionInfoImpl  CConvRoad::BASE_VERSION(0, 0, 0);
CVersionInfoImpl  CConvRoad::VERSION0(0, 0, 0);
CVersionInfoImpl  CConvRoad::VERSION1(0, 0, 1);

unsigned long CConvRoad::SUPPORTED_SIZE[CConvRoad::EM_ROAD_VERSION_COUNT]=
{
  sizeof(EM_ROAD_GenAll::Road_t),
  sizeof(EM_ROAD_V0::Road_t),
  sizeof(EM_ROAD_V1::Road_t),
};

const CVersionInfoImpl * const CConvRoad::VERSION_NUMBERS[CConvRoad::EM_ROAD_VERSION_COUNT] =
{
  &BASE_VERSION,
  &VERSION0,
  &VERSION1,
};

CConvRoad::CConvRoad(void)
: CSimConverterBase(NULL/*DEP_NAMES*/, DEP_COUNT), m_RoadV1()//, m_RoadV2()
{
  InitGen(m_BufGen, 0);
  InitV0(m_RoadV0);
  InitV1(m_RoadV1);
}

CConvRoad::~CConvRoad(void)
{
}

void CConvRoad::InitV0(EM_ROAD_V0::Road_t & Dest)
{
  memset(&Dest, 0, sizeof(Dest));
  Dest.uiVersionNumber  = 0;
}

void CConvRoad::InitV1(EM_ROAD_V1::Road_t & Dest)
{
  memset(&Dest, 0, sizeof(Dest));
  Dest.uiVersionNumber  = 1;
}

void CConvRoad::InitGen(EM_ROAD_GenAll::Road_t & Dest, unsigned long VersionNumber)
{
  memset(&Dest, 0, sizeof(Dest));
  Dest.uiVersionNumber  = VersionNumber;
}

void CConvRoad::Convert_V0_to_Gen(EM_ROAD_GenAll::Road_t & Dest, const EM_ROAD_V0::Road_t & Src)
{
  Dest.uiVersionNumber = Src.uiVersionNumber;

  Dest.sSigHeader.eSigStatus = Src.sSigHeader.eSigStatus;
  Dest.sSigHeader.uiCycleCounter = Src.sSigHeader.uiCycleCounter;
  Dest.sSigHeader.uiMeasurementCounter = Src.sSigHeader.uiMeasurementCounter;
  Dest.sSigHeader.uiTimeStamp = Src.sSigHeader.uiTimeStamp;

  Dest.RoadType.eRoadTypeClass = Src.RoadType.eRoadTypeClass;
  Dest.RoadType.eRoadWorksClass = Src.RoadType.eRoadWorksClass;
  Dest.RoadType.fRoadTypeClassConf = Src.RoadType.fRoadTypeClassConf;
  Dest.RoadType.fRoadWorksClassConf = Src.RoadType.fRoadWorksClassConf;

  Dest.LaneWidth.eLaneWidthClass = Src.LaneWidth.eLaneWidthClass;
  Dest.LaneWidth.eLaneWidthSource = Src.LaneWidth.eLaneWidthSource;
  Dest.LaneWidth.fLaneWidth = Src.LaneWidth.fLaneWidth;

  Dest.LaneMatrix.iNumOfLaneLeft = Src.LaneMatrix.iNumOfLaneLeft;
  Dest.LaneMatrix.iNumOfLaneRight = Src.LaneMatrix.iNumOfLaneRight;
  Dest.LaneMatrix.Legacy.NoLaneProbLeft = Src.LaneMatrix.NoLaneProbLeft;
  Dest.LaneMatrix.Legacy.NoLaneProbRight = Src.LaneMatrix.NoLaneProbRight;

  Dest.RoadEstimation.CoupledRoad.ClothoidParams.f_ClothoidParam1 = Src.RoadEstimation.CoupledRoad.ClothoidParams.f_ClothoidParam1;
  Dest.RoadEstimation.CoupledRoad.ClothoidParams.f_ClothoidParam2 = Src.RoadEstimation.CoupledRoad.ClothoidParams.f_ClothoidParam2;
  Dest.RoadEstimation.CoupledRoad.ClothoidParams.f_Curvature = Src.RoadEstimation.CoupledRoad.ClothoidParams.f_Curvature;
  Dest.RoadEstimation.CoupledRoad.ClothoidParams.f_TransitionPoint = Src.RoadEstimation.CoupledRoad.ClothoidParams.f_TransitionPoint;
  Dest.RoadEstimation.CoupledRoad.ClothoidParams.f_YawAngle = Src.RoadEstimation.CoupledRoad.ClothoidParams.f_YawAngle;
  Dest.RoadEstimation.CoupledRoad.f_LateralOffsetLeft = Src.RoadEstimation.CoupledRoad.f_LateralOffsetLeft;
  Dest.RoadEstimation.CoupledRoad.f_LateralOffsetRight = Src.RoadEstimation.CoupledRoad.f_LateralOffsetRight;
  Dest.RoadEstimation.CoupledRoad.f_LatStdDevFiltered = Src.RoadEstimation.CoupledRoad.f_LatStdDevFiltered;
  Dest.RoadEstimation.CoupledRoad.QualityMeasLeft.e_BorderType = Src.RoadEstimation.CoupledRoad.QualityMeasLeft.e_BorderType;
  Dest.RoadEstimation.CoupledRoad.QualityMeasLeft.f_Confidence = Src.RoadEstimation.CoupledRoad.QualityMeasLeft.f_Confidence;
  Dest.RoadEstimation.CoupledRoad.QualityMeasLeft.f_MaxX = Src.RoadEstimation.CoupledRoad.QualityMeasLeft.f_MaxX;
  Dest.RoadEstimation.CoupledRoad.QualityMeasLeft.f_MaxXCompensated = Src.RoadEstimation.CoupledRoad.QualityMeasLeft.f_MaxXCompensated;
  Dest.RoadEstimation.CoupledRoad.QualityMeasLeft.f_MinX = Src.RoadEstimation.CoupledRoad.QualityMeasLeft.f_MinX;
  Dest.RoadEstimation.CoupledRoad.QualityMeasLeft.u_TrackingStatus = Src.RoadEstimation.CoupledRoad.QualityMeasLeft.u_TrackingStatus;
  Dest.RoadEstimation.CoupledRoad.QualityMeasRight.e_BorderType = Src.RoadEstimation.CoupledRoad.QualityMeasRight.e_BorderType;
  Dest.RoadEstimation.CoupledRoad.QualityMeasRight.f_Confidence = Src.RoadEstimation.CoupledRoad.QualityMeasRight.f_Confidence;
  Dest.RoadEstimation.CoupledRoad.QualityMeasRight.f_MaxX = Src.RoadEstimation.CoupledRoad.QualityMeasRight.f_MaxX;
  Dest.RoadEstimation.CoupledRoad.QualityMeasRight.f_MaxXCompensated = Src.RoadEstimation.CoupledRoad.QualityMeasRight.f_MaxXCompensated;
  Dest.RoadEstimation.CoupledRoad.QualityMeasRight.f_MinX = Src.RoadEstimation.CoupledRoad.QualityMeasRight.f_MinX;
  Dest.RoadEstimation.CoupledRoad.QualityMeasRight.u_TrackingStatus = Src.RoadEstimation.CoupledRoad.QualityMeasRight.u_TrackingStatus;
  Dest.RoadEstimation.CoupledRoad.u_GlobalConfidence = Src.RoadEstimation.CoupledRoad.u_GlobalConfidence;
  Dest.RoadEstimation.CoupledRoad.u_GlobalTrackingStatus = Src.RoadEstimation.CoupledRoad.u_GlobalTrackingStatus;
  Dest.RoadEstimation.RoadBorderLeft.ClothoidParams.f_ClothoidParam1 = Src.RoadEstimation.RoadBorderLeft.ClothoidParams.f_ClothoidParam1;
  Dest.RoadEstimation.RoadBorderLeft.ClothoidParams.f_ClothoidParam2 = Src.RoadEstimation.RoadBorderLeft.ClothoidParams.f_ClothoidParam2;
  Dest.RoadEstimation.RoadBorderLeft.ClothoidParams.f_Curvature = Src.RoadEstimation.RoadBorderLeft.ClothoidParams.f_Curvature;
  Dest.RoadEstimation.RoadBorderLeft.ClothoidParams.f_TransitionPoint = Src.RoadEstimation.RoadBorderLeft.ClothoidParams.f_TransitionPoint;
  Dest.RoadEstimation.RoadBorderLeft.ClothoidParams.f_YawAngle = Src.RoadEstimation.RoadBorderLeft.ClothoidParams.f_YawAngle;
  Dest.RoadEstimation.RoadBorderLeft.f_LateralOffset = Src.RoadEstimation.RoadBorderLeft.f_LateralOffset;
  Dest.RoadEstimation.RoadBorderLeft.f_LatStdDevFiltered = Src.RoadEstimation.RoadBorderLeft.f_LatStdDevFiltered;
  Dest.RoadEstimation.RoadBorderLeft.QualityMeas.e_BorderType = Src.RoadEstimation.RoadBorderLeft.QualityMeas.e_BorderType;
  Dest.RoadEstimation.RoadBorderLeft.QualityMeas.f_Confidence = Src.RoadEstimation.RoadBorderLeft.QualityMeas.f_Confidence;
  Dest.RoadEstimation.RoadBorderLeft.QualityMeas.f_MaxX = Src.RoadEstimation.RoadBorderLeft.QualityMeas.f_MaxX;
  Dest.RoadEstimation.RoadBorderLeft.QualityMeas.f_MaxXCompensated = Src.RoadEstimation.RoadBorderLeft.QualityMeas.f_MaxXCompensated;
  Dest.RoadEstimation.RoadBorderLeft.QualityMeas.f_MinX = Src.RoadEstimation.RoadBorderLeft.QualityMeas.f_MinX;
  Dest.RoadEstimation.RoadBorderLeft.QualityMeas.u_TrackingStatus = Src.RoadEstimation.RoadBorderLeft.QualityMeas.u_TrackingStatus;
  Dest.RoadEstimation.RoadBorderRight.ClothoidParams.f_ClothoidParam1 = Src.RoadEstimation.RoadBorderRight.ClothoidParams.f_ClothoidParam1;
  Dest.RoadEstimation.RoadBorderRight.ClothoidParams.f_ClothoidParam2 = Src.RoadEstimation.RoadBorderRight.ClothoidParams.f_ClothoidParam2;
  Dest.RoadEstimation.RoadBorderRight.ClothoidParams.f_Curvature = Src.RoadEstimation.RoadBorderRight.ClothoidParams.f_Curvature;
  Dest.RoadEstimation.RoadBorderRight.ClothoidParams.f_TransitionPoint = Src.RoadEstimation.RoadBorderRight.ClothoidParams.f_TransitionPoint;
  Dest.RoadEstimation.RoadBorderRight.ClothoidParams.f_YawAngle = Src.RoadEstimation.RoadBorderRight.ClothoidParams.f_YawAngle;
  Dest.RoadEstimation.RoadBorderRight.f_LateralOffset = Src.RoadEstimation.RoadBorderRight.f_LateralOffset;
  Dest.RoadEstimation.RoadBorderRight.f_LatStdDevFiltered = Src.RoadEstimation.RoadBorderRight.f_LatStdDevFiltered;
  Dest.RoadEstimation.RoadBorderRight.QualityMeas.e_BorderType = Src.RoadEstimation.RoadBorderRight.QualityMeas.e_BorderType;
  Dest.RoadEstimation.RoadBorderRight.QualityMeas.f_Confidence = Src.RoadEstimation.RoadBorderRight.QualityMeas.f_Confidence;
  Dest.RoadEstimation.RoadBorderRight.QualityMeas.f_MaxX = Src.RoadEstimation.RoadBorderRight.QualityMeas.f_MaxX;
  Dest.RoadEstimation.RoadBorderRight.QualityMeas.f_MaxXCompensated = Src.RoadEstimation.RoadBorderRight.QualityMeas.f_MaxXCompensated;
  Dest.RoadEstimation.RoadBorderRight.QualityMeas.f_MinX = Src.RoadEstimation.RoadBorderRight.QualityMeas.f_MinX;
  Dest.RoadEstimation.RoadBorderRight.QualityMeas.u_TrackingStatus = Src.RoadEstimation.RoadBorderRight.QualityMeas.u_TrackingStatus;

  Dest.FusedRoadBorder.bStatusLeft = Src.FusedRoadBorder.bStatusLeft;
  Dest.FusedRoadBorder.bStatusRight = Src.FusedRoadBorder.bStatusRight;
  Dest.FusedRoadBorder.fDistLeft = Src.FusedRoadBorder.fDistLeft;
  Dest.FusedRoadBorder.fDistLeftStd = Src.FusedRoadBorder.fDistLeftStd;
  Dest.FusedRoadBorder.fDistRight = Src.FusedRoadBorder.fDistRight;
  Dest.FusedRoadBorder.fDistRightStd = Src.FusedRoadBorder.fDistRightStd;

  Dest.Traffic.eTrafficOrientation = Src.Traffic.eTrafficOrientation;
  Dest.Traffic.bWriteToNVM = Src.Traffic.bWriteToNVM;
  Dest.Traffic.fTimeToNextWriteAllowed = Src.Traffic.fTimeToNextWriteAllowed;
}

void CConvRoad::Convert_V1_to_Gen(EM_ROAD_GenAll::Road_t & Dest, const EM_ROAD_V1::Road_t & Src)
{
  Dest.uiVersionNumber = Src.uiVersionNumber;

  Dest.sSigHeader.eSigStatus = Src.sSigHeader.eSigStatus;
  Dest.sSigHeader.uiCycleCounter = Src.sSigHeader.uiCycleCounter;
  Dest.sSigHeader.uiMeasurementCounter = Src.sSigHeader.uiMeasurementCounter;
  Dest.sSigHeader.uiTimeStamp = Src.sSigHeader.uiTimeStamp;

  Dest.RoadType.eRoadType = Src.RoadType.eRoadType;

  Dest.LaneWidth.eLaneWidthClass = Src.LaneWidth.eLaneWidthClass;
  Dest.LaneWidth.eLaneWidthSource = Src.LaneWidth.eLaneWidthSource;
  Dest.LaneWidth.fLaneWidth = Src.LaneWidth.fLaneWidth;

  Dest.Roadworks = Src.Roadworks;

  Dest.LaneMatrix.iNumOfLaneLeft = Src.LaneMatrix.iNumOfLaneLeft;
  Dest.LaneMatrix.iNumOfLaneRight = Src.LaneMatrix.iNumOfLaneRight;
  Dest.LaneMatrix.Legacy.NoLaneProbLeft = Src.LaneMatrix.Legacy.NoLaneProbLeft;
  Dest.LaneMatrix.Legacy.NoLaneProbRight = Src.LaneMatrix.Legacy.NoLaneProbRight;

  Dest.RoadEstimation.fC0 = Src.RoadEstimation.fC0;
  Dest.RoadEstimation.fC1 = Src.RoadEstimation.fC1;
  Dest.RoadEstimation.fConfLeft = Src.RoadEstimation.fConfLeft;
  Dest.RoadEstimation.fConfRight = Src.RoadEstimation.fConfRight;
  Dest.RoadEstimation.fLateralVarianceMax = Src.RoadEstimation.fLateralVarianceMax;
  Dest.RoadEstimation.fRangeMaxLeft = Src.RoadEstimation.fRangeMaxLeft;
  Dest.RoadEstimation.fRangeMaxRight = Src.RoadEstimation.fRangeMaxRight;
  Dest.RoadEstimation.fYawAngle = Src.RoadEstimation.fYawAngle;
  Dest.RoadEstimation.Legacy.fYLeft = Src.RoadEstimation.Legacy.fYLeft;
  Dest.RoadEstimation.Legacy.fYRight = Src.RoadEstimation.Legacy.fYRight;
  Dest.RoadEstimation.Legacy.uiConfidence = Src.RoadEstimation.Legacy.uiConfidence;
  Dest.RoadEstimation.Legacy.uiTrackingStatus = Src.RoadEstimation.Legacy.uiTrackingStatus;
  Dest.RoadEstimation.Legacy.uiTrackingStatusLeft = Src.RoadEstimation.Legacy.uiTrackingStatusLeft;
  Dest.RoadEstimation.Legacy.uiTrackingStatusRight = Src.RoadEstimation.Legacy.uiTrackingStatusRight;

  Dest.FusedRoadBorder.bStatusLeft = Src.FusedRoadBorder.bStatusLeft;
  Dest.FusedRoadBorder.bStatusRight = Src.FusedRoadBorder.bStatusRight;
  Dest.FusedRoadBorder.fDistLeft = Src.FusedRoadBorder.fDistLeft;
  Dest.FusedRoadBorder.fDistLeftStd = Src.FusedRoadBorder.fDistLeftStd;
  Dest.FusedRoadBorder.fDistRight = Src.FusedRoadBorder.fDistRight;
  Dest.FusedRoadBorder.fDistRightStd = Src.FusedRoadBorder.fDistRightStd;

  Dest.LaneChange.left = Src.LaneChange.left;
  Dest.LaneChange.right = Src.LaneChange.right;

  Dest.Traffic.eTrafficOrientation = Src.Traffic.eTrafficOrientation;
  Dest.Traffic.Legacy.bWriteToNVM = Src.Traffic.Legacy.bWriteToNVM;
  Dest.Traffic.Legacy.fTimeToNextWriteAllowed = Src.Traffic.Legacy.fTimeToNextWriteAllowed;
  Dest.Traffic.TrafficDensity = Src.Traffic.TrafficDensity;

  Dest.Legacy.RoadIntData.fConfidenceLeft = Src.Legacy.RoadIntData.fConfidenceLeft;
  Dest.Legacy.RoadIntData.fConfidenceRight = Src.Legacy.RoadIntData.fConfidenceRight;
  Dest.Legacy.RoadIntData.fLatStdDevFiltered = Src.Legacy.RoadIntData.fLatStdDevFiltered;
  Dest.Legacy.RoadIntData.fmaxXLeftCompensated = Src.Legacy.RoadIntData.fmaxXLeftCompensated;
  Dest.Legacy.RoadIntData.fmaxXRightCompensated = Src.Legacy.RoadIntData.fmaxXRightCompensated;
  Dest.Legacy.RoadIntData.fminXLeft = Src.Legacy.RoadIntData.fminXLeft;
  Dest.Legacy.RoadIntData.fminXRight = Src.Legacy.RoadIntData.fminXRight;
  Dest.Legacy.RoadTypeClass.eRoadTypeLevel1 = Src.Legacy.RoadTypeClass.eRoadTypeLevel1;
  Dest.Legacy.RoadTypeClass.eRoadTypeLevel2 = Src.Legacy.RoadTypeClass.eRoadTypeLevel2;
  Dest.Legacy.RoadTypeClass.fRoadConfLevel1 = Src.Legacy.RoadTypeClass.fRoadConfLevel1;
  Dest.Legacy.RoadTypeClass.fRoadConfLevel2 = Src.Legacy.RoadTypeClass.fRoadConfLevel2;
}

void CConvRoad::Convert_Gen_to_V0(EM_ROAD_V0::Road_t & Dest, const EM_ROAD_GenAll::Road_t & Src)
{
  Dest.uiVersionNumber = 0;

  Dest.sSigHeader.eSigStatus = Src.sSigHeader.eSigStatus;
  Dest.sSigHeader.uiCycleCounter = Src.sSigHeader.uiCycleCounter;
  Dest.sSigHeader.uiMeasurementCounter = Src.sSigHeader.uiMeasurementCounter;
  Dest.sSigHeader.uiTimeStamp = Src.sSigHeader.uiTimeStamp;

  Dest.LaneWidth.eLaneWidthClass = Src.LaneWidth.eLaneWidthClass;
  Dest.LaneWidth.eLaneWidthSource = Src.LaneWidth.eLaneWidthSource;
  Dest.LaneWidth.fLaneWidth = Src.LaneWidth.fLaneWidth;

  Dest.LaneMatrix.iNumOfLaneLeft = Src.LaneMatrix.iNumOfLaneLeft;
  Dest.LaneMatrix.iNumOfLaneRight = Src.LaneMatrix.iNumOfLaneRight;
  Dest.LaneMatrix.NoLaneProbLeft = Src.LaneMatrix.Legacy.NoLaneProbLeft;
  Dest.LaneMatrix.NoLaneProbRight = Src.LaneMatrix.Legacy.NoLaneProbRight;

  Dest.RoadEstimation.CoupledRoad.ClothoidParams.f_ClothoidParam1 = Src.RoadEstimation.CoupledRoad.ClothoidParams.f_ClothoidParam1;
  Dest.RoadEstimation.CoupledRoad.ClothoidParams.f_ClothoidParam2 = Src.RoadEstimation.CoupledRoad.ClothoidParams.f_ClothoidParam2;
  Dest.RoadEstimation.CoupledRoad.ClothoidParams.f_Curvature = Src.RoadEstimation.CoupledRoad.ClothoidParams.f_Curvature;
  Dest.RoadEstimation.CoupledRoad.ClothoidParams.f_TransitionPoint = Src.RoadEstimation.CoupledRoad.ClothoidParams.f_TransitionPoint;
  Dest.RoadEstimation.CoupledRoad.ClothoidParams.f_YawAngle = Src.RoadEstimation.CoupledRoad.ClothoidParams.f_YawAngle;
  Dest.RoadEstimation.CoupledRoad.f_LateralOffsetLeft = Src.RoadEstimation.CoupledRoad.f_LateralOffsetLeft;
  Dest.RoadEstimation.CoupledRoad.f_LateralOffsetRight = Src.RoadEstimation.CoupledRoad.f_LateralOffsetRight;
  Dest.RoadEstimation.CoupledRoad.f_LatStdDevFiltered = Src.RoadEstimation.CoupledRoad.f_LatStdDevFiltered;
  Dest.RoadEstimation.CoupledRoad.QualityMeasLeft.e_BorderType = Src.RoadEstimation.CoupledRoad.QualityMeasLeft.e_BorderType;
  Dest.RoadEstimation.CoupledRoad.QualityMeasLeft.f_Confidence = Src.RoadEstimation.CoupledRoad.QualityMeasLeft.f_Confidence;
  Dest.RoadEstimation.CoupledRoad.QualityMeasLeft.f_MaxX = Src.RoadEstimation.CoupledRoad.QualityMeasLeft.f_MaxX;
  Dest.RoadEstimation.CoupledRoad.QualityMeasLeft.f_MaxXCompensated = Src.RoadEstimation.CoupledRoad.QualityMeasLeft.f_MaxXCompensated;
  Dest.RoadEstimation.CoupledRoad.QualityMeasLeft.f_MinX = Src.RoadEstimation.CoupledRoad.QualityMeasLeft.f_MinX;
  Dest.RoadEstimation.CoupledRoad.QualityMeasLeft.u_TrackingStatus = Src.RoadEstimation.CoupledRoad.QualityMeasLeft.u_TrackingStatus;
  Dest.RoadEstimation.CoupledRoad.QualityMeasRight.e_BorderType = Src.RoadEstimation.CoupledRoad.QualityMeasRight.e_BorderType;
  Dest.RoadEstimation.CoupledRoad.QualityMeasRight.f_Confidence = Src.RoadEstimation.CoupledRoad.QualityMeasRight.f_Confidence;
  Dest.RoadEstimation.CoupledRoad.QualityMeasRight.f_MaxX = Src.RoadEstimation.CoupledRoad.QualityMeasRight.f_MaxX;
  Dest.RoadEstimation.CoupledRoad.QualityMeasRight.f_MaxXCompensated = Src.RoadEstimation.CoupledRoad.QualityMeasRight.f_MaxXCompensated;
  Dest.RoadEstimation.CoupledRoad.QualityMeasRight.f_MinX = Src.RoadEstimation.CoupledRoad.QualityMeasRight.f_MinX;
  Dest.RoadEstimation.CoupledRoad.QualityMeasRight.u_TrackingStatus = Src.RoadEstimation.CoupledRoad.QualityMeasRight.u_TrackingStatus;
  Dest.RoadEstimation.CoupledRoad.u_GlobalConfidence = Src.RoadEstimation.CoupledRoad.u_GlobalConfidence;
  Dest.RoadEstimation.CoupledRoad.u_GlobalTrackingStatus = Src.RoadEstimation.CoupledRoad.u_GlobalTrackingStatus;
  Dest.RoadEstimation.RoadBorderLeft.ClothoidParams.f_ClothoidParam1 = Src.RoadEstimation.RoadBorderLeft.ClothoidParams.f_ClothoidParam1;
  Dest.RoadEstimation.RoadBorderLeft.ClothoidParams.f_ClothoidParam2 = Src.RoadEstimation.RoadBorderLeft.ClothoidParams.f_ClothoidParam2;
  Dest.RoadEstimation.RoadBorderLeft.ClothoidParams.f_Curvature = Src.RoadEstimation.RoadBorderLeft.ClothoidParams.f_Curvature;
  Dest.RoadEstimation.RoadBorderLeft.ClothoidParams.f_TransitionPoint = Src.RoadEstimation.RoadBorderLeft.ClothoidParams.f_TransitionPoint;
  Dest.RoadEstimation.RoadBorderLeft.ClothoidParams.f_YawAngle = Src.RoadEstimation.RoadBorderLeft.ClothoidParams.f_YawAngle;
  Dest.RoadEstimation.RoadBorderLeft.f_LateralOffset = Src.RoadEstimation.RoadBorderLeft.f_LateralOffset;
  Dest.RoadEstimation.RoadBorderLeft.f_LatStdDevFiltered = Src.RoadEstimation.RoadBorderLeft.f_LatStdDevFiltered;
  Dest.RoadEstimation.RoadBorderLeft.QualityMeas.e_BorderType = Src.RoadEstimation.RoadBorderLeft.QualityMeas.e_BorderType;
  Dest.RoadEstimation.RoadBorderLeft.QualityMeas.f_Confidence = Src.RoadEstimation.RoadBorderLeft.QualityMeas.f_Confidence;
  Dest.RoadEstimation.RoadBorderLeft.QualityMeas.f_MaxX = Src.RoadEstimation.RoadBorderLeft.QualityMeas.f_MaxX;
  Dest.RoadEstimation.RoadBorderLeft.QualityMeas.f_MaxXCompensated = Src.RoadEstimation.RoadBorderLeft.QualityMeas.f_MaxXCompensated;
  Dest.RoadEstimation.RoadBorderLeft.QualityMeas.f_MinX = Src.RoadEstimation.RoadBorderLeft.QualityMeas.f_MinX;
  Dest.RoadEstimation.RoadBorderLeft.QualityMeas.u_TrackingStatus = Src.RoadEstimation.RoadBorderLeft.QualityMeas.u_TrackingStatus;
  Dest.RoadEstimation.RoadBorderRight.ClothoidParams.f_ClothoidParam1 = Src.RoadEstimation.RoadBorderRight.ClothoidParams.f_ClothoidParam1;
  Dest.RoadEstimation.RoadBorderRight.ClothoidParams.f_ClothoidParam2 = Src.RoadEstimation.RoadBorderRight.ClothoidParams.f_ClothoidParam2;
  Dest.RoadEstimation.RoadBorderRight.ClothoidParams.f_Curvature = Src.RoadEstimation.RoadBorderRight.ClothoidParams.f_Curvature;
  Dest.RoadEstimation.RoadBorderRight.ClothoidParams.f_TransitionPoint = Src.RoadEstimation.RoadBorderRight.ClothoidParams.f_TransitionPoint;
  Dest.RoadEstimation.RoadBorderRight.ClothoidParams.f_YawAngle = Src.RoadEstimation.RoadBorderRight.ClothoidParams.f_YawAngle;
  Dest.RoadEstimation.RoadBorderRight.f_LateralOffset = Src.RoadEstimation.RoadBorderRight.f_LateralOffset;
  Dest.RoadEstimation.RoadBorderRight.f_LatStdDevFiltered = Src.RoadEstimation.RoadBorderRight.f_LatStdDevFiltered;
  Dest.RoadEstimation.RoadBorderRight.QualityMeas.e_BorderType = Src.RoadEstimation.RoadBorderRight.QualityMeas.e_BorderType;
  Dest.RoadEstimation.RoadBorderRight.QualityMeas.f_Confidence = Src.RoadEstimation.RoadBorderRight.QualityMeas.f_Confidence;
  Dest.RoadEstimation.RoadBorderRight.QualityMeas.f_MaxX = Src.RoadEstimation.RoadBorderRight.QualityMeas.f_MaxX;
  Dest.RoadEstimation.RoadBorderRight.QualityMeas.f_MaxXCompensated = Src.RoadEstimation.RoadBorderRight.QualityMeas.f_MaxXCompensated;
  Dest.RoadEstimation.RoadBorderRight.QualityMeas.f_MinX = Src.RoadEstimation.RoadBorderRight.QualityMeas.f_MinX;
  Dest.RoadEstimation.RoadBorderRight.QualityMeas.u_TrackingStatus = Src.RoadEstimation.RoadBorderRight.QualityMeas.u_TrackingStatus;

  Dest.FusedRoadBorder.bStatusLeft = Src.FusedRoadBorder.bStatusLeft;
  Dest.FusedRoadBorder.bStatusRight = Src.FusedRoadBorder.bStatusRight;
  Dest.FusedRoadBorder.fDistLeft = Src.FusedRoadBorder.fDistLeft;
  Dest.FusedRoadBorder.fDistLeftStd = Src.FusedRoadBorder.fDistLeftStd;
  Dest.FusedRoadBorder.fDistRight = Src.FusedRoadBorder.fDistRight;
  Dest.FusedRoadBorder.fDistRightStd = Src.FusedRoadBorder.fDistRightStd;

  Dest.Traffic.eTrafficOrientation = Src.Traffic.eTrafficOrientation;
  Dest.Traffic.bWriteToNVM = Src.Traffic.Legacy.bWriteToNVM;
  Dest.Traffic.fTimeToNextWriteAllowed = Src.Traffic.Legacy.fTimeToNextWriteAllowed;

  Dest.RoadType.eRoadTypeClass = Src.RoadType.eRoadTypeClass;
  Dest.RoadType.eRoadWorksClass = Src.RoadType.eRoadWorksClass;
  Dest.RoadType.fRoadTypeClassConf = Src.RoadType.fRoadTypeClassConf;
  Dest.RoadType.fRoadWorksClassConf = Src.RoadType.fRoadWorksClassConf;
}

void CConvRoad::Convert_Gen_to_V1(EM_ROAD_V1::Road_t & Dest, const EM_ROAD_GenAll::Road_t & Src)
{
  Dest.uiVersionNumber = 1;

  Dest.sSigHeader.eSigStatus = Src.sSigHeader.eSigStatus;
  Dest.sSigHeader.uiCycleCounter = Src.sSigHeader.uiCycleCounter;
  Dest.sSigHeader.uiMeasurementCounter = Src.sSigHeader.uiMeasurementCounter;
  Dest.sSigHeader.uiTimeStamp = Src.sSigHeader.uiTimeStamp;

  Dest.RoadType.eRoadType = Src.RoadType.eRoadType;

  Dest.LaneWidth.eLaneWidthClass = Src.LaneWidth.eLaneWidthClass;
  Dest.LaneWidth.eLaneWidthSource = Src.LaneWidth.eLaneWidthSource;
  Dest.LaneWidth.fLaneWidth = Src.LaneWidth.fLaneWidth;

  Dest.Roadworks = Src.Roadworks;

  Dest.LaneMatrix.iNumOfLaneLeft = Src.LaneMatrix.iNumOfLaneLeft;
  Dest.LaneMatrix.iNumOfLaneRight = Src.LaneMatrix.iNumOfLaneRight;
  Dest.LaneMatrix.Legacy.NoLaneProbLeft = Src.LaneMatrix.Legacy.NoLaneProbLeft;
  Dest.LaneMatrix.Legacy.NoLaneProbRight = Src.LaneMatrix.Legacy.NoLaneProbRight;

  Dest.RoadEstimation.fC0 = Src.RoadEstimation.fC0;
  Dest.RoadEstimation.fC1 = Src.RoadEstimation.fC1;
  Dest.RoadEstimation.fConfLeft = Src.RoadEstimation.fConfLeft;
  Dest.RoadEstimation.fConfRight = Src.RoadEstimation.fConfRight;
  Dest.RoadEstimation.fLateralVarianceMax = Src.RoadEstimation.fLateralVarianceMax;
  Dest.RoadEstimation.fRangeMaxLeft = Src.RoadEstimation.fRangeMaxLeft;
  Dest.RoadEstimation.fRangeMaxRight = Src.RoadEstimation.fRangeMaxRight;
  Dest.RoadEstimation.fYawAngle = Src.RoadEstimation.fYawAngle;
  Dest.RoadEstimation.Legacy.fYLeft = Src.RoadEstimation.Legacy.fYLeft;
  Dest.RoadEstimation.Legacy.fYRight = Src.RoadEstimation.Legacy.fYRight;
  Dest.RoadEstimation.Legacy.uiConfidence = Src.RoadEstimation.Legacy.uiConfidence;
  Dest.RoadEstimation.Legacy.uiTrackingStatus = Src.RoadEstimation.Legacy.uiTrackingStatus;
  Dest.RoadEstimation.Legacy.uiTrackingStatusLeft = Src.RoadEstimation.Legacy.uiTrackingStatusLeft;
  Dest.RoadEstimation.Legacy.uiTrackingStatusRight = Src.RoadEstimation.Legacy.uiTrackingStatusRight;

  Dest.FusedRoadBorder.bStatusLeft = Src.FusedRoadBorder.bStatusLeft;
  Dest.FusedRoadBorder.bStatusRight = Src.FusedRoadBorder.bStatusRight;
  Dest.FusedRoadBorder.fDistLeft = Src.FusedRoadBorder.fDistLeft;
  Dest.FusedRoadBorder.fDistLeftStd = Src.FusedRoadBorder.fDistLeftStd;
  Dest.FusedRoadBorder.fDistRight = Src.FusedRoadBorder.fDistRight;
  Dest.FusedRoadBorder.fDistRightStd = Src.FusedRoadBorder.fDistRightStd;

  Dest.LaneChange.left = Src.LaneChange.left;
  Dest.LaneChange.right = Src.LaneChange.right;

  Dest.Traffic.eTrafficOrientation = Src.Traffic.eTrafficOrientation;
  Dest.Traffic.Legacy.bWriteToNVM = Src.Traffic.Legacy.bWriteToNVM;
  Dest.Traffic.Legacy.fTimeToNextWriteAllowed = Src.Traffic.Legacy.fTimeToNextWriteAllowed;
  Dest.Traffic.TrafficDensity = Src.Traffic.TrafficDensity;

  Dest.Legacy.RoadIntData.fConfidenceLeft = Src.Legacy.RoadIntData.fConfidenceLeft;
  Dest.Legacy.RoadIntData.fConfidenceRight = Src.Legacy.RoadIntData.fConfidenceRight;
  Dest.Legacy.RoadIntData.fLatStdDevFiltered = Src.Legacy.RoadIntData.fLatStdDevFiltered;
  Dest.Legacy.RoadIntData.fmaxXLeftCompensated = Src.Legacy.RoadIntData.fmaxXLeftCompensated;
  Dest.Legacy.RoadIntData.fmaxXRightCompensated = Src.Legacy.RoadIntData.fmaxXRightCompensated;
  Dest.Legacy.RoadIntData.fminXLeft = Src.Legacy.RoadIntData.fminXLeft;
  Dest.Legacy.RoadIntData.fminXRight = Src.Legacy.RoadIntData.fminXRight;
  Dest.Legacy.RoadTypeClass.eRoadTypeLevel1 = Src.Legacy.RoadTypeClass.eRoadTypeLevel1;
  Dest.Legacy.RoadTypeClass.eRoadTypeLevel2 = Src.Legacy.RoadTypeClass.eRoadTypeLevel2;
  Dest.Legacy.RoadTypeClass.fRoadConfLevel1 = Src.Legacy.RoadTypeClass.fRoadConfLevel1;
  Dest.Legacy.RoadTypeClass.fRoadConfLevel2 = Src.Legacy.RoadTypeClass.fRoadConfLevel2;
}

long CConvRoad::ConvertData(
    SimPortDataTypes_t eRPortType, unsigned long ulRPortSize, const IVersionInfo& requestPortVersionInfo, 
    SimPortDataTypes_t ePPortType, unsigned long ulPPortSize, const IVersionInfo* pProvidePortVersionInfo, 
    void* pPPortData,
    void** pOutData, unsigned long& ulOutSize)
{
  long lRet = SIM_ERR_UNADAPTABLE_DATA_PORTS;
  bool bGenBufferFilled = false;
  const uint32 uDataVer = ((pPPortData != NULL) && (ulPPortSize >= 4) && (ePPortType == simOPAQUE_t))?(*reinterpret_cast<uint32*>(pPPortData)):(0);
  // If ports equal, then always compatible
  if (eRPortType == ePPortType)
  {
    if (ulPPortSize == ulRPortSize)
    {
      lRet = SIM_ERR_USE_VALUE_FROM_PPORT;
    }
    // First decide from which version we are converting and fill the generic buffer accordingly
    else if ((ulPPortSize == SUPPORTED_SIZE[EM_ROAD_V1])
      && ((pProvidePortVersionInfo == NULL) || (pProvidePortVersionInfo->Equals(VERSION_NUMBERS[EM_ROAD_V1])) || (pProvidePortVersionInfo->Equals(&BASE_VERSION)))
      && (uDataVer == 1u))
    {
      // Source Port V1
      InitGen(m_BufGen, 1);
      const EM_ROAD_V1::Road_t & Src = *reinterpret_cast<EM_ROAD_V1::Road_t*>(pPPortData);
      Convert_V1_to_Gen(m_BufGen, Src);
      bGenBufferFilled = true;
    }
    else if ((ulPPortSize == SUPPORTED_SIZE[EM_ROAD_V0])
      && ((pProvidePortVersionInfo == NULL) || (pProvidePortVersionInfo->Equals(VERSION_NUMBERS[EM_ROAD_V0])) || (pProvidePortVersionInfo->Equals(&BASE_VERSION)))
      && (uDataVer == 0u))
    {
      // Source Port V0
      InitGen(m_BufGen, 0);
      const EM_ROAD_V0::Road_t & Src = *reinterpret_cast<EM_ROAD_V0::Road_t*>(pPPortData);
      Convert_V0_to_Gen(m_BufGen, Src);
      bGenBufferFilled = true;
    }
    if (bGenBufferFilled == true)
    {
      // Second decide to which version we are converting
      // and take the generic buffer to fill the destination buffer
      if ((ulRPortSize == SUPPORTED_SIZE[EM_ROAD_V1]) && (requestPortVersionInfo.Equals(VERSION_NUMBERS[EM_ROAD_V1])))
      {
        // Destination port of V1
        InitV1(m_RoadV1);
        Convert_Gen_to_V1(m_RoadV1, m_BufGen);
        *pOutData = &m_RoadV1;
        ulOutSize = sizeof(m_RoadV1);
        lRet = SIM_ERR_OK;
      }
      else 
      if ((ulRPortSize == SUPPORTED_SIZE[EM_ROAD_V0]) && (requestPortVersionInfo.Equals(VERSION_NUMBERS[EM_ROAD_V0])))
      {
        // Destination port of V0
        InitV0(m_RoadV0);
        Convert_Gen_to_V0(m_RoadV0, m_BufGen);
        *pOutData = &m_RoadV0;
        ulOutSize = sizeof(m_RoadV0);
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
long CConvRoad::GetDefaultValue(
    SimPortDataTypes_t eRPortType, unsigned long ulRPortSize, const IVersionInfo& requestPortVersionInfo, 
    void** pDefaultData, unsigned long& ulDefaultSize)
{
  long lRet = SIM_ERR_USE_DEFAULT_VALUE_FROM_RPORT;
  if (eRPortType == simOPAQUE_t)
  {
    if ((ulRPortSize == sizeof(EM_ROAD_V1::Road_t)) &&
      ((requestPortVersionInfo.Equals(&VERSION1)) || (requestPortVersionInfo.Equals(&BASE_VERSION))))
    {
      InitV1(m_RoadV1);
      *pDefaultData = &m_RoadV1;
      ulDefaultSize = sizeof(m_RoadV1);
      lRet = SIM_ERR_OK;
    }
    else if ((ulRPortSize == sizeof(EM_ROAD_V0::Road_t)) &&
      ((requestPortVersionInfo.Equals(&VERSION0)) || (requestPortVersionInfo.Equals(&BASE_VERSION))))
    {
      InitV0(m_RoadV0);
      *pDefaultData = &m_RoadV0;
      ulDefaultSize = sizeof(m_RoadV0);
      lRet = SIM_ERR_OK;
    }
    else
    {
      //No default value(s) available
    }
  }
  return lRet;
}

// used to check if an unversioned PPort is compatible with a certain version of RPort
bool CConvRoad::IsVersionCompatibleWithType(
    SimPortDataTypes_t eRPortType, unsigned long ulRPortSize, const IVersionInfo& requestPortVersionInfo, 
    SimPortDataTypes_t ePPortType, unsigned long ulPPortSize)
{
  bool bResult = false;
  // Equal ports are always compatible (at least assumed to be)
  if ((ulRPortSize == ulPPortSize) &&(ePPortType == eRPortType))
  {
    bResult = true;
  }
  else
  {
    if ((IsPortSupported(ulRPortSize, &requestPortVersionInfo)) && (IsPortSupported(ulPPortSize, NULL)))
    {
      bResult = true;
    }
  }
  return bResult;
}

// used to check if ports are compatible between different versions
bool CConvRoad::AreVersionsCompatible(
  SimPortDataTypes_t eRPortType, unsigned long ulRPortSize, const IVersionInfo& requestPortVersionInfo,
  SimPortDataTypes_t ePPortType, unsigned long ulPPortSize, const IVersionInfo& providePortVersionInfo)
{
  bool bResult = false;
  // Ports with same type/size/version are always compatible
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

IConverter * CreateRoadConvInstance(void)
{
  return new CConvRoad();
}
