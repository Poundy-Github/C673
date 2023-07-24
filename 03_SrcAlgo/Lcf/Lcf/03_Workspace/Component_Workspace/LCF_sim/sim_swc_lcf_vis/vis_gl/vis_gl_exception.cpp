
#include "vis_gl_exception.h"

vis_gl_exception::vis_gl_exception( char const * cMsg)
: m_sMsg( cMsg)
{}

const char* vis_gl_exception::what() const throw()
{
  return m_sMsg.c_str();
}
