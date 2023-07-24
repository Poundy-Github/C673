
namespace GL
{
  inline
  Color::Color()
  : m_fR( -1.0F)
  , m_fG( -1.0F)
  , m_fB( -1.0F)
  , m_fA( -1.0F)
  {}

  inline
  Color::Color( int ucR, int ucG, int ucB, int ucA)
  : m_fR( ucR / 255.0F)
  , m_fG( ucG / 255.0F)
  , m_fB( ucB / 255.0F)
  , m_fA( ucA / 255.0F)
  {}

  inline
  Color::Color( int iSat, int iA)
  : m_fR( iSat / 255.0F)
  , m_fG( iSat / 255.0F)
  , m_fB( iSat / 255.0F)
  , m_fA( iSat / 255.0F)
  {}

  inline
  Color::Color( float fR, float fG, float fB, float fA)
  : m_fR( fR)
  , m_fG( fG)
  , m_fB( fB)
  , m_fA( fA)
  {}

  inline
  Color::Color( float fSat, float fA)
  : m_fR( fSat)
  , m_fG( fSat)
  , m_fB( fSat)
  , m_fA( fA)
  {}

  inline
  Color::Color( Color const & color, float fA)
  : m_fR( color.m_fR)
  , m_fG( color.m_fG)
  , m_fB( color.m_fB)
  , m_fA( fA)
  {}

  inline
  Color::operator float const*() const
  {
    return & m_fR;
  }

  inline
  Color Color::operator*=( float f)
  {
    m_fR *= f;
    m_fG *= f;
    m_fB *= f;
    return *this;
  }

  inline
  Color Color::operator/=( float f)
  {
    m_fR /= f;
    m_fG /= f;
    m_fB /= f;
    return *this;
  }

  inline
  Color operator*( Color const & color, float f)
  {
    return Color( color) *= f;
  }

  inline
  Color operator/( Color const & color, float f)
  {
    return Color( color) /= f;
  }
}
