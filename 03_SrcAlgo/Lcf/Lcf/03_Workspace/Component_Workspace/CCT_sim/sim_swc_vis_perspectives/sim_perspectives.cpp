#include "stdafx.h"
#include "resource.h"
#include "sim_perspectives.h"
#include "scopeLock.h"
#include "sim_gl_tools.h"

#include "sim_swc_gdv_ifc.h"
#include "sim_renderparam_helper.h"

#include <cmath>
#include <limits>
#include <sstream>
#include <iomanip>
#include <algorithm>

#define IMAGE_WIDTH    "ImageWidth"
#define IMAGE_HEIGHT   "ImageHeight"

const char* CSimPerspectives::PN_VIEW_MODE = "ViewMode";

const char* CSimPerspectives::PN_GRID_DIMENSION_X_MIN = "GridDimensionXMin";
const char* CSimPerspectives::PN_GRID_DIMENSION_X_MAX = "GridDimensionXMax";
const char* CSimPerspectives::PN_GRID_DIMENSION_Y_MIN = "GridDimensionYMin";
const char* CSimPerspectives::PN_GRID_DIMENSION_Y_MAX = "GridDimensionYMax";
const char* CSimPerspectives::PN_GRID_DIMENSION_Z_MIN = "GridDimensionZMin";
const char* CSimPerspectives::PN_GRID_DIMENSION_Z_MAX = "GridDimensionZMax";

const char* CSimPerspectives::FREEVIEW_EYE_X          = "FreeViewEyeX";
const char* CSimPerspectives::FREEVIEW_EYE_Y          = "FreeViewEyeY";
const char* CSimPerspectives::FREEVIEW_EYE_Z          = "FreeViewEyeZ";
const char* CSimPerspectives::FREEVIEW_CENTER_X       = "FreeViewCenterX";
const char* CSimPerspectives::FREEVIEW_CENTER_Y       = "FreeViewCenterY";
const char* CSimPerspectives::FREEVIEW_CENTER_Z       = "FreeViewCenterZ";
const char* CSimPerspectives::FREEVIEW_UP_X           = "FreeViewUpX";
const char* CSimPerspectives::FREEVIEW_UP_Y           = "FreeViewUpY";
const char* CSimPerspectives::FREEVIEW_UP_Z           = "FreeViewUpZ";
const char* CSimPerspectives::FREEVIEW_SHIFT_X        = "FreeViewShiftX";
const char* CSimPerspectives::FREEVIEW_SHIFT_Y        = "FreeViewShiftY";
const char* CSimPerspectives::FREEVIEW_FRUSTUM_Z_NEAR = "FreeViewFrustumZNear";
const char* CSimPerspectives::FREEVIEW_FRUSTUM_Z_FAR  = "FreeViewFrustumZFar";

const char* CSimPerspectives::PN_GRID_STEP_X = "GridStepX";
const char* CSimPerspectives::PN_GRID_STEP_Y = "GridStepY";
const char* CSimPerspectives::PN_GRID_STEP_Z = "GridStepZ";

const char* CSimPerspectives::PN_IMAGE_VIEW_FIXED_SCALE = "ImageViewFixedScale";

const char* CSimPerspectives::PN_BIRDVIEW_FIXED_X_Y_RATIO = "BirdViewFixedXY_Ratio";

CSimPerspectives::CSimPerspectives()
: CSimSwcDrawBase ( 10, "__BufferDataID", simI64_t, "__DoStore", "..\\gia_sim\\adapter.dll" )

// Parameters: Image
, m_imageWidth (this, "ImageWidth",  DEFAULT_IMG_WIDTH)
, m_imageHeight(this, "ImageHeight", DEFAULT_IMG_HEIGHT)
#ifdef IMAGE16_INTFVER
, m_RTEImage(this, "RTEImage", NULL)
#endif
, m_CTKImage(this, "CTKImage", NULL)
, m_uImgWidth(DEFAULT_IMG_WIDTH)
, m_uImgHeight(DEFAULT_IMG_HEIGHT)
#ifdef MONO_CALIBRATION_INTFVER
, m_camCalibrationData (this, "CamCalibrationData[MonoCalibration_t]", MonoCalibration_t())
#endif
{
  // sim draw
  AddDrawServerPort ("FPS"                , RenderFPS          , this);
  AddDrawServerPort ("ImageViewPixels"    , ImageViewPixels    , this);
  AddDrawServerPort ("ViewportViewPixels" , ViewportViewPixels , this);
  AddDrawServerPort ("DrawInteractions"   , DrawInteractions   , this);

  AddDrawServerPort ("CameraViewAutosar"        ,        CameraViewAutosar , this);
  AddDrawServerPort ("CameraViewDynamicAutosar" , CameraViewDynamicAutosar , this);
  AddDrawServerPort ("FreeViewAutosar"          ,          FreeViewAutosar , this);
  AddDrawServerPort ("SideViewAutosar"          ,          SideViewAutosar , this);
  AddDrawServerPort ("BirdViewAutosar"          ,          BirdViewAutosar , this);

  AddDrawServerPort ("GridXY"     , GridXY          , this);
  AddDrawServerPort ("GridXZ"     , GridXZ          , this);
  AddDrawServerPort ("DrawHorizon", DrawHorizon     , this);
  AddDrawServerPort ("Crosshair"  , RenderCrosshair , this);

#ifdef IMAGE16_INTFVER
  m_RTEImage.setAutoLock(true);
#endif
  m_CTKImage.setAutoLock(true);

  // critical section
  ::InitializeCriticalSection(&m_csContextData);

  // menus
  AttachFunctionToMenu("Default",     MenuHandler, this, MA_VIEWMODE_DEFAULT);
  AttachFunctionToMenu("FreeView",    MenuHandler, this, MA_VIEWMODE_FREE);
  AttachFunctionToMenu("BirdView",    MenuHandler, this, MA_VIEWMODE_BIRD);
  AttachFunctionToMenu("SideView",    MenuHandler, this, MA_VIEWMODE_SIDE);
  AttachFunctionToMenu("CamViewCal",  MenuHandler, this, MA_VIEWMODE_CAM);
  AttachFunctionToMenu("CamViewDyn",  MenuHandler, this, MA_VIEWMODE_CAM_DYNAMIC);

  // View Mode parameter
  const unsigned char viewMode = static_cast<unsigned char>(VM_DEFAULT);
  AddLocalParameter(PN_VIEW_MODE, simUI8_t, &viewMode, sizeof(viewMode));

  // Parameters: Grid
  const GridDimension gridDimension = GridDimension(0.0F, 70.0F, -5.0F, 5.0F, 0.0F, 3.0F);
  AddLocalParameter(PN_GRID_DIMENSION_X_MIN, simF32_t, &gridDimension.xMin, sizeof(gridDimension.xMin));
  AddLocalParameter(PN_GRID_DIMENSION_X_MAX, simF32_t, &gridDimension.xMax, sizeof(gridDimension.xMax));
  AddLocalParameter(PN_GRID_DIMENSION_Y_MIN, simF32_t, &gridDimension.yMin, sizeof(gridDimension.yMin));
  AddLocalParameter(PN_GRID_DIMENSION_Y_MAX, simF32_t, &gridDimension.yMax, sizeof(gridDimension.yMax));
  AddLocalParameter(PN_GRID_DIMENSION_Z_MIN, simF32_t, &gridDimension.zMin, sizeof(gridDimension.zMin));
  AddLocalParameter(PN_GRID_DIMENSION_Z_MAX, simF32_t, &gridDimension.zMax, sizeof(gridDimension.zMax));

  // Parameters: freeViewPerspectiveParam
  const ViewPerspectiveParam freeViewPerspectiveParam = ViewPerspectiveParam(-25.F, -25.F, 25.F, 20.F, 0.F, 0.F, 0.F, 0.F, 1.F, 1.F, 1000.F, 0.F, 0.F);
  AddLocalParameter(FREEVIEW_EYE_X,          simF32_t, &freeViewPerspectiveParam.eyeX,    sizeof(freeViewPerspectiveParam.eyeX));
  AddLocalParameter(FREEVIEW_EYE_Y,          simF32_t, &freeViewPerspectiveParam.eyeY,    sizeof(freeViewPerspectiveParam.eyeY));
  AddLocalParameter(FREEVIEW_EYE_Z,          simF32_t, &freeViewPerspectiveParam.eyeZ,    sizeof(freeViewPerspectiveParam.eyeZ));
  AddLocalParameter(FREEVIEW_CENTER_X,       simF32_t, &freeViewPerspectiveParam.centerX, sizeof(freeViewPerspectiveParam.centerX));
  AddLocalParameter(FREEVIEW_CENTER_Y,       simF32_t, &freeViewPerspectiveParam.centerY, sizeof(freeViewPerspectiveParam.centerY));
  AddLocalParameter(FREEVIEW_CENTER_Z,       simF32_t, &freeViewPerspectiveParam.centerZ, sizeof(freeViewPerspectiveParam.centerZ));
  AddLocalParameter(FREEVIEW_UP_X,           simF32_t, &freeViewPerspectiveParam.upX,     sizeof(freeViewPerspectiveParam.upX));
  AddLocalParameter(FREEVIEW_UP_Y,           simF32_t, &freeViewPerspectiveParam.upY,     sizeof(freeViewPerspectiveParam.upY));
  AddLocalParameter(FREEVIEW_UP_Z,           simF32_t, &freeViewPerspectiveParam.upZ,     sizeof(freeViewPerspectiveParam.upZ));
  AddLocalParameter(FREEVIEW_SHIFT_X,        simF32_t, &freeViewPerspectiveParam.shiftX,  sizeof(freeViewPerspectiveParam.shiftX));
  AddLocalParameter(FREEVIEW_SHIFT_Y,        simF32_t, &freeViewPerspectiveParam.shiftY,  sizeof(freeViewPerspectiveParam.shiftY));
  AddLocalParameter(FREEVIEW_FRUSTUM_Z_NEAR, simF32_t, &freeViewPerspectiveParam.zNear,   sizeof(freeViewPerspectiveParam.zNear));
  AddLocalParameter(FREEVIEW_FRUSTUM_Z_FAR,  simF32_t, &freeViewPerspectiveParam.zFar,    sizeof(freeViewPerspectiveParam.zFar));

  const GridStep gridStep = GridStep(5.0F, 1.0F, 0.5F);
  AddLocalParameter(PN_GRID_STEP_X, simF32_t, &gridStep.xStep, sizeof(gridStep.xStep));
  AddLocalParameter(PN_GRID_STEP_Y, simF32_t, &gridStep.yStep, sizeof(gridStep.yStep));
  AddLocalParameter(PN_GRID_STEP_Z, simF32_t, &gridStep.zStep, sizeof(gridStep.zStep));

  AddLocalParameter( IMAGE_WIDTH , simUI32_t, &DEFAULT_IMG_WIDTH , sizeof(DEFAULT_IMG_WIDTH));
  AddLocalParameter( IMAGE_HEIGHT, simUI32_t, &DEFAULT_IMG_HEIGHT, sizeof(DEFAULT_IMG_HEIGHT));

  // Parameters: ImageViewPixels
  const float imageViewFixedScale = 0.0F;
  AddLocalParameter(PN_IMAGE_VIEW_FIXED_SCALE, simF32_t, &imageViewFixedScale, sizeof(float));

  const uint8 birdViewFixedXY_ratio = 0;
  AddLocalParameter(PN_BIRDVIEW_FIXED_X_Y_RATIO, simUI8_t, &birdViewFixedXY_ratio, sizeof(uint8));

  SetupAlgoPorts();
}

CSimPerspectives::~CSimPerspectives()
{
  ::DeleteCriticalSection(&m_csContextData);
}

void CSimPerspectives::SetupAlgoPorts()
{
#ifdef MONO_CALIBRATION_INTFVER
  m_camCalibrationData.setVersion( "MonoCalibration_t", CreateVersionInfoFromI32(MONO_CALIBRATION_INTFVER) );
#endif
#ifdef IMAGE16_INTFVER
  m_RTEImage.setVersion          ( "ImageU16_t"       , CreateVersionInfoFromI32(IMAGE16_INTFVER)          );
#endif
}

void CSimPerspectives::RenderFPS( ContextData& context )
{
  static const double SMOOTHFACTOR = 0.05;
  __int64 frequency;
  __int64 currentTime;
  ::QueryPerformanceFrequency(reinterpret_cast<LARGE_INTEGER*>(&frequency));
  ::QueryPerformanceCounter  (reinterpret_cast<LARGE_INTEGER*>(&currentTime));

  if (context.lastRenderTime() > 0)
  {
    const double dT = static_cast<double>(currentTime - context.lastRenderTime()) / static_cast<double>(frequency);

    if (context.smoothedDT() > 0)
    {
      context.setSmoothedDT(context.smoothedDT() * (1 - SMOOTHFACTOR) + dT * SMOOTHFACTOR);
    }
    else
    {
      context.setSmoothedDT(dT);
    }
  }
  context.setLastRenderTime(currentTime);

  // draw that
  GLint viewport[4];
  glGetIntegerv(GL_VIEWPORT, viewport);

  glMatrixMode(GL_PROJECTION);
  glPushMatrix();
  glLoadIdentity();
  glOrtho(0, viewport[2] - 1, 0, viewport[3] - 1, -1, 1);

  glMatrixMode(GL_MODELVIEW);
  glPushMatrix();
  glLoadIdentity();

  IGDVFont& font = context.fixedFont();

  const double fps  = 1.0 / context.smoothedDT();
  const double dtms = context.smoothedDT() * 1000.0;

  const char format[] = "fps: %.1f, dT: %.1fms";
  const int textWidth  = _scprintf(format, fps, dtms) * static_cast<int>(font.GetCharWidth('X'));
  const int textHeight = static_cast<int>(font.GetCharHeight('X'));

  glColor3d(0, 0, 0);
  glBegin(GL_QUADS);
  {
    glVertex2i(viewport[2] - textWidth - 10,  viewport[3]);
    glVertex2i(viewport[2] - textWidth - 10,  viewport[3] - textHeight - 5);
    glVertex2i(viewport[2]                 ,  viewport[3] - textHeight - 5);
    glVertex2i(viewport[2]                 ,  viewport[3]);
  }
  glEnd();

  font.BeginRender();
  font.SetTextColor(1, 1, 1, 1);
  font.RenderTextf(viewport[2] - textWidth - 5, viewport[3] - 3, 0, format, fps, dtms);
  font.EndRender();

  glPopMatrix();
  glMatrixMode(GL_PROJECTION);
  glPopMatrix();
  glMatrixMode(GL_MODELVIEW);
}

void CSimPerspectives::GridXY(ContextData& context)
{
  const GridDimension gridDimension = GridDimension(
    CSimRenderParamHelper::GetLocalParamByRef<float>(*context.simRenderContext(), PN_GRID_DIMENSION_X_MIN),
    CSimRenderParamHelper::GetLocalParamByRef<float>(*context.simRenderContext(), PN_GRID_DIMENSION_X_MAX),
    CSimRenderParamHelper::GetLocalParamByRef<float>(*context.simRenderContext(), PN_GRID_DIMENSION_Y_MIN),
    CSimRenderParamHelper::GetLocalParamByRef<float>(*context.simRenderContext(), PN_GRID_DIMENSION_Y_MAX),
    CSimRenderParamHelper::GetLocalParamByRef<float>(*context.simRenderContext(), PN_GRID_DIMENSION_Z_MIN),
    CSimRenderParamHelper::GetLocalParamByRef<float>(*context.simRenderContext(), PN_GRID_DIMENSION_Z_MAX) );

  const GridStep gridStep = GridStep(
    CSimRenderParamHelper::GetLocalParamByRef<float>(*context.simRenderContext(), PN_GRID_STEP_X),
    CSimRenderParamHelper::GetLocalParamByRef<float>(*context.simRenderContext(), PN_GRID_STEP_Y),
    CSimRenderParamHelper::GetLocalParamByRef<float>(*context.simRenderContext(), PN_GRID_STEP_Z) );

  RenderXYGrid(
    gridDimension.xMin, gridDimension.xMax, gridStep.xStep,
    gridDimension.yMin, gridDimension.yMax, gridStep.yStep,
    1, RGBAColor(0.5f, 0.5f, 0.5f, 1),
    RGBAColor(1, 0, 0, 1), RGBAColor(0, 1, 0, 1),
    "x", "y",
    context);
}

void CSimPerspectives::GridXZ(ContextData& context)
{
  const GridDimension gridDimension = GridDimension(
    CSimRenderParamHelper::GetLocalParamByRef<float>(*context.simRenderContext(), PN_GRID_DIMENSION_X_MIN),
    CSimRenderParamHelper::GetLocalParamByRef<float>(*context.simRenderContext(), PN_GRID_DIMENSION_X_MAX),
    CSimRenderParamHelper::GetLocalParamByRef<float>(*context.simRenderContext(), PN_GRID_DIMENSION_Y_MIN),
    CSimRenderParamHelper::GetLocalParamByRef<float>(*context.simRenderContext(), PN_GRID_DIMENSION_Y_MAX),
    CSimRenderParamHelper::GetLocalParamByRef<float>(*context.simRenderContext(), PN_GRID_DIMENSION_Z_MIN),
    CSimRenderParamHelper::GetLocalParamByRef<float>(*context.simRenderContext(), PN_GRID_DIMENSION_Z_MAX) );

  const GridStep gridStep = GridStep(
    CSimRenderParamHelper::GetLocalParamByRef<float>(*context.simRenderContext(), PN_GRID_STEP_X),
    CSimRenderParamHelper::GetLocalParamByRef<float>(*context.simRenderContext(), PN_GRID_STEP_Y),
    CSimRenderParamHelper::GetLocalParamByRef<float>(*context.simRenderContext(), PN_GRID_STEP_Z) );

  glPushMatrix();
  {
    // move to y max and rotate that we can reuse the drawing method
    glTranslatef(0, gridDimension.yMax, 0);
    glRotated(90, 1, 0, 0);

    RenderXYGrid(
      gridDimension.xMin, gridDimension.xMax, gridStep.xStep,
      gridDimension.zMin, gridDimension.zMax, gridStep.zStep,
      1, RGBAColor(0.5f, 0.5f, 0.5f, 1),
      RGBAColor(1, 0, 0, 1), RGBAColor(0, 0, 1, 1),
      "x", "z",
      context);
  }
  glPopMatrix();
}

void CSimPerspectives::ImageViewPixels(ContextData& context)
{
  // get viewport to keep the aspect ratio of the viewing scene
  GLint viewport[4];
  glGetIntegerv(GL_VIEWPORT, viewport);

  // default scale from parameter
  float scale = CSimRenderParamHelper::GetLocalParamByRef<float>(*context.simRenderContext(), PN_IMAGE_VIEW_FIXED_SCALE);

  //get image width/height
  adjustImageWidthAndHeight( *context.simRenderContext());

  // create the needed 2D perspective
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();

  GLdouble left, right, bottom, top;
  context.zoomViewState().Init( m_uImgWidth, m_uImgHeight, viewport[2], viewport[3], scale);
  context.zoomViewState().Update();
  context.zoomViewState().GetOrthoPar( left, right, bottom, top);
  glOrtho( left, right, bottom, top, -1, 1);

  // align the 3d world according the camera extrinsic
  // calibration properties
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();

  context.zoomViewState().RenderRect2D();
}

void CSimPerspectives::ViewportViewPixels(ContextData & context)
{
  // get viewport to keep the aspect ratio of the viewing scene
  GLint viewport[4];
  glGetIntegerv(GL_VIEWPORT, viewport);

  // create the needed 2D perspective
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  GLdouble left, right, bottom, top;
  context.zoomViewState().Init( viewport[2], viewport[3], viewport[2], viewport[3], 1);
  context.zoomViewState().Update();
  context.zoomViewState().GetOrthoPar( left, right, bottom, top);
  glOrtho(left, right, bottom, top, -1, 1);

  // calibration properties
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
}

#ifdef MONO_CALIBRATION_INTFVER
void CSimPerspectives::CameraViewAutosar(ContextData& context)
{
  CameraView(context, m_camCalibrationData.val().sIntrinsic, m_camCalibrationData.val().sPoseCalibration);
}

void CSimPerspectives::CameraViewDynamicAutosar(ContextData& context)
{
  CameraView(context, m_camCalibrationData.val().sIntrinsic, m_camCalibrationData.val().sPoseDynamic);
}

void CSimPerspectives::CameraView( ContextData& context, const MonoCalibrationIntrinsic_t& intrinsic, const PoseParameters_t& pose )
{
  // get viewport to keep the aspect ratio of the viewing scene
  GLint viewport[4];
  glGetIntegerv(GL_VIEWPORT, viewport);

  //get image width/height
  adjustImageWidthAndHeight( *context.simRenderContext());

  // default scale from parameter
  float scale = CSimRenderParamHelper::GetLocalParamByRef<float>(*context.simRenderContext(), PN_IMAGE_VIEW_FIXED_SCALE);

  context.zoomViewState().Init( m_uImgWidth, m_uImgHeight, viewport[2], viewport[3], scale);
  context.zoomViewState().Update();
  context.zoomViewState().RenderRect3D();  // MUST be in front of perspective modification, because it modifies perspectives as well

  // create the needed projective perspective
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();


  GLdouble left, right, bottom, top;
  context.zoomViewState().GetFrustrumPar( intrinsic.fCenterX, intrinsic.fCenterY, intrinsic.fFocalX, left, right, bottom, top);

  // frustum according intrinsics parameters & according viewport geometry (to be compatible with old 2d vis)
  glFrustum( -left, right, bottom, -top, 1, 1100);

  // align the 3d world according the camera extrinsic
  // calibration properties
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();

  // move z-axis to point forward (we want to have a right hand coordinate system)
  glScalef(1, 1, -1);

  // rotate gl default cam to autosar coordinates (x -> forward, y -> left, z -> up)
  glRotatef( 90, 1, 0, 0);
  glRotatef( 90, 0, 0, 1);

  // rotate according extrinsics (in order -yaw, -pitch, -roll)
  // in reverse direction because we are moving from camera to world
  glRotated(-pose.fYaw   * 180 / M_PI, 0, 0, 1);
  glRotated(-pose.fPitch * 180 / M_PI, 0, 1, 0);
  glRotated(-pose.fRoll  * 180 / M_PI, 1, 0, 0);

  // move according extrinsic mount position
  // in reverse direction because we are moving from camera to world
  glTranslatef(-pose.fTx, -pose.fTy, -pose.fTz);

  // here we are in autosar coordinates according to camera calibration
  // and viewing the scene through the camera
  // any following do render, that uses this perspective could render 3d
  // objects and thei get projected on to the viewport as if they are
  // monitored by a pinhole camera
}
#endif

void CSimPerspectives::FreeViewAutosar(ContextData& context)
{
  // link context specific data
  MouseState& mouse          = context.mouse();
  KeyboardState& keyboard    = context.keyboard();
  MouseState& lastMouse      = context.freeViewState().lastMouse;
  float& zoomFactor          = context.freeViewState().zoomFactor;
  float& shiftX              = context.freeViewState().shiftX;
  float& shiftY              = context.freeViewState().shiftY;
  bool&  viewInitialized     = context.freeViewState().initialized;
  ArcBallNavigation& arcBall = context.freeViewState().arcBall;

  // check which kind of modification will be done by the mouse
  enum ModificationState
  {
    MODIFY_NOTHING = 0,

    MOUSE_MODIFY_ROT,
    MOUSE_MODIFY_ROTPOINT,
    MOUSE_MODIFY_PAN,
    MOUSE_MODIFY_ZOOM,

    KEY_MODIFY_PAN,
    KEY_MODIFY_ZOOM,
    KEY_MODIFY_ROT
  };

  ModificationState modificationState =  MODIFY_NOTHING;

  if ( mouse.left.down )
  {
    if (mouse.control)
    {
      modificationState = MOUSE_MODIFY_PAN;
    }
    else if (mouse.shift)
    {
      modificationState = MOUSE_MODIFY_ROTPOINT;
    }
    else
    {
      modificationState = MOUSE_MODIFY_ROT;
    }
  }
  else if (mouse.scroll != 0)
  {
    modificationState = MOUSE_MODIFY_ZOOM;
  }
  else if (keyboard.someDown())
  {
    if (keyboard.isDown(VK_CONTROL))
    {
      modificationState = KEY_MODIFY_PAN;
    }
    else
    {
      if ( keyboard.isDown(VK_ADD)
        || keyboard.isDown(VK_SUBTRACT)
        || keyboard.isDown(VK_OEM_PLUS)
        || keyboard.isDown(VK_OEM_MINUS) )
      {
        modificationState = KEY_MODIFY_ZOOM;
      }
      else
      {
        modificationState = KEY_MODIFY_ROT;
      }
    }
  }

  // apply zooming if needed
  if ( modificationState == MOUSE_MODIFY_ZOOM)
  {
    const float scrollDirection = (mouse.scroll > 0) ? 1.f : -1.f;
    zoomFactor *= std::pow(1.1f, scrollDirection);
  }
  else if (modificationState == KEY_MODIFY_ZOOM)
  {
    if ( keyboard.isDown(VK_ADD)
      || keyboard.isDown(VK_OEM_PLUS) )
    {
      zoomFactor *= std::pow(1.1f, 1.f);
    }
    else if ( keyboard.isDown(VK_SUBTRACT)
      ||      keyboard.isDown(VK_OEM_MINUS) )
    {
      zoomFactor *= std::pow(1.1f, -1.f);
    }
  }

  // apply panning if needed
  if ( modificationState == MOUSE_MODIFY_PAN )
  {
    shiftX += mouse.x     - lastMouse.x;
    shiftY += lastMouse.y - mouse.y;
  }
  else if ( modificationState == KEY_MODIFY_PAN )
  {
    if (keyboard.isDown(VK_LEFT))
    {
      shiftX -= 10;
    }
    else if (keyboard.isDown(VK_RIGHT))
    {
      shiftX += 10;
    }

    if (keyboard.isDown(VK_UP))
    {
      shiftY += 10;
    }
    else if (keyboard.isDown(VK_DOWN))
    {
      shiftY -= 10;
    }
  }

  // check for reset pressed (the "0" key)
  if ( keyboard.isOnlyDown('0') )
  {
    // reset
    shiftX          = CSimRenderParamHelper::GetLocalParamByRef<float>(*context.simRenderContext(), FREEVIEW_SHIFT_X);
    shiftY          = CSimRenderParamHelper::GetLocalParamByRef<float>(*context.simRenderContext(), FREEVIEW_SHIFT_Y);
    zoomFactor      = 1;
    viewInitialized = false;
  }

  // fetch current viewport
  GLint viewport[4];
  glGetIntegerv(GL_VIEWPORT, viewport);

  // setup projection
  const int& vpw = viewport[2];
  const int& vph = viewport[3];
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();

  const float32 zNear = CSimRenderParamHelper::GetLocalParamByRef<float>(*context.simRenderContext(), FREEVIEW_FRUSTUM_Z_NEAR);
  const float32 zFar  = CSimRenderParamHelper::GetLocalParamByRef<float>(*context.simRenderContext(), FREEVIEW_FRUSTUM_Z_FAR);

  glFrustum(
    (-vpw/2.f - shiftX) / vpw, (vpw/2.f - shiftX) / vpw,
    (-vph/2.f - shiftY) / vpw, (vph/2.f - shiftY) / vpw,
    zNear, zFar);

  // setup modelview
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();

  if (viewInitialized)
  {
    // restore last model view
    glMultMatrixd(arcBall.lastModelMatrix());
  }
  else
  {
    // setup default view
    const float32 eyeX    = CSimRenderParamHelper::GetLocalParamByRef<float>(*context.simRenderContext(), FREEVIEW_EYE_X);
    const float32 eyeY    = CSimRenderParamHelper::GetLocalParamByRef<float>(*context.simRenderContext(), FREEVIEW_EYE_Y);
    const float32 eyeZ    = CSimRenderParamHelper::GetLocalParamByRef<float>(*context.simRenderContext(), FREEVIEW_EYE_Z);
    const float32 centerX = CSimRenderParamHelper::GetLocalParamByRef<float>(*context.simRenderContext(), FREEVIEW_CENTER_X);
    const float32 centerY = CSimRenderParamHelper::GetLocalParamByRef<float>(*context.simRenderContext(), FREEVIEW_CENTER_Y);
    const float32 centerZ = CSimRenderParamHelper::GetLocalParamByRef<float>(*context.simRenderContext(), FREEVIEW_CENTER_Z);
    const float32 upX     = CSimRenderParamHelper::GetLocalParamByRef<float>(*context.simRenderContext(), FREEVIEW_UP_X);
    const float32 upY     = CSimRenderParamHelper::GetLocalParamByRef<float>(*context.simRenderContext(), FREEVIEW_UP_Y);
    const float32 upZ     = CSimRenderParamHelper::GetLocalParamByRef<float>(*context.simRenderContext(), FREEVIEW_UP_Z);
    shiftX                = CSimRenderParamHelper::GetLocalParamByRef<float>(*context.simRenderContext(), FREEVIEW_SHIFT_X);
    shiftY                = CSimRenderParamHelper::GetLocalParamByRef<float>(*context.simRenderContext(), FREEVIEW_SHIFT_Y);

    arcBall.setRotationPoint3D(centerX, centerY, centerZ);

    gluLookAt(
      eyeX, eyeY, eyeZ,
      arcBall.rotationPoint()[0], arcBall.rotationPoint()[1], arcBall.rotationPoint()[2],
      upX, upY, upZ);

    glGetDoublev(GL_MODELVIEW_MATRIX, arcBall.lastModelMatrix());

    viewInitialized = true;
  }

  if ( modificationState == MOUSE_MODIFY_ROT )
  {
    if ( mouse.left.down     == true
      && lastMouse.left.down == false)
    {
      // left mouse down event, set initial start point
      arcBall.setNavStartPoint2D(mouse.x, mouse.y);
    }

    // mouse still down, set endpoint and rotate
    arcBall.setNavEndPoint2D(mouse.x, mouse.y);
    arcBall.rotateGL();

    // store result of rotation
    glGetDoublev(GL_MODELVIEW_MATRIX, arcBall.lastModelMatrix());
    // set start to end point for next rotation
    arcBall.setNavStartPoint2D(arcBall.navEndPoint()[0], arcBall.navEndPoint()[1]);
  }
  else if ( modificationState == KEY_MODIFY_ROT )
  {
    // TODO
  }
  else if ( modificationState == MOUSE_MODIFY_ROTPOINT )
  {
    glPushAttrib(GL_DEPTH_BUFFER_BIT | GL_COLOR_BUFFER_BIT);
    {
      glEnable(GL_DEPTH_TEST);
      glEnable(GL_BLEND);
      glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

      const int vpX = mouse.x;
      const int vpY = viewport[3] - mouse.y + viewport[1];

      double mv[16];
      double pv[16];

      glGetDoublev(GL_MODELVIEW_MATRIX,  mv);
      glGetDoublev(GL_PROJECTION_MATRIX, pv);

      double x, y, z = 0.0;
      set::gl::viewport2ModelviewKnownMVZ(vpX, vpY, 0.0, mv, pv, viewport, x, y);

      arcBall.setRotationPoint3D(x, y, z);
    }
    glPopAttrib();

    // render new point
    glMatrixMode(GL_PROJECTION);
    glPushMatrix();
    glLoadIdentity();
    glOrtho(0, viewport[2] - 1, viewport[3] - 1, 0, -1, 1);

    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    {
      glLoadIdentity();
      glTranslatef(static_cast<GLfloat>(mouse.x), static_cast<GLfloat>(mouse.y), 0);
      glLineWidth(3);
      glColor3f(1,1,1);
      glBegin(GL_LINES);
      {
        glVertex2d(-20, 0);
        glVertex2d(+20, 0);

        glVertex2d(0, -20);
        glVertex2d(0, +20);
      }
      glEnd();
    }
    glPopMatrix();

    glMatrixMode(GL_PROJECTION);
    glPopMatrix();

    glMatrixMode(GL_MODELVIEW);
  }

  glTranslated(arcBall.rotationPoint()[0], arcBall.rotationPoint()[1], arcBall.rotationPoint()[2]);
  glScalef(zoomFactor, zoomFactor, zoomFactor);
  glTranslated(-arcBall.rotationPoint()[0], -arcBall.rotationPoint()[1], -arcBall.rotationPoint()[2]);

  // reset wheel state
  mouse.setWheel(0);
  // store last mouse state
  lastMouse = mouse;
}

void CSimPerspectives::RenderCrosshair(ContextData& context)
{
  // link context specific data
  MouseState& mouse     = context.mouse();
  Crosshair&  crosshair = context.freeViewState().crosshair;

  if ( mouse.left.down )
  {
    crosshair.toggleAction();
  }

  crosshair.draw( mouse.x, mouse.y, context.fixedFont() );
}

void CSimPerspectives::SideViewAutosar(ContextData& context)
{
  const GridDimension gridDimension = GridDimension(
    CSimRenderParamHelper::GetLocalParamByRef<float>(*context.simRenderContext(), PN_GRID_DIMENSION_X_MIN),
    CSimRenderParamHelper::GetLocalParamByRef<float>(*context.simRenderContext(), PN_GRID_DIMENSION_X_MAX),
    CSimRenderParamHelper::GetLocalParamByRef<float>(*context.simRenderContext(), PN_GRID_DIMENSION_Y_MIN),
    CSimRenderParamHelper::GetLocalParamByRef<float>(*context.simRenderContext(), PN_GRID_DIMENSION_Y_MAX),
    CSimRenderParamHelper::GetLocalParamByRef<float>(*context.simRenderContext(), PN_GRID_DIMENSION_Z_MIN),
    CSimRenderParamHelper::GetLocalParamByRef<float>(*context.simRenderContext(), PN_GRID_DIMENSION_Z_MAX) );

  const GridStep gridStep = GridStep(
    CSimRenderParamHelper::GetLocalParamByRef<float>(*context.simRenderContext(), PN_GRID_STEP_X),
    CSimRenderParamHelper::GetLocalParamByRef<float>(*context.simRenderContext(), PN_GRID_STEP_Y),
    CSimRenderParamHelper::GetLocalParamByRef<float>(*context.simRenderContext(), PN_GRID_STEP_Z) );

  ContextData::SideViewState & svs = context.sideViewState();
  MouseState const & mouse = context.mouse();
  KeyboardState const & keyb = context.keyboard();

  if( keyb.isDown( '0'))
  {
    svs.bInit = false;
  }

  if( ! svs.bInit)
  {
    svs.xMinCur = gridDimension.xMin - gridStep.xStep;
    svs.xMaxCur = gridDimension.xMax + gridStep.xStep;
    svs.zMinCur = gridDimension.zMin - gridStep.zStep;
    svs.zMaxCur = gridDimension.zMax + gridStep.zStep;
    svs.bInit = true;
    svs.bInSet = false;
  }

  // Initialise for mouse
  float viewport[2][2];
  glGetFloatv( GL_VIEWPORT, viewport[0]);
  double xCor = mouse.x * ( svs.xMaxCur - svs.xMinCur) / viewport[1][0] + svs.xMinCur;
  double zCor = ( viewport[1][1] - mouse.y ) * ( svs.zMaxCur - svs.zMinCur) / viewport[1][1] + svs.zMinCur;

  // mouse pressed
  if( mouse.left.down && ! svs.bInSet)
  {
    svs.xMinMouse = xCor;
    svs.zMinMouse = zCor;
    svs.xMaxMouse = xCor;
    svs.zMaxMouse = zCor;
    svs.xBeginMouse = mouse.x;
    svs.yBeginMouse = mouse.y;
    svs.bInSet = true;
  }
  // mouse moved
  else if( mouse.left.down && svs.bInSet)
  {
    svs.xMaxMouse = xCor;
    svs.zMaxMouse = zCor;
  }
  // mouse released
  else if( ! mouse.left.down && svs.bInSet)
  {
    // check mouse has been moved more than a click
    if( abs( svs.xBeginMouse - mouse.x) > 2 &&
        abs( svs.yBeginMouse - mouse.y) > 2)
    {
      svs.xMinCur = std::min( svs.xMinMouse, svs.xMaxMouse);
      svs.xMaxCur = std::max( svs.xMinMouse, svs.xMaxMouse);
      svs.zMinCur = std::min( svs.zMinMouse, svs.zMaxMouse);
      svs.zMaxCur = std::max( svs.zMinMouse, svs.zMaxMouse);
    }
    svs.bInSet = false;
  }

  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();

  glOrtho( svs.xMinCur, svs.xMaxCur, svs.zMinCur, svs.zMaxCur, -50, 50);

  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();

  // rotate to have z up, x right, y pointing away from camera
  glRotatef(-90, 1, 0, 0);

  if( svs.bInSet)
  {
    glColor3f( 0, 1, 0);
    glBegin( GL_LINE_LOOP);
      glVertex3d( svs.xMinMouse, 0, svs.zMinMouse);
      glVertex3d( svs.xMaxMouse, 0, svs.zMinMouse);
      glVertex3d( svs.xMaxMouse, 0, svs.zMaxMouse);
      glVertex3d( svs.xMinMouse, 0, svs.zMaxMouse);
    glEnd();
  }
}

void CSimPerspectives::BirdViewAutosar(ContextData& context)
{
  static const uint8 KEYSHIFT = 10;
  // link context specific data
  MouseState&                       mouse           = context.mouse();
  const KeyboardState&              keyboard        = context.keyboard();
  MouseState&                       lastMouse       = context.birdViewState().lastMouse;
  bool&                             viewInitialized = context.birdViewState().initialized; // The view is initialized
  ContextData::BirdViewState::Rect& zoomRect        = context.birdViewState().zoomRect; // Used for drawing the zoom box with left mouse button
  float&                            leftBorderVeh   = context.birdViewState().border[0]; // border saves the actual border of the viewport. Given in vehicle coordinate system.
  float&                            rightBorderVeh  = context.birdViewState().border[1];
  float&                            topBorderVeh    = context.birdViewState().border[2];
  float&                            botBorderVeh    = context.birdViewState().border[3];
  bool&                             flipViewPort    = context.birdViewState().flipViewPort; // Rotate the viewport for 90 degree
  int&                              oldVph          = context.birdViewState().viewHeight; // Save the last size of the viewport in pixel to detect a resize
  int&                              oldVpw          = context.birdViewState().viewWidth;

  // The grid dimension are given in [m]
  const GridDimension gridDimension = GridDimension(
    CSimRenderParamHelper::GetLocalParamByRef<float>(*context.simRenderContext(), PN_GRID_DIMENSION_X_MIN),
    CSimRenderParamHelper::GetLocalParamByRef<float>(*context.simRenderContext(), PN_GRID_DIMENSION_X_MAX),
    CSimRenderParamHelper::GetLocalParamByRef<float>(*context.simRenderContext(), PN_GRID_DIMENSION_Y_MIN),
    CSimRenderParamHelper::GetLocalParamByRef<float>(*context.simRenderContext(), PN_GRID_DIMENSION_Y_MAX),
    CSimRenderParamHelper::GetLocalParamByRef<float>(*context.simRenderContext(), PN_GRID_DIMENSION_Z_MIN),
    CSimRenderParamHelper::GetLocalParamByRef<float>(*context.simRenderContext(), PN_GRID_DIMENSION_Z_MAX));
  const bool birdViewFixedXYRatio = (CSimRenderParamHelper::GetLocalParamByRef<uint8>(*(context.simRenderContext()), PN_BIRDVIEW_FIXED_X_Y_RATIO) > 0);

  int   shiftXPx   = 0;
  int   shiftYPx   = 0;

  // check which kind of modification will be done
  enum ModificationState
  {
    MODIFY_NOTHING = 0,
    MOUSE_MODIFY_PAN,
    MOUSE_MODIFY_ZOOM_WHEEL,
    MOUSE_ZOOM_BOX_START,
    MOUSE_ZOOM_BOX_END,
    MOUSE_ZOOM_PRESSED,
    KEY_MODIFY_PAN,
    KEY_MODIFY_ZOOM
  };

  ModificationState modificationState = MODIFY_NOTHING;

  if (mouse.left.down)
  {
    if (mouse.control)
    {
      modificationState = MOUSE_MODIFY_PAN;
    }
    else if (!lastMouse.left.down)
    {
      modificationState = MOUSE_ZOOM_BOX_START;
    }
    else if (lastMouse.left.down)
    {
      modificationState = MOUSE_ZOOM_PRESSED;
    }
  }
  else if (mouse.middle.down)
  {
    modificationState = MOUSE_MODIFY_PAN;
  }
  else if (!mouse.left.down && lastMouse.left.down && !mouse.control)
  {
    modificationState = MOUSE_ZOOM_BOX_END;
  }
  else if (mouse.scroll != 0)
  {
    modificationState = MOUSE_MODIFY_ZOOM_WHEEL;
  }
  else if (keyboard.someDown())
  {
    if (keyboard.isDown(VK_NUMPAD0)
        || keyboard.isDown(VK_NUMPAD1)
        || keyboard.isDown(VK_NUMPAD2)
        || keyboard.isDown(VK_NUMPAD3)
        || keyboard.isDown(VK_NUMPAD4)
        || keyboard.isDown(VK_NUMPAD2)
        || keyboard.isDown(VK_NUMPAD6)
        || keyboard.isDown(VK_NUMPAD7)
        || keyboard.isDown(VK_NUMPAD8)
        || keyboard.isDown(VK_NUMPAD9))
    {
      modificationState = KEY_MODIFY_PAN;
    }
    else
    {
      if ( keyboard.isDown(VK_ADD)
           || keyboard.isDown(VK_SUBTRACT)
           || keyboard.isDown(VK_OEM_PLUS)
           || keyboard.isDown(VK_OEM_MINUS))
      {
        modificationState = KEY_MODIFY_ZOOM;
      }
    }
  }

  // Set zoom factor
  float relZoomFactor = 1.f;
  if ( modificationState == MOUSE_MODIFY_ZOOM_WHEEL)
  {
    const float scrollDirection = (mouse.scroll > 0) ? 1.f : -1.f;
    relZoomFactor = std::pow(1.2f, scrollDirection);
  }
  else if (modificationState == KEY_MODIFY_ZOOM)
  {
    if ( keyboard.isDown(VK_ADD)
         || keyboard.isDown(VK_OEM_PLUS))
    {
      relZoomFactor = std::pow(1.1f, 1.f);
    }
    else if ( keyboard.isDown(VK_SUBTRACT)
              || keyboard.isDown(VK_OEM_MINUS))
    {
      relZoomFactor = std::pow(1.1f, -1.f);
    }
  }

  // Set panning/shift value
  if ( modificationState == MOUSE_MODIFY_PAN )
  {
    shiftXPx = mouse.x     - lastMouse.x;
    shiftYPx = lastMouse.y - mouse.y;
  }
  else if ( modificationState == KEY_MODIFY_PAN )
  {
    if (keyboard.isDown(VK_NUMPAD4) || keyboard.isDown(VK_NUMPAD1) || keyboard.isDown(VK_NUMPAD7) || keyboard.isDown(VK_LEFT))
    {
      shiftXPx = KEYSHIFT;
    }
    if (keyboard.isDown(VK_NUMPAD6) || keyboard.isDown(VK_NUMPAD3) || keyboard.isDown(VK_NUMPAD9) || keyboard.isDown(VK_RIGHT))
    {
      shiftXPx = -KEYSHIFT;
    }
    if (keyboard.isDown(VK_NUMPAD8) || keyboard.isDown(VK_NUMPAD7) || keyboard.isDown(VK_NUMPAD9) || keyboard.isDown(VK_UP))
    {
      shiftYPx = -KEYSHIFT;
    }
    if (keyboard.isDown(VK_NUMPAD2) || keyboard.isDown(VK_NUMPAD1) || keyboard.isDown(VK_NUMPAD3) || keyboard.isDown(VK_DOWN))
    {
      shiftYPx = KEYSHIFT;
    }
  }

  // fetch current viewport
  GLint viewport[4]; // [x, y, width, height]
  glGetIntegerv(GL_VIEWPORT, viewport);
  const int& vpw = viewport[2];
  const int& vph = viewport[3];

  // Get the ratio of grid and viewport to detect if we need to flip the view
  const float32 gridXY_Ratio = static_cast<float32>((gridDimension.xMax - gridDimension.xMin))/(gridDimension.yMax - gridDimension.yMin);
  const float32 viewportWidthHeight_Ratio = static_cast<float32>(viewport[2])/viewport[3];

  // check for reset pressed (the "0" key) or the viewport if flipped or the viewport in fixedXYRatio mode is resized
  if (keyboard.isOnlyDown('0') 
    || (flipViewPort != (viewportWidthHeight_Ratio > gridXY_Ratio))
    || (((oldVph != vph) || (oldVpw != vpw)) && birdViewFixedXYRatio))
  {
    // reset
    shiftXPx        = 0;
    shiftYPx        = 0;
    viewInitialized = false;
  }
  oldVpw = vpw;
  oldVph = vph;

  flipViewPort = viewportWidthHeight_Ratio >  gridXY_Ratio;

  // Initialize border
  if (!viewInitialized)
  {
    const GridStep gridStep = GridStep(
        CSimRenderParamHelper::GetLocalParamByRef<float>(*context.simRenderContext(), PN_GRID_STEP_X),
        CSimRenderParamHelper::GetLocalParamByRef<float>(*context.simRenderContext(), PN_GRID_STEP_Y),
        CSimRenderParamHelper::GetLocalParamByRef<float>(*context.simRenderContext(), PN_GRID_STEP_Z));
    if (flipViewPort)
    {
      // get the largest text on the y axis
      float       largeYAxisNumber     = std::max(abs(gridDimension.yMax), abs(gridDimension.yMin));
      std::string yAxisStr             = static_cast<std::ostringstream*>(&(std::ostringstream() << "-" << largeYAxisNumber << " m"))->str();
      const float fontWidthPix         = static_cast<float>(context.variableFont().GetTextWidth(yAxisStr.c_str()));
      const float fontHeightPix        = static_cast<float>(context.variableFont().GetCharHeight('Y'));
      float       gridHeight           = (gridDimension.yMax + 0.5f * gridStep.yStep) - (gridDimension.yMin - 0.5f * gridStep.yStep);
      float       gridWidth            = (gridDimension.xMax + 0.5f * gridStep.xStep) - (gridDimension.xMin - 0.5f * gridStep.xStep);
      float       gridViewPortRatioHor = gridWidth / vpw;
      float       gridViewPortRatioVer = gridHeight / vph;
      // Approximate the font size in vehicle coordinate system and update the ratio variables
      const float fontWidthVeh  = fontWidthPix * gridViewPortRatioHor;
      const float fontHeightVeh = fontHeightPix * gridViewPortRatioVer;
      if (birdViewFixedXYRatio)
      {
        gridWidth += 2 * fontWidthVeh;
        gridHeight += 2 * fontHeightVeh;
        gridViewPortRatioHor    = gridWidth / vpw;
        gridViewPortRatioVer    = gridHeight / vph;
        const float widthFactor = gridViewPortRatioVer / gridViewPortRatioHor;
        leftBorderVeh           = (gridDimension.xMin - 0.5f * gridStep.xStep - fontWidthVeh) * widthFactor;
        rightBorderVeh          = (gridDimension.xMax + 0.5f * gridStep.xStep + fontWidthVeh) * widthFactor;
        const float horOffset   = 0.f;
        leftBorderVeh -= horOffset;
        rightBorderVeh -= horOffset;
        botBorderVeh = gridDimension.yMin - 0.5f * gridStep.xStep - fontHeightVeh;
        topBorderVeh = gridDimension.yMax + 0.5f * gridStep.xStep + fontHeightVeh;
      }
      else
      {
        leftBorderVeh  = gridDimension.xMin - 0.5f * gridStep.xStep - fontWidthVeh;
        rightBorderVeh = gridDimension.xMax + 0.5f * gridStep.xStep + fontWidthVeh;
        botBorderVeh   = gridDimension.yMin - 0.5f * gridStep.yStep - fontHeightVeh;
        topBorderVeh   = gridDimension.yMax + 0.5f * gridStep.yStep + fontHeightVeh;
      }
    }
    else
    {
      // get the largest text on the x axis
      float             largeXAxisNumber     = std::max(abs(gridDimension.xMax), abs(gridDimension.xMin));
      const std::string xAxisStr             = static_cast<std::ostringstream*>(&(std::ostringstream() << "-" << largeXAxisNumber << " m"))->str();
      const float       fontWidthPix         = static_cast<float>(context.variableFont().GetTextWidth(xAxisStr.c_str()));
      const float       fontHeightPix        = static_cast<float>(context.variableFont().GetCharHeight('X'));
      float             gridHeight           = (gridDimension.xMax + 0.5f * gridStep.xStep) - (gridDimension.xMin - 0.5f * gridStep.xStep);
      float             gridWidth            = (gridDimension.yMax + 0.5f * gridStep.yStep) - (gridDimension.yMin - 0.5f * gridStep.yStep);
      float             gridViewPortRatioHor = gridWidth / vpw;
      float             gridViewPortRatioVer = gridHeight / vph;
      // Approximate the font size in vehicle coordinate system and update the ratio variables
      const float fontWidthVeh  = fontWidthPix * gridViewPortRatioHor;
      const float fontHeightVeh = fontHeightPix * gridViewPortRatioVer;
      if (birdViewFixedXYRatio)
      {
        gridWidth += 2 * fontWidthVeh;
        gridHeight += 2 * fontHeightVeh;
        gridViewPortRatioHor    = gridWidth / vpw;
        gridViewPortRatioVer    = gridHeight / vph;
        // We always prefer the to scale the width
        const float widthFactor = gridViewPortRatioVer / gridViewPortRatioHor;
        leftBorderVeh           = -(gridDimension.yMax + 0.5f * gridStep.yStep + fontWidthVeh) * widthFactor;
        rightBorderVeh          = -(gridDimension.yMin - 0.5f * gridStep.xStep - fontWidthVeh) * widthFactor;
        // At the mome
        const float horOffset   = 0.f;
        leftBorderVeh -= horOffset;
        rightBorderVeh -= horOffset;
        botBorderVeh = gridDimension.xMin - 0.5f * gridStep.xStep - fontHeightVeh;
        topBorderVeh = gridDimension.xMax + 0.5f * gridStep.xStep + fontHeightVeh;
      }
      else
      {
        leftBorderVeh  = gridDimension.yMin - 0.5f * gridStep.yStep - fontWidthVeh;
        rightBorderVeh = gridDimension.yMax + 0.5f * gridStep.yStep + fontWidthVeh;
        botBorderVeh   = gridDimension.xMin - 0.5f * gridStep.xStep - fontHeightVeh;
        topBorderVeh   = gridDimension.xMax + 0.5f * gridStep.xStep + fontHeightVeh;
      }
    }
    viewInitialized = true;
  }
  float xMeterPerPixel = (rightBorderVeh - leftBorderVeh) / vpw;
  float yMeterPerPixel = (topBorderVeh - botBorderVeh) / vph;

  // get mouse coordinates in vehicle coordinate system
  float mouseVehX = 0.f;
  float mouseVehY = 0.f;
  if (flipViewPort)
  {
    mouseVehX = static_cast<float>(mouse.x) / vpw * (rightBorderVeh - leftBorderVeh) + leftBorderVeh;
    mouseVehY = static_cast<float>(mouse.y) / vph * (topBorderVeh - botBorderVeh) - topBorderVeh;
  }
  else
  {
    mouseVehX = static_cast<float>(vph - mouse.y) / vph * (topBorderVeh - botBorderVeh) + botBorderVeh;
    mouseVehY = static_cast<float>(mouse.x) / vpw * (rightBorderVeh - leftBorderVeh) + leftBorderVeh;
  }

  switch(modificationState)
  {
    // Mouse Zoom Box
    case MOUSE_ZOOM_BOX_START:
    {
      zoomRect.x1 = mouseVehX;
      zoomRect.y1 = mouseVehY;
      break;
    }
    case MOUSE_ZOOM_PRESSED:
    {
      ContextData::BirdViewState::Rect drawRect;
      drawRect.x1 = zoomRect.x1;
      drawRect.y1 = zoomRect.y1;
      drawRect.x2 = mouseVehX;
      drawRect.y2 = mouseVehY;
      if (birdViewFixedXYRatio)
      {
        zoomRect.x2 = mouseVehX;
        zoomRect.y2 = mouseVehY;

        // Calc new ratio between viewport and real distance
        float yMeterPerPixelLocal = abs(drawRect.y2 - drawRect.y1) / vpw;
        float xMeterPerPixelLocal = abs(drawRect.x2 - drawRect.x1) / vph;
        if (flipViewPort)
        {
          yMeterPerPixelLocal = abs(drawRect.y2 - drawRect.y1) / vph;
          xMeterPerPixelLocal = abs(drawRect.x2 - drawRect.x1) / vpw;
        }
        if (xMeterPerPixelLocal > yMeterPerPixelLocal)
        {
          // Zoom the x axis
          float midy  = zoomRect.y2 - (zoomRect.y2 - zoomRect.y1) / 2.f;
          drawRect.y1 = midy - (zoomRect.y2 - zoomRect.y1) / 2.f * (xMeterPerPixelLocal / yMeterPerPixelLocal);
          drawRect.y2 = midy + (zoomRect.y2 - zoomRect.y1) / 2.f * (xMeterPerPixelLocal / yMeterPerPixelLocal);
        }
        else
        {
          // Zoom the y axis
          float midx  = zoomRect.x2 - (zoomRect.x2 - zoomRect.x1) / 2.f;
          drawRect.x1 = midx + (zoomRect.x2 - zoomRect.x1) / 2.f * (yMeterPerPixelLocal / xMeterPerPixelLocal);
          drawRect.x2 = midx - (zoomRect.x2 - zoomRect.x1) / 2.f * (yMeterPerPixelLocal / xMeterPerPixelLocal);
        }
      }
      // Render zoom rect
      glColor3f(0, 1, 0);
      glLineWidth(1.5f);
      glBegin(GL_LINE_LOOP);
      {
        glVertex3f(drawRect.x1, -drawRect.y1, 20.f);
        glVertex3f(drawRect.x2, -drawRect.y1, 20.f);
        glVertex3f(drawRect.x2, -drawRect.y2, 20.f);
        glVertex3f(drawRect.x1, -drawRect.y2, 20.f);
      }
      glEnd();
      if (birdViewFixedXYRatio)
      {
        glColor3f(1, 0, 0);
        glLineWidth(1.5f);
        glBegin(GL_LINE_LOOP);
        {
          glVertex3f(zoomRect.x1, -zoomRect.y1, 20.f);
          glVertex3f(zoomRect.x2, -zoomRect.y1, 20.f);
          glVertex3f(zoomRect.x2, -zoomRect.y2, 20.f);
          glVertex3f(zoomRect.x1, -zoomRect.y2, 20.f);
        }
        glEnd();
      }
      break;
    }
    case MOUSE_ZOOM_BOX_END:
    {
      zoomRect.x2 = mouseVehX;
      zoomRect.y2 = mouseVehY;
      if ((fabs(zoomRect.x1 - zoomRect.x2) > 0.1) && (fabs(zoomRect.y1 - zoomRect.y2) > 0.1))
      {
        // Swap x or y if user starts from bottom or right
        if (zoomRect.y2 < zoomRect.y1)
        {
          std::swap(zoomRect.y1, zoomRect.y2);
        }
        if (zoomRect.x2 < zoomRect.x1)
        {
          std::swap(zoomRect.x1, zoomRect.x2);
        }

        // Set new ratio between viewport and real distance
        if (birdViewFixedXYRatio)
        {
          if (flipViewPort)
          {
            yMeterPerPixel = static_cast<float>(zoomRect.y2 - zoomRect.y1) / vph;
            xMeterPerPixel = static_cast<float>(zoomRect.x2 - zoomRect.x1) / vpw;
          }
          else
          {
            yMeterPerPixel = static_cast<float>(zoomRect.y2 - zoomRect.y1) / vpw;
            xMeterPerPixel = static_cast<float>(zoomRect.x2 - zoomRect.x1) / vph;
          }
          if (xMeterPerPixel > yMeterPerPixel)
          {
            // Zoom the x axis
            const float midy = zoomRect.y2 - (zoomRect.y2 - zoomRect.y1) / 2.f;
            if (flipViewPort)
            {
              topBorderVeh   = -(midy - (zoomRect.y2 - zoomRect.y1) / 2.f * (xMeterPerPixel / yMeterPerPixel));
              botBorderVeh   = -(midy + (zoomRect.y2 - zoomRect.y1) / 2.f * (xMeterPerPixel / yMeterPerPixel));
              rightBorderVeh = zoomRect.x2;
              leftBorderVeh  = zoomRect.x1;
            }
            else
            {
              leftBorderVeh  = midy - (zoomRect.y2 - zoomRect.y1) / 2.f * (xMeterPerPixel / yMeterPerPixel);
              rightBorderVeh = midy + (zoomRect.y2 - zoomRect.y1) / 2.f * (xMeterPerPixel / yMeterPerPixel);
              topBorderVeh   = zoomRect.x2;
              botBorderVeh   = zoomRect.x1;
            }
          }
          else
          {
            // Zoom the y axis
            const float midx = zoomRect.x2 - (zoomRect.x2 - zoomRect.x1) / 2.f;
            if (flipViewPort)
            {
              topBorderVeh   = -zoomRect.y1;
              botBorderVeh   = -zoomRect.y2;
              rightBorderVeh = midx + (zoomRect.x2 - zoomRect.x1) / 2.f * (yMeterPerPixel / xMeterPerPixel);
              leftBorderVeh  = midx - (zoomRect.x2 - zoomRect.x1) / 2.f * (yMeterPerPixel / xMeterPerPixel);
            }
            else
            {
              // Zoom the y axis
              leftBorderVeh  = zoomRect.y1;
              rightBorderVeh = zoomRect.y2;
              topBorderVeh   = midx + (zoomRect.x2 - zoomRect.x1) / 2.f * (yMeterPerPixel / xMeterPerPixel);
              botBorderVeh   = midx - (zoomRect.x2 - zoomRect.x1) / 2.f * (yMeterPerPixel / xMeterPerPixel);
            }
          }
        }
        else
        {
          // Update zoom factor (used for pan)
          leftBorderVeh  = zoomRect.y1;
          rightBorderVeh = zoomRect.y2;
          topBorderVeh   = zoomRect.x2;
          botBorderVeh   = zoomRect.x1;
        }
      }
      break;
    }
    case MOUSE_MODIFY_ZOOM_WHEEL:
    case KEY_MODIFY_ZOOM:
    {
      float zoomShiftX = 0.f;
      float zoomShiftY = 0.f;
      // Zoom with keys or mouse wheel
      if (modificationState == MOUSE_MODIFY_ZOOM_WHEEL)
      {
        // Zoom poi is the mouse pointer
        if (flipViewPort)
        {
          zoomShiftY = mouseVehX;
          zoomShiftX = -mouseVehY;
        }
        else
        {
          zoomShiftX = mouseVehX;
          zoomShiftY = mouseVehY;
        }
      }
      if (modificationState == KEY_MODIFY_ZOOM)
      {
        // Zoom poi is the middle of the screen
        zoomShiftX = topBorderVeh - (topBorderVeh - botBorderVeh) / 2.f;
        zoomShiftY = rightBorderVeh - (rightBorderVeh - leftBorderVeh) / 2.f;
      }
      // Translate to zoom poi, zoom, translate back
      leftBorderVeh  -= zoomShiftY;
      rightBorderVeh -= zoomShiftY;
      botBorderVeh   -= zoomShiftX;
      topBorderVeh   -= zoomShiftX;

      leftBorderVeh  /= relZoomFactor;
      rightBorderVeh /= relZoomFactor;
      topBorderVeh   /= relZoomFactor;
      botBorderVeh   /= relZoomFactor;

      leftBorderVeh  += zoomShiftY;
      rightBorderVeh += zoomShiftY;
      botBorderVeh   += zoomShiftX;
      topBorderVeh   += zoomShiftX;

      break;
    }
    case MOUSE_MODIFY_PAN:
    case KEY_MODIFY_PAN:
    {
      // Apply pan/shift
      leftBorderVeh  -= shiftXPx * xMeterPerPixel;
      rightBorderVeh -= shiftXPx * xMeterPerPixel;
      topBorderVeh   -= shiftYPx * yMeterPerPixel;
      botBorderVeh   -= shiftYPx * yMeterPerPixel;
      break;
    }
    default:
    {
      break;
    }
  }

  // DRAW
  // setup projection
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();

  glOrtho(leftBorderVeh,  // left
          rightBorderVeh, // right
          botBorderVeh,   // bot
          topBorderVeh,   // top
          -50.0,
          50.0);
  if (!flipViewPort)
  {
    glRotatef(90.f, 0.f, 0.f, 1.f);
  }

  // setup modelview
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();

  // reset wheel state
  mouse.setWheel(0);
  // store last mouse state
  lastMouse = mouse;
}

static std::string StepFormat( float fStepSize)
{
  static char cFormat[16];
  int iLog = static_cast<int>( floor( log10( (float) fStepSize)));
  if( iLog >=0)
  {
    strcpy( cFormat, "%.0f m");
    return cFormat;
  }
  _snprintf( cFormat, sizeof( cFormat), "%%.%df m", - iLog);
  return cFormat;
}

void CSimPerspectives::RenderXYGrid(const float& minX, const float& maxX, const float& stepX,
                                    const float& minY, const float& maxY, const float& stepY, 
                                    const float lineWidth,
                                    const RGBAColor& color, const RGBAColor& xColor, const RGBAColor& yColor,
                                    const char* const xName, const char* const yName,
                                    ContextData& context)
{
  glLineWidth(lineWidth);
  glColor4f(color.r, color.g, color.b, color.a);

  const float x1 = minX - 0.5f * stepX;
  const float x2 = maxX + 0.5f * stepX;
  const float y1 = minY - 0.5f * stepY;
  const float y2 = maxY + 0.5f * stepY;

  const size_t xSteps = static_cast<size_t>(std::abs(maxX - minX) / stepX + 0.5f) + 1;
  const size_t ySteps = static_cast<size_t>(std::abs(maxY - minY) / stepY + 0.5f) + 1;

  // the lines
  glBegin(GL_LINES);
  {
    for (size_t i = 0; i < xSteps; ++i)
    {
      const float x = minX + i * stepX;
      glVertex2f (x, y1);
      glVertex2f (x, y2);
    }

    for (size_t i = 0; i < ySteps; ++i)
    {
      const float y = minY + i * stepY;
      glVertex2d (x1, y);
      glVertex2d (x2, y);
    }
  }
  glEnd();

  // axis colors
  glLineWidth(1);

  glBegin(GL_LINES);
  {
    glColor4f(xColor.r, xColor.g, xColor.b, xColor.a);
    glVertex2f(    0, 0);
    glVertex2f(stepX, 0);

    glColor4f(yColor.r, yColor.g, yColor.b, yColor.a);
    glVertex2f(0,     0);
    glVertex2f(0, stepY);
  }
  glEnd();

  // get current view mode
  ViewMode vm = context.getViewMode();

  if(vm == VM_BIRD)
  {
    GLdouble m[16];
    GLdouble p[16];

    glGetDoublev(GL_MODELVIEW_MATRIX,  m);
    glGetDoublev(GL_PROJECTION_MATRIX, p);

    double x;
    double y;
    double z;

    double xLeft;
    double yBottom;

    GLint viewport[4];
    glGetIntegerv(GL_VIEWPORT, viewport);

    gluUnProject(0, context.variableFont().GetCharHeight('Y'), 0, m, p, viewport, &xLeft, &y, &z);
    gluUnProject(0, context.variableFont().GetCharHeight('X'), 0, m, p, viewport, &x, &yBottom, &z);

    context.variableFont().BeginRender2D();

    // the length annotations
    context.variableFont().SetTextColor(1, 1, 1, 1);
    std::string cFormatX = StepFormat( stepX);
    for (size_t i = 0; i < xSteps; i += 2)
    {
      const float x = minX + i * stepX;
      context.variableFont().RenderTextf(x, yBottom, 0, cFormatX.c_str(), x);
    }

    std::string cFormatY = StepFormat( stepY);
    for (size_t i = 0; i < ySteps; i += 2)
    {
      const float y = minY + i * stepY;
      context.variableFont().RenderTextf(xLeft, y, 0, cFormatY.c_str(), y);
    }
  }
  else
  {
    context.variableFont().BeginRender2D();

    // the length annotations
    context.variableFont().SetTextColor(1, 1, 1, 1);
    std::string cFormatX = StepFormat( stepX);
    for (size_t i = 0; i < xSteps; i += 2)
    {
      const float x = minX + i * stepX;
      context.variableFont().RenderTextf(x, y1, 0, cFormatX.c_str(), x);
    }

    std::string cFormatY = StepFormat( stepY);
    for (size_t i = 0; i < ySteps; i += 2)
    {
      const float y = minY + i * stepY;
      context.variableFont().RenderTextf(x1, y, 0, cFormatY.c_str(), y);
    }

  }

  // axis annotations
  context.variableFont().SetTextColor(xColor.r, xColor.g, xColor.b, xColor.a);
  context.variableFont().RenderText(xName, stepX, 0, 0);

  context.variableFont().SetTextColor(yColor.r, yColor.g, yColor.b, yColor.a);
  context.variableFont().RenderText(yName, 0, stepY, 0);

  context.variableFont().EndRender2D();
}

void CSimPerspectives::SimDrawPortAdapter( void* plgId, long param1, void (CSimPerspectives::*renderFunc)(ContextData&) )
{
  // adapter for sim draw

  CSimPerspectives* pThis = reinterpret_cast<CSimPerspectives*>(plgId);
  // lock std::map data
  ScopeLock lock(pThis->m_csContextData);
  // Cast input param1 to ISimRenderContext
  ISimRenderContext* renderContext = reinterpret_cast<ISimRenderContext*>(LongToPtr(param1));
  assert(renderContext != NULL);
  // select context
  ContextData& context = pThis->m_contextData[renderContext];
  // store isimrendercontext pointer
  context.setSimRenderContext(renderContext);
  // call the render function
  (pThis->*renderFunc)(context);
}

void CSimPerspectives::SimDynViewDrawPortAdapter( void* plgId, long param1, const ViewMode vm )
{
  // adapter for sim draw

  CSimPerspectives* pThis = reinterpret_cast<CSimPerspectives*>(plgId);
  // lock std::map data
  ScopeLock lock(pThis->m_csContextData);
  // Cast input param1 to ISimRenderContext
  ISimRenderContext* renderContext = reinterpret_cast<ISimRenderContext*>(LongToPtr(param1));
  assert(renderContext != NULL);
  // select context
  ContextData& context = pThis->m_contextData[renderContext];
  // store isimrendercontext pointer
  context.setSimRenderContext(renderContext);
  // call the render function
  pThis->DynamicViewAutosar(context, vm);
}

bool CSimPerspectives::OnMouseMessage (const ISimRenderContext& context, const ISimWindowMessage& windowMessage)
{
  bool returnValue = false;

  ScopeLock lock(m_csContextData);
  // fill mouse for context
  MouseState& mouse = m_contextData[context].mouse();
  ContextData::ZoomState & zoomViewState = m_contextData[context].zoomViewState();

  switch (windowMessage.GetMessageId())
  {
  case WM_LBUTTONDOWN:
  case WM_LBUTTONUP:
  case WM_LBUTTONDBLCLK:
  case WM_RBUTTONDOWN:
  case WM_RBUTTONUP:
  case WM_RBUTTONDBLCLK:
  case WM_MBUTTONDOWN:
  case WM_MBUTTONUP:
  case WM_MBUTTONDBLCLK:
  case WM_MOUSEMOVE:
    {
      mouse.setPos    (LOWORD(windowMessage.GetLParam()), HIWORD(windowMessage.GetLParam()));
      mouse.setShift  ((LOWORD(windowMessage.GetWParam()) & MK_SHIFT)   != 0);
      mouse.setControl((LOWORD(windowMessage.GetWParam()) & MK_CONTROL) != 0);
      mouse.setWheel  ( 0);
      mouse.right.down = GetAsyncKeyState(VK_RBUTTON) != 0;  // WM_RBUTTONUP message never appears

      switch (windowMessage.GetMessageId())
      {
      case WM_LBUTTONDOWN:
        mouse.left.setDown();
        break;
      case WM_LBUTTONUP:
        mouse.left.setClicked();
        break;
      case WM_LBUTTONDBLCLK:
        mouse.left.setDblClicked();
        break;
      case WM_RBUTTONDOWN:
        mouse.right.setDown();
        break;
      case WM_RBUTTONUP:
        mouse.right.setClicked();
        break;
      case WM_RBUTTONDBLCLK:
        mouse.right.setDblClicked();
        break;
      case WM_MBUTTONDOWN:
        mouse.middle.setDown();
        break;
      case WM_MBUTTONUP:
        mouse.middle.setClicked();
        break;
      case WM_MBUTTONDBLCLK:
        mouse.middle.setDblClicked();
        break;
      }

      if (windowMessage.GetMessageId() == WM_MOUSEMOVE)
      {
        // render as soon as the mouse moves
        returnValue = true;
      }
      else
      {
        returnValue = true;
      }

      returnValue |= zoomViewState.SetMouse( mouse.x, mouse.y, 0, mouse.left.down, m_contextData[context].keyboard().isDown( VK_CONTROL));
      break;
    }
  case WM_MOUSEWHEEL:
    {
      POINT p;
      p.x = LOWORD(windowMessage.GetLParam());
      p.y = HIWORD(windowMessage.GetLParam());
      ScreenToClient( context.GetWindow().GetWindowHandle(), & p);
      mouse.setPos    ( p.x, p.y);
      mouse.setShift  ((LOWORD(windowMessage.GetWParam()) & MK_SHIFT)   != 0);
      mouse.setControl((LOWORD(windowMessage.GetWParam()) & MK_CONTROL) != 0);
      mouse.setWheel(GET_WHEEL_DELTA_WPARAM(windowMessage.GetWParam()));
      zoomViewState.SetMouse( mouse.x, mouse.y, mouse.scroll / WHEEL_DELTA, mouse.left.down, m_contextData[context].keyboard().isDown( VK_CONTROL));
      returnValue = true;
    }
  }

  return returnValue;
}

bool CSimPerspectives::OnKeyboardMessage( const ISimRenderContext& context, const ISimWindowMessage& windowMessage )
{
  switch (windowMessage.GetMessageId())
  {
  case WM_KEYDOWN:
  case WM_KEYUP:
    {
      ScopeLock lock(m_csContextData);
      // fill keyboard for context
      KeyboardState& keyboard = m_contextData[context].keyboard();

      switch (windowMessage.GetMessageId())
      {
      case WM_KEYDOWN:
        keyboard.setDown(windowMessage.GetWParam());
        m_contextData[context].zoomViewState().SetKeybord( keyboard.isDown( VK_LEFT), keyboard.isDown( VK_RIGHT), keyboard.isDown( VK_UP), keyboard.isDown( VK_DOWN), keyboard.isDown( VK_CONTROL));
        return true;
      case WM_KEYUP:
        keyboard.setUp(windowMessage.GetWParam());
        return true;
      }
    }
    return false;
  case WM_CHAR:
    switch( windowMessage.GetWParam())
    {
    case '0':
      m_contextData[context].zoomViewState().Reset();
      return true;
    }
  default:
    return false;
  }
}

void CSimPerspectives::adjustImageWidthAndHeight( ISimRenderContext & simRenderContert)
{
#ifdef IMAGE16_INTFVER
  if(m_RTEImage.isDirty() && m_RTEImage.val() != NULL)
  {
    m_uImgWidth  = m_RTEImage.val()->sImgHeader.uiWidth;
    m_uImgHeight = m_RTEImage.val()->sImgHeader.uiHeight;
  }
  else
#endif
  if(m_CTKImage.isDirty() && m_CTKImage.val() != NULL)
  {
    m_uImgWidth  = m_CTKImage.val()->bmWidth;
    m_uImgHeight = m_CTKImage.val()->bmHeight;
  }
  else
  {
    // use parameter file as default
    m_uImgWidth  = m_imageWidth.val();
    m_uImgHeight = m_imageHeight.val();
  }

  // local simvis file overwrites values if non-default
  uint32 uImgWidth  = CSimRenderParamHelper::GetLocalParamByRef<uint32>( simRenderContert, IMAGE_WIDTH, DEFAULT_IMG_WIDTH);
  uint32 uImgHeight = CSimRenderParamHelper::GetLocalParamByRef<uint32>( simRenderContert, IMAGE_HEIGHT, DEFAULT_IMG_HEIGHT);
  if (uImgWidth != DEFAULT_IMG_WIDTH || uImgHeight != DEFAULT_IMG_HEIGHT)
  {
    m_uImgWidth = uImgWidth;
    m_uImgHeight = uImgHeight;
  }
}

void CSimPerspectives::MenuHandler( ISimRenderContext& ctx, const MenuAction action )
{
  unsigned char vm = static_cast<unsigned char>(VM_DEFAULT);
  switch (action)
  {
  case MA_VIEWMODE_DEFAULT:
    vm = static_cast<unsigned char>(VM_DEFAULT);
    break;
  case MA_VIEWMODE_FREE:
    vm = static_cast<unsigned char>(VM_FREE);
    break;
  case MA_VIEWMODE_BIRD:
    vm = static_cast<unsigned char>(VM_BIRD);
    break;
  case MA_VIEWMODE_SIDE:
    vm = static_cast<unsigned char>(VM_SIDE);
    break;
  case MA_VIEWMODE_CAM:
    vm = static_cast<unsigned char>(VM_CAM);
    break;
  case MA_VIEWMODE_CAM_DYNAMIC:
    vm = static_cast<unsigned char>(VM_CAM_DYNAMIC);
    break;
  default:
    assert (0);
  }

  CSimRenderParamHelper::SetLocalParamByRef(ctx, PN_VIEW_MODE, vm);
}

void CSimPerspectives::DynamicViewAutosar( ContextData& context, const ViewMode defaultMode)
{
  // check for key-based perspective switch
  if (context.keyboard().someDown())
  {
    if (context.keyboard().isOnlyDown('1'))
    {
      MenuHandler(*context.simRenderContext(), MA_VIEWMODE_FREE);
    }
    else if (context.keyboard().isOnlyDown('2'))
    {
      MenuHandler(*context.simRenderContext(), MA_VIEWMODE_BIRD);
    }
    else if (context.keyboard().isOnlyDown('3'))
    {
      MenuHandler(*context.simRenderContext(), MA_VIEWMODE_SIDE);
    }
    else if (context.keyboard().isOnlyDown('4'))
    {
      MenuHandler(*context.simRenderContext(), MA_VIEWMODE_CAM);
    }
    else if (context.keyboard().isOnlyDown('5'))
    {
      MenuHandler(*context.simRenderContext(), MA_VIEWMODE_CAM_DYNAMIC);
    }
  }

  // get current view mode
  ViewMode vm = static_cast<ViewMode>(CSimRenderParamHelper::GetLocalParamByRef<unsigned char>(*context.simRenderContext(), PN_VIEW_MODE));

  if (vm == VM_DEFAULT)
  {
    vm = defaultMode;
  }

  context.setViewMode(vm);

  switch (vm)
  {
  default:
  case VM_FREE:
    FreeViewAutosar(context);
    break;
  case VM_BIRD:
    BirdViewAutosar(context);
    break;
  case VM_SIDE:
    SideViewAutosar(context);
    break;
#ifdef MONO_CALIBRATION_INTFVER
  case VM_CAM:
    CameraViewAutosar(context);
    break;
  case VM_CAM_DYNAMIC:
    CameraViewDynamicAutosar(context);
    break;
#endif
  }
}

CVersionInfoImpl CSimPerspectives::CreateVersionInfoFromI32( const long version )
{
  return CVersionInfoImpl (
    static_cast<unsigned char>((version >> 16) & 0xFF),
    static_cast<unsigned char>((version >> 8)  & 0xFF),
    static_cast<unsigned char>( version        & 0xFF));
}

//////////////////////// Context Data /////////////////////////////////////////

CSimPerspectives::ContextData::ContextData()
: m_simRenderContext(0)
, m_lastRenderTime(-1)
, m_smoothedDT(-1)
, m_viewMode(VM_DEFAULT)
{
}

IGDVFont& CSimPerspectives::ContextData::fixedFont()
{
  assert(m_simRenderContext != NULL);
  return m_simRenderContext->GetWindow().GetFontInterface("Courier New", 8);
}

IGDVFont& CSimPerspectives::ContextData::variableFont()
{
  assert(m_simRenderContext != NULL);
  return m_simRenderContext->GetWindow().GetFontInterface("Arial", 8);
}

void CSimPerspectives::DrawHorizon( ContextData& /*context*/ )
{
  glPushMatrix();
  {
    glLineWidth(1.2F);
    glColor3ub(245U, 222U, 179U);

    glBegin(GL_LINES);
    {
      glVertex3f(1024.0F, -20.0F,  0.0F);
      glVertex3f(1024.0F, 20.0F ,  0.0F);
      glVertex3f(1024.0F, 0.0F  , -3.0F);
      glVertex3f(1024.0F, 0.0F  ,  3.0F);
    }
    glEnd();
  }
  glPopMatrix();
}


void CSimPerspectives::DrawInteractions( ContextData& context)
{
  context.zoomViewState().RenderRect3D();
}

//----------------------  ZoomState  --------------------------------

CSimPerspectives::ContextData::ZoomState::ZoomState()
: m_bInit( false)
, m_iViewportX( -1)
, m_iViewportY( -1)
{
}

void CSimPerspectives::ContextData::ZoomState::Init( double dImgWidth, double dImgHeight, int iViewportX, int iViewportY, double scale)
{
  m_bInit &= m_iViewportX == iViewportX && m_iViewportY == iViewportY;
  m_dImgWidth  = dImgWidth;
  m_dImgHeight = dImgHeight;
  m_iViewportX = iViewportX;
  m_iViewportY = iViewportY;

  if( m_bInit)
    return;

  m_bInit = true;
  m_bInRect = false;
  m_bMouseDown = false;
  m_leftCur = 0;
  m_topCur = 0;

  const double dRatioVP  = 1.0 * m_iViewportX / m_iViewportY;
  const double dRatioImg = dImgWidth / dImgHeight;

  if( dImgWidth == 0 || dImgHeight == 0)
  {
    m_rightCur  = m_iViewportX * scale;
    m_bottomCur = m_iViewportY * scale;
  }
  else if( scale == 0)
  {
    if( dRatioVP > dRatioImg)
    {
      m_rightCur  = m_dImgWidth * dRatioVP / dRatioImg;
      m_bottomCur = m_dImgHeight;
    }
    else if( dRatioVP < dRatioImg)
    {
      m_rightCur  = m_dImgWidth;
      m_bottomCur = m_dImgHeight * dRatioImg / dRatioVP;
    }
    else
    {
      m_rightCur  = m_dImgWidth;
      m_bottomCur = m_dImgHeight;
    }
  }
  else
  {
    m_rightCur  = m_dImgWidth * scale;
    m_bottomCur = m_dImgHeight * scale;
  }
  m_bReset = false;
  m_dScaleNew = 1;
  m_dInitScale = scale;
}

void CSimPerspectives::ContextData::ZoomState::Reset()
{
  m_bInit = false;
  Init( m_dImgWidth, m_dImgHeight, m_iViewportX, m_iViewportY, m_dInitScale);
}

bool CSimPerspectives::ContextData::ZoomState::SetMouse( int iMouseX, int iMouseY, double scaleNew, bool bDown, bool bCtrl)
{
  if( scaleNew)
    m_dScaleNew *= pow( 1.05, -scaleNew);

  m_iMouseX = iMouseX;
  m_iMouseY = iMouseY;
  bool bRedraw = m_bMouseDown ^ bDown;
  m_bMouseDown = bDown;
  m_bControl = bCtrl;
  return bRedraw;
}

static void FixMinMax( double & dMin, double & dMax, double dTotal)
{
  if( dMax > dTotal)
  {
    dMin -= dMax - dTotal;
    dMax = dTotal;
  }

  if( dMin < 0)
  {
    dMax -= dMin;
    dMin = 0;
  }
}

bool CSimPerspectives::ContextData::ZoomState::SetKeybord( bool bLeft, bool bRight, bool bUp, bool bDown, bool bControl)
{
  int const iPanningPxl = 10;
  bool bModified = false;
  if( bLeft && bControl)
  {
    m_leftCur += iPanningPxl;
    m_rightCur += iPanningPxl;
    bModified = true;
  }
  else if( bRight && bControl)
  {
    m_leftCur -= iPanningPxl;
    m_rightCur -= iPanningPxl;
    bModified = true;
  }
  else if( bUp && bControl)
  {
    m_topCur += iPanningPxl;
    m_bottomCur += iPanningPxl;
    bModified = true;
  }
  else if( bDown && bControl)
  {
    m_topCur -= iPanningPxl;
    m_bottomCur -= iPanningPxl;
    bModified = true;
  }

  if( bModified)
  {
    FixMinMax( m_leftCur, m_rightCur, m_dImgWidth);
    FixMinMax( m_topCur, m_bottomCur, m_dImgHeight);
  }

  return bModified;
}

static double GetMouseInImg( double dWidthImg, int iWidthViewport, double dOffset, int iMouse)
{
  return 1.0 * ( dWidthImg - 1 ) * iMouse / ( iWidthViewport - 1 ) + dOffset;
}

static void Sort( double & dMin, double & dMax)
{
  double d1 = std::min( dMin, dMax);
  double d2 = std::max( dMin, dMax);
  dMin = d1;
  dMax = d2;
}

void CSimPerspectives::ContextData::ZoomState::Update()
{
  double dImgPosX = GetMouseInImg( abs( m_rightCur - m_leftCur) + 1, m_iViewportX, m_leftCur, m_iMouseX);
  double dImgPosY = GetMouseInImg( abs( m_topCur - m_bottomCur) + 1, m_iViewportY, m_topCur, m_iMouseY);

  // zoom to mouseposition
  // do mouse in center -> zoom -> set new borders
  if( m_dScaleNew != 1)
  {
    double left   = dImgPosX   - m_leftCur;
    double right  = m_rightCur  - dImgPosX;
    double top    = dImgPosY   - m_topCur;
    double bottom = m_bottomCur - dImgPosY;

    left   *= m_dScaleNew;
    right  *= m_dScaleNew;
    top    *= m_dScaleNew;
    bottom *= m_dScaleNew;

    m_leftCur   = dImgPosX - left;
    m_rightCur  = dImgPosX + right;
    m_topCur    = dImgPosY - top;
    m_bottomCur = dImgPosY + bottom;

    m_dScaleNew = 1;

    FixMinMax( m_leftCur, m_rightCur, m_dImgWidth);
    FixMinMax( m_topCur, m_bottomCur, m_dImgHeight);
  }
  else if( ! m_bControl)
  {
    if( ! m_bInRect && m_bMouseDown)
    {
      m_rectLeft   = dImgPosX;
      m_rectRight  = dImgPosX;
      m_rectTop    = dImgPosY;
      m_rectBottom = dImgPosY;
      m_bInRect = true;
    }
    else if( m_bInRect && m_bMouseDown)
    {
      double dRatioXY = 1.0 * m_iViewportX / m_iViewportY;
      m_rectRight = dImgPosX;
      m_rectBottom = dImgPosY;
      double dExtX = m_rectRight - m_rectLeft;
      double dExtY = m_rectBottom - m_rectTop;
      if( abs( dExtX ) / abs( dExtY) < dRatioXY)
      {
        m_rectRight = _copysign( dExtY, dExtX) * dRatioXY + m_rectLeft;
      }
      else if( abs( dExtX ) / abs( dExtY) > dRatioXY)
      {
        m_rectBottom = _copysign( dExtX, dExtY ) / dRatioXY + m_rectTop;
      }
    }
    else if( m_bInRect && ! m_bMouseDown)
    {
      if( abs( m_rectLeft - m_rectRight) > 3 &&
          abs( m_rectTop - m_rectBottom) > 3)
      {
        m_leftCur = m_rectLeft;
        m_rightCur = m_rectRight;
        m_topCur = m_rectTop;
        m_bottomCur = m_rectBottom;
        Sort( m_leftCur, m_rightCur);
        Sort( m_topCur, m_bottomCur);
      }
      m_bInRect = false;
    }
  }
  else if( m_bControl && m_bMouseDown)
  {
    double dLastImgX = GetMouseInImg( abs( m_rightCur - m_leftCur) + 1, m_iViewportX, m_leftCur, m_iLastMouseX);
    double dLastImgY = GetMouseInImg( abs( m_topCur - m_bottomCur) + 1, m_iViewportY, m_topCur, m_iLastMouseY);
    m_leftCur   -= dImgPosX - dLastImgX;
    m_rightCur  -= dImgPosX - dLastImgX;
    m_topCur    -= dImgPosY - dLastImgY;
    m_bottomCur -= dImgPosY - dLastImgY;
    FixMinMax( m_leftCur, m_rightCur, m_dImgWidth);
    FixMinMax( m_topCur, m_bottomCur, m_dImgHeight);
  }

  m_iLastMouseX = m_iMouseX;
  m_iLastMouseY = m_iMouseY;

  return;
}

void CSimPerspectives::ContextData::ZoomState::GetFrustrumPar( double dCenterX, double dCenterY, double dFocalLength
                                                             , GLdouble & left, GLdouble & right, GLdouble & bottom, GLdouble & top) const
{
  left   = dCenterX - m_leftCur;
  right  = m_rightCur - dCenterX;
  top    = dCenterY - m_topCur;
  bottom = m_bottomCur - dCenterY;

  left /= dFocalLength;
  right /= dFocalLength;
  top /= dFocalLength;
  bottom /= dFocalLength;
}

void CSimPerspectives::ContextData::ZoomState::RenderRect2D() const
{
  if( ! m_bInit || ! m_bInRect)
    return;

  glColor3ub( 0, 255, 0);
  glBegin( GL_LINE_LOOP);
    glVertex2d( m_rectLeft , m_rectTop);
    glVertex2d( m_rectRight, m_rectTop);
    glVertex2d( m_rectRight, m_rectBottom);
    glVertex2d( m_rectLeft , m_rectBottom);
  glEnd();
}

void CSimPerspectives::ContextData::ZoomState::GetOrthoPar( GLdouble & left, GLdouble & right, GLdouble & bottom, GLdouble & top) const
{
  left = m_leftCur;
  right = m_rightCur;
  bottom = m_bottomCur;
  top = m_topCur;
}

void CSimPerspectives::ContextData::ZoomState::RenderRect3D() const
{
  glPushAttrib( GL_ALL_ATTRIB_BITS);
  glMatrixMode( GL_PROJECTION);
  glPushMatrix();
  glLoadIdentity();
  glMatrixMode( GL_MODELVIEW);
  glPushMatrix();
  glLoadIdentity();

  glDisable( GL_DEPTH_TEST);
  GLdouble left, right, bottom, top;
  GetOrthoPar( left, right, bottom, top);
  glOrtho( left, right, bottom, top, -1, 1);

  RenderRect2D();

  glMatrixMode( GL_MODELVIEW);
  glPopMatrix();
  glMatrixMode( GL_PROJECTION);
  glPopMatrix();
  glPopAttrib();
}
