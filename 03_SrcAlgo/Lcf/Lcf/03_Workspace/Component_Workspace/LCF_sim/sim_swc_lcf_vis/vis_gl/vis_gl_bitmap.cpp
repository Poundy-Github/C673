
#include "vis_gl_bitmap.h"

#include "vis_gl.h"

#include <io.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <assert.h>

#ifdef max
#  undef max
#endif

#ifdef VIS_GL_PNG_SUPPORT
#  include <png.h>
#endif

using namespace GL;
using namespace std;

#ifdef _WIN32
#  define read _read
#endif

static std::string FnGetExtension( std::string const & sFilePath)
{
  char const * psz = strrchr( sFilePath.c_str(), '.');
  assert( psz);
  return psz;
}

Bitmap::Bitmap()
: m_bValid( false)
, m_format( eUndef)
{}

Bitmap::Bitmap( std::string const & sFile)
: m_bValid( false)
, m_format( eUndef)
{
  Load( sFile);
}

void readok( int fd, void * vp, int iSize)
{
  int rc = read( fd, vp, iSize);
  assert( rc == iSize);
}

void writeok( int fd, void const * vp, int iSize)
{
  if( ! iSize)
    return;
  int rc = write( fd, vp, iSize);
  assert( rc == iSize);
}

void Bitmap::Load( std::string const & sFile)
{
  std::string sExt = FnGetExtension( sFile);

  if( stricmp( sExt.c_str(), ".bmp") == 0)
    LoadWindowsBmp( sFile);
#ifdef VIS_GL_PNG_SUPPORT
  else if( stricmp( sExt.c_str(), ".png") == 0)
    LoadPNG( sFile);
#endif
  else
    throw "wrong file name extension";
}

#ifdef VIS_GL_PNG_SUPPORT
static void user_error_fn( png_structp, png_const_charp)
{
  int i=0;
}

static void user_warning_fn( png_structp, png_const_charp)
{
  int i=0;
}

void Bitmap::LoadPNG( std::string const & sFile)
{
  m_bValid = true;

  FILE *fp = fopen( sFile.c_str(), "rb");
  if (!fp)
    throw strerror( errno);

  unsigned char cHeader[8];
  fread( cHeader, 1, sizeof( cHeader), fp);
  bool is_png = png_check_sig( cHeader, sizeof( cHeader));

  if (!is_png)
  {
    m_bValid = false;
    fclose( fp);
    throw 2;
  }

  // fseek( fp, 0, SEEK_SET);

  png_structp png_ptr = png_create_read_struct( PNG_LIBPNG_VER_STRING, (png_voidp) NULL, user_error_fn, user_warning_fn);
  assert( png_ptr);

  png_infop info_ptr = png_create_info_struct(png_ptr);
  assert( info_ptr);

  png_init_io(png_ptr, fp);
  png_set_sig_bytes(png_ptr, sizeof( cHeader));

  png_read_png( png_ptr, info_ptr, PNG_TRANSFORM_IDENTITY, NULL);

  m_bih.biSize = sizeof( m_bih);
  m_bih.biPlanes = 1;
  m_bih.biCompression = BI_RGB;
  m_bih.biSizeImage = 0;
  m_bih.biXPelsPerMeter = 0;
  m_bih.biYPelsPerMeter = 0;
  m_bih.biClrUsed = 0;
  m_bih.biClrImportant = 0;
  m_bih.biWidth = png_get_image_width( png_ptr, info_ptr);
  m_bih.biHeight = png_get_image_height( png_ptr, info_ptr);
  m_bih.biBitCount = png_get_bit_depth( png_ptr, info_ptr) * png_get_channels(png_ptr, info_ptr);

  int color_type = png_get_color_type( png_ptr, info_ptr);
  switch( color_type)
  {
  case PNG_COLOR_TYPE_GRAY:
    assert( m_bih.biBitCount = 24);
    m_format = eColorTable;
    png_set_gray_to_rgb( png_ptr);
    break;
  case PNG_COLOR_TYPE_RGB_ALPHA:
    assert( m_bih.biBitCount = 32);
    m_format = eRgbA;
    break;
  case PNG_COLOR_TYPE_RGB:
    assert( m_bih.biBitCount = 24);
    m_format = eRgbA;
    break;
  default:
    assert( 0 && "not implemented");
    break;
  }

  png_bytepp row_pointers = png_get_rows(png_ptr, info_ptr);

  int iLineSize = m_bih.biWidth * m_bih.biBitCount / 8;

  if( (int) m_pixel.size() < iLineSize * Height())
    m_pixel.resize( iLineSize * Height());

  for( int iRow=0; iRow < Height(); iRow++)
  {
    unsigned char * psz = & m_pixel[iLineSize * iRow];
    memcpy( psz, row_pointers[iRow], iLineSize);
  }
  m_iValidBits = m_bih.biBitCount;
}

void Bitmap::SavePNG( std::string const & sFile) const
{
  FILE * fd = fopen( sFile.c_str(), "wb");
  if( ! fd)
    throw "can not open file";

  png_structp png_ptr = png_create_write_struct( PNG_LIBPNG_VER_STRING, 0, 0, 0);
  if (!png_ptr)
  {
    fclose( fd);
    throw "can not png_create_write_struct";
  }

  png_infop info_ptr = png_create_info_struct(png_ptr);
  if (!info_ptr)
  {
    fclose( fd);
    png_destroy_write_struct(&png_ptr, (png_infopp)NULL);
    throw "can not png_create_write_struct";
  }

  png_init_io(png_ptr, fd);

  int iColorType = m_bih.biBitCount == 24 ? PNG_COLOR_TYPE_RGB:
                   m_bih.biBitCount == 32 ? PNG_COLOR_TYPE_RGB_ALPHA:
                   m_bih.biBitCount == 8 ? PNG_COLOR_TYPE_GRAY: -1;
  assert( iColorType != -1);
  png_set_IHDR(png_ptr, info_ptr, m_bih.biWidth, m_bih.biHeight, m_bih.biBitCount, iColorType, PNG_INTERLACE_NONE, PNG_COMPRESSION_TYPE_DEFAULT, PNG_FILTER_TYPE_DEFAULT);

  std::vector<png_byte*> vecRows;
  vecRows.resize( m_bih.biHeight);
  for( int i=0; i < m_bih.biHeight; i++)
  {
    vecRows[i] = (png_byte*) & m_pixel[i * m_bih.biWidth];
  }
  png_write_rows(png_ptr, & vecRows[0], static_cast<png_uint_32>( vecRows.size()));
  png_write_flush(png_ptr);
  png_write_end(png_ptr, info_ptr);
  png_destroy_write_struct(&png_ptr, &info_ptr);
  fclose( fd);
}

#endif // VIS_GL_PNG_SUPPORT

void Bitmap::LoadWindowsBmp( std::string const & sFile)
{
  int fd = _open( sFile.c_str(), O_RDONLY | O_BINARY);
  if( fd == -1)
    throw strerror( errno);

  m_bValid = true;
  try
  {
    struct _stat st;
    int rc = _fstat( fd, & st);
    assert( rc != -1);

    BITMAPFILEHEADER fh;
    readok( fd, & fh, sizeof( fh));
    if( fh.bfType != *(WORD*)"BM")
      throw "wrong file type";
    if( (DWORD) st.st_size != fh.bfSize)
      throw "wrong size";

    readok( fd, & m_bih, sizeof( m_bih));

    rc = lseek( fd, fh.bfOffBits, SEEK_SET);
    assert( rc != -1);

    int iWidthBytes = m_bih.biWidth * 3 + 3 / 4 * 4;
    m_pixel.resize( Height() * iWidthBytes);
    readok( fd, & m_pixel[0], (int) m_pixel.size());
  }
  catch( ...)
  {
    m_bValid = false;
    close( fd);
    throw;
  }
  close( fd);
  m_bValid = true;
  m_format = m_bih.biBitCount == 24 ? eBgr : eColorTable;
  m_iValidBits = m_bih.biBitCount;
}

void Bitmap::Save( std::string const & sFile) const
{
  std::string sExt = FnGetExtension( sFile);

  if( stricmp( sExt.c_str(), ".bmp") == 0)
    SaveBMP( sFile);
  else if( stricmp( sExt.c_str(), ".ppm") == 0)
    SavePPM( sFile);
  else if( stricmp( sExt.c_str(), ".pgm") == 0)
    SavePGM( sFile);
  else
    throw "wrong file name extension";
}

std::vector<unsigned char> GrayColorTable( int iBits, int iValidBits)
{
  std::vector<unsigned char> ret;
  if( iBits == 8 || iBits == 16)
  {
    int iShift = std::max( iValidBits - 8, 0);
    ret.resize( 4 * ( 1 << iBits));
    for( int i=0; i < ( 1 << iBits) ; i++)
    {
      unsigned char ucValue = static_cast<unsigned char>( i >> iShift );
      ret[4*i+0] = ucValue;
      ret[4*i+1] = ucValue;
      ret[4*i+2] = ucValue;
      ret[4*i+3] = ucValue;
    }
  }
  return ret;
}

void Bitmap::SaveBMP( std::string const & sFile) const
{
  assert( m_bValid);

  if( m_format != eBgr && m_format != eColorTable)
  {
    Bitmap bmp = *this;
    bmp.ToBgr();
    bmp.SaveBMP( sFile);
    return;
  }

  int fd = _open( sFile.c_str(), O_BINARY | O_WRONLY | O_CREAT, _S_IREAD | _S_IWRITE);
  if( fd == -1)
    throw strerror( errno);

  try
  {
    int iBytesPerPixel = m_bih.biBitCount / 8;
    int iLineSize = ( m_bih.biWidth * iBytesPerPixel + 3 ) / 4 * 4;
    int iNumColors = m_bih.biBitCount == 24 || m_bih.biBitCount == 32 ? 0 : ( 1 << m_bih.biBitCount);
    BITMAPFILEHEADER fh;
    memset( & fh, 0, sizeof( fh));
    fh.bfType = *(WORD*)"BM";
    fh.bfSize = Height() * iLineSize + sizeof( BITMAPFILEHEADER) + sizeof( m_bih) + iNumColors * 4;
    fh.bfOffBits = sizeof( fh) + sizeof( m_bih) + iNumColors * 4;
    writeok( fd, & fh, sizeof( fh));

    writeok( fd, & m_bih, sizeof( m_bih));

    if( m_bih.biBitCount != 24)
    {
      std::vector<unsigned char> ucColorTable = GrayColorTable( m_bih.biBitCount, m_iValidBits);
      writeok( fd, & ucColorTable[0], (int) ucColorTable.size());
    }

    writeok( fd, & m_pixel[0], (int) m_pixel.size());

#ifdef _DEBUG
    int iPos = lseek( fd, 0, SEEK_CUR);
    assert( iPos == (int) fh.bfSize);
#endif
  }
  catch( ...)
  {
    close( fd);
    throw;
  }
  close( fd);
}

void Bitmap::SavePPM( std::string const & sFile) const
{
  if( m_format != eRgb)
  {
    Bitmap bmp = *this;
    bmp.ToRgb();
    assert( m_format == eRgb);
    bmp.SavePPM( sFile);
    return;
  }

  FILE * fd = fopen( sFile.c_str(), "w");
  assert( fd);

  fprintf( fd,
    "P3\n"
    "# image generated with GL::Bitmap\n"
    "%d %d\n"
    "%d\n"
    , m_bih.biWidth, Height(), 1 << m_iValidBits);
  int iLineSize = m_bih.biWidth * m_bih.biBitCount / 8;

  for( int iy=0; iy < Height(); iy++)
  {
    for( int ix=0; ix < m_bih.biWidth; ix++)
    {
      if( m_bih.biBitCount == 24)
        fprintf( fd, "%d %d %d  ", m_pixel[iy*iLineSize+ix*3], m_pixel[iy*iLineSize+ix*3+1], m_pixel[iy*iLineSize+ix*3+2]);
      else if( m_bih.biBitCount == 8)
        fprintf( fd, "%d %d %d  ", m_pixel[iy*iLineSize+ix], m_pixel[iy*iLineSize+ix], m_pixel[iy*iLineSize+ix]);
      else
        assert( 0 && "not implemented");
    }
    fprintf( fd, "\n");
  }
  fclose( fd);
}

void Bitmap::SavePGM( std::string const & sFile) const
{
  if( m_bih.biBitCount != 8 && m_bih.biBitCount != 16)
    throw "wrong file type";

  FILE * fd = fopen( sFile.c_str(), "w");
  assert( fd);

  fprintf( fd,
    "P2\n"
    "# image generated with GL::Bitmap\n"
    "%d %d\n"
    "%d\n"
    , m_bih.biWidth, Height(), ( 1 << m_iValidBits ) - 1);

  int iLineSize = ( m_bih.biWidth * m_bih.biBitCount / 8 + 3 ) / 4 * 4;

  unsigned short * pUs = (unsigned short*) & m_pixel[0];

  for( int iy=0; iy < Height(); iy++)
  {
    for( int ix=0; ix < m_bih.biWidth; ix++)
    {
      fprintf( fd, "%d ", pUs[iy*iLineSize/2+ix]);
    }
    fprintf( fd, "\n");
  }
  fclose( fd);
}


void Bitmap::Unload()
{
  memset( & m_bih, 0, sizeof( m_bih));
  m_pixel.clear();
  m_bValid = false;
  m_format = eUndef;
}

int Bitmap::Height() const
{
  assert( m_bValid);
  return abs( m_bih.biHeight);
}

int Bitmap::Width() const
{
  assert( m_bValid);
  return m_bih.biWidth;
}

GL::Pixel Bitmap::GetExtension() const
{
  assert( m_bValid);
  return GL::Pixel( m_bih.biWidth, Height());
}

void Bitmap::TexImage( int iLevel, int iInternalFormat, int iBorder) const
{
  assert( m_bValid);
  glPixelStorei( GL_PACK_ALIGNMENT, 4);  // http://de.wikipedia.org/wiki/Windows_Bitmap -> 4 Byte alignement per line
  GLenum format = m_bih.biBitCount == 24 ? GL_RGB :
                  m_bih.biBitCount == 32 ? GL_RGBA :
                                           GL_LUMINANCE;
  GL::TexImage2D( iInternalFormat, GetExtension(), iBorder, format, & m_pixel[0], iLevel);
}

void Bitmap::GetTexImage( int iLevel, GLenum format)
{
  GLint iWidth, iHeight;
  glGetTexLevelParameteriv( GL_TEXTURE_2D, iLevel, GL_TEXTURE_WIDTH, & iWidth);
  glGetTexLevelParameteriv( GL_TEXTURE_2D, iLevel, GL_TEXTURE_HEIGHT, & iHeight);

  short iBytesPerPixel = format == GL_RGB             ? 3 :
                         format == GL_RGBA            ? 4 :
                         format == GL_LUMINANCE       ? 1 :
                                                        0;

  assert( iBytesPerPixel != 0);
  if( iBytesPerPixel == 0)
    throw "not supported";

  int iLineWidthBytes = iWidth * iBytesPerPixel + 3 / 4 * 4;

  m_pixel.resize( iHeight * iLineWidthBytes);

  glPixelStorei( GL_UNPACK_ALIGNMENT, 4);
  GL::GetTexImage2D( GL_RGB, & m_pixel[0], iLevel);

  m_bih.biSize = sizeof( m_bih);
  m_bih.biWidth = iWidth;
  m_bih.biHeight = iHeight;
  m_bih.biPlanes = 1;
  m_bih.biBitCount = iBytesPerPixel * 8;
  m_bih.biCompression = BI_RGB;
  m_bih.biSizeImage = iLineWidthBytes * iHeight;
  m_bih.biXPelsPerMeter = 0;
  m_bih.biYPelsPerMeter = 0;
  m_bih.biClrUsed = 0;
  m_bih.biClrImportant = 0;

  m_bValid = true;
  m_format = GL2Format( format);
  m_iValidBits = m_bih.biBitCount;
}

Bitmap::operator bool() const
{
  return m_bValid;
}

int Bitmap::XPixelsPerMeter() const
{
  return m_bih.biXPelsPerMeter;
}

int Bitmap::YPixelsPerMeter() const
{
  return m_bih.biYPelsPerMeter;
}

void Bitmap::SetXPixelsPerMeter( int iPixels)
{
  m_bih.biXPelsPerMeter = iPixels;
}

void Bitmap::SetYPixelsPerMeter( int iPixels)
{
  m_bih.biYPelsPerMeter = iPixels;
}

void Bitmap::ScaleXY( double dFakX, double dFakY) const
{
  assert( XPixelsPerMeter() && YPixelsPerMeter());

  glMatrixMode( GL_TEXTURE);
  glLoadIdentity();

  glScaled( dFakX * XPixelsPerMeter() / Width()
          , dFakY * YPixelsPerMeter() / Height()
          , 1);
}

void Bitmap::Set( unsigned char * rgb, int iWidth, int iHeight)
{
  int iLineSize = ( iWidth * 3 + 3 ) / 4 * 4;

  memset( & m_bih, 0, sizeof( m_bih));
  m_bih.biSize = sizeof( m_bih);
  m_bih.biWidth = iWidth;
  m_bih.biHeight = iHeight;
  m_bih.biPlanes = 1;
  m_bih.biBitCount = 24;
  m_bih.biCompression = BI_RGB;
  m_bih.biSizeImage = iLineSize * Height();

  m_pixel.resize( m_bih.biSizeImage);
  for( int i=0; i < iHeight; i++)
  {
    memcpy( & m_pixel[i * m_bih.biWidth * 3], rgb + i * iWidth * 3, iWidth);
  }
  m_bValid = true;
  m_format = eRgb;
  m_iValidBits = m_bih.biBitCount;
}

void Bitmap::Set( unsigned short * gray16, int iWidth, int iHeight, int iValidBits)
{
  int iLineSize = ( iWidth * 2 + 3 ) / 4 * 4;

  memset( & m_bih, 0, sizeof( m_bih));
  m_bih.biSize = sizeof( m_bih);
  m_bih.biWidth = iWidth;
  m_bih.biHeight = iHeight;
  m_bih.biPlanes = 1;
  m_bih.biBitCount = 16;
  m_bih.biCompression = BI_RGB;
  m_bValid = true;
  m_bih.biSizeImage = iLineSize * Height();
  m_bih.biClrUsed = 1 << 16;
  m_iValidBits = iValidBits;

  m_pixel.resize( m_bih.biSizeImage);
  unsigned short * pUs = (unsigned short*) & m_pixel[0];
  for( int i=0; i < iHeight; i++)
  {
    memcpy( pUs + i*iLineSize/2, gray16 + i*iLineSize/2, iLineSize);
  }
  m_iValidBits = iValidBits;
  m_bValid = true;
  m_format = eColorTable;
}

void Bitmap::SetTopDown( bool bTopDown)
{
  m_bih.biHeight = bTopDown ? - abs( m_bih.biHeight) : abs( m_bih.biHeight);
}

void Bitmap::ReadPixels( GLenum format)
{
  Screen vp = GetViewport();
  ReadPixels( GL::Screen( 0, 0), vp, format);
}

void Bitmap::ReadPixels(  Screen const & start, Screen const & size, GLenum format)
{
  ReadPixels( start.m_x, start.m_y, size.m_x, size.m_y, format);
}

void Bitmap::ReadPixels(  GLint x, GLint y, GLsizei width, GLsizei height, GLenum format)
{
  int iBytesPerPixel = format == GL_RGB  ? 3 :
                       format == GL_RGBA ? 4 :
                       format == GL_BGR  ? 3 :
                       format == GL_BGRA ? 4 : 1;
  glFinish();
  int iLineSize = ( width * iBytesPerPixel + 3 ) / 4 * 4;
  m_pixel.resize( iLineSize * height);
  GLint iDrawBuffer = -1;
  GL::Get( GL_DRAW_BUFFER, & iDrawBuffer);
  glReadBuffer( iDrawBuffer);
  GLvoid *pixels = & m_pixel[0];
  glPixelStorei( GL_PACK_ALIGNMENT, 4);
  glReadPixels( x, y, width, height, format, GL_UNSIGNED_BYTE, pixels);
  glPixelStorei( GL_PACK_ALIGNMENT, 1);

  m_bih.biSize = sizeof( m_bih);
  m_bih.biWidth = width;
  m_bih.biHeight = height;
  m_bih.biPlanes = 1;
  m_bih.biBitCount = static_cast<WORD>( iBytesPerPixel * 8);
  m_bih.biCompression = BI_RGB;
  m_bih.biSizeImage = static_cast<DWORD>( m_pixel.size());
  m_bih.biXPelsPerMeter = 0;
  m_bih.biYPelsPerMeter = 0;
  m_bih.biClrUsed = 0;
  m_bih.biClrImportant = 0;

  m_bValid = true;
  m_format = GL2Format( format);
  m_iValidBits = m_bih.biBitCount;
}

inline
void SwapRgb( void * vp)
{
  unsigned char * uc = (unsigned char *) vp;
  unsigned char c = uc[0];
  uc[0] = uc[2];
  uc[2] = c;
}

void Bitmap::SwapRgb()
{
  int iLineSize = ( m_bih.biWidth * m_bih.biBitCount / 8 + 3 ) / 4 * 4;
  for( int iy=0; iy < Height(); iy++)
  {
    for( int ix=0; ix < iLineSize - 2; ix+=3)
    {
      ::SwapRgb( & m_pixel[iLineSize*iy+ix]);
    }    
  }
  if( m_format == eRgb)
    m_format = eBgr;
  else if( m_format == eBgr)
    m_format = eRgb;
}

void Bitmap::ToRgb()
{
  if( m_format == eRgbA || m_format == eBgrA)
    EraseAlpha();
  if( m_format == eBgr)
    SwapRgb();
}

void Bitmap::ToBgr()
{
  if( m_format == eRgbA || m_format == eBgrA)
    EraseAlpha();
  if( m_format == eRgb)
    SwapRgb();
}

Bitmap::Format Bitmap::GL2Format( GLenum format)
{
  switch( format)
  {
  case GL_RGB:  return eRgb;
  case GL_RGBA: return eRgbA;
  case GL_BGR:  return eBgr;
  case GL_BGRA: return eBgrA;
  default:
    return eColorTable;
  }
}

int Bitmap::LineSize() const
{
  return ( m_bih.biWidth * m_bih.biBitCount / 8 + 3 ) / 4 * 4;
}

void Bitmap::EraseAlpha()
{
  assert( m_format == eRgbA || m_format == eBgrA);

  std::vector<unsigned char> rgb;
  int iLineSize = ( m_bih.biWidth * 3 + 3 ) / 4 * 4;
  rgb.resize( iLineSize);
  for( int iy = 0; iy < Height(); iy ++)
  {
    for( int ix = 0; ix < m_bih.biWidth; ix++)
    {
      rgb[iy * iLineSize + ix*3+0] = m_pixel[iy*LineSize()+ix*4+0];
      rgb[iy * iLineSize + ix*3+1] = m_pixel[iy*LineSize()+ix*4+1];
      rgb[iy * iLineSize + ix*3+2] = m_pixel[iy*LineSize()+ix*4+2];
    }
  }

  m_format = m_format == eRgbA ? eRgb : eBgr;
  m_bih.biBitCount = 24;
  m_pixel.swap( rgb);
}
