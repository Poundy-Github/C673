#include <algorithm>
#include <viscr_SMPC.hpp>

// ~CodeReview ~ID:c939a604323a01f6089b4c7a136572e0 ~Reviewer:CW01\uidk7517 ~Date:23.06.2012 ~Priority:3 ~Comment:Remove or comment dead code
/*
viscr_int32 sac_rand(viscr_int32 SMPC_rand_seed)
{
  return(_rotl(SMPC_rand_seed,1u)^(SMPC_rand_seed & ((0xdu)<<28)));
}
*/


void 
viscr_SMPC_alloc( 
    viscr_SMPC_data & data/*, 
    const viscr_SMPC_param & param*/)
{
  // ~CodeReview ~ID:4c17025f36af6f1199a3d89fe95e1947 ~Reviewer:CW01\uidk7517 ~Date:23.06.2012 ~Priority:3 ~Comment:Remove or comment dead code
  //data.param=param;
  
  viscr_uint nBins = data.param.bins_u * data.param.bins_v;

  // ~CodeReview ~ID:fb53f2bc24585bd827dedaa9441e2732 ~Reviewer:CW01\uidk7517 ~Date:23.06.2012 ~Priority:3 ~Comment:Remove or comment dead code
  //data.binned_epipolar_points.resize( data.param.points_per_epipolar_bin*nBins);
  //data.bin_cnt_epipolar.resize( nBins);

  //data.binned_yaw_points.resize( data.param.points_per_yaw_bin*data.param.bins_d);
  //data.bin_cnt_yaw.resize( data.param.bins_d);

  for( viscr_uint i = 0U; i < nBins; ++i)
  {
    data.bin_cnt_epipolar[i] = 0U;
  }

  for( viscr_uint i = 0U; i < data.param.bins_d; ++i)
  {
    data.bin_cnt_yaw[i] = 0U;
  }

  // ~CodeReview ~ID:34def5276da1528783bac0cd29081d90 ~Reviewer:CW01\uidk7517 ~Date:23.06.2012 ~Priority:3 ~Comment:Remove or comment dead code
  //if (data.random_point_index.size() == 0)
  //{
  //  data.random_point_index.resize( data.param.max_input_coarse);
  //  for( viscr_uint i=0; i<data.param.max_input_coarse; ++i)
  //    data.random_point_index[i]=i;
  //  std::random_shuffle( data.random_point_index.begin(), data.random_point_index.end());
  //}
  //data.random_point_index = (viscr_pixel *)const_random_point_index;
  //data.klt_accu.resize( 2*param.klt_shift_rad+1);

//  for( viscr_uint dim=0; dim<VISCR_SMPC_PARAM_CNT; ++dim)
//    data.median_buffer[dim].resize( param.median_len);
//  data.median_buffer_sortinfo.resize( param.median_len);

}


void 
viscr_SMPC_init( 
    viscr_SMPC_data & data, 
    const viscr_timestamp & now)
{
  data.last_calib_time = now;
  viscr_uint nBins = data.param.bins_u * data.param.bins_v;
  for( viscr_uint i = 0U; i < nBins; ++i)
  {
    data.bin_cnt_epipolar[i] = 0U;
  }
  for( viscr_uint i = 0U; i < data.param.bins_d; ++i)
  {
    data.bin_cnt_yaw[i] = 0U;
  }
  data.median_buffer_entries = 0U;
  data.new_calib_done = viscr_false;

  data.algo_state = VISCR_SMPC_STATE_BUFFER_EMPTY;
  // ~CodeReview ~ID:dab95443434637a346f1689f64ffe269 ~Reviewer:CW01\uidk7517 ~Date:23.06.2012 ~Priority:3 ~Comment:Remove or comment dead code
  //data.algo_state= VISCR_SMPC_STATE_BUFFER_FULL;

  data.random_seed_epi = (static_cast<viscr_uint>(1) << static_cast<viscr_uint>(4)); // arbitrary int32 except 0 which is not admissible
  data.random_seed_yaw = 0U;
  data.num_calib_in_state = 0U;
}

// ~CodeReview ~ID:10fa0cf09d73fa8d11876d4585dc22c6 ~Reviewer:CW01\uidk7517 ~Date:23.06.2012 ~Priority:3 ~Comment:Remove or comment dead code
#if 0 // CODE NOT USED
void
viscr_SMPC_free(
    viscr_SMPC_data & )
{

}
#endif

void
viscr_SMPC_calib_taken(
    viscr_SMPC_data & data)
{
  data.new_calib_done = viscr_false;
  viscr_uint nBins = data.param.bins_u * data.param.bins_v;
  for( viscr_uint i = 0U; i < nBins; ++i)
  {
    data.bin_cnt_epipolar[i] = 0U;
  }
  for( viscr_uint i = 0U; i < data.param.bins_d; ++i)
  {
    data.bin_cnt_yaw[i] = 0U;
  }
}


viscr_bool
viscr_SMPC_epipolar_bins_are_full( 
    const viscr_SMPC_data & data)
{
  viscr_bool ret_value = viscr_true;
  viscr_uint nBins = data.param.bins_u * data.param.bins_v;
  for( viscr_uint i = 0U; i < nBins; ++i)
  {
    if( data.bin_cnt_epipolar[i] < data.param.points_per_epipolar_bin_max[i])
    {
      ret_value = viscr_false;
    }
  }
  return ret_value;
}

#if (VISCR_SMPC_REMOVE_YAW_IN_FINE==0) 
viscr_bool
viscr_SMPC_yaw_bins_are_full( 
    const viscr_SMPC_data & data)
{
  viscr_bool ret_value = viscr_true;
  for( viscr_uint i=0; i<data.param.bins_d; ++i)
  {
    if( data.bin_cnt_yaw[i]<data.param.points_per_yaw_bin)
    {
      ret_value = viscr_false;
    }
  }
  return ret_value;
}
#endif

viscr_uint
viscr_SMPC_coord2bin(
    const viscr_SMPC_param & param,
    const viscr_coord u,
    const viscr_coord v)
{
  viscr_int itemp;
  // ~CodeReview ~ID:9d2ab7838d796fab1f3aed340be938cb ~Reviewer:CW01\uidk7517 ~Date:23.06.2012 ~Priority:3 ~Comment:Potential div zero
  viscr_int uBin = (static_cast<viscr_int>(param.bins_u) * u) / param.size.u;
  viscr_int vBin = (static_cast<viscr_int>(param.bins_v) * v) / param.size.v;
  itemp = uBin + (vBin * static_cast<viscr_int>(param.bins_u));
  return static_cast<viscr_uint>(itemp);
}


viscr_uint
viscr_SMPC_median( 
    const viscr_float values[],
    viscr_uint indices[],
    const viscr_uint nValues)
{
  // Setup indices
  for( viscr_uint i = 0U; i < nValues; ++i)
  {
    indices[i] = i;
  }

  // Bubble sort
  viscr_uint n = nValues;
  bool_t swapped;
  do
  {
    swapped = FALSE;
    for( viscr_uint i = 0U; (i + 1U) < n; ++i)
    {
      viscr_uint j = indices[i];
      viscr_uint j1 = indices[i + 1U];
      if( values[j] > values[j1])
      {
        viscr_uint h = indices[i];
        indices[i] = indices[i + 1U];
        indices[i + 1U] = h;
        swapped = TRUE;
      }
    }
    --n;
  } while( (swapped == TRUE) && (n > 1U) );

  // Get median entry
  return indices[nValues / 2U];
}


void
viscr_SMPC_calib_available(
    viscr_SMPC_data & data)
{
  // make a new calib as available
  data.new_calib_done = viscr_true;
  // keep note of the calibrations done in this state
  ++data.num_calib_in_state;

  // State machine for top-level algo switching. We switch states if we
  // exceeded the number of calibs in the current state according to the
  // parameters.
  switch( data.algo_state)
  {
    // In coarse_epi, we go to coarse_all 
    // ~CodeReview ~ID:ad8f20267e6c532ed5c6771051904834 ~Reviewer:CW01\uidk7517 ~Date:23.06.2012 ~Priority:3 ~Comment:Remove or comment dead code
    /*case VISCR_SMPC_STATE_COARSE_EPI:
      if( data.num_calib_in_state>=data.param.num_calib_coarse_epi)
      {
        data.num_calib_in_state=0;
        data.algo_state=VISCR_SMPC_STATE_COARSE_ALL;
        data.median_buffer_entries=0;
      }
      break;*/
    // in coarse_all, we go to fine_all. We initialise the low pass from the
    // current values.
    case VISCR_SMPC_STATE_BUFFER_EMPTY:
      if( data.num_calib_in_state >= data.param.num_calib_coarse_all)
      {
        data.num_calib_in_state = 0U;
        data.algo_state = VISCR_SMPC_STATE_BUFFER_FULL;
        for( viscr_uint iDim = 0U; iDim < static_cast<viscr_uint>(VISCR_SMPC_PARAM_CNT); ++iDim)
        {
          data.low_pass[iDim] = data.current_angles[iDim];
        }
      }
      break;
    // once in fine_all, we remain here indefinitely. If you want to go back,
    // call viscr_SMPC_init or set the flags yourself.
    case VISCR_SMPC_STATE_BUFFER_FULL:
      break;
    /* <ln_offset:+1 COVERAGE reviewer name: Alexander Behrens date: 13.07.2012 reason: Switch case control. If unknown parameter do nothing. */
    default:
      break;
  }
}

// ~CodeReview ~ID:7a6249961c92e2fff39dccb02fcfe8ab ~Reviewer:CW01\uidk7517 ~Date:23.06.2012 ~Priority:3 ~Comment:Remove or comment dead code
//viscr_bool
//viscr_SMPC_want_powerstereo(
//    viscr_SMPC_data & data)
//{
//  // we want powerstereo in coarse_epi mode only
//  return (data.algo_state==VISCR_SMPC_STATE_COARSE_EPI)?viscr_true:viscr_false;
//}
