#pragma once
#include "sim_swc_base.h"
#include "sim_swc_draw_base.h"
#include "sim_swc_meas.h"
#include "sim_swc_cdl.h"
#include "sim_swc_gdv_ifc.h"
#include "sim_gdvfont_ifc.h"
#include "sim_versioninfo_impl.h"
#include "ctk_img_type.h"
#include "algo_type.h"

#include "simReceivePort.h"
#include "mouseState.h"
#include "keyboardState.h"
#include "arcBallNavigation.h"
#include "crosshair.h"

#include "renderContextMap.h"
#include "sim_perspectives_ver.h"

class CSimPerspectives
  : public CSimSwcDrawBase
{
public:
  CSimPerspectives();
  ~CSimPerspectives();

  // sim draw drawings
  static void RenderFPS (void* plgId, long param1, long) { SimDrawPortAdapter(plgId, param1, &RenderFPS); }

  static void ImageViewPixels (void* plgId, long param1, long) { SimDrawPortAdapter(plgId, param1, &ImageViewPixels); }
  static void ViewportViewPixels (void* plgId, long param1, long) { SimDrawPortAdapter(plgId, param1, &ViewportViewPixels); }
  static void DrawInteractions( void* plgId, long param1, long) { SimDrawPortAdapter(plgId, param1, &DrawInteractions); }

  static void CameraViewAutosar        (void* plgId, long param1, long) { SimDynViewDrawPortAdapter(plgId, param1, VM_CAM);         }
  static void CameraViewDynamicAutosar (void* plgId, long param1, long) { SimDynViewDrawPortAdapter(plgId, param1, VM_CAM_DYNAMIC); }
  static void FreeViewAutosar          (void* plgId, long param1, long) { SimDynViewDrawPortAdapter(plgId, param1, VM_FREE);        }
  static void SideViewAutosar          (void* plgId, long param1, long) { SimDynViewDrawPortAdapter(plgId, param1, VM_SIDE);        }
  static void BirdViewAutosar          (void* plgId, long param1, long) { SimDynViewDrawPortAdapter(plgId, param1, VM_BIRD);        }

  static void GridXY      (void* plgId, long param1, long) { SimDrawPortAdapter(plgId, param1, &GridXY); }
  static void GridXZ      (void* plgId, long param1, long) { SimDrawPortAdapter(plgId, param1, &GridXZ); }
  static void DrawHorizon (void* plgId, long param1, long) { SimDrawPortAdapter(plgId, param1, &DrawHorizon); }

  static void RenderCrosshair  (void* plgId, long param1, long) { SimDrawPortAdapter(plgId, param1, &RenderCrosshair); }

  // overloads
  bool OnMouseMessage    (const ISimRenderContext& context, const ISimWindowMessage& windowMessage);
  bool OnKeyboardMessage (const ISimRenderContext& context, const ISimWindowMessage& windowMessage);

private:
  struct GridDimension
  {
    GridDimension (
      const float& _xMin, const float& _xMax,
      const float& _yMin, const float& _yMax,
      const float& _zMin, const float& _zMax)
      : xMin(_xMin), xMax(_xMax)
      , yMin(_yMin), yMax(_yMax)
      , zMin(_zMin), zMax(_zMax) {}
    float xMin;
    float xMax;
    float yMin;
    float yMax;
    float zMin;
    float zMax;
  };

  struct ViewPerspectiveParam
  {
    ViewPerspectiveParam (
      const float& _eyeX,    const float& _eyeY,    const float& _eyeZ,
      const float& _centerX, const float& _centerY, const float& _centerZ,
      const float& _upX,     const float& _upY,     const float& _upZ,
      const float& _zNear,   const float& _zFar,
      const float& _shiftX,  const float& _shiftY                         )
      : eyeX(_eyeX),       eyeY(_eyeY),       eyeZ(_eyeZ)
      , centerX(_centerX), centerY(_centerY), centerZ(_centerZ)
      , upX(_upX),         upY(_upY),         upZ(_upZ)
      , shiftX(_shiftX),   shiftY(_shiftY)
      , zNear(_zNear),     zFar(_zFar)                           {}
    float eyeX;
    float eyeY;
    float eyeZ;
    float centerX;
    float centerY;
    float centerZ;
    float upX;
    float upY;
    float upZ;
    float zNear;
    float zFar;
    float shiftX;
    float shiftY;
  };

  struct GridStep
  {
    GridStep (const float& _xStep, const float& _yStep, const float& _zStep)
      : xStep(_xStep), yStep(_yStep), zStep(_zStep) {}
    float xStep;
    float yStep;
    float zStep;
  };

  class RGBAColor
  {
  public:
    RGBAColor(const float& _r = 1.0f, const float& _g = 1.0f, const float& _b = 1.0f, const float& _a = 1.0f)
      : r(_r), g(_g), b(_b), a(_a) {}
    float r;
    float g;
    float b;
    float a;
  };

  enum MenuAction
  {
    MA_VIEWMODE_DEFAULT = 0,
    MA_VIEWMODE_FREE,
    MA_VIEWMODE_BIRD,
    MA_VIEWMODE_SIDE,
    MA_VIEWMODE_CAM,
    MA_VIEWMODE_CAM_DYNAMIC
  };

  enum ViewMode
  {
    VM_DEFAULT = 0,
    VM_FREE,
    VM_BIRD,
    VM_SIDE,
    VM_CAM,
    VM_CAM_DYNAMIC
  };

  class ContextData
  {
  public:
    ContextData();

    struct FreeViewState
    {
      float             zoomFactor;
      float             shiftX;
      float             shiftY;
      ArcBallNavigation arcBall;
      Crosshair         crosshair;
      double            newRotPoint[3];
      bool              initialized;
      MouseState        lastMouse;

      FreeViewState()
        : zoomFactor(1), shiftX(0), shiftY(0), initialized(false) {}
    };

    struct BirdViewState
    {
      struct Rect
      {
        float x1;
        float y1;
        float x2;
        float y2;

        enum State
        {
          S_INVALID = 0,
          S_FIRST_CORNER,
          S_BOTH_CORNERS
        };

        float xMin() const { return std::min(x1, x2); }
        float xMax() const { return std::max(x1, x2); }
        float yMin() const { return std::min(y1, y2); }
        float yMax() const { return std::max(y1, y2); }
        float xSize() const { return std::abs(x1 - x2); }
        float ySize() const { return std::abs(y1 - y2); }
        State state;

        Rect()
            : state(S_INVALID)
        {
        }
      };

      Rect       zoomRect;
      bool       initialized;
      bool       flipViewPort;
      MouseState lastMouse;
      float      border[4];
      int        viewHeight;
      int        viewWidth;

      BirdViewState()
          : initialized(false)
          , flipViewPort(false)
          , viewHeight(0)
          , viewWidth(0)
      {
        std::memset(border, 0, sizeof(border));
      }
    };

    struct SideViewState
    {
      SideViewState()
        : bInit( false), bInSet( false) {}

      double xMinCur, xMaxCur, zMinCur, zMaxCur;
      double xMinMouse, xMaxMouse, zMinMouse, zMaxMouse;
      int xBeginMouse, yBeginMouse;
      bool bInit;
      bool bInSet;
    };

    struct ZoomState
    {
      ZoomState();

      void Init( double dImgWidth, double dImgHeight, int iViewportX, int iViewportY, double scale);
      bool SetMouse( int iMouseX, int iMouseY, double scaleNew, bool bDown, bool bCtrl);
      bool SetKeybord( bool bLeft, bool bRight, bool bUp, bool bDown, bool bControl);
      void Update();
      void GetFrustrumPar( double dCenterX, double dCenterY, double dFocalLength, GLdouble & left, GLdouble & right, GLdouble & bottom, GLdouble & top) const;
      void GetOrthoPar( GLdouble & left, GLdouble & right, GLdouble & bottom, GLdouble & top) const;
      void RenderRect2D() const;
      void RenderRect3D() const;
      void Reset();

    private:
      double m_dImgWidth, m_dImgHeight;
      int m_iViewportX, m_iViewportY;
      double m_dInitScale;
      double m_rectLeft, m_rectRight, m_rectTop, m_rectBottom;  ///< drawing rectangle in IMG dimensions
      double m_leftCur, m_rightCur, m_topCur, m_bottomCur;  ///< actual subset of image

      // State of mouse and keyboard for message handling
      bool   m_bMouseDown;                  ///< left mouse pressed
      bool   m_bControl;                    ///< control key pressed
      int    m_iMouseX, m_iMouseY;          ///< mouse pos from message handler to update
      int    m_iLastMouseX, m_iLastMouseY;  ///< mouse panning last state
      double m_dScaleNew;                   ///< mouse scroll
      bool   m_bInRect;                     ///< in rectangle movement
      bool   m_bInit;                       ///< delay CTOR
      bool   m_bReset;                      ///< send reset '0'
    };

    IGDVFont& fixedFont();
    IGDVFont& variableFont();

    MouseState&              mouse()                  { return m_mouse;            }
    KeyboardState&           keyboard()               { return m_keyboard;         }
    const ISimRenderContext* simRenderContext() const { return m_simRenderContext; }
    ISimRenderContext*       simRenderContext()       { return m_simRenderContext; }
    FreeViewState&           freeViewState()          { return m_freeViewState;    }
    BirdViewState&           birdViewState()          { return m_birdViewState;    }
    SideViewState&           sideViewState()          { return m_sideViewState;    }
    ZoomState&               zoomViewState()          { return m_camViewState;     }

    void setSimRenderContext(ISimRenderContext* ctx) { m_simRenderContext = ctx; }

    __int64 lastRenderTime() const { return m_lastRenderTime; }
    void setLastRenderTime(const __int64& t) { m_lastRenderTime = t; }

    double smoothedDT() const { return m_smoothedDT; }
    void setSmoothedDT(const double& t) { m_smoothedDT = t; }

    ViewMode getViewMode() const { return m_viewMode; }
    void setViewMode(ViewMode val) { m_viewMode = val; }
  private:
    MouseState         m_mouse;
    KeyboardState      m_keyboard;
    FreeViewState      m_freeViewState;
    BirdViewState      m_birdViewState;
    SideViewState      m_sideViewState;
    ZoomState          m_camViewState;
    ISimRenderContext* m_simRenderContext;
    __int64            m_lastRenderTime;
    double             m_smoothedDT;
    ViewMode           m_viewMode;
  };

  static const char* PN_VIEW_MODE;

  static const char* PN_GRID_DIMENSION_X_MIN;
  static const char* PN_GRID_DIMENSION_X_MAX;
  static const char* PN_GRID_DIMENSION_Y_MIN;
  static const char* PN_GRID_DIMENSION_Y_MAX;
  static const char* PN_GRID_DIMENSION_Z_MIN;
  static const char* PN_GRID_DIMENSION_Z_MAX;

  static const char* FREEVIEW_EYE_X;
  static const char* FREEVIEW_EYE_Y;
  static const char* FREEVIEW_EYE_Z;
  static const char* FREEVIEW_CENTER_X;
  static const char* FREEVIEW_CENTER_Y;
  static const char* FREEVIEW_CENTER_Z;
  static const char* FREEVIEW_UP_X;
  static const char* FREEVIEW_UP_Y;
  static const char* FREEVIEW_UP_Z;
  static const char* FREEVIEW_SHIFT_X;
  static const char* FREEVIEW_SHIFT_Y;

  static const char* FREEVIEW_FRUSTUM_Z_NEAR;
  static const char* FREEVIEW_FRUSTUM_Z_FAR;

  static const char* PN_GRID_STEP_X;
  static const char* PN_GRID_STEP_Y;
  static const char* PN_GRID_STEP_Z;

  static const char* PN_IMAGE_VIEW_FIXED_SCALE;

  static const char* PN_BIRDVIEW_FIXED_X_Y_RATIO;

  typedef RenderContextMap<ContextData> context_map;
  context_map m_contextData;
  CRITICAL_SECTION m_csContextData;

  // Parameters: Image
  SimReceivePort<unsigned long, simUI32_t> m_imageWidth;
  SimReceivePort<unsigned long, simUI32_t> m_imageHeight;

#ifdef MFC_REDUCED_ROI_WIDTH_L0
  const static unsigned int DEFAULT_IMG_WIDTH  = MFC_REDUCED_ROI_WIDTH_L0;
#else
  const static unsigned int DEFAULT_IMG_WIDTH  = 1024;
#endif

#ifdef MFC_REDUCED_ROI_HEIGHT_L0
  const static unsigned int DEFAULT_IMG_HEIGHT = MFC_REDUCED_ROI_HEIGHT_L0;
#else
  const static unsigned int DEFAULT_IMG_HEIGHT = 460;
#endif

  // Parameters: All as BLOB
#ifdef MONO_CALIBRATION_INTFVER
  SimReceivePort<MonoCalibration_t, simOPAQUE_t> m_camCalibrationData;
#endif
  SimReceivePort<CTKImageData_t*, simREFERENCE_t> m_CTKImage;
#ifdef IMAGE16_INTFVER
  SimReceivePort<ImageU16_t*,     simREFERENCE_t> m_RTEImage;
#endif

  uint32 m_uImgWidth;
  uint32 m_uImgHeight;

  void SetupAlgoPorts();

  // private helpers
  static void RenderXYGrid(
    const float& minX, const float& maxX, const float& stepX,
    const float& minY, const float& maxY, const float& stepY,
    const float lineWidth,
    const RGBAColor& color, const RGBAColor& xColor, const RGBAColor& yColor,
    const char* const xName, const char* const yName,
    ContextData& context);

  // the render methods
  void RenderFPS   (ContextData& context);
  void GridXY      (ContextData& context);
  void GridXZ      (ContextData& context);
  void DrawHorizon (ContextData& context);

  void ImageViewPixels   (ContextData& context);
  void ViewportViewPixels(ContextData& context);
  void DrawInteractions  (ContextData& context);
#ifdef MONO_CALIBRATION_INTFVER
  void CameraViewAutosar       (ContextData& context);
  void CameraViewDynamicAutosar(ContextData& context);
#endif
  void FreeViewAutosar         (ContextData& context);
  void SideViewAutosar         (ContextData& context);
  void BirdViewAutosar         (ContextData& context);

  void DynamicViewAutosar (ContextData& context, const ViewMode defaultMode);
#ifdef MONO_CALIBRATION_INTFVER
  void CameraView( ContextData& context, const MonoCalibrationIntrinsic_t& intrinsic, const PoseParameters_t& pose );
#endif

  static CVersionInfoImpl CreateVersionInfoFromI32 (const long version);

  static void MenuHandler(void* PlgID, long Param1, long Param2)
  {
    reinterpret_cast<CSimPerspectives*>(PlgID)->MenuHandler(
      *reinterpret_cast<ISimRenderContext*>(LongToPtr(Param1)),
      static_cast<MenuAction>(Param2));
  }
  void MenuHandler(ISimRenderContext& ctx, const MenuAction action);

  // helper to adapt to the 2 architectures sim draw and gdv
  static void SimDrawPortAdapter ( void* plgId, long param1, void (CSimPerspectives::*renderFunc)(ContextData&) );
  static void SimDynViewDrawPortAdapter( void* plgId, long param1, const ViewMode vm );

  void adjustImageWidthAndHeight( ISimRenderContext & simRenderContert);

  void RenderCrosshair(ContextData& context);
};
