#ifndef sim_swc_yaw_rate_workaround_h__
#define sim_swc_yaw_rate_workaround_h__

#include "sim_swc_base.h"
#include "sim_versioninfo_impl.h"
#include "simReceivePort.h"
#include "Rte_Ext_Type.h"
#include "sim_algo_service_types.h"

#include <map>

# define C_PI          3.141592653589793238462643383279502884L /* pi */

#define DEG2RAD(deg_)  \
  ((deg_)*(C_PI/180.F))

/// Class representing a SIM plugin to the SIM VFB MO in MTS
class CSimYawRateWorkaround
  : public CSimSwcBase
{
public:
  /// Constructor of the class.
  /// Gets called when the plugin is loaded.
  CSimYawRateWorkaround();

  /// Destructor of the class.
  /// Gets called when the plugin is unloaded.
  ~CSimYawRateWorkaround();

  /// @name Static server port methods
  /// @{

  /// Server port "Reset" class method stub, calls directly the instance method
  static void Reset(void* PlgID, long, long) { reinterpret_cast<CSimYawRateWorkaround*>(PlgID)->Reset(); }

  /// Server port "Init" class method stub, calls directly the instance method
  static void Init(void* PlgID, long, long) { reinterpret_cast<CSimYawRateWorkaround*>(PlgID)->Init(); }

  /// Server port "Doit" class method stub, calls directly the instance method
  static void Doit(void* PlgID, long, long) { reinterpret_cast<CSimYawRateWorkaround*>(PlgID)->Doit(); }
  
  // @}

  void ReplaceVehSigYawRate();
  void ReplaceVehDynYawRate();
  void ComputeYawRate();

private:

  /// @name client port names, for reuse
  /// @{
  static const char* CP_CALCULATIONDONE;
  static const char* CP_DISTRIBUTEOUTPUTDATA;
  static const char* CP_DISTRIBUTEONLYDIRTYPORTS;
  /// @}

  /// @name provide port names
  /// @{
  static const char* PP_VEH_SIG;
  static const char* PP_VEH_DYN;
  static const char* PP_VEH_DYN_RADAR;

  //static const float CAN_YAW_RATE_LSB;

  /// @name receive ports
  /// @{
  SimReceivePort<VehSig_t,                            simOPAQUE_t>    m_rpVehSig;
  SimReceivePort<VehDyn_t,                            simOPAQUE_t>    m_rpVehDyn;
  SimReceivePort<VehDyn_t,                            simOPAQUE_t>    m_rpVehDynRadar;
  SimReceivePort<float,                               simF32_t>       m_rpYawRate;
  SimReceivePort<uint8,                               simUI8_t>       m_rpYawRateDiff;
  SimReceivePort<uint8,                               simUI8_t>       m_rpYRS1Error;
  SimReceivePort<uint8,                               simUI8_t>       m_rpYRS1InvalidFlag;
  SimReceivePort<uint8,                               simUI8_t>       m_rpYRS2Error;
  SimReceivePort<uint8,                               simUI8_t>       m_rpYRS2InvalidFlag;
  SimReceivePort<uint8,                               simUI8_t>       m_rpPowerSupplyInvalidFlag;
  /// @}

  /// @name provide ports
  /// @{
  VehSig_t m_ppVehSig;
  VehDyn_t m_ppVehDyn;
  /// @}

  bool  m_bYawRateComputed;
  float m_fYawRate;

  void Reset();
  void Init();
  void Doit();
  void SetupPorts();

  static CVersionInfoImpl CreateVersionInfoFromI32 (const long version);
};

#endif // sim_swc_yaw_rate_workaround_h__
