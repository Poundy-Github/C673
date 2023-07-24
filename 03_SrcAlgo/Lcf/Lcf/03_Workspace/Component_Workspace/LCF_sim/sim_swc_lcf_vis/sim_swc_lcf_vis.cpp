/*! \file **********************************************************************

TEMPLATE VERSION:          1.2
changed parameters in cpp version to be a struct/class
added version management for template

*/

#include "stdafx.h"
#include <vis_gl.h>

#include "resource.h"
#include "sim_swc_lcf_vis.h"
#include "sim_swc_lcf_vis_version.h"
#include "sim_swc_dbg_exc.h"
#include <stdio.h>
#include <string>
#include <sstream>
#include <direct.h>
#include <math.h>

#define CHECK_BIT(var,pos) ((var) & (1<<(pos)))
#define CHECK_MAPPING(map, key, valid)		((map.find(key) != map.end()) ? map[key] : (valid ? map["Key_NotFound"] : map["CSV_Not_Loaded"]))

#define CHECK_DLC_LEFT(Signal_Port, Thresold)				(((Signal_Port.isConnected()) && (Thresold.isConnected())) ? ((Signal_Port.val() > Thresold.val()) ? (colorLime) : (colorOrange)) : (colorRed))
#define CHECK_DLC_RIGHT(Signal_Port, Thresold)				(((Signal_Port.isConnected()) && (Thresold.isConnected())) ? ((Signal_Port.val() < Thresold.val()) ? (colorLime) : (colorOrange)) : (colorRed))
#define CHECK_IS_CONNECTED(Signal_Port)						((Signal_Port.isConnected()) ? (colorLime) : (colorRed))
#define CHECK_PORT_AVAIL(MTS_Port, string)					((MTS_Port.isConnected()) ? (LcofValueToString(MTS_Port.val(), string)) : ("Not connected"))
#define GET_SIGNAL_VALUE(MTS_Port, Signal, string)			((MTS_Port.isConnected()) ? (LcofValueToString(Signal, string)) : ("Not connected"))
#define CHECK_PORT_AVAIL_SYSSTATE(MTS_Port, string)			((MTS_Port.isConnected()) ? (LcofSysStateToString(MTS_Port.val(), string)) : ("Not connected"))
#define CHECK_PORT_AVAIL_MODCTRL(MTS_Port, string)			((MTS_Port.isConnected()) ? (CtrlFunctionToString(MTS_Port.val(), string)) : ("Not connected"))
#define CHECK_PORT_ARRAY_AVAIL(MTS_Port, index, string)		((MTS_Port.isConnected()) ? (LcofValueToString(MTS_Port.val()[index], string)) : ("Not connected"))
#define convByteToBit(signal)	((unsigned char)(signal * 8))

#ifndef M_PI
#define M_PI 3.14159265358979323846 //for some reason it still throws a compiler error if not defined here
#endif //M_PI

#define LCF_VIS_LANE_MRKR_NUM_PTS     500.0f  //number of points to draw a lane marker

//asked Mohammed Anwar from LD - these defines do not exist yet
//DEFINES TO BE REPLACED BY DEFINES USED IN LD
enum LDLaneQualityState{

	NOT_AVAILABLE_LDLQS = 0,  // 2022/09/01 Chengyou, Tang : Modify because MFC5J3 project define a MACRO named NOT_AVAILABLE
	VIRTUAL_LANE = 3,
	NEAR_DEATH = 15,
	PREDICTED = 30,
	ROAD_EDGE = 51,
	EXIT_RAMP = 90,
	HIGH_QUALITY = 100

};

enum ABDMarkerPosition{

	ABD_EGO_MARKER = 0,
	ABD_EGO_ADJACENT_MARKER = 1,
	ABD_ROAD_EDGE = 2

};
//DEFINES TO BE REPLACED BY DEFINES USED IN LD

//image size in pixels
const uint32 imageWidth = 1024;
const uint32 imageHeight = 640;

// the client port names
const char* CSimLcfVis::CP_CALCULATIONDONE = "CalculationDone";


CSimLcfVis::CSimLcfVis()
: CSimSwcDrawBase (10, "__BufferDataID", simI64_t, "__DoStore", "..\\gia_sim\\adapter.dll")
, m_rpLcfVehOutputData     (this, "pLcfVehOutputData", LCF_VehGenericOutputs_t())
, m_rpLcfVehOutputToSenData(this, "pLcfVehOutputToSenData", LCF_VehToSen_t())
, m_rpLcfSenOutputData     (this, "pLcfSenOutputData", LCF_SenGenericOutputs_t())
, m_rpLcfSenOutputToVehData(this, "pLcfSenOutputToVehData", LCF_SenToVeh_t())
, m_rpLcfInputData         (this, "pLcfInputData", LCF_GenericInputs_t())
#if defined(LCF_SEN_RPORT_PHLARADAROBJECTLIST)
, m_rpHlaRadarObjectList   (this, "pHlaRadarObjectList", HLA_RadarObjectList_t())
#endif
#if defined(LCF_SEN_RPORT_PLSDENVIRONMENTDATA)
, m_rpLsdEnvironmentData   (this, "pLsdEnvironmentData", LSD_EnvironmentData_t())
#endif
#if defined(LCF_SEN_RPORT_PCBOUTPUTS)
, m_rpCbOutputs    		   (this, "pCbOutputs ", CB_t_ProvidedOutputs_t())
#endif
, m_rpAbdOutputData        (this, "pAbdOutputData", AbdOutputData_t())
, m_rpVehPar               (this, "pVehPar", VehPar_t())
, m_rpVehSig               (this, "pVehSig", VehSig_t())
, m_rpVehDyn               (this, "pVehDyn", VehDyn_t())
, m_rpLCF_SenDebugData     (this, "pLcfSenDebugData", LCF_SenDebugData_t())
, m_rpLCF_VehDebugData     (this, "pLcfVehDebugData", LCF_VehDebugData_t())
, m_rpLCF_SenAlgoCompState (this, "pAlgoSenCompState", AlgoCompState_t())
, m_rpLCF_VehAlgoCompState (this, "pAlgoVehCompState", AlgoCompState_t())

, m_rpLCF_TJASideObject	   (this, "pLcf_TJASideObject", TJASideObject_t())
, m_rpLCF_TJATargetObject  (this, "pLcf_TJATargetObject", TJATargetObject_t())

/* TJA signals */
, m_rp_D_TJALKA_LaneCenterInvalid_btf			(this, "pLcf_D_TJALKA_LaneCenterInvalid_btf",       unsigned short())
, m_rp_D_TJALKA_LaneInvalid_btf					(this, "pLcf_D_TJALKA_LaneInvalid_btf",             unsigned short())
, m_rp_S_TJALKA_LanePredictValid_bool			(this, "pLcf_S_TJALKA_LanePredictValid_bool",		unsigned char())
, m_rp_S_TJALKA_LnBndValid_nu					(this, "pLcf_S_TJALKA_LnBndValid_nu",				unsigned char())
, m_rp_S_TJALKA_StrongReady_bool				(this, "pLcf_S_TJALKA_StrongReady_bool",			unsigned char())
, m_rp_S_TJALKA_WeakReady_bool					(this, "pLcf_S_TJALKA_WeakReady_bool",			    unsigned char())
, m_rp_D_TJAOBF_ObjFollowInvalid_btf			(this, "pLcf_D_TJAOBF_ObjFollowInvalid_btf",	    unsigned short())
, m_rp_D_TJAOBF_ObjInLaneInvalid_btf			(this, "pLcf_D_TJAOBF_ObjInLaneInvalid_btf",	    unsigned short())
, m_rp_D_TJAOBF_TgtObjDataInvalid_btf			(this, "pLcf_D_TJAOBF_TgtObjDataInvalid_btf",	    unsigned char())
, m_rp_S_TJAOBF_AccObjValid_bool				(this, "pLcf_S_TJAOBF_AccObjValid_bool",			unsigned char())
, m_rp_S_TJAOBF_StrongReady_bool				(this, "pLcf_S_TJAOBF_StrongReady_bool",		    unsigned char())
, m_rp_S_TJAOBF_WeakReady_bool					(this, "pLcf_S_TJAOBF_WeakReady_bool",			    unsigned char())
, m_rp_S_TJACMB_StrongReady_bool				(this, "pLcf_S_TJACMB_StrongReady_bool",		    unsigned char())
, m_rp_D_TJAGEN_StrongReadyInvalid_btf			(this, "pLcf_D_TJAGEN_StrongReadyInvalid_btf",	    unsigned char())
, m_rp_D_TJAGEN_WeakReadyInvalid_btf			(this, "pLcf_D_TJAGEN_WeakReadyInvalid_btf",		unsigned char())
, m_rp_D_TJAGEN_CancelStatus_btf				(this, "pLcf_D_TJAGEN_CancelStatus_btf",		    unsigned char())
, m_rp_D_TJASTM_TJAInvalid_btf					(this, "pLcf_D_TJASTM_TJAInvalid_btf",		        unsigned short())
, m_rp_D_TJACMB_CombinedInvalid_btf			    (this, "pLcf_D_TJACMB_CombinedInvalid_btf",		    unsigned short())

/* ODPR signals */
, m_rp_S_ODPFOP_AccObjPosX_met					(this, "pLcf_S_ODPFOP_AccObjPosX_met",			    float())
, m_rp_S_ODPFOP_AccObjPosY_met			    	(this, "pLcf_S_ODPFOP_AccObjPosY_met",		        float())
, m_rp_S_ODPFOP_AccObjRelAclX_mps2		    	(this, "pLcf_S_ODPFOP_AccObjRelAclX_mps2",	        float())
, m_rp_S_ODPFOP_AccObjRelAclY_mps2		    	(this, "pLcf_S_ODPFOP_AccObjRelAclY_mps2",			float())
, m_rp_S_ODPFOP_AccObjRelVelX_mps				(this, "pLcf_S_ODPFOP_AccObjRelVelX_mps",		    float())
, m_rp_S_ODPFOP_AccObjRelVelY_mps				(this, "pLcf_S_ODPFOP_AccObjRelVelY_mps",		    float())
, m_rp_S_ODPFOP_EstimatedObjPosX_met		    (this, "pLcf_S_ODPFOP_EstimatedObjPosX_met",	    float())
, m_rp_S_ODPFOP_EstimatedObjPosY_met			(this, "pLcf_S_ODPFOP_EstimatedObjPosY_met",	    float())
, m_rp_S_ODPFOP_AccObjInvBitfield_btf			(this, "pLcf_S_ODPFOP_AccObjInvBitfield_btf",	    unsigned short())

/* VDPR signals */
, m_rp_S_VDPDRV_VehStInvalid_btf				(this, "pLcf_S_VDPDRV_VehStInvalid_btf",		    unsigned short())
, m_rp_S_VDPDRV_ActiveStCtrl_btf				(this, "pLcf_S_VDPDRV_ActiveStCtrl_btf",		    unsigned char())
, m_rp_S_VDPDRV_DrvStInvalid_btf			    (this, "pLcf_S_VDPDRV_DrvStInvalid_btf",	        unsigned char())
, m_rp_S_VDPDRV_SysStError_btf					(this, "pLcf_S_VDPDRV_SysStError_btf",	            unsigned char())
, m_rp_S_VDPDRV_SysStNotAvailable_btf			(this, "pLcf_S_VDPDRV_SysStNotAvailable_btf",	    unsigned char())

/* ABPR signals */
, m_rp_S_ABPLBP_LaneWidth_met					(this, "pLcf_S_ABPLBP_LaneWidth_met",		        float())
, m_rp_S_ABPLBP_LeLnClthPosY0_met				(this, "pLcf_S_ABPLBP_LeLnClthPosY0_met",		    float())
, m_rp_S_ABPLBP_LeLnClthPosY0SIF_met			(this, "pLcf_S_ABPLBP_LeLnClthPosY0SIF_met",	    float())
, m_rp_S_ABPLBP_RiLnClthPosY0_met				(this, "pLcf_S_ABPLBP_RiLnClthPosY0_met",	        float())
, m_rp_S_ABPLBP_RiLnClthPosY0SIF_met			(this, "pLcf_S_ABPLBP_RiLnClthPosY0SIF_met",	    float())
, m_rp_S_ABPLBP_LeLnInvalidQu_btf				(this, "pLcf_S_ABPLBP_LeLnInvalidQu_btf",	        unsigned short())
, m_rp_S_ABPLBP_RiLnInvalidQu_btf				(this, "pLcf_S_ABPLBP_RiLnInvalidQu_btf",		    unsigned short())
, m_rp_S_ABPLBP_ConstructionSite_bool			(this, "pLcf_S_ABPLBP_ConstructionSite_bool",	    unsigned char())
, m_rp_S_ABPLBP_CntrLnKalmanStatus_nu			(this, "pLcf_S_ABPLBP_CntrLnKalmanStatus_nu",		unsigned char())
, m_rp_S_ABPLBP_LeLnClthLength_met				(this, "pLcf_S_ABPLBP_LeLnClthLength_met",	        float())
, m_rp_S_ABPLBP_RiLnClthLength_met				(this, "pLcf_S_ABPLBP_RiLnClthLength_met",	        float())
, m_rp_S_ABPLBP_LeLnQuality_perc				(this, "pLcf_S_ABPLBP_LeLnQuality_perc",		    unsigned char())
, m_rp_S_ABPLBP_RiLnQuality_perc				(this, "pLcf_S_ABPLBP_RiLnQuality_perc",		    unsigned char())
, m_rp_S_ABPLBP_LaneValidQualVis_nu				(this, "pLcf_S_ABPLBP_LaneValidQualVis_nu",		    unsigned char())
, m_rp_S_ABPREP_LeRePosY0_met					(this, "pLcf_S_ABPREP_LeRePosY0_met",				float())
, m_rp_S_ABPREP_RiRePosY0_met					(this, "pLcf_S_ABPREP_RiRePosY0_met",			    float())
, m_rp_S_ABPREP_LeReInvalidQu_btf				(this, "pLcf_S_ABPREP_LeReInvalidQu_btf",	        unsigned short())
, m_rp_S_ABPREP_RiReInvalidQu_btf				(this, "pLcf_S_ABPREP_RiReInvalidQu_btf",		    unsigned short())

/* LDP signals */
, m_rp_S_DPLSIA_DlcLeLDP_met					(this, "pLcf_S_DPLSIA_DlcLeLDP_met",		        float())
, m_rp_D_DPLSMI_DlcLeThreshold_met				(this, "pLcf_D_DPLSMI_DlcLeThreshold_met",		    float())
, m_rp_S_DPLSIA_DlcRiLDP_met					(this, "pLcf_S_DPLSIA_DlcRiLDP_met",			    float())
, m_rp_D_DPLSMI_DlcRiThreshold_met				(this, "pLcf_D_DPLSMI_DlcRiThreshold_met",	        float())
, m_rp_S_DPLSIA_TlcLeLDP_sec					(this, "pLcf_S_DPLSIA_TlcLeLDP_sec",		        float())
, m_rp_D_DPLSMI_TlcLeThreshold_sec				(this, "pLcf_D_DPLSMI_TlcLeThreshold_sec",		    float())
, m_rp_S_DPLSIA_TlcRiLDP_sec					(this, "pLcf_S_DPLSIA_TlcRiLDP_sec",			    float())
, m_rp_D_DPLSMI_TlcRiThreshold_sec				(this, "pLcf_D_DPLSMI_TlcRiThreshold_sec",	        float())
, m_rp_S_DPLSIA_VelLatLeLDP_mps					(this, "pLcf_S_DPLSIA_VelLatLeLDP_mps",		        float())
, m_rp_S_DPLSIA_VelLatRiLDP_mps					(this, "pLcf_S_DPLSIA_VelLatRiLDP_mps",				float())
, m_rp_S_DPLSIA_LnBndValidLDP_nu				(this, "pLcf_S_DPLSIA_LnBndValidLDP_nu",			unsigned char())
, m_rp_S_DPLSIA_SideCondLDPLe_btf				(this, "pLcf_S_DPLSIA_SideCondLDPLe_btf",	        unsigned char())
, m_rp_S_DPLSIA_SideCondLDPRi_btf				(this, "pLcf_S_DPLSIA_SideCondLDPRi_btf",	        unsigned char())
, m_rp_S_DPLSIA_SpecificLDP_btf					(this, "pLcf_S_DPLSIA_SpecificLDP_btf",				unsigned char())
, m_rp_D_DPLSMI_Cancel_btf						(this, "pLcf_D_DPLSMI_Cancel_btf",					unsigned char())
, m_rp_D_DPLSMI_StrongReady_btf					(this, "pLcf_D_DPLSMI_StrongReady_btf",				unsigned char())
, m_rp_D_DPLSMI_SysStateLDP_btf					(this, "pLcf_D_DPLSMI_SysStateLDP_btf",			    unsigned char())
, m_rp_D_DPLSMI_WeakReady_btf					(this, "pLcf_D_DPLSMI_WeakReady_btf",				unsigned char())
, m_rp_S_DPLSMI_DangerousSide_nu				(this, "pLcf_S_DPLSMI_DangerousSide_nu",		    unsigned char())
, m_rp_S_DPLSMI_ReadyToTrigger_bool				(this, "pLcf_S_DPLSMI_ReadyToTrigger_bool",		    unsigned char())

/* LDW signals */
, m_rp_S_DPLSIA_DlcLeLDW_met					(this, "pLcf_S_DPLSIA_DlcLeLDW_met",		        float())
, m_rp_D_DPLSMW_DlcLeThreshold_met				(this, "pLcf_D_DPLSMW_DlcLeThreshold_met",		    float())
, m_rp_S_DPLSIA_DlcRiLDW_met					(this, "pLcf_S_DPLSIA_DlcRiLDW_met",			    float())
, m_rp_D_DPLSMW_DlcRiThreshold_met				(this, "pLcf_D_DPLSMW_DlcRiThreshold_met",	        float())
, m_rp_S_DPLSIA_TlcLeLDW_sec					(this, "pLcf_S_DPLSIA_TlcLeLDW_sec",		        float())
, m_rp_D_DPLSMW_TlcLeThreshold_sec				(this, "pLcf_D_DPLSMW_TlcLeThreshold_sec",		    float())
, m_rp_S_DPLSIA_TlcRiLDW_sec					(this, "pLcf_S_DPLSIA_TlcRiLDW_sec",			    float())
, m_rp_D_DPLSMW_TlcRiThreshold_sec				(this, "pLcf_D_DPLSMW_TlcRiThreshold_sec",	        float())
, m_rp_S_DPLSIA_VelLatLeLDW_mps					(this, "pLcf_S_DPLSIA_VelLatLeLDW_mps",		        float())
, m_rp_S_DPLSIA_VelLatRiLDW_mps					(this, "pLcf_S_DPLSIA_VelLatRiLDW_mps",				float())
, m_rp_S_DPLSIA_LnBndValidLDW_nu				(this, "pLcf_S_DPLSIA_LnBndValidLDW_nu",			unsigned char())
, m_rp_S_DPLSIA_SideCondLDWLe_btf				(this, "pLcf_S_DPLSIA_SideCondLDWLe_btf",	        unsigned char())
, m_rp_S_DPLSIA_SideCondLDWRi_btf				(this, "pLcf_S_DPLSIA_SideCondLDWRi_btf",	        unsigned char())
, m_rp_S_DPLSIA_SpecificLDW_btf					(this, "pLcf_S_DPLSIA_SpecificLDW_btf",				unsigned char())
, m_rp_D_DPLSMW_Cancel_btf						(this, "pLcf_D_DPLSMW_Cancel_btf",					unsigned char())
, m_rp_D_DPLSMW_StrongReady_btf					(this, "pLcf_D_DPLSMW_StrongReady_btf",				unsigned char())
, m_rp_D_DPLSMW_SysStateLDW_btf					(this, "pLcf_D_DPLSMW_SysStateLDW_btf",			    unsigned char())
, m_rp_D_DPLSMW_WeakReady_btf					(this, "pLcf_D_DPLSMW_WeakReady_btf",				unsigned char())
, m_rp_S_DPLSMW_DangerousSide_nu				(this, "pLcf_S_DPLSMW_DangerousSide_nu",		    unsigned char())
, m_rp_S_DPLSMW_ReadyToTrigger_bool				(this, "pLcf_S_DPLSMW_ReadyToTrigger_bool",		    unsigned char())

/* RDP signals */
, m_rp_S_DPRSIA_DrcLeRDP_met					(this, "pLcf_S_DPRSIA_DrcLeRDP_met",		        float())
, m_rp_D_DPRSMI_DrcLeThreshold_met				(this, "pLcf_D_DPRSMI_DrcLeThreshold_met",	        float())
, m_rp_S_DPRSIA_DrcRiRDP_met					(this, "pLcf_S_DPRSIA_DrcRiRDP_met",				float())
, m_rp_D_DPRSMI_DrcRiThreshold_met				(this, "pLcf_D_DPRSMI_DrcRiThreshold_met",	        float())
, m_rp_S_DPRSIA_DlcLeRDP_met					(this, "pLcf_S_DPRSIA_DlcLeRDP_met",		        float())
, m_rp_D_DPRSMI_DlcLeThreshold_met				(this, "pLcf_D_DPRSMI_DlcLeThreshold_met",	        float())
, m_rp_S_DPRSIA_DlcRiRDP_met					(this, "pLcf_S_DPRSIA_DlcRiRDP_met",				float())
, m_rp_D_DPRSMI_DlcRiThreshold_met				(this, "pLcf_D_DPRSMI_DlcRiThreshold_met",	        float())
, m_rp_S_DPRSIA_VelLatReLeRDP_mps				(this, "pLcf_S_DPRSIA_VelLatReLeRDP_mps",			float())
, m_rp_S_DPRSIA_VelLatReRiRDP_mps				(this, "pLcf_S_DPRSIA_VelLatReRiRDP_mps",	        float())
, m_rp_S_DPRSIA_TgtCntrLnEnable_bool			(this, "pLcf_S_DPRSIA_TgtCntrLnEnable_bool",	    unsigned char())
, m_rp_S_DPRSIA_LaneWidthRDP_met				(this, "pLcf_S_DPRSIA_LaneWidthRDP_met",		    float())
, m_rp_S_DPRSIA_LnBndValidRDP_nu				(this, "pLcf_S_DPRSIA_LnBndValidRDP_nu",	        unsigned char())
, m_rp_S_DPRSIA_RdBndValidRDP_nu				(this, "pLcf_S_DPRSIA_RdBndValidRDP_nu",	        unsigned char())
, m_rp_S_DPRSIA_SideCondRDPLe_btf				(this, "pLcf_S_DPRSIA_SideCondRDPLe_btf",			unsigned char())
, m_rp_S_DPRSIA_SideCondRDPRi_btf				(this, "pLcf_S_DPRSIA_SideCondRDPRi_btf",			unsigned char())
, m_rp_S_DPRSIA_SpecificRDP_btf					(this, "pLcf_S_DPRSIA_SpecificRDP_btf",		        unsigned char())
, m_rp_D_DPRSMI_Cancel_btf						(this, "pLcf_D_DPRSMI_Cancel_btf",					unsigned char())
, m_rp_D_DPRSMI_StrongReady_btf					(this, "pLcf_D_DPRSMI_StrongReady_btf",				unsigned char())
, m_rp_D_DPRSMI_SysStateRDP_btf					(this, "pLcf_D_DPRSMI_SysStateRDP_btf",				unsigned char())
, m_rp_D_DPRSMI_WeakReady_btf					(this, "pLcf_D_DPRSMI_WeakReady_btf",				unsigned char())
, m_rp_S_DPRSMI_DangerousSide_nu				(this, "pLcf_S_DPRSMI_DangerousSide_nu",		    unsigned char())
, m_rp_S_DPRSMI_TriggerReason_nu				(this, "pLcf_S_DPRSMI_TriggerReason_nu",			unsigned char())
, m_rp_S_DPRSMI_ReadyToTrigger_bool				(this, "pLcf_S_DPRSMI_ReadyToTrigger_bool",			unsigned char())

/* LCF SEN Integration signals */
, m_rp_D_LCFSEN_proPorts_NullStatusCheck		(this, "pLcf_D_LCFSEN_proPorts_NullStatusCheck",		unsigned short())
, m_rp_D_LCFSEN_reqPorts_NullStatusCheck		(this, "pLcf_D_LCFSEN_reqPorts_NullStatusCheck",		unsigned int())
, m_rp_D_LCFSEN_services_NullStatusCheck		(this, "pLcf_D_LCFSEN_services_NullStatusCheck",		unsigned short())
, m_rp_D_LCFSEN_reqPorts_SignalStatusOk			(this, "pLcf_D_LCFSEN_reqPorts_SignalStatusOk",		    unsigned int())
, m_rp_D_LCFSEN_reqPorts_SignalStatusInit		(this, "pLcf_D_LCFSEN_reqPorts_SignalStatusInit",		unsigned int())
, m_rp_D_LCFSEN_reqPorts_SignalStatusInvalid	(this, "pLcf_D_LCFSEN_reqPorts_SignalStatusInvalid",	unsigned int())
, m_rp_D_LCFSEN_reqPorts_VersionNumberCheck		(this, "pLcf_D_LCFSEN_reqPorts_VersionNumberCheck",		unsigned int())
, m_rp_uiSenTunParCopied						(this, "pLcf_uiSenTunParCopied",						unsigned char())
, m_rp_uiSenVdyParCopied						(this, "pLcf_uiSenVdyParCopied",						unsigned char())

/* LCF VEH Integration signals */
, m_rp_D_LCFVEH_proPorts_NullStatusCheck		(this, "pLcf_D_LCFVEH_proPorts_NullStatusCheck",		unsigned short())
, m_rp_D_LCFVEH_reqPorts_NullStatusCheck		(this, "pLcf_D_LCFVEH_reqPorts_NullStatusCheck",		unsigned short())
, m_rp_D_LCFVEH_services_NullStatusCheck		(this, "pLcf_D_LCFVEH_services_NullStatusCheck",		unsigned short())
, m_rp_D_LCFVEH_reqPorts_SignalStatusOk			(this, "pLcf_D_LCFVEH_reqPorts_SignalStatusOk",		    unsigned short())
, m_rp_D_LCFVEH_reqPorts_SignalStatusInit		(this, "pLcf_D_LCFVEH_reqPorts_SignalStatusInit",		unsigned short())
, m_rp_D_LCFVEH_reqPorts_SignalStatusInvalid	(this, "pLcf_D_LCFVEH_reqPorts_SignalStatusInvalid",	unsigned short())
, m_rp_D_LCFVEH_reqPorts_VersionNumberCheck		(this, "pLcf_D_LCFVEH_reqPorts_VersionNumberCheck",	    unsigned short())
, m_rp_uiVehTunParCopied						(this, "pLcf_uiVehTunParCopied",						unsigned char())
, m_rp_uiVehVdyParCopied						(this, "pLcf_uiVehVdyParCopied",						unsigned char())
, m_rp_uiVehNvmDataValid						(this, "pLcf_uiVehNvmDataValid",						unsigned char())

/* LCF SEN Error Handler signals */
, m_rp_D_LCFERR_ErrorConfirmedNorm_btf			(this, "pLcf_D_LCFERR_ErrorConfirmedNorm_btf",			unsigned int())
, m_rp_D_LCFERR_ErrorConfirmedVDY_btf			(this, "pLcf_D_LCFERR_ErrorConfirmedVDY_btf",			unsigned char())
, m_rp_D_LCFERR_ErrorConfirmedVSA_btf			(this, "pLcf_D_LCFERR_ErrorConfirmedVSA_btf",			unsigned char())
, m_rp_D_LCFERR_ErrorConfirmedVSM_btf			(this, "pLcf_D_LCFERR_ErrorConfirmedVSM_btf",			unsigned char())
, m_rp_D_LCFERR_AlliveFailedTSMon_btf			(this, "pLcf_D_LCFERR_AlliveFailedTSMon_btf",		    unsigned short())
, m_rp_D_LCFERR_AlliveFailedTSBcd_btf			(this, "pLcf_D_LCFERR_AlliveFailedTSBcd_btf",			unsigned short())
, m_rp_D_LCFERR_AlliveFailedMC_btf				(this, "pLcf_D_LCFERR_AlliveFailedMC_btf",				unsigned short())
, m_rp_D_LCFERR_AlliveFailedCCMon_btf			(this, "pLcf_D_LCFERR_AlliveFailedCCMon_btf",	        unsigned short())
, m_rp_D_LCFERR_AlliveFailedCCConst_btf			(this, "pLcf_D_LCFERR_AlliveFailedCCConst_btf",			unsigned short())
, m_rp_D_LCFERR_AlgoCompState					(this, "pLcf_D_LCFERR_AlgoCompState",					unsigned char())
, m_rp_D_LCFERR_SenOutSigStatus					(this, "pLcf_D_LCFERR_SenOutSigStatus",					unsigned char())
, m_rp_D_LCFERR_Sen2VehSigStatus				(this, "pLcf_D_LCFERR_Sen2VehSigStatus",				unsigned char())
, m_rp_D_LCFERR_DemEvents_btf					(this, "pLcf_D_LCFERR_DemEvents_btf",					unsigned char())
, m_rp_D_ERRIOSEN_ErrStateArray					(this, "pLcf_D_ERRIOSEN_ErrStateArray",					unsigned char())
, m_rp_D_LCFERR_RngChkDbg_btf					(this, "pLcf_D_LCFERR_RngChkDbg_btf",					unsigned int())

/* Error Handler LCF Veh */
, m_rp_D_LCFERR_Veh_ErrorConfirmedNorm_btf		(this, "pLcf_D_LCFERR_Veh_ErrorConfirmedNorm_btf",		unsigned int())
, m_rp_D_LCFERR_Veh_ErrorConfirmedVDY_btf		(this, "pLcf_D_LCFERR_Veh_ErrorConfirmedVDY_btf",		unsigned char())
, m_rp_D_LCFERR_Veh_ErrorConfirmedVSA_btf		(this, "pLcf_D_LCFERR_Veh_ErrorConfirmedVSA_btf",		unsigned char())
, m_rp_D_LCFERR_Veh_ErrorConfirmedVSM_btf		(this, "pLcf_D_LCFERR_Veh_ErrorConfirmedVSM_btf",		unsigned char())
, m_rp_D_LCFERR_Veh_AlliveFailedTSMon_btf		(this, "pLcf_D_LCFERR_Veh_AlliveFailedTSMon_btf",	    unsigned short())
, m_rp_D_LCFERR_Veh_AlliveFailedTSBcd_btf		(this, "pLcf_D_LCFERR_Veh_AlliveFailedTSBcd_btf",		unsigned short())
, m_rp_D_LCFERR_Veh_AlliveFailedMC_btf			(this, "pLcf_D_LCFERR_Veh_AlliveFailedMC_btf",			unsigned short())
, m_rp_D_LCFERR_Veh_AlliveFailedCCMon_btf		(this, "pLcf_D_LCFERR_Veh_AlliveFailedCCMon_btf",	    unsigned short())
, m_rp_D_LCFERR_Veh_AlliveFailedCCConst_btf		(this, "pLcf_D_LCFERR_Veh_AlliveFailedCCConst_btf",		unsigned short())
, m_rp_D_LCFERR_Veh_AlgoCompState				(this, "pLcf_D_LCFERR_Veh_AlgoCompState",				unsigned char())
, m_rp_D_LCFERR_Veh_VehOutSigStatus				(this, "pLcf_D_LCFERR_Veh_VehOutSigStatus",				unsigned char())
, m_rp_D_LCFERR_Veh_Veh2SenSigStatus			(this, "pLcf_D_LCFERR_Veh_Veh2SenSigStatus",			unsigned char())
, m_rp_D_LCFERR_Veh_Soc2IucSigStatus			(this, "pLcf_D_LCFERR_Veh_Soc2IucSigStatus",			unsigned char())
, m_rp_D_LCFERR_Veh_DemEvents_btf				(this, "pLcf_D_LCFERR_Veh_DemEvents_btf",				unsigned char())
, m_rp_D_ERRIOVEH_ErrStateArray					(this, "pLcf_D_ERRIOVEH_ErrStateArray",					unsigned char())
, m_rp_D_LCFERR_Veh_RngChkDbg_btf				(this, "pLcf_D_LCFERR_Veh_RngChkDbg_btf",				unsigned int())

/* TrajPlan signals */
, m_rp_D_TPLLCO_DeltaProjPosX_met				(this, "pLcf_D_TPLLCO_DeltaProjPosX_met",				float())
, m_rp_D_TPLLCO_DeltaProjPosY_met				(this, "pLcf_D_TPLLCO_DeltaProjPosY_met",				float())
, m_rp_D_TPLLCO_RightOri_rad					(this, "pLcf_D_TPLLCO_RightOri_rad",					float())
, m_rp_S_TPLTJC_EndPointTrajectory_nu			(this, "pLcf_S_TPLTJC_EndPointTrajectory_nu",		    float())
, m_rp_S_TPLLCO_RightCridrHeading_rad			(this, "pLcf_S_TPLLCO_RightCridrHeading_rad",			float())
, m_rp_S_TPLLCO_RightCorridorCrv_1pm			(this, "pLcf_S_TPLLCO_RightCorridorCrv_1pm",			float())
, m_rp_S_TPLLCO_RiCridrChngOfCrv_1pm2			(this, "pLcf_S_TPLLCO_RiCridrChngOfCrv_1pm2",	        float())
, m_rp_S_TPLTJC_TrajParam_nu					(this, "pLcf_S_TPLTJC_TrajParam_nu",					float())

/* Driver Monitoring Signals */
, m_rp_S_DRMDAE_AbuseWarning_bool				(this, "pLcf_S_DRMDAE_AbuseWarning_bool",				unsigned char())
, m_rp_S_DRMDAE_SysWarning_nu					(this, "pLcf_S_DRMDAE_SysWarning_nu",					unsigned char())
, m_rp_D_DRMHOD_EstHandTor_Nm					(this, "pLcf_D_DRMHOD_EstHandTor_Nm",					float())
, m_rp_S_DRMHOD_HandsOffConfirmed_bool			(this, "pLcf_S_DRMHOD_HandsOffConfirmed_bool",		    unsigned char())

/* LCF SEN Output Signals */
, m_rp_LDWSystemState_nu                       (this, "pLcf_LDWSystemState_nu",                       unsigned char())
, m_rp_LDWSystemStateLeft_nu                   (this, "pLcf_LDWSystemStateLeft_nu",                   unsigned char())
, m_rp_LDWSystemStateRight_nu                  (this, "pLcf_LDWSystemStateRight_nu",                  unsigned char())
, m_rp_LDPSystemState_nu                       (this, "pLcf_LDPSystemState_nu",                       unsigned char())
, m_rp_LDPSystemStateLeft_nu                   (this, "pLcf_LDPSystemStateLeft_nu",                   unsigned char())
, m_rp_LDPSystemStateRight_nu                  (this, "pLcf_LDPSystemStateRight_nu",                  unsigned char())
, m_rp_RDPSystemState_nu                       (this, "pLcf_RDPSystemState_nu",                       unsigned char())
, m_rp_RDPSystemStateLeft_nu                   (this, "pLcf_RDPSystemStateLeft_nu",                   unsigned char())
, m_rp_RDPSystemStateRight_nu                  (this, "pLcf_RDPSystemStateRight_nu",                  unsigned char())
, m_rp_TJASystemState_nu                       (this, "pLcf_TJASystemState_nu",                       unsigned char())
, m_rp_TJALatCtrlMode_nu                       (this, "pLcf_TJALatCtrlMode_nu",                       unsigned char())
, m_rp_LaneRecogState_nu                       (this, "pLcf_LaneRecogState_nu",                       unsigned char())
, m_rp_HapticWrnDeviceLeftReq_nu               (this, "pLcf_HapticWrnDeviceLeftReq_nu",               unsigned char())
, m_rp_HapticWrnDeviceRightReq_nu              (this, "pLcf_HapticWrnDeviceRightReq_nu",              unsigned char())
, m_rp_HapticWrnDeviceCommonReq_nu             (this, "pLcf_HapticWrnDeviceCommonReq_nu",             unsigned char())
, m_rp_VisualWrnDeviceLeftReq_nu               (this, "pLcf_VisualWrnDeviceLeftReq_nu",               unsigned char())
, m_rp_VisualWrnDeviceRightReq_nu              (this, "pLcf_VisualWrnDeviceRightReq_nu",              unsigned char())
, m_rp_VisualWrnDeviceCommonReq_nu             (this, "pLcf_VisualWrnDeviceCommonReq_nu",             unsigned char())
, m_rp_LaneValidQualDMC_nu                     (this, "pLcf_LaneValidQualDMC_nu",                     unsigned char())
, m_rp_HandsOffSysWarning_nu                   (this, "pLcf_HandsOffSysWarning_nu",                   unsigned char())
, m_rp_ErrorStateTJA_nu                        (this, "pLcf_ErrorStateTJA_nu",                        unsigned char())
, m_rp_CustSpecSysStateTJA_nu                  (this, "pLcf_CustSpecSysStateTJA_nu",                  unsigned char())
, m_rp_ErrorStateLDP_nu                        (this, "pLcf_ErrorStateLDP_nu",                        unsigned char())
, m_rp_CustSpecSysStateLDP_nu                  (this, "pLcf_CustSpecSysStateLDP_nu",                  unsigned char())
, m_rp_ErrorStateLDW_nu                        (this, "pLcf_ErrorStateLDW_nu",                        unsigned char())
, m_rp_CustSpecSysStateLDW_nu                  (this, "pLcf_CustSpecSysStateLDW_nu",                  unsigned char())
, m_rp_ErrorStateRDP_nu                        (this, "pLcf_ErrorStateRDP_nu",                        unsigned char())
, m_rp_CustSpecSysStateRDP_nu                  (this, "pLcf_CustSpecSysStateRDP_nu",                  unsigned char())
, m_rp_LCF_Stiffness_nu                        (this, "pLcf_LCF_Stiffness_nu",                        float())
, m_rp_LCF_Accuracy_nu                         (this, "pLcf_LCF_Accuracy_nu",                         float())
, m_rp_TJA_Status_nu                           (this, "pLcf_TJA_Status_nu",                           unsigned char())
, m_rp_DFFunctActiveState_btf                   (this, "pLcf_DFFunctActiveState_btf",                   unsigned short())
, m_rp_LnBndLeValid4Fct_btf                     (this, "pLcf_LnBndLeValid4Fct_btf",                     unsigned char())
, m_rp_LnBndRiValid4Fct_btf                     (this, "pLcf_LnBndRiValid4Fct_btf",                     unsigned char())
, m_rp_DispLaneLeftDetected_nu                  (this, "pLcf_DispLaneLeftDetected_nu",                  unsigned char())
, m_rp_DispLaneRightDetected_nu                 (this, "pLcf_DispLaneRightDetected_nu",                 unsigned char())
, m_rp_SteeringWheelVibrationReq_nu            (this, "pLcf_SteeringWheelVibrationReq_nu",            unsigned char())
, m_rp_DrvAttWarnQualifier_nu                  (this, "pLcf_DrvAttWarnQualifier_nu",                  unsigned char())
, m_rp_TMC_Indi_nu                             (this, "pLcf_TMC_Indi_nu",                             unsigned char())
, m_rp_TMC_LaneDispLeft_nu                     (this, "pLcf_TMC_LaneDispLeft_nu",                     unsigned char())
, m_rp_TMC_LaneDispRight_nu                    (this, "pLcf_TMC_LaneDispRight_nu",                    unsigned char())
, m_rp_TMC_StrgCtrlAct_nu                      (this, "pLcf_TMC_StrgCtrlAct_nu",                      unsigned char())
, m_rp_SenOut_uiVersionNumber                   (this, "pLcf_SenOut_uiVersionNumber",                   unsigned int())
, m_rp_SenOut_uiTimeStamp                       (this, "pLcf_SenOut_uiTimeStamp",                       unsigned int())
, m_rp_SenOut_uiMeasurementCounter              (this, "pLcf_SenOut_uiMeasurementCounter",              unsigned short())
, m_rp_SenOut_uiCycleCounter                    (this, "pLcf_SenOut_uiCycleCounter",                    unsigned short())
, m_rp_SenOut_eSigStatus                        (this, "pLcf_SenOut_eSigStatus",                        unsigned char())
/* OcPa : Take the left corridor / right corridor / target corridor as individual structures to draw the lines in DrawLcfLaneMarker method */
, m_rp_SenOut_LeftLaneCorridor                  (this, "pLcf_SenOut_LeftLaneCorridor",                  LCF_TrajPlanCorridor_t())
, m_rp_SenOut_RightLaneCorridor                 (this, "pLcf_SenOut_RightLaneCorridor",                 LCF_TrajPlanCorridor_t())
, m_rp_SenOut_TargetCorridor                    (this, "pLcf_SenOut_TargetCorridor",                    LCF_TrajPlanCorridor_t())

/* LCF Sen2Veh Output Signals */
, m_rp_ControllingFunction_nu				    (this, "pLcf_ControllingFunction_nu",                   unsigned char())
, m_rp_ActFctEnabled_nu						    (this, "pLcf_ActFctEnabled_nu",                         unsigned char())
, m_rp_ActFctLevel_nu						    (this, "pLcf_ActFctLevel_nu",                           unsigned char())
, m_rp_SpecialDrivingCorridor_nu			    (this, "pLcf_SpecialDrivingCorridor_nu",               unsigned char())
, m_rp_MaxJerkAllowed_mps3					    (this, "pLcf_MaxJerkAllowed_mps3",                      float())
, m_rp_OcObjActSide_nu						    (this, "pLcf_OcObjActSide_nu",                          unsigned char())
, m_rp_AngReqMaxLimitScale_per				    (this, "pLcf_AngReqMaxLimitScale_per",                  unsigned char())
, m_rp_AngReqRateMaxLimitScale_per			    (this, "pLcf_AngReqRateMaxLimitScale_per",              unsigned char())
, m_rp_SysStateLDP_nu						    (this, "pLcf_SysStateLDP_nu",                          unsigned char())
, m_rp_SysStateRDP_nu						    (this, "pLcf_SysStateRDP_nu",                          unsigned char())
, m_rp_SysStateLDW_nu						    (this, "pLcf_SysStateLDW_nu",                          unsigned char())
, m_rp_SysStateLDPOC_nu					    (this, "pLcf_SysStateLDPOC_nu",                        unsigned char())
, m_rp_SysStateALCA_nu						    (this, "pLcf_SysStateALCA_nu",                         unsigned char())
, m_rp_CoordSysStateLCF_nu					    (this, "pLcf_CoordSysStateLCF_nu",                     unsigned char())
, m_rp_SysStateLKA_nu						    (this, "pLcf_SysStateLKA_nu",                          unsigned char())
, m_rp_LatCtrlModeLKA_nu					    (this, "pLcf_LatCtrlModeLKA_nu",                       unsigned char())
, m_rp_SysStateTJA_nu						    (this, "pLcf_SysStateTJA_nu",                          unsigned char())
, m_rp_LatCtrlModeTJA_nu					    (this, "pLcf_LatCtrlModeTJA_nu",                       unsigned char())
, m_rp_LcfCtrlAbort_nu						    (this, "pLcf_LcfCtrlAbort_nu",                         unsigned char())
, m_rp_LnBndValidLKA_nu					    (this, "pLcf_LnBndValidLKA_nu",                        unsigned char())
, m_rp_LnBndValidLDW_nu					    (this, "pLcf_LnBndValidLDW_nu",                        unsigned char())
, m_rp_LnBndValidLDP_nu					    (this, "pLcf_LnBndValidLDP_nu",                        unsigned char())
, m_rp_LnBndValidRDP_nu					    (this, "pLcf_LnBndValidRDP_nu",                        unsigned char())
, m_rp_LnBndValidLDPOC_nu					    (this, "pLcf_LnBndValidLDPOC_nu",                      unsigned char())
, m_rp_LnBndValidTJA_nu					    (this, "pLcf_LnBndValidTJA_nu",                        unsigned char())
, m_rp_LnBndValidALCA_nu					    (this, "pLcf_LnBndValidALCA_nu",                       unsigned char())
, m_rp_LcfFctAvailability_nu				    (this, "pLcf_LcfFctAvailability_nu",                   unsigned short())
, m_rp_ABP_CamCorridorCurvature__1pm		    (this, "pLcf_ABP_CamCorridorCurvature__1pm",            float())
, m_rp_ABP_CamLateralError_m				    (this, "pLcf_ABP_CamLateralError_m",                   float())
, m_rp_ABP_CamHeadingError__rad				    (this, "pLcf_ABP_CamHeadingError__rad",                 float())
, m_rp_Sen2Veh_Reserved1_nu					    (this, "pLcf_Sen2Veh_Reserved1_nu",                     float())
, m_rp_Sen2Veh_Reserved2_nu					    (this, "pLcf_Sen2Veh_Reserved2_nu",                     float())
, m_rp_Sen2Veh_EventId_nu_0_					(this, "pLcf_Sen2Veh_EventId_nu_0_",				    unsigned short())
, m_rp_Sen2Veh_EventLifetime_nu_0_				(this, "pLcf_Sen2Veh_EventLifetime_nu_0_",			    unsigned short())
, m_rp_Sen2Veh_EventId_nu_1_					(this, "pLcf_Sen2Veh_EventId_nu_1_",				    unsigned short())
, m_rp_Sen2Veh_EventLifetime_nu_1_				(this, "pLcf_Sen2Veh_EventLifetime_nu_1_",			    unsigned short())
, m_rp_Sen2Veh_EventId_nu_2_					(this, "pLcf_Sen2Veh_EventId_nu_2_",				    unsigned short())
, m_rp_Sen2Veh_EventLifetime_nu_2_				(this, "pLcf_Sen2Veh_EventLifetime_nu_2_",			    unsigned short())
, m_rp_Sen2Veh_EventId_nu_3_					(this, "pLcf_Sen2Veh_EventId_nu_3_",				    unsigned short())
, m_rp_Sen2Veh_EventLifetime_nu_3_				(this, "pLcf_Sen2Veh_EventLifetime_nu_3_",			    unsigned short())
, m_rp_Sen2Veh_EventId_nu_4_					(this, "pLcf_Sen2Veh_EventId_nu_4_",				    unsigned short())
, m_rp_Sen2Veh_EventLifetime_nu_4_				(this, "pLcf_Sen2Veh_EventLifetime_nu_4_",			    unsigned short())
, m_rp_Sen2Veh_uiVersionNumber					(this, "pLcf_Sen2Veh_uiVersionNumber",				    unsigned int())
, m_rp_Sen2Veh_uiTimeStamp						(this, "pLcf_Sen2Veh_uiTimeStamp",					    unsigned int())
, m_rp_Sen2Veh_uiMeasurementCounter				(this, "pLcf_Sen2Veh_uiMeasurementCounter",			    unsigned short())
, m_rp_Sen2Veh_uiCycleCounter					(this, "pLcf_Sen2Veh_uiCycleCounter",				    unsigned short())
, m_rp_Sen2Veh_eSigStatus						(this, "pLcf_Sen2Veh_eSigStatus",					    unsigned char())

/* LCF VEH Output Signals */
, m_rp_LaDMC_Status_nu                         (this, "pLcf_LaDMC_Status_nu",                         unsigned char())
, m_rp_LaDMC_Eps_Damping_Level_Request__per     (this, "pLcf_LaDMC_Eps_Damping_Level_Request__per",     unsigned char())
, m_rp_Lkas_StrToqReq__nm                       (this, "pLcf_Lkas_StrToqReq__nm",                       float())
, m_rp_Lkas_ActToi_nu                          (this, "pLcf_Lkas_ActToi_nu",                          unsigned char())
, m_rp_Lkas_ToiFlt_nu                          (this, "pLcf_Lkas_ToiFlt_nu",                          unsigned char())
, m_rp_Lkas_SteeringAngleRate__rps              (this, "pLcf_Lkas_SteeringAngleRate__rps",              float())
, m_rp_LaKMC_CrvCmd_Sum__1pm                    (this, "pLcf_LaKMC_CrvCmd_Sum__1pm",                    float())
, m_rp_LaKMC_CrvCmd_FF__1pm                     (this, "pLcf_LaKMC_CrvCmd_FF__1pm",                     float())
, m_rp_LaKMC_CrvCmd_Ctrl__1pm                   (this, "pLcf_LaKMC_CrvCmd_Ctrl__1pm",                   float())
, m_rp_LaKMC_QuTgtVehCtrl_nu                   (this, "pLcf_LaKMC_QuTgtVehCtrl_nu",                   unsigned char())
, m_rp_LaDMC_StrAngReq__deg                     (this, "pLcf_LaDMC_StrAngReq__deg",                     float())
, m_rp_LaDMC_StrAngEst__deg                     (this, "pLcf_LaDMC_StrAngEst__deg",                     float())
, m_rp_LaDMC_ActFunc_nu                        (this, "pLcf_LaDMC_ActFunc_nu",                        unsigned char())
, m_rp_LaDMC_DeratingFactorReq_nu              (this, "pLcf_LaDMC_DeratingFactorReq_nu",              float())
, m_rp_LaDMC_StiffnessReq_nu                   (this, "pLcf_LaDMC_StiffnessReq_nu",                   float())
, m_rp_LaDMC_AccuracyReq_nu                    (this, "pLcf_LaDMC_AccuracyReq_nu",                    float())
, m_rp_LaDMC_SteerAngReqQF_nu                  (this, "pLcf_LaDMC_SteerAngReqQF_nu",                  unsigned char())
, m_rp_LaDMC_YawRateReqQF_nu                   (this, "pLcf_LaDMC_YawRateReqQF_nu",                   unsigned char())
, m_rp_TMC_DdrData1_nu                         (this, "pLcf_TMC_DdrData1_nu",                         unsigned char())
, m_rp_TMC_DdrData2_nu                         (this, "pLcf_TMC_DdrData2_nu",                         unsigned char())
, m_rp_TMC_DdrData3_nu                         (this, "pLcf_TMC_DdrData3_nu",                         unsigned char())
, m_rp_TSEAESSysState_nu                       (this, "pLcf_TSEAESSysState_nu",                       unsigned char())
, m_rp_VehOut_uiVersionNumber                   (this, "pLcf_VehOut_uiVersionNumber",                   unsigned int())
, m_rp_VehOut_uiTimeStamp                       (this, "pLcf_VehOut_uiTimeStamp",                       unsigned int())
, m_rp_VehOut_uiMeasurementCounter              (this, "pLcf_VehOut_uiMeasurementCounter",              unsigned short())
, m_rp_VehOut_uiCycleCounter                    (this, "pLcf_VehOut_uiCycleCounter",                    unsigned short())
, m_rp_VehOut_eSigStatus                        (this, "pLcf_VehOut_eSigStatus",                        unsigned char())

/* LCF Veh2Sen Output Signals */
, m_rp_DrvAttention_perc						(this, "pLcf_DrvAttention_perc",						float())
, m_rp_DrvAttentionConf_perc					(this, "pLcf_DrvAttentionConf_perc",					signed char())
, m_rp_DrvMonSysWarning_nu						(this, "pLcf_DrvMonSysWarning_nu",						unsigned char())
, m_rp_HandsOffConfirmed_nu						(this, "pLcf_HandsOffConfirmed_nu",						unsigned char())
, m_rp_AbuseWarning_nu							(this, "pLcf_AbuseWarning_nu",							unsigned char())
, m_rp_EstHandTor_nm							(this, "pLcf_EstHandTor_nm",							float())
, m_rp_SAC_Eps_Request_Flag_nu					(this, "pLcf_SAC_Eps_Request_Flag_nu",					unsigned char())
, m_rp_Veh2Sen_Reserved1_nu						(this, "pLcf_Veh2Sen_Reserved1_nu",						float())
, m_rp_Veh2Sen_Reserved2_nu						(this, "pLcf_Veh2Sen_Reserved2_nu",						float())
, m_rp_TrigCustFctReplanCurValues_nu			(this, "pLcf_TrigCustFctReplanCurValues_nu",			unsigned char())
, m_rp_TrajGuiQualifier_nu						(this, "pLcf_TrajGuiQualifier_nu",						unsigned char())
, m_rp_CurDistY_m								(this, "pLcf_CurDistY_m",								float())
, m_rp_CurHeading__rad							(this, "pLcf_CurHeading__rad",							float())
, m_rp_LtcyComp_DevHeading__rad					(this, "pLcf_LtcyComp_DevHeading__rad",					float())
, m_rp_TrajDistY_m								(this, "pLcf_TrajDistY_m",								float())
, m_rp_TrajHeading__rad							(this, "pLcf_TrajHeading__rad",							float())
, m_rp_TrajHeadingInclPreview__rad				(this, "pLcf_TrajHeadingInclPreview__rad",				float())
, m_rp_TgtTrajCrv__1pm							(this, "pLcf_TgtTrajCrv__1pm",							float())
, m_rp_TgtTrajCrvGrd__1pms						(this, "pLcf_TgtTrajCrvGrd__1pms",						float())
, m_rp_LtcyComp_RightCorridorCrv__1pm			(this, "pLcf_LtcyComp_RightCorridorCrv__1pm",			float())
, m_rp_CtrlErrDistY_m							(this, "pLcf_CtrlErrDistY_m",							float())
, m_rp_CtrlErrHeadingAngle__rad					(this, "pLcf_CtrlErrHeadingAngle__rad",					float())
, m_rp_TgtCrv_NoDE__1pm							(this, "pLcf_TgtCrv_NoDE__1pm",							float())
, m_rp_TgtCrv_DEWithNoLatSlp__1pm				(this, "pLcf_TgtCrv_DEWithNoLatSlp__1pm",				float())
, m_rp_TgtCrv_DE__1pm							(this, "pLcf_TgtCrv_DE__1pm",							float())
, m_rp_TgtCrv_Limited__1pm						(this, "pLcf_TgtCrv_Limited__1pm",						float())
, m_rp_TgtCrv_Gradient__1pms					(this, "pLcf_TgtCrv_Gradient__1pms",					float())
, m_rp_TgtVehCtrlQualifier_nu					(this, "pLcf_TgtVehCtrlQualifier_nu",					unsigned char())
, m_rp_TgtCrv_LimiterWarning_nu				(this, "pLcf_TgtCrv_LimiterWarning_nu",				unsigned char())
, m_rp_TrjCtrQualifierService_nu				(this, "pLcf_TrjCtrQualifierService_nu",				unsigned char())
, m_rp_QuStatusTrajPlan_nu						(this, "pLcf_QuStatusTrajPlan_nu",						unsigned char())
, m_rp_LaDmcQualifierService_nu				(this, "pLcf_LaDmcQualifierService_nu",				unsigned char())
, m_rp_Veh2Sen_EventId_nu_0_					(this, "pLcf_Veh2Sen_EventId_nu_0_",					unsigned short())
, m_rp_Veh2Sen_EventLifetime_nu_0_				(this, "pLcf_Veh2Sen_EventLifetime_nu_0_",				unsigned short())
, m_rp_Veh2Sen_EventId_nu_1_					(this, "pLcf_Veh2Sen_EventId_nu_1_",					unsigned short())
, m_rp_Veh2Sen_EventLifetime_nu_1_				(this, "pLcf_Veh2Sen_EventLifetime_nu_1_",				unsigned short())
, m_rp_Veh2Sen_EventId_nu_2_					(this, "pLcf_Veh2Sen_EventId_nu_2_",					unsigned short())
, m_rp_Veh2Sen_EventLifetime_nu_2_				(this, "pLcf_Veh2Sen_EventLifetime_nu_2_",				unsigned short())
, m_rp_Veh2Sen_EventId_nu_3_					(this, "pLcf_Veh2Sen_EventId_nu_3_",					unsigned short())
, m_rp_Veh2Sen_EventLifetime_nu_3_				(this, "pLcf_Veh2Sen_EventLifetime_nu_3_",				unsigned short())
, m_rp_Veh2Sen_EventId_nu_4_					(this, "pLcf_Veh2Sen_EventId_nu_4_",					unsigned short())
, m_rp_Veh2Sen_EventLifetime_nu_4_				(this, "pLcf_Veh2Sen_EventLifetime_nu_4_",				unsigned short())
, m_rp_Veh2Sen_uiVersionNumber					(this, "pLcf_Veh2Sen_uiVersionNumber",					unsigned int())
, m_rp_Veh2Sen_uiTimeStamp						(this, "pLcf_Veh2Sen_uiTimeStamp",						unsigned int())
, m_rp_Veh2Sen_uiMeasurementCounter				(this, "pLcf_Veh2Sen_uiMeasurementCounter",				unsigned short())
, m_rp_Veh2Sen_uiCycleCounter					(this, "pLcf_Veh2Sen_uiCycleCounter",					unsigned short())
, m_rp_Veh2Sen_eSigStatus						(this, "pLcf_Veh2Sen_eSigStatus",						unsigned char())

/* LCF Algo Comp Sen Signals */
, m_rp_CompSen_uiVersionNumber                 (this, "pLcf_CompSen_uiVersionNumber",				    unsigned int())
, m_rp_CompSen_uiTimeStamp                     (this, "pLcf_CompSen_uiTimeStamp",					    unsigned int())
, m_rp_CompSen_uiMeasurementCounter            (this, "pLcf_CompSen_uiMeasurementCounter",			    unsigned short())
, m_rp_CompSen_uiCycleCounter                  (this, "pLcf_CompSen_uiCycleCounter",				    unsigned short())
, m_rp_CompSen_eSigStatus                      (this, "pLcf_CompSen_eSigStatus",					    unsigned char())
, m_rp_Sen_uiAlgoVersionNumber                 (this, "pLcf_CompSen_uiAlgoVersionNumber",			    unsigned int())
, m_rp_Sen_uiApplicationNumber                 (this, "pLcf_CompSen_uiApplicationNumber",			    unsigned int())
, m_rp_Sen_eCompState                          (this, "pLcf_CompSen_eCompState",					    unsigned char())
, m_rp_Sen_eShedulerSubModeRequest             (this, "pLcf_CompSen_eShedulerSubModeRequest",		    unsigned char())
, m_rp_Sen_eErrorCode                          (this, "pLcf_CompSen_eErrorCode",					    unsigned int())
, m_rp_Sen_eGenAlgoQualifier                   (this, "pLcf_CompSen_eGenAlgoQualifier",				    unsigned int())

/* LCF Algo Comp Veh Signals */
, m_rp_CompVeh_uiVersionNumber                 (this, "pLcf_CompVeh_uiVersionNumber",				    unsigned int())
, m_rp_CompVeh_uiTimeStamp                     (this, "pLcf_CompVeh_uiTimeStamp",					    unsigned int())
, m_rp_CompVeh_uiMeasurementCounter            (this, "pLcf_CompVeh_uiMeasurementCounter",			    unsigned short())
, m_rp_CompVeh_uiCycleCounter                  (this, "pLcf_CompVeh_uiCycleCounter",				    unsigned short())
, m_rp_CompVeh_eSigStatus                      (this, "pLcf_CompVeh_eSigStatus",					    unsigned char())
, m_rp_Veh_uiAlgoVersionNumber                 (this, "pLcf_CompVeh_uiAlgoVersionNumber",			    unsigned int())
, m_rp_Veh_uiApplicationNumber                 (this, "pLcf_CompVeh_uiApplicationNumber",			    unsigned int())
, m_rp_Veh_eCompState                          (this, "pLcf_CompVeh_eCompState",					    unsigned char())
, m_rp_Veh_eShedulerSubModeRequest             (this, "pLcf_CompVeh_eShedulerSubModeRequest",		    unsigned char())
, m_rp_Veh_eErrorCode                          (this, "pLcf_CompVeh_eErrorCode",					    unsigned int())
, m_rp_Veh_eGenAlgoQualifier                   (this, "pLcf_CompVeh_eGenAlgoQualifier",				    unsigned int())

/* LCF Generic Inputs Signals */
, m_rp_SteerHandWheelAngle__rad                 (this, "pLcf_SteerHandWheelAngle__rad",                 float())
, m_rp_SteerHandWheelAngleRate__rps             (this, "pLcf_SteerHandWheelAngleRate__rps",             float())
, m_rp_DeltaFSteerAngle__deg                    (this, "pLcf_DeltaFSteerAngle__deg",                    float())
, m_rp_DeltaFSteerAngleRate__degps              (this, "pLcf_DeltaFSteerAngleRate__degps",              float())
, m_rp_SteerTrq__nm                             (this, "pLcf_SteerTrq__nm",                             float())
, m_rp_DrvSteerWheelTrq__nm                     (this, "pLcf_DrvSteerWheelTrq__nm",                     float())
, m_rp_EPS_Motor_Torque__nm                     (this, "pLcf_EPS_Motor_Torque__nm",                     float())
, m_rp_ESC_SystemState_nu                      (this, "pLcf_ESC_SystemState_nu",                      unsigned char())
, m_rp_ESC_ActiveState_nu                      (this, "pLcf_ESC_ActiveState_nu",                      unsigned char())
, m_rp_ABS_SystemState_nu                      (this, "pLcf_ABS_SystemState_nu",                      unsigned char())
, m_rp_ABS_ActiveState_nu                      (this, "pLcf_ABS_ActiveState_nu",                      unsigned char())
, m_rp_TCS_SystemState_nu                      (this, "pLcf_TCS_SystemState_nu",                      unsigned char())
, m_rp_TCS_ActiveState_nu                      (this, "pLcf_TCS_ActiveState_nu",                      unsigned char())
, m_rp_ACC_SystemState_nu                      (this, "pLcf_ACC_SystemState_nu",                      unsigned char())
, m_rp_ACC_ActiveState_nu                      (this, "pLcf_ACC_ActiveState_nu",                      unsigned char())
, m_rp_VSM_SystemState_nu                      (this, "pLcf_VSM_SystemState_nu",                      unsigned char())
, m_rp_VSM_ActiveState_nu                      (this, "pLcf_VSM_ActiveState_nu",                      unsigned char())
, m_rp_EBA_SystemState_nu                      (this, "pLcf_EBA_SystemState_nu",                      unsigned char())
, m_rp_EBA_ActiveState_nu                      (this, "pLcf_EBA_ActiveState_nu",                      unsigned char())
, m_rp_EBA_WarningState_nu                     (this, "pLcf_EBA_WarningState_nu",                     unsigned char())
, m_rp_TSA_SystemState_nu                      (this, "pLcf_TSA_SystemState_nu",                      unsigned char())
, m_rp_TSA_ActiveState_nu                      (this, "pLcf_TSA_ActiveState_nu",                      unsigned char())
, m_rp_DynamometerTestBenchDetected_nu         (this, "pLcf_DynamometerTestBenchDetected_nu",         unsigned char())
, m_rp_DoorOpen_nu                             (this, "pLcf_DoorOpen_nu",                             unsigned char())
, m_rp_TurnSignalState_nu                      (this, "pLcf_TurnSignalState_nu",                      unsigned char())
, m_rp_TurnSignalLever_nu                      (this, "pLcf_TurnSignalLever_nu",                      unsigned char())
, m_rp_VehicleReadyState_nu                    (this, "pLcf_VehicleReadyState_nu",                    unsigned char())
, m_rp_DriverNotBuckledUp_nu                   (this, "pLcf_DriverNotBuckledUp_nu",                   unsigned char())
, m_rp_OversteeringDetected_nu                 (this, "pLcf_OversteeringDetected_nu",                 unsigned char())
, m_rp_UndersteeringDetected_nu                (this, "pLcf_UndersteeringDetected_nu",                unsigned char())
, m_rp_BankAngle__rad                           (this, "pLcf_BankAngle__rad",                           float())
, m_rp_TieRodLoad__n                            (this, "pLcf_TieRodLoad__n",                            float())
, m_rp_EPS_Toi_Unavail_nu                      (this, "pLcf_EPS_Toi_Unavail_nu",                      unsigned char())
, m_rp_EPS_Toi_Active_nu                       (this, "pLcf_EPS_Toi_Active_nu",                       unsigned char())
, m_rp_EPS_Toi_Flt_nu                          (this, "pLcf_EPS_Toi_Flt_nu",                          unsigned char())
, m_rp_EPS_Fail_Stat_nu                        (this, "pLcf_EPS_Fail_Stat_nu",                        unsigned char())
, m_rp_EPS_Def_nu                              (this, "pLcf_EPS_Def_nu",                              unsigned char())
, m_rp_LKAMainSwitch_nu                        (this, "pLcf_LKAMainSwitch_nu",                        unsigned char())
, m_rp_LKAMode_nu                              (this, "pLcf_LKAMode_nu",                              unsigned char())
, m_rp_TJAMainSwitch_nu                        (this, "pLcf_TJAMainSwitch_nu",                        unsigned char())
, m_rp_TJAMode_nu                              (this, "pLcf_TJAMode_nu",                              unsigned char())
, m_rp_VibrationActState_nu                    (this, "pLcf_VibrationActState_nu",                    unsigned char())
, m_rp_SideMirrorLEDState_nu                   (this, "pLcf_SideMirrorLEDState_nu",                   unsigned char())
, m_rp_LDWSwitch_nu                            (this, "pLcf_LDWSwitch_nu",                            unsigned char())
, m_rp_LDPSwitch_nu                            (this, "pLcf_LDPSwitch_nu",                            unsigned char())
, m_rp_RDWSwitch_nu                            (this, "pLcf_RDWSwitch_nu",                            unsigned char())
, m_rp_RDPSwitch_nu                            (this, "pLcf_RDPSwitch_nu",                            unsigned char())
, m_rp_LDPOncomingSwitch_nu                    (this, "pLcf_LDPOncomingSwitch_nu",                    unsigned char())
#if ((LCF_INPUT_INTFVER >= 18) && (LCF_INPUT_INTFVER < 30)) /* RTE used for AES has a higher version */
, m_rp_AoLCSwitch_nu                           (this, "pLcf_AoLCSwitch_nu",                           unsigned char())
, m_rp_LDWOncomingSwitch_nu                    (this, "pLcf_LDWOncomingSwitch_nu",                    unsigned char())
, m_rp_LDWOCSensitivity_nu                     (this, "pLcf_LDWOCSensitivity_nu",                     unsigned char())
#endif
, m_rp_LDWSensitivity_nu                       (this, "pLcf_LDWSensitivity_nu",                       unsigned char())
, m_rp_LDPSensitivity_nu                       (this, "pLcf_LDPSensitivity_nu",                       unsigned char())
, m_rp_RDPSensitivity_nu                       (this, "pLcf_RDPSensitivity_nu",                       unsigned char())
#if ((LCF_INPUT_INTFVER >= 18) && (LCF_INPUT_INTFVER < 30)) /* RTE used for AES has a higher version */
, m_rp_RDWSensitivity_nu                       (this, "pLcf_RDWSensitivity_nu",                       unsigned char())
, m_rp_LDPMode_nu                              (this, "pLcf_LDPMode_nu",                              unsigned char())
, m_rp_LDWMode_nu                              (this, "pLcf_LDWMode_nu",                              unsigned char())
, m_rp_RDPMode_nu                              (this, "pLcf_RDPMode_nu",                              unsigned char())
, m_rp_RDWMode_nu                              (this, "pLcf_RDWMode_nu",                              unsigned char())
, m_rp_LDPOCMode_nu                            (this, "pLcf_LDPOCMode_nu",                            unsigned char())
, m_rp_LDWOCMode_nu                            (this, "pLcf_LDWOCMode_nu",                            unsigned char())
, m_rp_AoLCMode_nu                             (this, "pLcf_AoLCMode_nu",                             unsigned char())
#endif
, m_rp_DriverHandsOff_nu                       (this, "pLcf_DriverHandsOff_nu",                       unsigned char())
, m_rp_SCCActive_nu                            (this, "pLcf_SCCActive_nu",                            unsigned char())
, m_rp_USMReset_nu                             (this, "pLcf_USMReset_nu",                             unsigned char())
, m_rp_HDAOn_nu                                (this, "pLcf_HDAOn_nu",                                unsigned char())
, m_rp_SCCOn_nu                                (this, "pLcf_SCCOn_nu",                                unsigned char())
, m_rp_USMSetSpd__kph                           (this, "pLcf_USMSetSpd__kph",                           unsigned char())
, m_rp_NAVIRoadType_nu                         (this, "pLcf_NAVIRoadType_nu",                         unsigned char())
, m_rp_NAVISegFormOfWay_nu                     (this, "pLcf_NAVISegFormOfWay_nu",                     unsigned char())
, m_rp_NAVISegSpeedLim__kph                     (this, "pLcf_NAVISegSpeedLim__kph",                     unsigned char())
, m_rp_NAVIStatus_nu                           (this, "pLcf_NAVIStatus_nu",                           unsigned char())
, m_rp_NAVIProlProfType_nu                     (this, "pLcf_NAVIProlProfType_nu",                     unsigned char())
, m_rp_NAVITollgateDet_nu                      (this, "pLcf_NAVITollgateDet_nu",                      unsigned char())
, m_rp_NAVITgDetDistOffset_m                   (this, "pLcf_NAVITgDetDistOffset_m",                   unsigned short())
, m_rp_NAVIPosOffset_m                         (this, "pLcf_NAVIPosOffset_m",                         unsigned short())
, m_rp_NAVIProlCyclicCount_nu                  (this, "pLcf_NAVIProlCyclicCount_nu",                  unsigned char())
, m_rp_NAVIPosCyclicCount_nu                   (this, "pLcf_NAVIPosCyclicCount_nu",                   unsigned char())
, m_rp_HDAExtFailFlag_nu                       (this, "pLcf_HDAExtFailFlag_nu",                       unsigned char())
, m_rp_SCCMainMode_nu                          (this, "pLcf_SCCMainMode_nu",                          unsigned char())
, m_rp_NAVISpeedUnit_nu                        (this, "pLcf_NAVISpeedUnit_nu",                        unsigned char())
, m_rp_AlwaysHandsOn_nu                        (this, "pLcf_AlwaysHandsOn_nu",                        unsigned char())
, m_rp_AccelPedalPos_nu                        (this, "pLcf_AccelPedalPos_nu",                        float())
, m_rp_LcfVariantInfo_nu                       (this, "pLcf_LcfVariantInfo_nu",                       unsigned char())
, m_rp_DanRearObjBS_RearLeft_nu                (this, "pLcf_DanRearObjBS_RearLeft_nu",                unsigned char())
, m_rp_DanRearObjFOV_RearLeft_nu               (this, "pLcf_DanRearObjFOV_RearLeft_nu",               unsigned char())
, m_rp_OIQualifierFlag_RearLeft_nu             (this, "pLcf_OIQualifierFlag_RearLeft_nu",             unsigned char())
, m_rp_MSFlag_RearLeft_nu                      (this, "pLcf_MSFlag_RearLeft_nu",                      unsigned char())
, m_rp_DanRearObjBS_RearRight_nu               (this, "pLcf_DanRearObjBS_RearRight_nu",               unsigned char())
, m_rp_DanRearObjFOV_RearRight_nu              (this, "pLcf_DanRearObjFOV_RearRight_nu",              unsigned char())
, m_rp_OIQualifierFlag_RearRight_nu            (this, "pLcf_OIQualifierFlag_RearRight_nu",            unsigned char())
, m_rp_MSFlag_RearRight_nu                     (this, "pLcf_MSFlag_RearRight_nu",                     unsigned char())
, m_rp_ALCASwitch_nu                           (this, "pLcf_ALCASwitch_nu",                           unsigned char())
, m_rp_ALCASensitivity_nu                      (this, "pLcf_ALCASensitivity_nu",                      unsigned char())
, m_rp_ALCAMode_nu                             (this, "pLcf_ALCAMode_nu",                             unsigned char())
, m_rp_LCA_Active_Left_nu                      (this, "pLcf_LCA_Active_Left_nu",                      unsigned char())
, m_rp_BSD_Active_Left_nu                      (this, "pLcf_BSD_Active_Left_nu",                      unsigned char())
, m_rp_LCA_Warning_Left_nu                     (this, "pLcf_LCA_Warning_Left_nu",                     unsigned char())
, m_rp_BSD_Warning_Left_nu                     (this, "pLcf_BSD_Warning_Left_nu",                     unsigned char())
, m_rp_LCA_Active_Right_nu                     (this, "pLcf_LCA_Active_Right_nu",                     unsigned char())
, m_rp_BSD_Active_Right_nu                     (this, "pLcf_BSD_Active_Right_nu",                     unsigned char())
, m_rp_LCA_Warning_Right_nu                    (this, "pLcf_LCA_Warning_Right_nu",                    unsigned char())
, m_rp_BSD_Warning_Right_nu                    (this, "pLcf_BSD_Warning_Right_nu",                    unsigned char())
, m_rp_HapticWrnDeviceLeftState_nu             (this, "pLcf_HapticWrnDeviceLeftState_nu",             unsigned char())
, m_rp_HapticWrnDeviceRightState_nu            (this, "pLcf_HapticWrnDeviceRightState_nu",            unsigned char())
, m_rp_HapticWrnDeviceCommonState_nu           (this, "pLcf_HapticWrnDeviceCommonState_nu",           unsigned char())
, m_rp_HapticWrnDeviceLeftMode_nu              (this, "pLcf_HapticWrnDeviceLeftMode_nu",              unsigned char())
, m_rp_HapticWrnDeviceRightMode_nu             (this, "pLcf_HapticWrnDeviceRightMode_nu",             unsigned char())
, m_rp_HapticWrnDeviceCommonMode_nu            (this, "pLcf_HapticWrnDeviceCommonMode_nu",            unsigned char())
, m_rp_VisualWrnDeviceLeftState_nu             (this, "pLcf_VisualWrnDeviceLeftState_nu",             unsigned char())
, m_rp_VisualWrnDeviceRightState_nu            (this, "pLcf_VisualWrnDeviceRightState_nu",            unsigned char())
, m_rp_VisualWrnDeviceCommonState_nu           (this, "pLcf_VisualWrnDeviceCommonState_nu",           unsigned char())
, m_rp_VisualWrnDeviceLeftMode_nu              (this, "pLcf_VisualWrnDeviceLeftMode_nu",              unsigned char())
, m_rp_VisualWrnDeviceRightMode_nu             (this, "pLcf_VisualWrnDeviceRightMode_nu",             unsigned char())
, m_rp_VisualWrnDeviceCommonMode_nu            (this, "pLcf_VisualWrnDeviceCommonMode_nu",            unsigned char())
, m_rp_LDPOCSensitivity_nu                     (this, "pLcf_LDPOCSensitivity_nu",                     unsigned char())
, m_rp_AoLCSensitivity_nu                      (this, "pLcf_AoLCSensitivity_nu",                      unsigned char())
, m_rp_TJALatCtrlActive_nu                     (this, "pLcf_TJALatCtrlActive_nu",                     unsigned char())
, m_rp_TJAHandsOffWrnEnable_nu                 (this, "pLcf_TJAHandsOffWrnEnable_nu",                 unsigned char())
, m_rp_EPSSteerCtrlMode_nu                     (this, "pLcf_EPSSteerCtrlMode_nu",                     unsigned char())
, m_rp_EPSECUActFact_nu                        (this, "pLcf_EPSECUActFact_nu",                        unsigned char())
, m_rp_EPSDriverIntervention_nu                (this, "pLcf_EPSDriverIntervention_nu",                unsigned char())
, m_rp_EPSReqTrq__nm                            (this, "pLcf_EPSReqTrq__nm",                            float())
, m_rp_EPSMotTrq__nm                            (this, "pLcf_EPSMotTrq__nm",                            float())
, m_rp_EPSMotAngSpd__degps                      (this, "pLcf_EPSMotAngSpd__degps",                      float())
, m_rp_EPSReqStAng__deg                         (this, "pLcf_EPSReqStAng__deg",                         float())
#if ((LCF_INPUT_INTFVER >= 18) && (LCF_INPUT_INTFVER < 30)) /* RTE used for AES has a higher version */
, m_rp_SteerWheelAngSensorStatus_nu            (this, "pLcf_SteerWheelAngSensorStatus_nu",            unsigned char())
, m_rp_CommunicationLostEps_nu                 (this, "pLcf_CommunicationLostEps_nu",                 unsigned char())
, m_rp_CommunicationLostSCS_nu                 (this, "pLcf_CommunicationLostSCS_nu",                 unsigned char())
, m_rp_CommunicationLostTCM_nu                 (this, "pLcf_CommunicationLostTCM_nu",                 unsigned char())
, m_rp_MainCylPressure_pa                       (this, "pLcf_MainCylPressure_pa",                       float())
, m_rp_TerrainMode_nu                          (this, "pLcf_TerrainMode_nu",                          unsigned char())
#endif
, m_rp_ASLRNG_nu                               (this, "pLcf_ASLRNG_nu",                               float())
, m_rp_GOS_Lamp_nu                             (this, "pLcf_GOS_Lamp_nu",                             float())
, m_rp_GOS_Multi_inf_nu                        (this, "pLcf_GOS_Multi_inf_nu",                        float())
, m_rp_CWA_Activation_nu                       (this, "pLcf_CWA_Activation_nu",                       float())
, m_rp_PCS_Destination_nu                      (this, "pLcf_PCS_Destination_nu",                      float())
, m_rp_PCS_AES_invalid_flag1_nu                (this, "pLcf_PCS_AES_invalid_flag1_nu",                float())
, m_rp_DangOcObjLe_nu                           (this, "pLcf_DangOcObjLe_nu",                           unsigned char())
, m_rp_DangOcObjRi_nu                           (this, "pLcf_DangOcObjRi_nu",                           unsigned char())
, m_rp_QuDangOcObjDtct_nu                       (this, "pLcf_QuDangOcObjDtct_nu",                       unsigned char())
#if ((LCF_INPUT_INTFVER >= 18) && (LCF_INPUT_INTFVER < 30)) /* RTE used for AES has a higher version */
, m_rp_ObjectStationaryLeft_nu                 (this, "pLcf_ObjectStationaryLeft_nu",                 unsigned char())
, m_rp_ObjectStationaryRight_nu                (this, "pLcf_ObjectStationaryRight_nu",                unsigned char())
, m_rp_ObjectSensitiveLeft_nu                  (this, "pLcf_ObjectSensitiveLeft_nu",                  unsigned char())
, m_rp_ObjectSensitiveRight_nu                 (this, "pLcf_ObjectSensitiveRight_nu",                 unsigned char())
#endif
, m_rp_TSEGapLongDistEgoToTarget_m             (this, "pLcf_TSEGapLongDistEgoToTarget_m",             float())
, m_rp_TSEGapLongDistEgoToTargetPRE_m          (this, "pLcf_TSEGapLongDistEgoToTargetPRE_m",          float())
, m_rp_TSETargetLongVel_mps                    (this, "pLcf_TSETargetLongVel_mps",                    float())
, m_rp_TSETargetLongAccel_mps2                 (this, "pLcf_TSETargetLongAccel_mps2",                 float())
, m_rp_TSEKappaEvasiveCorrRight__1pm            (this, "pLcf_TSEKappaEvasiveCorrRight__1pm",            float())
, m_rp_TSEGapLatDistEgoToCorrLeft_m            (this, "pLcf_TSEGapLatDistEgoToCorrLeft_m",            float())
, m_rp_TSEGapLatDistEgoToCorrRight_m           (this, "pLcf_TSEGapLatDistEgoToCorrRight_m",           float())
, m_rp_TSEGapLatDistObjToCorrLeft_m            (this, "pLcf_TSEGapLatDistObjToCorrLeft_m",            float())
, m_rp_TSEGapLatDistObjToCorrRight_m           (this, "pLcf_TSEGapLatDistObjToCorrRight_m",           float())
, m_rp_TSEAEBAcuteDynWarnFCTChan_nu            (this, "pLcf_TSEAEBAcuteDynWarnFCTChan_nu",            unsigned char())
, m_rp_TSEAEBAcuteDynWarnSigState_nu           (this, "pLcf_TSEAEBAcuteDynWarnSigState_nu",           unsigned char())
, m_rp_TSEStatusFunctionEPF_nu                 (this, "pLcf_TSEStatusFunctionEPF_nu",                 unsigned char())
, m_rp_TSEAEBAnecLongAccel_mpss                (this, "pLcf_TSEAEBAnecLongAccel_mpss",                float())
, m_rp_LCF_GenInput_uiVersionNumber             (this, "pLcf_LCF_GenInput_uiVersionNumber",             unsigned int())
, m_rp_LCF_GenInput_uiTimeStamp                 (this, "pLcf_LCF_GenInput_uiTimeStamp",                 unsigned int())
, m_rp_LCF_GenInput_uiMeasurementCounter        (this, "pLcf_LCF_GenInput_uiMeasurementCounter",        unsigned short())
, m_rp_LCF_GenInput_uiCycleCounter              (this, "pLcf_LCF_GenInput_uiCycleCounter",              unsigned short())
, m_rp_LCF_GenInput_eSigStatus                  (this, "pLcf_LCF_GenInput_eSigStatus",                  unsigned char())
/* Get SOC Version to be easier to identify a MFC CP */
, m_rp_SOC_u_VersionNumber                      (this, "pIPC_SOC_u_VersionNumber",                      unsigned int())

#if (GET_LCF_PRJ_NR() == GET_LCFPRJ_MFC431LO19())
/* MFC431LO19 Specific Signals */
, m_rp_D_LSCCTR_PreconditionsOK_btf				(this, "pLcf_D_LSCCTR_PreconditionsOK_btf",				unsigned short())
, m_rp_D_LSCCTR_PrjSpecQu_btf					(this, "pLcf_D_LSCCTR_PrjSpecQu_btf",					unsigned short())
, m_rp_D_HMOLCO_SysStateHWA_btf					(this, "pLcf_D_HMOLCO_SysStateHWA_btf",					unsigned short())
, m_rp_S_HMOLCO_ActFctEnabled_bool				(this, "pLcf_S_HMOLCO_ActFctEnabled_bool",			    unsigned char())
, m_rp_S_HMOLCO_ActFctLevel_nu					(this, "pLcf_S_HMOLCO_ActFctLevel_nu",					unsigned char())
, m_rp_S_HMOLCO_CnclReqForCrsCtrl_nu			(this, "pLcf_S_HMOLCO_CnclReqForCrsCtrl_nu",			unsigned char())
, m_rp_S_HMOLCO_HWAStatus_nu					(this, "pLcf_S_HMOLCO_HWAStatus_nu",				    unsigned char())
, m_rp_S_HMOLCO_HapticWrnReq_nu					(this, "pLcf_S_HMOLCO_HapticWrnReq_nu",					unsigned char())
, m_rp_S_HMOLCO_LDWState_nu						(this, "pLcf_S_HMOLCO_LDWState_nu",						unsigned char())
, m_rp_S_HMOLCO_LKAState_nu						(this, "pLcf_S_HMOLCO_LKAState_nu",						unsigned char())
, m_rp_S_HMOLCO_LaneDetectionStatusForHWA_nu	(this, "pLcf_S_HMOLCO_LaneDetectionStatusForHWA_nu",	unsigned char())
, m_rp_S_HMOLCO_LaneDetectionStatus_nu			(this, "pLcf_S_HMOLCO_LaneDetectionStatus_nu",			unsigned char())
, m_rp_S_HMOLCO_SteerActiveOK_bool				(this, "pLcf_S_HMOLCO_SteerActiveOK_bool",			    unsigned char())
, m_rp_S_HMOLCO_SteerStandbyOK_bool				(this, "pLcf_S_HMOLCO_SteerStandbyOK_bool",				unsigned char())
, m_rp_S_HMOLCO_StsForLatAutDrv_nu				(this, "pLcf_S_HMOLCO_StsForLatAutDrv_nu",				unsigned char())
, m_rp_S_HMOLCO_SysWarning_nu					(this, "pLcf_S_HMOLCO_SysWarning_nu",				    unsigned char())
, m_rp_S_HMOLCO_WarnForLatAutDrv_nu				(this, "pLcf_S_HMOLCO_WarnForLatAutDrv_nu",				unsigned char())
, m_rp_S_HMOLCO_WarnReqHWA_nu					(this, "pLcf_S_HMOLCO_WarnReqHWA_nu",				    unsigned char())
, m_rp_S_HMOLCO_eLKAState_nu					(this, "pLcf_S_HMOLCO_eLKAState_nu",					unsigned char())

#elif (GET_LCF_PRJ_NR() == GET_LCFPRJ_MFC431TA19())
/* MFC431TA19 Specific Signals */
, m_rp_S_TSCCTR_PrjSpecQu_btf					(this, "pLcf_S_TSCCTR_PrjSpecQu_btf",					unsigned short())
, m_rp_S_TSCLDA_PrjSpecQu_btf					(this, "pLcf_S_TSCLDA_PrjSpecQu_btf",					unsigned char())
, m_rp_S_TSCLTA_PrjSpecQu_btf					(this, "pLcf_S_TSCLTA_PrjSpecQu_btf",					unsigned char())
, m_rp_D_TSCLTA_HmiCancelWarningQu_btf			(this, "pLcf_D_TSCLTA_HmiCancelWarningQu_btf",		    unsigned int())
, m_rp_S_TSCLTA_HmiCancelWarningQu_nu			(this, "pLcf_S_TSCLTA_HmiCancelWarningQu_nu",			unsigned char())
, m_rp_S_TSCLTA_LDAIndiOffReq_bool				(this, "pLcf_S_TSCLTA_LDAIndiOffReq_bool",				unsigned char())
, m_rp_S_TSCLTA_SysGainDec_bool					(this, "pLcf_S_TSCLTA_SysGainDec_bool",				    unsigned char())
, m_rp_D_TSCLDA_LDPMode2DispVel_kph				(this, "pLcf_D_TSCLDA_LDPMode2DispVel_kph",				float())
, m_rp_D_TSCLDA_ObjLeDetect_bool				(this, "pLcf_D_TSCLDA_ObjLeDetect_bool",				unsigned char())
, m_rp_D_TSCLDA_ObjRiDetect_bool				(this, "pLcf_D_TSCLDA_ObjRiDetect_bool",				unsigned char())
, m_rp_D_TSCLDA_OneSideLnReDtct_bool			(this, "pLcf_D_TSCLDA_OneSideLnReDtct_bool",			unsigned char())
, m_rp_D_TSCLDA_Precondition_bool				(this, "pLcf_D_TSCLDA_Precondition_bool",				unsigned char())
, m_rp_D_TSCLDA_RoadWidth_met					(this, "pLcf_D_TSCLDA_RoadWidth_met",				    float())
, m_rp_D_TSCLDA_TMCCurvGLeLn_mps2				(this, "pLcf_D_TSCLDA_TMCCurvGLeLn_mps2",				float())
, m_rp_D_TSCLDA_TMCCurvGLeRe_mps2				(this, "pLcf_D_TSCLDA_TMCCurvGLeRe_mps2",				float())
, m_rp_D_TSCLDA_TMCCurvGRiLn_mps2				(this, "pLcf_D_TSCLDA_TMCCurvGRiLn_mps2",		        float())
, m_rp_D_TSCLDA_TMCCurvGRiRe_mps2				(this, "pLcf_D_TSCLDA_TMCCurvGRiRe_mps2",				float())
, m_rp_D_TSCLDA_TurnSignalLeft_bool		    	(this, "pLcf_D_TSCLDA_TurnSignalLeft_bool",			    unsigned char())
, m_rp_D_TSCLDA_TurnSignalRight_bool			(this, "pLcf_D_TSCLDA_TurnSignalRight_bool",			unsigned char())
, m_rp_D_TSCLDA_VehVelYLeLn_mps					(this, "pLcf_D_TSCLDA_VehVelYLeLn_mps",					float())
, m_rp_D_TSCLDA_VehVelYLeRe_mps					(this, "pLcf_D_TSCLDA_VehVelYLeRe_mps",				    float())
, m_rp_D_TSCLDA_VehVelYRiLn_mps					(this, "pLcf_D_TSCLDA_VehVelYRiLn_mps",					float())
, m_rp_D_TSCLDA_VehVelYRiRe_mps		    		(this, "pLcf_D_TSCLDA_VehVelYRiRe_mps",				    float())
, m_rp_S_TSCLDA_LDPModeCustom_st				(this, "pLcf_S_TSCLDA_LDPModeCustom_st",				unsigned char())
#endif

, colorWhite(1.0F, 1.0F, 1.0F, 0.75F)
, colorYellow(1.0F, 1.0F, 0.0F, 0.75F)
, colorOrange(1.0F, 0.65F, 0.0F, 0.75F)
, colorGreen(0.0F, 0.5F, 0.0F, 0.75F)
, colorTeal(0.0F, 0.5F, 0.5F, 1.0F)
, colorRed(1.0F, 0.0F, 0.0F, 0.75F)
, colorBlue(0.0f, 0.0F, 1.0F, 1.0F)
, colorNavy(0.0F, 0.0F, 0.5F, 1.0F)
, colorLime(0.0F, 1.0F, 0.0F, 0.75F)
, colorAqua(0.0F, 1.0F, 1.0F, 0.75F)
, colorMaroon(0.5F, 0.0F, 0.0F, 1.0F)
, colorPurple(0.5F, 0.0F, 0.5F, 0.75F)
, colorViolet(0.93F, 0.51F, 0.93F, 0.75F)
, colorOlive(0.5F, 0.5F, 0.0F, 1.0F)
, colorGray(0.5F, 0.5F, 0.5F, 0.75F)
, colorLightGray(0.82F, 0.82F, 0.82F, 0.75F)
, colorSilver(0.75F, 0.75F, 0.75F, 0.75F)
, colorFuchsia(1.0F, 0.0F, 1.0F, 0.75F)
, DebugSelect(8) /* LCF Integration Debug signals selected as default */
, BitfiledSel_idx(0)
, ERRIO_Select(0)
, SelectTrajDraw(0)
, m_bDrawHelp(0)
, m_ResolutionMode(0)
, m_Function_Activation_Number(SizeStatisticalArray, 0)
, LCF_SEN_Scheduler_Info(0,0,0,0,0,0,1,0,0,0,0.0f)
, LCF_VEH_Scheduler_Info(0,0,0,0,0,0,1,0,0,0,0.0f)
{
    // info strings
    std::stringstream headerTxt;
    std::stringstream dataTxt;

    headerTxt << "LcfVis version " << LCF_VISALL_SW_MAIN_VER_NO << "." << LCF_VISALL_SW_SUB_VER_NO << "." << LCF_VISALL_SW_BUG_FIX_LEV << "." << LCF_VISALL_SW_BUG_FIX_LEV2;
    dataTxt   << "LcfVis (LcfVis Simulation Module)";
    AddInternalData(headerTxt.str().c_str(), dataTxt.str().c_str());
	
    // initialize the LCF internal result parameters
    m_bLcfVehOutputDataValid = false;
    m_bLcfVehOutputToSenDataValid = false;
    m_bLcfSenOutputDataValid = false;
	m_bLcfSenOutputToVehDataValid = false;
	m_bLcfInputDataValid = false;
	m_bLDOutputDataValid = false;
	m_bHlaRadarObjectList = false;
	m_bLsdEnvironmentData = false;
	m_bCbOutputs = false;
    m_bAbdOutputDataValid = false;
	m_bVehParValid = false;
	m_bVehDynValid = false;
	m_bLCFSenDebugDataValid = false;
	m_bLCFVehDebugDataValid = false;
	m_bLCFSenAlgoCompState = false;
	m_bLCFVehAlgoCompState = false;
	m_SenOut_LeftLaneCorridorValid = false;
	m_SenOut_RightLaneCorridorValid = false;
	m_SenOut_TargetCorridorValid = false;

	fileName = "..\\mts_measurement\\cfg\\LCF\\LCF_Bitfields.csv";
	fileName_SpecCase = "mts_measurement\\cfg\\LCF\\LCF_Bitfields.csv"; /* Used when MTS is opened from deliverables folder using bat file */
	delimeter = ",";
	LcfCSVData = getData(fileName);

	/* Treat the case when MTS is opened from bat file : Deliverables folder : mts.bat*/
	if(!CSV_Open_Flag) {
		LcfCSVData = getData(fileName_SpecCase);
	}
#ifdef _DEBUG
    dataTxt.str("Debug ");
#else
    dataTxt.str("Release ");
#endif
    dataTxt << "build at " << __DATE__ << " " << __TIME__;
    AddInternalData("Compiling Info", dataTxt.str().c_str());

    // Create server Ports
    AddServerPort("Reset", Reset, this);
    AddServerPort("Doit",  Doit,  this);

    // Create client ports
    AddClientPort(CP_CALCULATIONDONE,      NULL, 0, PORT_WITH_AUTOCLONE);
	
	//AddReceivePort( "pLDOutputData", simOPAQUE_t, &m_rpLDOutputData, sizeof( m_rpLDOutputData));

    // Create algorithm ports
    SetupPorts();

    // reset "received" flags and error counters
    ResetReceiveErrors();
}

CSimLcfVis::~CSimLcfVis()
{
}

void CSimLcfVis::SetupPorts()
{
    // input ports
	m_rpLcfVehOutputData.setVersion       ("LCF_VehGenericOutputs_t",   CreateVersionInfoFromI32(LCF_VEH_OUTPUT_INTFVER));
	m_rpLcfVehOutputToSenData.setVersion  ("LCF_VehToSen_t",            CreateVersionInfoFromI32(LCF_VEH2SEN_INTFVER));
	m_rpLcfSenOutputData.setVersion       ("LCF_SenGenericOutputs_t",   CreateVersionInfoFromI32(LCF_SEN_OUTPUT_INTFVER));
	m_rpLcfSenOutputToVehData.setVersion  ("LCF_SenToVeh_t",            CreateVersionInfoFromI32(LCF_SEN2VEH_INTFVER));
	m_rpLcfInputData.setVersion           ("LCF_GenericInputs_t",       CreateVersionInfoFromI32(LCF_INPUT_INTFVER));
#if defined(LCF_SEN_RPORT_PHLARADAROBJECTLIST)
	m_rpHlaRadarObjectList.setVersion     ("HLA_RadarObjectList_t",     CreateVersionInfoFromI32(HLA_RADAR_OBJECT_LIST_INTFVER));
#endif
#if defined(LCF_SEN_RPORT_PLSDENVIRONMENTDATA)
	m_rpLsdEnvironmentData.setVersion     ("LSD_EnvironmentData_t",     CreateVersionInfoFromI32(LSD_ENVIRONMENT_DATA_INTFVER));
#endif
#if defined(LCF_SEN_RPORT_PCBOUTPUTS)
	m_rpCbOutputs.setVersion     		  ("CB_t_ProvidedOutputs_t",    CreateVersionInfoFromI32(CB_PROVIDED_OUTPUTS_INTFVER));
#endif
	m_rpAbdOutputData.setVersion          ("AbdOutputData_t",           CreateVersionInfoFromI32(ABD_OUTPUT_DATA_INTFVER));
	m_rpVehDyn.setVersion                 ("VehDyn_t",                  CreateVersionInfoFromI32(VDY_VEH_DYN_INTFVER));
	m_rpVehPar.setVersion                 ("VehPar_t",                  CreateVersionInfoFromI32(BSW_VEH_PAR_INTFVER));
	m_rpVehSig.setVersion                 ("VehSig_t",                  CreateVersionInfoFromI32(BSW_VEH_SIG_INTFVER));
	m_rpLCF_SenAlgoCompState.setVersion   ("AlgoCompState_t",           CreateVersionInfoFromI32(COMP_STATE_INTFVER));
	m_rpLCF_VehAlgoCompState.setVersion   ("AlgoCompState_t",           CreateVersionInfoFromI32(COMP_STATE_INTFVER));
	
	//test
	//m_rpCB_t_ProvidedOutputs.setVersion                 ("CB_t_ProvidedOutputs_t",                  CreateVersionInfoFromI32(CB_PROVIDED_OUTPUTS_INTFVER));

    // initialize input port map
    m_receivePortMap[&m_rpLcfVehOutputData].errorCount   = 0;
    m_receivePortMap[&m_rpLcfVehOutputData].checkForData = false;

	m_receivePortMap[&m_rpLcfVehOutputToSenData].errorCount   = 0;
    m_receivePortMap[&m_rpLcfVehOutputToSenData].checkForData = false;

	m_receivePortMap[&m_rpLcfSenOutputData].errorCount   = 0;
    m_receivePortMap[&m_rpLcfSenOutputData].checkForData = false;

	m_receivePortMap[&m_rpLcfSenOutputToVehData].errorCount   = 0;
    m_receivePortMap[&m_rpLcfSenOutputToVehData].checkForData = false;

	m_receivePortMap[&m_rpLcfInputData].errorCount   = 0;
    m_receivePortMap[&m_rpLcfInputData].checkForData = false;
	
#if defined(LCF_SEN_RPORT_PHLARADAROBJECTLIST)
	m_receivePortMap[&m_rpHlaRadarObjectList].errorCount   = 0;
    m_receivePortMap[&m_rpHlaRadarObjectList].checkForData = false;
#endif

#if defined(LCF_SEN_RPORT_PLSDENVIRONMENTDATA)
	m_receivePortMap[&m_rpLsdEnvironmentData].errorCount   = 0;
    m_receivePortMap[&m_rpLsdEnvironmentData].checkForData = false;
#endif

#if defined(LCF_SEN_RPORT_PCBOUTPUTS)
	m_receivePortMap[&m_rpCbOutputs].errorCount   = 0;
    m_receivePortMap[&m_rpCbOutputs].checkForData = false;
#endif

	m_receivePortMap[&m_rpAbdOutputData].errorCount   = 0;
    m_receivePortMap[&m_rpAbdOutputData].checkForData = false;

	m_receivePortMap[&m_rpVehDyn].errorCount   = 0;
    m_receivePortMap[&m_rpVehDyn].checkForData = false;

	m_receivePortMap[&m_rpVehSig].errorCount   = 0;
    m_receivePortMap[&m_rpVehSig].checkForData = false;

	m_receivePortMap[&m_rpVehPar].errorCount   = 0;
    m_receivePortMap[&m_rpVehPar].checkForData = false;
	
	m_receivePortMap[&m_rpLCF_SenDebugData].errorCount   = 0;
    m_receivePortMap[&m_rpLCF_SenDebugData].checkForData = false;
	
	m_receivePortMap[&m_rpLCF_VehDebugData].errorCount   = 0;
    m_receivePortMap[&m_rpLCF_VehDebugData].checkForData = false;

	m_receivePortMap[&m_rpLCF_SenAlgoCompState].errorCount   = 0;
    m_receivePortMap[&m_rpLCF_SenAlgoCompState].checkForData = false;

	m_receivePortMap[&m_rpLCF_VehAlgoCompState].errorCount   = 0;
    m_receivePortMap[&m_rpLCF_VehAlgoCompState].checkForData = false;

	AddDrawServerPort("LcfLaneOverlay",  DrawLcfGraphic, this);
	AddDrawServerPort("LDLaneOverlay",  DrawLDGraphic, this);
	AddDrawServerPort("LcfInfoOverlay",  DrawLcfInfo,    this);
	AddDrawServerPort("LcfInfoHMIOverlay",  DrawLcfHMIInfo,    this);
	AddDrawServerPort("LcfLegendOverlay",  DrawLCFLegend,    this);
	AddDrawServerPort("LcfStatusOverlay",  DrawLcfStatusInfo,    this);
	AddDrawServerPort("LcfFunctionTableOverlay",  DrawLcfFunctionTable,    this);
	AddDrawServerPort("LcfFunctionDrawLCFTableDebug",  DrawLCFTableDebug,    this);
	AddDrawServerPort("LcfFunctionBitfieldInfo",  DrawLCFBitfieldInfo,    this);

}

void CSimLcfVis::ResetReceiveErrors()
{
	for (ReceivePortMap_t::iterator i = m_receivePortMap.begin(); i != m_receivePortMap.end(); ++i)
    {
        i->second.errorCount = 0;
    }
}

void CSimLcfVis::Reset()
{
	// reset received flags
    ResetReceiveErrors();

    // setting for default values is only done if adapter is available
    FillRPortDefaultValues(Doit, this);

    // mark RPorts as not dirty
    ResetRPortDirtyFlags(Doit, this);

	/* Reset the number of Function Activation to start for the next recording with 0 */
	for (unsigned i = 0; i < SizeStatisticalArray; i++) {
		m_Function_Activation_Number[i] = 0;
	}

	/* Reset between two recordings loaded */
	LCF_SEN_Scheduler_Info = LCF_Scheduler_Check_t(0,0,0,0,0,0,1,0,0,0,0.0f);
	LCF_VEH_Scheduler_Info = LCF_Scheduler_Check_t(0,0,0,0,0,0,1,0,0,0,0.0f);

	/* Reset the queue */
	std::queue<unsigned int>().swap(LCF_SEN_Scheduler_Info.Buffer_Inst_TS_Difference);
	std::queue<unsigned int>().swap(LCF_VEH_Scheduler_Info.Buffer_Inst_TS_Difference);

    // TODO: Place reset stuff

}

void CSimLcfVis::Doit()
{
	if ( IsRequiredDataAvailable() )
    {
        // execute the algo calculation
        FillRPortDefaultValues(Doit, this);

        // TODO: place your plugin stuff here
		m_LcfVehOutputData = m_rpLcfVehOutputData.val();
        m_bLcfVehOutputDataValid = true;
		m_LcfVehOutputToSenData = m_rpLcfVehOutputToSenData.val();
        m_bLcfVehOutputToSenDataValid = true;
		m_LcfSenOutputData = m_rpLcfSenOutputData.val();
        m_bLcfSenOutputDataValid = true;
		m_LcfSenOutputToVehData = m_rpLcfSenOutputToVehData.val();
        m_bLcfSenOutputToVehDataValid = true;
		m_LcfInputData = m_rpLcfInputData.val();
        m_bLcfInputDataValid = true;
#if defined(LCF_SEN_RPORT_PHLARADAROBJECTLIST)
		m_HLA_RadarObjectListData = m_rpHlaRadarObjectList.val();
		m_bHlaRadarObjectList = true;
#endif
#if defined(LCF_SEN_RPORT_PLSDENVIRONMENTDATA)
		m_LSD_EnvironmentData = m_rpLsdEnvironmentData.val();
		m_bHlaRadarObjectList = true;
#endif
#if defined(LCF_SEN_RPORT_PCBOUTPUTS)
		m_CB_t_ProvidedOutputs = m_rpCbOutputs.val();
		m_bCbOutputs  = true;
#endif
		m_AbdOutputData = m_rpAbdOutputData.val();
		m_bAbdOutputDataValid = true;
		m_VehPar = m_rpVehPar.val();
        m_bVehParValid = true;
		m_VehSig = m_rpVehSig.val();
        m_bVehSigValid = true;
        m_VehDyn = m_rpVehDyn.val();
        m_bVehDynValid = true;
		m_LCF_SenDebugData = m_rpLCF_SenDebugData.val();
        m_bLCFSenDebugDataValid = true;
		m_LCF_VehDebugData = m_rpLCF_VehDebugData.val();
        m_bLCFVehDebugDataValid = true;
		m_LCF_SenAlgoCompState = m_rpLCF_SenAlgoCompState.val();
        m_bLCFSenAlgoCompState = true;
		m_LCF_VehAlgoCompState = m_rpLCF_VehAlgoCompState.val();
        m_bLCFVehAlgoCompState = true;

		m_LCF_TJASideObject = m_rpLCF_TJASideObject.val();
		m_LCF_TJATargetObject = m_rpLCF_TJATargetObject.val();

		m_LCF_SenOut_LeftLaneCorridor = m_rp_SenOut_LeftLaneCorridor.val();
		m_SenOut_LeftLaneCorridorValid = true;
		m_LCF_SenOut_RightLaneCorridor = m_rp_SenOut_RightLaneCorridor.val();
		m_SenOut_RightLaneCorridorValid = true;
		m_LCF_SenOut_TargetCorridor = m_rp_SenOut_TargetCorridor.val();
		m_SenOut_TargetCorridorValid = true;

		/* Collect Average time for LCF SEN / LCF VEH : Identifiy if there are GS problems */
		LCF_SchedulerData(LCF_SEN_Scheduler_Info, m_rp_SenOut_uiTimeStamp.val(), m_rp_SenOut_uiCycleCounter.val(), 60.0f);
		LCF_SchedulerData(LCF_VEH_Scheduler_Info, m_rp_VehOut_uiTimeStamp.val(), m_rp_VehOut_uiCycleCounter.val(), 10.0f);

        // mark RPorts used by Doit as not dirty
        ResetRPortDirtyFlags(Doit,this);

        // reset the received flags for the request ports
        ResetReceiveErrors();

        // trigger done port
        TriggerEvent(CP_CALCULATIONDONE, 0, 0);

    }
}

bool CSimLcfVis::IsRequiredDataAvailable()
{
    bool bEnableFlag = true;

	// general data loss handling
    for (ReceivePortMap_t::iterator i = m_receivePortMap.begin(); i != m_receivePortMap.end(); ++i)
    {
        SimReceivePortBase& port = *(i->first);
        SimReceivePortInfo& info = i->second;

        if (info.checkForData && (! port.isDirty()))
        {
            // increment error counter
            info.errorCount++;

            // disable plugin
            bEnableFlag = false;

            // report
            if (info.errorCount < MAX_REPORTED_PORT_ERRORS)
            {
                // print error message when below the counter
                std::stringstream err;
                err << "Input: " << port.name() << " data not received, LcfVis can't run.";

                ReportError(err_sev_error, 1, err.str().c_str());
            }
            else if (info.errorCount == MAX_REPORTED_PORT_ERRORS)
            {
                // print final error message
                std::stringstream err;
                err << "Input: " << port.name() << " data not received for " << info.errorCount << " cycles. No more Errors are generated";

                ReportError(err_sev_error, 1, err.str().c_str());
            }
        }
    }

    return bEnableFlag;
}

CVersionInfoImpl CSimLcfVis::CreateVersionInfoFromI32( const long version )
{
    return CVersionInfoImpl (
        static_cast<unsigned char>((version >> 16) & 0xFF),
        static_cast<unsigned char>((version >> 8)  & 0xFF),
        static_cast<unsigned char>( version        & 0xFF));
}


STRINGLIST CSimLcfVis::ParseComma(std::string line) {
	STRINGLIST list = STRINGLIST();
	std::string buffer = "";
	unsigned int i;
	for (i = 0; i < line.size(); i++) {
		char currentChar = line[i];
		if (currentChar == ',') {
			list.emplace_back(buffer);
			buffer = "";
		}
		else {
			buffer += line[i];
		}
		if (i == line.size() - 1) {
			list.emplace_back(buffer);
		}
	}
	return list;
}

BITFIELDMAP CSimLcfVis::getData(std::string& fileName)
{
	//Dictionary to be filled in this function
	NoOfColumnsCSV = 0;
	NoOfRowsCSV = 0;
	CSV_Open_Flag = false;

	RECTLIST CSVdata = RECTLIST();
	std::ifstream file;
	
	file.open(fileName);
	if (file.is_open()) {
		CSV_Open_Flag = true;
		std::string line;
			while (getline(file, line)) {
					STRINGLIST procLine = ParseComma(line);
					/*start of coordinates is 0...*/
					CSVdata.push_back(procLine);

					//Get no of columns / rows
					NoOfColumnsCSV = procLine.size();
					NoOfRowsCSV += 1;
			}
		file.close();
	}

	STRINGLIST Line;
	BITFIELDMAP LcfBitfield = BITFIELDMAP();

	if (CSV_Open_Flag != false) {
		for (unsigned char lin = 0; lin < CSVdata[0].size(); lin++) {
			Line = STRINGLIST();
			for (unsigned counter = 0; counter < CSVdata.size(); counter++) {
				//if (!CSVdata[counter][lin].empty())
				Line.push_back(CSVdata[counter][lin]);
			}
			LcfBitfield.insert(BITFIELDPAIR(Line[0],Line));
		}
	}
	else {
		STRINGLIST CSVNotLoaded = STRINGLIST();
		for(unsigned char i = 0; i < 33; i++) { CSVNotLoaded.push_back("CSV Not Loaded");}
		LcfBitfield.insert(BITFIELDPAIR("CSV_Not_Loaded", CSVNotLoaded));
	}
	return LcfBitfield;
}

void CSimLcfVis::DrawLcfLaneMarker( LCF_TrajPlanCorridor_t* corridor, GL::Color color )
{
	std::vector<GL::Pos> vecGlPos;
	float x, y, z, x_s, x_e, x_inc, delta_x, y_temp0, y_temp1, y_temp2, y_temp3;
	//uint32 i;

	x_s = max(corridor->CorridorPosX0_m, m_VehPar.VehParMain.WheelBase);
	x_e = corridor->CorridorPosX0_m + corridor->CorridorLength_m;
	x_inc = (x_e - x_s) / LCF_VIS_LANE_MRKR_NUM_PTS;

	x = x_s;
	while (x <= x_e)
	{
		delta_x = x - corridor->CorridorPosX0_m;
        y_temp0 = corridor->CorridorPosY0_m;
		y_temp1 = tan(corridor->CorridorHeading_rad) * delta_x;
		y_temp2 = 1.0f / 2.0f * (corridor->CorridorCrv_1pm) * delta_x * delta_x;
		y_temp3 = 1.0f / 6.0f * (corridor->CorridorChngOfCrv_1pm2) * delta_x * delta_x * delta_x;

		y = y_temp0 + y_temp1 + y_temp2 + y_temp3;

		z = 0.0f;

		GL::Pos pos(x - m_VehPar.VehParMain.WheelBase, y, z);
		vecGlPos.push_back(pos);

		if ((x - x_s) <= 10.0f)
		{
			x = x + min(x_inc, 0.01f);
		}
		else
		{
			x = x + x_inc;
		}
	}

	GL::Draw(vecGlPos, 5, color);
}

//ABD draw function
//lanePosition = 0 - Left, 1 - Right
//laneType = 0 - EgoMarker, 1 - EgoAdjacentMarker, 2 - RoadEdge
void CSimLcfVis::DrawABDMarker( AbdOutputData_t* laneStruct, unsigned int lanePosition, unsigned int laneType, GL::Color color )
{
	const unsigned int left = 0;
	const unsigned int right = 1;

	std::vector<GL::Pos> vecGlPos;
	float x, y, z, x_s, x_e, x_inc, delta_x, y_temp0, y_temp1, y_temp2, y_temp3;

	switch(lanePosition){
		case left:
			x_s =  m_VehPar.VehParMain.WheelBase;
			x_e = /*corridor->CorridorPosX0_m*/ 0 + laneStruct->asLaneBoundary[laneStruct->sLaneInformation.aiLaneBoundariesLeft[laneType]].sGeometry.sParameters.sClothoidNear.fValidLengthMeter;
			x_inc = (x_e - x_s) / LCF_VIS_LANE_MRKR_NUM_PTS;

			x = x_s;
			while (x <= x_e)
			{
				delta_x = x - 0/*corridor->CorridorPosX0_m*/;
				y_temp0 = laneStruct->asLaneBoundary[laneStruct->sLaneInformation.aiLaneBoundariesLeft[laneType]].sGeometry.sParameters.fDistanceMeter;
				y_temp1 = tan((-1.0f) * laneStruct->asLaneBoundary[laneStruct->sLaneInformation.aiLaneBoundariesLeft[laneType]].sGeometry.sParameters.fYawAngleRad) * delta_x;
				y_temp2 = 1.0f / 2.0f * (laneStruct->asLaneBoundary[laneStruct->sLaneInformation.aiLaneBoundariesLeft[laneType]].sGeometry.sParameters.sClothoidNear.fCurvature) * delta_x * delta_x;
				y_temp3 = 1.0f / 6.0f * (laneStruct->asLaneBoundary[laneStruct->sLaneInformation.aiLaneBoundariesLeft[laneType]].sGeometry.sParameters.sClothoidNear.fCurvatureRate) * delta_x * delta_x * delta_x;

				y = y_temp0 + y_temp1 + y_temp2 + y_temp3;

				z = 0.0f;

				GL::Pos pos(x - m_VehPar.VehParMain.WheelBase, y, z);
				vecGlPos.push_back(pos);

				if ((x - x_s) <= 10.0f)
				{
					x = x + min(x_inc, 0.01f);
				}
				else
				{
					x = x + x_inc;
				}
			}

			break;
		case right:

			x_s =  m_VehPar.VehParMain.WheelBase;
			x_e = /*corridor->CorridorPosX0_m*/ 0 + laneStruct->asLaneBoundary[laneStruct->sLaneInformation.aiLaneBoundariesRight[laneType]].sGeometry.sParameters.sClothoidNear.fValidLengthMeter;
			x_inc = (x_e - x_s) / LCF_VIS_LANE_MRKR_NUM_PTS;
			x = x_s;
			while (x <= x_e)
			{
				delta_x = x - 0/*corridor->CorridorPosX0_m*/;
				 //multiplication with -1 is not needed anymore
				y_temp0 = /*(-1.0f) **/ laneStruct->asLaneBoundary[laneStruct->sLaneInformation.aiLaneBoundariesRight[laneType]].sGeometry.sParameters.fDistanceMeter;
				y_temp1 = tan((-1.0f) * laneStruct->asLaneBoundary[laneStruct->sLaneInformation.aiLaneBoundariesRight[laneType]].sGeometry.sParameters.fYawAngleRad) * delta_x;
				y_temp2 = 1.0f / 2.0f * (laneStruct->asLaneBoundary[laneStruct->sLaneInformation.aiLaneBoundariesRight[laneType]].sGeometry.sParameters.sClothoidNear.fCurvature) * delta_x * delta_x;
				y_temp3 = 1.0f / 6.0f * (laneStruct->asLaneBoundary[laneStruct->sLaneInformation.aiLaneBoundariesRight[laneType]].sGeometry.sParameters.sClothoidNear.fCurvatureRate) * delta_x * delta_x * delta_x;

				y = y_temp0 + y_temp1 + y_temp2 + y_temp3;

				z = 0.0f;

				GL::Pos pos(x - m_VehPar.VehParMain.WheelBase, y, z);
				vecGlPos.push_back(pos);

				if ((x - x_s) <= 10.0f)
				{
					x = x + min(x_inc, 0.01f);
				}
				else
				{
					x = x + x_inc;
				}
			}

			break;
	}

	GL::Draw(vecGlPos, 2, color);
}

void CSimLcfVis::DrawLcfGraphic( const ISimRenderContext& ctx )
{
	uint8 ui8LaneValidQual;
	GL::Color color_left;
	GL::Color color_right;
	GL::Color color_target;
	
	color_target = GL::Color::teal;
	
	GL::Init();
	
#ifdef LCF_MFC431_RELEASE_0800_RTE_INT01
	/*
	Bit 0: Left lane valid only
	Bit 1: Right lane valid only 
	Bit 2: Left lane bridged
	Bit 3: Right lane bridged 
	Bit 4: Left lane LD virtual 
	Bit 5: Right lane LD virtual
	Bit 6: Both lane markers valid
	Bit 7:
	*/
	
	ui8LaneValidQual = m_rp_S_ABPLBP_LaneValidQualVis_nu.val();    /* Use the debug signal; m_LcfSenOutputData.Visualization.LaneValidQualVis_nu is used for another purpose. */
	
	ui8LaneValidQual = ui8LaneValidQual & 207;//remove LD virtual bits
	
	if (m_bLcfSenOutputDataValid && m_bVehParValid && m_SenOut_LeftLaneCorridorValid && m_SenOut_RightLaneCorridorValid && m_SenOut_TargetCorridorValid && (m_VehPar.VehParMain.WheelBase != 0))
    {
		switch(ui8LaneValidQual)
		{
		case 1://left lane valid only
			color_left = GL::Color::yellow;
			color_right = GL::Color::gray;
			break; 
		case 2://right lane valid only
			color_left = GL::Color::gray;
			color_right = GL::Color::yellow;
			break; 
		case 4://left lane bridged
			color_left = GL::Color::violet;
			color_right = GL::Color::yellow;
			break; 
		case 8: //right lane bridged
			color_left = GL::Color::yellow;
			color_right = GL::Color::violet;
			break;
		case 16://right lane virtual LD
			color_left = GL::Color::black;
			color_right = GL::Color::orange;
			break; 
		case 32://left lane virtual LD
			color_left = GL::Color::orange;
			color_right = GL::Color::black;
			break; 
		case 64: //both lanes valid
			color_left = GL::Color::yellow;
			color_right = GL::Color::yellow;
			break;
		default:
			color_left = GL::Color::red;
			color_right = GL::Color::red;
		}
		//if lanes are available
		if(ui8LaneValidQual != 0) {
			if (SelectTrajDraw != 3)
			{
				DrawLcfLaneMarker(&(m_LCF_SenOut_LeftLaneCorridor), color_left);
				DrawLcfLaneMarker(&(m_LCF_SenOut_RightLaneCorridor), color_right);
			}

			if ((SelectTrajDraw == 0) || (SelectTrajDraw == 1))
				DrawLcfLaneMarker(&(m_LCF_SenOut_TargetCorridor), color_target); 
			
		}
		/*Draw planned trajectory*/
		if ((SelectTrajDraw == 0) || (SelectTrajDraw == 2) || (SelectTrajDraw == 3))
			DrawLcfTrajectory( GL::Color::fuchsia);
    }
	
	
#else
	ui8LaneValidQual = m_LcfSenOutputData.Visualization.LaneValidQualifier_nu;
	
    if (m_bLcfSenOutputDataValid && m_bVehParValid)
    {
		switch(ui8LaneValidQual)
		{
		case E_ABPLBP_LQ_LE_EGO_LN_VIRTUAL:
			color_left = GL::Color::red;
			color_right = GL::Color::yellow;
			break; 
		case E_ABPLBP_LQ_RI_EGO_LN_VIRTUAL:
			color_left = GL::Color::yellow;
			color_right = GL::Color::red;
			break; 
		case E_ABPLBP_LQ_BOTH_EGO_LN_VALID:
			color_left = GL::Color::yellow;
			color_right = GL::Color::yellow;
			break; 	
		default:
			color_left = GL::Color::red;
			color_right = GL::Color::red;
		}
        DrawLcfLaneMarker(&(m_LcfSenOutputData.Visualization.AllCorridors.LeftCorridor), color_left);
		DrawLcfLaneMarker(&(m_LcfSenOutputData.Visualization.AllCorridors.RightCorridor), color_right);
		//DrawLcfLaneMarker(&(m_LcfSenOutputData.Visualization.AllCorridors.TargetCorridor), color_target);
		
		//////
		DrawLcfTrajectory(GL::Color::fuchsia);
    }
#endif
}

void CSimLcfVis::DrawLDGraphic( const ISimRenderContext& ctx )
{
	GL::Color color_left;
	GL::Color color_right;
	GL::Color color_left_adjacent;
	GL::Color color_right_adjacent;

	//in lack of any defines for these positions I had to make my own static variables -- to be clarified with LD team
	const unsigned int left = 0;
	const unsigned int right = 1;

	GL::Init();

    if (m_bAbdOutputDataValid && m_bVehParValid)
    {	//left marker status and colour
		switch(m_AbdOutputData.asLaneBoundary[m_AbdOutputData.sLaneInformation.aiLaneBoundariesLeft[ABD_EGO_MARKER]].sStatus.iQuality)
		{
		case NOT_AVAILABLE_LDLQS:  // 2022/09/01 Chengyou, Tang : Modify because MFC5J3 project define a MACRO named NOT_AVAILABLE
			color_left = GL::Color::red;
			break;
		case VIRTUAL_LANE:
			color_left = GL::Color::violet;
			break;
		case NEAR_DEATH:
			color_left = GL::Color::navy;
			break;
		case PREDICTED:
			color_left = GL::Color::olive;
			break;
		case ROAD_EDGE:
			color_left = GL::Color::aqua;
			break;
		case EXIT_RAMP:
			color_left = GL::Color::lightGray;
			break;
		case HIGH_QUALITY:
			color_left = GL::Color::blue;
			break;
		default:
			color_left = GL::Color::red;
		}
		//right marker status and colour
		switch(m_AbdOutputData.asLaneBoundary[m_AbdOutputData.sLaneInformation.aiLaneBoundariesRight[ABD_EGO_MARKER]].sStatus.iQuality)
		{
		case NOT_AVAILABLE_LDLQS:  // 2022/09/01 Chengyou, Tang : Modify because MFC5J3 project define a MACRO named NOT_AVAILABLE
			color_right = GL::Color::red;
			break;
		case VIRTUAL_LANE:
			color_right = GL::Color::violet;
			break;
		case NEAR_DEATH:
			color_right = GL::Color::navy;
			break;
		case PREDICTED:
			color_right = GL::Color::olive;
			break;
		case ROAD_EDGE:
			color_right = GL::Color::aqua;
			break;
		case EXIT_RAMP:
			color_right = GL::Color::lightGray;
			break;
		case HIGH_QUALITY:
			color_right = GL::Color::blue;
			break;
		default:
			color_right = GL::Color::red;
		}
		//left adjacent marker status and colour
		switch(m_AbdOutputData.asLaneBoundary[m_AbdOutputData.sLaneInformation.aiLaneBoundariesLeft[ABD_EGO_ADJACENT_MARKER]].sStatus.iQuality)
		{
		case NOT_AVAILABLE_LDLQS:  // 2022/09/01 Chengyou, Tang : Modify because MFC5J3 project define a MACRO named NOT_AVAILABLE
			color_left_adjacent = GL::Color::red;
			break;
		case VIRTUAL_LANE:
			color_left_adjacent = GL::Color::violet;
			break;
		case NEAR_DEATH:
			color_left_adjacent = GL::Color::navy;
			break;
		case PREDICTED:
			color_left_adjacent = GL::Color::olive;
			break;
		case ROAD_EDGE:
			color_left_adjacent = GL::Color::aqua;
			break;
		case EXIT_RAMP:
			color_left_adjacent = GL::Color::lightGray;
			break;
		case HIGH_QUALITY:
			color_left_adjacent = GL::Color::blue;
			break;
		default:
			color_left_adjacent = GL::Color::red;
		}
		//right adjacent marker status and colour
		switch(m_AbdOutputData.asLaneBoundary[m_AbdOutputData.sLaneInformation.aiLaneBoundariesRight[ABD_EGO_ADJACENT_MARKER]].sStatus.iQuality)
		{
		case NOT_AVAILABLE_LDLQS:  // 2022/09/01 Chengyou, Tang : Modify because MFC5J3 project define a MACRO named NOT_AVAILABLE
			color_right_adjacent = GL::Color::red;
			break;
		case VIRTUAL_LANE:
			color_right_adjacent = GL::Color::violet;
			break;
		case NEAR_DEATH:
			color_right_adjacent = GL::Color::navy;
			break;
		case PREDICTED:
			color_right_adjacent = GL::Color::olive;
			break;
		case ROAD_EDGE:
			color_right_adjacent = GL::Color::aqua;
			break;
		case EXIT_RAMP:
			color_right_adjacent = GL::Color::lightGray;
			break;
		case HIGH_QUALITY:
			color_right_adjacent = GL::Color::blue;
			break;
		default:
			color_right_adjacent = GL::Color::red;
		}

		if(m_AbdOutputData.asLaneBoundary[m_AbdOutputData.sLaneInformation.aiLaneBoundariesLeft[ABD_EGO_MARKER]].sStatus.bAvailable){
			DrawABDMarker(&(m_AbdOutputData), left, ABD_EGO_MARKER, color_left);
			}
		if(m_AbdOutputData.asLaneBoundary[m_AbdOutputData.sLaneInformation.aiLaneBoundariesRight[ABD_EGO_MARKER]].sStatus.bAvailable){
			DrawABDMarker(&(m_AbdOutputData), right, ABD_EGO_MARKER, color_right);
			}
		if(m_AbdOutputData.asLaneBoundary[m_AbdOutputData.sLaneInformation.aiLaneBoundariesLeft[ABD_EGO_ADJACENT_MARKER]].sStatus.bAvailable){
			DrawABDMarker(&(m_AbdOutputData), left, ABD_EGO_ADJACENT_MARKER, color_left_adjacent);
		}
		if(m_AbdOutputData.asLaneBoundary[m_AbdOutputData.sLaneInformation.aiLaneBoundariesRight[ABD_EGO_ADJACENT_MARKER]].sStatus.bAvailable){
			DrawABDMarker(&(m_AbdOutputData), right, ABD_EGO_ADJACENT_MARKER, color_right_adjacent);
		}

    }
}

const char* CSimLcfVis::LcofLatCtrlModeToString(unsigned char input, char* debs)
{
    memset(debs, 0, sizeof(debs));
    switch(input)
    {
    case LCF_TJA_SYS_COORD_LAT_CTRL_MODE_PASSIVE:
        sprintf(debs, "%d = PASSIVE", input);
        break;
    case LCF_TJA_SYS_COORD_LAT_CTRL_MODE_LANE_CENTERING:
        sprintf(debs, "%d = LANE_CENTERING", input);
        break;
	case LCF_TJA_SYS_COORD_LAT_CTRL_MODE_PURSUIT_NO_LANE_BOUNDS:
        sprintf(debs, "%d = PURSUIT_NO_LANE_BOUNDS", input);
        break;
	case LCF_TJA_SYS_COORD_LAT_CTRL_MODE_PURSUIT_CLOSE_TO_RIGHT_BOUND:
        sprintf(debs, "%d = PURSUIT_CLOSE_TO_RIGHT_BOUND", input);
        break;
	case LCF_TJA_SYS_COORD_LAT_CTRL_MODE_PURSUIT_CLOSE_TO_LEFT_BOUND:
        sprintf(debs, "%d = PURSUIT_CLOSE_TO_LEFT_BOUND", input);
        break;
	case LCF_TJA_SYS_COORD_LAT_CTRL_MODE_PURSUIT_WITH_LANE_BOUNDARIES:
        sprintf(debs, "%d = PURSUIT_WITH_LANE_BOUNDARIES", input);
        break;
	case LCF_TJA_SYS_COORD_LAT_CTRL_MODE_DEGRADATION:
        sprintf(debs, "%d = DEGRADATION", input);
        break;
    default:
        sprintf(debs, "%d = Invalid", input);
    }
    return debs;
}

static const char* LcofValueToString(float input, char* debs, const unsigned char InfoKey = 0)
{
    memset(debs, 0, sizeof(debs));

	switch(InfoKey)
	{
	case 1:
		sprintf(debs, "%.2f  [perc]", input);
		break;
	default:
		sprintf(debs, "%g", input);
		break;
	}

    return debs;
}

static const char* LcofValueToString(unsigned char input, char* debs)
{
    memset(debs, 0, sizeof(debs));
    sprintf(debs, "%u", input);
    return debs;
}

static const char* LcofValueToString(unsigned short input, char* debs)
{
    memset(debs, 0, sizeof(debs));
    sprintf(debs, "%u", input);
    return debs;
}

static const char* LcofValueToString(signed char input, char* debs)
{
    memset(debs, 0, sizeof(debs));
    sprintf(debs, "%d", input);
    return debs;
}

static const char* LcofValueToString(signed long input, char* debs)
{
    memset(debs, 0, sizeof(debs));
    sprintf(debs, "%ld", input);
    return debs;
}

static const char* LcofValueToString(std::queue <unsigned int> input, char* debs, const unsigned char SpecificMode = 0)
{
    memset(debs, 0, sizeof(debs));
    unsigned char idx;

	/* Remove first elements if is the case */
	for (idx = 0; idx < (SpecificMode * 3); idx++) {
		if (input.size() != 0) 
		{
			input.pop();
		}
	}

	/* Reset to use in the next iteration*/
	idx = 0;

	while (!input.empty())
	{
		if (idx >= 2 || (SpecificMode == 3 && idx == 1)) {
			sprintf(debs + strlen(debs), "%d", input.front());
		}
		else {
			sprintf(debs + strlen(debs), "%d, ", input.front());
		}
		input.pop();
		idx += 1;

		if (idx >= 3) {
			break;
		}
	}

    return debs;
}

static const char* LcofValueToString(unsigned int input, char* debs, const unsigned char InfoKey = 0)
{
    memset(debs, 0, sizeof(debs));

	const static string Info_LaneMarkerType[10] = {"No Line", "Continuous", "Dashed", "Decorative", "Dotted Cont", "Dotted Dashed", "Elev Continuous", "Elev Discrete", "Curbstone", "RoadEdge"};
	const static string Info_LaneMarkerColor[6] = {"Unclassified", "White", "Yellow", "Red", "Blue", "Green"};

	if (InfoKey == 31 && (input >= 0 && input < 10))
		sprintf(debs, "%u  ( %s )", input, Info_LaneMarkerType[input].c_str());
	else if (InfoKey == 32 && (input >= 0 && input < 6))
		sprintf(debs, "%u  ( %s )", input, Info_LaneMarkerColor[input].c_str());
	else if (InfoKey == 40)
		sprintf(debs, "SW_LCF_%02x.%02x.%02x.%02x", (input >> 24), ((input >> 16) & 0xFF), ((input >> 8) & 0xFF), (input & 0xFF)); 
	else if (InfoKey == 41)
		sprintf(debs, "DPU_%03u.%03u.%02u", ((input >> 16) & 0xFF), ((input >> 8) & 0xFF), (input & 0xFF));
	else if (InfoKey == 42)
		sprintf(debs, "%g ms", (float(input)/1000.0f));
	else
		sprintf(debs, "%u", input);
    return debs;
}

static const char* LcofValueToString(unsigned char *input, char* debs, unsigned short size_array)
{
    memset(debs, 0, sizeof(debs));
	for(unsigned char i = 0; i < size_array; i++)
	{
		if (i+1 != size_array) {
			sprintf(debs + strlen(debs), "%u,", input[i]);
		}
		else { 
			sprintf(debs + strlen(debs), "%u", input[i]);
		}
	}
    return debs;
}

static const char* LcofValueToString(unsigned int *input, char* debs, unsigned short size_array)
{
    memset(debs, 0, sizeof(debs));
	for(unsigned char i = 0; i < size_array; i++)
	{
		if (i+1 != size_array) {
			sprintf(debs + strlen(debs), "%u,", input[i]);
		}
		else { 
			sprintf(debs + strlen(debs), "%u", input[i]);
		}
	}
    return debs;
}

static const char* CheckBitPosition(unsigned int input, unsigned char bit_pos, char* debs)
{
    memset(debs, 0, sizeof(debs));
    sprintf(debs, "%d", bool(CHECK_BIT(input, bit_pos)));
    return debs;
}

void CSimLcfVis::Add_LD_Signals(IGDVFont& font, int start_y_coord, int x_coord_c1, int x_coord_c2, unsigned short y_offset_inc, bool ValidData)
{
	char debugString[100];
	unsigned char step = 0;

	vector <string> LD_Signal_Names;
	LD_Signal_Names.push_back("S_LCFRCV_AnyBndDistance_met");
	LD_Signal_Names.push_back("S_LCFRCV_AnyBndYawAngle_rad");
	LD_Signal_Names.push_back("S_LCFRCV_AnyBndValidLength_met");
	LD_Signal_Names.push_back("S_LCFRCV_AnyBndCurvature_1pm");
	LD_Signal_Names.push_back("S_LCFRCV_AnyBndQuality_nu");
	LD_Signal_Names.push_back("S_LCFRCV_AnyBndMarkerType_nu");
	LD_Signal_Names.push_back("S_LCFRCV_AnyBndColor_nu");

	signed char aiLaneBoundaries[6] = {m_AbdOutputData.sLaneInformation.aiLaneBoundariesLeft[ABD_EGO_MARKER], m_AbdOutputData.sLaneInformation.aiLaneBoundariesRight[ABD_EGO_MARKER], 
										   m_AbdOutputData.sLaneInformation.aiLaneBoundariesLeft[ABD_EGO_ADJACENT_MARKER], m_AbdOutputData.sLaneInformation.aiLaneBoundariesRight[ABD_EGO_ADJACENT_MARKER], 
										   m_AbdOutputData.sLaneInformation.aiLaneBoundariesLeft[ABD_ROAD_EDGE], m_AbdOutputData.sLaneInformation.aiLaneBoundariesRight[ABD_ROAD_EDGE]};
	if (!m_bDrawHelp) {
		if(ValidData) 
		{
			for(unsigned char i = 0; i < LD_Signal_Names.size(); i++)
			{
				for(unsigned char j = 0; j < 6; j++, step++)
				{	
					if (step >= 21)
					{
						x_coord_c1 += 445;
						x_coord_c2 += 453;
						step = 0;
						start_y_coord = 45;
					}

					font.SetTextColor( colorWhite.r, colorWhite.g, colorWhite.b, colorWhite.a);
					memset(debugString, 0, sizeof(debugString));
					sprintf(debugString, "%s[%d]",LD_Signal_Names[i].c_str(),  j);
					font.RenderTextf(x_coord_c1, start_y_coord + y_offset_inc* step, 0, debugString);

					font.SetTextColor(colorLime.r, colorLime.g, colorLime.b, colorLime.a);
					switch(i)
					{
					case 0:
						font.RenderTextf(x_coord_c2, start_y_coord + y_offset_inc* step, 0, LcofValueToString(m_AbdOutputData.asLaneBoundary[aiLaneBoundaries[j]].sGeometry.sParameters.fDistanceMeter, debugString));
						break;
					case 1:
						font.RenderTextf(x_coord_c2, start_y_coord + y_offset_inc* step, 0, LcofValueToString(m_AbdOutputData.asLaneBoundary[aiLaneBoundaries[j]].sGeometry.sParameters.fYawAngleRad * (-1.0f), debugString));
						break;
					case 2:
						font.RenderTextf(x_coord_c2, start_y_coord + y_offset_inc* step, 0, LcofValueToString(m_AbdOutputData.asLaneBoundary[aiLaneBoundaries[j]].sGeometry.sParameters.sClothoidNear.fValidLengthMeter, debugString));
						break;
					case 3:
						font.RenderTextf(x_coord_c2, start_y_coord + y_offset_inc* step, 0, LcofValueToString(m_AbdOutputData.asLaneBoundary[aiLaneBoundaries[j]].sGeometry.sParameters.sClothoidNear.fCurvature, debugString));
						break;
					case 4:
						font.RenderTextf(x_coord_c2, start_y_coord + y_offset_inc* step, 0, LcofValueToString(m_AbdOutputData.asLaneBoundary[aiLaneBoundaries[j]].sStatus.iQuality, debugString));
						break;
					case 5:
						font.RenderTextf(x_coord_c2, start_y_coord + y_offset_inc* step, 0, LcofValueToString(m_AbdOutputData.asLaneBoundary[aiLaneBoundaries[j]].sAttributes.sType.eType, debugString, 31));
						break;
					case 6:
						font.RenderTextf(x_coord_c2, start_y_coord + y_offset_inc* step, 0, LcofValueToString(m_AbdOutputData.asLaneBoundary[aiLaneBoundaries[j]].sAttributes.eColor, debugString, 32));
						break;
					default:
						break;
					}
				}
			}

			DrawTextLCF(x_coord_c1, start_y_coord + y_offset_inc* step++, unsigned short(x_coord_c2 - x_coord_c1), colorWhite, colorLime, "S_LCFRCV_LaneChange_nu", font, LcofValueToString(m_AbdOutputData.eLaneChange, debugString), 33);
			DrawTextLCF(x_coord_c1, start_y_coord + y_offset_inc* step++, unsigned short(x_coord_c2 - x_coord_c1), colorWhite, colorLime, "ABD_eSigStatus", font, LcofValueToString(m_AbdOutputData.sSigHeader.eSigStatus, debugString), 36);
			DrawTextLCF(x_coord_c1, start_y_coord + y_offset_inc* step++, unsigned short(x_coord_c2 - x_coord_c1), colorWhite, colorLime, "ABD_uiMeasurementCounter", font, LcofValueToString(m_AbdOutputData.sSigHeader.uiMeasurementCounter, debugString));
			DrawTextLCF(x_coord_c1, start_y_coord + y_offset_inc* step++, unsigned short(x_coord_c2 - x_coord_c1), colorWhite, colorLime, "ABD_uiCycleCounter", font, LcofValueToString(m_AbdOutputData.sSigHeader.uiCycleCounter, debugString));
			DrawTextLCF(x_coord_c1, start_y_coord + y_offset_inc* step++, unsigned short(x_coord_c2 - x_coord_c1), colorWhite, colorLime, "ABD_uiTimeStamp", font, LcofValueToString(m_AbdOutputData.sSigHeader.uiTimeStamp, debugString));
		}
		else {
			for( unsigned char counter = 0; counter < 21; counter++) {
				DrawTextLCF(x_coord_c1, start_y_coord + y_offset_inc* counter, (unsigned short)(x_coord_c2 - x_coord_c1), colorRed, colorRed, "No Valid Data in ABD Port", font, "Update LCFVis dll file !");
			}
		}
	}
}

void CSimLcfVis::Add_VehDyn_Signals(IGDVFont& font, int start_y_coord, int x_coord_c1, unsigned short offset, unsigned short y_offset_inc, bool ValidData)
{
	char debugString[100];
	unsigned char step = 1;

	if (!m_bDrawHelp) {
		if(ValidData) 
		{
			DrawTextLCF(x_coord_c1, start_y_coord, offset, colorWhite, colorLime, "S_LCFRCV_VehVelX_mps", font, LcofValueToString(m_VehDyn.Longitudinal.Velocity, debugString));
			DrawTextLCF(x_coord_c1, start_y_coord + y_offset_inc* step++, offset, colorWhite, colorLime, "S_LCFRCV_VehAclY_mps2", font, LcofValueToString(m_VehDyn.Lateral.Accel.LatAccel, debugString));
			DrawTextLCF(x_coord_c1, start_y_coord + y_offset_inc* step++, offset, colorWhite, colorLime, "S_LCFRCV_VehAclX_mps2", font, LcofValueToString(m_VehDyn.Longitudinal.Accel, debugString));
			DrawTextLCF(x_coord_c1, start_y_coord + y_offset_inc* step++, offset, colorWhite, colorLime, "S_LCFRCV_VehMotionState_enum", font, LcofValueToString(m_VehDyn.MotionState.MotState, debugString), 25);
			DrawTextLCF(x_coord_c1, start_y_coord + y_offset_inc* step++, offset, colorWhite, colorLime, "S_LCFRCV_VehYawRate_rps", font, LcofValueToString(m_VehDyn.Lateral.YawRate.YawRate, debugString));
			DrawTextLCF(x_coord_c1, start_y_coord + y_offset_inc* step++, offset, colorWhite, colorLime, "S_LCFRCV_VehYawRateStd_radps", font, LcofValueToString(m_VehDyn.Lateral.YawRate.Variance, debugString));
			DrawTextLCF(x_coord_c1, start_y_coord + y_offset_inc* step++, offset, colorWhite, colorLime, "S_LCFRCV_VehCrv_1pm", font, LcofValueToString(m_VehDyn.Lateral.Curve.Curve, debugString));
			#if (VDY_VEH_DYN_INTFVER >= 33)
			DrawTextLCF(x_coord_c1, start_y_coord + y_offset_inc* step++, offset, colorWhite, colorLime, "S_LCFRCV_RoadBankAngle_rad", font, LcofValueToString(m_VehDyn.Lateral.SelfSteering.RoadBankAngle, debugString));
			DrawTextLCF(x_coord_c1, start_y_coord + y_offset_inc* step++, offset, colorWhite, colorLime, "S_LCFRCV_QuRoadBankAngle_nu", font, LcofValueToString(m_VehDyn.Lateral.SelfSteering.QuRoadBankAngle, debugString));
			DrawTextLCF(x_coord_c1, start_y_coord + y_offset_inc* step++, offset, colorWhite, colorLime, "S_LCFRCV_SelfSteerGradEst_rads2pm", font, LcofValueToString(m_VehDyn.Lateral.SelfSteering.SelfSteerGradEst, debugString));
			DrawTextLCF(x_coord_c1, start_y_coord + y_offset_inc* step++, offset, colorWhite, colorLime, "S_LCFRCV_QuSelfSteerGradEst_nu", font, LcofValueToString(m_VehDyn.Lateral.SelfSteering.SelfSteerGradEst, debugString));
			#endif
			DrawTextLCF(x_coord_c1, start_y_coord + y_offset_inc* step++, offset, colorWhite, colorLime, "S_LCFRCV_TurnSignalState_enum", font, LcofValueToString(m_VehSig.VehSigAdd.TurnSignal, debugString), 26);
			DrawTextLCF(x_coord_c1, start_y_coord + y_offset_inc* step++, offset, colorWhite, colorLime, "S_LCFRCV_WiperStage_nu", font, LcofValueToString(m_VehSig.VehSigAdd.WiperStage, debugString), 27);
			DrawTextLCF(x_coord_c1, start_y_coord + y_offset_inc* step++, offset, colorWhite, colorLime, "S_LCFRCV_WiperState_nu", font, LcofValueToString(m_VehSig.VehSigAdd.WiperState, debugString), 28);
			DrawTextLCF(x_coord_c1, start_y_coord + y_offset_inc* step++, offset, colorWhite, colorLime, "S_LCFRCV_CurrentGear_enum", font, LcofValueToString(m_VehSig.VehSigMain.ActGearPos, debugString), 29);
			DrawTextLCF(x_coord_c1, start_y_coord + y_offset_inc* step++, offset, colorWhite, colorLime, "S_LCFRCV_SteerAngFrontAxleEff_rad", font, LcofValueToString(m_VehSig.VehSigAdd.RoadWhlAngFr, debugString));
			DrawTextLCF(x_coord_c1, start_y_coord + y_offset_inc* step++, offset, colorWhite, colorLime, "S_LCFRCV_AccelPedalPos_nu", font, LcofValueToString(m_VehSig.VehSigAdd.GasPedalPos, debugString));
			DrawTextLCF(x_coord_c1, start_y_coord + y_offset_inc* step++, offset, colorWhite, colorLime, "S_LCFRCV_VDy_VehVelocity_kph", font, LcofValueToString(m_VehSig.VehSigAdd.SpeedoSpeed, debugString));
			DrawTextLCF(x_coord_c1, start_y_coord + y_offset_inc* step++, offset, colorWhite, colorLime, "S_LCFRCV_BrkPedlPressed_bool", font, LcofValueToString(m_VehSig.VehSigAdd.BrakePedalPressed, debugString));
			DrawTextLCF(x_coord_c1, start_y_coord + y_offset_inc* step++, offset, colorWhite, colorLime, "TrailerConnection", font, LcofValueToString(m_VehSig.VehSigAdd.TrailerConnection, debugString), 30);
		}
		else {
			for( unsigned char counter = 0; counter < 21; counter++) {
				DrawTextLCF(x_coord_c1, start_y_coord + y_offset_inc* counter, offset, colorRed, colorRed, "No Valid Data in VDY Port", font, "Update LCFVis dll file !");
			}
		}
	}
}

void CSimLcfVis::Add_Output_Signals(IGDVFont& font, int start_y_coord, int x_coord_c1, unsigned short offset, unsigned short y_offset_inc, unsigned char idxSelect, bool *Data_Validity)
{
	char debugString[100];
	unsigned char step = 1;

	if ((idxSelect == 0 || idxSelect == 1) && !m_bDrawHelp && Data_Validity[0]) { /* LCF Sen Output Port */
        DrawTextLCF(x_coord_c1, start_y_coord, offset, colorWhite, CHECK_IS_CONNECTED(m_rp_LDWSystemState_nu), "LDWSystemState_nu", font, CHECK_PORT_AVAIL_SYSSTATE(m_rp_LDWSystemState_nu, debugString));
        DrawTextLCF(x_coord_c1, start_y_coord + y_offset_inc* step++, offset, colorWhite, CHECK_IS_CONNECTED(m_rp_LDWSystemStateLeft_nu), "LDWSystemStateLeft_nu", font, CHECK_PORT_AVAIL(m_rp_LDWSystemStateLeft_nu, debugString));
        DrawTextLCF(x_coord_c1, start_y_coord + y_offset_inc* step++, offset, colorWhite, CHECK_IS_CONNECTED(m_rp_LDWSystemStateRight_nu), "LDWSystemStateRight_nu", font, CHECK_PORT_AVAIL(m_rp_LDWSystemStateRight_nu, debugString));
        DrawTextLCF(x_coord_c1, start_y_coord + y_offset_inc* step++, offset, colorWhite, CHECK_IS_CONNECTED(m_rp_LDPSystemState_nu), "LDPSystemState_nu", font, CHECK_PORT_AVAIL_SYSSTATE(m_rp_LDPSystemState_nu, debugString));
        DrawTextLCF(x_coord_c1, start_y_coord + y_offset_inc* step++, offset, colorWhite, CHECK_IS_CONNECTED(m_rp_LDPSystemStateLeft_nu), "LDPSystemStateLeft_nu", font, CHECK_PORT_AVAIL(m_rp_LDPSystemStateLeft_nu, debugString));
        DrawTextLCF(x_coord_c1, start_y_coord + y_offset_inc* step++, offset, colorWhite, CHECK_IS_CONNECTED(m_rp_LDPSystemStateRight_nu), "LDPSystemStateRight_nu", font, CHECK_PORT_AVAIL(m_rp_LDPSystemStateRight_nu, debugString));
        DrawTextLCF(x_coord_c1, start_y_coord + y_offset_inc* step++, offset, colorWhite, CHECK_IS_CONNECTED(m_rp_RDPSystemState_nu), "RDPSystemState_nu", font, CHECK_PORT_AVAIL_SYSSTATE(m_rp_RDPSystemState_nu, debugString));
        DrawTextLCF(x_coord_c1, start_y_coord + y_offset_inc* step++, offset, colorWhite, CHECK_IS_CONNECTED(m_rp_RDPSystemStateLeft_nu), "RDPSystemStateLeft_nu", font, CHECK_PORT_AVAIL(m_rp_RDPSystemStateLeft_nu, debugString));
        DrawTextLCF(x_coord_c1, start_y_coord + y_offset_inc* step++, offset, colorWhite, CHECK_IS_CONNECTED(m_rp_RDPSystemStateRight_nu), "RDPSystemStateRight_nu", font, CHECK_PORT_AVAIL(m_rp_RDPSystemStateRight_nu, debugString));
        DrawTextLCF(x_coord_c1, start_y_coord + y_offset_inc* step++, offset, colorWhite, CHECK_IS_CONNECTED(m_rp_TJASystemState_nu), "TJASystemState_nu", font, CHECK_PORT_AVAIL_SYSSTATE(m_rp_TJASystemState_nu, debugString));
        DrawTextLCF(x_coord_c1, start_y_coord + y_offset_inc* step++, offset, colorWhite, CHECK_IS_CONNECTED(m_rp_TJALatCtrlMode_nu), "TJALatCtrlMode_nu", font, CHECK_PORT_AVAIL(m_rp_TJALatCtrlMode_nu, debugString));
        DrawTextLCF(x_coord_c1, start_y_coord + y_offset_inc* step++, offset, colorWhite, CHECK_IS_CONNECTED(m_rp_LaneRecogState_nu), "LaneRecogState_nu", font, CHECK_PORT_AVAIL(m_rp_LaneRecogState_nu, debugString));
        DrawTextLCF(x_coord_c1, start_y_coord + y_offset_inc* step++, offset, colorWhite, CHECK_IS_CONNECTED(m_rp_HapticWrnDeviceLeftReq_nu), "HapticWrnDeviceLeftReq_nu", font, CHECK_PORT_AVAIL(m_rp_HapticWrnDeviceLeftReq_nu, debugString));
        DrawTextLCF(x_coord_c1, start_y_coord + y_offset_inc* step++, offset, colorWhite, CHECK_IS_CONNECTED(m_rp_HapticWrnDeviceRightReq_nu), "HapticWrnDeviceRightReq_nu", font, CHECK_PORT_AVAIL(m_rp_HapticWrnDeviceRightReq_nu, debugString));
        DrawTextLCF(x_coord_c1, start_y_coord + y_offset_inc* step++, offset, colorWhite, CHECK_IS_CONNECTED(m_rp_HapticWrnDeviceCommonReq_nu), "HapticWrnDeviceCommonReq_nu", font, CHECK_PORT_AVAIL(m_rp_HapticWrnDeviceCommonReq_nu, debugString));
        DrawTextLCF(x_coord_c1, start_y_coord + y_offset_inc* step++, offset, colorWhite, CHECK_IS_CONNECTED(m_rp_VisualWrnDeviceLeftReq_nu), "VisualWrnDeviceLeftReq_nu", font, CHECK_PORT_AVAIL(m_rp_VisualWrnDeviceLeftReq_nu, debugString));
        DrawTextLCF(x_coord_c1, start_y_coord + y_offset_inc* step++, offset, colorWhite, CHECK_IS_CONNECTED(m_rp_VisualWrnDeviceRightReq_nu), "VisualWrnDeviceRightReq_nu", font, CHECK_PORT_AVAIL(m_rp_VisualWrnDeviceRightReq_nu, debugString));
        DrawTextLCF(x_coord_c1, start_y_coord + y_offset_inc* step++, offset, colorWhite, CHECK_IS_CONNECTED(m_rp_VisualWrnDeviceCommonReq_nu), "VisualWrnDeviceCommonReq_nu", font, CHECK_PORT_AVAIL(m_rp_VisualWrnDeviceCommonReq_nu, debugString));
        DrawTextLCF(x_coord_c1, start_y_coord + y_offset_inc* step++, offset, colorWhite, CHECK_IS_CONNECTED(m_rp_LaneValidQualDMC_nu), "LaneValidQualDMC_nu", font, CHECK_PORT_AVAIL(m_rp_LaneValidQualDMC_nu, debugString));
        DrawTextLCF(x_coord_c1, start_y_coord + y_offset_inc* step++, offset, colorWhite, CHECK_IS_CONNECTED(m_rp_HandsOffSysWarning_nu), "HandsOffSysWarning_nu", font, CHECK_PORT_AVAIL(m_rp_HandsOffSysWarning_nu, debugString));
        DrawTextLCF(x_coord_c1, start_y_coord + y_offset_inc* step++, offset, colorWhite, CHECK_IS_CONNECTED(m_rp_ErrorStateTJA_nu), "ErrorStateTJA_nu", font, CHECK_PORT_AVAIL(m_rp_ErrorStateTJA_nu, debugString));
	}
	else if (idxSelect == 2  && !m_bDrawHelp && Data_Validity[1]) { /* LCF Sen2Veh Output port */
		DrawTextLCF(x_coord_c1, start_y_coord, offset, colorWhite, CHECK_IS_CONNECTED(m_rp_ControllingFunction_nu), "ControllingFunction_nu", font, CHECK_PORT_AVAIL_MODCTRL(m_rp_ControllingFunction_nu, debugString));
        DrawTextLCF(x_coord_c1, start_y_coord + y_offset_inc* step++, offset, colorWhite, CHECK_IS_CONNECTED(m_rp_ActFctEnabled_nu), "ActFctEnabled_nu", font, CHECK_PORT_AVAIL(m_rp_ActFctEnabled_nu, debugString));
        DrawTextLCF(x_coord_c1, start_y_coord + y_offset_inc* step++, offset, colorWhite, CHECK_IS_CONNECTED(m_rp_ActFctLevel_nu), "ActFctLevel_nu", font, CHECK_PORT_AVAIL(m_rp_ActFctLevel_nu, debugString));
        DrawTextLCF(x_coord_c1, start_y_coord + y_offset_inc* step++, offset, colorWhite, CHECK_IS_CONNECTED(m_rp_SpecialDrivingCorridor_nu), "SpecialDrivingCorridor_nu", font, CHECK_PORT_AVAIL(m_rp_SpecialDrivingCorridor_nu, debugString));
        DrawTextLCF(x_coord_c1, start_y_coord + y_offset_inc* step++, offset, colorWhite, CHECK_IS_CONNECTED(m_rp_MaxJerkAllowed_mps3), "MaxJerkAllowed_mps3", font, CHECK_PORT_AVAIL(m_rp_MaxJerkAllowed_mps3, debugString));
        DrawTextLCF(x_coord_c1, start_y_coord + y_offset_inc* step++, offset, colorWhite, CHECK_IS_CONNECTED(m_rp_OcObjActSide_nu), "OcObjActSide_nu", font, CHECK_PORT_AVAIL(m_rp_OcObjActSide_nu, debugString));
        DrawTextLCF(x_coord_c1, start_y_coord + y_offset_inc* step++, offset, colorWhite, CHECK_IS_CONNECTED(m_rp_AngReqMaxLimitScale_per), "AngReqMaxLimitScale_per", font, CHECK_PORT_AVAIL(m_rp_AngReqMaxLimitScale_per, debugString));
        DrawTextLCF(x_coord_c1, start_y_coord + y_offset_inc* step++, offset, colorWhite, CHECK_IS_CONNECTED(m_rp_AngReqRateMaxLimitScale_per), "AngReqRateMaxLimitScale_per", font, CHECK_PORT_AVAIL(m_rp_AngReqRateMaxLimitScale_per, debugString));
        DrawTextLCF(x_coord_c1, start_y_coord + y_offset_inc* step++, offset, colorWhite, CHECK_IS_CONNECTED(m_rp_SysStateLDP_nu), "SysStateLDP_nu", font, CHECK_PORT_AVAIL_SYSSTATE(m_rp_SysStateLDP_nu, debugString));
        DrawTextLCF(x_coord_c1, start_y_coord + y_offset_inc* step++, offset, colorWhite, CHECK_IS_CONNECTED(m_rp_SysStateRDP_nu), "SysStateRDP_nu", font, CHECK_PORT_AVAIL_SYSSTATE(m_rp_SysStateRDP_nu, debugString));
        DrawTextLCF(x_coord_c1, start_y_coord + y_offset_inc* step++, offset, colorWhite, CHECK_IS_CONNECTED(m_rp_SysStateLDW_nu), "SysStateLDW_nu", font, CHECK_PORT_AVAIL_SYSSTATE(m_rp_SysStateLDW_nu, debugString));
        DrawTextLCF(x_coord_c1, start_y_coord + y_offset_inc* step++, offset, colorWhite, CHECK_IS_CONNECTED(m_rp_SysStateLDPOC_nu), "SysStateLDPOC_nu", font, CHECK_PORT_AVAIL_SYSSTATE(m_rp_SysStateLDPOC_nu, debugString));
        DrawTextLCF(x_coord_c1, start_y_coord + y_offset_inc* step++, offset, colorWhite, CHECK_IS_CONNECTED(m_rp_SysStateALCA_nu), "SysStateALCA_nu", font, CHECK_PORT_AVAIL_SYSSTATE(m_rp_SysStateALCA_nu, debugString));
        DrawTextLCF(x_coord_c1, start_y_coord + y_offset_inc* step++, offset, colorWhite, CHECK_IS_CONNECTED(m_rp_CoordSysStateLCF_nu), "CoordSysStateLCF_nu", font, CHECK_PORT_AVAIL(m_rp_CoordSysStateLCF_nu, debugString));
        DrawTextLCF(x_coord_c1, start_y_coord + y_offset_inc* step++, offset, colorWhite, CHECK_IS_CONNECTED(m_rp_SysStateLKA_nu), "SysStateLKA_nu", font, CHECK_PORT_AVAIL(m_rp_SysStateLKA_nu, debugString));
        DrawTextLCF(x_coord_c1, start_y_coord + y_offset_inc* step++, offset, colorWhite, CHECK_IS_CONNECTED(m_rp_LatCtrlModeLKA_nu), "LatCtrlModeLKA_nu", font, CHECK_PORT_AVAIL(m_rp_LatCtrlModeLKA_nu, debugString));
        DrawTextLCF(x_coord_c1, start_y_coord + y_offset_inc* step++, offset, colorWhite, CHECK_IS_CONNECTED(m_rp_SysStateTJA_nu), "SysStateTJA_nu", font, CHECK_PORT_AVAIL_SYSSTATE(m_rp_SysStateTJA_nu, debugString));
        DrawTextLCF(x_coord_c1, start_y_coord + y_offset_inc* step++, offset, colorWhite, CHECK_IS_CONNECTED(m_rp_LatCtrlModeTJA_nu), "LatCtrlModeTJA_nu", font, CHECK_PORT_AVAIL(m_rp_LatCtrlModeTJA_nu, debugString), 22);
        DrawTextLCF(x_coord_c1, start_y_coord + y_offset_inc* step++, offset, colorWhite, CHECK_IS_CONNECTED(m_rp_LcfCtrlAbort_nu), "LcfCtrlAbort_nu", font, CHECK_PORT_AVAIL(m_rp_LcfCtrlAbort_nu, debugString));
        DrawTextLCF(x_coord_c1, start_y_coord + y_offset_inc* step++, offset, colorWhite, CHECK_IS_CONNECTED(m_rp_LnBndValidLKA_nu), "LnBndValidLKA_nu", font, CHECK_PORT_AVAIL(m_rp_LnBndValidLKA_nu, debugString), 23);
        DrawTextLCF(x_coord_c1, start_y_coord + y_offset_inc* step++, offset, colorWhite, CHECK_IS_CONNECTED(m_rp_LnBndValidLDW_nu), "LnBndValidLDW_nu", font, CHECK_PORT_AVAIL(m_rp_LnBndValidLDW_nu, debugString), 23);
	}
	else if (idxSelect == 3 && !m_bDrawHelp && Data_Validity[2]) { /* LCF Veh Output port */
        DrawTextLCF(x_coord_c1, start_y_coord, offset, colorWhite, CHECK_IS_CONNECTED(m_rp_LaDMC_Status_nu), "LaDMC_Status_nu", font, CHECK_PORT_AVAIL(m_rp_LaDMC_Status_nu, debugString), 35);
        DrawTextLCF(x_coord_c1, start_y_coord + y_offset_inc* step++, offset, colorWhite, CHECK_IS_CONNECTED(m_rp_LaDMC_Eps_Damping_Level_Request__per), "LaDMC_Eps_Damp_Level_Req__per", font, CHECK_PORT_AVAIL(m_rp_LaDMC_Eps_Damping_Level_Request__per, debugString));
        DrawTextLCF(x_coord_c1, start_y_coord + y_offset_inc* step++, offset, colorWhite, CHECK_IS_CONNECTED(m_rp_Lkas_StrToqReq__nm), "Lkas_StrToqReq__nm", font, CHECK_PORT_AVAIL(m_rp_Lkas_StrToqReq__nm, debugString));
        DrawTextLCF(x_coord_c1, start_y_coord + y_offset_inc* step++, offset, colorWhite, CHECK_IS_CONNECTED(m_rp_Lkas_ActToi_nu), "Lkas_ActToi_nu", font, CHECK_PORT_AVAIL(m_rp_Lkas_ActToi_nu, debugString));
        DrawTextLCF(x_coord_c1, start_y_coord + y_offset_inc* step++, offset, colorWhite, CHECK_IS_CONNECTED(m_rp_Lkas_ToiFlt_nu), "Lkas_ToiFlt_nu", font, CHECK_PORT_AVAIL(m_rp_Lkas_ToiFlt_nu, debugString));
        DrawTextLCF(x_coord_c1, start_y_coord + y_offset_inc* step++, offset, colorWhite, CHECK_IS_CONNECTED(m_rp_Lkas_SteeringAngleRate__rps), "Lkas_SteeringAngleRate__rps", font, CHECK_PORT_AVAIL(m_rp_Lkas_SteeringAngleRate__rps, debugString));
        DrawTextLCF(x_coord_c1, start_y_coord + y_offset_inc* step++, offset, colorWhite, CHECK_IS_CONNECTED(m_rp_LaKMC_CrvCmd_Sum__1pm), "LaKMC_CrvCmd_Sum__1pm", font, CHECK_PORT_AVAIL(m_rp_LaKMC_CrvCmd_Sum__1pm, debugString));
        DrawTextLCF(x_coord_c1, start_y_coord + y_offset_inc* step++, offset, colorWhite, CHECK_IS_CONNECTED(m_rp_LaKMC_CrvCmd_FF__1pm), "LaKMC_CrvCmd_FF__1pm", font, CHECK_PORT_AVAIL(m_rp_LaKMC_CrvCmd_FF__1pm, debugString));
        DrawTextLCF(x_coord_c1, start_y_coord + y_offset_inc* step++, offset, colorWhite, CHECK_IS_CONNECTED(m_rp_LaKMC_CrvCmd_Ctrl__1pm), "LaKMC_CrvCmd_Ctrl__1pm", font, CHECK_PORT_AVAIL(m_rp_LaKMC_CrvCmd_Ctrl__1pm, debugString));
        DrawTextLCF(x_coord_c1, start_y_coord + y_offset_inc* step++, offset, colorWhite, CHECK_IS_CONNECTED(m_rp_LaKMC_QuTgtVehCtrl_nu), "LaKMC_QuTgtVehCtrl_nu", font, CHECK_PORT_AVAIL(m_rp_LaKMC_QuTgtVehCtrl_nu, debugString));
        DrawTextLCF(x_coord_c1, start_y_coord + y_offset_inc* step++, offset, colorWhite, CHECK_IS_CONNECTED(m_rp_LaDMC_StrAngReq__deg), "LaDMC_StrAngReq__deg", font, CHECK_PORT_AVAIL(m_rp_LaDMC_StrAngReq__deg, debugString));
        DrawTextLCF(x_coord_c1, start_y_coord + y_offset_inc* step++, offset, colorWhite, CHECK_IS_CONNECTED(m_rp_LaDMC_StrAngEst__deg), "LaDMC_StrAngEst__deg", font, CHECK_PORT_AVAIL(m_rp_LaDMC_StrAngEst__deg, debugString));
        DrawTextLCF(x_coord_c1, start_y_coord + y_offset_inc* step++, offset, colorWhite, CHECK_IS_CONNECTED(m_rp_LaDMC_ActFunc_nu), "LaDMC_ActFunc_nu", font, CHECK_PORT_AVAIL(m_rp_LaDMC_ActFunc_nu, debugString));
        DrawTextLCF(x_coord_c1, start_y_coord + y_offset_inc* step++, offset, colorWhite, CHECK_IS_CONNECTED(m_rp_LaDMC_DeratingFactorReq_nu), "LaDMC_DeratingFactorReq_nu", font, CHECK_PORT_AVAIL(m_rp_LaDMC_DeratingFactorReq_nu, debugString));
        DrawTextLCF(x_coord_c1, start_y_coord + y_offset_inc* step++, offset, colorWhite, CHECK_IS_CONNECTED(m_rp_LaDMC_StiffnessReq_nu), "LaDMC_StiffnessReq_nu", font, CHECK_PORT_AVAIL(m_rp_LaDMC_StiffnessReq_nu, debugString));
        DrawTextLCF(x_coord_c1, start_y_coord + y_offset_inc* step++, offset, colorWhite, CHECK_IS_CONNECTED(m_rp_LaDMC_AccuracyReq_nu), "LaDMC_AccuracyReq_nu", font, CHECK_PORT_AVAIL(m_rp_LaDMC_AccuracyReq_nu, debugString));
        DrawTextLCF(x_coord_c1, start_y_coord + y_offset_inc* step++, offset, colorWhite, CHECK_IS_CONNECTED(m_rp_LaDMC_SteerAngReqQF_nu), "LaDMC_SteerAngReqQF_nu", font, CHECK_PORT_AVAIL(m_rp_LaDMC_SteerAngReqQF_nu, debugString));
        DrawTextLCF(x_coord_c1, start_y_coord + y_offset_inc* step++, offset, colorWhite, CHECK_IS_CONNECTED(m_rp_LaDMC_YawRateReqQF_nu), "LaDMC_YawRateReqQF_nu", font, CHECK_PORT_AVAIL(m_rp_LaDMC_YawRateReqQF_nu, debugString));
        DrawTextLCF(x_coord_c1, start_y_coord + y_offset_inc* step++, offset, colorWhite, CHECK_IS_CONNECTED(m_rp_TMC_DdrData1_nu), "TMC_DdrData1_nu", font, CHECK_PORT_AVAIL(m_rp_TMC_DdrData1_nu, debugString));
        DrawTextLCF(x_coord_c1, start_y_coord + y_offset_inc* step++, offset, colorWhite, CHECK_IS_CONNECTED(m_rp_TMC_DdrData2_nu), "TMC_DdrData2_nu", font, CHECK_PORT_AVAIL(m_rp_TMC_DdrData2_nu, debugString));
        DrawTextLCF(x_coord_c1, start_y_coord + y_offset_inc* step++, offset, colorWhite, CHECK_IS_CONNECTED(m_rp_TMC_DdrData3_nu), "TMC_DdrData3_nu", font, CHECK_PORT_AVAIL(m_rp_TMC_DdrData3_nu, debugString));
	}
	else if (idxSelect == 4 && !m_bDrawHelp && Data_Validity[3]) { /* LCF Veh2Sen Output port */
        DrawTextLCF(x_coord_c1, start_y_coord, offset, colorWhite, CHECK_IS_CONNECTED(m_rp_DrvAttention_perc), "DrvAttention_perc", font, CHECK_PORT_AVAIL(m_rp_DrvAttention_perc, debugString));
        DrawTextLCF(x_coord_c1, start_y_coord + y_offset_inc* step++, offset, colorWhite, CHECK_IS_CONNECTED(m_rp_DrvAttentionConf_perc), "DrvAttentionConf_perc", font, CHECK_PORT_AVAIL(m_rp_DrvAttentionConf_perc, debugString));
        DrawTextLCF(x_coord_c1, start_y_coord + y_offset_inc* step++, offset, colorWhite, CHECK_IS_CONNECTED(m_rp_DrvMonSysWarning_nu), "DrvMonSysWarning_nu", font, CHECK_PORT_AVAIL(m_rp_DrvMonSysWarning_nu, debugString));
        DrawTextLCF(x_coord_c1, start_y_coord + y_offset_inc* step++, offset, colorWhite, CHECK_IS_CONNECTED(m_rp_HandsOffConfirmed_nu), "HandsOffConfirmed_nu", font, CHECK_PORT_AVAIL(m_rp_HandsOffConfirmed_nu, debugString));
        DrawTextLCF(x_coord_c1, start_y_coord + y_offset_inc* step++, offset, colorWhite, CHECK_IS_CONNECTED(m_rp_AbuseWarning_nu), "AbuseWarning_nu", font, CHECK_PORT_AVAIL(m_rp_AbuseWarning_nu, debugString));
        DrawTextLCF(x_coord_c1, start_y_coord + y_offset_inc* step++, offset, colorWhite, CHECK_IS_CONNECTED(m_rp_EstHandTor_nm), "EstHandTor_nm", font, CHECK_PORT_AVAIL(m_rp_EstHandTor_nm, debugString));
        DrawTextLCF(x_coord_c1, start_y_coord + y_offset_inc* step++, offset, colorWhite, CHECK_IS_CONNECTED(m_rp_SAC_Eps_Request_Flag_nu), "SAC_Eps_Request_Flag_nu", font, CHECK_PORT_AVAIL(m_rp_SAC_Eps_Request_Flag_nu, debugString));
        DrawTextLCF(x_coord_c1, start_y_coord + y_offset_inc* step++, offset, colorWhite, CHECK_IS_CONNECTED(m_rp_Veh2Sen_Reserved1_nu), "Reserved1_nu", font, CHECK_PORT_AVAIL(m_rp_Veh2Sen_Reserved1_nu, debugString));
        DrawTextLCF(x_coord_c1, start_y_coord + y_offset_inc* step++, offset, colorWhite, CHECK_IS_CONNECTED(m_rp_Veh2Sen_Reserved2_nu), "Reserved2_nu", font, CHECK_PORT_AVAIL(m_rp_Veh2Sen_Reserved2_nu, debugString));
        DrawTextLCF(x_coord_c1, start_y_coord + y_offset_inc* step++, offset, colorWhite, CHECK_IS_CONNECTED(m_rp_TrigCustFctReplanCurValues_nu), "TrigCustFctReplanCurValues_nu", font, CHECK_PORT_AVAIL(m_rp_TrigCustFctReplanCurValues_nu, debugString));
        DrawTextLCF(x_coord_c1, start_y_coord + y_offset_inc* step++, offset, colorWhite, CHECK_IS_CONNECTED(m_rp_TrajGuiQualifier_nu), "TrajGuiQualifier_nu", font, CHECK_PORT_AVAIL(m_rp_TrajGuiQualifier_nu, debugString));
        DrawTextLCF(x_coord_c1, start_y_coord + y_offset_inc* step++, offset, colorWhite, CHECK_IS_CONNECTED(m_rp_CurDistY_m), "Traj_Error.CurDistY_m", font, CHECK_PORT_AVAIL(m_rp_CurDistY_m, debugString));
        DrawTextLCF(x_coord_c1, start_y_coord + y_offset_inc* step++, offset, colorWhite, CHECK_IS_CONNECTED(m_rp_CurHeading__rad), "Traj_Error.CurHeading__rad", font, CHECK_PORT_AVAIL(m_rp_CurHeading__rad, debugString));
        DrawTextLCF(x_coord_c1, start_y_coord + y_offset_inc* step++, offset, colorWhite, CHECK_IS_CONNECTED(m_rp_LtcyComp_DevHeading__rad), "Traj_Error.LtcyComp_DevHeading__rad", font, CHECK_PORT_AVAIL(m_rp_LtcyComp_DevHeading__rad, debugString));
        DrawTextLCF(x_coord_c1, start_y_coord + y_offset_inc* step++, offset, colorWhite, CHECK_IS_CONNECTED(m_rp_TrajDistY_m), "Desired_Traj.TrajDistY_m", font, CHECK_PORT_AVAIL(m_rp_TrajDistY_m, debugString));
        DrawTextLCF(x_coord_c1, start_y_coord + y_offset_inc* step++, offset, colorWhite, CHECK_IS_CONNECTED(m_rp_TrajHeading__rad), "Desired_Traj.TrajHeading__rad", font, CHECK_PORT_AVAIL(m_rp_TrajHeading__rad, debugString));
        DrawTextLCF(x_coord_c1, start_y_coord + y_offset_inc* step++, offset, colorWhite, CHECK_IS_CONNECTED(m_rp_TrajHeadingInclPreview__rad), "Desired_Traj.TrajHeadInclPrev__rad", font, CHECK_PORT_AVAIL(m_rp_TrajHeadingInclPreview__rad, debugString));
        DrawTextLCF(x_coord_c1, start_y_coord + y_offset_inc* step++, offset, colorWhite, CHECK_IS_CONNECTED(m_rp_TgtTrajCrv__1pm), "TrjPlnCrv.TgtTrajCrv__1pm", font, CHECK_PORT_AVAIL(m_rp_TgtTrajCrv__1pm, debugString));
        DrawTextLCF(x_coord_c1, start_y_coord + y_offset_inc* step++, offset, colorWhite, CHECK_IS_CONNECTED(m_rp_TgtTrajCrvGrd__1pms), "TrjPlnCrv.TgtTrajCrvGrd__1pms", font, CHECK_PORT_AVAIL(m_rp_TgtTrajCrvGrd__1pms, debugString));
        DrawTextLCF(x_coord_c1, start_y_coord + y_offset_inc* step++, offset, colorWhite, CHECK_IS_CONNECTED(m_rp_LtcyComp_RightCorridorCrv__1pm), "TrjPlnCrv.LtcyComp_RightCorrCrv_1pm", font, CHECK_PORT_AVAIL(m_rp_LtcyComp_RightCorridorCrv__1pm, debugString));
        DrawTextLCF(x_coord_c1, start_y_coord + y_offset_inc* step++, offset, colorWhite, CHECK_IS_CONNECTED(m_rp_CtrlErrDistY_m), "Error.CtrlErrDistY_m", font, CHECK_PORT_AVAIL(m_rp_CtrlErrDistY_m, debugString));
	}
	else if (idxSelect == 5 && !m_bDrawHelp && Data_Validity[4]) {
        DrawTextLCF(x_coord_c1, start_y_coord, offset, colorWhite, CHECK_IS_CONNECTED(m_rp_CompSen_uiVersionNumber), "LCF_SEN.uiVersionNumber", font, CHECK_PORT_AVAIL(m_rp_CompSen_uiVersionNumber, debugString));
        DrawTextLCF(x_coord_c1, start_y_coord + y_offset_inc* step++, offset, colorWhite, CHECK_IS_CONNECTED(m_rp_CompSen_uiTimeStamp), "LCF_SEN.uiTimeStamp", font, CHECK_PORT_AVAIL(m_rp_CompSen_uiTimeStamp, debugString));
        DrawTextLCF(x_coord_c1, start_y_coord + y_offset_inc* step++, offset, colorWhite, CHECK_IS_CONNECTED(m_rp_CompSen_uiMeasurementCounter), "LCF_SEN.uiMeasurementCounter", font, CHECK_PORT_AVAIL(m_rp_CompSen_uiMeasurementCounter, debugString));
        DrawTextLCF(x_coord_c1, start_y_coord + y_offset_inc* step++, offset, colorWhite, CHECK_IS_CONNECTED(m_rp_CompSen_uiCycleCounter), "LCF_SEN.uiCycleCounter", font, CHECK_PORT_AVAIL(m_rp_CompSen_uiCycleCounter, debugString));
        DrawTextLCF(x_coord_c1, start_y_coord + y_offset_inc* step++, offset, colorWhite, CHECK_IS_CONNECTED(m_rp_CompSen_eSigStatus), "LCF_SEN.eSigStatus", font, CHECK_PORT_AVAIL(m_rp_CompSen_eSigStatus, debugString), 36);
        DrawTextLCF(x_coord_c1, start_y_coord + y_offset_inc* step++, offset, colorWhite, CHECK_IS_CONNECTED(m_rp_Sen_uiAlgoVersionNumber), "LCF_SEN.uiAlgoVersionNumber", font, (m_rp_Sen_uiAlgoVersionNumber.isConnected()) ? (LcofValueToString(m_rp_Sen_uiAlgoVersionNumber.val(), debugString, 40)) : ("Not connected"));
        DrawTextLCF(x_coord_c1, start_y_coord + y_offset_inc* step++, offset, colorWhite, CHECK_IS_CONNECTED(m_rp_Sen_uiApplicationNumber), "LCF_SEN.uiApplicationNumber", font, CHECK_PORT_AVAIL(m_rp_Sen_uiApplicationNumber, debugString), 20);
        DrawTextLCF(x_coord_c1, start_y_coord + y_offset_inc* step++, offset, colorWhite, CHECK_IS_CONNECTED(m_rp_Sen_eCompState), "LCF_SEN.eCompState", font, CHECK_PORT_AVAIL(m_rp_Sen_eCompState, debugString), 21);
        DrawTextLCF(x_coord_c1, start_y_coord + y_offset_inc* step++, offset, colorWhite, CHECK_IS_CONNECTED(m_rp_Sen_eShedulerSubModeRequest), "LCF_SEN.eShedulerSubModeRequest", font, CHECK_PORT_AVAIL(m_rp_Sen_eShedulerSubModeRequest, debugString));
        DrawTextLCF(x_coord_c1, start_y_coord + y_offset_inc* step++, offset, colorWhite, CHECK_IS_CONNECTED(m_rp_Sen_eErrorCode), "LCF_SEN.eErrorCode", font, CHECK_PORT_AVAIL(m_rp_Sen_eErrorCode, debugString));
        DrawTextLCF(x_coord_c1, start_y_coord + y_offset_inc* step++, offset, colorWhite, CHECK_IS_CONNECTED(m_rp_Sen_eGenAlgoQualifier), "LCF_SEN.eGenAlgoQualifier", font, CHECK_PORT_AVAIL(m_rp_Sen_eGenAlgoQualifier, debugString));
        DrawTextLCF(x_coord_c1, start_y_coord + y_offset_inc* step++, offset, colorWhite, CHECK_IS_CONNECTED(m_rp_CompVeh_uiVersionNumber), "LCF_VEH.uiVersionNumber", font, CHECK_PORT_AVAIL(m_rp_CompVeh_uiVersionNumber, debugString));
        DrawTextLCF(x_coord_c1, start_y_coord + y_offset_inc* step++, offset, colorWhite, CHECK_IS_CONNECTED(m_rp_CompVeh_uiTimeStamp), "LCF_VEH.uiTimeStamp", font, CHECK_PORT_AVAIL(m_rp_CompVeh_uiTimeStamp, debugString));
        DrawTextLCF(x_coord_c1, start_y_coord + y_offset_inc* step++, offset, colorWhite, CHECK_IS_CONNECTED(m_rp_CompVeh_uiMeasurementCounter), "LCF_VEH.uiMeasurementCounter", font, CHECK_PORT_AVAIL(m_rp_CompVeh_uiMeasurementCounter, debugString));
        DrawTextLCF(x_coord_c1, start_y_coord + y_offset_inc* step++, offset, colorWhite, CHECK_IS_CONNECTED(m_rp_CompVeh_uiCycleCounter), "LCF_VEH.uiCycleCounter", font, CHECK_PORT_AVAIL(m_rp_CompVeh_uiCycleCounter, debugString));
        DrawTextLCF(x_coord_c1, start_y_coord + y_offset_inc* step++, offset, colorWhite, CHECK_IS_CONNECTED(m_rp_CompVeh_eSigStatus), "LCF_VEH.eSigStatus", font, CHECK_PORT_AVAIL(m_rp_CompVeh_eSigStatus, debugString), 36);
        DrawTextLCF(x_coord_c1, start_y_coord + y_offset_inc* step++, offset, colorWhite, CHECK_IS_CONNECTED(m_rp_Veh_uiAlgoVersionNumber), "LCF_VEH.uiAlgoVersionNumber", font, (m_rp_Veh_uiAlgoVersionNumber.isConnected()) ? (LcofValueToString(m_rp_Veh_uiAlgoVersionNumber.val(), debugString, 40)) : ("Not connected"));
        DrawTextLCF(x_coord_c1, start_y_coord + y_offset_inc* step++, offset, colorWhite, CHECK_IS_CONNECTED(m_rp_Veh_uiApplicationNumber), "LCF_VEH.uiApplicationNumber", font, CHECK_PORT_AVAIL(m_rp_Veh_uiApplicationNumber, debugString), 20);
        DrawTextLCF(x_coord_c1, start_y_coord + y_offset_inc* step++, offset, colorWhite, CHECK_IS_CONNECTED(m_rp_Veh_eCompState), "LCF_VEH.eCompState", font, CHECK_PORT_AVAIL(m_rp_Veh_eCompState, debugString), 21);
        DrawTextLCF(x_coord_c1, start_y_coord + y_offset_inc* step++, offset, colorWhite, CHECK_IS_CONNECTED(m_rp_Veh_eShedulerSubModeRequest), "LCF_VEH.eShedulerSubModeRequest", font, CHECK_PORT_AVAIL(m_rp_Veh_eShedulerSubModeRequest, debugString));
        DrawTextLCF(x_coord_c1, start_y_coord + y_offset_inc* step++, offset, colorWhite, CHECK_IS_CONNECTED(m_rp_Veh_eErrorCode), "LCF_VEH.eErrorCode", font, CHECK_PORT_AVAIL(m_rp_Veh_eErrorCode, debugString));
	}

	x_coord_c1 += 445;
	offset = 283;
	start_y_coord = 45;
	step = 0;

	if ((idxSelect == 0 || idxSelect == 1) && Data_Validity[0]) { /* LCF Sen Output port */
        DrawTextLCF(x_coord_c1, start_y_coord + y_offset_inc* step++, offset, colorWhite, CHECK_IS_CONNECTED(m_rp_CustSpecSysStateTJA_nu), "CustSpecSysStateTJA_nu", font, CHECK_PORT_AVAIL(m_rp_CustSpecSysStateTJA_nu, debugString));
        DrawTextLCF(x_coord_c1, start_y_coord + y_offset_inc* step++, offset, colorWhite, CHECK_IS_CONNECTED(m_rp_ErrorStateLDP_nu), "ErrorStateLDP_nu", font, CHECK_PORT_AVAIL(m_rp_ErrorStateLDP_nu, debugString));
        DrawTextLCF(x_coord_c1, start_y_coord + y_offset_inc* step++, offset, colorWhite, CHECK_IS_CONNECTED(m_rp_CustSpecSysStateLDP_nu), "CustSpecSysStateLDP_nu", font, CHECK_PORT_AVAIL(m_rp_CustSpecSysStateLDP_nu, debugString));
        DrawTextLCF(x_coord_c1, start_y_coord + y_offset_inc* step++, offset, colorWhite, CHECK_IS_CONNECTED(m_rp_ErrorStateLDW_nu), "ErrorStateLDW_nu", font, CHECK_PORT_AVAIL(m_rp_ErrorStateLDW_nu, debugString));
        DrawTextLCF(x_coord_c1, start_y_coord + y_offset_inc* step++, offset, colorWhite, CHECK_IS_CONNECTED(m_rp_CustSpecSysStateLDW_nu), "CustSpecSysStateLDW_nu", font, CHECK_PORT_AVAIL(m_rp_CustSpecSysStateLDW_nu, debugString));
        DrawTextLCF(x_coord_c1, start_y_coord + y_offset_inc* step++, offset, colorWhite, CHECK_IS_CONNECTED(m_rp_ErrorStateRDP_nu), "ErrorStateRDP_nu", font, CHECK_PORT_AVAIL(m_rp_ErrorStateRDP_nu, debugString));
        DrawTextLCF(x_coord_c1, start_y_coord + y_offset_inc* step++, offset, colorWhite, CHECK_IS_CONNECTED(m_rp_CustSpecSysStateRDP_nu), "CustSpecSysStateRDP_nu", font, CHECK_PORT_AVAIL(m_rp_CustSpecSysStateRDP_nu, debugString));
        DrawTextLCF(x_coord_c1, start_y_coord + y_offset_inc* step++, offset, colorWhite, CHECK_IS_CONNECTED(m_rp_LCF_Stiffness_nu), "LCF_Stiffness_nu", font, CHECK_PORT_AVAIL(m_rp_LCF_Stiffness_nu, debugString));
        DrawTextLCF(x_coord_c1, start_y_coord + y_offset_inc* step++, offset, colorWhite, CHECK_IS_CONNECTED(m_rp_LCF_Accuracy_nu), "LCF_Accuracy_nu", font, CHECK_PORT_AVAIL(m_rp_LCF_Accuracy_nu, debugString));
        DrawTextLCF(x_coord_c1, start_y_coord + y_offset_inc* step++, offset, colorWhite, CHECK_IS_CONNECTED(m_rp_TJA_Status_nu), "TJA_Status_nu", font, CHECK_PORT_AVAIL(m_rp_TJA_Status_nu, debugString));
        DrawTextLCF(x_coord_c1, start_y_coord + y_offset_inc* step++, offset, colorWhite, CHECK_IS_CONNECTED(m_rp_DFFunctActiveState_btf), "HMI.DFFunctActiveState_btf", font, CHECK_PORT_AVAIL(m_rp_DFFunctActiveState_btf, debugString));
        DrawTextLCF(x_coord_c1, start_y_coord + y_offset_inc* step++, offset, colorWhite, CHECK_IS_CONNECTED(m_rp_LnBndLeValid4Fct_btf), "HMI.LnBndLeValid4Fct_btf", font, CHECK_PORT_AVAIL(m_rp_LnBndLeValid4Fct_btf, debugString));
        DrawTextLCF(x_coord_c1, start_y_coord + y_offset_inc* step++, offset, colorWhite, CHECK_IS_CONNECTED(m_rp_LnBndRiValid4Fct_btf), "HMI.LnBndRiValid4Fct_btf", font, CHECK_PORT_AVAIL(m_rp_LnBndRiValid4Fct_btf, debugString));
        DrawTextLCF(x_coord_c1, start_y_coord + y_offset_inc* step++, offset, colorWhite, CHECK_IS_CONNECTED(m_rp_DispLaneLeftDetected_nu), "HMI.DispLaneLeftDetected_nu", font, CHECK_PORT_AVAIL(m_rp_DispLaneLeftDetected_nu, debugString));
        DrawTextLCF(x_coord_c1, start_y_coord + y_offset_inc* step++, offset, colorWhite, CHECK_IS_CONNECTED(m_rp_DispLaneRightDetected_nu), "HMI.DispLaneRightDetected_nu", font, CHECK_PORT_AVAIL(m_rp_DispLaneRightDetected_nu, debugString));
        DrawTextLCF(x_coord_c1, start_y_coord + y_offset_inc* step++, offset, colorWhite, CHECK_IS_CONNECTED(m_rp_SteeringWheelVibrationReq_nu), "HMI.SteeringWheelVibrationReq_nu", font, CHECK_PORT_AVAIL(m_rp_SteeringWheelVibrationReq_nu, debugString));
        DrawTextLCF(x_coord_c1, start_y_coord + y_offset_inc* step++, offset, colorWhite, CHECK_IS_CONNECTED(m_rp_DrvAttWarnQualifier_nu), "HMI.DrvAttWarnQualifier_nu", font, CHECK_PORT_AVAIL(m_rp_DrvAttWarnQualifier_nu, debugString));
        DrawTextLCF(x_coord_c1, start_y_coord + y_offset_inc* step++, offset, colorWhite, CHECK_IS_CONNECTED(m_rp_TMC_Indi_nu), "TMC_Indi_nu", font, CHECK_PORT_AVAIL(m_rp_TMC_Indi_nu, debugString));
        DrawTextLCF(x_coord_c1, start_y_coord + y_offset_inc* step++, offset, colorWhite, CHECK_IS_CONNECTED(m_rp_TMC_LaneDispLeft_nu), "TMC_LaneDispLeft_nu", font, CHECK_PORT_AVAIL(m_rp_TMC_LaneDispLeft_nu, debugString));
        DrawTextLCF(x_coord_c1, start_y_coord + y_offset_inc* step++, offset, colorWhite, CHECK_IS_CONNECTED(m_rp_TMC_LaneDispRight_nu), "TMC_LaneDispRight_nu", font, CHECK_PORT_AVAIL(m_rp_TMC_LaneDispRight_nu, debugString));
        DrawTextLCF(x_coord_c1, start_y_coord + y_offset_inc* step++, offset, colorWhite, CHECK_IS_CONNECTED(m_rp_TMC_StrgCtrlAct_nu), "TMC_StrgCtrlAct_nu", font, CHECK_PORT_AVAIL(m_rp_TMC_StrgCtrlAct_nu, debugString));
        DrawTextLCF(x_coord_c1, start_y_coord + y_offset_inc* step++, offset, colorWhite, CHECK_IS_CONNECTED(m_rp_SenOut_uiVersionNumber), "uiVersionNumber", font, CHECK_PORT_AVAIL(m_rp_SenOut_uiVersionNumber, debugString));
        DrawTextLCF(x_coord_c1, start_y_coord + y_offset_inc* step++, offset, colorWhite, CHECK_IS_CONNECTED(m_rp_SenOut_uiTimeStamp), "uiTimeStamp", font, CHECK_PORT_AVAIL(m_rp_SenOut_uiTimeStamp, debugString));
        DrawTextLCF(x_coord_c1, start_y_coord + y_offset_inc* step++, offset, colorWhite, CHECK_IS_CONNECTED(m_rp_SenOut_uiMeasurementCounter), "uiMeasurementCounter", font, CHECK_PORT_AVAIL(m_rp_SenOut_uiMeasurementCounter, debugString));
        DrawTextLCF(x_coord_c1, start_y_coord + y_offset_inc* step++, offset, colorWhite, CHECK_IS_CONNECTED(m_rp_SenOut_uiCycleCounter), "uiCycleCounter", font, CHECK_PORT_AVAIL(m_rp_SenOut_uiCycleCounter, debugString));
        DrawTextLCF(x_coord_c1, start_y_coord + y_offset_inc* step++, offset, colorWhite, CHECK_IS_CONNECTED(m_rp_SenOut_eSigStatus), "eSigStatus", font, CHECK_PORT_AVAIL(m_rp_SenOut_eSigStatus, debugString), 36);
	}
	else if (idxSelect == 2 && Data_Validity[1]) { /* LCF Sen2Veh Output port */
        DrawTextLCF(x_coord_c1, start_y_coord + y_offset_inc* step++, offset, colorWhite, CHECK_IS_CONNECTED(m_rp_LnBndValidLDP_nu), "LnBndValidLDP_nu", font, CHECK_PORT_AVAIL(m_rp_LnBndValidLDP_nu, debugString), 23);
        DrawTextLCF(x_coord_c1, start_y_coord + y_offset_inc* step++, offset, colorWhite, CHECK_IS_CONNECTED(m_rp_LnBndValidRDP_nu), "LnBndValidRDP_nu", font, CHECK_PORT_AVAIL(m_rp_LnBndValidRDP_nu, debugString), 23);
        DrawTextLCF(x_coord_c1, start_y_coord + y_offset_inc* step++, offset, colorWhite, CHECK_IS_CONNECTED(m_rp_LnBndValidLDPOC_nu), "LnBndValidLDPOC_nu", font, CHECK_PORT_AVAIL(m_rp_LnBndValidLDPOC_nu, debugString));
        DrawTextLCF(x_coord_c1, start_y_coord + y_offset_inc* step++, offset, colorWhite, CHECK_IS_CONNECTED(m_rp_LnBndValidTJA_nu), "LnBndValidTJA_nu", font, CHECK_PORT_AVAIL(m_rp_LnBndValidTJA_nu, debugString), 23);
        DrawTextLCF(x_coord_c1, start_y_coord + y_offset_inc* step++, offset, colorWhite, CHECK_IS_CONNECTED(m_rp_LnBndValidALCA_nu), "LnBndValidALCA_nu", font, CHECK_PORT_AVAIL(m_rp_LnBndValidALCA_nu, debugString), 23);
        DrawTextLCF(x_coord_c1, start_y_coord + y_offset_inc* step++, offset, colorWhite, CHECK_IS_CONNECTED(m_rp_LcfFctAvailability_nu), "LcfFctAvailability_nu", font, CHECK_PORT_AVAIL(m_rp_LcfFctAvailability_nu, debugString));
        DrawTextLCF(x_coord_c1, start_y_coord + y_offset_inc* step++, offset, colorWhite, CHECK_IS_CONNECTED(m_rp_ABP_CamCorridorCurvature__1pm), "ABP_CamCorridorCurvature__1pm", font, CHECK_PORT_AVAIL(m_rp_ABP_CamCorridorCurvature__1pm, debugString));
        DrawTextLCF(x_coord_c1, start_y_coord + y_offset_inc* step++, offset, colorWhite, CHECK_IS_CONNECTED(m_rp_ABP_CamLateralError_m), "ABP_CamLateralError_m", font, CHECK_PORT_AVAIL(m_rp_ABP_CamLateralError_m, debugString));
        DrawTextLCF(x_coord_c1, start_y_coord + y_offset_inc* step++, offset, colorWhite, CHECK_IS_CONNECTED(m_rp_ABP_CamHeadingError__rad), "ABP_CamHeadingError__rad", font, CHECK_PORT_AVAIL(m_rp_ABP_CamHeadingError__rad, debugString));
        DrawTextLCF(x_coord_c1, start_y_coord + y_offset_inc* step++, offset, colorWhite, CHECK_IS_CONNECTED(m_rp_Sen2Veh_Reserved1_nu), "Reserved1_nu", font, CHECK_PORT_AVAIL(m_rp_Sen2Veh_Reserved1_nu, debugString));
        DrawTextLCF(x_coord_c1, start_y_coord + y_offset_inc* step++, offset, colorWhite, CHECK_IS_CONNECTED(m_rp_Sen2Veh_Reserved2_nu), "Reserved2_nu", font, CHECK_PORT_AVAIL(m_rp_Sen2Veh_Reserved2_nu, debugString));
        DrawTextLCF(x_coord_c1, start_y_coord + y_offset_inc* step++, offset, colorWhite, CHECK_IS_CONNECTED(m_rp_Sen2Veh_EventId_nu_0_), "EvntDtctnVehEvents[0].EventId_nu", font, CHECK_PORT_AVAIL(m_rp_Sen2Veh_EventId_nu_0_, debugString));
        DrawTextLCF(x_coord_c1, start_y_coord + y_offset_inc* step++, offset, colorWhite, CHECK_IS_CONNECTED(m_rp_Sen2Veh_EventLifetime_nu_0_), "EvntDtctnVehEvents[0].EventLifetime_nu", font, CHECK_PORT_AVAIL(m_rp_Sen2Veh_EventLifetime_nu_0_, debugString));
        DrawTextLCF(x_coord_c1, start_y_coord + y_offset_inc* step++, offset, colorWhite, CHECK_IS_CONNECTED(m_rp_Sen2Veh_EventId_nu_1_), "EvntDtctnVehEvents[1].EventId_nu", font, CHECK_PORT_AVAIL(m_rp_Sen2Veh_EventId_nu_1_, debugString));
        DrawTextLCF(x_coord_c1, start_y_coord + y_offset_inc* step++, offset, colorWhite, CHECK_IS_CONNECTED(m_rp_Sen2Veh_EventLifetime_nu_1_), "EvntDtctnVehEvents[1].EventLifetime_nu", font, CHECK_PORT_AVAIL(m_rp_Sen2Veh_EventLifetime_nu_1_, debugString));
        DrawTextLCF(x_coord_c1, start_y_coord + y_offset_inc* step++, offset, colorWhite, CHECK_IS_CONNECTED(m_rp_Sen2Veh_EventId_nu_2_), "EvntDtctnVehEvents[2].EventId_nu", font, CHECK_PORT_AVAIL(m_rp_Sen2Veh_EventId_nu_2_, debugString));
        DrawTextLCF(x_coord_c1, start_y_coord + y_offset_inc* step++, offset, colorWhite, CHECK_IS_CONNECTED(m_rp_Sen2Veh_EventLifetime_nu_2_), "EvntDtctnVehEvents[2].EventLifetime_nu", font, CHECK_PORT_AVAIL(m_rp_Sen2Veh_EventLifetime_nu_2_, debugString));
        DrawTextLCF(x_coord_c1, start_y_coord + y_offset_inc* step++, offset, colorWhite, CHECK_IS_CONNECTED(m_rp_Sen2Veh_EventId_nu_3_), "EvntDtctnVehEvents[3].EventId_nu", font, CHECK_PORT_AVAIL(m_rp_Sen2Veh_EventId_nu_3_, debugString));
        DrawTextLCF(x_coord_c1, start_y_coord + y_offset_inc* step++, offset, colorWhite, CHECK_IS_CONNECTED(m_rp_Sen2Veh_EventLifetime_nu_3_), "EvntDtctnVehEvents[3].EventLifetime_nu", font, CHECK_PORT_AVAIL(m_rp_Sen2Veh_EventLifetime_nu_3_, debugString));
        DrawTextLCF(x_coord_c1, start_y_coord + y_offset_inc* step++, offset, colorWhite, CHECK_IS_CONNECTED(m_rp_Sen2Veh_EventId_nu_4_), "EvntDtctnVehEvents[4].EventId_nu", font, CHECK_PORT_AVAIL(m_rp_Sen2Veh_EventId_nu_4_, debugString));
        DrawTextLCF(x_coord_c1, start_y_coord + y_offset_inc* step++, offset, colorWhite, CHECK_IS_CONNECTED(m_rp_Sen2Veh_EventLifetime_nu_4_), "EvntDtctnVehEvents[4].EventLifetime_nu", font, CHECK_PORT_AVAIL(m_rp_Sen2Veh_EventLifetime_nu_4_, debugString));
        DrawTextLCF(x_coord_c1, start_y_coord + y_offset_inc* step++, offset, colorWhite, CHECK_IS_CONNECTED(m_rp_Sen2Veh_uiVersionNumber), "uiVersionNumber", font, CHECK_PORT_AVAIL(m_rp_Sen2Veh_uiVersionNumber, debugString));
        DrawTextLCF(x_coord_c1, start_y_coord + y_offset_inc* step++, offset, colorWhite, CHECK_IS_CONNECTED(m_rp_Sen2Veh_uiTimeStamp), "uiTimeStamp", font, CHECK_PORT_AVAIL(m_rp_Sen2Veh_uiTimeStamp, debugString));
        DrawTextLCF(x_coord_c1, start_y_coord + y_offset_inc* step++, offset, colorWhite, CHECK_IS_CONNECTED(m_rp_Sen2Veh_uiMeasurementCounter), "uiMeasurementCounter", font, CHECK_PORT_AVAIL(m_rp_Sen2Veh_uiMeasurementCounter, debugString));
        DrawTextLCF(x_coord_c1, start_y_coord + y_offset_inc* step++, offset, colorWhite, CHECK_IS_CONNECTED(m_rp_Sen2Veh_uiCycleCounter), "uiCycleCounter", font, CHECK_PORT_AVAIL(m_rp_Sen2Veh_uiCycleCounter, debugString));
        DrawTextLCF(x_coord_c1, start_y_coord + y_offset_inc* step++, offset, colorWhite, CHECK_IS_CONNECTED(m_rp_Sen2Veh_eSigStatus), "eSigStatus", font, CHECK_PORT_AVAIL(m_rp_Sen2Veh_eSigStatus, debugString), 36);
	}
	else if (idxSelect == 3 && Data_Validity[2]) { /* LCF Veh Output port */
        DrawTextLCF(x_coord_c1, start_y_coord + y_offset_inc* step++, offset, colorWhite, CHECK_IS_CONNECTED(m_rp_TSEAESSysState_nu), "TSEAESSysState_nu", font, CHECK_PORT_AVAIL_SYSSTATE(m_rp_TSEAESSysState_nu, debugString));
        DrawTextLCF(x_coord_c1, start_y_coord + y_offset_inc* step++, offset, colorWhite, CHECK_IS_CONNECTED(m_rp_VehOut_uiVersionNumber), "uiVersionNumber", font, CHECK_PORT_AVAIL(m_rp_VehOut_uiVersionNumber, debugString));
        DrawTextLCF(x_coord_c1, start_y_coord + y_offset_inc* step++, offset, colorWhite, CHECK_IS_CONNECTED(m_rp_VehOut_uiTimeStamp), "uiTimeStamp", font, CHECK_PORT_AVAIL(m_rp_VehOut_uiTimeStamp, debugString));
        DrawTextLCF(x_coord_c1, start_y_coord + y_offset_inc* step++, offset, colorWhite, CHECK_IS_CONNECTED(m_rp_VehOut_uiMeasurementCounter), "uiMeasurementCounter", font, CHECK_PORT_AVAIL(m_rp_VehOut_uiMeasurementCounter, debugString));
        DrawTextLCF(x_coord_c1, start_y_coord + y_offset_inc* step++, offset, colorWhite, CHECK_IS_CONNECTED(m_rp_VehOut_uiCycleCounter), "uiCycleCounter", font, CHECK_PORT_AVAIL(m_rp_VehOut_uiCycleCounter, debugString));
        DrawTextLCF(x_coord_c1, start_y_coord + y_offset_inc* step++, offset, colorWhite, CHECK_IS_CONNECTED(m_rp_VehOut_eSigStatus), "eSigStatus", font, CHECK_PORT_AVAIL(m_rp_VehOut_eSigStatus, debugString), 36);
	}
	else if (idxSelect == 4 && Data_Validity[3]) { /* LCF Veh2Sen Output port */
        DrawTextLCF(x_coord_c1, start_y_coord + y_offset_inc* step++, offset, colorWhite, CHECK_IS_CONNECTED(m_rp_CtrlErrHeadingAngle__rad), "Error.CtrlErrHeadingAngle__rad", font, CHECK_PORT_AVAIL(m_rp_CtrlErrHeadingAngle__rad, debugString));
        DrawTextLCF(x_coord_c1, start_y_coord + y_offset_inc* step++, offset, colorWhite, CHECK_IS_CONNECTED(m_rp_TgtCrv_NoDE__1pm), "Crv.TgtCrv_NoDE__1pm", font, CHECK_PORT_AVAIL(m_rp_TgtCrv_NoDE__1pm, debugString));
        DrawTextLCF(x_coord_c1, start_y_coord + y_offset_inc* step++, offset, colorWhite, CHECK_IS_CONNECTED(m_rp_TgtCrv_DEWithNoLatSlp__1pm), "Crv.TgtCrv_DEWithNoLatSlp__1pm", font, CHECK_PORT_AVAIL(m_rp_TgtCrv_DEWithNoLatSlp__1pm, debugString));
        DrawTextLCF(x_coord_c1, start_y_coord + y_offset_inc* step++, offset, colorWhite, CHECK_IS_CONNECTED(m_rp_TgtCrv_DE__1pm), "Crv.TgtCrv_DE__1pm", font, CHECK_PORT_AVAIL(m_rp_TgtCrv_DE__1pm, debugString));
        DrawTextLCF(x_coord_c1, start_y_coord + y_offset_inc* step++, offset, colorWhite, CHECK_IS_CONNECTED(m_rp_TgtCrv_Limited__1pm), "Crv.TgtCrv_Limited__1pm", font, CHECK_PORT_AVAIL(m_rp_TgtCrv_Limited__1pm, debugString));
        DrawTextLCF(x_coord_c1, start_y_coord + y_offset_inc* step++, offset, colorWhite, CHECK_IS_CONNECTED(m_rp_TgtCrv_Gradient__1pms), "Crv.TgtCrv_Gradient__1pms", font, CHECK_PORT_AVAIL(m_rp_TgtCrv_Gradient__1pms, debugString));
        DrawTextLCF(x_coord_c1, start_y_coord + y_offset_inc* step++, offset, colorWhite, CHECK_IS_CONNECTED(m_rp_TgtVehCtrlQualifier_nu), "Flags.TgtVehCtrlQualifier_nu", font, CHECK_PORT_AVAIL(m_rp_TgtVehCtrlQualifier_nu, debugString));
        DrawTextLCF(x_coord_c1, start_y_coord + y_offset_inc* step++, offset, colorWhite, CHECK_IS_CONNECTED(m_rp_TgtCrv_LimiterWarning_nu), "Flags.TgtCrv_LimiterWarning_nu", font, CHECK_PORT_AVAIL(m_rp_TgtCrv_LimiterWarning_nu, debugString));
        DrawTextLCF(x_coord_c1, start_y_coord + y_offset_inc* step++, offset, colorWhite, CHECK_IS_CONNECTED(m_rp_TrjCtrQualifierService_nu), "Flags.TrjCtrQualifierService_nu", font, CHECK_PORT_AVAIL(m_rp_TrjCtrQualifierService_nu, debugString));
        DrawTextLCF(x_coord_c1, start_y_coord + y_offset_inc* step++, offset, colorWhite, CHECK_IS_CONNECTED(m_rp_QuStatusTrajPlan_nu), "Flags.QuStatusTrajPlan_nu", font, CHECK_PORT_AVAIL(m_rp_QuStatusTrajPlan_nu, debugString));
        DrawTextLCF(x_coord_c1, start_y_coord + y_offset_inc* step++, offset, colorWhite, CHECK_IS_CONNECTED(m_rp_LaDmcQualifierService_nu), "Flags.LaDmcQualifierService_nu", font, CHECK_PORT_AVAIL(m_rp_LaDmcQualifierService_nu, debugString));
        DrawTextLCF(x_coord_c1, start_y_coord + y_offset_inc* step++, offset, colorWhite, CHECK_IS_CONNECTED(m_rp_Veh2Sen_EventId_nu_0_), "EvntDtctnSenEvents[0].EventId_nu", font, CHECK_PORT_AVAIL(m_rp_Veh2Sen_EventId_nu_0_, debugString));
        DrawTextLCF(x_coord_c1, start_y_coord + y_offset_inc* step++, offset, colorWhite, CHECK_IS_CONNECTED(m_rp_Veh2Sen_EventLifetime_nu_0_), "EvntDtctnSenEvents[0].EventLifetime_nu", font, CHECK_PORT_AVAIL(m_rp_Veh2Sen_EventLifetime_nu_0_, debugString));
        DrawTextLCF(x_coord_c1, start_y_coord + y_offset_inc* step++, offset, colorWhite, CHECK_IS_CONNECTED(m_rp_Veh2Sen_EventId_nu_1_), "EvntDtctnSenEvents[1].EventId_nu", font, CHECK_PORT_AVAIL(m_rp_Veh2Sen_EventId_nu_1_, debugString));
        DrawTextLCF(x_coord_c1, start_y_coord + y_offset_inc* step++, offset, colorWhite, CHECK_IS_CONNECTED(m_rp_Veh2Sen_EventLifetime_nu_1_), "EvntDtctnSenEvents[1].EventLifetime_nu", font, CHECK_PORT_AVAIL(m_rp_Veh2Sen_EventLifetime_nu_1_, debugString));
        DrawTextLCF(x_coord_c1, start_y_coord + y_offset_inc* step++, offset, colorWhite, CHECK_IS_CONNECTED(m_rp_Veh2Sen_EventId_nu_2_), "EvntDtctnSenEvents[2].EventId_nu", font, CHECK_PORT_AVAIL(m_rp_Veh2Sen_EventId_nu_2_, debugString));
        DrawTextLCF(x_coord_c1, start_y_coord + y_offset_inc* step++, offset, colorWhite, CHECK_IS_CONNECTED(m_rp_Veh2Sen_EventLifetime_nu_2_), "EvntDtctnSenEvents[2].EventLifetime_nu", font, CHECK_PORT_AVAIL(m_rp_Veh2Sen_EventLifetime_nu_2_, debugString));
        DrawTextLCF(x_coord_c1, start_y_coord + y_offset_inc* step++, offset, colorWhite, CHECK_IS_CONNECTED(m_rp_Veh2Sen_EventId_nu_3_), "EvntDtctnSenEvents[3].EventId_nu", font, CHECK_PORT_AVAIL(m_rp_Veh2Sen_EventId_nu_3_, debugString));
        DrawTextLCF(x_coord_c1, start_y_coord + y_offset_inc* step++, offset, colorWhite, CHECK_IS_CONNECTED(m_rp_Veh2Sen_EventLifetime_nu_3_), "EvntDtctnSenEvents[3].EventLifetime_nu", font, CHECK_PORT_AVAIL(m_rp_Veh2Sen_EventLifetime_nu_3_, debugString));
        DrawTextLCF(x_coord_c1, start_y_coord + y_offset_inc* step++, offset, colorWhite, CHECK_IS_CONNECTED(m_rp_Veh2Sen_EventId_nu_4_), "EvntDtctnSenEvents[4].EventId_nu", font, CHECK_PORT_AVAIL(m_rp_Veh2Sen_EventId_nu_4_, debugString));
        DrawTextLCF(x_coord_c1, start_y_coord + y_offset_inc* step++, offset, colorWhite, CHECK_IS_CONNECTED(m_rp_Veh2Sen_EventLifetime_nu_4_), "EvntDtctnSenEvents[4].EventLifetime_nu", font, CHECK_PORT_AVAIL(m_rp_Veh2Sen_EventLifetime_nu_4_, debugString));
        DrawTextLCF(x_coord_c1, start_y_coord + y_offset_inc* step++, offset, colorWhite, CHECK_IS_CONNECTED(m_rp_Veh2Sen_uiVersionNumber), "uiVersionNumber", font, CHECK_PORT_AVAIL(m_rp_Veh2Sen_uiVersionNumber, debugString));
        DrawTextLCF(x_coord_c1, start_y_coord + y_offset_inc* step++, offset, colorWhite, CHECK_IS_CONNECTED(m_rp_Veh2Sen_uiTimeStamp), "uiTimeStamp", font, CHECK_PORT_AVAIL(m_rp_Veh2Sen_uiTimeStamp, debugString));
        DrawTextLCF(x_coord_c1, start_y_coord + y_offset_inc* step++, offset, colorWhite, CHECK_IS_CONNECTED(m_rp_Veh2Sen_uiMeasurementCounter), "uiMeasurementCounter", font, CHECK_PORT_AVAIL(m_rp_Veh2Sen_uiMeasurementCounter, debugString));
        DrawTextLCF(x_coord_c1, start_y_coord + y_offset_inc* step++, offset, colorWhite, CHECK_IS_CONNECTED(m_rp_Veh2Sen_uiCycleCounter), "uiCycleCounter", font, CHECK_PORT_AVAIL(m_rp_Veh2Sen_uiCycleCounter, debugString));
        DrawTextLCF(x_coord_c1, start_y_coord + y_offset_inc* step++, offset, colorWhite, CHECK_IS_CONNECTED(m_rp_Veh2Sen_eSigStatus), "eSigStatus", font, CHECK_PORT_AVAIL(m_rp_Veh2Sen_eSigStatus, debugString), 36);
	}
	else if (idxSelect == 5 && Data_Validity[4]) {
        DrawTextLCF(x_coord_c1, start_y_coord + y_offset_inc* step++, offset, colorWhite, CHECK_IS_CONNECTED(m_rp_Veh_eGenAlgoQualifier), "LCF_VEH.eGenAlgoQualifier", font, CHECK_PORT_AVAIL(m_rp_Veh_eGenAlgoQualifier, debugString));
	}
}

void CSimLcfVis::Add_LcfGenPort_Signals(IGDVFont& font, int start_y_coord, int x_coord_c1, unsigned short offset, unsigned short y_offset_inc, unsigned char idxSelect)
{
	char debugString[100];
	unsigned char step = 1;

	if (idxSelect == 1 && !m_bDrawHelp) {
        DrawTextLCF(x_coord_c1, start_y_coord, offset, colorWhite, CHECK_IS_CONNECTED(m_rp_SteerHandWheelAngle__rad), "SteerHandWheelAngle__rad", font, CHECK_PORT_AVAIL(m_rp_SteerHandWheelAngle__rad, debugString));
        DrawTextLCF(x_coord_c1, start_y_coord + y_offset_inc* step++, offset, colorWhite, CHECK_IS_CONNECTED(m_rp_SteerHandWheelAngleRate__rps), "SteerHandWheelAngleRate__rps", font, CHECK_PORT_AVAIL(m_rp_SteerHandWheelAngleRate__rps, debugString));
        DrawTextLCF(x_coord_c1, start_y_coord + y_offset_inc* step++, offset, colorWhite, CHECK_IS_CONNECTED(m_rp_DeltaFSteerAngle__deg), "DeltaFSteerAngle__deg", font, CHECK_PORT_AVAIL(m_rp_DeltaFSteerAngle__deg, debugString));
        DrawTextLCF(x_coord_c1, start_y_coord + y_offset_inc* step++, offset, colorWhite, CHECK_IS_CONNECTED(m_rp_DeltaFSteerAngleRate__degps), "DeltaFSteerAngleRate__degps", font, CHECK_PORT_AVAIL(m_rp_DeltaFSteerAngleRate__degps, debugString));
        DrawTextLCF(x_coord_c1, start_y_coord + y_offset_inc* step++, offset, colorWhite, CHECK_IS_CONNECTED(m_rp_SteerTrq__nm), "SteerTrq__nm", font, CHECK_PORT_AVAIL(m_rp_SteerTrq__nm, debugString));
        DrawTextLCF(x_coord_c1, start_y_coord + y_offset_inc* step++, offset, colorWhite, CHECK_IS_CONNECTED(m_rp_DrvSteerWheelTrq__nm), "DrvSteerWheelTrq__nm", font, CHECK_PORT_AVAIL(m_rp_DrvSteerWheelTrq__nm, debugString));
        DrawTextLCF(x_coord_c1, start_y_coord + y_offset_inc* step++, offset, colorWhite, CHECK_IS_CONNECTED(m_rp_EPS_Motor_Torque__nm), "EPS_Motor_Torque__nm", font, CHECK_PORT_AVAIL(m_rp_EPS_Motor_Torque__nm, debugString));
        DrawTextLCF(x_coord_c1, start_y_coord + y_offset_inc* step++, offset, colorWhite, CHECK_IS_CONNECTED(m_rp_ESC_SystemState_nu), "ESC_SystemState_nu", font, CHECK_PORT_AVAIL(m_rp_ESC_SystemState_nu, debugString));
        DrawTextLCF(x_coord_c1, start_y_coord + y_offset_inc* step++, offset, colorWhite, CHECK_IS_CONNECTED(m_rp_ESC_ActiveState_nu), "ESC_ActiveState_nu", font, CHECK_PORT_AVAIL(m_rp_ESC_ActiveState_nu, debugString));
        DrawTextLCF(x_coord_c1, start_y_coord + y_offset_inc* step++, offset, colorWhite, CHECK_IS_CONNECTED(m_rp_ABS_SystemState_nu), "ABS_SystemState_nu", font, CHECK_PORT_AVAIL(m_rp_ABS_SystemState_nu, debugString));
        DrawTextLCF(x_coord_c1, start_y_coord + y_offset_inc* step++, offset, colorWhite, CHECK_IS_CONNECTED(m_rp_ABS_ActiveState_nu), "ABS_ActiveState_nu", font, CHECK_PORT_AVAIL(m_rp_ABS_ActiveState_nu, debugString));
        DrawTextLCF(x_coord_c1, start_y_coord + y_offset_inc* step++, offset, colorWhite, CHECK_IS_CONNECTED(m_rp_TCS_SystemState_nu), "TCS_SystemState_nu", font, CHECK_PORT_AVAIL(m_rp_TCS_SystemState_nu, debugString));
        DrawTextLCF(x_coord_c1, start_y_coord + y_offset_inc* step++, offset, colorWhite, CHECK_IS_CONNECTED(m_rp_TCS_ActiveState_nu), "TCS_ActiveState_nu", font, CHECK_PORT_AVAIL(m_rp_TCS_ActiveState_nu, debugString));
        DrawTextLCF(x_coord_c1, start_y_coord + y_offset_inc* step++, offset, colorWhite, CHECK_IS_CONNECTED(m_rp_ACC_SystemState_nu), "ACC_SystemState_nu", font, CHECK_PORT_AVAIL(m_rp_ACC_SystemState_nu, debugString));
        DrawTextLCF(x_coord_c1, start_y_coord + y_offset_inc* step++, offset, colorWhite, CHECK_IS_CONNECTED(m_rp_ACC_ActiveState_nu), "ACC_ActiveState_nu", font, CHECK_PORT_AVAIL(m_rp_ACC_ActiveState_nu, debugString));
        DrawTextLCF(x_coord_c1, start_y_coord + y_offset_inc* step++, offset, colorWhite, CHECK_IS_CONNECTED(m_rp_VSM_SystemState_nu), "VSM_SystemState_nu", font, CHECK_PORT_AVAIL(m_rp_VSM_SystemState_nu, debugString));
        DrawTextLCF(x_coord_c1, start_y_coord + y_offset_inc* step++, offset, colorWhite, CHECK_IS_CONNECTED(m_rp_VSM_ActiveState_nu), "VSM_ActiveState_nu", font, CHECK_PORT_AVAIL(m_rp_VSM_ActiveState_nu, debugString));
        DrawTextLCF(x_coord_c1, start_y_coord + y_offset_inc* step++, offset, colorWhite, CHECK_IS_CONNECTED(m_rp_EBA_SystemState_nu), "EBA_SystemState_nu", font, CHECK_PORT_AVAIL(m_rp_EBA_SystemState_nu, debugString));
        DrawTextLCF(x_coord_c1, start_y_coord + y_offset_inc* step++, offset, colorWhite, CHECK_IS_CONNECTED(m_rp_EBA_ActiveState_nu), "EBA_ActiveState_nu", font, CHECK_PORT_AVAIL(m_rp_EBA_ActiveState_nu, debugString));
        DrawTextLCF(x_coord_c1, start_y_coord + y_offset_inc* step++, offset, colorWhite, CHECK_IS_CONNECTED(m_rp_EBA_WarningState_nu), "EBA_WarningState_nu", font, CHECK_PORT_AVAIL(m_rp_EBA_WarningState_nu, debugString));
        DrawTextLCF(x_coord_c1, start_y_coord + y_offset_inc* step++, offset, colorWhite, CHECK_IS_CONNECTED(m_rp_TSA_SystemState_nu), "TSA_SystemState_nu", font, CHECK_PORT_AVAIL(m_rp_TSA_SystemState_nu, debugString));
	}
	else if (idxSelect == 2  && !m_bDrawHelp) {
        DrawTextLCF(x_coord_c1, start_y_coord, offset, colorWhite, CHECK_IS_CONNECTED(m_rp_LDPOncomingSwitch_nu), "LDPOncomingSwitch_nu", font, CHECK_PORT_AVAIL(m_rp_LDPOncomingSwitch_nu, debugString));
        #if ((LCF_INPUT_INTFVER >= 18) && (LCF_INPUT_INTFVER < 30)) /* RTE used for AES has a higher version */
		DrawTextLCF(x_coord_c1, start_y_coord + y_offset_inc* step++, offset, colorWhite, CHECK_IS_CONNECTED(m_rp_AoLCSwitch_nu), "AoLCSwitch_nu", font, CHECK_PORT_AVAIL(m_rp_AoLCSwitch_nu, debugString));
        DrawTextLCF(x_coord_c1, start_y_coord + y_offset_inc* step++, offset, colorWhite, CHECK_IS_CONNECTED(m_rp_LDWOncomingSwitch_nu), "LDWOncomingSwitch_nu", font, CHECK_PORT_AVAIL(m_rp_LDWOncomingSwitch_nu, debugString));
        DrawTextLCF(x_coord_c1, start_y_coord + y_offset_inc* step++, offset, colorWhite, CHECK_IS_CONNECTED(m_rp_LDWOCSensitivity_nu), "LDWOCSensitivity_nu", font, CHECK_PORT_AVAIL(m_rp_LDWOCSensitivity_nu, debugString));
		#endif
		DrawTextLCF(x_coord_c1, start_y_coord + y_offset_inc* step++, offset, colorWhite, CHECK_IS_CONNECTED(m_rp_LDWSensitivity_nu), "LDWSensitivity_nu", font, CHECK_PORT_AVAIL(m_rp_LDWSensitivity_nu, debugString));
        DrawTextLCF(x_coord_c1, start_y_coord + y_offset_inc* step++, offset, colorWhite, CHECK_IS_CONNECTED(m_rp_LDPSensitivity_nu), "LDPSensitivity_nu", font, CHECK_PORT_AVAIL(m_rp_LDPSensitivity_nu, debugString));
        DrawTextLCF(x_coord_c1, start_y_coord + y_offset_inc* step++, offset, colorWhite, CHECK_IS_CONNECTED(m_rp_RDPSensitivity_nu), "RDPSensitivity_nu", font, CHECK_PORT_AVAIL(m_rp_RDPSensitivity_nu, debugString));
        #if ((LCF_INPUT_INTFVER >= 18) && (LCF_INPUT_INTFVER < 30)) /* RTE used for AES has a higher version */
		DrawTextLCF(x_coord_c1, start_y_coord + y_offset_inc* step++, offset, colorWhite, CHECK_IS_CONNECTED(m_rp_RDWSensitivity_nu), "RDWSensitivity_nu", font, CHECK_PORT_AVAIL(m_rp_RDWSensitivity_nu, debugString));
        DrawTextLCF(x_coord_c1, start_y_coord + y_offset_inc* step++, offset, colorWhite, CHECK_IS_CONNECTED(m_rp_LDPMode_nu), "LDPMode_nu", font, CHECK_PORT_AVAIL(m_rp_LDPMode_nu, debugString));
        DrawTextLCF(x_coord_c1, start_y_coord + y_offset_inc* step++, offset, colorWhite, CHECK_IS_CONNECTED(m_rp_LDWMode_nu), "LDWMode_nu", font, CHECK_PORT_AVAIL(m_rp_LDWMode_nu, debugString));
        DrawTextLCF(x_coord_c1, start_y_coord + y_offset_inc* step++, offset, colorWhite, CHECK_IS_CONNECTED(m_rp_RDPMode_nu), "RDPMode_nu", font, CHECK_PORT_AVAIL(m_rp_RDPMode_nu, debugString));
        DrawTextLCF(x_coord_c1, start_y_coord + y_offset_inc* step++, offset, colorWhite, CHECK_IS_CONNECTED(m_rp_RDWMode_nu), "RDWMode_nu", font, CHECK_PORT_AVAIL(m_rp_RDWMode_nu, debugString));
        DrawTextLCF(x_coord_c1, start_y_coord + y_offset_inc* step++, offset, colorWhite, CHECK_IS_CONNECTED(m_rp_LDPOCMode_nu), "LDPOCMode_nu", font, CHECK_PORT_AVAIL(m_rp_LDPOCMode_nu, debugString));
        DrawTextLCF(x_coord_c1, start_y_coord + y_offset_inc* step++, offset, colorWhite, CHECK_IS_CONNECTED(m_rp_LDWOCMode_nu), "LDWOCMode_nu", font, CHECK_PORT_AVAIL(m_rp_LDWOCMode_nu, debugString));
        DrawTextLCF(x_coord_c1, start_y_coord + y_offset_inc* step++, offset, colorWhite, CHECK_IS_CONNECTED(m_rp_AoLCMode_nu), "AoLCMode_nu", font, CHECK_PORT_AVAIL(m_rp_AoLCMode_nu, debugString));
		#endif
		DrawTextLCF(x_coord_c1, start_y_coord + y_offset_inc* step++, offset, colorWhite, CHECK_IS_CONNECTED(m_rp_DriverHandsOff_nu), "DriverHandsOff_nu", font, CHECK_PORT_AVAIL(m_rp_DriverHandsOff_nu, debugString));
        DrawTextLCF(x_coord_c1, start_y_coord + y_offset_inc* step++, offset, colorWhite, CHECK_IS_CONNECTED(m_rp_SCCActive_nu), "SCCActive_nu", font, CHECK_PORT_AVAIL(m_rp_SCCActive_nu, debugString));
        DrawTextLCF(x_coord_c1, start_y_coord + y_offset_inc* step++, offset, colorWhite, CHECK_IS_CONNECTED(m_rp_USMReset_nu), "USMReset_nu", font, CHECK_PORT_AVAIL(m_rp_USMReset_nu, debugString));
        DrawTextLCF(x_coord_c1, start_y_coord + y_offset_inc* step++, offset, colorWhite, CHECK_IS_CONNECTED(m_rp_HDAOn_nu), "HDAOn_nu", font, CHECK_PORT_AVAIL(m_rp_HDAOn_nu, debugString));
        DrawTextLCF(x_coord_c1, start_y_coord + y_offset_inc* step++, offset, colorWhite, CHECK_IS_CONNECTED(m_rp_SCCOn_nu), "SCCOn_nu", font, CHECK_PORT_AVAIL(m_rp_SCCOn_nu, debugString));
        DrawTextLCF(x_coord_c1, start_y_coord + y_offset_inc* step++, offset, colorWhite, CHECK_IS_CONNECTED(m_rp_USMSetSpd__kph), "USMSetSpd__kph", font, CHECK_PORT_AVAIL(m_rp_USMSetSpd__kph, debugString));
	}
	else if (idxSelect == 3 && !m_bDrawHelp) {
        DrawTextLCF(x_coord_c1, start_y_coord, offset, colorWhite, CHECK_IS_CONNECTED(m_rp_ALCAMode_nu), "ALCAMode_nu", font, CHECK_PORT_AVAIL(m_rp_ALCAMode_nu, debugString));
        DrawTextLCF(x_coord_c1, start_y_coord + y_offset_inc* step++, offset, colorWhite, CHECK_IS_CONNECTED(m_rp_LCA_Active_Left_nu), "LCA_Active_Left_nu", font, CHECK_PORT_AVAIL(m_rp_LCA_Active_Left_nu, debugString));
        DrawTextLCF(x_coord_c1, start_y_coord + y_offset_inc* step++, offset, colorWhite, CHECK_IS_CONNECTED(m_rp_BSD_Active_Left_nu), "BSD_Active_Left_nu", font, CHECK_PORT_AVAIL(m_rp_BSD_Active_Left_nu, debugString));
        DrawTextLCF(x_coord_c1, start_y_coord + y_offset_inc* step++, offset, colorWhite, CHECK_IS_CONNECTED(m_rp_LCA_Warning_Left_nu), "LCA_Warning_Left_nu", font, CHECK_PORT_AVAIL(m_rp_LCA_Warning_Left_nu, debugString));
        DrawTextLCF(x_coord_c1, start_y_coord + y_offset_inc* step++, offset, colorWhite, CHECK_IS_CONNECTED(m_rp_BSD_Warning_Left_nu), "BSD_Warning_Left_nu", font, CHECK_PORT_AVAIL(m_rp_BSD_Warning_Left_nu, debugString));
        DrawTextLCF(x_coord_c1, start_y_coord + y_offset_inc* step++, offset, colorWhite, CHECK_IS_CONNECTED(m_rp_LCA_Active_Right_nu), "LCA_Active_Right_nu", font, CHECK_PORT_AVAIL(m_rp_LCA_Active_Right_nu, debugString));
        DrawTextLCF(x_coord_c1, start_y_coord + y_offset_inc* step++, offset, colorWhite, CHECK_IS_CONNECTED(m_rp_BSD_Active_Right_nu), "BSD_Active_Right_nu", font, CHECK_PORT_AVAIL(m_rp_BSD_Active_Right_nu, debugString));
        DrawTextLCF(x_coord_c1, start_y_coord + y_offset_inc* step++, offset, colorWhite, CHECK_IS_CONNECTED(m_rp_LCA_Warning_Right_nu), "LCA_Warning_Right_nu", font, CHECK_PORT_AVAIL(m_rp_LCA_Warning_Right_nu, debugString));
        DrawTextLCF(x_coord_c1, start_y_coord + y_offset_inc* step++, offset, colorWhite, CHECK_IS_CONNECTED(m_rp_BSD_Warning_Right_nu), "BSD_Warning_Right_nu", font, CHECK_PORT_AVAIL(m_rp_BSD_Warning_Right_nu, debugString));
        DrawTextLCF(x_coord_c1, start_y_coord + y_offset_inc* step++, offset, colorWhite, CHECK_IS_CONNECTED(m_rp_HapticWrnDeviceLeftState_nu), "HapticWrnDeviceLeftState_nu", font, CHECK_PORT_AVAIL(m_rp_HapticWrnDeviceLeftState_nu, debugString));
        DrawTextLCF(x_coord_c1, start_y_coord + y_offset_inc* step++, offset, colorWhite, CHECK_IS_CONNECTED(m_rp_HapticWrnDeviceRightState_nu), "HapticWrnDeviceRightState_nu", font, CHECK_PORT_AVAIL(m_rp_HapticWrnDeviceRightState_nu, debugString));
        DrawTextLCF(x_coord_c1, start_y_coord + y_offset_inc* step++, offset, colorWhite, CHECK_IS_CONNECTED(m_rp_HapticWrnDeviceCommonState_nu), "HapticWrnDeviceCommonState_nu", font, CHECK_PORT_AVAIL(m_rp_HapticWrnDeviceCommonState_nu, debugString));
        DrawTextLCF(x_coord_c1, start_y_coord + y_offset_inc* step++, offset, colorWhite, CHECK_IS_CONNECTED(m_rp_HapticWrnDeviceLeftMode_nu), "HapticWrnDeviceLeftMode_nu", font, CHECK_PORT_AVAIL(m_rp_HapticWrnDeviceLeftMode_nu, debugString));
        DrawTextLCF(x_coord_c1, start_y_coord + y_offset_inc* step++, offset, colorWhite, CHECK_IS_CONNECTED(m_rp_HapticWrnDeviceRightMode_nu), "HapticWrnDeviceRightMode_nu", font, CHECK_PORT_AVAIL(m_rp_HapticWrnDeviceRightMode_nu, debugString));
        DrawTextLCF(x_coord_c1, start_y_coord + y_offset_inc* step++, offset, colorWhite, CHECK_IS_CONNECTED(m_rp_HapticWrnDeviceCommonMode_nu), "HapticWrnDeviceCommonMode_nu", font, CHECK_PORT_AVAIL(m_rp_HapticWrnDeviceCommonMode_nu, debugString));
        DrawTextLCF(x_coord_c1, start_y_coord + y_offset_inc* step++, offset, colorWhite, CHECK_IS_CONNECTED(m_rp_VisualWrnDeviceLeftState_nu), "VisualWrnDeviceLeftState_nu", font, CHECK_PORT_AVAIL(m_rp_VisualWrnDeviceLeftState_nu, debugString));
        DrawTextLCF(x_coord_c1, start_y_coord + y_offset_inc* step++, offset, colorWhite, CHECK_IS_CONNECTED(m_rp_VisualWrnDeviceRightState_nu), "VisualWrnDeviceRightState_nu", font, CHECK_PORT_AVAIL(m_rp_VisualWrnDeviceRightState_nu, debugString));
        DrawTextLCF(x_coord_c1, start_y_coord + y_offset_inc* step++, offset, colorWhite, CHECK_IS_CONNECTED(m_rp_VisualWrnDeviceCommonState_nu), "VisualWrnDeviceCommonState_nu", font, CHECK_PORT_AVAIL(m_rp_VisualWrnDeviceCommonState_nu, debugString));
        DrawTextLCF(x_coord_c1, start_y_coord + y_offset_inc* step++, offset, colorWhite, CHECK_IS_CONNECTED(m_rp_VisualWrnDeviceLeftMode_nu), "VisualWrnDeviceLeftMode_nu", font, CHECK_PORT_AVAIL(m_rp_VisualWrnDeviceLeftMode_nu, debugString));
        DrawTextLCF(x_coord_c1, start_y_coord + y_offset_inc* step++, offset, colorWhite, CHECK_IS_CONNECTED(m_rp_VisualWrnDeviceRightMode_nu), "VisualWrnDeviceRightMode_nu", font, CHECK_PORT_AVAIL(m_rp_VisualWrnDeviceRightMode_nu, debugString));
        DrawTextLCF(x_coord_c1, start_y_coord + y_offset_inc* step++, offset, colorWhite, CHECK_IS_CONNECTED(m_rp_VisualWrnDeviceCommonMode_nu), "VisualWrnDeviceCommonMode_nu", font, CHECK_PORT_AVAIL(m_rp_VisualWrnDeviceCommonMode_nu, debugString));
	}
	else if (idxSelect == 4 && !m_bDrawHelp) {
        DrawTextLCF(x_coord_c1, start_y_coord, offset, colorWhite, CHECK_IS_CONNECTED(m_rpLCF_TJATargetObject), "TJA_Tgt.SelectedTargetObjDetect_nu", font, GET_SIGNAL_VALUE(m_rpLCF_TJATargetObject, m_LCF_TJATargetObject.SelectedTargetObjDetected_nu, debugString));
        DrawTextLCF(x_coord_c1, start_y_coord + y_offset_inc* step++, offset, colorWhite, CHECK_IS_CONNECTED(m_rpLCF_TJATargetObject), "TJA_Tgt.MovementRelAclX_mps2", font, GET_SIGNAL_VALUE(m_rpLCF_TJATargetObject, m_LCF_TJATargetObject.MovementRelAclX_mps2, debugString));
        DrawTextLCF(x_coord_c1, start_y_coord + y_offset_inc* step++, offset, colorWhite, CHECK_IS_CONNECTED(m_rpLCF_TJATargetObject), "TJA_Tgt.MovementRelVelX_mps", font, GET_SIGNAL_VALUE(m_rpLCF_TJATargetObject, m_LCF_TJATargetObject.MovementRelVelX_mps, debugString));
        DrawTextLCF(x_coord_c1, start_y_coord + y_offset_inc* step++, offset, colorWhite, CHECK_IS_CONNECTED(m_rpLCF_TJATargetObject), "TJA_Tgt.MovementRelAclY_mps2", font, GET_SIGNAL_VALUE(m_rpLCF_TJATargetObject, m_LCF_TJATargetObject.MovementRelAclY_mps2, debugString));
        DrawTextLCF(x_coord_c1, start_y_coord + y_offset_inc* step++, offset, colorWhite, CHECK_IS_CONNECTED(m_rpLCF_TJATargetObject), "TJA_Tgt.MovementRelVelY_mps", font, GET_SIGNAL_VALUE(m_rpLCF_TJATargetObject, m_LCF_TJATargetObject.MovementRelVelY_mps, debugString));
        DrawTextLCF(x_coord_c1, start_y_coord + y_offset_inc* step++, offset, colorWhite, CHECK_IS_CONNECTED(m_rpLCF_TJATargetObject), "TJA_Tgt.PositionPosX_m", font, GET_SIGNAL_VALUE(m_rpLCF_TJATargetObject, m_LCF_TJATargetObject.PositionPosX_m, debugString));
        DrawTextLCF(x_coord_c1, start_y_coord + y_offset_inc* step++, offset, colorWhite, CHECK_IS_CONNECTED(m_rpLCF_TJATargetObject), "TJA_Tgt.PositionPosY_m", font, GET_SIGNAL_VALUE(m_rpLCF_TJATargetObject, m_LCF_TJATargetObject.PositionPosY_m, debugString));
        DrawTextLCF(x_coord_c1, start_y_coord + y_offset_inc* step++, offset, colorWhite, CHECK_IS_CONNECTED(m_rpLCF_TJATargetObject), "TJA_Tgt.PositionPosXStdDev_m", font, GET_SIGNAL_VALUE(m_rpLCF_TJATargetObject, m_LCF_TJATargetObject.PositionPosXStdDev_m, debugString));
        DrawTextLCF(x_coord_c1, start_y_coord + y_offset_inc* step++, offset, colorWhite, CHECK_IS_CONNECTED(m_rpLCF_TJATargetObject), "TJA_Tgt.PositionPosYStdDev_m", font, GET_SIGNAL_VALUE(m_rpLCF_TJATargetObject, m_LCF_TJATargetObject.PositionPosYStdDev_m, debugString));
        DrawTextLCF(x_coord_c1, start_y_coord + y_offset_inc* step++, offset, colorWhite, CHECK_IS_CONNECTED(m_rpLCF_TJATargetObject), "TJA_Tgt.ObjQuality_nu", font, GET_SIGNAL_VALUE(m_rpLCF_TJATargetObject, m_LCF_TJATargetObject.ObjQuality_nu, debugString));
        DrawTextLCF(x_coord_c1, start_y_coord + y_offset_inc* step++, offset, colorWhite, CHECK_IS_CONNECTED(m_rpLCF_TJATargetObject), "TJA_Tgt.ObjRecognClassType_nu", font, GET_SIGNAL_VALUE(m_rpLCF_TJATargetObject, m_LCF_TJATargetObject.ObjRecognClassType_nu, debugString));
        DrawTextLCF(x_coord_c1, start_y_coord + y_offset_inc* step++, offset, colorWhite, CHECK_IS_CONNECTED(m_rpLCF_TJATargetObject), "TJA_Tgt.ObjRecognMeasState_nu", font, GET_SIGNAL_VALUE(m_rpLCF_TJATargetObject, m_LCF_TJATargetObject.ObjRecognMeasState_nu, debugString));
        DrawTextLCF(x_coord_c1, start_y_coord + y_offset_inc* step++, offset, colorWhite, CHECK_IS_CONNECTED(m_rpLCF_TJATargetObject), "TJA_Tgt.DimensionsWidth_m", font, GET_SIGNAL_VALUE(m_rpLCF_TJATargetObject, m_LCF_TJATargetObject.DimensionsWidth_m, debugString));
        DrawTextLCF(x_coord_c1, start_y_coord + y_offset_inc* step++, offset, colorWhite, CHECK_IS_CONNECTED(m_rpLCF_TJATargetObject), "TJA_Tgt.SensorSource_nu", font, GET_SIGNAL_VALUE(m_rpLCF_TJATargetObject, m_LCF_TJATargetObject.SensorSource_nu, debugString));
        DrawTextLCF(x_coord_c1, start_y_coord + y_offset_inc* step++, offset, colorWhite, CHECK_IS_CONNECTED(m_rpLCF_TJATargetObject), "TJA_Tgt.Tstamp_us", font, GET_SIGNAL_VALUE(m_rpLCF_TJATargetObject, m_LCF_TJATargetObject.Tstamp_us, debugString));
        DrawTextLCF(x_coord_c1, start_y_coord + y_offset_inc* step++, offset, colorWhite, CHECK_IS_CONNECTED(m_rpLCF_TJATargetObject), "TJA_Tgt.ObjRecognExtQualifier_nu", font, GET_SIGNAL_VALUE(m_rpLCF_TJATargetObject, m_LCF_TJATargetObject.ObjRecognExtendedQualifier_nu, debugString));
        DrawTextLCF(x_coord_c1, start_y_coord + y_offset_inc* step++, offset, colorWhite, CHECK_IS_CONNECTED(m_rpLCF_TJASideObject), "TJA_Left.PosX_m", font, GET_SIGNAL_VALUE(m_rpLCF_TJASideObject, m_LCF_TJASideObject.SideObjectLeft.PosX_m, debugString));
        DrawTextLCF(x_coord_c1, start_y_coord + y_offset_inc* step++, offset, colorWhite, CHECK_IS_CONNECTED(m_rpLCF_TJASideObject), "TJA_Left.PosY_m", font, GET_SIGNAL_VALUE(m_rpLCF_TJASideObject, m_LCF_TJASideObject.SideObjectLeft.PosY_m, debugString));
        DrawTextLCF(x_coord_c1, start_y_coord + y_offset_inc* step++, offset, colorWhite, CHECK_IS_CONNECTED(m_rpLCF_TJASideObject), "TJA_Left.RelVelX_mps", font, GET_SIGNAL_VALUE(m_rpLCF_TJASideObject, m_LCF_TJASideObject.SideObjectLeft.RelVelX_mps, debugString));
        DrawTextLCF(x_coord_c1, start_y_coord + y_offset_inc* step++, offset, colorWhite, CHECK_IS_CONNECTED(m_rpLCF_TJASideObject), "TJA_Left.RelVelY_mps", font, GET_SIGNAL_VALUE(m_rpLCF_TJASideObject, m_LCF_TJASideObject.SideObjectLeft.RelVelY_mps, debugString));
        DrawTextLCF(x_coord_c1, start_y_coord + y_offset_inc* step++, offset, colorWhite, CHECK_IS_CONNECTED(m_rpLCF_TJASideObject), "TJA_Left.RelAclX_mps2", font, GET_SIGNAL_VALUE(m_rpLCF_TJASideObject, m_LCF_TJASideObject.SideObjectLeft.RelAclX_mps2, debugString));
	}
	else if (idxSelect == 5 && !m_bDrawHelp) {
		DrawTextLCF(x_coord_c1, start_y_coord, offset, colorWhite, CHECK_IS_CONNECTED(m_rp_TSEGapLongDistEgoToTarget_m), "TSEGapLongDistEgoToTarget_m", font, CHECK_PORT_AVAIL(m_rp_TSEGapLongDistEgoToTarget_m, debugString));
        DrawTextLCF(x_coord_c1, start_y_coord + y_offset_inc* step++, offset, colorWhite, CHECK_IS_CONNECTED(m_rp_TSEGapLongDistEgoToTargetPRE_m), "TSEGapLongDistEgoToTargetPRE_m", font, CHECK_PORT_AVAIL(m_rp_TSEGapLongDistEgoToTargetPRE_m, debugString));
        DrawTextLCF(x_coord_c1, start_y_coord + y_offset_inc* step++, offset, colorWhite, CHECK_IS_CONNECTED(m_rp_TSETargetLongVel_mps), "TSETargetLongVel_mps", font, CHECK_PORT_AVAIL(m_rp_TSETargetLongVel_mps, debugString));
        DrawTextLCF(x_coord_c1, start_y_coord + y_offset_inc* step++, offset, colorWhite, CHECK_IS_CONNECTED(m_rp_TSETargetLongAccel_mps2), "TSETargetLongAccel_mps2", font, CHECK_PORT_AVAIL(m_rp_TSETargetLongAccel_mps2, debugString));
        DrawTextLCF(x_coord_c1, start_y_coord + y_offset_inc* step++, offset, colorWhite, CHECK_IS_CONNECTED(m_rp_TSEKappaEvasiveCorrRight__1pm), "TSEKappaEvasiveCorrRight__1pm", font, CHECK_PORT_AVAIL(m_rp_TSEKappaEvasiveCorrRight__1pm, debugString));
        DrawTextLCF(x_coord_c1, start_y_coord + y_offset_inc* step++, offset, colorWhite, CHECK_IS_CONNECTED(m_rp_TSEGapLatDistEgoToCorrLeft_m), "TSEGapLatDistEgoToCorrLeft_m", font, CHECK_PORT_AVAIL(m_rp_TSEGapLatDistEgoToCorrLeft_m, debugString));
        DrawTextLCF(x_coord_c1, start_y_coord + y_offset_inc* step++, offset, colorWhite, CHECK_IS_CONNECTED(m_rp_TSEGapLatDistEgoToCorrRight_m), "TSEGapLatDistEgoToCorrRight_m", font, CHECK_PORT_AVAIL(m_rp_TSEGapLatDistEgoToCorrRight_m, debugString));
        DrawTextLCF(x_coord_c1, start_y_coord + y_offset_inc* step++, offset, colorWhite, CHECK_IS_CONNECTED(m_rp_TSEGapLatDistObjToCorrLeft_m), "TSEGapLatDistObjToCorrLeft_m", font, CHECK_PORT_AVAIL(m_rp_TSEGapLatDistObjToCorrLeft_m, debugString));
        DrawTextLCF(x_coord_c1, start_y_coord + y_offset_inc* step++, offset, colorWhite, CHECK_IS_CONNECTED(m_rp_TSEGapLatDistObjToCorrRight_m), "TSEGapLatDistObjToCorrRight_m", font, CHECK_PORT_AVAIL(m_rp_TSEGapLatDistObjToCorrRight_m, debugString));
        DrawTextLCF(x_coord_c1, start_y_coord + y_offset_inc* step++, offset, colorWhite, CHECK_IS_CONNECTED(m_rp_TSEAEBAcuteDynWarnFCTChan_nu), "TSEAEBAcuteDynWarnFCTChan_nu", font, CHECK_PORT_AVAIL(m_rp_TSEAEBAcuteDynWarnFCTChan_nu, debugString));
        DrawTextLCF(x_coord_c1, start_y_coord + y_offset_inc* step++, offset, colorWhite, CHECK_IS_CONNECTED(m_rp_TSEAEBAcuteDynWarnSigState_nu), "TSEAEBAcuteDynWarnSigState_nu", font, CHECK_PORT_AVAIL(m_rp_TSEAEBAcuteDynWarnSigState_nu, debugString));
        DrawTextLCF(x_coord_c1, start_y_coord + y_offset_inc* step++, offset, colorWhite, CHECK_IS_CONNECTED(m_rp_TSEStatusFunctionEPF_nu), "TSEStatusFunctionEPF_nu", font, CHECK_PORT_AVAIL(m_rp_TSEStatusFunctionEPF_nu, debugString));
        DrawTextLCF(x_coord_c1, start_y_coord + y_offset_inc* step++, offset, colorWhite, CHECK_IS_CONNECTED(m_rp_TSEAEBAnecLongAccel_mpss), "TSEAEBAnecLongAccel_mpss", font, CHECK_PORT_AVAIL(m_rp_TSEAEBAnecLongAccel_mpss, debugString));
        DrawTextLCF(x_coord_c1, start_y_coord + y_offset_inc* step++, offset, colorWhite, CHECK_IS_CONNECTED(m_rp_LCF_GenInput_uiVersionNumber), "uiVersionNumber", font, CHECK_PORT_AVAIL(m_rp_LCF_GenInput_uiVersionNumber, debugString));
        DrawTextLCF(x_coord_c1, start_y_coord + y_offset_inc* step++, offset, colorWhite, CHECK_IS_CONNECTED(m_rp_LCF_GenInput_uiTimeStamp), "uiTimeStamp", font, CHECK_PORT_AVAIL(m_rp_LCF_GenInput_uiTimeStamp, debugString));
        DrawTextLCF(x_coord_c1, start_y_coord + y_offset_inc* step++, offset, colorWhite, CHECK_IS_CONNECTED(m_rp_LCF_GenInput_uiMeasurementCounter), "uiMeasurementCounter", font, CHECK_PORT_AVAIL(m_rp_LCF_GenInput_uiMeasurementCounter, debugString));
        DrawTextLCF(x_coord_c1, start_y_coord + y_offset_inc* step++, offset, colorWhite, CHECK_IS_CONNECTED(m_rp_LCF_GenInput_uiCycleCounter), "uiCycleCounter", font, CHECK_PORT_AVAIL(m_rp_LCF_GenInput_uiCycleCounter, debugString));
        DrawTextLCF(x_coord_c1, start_y_coord + y_offset_inc* step++, offset, colorWhite, CHECK_IS_CONNECTED(m_rp_LCF_GenInput_eSigStatus), "eSigStatus", font, CHECK_PORT_AVAIL(m_rp_LCF_GenInput_eSigStatus, debugString));
	}

	x_coord_c1 += 445;
	offset = 283;
	start_y_coord = 45;
	step = 0;

	if (idxSelect == 1) {
		DrawTextLCF(x_coord_c1, start_y_coord + y_offset_inc* step++, offset, colorWhite, CHECK_IS_CONNECTED(m_rp_TSA_ActiveState_nu), "TSA_ActiveState_nu", font, CHECK_PORT_AVAIL(m_rp_TSA_ActiveState_nu, debugString));
		DrawTextLCF(x_coord_c1, start_y_coord + y_offset_inc* step++, offset, colorWhite, CHECK_IS_CONNECTED(m_rp_DynamometerTestBenchDetected_nu), "DynamometerTestBenchDetected_nu", font, CHECK_PORT_AVAIL(m_rp_DynamometerTestBenchDetected_nu, debugString));
        DrawTextLCF(x_coord_c1, start_y_coord + y_offset_inc* step++, offset, colorWhite, CHECK_IS_CONNECTED(m_rp_DoorOpen_nu), "DoorOpen_nu", font, CHECK_PORT_AVAIL(m_rp_DoorOpen_nu, debugString));
        DrawTextLCF(x_coord_c1, start_y_coord + y_offset_inc* step++, offset, colorWhite, CHECK_IS_CONNECTED(m_rp_TurnSignalState_nu), "TurnSignalState_nu", font, CHECK_PORT_AVAIL(m_rp_TurnSignalState_nu, debugString));
        DrawTextLCF(x_coord_c1, start_y_coord + y_offset_inc* step++, offset, colorWhite, CHECK_IS_CONNECTED(m_rp_TurnSignalLever_nu), "TurnSignalLever_nu", font, CHECK_PORT_AVAIL(m_rp_TurnSignalLever_nu, debugString));
        DrawTextLCF(x_coord_c1, start_y_coord + y_offset_inc* step++, offset, colorWhite, CHECK_IS_CONNECTED(m_rp_VehicleReadyState_nu), "VehicleReadyState_nu", font, CHECK_PORT_AVAIL(m_rp_VehicleReadyState_nu, debugString));
        DrawTextLCF(x_coord_c1, start_y_coord + y_offset_inc* step++, offset, colorWhite, CHECK_IS_CONNECTED(m_rp_DriverNotBuckledUp_nu), "DriverNotBuckledUp_nu", font, CHECK_PORT_AVAIL(m_rp_DriverNotBuckledUp_nu, debugString));
        DrawTextLCF(x_coord_c1, start_y_coord + y_offset_inc* step++, offset, colorWhite, CHECK_IS_CONNECTED(m_rp_OversteeringDetected_nu), "OversteeringDetected_nu", font, CHECK_PORT_AVAIL(m_rp_OversteeringDetected_nu, debugString));
        DrawTextLCF(x_coord_c1, start_y_coord + y_offset_inc* step++, offset, colorWhite, CHECK_IS_CONNECTED(m_rp_UndersteeringDetected_nu), "UndersteeringDetected_nu", font, CHECK_PORT_AVAIL(m_rp_UndersteeringDetected_nu, debugString));
        DrawTextLCF(x_coord_c1, start_y_coord + y_offset_inc* step++, offset, colorWhite, CHECK_IS_CONNECTED(m_rp_BankAngle__rad), "BankAngle__rad", font, CHECK_PORT_AVAIL(m_rp_BankAngle__rad, debugString));
        DrawTextLCF(x_coord_c1, start_y_coord + y_offset_inc* step++, offset, colorWhite, CHECK_IS_CONNECTED(m_rp_TieRodLoad__n), "TieRodLoad__n", font, CHECK_PORT_AVAIL(m_rp_TieRodLoad__n, debugString));
        DrawTextLCF(x_coord_c1, start_y_coord + y_offset_inc* step++, offset, colorWhite, CHECK_IS_CONNECTED(m_rp_EPS_Toi_Unavail_nu), "EPS_Toi_Unavail_nu", font, CHECK_PORT_AVAIL(m_rp_EPS_Toi_Unavail_nu, debugString));
        DrawTextLCF(x_coord_c1, start_y_coord + y_offset_inc* step++, offset, colorWhite, CHECK_IS_CONNECTED(m_rp_EPS_Toi_Active_nu), "EPS_Toi_Active_nu", font, CHECK_PORT_AVAIL(m_rp_EPS_Toi_Active_nu, debugString));
        DrawTextLCF(x_coord_c1, start_y_coord + y_offset_inc* step++, offset, colorWhite, CHECK_IS_CONNECTED(m_rp_EPS_Toi_Flt_nu), "EPS_Toi_Flt_nu", font, CHECK_PORT_AVAIL(m_rp_EPS_Toi_Flt_nu, debugString));
        DrawTextLCF(x_coord_c1, start_y_coord + y_offset_inc* step++, offset, colorWhite, CHECK_IS_CONNECTED(m_rp_EPS_Fail_Stat_nu), "EPS_Fail_Stat_nu", font, CHECK_PORT_AVAIL(m_rp_EPS_Fail_Stat_nu, debugString));
        DrawTextLCF(x_coord_c1, start_y_coord + y_offset_inc* step++, offset, colorWhite, CHECK_IS_CONNECTED(m_rp_EPS_Def_nu), "EPS_Def_nu", font, CHECK_PORT_AVAIL(m_rp_EPS_Def_nu, debugString));
        DrawTextLCF(x_coord_c1, start_y_coord + y_offset_inc* step++, offset, colorWhite, CHECK_IS_CONNECTED(m_rp_LKAMainSwitch_nu), "LKAMainSwitch_nu", font, CHECK_PORT_AVAIL(m_rp_LKAMainSwitch_nu, debugString));
        DrawTextLCF(x_coord_c1, start_y_coord + y_offset_inc* step++, offset, colorWhite, CHECK_IS_CONNECTED(m_rp_LKAMode_nu), "LKAMode_nu", font, CHECK_PORT_AVAIL(m_rp_LKAMode_nu, debugString));
        DrawTextLCF(x_coord_c1, start_y_coord + y_offset_inc* step++, offset, colorWhite, CHECK_IS_CONNECTED(m_rp_TJAMainSwitch_nu), "TJAMainSwitch_nu", font, CHECK_PORT_AVAIL(m_rp_TJAMainSwitch_nu, debugString));
        DrawTextLCF(x_coord_c1, start_y_coord + y_offset_inc* step++, offset, colorWhite, CHECK_IS_CONNECTED(m_rp_TJAMode_nu), "TJAMode_nu", font, CHECK_PORT_AVAIL(m_rp_TJAMode_nu, debugString));
        DrawTextLCF(x_coord_c1, start_y_coord + y_offset_inc* step++, offset, colorWhite, CHECK_IS_CONNECTED(m_rp_VibrationActState_nu), "VibrationActState_nu", font, CHECK_PORT_AVAIL(m_rp_VibrationActState_nu, debugString));
        DrawTextLCF(x_coord_c1, start_y_coord + y_offset_inc* step++, offset, colorWhite, CHECK_IS_CONNECTED(m_rp_SideMirrorLEDState_nu), "SideMirrorLEDState_nu", font, CHECK_PORT_AVAIL(m_rp_SideMirrorLEDState_nu, debugString));
        DrawTextLCF(x_coord_c1, start_y_coord + y_offset_inc* step++, offset, colorWhite, CHECK_IS_CONNECTED(m_rp_LDWSwitch_nu), "LDWSwitch_nu", font, CHECK_PORT_AVAIL(m_rp_LDWSwitch_nu, debugString));
        DrawTextLCF(x_coord_c1, start_y_coord + y_offset_inc* step++, offset, colorWhite, CHECK_IS_CONNECTED(m_rp_LDPSwitch_nu), "LDPSwitch_nu", font, CHECK_PORT_AVAIL(m_rp_LDPSwitch_nu, debugString));
        DrawTextLCF(x_coord_c1, start_y_coord + y_offset_inc* step++, offset, colorWhite, CHECK_IS_CONNECTED(m_rp_RDWSwitch_nu), "RDWSwitch_nu", font, CHECK_PORT_AVAIL(m_rp_RDWSwitch_nu, debugString));
        DrawTextLCF(x_coord_c1, start_y_coord + y_offset_inc* step++, offset, colorWhite, CHECK_IS_CONNECTED(m_rp_RDPSwitch_nu), "RDPSwitch_nu", font, CHECK_PORT_AVAIL(m_rp_RDPSwitch_nu, debugString));
	}
	else if (idxSelect == 2) {
		DrawTextLCF(x_coord_c1, start_y_coord + y_offset_inc* step++, offset, colorWhite, CHECK_IS_CONNECTED(m_rp_NAVIRoadType_nu), "NAVIRoadType_nu", font, CHECK_PORT_AVAIL(m_rp_NAVIRoadType_nu, debugString));
        DrawTextLCF(x_coord_c1, start_y_coord + y_offset_inc* step++, offset, colorWhite, CHECK_IS_CONNECTED(m_rp_NAVISegFormOfWay_nu), "NAVISegFormOfWay_nu", font, CHECK_PORT_AVAIL(m_rp_NAVISegFormOfWay_nu, debugString));
        DrawTextLCF(x_coord_c1, start_y_coord + y_offset_inc* step++, offset, colorWhite, CHECK_IS_CONNECTED(m_rp_NAVISegSpeedLim__kph), "NAVISegSpeedLim__kph", font, CHECK_PORT_AVAIL(m_rp_NAVISegSpeedLim__kph, debugString));
        DrawTextLCF(x_coord_c1, start_y_coord + y_offset_inc* step++, offset, colorWhite, CHECK_IS_CONNECTED(m_rp_NAVIStatus_nu), "NAVIStatus_nu", font, CHECK_PORT_AVAIL(m_rp_NAVIStatus_nu, debugString));
        DrawTextLCF(x_coord_c1, start_y_coord + y_offset_inc* step++, offset, colorWhite, CHECK_IS_CONNECTED(m_rp_NAVIProlProfType_nu), "NAVIProlProfType_nu", font, CHECK_PORT_AVAIL(m_rp_NAVIProlProfType_nu, debugString));
        DrawTextLCF(x_coord_c1, start_y_coord + y_offset_inc* step++, offset, colorWhite, CHECK_IS_CONNECTED(m_rp_NAVITollgateDet_nu), "NAVITollgateDet_nu", font, CHECK_PORT_AVAIL(m_rp_NAVITollgateDet_nu, debugString));
        DrawTextLCF(x_coord_c1, start_y_coord + y_offset_inc* step++, offset, colorWhite, CHECK_IS_CONNECTED(m_rp_NAVITgDetDistOffset_m), "NAVITgDetDistOffset_m", font, CHECK_PORT_AVAIL(m_rp_NAVITgDetDistOffset_m, debugString));
        DrawTextLCF(x_coord_c1, start_y_coord + y_offset_inc* step++, offset, colorWhite, CHECK_IS_CONNECTED(m_rp_NAVIPosOffset_m), "NAVIPosOffset_m", font, CHECK_PORT_AVAIL(m_rp_NAVIPosOffset_m, debugString));
        DrawTextLCF(x_coord_c1, start_y_coord + y_offset_inc* step++, offset, colorWhite, CHECK_IS_CONNECTED(m_rp_NAVIProlCyclicCount_nu), "NAVIProlCyclicCount_nu", font, CHECK_PORT_AVAIL(m_rp_NAVIProlCyclicCount_nu, debugString));
        DrawTextLCF(x_coord_c1, start_y_coord + y_offset_inc* step++, offset, colorWhite, CHECK_IS_CONNECTED(m_rp_NAVIPosCyclicCount_nu), "NAVIPosCyclicCount_nu", font, CHECK_PORT_AVAIL(m_rp_NAVIPosCyclicCount_nu, debugString));
        DrawTextLCF(x_coord_c1, start_y_coord + y_offset_inc* step++, offset, colorWhite, CHECK_IS_CONNECTED(m_rp_HDAExtFailFlag_nu), "HDAExtFailFlag_nu", font, CHECK_PORT_AVAIL(m_rp_HDAExtFailFlag_nu, debugString));
        DrawTextLCF(x_coord_c1, start_y_coord + y_offset_inc* step++, offset, colorWhite, CHECK_IS_CONNECTED(m_rp_SCCMainMode_nu), "SCCMainMode_nu", font, CHECK_PORT_AVAIL(m_rp_SCCMainMode_nu, debugString));
        DrawTextLCF(x_coord_c1, start_y_coord + y_offset_inc* step++, offset, colorWhite, CHECK_IS_CONNECTED(m_rp_NAVISpeedUnit_nu), "NAVISpeedUnit_nu", font, CHECK_PORT_AVAIL(m_rp_NAVISpeedUnit_nu, debugString));
        DrawTextLCF(x_coord_c1, start_y_coord + y_offset_inc* step++, offset, colorWhite, CHECK_IS_CONNECTED(m_rp_AlwaysHandsOn_nu), "AlwaysHandsOn_nu", font, CHECK_PORT_AVAIL(m_rp_AlwaysHandsOn_nu, debugString));
        DrawTextLCF(x_coord_c1, start_y_coord + y_offset_inc* step++, offset, colorWhite, CHECK_IS_CONNECTED(m_rp_AccelPedalPos_nu), "AccelPedalPos_nu", font, CHECK_PORT_AVAIL(m_rp_AccelPedalPos_nu, debugString));
        DrawTextLCF(x_coord_c1, start_y_coord + y_offset_inc* step++, offset, colorWhite, CHECK_IS_CONNECTED(m_rp_LcfVariantInfo_nu), "LcfVariantInfo_nu", font, CHECK_PORT_AVAIL(m_rp_LcfVariantInfo_nu, debugString));
        DrawTextLCF(x_coord_c1, start_y_coord + y_offset_inc* step++, offset, colorWhite, CHECK_IS_CONNECTED(m_rp_DanRearObjBS_RearLeft_nu), "DanRearObjBS_RearLeft_nu", font, CHECK_PORT_AVAIL(m_rp_DanRearObjBS_RearLeft_nu, debugString));
        DrawTextLCF(x_coord_c1, start_y_coord + y_offset_inc* step++, offset, colorWhite, CHECK_IS_CONNECTED(m_rp_DanRearObjFOV_RearLeft_nu), "DanRearObjFOV_RearLeft_nu", font, CHECK_PORT_AVAIL(m_rp_DanRearObjFOV_RearLeft_nu, debugString));
        DrawTextLCF(x_coord_c1, start_y_coord + y_offset_inc* step++, offset, colorWhite, CHECK_IS_CONNECTED(m_rp_OIQualifierFlag_RearLeft_nu), "OIQualifierFlag_RearLeft_nu", font, CHECK_PORT_AVAIL(m_rp_OIQualifierFlag_RearLeft_nu, debugString));
        DrawTextLCF(x_coord_c1, start_y_coord + y_offset_inc* step++, offset, colorWhite, CHECK_IS_CONNECTED(m_rp_MSFlag_RearLeft_nu), "MSFlag_RearLeft_nu", font, CHECK_PORT_AVAIL(m_rp_MSFlag_RearLeft_nu, debugString));
        DrawTextLCF(x_coord_c1, start_y_coord + y_offset_inc* step++, offset, colorWhite, CHECK_IS_CONNECTED(m_rp_DanRearObjBS_RearRight_nu), "DanRearObjBS_RearRight_nu", font, CHECK_PORT_AVAIL(m_rp_DanRearObjBS_RearRight_nu, debugString));
        DrawTextLCF(x_coord_c1, start_y_coord + y_offset_inc* step++, offset, colorWhite, CHECK_IS_CONNECTED(m_rp_DanRearObjFOV_RearRight_nu), "DanRearObjFOV_RearRight_nu", font, CHECK_PORT_AVAIL(m_rp_DanRearObjFOV_RearRight_nu, debugString));
        DrawTextLCF(x_coord_c1, start_y_coord + y_offset_inc* step++, offset, colorWhite, CHECK_IS_CONNECTED(m_rp_OIQualifierFlag_RearRight_nu), "OIQualifierFlag_RearRight_nu", font, CHECK_PORT_AVAIL(m_rp_OIQualifierFlag_RearRight_nu, debugString));
        DrawTextLCF(x_coord_c1, start_y_coord + y_offset_inc* step++, offset, colorWhite, CHECK_IS_CONNECTED(m_rp_MSFlag_RearRight_nu), "MSFlag_RearRight_nu", font, CHECK_PORT_AVAIL(m_rp_MSFlag_RearRight_nu, debugString));
        DrawTextLCF(x_coord_c1, start_y_coord + y_offset_inc* step++, offset, colorWhite, CHECK_IS_CONNECTED(m_rp_ALCASwitch_nu), "ALCASwitch_nu", font, CHECK_PORT_AVAIL(m_rp_ALCASwitch_nu, debugString));
        DrawTextLCF(x_coord_c1, start_y_coord + y_offset_inc* step++, offset, colorWhite, CHECK_IS_CONNECTED(m_rp_ALCASensitivity_nu), "ALCASensitivity_nu", font, CHECK_PORT_AVAIL(m_rp_ALCASensitivity_nu, debugString));
	}
	else if (idxSelect == 3) {
        DrawTextLCF(x_coord_c1, start_y_coord + y_offset_inc* step++, offset, colorWhite, CHECK_IS_CONNECTED(m_rp_LDPOCSensitivity_nu), "LDPOCSensitivity_nu", font, CHECK_PORT_AVAIL(m_rp_LDPOCSensitivity_nu, debugString));
        DrawTextLCF(x_coord_c1, start_y_coord + y_offset_inc* step++, offset, colorWhite, CHECK_IS_CONNECTED(m_rp_AoLCSensitivity_nu), "AoLCSensitivity_nu", font, CHECK_PORT_AVAIL(m_rp_AoLCSensitivity_nu, debugString));
        DrawTextLCF(x_coord_c1, start_y_coord + y_offset_inc* step++, offset, colorWhite, CHECK_IS_CONNECTED(m_rp_TJALatCtrlActive_nu), "TJALatCtrlActive_nu", font, CHECK_PORT_AVAIL(m_rp_TJALatCtrlActive_nu, debugString));
        DrawTextLCF(x_coord_c1, start_y_coord + y_offset_inc* step++, offset, colorWhite, CHECK_IS_CONNECTED(m_rp_TJAHandsOffWrnEnable_nu), "TJAHandsOffWrnEnable_nu", font, CHECK_PORT_AVAIL(m_rp_TJAHandsOffWrnEnable_nu, debugString));
        DrawTextLCF(x_coord_c1, start_y_coord + y_offset_inc* step++, offset, colorWhite, CHECK_IS_CONNECTED(m_rp_EPSSteerCtrlMode_nu), "EPSSteerCtrlMode_nu", font, CHECK_PORT_AVAIL(m_rp_EPSSteerCtrlMode_nu, debugString));
        DrawTextLCF(x_coord_c1, start_y_coord + y_offset_inc* step++, offset, colorWhite, CHECK_IS_CONNECTED(m_rp_EPSECUActFact_nu), "EPSECUActFact_nu", font, CHECK_PORT_AVAIL(m_rp_EPSECUActFact_nu, debugString));
        DrawTextLCF(x_coord_c1, start_y_coord + y_offset_inc* step++, offset, colorWhite, CHECK_IS_CONNECTED(m_rp_EPSDriverIntervention_nu), "EPSDriverIntervention_nu", font, CHECK_PORT_AVAIL(m_rp_EPSDriverIntervention_nu, debugString));
        DrawTextLCF(x_coord_c1, start_y_coord + y_offset_inc* step++, offset, colorWhite, CHECK_IS_CONNECTED(m_rp_EPSReqTrq__nm), "EPSReqTrq__nm", font, CHECK_PORT_AVAIL(m_rp_EPSReqTrq__nm, debugString));
        DrawTextLCF(x_coord_c1, start_y_coord + y_offset_inc* step++, offset, colorWhite, CHECK_IS_CONNECTED(m_rp_EPSMotTrq__nm), "EPSMotTrq__nm", font, CHECK_PORT_AVAIL(m_rp_EPSMotTrq__nm, debugString));
        DrawTextLCF(x_coord_c1, start_y_coord + y_offset_inc* step++, offset, colorWhite, CHECK_IS_CONNECTED(m_rp_EPSMotAngSpd__degps), "EPSMotAngSpd__degps", font, CHECK_PORT_AVAIL(m_rp_EPSMotAngSpd__degps, debugString));
        DrawTextLCF(x_coord_c1, start_y_coord + y_offset_inc* step++, offset, colorWhite, CHECK_IS_CONNECTED(m_rp_EPSReqStAng__deg), "EPSReqStAng__deg", font, CHECK_PORT_AVAIL(m_rp_EPSReqStAng__deg, debugString));
		#if ((LCF_INPUT_INTFVER >= 18) && (LCF_INPUT_INTFVER < 30)) /* RTE used for AES has a higher version */ 
        DrawTextLCF(x_coord_c1, start_y_coord + y_offset_inc* step++, offset, colorWhite, CHECK_IS_CONNECTED(m_rp_SteerWheelAngSensorStatus_nu), "SteerWheelAngSensorStatus_nu", font, CHECK_PORT_AVAIL(m_rp_SteerWheelAngSensorStatus_nu, debugString));
        DrawTextLCF(x_coord_c1, start_y_coord + y_offset_inc* step++, offset, colorWhite, CHECK_IS_CONNECTED(m_rp_CommunicationLostEps_nu), "CommunicationLostEps_nu", font, CHECK_PORT_AVAIL(m_rp_CommunicationLostEps_nu, debugString));
        DrawTextLCF(x_coord_c1, start_y_coord + y_offset_inc* step++, offset, colorWhite, CHECK_IS_CONNECTED(m_rp_CommunicationLostSCS_nu), "CommunicationLostSCS_nu", font, CHECK_PORT_AVAIL(m_rp_CommunicationLostSCS_nu, debugString));
        DrawTextLCF(x_coord_c1, start_y_coord + y_offset_inc* step++, offset, colorWhite, CHECK_IS_CONNECTED(m_rp_CommunicationLostTCM_nu), "CommunicationLostTCM_nu", font, CHECK_PORT_AVAIL(m_rp_CommunicationLostTCM_nu, debugString));
        DrawTextLCF(x_coord_c1, start_y_coord + y_offset_inc* step++, offset, colorWhite, CHECK_IS_CONNECTED(m_rp_MainCylPressure_pa), "MainCylPressure_pa", font, CHECK_PORT_AVAIL(m_rp_MainCylPressure_pa, debugString));
        DrawTextLCF(x_coord_c1, start_y_coord + y_offset_inc* step++, offset, colorWhite, CHECK_IS_CONNECTED(m_rp_TerrainMode_nu), "TerrainMode_nu", font, CHECK_PORT_AVAIL(m_rp_TerrainMode_nu, debugString));
		#endif
		DrawTextLCF(x_coord_c1, start_y_coord + y_offset_inc* step++, offset, colorWhite, CHECK_IS_CONNECTED(m_rp_ASLRNG_nu), "ASLRNG_nu", font, CHECK_PORT_AVAIL(m_rp_ASLRNG_nu, debugString));
        DrawTextLCF(x_coord_c1, start_y_coord + y_offset_inc* step++, offset, colorWhite, CHECK_IS_CONNECTED(m_rp_GOS_Lamp_nu), "GOS_Lamp_nu", font, CHECK_PORT_AVAIL(m_rp_GOS_Lamp_nu, debugString));
        DrawTextLCF(x_coord_c1, start_y_coord + y_offset_inc* step++, offset, colorWhite, CHECK_IS_CONNECTED(m_rp_GOS_Multi_inf_nu), "GOS_Multi_inf_nu", font, CHECK_PORT_AVAIL(m_rp_GOS_Multi_inf_nu, debugString));
        DrawTextLCF(x_coord_c1, start_y_coord + y_offset_inc* step++, offset, colorWhite, CHECK_IS_CONNECTED(m_rp_CWA_Activation_nu), "CWA_Activation_nu", font, CHECK_PORT_AVAIL(m_rp_CWA_Activation_nu, debugString));
        DrawTextLCF(x_coord_c1, start_y_coord + y_offset_inc* step++, offset, colorWhite, CHECK_IS_CONNECTED(m_rp_PCS_Destination_nu), "PCS_Destination_nu", font, CHECK_PORT_AVAIL(m_rp_PCS_Destination_nu, debugString));
        DrawTextLCF(x_coord_c1, start_y_coord + y_offset_inc* step++, offset, colorWhite, CHECK_IS_CONNECTED(m_rp_PCS_AES_invalid_flag1_nu), "PCS_AES_invalid_flag1_nu", font, CHECK_PORT_AVAIL(m_rp_PCS_AES_invalid_flag1_nu, debugString));
	}
	else if (idxSelect == 4) {
        DrawTextLCF(x_coord_c1, start_y_coord + y_offset_inc* step++, offset, colorWhite, CHECK_IS_CONNECTED(m_rpLCF_TJASideObject), "TJA_Left.RelAclY_mps2", font, GET_SIGNAL_VALUE(m_rpLCF_TJASideObject, m_LCF_TJASideObject.SideObjectLeft.RelAclY_mps2, debugString));
        DrawTextLCF(x_coord_c1, start_y_coord + y_offset_inc* step++, offset, colorWhite, CHECK_IS_CONNECTED(m_rpLCF_TJASideObject), "TJA_Left.Quality_nu", font, GET_SIGNAL_VALUE(m_rpLCF_TJASideObject, m_LCF_TJASideObject.SideObjectLeft.Quality_nu, debugString));
        DrawTextLCF(x_coord_c1, start_y_coord + y_offset_inc* step++, offset, colorWhite, CHECK_IS_CONNECTED(m_rpLCF_TJASideObject), "TJA_Left.MeasState_nu", font, GET_SIGNAL_VALUE(m_rpLCF_TJASideObject, m_LCF_TJASideObject.SideObjectLeft.MeasState_nu, debugString));
        DrawTextLCF(x_coord_c1, start_y_coord + y_offset_inc* step++, offset, colorWhite, CHECK_IS_CONNECTED(m_rpLCF_TJASideObject), "TJA_Left.ObjRecognClassType_nu", font, GET_SIGNAL_VALUE(m_rpLCF_TJASideObject, m_LCF_TJASideObject.SideObjectLeft.ObjRecognClassType_nu, debugString));
        DrawTextLCF(x_coord_c1, start_y_coord + y_offset_inc* step++, offset, colorWhite, CHECK_IS_CONNECTED(m_rpLCF_TJASideObject), "TJA_Left.ObjTstamp_us", font, GET_SIGNAL_VALUE(m_rpLCF_TJASideObject, m_LCF_TJASideObject.SideObjectLeft.ObjTstamp_us, debugString));
        DrawTextLCF(x_coord_c1, start_y_coord + y_offset_inc* step++, offset, colorWhite, CHECK_IS_CONNECTED(m_rpLCF_TJASideObject), "TJA_Right.PosX_m", font, GET_SIGNAL_VALUE(m_rpLCF_TJASideObject, m_LCF_TJASideObject.SideObjectRight.PosX_m, debugString));
        DrawTextLCF(x_coord_c1, start_y_coord + y_offset_inc* step++, offset, colorWhite, CHECK_IS_CONNECTED(m_rpLCF_TJASideObject), "TJA_Right.PosY_m", font, GET_SIGNAL_VALUE(m_rpLCF_TJASideObject, m_LCF_TJASideObject.SideObjectRight.PosY_m, debugString));
        DrawTextLCF(x_coord_c1, start_y_coord + y_offset_inc* step++, offset, colorWhite, CHECK_IS_CONNECTED(m_rpLCF_TJASideObject), "TJA_Right.RelVelX_mps", font, GET_SIGNAL_VALUE(m_rpLCF_TJASideObject, m_LCF_TJASideObject.SideObjectRight.RelVelX_mps, debugString));
        DrawTextLCF(x_coord_c1, start_y_coord + y_offset_inc* step++, offset, colorWhite, CHECK_IS_CONNECTED(m_rpLCF_TJASideObject), "TJA_Right.RelVelY_mps", font, GET_SIGNAL_VALUE(m_rpLCF_TJASideObject, m_LCF_TJASideObject.SideObjectRight.RelVelY_mps, debugString));
        DrawTextLCF(x_coord_c1, start_y_coord + y_offset_inc* step++, offset, colorWhite, CHECK_IS_CONNECTED(m_rpLCF_TJASideObject), "TJA_Right.RelAclX_mps2", font, GET_SIGNAL_VALUE(m_rpLCF_TJASideObject, m_LCF_TJASideObject.SideObjectRight.RelAclX_mps2, debugString));
        DrawTextLCF(x_coord_c1, start_y_coord + y_offset_inc* step++, offset, colorWhite, CHECK_IS_CONNECTED(m_rpLCF_TJASideObject), "TJA_Right.RelAclY_mps2", font, GET_SIGNAL_VALUE(m_rpLCF_TJASideObject, m_LCF_TJASideObject.SideObjectRight.RelAclY_mps2, debugString));
        DrawTextLCF(x_coord_c1, start_y_coord + y_offset_inc* step++, offset, colorWhite, CHECK_IS_CONNECTED(m_rpLCF_TJASideObject), "TJA_Right.Quality_nu", font, GET_SIGNAL_VALUE(m_rpLCF_TJASideObject, m_LCF_TJASideObject.SideObjectRight.Quality_nu, debugString));
        DrawTextLCF(x_coord_c1, start_y_coord + y_offset_inc* step++, offset, colorWhite, CHECK_IS_CONNECTED(m_rpLCF_TJASideObject), "TJA_Right.MeasState_nu", font, GET_SIGNAL_VALUE(m_rpLCF_TJASideObject, m_LCF_TJASideObject.SideObjectRight.MeasState_nu, debugString));
        DrawTextLCF(x_coord_c1, start_y_coord + y_offset_inc* step++, offset, colorWhite, CHECK_IS_CONNECTED(m_rpLCF_TJASideObject), "TJA_Right.ObjRecognClassType_nu", font, GET_SIGNAL_VALUE(m_rpLCF_TJASideObject, m_LCF_TJASideObject.SideObjectRight.ObjRecognClassType_nu, debugString));
        DrawTextLCF(x_coord_c1, start_y_coord + y_offset_inc* step++, offset, colorWhite, CHECK_IS_CONNECTED(m_rpLCF_TJASideObject), "TJA_Right.ObjTstamp_us", font, GET_SIGNAL_VALUE(m_rpLCF_TJASideObject, m_LCF_TJASideObject.SideObjectRight.ObjTstamp_us, debugString));
        DrawTextLCF(x_coord_c1, start_y_coord + y_offset_inc* step++, offset, colorWhite, CHECK_IS_CONNECTED(m_rp_DangOcObjLe_nu), "FroopToLCF.DangOcObjLe_nu", font, CHECK_PORT_AVAIL(m_rp_DangOcObjLe_nu, debugString));
        DrawTextLCF(x_coord_c1, start_y_coord + y_offset_inc* step++, offset, colorWhite, CHECK_IS_CONNECTED(m_rp_DangOcObjRi_nu), "FroopToLCF.DangOcObjRi_nu", font, CHECK_PORT_AVAIL(m_rp_DangOcObjRi_nu, debugString));
        DrawTextLCF(x_coord_c1, start_y_coord + y_offset_inc* step++, offset, colorWhite, CHECK_IS_CONNECTED(m_rp_QuDangOcObjDtct_nu), "FroopToLCF.QuDangOcObjDtct_nu", font, CHECK_PORT_AVAIL(m_rp_QuDangOcObjDtct_nu, debugString));
		#if ((LCF_INPUT_INTFVER >= 18) && (LCF_INPUT_INTFVER < 30)) /* RTE used for AES has a higher version */
        DrawTextLCF(x_coord_c1, start_y_coord + y_offset_inc* step++, offset, colorWhite, CHECK_IS_CONNECTED(m_rp_ObjectStationaryLeft_nu), "FroopToLCF.ObjectStationaryLeft_nu", font, CHECK_PORT_AVAIL(m_rp_ObjectStationaryLeft_nu, debugString));
        DrawTextLCF(x_coord_c1, start_y_coord + y_offset_inc* step++, offset, colorWhite, CHECK_IS_CONNECTED(m_rp_ObjectStationaryRight_nu), "FroopToLCF.ObjectStationaryRight_nu", font, CHECK_PORT_AVAIL(m_rp_ObjectStationaryRight_nu, debugString));
        DrawTextLCF(x_coord_c1, start_y_coord + y_offset_inc* step++, offset, colorWhite, CHECK_IS_CONNECTED(m_rp_ObjectSensitiveLeft_nu), "FroopToLCF.ObjectSensitiveLeft_nu", font, CHECK_PORT_AVAIL(m_rp_ObjectSensitiveLeft_nu, debugString));
        DrawTextLCF(x_coord_c1, start_y_coord + y_offset_inc* step++, offset, colorWhite, CHECK_IS_CONNECTED(m_rp_ObjectSensitiveRight_nu), "FroopToLCF.ObjectSensitiveRight_nu", font, CHECK_PORT_AVAIL(m_rp_ObjectSensitiveRight_nu, debugString));
		#endif
	}
}

void CSimLcfVis::Add_Common_Debug_Signals(IGDVFont& font, int start_y_coord, int x_coord_c1, unsigned short offset, unsigned short y_offset_inc, bool ValidData)
{
	char debugString[100];
	unsigned char step = 1;

	if (!m_bDrawHelp)
	{
		if (ValidData) {
			DrawTextLCF(x_coord_c1, start_y_coord, offset, colorWhite, CHECK_IS_CONNECTED(m_rp_S_VDPDRV_VehStInvalid_btf), "S_VDPDRV_VehStInvalid_btf", font, CHECK_PORT_AVAIL(m_rp_S_VDPDRV_VehStInvalid_btf, debugString), 11);
			DrawTextLCF(x_coord_c1, start_y_coord + y_offset_inc* step++, offset, colorWhite, CHECK_IS_CONNECTED(m_rp_S_VDPDRV_ActiveStCtrl_btf), "S_VDPDRV_ActiveStCtrl_btf", font, CHECK_PORT_AVAIL(m_rp_S_VDPDRV_ActiveStCtrl_btf, debugString), 13);
			DrawTextLCF(x_coord_c1, start_y_coord + y_offset_inc* step++, offset, colorWhite, CHECK_IS_CONNECTED(m_rp_S_VDPDRV_DrvStInvalid_btf), "S_VDPDRV_DrvStInvalid_btf", font, CHECK_PORT_AVAIL(m_rp_S_VDPDRV_DrvStInvalid_btf, debugString), 12);
			DrawTextLCF(x_coord_c1, start_y_coord + y_offset_inc* step++, offset, colorWhite, CHECK_IS_CONNECTED(m_rp_S_VDPDRV_SysStError_btf), "S_VDPDRV_SysStError_btf", font, CHECK_PORT_AVAIL(m_rp_S_VDPDRV_SysStError_btf, debugString), 15);
			DrawTextLCF(x_coord_c1, start_y_coord + y_offset_inc* step++, offset, colorWhite, CHECK_IS_CONNECTED(m_rp_S_VDPDRV_SysStNotAvailable_btf), "S_VDPDRV_SysStNotAvailable_btf", font, CHECK_PORT_AVAIL(m_rp_S_VDPDRV_SysStNotAvailable_btf, debugString), 14);
			DrawTextLCF(x_coord_c1, start_y_coord + y_offset_inc* step++, offset, colorWhite, CHECK_IS_CONNECTED(m_rp_S_ABPLBP_LaneWidth_met), "S_ABPLBP_LaneWidth_met", font, CHECK_PORT_AVAIL(m_rp_S_ABPLBP_LaneWidth_met, debugString));
			DrawTextLCF(x_coord_c1, start_y_coord + y_offset_inc* step++, offset, colorWhite, CHECK_IS_CONNECTED(m_rp_S_ABPLBP_LeLnClthPosY0_met), "S_ABPLBP_LeLnClthPosY0_met", font, CHECK_PORT_AVAIL(m_rp_S_ABPLBP_LeLnClthPosY0_met, debugString));
			DrawTextLCF(x_coord_c1, start_y_coord + y_offset_inc* step++, offset, colorWhite, CHECK_IS_CONNECTED(m_rp_S_ABPLBP_LeLnClthPosY0SIF_met), "S_ABPLBP_LeLnClthPosY0SIF_met", font, CHECK_PORT_AVAIL(m_rp_S_ABPLBP_LeLnClthPosY0SIF_met, debugString));
			DrawTextLCF(x_coord_c1, start_y_coord + y_offset_inc* step++, offset, colorWhite, CHECK_IS_CONNECTED(m_rp_S_ABPLBP_RiLnClthPosY0_met), "S_ABPLBP_RiLnClthPosY0_met", font, CHECK_PORT_AVAIL(m_rp_S_ABPLBP_RiLnClthPosY0_met, debugString));
			DrawTextLCF(x_coord_c1, start_y_coord + y_offset_inc* step++, offset, colorWhite, CHECK_IS_CONNECTED(m_rp_S_ABPLBP_RiLnClthPosY0SIF_met), "S_ABPLBP_RiLnClthPosY0SIF_met", font, CHECK_PORT_AVAIL(m_rp_S_ABPLBP_RiLnClthPosY0SIF_met, debugString));
			DrawTextLCF(x_coord_c1, start_y_coord + y_offset_inc* step++, offset, colorWhite, CHECK_IS_CONNECTED(m_rp_S_ABPLBP_LeLnInvalidQu_btf), "S_ABPLBP_LeLnInvalidQu_btf", font, CHECK_PORT_AVAIL(m_rp_S_ABPLBP_LeLnInvalidQu_btf, debugString), 7);
			DrawTextLCF(x_coord_c1, start_y_coord + y_offset_inc* step++, offset, colorWhite, CHECK_IS_CONNECTED(m_rp_S_ABPLBP_RiLnInvalidQu_btf), "S_ABPLBP_RiLnInvalidQu_btf", font, CHECK_PORT_AVAIL(m_rp_S_ABPLBP_RiLnInvalidQu_btf, debugString), 8);
			DrawTextLCF(x_coord_c1, start_y_coord + y_offset_inc* step++, offset, colorWhite, CHECK_IS_CONNECTED(m_rp_S_ABPLBP_ConstructionSite_bool), "S_ABPLBP_ConstructionSite_bool", font, CHECK_PORT_AVAIL(m_rp_S_ABPLBP_ConstructionSite_bool, debugString));
			DrawTextLCF(x_coord_c1, start_y_coord + y_offset_inc* step++, offset, colorWhite, CHECK_IS_CONNECTED(m_rp_S_ABPLBP_CntrLnKalmanStatus_nu), "S_ABPLBP_CntrLnKalmanStatus_nu", font, CHECK_PORT_AVAIL(m_rp_S_ABPLBP_CntrLnKalmanStatus_nu, debugString));
			DrawTextLCF(x_coord_c1, start_y_coord + y_offset_inc* step++, offset, colorWhite, CHECK_IS_CONNECTED(m_rp_S_ABPLBP_LeLnClthLength_met), "S_ABPLBP_LeLnClthLength_met", font, CHECK_PORT_AVAIL(m_rp_S_ABPLBP_LeLnClthLength_met, debugString));
			DrawTextLCF(x_coord_c1, start_y_coord + y_offset_inc* step++, offset, colorWhite, CHECK_IS_CONNECTED(m_rp_S_ABPLBP_RiLnClthLength_met), "S_ABPLBP_RiLnClthLength_met", font, CHECK_PORT_AVAIL(m_rp_S_ABPLBP_RiLnClthLength_met, debugString));
			DrawTextLCF(x_coord_c1, start_y_coord + y_offset_inc* step++, offset, colorWhite, CHECK_IS_CONNECTED(m_rp_S_ABPLBP_LeLnQuality_perc), "S_ABPLBP_LeLnQuality_perc", font, CHECK_PORT_AVAIL(m_rp_S_ABPLBP_LeLnQuality_perc, debugString));
			DrawTextLCF(x_coord_c1, start_y_coord + y_offset_inc* step++, offset, colorWhite, CHECK_IS_CONNECTED(m_rp_S_ABPLBP_RiLnQuality_perc), "S_ABPLBP_RiLnQuality_perc", font, CHECK_PORT_AVAIL(m_rp_S_ABPLBP_RiLnQuality_perc, debugString));
			#ifndef LCF_MFC431VA10
			DrawTextLCF(x_coord_c1, start_y_coord + y_offset_inc* step++, offset, colorWhite, CHECK_IS_CONNECTED(m_rp_S_ABPREP_LeRePosY0_met), "S_ABPREP_LeRePosY0_met", font, CHECK_PORT_AVAIL(m_rp_S_ABPREP_LeRePosY0_met, debugString));
			DrawTextLCF(x_coord_c1, start_y_coord + y_offset_inc* step++, offset, colorWhite, CHECK_IS_CONNECTED(m_rp_S_ABPREP_RiRePosY0_met), "S_ABPREP_RiRePosY0_met", font, CHECK_PORT_AVAIL(m_rp_S_ABPREP_RiRePosY0_met, debugString));
			#endif
			DrawTextLCF(x_coord_c1, start_y_coord + y_offset_inc* step++, offset, colorWhite, CHECK_IS_CONNECTED(m_rp_ControllingFunction_nu), "ControllingFunction_nu", font, CHECK_PORT_AVAIL_MODCTRL(m_rp_ControllingFunction_nu, debugString));
		}
		else {
			for( unsigned char counter = 0; counter < 21; counter++) {
				DrawTextLCF(x_coord_c1, start_y_coord + y_offset_inc* counter, offset, colorRed, colorRed, "No Valid Data in Sen Debug Port", font, "Update LCFVis dll file !");
			}
		}
	}
}

void CSimLcfVis::Add_TJA_Debug_Signals(IGDVFont& font, int start_y_coord, int x_coord_c3, unsigned short offset, unsigned short y_offset_inc, bool ValidData)
{
	char debugString[100];
	unsigned char step = 1;

	if (ValidData) {
		#ifndef LCF_MFC431VA10
		DrawTextLCF(x_coord_c3, start_y_coord, offset, colorWhite, CHECK_IS_CONNECTED(m_rp_S_ODPFOP_AccObjPosX_met), "S_ODPFOP_AccObjPosX_met", font, CHECK_PORT_AVAIL(m_rp_S_ODPFOP_AccObjPosX_met, debugString));
		DrawTextLCF(x_coord_c3, start_y_coord + y_offset_inc* step++, offset, colorWhite, CHECK_IS_CONNECTED(m_rp_S_ODPFOP_AccObjPosY_met), "S_ODPFOP_AccObjPosY_met", font, CHECK_PORT_AVAIL(m_rp_S_ODPFOP_AccObjPosY_met, debugString));
		DrawTextLCF(x_coord_c3, start_y_coord + y_offset_inc* step++, offset, colorWhite, CHECK_IS_CONNECTED(m_rp_S_ODPFOP_AccObjRelAclX_mps2), "S_ODPFOP_AccObjRelAclX_mps2", font, CHECK_PORT_AVAIL(m_rp_S_ODPFOP_AccObjRelAclX_mps2, debugString));
		DrawTextLCF(x_coord_c3, start_y_coord + y_offset_inc* step++, offset, colorWhite, CHECK_IS_CONNECTED(m_rp_S_ODPFOP_AccObjRelAclY_mps2), "S_ODPFOP_AccObjRelAclY_mps2", font, CHECK_PORT_AVAIL(m_rp_S_ODPFOP_AccObjRelAclY_mps2, debugString));
		DrawTextLCF(x_coord_c3, start_y_coord + y_offset_inc* step++, offset, colorWhite, CHECK_IS_CONNECTED(m_rp_S_ODPFOP_AccObjRelVelX_mps), "S_ODPFOP_AccObjRelVelX_mps", font, CHECK_PORT_AVAIL(m_rp_S_ODPFOP_AccObjRelVelX_mps, debugString));
		DrawTextLCF(x_coord_c3, start_y_coord + y_offset_inc* step++, offset, colorWhite, CHECK_IS_CONNECTED(m_rp_S_ODPFOP_AccObjRelVelY_mps), "S_ODPFOP_AccObjRelVelY_mps", font, CHECK_PORT_AVAIL(m_rp_S_ODPFOP_AccObjRelVelY_mps, debugString));
		DrawTextLCF(x_coord_c3, start_y_coord + y_offset_inc* step++, offset, colorWhite, CHECK_IS_CONNECTED(m_rp_S_ODPFOP_EstimatedObjPosX_met), "S_ODPFOP_EstimatedObjPosX_met", font, CHECK_PORT_AVAIL(m_rp_S_ODPFOP_EstimatedObjPosX_met, debugString));
		DrawTextLCF(x_coord_c3, start_y_coord + y_offset_inc* step++, offset, colorWhite, CHECK_IS_CONNECTED(m_rp_S_ODPFOP_EstimatedObjPosY_met), "S_ODPFOP_EstimatedObjPosY_met", font, CHECK_PORT_AVAIL(m_rp_S_ODPFOP_EstimatedObjPosY_met, debugString));
		DrawTextLCF(x_coord_c3, start_y_coord + y_offset_inc* step++, offset, colorWhite, CHECK_IS_CONNECTED(m_rp_S_ODPFOP_AccObjInvBitfield_btf), "S_ODPFOP_AccObjInvBitfield_btf", font, CHECK_PORT_AVAIL(m_rp_S_ODPFOP_AccObjInvBitfield_btf, debugString));
		#endif
		DrawTextLCF(x_coord_c3, start_y_coord + y_offset_inc* step++, offset, colorWhite, CHECK_IS_CONNECTED(m_rp_D_TJALKA_LaneCenterInvalid_btf), "D_TJALKA_LaneCenterInvalid_btf", font, CHECK_PORT_AVAIL(m_rp_D_TJALKA_LaneCenterInvalid_btf, debugString), 5);
		DrawTextLCF(x_coord_c3, start_y_coord + y_offset_inc* step++, offset, colorWhite, CHECK_IS_CONNECTED(m_rp_D_TJALKA_LaneInvalid_btf), "D_TJALKA_LaneInvalid_btf", font, CHECK_PORT_AVAIL(m_rp_D_TJALKA_LaneInvalid_btf, debugString));
		DrawTextLCF(x_coord_c3, start_y_coord + y_offset_inc* step++, offset, colorWhite, CHECK_IS_CONNECTED(m_rp_S_TJALKA_LanePredictValid_bool), "S_TJALKA_LanePredictValid_bool", font, CHECK_PORT_AVAIL(m_rp_S_TJALKA_LanePredictValid_bool, debugString));
		DrawTextLCF(x_coord_c3, start_y_coord + y_offset_inc* step++, offset, colorWhite, CHECK_IS_CONNECTED(m_rp_S_TJALKA_LnBndValid_nu), "S_TJALKA_LnBndValid_nu", font, CHECK_PORT_AVAIL(m_rp_S_TJALKA_LnBndValid_nu, debugString), 23);
		DrawTextLCF(x_coord_c3, start_y_coord + y_offset_inc* step++, offset, colorWhite, CHECK_IS_CONNECTED(m_rp_S_TJALKA_StrongReady_bool), "S_TJALKA_StrongReady_bool", font, CHECK_PORT_AVAIL(m_rp_S_TJALKA_StrongReady_bool, debugString));
		DrawTextLCF(x_coord_c3, start_y_coord + y_offset_inc* step++, offset, colorWhite, CHECK_IS_CONNECTED(m_rp_S_TJALKA_WeakReady_bool), "S_TJALKA_WeakReady_bool", font, CHECK_PORT_AVAIL(m_rp_S_TJALKA_WeakReady_bool, debugString));
		#ifndef LCF_MFC431VA10
		DrawTextLCF(x_coord_c3, start_y_coord + y_offset_inc* step++, offset, colorWhite, CHECK_IS_CONNECTED(m_rp_D_TJAOBF_ObjFollowInvalid_btf), "D_TJAOBF_ObjFollowInvalid_btf", font, CHECK_PORT_AVAIL(m_rp_D_TJAOBF_ObjFollowInvalid_btf, debugString), 6);
		DrawTextLCF(x_coord_c3, start_y_coord + y_offset_inc* step++, offset, colorWhite, CHECK_IS_CONNECTED(m_rp_D_TJAOBF_ObjInLaneInvalid_btf), "D_TJAOBF_ObjInLaneInvalid_btf", font, CHECK_PORT_AVAIL(m_rp_D_TJAOBF_ObjInLaneInvalid_btf, debugString));
		DrawTextLCF(x_coord_c3, start_y_coord + y_offset_inc* step++, offset, colorWhite, CHECK_IS_CONNECTED(m_rp_D_TJAOBF_TgtObjDataInvalid_btf), "D_TJAOBF_TgtObjDataInvalid_btf", font, CHECK_PORT_AVAIL(m_rp_D_TJAOBF_TgtObjDataInvalid_btf, debugString));
		DrawTextLCF(x_coord_c3, start_y_coord + y_offset_inc* step++, offset, colorWhite, CHECK_IS_CONNECTED(m_rp_S_TJAOBF_AccObjValid_bool), "S_TJAOBF_AccObjValid_bool", font, CHECK_PORT_AVAIL(m_rp_S_TJAOBF_AccObjValid_bool, debugString));
		DrawTextLCF(x_coord_c3, start_y_coord + y_offset_inc* step++, offset, colorWhite, CHECK_IS_CONNECTED(m_rp_S_TJAOBF_StrongReady_bool), "S_TJAOBF_StrongReady_bool", font, CHECK_PORT_AVAIL(m_rp_S_TJAOBF_StrongReady_bool, debugString));
		DrawTextLCF(x_coord_c3, start_y_coord + y_offset_inc* step++, offset, colorWhite, CHECK_IS_CONNECTED(m_rp_S_TJAOBF_WeakReady_bool), "S_TJAOBF_WeakReady_bool", font, CHECK_PORT_AVAIL(m_rp_S_TJAOBF_WeakReady_bool, debugString));
		DrawTextLCF(x_coord_c3, start_y_coord + y_offset_inc* step++, offset, colorWhite, CHECK_IS_CONNECTED(m_rp_S_TJACMB_StrongReady_bool), "S_TJACMB_StrongReady_bool", font, CHECK_PORT_AVAIL(m_rp_S_TJACMB_StrongReady_bool, debugString));
		#endif
		DrawTextLCF(x_coord_c3, start_y_coord + y_offset_inc* step++, offset, colorWhite, CHECK_IS_CONNECTED(m_rp_D_TJAGEN_StrongReadyInvalid_btf), "D_TJAGEN_StrongReadyInvalid_btf", font, CHECK_PORT_AVAIL(m_rp_D_TJAGEN_StrongReadyInvalid_btf, debugString), 2);
		DrawTextLCF(x_coord_c3, start_y_coord + y_offset_inc* step++, offset, colorWhite, CHECK_IS_CONNECTED(m_rp_D_TJAGEN_WeakReadyInvalid_btf), "D_TJAGEN_WeakReadyInvalid_btf", font, CHECK_PORT_AVAIL(m_rp_D_TJAGEN_WeakReadyInvalid_btf, debugString), 3);
		DrawTextLCF(x_coord_c3, start_y_coord + y_offset_inc* step++, offset, colorWhite, CHECK_IS_CONNECTED(m_rp_D_TJAGEN_CancelStatus_btf), "D_TJAGEN_CancelStatus_btf", font, CHECK_PORT_AVAIL(m_rp_D_TJAGEN_CancelStatus_btf, debugString), 4);
		DrawTextLCF(x_coord_c3, start_y_coord + y_offset_inc* step++, offset, colorWhite, CHECK_IS_CONNECTED(m_rp_D_TJASTM_TJAInvalid_btf), "D_TJASTM_TJAInvalid_btf", font, CHECK_PORT_AVAIL(m_rp_D_TJASTM_TJAInvalid_btf, debugString), 1);
	}
	else {
		for( unsigned char counter = 0; counter < 21; counter++) {
			DrawTextLCF(x_coord_c3, start_y_coord + y_offset_inc* counter, offset, colorRed, colorRed, "No Valid Data in Sen Debug Port", font, "Update LCFVis dll file !");
		}
	}
}

void CSimLcfVis::Add_LDP_Debug_Signals(IGDVFont& font, int start_y_coord, int x_coord_c3, unsigned short offset, unsigned short y_offset_inc, bool ValidData)
{
	char debugString[100];
	unsigned char step = 1;
	if (ValidData) {
		#ifndef LCF_MFC431VA10
		DrawTextLCF(x_coord_c3, start_y_coord, offset, colorWhite, CHECK_DLC_LEFT(m_rp_S_DPLSIA_DlcLeLDP_met, m_rp_D_DPLSMI_DlcLeThreshold_met), "S_DPLSIA_DlcLeLDP_met", font, CHECK_PORT_AVAIL(m_rp_S_DPLSIA_DlcLeLDP_met, debugString));
		DrawTextLCF(x_coord_c3, start_y_coord + y_offset_inc* step++, offset, colorWhite, CHECK_IS_CONNECTED(m_rp_D_DPLSMI_DlcLeThreshold_met), "D_DPLSMI_DlcLeThreshold_met", font, CHECK_PORT_AVAIL(m_rp_D_DPLSMI_DlcLeThreshold_met, debugString));
		DrawTextLCF(x_coord_c3, start_y_coord + y_offset_inc* step++, offset, colorWhite, CHECK_DLC_RIGHT(m_rp_S_DPLSIA_DlcRiLDP_met, m_rp_D_DPLSMI_DlcRiThreshold_met), "S_DPLSIA_DlcRiLDP_met", font, CHECK_PORT_AVAIL(m_rp_S_DPLSIA_DlcRiLDP_met, debugString));
		DrawTextLCF(x_coord_c3, start_y_coord + y_offset_inc* step++, offset, colorWhite, CHECK_IS_CONNECTED(m_rp_D_DPLSMI_DlcRiThreshold_met), "D_DPLSMI_DlcRiThreshold_met", font, CHECK_PORT_AVAIL(m_rp_D_DPLSMI_DlcRiThreshold_met, debugString));
		DrawTextLCF(x_coord_c3, start_y_coord + y_offset_inc* step++, offset, colorWhite, CHECK_IS_CONNECTED(m_rp_S_DPLSIA_TlcLeLDP_sec), "S_DPLSIA_TlcLeLDP_sec", font, CHECK_PORT_AVAIL(m_rp_S_DPLSIA_TlcLeLDP_sec, debugString));
		DrawTextLCF(x_coord_c3, start_y_coord + y_offset_inc* step++, offset, colorWhite, CHECK_IS_CONNECTED(m_rp_D_DPLSMI_TlcLeThreshold_sec), "D_DPLSMI_TlcLeThreshold_sec", font, CHECK_PORT_AVAIL(m_rp_D_DPLSMI_TlcLeThreshold_sec, debugString));
		DrawTextLCF(x_coord_c3, start_y_coord + y_offset_inc* step++, offset, colorWhite, CHECK_IS_CONNECTED(m_rp_S_DPLSIA_TlcRiLDP_sec), "S_DPLSIA_TlcRiLDP_sec", font, CHECK_PORT_AVAIL(m_rp_S_DPLSIA_TlcRiLDP_sec, debugString));
		DrawTextLCF(x_coord_c3, start_y_coord + y_offset_inc* step++, offset, colorWhite, CHECK_IS_CONNECTED(m_rp_D_DPLSMI_TlcRiThreshold_sec), "D_DPLSMI_TlcRiThreshold_sec", font, CHECK_PORT_AVAIL(m_rp_D_DPLSMI_TlcRiThreshold_sec, debugString));
		DrawTextLCF(x_coord_c3, start_y_coord + y_offset_inc* step++, offset, colorWhite, CHECK_IS_CONNECTED(m_rp_S_DPLSIA_VelLatLeLDP_mps), "S_DPLSIA_VelLatLeLDP_mps", font, CHECK_PORT_AVAIL(m_rp_S_DPLSIA_VelLatLeLDP_mps, debugString));
		DrawTextLCF(x_coord_c3, start_y_coord + y_offset_inc* step++, offset, colorWhite, CHECK_IS_CONNECTED(m_rp_S_DPLSIA_VelLatRiLDP_mps), "S_DPLSIA_VelLatRiLDP_mps", font, CHECK_PORT_AVAIL(m_rp_S_DPLSIA_VelLatRiLDP_mps, debugString));
		DrawTextLCF(x_coord_c3, start_y_coord + y_offset_inc* step++, offset, colorWhite, CHECK_IS_CONNECTED(m_rp_S_DPLSIA_LnBndValidLDP_nu), "S_DPLSIA_LnBndValidLDP_nu", font, CHECK_PORT_AVAIL(m_rp_S_DPLSIA_LnBndValidLDP_nu, debugString), 23);
		DrawTextLCF(x_coord_c3, start_y_coord + y_offset_inc* step++, offset, colorWhite, CHECK_IS_CONNECTED(m_rp_S_DPLSIA_SideCondLDPLe_btf), "S_DPLSIA_SideCondLDPLe_btf", font, CHECK_PORT_AVAIL(m_rp_S_DPLSIA_SideCondLDPLe_btf, debugString), 5);
		DrawTextLCF(x_coord_c3, start_y_coord + y_offset_inc* step++, offset, colorWhite, CHECK_IS_CONNECTED(m_rp_S_DPLSIA_SideCondLDPRi_btf), "S_DPLSIA_SideCondLDPRi_btf", font, CHECK_PORT_AVAIL(m_rp_S_DPLSIA_SideCondLDPRi_btf, debugString), 6);
		DrawTextLCF(x_coord_c3, start_y_coord + y_offset_inc* step++, offset, colorWhite, CHECK_IS_CONNECTED(m_rp_S_DPLSIA_SpecificLDP_btf), "S_DPLSIA_SpecificLDP_btf", font, CHECK_PORT_AVAIL(m_rp_S_DPLSIA_SpecificLDP_btf, debugString), 9);
		DrawTextLCF(x_coord_c3, start_y_coord + y_offset_inc* step++, offset, colorWhite, CHECK_IS_CONNECTED(m_rp_D_DPLSMI_Cancel_btf), "D_DPLSMI_Cancel_btf", font, CHECK_PORT_AVAIL(m_rp_D_DPLSMI_Cancel_btf, debugString), 4);
		DrawTextLCF(x_coord_c3, start_y_coord + y_offset_inc* step++, offset, colorWhite, CHECK_IS_CONNECTED(m_rp_D_DPLSMI_StrongReady_btf), "D_DPLSMI_StrongReady_btf", font, CHECK_PORT_AVAIL(m_rp_D_DPLSMI_StrongReady_btf, debugString), 2);
		DrawTextLCF(x_coord_c3, start_y_coord + y_offset_inc* step++, offset, colorWhite, CHECK_IS_CONNECTED(m_rp_D_DPLSMI_SysStateLDP_btf), "D_DPLSMI_SysStateLDP_btf", font, CHECK_PORT_AVAIL(m_rp_D_DPLSMI_SysStateLDP_btf, debugString), 1);
		DrawTextLCF(x_coord_c3, start_y_coord + y_offset_inc* step++, offset, colorWhite, CHECK_IS_CONNECTED(m_rp_D_DPLSMI_WeakReady_btf), "D_DPLSMI_WeakReady_btf", font, CHECK_PORT_AVAIL(m_rp_D_DPLSMI_WeakReady_btf, debugString), 3);
		DrawTextLCF(x_coord_c3, start_y_coord + y_offset_inc* step++, offset, colorWhite, CHECK_IS_CONNECTED(m_rp_S_DPLSMI_DangerousSide_nu), "S_DPLSMI_DangerousSide_nu", font, CHECK_PORT_AVAIL(m_rp_S_DPLSMI_DangerousSide_nu, debugString), 31);
		DrawTextLCF(x_coord_c3, start_y_coord + y_offset_inc* step++, offset, colorWhite, CHECK_IS_CONNECTED(m_rp_S_DPLSMI_ReadyToTrigger_bool), "S_DPLSMI_ReadyToTrigger_bool", font, CHECK_PORT_AVAIL(m_rp_S_DPLSMI_ReadyToTrigger_bool, debugString));
		#endif
	}
	else {
		for( unsigned char counter = 0; counter < 21; counter++) {
			DrawTextLCF(x_coord_c3, start_y_coord + y_offset_inc* counter, offset, colorRed, colorRed, "No Valid Data in Sen Debug Port", font, "Update LCFVis dll file !");
		}
	}
}

void CSimLcfVis::Add_LDW_Debug_Signals(IGDVFont& font, int start_y_coord, int x_coord_c3, unsigned short offset, unsigned short y_offset_inc, bool ValidData)
{
	char debugString[100];
	unsigned char step = 1;

	if (ValidData) {
		DrawTextLCF(x_coord_c3, start_y_coord, offset, colorWhite, CHECK_DLC_LEFT(m_rp_S_DPLSIA_DlcLeLDW_met, m_rp_D_DPLSMW_DlcLeThreshold_met), "S_DPLSIA_DlcLeLDW_met", font, CHECK_PORT_AVAIL(m_rp_S_DPLSIA_DlcLeLDW_met, debugString));
		DrawTextLCF(x_coord_c3, start_y_coord + y_offset_inc* step++, offset, colorWhite, CHECK_IS_CONNECTED(m_rp_D_DPLSMW_DlcLeThreshold_met), "D_DPLSMW_DlcLeThreshold_met", font, CHECK_PORT_AVAIL(m_rp_D_DPLSMW_DlcLeThreshold_met, debugString));
		DrawTextLCF(x_coord_c3, start_y_coord + y_offset_inc* step++, offset, colorWhite, CHECK_DLC_RIGHT(m_rp_S_DPLSIA_DlcRiLDW_met, m_rp_D_DPLSMW_DlcRiThreshold_met), "S_DPLSIA_DlcRiLDW_met", font, CHECK_PORT_AVAIL(m_rp_S_DPLSIA_DlcRiLDW_met, debugString));
		DrawTextLCF(x_coord_c3, start_y_coord + y_offset_inc* step++, offset, colorWhite, CHECK_IS_CONNECTED(m_rp_D_DPLSMW_DlcRiThreshold_met), "D_DPLSMW_DlcRiThreshold_met", font, CHECK_PORT_AVAIL(m_rp_D_DPLSMW_DlcRiThreshold_met, debugString));
		DrawTextLCF(x_coord_c3, start_y_coord + y_offset_inc* step++, offset, colorWhite, CHECK_IS_CONNECTED(m_rp_S_DPLSIA_TlcLeLDW_sec), "S_DPLSIA_TlcLeLDW_sec", font, CHECK_PORT_AVAIL(m_rp_S_DPLSIA_TlcLeLDW_sec, debugString));
		DrawTextLCF(x_coord_c3, start_y_coord + y_offset_inc* step++, offset, colorWhite, CHECK_IS_CONNECTED(m_rp_D_DPLSMW_TlcLeThreshold_sec), "D_DPLSMW_TlcLeThreshold_sec", font, CHECK_PORT_AVAIL(m_rp_D_DPLSMW_TlcLeThreshold_sec, debugString));
		DrawTextLCF(x_coord_c3, start_y_coord + y_offset_inc* step++, offset, colorWhite, CHECK_IS_CONNECTED(m_rp_S_DPLSIA_TlcRiLDW_sec), "S_DPLSIA_TlcRiLDW_sec", font, CHECK_PORT_AVAIL(m_rp_S_DPLSIA_TlcRiLDW_sec, debugString));
		DrawTextLCF(x_coord_c3, start_y_coord + y_offset_inc* step++, offset, colorWhite, CHECK_IS_CONNECTED(m_rp_D_DPLSMW_TlcRiThreshold_sec), "D_DPLSMW_TlcRiThreshold_sec", font, CHECK_PORT_AVAIL(m_rp_D_DPLSMW_TlcRiThreshold_sec, debugString));
		DrawTextLCF(x_coord_c3, start_y_coord + y_offset_inc* step++, offset, colorWhite, CHECK_IS_CONNECTED(m_rp_S_DPLSIA_VelLatLeLDW_mps), "S_DPLSIA_VelLatLeLDW_mps", font, CHECK_PORT_AVAIL(m_rp_S_DPLSIA_VelLatLeLDW_mps, debugString));
		DrawTextLCF(x_coord_c3, start_y_coord + y_offset_inc* step++, offset, colorWhite, CHECK_IS_CONNECTED(m_rp_S_DPLSIA_VelLatRiLDW_mps), "S_DPLSIA_VelLatRiLDW_mps", font, CHECK_PORT_AVAIL(m_rp_S_DPLSIA_VelLatRiLDW_mps, debugString));
		DrawTextLCF(x_coord_c3, start_y_coord + y_offset_inc* step++, offset, colorWhite, CHECK_IS_CONNECTED(m_rp_S_DPLSIA_LnBndValidLDW_nu), "S_DPLSIA_LnBndValidLDW_nu", font, CHECK_PORT_AVAIL(m_rp_S_DPLSIA_LnBndValidLDW_nu, debugString), 23);
		DrawTextLCF(x_coord_c3, start_y_coord + y_offset_inc* step++, offset, colorWhite, CHECK_IS_CONNECTED(m_rp_S_DPLSIA_SideCondLDWLe_btf), "S_DPLSIA_SideCondLDWLe_btf", font, CHECK_PORT_AVAIL(m_rp_S_DPLSIA_SideCondLDWLe_btf, debugString), 5);
		DrawTextLCF(x_coord_c3, start_y_coord + y_offset_inc* step++, offset, colorWhite, CHECK_IS_CONNECTED(m_rp_S_DPLSIA_SideCondLDWRi_btf), "S_DPLSIA_SideCondLDWRi_btf", font, CHECK_PORT_AVAIL(m_rp_S_DPLSIA_SideCondLDWRi_btf, debugString), 6);
		DrawTextLCF(x_coord_c3, start_y_coord + y_offset_inc* step++, offset, colorWhite, CHECK_IS_CONNECTED(m_rp_S_DPLSIA_SpecificLDW_btf), "S_DPLSIA_SpecificLDW_btf", font, CHECK_PORT_AVAIL(m_rp_S_DPLSIA_SpecificLDW_btf, debugString), 9);
		DrawTextLCF(x_coord_c3, start_y_coord + y_offset_inc* step++, offset, colorWhite, CHECK_IS_CONNECTED(m_rp_D_DPLSMW_Cancel_btf), "D_DPLSMW_Cancel_btf", font, CHECK_PORT_AVAIL(m_rp_D_DPLSMW_Cancel_btf, debugString), 4);
		DrawTextLCF(x_coord_c3, start_y_coord + y_offset_inc* step++, offset, colorWhite, CHECK_IS_CONNECTED(m_rp_D_DPLSMW_StrongReady_btf), "D_DPLSMW_StrongReady_btf", font, CHECK_PORT_AVAIL(m_rp_D_DPLSMW_StrongReady_btf, debugString), 2);
		DrawTextLCF(x_coord_c3, start_y_coord + y_offset_inc* step++, offset, colorWhite, CHECK_IS_CONNECTED(m_rp_D_DPLSMW_SysStateLDW_btf), "D_DPLSMW_SysStateLDW_btf", font, CHECK_PORT_AVAIL(m_rp_D_DPLSMW_SysStateLDW_btf, debugString), 1);
		DrawTextLCF(x_coord_c3, start_y_coord + y_offset_inc* step++, offset, colorWhite, CHECK_IS_CONNECTED(m_rp_D_DPLSMW_WeakReady_btf), "D_DPLSMW_WeakReady_btf", font, CHECK_PORT_AVAIL(m_rp_D_DPLSMW_WeakReady_btf, debugString), 3);
		DrawTextLCF(x_coord_c3, start_y_coord + y_offset_inc* step++, offset, colorWhite, CHECK_IS_CONNECTED(m_rp_S_DPLSMW_DangerousSide_nu), "S_DPLSMW_DangerousSide_nu", font, CHECK_PORT_AVAIL(m_rp_S_DPLSMW_DangerousSide_nu, debugString), 31);
		DrawTextLCF(x_coord_c3, start_y_coord + y_offset_inc* step++, offset, colorWhite, CHECK_IS_CONNECTED(m_rp_S_DPLSMW_ReadyToTrigger_bool), "S_DPLSMW_ReadyToTrigger_bool", font, CHECK_PORT_AVAIL(m_rp_S_DPLSMW_ReadyToTrigger_bool, debugString));
	}
	else {
		for( unsigned char counter = 0; counter < 21; counter++) {
			DrawTextLCF(x_coord_c3, start_y_coord + y_offset_inc* counter, offset, colorRed, colorRed, "No Valid Data in Sen Debug Port", font, "Update LCFVis dll file !");
		}
	}
}

void CSimLcfVis::Add_RDP_Debug_Signals(IGDVFont& font, int start_y_coord, int x_coord_c3, unsigned short offset, unsigned short y_offset_inc, bool ValidData)
{
	char debugString[100];
	unsigned char step = 1;
	
	if (ValidData)
	{
		#ifndef LCF_MFC431VA10
		DrawTextLCF(x_coord_c3, start_y_coord, offset, colorWhite, CHECK_IS_CONNECTED(m_rp_S_ABPREP_LeReInvalidQu_btf), "S_ABPREP_LeReInvalidQu_btf", font, CHECK_PORT_AVAIL(m_rp_S_ABPREP_LeReInvalidQu_btf, debugString), 16);
		DrawTextLCF(x_coord_c3, start_y_coord + y_offset_inc* step++, offset, colorWhite, CHECK_IS_CONNECTED(m_rp_S_ABPREP_RiReInvalidQu_btf), "S_ABPREP_RiReInvalidQu_btf", font, CHECK_PORT_AVAIL(m_rp_S_ABPREP_RiReInvalidQu_btf, debugString), 17);
		DrawTextLCF(x_coord_c3, start_y_coord + y_offset_inc* step++, offset, colorWhite, CHECK_DLC_LEFT(m_rp_S_DPRSIA_DrcLeRDP_met, m_rp_D_DPRSMI_DrcLeThreshold_met), "S_DPRSIA_DrcLeRDP_met", font, CHECK_PORT_AVAIL(m_rp_S_DPRSIA_DrcLeRDP_met, debugString));
		DrawTextLCF(x_coord_c3, start_y_coord + y_offset_inc* step++, offset, colorWhite, CHECK_IS_CONNECTED(m_rp_D_DPRSMI_DrcLeThreshold_met), "D_DPRSMI_DrcLeThreshold_met", font, CHECK_PORT_AVAIL(m_rp_D_DPRSMI_DrcLeThreshold_met, debugString));
		DrawTextLCF(x_coord_c3, start_y_coord + y_offset_inc* step++, offset, colorWhite, CHECK_DLC_RIGHT(m_rp_S_DPRSIA_DrcRiRDP_met, m_rp_D_DPRSMI_DrcRiThreshold_met), "S_DPRSIA_DrcRiRDP_met", font, CHECK_PORT_AVAIL(m_rp_S_DPRSIA_DrcRiRDP_met, debugString));
		DrawTextLCF(x_coord_c3, start_y_coord + y_offset_inc* step++, offset, colorWhite, CHECK_IS_CONNECTED(m_rp_D_DPRSMI_DrcRiThreshold_met), "D_DPRSMI_DrcRiThreshold_met", font, CHECK_PORT_AVAIL(m_rp_D_DPRSMI_DrcRiThreshold_met, debugString));
		DrawTextLCF(x_coord_c3, start_y_coord + y_offset_inc* step++, offset, colorWhite, CHECK_DLC_LEFT(m_rp_S_DPRSIA_DlcLeRDP_met, m_rp_D_DPRSMI_DlcLeThreshold_met), "S_DPRSIA_DlcLeRDP_met", font, CHECK_PORT_AVAIL(m_rp_S_DPRSIA_DlcLeRDP_met, debugString));
		DrawTextLCF(x_coord_c3, start_y_coord + y_offset_inc* step++, offset, colorWhite, CHECK_IS_CONNECTED(m_rp_D_DPRSMI_DlcLeThreshold_met), "D_DPRSMI_DlcLeThreshold_met", font, CHECK_PORT_AVAIL(m_rp_D_DPRSMI_DlcLeThreshold_met, debugString));
		DrawTextLCF(x_coord_c3, start_y_coord + y_offset_inc* step++, offset, colorWhite, CHECK_DLC_RIGHT(m_rp_S_DPRSIA_DlcRiRDP_met, m_rp_D_DPRSMI_DlcRiThreshold_met), "S_DPRSIA_DlcRiRDP_met", font, CHECK_PORT_AVAIL(m_rp_S_DPRSIA_DlcRiRDP_met, debugString));
		DrawTextLCF(x_coord_c3, start_y_coord + y_offset_inc* step++, offset, colorWhite, CHECK_IS_CONNECTED(m_rp_D_DPRSMI_DlcRiThreshold_met), "D_DPRSMI_DlcRiThreshold_met", font, CHECK_PORT_AVAIL(m_rp_D_DPRSMI_DlcRiThreshold_met, debugString));
		DrawTextLCF(x_coord_c3, start_y_coord + y_offset_inc* step++, offset, colorWhite, CHECK_IS_CONNECTED(m_rp_S_DPRSIA_VelLatReLeRDP_mps), "S_DPRSIA_VelLatReLeRDP_mps", font, CHECK_PORT_AVAIL(m_rp_S_DPRSIA_VelLatReLeRDP_mps, debugString));
		DrawTextLCF(x_coord_c3, start_y_coord + y_offset_inc* step++, offset, colorWhite, CHECK_IS_CONNECTED(m_rp_S_DPRSIA_VelLatReRiRDP_mps), "S_DPRSIA_VelLatReRiRDP_mps", font, CHECK_PORT_AVAIL(m_rp_S_DPRSIA_VelLatReRiRDP_mps, debugString));
		DrawTextLCF(x_coord_c3, start_y_coord + y_offset_inc* step++, offset, colorWhite, CHECK_IS_CONNECTED(m_rp_S_DPRSIA_TgtCntrLnEnable_bool), "S_DPRSIA_TgtCntrLnEnable_bool", font, CHECK_PORT_AVAIL(m_rp_S_DPRSIA_TgtCntrLnEnable_bool, debugString));
		DrawTextLCF(x_coord_c3, start_y_coord + y_offset_inc* step++, offset, colorWhite, CHECK_IS_CONNECTED(m_rp_S_DPRSIA_LaneWidthRDP_met), "S_DPRSIA_LaneWidthRDP_met", font, CHECK_PORT_AVAIL(m_rp_S_DPRSIA_LaneWidthRDP_met, debugString));
		DrawTextLCF(x_coord_c3, start_y_coord + y_offset_inc* step++, offset, colorWhite, CHECK_IS_CONNECTED(m_rp_S_DPRSIA_LnBndValidRDP_nu), "S_DPRSIA_LnBndValidRDP_nu", font, CHECK_PORT_AVAIL(m_rp_S_DPRSIA_LnBndValidRDP_nu, debugString), 23);
		DrawTextLCF(x_coord_c3, start_y_coord + y_offset_inc* step++, offset, colorWhite, CHECK_IS_CONNECTED(m_rp_S_DPRSIA_RdBndValidRDP_nu), "S_DPRSIA_RdBndValidRDP_nu", font, CHECK_PORT_AVAIL(m_rp_S_DPRSIA_RdBndValidRDP_nu, debugString), 23);
		DrawTextLCF(x_coord_c3, start_y_coord + y_offset_inc* step++, offset, colorWhite, CHECK_IS_CONNECTED(m_rp_S_DPRSIA_SideCondRDPLe_btf), "S_DPRSIA_SideCondRDPLe_btf", font, CHECK_PORT_AVAIL(m_rp_S_DPRSIA_SideCondRDPLe_btf, debugString), 5);
		DrawTextLCF(x_coord_c3, start_y_coord + y_offset_inc* step++, offset, colorWhite, CHECK_IS_CONNECTED(m_rp_S_DPRSIA_SideCondRDPRi_btf), "S_DPRSIA_SideCondRDPRi_btf", font, CHECK_PORT_AVAIL(m_rp_S_DPRSIA_SideCondRDPRi_btf, debugString), 6);
		DrawTextLCF(x_coord_c3, start_y_coord + y_offset_inc* step++, offset, colorWhite, CHECK_IS_CONNECTED(m_rp_S_DPRSIA_SpecificRDP_btf), "S_DPRSIA_SpecificRDP_btf", font, CHECK_PORT_AVAIL(m_rp_S_DPRSIA_SpecificRDP_btf, debugString), 9);
		DrawTextLCF(x_coord_c3, start_y_coord + y_offset_inc* step++, offset, colorWhite, CHECK_IS_CONNECTED(m_rp_D_DPRSMI_Cancel_btf), "D_DPRSMI_Cancel_btf", font, CHECK_PORT_AVAIL(m_rp_D_DPRSMI_Cancel_btf, debugString), 4);
		DrawTextLCF(x_coord_c3, start_y_coord + y_offset_inc* step++, offset, colorWhite, CHECK_IS_CONNECTED(m_rp_D_DPRSMI_StrongReady_btf), "D_DPRSMI_StrongReady_btf", font, CHECK_PORT_AVAIL(m_rp_D_DPRSMI_StrongReady_btf, debugString), 2);
		DrawTextLCF(x_coord_c3, start_y_coord + y_offset_inc* step++, offset, colorWhite, CHECK_IS_CONNECTED(m_rp_D_DPRSMI_SysStateRDP_btf), "D_DPRSMI_SysStateRDP_btf", font, CHECK_PORT_AVAIL(m_rp_D_DPRSMI_SysStateRDP_btf, debugString), 1);
		DrawTextLCF(x_coord_c3, start_y_coord + y_offset_inc* step++, offset, colorWhite, CHECK_IS_CONNECTED(m_rp_D_DPRSMI_WeakReady_btf), "D_DPRSMI_WeakReady_btf", font, CHECK_PORT_AVAIL(m_rp_D_DPRSMI_WeakReady_btf, debugString), 3);
		DrawTextLCF(x_coord_c3, start_y_coord + y_offset_inc* step++, offset, colorWhite, CHECK_IS_CONNECTED(m_rp_S_DPRSMI_DangerousSide_nu), "S_DPRSMI_DangerousSide_nu", font, CHECK_PORT_AVAIL(m_rp_S_DPRSMI_DangerousSide_nu, debugString), 31);
		DrawTextLCF(x_coord_c3, start_y_coord + y_offset_inc* step++, offset, colorWhite, CHECK_IS_CONNECTED(m_rp_S_DPRSMI_TriggerReason_nu), "S_DPRSMI_TriggerReason_nu", font, CHECK_PORT_AVAIL(m_rp_S_DPRSMI_TriggerReason_nu, debugString));
		DrawTextLCF(x_coord_c3, start_y_coord + y_offset_inc* step++, offset, colorWhite, CHECK_IS_CONNECTED(m_rp_S_DPRSMI_ReadyToTrigger_bool), "S_DPRSMI_ReadyToTrigger_bool", font, CHECK_PORT_AVAIL(m_rp_S_DPRSMI_ReadyToTrigger_bool, debugString));
		#endif
	}
	else
	{
		for( unsigned char counter = 0; counter < 21; counter++) {
			DrawTextLCF(x_coord_c3, start_y_coord + y_offset_inc* counter, offset, colorRed, colorRed, "No Valid Data in Sen Debug Port", font, "Update LCFVis dll file !");
		}
	}
}

void CSimLcfVis::Add_Customer_Signals(IGDVFont& font, int start_y_coord, int x_coord_c3, unsigned short offset, unsigned short y_offset_inc, bool ValidData)
{
	char debugString[100];
	unsigned char step = 1;

	if (ValidData)
	{
		#if (GET_LCF_PRJ_NR() == GET_LCFPRJ_MFC431LO19())
		DrawTextLCF(x_coord_c3, start_y_coord, offset, colorWhite, CHECK_IS_CONNECTED(m_rp_D_LSCCTR_PreconditionsOK_btf), "D_LSCCTR_PreconditionsOK_btf", font, CHECK_PORT_AVAIL(m_rp_D_LSCCTR_PreconditionsOK_btf, debugString), 1);
		DrawTextLCF(x_coord_c3, start_y_coord + y_offset_inc* step++, offset, colorWhite, CHECK_IS_CONNECTED(m_rp_D_LSCCTR_PrjSpecQu_btf), "D_LSCCTR_PrjSpecQu_btf", font, CHECK_PORT_AVAIL(m_rp_D_LSCCTR_PrjSpecQu_btf, debugString), 2);
		DrawTextLCF(x_coord_c3, start_y_coord + y_offset_inc* step++, offset, colorWhite, CHECK_IS_CONNECTED(m_rp_D_HMOLCO_SysStateHWA_btf), "D_HMOLCO_SysStateHWA_btf", font, CHECK_PORT_AVAIL(m_rp_D_HMOLCO_SysStateHWA_btf, debugString), 3);
		DrawTextLCF(x_coord_c3, start_y_coord + y_offset_inc* step++, offset, colorWhite, CHECK_IS_CONNECTED(m_rp_S_HMOLCO_ActFctEnabled_bool), "S_HMOLCO_ActFctEnabled_bool", font, CHECK_PORT_AVAIL(m_rp_S_HMOLCO_ActFctEnabled_bool, debugString));
		DrawTextLCF(x_coord_c3, start_y_coord + y_offset_inc* step++, offset, colorWhite, CHECK_IS_CONNECTED(m_rp_S_HMOLCO_ActFctLevel_nu), "S_HMOLCO_ActFctLevel_nu", font, CHECK_PORT_AVAIL(m_rp_S_HMOLCO_ActFctLevel_nu, debugString));
		DrawTextLCF(x_coord_c3, start_y_coord + y_offset_inc* step++, offset, colorWhite, CHECK_IS_CONNECTED(m_rp_S_HMOLCO_CnclReqForCrsCtrl_nu), "S_HMOLCO_CnclReqForCrsCtrl_nu", font, CHECK_PORT_AVAIL(m_rp_S_HMOLCO_CnclReqForCrsCtrl_nu, debugString));
		DrawTextLCF(x_coord_c3, start_y_coord + y_offset_inc* step++, offset, colorWhite, CHECK_IS_CONNECTED(m_rp_S_HMOLCO_HWAStatus_nu), "S_HMOLCO_HWAStatus_nu", font, CHECK_PORT_AVAIL(m_rp_S_HMOLCO_HWAStatus_nu, debugString));
		DrawTextLCF(x_coord_c3, start_y_coord + y_offset_inc* step++, offset, colorWhite, CHECK_IS_CONNECTED(m_rp_S_HMOLCO_HapticWrnReq_nu), "S_HMOLCO_HapticWrnReq_nu", font, CHECK_PORT_AVAIL(m_rp_S_HMOLCO_HapticWrnReq_nu, debugString));
		DrawTextLCF(x_coord_c3, start_y_coord + y_offset_inc* step++, offset, colorWhite, CHECK_IS_CONNECTED(m_rp_S_HMOLCO_LDWState_nu), "S_HMOLCO_LDWState_nu", font, CHECK_PORT_AVAIL(m_rp_S_HMOLCO_LDWState_nu, debugString));
		DrawTextLCF(x_coord_c3, start_y_coord + y_offset_inc* step++, offset, colorWhite, CHECK_IS_CONNECTED(m_rp_S_HMOLCO_LKAState_nu), "S_HMOLCO_LKAState_nu", font, CHECK_PORT_AVAIL(m_rp_S_HMOLCO_LKAState_nu, debugString));
		DrawTextLCF(x_coord_c3, start_y_coord + y_offset_inc* step++, offset, colorWhite, CHECK_IS_CONNECTED(m_rp_S_HMOLCO_LaneDetectionStatusForHWA_nu), "S_HMOLCO_LaneDetectionStatusForHWA", font, CHECK_PORT_AVAIL(m_rp_S_HMOLCO_LaneDetectionStatusForHWA_nu, debugString));
		DrawTextLCF(x_coord_c3, start_y_coord + y_offset_inc* step++, offset, colorWhite, CHECK_IS_CONNECTED(m_rp_S_HMOLCO_LaneDetectionStatus_nu), "S_HMOLCO_LaneDetectionStatus_nu", font, CHECK_PORT_AVAIL(m_rp_S_HMOLCO_LaneDetectionStatus_nu, debugString));
		DrawTextLCF(x_coord_c3, start_y_coord + y_offset_inc* step++, offset, colorWhite, CHECK_IS_CONNECTED(m_rp_S_HMOLCO_SteerActiveOK_bool), "S_HMOLCO_SteerActiveOK_bool", font, CHECK_PORT_AVAIL(m_rp_S_HMOLCO_SteerActiveOK_bool, debugString));
		DrawTextLCF(x_coord_c3, start_y_coord + y_offset_inc* step++, offset, colorWhite, CHECK_IS_CONNECTED(m_rp_S_HMOLCO_SteerStandbyOK_bool), "S_HMOLCO_SteerStandbyOK_bool", font, CHECK_PORT_AVAIL(m_rp_S_HMOLCO_SteerStandbyOK_bool, debugString));
		DrawTextLCF(x_coord_c3, start_y_coord + y_offset_inc* step++, offset, colorWhite, CHECK_IS_CONNECTED(m_rp_S_HMOLCO_StsForLatAutDrv_nu), "S_HMOLCO_StsForLatAutDrv_nu", font, CHECK_PORT_AVAIL(m_rp_S_HMOLCO_StsForLatAutDrv_nu, debugString));
		DrawTextLCF(x_coord_c3, start_y_coord + y_offset_inc* step++, offset, colorWhite, CHECK_IS_CONNECTED(m_rp_S_HMOLCO_SysWarning_nu), "S_HMOLCO_SysWarning_nu", font, CHECK_PORT_AVAIL(m_rp_S_HMOLCO_SysWarning_nu, debugString));
		DrawTextLCF(x_coord_c3, start_y_coord + y_offset_inc* step++, offset, colorWhite, CHECK_IS_CONNECTED(m_rp_S_HMOLCO_WarnForLatAutDrv_nu), "S_HMOLCO_WarnForLatAutDrv_nu", font, CHECK_PORT_AVAIL(m_rp_S_HMOLCO_WarnForLatAutDrv_nu, debugString));
		DrawTextLCF(x_coord_c3, start_y_coord + y_offset_inc* step++, offset, colorWhite, CHECK_IS_CONNECTED(m_rp_S_HMOLCO_WarnReqHWA_nu), "S_HMOLCO_WarnReqHWA_nu", font, CHECK_PORT_AVAIL(m_rp_S_HMOLCO_WarnReqHWA_nu, debugString));
		DrawTextLCF(x_coord_c3, start_y_coord + y_offset_inc* step++, offset, colorWhite, CHECK_IS_CONNECTED(m_rp_S_HMOLCO_eLKAState_nu), "S_HMOLCO_eLKAState_nu", font, CHECK_PORT_AVAIL(m_rp_S_HMOLCO_eLKAState_nu, debugString));
		#elif (GET_LCF_PRJ_NR() == GET_LCFPRJ_MFC431TA19())
		DrawTextLCF(x_coord_c3, start_y_coord, offset, colorWhite, CHECK_IS_CONNECTED(m_rp_S_TSCCTR_PrjSpecQu_btf), "S_TSCCTR_PrjSpecQu_btf", font, CHECK_PORT_AVAIL(m_rp_S_TSCCTR_PrjSpecQu_btf, debugString), 1);
		DrawTextLCF(x_coord_c3, start_y_coord + y_offset_inc* step++, offset, colorWhite, CHECK_IS_CONNECTED(m_rp_S_TSCLDA_PrjSpecQu_btf), "S_TSCLDA_PrjSpecQu_btf", font, CHECK_PORT_AVAIL(m_rp_S_TSCLDA_PrjSpecQu_btf, debugString), 2);
		DrawTextLCF(x_coord_c3, start_y_coord + y_offset_inc* step++, offset, colorWhite, CHECK_IS_CONNECTED(m_rp_S_TSCLTA_PrjSpecQu_btf), "S_TSCLTA_PrjSpecQu_btf", font, CHECK_PORT_AVAIL(m_rp_S_TSCLTA_PrjSpecQu_btf, debugString), 3);
		DrawTextLCF(x_coord_c3, start_y_coord + y_offset_inc* step++, offset, colorWhite, CHECK_IS_CONNECTED(m_rp_D_TSCLTA_HmiCancelWarningQu_btf), "D_TSCLTA_HmiCancelWarningQu_btf", font, CHECK_PORT_AVAIL(m_rp_D_TSCLTA_HmiCancelWarningQu_btf, debugString), 4);
		DrawTextLCF(x_coord_c3, start_y_coord + y_offset_inc* step++, offset, colorWhite, CHECK_IS_CONNECTED(m_rp_S_TSCLTA_HmiCancelWarningQu_nu), "S_TSCLTA_HmiCancelWarningQu_nu", font, CHECK_PORT_AVAIL(m_rp_S_TSCLTA_HmiCancelWarningQu_nu, debugString));
		DrawTextLCF(x_coord_c3, start_y_coord + y_offset_inc* step++, offset, colorWhite, CHECK_IS_CONNECTED(m_rp_S_TSCLTA_LDAIndiOffReq_bool), "S_TSCLTA_LDAIndiOffReq_bool", font, CHECK_PORT_AVAIL(m_rp_S_TSCLTA_LDAIndiOffReq_bool, debugString));
		DrawTextLCF(x_coord_c3, start_y_coord + y_offset_inc* step++, offset, colorWhite, CHECK_IS_CONNECTED(m_rp_S_TSCLTA_SysGainDec_bool), "S_TSCLTA_SysGainDec_bool", font, CHECK_PORT_AVAIL(m_rp_S_TSCLTA_SysGainDec_bool, debugString));
		DrawTextLCF(x_coord_c3, start_y_coord + y_offset_inc* step++, offset, colorWhite, CHECK_IS_CONNECTED(m_rp_D_TSCLDA_LDPMode2DispVel_kph), "D_TSCLDA_LDPMode2DispVel_kph", font, CHECK_PORT_AVAIL(m_rp_D_TSCLDA_LDPMode2DispVel_kph, debugString));
		DrawTextLCF(x_coord_c3, start_y_coord + y_offset_inc* step++, offset, colorWhite, CHECK_IS_CONNECTED(m_rp_D_TSCLDA_ObjLeDetect_bool), "D_TSCLDA_ObjLeDetect_bool", font, CHECK_PORT_AVAIL(m_rp_D_TSCLDA_ObjLeDetect_bool, debugString));
		DrawTextLCF(x_coord_c3, start_y_coord + y_offset_inc* step++, offset, colorWhite, CHECK_IS_CONNECTED(m_rp_D_TSCLDA_ObjRiDetect_bool), "D_TSCLDA_ObjRiDetect_bool", font, CHECK_PORT_AVAIL(m_rp_D_TSCLDA_ObjRiDetect_bool, debugString));
		DrawTextLCF(x_coord_c3, start_y_coord + y_offset_inc* step++, offset, colorWhite, CHECK_IS_CONNECTED(m_rp_D_TSCLDA_OneSideLnReDtct_bool), "D_TSCLDA_OneSideLnReDtct_bool", font, CHECK_PORT_AVAIL(m_rp_D_TSCLDA_OneSideLnReDtct_bool, debugString));
		DrawTextLCF(x_coord_c3, start_y_coord + y_offset_inc* step++, offset, colorWhite, CHECK_IS_CONNECTED(m_rp_D_TSCLDA_Precondition_bool), "D_TSCLDA_Precondition_bool", font, CHECK_PORT_AVAIL(m_rp_D_TSCLDA_Precondition_bool, debugString));
		DrawTextLCF(x_coord_c3, start_y_coord + y_offset_inc* step++, offset, colorWhite, CHECK_IS_CONNECTED(m_rp_D_TSCLDA_RoadWidth_met), "D_TSCLDA_RoadWidth_met", font, CHECK_PORT_AVAIL(m_rp_D_TSCLDA_RoadWidth_met, debugString));
		DrawTextLCF(x_coord_c3, start_y_coord + y_offset_inc* step++, offset, colorWhite, CHECK_IS_CONNECTED(m_rp_D_TSCLDA_TMCCurvGLeLn_mps2), "D_TSCLDA_TMCCurvGLeLn_mps2", font, CHECK_PORT_AVAIL(m_rp_D_TSCLDA_TMCCurvGLeLn_mps2, debugString));
		DrawTextLCF(x_coord_c3, start_y_coord + y_offset_inc* step++, offset, colorWhite, CHECK_IS_CONNECTED(m_rp_D_TSCLDA_TMCCurvGLeRe_mps2), "D_TSCLDA_TMCCurvGLeRe_mps2", font, CHECK_PORT_AVAIL(m_rp_D_TSCLDA_TMCCurvGLeRe_mps2, debugString));
		DrawTextLCF(x_coord_c3, start_y_coord + y_offset_inc* step++, offset, colorWhite, CHECK_IS_CONNECTED(m_rp_D_TSCLDA_TMCCurvGRiLn_mps2), "D_TSCLDA_TMCCurvGRiLn_mps2", font, CHECK_PORT_AVAIL(m_rp_D_TSCLDA_TMCCurvGRiLn_mps2, debugString));
		DrawTextLCF(x_coord_c3, start_y_coord + y_offset_inc* step++, offset, colorWhite, CHECK_IS_CONNECTED(m_rp_D_TSCLDA_TMCCurvGRiRe_mps2), "D_TSCLDA_TMCCurvGRiRe_mps2", font, CHECK_PORT_AVAIL(m_rp_D_TSCLDA_TMCCurvGRiRe_mps2, debugString));
		DrawTextLCF(x_coord_c3, start_y_coord + y_offset_inc* step++, offset, colorWhite, CHECK_IS_CONNECTED(m_rp_D_TSCLDA_TurnSignalLeft_bool), "D_TSCLDA_TurnSignalLeft_bool", font, CHECK_PORT_AVAIL(m_rp_D_TSCLDA_TurnSignalLeft_bool, debugString));
		DrawTextLCF(x_coord_c3, start_y_coord + y_offset_inc* step++, offset, colorWhite, CHECK_IS_CONNECTED(m_rp_D_TSCLDA_TurnSignalRight_bool), "D_TSCLDA_TurnSignalRight_bool", font, CHECK_PORT_AVAIL(m_rp_D_TSCLDA_TurnSignalRight_bool, debugString));
		DrawTextLCF(x_coord_c3, start_y_coord + y_offset_inc* step++, offset, colorWhite, CHECK_IS_CONNECTED(m_rp_D_TSCLDA_VehVelYLeLn_mps), "D_TSCLDA_VehVelYLeLn_mps", font, CHECK_PORT_AVAIL(m_rp_D_TSCLDA_VehVelYLeLn_mps, debugString));
		DrawTextLCF(x_coord_c3, start_y_coord + y_offset_inc* step++, offset, colorWhite, CHECK_IS_CONNECTED(m_rp_D_TSCLDA_VehVelYLeRe_mps), "D_TSCLDA_VehVelYLeRe_mps", font, CHECK_PORT_AVAIL(m_rp_D_TSCLDA_VehVelYLeRe_mps, debugString));
		DrawTextLCF(x_coord_c3, start_y_coord + y_offset_inc* step++, offset, colorWhite, CHECK_IS_CONNECTED(m_rp_D_TSCLDA_VehVelYRiLn_mps), "D_TSCLDA_VehVelYRiLn_mps", font, CHECK_PORT_AVAIL(m_rp_D_TSCLDA_VehVelYRiLn_mps, debugString));
		DrawTextLCF(x_coord_c3, start_y_coord + y_offset_inc* step++, offset, colorWhite, CHECK_IS_CONNECTED(m_rp_D_TSCLDA_VehVelYRiRe_mps), "D_TSCLDA_VehVelYRiRe_mps", font, CHECK_PORT_AVAIL(m_rp_D_TSCLDA_VehVelYRiRe_mps, debugString));
		DrawTextLCF(x_coord_c3, start_y_coord + y_offset_inc* step++, offset, colorWhite, CHECK_IS_CONNECTED(m_rp_S_TSCLDA_LDPModeCustom_st), "S_TSCLDA_LDPModeCustom_st", font, CHECK_PORT_AVAIL(m_rp_S_TSCLDA_LDPModeCustom_st, debugString));
		#endif
	}
	else
	{
		for( unsigned char counter = 0; counter < 21; counter++) {
			DrawTextLCF(x_coord_c3, start_y_coord + y_offset_inc* counter, offset, colorRed, colorRed, "No Valid Data in Sen Debug Port", font, "Update LCFVis dll file !");
		}
	}
}

void CSimLcfVis::Add_ErrorHandler_Debug_Signals(IGDVFont& font, int start_y_coord, int x_coord_c1, unsigned short offset, unsigned short y_offset_inc, bool ValidData)
{
	char debugString[100];
	unsigned char step = 1;

	if (!m_bDrawHelp)
	{
		DrawTextLCF(x_coord_c1, start_y_coord, offset, (ERRIO_Select != 2) ? (colorBlue):(colorRed), (ERRIO_Select != 2) ? (colorBlue):(colorRed), "Error Handler : LCF SEN", font, "Press S + 1-9 / Num0-9");
		DrawTextLCF(x_coord_c1, start_y_coord + y_offset_inc* step++, offset, colorWhite, CHECK_IS_CONNECTED(m_rp_D_LCFERR_ErrorConfirmedVDY_btf), "D_LCFERR_ErrorConfirmedVDY_btf", font, CHECK_PORT_AVAIL(m_rp_D_LCFERR_ErrorConfirmedVDY_btf, debugString), 1);
		DrawTextLCF(x_coord_c1, start_y_coord + y_offset_inc* step++, offset, colorWhite, CHECK_IS_CONNECTED(m_rp_D_LCFERR_ErrorConfirmedVSA_btf), "D_LCFERR_ErrorConfirmedVSA_btf", font, CHECK_PORT_AVAIL(m_rp_D_LCFERR_ErrorConfirmedVSA_btf, debugString), 2);
		DrawTextLCF(x_coord_c1, start_y_coord + y_offset_inc* step++, offset, colorWhite, CHECK_IS_CONNECTED(m_rp_D_LCFERR_ErrorConfirmedNorm_btf), "D_LCFERR_ErrorConfirmedNorm_btf_0_", font, CHECK_PORT_ARRAY_AVAIL(m_rp_D_LCFERR_ErrorConfirmedNorm_btf, 0, debugString), 3);
		DrawTextLCF(x_coord_c1, start_y_coord + y_offset_inc* step++, offset, colorWhite, CHECK_IS_CONNECTED(m_rp_D_LCFERR_ErrorConfirmedNorm_btf), "D_LCFERR_ErrorConfirmedNorm_btf_1_", font, CHECK_PORT_ARRAY_AVAIL(m_rp_D_LCFERR_ErrorConfirmedNorm_btf, 1, debugString), 4);
		DrawTextLCF(x_coord_c1, start_y_coord + y_offset_inc* step++, offset, colorWhite, CHECK_IS_CONNECTED(m_rp_D_LCFERR_ErrorConfirmedNorm_btf), "D_LCFERR_ErrorConfirmedNorm_btf_2_", font, CHECK_PORT_ARRAY_AVAIL(m_rp_D_LCFERR_ErrorConfirmedNorm_btf, 2, debugString), 5);
		DrawTextLCF(x_coord_c1, start_y_coord + y_offset_inc* step++, offset, colorWhite, CHECK_IS_CONNECTED(m_rp_D_LCFERR_ErrorConfirmedNorm_btf), "D_LCFERR_ErrorConfirmedNorm_btf_3_", font, CHECK_PORT_ARRAY_AVAIL(m_rp_D_LCFERR_ErrorConfirmedNorm_btf, 3, debugString));
		DrawTextLCF(x_coord_c1, start_y_coord + y_offset_inc* step++, offset, colorWhite, CHECK_IS_CONNECTED(m_rp_D_LCFERR_ErrorConfirmedVSM_btf), "D_LCFERR_ErrorConfirmedVSM_btf", font, CHECK_PORT_AVAIL(m_rp_D_LCFERR_ErrorConfirmedVSM_btf, debugString), 6);
		DrawTextLCF(x_coord_c1, start_y_coord + y_offset_inc* step++, offset, colorWhite, CHECK_IS_CONNECTED(m_rp_D_LCFERR_AlliveFailedTSMon_btf), "D_LCFERR_AlliveFailedTSMon_btf", font, CHECK_PORT_AVAIL(m_rp_D_LCFERR_AlliveFailedTSMon_btf, debugString), 7);
		DrawTextLCF(x_coord_c1, start_y_coord + y_offset_inc* step++, offset, colorWhite, CHECK_IS_CONNECTED(m_rp_D_LCFERR_AlliveFailedTSBcd_btf), "D_LCFERR_AlliveFailedTSBcd_btf", font, CHECK_PORT_AVAIL(m_rp_D_LCFERR_AlliveFailedTSBcd_btf, debugString), 8);
		DrawTextLCF(x_coord_c1, start_y_coord + y_offset_inc* step++, offset, colorWhite, CHECK_IS_CONNECTED(m_rp_D_LCFERR_AlliveFailedMC_btf), "D_LCFERR_AlliveFailedMC_btf", font, CHECK_PORT_AVAIL(m_rp_D_LCFERR_AlliveFailedMC_btf, debugString), 9);
		DrawTextLCF(x_coord_c1, start_y_coord + y_offset_inc* step++, offset, colorWhite, CHECK_IS_CONNECTED(m_rp_D_LCFERR_AlliveFailedCCMon_btf), "D_LCFERR_AlliveFailedCCMon_btf", font, CHECK_PORT_AVAIL(m_rp_D_LCFERR_AlliveFailedCCMon_btf, debugString), 10);
		DrawTextLCF(x_coord_c1, start_y_coord + y_offset_inc* step++, offset, colorWhite, CHECK_IS_CONNECTED(m_rp_D_LCFERR_AlliveFailedCCConst_btf), "D_LCFERR_AlliveFailedCCConst_btf", font, CHECK_PORT_AVAIL(m_rp_D_LCFERR_AlliveFailedCCConst_btf, debugString), 11);
		DrawTextLCF(x_coord_c1, start_y_coord + y_offset_inc* step++, offset, colorWhite, CHECK_IS_CONNECTED(m_rp_D_LCFERR_AlgoCompState), "D_LCFERR_AlgoCompState", font, CHECK_PORT_AVAIL(m_rp_D_LCFERR_AlgoCompState, debugString));
		DrawTextLCF(x_coord_c1, start_y_coord + y_offset_inc* step++, offset, colorWhite, CHECK_IS_CONNECTED(m_rp_D_LCFERR_SenOutSigStatus), "D_LCFERR_SenOutSigStatus", font, CHECK_PORT_AVAIL(m_rp_D_LCFERR_SenOutSigStatus, debugString));
		DrawTextLCF(x_coord_c1, start_y_coord + y_offset_inc* step++, offset, colorWhite, CHECK_IS_CONNECTED(m_rp_D_LCFERR_Sen2VehSigStatus), "D_LCFERR_Sen2VehSigStatus", font, CHECK_PORT_AVAIL(m_rp_D_LCFERR_Sen2VehSigStatus, debugString));
		DrawTextLCF(x_coord_c1, start_y_coord + y_offset_inc* step++, offset, colorWhite, CHECK_IS_CONNECTED(m_rp_D_LCFERR_DemEvents_btf), "D_LCFERR_DemEvents_btf", font, CHECK_PORT_AVAIL(m_rp_D_LCFERR_DemEvents_btf, debugString));
		DrawTextLCF(x_coord_c1, start_y_coord + y_offset_inc* step++, offset, colorWhite, CHECK_IS_CONNECTED(m_rp_D_ERRIOSEN_ErrStateArray), "D_ERRIOSEN_ErrStateArray", font, (m_rp_D_ERRIOSEN_ErrStateArray.isConnected()) ? (LcofValueToString(m_rp_D_ERRIOSEN_ErrStateArray.val(), debugString, m_rp_D_ERRIOSEN_ErrStateArray.size() / sizeof(unsigned char))) : ("Not Connected"));
		DrawTextLCF(x_coord_c1, start_y_coord + y_offset_inc* step++, offset, colorWhite, CHECK_IS_CONNECTED(m_rp_D_LCFERR_RngChkDbg_btf), "D_LCFERR_RngChkDbg_btf", font, (m_rp_D_LCFERR_RngChkDbg_btf.isConnected()) ? (LcofValueToString(m_rp_D_LCFERR_RngChkDbg_btf.val(), debugString, m_rp_D_LCFERR_RngChkDbg_btf.size() / sizeof(unsigned int))) : ("Not Connected"));
		DrawTextLCF(x_coord_c1, start_y_coord + y_offset_inc* step++, offset, colorOrange, colorOrange, "For LCF SEN RangeCheckDebug", font, "Press Num 2...9");
	}

	x_coord_c1 += 445;
	offset = 283;
	start_y_coord = 45;
	step = 0;

	DrawTextLCF(x_coord_c1, start_y_coord + y_offset_inc* step++, offset, (ERRIO_Select == 2) ? (colorBlue):(colorRed), (ERRIO_Select == 2) ? (colorBlue):(colorRed), "Error Handler : LCF VEH", font, "Press V + 1-9 / Num0-9");
	DrawTextLCF(x_coord_c1, start_y_coord + y_offset_inc* step++, offset, colorWhite, CHECK_IS_CONNECTED(m_rp_D_LCFERR_Veh_ErrorConfirmedVDY_btf), "D_LCFERR_ErrorConfirmedVDY_btf", font, CHECK_PORT_AVAIL(m_rp_D_LCFERR_Veh_ErrorConfirmedVDY_btf, debugString), 1);
	DrawTextLCF(x_coord_c1, start_y_coord + y_offset_inc* step++, offset, colorWhite, CHECK_IS_CONNECTED(m_rp_D_LCFERR_Veh_ErrorConfirmedVSA_btf), "D_LCFERR_ErrorConfirmedVSA_btf", font, CHECK_PORT_AVAIL(m_rp_D_LCFERR_Veh_ErrorConfirmedVSA_btf, debugString), 2);
	DrawTextLCF(x_coord_c1, start_y_coord + y_offset_inc* step++, offset, colorWhite, CHECK_IS_CONNECTED(m_rp_D_LCFERR_Veh_ErrorConfirmedNorm_btf), "D_LCFERR_ErrorConfirmedNorm_btf_0_", font, CHECK_PORT_ARRAY_AVAIL(m_rp_D_LCFERR_Veh_ErrorConfirmedNorm_btf, 0, debugString), 3);
	DrawTextLCF(x_coord_c1, start_y_coord + y_offset_inc* step++, offset, colorWhite, CHECK_IS_CONNECTED(m_rp_D_LCFERR_Veh_ErrorConfirmedNorm_btf), "D_LCFERR_ErrorConfirmedNorm_btf_1_", font, CHECK_PORT_ARRAY_AVAIL(m_rp_D_LCFERR_Veh_ErrorConfirmedNorm_btf, 1, debugString), 4);
	DrawTextLCF(x_coord_c1, start_y_coord + y_offset_inc* step++, offset, colorWhite, CHECK_IS_CONNECTED(m_rp_D_LCFERR_Veh_ErrorConfirmedNorm_btf), "D_LCFERR_ErrorConfirmedNorm_btf_2_", font, CHECK_PORT_ARRAY_AVAIL(m_rp_D_LCFERR_Veh_ErrorConfirmedNorm_btf, 2, debugString), 5);
	DrawTextLCF(x_coord_c1, start_y_coord + y_offset_inc* step++, offset, colorWhite, CHECK_IS_CONNECTED(m_rp_D_LCFERR_Veh_ErrorConfirmedNorm_btf), "D_LCFERR_ErrorConfirmedNorm_btf_3_", font, CHECK_PORT_ARRAY_AVAIL(m_rp_D_LCFERR_Veh_ErrorConfirmedNorm_btf, 3, debugString));
	DrawTextLCF(x_coord_c1, start_y_coord + y_offset_inc* step++, offset, colorWhite, CHECK_IS_CONNECTED(m_rp_D_LCFERR_Veh_ErrorConfirmedVSM_btf), "D_LCFERR_ErrorConfirmedVSM_btf", font, CHECK_PORT_AVAIL(m_rp_D_LCFERR_Veh_ErrorConfirmedVSM_btf, debugString), 6);
	DrawTextLCF(x_coord_c1, start_y_coord + y_offset_inc* step++, offset, colorWhite, CHECK_IS_CONNECTED(m_rp_D_LCFERR_Veh_AlliveFailedTSMon_btf), "D_LCFERR_AlliveFailedTSMon_btf", font, CHECK_PORT_AVAIL(m_rp_D_LCFERR_Veh_AlliveFailedTSMon_btf, debugString), 7);
	DrawTextLCF(x_coord_c1, start_y_coord + y_offset_inc* step++, offset, colorWhite, CHECK_IS_CONNECTED(m_rp_D_LCFERR_Veh_AlliveFailedTSBcd_btf), "D_LCFERR_AlliveFailedTSBcd_btf", font, CHECK_PORT_AVAIL(m_rp_D_LCFERR_Veh_AlliveFailedTSBcd_btf, debugString), 8);
	DrawTextLCF(x_coord_c1, start_y_coord + y_offset_inc* step++, offset, colorWhite, CHECK_IS_CONNECTED(m_rp_D_LCFERR_Veh_AlliveFailedMC_btf), "D_LCFERR_AlliveFailedMC_btf", font, CHECK_PORT_AVAIL(m_rp_D_LCFERR_Veh_AlliveFailedMC_btf, debugString), 9);
	DrawTextLCF(x_coord_c1, start_y_coord + y_offset_inc* step++, offset, colorWhite, CHECK_IS_CONNECTED(m_rp_D_LCFERR_Veh_AlliveFailedCCMon_btf), "D_LCFERR_AlliveFailedCCMon_btf", font, CHECK_PORT_AVAIL(m_rp_D_LCFERR_Veh_AlliveFailedCCMon_btf, debugString), 10);
	DrawTextLCF(x_coord_c1, start_y_coord + y_offset_inc* step++, offset, colorWhite, CHECK_IS_CONNECTED(m_rp_D_LCFERR_Veh_AlliveFailedCCConst_btf), "D_LCFERR_AlliveFailedCCConst_btf", font, CHECK_PORT_AVAIL(m_rp_D_LCFERR_Veh_AlliveFailedCCConst_btf, debugString), 11);
	DrawTextLCF(x_coord_c1, start_y_coord + y_offset_inc* step++, offset, colorWhite, CHECK_IS_CONNECTED(m_rp_D_LCFERR_Veh_AlgoCompState), "D_LCFERR_AlgoCompState", font, CHECK_PORT_AVAIL(m_rp_D_LCFERR_Veh_AlgoCompState, debugString));
	DrawTextLCF(x_coord_c1, start_y_coord + y_offset_inc* step++, offset, colorWhite, CHECK_IS_CONNECTED(m_rp_D_LCFERR_Veh_VehOutSigStatus), "D_LCFERR_VehOutSigStatus", font, CHECK_PORT_AVAIL(m_rp_D_LCFERR_Veh_VehOutSigStatus, debugString));
	DrawTextLCF(x_coord_c1, start_y_coord + y_offset_inc* step++, offset, colorWhite, CHECK_IS_CONNECTED(m_rp_D_LCFERR_Veh_Veh2SenSigStatus), "D_LCFERR_Veh2SenSigStatus", font, CHECK_PORT_AVAIL(m_rp_D_LCFERR_Veh_Veh2SenSigStatus, debugString));
	DrawTextLCF(x_coord_c1, start_y_coord + y_offset_inc* step++, offset, colorWhite, CHECK_IS_CONNECTED(m_rp_D_LCFERR_Veh_Soc2IucSigStatus), "D_LCFERR_Veh_Soc2IucSigStatus", font, CHECK_PORT_AVAIL(m_rp_D_LCFERR_Veh_Soc2IucSigStatus, debugString));
	DrawTextLCF(x_coord_c1, start_y_coord + y_offset_inc* step++, offset, colorWhite, CHECK_IS_CONNECTED(m_rp_D_LCFERR_Veh_DemEvents_btf), "D_LCFERR_DemEvents_btf", font, CHECK_PORT_AVAIL(m_rp_D_LCFERR_Veh_DemEvents_btf, debugString));
	DrawTextLCF(x_coord_c1, start_y_coord + y_offset_inc* step++, offset, colorWhite, CHECK_IS_CONNECTED(m_rp_D_ERRIOVEH_ErrStateArray), "D_ERRIOVEH_ErrStateArray", font, (m_rp_D_ERRIOVEH_ErrStateArray.isConnected()) ? (LcofValueToString(m_rp_D_ERRIOVEH_ErrStateArray.val(), debugString, m_rp_D_ERRIOVEH_ErrStateArray.size() / sizeof(unsigned char))) : ("Not Connected"));
	DrawTextLCF(x_coord_c1, start_y_coord + y_offset_inc* step++, offset, colorWhite, CHECK_IS_CONNECTED(m_rp_D_LCFERR_Veh_RngChkDbg_btf), "D_LCFERR_RngChkDbg_btf", font, (m_rp_D_LCFERR_Veh_RngChkDbg_btf.isConnected()) ? (LcofValueToString(m_rp_D_LCFERR_Veh_RngChkDbg_btf.val(), debugString, m_rp_D_LCFERR_Veh_RngChkDbg_btf.size() / sizeof(unsigned int))) : ("Not Connected"));
	DrawTextLCF(x_coord_c1, start_y_coord + y_offset_inc* step++, offset, colorOrange, colorOrange, "For LCF VEH RangeCheckDebug", font, "Press Num 2...9");
}

void CSimLcfVis::Add_LCFIntegration_Debug_Signals(IGDVFont& font, int start_y_coord, int x_coord_c1, unsigned short offset, unsigned short y_offset_inc, bool ValidData)
{
	char debugString[100];
	unsigned char step = 1;

	if (!m_bDrawHelp) {
		DrawTextLCF(x_coord_c1, start_y_coord, offset, colorBlue, colorBlue, "LCF Component Status", font, "");
		DrawTextLCF(x_coord_c1, start_y_coord + y_offset_inc* step++, offset, colorWhite, CHECK_IS_CONNECTED(m_rp_D_LCFSEN_proPorts_NullStatusCheck), "D_LCFSEN_proPorts_NullStatusCheck", font, CHECK_PORT_AVAIL(m_rp_D_LCFSEN_proPorts_NullStatusCheck, debugString), 1);
		DrawTextLCF(x_coord_c1, start_y_coord + y_offset_inc* step++, offset, colorWhite, CHECK_IS_CONNECTED(m_rp_D_LCFSEN_reqPorts_NullStatusCheck), "D_LCFSEN_reqPorts_NullStatusCheck", font, CHECK_PORT_AVAIL(m_rp_D_LCFSEN_reqPorts_NullStatusCheck, debugString), 3);
		DrawTextLCF(x_coord_c1, start_y_coord + y_offset_inc* step++, offset, colorWhite, CHECK_IS_CONNECTED(m_rp_D_LCFSEN_services_NullStatusCheck), "D_LCFSEN_services_NullStatusCheck", font, CHECK_PORT_AVAIL(m_rp_D_LCFSEN_services_NullStatusCheck, debugString));
		DrawTextLCF(x_coord_c1, start_y_coord + y_offset_inc* step++, offset, colorWhite, CHECK_IS_CONNECTED(m_rp_D_LCFSEN_reqPorts_SignalStatusOk), "D_LCFSEN_reqPorts_SignalStatusOk", font, CHECK_PORT_AVAIL(m_rp_D_LCFSEN_reqPorts_SignalStatusOk, debugString));
		DrawTextLCF(x_coord_c1, start_y_coord + y_offset_inc* step++, offset, colorWhite, CHECK_IS_CONNECTED(m_rp_D_LCFSEN_reqPorts_SignalStatusInit), "D_LCFSEN_reqPorts_SignalStatusInit", font, CHECK_PORT_AVAIL(m_rp_D_LCFSEN_reqPorts_SignalStatusInit, debugString));
		DrawTextLCF(x_coord_c1, start_y_coord + y_offset_inc* step++, offset, colorWhite, CHECK_IS_CONNECTED(m_rp_D_LCFSEN_reqPorts_SignalStatusInvalid), "D_LCFSEN_reqPorts_SignalStatusInvalid", font, CHECK_PORT_AVAIL(m_rp_D_LCFSEN_reqPorts_SignalStatusInvalid, debugString));
		DrawTextLCF(x_coord_c1, start_y_coord + y_offset_inc* step++, offset, colorWhite, CHECK_IS_CONNECTED(m_rp_D_LCFSEN_reqPorts_VersionNumberCheck), "D_LCFSEN_reqPorts_VersNumberCheck", font, CHECK_PORT_AVAIL(m_rp_D_LCFSEN_reqPorts_VersionNumberCheck, debugString));
		DrawTextLCF(x_coord_c1, start_y_coord + y_offset_inc* step++, offset, colorWhite, CHECK_IS_CONNECTED(m_rp_uiSenTunParCopied), "LCFSEN_uiTunParCopied", font, CHECK_PORT_AVAIL(m_rp_uiSenTunParCopied, debugString));
		DrawTextLCF(x_coord_c1, start_y_coord + y_offset_inc* step++, offset, colorWhite, CHECK_IS_CONNECTED(m_rp_uiSenVdyParCopied), "LCFSEN_uiVdyParCopied", font, CHECK_PORT_AVAIL(m_rp_uiSenVdyParCopied, debugString));
		DrawTextLCF(x_coord_c1, start_y_coord + y_offset_inc* step++, offset, colorWhite, CHECK_IS_CONNECTED(m_rp_D_LCFVEH_proPorts_NullStatusCheck), "D_LCFVEH_proPorts_NullStatusCheck", font, CHECK_PORT_AVAIL(m_rp_D_LCFVEH_proPorts_NullStatusCheck, debugString), 2);
		DrawTextLCF(x_coord_c1, start_y_coord + y_offset_inc* step++, offset, colorWhite, CHECK_IS_CONNECTED(m_rp_D_LCFVEH_reqPorts_NullStatusCheck), "D_LCFVEH_reqPorts_NullStatusCheck", font, CHECK_PORT_AVAIL(m_rp_D_LCFVEH_reqPorts_NullStatusCheck, debugString), 4);
		DrawTextLCF(x_coord_c1, start_y_coord + y_offset_inc* step++, offset, colorWhite, CHECK_IS_CONNECTED(m_rp_D_LCFVEH_services_NullStatusCheck), "D_LCFVEH_services_NullStatusCheck", font, CHECK_PORT_AVAIL(m_rp_D_LCFVEH_services_NullStatusCheck, debugString));
		DrawTextLCF(x_coord_c1, start_y_coord + y_offset_inc* step++, offset, colorWhite, CHECK_IS_CONNECTED(m_rp_D_LCFVEH_reqPorts_SignalStatusOk), "D_LCFVEH_reqPorts_SignalStatusOk", font, CHECK_PORT_AVAIL(m_rp_D_LCFVEH_reqPorts_SignalStatusOk, debugString));
		DrawTextLCF(x_coord_c1, start_y_coord + y_offset_inc* step++, offset, colorWhite, CHECK_IS_CONNECTED(m_rp_D_LCFVEH_reqPorts_SignalStatusInit), "D_LCFVEH_reqPorts_SignalStatusInit", font, CHECK_PORT_AVAIL(m_rp_D_LCFVEH_reqPorts_SignalStatusInit, debugString));
		DrawTextLCF(x_coord_c1, start_y_coord + y_offset_inc* step++, offset, colorWhite, CHECK_IS_CONNECTED(m_rp_D_LCFVEH_reqPorts_SignalStatusInvalid), "D_LCFVEH_reqPorts_SignalStatusInvalid", font, CHECK_PORT_AVAIL(m_rp_D_LCFVEH_reqPorts_SignalStatusInvalid, debugString));
		DrawTextLCF(x_coord_c1, start_y_coord + y_offset_inc* step++, offset, colorWhite, CHECK_IS_CONNECTED(m_rp_D_LCFVEH_reqPorts_VersionNumberCheck), "D_LCFVEH_reqPorts_VersNumberCheck", font, CHECK_PORT_AVAIL(m_rp_D_LCFVEH_reqPorts_VersionNumberCheck, debugString));
		DrawTextLCF(x_coord_c1, start_y_coord + y_offset_inc* step++, offset, colorWhite, CHECK_IS_CONNECTED(m_rp_uiVehTunParCopied), "LCFVEH_uiTunParCopied", font, CHECK_PORT_AVAIL(m_rp_uiVehTunParCopied, debugString));
		DrawTextLCF(x_coord_c1, start_y_coord + y_offset_inc* step++, offset, colorWhite, CHECK_IS_CONNECTED(m_rp_uiVehVdyParCopied), "LCFVEH_uiVdyParCopied", font, CHECK_PORT_AVAIL(m_rp_uiVehVdyParCopied, debugString));
		DrawTextLCF(x_coord_c1, start_y_coord + y_offset_inc* step++, offset, colorWhite, CHECK_IS_CONNECTED(m_rp_uiVehNvmDataValid), "LCFVEH_uiNvmDataValid", font, CHECK_PORT_AVAIL(m_rp_uiVehNvmDataValid, debugString));
		}
	
	x_coord_c1 += 445;
	offset = 283;
	start_y_coord = 45;
	step = 0;

	/* Statistical Data */
	DrawTextLCF(x_coord_c1, start_y_coord + y_offset_inc* step++, offset, colorBlue, colorBlue, "Statistical Data", font, "Number of activations");
	DrawTextLCF(x_coord_c1, start_y_coord + y_offset_inc* step++, offset, colorWhite, colorLime, "TJA Function", font, LcofValueToString(m_Function_Activation_Number[0], debugString));
	DrawTextLCF(x_coord_c1, start_y_coord + y_offset_inc* step++, offset, colorWhite, colorLime, "LDP Function", font, LcofValueToString(m_Function_Activation_Number[1], debugString));
	DrawTextLCF(x_coord_c1, start_y_coord + y_offset_inc* step++, offset, colorWhite, colorLime, "LDW Function", font, LcofValueToString(m_Function_Activation_Number[2], debugString));
	DrawTextLCF(x_coord_c1, start_y_coord + y_offset_inc* step++, offset, colorWhite, colorLime, "RDP Function", font, LcofValueToString(m_Function_Activation_Number[3], debugString));
	DrawTextLCF(x_coord_c1, start_y_coord + y_offset_inc* step++, offset, colorWhite, colorLime, "LDPOC Function", font, LcofValueToString(m_Function_Activation_Number[4], debugString));
}

void CSimLcfVis::Add_DRVMN_Debug_Signals(IGDVFont& font, int start_y_coord, int x_coord_c1, unsigned short offset, unsigned short y_offset_inc, bool ValidData)
{
	char debugString[100];
	unsigned char step = 1;

	if (!m_bDrawHelp)
	{
		if(ValidData) {
			#if defined(_DRVMN_VEHDBGTYPE_T_) || defined(_V1DRVMN_VEHDBGTYPE_T_) || defined(_V2DRVMN_VEHDBGTYPE_T_)
			DrawTextLCF(x_coord_c1, start_y_coord, offset, colorWhite, CHECK_IS_CONNECTED(m_rp_S_DRMDAE_AbuseWarning_bool), "S_DRMDAE_AbuseWarning_bool", font, CHECK_PORT_AVAIL(m_rp_S_DRMDAE_AbuseWarning_bool, debugString));
			DrawTextLCF(x_coord_c1, start_y_coord + y_offset_inc* step++, offset, colorWhite, CHECK_IS_CONNECTED(m_rp_S_DRMDAE_SysWarning_nu), "S_DRMDAE_SysWarning_nu", font, CHECK_PORT_AVAIL(m_rp_S_DRMDAE_SysWarning_nu, debugString));
			DrawTextLCF(x_coord_c1, start_y_coord + y_offset_inc* step++, offset, colorWhite, CHECK_IS_CONNECTED(m_rp_D_DRMHOD_EstHandTor_Nm), "D_DRMHOD_EstHandTor_Nm", font, CHECK_PORT_AVAIL(m_rp_D_DRMHOD_EstHandTor_Nm, debugString));
			DrawTextLCF(x_coord_c1, start_y_coord + y_offset_inc* step++, offset, colorWhite, CHECK_IS_CONNECTED(m_rp_S_DRMHOD_HandsOffConfirmed_bool), "S_DRMHOD_HandsOffConfirmed_bool", font, CHECK_PORT_AVAIL(m_rp_S_DRMHOD_HandsOffConfirmed_bool, debugString));
			#endif
		}
		else {
			for( unsigned char counter = 0; counter < 21; counter++) {
				DrawTextLCF(x_coord_c1, start_y_coord + y_offset_inc* counter, offset, colorRed, colorRed, "No Valid Data in Veh Debug Port", font, "Update LCFVis dll file !");
			}
		}
	}

	x_coord_c1 += 445;
	offset = 283;
	start_y_coord = 45;
	step = 0;

	/* LCF SEN Scheduler Info */
	DrawTextLCF(x_coord_c1, start_y_coord + y_offset_inc* step++, offset, colorBlue, colorBlue, "LCF SEN Scheduler Info Data", font, "");
	/* OcPa : Plot the next two signals only if debug is needed */
	//DrawTextLCF(x_coord_c1, start_y_coord + y_offset_inc* step++, offset, colorWhite, colorLime, "Total Timestamp SEN", font, LcofValueToString(LCF_SEN_Scheduler_Info.Total_TS_Value, debugString));
	//DrawTextLCF(x_coord_c1, start_y_coord + y_offset_inc* step++, offset, colorWhite, colorLime, "Total CycleCounter SEN", font, LcofValueToString(LCF_SEN_Scheduler_Info.Total_CC_Value, debugString));
	DrawTextLCF(x_coord_c1, start_y_coord + y_offset_inc* step++, offset, colorWhite, colorLime, "Average Cycle Time LCF SEN", font, LcofValueToString(LCF_SEN_Scheduler_Info.AverageCycleTime, debugString, 42));
	DrawTextLCF(x_coord_c1, start_y_coord + y_offset_inc* step++, offset, colorWhite, colorLime, "Instant Cycle Time LCF SEN", font, LcofValueToString(LCF_SEN_Scheduler_Info.Instant_TS_Difference, debugString, 42));
	DrawTextLCF(x_coord_c1, start_y_coord + y_offset_inc* step++, offset, colorWhite, colorLime, "Instant Cycle Time History [0..2]", font, LcofValueToString(LCF_SEN_Scheduler_Info.Buffer_Inst_TS_Difference, debugString, 0));
	DrawTextLCF(x_coord_c1, start_y_coord + y_offset_inc* step++, offset, colorWhite, colorLime, "Instant Cycle Time History [3..5]", font, LcofValueToString(LCF_SEN_Scheduler_Info.Buffer_Inst_TS_Difference, debugString, 1));
	DrawTextLCF(x_coord_c1, start_y_coord + y_offset_inc* step++, offset, colorWhite, colorLime, "Instant Cycle Time History [6..8]", font, LcofValueToString(LCF_SEN_Scheduler_Info.Buffer_Inst_TS_Difference, debugString, 2));
	DrawTextLCF(x_coord_c1, start_y_coord + y_offset_inc* step++, offset, colorWhite, colorLime, "Instant Cycle Time History [8..9]", font, LcofValueToString(LCF_SEN_Scheduler_Info.Buffer_Inst_TS_Difference, debugString, 3));
	DrawTextLCF(x_coord_c1, start_y_coord + y_offset_inc* step++, offset, colorWhite, ((LCF_SEN_Scheduler_Info.TimestampBlocked == 0) ? (colorLime) : (colorRed)), "Timestamp Blocked LCF SEN", font, ((LCF_SEN_Scheduler_Info.TimestampBlocked == 0) ? ("False") : ("True")));
	DrawTextLCF(x_coord_c1, start_y_coord + y_offset_inc* step++, offset, colorWhite, ((LCF_SEN_Scheduler_Info.CycleCounterBlocked == 0) ? (colorLime) : (colorRed)), "Cycle Counter Blocked LCF SEN", font, ((LCF_SEN_Scheduler_Info.CycleCounterBlocked == 0) ? ("False") : ("True")));
	DrawTextLCF(x_coord_c1, start_y_coord + y_offset_inc* step++, offset, colorWhite, colorLime, "Number of LCF SEN Tasks Skipped", font, LcofValueToString(LCF_SEN_Scheduler_Info.NumberOfSkippedFrames, debugString));
	DrawTextLCF(x_coord_c1, start_y_coord + y_offset_inc* step++, offset, colorWhite, colorLime, "Percentage of LCF SEN Tasks Skipped", font, LcofValueToString(LCF_SEN_Scheduler_Info.PercentageOfSkippedFrames, debugString, 1));
	
	/* LCF VEH Scheduler Info */
	DrawTextLCF(x_coord_c1, start_y_coord + y_offset_inc* step++, offset, colorBlue, colorBlue, "LCF VEH Scheduler Info Data", font, "");
	/* OcPa : Plot the next two signals only if debug is needed */
	//DrawTextLCF(x_coord_c1, start_y_coord + y_offset_inc* step++, offset, colorWhite, colorLime, "Total Timestamp VEH", font, LcofValueToString(LCF_VEH_Scheduler_Info.Total_TS_Value, debugString));
	//DrawTextLCF(x_coord_c1, start_y_coord + y_offset_inc* step++, offset, colorWhite, colorLime, "Total CycleCounter VEH", font, LcofValueToString(LCF_VEH_Scheduler_Info.Total_CC_Value, debugString));
	DrawTextLCF(x_coord_c1, start_y_coord + y_offset_inc* step++, offset, colorWhite, colorLime, "Average Cycle Time LCF VEH", font, LcofValueToString(LCF_VEH_Scheduler_Info.AverageCycleTime, debugString, 42));
	DrawTextLCF(x_coord_c1, start_y_coord + y_offset_inc* step++, offset, colorWhite, colorLime, "Instant Cycle Time LCF VEH", font, LcofValueToString(LCF_VEH_Scheduler_Info.Instant_TS_Difference, debugString, 42));
	DrawTextLCF(x_coord_c1, start_y_coord + y_offset_inc* step++, offset, colorWhite, colorLime, "Instant Cycle Time History [0..2]", font, LcofValueToString(LCF_VEH_Scheduler_Info.Buffer_Inst_TS_Difference, debugString, 0));
	DrawTextLCF(x_coord_c1, start_y_coord + y_offset_inc* step++, offset, colorWhite, colorLime, "Instant Cycle Time History [3..5]", font, LcofValueToString(LCF_VEH_Scheduler_Info.Buffer_Inst_TS_Difference, debugString, 1));
	DrawTextLCF(x_coord_c1, start_y_coord + y_offset_inc* step++, offset, colorWhite, colorLime, "Instant Cycle Time History [6..8]", font, LcofValueToString(LCF_VEH_Scheduler_Info.Buffer_Inst_TS_Difference, debugString, 2));
	DrawTextLCF(x_coord_c1, start_y_coord + y_offset_inc* step++, offset, colorWhite, colorLime, "Instant Cycle Time History [8..9]", font, LcofValueToString(LCF_VEH_Scheduler_Info.Buffer_Inst_TS_Difference, debugString, 3));
	DrawTextLCF(x_coord_c1, start_y_coord + y_offset_inc* step++, offset, colorWhite, ((LCF_VEH_Scheduler_Info.TimestampBlocked == 0) ? (colorLime) : (colorRed)), "Timestamp Blocked LCF VEH", font, ((LCF_VEH_Scheduler_Info.TimestampBlocked == 0) ? ("False") : ("True")));
	DrawTextLCF(x_coord_c1, start_y_coord + y_offset_inc* step++, offset, colorWhite, ((LCF_VEH_Scheduler_Info.CycleCounterBlocked == 0) ? (colorLime) : (colorRed)), "Cycle Counter Blocked LCF VEH", font, ((LCF_VEH_Scheduler_Info.CycleCounterBlocked == 0) ? ("False") : ("True")));
	DrawTextLCF(x_coord_c1, start_y_coord + y_offset_inc* step++, offset, colorWhite, colorLime, "Number of LCF VEH Tasks Skipped", font, LcofValueToString(LCF_VEH_Scheduler_Info.NumberOfSkippedFrames, debugString));
	DrawTextLCF(x_coord_c1, start_y_coord + y_offset_inc* step++, offset, colorWhite, colorLime, "Percentage of LCF VEH Tasks Skipped", font, LcofValueToString(LCF_VEH_Scheduler_Info.PercentageOfSkippedFrames, debugString, 1));

}

const char* CSimLcfVis::LcofSysStateToString(unsigned char input, char* debs)
{
    memset(debs, 0, sizeof(debs));
    switch(input)
    {
    case LCF_SYSSTATE_NOTPRESENT:
        sprintf(debs, "%d = NOTPRESENT", input);
        break;
    case LCF_SYSSTATE_DISABLED:
        sprintf(debs, "%d = DISABLED", input);
        break;
	case LCF_SYSSTATE_PASSIVE:
        sprintf(debs, "%d = PASSIVE", input);
        break;
	case LCF_SYSSTATE_REQUEST:
        sprintf(debs, "%d = REQUEST", input);
        break;
	case LCF_SYSSTATE_CONTROLLING:
        sprintf(debs, "%d = CONTROLLING", input);
        break;
	case LCF_SYSSTATE_RAMPOUT:
        sprintf(debs, "%d = RAMPOUT", input);
        break;
	case LCF_SYSSTATE_ERROR:
        sprintf(debs, "%d = ERROR", input);
        break;
    default:
        sprintf(debs, "%d = Invalid", input);
    }
    return debs;
}

const char* CSimLcfVis::CtrlFunctionToString(unsigned char input, char* debs)
{
    memset(debs, 0, sizeof(debs));
    switch(input)
    {
    case E_LCF_OFF_nu:
        sprintf(debs, "%d = OFF", input);
        break;
    case E_LCF_TJA_nu:
        sprintf(debs, "%d = TJA", input);
        break;
	case E_LCF_LDP_nu:
        sprintf(debs, "%d = LDP", input);
        break;
	case E_LCF_LDPOC_nu:
        sprintf(debs, "%d = LDPOC", input);
        break;
	case E_LCF_RDP_nu:
        sprintf(debs, "%d = RDP", input);
        break;
	case E_LCF_ESA_nu:
        sprintf(debs, "%d = AES", input);
        break;
    default:
        sprintf(debs, "%d = Invalid", input);
    }
    return debs;
}

const char* CSimLcfVis::LaneValidQualifToString(unsigned char input, char* debs)
{
	memset(debs, 0, sizeof(debs));

#ifdef LCF_MFC431_RELEASE_0800_RTE_INT01

	/* 	Visu Bitfield: 

	Bit 0: Left lane valid only
	Bit 1: Right lane valid only 
	Bit 2: Left lane bridged
	Bit 3: Right lane bridged 
	Bit 4: Left lane LD virtual 
	Bit 5: Right lane LD virtual
	Bit 6:  Both lane markers valid
	Bit 7:  */
	
	input = input & 207; //remove LD virtual bits
	
    switch(input)
    {
    case 0: //NO_LANE_MARKINGS
        sprintf(debs, "%d = NO_LANE_MARKINGS", input);
        break;
	case 1: //Left lane only
        sprintf(debs, "%d = ONE_SIDED_LEFT", input);
        break;
    case 2:
        sprintf(debs, "%d = ONE_SIDED_RIGHT", input);
        break;
	case 4:
        sprintf(debs, "%d = LEFT VIRTUAL", input);
        break;
	case 8:
        sprintf(debs, "%d = RIGHT VIRTUAL", input);
        break;
    case 16:
        sprintf(debs, "%d = LEFT_LD_VIRTUAL", input);
        break;
	case 32:
        sprintf(debs, "%d = RIGHT_LD_VIRTUAL", input);
        break;
	case 64:
        sprintf(debs, "%d = BOTH_LANES_VALID", input);
        break;
    default:
        sprintf(debs, "%d = Invalid", input);
    }
    return debs;
 
#else
   switch(input)
    {
    case E_ABPLBP_LQ_NO_EGO_LN_MARKER:
        sprintf(debs, "%d = NO_LANE_MARKINGS", input);
        break;
    case E_ABPLBP_LQ_LE_EGO_LN_VALID:
        sprintf(debs, "%d = ONE_SIDED_LEFT", input);
        break;
	case E_ABPLBP_LQ_LE_EGO_LN_VIRTUAL:
        sprintf(debs, "%d = ONE_SIDED_BRIDGED_LEFT", input);
        break;
	case E_ABPLBP_LQ_RI_EGO_LN_VALID:
        sprintf(debs, "%d = ONE_SIDED_RIGHT", input);
        break;
    case E_ABPLBP_LQ_RI_EGO_LN_VIRTUAL:
        sprintf(debs, "%d = ONE_SIDED_BRIDGED_RIGHT", input);
        break;
	case E_ABPLBP_LQ_BOTH_EGO_LN_VALID:
        sprintf(debs, "%d = BOTH_SIDED", input);
        break;
    default:
        sprintf(debs, "%d = Invalid", input);
    }
    return debs;
	
#endif
}

const char* CSimLcfVis::LDParallelModeToString(unsigned char input, char* debs)
{
    memset(debs, 0, sizeof(debs));
    switch(input)
    {
    case LD_PM_NOT_PARALLEL:
        sprintf(debs, "%d = OFF", input);
        break;
    case LD_PM_PARALLEL:
        sprintf(debs, "%d = ON", input);
        break;
    default:
        sprintf(debs, "%d = Invalid", input);
    }
    return debs;
}

void CSimLcfVis::DrawLcfInfo( const ISimRenderContext& ctx )
{
	uint8 ui8LaneValidQual;
	
	GL::Init();

	char debugString[500];
    IGDVFont& font = ctx.GetWindow().GetFontInterface("Arial", 10);

    int drawAtY1=20;
    int drawAtX1_1=20;
    int drawAtX1_2=500;

    int drawStep=50;

    font.BeginRender2D();

	if (m_bLcfSenOutputDataValid && m_bLcfSenOutputToVehDataValid && m_bAbdOutputDataValid)
    {
        /* *COL1******************************************************************************* */
		/* State */
        font.SetTextColor( colorYellow.r, colorYellow.g, colorYellow.b, colorYellow.a);
        font.RenderTextf(drawAtX1_1, drawAtY1, 0, "State");
        drawAtY1+=drawStep;

		/* LatCtrlModeLKA_nu */
		// font.SetTextColor( colorWhite.r, colorWhite.g, colorWhite.b, colorWhite.a);
        // font.RenderTextf(drawAtX1_1, drawAtY1, 0, "LatCtrlModeLKA:");
		// font.SetTextColor( colorLime.r, colorLime.g, colorLime.b, colorLime.a);
		// font.RenderTextf(drawAtX1_2, drawAtY1, 0, LcofLatCtrlModeToString(m_LcfSenOutputToVehData.LCF_SysCoordinator.LatCtrlModeLKA_nu, debugString));
		// drawAtY1+=drawStep;

		/* SysStateTJA_nu */
		font.SetTextColor( colorWhite.r, colorWhite.g, colorWhite.b, colorWhite.a);
        font.RenderTextf(drawAtX1_1, drawAtY1, 0, "SysStateTJA:");
		font.SetTextColor( colorLime.r, colorLime.g, colorLime.b, colorLime.a);
		font.RenderTextf(drawAtX1_2, drawAtY1, 0, LcofSysStateToString(m_LcfSenOutputToVehData.LCF_SysCoordinator.SysStateTJA_nu, debugString));
		drawAtY1+=drawStep;

		/* SysStateLDP_nu */
		font.SetTextColor( colorWhite.r, colorWhite.g, colorWhite.b, colorWhite.a);
        font.RenderTextf(drawAtX1_1, drawAtY1, 0, "SysStateLDP:");
		font.SetTextColor( colorLime.r, colorLime.g, colorLime.b, colorLime.a);
		font.RenderTextf(drawAtX1_2, drawAtY1, 0, LcofSysStateToString(m_LcfSenOutputToVehData.LCF_SysCoordinator.SysStateLDP_nu, debugString));
		drawAtY1+=drawStep;

		/* ControllingFunction_nu */
		font.SetTextColor( colorWhite.r, colorWhite.g, colorWhite.b, colorWhite.a);
        font.RenderTextf(drawAtX1_1, drawAtY1, 0, "ControllingFunction:");
		font.SetTextColor( colorLime.r, colorLime.g, colorLime.b, colorLime.a);
		font.RenderTextf(drawAtX1_2, drawAtY1, 0, CtrlFunctionToString(m_LcfSenOutputToVehData.ControllingFunction_nu, debugString));
		drawAtY1+=drawStep;
		
		/* TEST */
		/* font.SetTextColor( colorWhite.r, colorWhite.g, colorWhite.b, colorWhite.a);
        font.RenderTextf(drawAtX1_1, drawAtY1, 0, "S_DPLSIA_DlcLeLDW_met:");
		font.SetTextColor( colorLime.r, colorLime.g, colorLime.b, colorLime.a);
		font.RenderTextf(drawAtX1_2, drawAtY1, 0, "%4.4f m", m_LCF_SenDebugData.LCF_stSenDbgData.LDPSA_SenDbgData.DPLSIA_SenDbgData.S_DPLSIA_DlcLeLDW_met); 
		drawAtY1+=drawStep;
		
		/* TEST */
		/* font.SetTextColor( colorWhite.r, colorWhite.g, colorWhite.b, colorWhite.a);
        font.RenderTextf(drawAtX1_1, drawAtY1, 0, "D_TCTCDC_EstiCurHeading_rad:");
		font.SetTextColor( colorLime.r, colorLime.g, colorLime.b, colorLime.a);
		font.RenderTextf(drawAtX1_2, drawAtY1, 0, "%4.4f", m_LCF_VehDebugData.LCF_pstVehDbgData.TRJCTR_VehDbgData.TCTCDC_VehDbgData.D_TCTCDC_EstiCurHeading_rad); 
		drawAtY1+=drawStep; */
		
		//MFC4xx Device.LCF_VEH.pLcfVehDebugData.LCF_pstVehDbgData.TRJCTR_VehDbgData.TCTCDC_VehDbgData.D_TCTCDC_EstiCurHeading_rad
		//MFC4xx Device.LCF_SEN.pLcfSenDebugData.LCF_stSenDbgData.LDPSA_SenDbgData.DPLSIA_SenDbgData.S_DPLSIA_DlcLeLDW_met
		//m_LCF_VehDebugData.LCF_pstVehDbgData.TRJPLN_VehDbgData.TPLLCO_VehDbgData.D_TPLLCO_DeltaProj_metY_met
		//m_LCF_SenDebugData.LCF_stSenDbgData.ABPR_SenDbgData.ABPLBP_SenDbgData.S_ABPLBP_CntrLnClthLength_met
		//m_LCF_VehDebugData.LCF_pstVehDbgData.TRJPLN_VehDbgData.TPLLCO_VehDbgData.D_TPLLCO_DeltaProj_metX_met
		
		drawAtY1+=drawStep;

		/* LaneValidQualifier_nu */
#ifdef LCF_MFC431_RELEASE_0800_RTE_INT01	
	ui8LaneValidQual = m_LcfSenOutputData.Visualization.LaneValidQualVis_nu; 
	font.SetTextColor( colorWhite.r, colorWhite.g, colorWhite.b, colorWhite.a);
	font.RenderTextf(drawAtX1_1, drawAtY1, 0, "LaneValidQualifier:");
	if ((ui8LaneValidQual == E_ABPLBP_LQ_LE_EGO_LN_VIRTUAL) ||
		(ui8LaneValidQual == E_ABPLBP_LQ_RI_EGO_LN_VIRTUAL))
		font.SetTextColor( colorRed.r, colorRed.g, colorRed.b, colorRed.a);
	else
		font.SetTextColor( colorLime.r, colorLime.g, colorLime.b, colorLime.a);
	font.RenderTextf(drawAtX1_2, drawAtY1, 0, LaneValidQualifToString(ui8LaneValidQual, debugString));
	drawAtY1+=drawStep;
	drawAtY1+=drawStep;

	/* ABD parallel mode */
	font.SetTextColor( colorWhite.r, colorWhite.g, colorWhite.b, colorWhite.a);
	font.RenderTextf(drawAtX1_1, drawAtY1, 0, "ABD Parallel Mode:");
	font.SetTextColor( colorLime.r, colorLime.g, colorLime.b, colorLime.a);
	font.RenderTextf(drawAtX1_2, drawAtY1, 0, LDParallelModeToString(m_AbdOutputData.eParallelModelActive, debugString));
	drawAtY1+=drawStep;
#else
	ui8LaneValidQual = m_LcfSenOutputData.Visualization.LaneValidQualifier_nu;
	
/* 	Visu Bitfield: 

	Bit 0: Left lane valid only
	Bit 1: Right lane valid only 
	Bit 2: Left lane bridged
	Bit 3: Right lane bridged 
	Bit 4: Left lane LD virtual 
	Bit 5: Right lane LD virtual
	Bit 6:  Both lane markers valid
	Bit 7:  */
	font.SetTextColor( colorWhite.r, colorWhite.g, colorWhite.b, colorWhite.a);
	font.RenderTextf(drawAtX1_1, drawAtY1, 0, "LaneValidQualifier:");
	if (ui8LaneValidQual != 0 ) //E_ABPLBP_LQ_BOTH_EGO_LN_VALID
		font.SetTextColor( colorLime.r, colorLime.g, colorLime.b, colorLime.a);
	else
		font.SetTextColor( colorRed.r, colorRed.g, colorRed.b, colorRed.a);
		
	font.RenderTextf(drawAtX1_2, drawAtY1, 0, LaneValidQualifToString(ui8LaneValidQual, debugString));
	drawAtY1+=drawStep;
	drawAtY1+=drawStep;

	/* ABD parallel mode */
	font.SetTextColor( colorWhite.r, colorWhite.g, colorWhite.b, colorWhite.a);
	font.RenderTextf(drawAtX1_1, drawAtY1, 0, "ABD Parallel Mode:");
	font.SetTextColor( colorLime.r, colorLime.g, colorLime.b, colorLime.a);
	font.RenderTextf(drawAtX1_2, drawAtY1, 0, LDParallelModeToString(m_AbdOutputData.eParallelModelActive, debugString));
	drawAtY1+=drawStep;
	
#endif

	}

	font.EndRender2D();
}


bool CSimLcfVis::OnKeyboardMessage(const ISimRenderContext& context, const ISimWindowMessage& windowMessage)
{
	unsigned int iMsgId = windowMessage.GetMessageId();
	unsigned int wKey = static_cast<unsigned int>(windowMessage.GetWParam());

	if(iMsgId != WM_KEYDOWN)
		return false;
	 switch(wKey)
	 {
    case 'L':
      if(!(GetKeyState(VK_SHIFT) & 0x8000))
        DebugSelect = 1;
      break;
    case 'W':
      if(!(GetKeyState(VK_SHIFT) & 0x8000))
        DebugSelect = 2;
      break;
    case 'T':
      if(!(GetKeyState(VK_SHIFT) & 0x8000))
        DebugSelect = 3;
	  break;
    case 'R':
      if(!(GetKeyState(VK_SHIFT) & 0x8000))
        DebugSelect = 4;
      break;
    case 'C':
      if(!(GetKeyState(VK_SHIFT) & 0x8000))
        DebugSelect = 5;
      break;
    case 'I':
      if(!(GetKeyState(VK_SHIFT) & 0x8000))
        DebugSelect = 6;
      break;
    case 'E':
      if(!(GetKeyState(VK_SHIFT) & 0x8000))
        DebugSelect = 7;
      break;
    case 'P':
      if(!(GetKeyState(VK_SHIFT) & 0x8000))
        DebugSelect = 8;
      break;
    case 'D':
      if(!(GetKeyState(VK_SHIFT) & 0x8000))
        DebugSelect = 9;
	  break;
    case 'O':
      if(!(GetKeyState(VK_SHIFT) & 0x8000))
        DebugSelect = 10;
      break;
    case 'M':
      if(!(GetKeyState(VK_SHIFT) & 0x8000)) {
		  SelectTrajDraw = SelectTrajDraw + 1;
	  }
	  SelectTrajDraw = SelectTrajDraw % 4;
      break;
    case 'H':
      if(!(GetKeyState(VK_SHIFT) & 0x8000))
		  m_bDrawHelp = !m_bDrawHelp;
      break;
    case VK_HOME:
      if(!(GetKeyState(VK_SHIFT) & 0x8000)) {
		  m_ResolutionMode = m_ResolutionMode + 1;
	  }
	  m_ResolutionMode = m_ResolutionMode % 2;
      break;
    case '1':
      if(!(GetKeyState(VK_SHIFT) & 0x8000))
		  BitfiledSel_idx = 1;
      break;
    case '2':
      if(!(GetKeyState(VK_SHIFT) & 0x8000))
		  BitfiledSel_idx = 2;
      break;
    case '3':
      if(!(GetKeyState(VK_SHIFT) & 0x8000))
		  BitfiledSel_idx = 3;
      break;
    case '4':
      if(!(GetKeyState(VK_SHIFT) & 0x8000))
		  BitfiledSel_idx = 4;
      break;
    case '5':
      if(!(GetKeyState(VK_SHIFT) & 0x8000))
		  BitfiledSel_idx = 5;
      break;
    case '6':
      if(!(GetKeyState(VK_SHIFT) & 0x8000))
		  BitfiledSel_idx = 6;
      break;
    case '7':
      if(!(GetKeyState(VK_SHIFT) & 0x8000))
		  BitfiledSel_idx = 7;
      break;
    case '8':
      if(!(GetKeyState(VK_SHIFT) & 0x8000))
		  BitfiledSel_idx = 8;
      break;
    case '9':
      if(!(GetKeyState(VK_SHIFT) & 0x8000))
		  BitfiledSel_idx = 9;
      break;
    case VK_NUMPAD0: /*	Numpad 0 */
      if(!(GetKeyState(VK_SHIFT) & 0x8000))
		  BitfiledSel_idx = 10;
      break;
    case VK_NUMPAD1: /*	Numpad 1 */
      if(!(GetKeyState(VK_SHIFT) & 0x8000))
		  BitfiledSel_idx = 11;
      break;
    case VK_NUMPAD2: /*	Numpad 2 */
      if(!(GetKeyState(VK_SHIFT) & 0x8000))
		  BitfiledSel_idx = 12;
      break;
    case VK_NUMPAD3: /*	Numpad 3 */
      if(!(GetKeyState(VK_SHIFT) & 0x8000))
		  BitfiledSel_idx = 13;
      break;
    case VK_NUMPAD4: /*	Numpad 4 */
      if(!(GetKeyState(VK_SHIFT) & 0x8000))
		  BitfiledSel_idx = 14;
      break;
    case VK_NUMPAD5: /*	Numpad 5 */
      if(!(GetKeyState(VK_SHIFT) & 0x8000))
		  BitfiledSel_idx = 15;
      break;
    case VK_NUMPAD6: /*	Numpad 6 */
      if(!(GetKeyState(VK_SHIFT) & 0x8000))
		  BitfiledSel_idx = 16;
      break;
    case VK_NUMPAD7: /*	Numpad 7 */
      if(!(GetKeyState(VK_SHIFT) & 0x8000))
		  BitfiledSel_idx = 17;
      break;
    case VK_NUMPAD8: /*	Numpad 8 */
      if(!(GetKeyState(VK_SHIFT) & 0x8000))
		  BitfiledSel_idx = 18;
      break;
    case VK_NUMPAD9: /*	Numpad 9 */
      if(!(GetKeyState(VK_SHIFT) & 0x8000))
		  BitfiledSel_idx = 19;
      break;
    case 'S': /* 'S' key */
      if(!(GetKeyState(VK_SHIFT) & 0x8000))
		  ERRIO_Select = 1;
      break;
    case 'V': /* 'V' key */
      if(!(GetKeyState(VK_SHIFT) & 0x8000))
		  ERRIO_Select = 2;
      break;
	default:
      return false;
	}

	return true;
}

void CSimLcfVis::DrawHelp( IGDVFont& font, IGDVFont& titlefont)
{
  const int iNum = 21;
  const unsigned int x_coor = 25;
  unsigned char step = 1;

  GL::Pixel pxlCenter(237.5f, 505.0f);

  const int iBoxWidthParam = 445;
  const int iBoxHeightParam = 630;

  GL::PixelRect box = GL::PixelRect::CenterBox(pxlCenter, iBoxWidthParam, iBoxHeightParam);
  GL::Draw( box,  GL::Color(colorLightGray.r, colorLightGray.g, colorLightGray.b, colorLightGray.a));
  GL::Color clrTmp = GL::Color::white;

  titlefont.BeginRender2D();
  titlefont.SetTextColor( colorGreen.r, colorGreen.g, colorGreen.b, colorGreen.a);
  titlefont.RenderTextf(x_coor + 105, 208, 0, "Select Debug Signals");
  titlefont.EndRender2D();

  font.BeginRender2D();
  font.SetTextColor( colorBlue.r, colorBlue.g, colorBlue.b, colorBlue.a);
  font.RenderTextf(x_coor, 218 + iNum * step++, 0, "'L': LDP Signals            'W': LDW Signals");
  font.RenderTextf(x_coor, 218 + iNum * step++, 0, "'R': RDP Signals            'T': TJA Signals");
  font.RenderTextf(x_coor, 218 + iNum * step++, 0, "'C': Custom Specific Debug Signals");
  #if (GET_LCF_PRJ_NR() == GET_LCFPRJ_MFC431LO19())
	 font.RenderTextf(x_coor + 10, 218 + iNum * step++, 0, "-'1':PrecondOk  -'2':PrjSpec  -'3':HMOLCO_SysStHWA ");
  #elif (GET_LCF_PRJ_NR() == GET_LCFPRJ_MFC431TA19())
	 font.RenderTextf(x_coor + 10, 218 + iNum * step++, 0, "-'1':CTR   -'2':LDA   -'3':LTA   -'4':HMICancel ");
  #endif
  font.RenderTextf(x_coor, 218 + iNum * step++, 0, "'I': LCF Input Signals");
  font.RenderTextf(x_coor + iNum, 218 + iNum * step++, 0, "-'1': ABD Signals          -'2': VDY Signals");
  font.RenderTextf(x_coor + iNum, 218 + iNum * step++, 0, "-'3..7': LCF Gen Inputs 1..5");
  font.RenderTextf(x_coor, 218 + iNum * step++, 0, "'Home': Change font size / resolution");
  font.RenderTextf(x_coor, 218 + iNum * step++, 0, "'E': Error Handler Debug Signals");
  font.RenderTextf(x_coor, 218 + iNum * step++, 0, "'P': LCF Integration Debug Signals / Statistics");
  font.RenderTextf(x_coor, 218 + iNum * step++, 0, "'D': DRVMN Debug Signals / LCF Scheduler Info");
  font.RenderTextf(x_coor, 218 + iNum * step++, 0, "'O': LCF Output Signals");
  font.RenderTextf(x_coor + iNum, 218 + iNum * step++, 0, "-'1': LCF SEN Output Signals");
  font.RenderTextf(x_coor + iNum, 218 + iNum * step++, 0, "-'2': LCF SenToVeh Signals");
  font.RenderTextf(x_coor + iNum, 218 + iNum * step++, 0, "-'3': LCF VEH Output Signals");
  font.RenderTextf(x_coor + iNum, 218 + iNum * step++, 0, "-'4': LCF VehToSen Signals");
  font.RenderTextf(x_coor, 218 + iNum * step++, 0, "'M': Show Lane / Trajectory Mode");
  font.RenderTextf(x_coor + iNum, 218 + iNum * step++, 0, "-'0': Both/Center/Trajectory    -'1': Both/Center");
  font.RenderTextf(x_coor + iNum, 218 + iNum * step++, 0, "-'2': Both/Trajectory        -'3': Trajectory only");

  font.RenderTextf(x_coor, 218 + iNum * step++, 0, "'L' / 'W' / 'R' / 'T': Bitfield Info");
  font.RenderTextf(x_coor + 14 , 218 + iNum * step++, 0, "-'1': SysState      -'2': SR       -'3': WR");
  font.RenderTextf(x_coor + 14, 218 + iNum * step++, 0,  "-'4': Cancel        -'5': SideCondLe / TJA_LnCen");
  font.RenderTextf(x_coor + 14, 218 + iNum * step++, 0,  "-'6': SideCondLe / TJA_ObjFollow   -'7': ABPR_LeLn");
  font.RenderTextf(x_coor + 14, 218 + iNum * step++, 0,  "-'8': ABPR_RiLn     -'9': Specific / TJA_Combined");
  font.RenderTextf(x_coor + 14, 218 + iNum * step++, 0,  "-'NUM1': VDPR_VehState     -'NUM2': VDPR_DrvState");
  font.RenderTextf(x_coor + 14, 218 + iNum * step++, 0,  "-'NUM3': VDPR_ActStCtrl    -'NUM4': SysNotAvail");
  font.RenderTextf(x_coor + 14, 218 + iNum * step++, 0,  "-'NUM5': SysStError    -'NUM6/7': ABPR_LeRe/RiRe");

  font.EndRender2D();
}

static void DrawTable(float *X_coord_points, float Y_coord_1, int drawStep, unsigned char no_of_horiz_lines, unsigned char no_of_vert_lines, unsigned char type = 0)
{

	glBegin(GL_LINES);
	glColor3f(1.0f, 1.0f, 0.0f); //yellow
	unsigned char h_line = 0;

	if (type == 2) /* Highlight the cells where SysStates Signals are plotted */
	{
		for (h_line = 0; h_line < no_of_horiz_lines; h_line++) {
			glVertex2f( X_coord_points[0] - 1, Y_coord_1 + h_line * drawStep); // x1,y1
			glVertex2f( X_coord_points[2] + 1, Y_coord_1 + h_line * drawStep); // x2,y2
		}
		for(unsigned char idx_v_line = 0; idx_v_line <= no_of_vert_lines; idx_v_line += 2) {
			glVertex2f(X_coord_points[idx_v_line] + 40 - Y_coord_1, Y_coord_1 - 1); // x1,y1
			glVertex2f(X_coord_points[idx_v_line] + 40 - Y_coord_1, Y_coord_1 + (h_line-1) * drawStep); //x2,y2
		}
	}
	else {
		for (h_line = 0; h_line < no_of_horiz_lines; h_line++) {
			glVertex2f( X_coord_points[0], Y_coord_1 + h_line * drawStep); // x1,y1
			glVertex2f( X_coord_points[no_of_vert_lines-1], Y_coord_1 + h_line * drawStep); // x2,y2
		}
	
		for(unsigned char idx_v_line = 0; idx_v_line < no_of_vert_lines; idx_v_line++) 
		{
			if (type == 1)
			{
				if ((idx_v_line == 0) || (idx_v_line == no_of_vert_lines - 1)) {
					glVertex2f(X_coord_points[idx_v_line], Y_coord_1); // x1,y1
				}
				else {
					glVertex2f(X_coord_points[idx_v_line], Y_coord_1 + drawStep); // x1,y1
				}
				glVertex2f(X_coord_points[idx_v_line], Y_coord_1 + (h_line-1) * drawStep); //x2,y2
			}
			else {
				glVertex2f(X_coord_points[idx_v_line], Y_coord_1); // x1,y1
				glVertex2f(X_coord_points[idx_v_line], Y_coord_1 + (h_line-1) * drawStep); //x2,y2
			}
		}
	}
	glEnd();
}

void CSimLcfVis::DrawTextLCF(int x_coord, int y_coord, unsigned short offset, RGBAColor & colorTxt, RGBAColor & colorVal, std::string const & sText, IGDVFont& rFont, const char *value, const unsigned char InfoKey)
{
	char debugString[100];
	char BufferText[25];

	const static string Info_eSigStatus[3] = {"INIT", "OK", "INVALID"}; /* 36 */
	const static string Info_eCompState[7] = {"Not Initialized", "Running", "Temp Error", "Perm Error", "Success", "Reduced Avail", "Not Running"}; /* 21 */
	const static string Info_LatCtrlModeTJA_nu[9] = {"Passive", "Lane Center", "Obj Follow", "Combined", "SALC", "LC_Req", "OF_Req", "CMB_Req", "SALC_Req"}; /* 22 */
	const static string Info_BndValidType[4] = {"No Valid Lane", "Left Valid", "Right Valid", "Both Valid"}; /* 23 */
	const static string Info_MotState[4] = {"MOVE", "MOVE_FWD", "MOVE_RWD", "STANDSTILL"}; /* 25 */
	const static string Info_TurnSignalVDY[5] = {"UNKNOWN", "LEFT", "RIGHT", "NEUTRAL", "BOTH"}; /* 26 */
	const static string Info_WiperStage[7] = {"OFF", "INTERVAL1", "INTERVAL2", "INTERVAL3", "INTERVAL4", "STAGE1", "STAGE2"}; /* 27 */
	const static string Info_WiperState[2] = {"INACTIVE", "ACTIVE"}; /* 28 */
	const static string Info_ActGearPos[4] = {"NEUTRAL", "PARKING", "FORWARD", "REVERSE"}; /* 29 */
	const static string Info_TrailerConnectionVDY[4] = {"NO_DETECT", "OK", "NDEF2", "SNA"}; /* 30 */
	const static string Info_DangerousSide_nu[3] = {"None", "LEFT", "RIGHT"}; /* 31 */
	const static string Info_eLaneChange[4] = {"Unknown", "Left", "Right", "Unchanged"}; /* 33 */
	const static string Info_LaDMCStatus[7] = {"OFF", "ON", "DrvSupSteer", "DrvCntSt", "Perm_Disbled", "Temp_Disabled", "Request"}; /* 35 */

	rFont.SetTextColor( colorTxt.r, colorTxt.g, colorTxt.b, colorTxt.a);
	rFont.RenderTextf(x_coord, y_coord, 0, sText.c_str());

	rFont.SetTextColor( colorVal.r, colorVal.g, colorVal.b, colorVal.a);
	if (InfoKey >= 10 && InfoKey <= 19) {
		sprintf(debugString, "%s  (Press Num %d)", value, InfoKey - 10);
	}
	else if ((InfoKey < 10) && (InfoKey != 0)) {
		sprintf(debugString, "%s  (Press %d for info)", value, InfoKey);
	}
	else if (InfoKey == 20 && (atoi(value) >= 0 && atoi(value) < 11)) { /* MFC431VA10 => Pos 10 in vector */
		sprintf(debugString, "%s  ( %s )", value, GetProjectName(atoi(value), BufferText));
	}
	else if (InfoKey == 21 && (atoi(value) >= 0 && atoi(value) < 9)) {
		sprintf(debugString, "%s  ( %s )", value, Info_eCompState[atoi(value)].c_str());
	}
	else if (InfoKey == 22 && (atoi(value) >= 0 && atoi(value) < 4)) {
		sprintf(debugString, "%s  ( %s )", value, Info_LatCtrlModeTJA_nu[atoi(value)].c_str());
	}
	else if (InfoKey == 23 && (atoi(value) >= 0 && atoi(value) < 7)) {
		sprintf(debugString, "%s  ( %s )", value, Info_BndValidType[atoi(value)].c_str());
	}
	else if (InfoKey == 25 && (atoi(value) >= 0 && atoi(value) < 4)) {
		sprintf(debugString, "%s  ( %s )", value, Info_MotState[atoi(value)].c_str());
	}
	else if (InfoKey == 26 && (atoi(value) >= 0 && atoi(value) < 5)) {
		sprintf(debugString, "%s  ( %s )", value, Info_TurnSignalVDY[atoi(value)].c_str());
	}
	else if (InfoKey == 27 && (atoi(value) >= 0 && atoi(value) < 7)) {
		sprintf(debugString, "%s  ( %s )", value, Info_WiperStage[atoi(value)].c_str());
	}
	else if (InfoKey == 28 && (atoi(value) >= 0 && atoi(value) < 2)) {
		sprintf(debugString, "%s  ( %s )", value, Info_WiperState[atoi(value)].c_str());
	}
	else if (InfoKey == 29 && (atoi(value) >= 0 && atoi(value) < 4)) {
		sprintf(debugString, "%s  ( %s )", value, Info_ActGearPos[atoi(value)].c_str());
	}
	else if (InfoKey == 30 && (atoi(value) >= 0 && atoi(value) < 4)) {
		sprintf(debugString, "%s  ( %s )", value, Info_TrailerConnectionVDY[atoi(value)].c_str());
	}
	else if (InfoKey == 31 && (atoi(value) >= 0 && atoi(value) < 3)) {
		sprintf(debugString, "%s  ( %s )", value, Info_DangerousSide_nu[atoi(value)].c_str());
	}
	else if (InfoKey == 33 && (atoi(value) >= 0 && atoi(value) < 4)) {
		sprintf(debugString, "%s  ( %s )", value, Info_eLaneChange[atoi(value)].c_str());
	}
	else if (InfoKey == 35 && (atoi(value) >= 0 && atoi(value) < 7)) {
		sprintf(debugString, "%s  ( %s )", value, Info_LaDMCStatus[atoi(value)].c_str());
	}
	else if (InfoKey == 36 && (atoi(value) >= 0 && atoi(value) < 3)) {
		sprintf(debugString, "%s  ( %s )", value, Info_eSigStatus[atoi(value)].c_str());
	}
	else {
		sprintf(debugString, "%s", value);
	}
	rFont.RenderTextf(x_coord + offset, y_coord, 0, debugString);

}


const char* CSimLcfVis::GetProjectName(unsigned char ProjectNo, char* debs)
{
    memset(debs, 0, sizeof(debs));

	const static string Project_Index[11] = {"UNKNOWN", "MFC431", "MFC430HI19", "MFC431TA19", "MFC431HI28", "MFC431LO19", "MFC431SC19", "MFC510", "MFC520", "MFC431SW19", "MFC431VA10"};

	sprintf(debs, "%s", (ProjectNo < 11) ? Project_Index[ProjectNo].c_str() : Project_Index[0].c_str());
    return debs;
}


void CSimLcfVis::StatisticalData(unsigned int Timestamp, LCF_e_FctSystemState_t *FunctionSysState)
{
	static unsigned int Prev_Timestamp;
	static unsigned char Prev_SysState[SizeStatisticalArray] = {0,0,0,0,0};
	unsigned char index;

	if (Prev_Timestamp != Timestamp)
	{
		for (index = 0; index < SizeStatisticalArray; index++)
		{
			if ((FunctionSysState[index] == 4) && (Prev_SysState[index] != 4)) {
				m_Function_Activation_Number[index] += 1;
			}
			Prev_Timestamp = Timestamp;
			Prev_SysState[index] = FunctionSysState[index];
		}
	}
}

void CSimLcfVis::LCF_SchedulerData(LCF_Scheduler_Check_t &Scheduler_Info, unsigned int Timestamp, unsigned short CycleCounter, float TaskCycleTime)
{

	/* 
	This function is designed to check if Global Schedule is working fine and calls LCF VEH / LCF SEN at correct interval of time.
	Based on Actual Timestamp / Cycle Counter for Output Ports ( LCF SEN Output / LCF VEH Output ) and previous values is determined if one of bellow situation :
	- Tasks are skipped and count how many times this is happen.
	- Identify if GS calls components with the same timestamp.
	- Calculate the Average Cycle Time.
	- Plot on SIM DRAW the Instant cycle time ( time between two LCF VEH / LCF SEN calls ) 
	*/

	/* Reset the flags for current frame */
	Scheduler_Info.CycleCounterBlocked = 0;
	Scheduler_Info.TimestampBlocked = 0;

	if ((Scheduler_Info.Prev_TS_Value == 0) && (Scheduler_Info.Prev_CC_Value == 0)) /* First Frame : Need to take relevant data from the current timestamp */
	{
		Scheduler_Info.Prev_TS_Value = Timestamp;
		Scheduler_Info.Prev_CC_Value = CycleCounter;
	}
	else
	{
		if ((Scheduler_Info.Prev_TS_Value != Timestamp) && (Scheduler_Info.Prev_CC_Value != CycleCounter)) /* A relevant cycle is gone */
		{
			/* Treat a very probably overflow in timestamp / cycle counter signals : If overflow identified, then skip the current frame */
			if ((Scheduler_Info.IgnoreFrame == 0) && (((Scheduler_Info.Prev_TS_Value > 4150000000) && (Timestamp < 20000000 )) || ((Scheduler_Info.Prev_CC_Value > 62000) && (CycleCounter < 100))))
			{
				Scheduler_Info.IgnoreFrame = 1; 
			}

			if (Scheduler_Info.IgnoreFrame != 1)
			{
				Scheduler_Info.Total_TS_Value += Timestamp - Scheduler_Info.Prev_TS_Value;
				Scheduler_Info.Total_CC_Value += CycleCounter - Scheduler_Info.Prev_CC_Value;

				if (Scheduler_Info.Total_CC_Value > 0) /* Treat the case when the user is moving the cursor at the start of rrec file : */
				{
					Scheduler_Info.AverageCycleTime = (unsigned int)(Scheduler_Info.Total_TS_Value / Scheduler_Info.Total_CC_Value);		
				}

				/* If a jump is not detected, then count the TS difference */ 
				if (ABS((signed int)(Timestamp - Scheduler_Info.Prev_TS_Value)) < 500000 ) 
				{
					Scheduler_Info.Instant_TS_Difference = (Timestamp - Scheduler_Info.Prev_TS_Value) / (CycleCounter - Scheduler_Info.Prev_CC_Value);

					/* Check if a task is skipped based on Cycle time difference. Value 1 : Execution works ok. Value > 1 : Number of skipped task = Value - 1 */
					if(CML_u_Round2Uint(((float)(Scheduler_Info.Instant_TS_Difference) / 1000.0f) / TaskCycleTime) > 1)
					{
						Scheduler_Info.NumberOfSkippedFrames += (CML_u_Round2Uint(((float)(Scheduler_Info.Instant_TS_Difference) / 1000.0f) / TaskCycleTime) - 1);
					}

					if (Scheduler_Info.Total_TS_Value != 0) /* Probably not necessary, but just to be sure when user is moving the cursor again at the start of rrec */
					{
						/* Get the percentage of skipped frames. Total_TS_Value need to be converted to ms ( default us ) and also the num of skipped frames need to be calculated based on task cycle time */ 
						Scheduler_Info.PercentageOfSkippedFrames = (float)((((float)Scheduler_Info.NumberOfSkippedFrames * TaskCycleTime) / ((float)Scheduler_Info.Total_TS_Value / 1000.0f)) * 100.0f);
					}

					/* If size > 10 -> Then erase the first element in queue */
					if (Scheduler_Info.Buffer_Inst_TS_Difference.size() >= 11)
					{
						Scheduler_Info.Buffer_Inst_TS_Difference.pop();
					}
					Scheduler_Info.Buffer_Inst_TS_Difference.push(Scheduler_Info.Instant_TS_Difference);
				
				}
			}
			else
			{
				Scheduler_Info.IgnoreFrame = 0;
			}
			/* Update data for prevCycle with current value to be used in the next function call */
			Scheduler_Info.Prev_TS_Value = Timestamp;
			Scheduler_Info.Prev_CC_Value = CycleCounter;
		}
		else if ((Scheduler_Info.Prev_TS_Value != Timestamp) && (Scheduler_Info.Prev_CC_Value == CycleCounter))
		{
			Scheduler_Info.CycleCounterBlocked = 1; /* If TS different than previous, but the cycle counter is the same -> keep the event to be plotted */
		}
		else if ((Scheduler_Info.Prev_TS_Value == Timestamp) && (Scheduler_Info.Prev_CC_Value != CycleCounter))
		{
			Scheduler_Info.TimestampBlocked = 1; /* If CC different than previous, but the timestamp is the same -> keep the event to be plotted */
		}
		else
		{
		 /* Nothing to do for the moment. Just wait for the next frame... */
		}
	}
}

void CSimLcfVis::DrawLCFTableDebug(const ISimRenderContext& ctx)
{
	GL::Init();

	unsigned int col1_coord = 30;
	unsigned int col2_coord = 305;
	unsigned int col3_coord = 475;
	unsigned int col4_coord = 758;
	unsigned short row_coord_increment = 30;

	unsigned char textsize = 10;
	unsigned char versionsize = 11;
	unsigned char helpsize = 10;

	if(m_ResolutionMode)
	{
		textsize = 8;
		versionsize = 9;
		helpsize = 8;
	}	

	char debugString[100];
	float X_coord_table[] = {15, 295, 460, 745, 910};

	DrawTable(X_coord_table, 40.0f, row_coord_increment, 27, 5);
	DrawTable(X_coord_table, 39.0f, 150, 2, 2, 2);
	DrawTable(X_coord_table, 38.0f, 150, 2, 2, 2);

	std::vector <std::string> SysState_Names;
	SysState_Names.push_back("SysStateTJA       (key 'T' for debug)");
	SysState_Names.push_back("SysStateLDP       (key 'L' for debug)");
	SysState_Names.push_back("SysStateLDW       (key 'W' for debug)");
	SysState_Names.push_back("SysStateRDP       (key 'R' for debug)");
	SysState_Names.push_back("SysStateLDPOC");
	
	LCF_e_FctSystemState_t Signal_Vect[SizeStatisticalArray] = {m_rp_SysStateTJA_nu.val(), m_rp_SysStateLDP_nu.val(), m_rp_SysStateLDW_nu.val(), m_rp_SysStateRDP_nu.val(), m_rp_SysStateLDPOC_nu.val()};

	IGDVFont& Versionfont = ctx.GetWindow().GetFontInterface("Arial", versionsize, 0.0F, FW_BOLD);
	Versionfont.BeginRender2D();
	DrawTextLCF(25, 10, 240, colorYellow, colorYellow, "VIS dll compiled for LCF Version: ", Versionfont, LCF_CHECKPOINT);
	DrawTextLCF(445, 10, 65, colorYellow, colorYellow, ", Project: ", Versionfont, GetProjectName(LCF_PRJ_NR, debugString));
	Versionfont.EndRender2D();

	IGDVFont& AuxFont = ctx.GetWindow().GetFontInterface("Arial", helpsize, 0.0F, FW_BOLD);
	AuxFont.BeginRender2D();
	DrawTextLCF(750, 10, 38, colorRed, colorRed, "Press ", AuxFont, "'H' for help menu");
	AuxFont.EndRender2D();

	IGDVFont& font = ctx.GetWindow().GetFontInterface("Arial", textsize, 0.0F, FW_BOLD);
	font.BeginRender2D();

	/* Populate table with signal / values */
	for(unsigned char signal_no = 0; signal_no < 5; signal_no++) {
		DrawTextLCF(col1_coord, 45 + signal_no * row_coord_increment, 275, colorWhite, (Signal_Vect[signal_no] == 4)?colorRed:colorLime, SysState_Names[signal_no], font, LcofSysStateToString(Signal_Vect[signal_no], debugString));
	}

	bool OutputDataValidity[5] = {m_bLcfSenOutputDataValid, m_bLcfSenOutputToVehDataValid, m_bLcfVehOutputDataValid, m_bLcfVehOutputToSenDataValid, (m_bLCFSenAlgoCompState && m_bLCFVehAlgoCompState)};

	/* Collect statistical Data -> Function Activation Number */
	StatisticalData(m_rp_Sen2Veh_uiTimeStamp.val(), Signal_Vect);

	switch(DebugSelect)
	{
	case 6:
		switch(BitfiledSel_idx)
		{
		case 0:
		case 1:
			if (m_bAbdOutputDataValid) {
				Add_LD_Signals(font, 195, col1_coord, col2_coord, row_coord_increment, m_rpAbdOutputData.isConnected());
			}
			break;
		case 2:
			if (m_bVehDynValid && m_bVehSigValid && m_bVehParValid) {
				Add_VehDyn_Signals(font, 195, col1_coord, unsigned short(col2_coord - col1_coord), row_coord_increment, (m_rpVehDyn.isConnected() && m_rpVehSig.isConnected()));
			}
			break;
		case 3:
		case 4:
		case 5:
		case 6:
		case 7:
			if (m_bLcfInputDataValid) {
				Add_LcfGenPort_Signals(font, 195, col1_coord, unsigned short(col2_coord - col1_coord), row_coord_increment, BitfiledSel_idx-2);
			}
			break;
		default:
			break;
		}
		break;
	case 10:
		if (BitfiledSel_idx < 6) {
			Add_Output_Signals(font, 195, col1_coord, unsigned short(col2_coord - col1_coord), row_coord_increment, BitfiledSel_idx, OutputDataValidity);
		}
		break;
	default:
		break;
	}

	//check if ports are valid
	if(m_bLCFVehDebugDataValid && m_bLCFSenDebugDataValid)
	{ 
		 if ((DebugSelect != 0) && (DebugSelect < 6)) {
			 Add_Common_Debug_Signals(font, 195, col1_coord, unsigned short(col2_coord - col1_coord), row_coord_increment, true);
		 }
		 switch(DebugSelect)
		 {
			case 1:
				Add_LDP_Debug_Signals(font, 45, col3_coord, unsigned short(col4_coord - col3_coord), row_coord_increment, true);
				break;
			case 2:
				Add_LDW_Debug_Signals(font, 45, col3_coord, unsigned short(col4_coord - col3_coord), row_coord_increment, true);
    			break;
			case 3:
				Add_TJA_Debug_Signals(font, 45, col3_coord, unsigned short(col4_coord - col3_coord), row_coord_increment, true);
    			break;
			case 4:
				Add_RDP_Debug_Signals(font, 45, col3_coord, unsigned short(col4_coord - col3_coord), row_coord_increment, true);
    			break;
			case 5:
				Add_Customer_Signals(font, 45, col3_coord, unsigned short(col4_coord - col3_coord), row_coord_increment, true);
				break;
			case 7:
				Add_ErrorHandler_Debug_Signals(font, 195, col1_coord, unsigned short(col2_coord - col1_coord), row_coord_increment, true);
    			break;
			case 8:
				Add_LCFIntegration_Debug_Signals(font, 195, col1_coord, unsigned short(col2_coord - col1_coord), row_coord_increment, true);
    			break;
			case 9:
				Add_DRVMN_Debug_Signals(font, 195, col1_coord, unsigned short(col2_coord - col1_coord), row_coord_increment, true);
    			break;
			default:
				break;
		 }
	}

	font.EndRender2D();

	if(m_bDrawHelp)
	{
		if (!m_ResolutionMode) {
			DrawHelp(ctx.GetWindow().GetFontInterface( "Courier New", 10, 0.0F, FW_BOLD), ctx.GetWindow().GetFontInterface("Courier New", 12, 0.0F, FW_BOLD, False, True));
		}
		else {
			DrawHelp(ctx.GetWindow().GetFontInterface( "Courier New", 8, 0.0F, FW_BOLD), ctx.GetWindow().GetFontInterface("Courier New", 10, 0.0F, FW_BOLD, False, True));
		}
	}

}

void CSimLcfVis::Get_Bitfield_Information(LCF_Bitfield_Info &Structure, unsigned int Signal_Value, string Name, const STRINGLIST &Info_Signal, unsigned char size, bool PortConnected = true, unsigned char IgnoreBit = 0)
{
	Structure.signal_name = Name;
	Structure.Bitfield_Value = Signal_Value;
	Structure.Is_Connected = PortConnected;
	
	if(size >= Info_Signal.size()) {
		size = Info_Signal.size() - 1;
	}

	for (int i=1; i <= size; i++)
	{
		if (((IgnoreBit & (1 << (i-1))) == 0) || (IgnoreBit == 0)) {
			Structure.Description.push_back((!Info_Signal[i].empty()) ? (Info_Signal[i]) : ("No Info in CSV"));
		}
	}
}

void CSimLcfVis::DrawLCFBitfieldInfo(const ISimRenderContext& ctx)
{
	GL::Init();

	char debugString[100];
	char debugString_2[100];
	static float X_coord_table_2[] = {10, 85, 160, 460};
	static float X_coord_General_Table[] = {10, 245, 475};
	unsigned char textsize = 11;
	char Signal_Name_ERRIO[50];

	if(m_ResolutionMode) {
		textsize = 9;
	}

	DrawTable(X_coord_table_2, 100.0f, 25, 34, 4, 1); /* Bitfield table */
	DrawTable(X_coord_General_Table, 10.0f, 25, 4, 3, 0); /* General Table always visible : Contains LCF / DPU version, GS information */

	IGDVFont& General_font = ctx.GetWindow().GetFontInterface("Arial", textsize-1, 0.0f, FW_BOLD);
	General_font.BeginRender2D();

	/* Fill General table with relevant information */
	/* LCF / DPU version */
	DrawTextLCF(20, 15, 75, colorWhite, colorLime, "LCF Vers:", General_font, (m_rp_Sen_uiAlgoVersionNumber.isConnected()) ? (LcofValueToString(m_rp_Sen_uiAlgoVersionNumber.val(), debugString, 40)) : ("Not connected"));
	DrawTextLCF(255, 15, 75, colorWhite, colorLime, "SOC Vers:", General_font, (m_rp_SOC_u_VersionNumber.isConnected()) ? (LcofValueToString(m_rp_SOC_u_VersionNumber.val(), debugString, 41)) : ("Not connected"));

	/* Average Cycle Time LCF SEN / VEH call */
	DrawTextLCF(20, 40, 120, colorWhite, colorLime, "Avg CT LCF SEN:", General_font, LcofValueToString(LCF_SEN_Scheduler_Info.AverageCycleTime, debugString, 42));
	DrawTextLCF(255, 40, 120, colorWhite, colorLime, "Avg CT LCF VEH:", General_font, LcofValueToString(LCF_VEH_Scheduler_Info.AverageCycleTime, debugString, 42));

	/* Difference between 2 calls for LCF SEN / VEH call */
	DrawTextLCF(20, 65, 120, colorWhite, ((LCF_SEN_Scheduler_Info.Instant_TS_Difference > 70000) ? (colorRed) : (colorLime)), "Inst CT LCF SEN:", General_font, LcofValueToString(LCF_SEN_Scheduler_Info.Instant_TS_Difference, debugString, 42));
	DrawTextLCF(255, 65, 120, colorWhite, ((LCF_VEH_Scheduler_Info.Instant_TS_Difference > 15000) ? (colorRed) : (colorLime)), "Inst CT LCF VEH:", General_font, LcofValueToString(LCF_VEH_Scheduler_Info.Instant_TS_Difference, debugString, 42));
	General_font.EndRender2D();
	
	/* Font used for Bitfield information */
	IGDVFont& font = ctx.GetWindow().GetFontInterface("Arial", textsize, 0.0f, FW_BOLD);
	font.BeginRender2D();

	LCF_Bitfield_Info Signal_Selected = LCF_Bitfield_Info(); /*reset values*/

	// Start show Bitfield based on a event...
	switch(DebugSelect)
	{
	#ifndef LCF_MFC431VA10
	case 1:  /*LDP*/
		switch(BitfiledSel_idx) {
		case 0:
		case 1:
			Get_Bitfield_Information(Signal_Selected, m_rp_D_DPLSMI_SysStateLDP_btf.val(), "D_DPLSMI_SysStateLDP_btf", CHECK_MAPPING(LcfCSVData, "D_DPLSMI_SysStateLDP_btf", CSV_Open_Flag), 
					convByteToBit(m_rp_D_DPLSMI_SysStateLDP_btf.size()), m_rp_D_DPLSMI_SysStateLDP_btf.isConnected());
			break;
		case 2:
			Get_Bitfield_Information(Signal_Selected, m_rp_D_DPLSMI_StrongReady_btf.val(), "D_DPLSMI_StrongReady_btf", CHECK_MAPPING(LcfCSVData, "D_DPLSMI_StrongReady_btf", CSV_Open_Flag), 
					convByteToBit(m_rp_D_DPLSMI_StrongReady_btf.size()), m_rp_D_DPLSMI_StrongReady_btf.isConnected());
			break;
		case 3:
			Get_Bitfield_Information(Signal_Selected, m_rp_D_DPLSMI_WeakReady_btf.val(), "D_DPLSMI_WeakReady_btf", CHECK_MAPPING(LcfCSVData, "D_DPLSMI_WeakReady_btf", CSV_Open_Flag), 
					convByteToBit(m_rp_D_DPLSMI_WeakReady_btf.size()), m_rp_D_DPLSMI_WeakReady_btf.isConnected());
			break;
		case 4:
			Get_Bitfield_Information(Signal_Selected, m_rp_D_DPLSMI_Cancel_btf.val(), "D_DPLSMI_Cancel_btf", CHECK_MAPPING(LcfCSVData, "D_DPLSMI_Cancel_btf", CSV_Open_Flag), 
					convByteToBit(m_rp_D_DPLSMI_Cancel_btf.size()), m_rp_D_DPLSMI_Cancel_btf.isConnected());
			break;
		case 5:
			Get_Bitfield_Information(Signal_Selected, m_rp_S_DPLSIA_SideCondLDPLe_btf.val(), "S_DPLSIA_SideCondLDPLe_btf", CHECK_MAPPING(LcfCSVData, "S_DPLSIA_SideCondLDPLe_btf", CSV_Open_Flag), 
					convByteToBit(m_rp_S_DPLSIA_SideCondLDPLe_btf.size()), m_rp_S_DPLSIA_SideCondLDPLe_btf.isConnected());
			break;
		case 6:
			Get_Bitfield_Information(Signal_Selected, m_rp_S_DPLSIA_SideCondLDPRi_btf.val(), "S_DPLSIA_SideCondLDPRi_btf", CHECK_MAPPING(LcfCSVData, "S_DPLSIA_SideCondLDPRi_btf", CSV_Open_Flag), 
					convByteToBit(m_rp_S_DPLSIA_SideCondLDPRi_btf.size()), m_rp_S_DPLSIA_SideCondLDPRi_btf.isConnected());
			break;
		case 9:
			Get_Bitfield_Information(Signal_Selected, m_rp_S_DPLSIA_SpecificLDP_btf.val(), "S_DPLSIA_SpecificLDP_btf", CHECK_MAPPING(LcfCSVData, "S_DPLSIA_SpecificLDP_btf", CSV_Open_Flag), 
					convByteToBit(m_rp_S_DPLSIA_SpecificLDP_btf.size()), m_rp_S_DPLSIA_SpecificLDP_btf.isConnected());
			break;
		default:
			break;
		}
		break;
	#endif
	case 2: /*LDW*/
		switch(BitfiledSel_idx) {
		case 0:
		case 1:
			Get_Bitfield_Information(Signal_Selected, m_rp_D_DPLSMW_SysStateLDW_btf.val(), "D_DPLSMW_SysStateLDW_btf", CHECK_MAPPING(LcfCSVData, "D_DPLSMW_SysStateLDW_btf", CSV_Open_Flag), 
					convByteToBit(m_rp_D_DPLSMW_SysStateLDW_btf.size()), m_rp_D_DPLSMW_SysStateLDW_btf.isConnected());
			break;
		case 2:
			Get_Bitfield_Information(Signal_Selected, m_rp_D_DPLSMW_StrongReady_btf.val(), "D_DPLSMW_StrongReady_btf", CHECK_MAPPING(LcfCSVData, "D_DPLSMW_StrongReady_btf", CSV_Open_Flag), 
					convByteToBit(m_rp_D_DPLSMW_StrongReady_btf.size()), m_rp_D_DPLSMW_StrongReady_btf.isConnected());
			break;
		case 3:
			Get_Bitfield_Information(Signal_Selected, m_rp_D_DPLSMW_WeakReady_btf.val(), "D_DPLSMW_WeakReady_btf", CHECK_MAPPING(LcfCSVData, "D_DPLSMW_WeakReady_btf", CSV_Open_Flag), 
					convByteToBit(m_rp_D_DPLSMW_WeakReady_btf.size()), m_rp_D_DPLSMW_WeakReady_btf.isConnected());
			break;
		case 4:
			Get_Bitfield_Information(Signal_Selected, m_rp_D_DPLSMW_Cancel_btf.val(), "D_DPLSMW_Cancel_btf", CHECK_MAPPING(LcfCSVData, "D_DPLSMW_Cancel_btf", CSV_Open_Flag), 
					convByteToBit(m_rp_D_DPLSMW_Cancel_btf.size()), m_rp_D_DPLSMW_Cancel_btf.isConnected());
			break;
		case 5:
			Get_Bitfield_Information(Signal_Selected, m_rp_S_DPLSIA_SideCondLDWLe_btf.val(), "S_DPLSIA_SideCondLDWLe_btf", CHECK_MAPPING(LcfCSVData, "S_DPLSIA_SideCondLDWLe_btf", CSV_Open_Flag), 
					convByteToBit(m_rp_S_DPLSIA_SideCondLDWLe_btf.size()), m_rp_S_DPLSIA_SideCondLDWLe_btf.isConnected());
			break;
		case 6:
			Get_Bitfield_Information(Signal_Selected, m_rp_S_DPLSIA_SideCondLDWRi_btf.val(), "S_DPLSIA_SideCondLDWRi_btf", CHECK_MAPPING(LcfCSVData, "S_DPLSIA_SideCondLDWRi_btf", CSV_Open_Flag), 
					convByteToBit(m_rp_S_DPLSIA_SideCondLDWRi_btf.size()), m_rp_S_DPLSIA_SideCondLDWRi_btf.isConnected());
			break;
		case 9:
			Get_Bitfield_Information(Signal_Selected, m_rp_S_DPLSIA_SpecificLDW_btf.val(), "S_DPLSIA_SpecificLDW_btf", CHECK_MAPPING(LcfCSVData, "S_DPLSIA_SpecificLDW_btf", CSV_Open_Flag), 
					convByteToBit(m_rp_S_DPLSIA_SpecificLDW_btf.size()), m_rp_S_DPLSIA_SpecificLDW_btf.isConnected());
			break;
		default:
			break;
		}
		break;
	case 3: /*TJA*/
		switch(BitfiledSel_idx) {
		case 0:
		case 1:
			Get_Bitfield_Information(Signal_Selected, m_rp_D_TJASTM_TJAInvalid_btf.val(), "D_TJASTM_TJAInvalid_btf", CHECK_MAPPING(LcfCSVData, "D_TJASTM_TJAInvalid_btf", CSV_Open_Flag), 
					convByteToBit(m_rp_D_TJASTM_TJAInvalid_btf.size()), m_rp_D_TJASTM_TJAInvalid_btf.isConnected());
			break;
		case 2:
			Get_Bitfield_Information(Signal_Selected, m_rp_D_TJAGEN_StrongReadyInvalid_btf.val(), "D_TJAGEN_StrongReadyInvalid_btf", CHECK_MAPPING(LcfCSVData, "D_TJAGEN_StrongReadyInvalid_btf", CSV_Open_Flag), 
					convByteToBit(m_rp_D_TJAGEN_StrongReadyInvalid_btf.size()), m_rp_D_TJAGEN_StrongReadyInvalid_btf.isConnected());	
			break;
		case 3:
			Get_Bitfield_Information(Signal_Selected, m_rp_D_TJAGEN_WeakReadyInvalid_btf.val(), "D_TJAGEN_WeakReadyInvalid_btf", CHECK_MAPPING(LcfCSVData, "D_TJAGEN_WeakReadyInvalid_btf", CSV_Open_Flag), 
					convByteToBit(m_rp_D_TJAGEN_WeakReadyInvalid_btf.size()), m_rp_D_TJAGEN_WeakReadyInvalid_btf.isConnected());
			break;
		case 4:
			Get_Bitfield_Information(Signal_Selected, m_rp_D_TJAGEN_CancelStatus_btf.val(), "D_TJAGEN_CancelStatus_btf", CHECK_MAPPING(LcfCSVData, "D_TJAGEN_CancelStatus_btf", CSV_Open_Flag), 
					convByteToBit(m_rp_D_TJAGEN_CancelStatus_btf.size()), m_rp_D_TJAGEN_CancelStatus_btf.isConnected());
			break;
		case 5:
			Get_Bitfield_Information(Signal_Selected, m_rp_D_TJALKA_LaneCenterInvalid_btf.val(), "D_TJALKA_LaneCenterInvalid_btf", CHECK_MAPPING(LcfCSVData, "D_TJALKA_LaneCenterInvalid_btf", CSV_Open_Flag), 
					convByteToBit(m_rp_D_TJALKA_LaneCenterInvalid_btf.size()), m_rp_D_TJALKA_LaneCenterInvalid_btf.isConnected());
			break;
		#ifndef LCF_MFC431VA10
		case 6:
			Get_Bitfield_Information(Signal_Selected, m_rp_D_TJAOBF_ObjFollowInvalid_btf.val(), "D_TJAOBF_ObjFollowInvalid_btf", CHECK_MAPPING(LcfCSVData, "D_TJAOBF_ObjFollowInvalid_btf", CSV_Open_Flag), 
					convByteToBit(m_rp_D_TJAOBF_ObjFollowInvalid_btf.size()), m_rp_D_TJAOBF_ObjFollowInvalid_btf.isConnected());		
			break;
		case 9:
			Get_Bitfield_Information(Signal_Selected, m_rp_D_TJACMB_CombinedInvalid_btf.val(), "D_TJACMB_CombinedInvalid_btf", CHECK_MAPPING(LcfCSVData, "D_TJACMB_CombinedInvalid_btf", CSV_Open_Flag), 
					convByteToBit(m_rp_D_TJACMB_CombinedInvalid_btf.size()), m_rp_D_TJACMB_CombinedInvalid_btf.isConnected());	
			break;
		#endif
		default:
			break;
		}
		break;
	#ifndef LCF_MFC431VA10
	case 4: /*RDP*/
		switch(BitfiledSel_idx) {
		case 0:
		case 1:
			Get_Bitfield_Information(Signal_Selected, m_rp_D_DPRSMI_SysStateRDP_btf.val(), "D_DPRSMI_SysStateRDP_btf", CHECK_MAPPING(LcfCSVData, "D_DPRSMI_SysStateRDP_btf", CSV_Open_Flag), 
					convByteToBit(m_rp_D_DPRSMI_SysStateRDP_btf.size()), m_rp_D_DPRSMI_SysStateRDP_btf.isConnected());
			break;
		case 2:
			Get_Bitfield_Information(Signal_Selected, m_rp_D_DPRSMI_StrongReady_btf.val(), "D_DPRSMI_StrongReady_btf", CHECK_MAPPING(LcfCSVData, "D_DPRSMI_StrongReady_btf", CSV_Open_Flag), 
					convByteToBit(m_rp_D_DPRSMI_StrongReady_btf.size()), m_rp_D_DPRSMI_StrongReady_btf.isConnected());
			break;
		case 3:
			Get_Bitfield_Information(Signal_Selected, m_rp_D_DPRSMI_WeakReady_btf.val(), "D_DPRSMI_WeakReady_btf", CHECK_MAPPING(LcfCSVData, "D_DPRSMI_WeakReady_btf", CSV_Open_Flag), 
					convByteToBit(m_rp_D_DPRSMI_WeakReady_btf.size()), m_rp_D_DPRSMI_WeakReady_btf.isConnected());
			break;
		case 4:
			Get_Bitfield_Information(Signal_Selected, m_rp_D_DPRSMI_Cancel_btf.val(), "D_DPRSMI_Cancel_btf", CHECK_MAPPING(LcfCSVData, "D_DPRSMI_Cancel_btf", CSV_Open_Flag), 
					convByteToBit(m_rp_D_DPRSMI_Cancel_btf.size()), m_rp_D_DPRSMI_Cancel_btf.isConnected());
			break;
		case 5:
			Get_Bitfield_Information(Signal_Selected, m_rp_S_DPRSIA_SideCondRDPLe_btf.val(), "S_DPRSIA_SideCondRDPLe_btf", CHECK_MAPPING(LcfCSVData, "S_DPRSIA_SideCondRDPLe_btf", CSV_Open_Flag), 
					convByteToBit(m_rp_S_DPRSIA_SideCondRDPLe_btf.size()), m_rp_S_DPRSIA_SideCondRDPLe_btf.isConnected());	
			break;
		case 6:
			Get_Bitfield_Information(Signal_Selected, m_rp_S_DPRSIA_SideCondRDPRi_btf.val(), "S_DPRSIA_SideCondRDPRi_btf", CHECK_MAPPING(LcfCSVData, "S_DPRSIA_SideCondRDPRi_btf", CSV_Open_Flag),
					convByteToBit(m_rp_S_DPRSIA_SideCondRDPRi_btf.size()), m_rp_S_DPRSIA_SideCondRDPRi_btf.isConnected());
			break;
		case 9:
			Get_Bitfield_Information(Signal_Selected, m_rp_S_DPRSIA_SpecificRDP_btf.val(), "S_DPRSIA_SpecificRDP_btf", CHECK_MAPPING(LcfCSVData, "S_DPRSIA_SpecificRDP_btf", CSV_Open_Flag), 
					convByteToBit(m_rp_S_DPRSIA_SpecificRDP_btf.size()), m_rp_S_DPRSIA_SpecificRDP_btf.isConnected());
			break;
		default:
			break;
		}
		break;
	#endif
	case 5: /*CustomerSpecific*/
		switch(BitfiledSel_idx)
		{
		#if (GET_LCF_PRJ_NR() == GET_LCFPRJ_MFC431LO19())
			case 0:
			case 1:
				Get_Bitfield_Information(Signal_Selected, m_rp_D_LSCCTR_PreconditionsOK_btf.val(), "D_LSCCTR_PreconditionsOK_btf", CHECK_MAPPING(LcfCSVData, "D_LSCCTR_PreconditionsOK_btf", CSV_Open_Flag), 
					convByteToBit(m_rp_D_LSCCTR_PreconditionsOK_btf.size()), m_rp_D_LSCCTR_PreconditionsOK_btf.isConnected());
				break;
			case 2:
				Get_Bitfield_Information(Signal_Selected, m_rp_D_LSCCTR_PrjSpecQu_btf.val(), "D_LSCCTR_PrjSpecQu_btf", CHECK_MAPPING(LcfCSVData, "D_LSCCTR_PrjSpecQu_btf", CSV_Open_Flag), 
					convByteToBit(m_rp_D_LSCCTR_PrjSpecQu_btf.size()), m_rp_D_LSCCTR_PrjSpecQu_btf.isConnected());
				break;
			case 3:
				Get_Bitfield_Information(Signal_Selected, m_rp_D_HMOLCO_SysStateHWA_btf.val(), "D_HMOLCO_SysStateHWA_btf", CHECK_MAPPING(LcfCSVData, "D_HMOLCO_SysStateHWA_btf", CSV_Open_Flag), 
					convByteToBit(m_rp_D_HMOLCO_SysStateHWA_btf.size()), m_rp_D_HMOLCO_SysStateHWA_btf.isConnected());	
				break;
		#elif (GET_LCF_PRJ_NR() == GET_LCFPRJ_MFC431TA19())
			case 0:
			case 1:
				Get_Bitfield_Information(Signal_Selected, m_rp_S_TSCCTR_PrjSpecQu_btf.val(), "S_TSCCTR_PrjSpecQu_btf", CHECK_MAPPING(LcfCSVData, "S_TSCCTR_PrjSpecQu_btf", CSV_Open_Flag), 
					convByteToBit(m_rp_S_TSCCTR_PrjSpecQu_btf.size()), m_rp_S_TSCCTR_PrjSpecQu_btf.isConnected());	
				break;
			case 2:
				Get_Bitfield_Information(Signal_Selected, m_rp_S_TSCLDA_PrjSpecQu_btf.val(), "S_TSCLDA_PrjSpecQu_btf", CHECK_MAPPING(LcfCSVData, "S_TSCLDA_PrjSpecQu_btf", CSV_Open_Flag), 
					convByteToBit(m_rp_S_TSCLDA_PrjSpecQu_btf.size()), m_rp_S_TSCLDA_PrjSpecQu_btf.isConnected());			
				break;
			case 3:
				Get_Bitfield_Information(Signal_Selected, m_rp_S_TSCLTA_PrjSpecQu_btf.val(), "S_TSCLTA_PrjSpecQu_btf", CHECK_MAPPING(LcfCSVData, "S_TSCLTA_PrjSpecQu_btf", CSV_Open_Flag), 
					convByteToBit(m_rp_S_TSCLTA_PrjSpecQu_btf.size()), m_rp_S_TSCLTA_PrjSpecQu_btf.isConnected());		
				break;
			case 4:
				Get_Bitfield_Information(Signal_Selected, m_rp_D_TSCLTA_HmiCancelWarningQu_btf.val(), "D_TSCLTA_HmiCancelWarningQu_btf", CHECK_MAPPING(LcfCSVData, "D_TSCLTA_HmiCancelWarningQu_btf", CSV_Open_Flag), 
					convByteToBit(m_rp_D_TSCLTA_HmiCancelWarningQu_btf.size()), m_rp_D_TSCLTA_HmiCancelWarningQu_btf.isConnected());			
				break;
		#endif
		default:
			break;	
		}
		break;
	case 7: /* Error Handler */
		switch(ERRIO_Select)
		{
		case 0: /* Error Handler -> LCF SEN */
		case 1:
			switch(BitfiledSel_idx)
			{
				case 0:
				case 1: /*	Key 1 */
					Get_Bitfield_Information(Signal_Selected, m_rp_D_LCFERR_ErrorConfirmedVDY_btf.val(), "D_LCFERR_SEN_ErrorConfirmedVDY_btf", CHECK_MAPPING(LcfCSVData, "D_LCFERR_ErrorConfirmedVDY_btf", CSV_Open_Flag), 
						convByteToBit(m_rp_D_LCFERR_ErrorConfirmedVDY_btf.size()), m_rp_D_LCFERR_ErrorConfirmedVDY_btf.isConnected());	
					break;
				case 2: /*	Key 2 */
					Get_Bitfield_Information(Signal_Selected, m_rp_D_LCFERR_ErrorConfirmedVSA_btf.val(), "D_LCFERR_SEN_ErrorConfirmedVSA_btf", CHECK_MAPPING(LcfCSVData, "D_LCFERR_ErrorConfirmedVSA_btf", CSV_Open_Flag), 
						convByteToBit(m_rp_D_LCFERR_ErrorConfirmedVSA_btf.size()), m_rp_D_LCFERR_ErrorConfirmedVSA_btf.isConnected());	
					break;
				case 3:
				case 4:
				case 5:
					memset(Signal_Name_ERRIO, 0, sizeof(Signal_Name_ERRIO)); /* Erase if something is in the variable -> It should not be the case, but just to be sure */
					sprintf(Signal_Name_ERRIO, "D_LCFERR_ErrorConfirmedNorm_btf[%d]", BitfiledSel_idx-3); /* 0...2 range for D_LCFERR_ErrorConfirmedNorm_btf */

					Get_Bitfield_Information(Signal_Selected, m_rp_D_LCFERR_ErrorConfirmedNorm_btf.val()[BitfiledSel_idx-3], Signal_Name_ERRIO, CHECK_MAPPING(LcfCSVData, Signal_Name_ERRIO, CSV_Open_Flag), 
						convByteToBit(m_rp_D_LCFERR_ErrorConfirmedNorm_btf.size()/(NUM_DEBUG_ERR_POS_NORM/32)), m_rp_D_LCFERR_ErrorConfirmedNorm_btf.isConnected());	
					break;
				case 6: /*	Key 6 */
					Get_Bitfield_Information(Signal_Selected, m_rp_D_LCFERR_ErrorConfirmedVSM_btf.val(), "D_LCFERR_SEN_ErrorConfirmedVSM_btf", CHECK_MAPPING(LcfCSVData, "D_LCFERR_ErrorConfirmedVSM_btf", CSV_Open_Flag), 
						convByteToBit(m_rp_D_LCFERR_ErrorConfirmedVSM_btf.size()), m_rp_D_LCFERR_ErrorConfirmedVSM_btf.isConnected());	
					break;
				case 7: /*	Key 7 */
					Get_Bitfield_Information(Signal_Selected, m_rp_D_LCFERR_AlliveFailedTSMon_btf.val(), "D_LCFERR_SEN_AlliveFailedTSMon_btf", CHECK_MAPPING(LcfCSVData, "D_LCFERR_SEN_AlliveFailedTSMon_btf", CSV_Open_Flag), 
						convByteToBit(m_rp_D_LCFERR_AlliveFailedTSMon_btf.size()), m_rp_D_LCFERR_AlliveFailedTSMon_btf.isConnected(), ERRIO_IgnoreBit_Sen);	
					break;
				case 8: /*	Key 8 */
					Get_Bitfield_Information(Signal_Selected, m_rp_D_LCFERR_AlliveFailedTSBcd_btf.val(), "D_LCFERR_SEN_AlliveFailedTSBcd_btf", CHECK_MAPPING(LcfCSVData, "D_LCFERR_SEN_AlliveFailedTSBcd_btf", CSV_Open_Flag), 
						convByteToBit(m_rp_D_LCFERR_AlliveFailedTSBcd_btf.size()), m_rp_D_LCFERR_AlliveFailedTSBcd_btf.isConnected(), ERRIO_IgnoreBit_Sen);	
					break;
				case 9: /*	Key 9 */
					Get_Bitfield_Information(Signal_Selected, m_rp_D_LCFERR_AlliveFailedMC_btf.val(), "D_LCFERR_SEN_AlliveFailedMC_btf", CHECK_MAPPING(LcfCSVData, "D_LCFERR_SEN_AlliveFailedMC_btf", CSV_Open_Flag), 
						convByteToBit(m_rp_D_LCFERR_AlliveFailedMC_btf.size()), m_rp_D_LCFERR_AlliveFailedMC_btf.isConnected(), ERRIO_IgnoreBit_Sen);	
					break;
				case 10: /*	Numpad 0 */
					Get_Bitfield_Information(Signal_Selected, m_rp_D_LCFERR_AlliveFailedCCMon_btf.val(), "D_LCFERR_SEN_AlliveFailedCCMon_btf", CHECK_MAPPING(LcfCSVData, "D_LCFERR_SEN_AlliveFailedCCMon_btf", CSV_Open_Flag), 
						convByteToBit(m_rp_D_LCFERR_AlliveFailedCCMon_btf.size()), m_rp_D_LCFERR_AlliveFailedCCMon_btf.isConnected(), ERRIO_IgnoreBit_Sen);	
					break;
				case 11: /*	Numpad 1 */
					Get_Bitfield_Information(Signal_Selected, m_rp_D_LCFERR_AlliveFailedCCConst_btf.val(), "D_LCFERR_SEN_AlliveFailedCCConst_btf", CHECK_MAPPING(LcfCSVData, "D_LCFERR_SEN_AlliveFailedCCConst_btf", CSV_Open_Flag), 
						convByteToBit(m_rp_D_LCFERR_AlliveFailedCCConst_btf.size()), m_rp_D_LCFERR_AlliveFailedCCConst_btf.isConnected(), ERRIO_IgnoreBit_Sen);	
					break;
				case 12:
				case 13:
				case 14:
				case 15:
				case 16:
				case 17:
				case 18:
				case 19:
					memset(Signal_Name_ERRIO, 0, sizeof(Signal_Name_ERRIO)); /* Erase if something is in the variable -> It should not be the case, but just to be sure */
					sprintf(Signal_Name_ERRIO, "D_LCFERR_RngChkDbg_btf[%d]", BitfiledSel_idx-12); /* 0...7 range for D_LCFERR_RngChkDbg_btf */
					
					Get_Bitfield_Information(Signal_Selected, m_rp_D_LCFERR_RngChkDbg_btf.val()[BitfiledSel_idx-12], Signal_Name_ERRIO, CHECK_MAPPING(LcfCSVData, Signal_Name_ERRIO, CSV_Open_Flag), 
						convByteToBit(m_rp_D_LCFERR_RngChkDbg_btf.size()/8), m_rp_D_LCFERR_RngChkDbg_btf.isConnected());
					break;
				default:
					break;
			}
			break;
		case 2: /* Error Handler -> LCF VEH */
			switch(BitfiledSel_idx)
			{
				case 0: 
				case 1: /*	Key 1 */
					Get_Bitfield_Information(Signal_Selected, m_rp_D_LCFERR_Veh_ErrorConfirmedVDY_btf.val(), "D_LCFERR_VEH_ErrorConfirmedVDY_btf", CHECK_MAPPING(LcfCSVData, "D_LCFERR_ErrorConfirmedVDY_btf", CSV_Open_Flag), 
						convByteToBit(m_rp_D_LCFERR_Veh_ErrorConfirmedVDY_btf.size()), m_rp_D_LCFERR_Veh_ErrorConfirmedVDY_btf.isConnected());	
					break;
				case 2: /*	Key 2 */
					Get_Bitfield_Information(Signal_Selected, m_rp_D_LCFERR_Veh_ErrorConfirmedVSA_btf.val(), "D_LCFERR_VEH_ErrorConfirmedVSA_btf", CHECK_MAPPING(LcfCSVData, "D_LCFERR_ErrorConfirmedVSA_btf", CSV_Open_Flag), 
						convByteToBit(m_rp_D_LCFERR_Veh_ErrorConfirmedVSA_btf.size()), m_rp_D_LCFERR_Veh_ErrorConfirmedVSA_btf.isConnected());	
					break;
				case 3:
				case 4:
				case 5:
					memset(Signal_Name_ERRIO, 0, sizeof(Signal_Name_ERRIO)); /* Erase if something is in the variable -> It should not be the case, but just to be sure */
					sprintf(Signal_Name_ERRIO, "D_LCFERR_ErrorConfirmedNorm_btf[%d]", BitfiledSel_idx-3); /* 0...2 range for D_LCFERR_ErrorConfirmedNorm_btf */

					Get_Bitfield_Information(Signal_Selected, m_rp_D_LCFERR_Veh_ErrorConfirmedNorm_btf.val()[BitfiledSel_idx-3], Signal_Name_ERRIO, CHECK_MAPPING(LcfCSVData, Signal_Name_ERRIO, CSV_Open_Flag), 
						convByteToBit(m_rp_D_LCFERR_Veh_ErrorConfirmedNorm_btf.size()/(NUM_DEBUG_ERR_POS_NORM/32)), m_rp_D_LCFERR_Veh_ErrorConfirmedNorm_btf.isConnected());	
					break;
				case 6: /*	Key 6 */
					Get_Bitfield_Information(Signal_Selected, m_rp_D_LCFERR_Veh_ErrorConfirmedVSM_btf.val(), "D_LCFERR_VEH_ErrorConfirmedVSM_btf", CHECK_MAPPING(LcfCSVData, "D_LCFERR_ErrorConfirmedVSM_btf", CSV_Open_Flag), 
						convByteToBit(m_rp_D_LCFERR_Veh_ErrorConfirmedVSM_btf.size()), m_rp_D_LCFERR_Veh_ErrorConfirmedVSM_btf.isConnected());	
					break;
				case 7: /*	Key 7 */
					Get_Bitfield_Information(Signal_Selected, m_rp_D_LCFERR_Veh_AlliveFailedTSMon_btf.val(), "D_LCFERR_VEH_AlliveFailedTSMon_btf", CHECK_MAPPING(LcfCSVData, "D_LCFERR_VEH_AlliveFailedTSMon_btf", CSV_Open_Flag), 
						convByteToBit(m_rp_D_LCFERR_Veh_AlliveFailedTSMon_btf.size()), m_rp_D_LCFERR_Veh_AlliveFailedTSMon_btf.isConnected(), ERRIO_IgnoreBit_Veh);	
					break;
				case 8: /*	Key 8 */
					Get_Bitfield_Information(Signal_Selected, m_rp_D_LCFERR_Veh_AlliveFailedTSBcd_btf.val(), "D_LCFERR_VEH_AlliveFailedTSBcd_btf", CHECK_MAPPING(LcfCSVData, "D_LCFERR_VEH_AlliveFailedTSBcd_btf", CSV_Open_Flag), 
						convByteToBit(m_rp_D_LCFERR_Veh_AlliveFailedTSBcd_btf.size()), m_rp_D_LCFERR_Veh_AlliveFailedTSBcd_btf.isConnected(), ERRIO_IgnoreBit_Veh);	
					break;
				case 9: /*	Key 9 */
					Get_Bitfield_Information(Signal_Selected, m_rp_D_LCFERR_Veh_AlliveFailedMC_btf.val(), "D_LCFERR_VEH_AlliveFailedMC_btf", CHECK_MAPPING(LcfCSVData, "D_LCFERR_VEH_AlliveFailedMC_btf", CSV_Open_Flag), 
						convByteToBit(m_rp_D_LCFERR_Veh_AlliveFailedMC_btf.size()), m_rp_D_LCFERR_Veh_AlliveFailedMC_btf.isConnected(), ERRIO_IgnoreBit_Veh);	
					break;
				case 10: /*	Numpad 0 */
					Get_Bitfield_Information(Signal_Selected, m_rp_D_LCFERR_Veh_AlliveFailedCCMon_btf.val(), "D_LCFERR_VEH_AlliveFailedCCMon_btf", CHECK_MAPPING(LcfCSVData, "D_LCFERR_VEH_AlliveFailedCCMon_btf", CSV_Open_Flag), 
						convByteToBit(m_rp_D_LCFERR_Veh_AlliveFailedCCMon_btf.size()), m_rp_D_LCFERR_Veh_AlliveFailedCCMon_btf.isConnected(), ERRIO_IgnoreBit_Veh);	
					break;
				case 11: /*	Numpad 1 */
					Get_Bitfield_Information(Signal_Selected, m_rp_D_LCFERR_Veh_AlliveFailedCCConst_btf.val(), "D_LCFERR_VEH_AlliveFailedCCConst_btf", CHECK_MAPPING(LcfCSVData, "D_LCFERR_VEH_AlliveFailedCCConst_btf", CSV_Open_Flag), 
						convByteToBit(m_rp_D_LCFERR_Veh_AlliveFailedCCConst_btf.size()), m_rp_D_LCFERR_Veh_AlliveFailedCCConst_btf.isConnected(), ERRIO_IgnoreBit_Veh);	
					break;
				case 12:
				case 13:
				case 14:
				case 15:
				case 16:
				case 17:
				case 18:
				case 19:
					memset(Signal_Name_ERRIO, 0, sizeof(Signal_Name_ERRIO)); /* Erase if something is in the variable -> It should not be the case, but just to be sure */
					sprintf(Signal_Name_ERRIO, "D_LCFERR_RngChkDbg_btf[%d]", BitfiledSel_idx-12); /* 0...7 range for D_LCFERR_RngChkDbg_btf */
					
					Get_Bitfield_Information(Signal_Selected, m_rp_D_LCFERR_Veh_RngChkDbg_btf.val()[BitfiledSel_idx-12], Signal_Name_ERRIO, CHECK_MAPPING(LcfCSVData, Signal_Name_ERRIO, CSV_Open_Flag), 
						convByteToBit(m_rp_D_LCFERR_Veh_RngChkDbg_btf.size()/8), m_rp_D_LCFERR_Veh_RngChkDbg_btf.isConnected());
					break;
				default:
					break;
			}
			break;
		default:
			break;
		}
		break;
	case 8: /* LCF Integration Sen / VEH */
		switch(BitfiledSel_idx)
		{
		case 0:
		case 1:
			Get_Bitfield_Information(Signal_Selected, m_rp_D_LCFSEN_proPorts_NullStatusCheck.val(), "D_LCFSEN_proPorts_NullStatusCheck", CHECK_MAPPING(LcfCSVData, "D_LCFSEN_proPorts_NullStatusCheck", CSV_Open_Flag), 
				convByteToBit(m_rp_D_LCFSEN_proPorts_NullStatusCheck.size()), m_rp_D_LCFSEN_proPorts_NullStatusCheck.isConnected());
			break;
		case 2:
			Get_Bitfield_Information(Signal_Selected, m_rp_D_LCFVEH_proPorts_NullStatusCheck.val(), "D_LCFVEH_proPorts_NullStatusCheck", CHECK_MAPPING(LcfCSVData, "D_LCFVEH_proPorts_NullStatusCheck", CSV_Open_Flag), 
				convByteToBit(m_rp_D_LCFVEH_proPorts_NullStatusCheck.size()), m_rp_D_LCFVEH_proPorts_NullStatusCheck.isConnected());	
			break;
		case 3:
			Get_Bitfield_Information(Signal_Selected, m_rp_D_LCFSEN_reqPorts_NullStatusCheck.val(), "D_LCFSEN_reqPorts_NullStatusCheck", CHECK_MAPPING(LcfCSVData, "D_LCFSEN_reqPorts_NullStatusCheck", CSV_Open_Flag), 
				convByteToBit(m_rp_D_LCFSEN_reqPorts_NullStatusCheck.size()), m_rp_D_LCFSEN_reqPorts_NullStatusCheck.isConnected());		
			break;
		case 4:
			Get_Bitfield_Information(Signal_Selected, m_rp_D_LCFVEH_reqPorts_NullStatusCheck.val(), "D_LCFVEH_reqPorts_NullStatusCheck", CHECK_MAPPING(LcfCSVData, "D_LCFVEH_reqPorts_NullStatusCheck", CSV_Open_Flag), 
				convByteToBit(m_rp_D_LCFVEH_reqPorts_NullStatusCheck.size()), m_rp_D_LCFVEH_reqPorts_NullStatusCheck.isConnected());
			break;
		default:
			break;
		}
		break;
	default:
		break;
	}

	if (DebugSelect < 6) {
		switch(BitfiledSel_idx)
		{
			case 7:
				Get_Bitfield_Information(Signal_Selected, m_rp_S_ABPLBP_LeLnInvalidQu_btf.val(), "S_ABPLBP_LeLnInvalidQu_btf", CHECK_MAPPING(LcfCSVData, "S_ABPLBP_LeLnInvalidQu_btf", CSV_Open_Flag), 
					convByteToBit(m_rp_S_ABPLBP_LeLnInvalidQu_btf.size()), m_rp_S_ABPLBP_LeLnInvalidQu_btf.isConnected());	
				break;
			case 8:
				Get_Bitfield_Information(Signal_Selected, m_rp_S_ABPLBP_RiLnInvalidQu_btf.val(), "S_ABPLBP_RiLnInvalidQu_btf", CHECK_MAPPING(LcfCSVData, "S_ABPLBP_RiLnInvalidQu_btf", CSV_Open_Flag), 
					convByteToBit(m_rp_S_ABPLBP_RiLnInvalidQu_btf.size()), m_rp_S_ABPLBP_RiLnInvalidQu_btf.isConnected());
				break;
			case 11:
				Get_Bitfield_Information(Signal_Selected, m_rp_S_VDPDRV_VehStInvalid_btf.val(), "S_VDPDRV_VehStInvalid_btf", CHECK_MAPPING(LcfCSVData, "S_VDPDRV_VehStInvalid_btf", CSV_Open_Flag), 
					convByteToBit(m_rp_S_VDPDRV_VehStInvalid_btf.size()), m_rp_S_VDPDRV_VehStInvalid_btf.isConnected());
				break;
			case 12:
				Get_Bitfield_Information(Signal_Selected, m_rp_S_VDPDRV_DrvStInvalid_btf.val(), "S_VDPDRV_DrvStInvalid_btf", CHECK_MAPPING(LcfCSVData, "S_VDPDRV_DrvStInvalid_btf", CSV_Open_Flag), 
					convByteToBit(m_rp_S_VDPDRV_DrvStInvalid_btf.size()), m_rp_S_VDPDRV_DrvStInvalid_btf.isConnected());
				break;
			case 13:
				Get_Bitfield_Information(Signal_Selected, m_rp_S_VDPDRV_ActiveStCtrl_btf.val(), "S_VDPDRV_ActiveStCtrl_btf", CHECK_MAPPING(LcfCSVData, "S_VDPDRV_ActiveStCtrl_btf", CSV_Open_Flag), 
					convByteToBit(m_rp_S_VDPDRV_ActiveStCtrl_btf.size()), m_rp_S_VDPDRV_ActiveStCtrl_btf.isConnected());
				break;
			case 14:
				Get_Bitfield_Information(Signal_Selected, m_rp_S_VDPDRV_SysStNotAvailable_btf.val(), "S_VDPDRV_SysStNotAvailable_btf", CHECK_MAPPING(LcfCSVData, "S_VDPDRV_SysStNotAvailable_btf", CSV_Open_Flag), 
					convByteToBit(m_rp_S_VDPDRV_SysStNotAvailable_btf.size()), m_rp_S_VDPDRV_SysStNotAvailable_btf.isConnected());
				break;
			case 15:
				Get_Bitfield_Information(Signal_Selected, m_rp_S_VDPDRV_SysStError_btf.val(), "S_VDPDRV_SysStError_btf", CHECK_MAPPING(LcfCSVData, "S_VDPDRV_SysStError_btf", CSV_Open_Flag), 
					convByteToBit(m_rp_S_VDPDRV_SysStError_btf.size()), m_rp_S_VDPDRV_SysStError_btf.isConnected());
				break;
			#ifndef LCF_MFC431VA10
			case 16:
				Get_Bitfield_Information(Signal_Selected, m_rp_S_ABPREP_LeReInvalidQu_btf.val(), "S_ABPREP_LeReInvalidQu_btf", CHECK_MAPPING(LcfCSVData, "S_ABPREP_LeReInvalidQu_btf", CSV_Open_Flag), 
					convByteToBit(m_rp_S_ABPREP_LeReInvalidQu_btf.size()), m_rp_S_ABPREP_LeReInvalidQu_btf.isConnected());	
				break;
			case 17:
				Get_Bitfield_Information(Signal_Selected, m_rp_S_ABPREP_RiReInvalidQu_btf.val(), "S_ABPREP_RiReInvalidQu_btf", CHECK_MAPPING(LcfCSVData, "S_ABPREP_RiReInvalidQu_btf", CSV_Open_Flag), 
					convByteToBit(m_rp_S_ABPREP_RiReInvalidQu_btf.size()), m_rp_S_ABPREP_RiReInvalidQu_btf.isConnected());
				break;
			#endif
			case 18: /* ABD Signals -> Construction Site Detected */
				Get_Bitfield_Information(Signal_Selected, ABD_AnyBndRoadWorks_btf, "ABDLaneData_sConstructionSite", CHECK_MAPPING(LcfCSVData, "ABDLaneData_sConstructionSite", CSV_Open_Flag), 
					convByteToBit(sizeof(ABD_AnyBndRoadWorks_btf)), m_rpAbdOutputData.isConnected());
				break;
			default:
				break;
		}
	}
	
	unsigned int y_step = 25;
	
	if((BitfiledSel_idx >= 0) && (m_bLCFVehDebugDataValid && m_bLCFSenDebugDataValid) && ( DebugSelect < 6 || ( DebugSelect == 8 || DebugSelect == 7)))
	{
		for(unsigned char bit_no = 0; bit_no < Signal_Selected.Description.size()/*LcfCSVData[Signal_Selected.signal_name].size() -1*/ ; bit_no++)
		{
			font.SetTextColor( colorBlue.r, colorBlue.g, colorBlue.b, colorBlue.a);
			font.RenderTextf(45, 105, 0, Signal_Selected.signal_name.c_str());
			sprintf(debugString_2, "( =  %u )", Signal_Selected.Bitfield_Value);
			font.RenderTextf(360, 105, 0, debugString_2);

			font.SetTextColor( colorWhite.r, colorWhite.g, colorWhite.b, colorWhite.a);
			sprintf(debugString, "BIT %d", bit_no);
			font.RenderTextf(22, 128 + bit_no * y_step, 0, debugString);

			font.SetTextColor( colorLime.r, colorLime.g, colorLime.b, colorLime.a);

			if ((Signal_Selected.signal_name.find("SysState") != std::string::npos) || (Signal_Selected.signal_name.find("LSCCTR_PreconditionsOK") != std::string::npos) || 
				(Signal_Selected.signal_name.find("HMOLCO_SysStateHWA") != std::string::npos) || (Signal_Selected.Is_Connected == false))
			{
				if(!CHECK_BIT(Signal_Selected.Bitfield_Value, bit_no)) {
					font.SetTextColor( colorRed.r, colorRed.g, colorRed.b, colorRed.a);
				}
			}
			else
			{
				if(CHECK_BIT(Signal_Selected.Bitfield_Value, bit_no)) {
					font.SetTextColor( colorRed.r, colorRed.g, colorRed.b, colorRed.a);
				}
			}

			if (Signal_Selected.Is_Connected) {
				font.RenderTextf(115, 128 + bit_no * y_step, 0, CheckBitPosition(Signal_Selected.Bitfield_Value, bit_no, debugString));
			}
			else {
				font.RenderTextf(95, 128 + bit_no * y_step, 0, "No Info");
			}
			if (!Signal_Selected.Description.empty() /*!LcfCSVData[Signal_Selected.signal_name].empty()*/) {
				if ((Signal_Selected.Description[bit_no].find("No Info in CSV") != std::string::npos) || (Signal_Selected.Description[bit_no].find("CSV Not Loaded") != std::string::npos)) {
					font.SetTextColor( colorOrange.r, colorOrange.g, colorOrange.b, colorOrange.a);
				}
				font.RenderTextf(175, 128 + bit_no * y_step, 0, Signal_Selected.Description[bit_no].c_str()); /*LcfCSVData[Signal_Selected.signal_name][bit_no + 1].c_str()*/
			}
		} 
	}

	font.EndRender2D();

}


void CSimLcfVis::DrawLcfFunctionTable( const ISimRenderContext& ctx )
{
	GL::Init();

	char debugString[500];
    IGDVFont& font = ctx.GetWindow().GetFontInterface("Arial", 10);

    int drawAtY1=600;
    int drawAtX1_1=20;
    int drawAtX1_2=200;
	int drawAtX1_3=500;

    int drawStep=50;

    font.BeginRender2D();

	if (m_bLcfSenOutputToVehDataValid && m_bLcfSenOutputDataValid)
    {
        /* *COL1******************************************************************************* */
		/* State */
        font.SetTextColor( colorYellow.r, colorYellow.g, colorYellow.b, colorYellow.a);
        font.RenderTextf(drawAtX1_2, drawAtY1, 0, "Controlling");
		font.RenderTextf(drawAtX1_3, drawAtY1, 0, "|| Available Left/Right");
        drawAtY1+=drawStep;

		/* LKA */
		/* font.SetTextColor( colorWhite.r, colorWhite.g, colorWhite.b, colorWhite.a);
        font.RenderTextf(drawAtX1_1, drawAtY1, 0, "LKA:");
		//if controlling
		if(m_LcfSenOutputToVehData.ControllingFunction_nu == E_LCF_FunctionV3Type_E_LCF_LKA_nu){
			font.SetTextColor( colorLime.r, colorLime.g, colorLime.b, colorLime.a);
			font.RenderTextf(drawAtX1_2 + 50, drawAtY1, 0, "X");
		}else{
			font.SetTextColor( colorGray.r, colorGray.g, colorGray.b, colorGray.a);
			font.RenderTextf(drawAtX1_2 + 50, drawAtY1, 0, "-");
		} */
//		if available -- TODO: update with availability signal provided by LDPSA
		// if(m_LcfSenOutputData.LaneRecogState_nu == E_HMORQG_DISP_LANE_PHYSICAL){ //workaround
			// font.SetTextColor( colorLime.r, colorLime.g, colorLime.b, colorLime.a);
			// font.RenderTextf(drawAtX1_3 + 50, drawAtY1, 0, "X");
		// }else{
			// if(m_LcfSenOutputToVehData.ControllingFunction_nu != E_LCF_FunctionV3Type_E_LCF_LKA_nu){ //don't show function is unavailable if function is in controlling
				// font.SetTextColor( colorGray.r, colorGray.g, colorGray.b, colorGray.a);
				// font.RenderTextf(drawAtX1_3 + 50, drawAtY1, 0, "-");
			// }
		// }
		// drawAtY1+=drawStep;

		/* LDP */
		font.SetTextColor( colorWhite.r, colorWhite.g, colorWhite.b, colorWhite.a);
        font.RenderTextf(drawAtX1_1, drawAtY1, 0, "LDP:");
		//if controlling
		if(m_LcfSenOutputToVehData.ControllingFunction_nu == (uint8)E_LCF_LDP_nu){
			switch(m_LcfSenOutputData.LaKMC_lane_status_nu){
				case LCF_DEPARTING_RIGHT_LANE:
					font.SetTextColor( colorLime.r, colorLime.g, colorLime.b, colorLime.a);
					font.RenderTextf(drawAtX1_2 + 50, drawAtY1, 0, "-/X");
					//available
					font.SetTextColor( colorLime.r, colorLime.g, colorLime.b, colorLime.a);
					font.RenderTextf(drawAtX1_3 + 50, drawAtY1, 0, "-/X");
					break;
				case LCF_DEPARTING_LEFT_LANE:
					font.SetTextColor( colorLime.r, colorLime.g, colorLime.b, colorLime.a);
					font.RenderTextf(drawAtX1_2 + 50, drawAtY1, 0, "X/-");
					//available
					font.SetTextColor( colorLime.r, colorLime.g, colorLime.b, colorLime.a);
					font.RenderTextf(drawAtX1_3 + 50, drawAtY1, 0, "X/-");
					break;
				default:
					font.SetTextColor( colorGray.r, colorGray.g, colorGray.b, colorGray.a);
					font.RenderTextf(drawAtX1_2 + 50, drawAtY1, 0, "-/-");
					break;
			}
		}else{
			font.SetTextColor( colorGray.r, colorGray.g, colorGray.b, colorGray.a);
			font.RenderTextf(drawAtX1_2 + 50, drawAtY1, 0, "-/-");
			
			//if available LDP
			if((m_LcfSenOutputData.LDPSystemStateLeft_nu == E_LCF_SSD_LN_AVL)){
				if((m_LcfSenOutputData.LDPSystemStateRight_nu == E_LCF_SSD_LN_AVL)){
					
					font.SetTextColor( colorLime.r, colorLime.g, colorLime.b, colorLime.a);
					font.RenderTextf(drawAtX1_3 + 50, drawAtY1, 0, "X/X");
					
				}else{
				
					font.SetTextColor( colorLime.r, colorLime.g, colorLime.b, colorLime.a);
					font.RenderTextf(drawAtX1_3 + 50, drawAtY1, 0, "X/-");
				
				}
			}else{
				if((m_LcfSenOutputData.LDPSystemStateRight_nu == E_LCF_SSD_LN_AVL)){
					
					font.SetTextColor( colorLime.r, colorLime.g, colorLime.b, colorLime.a);
					font.RenderTextf(drawAtX1_3 + 50, drawAtY1, 0, "-/X");
					
				}else{
				
					font.SetTextColor( colorLime.r, colorLime.g, colorGray.b, colorGray.a);
					font.RenderTextf(drawAtX1_3 + 50, drawAtY1, 0, "-/-");
				}
			}
		}

		drawAtY1+=drawStep;

		/* RDP */
		font.SetTextColor( colorWhite.r, colorWhite.g, colorWhite.b, colorWhite.a);
        font.RenderTextf(drawAtX1_1, drawAtY1, 0, "RDP:");
		//if controlling
		if(m_LcfSenOutputToVehData.ControllingFunction_nu == (uint8)E_LCF_RDP_nu){
			switch(m_LcfSenOutputData.LaKMC_lane_status_nu){
				case LCF_DEPARTING_RIGHT_LANE:
					font.SetTextColor( colorLime.r, colorLime.g, colorLime.b, colorLime.a);
					font.RenderTextf(drawAtX1_2 + 50, drawAtY1, 0, "-/X");
					//available
					font.SetTextColor( colorLime.r, colorLime.g, colorLime.b, colorLime.a);
					font.RenderTextf(drawAtX1_3 + 50, drawAtY1, 0, "-/X");
					break;
				case LCF_DEPARTING_LEFT_LANE:
					font.SetTextColor( colorLime.r, colorLime.g, colorLime.b, colorLime.a);
					font.RenderTextf(drawAtX1_2 + 50, drawAtY1, 0, "X/-");
					//available
					font.SetTextColor( colorLime.r, colorLime.g, colorLime.b, colorLime.a);
					font.RenderTextf(drawAtX1_3 + 50, drawAtY1, 0, "X/-");
					break;
				default:
					font.SetTextColor( colorGray.r, colorGray.g, colorGray.b, colorGray.a);
					font.RenderTextf(drawAtX1_2 + 50, drawAtY1, 0, "-/-");
					break;
			}
		}else{
			font.SetTextColor( colorGray.r, colorGray.g, colorGray.b, colorGray.a);
			font.RenderTextf(drawAtX1_2 + 50, drawAtY1, 0, "-/-");
			
			//if available RDP
			if((m_LcfSenOutputData.RDPSystemStateLeft_nu == E_LCF_SSD_LN_AVL)){
				if((m_LcfSenOutputData.RDPSystemStateRight_nu == E_LCF_SSD_LN_AVL)){
				
					font.SetTextColor( colorLime.r, colorLime.g, colorLime.b, colorLime.a);
					font.RenderTextf(drawAtX1_3 + 50, drawAtY1, 0, "X/X");
					
				}else{
				
					font.SetTextColor( colorLime.r, colorLime.g, colorLime.b, colorLime.a);
					font.RenderTextf(drawAtX1_3 + 50, drawAtY1, 0, "X/-");
					
				}
			}else{
				if((m_LcfSenOutputData.LDPSystemStateRight_nu == E_LCF_SSD_LN_AVL)){
					
					font.SetTextColor( colorLime.r, colorLime.g, colorLime.b, colorLime.a);
					font.RenderTextf(drawAtX1_3 + 50, drawAtY1, 0, "-/X");
					
				}else{
				
					font.SetTextColor( colorLime.r, colorLime.g, colorGray.b, colorGray.a);
					font.RenderTextf(drawAtX1_3 + 50, drawAtY1, 0, "-/-");
					
				}
			}
			drawAtY1+=drawStep;
		}

		#ifndef LCF_MFC431VA10
 		/* LDP */
		font.SetTextColor( colorWhite.r, colorWhite.g, colorWhite.b, colorWhite.a);
        font.RenderTextf(drawAtX1_1, drawAtY1, 0, "LDW:");
		//if controlling
		switch(m_rp_S_DPLSMI_DangerousSide_nu.val()){
			case E_LCF_DANGEROUSSIDE_LEFT:
				font.SetTextColor( colorLime.r, colorLime.g, colorLime.b, colorLime.a);
				font.RenderTextf(drawAtX1_2 + 50, drawAtY1, 0, "X/-");
				break;
			case E_LCF_DANGEROUSSIDE_RIGHT:
				font.SetTextColor( colorLime.r, colorLime.g, colorLime.b, colorLime.a);
				font.RenderTextf(drawAtX1_2 + 50, drawAtY1, 0, "-/X");
				break;
			case E_LCF_DANGEROUSSIDE_NONE:
				font.SetTextColor( colorGray.r, colorGray.g, colorGray.b, colorGray.a);
				font.RenderTextf(drawAtX1_2 + 50, drawAtY1, 0, "-/-");
				break;
			default:
				font.SetTextColor( colorGray.r, colorGray.g, colorGray.b, colorGray.a);
				font.RenderTextf(drawAtX1_2 + 50, drawAtY1, 0, "-/-");
				break;
		}
		/* if(m_LCF_SenDebugData.S_DPLSMI_DangerousSide_nu == E_LCF_DANGEROUSSIDE_LEFT){
			font.SetTextColor( colorLime.r, colorLime.g, colorLime.b, colorLime.a);
			font.RenderTextf(drawAtX1_2 + 50, drawAtY1, 0, "X/-");
		}else{
			font.SetTextColor( colorGray.r, colorGray.g, colorGray.b, colorGray.a);
			font.RenderTextf(drawAtX1_2 + 50, drawAtY1, 0, "-/-");
		}
		if(m_LCF_SenDebugData.S_DPLSMI_DangerousSide_nu == E_LCF_DANGEROUSSIDE_RIGHT){
			font.SetTextColor( colorLime.r, colorLime.g, colorLime.b, colorLime.a);
			font.RenderTextf(drawAtX1_2 + 50, drawAtY1, 0, "-/X");
		}else{
			font.SetTextColor( colorGray.r, colorGray.g, colorGray.b, colorGray.a);
			font.RenderTextf(drawAtX1_2 + 50, drawAtY1, 0, "-/-");
		} */

		//if available
/*		switch(m_LcfSenOutputData.LaneRecogState_nu){
				case E_HMORQG_DISP_LANE_PHYSICAL:s
					font.SetTextColor( colorLime.r, colorLime.g, colorLime.b, colorLime.a);
					font.RenderTextf(drawAtX1_3 + 50, drawAtY1, 0, "-/X");
					break;
				case E_HMORQG_DISP_LANE_PHYSICAL:
					font.SetTextColor( colorLime.r, colorLime.g, colorLime.b, colorLime.a);
					font.RenderTextf(drawAtX1_3 + 50, drawAtY1, 0, "X/-");
					break;
				case E_HMORQG_DISP_LANE_PHYSICAL:
					font.SetTextColor( colorLime.r, colorLime.g, colorLime.b, colorLime.a);
					font.RenderTextf(drawAtX1_3 + 50, drawAtY1, 0, "X/X");
					break;
				case E_HMORQG_DISP_LANE_PHYSICAL:
					font.SetTextColor( colorLime.r, colorLime.g, colorLime.b, colorLime.a);
					font.RenderTextf(drawAtX1_3 + 50, drawAtY1, 0, "-/-");
					break;
				default:
					font.SetTextColor( colorGray.r, colorGray.g, colorGray.b, colorGray.a);
					font.RenderTextf(drawAtX1_3 + 50, drawAtY1, 0, "-/-");
					break;
			}*/
		drawAtY1+=drawStep;
	#endif
	
	#ifdef LCF_MFC431VA10 /*ElNa, Use DPLSMW for MFC431VA10 project */
 		/* LDW */
		font.SetTextColor( colorWhite.r, colorWhite.g, colorWhite.b, colorWhite.a);
        font.RenderTextf(drawAtX1_1, drawAtY1, 0, "LDW:");
		//if controlling
		switch(m_rp_S_DPLSMW_DangerousSide_nu.val()){
			case E_LCF_DANGEROUSSIDE_LEFT:
				font.SetTextColor( colorLime.r, colorLime.g, colorLime.b, colorLime.a);
				font.RenderTextf(drawAtX1_2 + 50, drawAtY1, 0, "X/-");
				break;
			case E_LCF_DANGEROUSSIDE_RIGHT:
				font.SetTextColor( colorLime.r, colorLime.g, colorLime.b, colorLime.a);
				font.RenderTextf(drawAtX1_2 + 50, drawAtY1, 0, "-/X");
				break;
			case E_LCF_DANGEROUSSIDE_NONE:
				font.SetTextColor( colorGray.r, colorGray.g, colorGray.b, colorGray.a);
				font.RenderTextf(drawAtX1_2 + 50, drawAtY1, 0, "-/-");
				break;
			default:
				font.SetTextColor( colorGray.r, colorGray.g, colorGray.b, colorGray.a);
				font.RenderTextf(drawAtX1_2 + 50, drawAtY1, 0, "-/-");
				break;
		}

		drawAtY1+=drawStep;
	#endif

		/* TJA */
		font.SetTextColor( colorWhite.r, colorWhite.g, colorWhite.b, colorWhite.a);
        font.RenderTextf(drawAtX1_1, drawAtY1, 0, "TJA:");
		//if controlling
		if(m_LcfSenOutputToVehData.ControllingFunction_nu == E_LCF_FunctionV3Type_E_LCF_TJA_nu){
			font.SetTextColor( colorLime.r, colorLime.g, colorLime.b, colorLime.a);
			font.RenderTextf(drawAtX1_2 + 50, drawAtY1, 0, "X");
			//available
			font.SetTextColor( colorLime.r, colorLime.g, colorLime.b, colorLime.a);
			font.RenderTextf(drawAtX1_3 + 50, drawAtY1, 0, "X");
		}else{
			font.SetTextColor( colorGray.r, colorGray.g, colorGray.b, colorGray.a);
			font.RenderTextf(drawAtX1_2 + 50, drawAtY1, 0, "-");
			
			//if available
			if((m_LcfSenOutputData.TJASystemState_nu == E_LCF_SSD_LN_AVL)){
				font.SetTextColor( colorLime.r, colorLime.g, colorLime.b, colorLime.a);
				font.RenderTextf(drawAtX1_3 + 50, drawAtY1, 0, "X");
			}else{
				font.SetTextColor( colorGray.r, colorGray.g, colorGray.b, colorGray.a);
				font.RenderTextf(drawAtX1_3 + 50, drawAtY1, 0, "-");
			}
		}
		
		drawAtY1+=drawStep;
		drawAtY1+=drawStep;

	}

	font.EndRender2D();
}

void CSimLcfVis::DrawLCFLegend( const ISimRenderContext& ctx )
{
	GL::Init();

	char debugString[500];
    IGDVFont& font = ctx.GetWindow().GetFontInterface("Arial", 10);

    int drawAtY1=1500;
    int drawAtX1_1=20;
    int drawAtX1_2=700;

    int drawStep=50;

    font.BeginRender2D();

        /* *COL1******************************************************************************* */
        font.SetTextColor( colorYellow.r, colorYellow.g, colorYellow.b, colorYellow.a);
        font.RenderTextf(drawAtX1_1, drawAtY1, 0, "LCF Lane Legend");
        drawAtY1+=drawStep;

		font.SetTextColor( colorWhite.r, colorWhite.g, colorWhite.b, colorWhite.a);
        font.RenderTextf(drawAtX1_1, drawAtY1, 0, "Valid:");
		font.SetTextColor( colorYellow.r, colorYellow.g, colorYellow.b, colorYellow.a);
		font.RenderTextf(drawAtX1_2, drawAtY1, 0, "Yellow");
		drawAtY1+=drawStep;

		font.SetTextColor( colorWhite.r, colorWhite.g, colorWhite.b, colorWhite.a);
        font.RenderTextf(drawAtX1_1, drawAtY1, 0, "Virtual:");
		font.SetTextColor( colorViolet.r, colorViolet.g, colorViolet.b, colorViolet.a);
		font.RenderTextf(drawAtX1_2, drawAtY1, 0, "Violet");
		drawAtY1+=drawStep;

		font.SetTextColor( colorWhite.r, colorWhite.g, colorWhite.b, colorWhite.a);
        font.RenderTextf(drawAtX1_1, drawAtY1, 0, "Safety Support Marking:");
		font.SetTextColor( colorLightGray.r, colorLightGray.g, colorLightGray.b, colorLightGray.a);
		font.RenderTextf(drawAtX1_2, drawAtY1, 0, "LightGray");
		drawAtY1+=drawStep;

		font.SetTextColor( colorYellow.r, colorYellow.g, colorYellow.b, colorYellow.a);
        font.RenderTextf(drawAtX1_1, drawAtY1, 0, "LD Lane Legend");
        drawAtY1+=drawStep;

		font.SetTextColor( colorWhite.r, colorWhite.g, colorWhite.b, colorWhite.a);
        font.RenderTextf(drawAtX1_1, drawAtY1, 0, "NOT_AVAILABLE_LDLQS:");  // 2022/09/01 Chengyou, Tang : Modify because MFC5J3 project define a MACRO named NOT_AVAILABLE
		font.SetTextColor( colorRed.r, colorRed.g, colorRed.b, colorRed.a);
		font.RenderTextf(drawAtX1_2, drawAtY1, 0, "Red");
		drawAtY1+=drawStep;

		font.SetTextColor( colorWhite.r, colorWhite.g, colorWhite.b, colorWhite.a);
        font.RenderTextf(drawAtX1_1, drawAtY1, 0, "VIRTUAL_LANE:");
		font.SetTextColor( colorViolet.r, colorViolet.g, colorViolet.b, colorViolet.a);
		font.RenderTextf(drawAtX1_2, drawAtY1, 0, "Violet");
		drawAtY1+=drawStep;

		font.SetTextColor( colorWhite.r, colorWhite.g, colorWhite.b, colorWhite.a);
        font.RenderTextf(drawAtX1_1, drawAtY1, 0, "NEAR_DEATH:");
		font.SetTextColor( colorOrange.r, colorOrange.g, colorOrange.b, colorOrange.a);
		font.RenderTextf(drawAtX1_2, drawAtY1, 0, "Orange");
		drawAtY1+=drawStep;

		font.SetTextColor( colorWhite.r, colorWhite.g, colorWhite.b, colorWhite.a);
        font.RenderTextf(drawAtX1_1, drawAtY1, 0, "PREDICTED:");
		font.SetTextColor( colorGreen.r, colorGreen.g, colorGreen.b, colorGreen.a);
		font.RenderTextf(drawAtX1_2, drawAtY1, 0, "Green");
		drawAtY1+=drawStep;

		font.SetTextColor( colorWhite.r, colorWhite.g, colorWhite.b, colorWhite.a);
        font.RenderTextf(drawAtX1_1, drawAtY1, 0, "ROAD_EDGE:");
		font.SetTextColor( colorAqua.r, colorAqua.g, colorAqua.b, colorAqua.a);
		font.RenderTextf(drawAtX1_2, drawAtY1, 0, "Aqua");
		drawAtY1+=drawStep;

		font.SetTextColor( colorWhite.r, colorWhite.g, colorWhite.b, colorWhite.a);
        font.RenderTextf(drawAtX1_1, drawAtY1, 0, "EXIT_RAMP:");
		font.SetTextColor( colorLightGray.r, colorLightGray.g, colorLightGray.b, colorLightGray.a);
		font.RenderTextf(drawAtX1_2, drawAtY1, 0, "LightGray");
		drawAtY1+=drawStep;

		font.SetTextColor( colorWhite.r, colorWhite.g, colorWhite.b, colorWhite.a);
        font.RenderTextf(drawAtX1_1, drawAtY1, 0, "HIGH_QUALITY:");
		font.SetTextColor( colorBlue.r, colorBlue.g, colorBlue.b, colorBlue.a);
		font.RenderTextf(drawAtX1_2, drawAtY1, 0, "Blue");
		drawAtY1+=drawStep;

	font.EndRender2D();
}


void CSimLcfVis::DrawLcfHMIInfo( const ISimRenderContext& ctx )
{
	const unsigned int boxPositionX = imageWidth/2;
	const unsigned int boxPositionY = imageHeight - 60;
	const unsigned int markerLength = 40;

	glLineWidth(5);
//	if(m_bLcfSenOutputDataValid){

		//left Marker
		// if((m_LcfSenOutputData.LaneRecogState_nu == E_HMORQG_DISP_LANE_PHYSICAL) || (m_LcfSenOutputData.LaneRecogState_nu == E_HMORQG_DISP_LANE_PHYSICAL)){
				// glColor3f(0.0, 0.5, 0.0); //green
		// }else{
				// glColor3f(0.5, 0.5, 0.5); //gray
		// }
				// glBegin(GL_LINES);
				// glVertex2i(boxPositionX - 10, boxPositionY);
				// glVertex2i(boxPositionX - 15, boxPositionY + markerLength); //15 to make the line diagonal
				// glEnd();

		//Right Marker
		// if((m_LcfSenOutputData.LaneRecogState_nu == E_HMORQG_DISP_LANE_PHYSICAL) || (m_LcfSenOutputData.LaneRecogState_nu == E_HMORQG_DISP_LANE_PHYSICAL)){
			// glColor3f(0.0, 0.5, 0.0); //green
		// }else{
			// glColor3f(0.5, 0.5, 0.5); //gray
		// }
				// glBegin(GL_LINES);
				// glVertex2i(boxPositionX + 10, boxPositionY);
				// glVertex2i(boxPositionX + 15, boxPositionY + markerLength); //15 to make the line diagonal
				// glEnd();

	// }
	
}

void CSimLcfVis::DrawLcfStatusInfo( const ISimRenderContext& ctx ){

	char debugString[50];
	const float centerX = 1100;
	const float centerY = 58;
	const float radiusDisk = 45; //radius of outer line of the LCF disk
	const float radiusOuterLine = radiusDisk + 1; //radius of LCF disk
	const unsigned int numberSegments = 50; //polygon number of segments - the higher the number the smoother the circle
	const static string LatCtrlMode[3] = {"LC", "OF", "CB"};
	unsigned char textsize = 10;

	if(m_ResolutionMode)
	{
		textsize = 8;
	}	

	IGDVFont& font = ctx.GetWindow().GetFontInterface("Arial", textsize,  0.0F, FW_BOLD);
	
	font.BeginRender2D();
	DrawTextLCF(25, 10, 260, colorRed, colorRed, "Trajectory Mode: ", font, LcofValueToString(SelectTrajDraw, debugString));
	font.EndRender2D();

	font.SetTextColor( colorWhite.r, colorWhite.g, colorWhite.b, colorWhite.a);

	float colorCicle[8][3] = {{0.5, 0.5, 0.5}, {0, 0.6, 0}, {0.8, 0.407, 0}, {0, 0, 1.0}, {0.8, 0.407, 0}, {0, 0, 1.0}, {0, 0, 1.0}, { 0, 0, 1.0}};
	std::vector<std::string> stringStatus;

    stringStatus.push_back("OFF");
	stringStatus.push_back("TJA");
	stringStatus.push_back("LDP");
	stringStatus.push_back("LDPOC");
	stringStatus.push_back("RDP");
	stringStatus.push_back("ALCA");
	stringStatus.push_back("AOLC");
	stringStatus.push_back("AES");

	unsigned char statusLCF = m_rp_ControllingFunction_nu.val();

	glColor3f(colorCicle[statusLCF][0], colorCicle[statusLCF][1], colorCicle[statusLCF][2]);
	LCFDrawFilledCircle(centerX,centerY, radiusDisk , numberSegments);
	font.BeginRender2D();
	font.RenderTextf(centerX - 29, centerY - 32, 0, stringStatus[statusLCF].c_str());
	if (statusLCF == 1) /*TJA*/
		if ((m_rp_LatCtrlModeTJA_nu.val() > 0) && (m_rp_LatCtrlModeTJA_nu.val() < 4))
			font.RenderTextf(centerX - 22, centerY, 0,  LatCtrlMode[m_rp_LatCtrlModeTJA_nu.val() - 1].c_str());
	font.EndRender2D();

	//draw outer circle black lining
	glColor3f(0.0, 0.0, 0.0); //black
	LCFDrawCircle(centerX, centerY, radiusOuterLine, numberSegments);

}

void LCFDrawCircle(float cx, float cy, float r, unsigned int num_segments)
{
	const float theta = (float)(2 * 3.1415926 / float(num_segments));
	const float c = cosf(theta);//precalculate the sine and cosine
	const float s = sinf(theta);
	float t;

	float x = r;//we start at angle = 0
	float y = 0;

	glBegin(GL_LINE_LOOP);
	for(unsigned int ii = 0; ii < num_segments; ii++)
	{
		glVertex2f(x + cx, y + cy);//output vertex

		//apply the rotation matrix
		t = x;
		x = c * x - s * y;
		y = s * t + c * y;
	}
	glEnd();
}

void LCFDrawFilledCircle(float cx, float cy, float r, unsigned int num_segments)
{
	const float theta = (float)(2 * 3.1415926 / float(num_segments));
	const float c = cosf(theta);//precalculate the sine and cosine
	const float s = sinf(theta);
	float t;

	float x = r;//we start at angle = 0
	float y = 0;
    glPolygonMode( GL_FRONT, GL_FILL );
	glBegin(GL_POLYGON);
	for(unsigned int ii = 0; ii < num_segments; ii++)
	{
		glVertex2f(x + cx, y + cy);//output vertex

		//apply the rotation matrix
		t = x;
		x = c * x - s * y;
		y = s * t + c * y;
	}
	glEnd();
}

//rotate_point rotates a point around another point with theta degrees anticlockwise
//poly_point is the point to be rotated
//theta is the angle in degrees
//center_point is the point around which the rotation is made
point rotate_point(point poly_point, float theta, point center_point){
	
	float theta_rad;
	point poly_point_new;
	theta_rad = theta * M_PI / 180;
	
	poly_point_new.x = (poly_point.x - center_point.x)*cos(theta_rad) - (poly_point.y - center_point.y)*sin(theta_rad) + center_point.x;
	poly_point_new.y = (poly_point.x - center_point.x)*sin(theta_rad) + (poly_point.y - center_point.y)*cos(theta_rad) + center_point.y;

	return poly_point_new;
}

//translate point shifts a point with a certain specified value
//poly_point is the point to be translated
//longitudinal_shift is the shift value in the "x" axis of the reference frame
//lateral_shift is the shift value on the "y" axis of the reference frame
point translate_point(point poly_point, float longitudinal_shift, float lateral_shift){
	
	point poly_point_new;
	
	poly_point_new.x = poly_point.x + longitudinal_shift;
	poly_point_new.y = poly_point.y + lateral_shift;

	return poly_point_new;
}

//calculates points of the planned trajectory from TRJPLN and plots them on the image
//input parameter: color - the color of the drawn trajectory
void CSimLcfVis::DrawLcfTrajectory( GL::Color color )
{
	//check if ports are valid
	if(m_bLCFVehDebugDataValid){ 
		//check if functions are controlling
		if(m_rp_ControllingFunction_nu.val() != E_LCF_FunctionV3Type_E_LCF_OFF_nu ){
			std::vector<GL::Pos> vecGlPos;
			float delta_x, y_derofx,delta_sderofx_cur,delta_sderofx_prev,delta_s,NV_x,NV_y,t,d,s_cur,s_prev;
			uint32 i;
			float x_n, y_n, x_d, y_d, z;
			float speed, acceleration, heading, end_time, tan_theta, c0, c1, y0;
			float A[6],t_array[6];
			float res;
			
			//signals for translating and rotating points
			float lateralDelta, longitudinalDelta, rotation_rad;
			
			//matrix declarations for CML function - matrix multiplication
			CML_t_Matrix A_matrix, t_matrix;
			CML_t_Matrix MatrixRes;
			
			MatrixRes.Desc.col = 1;
			MatrixRes.Desc.row = 1;
			MatrixRes.pData = &res;
			
			A_matrix.Desc.col = 6;
			A_matrix.Desc.row = 1;
			A_matrix.pData = &(A[0]);
			
			t_matrix.Desc.col = 1;
			t_matrix.Desc.row = 6;
			t_matrix.pData = &(t_array[0]);
			
			//init time array
			t_array[0] = 0;
			t_array[1] = 0;
			t_array[2] = 0;
			t_array[3] = 0;
			t_array[4] = 0;
			t_array[5] = 0;
			
			//signals for translating and rotating points in camera reference frame
			//longitudinalDelta = m_LCF_VehDebugData.LCF_pstVehDbgData.TRJPLN_VehDbgData.TPLLCO_VehDbgData.D_TPLLCO_DeltaProj_metX_met;//GeGr: Renamed
            longitudinalDelta = m_rp_D_TPLLCO_DeltaProjPosX_met.val();
			lateralDelta = m_rp_D_TPLLCO_DeltaProjPosY_met.val();
			rotation_rad = m_rp_D_TPLLCO_RightOri_rad.val();
			
			/*
				v = S_LCFRCV_VehVelX_mps; % speed
				a = S_LCFRCV_VehAclX_mps2; %acceleration
				t_e = S_TPLTJC_EndPointTrajectory_nu; % end time
				tan_theta = tan(S_TPLLCO_RightCridrHeading_rad);
				c0 = S_TPLLCO_RightCorridorCrv_1pm;
				c1 = S_TPLLCO_RiCridrChngOfCrv_1pm2;
				A = S_TPLTJC_TrajParam_nu;
				y0 = 0;
			*/
			
			speed = m_VehDyn.Longitudinal.Velocity; /*S_LCFRCV_VehVelX_mps */
			acceleration = m_VehDyn.Longitudinal.Accel; /*S_LCFRCV_VehAclX_mps2 */
			end_time = m_rp_S_TPLTJC_EndPointTrajectory_nu.val();
			heading = m_rp_S_TPLLCO_RightCridrHeading_rad.val();
			tan_theta = tan(heading);
			c0 = m_rp_S_TPLLCO_RightCorridorCrv_1pm.val();
			c1 = m_rp_S_TPLLCO_RiCridrChngOfCrv_1pm2.val();
			//start S_TPLTJC_TrajParam_nu
			A[0] = m_rp_S_TPLTJC_TrajParam_nu.val()[0];	/*PlannedTrajParam_nu[0]; */
			A[1] = m_rp_S_TPLTJC_TrajParam_nu.val()[1];	/*PlannedTrajParam_nu[1]; */
			A[2] = m_rp_S_TPLTJC_TrajParam_nu.val()[2];	/*PlannedTrajParam_nu[2]; */
			A[3] = m_rp_S_TPLTJC_TrajParam_nu.val()[3];	/*PlannedTrajParam_nu[3]; */
			A[4] = m_rp_S_TPLTJC_TrajParam_nu.val()[4];	/*PlannedTrajParam_nu[4]; */
			A[5] = m_rp_S_TPLTJC_TrajParam_nu.val()[5];	/*PlannedTrajParam_nu[5]; */
			//end S_TPLTJC_TrajParam_nu
			y0 = 0;

			delta_x = 1;// step
			i = 0;
			
			x_n = delta_x * i;
			y_n = y0 + tan_theta * x_n + 1.0f / 2.0f * c0 * x_n*x_n + 1.0f / 6.0f * c1 * x_n*x_n*x_n; // clothoid model
			y_derofx = tan_theta + c0 * x_n + 1.0f / 2.0f * c1 * x_n * x_n; // dy/dx, differential of the clothoid
			delta_sderofx_cur = sqrt(1 + y_derofx * y_derofx);
			delta_sderofx_prev = delta_sderofx_cur;
			s_cur = 0; // arc length
			s_prev = s_cur;

			NV_x = - 1.0f * y_derofx / delta_sderofx_cur; // normal vector x
			NV_y = 1.0f / delta_sderofx_cur; // normal vector y

			t = 0; // t of s
			d = 0; // planned d

			z = 0.0f;
			
			while (s_cur < (1.0f/2.0f * acceleration * end_time*end_time + speed * end_time))//(x <= x_e)
			{
			
				i = i + 1;
				x_n = delta_x * i;
				y_n = y0 + tan_theta * x_n + 1.0f / 2.0f * c0 * x_n*x_n + 1.0f / 6.0f * c1 * x_n*x_n*x_n;
				y_derofx = tan_theta + c0 * x_n + 1.0f / 2.0f * c1 * x_n * x_n;
				delta_sderofx_cur = sqrt(1 + y_derofx * y_derofx);
				delta_s = 1.0f / 2.0f * (delta_sderofx_prev + delta_sderofx_cur) * delta_x;
				delta_sderofx_prev = delta_sderofx_cur;
				s_cur = s_prev + delta_s;
				s_prev = s_cur;
				NV_x = - 1.0f * y_derofx / delta_sderofx_cur;
				NV_y = 1.0f / delta_sderofx_cur;
				t = (sqrt(speed*speed + 2.0f * acceleration * s_cur) - speed) / acceleration;
				t_array[0] = 1;
				t_array[1] = t;
				t_array[2] = t*t;
				t_array[3] = t * t * t;
				t_array[4] = t * t * t * t;
				t_array[5] = t * t * t * t * t;
				CML_v_multiplyMatrices(&MatrixRes, &A_matrix, &t_matrix);
				d = *(MatrixRes.pData);
				x_d = x_n + d * NV_x;
				y_d = y_n + d * NV_y;
				
				//translate points
				x_d = x_d + longitudinalDelta;
				y_d = y_d - lateralDelta;
				//rotate points
				x_d = x_d * cos(rotation_rad) - y_d * sin(rotation_rad);
				y_d = x_d * sin(rotation_rad) + y_d * cos(rotation_rad);
				
				//add the points to array
				GL::Pos pos(x_d , y_d, z);
				vecGlPos.push_back(pos);
				
			}
			
			//draw the points with LINE interpolation
			GL::Draw(GL_LINE_STRIP, vecGlPos, 10, color);
			
		}/*end function controlling check */
	}/*end port valid check */
}
