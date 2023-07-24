/*! \file **********************************************************************

  TEMPLATE VERSION:          1.2
                             changed parameters in cpp version to be a struct/class
                             added version management for template

*/
#ifndef sim_swc_lcf_vis_h__
#define sim_swc_lcf_vis_h__

#include <vis_gl.h>
#include "sim_swc_base.h"
#include "sim_swc_draw_base.h"
#include "sim_versioninfo_impl.h"
#include "simReceivePort.h"
#include "sim_swc_gdv_ifc.h"
#include "sim_gdvfont_ifc.h"
#include "sim_swc_img.h"
#include "algo_glob.h"
#include <map>
#include "renderContextMap.h"
#include <queue>

//LCF types headers
#include "lcf_sen_ext.h"
#include "lcf_veh_ext.h"
#include "LCF_type.h"
#include "lcf_sen_iface.h"
#include "lcf_veh_iface.h"
#include "lcf_ver.h"

//GeGr: Fix incompatibilities with new code
#ifndef E_LCF_LKA_nu
#define E_LCF_LKA_nu 8
#endif
#ifndef SizeStatisticalArray
#define SizeStatisticalArray 5
#endif
#define   PV_DEBUG_OUTPUT_DATA_INTFVER 1

#ifndef ABD_AnyBndRoadWorks_btf
#define ABD_AnyBndRoadWorks_btf     (uint8)(((m_AbdOutputData.sConstructionSite.CS_MULTIPLE_MARKER) << 0)| \
                                             ((m_AbdOutputData.sConstructionSite.CS_LEFT_BARRIER) << 1) |\
                                             ((m_AbdOutputData.sConstructionSite.CS_RIGHT_BARRIER) << 2)|\
                                             ((m_AbdOutputData.sConstructionSite.CS_CROSSING_MARKER) << 3)|\
                                             ((m_AbdOutputData.sConstructionSite.CS_INHIBIT_SINGLE_LINE) << 4)|\
                                             ((m_AbdOutputData.sConstructionSite.CS_MARKER_COLOR_CHANGE) << 5)|\
                                             ((m_AbdOutputData.sConstructionSite.CS_HOLD) << 6))
#endif

#if (defined(LCF_IUC_USED) && (LCF_IUC_USED == 1)) && (defined(LCF_CAMOBJ_USED) && (LCF_CAMOBJ_USED == 1))
#define ERRIO_IgnoreBit_Sen				(unsigned char(0))
#elif defined(LCF_IUC_USED) && (LCF_IUC_USED == 1)
#define ERRIO_IgnoreBit_Sen				(unsigned char(12))
#elif defined(LCF_CAMOBJ_USED) && (LCF_CAMOBJ_USED == 1)
#define ERRIO_IgnoreBit_Sen				(unsigned char(32))
#else
#define ERRIO_IgnoreBit_Sen				(unsigned char(44))
#endif

#if (defined(LCF_IUC_USED) && (LCF_IUC_USED == 1))
#define ERRIO_IgnoreBit_Veh				(unsigned char(0))
#else
#define ERRIO_IgnoreBit_Veh				(unsigned char(8))
#endif

//Typedefs
typedef std::vector<std::string> STRINGLIST;
typedef std::vector<STRINGLIST> RECTLIST;
typedef std::map<std::string, STRINGLIST> BITFIELDMAP;
typedef std::pair<std::string, STRINGLIST> BITFIELDPAIR;

/// Class representing a SIM plugin to the SIM VFB MO in MTS
class CSimLcfVis 
  : public CSimSwcDrawBase
{
public:
  /// Constructor of the class.
  /// Gets called when the plugin is loaded.
  CSimLcfVis();

  /// Destructor of the class.
  /// Gets called when the plugin is unloaded.
  ~CSimLcfVis();

  static void Reset(void* PlgID, long, long) { reinterpret_cast<CSimLcfVis*>(PlgID)->Reset(); }
  //static void Init(void* PlgID, long, long) { reinterpret_cast<CSimLcf*>(PlgID)->Init(); }
  static void Doit(void* PlgID, long, long) { reinterpret_cast<CSimLcfVis*>(PlgID)->Doit(); }

  // @name static drawing functions
  static void DrawLcfGraphic(void* PlgID, long CtxPtr, long) { reinterpret_cast<CSimLcfVis*>(PlgID)->DrawLcfGraphic(*reinterpret_cast<ISimRenderContext*>( LongToPtr(CtxPtr))); }
  static void DrawLDGraphic(void* PlgID, long CtxPtr, long) { reinterpret_cast<CSimLcfVis*>(PlgID)->DrawLDGraphic(*reinterpret_cast<ISimRenderContext*>( LongToPtr(CtxPtr))); }
  static void DrawLcfInfo(void* PlgID, long CtxPtr, long) { reinterpret_cast<CSimLcfVis*>(PlgID)->DrawLcfInfo(*reinterpret_cast<ISimRenderContext*>( LongToPtr(CtxPtr))); }
  static void DrawLcfHMIInfo(void* PlgID, long CtxPtr, long) { reinterpret_cast<CSimLcfVis*>(PlgID)->DrawLcfHMIInfo(*reinterpret_cast<ISimRenderContext*>( LongToPtr(CtxPtr))); }
  static void DrawLCFLegend(void* PlgID, long CtxPtr, long) { reinterpret_cast<CSimLcfVis*>(PlgID)->DrawLCFLegend(*reinterpret_cast<ISimRenderContext*>( LongToPtr(CtxPtr))); }
  static void DrawLcfStatusInfo(void* PlgID, long CtxPtr, long) { reinterpret_cast<CSimLcfVis*>(PlgID)->DrawLcfStatusInfo(*reinterpret_cast<ISimRenderContext*>( LongToPtr(CtxPtr))); }
  static void DrawLcfFunctionTable(void* PlgID, long CtxPtr, long) { reinterpret_cast<CSimLcfVis*>(PlgID)->DrawLcfFunctionTable(*reinterpret_cast<ISimRenderContext*>( LongToPtr(CtxPtr))); }
  static void DrawLCFTableDebug(void* PlgID, long CtxPtr, long) {reinterpret_cast<CSimLcfVis*>(PlgID)->DrawLCFTableDebug(*reinterpret_cast<ISimRenderContext*>( LongToPtr(CtxPtr))); }
  static void DrawLCFBitfieldInfo(void* PlgID, long CtxPtr, long) {reinterpret_cast<CSimLcfVis*>(PlgID)->DrawLCFBitfieldInfo(*reinterpret_cast<ISimRenderContext*>( LongToPtr(CtxPtr))); }

  virtual bool OnKeyboardMessage(const ISimRenderContext& context, const ISimWindowMessage& windowMessage);

  typedef struct {
  	string signal_name; 
  	unsigned int Bitfield_Value;
  	vector <string> Description;
	bool Is_Connected;
  }LCF_Bitfield_Info;

  struct LCF_Scheduler_Check_t {
	  unsigned int Prev_TS_Value;
	  unsigned int Prev_CC_Value;
	  signed long Total_TS_Value;
	  signed long Total_CC_Value;
	  unsigned int Instant_TS_Difference;
	  unsigned int AverageCycleTime;
	  unsigned char IgnoreFrame;
	  unsigned char CycleCounterBlocked;
	  unsigned char TimestampBlocked;
	  unsigned int NumberOfSkippedFrames;
	  float PercentageOfSkippedFrames;
	  std::queue<unsigned int> Buffer_Inst_TS_Difference;

	  /* Initialize in constructor with default values */
	  LCF_Scheduler_Check_t(unsigned int Prev_TS, unsigned int Prev_CC, long timestamp, long cycle_counter, unsigned int TS_difference, unsigned int average, unsigned char _ignoreframe, unsigned char CC_Blocked, unsigned char TS_Blocked, unsigned int skipped_frames, float perc):
		  Prev_TS_Value(Prev_TS), Prev_CC_Value(Prev_CC), Total_TS_Value(timestamp), Total_CC_Value(cycle_counter), Instant_TS_Difference(TS_difference), AverageCycleTime(average), IgnoreFrame(_ignoreframe),
		  CycleCounterBlocked(CC_Blocked), TimestampBlocked(TS_Blocked), NumberOfSkippedFrames(skipped_frames), PercentageOfSkippedFrames(perc)
		  {
		  }
  };


private:

	std::string fileName;
	std::string fileName_SpecCase;
	std::string delimeter;

	int	NoOfRowsCSV;
	int	NoOfColumnsCSV;
	bool CSV_Open_Flag;

    struct RGBAColor
    {
    public:
        RGBAColor(const float& _r = 1.0f, const float& _g = 1.0f, const float& _b = 1.0f, const float& _a = 1.0f) : r(_r), g(_g), b(_b), a(_a) {}
        float r;
        float g;
        float b;
        float a;
    };

  RGBAColor colorWhite;
  RGBAColor colorYellow;
  RGBAColor colorOrange;
  RGBAColor colorGreen;
  RGBAColor colorRed;
  RGBAColor colorBlue;
  RGBAColor colorNavy;
  RGBAColor colorTeal;
  RGBAColor colorLime;
  RGBAColor colorAqua;
  RGBAColor colorMaroon;
  RGBAColor colorPurple;
  RGBAColor colorViolet;
  RGBAColor colorOlive;
  RGBAColor colorGray;
  RGBAColor colorLightGray;
  RGBAColor colorSilver;
  RGBAColor colorFuchsia;

  static const unsigned long MAX_REPORTED_PORT_ERRORS = 100; ///< Maximum reported receive port errors

  /// @name client port names, for reuse
  static const char* CP_CALCULATIONDONE;

  /// @name receive ports
  SimReceivePort<LCF_VehGenericOutputs_t,       simOPAQUE_t>    m_rpLcfVehOutputData;
  SimReceivePort<LCF_VehToSen_t,                simOPAQUE_t>    m_rpLcfVehOutputToSenData;
  SimReceivePort<LCF_SenGenericOutputs_t,       simOPAQUE_t>    m_rpLcfSenOutputData;
  SimReceivePort<LCF_SenToVeh_t,                simOPAQUE_t>    m_rpLcfSenOutputToVehData;
  SimReceivePort<LCF_GenericInputs_t,           simOPAQUE_t>    m_rpLcfInputData;
#if defined(LCF_SEN_RPORT_PHLARADAROBJECTLIST)
  SimReceivePort<HLA_RadarObjectList_t,         simOPAQUE_t>    m_rpHlaRadarObjectList;
#endif
#if defined(LCF_SEN_RPORT_PLSDENVIRONMENTDATA)
  SimReceivePort<LSD_EnvironmentData_t,         simOPAQUE_t>    m_rpLsdEnvironmentData;
#endif
#if defined(LCF_SEN_RPORT_PCBOUTPUTS)
  SimReceivePort<CB_t_ProvidedOutputs_t,        simOPAQUE_t>    m_rpCbOutputs;
#endif
  SimReceivePort<AbdOutputData_t,               simOPAQUE_t>    m_rpAbdOutputData;
  SimReceivePort<VehPar_t,                      simOPAQUE_t>    m_rpVehPar;
  SimReceivePort<VehSig_t,                      simOPAQUE_t>    m_rpVehSig;
  SimReceivePort<VehDyn_t,                      simOPAQUE_t>    m_rpVehDyn;
  SimReceivePort<LCF_SenDebugData_t,			simOPAQUE_t>	m_rpLCF_SenDebugData;
  SimReceivePort<LCF_VehDebugData_t,			simOPAQUE_t>	m_rpLCF_VehDebugData;
  SimReceivePort<AlgoCompState_t,			    simOPAQUE_t>	m_rpLCF_SenAlgoCompState;
  SimReceivePort<AlgoCompState_t,			    simOPAQUE_t>	m_rpLCF_VehAlgoCompState;

  SimReceivePort<TJASideObject_t,			    simOPAQUE_t>	m_rpLCF_TJASideObject;
  SimReceivePort<TJATargetObject_t,			    simOPAQUE_t>	m_rpLCF_TJATargetObject;
  
  /* TJA signals */
  SimReceivePort<unsigned short,		        simUI16_t>      m_rp_D_TJALKA_LaneCenterInvalid_btf;
  SimReceivePort<unsigned short,		        simUI16_t>      m_rp_D_TJALKA_LaneInvalid_btf;
  SimReceivePort<unsigned char,				    simUI8_t>       m_rp_S_TJALKA_LanePredictValid_bool;
  SimReceivePort<unsigned char,				    simUI8_t>       m_rp_S_TJALKA_LnBndValid_nu;
  SimReceivePort<unsigned char,				    simUI8_t>       m_rp_S_TJALKA_StrongReady_bool;
  SimReceivePort<unsigned char,				    simUI8_t>       m_rp_S_TJALKA_WeakReady_bool;
  SimReceivePort<unsigned short,     		    simUI16_t>      m_rp_D_TJAOBF_ObjFollowInvalid_btf;
  SimReceivePort<unsigned short,		        simUI16_t>      m_rp_D_TJAOBF_ObjInLaneInvalid_btf;
  SimReceivePort<unsigned char,				    simUI8_t>       m_rp_D_TJAOBF_TgtObjDataInvalid_btf;
  SimReceivePort<unsigned char,				    simUI8_t>       m_rp_S_TJAOBF_AccObjValid_bool;
  SimReceivePort<unsigned char,				    simUI8_t>       m_rp_S_TJAOBF_StrongReady_bool;
  SimReceivePort<unsigned char,				    simUI8_t>       m_rp_S_TJAOBF_WeakReady_bool;
  SimReceivePort<unsigned char,				    simUI8_t>       m_rp_S_TJACMB_StrongReady_bool;
  SimReceivePort<unsigned char,				    simUI8_t>       m_rp_D_TJAGEN_StrongReadyInvalid_btf;
  SimReceivePort<unsigned char,				    simUI8_t>       m_rp_D_TJAGEN_WeakReadyInvalid_btf;
  SimReceivePort<unsigned char,				    simUI8_t>       m_rp_D_TJAGEN_CancelStatus_btf;
  SimReceivePort<unsigned short,		        simUI16_t>      m_rp_D_TJASTM_TJAInvalid_btf;
  SimReceivePort<unsigned short,		        simUI16_t>      m_rp_D_TJACMB_CombinedInvalid_btf;

  /* ODPR signals */
  SimReceivePort<float,						    simF32_t>       m_rp_S_ODPFOP_AccObjPosX_met;
  SimReceivePort<float,							simF32_t>       m_rp_S_ODPFOP_AccObjPosY_met;
  SimReceivePort<float,							simF32_t>       m_rp_S_ODPFOP_AccObjRelAclX_mps2;
  SimReceivePort<float,							simF32_t>       m_rp_S_ODPFOP_AccObjRelAclY_mps2;
  SimReceivePort<float,							simF32_t>       m_rp_S_ODPFOP_AccObjRelVelX_mps;
  SimReceivePort<float,							simF32_t>       m_rp_S_ODPFOP_AccObjRelVelY_mps;
  SimReceivePort<float,     					simF32_t>       m_rp_S_ODPFOP_EstimatedObjPosX_met;
  SimReceivePort<float,					        simF32_t>       m_rp_S_ODPFOP_EstimatedObjPosY_met;
  SimReceivePort<unsigned short,		        simUI16_t>     	m_rp_S_ODPFOP_AccObjInvBitfield_btf;

  /* VDPR signals */
  SimReceivePort<unsigned short,			    simUI16_t>      m_rp_S_VDPDRV_VehStInvalid_btf;
  SimReceivePort<unsigned char,				    simUI8_t>       m_rp_S_VDPDRV_ActiveStCtrl_btf;
  SimReceivePort<unsigned char,				    simUI8_t>       m_rp_S_VDPDRV_DrvStInvalid_btf;
  SimReceivePort<unsigned char,				    simUI8_t>       m_rp_S_VDPDRV_SysStError_btf;
  SimReceivePort<unsigned char,				    simUI8_t>       m_rp_S_VDPDRV_SysStNotAvailable_btf;

  /* ABPR signals */
  SimReceivePort<float,     				    simF32_t>       m_rp_S_ABPLBP_LaneWidth_met;
  SimReceivePort<float,					        simF32_t>       m_rp_S_ABPLBP_LeLnClthPosY0_met;
  SimReceivePort<float,					        simF32_t>       m_rp_S_ABPLBP_LeLnClthPosY0SIF_met;
  SimReceivePort<float,						    simF32_t>       m_rp_S_ABPLBP_RiLnClthPosY0_met;
  SimReceivePort<float,						    simF32_t>       m_rp_S_ABPLBP_RiLnClthPosY0SIF_met;
  SimReceivePort<unsigned short,			    simUI16_t>      m_rp_S_ABPLBP_LeLnInvalidQu_btf;
  SimReceivePort<unsigned short,			    simUI16_t>      m_rp_S_ABPLBP_RiLnInvalidQu_btf;
  SimReceivePort<unsigned char,				    simUI8_t>       m_rp_S_ABPLBP_ConstructionSite_bool;
  SimReceivePort<unsigned char,				    simUI8_t>       m_rp_S_ABPLBP_CntrLnKalmanStatus_nu;
  SimReceivePort<float,						    simF32_t>       m_rp_S_ABPLBP_LeLnClthLength_met;
  SimReceivePort<float,						    simF32_t>       m_rp_S_ABPLBP_RiLnClthLength_met;
  SimReceivePort<unsigned char,				    simUI8_t>       m_rp_S_ABPLBP_LeLnQuality_perc;
  SimReceivePort<unsigned char, 		        simUI8_t>       m_rp_S_ABPLBP_RiLnQuality_perc;
  SimReceivePort<unsigned char, 		        simUI8_t>       m_rp_S_ABPLBP_LaneValidQualVis_nu;
  SimReceivePort<float,					        simF32_t>       m_rp_S_ABPREP_LeRePosY0_met;
  SimReceivePort<float,						    simF32_t>       m_rp_S_ABPREP_RiRePosY0_met;
  SimReceivePort<unsigned short,		        simUI16_t>      m_rp_S_ABPREP_LeReInvalidQu_btf;	
  SimReceivePort<unsigned short,		        simUI16_t>      m_rp_S_ABPREP_RiReInvalidQu_btf;

  /* LDP signals */
  SimReceivePort<float,     				    simF32_t>       m_rp_S_DPLSIA_DlcLeLDP_met;
  SimReceivePort<float,					        simF32_t>       m_rp_D_DPLSMI_DlcLeThreshold_met;
  SimReceivePort<float,						    simF32_t>       m_rp_S_DPLSIA_DlcRiLDP_met;
  SimReceivePort<float,							simF32_t>       m_rp_D_DPLSMI_DlcRiThreshold_met;
  SimReceivePort<float,     				    simF32_t>       m_rp_S_DPLSIA_TlcLeLDP_sec;
  SimReceivePort<float,					        simF32_t>       m_rp_D_DPLSMI_TlcLeThreshold_sec;
  SimReceivePort<float,						    simF32_t>       m_rp_S_DPLSIA_TlcRiLDP_sec;
  SimReceivePort<float,							simF32_t>       m_rp_D_DPLSMI_TlcRiThreshold_sec;
  SimReceivePort<float,						    simF32_t>       m_rp_S_DPLSIA_VelLatLeLDP_mps;
  SimReceivePort<float,						    simF32_t>       m_rp_S_DPLSIA_VelLatRiLDP_mps;
  SimReceivePort<unsigned char,				    simUI8_t>       m_rp_S_DPLSIA_LnBndValidLDP_nu;
  SimReceivePort<unsigned char,				    simUI8_t>       m_rp_S_DPLSIA_SideCondLDPLe_btf;
  SimReceivePort<unsigned char,			        simUI8_t>       m_rp_S_DPLSIA_SideCondLDPRi_btf;
  SimReceivePort<unsigned char,			        simUI8_t>       m_rp_S_DPLSIA_SpecificLDP_btf;
  SimReceivePort<unsigned char,					simUI8_t>       m_rp_D_DPLSMI_Cancel_btf;
  SimReceivePort<unsigned char,					simUI8_t>       m_rp_D_DPLSMI_StrongReady_btf;
  SimReceivePort<unsigned char,					simUI8_t>       m_rp_D_DPLSMI_SysStateLDP_btf;
  SimReceivePort<unsigned char,					simUI8_t>       m_rp_D_DPLSMI_WeakReady_btf;
  SimReceivePort<unsigned char,					simUI8_t>       m_rp_S_DPLSMI_DangerousSide_nu;
  SimReceivePort<unsigned char,					simUI8_t>       m_rp_S_DPLSMI_ReadyToTrigger_bool;

  /* LDW signals */
  SimReceivePort<float,     				    simF32_t>       m_rp_S_DPLSIA_DlcLeLDW_met;
  SimReceivePort<float,					        simF32_t>       m_rp_D_DPLSMW_DlcLeThreshold_met;
  SimReceivePort<float,						    simF32_t>       m_rp_S_DPLSIA_DlcRiLDW_met;
  SimReceivePort<float,							simF32_t>       m_rp_D_DPLSMW_DlcRiThreshold_met;
  SimReceivePort<float,     				    simF32_t>       m_rp_S_DPLSIA_TlcLeLDW_sec;
  SimReceivePort<float,					        simF32_t>       m_rp_D_DPLSMW_TlcLeThreshold_sec;
  SimReceivePort<float,						    simF32_t>       m_rp_S_DPLSIA_TlcRiLDW_sec;
  SimReceivePort<float,							simF32_t>       m_rp_D_DPLSMW_TlcRiThreshold_sec;
  SimReceivePort<float,						    simF32_t>       m_rp_S_DPLSIA_VelLatLeLDW_mps;
  SimReceivePort<float,						    simF32_t>       m_rp_S_DPLSIA_VelLatRiLDW_mps;
  SimReceivePort<unsigned char,				    simUI8_t>       m_rp_S_DPLSIA_LnBndValidLDW_nu;
  SimReceivePort<unsigned char,				    simUI8_t>       m_rp_S_DPLSIA_SideCondLDWLe_btf;
  SimReceivePort<unsigned char,			        simUI8_t>       m_rp_S_DPLSIA_SideCondLDWRi_btf;
  SimReceivePort<unsigned char,			        simUI8_t>       m_rp_S_DPLSIA_SpecificLDW_btf;
  SimReceivePort<unsigned char,					simUI8_t>       m_rp_D_DPLSMW_Cancel_btf;
  SimReceivePort<unsigned char,					simUI8_t>       m_rp_D_DPLSMW_StrongReady_btf;
  SimReceivePort<unsigned char,					simUI8_t>       m_rp_D_DPLSMW_SysStateLDW_btf;
  SimReceivePort<unsigned char,					simUI8_t>       m_rp_D_DPLSMW_WeakReady_btf;
  SimReceivePort<unsigned char,					simUI8_t>       m_rp_S_DPLSMW_DangerousSide_nu;
  SimReceivePort<unsigned char,					simUI8_t>       m_rp_S_DPLSMW_ReadyToTrigger_bool;

  /* RDP signals */
  SimReceivePort<float,     				    simF32_t>       m_rp_S_DPRSIA_DrcLeRDP_met;
  SimReceivePort<float,     				    simF32_t>       m_rp_D_DPRSMI_DrcLeThreshold_met;
  SimReceivePort<float,					        simF32_t>       m_rp_S_DPRSIA_DrcRiRDP_met;
  SimReceivePort<float,     				    simF32_t>       m_rp_D_DPRSMI_DrcRiThreshold_met;
  SimReceivePort<float,     				    simF32_t>       m_rp_S_DPRSIA_DlcLeRDP_met;
  SimReceivePort<float,     				    simF32_t>       m_rp_D_DPRSMI_DlcLeThreshold_met;
  SimReceivePort<float,					        simF32_t>       m_rp_S_DPRSIA_DlcRiRDP_met;
  SimReceivePort<float,     				    simF32_t>       m_rp_D_DPRSMI_DlcRiThreshold_met;
  SimReceivePort<float,					        simF32_t>       m_rp_S_DPRSIA_VelLatReLeRDP_mps;
  SimReceivePort<float,     				    simF32_t>       m_rp_S_DPRSIA_VelLatReRiRDP_mps;
  SimReceivePort<unsigned char,					simUI8_t>       m_rp_S_DPRSIA_TgtCntrLnEnable_bool; 
  SimReceivePort<float,						    simF32_t>       m_rp_S_DPRSIA_LaneWidthRDP_met;
  SimReceivePort<unsigned char,					simUI8_t>       m_rp_S_DPRSIA_LnBndValidRDP_nu;
  SimReceivePort<unsigned char,					simUI8_t>       m_rp_S_DPRSIA_RdBndValidRDP_nu;
  SimReceivePort<unsigned char,				    simUI8_t>       m_rp_S_DPRSIA_SideCondRDPLe_btf;
  SimReceivePort<unsigned char,				    simUI8_t>       m_rp_S_DPRSIA_SideCondRDPRi_btf;
  SimReceivePort<unsigned char,				    simUI8_t>       m_rp_S_DPRSIA_SpecificRDP_btf;
  SimReceivePort<unsigned char,			        simUI8_t>       m_rp_D_DPRSMI_Cancel_btf;
  SimReceivePort<unsigned char,			        simUI8_t>       m_rp_D_DPRSMI_StrongReady_btf;
  SimReceivePort<unsigned char,					simUI8_t>       m_rp_D_DPRSMI_SysStateRDP_btf;
  SimReceivePort<unsigned char,					simUI8_t>       m_rp_D_DPRSMI_WeakReady_btf;
  SimReceivePort<unsigned char,					simUI8_t>       m_rp_S_DPRSMI_DangerousSide_nu;
  SimReceivePort<unsigned char,					simUI8_t>       m_rp_S_DPRSMI_TriggerReason_nu;
  SimReceivePort<unsigned char,					simUI8_t>       m_rp_S_DPRSMI_ReadyToTrigger_bool;  

  /* LCF SEN Integration signals */
  SimReceivePort<unsigned short,			    simUI16_t>      m_rp_D_LCFSEN_proPorts_NullStatusCheck;
  SimReceivePort<unsigned int,			        simUI32_t>      m_rp_D_LCFSEN_reqPorts_NullStatusCheck;
  SimReceivePort<unsigned short,			    simUI16_t>      m_rp_D_LCFSEN_services_NullStatusCheck;
  SimReceivePort<unsigned int,					simUI32_t>      m_rp_D_LCFSEN_reqPorts_SignalStatusOk;
  SimReceivePort<unsigned int,					simUI32_t>      m_rp_D_LCFSEN_reqPorts_SignalStatusInit;
  SimReceivePort<unsigned int,				    simUI32_t>      m_rp_D_LCFSEN_reqPorts_SignalStatusInvalid;
  SimReceivePort<unsigned int,				    simUI32_t>      m_rp_D_LCFSEN_reqPorts_VersionNumberCheck;
  SimReceivePort<unsigned char,				    simUI8_t>       m_rp_uiSenTunParCopied;
  SimReceivePort<unsigned char,			        simUI8_t>       m_rp_uiSenVdyParCopied;

  /* LCF VEH Integration signals */
  SimReceivePort<unsigned short,			    simUI16_t>      m_rp_D_LCFVEH_proPorts_NullStatusCheck;
  SimReceivePort<unsigned short,		        simUI16_t>      m_rp_D_LCFVEH_reqPorts_NullStatusCheck;
  SimReceivePort<unsigned short,			    simUI16_t>      m_rp_D_LCFVEH_services_NullStatusCheck;
  SimReceivePort<unsigned short,				simUI16_t>      m_rp_D_LCFVEH_reqPorts_SignalStatusOk;
  SimReceivePort<unsigned short,				simUI16_t>      m_rp_D_LCFVEH_reqPorts_SignalStatusInit;
  SimReceivePort<unsigned short,				simUI16_t>      m_rp_D_LCFVEH_reqPorts_SignalStatusInvalid;
  SimReceivePort<unsigned short,			    simUI16_t>      m_rp_D_LCFVEH_reqPorts_VersionNumberCheck;
  SimReceivePort<unsigned char,				    simUI8_t>       m_rp_uiVehTunParCopied;
  SimReceivePort<unsigned char,			        simUI8_t>       m_rp_uiVehVdyParCopied;
  SimReceivePort<unsigned char,			        simUI8_t>	    m_rp_uiVehNvmDataValid;

  /* LCF SEN Error Handler signals */
  SimReceivePort<unsigned int[NUM_DEBUG_ERR_POS_NORM/32],		simUI32_t>      m_rp_D_LCFERR_ErrorConfirmedNorm_btf;
  SimReceivePort<unsigned char,									simUI8_t>       m_rp_D_LCFERR_ErrorConfirmedVDY_btf;
  SimReceivePort<unsigned char,									simUI8_t>       m_rp_D_LCFERR_ErrorConfirmedVSA_btf;
  SimReceivePort<unsigned char,									simUI8_t>       m_rp_D_LCFERR_ErrorConfirmedVSM_btf;
  SimReceivePort<unsigned short,								simUI16_t>      m_rp_D_LCFERR_AlliveFailedTSMon_btf;
  SimReceivePort<unsigned short,								simUI16_t>      m_rp_D_LCFERR_AlliveFailedTSBcd_btf;
  SimReceivePort<unsigned short,								simUI16_t>      m_rp_D_LCFERR_AlliveFailedMC_btf;
  SimReceivePort<unsigned short,								simUI16_t>      m_rp_D_LCFERR_AlliveFailedCCMon_btf;
  SimReceivePort<unsigned short,								simUI16_t>      m_rp_D_LCFERR_AlliveFailedCCConst_btf;
  SimReceivePort<unsigned char,									simUI8_t>       m_rp_D_LCFERR_AlgoCompState;
  SimReceivePort<unsigned char,									simUI8_t>		m_rp_D_LCFERR_SenOutSigStatus;
  SimReceivePort<unsigned char,									simUI8_t>		m_rp_D_LCFERR_Sen2VehSigStatus;
  SimReceivePort<unsigned char,									simUI8_t>		m_rp_D_LCFERR_DemEvents_btf;
  SimReceivePort<unsigned char[12],								simUI8_t>		m_rp_D_ERRIOSEN_ErrStateArray;
  SimReceivePort<unsigned int[8],								simUI32_t>		m_rp_D_LCFERR_RngChkDbg_btf;

  /* LCF VEH Error Handler signals */
  SimReceivePort<unsigned int[NUM_DEBUG_ERR_POS_NORM/32],		simUI32_t>      m_rp_D_LCFERR_Veh_ErrorConfirmedNorm_btf;
  SimReceivePort<unsigned char,									simUI8_t>       m_rp_D_LCFERR_Veh_ErrorConfirmedVDY_btf;
  SimReceivePort<unsigned char,									simUI8_t>       m_rp_D_LCFERR_Veh_ErrorConfirmedVSA_btf;
  SimReceivePort<unsigned char,									simUI8_t>       m_rp_D_LCFERR_Veh_ErrorConfirmedVSM_btf;
  SimReceivePort<unsigned short,								simUI16_t>      m_rp_D_LCFERR_Veh_AlliveFailedTSMon_btf;
  SimReceivePort<unsigned short,								simUI16_t>      m_rp_D_LCFERR_Veh_AlliveFailedTSBcd_btf;
  SimReceivePort<unsigned short,								simUI16_t>      m_rp_D_LCFERR_Veh_AlliveFailedMC_btf;
  SimReceivePort<unsigned short,								simUI16_t>      m_rp_D_LCFERR_Veh_AlliveFailedCCMon_btf;
  SimReceivePort<unsigned short,								simUI16_t>      m_rp_D_LCFERR_Veh_AlliveFailedCCConst_btf;
  SimReceivePort<unsigned char,									simUI8_t>       m_rp_D_LCFERR_Veh_AlgoCompState;
  SimReceivePort<unsigned char,									simUI8_t>		m_rp_D_LCFERR_Veh_VehOutSigStatus;
  SimReceivePort<unsigned char,									simUI8_t>		m_rp_D_LCFERR_Veh_Veh2SenSigStatus;
  SimReceivePort<unsigned char,									simUI8_t>		m_rp_D_LCFERR_Veh_Soc2IucSigStatus;
  SimReceivePort<unsigned char,									simUI8_t>		m_rp_D_LCFERR_Veh_DemEvents_btf;
  SimReceivePort<unsigned char[12],								simUI8_t>		m_rp_D_ERRIOVEH_ErrStateArray;
  SimReceivePort<unsigned int[8],								simUI32_t>		m_rp_D_LCFERR_Veh_RngChkDbg_btf;

  /* TrajPlan signals */
  SimReceivePort<float,							simF32_t>       m_rp_D_TPLLCO_DeltaProjPosX_met;
  SimReceivePort<float,							simF32_t>       m_rp_D_TPLLCO_DeltaProjPosY_met;
  SimReceivePort<float,							simF32_t>       m_rp_D_TPLLCO_RightOri_rad;
  SimReceivePort<float,							simF32_t>       m_rp_S_TPLTJC_EndPointTrajectory_nu;
  SimReceivePort<float,							simF32_t>       m_rp_S_TPLLCO_RightCridrHeading_rad;
  SimReceivePort<float,							simF32_t>       m_rp_S_TPLLCO_RightCorridorCrv_1pm;
  SimReceivePort<float,							simF32_t>       m_rp_S_TPLLCO_RiCridrChngOfCrv_1pm2;
  SimReceivePort<float[6],						simF32_t>       m_rp_S_TPLTJC_TrajParam_nu;

  /* Driver Monitoring signals */
  SimReceivePort<unsigned char,					simUI8_t>       m_rp_S_DRMDAE_AbuseWarning_bool;
  SimReceivePort<unsigned char,					simUI8_t>       m_rp_S_DRMDAE_SysWarning_nu;
  SimReceivePort<float,							simF32_t>       m_rp_D_DRMHOD_EstHandTor_Nm;
  SimReceivePort<unsigned char,				    simUI8_t>       m_rp_S_DRMHOD_HandsOffConfirmed_bool;

  /* LCF SEN Output Signals */
  SimReceivePort<unsigned char,                 simUI8_t>       m_rp_LDWSystemState_nu;
  SimReceivePort<unsigned char,                 simUI8_t>       m_rp_LDWSystemStateLeft_nu;
  SimReceivePort<unsigned char,                 simUI8_t>       m_rp_LDWSystemStateRight_nu;
  SimReceivePort<unsigned char,                 simUI8_t>       m_rp_LDPSystemState_nu;
  SimReceivePort<unsigned char,                 simUI8_t>       m_rp_LDPSystemStateLeft_nu;
  SimReceivePort<unsigned char,                 simUI8_t>       m_rp_LDPSystemStateRight_nu;
  SimReceivePort<unsigned char,                 simUI8_t>       m_rp_RDPSystemState_nu;
  SimReceivePort<unsigned char,                 simUI8_t>       m_rp_RDPSystemStateLeft_nu;
  SimReceivePort<unsigned char,                 simUI8_t>       m_rp_RDPSystemStateRight_nu;
  SimReceivePort<unsigned char,                 simUI8_t>       m_rp_TJASystemState_nu;
  SimReceivePort<unsigned char,                 simUI8_t>       m_rp_TJALatCtrlMode_nu;
  SimReceivePort<unsigned char,                 simUI8_t>       m_rp_LaneRecogState_nu;
  SimReceivePort<unsigned char,                 simUI8_t>       m_rp_HapticWrnDeviceLeftReq_nu;
  SimReceivePort<unsigned char,                 simUI8_t>       m_rp_HapticWrnDeviceRightReq_nu;
  SimReceivePort<unsigned char,                 simUI8_t>       m_rp_HapticWrnDeviceCommonReq_nu;
  SimReceivePort<unsigned char,                 simUI8_t>       m_rp_VisualWrnDeviceLeftReq_nu;
  SimReceivePort<unsigned char,                 simUI8_t>       m_rp_VisualWrnDeviceRightReq_nu;
  SimReceivePort<unsigned char,                 simUI8_t>       m_rp_VisualWrnDeviceCommonReq_nu;
  SimReceivePort<unsigned char,                 simUI8_t>       m_rp_LaneValidQualDMC_nu;
  SimReceivePort<unsigned char,                 simUI8_t>       m_rp_HandsOffSysWarning_nu;
  SimReceivePort<unsigned char,                 simUI8_t>       m_rp_ErrorStateTJA_nu;
  SimReceivePort<unsigned char,                 simUI8_t>       m_rp_CustSpecSysStateTJA_nu;
  SimReceivePort<unsigned char,                 simUI8_t>       m_rp_ErrorStateLDP_nu;
  SimReceivePort<unsigned char,                 simUI8_t>       m_rp_CustSpecSysStateLDP_nu;
  SimReceivePort<unsigned char,                 simUI8_t>       m_rp_ErrorStateLDW_nu;
  SimReceivePort<unsigned char,                 simUI8_t>       m_rp_CustSpecSysStateLDW_nu;
  SimReceivePort<unsigned char,                 simUI8_t>       m_rp_ErrorStateRDP_nu;
  SimReceivePort<unsigned char,                 simUI8_t>       m_rp_CustSpecSysStateRDP_nu;
  SimReceivePort<float,                         simF32_t>       m_rp_LCF_Stiffness_nu;
  SimReceivePort<float,                         simF32_t>       m_rp_LCF_Accuracy_nu;
  SimReceivePort<unsigned char,                 simUI8_t>       m_rp_TJA_Status_nu;
  SimReceivePort<unsigned short,                simUI16_t>      m_rp_DFFunctActiveState_btf;
  SimReceivePort<unsigned char,                 simUI8_t>       m_rp_LnBndLeValid4Fct_btf;
  SimReceivePort<unsigned char,                 simUI8_t>       m_rp_LnBndRiValid4Fct_btf;
  SimReceivePort<unsigned char,                 simUI8_t>       m_rp_DispLaneLeftDetected_nu;
  SimReceivePort<unsigned char,                 simUI8_t>       m_rp_DispLaneRightDetected_nu;
  SimReceivePort<unsigned char,                 simUI8_t>       m_rp_SteeringWheelVibrationReq_nu;
  SimReceivePort<unsigned char,                 simUI8_t>       m_rp_DrvAttWarnQualifier_nu;
  SimReceivePort<unsigned char,                 simUI8_t>       m_rp_TMC_Indi_nu;
  SimReceivePort<unsigned char,                 simUI8_t>       m_rp_TMC_LaneDispLeft_nu;
  SimReceivePort<unsigned char,                 simUI8_t>       m_rp_TMC_LaneDispRight_nu;
  SimReceivePort<unsigned char,                 simUI8_t>       m_rp_TMC_StrgCtrlAct_nu;
  SimReceivePort<unsigned int,                  simUI32_t>      m_rp_SenOut_uiVersionNumber;
  SimReceivePort<unsigned int,                  simUI32_t>      m_rp_SenOut_uiTimeStamp;
  SimReceivePort<unsigned short,                simUI16_t>      m_rp_SenOut_uiMeasurementCounter;
  SimReceivePort<unsigned short,                simUI16_t>      m_rp_SenOut_uiCycleCounter;
  SimReceivePort<unsigned char,                 simUI8_t>       m_rp_SenOut_eSigStatus;
  /* OcPa : Take the left corridor / right corridor / target corridor as individual structures to draw the lines in DrawLcfLaneMarker method */
  SimReceivePort<LCF_TrajPlanCorridor_t,        simOPAQUE_t>	m_rp_SenOut_LeftLaneCorridor;
  SimReceivePort<LCF_TrajPlanCorridor_t,	    simOPAQUE_t>	m_rp_SenOut_RightLaneCorridor;
  SimReceivePort<LCF_TrajPlanCorridor_t,	    simOPAQUE_t>	m_rp_SenOut_TargetCorridor;

  /* LCF Sen2Veh Output Signals */
  SimReceivePort<unsigned char,                 simUI8_t>       m_rp_ControllingFunction_nu;
  SimReceivePort<unsigned char,                 simUI8_t>       m_rp_ActFctEnabled_nu;
  SimReceivePort<unsigned char,                 simUI8_t>       m_rp_ActFctLevel_nu;
  SimReceivePort<unsigned char,                 simUI8_t>       m_rp_SpecialDrivingCorridor_nu;
  SimReceivePort<float,                         simF32_t>       m_rp_MaxJerkAllowed_mps3;
  SimReceivePort<unsigned char,                 simUI8_t>       m_rp_OcObjActSide_nu;
  SimReceivePort<unsigned char,                 simUI8_t>       m_rp_AngReqMaxLimitScale_per;
  SimReceivePort<unsigned char,                 simUI8_t>       m_rp_AngReqRateMaxLimitScale_per;
  SimReceivePort<unsigned char,                 simUI8_t>       m_rp_SysStateLDP_nu;
  SimReceivePort<unsigned char,                 simUI8_t>       m_rp_SysStateRDP_nu;
  SimReceivePort<unsigned char,                 simUI8_t>       m_rp_SysStateLDW_nu;
  SimReceivePort<unsigned char,                 simUI8_t>       m_rp_SysStateLDPOC_nu;
  SimReceivePort<unsigned char,                 simUI8_t>       m_rp_SysStateALCA_nu;
  SimReceivePort<unsigned char,                 simUI8_t>       m_rp_CoordSysStateLCF_nu;
  SimReceivePort<unsigned char,                 simUI8_t>       m_rp_SysStateLKA_nu;
  SimReceivePort<unsigned char,                 simUI8_t>       m_rp_LatCtrlModeLKA_nu;
  SimReceivePort<unsigned char,                 simUI8_t>       m_rp_SysStateTJA_nu;
  SimReceivePort<unsigned char,                 simUI8_t>       m_rp_LatCtrlModeTJA_nu;
  SimReceivePort<unsigned char,                 simUI8_t>       m_rp_LcfCtrlAbort_nu;
  SimReceivePort<unsigned char,                 simUI8_t>       m_rp_LnBndValidLKA_nu;
  SimReceivePort<unsigned char,                 simUI8_t>       m_rp_LnBndValidLDW_nu;
  SimReceivePort<unsigned char,                 simUI8_t>       m_rp_LnBndValidLDP_nu;
  SimReceivePort<unsigned char,                 simUI8_t>       m_rp_LnBndValidRDP_nu;
  SimReceivePort<unsigned char,                 simUI8_t>       m_rp_LnBndValidLDPOC_nu;
  SimReceivePort<unsigned char,                 simUI8_t>       m_rp_LnBndValidTJA_nu;
  SimReceivePort<unsigned char,                 simUI8_t>       m_rp_LnBndValidALCA_nu;
  SimReceivePort<unsigned short,                simUI16_t>      m_rp_LcfFctAvailability_nu;
  SimReceivePort<float,                         simF32_t>       m_rp_ABP_CamCorridorCurvature__1pm;
  SimReceivePort<float,                         simF32_t>       m_rp_ABP_CamLateralError_m;
  SimReceivePort<float,                         simF32_t>       m_rp_ABP_CamHeadingError__rad;
  SimReceivePort<float,                         simF32_t>       m_rp_Sen2Veh_Reserved1_nu;
  SimReceivePort<float,                         simF32_t>       m_rp_Sen2Veh_Reserved2_nu;
  SimReceivePort<unsigned short,                simUI16_t>      m_rp_Sen2Veh_EventId_nu_0_;
  SimReceivePort<unsigned short,                simUI16_t>      m_rp_Sen2Veh_EventLifetime_nu_0_;
  SimReceivePort<unsigned short,                simUI16_t>      m_rp_Sen2Veh_EventId_nu_1_;
  SimReceivePort<unsigned short,                simUI16_t>      m_rp_Sen2Veh_EventLifetime_nu_1_;
  SimReceivePort<unsigned short,                simUI16_t>      m_rp_Sen2Veh_EventId_nu_2_;
  SimReceivePort<unsigned short,                simUI16_t>      m_rp_Sen2Veh_EventLifetime_nu_2_;
  SimReceivePort<unsigned short,                simUI16_t>      m_rp_Sen2Veh_EventId_nu_3_;
  SimReceivePort<unsigned short,                simUI16_t>      m_rp_Sen2Veh_EventLifetime_nu_3_;
  SimReceivePort<unsigned short,                simUI16_t>      m_rp_Sen2Veh_EventId_nu_4_;
  SimReceivePort<unsigned short,                simUI16_t>      m_rp_Sen2Veh_EventLifetime_nu_4_;
  SimReceivePort<unsigned int,                  simUI32_t>      m_rp_Sen2Veh_uiVersionNumber;
  SimReceivePort<unsigned int,                  simUI32_t>      m_rp_Sen2Veh_uiTimeStamp;
  SimReceivePort<unsigned short,                simUI16_t>      m_rp_Sen2Veh_uiMeasurementCounter;
  SimReceivePort<unsigned short,                simUI16_t>      m_rp_Sen2Veh_uiCycleCounter;
  SimReceivePort<unsigned char,                 simUI8_t>       m_rp_Sen2Veh_eSigStatus;

   /* LCF VEH Output Signals */
  SimReceivePort<unsigned char,                 simUI8_t>       m_rp_LaDMC_Status_nu;
  SimReceivePort<unsigned char,                 simUI8_t>       m_rp_LaDMC_Eps_Damping_Level_Request__per;
  SimReceivePort<float,                         simF32_t>       m_rp_Lkas_StrToqReq__nm;
  SimReceivePort<unsigned char,                 simUI8_t>       m_rp_Lkas_ActToi_nu;
  SimReceivePort<unsigned char,                 simUI8_t>       m_rp_Lkas_ToiFlt_nu;
  SimReceivePort<float,                         simF32_t>       m_rp_Lkas_SteeringAngleRate__rps;
  SimReceivePort<float,                         simF32_t>       m_rp_LaKMC_CrvCmd_Sum__1pm;
  SimReceivePort<float,                         simF32_t>       m_rp_LaKMC_CrvCmd_FF__1pm;
  SimReceivePort<float,                         simF32_t>       m_rp_LaKMC_CrvCmd_Ctrl__1pm;
  SimReceivePort<unsigned char,                 simUI8_t>       m_rp_LaKMC_QuTgtVehCtrl_nu;
  SimReceivePort<float,                         simF32_t>       m_rp_LaDMC_StrAngReq__deg;
  SimReceivePort<float,                         simF32_t>       m_rp_LaDMC_StrAngEst__deg;
  SimReceivePort<unsigned char,                 simUI8_t>       m_rp_LaDMC_ActFunc_nu;
  SimReceivePort<float,                         simF32_t>       m_rp_LaDMC_DeratingFactorReq_nu;
  SimReceivePort<float,                         simF32_t>       m_rp_LaDMC_StiffnessReq_nu;
  SimReceivePort<float,                         simF32_t>       m_rp_LaDMC_AccuracyReq_nu;
  SimReceivePort<unsigned char,                 simUI8_t>       m_rp_LaDMC_SteerAngReqQF_nu;
  SimReceivePort<unsigned char,                 simUI8_t>       m_rp_LaDMC_YawRateReqQF_nu;
  SimReceivePort<unsigned char,                 simUI8_t>       m_rp_TMC_DdrData1_nu;
  SimReceivePort<unsigned char,                 simUI8_t>       m_rp_TMC_DdrData2_nu;
  SimReceivePort<unsigned char,                 simUI8_t>       m_rp_TMC_DdrData3_nu;
  SimReceivePort<unsigned char,                 simUI8_t>       m_rp_TSEAESSysState_nu;
  SimReceivePort<unsigned int,                  simUI32_t>      m_rp_VehOut_uiVersionNumber;
  SimReceivePort<unsigned int,                  simUI32_t>      m_rp_VehOut_uiTimeStamp;
  SimReceivePort<unsigned short,                simUI16_t>      m_rp_VehOut_uiMeasurementCounter;
  SimReceivePort<unsigned short,                simUI16_t>      m_rp_VehOut_uiCycleCounter;
  SimReceivePort<unsigned char,                 simUI8_t>       m_rp_VehOut_eSigStatus;

  /* LCF Veh2Sen Output Signals */
  SimReceivePort<float,                         simF32_t>       m_rp_DrvAttention_perc;
  SimReceivePort<signed char,                   simI8_t>        m_rp_DrvAttentionConf_perc;
  SimReceivePort<unsigned char,                 simUI8_t>       m_rp_DrvMonSysWarning_nu;
  SimReceivePort<unsigned char,                 simUI8_t>       m_rp_HandsOffConfirmed_nu;
  SimReceivePort<unsigned char,                 simUI8_t>       m_rp_AbuseWarning_nu;
  SimReceivePort<float,                         simF32_t>       m_rp_EstHandTor_nm;
  SimReceivePort<unsigned char,                 simUI8_t>       m_rp_SAC_Eps_Request_Flag_nu;
  SimReceivePort<float,                         simF32_t>       m_rp_Veh2Sen_Reserved1_nu;
  SimReceivePort<float,                         simF32_t>       m_rp_Veh2Sen_Reserved2_nu;
  SimReceivePort<unsigned char,                 simUI8_t>       m_rp_TrigCustFctReplanCurValues_nu;
  SimReceivePort<unsigned char,                 simUI8_t>       m_rp_TrajGuiQualifier_nu;
  SimReceivePort<float,                         simF32_t>       m_rp_CurDistY_m;
  SimReceivePort<float,                         simF32_t>       m_rp_CurHeading__rad;
  SimReceivePort<float,                         simF32_t>       m_rp_LtcyComp_DevHeading__rad;
  SimReceivePort<float,                         simF32_t>       m_rp_TrajDistY_m;
  SimReceivePort<float,                         simF32_t>       m_rp_TrajHeading__rad;
  SimReceivePort<float,                         simF32_t>       m_rp_TrajHeadingInclPreview__rad;
  SimReceivePort<float,                         simF32_t>       m_rp_TgtTrajCrv__1pm;
  SimReceivePort<float,                         simF32_t>       m_rp_TgtTrajCrvGrd__1pms;
  SimReceivePort<float,                         simF32_t>       m_rp_LtcyComp_RightCorridorCrv__1pm;
  SimReceivePort<float,                         simF32_t>       m_rp_CtrlErrDistY_m;
  SimReceivePort<float,                         simF32_t>       m_rp_CtrlErrHeadingAngle__rad;
  SimReceivePort<float,                         simF32_t>       m_rp_TgtCrv_NoDE__1pm;
  SimReceivePort<float,                         simF32_t>       m_rp_TgtCrv_DEWithNoLatSlp__1pm;
  SimReceivePort<float,                         simF32_t>       m_rp_TgtCrv_DE__1pm;
  SimReceivePort<float,                         simF32_t>       m_rp_TgtCrv_Limited__1pm;
  SimReceivePort<float,                         simF32_t>       m_rp_TgtCrv_Gradient__1pms;
  SimReceivePort<unsigned char,                 simUI8_t>       m_rp_TgtVehCtrlQualifier_nu;
  SimReceivePort<unsigned char,                 simUI8_t>       m_rp_TgtCrv_LimiterWarning_nu;
  SimReceivePort<unsigned char,                 simUI8_t>       m_rp_TrjCtrQualifierService_nu;
  SimReceivePort<unsigned char,                 simUI8_t>       m_rp_QuStatusTrajPlan_nu;
  SimReceivePort<unsigned char,                 simUI8_t>       m_rp_LaDmcQualifierService_nu;
  SimReceivePort<unsigned short,                simUI16_t>      m_rp_Veh2Sen_EventId_nu_0_;
  SimReceivePort<unsigned short,                simUI16_t>      m_rp_Veh2Sen_EventLifetime_nu_0_;
  SimReceivePort<unsigned short,                simUI16_t>      m_rp_Veh2Sen_EventId_nu_1_;
  SimReceivePort<unsigned short,                simUI16_t>      m_rp_Veh2Sen_EventLifetime_nu_1_;
  SimReceivePort<unsigned short,                simUI16_t>      m_rp_Veh2Sen_EventId_nu_2_;
  SimReceivePort<unsigned short,                simUI16_t>      m_rp_Veh2Sen_EventLifetime_nu_2_;
  SimReceivePort<unsigned short,                simUI16_t>      m_rp_Veh2Sen_EventId_nu_3_;
  SimReceivePort<unsigned short,                simUI16_t>      m_rp_Veh2Sen_EventLifetime_nu_3_;
  SimReceivePort<unsigned short,                simUI16_t>      m_rp_Veh2Sen_EventId_nu_4_;
  SimReceivePort<unsigned short,                simUI16_t>      m_rp_Veh2Sen_EventLifetime_nu_4_;
  SimReceivePort<unsigned int,                  simUI32_t>      m_rp_Veh2Sen_uiVersionNumber;
  SimReceivePort<unsigned int,                  simUI32_t>      m_rp_Veh2Sen_uiTimeStamp;
  SimReceivePort<unsigned short,                simUI16_t>      m_rp_Veh2Sen_uiMeasurementCounter;
  SimReceivePort<unsigned short,                simUI16_t>      m_rp_Veh2Sen_uiCycleCounter;
  SimReceivePort<unsigned char,                 simUI8_t>       m_rp_Veh2Sen_eSigStatus;

  /* LCF Algo Comp Sen Signals */
  SimReceivePort<unsigned int,                  simUI32_t>      m_rp_CompSen_uiVersionNumber;
  SimReceivePort<unsigned int,                  simUI32_t>      m_rp_CompSen_uiTimeStamp;
  SimReceivePort<unsigned short,                simUI16_t>      m_rp_CompSen_uiMeasurementCounter;
  SimReceivePort<unsigned short,                simUI16_t>      m_rp_CompSen_uiCycleCounter;
  SimReceivePort<unsigned char,                 simUI8_t>       m_rp_CompSen_eSigStatus;
  SimReceivePort<unsigned int,                  simUI32_t>      m_rp_Sen_uiAlgoVersionNumber;
  SimReceivePort<unsigned int,                  simUI32_t>      m_rp_Sen_uiApplicationNumber;
  SimReceivePort<unsigned char,                 simUI8_t>       m_rp_Sen_eCompState;
  SimReceivePort<unsigned char,                 simUI8_t>       m_rp_Sen_eShedulerSubModeRequest;
  SimReceivePort<unsigned int,                  simUI32_t>      m_rp_Sen_eErrorCode;
  SimReceivePort<unsigned int,                  simUI32_t>      m_rp_Sen_eGenAlgoQualifier;
									    
  /* LCF Algo Comp Veh Signals */	    
  SimReceivePort<unsigned int,                  simUI32_t>      m_rp_CompVeh_uiVersionNumber;
  SimReceivePort<unsigned int,                  simUI32_t>      m_rp_CompVeh_uiTimeStamp;
  SimReceivePort<unsigned short,                simUI16_t>      m_rp_CompVeh_uiMeasurementCounter;
  SimReceivePort<unsigned short,                simUI16_t>      m_rp_CompVeh_uiCycleCounter;
  SimReceivePort<unsigned char,                 simUI8_t>       m_rp_CompVeh_eSigStatus;
  SimReceivePort<unsigned int,                  simUI32_t>      m_rp_Veh_uiAlgoVersionNumber;
  SimReceivePort<unsigned int,                  simUI32_t>      m_rp_Veh_uiApplicationNumber;
  SimReceivePort<unsigned char,                 simUI8_t>       m_rp_Veh_eCompState;
  SimReceivePort<unsigned char,                 simUI8_t>       m_rp_Veh_eShedulerSubModeRequest;
  SimReceivePort<unsigned int,                  simUI32_t>      m_rp_Veh_eErrorCode;
  SimReceivePort<unsigned int,                  simUI32_t>      m_rp_Veh_eGenAlgoQualifier;

  /* LCF Generic Inputs Signals */
  SimReceivePort<float,                         simF32_t>       m_rp_SteerHandWheelAngle__rad;
  SimReceivePort<float,                         simF32_t>       m_rp_SteerHandWheelAngleRate__rps;
  SimReceivePort<float,                         simF32_t>       m_rp_DeltaFSteerAngle__deg;
  SimReceivePort<float,                         simF32_t>       m_rp_DeltaFSteerAngleRate__degps;
  SimReceivePort<float,                         simF32_t>       m_rp_SteerTrq__nm;
  SimReceivePort<float,                         simF32_t>       m_rp_DrvSteerWheelTrq__nm;
  SimReceivePort<float,                         simF32_t>       m_rp_EPS_Motor_Torque__nm;
  SimReceivePort<unsigned char,                 simUI8_t>       m_rp_ESC_SystemState_nu;
  SimReceivePort<unsigned char,                 simUI8_t>       m_rp_ESC_ActiveState_nu;
  SimReceivePort<unsigned char,                 simUI8_t>       m_rp_ABS_SystemState_nu;
  SimReceivePort<unsigned char,                 simUI8_t>       m_rp_ABS_ActiveState_nu;
  SimReceivePort<unsigned char,                 simUI8_t>       m_rp_TCS_SystemState_nu;
  SimReceivePort<unsigned char,                 simUI8_t>       m_rp_TCS_ActiveState_nu;
  SimReceivePort<unsigned char,                 simUI8_t>       m_rp_ACC_SystemState_nu;
  SimReceivePort<unsigned char,                 simUI8_t>       m_rp_ACC_ActiveState_nu;
  SimReceivePort<unsigned char,                 simUI8_t>       m_rp_VSM_SystemState_nu;
  SimReceivePort<unsigned char,                 simUI8_t>       m_rp_VSM_ActiveState_nu;
  SimReceivePort<unsigned char,                 simUI8_t>       m_rp_EBA_SystemState_nu;
  SimReceivePort<unsigned char,                 simUI8_t>       m_rp_EBA_ActiveState_nu;
  SimReceivePort<unsigned char,                 simUI8_t>       m_rp_EBA_WarningState_nu;
  SimReceivePort<unsigned char,                 simUI8_t>       m_rp_TSA_SystemState_nu;
  SimReceivePort<unsigned char,                 simUI8_t>       m_rp_TSA_ActiveState_nu;
  SimReceivePort<unsigned char,                 simUI8_t>       m_rp_DynamometerTestBenchDetected_nu;
  SimReceivePort<unsigned char,                 simUI8_t>       m_rp_DoorOpen_nu;
  SimReceivePort<unsigned char,                 simUI8_t>       m_rp_TurnSignalState_nu;
  SimReceivePort<unsigned char,                 simUI8_t>       m_rp_TurnSignalLever_nu;
  SimReceivePort<unsigned char,                 simUI8_t>       m_rp_VehicleReadyState_nu;
  SimReceivePort<unsigned char,                 simUI8_t>       m_rp_DriverNotBuckledUp_nu;
  SimReceivePort<unsigned char,                 simUI8_t>       m_rp_OversteeringDetected_nu;
  SimReceivePort<unsigned char,                 simUI8_t>       m_rp_UndersteeringDetected_nu;
  SimReceivePort<float,                         simF32_t>       m_rp_BankAngle__rad;
  SimReceivePort<float,                         simF32_t>       m_rp_TieRodLoad__n;
  SimReceivePort<unsigned char,                 simUI8_t>       m_rp_EPS_Toi_Unavail_nu;
  SimReceivePort<unsigned char,                 simUI8_t>       m_rp_EPS_Toi_Active_nu;
  SimReceivePort<unsigned char,                 simUI8_t>       m_rp_EPS_Toi_Flt_nu;
  SimReceivePort<unsigned char,                 simUI8_t>       m_rp_EPS_Fail_Stat_nu;
  SimReceivePort<unsigned char,                 simUI8_t>       m_rp_EPS_Def_nu;
  SimReceivePort<unsigned char,                 simUI8_t>       m_rp_LKAMainSwitch_nu;
  SimReceivePort<unsigned char,                 simUI8_t>       m_rp_LKAMode_nu;
  SimReceivePort<unsigned char,                 simUI8_t>       m_rp_TJAMainSwitch_nu;
  SimReceivePort<unsigned char,                 simUI8_t>       m_rp_TJAMode_nu;
  SimReceivePort<unsigned char,                 simUI8_t>       m_rp_VibrationActState_nu;
  SimReceivePort<unsigned char,                 simUI8_t>       m_rp_SideMirrorLEDState_nu;
  SimReceivePort<unsigned char,                 simUI8_t>       m_rp_LDWSwitch_nu;
  SimReceivePort<unsigned char,                 simUI8_t>       m_rp_LDPSwitch_nu;
  SimReceivePort<unsigned char,                 simUI8_t>       m_rp_RDWSwitch_nu;
  SimReceivePort<unsigned char,                 simUI8_t>       m_rp_RDPSwitch_nu;
  SimReceivePort<unsigned char,                 simUI8_t>       m_rp_LDPOncomingSwitch_nu;
  #if ((LCF_INPUT_INTFVER >= 18) && (LCF_INPUT_INTFVER < 30)) /* RTE used for AES has a higher version */ 
  SimReceivePort<unsigned char,                 simUI8_t>       m_rp_AoLCSwitch_nu;
  SimReceivePort<unsigned char,                 simUI8_t>       m_rp_LDWOncomingSwitch_nu;
  SimReceivePort<unsigned char,                 simUI8_t>       m_rp_LDWOCSensitivity_nu;
  #endif
  SimReceivePort<unsigned char,                 simUI8_t>       m_rp_LDWSensitivity_nu;
  SimReceivePort<unsigned char,                 simUI8_t>       m_rp_LDPSensitivity_nu;
  SimReceivePort<unsigned char,                 simUI8_t>       m_rp_RDPSensitivity_nu;
  #if ((LCF_INPUT_INTFVER >= 18) && (LCF_INPUT_INTFVER < 30)) /* RTE used for AES has a higher version */ 
  SimReceivePort<unsigned char,                 simUI8_t>       m_rp_RDWSensitivity_nu;
  SimReceivePort<unsigned char,                 simUI8_t>       m_rp_LDPMode_nu;
  SimReceivePort<unsigned char,                 simUI8_t>       m_rp_LDWMode_nu;
  SimReceivePort<unsigned char,                 simUI8_t>       m_rp_RDPMode_nu;
  SimReceivePort<unsigned char,                 simUI8_t>       m_rp_RDWMode_nu;
  SimReceivePort<unsigned char,                 simUI8_t>       m_rp_LDPOCMode_nu;
  SimReceivePort<unsigned char,                 simUI8_t>       m_rp_LDWOCMode_nu;
  SimReceivePort<unsigned char,                 simUI8_t>       m_rp_AoLCMode_nu;
  #endif
  SimReceivePort<unsigned char,                 simUI8_t>       m_rp_DriverHandsOff_nu;
  SimReceivePort<unsigned char,                 simUI8_t>       m_rp_SCCActive_nu;
  SimReceivePort<unsigned char,                 simUI8_t>       m_rp_USMReset_nu;
  SimReceivePort<unsigned char,                 simUI8_t>       m_rp_HDAOn_nu;
  SimReceivePort<unsigned char,                 simUI8_t>       m_rp_SCCOn_nu;
  SimReceivePort<unsigned char,                 simUI8_t>       m_rp_USMSetSpd__kph;
  SimReceivePort<unsigned char,                 simUI8_t>       m_rp_NAVIRoadType_nu;
  SimReceivePort<unsigned char,                 simUI8_t>       m_rp_NAVISegFormOfWay_nu;
  SimReceivePort<unsigned char,                 simUI8_t>       m_rp_NAVISegSpeedLim__kph;
  SimReceivePort<unsigned char,                 simUI8_t>       m_rp_NAVIStatus_nu;
  SimReceivePort<unsigned char,                 simUI8_t>       m_rp_NAVIProlProfType_nu;
  SimReceivePort<unsigned char,                 simUI8_t>       m_rp_NAVITollgateDet_nu;
  SimReceivePort<unsigned short,                simUI16_t>      m_rp_NAVITgDetDistOffset_m;
  SimReceivePort<unsigned short,                simUI16_t>      m_rp_NAVIPosOffset_m;
  SimReceivePort<unsigned char,                 simUI8_t>       m_rp_NAVIProlCyclicCount_nu;
  SimReceivePort<unsigned char,                 simUI8_t>       m_rp_NAVIPosCyclicCount_nu;
  SimReceivePort<unsigned char,                 simUI8_t>       m_rp_HDAExtFailFlag_nu;
  SimReceivePort<unsigned char,                 simUI8_t>       m_rp_SCCMainMode_nu;
  SimReceivePort<unsigned char,                 simUI8_t>       m_rp_NAVISpeedUnit_nu;
  SimReceivePort<unsigned char,                 simUI8_t>       m_rp_AlwaysHandsOn_nu;
  SimReceivePort<float,                         simF32_t>       m_rp_AccelPedalPos_nu;
  SimReceivePort<unsigned char,                 simUI8_t>       m_rp_LcfVariantInfo_nu;
  SimReceivePort<unsigned char,                 simUI8_t>       m_rp_DanRearObjBS_RearLeft_nu;
  SimReceivePort<unsigned char,                 simUI8_t>       m_rp_DanRearObjFOV_RearLeft_nu;
  SimReceivePort<unsigned char,                 simUI8_t>       m_rp_OIQualifierFlag_RearLeft_nu;
  SimReceivePort<unsigned char,                 simUI8_t>       m_rp_MSFlag_RearLeft_nu;
  SimReceivePort<unsigned char,                 simUI8_t>       m_rp_DanRearObjBS_RearRight_nu;
  SimReceivePort<unsigned char,                 simUI8_t>       m_rp_DanRearObjFOV_RearRight_nu;
  SimReceivePort<unsigned char,                 simUI8_t>       m_rp_OIQualifierFlag_RearRight_nu;
  SimReceivePort<unsigned char,                 simUI8_t>       m_rp_MSFlag_RearRight_nu;
  SimReceivePort<unsigned char,                 simUI8_t>       m_rp_ALCASwitch_nu;
  SimReceivePort<unsigned char,                 simUI8_t>       m_rp_ALCASensitivity_nu;
  SimReceivePort<unsigned char,                 simUI8_t>       m_rp_ALCAMode_nu;
  SimReceivePort<unsigned char,                 simUI8_t>       m_rp_LCA_Active_Left_nu;
  SimReceivePort<unsigned char,                 simUI8_t>       m_rp_BSD_Active_Left_nu;
  SimReceivePort<unsigned char,                 simUI8_t>       m_rp_LCA_Warning_Left_nu;
  SimReceivePort<unsigned char,                 simUI8_t>       m_rp_BSD_Warning_Left_nu;
  SimReceivePort<unsigned char,                 simUI8_t>       m_rp_LCA_Active_Right_nu;
  SimReceivePort<unsigned char,                 simUI8_t>       m_rp_BSD_Active_Right_nu;
  SimReceivePort<unsigned char,                 simUI8_t>       m_rp_LCA_Warning_Right_nu;
  SimReceivePort<unsigned char,                 simUI8_t>       m_rp_BSD_Warning_Right_nu;
  SimReceivePort<unsigned char,                 simUI8_t>       m_rp_HapticWrnDeviceLeftState_nu;
  SimReceivePort<unsigned char,                 simUI8_t>       m_rp_HapticWrnDeviceRightState_nu;
  SimReceivePort<unsigned char,                 simUI8_t>       m_rp_HapticWrnDeviceCommonState_nu;
  SimReceivePort<unsigned char,                 simUI8_t>       m_rp_HapticWrnDeviceLeftMode_nu;
  SimReceivePort<unsigned char,                 simUI8_t>       m_rp_HapticWrnDeviceRightMode_nu;
  SimReceivePort<unsigned char,                 simUI8_t>       m_rp_HapticWrnDeviceCommonMode_nu;
  SimReceivePort<unsigned char,                 simUI8_t>       m_rp_VisualWrnDeviceLeftState_nu;
  SimReceivePort<unsigned char,                 simUI8_t>       m_rp_VisualWrnDeviceRightState_nu;
  SimReceivePort<unsigned char,                 simUI8_t>       m_rp_VisualWrnDeviceCommonState_nu;
  SimReceivePort<unsigned char,                 simUI8_t>       m_rp_VisualWrnDeviceLeftMode_nu;
  SimReceivePort<unsigned char,                 simUI8_t>       m_rp_VisualWrnDeviceRightMode_nu;
  SimReceivePort<unsigned char,                 simUI8_t>       m_rp_VisualWrnDeviceCommonMode_nu;
  SimReceivePort<unsigned char,                 simUI8_t>       m_rp_LDPOCSensitivity_nu;
  SimReceivePort<unsigned char,                 simUI8_t>       m_rp_AoLCSensitivity_nu;
  SimReceivePort<unsigned char,                 simUI8_t>       m_rp_TJALatCtrlActive_nu;
  SimReceivePort<unsigned char,                 simUI8_t>       m_rp_TJAHandsOffWrnEnable_nu;
  SimReceivePort<unsigned char,                 simUI8_t>       m_rp_EPSSteerCtrlMode_nu;
  SimReceivePort<unsigned char,                 simUI8_t>       m_rp_EPSECUActFact_nu;
  SimReceivePort<unsigned char,                 simUI8_t>       m_rp_EPSDriverIntervention_nu;
  SimReceivePort<float,                         simF32_t>       m_rp_EPSReqTrq__nm;
  SimReceivePort<float,                         simF32_t>       m_rp_EPSMotTrq__nm;
  SimReceivePort<float,                         simF32_t>       m_rp_EPSMotAngSpd__degps;
  SimReceivePort<float,                         simF32_t>       m_rp_EPSReqStAng__deg;
  #if ((LCF_INPUT_INTFVER >= 18) && (LCF_INPUT_INTFVER < 30)) /* RTE used for AES has a higher version */ 
  SimReceivePort<unsigned char,                 simUI8_t>       m_rp_SteerWheelAngSensorStatus_nu;
  SimReceivePort<unsigned char,                 simUI8_t>       m_rp_CommunicationLostEps_nu;
  SimReceivePort<unsigned char,                 simUI8_t>       m_rp_CommunicationLostSCS_nu;
  SimReceivePort<unsigned char,                 simUI8_t>       m_rp_CommunicationLostTCM_nu;
  SimReceivePort<float,                         simF32_t>       m_rp_MainCylPressure_pa;
  SimReceivePort<unsigned char,                 simUI8_t>       m_rp_TerrainMode_nu;
  #endif
  SimReceivePort<float,                         simF32_t>       m_rp_ASLRNG_nu;
  SimReceivePort<float,                         simF32_t>       m_rp_GOS_Lamp_nu;
  SimReceivePort<float,                         simF32_t>       m_rp_GOS_Multi_inf_nu;
  SimReceivePort<float,                         simF32_t>       m_rp_CWA_Activation_nu;
  SimReceivePort<float,                         simF32_t>       m_rp_PCS_Destination_nu;
  SimReceivePort<float,                         simF32_t>       m_rp_PCS_AES_invalid_flag1_nu;
  SimReceivePort<unsigned char,                 simUI8_t>       m_rp_DangOcObjLe_nu;
  SimReceivePort<unsigned char,                 simUI8_t>       m_rp_DangOcObjRi_nu;
  SimReceivePort<unsigned char,                 simUI8_t>       m_rp_QuDangOcObjDtct_nu;
  #if ((LCF_INPUT_INTFVER >= 18) && (LCF_INPUT_INTFVER < 30)) /* RTE used for AES has a higher version */
  SimReceivePort<unsigned char,                 simUI8_t>       m_rp_ObjectStationaryLeft_nu;
  SimReceivePort<unsigned char,                 simUI8_t>       m_rp_ObjectStationaryRight_nu;
  SimReceivePort<unsigned char,                 simUI8_t>       m_rp_ObjectSensitiveLeft_nu;
  SimReceivePort<unsigned char,                 simUI8_t>       m_rp_ObjectSensitiveRight_nu;
  #endif
  SimReceivePort<float,                         simF32_t>       m_rp_TSEGapLongDistEgoToTarget_m;
  SimReceivePort<float,                         simF32_t>       m_rp_TSEGapLongDistEgoToTargetPRE_m;
  SimReceivePort<float,                         simF32_t>       m_rp_TSETargetLongVel_mps;
  SimReceivePort<float,                         simF32_t>       m_rp_TSETargetLongAccel_mps2;
  SimReceivePort<float,                         simF32_t>       m_rp_TSEKappaEvasiveCorrRight__1pm;
  SimReceivePort<float,                         simF32_t>       m_rp_TSEGapLatDistEgoToCorrLeft_m;
  SimReceivePort<float,                         simF32_t>       m_rp_TSEGapLatDistEgoToCorrRight_m;
  SimReceivePort<float,                         simF32_t>       m_rp_TSEGapLatDistObjToCorrLeft_m;
  SimReceivePort<float,                         simF32_t>       m_rp_TSEGapLatDistObjToCorrRight_m;
  SimReceivePort<unsigned char,                 simUI8_t>       m_rp_TSEAEBAcuteDynWarnFCTChan_nu;
  SimReceivePort<unsigned char,                 simUI8_t>       m_rp_TSEAEBAcuteDynWarnSigState_nu;
  SimReceivePort<unsigned char,                 simUI8_t>       m_rp_TSEStatusFunctionEPF_nu;
  SimReceivePort<float,                         simF32_t>       m_rp_TSEAEBAnecLongAccel_mpss;
  SimReceivePort<unsigned int,                  simUI32_t>      m_rp_LCF_GenInput_uiVersionNumber;
  SimReceivePort<unsigned int,                  simUI32_t>      m_rp_LCF_GenInput_uiTimeStamp;
  SimReceivePort<unsigned short,                simUI16_t>      m_rp_LCF_GenInput_uiMeasurementCounter;
  SimReceivePort<unsigned short,                simUI16_t>      m_rp_LCF_GenInput_uiCycleCounter;
  SimReceivePort<unsigned char,                 simUI8_t>       m_rp_LCF_GenInput_eSigStatus;
  /* Get SOC Version to be easier to identify a MFC CP */
  SimReceivePort<unsigned int,                 simUI32_t>      m_rp_SOC_u_VersionNumber;

  #if (GET_LCF_PRJ_NR() == GET_LCFPRJ_MFC431LO19())
  /* MFC431LO19 Specific Signals */
  SimReceivePort<unsigned short,				simUI16_t>      m_rp_D_LSCCTR_PreconditionsOK_btf;
  SimReceivePort<unsigned short,				simUI16_t>      m_rp_D_LSCCTR_PrjSpecQu_btf;
  SimReceivePort<unsigned short,				simUI16_t>      m_rp_D_HMOLCO_SysStateHWA_btf;
  SimReceivePort<unsigned char,					simUI8_t>       m_rp_S_HMOLCO_ActFctEnabled_bool;
  SimReceivePort<unsigned char,					simUI8_t>       m_rp_S_HMOLCO_ActFctLevel_nu;
  SimReceivePort<unsigned char,					simUI8_t>       m_rp_S_HMOLCO_CnclReqForCrsCtrl_nu;
  SimReceivePort<unsigned char,				    simUI8_t>       m_rp_S_HMOLCO_HWAStatus_nu;
  SimReceivePort<unsigned char,				    simUI8_t>       m_rp_S_HMOLCO_HapticWrnReq_nu;
  SimReceivePort<unsigned char,			        simUI8_t>       m_rp_S_HMOLCO_LDWState_nu;
  SimReceivePort<unsigned char,			        simUI8_t>		m_rp_S_HMOLCO_LKAState_nu;
  SimReceivePort<unsigned char,			        simUI8_t>		m_rp_S_HMOLCO_LaneDetectionStatusForHWA_nu;
  SimReceivePort<unsigned char,			        simUI8_t>		m_rp_S_HMOLCO_LaneDetectionStatus_nu;
  SimReceivePort<unsigned char,			        simUI8_t>		m_rp_S_HMOLCO_SteerActiveOK_bool;
  SimReceivePort<unsigned char,			        simUI8_t>		m_rp_S_HMOLCO_SteerStandbyOK_bool;
  SimReceivePort<unsigned char,			        simUI8_t>		m_rp_S_HMOLCO_StsForLatAutDrv_nu;
  SimReceivePort<unsigned char,			        simUI8_t>		m_rp_S_HMOLCO_SysWarning_nu;
  SimReceivePort<unsigned char,			        simUI8_t>		m_rp_S_HMOLCO_WarnForLatAutDrv_nu;
  SimReceivePort<unsigned char,			        simUI8_t>		m_rp_S_HMOLCO_WarnReqHWA_nu;
  SimReceivePort<unsigned char,			        simUI8_t>		m_rp_S_HMOLCO_eLKAState_nu;

  #elif (GET_LCF_PRJ_NR() == GET_LCFPRJ_MFC431TA19())
  /* MFC431TA19 Specific Signals */
  SimReceivePort<unsigned short,				simUI16_t>      m_rp_S_TSCCTR_PrjSpecQu_btf;
  SimReceivePort<unsigned char,					simUI8_t>       m_rp_S_TSCLDA_PrjSpecQu_btf;
  SimReceivePort<unsigned char,					simUI8_t>       m_rp_S_TSCLTA_PrjSpecQu_btf;
  SimReceivePort<unsigned int,					simUI32_t>      m_rp_D_TSCLTA_HmiCancelWarningQu_btf;
  SimReceivePort<unsigned char,					simUI8_t>       m_rp_S_TSCLTA_HmiCancelWarningQu_nu;
  SimReceivePort<unsigned char,					simUI8_t>       m_rp_S_TSCLTA_LDAIndiOffReq_bool;
  SimReceivePort<unsigned char,				    simUI8_t>       m_rp_S_TSCLTA_SysGainDec_bool;
  SimReceivePort<float,						    simF32_t>       m_rp_D_TSCLDA_LDPMode2DispVel_kph;
  SimReceivePort<unsigned char,			        simUI8_t>       m_rp_D_TSCLDA_ObjLeDetect_bool;
  SimReceivePort<unsigned char,			        simUI8_t>		m_rp_D_TSCLDA_ObjRiDetect_bool;
  SimReceivePort<unsigned char,			        simUI8_t>		m_rp_D_TSCLDA_OneSideLnReDtct_bool;
  SimReceivePort<unsigned char,			        simUI8_t>		m_rp_D_TSCLDA_Precondition_bool;
  SimReceivePort<float,						    simF32_t>		m_rp_D_TSCLDA_RoadWidth_met;
  SimReceivePort<float,						    simF32_t>		m_rp_D_TSCLDA_TMCCurvGLeLn_mps2;
  SimReceivePort<float,						    simF32_t>		m_rp_D_TSCLDA_TMCCurvGLeRe_mps2;
  SimReceivePort<float,						    simF32_t>		m_rp_D_TSCLDA_TMCCurvGRiLn_mps2;
  SimReceivePort<float,						    simF32_t>		m_rp_D_TSCLDA_TMCCurvGRiRe_mps2;
  SimReceivePort<unsigned char,			        simUI8_t>		m_rp_D_TSCLDA_TurnSignalLeft_bool;
  SimReceivePort<unsigned char,			        simUI8_t>		m_rp_D_TSCLDA_TurnSignalRight_bool;
  SimReceivePort<float,						    simF32_t>		m_rp_D_TSCLDA_VehVelYLeLn_mps;
  SimReceivePort<float,						    simF32_t>		m_rp_D_TSCLDA_VehVelYLeRe_mps;
  SimReceivePort<float,						    simF32_t>		m_rp_D_TSCLDA_VehVelYRiLn_mps;
  SimReceivePort<float,						    simF32_t>		m_rp_D_TSCLDA_VehVelYRiRe_mps;
  SimReceivePort<unsigned char,			        simUI8_t>		m_rp_S_TSCLDA_LDPModeCustom_st;
  #endif

//#ifdef LCF_VEH_PPORT_PNVMLCFDATA  //TODO: delete this line in next release  
//  SimReceivePort<NVM_LcfLearningData_t,         simOPAQUE_t>    m_rpNvmLcfData;
//#endif
  
  /// Additional data to be memorized on a receive port
  struct SimReceivePortInfo
  {
    unsigned char errorCount;
    bool          checkForData;
  };

  /// Map type representing additional data per port
  typedef std::map<SimReceivePortBase*, SimReceivePortInfo> ReceivePortMap_t;

  /// Available receive ports with additional data
  ReceivePortMap_t m_receivePortMap;
  /// @}

  LCF_VehGenericOutputs_t      m_LcfVehOutputData;
  LCF_VehToSen_t               m_LcfVehOutputToSenData;
  LCF_SenGenericOutputs_t      m_LcfSenOutputData;
  LCF_SenToVeh_t               m_LcfSenOutputToVehData;
  LCF_GenericInputs_t          m_LcfInputData;
#if defined(LCF_SEN_RPORT_PHLARADAROBJECTLIST)
  HLA_RadarObjectList_t        m_HLA_RadarObjectListData;
#endif
#if defined(LCF_SEN_RPORT_PLSDENVIRONMENTDATA)
  LSD_EnvironmentData_t        m_LSD_EnvironmentData;
#endif
#if defined(LCF_SEN_RPORT_PCBOUTPUTS)
  CB_t_ProvidedOutputs_t       m_CB_t_ProvidedOutputs;
#endif
  AbdOutputData_t              m_AbdOutputData;   
  VehPar_t                     m_VehPar; 
  VehSig_t                     m_VehSig; 
  VehDyn_t                     m_VehDyn;
  LCF_SenDebugData_t		   m_LCF_SenDebugData;
  LCF_VehDebugData_t		   m_LCF_VehDebugData;
  AlgoCompState_t		       m_LCF_SenAlgoCompState;
  AlgoCompState_t		       m_LCF_VehAlgoCompState;

  TJASideObject_t              m_LCF_TJASideObject;
  TJATargetObject_t			   m_LCF_TJATargetObject;

  LCF_TrajPlanCorridor_t	   m_LCF_SenOut_LeftLaneCorridor;
  LCF_TrajPlanCorridor_t	   m_LCF_SenOut_RightLaneCorridor;
  LCF_TrajPlanCorridor_t	   m_LCF_SenOut_TargetCorridor;
  
//#ifdef LCF_VEH_PPORT_PNVMLCFDATA  //TODO: delete this line in next release  
//  NVM_LcfLearningData_t        m_NvmLcfData;
//#endif
  
  bool              m_bLcfVehOutputDataValid; 
  bool              m_bLcfVehOutputToSenDataValid; 
  bool              m_bLcfSenOutputDataValid; 
  bool              m_bLcfSenOutputToVehDataValid; 
  bool              m_bLcfInputDataValid; 
  bool              m_bLDOutputDataValid;
  bool              m_bHlaRadarObjectList;
  bool              m_bLsdEnvironmentData;
  bool              m_bCbOutputs;
  bool              m_bAbdOutputDataValid;  
  bool              m_bVehParValid; 
  bool              m_bVehSigValid;
  bool              m_bVehDynValid;
  bool				m_bLCFSenDebugDataValid;
  bool				m_bLCFVehDebugDataValid;
  bool				m_bLCFSenAlgoCompState;
  bool				m_bLCFVehAlgoCompState;
  bool			    m_SenOut_LeftLaneCorridorValid;
  bool			    m_SenOut_RightLaneCorridorValid;
  bool			    m_SenOut_TargetCorridorValid;
  unsigned char		DebugSelect;
  unsigned char		BitfiledSel_idx;
  unsigned char		ERRIO_Select;
  unsigned char     SelectTrajDraw;
  bool				m_bDrawHelp;
  unsigned char		m_ResolutionMode;
  std::vector<unsigned int>		m_Function_Activation_Number;

  LCF_Scheduler_Check_t LCF_SEN_Scheduler_Info;
  LCF_Scheduler_Check_t LCF_VEH_Scheduler_Info;

//  bool              m_bNvmLcfDataValid;
  
  BITFIELDMAP LcfCSVData;

  void Reset();
  void Doit();
  bool IsRequiredDataAvailable();
  void SetupPorts();
  void ResetReceiveErrors();
  
  const char* LcofLatCtrlModeToString(unsigned char input, char* debs);
  const char* LcofSysStateToString(unsigned char input, char* debs);
  const char* GetProjectName(unsigned char ProjectNo, char* debs);

  const char* CtrlFunctionToString(unsigned char input, char* debs);
  const char* LaneValidQualifToString(unsigned char input, char* debs);
  const char* LDParallelModeToString(unsigned char input, char* debs);

  void Get_Bitfield_Information(LCF_Bitfield_Info &Structure, unsigned int Signal_Value, string Name, const STRINGLIST &Info_Signal, unsigned char size, bool PortConnected, unsigned char IgnoreBit);

  void Add_LD_Signals(IGDVFont& font, int start_y_coord, int x_coord_c1, int x_coord_c2, unsigned short y_offset_inc, bool ValidData);
  void Add_VehDyn_Signals(IGDVFont& font, int start_y_coord, int x_coord_c1, unsigned short offset, unsigned short y_offset_inc, bool ValidData);
  void Add_LcfGenPort_Signals(IGDVFont& font, int start_y_coord, int x_coord_c1, unsigned short offset, unsigned short y_offset_inc, unsigned char idxSelect);
  void Add_Output_Signals(IGDVFont& font, int start_y_coord, int x_coord_c1, unsigned short offset, unsigned short y_offset_inc, unsigned char idxSelect, bool *Data_Validity);

  void DrawTextLCF(int x_coord, int y_coord, unsigned short offset, RGBAColor & colorTxt, RGBAColor & colorVal, std::string const & sText, IGDVFont& rFont, const char *value, const unsigned char InfoKey = 0);

  void Add_Common_Debug_Signals(IGDVFont& font, int start_y_coord, int x_coord_c1, unsigned short offset, unsigned short y_offset_inc, bool ValidData);
  void Add_Customer_Signals(IGDVFont& font, int start_y_coord, int x_coord_c3, unsigned short offset, unsigned short y_offset_inc, bool ValidData);
  void Add_TJA_Debug_Signals(IGDVFont& font, int start_y_coord, int x_coord_c3, unsigned short offset, unsigned short y_offset_inc, bool ValidData);
  void Add_LDP_Debug_Signals(IGDVFont& font, int start_y_coord, int x_coord_c3, unsigned short offset, unsigned short y_offset_inc, bool ValidData);
  void Add_LDW_Debug_Signals(IGDVFont& font, int start_y_coord, int x_coord_c3, unsigned short offset, unsigned short y_offset_inc, bool ValidData);
  void Add_RDP_Debug_Signals(IGDVFont& font, int start_y_coord, int x_coord_c3, unsigned short offset, unsigned short y_offset_inc, bool ValidData);
  void Add_ErrorHandler_Debug_Signals(IGDVFont& font, int start_y_coord, int x_coord_c1, unsigned short offset, unsigned short y_offset_inc, bool ValidData);
  void Add_LCFIntegration_Debug_Signals(IGDVFont& font, int start_y_coord, int x_coord_c1, unsigned short offset, unsigned short y_offset_inc, bool ValidData);
  void Add_DRVMN_Debug_Signals(IGDVFont& font, int start_y_coord, int x_coord_c1, unsigned short offset, unsigned short y_offset_inc, bool ValidData);

  void DrawHelp(IGDVFont& font, IGDVFont& titlefont);

  void DrawLcfLaneMarker( LCF_TrajPlanCorridor_t* corridor, GL::Color color );
  void DrawABDMarker( AbdOutputData_t* laneStruct, unsigned int lanePosition, unsigned int laneType, GL::Color color );
  void DrawLcfGraphic( const ISimRenderContext& ctx );
  void DrawLDGraphic( const ISimRenderContext& ctx );
  void DrawLcfInfo( const ISimRenderContext& ctx );
  void DrawLcfHMIInfo( const ISimRenderContext& ctx );
  void DrawLCFLegend( const ISimRenderContext& ctx );
  void DrawLcfStatusInfo( const ISimRenderContext& ctx );
  void DrawLcfFunctionTable( const ISimRenderContext& ctx );
  void DrawLcfTrajectory( GL::Color color );
  void DrawLCFTableDebug(const ISimRenderContext& ctx );
  void DrawLCFBitfieldInfo(const ISimRenderContext& ctx );

  void StatisticalData(unsigned Timestamp, LCF_e_FctSystemState_t* FunctionSysState);
  void CSimLcfVis::LCF_SchedulerData(LCF_Scheduler_Check_t &Scheduler_Info, const unsigned int Timestamp, const unsigned short CycleCounter, float TaskCycleTime);

  // Function to fetch data from a CSV File
  STRINGLIST ParseComma(std::string line);
  BITFIELDMAP getData(std::string& fileName);

  static CVersionInfoImpl CreateVersionInfoFromI32 (const long version);
};

typedef struct point{
	float x; //coordinate on the horizontal axis
	float y; //coordinate on the vertical axis
}point;

typedef struct {
//maximum 5th grade polynomial coefficients
	float a_5;//x^5
	float a_4;//x^4
	float a_3;//x^3
	float a_2;//x^2
	float a_1;//x^1
	float a_0;//x^0
}poly_coef;

void LCFDrawCircle(float cx, float cy, float r, unsigned int num_segments);
void LCFDrawFilledCircle(float cx, float cy, float r, unsigned int num_segments);
point rotate_point(point , float , point );
point translate_point(point , float , float );
poly_coef poly_fitting(point* );

#endif // sim_swc_lcf_vis_h__
