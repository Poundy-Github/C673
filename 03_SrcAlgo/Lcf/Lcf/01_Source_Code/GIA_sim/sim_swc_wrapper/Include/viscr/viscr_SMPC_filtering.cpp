#include <viscr_SMPC.hpp>



#if (VISCR_SMPC_FILTERING_MODE == 0)
void 
viscr_SMPC_set_rotation( 
    viscr_SMPC_data & data, 
    viscr_float a,
    viscr_float b,
    viscr_float c,
    viscr_float rmse_epipolar,
    viscr_float rmse_improvement,
    const viscr_timestamp & )
{
  viscr_float rot_ang[VISCR_SMPC_PARAM_CNT] = {a,b,c};

  // median filtering 
  if( data.param.median_len > 0)
  {
    // Insert next element

    // if the buffer is not full
    if( data.median_buffer_entries < data.param.median_len)
    {
      // update the number of points
      ++data.median_buffer_entries;
    }
    else
    {
      // otherwise move down the old points, make room at the end
      for( viscr_uint i = 1U; i < data.median_buffer_entries; ++i)
      {
        for( viscr_uint iDim = 0U; iDim < 3U; ++iDim)
        {
          data.median_buffer[iDim][i - 1] = data.median_buffer[iDim][i];
        }
        data.median_buffer_rmse_epipolar[i - 1] = data.median_buffer_rmse_epipolar[i];
        data.median_buffer_rmse_improvement[i - 1] = data.median_buffer_rmse_improvement[i];
      }
      
    }
    // write the new data in the newest available space
    for( viscr_uint iDim = 0U; iDim < 3U; ++iDim)
    {
      data.median_buffer[iDim][data.median_buffer_entries - 1] = rot_ang[iDim];
    }
    data.median_buffer_rmse_epipolar[data.median_buffer_entries - 1] = rmse_epipolar;
    data.median_buffer_rmse_improvement[data.median_buffer_entries - 1] = rmse_improvement;

    for( viscr_uint iDim = 0U; iDim < 3U; ++iDim)
    {
      // Sort the median buffer: bubble sort as there are very few entries
      // Only sort the index into the buffer, as the buffer must be kept in
      // temporal order for the code above.
      viscr_uint medianEntry = viscr_SMPC_median(&data.median_buffer[iDim][0],
                                                 &data.median_buffer_sortinfo[0],
                                                 data.median_buffer_entries);

      // update the output
      rot_ang[iDim] = data.median_buffer[iDim][medianEntry];
    }
  }

  // in fine_all state
  if( data.algo_state == VISCR_SMPC_STATE_BUFFER_FULL)
  {
    // Do a low pass on the median using a numerically stable sliding average
    for( viscr_uint iDim = 0U; iDim < 3U; ++iDim)
    {
      data.low_pass[iDim] += (rot_ang[iDim] - data.low_pass[iDim]) * data.param.low_pass_factor;
      rot_ang[iDim] = data.low_pass[iDim];
    }
  }

  // update the current angle
  for( viscr_uint iDim = 0U; iDim < 3U; ++iDim)
  {
    data.current_angles[iDim] = rot_ang[iDim];
  }
}
#endif

#if (VISCR_SMPC_FILTERING_MODE == 1)
void 
viscr_SMPC_set_rotation( 
    viscr_SMPC_data & data, 
    viscr_float const a,
    viscr_float const b,
    viscr_float const c,
    viscr_float const rmse_epipolar,
    viscr_float const rmse_improvement,
    const viscr_timestamp & )
{
  viscr_float rot_ang[VISCR_SMPC_PARAM_CNT] = {a,b,c};
  viscr_float low_pass_factor_dyn = 1.0F;
  // ~CodeReview ~ID:f03d2fccc79d29fc44fa4d10cf14eb1e ~Reviewer:CW01\uidk7517 ~Date:23.06.2012 ~Priority:3 ~Comment:Remove or document reason for dead code
  //viscr_int buffer_is_full = 0;

  // median filtering 
  /* <ln_offset:+1 COVERAGE reviewer name: Alexander Behrens date: 13.07.2012 reason: Check if median filter should be performed. */
  if( data.param.median_len > 0U)
  {
    // Insert next element

    // if the buffer is not full
    if( data.median_buffer_entries < data.param.median_len)
    {
      if (rmse_epipolar < VISCR_SMPC_FILTERING_GOOD_RMSE)
      {
        for (viscr_int i = static_cast<viscr_int>(data.median_buffer_entries); i < static_cast<viscr_int>(data.param.median_len); i++)
        {
          for( viscr_uint iDim = 0U; iDim < 3U; ++iDim)
          {
            data.median_buffer[iDim][i] = rot_ang[iDim];
          }
          data.median_buffer_rmse_epipolar[i] = rmse_epipolar;
          data.median_buffer_rmse_improvement[i] = rmse_improvement;
        }
        data.num_calib_in_state = data.param.median_len - 1U;
        data.median_buffer_entries = data.param.median_len - 1U;
       }
      // update the number of points
      ++data.median_buffer_entries;
    }
    else
    {
      //buffer_is_full = 1;
      // otherwise move down the old points, make room at the end
      for( viscr_uint i = 1U; i < data.median_buffer_entries; ++i)
      {
        for( viscr_uint iDim = 0U; iDim < 3U; ++iDim)
        {
          data.median_buffer[iDim][i - 1U] = data.median_buffer[iDim][i];
        }
        data.median_buffer_rmse_epipolar[i - 1U] = data.median_buffer_rmse_epipolar[i];
        data.median_buffer_rmse_improvement[i - 1U] = data.median_buffer_rmse_improvement[i];
      }
    }
    // write the new data in the newest available space
    for( viscr_uint iDim = 0U; iDim < 3U; ++iDim)
    {
      data.median_buffer[iDim][data.median_buffer_entries - 1U] = rot_ang[iDim];
    }
    data.median_buffer_rmse_epipolar[data.median_buffer_entries - 1U] = rmse_epipolar;
    data.median_buffer_rmse_improvement[data.median_buffer_entries - 1U] = rmse_improvement;

    // ~CodeReview ~ID:03d29e9f991db5b2076296b03fead214 ~Reviewer:CW01\uidk7517 ~Date:23.06.2012 ~Priority:3 ~Comment:Remove or document reason for dead code
    //for( viscr_uint iDim=0; iDim<3; ++iDim)
    //{
    //  // Sort the median buffer: bubble sort as there are very few entries
    //  // Only sort the index into the buffer, as the buffer must be kept in
    //  // temporal order for the code above.
    //  viscr_uint medianEntry=viscr_SMPC_median(
    //      &data.median_buffer[iDim][0],
    //      &data.median_buffer_sortinfo[0],
    //      data.median_buffer_entries);

    //  // update the output
    //  rot_ang[iDim]=data.median_buffer[iDim][medianEntry];
    //}
    if( data.algo_state == VISCR_SMPC_STATE_BUFFER_FULL) // is full now
    {
      // choose last solution
      low_pass_factor_dyn = VISCR_SMPC_FILTERING_LOW_PASS_FACTOR_DYN * rmse_improvement;
      if (low_pass_factor_dyn < 0.0F)/* <ln_offset:+0 COVERAGE reviewer name: Baomin Cui date: 27.09.2012 reason: Value is limited to zero on purpose. */
      {
        low_pass_factor_dyn = 0.0F;
      }
      /* <ln_offset:+1 COVERAGE reviewer name: Alexander Behrens date: 05.07.2012 reason: Value is limited to one on purpose. */
      if (low_pass_factor_dyn > 1.0F)
      {
        low_pass_factor_dyn = 1.0F;
      }
    }
    else
    {
      // choose best solution
      f32_t min_median_buffer_rmse_epipolar = 120.0F; // max value
      ui32_t min_median_buffer_rmse_epipolar_index = 0U;
      for( viscr_uint i = 1U; i < data.median_buffer_entries; ++i)
      { 
        if (data.median_buffer_rmse_epipolar[i - 1U] < min_median_buffer_rmse_epipolar)
        {
          min_median_buffer_rmse_epipolar_index = i - 1U;
          min_median_buffer_rmse_epipolar = data.median_buffer_rmse_epipolar[i - 1U];
        }
      }
      for( viscr_uint iDim = 0U; iDim < 3U; ++iDim)
      {
        rot_ang[iDim] = data.median_buffer[iDim][min_median_buffer_rmse_epipolar_index];
      }

      viscr_uint medianEntry = viscr_SMPC_median(&data.median_buffer[1][0],
                                                 &data.median_buffer_sortinfo[0],
                                                 data.median_buffer_entries);

      // update the output
      rot_ang[1] = data.median_buffer[1][medianEntry];
    }
  }

  if( data.algo_state == VISCR_SMPC_STATE_BUFFER_FULL)
  {
    viscr_float low_pass_step = 0.0F;
    // Do a low pass on the median using a numerically stable sliding average
    for( viscr_uint iDim = 0U; iDim < 3U; ++iDim)
    {
      if (iDim == 1U)
      {
        viscr_uint medianEntry = viscr_SMPC_median(&data.median_buffer[iDim][0],
                                                   &data.median_buffer_sortinfo[0],
                                                   data.median_buffer_entries);

        // update the output
        rot_ang[iDim] = data.median_buffer[iDim][medianEntry];
        low_pass_step = (rot_ang[iDim] - data.low_pass[iDim]) * data.param.low_pass_factor;
      }
      else
      {
        low_pass_step = (rot_ang[iDim] - data.low_pass[iDim]) * low_pass_factor_dyn;
      }
      /* <ln_offset:+1 COVERAGE reviewer name: Alexander Behrens date: 05.07.2012 reason: Value is limited to maximum value. */
      if (low_pass_step > VISCR_SMPC_FILTERING_LOW_PASS_MAX_STEP)
      {
        low_pass_step = VISCR_SMPC_FILTERING_LOW_PASS_MAX_STEP;
      }
      data.low_pass[iDim] += low_pass_step;
      rot_ang[iDim] = data.low_pass[iDim];
    }
  }

  // update the current angle
  for( viscr_uint iDim = 0U; iDim < 3U; ++iDim)
  {
    data.current_angles[iDim] = rot_ang[iDim];
  }
}
#endif
