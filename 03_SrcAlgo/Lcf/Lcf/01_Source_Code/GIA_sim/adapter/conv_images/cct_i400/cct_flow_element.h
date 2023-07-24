#ifndef flow_element_h__
#define flow_element_h__

#include "algo_type.h"

//---------------------------------------------------------------------------------
//| 31 | 30 | 29 | 28 | 27 | 26 | 25 | 24 | 23 | 22 | 21 | 20 | 19 | 18 | 17 | 16 |
//|  P |CollisionCount|   dy:  8.4 (signed, 2th complement)                       |
//---------------------------------------------------------------------------------
//| 15 | 14 | 13 | 12 | 11 | 10 | 09 | 08 | 07 | 06 | 05 | 04 | 03 | 02 | 01 | 00 |
//| xx   xx   xx   xx |   dx:  8.4 (signed, 2th complement)                       |
//---------------------------------------------------------------------------------
//
// parity_mask:          0x80000000 (1 bit)
// collision_count_mask: 0x70000000 (4 bit unsigned)
// dy_mask:              0x0FFF0000 (8.4 fixed point, 2th complement in mask)
// dx_mask:              0x00000FFF (8.4 fixed point, 2th complement in mask)
//
// collision_count_shift: 28
// dy_shift:              16
// dx_shift:               0

#define CCT_FE_PARITY_MASK          (0x80000000)
#define CCT_FE_COLLISION_COUNT_MASK (0x70000000)
#define CCT_FE_DY_MASK              (0x0FFF0000)
#define CCT_FE_DX_MASK              (0x00000FFF)
#define CCT_FE_INVALID_BIT_MASK     (0x00000800)
#define CCT_FE_S16Q8_SCALE          (0.00390625F) //  = 1 / (1 << 8)

static inline uint8 CCT_FE_CollisionCount(const FlowElement_t fe)
{
  const FlowElement_t cc = (fe & CCT_FE_COLLISION_COUNT_MASK) >> 28;
  return (uint8)cc;
}

static inline uint8 CCT_FE_Parity(const FlowElement_t fe)
{
  const FlowElement_t p = (fe & CCT_FE_PARITY_MASK) >> 31;
  return (uint8)p;
}

static inline s16q8_t CCT_FE_DyFixedPoint(const FlowElement_t fe)
{
  // shift 12bit MSB to sint16 MSB (lower 2 bytes)
  const FlowElement_t dy = (fe & CCT_FE_DY_MASK) >> 12;
  // cast to signed short fixed point type
  return (s16q8_t)dy;
}

static inline s16q8_t CCT_FE_DxFixedPoint(const FlowElement_t fe)
{
  // shift 12bit MSB to sint16 MSB (lower 2 bytes)
  const FlowElement_t dx = (fe & CCT_FE_DX_MASK) << 4;
  // cast to signed short fixed point type
  return (s16q8_t)dx;
}

static inline sint8 CCT_FE_DyInt(const FlowElement_t fe)
{
  // shift 12bit MSB to sint8 MSB (lower 1 byte)
  const FlowElement_t dy = (fe & CCT_FE_DY_MASK) >> 20;
  // cast to signed char fixed point type
  return (sint8)dy;
}

static inline sint8 CCT_FE_DxInt(const FlowElement_t fe)
{
  // shift 12bit MSB to sint8 MSB (lower 1 byte)
  const FlowElement_t dx = (fe & CCT_FE_DX_MASK) >> 4;
  // cast to signed char fixed point type
  return (sint8)dx;
}

static inline float32 CCT_FE_DyFloat(const FlowElement_t fe)
{
  const s16q8_t fe_fixed = CCT_FE_DyFixedPoint(fe);
  return ((float32)fe_fixed) * CCT_FE_S16Q8_SCALE;
}

static inline float32 CCT_FE_DxFloat(const FlowElement_t fe)
{
  const s16q8_t fe_fixed  = CCT_FE_DxFixedPoint(fe);
  return ((float32)fe_fixed) * CCT_FE_S16Q8_SCALE;
}

static inline bool8 CCT_FE_IsValid(const FlowElement_t fe)
{
  const FlowElement_t valid = (fe & CCT_FE_DX_MASK) - CCT_FE_INVALID_BIT_MASK;
  return (bool8)(valid != 0);
}

#ifdef __cplusplus

namespace cct
{
  class CFlowElement
  {
  public:
    static const FlowElement_t PARITY_MASK          = CCT_FE_PARITY_MASK;
    static const FlowElement_t COLLISION_COUNT_MASK = CCT_FE_COLLISION_COUNT_MASK;
    static const FlowElement_t DY_MASK              = CCT_FE_DY_MASK;
    static const FlowElement_t DX_MASK              = CCT_FE_DX_MASK;

    static const FlowElement_t INVALID_BIT_MASK     = CCT_FE_INVALID_BIT_MASK;

    CFlowElement(const FlowElement_t& fe) : m_data(fe) {}

    operator FlowElement_t()       { return m_data; }
    operator FlowElement_t() const { return m_data; }

    uint8     collisionCount() const { return CCT_FE_CollisionCount(m_data); }
    uint8     parity()         const { return CCT_FE_Parity(m_data);         }
    s16q8_t   dyFixedPoint()   const { return CCT_FE_DyFixedPoint(m_data);   }
    s16q8_t   dxFixedPoint()   const { return CCT_FE_DxFixedPoint(m_data);   }
    sint8     dyInt()          const { return CCT_FE_DyInt(m_data);          }
    sint8     dxInt()          const { return CCT_FE_DxInt(m_data);          }
    float32   dyFloat()        const { return CCT_FE_DyFloat(m_data);        }
    float32   dxFloat()        const { return CCT_FE_DxFloat(m_data);        }
    boolean_t isValid()        const { return CCT_FE_IsValid(m_data) != 0;   }

  private:
    const FlowElement_t& m_data;
    CFlowElement& operator=(const CFlowElement&);
  };
}

#endif

#endif // flow_element_h__
