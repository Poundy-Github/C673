
namespace GL
{

  inline
  Screen::Screen()
    : ix( -1)
    , iy( -1)
  {}

  inline
  Screen::Screen( int _ix, int _iy)
    : ix( _ix)
    , iy( _iy)
  {}

  inline
  Screen::operator int const *() const
  {
    return & ix;
  }

  inline
  bool Screen::operator==( Screen const & o)
  {
    return ix == o.ix && iy == o.iy;
  }

  inline
  bool Screen::operator!=( Screen const & o)
  {
    return ! operator==( o);
  }
}
