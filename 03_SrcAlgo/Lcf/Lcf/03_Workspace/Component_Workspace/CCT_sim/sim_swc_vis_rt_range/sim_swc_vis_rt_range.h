#ifndef sim_swc_vis_rt_range_h__
#define sim_swc_vis_rt_range_h__

#include "sim_swc_base.h"
#include "sim_swc_draw_base.h"
#include "sim_versioninfo_impl.h"
#include "simReceivePort.h"
#include "simDrawPort.h"

#include "vis_rt_range.h"

#include "algo_type.h"

/// Class representing a SIM plugin 
/// This SIM plugin visualizes RT range data by rendering a red line at the data location.
/// Signal URLs have to be configured in MTS and using the xml parameter file.
/// The process of recording is not standardized so far such that the temporal shift, the translation
/// in the world corrdinate system and scaling of data might be necessary. 
/// While translation and scaling needs to be done manually, the plugin is capable of autocorrelating
/// signals from the vehicle and the RT range data, e.g. ego speed.
class CSimVisRtRange 
  : public CSimSwcDrawBase
  , public CriticalSection
{
  /// Enumerator to identify the possible menu actions
  enum MenuAction
  {
    MA_TIME_SHIFT_INCREASE = 0,
    MA_TIME_SHIFT_DECREASE,
    MA_TRANSLATE_INCREASE,
    MA_TRANSLATE_DECREASE,
    MA_INVERTY,
    MA_SHOW_LEGEND,
    MA_CALC_AUTOCORRELATION
  };

public:

  /// TODO: Don't know why I got this one
  static const char* CP_CALCULATIONDONE;

  /// @name parameter names to identify the menu entries and the stored
  ///       parameters
  /// @{
  static const char* PN_TIME_SHIFT;
  static const char* PN_TRANSLATE;
  static const char* PN_INVERTY;
  static const char* PN_SHOW_LEGEND;
  static const char* PN_AUTOCORRELATE;
  /// @}

  /// Member variables indicating the state of the menu
  /// @{
  BOOL m_invertYMenuChecked;
  BOOL m_showLegendMenuChecked;
  /// @}

  /// Member variables indicating whether the menu is enabled or not
  /// @{
  BOOL m_invertYMenuEnabled;
  BOOL m_showLegendMenuEnabled;
  /// @}

  /// Constructor of the class.
  /// Gets called when the plugin is loaded.
  CSimVisRtRange();

  /// Destructor of the class.
  /// Gets called when the plugin is unloaded.
  ~CSimVisRtRange();

  /// Server port "Reset" class method stub, calls directly the instance method
  static void Reset(void* PlgID, long, long) { reinterpret_cast<CSimVisRtRange*>(PlgID)->Reset(); }

  /// Server port "DoStore" class method stub, calls directly the instance method
  static void DoStore(void* PlgID, long, long) { reinterpret_cast<CSimVisRtRange*>(PlgID)->DoStore(); }
  
  /// Server port "MenuHandler" class method stub, calls directly the instance method
  static void MenuHandler(void* PlgID, long Param1, long Param2)
  {
    reinterpret_cast<CSimVisRtRange*>(PlgID)->MenuHandler(
      *reinterpret_cast<ISimRenderContext*>(LongToPtr(Param1)),
      static_cast<MenuAction>(Param2));
  }
  // @}

  /// Implementation of virtual function to load a parameter file
  void SetIniFileName(const char* szIniFileName);

private:

  /// @name receive ports
  /// @{
  SimReceivePort<sint64                , simI64_t>    m_rpAbsoluteTimestamp;            ///< Allows time shift functionality
  SimReceivePort<float32               , simF32_t>    m_rpAutoCorrelationSignalMeas;    ///< Camera data for autocorrelation, e.g. ego speed
  SimReceivePort<float32               , simF32_t>    m_rpAutoCorrelationSignalRTRange; ///< RT Range Hunder data for autocorrelation, e.g. ego speed
  SimReceivePort<sint32                , simI32_t>    m_rpRtRangeForward;               ///< Relative X  position measured by RT Range (vcl 1) 
  SimReceivePort<sint32                , simI32_t>    m_rpRtRangeLateral;               ///< Relative Y  position measured by RT Range (vcl 1)    
  SimReceivePort<float32               , simF32_t>    m_rpRtRangeVelForward;            ///< VX position measured by RT Range (vcl 1) (text display only) 
  SimReceivePort<float32               , simF32_t>    m_rpRtRangeVelLateral;            ///< VY position measured by RT Range (vcl 1) (text display only) 
  SimReceivePort<float32               , simF32_t>    m_rpRtRangeForward2;              ///< Relative X  position measured by RT Range (vcl 2) 
  SimReceivePort<float32               , simF32_t>    m_rpRtRangeLateral2;              ///< Relative Y  position measured by RT Range (vcl 2) 
  SimReceivePort<float32               , simF32_t>    m_rpRtRangeVelForward2;           ///< VX position measured by RT Range (vcl 2)  (text display only)
  SimReceivePort<float32               , simF32_t>    m_rpRtRangeVelLateral2;           ///< VY position measured by RT Range (vcl 2)  (text display only)
  /// @}

  /// Stored string to ini parameter file
  std::string m_ssIniFilePath;

  /// Methods called indirectly from the server port
  /// @{
  void Reset();
  void Doit();
  void DoStore();
  void MenuHandler(ISimRenderContext& ctx, const MenuAction action);
 /// @}

  /// Helper methods to provide the functionality
  /// @{
  void setupPorts();
  void readIniFile();
  void drawRTRange(const ISimRenderContext& ctx);
  void setupParams(const ISimRenderContext& ctx);
 /// @}

  /// @Draw Ports
  /// @{
  SimDrawPort<CSimVisRtRange> m_dpDrawRtRange;
  /// @}

  /// Class providing the visualization, data storage and basic algorithms
  CVisRtRange    m_visRtRange;
};

#endif 
