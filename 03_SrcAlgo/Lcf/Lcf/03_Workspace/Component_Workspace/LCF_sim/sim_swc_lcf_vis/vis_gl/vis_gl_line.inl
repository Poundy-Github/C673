
namespace GL
{
  inline
  Line::Line()
  {}

  inline
  Line::Line( Pos const & p0, Pos const & p1)
  : m_p0( p0)
  , m_p1( p1)
  {}

  inline
  Line operator+( Line const & line, Pos const & offset)
  {
    Line ret = line;
    ret.m_p0 += offset;
    ret.m_p1 += offset;
    return ret;
  }

  inline
  Line::operator Pos const *() const
  {
    return & m_p0;
  }

}
