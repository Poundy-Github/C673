#ifndef cut_roi_decoder_h__
#define cut_roi_decoder_h__

#include "base_decoder.h"

class RoiCutterDecoder: public BaseDecoder
{
  public:
    static const int C_ADDR_FW_ROI_START_X_LEFT  = 0x000A;
    static const int C_ADDR_FW_ROI_START_Y_LEFT  = 0x000C;
    static const int C_ADDR_FW_ROI_START_X_RIGHT = 0x000E;
    static const int C_ADDR_FW_ROI_START_Y_RIGHT = 0x0010;

    // parse input stream into register map and set luts
    void decodeStream(unsigned short* register_stream, int stream_size);

    bool areRoiRegistersSet();
    int  getRoiStartX_Left();
    int  getRoiStartY_Left();
    int  getRoiStartX_Right();
    int  getRoiStartY_Right();
};
#endif // cut_roi_decoder_h__
