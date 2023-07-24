
namespace GL
{
  inline
  Pos::Pos()
  : m_x( -1)
  , m_y( -1)
  , m_z( -1)
  {}

  inline
  Pos::Pos( float x, float y, float z)
  : m_x( x)
  , m_y( y)
  , m_z( z)
  {}

  inline
  Pos & Pos::operator+=( Pos const & o)
  {
    m_x += o.m_x;
    m_y += o.m_y;
    m_z += o.m_z;
    return *this;
  }

  inline
  bool Pos::operator==( Pos const & o) const
  {
    return m_x == o.m_x && m_y == o.m_y && m_z == o.m_z;
  }

  inline
  Pos::Pos( Pos const & o)
  : m_x( o.m_x)
  , m_y( o.m_y)
  , m_z( o.m_z)
  {}

  inline
  Pos operator+( Pos const & p1, Pos const & p2)
  {
    return Pos( p1) += p2;
  }

  inline
  Pos operator*( float f, Pos const & p)
  {
    Pos ret = p;
    ret.m_x += f;
    return ret;
  }

  inline
  Pos operator/( Pos const & p, float fDiv)
  {
    return Pos( p.m_x / fDiv, p.m_y / fDiv, p.m_z / fDiv);
  }

  inline
  Pos operator-( Pos const & p1, Pos const & p2)
  {
    return Pos( p1.m_x - p2.m_x, p1.m_y - p2.m_y, p1.m_z - p2.m_z);
  }

  inline
  Pos::operator float const*() const
  {
    return & m_x;
  }
}
