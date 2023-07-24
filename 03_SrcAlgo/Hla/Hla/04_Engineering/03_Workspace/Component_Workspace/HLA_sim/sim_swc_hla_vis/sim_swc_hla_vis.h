/*! \file **********************************************************************

  TEMPLATE VERSION:          1.2
                             changed parameters in cpp version to be a struct/class
                             added version management for template

*/

#ifndef sim_swc_hla_vis_h__
#define sim_swc_hla_vis_h__

#include "sim_swc_base.h"
#include "sim_swc_draw_base.h"
#include "sim_versioninfo_impl.h"
#include "sim_swc_synchronization.h"
#include "rteSimReceivePort.h"
#include "hla_defs.h"
#include "sim_hla_ethernet.h"
#include "sim_hla_can.h"

#include "sim_visu_type.h"

#include "sim_hla_visu_hlaf.h"
#include "sim_hla_visu_turnoff.h"
#include "sim_hla_visu_error.h"
#include "sim_hla_visu_basic.h"
#include "sim_hla_visu_utils.h"

//TODO #include "sim_hla_visu_table.h"
#include "sim_visu_menu.h"

#include "sim_renderparam_helper.h"

#include <gl\gl.h>        // Header File For The OpenGL32 Library
#include <gl\glu.h>       // Header File For The GLu32 Library

#define CONV_I32VERSION_TO_TUPPLE(x)   (((x) >> 16) & 0xFF), (((x) >> 8) & 0xFF), ((x) & 0xFF)

// TODO: remove these fake types and defines
typedef int hlaInputA_t;
typedef int hlaInputB_t;
typedef int hlaOutputA_t;

static const int HLA_INPUT_A_INTFVER  = 1;
static const int HLA_INPUT_B_INTFVER  = 2;

static const char INPUT_A_TYPENAME[] = "TypeNameA";
static const char INPUT_B_TYPENAME[] = "TypeNameB";

#pragma deprecated (hlaInputA_t, hlaInputB_t)
#pragma deprecated (HLA_INPUT_A_INTFVER, HLA_INPUT_B_INTFVER, INPUT_A_TYPENAME, INPUT_B_TYPENAME)

/// Class representing a SIM plugin to the SIM VFB MO in MTS
class CSimhlaVis 
  : public CSimSwcDrawBase,
    public CSimSwcSynchronization<Hla_SyncRef_t>,
    public CSimHlaVisuHlaf,
    public CSimHlaVisuTurnoff,
    public CSimHlaVisuError,
    public CSimHlaVisuBasic,
//TODO     public CSimHlaVisuImage,
//TODO     public CSimHlaVisuTracking,
    public CSimHlaEthernet,
    public CSimHlaCan,
    public CSimVisuMenu
{
public:
  /// Constructor of the class.
  /// Gets called when the plugin is loaded.
  CSimhlaVis();

  /// Destructor of the class.
  /// Gets called when the plugin is unloaded.
  ~CSimhlaVis();

  /// @name Static server port methods
  /// @{

  /// Server port "Init" class method stub, calls directly the instance method
  static void Reset(void* PlgID, long, long) { reinterpret_cast<CSimhlaVis*>(PlgID)->Reset(); }

  /// Server port "Init" class method stub, calls directly the instance method
  static void Init(void* PlgID, long, long) { reinterpret_cast<CSimhlaVis*>(PlgID)->Init(); }

  static void Doit(void* PlgID, long, long) { reinterpret_cast<CSimhlaVis*>(PlgID)->Doit(); }

  /// Server port "DrawFunction" class method stub, calls directly the instance method
  static void DrawFunction(void* PlgID, long Param1, long) {reinterpret_cast<CSimhlaVis*>(PlgID)->DrawFunction(reinterpret_cast<const ISimRenderContext*>(LongToPtr(Param1))); }

  /// Server port "DrawFunction2" class method stub, calls directly the instance method
  static void DrawFunction2(void* PlgID, long Param1, long) {reinterpret_cast<CSimhlaVis*>(PlgID)->DrawFunction2(reinterpret_cast<const ISimRenderContext*>(LongToPtr(Param1))); }

  // @}

  SimHlaProPrtList_t m_ProPorts;
  reqHlaPrtList_t m_ReqPorts;

  int ImageOffsetX;
  int ImageOffsetY;

  SimHlaMeasdata_t        m_hlaMeasdataETH; 
  SimHlaMeasdata_t        m_hlaMeasdataCAN; 

  struct s_labelTool
  {
    std::string oldRecFilename;
    int labelMode;
    int labelGroup;
    int labelClass;
  } m_labelTool;

private:
  /// @name receive port members
  /// @{
  //hlaInputA_t    m_InputA;
  //hlaInputB_t*   m_pInputB;

  /* HLA RTE INPUT */
  SimReceivePortBuffered<CPAR_HLAF_Parameter_t,     simOPAQUE_t>    m_rpCPAR_HLAF_Parameter;
  SimReceivePortBuffered<MonoCalibration_t,         simOPAQUE_t>    m_rpMonoCalibration;
  SimReceivePortBuffered<HLA_BusInputSignals_t,     simOPAQUE_t>    m_rpHlaBusInputSignals;
  SimReceivePortBuffered<VehSig_t,                  simOPAQUE_t>    m_rpVehSig;
  SimReceivePortBuffered<VehDyn_t,                  simOPAQUE_t>    m_rpVehDyn;
  SimReceivePortBuffered<CB_t_ProvidedOutputs_t,    simOPAQUE_t>    m_rpCB_t_ProvidedOutputs;
  SimReceivePortBuffered<LSD_EnvironmentData_t,     simOPAQUE_t>    m_rpLsdEnvironmentData;
  SimReceivePortBuffered<LSD_LightObjectList_t,     simOPAQUE_t>    m_rpLsdLightObjectList;
  SimReceivePortBuffered<LSD_LightList_t,           simOPAQUE_t>    m_rpLsdLightList;


  /* HLA RTE OUTPUT */
  SimReceivePortBuffered<AlgoCompState_t,             simOPAQUE_t> m_rpAlgoCompState;
  SimReceivePortBuffered<RTE_HLAF_HeadlightControl_t, simOPAQUE_t> m_rpRTE_HLAF_HeadlightControl;

  /* HLA internal meas freeze */
  SimReceivePort<t_ErrorHandling_ErrorStack, simOPAQUE_t> m_rpHLA_ErrorStack;
  SimReceivePort<HLAFData_t, simOPAQUE_t> m_rpHLAFData;

  bool m_bAlgoWasExecuted;
  sint8 m_redrawCounter;
  bool m_newImage;
  uint32 m_old_ui32_HLAR_CycleCount;
  uint32 m_old_ui32_ImageOdd_CycleCount;

  /* Sub menu definition */
  CSimVisuSubMenu m_general;

  /// @}

  void Reset();

  void Init();

  void Doit();

  void DrawFunction( const ISimRenderContext* pContext
                    );

  void DrawFunction2( const ISimRenderContext* pContext
                     );

  void SetupPorts();

  static CVersionInfoImpl CreateVersionInfoFromI32( const long version 
                                                   );

  void CalcROI( const SimHlaProPrtList_t* rteOutput, const reqHlaPrtList_t* rteInput 
               );

  void UpdateLockedObjects(void);

  void DrawBrightObjects( const ISimRenderContext*      pContext,
                          const reqHlaPrtList_t*        m_rteInputs,
                          const SimHlaProPrtList_t*     m_rteOutputs
                        );

  void DrawSimuVersion( const ISimRenderContext* pContext 
                       );

  void drawMouseStatus(const ISimRenderContext* pContext
                       );

  char* GetSigStatus(AlgoSignalState_t SignalState);

  void UpdateCameraSimu( const reqHlaPrtList_t* rteInput 
                        );

  bool OnMouseMessage( const ISimRenderContext& context,
                       const ISimWindowMessage& windowMessage
                      );

  bool OnKeyboardMessage( const ISimRenderContext& context,
                          const ISimWindowMessage& windowMessage
                         );

  bool OnWindowMessage( const ISimRenderContext& context,
                        const ISimWindowMessage& windowMessage
                       );
};

#endif // sim_swc___template_h__
