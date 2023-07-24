#ifndef sim_swc_cut_roi_h__
#define sim_swc_cut_roi_h__

#include "cut_roi_decoder.h"

#include "sim_swc_base.h"
#include "sim_swc_img.h"

#include "simReceivePort.h"
#include "simProvidePort.h"

class CSimRoiCutter : public CSimSwcBase, public CSimSwcImg
{
public:
  CSimRoiCutter();

  static void InitExit       (void* PlgID, long Param1, long Param2);
  static void Doit           (void* PlgID, long Param1, long Param2);
  static void ParseConfigData(void* PlgID, long Param1, long Param2);

  void InitExit();
  void DecodeFexData();
  void Doit();

private:
  SimReceivePort<unsigned short, simUI16_t> m_rpRoiStartX;
  SimReceivePort<unsigned short, simUI16_t> m_rpRoiStartY;

  SimReceivePort<unsigned short, simUI16_t> m_rpRoiSizeX;
  SimReceivePort<unsigned short, simUI16_t> m_rpRoiSizeY;

  SimReceivePort<CTKImageData_t*, simREFERENCE_t> m_rpImage;
  SimProvidePort<CTKImageData_t*, simREFERENCE_t> m_ppImage;

  SimReceivePort<unsigned short*, simREFERENCE_t> m_rpFpgaConfigData;

  SimReceivePort<unsigned int, simUI32_t> m_rpProcessLeftImage;

  unsigned long long m_uiTimestamp;
  unsigned int       m_uiFrameCounter;

  RoiCutterDecoder m_cConfigDataDecoder;
};
#endif // sim_swc_cut_roi_h__
