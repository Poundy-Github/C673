
#pragma once

/** \class vis_gl_exception
 *
 *  exception class thrwon by vis_gl submodule.
 *
 *  \ingroup ld_vis2_opengl
 *
 */

#include <exception>
#include <string>

class vis_gl_exception : public std::exception
{
public:
  /// @param cMsg Message getable by what()
  vis_gl_exception( char const * cMsg);

  /// @return cMsg from CTOR
  virtual const char* what() const throw();

protected:
  std::string m_sMsg;
};
