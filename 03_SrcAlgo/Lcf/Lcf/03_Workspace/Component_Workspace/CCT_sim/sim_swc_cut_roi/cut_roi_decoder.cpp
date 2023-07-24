#include "cut_roi_decoder.h"

// parse input stream into register map and set luts afterwards
void RoiCutterDecoder::decodeStream(unsigned short* register_stream, int stream_size)
{
  if(isRegisterStream(register_stream))
  {
    __super::decodeStream(FrameworkID, register_stream, stream_size);
  }
}

bool RoiCutterDecoder::areRoiRegistersSet()
{
  return  isRegisterSet(C_ADDR_FW_ROI_START_X_LEFT)
    &&    isRegisterSet(C_ADDR_FW_ROI_START_Y_LEFT)
    &&    isRegisterSet(C_ADDR_FW_ROI_START_X_RIGHT)
    &&    isRegisterSet(C_ADDR_FW_ROI_START_Y_RIGHT);
}

int RoiCutterDecoder::getRoiStartX_Left()
{
  return getRegisterValue(C_ADDR_FW_ROI_START_X_LEFT);
}

int RoiCutterDecoder::getRoiStartY_Left()
{
  return getRegisterValue(C_ADDR_FW_ROI_START_Y_LEFT);
}

int RoiCutterDecoder::getRoiStartX_Right()
{
  return getRegisterValue(C_ADDR_FW_ROI_START_X_RIGHT);
}

int RoiCutterDecoder::getRoiStartY_Right()
{
  return getRegisterValue(C_ADDR_FW_ROI_START_Y_RIGHT);
}
