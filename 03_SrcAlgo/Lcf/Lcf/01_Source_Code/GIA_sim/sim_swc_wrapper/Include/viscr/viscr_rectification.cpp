#include <cassert>
#include <cstring>
#include <cmath>
#include <viscr_rectification.hpp>
#include <viscr_matrix.hpp>
#include <viscr_solve.hpp>

/**  please do not modify. the MMX implementation depends on it. 14 bits are
 * accurate enough.*/
#define RECTIFICATION_GREY_FIXPOINT (1<<14) 

void
viscr_rectification_alloc( 
    viscr_rectification & data, 
    const viscr_image_size & size)
{
  data.size=size;
  data.weight.resize( size.u*size.v*4);
  data.offset.resize( size.u*size.v);
}

void 
viscr_rectification_free(
    viscr_rectification & )
{
}

#ifdef HAVE_MMX
extern "C" void ts_rectification_core_16_14(void);
void
viscr_rectification_rectify(
    viscr_image & out,
    const viscr_image & in,
    const viscr_rectification & rect)
{
  assert( out.size==rect.size);

  viscr_uint32 params[6];
  params[0]=out.size.u*sizeof(viscr_uint16);
  params[1]=(unsigned)in.data;
  params[2]=(unsigned)out.data;
  params[3]=(unsigned)&rect.weight[0];
  params[4]=(unsigned)&rect.offset[0];
  params[5]=out.size.u*out.size.v;
#ifdef _WIN32
  __asm {
      push ebp
      push eax
      push ebx
      push ecx
      push edx
      push edi
      push esi
      mov ebp, params
      call ts_rectification_core_16_14 
      pop esi
      pop edi
      pop edx
      pop ecx
      pop ebx
      pop eax
      pop ebp
  }
#else
  asm(
      /* "push %%ebx \n"   rabe: uncomment for GCC 3.4.3 */
      "pushl %%ebp \n"
      "movl %0,%%ebp \n"
      "call rectification_core_16_14 \n"
      "popl %%ebp \n"
      /* "pop %%ebx \n"    rabe: uncomment for GCC 3.4.3 */
      : /* No output */
      : "m" (&params)
      : "eax", "ebx", "ecx", "edx", "edi", "esi"  /* rabe: remove "ebx" for GCC 3.4.3 */
     );
#endif
}

#else

static void 
rectifyNConsecutivePixel(
    const viscr_pixel * inPixel00,
    const viscr_uint32 * pOffs,
    const viscr_uint16 * pQ,
    viscr_pixel * outPixel,
    viscr_uint inputWidth,
    viscr_uint n)
{
  while( n)
  { 
    viscr_int32 offs=(viscr_int32)(*pOffs);

    viscr_pixel f_00 = inPixel00[offs];
    viscr_pixel f_01 = inPixel00[offs+inputWidth];
    viscr_pixel f_10 = inPixel00[offs+1];
    viscr_pixel f_11 = inPixel00[offs+inputWidth+1];

    // order of q3 and q2 has been swapped due to MMX.
    viscr_int q1 = *pQ++;
    viscr_int q3 = *pQ++;
    viscr_int q2 = *pQ++;
    viscr_int q4 = *pQ++;

    viscr_pixel outval=viscr_pixel( (
          f_00 * q1+ 
          f_01 * q2+ 
          f_10 * q3+ 
          f_11 * q4)/RECTIFICATION_GREY_FIXPOINT);

    *outPixel = outval;

    pOffs++;
    outPixel++;

    n--;
  }
}

void
viscr_rectification_rectify(
    viscr_image & out,
    const viscr_image & in,
    const viscr_rectification & rect)
{
  assert( out.size==rect.size);
  rectifyNConsecutivePixel( 
    in.data,
    &rect.offset[0],
    &rect.weight[0],
    out.data,
    out.size.u,
    out.size.u*out.size.v);
}
#endif

typedef void (*tDistortPixelFcn)( 
    viscr_float & distU, 
    viscr_float & distV, 
    viscr_float u, 
    viscr_float v,
    void * userData);

static void
fill_rectification_table(
    viscr_rectification & rect,
    const viscr_image_size & input_size,
    tDistortPixelFcn distort,
    void * userData
    )
{
  memset( &rect.offset[0], 0, sizeof( rect.offset[0])*rect.size.u*rect.size.v);
  memset( &rect.weight[0], 0, sizeof( rect.weight[0])*rect.size.u*rect.size.v*4);

  viscr_uint uvInd=0;
  for( viscr_int v=0; v<rect.size.v; v++)
  {
    for( viscr_int u=0; u<rect.size.u; ++u, ++uvInd)
    { 
      float distU, distV;

      distort( 
          distU, distV, 
          (float)u, (float)v,
          userData);

      int um = (int)floorf(distU);
      int vm = (int)floorf(distV);
      
      if( 0<=um && um+1<input_size.u &&
          0<=vm && vm+1<input_size.v )
      {
        // Assuming row major storage for grey reps.
        rect.offset[uvInd]=(um + input_size.u * vm)
#ifdef HAVE_MMX
          * sizeof( viscr_uint32)
#endif
          ;

        // precalculation
        float diffU = distU - um;
        float diffV = distV - vm;
        float a = diffU * diffV;

        /* Lagrange interpolation coefficients*/
        float q1=(a - diffU - diffV + 1.0f);
        float q2=(diffV - a);
        float q3=(diffU - a);
        float q4=a;

        rect.weight[4*uvInd+0] = viscr_int16( q1 * RECTIFICATION_GREY_FIXPOINT);
        // These two are flipped due to mmx order.
        rect.weight[4*uvInd+2] = viscr_int16( q2 * RECTIFICATION_GREY_FIXPOINT);
        rect.weight[4*uvInd+1] = viscr_int16( q3 * RECTIFICATION_GREY_FIXPOINT);

        rect.weight[4*uvInd+3] = viscr_int16( q4 * RECTIFICATION_GREY_FIXPOINT);
      }
    }
  }
}



static bool
build_Po(
    viscr_mat33 & invPo_33,
    viscr_vec3 & Po_4,
    const viscr_camera & k)
{
  // A = [ au  0 u0;
  //       0  av v0;
  //       0   0  1];
  // P = A[R | t].

  viscr_mat33 A;
  viscr_mat34 Rt;
  viscr_mat34 Po;
  viscr_mat33 Po_33;
  A.m(0,0)=k.f;
  A.m(0,1)=0.0f;
  A.m(0,2)=k.cu;
  A.m(1,0)=0.0f;
  A.m(1,1)=k.f*k.fs;
  A.m(1,2)=k.cv;
  A.m(2,0)=0.0f;
  A.m(2,1)=0.0f;
  A.m(2,2)=1.0f;

  for( viscr_uint r=0; r<3; ++r)
  {
    Rt.m(r,3)=k.m2c_t.v[r];
    for( viscr_uint c=0; c<3; ++c)
      Rt.m(r,c)=k.m2c_r.m(r,c);
  }

  viscr_mat_mult_mat( Po.m, A.m, Rt.m);

  for( viscr_uint r=0; r<3; ++r)
  {
    Po_4.v[r]=Po.m(r,3);
    for( viscr_uint c=0; c<3; ++c)
      Po_33.m(r,c)=Po.m(r,c);
  }

  viscr_mat33 LU;
  viscr_mat33 I;
  viscr_uint piv[3];
  viscr_float LUcol[3];

  viscr_mat_identity( I.m);

  if( viscr_compute_LU( LU.m, piv, LUcol, Po_33.m))
    if( viscr_solve_LU( invPo_33.m, LU.m, piv, I.m))
      return true;
  return false;
}


/// Compute parameter for stereo camera. return false on error.
static bool
compute_stereo_camera(
    viscr_stereo_camera & stereo_cam,
    const viscr_camera & k0_param,
    const viscr_camera & k1_param)
{
  /* This is based on:
     @ARTICLE{Fusiello00,
     author = {Fusiello, Andrea and Trucco, Emanuele and Verri, Alessandro},
     title = {A Compact Algorithm for Rectification of Stereo Pairs},
     journal = {Machine Vision and Applications},
     year = {2000},
     volume = {12},
     pages = {16-22},
     number = {1},
     }
     */

  // Build Po_i
  viscr_mat33 invPo1_33, invPo2_33;
  viscr_vec3 Po1_4, Po2_4;
  if( !build_Po( invPo1_33, Po1_4, k0_param))
    return false;
  if( !build_Po( invPo2_33, Po2_4, k1_param))
    return false;

  // optical centers (unchanged)
  viscr_vec3 c1, c2;
  viscr_mat_mult_vec( c1.v, invPo1_33.m, Po1_4.v);
  viscr_vec_negate( c1.v);
  viscr_mat_mult_vec( c2.v, invPo2_33.m, Po2_4.v);
  viscr_vec_negate( c2.v);

  viscr_vec3 v1, v2, v3;
  // new x axis (= direction of the baseline)
  viscr_vec_sub( v1.v, c1.v, c2.v);
  // new y axes (orthogonal to new x and old z)
  viscr_vec3 R1_3;
  for( viscr_uint i=0; i<3; ++i)
    R1_3.data[i]=k1_param.m2c_r.m(2,i);
  viscr_vec_cross( v2, R1_3, v1);
  // new z axes (orthogonal to baseline and y)
  viscr_vec_cross( v3, v1, v2);

  // new extrinsic parameters
  viscr_float nv1=viscr_vec_norm( v1.v);
  viscr_float nv2=viscr_vec_norm( v2.v);
  viscr_float nv3=viscr_vec_norm( v3.v);
  for( viscr_uint i=0; i<3; ++i)
  {
    stereo_cam.R.m( 0, i)=v1.data[i]/nv1;
    stereo_cam.R.m( 1, i)=v2.data[i]/nv2;
    stereo_cam.R.m( 2, i)=v3.data[i]/nv3;
  }

  stereo_cam.f=(k0_param.f+k1_param.f)/2.0f;
  stereo_cam.u=(k0_param.cu+k1_param.cu)/2.0f;
  stereo_cam.v=(k0_param.cv+k1_param.cv)/2.0f;
  stereo_cam.b=nv1;

  // translation is left unchanged
  // new intrinsic parameters (arbitrary)
  viscr_mat33 A;
  viscr_mat_zero( A.m);
  A.m(0,0)=-stereo_cam.f;
  A.m(1,1)=-stereo_cam.f;
  A.m(0,2)=stereo_cam.u;
  A.m(1,2)=stereo_cam.v;
  A.m(2,2)=1.0f;

  // new projection matrices
  viscr_mat33 AR;
  viscr_mat_mult_mat( AR.m, A.m, stereo_cam.R.m);

  // rectifying image transformation
  viscr_mat_mult_mat( stereo_cam.T_k0.m, AR.m, invPo1_33.m);
  viscr_mat_mult_mat( stereo_cam.T_k1.m, AR.m, invPo2_33.m);

  // De-rectifying transform
  viscr_mat33 LU;
  viscr_mat33 I;
  viscr_uint piv[3];
  viscr_float LUcol[3];

  viscr_mat_identity( I.m);

  if( !viscr_compute_LU( LU.m, piv, LUcol, stereo_cam.T_k0.m))
    return false;
  if( !viscr_solve_LU( stereo_cam.invT_k0.m, LU.m, piv, I.m))
    return false;
  if( !viscr_compute_LU( LU.m, piv, LUcol, stereo_cam.T_k1.m))
    return false;
  if( !viscr_solve_LU( stereo_cam.invT_k1.m, LU.m, piv, I.m))
    return false;
  return true;
}


/// Distortion user data for epipolar rectification
struct sDistortData
{
  /// Transform old to new camera coordinates (2D)
  viscr_matrix * T;

  /// Distortion parameters
  const viscr_camera * param;
  
  sDistortData() { }

  private:
    sDistortData( const sDistortData &);
    sDistortData & operator=( const sDistortData &);
};


/// Distortion computation for rectification of stereo cameras
static void 
epipolarDistorter( 
    viscr_float & distU, 
    viscr_float & distV, 
    viscr_float u, 
    viscr_float v,
    void * userData)
{
  sDistortData * ud=(sDistortData*)userData;

  viscr_vec3 uv_undist, uv_rect;
  uv_undist.data[0]=u;
  uv_undist.data[1]=v;
  uv_undist.data[2]=1.0f;

  // Do linear part
  viscr_mat_mult_vec( uv_rect.v, *(ud->T), uv_undist.v);
  
  // Do non-linear part
  // Make normalised coordinates first

  viscr_float u_rect=uv_rect.data[0]/uv_rect.data[2];
  viscr_float v_rect=uv_rect.data[1]/uv_rect.data[2];

  viscr_float u_norm=(u_rect-ud->param->cu)/ud->param->f;
  viscr_float v_norm=(v_rect-ud->param->cv)/(ud->param->f*ud->param->fs);

  // warp from normalised camera coordinates into distorted image coords.

  // do some precalculations
  viscr_float f_u2 = u_norm*u_norm;
  viscr_float f_v2 = v_norm*v_norm;
  viscr_float f_r2 = f_u2 + f_v2;
  viscr_float f_r4 = f_r2*f_r2;
  viscr_float f_r6 = f_r4*f_r2;
  
  // coefficient for radialsymmetric distortion
  viscr_float f_cf_rad = (1.0f + ud->param->k0*f_r2 + ud->param->k1*f_r4 + ud->param->k4*f_r6);

  // radialasymmetric and tangential component
  viscr_float f_du_tan = 2.0f*ud->param->k2*u_norm*v_norm + ud->param->k3*(f_r2 + 2.0f*f_u2);
  viscr_float f_dv_tan = ud->param->k2*(f_r2 + 2.0f*f_v2) + 2.0f*ud->param->k3*u_norm*v_norm;

  // complete distortion
  viscr_float f_u_radtan = f_cf_rad * u_norm + f_du_tan;
  viscr_float f_v_radtan = f_cf_rad * v_norm + f_dv_tan;

  // apply KK (here direct (not matrix) multiplication)
  distU = ud->param->f*f_u_radtan + ud->param->cu;
  distV = ud->param->f*ud->param->fs*f_v_radtan + ud->param->cv;
}


bool
viscr_rectification_compute_stereo(
    viscr_stereo_camera & stereo_cam,
    viscr_rectification & k0_rect,
    viscr_rectification & k1_rect,
    const viscr_camera & k0_param,
    const viscr_camera & k1_param)
{
  assert( k0_rect.size==k0_param.size);
  assert( k1_rect.size==k1_param.size);

  if( !compute_stereo_camera( stereo_cam, k0_param, k1_param))
    return false;

  // Fill the rectification table for both cameras.
  sDistortData distortData;
  distortData.T=&stereo_cam.invT_k0.m;
  distortData.param=&k0_param;
  fill_rectification_table( k0_rect, k0_param.size, epipolarDistorter, &distortData);
  distortData.T=&stereo_cam.invT_k1.m;
  distortData.param=&k1_param;
  fill_rectification_table( k1_rect, k1_param.size, epipolarDistorter, &distortData);

  return true;
}
