
#include "stdafx.h"
#include "image_fingerprint.h"
#include <cstddef>
#include <limits>

/* ***************************************************************************
  Functionname:     MurmurHashAligned2() - All code is released to the public 
                                    domain. For business purposes, Murmurhash 
                                    is under the MIT license. */ /*!
  Description:      Same algorithm as MurmurHash2, but only does aligned reads - 
                    Should be safer on certain platforms - 
                    Performance will be lower than MurmurHash2

  @param[in]        -
  @param[out]       -

  @return           -
  @pre              -
  @post             -
  @author           Austin Appleby
**************************************************************************** */
#define MIX(h,k,m) { k *= m; k ^= k >> r; k *= m; h *= m; h ^= k; }

uint32 ifp::CImageFingerPrint::MurmurHashAligned2 ( const uint8 * key, sint32 len, uint32 seed )
{
  uint32 m;
  uint8* data;
  sint32 r;
  sint32 align;
  sint32 sl;
  sint32 sr;
  uint32 h;
  uint32 t;
  uint32 d;
  uint32 k;
  
  m = 0x5bd1e995;
  r = 24;

  data = (uint8*)key;

  h = seed ^ len;

  align = static_cast<sint32>(reinterpret_cast<std::ptrdiff_t>(data) & 3);

  if(align && (len >= 4))
  {
    // Pre-load the temp registers

    t = 0;
    d = 0;

    switch(align)
    {
    case 1: t |= data[2] << 16;
    case 2: t |= data[1] << 8;
    case 3: t |= data[0];
    }

    t <<= (8 * align);

    data += 4-align;
    len  -= 4-align;

    sl = 8 * (4-align);
    sr = 8 * align;

    // Mix

    while(len >= 4)
    {
      d = *(uint32*)data;
      t = (t >> sr) | (d << sl);

      k = t;

      MIX(h,k,m);

      t = d;

      data += 4;
      len -= 4;
    }

    // Handle leftover data in temp registers

    d = 0;

    if(len >= align)
    {
      switch(align)
      {
      case 3: d |= data[2] << 16;
      case 2: d |= data[1] << 8;
      case 1: d |= data[0];
      }

      k = (t >> sr) | (d << sl);
      MIX(h,k,m);

      data += align;
      len -= align;

      //----------
      // Handle tail bytes

      switch(len)
      {
      case 3: h ^= data[2] << 16;
      case 2: h ^= data[1] << 8;
      case 1: h ^= data[0];
        h *= m;
      };
    }
    else
    {
      switch(len)
      {
      case 3: d |= data[2] << 16;
      case 2: d |= data[1] << 8;
      case 1: d |= data[0];
      case 0: h ^= (t >> sr) | (d << sl);
        h *= m;
      }
    }

    h ^= h >> 13;
    h *= m;
    h ^= h >> 15;

    return h;
  }
  else
  {
    while(len >= 4)
    {
      k = *(uint32 *)data;

      MIX(h,k,m);

      data += 4;
      len -= 4;
    }

    //----------
    // Handle tail bytes

    switch(len)
    {
    case 3: h ^= data[2] << 16;
    case 2: h ^= data[1] << 8;
    case 1: h ^= data[0];
      h *= m;
    };

    h ^= h >> 13;
    h *= m;
    h ^= h >> 15;

    return h;
  }
}

void ifp::CImageFingerPrint::v_ImageFingerPrintGeneration(const uint8*  const charImgPtr,
                                                          const uint16        width,
                                                          const uint16        height,
                                                          const sint16        iPixelBytes,
                                                          const sint32        iRowBytes,
                                                                uint32*       ui32_fingerprint)
{
  sint32 widthRatio;
  uint16 sampleColNumberRatio;
  uint16 colShift2, colShift3, rowShift1, rowShift2, rowShift3, rowShift4;
  const uint8 *data0, *data11, *data21, *data31, *data41;
  uint8 data[4 * IFP_SAMPLE_COL_NUMBER * 4];    // 4 is the maximum for iPixelBytes
  uint8 i, j;

  sampleColNumberRatio  = IFP_SAMPLE_COL_NUMBER * iPixelBytes;
  widthRatio            = iRowBytes;
  data0                 = charImgPtr;

  std::memset(&data[0],      0, 4 * IFP_SAMPLE_COL_NUMBER * 4 * sizeof(uint8));

  *ui32_fingerprint = 0;

  assert( widthRatio < static_cast<sint32>( std::numeric_limits<uint16>::max() ) );
  colShift2 = ((width*iPixelBytes) - sampleColNumberRatio)/2;  // Take pixels middle of row
  colShift2 -= colShift2%IFP_ALIGNMENT;                        // Alignment to 128
  colShift3 = ((width*iPixelBytes) - sampleColNumberRatio);    // Take pixels end of row
  colShift3 -= colShift3%IFP_ALIGNMENT;                        // Alignment to 128

  rowShift1 = 0;                                    // Take pixels begin of 2nd line
  rowShift2 = height/2;                             // Take pixels middle of image
  rowShift3 = 3*height/4;                           // Take pixels middle of image
  rowShift4 = height-4-IFP_SAMPLE_ROW_NUMBER;       // Take pixels end of image

  for (i=1; i<=IFP_SAMPLE_ROW_NUMBER; i++)
  {
    data11 = data0 + (i + rowShift1)        * widthRatio;
    data21 = data0 + (i + rowShift2)        * widthRatio + colShift2;
    data31 = data0 + (i + rowShift3)        * widthRatio;
    data41 = data0 + (i + rowShift4)        * widthRatio + colShift3;

    for (j=0; j<sampleColNumberRatio; j++)
    {
      data[j]                             = *data11;
      data[j + sampleColNumberRatio]      = *data21;
      data[j + 2 * sampleColNumberRatio]  = *data31;
      data[j + 3 * sampleColNumberRatio]  = *data41;

      data11++;        data21++;        data31++;        data41++;
    }
  }

  *ui32_fingerprint = MurmurHashAligned2(data, 4 * IFP_SAMPLE_COL_NUMBER * 4, 464);
}

