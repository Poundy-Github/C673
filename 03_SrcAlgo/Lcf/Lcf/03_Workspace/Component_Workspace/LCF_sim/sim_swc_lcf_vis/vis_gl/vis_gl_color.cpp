
#include "vis_gl_color.h"

#include <assert.h>

const GL::Color GL::Color::red      ( 255, 0, 0, 255);
const GL::Color GL::Color::green    ( 0, 128, 0, 255);
const GL::Color GL::Color::blue     ( 0, 0, 255, 255);
const GL::Color GL::Color::white    ( 255, 255, 255, 255);
const GL::Color GL::Color::black    ( 0, 0, 0, 255);
const GL::Color GL::Color::yellow   ( 255, 255, 0, 255);
const GL::Color GL::Color::cyan     ( 0, 255, 255);
const GL::Color GL::Color::magenta  ( 255, 0, 255);
const GL::Color GL::Color::gray     ( 0x80, 0x80, 0x80);
const GL::Color GL::Color::silver   ( 0xc0, 0xc0, 0xc0);
const GL::Color GL::Color::maroon   ( 0x80, 0, 0);
const GL::Color GL::Color::olive    ( 0x80, 0x80, 0x00);
const GL::Color GL::Color::lime     ( 0, 0xff, 0);
const GL::Color GL::Color::aqua     ( 0, 0xff, 0xff);
const GL::Color GL::Color::teal     ( 0, 0x80, 0x80);
const GL::Color GL::Color::navy     ( 0, 0, 0x80);
const GL::Color GL::Color::fuchsia  ( 0xff, 0, 0xff);
const GL::Color GL::Color::purple   ( 0x80, 0, 0x80);
const GL::Color GL::Color::orange   ( 0xff, 0xa5, 0);
const GL::Color GL::Color::pink     ( 0xFF, 0xC0, 0xCB);
const GL::Color GL::Color::hotPink  ( 0xFF, 0x69, 0xB4);
const GL::Color GL::Color::lightGray( 0xd3, 0xd3, 0xd3);
const GL::Color GL::Color::violet   ( 0xEE, 0x82, 0xEE);
const GL::Color GL::Color::orangeRed( 0xFF, 0x45, 0x00);

const GL::Color GL::Color::opaque( 0, 0, 0, 0);

GL::Color::Color()
: m_fR( -1.0F)
, m_fG( -1.0F)
, m_fB( -1.0F)
, m_fA( -1.0F)
{}

GL::Color::Color( int ucR, int ucG, int ucB, int ucA)
: m_fR( ucR / 255.0F)
, m_fG( ucG / 255.0F)
, m_fB( ucB / 255.0F)
, m_fA( ucA / 255.0F)
{}

GL::Color::Color( double dIntensity, double fOpaque)
: m_fR( (float) dIntensity)
, m_fG( (float) dIntensity)
, m_fB( (float) dIntensity)
, m_fA( (float) fOpaque)
{}

GL::Color::Color( int iSat, int iA)
: m_fR( iSat / 255.0F)
, m_fG( iSat / 255.0F)
, m_fB( iSat / 255.0F)
, m_fA( iA / 255.0F)
{}

GL::Color::Color( float fR, float fG, float fB, float fA)
: m_fR( fR)
, m_fG( fG)
, m_fB( fB)
, m_fA( fA)
{}

GL::Color::Color( double fR, double fG, double fB, double fA)
: m_fR( static_cast<float>( fR))
, m_fG( static_cast<float>( fG))
, m_fB( static_cast<float>( fB))
, m_fA( static_cast<float>( fA))
{}

GL::Color::Color( float fSat, float fA)
: m_fR( fSat)
, m_fG( fSat)
, m_fB( fSat)
, m_fA( fA)
{}

GL::Color::Color( Color const & color, float fA)
: m_fR( color.m_fR)
, m_fG( color.m_fG)
, m_fB( color.m_fB)
, m_fA( fA)
{}

GL::Color::operator float const*() const
{
  return & m_fR;
}

GL::Color & GL::Color::operator*=( double f)
{
  m_fR *= (float) f;
  m_fG *= (float) f;
  m_fB *= (float) f;
  return *this;
}

GL::Color & GL::Color::operator*=( Color const & clr)
{
  m_fR *= clr.m_fR;
  m_fG *= clr.m_fG;
  m_fB *= clr.m_fB;
  m_fA *= clr.m_fA;
  return *this;
}

GL::Color & GL::Color::operator/=( double f)
{
  assert( f != 0);
  m_fR /= (float) f;
  m_fG /= (float) f;
  m_fB /= (float) f;
  return *this;
}

GL::Color GL::operator*( Color const & color, double f)
{
  return Color( color) *= f;
}

GL::Color GL::operator*( Color const & color, Color const & c2)
{
  return GL::Color( color) *= c2;
}

GL::Color GL::operator/( Color const & color, double f)
{
  return Color( color) /= f;
}

float GL::Color::RedFloat() const
{
  return m_fR;
}

float GL::Color::GreenFloat() const
{
  return m_fG;
}

float GL::Color::BlueFloat() const
{
  return m_fB;
}

float GL::Color::AlphaFloat() const
{
  return m_fA;
}

void GL::Color::SetRed( float fRed)
{
  m_fR = fRed;
}

void GL::Color::SetGreen( float fGreen)
{
  m_fG = fGreen;
}

void GL::Color::SetBlue( float fBlue)
{
  m_fB = fBlue;
}

void GL::Color::SetAlpha( float fAlpha)
{
  m_fA = fAlpha;
}

float GL::Color::dot( Color c1, Color c2)
{
  return  c1.m_fR * c1.m_fR
        + c1.m_fG * c2.m_fG
        + c1.m_fB * c2.m_fB
        + c1.m_fA * c2.m_fA;
}

float GL::Color::Saturation() const
{
  float fMax = max( max( m_fR, m_fG), m_fB);
  float fMin = min( min( m_fR, m_fG), m_fB);
  return fMax - fMin;
}
