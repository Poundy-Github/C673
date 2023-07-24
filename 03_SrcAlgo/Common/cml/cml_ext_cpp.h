/*! \file **********************************************************************

  COMPANY:                   Continental AG, A.D.C. GmbH

  CPU:                       CPU-Independent

  COMPONENT:                 CML (Common Math Library)

  MODULNAME:                 cml_ext.h

  DESCRIPTION:               External C++ header for the Common Math Library

  AUTHOR:                    Christian Exner

  CREATION DATE:             28.03.2013

  VERSION:                   $Revision: 1.9 $

**************************************************************************** */

/*****************************************************************************
  INCLUDE PROTECTION
*****************************************************************************/

#ifndef cml_ext_cpp_h__
#define cml_ext_cpp_h__

/*****************************************************************************
  INCLUDES
*****************************************************************************/
extern "C"
{
#include "cml_ext.h"
}

#include "cml_stl_iterator.h"
#include "cml_stl_array.h"
#include "cml_stl_array2d.h"
#include "cml_stl_vector.h"
#include "cml_stl_matrix.h"
#include "cml_stl_list.h"
#include "cml_stl_algorithm.h"
#include "cml_stl_cmath.h"
#include "cml_stl_type_traits.h"
#include "cml_stl_point.h"
#include "cml_stl_memory.h"

#endif // cml_ext_cpp_h__
