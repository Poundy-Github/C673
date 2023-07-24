/*! \file **********************************************************************

  COMPANY:        Continental AG

  PROJECT:        MFC300

  CPU:            

  COMPONENT:      SAC - Stereo Auto Calibration

  MODULNAME:      sac_math.h  

  DESCRIPTION:    maths classes

  AUTHOR:         J. Schmidt

  CREATION DATE:  22.07.2009

  VERSION:        $Revision: 1.1 $

  CHANGES:        $Log: sac_math.h  $
  CHANGES:        Revision 1.1 2021/12/13 17:24:36CET Wang, David (Wangd3) 
  CHANGES:        Initial revision
  CHANGES:        Member added to project /ADAS/Projects/MFC5xx/MFC5J3/06_Algorithm/DPU/04_Engineering/01_Source_Code/GIA_sim/sim_swc_wrapper/Include/project.pj
  CHANGES:        Revision 1.0 2017/03/03 10:35:32CET Sorge, Sven (uidg3181) 
  CHANGES:        Initial revision
  CHANGES:        Member added to project /ADAS/SW/Integration/06_Simulation_Components/GIA_GenericInterfaceAdapter/04_Engineering/03_Workspace/Component_Workspace/GIA_sim/sim_swc_wrapper/Include/project.pj
  CHANGES:        Revision 1.31 2013/10/21 15:39:43CEST Mueller, Reik (muellerr5) 
  CHANGES:        - added #define RAD2DEG
  CHANGES:        - Added comments -  muellerr5 [Oct 21, 2013 3:39:43 PM CEST]
  CHANGES:        Change Package : 199831:1 http://mks-psad:7002/im/viewissue?selection=199831
  CHANGES:        Revision 1.30 2013/03/11 14:28:29CET Ruland, Thomas (uidw0251) 
  CHANGES:        - added sac_legacy_typeDefs.h to reactivate old style typedefs
  CHANGES:        --- Added comments ---  uidw0251 [Mar 11, 2013 2:28:29 PM CET]
  CHANGES:        Change Package : 173649:1 http://mks-psad:7002/im/viewissue?selection=173649
  CHANGES:        Revision 1.29 2013/01/24 14:03:38CET Pfitzer, Martin (uidu4871) 
  CHANGES:        using algo_type instead of cct_type
  CHANGES:        --- Added comments ---  uidu4871 [Jan 24, 2013 2:03:38 PM CET]
  CHANGES:        Change Package : 131461:3 http://mks-psad:7002/im/viewissue?selection=131461
  CHANGES:        Revision 1.28 2012/07/24 15:59:55CEST Behrens, Alexander (uidv2823) 
  CHANGES:        cahnge code to fixe MISRA errors
  CHANGES:        --- Added comments ---  uidv2823 [Jul 24, 2012 3:59:56 PM CEST]
  CHANGES:        Change Package : 134029:1 http://mks-psad:7002/im/viewissue?selection=134029
  CHANGES:        Revision 1.27 2012/07/23 18:59:43CEST Stache, Nicolaj (uidt6711) 
  CHANGES:        weighting function for wss distortion model implemented
  CHANGES:        --- Added comments ---  uidt6711 [Jul 23, 2012 6:59:43 PM CEST]
  CHANGES:        Change Package : 67326:3 http://mks-psad:7002/im/viewissue?selection=67326
  CHANGES:        Revision 1.26 2012/07/17 11:40:52CEST Behrens, Alexander (uidv2823) 
  CHANGES:        add code coverage tags (without changing code line numbering)
  CHANGES:        --- Added comments ---  uidv2823 [Jul 17, 2012 11:40:53 AM CEST]
  CHANGES:        Change Package : 134029:1 http://mks-psad:7002/im/viewissue?selection=134029
  CHANGES:        Revision 1.25 2012/07/14 10:32:28CEST Behrens, Alexander (uidv2823) 
  CHANGES:        add code coverage for dev 4.6.0
  CHANGES:        --- Added comments ---  uidv2823 [Jul 14, 2012 10:32:28 AM CEST]
  CHANGES:        Change Package : 134029:1 http://mks-psad:7002/im/viewissue?selection=134029
  CHANGES:        Revision 1.24 2012/07/02 10:21:06CEST Visscher-EXT, Eric (uidk7517) 
  CHANGES:        Added code review findings
  CHANGES:        --- Added comments ---  uidk7517 [Jul 2, 2012 10:21:06 AM CEST]
  CHANGES:        Change Package : 127722:1 http://mks-psad:7002/im/viewissue?selection=127722
  CHANGES:        Revision 1.23 2012/03/30 14:06:09CEST Garcia, Lucien (uid26778) 
  CHANGES:        Lint warning corrections : Bitexactness test and MTS simulation OK
  CHANGES:        --- Added comments ---  uid26778 [Mar 30, 2012 2:06:09 PM CEST]
  CHANGES:        Change Package : 80273:1 http://mks-psad:7002/im/viewissue?selection=80273
  CHANGES:        Revision 1.22 2012/03/08 11:23:46CET Konarski-EXT, Witek (uidt8403) 
  CHANGES:        Removed PC-LINT/Misra error.
  CHANGES:        --- Added comments ---  uidt8403 [Mar 8, 2012 11:23:47 AM CET]
  CHANGES:        Change Package : 101150:9 http://mks-psad:7002/im/viewissue?selection=101150
  CHANGES:        Revision 1.21 2012/02/24 16:07:08CET Garcia, Lucien (uid26778) 
  CHANGES:        Remove unused code
  CHANGES:        --- Added comments ---  uid26778 [Feb 24, 2012 4:07:08 PM CET]
  CHANGES:        Change Package : 80273:2 http://mks-psad:7002/im/viewissue?selection=80273
  CHANGES:        Revision 1.20 2011/11/16 19:38:27CET Garcia, Lucien (uid26778) 
  CHANGES:        Remove lint warnings
  CHANGES:        --- Added comments ---  uid26778 [Nov 16, 2011 7:38:27 PM CET]
  CHANGES:        Change Package : 80273:1 http://mks-psad:7002/im/viewissue?selection=80273
  CHANGES:        Revision 1.19 2011/11/14 16:09:36CET Spruck Jochen (spruckj) (spruckj) 
  CHANGES:        Init the not learnd buffer entries of yaw angle object median buffer with the yaw angle of the temp model
  CHANGES:        --- Added comments ---  spruckj [Nov 14, 2011 4:09:36 PM CET]
  CHANGES:        Change Package : 87958:1 http://mks-psad:7002/im/viewissue?selection=87958
  CHANGES:        Revision 1.18 2011/11/09 18:13:02CET Stache Nicolaj (uidt6711) (uidt6711) 
  CHANGES:        Bugfix-Papenburg
  CHANGES:        --- Added comments ---  uidt6711 [Nov 9, 2011 6:13:02 PM CET]
  CHANGES:        Change Package : 87467:1 http://mks-psad:7002/im/viewissue?selection=87467
  CHANGES:        Revision 1.17 2011/10/17 15:37:51CEST Spruck Jochen (spruckj) (spruckj) 
  CHANGES:        Add additional ReInit buffer function
  CHANGES:        --- Added comments ---  spruckj [Oct 17, 2011 3:37:51 PM CEST]
  CHANGES:        Change Package : 84444:1 http://mks-psad:7002/im/viewissue?selection=84444
  CHANGES:        Revision 1.16 2011/09/29 10:43:18CEST Spruck Jochen (spruckj) (spruckj) 
  CHANGES:        Add ring buffer class, used by yaw angle delta mean
  CHANGES:        --- Added comments ---  spruckj [Sep 29, 2011 10:43:18 AM CEST]
  CHANGES:        Change Package : 79035:1 http://mks-psad:7002/im/viewissue?selection=79035
  CHANGES:        Revision 1.15 2011/09/26 11:45:21CEST Spruck Jochen (spruckj) (spruckj) 
  CHANGES:        - Romve misra issues
  CHANGES:        - Remove misra by adding namespace SAC
  CHANGES:        Revision 1.14 2011/09/23 17:00:13CEST Spruck Jochen (spruckj) (spruckj) 
  CHANGES:        - Remove misra issues
  CHANGES:        Revision 1.13 2011/09/20 14:41:16CEST Spruck Jochen (spruckj) (spruckj) 
  CHANGES:        - Add interval class
  CHANGES:        - Add some math constants
  CHANGES:        - Add function for lin interpol
  CHANGES:        --- Added comments ---  spruckj [Sep 20, 2011 2:41:16 PM CEST]
  CHANGES:        Change Package : 79036:1 http://mks-psad:7002/im/viewissue?selection=79036
  CHANGES:        Revision 1.12 2011/07/26 15:55:46CEST Garcia Lucien (uid26778) (uid26778) 
  CHANGES:        mark safety relevant datas
  CHANGES:        --- Added comments ---  uid26778 [Jul 26, 2011 3:55:46 PM CEST]
  CHANGES:        Change Package : 67298:1 http://mks-psad:7002/im/viewissue?selection=67298
  CHANGES:        Revision 1.11 2011/07/25 19:00:19CEST Garcia Lucien (uid26778) (uid26778) 
  CHANGES:        Mark all safety relevant data and constant
  CHANGES:        --- Added comments ---  uid26778 [Jul 25, 2011 7:00:20 PM CEST]
  CHANGES:        Change Package : 67298:1 http://mks-psad:7002/im/viewissue?selection=67298
  CHANGES:        Revision 1.10 2011/05/30 16:54:29CEST Stache Nicolaj (uidt6711) (uidt6711) 
  CHANGES:        Mod: Heap sort for quality check criterion
  CHANGES:        --- Added comments ---  uidt6711 [May 30, 2011 4:54:29 PM CEST]
  CHANGES:        Change Package : 67326:2 http://mks-psad:7002/im/viewissue?selection=67326
  CHANGES:        Revision 1.9 2011/03/11 15:38:23CET Wagner Ulrich (uid04769) (uid04769) 
  CHANGES:        Bugfix: sqrt() was not defined on DSP
  CHANGES:        --- Added comments ---  uid04769 [Mar 11, 2011 3:38:23 PM CET]
  CHANGES:        Change Package : 37886:2 http://mks-psad:7002/im/viewissue?selection=37886
  CHANGES:        Revision 1.8 2011/02/28 14:06:08CET Stache Nicolaj (uidt6711) (uidt6711) 
  CHANGES:        ROI shift added
  CHANGES:        --- Added comments ---  uidt6711 [Feb 28, 2011 2:06:08 PM CET]
  CHANGES:        Change Package : 58788:1 http://mks-psad:7002/im/viewissue?selection=58788
  CHANGES:        Revision 1.7 2009/09/08 14:03:07CEST jschmidt 
  CHANGES:        replaced glob_type.he by cct_type.h
  CHANGES:        --- Added comments ---  jschmidt [2009/09/08 12:03:08Z]
  CHANGES:        Change Package : 26824:1 http://LISS014:6001/im/viewissue?selection=26824
  CHANGES:        --- Added comments ---  jschmidt [2009/09/08 12:03:08Z]
  CHANGES:        Change Package : 26824:1 http://LISS014:6001/im/viewissue?selection=26824
  CHANGES:        Revision 1.6 2009/08/20 10:14:02CEST Ulrich Wagner (uwagner) 
  CHANGES:        replaced #include "memory.h" by #include "string.h" (memory.h is unknown on DSP)
  CHANGES:        --- Added comments ---  uwagner [2009/08/20 08:14:02Z]
  CHANGES:        Change Package : 26829:1 http://LISS014:6001/im/viewissue?selection=26829
  CHANGES:        --- Added comments ---  uwagner [2009/08/20 08:14:02Z]
  CHANGES:        Change Package : 26829:1 http://LISS014:6001/im/viewissue?selection=26829
  CHANGES:        Revision 1.5 2009/07/29 17:35:11CEST jschmidt 
  CHANGES:        added code
  CHANGES:        --- Added comments ---  jschmidt [2009/07/29 15:35:12Z]
  CHANGES:        Change Package : 26824:1 http://LISS014:6001/im/viewissue?selection=26824
  CHANGES:        --- Added comments ---  jschmidt [2009/07/29 15:35:12Z]
  CHANGES:        Change Package : 26824:1 http://LISS014:6001/im/viewissue?selection=26824
  CHANGES:        Revision 1.4 2009/07/27 17:26:57CEST jschmidt 
  CHANGES:        code update
  CHANGES:        --- Added comments ---  jschmidt [2009/07/27 15:26:57Z]
  CHANGES:        Change Package : 26824:1 http://LISS014:6001/im/viewissue?selection=26824
  CHANGES:        --- Added comments ---  jschmidt [2009/07/27 15:26:57Z]
  CHANGES:        Change Package : 26824:1 http://LISS014:6001/im/viewissue?selection=26824
  CHANGES:        Revision 1.3 2009/07/23 15:48:55CEST jschmidt 
  CHANGES:        added cross and invert functions
  CHANGES:        --- Added comments ---  jschmidt [2009/07/23 13:48:55Z]
  CHANGES:        Change Package : 26824:1 http://LISS014:6001/im/viewissue?selection=26824
  CHANGES:        --- Added comments ---  jschmidt [2009/07/23 13:48:55Z]
  CHANGES:        Change Package : 26824:1 http://LISS014:6001/im/viewissue?selection=26824
  CHANGES:        Revision 1.2 2009/07/23 15:17:47CEST jschmidt 
  CHANGES:        updates
  CHANGES:        --- Added comments ---  jschmidt [2009/07/23 13:17:47Z]
  CHANGES:        Change Package : 26824:1 http://LISS014:6001/im/viewissue?selection=26824
  CHANGES:        --- Added comments ---  jschmidt [2009/07/23 13:17:47Z]
  CHANGES:        Change Package : 26824:1 http://LISS014:6001/im/viewissue?selection=26824
  CHANGES:        Revision 1.1 2009/07/22 17:22:54CEST jschmidt 
  CHANGES:        Initial revision
  CHANGES:        Member added to project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/SAC_StereoAutoCalibration/04_Engineering/01_Source_Code/Kernel/project.pj

**************************************************************************** */

#ifndef SAC_MATH_H
#define SAC_MATH_H

#include "sac_legacy_typeDefs.h"
#include "algo_glob.h"
#include <cmath>
// ~CodeReview ~ID:dc903b5691de45ba963fd8b9b09a9f4a ~Reviewer:CW01\uidk7517 ~Date:26.06.2012 ~Priority:2 ~Comment:Remove or comment dead code
//#include <memory.h>
#include <cstring>  // memset/memcpy

using namespace std;  // some problems, finding sqrt() on DSP => using std and including cmath instead of math.h

#include "sac_math_types.h"

#define MAX( a, b ) ((a)>(b))?(a):(b)
#define MIN( a, b ) ((a)<(b))?(a):(b)
#define ROUND(x) (((x)>=0.0F)?(x+0.5F):(x-0.5F))
/*! Absolute value */
#define ABS(x)        (((x)<(0))?(-(x)):(x))
/*! Absolute value for floating point*/
#define fABS(x)        (((x)<(0.F))?(-(x)):(x))

/*! Determines the smaller of two values - (simulation)  */
#define MIN_FLOAT(x,y)      (((x)<(y))?(x):(y))
/*! Limit the floating point number to a minimum and a maximum value - (simulation) */
#define MINMAX_FLOAT(min,max,value)  (((value) < (min))? (min) : (((value) > (max))? (max) : (value)))

/*! Calculating the square (x*x) of a number */
#define SQR(x)        ((x)*(x))

/*! Constant PI */
#define C_PI  (3.14159265359F)

/*! Delta threshold value for 32 bit floating point equality tests  @see EQ_ZERO */
#define C_F32_DELTA  (0.0001F)

/*! Conversion of angle from degree to radian unit */
#define DEG2RAD(deg_)  ((deg_)*(C_PI/180.F))
#define RAD2DEG(rad_)  ((rad_)*(180.F/C_PI))



const f32_t sac_eps = 10e-6f;

void heapSort(f32_t numbers[], const i32_t array_size);
void siftDown(f32_t numbers[], i32_t root, const i32_t bottom);

namespace SAC {
f32_t SACLFunction(const f32_t Input, const f32_t InputMin,const f32_t InputMax, const f32_t OutputMin, const f32_t OutputMax);

class Intervall
{
public:
  /** Default constructor to silence the compiler. */
  Intervall() {}
  ~Intervall() {}


  void SACStatIntervalInit(SACStatInterval_t * const StatInterval) const;
  void SACStatIntervalInitInput(SACStatInterval_t * const StatInterval) const;
  void SACStatIntervalAdd(SACStatInterval_t * const StatInterval,const f32_t Value , const f32_t Weight) const;
  void SACStatIntervalReduce(SACStatInterval_t * const StatInterval, const f32_t Factor) const;
  void SACStatIntervalMerge( SACStatInterval_t * const StatInterval_1,  const SACStatInterval_t * const StatInterval_2 ) const;
  void SACStatIntervalMeanDev(SACStatInterval_t * const StatInterval) const;
  void SACStatIntervalPrealloc(SACStatInterval_t * const StatInterval,const f32_t Mean, const f32_t Volume, const f32_t Dev) const;

};

class RingBuffer
{
public:
  void BufferInit(SACRingBuffer_t * const pBuffer, const ui32_t size) const;
  void BufferReInit(SACRingBuffer_t * const pBuffer) const;
  void BufferPushValue(const f32_t fValue, SACRingBuffer_t * const pBuffer) const;
  void BufferSort(const SACRingBuffer_t * const pBuffer, SACRingBuffer_t * const pSortedBuffer) const;
  f32_t GetBufferMedian(const SACRingBuffer_t * const pBuffer) const;
  f32_t GetQuantileMedian(const SACRingBuffer_t * const pSortedBuffer, const f32_t LowerBound, const f32_t UpperBound) const;
};

}

class vec3
{
public:
  f32_t x, y, z;
  f32_t *vec_array;     // array access


  vec3() { vec_array = &x; }
  vec3(f32_t _x, f32_t _y, f32_t _z) : x(_x), y(_y), z(_z) { vec_array = &x; }
  /* <ln_offset:+1 COVERAGE reviewer name: Alexander Behrens date: 14.07.2012 reason: Function is currently not used. */
  vec3(const f32_t* xyz) : x(xyz[0]), y(xyz[1]), z(xyz[2]) { vec_array = &x; }
  /* <ln_offset:+1 COVERAGE reviewer name: Alexander Behrens date: 14.07.2012 reason: Function is currently not used. */
  vec3(const vec3 &u) : x(u.x), y(u.y), z(u.z) { vec_array = &x; }

  /* <ln_offset:+1to+4 COVERAGE reviewer name: Alexander Behrens date: 14.07.2012 reason: Operator currently not used. */
  bool operator==(const vec3 &u) const
  {
    return (u.x == x && u.y == y && u.z == z) ? true : false;
  }

  /* <ln_offset:+1to+4 COVERAGE reviewer name: Alexander Behrens date: 14.07.2012 reason: Operator currently not used. */
  bool operator!=( const vec3 &rhs ) const
  {
    return !(*this == rhs );
  }

  /* <ln_offset:+1to+7 COVERAGE reviewer name: Alexander Behrens date: 14.07.2012 reason: Operator currently not used. */
  vec3& operator*=(const f32_t &lambda)
  {
    x*= lambda;
    y*= lambda;
    z*= lambda;
    return *this;
  }

  vec3& operator=(const vec3 &v)
  {
    x=v.x;
    y=v.y;
    z=v.z;
    return *this;
  }

  /* <ln_offset:+1to+4 COVERAGE reviewer name: Alexander Behrens date: 14.07.2012 reason: Operator currently not used. */
  vec3 operator - () const
  {
    return vec3(-x, -y, -z);
  }

  /* <ln_offset:+1to+7 COVERAGE reviewer name: Alexander Behrens date: 14.07.2012 reason: Operator currently not used. */
  vec3& operator-=(const vec3 &u)
  {
    x-= u.x;
    y-= u.y;
    z-= u.z;
    return *this;
  }

  /* <ln_offset:+1to+7 COVERAGE reviewer name: Alexander Behrens date: 14.07.2012 reason: Operator currently not used. */
  vec3& operator+=(const vec3 &u)
  {
    x+= u.x;
    y+= u.y;
    z+= u.z;
    return *this;
  }

  f32_t normalize();
  /* <ln_offset:+1 COVERAGE reviewer name: Alexander Behrens date: 14.07.2012 reason: Function is covered by function "norm". */
  f32_t sq_norm() const { return x * x + y * y + z * z; }

  /* <ln_offset:+1 COVERAGE reviewer name: Alexander Behrens date: 14.07.2012 reason: Function has currently no callers. */
  f32_t norm() const { return sqrtf(sq_norm()); }

  f32_t & operator[](int i)
  {
    return vec_array[i];
  }

  /* <ln_offset:+1to+4 COVERAGE reviewer name: Alexander Behrens date: 14.07.2012 reason: Operator currently not used. */
  f32_t operator[](int i) const
  {
    return vec_array[i];
  }
};

inline const vec3 operator+(const vec3 &u, const vec3 &v)
{
  return vec3(u.x + v.x, u.y + v.y, u.z + v.z);
}

inline const vec3 operator-(const vec3 &u, const vec3 &v)
{
  return vec3(u.x - v.x, u.y - v.y, u.z - v.z);
}

/* <ln_offset:+1to+4 COVERAGE reviewer name: Alexander Behrens date: 14.07.2012 reason: Operator currently not used. */
inline const vec3 operator^(const vec3 &u, const vec3 &v)
{
  return vec3(u.y * v.z - u.z * v.y, u.z * v.x - u.x * v.z, u.x * v.y - u.y * v.x);
}

/* <ln_offset:+1to+4 COVERAGE reviewer name: Alexander Behrens date: 14.07.2012 reason: Operator currently not used. */
inline const vec3 operator*(const f32_t s, const vec3 &u)
{
  return vec3(s * u.x, s * u.y, s * u.z);
}

inline const vec3 operator/(const vec3 &u, const f32_t s)
{
  return vec3(u.x / s, u.y / s, u.z / s);
}

/* <ln_offset:+1to+4 COVERAGE reviewer name: Alexander Behrens date: 14.07.2012 reason: Operator currently not used. */
inline const vec3 operator*(const vec3 &u, const vec3 &v)
{
  return vec3(u.x * v.x, u.y * v.y, u.z * v.z);
}


// ~CodeReviewBegin ~ID:aa4d32890372864a739a3d00e07678b3 ~Reviewer:CW01\uidk7517 ~Date:26.06.2012 ~Priority:2 ~Comment:Remove or comment dead code
/*
    for all the matrices...a<x><y> indicates the element at row x, col y

    For example:
    a01 <-> row 0, col 1 
*/
// ~CodeReviewEnd   ~ID:aa4d32890372864a739a3d00e07678b3

class mat3
{
public:
  f32_t a00, a10, a20;        // standard names for components
  f32_t a01, a11, a21;        // standard names for components
  f32_t a02, a12, a22;        // standard names for components
  f32_t *mat_array;           // array access

  mat3();
  mat3(const f32_t * const array);
  mat3(const mat3 &M);
  /* <ln_offset:+1to+6 COVERAGE reviewer name: Alexander Behrens date: 13.07.2012 reason: No callers. Dead code. */
  mat3( const f32_t& f0,  const f32_t& f1,  const f32_t& f2,
        const f32_t& f3,  const f32_t& f4,  const f32_t& f5,
        const f32_t& f6,  const f32_t& f7,  const f32_t& f8 )
        : a00( f0 ), a10( f1 ), a20( f2 ),
        a01( f3 ), a11( f4 ), a21( f5 ),
        a02( f6 ), a12( f7 ), a22( f8) {mat_array = &a00;}

  /* <ln_offset:+1to+4 COVERAGE reviewer name: Alexander Behrens date: 13.07.2012 reason: No callers. Dead code. */
  const vec3 col(const int i) const
  {
    return vec3(&mat_array[i * 3]);
  }

  /* <ln_offset:+1to+4 COVERAGE reviewer name: Alexander Behrens date: 14.07.2012 reason: Operator currently not used. */
  const vec3 operator[](int i) const
  {
    return vec3(mat_array[i], mat_array[i + 3], mat_array[i + 6]);
  }

  const f32_t& operator()(const int &i, const int &j) const
  {
    return mat_array[ j * 3 + i ];
  }

  f32_t& operator()(const int &i, const int &j)
  {
    return  mat_array[ j * 3 + i ];
  }

  mat3& operator=(const mat3 &m)
  {
    memcpy(mat_array,m.mat_array,9*sizeof(f32_t));
    return *this;
  }

  /* <ln_offset:+1to+6 COVERAGE reviewer name: Alexander Behrens date: 13.07.2012 reason: No callers. Dead code. */
  void set_row(int i, const vec3 &v)
  {
    mat_array[i] = v.x;
    mat_array[i + 3] = v.y;
    mat_array[i + 6] = v.z;
  }

  /* <ln_offset:+1to+6 COVERAGE reviewer name: Alexander Behrens date: 13.07.2012 reason: No callers. Dead code. */
  void set_col(int i, const vec3 &v)
  {
    mat_array[i * 3] = v.x;
    mat_array[i * 3 + 1] = v.y;
    mat_array[i * 3 + 2] = v.z;
  }

  /* <ln_offset:+1to+5 COVERAGE reviewer name: Alexander Behrens date: 13.07.2012 reason: No callers. Dead code. */
  void setMat(const f32_t *array)
  {
    mat_array = &a00;
    memcpy(mat_array, array, sizeof(f32_t) * 9);
  }
// ~CodeReviewBegin ~ID:ce70c35c1213208472c871bcef94dfaf ~Reviewer:CW01\uidk7517 ~Date:26.06.2012 ~Priority:2 ~Comment:Remove or comment dead code
#if 0 // CODE NOT USED
  void set_rot(const f32_t &theta, const vec3 &v);
#endif
// ~CodeReviewEnd   ~ID:ce70c35c1213208472c871bcef94dfaf
  void set_rot(const vec3 &u, const vec3 &v);

  mat3 operator*(const mat3& B) const;
};

const vec3 operator*(const mat3&, const vec3&);
const vec3 operator*(const vec3&, const mat3&);

/* <ln_offset:+1to+6 COVERAGE reviewer name: Alexander Behrens date: 13.07.2012 reason: Inline function may be used. Works correctly. */
inline const mat3 operator-(const mat3 &u, const mat3 &v)
{
  return mat3(u.a00 - v.a00, u.a10 - v.a10, u.a20 - v.a20,
    u.a01 - v.a01, u.a11 - v.a11, u.a21 - v.a21,
    u.a02 - v.a02, u.a12 - v.a12, u.a22 - v.a22);
}

mat3 &transpose(mat3 &A);

// Computes B = inverse(A)
//       -1
//  B = A
mat3 & invert(mat3 & B, const mat3 & A);

// computes the cross product ( v cross w) and stores the result in u
// i.e.     u = v cross w
void cross(vec3 &u, const vec3 &v, const vec3 &w);

void dot(f32_t &u, const vec3 &v, const vec3 &w);
f32_t dot(const vec3 &v, const vec3 &w);

f32_t angle(const vec3 &u, const vec3 &v);

// Computes the squared magnitude
/* <ln_offset:+1to+4 COVERAGE reviewer name: Alexander Behrens date: 13.07.2012 reason: Inline function is called by vec3Norm, and thus covered. */
inline f32_t vec3SQNorm(const vec3 &n)
{
  return n.x * n.x + n.y * n.y + n.z * n.z;
}

/* <ln_offset:+1to+4 COVERAGE reviewer name: Alexander Behrens date: 17.07.2012 reason: Function has no callers. */
inline f32_t vec3Norm(const vec3 &n)
{
  return sqrtf(vec3SQNorm(n));
}

// ~CodeReviewBegin ~ID:9c6eb5ba300ca6475cc876821314e18e ~Reviewer:CW01\uidk7517 ~Date:26.06.2012 ~Priority:2 ~Comment:Remove or comment dead code
/* funktioniert nicht so richtig ... 
const f32_t array9_id[] =         { 1.0f, 0.0f, 0.0f,
                                    0.0f, 1.0f, 0.0f,
                                    0.0f, 0.0f, 1.0f};

const mat3 mat3_id(array9_id);
*/

// ~CodeReviewEnd   ~ID:9c6eb5ba300ca6475cc876821314e18e

f32_t sigmoidWeight(const f32_t rowZeroWeight, const f32_t rowOneWeight, const f32_t row );
f32_t sigmoidValue(const f32_t u, const f32_t v, const f32_t v_top, const f32_t v_bot, const f32_t u_topLeft, const f32_t u_topRight, const f32_t u_botLeft, const f32_t u_botRight, const f32_t edgeWidth);


#endif /* SAC_MATH_H */

