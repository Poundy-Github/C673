#ifndef cct_disparity_element_h__
#define cct_disparity_element_h__

#include "algo_type.h"

namespace cct
{
  // ---------------------------------------------------------------------------------
  // | 15 | 14 | 13 | 12 | 11 | 10 | 09 | 08 | 07 | 06 | 05 | 04 | 03 | 02 | 01 | 00 |
  // | xx   xx   Q    Q  |   dx:  8.3 (signed, 2th complement)                  |  V |
  // ---------------------------------------------------------------------------------
  // valid_mask: 0x0001
  // disp_mask:  0x0FFE (8.3 fixed point, 2th complement in mask)
  // 
  // valid_shift: 0
  // disp_shift:  1
  class CDisparityElement
  {
  public:
    static const DisparityElement_t VALID_MASK     = 0x0001;
    static const DisparityElement_t DISPARITY_MASK = 0x0FFE;
    static const DisparityElement_t SIGN_BIT       = 0x0800;
    static const DisparityElement_t QUALITY_MASK   = 0x3000;

    CDisparityElement(const DisparityElement_t& de) : m_data(de) {}

    boolean_t isValid() const
    {
      return (m_data & VALID_MASK) != 0;
    }

    boolean_t isValidNotZero() const
    {
      return isValid() && ((m_data & DISPARITY_MASK) != 0);
    }

    // this function also returns 1 if the sign bit as well as the disparity are zero !
    boolean_t isValidPositive() const
    {
      return isValid() && ((m_data & SIGN_BIT) == 0);
    }

    boolean_t isNegative() const
    {
      return (m_data & SIGN_BIT) == (SIGN_BIT);
    }

    uint16 dispQuality() const
    {
      return (m_data & QUALITY_MASK) >> (12); 
    }

    s16q8_t asFixedPoint() const
    {
      // shift 11bit MSB to sint16 MSB
      const DisparityElement_t d = (m_data & DISPARITY_MASK) << 4;
      // cast to signed short fixed point type
      return static_cast<s16q8_t>(d);
    }

    sint16 asInt() const
    {
      return toInt<sint16,8>(asFixedPoint());
    }

    float32 asFloat() const
    {
      return toFloat<8>(asFixedPoint());
    }

  private:
    const DisparityElement_t& m_data;

    template<class R, uint32 Q, class T>
    static R toInt(const T& val)
    {
      const T val_int = val >> Q;
      return static_cast<R>(val_int);
    }

    template<uint32 Q, class T>
    static float32 toFloat(const T& val)
    {
      static const uint32  Q_SCALE     = 1 << Q;
      static const float32 Q_SCALE_INV = static_cast<float32>(1) / static_cast<float32>(Q_SCALE);

      const float32 val_casted = static_cast<float32>(static_cast<sint16>(val));

      return val_casted * Q_SCALE_INV;
    }

    CDisparityElement& operator=(const CDisparityElement&);
  };
}

#endif // cct_disparity_element_h__
