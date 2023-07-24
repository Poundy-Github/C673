
#ifndef sim_swc_vis_velodyne_h__
#define sim_swc_vis_velodyne_h__

#include "sim_swc_base.h"
#include "sim_swc_draw_base.h"
#include "sim_versioninfo_impl.h"
#include "simReceivePort.h"
#include "simDrawPort.h"

#include "vis_velodyne.h"

#include "algo_type.h"

#include "velodyne_processor/velodynePointCloudHDL64EPointCloud.h"

/// Class representing a SIM plugin to the SIM VFB MO in MTS
class CSimVisVelodyne 
  : public CSimSwcDrawBase
  , public CriticalSection
{
  enum MenuAction
  {
    MA_CM_INTENSITY = 0,
    MA_CM_DISTANCE,
    MA_CM_AUTOSAR_HEIGHT,        
    MA_CM_VELO_TIMESTAMP,        
    MA_PS_INCREASE,
    MA_PS_DECREASE,
    MA_SS_INCREASE,
    MA_SS_DECREASE,
    MA_MQ_ZERO,
    MA_MQ_ONE,
    MA_MQ_TWO,
    MA_MQ_THREE
  };

public:
  /// Constructor of the class.
  /// Gets called when the plugin is loaded.
  CSimVisVelodyne();

  /// Destructor of the class.
  /// Gets called when the plugin is unloaded.
  ~CSimVisVelodyne();

  /// @name Static server port methods
  /// @{

  /// Server port "Init" class method stub, calls directly the instance method
  static void Reset(void* PlgID, long, long) { reinterpret_cast<CSimVisVelodyne*>(PlgID)->Reset(); }

  /// Server port "Doit" class method stub, calls directly the instance method
  static void DoStore(void* PlgID, long, long) { reinterpret_cast<CSimVisVelodyne*>(PlgID)->DoStore(); }

  static void MenuHandler(void* PlgID, long Param1, long Param2)
  {
    reinterpret_cast<CSimVisVelodyne*>(PlgID)->MenuHandler(
      *reinterpret_cast<ISimRenderContext*>(LongToPtr(Param1)),
      static_cast<MenuAction>(Param2));
  }
  // @}

private:
  static const unsigned long MAX_REPORTED_PORT_ERRORS = 100; ///< Maximum reported receive port errors

  /// @name client port names, for reuse
  /// @{
  static const char* CP_CALCULATIONDONE;
  /// @}

  /// @name parameter names, for reuse
  /// @{
  static const char* PN_COLOR_MODE;
  static const char* PN_SUB_SAMPLE;
  static const char* PN_POINT_SIZE;
   
  /// @}

  /// @Draw Ports
  /// @{  
  SimDrawPort<CSimVisVelodyne> m_dpVelodyneAutosar;
  /// @}

  /// @name receive ports
  /// @{
  SimReceivePort<VelodyneHDL64EPointCloud_t*, simREFERENCE_t> m_rpMeasPointList;
  /// @}

  void Reset();
  void DoStore();
  void SetupPorts();

  void DrawVelodyneAutosar(const ISimRenderContext& ctx);

  void MenuHandler(ISimRenderContext& ctx, const MenuAction action);

  static CVersionInfoImpl CreateVersionInfoFromI32 (const long version);
  void setupParams( const ISimRenderContext& ctx );
  CVisVelodyne    m_visVelodyne;  
};

#endif // sim_swc___template_h__
