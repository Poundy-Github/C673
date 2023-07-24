#pragma once
#pragma warning( disable : 4481 )
#pragma warning( disable : 4100 )

#define WIN32_LEAN_AND_MEAN

#include <atlbase.h>

#include <map>
#include <fstream>
#include <cassert>

#include "sim_converter_base.h"
#include "../../vdy_sim/vdy_adapter/include/interface_base.h"

#define MAX(a,b) a>b?a:b;

#undef min
#undef max
#include "adapter_converter_base.h"

#define CONV_I32VERSION_TO_TUPPLE(x)         (unsigned char)(((x) >> 16) & 0xFF), (unsigned char)(((x) >> 8) & 0xFF), (unsigned char)((x) & 0xFF)

extern std::wfstream dbg;