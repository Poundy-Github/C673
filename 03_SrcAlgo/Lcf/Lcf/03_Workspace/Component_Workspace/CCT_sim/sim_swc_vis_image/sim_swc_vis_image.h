/*! \file **********************************************************************

  TEMPLATE VERSION:          1.2
                             changed parameters in cpp version to be a struct/class
                             added version management for template

*/
#ifndef sim_swc_vis_image_h__
#define sim_swc_vis_image_h__

#include "sim_swc_base.h"
#include "sim_swc_draw_base.h"
#include "sim_versioninfo_impl.h"

#include "sim_swc_gdv_ifc.h"

#include "simReceivePort.h"
#include "simDrawPort.h"

#include "scopeLock.h"

#include "algo_type.h"

#include "image.h"

#include <map>

/// Class representing a SIM plugin to the SIM VFB MO in MTS
class CSimVisImage
  : public CSimSwcDrawBase
  , public CriticalSection
{
public:
  /// Constructor of the class.
  /// Gets called when the plugin is loaded.
  CSimVisImage();

  /// @name Static server port methods
  /// @{
  /// Server port "Init" class method stub, calls directly the instance method
  static void Reset(void* PlgID, long, long) { reinterpret_cast<CSimVisImage*>(PlgID)->Reset(); }

  /// Server port "Init" class method stub, calls directly the instance method
  static void DoStore(void* PlgID, long, long) { reinterpret_cast<CSimVisImage*>(PlgID)->DoStore(); }
  // @}

private:
  static const char* PN_HIST_CUT;

  /// @name receive port members
  /// @{
  SimReceivePort<ImageU16_t*, simREFERENCE_t> m_rpImage;
  SimReceivePort<ImageU8_t* , simREFERENCE_t> m_rpImageUP1;
  SimReceivePort<ImageU8_t* , simREFERENCE_t> m_rpImageVP1;

#ifdef CIPP_WBR_INTFVER
  SimReceivePort<CippWhiteBalanceResult_t, simOPAQUE_t> m_rpCippWhiteBalanceResult;
#endif

#ifdef SAC_RTE_FEX_CONTROL_OUTPUT_INTFVER
  SimReceivePort<SacRteFexControlOutput_t, simOPAQUE_t> m_rpSacFexControlOutput;
#endif
  /// @}

  SimDrawPort<CSimVisImage> m_dpDraw;

  void Reset();
  void DoStore();
  void Draw(const ISimRenderContext& ctx);

  static CVersionInfoImpl CreateVersionInfoFromI32 (const long version);

  cct::CImage m_image;

  typedef std::map< const HGLRC, GLuint > Context2TextureMap_t;

  Context2TextureMap_t m_context2TextureMap;
};

#endif // sim_swc_vis_image_h__
